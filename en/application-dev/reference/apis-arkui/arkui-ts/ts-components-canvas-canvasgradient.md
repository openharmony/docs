# CanvasGradient

**CanvasGradient** provides a canvas gradient object.

>  **NOTE**
>
>  The APIs of this module are supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.



## addColorStop

addColorStop(offset: number, color: string): void

Adds a color stop for the **CanvasGradient** object based on the specified offset and gradient color.

**Widget capability**: This API can be used in ArkTS widgets since API version 9.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description|
| ------ | ------ | ---- | ---------------------------------------- |
| offset | number | Yes | Relative position of the gradient stop along the gradient vector, represented by the ratio of the distance between the gradient stop and the start point to the total length. The value ranges from 0 to 1.<br>If the value of **offset** is less than 0 or greater than 1, there is no gradient effect.            |
| color  | string | Yes | Gradient color to set. For details about the color notation, see the description of the string type in [ResourceColor](ts-types.md#resourcecolor).<br>Invalid values result in no gradient effect being displayed.|


## Example

This example shows how to add a color stop using **addColorStop**.

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct AddColorStop {
    private settings: RenderingContextSettings = new RenderingContextSettings(true)
    private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings)

    build() {
      Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
        Canvas(this.context)
          .width('100%')
          .height('100%')
          .backgroundColor('#ffff00')
          .onReady(() => {
            let grad = this.context.createLinearGradient(50, 0, 300, 100)
            grad.addColorStop(0.0, '#ff0000')
            grad.addColorStop(0.5, '#ffffff')
            grad.addColorStop(1.0, '#00ff00')
            this.context.fillStyle = grad
            this.context.fillRect(0, 0, 400, 400)
          })
      }
      .width('100%')
      .height('100%')
    }
  }
  ```
  ![en-us_image_0000001194032516](figures/en-us_image_0000001194032516.jpeg)

 
