#  Canvas

提供画布组件，用于自定义绘制图形。

> **说明：** 
>
>  该组件从API Version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## 子组件

不支持。

## 接口

Canvas(context?: CanvasRenderingContext2D)

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**参数：**

| 参数名  | 参数类型                                                     | 必填 | 参数描述                                                     |
| ------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| context | [CanvasRenderingContext2D](ts-canvasrenderingcontext2d.md) \| [DrawingRenderingContext<sup>12+</sup>](ts-drawingrenderingcontext.md) | 否   | CanvasRenderingContext2D: 不支持多个Canvas共用一个CanvasRenderingContext2D对象，具体描述见[CanvasRenderingContext2D](ts-canvasrenderingcontext2d.md)对象。DrawingRenderingContext: 不支持多个Canvas共用一个DrawingRenderingContext对象，具体描述见[DrawingRenderingContext](ts-drawingrenderingcontext.md)对象。 |

## 属性

除支持[通用属性](ts-universal-attributes-size.md)外，还支持以下属性：

### enableAnalyzer<sup>12+</sup>

设置组件支持AI分析，需要搭配[context](ts-canvasrenderingcontext2d.md)中的[StartImageAnalyzer](ts-canvasrenderingcontext2d.md#startimageanalyzer)和[StopImageAnalyzer](ts-canvasrenderingcontext2d.md#stopimageanalyzer)一起使用。
不能和[overlay](ts-universal-attributes-overlay.md)属性同时使用，两者同时设置时overlay中CustomBuilder属性将失效。该特性依赖设备能力。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型    | 必填 | 说明                                                         |
| ------ | ------- | ---- | ------------------------------------------------------------ |
| enable  | boolean | 是   | 组件支持AI分析，设置为true时，组件可进行AI分析。<br/>默认值：false |

## 事件

除支持[通用事件](ts-universal-events-click.md)外，还支持如下事件：

| 名称                         | 描述                                       |
| -------------------------- | ---------------------------------------- |
| onReady(event: () => void) | Canvas组件初始化完成时或者Canvas组件发生大小变化时的事件回调，当该事件被触发时画布被清空，该事件之后Canvas组件宽高确定且可获取，可使用Canvas相关API进行绘制。当Canvas组件仅发生位置变化时，只触发onAreaChange事件、不触发onReady事件。<br/>onAreaChange事件在onReady事件后触发。<br/>从API version 9开始，该接口支持在ArkTS卡片中使用。<br/>**元服务API：** 从API version 11开始，该接口支持在元服务中使用。 |

**示例：**

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
        .onReady(() => {
          this.context.fillRect(0, 30, 100, 100)
        })
    }
    .width('100%')
    .height('100%')
  }
}
```
  ![zh-cn_image_0000001194032666](figures/zh-cn_image_0000001194032666.png)
