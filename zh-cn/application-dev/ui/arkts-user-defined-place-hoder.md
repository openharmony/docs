# 自定义占位节点

ArkUI提供了ArkTS原生组件作为自定义节点的占位节点。该占位节点具备组件的通用属性。

## NodeContainer和NodeController

[NodeContainer](../reference/apis-arkui/arkui-ts/ts-basic-components-nodecontainer.md)作为原生组件，仅具备组件的通用属性，其节点规格参考默认左上角对齐的[Stack](../reference/apis-arkui/arkui-ts/ts-container-stack.md)组件。NodeContainer作为一个占位容器组件，主要是用于显示自定义节点以及自定义节点树的显示和复用。

[NodeController](../reference/apis-arkui/js-apis-arkui-nodeController.md)提供了一系列生命周期回调，通过makeNode回调返回一个FrameNode节点树的根节点。将[FrameNode](../reference/apis-arkui/js-apis-arkui-frameNode.md)节点树挂载到对应的NodeContainer下。同时提供了aboutToAppear、aboutToDisappear、aboutToResize、onTouchEvent、rebuild五个回调方法用于监听对应的NodeContainer的状态。

每个生命周期的回调的具体含义参考[NodeController](../reference/apis-arkui/js-apis-arkui-nodeController.md)的接口文档说明。

> **说明：**
> 
> - NodeContainer下仅支持挂载自定义的FrameNode节点以及BuilderNode创建的组件树的根节点。
> 
> - 从API Version 12开始支持的接口，可以通过FrameNode的查询接接口返回原生组件的代理节点，代理节点可以作为makeNode的返回值进行返回，但代理节点无法成功挂载在组件树上，最终的显示结果为代理节点挂载失败。
> 
> - 需要保证一个节点只能作为一个父节点的子节点去使用，否则可能存在显示异常或者功能异常，尤其是页面路由场景或者动效场景。例如，如果通过NodeController将同一个节点挂载在多个NodeContainer上，仅一个占位容器下会显示节点，且多个NodeContainer的可见性、透明度等影响子组件状态的属性更新均会影响被挂载的子节点。

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
