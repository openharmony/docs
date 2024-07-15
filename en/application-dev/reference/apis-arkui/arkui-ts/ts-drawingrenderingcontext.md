# DrawingRenderingContext

**DrawingRenderingContext** provides a rendering context for drawing rectangles, text, images, and other objects on a canvas.

> **NOTE**
>
> This feature is supported since API version 12. Updates will be marked with a superscript to indicate their earliest API version.




## Attributes

| Name      | Type                                                        | Description                                                     |
| ---------- | ------------------------------------------------------------ | --------------------------------------------------------- |
| size       | {width: number, height: number}                              | Width and height of the context, in vp.                                           |
| canvas     | [Canvas](../../apis-arkgraphics2d/js-apis-graphics-drawing.md#canvas) | **Canvas** object. For details, see [Canvas](../../apis-arkgraphics2d/js-apis-graphics-drawing.md#canvas).|
| invalidate | void                                                         | Triggers re-rendering of the component.                             |

**Example**

This example shows how to use the APIs in **DrawingRenderingContext** for drawing.

```ts
// xxx.ets
@Entry
@Component
struct CanvasExample {
  private context: DrawingRenderingContext = new DrawingRenderingContext()

  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
      Canvas(this.context)
        .width('100%')
        .height('100%')
        .backgroundColor('#ffff00')
        .onReady(() => {
          this.context.canvas.drawCircle(200, 200, 100)
          this.context.invalidate()
        })
    }
    .width('100%')
    .height('100%')
  }
}
```
  ![en-us_image_0000001194032666](figures/canvas_drawingRenderingContext.png)
