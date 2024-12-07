# Requesting Frame Rates for Animations

During application development, you can use the optional parameter [ExpectedFrameRateRange](../reference/apis-arkui/arkui-ts/ts-explicit-animation.md#expectedframeraterange11) to set an expected frame rate range for a [property animation](../reference/apis-arkui/arkui-ts/ts-animatorproperty.md) or an [explicit animation](../reference/apis-arkui/arkui-ts/ts-explicit-animation.md).

## Requesting a Frame Rate for a Property Animation
The code snippet below defines a property animation for the **Text** component and sets the frame rate to 60.

   ```ts
    Text()
     .animation({
        duration: 1200,
        iterations: 10,
        expectedFrameRateRange: { // Set the frame rate range of the property animation.
          expected: 60, // Set the expected frame rate of the animation to 60 Hz.
          min: 0, // Set the frame rate range.
          max: 120, // Set the frame rate range.
        },
     })
   ```

## Requesting a Frame Rate for an Explicit Animation
The code snippet below defines an explicit animation for the **Button** component and sets the frame rate to 30.

   ```ts
   Button()
    .onClick(() => {
      animateTo({
        duration: 1200,
        iterations: 10,
        expectedFrameRateRange: { // Set the frame rate range of the explicit animation.
          expected: 30, // Set the expected frame rate of the animation to 30 Hz.
          min: 0, // Set the frame rate range.
          max: 120, // Set the frame rate range.
        },
      }, () => {
      })
    })
   ```


## Sample Code

```ts
@Entry
@Component
struct AnimationToAnimationDemo {
  @State isAnimation: boolean = false;
  @State translateX1: number = -100;
  @State translateX2: number = -100;
  @State translateX3: number = -100;

  build() {
    Column() {
      Row() {
        Text('30')
          .fontWeight(FontWeight.Bold)
          .fontSize(16)
          .fontColor(Color.White)
          .textAlign(TextAlign.Center)
          .borderRadius(10)
          .backgroundColor(0xF56C6C)
          .width(80)
          .height(80)
          .translate({ x: this.translateX1 })
      }
      .height('20%')

      Row() {
        Text('40')
          .fontWeight(FontWeight.Bold)
          .fontSize(16)
          .fontColor(Color.White)
          .textAlign(TextAlign.Center)
          .borderRadius(10)
          .backgroundColor(0x2E8B57)
          .width(80)
          .height(80)
          .translate({ x: this.translateX2 })
      }
      .height('20%')

      Row() {
        Text('60')
          .fontWeight(FontWeight.Bold)
          .fontSize(16)
          .fontColor(Color.White)
          .textAlign(TextAlign.Center)
          .borderRadius(10)
          .backgroundColor(0x008B8B)
          .width(80)
          .height(80)
          .translate({ x: this.translateX3 })
          .animation({
            duration: 1200,
            iterations: 10,
            playMode: PlayMode.AlternateReverse,
            expectedFrameRateRange: { // Set the frame rate range of the property animation.
              expected: 60, // Set the expected frame rate of the animation to 60 Hz.
              min: 0, // Set the frame rate range.
              max: 120, // Set the frame rate range.
            },
          })
      }
      .height('20%')

      Row() {
        Button('Start')
          .id('PropertyAnimationStart')
          .fontSize(14)
          .fontWeight(500)
          .margin({ bottom: 10, left: 5 })
          .fontColor(Color.White)
          .onClick(() => {
            this.isAnimation = !this.isAnimation;
            this.translateX3 = this.isAnimation ? 100 : -100;

            animateTo({
              duration: 1200,
              iterations: 10,
              playMode: PlayMode.AlternateReverse,
              expectedFrameRateRange: { // Set the frame rate range of the explicit animation.
                expected: 30, // Set the expected frame rate of the animation to 30 Hz.
                min: 0, // Set the frame rate range.
                max: 120, // Set the frame rate range.
              },
            }, () => {
              this.translateX1 = this.isAnimation ? 100 : -100;
            })

            animateTo({
              duration: 1200,
              iterations: 10,
              playMode: PlayMode.AlternateReverse,
              expectedFrameRateRange: { // Set the frame rate range of the explicit animation.
                expected: 40, // Set the expected frame rate of the animation to 40 Hz.
                min: 0, // Set the frame rate range.
                max: 120, // Set the frame rate range.
              },
            }, () => {
              this.translateX2 = this.isAnimation ? 100 : -100;
            })
          })
          .width('40%')
          .height(40)
          .shadow(ShadowStyle.OUTER_DEFAULT_LG)
      }
      .width('100%')
      .justifyContent(FlexAlign.Center)
      .shadow(ShadowStyle.OUTER_DEFAULT_SM)
      .alignItems(VerticalAlign.Bottom)
      .layoutWeight(1)
    }
    .width('100%')
    .justifyContent(FlexAlign.Center)
    .shadow(ShadowStyle.OUTER_DEFAULT_SM)
    .layoutWeight(1)
  }
}
```
