# NodeContent

The **NodeContent** module implements a manager for **ContentSlot** components in ArkUI.

> **NOTE**
>
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import {NodeContent } from '@kit.ArkUI'
```

## NodeContent

### constructor

constructor()

A constructor used to create a **NodeContent** object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Example** 

<!--code_no_check-->

```ts
import { nativeNode } from'libNativeNode.so' // so. file implemented by you.
import {NodeContent } from '@kit.ArkUI'

@Component
struct Parent {
    private nodeContent: Content = new NodeContent();

    aboutToAppear() {
        // Create a node through the C API and add it to the nodeContent manager.
        nativeNode.createNativeNode(this.nodeContent);
    }

    build() {
        Column() {
            // Display the native components stored in the nodeContent manager.
            ContentSlot(this.nodeContent)
        }
    }
}
```

### addFrameNode<sup>12+</sup>

addFrameNode(node: FrameNode): void

Adds a FrameNode to this **NodeContent** object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type                                                  | Mandatory | Description            |
| ------- | ------------------------------------------------------ | ---- | ---------------- |
| node | [FrameNode](./js-apis-arkui-frameNode.md#framenode) | Yes  | FrameNode to add. |

### removeFrameNode<sup>12+</sup>

removeFrameNode(node: FrameNode): void

Removes a FrameNode from this **NodeContent** object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type                                                  | Mandatory | Description            |
| ------- | ------------------------------------------------------ | ---- | ---------------- |
| node | [FrameNode](./js-apis-arkui-frameNode.md#framenode) | Yes  | FrameNode to remove. |

**Example**

```ts
import {NodeContent, typeNode } from '@kit.ArkUI';

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

@Entry
@Component
struct Index {
  @State message: string = 'Hello World';
  controller = new NodeContentCtrl(this.getUIContext());

  build() {
    Row() {
      Column() {
        ContentSlot(this.controller.GetContent())
        Button("AddToSlot")
          .onClick(() => {
            this.controller.AddNode()
          })
        Button("RemoveBack")
          .onClick(() => {
            this.controller.RemoveNode()
          })
        Button("RemoveFront")
          .onClick(() => {
            this.controller.RemoveFront()
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```
