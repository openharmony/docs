# video    
用于播放视频文件并控制其播放状态的组件。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
 **子组件**   
无  
    
## SeekMode<sup>(8+)</sup>    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| PreviousKeyframe | 0 | 跳转到前一个最近的关键帧。 |  
| NextKeyframe | 1 | 跳转到后一个最近的关键帧。 |  
| ClosestKeyframe | 2 | 跳转到最近的关键帧。 |  
| Accurate | 3 | 精准跳转，不论是否为关键帧。 |  
    
## PlaybackSpeed<sup>(8+)</sup>    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| Speed_Forward_0_75_X | 0 | 0.75倍速播放。 |  
| Speed_Forward_1_00_X | 1 | 1倍速播放。 |  
| Speed_Forward_1_25_X | 2 | 1.25倍速播放。 |  
| Speed_Forward_1_75_X | 3 | 1.75倍速播放。 |  
| Speed_Forward_2_00_X | 4 | 2倍速播放。 |  
    
## VideoOptions  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| src | string \| Resource | false | false | 视频播放源的路径，支持本地视频路径和网络路径。<br>支持在resources下面的video或rawfile文件夹里放置媒体资源。<br>支持dataability://的路径前缀，用于访问通过Data Ability提供的视频路径，具体路径信息详见 [DataAbility说明](../../application-models/dataability-overview.md)。<br/>- 支持file:///data/storage路径前缀的字符串，用于读取应用沙箱路径内的资源。需要保证目录包路径下的文件有可读权限。<br/>**说明：**<br/>视频支持的格式是：mp4、mkv、webm、TS。 |  
| currentProgressRate | number \| string \| PlaybackSpeed | false | false | 视频播放倍速。<br/>**说明：**<br/>number取值仅支持：0.75，1.0，1.25，1.75，2.0。<br/>默认值：1.0 \| PlaybackSpeed.Speed_Forward_1_00_X |  
| previewUri | string \| PixelMap \| Resource | false | false | 视频未播放时的预览图片路径，默认不显示图片。 |  
| controller | VideoController | false | false | 设置视频控制器，可以控制视频的播放状态。 |  
    
## VideoController    
一个VideoController对象可以控制一个或多个video，可用视频播放实例请参考[ia](../apis/js-apis-media.md#mediacreateavplayer9)。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### start    
开始播放。  
 **调用形式：**     
- start()  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### pause    
暂停播放，显示当前帧，再次播放时从当前位置继续播放。  
 **调用形式：**     
- pause()  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### stop    
停止播放，显示当前帧，再次播放时从头开始播放。  
 **调用形式：**     
- stop()  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### setCurrentTime    
指定视频播放的进度位置，并指定跳转模式。  
 **调用形式：**     
- setCurrentTime(value: number)  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | number | true | 视频播放进度位置，单位为s。 |  
    
### requestFullscreen    
请求全屏播放。  
 **调用形式：**     
- requestFullscreen(value: boolean)  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | boolean | true | 是否全屏（填充满应用窗口）播放。 |  
    
### exitFullscreen    
退出全屏播放。  
 **调用形式：**     
- exitFullscreen()  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
## 接口  
  
  
    
 **调用形式**     
    
- Video(value: VideoOptions)    
起始版本： 7    
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | VideoOptions | true |  |  
    
## 属性  
    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 说明 |  
| --------| --------| --------|  
| muted |  boolean |  |  
| autoPlay |  boolean |  |  
| controls |  boolean |  |  
| loop<sup>10+</sup> |  boolean |  |  
| objectFit |  ImageFit |  |  
    
### onStart<sup>(deprecated)</sup>    
onStart(event: () => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event | () => void | true |  |  
    
### onPause<sup>(deprecated)</sup>    
onPause(event: () => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event | () => void | true |  |  
    
### onFinish<sup>(deprecated)</sup>    
onFinish(event: () => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event | () => void | true |  |  
    
### onFullscreenChange<sup>(deprecated)</sup>    
onFullscreenChange(callback: (event: {     /**      * Play the flag in full screen.      *      * @syscap SystemCapability.ArkUI.ArkUI.Full      * @crossplatform      * @since 10      */     fullscreen: boolean   }) => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
### onPrepared<sup>(deprecated)</sup>    
onPrepared(callback: (event: {     /**      * Playback duration.      *      * @syscap SystemCapability.ArkUI.ArkUI.Full      * @crossplatform      * @since 10      */     duration: number   }) => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
### onSeeking<sup>(deprecated)</sup>    
onSeeking(callback: (event: {     /**      * Play time.      *      * @syscap SystemCapability.ArkUI.ArkUI.Full      * @crossplatform      * @since 10      */     time: number   }) => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
### onSeeked<sup>(deprecated)</sup>    
onSeeked(callback: (event: {     /**      * Play time.      *      * @syscap SystemCapability.ArkUI.ArkUI.Full      * @crossplatform      * @since 10      */     time: number   }) => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
### onUpdate<sup>(deprecated)</sup>    
onUpdate(callback: (event: {     /**      * Play time.      *      * @syscap SystemCapability.ArkUI.ArkUI.Full      * @crossplatform      * @since 10      */     time: number   }) => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
### onError<sup>(deprecated)</sup>    
onError(event: () => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event | () => void | true |  |  
    
 **示例代码：**   
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
  
