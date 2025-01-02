# Using Same-Layer Rendering

In the system, applications can use the **Web** component to load web pages. If the capability or performance of non-native UI components (same-layer components) is inferior to that of native components, you can use the ArkUI component to render these components.

## When to Use
### On the Web Page
To improve the performance of an applet, you can use the ArkUI **XComponent** component to render the map component, and use the ArkUI **TextInput** component to render the input box component.
- On the web page, you can render the UI components (same-layer tags) such as **\<embed>** and **\<object>** at the same layer based on certain rules. For details, see [Specifications and Constraints](#specifications-and-constraints).

- On the application, you can use the same-layer rendering event reporting API of the **Web** component to detect the lifecycle and input event of the HTML5 same-layer tags, and process the service logic of the same-layer rendering components.

- In addition, you can use ArkUI APIs such as **NodeContainer** to construct same-layer rendering components corresponding to HTML5 same-layer tags. Common ArkUI components that support same-layer rendering: [TextInput](../reference/apis-arkui/arkui-ts/ts-basic-components-textinput.md), [XComponent](../reference/apis-arkui/arkui-ts/ts-basic-components-xcomponent.md), [Canvas](../reference/apis-arkui/arkui-ts/ts-components-canvas-canvas.md), [Video](../reference/apis-arkui/arkui-ts/ts-media-components-video.md), [Web](../reference/apis-arkweb/ts-basic-components-web.md). For details, see [Specifications and Constraints](#specifications-and-constraints).

### On the Third-Party UI Framework
Flutter provides the **PlatformView** and **Texture** abstract components that can be rendered using native components, which complete the functions of the Flutter components. Weex2.0 framework supports the **Camera**, **Video**, and **Canvas** components.

- Since third-party frameworks such as Flutter and Weex are not operated in the OS, the available third-party framework UI components that can be rendered at the same layer are not listed in the following.

- On the application, you can use ArkUI APIs such as **NodeContainer** to construct same-layer rendering components corresponding to third-party framework same-layer tags. Common ArkUI components that support same-layer rendering: [TextInput](../reference/apis-arkui/arkui-ts/ts-basic-components-textinput.md), [XComponent](../reference/apis-arkui/arkui-ts/ts-basic-components-xcomponent.md), [Canvas](../reference/apis-arkui/arkui-ts/ts-components-canvas-canvas.md), [Video](../reference/apis-arkui/arkui-ts/ts-media-components-video.md), [Web](../reference/apis-arkweb/ts-basic-components-web.md). For details, see [Specifications and Constraints](#specifications-and-constraints).

## Overall Architecture
The ArkWeb same-layer rendering feature supports same-layer tag lifecycle and event hit forwarding.

The lifecycle of same-layer tags is associated with front-end tags (\<embed>/\<object>). Events that hit the same-layer tags are reported to you, and you should distribute them to the corresponding component tree. The following figure shows the overall framework.

**Figure 1** Overall architecture of same-layer rendering

![web-same-layer](figures/web-same-layer-develop-architecture_en.png)

## Specifications and Constraints
### ArkUI Components That Can Be Rendered at the Same Layer

The following specifications take effect in both web pages and third-party frameworks.

**Supported Components**:

- Basic components: [AlphabetIndexer](../reference/apis-arkui/arkui-ts/ts-container-alphabet-indexer.md), [Blank](../reference/apis-arkui/arkui-ts/ts-basic-components-blank.md), [Button](../reference/apis-arkui/arkui-ts/ts-basic-components-button.md), [CalendarPicker](../reference/apis-arkui/arkui-ts/ts-basic-components-calendarpicker.md), [Checkbox](../reference/apis-arkui/arkui-ts/ts-basic-components-checkbox.md), [CheckboxGroup](../reference/apis-arkui/arkui-ts/ts-basic-components-checkboxgroup.md), [ContainerSpan](../reference/apis-arkui/arkui-ts/ts-basic-components-containerspan.md), [DataPanel](../reference/apis-arkui/arkui-ts/ts-basic-components-datapanel.md), [DatePicker](../reference/apis-arkui/arkui-ts/ts-basic-components-datepicker.md), [Divider](../reference/apis-arkui/arkui-ts/ts-basic-components-divider.md), [Gauge](../reference/apis-arkui/arkui-ts/ts-basic-components-gauge.md), [Hyperlink](../reference/apis-arkui/arkui-ts/ts-container-hyperlink.md), [Image](../reference/apis-arkui/arkui-ts/ts-basic-components-image.md), [ImageAnimator](../reference/apis-arkui/arkui-ts/ts-basic-components-imageanimator.md), [ImageSpan](../reference/apis-arkui/arkui-ts/ts-basic-components-imagespan.md), [LoadingProgress](../reference/apis-arkui/arkui-ts/ts-basic-components-loadingprogress.md), [Marquee](../reference/apis-arkui/arkui-ts/ts-basic-components-marquee.md), [PatternLock](../reference/apis-arkui/arkui-ts/ts-basic-components-patternlock.md), [Progress](../reference/apis-arkui/arkui-ts/ts-basic-components-progress.md), [QRCode](../reference/apis-arkui/arkui-ts/ts-basic-components-qrcode.md), [Radio](../reference/apis-arkui/arkui-ts/ts-basic-components-radio.md), [Rating](../reference/apis-arkui/arkui-ts/ts-basic-components-rating.md), [Refresh](../reference/apis-arkui/arkui-ts/ts-container-refresh.md), [ScrollBar](../reference/apis-arkui/arkui-ts/ts-container-scroll.md), [Search](../reference/apis-arkui/arkui-ts/ts-basic-components-search.md), [Span](../reference/apis-arkui/arkui-ts/ts-basic-components-span.md), [Select](../reference/apis-arkui/arkui-ts/ts-basic-components-select.md), [Slider](../reference/apis-arkui/arkui-ts/ts-basic-components-slider.md), [Text](../reference/apis-arkui/arkui-ts/ts-basic-components-text.md), [TextArea](../reference/apis-arkui/arkui-ts/ts-basic-components-textarea.md), [TextClock](../reference/apis-arkui/arkui-ts/ts-basic-components-textclock.md), [TextInput](../reference/apis-arkui/arkui-ts/ts-basic-components-textinput.md), [TextPicker](../reference/apis-arkui/arkui-ts/ts-basic-components-textpicker.md), [TextTimer](../reference/apis-arkui/arkui-ts/ts-basic-components-texttimer.md), [TimePicker](../reference/apis-arkui/arkui-ts/ts-basic-components-timepicker.md), [Toggle](../reference/apis-arkui/arkui-ts/ts-basic-components-toggle.md)

- Container components: [Badge](../reference/apis-arkui/arkui-ts/ts-container-badge.md), [Column](../reference/apis-arkui/arkui-ts/ts-container-column.md), [ColumnSplit](../reference/apis-arkui/arkui-ts/ts-container-columnsplit.md), [Counter](../reference/apis-arkui/arkui-ts/ts-container-counter.md), [Flex](../reference/apis-arkui/arkui-ts/ts-container-flex.md), [GridCol](../reference/apis-arkui/arkui-ts/ts-container-gridcol.md), [GridRow](../reference/apis-arkui/arkui-ts/ts-container-gridrow.md), [Grid](../reference/apis-arkui/arkui-ts/ts-container-grid.md), [GridItem](../reference/apis-arkui/arkui-ts/ts-container-griditem.md) and [List](../reference/apis-arkui/arkui-ts/ts-container-list.md), [ListItem](../reference/apis-arkui/arkui-ts/ts-container-listitem.md), [ListItemGroup](../reference/apis-arkui/arkui-ts/ts-container-listitemgroup.md), [RelativeContainer](../reference/apis-arkui/arkui-ts/ts-container-relativecontainer.md), [Row](../reference/apis-arkui/arkui-ts/ts-container-row.md), [RowSplit](../reference/apis-arkui/arkui-ts/ts-container-rowsplit.md), [Scroll](../reference/apis-arkui/arkui-ts/ts-container-scroll.md), [Stack](../reference/apis-arkui/arkui-ts/ts-container-stack.md), [Swiper](../reference/apis-arkui/arkui-ts/ts-container-swiper.md), [Tabs](../reference/apis-arkui/arkui-ts/ts-container-tabs.md), [TabContent](../reference/apis-arkui/arkui-ts/ts-container-tabcontent.md), [NodeContainer](../reference/apis-arkui/arkui-ts/ts-basic-components-nodecontainer.md), [SideBarContainer](../reference/apis-arkui/arkui-ts/ts-container-sidebarcontainer.md), [Stepper](../reference/apis-arkui/arkui-ts/ts-basic-components-stepper.md), [StepperItem](../reference/apis-arkui/arkui-ts/ts-basic-components-stepperitem.md), [WaterFlow](../reference/apis-arkui/arkui-ts/ts-container-waterflow.md), [FlowItem](../reference/apis-arkui/arkui-ts/ts-container-flowitem.md)

- Self-drawing components: [XComponent](../reference/apis-arkui/arkui-ts/ts-basic-components-xcomponent.md), [Canvas](../reference/apis-arkui/arkui-ts/ts-components-canvas-canvas.md), [Video](../reference/apis-arkui/arkui-ts/ts-media-components-video.md), [Web](../reference/apis-arkweb/ts-basic-components-web.md)

- Command-based custom drawing nodes: [BuilderNode](../reference/apis-arkui/js-apis-arkui-builderNode.md), [ComponentContent](../reference/apis-arkui/js-apis-arkui-ComponentContent.md), [ContentSlot](../reference/apis-arkui/arkui-ts/ts-components-contentSlot.md), [FrameNode](../reference/apis-arkui/js-apis-arkui-frameNode.md), [Graphics](../reference/apis-arkui/js-apis-arkui-graphics.md), [NodeController](../reference/apis-arkui/js-apis-arkui-nodeController.md), [RenderNode](../reference/apis-arkui/js-apis-arkui-renderNode.md), [XComponentNode](../reference/apis-arkui/js-apis-arkui-xcomponentNode.md), [AttributeUpdater](../reference/apis-arkui/js-apis-arkui-AttributeUpdater.md) and [CAPI](../reference/apis-arkui/_ark_u_i___native_module.md) (The components that support same-layer rendering are the same as that of ArkTS.)

**Supported Common Component Attributes and Events**:

- Common attributes that are not supported: [restoreId](../reference/apis-arkui/arkui-ts/ts-universal-attributes-restoreId.md) and [Special Effect Drawing Combination](../reference/apis-arkui/arkui-ts/ts-universal-attributes-use-effect.md).

- Other attributes, events, and component capabilities that are not clearly marked as not supported are supported by default.

### Same-Layer Rendering Tags of the Web Page
This specification applies only to web pages and does not apply to third-party frameworks.

If an application needs to use the same-layer rendering on a web page loaded by the **Web** component, you need to specify the **\<embed>** and **\<object>** tags on the web page as the same-layer rendering components based on the following specifications.

**Supported Devices**: 
Currently, only mobile phones and tablets are supported.

**Supported HTML5 Tags**:
- **\<embed>**: After same-layer rendering is enabled, only tags whose type is prefixed with **native** can be identified as same-layer components. Attributes cannot be customized.

- **\<object>**: After the same-layer rendering is enabled, the **\<object>** tag of the non-standard **MIME** type can be identified as a same-layer component and parsed based on the custom **param**/**value** attribute.

- W3C standard tags (such as **\<input>** and **\<video>**) cannot be defined as same-layer tags.

- The **\<object>** and **\<embed>** tags cannot be configured as the same-layer tags at the same time. 

- The tag types contain only English characters and are case insensitive.

**Supported Attributes of Same-Layer Tags**:
CSS attributes that comply with the W3C standard.

**Lifecycle Management of Same-Layer Tags**:
The [onNativeEmbedLifecycleChange()](../reference/apis-arkweb/ts-basic-components-web.md#onnativeembedlifecyclechange11) callback is triggered when the lifecycle of the **Embed** tag changes.

- Creation, destruction, and position width and height change are supported. The visibility status change is not supported.

- Web pages containing same-layer components support back-forward cache.

**Distributing and Processing the Input Events of Same-Layer Tags**:
- The **DOWN**, **UP**, **MOVE**, and **CANCEL** touch events are supported. The [onnativeembedgestureevent11](../reference/apis-arkweb/ts-basic-components-web.md#onnativeembedgestureevent11) can be configured. By default, the touch event is consumed on the application side.

- The application page containing same-layer components cannot be scaled, and the scaling APIs such as [initialScale](../reference/apis-arkweb/ts-basic-components-web.md#initialscale), [zoom](../reference/apis-arkweb/js-apis-webview.md#zoom), [zoomIn](../reference/apis-arkweb/js-apis-webview.md#zoomin) and [zoomOut](../reference/apis-arkweb/js-apis-webview.md#zoomout) are not supported.

- Mouse, keyboard, and touchpad events are not supported.

**Constraints**:

- Configure a maximum of five same-layer tags on a web page. Otherwise, the rendering performance deteriorates.

- Due to GPU restrictions, the maximum height and texture size of a same-layer tag are 8000 px.

- When same-layer rendering is enabled, web pages opened by the **Web** component do not support the unified [RenderMode](../reference/apis-arkweb/ts-basic-components-web.md#rendermode12).

- When the non-full-screen mode is changed to the full-screen mode, the **Video** component is exported through non-texture mode and the video playback status remains unchanged. When the non-full-screen mode is restored, the **Video** component is exported through texture mode and the video playback status remains unchanged.

- The **Web** component supports only same-layer rendering nesting at one layer. The input events such as swipe, tap, zoom, and long-press are supported, while drag and rotate events are not supported.

- In the page layout of ArkUI components (such as **TextInput**), you are advised to use a **Stack** component to wrap the same-layer **NodeContainer** and **BuilderNode** and ensure that they are in the same position. In addition, the **NodeContainer** must be aligned with the **\<embed>**/**\<object>** tag to ensure proper component interaction. If the positions of the two components are different, the following problems may occur: The position of the text selection box attached to the **TextInput**/**TextArea** component is incorrect (as shown in the following figure). The animation start and stop of the **LoadingProgress**/**Marquee** component do not match the visibility status of the component.

  **Figure 2** Misplaced **TextInput** without **Stack**

  ![web-same-layer-develop](figures/web-same-layer-develop-textinput1.png)

  **Figure 3** Proper **TextInput** with **Stack**

  ![web-same-layer-develop](figures/web-same-layer-develop-textinput2_en.png)

## Rendering Text Boxes at the Same Layer on Web Pages
On web pages, you can render the native ArkUI **TextInput** components at the same layer. The following figure shows the effect of three text boxes that are rendered at the same layer.

**Figure 4** Same-layer rendering text boxes

  ![web-same-layer-develop](figures/web-same-layer-develop-input.png)

1. Mark the HTML tags that need to be rendered at the same layer on the web page.

   The **\<embed>** and **\<object>** tags support same-layer rendering, and the **type** can be specified randomly. They are case insensitive and will be converted to lowercase letters by the ArkWeb kernel. The **tag** string is matched using the entire string, and the **type** string is matched using the prefix.

   If this API is not used or receives an invalid string (empty string), the ArkWeb kernel uses the default setting, that is, "embed" + "native/" prefix. If the specified **type** is the same as the W3C standard **object** or **embed** type, for example, **registerNativeEmbedRule** ("**object**," "**application**/**pdf**"), ArkWeb will comply with the W3C standard behavior and will not identify it as a same-layer tag.

   - Use the \<embed> tags.

     ```html
     <!--HAP's src/main/resources/rawfile/text.html-->
     <!DOCTYPE html>
     <html>
     <head>
         <title>Same-Layer Rendering Test HTML</title>
         <meta name="viewport">
     </head>

     <body style="background:white">

     <embed id = "input1" type="native/view" style="width: 100%; height: 100px; margin: 30px; margin-top: 600px"/>

     <embed id = "input2" type="native/view2" style="width: 100%; height: 100px; margin: 30px; margin-top: 50px"/>

     <embed id = "input3" type="native/view3" style="width: 100%; height: 100px; margin: 30px; margin-top: 50px"/>

     </body>
     </html>
     ```

   - Use the \<object> tags.

     Call **registerNativeEmbedRule** to register a **\<object>** tag.
     ```ts
     // ...
     Web({src: $rawfile("text.html"), controller: this.browserTabController})
       // Register the same-layer tag of "object" and type of "test."
       .registerNativeEmbedRule("object", "test")
       // ...
     ```

     Example of using **registerNativeEmbedRule** on the frontend page, with the tag of "object" and type of "test":

      ```html
      <!--HAP's src/main/resources/rawfile/text.html-->
      <!DOCTYPE html>
      <html>
      <head>
          <title>Same-Layer Rendering Test HTML</title>
          <meta name="viewport">
      </head>

      <body style="background:white">

      <object id = "input1" type="test/input" style="width: 100%; height: 100px; margin: 30px; margin-top: 600px"></object>

      <object id = "input2" type="test/input" style="width: 100%; height: 100px; margin: 30px; margin-top: 50px"></object>

      <object id = "input3" type="test/input" style="width: 100%; height: 100px; margin: 30px; margin-top: 50px"></object>

      </body>
      </html>
      ```

2. Use **enableNativeEmbedMode** to enable the same-layer rendering on the application,

   which is disabled by default.

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
           // Enable same-layer rendering.
           .enableNativeEmbedMode(true)
       }
     }
   }
   ```

3. Create a custom component,

   which is displayed as a native component in the corresponding area after the same-layer rendering is enabled.

   ```ts
   @Component
   struct TextInputComponent {
     @Prop params: Params
     @State bkColor: Color = Color.White

     build() {
       Column() {
         TextInput({text: '', placeholder: 'please input your word...'})
           .placeholderColor(Color.Gray)
           .id(this.params?.elementId)
           .placeholderFont({size: 13, weight: 400})
           .caretColor(Color.Gray)
           .width(this.params?.width)
           .height(this.params?.height)
           .fontSize(14)
           .fontColor(Color.Black)
       }
       // The width and height of the outermost custom container component must be the same as those of the tag at the same layer.
       .width(this.params.width)
       .height(this.params.height)
     }
   }

   @Builder
   function TextInputBuilder(params:Params) {
     TextInputComponent({params: params})
       .width(params.width)
       .height(params.height)
       .backgroundColor(Color.White)
   }
   ```

4. Create a node controller,

   which is used to control and report node behaviors of the corresponding NodeContainer.

   ```ts
   class MyNodeController extends NodeController {
     private rootNode: BuilderNode<[Params]> | undefined | null;
     private embedId_: string = "";
     private surfaceId_: string = "";
     private renderType_: NodeRenderType = NodeRenderType.RENDER_TYPE_DISPLAY;
     private width_: number = 0;
     private height_: number = 0;
     private type_: string = "";
     private isDestroy_: boolean = false;

     setRenderOption(params: nodeControllerParams) {
       this.surfaceId_ = params.surfaceId;
       this.renderType_ = params.renderType;
       this.embedId_ = params.embedId;
       this.width_ = params.width;
       this.height_ = params.height;
       this.type_ = params.type;
     }

     // Method that must be overridden. It is used to build the number of nodes and return the number of nodes that will be mounted to the corresponding NodeContainer.
     // Called when the corresponding NodeContainer is created or called by the rebuild method.
     makeNode(uiContext: UIContext): FrameNode | null {
       if (this.isDestroy_) { // rootNode is null.
         return null;
       }
       if (!this.rootNode) { // When rootNode is set to undefined
         this.rootNode = new BuilderNode(uiContext, { surfaceId: this.surfaceId_, type: this.renderType_ });
         if(this.rootNode) {
           this.rootNode.build(wrapBuilder(TextInputBuilder), {  textOne: "myTextInput", width: this.width_, height: this.height_  })
           return this.rootNode.getFrameNode();
         }else{
           return null;
         }
       }
       // Return the FrameNode object.
       return this.rootNode.getFrameNode();
     }

     setBuilderNode(rootNode: BuilderNode<Params[]> | null): void {
       this.rootNode = rootNode;
     }

     getBuilderNode(): BuilderNode<[Params]> | undefined | null {
       return this.rootNode;
     }

     updateNode(arg: Object): void {
       this.rootNode?.update(arg);
     }

     getEmbedId(): string {
       return this.embedId_;
     }
     
     setDestroy(isDestroy: boolean): void {
       this.isDestroy_ = isDestroy;
       if (this.isDestroy_) {
         this.rootNode = null;
       }
     }
    
     postEvent(event: TouchEvent | undefined): boolean {
       return this.rootNode?.postTouchEvent(event) as boolean
     }
   }
   ```

5. Call [onNativeEmbedLifecycleChange](../reference/apis-arkweb/ts-basic-components-web.md#onnativeembedlifecyclechange11) to listen for the lifecycle changes of the same-layer rendering tags.

   After this function is enabled, the ArkWeb kernel triggers the callback registered by [onNativeEmbedLifecycleChange](../reference/apis-arkweb/ts-basic-components-web.md#onnativeembedlifecyclechange11) each time a same-layer rendering tag is used on a web page.

    

    ```ts
    build() {
      Row() {
        Column() {
          Stack() {
            ForEach(this.componentIdArr, (componentId: string) => {
              NodeContainer(this.nodeControllerMap.get(componentId))
                .position(this.positionMap.get(componentId))
                .width(this.widthMap.get(componentId))
                .height(this.heightMap.get(componentId))
            }, (embedId: string) => embedId)
            // Load the local text.html page.
            Web({src: $rawfile("text.html"), controller: this.browserTabController})
              // Enable same-layer rendering.
              .enableNativeEmbedMode(true)
                // Register the same-layer tag of "object" and type of "test."
              .registerNativeEmbedRule("object", "test")
                // Obtain the lifecycle change data of the embed tag.
              .onNativeEmbedLifecycleChange((embed) => {
                console.log("NativeEmbed surfaceId" + embed.surfaceId);
                // If embed.info.id is used as the key for mapping nodeController, explicitly specify the ID on the HTML5 page.
                const componentId = embed.info?.id?.toString() as string
                if (embed.status == NativeEmbedStatus.CREATE) {
                  console.log("NativeEmbed create" + JSON.stringify(embed.info));
                  // Create a NodeController instance, set parameters, and rebuild.
                  let nodeController = new MyNodeController()
                  // The unit of embed.info.width and embed.info.height is px, which needs to be converted to the default unit vp on the eTS side.
                  nodeController.setRenderOption({surfaceId : embed.surfaceId as string,
                    type : embed.info?.type as string,
                    renderType : NodeRenderType.RENDER_TYPE_TEXTURE,
                    embedId : embed.embedId as string,
                    width : px2vp(embed.info?.width),
                    height : px2vp(embed.info?.height)})
                  this.edges = {left: `${embed.info?.position?.x as number}px`, top: `${embed.info?.position?.y as number}px`}
                  nodeController.setDestroy(false);
                  // Save the nodeController instance to the Map, with the Id attribute of the embed tag passed in by the Web component as the key.
                  this.nodeControllerMap.set(componentId, nodeController);
                  this.widthMap.set(componentId, px2vp(embed.info?.width));
                  this.heightMap.set(componentId, px2vp(embed.info?.height));
                  this.positionMap.set(componentId, this.edges);
                  // Save the Id attribute of the embed tag passed in by the Web component to the @State decorated variable for dynamically creating a nodeContainer. The push action must be executed after the set action.
                  this.componentIdArr.push(componentId)
                } else if (embed.status == NativeEmbedStatus.UPDATE) {
                  let nodeController = this.nodeControllerMap.get(componentId);
                  console.log("NativeEmbed update" + JSON.stringify(embed));
                  this.edges = {left: `${embed.info?.position?.x as number}px`, top: `${embed.info?.position?.y as number}px`}
                  this.positionMap.set(componentId, this.edges);
                  this.widthMap.set(componentId, px2vp(embed.info?.width));
                  this.heightMap.set(componentId, px2vp(embed.info?.height));
                  nodeController?.updateNode({textOne: 'update', width: px2vp(embed.info?.width), height: px2vp(embed.info?.height)} as ESObject)
                } else if (embed.status == NativeEmbedStatus.DESTROY) {
                  console.log("NativeEmbed destroy" + JSON.stringify(embed));
                  let nodeController = this.nodeControllerMap.get(componentId);
                  nodeController?.setDestroy(true)
                  this.nodeControllerMap.clear();
                  this.positionMap.delete(componentId);
                  this.widthMap.delete(componentId);
                  this.heightMap.delete(componentId);
                  this.componentIdArr.filter((value: string) => value != componentId)
                } else {
                  console.log("NativeEmbed status" + embed.status);
                }
              })
          }.height("80%")
        }
      }
    }
    ```

6. Call [onNativeEmbedGestureEvent](../reference/apis-arkweb/ts-basic-components-web.md#onnativeembedgestureevent11) to listen for gesture events that are rendered at the same layer.

   When gesture events are listened, the ArkWeb kernel triggers the callback registered by [onNativeEmbedGestureEvent](../reference/apis-arkweb/ts-basic-components-web.md#onnativeembedgestureevent11) each time a touch operation is performed in the same-layer rendering region.

    

    ```ts
    build() {
      Row() {
        Column() {
          Stack() {
            ForEach(this.componentIdArr, (componentId: string) => {
              NodeContainer(this.nodeControllerMap.get(componentId))
                .position(this.positionMap.get(componentId))
                .width(this.widthMap.get(componentId))
                .height(this.heightMap.get(componentId))
            }, (embedId: string) => embedId)
            // Load the local text.html page.
            Web({src: $rawfile("text.html"), controller: this.browserTabController})
              // Enable same-layer rendering.
              .enableNativeEmbedMode(true)
                // Obtain the lifecycle change data of the embed tag.
              .onNativeEmbedLifecycleChange((embed) => {
                // Implement lifecycle changes.
              })
              .onNativeEmbedGestureEvent((touch) => {
                console.log("NativeEmbed onNativeEmbedGestureEvent" + JSON.stringify(touch.touchEvent));
                this.componentIdArr.forEach((componentId: string) => {
                  let nodeController = this.nodeControllerMap.get(componentId);
                  // Send the obtained event of the region at the same layer to the nodeController corresponding to embedId of the region.
                  if(nodeController?.getEmbedId() == touch.embedId) {
                    let ret = nodeController?.postEvent(touch.touchEvent)
                    if(ret) {
                      console.log("onNativeEmbedGestureEvent success " + componentId);
                    } else {
                      console.log("onNativeEmbedGestureEvent fail " + componentId);
                    }
                    if(touch.result) {
                      // Notify the Web component of the gesture event consumption result.
                      touch.result.setGestureEventResult(ret);
                    }
                  }
                })
              })
          }
        }
      }
    }
    ```

**Sample Code**

To start with, add the Internet permission to the **module.json5** file. For details, see [Declaring Permissions](../security/AccessToken/declare-permissions.md).

  ```
  "requestPermissions":[
      {
        "name" : "ohos.permission.INTERNET"
      }
    ]
  ```

Code on the application side:

  ```ts
  // Create a NodeController instance.
  import webview from '@ohos.web.webview';
  import { UIContext } from '@ohos.arkui.UIContext';
  import { NodeController, BuilderNode, NodeRenderType, FrameNode } from "@ohos.arkui.node";

  @Observed
  declare class Params{
    elementId: string
    textOne: string
    textTwo: string
    width: number
    height: number
  }

  declare class nodeControllerParams {
    surfaceId: string
    type: string
    renderType: NodeRenderType
    embedId: string
    width: number
    height: number
  }

  // The NodeController instance must be used with a NodeContainer for controlling and feeding back the behavior of the nodes in the container.
  class MyNodeController extends NodeController {
    private rootNode: BuilderNode<[Params]> | undefined | null;
    private embedId_: string = "";
    private surfaceId_: string = "";
    private renderType_: NodeRenderType = NodeRenderType.RENDER_TYPE_DISPLAY;
    private width_: number = 0;
    private height_: number = 0;
    private type_: string = "";
    private isDestroy_: boolean = false;

    setRenderOption(params: nodeControllerParams) {
      this.surfaceId_ = params.surfaceId;
      this.renderType_ = params.renderType;
      this.embedId_ = params.embedId;
      this.width_ = params.width;
      this.height_ = params.height;
      this.type_ = params.type;
    }

    // Method that must be overridden. It is used to build the number of nodes and return the number of nodes that will be mounted to the corresponding NodeContainer.
    // Called when the corresponding NodeContainer is created or called by the rebuild method.
    makeNode(uiContext: UIContext): FrameNode | null {
      if (this.isDestroy_) { // rootNode is null.
        return null;
      }
      if (!this.rootNode) { // When rootNode is set to undefined
        this.rootNode = new BuilderNode(uiContext, { surfaceId: this.surfaceId_, type: this.renderType_ });
        if(this.rootNode) {
          this.rootNode.build(wrapBuilder(TextInputBuilder), {  textOne: "myTextInput", width: this.width_, height: this.height_  })
          return this.rootNode.getFrameNode();
        }else{
          return null;
        }
      }
      // Return the FrameNode object.
      return this.rootNode.getFrameNode();
    }

    setBuilderNode(rootNode: BuilderNode<Params[]> | null): void {
      this.rootNode = rootNode;
    }

    getBuilderNode(): BuilderNode<[Params]> | undefined | null {
      return this.rootNode;
    }

    updateNode(arg: Object): void {
      this.rootNode?.update(arg);
    }

    getEmbedId(): string {
      return this.embedId_;
    }

    setDestroy(isDestroy: boolean): void {
      this.isDestroy_ = isDestroy;
      if (this.isDestroy_) {
        this.rootNode = null;
      }
    }

    postEvent(event: TouchEvent | undefined): boolean {
      return this.rootNode?.postTouchEvent(event) as boolean
    }
  }

  @Component
  struct TextInputComponent {
    @Prop params: Params
    @State bkColor: Color = Color.White

    build() {
      Column() {
        TextInput({text: '', placeholder: 'please input your word...'})
          .placeholderColor(Color.Gray)
          .id(this.params?.elementId)
          .placeholderFont({size: 13, weight: 400})
          .caretColor(Color.Gray)
          .fontSize(14)
          .fontColor(Color.Black)
      }
      // The width and height of the outermost custom container component must be the same as those of the tag at the same layer.
      .width(this.params.width)
      .height(this.params.height)
    }
  }

  // In @Builder, add the specific dynamic component content.
  @Builder
  function TextInputBuilder(params:Params) {
    TextInputComponent({params: params})
      .width(params.width)
      .height(params.height)
      .backgroundColor(Color.White)
  }

  @Entry
  @Component
  struct Page{
    browserTabController: WebviewController = new webview.WebviewController()
    private nodeControllerMap: Map<string, MyNodeController> = new Map();
    @State componentIdArr: Array<string> = [];
    @State posMap: Map<string, Position | undefined> = new Map();
    @State widthMap: Map<string, number> = new Map();
    @State heightMap: Map<string, number> = new Map();
    @State positionMap: Map<string, Edges> = new Map();
    @State edges: Edges = {};

    build() {
      Row() {
        Column() {
          Stack() {
            ForEach(this.componentIdArr, (componentId: string) => {
              NodeContainer(this.nodeControllerMap.get(componentId))
                .position(this.positionMap.get(componentId))
                .width(this.widthMap.get(componentId))
                .height(this.heightMap.get(componentId))
            }, (embedId: string) => embedId)
            // Load the local text.html page.
            Web({src: $rawfile("text.html"), controller: this.browserTabController})
              // Enable same-layer rendering.
              .enableNativeEmbedMode(true)
              // Obtain the lifecycle change data of the embed tag.
              .onNativeEmbedLifecycleChange((embed) => {
                 console.log("NativeEmbed surfaceId" + embed.surfaceId);
                 // If embed.info.id is used as the key for mapping nodeController, explicitly specify the ID on the HTML5 page.
                 const componentId = embed.info?.id?.toString() as string
                 if (embed.status == NativeEmbedStatus.CREATE) {
                   console.log("NativeEmbed create" + JSON.stringify(embed.info));
                   // Create a NodeController instance, set parameters, and rebuild.
                   let nodeController = new MyNodeController()
                   // The unit of embed.info.width and embed.info.height is px, which needs to be converted to the default unit vp on the eTS side.
                   nodeController.setRenderOption({surfaceId : embed.surfaceId as string,
                     type : embed.info?.type as string,
                     renderType : NodeRenderType.RENDER_TYPE_TEXTURE,
                     embedId : embed.embedId as string,
                     width : px2vp(embed.info?.width),
                     height : px2vp(embed.info?.height)})
                   this.edges = {left: `${embed.info?.position?.x as number}px`, top: `${embed.info?.position?.y as number}px`}
                   nodeController.setDestroy(false);
                   // Save the nodeController instance to the Map, with the Id attribute of the embed tag passed in by the Web component as the key.
                   this.nodeControllerMap.set(componentId, nodeController);
                   this.widthMap.set(componentId, px2vp(embed.info?.width));
                   this.heightMap.set(componentId, px2vp(embed.info?.height));
                   this.positionMap.set(componentId, this.edges);
                   // Save the Id attribute of the embed tag passed in by the Web component to the @State decorated variable for dynamically creating a nodeContainer. The push action must be executed after the set action.
                   this.componentIdArr.push(componentId)
                 } else if (embed.status == NativeEmbedStatus.UPDATE) {
                   let nodeController = this.nodeControllerMap.get(componentId);
                   console.log("NativeEmbed update" + JSON.stringify(embed));
                   this.edges = {left: `${embed.info?.position?.x as number}px`, top: `${embed.info?.position?.y as number}px`}
                   this.positionMap.set(componentId, this.edges);
                   this.widthMap.set(componentId, px2vp(embed.info?.width));
                   this.heightMap.set(componentId, px2vp(embed.info?.height));
                   nodeController?.updateNode({textOne: 'update', width: px2vp(embed.info?.width), height: px2vp(embed.info?.height)} as ESObject)
                 } else if (embed.status == NativeEmbedStatus.DESTROY) {
                   console.log("NativeEmbed destroy" + JSON.stringify(embed));
                   let nodeController = this.nodeControllerMap.get(componentId);
                   nodeController?.setDestroy(true)
                   this.nodeControllerMap.clear();
                   this.positionMap.delete(componentId);
                   this.widthMap.delete(componentId);
                   this.heightMap.delete(componentId);
                   this.componentIdArr.filter((value: string) => value != componentId)
                 } else {
                   console.log("NativeEmbed status" + embed.status);
                 }
               })// Obtain the touch event information of components for same-layer rendering.
              .onNativeEmbedGestureEvent((touch) => {
                console.log("NativeEmbed onNativeEmbedGestureEvent" + JSON.stringify(touch.touchEvent));
                this.componentIdArr.forEach((componentId: string) => {
                  let nodeController = this.nodeControllerMap.get(componentId);
                  // Send the obtained event of the region at the same layer to the nodeController corresponding to embedId of the region.
                  if(nodeController?.getEmbedId() == touch.embedId) {
                    let ret = nodeController?.postEvent(touch.touchEvent)
                    if(ret) {
                      console.log("onNativeEmbedGestureEvent success " + componentId);
                    } else {
                      console.log("onNativeEmbedGestureEvent fail " + componentId);
                    }
                    if(touch.result) {
                      // Notify the Web component of the gesture event consumption result.
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

## Drawing the XComponent+AVPlayer and Button Components

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
      // The width and height of the outermost custom container component must be the same as those of the tag at the same layer.
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
                // Obtain the lifecycle change data of the embed tag.
              .onNativeEmbedLifecycleChange((embed) => {
                console.log("NativeEmbed surfaceId" + embed.surfaceId);
                // 1. If embed.info.id is used as the key for mapping nodeController, explicitly specify the ID on the HTML5 page.
                const componentId = embed.info?.id?.toString() as string
                if (embed.status == NativeEmbedStatus.CREATE) {
                  console.log("NativeEmbed create" + JSON.stringify(embed.info))
                  // Create a NodeController instance, set parameters, and rebuild.
                  let nodeController = new MyNodeController()
                  // 1. The unit of embed.info.width and embed.info.height is px, which needs to be converted to the default unit vp on the eTS side.
                  nodeController.setRenderOption({surfaceId : embed.surfaceId as string, type : embed.info?.type as string,
                    renderType : NodeRenderType.RENDER_TYPE_TEXTURE, embedId : embed.embedId as string,
                    width : px2vp(embed.info?.width), height : px2vp(embed.info?.height)})
                  nodeController.setDestroy(false);
                  // Save the nodeController instance to the Map, with the Id attribute of the embed tag passed in by the Web component as the key.
                  this.nodeControllerMap.set(componentId, nodeController)
                  // Save the Id attribute of the embed tag passed in by the Web component to the @State decorated variable for dynamically creating a nodeContainer. The push action must be executed after the set action.
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
                      // Notify the Web component of the gesture event consumption result.
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

- Example of video playback code on the application side. Replace the video URL with the correct one in practice.

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
      // Set a callback for state changes.
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
      <title>Same-Layer Rendering Test HTML</title>
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
