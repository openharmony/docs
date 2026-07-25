# NodeContainer
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @wangyang2022-->
<!--Designer: @wangyang2022-->
<!--Tester: @sally__-->
<!--Adviser: @Brilliantry_Rui-->

基础组件，用于挂载自定义节点（如[FrameNode](../js-apis-arkui-frameNode.md)或[BuilderNode](../js-apis-arkui-builderNode.md)中获取的根节点FrameNode），并通过[NodeController](../js-apis-arkui-nodeController.md)动态控制节点的上树和下树，适用于需要在组件树中动态插入、移除自定义节点以实现UI按需加载与节点复用的场景，可提升页面渲染效率并降低节点创建开销。组件不支持尾随添加子节点，接受一个[NodeController](../js-apis-arkui-nodeController.md)实例，需与NodeController组合使用。

> **说明：**
>
> - 该组件从API version 11开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> - 本模块接口仅可在Stage模型下使用。
>
> - 该组件下仅支持挂载自定义节点[FrameNode](../js-apis-arkui-frameNode.md)或者是[BuilderNode](../js-apis-arkui-builderNode.md)中获取的根节点FrameNode。
>
> - 不支持挂载查询获得的系统组件代理节点，请参见[isModifiable](../js-apis-arkui-frameNode.md#ismodifiable12)。
>
> - 当前不支持使用[动态属性设置](./ts-universal-attributes-attribute-modifier.md)。
>
> - 该组件下的节点树构建时会使用UI实例[UIContext](../arkts-apis-uicontext-uicontext.md)，实例切换时可能会因实例不匹配，导致所绑定[NodeController](../js-apis-arkui-nodeController.md)的[makeNode](../js-apis-arkui-nodeController.md#makenode)回调方法的入参为undefined，因此该组件当前不支持跨实例的节点复用。
>
> - 该组件未销毁时，不会主动触发挂载节点的下树。

## 子组件

不支持子组件。

## 接口

### NodeContainer

NodeContainer(controller: import('../api/@ohos.arkui.node').NodeController)

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型                                                 | 必填 | 说明                                                         |
| ---------- | ---------------------------------------------------- | ---- | ------------------------------------------------------------ |
| controller | import('../api/@ohos.arkui.node').[NodeController](../js-apis-arkui-nodeController.md) | 是   | NodeController用于控制NodeContainer中的节点的上树和下树，反映NodeContainer容器的生命周期。 |
## 属性

支持[通用属性](./ts-component-general-attributes.md)，但不支持[动态属性设置](./ts-universal-attributes-attribute-modifier.md)。

## 事件

支持[通用事件](./ts-component-general-events.md)。

## 示例

通过NodeController挂载BuilderNode节点。

```ts
import { NodeController, BuilderNode, FrameNode, UIContext } from '@kit.ArkUI';

declare class Params {
  text: string
}

@Builder
function buttonBuilder(params: Params) {
  Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.SpaceEvenly }) {
    Text(params.text)
      .fontSize(12)
    Button(`This is a Button`, { type: ButtonType.Normal, stateEffect: true })
      .fontSize(12)
      .borderRadius(8)
      .backgroundColor(0x317aff)
  }
  .height(100)
  .width(200)
}

class MyNodeController extends NodeController {
  private rootNode: BuilderNode<[Params]> | null = null;
  private wrapBuilder: WrappedBuilder<[Params]> = wrapBuilder(buttonBuilder);

  makeNode(uiContext: UIContext): FrameNode | null {
    if (this.rootNode === null) {
      this.rootNode = new BuilderNode(uiContext);
      this.rootNode.build(this.wrapBuilder, { text: 'This is a Text' })
    }
    return this.rootNode.getFrameNode();
  }

  aboutToDisappear() {
    this.rootNode?.dispose();
  }
}


@Entry
@Component
struct Index {
  private baseNode: MyNodeController = new MyNodeController()

  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Start, justifyContent: FlexAlign.SpaceEvenly }) {
      Text('This is a NodeContainer contains a text and a button ')
        .fontSize(9)
        .fontColor(0xCCCCCC)
      NodeContainer(this.baseNode)
        .borderWidth(1)
        .onClick(() => {
          console.info('click event');
        })
    }
    .padding({ left: 35, right: 35, top: 35 })
    .height(200)
    .width(300)
  }
}
```
![NodeContainer示例](figures/nodeContainer_sample.jpg)