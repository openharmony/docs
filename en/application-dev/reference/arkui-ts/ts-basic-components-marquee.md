# Marquee


> **NOTE**<br>
> This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.


The **\<Marquee>** component is used to display a scrolling piece of text.


## Required Permissions

None


## Child Components

None


## APIs

Marquee(value: { start: boolean, step?: number, loop?: number, fromStart?: boolean, src: string })

- Parameters
  | Name | Type | Mandatory | Default Value | Description | 
  | -------- | -------- | -------- | -------- | -------- |
  | start | boolean | Yes | - | Whether to start scrolling. | 
  | step | number | No | 6 | Scrolling step. | 
  | loop | number | No | -1 | Number of times the marquee will scroll. If the value is less than or equal to **0**, the marquee will scroll continuously. | 
  | fromStart | boolean | No | true | Whether the text scrolls from the start. | 
  | src | string | Yes | - | Text to scroll. | 


## Events

| Name | Description | 
| -------- | -------- |
| onStart(callback:&nbsp;()&nbsp;=&gt;&nbsp;void) | Triggered when the marquee starts scrolling. | 
| onBounce(callback:&nbsp;()&nbsp;=&gt;&nbsp;void) | Triggered when the marquee has reached the end. | 
| onFinish(callback:&nbsp;()&nbsp;=&gt;&nbsp;void) | Triggered when the marquee has finished scrolling. | 


## Example


```
@Entry
@Component
struct MarqueeExample {
  @State start: boolean = false
  @State fromStart: boolean = true
  @State step: number = 50
  @State loop: number = 3
  @State src: string = "Running Marquee starts rolling"

  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
      Marquee({
        start: this.start,
        step: this.step,
        loop: this.loop,
        fromStart: this.fromStart,
        src: this.src
      })
        .fontColor(Color.White)
        .fontSize(50)
        .allowScale(false)
        .fontWeight(FontWeight.Bold)
        .backgroundColor(Color.Black)
        .margin({bottom:40})
        .onStart(() => {
          console.log('Marquee animation complete onStart')
        })
        .onBounce(() => {
          console.log('Marquee animation complete onBounce')
        })
        .onFinish(() => {
          console.log('Marquee animation complete onFinish')
        })
        Button('start')
          .onClick(() => {
            this.start = true
             })
          .width(200)
          .height(60)
          .margin({bottom:20})
    }
    .width('100%')
    .height('100%')
  }
}
```

![en-us_image_0000001193499234](figures/en-us_image_0000001193499234.gif)
