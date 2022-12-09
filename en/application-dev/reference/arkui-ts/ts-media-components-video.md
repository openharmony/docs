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

| Name             | Type                                                    | Mandatory| Description                                                    |
| ------------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| src                 | string \| [Resource](ts-types.md#resource)                   | No  | Path of the video source, which can be a local path or a URL.<br>The video resources can be stored in the **video** or **rawfile** folder under **resources**.<br>The path can include a **dataability://** prefix, which is used to access the video path provided by a Data ability. For details about the path, see [Data Ability Development](../../ability/fa-dataability.md).<br>**NOTE**<br>The supported video formats are MP4, MKV, WebM, and TS. |
| currentProgressRate | number \| PlaybackSpeed<sup>8+</sup> | No  | Video playback speed.<br>**NOTE**<br>The value of the number type can only be **0.75**, **1.0**, **1.25**, **1.75**, or **2.0**.<br>Default value: **1.0** \| PlaybackSpeed.Speed_Forward_1_00_X |
| previewUri          | string \| PixelMap<sup>8+</sup> \| [Resource](ts-types.md#resource) | No  | Path of the preview image.                                            |
| controller          | [VideoController](#videocontroller)                          | No  | Controller.                                                    |

## PlaybackSpeed<sup>8+</sup>

| Name                  | Description       |
| -------------------- | --------- |
| Speed_Forward_0_75_X | 0.75x playback speed.|
| Speed_Forward_1_00_X | 1x playback speed.   |
| Speed_Forward_1_25_X | 1.25x playback speed.|
| Speed_Forward_1_75_X | 1.75x playback speed.|
| Speed_Forward_2_00_X | 2x playback speed.   |

## Attributes

| Name     | Type                                | Description                                           |
| --------- | ---------------------------------------- | ----------------------------------------------- |
| muted     | boolean                                  | Whether to mute the video.<br>Default value: **false**                   |
| autoPlay  | boolean                                  | Whether to enable auto play.<br>Default value: **false**               |
| controls  | boolean                                  | Whether to display the video playback control bar.<br>Default value: **true**|
| objectFit | [ImageFit](ts-appendix-enums.md#imagefit) | Video scale type.<br>Default value: **Cover**           |
| loop      | boolean                                  | Whether to repeat the video.<br>Default value: **false**       |

## Events

| Name                                                         | Description                                                  |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| onStart(event:() =&gt; void)                                 | Triggered when the video is played.                          |
| onPause(event:() =&gt; void)                                 | Triggered when the video playback is paused.                 |
| onFinish(event:() =&gt; void)                                | Triggered when the video playback is finished.               |
| onError(event:() =&gt; void)                                 | Triggered when the video playback fails.                     |
| onPrepared(callback:(event?: { duration: number }) =&gt; void) | Triggered when video preparation is complete. The video duration (in seconds) is obtained from **duration**. |
| onSeeking(callback:(event?: { time: number }) =&gt; void)    | Triggered to report the time (in seconds) when the progress bar is being dragged. |
| onSeeked(callback:(event?: { time: number }) =&gt; void)     | Triggered to report the playback time (in seconds) when the user finishes dragging the progress bar. |
| onUpdate(callback:(event?: { time: number }) =&gt; void)     | Triggered once per 250 ms when the playback progress changes. The unit of the current playback time is second. |


## VideoController

Defines a **VideoController** object to control one or more videos.


### Objects to Import

```ts
controller: VideoController = new VideoController();
```


### start

start(): void

Starts playback.

### pause

pause(): void

Pauses playback.

### stop

stop(): void

Stops playback.

### setCurrentTime

setCurrentTime(value: number)

Sets the video playback position.

**Parameters**

| Name| Type| Mandatory| Description                   |
| ------ | -------- | ---- | --------------------------- |
| value  | number   | Yes  | Video playback position. |

### requestFullscreen

requestFullscreen(value: boolean)

Requests full-screen mode.

**Parameters**

| Name  | Type  | Mandatory  | Description   |
| ----- | ------ | ---- | ------- |
| value | boolean | Yes   | Whether the playback is in full-screen mode.<br>Default value: **false**|

### exitFullscreen

exitFullscreen()

Exits full-screen mode.

### setCurrentTime<sup>8+</sup>

setCurrentTime(value: number, seekMode: SeekMode)

Sets the video playback position with the specified seek mode.

**Parameters**

| Name  | Type| Mandatory| Description          |
| -------- | -------- | ---- | ------------------ |
| value    | number   | Yes  | Video playback position.|
| seekMode | SeekMode | Yes  | Seek mode.        |

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
  @State srcs: Resource = $rawfile('video1.mp4');
  @State previewUris: Resource = $r('app.media.img');
  @State currentProgressRates: number = 1;
  @State autoPlays: boolean = false;
  @State controlsss: boolean = true;
  controller: VideoController = new VideoController();
  
  build() {
    Column() {
      Video({
        src: this.srcs,
        previewUri: this.previewUris, 
        currentProgressRate: this.currentProgressRates,
        controller: this.controller
      }).width(700).height(500)
        .autoPlay(this.autoPlays)
        .controls(this.controlsss)
        .onStart(() => {
                  console.error('onStart');
                })
        .onPause(() => {
                  console.error('onPause');
                })
        .onFinish(() => {
                  console.error('onFinish');
                })
        .onError(() => {
                  console.error('onError');
                })
        .onPrepared((e) => {
                    console.error('onPrepared is ' + e.duration);
                })
        .onSeeking((e) => {
                    console.error('onSeeking is ' + e.time);
                })
        .onSeeked((e) => {
                    console.error('onSeekedis ' + e.time);
                })
        .onUpdate((e) => {
                    console.error('onUpdateis ' + e.time);
                })
      Row() {
        Button("src").onClick(() => {
            this.srcs = $rawfile('video2.mp4');
        });
        Button("previewUri").onClick(() => {
            this.previewUris = $r('app.media.img1');
        });
        Button("controlsss").onClick(() => {
          this.controlsss = !this.controlsss;
        });
      }

      Row() {
        Button("start").onClick(() => {
          this.controller.start();
        });
        Button("pause").onClick(() => {
          this.controller.pause();
        });
        Button("stop").onClick(() => {
          this.controller.stop();
        });
      }

      Row() {
        Button("setCurrentTime").onClick(() => {
          this.controller.setCurrentTime(9, SeekMode.Accurate);
        });
      }
    }
  }
}
```
