# AnimatorProperty


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE：**
> This animation is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


When the universal attributes of a component change, you can create an **AnimatorProperty** for gradient to improve user experience.


| Name | Type | Default&nbsp;Value | Description |
| -------- | -------- | -------- | -------- |
| duration | number | 1000 | Animation&nbsp;duration,&nbsp;in&nbsp;ms.&nbsp;The&nbsp;default&nbsp;duration&nbsp;is&nbsp;1000&nbsp;ms. |
| curve | Curve | Curve.Linear | Animation&nbsp;curve.&nbsp;The&nbsp;default&nbsp;curve&nbsp;is&nbsp;linear. |
| delay | number | 0 | Delay&nbsp;of&nbsp;animation&nbsp;playback,&nbsp;in&nbsp;ms.&nbsp;By&nbsp;default,&nbsp;the&nbsp;playback&nbsp;is&nbsp;not&nbsp;delayed. |
| iterations | number | 1 | Number&nbsp;of&nbsp;times&nbsp;that&nbsp;the&nbsp;animation&nbsp;is&nbsp;played.&nbsp;By&nbsp;default,&nbsp;the&nbsp;animation&nbsp;is&nbsp;played&nbsp;once.&nbsp;The&nbsp;value&nbsp;**-1**&nbsp;indicates&nbsp;that&nbsp;the&nbsp;animation&nbsp;is&nbsp;played&nbsp;for&nbsp;an&nbsp;unlimited&nbsp;number&nbsp;of&nbsp;times. |
| playMode | [PlayMode](ts-appendix-enums.md#playmode-enums) | PlayMode.Normal | Playback&nbsp;mode.&nbsp;By&nbsp;default,&nbsp;the&nbsp;animation&nbsp;is&nbsp;played&nbsp;from&nbsp;the&nbsp;beginning&nbsp;after&nbsp;the&nbsp;playback&nbsp;is&nbsp;complete. |


- Curve enums
    | Name | Description | 
  | -------- | -------- |
  | Linear | The&nbsp;animation&nbsp;speed&nbsp;keeps&nbsp;unchanged. | 
  | Ease | The&nbsp;animation&nbsp;starts&nbsp;at&nbsp;a&nbsp;low&nbsp;speed&nbsp;and&nbsp;then&nbsp;accelerates.&nbsp;It&nbsp;slows&nbsp;down&nbsp;before&nbsp;the&nbsp;animation&nbsp;ends.&nbsp;The&nbsp;cubic-bezier&nbsp;curve&nbsp;(0.25,&nbsp;0.1,&nbsp;0.25,&nbsp;1.0)&nbsp;is&nbsp;used. | 
  | EaseIn | The&nbsp;animation&nbsp;starts&nbsp;at&nbsp;a&nbsp;low&nbsp;speed.&nbsp;The&nbsp;cubic-bezier&nbsp;curve&nbsp;(0.42,&nbsp;0.0,&nbsp;1.0,&nbsp;1.0)&nbsp;is&nbsp;used. | 
  | EaseOut | The&nbsp;animation&nbsp;ends&nbsp;at&nbsp;a&nbsp;low&nbsp;speed.&nbsp;The&nbsp;cubic-bezier&nbsp;curve&nbsp;(0.0,&nbsp;0.0,&nbsp;0.58,&nbsp;1.0)&nbsp;is&nbsp;used. | 
  | EaseInOut | The&nbsp;animation&nbsp;starts&nbsp;and&nbsp;ends&nbsp;at&nbsp;a&nbsp;low&nbsp;speed.&nbsp;The&nbsp;cubic-bezier&nbsp;curve&nbsp;(0.42,&nbsp;0.0,&nbsp;0.58,&nbsp;1.0)&nbsp;is&nbsp;used. | 
  | FastOutSlowIn | The&nbsp;animation&nbsp;uses&nbsp;the&nbsp;standard&nbsp;cubic-bezier&nbsp;curve&nbsp;(0.4,&nbsp;0.0,&nbsp;0.2,&nbsp;1.0). | 
  | LinearOutSlowIn | The&nbsp;animation&nbsp;uses&nbsp;the&nbsp;deceleration&nbsp;cubic-bezier&nbsp;curve&nbsp;(0.0,&nbsp;0.0,&nbsp;0.2,&nbsp;1.0). | 
  | FastOutLinearIn | The&nbsp;animation&nbsp;uses&nbsp;the&nbsp;acceleration&nbsp;cubic-bezier&nbsp;curve&nbsp;(0.4,&nbsp;0.0,&nbsp;1.0,&nbsp;1.0). | 
  | ExtremeDeceleration | The&nbsp;animation&nbsp;uses&nbsp;the&nbsp;extreme&nbsp;deceleration&nbsp;cubic-bezier&nbsp;curve&nbsp;(0.0,&nbsp;0.0,&nbsp;0.0,&nbsp;1.0). | 
  | Sharp | The&nbsp;animation&nbsp;uses&nbsp;the&nbsp;sharp&nbsp;cubic-bezier&nbsp;curve&nbsp;(0.33,&nbsp;0.0,&nbsp;0.67,&nbsp;1.0). | 
  | Rhythm | The&nbsp;animation&nbsp;uses&nbsp;the&nbsp;rhythm&nbsp;cubic-bezier&nbsp;curve&nbsp;(0.7,&nbsp;0.0,&nbsp;0.2,&nbsp;1.0). | 
  | Smooth | The&nbsp;animation&nbsp;uses&nbsp;the&nbsp;smooth&nbsp;cubic-bezier&nbsp;curve&nbsp;(0.4,&nbsp;0.0,&nbsp;0.4,&nbsp;1.0). | 
  | Friction | Damping&nbsp;curve.&nbsp;The&nbsp;cubic-bezier&nbsp;curve&nbsp;(0.2,&nbsp;0.0,&nbsp;0.2,&nbsp;1.0)&nbsp;is&nbsp;used. | 


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
