# Custom Node Overview

Custom nodes in the ArkUI framework are node objects that provide some basic capabilities of the underlying entity nodes through various APIs, allowing for the mixing with built-in components.

The mounting and display of these custom nodes rely on what are known as custom placeholder nodes.  Three types of custom nodes that are currently available:  [FrameNode](../reference/apis-arkui/js-apis-arkui-frameNode.md), [RenderNode](../reference/apis-arkui/js-apis-arkui-renderNode.md), [BuilderNode](../reference/apis-arkui/js-apis-arkui-builderNode.md).

## Custom Placeholder Nodes
Custom placeholder nodes act as built-in components and provide mounting points for custom nodes on the built-in component tree. By using custom placeholder nodes, custom nodes can be mounted on placeholder nodes to achieve a mixed display of custom nodes and built-in components.

## FrameNode
FrameNode represents the entity node of a component and can be divided into two major capabilities: full custom node capabilities and proxy capabilities for native component nodes.

- Full custom node: Provides complete customization capabilities, including custom measurement, layout, and drawing, supports dynamic addition and deletion of nodes, setting common attributes, and setting event callbacks. Suitable for scenarios that do not have their own rendering engine and need to rely on the system's layout, event, animation, and rendering capabilities.

- Proxy node for built-in components: Provides proxy capabilities for built-in components, offering the capability to traverse the component tree. Through FrameNodes on the component tree, you can traverse the entire component tree and access component information or register additional event listening callbacks. Suitable for combining unobtrusive listening interfaces to implement business such as tracking, ad SDKs, and mid-platform DFX.

## RenderNode
RenderNode, as a lightweight rendering node, only provides capabilities for setting rendering-related properties, custom drawing content, and node operations. Suitable for custom scenarios that rely solely on the system's rendering and animation capabilities.

## BuilderNode
BuilderNode generates a component tree through stateless UI methods [Global @Builder](../quick-start/arkts-builder.md#global-custom-builder-function), and the nodes within the component tree are native components. Suitable for scenarios that require creating a specific native component tree based on system capabilities for mixed display with other custom nodes. Compared to native components, BuilderNode has the advantage of pre-creation, allowing control over the start time of creation. Since it holds the entity node object, it can synchronize the reuse of nodes, and control the display position through placeholder nodes combined with the node operation capabilities of FrameNode and RenderNode.
