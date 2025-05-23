# 使用AVPlayer播放视频(ArkTS)

当前提供两种视频播放开发的方案：

- [AVPlayer](media-kit-intro.md#avplayer)：功能较完善的音视频播放ArkTS/JS API，集成了流媒体和本地资源解析，媒体资源解封装，视频解码和渲染功能，适用于对媒体资源进行端到端播放的场景，可直接播放mp4、mkv等格式的视频文件。

- Video组件：封装了视频播放的基础能力，需要设置数据源以及基础信息即可播放视频，但相对扩展能力较弱。Video组件由ArkUI提供能力，相关指导请参考UI开发文档-[Video组件](../../ui/arkts-common-components-video-player.md)。

本开发指导将介绍如何使用AVPlayer开发视频播放功能，以完整地播放一个视频作为示例，实现端到端播放原始媒体资源。

播放的全流程包含：创建AVPlayer，设置播放资源和窗口，设置播放参数（音量/倍速/缩放模式），播放控制（播放/暂停/跳转/停止），重置，销毁资源。在进行应用开发的过程中，开发者可以通过AVPlayer的state属性主动获取当前状态或使用on('stateChange')方法监听状态变化。如果应用在视频播放器处于错误状态时执行操作，系统可能会抛出异常或生成其他未定义的行为。

**图1** 播放状态变化示意图  

![Playback status change](figures/video-playback-status-change.png)

状态的详细说明请参考[AVPlayerState](../../reference/apis-media-kit/js-apis-media.md#avplayerstate9)。当播放处于prepared / playing / paused / completed状态时，播放引擎处于工作状态，这需要占用系统较多的运行内存。当客户端暂时不使用播放器时，调用reset()或release()回收内存资源，做好资源利用。

## 开发建议

当前指导仅介绍如何实现媒体资源播放，在应用开发过程中可能会涉及后台播放、播放冲突等情况，请根据实际需要参考以下说明。

- 如果要实现后台播放或熄屏播放，需要接入[AVSession（媒体会话）](../avsession/avsession-access-scene.md)和[申请长时任务](../../task-management/continuous-task.md)，避免播放被系统强制中断。
- 应用在播放过程中，若播放的媒体数据涉及音频，根据系统音频管理策略（参考[处理音频焦点事件](../audio/audio-playback-concurrency.md)），可能会被其他应用打断，建议应用主动监听音频打断事件，根据其内容提示，做出相应的处理，避免出现应用状态与预期效果不一致的问题。
- 面对设备同时连接多个音频输出设备的情况，应用可以通过[on('audioOutputDeviceChangeWithInfo')](../../reference/apis-media-kit/js-apis-media.md#onaudiooutputdevicechangewithinfo11)监听音频输出设备的变化，从而做出相应处理。
- 如果需要访问在线媒体资源，需要申请 ohos.permission.INTERNET 权限。

## 开发步骤及注意事项

详细的API说明请参考[AVPlayer API参考](../../reference/apis-media-kit/js-apis-media.md#avplayer9)。

1. 调用createAVPlayer()创建AVPlayer实例，初始化进入idle状态。

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
   | startRenderFrame | 用于视频播放，监听视频播放首帧渲染时间。<br/>当AVPlayer首次起播进入playing状态后，等到首帧视频画面被渲染到显示画面时，将上报该事件。应用通常可以利用此事件上报，进行视频封面移除，达成封面与视频画面的顺利衔接。 |
   | videoSizeChange | 用于视频播放，监听视频播放的宽高信息，可用于调整窗口大小、比例。 |
   | audioInterrupt | 监听音频焦点切换信息，搭配属性audioInterruptMode使用。<br/>如果当前设备存在多个媒体正在播放，音频焦点被切换（即播放其他媒体如通话等）时将上报该事件，应用可以及时处理。 |

3. 设置资源：设置属性url，AVPlayer进入initialized状态。
   > **说明：**
   >
   > 下面代码示例中的url仅作示意使用，开发者需根据实际情况，确认资源有效性并设置：
   > 
   > - 如果使用本地资源播放，必须确认资源文件可用，并使用应用沙箱路径访问对应资源，参考[获取应用文件路径](../../application-models/application-context-stage.md#获取应用文件路径)。应用沙箱的介绍及如何向应用沙箱推送文件，请参考[文件管理](../../file-management/app-sandbox-directory.md)。
   > 
   > - 如果使用网络播放路径，需[声明权限](../../security/AccessToken/declare-permissions.md)：ohos.permission.INTERNET。
   > 
   > - 如果使用ResourceManager.getRawFd打开HAP资源文件描述符，使用方法可参考[ResourceManager API参考](../../reference/apis-localization-kit/js-apis-resource-manager.md#getrawfd9)。
   > 
   > - 需要使用[支持的播放格式与协议](media-kit-intro.md#支持的格式与协议)。

4. 设置窗口：获取并设置属性SurfaceID，用于设置显示画面。
   应用需要从XComponent组件获取surfaceID，获取方式请参考[XComponent](../../reference/apis-arkui/arkui-ts/ts-basic-components-xcomponent.md)。

5. 准备播放：调用prepare()，AVPlayer进入prepared状态，此时可以获取duration，设置缩放模式、音量等。

6. 视频播控：播放play()，暂停pause()，跳转seek()，停止stop() 等操作。

7. （可选）更换资源：调用reset()重置资源，AVPlayer重新进入idle状态，允许更换资源url。

8. 退出播放：调用release()销毁实例，AVPlayer进入released状态，退出播放。

## 运行完整示例

1. 新建工程，下载[示例工程](https://gitee.com/openharmony/applications_app_samples/tree/master/code/DocsSample/Media/AVPlayer/AVPlayerArkTSVideo)，并将示例工程的以下资源复制到对应目录。
    ```
    AVPlayerArkTSVideo
    entry/src/main/ets/
    └── pages
        └── Index.ets (播放界面)
    entry/src/main/resources/
    ├── base
    │   ├── element
    │   │   ├── color.json
    │   │   ├── float.json
    │   │   └── string.json
    │   └── media
    │       ├── ic_video_play.svg  (播放键图片资源)
    │       └── ic_video_pause.svg (暂停键图片资源)
    └── rawfile
        └── test1.mp4 （视频资源）
    ```
2. 编译新建工程并运行。

## 开发示例

```ts
import display from '@ohos.display';
import emitter from '@ohos.events.emitter';
import { common } from '@kit.AbilityKit';
import media from '@ohos.multimedia.media';

...

@Entry
@Component
struct Index {
  private avPlayer: media.AVPlayer | null = null;
  private context: common.UIAbilityContext | undefined = undefined;
  @State fileName: string = 'test1.mp4';
  ...

  getDurationTime(): number {
    return this.durationTime;
  }

  getCurrentTime(): number {
    return this.currentTime;
  }

  timeConvert(time: number): string {
    let min: number = Math.floor(time / TIME_ONE);
    let second: string = ((time % TIME_ONE) / TIME_TWO).toFixed(0);
    // return `${min}:${(+second < TIME_THREE ? '0' : '') + second}`;
    second = second.padStart(2, '0');
    return `${min}:${second}`;
  }

  async msleepAsync(ms: number): Promise<boolean> {
    return new Promise((resolve, reject) => {
      setTimeout(() => {
        resolve(true)
      }, ms)
    })
  }

  async avSetupVideo() {
    // 通过UIAbilityContext的resourceManager成员的getRawFd接口获取媒体资源播放地址。
    // 返回类型为{fd,offset,length},fd为HAP包fd地址，offset为媒体资源偏移量，length为播放长度。
    if (this.context == undefined) return;
    let fileDescriptor = await this.context.resourceManager.getRawFd(this.fileName);
    let avFileDescriptor: media.AVFileDescriptor =
      { fd: fileDescriptor.fd, offset: fileDescriptor.offset, length: fileDescriptor.length };

    if (this.avPlayer) {
      console.info(`${this.tag}: init avPlayer release2createNew`);
      this.avPlayer.release();
      await this.msleepAsync(1500);
    }
    // 创建avPlayer实例对象
    this.avPlayer = await media.createAVPlayer();

    // 创建状态机变化回调函数
    await this.setAVPlayerCallback((avPlayer: media.AVPlayer) => {
      this.percent = avPlayer.width / avPlayer.height;
      this.setVideoWH();
      this.durationTime = this.getDurationTime();
      setInterval(() => { // 更新当前时间
        if (!this.isSwiping) {
          this.currentTime = this.getCurrentTime();
        }
      }, SET_INTERVAL);
    });

    // 为fdSrc赋值触发initialized状态机上报
    this.avPlayer.fdSrc = avFileDescriptor;
  }

  avPlay(): void {
    if (this.avPlayer) {
      try {
        this.avPlayer.play();
      } catch (e) {
        console.error(`${this.tag}: avPlay = ${JSON.stringify(e)}`);
      }
    }
  }

  avPause(): void {
    if (this.avPlayer) {
      try {
        this.avPlayer.pause();
        console.info(`${this.tag}: avPause==`);
      } catch (e) {
        console.info(`${this.tag}: avPause== ${JSON.stringify(e)}`);
      }
    }
  }

  async avSeek(seekTime: number, mode: SliderChangeMode): Promise<void> {
    if (this.avPlayer) {
      try {
        console.info(`${this.tag}: videoSeek  seekTime== ${seekTime}`);
        this.avPlayer.seek(seekTime, 2);
        this.currentTime = seekTime;
      } catch (e) {
        console.info(`${this.tag}: videoSeek== ${JSON.stringify(e)}`);
      }
    }
  }

  avSetSpeed(speed: number): void {
    if (this.avPlayer) {
      try {
        this.avPlayer.setSpeed(speed);
        console.info(`${this.tag}: avSetSpeed enum ${speed}`);
      } catch (e) {
        console.info(`${this.tag}: avSetSpeed == ${JSON.stringify(e)}`);
      }
    }
  }

  // 注册avplayer回调函数
  async setAVPlayerCallback(callback: (avPlayer: media.AVPlayer) => void, vType?: number): Promise<void> {
    // seek操作结果回调函数
    if (this.avPlayer == null) {
      console.info(`${this.tag}: avPlayer has not init!`);
      return;
    }
    this.avPlayer.on('seekDone', (seekDoneTime) => {
      console.info(`${this.tag}: setAVPlayerCallback AVPlayer seek succeeded, seek time is ${seekDoneTime}`);
    });
    this.avPlayer.on('speedDone', (speed) => {
      console.info(`${this.tag}: setAVPlayerCallback AVPlayer speedDone, speed is ${speed}`);
    });
    // error回调监听函数,当avPlayer在操作过程中出现错误时调用reset接口触发重置流程
    this.avPlayer.on('error', (err) => {
      console.error(`${this.tag}: setAVPlayerCallback Invoke avPlayer failed ${JSON.stringify(err)}`);
      if (this.avPlayer == null) {
        console.info(`${this.tag}: avPlayer has not init on error`);
        return;
      }
      this.avPlayer.reset();
    });
    // 状态机变化回调函数
    this.avPlayer.on('stateChange', async (state, reason) => {
      if (this.avPlayer == null) {
        console.info(`${this.tag}: avPlayer has not init on state change`);
        return;
      }
      switch (state) {
        case 'idle': // 成功调用reset接口后触发该状态机上报
          console.info(`${this.tag}: setAVPlayerCallback AVPlayer state idle called.`);
          break;
        case 'initialized': // avplayer 设置播放源后触发该状态上报
          console.info(`${this.tag}: setAVPlayerCallback AVPlayer state initialized called.`);
          if (this.surfaceId) {
            this.avPlayer.surfaceId = this.surfaceId; // 设置显示画面，当播放的资源为纯音频时无需设置
            console.info(`${this.tag}: setAVPlayerCallback this.avPlayer.surfaceId = ${this.avPlayer.surfaceId}`);
            this.avPlayer.prepare();
          }
          break;
        case 'prepared': // prepare调用成功后上报该状态机
          console.info(`${this.tag}: setAVPlayerCallback AVPlayer state prepared called.`);
          this.avPlayer.on('bufferingUpdate', (infoType: media.BufferingInfoType, value: number) => {
            console.info(`${this.tag}: bufferingUpdate called, infoType value: ${infoType}, value:${value}}`);
          })
          this.durationTime = this.avPlayer.duration;
          this.currentTime = this.avPlayer.currentTime;
          this.avPlayer.play(); // 调用播放接口开始播放
          console.info(`${this.tag}:
            setAVPlayerCallback speedSelect: ${this.speedSelect}, duration: ${this.durationTime}`);
          if (this.speedSelect != -1) {
            switch (this.speedSelect) {
              case SPEED_ZERO:
                this.avSetSpeed(media.PlaybackSpeed.SPEED_FORWARD_1_00_X);
                break;
              case SPEED_ONE:
                this.avSetSpeed(media.PlaybackSpeed.SPEED_FORWARD_1_25_X);
                break;
              case SPEED_TWO:
                this.avSetSpeed(media.PlaybackSpeed.SPEED_FORWARD_1_75_X);
                break;
              case SPEED_THREE:
                this.avSetSpeed(media.PlaybackSpeed.SPEED_FORWARD_2_00_X);
                break;
            }
          }
          callback(this.avPlayer);
          break;
        case 'playing': // play成功调用后触发该状态机上报
          console.info(`${this.tag}: setAVPlayerCallback AVPlayer state playing called.`);
          if (this.intervalID != -1) {
            clearInterval(this.intervalID)
          }
          this.intervalID = setInterval(() => { // 更新当前时间
            AppStorage.setOrCreate('durationTime', this.durationTime);
            AppStorage.setOrCreate('currentTime', this.currentTime);
          }, 100);
          let eventDataTrue: emitter.EventData = {
            data: {
              'flag': true
            }
          };
          let innerEventTrue: emitter.InnerEvent = {
            eventId: 2,
            priority: emitter.EventPriority.HIGH
          };
          emitter.emit(innerEventTrue, eventDataTrue);
          break;
        case 'completed': // 播放结束后触发该状态机上报
          console.info(`${this.tag}: setAVPlayerCallback AVPlayer state completed called.`);
          let eventDataFalse: emitter.EventData = {
            data: {
              'flag': false
            }
          };
          let innerEvent: emitter.InnerEvent = {
            eventId: 1,
            priority: emitter.EventPriority.HIGH
          };
          emitter.emit(innerEvent, eventDataFalse);
          if (this.intervalID != -1) {
            clearInterval(this.intervalID)
          }
          this.avPlayer.off('bufferingUpdate')
          AppStorage.setOrCreate('currentTime', this.durationTime);
          break;
        case 'released':
          console.info(`${this.tag}: setAVPlayerCallback released called.`);
          break
        case 'stopped':
          console.info(`${this.tag}: setAVPlayerCallback AVPlayer state stopped called.`);
          break
        case 'error':
          console.info(`${this.tag}: setAVPlayerCallback AVPlayer state error called.`);
          break
        case 'paused':
          console.info(`${this.tag}: setAVPlayerCallback AVPlayer state paused called.`);
          break
        default:
          console.info(`${this.tag}: setAVPlayerCallback AVPlayer state unknown called.`);
          break;
      }
    });
    // 时间上报监听函数
    this.avPlayer.on('timeUpdate', (time: number) => {
      this.currentTime = time;
    });
  }

  aboutToAppear() {
    this.windowWidth = display.getDefaultDisplaySync().width;
    this.windowHeight = display.getDefaultDisplaySync().height;
    this.surfaceW = this.windowWidth * SURFACE_W;
    this.surfaceH = this.surfaceW / SURFACE_H;
    this.isPaused = true;
    this.context = getContext(this) as common.UIAbilityContext;
  }

  aboutToDisappear() {
    if (this.avPlayer == null) {
      console.info(`${this.tag}: avPlayer has not init aboutToDisappear`);
      return;
    }
    this.avPlayer.release((err) => {
      if (err == null) {
        console.info(`${this.tag}: videoRelease release success`);
      } else {
        console.error(`${this.tag}: videoRelease release filed,error message is = ${JSON.stringify(err.message)}`);
      }
    });
    emitter.off(innerEventFalse.eventId);
  }

  onPageHide() {
    this.avPause();
    this.isPaused = false;
  }

  onPageShow() {
    emitter.on(innerEventTrue, (res: emitter.EventData) => {
      if (res.data) {
        this.isPaused = res.data.flag;
        this.XComponentFlag = res.data.flag;
      }
    });
    emitter.on(innerEventFalse, (res: emitter.EventData) => {
      if (res.data) {
        this.isPaused = res.data.flag;
      }
    });
    emitter.on(innerEventWH, (res: emitter.EventData) => {
      if (res.data) {
        this.windowWidth = res.data.width;
        this.windowHeight = res.data.height;
        this.setVideoWH();
      }
    });
  }

  setVideoWH(): void {
    if (this.percent >= 1) { // 横向视频
      this.surfaceW = Math.round(this.windowWidth * PROPORTION);
      this.surfaceH = Math.round(this.surfaceW / this.percent);
    } else { // 纵向视频
      this.surfaceH = Math.round(this.windowHeight * PROPORTION);
      this.surfaceW = Math.round(this.surfaceH * this.percent);
    }
  }

  @Builder
  CoverXComponent() {...}

  build() {...}
}
```

## 相关实例

针对视频播放，有以下相关实例可供参考：

- [视频播放（ArkTS）（API9）](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Media/VideoPlay)

- [视频播放器（ArkTS）（API9）](https://gitee.com/openharmony/codelabs/tree/master/Media/VideoPlayer)