# 视频播放（Video）


Video组件用于播放视频文件并控制其播放状态，常用于为短视频应用和应用内部视频的列表页面。当视频完整出现时会自动播放，用户点击视频区域则会暂停播放，同时显示播放进度条，通过拖动播放进度条指定视频播放到具体位置。具体用法请参考[Video](../reference/arkui-ts/ts-media-components-video.md)。


## 创建视频组件

Video通过调用接口来创建，接口调用形式如下：


```ts
Video(value: {src?: string | Resource, currentProgressRate?: number | string | PlaybackSpeed, previewUri?: string | PixelMap | Resource, controller?: VideoController})
```

该接口用于创建视频播放组件。其中，src指定视频播放源的路径，加载方式请参考[加载视频资源](#加载视频资源)，currentProgressRate用于设置视频播放倍速，previewUri指定视频未播放时的预览图片路径，controller设置视频控制器，用于自定义控制视频。


## 加载视频资源

Video组件支持加载本地视频和网络视频。


### 加载本地视频

- 普通本地视频。

  加载本地视频时，首先在本地rawfile目录指定对应的文件，如下图所示。

  ![zh-cn_image_0000001562700409](figures/zh-cn_image_0000001562700409.png)

  再使用资源访问符$rawfile()引用视频资源。

  ```ts
  @Component
  export struct VideoPlayer{
     private controller:VideoController;
     private previewUris: Resource = $r ('app.media.preview');
     private innerResource: Resource = $rawfile('videoTest.mp4');
     build(){
       Column() {
         Video({
           src: this.innerResource,
           previewUri: this.previewUris,
           controller: this.controller
         })
     }
   }
  }
  ```


- [Data Ability](../application-models/dataability-overview.md)提供的视频路径带有dataability://前缀，使用时确保对应视频资源存在即可。

  ```ts
  @Component
  export struct VideoPlayer{
     private controller:VideoController;
     private previewUris: Resource = $r ('app.media.preview');
     private videosrc: string= 'dataability://device_id/com.domainname.dataability.videodata/video/10'
     build(){
       Column() {
         Video({
           src: this.videosrc,
           previewUri: this.previewUris,
           controller: this.controller
         })
     }
   }
  }
  ```

### 加载沙箱路径视频

支持file:///data/storage路径前缀的字符串，用于读取应用沙箱路径内的资源。需要保证应用沙箱目录路径下的文件存在并且有可读权限。

```ts
@Component
export struct VideoPlayer {
  private controller: VideoController;
  private videosrc: string = 'file:///data/storage/el2/base/haps/entry/files/show.mp4'

  build() {
    Column() {
      Video({
        src: this.videosrc,
        controller: this.controller
      })
    }
  }
}
```


### 加载网络视频

加载网络视频时，需要申请权限ohos.permission.INTERNET，具体申请方式请参考[权限申请声明](../security/accesstoken-guidelines.md)。此时，Video的src属性为网络视频的链接。


```ts
@Component
export struct VideoPlayer{
   private controller:VideoController;
   private previewUris: Resource = $r ('app.media.preview');
   private videosrc: string= 'https://www.example.com/example.mp4' // 使用时请替换为实际视频加载网址
   build(){
     Column() {
       Video({
         src: this.videosrc,
         previewUri: this.previewUris,
         controller: this.controller
       })
   }
 }
}
```


## 添加属性

Video组件[属性](../reference/arkui-ts/ts-media-components-video.md#属性)主要用于设置视频的播放形式。例如设置视频播放是否静音、播放时是否显示控制条等。


```ts
@Component
export struct VideoPlayer {
  private controller: VideoController;

  build() {
    Column() {
      Video({
        controller: this.controller
      })
        .muted(false) //设置是否静音
        .controls(false) //设置是否显示默认控制条
        .autoPlay(false) //设置是否自动播放
        .loop(false) //设置是否循环播放
        .objectFit(ImageFit.Contain) //设置视频适配模式
    }
  }
}
```


## 事件调用

  Video组件回调事件主要为播放开始、暂停结束、播放失败、视频准备和操作进度条等事件，除此之外，Video组件也支持通用事件的调用，如点击、触摸等事件的调用。详细的事件请参考[事件说明](../reference/arkui-ts/ts-media-components-video.md#事件)。

```ts
@Entry
@Component
struct VideoPlayer{
  private controller:VideoController;
  private previewUris: Resource = $r ('app.media.preview');
  private innerResource: Resource = $rawfile('videoTest.mp4');
  build(){
    Column() {
      Video({
        src: this.innerResource,
        previewUri: this.previewUris,
        controller: this.controller
      })
        .onUpdate((event) => {   //更新事件回调
          console.info("Video update.");
        })
        .onPrepared((event) => {  //准备事件回调
          console.info("Video prepared.");
        })
        .onError(() => {          //失败事件回调
          console.info("Video error.");
        })
    }
  }
}
```


## Video控制器使用

Video控制器主要用于控制视频的状态，包括播放、暂停、停止以及设置进度等，详细的使用请参考[VideoController使用说明](../reference/arkui-ts/ts-media-components-video.md#videocontroller)。

- 默认控制器

  默认的控制器支持视频的开始、暂停、进度调整、全屏显示四项基本功能。

  ```ts
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
            currentProgressRate: this.curRate
          })
        }
        .width('100%')
      }
      .height('100%')
    }
  }
  ```

- 自定义控制器

  使用自定义的控制器，先将默认控制器关闭掉，之后可以使用button以及slider等组件进行自定义的控制与显示，适合自定义较强的场景下使用。

  ```ts
  @Entry
  @Component
  struct VideoGuide {
    @State videoSrc: Resource = $rawfile('videoTest.mp4')
    @State previewUri: string = 'common/videoIcon.png'
    @State curRate: PlaybackSpeed = PlaybackSpeed.Speed_Forward_1_00_X
    @State isAutoPlay: boolean = false
    @State showControls: boolean = true
    @State sliderStartTime: string = '';
    @State currentTime: number = 0;
    @State durationTime: number = 0;
    @State durationStringTime: string ='';
    controller: VideoController = new VideoController()

    build() {
      Row() {
        Column() {
          Video({
            src: this.videoSrc,
            previewUri: this.previewUri,
            currentProgressRate: this.curRate,
            controller: this.controller
          }).controls(false).autoPlay(true)
          .onPrepared((event)=>{
            this.durationTime = event.duration
          })
          .onUpdate((event)=>{
            this.currentTime =event.time
          })
          Row() {
            Text(JSON.stringify(this.currentTime) + 's')
            Slider({
              value: this.currentTime,
              min: 0,
              max: this.durationTime
            })
            .onChange((value: number, mode: SliderChangeMode) => {
                this.controller.setCurrentTime(value);
              }).width("90%")
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

Video组件已经封装好了视频播放的基础能力，开发者无需进行视频实例的创建，视频信息的设置获取，只需要设置数据源以及基础信息即可播放视频，相对扩展能力较弱。如果开发者想自定义视频播放，还请参考[媒体系统播放音视频](../media/video-playback.md)。

## 相关实例

针对Video组件开发，有以下相关实例可供参考：

- [视频播放（ArkTS）（API9）](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-3.2-Release/code/BasicFeature/Media/VideoShow)

- [简易视频播放器（ArkTS）（API9）](https://gitee.com/openharmony/codelabs/tree/master/Media/SimpleVideo)