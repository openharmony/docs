# Rendering and Drawing XComponent+AVPlayer and Button Components at the Same Layer

For details about the components that support same-layer rendering, see [NodeRenderType](../reference/apis-arkui/js-apis-arkui-builderNode.md#noderendertype).

You enable or disable same-layer rendering through [enableNativeEmbedMode()](../reference/apis-arkweb/ts-basic-components-web.md#enablenativeembedmode11). To use same-layer rendering, the **\<embed>** element must be explicitly used in the HTML file, and the **type** attribute of the element must start with **native/**.


The background color for same-layer rendering is white. Only one layer of **\<Web>** components can be nested.


- To start with, add the following permission to the **module.json5** file:
  
  ```ts
  "ohos.permission.INTERNET"
  ```

- Example of using same-layer rendering on the application side:

  ```ts
  // Create a NodeController instance.
  import webview from '@ohos.web.webview';
  import {UIContext} from '@ohos.arkui.UIContext';
  import {NodeController, BuilderNode, NodeRenderType, FrameNode} from "@ohos.arkui.node";
  import {AVPlayerDemo} from './PlayerDemo';

  @Observed
  declare class Params {
    textOne : string
    textTwo : string
    width : number
    height : number
  }

  declare class nodeControllerParams {
    surfaceId : string
    type : string
    renderType : NodeRenderType
    embedId : string
    width : number
    height : number
  }

  // The NodeController instance must be used with a <NodeContainer> for controlling and feeding back the behavior of the nodes in the container.
  class MyNodeController extends NodeController {
    private rootNode: BuilderNode<[Params]> | undefined | null;
    private embedId_ : string = "";
    private surfaceId_ : string = "";
    private renderType_ :NodeRenderType = NodeRenderType.RENDER_TYPE_DISPLAY;
    private width_ : number = 0;
    private height_ : number = 0;
    private type_ : string = "";
    private isDestroy_ : boolean = false;

    setRenderOption(params : nodeControllerParams) {
      this.surfaceId_ = params.surfaceId;
      this.renderType_ = params.renderType;
      this.embedId_ = params.embedId;
      this.width_ = params.width;
      this.height_ = params.height;
      this.type_ = params.type;
    }
    // Method that must be overridden. It is used to build the number of nodes and return the number of nodes that will be mounted to the corresponding <NodeContainer>.
    // Called when the corresponding <NodeContainer> is created or called by the rebuild method.
    makeNode(uiContext: UIContext): FrameNode | null{
      if (this.isDestroy_) { // rootNode is null.
        return null;
      }
      if (!this.rootNode) { // When rootNode is set to undefined
        this.rootNode = new BuilderNode(uiContext, { surfaceId: this.surfaceId_, type: this.renderType_});
        if (this.type_ === 'native/button') {
          this.rootNode.build(wrapBuilder(ButtonBuilder), {textOne: "myButton1", textTwo : "myButton2", width : this.width_, height : this.height_});
        } else if (this.type_ === 'native/video') {
          this.rootNode.build(wrapBuilder(VideoBuilder), {textOne: "myButton", width : this.width_, height : this.height_});
        } else {
          // other
        }
      }
      // Return the FrameNode object.
      return this.rootNode.getFrameNode();
    }

    setBuilderNode(rootNode: BuilderNode<Params[]> | null): void{
      this.rootNode = rootNode;
    }

    getBuilderNode(): BuilderNode<[Params]> | undefined | null{
      return this.rootNode;
    }

    updateNode(arg: Object): void {
      this.rootNode?.update(arg);
    }
    getEmbedId() : string {
      return this.embedId_;
    }

    setDestroy(isDestroy : boolean) : void {
      this.isDestroy_ = isDestroy;
      if (this.isDestroy_) {
        this.rootNode = null;
      }
    }

    postEvent(event: TouchEvent | undefined) : boolean {
      return this.rootNode?.postTouchEvent(event) as boolean
    }
  }

  @Component
  struct ButtonComponent {
    @ObjectLink params: Params
    @State bkColor: Color = Color.Red

    build() {
      Column() {
        Button(this.params.textOne)
          .border({ width: 2, color: Color.Red})
          .backgroundColor(this.bkColor)

        Button(this.params.textTwo)
          .border({ width: 2, color: Color.Red})
          .backgroundColor(this.bkColor)
      }
      .width(this.params.width)
      .height(this.params.height)
    }
  }

  @Component
  struct VideoComponent {
    @ObjectLink params: Params
    @State bkColor: Color = Color.Red
    mXComponentController: XComponentController = new XComponentController();
    @State player_changed: boolean = false;
    player?: AVPlayerDemo;

    build() {
      Column() {
        Button(this.params.textOne)
          .border({ width: 2, color: Color.Red})
          .backgroundColor(this.bkColor)

        XComponent({ id: 'video_player_id', type: XComponentType.SURFACE, controller: this.mXComponentController})
          .border({width: 1, color: Color.Red})
          .onLoad(() => {
            this.player = new AVPlayerDemo();
            this.player.setSurfaceID(this.mXComponentController.getXComponentSurfaceId());
            this.player_changed = !this.player_changed;
            this.player.avPlayerLiveDemo()
          })
      }
      .width(this.params.width)
      .height(this.params.height)
    }
  }
  // In @Builder, add the specific dynamic component content.
  @Builder
  function ButtonBuilder(params: Params) {
    ButtonComponent({ params: params })
      .backgroundColor(Color.Green)
  }

  @Builder
  function VideoBuilder(params: Params) {
    VideoComponent({ params: params })
      .backgroundColor(Color.Green)
  }

  @Entry
  @Component
  struct WebIndex {
    browserTabController: WebviewController = new webview.WebviewController()
    private nodeControllerMap: Map<string, MyNodeController> = new Map();
    @State componentIdArr: Array<string> = [];

    aboutToAppear() {
      // Enable web frontend page debugging.
      webview.WebviewController.setWebDebuggingAccess(true);
    }

    build(){
      Row() {
        Column() {
          Stack() {
            ForEach(this.componentIdArr, (componentId: string) => {
              NodeContainer(this.nodeControllerMap.get(componentId))
            }, (embedId: string) => embedId)
            // Load the local test.html page in the <Web> component.
            Web({ src: $rawfile("test.html"), controller: this.browserTabController })
                // Enable same-layer rendering.
              .enableNativeEmbedMode(true)
                // Obtain the lifecycle change data of the <embed> element.
              .onNativeEmbedLifecycleChange((embed) => {
                console.log("NativeEmbed surfaceId" + embed.surfaceId);
                // Obtain the ID of the <embed> element on the web side.
                const componentId = embed.info?.id?.toString() as string
                if (embed.status == NativeEmbedStatus.CREATE) {
                  console.log("NativeEmbed create" + JSON.stringify(embed.info))
                  // Create a NodeController instance, set parameters, and rebuild.
                  let nodeController = new MyNodeController()
                  nodeController.setRenderOption({surfaceId : embed.surfaceId as string, type : embed.info?.type as string,
                    renderType : NodeRenderType.RENDER_TYPE_TEXTURE, embedId : embed.embedId as string,
                    width : px2vp(embed.info?.width), height : px2vp(embed.info?.height)})
                  nodeController.setDestroy(false);
                  // Save the NodeController instance to the map, with the ID attribute of the <embed> element passed in by the <Web> component as the key.
                  this.nodeControllerMap.set(componentId, nodeController)
                  // Save the ID attribute of the <embed> element passed in by the <Web> component to the @State decorated array variable for dynamically creating a node container. The push action must be executed after the set action.
                  this.componentIdArr.push(componentId)
                } else if (embed.status == NativeEmbedStatus.UPDATE) {
                  let nodeController = this.nodeControllerMap.get(componentId)
                  nodeController?.updateNode({textOne: 'update', width: px2vp(embed.info?.width), height: px2vp(embed.info?.height)} as ESObject)
                } else {
                  let nodeController = this.nodeControllerMap.get(componentId);
                  nodeController?.setDestroy(true)
                  this.nodeControllerMap.clear();
                  this.componentIdArr.length = 0;
                }
              })// Obtain the touch event information of components for same-layer rendering.
              .onNativeEmbedGestureEvent((touch) => {
                console.log("NativeEmbed onNativeEmbedGestureEvent" + JSON.stringify(touch.touchEvent));
                this.componentIdArr.forEach((componentId: string) => {
                  let nodeController = this.nodeControllerMap.get(componentId)
                  if (nodeController?.getEmbedId() === touch.embedId) {
                    let ret = nodeController?.postEvent(touch.touchEvent)
                    if (ret) {
                      console.log("onNativeEmbedGestureEvent success " + componentId)
                    } else {
                      console.log("onNativeEmbedGestureEvent fail " + componentId)
                    }
                    if (event.result) {
                      // Notify the <Web> component of the gesture event consumption result.
                      event.result.setGestureEventResult(ret);
                    }
                  }
                })
              })
          }
        }
      }
    }
  }
  ```
- Example of application code for video playback in **./PlayerDemo.ets**:

  ```ts
  import media from '@ohos.multimedia.media';
  import {BusinessError} from '@ohos.base';

  export class AVPlayerDemo {
    private count: number = 0;
    private surfaceID: string = ''; // The surfaceID parameter specifies the window used to display the video. Its value is obtained through the XComponent.
    private isSeek: boolean = true; // Specify whether the seek operation is supported.

    setSurfaceID(surface_id: string){
      console.log('setSurfaceID : ' + surface_id);
      this.surfaceID = surface_id;
    }
    // Set AVPlayer callback functions.
    setAVPlayerCallback(avPlayer: media.AVPlayer) {
      // Callback function for the seek operation.
      avPlayer.on('seekDone', (seekDoneTime: number) => {
        console.info(`AVPlayer seek succeeded, seek time is ${seekDoneTime}`);
      })
      // Callback function for errors. If an error occurs during the operation on the AVPlayer, reset() is called to reset the AVPlayer.
      avPlayer.on('error', (err: BusinessError) => {
        console.error(`Invoke avPlayer failed, code is ${err.code}, message is ${err.message}`);
        avPlayer.reset();
      })
      // Callback function for state changes.
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
            avPlayer.play(); // Call play() to start playback.
            break;
          case 'playing': // This state is reported upon a successful callback of play().
            console.info('AVPlayer state prepared called.');
            if(this.count !== 0) {
              if (this.isSeek) {
                console.info('AVPlayer start to seek.');
                avPlayer.seek(avPlayer.duration); // Call seek() to seek to the end of the video clip.
              } else {
                // When the seek operation is not supported, the playback continues until it reaches the end.
                console.info('AVPlayer wait to play end.');
              }
            } else {
              avPlayer.pause(); // Call pause() to pause the playback.
            }
            this.count++;
            break;
          case 'paused': // This state is reported upon a successful callback of pause().
            console.info('AVPlayer state paused called.');
            avPlayer.play(); // Call play() again to start playback.
            break;
          case 'completed': // This state is reported upon the completion of the playback.
            console.info('AVPlayer state paused called.');
            avPlayer.stop(); // Call stop() to stop the playback.
            break;
          case 'stopped': // This state is reported upon a successful callback of stop().
            console.info('AVPlayer state stopped called.');
            avPlayer.reset(); // Call reset() to reset the AVPlayer.
            break;
          case 'released': // This state is reported upon the release of the AVPlayer.
            console.info('AVPlayer state released called.');
            break;
          default:
            break;
        }
      })
    }

    // Set the live stream source through the URL.
    async avPlayerLiveDemo(){
      // Create an AVPlayer instance.
      let avPlayer: media.AVPlayer = await media.createAVPlayer();
      // Set a callback function for state changes.
      this.setAVPlayerCallback(avPlayer);
      this.isSeek = false; // The seek operation is not supported.
      avPlayer.url = 'https://xxx.xxx/demo.mp4';
    }
  }
  ```

- Example of the frontend page:

  ```html
  <!Document>
  <html>
  <head>
      <title>Same-layer rendering test html</title>
      <meta name="viewport">
  </head>
  <body>
  <div>
      <div id="bodyId">
          <embed id="nativeButton" type = "native/button" width="800" height="800" src="test?params1=xxx?" style = "background-color:red"/>
      </div>
      <div id="bodyId1">
          <embed id="nativeVideo" type = "native/video" width="500" height="500" src="test" style = "background-color:red"/>
      </div>
  </div>
  <div id="button" width="500" height="200">
      <p>bottom</p>
  </div>
  </body>
  </html>
  ```

  ![web-same-layer](figures/web-same-layer.png)
