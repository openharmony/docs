# 自定义占位节点

ArkUI提供了ArkTS原生组件作为自定义节点的占位节点。该占位节点具备组件的通用属性。

## NodeContainer和NodeController

[NodeContainer](../reference/apis-arkui/arkui-ts/ts-basic-components-nodecontainer.md)作为原生组件，仅具备组件的通用属性，其节点规格参考默认左上角对齐的[Stack](../reference/apis-arkui/arkui-ts/ts-container-stack.md)组件。[NodeContainer](../reference/apis-arkui/arkui-ts/ts-basic-components-nodecontainer.md)作为一个占位容器组件，主要是用于显示自定义节点以及自定义节点树的显示和复用。

[NodeController](../reference/apis-arkui/js-apis-arkui-nodeController.md)提供了一系列生命周期回调，通过[makeNode](../reference/apis-arkui/js-apis-arkui-nodeController.md#makenode)回调返回一个 [FrameNode](../reference/apis-arkui/js-apis-arkui-frameNode.md#framenode) 节点树的根节点。将[FrameNode](../reference/apis-arkui/js-apis-arkui-frameNode.md)节点树挂载到对应的[NodeContainer](../reference/apis-arkui/arkui-ts/ts-basic-components-nodecontainer.md)下。同时提供了[aboutToAppear](../reference/apis-arkui/arkui-ts/ts-custom-component-lifecycle.md#abouttoappear)、[aboutToDisappear](../reference/apis-arkui/arkui-ts/ts-custom-component-lifecycle.md#abouttodisappear)、[aboutToResize](../reference/apis-arkui/js-apis-arkui-nodeController.md#abouttoresize)、[onTouchEvent](../reference/apis-arkui/js-apis-arkui-nodeController.md#ontouchevent)、[rebuild](../reference/apis-arkui/js-apis-arkui-nodeController.md#rebuild)五个回调方法用于监听对应的[NodeContainer](../reference/apis-arkui/arkui-ts/ts-basic-components-nodecontainer.md)的状态。

每个生命周期的回调的具体含义参考[NodeController](../reference/apis-arkui/js-apis-arkui-nodeController.md)的接口文档说明。

> **说明：**
> 
> - NodeContainer下仅支持挂载自定义的FrameNode节点以及BuilderNode创建的组件树的根节点。
> 
> - 从API Version 12开始支持的接口，可以通过FrameNode的查询接接口返回原生组件的代理节点，代理节点可以作为makeNode的返回值进行返回，但代理节点无法成功挂载在组件树上，最终的显示结果为代理节点挂载失败。
> 
> - 需要保证一个节点只能作为一个父节点的子节点去使用，否则可能存在显示异常或者功能异常，尤其是页面路由场景或者动效场景。例如，如果通过NodeController将同一个节点挂载在多个NodeContainer上，仅一个占位容器下会显示节点，且多个NodeContainer的可见性、透明度等影响子组件状态的属性更新均会影响被挂载的子节点。

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
          // 先在原始占位节点中下树
          // 后在新的占位节点中上树
          // 保证自定义节点仅作为一个节点的子节点存在
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
