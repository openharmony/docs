#  Canvas

> **说明：** 该组件从API Version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

提供画布组件，用于自定义绘制图形。

## 权限列表

无

## 子组件

不支持。

## 接口

Canvas(context: CanvasRenderingContext2D)

- 参数

  | 参数名     | 参数类型                                     | 必填   | 默认值  | 参数描述                         |
  | ------- | ---------------------------------------- | ---- | ---- | ---------------------------- |
  | context | [CanvasRenderingContext2D](ts-canvasrenderingcontext2d.md) | 是    | -    | 见CanvasRenderingContext2D对象。 |

## 属性

支持通用属性。

## 事件

除支持通用事件外，还支持如下事件：

| 名称                            | 参数   | 描述                   |
| ----------------------------- | ---- | -------------------- |
| onReady(callback: () => void) | 无    | 画布组件的事件回调，可以在此时进行绘制。 |

## 示例

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
          this.context.fillRect(0,30,100,100)
        })
    }
    .width('100%')
    .height('100%')
  }
}
```
