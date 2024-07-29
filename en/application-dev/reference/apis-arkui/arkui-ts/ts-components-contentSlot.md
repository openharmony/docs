# ContentSlot

To render and manage components created by the native layer using C-APIs.

Hybrid development is supported. When the container is an **ArkTS** component and the child component is created on the native side, the **ContentSlot** placeholder component is recommended.

> **NOTE**
>
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Interface

ContentSlot(content: Content)

Called when content is added to a placeholder component

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type | Mandatory | Description                                                    |
| ------- | -------- | ---- | ------------------------------------------------------------ |
| content | [Content](../js-apis-arkui-Content.md)  | Yes  | As the manager of **ContentSlot**, **Content** can register and trigger the callback of the log-in and log-out events of **ContentSlot** and manage the child components through native APIs. |

**Example**

```ts
import { nativeNode } from'libNativeNode.so' // so implemented by the developers
import { NodeContent } from '@ohos.arkui.node'

@Entry
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
