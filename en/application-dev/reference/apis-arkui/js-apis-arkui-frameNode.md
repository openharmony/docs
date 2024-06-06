# FrameNode

**FrameNode** represents an entity node in the component tree. It can be used by a [NodeController](./js-apis-arkui-nodeController.md#nodecontroller) to mount a [BuilderNode](./js-apis-arkui-builderNode.md#buildernode) (that holds the to FrameNode) to a [\<NodeContainer>](arkui-ts/ts-basic-components-nodecontainer.md#nodecontainer) or mount a [RenderNode](./js-apis-arkui-renderNode.md#rendernode) to another FrameNode.

> **NOTE**
>
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> 
> **FrameNode** is not available in DevEco Studio Previewer.

## Modules to Import

```ts
import { FrameNode } from "@ohos.arkui.node";
```

## FrameNode

### constructor

constructor(uiContext: UIContext)

Constructor used to create a FrameNode.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name   | Type                                     | Mandatory| Description                              |
| --------- | ----------------------------------------- | ---- | ---------------------------------- |
| uiContext | [UIContext](./js-apis-arkui-UIContext.md) | Yes  | UI context required for creating a node.|

### getRenderNode

getRenderNode(): RenderNode | null

Obtains the RenderNode instance held in this FrameNode.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type                                                          | Description                                                                 |
| -------------------------------------------------------------- | --------------------------------------------------------------------- |
| [RenderNode](./js-apis-arkui-renderNode.md#rendernode) \| null | **RenderNode** instance. If this FrameNode does not hold any RenderNode, null is returned.|

### Example

```ts
import { NodeController, FrameNode } from '@ohos.arkui.node';

class MyNodeController extends NodeController {
  private rootNode: FrameNode | null = null;

  makeNode(uiContext: UIContext): FrameNode | null {
    this.rootNode = new FrameNode(uiContext);

    const renderNode = this.rootNode.getRenderNode();
    if (renderNode !== null) {
      renderNode.size = { width: 100, height: 100 };
      renderNode.backgroundColor = 0XFFFF0000;
    }

    return this.rootNode;
  }
}

@Entry
@Component
struct Index {
  private myNodeController: MyNodeController = new MyNodeController();

  build() {
    Row() {
      NodeContainer(this.myNodeController)
    }
  }
}
```
