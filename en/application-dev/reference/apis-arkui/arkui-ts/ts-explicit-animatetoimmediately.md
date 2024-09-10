# Immediate Delivery of Explicit Animation (animateToImmediately)

The **animateToImmediately** API implements immediate delivery for [explicit animations](ts-explicit-animation.md). When multiple property animations are loaded at once, you can call this API to immediately execute the transition animation for state changes caused by the specified closure function.

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
