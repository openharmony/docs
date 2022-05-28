# AnimatorProperty


> **NOTE**<br>
> This animation is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


When the universal attributes of a component change, you can create an **AnimatorProperty** for gradient to improve user experience.


| Name | Type | Default Value | Description |
| -------- | -------- | -------- | -------- |
| duration | number | 1000 | Animation duration, in ms. The default duration is 1000 ms. |
| curve | Curve | Curve.Linear | Animation curve. The default curve is linear. |
| delay | number | 0 | Delay of animation playback, in ms. By default, the playback is not delayed. |
| iterations | number | 1 | Number of times that the animation is played. By default, the animation is played once. The value **-1** indicates that the animation is played for an unlimited number of times. |
| playMode | [PlayMode](ts-appendix-enums.md#playmode-enums) | PlayMode.Normal | Playback mode. By default, the animation is played from the beginning after the playback is complete. |


- Curve enums
    | Name | Description | 
  | -------- | -------- |
  | Linear | The animation speed keeps unchanged. | 
  | Ease | The animation starts at a low speed and then accelerates. It slows down before the animation ends. The cubic-bezier curve (0.25, 0.1, 0.25, 1.0) is used. | 
  | EaseIn | The animation starts at a low speed. The cubic-bezier curve (0.42, 0.0, 1.0, 1.0) is used. | 
  | EaseOut | The animation ends at a low speed. The cubic-bezier curve (0.0, 0.0, 0.58, 1.0) is used. | 
  | EaseInOut | The animation starts and ends at a low speed. The cubic-bezier curve (0.42, 0.0, 0.58, 1.0) is used. | 
  | FastOutSlowIn | The animation uses the standard cubic-bezier curve (0.4, 0.0, 0.2, 1.0). | 
  | LinearOutSlowIn | The animation uses the deceleration cubic-bezier curve (0.0, 0.0, 0.2, 1.0). | 
  | FastOutLinearIn | The animation uses the acceleration cubic-bezier curve (0.4, 0.0, 1.0, 1.0). | 
  | ExtremeDeceleration | The animation uses the extreme deceleration cubic-bezier curve (0.0, 0.0, 0.0, 1.0). | 
  | Sharp | The animation uses the sharp cubic-bezier curve (0.33, 0.0, 0.67, 1.0). | 
  | Rhythm | The animation uses the rhythm cubic-bezier curve (0.7, 0.0, 0.2, 1.0). | 
  | Smooth | The animation uses the smooth cubic-bezier curve (0.4, 0.0, 0.4, 1.0). | 
  | Friction | Damping curve. The cubic-bezier curve (0.2, 0.0, 0.2, 1.0) is used. | 


## Example


```
@Entry
@Component
struct AttrAnimationExample {
  @State widthSize: number = 200
  @State heightSize: number = 100
  @State flag: boolean = true

  build() {
    Column() {
      Button('click me')
        .onClick((event: ClickEvent) => {
          if (this.flag) {
            this.widthSize = 100
            this.heightSize = 50
          } else {
            this.widthSize = 200
            this.heightSize = 100
          }
          this.flag = !this.flag
        })
        .width(this.widthSize).height(this.heightSize).backgroundColor(0x317aff)
        .animation({
          duration: 2000, // Animation duration
          curve: Curve.EaseOut, // Animation curve
          delay: 500, // Animation delay
          iterations: 1, // Number of playback times
          playMode: PlayMode.Normal // Animation mode
        }) // Animation configuration for the width and height attributes of the Button component
    }.width('100%').margin({ top: 5 })
  }
}
```

![en-us_image_0000001212378444](figures/en-us_image_0000001212378444.gif)
