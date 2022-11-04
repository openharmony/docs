#  Canvas

The **\<Canvas>** component can be used to customize drawings.

> **NOTE**
> 
>  This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.



## Required Permissions

None

## Child Components

Not supported

## APIs

Canvas(context?: CanvasRenderingContext2D)

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
| onReady(event: () => void) | -   | Triggered when a canvas is ready. When this event is triggered, the width and height of the canvas can be obtained, and you can use the canvas APIs to draw images.|


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
