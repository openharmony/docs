# Explicit Animation


> **NOTE**<br>
> This animation is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.

| Name | Description |
| -------- | -------- |
| animateTo(value: [AnimationOptions](#animationoptions), event: ()=&gt; void) : void | Provides a transition animation when the status changes due to the closure code.<br/>**event** specifies the closure function that displays the dynamic effect. The system automatically inserts the transition animation if the status changes in the closure function. |


## AnimationOptions

- Attributes
  | Name | Type | Default Value | Description |
  | -------- | -------- | -------- | -------- |
  | duration | number | 1000 | Animation duration, in ms. |
  | tempo | number | 1.0 | Animation playback speed. A larger value indicates faster animation playback, and a smaller value indicates slower animation playback. The value **0** means that there is no animation. |
  | curve | Curve \| Curves | Linear | Animation curve. |
  | delay | number | 0 | Delay of animation playback, in ms. By default, the playback is not delayed. |
  | iterations | number | 1 | Number of times that the animation is played. By default, the animation is played once. The value **-1** indicates that the animation is played for an unlimited number of times. |
  | playMode | PlayMode | Normal | Animation playback mode. By default, the animation is played from the beginning after the playback is complete. |


- APIs
  | Name                  | Description                                               |
  | --------------------- | --------------------------------------------------------- |
  | onFinish() =&gt; void | Callback invoked when the animation playback is complete. |


## Example


```ts
@Entry
@Component
struct AnimateToExample {
  @State widthSize: number = 200
  @State heightSize: number = 100
  private flag: boolean = true

  build() {
    Column() {
      Button('click me')
        .width(this.widthSize)
        .height(this.heightSize)
        .backgroundColor(0x317aff)
        .onClick((event: ClickEvent) => {
          // Animation configuration for the width and height attributes of the Button component
          if (this.flag) {
            animateTo({
            duration: 1000, // Animation duration
            tempo: 0.5, // Playback speed
            curve: Curve.EaseInOut, // Animation curve
            delay: 200, // Animation delay
          iterations: 1, // Number of playback times
            playMode: PlayMode.Normal, // Animation mode
              onFinish: () => {
                console.info('play end')
              }
            }, () => {
              this.widthSize = 100
              this.heightSize = 50
            })
          } else {
            animateTo({
            duration: 200, // Animation duration
            curve: Curve.Ease, // Animation curve
            delay: 200, // Animation delay
          iterations: 1, // Number of playback times
            playMode: PlayMode.Normal, // Animation mode
              onFinish: () => {
                console.info('play end')
              }
            }, () => {
              this.widthSize = 200
              this.heightSize = 100
            })
          }
          this.flag = !this.flag
        })
    }.width('100%').margin({ top: 5 })
  }
}
```

![en-us_image_0000001256978345](figures/en-us_image_0000001256978345.gif)