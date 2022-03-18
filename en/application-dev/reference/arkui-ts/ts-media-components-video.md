# Video


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE：**
> This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


The **&lt;Video&gt;** component provides a video player.


## Child Components

The **&lt;Video&gt;** component does not support any child component.


## APIs

Video(value: VideoOption)

- VideoOption attributes
    | Name | Type | Mandatory | Default&nbsp;Value | Description |
  | -------- | -------- | -------- | -------- | -------- |
  | src | string | No | - | Path&nbsp;of&nbsp;the&nbsp;video&nbsp;source. |
  | currentProgressRate | number&nbsp;\|&nbsp;PlaybackSpeed<sup>8+</sup> | No | 1.0&nbsp;\|&nbsp;PlaybackSpeed.Speed_Forward_1_00_X | Video&nbsp;playback&nbsp;speed.<br/>>&nbsp;![icon-note.gif](public_sys-resources/icon-note.gif)&nbsp;**NOTE：**<br/>>&nbsp;The&nbsp;value&nbsp;of&nbsp;the&nbsp;number&nbsp;type&nbsp;can&nbsp;only&nbsp;be&nbsp;**0.75**,&nbsp;**1.0**,&nbsp;**1.25**,&nbsp;**1.75**,&nbsp;or&nbsp;**2.0**.<br/>>&nbsp;<br/>>&nbsp; |
  | previewUri | string&nbsp;\|&nbsp;PixelMap<sup>8+</sup>&nbsp;\|[Resource](../../ui/ts-types.md) | No | - | Path&nbsp;of&nbsp;the&nbsp;preview&nbsp;image. |
  | controller | [VideoController](#videocontroller) | No | - | Controller. |


- PlaybackSpeed<sup>8+</sup>
    | Name | Description | 
  | -------- | -------- |
  | Speed_Forward_0_75_X | 0.75x&nbsp;playback&nbsp;speed. | 
  | Speed_Forward_1_00_X | 1x&nbsp;playback&nbsp;speed. | 
  | Speed_Forward_1_25_X | 1.25x&nbsp;playback&nbsp;speed. | 
  | Speed_Forward_1_75_X | 1.75x&nbsp;playback&nbsp;speed. | 
  | Speed_Forward_2_00_X | 2x&nbsp;playback&nbsp;speed. | 


## Attributes

| Name | Type | Default&nbsp;Value | Description |
| -------- | -------- | -------- | -------- |
| muted | boolean | false | Whether&nbsp;the&nbsp;video&nbsp;is&nbsp;muted. |
| autoPlay | boolean | false | Whether&nbsp;the&nbsp;video&nbsp;is&nbsp;automatically&nbsp;played. |
| controls | boolean | true | Whether&nbsp;the&nbsp;video&nbsp;playback&nbsp;control&nbsp;bar&nbsp;is&nbsp;displayed. |
| objectFit | [ImageFit](ts-basic-components-image.md) | Cover | Video&nbsp;display&nbsp;mode. |
| loop | boolean | false | Whether&nbsp;a&nbsp;single&nbsp;video&nbsp;is&nbsp;played&nbsp;cyclically. |


## Events

  | Name | Description | 
| -------- | -------- |
| onStart()&nbsp;=&gt;&nbsp;void | Triggered&nbsp;when&nbsp;the&nbsp;video&nbsp;is&nbsp;played. | 
| onPause()&nbsp;=&gt;&nbsp;void | Triggered&nbsp;when&nbsp;the&nbsp;video&nbsp;playback&nbsp;is&nbsp;paused. | 
| onFinish()&nbsp;=&gt;&nbsp;void | Triggered&nbsp;when&nbsp;the&nbsp;video&nbsp;playback&nbsp;is&nbsp;finished. | 
| onError()&nbsp;=&gt;&nbsp;void | Triggered&nbsp;when&nbsp;the&nbsp;video&nbsp;playback&nbsp;fails. |
| onPrepared(event?:&nbsp;{&nbsp;duration:&nbsp;number&nbsp;})&nbsp;=&gt;&nbsp;void | Triggered&nbsp;when&nbsp;video&nbsp;preparation&nbsp;is&nbsp;complete.&nbsp;The&nbsp;video&nbsp;duration&nbsp;(in&nbsp;seconds)&nbsp;is&nbsp;obtained&nbsp;from&nbsp;**duration**. | 
| onSeeking(event?:&nbsp;{&nbsp;time:&nbsp;number&nbsp;})&nbsp;=&gt;&nbsp;void | Triggered&nbsp;to&nbsp;report&nbsp;the&nbsp;time&nbsp;(in&nbsp;seconds)&nbsp;when&nbsp;the&nbsp;progress&nbsp;bar&nbsp;is&nbsp;being&nbsp;dragged. | 
| onSeeked(event?:&nbsp;{&nbsp;time:&nbsp;number&nbsp;})&nbsp;=&gt;&nbsp;void | Triggered&nbsp;to&nbsp;report&nbsp;the&nbsp;playback&nbsp;time&nbsp;(in&nbsp;seconds)&nbsp;when&nbsp;the&nbsp;user&nbsp;finishes&nbsp;dragging&nbsp;the&nbsp;progress&nbsp;bar. | 
| onUpdate(event?:&nbsp;{&nbsp;time:&nbsp;number&nbsp;})&nbsp;=&gt;&nbsp;void | Triggered&nbsp;once&nbsp;per&nbsp;250&nbsp;ms&nbsp;when&nbsp;the&nbsp;playback&nbsp;progress&nbsp;changes.&nbsp;The&nbsp;unit&nbsp;of&nbsp;the&nbsp;current&nbsp;playback&nbsp;time&nbsp;is&nbsp;second. | 


### VideoController

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE：**
> A **VideoController** object can control one or more videos.

  | Name | Description | 
| -------- | -------- |
| start()&nbsp;:&nbsp;void | Starts&nbsp;playback. | 
| pause()&nbsp;:&nbsp;void | Pauses&nbsp;playback. | 
| stop()&nbsp;:&nbsp;void | Stops&nbsp;playback. | 
| setCurrentTime(value:&nbsp;number) | Sets&nbsp;the&nbsp;video&nbsp;playback&nbsp;position. | 
| setCurrentTime(value:&nbsp;number,&nbsp;seekMode:&nbsp;SeekMode)<sup>8+</sup> | Sets&nbsp;the&nbsp;video&nbsp;playback&nbsp;position&nbsp;with&nbsp;the&nbsp;specified&nbsp;seek&nbsp;mode. |

- SeekMode<sup>8+</sup>
    | Name | Description | 
  | -------- | -------- |
  | PreviousKeyframe | Seeks&nbsp;to&nbsp;the&nbsp;nearest&nbsp;previous&nbsp;keyframe. | 
  | NextKeyframe | Seeks&nbsp;to&nbsp;the&nbsp;nearest&nbsp;next&nbsp;keyframe. | 
  | ClosestKeyframe | Seeks&nbsp;to&nbsp;the&nbsp;nearest&nbsp;keyframe. | 
  | Accurate | Seeks&nbsp;to&nbsp;a&nbsp;specific&nbsp;frame,&nbsp;regardless&nbsp;of&nbsp;whether&nbsp;the&nbsp;frame&nbsp;is&nbsp;a&nbsp;keyframe. | 


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
