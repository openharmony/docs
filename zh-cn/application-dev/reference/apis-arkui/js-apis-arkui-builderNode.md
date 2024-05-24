# BuilderNode

提供能够挂载原生组件的自定义节点BuilderNode。BuilderNode仅可作为叶子节点使用, 且不建议通过获取根节点的renderNode对根节点的子节点以及属性进行操作。

> **说明：**
>
> 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 
> 当前不支持在预览器中使用BuilderNode。

## 导入模块

```ts
import { BuilderNode, RenderOptions, NodeRenderType } from "@kit.ArkUI";
```

## NodeRenderType

节点渲染类型枚举。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称                | 值  | 说明                         |
| ------------------- | --- | ---------------------------- |
| RENDER_TYPE_DISPLAY | 0   | 表示该节点将被显示到屏幕上。 |
| RENDER_TYPE_TEXTURE | 1   | 表示该节点将被导出为纹理。   |

> **说明：**
>
> RENDER_TYPE_TEXTURE类型目前仅在[BuilderNode](#buildernode-1)持有组件树的根节点为自定义组件时以及[XComponentNode](./js-apis-arkui-xcomponentNode.md)中设置生效。
>
> 在[BuilderNode](#buildernode-1)的情况下，目前在作为根节点的自定义组件中支持纹理导出的有以下组件：Badge、Blank、Button、CanvasGradient、CanvasPattern、CanvasRenderingContext2D、Canvas、CheckboxGroup、Checkbox、Circle、ColumnSplit、Column、ContainerSpan、Counter、DataPanel、Divider、Ellipse、Flex、Gauge、Hyperlink、ImageBitmap、ImageData、Image、Line、LoadingProgress、Marquee、Matrix2D、OffscreenCanvasRenderingContext2D、OffscreenCanvas、Path2D、Path、PatternLock、Polygon、Polyline、Progress、QRCode、Radio、Rating、Rect、RelativeContainer、RowSplit、Row、Shape、Slider、Span、Stack、TextArea、TextClock、TextInput、TextTimer、Text、Toggle、Video（不支持原生的全屏模式）、Web、XComponent。
>
> 从API version 12开始，新增以下组件支持纹理导出：DatePicker、ForEach、Grid、IfElse、LazyForEach、List、Scroll、Swiper、TimePicker、@Component修饰的自定义组件、NodeContainer以及NodeContainer下挂载的FrameNode和RenderNode。
>
> 使用方式可参考[同层渲染绘制](../../web/web-same-layer.md)。

## RenderOptions

创建BuilderNode时的可选参数。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称          | 类型                                   | 必填 | 说明                                                         |
| ------------- | -------------------------------------- | ---- | ------------------------------------------------------------ |
| selfIdealSize | [Size](js-apis-arkui-graphics.md#size) | 否   | 节点的理想大小。                                             |
| type          | [NodeRenderType](#noderendertype)      | 否   | 节点的渲染类型。                                             |
| surfaceId     | string                                 | 否   | 纹理接收方的surfaceId。纹理接收方一般为[OH_NativeImage](../apis-arkgraphics2d/_o_h___native_image.md#oh_nativeimage)。 |

## BuilderNode

class BuilderNode<Args extends Object[]>

BuilderNode支持通过无状态的UI方法[@Builder](../../quick-start/arkts-builder.md)生成组件树，并持有组件树的根节点。不支持定义为状态变量。BuilderNode中持有的FrameNode仅用于将该BuilderNode作为子节点挂载到其他FrameNode上。对BuilderNode持有的FrameNode进行属性设置与子节点操作可能会产生未定义行为，因此不建议通过BuilderNode的[getFrameNode](#getframenode)方法和[FrameNode](js-apis-arkui-frameNode.md#framenode)的[getRenderNode](js-apis-arkui-frameNode.md#getrendernode)方法获取RenderNode，并通过[RenderNode](js-apis-arkui-renderNode.md#rendernode)的接口对其进行属性设置与子节点操作。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### constructor

constructor(uiContext: UIContext, options?: RenderOptions)

当将BuilderNode生成的内容嵌入到其它RenderNode中显示时，即将BuilderNode对应的RenderNode挂载到另一个RenderNode中显示，需要显式指定RenderOptions中的selfIdealSize，否则Builder内的节点默认父组件布局约束为[0,0],即不设置selfIdealSize则认为BuilderNode中子树的根节点大小为[0,0]。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 参数名    | 类型                                    | 必填 | 说明                                                              |
| --------- | --------------------------------------- | ---- | ----------------------------------------------------------------- |
| uiContext | [UIContext](js-apis-arkui-UIContext.md) | 是   | UI上下文，获取方式可参考[UIContext获取方法](./js-apis-arkui-node.md#uicontext获取方法)。 |
| options   | [RenderOptions](#renderoptions)         | 否   | BuilderNode的构造可选参数。                                       |

### build

build(builder: WrappedBuilder\<Args>, arg?: Object): void

依照传入的对象创建组件树，并持有组件树的根节点。无状态的UI方法[@Builder](../../quick-start/arkts-builder.md)最多拥有一个根节点。
支持自定义组件。不支持使用自定义组件使用[@Reusable](../../quick-start/arkts-create-custom-components.md#自定义组件的基本结构)、[@Link](../../quick-start/arkts-link.md)、[@Prop](../../quick-start/arkts-prop.md)、[@Provide](../../quick-start/arkts-provide-and-consume.md)、[@Consume](../../quick-start/arkts-provide-and-consume.md)等装饰器用于当前页面与自定义组件的状态同步。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型                                                            | 必填 | 说明                                                                                   |
| ------- | --------------------------------------------------------------- | ---- | -------------------------------------------------------------------------------------- |
| builder | [WrappedBuilder\<Args>](../../quick-start/arkts-wrapBuilder.md) | 是   | 创建对应节点树的时候所需的无状态UI方法[@Builder](../../quick-start/arkts-builder.md)。 |
| arg     | Object                                                          | 否   | 对象，作为builder入参的对象。                                                          |


### getFrameNode

getFrameNode(): FrameNode | null

获取BuilderNode中的FrameNode。在BuilderNode执行build操作之后，才会生成FrameNode。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型                                                      | 说明                                                                  |
| --------------------------------------------------------- | --------------------------------------------------------------------- |
| [FrameNode](js-apis-arkui-frameNode.md#framenode) \| null | 一个FrameNode对象。若该BuilderNode不包含FrameNode，则返回空对象null。 |

**示例1：**

BuilderNode作为NodeContainer的根节点返回。

```ts
import { NodeController, BuilderNode, FrameNode, UIContext } from "@kit.ArkUI"

class Params {
  text: string = ""
  constructor(text: string) {
    this.text = text;
  }
}

@Builder
function buildText(params: Params) {
  Column() {
    Text(params.text)
      .fontSize(50)
      .fontWeight(FontWeight.Bold)
      .margin({bottom: 36})
  }
}

class TextNodeController extends NodeController {
  private textNode: BuilderNode<[Params]> | null = null;
  private message: string = "DEFAULT";

  constructor(message: string) {
    super();
    this.message = message;
  }

  makeNode(context: UIContext): FrameNode | null {
    this.textNode = new BuilderNode(context);
    this.textNode.build(wrapBuilder<[Params]>(buildText), new Params(this.message))

    return this.textNode.getFrameNode();
  }
}

@Entry
@Component
struct Index {
  @State message: string = "hello"

  build() {
    Row() {
      Column() {
        NodeContainer(new TextNodeController(this.message))
          .width('100%')
          .height(100)
          .backgroundColor('#FFF0F0F0')
      }
      .width('100%')
      .height('100%')
    }
    .height('100%')
  }
}
```

**示例2：**

BuilderNode的RenderNode挂到其它RenderNode下。

```ts
import { NodeController, BuilderNode, FrameNode, UIContext } from "@kit.ArkUI"

class Params {
  text: string = ""

  constructor(text: string) {
    this.text = text;
  }
}

@Builder
function buildText(params: Params) {
  Column() {
    Text(params.text)
      .fontSize(50)
      .fontWeight(FontWeight.Bold)
      .margin({ bottom: 36 })
  }
}

class TextNodeController extends NodeController {
  private rootNode: FrameNode | null = null;
  private textNode: BuilderNode<[Params]> | null = null;
  private message: string = "DEFAULT";

  constructor(message: string) {
    super();
    this.message = message;
  }

  makeNode(context: UIContext): FrameNode | null {
    this.rootNode = new FrameNode(context);

    this.textNode = new BuilderNode(context, { selfIdealSize: { width: 150, height: 150 } });
    this.textNode.build(wrapBuilder<[Params]>(buildText), new Params(this.message));
    const textRenderNode = this.textNode?.getFrameNode()?.getRenderNode();

    const rootRenderNode = this.rootNode.getRenderNode();
    if (rootRenderNode !== null) {
      rootRenderNode.appendChild(textRenderNode);
    }

    return this.rootNode;
  }
}

@Entry
@Component
struct Index {
  @State message: string = "hello"

  build() {
    Row() {
      Column() {
        NodeContainer(new TextNodeController(this.message))
          .width('100%')
          .height(100)
          .backgroundColor('#FFF0F0F0')
      }
      .width('100%')
      .height('100%')
    }
    .height('100%')
  }
}
```

### update

update(arg: Object): void

根据提供的参数更新BuilderNode，该参数为[build](#build)方法调用时传入的参数类型相同。对自定义组件进行update的时候需要在自定义组件中使用的变量定义为@Prop类型。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                                     |
| ------ | ------ | ---- | ------------------------------------------------------------------------ |
| arg    | Object | 是   | 用于更新BuilderNode的参数，和[build](#build)调用时传入的参数类型一致。 |

**示例：**
```ts
import { NodeController, BuilderNode, FrameNode, UIContext } from "@kit.ArkUI"

class Params {
  text: string = ""
  constructor(text: string) {
    this.text = text;
  }
}

// 自定义组件
@Component
struct TextBuilder {
  @Prop message: string = "TextBuilder";

  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
          .margin({bottom: 36})
          .backgroundColor(Color.Gray)
      }
    }
  }
}

@Builder
function buildText(params: Params) {
  Column() {
    Text(params.text)
      .fontSize(50)
      .fontWeight(FontWeight.Bold)
      .margin({ bottom: 36 })
    TextBuilder({message: params.text}) // 自定义组件
  }
}

class TextNodeController extends NodeController {
  private rootNode: FrameNode | null = null;
  private textNode: BuilderNode<[Params]> | null = null;
  private message: string = "";

  constructor(message: string) {
    super()
    this.message = message
  }

  makeNode(context: UIContext): FrameNode | null {
    this.textNode = new BuilderNode(context);
    this.textNode.build(wrapBuilder<[Params]>(buildText), new Params(this.message))
    return this.textNode.getFrameNode();
  }

  update(message: string) {
    if (this.textNode !== null) {
      this.textNode.update(new Params(message));
    }
  }
}

@Entry
@Component
struct Index {
  @State message: string = "hello"
  private textNodeController: TextNodeController = new TextNodeController(this.message);
  private count = 0;

  build() {
    Row() {
      Column() {
        NodeContainer(this.textNodeController)
          .width('100%')
          .height(100)
          .backgroundColor('#FFF0F0F0')
        Button('Update')
          .onClick(() => {
            this.count += 1;
            const message = "Update " + this.count.toString();
            this.textNodeController.update(message);
          })
      }
      .width('100%')
      .height('100%')
    }
    .height('100%')
  }
}
```

### postTouchEvent

postTouchEvent(event: TouchEvent): boolean

将原始事件派发到某个BuilderNode创建出的FrameNode上。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                                                                      | 必填 | 说明       |
| ------ | ------------------------------------------------------------------------- | ---- | ---------- |
| event  | [TouchEvent](arkui-ts/ts-universal-events-touch.md#touchevent对象说明) | 是   | 触摸事件。 |

**返回值：**

| 类型    | 说明               |
| ------- | ------------------ |
| boolean | 派发事件是否成功。 |

**示例：**

```ts
import { NodeController, BuilderNode, FrameNode, UIContext } from '@kit.ArkUI';

class Params {
  text: string = "this is a text"
}

@Builder
function ButtonBuilder(params: Params) {
  Column() {
    Button(`button ` + params.text)
      .borderWidth(2)
      .backgroundColor(Color.Orange)
      .width("100%")
      .height("100%")
      .gesture(
        TapGesture()
          .onAction((event: GestureEvent) => {
            console.log("TapGesture");
          })
      )
  }
  .width(500)
  .height(300)
  .backgroundColor(Color.Gray)
}

class MyNodeController extends NodeController {
  private rootNode: BuilderNode<[Params]> | null = null;
  private wrapBuilder: WrappedBuilder<[Params]> = wrapBuilder(ButtonBuilder);

  makeNode(uiContext: UIContext): FrameNode | null {
    this.rootNode = new BuilderNode(uiContext);
    this.rootNode.build(this.wrapBuilder, { text: "this is a string" })
    return this.rootNode.getFrameNode();
  }

  postTouchEvent(touchEvent: TouchEvent): void {
    if(this.rootNode == null){
      return;
    }
    let result = this.rootNode.postTouchEvent(touchEvent);
    console.log("result " + result);
  }
}

@Entry
@Component
struct MyComponent {
  private nodeController: MyNodeController = new MyNodeController();

  build() {
    Column() {
      NodeContainer(this.nodeController)
        .height(300)
        .width(500)

      Column()
        .width(500)
        .height(300)
        .backgroundColor(Color.Pink)
        .onTouch((event) => {
          if(event != undefined){
            this.nodeController.postTouchEvent(event);
          }
        })
    }
  }
}
```

### dispose<sup>12+</sup>

dispose(): void

立即释放当前BuilderNode。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

```ts
import { RenderNode, FrameNode, NodeController, BuilderNode } from "@kit.ArkUI"

@Component
struct TestComponent {
  build() {
    Column() {
      Text('This is a BuilderNode.')
        .fontSize(16)
        .fontWeight(FontWeight.Bold)
    }
    .width('100%')
    .backgroundColor(Color.Gray)
  }

  aboutToAppear() {
    console.error('aboutToAppear');
  }

  aboutToDisappear() {
    console.error('aboutToDisappear');
  }
}

@Builder
function buildComponent() {
  TestComponent()
}

class MyNodeController extends NodeController {
  private rootNode: FrameNode | null = null;
  private builderNode: BuilderNode<[]> | null = null;

  makeNode(uiContext: UIContext): FrameNode | null {
    this.rootNode = new FrameNode(uiContext);
    this.builderNode = new BuilderNode(uiContext, { selfIdealSize: { width: 200, height: 100 } });
    this.builderNode.build(new WrappedBuilder(buildComponent));

    const rootRenderNode = this.rootNode!.getRenderNode();
    if (rootRenderNode !== null) {
      rootRenderNode.size = { width: 200, height: 200 };
      rootRenderNode.backgroundColor = 0xff00ff00;
      rootRenderNode.appendChild(this.builderNode!.getFrameNode()!.getRenderNode());
    }

    return this.rootNode;
  }

  dispose() {
    if (this.builderNode !== null) {
      this.builderNode.dispose();
    }
  }

  removeBuilderNode() {
    const rootRenderNode = this.rootNode!.getRenderNode();
    if (rootRenderNode !== null && this.builderNode !== null && this.builderNode.getFrameNode() !== null) {
      rootRenderNode.removeChild(this.builderNode!.getFrameNode()!.getRenderNode());
    }
  }
}

@Entry
@Component
struct Index {
  private myNodeController: MyNodeController = new MyNodeController();

  build() {
    Column({ space: 4 }) {
      NodeContainer(this.myNodeController)
      Button('BuilderNode dispose')
        .onClick(() => {
          this.myNodeController.removeBuilderNode();
          this.myNodeController.dispose();
        })
        .width('100%')
    }
  }
}
```
