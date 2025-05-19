# Custom Placeholder Nodes

ArkUI provides two types of custom placeholder nodes: the built-in component [NodeContainer](../../application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-nodecontainer.md) and [ContentSlot](../../application-dev/reference/apis-arkui/arkui-ts/ts-components-contentSlot.md). They are used to display custom nodes and custom node trees.

Unlike [NodeContainer](../../application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-nodecontainer.md), which acts as a container node with universal attributes, [ContentSlot](../ui/state-management/arkts-rendering-control-contentslot.md) is merely a semantic node and does not have universal attributes. It does not engage in layout and rendering processes. For hybrid development scenarios, the **ContentSlot** component is recommended when the container is an ArkTS component and the child component is created on the native side. For details, see [ContentSlot](../../application-dev/reference/apis-arkui/arkui-ts/ts-components-contentSlot.md).

[NodeContainer](../reference/apis-arkui/arkui-ts/ts-basic-components-nodecontainer.md), a built-in component serving as a placeholder, comes with universal attributes, and its node layout follows the default top-left aligned [Stack](../reference/apis-arkui/arkui-ts/ts-container-stack.md) component.

[NodeController](../reference/apis-arkui/js-apis-arkui-nodeController.md) provides a set of lifecycle callbacks, including a [makeNode](../reference/apis-arkui/js-apis-arkui-nodeController.md#makenode) callback that returns the root node of a [FrameNode](../reference/apis-arkui/js-apis-arkui-frameNode.md#framenode) tree. This [FrameNode](../reference/apis-arkui/js-apis-arkui-frameNode.md) tree is then mounted under the corresponding [NodeContainer](../reference/apis-arkui/arkui-ts/ts-basic-components-nodecontainer.md). In addition, NodeController provides the following callback methods: [aboutToAppear](../reference/apis-arkui/arkui-ts/ts-custom-component-lifecycle.md#abouttoappear), [aboutToDisappear](../reference/apis-arkui/arkui-ts/ts-custom-component-lifecycle.md#abouttodisappear), [aboutToResize](../reference/apis-arkui/js-apis-arkui-nodeController.md#abouttoresize), [onTouchEvent](../reference/apis-arkui/js-apis-arkui-nodeController.md#ontouchevent), and [rebuild](../reference/apis-arkui/js-apis-arkui-nodeController.md#rebuild), which are used to listen for the status of the associated [NodeContainer](../reference/apis-arkui/arkui-ts/ts-basic-components-nodecontainer.md).

For details about the callbacks, see [NodeController](../reference/apis-arkui/js-apis-arkui-nodeController.md).

> **NOTE**
> 
> - Only custom FrameNodes and root nodes of component trees created by **BuilderNode** are supported under the **NodeContainer**.
> 
> - Since API version 12, you can obtain a built-in component's proxy node through the query API of the FrameNode. This proxy node can be returned as the result of the **makeNode** callback, but it cannot be successfully mounted on the component tree, resulting in a failed display of the proxy node.
> 
> - A node must be used as the child of only one parent node to avoid display or functional issues, particularly in page routing and animation scenarios. For example, if a single node is mounted on multiple **NodeContainer**s through **NodeController**, only one of the **NodeContainer**s will display the node. In addition, any updates to attributes such as visibility and opacity in any of these **NodeContainer**s, which can affect the child component state, will all influence the mounted child node.

## Basic concepts

- Custom node: node created using the APIs provided by ArkUI. Custom nodes include custom component nodes (FrameNode), custom render nodes (RenderNode), custom declarative nodes (BuilderNode), and [ComponentContent](../reference/apis-arkui/js-apis-arkui-ComponentContent.md).

- Custom node tree: tree structure where the root node is a custom node.

- Declarative node tree: tree structure where the root node is a declarative node.

- Node tree: data structure that represents the hierarchical relationships between nodes.

- Placeholder node: special node used in a declarative node tree to reserve a spot for a custom node tree. Placeholder nodes include **NodeContainer** and **ContentSlot**. As the main tree of a page is declarative, placeholder nodes are necessary to attach custom nodes built imperatively to the main tree.

## Using NodeContainer to Mount Custom Nodes

You can mount custom nodes under a **NodeContainer** using **NodeController**.

```ts
// common.ets
import { BuilderNode, UIContext } from '@kit.ArkUI'

class Params {
  text: string = "this is a text"
}

let buttonNode: BuilderNode<[Params]> | null = null;

@Builder
function buttonBuilder(params: Params) {
  Column() {
    Button(params.text)
      .fontSize(12)
      .borderRadius(8)
      .borderWidth(2)
      .backgroundColor(Color.Orange)
  }
}

export function createNode(uiContext: UIContext) {
  buttonNode = new BuilderNode<[Params]>(uiContext);
  buttonNode.build(wrapBuilder(buttonBuilder), { text: "This is a Button" });
  return buttonNode;
}

export function getOrCreateNode(uiContext: UIContext): BuilderNode<[Params]> | null {
  if (buttonNode?.getFrameNode() && buttonNode?.getFrameNode()?.getUniqueId() != -1) {
    return buttonNode;
  } else {
    return createNode(uiContext);
  }
}
```
```ts
// Index.ets
import { FrameNode, NodeController, Size, UIContext } from '@kit.ArkUI'
import { getOrCreateNode } from "./common"

const TEST_TAG: string = "NodeContainer";

class MyNodeController extends NodeController {
  private isShow: boolean = false;

  constructor(isShow: boolean) {
    super();
    this.isShow = isShow;
  }

  makeNode(uiContext: UIContext): FrameNode | null {
    if (!this.isShow) {
      return null;
    }
    let frameNode = getOrCreateNode(uiContext)?.getFrameNode();
    return frameNode ? frameNode : null;
  }

  aboutToResize(size: Size) {
    console.log(TEST_TAG + " aboutToResize width : " + size.width + " height : " + size.height)
  }

  aboutToAppear() {
    console.log(TEST_TAG + " aboutToAppear")
  }

  aboutToDisappear() {
    console.log(TEST_TAG + " aboutToDisappear");
  }

  onTouchEvent(event: TouchEvent) {
    console.log(TEST_TAG + " onTouchEvent");
  }

  toShow() {
    this.isShow = true;
    this.rebuild();
  }

  toHide() {
    this.isShow = false;
    this.rebuild();
  }
}

@Entry
@Component
struct Index {
  private myNodeController1: MyNodeController = new MyNodeController(true);
  private myNodeController2: MyNodeController = new MyNodeController(false);

  build() {
    Column() {
      NodeContainer(this.myNodeController1)
        .width("100%")
        .height("40%")
        .backgroundColor(Color.Brown)
      NodeContainer(this.myNodeController2)
        .width("100%")
        .height("40%")
        .backgroundColor(Color.Gray)
      Button("Change the place of button")
        .onClick(() => {
          // First, remove the node from the original placeholder node.
          // Then, add the node to the new placeholder node.
          // This ensures that the custom node exists only as the child of one node.
          this.myNodeController1.toHide();
          this.myNodeController2.toShow();
        })
    }
    .padding({ left: 35, right: 35, top: 35 })
    .width("100%")
    .height("100%")
  }
}
```

## Layout Differences Between Child Nodes Added Using NodeContainer and ContentSlot

[NodeContainer](../../application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-nodecontainer.md) acts as a standard container that manages the layout of its child nodes. The child nodes added using **NodeContainer** follows the layout rules of the default top-left aligned [Stack](../reference/apis-arkui/arkui-ts/ts-container-stack.md) component, instead of those of the parent container. On the other hand, [ContentSlot](../../application-dev/reference/apis-arkui/arkui-ts/ts-components-contentSlot.md) is a semantic node and does not engage in the layout process. Any child nodes added will be arranged according to the layout rules of the parent container.

```ts
import { FrameNode, NodeContent, NodeController, typeNode, UIContext } from '@kit.ArkUI';

class NodeContentCtrl {
  content: NodeContent
  textNode: Array<typeNode.Text> = new Array();
  uiContext: UIContext
  width: number

  constructor(uiContext: UIContext) {
    this.content = new NodeContent()
    this.uiContext = uiContext
    this.width = Infinity
  }

  AddNode() {
    let node = typeNode.createNode(this.uiContext, "Text")
    node.initialize("ContentText:" + this.textNode.length).fontSize(20)
    this.textNode.push(node)
    this.content.addFrameNode(node)
  }

  RemoveNode() {
    let node = this.textNode.pop()
    this.content.removeFrameNode(node)
  }

  RemoveFront() {
    let node = this.textNode.shift()
    this.content.removeFrameNode(node)
  }

  GetContent(): NodeContent {
    return this.content
  }
}

class MyNodeController extends NodeController {
  public rootNode: FrameNode | null = null;
  textNode: Array<typeNode.Text> = new Array();

  makeNode(uiContext: UIContext): FrameNode {
    this.rootNode = new FrameNode(uiContext);
    return this.rootNode;
  }

  AddNode(frameNode: FrameNode | null, uiContext: UIContext) {
    let node = typeNode.createNode(uiContext, "Text")
    node.initialize("ControllerText:" + this.textNode.length).fontSize(20)
    this.textNode.push(node)
    frameNode?.appendChild(node)
  }

  RemoveNode(frameNode: FrameNode | null) {
    let node = this.textNode.pop()
    frameNode?.removeChild(node)
  }

  RemoveFront(frameNode: FrameNode | null) {
    let node = this.textNode.shift()
    frameNode?.removeChild(node)
  }
}

@Entry
@Component
struct Index {
  @State message: string = 'Hello World';
  controller = new NodeContentCtrl(this.getUIContext());
  myNodeController = new MyNodeController();

  build() {
    Row() {
      Column() {
        ContentSlot(this.controller.GetContent())
        Button("AddToSlot")
          .onClick(() => {
            this.controller.AddNode()
          })
          .margin(10)
        Button("RemoveBack")
          .onClick(() => {
            this.controller.RemoveNode()
          })
          .margin(10)
        Button("RemoveFront")
          .onClick(() => {
            this.controller.RemoveFront()
          })
          .margin(10)
      }
      .width('50%')

      Column() {
        NodeContainer(this.myNodeController)
        Button("AddToNodeContainer")
          .onClick(() => {
            this.myNodeController.AddNode(this.myNodeController.rootNode, this.getUIContext())
          })
          .margin(10)
        Button("RemoveBack")
          .onClick(() => {
            this.myNodeController.RemoveNode(this.myNodeController.rootNode)
          })
          .margin(10)
        Button("RemoveFront")
          .onClick(() => {
            this.myNodeController.RemoveFront(this.myNodeController.rootNode)
          })
          .margin(10)
      }
      .width('50%')
    }
    .height('100%')
  }
}
```

![en-us_image_user-defined-node-01](figures/user-defined-node-01.gif)
