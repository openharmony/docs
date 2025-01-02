# Taking Over the Media Playback on Web Pages

The **Web** component provides the capability for applications to take over media playback on web pages, which improves media playback qualities on the web page.

## When to Use

On web pages, media players are simple and provide few functions, with lower video quality and some videos cannot be played.

In this case, you can use your own or a third-party player to take over web page media playback to improve media playback experience.

## Implementation Principle

### Framework of Using the ArkWeb Kernel to Play Media

When web media playback takeover is disabled, the playback architecture of the ArkWeb kernel is as follows:

  ![arkweb media pipeline](figures/arkweb_media_pipeline.png)

  > **NOTE**
  >
  > - In the preceding figure, step 1 indicates that the ArkWeb kernel creates a **WebMediaPlayer** to play media resources on web pages.
  > - Step 2 indicates that the **WebMediaPlayer** uses the system decoder to render media data.

When web media playback takeover is enabled, the playback architecture of the ArkWeb kernel is as follows:

  ![arkweb native media player](figures/arkweb_native_media_player.png)

  > **NOTE**
  >
  > - In the preceding figure, step 1 indicates that the ArkWeb kernel creates a **WebMediaPlayer** to play media resources on web pages.
  > - Step 2 indicates that **WebMediaPlayer** uses **NativeMediaPlayer** provided by the application to render media data.


### Interactions Between the ArkWeb Kernel and Application

  ![interactions between arkweb and native media player](figures/interactions_between_arkweb_and_native_media_player.png)

  > **NOTE**
  >
  > - For details about step 1 in the preceding figure, see [Enabling Web Media Playback Takeover](#enabling-web-media-playback-takeover).
  > - For details about step 2, see [Creating a Native Media Player](#creating-a-native-media-player).
  > - For details about step 3, see [Drawing Native Media Player Components](#drawing-native-media-player-components).
  > - For details about step 4, see [Executing Playback Control Commands Sent by ArkWeb Kernel to the Native Media Player](#executing-playback-control-commands-sent-by-arkweb-kernel-to-the-native-media-player).
  > - For details about step 5, see [Notifying the Status Information of Native Media Player to the ArkWeb Kernel](#notifying-the-status-information-of-native-media-player-to-the-arkweb-kernel).

## How to Develop

### Enabling Web Media Playback Takeover

You need to use the [enableNativeMediaPlayer](../reference/apis-arkweb/ts-basic-components-web.md#enablenativemediaplayer12) API to enable the function of taking over web page media playback.

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

### Creating a Native Media Player

Once web media playback takeover is enabled, the ArkWeb kernel triggers the callback registered by [onCreateNativeMediaPlayer](../reference/apis-arkweb/js-apis-webview.md#oncreatenativemediaplayer12) each time a media file needs to be played on the web page.

You need to register a callback for creating a native media player by invoking **onCreateNativeMediaPlayer**.

The callback function determines whether to create a native media player to take over the web page media resources based on the media information.

  * If the application does not take over the web page media resource, **null** is returned in the callback function.
  * If the application takes over the web page media resource, a native media player instance is returned in the callback function.

The native media player needs to implement the [NativeMediaPlayerBridge](../reference/apis-arkweb/js-apis-webview.md#nativemediaplayerbridge12) API so that the ArkWeb kernel can control the playback on the native media player.

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  // Implement the webview.NativeMediaPlayerBridge API.
  // The ArkWeb kernel calls the webview.NativeMediaPlayerBridge methods to control playback on NativeMediaPlayer.
  class NativeMediaPlayerImpl implements webview.NativeMediaPlayerBridge {
    // ...Implement the APIs in NativeMediaPlayerBridge...
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
              // Determine whether to take over the media.
              if (!shouldHandle(mediaInfo)) {
                // The native media player does not take over the media.
                // Return null. The ArkWeb kernel will play the media with the web media player.
                return null;
              }
              // Take over the web media.
              // Return a native media player instance to the ArkWeb kernel.
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

### Drawing Native Media Player Components

When an application takes over the media playback on web pages, you need to draw the native media player component and video images on the surface provided by the ArkWeb kernel. Then the ArkWeb kernel combines the surface with the web page and displays it on the screen.

This process is the same as that of [Rendering and Drawing XComponent+AVPlayer and Button Components at the Same Layer](web-same-layer.md#)

1. In the application startup phase, **UIContext** must be saved so that it can be used in subsequent rendering and drawing processes at the same layer.

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
         // Save UIContext, which will be used in subsequent rendering and drawing at the same layer.
         AppStorage.setOrCreate<UIContext>("UIContext", windowStage.getMainWindowSync().getUIContext());
       });
     }

     // ...Other APIs that need to be overridden...
   }
   ```

2. Use the surface created by the ArkWeb kernel for rendering and drawing at the same layer.

   ```ts
   // xxx.ets
   import { webview } from '@kit.ArkWeb';
   import { BuilderNode, FrameNode, NodeController, NodeRenderType } from '@kit.ArkUI';

   interface ComponentParams {}

   class MyNodeController extends NodeController {
     private rootNode: BuilderNode<[ComponentParams]> | undefined;

     constructor(surfaceId: string, renderType: NodeRenderType) {
       super();

       // Obtain the saved UIContext.
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
       // Construct the native media player component.
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
                 // Take over the web media.

                 // Use the surface provided by the rendering at the same layer to construct a native media player component.
                 this.node_controller = new MyNodeController(mediaInfo.surfaceInfo.id, NodeRenderType.RENDER_TYPE_TEXTURE);
                 this.node_controller.build();

                 // Show the native media player component.
                 this.show_native_media_player = true;

                 // Return a native media player instance to the ArkWeb kernel.
                 return null;
               });
             })
         }
       }
     }
   }
   ```

For details about how to dynamically create components and draw them on the surface, see [Rendering and Drawing XComponent+AVPlayer and Button Components at the Same Layer](web-same-layer.md#).

### Executing Playback Control Commands Sent by ArkWeb Kernel to the Native Media Player

To facilitate the control over native media player by the ArkWeb kernel, you need to implement the [NativeMediaPlayerBridge](../reference/apis-arkweb/js-apis-webview.md#nativemediaplayerbridge12) API on the native media player and operate the native media player based on the function of each API.

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  class ActualNativeMediaPlayerListener {
    constructor(handler: webview.NativeMediaPlayerHandler) {}
  }

  class NativeMediaPlayerImpl implements webview.NativeMediaPlayerBridge {
    constructor(handler: webview.NativeMediaPlayerHandler, mediaInfo: webview.MediaInfo) {
      // 1. Create a listener for the native media player.
      let listener: ActualNativeMediaPlayerListener = new ActualNativeMediaPlayerListener(handler);
      // 2. Create a native media player.
      // 3. Listen for the native media player.
      // ...
    }

    updateRect(x: number, y: number, width: number, height: number) {
      // The position and size of the <video> tag are changed.
      // Make changes based on the information change.
    }

    play() {
      // Starts the native media player for playback.
    }

    pause() {
      // Pause the playback.
    }

    seek(targetTime: number) {
      // The native media player seeks to the target playback time.
    }

    release() {
      // Destroy the native media player.
    }

    setVolume(volume: number) {
      // The ArkWeb kernel adjusts the volume of the native media player.
      // Set the volume of the native media player.
    }

    setMuted(muted: boolean) {
      // Mute or unmute the native media player.
    }

    setPlaybackRate(playbackRate: number) {
      // Set the playback rate of the native media player.
    }

    enterFullscreen() {
      // Enter the full-screen mode.
    }

    exitFullscreen() {
      // Exit the full-screen mode.
    }
  }
  ```

### Notifying the Status Information of Native Media Player to the ArkWeb Kernel

The ArkWeb kernel need to update the status information (such as the video width and height, playback time, and cache time) of the native player to the web page. Therefore, you need to notify the ArkWeb kernel of the status information of the native player.

Through the [onCreateNativeMediaPlayer](../reference/apis-arkweb/js-apis-webview.md#oncreatenativemediaplayer12) API, the Ark Web kernel passes a [NativeMediaPlayerHandler](../reference/apis-arkweb/js-apis-webview.md#nativemediaplayerhandler12) object to the application. You need to use this object to notify the ArkWeb kernel of the latest status information of the native media player.

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  class ActualNativeMediaPlayerListener {
    handler: webview.NativeMediaPlayerHandler;

    constructor(handler: webview.NativeMediaPlayerHandler) {
      this.handler = handler;
    }

    onPlaying() {
      // The native media player starts playback.
      this.handler.handleStatusChanged(webview.PlaybackStatus.PLAYING);
    }
    onPaused() {
      // The native media player pauses the playback.
      this.handler.handleStatusChanged(webview.PlaybackStatus.PAUSED);
    }
    onSeeking() {
      // The native media player starts to seek the target time point.
      this.handler.handleSeeking();
    }
    onSeekDone() {
      // The target time point is sought.
      this.handler.handleSeekFinished();
    }
    onEnded() {
      // The playback on the native media player is ended.
      this.handler.handleEnded();
    }
    onVolumeChanged() {
      // Obtain the volume of the native media player.
      let volume: number = getVolume();
      this.handler.handleVolumeChanged(volume);
    }
    onCurrentPlayingTimeUpdate() {
      // Update the playback time.
      let currentTime: number = getCurrentPlayingTime();
      // Convert the time unit to second.
      let currentTimeInSeconds = convertToSeconds(currentTime);
      this.handler.handleTimeUpdate(currentTimeInSeconds);
    }
    onBufferedChanged() {
      // The buffer is changed.
      // Obtain the cache duration of the native media player.
      let bufferedEndTime: number = getCurrentBufferedTime();
      // Convert the time unit to second.
      let bufferedEndTimeInSeconds = convertToSeconds(bufferedEndTime);
      this.handler.handleBufferedEndTimeChanged(bufferedEndTimeInSeconds);

      // Check the cache state.
      // If the cache state changes, notify the ArkWeb engine of the cache state.
      let lastReadyState: webview.ReadyState = getLastReadyState();
      let currentReadyState: webview.ReadyState = getCurrentReadyState();
      if (lastReadyState != currentReadyState) {
        this.handler.handleReadyStateChanged(currentReadyState);
      }
    }
    onEnterFullscreen() {
      // The native media player enters the full-screen mode.
      let isFullscreen: boolean = true;
      this.handler.handleFullscreenChanged(isFullscreen);
    }
    onExitFullscreen() {
      // The native media player exits the full-screen mode.
      let isFullscreen: boolean = false;
      this.handler.handleFullscreenChanged(isFullscreen);
    }
    onUpdateVideoSize(width: number, height: number) {
      // Notify the ArkWeb kernel of the video width and height parsed by the native player.
      this.handler.handleVideoSizeChanged(width, height);
    }
    onDurationChanged(duration: number) {
      // Notify the ArkWeb kernel of the new media duration parsed by the native player.
      this.handler.handleDurationChanged(duration);
    }
    onError(error: webview.MediaError, errorMessage: string) {
      // Notify the ArkWeb kernel that an error occurs in the native player.
      this.handler.handleError(error, errorMessage);
    }
    onNetworkStateChanged(state: webview.NetworkState) {
      // Notify the ArkWeb kernel that the network state of the native player changes.
      this.handler.handleNetworkStateChanged(state);
    }
    onPlaybackRateChanged(playbackRate: number) {
      // Notify the ArkWeb kernel that the playback rate of the native player changes.
      this.handler.handlePlaybackRateChanged(playbackRate);
    }
    onMutedChanged(muted: boolean) {
      // Notify the ArkWeb kernel that the native player is muted.
      this.handler.handleMutedChanged(muted);
    }

    // ...Listen for other status of the native player.
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
              // Take over the web media.

              // Create a native media player instance.
              // let nativePlayer: NativeMediaPlayerImpl = new NativeMediaPlayerImpl(handler, mediaInfo);

              // Create a listener for the native media player state. 
              let nativeMediaPlayerListener: ActualNativeMediaPlayerListener = new ActualNativeMediaPlayerListener(handler);
              // Listen for the native media player state.
              // nativePlayer.setListener(nativeMediaPlayerListener);

              // Return the native media player instance to the ArkWeb kernel.
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


## Sample Code

- Add the following permissions to **module.json5** before using it:

  ```ts
  "ohos.permission.INTERNET"
  ```

- Example of saving **UIContext** during application startup on the application side:

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
        // Save UIContext, which will be used in subsequent rendering and drawing at the same layer.
        AppStorage.setOrCreate<UIContext>("UIContext", windowStage.getMainWindowSync().getUIContext());
      });
    }

    // ...Other APIs that need to be overridden...
  }
  ```

- Example of web media playback takeover:

  ```ts
  // Index.ets

  import { webview } from '@kit.ArkWeb';
  import { BuilderNode, FrameNode, NodeController, NodeRenderType, UIContext } from '@kit.ArkUI';
  import { AVPlayerDemo, AVPlayerListener } from './PlayerDemo';

  // Implement the webview.NativeMediaPlayerBridge API.
  // The ArkWeb kernel calls the APIs to control playback on NativeMediaPlayer.
  class NativeMediaPlayerImpl implements webview.NativeMediaPlayerBridge {
    private surfaceId: string;
    mediaSource: string;
    private mediaHandler: webview.NativeMediaPlayerHandler;
    nativePlayerInfo: NativePlayerInfo;
    nativePlayer: AVPlayerDemo;
    httpHeaders: Record<string, string>;

    constructor(nativePlayerInfo: NativePlayerInfo, handler: webview.NativeMediaPlayerHandler, mediaInfo: webview.MediaInfo) {
      console.log(`NativeMediaPlayerImpl.constructor, surface_id[${mediaInfo.surfaceInfo.id}]`);
      this.nativePlayerInfo = nativePlayerInfo;
      this.mediaHandler = handler;
      this.surfaceId = mediaInfo.surfaceInfo.id;
      this.mediaSource = mediaInfo.mediaSrcList.find((item)=>{item.source.indexOf('.mp4') > 0})?.source
        || mediaInfo.mediaSrcList[0].source;
      this.httpHeaders = mediaInfo.headers;
      this.nativePlayer = new AVPlayerDemo();

      // Use the rendering function at the same layer to draw the video and its playback control components to the web page.
      this.nativePlayerInfo.node_controller = new MyNodeController(
        this.nativePlayerInfo, this.surfaceId, this.mediaHandler, this, NodeRenderType.RENDER_TYPE_TEXTURE);
      this.nativePlayerInfo.node_controller.build();
      this.nativePlayerInfo.show_native_media_player = true;

      console.log(`NativeMediaPlayerImpl.mediaSource: ${this.mediaSource}, headers: ${JSON.stringify(this.httpHeaders)}`);
    }

    updateRect(x: number, y: number, width: number, height: number): void {
      let width_in_vp = px2vp(width);
      let height_in_vp = px2vp(height);
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

  // Listen for the NativeMediaPlayer status and report the status to the ArkWeb kernel using webview.NativeMediaPlayerHandler.
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

  // Define the player components.
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

  // Use NodeController to dynamically create a player component and draw the component content on the surface specified by surfaceId.
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

    static toNodeRect(rectInPx: webview.RectEvent) : Rect {
      let rect = new Rect();
      rect.x = px2vp(rectInPx.x);
      rect.y = px2vp(rectInPx.x);
      rect.width = px2vp(rectInPx.width);
      rect.height = px2vp(rectInPx.height);
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

    constructor(web: WebComponent, handler: webview.NativeMediaPlayerHandler, videoInfo: webview.MediaInfo) {
      this.web = web;
      this.embed_id = videoInfo.embedID;

      let node_rect = Rect.toNodeRect(videoInfo.surfaceInfo.rect);
      this.node_pos_x = node_rect.x;
      this.node_pos_y = node_rect.y;
      this.node_width = node_rect.width;
      this.node_height = node_rect.height;

      this.player = new NativeMediaPlayerImpl(this, handler, videoInfo);
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
      let node_rect = Rect.toNodeRect({x, y, width, height});
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
                let nativePlayerInfo = new NativePlayerInfo(this, handler, mediaInfo);
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

- Example of using video playback on the application side:

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
    private surfaceID: string = ''; // The surfaceID parameter specifies the window used to display the video. Its value is obtained through the XComponent.

    avPlayer?: media.AVPlayer;
    prepared: boolean = false;

    commands: PlayCommand[] = [];

    setSurfaceID(surface_id: string) {
      console.log(`AVPlayerDemo.setSurfaceID : ${surface_id}`);
      this.surfaceID = surface_id;
    }
    // Set AVPlayer callback functions.
    setAVPlayerCallback(avPlayer: media.AVPlayer, listener?: AVPlayerListener) {
      // Callback function for the seek operation.
      avPlayer.on('seekDone', (seekDoneTime: number) => {
        console.info(`AVPlayer seek succeeded, seek time is ${seekDoneTime}`);
      });
      // Callback function for errors. If an error occurs during the operation on the AVPlayer, reset() is called to reset the AVPlayer.
      avPlayer.on('error', (err: BusinessError) => {
        console.error(`Invoke avPlayer failed, code is ${err.code}, message is ${err.message}`);
        listener?.onError();
        avPlayer.reset(); // Call reset() to reset the AVPlayer, which enters the idle state.
      });
      // Callback for state changes.
      avPlayer.on('stateChange', async (state: string, reason: media.StateChangeReason) => {
        switch (state) {
          case 'idle': // This state is reported upon a successful callback of reset().
            console.info('AVPlayer state idle called.');
            avPlayer.release(); // Call release() to release the instance.
            break;
          case 'initialized': // This state is reported when the AVPlayer sets the playback source.
            console.info('AVPlayer state initialized called.');
            avPlayer.surfaceId = this.surfaceID; // Set the window to display the video. This setting is not required when a pure audio asset is to be played.
            avPlayer.prepare();
            break;
          case 'prepared': // This state is reported upon a successful callback of prepare().
            console.info('AVPlayer state prepared called.');
            this.prepared = true;
            this.schedule();
            break;
          case 'playing': // This state is reported upon a successful callback of play().
            console.info('AVPlayer state playing called.');
            listener?.onPlaying();
            break;
          case 'paused': // This state is reported upon a successful callback of pause().
            console.info('AVPlayer state paused called.');
            listener?.onPaused();
            break;
          case 'completed': // This state is reported upon the completion of the playback.
            console.info('AVPlayer state completed called.');
            avPlayer.stop(); // Call stop() to stop the playback.
            break;
          case 'stopped': // This state is reported upon a successful callback of stop().
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

    // The following demo shows how to play live streams by setting the network address through the URL.
    async avPlayerLiveDemo(playerParam: PlayerParam) {
      // Create an AVPlayer instance.
      this.avPlayer = await media.createAVPlayer();
      // Create a callback for state changes.
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

- Example of a frontend page:

  ```html
  <html>
  <head>
      <title>Video Hosting Test html</title>
      <meta name="viewport" content="width=device-width">
  </head>
  <body>
  <div>
      <!--Replace the URL with the actual URL of the video source.-->
      <video src='https://xxx.xxx/demo.mp4' style='width: 100%'></video>
  </div>
  </body>
  </html>
  ```
