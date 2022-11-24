# Explicit Animation

You can create explicit animation with your custom settings.

>  **NOTE**
>
>  The APIs of this module are supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


| API                                                          | Description                                                  |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| animateTo(value: [AnimationOptions](#animationoptions), event: ()=&gt; void) : void | Provides a transition animation when the status changes due to the closure code.<br>**event** specifies the closure function that displays the dynamic effect. The system automatically inserts the transition animation if the status changes in the closure function. |


## AnimationOptions

| Name| Type| Description|
| -------- | -------- | -------- |
| duration | number | Animation duration, in ms.<br>Default value: **1000**|
| tempo | number | Animation playback speed. A larger value indicates faster animation playback, and a smaller value indicates slower animation playback. The value **0** means that there is no animation.<br>Default value: **1.0**|
| curve | Curve \| Curves | Animation curve.<br>Default value: **Curve.Linear**|
| delay | number | Delay of animation playback, in ms. By default, the playback is not delayed.<br>Default value: **0**|
| iterations | number | Number of times that the animation is played. By default, the animation is played once. The value **-1** indicates that the animation is played for an unlimited number of times.<br>Default value: **1**|
| playMode | [PlayMode](ts-appendix-enums.md#playmode) | Animation playback mode. By default, the animation is played from the beginning after the playback is complete.<br>Default value: **PlayMode.Normal**|
| onFinish   | () =&gt; void   | Callback invoked when the animation playback is complete.|



## Example

```ts
// xxx.ets
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
          // Animation configuration for the width and height attributes of the <Button> component
          if (this.flag) {
            animateTo({
              duration: 1000, // Animation duration
              tempo: 0.5, // Playback speed
              curve: Curve.EaseInOut, // Animation curve
              delay: 200, // Animation delay
              iterations: 1, // Number of playback times
              playMode: PlayMode.Normal // Animation playback mode
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
              curve: Curve.Ease, // Animated curve
              delay: 200, // Animation delay
              iterations: 1, // Number of playback times
              playMode: PlayMode.Normal // Animation playback mode
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
