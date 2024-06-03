# NodeContent

NodeContent是ArkUI提供的ContentSlot的管理器。

> **说明：**
>
> 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { NodeContent } from "@ohos.arkui.node";
```

## NodeContent

### constructor

constructor()

节点内容的实体封装。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**示例：**

```ts
import { nativeNode } from 'libNativeNode.so' // 开发者自己实现的so
import { NodeContent } from '@ohos.arkui.node'

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
