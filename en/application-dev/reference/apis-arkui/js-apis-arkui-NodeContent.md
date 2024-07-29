# NodeContent

NodeContent is the manager of ContentSlot provided by ArkUI.

> **NOTE**
>
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Import modules.

```ts
import { NodeContent } from "@ohos.arkui.node";
```

## NodeContent

### constructor

constructor()

Encapsulates node content entities.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Example**

```ts
import { nativeNode } from'libNativeNode.so' // so implemented by the developers
import { NodeContent } from '@ohos.arkui.node'

@Component
struct Parent {
    private nodeContent: Content = new NodeContent();

    aboutToAppear() {
        // Create a node through the C-API and add it to the nodeContent manager.
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

Add FrameNode to NodeContent based on parameters.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type                                                  | Mandatory/Optional | Note:            |
| ------- | ------------------------------------------------------ | ---- | ---------------- |
| node | [FrameNode](./js-apis-arkui-frameNode.md#framenode) | M  | Child node to append. |

### removeFrameNode<sup>12+</sup>

removeFrameNode(node: FrameNode): void

Deletes FrameNode from NodeContent based on parameters.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type                                                  | Mandatory/Optional | Note:            |
| ------- | ------------------------------------------------------ | ---- | ---------------- |
| node | [FrameNode](./js-apis-arkui-frameNode.md#framenode) | M  | FrameNode to be deleted. |

**Example**

```ts
import { NodeContent, typeNode } from '@ohos.arkui.node';

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
