# 渲染节点错误码
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @xiang-shouxing-->
<!--Designer: @xiang-shouxing-->
<!--Tester: @sally__-->
<!--Adviser: @HelloCrease-->

> **说明：**
>
> 以下仅介绍本模块特有错误码，通用错误码请参考[通用错误码说明文档](../errorcode-universal.md)。

## 106401 当前节点不是自定义节点

**错误信息**

The FrameNode is not custom node.

**错误描述**

当前的操作的节点不是NDK侧的自定义节点。

**可能原因**

开发者传入的ArkUI_NodeHandle指针所对应的节点类型非ARKUI_NODE_CUSTOM类型。

**处理步骤**

接入渲染节点流程时，创建一个Custom类型的NDK节点作为渲染节点的根节点类型。

## 106402 当前节点已存在子节点

**错误信息**

The FrameNode has children.

**错误描述**

当前的操作的自定义节点已存在子节点。

**可能原因**

开发者构造render树时，作为根节点的自定义节点已挂载子FrameNode或RenderNode。

**处理步骤**

接入渲染节点流程时，排查使用的自定义节点是否已存在子节点。

## 106403 当前渲染节点存在父组件

**错误信息**

The RenderNode has a parent.

**错误描述**

当前操作的渲染节点已有父节点，无法挂载至相应自定义组件下。

**可能原因**

开发者传入的ArkUI_RenderNodeHandle指针所对应的节点已挂载至其他组件下。

**处理步骤**

接入渲染节点流程时，排查作为根节点的renderNode是否已挂载至其他组件下。

## 106404 未找到对应的渲染子节点

**错误信息**

The render child node is not exist.

**错误描述**

无法查找到对应的渲染子节点。

**可能原因**

开发者传入的ArkUI_RenderNodeHandle指针所对应的渲染节点无法查询到对应下标的子节点。

**处理步骤**

排查传入的下标是否超出节点范围，或对应指针对应的渲染节点是否存在子节点。

## 106405 参数值超出范围

**错误信息**

The param is out of range.

**错误描述**

入参值超出接口接收值的范围。

**可能原因**

开发者传入的参数超出该接口的边界。

**处理步骤**

检查接口调用的入参范围。
