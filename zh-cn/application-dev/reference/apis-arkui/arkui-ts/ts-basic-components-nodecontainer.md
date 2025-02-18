# NodeContainer

基础组件，不支持尾随添加子节点。组件接受一个[NodeController](../js-apis-arkui-nodeController.md)的实例接口。需要NodeController组合使用。

> **说明：**
>
> 该组件从API Version 11开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> 该组件下仅支持挂载自定义节点[FrameNode](../js-apis-arkui-frameNode.md)或者是[BuilderNode](../js-apis-arkui-builderNode.md)中获取的根节点FrameNode。
> 不支持挂载查询获得的原生系统组件[代理节点](../js-apis-arkui-frameNode.md#ismodifiable12)。
>
> 当前不支持使用[动态属性设置](./ts-universal-attributes-attribute-modifier.md)
## 子组件

不支持子组件。

## 接口

### NodeContainer

NodeContainer(controller: NodeController)

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型                                                 | 必填 | 说明                                                         |
| ---------- | ---------------------------------------------------- | ---- | ------------------------------------------------------------ |
| controller | [NodeController](../js-apis-arkui-nodeController.md) | 是   | NodeController用于控制NodeContainer中的节点的上树和下树，反映NodeContainer容器的生命周期。 |
## 属性

支持[通用属性](ts-universal-attributes-size.md)

## 事件

支持[通用事件](ts-universal-events-click.md)。

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
      this.rootNode.build(this.wrapBuilder, { text: "This is a Text" })
    }
    return this.rootNode.getFrameNode();
  }
}


@Entry
@Component
struct Index {
  private baseNode: MyNodeController = new MyNodeController()

  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Start, justifyContent: FlexAlign.SpaceEvenly }) {
      Text("This is a NodeContainer contains a text and a button ")
        .fontSize(9)
        .fontColor(0xCCCCCC)
      NodeContainer(this.baseNode)
        .borderWidth(1)
        .onClick(() => {
          console.log("click event");
        })
    }
    .padding({ left: 35, right: 35, top: 35 })
    .height(200)
    .width(300)
  }
}
```
![patternlock](figures/nodeContainer_sample.jpg)