# Rendering and Drawing Video and Button Components at the Same Layer

With the same-layer rendering feature of ArkWeb, you can render and draw native components at the same layer as the **\<Web>** component for your application. For details about the components that support same-layer rendering, see [NodeRenderType](../reference/apis-arkui/js-apis-arkui-builderNode.md#noderendertype).

- To start with, add the Internet permission to the **module.json5** file. For details, see [Declaring Permissions in the Configuration File](../security/AccessToken/declare-permissions.md).
  
   ```
   "requestPermissions":[
      {
        "name" : "ohos.permission.INTERNET"
      }
    ]
   ```

## Constraints
The following constraints apply when same-layer rendering is used:

- W3C standards-based tags cannot be defined as tags for same-layer rendering.

- The **<object>** tags and **\<embed>** tags cannot be configured for same-layer rendering at the same time.

- To deliver best possible performance, keep the number of tags at the same layer on a page within five.

- The maximum height of tags at the same layer is 8192 px, and the maximum texture size is 8192 px.

- Only one nesting level is supported for the **\<Web>** component. If multiple nesting levels are detected, an error message is displayed.

- The touchscreen events supported in the region for same-layer rendering include swiping, taping, scaling, and long pressing, while dragging is not supported.

- When same-layer rendering is enabled, web pages opened by the **\<Web>** component do not support the pinch gesture or scale APIs, including [initialScale](../reference/apis-arkweb/ts-basic-components-web.md#initialscale), [zoom](../reference/apis-arkweb/js-apis-webview.md#zoom), [zoomIn](../reference/apis-arkweb/js-apis-webview.md#zoomin), and [zoomOut](../reference/apis-arkweb/js-apis-webview.md#zoomout).

- The region for same-layer rendering does not support mouse, keyboard, and touchpad events.

- When same-layer rendering is enabled, web pages opened by the **\<Web>** component do not support the unified rendering mode [RenderMode](../reference/apis-arkweb/ts-basic-components-web.md#rendermode).


## Drawing the XComponent+AVPlayer and Button Components

### Enabling Same-Layer Rendering

You can enable or disable same-layer rendering through [enableNativeEmbedMode()](../reference/apis-arkweb/ts-basic-components-web.md#enablenativeembedmode11). To use same-layer rendering, the **\<embed>** element must be explicitly used in the HTML file, and the **type** attribute of the element must start with **native/**. The background of the elements corresponding to the tags at the same layer is transparent.

- Example of using same-layer rendering on the application side:

  ```ts
  // HAP's src/main/ets/pages/Index.ets
  // Create a NodeController instance.
  import { webview } from '@kit.ArkWeb';
  import { UIContext, NodeController, BuilderNode, NodeRenderType, FrameNode } from "@kit.ArkUI";
  import { AVPlayerDemo } from './PlayerDemo';

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

  // The NodeController instance must be used with a NodeContainer for controlling and feeding back the behavior of the nodes in the container.
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
    // Method that must be overridden. It is used to build the number of nodes and return the number of nodes that will be mounted to the corresponding NodeContainer.
    // Called when the corresponding NodeContainer is created or called by the rebuild method.
    makeNode(uiContext: UIContext): FrameNode | null{
      if (this.isDestroy_) { // rootNode is null.
        return null;
      }
      if (!this.rootNode) { // When rootNode is set to undefined
        this.rootNode = new BuilderNode(uiContext, { surfaceId: this.surfaceId_, type: this.renderType_});
        if (this.type_ === 'native/video') {
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
  struct VideoComponent {
    @ObjectLink params: Params
    @State bkColor: Color = Color.Red
    mXComponentController: XComponentController = new XComponentController();
    @State player_changed: boolean = false;
    player?: AVPlayerDemo;

    build() {
      Column() {
        Button(this.params.textOne)

        XComponent({ id: 'video_player_id', type: XComponentType.SURFACE, controller: this.mXComponentController})
          .border({width: 1, color: Color.Red})
          .onLoad(() => {
            this.player = new AVPlayerDemo();
            this.player.setSurfaceID(this.mXComponentController.getXComponentSurfaceId());
            this.player_changed = !this.player_changed;
            this.player.avPlayerLiveDemo()
          })
          .width(300)
          .height(200)
      }
      // The width and height of the outermost container in the custom component must be the width and height of the tag at the same layer.
      .width(this.params.width)
      .height(this.params.height)
    }
  }
  // In @Builder, add the specific dynamic component content.
  @Builder
  function VideoBuilder(params: Params) {
    VideoComponent({ params: params })
      .backgroundColor(Color.Gray)
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
            // Load the local test.html page.
            Web({ src: $rawfile("test.html"), controller: this.browserTabController })
                // Enable same-layer rendering.
              .enableNativeEmbedMode(true)
                // Obtain the lifecycle change data of the embed element.
              .onNativeEmbedLifecycleChange((embed) => {
                console.log("NativeEmbed surfaceId" + embed.surfaceId);
                // 1. If embed.info.id is used as the key for mapping nodeController, explicitly specify the ID on the HTML5 page.
                const componentId = embed.info?.id?.toString() as string
                if (embed.status == NativeEmbedStatus.CREATE) {
                  console.log("NativeEmbed create" + JSON.stringify(embed.info))
                  // Create a NodeController instance, set parameters, and rebuild.
                  let nodeController = new MyNodeController()
                  // 1. The unit of embed.info.width and embed.info.height is px, which needs to be converted to the default unit vp on the ets side.
                  nodeController.setRenderOption({surfaceId : embed.surfaceId as string, type : embed.info?.type as string,
                    renderType : NodeRenderType.RENDER_TYPE_TEXTURE, embedId : embed.embedId as string,
                    width : px2vp(embed.info?.width), height : px2vp(embed.info?.height)})
                  nodeController.setDestroy(false);
                  // Save the NodeController instance to the map, with the ID attribute of the embed element passed in by the Web component as the key.
                  this.nodeControllerMap.set(componentId, nodeController)
                  // Save the ID attribute of the embed element passed in by the Web component to the @State decorated array variable for creating a node container dynamically. The push action must be executed after the set action.
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
                  // Send the obtained event of the region at the same layer to the nodeController corresponding to embedId of the region.
                  if (nodeController?.getEmbedId() === touch.embedId) {
                    let ret = nodeController?.postEvent(touch.touchEvent)
                    if (ret) {
                      console.log("onNativeEmbedGestureEvent success " + componentId)
                    } else {
                      console.log("onNativeEmbedGestureEvent fail " + componentId)
                    }
                    if (touch.result) {
                      // Notify the <Web> component of the gesture event consumption result.
                      touch.result.setGestureEventResult(ret);
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

- Example of using video playback on the application side:

  ```ts
  // HAP's src/main/ets/pages/PlayerDemo.ets
  import { media } from '@kit.MediaKit';
  import { BusinessError } from '@ohos.base';

  export class AVPlayerDemo {
    private count: number = 0;
    private surfaceID: string = ''; // The surfaceID parameter specifies the window used to display the video. Its value is obtained through XComponent.
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
      // Replace the URL with the actual URL of the video source.
      avPlayer.url = 'https://xxx.xxx/demo.mp4';
    }
  }
  ```

- Example of the frontend page:

  ```html
  <!--HAP's src/main/resources/rawfile/test.html-->
  <!DOCTYPE html>
  <html>
  <head>
      <title>Same-layer rendering test html</title>
      <meta name="viewport">
  </head>
  <body>
  <div>
      <div id="bodyId">
          <embed id="nativeVideo" type = "native/video" width="1000" height="1500" src="test" style = "background-color:red"/>
      </div>
  </div>
  </body>
  </html>
  ```
  
  ![web-same-layer](figures/web-same-layer.png)

### Enabling Same-Layer Rendering and Specifying the Label Name and Custom Type

You can also use [registerNativeEmbedRule(tag: string, type: string)](../reference/apis-arkweb/ts-basic-components-web.md#registernativeembedrule12) to specify the tag and type.

For the **tag** parameter, only **embed** and **object** are supported. For the **type** parameter, you can specify any string. These two parameters are case insensitive: The ArkWeb kernel converts the values into lowercase letters. The **tag** parameter uses the full string for matching, and **type** uses the prefix for matching.

If you do not use this API or the API receives an invalid string (for example, an empty string), the kernel uses the default prefix mode "embed" + "native/". If the specified type is the same as any object or embedded type defined by W3C, as in **registerNativeEmbedRule("object", "application/pdf")**,
ArkWeb will follow the W3C standard behavior and will not identify it as a tag at the same layer.

- Example of using **registerNativeEmbedRule** on the application side: 

  ```ts
  class MyNodeController extends NodeController {
    ...
    makeNode(uiContext: UIContext): FrameNode | null{

      if (this.type_ === 'test') {
        ...
      } else if (this.type_ === 'test/video') {
        ...
      } else {
        // other
      }
	  ...
    }
    ...
  }
  ...

    build(){
        ...
          Stack() {
            ...
            Web({ src: $rawfile("test.html"), controller: this.browserTabController })
               // Enable same-layer rendering.
              .enableNativeEmbedMode(true)
               // Register the same-layer tag of "object" and type of "test."
              .registerNativeEmbedRule("object", "test")
              ...
		  }
		...
	}

  ```

- Example of using **registerNativeEmbedRule** on the frontend page, with the tag of "object" and type of "test":

  ```html

  <!DOCTYPE html>
  <html>
  <head>
      <title>Same-layer rendering test html</title>
      <meta name="viewport">
  </head>
  <body>
  <div>
      <div>
          <object id="nativeButton" type="test" width="800" height="800" data="test?params1=xxx?" style = "background-color:red"/>
            <param name="id" value="playerId" />
            <param name="data" value='{}' />
		  </object>
      </div>
      <div>
          <object id="nativeVideo" type="test/video" width="500" height="500" data="test" style = "background-color:red"/><object>
      </div>
  </div>
  <div id="button" width="500" height="200">
      <p>bottom</p>
  </div>

  </body>
  </html>
  ```

## Drawing the TextInput Component and Synchronizing Position Information Returned During Same-Layer Element Updates to the Component

The same-layer elements are updated as a result of scrolling, scaling, or any other behavior that may cause a re-layout. The positions of same-layer elements are based on the **\<Web>** component coordinate system. For web page scaling that does not change the element size, only the position changes, and the width and height remain at the initial values.

For components that require location information, such as **\<TextInput>** and **\<TextArea>**, you need to synchronize the location information reported by the same-layer elements to the components in real time.

- Complete sample code on the application side:

  ```ts
  ...
  class MyNodeController extends NodeController {
    ...
    makeNode(uiContext: UIContext): FrameNode | null{

      if (this.type_ === 'application/view') {
        this.rootNode.build(wrapBuilder(TextInputBuilder), {
          textOne: "myInput",
          width: this.width_,
          height: this.height_
        }); 
      } else {
        // other
      }
      ...
    }
    ...
  }


  @Component
  struct TextInputComponent {
    @Prop params: Params
    @State bkColor: Color = Color.Red
    mXComponentController: XComponentController = new XComponentController();

    build() {
      Column() {
        TextInput({ text: `${this.params.textOne}` })
          .height(50)
          .width(200)
          .backgroundColor(Color.Green)
          .onTouch((event) => {
            console.log('input1 event ' + JSON.stringify(event));
          }).margin({ top: 30})

        TextInput({ text: `${this.params.textOne}` })
          .height(50)
          .width(200)
          .backgroundColor(Color.Green)
          .onTouch((event) => {
            console.log('input2 event ' + JSON.stringify(event));
          }).margin({ top: 30})

        TextInput({ text: `${this.params.textOne}` })
          .height(50)
          .width(200)
          .backgroundColor(Color.Green)
          .onTouch((event) => {
            console.log('input2 event ' + JSON.stringify(event));
          }).margin({ top: 30})
      }
      .width(this.params.width)
      .height(this.params.height)
    }
  }

  @Builder
  function TextInputBuilder(params: Params) {
    TextInputComponent({ params: params })
      .height(params.height)
      .width(params.width)
      .backgroundColor(Color.Red)
  }

  @Entry
  @Component
  struct Page {
    browserTabController: WebviewController = new webview.WebviewController()
    private nodeControllerMap: Map<string, MyNodeController> = new Map();
    @State componentIdArr: Array<string> = [];
    @State edges: Edges = {};

    build() {
      Row() {
        Column() {
          Stack(){
            ForEach(this.componentIdArr, (componentId: string) => {
              NodeContainer(this.nodeControllerMap.get(componentId)).position(this.edges)
            }, (embedId: string) => embedId)

            Web({ src: $rawfile('test.html'), controller: this.browserTabController})
              .enableNativeEmbedMode(true)
              .registerNativeEmbedRule("object", "APPlication/view")
              .onNativeEmbedLifecycleChange((embed) => {
                const componentId = embed.info?.id?.toString() as string;
                if (embed.status == NativeEmbedStatus.CREATE) {
                  // You are advised to use position in edges mode to avoid extra precision loss caused by floating-point calculation during the conversion between px and vp.
                  this.edges = {left: `${embed.info?.position?.x as number}px`, top: `${embed.info?.position?.y as number}px`}
                  let nodeController = new MyNodeController()
                  nodeController.setRenderOption({surfaceId : embed.surfaceId as string,
                    type : embed.info?.type as string,
                    renderType : NodeRenderType.RENDER_TYPE_TEXTURE,
                    embedId : embed.embedId as string,
                    width : px2vp(embed.info?.width),
                    height :px2vp(embed.info?.height)})
                  nodeController.rebuild()

                  this.nodeControllerMap.set(componentId, nodeController)
                  this.componentIdArr.push(componentId)
                } else if (embed.status == NativeEmbedStatus.UPDATE) {
                  console.log("NativeEmbed update" + JSON.stringify(embed.info))

                  this.edges = {left: `${embed.info?.position?.x as number}px`, top: `${embed.info?.position?.y as number}px`}
                  let nodeController = this.nodeControllerMap.get(componentId)

                  nodeController?.updateNode({text: 'update',   width : px2vp(embed.info?.width),
                    height :px2vp(embed.info?.height)} as ESObject)
                  nodeController?.rebuild()
                } else {
                  let nodeController = this.nodeControllerMap.get(componentId)
                  nodeController?.setBuilderNode(null)
                  nodeController?.rebuild()
                }
              })
              .onNativeEmbedGestureEvent((touch) => {
                this.componentIdArr.forEach((componentId: string) => {
                  let nodeController = this.nodeControllerMap.get(componentId)
                  if (nodeController?.getEmbedId() === touch.embedId) {
                    let ret = nodeController?.postEvent(touch.touchEvent)
                    if (ret) {
                      console.log("onNativeEmbedGestureEvent success " + componentId)
                    } else {
                      console.log("onNativeEmbedGestureEvent fail " + componentId)
                    }
                  }
                })
              })
          }
        }
        .width('100%')
      }
      .height('100%')
    }
  }

  ```

- Example of the frontend page:

  ```html
  <!DOCTYPE html>
  <html>
  <head>
      <title>Same-layer rendering test html</title>
      <meta charset="UTF-8">
      <style>
      html {
          background-color: blue;
      }
      </style>
  </head>
  <body>

  <div id="bodyId" style="width:800px; height:1000px; margin-top:1000px;">
      <object id="cameraTest" type="application/view" width="100%" height="100%" ></object>
  </div>
  <div style="height:1000px;">
  </div>

  </body>
  </html>
  ```
