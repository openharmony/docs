# Video


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
> This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


The **&lt;Video&gt;** component provides a video player.


## Child Components

The **&lt;Video&gt;** component does not support any child component.


## APIs

Video(value: VideoOptions)

- VideoOptions attributes
    | Name | Type | Mandatory | Default Value | Description |
  | -------- | -------- | -------- | -------- | -------- |
  | src | string | No | - | Path of the video source. |
  | currentProgressRate | number \| PlaybackSpeed<sup>8+</sup> | No | 1.0 \| PlaybackSpeed.Speed_Forward_1_00_X | Video playback speed.<br/>> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**<br/>> The value of the number type can only be **0.75**, **1.0**, **1.25**, **1.75**, or **2.0**.<br/>> <br/>>  |
  | previewUri | string \| PixelMap<sup>8+</sup> \|[Resource](../../ui/ts-types.md) | No | - | Path of the preview image. |
  | controller | [VideoController](#videocontroller) | No | - | Controller. |


- PlaybackSpeed<sup>8+</sup>
    | Name | Description |
  | -------- | -------- |
  | Speed_Forward_0_75_X | 0.75x playback speed. |
  | Speed_Forward_1_00_X | 1x playback speed. |
  | Speed_Forward_1_25_X | 1.25x playback speed. |
  | Speed_Forward_1_75_X | 1.75x playback speed. |
  | Speed_Forward_2_00_X | 2x playback speed. |


## Attributes

| Name | Type | Default Value | Description |
| -------- | -------- | -------- | -------- |
| muted | boolean | false | Whether the video is muted. |
| autoPlay | boolean | false | Whether the video is automatically played. |
| controls | boolean | true | Whether the video playback control bar is displayed. |
| objectFit | [ImageFit](ts-basic-components-image.md) | Cover | Video display mode. |
| loop | boolean | false | Whether a single video is played cyclically. |


## Events

| Name | Description |
| -------- | -------- |
| onStart() =&gt; void | Triggered when the video is played. |
| onPause() =&gt; void | Triggered when the video playback is paused. |
| onFinish() =&gt; void | Triggered when the video playback is finished. |
| onError() =&gt; void | Triggered when the video playback fails. |
| onPrepared(event?: { duration: number }) =&gt; void | Triggered when video preparation is complete. The video duration (in seconds) is obtained from **duration**. |
| onSeeking(event?: { time: number }) =&gt; void | Triggered to report the time (in seconds) when the progress bar is being dragged. |
| onSeeked(event?: { time: number }) =&gt; void | Triggered to report the playback time (in seconds) when the user finishes dragging the progress bar. |
| onUpdate(event?: { time: number }) =&gt; void | Triggered once per 250 ms when the playback progress changes. The unit of the current playback time is second. |


## VideoController

A **VideoController** object can control one or more videos.


### Objects to Import

```
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

- Parameters
  | Name | Type | Mandatory | Default Value | Description |
  | -------- | -------- | -------- | -------- | -------- |
  | value | number | Yes | - | Video playback position. |

### requestFullscreen

requestFullscreen(value: boolean)

Requests full-screen mode.

- Parameters
  | Name | Type | Mandatory | Default Value | Description |
  | -------- | -------- | -------- | -------- | -------- |
  | value | number | Yes | false | Whether the playback is in full-screen mode. |

### exitFullscreen

exitFullscreen()

Exits full-screen mode.

### setCurrentTime<sup>8+</sup>

setCurrentTime(value: number, seekMode: SeekMode)

Sets the video playback position with the specified seek mode.

- Parameters
  | Name | Type | Mandatory | Default Value | Description |
  | -------- | -------- | -------- | -------- | -------- |
  | value | number | Yes | - | Video playback position. |
  | seekMode | SeekMode | Yes | - | Seek mode. |

- SeekMode<sup>8+</sup>
  | Name | Description |
  | -------- | -------- |
  | PreviousKeyframe | Seeks to the nearest previous keyframe. |
  | NextKeyframe | Seeks to the nearest next keyframe. |
  | ClosestKeyframe | Seeks to the nearest keyframe. |
  | Accurate | Seeks to a specific frame, regardless of whether the frame is a keyframe. |


## Example


```
@Entry
@Component
struct VideoCreateComponent {
  @State srcs: string = "/resources/video/video1.mp4";
  @State previewUris: string = "/resources/image/media.JPG";
  @State currentProgressRates: number = 1;
  @State autoPlays: boolean = false;
  @State controlsss: boolean = true;
  myVideoController: VideoController = new VideoController();
  @State startStaus: boolean = true;
  build() {
    Column() {
      Video({
        src: this.srcs,
        previewUri: this.previewUris, 
        currentProgressRate: this.currentProgressRates,
        controller: this.myVideoController
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
                  console.error('onFinish');
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
          if (this.srcs == "/resources/video/video1.mp4") {
            this.srcs = "/resources/video/video2.mp4";
          } else {
            this.srcs = "/resources/video/video1.mp4";
          }
        });
        Button("previewUri").onClick(() => {
          if (this.previewUris == "/resources/image/media.JPG") {
            this.previewUris = "/resources/image/sinlin.png";
          } else {
            this.previewUris = "/resources/image/media.JPG";
          }
        });
        Button("controlsss").onClick(() => {
          this.controlsss = !this.controlsss;
        });
      }

      Row() {
        Button("start").onClick(() => {
          this.myVideoController.start();
        });
        Button("pause").onClick(() => {
          this.myVideoController.pause();
        });
        Button("stop").onClick(() => {
          this.myVideoController.stop();
        });
      }

      Row() {
        Button("setCurrentTime").onClick(() => {
          this.myVideoController.setCurrentTime(9, SeekMode.Accurate);
        });
      }
    }
  }
}
```
