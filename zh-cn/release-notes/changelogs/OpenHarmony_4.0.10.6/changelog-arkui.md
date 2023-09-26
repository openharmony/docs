# arkui子系统ChangeLog

## cl.arkui.1 setLineDash接口实现变更

**说明**
setLineDash接口参数number的单位由px变成vp。

**示例：**
```ts
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
          let ctx = this.context
          ctx.lineWidth = 5
          ctx.arc(100, 75, 50, 0, 6.28)
          ctx.setLineDash([10,20])
          ctx.stroke();
        })
      Image('image/SetLineDash.png')
        .objectFit(ImageFit.Contain)
    }
    .width('100%')
    .height('100%')
  }
}
```
API version 9：setLineDash接口参数number的单位为px。

![stack](figures/zh_cn_image_setLineDash_change_before.jpeg)

API version 10及以后：setLineDash接口参数number的单位为vp。

![stack](figures/zh_cn_image_setLineDash_change_after.jpeg)

**变更影响**

setLineDash接口参数number的单位由px变为vp，setLineDash接口在API version 9及以前与API version 10及以后的绘制效果不一样。