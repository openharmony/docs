# ImageAnimator


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE：**
> This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


The **&lt;ImageAnimator&gt;** component enables images to be played frame by frame. The list of images to be played can be configured, and the duration of each image can be configured.


## Required Permissions

None


## Child Components

None


## APIs

ImageAnimator()


## Attributes

| Name | Type | Default&nbsp;Value | Mandatory | Description |
| -------- | -------- | -------- | -------- | -------- |
| images | Array&lt;{<br/>src:string,<br/>width?:Length,<br/>height?:Length,<br/>top?:Length,<br/>left?:Length,<br/>duration?:number<br/>}&gt; | [] | Yes | Image&nbsp;frame&nbsp;information.&nbsp;The&nbsp;information&nbsp;of&nbsp;each&nbsp;frame&nbsp;includes&nbsp;the&nbsp;image&nbsp;path,&nbsp;image&nbsp;size,&nbsp;image&nbsp;position,&nbsp;and&nbsp;image&nbsp;playback&nbsp;duration.&nbsp;The&nbsp;detailed&nbsp;description&nbsp;is&nbsp;as&nbsp;follows:<br/>**src**:&nbsp;image&nbsp;path.&nbsp;The&nbsp;image&nbsp;format&nbsp;can&nbsp;be&nbsp;SVG,&nbsp;PNG,&nbsp;or&nbsp;JPG.<br/>**width**:&nbsp;image&nbsp;width.<br/>**height**:&nbsp;image&nbsp;height.<br/>**top**:&nbsp;vertical&nbsp;coordinate&nbsp;of&nbsp;the&nbsp;image&nbsp;relative&nbsp;to&nbsp;the&nbsp;upper&nbsp;left&nbsp;corner&nbsp;of&nbsp;the&nbsp;component.<br/>**left**:&nbsp;horizontal&nbsp;coordinate&nbsp;of&nbsp;the&nbsp;image&nbsp;relative&nbsp;to&nbsp;the&nbsp;upper&nbsp;left&nbsp;corner&nbsp;of&nbsp;the&nbsp;component.<br/>**duration**:&nbsp;playback&nbsp;duration&nbsp;of&nbsp;the&nbsp;image,&nbsp;in&nbsp;ms. |
| state | AnimationStatus | AnimationStatus.Initial | No | Playback&nbsp;status&nbsp;of&nbsp;the&nbsp;animation.&nbsp;The&nbsp;default&nbsp;status&nbsp;is&nbsp;**Initial**. |
| duration | number | 1000 | No | Playback&nbsp;duration,&nbsp;in&nbsp;ms.&nbsp;The&nbsp;default&nbsp;duration&nbsp;is&nbsp;1000&nbsp;ms.&nbsp;When&nbsp;the&nbsp;duration&nbsp;is&nbsp;**0**,&nbsp;no&nbsp;image&nbsp;is&nbsp;played.&nbsp;The&nbsp;value&nbsp;change&nbsp;takes&nbsp;effect&nbsp;only&nbsp;at&nbsp;the&nbsp;beginning&nbsp;of&nbsp;the&nbsp;next&nbsp;cycle.&nbsp;When&nbsp;a&nbsp;separate&nbsp;duration&nbsp;is&nbsp;set&nbsp;in&nbsp;images,&nbsp;the&nbsp;setting&nbsp;of&nbsp;this&nbsp;attribute&nbsp;is&nbsp;invalid. |
| reverse | boolean | false | No | Playback&nbsp;sequence.&nbsp;The&nbsp;value&nbsp;**false**&nbsp;indicates&nbsp;that&nbsp;images&nbsp;are&nbsp;played&nbsp;from&nbsp;the&nbsp;first&nbsp;one&nbsp;to&nbsp;the&nbsp;last&nbsp;one,&nbsp;and&nbsp;**true**&nbsp;indicates&nbsp;that&nbsp;images&nbsp;are&nbsp;played&nbsp;from&nbsp;the&nbsp;last&nbsp;one&nbsp;to&nbsp;the&nbsp;first&nbsp;one. |
| fixedSize | boolean | true | No | Whether&nbsp;the&nbsp;image&nbsp;size&nbsp;is&nbsp;the&nbsp;same&nbsp;as&nbsp;the&nbsp;component&nbsp;size.&nbsp;**true**:&nbsp;The&nbsp;image&nbsp;size&nbsp;is&nbsp;the&nbsp;same&nbsp;as&nbsp;the&nbsp;component&nbsp;size.&nbsp;In&nbsp;this&nbsp;case,&nbsp;the&nbsp;width,&nbsp;height,&nbsp;top,&nbsp;and&nbsp;left&nbsp;attributes&nbsp;of&nbsp;the&nbsp;image&nbsp;are&nbsp;invalid.&nbsp;**false**:&nbsp;The&nbsp;width,&nbsp;height,&nbsp;top,&nbsp;and&nbsp;left&nbsp;attributes&nbsp;of&nbsp;each&nbsp;image&nbsp;must&nbsp;be&nbsp;set&nbsp;separately. |
| preDecode | number | 0 | No | Whether&nbsp;to&nbsp;enable&nbsp;pre-decoding.&nbsp;The&nbsp;default&nbsp;value&nbsp;**0**&nbsp;indicates&nbsp;that&nbsp;pre-decoding&nbsp;is&nbsp;disabled.&nbsp;If&nbsp;this&nbsp;attribute&nbsp;is&nbsp;set&nbsp;to&nbsp;**2**,&nbsp;two&nbsp;images&nbsp;following&nbsp;the&nbsp;currently&nbsp;playing&nbsp;frame&nbsp;will&nbsp;be&nbsp;cached&nbsp;in&nbsp;advance&nbsp;to&nbsp;improve&nbsp;performance. |
| fillMode | FillMode | FillMode.Forwards | No | Status&nbsp;before&nbsp;and&nbsp;after&nbsp;the&nbsp;animation&nbsp;starts.&nbsp;For&nbsp;details&nbsp;about&nbsp;the&nbsp;options,&nbsp;see&nbsp;**FillMode**. |
| iterations | number | 1 | No | By&nbsp;default,&nbsp;the&nbsp;animation&nbsp;is&nbsp;played&nbsp;once.&nbsp;The&nbsp;value&nbsp;**-1**&nbsp;indicates&nbsp;that&nbsp;the&nbsp;animation&nbsp;is&nbsp;played&nbsp;for&nbsp;an&nbsp;unlimited&nbsp;number&nbsp;of&nbsp;times. |

- AnimationStatus enums
    | Name | Description | 
  | -------- | -------- |
  | Initial | The&nbsp;animation&nbsp;is&nbsp;in&nbsp;the&nbsp;initial&nbsp;state. | 
  | Running | The&nbsp;animation&nbsp;is&nbsp;being&nbsp;played. | 
  | Paused | The&nbsp;animation&nbsp;is&nbsp;paused. | 
  | Stopped | The&nbsp;animation&nbsp;is&nbsp;stopped. | 

- FillMode enums
    | Name | Description | 
  | -------- | -------- |
  | None | After&nbsp;the&nbsp;playback&nbsp;is&nbsp;complete,&nbsp;the&nbsp;animation&nbsp;restores&nbsp;to&nbsp;the&nbsp;initial&nbsp;state. | 
  | Forwards | After&nbsp;the&nbsp;playback&nbsp;is&nbsp;complete,&nbsp;the&nbsp;animation&nbsp;remains&nbsp;in&nbsp;the&nbsp;end&nbsp;state. | 


## Events

  | Name | Description | 
| -------- | -------- | -------- |
| onStart()&nbsp;=&gt;&nbsp;void | Triggered&nbsp;when&nbsp;the&nbsp;animation&nbsp;starts&nbsp;to&nbsp;play. | 
| onPause()&nbsp;=&gt;&nbsp;void | Triggered&nbsp;when&nbsp;the&nbsp;animation&nbsp;playback&nbsp;is&nbsp;paused. | 
| onRepeat()&nbsp;=&gt;&nbsp;void | Triggered&nbsp;when&nbsp;the&nbsp;animation&nbsp;playback&nbsp;is&nbsp;repeated. | 
| onCancel()&nbsp;=&gt;&nbsp;void | Triggered&nbsp;when&nbsp;the&nbsp;animation&nbsp;playback&nbsp;is&nbsp;canceled. | 
| onFinish()&nbsp;=&gt;&nbsp;void | Triggered&nbsp;when&nbsp;the&nbsp;animation&nbsp;playback&nbsp;is&nbsp;complete. | 


## Example


```
@Entry
@Component
struct ImageAnimatorExample {
  @State state: AnimationStatus = AnimationStatus.Initial
  @State reverse: boolean = false
  @State iterations: number = 1

  build() {
    Column({ space:5 }) {
      ImageAnimator()
        .images([
          {
            src: '/comment/bg1.jpg',
            duration: 500,
            width: 325,
            height: 200,
            top: 0,
            left: 0
          },
          {
            src: '/comment/bg2.jpg',
            duration: 500,
            width: 325,
            height: 200,
            top: 0,
            left: 0
          },
          {
            src: '/comment/bg3.jpg',
            duration: 500,
            width: 325,
            height: 200,
            top: 0,
            left: 0
          },
          {
            src: '/comment/bg4.jpg',
            duration: 500,
            width: 325,
            height: 200,
            top: 0,
            left: 0
          }
        ])
        .state(this.state).reverse(this.reverse).fixedSize(false).preDecode(2)
        .fillMode(FillMode.None).iterations(this.iterations).width(325).height(210)
        .margin({top:100})
        .onStart(() => { // Triggered when the frame animation playback starts.
          console.info('Start')
        })
        .onPause(() => {
          console.info('Pause')
        })
        .onRepeat(() => {
          console.info('Repeat')
        })
        .onCancel(() => {
          console.info('Cancel')
        })
        .onFinish(() => { // Triggered after the frame animation playback is complete.
          console.info('Finish')
        })
      Row() {
        Button('start').width(100).padding(5).onClick(() => {
          this.state = AnimationStatus.Running
        })
        Button('pause').width(100).padding(5).onClick(() => {
          this.state = AnimationStatus.Paused
        })
        Button('stop').width(100).padding(5).onClick(() => {
          this.state = AnimationStatus.Stopped
        })
      }
      Row() {
        Button('reverse').width(100).padding(5).onClick(() => {
          this.reverse = !this.reverse
        })
        Button('once').width(100).padding(5).onClick(() => {
          this.iterations = 1
        })
        Button('iteration').width(100).padding(5).onClick(() => {
          this.iterations = -1
        })
      }
    }.width('100%').height('100%').backgroundColor(0xF1F3F5)
  }
}
```

![en-us_image_0000001211898470](figures/en-us_image_0000001211898470.gif)
