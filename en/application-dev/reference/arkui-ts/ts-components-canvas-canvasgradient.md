# CanvasGradient


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE：**
> This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.


**CanvasGradient** provides a gradient object.


## addColorStop

addColorStop(offset: number, color: string): void

Adds a color stop for the **CanvasGradient** object based on the specified offset and gradient color.

- Parameters
    | Name | Type | Mandatory | Default&nbsp;Value | Description | 
  | -------- | -------- | -------- | -------- | -------- |
  | offset | number | Yes | 0 | Proportion&nbsp;of&nbsp;the&nbsp;distance&nbsp;between&nbsp;the&nbsp;color&nbsp;stop&nbsp;and&nbsp;the&nbsp;start&nbsp;point&nbsp;to&nbsp;the&nbsp;total&nbsp;length.&nbsp;The&nbsp;value&nbsp;ranges&nbsp;from&nbsp;0&nbsp;to&nbsp;1. | 
  | color | string | Yes | 'ffffff' | Gradient&nbsp;color&nbsp;to&nbsp;set. | 

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
