# CanvasRenderingContext2D


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE：**
> This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.


Use **RenderingContext** to draw rectangles, text, images, and other objects on a canvas.


## APIs

CanvasRenderingContext2D(setting: RenderingContextSetting)

- Parameters
    | Name | Type | Mandatory | Default&nbsp;Value | Description | 
  | -------- | -------- | -------- | -------- | -------- |
  | setting | [RenderingContextSettings](#renderingcontextsettings) | Yes | - | See&nbsp;RenderingContextSettings. | 


### RenderingContextSettings

RenderingContextSettings(antialias?: bool)

Configures the settings of a **CanvasRenderingContext2D** object, including whether to enable antialiasing.

- Parameters
    | Name | Type | Mandatory | Default&nbsp;Value | Description | 
  | -------- | -------- | -------- | -------- | -------- |
  | antialias | bool | No | false | Whether&nbsp;antialiasing&nbsp;is&nbsp;enabled. | 


## Attributes

| Name | Type | Default&nbsp;Value | Description |
| -------- | -------- | -------- | -------- |
| [fillStyle](#fillstyle) | &lt;color&gt;&nbsp;\|&nbsp;[CanvasGradient](ts-components-canvas-canvasgradient.md)&nbsp;\|&nbsp;[CanvasPattern](#canvaspattern) | - | Style&nbsp;used&nbsp;to&nbsp;fill&nbsp;an&nbsp;area.<br/>-&nbsp;When&nbsp;the&nbsp;type&nbsp;is&nbsp;**&lt;color&gt;**,&nbsp;this&nbsp;attribute&nbsp;indicates&nbsp;the&nbsp;fill&nbsp;color.<br/>-&nbsp;When&nbsp;the&nbsp;type&nbsp;is&nbsp;**CanvasGradient**,&nbsp;this&nbsp;attribute&nbsp;indicates&nbsp;a&nbsp;gradient&nbsp;object,&nbsp;which&nbsp;is&nbsp;created&nbsp;using&nbsp;the&nbsp;[createLinearGradient](#createlineargradient)&nbsp;method.<br/>-&nbsp;When&nbsp;the&nbsp;type&nbsp;is&nbsp;**CanvasPattern**,&nbsp;this&nbsp;attribute&nbsp;indicates&nbsp;a&nbsp;pattern,&nbsp;which&nbsp;is&nbsp;created&nbsp;using&nbsp;the&nbsp;[createPattern](#createpattern)&nbsp;method. |
| [lineWidth](#linewidth) | number | - | Line&nbsp;width. |
| [strokeStyle](#strokestyle) | &lt;color&gt;&nbsp;\|&nbsp;[CanvasGradient](ts-components-canvas-canvasgradient.md)&nbsp;\|&nbsp;[CanvasPattern](#canvaspattern) | - | Stroke&nbsp;style.<br/>-&nbsp;When&nbsp;the&nbsp;type&nbsp;is&nbsp;**&lt;color&gt;**,&nbsp;this&nbsp;attribute&nbsp;indicates&nbsp;the&nbsp;stroke&nbsp;color.<br/>-&nbsp;When&nbsp;the&nbsp;type&nbsp;is&nbsp;**CanvasGradient**,&nbsp;this&nbsp;attribute&nbsp;indicates&nbsp;a&nbsp;gradient&nbsp;object,&nbsp;which&nbsp;is&nbsp;created&nbsp;using&nbsp;the&nbsp;[createLinearGradient](#createlineargradient)&nbsp;method.<br/>-&nbsp;When&nbsp;the&nbsp;type&nbsp;is&nbsp;**CanvasPattern**,&nbsp;this&nbsp;attribute&nbsp;indicates&nbsp;a&nbsp;pattern,&nbsp;which&nbsp;is&nbsp;created&nbsp;using&nbsp;the&nbsp;[createPattern](#createpattern)&nbsp;method. |
| [lineCap](#linecap) | string | 'butt' | Style&nbsp;of&nbsp;the&nbsp;line&nbsp;endpoints.&nbsp;The&nbsp;options&nbsp;are&nbsp;as&nbsp;follows:<br/>-&nbsp;**'butt'**:&nbsp;The&nbsp;endpoints&nbsp;of&nbsp;the&nbsp;line&nbsp;are&nbsp;squared&nbsp;off.<br/>-&nbsp;**'round'**:&nbsp;The&nbsp;endpoints&nbsp;of&nbsp;the&nbsp;line&nbsp;are&nbsp;rounded.<br/>-&nbsp;**'square'**:&nbsp;The&nbsp;endpoints&nbsp;of&nbsp;the&nbsp;line&nbsp;are&nbsp;squared&nbsp;off&nbsp;by&nbsp;adding&nbsp;a&nbsp;box&nbsp;with&nbsp;an&nbsp;equal&nbsp;width&nbsp;and&nbsp;half&nbsp;the&nbsp;height&nbsp;of&nbsp;the&nbsp;line's&nbsp;thickness. |
| [lineJoin](#linejoin) | string | 'miter' | Style&nbsp;of&nbsp;the&nbsp;shape&nbsp;used&nbsp;to&nbsp;join&nbsp;line&nbsp;segments.&nbsp;The&nbsp;options&nbsp;are&nbsp;as&nbsp;follows:<br/>-&nbsp;**'round'**:&nbsp;The&nbsp;shape&nbsp;used&nbsp;to&nbsp;join&nbsp;line&nbsp;segments&nbsp;is&nbsp;a&nbsp;rounded&nbsp;corner&nbsp;with&nbsp;the&nbsp;radius&nbsp;equal&nbsp;to&nbsp;the&nbsp;line&nbsp;width.<br/>-&nbsp;**'bevel'**:&nbsp;The&nbsp;shape&nbsp;used&nbsp;to&nbsp;join&nbsp;line&nbsp;segments&nbsp;is&nbsp;a&nbsp;beveled&nbsp;corner.&nbsp;The&nbsp;rectangular&nbsp;corner&nbsp;of&nbsp;each&nbsp;line&nbsp;is&nbsp;independent.<br/>-&nbsp;**'miter'**:&nbsp;The&nbsp;shape&nbsp;used&nbsp;to&nbsp;join&nbsp;line&nbsp;segments&nbsp;is&nbsp;a&nbsp;mitered&nbsp;corner.&nbsp;The&nbsp;corner&nbsp;is&nbsp;formed&nbsp;by&nbsp;extending&nbsp;the&nbsp;outside&nbsp;edges&nbsp;of&nbsp;the&nbsp;lines&nbsp;until&nbsp;they&nbsp;meet.&nbsp;You&nbsp;can&nbsp;adjust&nbsp;the&nbsp;effect&nbsp;of&nbsp;this&nbsp;attribute&nbsp;using&nbsp;**miterLimit**. |
| [miterLimit](#miterlimit) | number | 10 | Maximum&nbsp;miter&nbsp;length.&nbsp;The&nbsp;miter&nbsp;length&nbsp;is&nbsp;the&nbsp;distance&nbsp;between&nbsp;the&nbsp;inner&nbsp;corner&nbsp;and&nbsp;the&nbsp;outer&nbsp;corner&nbsp;where&nbsp;two&nbsp;lines&nbsp;meet. |
| [font](#font) | string | 'normal&nbsp;normal&nbsp;14px&nbsp;sans-serif' | Font&nbsp;style.<br/>Syntax:&nbsp;ctx.font='font-size&nbsp;font-family'<br/>-&nbsp;(Optional)&nbsp;**font-size**:&nbsp;font&nbsp;size&nbsp;and&nbsp;row&nbsp;height.&nbsp;The&nbsp;unit&nbsp;can&nbsp;only&nbsp;be&nbsp;px.<br/>-&nbsp;(Optional)&nbsp;**font-family**:&nbsp;font&nbsp;family.<br/>Syntax:&nbsp;ctx.font='font-style&nbsp;font-weight&nbsp;font-size&nbsp;font-family'<br/>-&nbsp;(Optional)&nbsp;**font-style**:&nbsp;font&nbsp;style.&nbsp;Available&nbsp;values&nbsp;are&nbsp;**'normal'**&nbsp;and&nbsp;**'italic'**.<br/>-&nbsp;(Optional)&nbsp;**font-weight**:&nbsp;font&nbsp;weight.&nbsp;Available&nbsp;values&nbsp;are&nbsp;as&nbsp;follows:&nbsp;**'normal'**,&nbsp;**'bold'**,&nbsp;**'bolder'**,&nbsp;**'lighter'**,&nbsp;**100**,&nbsp;**200**,&nbsp;**300**,&nbsp;**400**,&nbsp;**500**,&nbsp;**600**,&nbsp;**700**,&nbsp;**800**,&nbsp;**900**<br/>-&nbsp;(Optional)&nbsp;**font-size**:&nbsp;font&nbsp;size&nbsp;and&nbsp;row&nbsp;height.&nbsp;The&nbsp;unit&nbsp;can&nbsp;only&nbsp;be&nbsp;px.<br/>-&nbsp;(Optional)&nbsp;**font-family**:&nbsp;font&nbsp;family.&nbsp;Available&nbsp;values&nbsp;are&nbsp;**'sans-serif'**,&nbsp;**'serif'**,&nbsp;and&nbsp;**'monospace'**. |
| [textAlign](#textalign) | string | 'left' | Text&nbsp;alignment&nbsp;mode.&nbsp;Available&nbsp;values&nbsp;are&nbsp;as&nbsp;follows:<br/>-&nbsp;**'left'**:&nbsp;The&nbsp;text&nbsp;is&nbsp;left-aligned.<br/>-&nbsp;**'right'**:&nbsp;The&nbsp;text&nbsp;is&nbsp;right-aligned.<br/>-&nbsp;**'center'**:&nbsp;The&nbsp;text&nbsp;is&nbsp;center-aligned.<br/>-&nbsp;**'start'**:&nbsp;The&nbsp;text&nbsp;is&nbsp;aligned&nbsp;with&nbsp;the&nbsp;start&nbsp;bound.<br/>-&nbsp;**'end'**:&nbsp;The&nbsp;text&nbsp;is&nbsp;aligned&nbsp;with&nbsp;the&nbsp;end&nbsp;bound.<br/>>&nbsp;![icon-note.gif](public_sys-resources/icon-note.gif)&nbsp;**NOTE：**<br/>>&nbsp;In&nbsp;the&nbsp;**ltr**&nbsp;layout&nbsp;mode,&nbsp;the&nbsp;value&nbsp;**'start'**&nbsp;equals&nbsp;**'left'**.&nbsp;In&nbsp;the&nbsp;**rtl**&nbsp;layout&nbsp;mode,&nbsp;the&nbsp;value&nbsp;**'start'**&nbsp;equals&nbsp;**'right'**. |
| [textBaseline](#textbaseline) | string | 'alphabetic' | Horizontal&nbsp;alignment&nbsp;mode&nbsp;of&nbsp;text.&nbsp;Available&nbsp;values&nbsp;are&nbsp;as&nbsp;follows:<br/>-&nbsp;**'alphabetic'**:&nbsp;The&nbsp;text&nbsp;baseline&nbsp;is&nbsp;the&nbsp;normal&nbsp;alphabetic&nbsp;baseline.<br/>-&nbsp;**'top'**:&nbsp;The&nbsp;text&nbsp;baseline&nbsp;is&nbsp;on&nbsp;the&nbsp;top&nbsp;of&nbsp;the&nbsp;text&nbsp;bounding&nbsp;box.<br/>-&nbsp;**'hanging'**:&nbsp;The&nbsp;text&nbsp;baseline&nbsp;is&nbsp;a&nbsp;hanging&nbsp;baseline&nbsp;over&nbsp;the&nbsp;text.<br/>-&nbsp;**'middle'**:&nbsp;The&nbsp;text&nbsp;baseline&nbsp;is&nbsp;in&nbsp;the&nbsp;middle&nbsp;of&nbsp;the&nbsp;text&nbsp;bounding&nbsp;box.<br/>-&nbsp;**'ideographic'**:&nbsp;The&nbsp;text&nbsp;baseline&nbsp;is&nbsp;the&nbsp;ideographic&nbsp;baseline.&nbsp;If&nbsp;a&nbsp;character&nbsp;exceeds&nbsp;the&nbsp;alphabetic&nbsp;baseline,&nbsp;the&nbsp;ideographic&nbsp;baseline&nbsp;is&nbsp;located&nbsp;at&nbsp;the&nbsp;bottom&nbsp;of&nbsp;the&nbsp;excess&nbsp;character.<br/>-&nbsp;**'bottom'**:&nbsp;The&nbsp;text&nbsp;baseline&nbsp;is&nbsp;at&nbsp;the&nbsp;bottom&nbsp;of&nbsp;the&nbsp;text&nbsp;bounding&nbsp;box.&nbsp;Its&nbsp;difference&nbsp;from&nbsp;the&nbsp;ideographic&nbsp;baseline&nbsp;is&nbsp;that&nbsp;the&nbsp;ideographic&nbsp;baseline&nbsp;does&nbsp;not&nbsp;consider&nbsp;letters&nbsp;in&nbsp;the&nbsp;next&nbsp;line. |
| [globalAlpha](#globalalpha) | number | - | Opacity.&nbsp;**0.0**:&nbsp;completely&nbsp;transparent;&nbsp;**1.0**:&nbsp;completely&nbsp;opaque. |
| [lineDashOffset](#linedashoffset) | number | 0.0 | Offset&nbsp;of&nbsp;the&nbsp;dashed&nbsp;line.&nbsp;The&nbsp;precision&nbsp;is&nbsp;float. |
| [globalCompositeOperation](#globalcompositeoperation) | string | 'source-over' | Composition&nbsp;operation&nbsp;type.&nbsp;Available&nbsp;values&nbsp;are&nbsp;as&nbsp;follows:&nbsp;**'source-over'**,&nbsp;**'source-atop'**,&nbsp;**'source-in'**,&nbsp;**'source-out'**,&nbsp;**'destination-over'**,&nbsp;**'destination-atop'**,&nbsp;**'destination-in'**,&nbsp;**'destination-out'**,&nbsp;**'lighter'**,&nbsp;**'copy'**,&nbsp;and&nbsp;**'xor'**. |
| [shadowBlur](#shadowblur) | number | 0.0 | Blur&nbsp;level&nbsp;during&nbsp;shadow&nbsp;drawing.&nbsp;A&nbsp;larger&nbsp;value&nbsp;indicates&nbsp;a&nbsp;more&nbsp;blurred&nbsp;effect.&nbsp;The&nbsp;precision&nbsp;is&nbsp;float. |
| [shadowColor](#shadowcolor) | &lt;color&gt; | - | Shadow&nbsp;color. |
| [shadowOffsetX](#shadowoffsetx) | number | - | X-axis&nbsp;shadow&nbsp;offset&nbsp;relative&nbsp;to&nbsp;the&nbsp;original&nbsp;object. |
| [shadowOffsetY](#shadowoffsety) | number | - | Y-axis&nbsp;shadow&nbsp;offset&nbsp;relative&nbsp;to&nbsp;the&nbsp;original&nbsp;object. |
| [imageSmoothingEnabled](#imagesmoothingenabled) | boolean | true | Whether&nbsp;to&nbsp;adjust&nbsp;the&nbsp;image&nbsp;smoothness&nbsp;during&nbsp;image&nbsp;drawing.&nbsp;The&nbsp;value&nbsp;**true**&nbsp;means&nbsp;to&nbsp;enable&nbsp;this&nbsp;feature,&nbsp;and&nbsp;**false**&nbsp;means&nbsp;the&nbsp;opposite. |
| imageSmoothingQuality | string | 'low' | Image&nbsp;smoothness.&nbsp;The&nbsp;value&nbsp;can&nbsp;be&nbsp;**'low'**,&nbsp;**'medium'**,&nbsp;or&nbsp;**'high'**. |

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE：**
> The value of the **&lt;color&gt;** type can be in 'rgb(255, 255, 255)', 'rgba(255, 255, 255, 1.0)', or '\#FFFFFF' format.


### fillStyle


```
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


```
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


```
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


```
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


```
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


```
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


```
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


```
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


```
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


```
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


```
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

  | Name | Description | 
| -------- | -------- |
| source-over | Displays&nbsp;the&nbsp;new&nbsp;drawing&nbsp;above&nbsp;the&nbsp;existing&nbsp;drawing.&nbsp;This&nbsp;attribute&nbsp;is&nbsp;used&nbsp;by&nbsp;default. | 
| source-atop | Displays&nbsp;the&nbsp;new&nbsp;drawing&nbsp;on&nbsp;the&nbsp;top&nbsp;of&nbsp;the&nbsp;existing&nbsp;drawing. | 
| source-in | Displays&nbsp;the&nbsp;new&nbsp;drawing&nbsp;inside&nbsp;the&nbsp;existing&nbsp;drawing. | 
| source-out | Displays&nbsp;the&nbsp;part&nbsp;of&nbsp;the&nbsp;new&nbsp;drawing&nbsp;that&nbsp;is&nbsp;outside&nbsp;of&nbsp;the&nbsp;existing&nbsp;drawing. | 
| destination-over | Displays&nbsp;the&nbsp;existing&nbsp;drawing&nbsp;above&nbsp;the&nbsp;new&nbsp;drawing. | 
| destination-atop | Displays&nbsp;the&nbsp;existing&nbsp;drawing&nbsp;on&nbsp;the&nbsp;top&nbsp;of&nbsp;the&nbsp;new&nbsp;drawing. | 
| destination-in | Displays&nbsp;the&nbsp;existing&nbsp;drawing&nbsp;inside&nbsp;the&nbsp;new&nbsp;drawing. | 
| destination-out | Displays&nbsp;the&nbsp;part&nbsp;of&nbsp;the&nbsp;existing&nbsp;drawing&nbsp;that&nbsp;is&nbsp;outside&nbsp;of&nbsp;the&nbsp;new&nbsp;drawing. | 
| lighter | Displays&nbsp;both&nbsp;the&nbsp;new&nbsp;drawing&nbsp;and&nbsp;the&nbsp;existing&nbsp;drawing. | 
| copy | Displays&nbsp;the&nbsp;new&nbsp;drawing&nbsp;and&nbsp;neglects&nbsp;the&nbsp;existing&nbsp;drawing. | 
| xor | Combines&nbsp;the&nbsp;new&nbsp;drawing&nbsp;and&nbsp;existing&nbsp;drawing&nbsp;using&nbsp;the&nbsp;XOR&nbsp;operation. | 


```
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


```
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


```
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


```
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


```
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


```
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
    | Name | Type | Mandatory | Default&nbsp;Value | Description | 
  | -------- | -------- | -------- | -------- | -------- |
  | x | number | Yes | 0 | X-coordinate&nbsp;of&nbsp;the&nbsp;upper&nbsp;left&nbsp;corner&nbsp;of&nbsp;the&nbsp;rectangle. | 
  | y | number | Yes | 0 | Y-coordinate&nbsp;of&nbsp;the&nbsp;upper&nbsp;left&nbsp;corner&nbsp;of&nbsp;the&nbsp;rectangle. | 
  | width | number | Yes | 0 | Width&nbsp;of&nbsp;the&nbsp;rectangle. | 
  | height | number | Yes | 0 | Height&nbsp;of&nbsp;the&nbsp;rectangle. | 

- Example
  
  ```
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
    | Name | Type | Mandatory | Default&nbsp;Value | Description | 
  | -------- | -------- | -------- | -------- | -------- |
  | x | number | Yes | 0 | X-coordinate&nbsp;of&nbsp;the&nbsp;upper&nbsp;left&nbsp;corner&nbsp;of&nbsp;the&nbsp;rectangle. | 
  | y | number | Yes | 0 | Y-coordinate&nbsp;of&nbsp;the&nbsp;upper&nbsp;left&nbsp;corner&nbsp;of&nbsp;the&nbsp;rectangle. | 
  | width | number | Yes | 0 | Width&nbsp;of&nbsp;the&nbsp;rectangle. | 
  | height | number | Yes | 0 | Height&nbsp;of&nbsp;the&nbsp;rectangle. | 

- Example
  
  ```
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
    | Name | Type | Mandatory | Default&nbsp;Value | Description | 
  | -------- | -------- | -------- | -------- | -------- |
  | x | number | Yes | 0 | X-coordinate&nbsp;of&nbsp;the&nbsp;upper&nbsp;left&nbsp;corner&nbsp;of&nbsp;the&nbsp;rectangle. | 
  | y | number | Yes | 0 | Y-coordinate&nbsp;of&nbsp;the&nbsp;upper&nbsp;left&nbsp;corner&nbsp;of&nbsp;the&nbsp;rectangle. | 
  | width | number | Yes | 0 | Width&nbsp;of&nbsp;the&nbsp;rectangle. | 
  | height | number | Yes | 0 | Height&nbsp;of&nbsp;the&nbsp;rectangle. | 

- Example
  
  ```
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
    | Name | Type | Mandatory | Default&nbsp;Value | Description | 
  | -------- | -------- | -------- | -------- | -------- |
  | text | string | Yes | "" | Text&nbsp;to&nbsp;draw. | 
  | x | number | Yes | 0 | X-coordinate&nbsp;of&nbsp;the&nbsp;lower&nbsp;left&nbsp;corner&nbsp;of&nbsp;the&nbsp;text. | 
  | y | number | Yes | 0 | Y-coordinate&nbsp;of&nbsp;the&nbsp;lower&nbsp;left&nbsp;corner&nbsp;of&nbsp;the&nbsp;text. | 

- Example
  
  ```
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
    | Name | Type | Mandatory | Default&nbsp;Value | Description | 
  | -------- | -------- | -------- | -------- | -------- |
  | text | string | Yes | "" | Text&nbsp;to&nbsp;draw. | 
  | x | number | Yes | 0 | X-coordinate&nbsp;of&nbsp;the&nbsp;lower&nbsp;left&nbsp;corner&nbsp;of&nbsp;the&nbsp;text. | 
  | y | number | Yes | 0 | Y-coordinate&nbsp;of&nbsp;the&nbsp;lower&nbsp;left&nbsp;corner&nbsp;of&nbsp;the&nbsp;text. | 

- Example
  
  ```
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
    | Name | Type | Mandatory | Default&nbsp;Value | Description | 
  | -------- | -------- | -------- | -------- | -------- |
  | text | string | Yes | "" | Text&nbsp;to&nbsp;be&nbsp;measured. | 

- Return value
    | Type | Description | 
  | -------- | -------- |
  | TextMetrics | **TextMetrics**&nbsp;object. | 

- **TextMetrics** attributes
    | Name | Type | Description | 
  | -------- | -------- | -------- |
  | width | number | Width&nbsp;of&nbsp;the&nbsp;text. | 

- Example
  
  ```
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
    | Name | Type | Mandatory | Default&nbsp;Value | Description | 
  | -------- | -------- | -------- | -------- | -------- |
  | path | [Path2D](../reference/arkui-ts/ts-components-canvas-path2d.md) | No | null | A&nbsp;**Path2D**&nbsp;path&nbsp;to&nbsp;draw. | 

- Example
  
  ```
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
  
  ```
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
    | Name | Type | Mandatory | Default&nbsp;Value | Description | 
  | -------- | -------- | -------- | -------- | -------- |
  | x | number | Yes | 0 | X-coordinate&nbsp;of&nbsp;the&nbsp;target&nbsp;position. | 
  | y | number | Yes | 0 | Y-coordinate&nbsp;of&nbsp;the&nbsp;target&nbsp;position. | 

- Example
  
  ```
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
    | Name | Type | Mandatory | Default&nbsp;Value | Description | 
  | -------- | -------- | -------- | -------- | -------- |
  | x | number | Yes | 0 | X-coordinate&nbsp;of&nbsp;the&nbsp;target&nbsp;position. | 
  | y | number | Yes | 0 | Y-coordinate&nbsp;of&nbsp;the&nbsp;target&nbsp;position. | 

- Example
  
  ```
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
  
  ```
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
    | Name | Type | Mandatory | Default&nbsp;Value | Description | 
  | -------- | -------- | -------- | -------- | -------- |
  | image | [ERROR:Invalid&nbsp;link:en-us_topic_0000001212378364.xml#en-us_topic_0000001193075104_xref1892917323814,link:en-us_topic_0000001192915114.xml](en-us_topic_0000001192915114.xml) | Yes | null | Source&nbsp;image.&nbsp;For&nbsp;details,&nbsp;see&nbsp;[ERROR:Invalid&nbsp;link:en-us_topic_0000001212378364.xml#xref539610179238,link:en-us_topic_0000001192915114.xml](en-us_topic_0000001192915114.xml). | 
  | repetition | string | Yes | "" | Repetition&nbsp;mode.&nbsp;The&nbsp;value&nbsp;can&nbsp;be&nbsp;**'repeat'**,&nbsp;**'repeat-x'**,&nbsp;**'repeat-y'**,&nbsp;or&nbsp;**'no-repeat'**. | 

- Example
  
  ```
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
    | Name | Type | Mandatory | Default&nbsp;Value | Description | 
  | -------- | -------- | -------- | -------- | -------- |
  | cp1x | number | Yes | 0 | X-coordinate&nbsp;of&nbsp;the&nbsp;first&nbsp;parameter&nbsp;of&nbsp;the&nbsp;bezier&nbsp;curve. | 
  | cp1y | number | Yes | 0 | Y-coordinate&nbsp;of&nbsp;the&nbsp;first&nbsp;parameter&nbsp;of&nbsp;the&nbsp;bezier&nbsp;curve. | 
  | cp2x | number | Yes | 0 | X-coordinate&nbsp;of&nbsp;the&nbsp;second&nbsp;parameter&nbsp;of&nbsp;the&nbsp;bezier&nbsp;curve. | 
  | cp2y | number | Yes | 0 | Y-coordinate&nbsp;of&nbsp;the&nbsp;second&nbsp;parameter&nbsp;of&nbsp;the&nbsp;bezier&nbsp;curve. | 
  | x | number | Yes | 0 | X-coordinate&nbsp;of&nbsp;the&nbsp;end&nbsp;point&nbsp;on&nbsp;the&nbsp;bezier&nbsp;curve. | 
  | y | number | Yes | 0 | Y-coordinate&nbsp;of&nbsp;the&nbsp;end&nbsp;point&nbsp;on&nbsp;the&nbsp;bezier&nbsp;curve. | 

- Example
  
  ```
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
    | Name | Type | Mandatory | Default&nbsp;Value | Description | 
  | -------- | -------- | -------- | -------- | -------- |
  | cpx | number | Yes | 0 | X-coordinate&nbsp;of&nbsp;the&nbsp;bezier&nbsp;curve&nbsp;parameter. | 
  | cpy | number | Yes | 0 | Y-coordinate&nbsp;of&nbsp;the&nbsp;bezier&nbsp;curve&nbsp;parameter. | 
  | x | number | Yes | 0 | X-coordinate&nbsp;of&nbsp;the&nbsp;end&nbsp;point&nbsp;on&nbsp;the&nbsp;bezier&nbsp;curve. | 
  | y | number | Yes | 0 | Y-coordinate&nbsp;of&nbsp;the&nbsp;end&nbsp;point&nbsp;on&nbsp;the&nbsp;bezier&nbsp;curve. | 

- Example
  
  ```
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
    | Name | Type | Mandatory | Default&nbsp;Value | Description | 
  | -------- | -------- | -------- | -------- | -------- |
  | x | number | Yes | 0 | X-coordinate&nbsp;of&nbsp;the&nbsp;center&nbsp;point&nbsp;of&nbsp;the&nbsp;arc. | 
  | y | number | Yes | 0 | Y-coordinate&nbsp;of&nbsp;the&nbsp;center&nbsp;point&nbsp;of&nbsp;the&nbsp;arc. | 
  | radius | number | Yes | 0 | Radius&nbsp;of&nbsp;the&nbsp;arc. | 
  | startAngle | number | Yes | 0 | Start&nbsp;radian&nbsp;of&nbsp;the&nbsp;arc. | 
  | endAngle | number | Yes | 0 | End&nbsp;radian&nbsp;of&nbsp;the&nbsp;arc. | 
  | anticlockwise | boolean | No | false | Whether&nbsp;to&nbsp;draw&nbsp;the&nbsp;arc&nbsp;counterclockwise. | 

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
    | Name | Type | Mandatory | Default&nbsp;Value | Description | 
  | -------- | -------- | -------- | -------- | -------- |
  | x1 | number | Yes | 0 | X-coordinate&nbsp;of&nbsp;the&nbsp;first&nbsp;point&nbsp;on&nbsp;the&nbsp;arc. | 
  | y1 | number | Yes | 0 | Y-coordinate&nbsp;of&nbsp;the&nbsp;first&nbsp;point&nbsp;on&nbsp;the&nbsp;arc. | 
  | x2 | number | Yes | 0 | X-coordinate&nbsp;of&nbsp;the&nbsp;second&nbsp;point&nbsp;on&nbsp;the&nbsp;arc. | 
  | y2 | number | Yes | 0 | Y-coordinate&nbsp;of&nbsp;the&nbsp;second&nbsp;point&nbsp;on&nbsp;the&nbsp;arc. | 
  | radius | number | Yes | 0 | Radius&nbsp;of&nbsp;the&nbsp;arc. | 

- Example
  
  ```
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
    | Name | Type | Mandatory | Default&nbsp;Value | Description | 
  | -------- | -------- | -------- | -------- | -------- |
  | x | number | Yes | 0 | X-coordinate&nbsp;of&nbsp;the&nbsp;ellipse&nbsp;center. | 
  | y | number | Yes | 0 | Y-coordinate&nbsp;of&nbsp;the&nbsp;ellipse&nbsp;center. | 
  | radiusX | number | Yes | 0 | Ellipse&nbsp;radius&nbsp;on&nbsp;the&nbsp;x-axis. | 
  | radiusY | number | Yes | 0 | Ellipse&nbsp;radius&nbsp;on&nbsp;the&nbsp;y-axis. | 
  | rotation | number | Yes | 0 | Rotation&nbsp;angle&nbsp;of&nbsp;the&nbsp;ellipse,&nbsp;in&nbsp;radians. | 
  | startAngle | number | Yes | 0 | Angle&nbsp;of&nbsp;the&nbsp;start&nbsp;point&nbsp;for&nbsp;drawing&nbsp;the&nbsp;ellipse,&nbsp;in&nbsp;radians. | 
  | endAngle | number | Yes | 0 | Angle&nbsp;of&nbsp;the&nbsp;end&nbsp;point&nbsp;for&nbsp;drawing&nbsp;the&nbsp;ellipse,&nbsp;in&nbsp;radians. | 
  | anticlockwise | boolean | No | false | Whether&nbsp;to&nbsp;draw&nbsp;the&nbsp;ellipse&nbsp;in&nbsp;the&nbsp;counterclockwise&nbsp;direction. | 

- Example

  
  ```
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
    | Name | Type | Mandatory | Default&nbsp;Value | Description | 
  | -------- | -------- | -------- | -------- | -------- |
  | x | number | Yes | 0 | X-coordinate&nbsp;of&nbsp;the&nbsp;upper&nbsp;left&nbsp;corner&nbsp;of&nbsp;the&nbsp;rectangle. | 
  | y | number | Yes | 0 | Y-coordinate&nbsp;of&nbsp;the&nbsp;upper&nbsp;left&nbsp;corner&nbsp;of&nbsp;the&nbsp;rectangle. | 
  | width | number | Yes | 0 | Width&nbsp;of&nbsp;the&nbsp;rectangle. | 
  | height | number | Yes | 0 | Height&nbsp;of&nbsp;the&nbsp;rectangle. | 

- Example
  
  ```
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
  
  ```
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
  
  ```
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
    | Name | Type | Mandatory | Default&nbsp;Value | Description | 
  | -------- | -------- | -------- | -------- | -------- |
  | rotate | number | Yes | 0 | Clockwise&nbsp;rotation&nbsp;angle.&nbsp;You&nbsp;can&nbsp;use&nbsp;**Math.PI&nbsp;/&nbsp;180**&nbsp;to&nbsp;convert&nbsp;the&nbsp;angle&nbsp;to&nbsp;a&nbsp;radian. | 

- Example
  
  ```
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
    | Name | Type | Mandatory | Default&nbsp;Value | Description | 
  | -------- | -------- | -------- | -------- | -------- |
  | x | number | Yes | 0 | Horizontal&nbsp;scale&nbsp;factor. | 
  | y | number | Yes | 0 | Vertical&nbsp;scale&nbsp;factor. | 

- Example
  
  ```
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

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE：**
> The following formulas calculate coordinates of the transformed graph. **x** and **y** represent coordinates before transformation, and **x'** and **y'** represent coordinates after transformation.
> 
> - x' = scaleX \* x + skewY \* y + translateX
> 
> - y' = skewX \* x + scaleY \* y + translateY

- Parameters
    | Name | Type | Mandatory | Default&nbsp;Value | Description | 
  | -------- | -------- | -------- | -------- | -------- |
  | scaleX | number | Yes | 0 | X-axis&nbsp;scale. | 
  | skewX | number | Yes | 0 | X-axis&nbsp;skew. | 
  | skewY | number | Yes | 0 | Y-axis&nbsp;skew. | 
  | scaleY | number | Yes | 0 | Y-axis&nbsp;scale. | 
  | translateX | number | Yes | 0 | X-axis&nbsp;translation. | 
  | translateY | number | Yes | 0 | Y-axis&nbsp;translation. | 

- Example
  
  ```
  @Entry
  @Component
  struct Transform {
    private settings: RenderingContextSettings = new RenderingContextSettings(true)
    private context: RenderingContext = new RenderingContext(this.settings)
  
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
    | Name | Type | Mandatory | Default&nbsp;Value | Description | 
  | -------- | -------- | -------- | -------- | -------- |
  | scaleX | number | Yes | 0 | X-axis&nbsp;scale. | 
  | skewX | number | Yes | 0 | X-axis&nbsp;skew. | 
  | skewY | number | Yes | 0 | Y-axis&nbsp;skew. | 
  | scaleY | number | Yes | 0 | Y-axis&nbsp;scale. | 
  | translateX | number | Yes | 0 | X-axis&nbsp;translation. | 
  | translateY | number | Yes | 0 | Y-axis&nbsp;translation. | 

- Example
  
  ```
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
    | Name | Type | Mandatory | Default&nbsp;Value | Description | 
  | -------- | -------- | -------- | -------- | -------- |
  | x | number | Yes | 0 | X-axis&nbsp;translation. | 
  | y | number | Yes | 0 | Y-axis&nbsp;translation. | 

- Example
  
  ```
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

drawImage(image: ImageBitmap, dx: number, dy: number): void

drawImage(image: ImageBitmap, dx: number, dy: number, dWidth: number, dHeight: number): void

drawImage(image: ImageBitmap, sx: number, sy: number, sWidth: number, sHeight: number, dx: number, dy: number, dWidth: number, dHeight: number):void

Draws an image.

- Parameters
    | Name | Type | Mandatory | Default&nbsp;Value | Description | 
  | -------- | -------- | -------- | -------- | -------- |
  | image | [ERROR:Invalid&nbsp;link:en-us_topic_0000001212378364.xml#en-us_topic_0000001193075104_xref962584519412,link:en-us_topic_0000001192915114.xml](en-us_topic_0000001192915114.xml) | Yes | null | Image&nbsp;resource.&nbsp;For&nbsp;details,&nbsp;see&nbsp;[ERROR:Invalid&nbsp;link:en-us_topic_0000001212378364.xml#xref29052050153012,link:en-us_topic_0000001192915114.xml](en-us_topic_0000001192915114.xml). | 
  | sx | number | No | 0 | X-coordinate&nbsp;of&nbsp;the&nbsp;upper&nbsp;left&nbsp;corner&nbsp;of&nbsp;the&nbsp;rectangle&nbsp;used&nbsp;to&nbsp;crop&nbsp;the&nbsp;source&nbsp;image. | 
  | sy | number | No | 0 | Y-coordinate&nbsp;of&nbsp;the&nbsp;upper&nbsp;left&nbsp;corner&nbsp;of&nbsp;the&nbsp;rectangle&nbsp;used&nbsp;to&nbsp;crop&nbsp;the&nbsp;source&nbsp;image. | 
  | sWidth | number | No | 0 | Target&nbsp;width&nbsp;to&nbsp;crop&nbsp;the&nbsp;source&nbsp;image. | 
  | sHeight | number | No | 0 | Target&nbsp;height&nbsp;to&nbsp;crop&nbsp;the&nbsp;source&nbsp;image. | 
  | dx | number | Yes | 0 | X-coordinate&nbsp;of&nbsp;the&nbsp;upper&nbsp;left&nbsp;corner&nbsp;of&nbsp;the&nbsp;drawing&nbsp;area&nbsp;on&nbsp;the&nbsp;canvas. | 
  | dy | number | Yes | 0 | Y-coordinate&nbsp;of&nbsp;the&nbsp;upper&nbsp;left&nbsp;corner&nbsp;of&nbsp;the&nbsp;drawing&nbsp;area&nbsp;on&nbsp;the&nbsp;canvas. | 
  | dWidth | number | No | 0 | Width&nbsp;of&nbsp;the&nbsp;drawing&nbsp;area. | 
  | dHeight | number | No | 0 | Height&nbsp;of&nbsp;the&nbsp;drawing&nbsp;area. | 


- Example
  
  ```
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

Creates an **ImageData** object. For details, see [ImageData](../reference/arkui-ts/ts-components-canvas-imagebitmap.md).

- Parameters
    | Name | Type | Mandatory | Default&nbsp;Value | Description | 
  | -------- | -------- | -------- | -------- | -------- |
  | width | number | Yes | 0 | Width&nbsp;of&nbsp;the&nbsp;**ImageData**&nbsp;object. | 
  | height | number | Yes | 0 | Height&nbsp;of&nbsp;the&nbsp;**ImageData**&nbsp;object. | 


### createImageData

createImageData(imageData: Object): Object

Creates an **ImageData** object. For details, see [ImageData](../reference/arkui-ts/ts-components-canvas-imagebitmap.md).

- Parameters
    | Name | Type | Mandatory | Default&nbsp;Value | Description | 
  | -------- | -------- | -------- | -------- | -------- |
  | imagedata | Object | Yes | null | **ImageData**&nbsp;object&nbsp;with&nbsp;the&nbsp;same&nbsp;width&nbsp;and&nbsp;height&nbsp;copied&nbsp;from&nbsp;the&nbsp;original&nbsp;**ImageData**&nbsp;object. | 


### getImageData

getImageData(sx: number, sy: number, sw: number, sh: number): Object

  Creates an [ImageData](../reference/arkui-ts/ts-components-canvas-imagebitmap.md) object with pixels in the specified area on the canvas.
- Parameters
    | Name | Type | Mandatory | Default&nbsp;Value | Description | 
  | -------- | -------- | -------- | -------- | -------- |
  | sx | number | Yes | 0 | X-coordinate&nbsp;of&nbsp;the&nbsp;upper&nbsp;left&nbsp;corner&nbsp;of&nbsp;the&nbsp;output&nbsp;area. | 
  | sy | number | Yes | 0 | Y-coordinate&nbsp;of&nbsp;the&nbsp;upper&nbsp;left&nbsp;corner&nbsp;of&nbsp;the&nbsp;output&nbsp;area. | 
  | sw | number | Yes | 0 | Width&nbsp;of&nbsp;the&nbsp;output&nbsp;area. | 
  | sh | number | Yes | 0 | Height&nbsp;of&nbsp;the&nbsp;output&nbsp;area. | 


### putImageData

putImageData(imageData: Object, dx: number, dy: number, dirtyX?: number, dirtyY?: number, dirtyWidth?: number, dirtyHeight?: number): void

Puts the [ImageData](../reference/arkui-ts/ts-components-canvas-imagebitmap.md) onto a rectangular area on the canvas.

- Parameters
    | Name | Type | Mandatory | Default&nbsp;Value | Description | 
  | -------- | -------- | -------- | -------- | -------- |
  | imagedata | Object | Yes | null | **ImageData**&nbsp;object&nbsp;with&nbsp;pixels&nbsp;to&nbsp;put&nbsp;onto&nbsp;the&nbsp;canvas. | 
  | dx | number | Yes | 0 | X-axis&nbsp;offset&nbsp;of&nbsp;the&nbsp;rectangular&nbsp;area&nbsp;on&nbsp;the&nbsp;canvas. | 
  | dy | number | Yes | 0 | Y-axis&nbsp;offset&nbsp;of&nbsp;the&nbsp;rectangular&nbsp;area&nbsp;on&nbsp;the&nbsp;canvas. | 
  | dirtyX | number | No | 0 | X-axis&nbsp;offset&nbsp;of&nbsp;the&nbsp;upper&nbsp;left&nbsp;corner&nbsp;of&nbsp;the&nbsp;rectangular&nbsp;area&nbsp;relative&nbsp;to&nbsp;that&nbsp;of&nbsp;the&nbsp;source&nbsp;image. | 
  | dirtyY | number | No | 0 | Y-axis&nbsp;offset&nbsp;of&nbsp;the&nbsp;upper&nbsp;left&nbsp;corner&nbsp;of&nbsp;the&nbsp;rectangular&nbsp;area&nbsp;relative&nbsp;to&nbsp;that&nbsp;of&nbsp;the&nbsp;source&nbsp;image. | 
  | dirtyWidth | number | No | Width&nbsp;of&nbsp;the&nbsp;**ImageData**&nbsp;object | Width&nbsp;of&nbsp;the&nbsp;rectangular&nbsp;area&nbsp;to&nbsp;crop&nbsp;the&nbsp;source&nbsp;image. | 
  | dirtyHeight | number | No | Height&nbsp;of&nbsp;the&nbsp;**ImageData**&nbsp;object | Height&nbsp;of&nbsp;the&nbsp;rectangular&nbsp;area&nbsp;to&nbsp;crop&nbsp;the&nbsp;source&nbsp;image. | 

- Example
  
  ```
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
  
  ```
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
  
  ```
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
    | Name | Type | Mandatory | Default&nbsp;Value | Description | 
  | -------- | -------- | -------- | -------- | -------- |
  | x0 | number | Yes | 0 | X-coordinate&nbsp;of&nbsp;the&nbsp;start&nbsp;point. | 
  | y0 | number | Yes | 0 | Y-coordinate&nbsp;of&nbsp;the&nbsp;start&nbsp;point. | 
  | x1 | number | Yes | 0 | X-coordinate&nbsp;of&nbsp;the&nbsp;end&nbsp;point. | 
  | y1 | number | Yes | 0 | Y-coordinate&nbsp;of&nbsp;the&nbsp;end&nbsp;point. | 

- Example
  
  ```
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
            this.grad.addColorStop(0.0, 'red')
            this.grad.addColorStop(0.5, 'white')
            this.grad.addColorStop(1.0, 'green')
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
    | Name | Type | Mandatory | Default&nbsp;Value | Description | 
  | -------- | -------- | -------- | -------- | -------- |
  | x0 | number | Yes | 0 | X-coordinate&nbsp;of&nbsp;the&nbsp;center&nbsp;of&nbsp;the&nbsp;start&nbsp;circle. | 
  | y0 | number | Yes | 0 | Y-coordinate&nbsp;of&nbsp;the&nbsp;center&nbsp;of&nbsp;the&nbsp;start&nbsp;circle. | 
  | r0 | number | Yes | 0 | Radius&nbsp;of&nbsp;the&nbsp;start&nbsp;circle,&nbsp;which&nbsp;must&nbsp;be&nbsp;a&nbsp;non-negative&nbsp;finite&nbsp;number. | 
  | x1 | number | Yes | 0 | X-coordinate&nbsp;of&nbsp;the&nbsp;center&nbsp;of&nbsp;the&nbsp;end&nbsp;circle. | 
  | y1 | number | Yes | 0 | Y-coordinate&nbsp;of&nbsp;the&nbsp;center&nbsp;of&nbsp;the&nbsp;end&nbsp;circle. | 
  | r1 | number | Yes | 0 | Radius&nbsp;of&nbsp;the&nbsp;end&nbsp;circle,&nbsp;which&nbsp;must&nbsp;be&nbsp;a&nbsp;non-negative&nbsp;finite&nbsp;number. | 

- Example
  
  ```
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
            this.grad.addColorStop(0.0, 'red')
            this.grad.addColorStop(0.5, 'white')
            this.grad.addColorStop(1.0, 'green')
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
