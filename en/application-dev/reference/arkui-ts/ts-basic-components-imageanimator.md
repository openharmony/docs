# ImageAnimator

The **\<ImageAnimator>** component enables images to be played frame by frame. The list of images to be played can be configured, and the duration of each image can be configured.

>  **NOTE**
>
> This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.



## Child Components

Not supported


## APIs

ImageAnimator()


## Attributes

| Name    | Type                 | Mandatory     | Description                  |
| ---------- | ----------------------- | -------- | -------- |
| images     | Array&lt;ImageFrameInfo&gt; | No  | Image frame information. The information of each frame includes the image path, image size, image position, and image playback duration. For details, see **ImageFrameInfo**.<br>Default value: **[]** |
| state      | [AnimationStatus](ts-appendix-enums.md#animationstatus) | No   | Playback status of the animation. The default status is **Initial**.<br>Default value: **AnimationStatus.Initial**|
| duration   | number  | No   | Playback duration, in ms. The default duration is 1000 ms. When the duration is **0**, no image is played. The value change takes effect only at the beginning of the next cycle. When a separate duration is set in **images**, the setting of this attribute is invalid.<br>Default value: **1000**|
| reverse    | boolean | No   | Playback sequence. The value **false** indicates that images are played from the first one to the last one, and **true** indicates that images are played from the last one to the first one.<br>Default value: **false**|
| fixedSize  | boolean | No   | Whether the image size is the same as the component size.<br> **true**: The image size is the same as the component size. In this case, the width, height, top, and left attributes of the image are invalid.<br> **false**: The width, height, top, and left attributes of each image must be set separately.<br>Default value: **true**|
| preDecode  | number  | No   | Whether to enable pre-decoding. The default value **0** indicates that pre-decoding is disabled. The value **2** indicates that two images following the currently playing frame will be cached in advance to improve performance.<br>Default value: **0**|
| fillMode   | [FillMode](ts-appendix-enums.md#fillmode) | No   | Status before and after the animation starts. For details about the options, see **FillMode**.<br>Default value: **FillMode.Forwards**|
| iterations | number  | No   | Number of times that the animation is played. By default, the animation is played once. The value **-1** indicates that the animation is played for an unlimited number of times.<br>Default value: **1**|

- ImageFrameInfo

| Name  | Type  | Mandatory| Description|
| -------- | -------------- | -------- | -------- |
| src      | string \| [Resource](ts-types.md#resource)<sup>9+</sup> | Yes   | Image path. The image format can be .svg, .png, or .jpg. Since API version 9, this attribute accepts paths of the [Resource](ts-types.md#resource) type.|
| width    | [Length](ts-types.md#length)  | No | Image width.<br>Default value: **0**         |
| height   | [Length](ts-types.md#length)  | No | Image height.<br>Default value: **0**            |
| top      | [Length](ts-types.md#length)  | No | Vertical coordinate of the image relative to the upper left corner of the widget<br>Default value: **0**   |
| left     | [Length](ts-types.md#length)  | No | Horizontal coordinate of the image relative to the upper left corner of the widget<br>Default value: **0**   |
| duration | number          | No    | Playback duration of each image frame, in milliseconds.<br>Default value: **0**              |


## Events

| Name| Description|
| -------- | -------- |
| onStart(event:&nbsp;()&nbsp;=&gt;&nbsp;void)  | Triggered when the animation starts to play.|
| onPause(event:&nbsp;()&nbsp;=&gt;&nbsp;void)  | Triggered when the animation playback is paused.|
| onRepeat(event:&nbsp;()&nbsp;=&gt;&nbsp;void) | Triggered when the animation playback is repeated.|
| onCancel(event:&nbsp;()&nbsp;=&gt;&nbsp;void) | Triggered when the animation playback is canceled.|
| onFinish(event:&nbsp;()&nbsp;=&gt;&nbsp;void) | Triggered when the animation playback is complete.|


## Example

```ts
// xxx.ets
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
            // The comment folder is at the same level as the pages folder.
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
            src: $r('app.media.bg3'),
            duration: 500,
            width: 325,
            height: 200,
            top: 0,
            left: 0
          },
          {
            src: $rawfile('bg4.jpg'),
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
          this.state = AnimationStatus.Stopped
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
