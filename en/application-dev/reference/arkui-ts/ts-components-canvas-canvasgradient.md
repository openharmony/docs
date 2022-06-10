# CanvasGradient


> **NOTE**
> This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.


**CanvasGradient** provides a canvas gradient object.


## addColorStop

addColorStop(offset: number, color: string): void

Adds a color stop for the **CanvasGradient** object based on the specified offset and gradient color.

- Parameters
  | Name | Type | Mandatory | Default Value | Description |
  | -------- | -------- | -------- | -------- | -------- |
  | offset | number | Yes | 0 | Proportion of the distance between the color stop and the start point to the total length. The value ranges from 0 to 1. |
  | color | string | Yes | 'ffffff' | Gradient color to set. |

- Example
    
  ```
  @Entry
  @Component
  struct Page45 {
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

  ![en-us_image_0000001256858381](figures/en-us_image_0000001256858381.png)
