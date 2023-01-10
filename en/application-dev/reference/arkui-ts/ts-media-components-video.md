# Video

The **\<Video>** component is used to play a video and control its playback.

>  **NOTE**
>
>  This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.

## Required Permissions

To use online videos, you must apply for the **ohos.permission.INTERNET** permission. For details about how to apply for the permission, see [Declaring Permissions](../../security/accesstoken-guidelines.md).


## Child Components

Not supported


## APIs

Video(value: {src?: string | Resource, currentProgressRate?: number | string | PlaybackSpeed, previewUri?: string | PixelMap | Resource, controller?: VideoController}) 

**Parameters**

| Name                | Type                                    | Mandatory  | Description                                    |
| ------------------- | ---------------------------------------- | ---- | ---------------------------------------- |
| src                 | string \| [Resource](ts-types.md)        | No   | Path of the video source, which can be a local path or a URL.<br>The video resources can be stored in the **video** or **rawfile** folder under **resources**.<br>The path can include a **dataability://** prefix, which indicates that the path is provided by a Data ability. For details about the path, see [Data Ability Development](../../application-models/dataability-overview.md).<br>**NOTE**<br>The supported video formats are MP4, MKV, WebM, and TS. |
| currentProgressRate | number \| string \| PlaybackSpeed<sup>8+</sup> | No   | Video playback speed.<br>**NOTE**<br>The value of the number type can only be **0.75**, **1.0**, **1.25**, **1.75**, or **2.0**.<br>Default value: **1.0** \| **PlaybackSpeed.Speed_Forward_1_00_X** |
| previewUri          | string \| PixelMap<sup>8+</sup> \| [Resource](ts-types.md) | No   | Path of the preview image.                          |
| controller          | [VideoController](#videocontroller)      | No   | Video controller.                                |

## PlaybackSpeed<sup>8+</sup>

| Name                  | Description       |
| -------------------- | --------- |
| Speed_Forward_0_75_X | 0.75x playback speed.|
| Speed_Forward_1_00_X | 1x playback speed.   |
| Speed_Forward_1_25_X | 1.25x playback speed.|
| Speed_Forward_1_75_X | 1.75x playback speed.|
| Speed_Forward_2_00_X | 2x playback speed.   |

## Attributes

In addition to the [universal attributes](ts-universal-attributes-size.md), the following attributes are supported.

| Name       | Type                                    | Description                          |
| --------- | ---------------------------------------- | ---------------------------- |
| muted     | boolean                                  | Whether to mute the video.<br>Default value: **false**         |
| autoPlay  | boolean                                  | Whether to enable auto play.<br>Default value: **false**       |
| controls  | boolean                                  | Whether to display the video playback control bar.<br>Default value: **true**|
| objectFit | [ImageFit](ts-basic-components-image.md) | Video scale type.<br>Default value: **Cover**     |
| loop      | boolean                                  | Whether to repeat the video.<br>Default value: **false**   |

## Events

In addition to the [universal events](ts-universal-events-click.md), the following events are supported.

| Name                                      | Description                                    |
| ---------------------------------------- | ---------------------------------------- |
| onStart(event:() =&gt; void)   | Triggered when the video is played.                               |
| onPause(event:() =&gt; void)   | Triggered when the video playback is paused.                               |
| onFinish(event:() =&gt; void)  | Triggered when the video playback is finished.                             |
| onError(event:() =&gt; void)   | Triggered when the video playback fails.                             |
| onPrepared(callback:(event?: { duration: number }) =&gt; void) | Triggered when video preparation is complete. The video duration (in seconds) is obtained from **duration**.|
| onSeeking(callback:(event?: { time: number }) =&gt; void) | Triggered to report the time (in seconds) when the progress bar is being dragged.                    |
| onSeeked(callback:(event?: { time: number }) =&gt; void) | Triggered to report the playback time (in seconds) when the user finishes dragging the progress bar.                 |
| onUpdate(callback:(event?: { time: number }) =&gt; void) | Triggered once per 250 ms when the playback progress changes. The unit of the current playback time is second.         |
| onFullscreenChange(callback:(event?: { fullscreen: boolean }) =&gt; void) | Triggered when the playback mode is switched between full-screen mode and non-full-screen mode. The value **true** means that the playback is in full-screen mode, and **false** means that the playback is non-full-screen mode.|


## VideoController

Defines a **VideoController** object to control one or more videos.


### Objects to Import

```ts
controller: VideoController = new VideoController()
```


### start

start(): void

Starts playback.

### pause

pause(): void

Pauses playback. The current frame is then displayed, and playback will be resumed from this paused position.

### stop

stop(): void

Stops playback. The current frame is then displayed, and playback will restart from the very beginning.

### setCurrentTime

setCurrentTime(value: number)

Sets the video playback position.

**Parameters**

| Name  | Type  | Mandatory  | Description          |
| ----- | ------ | ---- | -------------- |
| value | number | Yes   | Video playback position, in seconds.|

### requestFullscreen

requestFullscreen(value: boolean)

Requests full-screen mode.

**Parameters**

| Name  | Type   | Mandatory  | Description                 |
| ----- | ------- | ---- | --------------------- |
| value | boolean | Yes   | Whether the playback is in full-screen mode.<br>Default value: **false**|

### exitFullscreen

exitFullscreen()

Exits full-screen mode.

### setCurrentTime<sup>8+</sup>

setCurrentTime(value: number, seekMode: SeekMode)

Sets the video playback position with the specified seek mode.

**Parameters**

| Name     | Type    | Mandatory  | Description          |
| -------- | -------- | ---- | -------------- |
| value    | number   | Yes   | Video playback position, in seconds.|
| seekMode | SeekMode | Yes   | Seek mode.         |

## SeekMode<sup>8+</sup>

| Name              | Description            |
| ---------------- | -------------- |
| PreviousKeyframe | Seeks to the nearest previous keyframe. |
| NextKeyframe     | Seeks to the nearest next keyframe. |
| ClosestKeyframe  | Seeks to the nearest keyframe.    |
| Accurate         | Seeks to a specific frame, regardless of whether the frame is a keyframe.|



## Example

```ts
// xxx.ets
@Entry
@Component
struct VideoCreateComponent {
  @State videoSrc: Resource = $rawfile('video1.mp4')
  @State previewUri: Resource = $r('app.media.poster1')
  @State curRate: PlaybackSpeed = PlaybackSpeed.Speed_Forward_1_00_X
  @State isAutoPlay: boolean = false
  @State showControls: boolean = true
  controller: VideoController = new VideoController()

  build() {
    Column() {
      Video({
        src: this.videoSrc,
        previewUri: this.previewUri,
        currentProgressRate: this.curRate,
        controller: this.controller
      }).width(800).height(600)
        .autoPlay(this.isAutoPlay)
        .controls(this.showControls)
        .onStart(() => {
          console.info('onStart')
        })
        .onPause(() => {
          console.info('onPause')
        })
        .onFinish(() => {
          console.info('onFinish')
        })
        .onError(() => {
          console.info('onFinish')
        })
        .onPrepared((e) => {
          console.info('onPrepared is ' + e.duration)
        })
        .onSeeking((e) => {
          console.info('onSeeking is ' + e.time)
        })
        .onSeeked((e) => {
          console.info('onSeeked is ' + e.time)
        })
        .onUpdate((e) => {
          console.info('onUpdate is ' + e.time)
        })
      
      Row() {
        Button('src').onClick(() => {
          this.videoSrc = $rawfile('video2.mp4') // Switch the video source.
        }).margin(5)
        Button('previewUri').onClick(() => {
          this.previewUri = $r('app.media.poster2') // Switch the preview image.
        }).margin(5)
        Button('controls').onClick(() => {
          this.showControls = !this.showControls // Specify whether to show the control bar.
        }).margin(5)
      }

      Row() {
        Button('start').onClick(() => {
          this.controller.start() // Start playback.
        }).margin(5)
        Button('pause').onClick(() => {
          this.controller.pause() // Pause playback.
        }).margin(5)
        Button('stop').onClick(() => {
          this.controller.stop() // Stop playback.
        }).margin(5)
        Button('setTime').onClick(() => {
          this.controller.setCurrentTime(10, SeekMode.Accurate) // Seek to the 10s position of the video.
        }).margin(5)
      }

      Row() {
        Button('rate 0.75').onClick(() => {
          this.curRate = PlaybackSpeed.Speed_Forward_0_75_X // Play the video at the 0.75x speed.
        }).margin(5)
        Button('rate 1').onClick(() => {
          this.curRate = PlaybackSpeed.Speed_Forward_1_00_X // Play the video at the 1x speed.
        }).margin(5)
        Button('rate 2').onClick(() => {
          this.curRate = PlaybackSpeed.Speed_Forward_2_00_X // Play the video at the 2x speed.
        }).margin(5)
      }
    }
  }
}
```

<!--no_check-->