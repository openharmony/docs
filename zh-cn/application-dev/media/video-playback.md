# 视频播放

在OpenHarmony系统中，提供两种视频播放开发的方案：

- [AVPlayer](using-avplayer-for-playback.md)：功能较完善的音视频播放ArkTS/JS API，集成了流媒体和本地资源解析，媒体资源解封装，视频解码和渲染功能，适用于对媒体资源进行端到端播放的场景，可直接播放mp4、mkv等格式的视频文件。

- Video组件：封装了视频播放的基础能力，需要设置数据源以及基础信息即可播放视频，但相对扩展能力较弱。Video组件由ArkUI提供能力，相关指导请参考UI开发文档-[Video组件](../ui/arkts-common-components-video-player.md)。

本开发指导将介绍如何使用AVPlayer开发视频播放功能，以完整地播放一个视频作为示例，实现端到端播放原始媒体资源。如果要实现后台播放或熄屏播放，需要使用[AVSession（媒体会话）](avsession-overview.md)和[申请长时任务](../task-management/continuous-task.md)，避免播放过程中音频模块被系统强制中断。

## 开发指导

播放的全流程包含：创建AVPlayer，设置播放资源和窗口，设置播放参数（音量/倍速/缩放模式），播放控制（播放/暂停/跳转/停止），重置，销毁资源。在进行应用开发的过程中，开发者可以通过AVPlayer的state属性主动获取当前状态或使用on('stateChange')方法监听状态变化。如果应用在视频播放器处于错误状态时执行操作，系统可能会抛出异常或生成其他未定义的行为。

**图1** 播放状态变化示意图  

![Playback status change](figures/video-playback-status-change.png)

状态的详细说明请参考[AVPlayerState](../reference/apis/js-apis-media.md#avplayerstate9)。当播放处于prepared / playing / paused / completed状态时，播放引擎处于工作状态，这需要占用系统较多的运行内存。当客户端暂时不使用播放器时，调用reset()或release()回收内存资源，做好资源利用。

### 开发步骤及注意事项

详细的API说明请参考[AVPlayer API参考](../reference/apis/js-apis-media.md#avplayer9)。

1. 创建实例createAVPlayer()，AVPlayer初始化idle状态。

2. 设置业务需要的监听事件，搭配全流程场景使用。支持的监听事件包括：
   | 事件类型 | 说明 | 
   | -------- | -------- |
   | stateChange | 必要事件，监听播放器的state属性改变。 | 
   | error | 必要事件，监听播放器的错误信息。 | 
   | durationUpdate | 用于进度条，监听进度条长度，刷新资源时长。 | 
   | timeUpdate | 用于进度条，监听进度条当前位置，刷新当前时间。 | 
   | seekDone | 响应API调用，监听seek()请求完成情况。<br/>当使用seek()跳转到指定播放位置后，如果seek操作成功，将上报该事件。 | 
   | speedDone | 响应API调用，监听setSpeed()请求完成情况。<br/>当使用setSpeed()设置播放倍速后，如果setSpeed操作成功，将上报该事件。 | 
   | volumeChange | 响应API调用，监听setVolume()请求完成情况。<br/>当使用setVolume()调节播放音量后，如果setVolume操作成功，将上报该事件。 | 
   | bitrateDone | 响应API调用，用于HLS协议流，监听setBitrate()请求完成情况。<br/>当使用setBitrate()指定播放比特率后，如果setBitrate操作成功，将上报该事件。 | 
   | availableBitrates | 用于HLS协议流，监听HLS资源的可选bitrates，用于setBitrate()。 | 
   | bufferingUpdate | 用于网络播放，监听网络播放缓冲信息。 | 
   | startRenderFrame | 用于视频播放，监听视频播放首帧渲染时间。 | 
   | videoSizeChange | 用于视频播放，监听视频播放的宽高信息，可用于调整窗口大小、比例。 | 
   | audioInterrupt | 监听音频焦点切换信息，搭配属性audioInterruptMode使用。<br/>如果当前设备存在多个媒体正在播放，音频焦点被切换（即播放其他媒体如通话等）时将上报该事件，应用可以及时处理。 | 

3. 设置资源：设置属性url，AVPlayer进入initialized状态。
   > **说明：**
   >
   > 下面代码示例中的url仅作示意使用，开发者需根据实际情况，确认资源有效性并设置：
   > 
   > - 如果使用本地资源播放，必须确认资源文件可用，并使用应用沙箱路径访问对应资源，参考[获取应用文件路径](../application-models/application-context-stage.md#获取应用文件路径)。应用沙箱的介绍及如何向应用沙箱推送文件，请参考[文件管理](../file-management/app-sandbox-directory.md)。
   > 
   > - 如果使用网络播放路径，需[申请相关权限](../security/accesstoken-guidelines.md)：ohos.permission.INTERNET。
   > 
   > - 如果使用ResourceManager.getRawFd打开HAP资源文件描述符，使用方法可参考[ResourceManager API参考](../reference/apis/js-apis-resource-manager.md#getrawfd9)。
   > 
   > - 需要使用[支持的播放格式与协议](avplayer-avrecorder-overview.md#支持的格式与协议)。

4. 设置窗口：获取并设置属性SurfaceID，用于设置显示画面。
   应用需要从XComponent组件获取surfaceID，获取方式请参考[XComponent](../reference/arkui-ts/ts-basic-components-xcomponent.md)。

5. 准备播放：调用prepare()，AVPlayer进入prepared状态，此时可以获取duration，设置缩放模式、音量等。

6. 视频播控：播放play()，暂停pause()，跳转seek()，停止stop() 等操作。

7. （可选）更换资源：调用reset()重置资源，AVPlayer重新进入idle状态，允许更换资源url。

8. 退出播放：调用release()销毁实例，AVPlayer进入released状态，退出播放。


### 完整示例

  
```ts
import media from '@ohos.multimedia.media';
import fs from '@ohos.file.fs';
import common from '@ohos.app.ability.common';

export class AVPlayerDemo {
  private avPlayer;
  private count: number = 0;
  private surfaceID: string; // surfaceID用于播放画面显示，具体的值需要通过Xcomponent接口获取，相关文档链接见上面Xcomponent创建方法

  // 注册avplayer回调函数
  setAVPlayerCallback() {
    // seek操作结果回调函数
    this.avPlayer.on('seekDone', (seekDoneTime) => {
      console.info(`AVPlayer seek succeeded, seek time is ${seekDoneTime}`);
    })
    // error回调监听函数,当avPlayer在操作过程中出现错误时调用reset接口触发重置流程
    this.avPlayer.on('error', (err) => {
      console.error(`Invoke avPlayer failed, code is ${err.code}, message is ${err.message}`);
      this.avPlayer.reset(); // 调用reset重置资源，触发idle状态
    })
    // 状态机变化回调函数
    this.avPlayer.on('stateChange', async (state, reason) => {
      switch (state) {
        case 'idle': // 成功调用reset接口后触发该状态机上报
          console.info('AVPlayer state idle called.');
          this.avPlayer.release(); // 调用release接口销毁实例对象
          break;
        case 'initialized': // avplayer 设置播放源后触发该状态上报
          console.info('AVPlayerstate initialized called.');
          this.avPlayer.surfaceId = this.surfaceID; // 设置显示画面，当播放的资源为纯音频时无需设置
          this.avPlayer.prepare().then(() => {
            console.info('AVPlayer prepare succeeded.');
          }, (err) => {
            console.error(`Invoke prepare failed, code is ${err.code}, message is ${err.message}`);
          });
          break;
        case 'prepared': // prepare调用成功后上报该状态机
          console.info('AVPlayer state prepared called.');
          this.avPlayer.play(); // 调用播放接口开始播放
          break;
        case 'playing': // play成功调用后触发该状态机上报
          console.info('AVPlayer state playing called.');
          if (this.count !== 0) {
            console.info('AVPlayer start to seek.');
            this.avPlayer.seek(this.avPlayer.duration); //seek到视频末尾
          } else {
            this.avPlayer.pause(); // 调用暂停接口暂停播放
          }
          this.count++;
          break;
        case 'paused': // pause成功调用后触发该状态机上报
          console.info('AVPlayer state paused called.');
          this.avPlayer.play(); // 再次播放接口开始播放
          break;
        case 'completed': // 播放结束后触发该状态机上报
          console.info('AVPlayer state completed called.');
          this.avPlayer.stop(); //调用播放结束接口
          break;
        case 'stopped': // stop接口成功调用后触发该状态机上报
          console.info('AVPlayer state stopped called.');
          this.avPlayer.reset(); // 调用reset接口初始化avplayer状态
          break;
        case 'released':
          console.info('AVPlayer state released called.');
          break;
        default:
          console.info('AVPlayer state unknown called.');
          break;
      }
    })
  }

  // 以下demo为使用fs文件系统打开沙箱地址获取媒体文件地址并通过url属性进行播放示例
  async avPlayerUrlDemo() {
    // 创建avPlayer实例对象
    this.avPlayer = await media.createAVPlayer();
    // 创建状态机变化回调函数
    this.setAVPlayerCallback();
    let fdPath = 'fd://';
    let context = getContext(this) as common.UIAbilityContext;
    // 通过UIAbilityContext获取沙箱地址filesDir，以Stage模型为例
    let pathDir = context.filesDir;
    let path = pathDir  + '/H264_AAC.mp4'; 
    // 打开相应的资源文件地址获取fd，并为url赋值触发initialized状态机上报
    let file = await fs.open(path);
    fdPath = fdPath + '' + file.fd;
    this.avPlayer.url = fdPath;
  }

  // 以下demo为使用资源管理接口获取打包在HAP内的媒体资源文件并通过fdSrc属性进行播放示例
  async avPlayerFdSrcDemo() {
    // 创建avPlayer实例对象
    this.avPlayer = await media.createAVPlayer();
    // 创建状态机变化回调函数
    this.setAVPlayerCallback();
    // 通过UIAbilityContext的resourceManager成员的getRawFd接口获取媒体资源播放地址
    // 返回类型为{fd,offset,length},fd为HAP包fd地址，offset为媒体资源偏移量，length为播放长度
    let context = getContext(this) as common.UIAbilityContext;
    let fileDescriptor = await context.resourceManager.getRawFd('H264_AAC.mp4');
    // 为fdSrc赋值触发initialized状态机上报
    this.avPlayer.fdSrc = fileDescriptor;
  }
}
```
