# 托管网页中的媒体播放

Web组件提供了应用接管网页中媒体播放的能力，用来支持应用增强网页的媒体播放，如画质增强等。

## 使用场景

网页播放媒体时，存在以下问题：网页清晰度低、网页播放器播放控件功能有限、某些视频无法播放。

应用开发者可以使用该功能，通过自己或者第三方播放器接管网页媒体播放，从而改善播放体验。

## 实现原理

### ArkWeb内核播放媒体的框架

不开启该功能时，ArkWeb内核的播放架构如下所示：

  ![arkweb media pipeline](figures/arkweb_media_pipeline.png)

  > **说明：**
  >
  > - 上图中1表示ArkWeb内核创建WebMediaPlayer来播放网页中的媒体资源。
  > - 上图中2表示WebMediaPlayer使用系统解码器来渲染媒体数据。

开启该功能后，ArkWeb内核的播放架构如下：

  ![arkweb native media player](figures/arkweb_native_media_player.png)

  > **说明：**
  >
  > - 上图中1表示ArkWeb内核创建WebMediaPlayer来播放网页中的媒体资源。
  > - 上图中2表示WebMediaPlayer使用应用提供的本地播放器（NativeMediaPlayer）来渲染媒体数据。


### ArkWeb内核与应用的交互

  ![interactions between arkweb and native media player](figures/interactions_between_arkweb_and_native_media_player.png)

  > **说明：**
  >
  > - 上图中1的详细说明见[开启接管网页媒体播放](#开启接管网页媒体播放)。
  > - 上图中2的详细说明见[创建本地播放器](#创建本地播放器nativemediaplayer)。
  > - 上图中3的详细说明见[绘制本地播放器组件](#绘制本地播放器组件)。
  > - 上图中4的详细说明见[执行 ArkWeb 内核发送给本地播放器的播控指令](#执行arkweb内核发送给本地播放器的播控指令)。
  > - 上图中5的详细说明见[将本地播放器的状态信息通知给 ArkWeb 内核](#将本地播放器的状态信息通知给arkweb内核)。

## 开发指导

### 开启接管网页媒体播放

需要先通过[enableNativeMediaPlayer](../reference/apis-arkweb/ts-basic-components-web-attributes.md#enablenativemediaplayer12)接口开启接管网页媒体播放的功能。

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .enableNativeMediaPlayer({ enable: true, shouldOverlay: false })
      }
    }
  }
  ```

### 创建本地播放器(NativeMediaPlayer)

该功能开启后，网页中有媒体需要播放时，ArkWeb内核会触发[onCreateNativeMediaPlayer](../reference/apis-arkweb/js-apis-webview-WebviewController.md#oncreatenativemediaplayer12)注册的回调函数。

应用则需要调用 `onCreateNativeMediaPlayer` 来注册一个创建本地播放器的回调函数。

该回调函数需要根据媒体信息来判断是否要创建一个本地播放器来接管当前的网页媒体资源。

  * 如果应用不接管当前的网页媒体资源， 需在回调函数里返回 `null` 。
  * 如果应用接管当前的网页媒体资源， 需在回调函数里返回一个本地播放器实例。

本地播放器需要实现[NativeMediaPlayerBridge](../reference/apis-arkweb/js-apis-webview.md#nativemediaplayerbridge12)接口，以便ArkWeb内核对本地播放器进行播控操作。

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  // 实现 webview.NativeMediaPlayerBridge 接口。
  // ArkWeb 内核调用该类的方法来对 NativeMediaPlayer 进行播控。
  class NativeMediaPlayerImpl implements webview.NativeMediaPlayerBridge {
    // ... 实现 NativeMediaPlayerBridge 里的接口方法 ...
    constructor(handler: webview.NativeMediaPlayerHandler, mediaInfo: webview.MediaInfo) {}
    updateRect(x: number, y: number, width: number, height: number) {}
    play() {}
    pause() {}
    seek(targetTime: number) {}
    release() {}
    setVolume(volume: number) {}
    setMuted(muted: boolean) {}
    setPlaybackRate(playbackRate: number) {}
    enterFullscreen() {}
    exitFullscreen() {}
  }

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .enableNativeMediaPlayer({ enable: true, shouldOverlay: false })
          .onPageBegin((event) => {
            this.controller.onCreateNativeMediaPlayer((handler: webview.NativeMediaPlayerHandler, mediaInfo: webview.MediaInfo) => {
              // 判断需不需要接管当前的媒体。
              if (!shouldHandle(mediaInfo)) {
                // 本地播放器不接管该媒体。
                // 返回 null 。ArkWeb 内核将用自己的播放器来播放该媒体。
                return null;
              }
              // 接管当前的媒体。
              // 返回一个本地播放器实例给 ArkWeb 内核。
              let nativePlayer: webview.NativeMediaPlayerBridge = new NativeMediaPlayerImpl(handler, mediaInfo);
              return nativePlayer;
            });
          })
      }
    }
  }

  // stub
  function shouldHandle(mediaInfo: webview.MediaInfo) {
    return true;
  }
  ```

### 绘制本地播放器组件

应用接管网页媒体后，应用需要将本地播放器组件及视频画面绘制到ArkWeb内核提供的Surface上。ArkWeb内核再将Surface与网页进行合成并显示。

该流程与[同层渲染绘制](web-same-layer.md)一致。

1. 在应用启动阶段，应用应保存UIContext，以便后续的同层渲染绘制流程能够使用该UIContext。

   ```ts
   // xxxAbility.ets

   import { UIAbility } from '@kit.AbilityKit';
   import { window } from '@kit.ArkUI';

   export default class EntryAbility extends UIAbility {
     onWindowStageCreate(windowStage: window.WindowStage): void {
       windowStage.loadContent('pages/Index', (err, data) => {
         if (err.code) {
           return;
         }
         // 保存UIContext， 在后续的同层渲染绘制中使用。
         AppStorage.setOrCreate<UIContext>("UIContext", windowStage.getMainWindowSync().getUIContext());
       });
     }

     // ... 其他需要重写的方法 ...
   }
   ```

2. 应用使用ArkWeb内核创建的Surface进行同层渲染绘制。

   ```ts
   // xxx.ets
   import { webview } from '@kit.ArkWeb';
   import { BuilderNode, FrameNode, NodeController, NodeRenderType } from '@kit.ArkUI';

   interface ComponentParams {}

   class MyNodeController extends NodeController {
     private rootNode: BuilderNode<[ComponentParams]> | undefined;

     constructor(surfaceId: string, renderType: NodeRenderType) {
       super();

       // 获取之前保存的 UIContext 。
       let uiContext = AppStorage.get<UIContext>("UIContext");
       this.rootNode = new BuilderNode(uiContext as UIContext, { surfaceId: surfaceId, type: renderType });
     }

     makeNode(uiContext: UIContext): FrameNode | null {
       if (this.rootNode) {
         return this.rootNode.getFrameNode() as FrameNode;
       }
       return null;
     }

     build() {
       // 构造本地播放器组件
     }
   }

   @Entry
   @Component
   struct WebComponent {
     node_controller?: MyNodeController;
     controller: webview.WebviewController = new webview.WebviewController();
     @State show_native_media_player: boolean = false;

     build() {
       Column() {
         Stack({ alignContent: Alignment.TopStart }) {
           if (this.show_native_media_player) {
             NodeContainer(this.node_controller)
               .width(300)
               .height(150)
               .backgroundColor(Color.Transparent)
               .border({ width: 2, color: Color.Orange })
           }
           Web({ src: 'www.example.com', controller: this.controller })
             .enableNativeMediaPlayer({ enable: true, shouldOverlay: false })
             .onPageBegin((event) => {
               this.controller.onCreateNativeMediaPlayer((handler: webview.NativeMediaPlayerHandler, mediaInfo:    webview.MediaInfo) => {
                 // 接管当前的媒体。

                 // 使用同层渲染流程提供的 surface 来构造一个本地播放器组件。
                 this.node_controller = new MyNodeController(mediaInfo.surfaceInfo.id, NodeRenderType.RENDER_TYPE_TEXTURE);
                 this.node_controller.build();

                 // 展示本地播放器组件。
                 this.show_native_media_player = true;

                 // 返回一个本地播放器实例给 ArkWeb 内核。
                 return null;
               });
             })
         }
       }
     }
   }
   ```

动态创建组件并绘制到Surface上的详细介绍见[同层渲染绘制](web-same-layer.md) 。

### 执行ArkWeb内核发送给本地播放器的播控指令

为了方便ArkWeb内核对本地播放器进行播控操作，应用需要令本地播放器实现[NativeMediaPlayerBridge](../reference/apis-arkweb/js-apis-webview.md#nativemediaplayerbridge12)接口，并根据每个接口方法的功能对本地播放器进行相应操作。

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  class ActualNativeMediaPlayerListener {
    constructor(handler: webview.NativeMediaPlayerHandler) {}
  }

  class NativeMediaPlayerImpl implements webview.NativeMediaPlayerBridge {
    constructor(handler: webview.NativeMediaPlayerHandler, mediaInfo: webview.MediaInfo) {
      // 1. 创建一个本地播放器的状态监听。
      let listener: ActualNativeMediaPlayerListener = new ActualNativeMediaPlayerListener(handler);
      // 2. 创建一个本地播放器。
      // 3. 监听该本地播放器。
      // ...
    }

    updateRect(x: number, y: number, width: number, height: number) {
      // <video> 标签的位置和大小发生了变化。
      // 根据该信息变化，作出相应的改变。
    }

    play() {
      // 启动本地播放器播放。
    }

    pause() {
      // 暂停本地播放器播放。
    }

    seek(targetTime: number) {
      // 本地播放器跳转到指定的时间点。
    }

    release() {
      // 销毁本地播放器。
    }

    setVolume(volume: number) {
      // ArkWeb 内核要求调整本地播放器的音量。
      // 设置本地播放器的音量。
    }

    setMuted(muted: boolean) {
      // 将本地播放器静音或取消静音。
    }

    setPlaybackRate(playbackRate: number) {
      // 调整本地播放器的播放速度。
    }

    enterFullscreen() {
      // 将本地播放器设置为全屏播放。
    }

    exitFullscreen() {
      // 将本地播放器退出全屏播放。
    }
  }
  ```

### 将本地播放器的状态信息通知给ArkWeb内核

ArkWeb内核需要本地播放器的状态信息来更新到网页（例如：视频的宽高、播放时间、缓存时间等），因此，应用需要将本地播放器的状态信息通知给ArkWeb内核。

在[onCreateNativeMediaPlayer](../reference/apis-arkweb/js-apis-webview-WebviewController.md#oncreatenativemediaplayer12)接口中， ArkWeb内核传递一个[NativeMediaPlayerHandler](../reference/apis-arkweb/js-apis-webview.md#nativemediaplayerhandler12)对象给应用。应用需要通过该对象，将本地播放器的最新状态信息通知给ArkWeb内核。

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  class ActualNativeMediaPlayerListener {
    handler: webview.NativeMediaPlayerHandler;

    constructor(handler: webview.NativeMediaPlayerHandler) {
      this.handler = handler;
    }

    onPlaying() {
      // 本地播放器开始播放。
      this.handler.handleStatusChanged(webview.PlaybackStatus.PLAYING);
    }
    onPaused() {
      // 本地播放器暂停播放。
      this.handler.handleStatusChanged(webview.PlaybackStatus.PAUSED);
    }
    onSeeking() {
      // 本地播放器开始执行跳转到目标时间点。
      this.handler.handleSeeking();
    }
    onSeekDone() {
      // 本地播放器 seek 完成。
      this.handler.handleSeekFinished();
    }
    onEnded() {
      // 本地播放器播放完成。
      this.handler.handleEnded();
    }
    onVolumeChanged() {
      // 获取本地播放器的音量。
      let volume: number = getVolume();
      this.handler.handleVolumeChanged(volume);
    }
    onCurrentPlayingTimeUpdate() {
      // 更新播放时间。
      let currentTime: number = getCurrentPlayingTime();
      // 将时间单位换算成秒。
      let currentTimeInSeconds = convertToSeconds(currentTime);
      this.handler.handleTimeUpdate(currentTimeInSeconds);
    }
    onBufferedChanged() {
      // 缓存发生了变化。
      // 获取本地播放器的缓存时长。
      let bufferedEndTime: number = getCurrentBufferedTime();
      // 将时间单位换算成秒。
      let bufferedEndTimeInSeconds = convertToSeconds(bufferedEndTime);
      this.handler.handleBufferedEndTimeChanged(bufferedEndTimeInSeconds);

      // 检查缓存状态。
      // 如果缓存状态发生了变化，则向 ArkWeb 内核通知缓存状态。
      let lastReadyState: webview.ReadyState = getLastReadyState();
      let currentReadyState: webview.ReadyState = getCurrentReadyState();
      if (lastReadyState != currentReadyState) {
        this.handler.handleReadyStateChanged(currentReadyState);
      }
    }
    onEnterFullscreen() {
      // 本地播放器进入了全屏状态。
      let isFullscreen: boolean = true;
      this.handler.handleFullscreenChanged(isFullscreen);
    }
    onExitFullscreen() {
      // 本地播放器退出了全屏状态。
      let isFullscreen: boolean = false;
      this.handler.handleFullscreenChanged(isFullscreen);
    }
    onUpdateVideoSize(width: number, height: number) {
      // 当本地播放器解析出视频宽高时， 通知 ArkWeb 内核。
      this.handler.handleVideoSizeChanged(width, height);
    }
    onDurationChanged(duration: number) {
      // 本地播放器解析到了新的媒体时长， 通知 ArkWeb 内核。
      this.handler.handleDurationChanged(duration);
    }
    onError(error: webview.MediaError, errorMessage: string) {
      // 本地播放器出错了，通知 ArkWeb 内核。
      this.handler.handleError(error, errorMessage);
    }
    onNetworkStateChanged(state: webview.NetworkState) {
      // 本地播放器的网络状态发生了变化， 通知 ArkWeb 内核。
      this.handler.handleNetworkStateChanged(state);
    }
    onPlaybackRateChanged(playbackRate: number) {
      // 本地播放器的播放速率发生了变化， 通知 ArkWeb 内核。
      this.handler.handlePlaybackRateChanged(playbackRate);
    }
    onMutedChanged(muted: boolean) {
      // 本地播放器的静音状态发生了变化， 通知 ArkWeb 内核。
      this.handler.handleMutedChanged(muted);
    }

    // ... 监听本地播放器其他的状态 ...
  }
  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    @State show_native_media_player: boolean = false;

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .enableNativeMediaPlayer({enable: true, shouldOverlay: false})
          .onPageBegin((event) => {
            this.controller.onCreateNativeMediaPlayer((handler: webview.NativeMediaPlayerHandler, mediaInfo: webview.MediaInfo) => {
              // 接管当前的媒体。

              // 创建一个本地播放器实例。
              // let nativePlayer: NativeMediaPlayerImpl = new NativeMediaPlayerImpl(handler, mediaInfo);

              // 创建一个本地播放器状态监听对象。
              let nativeMediaPlayerListener: ActualNativeMediaPlayerListener = new ActualNativeMediaPlayerListener(handler);
              // 监听本地播放器状态。
              // nativePlayer.setListener(nativeMediaPlayerListener);

              // 返回这个本地播放器实例给 ArkWeb 内核。
              return null;
            });
          })
      }
    }
  }

  // stub
  function getVolume() {
    return 1;
  }
  function getCurrentPlayingTime() {
    return 1;
  }
  function getCurrentBufferedTime() {
    return 1;
  }
  function convertToSeconds(input: number) {
    return input;
  }
  function getLastReadyState() {
    return webview.ReadyState.HAVE_NOTHING;
  }
  function getCurrentReadyState() {
    return webview.ReadyState.HAVE_NOTHING;
  }
  ```


## 完整示例

- 使用前在module.json5中添加如下权限。

  ```ts
  "ohos.permission.INTERNET"
  ```

- 在应用启动阶段保存UIContext。

  ```ts
  // xxxAbility.ets

  import { UIAbility } from '@kit.AbilityKit';
  import { window } from '@kit.ArkUI';

  export default class EntryAbility extends UIAbility {
    onWindowStageCreate(windowStage: window.WindowStage): void {
      windowStage.loadContent('pages/Index', (err, data) => {
        if (err.code) {
          return;
        }
        // 保存 UIContext， 在后续的同层渲染绘制中会用到。
        AppStorage.setOrCreate<UIContext>("UIContext", windowStage.getMainWindowSync().getUIContext());
      });
    }

    // ... 其他需要重写的方法 ...
  }
  ```

- 应用侧代码，视频托管使用示例。

  ```ts
  // Index.ets
  import { webview } from '@kit.ArkWeb';
  import { BuilderNode, FrameNode, NodeController, NodeRenderType } from '@kit.ArkUI';
  import { AVPlayerDemo, AVPlayerListener } from './PlayerDemo';

  // 实现 webview.NativeMediaPlayerBridge 接口。
  // ArkWeb 内核调用该类的方法来对 NativeMediaPlayer 进行播控。
  class NativeMediaPlayerImpl implements webview.NativeMediaPlayerBridge {
    private surfaceId: string;
    mediaSource: string;
    private mediaHandler: webview.NativeMediaPlayerHandler;
    nativePlayerInfo: NativePlayerInfo;
    nativePlayer: AVPlayerDemo;
    httpHeaders: Record<string, string>;
    uiContext?: UIContext;

    constructor(nativePlayerInfo: NativePlayerInfo, handler: webview.NativeMediaPlayerHandler, mediaInfo: webview.MediaInfo, uiContext: UIContext) {
      this.uiContext = uiContext;
      console.log(`NativeMediaPlayerImpl.constructor, surface_id[${mediaInfo.surfaceInfo.id}]`);
      this.nativePlayerInfo = nativePlayerInfo;
      this.mediaHandler = handler;
      this.surfaceId = mediaInfo.surfaceInfo.id;
      this.mediaSource = mediaInfo.mediaSrcList.find((item)=>{item.source.indexOf('.mp4') > 0})?.source
        || mediaInfo.mediaSrcList[0].source;
      this.httpHeaders = mediaInfo.headers;
      this.nativePlayer = new AVPlayerDemo();

      // 使用同层渲染功能，将视频及其播控组件绘制到网页中
      this.nativePlayerInfo.node_controller = new MyNodeController(
        this.nativePlayerInfo, this.surfaceId, this.mediaHandler, this, NodeRenderType.RENDER_TYPE_TEXTURE);
      this.nativePlayerInfo.node_controller.build();
      this.nativePlayerInfo.show_native_media_player = true;

      console.log(`NativeMediaPlayerImpl.mediaSource: ${this.mediaSource}, headers: ${JSON.stringify(this.httpHeaders)}`);
    }

    updateRect(x: number, y: number, width: number, height: number): void {
      let width_in_vp = this.uiContext!.px2vp(width);
      let height_in_vp = this.uiContext!.px2vp(height);
      console.log(`updateRect(${x}, ${y}, ${width}, ${height}), vp:{${width_in_vp}, ${height_in_vp}}`);

      this.nativePlayerInfo.updateNativePlayerRect(x, y, width, height);
    }

    play() {
      console.log('NativeMediaPlayerImpl.play');
      this.nativePlayer.play();
    }
    pause() {
      console.log('NativeMediaPlayerImpl.pause');
      this.nativePlayer.pause();
    }
    seek(targetTime: number) {
      console.log(`NativeMediaPlayerImpl.seek(${targetTime})`);
      this.nativePlayer.seek(targetTime);
    }
    setVolume(volume: number) {
      console.log(`NativeMediaPlayerImpl.setVolume(${volume})`);
      this.nativePlayer.setVolume(volume);
    }
    setMuted(muted: boolean) {
      console.log(`NativeMediaPlayerImpl.setMuted(${muted})`);
    }
    setPlaybackRate(playbackRate: number) {
      console.log(`NativeMediaPlayerImpl.setPlaybackRate(${playbackRate})`);
      this.nativePlayer.setPlaybackRate(playbackRate);
    }
    release() {
      console.log('NativeMediaPlayerImpl.release');
      this.nativePlayer?.release();
      this.nativePlayerInfo.show_native_media_player = false;
      this.nativePlayerInfo.node_width = 300;
      this.nativePlayerInfo.node_height = 150;
      this.nativePlayerInfo.destroyed();
    }
    enterFullscreen() {
      console.log('NativeMediaPlayerImpl.enterFullscreen');
    }
    exitFullscreen() {
      console.log('NativeMediaPlayerImpl.exitFullscreen');
    }
  }

  // 监听NativeMediaPlayer的状态，然后通过 webview.NativeMediaPlayerHandler 将状态上报给 ArkWeb 内核。
  class AVPlayerListenerImpl implements AVPlayerListener {
    handler: webview.NativeMediaPlayerHandler;
    component: NativePlayerComponent;

    constructor(handler: webview.NativeMediaPlayerHandler, component: NativePlayerComponent) {
      this.handler = handler;
      this.component = component;
    }
    onPlaying() {
      console.log('AVPlayerListenerImpl.onPlaying');
      this.handler.handleStatusChanged(webview.PlaybackStatus.PLAYING);
    }
    onPaused() {
      console.log('AVPlayerListenerImpl.onPaused');
      this.handler.handleStatusChanged(webview.PlaybackStatus.PAUSED);
    }
    onDurationChanged(duration: number) {
      console.log(`AVPlayerListenerImpl.onDurationChanged(${duration})`);
      this.handler.handleDurationChanged(duration);
    }
    onBufferedTimeChanged(buffered: number) {
      console.log(`AVPlayerListenerImpl.onBufferedTimeChanged(${buffered})`);
      this.handler.handleBufferedEndTimeChanged(buffered);
    }
    onTimeUpdate(time: number) {
      this.handler.handleTimeUpdate(time);
    }
    onEnded() {
      console.log('AVPlayerListenerImpl.onEnded');
      this.handler.handleEnded();
    }
    onError() {
      console.log('AVPlayerListenerImpl.onError');
      this.component.has_error = true;
      setTimeout(()=>{
        this.handler.handleError(1, "Oops!");
      }, 200);
    }
    onVideoSizeChanged(width: number, height: number) {
      console.log(`AVPlayerListenerImpl.onVideoSizeChanged(${width}, ${height})`);
      this.handler.handleVideoSizeChanged(width, height);
      this.component.onSizeChanged(width, height);
    }
    onDestroyed(): void {
      console.log('AVPlayerListenerImpl.onDestroyed');
    }
  }

  interface ComponentParams {
    text: string;
    text2: string;
    playerInfo: NativePlayerInfo;
    handler: webview.NativeMediaPlayerHandler;
    player: NativeMediaPlayerImpl;
  }

  // 自定义的播放器组件
  @Component
  struct NativePlayerComponent {
    params?: ComponentParams;
    @State bgColor: Color = Color.Red;
    mXComponentController: XComponentController = new XComponentController();

    videoController: VideoController = new VideoController();
    offset_x: number = 0;
    offset_y: number = 0;
    @State video_width_percent: number = 100;
    @State video_height_percent: number = 100;
    view_width: number = 0;
    view_height: number = 0;
    video_width: number = 0;
    video_height: number = 0;

    fullscreen: boolean = false;
    @State has_error: boolean = false;

    onSizeChanged(width: number, height: number) {
      this.video_width = width;
      this.video_height = height;
      let scale: number = this.view_width / width;
      let scaled_video_height: number = scale * height;
      this.video_height_percent = scaled_video_height / this.view_height * 100;
      console.log(`NativePlayerComponent.onSizeChanged(${width},${height}), video_height_percent[${this.video_height_percent }]`);
    }

    build() {
      Column() {
        Stack() {
          XComponent({ id: 'video_player_id', type: XComponentType.SURFACE, controller: this.mXComponentController })
            .width(this.video_width_percent + '%')
            .height(this.video_height_percent + '%')
            .onLoad(()=>{
              if (!this.params) {
                console.log('this.params is null');
                return;
              }
              console.log('NativePlayerComponent.onLoad, params[' + this.params
                + '], text[' + this.params.text + '], text2[' + this.params.text2
                + '], web_tab[' + this.params.playerInfo + '], handler[' + this.params.handler + ']');
              this.params.player.nativePlayer.setSurfaceID(this.mXComponentController.getXComponentSurfaceId());

              this.params.player.nativePlayer.avPlayerLiveDemo({
                url: this.params.player.mediaSource,
                listener: new AVPlayerListenerImpl(this.params.handler, this),
                httpHeaders: this.params.player.httpHeaders,
              });
            })
          Column() {
            Row() {
              Button(this.params?.text)
                .height(50)
                .border({ width: 2, color: Color.Red })
                .backgroundColor(this.bgColor)
                .onClick(()=>{
                  console.log(`NativePlayerComponent.Button[${this.params?.text}] is clicked`);
                  this.params?.player.nativePlayer?.play();
                })
                .onTouch((event: TouchEvent) => {
                  event.stopPropagation();
                })
              Button(this.params?.text2)
                .height(50)
                .border({ width: 2, color: Color.Red })
                .onClick(()=>{
                  console.log(`NativePlayerComponent.Button[${this.params?.text2}] is clicked`);
                  this.params?.player.nativePlayer?.pause();
                })
                .onTouch((event: TouchEvent) => {
                  event.stopPropagation();
                })
            }
            .width('100%')
            .justifyContent(FlexAlign.SpaceEvenly)
          }
          if (this.has_error) {
            Column() {
              Text('Error')
                .fontSize(30)
            }
            .backgroundColor('#eb5555')
            .width('100%')
            .height('100%')
            .justifyContent(FlexAlign.Center)
          }
        }
      }
      .width('100%')
      .height('100%')
      .onAreaChange((oldValue: Area, newValue: Area) => {
        console.log(`NativePlayerComponent.onAreaChange(${JSON.stringify(oldValue)}, ${JSON.stringify(newValue)})`);
        this.view_width = new Number(newValue.width).valueOf();
        this.view_height = new Number(newValue.height).valueOf();
        this.onSizeChanged(this.video_width, this.video_height);
      })
    }
  }

  @Builder
  function NativePlayerComponentBuilder(params: ComponentParams) {
    NativePlayerComponent({ params: params })
      .backgroundColor(Color.Green)
      .border({ width: 1, color: Color.Brown })
      .width('100%')
      .height('100%')
  }

  // 通过 NodeController 动态创建自定义的播放器组件， 并将组件内容绘制到 surface 上。
  class MyNodeController extends NodeController {
    private rootNode: BuilderNode<[ComponentParams]> | undefined;
    playerInfo: NativePlayerInfo;
    listener: webview.NativeMediaPlayerHandler;
    player: NativeMediaPlayerImpl;

    constructor(playerInfo: NativePlayerInfo,
                surfaceId: string,
                listener: webview.NativeMediaPlayerHandler,
                player: NativeMediaPlayerImpl,
                renderType: NodeRenderType) {
      super();
      this.playerInfo = playerInfo;
      this.listener = listener;
      this.player = player;
      let uiContext = AppStorage.get<UIContext>("UIContext");
      this.rootNode = new BuilderNode(uiContext as UIContext, { surfaceId: surfaceId, type: renderType });
      console.log(`MyNodeController, rootNode[${this.rootNode}], playerInfo[${playerInfo}], listener[${listener}], surfaceId[${surfaceId}]`);
    }

    makeNode(): FrameNode | null {
      if (this.rootNode) {
        return this.rootNode.getFrameNode() as FrameNode;
      }
      return null;
    }

    build() {
      let params: ComponentParams = {
        "text": "play",
        "text2": "pause",
        playerInfo: this.playerInfo,
        handler: this.listener,
        player: this.player
      };
      if (this.rootNode) {
        this.rootNode.build(wrapBuilder(NativePlayerComponentBuilder), params);
      }
    }

    postTouchEvent(event: TouchEvent) {
      return this.rootNode?.postTouchEvent(event);
    }
  }

  class Rect {
    x: number = 0;
    y: number = 0;
    width: number = 0;
    height: number = 0;

    static toNodeRect(rectInPx: webview.RectEvent, uiContext: UIContext) : Rect {
      let rect = new Rect();
      rect.x = uiContext.px2vp(rectInPx.x);
      rect.y = uiContext.px2vp(rectInPx.x);
      rect.width = uiContext.px2vp(rectInPx.width);
      rect.height = uiContext.px2vp(rectInPx.height);
      return rect;
    }
  }

  @Observed
  class NativePlayerInfo {
    public web: WebComponent;
    public embed_id: string;
    public player: webview.NativeMediaPlayerBridge;
    public node_controller?: MyNodeController;
    public show_native_media_player: boolean = false;
    public node_pos_x: number;
    public node_pos_y: number;
    public node_width: number;
    public node_height: number;

    playerComponent?: NativeMediaPlayerComponent;

    constructor(web: WebComponent, handler: webview.NativeMediaPlayerHandler, videoInfo: webview.MediaInfo, uiContext: UIContext) {
      this.web = web;
      this.embed_id = videoInfo.embedID;

      let node_rect = Rect.toNodeRect(videoInfo.surfaceInfo.rect, uiContext);
      this.node_pos_x = node_rect.x;
      this.node_pos_y = node_rect.y;
      this.node_width = node_rect.width;
      this.node_height = node_rect.height;

      this.player = new NativeMediaPlayerImpl(this, handler, videoInfo, uiContext);
    }

    updateNativePlayerRect(x: number, y: number, width: number, height: number) {
      this.playerComponent?.updateNativePlayerRect(x, y, width, height);
    }

    destroyed() {
      let info_list = this.web.native_player_info_list;
      console.log(`NativePlayerInfo[${this.embed_id}] destroyed, list.size[${info_list.length}]`);
      this.web.native_player_info_list = info_list.filter((item) => item.embed_id != this.embed_id);
      console.log(`NativePlayerInfo after destroyed, new_list.size[${this.web.native_player_info_list.length}]`);
    }
  }

  @Component
  struct NativeMediaPlayerComponent {
    @ObjectLink playerInfo: NativePlayerInfo;

    aboutToAppear() {
      this.playerInfo.playerComponent = this;
    }

    build() {
      NodeContainer(this.playerInfo.node_controller)
        .width(this.playerInfo.node_width)
        .height(this.playerInfo.node_height)
        .offset({x: this.playerInfo.node_pos_x, y: this.playerInfo.node_pos_y})
        .backgroundColor(Color.Transparent)
        .border({ width: 2, color: Color.Orange })
        .onAreaChange((oldValue, newValue) => {
          console.log(`NodeContainer[${this.playerInfo.embed_id}].onAreaChange([${oldValue.width} x ${oldValue.height}]->[${newValue.width} x ${newValue.height}]`);
        })
    }

    updateNativePlayerRect(x: number, y: number, width: number, height: number) {
      let node_rect = Rect.toNodeRect({x, y, width, height}, this.getUIContext());
      this.playerInfo.node_pos_x = node_rect.x;
      this.playerInfo.node_pos_y = node_rect.y;
      this.playerInfo.node_width = node_rect.width;
      this.playerInfo.node_height = node_rect.height;
    }
  }

  @Entry
  @Component
  struct WebComponent {
    controller: WebviewController = new webview.WebviewController();
    page_url: Resource = $rawfile('main.html');

    @State native_player_info_list: NativePlayerInfo[] = [];

    area?: Area;

    build() {
      Column() {
        Stack({alignContent: Alignment.TopStart}) {
          ForEach(this.native_player_info_list, (item: NativePlayerInfo) => {
            if (item.show_native_media_player) {
              NativeMediaPlayerComponent({ playerInfo: item })
            }
          }, (item: NativePlayerInfo) => {
            return item.embed_id;
          })
          Web({ src: this.page_url, controller: this.controller })
            .enableNativeMediaPlayer({ enable: true, shouldOverlay: true })
            .onPageBegin(() => {
              this.controller.onCreateNativeMediaPlayer((handler: webview.NativeMediaPlayerHandler, mediaInfo: webview.MediaInfo) => {
                console.log('onCreateNativeMediaPlayer(' + JSON.stringify(mediaInfo) + ')');
                let nativePlayerInfo = new NativePlayerInfo(this, handler, mediaInfo, this.getUIContext());
                this.native_player_info_list.push(nativePlayerInfo);
                return nativePlayerInfo.player;
              });
            })
            .onNativeEmbedGestureEvent((event)=>{
              if (!event.touchEvent || !event.embedId) {
                event.result?.setGestureEventResult(false);
                return;
              }
              console.log(`WebComponent.onNativeEmbedGestureEvent, embedId[${event.embedId}]`);
              let native_player_info = this.getNativePlayerInfoByEmbedId(event.embedId);
              if (!native_player_info) {
                console.log(`WebComponent.onNativeEmbedGestureEvent, embedId[${event.embedId}], no native_player_info`);
                event.result?.setGestureEventResult(false);
                return;
              }
              if (!native_player_info.node_controller) {
                console.log(`WebComponent.onNativeEmbedGestureEvent, embedId[${event.embedId}], no node_controller`);
                event.result?.setGestureEventResult(false);
                return;
              }
              let ret = native_player_info.node_controller.postTouchEvent(event.touchEvent);
              console.log(`WebComponent.postTouchEvent, ret[${ret}], touchEvent[${JSON.stringify(event.touchEvent)}]`);
              event.result?.setGestureEventResult(ret);
            })
            .width('100%')
            .height('100%')
            .onAreaChange((oldValue: Area, newValue: Area) => {
              oldValue;
              this.area = newValue;
            })
        }
      }
    }

    getNativePlayerInfoByEmbedId(embedId: string) : NativePlayerInfo | undefined {
      return this.native_player_info_list.find((item)=> item.embed_id == embedId);
    }
  }
  ```

- 应用侧代码，视频播放示例, ./PlayerDemo.ets。

  ```ts
  import { media } from '@kit.MediaKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  export interface AVPlayerListener {
    onPlaying() : void;
    onPaused() : void;
    onDurationChanged(duration: number) : void;
    onBufferedTimeChanged(buffered: number) : void;
    onTimeUpdate(time: number) : void;
    onEnded() : void;
    onError() : void;
    onVideoSizeChanged(width: number, height: number): void;
    onDestroyed(): void;
  }

  interface PlayerParam {
    url: string;
    listener?: AVPlayerListener;
    httpHeaders?: Record<string, string>;
  }

  interface PlayCommand {
    func: Function;
    name?: string;
  }

  interface CheckPlayCommandResult {
    ignore: boolean;
    index_to_remove: number;
  }

  export class AVPlayerDemo {
    private surfaceID: string = ''; // surfaceID用于播放画面显示，具体的值需要通过Xcomponent接口获取，相关文档链接见上面Xcomponent创建方法

    avPlayer?: media.AVPlayer;
    prepared: boolean = false;

    commands: PlayCommand[] = [];

    setSurfaceID(surface_id: string) {
      console.log(`AVPlayerDemo.setSurfaceID : ${surface_id}`);
      this.surfaceID = surface_id;
    }
    // 注册avplayer回调函数
    setAVPlayerCallback(avPlayer: media.AVPlayer, listener?: AVPlayerListener) {
      // seek操作结果回调函数
      avPlayer.on('seekDone', (seekDoneTime: number) => {
        console.info(`AVPlayer seek succeeded, seek time is ${seekDoneTime}`);
      });
      // error回调监听函数,当avPlayer在操作过程中出现错误时调用reset接口触发重置流程
      avPlayer.on('error', (err: BusinessError) => {
        console.error(`Invoke avPlayer failed, code is ${err.code}, message is ${err.message}`);
        listener?.onError();
        avPlayer.reset(); // 调用reset重置资源，触发idle状态
      });
      // 状态机变化回调函数
      avPlayer.on('stateChange', async (state: string, reason: media.StateChangeReason) => {
        switch (state) {
          case 'idle': // 成功调用reset接口后触发该状态机上报
            console.info('AVPlayer state idle called.');
            avPlayer.release(); // 调用release接口销毁实例对象
            break;
          case 'initialized': // avplayer 设置播放源后触发该状态上报
            console.info('AVPlayer state initialized called.');
            avPlayer.surfaceId = this.surfaceID; // 设置显示画面，当播放的资源为纯音频时无需设置
            avPlayer.prepare();
            break;
          case 'prepared': // prepare调用成功后上报该状态机
            console.info('AVPlayer state prepared called.');
            this.prepared = true;
            this.schedule();
            break;
          case 'playing': // play成功调用后触发该状态机上报
            console.info('AVPlayer state playing called.');
            listener?.onPlaying();
            break;
          case 'paused': // pause成功调用后触发该状态机上报
            console.info('AVPlayer state paused called.');
            listener?.onPaused();
            break;
          case 'completed': // 播放结束后触发该状态机上报
            console.info('AVPlayer state completed called.');
            avPlayer.stop(); //调用播放结束接口
            break;
          case 'stopped': // stop接口成功调用后触发该状态机上报
            console.info('AVPlayer state stopped called.');
            listener?.onEnded();
            break;
          case 'released':
            this.prepared = false;
            listener?.onDestroyed();
            console.info('AVPlayer state released called.');
            break;
          default:
            console.info('AVPlayer state unknown called.');
            break;
        }
      });
      avPlayer.on('durationUpdate', (duration: number) => {
        console.info(`AVPlayer state durationUpdate success,new duration is :${duration}`);
        listener?.onDurationChanged(duration/1000);
      });
      avPlayer.on('timeUpdate', (time:number) => {
        listener?.onTimeUpdate(time/1000);
      });
      avPlayer.on('bufferingUpdate', (infoType: media.BufferingInfoType, value: number) => {
        console.info(`AVPlayer state bufferingUpdate success,and infoType value is:${infoType}, value is : ${value}`);
        if (infoType == media.BufferingInfoType.BUFFERING_PERCENT) {
        }
        listener?.onBufferedTimeChanged(value);
      })
      avPlayer.on('videoSizeChange', (width: number, height: number) => {
        console.info(`AVPlayer state videoSizeChange success,and width is:${width}, height is : ${height}`);
        listener?.onVideoSizeChanged(width, height);
      })
    }

    // 以下示例通过URL设置网络地址来播放直播码流
    async avPlayerLiveDemo(playerParam: PlayerParam) {
      // 创建avPlayer实例对象
      this.avPlayer = await media.createAVPlayer();
      // 创建状态机变化回调函数
      this.setAVPlayerCallback(this.avPlayer, playerParam.listener);

      let mediaSource: media.MediaSource = media.createMediaSourceWithUrl(playerParam.url, playerParam.httpHeaders);
      let strategy: media.PlaybackStrategy = {
        preferredWidth: 100,
        preferredHeight: 100,
        preferredBufferDuration: 100,
        preferredHdr: false
      };
      this.avPlayer.setMediaSource(mediaSource, strategy);
      console.log(`AVPlayer url:[${playerParam.url}]`);
    }

    schedule() {
      if (!this.avPlayer) {
        return;
      }
      if (!this.prepared) {
        return;
      }
      if (this.commands.length > 0) {
        let command = this.commands.shift();
        if (command) {
          command.func();
        }
        if (this.commands.length > 0) {
          setTimeout(() => {
            this.schedule();
          });
        }
      }
    }

    private checkCommand(selfName: string, oppositeName: string) {
      let index_to_remove = -1;
      let ignore_this_action = false;
      let index = this.commands.length - 1;
      while (index >= 0) {
        if (this.commands[index].name == selfName) {
          ignore_this_action = true;
          break;
        }
        if (this.commands[index].name == oppositeName) {
          index_to_remove = index;
          break;
        }
        index--;
      }

      let result : CheckPlayCommandResult = {
        ignore: ignore_this_action,
        index_to_remove: index_to_remove,
      };
      return result;
    }

    play() {
      let commandName = 'play';
      let checkResult = this.checkCommand(commandName, 'pause');
      if (checkResult.ignore) {
        console.log(`AVPlayer ${commandName} ignored.`);
        this.schedule();
        return;
      }
      if (checkResult.index_to_remove >= 0) {
        let removedCommand = this.commands.splice(checkResult.index_to_remove, 1);
        console.log(`AVPlayer ${JSON.stringify(removedCommand)} removed.`);
        return;
      }
      this.commands.push({ func: ()=>{
        console.info('AVPlayer.play()');
        this.avPlayer?.play();
      }, name: commandName});
      this.schedule();
    }
    pause() {
      let commandName = 'pause';
      let checkResult = this.checkCommand(commandName, 'play');
      console.log(`checkResult:${JSON.stringify(checkResult)}`);
      if (checkResult.ignore) {
        console.log(`AVPlayer ${commandName} ignored.`);
        this.schedule();
        return;
      }
      if (checkResult.index_to_remove >= 0) {
        let removedCommand = this.commands.splice(checkResult.index_to_remove, 1);
        console.log(`AVPlayer ${JSON.stringify(removedCommand)} removed.`);
        return;
      }
      this.commands.push({ func: ()=>{
        console.info('AVPlayer.pause()');
        this.avPlayer?.pause();
      }, name: commandName});
      this.schedule();
    }
    release() {
      this.commands.push({ func: ()=>{
        console.info('AVPlayer.release()');
        this.avPlayer?.release();
      }});
      this.schedule();
    }
    seek(time: number) {
      this.commands.push({ func: ()=>{
        console.info(`AVPlayer.seek(${time})`);
        this.avPlayer?.seek(time * 1000);
      }});
      this.schedule();
    }
    setVolume(volume: number) {
      this.commands.push({ func: ()=>{
        console.info(`AVPlayer.setVolume(${volume})`);
        this.avPlayer?.setVolume(volume);
      }});
      this.schedule();
    }
    setPlaybackRate(playbackRate: number) {
      let speed = media.PlaybackSpeed.SPEED_FORWARD_1_00_X;
      let delta = 0.05;
      playbackRate += delta;
      if (playbackRate < 1) {
        speed = media.PlaybackSpeed.SPEED_FORWARD_0_75_X;
      } else if (playbackRate < 1.25) {
        speed = media.PlaybackSpeed.SPEED_FORWARD_1_00_X;
      } else if (playbackRate < 1.5) {
        speed = media.PlaybackSpeed.SPEED_FORWARD_1_25_X;
      } else if (playbackRate < 2) {
        speed = media.PlaybackSpeed.SPEED_FORWARD_1_75_X;
      } else {
        speed = media.PlaybackSpeed.SPEED_FORWARD_2_00_X;
      }
      this.commands.push({ func: ()=>{
        console.info(`AVPlayer.setSpeed(${speed})`);
        this.avPlayer?.setSpeed(speed);
      }});
      this.schedule();
    }
  }
  ```

- 前端页面示例。

  ```html
  <html>
  <head>
      <title>视频托管测试html</title>
      <meta name="viewport" content="width=device-width">
  </head>
  <body>
  <div>
      <!-- 使用时需要自行替换视频链接 -->
      <video src='https://xxx.xxx/demo.mp4' style='width: 100%'></video>
  </div>
  </body>
  </html>
  ```