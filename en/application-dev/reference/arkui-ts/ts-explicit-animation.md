# Explicit Animation


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE：**
> This animation is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.

  | Name | Description | 
| -------- | -------- |
| animateTo(value:&nbsp;[AnimationOption](#animationoption-object),&nbsp;event:&nbsp;()=&gt;&nbsp;void)&nbsp;:&nbsp;void | Provides&nbsp;a&nbsp;transition&nbsp;animation&nbsp;when&nbsp;the&nbsp;status&nbsp;changes&nbsp;due&nbsp;to&nbsp;the&nbsp;closure&nbsp;code.<br/>**event**&nbsp;specifies&nbsp;the&nbsp;closure&nbsp;function&nbsp;that&nbsp;displays&nbsp;the&nbsp;dynamic&nbsp;effect.&nbsp;The&nbsp;system&nbsp;automatically&nbsp;inserts&nbsp;the&nbsp;transition&nbsp;animation&nbsp;if&nbsp;the&nbsp;status&nbsp;changes&nbsp;in&nbsp;the&nbsp;closure&nbsp;function. | 


## AnimationOption Object

- Attributes
    | Name | Type | Default&nbsp;Value | Description | 
  | -------- | -------- | -------- | -------- |
  | duration | number | 1000 | Animation&nbsp;duration,&nbsp;in&nbsp;ms. | 
  | tempo | number | 1.0 | Animation&nbsp;playback&nbsp;speed.&nbsp;A&nbsp;larger&nbsp;value&nbsp;indicates&nbsp;faster&nbsp;animation&nbsp;playback,&nbsp;and&nbsp;a&nbsp;smaller&nbsp;value&nbsp;indicates&nbsp;slower&nbsp;animation&nbsp;playback.&nbsp;The&nbsp;value&nbsp;**0**&nbsp;means&nbsp;that&nbsp;there&nbsp;is&nbsp;no&nbsp;animation. | 
  | curve | Curve&nbsp;\|&nbsp;Curves | Linear | Animation&nbsp;curve. | 
  | delay | number | 0 | Delay&nbsp;of&nbsp;animation&nbsp;playback,&nbsp;in&nbsp;ms.&nbsp;By&nbsp;default,&nbsp;the&nbsp;playback&nbsp;is&nbsp;not&nbsp;delayed. | 
  | iterations | number | 1 | Number&nbsp;of&nbsp;times&nbsp;that&nbsp;the&nbsp;animation&nbsp;is&nbsp;played.&nbsp;By&nbsp;default,&nbsp;the&nbsp;animation&nbsp;is&nbsp;played&nbsp;once.&nbsp;The&nbsp;value&nbsp;**-1**&nbsp;indicates&nbsp;that&nbsp;the&nbsp;animation&nbsp;is&nbsp;played&nbsp;for&nbsp;an&nbsp;unlimited&nbsp;number&nbsp;of&nbsp;times. | 
  | playMode | PlayMode | Normal | Animation&nbsp;playback&nbsp;mode.&nbsp;By&nbsp;default,&nbsp;the&nbsp;animation&nbsp;is&nbsp;played&nbsp;from&nbsp;the&nbsp;beginning&nbsp;after&nbsp;the&nbsp;playback&nbsp;is&nbsp;complete. | 


- APIs
    | Name | Description | 
  | -------- | -------- |
  | onFinish()&nbsp;=&gt;&nbsp;void | Callback&nbsp;invoked&nbsp;when&nbsp;the&nbsp;animation&nbsp;playback&nbsp;is&nbsp;complete. | 


## Example


```
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
