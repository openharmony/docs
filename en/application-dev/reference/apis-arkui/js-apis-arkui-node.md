# @ohos.arkui.node 

The **Node** module provides level-2 module APIs of custom nodes to export and use.

> **NOTE**
>
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> 
> Custom nodes are not available in DevEco Studio Previewer.

## BuilderNode

The [BuilderNode](./js-apis-arkui-builderNode.md#buildernode) module provides APIs for creating a BuilderNode – a custom node that can be used to mount built-in components. Avoid mounting a BuilderNode as a child node to other custom nodes.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

## FrameNode

The [FrameNode](./js-apis-arkui-frameNode.md#framenode) module provides APIs for a FrameNode, which represents an entity node in the component tree. It can be used by a [NodeController](./js-apis-arkui-nodeController.md#nodecontroller) to mount a [BuilderNode](./js-apis-arkui-builderNode.md#buildernode) (that holds the FrameNode) to a [NodeContainer](arkui-ts/ts-basic-components-nodecontainer.md#nodecontainer) or mount a [RenderNode](./js-apis-arkui-renderNode.md#rendernode) to another FrameNode.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

## NodeController

The [NodeController](./js-apis-arkui-nodeController.md#nodecontroller) module provides APIs for managing custom nodes, such as creating, showing, and updating custom nodes, and APIs for mounting custom nodes to a [NodeContainer](arkui-ts/ts-basic-components-nodecontainer.md#nodecontainer) component.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

## Graphics

[Graphics](./js-apis-arkui-graphics.md#graphics) module: provides APIs for defining attributes of a custom node.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

## RenderNode

The [RenderNode](./js-apis-arkui-renderNode.md#rendernode) module provides APIs for creating a RenderNode in custom drawing settings with C APIs.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

## XComponentNode

The [XComponentNode](./js-apis-arkui-xcomponentNode.md#xcomponentnode) module provides APIs a XComponentNode, an **XComponent** in the component tree. You can write EGL/OpenGL ES and media data and display it on the **XComponent**, whose rendering type can be dynamically modified.

**System capability**: SystemCapability.ArkUI.ArkUI.Full



## Obtaining UI Context
To obtain the UI context, use any of the following methods:

1. Call [getUIContext()](arkts-apis-window-Window.md#getuicontext10) in **ohos.window** to obtain the **UIContext **instance.

2. Call the built-in method [getUIContext()](arkui-ts/ts-custom-component-api.md#getuicontext) of the custom component.

3. Use the [makeNode](./js-apis-arkui-nodeController.md#makenode) callback of [NodeController](./js-apis-arkui-nodeController.md#nodecontroller).
