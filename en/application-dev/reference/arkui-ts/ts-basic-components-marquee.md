# Marquee

The **\<Marquee>** component is used to display a scrolling piece of text. The text is scrolled only when its width exceeds the width of the **\<Marquee>** component.


>  **NOTE**
>
>  This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.


## Child Components

Not supported


## APIs

Marquee(value: { start: boolean, step?: number, loop?: number, fromStart?: boolean, src: string })

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| start | boolean | Yes| Whether to start scrolling.|
| step | number | No| Scrolling step.<br>Default value: **6**, in vp|
| loop | number | No| Number of times the marquee will scroll. If the value is less than or equal to **0**, the marquee will scroll continuously.<br>Default value: **-1**|
| fromStart | boolean | No| Whether the text scrolls from the start.<br>Default value: **true**|
| src | string | Yes| Text to scroll.|

## Attributes

| Name      | Type| Description                                |
| ---------- | -------- | ------------------------------------ |
| allowScale | boolean  | Whether to allow text to scale.<br>Default value: **false**|

## Events

| Name| Description|
| -------- | -------- |
| onStart(event: () =&gt; void) | Triggered when the marquee starts scrolling.|
| onBounce(event: () =&gt; void) | Triggered when the marquee has reached the end. This event will be triggered for multiple times if the **loop** attribute is not set to **1**.|
| onFinish(event: () =&gt; void) | Triggered when the marquee has finished the number of scrolling times set by the **loop** attribute.|


## Example


```ts
// xxx.ets
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
        .width(400)
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
