# Render Node Error Codes
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @xiang-shouxing-->
<!--Designer: @xiang-shouxing-->
<!--Tester: @sally__-->
<!--Adviser: @HelloCrease-->

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 106401 Current Node Is Not a Custom Node

**Error Message**

The FrameNode is not custom node.

**Description**

This error code is reported when the operation is attempted on a node that is not a custom node created on the NDK side.

**Possible Causes**

The provided **ArkUI_NodeHandle** pointer references a node that is not of type ARKUI_NODE_CUSTOM.

**Solution**

When integrating a render node, ensure that you create an NDK node of type ARKUI_NODE_CUSTOM as the root node for the render node.

## 106402 Current Node Already Has Child Nodes

**Error Message**

The FrameNode has children.

**Description**

This error code is reported when the target custom node already contains child nodes.

**Possible Causes**

During render tree construction, the custom node designated as the root node has already mounted child FrameNodes or RenderNodes.

**Solution**

When integrating a render node, verify whether the custom node being used already has child nodes.

## 106403 Current Render Node Has a Parent Component

**Error Message**

The RenderNode has a parent.

**Description**

This error code is reported when the target render node already has a parent node and cannot be mounted under the specified custom component.

**Possible Causes**

The provided **ArkUI_RenderNodeHandle** pointer references a node that is already mounted under another component.

**Solution**

When integrating a render node, verify whether the render node designated as the root is already mounted under another component.

## 106404 Corresponding Render Child Node Not Found

**Error Message**

The render child node is not exist.

**Description**

This error code is reported when the corresponding render child node cannot be located.

**Possible Causes**

The render node referenced by the provided **ArkUI_RenderNodeHandle** pointer does not contain a child node at the specified index.

**Solution**

Verify whether the provided index exceeds the node's range, or whether the render node referenced by the pointer contains any child nodes.

## 106405 Parameter Value Out of Range

**Error Message**

The param is out of range.

**Description**

This error code is reported when an input parameter value exceeds the acceptable range for the API.

**Possible Causes**

The provided parameter exceeds the boundary limits defined for the API being called.

**Solution**

Check the valid parameter range for the API being called.
