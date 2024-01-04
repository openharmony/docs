# BuilderNode

提供能够挂载原生组件的自定义节点BuilderNode。当前不建议将BuilderNode作为子节点挂载到其他自定义节点上。

> **说明：**
>
> 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 
> 当前不支持在预览器中使用BuilderNode。

## 导入模块

```ts
import { BuilderNode, RenderOptions, NodeRenderType } from "@ohos.arkui.node";
```

## NodeRenderType

节点渲染类型枚举。

| 名称                | 值  | 说明                         |
| ------------------- | --- | ---------------------------- |
| RENDER_TYPE_DISPLAY | 0   | 表示该节点将被显示到屏幕上。 |
| RENDER_TYPE_TEXTURE | 1   | 表示该节点将被导出为纹理。   |

## RenderOptions

创建BuilderNode时的可选参数。

| 参数名        | 类型                              | 必填 | 说明                                                                                                            |
| ------------- | --------------------------------- | ---- | --------------------------------------------------------------------------------------------------------------- |
| selfIdealSize | [Size](./js-apis-arkui-graphics.md#size)                     | 否   | 节点的理想大小。                                                                                                |
| type          | [NodeRenderType](#noderendertype) | 否   | 节点的渲染类型。                                                                                                |
| surfaceId     | string                            | 否   | 纹理接收方的surfaceId。纹理接收方一般为[OH_NativeImage](../native-apis/_o_h___native_image.md#oh_nativeimage)。 |

## BuilderNode

class BuilderNode<Args extends Object[]>

BuilderNode支持通过无状态的UI方法[@Builder](../../quick-start/arkts-builder.md)生成组件树，并持有组件树的根节点。不支持定义为状态变量。BuilderNode中持有的FrameNode仅用于将该BuilderNode作为子节点挂载到其他FrameNode上。对BuilderNode持有的FrameNode进行属性设置与子节点操作可能会产生未定义行为，因此不建议通过BuilderNode的[getFrameNode](#getframenode)方法和[FrameNode](./js-apis-arkui-frameNode.md#framenode)的[getRenderNode](./js-apis-arkui-frameNode.md#getrendernode)方法获取RenderNode，并通过[RenderNode](./js-apis-arkui-renderNode.md#rendernode)的接口对其进行属性设置与子节点操作。

### constructor

constructor(uiContext: UIContext, options?: RenderOptions)

当将BuilderNode生成的内容嵌入到其它RenderNode中显示时，即将BuilderNode对应的RenderNode挂载到另一个RenderNode中显示，需要显式指定RenderOptions中的selfIdealSize，否则Builder内容大小为空，不显示任何内容。

| 参数名    | 类型                                      | 必填 | 说明                                                              |
| --------- | ----------------------------------------- | ---- | ----------------------------------------------------------------- |
| uiContext | [UIContext](./js-apis-arkui-UIContext.md) | 是   | UI上下文，获取方式可参考[UIContext获取方法](#uicontext获取方法)。 |
| options   | [RenderOptions](#renderoptions)           | 否   | BuilderNode的构造可选参数。                                       |

### build

build(builder: WrappedBuilder<Args>, arg?: Object): void

依照传入的对象创建组件树，并持有组件树的根节点。无状态的UI方法[@Builder](../../quick-start/arkts-builder.md)最多拥有一个根节点。
支持自定义组件。不支持使用自定义组件使用[@Reusable](../../quick-start/arkts-create-custom-components.md#自定义组件的基本结构)、[@Link](../../quick-start/arkts-link.md)、[@Prop](../../quick-start/arkts-prop.md)、[@Provide](../../quick-start/arkts-provide-and-consume.md)、[@Consume](../../quick-start/arkts-provide-and-consume.md)等装饰器用于当前页面与自定义组件的状态同步。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型                 | 必填 | 说明                                                                                   |
| ------- | -------------------- | ---- | -------------------------------------------------------------------------------------- |
| builder | WrappedBuilder<Args> | 是   | 创建对应节点树的时候所需的无状态UI方法[@Builder](../../quick-start/arkts-builder.md)。 |
| arg     | Object               | 否   | 对象，作为builder入参的对象。                                                          |


### getFrameNode

getFrameNode(): FrameNode | null

获取BuilderNode中的FrameNode。在BuilderNode执行build操作之后，才会生成FrameNode。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型                            | 说明                                                                  |
| ------------------------------- | --------------------------------------------------------------------- |
| [FrameNode](./js-apis-arkui-frameNode.md#framenode) \| null | 一个FrameNode对象。若该BuilderNode不包含FrameNode，则返回空对象null。 |

**示例1：**

BuilderNode作为NodeContainer的根节点返回。

```ts
import { NodeController, BuilderNode, FrameNode } from "@ohos.arkui.node"
import { UIContext } from '@ohos.arkui.UIContext';

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
  private textNode: BuilderNode<Params[]> | null = null;
  private message: string = "DEFAULT";

  constructor(message: string) {
    super();
    this.message = message;
  }

  makeNode(context: UIContext): FrameNode | null {
    this.textNode = new BuilderNode(context);
    this.textNode.build(new WrappedBuilder<Params[]>(buildText), new Params(this.message))

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
import { NodeController, BuilderNode, FrameNode } from "@ohos.arkui.node"
import { UIContext } from '@ohos.arkui.UIContext';

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
  private textNode: BuilderNode<Params[]> | null = null;
  private message: string = "DEFAULT";

  constructor(message: string) {
    super();
    this.message = message;
  }

  makeNode(context: UIContext): FrameNode | null {
    this.rootNode = new FrameNode(context);

    this.textNode = new BuilderNode(context, { selfIdealSize: { width: 150, height: 150 } });
    this.textNode.build(new WrappedBuilder<Params[]>(buildText), new Params(this.message))
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

根据提供的参数更新BuilderNode，该参数为[build](###build)方法调用时传入的参数类型相同。暂不支持在自定义组件中通过update方法对BuilderNode进行更新。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                                     |
| ------ | ------ | ---- | ------------------------------------------------------------------------ |
| arg    | Object | 是   | 用于更新BuilderNode的参数，和[build](###build)调用时传入的参数类型一致。 |

**示例：**
```ts
import { NodeController, BuilderNode, FrameNode } from "@ohos.arkui.node"

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
  private textNode: BuilderNode<Params[]> | null = null;
  private message: string = "";

  constructor(message: string) {
    super()
    this.message = message
  }

  makeNode(context: UIContext): FrameNode | null {
    this.rootNode = new FrameNode(context);
    this.textNode = new BuilderNode(context);
    this.textNode.build(new WrappedBuilder<Params[]>(buildText), new Params(this.message))

    const renderNode = this.rootNode.getRenderNode();
    if (renderNode !== null) {
      renderNode.appendChild(this.textNode?.getFrameNode()?.getRenderNode());
    }
    return this.rootNode;
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
| event  | [TouchEvent](../arkui-ts/ts-universal-events-touch.md#touchevent对象说明) | 是   | 触摸事件。 |

**返回值：**

| 类型    | 说明               |
| ------- | ------------------ |
| boolean | 派发事件是否成功。 |

**示例：**

```ts
import { UIContext } from '@ohos.arkui.UIContext';
import { NodeController, BuilderNode, FrameNode } from '@ohos.arkui.node';

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
  private rootNode: BuilderNode<Params[]> = null;
  private wrapBuilder = new WrappedBuilder(ButtonBuilder);

  makeNode(uiContext: UIContext): FrameNode | null {
    if (this.rootNode == null) {
      this.rootNode = new BuilderNode(uiContext);
      this.rootNode.build(this.wrapBuilder, { text: "this is a string" })
    }
    return this.rootNode.getFrameNode();
  }

  getBuilderNode(): FrameNode {
    return this.rootNode.getFrameNode();
  }

  setBuilderNode(rootNode: BuilderNode<Params[]>): void {
    this.rootNode = rootNode;
  }
}

@Entry
@Component
struct MyComponent {
  private rootNode: BuilderNode<Params[]> = null;
  private nodeController: MyNodeController = new MyNodeController()
  private wrapBuilder = new WrappedBuilder(ButtonBuilder);

  aboutToAppear() {
    this.rootNode = new BuilderNode(this.getUIContext());
    this.rootNode.build(this.wrapBuilder, { text: "this is a string" })
    this.nodeController.setBuilderNode(this.rootNode)
    this.nodeController.rebuild()
  }

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
          let result = this.rootNode.postTouchEvent(event)
          console.log("result " + result);
        })
    }
  }
}
```