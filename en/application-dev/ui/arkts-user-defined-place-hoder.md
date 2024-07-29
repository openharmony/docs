# Custom Placeholder Node

ArkUI provides ArkTS built-in components as placeholders for custom nodes. These placeholder nodes have common component attributes.

## NodeContainer and NodeController

[NodeContainer](../reference/apis-arkui/arkui-ts/ts-basic-components-nodecontainer.md), as a built-in component, only has common component attributes, and its node specifications refer to the default top-left aligned [Stack](../reference/apis-arkui/arkui-ts/ts-container-stack.md) component. NodeContainer serves as a placeholder container component, mainly used for displaying custom nodes and the display and reuse of custom node trees.

[NodeController](../reference/apis-arkui/js-apis-arkui-nodeController.md) provides a series of lifecycle callbacks, returning the root node of a FrameNode node tree through the makeNode callback. Mount the [FrameNode](../reference/apis-arkui/js-apis-arkui-frameNode.md) node tree to the corresponding NodeContainer. It also provides five callback methods: aboutToAppear, aboutToDisappear, aboutToResize, onTouchEvent, and rebuild, to listen to the corresponding NodeContainer states.

The specific meanings of each lifecycle callback are documented in the [NodeController](../reference/apis-arkui/js-apis-arkui-nodeController.md) interface documentation.

> **NOTE**
> 
> - Only custom FrameNode nodes and the root nodes of component trees created by BuilderNode are supported under NodeContainer.
> 
> - From API Version 12, the interface that returns the proxy node of the built-in component through the FrameNode query interface is supported. The proxy node can be returned as the value of makeNode, but the proxy node cannot be successfully mounted on the component tree, and the final display result is that the proxy node mounting fails.
> 
> - It is necessary to ensure that a node can only be used as a child node of one parent node, otherwise, there may be display exceptions or functional exceptions, especially in page routing scenarios or dynamic effect scenarios. For example, if the same node is mounted on multiple NodeContainer through NodeController, only one placeholder container will display the node, and the visibility, transparency, and other attribute updates of multiple NodeContainer that affect the state of the child component will all affect the mounted child node.

```ts
import { BuilderNode, FrameNode, NodeController, Size, UIContext } from '@kit.ArkUI'

class Params {
  text: string = "this is a text"
}

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

let buttonNode: BuilderNode<[Params]> | null = null;

class MyNodeController extends NodeController {
  private wrapBuilder: WrappedBuilder<[Params]> = wrapBuilder(buttonBuilder);
  private isShow: boolean = false;

  constructor(isShow: boolean) {
    super();
    this.isShow = isShow;
  }

  makeNode(uiContext: UIContext): FrameNode | null {
    if (!this.isShow) {
      return null;
    }
    if (buttonNode == null) {
      buttonNode = new BuilderNode<[Params]>(uiContext);
      buttonNode.build(this.wrapBuilder, { text: "This is a Button" })
    }
    let frameNode = buttonNode?.getFrameNode();
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
          // Then, mount it on the new placeholder node.
          // Ensure that the custom node only exists as a child node of one node.
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
