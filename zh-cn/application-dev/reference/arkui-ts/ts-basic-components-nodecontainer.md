# NodeContanier

基础组件，不支持尾随添加子节点。组件接受一个[NodeController](../apis/js-apis-arkui-node.md#nodecontroller)的实例接口。需要与[NodeController](../apis/js-apis-arkui-node.md#nodecontroller)组合使用。

> **说明：**
>
> 该组件从API Version 11开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## 子组件

不支持子组件。

## 接口

### NodeContanier

NodeContanier(controller: import('../api/@ohos.arkui.node').NodeController)

**参数：**

| 参数名     | 参数类型                                                       | 必填 | 参数描述                                                                                                                                   |
| ---------- | -------------------------------------------------------------- | ---- | ------------------------------------------------------------------------------------------------------------------------------------------ |
| controller | [NodeController](../apis/js-apis-arkui-node.md#nodecontroller) | 是   | NodeController用于控制NodeContainer中的节点的上树和下树，反映NodeContainer容器的生命周期。 |

## 属性

支持[通用属性](ts-universal-attributes-size.md)

## 事件

支持[通用事件](ts-universal-events-click.md)。

## 示例

```ts
import { UIContext } from '@ohos.arkui.UIContext';
import { NodeController,BuilderNode, BaseNode }  from '@ohos.arkui.node';


declare class Params{
  text:string
}

@Builder
function buttonBuilder(params:Params)
{
  Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.SpaceEvenly }) {
    Text(params.text)
      .fontSize(12)
    Button(`This is a Button`,{ type: ButtonType.Normal, stateEffect: true })
      .fontSize(12)
      .borderRadius(8)
      .backgroundColor(0x317aff)
  }
  .height(100)
  .width(200)
}

class MyNodeController extends NodeController {
  private rootNode :BuilderNode<Params[]> | null = null;
  private wrapBuilder  = new WrappedBuilder(buttonBuilder);

  makeNode(uiContext:UIContext) : BaseNode | null
  {
    if(this.rootNode == null)
    {
      this.rootNode = new BuilderNode(uiContext);
      this.rootNode.build(this.wrapBuilder,{ text:"This is a Text" })
    }
    return this.rootNode;
  }
}


@Entry
@Component
struct Index {
  @State baseNode : MyNodeController = new MyNodeController()

  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Start, justifyContent: FlexAlign.SpaceEvenly }) {
      Text("This is a NodeContainer contains a text and a button ")
        .fontSize(9)
        .fontColor(0xCCCCCC)
      NodeContainer( this.baseNode )
        .borderWidth(1)
        .onClick(()=> {
          console.log("click event");
        })
    }
    .padding({ left: 35, right: 35, top: 35 })
    .height(200)
    .width(300)
  }
}
```
![patternlock](figures/nodeContianer_sample.jpg)