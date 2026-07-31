# Video Playback (Video)

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @qianpinyi-->
<!--Designer: @fenglinbailu-->
<!--Tester: @liuli0427-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=1267406e0fa2ca7baf28f4ef9e63b8ea6b455600 translatedAt=2026-07-31T03:35:38.129Z pushedAt=2026-07-31T03:54:32.173Z -->

The **\<Video>** component is used to play a video and control its playback. It is usually used in short video and in-app video list pages. A video automatically plays once fully visible. Tapping the video area pauses playback and displays the playback progress bar. You can drag the progress bar to seek to a specific position. For details, see [Video](../reference/apis-arkui/arkui-ts/ts-media-components-video.md).

## Creating a \<Video> Component

You can create a **\<Video>** component by calling the following API:

`Video(value: VideoOptions)`

## Loading Video

The **\<Video>** component supports loading both local and network videos. For details about data source configuration, see [VideoOptions](../reference/apis-arkui/arkui-ts/ts-media-components-video.md#videooptions).

### Loading a Local Video

- Common local video

  To load a local video, place the video file in the **rawfile** directory of the project, as shown in the following figure.

  ![videoplayer-local](figures/videoplayer-local.png)

  Use **$rawfile()** to reference the video resource.

  <!-- @[local_video](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/VideoPlayer/entry/src/main/ets/pages/LocalVideo.ets) -->

  ``` TypeScript
  // xxx.ets
  // ...
  @Component
  export struct LocalVideo {
    private controller: VideoController = new VideoController();
    // Replace $r('app.media.preview') with the image resource file you need.
    private previewUris: Resource = $r('app.media.preview');
    // Replace $rawfile('videoTest.mp4') with the video resource file you need.
    private innerResource: Resource = $rawfile('videoTest.mp4');
  
    build() {
      Column() {
        Video({
          src: this.innerResource,  // Set the video source.
          previewUri: this.previewUris, // Set the preview image.
          controller: this.controller // Set the video controller to control the playback state.
        })
      }
    }
  }
  ```

- Video provided by a [DataAbility](../application-models/dataability-overview.md), whose path contains the **dataability://** prefix. Ensure that the corresponding video resource exists.

  <!-- @[data_ability](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/VideoPlayer/entry/src/main/ets/pages/DataAbility.ets) -->

  ``` TypeScript
  // xxx.ets
  // ···
  @Component
  export struct LocalVideoTwo {
    private controller: VideoController = new VideoController();
    // Replace $r('app.media.preview') with the image resource file you need.
    private previewUris: Resource = $r('app.media.preview');
    // Replace 'dataability://device_id/com.domainname.dataability.videodata/video/10' with the video resource file you need.
    private videoSrc: string = 'dataability://device_id/com.domainname.dataability.videodata/video/10';
  
    build() {
      Column() {
        Video({
          src: this.videoSrc,
          previewUri: this.previewUris,
          controller: this.controller
        })
      }
    }
  }
  ```

### Loading a Video in the Application Sandbox

A string with the **file://** path prefix is supported for reading resources in the app sandbox path. Ensure that the file exists in the app sandbox directory and has read permission.

<!-- @[sandbox](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/VideoPlayer/entry/src/main/ets/pages/Sandbox.ets) -->

``` TypeScript
// xxx.ets
// ···
@Component
export struct Sandbox {
  private controller: VideoController = new VideoController();
  // Replace 'file:///data/storage/el2/base/haps/entry/files/show.mp4' with the actual video sandbox path.
  private videoSrc: string = 'file:///data/storage/el2/base/haps/entry/files/show.mp4';

  build() {
    Column() {
      Video({
        src: this.videoSrc,
        controller: this.controller
      })
    }
  }
}
```

### Loading an Online Video

To load a network video, you must apply for the **ohos.permission.INTERNET** permission. For details about how to apply for the permission, see [Declaring Permissions](../security/AccessToken/declare-permissions.md). In this case, the **src** attribute of the **\<Video>** component is the URL of the network video.

<!-- @[online_video](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/VideoPlayer/entry/src/main/ets/pages/OnlineVideo.ets) -->

``` TypeScript
// xxx.ets
// ···
@Component
export struct OnlineVideo {
  private controller: VideoController = new VideoController();
  // Replace $r('app.media.preview') with the image resource file you need.
  private previewUris: Resource = $r('app.media.preview');
  // Replace 'www.example.com/example.mp4' with the actual video URL to load.
  private videoSrc: string = 'www.example.com/example.mp4';

  build() {
    Column() {
      Video({
        src: this.videoSrc,
        previewUri: this.previewUris,
        controller: this.controller
      })
    }
  }
}
```

## Adding Attributes

The [attributes](../reference/apis-arkui/arkui-ts/ts-media-components-video.md#attributes) of the **\<Video>** component are mainly used to set the playback mode, such as whether to mute the video and whether to display the control bar.

<!-- @[attribute_video](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/VideoPlayer/entry/src/main/ets/pages/AttributeVideo.ets) -->

``` TypeScript
// xxx.ets
// ···
@Component
export struct AttributeVideo {
  // Replace $rawfile('videoTest.mp4') with the video resource file required by the developer.
  private videoSrc: Resource = $rawfile('videoTest.mp4');
  private controller: VideoController = new VideoController();

  build() {
    Column() {
      Video({
        src: this.videoSrc,
        controller: this.controller
      })
        .muted(false) // Whether to mute.
        .controls(false) // Whether to display the default control bar.
        .autoPlay(true) // Whether to enable auto-play.
        .loop(true) // Whether to loop.
        .objectFit(ImageFit.Contain) // Set the video fill mode.
    }
  }
}
```

## Adding Events

  The callback events of the **\<Video>** component mainly include playback start, playback pause, playback end, playback failure, playback stop, video preparation, and progress bar operation. In addition, the **\<Video>** component also supports universal events, such as click and touch events. For details, see [Events](../reference/apis-arkui/arkui-ts/ts-media-components-video.md#events).

<!-- @[event_call](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/VideoPlayer/entry/src/main/ets/pages/EventCall.ets) -->

``` TypeScript
// xxx.ets
@Entry
@Component
struct EventCall {
  private controller: VideoController = new VideoController();
  // $r('app.media.preview') needs to be replaced with the image resource file required by the developer.
  private previewUris: Resource = $r('app.media.preview');
  // $rawfile('videoTest.mp4') needs to be replaced with the video resource file required by the developer.
  private innerResource: Resource = $rawfile('videoTest.mp4');

  build() {
    Column() {
      Video({
        src: this.innerResource,
        previewUri: this.previewUris,
        controller: this.controller
      })
        .onUpdate((event) => { // Update event callback.
        })
        .onPrepared((event) => { // Prepared event callback.
        })
        .onError(() => { // Error event callback.
        })
        .onStop(() => { // Stop event callback.
        })
    }
  }
}
```

## Using the Video Controller

The video controller is mainly used to control the video state, including play, pause, stop, and seek. For details, see [VideoController](../reference/apis-arkui/arkui-ts/ts-media-components-video.md#videocontroller).

- Default controller

  The default controller supports four basic features: start playback, pause playback, set the video playback position, and play the video in full screen.

  <!-- @[video_guide](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/VideoPlayer/entry/src/main/ets/pages/VideoControl.ets) -->

  ``` TypeScript
  // xxx.ets
  @Entry
  @Component
  struct VideoGuide {
    // Replace $rawfile('videoTest.mp4') with the video resource file you need.
    @State videoSrc: Resource = $rawfile('videoTest.mp4');
    // Replace common/videoIcon.png with the image resource file you need.
    @State previewUri: string = 'common/videoIcon.png';
    @State curRate: PlaybackSpeed = PlaybackSpeed.Speed_Forward_1_00_X;
  
    build() {
      Row() {
        Column() {
          Video({
            src: this.videoSrc,
            previewUri: this.previewUri,
            currentProgressRate: this.curRate // Set the video playback speed.
          })
        }
        .width('100%')
      }
      .height('100%')
    }
  }
  ```

- Custom controller

  To use a custom controller, disable the default controller first, and then use components such as [Button](../reference/apis-arkui/arkui-ts/ts-basic-components-button.md) and [Slider](../reference/apis-arkui/arkui-ts/ts-basic-components-slider.md) to customize the control and display. This approach is suitable for scenarios that require a high degree of customization.

  <!-- @[customize_control](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/VideoPlayer/entry/src/main/ets/pages/CustomizedControl.ets) -->

  ``` TypeScript
  // xxx.ets
  @Entry
  @Component
  struct CustomizedControl {
    // Replace $rawfile('videoTest.mp4') with the video resource file you need.
    @State videoSrc: Resource = $rawfile('videoTest.mp4');
    // Replace common/videoIcon.png with the image resource file you need.
    @State previewUri: string = 'common/videoIcon.png';
    @State curRate: PlaybackSpeed = PlaybackSpeed.Speed_Forward_1_00_X;
    // Initialize the current time to 0.
    @State currentTime: number = 0;
    // Initialize the duration to 0.
    @State durationTime: number = 0;
    controller: VideoController = new VideoController();

    build() {
      Row() {
        Column() {
          Video({
            src: this.videoSrc,
            previewUri: this.previewUri,
            currentProgressRate: this.curRate,
            controller: this.controller
          })
            .controls(false)
            .autoPlay(true)
            .onPrepared((event) => {
              if (event) {
                this.durationTime = event.duration
              }
            })
            .onUpdate((event) => {
              if (event) {
                this.currentTime = event.time
              }
            })
          Row() {
            Text(JSON.stringify(this.currentTime) + 's')
            Slider({
              value: this.currentTime,
              min: 0,
              max: this.durationTime
            })
              .onChange((value: number, mode: SliderChangeMode) => {
                this.controller.setCurrentTime(value); // Set the video playback progress to jump to the position specified by value.
              })
              .width('90%')
            Text(JSON.stringify(this.durationTime) + 's')
          }
          .opacity(0.8)
          .width('100%')
        }
        .width('100%')
      }
      .height('40%')
    }
  }
  ```

## Remarks

The **\<Video>** component encapsulates the basic video playback capabilities. You do not need to create a video instance or configure video information. You only need to set the data source and basic information to play a video, though the extensibility is relatively limited. If you want to customize video playback, use [AVPlayer](../media/media/media-kit-intro.md#avplayer). The following is a simple example of using AVPlayer for video playback. For more details or complex features, see [Video Playback](../media/media/video-playback.md).

  <!-- @[xcomponent_av_player](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/VideoPlayer/entry/src/main/ets/pages/XComponentAVPlayer.ets) -->

  ``` TypeScript
  // xxx.ets
  import { window } from '@kit.ArkUI';
  import { AVPlayerController } from '../avplayertool/AVPlayerController';
  import { emitter } from '@kit.BasicServicesKit';
  import { CommonConstants, VideoDataType } from  '../common/constants/CommonConstants';
  import { VideoData } from '../model/VideoData';
  import { common } from '@kit.AbilityKit';

  class VideoXComponentController extends XComponentController {
    private avPlayerController: AVPlayerController;

    constructor(avPlayerController: AVPlayerController) {
      super();
      this.avPlayerController = avPlayerController;
    }

    onSurfaceCreated(surfaceId: string): void {
      let source: VideoData = {
        type: VideoDataType.RAW_FILE,
        videoSrc: 'videoTest.mp4'
      };
      // Pass the surfaceId and video source information to AVPlayer.
      this.avPlayerController.initAVPlayer(source, surfaceId);
    }
  }

  const MINUTE_UNIT = 60000;
  const SECOND_UNIT = 1000;
  const SECOND_TEN = 10;
  function timeCover(time: number): string {
    let min: number = Math.floor(time / MINUTE_UNIT);
    let second: string = ((time % MINUTE_UNIT) / SECOND_UNIT).toFixed(0);
    return `${min}:${(Number(second) < SECOND_TEN ? '0' : '') + second}`;
  }

  @Entry
  @Component
  struct XComponentAVPlayer {
    // Set the video controller to control the playback state.
    @State avPlayerController: AVPlayerController = new AVPlayerController(this.getUIContext().getHostContext()!);
    // Total duration of the video.
    @State durationTime: number = 0;
    // Current progress of the video.
    @State currentTime: number = 0;
    // Whether the video is paused.
    @State isPause: boolean = true;
    // Whether the video is in full-screen mode.
    @State isLayoutFullScreen: boolean = false;
    // Set the XComponent controller.
    private videoXComponentController: XComponentController = new VideoXComponentController(this.avPlayerController);
    // Whether the window is in landscape mode.
    @State isLandScape: boolean = false;
    // Identifiers of the system navigation bar.
    private WINDOW_SYSTEM_BAR: Array<'status' | 'navigation'> = ['navigation', 'status'];
    // Window width.
    @State windowWidth:number = 0;
    // Window height.
    @State windowHeight: number = 0;
    // Window instance.
    private windowClass: window.Window | null = null;

    // Obtain the window instance.
    getWindow(): window.Window {
      const context = this.getUIContext().getHostContext() as common.UIAbilityContext;
      return context.windowStage!.getMainWindowSync();
    }

    aboutToAppear(): void {
      this.windowClass = this.getWindow();
      let properties = this.windowClass.getWindowProperties();
      let context = this.getUIContext();
      this.windowWidth = context.px2vp(properties.windowRect.width);
      this.windowHeight = context.px2vp(properties.windowRect.height);
      // Obtain the window orientation and dimensions.
      this.windowClass.on('windowSizeChange', (size: window.Size) => {
        this.isLandScape = size.width > size.height;
        this.windowWidth = context.px2vp(size.width);
        this.windowHeight = context.px2vp(size.height);
      })
      emitter.on(CommonConstants.AVPLAYER_PREPARED, (res) => {
        if (res.data) {
          this.durationTime = this.avPlayerController.durationTime;
          // Update the video progress time.
          setInterval(() => {
            this.currentTime = this.avPlayerController.currentTime;
          }, 1000);
        }
      });
    }

    // Set the immersive window.
    setFullScreen(isLayoutFullScreen: boolean) {
      window.getLastWindow(this.getUIContext().getHostContext()).then((win) => {
        if (isLayoutFullScreen) {
          // Set the visibility mode of the navigation bar and status bar in full-screen mode.
          win.setWindowSystemBarEnable([]);
        } else {
          // Set the visibility mode of the navigation bar and status bar in non-full-screen mode.
          win.setWindowSystemBarEnable(this.WINDOW_SYSTEM_BAR);
        }
      }).catch((err: string) => {
        console.error(`setFullScreen failed, message is ${err}`);
      });
    }

    build() {
      Column() {
        Stack() {
          XComponent({ type: XComponentType.SURFACE, controller: this.videoXComponentController })
          Column() {
            Blank()
            Column() {
              Column() {
                Row() {
                  Row() {
                    // Button for playing or pausing the video.
                    SymbolGlyph(this.isPause ? $r('sys.symbol.pause') : $r('sys.symbol.play_fill'))
                      .fontSize(30)
                      .fontWeight(FontWeight.Bolder)
                      .fontColor([Color.White])
                      .onClick(() => {
                        if (this.isPause) {
                          this.avPlayerController.videoPause();
                        } else {
                          this.avPlayerController.videoPlay();
                        }
                        this.isPause = !this.isPause;
                      })
                    // Current progress of the video.
                    Text(timeCover(this.currentTime))
                      .fontColor(Color.White)
                      .textAlign(TextAlign.End)
                      .fontWeight(FontWeight.Regular)
                      .margin({ left: 5 })
                  }
                  Row() {
                    // Video progress bar.
                    Slider({
                      value: this.currentTime,
                      min: 0,
                      max: this.durationTime,
                      style: SliderStyle.OutSet
                    })
                      .id('Slider')
                      .blockColor(Color.White)
                      .trackColor(Color.Gray)
                      .selectedColor('#317af7')
                      .showTips(false)
                      .onChange((value: number, mode: SliderChangeMode) => {
                        if (mode === SliderChangeMode.Begin) {
                          this.avPlayerController.videoPause();
                        }
                        this.avPlayerController.videoSeek(value);
                        this.currentTime = value;
                        if (mode === SliderChangeMode.End) {
                          this.isPause = true;
                          this.avPlayerController.videoPlay();
                        }
                      })
                  }
                  .layoutWeight(1)
                  Row() {
                    // Total duration of the video.
                    Text(timeCover(this.durationTime))
                      .fontColor(Color.White)
                      .fontWeight(FontWeight.Regular)
                      .margin({ right: 5 })
                  }
                  Row() {
                    // Button for toggling full-screen mode.
                    SymbolGlyph(this.isLayoutFullScreen ? $r('sys.symbol.arrow_down_right_and_arrow_up_left') : $r('sys.symbol.arrow_up_left_and_arrow_down_right'))
                      .fontSize(30)
                      .fontWeight(FontWeight.Bolder)
                      .fontColor([Color.White])
                      .onClick(()=> {
                        this.isLayoutFullScreen = !this.isLayoutFullScreen;
                        this.setFullScreen(this.isLayoutFullScreen);
                      })
                  }
                }
                .justifyContent(FlexAlign.Center)
                .padding({ left: 12, right: 20, bottom: 28 })
                .width('100%')
              }
              .backgroundColor(Color.Black)
            }
            .justifyContent(FlexAlign.Center)
          }
          .width('100%')
          .height('100%')
        }
        .height(this.isLayoutFullScreen ? this.windowHeight : 300)
        .width(this.isLayoutFullScreen ? this.windowWidth : 300)
      }
      .width('100%')
      .height('100%')
      .justifyContent(FlexAlign.Center)
      .alignItems(HorizontalAlign.Center)
    }
  }
  ```

## Samples

For **\<Video>** component development, the following samples are available for reference:

- [Media Library Video (ArkTS) (API 9)](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Media/VideoShow)

- [Simple Video Player (ArkTS) (API 9)](https://gitcode.com/openharmony/codelabs/tree/master/Media/SimpleVideo)

<!--RP1--><!--RP1End-->