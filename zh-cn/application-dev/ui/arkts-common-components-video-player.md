# 视频播放 (Video)
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @sd-wu-->
<!--SE: @sunbees-->
<!--TSE: @liuli0427-->


Video组件用于播放视频文件并控制其播放状态，常用于短视频和应用内部视频的列表页面。当视频完整出现时会自动播放，用户点击视频区域则会暂停播放，同时显示播放进度条，通过拖动播放进度条指定视频播放到具体位置。具体用法请参考[Video](../reference/apis-arkui/arkui-ts/ts-media-components-video.md)。


## 创建视频组件

Video通过调用接口来创建，接口调用形式如下：

`Video(value: VideoOptions)`

## 加载视频资源

Video组件支持加载本地视频和网络视频。具体的数据源配置请参考[VideoOptions对象说明](../reference/apis-arkui/arkui-ts/ts-media-components-video.md#videooptions对象说明)。


### 加载本地视频

- 普通本地视频。

  加载本地视频时，首先在本地rawfile目录指定对应的文件，如下图所示。

  ![zh-cn_image_0000001562700409](figures/zh-cn_image_0000001562700409.png)

  再使用资源访问符$rawfile()引用视频资源。

  ```ts
  // xxx.ets
  @Component
  export struct VideoPlayer {
    private controller: VideoController = new VideoController()
    private previewUris: Resource = $r('app.media.preview')
    private innerResource: Resource = $rawfile('videoTest.mp4')

    build() {
      Column() {
        Video({
          src: this.innerResource,  // 设置视频源
          previewUri: this.previewUris, // 设置预览图
          controller: this.controller //设置视频控制器，可以控制视频的播放状态
        })
      }
    }
  }
  ```


- [Data Ability](../application-models/dataability-overview.md)提供的视频路径带有dataability://前缀，使用时确保对应视频资源存在。

  ```ts
  // xxx.ets
  @Component
  export struct VideoPlayer {
    private controller: VideoController = new VideoController()
    private previewUris: Resource = $r('app.media.preview')
    private videoSrc: string = 'dataability://device_id/com.domainname.dataability.videodata/video/10'

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

### 加载沙箱路径视频

支持file://路径前缀的字符串，用于读取应用沙箱路径内的资源，需要确保应用沙箱目录路径下的文件存在并且有可读权限。

```ts
// xxx.ets
@Component
export struct VideoPlayer {
  private controller: VideoController = new VideoController()
  private videoSrc: string = 'file:///data/storage/el2/base/haps/entry/files/show.mp4'

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


### 加载网络视频

加载网络视频时，需要申请ohos.permission.INTERNET权限，具体申请方式请参考[声明权限](../security/AccessToken/declare-permissions.md)。此时，Video的src属性为网络视频的链接。


```ts
// xxx.ets
@Component
export struct VideoPlayer {
  private controller: VideoController = new VideoController()
  private previewUris: Resource = $r('app.media.preview')
  private videoSrc: string = 'https://www.example.com/example.mp4' // 使用时请替换为实际视频加载网址

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


## 添加属性

Video组件[属性](../reference/apis-arkui/arkui-ts/ts-media-components-video.md#属性)主要用于设置视频的播放形式。例如设置视频播放是否静音、播放是否显示控制条等。


```ts
// xxx.ets
@Component
export struct VideoPlayer {
  private controller: VideoController = new VideoController()

  build() {
    Column() {
      Video({
        controller: this.controller
      })
        .muted(false) // 设置是否静音
        .controls(false) // 设置是否显示默认控制条
        .autoPlay(false) // 设置是否自动播放
        .loop(false) // 设置是否循环播放
        .objectFit(ImageFit.Contain) // 设置视频填充模式
    }
  }
}
```


## 事件调用

  Video组件回调事件主要包括播放开始、播放暂停、播放结束、播放失败、播放停止、视频准备和操作进度条等事件，除此之外，Video组件也支持通用事件的调用，如点击、触摸等事件的调用。详细事件请参考[事件说明](../reference/apis-arkui/arkui-ts/ts-media-components-video.md#事件)。

```ts
// xxx.ets
@Entry
@Component
struct VideoPlayer {
  private controller: VideoController = new VideoController()
  private previewUris: Resource = $r('app.media.preview')
  private innerResource: Resource = $rawfile('videoTest.mp4')

  build() {
    Column() {
      Video({
        src: this.innerResource,
        previewUri: this.previewUris,
        controller: this.controller
      })
        .onUpdate((event) => { // 更新事件回调
          console.info("Video update.");
        })
        .onPrepared((event) => { // 准备事件回调
          console.info("Video prepared.");
        })
        .onError(() => { // 失败事件回调
          console.error("Video error.");
        })
        .onStop(() => { // 停止事件回调
          console.info("Video stopped.");
        })
    }
  }
}
```


## Video控制器使用

Video控制器主要用于控制视频的状态，包括播放、暂停、停止以及设置进度等，详细使用请参考[VideoController使用说明](../reference/apis-arkui/arkui-ts/ts-media-components-video.md#videocontroller)。

- 默认控制器

  默认的控制器支持视频的开始、暂停、进度调整、全屏显示四项基本功能。

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct VideoGuide {
    @State videoSrc: Resource = $rawfile('videoTest.mp4')
    @State previewUri: string = 'common/videoIcon.png'
    @State curRate: PlaybackSpeed = PlaybackSpeed.Speed_Forward_1_00_X

    build() {
      Row() {
        Column() {
          Video({
            src: this.videoSrc,
            previewUri: this.previewUri,
            currentProgressRate: this.curRate // 设置视频播放倍速
          })
        }
        .width('100%')
      }
      .height('100%')
    }
  }
  ```

- 自定义控制器

  使用自定义的控制器，先关闭默认控制器，然后使用button以及slider等组件进行自定义的控制与显示，适合自定义较强的场景下使用。

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct VideoGuide {
    @State videoSrc: Resource = $rawfile('videoTest.mp4')
    @State previewUri: string = 'common/videoIcon.png'
    @State curRate: PlaybackSpeed = PlaybackSpeed.Speed_Forward_1_00_X
    @State currentTime: number = 0
    @State durationTime: number = 0
    controller: VideoController = new VideoController()

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
                this.controller.setCurrentTime(value); // 设置视频播放的进度跳转到value处
              })
              .width("90%")
            Text(JSON.stringify(this.durationTime) + 's')
          }
          .opacity(0.8)
          .width("100%")
        }
        .width('100%')
      }
      .height('40%')
    }
  }
  ```


## 其他说明

Video组件已经封装好了视频播放的基础能力，开发者无需进行视频实例的创建，视频信息的设置获取，只需要设置数据源以及基础信息即可播放视频，相对扩展能力较弱。如果开发者想自定义视频播放，请参考[视频播放](../media/media/video-playback.md)。

## 相关实例

针对Video组件开发，有以下相关实例可供参考：

- [ 媒体库视频（ArkTS）（API9）](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Media/VideoShow)

- [简易视频播放器（ArkTS）（API9）](https://gitee.com/openharmony/codelabs/tree/master/Media/SimpleVideo)
<!--RP1--><!--RP1End-->