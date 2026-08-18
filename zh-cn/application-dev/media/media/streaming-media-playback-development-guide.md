# 使用AVPlayer播放流媒体(ArkTS)
<!--Kit: Media Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @chennotfound-->
<!--Designer: @dongyu_dy-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->

本开发指导将介绍如何使用[AVPlayer](media-kit-intro.md#avplayer)开发流媒体直播和点播功能。示例展示如何完整播放流媒体视频，实现端到端的流媒体资源播放。

本指导仅介绍流媒体播放功能。本地音视频播放等其他场景，请参考[视频播放](video-playback.md)。

## 流媒体支持的格式

| 流媒体协议类型 | 典型链接 | 网络点播 | 网络直播 |内容保护 |
| -------- | -------- | -------- | -------- | -------- |
| HLS | `https://example/index.m3u8` | 支持 | 支持 | 支持，详见[DRM Kit](../drm/drm-overview.md)。 |
| DASH | `https://example.mpd` | 支持 | - | 支持，详见[DRM Kit](../drm/drm-overview.md)。 |
| HTTP/HTTPS | `https://example.mp4` | 支持 | - | - |
| HTTP-FLV | `https://example.flv` | 支持 | 支持 | - |

## 开发步骤

创建AVPlayer、设置播放资源和窗口、设置播放参数（音量/倍速/缩放模式）、进行播放控制（播放/暂停/跳转/停止）、重置资源、销毁资源。应用开发时，开发者可通过AVPlayer的state属性主动获取当前状态，或使用on('stateChange')方法监听状态变化。视频播放器处于错误状态时执行操作，可能导致异常或未定义行为。状态详细参见[AVPlayerState](../../reference/apis-media-kit/arkts-apis-media-t.md#avplayerstate9)。具体步骤如下：

1. 创建实例createAVPlayer()，初始化AVPlayer为idle状态。

2. 设置业务需要的监听事件，搭配全流程场景使用。支持的监听事件包括：

   | 事件类型 | 说明 |
   | -------- | -------- |
   | stateChange | 必要事件，监听播放器的state属性改变。<br>需要播放器在idle状态下、未调用设置资源接口前完成设置监听，若在调用设置资源接口后再设置监听，可能导致无法收到资源设置过程中上报的stateChange事件。 |
   | error | 必要事件，监听播放器的错误信息。<br>需要播放器在idle状态下、未调用设置资源接口前完成设置监听，若在调用设置资源接口后再设置监听，可能导致无法收到资源设置过程中上报的error事件。 |
   | durationUpdate | 监听进度条长度，刷新资源时长。 |
   | timeUpdate | 监听进度条当前位置，刷新当前时间。 |
   | seekDone | 监听seek()请求完成情况。<br/>当使用seek()跳转到指定播放位置后，如果seek操作成功，将上报该事件。 |
   | speedDone | 监听setSpeed()请求完成情况。<br/>当使用setSpeed()设置播放倍速后，如果setSpeed操作成功，将上报该事件。 |
   | volumeChange | 监听setVolume()请求完成情况。<br/>当使用setVolume()调节播放音量后，如果setVolume操作成功，将上报该事件。 |
   | bufferingUpdate | 监听网络播放缓冲信息，上报缓冲百分比以及缓存播放进度。 |
   | audioInterrupt | 监听音频焦点切换信息，搭配属性audioInterruptMode使用。<br/>如果当前设备存在多个音频正在播放，音频焦点被切换（即播放其他媒体如通话等）时将上报该事件，应用可以及时处理。 |

3. 设置资源：[使用AVPlayer设置播放URL](playback-url-setting-method.md)，使AVPlayer进入initialized状态。
   > **说明：**
   >
   > 下面代码示例中的url仅作示意，开发者需根据实际情况确认资源有效性并设置。
   > 
   > - 使用网络播放路径，需[声明权限](../../security/AccessToken/declare-permissions.md)：ohos.permission.INTERNET。
   > 
   > - 使用支持的播放格式和协议。
   > 

4. 设置窗口：获取并设置SurfaceID属性，用于配置显示画面。

   应用从XComponent组件获取surfaceID，获取方式请参考[XComponent](../../reference/apis-arkui/arkui-ts/ts-basic-components-xcomponent.md)。

5. 准备播放：调用prepare()，使AVPlayer进入prepared状态，此时可获取duration，设置缩放模式、音量等。

6. 进行视频播放控制：播放play()，暂停pause()，跳转seek()，停止stop() 等操作。

7. （可选）更换资源：调用reset()重置资源，使AVPlayer重新进入idle状态，允许更换资源url。

8. 退出播放：调用release()销毁实例，使AVPlayer进入released状态，退出播放。

## 注意事项

播放流媒体的标准流程如上述开发步骤所示。不同的流媒体格式在实际开发的过程中存在差异，本节将详细描述这些差异，包括视频起播策略的设置和音视频轨道的切换。

### 流媒体缓冲状态

当下载速率低于片源的码率时，会出现卡顿。此时，播放器检测到缓冲区数据不足，会先缓冲一些数据再播放，避免连续卡顿。一次卡顿对应的缓冲事件上报过程为：BUFFERING_START-> BUFFERING_PERCENT 0 -> ... -> BUFFERING_PERCENT 100 -> BUFFERING_END。CACHED_DURATION在卡顿过程和播放过程中都会持续上报，直至下载至资源末尾。详见[BufferingInfoType](../../reference/apis-media-kit/arkts-apis-media-e.md#bufferinginfotype8)缓冲事件类型枚举。

监听当前bufferingUpdate缓冲状态示例代码：

<!-- @[bufferingUpdate](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVPlayer/AVPlayerArkTSStreamingMedia/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
this.avPlayer.on('bufferingUpdate', (infoType: media.BufferingInfoType, value: number) => {
  console.info(`${this.tag}: bufferingUpdate called, infoType value: ${infoType}, value:${value}}`);
})
```

### HLS切换码率

当前流媒体HLS协议流支持多码率播放，默认情况下，播放器会根据网络下载速度选择合适的码率。

1. 通过[on('availableBitrates')](../../reference/apis-media-kit/arkts-apis-media-AVPlayer.md#onavailablebitrates9)监听当前HLS协议流可用的码率。如果监听的码率列表长度为0，则不支持设置指定码率。
   
   <!-- @[availableBitrates](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVPlayer/AVPlayerArkTSStreamingMedia/entry/src/main/ets/pages/Index.ets) -->
   
   ``` TypeScript
   this.avPlayer.on('availableBitrates', (bitrates: Array<number>) => {
     console.info('availableBitrates called, and availableBitrates length is: ' + bitrates.length);
     this.bitrate = bitrates[0]; // 保存需要切换的码率
   })
   ```

2. 通过[setBitrate](../../reference/apis-media-kit/arkts-apis-media-AVPlayer.md#setbitrate9)接口设置播放码率。若用户设置的码率不在可用码率中，播放器将选择最小且最接近的码率。该接口只能在prepared/playing/paused/completed状态下调用，可通过监听[bitrateDone](../../reference/apis-media-kit/arkts-apis-media-AVPlayer.md#onbitratedone9)事件确认是否生效。

   <!-- @[setBitrate](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVPlayer/AVPlayerArkTSStreamingMedia/entry/src/main/ets/pages/Index.ets) -->
  
   ``` TypeScript
   // 设置播放码率
   try {
     this.avPlayer.setBitrate(bitrate);
   } catch (error) {
     console.error(`${this.tag}: setBitrate failed, error message is = ${JSON.stringify(error.message)}`);
   }
   ```

### DASH设置视频起播策略

为了保证在弱网环境下的播放体验，AVPlayer将默认选择最低的视频分辨率开始播放，随后依据网络状况自动调整。开发者可以根据具体需求，自定义DASH视频的起播策略，包括设定视频的宽度、高度以及色彩格式等参数。

下述示例代码描述了设置视频宽度1920px、高度1080px起播。AVPlayer会选择MPD资源中一路分辨率为1920x1080的视频资源进行播放。

```ts
import { media } from '@kit.MediaKit';

let mediaSource : media.MediaSource = media.createMediaSourceWithUrl("http://test.cn/dash/aaa.mpd",  {"User-Agent" : "User-Agent-Value"});
let playbackStrategy : media.PlaybackStrategy = {preferredWidth: 1920, preferredHeight: 1080};
this.avPlayer.setMediaSource(mediaSource, playbackStrategy);
```

### DASH切换音视频轨道

DASH流媒体资源包含多路不同分辨率、码率、采样率、编码格式的音频、视频及字幕资源。默认情况下，AVPlayer会依据网络状况自动切换不同码率的视频轨道。开发者可根据需求选择指定的音视频轨道播放，此时自适应码率切换策略将失效。

1. 设置selectTrack生效的监听事件[trackChange](../../reference/apis-media-kit/arkts-apis-media-AVPlayer.md#ontrackchange12)。
   
   <!-- @[trackChange](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVPlayer/AVPlayerArkTSStreamingMedia/entry/src/main/ets/pages/Index.ets) -->

   ``` TypeScript
   this.avPlayer.on('trackChange', (index: number, isSelect: boolean) => {
   console.info(`trackChange info, index: ${index}, isSelect: ${isSelect}`);
   })
   ```

2. 调用[getTrackDescription](../../reference/apis-media-kit/arkts-apis-media-AVPlayer.md#gettrackdescription9)获取所有音视频轨道列表。开发者可根据实际需求，基于[MediaDescription](../../reference/apis-media-kit/arkts-apis-media-i.md#mediadescription8)各字段信息，确定目标轨道索引。

   <!-- @[getTrackDescription](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVPlayer/AVPlayerArkTSStreamingMedia/entry/src/main/ets/pages/Index.ets) -->
   
   ``` TypeScript
   this.avPlayer.getTrackDescription((error: BusinessError, arrList: Array<media.MediaDescription>) => {
     if (arrList != null) {
       for (let i = 0; i < arrList.length; i++) {
         let propertyIndex: Object = arrList[i][media.MediaDescriptionKey.MD_KEY_TRACK_INDEX];
         let propertyType: Object = arrList[i][media.MediaDescriptionKey.MD_KEY_TRACK_TYPE];
         let propertyWidth: Object = arrList[i][media.MediaDescriptionKey.MD_KEY_WIDTH];
         let propertyHeight: Object = arrList[i][media.MediaDescriptionKey.MD_KEY_HEIGHT];
         if (propertyType == media.MediaType.MEDIA_TYPE_VID && propertyWidth == 1920 && propertyHeight == 1080) {
           this.videoTrackIndex = parseInt(propertyIndex.toString()); // 获取1080p视频轨道索引。
         }
       }
     } else {
       console.error(`getTrackDescription fail, error:${error}`);
     }
   });
   ```

3. 在音视频播放过程中调用[selectTrack](../../reference/apis-media-kit/arkts-apis-media-AVPlayer.md#selecttrack12)选择对应的音视频轨道，或者调用[deselectTrack](../../reference/apis-media-kit/arkts-apis-media-AVPlayer.md#deselecttrack12)取消选择的音视频轨道。
   
   <!-- @[selectTrack](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVPlayer/AVPlayerArkTSStreamingMedia/entry/src/main/ets/pages/Index.ets) -->
   
   ``` TypeScript
   // 切换至目标视频轨道
   try {
     this.avPlayer.selectTrack(track);
   } catch (error) {
     console.error(`${this.tag}: selectTrack failed, error message is = ${JSON.stringify(error.message)}`);
   }
   ```

## 异常场景说明

使用AVPlayer播放流媒体过程中断网时，流媒体模块会根据返回的错误码、服务器响应时间和请求次数等因素综合处理。若错误码类型属于不进行请求重试的类型，会向应用上报对应的错误码。如果错误码类型需要进行请求重试，会在30s内进行至多10次的请求重试。如果请求重试次数超过10次，或重试总时长超过30秒，会向应用上报对应的错误码。如果请求重试成功，则继续播放。

## 运行完整示例

参考以下示例，完整地播放一个流媒体视频。

1. 新建工程，下载[示例工程](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/Media/AVPlayer/AVPlayerArkTSStreamingMedia)，并将示例工程的以下资源复制到对应目录。
    ```txt
    AVPlayerArkTSAudio
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

2. 在/entry/src/main/module.json5中，申请使用网络的权限（或直接替换为示例工程的module.json5）。
    ```json
    "requestPermissions": [
      {
        "name": "ohos.permission.INTERNET"
      },
      {
        "name": "ohos.permission.GET_WIFI_INFO"
      }
    ]
    ```
3. 通过注释、解注释/entry/src/main/ets/pages/Index.ets中的上文示例的各种情况，编译并运行。
