# Canvas


> **NOTE**<br>
> This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.


The **&lt;Canvas&gt;** component can be used to customize drawings.


## Required Permissions

None


## Child Components

None


## APIs

Canvas(context: CanvasRenderingContext2D)

- Parameters
    | Name    | Type                                     | Mandatory | Default Value | Description                              |
    | ------- | ---------------------------------------- | --------- | ------------- | ---------------------------------------- |
    | context | [CanvasRenderingContext2D](ts-canvasrenderingcontext2d.md) | Yes     | -             | For details, see [CanvasRenderingContext2D](ts-canvasrenderingcontext2d.md). |


## Attributes

Universal attributes are supported.


## Events

In addition to universal events, the following events are supported.

| Name                             | Parameter | Description      |
| -------------------------------- | --------- | ---------------- |
| onReady(callback: () =&gt; void) | None      | Triggered when a canvas is ready. |


## Example


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
          this.context.fillRect(0,30,100,100)
        })
    }
    .width('100%')
    .height('100%')
  }
}
```
