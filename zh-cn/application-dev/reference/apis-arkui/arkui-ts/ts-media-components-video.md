# Video

用于播放视频文件并控制其播放状态的组件。 

>  **说明：**
>
>  该组件从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## 权限列表

使用网络视频时，需要申请权限ohos.permission.INTERNET。具体申请方式请参考[声明权限](../../../security/AccessToken/declare-permissions.md)。


## 子组件

不支持子组件。


## 接口

Video(value: VideoOptions)

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**参数：**

| 参数名 | 参数类型 | 必填 | 参数描述 |
| -------- | -------- | -------- | -------- |
| value | [VideoOptions](#videooptions对象说明) | 是 | 视频信息。 |

##  VideoOptions对象说明

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

| 参数名              | 参数类型                                                     | 必填 | 参数描述                                                     |
| ------------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| src                 | string \| [Resource](ts-types.md#resource)                            | 否   | 视频播放源的路径，支持本地视频路径和网络路径。<br>支持在resources下面的video或rawfile文件夹里放置媒体资源。<br>支持dataability://的路径前缀，用于访问通过Data Ability提供的视频路径，具体路径信息详见 [DataAbility说明](../../../application-models/dataability-overview.md)。<br/>- 支持file:///data/storage路径前缀的字符串，用于读取应用沙箱路径内的资源。需要保证目录包路径下的文件有可读权限。<br/>**说明：**<br/>视频支持的格式是：mp4、mkv、TS。 |
| currentProgressRate | number&nbsp;\|&nbsp;string&nbsp;\|&nbsp;[PlaybackSpeed<sup>8+</sup>](#playbackspeed8枚举说明) | 否   | 视频播放倍速。<br/>**说明：**<br/>number取值仅支持：0.75，1.0，1.25，1.75，2.0。<br/>默认值：1.0 \| PlaybackSpeed.Speed_Forward_1_00_X |
| previewUri          | string&nbsp;\| [PixelMap](../../apis-image-kit/js-apis-image.md#pixelmap7)&nbsp;\|&nbsp;[Resource](ts-types.md)  | 否   | 视频未播放时的预览图片路径，默认不显示图片。                 |
| controller          | [VideoController](#videocontroller)                          | 否   | 设置视频控制器，可以控制视频的播放状态。                     |


## PlaybackSpeed<sup>8+</sup>枚举说明

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

| 名称                   | 描述        |
| -------------------- | --------- |
| Speed_Forward_0_75_X | 0.75倍速播放。 |
| Speed_Forward_1_00_X | 1倍速播放。    |
| Speed_Forward_1_25_X | 1.25倍速播放。 |
| Speed_Forward_1_75_X | 1.75倍速播放。 |
| Speed_Forward_2_00_X | 2倍速播放。    |

## 属性

除支持[通用属性](ts-universal-attributes-size.md)外，还支持以下属性：

### muted

muted(value: boolean)

设置是否静音。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型    | 必填 | 说明                         |
| ------ | ------- | ---- | ---------------------------- |
| value  | boolean | 是   | 是否静音。<br/>默认值：false |

### autoPlay

autoPlay(value: boolean)

设置是否自动播放。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型    | 必填 | 说明                             |
| ------ | ------- | ---- | -------------------------------- |
| value  | boolean | 是   | 是否自动播放。<br/>默认值：false |

### controls

controls(value: boolean)

设置控制视频播放的控制栏是否显示。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型    | 必填 | 说明                                            |
| ------ | ------- | ---- | ----------------------------------------------- |
| value  | boolean | 是   | 控制视频播放的控制栏是否显示。<br/>默认值：true |

### objectFit

objectFit(value: ImageFit)

设置视频显示模式。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                      | 必填 | 说明                             |
| ------ | ----------------------------------------- | ---- | -------------------------------- |
| value  | [ImageFit](ts-appendix-enums.md#imagefit) | 是   | 视频显示模式。<br/>默认值：Cover |

### loop

loop(value: boolean)

设置是否单个视频循环播放。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型    | 必填 | 说明                                     |
| ------ | ------- | ---- | ---------------------------------------- |
| value  | boolean | 是   | 是否单个视频循环播放。<br/>默认值：false |

### enableAnalyzer<sup>12+</sup>

enableAnalyzer(enable: boolean)

设置组件支持AI分析。使能后，视频播放暂停时自动进入分析状态，开始分析当前画面帧，视频继续播放后自动退出分析状态。
不能和[overlay](ts-universal-attributes-overlay.md)属性同时使用，两者同时设置时overlay中CustomBuilder属性将失效。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| enable | boolean | 是 | 是否启用AI分析功能 |

> **说明：**
>
> 当前仅在使用自定义控制栏([controls](#controls)属性设置为false)时支持该功能。
> 该特性依赖设备能力。

### analyzerConfig<sup>12+</sup>

analyzerConfig(config: ImageAnalyzerConfig)

设置AI分析识别类型，包括主体识别和文字识别功能，默认全部开启。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| config | [ImageAnalyzerConfig](ts-image-common.md#imageanalyzerconfig12) | 是 | 设置AI分析识别类型 |

## 事件

除支持[通用事件](ts-universal-events-click.md)外，还支持以下事件：

### onStart

onStart(event:()&nbsp;=&gt;&nbsp;void)

播放时触发该事件。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### onPause

onPause(event:()&nbsp;=&gt;&nbsp;void)

暂停时触发该事件。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### onFinish

onFinish(event:()&nbsp;=&gt;&nbsp;void)

播放结束时触发该事件。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### onError

onError(event:()&nbsp;=&gt;&nbsp;void)

播放失败时触发该事件。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### onStop<sup>12+</sup>

onStop(event:()&nbsp;=&gt;&nbsp;void)

播放停止时触发该事件(当stop()方法被调用后触发)。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### onPrepared

onPrepared(callback:(event:&nbsp;{&nbsp;duration:&nbsp;number&nbsp;})&nbsp;=&gt;&nbsp;void)

视频准备完成时触发该事件。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名   | 类型   | 必填 | 说明                       |
| -------- | ------ | ---- | -------------------------- |
| duration | number | 是   | 当前视频的时长，单位为秒。 |

### onSeeking

onSeeking(callback:(event:&nbsp;{&nbsp;time:&nbsp;number&nbsp;})&nbsp;=&gt;&nbsp;void)

操作进度条过程时上报时间信息。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型   | 必填 | 说明                           |
| ------ | ------ | ---- | ------------------------------ |
| time   | number | 是   | 当前视频播放的进度，单位为秒。 |

### onSeeked

onSeeked(callback:(event:&nbsp;{&nbsp;time:&nbsp;number&nbsp;})&nbsp;=&gt;&nbsp;void)

操作进度条完成后，上报播放时间信息。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型   | 必填 | 说明                           |
| ------ | ------ | ---- | ------------------------------ |
| time   | number | 是   | 当前视频播放的进度，单位为秒。 |

### onUpdate

onUpdate(callback:(event:&nbsp;{&nbsp;time:&nbsp;number&nbsp;})&nbsp;=&gt;&nbsp;void)

播放进度变化时触发该事件。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型   | 必填 | 说明                           |
| ------ | ------ | ---- | ------------------------------ |
| time   | number | 是   | 当前视频播放的进度，单位为秒。 |

### onFullscreenChange

onFullscreenChange(callback:(event:&nbsp;{&nbsp;fullscreen:&nbsp;boolean&nbsp;})&nbsp;=&gt;&nbsp;void)

在全屏播放与非全屏播放状态之间切换时触发该事件。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名     | 类型    | 必填 | 说明                                                  |
| ---------- | ------- | ---- | ----------------------------------------------------- |
| fullscreen | boolean | 是   | 为true表示进入全屏播放状态，为false则表示非全屏播放。 |


## VideoController

一个VideoController对象可以控制一个或多个video，可用视频播放实例请参考[@ohos.multimedia.media](../../apis-media-kit/js-apis-media.md)。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。


### 导入对象

```ts
let controller: VideoController = new VideoController()
```


### start

start(): void

开始播放。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

### pause

pause(): void

暂停播放，显示当前帧，再次播放时从当前位置继续播放。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

### stop

stop(): void

停止播放，显示当前帧，再次播放时从头开始播放。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

### setCurrentTime

setCurrentTime(value: number)

指定视频播放的进度位置。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**参数：**

| 参数名   | 参数类型   | 必填   | 参数描述           |
| ----- | ------ | ---- | -------------- |
| value | number | 是    | 视频播放进度位置，单位为s。 |

### requestFullscreen

requestFullscreen(value: boolean)

请求全屏播放。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**参数：**

| 参数名 | 参数类型 | 必填 | 参数描述                         |
| ------ | -------- | ---- | -------------------------------- |
| value  | boolean  | 是   | 是否全屏（填充满应用窗口）播放。 |

### exitFullscreen

exitFullscreen()

退出全屏播放。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

### setCurrentTime<sup>8+</sup>

setCurrentTime(value: number, seekMode: SeekMode)

指定视频播放的进度位置，并指定跳转模式。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**参数：**

| 参数名      | 参数类型     | 必填   | 参数描述           |
| -------- | -------- | ---- | -------------- |
| value    | number   | 是    | 视频播放进度位置，单位为s。 |
| seekMode | [SeekMode](#seekmode8枚举说明) | 是    | 跳转模式。          |

## SeekMode<sup>8+</sup>枚举说明

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

| 名称               | 描述             |
| ---------------- | -------------- |
| PreviousKeyframe | 跳转到前一个最近的关键帧。  |
| NextKeyframe     | 跳转到后一个最近的关键帧。  |
| ClosestKeyframe  | 跳转到最近的关键帧。     |
| Accurate         | 精准跳转，不论是否为关键帧。 |

## 示例

### 示例1

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
          this.videoSrc = $rawfile('video2.mp4') // 切换视频源
        }).margin(5)
        Button('previewUri').onClick(() => {
          this.previewUri = $r('app.media.poster2') // 切换视频预览海报
        }).margin(5)
        Button('controls').onClick(() => {
          this.showControls = !this.showControls // 切换是否显示视频控制栏
        }).margin(5)
      }

      Row() {
        Button('start').onClick(() => {
          this.controller.start() // 开始播放
        }).margin(5)
        Button('pause').onClick(() => {
          this.controller.pause() // 暂停播放
        }).margin(5)
        Button('stop').onClick(() => {
          this.controller.stop() // 结束播放
        }).margin(5)
        Button('setTime').onClick(() => {
          this.controller.setCurrentTime(10, SeekMode.Accurate) // 精准跳转到视频的10s位置
        }).margin(5)
      }

      Row() {
        Button('rate 0.75').onClick(() => {
          this.curRate = PlaybackSpeed.Speed_Forward_0_75_X // 0.75倍速播放
        }).margin(5)
        Button('rate 1').onClick(() => {
          this.curRate = PlaybackSpeed.Speed_Forward_1_00_X // 原倍速播放
        }).margin(5)
        Button('rate 2').onClick(() => {
          this.curRate = PlaybackSpeed.Speed_Forward_2_00_X // 2倍速播放
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

### 示例2

图像分析功能使用示例。

```ts
// xxx.ets
@Entry
@Component
struct ImageAnalyzerExample {
  @State videoSrc: Resource = $rawfile('video1.mp4')
  @State previewUri: Resource = $r('app.media.poster1')
  @State showControls: boolean = true
  controller: VideoController = new VideoController()
  config: ImageAnalyzerConfig = {
    types: [ImageAnalyzerType.SUBJECT, ImageAnalyzerType.TEXT]
  }

  build() {
    Column() {
      Video({
        src: this.videoSrc,
        previewUri: this.previewUri,
        controller: this.controller
      })
        .width('100%')
        .height(600)
        .controls(false)
        .enableAnalyzer(true)
        .analyzerConfig(this.config)
        .onStart(() => {
          console.info('onStart')
        })
        .onPause(() => {
          console.info('onPause')
        })

      Row() {
        Button('start').onClick(() => {
          this.controller.start() // 开始播放
        }).margin(5)
        Button('pause').onClick(() => {
          this.controller.pause() // 暂停播放
        }).margin(5)
      }
    }
  }
}
```