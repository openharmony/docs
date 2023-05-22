#  Canvas

The **\<Canvas>** component can be used to customize drawings.

> **NOTE**
> 
>  This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.

## Child Components

Not supported

## APIs

Canvas(context?: CanvasRenderingContext2D)

Since API version 9, this API is supported in ArkTS widgets.

**Parameters**

| Name    | Type                                    | Mandatory  | Default Value | Description                        |
| ------- | ---------------------------------------- | ---- | ---- | ---------------------------- |
| context | [CanvasRenderingContext2D](ts-canvasrenderingcontext2d.md) | No   | -    | For details, see **CanvasRenderingContext2D**.|

## Attributes

The [universal attributes](ts-universal-attributes-size.md) are supported.

## Events

In addition to the [universal events](ts-universal-events-click.md), the following events are supported.

| Name                           | Parameter  | Description                  |
| ----------------------------- | ---- | -------------------- |
| onReady(event: () => void) | -   | Triggered when a canvas is ready or its size changes. When this event is triggered, the canvas is cleared. The width and height of the canvas can then be obtained, and you can use the canvas APIs to draw images. If the canvas is merely relocated, the **onAreaChange** event is triggered, but the **onReady** event is not.<br>Since API version 9, this API is supported in ArkTS widgets.|

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
        .onReady(() => {
          this.context.fillRect(0, 30, 100, 100)
        })
    }
    .width('100%')
    .height('100%')
  }
}
```
  ![en-us_image_0000001194032666](figures/en-us_image_0000001194032666.png)
