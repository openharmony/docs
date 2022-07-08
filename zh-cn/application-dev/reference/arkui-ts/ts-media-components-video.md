# Video

 用于播放单个视频并控制其播放状态的组件。 

>  **说明：**
>  该组件从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## 权限列表

使用网络视频时，需要在config或者module.json对应的"abilities"中添加网络使用权限ohos.permission.INTERNET。

```
"abilities":[
  {
    ...
    "permissions": ["ohos.permission.INTERNET"],
    ...
  }
]
```


## 子组件

不支持子组件。


## 接口

Video(value: VideoOptions)

- VideoOptions类型接口说明
  | 参数名                 | 参数类型                                     | 必填   | 默认值                                      | 参数描述                                     |
  | ------------------- | ---------------------------------------- | ---- | ---------------------------------------- | ---------------------------------------- |
  | src                 | string \| [Resource](../../ui/ts-types.md) | 否    | -                                        | 视频播放源的路径，支持本地视频路径和网络路径。<br>支持在resources下面的video或rawfile文件夹里放置媒体资源。<br>支持dataability://的路径前缀，用于访问通过Data Ability提供的视频路径，具体路径信息详见[Data Ability说明](../../ability/fa-dataability.md)。 |
  | currentProgressRate | number&nbsp;\|&nbsp;PlaybackSpeed<sup>8+</sup> | 否    | 1.0&nbsp;\|&nbsp;PlaybackSpeed.<br>Speed_Forward_1_00_X | 视频播放倍速。<br/>>&nbsp;&nbsp;**说明：**<br/>>&nbsp;number取值仅支持：0.75，1.0，1.25，1.75，2.0。<br/> |
  | previewUri          | string&nbsp;\|&nbsp;PixelMap<sup>8+</sup>&nbsp;\|&nbsp;[Resource](../../ui/ts-types.md) | 否    | -                                        | 预览图片的路径。                                 |
  | controller          | [VideoController](#videocontroller)      | 否    | -                                        | 控制器。                                     |


- PlaybackSpeed<sup>8+</sup>类型接口说明
  | 名称                   | 描述        |
  | -------------------- | --------- |
  | Speed_Forward_0_75_X | 0.75倍速播放。 |
  | Speed_Forward_1_00_X | 1倍速播放。    |
  | Speed_Forward_1_25_X | 1.25倍速播放。 |
  | Speed_Forward_1_75_X | 1.75倍速播放。 |
  | Speed_Forward_2_00_X | 2倍速播放。    |


## 属性

| 名称        | 参数类型                                     | 默认值   | 描述              |
| --------- | ---------------------------------------- | ----- | --------------- |
| muted     | boolean                                  | false | 是否静音。           |
| autoPlay  | boolean                                  | false | 是否自动播放。         |
| controls  | boolean                                  | true  | 控制视频播放的控制栏是否显示。 |
| objectFit | [ImageFit](ts-basic-components-image.md) | Cover | 设置视频显示模式。       |
| loop      | boolean                                  | false | 是否单个视频循环播放。     |


## 事件

| 名称                                       | 功能描述                                     |
| ---------------------------------------- | ---------------------------------------- |
| onStart()&nbsp;=&gt;&nbsp;void           | 播放时触发该事件。                                |
| onPause()&nbsp;=&gt;&nbsp;void           | 暂停时触发该事件。                                |
| onFinish()&nbsp;=&gt;&nbsp;void          | 播放结束时触发该事件。                              |
| onError()&nbsp;=&gt;&nbsp;void           | 播放失败时触发该事件。                              |
| onPrepared(event?:&nbsp;{&nbsp;duration:&nbsp;number&nbsp;})&nbsp;=&gt;&nbsp;void | 视频准备完成时触发该事件，通过duration可以获取视频时长，单位为秒(s)。 |
| onSeeking(event?:&nbsp;{&nbsp;time:&nbsp;number&nbsp;})&nbsp;=&gt;&nbsp;void | 操作进度条过程时上报时间信息，单位为s。                     |
| onSeeked(event?:&nbsp;{&nbsp;time:&nbsp;number&nbsp;})&nbsp;=&gt;&nbsp;void | 操作进度条完成后，上报播放时间信息，单位为s。                  |
| onUpdate(event?:&nbsp;{&nbsp;time:&nbsp;number&nbsp;})&nbsp;=&gt;&nbsp;void | 播放进度变化时触发该事件，单位为s，更新时间间隔为250ms。          |


## VideoController

一个VideoController对象可以控制一个或多个video。


### 导入对象

```
controller: VideoController = new VideoController();
```


### start

start(): void

开始播放。

### pause

pause(): void

暂停播放。

### stop

stop(): void

停止播放。

### setCurrentTime

setCurrentTime(value: number)

指定视频播放的进度位置。

- 参数
  | 参数名   | 参数类型   | 必填   | 默认值  | 参数描述      |
  | ----- | ------ | ---- | ---- | --------- |
  | value | number | 是    | -    | 视频播放进度位置。 |

### requestFullscreen

requestFullscreen(value: boolean)

请求全屏播放。

- 参数
  | 参数名   | 参数类型   | 必填   | 默认值   | 参数描述    |
  | ----- | ------ | ---- | ----- | ------- |
  | value | boolean | 是    | false | 是否全屏播放。 |

### exitFullscreen

exitFullscreen()

退出全屏播放。

### setCurrentTime<sup>8+</sup>

setCurrentTime(value: number, seekMode: SeekMode)

指定视频播放的进度位置，并指定跳转模式。

- 参数
  | 参数名      | 参数类型     | 必填   | 默认值  | 参数描述      |
  | -------- | -------- | ---- | ---- | --------- |
  | value    | number   | 是    | -    | 视频播放进度位置。 |
  | seekMode | SeekMode | 是    | -    | 跳转模式。     |

- SeekMode<sup>8+</sup>类型接口说明
  | 名称               | 描述             |
  | ---------------- | -------------- |
  | PreviousKeyframe | 跳转到前一个最近的关键帧。  |
  | NextKeyframe     | 跳转到后一个最近的关键帧。  |
  | ClosestKeyframe  | 跳转到最近的关键帧。     |
  | Accurate         | 精准跳转，不论是否为关键帧。 |



## 示例

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
