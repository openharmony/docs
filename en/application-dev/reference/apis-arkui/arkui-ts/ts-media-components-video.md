# Video

The **\<Video>** component is used to play a video and control its playback.

>  **NOTE**
>
>  This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.

## Required Permissions

To use online videos, you must apply for the **ohos.permission.INTERNET** permission. For details about how to apply for a permission, see [Declaring Permissions](../../../security/AccessToken/declare-permissions.md).


## Child Components

Not supported


## APIs

Video(value: VideoOptions)

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | [VideoOptions](#videooptions) | Yes| Video information.|

##  VideoOptions

| Name             | Type                                                    | Mandatory| Description                                                    |
| ------------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| src                 | string \| [Resource](ts-types.md#resource)                            | No  | Path of the video source, which can be a local path or a URL.<br>The video resources can be stored in the **video** or **rawfile** folder under **resources**.<br>The path can include a **dataability://** prefix, which indicates that the path is provided by a DataAbility Overview. For details about the path, see [DataAbility Overview](../../../application-models/dataability-overview.md).<br>- Strings with the **file:///data/storage** prefix are supported, which are used to read resources in the application sandbox. Ensure that the application has the read permission to the files in the specified path.<br>**NOTE**<br><br>The supported video formats are MP4, MKV, and TS.|
| currentProgressRate | number \| string \| [PlaybackSpeed<sup>8+</sup>](#playbackspeed8) | No  | Video playback speed.<br>**NOTE**<br><br>The value of the number type can only be **0.75**, **1.0**, **1.25**, **1.75**, or **2.0**.<br>Default value: 1.0 \| PlaybackSpeed.Speed_Forward_1_00_X |
| previewUri          | string \| [PixelMap](../../apis-image-kit/js-apis-image.md#pixelmap7) \| [Resource](ts-types.md)  | No  | Path of the preview image displayed before the video playback starts. By default, no preview image is displayed.                |
| controller          | [VideoController](#videocontroller)                          | No  | Video controller to control the video playback status.                    |


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

### muted

muted(value: boolean)

Specifies whether to mute the video.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type   | Mandatory| Description                        |
| ------ | ------- | ---- | ---------------------------- |
| value  | boolean | Yes  | Whether to mute the video.<br>Default value: **false**|

### autoPlay

autoPlay(value: boolean)

Specifies whether to enable auto play

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type   | Mandatory| Description                            |
| ------ | ------- | ---- | -------------------------------- |
| value  | boolean | Yes  | Whether to enable auto play.<br>Default value: **false**|

### controls

controls(value: boolean)

Specifies whether to display the video playback control bar.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type   | Mandatory| Description                                           |
| ------ | ------- | ---- | ----------------------------------------------- |
| value  | boolean | Yes  | Whether to display the video playback control bar.<br>Default value: **true**|

### objectFit

objectFit(value: ImageFit)

Sets the video scale type.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                     | Mandatory| Description                            |
| ------ | ----------------------------------------- | ---- | -------------------------------- |
| value  | [ImageFit](ts-appendix-enums.md#imagefit) | Yes  | Video scale type.<br>Default value: **Cover**|

### loop

loop(value: boolean)

Specifies whether to repeat the video.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type   | Mandatory| Description                                    |
| ------ | ------- | ---- | ---------------------------------------- |
| value  | boolean | Yes  | Whether to repeat the video.<br>Default value: **false**|

## Events

In addition to the [universal events](ts-universal-events-click.md), the following events are supported.

### onStart

onStart(event:() =&gt; void)

Triggered when the video is played.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### onPause

onPause(event:() =&gt; void)

Triggered when the video playback is paused.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### onFinish

onFinish(event:() =&gt; void)

Triggered when the video playback is finished.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### onError

onError(event:() =&gt; void)

Triggered when the video playback fails.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### onStop<sup>12+</sup>

onStop(event:() =&gt; void)

Triggered when the video playback is stopped (after **stop()** is called).

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### onPrepared

onPrepared(callback:(event: { duration: number }) =&gt; void)

Triggered when video preparation is complete.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name  | Type  | Mandatory| Description                      |
| -------- | ------ | ---- | -------------------------- |
| duration | number | Yes  | Duration of the video, in seconds.|

### onSeeking

onSeeking(callback:(event: { time: number }) =&gt; void)

Triggered to report the time when the progress bar is being dragged.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description                          |
| ------ | ------ | ---- | ------------------------------ |
| time   | number | Yes  | Current video playback progress, in seconds.|

### onSeeked

onSeeked(callback:(event: { time: number }) =&gt; void)

Triggered to report the playback time when the user finishes dragging the progress bar.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description                          |
| ------ | ------ | ---- | ------------------------------ |
| time   | number | Yes  | Current video playback progress, in seconds.|

### onUpdate

onUpdate(callback:(event: { time: number }) =&gt; void)

Triggered when the playback progress changes.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description                          |
| ------ | ------ | ---- | ------------------------------ |
| time   | number | Yes  | Current video playback progress, in seconds.|

### onFullscreenChange

onFullscreenChange(callback:(event: { fullscreen: boolean }) =&gt; void)

Triggered when the playback is switched between full-screen mode and non-full-screen mode.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type   | Mandatory| Description                                                 |
| ---------- | ------- | ---- | ----------------------------------------------------- |
| fullscreen | boolean | Yes  | The value **true** means that the playback is in full-screen mode, and **false** means the opposite.|


## VideoController

Defines a **VideoController** object to control one or more videos. For details about available video playback examples, see [@ohos.multimedia.media](../../apis-media-kit/js-apis-media.md).


### Objects to Import

```ts
let controller: VideoController = new VideoController()
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

| Name| Type| Mandatory| Description                        |
| ------ | -------- | ---- | -------------------------------- |
| value  | boolean  | Yes  | Whether to play the video in full screen mode within the application window.|

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
| seekMode | [SeekMode](#seekmode8) | Yes   | Seek mode.         |

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
      })
        .width('100%')
        .height(600)
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
          console.info('onError')
        })
        .onStop(() => {
          console.info('onStop')
        })
        .onPrepared((e?: DurationObject) => {
          if (e != undefined) {
            console.info('onPrepared is ' + e.duration)
          }
        })
        .onSeeking((e?: TimeObject) => {
          if (e != undefined) {
            console.info('onSeeking is ' + e.time)
          }
        })
        .onSeeked((e?: TimeObject) => {
          if (e != undefined) {
            console.info('onSeeked is ' + e.time)
          }
        })
        .onUpdate((e?: TimeObject) => {
          if (e != undefined) {
            console.info('onUpdate is ' + e.time)
          }
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

interface DurationObject {
  duration: number;
}

interface TimeObject {
  time: number;
}
```
