# Auxiliary Node Error Codes

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @wangyang2022-->
<!--Designer: @wangyang2022-->
<!--Tester: @sally__-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=4da4cab88c5c9e987b28cefe3239aadd52f84dba translatedAt=2026-08-13T01:25:46.347Z pushedAt=2026-08-13T01:31:11.553Z -->

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 106206 The Node Has Been Accepted as an Auxiliary Node

**Error Message**

The node has already been adopted.

**Description**

This error code is reported when the node has been accepted as an auxiliary node and an attempt is made to mount the node as a child node.<br>

**Possible Causes**

The node has been accepted as an auxiliary node (through the previous acceptance) and cannot be accepted or mounted again.

**Solution**

Cancel the acceptance of the node and then mount it as a child node.

## 106207 The Auxiliary Node to Accept Has a Parent Node

**Error Message**

This node already has a parent node.

**Description**

This error code is reported when the node already has a parent node and other nodes attempt to accept the node.<br>

**Possible Causes**

The node to accept already has a parent node (for example, it has been mounted under another parent node), and cannot be accepted again.

**Solution**

Remove the node from its parent node and then accept the node.

## 106208 The Node Cannot Be Accepted as an Auxiliary Node

**Error Message**

The node cannot be adopted.

**Description**

This error code is reported when the node cannot be accepted as an auxiliary node.<br>

**Possible Causes**

1. The node is a null pointer.

2. The node does not meet the acceptance criteria. Only the following node types are supported for acceptance:

    - Command node created using the ArkTS language.

    - Command node created using the C language.

    - Root node of BuilderNode.

**Solution**

Ensure that the node is not a null pointer and meets the acceptance criteria before attempting to accept it.

## 106209 The Node Cannot Accept Other Nodes

**Error Message**

The node cannot adopt children.

**Description**

This error code is reported when the node cannot accept other nodes.

**Possible Causes**

1. The node is a null pointer.

2. The node does not support the acceptance operation. Only the following node types are supported for acceptance:

    - Command node created using the ArkTS language.

    - Command node created using the C language.

**Solution**

Ensure that the node is not a null pointer and supports acceptance of other nodes before performing acceptance.

## 106210 The Node Is Not an Affiliated Node Accepted by the Target Node

**Error Message**

This child is not adopted by the parent node.

**Description**

This error code is reported when the child node is not accepted by the parent node.

**Possible Causes**

1. The child node has not been accepted by any parent node.

2. The child node has been accepted, but the accepting parent node is not the current target node.

**Solution**

Check whether the node has been adopted as an affiliated node by the parent node. If it has not been adopted, it does not need to be removed. If it has been adopted by another node, remove it from the original parent node before proceeding.