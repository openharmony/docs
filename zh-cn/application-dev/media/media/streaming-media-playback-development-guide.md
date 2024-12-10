# 使用AVPlayer开发流媒体播放功能

本开发指导将介绍如何使用[AVPlayer](media-kit-intro.md#avplayer)开发流媒体播放功能，以完整地播放一个流媒体视频作为示例，实现端到端播放流媒体资源。
当前指导仅介绍如何实现流媒体播放功能，本地音视频播放等其他场景，请参考[视频播放](using-avplayer-for-playback.md)。

## 流媒体支持的格式

| 流媒体协议类型 | 典型链接 | 网络点播 | 网络直播 | 字幕 | 内容保护 | 元数据 |
| -------- | -------- | -------- | -------- | -------- | -------- | -------- |
| HLS | `https://xxxx/index.m3u8` | 支持 | 支持 | srt/vtt | 支持 | 支持 |
| DASH | `https://xxxx.mpd` | 支持 | - | srt/vtt/webvtt | 支持 | 支持 |
| HTTP/HTTPS | `https://xxxx.mp4` | 支持 |-  | srt/vtt | - | 支持 |
| HTTP-FLV | `https://xxxx.flv` | 支持 | 支持 | srt/vtt | - | 支持 |

## 流媒体播放流程

创建AVPlayer，设置播放资源和窗口，设置播放参数（音量/倍速/缩放模式），播放控制（播放/暂停/跳转/停止），重置，销毁资源。在进行应用开发的过程中，开发者可以通过AVPlayer的state属性主动获取当前状态或使用on('stateChange')方法监听状态变化。如果应用在视频播放器处于错误状态时执行操作，系统可能会抛出异常或生成其他未定义的行为。状态的详细说明请参考[AVPlayerState](../../reference/apis-media-kit/js-apis-media.md#avplayerstate9)。

## 开发步骤及注意事项

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
   | bufferingUpdate | 用于网络播放，监听网络播放缓冲信息，用于上报缓冲百分比以及缓存播放进度。 |
   | audioInterrupt | 监听音频焦点切换信息，搭配属性audioInterruptMode使用。<br/>如果当前设备存在多个音频正在播放，音频焦点被切换（即播放其他媒体如通话等）时将上报该事件，应用可以及时处理。 |

3. 设置资源：设置属性url，AVPlayer进入initialized状态。
   > **说明：**
   >
   > 下面代码示例中的url仅作示意使用，开发者需根据实际情况，确认资源有效性并设置：
   > 
   > - 使用网络播放路径，需[声明权限](../../security/AccessToken/declare-permissions.md)：ohos.permission.INTERNET。
   > 
   > - 需要使用支持的播放格式与协议。
   > 

4. 准备播放：调用prepare()，AVPlayer进入prepared状态，此时可以获取duration，设置音量。

5. 音频播控：播放play()，暂停pause()，跳转seek()，停止stop() 等操作。

6. （可选）更换资源：调用reset()重置资源，AVPlayer重新进入idle状态，允许更换资源url。

7. 退出播放：调用release()销毁实例，AVPlayer进入released状态，退出播放。

## 完整实例

参考以下示例，完整地播放一个流媒体视频。

```ts
import { media } from '@kit.MediaKit';
import { fileIo as fs } from '@kit.CoreFileKit';
import { common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export class AVPlayerDemo {
  private count: number = 0;
  private isSeek: boolean = true; // 用于区分模式是否支持seek操作
  // 注册avplayer回调函数
  setAVPlayerCallback(avPlayer: media.AVPlayer) {
    // seek操作结果回调函数
    avPlayer.on('seekDone', (seekDoneTime: number) => {
      console.info(`AVPlayer seek succeeded, seek time is ${seekDoneTime}`);
    })
    // error回调监听函数,当avPlayer在操作过程中出现错误时调用 reset接口触发重置流程
    avPlayer.on('error', (err: BusinessError) => {
      console.error(`Invoke avPlayer failed, code is ${err.code}, message is ${err.message}`);
      avPlayer.reset(); // 调用reset重置资源，触发idle状态
    })
    // 状态机变化回调函数
    avPlayer.on('stateChange', async (state: string, reason: media.StateChangeReason) => {
      switch (state) {
        case 'idle': // 成功调用reset接口后触发该状态机上报
          console.info('AVPlayer state idle called.');
          avPlayer.release(); // 调用release接口销毁实例对象
          break;
        case 'initialized': // avplayer 设置播放源后触发该状态上报
          console.info('AVPlayer state initialized called.');
          this.avPlayer.audioRendererInfo = {
            usage: audio.StreamUsage.STREAM_USAGE_MUSIC,
            rendererFlags: 0
          }
          avPlayer.prepare();
          break;
        case 'prepared': // prepare调用成功后上报该状态机
          console.info('AVPlayer state prepared called.');
          avPlayer.play(); // 调用播放接口开始播放
          break;
        case 'playing': // play成功调用后触发该状态机上报
          console.info('AVPlayer state playing called.');
          break;
        case 'paused': // pause成功调用后触发该状态机上报
          console.info('AVPlayer state paused called.');
          break;
        case 'completed': // 播放结束后触发该状态机上报
          console.info('AVPlayer state completed called.');
          avPlayer.stop(); //调用播放结束接口
          break;
        case 'stopped': // stop接口成功调用后触发该状态机上报
          console.info('AVPlayer state stopped called.');
          avPlayer.reset(); // 调用reset接口初始化avplayer状态
          break;
        case 'released':
          console.info('AVPlayer state released called.');
          break;
        default:
          console.info('AVPlayer state unknown called.');
          break;
      }
    })
    // 获取流媒体缓冲状态和缓冲进度
    avPlayer.on('bufferingUpdate', (infoType : media.BufferingInfoType, value : number) => {
      console.info(`AVPlayer bufferingUpdate, infoType is ${infoType}, value is ${value}.`);
    })
  }

  // 以下demo为通过url设置网络地址来实现播放流媒体HLS点播视频
  async avPlayerVodDemo() {
    // 创建avPlayer实例对象
    let avPlayer: media.AVPlayer = await media.createAVPlayer();
    // 创建状态机变化回调函数
    this.setAVPlayerCallback(avPlayer);
    this.isSeek = true; // 点播支持seek操作
    avPlayer.url = 'http://xxx.xxx.xxx.xxx:xx/xx/index.m3u8';
  }

  // 以下demo为通过url设置网络地址来实现播放流媒体HLS直播视频
  async avPlayerLiveDemo() {
    // 创建avPlayer实例对象
    let avPlayer: media.AVPlayer = await media.createAVPlayer();
    // 创建状态机变化回调函数
    this.setAVPlayerCallback(avPlayer);
    this.isSeek = false; // 直播不支持seek操作
    avPlayer.url = 'http://xxx.xxx.xxx.xxx:xx/xx/index.m3u8';
  }

  // 以下demo为通过setMediaSource设置自定义头域及媒体播放优选参数实现初始播放参数设置，以流媒体Https点播为例
  async preDownloadDemo() {
    // 创建avPlayer实例对象
    let avPlayer: media.AVPlayer = await media.createAVPlayer();
    // 创建状态机变化回调函数
    this.setAVPlayerCallback(avPlayer);
    this.isSeek = true; // 点播支持seek操作
    // 创建mediaSource实例对象，设置媒体来源，定制HTTP请求，如需要，可以键值对的形式设置User-Agent、Cookie、Referer等字段
    let mediaSource : media.MediaSource = media.createMediaSourceWithUrl("https://xxx.xxx",  {"User-Agent" : "User-Agent-Value", "Cookie" : "Cookie-Value", "Referer" : "Referer-Value"});
    // 设置播放策略，播放片源的尺寸为1920*1080、设置缓冲区大小为20MB
    let playbackStrategy : media.PlaybackStrategy = {preferredWidth: 1920, preferredHeight: 1080, preferredBufferDuration: 20, preferredHdr: false};
    // 为avPlayer设置媒体来源和播放策略
    avPlayer.setMediaSource(mediaSource, playbackStrategy);
  }
}
```

## 异常场景说明

使用avPlayer播放流媒体过程中断网：流媒体模块会根据返回的错误码、服务器请求失败的响应时间、请求次数等因素综合处理。若错误码类型属于不进行请求重试的类型，会向应用上报对应的错误码。若错误码类型需要进行请求重试，会在30s内进行至多10次的请求重试。若请求重试次数超过10次，或重试总时长超过30秒，会上向应用上报对应的错误码。若请求重试成功，则继续播放。