# ImageAnimator

The **\<ImageAnimator>** component enables images to be played frame by frame. The list of images to be played can be configured, and the duration of each image can be configured.

> **NOTE**
>
> This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.

## Required Permissions

None

## Child Components

Not supported


## APIs

ImageAnimator()


## Attributes

| Name    | Type                 | Default Value | Mandatory     | Description                  |
| ---------- | ----------------------- | -------- | -------- | -------- |
| images     | Array&lt;{<br/>src: string,<br/>width?: number \| string,<br/>height?: number \| string,<br/>top?: number \| string,<br/>left?: number \| string,<br/>duration?: number<br/>}&gt; | [] | No  | Image frame information. The information of each frame includes the image path, image size, image position, and image playback duration. The detailed description is as follows:<br/>**src**: image path. The image format can be SVG, PNG, or JPG.<br/>**width**: image width.<br/>**height**: image height.<br/>**top**: vertical coordinate of the image relative to the upper left corner of the component.<br/>**left**: horizontal coordinate of the image relative to the upper left corner of the component.<br/>**duration**: playback duration of the image, in ms. |
| state      | [AnimationStatus](ts-appendix-enums.md#animationstatus) | Initial | No   | Playback status of the animation. |
| duration   | number  | 1000 | No   | Playback duration, in ms. The default duration is 1000 ms. When the duration is **0**, no image is played. The value change takes effect only at the beginning of the next cycle. When a separate duration is set in **images**, the setting of this attribute is invalid. |
| reverse    | boolean | false | No   | Playback sequence. The value **false** indicates that images are played from the first one to the last one, and **true** indicates that images are played from the last one to the first one. |
| fixedSize  | boolean | true | No   | Whether the image size is the same as the component size.<br> **true**: The image size is the same as the component size. In this case, the width, height, top, and left attributes of the image are invalid.<br> **false**: The width, height, top, and left attributes of each image must be set separately. |
| preDecode  | number  | 0  | No   | Whether to enable pre-decoding. The default value **0** indicates that pre-decoding is disabled. The value **2** indicates that two images following the currently playing frame will be cached in advance to improve performance. |
| fillMode   | [FillMode](ts-appendix-enums.md#fillmode) | Forwards | No   | Status before and after the animation starts. For details about the options, see **FillMode**. |
| iterations | number  | 1  | No   | Number of times that the animation is played. By default, the animation is played once. The value **-1** indicates that the animation is played for an unlimited number of times. |

## Events

| Name| Description|
| -------- | -------- |
| onStart(event: () =&gt; void)  | Triggered when the animation starts to play.|
| onPause(event: () =&gt; void)  | Triggered when the animation playback is paused.|
| onRepeat(event: () =&gt; void) | Triggered when the animation playback is repeated.|
| onCancel(event: () =&gt; void) | Triggered when the animation playback is canceled.|
| onFinish(event: () =&gt; void) | Triggered when the animation playback is complete.|


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
