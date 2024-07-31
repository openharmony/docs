# BuilderNode

## Overview

[BuilderNode](../reference/apis-arkui/js-apis-arkui-builderNode.md) provides the capability to mount native components, supports the generation of component trees through stateless UI methods [Global @Builder](../quick-start/arkts-builder.md#global-custom-builder-function), and obtains the root [FrameNode](../reference/apis-arkui/js-apis-arkui-frameNode.md) of the component tree through [getFrameNode](../reference/apis-arkui/js-apis-arkui-builderNode.md#getframenode). This node can be directly returned via [NodeController](../reference/apis-arkui/js-apis-arkui-nodeController.md) and mounted under the [NodeContainer](../reference/apis-arkui/arkui-ts/ts-basic-components-nodecontainer.md) node. It can also embed declarative component structures in the FrameNode tree structure and [RenderNode](../reference/apis-arkui/js-apis-arkui-renderNode.md) tree structure to achieve the capability of mixed display. At the same time, BuilderNode can provide texture export functionality, and the exported textures are used for peer layer rendering display in [XComponent](../reference/apis-arkui/arkui-ts/ts-basic-components-xcomponent.md).

The ArkTS native control tree created by BuilderNode supports association with custom nodes (e.g., FrameNode, RenderNode), achieving mixed display of native components and custom nodes. For third-party frameworks that use custom node capabilities for docking, BuilderNode provides the capability to embed native components.

BuilderNode provides the capability to pre-create components, allowing customization of the start time for creating native components, which can be dynamically mounted and displayed in subsequent business. For some declarative components that take a long time to initialize, such as [Web](../reference/apis-arkweb/ts-basic-components-web.md), [XComponent](../reference/apis-arkui/arkui-ts/ts-basic-components-xcomponent.md), etc., pre-creation can effectively reduce the time required for component initialization.

> **NOTE**
> 
> - BuilderNode only supports one [wrapBuilder](../quick-start/arkts-wrapBuilder.md) wrapped [Global @Builder](../quick-start/arkts-builder.md#global-custom-builder-function).
> 
> - A newly created BuildNode can only obtain a FrameNode object pointing to the root node through [getFrameNode](../reference/apis-arkui/js-apis-arkui-builderNode.md#getframenode) after [build](../reference/apis-arkui/js-apis-arkui-builderNode.md#build), otherwise it returns null.
> 
> - If the root node passed into the Builder is a syntax node (if/else/foreach/...), an additional FrameNode needs to be generated, which is displayed as "BuilderProxyNode" in the node tree.
> 
> - If BuilderNode mounts the node on another FrameNode through getFrameNode, or mounts it as a child node on the NodeContainer node. The node uses the layout constraints of the parent component for layout.
> 
> - If BuilderNode's FrameNode mounts its own node on the RenderNode node through [getRenderNode](../reference/apis-arkui/js-apis-arkui-frameNode.md#getrendernode), since its FrameNode is not on the tree, its size defaults to 0. It needs to explicitly specify the layout constraint size through [selfIdeaSize](../reference/apis-arkui/js-apis-arkui-builderNode.md#renderoptions) in the constructor to be displayed normally.
> 
> - The pre-loading of BuilderNode does not reduce the creation time of the component. When creating Web components, resources need to be loaded in the kernel. Pre-creation cannot reduce the creation time of Web components, but it can allow the kernel to pre-load, reducing the loading time of the kernel when actually used.

## Creating BuilderNode Objects

BuilderNode objects are template classes that require a specified type when created. This type needs to be consistent with the type of the WrappedBuilder passed in the subsequent build method, otherwise, there will be a compilation warning that will cause the compilation to fail.

## Creating Native Component Trees

The creation of the native component tree can be achieved through the build of BuilderNode. The component tree is created according to the passed WrappedBuilder object and the root node of the component tree is held.

> **NOTE**
>
> The stateless UI method Global @Builder has at most one root node.

Create offline nodes and native component trees in combination with FrameNode for use.

The root node of BuilderNode is directly used as the return value of [NodeController](../reference/apis-arkui/js-apis-arkui-nodeController.md)'s [makeNode](../reference/apis-arkui/js-apis-arkui-nodeController.md#makenode).

```ts
import { BuilderNode, FrameNode, NodeController, UIContext } from '@kit.ArkUI'

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

Combine BuilderNode with RenderNode for use.

The RenderNode of BuilderNode is hung under other RenderNodes, and the size of selfIdeaSize needs to be clearly defined as a layout constraint.

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
## Updating Native Component Tree

The native component tree is created through the `build` method of the `BuilderNode` object. The component tree is constructed according to the passed `WrappedBuilder` object and retains the root node of the component tree.

Custom component updates follow the update mechanism of [State Management](../quick-start/arkts-state-management-overview.md). The parent component of the custom component directly used in `WrappedBuilder` is the `BuilderNode` object. Therefore, updating a child component, i.e., the custom component defined in `WrappedBuilder`, requires adhering to the state management definition to define the relevant state variables as either [@Prop](../quick-start/arkts-prop.md) or [@ObjectLink](../quick-start/arkts-observed-and-objectlink.md). The choice of decorator should be based on the specifications of the state management decorator combined with the application development requirements.

Use `update` to update the nodes in the BuilderNode.


Update the nodes in the BuilderNode.

```ts
import { NodeController, BuilderNode, FrameNode, UIContext } from "@kit.ArkUI"

class Params {
  text: string = ""
  constructor(text: string) {
    this.text = text;
  }
}

// Custom component
@Component
struct TextBuilder {
  // As a property that needs to be updated in the custom component, the data type is a basic attribute, defined as @Prop
  @Prop message: string = "TextBuilder";

  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
          .margin({ bottom: 36 })
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
    TextBuilder({ message: params.text }) // Custom component
  }
}

class TextNodeController extends NodeController {
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
      // Call update.
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

## Disposing of Entity Node References

Since `BuilderNode` corresponds to the backend entity node, normal memory release depends on the garbage collection of the frontend object. If you expect to directly release the backend node object, you can call [dispose](../reference/apis-arkui/js-apis-arkui-builderNode.md#dispose12) to break the reference relationship with the entity node. At this point, the frontend `BuilderNode` object no longer affects the lifecycle of the entity node.

> **NOTE**
>
> After the `BuilderNode` object calls `dispose`, not only is the reference relationship between the `BuilderNode` object and the backend entity node broken, but the `FrameNode` and `RenderNode` in `BuilderNode` will also synchronize and break the reference relationship with the entity node.

## Injecting Touch Events

`BuilderNode` provides [postTouchEvent](../reference/apis-arkui/js-apis-arkui-builderNode.md#posttouchevent), which allows you to inject [touch events](../reference/apis-arkui/arkui-ts/ts-universal-events-touch.md) into the components bound to `BuilderNode`, achieving event simulation forwarding.

Inject touch events into the node tree corresponding to `BuilderNode` through `postTouchEvent`.

Forward the received events of one `Column` component to another `Column` component in `BuilderNode`, that is, when the lower `Column` component is clicked, the upper `Column` component will also receive the same touch event. When the event in `Button` is successfully recognized, the return value is true.

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
    if (this.rootNode == null) {
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
          if (event != undefined) {
            this.nodeController.postTouchEvent(event);
          }
        })
    }
  }
}
```

<!--no_check-->