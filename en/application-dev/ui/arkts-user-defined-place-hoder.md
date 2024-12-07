# Custom Placeholder Node

ArkUI provides ArkTS built-in components as placeholder nodes for custom nodes. These placeholder nodes have universal component attributes.

## NodeContainer and NodeController

[NodeContainer](../reference/apis-arkui/arkui-ts/ts-basic-components-nodecontainer.md), as a built-in component, only has universal component attributes, and its node layout follows the default top-left aligned [Stack](../reference/apis-arkui/arkui-ts/ts-container-stack.md) component. As a placeholder container, [NodeContainer](../reference/apis-arkui/arkui-ts/ts-basic-components-nodecontainer.md) is primarily used for displaying custom nodes and for the display and reuse of custom node trees.

[NodeController](../reference/apis-arkui/js-apis-arkui-nodeController.md) provides a set of lifecycle callbacks, including a [makeNode](../reference/apis-arkui/js-apis-arkui-nodeController.md#makenode) callback that returns the root node of a [FrameNode](../reference/apis-arkui/js-apis-arkui-frameNode.md#framenode) tree. This [FrameNode](../reference/apis-arkui/js-apis-arkui-frameNode.md) tree is then mounted under the corresponding [NodeContainer](../reference/apis-arkui/arkui-ts/ts-basic-components-nodecontainer.md). In addition, NodeController provides the following callback methods: [aboutToAppear](../reference/apis-arkui/arkui-ts/ts-custom-component-lifecycle.md#abouttoappear), [aboutToDisappear](../reference/apis-arkui/arkui-ts/ts-custom-component-lifecycle.md#abouttodisappear), [aboutToResize](../reference/apis-arkui/js-apis-arkui-nodeController.md#abouttoresize), [onTouchEvent](../reference/apis-arkui/js-apis-arkui-nodeController.md#ontouchevent), and [rebuild](../reference/apis-arkui/js-apis-arkui-nodeController.md#rebuild), which are used to listen for the status of the associated [NodeContainer](../reference/apis-arkui/arkui-ts/ts-basic-components-nodecontainer.md).

For details about the callbacks, see [NodeController](../reference/apis-arkui/js-apis-arkui-nodeController.md).

> **NOTE**
> 
> - Only custom FrameNodes and root nodes of component trees created by **BuilderNode** are supported under the **NodeContainer**.
> 
> - Since API version 12, you can obtain a built-in component's proxy node through the query API of the FrameNode. This proxy node can be returned as the result of the **makeNode** callback, but it cannot be successfully mounted on the component tree, resulting in a failed display of the proxy node.
> 
> - A node must be used as the child of only one parent node to avoid display or functional issues, particularly in page routing and animation scenarios. For example, if a single node is mounted on multiple **NodeContainer**s through **NodeController**, only one of the **NodeContainer**s will display the node. In addition, any updates to attributes such as visibility and opacity in any of these **NodeContainer**s, which can affect the child component state, will all influence the mounted child node.

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
    console.log("aboutToResize width : " + size.width + " height : " + size.height)
  }

  aboutToAppear() {
    console.log("aboutToAppear")
  }

  aboutToDisappear() {
    console.log("aboutToDisappear");
  }

  onTouchEvent(event: TouchEvent) {
    console.log("onTouchEvent");
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
          // Ensure that the custom node only exists as the child of one node.
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
