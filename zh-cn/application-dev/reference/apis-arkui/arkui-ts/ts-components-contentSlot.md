# ContentSlot

用于渲染并管理Native层使用C-API创建的组件。

支持混合模式开发，当容器是ArkTS组件，子组件在Native侧创建时，推荐使用ContentSlot占位组件。

> **说明：**
>
> 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 接口

ContentSlot(content: Content)

当内容添加到占位符组件时调用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型 | 必填 | 参数描述                                                     |
| ------- | -------- | ---- | ------------------------------------------------------------ |
| content | [Content](#content)  | 是   | Content作为ContentSlot的管理器，通过Native侧提供的接口，可以注册并触发ContentSlot的上下树事件回调以及管理ContentSlot的子组件。 |

## Content

type Content = Content

定义ComponentContent和NodeContent的基类。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 类型 | 说明                                                     |
| ---- | ------------------------------------------------------------ |
| [Content](../js-apis-arkui-Content.md)   | 定义ComponentContent和NodeContent的基类。 |

## 示例

下面的示例展示了ContentSlot的基本用法。

```ts
import { nativeNode } from 'libNativeNode.so' // 开发者自己实现的so
import { NodeContent } from '@kit.ArkUI'

@Entry
@Component
struct Parent {
  private nodeContent: Content = new NodeContent();

  aboutToAppear() {
    // 通过C-API创建节点，并添加到管理器nodeContent上
    nativeNode.createNativeNode(this.nodeContent);
  }

  build() {
    Column() {
      // 显示nodeContent管理器里存放的Native侧的组件
      ContentSlot(this.nodeContent)
    }
  }
}
```
