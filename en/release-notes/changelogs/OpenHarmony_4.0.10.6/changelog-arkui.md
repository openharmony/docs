# ArkUI Subsystem Changelog

## cl.arkui.1 setLineDash Implementation Change

 
Changed the unit of the **number** parameter in the **setLineDash** API from px to vp.

**Example**
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
API version 9: The unit of the **number** parameter in the **setLineDash** API is px.

![stack](figures/en-us_image_setLineDash_change_before.jpeg)

API version 10 and later: The unit of the **number** parameter in the **setLineDash** API is vp.

![stack](figures/en-us_image_setLineDash_change_after.jpeg)

**Change Impact**

The drawing effect of the **setLineDash** API in API version 9 or earlier is different from that in API version 10 or later.
