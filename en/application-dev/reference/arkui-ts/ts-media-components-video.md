# Video

>  **NOTE**<br>
> This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.

The **\<Video>** component provides a video player.

## Required Permissions

To use online videos, you need to add the **ohos.permission.INTERNET** permission to the corresponding **abilities** in the **config.json** or **module.json** file, whichever is appropriate.

```json
"abilities":[
  {
    ...
    "permissions": ["ohos.permission.INTERNET],
    ...
  }
]
```

## Child Components

Not supported

## APIs

Video(value: VideoOptions)

1. VideoOptions attributes
  | Name| Type| Mandatory| Default Value| Description|
  | -------- | -------- | -------- | -------- | -------- |
  | src | string \| [Resource](../../ui/ts-types.md) | No| - | Path of the video source, which can be a local path or a URL.<br>The video resources can be stored in the **video** or **rawfile** folder under **resources**.<br>The path can include a **dataability://** prefix, which is used to access the video path provided by a Data ability. For details about the path, see [Data Ability Development](../../ability/fa-dataability.md).|
  | currentProgressRate | number \| PlaybackSpeed<sup>8+</sup> | No| 1.0 \| PlaybackSpeed.<br>Speed_Forward_1_00_X | Video playback speed.<br>> **NOTE**<br>> The value of the number type can only be **0.75**, **1.0**, **1.25**, **1.75**, or **2.0**.<br>|
  | previewUri | string \| PixelMap<sup>8+</sup> \| [Resource](../../ui/ts-types.md) | No| - | Path of the preview image.|
  | controller | [VideoController](#videocontroller) | No| - | Controller.|


2. PlaybackSpeed<sup>8+</sup>
  | Name                 | Description           |
  | -------------------- | --------------------- |
  | Speed_Forward_0_75_X | 0.75x playback speed. |
  | Speed_Forward_1_00_X | 1x playback speed.    |
  | Speed_Forward_1_25_X | 1.25x playback speed. |
  | Speed_Forward_1_75_X | 1.75x playback speed. |
  | Speed_Forward_2_00_X | 2x playback speed.    |

## Attributes

| Name      | Type                                     | Default Value | Description                                        |
| --------- | ---------------------------------------- | ------------- | -------------------------------------------------- |
| muted     | boolean                                  | false         | Whether the video is muted.                        |
| autoPlay  | boolean                                  | false         | Whether to enable auto play.                       |
| controls  | boolean                                  | true          | Whether to display the video playback control bar. |
| objectFit | [ImageFit](ts-basic-components-image.md) | Cover         | Video scale type.                                  |
| loop      | boolean                                  | false         | Whether to repeat the video.                       |


## Events

| Name| Description|
| -------- | -------- |
| onStart() =&gt; void | Triggered when the video is played.|
| onPause() =&gt; void | Triggered when the video playback is paused.|
| onFinish() =&gt; void | Triggered when the video playback is finished.|
| onError() =&gt; void | Triggered when the video playback fails.|
| onPrepared(event?: { duration: number }) =&gt; void | Triggered when video preparation is complete. The video duration (in seconds) is obtained from **duration**.|
| onSeeking(event?: { time: number }) =&gt; void | Triggered to report the time (in seconds) when the progress bar is being dragged.|
| onSeeked(event?: { time: number }) =&gt; void | Triggered to report the playback time (in seconds) when the user finishes dragging the progress bar.|
| onUpdate(event?: { time: number }) =&gt; void | Triggered once per 250 ms when the playback progress changes. The unit of the current playback time is second.|


## VideoController

A **VideoController** object can control one or more videos.


### Objects to Import

```ts
controller: VideoController = new VideoController();
```


### start

```ts
start(): void

Starts playback.
```

### pause

```ts
pause(): void

Pauses playback.
```

### stop

```ts
stop(): void

Stops playback.
```

### setCurrentTime

```ts
setCurrentTime(value: number)

Sets the video playback position.
```

- Parameters
  | Name  | Type   | Mandatory | Default Value | Description              |
  | ----- | ------ | --------- | ------------- | ------------------------ |
  | value | number | Yes       | -             | Video playback position. |

### requestFullscreen

requestFullscreen(value: boolean)

Requests full-screen mode.

- Parameters
  | Name  | Type   | Mandatory | Default Value | Description                                  |
  | ----- | ------ | --------- | ------------- | -------------------------------------------- |
  | value | number | Yes       | false         | Whether the playback is in full-screen mode. |

### exitFullscreen

exitFullscreen()

Exits full-screen mode.

### setCurrentTime<sup>8+</sup>

setCurrentTime(value: number, seekMode: SeekMode)

Sets the video playback position with the specified seek mode.

1. Parameters
  | Name     | Type     | Mandatory | Default Value | Description              |
  | -------- | -------- | --------- | ------------- | -----------------------  |
  | value    | number   | Yes       | -             | Video playback position. |
  | seekMode | SeekMode | Yes       | -             | Seek mode.               |

2. SeekMode<sup>8+</sup>
  | Name             | Description                                                               |
  | ---------------- | ------------------------------------------------------------------------- |
  | PreviousKeyframe | Seeks to the nearest previous keyframe.                                   |
  | NextKeyframe     | Seeks to the nearest next keyframe.                                       |
  | ClosestKeyframe  | Seeks to the nearest keyframe.                                            |
  | Accurate         | Seeks to a specific frame, regardless of whether the frame is a keyframe. |

## Example

```ts
// xxx.ets
@Entry
@Component
struct VideoCreateComponent {
  @State srcs: Resource = $rawfile('video1');
  @State previewUris: Resource = $r('app.media.img');
  @State currentProgressRates: number = 1;
  @State autoPlays: boolean = false;
  @State controlsss: boolean = true;
  controller: VideoController = new VideoController();
  @State startStaus: boolean = true;
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
            this.srcs = $rawfile('video2');
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