# CanvasRenderingContext2D

Use **RenderingContext** to draw rectangles, text, images, and other objects on a canvas.

> **NOTE**
>
> The APIs of this module are supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.



## APIs

CanvasRenderingContext2D(settings?: RenderingContextSettings)

This API can be used in ArkTS widgets since API version 9.

**Parameters**

| Name     | Type                                    | Mandatory  | Description                                    |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| settings | [RenderingContextSettings](#renderingcontextsettings) | No   | See [RenderingContextSettings](#renderingcontextsettings).|


### RenderingContextSettings

RenderingContextSettings(antialias?: boolean)

Configures the settings of a **CanvasRenderingContext2D** object, including whether to enable antialiasing.

This API can be used in ArkTS widgets since API version 9.

**Parameters**

| Name      | Type   | Mandatory  | Description                         |
| --------- | ------- | ---- | ----------------------------- |
| antialias | boolean | No   | Whether to enable antialiasing.<br>Default value: **false**|


## Attributes

| Name                                      | Type                                      | Description                                      |
| ---------------------------------------- | ---------------------------------------- | ---------------------------------------- |
| [fillStyle](#fillstyle)                  | string \|number<sup>10+</sup> \|[CanvasGradient](ts-components-canvas-canvasgradient.md) \| [CanvasPattern](ts-components-canvas-canvaspattern.md#canvaspattern) | Style to fill an area.<br>- When the type is string, this attribute indicates the color of the fill area.<br>Default value: **'black'**<br>- When the type is number, this attribute indicates the color of the fill area.<br>Default value: **'#000000'**<br>- When the type is **CanvasGradient**, this attribute indicates a gradient object, which is created using the **[createLinearGradient](#createlineargradient)** API.<br>- When the type is **CanvasPattern**, this attribute indicates a pattern, which is created using the **[createPattern](#createpattern)** API.<br>This API can be used in ArkTS widgets since API version 9.|
| [lineWidth](#linewidth)                  | number                                   | Line width.<br>Default value: **1(px)**<br>Unit: vp<br> The value cannot be **0** or a negative number. If it is set to **0** or a negative number, the default value is used instead.              |
| [strokeStyle](#strokestyle)              | string \| number<sup>10+</sup> \| [CanvasGradient](ts-components-canvas-canvasgradient.md) \| [CanvasPattern](ts-components-canvas-canvaspattern.md#canvaspattern) | Stroke color.<br>Default value: **'black'**<br>Default value: **'#000000'**<br>- When the type is **CanvasGradient**, this attribute indicates a gradient object, which is created using the **[createLinearGradient](#createlineargradient)** API.<br>- When the type is **CanvasPattern**, this attribute indicates a pattern, which is created using the **[createPattern](#createpattern)** API.<br>This API can be used in ArkTS widgets since API version 9.|
| [lineCap](#linecap)                      | [CanvasLineCap](#canvaslinecap)                            | Style of the line endpoints. The options are as follows:<br>- **'butt'**: The endpoints of the line are squared off.<br>- **'round'**: The endpoints of the line are rounded.<br>- **'square'**: The endpoints of the line are squared off by adding a box with an equal width and half the height of the line's thickness.<br>Default value: **'butt'**<br>This API can be used in ArkTS widgets since API version 9.|
| [lineJoin](#linejoin)                    | [CanvasLineJoin](#canvaslinejoin)     | Style of the shape used to join line segments. The options are as follows:<br>- **'round'**: The shape used to join line segments is a sector, whose radius at the rounded corner is equal to the line width.<br>- **'bevel'**: The shape used to join line segments is a triangle. The rectangular corner of each line is independent.<br>- **'miter'**: The shape used to join line segments has a mitered corner by extending the outside edges of the lines until they meet. You can view the effect of this attribute in **miterLimit**.<br>Default value: **'miter'**<br>This API can be used in ArkTS widgets since API version 9.|
| [miterLimit](#miterlimit)                | number                                   | Maximum miter length. The miter length is the distance between the inner corner and the outer corner where two lines meet.<br>Default value: **10**<br>Unit: px<br>The value cannot be **0** or a negative number. If it is set to **0** or a negative number, the default value is used instead.<br>This API can be used in ArkTS widgets since API version 9.|
| [font](#font)                            | string                                   | Font style.<br>Syntax: ctx.font='font-size font-family'<br>- (Optional) **font-size**: font size and line height. The unit can be px or vp.<br>- (Optional) **font-family**: font family.<br>Syntax: ctx.font='font-style font-weight font-size font-family'<br>- (Optional) **font-style**: font style. Available values are **'normal'** and **'italic'**.<br>- (Optional) **font-weight**: font weight. Available values are as follows: **'normal'**, **'bold'**, **'bolder'**, **'lighter'**, **'100'**, **'200'**, **'300'**, **'400'**, **'500'**, **'600'**, **'700'**, **'800'**, **'900'**.<br>- (Optional) **font-size**: font size and line height. The unit must be specified and can be px or vp.<br>- (Optional) **font-family**: font family. Available values are **'sans-serif'**, **'serif'**, and **'monospace'**.<br>Default value: **'normal normal 14px sans-serif'**<br>This API can be used in ArkTS widgets since API version 9.|
| [textAlign](#textalign)                  | [CanvasTextAlign](#canvastextalign)          | Text alignment mode. Available values are as follows:<br>- **'left'**: The text is left-aligned.<br>- **'right'**: The text is right-aligned.<br>- **'center'**: The text is center-aligned.<br>- **'start'**: The text is aligned with the start bound.<br>- **'end'**: The text is aligned with the end bound.<br>In the **ltr** layout mode, the value **'start'** equals **'left'**. In the **rtl** layout mode, the value **'start'** equals **'right'**.<br>Default value: **'left'**<br>This API can be used in ArkTS widgets since API version 9.|
| [textBaseline](#textbaseline)            | [CanvasTextBaseline](#canvastextbaseline)           | Horizontal alignment mode of text. Available values are as follows:<br>- **'alphabetic'**: The text baseline is the normal alphabetic baseline.<br>- **'top'**: The text baseline is on the top of the text bounding box.<br>- **'hanging'**: The text baseline is a hanging baseline over the text.<br>- **'middle'**: The text baseline is in the middle of the text bounding box.<br>**'ideographic'**: The text baseline is the ideographic baseline. If a character exceeds the alphabetic baseline, the ideographic baseline is located at the bottom of the excess character.<br>- **'bottom'**: The text baseline is at the bottom of the text bounding box. Its difference from the ideographic baseline is that the ideographic baseline does not consider letters in the next line.<br>Default value: **'alphabetic'**<br>This API can be used in ArkTS widgets since API version 9.|
| [globalAlpha](#globalalpha)              | number                                   | Opacity.<br>**0.0**: completely transparent.<br>**1.0**: completely opaque.<br>Default value: **1.0**<br>This API can be used in ArkTS widgets since API version 9.|
| [lineDashOffset](#linedashoffset)        | number                                   | Offset of the dashed line. The precision is float.<br>Default value: **0.0**<br>Unit: px<br>This API can be used in ArkTS widgets since API version 9.|
| [globalCompositeOperation](#globalcompositeoperation) | string                                   | Composition operation type. Available values are as follows: **'source-over'**, **'source-atop'**, **'source-in'**, **'source-out'**, **'destination-over'**, **'destination-atop'**, **'destination-in'**, **'destination-out'**, **'lighter'**, **'copy'**, and **'xor'**.<br>Default value: **'source-over'**<br>This API can be used in ArkTS widgets since API version 9.|
| [shadowBlur](#shadowblur)                | number                                   | Blur level during shadow drawing. A larger value indicates a more blurred effect. The precision is float.<br>Default value: **0.0**<br>The value cannot be a negative number. If it is set to a negative number, the default value is used instead.<br>This API can be used in ArkTS widgets since API version 9.|
| [shadowColor](#shadowcolor)              | string                                   | Shadow color.<br>Default value: transparent black<br>This API can be used in ArkTS widgets since API version 9.|
| [shadowOffsetX](#shadowoffsetx)          | number                                   | X-axis shadow offset relative to the original object.<br>Default value: **0**<br>Unit: vp<br>This API can be used in ArkTS widgets since API version 9.|
| [shadowOffsetY](#shadowoffsety)          | number                                   | Y-axis shadow offset relative to the original object.<br>Default value: **0**<br>Unit: vp<br>This API can be used in ArkTS widgets since API version 9.|
| [imageSmoothingEnabled](#imagesmoothingenabled) | boolean                                  | Whether to adjust the image smoothness during image drawing. The value **true** means to enable this feature, and **false** means the opposite.<br>Default value: **true**<br>This API can be used in ArkTS widgets since API version 9.|
| [height](#height)                        | number                                   | Component height.<br>Unit: vp<br>This API can be used in ArkTS widgets since API version 9.|
| [width](#width)                          | number                                   | Component width.<br>Unit: vp<br>This API can be used in ArkTS widgets since API version 9.|
| [imageSmoothingQuality](#imagesmoothingquality) | [ImageSmoothingQuality](#imagesmoothingquality-1) | Quality of image smoothing. This attribute works only when **imageSmoothingEnabled** is set to **true**.<br>Default value: **ImageSmoothingQuality.low**<br>This API can be used in ArkTS widgets since API version 9.|
| [direction](#direction)                  | [CanvasDirection](#canvasdirection) | Text direction used for drawing text.<br>Default value: **CanvasDirection.inherit**<br>This API can be used in ArkTS widgets since API version 9.|
| [filter](#filter)                        | string                                   | Filter effect. Available values are as follows:<br>- **'none'**: no filter effect.<br>- **'blur'**: applies the Gaussian blur for the image.<br>- **'brightness'**: applies a linear multiplication to the image to make it look brighter or darker.<br>- **'contrast'**: adjusts the image contrast.<br>- **'grayscale'**: converts the image to a grayscale image.<br>- **'hue-rotate'**: applies hue rotation to the image.<br>- **'invert'**: inverts the input image.<br>- **'opacity'**: sets the opacity of the image.<br>- **'saturate'**: sets the saturation of the image.<br>- **'sepia'**: converts the image to dark brown.<br>Default value: **'none'**<br>This API can be used in ArkTS widgets since API version 9.|

> **NOTE**
>
> The string-type value of **fillStyle**, **shadowColor**, and **strokeStyle** can be in 'rgb(255, 255, 255)', 'rgba(255, 255, 255, 1.0)', or '\#FFFFFF' format.


### fillStyle

```ts
// xxx.ets
@Entry
@Component
struct FillStyleExample {
  private settings: RenderingContextSettings = new RenderingContextSettings(true)
  private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings)

  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
      Canvas(this.context)
        .width('100%')
        .height('100%')
        .backgroundColor('#ffff00')
        .onReady(() =>{
          this.context.fillStyle = '#0000ff'
          this.context.fillRect(20, 20, 150, 100)
        })
    }
    .width('100%')
    .height('100%')
  }
}
```

![en-us_image_0000001257058395](figures/en-us_image_0000001257058395.png)


### lineWidth

```ts
// xxx.ets
@Entry
@Component
struct LineWidthExample {
  private settings: RenderingContextSettings = new RenderingContextSettings(true)
  private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings)

  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
      Canvas(this.context)
        .width('100%')
        .height('100%')
        .backgroundColor('#ffff00')
        .onReady(() =>{
        this.context.lineWidth = 5
        this.context.strokeRect(25, 25, 85, 105)
      })
    }
    .width('100%')
    .height('100%')
  }
}
```

![en-us_image_0000001212378408](figures/en-us_image_0000001212378408.png)


### strokeStyle

```ts
// xxx.ets
@Entry
@Component
struct StrokeStyleExample {
  private settings: RenderingContextSettings = new RenderingContextSettings(true)
  private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings)

  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
      Canvas(this.context)
        .width('100%')
        .height('100%')
        .backgroundColor('#ffff00')
        .onReady(() =>{
          this.context.lineWidth = 10
          this.context.strokeStyle = '#0000ff'
          this.context.strokeRect(25, 25, 155, 105)
        })
    }
    .width('100%')
    .height('100%')
  }
}
```


![en-us_image_0000001212218446](figures/en-us_image_0000001212218446.png)


### lineCap

```ts
// xxx.ets
@Entry
@Component
struct LineCapExample {
  private settings: RenderingContextSettings = new RenderingContextSettings(true)
  private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings)

  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
      Canvas(this.context)
        .width('100%')
        .height('100%')
        .backgroundColor('#ffff00')
        .onReady(() =>{
          this.context.lineWidth = 8
          this.context.beginPath()
          this.context.lineCap = 'round'
          this.context.moveTo(30, 50)
          this.context.lineTo(220, 50)
          this.context.stroke()
        })
    }
    .width('100%')
    .height('100%')
  }
}
```

![en-us_image_0000001212378406](figures/en-us_image_0000001212378406.png)


### lineJoin

```ts
// xxx.ets
@Entry
@Component
struct LineJoinExample {
  private settings: RenderingContextSettings = new RenderingContextSettings(true)
  private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings)

  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
      Canvas(this.context)
        .width('100%')
        .height('100%')
        .backgroundColor('#ffff00')
        .onReady(() =>{
        this.context.beginPath()
        this.context.lineWidth = 8
        this.context.lineJoin = 'miter'
        this.context.moveTo(30, 30)
        this.context.lineTo(120, 60)
        this.context.lineTo(30, 110)
        this.context.stroke()
      })
    }
    .width('100%')
    .height('100%')
  }
}
```

![en-us_image_0000001212218438](figures/en-us_image_0000001212218438.png)


### miterLimit

```ts
// xxx.ets
@Entry
@Component
struct MiterLimit {
  private settings: RenderingContextSettings = new RenderingContextSettings(true)
  private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings)
  
  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
      Canvas(this.context)
        .width('100%')
        .height('100%')
        .backgroundColor('#ffff00')
        .onReady(() =>{
          this.context.lineWidth = 8
          this.context.lineJoin = 'miter'
          this.context.miterLimit = 3
          this.context.moveTo(30, 30)
          this.context.lineTo(60, 35)
          this.context.lineTo(30, 37)
          this.context.stroke()
      })
    }
    .width('100%')
    .height('100%')
  }
}
```

![en-us_image_0000001212378398](figures/en-us_image_0000001212378398.png)


### font

```ts
// xxx.ets
@Entry
@Component
struct Fonts {
  private settings: RenderingContextSettings = new RenderingContextSettings(true)
  private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings)

  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
      Canvas(this.context)
        .width('100%')
        .height('100%')
        .backgroundColor('#ffff00')
        .onReady(() =>{
          this.context.font = '30px sans-serif'
          this.context.fillText("Hello px", 20, 60)
          this.context.font = '30vp sans-serif'
          this.context.fillText("Hello vp", 20, 100)
        })
    }
    .width('100%')
    .height('100%')
  }
}
```

![en-us_image_0000001257058409](figures/en-us_image_0000001257058409.png)


### textAlign

```ts
// xxx.ets
@Entry
@Component
struct CanvasExample {
  private settings: RenderingContextSettings = new RenderingContextSettings(true)
  private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings)
  
  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
      Canvas(this.context)
        .width('100%')
        .height('100%')
        .backgroundColor('#ffff00')
        .onReady(() =>{
        this.context.strokeStyle = '#0000ff'
        this.context.moveTo(140, 10)
        this.context.lineTo(140, 160)
        this.context.stroke()
        this.context.font = '18px sans-serif'
        this.context.textAlign = 'start'
        this.context.fillText('textAlign=start', 140, 60)
        this.context.textAlign = 'end'
        this.context.fillText('textAlign=end', 140, 80)
        this.context.textAlign = 'left'
        this.context.fillText('textAlign=left', 140, 100)
        this.context.textAlign = 'center'
        this.context.fillText('textAlign=center',140, 120)
        this.context.textAlign = 'right'
        this.context.fillText('textAlign=right',140, 140)
      })
    }
    .width('100%')
    .height('100%')
  }
}
```

![en-us_image_0000001256978351](figures/en-us_image_0000001256978351.png)


### textBaseline

```ts
// xxx.ets
@Entry
@Component
struct TextBaseline {
  private settings: RenderingContextSettings = new RenderingContextSettings(true)
  private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings)
  
  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
      Canvas(this.context)
        .width('100%')
        .height('100%')
        .backgroundColor('#ffff00')
        .onReady(() =>{
          this.context.strokeStyle = '#0000ff'
          this.context.moveTo(0, 120)
          this.context.lineTo(400, 120)
          this.context.stroke()
          this.context.font = '20px sans-serif'
          this.context.textBaseline = 'top'
          this.context.fillText('Top', 10, 120)
          this.context.textBaseline = 'bottom'
          this.context.fillText('Bottom', 55, 120)
          this.context.textBaseline = 'middle'
          this.context.fillText('Middle', 125, 120)
          this.context.textBaseline = 'alphabetic'
          this.context.fillText('Alphabetic', 195, 120)
          this.context.textBaseline = 'hanging'
          this.context.fillText('Hanging', 295, 120)
      })
    }
    .width('100%')
    .height('100%')
  }
}
```

![en-us_image_0000001212058462](figures/en-us_image_0000001212058462.png)


### globalAlpha

```ts
// xxx.ets
@Entry
@Component
struct GlobalAlpha {
  private settings: RenderingContextSettings = new RenderingContextSettings(true)
  private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings)
  
  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
      Canvas(this.context)
        .width('100%')
        .height('100%')
        .backgroundColor('#ffff00')
        .onReady(() =>{
          this.context.fillStyle = 'rgb(0,0,255)'
          this.context.fillRect(0, 0, 50, 50)
          this.context.globalAlpha = 0.4
          this.context.fillStyle = 'rgb(0,0,255)'
          this.context.fillRect(50, 50, 50, 50)
      })
    }
    .width('100%')
    .height('100%')
  }
}
```

![en-us_image_0000001194192434](figures/en-us_image_0000001194192434.png)


### lineDashOffset

```ts
// xxx.ets
@Entry
@Component
struct LineDashOffset {
  private settings: RenderingContextSettings = new RenderingContextSettings(true)
  private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings)
  
  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
      Canvas(this.context)
        .width('100%')
        .height('100%')
        .backgroundColor('#ffff00')
        .onReady(() =>{
          this.context.arc(100, 75, 50, 0, 6.28)
          this.context.setLineDash([10,20])
          this.context.lineDashOffset = 10.0
          this.context.stroke()
      })
    }
    .width('100%')
    .height('100%')
  }
}
```

![en-us_image_0000001194352434](figures/en-us_image_0000001194352434.png)


### globalCompositeOperation

| Name              | Description                      |
| ---------------- | ------------------------ |
| source-over      | Displays the new drawing above the existing drawing. This attribute is used by default.  |
| source-atop      | Displays the new drawing on the top of the existing drawing.       |
| source-in        | Displays the new drawing inside the existing drawing.        |
| source-out       | Displays part of the new drawing that is outside of the existing drawing.       |
| destination-over | Displays the existing drawing above the new drawing.       |
| destination-atop | Displays the existing drawing on the top of the new drawing.       |
| destination-in   | Displays the existing drawing inside the new drawing.        |
| destination-out  | Displays the existing drawing outside the new drawing.        |
| lighter          | Displays both the new and existing drawing.         |
| copy             | Displays the new drawing and neglects the existing drawing.       |
| xor              | Combines the new drawing and existing drawing using the XOR operation.|

```ts
// xxx.ets
@Entry
@Component
struct GlobalCompositeOperation {
  private settings: RenderingContextSettings = new RenderingContextSettings(true)
  private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings)
  
  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
      Canvas(this.context)
        .width('100%')
        .height('100%')
        .backgroundColor('#ffff00')
        .onReady(() =>{
          this.context.fillStyle = 'rgb(255,0,0)'
          this.context.fillRect(20, 20, 50, 50)
          this.context.globalCompositeOperation = 'source-over'
          this.context.fillStyle = 'rgb(0,0,255)'
          this.context.fillRect(50, 50, 50, 50)
          this.context.fillStyle = 'rgb(255,0,0)'
          this.context.fillRect(120, 20, 50, 50)
          this.context.globalCompositeOperation = 'destination-over'
          this.context.fillStyle = 'rgb(0,0,255)'
          this.context.fillRect(150, 50, 50, 50)
      })
    }
    .width('100%')
    .height('100%')
  }
}
```

![en-us_image_0000001211898480](figures/en-us_image_0000001211898480.png)


### shadowBlur

```ts
// xxx.ets
@Entry
@Component
struct ShadowBlur {
  private settings: RenderingContextSettings = new RenderingContextSettings(true)
  private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings)
  
  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
      Canvas(this.context)
        .width('100%')
        .height('100%')
        .backgroundColor('#ffff00')
        .onReady(() =>{
          this.context.shadowBlur = 30
          this.context.shadowColor = 'rgb(0,0,0)'
          this.context.fillStyle = 'rgb(255,0,0)'
          this.context.fillRect(20, 20, 100, 80)
      })
    }
    .width('100%')
    .height('100%')
  }
}
```

![en-us_image_0000001256978343](figures/en-us_image_0000001256978343.png)


### shadowColor

```ts
// xxx.ets
@Entry
@Component
struct ShadowColor {
  private settings: RenderingContextSettings = new RenderingContextSettings(true)
  private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings)
  
  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
      Canvas(this.context)
        .width('100%')
        .height('100%')
        .backgroundColor('#ffff00')
        .onReady(() =>{
          this.context.shadowBlur = 30
          this.context.shadowColor = 'rgb(0,0,255)'
          this.context.fillStyle = 'rgb(255,0,0)'
          this.context.fillRect(30, 30, 100, 100)
      })
    }
    .width('100%')
    .height('100%')
  }
}
```

![en-us_image_0000001257138353](figures/en-us_image_0000001257138353.png)


### shadowOffsetX

```ts
// xxx.ets
@Entry
@Component
struct ShadowOffsetX {
  private settings: RenderingContextSettings = new RenderingContextSettings(true)
  private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings)
  
  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
      Canvas(this.context)
        .width('100%')
        .height('100%')
        .backgroundColor('#ffff00')
        .onReady(() =>{
          this.context.shadowBlur = 10
          this.context.shadowOffsetX = 20
          this.context.shadowColor = 'rgb(0,0,0)'
          this.context.fillStyle = 'rgb(255,0,0)'
          this.context.fillRect(20, 20, 100, 80)
      })
    }
    .width('100%')
    .height('100%')
  }
}
```

![en-us_image_0000001212218436](figures/en-us_image_0000001212218436.png)


### shadowOffsetY

```ts
// xxx.ets
@Entry
@Component
struct ShadowOffsetY {
  private settings: RenderingContextSettings = new RenderingContextSettings(true)
  private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings)
  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
      Canvas(this.context)
        .width('100%')
        .height('100%')
        .backgroundColor('#ffff00')
        .onReady(() =>{
          this.context.shadowBlur = 10
          this.context.shadowOffsetY = 20
          this.context.shadowColor = 'rgb(0,0,0)'
          this.context.fillStyle = 'rgb(255,0,0)'
          this.context.fillRect(30, 30, 100, 100)
      })
    }
    .width('100%')
    .height('100%')
  }
}
```

![en-us_image_0000001212378410](figures/en-us_image_0000001212378410.png)


### imageSmoothingEnabled

```ts
// xxx.ets
@Entry
@Component
struct ImageSmoothingEnabled {
  private settings: RenderingContextSettings = new RenderingContextSettings(true)
  private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings)
  private img:ImageBitmap = new ImageBitmap("common/images/icon.jpg")
  
  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
      Canvas(this.context)
        .width('100%')
        .height('100%')
        .backgroundColor('#ffff00')
        .onReady(() =>{
          this.context.imageSmoothingEnabled = false
          this.context.drawImage( this.img,0,0,400,200)
      })
    }
    .width('100%')
    .height('100%')
  }
}
```

![en-us_image_0000001211898472](figures/en-us_image_0000001211898472.png)


### height

```ts
// xxx.ets
@Entry
@Component
struct HeightExample {
  private settings: RenderingContextSettings = new RenderingContextSettings(true)
  private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings)

  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
      Canvas(this.context)
        .width(300)
        .height(300)
        .backgroundColor('#ffff00')
        .onReady(() => {
          let h = this.context.height
          this.context.fillRect(0, 0, 300, h/2)
        })
    }
    .width('100%')
    .height('100%')
  }
}
```

![en-us_image_canvas_height](figures/en-us_image_canvas_height.png)


### width

```ts
// xxx.ets
@Entry
@Component
struct WidthExample {
  private settings: RenderingContextSettings = new RenderingContextSettings(true)
  private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings)

  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
      Canvas(this.context)
        .width(300)
        .height(300)
        .backgroundColor('#ffff00')
        .onReady(() => {
          let w = this.context.width
          this.context.fillRect(0, 0, w/2, 300)
        })
    }
    .width('100%')
    .height('100%')
  }
}
```

![en-us_image_canvas_width](figures/en-us_image_canvas_width.png)


### imageSmoothingQuality

```ts
  // xxx.ets
  @Entry
  @Component
  struct ImageSmoothingQualityDemo {
    private settings: RenderingContextSettings = new RenderingContextSettings(true);
    private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings);
    private img:ImageBitmap = new ImageBitmap("common/images/example.jpg");

    build() {
      Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
        Canvas(this.context)
          .width('100%')
          .height('100%')
          .backgroundColor('#ffff00')
          .onReady(() =>{
            let ctx = this.context
            ctx.imageSmoothingEnabled = true
            ctx.imageSmoothingQuality = 'high'
            ctx.drawImage(this.img, 0, 0, 400, 200)
          })
      }
      .width('100%')
      .height('100%')
    }
  }
```

![ImageSmoothingQualityDemo](figures/ImageSmoothingQualityDemo.jpeg)


### direction

```ts
  // xxx.ets
  @Entry
  @Component
  struct DirectionDemo {
    private settings: RenderingContextSettings = new RenderingContextSettings(true);
    private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings);

    build() {
      Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
        Canvas(this.context)
          .width('100%')
          .height('100%')
          .backgroundColor('#ffff00')
          .onReady(() =>{
            let ctx = this.context
            ctx.font = '48px serif';
            ctx.textAlign = 'start'
            ctx.fillText("Hi ltr!", 200, 50);

            ctx.direction = "rtl";
            ctx.fillText("Hi rtl!", 200, 100);
          })
      }
      .width('100%')
      .height('100%')
    }
  }
```

![directionDemo](figures/directionDemo.jpeg)


### filter

```ts
  // xxx.ets
  @Entry
  @Component
  struct FilterDemo {
    private settings: RenderingContextSettings = new RenderingContextSettings(true);
    private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings);
    private img:ImageBitmap = new ImageBitmap("common/images/example.jpg");

    build() {
      Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
        Canvas(this.context)
          .width('100%')
          .height('100%')
          .backgroundColor('#ffff00')
          .onReady(() =>{
            let ctx = this.context
            let img = this.img

            ctx.drawImage(img, 0, 0, 100, 100);

            ctx.filter = 'grayscale(50%)';
            ctx.drawImage(img, 100, 0, 100, 100);

            ctx.filter = 'sepia(60%)';
            ctx.drawImage(img, 200, 0, 100, 100);

            ctx.filter = 'saturate(30%)';
            ctx.drawImage(img, 0, 100, 100, 100);

            ctx.filter = 'hue-rotate(90deg)';
            ctx.drawImage(img, 100, 100, 100, 100);

            ctx.filter = 'invert(100%)';
            ctx.drawImage(img, 200, 100, 100, 100);

            ctx.filter = 'opacity(25%)';
            ctx.drawImage(img, 0, 200, 100, 100);

            ctx.filter = 'brightness(0.4)';
            ctx.drawImage(img, 100, 200, 100, 100);

            ctx.filter = 'contrast(200%)';
            ctx.drawImage(img, 200, 200, 100, 100);

            ctx.filter = 'blur(5px)';
            ctx.drawImage(img, 0, 300, 100, 100);

            let result = ctx.toDataURL()
            console.info(result)
          })
      }
      .width('100%')
      .height('100%')
    }
  }
```

![filterDemo](figures/filterDemo.jpeg)

## Methods

Calls to the following methods on hidden pages will result in cache data. Therefore, avoid frequently refreshing the canvas on hidden pages.

### fillRect

fillRect(x: number, y: number, w: number, h: number): void

Fills a rectangle on the canvas.

This API can be used in ArkTS widgets since API version 9.

**Parameters**

| Name    | Type    | Mandatory  | Default Value | Description           |
| ------ | ------ | ---- | ---- | ------------- |
| x      | number | Yes   | 0    | X coordinate of the upper left corner of the rectangle, in vp.|
| y      | number | Yes   | 0    | Y coordinate of the upper left corner of the rectangle, in vp.|
| w      | number | Yes   | 0    | Width of the rectangle, in vp.|
| h      | number | Yes   | 0    | Height of the rectangle, in vp.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct FillRect {
    private settings: RenderingContextSettings = new RenderingContextSettings(true)
    private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings)
    
    build() {
      Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
        Canvas(this.context)
          .width('100%')
          .height('100%')
          .backgroundColor('#ffff00')
          .onReady(() =>{
            this.context.fillRect(30,30,100,100)
         })
        }
      .width('100%')
      .height('100%')
    }
  }
  ```

  ![en-us_image_0000001212218440](figures/en-us_image_0000001212218440.png)


### strokeRect

strokeRect(x: number, y: number, w: number, h: number): void

Draws an outlined rectangle on the canvas.

This API can be used in ArkTS widgets since API version 9.

**Parameters**

| Name  | Type    | Mandatory  | Default Value | Description          |
| ---- | ------ | ---- | ---- | ------------ |
| x    | number | Yes   | 0    | X coordinate of the upper left corner of the rectangle, in vp.|
| y    | number | Yes   | 0    | Y coordinate of the upper left corner of the rectangle, in vp.|
| w    | number | Yes   | 0    | Width of the rectangle, in vp.|
| h    | number | Yes   | 0    | Height of the rectangle, in vp.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct StrokeRect {
    private settings: RenderingContextSettings = new RenderingContextSettings(true)
    private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings)

    build() {
      Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
        Canvas(this.context)
          .width('100%')
          .height('100%')
          .backgroundColor('#ffff00')
          .onReady(() =>{
            this.context.strokeRect(30, 30, 200, 150)
        })
      }
      .width('100%')
      .height('100%')
    }
  }
  ```

  ![en-us_image_0000001257138359](figures/en-us_image_0000001257138359.png)


### clearRect

clearRect(x: number, y: number, w: number, h: number): void

Clears the content in a rectangle on the canvas.

This API can be used in ArkTS widgets since API version 9.

**Parameters**

| Name  | Type    | Mandatory  | Default Value | Description           |
| ---- | ------ | ---- | ---- | ------------- |
| x    | number | Yes   | 0    | X coordinate of the upper left corner of the rectangle, in vp.|
| y    | number | Yes   | 0    | Y coordinate of the upper left corner of the rectangle, in vp.|
| w    | number | Yes   | 0    | Width of the rectangle, in vp.|
| h    | number | Yes   | 0    | Height of the rectangle, in vp.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct ClearRect {
    private settings: RenderingContextSettings = new RenderingContextSettings(true)
    private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings)

    build() {
      Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
        Canvas(this.context)
          .width('100%')
          .height('100%')
          .backgroundColor('#ffff00')
          .onReady(() =>{
            this.context.fillStyle = 'rgb(0,0,255)'
            this.context.fillRect(20,20,200,200)
            this.context.clearRect(30,30,150,100)
        })
      }
      .width('100%')
      .height('100%')
    }
  }
  ```

  ![en-us_image_0000001211898482](figures/en-us_image_0000001211898482.png)


### fillText

fillText(text: string, x: number, y: number, maxWidth?: number): void

Draws filled text on the canvas.

This API can be used in ArkTS widgets since API version 9.

**Parameters**

| Name      | Type    | Mandatory  | Default Value | Description             |
| -------- | ------ | ---- | ---- | --------------- |
| text     | string | Yes   | ''   | Text to draw.     |
| x        | number | Yes   | 0    | X coordinate of the lower left corner of the text, in vp.|
| y        | number | Yes   | 0    | Y coordinate of the lower left corner of the text, in vp.|
| maxWidth | number | No   | -    | Maximum width allowed for the text, in vp.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct FillText {
    private settings: RenderingContextSettings = new RenderingContextSettings(true)
    private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings)

    build() {
      Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
        Canvas(this.context)
          .width('100%')
          .height('100%')
          .backgroundColor('#ffff00')
          .onReady(() =>{
            this.context.font = '30px sans-serif'
            this.context.fillText("Hello World!", 20, 100)
        })
      }
      .width('100%')
      .height('100%')
    }
  }
  ```

  ![en-us_image_0000001257058399](figures/en-us_image_0000001257058399.png)


### strokeText

strokeText(text: string, x: number, y: number, maxWidth?:number): void

Draws a text stroke on the canvas.

This API can be used in ArkTS widgets since API version 9.

**Parameters**

| Name      | Type    | Mandatory  | Default Value | Description             |
| -------- | ------ | ---- | ---- | --------------- |
| text     | string | Yes   | ''   | Text to draw.     |
| x        | number | Yes   | 0    | X coordinate of the lower left corner of the text, in vp.|
| y        | number | Yes   | 0    | Y coordinate of the lower left corner of the text, in vp.|
| maxWidth | number | No   | -    | Maximum width allowed for the text, in vp.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct StrokeText {
    private settings: RenderingContextSettings = new RenderingContextSettings(true)
    private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings)

    build() {
      Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
        Canvas(this.context)
          .width('100%')
          .height('100%')
          .backgroundColor('#ffff00')
          .onReady(() =>{
            this.context.font = '55px sans-serif'
            this.context.strokeText("Hello World!", 20, 60)
        })
      }
      .width('100%')
      .height('100%')
    }
  }
  ```

  ![en-us_image_0000001256978349](figures/en-us_image_0000001256978349.png)


### measureText

measureText(text: string): TextMetrics

Measures the specified text to obtain its width. This API returns a **TextMetrics** object.

This API can be used in ArkTS widgets since API version 9.

**Parameters**

| Name  | Type    | Mandatory  | Default Value | Description        |
| ---- | ------ | ---- | ---- | ---------- |
| text | string | Yes   | ''   | Text to be measured.|

**Return value**

| Type         | Description                                      |
| ----------- | ---------------------------------------- |
| [TextMetrics](#textmetrics) | **TextMetrics** object.<br>This API can be used in ArkTS widgets since API version 9.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct MeasureText {
    private settings: RenderingContextSettings = new RenderingContextSettings(true)
    private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings)

    build() {
      Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
        Canvas(this.context)
          .width('100%')
          .height('100%')
          .backgroundColor('#ffff00')
          .onReady(() =>{
            this.context.font = '50px sans-serif'
            this.context.fillText("Hello World!", 20, 100)
            this.context.fillText("width:" + this.context.measureText("Hello World!").width, 20, 200)
        })
      }
      .width('100%')
      .height('100%')
    }
  }
  ```

  ![en-us_image_0000001257138343](figures/en-us_image_0000001257138343.png)


### stroke

stroke(path?: Path2D): void

Strokes a path.

This API can be used in ArkTS widgets since API version 9.

**Parameters**

| Name  | Type                                      | Mandatory  | Default Value | Description          |
| ---- | ---------------------------------------- | ---- | ---- | ------------ |
| path | [Path2D](ts-components-canvas-path2d.md) | No   | null | A **Path2D** path to draw.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct Stroke {
    private settings: RenderingContextSettings = new RenderingContextSettings(true)
    private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings)

    build() {
      Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
        Canvas(this.context)
          .width('100%')
          .height('100%')
          .backgroundColor('#ffff00')
          .onReady(() =>{
            this.context.moveTo(25, 25)
            this.context.lineTo(25, 105)
            this.context.lineTo(75, 105)
            this.context.lineTo(75, 25)
            this.context.strokeStyle = 'rgb(0,0,255)'
            this.context.stroke()
          })
      }
      .width('100%')
      .height('100%')
    }
  }
  ```

  ![en-us_image_0000001257058411](figures/en-us_image_0000001257058411.png)


### beginPath

beginPath(): void

Creates a drawing path.

This API can be used in ArkTS widgets since API version 9.

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct BeginPath {
    private settings: RenderingContextSettings = new RenderingContextSettings(true)
    private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings)

    build() {
      Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
        Canvas(this.context)
          .width('100%')
          .height('100%')
          .backgroundColor('#ffff00')
          .onReady(() =>{
            this.context.beginPath()
            this.context.lineWidth = 6
            this.context.strokeStyle = '#0000ff'
            this.context.moveTo(15, 80)
            this.context.lineTo(280, 160)
            this.context.stroke()
          })
      }
      .width('100%')
      .height('100%')
    }
  }
  ```

  ![en-us_image_0000001212058478](figures/en-us_image_0000001212058478.png)


### moveTo

moveTo(x: number, y: number): void

Moves a drawing path to a target position on the canvas.

This API can be used in ArkTS widgets since API version 9.

**Parameters**

| Name  | Type    | Mandatory  | Default Value | Description       |
| ---- | ------ | ---- | ---- | --------- |
| x    | number | Yes   | 0    | X coordinate of the target position, in vp.|
| y    | number | Yes   | 0    | Y coordinate of the target position, in vp.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct MoveTo {
    private settings: RenderingContextSettings = new RenderingContextSettings(true)
    private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings)

    build() {
      Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
        Canvas(this.context)
          .width('100%')
          .height('100%')
          .backgroundColor('#ffff00')
          .onReady(() =>{
            this.context.beginPath()
            this.context.moveTo(10, 10)
            this.context.lineTo(280, 160)
            this.context.stroke()
          })
      }
      .width('100%')
      .height('100%')
    }
  }
  ```

  ![en-us_image_0000001256858391](figures/en-us_image_0000001256858391.png)


### lineTo

lineTo(x: number, y: number): void

Connects the current point to a target position using a straight line.

This API can be used in ArkTS widgets since API version 9.

**Parameters**

| Name  | Type    | Mandatory  | Default Value | Description       |
| ---- | ------ | ---- | ---- | --------- |
| x    | number | Yes   | 0    | X coordinate of the target position, in vp.|
| y    | number | Yes   | 0    | Y coordinate of the target position, in vp.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct LineTo {
    private settings: RenderingContextSettings = new RenderingContextSettings(true)
    private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings)

    build() {
      Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
        Canvas(this.context)
          .width('100%')
          .height('100%')
          .backgroundColor('#ffff00')
          .onReady(() =>{
            this.context.beginPath()
            this.context.moveTo(10, 10)
            this.context.lineTo(280, 160)
            this.context.stroke()
          })
      }
      .width('100%')
      .height('100%')
    }
  }
  ```

  ![en-us_image_0000001212378414](figures/en-us_image_0000001212378414.png)


### closePath

closePath(): void

Draws a closed path.

This API can be used in ArkTS widgets since API version 9.

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct ClosePath {
    private settings: RenderingContextSettings = new RenderingContextSettings(true)
    private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings)

    build() {
      Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
        Canvas(this.context)
          .width('100%')
          .height('100%')
          .backgroundColor('#ffff00')
          .onReady(() =>{
              this.context.beginPath()
              this.context.moveTo(30, 30)
              this.context.lineTo(110, 30)
              this.context.lineTo(70, 90)
              this.context.closePath()
              this.context.stroke()
          })
      }
      .width('100%')
      .height('100%')
    }
  }
  ```

  ![en-us_image_0000001256978347](figures/en-us_image_0000001256978347.png)


### createPattern

createPattern(image: ImageBitmap, repetition: string | null): CanvasPattern | null

Creates a pattern for image filling based on a specified source image and repetition mode.

This API can be used in ArkTS widgets since API version 9.

**Parameters**

| Name | Type | Mandatory | Default Value | Description |
| ---------- | ---------- | ---- | ---------- | ---------------------------------------- |
| image  | [ImageBitmap](ts-components-canvas-imagebitmap.md) | Yes |     | Source image. For details, see **ImageBitmap**.|
| repetition | string \| null  | Yes   | null    | Repetition mode.<br>**'repeat'**: The image is repeated along both the x-axis and y-axis.<br>**'repeat-x'**: The image is repeated along the x-axis.<br>**'repeat-y'**: The image is repeated along the y-axis.<br>**'no-repeat'**: The image is not repeated.<br>**'clamp'**: Coordinates outside the original bounds are clamped to the edge of the image.<br>**'mirror'**: The image is mirrored with each repetition along the x-axis and y-axis.|

**Return value**

| Type                                      | Description                     |
| ---------------------------------------- | ----------------------- |
| [CanvasPattern](ts-components-canvas-canvaspattern.md#canvaspattern) \| null | Created pattern for image filling based on a specified source image and repetition mode.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct CreatePattern {
    private settings: RenderingContextSettings = new RenderingContextSettings(true)
    private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings)
    private img:ImageBitmap = new ImageBitmap("common/images/icon.jpg")

    build() {
      Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
        Canvas(this.context)
          .width('100%')
          .height('100%')
          .backgroundColor('#ffff00')
          .onReady(() =>{
            let pattern = this.context.createPattern(this.img, 'repeat')
            if (pattern) {
              this.context.fillStyle = pattern
            }
            this.context.fillRect(0, 0, 200, 200)
          })
      }
      .width('100%')
      .height('100%')
    }
  }
  ```

  ![en-us_image_0000001211898490](figures/en-us_image_0000001211898490.png)


### bezierCurveTo

bezierCurveTo(cp1x: number, cp1y: number, cp2x: number, cp2y: number, x: number, y: number): void

Draws a cubic Bezier curve on the canvas.

This API can be used in ArkTS widgets since API version 9.

**Parameters**

| Name  | Type    | Mandatory  | Default Value | Description            |
| ---- | ------ | ---- | ---- | -------------- |
| cp1x | number | Yes   | 0    | X coordinate of the first parameter of the Bezier curve, in vp.|
| cp1y | number | Yes   | 0    | Y coordinate of the first parameter of the Bezier curve, in vp.|
| cp2x | number | Yes   | 0    | X coordinate of the second parameter of the Bezier curve, in vp.|
| cp2y | number | Yes   | 0    | Y coordinate of the second parameter of the Bezier curve, in vp.|
| x    | number | Yes   | 0    | X coordinate of the end point on the Bezier curve, in vp.|
| y    | number | Yes   | 0    | Y coordinate of the end point on the Bezier curve, in vp.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct BezierCurveTo {
    private settings: RenderingContextSettings = new RenderingContextSettings(true)
    private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings)

    build() {
      Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
        Canvas(this.context)
          .width('100%')
          .height('100%')
          .backgroundColor('#ffff00')
          .onReady(() =>{
            this.context.beginPath()
            this.context.moveTo(10, 10)
            this.context.bezierCurveTo(20, 100, 200, 100, 200, 20)
            this.context.stroke()
          })
      }
      .width('100%')
      .height('100%')
    }
  }
  ```

  ![en-us_image_0000001257138349](figures/en-us_image_0000001257138349.png)


### quadraticCurveTo

quadraticCurveTo(cpx: number, cpy: number, x: number, y: number): void

Draws a quadratic curve on the canvas.

This API can be used in ArkTS widgets since API version 9.

**Parameters**

| Name  | Type    | Mandatory  | Default Value | Description         |
| ---- | ------ | ---- | ---- | ----------- |
| cpx  | number | Yes   | 0    | X coordinate of the Bezier curve parameter, in vp.|
| cpy  | number | Yes   | 0    | Y coordinate of the Bezier curve parameter, in vp.|
| x    | number | Yes   | 0    | X coordinate of the end point on the Bezier curve, in vp.|
| y    | number | Yes   | 0    | Y coordinate of the end point on the Bezier curve, in vp.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct QuadraticCurveTo {
    private settings: RenderingContextSettings = new RenderingContextSettings(true)
    private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings)

    build() {
      Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
        Canvas(this.context)
          .width('100%')
          .height('100%')
          .backgroundColor('#ffff00')
          .onReady(() =>{
            this.context.beginPath()
            this.context.moveTo(20, 20)
            this.context.quadraticCurveTo(100, 100, 200, 20)
            this.context.stroke()
        })
      }
      .width('100%')
      .height('100%')
    }
  }
  ```

  ![en-us_image_0000001257058397](figures/en-us_image_0000001257058397.png)


### arc

arc(x: number, y: number, radius: number, startAngle: number, endAngle: number, counterclockwise?: boolean): void

Draws an arc on the canvas.

This API can be used in ArkTS widgets since API version 9.

**Parameters**

| Name              | Type     | Mandatory  | Default Value  | Description        |
| ---------------- | ------- | ---- | ----- | ---------- |
| x                | number  | Yes   | 0     | X coordinate of the center point of the arc, in vp.|
| y                | number  | Yes   | 0     | Y coordinate of the center point of the arc, in vp.|
| radius           | number  | Yes   | 0     | Radius of the arc, in vp.|
| startAngle       | number  | Yes   | 0     | Start radian of the arc.  |
| endAngle         | number  | Yes   | 0     | End radian of the arc.  |
| counterclockwise | boolean | No   | false | Whether to draw the arc counterclockwise.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct Arc {
    private settings: RenderingContextSettings = new RenderingContextSettings(true)
    private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings)

    build() {
      Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
        Canvas(this.context)
          .width('100%')
          .height('100%')
          .backgroundColor('#ffff00')
          .onReady(() =>{
            this.context.beginPath()
            this.context.arc(100, 75, 50, 0, 6.28)
            this.context.stroke()
          })
      }
      .width('100%')
      .height('100%')
    }
  }
  ```

  ![en-us_image_0000001212378404](figures/en-us_image_0000001212378404.png)


### arcTo

arcTo(x1: number, y1: number, x2: number, y2: number, radius: number): void

Draws an arc based on the radius and points on the arc.

This API can be used in ArkTS widgets since API version 9.

**Parameters**

| Name    | Type    | Mandatory  | Default Value | Description             |
| ------ | ------ | ---- | ---- | --------------- |
| x1     | number | Yes   | 0    | X coordinate of the first point on the arc, in vp.|
| y1     | number | Yes   | 0    | Y coordinate of the first point on the arc, in vp.|
| x2     | number | Yes   | 0    | X coordinate of the second point on the arc, in vp.|
| y2     | number | Yes   | 0    | Y coordinate of the second point on the arc, in vp.|
| radius | number | Yes   | 0    | Radius of the arc, in vp.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct ArcTo {
    private settings: RenderingContextSettings = new RenderingContextSettings(true)
    private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings)

    build() {
      Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
        Canvas(this.context)
          .width('100%')
          .height('100%')
          .backgroundColor('#ffff00')
          .onReady(() =>{
            this.context.moveTo(100, 20)
            this.context.arcTo(150, 20, 150, 70, 50)
            this.context.stroke()
          })
      }
      .width('100%')
      .height('100%')
    }
  }
  ```

  ![en-us_image_0000001257058413](figures/en-us_image_0000001257058413.png)


### ellipse

ellipse(x: number, y: number, radiusX: number, radiusY: number, rotation: number, startAngle: number, endAngle: number, counterclockwise?: boolean): void

Draws an ellipse in the specified rectangular region on the canvas.

This API can be used in ArkTS widgets since API version 9.

**Parameters**

| Name              | Type     | Mandatory  | Default Value  | Description                                      |
| ---------------- | ------- | ---- | ----- | ---------------------------------------- |
| x                | number  | Yes   | 0     | X coordinate of the ellipse center, in vp.|
| y                | number  | Yes   | 0     | Y coordinate of the ellipse center, in vp.|
| radiusX          | number  | Yes   | 0     | Ellipse radius on the x-axis, in vp.|
| radiusY          | number  | Yes   | 0     | Ellipse radius on the y-axis, in vp.|
| rotation         | number  | Yes   | 0     | Rotation angle of the ellipse. The unit is radian.                          |
| startAngle       | number  | Yes   | 0     | Angle of the start point for drawing the ellipse. The unit is radian.                       |
| endAngle         | number  | Yes   | 0     | Angle of the end point for drawing the ellipse. The unit is radian.                       |
| counterclockwise | boolean | No   | false | Whether to draw the ellipse in the counterclockwise direction.<br>**true**: Draw the arc counterclockwise.<br>**false**: Draw the arc clockwise.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct CanvasExample {
    private settings: RenderingContextSettings = new RenderingContextSettings(true)
    private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings)

    build() {
      Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
        Canvas(this.context)
          .width('100%')
          .height('100%')
          .backgroundColor('#ffff00')
          .onReady(() =>{
            this.context.beginPath()
            this.context.ellipse(200, 200, 50, 100, Math.PI * 0.25, Math.PI * 0.5, Math.PI * 2, false)
            this.context.stroke()
            this.context.beginPath()
            this.context.ellipse(200, 300, 50, 100, Math.PI * 0.25, Math.PI * 0.5, Math.PI * 2, true)
            this.context.stroke()
          })
      }
      .width('100%')
      .height('100%')
    }
  }
  ```

  ![en-us_image_0000001194192440](figures/en-us_image_0000001194192440.jpeg)


### rect

rect(x: number, y: number, w: number, h: number): void

Creates a rectangle on the canvas.

This API can be used in ArkTS widgets since API version 9.

**Parameters**

| Name  | Type    | Mandatory  | Default Value | Description           |
| ---- | ------ | ---- | ---- | ------------- |
| x    | number | Yes   | 0    | X coordinate of the upper left corner of the rectangle, in vp.|
| y    | number | Yes   | 0    | Y coordinate of the upper left corner of the rectangle, in vp.|
| w    | number | Yes   | 0    | Width of the rectangle, in vp.|
| h    | number | Yes   | 0    | Height of the rectangle, in vp.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct CanvasExample {
    private settings: RenderingContextSettings = new RenderingContextSettings(true)
    private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings)

    build() {
      Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
        Canvas(this.context)
          .width('100%')
          .height('100%')
          .backgroundColor('#ffff00')
          .onReady(() =>{
            this.context.rect(20, 20, 100, 100) // Create a 100*100 rectangle at (20, 20)
            this.context.stroke()
          })
      }
      .width('100%')
      .height('100%')
    }
  }
  ```

  ![en-us_image_0000001256978341](figures/en-us_image_0000001256978341.png)


### fill

fill(fillRule?: CanvasFillRule): void

Fills the area inside a closed path on the canvas.

This API can be used in ArkTS widgets since API version 9.

**Parameters**

| Name      | Type            | Mandatory  | Default Value      | Description                                      |
| -------- | -------------- | ---- | --------- | ---------------------------------------- |
| fillRule | [CanvasFillRule](ts-canvasrenderingcontext2d.md#canvasfillrule) | No   | "nonzero" | Rule by which to determine whether a point is inside or outside the area to fill.<br>The options are **"nonzero"** and **"evenodd"**.|


**Example**  

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct Fill {
    private settings: RenderingContextSettings = new RenderingContextSettings(true)
    private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings)

    build() {
      Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
        Canvas(this.context)
          .width('100%')
          .height('100%')
          .backgroundColor('#ffff00')
          .onReady(() =>{
            this.context.rect(20, 20, 100, 100) // Create a 100*100 rectangle at (20, 20)
            this.context.fill()
          })
      }
      .width('100%')
      .height('100%')
    }
  }
  ```

  ![en-us_image_0000001256858389](figures/en-us_image_0000001256858389.png)


fill(path: Path2D, fillRule?: CanvasFillRule): void

Fills the area inside a closed path on the canvas.

This API can be used in ArkTS widgets since API version 9.

**Parameters**

| Name      | Type            | Mandatory  | Default Value      | Description                                      |
| -------- | -------------- | ---- | --------- | ---------------------------------------- |
| path     | [Path2D](ts-components-canvas-path2d.md)         | Yes   |           | A **Path2D** path to fill.                             |
| fillRule | [CanvasFillRule](ts-canvasrenderingcontext2d.md#canvasfillrule) | No   | "nonzero" | Rule by which to determine whether a point is inside or outside the area to fill.<br>The options are **"nonzero"** and **"evenodd"**.|


**Example**  

```ts
// xxx.ets
@Entry
@Component
struct Fill {
  private settings: RenderingContextSettings = new RenderingContextSettings(true)
  private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings)

  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
      Canvas(this.context)
        .width('100%')
        .height('100%')
        .backgroundColor('#ffff00')
        .onReady(() =>{
          let region = new Path2D()
          region.moveTo(30, 90)
          region.lineTo(110, 20)
          region.lineTo(240, 130)
          region.lineTo(60, 130)
          region.lineTo(190, 20)
          region.lineTo(270, 90)
          region.closePath()
          // Fill path
          this.context.fillStyle = '#00ff00'
          this.context.fill(region, "evenodd")
        })
    }
    .width('100%')
    .height('100%')
  }
}
```

 ![en-us_image_000000127777774](figures/en-us_image_000000127777774.png)


### clip

clip(fillRule?: CanvasFillRule): void

Sets the current path to a clipping area.

This API can be used in ArkTS widgets since API version 9.

**Parameters**

| Name      | Type            | Mandatory  | Default Value      | Description                                      |
| -------- | -------------- | ---- | --------- | ---------------------------------------- |
| fillRule | [CanvasFillRule](#canvasfillrule) | No   | "nonzero" | Rule by which to determine whether a point is inside or outside the area to clip.<br>The options are **"nonzero"** and **"evenodd"**.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct Clip {
    private settings: RenderingContextSettings = new RenderingContextSettings(true)
    private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings)

    build() {
      Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
        Canvas(this.context)
          .width('100%')
          .height('100%')
          .backgroundColor('#ffff00')
          .onReady(() =>{
            this.context.rect(0, 0, 100, 200)
            this.context.stroke()
            this.context.clip()
            this.context.fillStyle = "rgb(255,0,0)"
            this.context.fillRect(0, 0, 200, 200)
          })
      }
      .width('100%')
      .height('100%')
    }
  }
  ```

  ![en-us_image_0000001211898488](figures/en-us_image_0000001211898488.png)


clip(path: Path2D, fillRule?: CanvasFillRule): void

Sets the current path to a clipping path.

This API can be used in ArkTS widgets since API version 9.

**Parameters**

| Name      | Type            | Mandatory  | Default Value      | Description                                      |
| -------- | -------------- | ---- | --------- | ---------------------------------------- |
| path     | [Path2D](ts-components-canvas-path2d.md)         | Yes   | -         | A **Path2D** path to use as a clipping area.                             |
| fillRule | [CanvasFillRule](#canvasfillrule) | No   | "nonzero" | Rule by which to determine whether a point is inside or outside the area to clip.<br>The options are **"nonzero"** and **"evenodd"**.|


**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct Clip {
    private settings: RenderingContextSettings = new RenderingContextSettings(true)
    private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings)
    build() {
      Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
        Canvas(this.context)
          .width('100%')
          .height('100%')
          .backgroundColor('#ffff00')
          .onReady(() =>{
            let region = new Path2D()
            region.moveTo(30, 90)
            region.lineTo(110, 20)
            region.lineTo(240, 130)
            region.lineTo(60, 130)
            region.lineTo(190, 20)
            region.lineTo(270, 90)
            region.closePath()
            this.context.clip(region,"evenodd")
            this.context.fillStyle = "rgb(0,255,0)"
            this.context.fillRect(0, 0, this.context.width, this.context.height)
          })
      }
      .width('100%')
      .height('100%')
    }
  }
  ```

  ![en-us_image_000000127777779](figures/en-us_image_000000127777779.png)


### resetTransform

resetTransform(): void

Resets the current transform to the identity matrix. This API is a void API.

This API can be used in ArkTS widgets since API version 9.


### rotate

rotate(angle: number): void

Rotates a canvas clockwise around its coordinate axes.

This API can be used in ArkTS widgets since API version 9.

**Parameters**

| Name   | Type    | Mandatory  | Default Value | Description                                      |
| ----- | ------ | ---- | ---- | ---------------------------------------- |
| angle | number | Yes   | 0    | Clockwise rotation angle. You can use **Math.PI / 180** to convert the angle to a radian.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct Rotate {
    private settings: RenderingContextSettings = new RenderingContextSettings(true)
    private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings)

    build() {
      Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
        Canvas(this.context)
          .width('100%')
          .height('100%')
          .backgroundColor('#ffff00')
          .onReady(() =>{
            this.context.rotate(45 * Math.PI / 180)
            this.context.fillRect(70, 20, 50, 50)
          })
      }
      .width('100%')
      .height('100%')
    }
  }
  ```

  ![en-us_image_0000001212218442](figures/en-us_image_0000001212218442.png)


### scale

scale(x: number, y: number): void

Scales the canvas based on the given scale factors.

This API can be used in ArkTS widgets since API version 9.

**Parameters**

| Name  | Type    | Mandatory  | Default Value | Description         |
| ---- | ------ | ---- | ---- | ----------- |
| x    | number | Yes   | 0    | Horizontal scale factor.|
| y    | number | Yes   | 0    | Vertical scale factor.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct Scale {
    private settings: RenderingContextSettings = new RenderingContextSettings(true)
    private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings)

    build() {
      Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
        Canvas(this.context)
          .width('100%')
          .height('100%')
          .backgroundColor('#ffff00')
          .onReady(() =>{
            this.context.lineWidth = 3
            this.context.strokeRect(30, 30, 50, 50)
            this.context.scale(2, 2) // Scale to 200%
            this.context.strokeRect(30, 30, 50, 50)
          })
      }
      .width('100%')
      .height('100%')
    }
  }
  ```

  ![en-us_image_0000001257138347](figures/en-us_image_0000001257138347.png)


### transform

transform(a: number, b: number, c: number, d: number, e: number, f: number): void

Defines a transformation matrix. To transform a graph, you only need to set parameters of the matrix. The coordinates of the graph are multiplied by the matrix values to obtain new coordinates of the transformed graph. You can use the matrix to implement multiple transform effects.

This API can be used in ArkTS widgets since API version 9.

> **NOTE**
> The following formulas calculate coordinates of the transformed graph. **x** and **y** represent coordinates before transformation, and **x'** and **y'** represent coordinates after transformation.
>
> - x' = scaleX \* x + skewY \* y + translateX
>
> - y' = skewX \* x + scaleY \* y + translateY

**Parameters**

| Name  | Type    | Mandatory  | Default Value | Description                  |
| ---- | ------ | ---- | ---- | -------------------- |
| a    | number | Yes   | 0    | X-axis scale.    |
| b    | number | Yes   | 0    | X-axis skew.     |
| c    | number | Yes   | 0    | Y-axis skew.     |
| d    | number | Yes   | 0    | Y-axis scale.    |
| e    | number | Yes   | 0    | X-axis translation, in vp.|
| f    | number | Yes   | 0    | Y-axis translation, in vp.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct Transform {
    private settings: RenderingContextSettings = new RenderingContextSettings(true)
    private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings)

    build() {
      Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
        Canvas(this.context)
          .width('100%')
          .height('100%')
          .backgroundColor('#ffff00')
          .onReady(() =>{
            this.context.fillStyle = 'rgb(0,0,0)'
            this.context.fillRect(0, 0, 100, 100)
            this.context.transform(1, 0.5, -0.5, 1, 10, 10)
            this.context.fillStyle = 'rgb(255,0,0)'
            this.context.fillRect(0, 0, 100, 100)
            this.context.transform(1, 0.5, -0.5, 1, 10, 10)
            this.context.fillStyle = 'rgb(0,0,255)'
            this.context.fillRect(0, 0, 100, 100)
          })
      }
      .width('100%')
      .height('100%')
    }
  }
  ```

  ![en-us_image_0000001256858393](figures/en-us_image_0000001256858393.png)


### setTransform

setTransform(a: number, b: number, c: number, d: number, e: number, f: number): void

Resets the existing transformation matrix and creates a new transformation matrix by using the same parameters as the **transform()** API.

This API can be used in ArkTS widgets since API version 9.

**Parameters**

| Name  | Type    | Mandatory  | Default Value | Description                  |
| ---- | ------ | ---- | ---- | -------------------- |
| a    | number | Yes   | 0    | X-axis scale.    |
| b    | number | Yes   | 0    | Y-axis skew.     |
| c    | number | Yes   | 0    | X-axis skew.     |
| d    | number | Yes   | 0    | Y-axis scale.    |
| e    | number | Yes   | 0    | X-axis translation, in vp.|
| f    | number | Yes   | 0    | Y-axis translation, in vp.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct SetTransform {
    private settings: RenderingContextSettings = new RenderingContextSettings(true)
    private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings)

    build() {
      Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
        Canvas(this.context)
          .width('100%')
          .height('100%')
          .backgroundColor('#ffff00')
          .onReady(() =>{
            this.context.fillStyle = 'rgb(255,0,0)'
            this.context.fillRect(0, 0, 100, 100)
            this.context.setTransform(1,0.5, -0.5, 1, 10, 10)
            this.context.fillStyle = 'rgb(0,0,255)'
            this.context.fillRect(0, 0, 100, 100)
          })
      }
      .width('100%')
      .height('100%')
    }
  }
  ```

  ![en-us_image_0000001256858395](figures/en-us_image_0000001256858395.png)

### setTransform

setTransform(transform?: Matrix2D): void

Resets the current transformation to the identity matrix, and then creates a new transformation matrix based on the specified **Matrix2D** object.

This API can be used in ArkTS widgets since API version 9.

**Parameters**

| Name       | Type                                      | Mandatory  | Default Value | Description   |
| --------- | ---------------------------------------- | ---- | ---- | ----- |
| transform | [Matrix2D](ts-components-canvas-matrix2d.md#Matrix2D) | No   | null | Transformation matrix.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct TransFormDemo {
    private settings: RenderingContextSettings = new RenderingContextSettings(true);
    private context1: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.  settings);
    private context2: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings);

    build() {
      Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
        Text('context1');
        Canvas(this.context1)
          .width('230vp')
          .height('160vp')
          .backgroundColor('#ffff00')
          .onReady(() =>{
            this.context1.fillRect(100, 20, 50, 50);
            this.context1.setTransform(1, 0.5, -0.5, 1, 10, 10);
            this.context1.fillRect(100, 20, 50, 50);
          })
        Text('context2');
        Canvas(this.context2)
          .width('230vp')
          .height('160vp')
          .backgroundColor('#0ffff0')
          .onReady(() =>{
            this.context2.fillRect(100, 20, 50, 50);
            let storedTransform = this.context1.getTransform();
            this.context2.setTransform(storedTransform);
            this.context2.fillRect(100, 20, 50, 50);
          })
      }
      .width('100%')
      .height('100%')
    }
  }
  ```

  ![en-us_image_0000001238712422.jpeg](figures/en-us_image_0000001238712422.jpeg)

### getTransform

getTransform(): Matrix2D

Obtains the current transformation matrix being applied to the context.

This API can be used in ArkTS widgets since API version 9.

**Return value**

| Type                                      | Description   |
| ---------------------------------------- | ----- |
| [Matrix2D](ts-components-canvas-matrix2d.md#Matrix2D) | **Matrix2D** object.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct TransFormDemo {
    private settings: RenderingContextSettings = new RenderingContextSettings(true);
    private context1: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings);
    private context2: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings);

    build() {
      Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
        Text('context1');
        Canvas(this.context1)
          .width('230vp')
          .height('120vp')
          .backgroundColor('#ffff00')
          .onReady(() =>{
            this.context1.fillRect(50, 50, 50, 50);
            this.context1.setTransform(1.2, Math.PI/8, Math.PI/6, 0.5, 30, -25);
            this.context1.fillRect(50, 50, 50, 50);
          })
        Text('context2');
        Canvas(this.context2)
          .width('230vp')
          .height('120vp')
          .backgroundColor('#0ffff0')
          .onReady(() =>{
            this.context2.fillRect(50, 50, 50, 50);
            let storedTransform = this.context1.getTransform();
            console.log("Matrix [scaleX = " + storedTransform.scaleX + ", scaleY = " + storedTransform.scaleY +
            ", rotateX = " + storedTransform.rotateX + ", rotateY = " + storedTransform.rotateY +
            ", translateX = " + storedTransform.translateX + ", translateY = " + storedTransform.translateY + "]")
            this.context2.setTransform(storedTransform);
            this.context2.fillRect(50,50,50,50);
          })
      }
      .width('100%')
      .height('100%')
    }
  }
  ```

  ![en-us_image_0000001219982726.png](figures/en-us_image_0000001219982726.png)

### translate

translate(x: number, y: number): void

Moves the origin of the coordinate system.

This API can be used in ArkTS widgets since API version 9.

**Parameters**

| Name  | Type    | Mandatory  | Default Value | Description      |
| ---- | ------ | ---- | ---- | -------- |
| x    | number | Yes   | 0    | X-axis translation, in vp.|
| y    | number | Yes   | 0    | Y-axis translation, in vp.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct Translate {
    private settings: RenderingContextSettings = new RenderingContextSettings(true)
    private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings)

    build() {
      Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
        Canvas(this.context)
          .width('100%')
          .height('100%')
          .backgroundColor('#ffff00')
          .onReady(() =>{
            this.context.fillRect(10, 10, 50, 50)
            this.context.translate(70, 70)
            this.context.fillRect(10, 10, 50, 50)
          })
      }
      .width('100%')
      .height('100%')
    }
  }
  ```

  ![en-us_image_0000001257138357](figures/en-us_image_0000001257138357.png)


### drawImage

drawImage(image: ImageBitmap | PixelMap, dx: number, dy: number): void

drawImage(image: ImageBitmap | PixelMap, dx: number, dy: number, dw: number, dh: number): void

drawImage(image: ImageBitmap | PixelMap, sx: number, sy: number, sw: number, sh: number, dx: number, dy: number, dw: number, dh: number):void

Draws an image on the canvas.

Since API version 9, this API is supported in ArkTS widgets, except that **PixelMap** objects are not supported.

**Parameters**

| Name   | Type                                      | Mandatory  | Default Value | Description                                      |
| ----- | ---------------------------------------- | ---- | ---- | ---------------------------------------- |
| image | [ImageBitmap](ts-components-canvas-imagebitmap.md) or [PixelMap](../../apis-image-kit/js-apis-image.md#pixelmap7)| Yes   | null | Image resource. For details, see **ImageBitmap** or PixelMap.           |
| sx    | number                                   | No   | 0    | X coordinate of the upper left corner of the rectangle used to crop the source image, in vp.|
| sy    | number                                   | No   | 0    | Y coordinate of the upper left corner of the rectangle used to crop the source image, in vp.|
| sw    | number                                   | No   | 0    | Target width by which the source image is cropped, in vp.|
| sh    | number                                   | No   | 0    | Target height by which the source image is cropped, in vp.|
| dx    | number                                   | Yes   | 0    | X coordinate of the upper left corner of the drawing area on the canvas, in vp.|
| dy    | number                                   | Yes   | 0    | Y coordinate of the upper left corner of the drawing area on the canvas, in vp.|
| dw    | number                                   | No   | 0    | Width of the drawing area. If the width of the drawing area is different from that of the cropped image, the latter will be stretched or compressed to the former.<br>Unit: vp|
| dh    | number                                   | No   | 0    | Height of the drawing area. If the height of the drawing area is different from that of the cropped image, the latter will be stretched or compressed to the former.<br>Unit: vp|


**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct ImageExample {
    private settings: RenderingContextSettings = new RenderingContextSettings(true)
    private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings)
    private img:ImageBitmap = new ImageBitmap("common/images/example.jpg")

    build() {
      Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
        Canvas(this.context)
          .width('100%')
          .height('100%')
          .backgroundColor('#ffff00')
          .onReady(() =>{
            this.context.drawImage( this.img,0,0,500,500,0,0,400,200)
        })
      }
      .width('100%')
      .height('100%')
    }
  }
  ```

  ![en-us_image_0000001212058466](figures/en-us_image_0000001212058466.png)


### createImageData

createImageData(sw: number, sh: number): ImageData

Creates an **ImageData** object with the same width and height of the current **ImageData** object. For details, see [ImageData](ts-components-canvas-imagedata.md). The example is the same as that of **putImageData**.

This API can be used in ArkTS widgets since API version 9.

**Parameters**

| Name  | Type    | Mandatory  | Default Value  | Description           |
| ---- | ------ | ---- | ---- | ------------- |
| sw   | number | Yes   | 0    | Width of the **ImageData** object, in vp.|
| sh   | number | Yes   | 0    | Height of the **ImageData** object, in vp.|


createImageData(imageData: ImageData): ImageData

Creates an **[ImageData](ts-components-canvas-imagedata.md)** object. The example is the same as that of **putImageData**.

This API can be used in ArkTS widgets since API version 9.

**Parameters**

| Name       | Type                                      | Mandatory  | Default Value  | Description               |
| --------- | ---------------------------------------- | ---- | ---- | ----------------- |
| imagedata | [ImageData](ts-components-canvas-imagedata.md) | Yes   | null | **ImageData** object with the same width and height copied from the original **ImageData** object.|

  **Return value**

| Type                                      | Description            |
| ---------------------------------------- | -------------- |
| [ImageData](ts-components-canvas-imagedata.md) | New **ImageData** object.|


### getPixelMap

getPixelMap(sx: number, sy: number, sw: number, sh: number): PixelMap

Obtains the [PixelMap](../../apis-image-kit/js-apis-image.md#pixelmap7) object created with the pixels within the specified area on the canvas. This API involves time-consuming memory copy. Therefore, avoid frequent calls to it.

**Parameters**

| Name  | Type    | Mandatory  | Default Value | Description             |
| ---- | ------ | ---- | ---- | --------------- |
| sx   | number | Yes   | 0    | X coordinate of the upper left corner of the output area, in vp.|
| sy   | number | Yes   | 0    | Y coordinate of the upper left corner of the output area, in vp.|
| sw   | number | Yes   | 0    | Width of the output area, in vp.|
| sh   | number | Yes   | 0    | Height of the output area, in vp.|

**Return value**

| Type                                      | Description           |
| ---------------------------------------- | ------------- |
| [PixelMap](../../apis-image-kit/js-apis-image.md#pixelmap7) | **PixelMap** object.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct GetPixelMap {
    private settings: RenderingContextSettings = new RenderingContextSettings(true)
    private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings)
    private img:ImageBitmap = new ImageBitmap("/images/star.png")

    build() {
      Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
        Canvas(this.context)
          .width('100%')
          .height('100%')
          .backgroundColor('#ffff00')
          .onReady(() =>{
            this.context.drawImage(this.img,0,0,130,130)
            let pixelmap = this.context.getPixelMap(50,50,130,130)
            this.context.drawImage(pixelmap,150,150)
          })
      }
      .width('100%')
      .height('100%')
    }
  } 
  ```

  ![en-us_image_000000127777782](figures/en-us_image_000000127777782.jpeg)

### getImageData

getImageData(sx: number, sy: number, sw: number, sh: number): ImageData

Obtains the [ImageData](ts-components-canvas-imagedata.md) object created with the pixels within the specified area on the canvas. This API involves time-consuming memory copy. Therefore, avoid frequent calls to it.

This API can be used in ArkTS widgets since API version 9.

**Parameters**

| Name  | Type    | Mandatory  | Default Value | Description             |
| ---- | ------ | ---- | ---- | --------------- |
| sx   | number | Yes   | 0    | X coordinate of the upper left corner of the output area, in vp.|
| sy   | number | Yes   | 0    | Y coordinate of the upper left corner of the output area, in vp.|
| sw   | number | Yes   | 0    | Width of the output area, in vp.|
| sh   | number | Yes   | 0    | Height of the output area, in vp.|

  **Return value**

| Type                                      | Description            |
| ---------------------------------------- | -------------- |
| [ImageData](ts-components-canvas-imagedata.md) | New **ImageData** object.|


**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct GetImageData {
    private settings: RenderingContextSettings = new RenderingContextSettings(true)
    private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings)
    private img:ImageBitmap = new ImageBitmap("/common/images/1234.png")

    build() {
      Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
        Canvas(this.context)
          .width('100%')
          .height('100%')
          .backgroundColor('#ffff00')
          .onReady(() =>{
            this.context.drawImage(this.img,0,0,130,130)
            let imagedata = this.context.getImageData(50,50,130,130)
            this.context.putImageData(imagedata,150,150)
          })
      }
      .width('100%')
      .height('100%')
    }
  }
  ```

  ![en-us_image_000000127777780](figures/en-us_image_000000127777780.png)


### putImageData

putImageData(imageData: ImageData, dx: number | string, dy: number | string): void

putImageData(imageData: ImageData, dx: number | string, dy: number | string, dirtyX: number | string, dirtyY: number | string, dirtyWidth: number | string, dirtyHeight: number | string): void

Puts an **[ImageData](ts-components-canvas-imagedata.md)** object onto a rectangular area on the canvas.

This API can be used in ArkTS widgets since API version 9.

**Parameters**

| Name         | Type                                      | Mandatory  | Default Value         | Description                           |
| ----------- | ---------------------------------------- | ---- | ------------ | ----------------------------- |
| imagedata   | [ImageData](ts-components-canvas-imagedata.md) | Yes   | null         | **ImageData** object with pixels to put onto the canvas.|
| dx          | number \| string<sup>10+</sup> | Yes   | 0            | X-axis offset of the rectangular area on the canvas, in vp.|
| dy          | number \| string<sup>10+</sup> | Yes   | 0            | Y-axis offset of the rectangular area on the canvas, in vp.|
| dirtyX      | number \| string<sup>10+</sup> | No   | 0            | X-axis offset of the upper left corner of the rectangular area relative to that of the source image, in vp.|
| dirtyY      | number \| string<sup>10+</sup> | No   | 0            | Y-axis offset of the upper left corner of the rectangular area relative to that of the source image, in vp.|
| dirtyWidth  | number \| string<sup>10+</sup> | No   | Width of the **ImageData** object| Width of the rectangular area by which the source image is cropped, in vp.|
| dirtyHeight | number \| string<sup>10+</sup> | No   | Height of the **ImageData** object| Height of the rectangular area by which the source image is cropped, in vp.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct PutImageData {
    private settings: RenderingContextSettings = new RenderingContextSettings(true)
    private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings)

    build() {
      Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
        Canvas(this.context)
          .width('100%')
          .height('100%')
          .backgroundColor('#ffff00')
          .onReady(() =>{
            let imageDataNum = this.context.createImageData(100, 100)
            for (let i = 0; i < imageDataNum.data.length; i += 4) {
              imageDataNum.data[i + 0] = 255
              imageDataNum.data[i + 1] = 0
              imageDataNum.data[i + 2] = 255
              imageDataNum.data[i + 3] = 255
            }
            let imageData = this.context.createImageData(imageDataNum)
            this.context.putImageData(imageData, 10, 10)
          })
      }
      .width('100%')
      .height('100%')
    }
  }
  ```

  ![en-us_image_0000001212378396](figures/en-us_image_0000001212378396.png)


### setLineDash

setLineDash(segments: number[]): void

Sets the dash line style.

This API can be used in ArkTS widgets since API version 9.

**Parameters**

| Name      | Type      | Description                 |
| -------- | -------- | ------------------- |
| segments | number[] | An array of numbers that specify distances, in vp, to alternately draw a line and a gap.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct SetLineDash {
    private settings: RenderingContextSettings = new RenderingContextSettings(true)
    private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings)
    
    build() {
      Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
        Canvas(this.context)
          .width('100%')
          .height('100%')
          .backgroundColor('#ffff00')
          .onReady(() =>{
            this.context.arc(100, 75, 50, 0, 6.28)
            this.context.setLineDash([10,20])
            this.context.stroke()
          })
      }
      .width('100%')
      .height('100%')
    }
  }
  ```

  ![en-us_image_000000127777771](figures/en-us_image_000000127777771.png)


### getLineDash

getLineDash(): number[]

Obtains the dash line style.

This API can be used in ArkTS widgets since API version 9.

**Return value**

| Type      | Description                      |
| -------- | ------------------------ |
| number[] | An array of numbers that specify distances, in vp, to alternately draw a line and a gap.|


**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct CanvasGetLineDash {
    @State message: string = 'Hello World'
    private settings: RenderingContextSettings = new RenderingContextSettings(true)
    private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings)

    build() {
      Row() {
        Column() {
          Text(this.message)
            .fontSize(50)
            .fontWeight(FontWeight.Bold)
            .onClick(()=>{
              console.error('before getlinedash clicked')
              let res = this.context.getLineDash()
              console.error(JSON.stringify(res))
            })
          Canvas(this.context)
            .width('100%')
            .height('100%')
            .backgroundColor('#ffff00')
            .onReady(() => {
              this.context.arc(100, 75, 50, 0, 6.28)
              this.context.setLineDash([10,20])
              this.context.stroke()
            })
        }
        .width('100%')
      }
      .height('100%')
    }
  }
  ```
![en-us_image_000000127777778](figures/en-us_image_000000127777778.png) 


### transferFromImageBitmap

transferFromImageBitmap(bitmap: ImageBitmap): void

Displays the specified **ImageBitmap** object.

This API can be used in ArkTS widgets since API version 9.

**Parameters**

| Name    | Type                                      | Description                |
| ------ | ---------------------------------------- | ------------------ |
| bitmap | [ImageBitmap](ts-components-canvas-imagebitmap.md) | **ImageBitmap** object to display.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct TransferFromImageBitmap {
    private settings: RenderingContextSettings = new RenderingContextSettings(true)
    private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings)
    private offContext: OffscreenCanvasRenderingContext2D = new OffscreenCanvasRenderingContext2D(600, 600, this.settings)

    build() {
      Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
        Canvas(this.context)
          .width('100%')
          .height('100%')
          .backgroundColor('#ffff00')
          .onReady(() =>{
            let imageData = this.offContext.createImageData(100, 100)
            for (let i = 0; i < imageData.data.length; i += 4) {
              imageData.data[i + 0] = 255
              imageData.data[i + 1] = 0
              imageData.data[i + 2] = 255
              imageData.data[i + 3] = 255
            }
            this.offContext.putImageData(imageData, 10, 10)
            let image = this.offContext.transferToImageBitmap()
            this.context.transferFromImageBitmap(image)
          })
      }
      .width('100%')
      .height('100%')
    }
  }
  ```
  ![en-us_image_000000127777773](figures/en-us_image_000000127777773.png)  


### toDataURL

toDataURL(type?: string, quality?: number): string

Generates a URL containing image display information.

This API can be used in ArkTS widgets since API version 9.

**Parameters**

| Name    | Type  | Mandatory  | Default Value        | Description                                      |
| ------- | ------ | ---- | ----------- | ---------------------------------------- |
| type    | string | No   | "image/png" | Image format. The default value is **image/png**.           |
| quality | number | No   | 0.92        | Image quality, which ranges from 0 to 1, when the image format is **image/jpeg** or **image/webp**. If the set value is beyond the value range, the default value **0.92** is used.|

**Return value**

| Type    | Description       |
| ------ | --------- |
| string | Image URL.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct CanvasExample {
    private settings: RenderingContextSettings = new RenderingContextSettings(true)
    private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings)
    @State toDataURL: string = ""

    build() {
      Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
        Canvas(this.context)
          .width(100)
          .height(100)
          .onReady(() =>{
            this.context.fillStyle = "#00ff00"
            this.context.fillRect(0,0,100,100)
            this.toDataURL = this.context.toDataURL("image/png", 0.92)
          })
        Text(this.toDataURL)
      }
      .width('100%')
      .height('100%')
      .backgroundColor('#ffff00')
    }
  }
  ```
  ![en-us_image_0000001238952387](figures/en-us_image_0000001194192441.png)  


### restore

restore(): void

Restores the saved drawing context.

This API can be used in ArkTS widgets since API version 9.

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct CanvasExample {
    private settings: RenderingContextSettings = new RenderingContextSettings(true)
    private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings)

    build() {
      Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
        Canvas(this.context)
          .width('100%')
          .height('100%')
          .backgroundColor('#ffff00')
          .onReady(() =>{
            this.context.save() // save the default state
            this.context.fillStyle = "#00ff00"
            this.context.fillRect(20, 20, 100, 100)
            this.context.restore() // restore to the default state
            this.context.fillRect(150, 75, 100, 100)
          })
      }
      .width('100%')
      .height('100%')
    }
  }
  ```
  ![en-us_image_000000127777781](figures/en-us_image_000000127777781.png)


### save

save(): void

Saves all states of the canvas in the stack. This API is usually called when the drawing state needs to be saved.

This API can be used in ArkTS widgets since API version 9.

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct CanvasExample {
    private settings: RenderingContextSettings = new RenderingContextSettings(true)
    private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings)

    build() {
      Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
        Canvas(this.context)
          .width('100%')
          .height('100%')
          .backgroundColor('#ffff00')
          .onReady(() =>{
            this.context.save() // save the default state
            this.context.fillStyle = "#00ff00"
            this.context.fillRect(20, 20, 100, 100)
            this.context.restore() // restore to the default state
            this.context.fillRect(150, 75, 100, 100)
          })
      }
      .width('100%')
      .height('100%')
    }
  }
  ```
  ![en-us_image_000000127777781](figures/en-us_image_000000127777781.png)


### createLinearGradient

createLinearGradient(x0: number, y0: number, x1: number, y1: number): CanvasGradient

Creates a linear gradient.

This API can be used in ArkTS widgets since API version 9.

**Parameters**

| Name  | Type    | Mandatory  | Default Value | Description      |
| ---- | ------ | ---- | ---- | -------- |
| x0   | number | Yes   | 0    | X coordinate of the start point, in vp.|
| y0   | number | Yes   | 0    | Y coordinate of the start point, in vp.|
| x1   | number | Yes   | 0    | X coordinate of the end point, in vp.|
| y1   | number | Yes   | 0    | Y coordinate of the end point, in vp.|

**Return value**

| Type    | Description       |
| ------ | --------- |
| [CanvasGradient](ts-components-canvas-canvasgradient.md) | New **CanvasGradient** object used to create a gradient on the canvas.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct CreateLinearGradient {
    private settings: RenderingContextSettings = new RenderingContextSettings(true)
    private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings)
    
    build() {
      Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
        Canvas(this.context)
          .width('100%')
          .height('100%')
          .backgroundColor('#ffff00')
          .onReady(() =>{
            let grad = this.context.createLinearGradient(50,0, 300,100)
            grad.addColorStop(0.0, '#ff0000')
            grad.addColorStop(0.5, '#ffffff')
            grad.addColorStop(1.0, '#00ff00')
            this.context.fillStyle = grad
            this.context.fillRect(0, 0, 400, 400)
          })
      }
      .width('100%')
      .height('100%')
    }
  }
  ```

  ![en-us_image_0000001212378412](figures/en-us_image_0000001212378412.png)


### createRadialGradient

createRadialGradient(x0: number, y0: number, r0: number, x1: number, y1: number, r1: number): CanvasGradient

Creates a linear gradient.

This API can be used in ArkTS widgets since API version 9.

**Parameters**

| Name  | Type    | Mandatory  | Default Value | Description               |
| ---- | ------ | ---- | ---- | ----------------- |
| x0   | number | Yes   | 0    | X coordinate of the center of the start circle, in vp.|
| y0   | number | Yes   | 0    | Y coordinate of the center of the start circle, in vp.|
| r0   | number | Yes   | 0    | Radius of the start circle, in vp. The value must be a non-negative finite number.|
| x1   | number | Yes   | 0    | X coordinate of the center of the end circle, in vp.|
| y1   | number | Yes   | 0    | Y coordinate of the center of the end circle, in vp.|
| r1   | number | Yes   | 0    | Radius of the end circle, in vp. The value must be a non-negative finite number.|

**Return value**

| Type    | Description       |
| ------ | --------- |
| [CanvasGradient](ts-components-canvas-canvasgradient.md) | New **CanvasGradient** object used to create a gradient on the canvas.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct CreateRadialGradient {
    private settings: RenderingContextSettings = new RenderingContextSettings(true)
    private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings)
    
    build() {
      Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
        Canvas(this.context)
          .width('100%')
          .height('100%')
          .backgroundColor('#ffff00')
          .onReady(() =>{
            let grad = this.context.createRadialGradient(200,200,50, 200,200,200)
            grad.addColorStop(0.0, '#ff0000')
            grad.addColorStop(0.5, '#ffffff')
            grad.addColorStop(1.0, '#00ff00')
            this.context.fillStyle = grad
            this.context.fillRect(0, 0, 440, 440)
          })
      }
      .width('100%')
      .height('100%')
    }
  }
  ```

  ![en-us_image_0000001257058405](figures/en-us_image_0000001257058405.png)

### createConicGradient<sup>10+</sup>

createConicGradient(startAngle: number, x: number, y: number): CanvasGradient

Creates a conic gradient.

**Parameters**

| Name        | Type    | Mandatory  | Default Value | Description                                 |
| ---------- | ------ | ---- | ---- | ----------------------------------- |
| startAngle | number | Yes   | 0    | Angle at which the gradient starts, in radians. The angle measurement starts horizontally from the right side of the center and moves clockwise.|
| x          | number | Yes   | 0    | X coordinate of the center of the conic gradient, in vp.|
| y          | number | Yes   | 0    | Y coordinate of the center of the conic gradient, in vp.|

**Return value**

| Type    | Description       |
| ------ | --------- |
| [CanvasGradient](ts-components-canvas-canvasgradient.md) | New **CanvasGradient** object used to create a gradient on the canvas.|

**Example**

```ts
// xxx.ets
@Entry
@Component
struct CanvasExample {
  private settings: RenderingContextSettings = new RenderingContextSettings(true)
  private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings)

  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
      Canvas(this.context)
        .width('100%')
        .height('100%')
        .backgroundColor('#ffffff')
        .onReady(() => {
          let grad = this.context.createConicGradient(0, 50, 80)
          grad.addColorStop(0.0, '#ff0000')
          grad.addColorStop(0.5, '#ffffff')
          grad.addColorStop(1.0, '#00ff00')
          this.context.fillStyle = grad
          this.context.fillRect(0, 30, 100, 100)
        })
    }
    .width('100%')
    .height('100%')
  }
}
```

  ![en-us_image_0000001239032419](figures/en-us_image_0000001239032420.png)


## CanvasDirection

This API can be used in ArkTS widgets since API version 9.

| Name     | Description                 |
| ------- | ------------------- |
| inherit | The text direction is inherited from the **\<Canvas>** component.|
| ltr     | The text direction is from left to right.              |
| rtl     | The text direction is from right to left.              |

## CanvasFillRule

This API can be used in ArkTS widgets since API version 9.

| Name     | Description   |
| ------- | ----- |
| evenodd | The inside part of a shape is determined based on whether the counting result is an odd number or not.|
| nonzero | The inside part of a shape is determined based on whether the counting result is zero or not.|

## CanvasLineCap

This API can be used in ArkTS widgets since API version 9.

| Name    | Description                           |
| ------ | ----------------------------- |
| butt   | The ends of the line are squared off, and the line does not extend beyond its two endpoints.              |
| round  | The line is extended at the endpoints by a half circle whose diameter is equal to the line width.           |
| square | The line is extended at the endpoints by a rectangle whose width is equal to half the line width and height equal to the line width.|

## CanvasLineJoin

This API can be used in ArkTS widgets since API version 9.

| Name   | Description                                      |
| ----- | ---------------------------------------- |
| bevel | The intersection is a triangle. The rectangular corner of each line is independent.            |
| miter | The intersection has a miter corner by extending the outside edges of the lines until they meet. You can view the effect of this attribute in **miterLimit**.|
| round | The intersection is a sector, whose radius at the rounded corner is equal to the line width.             |

## CanvasTextAlign

This API can be used in ArkTS widgets since API version 9.

| Name    | Description          |
| ------ | ------------ |
| center | The text is center-aligned.     |
| start  | The text is aligned with the start bound.|
| end    | The text is aligned with the end bound.|
| left   | The text is left-aligned.      |
| right  | The text is right-aligned.      |

## CanvasTextBaseline

This API can be used in ArkTS widgets since API version 9.

| Name         | Description                                      |
| ----------- | ---------------------------------------- |
| alphabetic  | The text baseline is the normal alphabetic baseline.                           |
| bottom      | The text baseline is at the bottom of the text bounding box. Its difference from the ideographic baseline is that the ideographic baseline does not consider letters in the next line.|
| hanging     | The text baseline is a hanging baseline over the text.                              |
| ideographic | The text baseline is the ideographic baseline. If a character exceeds the alphabetic baseline, the ideographic baseline is located at the bottom of the excessive character.|
| middle      | The text baseline is in the middle of the text bounding box.                            |
| top         | The text baseline is on the top of the text bounding box.                            |

## ImageSmoothingQuality

This API can be used in ArkTS widgets since API version 9.

| Name    | Description  |
| ------ | ---- |
| low    | Low quality. |
| medium | Medium quality. |
| high   | High quality. |

## TextMetrics

| Attribute                      | Type    | Description                                      |
| ------------------------ | ------ | ---------------------------------------- |
| width                    | number | Width of the text. Read-only.                                 |
| height                   | number | Height of the text. Read-only.                                 |
| actualBoundingBoxAscent  | number | Distance from the horizontal line specified by the [CanvasRenderingContext2D.textBaseline](#canvastextbaseline) attribute to the top of the bounding rectangle used to render the text. Read-only. The current value is **0**.|
| actualBoundingBoxDescent | number | Distance from the horizontal line specified by the [CanvasRenderingContext2D.textBaseline](#canvastextbaseline) attribute to the bottom of the bounding rectangle used to render the text. Read-only. The current value is **0**.|
| actualBoundingBoxLeft    | number | Distance parallel to the baseline from the alignment point determined by the [CanvasRenderingContext2D.textAlign](#canvastextalign) attribute to the left side of the bounding rectangle of the text. Read-only. The current value is **0**.|
| actualBoundingBoxRight   | number | Distance parallel to the baseline from the alignment point determined by the [CanvasRenderingContext2D.textAlign](#canvastextalign) attribute to the right side of the bounding rectangle of the text. Read-only. The current value is **0**.|
| alphabeticBaseline       | number | Distance from the horizontal line specified by the [CanvasRenderingContext2D.textBaseline](#canvastextbaseline) attribute to the alphabetic baseline of the line box. Read-only. The current value is **0**.|
| emHeightAscent           | number | Distance from the horizontal line specified by the [CanvasRenderingContext2D.textBaseline](#canvastextbaseline) attribute to the top of the em square in the line box. Read-only. The current value is **0**.|
| emHeightDescent          | number | Distance from the horizontal line specified by the [CanvasRenderingContext2D.textBaseline](#canvastextbaseline) attribute to the bottom of the em square in the line box. Read-only. The current value is **0**.|
| fontBoundingBoxAscent    | number | Distance from the horizontal line specified by the [CanvasRenderingContext2D.textBaseline](#canvastextbaseline) attribute to the top of the bounding rectangle of all the fonts used to render the text. Read-only. The current value is **0**.|
| fontBoundingBoxDescent   | number | Distance from the horizontal line specified by the [CanvasRenderingContext2D.textBaseline](#canvastextbaseline) attribute to the bottom of the bounding rectangle of all the fonts used to render the text. Read-only. The current value is **0**.|
| hangingBaseline          | number | Distance from the horizontal line specified by the [CanvasRenderingContext2D.textBaseline](#canvastextbaseline) attribute to the hanging baseline of the line box. Read-only. The current value is **0**.|
| ideographicBaseline      | number | Distance from the horizontal line specified by the [CanvasRenderingContext2D.textBaseline](#canvastextbaseline) attribute to the ideographic baseline of the line box. Read-only. The current value is **0**.|
