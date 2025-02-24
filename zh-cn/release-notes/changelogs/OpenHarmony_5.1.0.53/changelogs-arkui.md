# ArkUI子系统Changelog

## cl.arkui.1 命令式节点跨页面复用行为变更

**访问级别**

公开接口

**变更原因**

当使用router.replace、router.back或router.clear接口进行页面跳转时，原页面将被销毁，页面上的所有节点将被标记为InDestroying。变更后，此过程将不再触发布局和绘制流程。由于命令式节点无法清除InDestroying标志位，因此在新页面上复用这些节点时，无法显示更新后的内容。

**变更影响**

此变更涉及应用适配，以下生命周期接口的行为将会受到影响。如果开发者在这些生命周期接口中实现了业务代码，由于变更前后的不同，通过BuilderNode进行跨页面复用时，生命周期接口的触发情况存在差异。若想保持原有的业务行为，则需要进行相应的适配。

| 模块            | 变更说明                                                                                                                                                                                                                                                                                                                                                                                        |
| --------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| FrameNode       | 使用router.replace、router.back或router.clear发生页面跳转后，被复用的FrameNode无法在新页面中进行布局和绘制，变更前onMeasure、onLayout和onDraw生命周期函数不触发，变更后将会触发。                                                                                                                                                                                                               |
| RenderNode      | 使用router.replace、router.back或router.clear发生页面跳转后，被复用的RenderNode无法在新页面中进行绘制，draw回调接口不触发，变更后将会触发。                                                                                                                                                                                                                                                     |
| CustomSpan      | 使用router.replace、router.back或router.clear发生页面跳转后，被复用的CustomSpan无法在新页面中进行布局和绘制，onMeasure和onDraw生命周期函数不触发，变更后将会触发。                                                                                                                                                                                                                              |
| CustomComponent | 使用router.replace、router.back或router.clear发生页面跳转后，当自定义组件CustomComponent用于BuilderNode进行复用时，自定义组件无法在新页面中进行布局，onMeasureSize生命周期函数不触发，变更后将会触发。                                                                                                                                                                                          |
| LazyForEach     | 使用router.replace、router.back或router.clear发生页面跳转后，当LazyForEach用于BuilderNode进行复用时，BuilderNode无法在新页面中进行布局，getData不触发。                                                                                                                                                                                                                                         |
| DrawModifier    | 使用router.replace、router.back或router.clear发生页面跳转后，在BuilderNode中使用的DrawModifier，由于BuilderNode及其子节点无法在新页面中进行布局和绘制，drawFront、drawContent和drawBehind生命周期函数不触发，变更后将会触发。                                                                                                                                                                   |
| C API           | 使用router.replace、router.back或router.clear发生页面跳转后，当C API自定义组件用于BuilderNode进行复用时，由于BuilderNode及其子节点无法在新页面中进行布局和绘制，ARKUI_NODE_CUSTOM_EVENT_ON_MEASURE、ARKUI_NODE_CUSTOM_EVENT_ON_LAYOUT、ARKUI_NODE_CUSTOM_EVENT_ON_DRAW、ARKUI_NODE_CUSTOM_EVENT_ON_FOREGROUND_DRAW、ARKUI_NODE_CUSTOM_EVENT_ON_OVERLAY_DRAW生命周期函数不触发，变更后将会触发。 |

**变更发生版本**

从OpenHarmony SDK 5.1.0.53 版本开始。

**变更的接口/组件**

| 文件               | 接口                                       |
| ------------------ | ------------------------------------------ |
| FrameNode.d.ts     | FrameNode的onMeasure                       |
| FrameNode.d.ts     | FrameNode的onLayout                        |
| FrameNode.d.ts     | FrameNode的onDraw                          |
| styled_string.d.ts | CustomSpan的onMeasure                      |
| styled_string.d.ts | CustomSpan的onDraw                         |
| common.d.ts        | CustomComponent的onMeasureSize             |
| common.d.ts        | DrawModifier的drawBehind                   |
| common.d.ts        | DrawModifier的drawContent                  |
| common.d.ts        | DrawModifier的drawFront                    |
| lazy_for_each.d.ts | IDataSource的getData                       |
| RenderNode.d.ts    | RenderNode的draw                           |
| native_node.h      | ARKUI_NODE_CUSTOM_EVENT_ON_MEASURE         |
| native_node.h      | ARKUI_NODE_CUSTOM_EVENT_ON_LAYOUT          |
| native_node.h      | ARKUI_NODE_CUSTOM_EVENT_ON_DRAW            |
| native_node.h      | ARKUI_NODE_CUSTOM_EVENT_ON_FOREGROUND_DRAW |
| native_node.h      | ARKUI_NODE_CUSTOM_EVENT_ON_OVERLAY_DRAW    |

**适配指导**

可通过在页面跳转时，将BuilderNode从缓存池中移除来保持节点的行为不变，示例代码如下：

1. 按照[接入ArkTS页面](../../../application-dev/ui/ndk-access-the-arkts-page.md)创建前置工程以及添加相关封装对象。

2. 替换cpp/NativeEntry.cpp为如下内容。
    ```cpp
    // NativeEntry.cpp
    #include <arkui/native_node_napi.h>
    #include <hilog/log.h>
    #include <js_native_api.h>
    #include <native_drawing/drawing_canvas.h>
    #include <native_drawing/drawing_color.h>
    #include <native_drawing/drawing_path.h>
    #include <native_drawing/drawing_pen.h>

    #include "NativeEntry.h"
    #include "ArkUINode.h"

    namespace NativeModule {

    void DrawRect(ArkUI_NodeCustomEvent *event, int32_t width, int32_t height, uint32_t penColor) {
        auto *drawContext = OH_ArkUI_NodeCustomEvent_GetDrawContextInDraw(event);
        auto *canvas = OH_ArkUI_DrawContext_GetCanvas(drawContext);
        OH_ArkUI_QueryModuleInterfaceByName(ARKUI_NATIVE_NODE, "ArkUI_NativeNodeAPI_1");
        OH_ArkUI_DrawContext_GetSize(drawContext);

        auto *drawingCanvas = reinterpret_cast<OH_Drawing_Canvas *>(canvas);

        auto *path = OH_Drawing_PathCreate();
        OH_Drawing_PathMoveTo(path, width / 4, height / 4);
        OH_Drawing_PathLineTo(path, width * 3 / 4, height / 4);
        OH_Drawing_PathLineTo(path, width * 3 / 4, height * 3 / 4);
        OH_Drawing_PathLineTo(path, width / 4, height * 3 / 4);
        OH_Drawing_PathLineTo(path, width / 4, height / 4);

        auto *pen = OH_Drawing_PenCreate();
        OH_Drawing_PenSetWidth(pen, 10);
        OH_Drawing_PenSetColor(pen, penColor);
        OH_Drawing_CanvasAttachPen(drawingCanvas, pen);
        OH_Drawing_CanvasDrawPath(drawingCanvas, path);

        OH_Drawing_PathDestroy(path);
        OH_Drawing_PenDestroy(pen);
    }

    ArkUI_NodeHandle testCustomNode(ArkUI_NativeNodeAPI_1 *nodeAPI) {
        auto column = nodeAPI->createNode(ARKUI_NODE_COLUMN);
        auto customNode = nodeAPI->createNode(ARKUI_NODE_CUSTOM);

        static ArkUI_NativeNodeAPI_1 *nodeAPISelf = nodeAPI;
        static ArkUI_NodeHandle customNodeSelf = customNode;

        ArkUI_NumberValue columnValue[] = {400};
        ArkUI_AttributeItem columnItem = {columnValue, 1};
        nodeAPI->setAttribute(column, NODE_WIDTH, &columnItem);
        nodeAPI->setAttribute(column, NODE_HEIGHT, &columnItem);

        ArkUI_NumberValue customValue[] = {400};
        ArkUI_AttributeItem customItem = {customValue, 1};
        nodeAPI->setAttribute(customNode, NODE_WIDTH, &customItem);
        nodeAPI->setAttribute(customNode, NODE_HEIGHT, &customItem);
        ArkUI_NumberValue nodeBackgroundColorValue[] = {{.u32 = 0xffffff00}};
        ArkUI_AttributeItem nodeBackgroundColorItem = {nodeBackgroundColorValue};
        nodeAPI->setAttribute(customNode, NODE_BACKGROUND_COLOR, &nodeBackgroundColorItem);

        nodeAPI->registerNodeCustomEvent(customNode, ARKUI_NODE_CUSTOM_EVENT_ON_MEASURE, 1, nullptr);
        nodeAPI->registerNodeCustomEvent(customNode, ARKUI_NODE_CUSTOM_EVENT_ON_LAYOUT, 2, nullptr);
        nodeAPI->registerNodeCustomEvent(customNode, ARKUI_NODE_CUSTOM_EVENT_ON_FOREGROUND_DRAW, 3, nullptr);
        nodeAPI->registerNodeCustomEvent(customNode, ARKUI_NODE_CUSTOM_EVENT_ON_DRAW, 4, nullptr);
        nodeAPI->registerNodeCustomEvent(customNode, ARKUI_NODE_CUSTOM_EVENT_ON_OVERLAY_DRAW, 5, nullptr);

        nodeAPI->registerNodeCustomEventReceiver([](ArkUI_NodeCustomEvent *event) {
            auto type = OH_ArkUI_NodeCustomEvent_GetEventType(event);
            if (type == ARKUI_NODE_CUSTOM_EVENT_ON_MEASURE) {
                // 变更前ARKUI_NODE_CUSTOM_EVENT_ON_MEASURE在页面返回后不会触发，变更后将会触发
                OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "Manager", "CustomNode OnMeasure");
                nodeAPISelf->setMeasuredSize(customNodeSelf, 100, 100);
            } else if (type == ARKUI_NODE_CUSTOM_EVENT_ON_LAYOUT) {
                // 变更前ARKUI_NODE_CUSTOM_EVENT_ON_LAYOUT在页面返回后不会触发，变更后将会触发
                OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "Manager", "CustomNode OnLayout");
                nodeAPISelf->setLayoutPosition(customNodeSelf, 48, 0);
            } else if (type == ARKUI_NODE_CUSTOM_EVENT_ON_FOREGROUND_DRAW) {
                // 变更前ARKUI_NODE_CUSTOM_EVENT_ON_FOREGROUND_DRAW在页面返回后不会触发，变更后将会触发
                OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "Manager", "CustomNode OnForegroundDraw");
                DrawRect(event, 200, 200, OH_Drawing_ColorSetArgb(0xff, 0xff, 0x00, 0x00));
            } else if (type == ARKUI_NODE_CUSTOM_EVENT_ON_DRAW) {
                // 变更前ARKUI_NODE_CUSTOM_EVENT_ON_DRAW在页面返回后不会触发，变更后将会触发
                OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "Manager", "CustomNode OnDraw");
                DrawRect(event, 300, 300, OH_Drawing_ColorSetArgb(0xff, 0x00, 0xff, 0x00));
            } else if (type == ARKUI_NODE_CUSTOM_EVENT_ON_OVERLAY_DRAW) {
                // 变更前ARKUI_NODE_CUSTOM_EVENT_ON_OVERLAY_DRAW在页面返回后不会触发，变更后将会触发
                OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "Manager", "CustomNode OnDraw");
                DrawRect(event, 400, 400, OH_Drawing_ColorSetArgb(0xff, 0x00, 0x00, 0xff));
            }
        });
        nodeAPI->addChild(column, customNode);
        return column;
    }

    napi_value CreateNativeRoot(napi_env env, napi_callback_info info) {
        size_t argc = 1;
        napi_value args[1] = {nullptr};

        napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);

        // 获取NodeContent
        ArkUI_NodeContentHandle contentHandle;
        OH_ArkUI_GetNodeContentFromNapiValue(env, args[0], &contentHandle);
        NativeEntry::GetInstance()->SetContentHandle(contentHandle);

        // 创建CustomNode
        auto *nodeAPI = reinterpret_cast<ArkUI_NativeNodeAPI_1 *>(
            OH_ArkUI_QueryModuleInterfaceByName(ARKUI_NATIVE_NODE, "ArkUI_NativeNodeAPI_1"));
        auto column = testCustomNode(nodeAPI);
        auto root = std::make_shared<ArkUINode>(column);

        // 保持Native侧对象到管理类中，维护生命周期。
        NativeEntry::GetInstance()->SetRootNode(root);
        return nullptr;
    }

    napi_value DestroyNativeRoot(napi_env env, napi_callback_info info) {
        // 从管理类中释放Native侧对象。
        NativeEntry::GetInstance()->DisposeRootNode();
        return nullptr;
    }

    } // namespace NativeModule
    ```

3. pages目录下添加如下文件。

    ```ts
    // pages/CustomComponentExample.ets
    @Component
    struct MyComponentWithOnMeasure {
      @StorageLink("isShowText") isShowText: boolean = true;

      build() {
        if (this.isShowText) {
          Column({ space: 16 }) {
            Text("This is CustomComponent")
              .fontWeight(FontWeight.Bold)
              .fontSize(24)
          }
          .alignItems(HorizontalAlign.Center)
          .width('100%')
          .padding(16)
        }
      }

      onMeasureSize(selfLayoutInfo: GeometryInfo, children: Measurable[], constraint: ConstraintSizeOptions): SizeResult {
        // 变更前onMeasureSize在页面返回后不会触发，变更后将会触发
        console.info(`FZY ${JSON.stringify(constraint)}`);
        let height = 0;
        let width = 0;
        children.forEach((child) => {
          let result: MeasureResult = child.measure({
            minHeight: 0,
            minWidth: 0,
            maxWidth: constraint.maxWidth,
            maxHeight: constraint.maxHeight
          })
          height += result.height;
          width = Math.max(width, result.width);
          ;
        })
        return { width, height };
      }
    }

    export { MyComponentWithOnMeasure };

    ```

    ```ts
    // pages/CustomSpanExample.ets
    import drawing from '@ohos.graphics.drawing';

    const TEST_TAG = 'TEST'

    class MyCustomSpan extends CustomSpan {
      constructor(word: string, width: number, height: number) {
        super();
        this.word = word;
        this.width = width;
        this.height = height;
      }

      onMeasure(measureInfo: CustomSpanMeasureInfo): CustomSpanMetrics {
        // 变更前onMeasure在页面返回后不会触发，变更后将会触发
        console.info(`${TEST_TAG} CustomSpan onMeasure`);
        return { width: this.width, height: this.height };
      }

      onDraw(context: DrawContext, options: CustomSpanDrawInfo) {
        // 变更前onDraw在页面返回后不会触发，变更后将会触发
        let canvas = context.canvas;

        const brush = new drawing.Brush();
        brush.setColor({
          alpha: 255,
          red: 0,
          green: 74,
          blue: 175
        });
        const font = new drawing.Font();
        font.setSize(25);
        const textBlob = drawing.TextBlob.makeFromString(this.word, font, drawing.TextEncoding.TEXT_ENCODING_UTF8);
        canvas.attachBrush(brush);
        canvas.drawRect({
          left: options.x + 10,
          right: options.x + vp2px(this.width) - 10,
          top: options.lineTop + 10,
          bottom: options.lineBottom - 10
        });

        brush.setColor({
          alpha: 255,
          red: 23,
          green: 169,
          blue: 141
        });
        canvas.attachBrush(brush);
        canvas.drawTextBlob(textBlob, options.x + 20, options.lineBottom - 15);
        canvas.detachBrush();
      }

      setWord(word: string) {
        this.word = word;
      }

      width: number = 160;
      word: string = "drawing";
      height: number = 10;
    }

    export { MyCustomSpan };
    ```

    ```ts
    // pages/DataSource.ets
    // 点击Add Data->Router pageTwo->Add Data
    // 最后一次Add Data点击后，measure和draw不触发，List无内容显示

    const TEST_TAG = 'TEST'

    class BasicDataSource implements IDataSource {
      private listeners: DataChangeListener[] = [];
      private originDataArray: string[] = [];

      public totalCount(): number {
        return 0;
      }

      public getData(index: number): string {
        return this.originDataArray[index];
      }

      registerDataChangeListener(listener: DataChangeListener): void {
        if (this.listeners.indexOf(listener) < 0) {
          console.info('add listener');
          this.listeners.push(listener);
        }
      }

      unregisterDataChangeListener(listener: DataChangeListener): void {
        const pos = this.listeners.indexOf(listener);
        if (pos >= 0) {
          console.info('remove listener');
          this.listeners.splice(pos, 1);
        }
      }

      notifyDataReload(): void {
        this.listeners.forEach(listener => {
          listener.onDataReloaded();
        })
      }

      notifyDataAdd(index: number): void {
        this.listeners.forEach(listener => {
          listener.onDataAdd(index);
        })
      }

      notifyDataChange(index: number): void {
        this.listeners.forEach(listener => {
          listener.onDataChange(index);
        })
      }

      notifyDataDelete(index: number): void {
        this.listeners.forEach(listener => {
          listener.onDataDelete(index);
        })
      }

      notifyDataMove(from: number, to: number): void {
        this.listeners.forEach(listener => {
          listener.onDataMove(from, to);
        })
      }

      notifyDatasetChange(operations: DataOperation[]): void {
        this.listeners.forEach(listener => {
          listener.onDatasetChange(operations);
        })
      }
    }

    class MyDataSource extends BasicDataSource {
      private dataArray: string[] = [];
      private getDataCount: number = 0;

      public totalCount(): number {
        return this.dataArray.length;
      }

      public getData(index: number): string {
        // 变更前getData在页面返回后不会触发，变更后将会触发
        console.info(`${TEST_TAG} LazyForeach getData`);
        this.getDataCount++;
        return this.dataArray[index];
      }

      public pushData(data: string): void {
        this.dataArray.push(data);
        this.notifyDataAdd(this.dataArray.length - 1);
      }
    }

    export { MyDataSource };
    ```

    ```ts
    // pages/FrameNodeExample.ets
    import { FrameNode, Position, LayoutConstraint } from "@kit.ArkUI"

    const TEST_TAG = "TEST"

    class MyFrameNode extends FrameNode {
      private nodeId: number;

      constructor(uiContext: UIContext, nodeId: number) {
        super(uiContext);
        this.nodeId = nodeId;
      }

      onMeasure(constraint: LayoutConstraint): void {
        // 变更前onMeasure在页面返回后不会触发，变更后将会触发
        console.info(`${TEST_TAG} FrameNode onMeasure ${this.nodeId}`);
        this.setMeasuredSize(constraint.maxSize);
      }

      onLayout(position: Position): void {
        // 变更前onLayout在页面返回后不会触发，变更后将会触发
        console.info(`${TEST_TAG} FrameNode onLayout ${this.nodeId}`);
        this.setLayoutPosition(position);
      }

      onDraw(context: DrawContext): void {
        // 变更前onDraw在页面返回后不会触发，变更后将会触发
        console.info(`${TEST_TAG} FrameNode onDraw ${this.nodeId}`);

        const canvas = context.canvas;
        const width = context.sizeInPixel.width;
        const height = context.sizeInPixel.height;

        canvas.drawCircle(width / 2, height / 2, Math.min(width, height) / 2);
      }
    }

    export { MyFrameNode };
    ```

    ```ts
    // pages/Index.ets
    import { NodeController, BuilderNode, FrameNode, UIContext, NodeContent } from "@kit.ArkUI";
    import { MyFrameNode } from './FrameNodeExample';
    import { MyRenderNode } from './RenderNodeExample';
    import { MyCustomSpan } from './CustomSpanExample';
    import { MyComponentWithOnMeasure } from './CustomComponentExample';
    import { MyDataSource } from './DataSource';
    import { MyFullDrawModifier } from './ModifierExample';
    import nativeNode from "libentry.so"
    import "ets/pages/PageTwo"

    const TEST_TAG = "TEST"

    class MyController extends NodeController {
      private rootNode: FrameNode | null = null;
      private frameNode: FrameNode | null = null;
      private nodeId: number;

      constructor(nodeId: number) {
        super();
        this.nodeId = nodeId;
      }

      makeNode(uiContext: UIContext): FrameNode {
        this.rootNode = new FrameNode(uiContext);

        this.frameNode = new MyFrameNode(uiContext, this.nodeId);
        this.frameNode.commonAttribute.width(50);
        this.frameNode.commonAttribute.height(50);
        this.frameNode.commonAttribute.backgroundColor(Color.Gray);
        this.rootNode.appendChild(this.frameNode);

        const renderNode = new MyRenderNode();
        renderNode.size = { width: 50, height: 50 };
        renderNode.position = { x: 100, y: 0 }
        this.rootNode.getRenderNode()?.appendChild(renderNode);

        return this.rootNode;
      }
    }


    @Builder
    function buildText() {
      MyComponent()
    }

    @Component
    struct MyComponent {
      @StorageLink("isShowText") isShowText: boolean = true;
      @StorageLink("controllers") controllers: Array<MyController> = [];
      private scroller: Scroller = new Scroller();
      private customSpan: MyCustomSpan = new MyCustomSpan("TextSpan Example", 80, 10);
      private style: MutableStyledString = new MutableStyledString(this.customSpan);
      private textController: TextController = new TextController();
      @State data: MyDataSource = new MyDataSource();
      private rootSlot = new NodeContent();
      private nodeCnt: number = 0;

      build() {
        if (this.isShowText) {
          Scroll(this.scroller) {
            Column({ space: 16 }) {
              Column() {
                Text("NDK：")
                  .fontSize(24)
                  .fontWeight(FontWeight.Bold)
                ContentSlot(this.rootSlot)
              }
              .alignItems(HorizontalAlign.Center)
              .width('100%')
              .height(150)
              .backgroundColor(Color.Yellow)
              .onAppear(() => {
                nativeNode.createNativeRoot(this.rootSlot);
              })
              .onDisAppear(() => {
                nativeNode.destroyNativeRoot();
              })
              Column({ space: 16 }) {
                Text('FrameNode & RenderNode & CustomSpan & CustomComponent & DrawModifier & LazyForeach：')
                  .fontSize(24)
                  .fontWeight(FontWeight.Bold)
                  .alignSelf(ItemAlign.Start)
                Button("Add FrameNode")
                  .onClick(() => {
                    this.data.pushData((this.nodeCnt + 1).toString());
                    console.info(`controllers cnt ${this.controllers.length}`)
                  })
                Button("Set CustomSpan")
                  .onClick(() => {
                    this.textController.setStyledString(this.style)
                  })
                List() {
                  LazyForEach(this.data, (item: string) => {
                    ListItem() {
                      Column({ space: 16 }) {
                        NodeContainer(new MyController(++this.nodeCnt))
                          .width('100%')
                          .backgroundColor(Color.Pink)
                        Text(undefined, { controller: this.textController })
                          .copyOption(CopyOptions.InApp)
                          .fontSize(36)
                        MyComponentWithOnMeasure()
                        Text('DrawModifier Example')
                          .fontWeight(FontWeight.Bold)
                          .fontSize(24)
                          .width('100%')
                          .height(200)
                          .drawModifier(new MyFullDrawModifier())
                      }
                    }
                  })
                }
                .width('100%')
                .layoutWeight(1)
              }
              .width('100%')
              .height('90%')
              .borderWidth(1)

            }
            .width('100%')
            .height('100%')
            .padding(16)
          }
          .width('100%')
          .layoutWeight(1)
        }
      }
    }

    class TextNodeController extends NodeController {
      private rootNode: FrameNode | null = null;
      private textNode: BuilderNode<[]> | null = null;

      makeNode(context: UIContext): FrameNode | null {
        if (AppStorage.has("textNode")) {
          // Reuse the BuilderNode in AppStorage
          this.textNode = AppStorage.get<BuilderNode<[]>>("textNode") as BuilderNode<[]>;
          const parent = this.textNode.getFrameNode()?.getParent();
          if (parent) {
            parent.removeChild(this.textNode.getFrameNode());
          }
        } else {
          this.textNode = new BuilderNode(context);
          this.textNode.build(wrapBuilder<[]>(buildText));
          // Add BuilderNode to AppStorage
          AppStorage.setOrCreate<BuilderNode<[]>>("textNode", this.textNode);
        }

        return this.textNode.getFrameNode();
      }
    }

    @Entry({ routeName: "myIndex" })
    @Component
    struct Index {
      aboutToAppear(): void {
        AppStorage.setOrCreate<boolean>("isShowText", true);
      }

      build() {
        Row() {
          Column({ space: 16 }) {
            Button('Router pageTwo')
              .onClick(() => {
                // Change the conditions to trigger Text rebuild
                AppStorage.setOrCreate<boolean>("isShowText", false);
                // Remove BuilderNode from AppStorage
                AppStorage.delete("textNode");

                this.getUIContext().getRouter().replaceNamedRoute({ name: "pageTwo" });
              })
            NodeContainer(new TextNodeController())
              .width('100%')
              .backgroundColor('#FFF0F0F0')
          }
          .width('100%')
          .height('100%')
          .padding({ bottom: 16 })
        }
        .height('100%')
      }
    }
    ```

    ```ts
    // pages/ModifierExample.ets
    import { DrawContext } from "@kit.ArkUI";
    import drawing from '@ohos.graphics.drawing';

    const TEST_TAG = "DrawModifier"

    class MyFullDrawModifier extends DrawModifier {
      drawBehind(context: DrawContext): void {
        // 变更前drawBehind在页面返回后不会触发，变更后将会触发
        console.info(TEST_TAG + " drawBehind");
        const brush = new drawing.Brush();
        brush.setColor(255, 255, 0, 0);
        context.canvas.attachBrush(brush);
        const halfWidth = context.size.width / 2;
        const halfHeight = context.size.width / 2;
        context.canvas.drawRect({
          left: 0,
          top: 0,
          right: vp2px(halfWidth / 2),
          bottom: vp2px(halfHeight / 2)
        });
      }

      drawContent(context: DrawContext): void {
        // 变更前drawContent在页面返回后不会触发，变更后将会触发
        console.info(TEST_TAG + " drawContent");
        const brush = new drawing.Brush();
        brush.setColor(255, 0, 255, 0);
        context.canvas.attachBrush(brush);
        const halfWidth = context.size.width / 2;
        const halfHeight = context.size.width / 2;
        context.canvas.drawRect({
          left: 30,
          top: 30,
          right: vp2px(halfWidth / 2) - 30,
          bottom: vp2px(halfHeight / 2) - 30
        });
      }

      drawFront(context: DrawContext): void {
        // 变更前drawFront在页面返回后不会触发，变更后将会触发
        console.info(TEST_TAG + " drawFront");
        const brush = new drawing.Brush();
        brush.setColor(255, 0, 0, 255);
        context.canvas.attachBrush(brush);
        const halfWidth = context.size.width / 2;
        const halfHeight = context.size.width / 2;
        const radius = Math.min(halfWidth, halfHeight) / 2;
        context.canvas.drawCircle(vp2px(halfWidth / 2), vp2px(halfHeight / 2), vp2px(radius / 2));
      }
    }

    export { MyFullDrawModifier };
    ```

    ```ts
    // pages/RenderNodeExample.ets
    import { RenderNode } from '@kit.ArkUI'
    import drawing from '@ohos.graphics.drawing';

    const TEST_TAG = "TEST"

    class MyRenderNode extends RenderNode {
      draw(context: DrawContext): void {
        // 变更前draw在页面返回后不会触发，变更后将会触发
        console.info(`${TEST_TAG} RenderNode draw`);
        const canvas = context.canvas;
        const width = context.sizeInPixel.width;
        const height = context.sizeInPixel.height;

        const brush = new drawing.Brush();
        brush.setColor(0xff, 0xff, 0x00, 0x00);
        canvas.attachBrush(brush);
        canvas.drawCircle(width / 2, height / 2, Math.min(width, height) / 2);
        canvas.detachBrush();
      }
    }

    export { MyRenderNode };
    ```

    ```ts
    // pages/PageTwo.ets
    // 该页面中存在一个按钮，可跳转回主页面，回到主页面后，原有的文字消失
    import "ets/pages/Index"

    @Entry({ routeName: "pageTwo" })
    @Component
    struct PageTwo {
      build() {
        Column() {
          Button('Router replace to index')
            .onClick(() => {
              this.getUIContext().getRouter().replaceNamedRoute({ name: "myIndex" });
            })
        }
        .height('100%')
        .width('100%')
        .alignItems(HorizontalAlign.Center)
        .padding(16)
      }
    }
    ```
