# Immediate Delivery of Explicit Animation (animateToImmediately)

The **animateToImmediately** API implements immediate delivery for [explicit animations](ts-explicit-animation.md). When multiple property animations are loaded at once, you can call this API to immediately execute the transition animation for state changes caused by the specified closure function.

Unlike [animateTo](../js-apis-arkui-UIContext.md#animateto), which waits for the VSync signal, **animateToImmediately** instantly sends animation commands to the rendering layer for execution. This is particularly useful in scenarios where you need to prioritize certain animations or update part of the UI in advance, especially when your application's main thread is occupied with time-consuming operations. However, it is important to note that **animateToImmediately** is limited to property animations on the rendering layer and does not affect frame-by-frame animations on the UI side.

In addition, **animateToImmediately** captures the current state at the time of the call and sends it alongside the animation to the rendering layer. This means that the rendering output will reflect the state at the time of the call. Therefore, before calling this API, ensure that the current state is complete and correctly configured, to prevent rendering issues due to incorrect initial frames.

In general cases, using **animateToImmediately** is not advised. Opt for [animateTo](../js-apis-arkui-UIContext.md#animateto) to avoid disrupting the display timing of the framework and to prevent potential display issues caused by incomplete state settings at the start of the animation.

> **NOTE**
>
> This feature is supported since API version 12. Updates will be marked with a superscript to indicate their earliest API version.
>

## APIs

## animateToImmediately

animateToImmediately(value: AnimateParam , event: () => void): void

Delivers an explicit animation immediately.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                                        | Mandatory| Description                                                        |
| ------ | ------------------------------------------------------------ | -------- | ------------------------------------------------------------ |
| value  | [AnimateParam](ts-explicit-animation.md#animateparam) | Yes      | Animation settings.                                      |
| event  | () => void                                                   | Yes      | Closure function that displays the animation. The system automatically inserts a transition animation for state changes caused by the closure function.|

## Example

This example demonstrates how to use the **animateToImmediately** API to deliver an explicit animation immediately.

```ts
// xxx.ets
@Entry
@Component
struct AnimateToImmediatelyExample {
  @State widthSize: number = 250
  @State heightSize: number = 100
  @State opacitySize: number = 0
  private flag: boolean = true

  build() {
    Column() {
      Column()
      .width(this.widthSize)
      .height(this.heightSize)
      .backgroundColor(Color.Green)
      .opacity(this.opacitySize)
      Button('change size')
        .margin(30)
        .onClick(() => {
          if (this.flag) {
            animateToImmediately({
              delay: 0,
              duration: 1000
            }, () => {
              this.opacitySize = 1
            })
            animateTo({
              delay: 1000,
              duration: 1000
            }, () => {
              this.widthSize = 150
              this.heightSize = 60
            })
          } else {
            animateToImmediately({
              delay: 0,
              duration: 1000
            }, () => {
              this.widthSize = 250
              this.heightSize = 100
            })
            animateTo({
              delay: 1000,
              duration: 1000
            }, () => {
              this.opacitySize = 0
            })
          }
          this.flag = !this.flag
        })
    }.width('100%').margin({ top: 5 })
  }
}
```

![animation1](figures/animateToImmediately1.gif)
