# CanvasRenderingContext2D


> **NOTE**<br>
> This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.


The **\<RenderingContext>** component is used to draw rectangles, text, images, and other objects on a canvas.


## APIs

CanvasRenderingContext2D(setting: RenderingContextSetting)

- Parameters
    | Name    | Type                                     | Mandatory | Default Value | Description                   |
    | ------- | ---------------------------------------- | --------- | ------------- | ----------------------------- |
    | setting | [RenderingContextSettings](#renderingcontextsettings) | Yes       | -             | See [RenderingContextSettings](#renderingcontextsettings). |


### RenderingContextSettings

RenderingContextSettings(antialias?: bool)

Configures the settings of a **CanvasRenderingContext2D** object, including whether to enable antialiasing.

- Parameters
    | Name      | Type | Mandatory | Default Value | Description                      |
    | --------- | ---- | --------- | ------------- | -------------------------------- |
    | antialias | bool | No        | false         | Whether antialiasing is enabled. |


## Attributes

| Name                                     | Type                                     | Default Value                   | Description                              |
| ---------------------------------------- | ---------------------------------------- | ------------------------------- | ---------------------------------------- |
| [fillStyle](#fillstyle)                  | &lt;color&gt; \| [CanvasGradient](ts-components-canvas-canvasgradient.md) \| [CanvasPattern](#canvaspattern) | -                               | Style used to fill an area.<br>- When the type is **&lt;color&gt;**, this attribute indicates the fill color.<br>- When the type is **CanvasGradient**, this attribute indicates a gradient object, which is created using the [createLinearGradient](#createlineargradient) method.<br>- When the type is **CanvasPattern**, this attribute indicates a pattern, which is created using the [createPattern](#createpattern) method. |
| [lineWidth](#linewidth)                  | number                                   | -                               | Line width.                              |
| [strokeStyle](#strokestyle)              | &lt;color&gt; \| [CanvasGradient](ts-components-canvas-canvasgradient.md) \| [CanvasPattern](#canvaspattern) | -                               | Stroke style.<br>- When the type is **&lt;color&gt;**, this attribute indicates the stroke color.<br>- When the type is **CanvasGradient**, this attribute indicates a gradient object, which is created using the [createLinearGradient](#createlineargradient) method.<br>- When the type is **CanvasPattern**, this attribute indicates a pattern, which is created using the [createPattern](#createpattern) method. |
| [lineCap](#linecap)                      | string                                   | 'butt'                          | Style of the line endpoints. The options are as follows:<br>- **'butt'**: The endpoints of the line are squared off.<br>- **'round'**: The endpoints of the line are rounded.<br>- **'square'**: The endpoints of the line are squared off by adding a box with an equal width and half the height of the line's thickness. |
| [lineJoin](#linejoin)                    | string                                   | 'miter'                         | Style of the shape used to join line segments. The options are as follows:<br>- **'round'**: The shape used to join line segments is a rounded corner with the radius equal to the line width.<br>- **'bevel'**: The shape used to join line segments is a beveled corner. The rectangular corner of each line is independent.<br>- **'miter'**: The shape used to join line segments is a mitered corner. The corner is formed by extending the outside edges of the lines until they meet. You can adjust the effect of this attribute using **miterLimit**. |
| [miterLimit](#miterlimit)                | number                                   | 10                              | Maximum miter length. The miter length is the distance between the inner corner and the outer corner where two lines meet. |
| [font](#font)                            | string                                   | 'normal normal 14px sans-serif' | Font style.<br>Syntax: ctx.font='font-size font-family'<br>- (Optional) **font-size**: font size and row height. The unit can only be px.<br>- (Optional) **font-family**: font family.<br>Syntax: ctx.font='font-style font-weight font-size font-family'<br>- (Optional) **font-style**: font style. Available values are **'normal'** and **'italic'**.<br>- (Optional) **font-weight**: font weight. Available values are as follows: **'normal'**, **'bold'**, **'bolder'**, **'lighter'**, **100**, **200**, **300**, **400**, **500**, **600**, **700**, **800**, **900**<br>- (Optional) **font-size**: font size and row height. The unit can only be px.<br>- (Optional) **font-family**: font family. Available values are **'sans-serif'**, **'serif'**, and **'monospace'**. |
| [textAlign](#textalign)                  | string                                   | 'left'                          | Text alignment mode. Available values are as follows:<br>- **'left'**: The text is left-aligned.<br>- **'right'**: The text is right-aligned.<br>- **'center'**: The text is center-aligned.<br>- **'start'**: The text is aligned with the start bound.<br>- **'end'**: The text is aligned with the end bound.<br>**NOTE**<br>In the **ltr** layout mode, the value **'start'** equals **'left'**. In the **rtl** layout mode, the value **'start'** equals **'right'**. |
| [textBaseline](#textbaseline)            | string                                   | 'alphabetic'                    | Horizontal alignment mode of text. Available values are as follows:<br>- **'alphabetic'**: The text baseline is the normal alphabetic baseline.<br>- **'top'**: The text baseline is on the top of the text bounding box.<br>- **'hanging'**: The text baseline is a hanging baseline over the text.<br>- **'middle'**: The text baseline is in the middle of the text bounding box.<br>- **'ideographic'**: The text baseline is the ideographic baseline. If a character exceeds the alphabetic baseline, the ideographic baseline is located at the bottom of the excess character.<br>- **'bottom'**: The text baseline is at the bottom of the text bounding box. Its difference from the ideographic baseline is that the ideographic baseline does not consider letters in the next line. |
| [globalAlpha](#globalalpha)              | number                                   | -                               | Opacity. **0.0**: completely transparent; **1.0**: completely opaque. |
| [lineDashOffset](#linedashoffset)        | number                                   | 0.0                             | Offset of the dashed line. The precision is float. |
| [globalCompositeOperation](#globalcompositeoperation) | string                                   | 'source-over'                   | Composition operation type. Available values are as follows: **'source-over'**, **'source-atop'**, **'source-in'**, **'source-out'**, **'destination-over'**, **'destination-atop'**, **'destination-in'**, **'destination-out'**, **'lighter'**, **'copy'**, and **'xor'**. |
| [shadowBlur](#shadowblur)                | number                                   | 0.0                             | Blur level during shadow drawing. A larger value indicates a more blurred effect. The precision is float. |
| [shadowColor](#shadowcolor)              | &lt;color&gt;                            | -                               | Shadow color.                            |
| [shadowOffsetX](#shadowoffsetx)          | number                                   | -                               | X-axis shadow offset relative to the original object. |
| [shadowOffsetY](#shadowoffsety)          | number                                   | -                               | Y-axis shadow offset relative to the original object. |
| [imageSmoothingEnabled](#imagesmoothingenabled) | boolean                                  | true                            | Whether to adjust the image smoothness during image drawing. The value **true** means to enable this feature, and **false** means the opposite. |
| imageSmoothingQuality                    | string                                   | 'low'                           | Image smoothness. The value can be **'low'**, **'medium'**, or **'high'**. |

> **NOTE**<br>
> The value of the **&lt;color&gt;** type can be in 'rgb(255, 255, 255)', 'rgba(255, 255, 255, 1.0)', or '\#FFFFFF' format.


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
          this.context.fillRect(20, 160, 150, 100)
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
struct Font {
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
          this.context.fillText("Hello World", 20, 60)
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
        this.context.fillStyle = 'rgb(255,0,0)'
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

![en-us_image_0000001212218444](figures/en-us_image_0000001212218444.png)


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
          this.context.stroke();
      })
    }
    .width('100%')
    .height('100%')
  }
}
```

![en-us_image_0000001212058480](figures/en-us_image_0000001212058480.png)


### globalCompositeOperation

| Name             | Description                              |
| ---------------- | ---------------------------------------- |
| source-over      | Displays the new drawing above the existing drawing. This attribute is used by default. |
| source-atop      | Displays the new drawing on the top of the existing drawing. |
| source-in        | Displays the new drawing inside the existing drawing. |
| source-out       | Displays the part of the new drawing that is outside of the existing drawing. |
| destination-over | Displays the existing drawing above the new drawing. |
| destination-atop | Displays the existing drawing on the top of the new drawing. |
| destination-in   | Displays the existing drawing inside the new drawing. |
| destination-out  | Displays the part of the existing drawing that is outside of the new drawing. |
| lighter          | Displays both the new drawing and the existing drawing. |
| copy             | Displays the new drawing and neglects the existing drawing. |
| xor              | Combines the new drawing and existing drawing using the XOR operation. |

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
  private settings: RenderingContextSettings = new RenderingContextSettings(true);
  private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings);
  
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


## Methods


### fillRect

fillRect(x: number, y: number, w: number, h: number): void

Fills a rectangle on the canvas.

- Parameters
    | Name   | Type   | Mandatory | Default Value | Description                              |
    | ------ | ------ | --------- | ------------- | ---------------------------------------- |
    | x      | number | Yes       | 0             | X-coordinate of the upper left corner of the rectangle. |
    | y      | number | Yes       | 0             | Y-coordinate of the upper left corner of the rectangle. |
    | width  | number | Yes       | 0             | Width of the rectangle.                  |
    | height | number | Yes       | 0             | Height of the rectangle.                 |

- Example

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
            this.context.fillRect(0,30,100,100)
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

- Parameters
    | Name   | Type   | Mandatory | Default Value | Description                              |
    | ------ | ------ | --------- | ------------- | ---------------------------------------- |
    | x      | number | Yes       | 0             | X-coordinate of the upper left corner of the rectangle. |
    | y      | number | Yes       | 0             | Y-coordinate of the upper left corner of the rectangle. |
    | width  | number | Yes       | 0             | Width of the rectangle.                  |
    | height | number | Yes       | 0             | Height of the rectangle.                 |

- Example

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

- Parameters
    | Name   | Type   | Mandatory | Default Value | Description                              |
    | ------ | ------ | --------- | ------------- | ---------------------------------------- |
    | x      | number | Yes       | 0             | X-coordinate of the upper left corner of the rectangle. |
    | y      | number | Yes       | 0             | Y-coordinate of the upper left corner of the rectangle. |
    | width  | number | Yes       | 0             | Width of the rectangle.                  |
    | height | number | Yes       | 0             | Height of the rectangle.                 |

- Example

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
            this.context.fillRect(0,0,500,500)
            this.context.clearRect(20,20,150,100)
        })
      }
      .width('100%')
      .height('100%')
    }
  }
  ```

  ![en-us_image_0000001211898482](figures/en-us_image_0000001211898482.png)


### fillText

fillText(text: string, x: number, y: number): void

Draws filled text on the canvas.

- Parameters
    | Name | Type   | Mandatory | Default Value | Description                              |
    | ---- | ------ | --------- | ------------- | ---------------------------------------- |
    | text | string | Yes       | ""            | Text to draw.                            |
    | x    | number | Yes       | 0             | X-coordinate of the lower left corner of the text. |
    | y    | number | Yes       | 0             | Y-coordinate of the lower left corner of the text. |

- Example

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

strokeText(text: string, x: number, y: number): void

Draws a text stroke on the canvas.

- Parameters
    | Name | Type   | Mandatory | Default Value | Description                              |
    | ---- | ------ | --------- | ------------- | ---------------------------------------- |
    | text | string | Yes       | ""            | Text to draw.                            |
    | x    | number | Yes       | 0             | X-coordinate of the lower left corner of the text. |
    | y    | number | Yes       | 0             | Y-coordinate of the lower left corner of the text. |

- Example

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

Returns a **TextMetrics** object used to obtain the width of specified text.

- Parameters
    | Name | Type   | Mandatory | Default Value | Description          |
    | ---- | ------ | --------- | ------------- | -------------------- |
    | text | string | Yes       | ""            | Text to be measured. |

- Return value
    | Type        | Description             |
    | ----------- | ----------------------- |
    | TextMetrics | **TextMetrics** object. |

- **TextMetrics** attributes
    | Name  | Type   | Description        |
    | ----- | ------ | ------------------ |
    | width | number | Width of the text. |

- Example

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

- Parameters
    | Name | Type                                     | Mandatory | Default Value | Description                |
    | ---- | ---------------------------------------- | --------- | ------------- | -------------------------- |
    | path | [Path2D](ts-components-canvas-path2d.md) | No        | null          | A **Path2D** path to draw. |

- Example

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

- Example

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

- Parameters
    | Name | Type   | Mandatory | Default Value | Description                          |
    | ---- | ------ | --------- | ------------- | ------------------------------------ |
    | x    | number | Yes       | 0             | X-coordinate of the target position. |
    | y    | number | Yes       | 0             | Y-coordinate of the target position. |

- Example

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

- Parameters
    | Name | Type   | Mandatory | Default Value | Description                          |
    | ---- | ------ | --------- | ------------- | ------------------------------------ |
    | x    | number | Yes       | 0             | X-coordinate of the target position. |
    | y    | number | Yes       | 0             | Y-coordinate of the target position. |

- Example

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

- Example

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

createPattern(image: ImageBitmap, repetition: string): void

Creates a pattern for image filling based on a specified source image and repetition mode.

- Parameters
    | Name       | Type                                     | Mandatory | Default Value | Description                              |
    | ---------- | ---------------------------------------- | --------- | ------------- | ---------------------------------------- |
    | image      | [ImageBitmap](ts-components-canvas-imagebitmap.md) | Yes       | null          | Source image. For details, see ImageBitmap. |
    | repetition | string                                   | Yes       | ""            | Repetition mode. The value can be **'repeat'**, **'repeat-x'**, **'repeat-y'**, or **'no-repeat'**. |

- Example

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
            var pattern = this.context.createPattern(this.img, 'repeat')
            this.context.fillStyle = pattern
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

Draws a cubic bezier curve on the canvas.

- Parameters
    | Name | Type   | Mandatory | Default Value | Description                              |
    | ---- | ------ | --------- | ------------- | ---------------------------------------- |
    | cp1x | number | Yes       | 0             | X-coordinate of the first parameter of the bezier curve. |
    | cp1y | number | Yes       | 0             | Y-coordinate of the first parameter of the bezier curve. |
    | cp2x | number | Yes       | 0             | X-coordinate of the second parameter of the bezier curve. |
    | cp2y | number | Yes       | 0             | Y-coordinate of the second parameter of the bezier curve. |
    | x    | number | Yes       | 0             | X-coordinate of the end point on the bezier curve. |
    | y    | number | Yes       | 0             | Y-coordinate of the end point on the bezier curve. |

- Example

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

- Parameters
    | Name | Type   | Mandatory | Default Value | Description                              |
    | ---- | ------ | --------- | ------------- | ---------------------------------------- |
    | cpx  | number | Yes       | 0             | X-coordinate of the bezier curve parameter. |
    | cpy  | number | Yes       | 0             | Y-coordinate of the bezier curve parameter. |
    | x    | number | Yes       | 0             | X-coordinate of the end point on the bezier curve. |
    | y    | number | Yes       | 0             | Y-coordinate of the end point on the bezier curve. |

- Example

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct QuadraticCurveTo {
    private settings: RenderingContextSettings = new RenderingContextSettings(true);
    private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings);
    build() {
      Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
        Canvas(this.context)
          .width('100%')
          .height('100%')
          .backgroundColor('#ffff00')
          .onReady(() =>{
            this.context.beginPath();
            this.context.moveTo(20, 20);
            this.context.quadraticCurveTo(100, 100, 200, 20);
            this.context.stroke();
        })
      }
      .width('100%')
      .height('100%')
    }
  }
  ```

  ![en-us_image_0000001257058397](figures/en-us_image_0000001257058397.png)


### arc

arc(x: number, y: number, radius: number, startAngle: number, endAngle: number, anticlockwise?: boolean): void

Draws an arc on the canvas.

- Parameters
    | Name          | Type    | Mandatory | Default Value | Description                              |
    | ------------- | ------- | --------- | ------------- | ---------------------------------------- |
    | x             | number  | Yes       | 0             | X-coordinate of the center point of the arc. |
    | y             | number  | Yes       | 0             | Y-coordinate of the center point of the arc. |
    | radius        | number  | Yes       | 0             | Radius of the arc.                       |
    | startAngle    | number  | Yes       | 0             | Start radian of the arc.                 |
    | endAngle      | number  | Yes       | 0             | End radian of the arc.                   |
    | anticlockwise | boolean | No        | false         | Whether to draw the arc counterclockwise. |

- Example

  ```
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

- Parameters
    | Name   | Type   | Mandatory | Default Value | Description                              |
    | ------ | ------ | --------- | ------------- | ---------------------------------------- |
    | x1     | number | Yes       | 0             | X-coordinate of the first point on the arc. |
    | y1     | number | Yes       | 0             | Y-coordinate of the first point on the arc. |
    | x2     | number | Yes       | 0             | X-coordinate of the second point on the arc. |
    | y2     | number | Yes       | 0             | Y-coordinate of the second point on the arc. |
    | radius | number | Yes       | 0             | Radius of the arc.                       |

- Example

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
            this.context.moveTo(100, 20);
            this.context.arcTo(150, 20, 150, 70, 50);
            this.context.stroke();
          })
      }
      .width('100%')
      .height('100%')
    }
  }
  ```

  ![en-us_image_0000001257058413](figures/en-us_image_0000001257058413.png)


### ellipse

ellipse(x: number, y: number, radiusX: number, radiusY: number, rotation: number, startAngle: number, endAngle: number, anticlockwise?: boolean): void

Draws an ellipse in the specified rectangular region.

- Parameters
    | Name          | Type    | Mandatory | Default Value | Description                              |
    | ------------- | ------- | --------- | ------------- | ---------------------------------------- |
    | x             | number  | Yes       | 0             | X-coordinate of the ellipse center.      |
    | y             | number  | Yes       | 0             | Y-coordinate of the ellipse center.      |
    | radiusX       | number  | Yes       | 0             | Ellipse radius on the x-axis.            |
    | radiusY       | number  | Yes       | 0             | Ellipse radius on the y-axis.            |
    | rotation      | number  | Yes       | 0             | Rotation angle of the ellipse, in radians. |
    | startAngle    | number  | Yes       | 0             | Angle of the start point for drawing the ellipse, in radians. |
    | endAngle      | number  | Yes       | 0             | Angle of the end point for drawing the ellipse, in radians. |
    | anticlockwise | boolean | No        | false         | Whether to draw the ellipse in the counterclockwise direction. |

- Example


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
            this.context.ellipse(200, 200, 50, 100, Math.PI * 0.25, Math.PI * 0.5, Math.PI)
            this.context.stroke()
          })
      }
      .width('100%')
      .height('100%')
    }
  }
  ```

  ![en-us_image_0000001256978339](figures/en-us_image_0000001256978339.png)


### rect

rect(x: number, y: number, width: number, height: number): void

Creates a rectangle.

- Parameters
    | Name   | Type   | Mandatory | Default Value | Description                              |
    | ------ | ------ | --------- | ------------- | ---------------------------------------- |
    | x      | number | Yes       | 0             | X-coordinate of the upper left corner of the rectangle. |
    | y      | number | Yes       | 0             | Y-coordinate of the upper left corner of the rectangle. |
    | width  | number | Yes       | 0             | Width of the rectangle.                  |
    | height | number | Yes       | 0             | Height of the rectangle.                 |

- Example

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

fill(): void

Fills the area inside a closed path.

- Example

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


### clip

clip(): void

Sets the current path to a clipping path.

- Example

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
            this.context.rect(0, 0, 200, 200)
            this.context.stroke()
            this.context.clip()
            this.context.fillStyle = "rgb(255,0,0)"
            this.context.fillRect(0, 0, 150, 150)
          })
      }
      .width('100%')
      .height('100%')
    }
  }
  ```

  ![en-us_image_0000001211898488](figures/en-us_image_0000001211898488.png)


### rotate

rotate(rotate: number): void

Rotates a canvas clockwise around its coordinate axes.

- Parameters
    | Name   | Type   | Mandatory | Default Value | Description                              |
    | ------ | ------ | --------- | ------------- | ---------------------------------------- |
    | rotate | number | Yes       | 0             | Clockwise rotation angle. You can use **Math.PI / 180** to convert the angle to a radian. |

- Example

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
            this.context.rotate(45 * Math.PI / 180) // Rotate the rectangle 45 degrees
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

Scales a canvas based on scale factors.

- Parameters
    | Name | Type   | Mandatory | Default Value | Description              |
    | ---- | ------ | --------- | ------------- | ------------------------ |
    | x    | number | Yes       | 0             | Horizontal scale factor. |
    | y    | number | Yes       | 0             | Vertical scale factor.   |

- Example

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
            this.context.strokeRect(10, 10, 25, 25)
            this.context.scale(2, 2) // Scale to 200%
            this.context.strokeRect(10, 10, 25, 25)
          })
      }
      .width('100%')
      .height('100%')
    }
  }
  ```

  ![en-us_image_0000001257138347](figures/en-us_image_0000001257138347.png)


### transform

transform(scaleX: number, skewX: number, skewY: number, scaleY: number, translateX: number, translateY: number): void

Defines a transformation matrix. To transform a graph, you only need to set parameters of the matrix. The coordinates of the graph are multiplied by the matrix values to obtain new coordinates of the transformed graph. You can use the matrix to implement multiple transform effects.

> **NOTE**<br>
> The following formulas calculate coordinates of the transformed graph. **x** and **y** represent coordinates before transformation, and **x'** and **y'** represent coordinates after transformation.
>
> - x' = scaleX \* x + skewY \* y + translateX
>
> - y' = skewX \* x + scaleY \* y + translateY

- Parameters
    | Name       | Type   | Mandatory | Default Value | Description         |
    | ---------- | ------ | --------- | ------------- | ------------------- |
    | scaleX     | number | Yes       | 0             | X-axis scale.       |
    | skewX      | number | Yes       | 0             | X-axis skew.        |
    | skewY      | number | Yes       | 0             | Y-axis skew.        |
    | scaleY     | number | Yes       | 0             | Y-axis scale.       |
    | translateX | number | Yes       | 0             | X-axis translation. |
    | translateY | number | Yes       | 0             | Y-axis translation. |

- Example

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

setTransform(scaleX: number, skewX: number, skewY: number, scale: number, translateX: number, translateY: number): void

Resets the existing transformation matrix and creates a new transformation matrix by using the same parameters as the **transform()** function.

- Parameters
    | Name       | Type   | Mandatory | Default Value | Description         |
    | ---------- | ------ | --------- | ------------- | ------------------- |
    | scaleX     | number | Yes       | 0             | X-axis scale.       |
    | skewX      | number | Yes       | 0             | X-axis skew.        |
    | skewY      | number | Yes       | 0             | Y-axis skew.        |
    | scaleY     | number | Yes       | 0             | Y-axis scale.       |
    | translateX | number | Yes       | 0             | X-axis translation. |
    | translateY | number | Yes       | 0             | Y-axis translation. |

- Example

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


### translate

translate(x: number, y: number): void

Moves the origin of the coordinate system.

- Parameters
    | Name | Type   | Mandatory | Default Value | Description         |
    | ---- | ------ | --------- | ------------- | ------------------- |
    | x    | number | Yes       | 0             | X-axis translation. |
    | y    | number | Yes       | 0             | Y-axis translation. |

- Example

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

drawImage(image: ImageBitmap | PixelMap, dx: number, dy: number, dWidth: number, dHeight: number): void

drawImage(image: ImageBitmap | PixelMap, sx: number, sy: number, sWidth: number, sHeight: number, dx: number, dy: number, dWidth: number, dHeight: number):void

Draws an image.

- Parameters
    | Name    | Type                                     | Mandatory | Default Value | Description                              |
    | ------- | ---------------------------------------- | --------- | ------------- | ---------------------------------------- |
    | image   | [ImageBitmap](ts-components-canvas-imagebitmap.md) or [PixelMap](../apis/js-apis-image.md#pixelmap7) | Yes       | null          | Image resource. For details, see ImageBitmap or PixelMap. |
    | sx      | number                                   | No        | 0             | X-coordinate of the upper left corner of the rectangle used to crop the source image. |
    | sy      | number                                   | No        | 0             | Y-coordinate of the upper left corner of the rectangle used to crop the source image. |
    | sWidth  | number                                   | No        | 0             | Target width to crop the source image.   |
    | sHeight | number                                   | No        | 0             | Target height to crop the source image.  |
    | dx      | number                                   | Yes       | 0             | X-coordinate of the upper left corner of the drawing area on the canvas. |
    | dy      | number                                   | Yes       | 0             | Y-coordinate of the upper left corner of the drawing area on the canvas. |
    | dWidth  | number                                   | No        | 0             | Width of the drawing area.               |
    | dHeight | number                                   | No        | 0             | Height of the drawing area.              |


- Example

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct ImageExample {
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
            this.context.drawImage( this.img,0,0,500,500,0,0,400,200);
        })
      }
      .width('100%')
      .height('100%')
    }
  }
  ```

  ![en-us_image_0000001212058466](figures/en-us_image_0000001212058466.png)


### createImageData

createImageData(width: number, height: number): Object

Creates an **ImageData** object. For details, see [ImageData](ts-components-canvas-imagebitmap.md).

- Parameters
    | Name   | Type   | Mandatory | Default Value | Description                         |
    | ------ | ------ | --------- | ------------- | ----------------------------------- |
    | width  | number | Yes       | 0             | Width of the **ImageData** object.  |
    | height | number | Yes       | 0             | Height of the **ImageData** object. |


### createImageData

createImageData(imageData: Object): Object

Creates an **ImageData** object. For details, see [ImageData](ts-components-canvas-imagebitmap.md).

- Parameters
    | Name      | Type   | Mandatory | Default Value | Description                              |
    | --------- | ------ | --------- | ------------- | ---------------------------------------- |
    | imagedata | Object | Yes       | null          | **ImageData** object with the same width and height copied from the original **ImageData** object. |

### getPixelMap

getPixelMap(sx: number, sy: number, sw: number, sh: number): PixelMap

Obtains the **[PixelMap](../apis/js-apis-image.md#pixelmap7)** object created with the pixels within the specified area on the canvas.
- Parameters
  | Name  | Type    | Mandatory  | Default Value | Description             |
  | ---- | ------ | ---- | ---- | --------------- |
  | sx   | number | Yes   | 0    | X-coordinate of the upper left corner of the output area.|
  | sy   | number | Yes   | 0    | Y-coordinate of the upper left corner of the output area.|
  | sw   | number | Yes   | 0    | Width of the output area.    |
  | sh   | number | Yes   | 0    | Height of the output area.    |

### getImageData

getImageData(sx: number, sy: number, sw: number, sh: number): Object

Creates an **[ImageData](ts-components-canvas-imagebitmap.md)** object with pixels in the specified area on the canvas.
- Parameters
    | Name | Type   | Mandatory | Default Value | Description                              |
    | ---- | ------ | --------- | ------------- | ---------------------------------------- |
    | sx   | number | Yes       | 0             | X-coordinate of the upper left corner of the output area. |
    | sy   | number | Yes       | 0             | Y-coordinate of the upper left corner of the output area. |
    | sw   | number | Yes       | 0             | Width of the output area.                |
    | sh   | number | Yes       | 0             | Height of the output area.               |


### putImageData

putImageData(imageData: Object, dx: number, dy: number, dirtyX?: number, dirtyY?: number, dirtyWidth?: number, dirtyHeight?: number): void

Puts the **[ImageData](ts-components-canvas-imagebitmap.md)** onto a rectangular area on the canvas.

- Parameters
    | Name        | Type   | Mandatory | Default Value                      | Description                              |
    | ----------- | ------ | --------- | ---------------------------------- | ---------------------------------------- |
    | imagedata   | Object | Yes       | null                               | **ImageData** object with pixels to put onto the canvas. |
    | dx          | number | Yes       | 0                                  | X-axis offset of the rectangular area on the canvas. |
    | dy          | number | Yes       | 0                                  | Y-axis offset of the rectangular area on the canvas. |
    | dirtyX      | number | No        | 0                                  | X-axis offset of the upper left corner of the rectangular area relative to that of the source image. |
    | dirtyY      | number | No        | 0                                  | Y-axis offset of the upper left corner of the rectangular area relative to that of the source image. |
    | dirtyWidth  | number | No        | Width of the **ImageData** object  | Width of the rectangular area to crop the source image. |
    | dirtyHeight | number | No        | Height of the **ImageData** object | Height of the rectangular area to crop the source image. |

- Example

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
            var imageData = this.context.createImageData(100, 100)
            for (var i = 0; i < imageData.data.length; i += 4) {
              imageData.data[i + 0] = 255
              imageData.data[i + 1] = 0
              imageData.data[i + 2] = 255
              imageData.data[i + 3] = 255
            }
            this.context.putImageData(imageData, 10, 10)
          })
      }
      .width('100%')
      .height('100%')
    }
  }
  ```

  ![en-us_image_0000001212378396](figures/en-us_image_0000001212378396.png)


### restore

restore(): void

Restores the saved drawing context.

- Example

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
            this.context.restore()
          })
      }
      .width('100%')
      .height('100%')
    }
  }
  ```


### save

save(): void

Saves the current drawing context.

- Example

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
            this.context.save()
        })
      }
      .width('100%')
      .height('100%')
    }
  }
  ```


### createLinearGradient

createLinearGradient(x0: number, y0: number, x1: number, y1: number): void

Creates a linear gradient.

- Parameters
    | Name | Type   | Mandatory | Default Value | Description                      |
    | ---- | ------ | --------- | ------------- | -------------------------------- |
    | x0   | number | Yes       | 0             | X-coordinate of the start point. |
    | y0   | number | Yes       | 0             | Y-coordinate of the start point. |
    | x1   | number | Yes       | 0             | X-coordinate of the end point.   |
    | y1   | number | Yes       | 0             | Y-coordinate of the end point.   |

- Example

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
            var grad = this.context.createLinearGradient(50,0, 300,100)
            grad.addColorStop(0.0, 'red')
            grad.addColorStop(0.5, 'white')
            grad.addColorStop(1.0, 'green')
            this.context.fillStyle = grad
            this.context.fillRect(0, 0, 500, 500)
          })
      }
      .width('100%')
      .height('100%')
    }
  }
  ```

  ![en-us_image_0000001212378412](figures/en-us_image_0000001212378412.png)


### createRadialGradient

createRadialGradient(x0: number, y0: number, r0: number, x1: number, y1: number, r1: number): void

Creates a linear gradient.

- Parameters
    | Name | Type   | Mandatory | Default Value | Description                              |
    | ---- | ------ | --------- | ------------- | ---------------------------------------- |
    | x0   | number | Yes       | 0             | X-coordinate of the center of the start circle. |
    | y0   | number | Yes       | 0             | Y-coordinate of the center of the start circle. |
    | r0   | number | Yes       | 0             | Radius of the start circle, which must be a non-negative finite number. |
    | x1   | number | Yes       | 0             | X-coordinate of the center of the end circle. |
    | y1   | number | Yes       | 0             | Y-coordinate of the center of the end circle. |
    | r1   | number | Yes       | 0             | Radius of the end circle, which must be a non-negative finite number. |

- Example

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
            var grad = this.context.createRadialGradient(200,200,50, 200,200,200)
            grad.addColorStop(0.0, 'red')
            grad.addColorStop(0.5, 'white')
            grad.addColorStop(1.0, 'green')
            this.context.fillStyle = grad
            this.context.fillRect(0, 0, 500, 500)
          })
      }
      .width('100%')
      .height('100%')
    }
  }
  ```

  ![en-us_image_0000001257058405](figures/en-us_image_0000001257058405.png)


## CanvasPattern

Defines an object created by using the [createPattern](#createpattern) method.
