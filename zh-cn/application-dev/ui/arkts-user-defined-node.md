# 自定义节点概述

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @xiang-shouxing-->
<!--Designer: @xiang-shouxing-->
<!--Tester: @sally__-->
<!--Adviser: @HelloCrease-->

自定义节点是ArkUI通过接口提供的底层实体节点，具备部分基础能力，能够与系统组件混合显示。自定义节点的挂载与显示依赖于[自定义占位节点](./arkts-user-defined-place-holder.md)。当前，自定义节点涵盖三类对象：[FrameNode](../reference/apis-arkui/js-apis-arkui-frameNode.md)、[RenderNode](../reference/apis-arkui/js-apis-arkui-renderNode.md)和[BuilderNode](../reference/apis-arkui/js-apis-arkui-builderNode.md)。FrameNode表示单个自定义组件节点，RenderNode表示为更轻量级的渲染节点，而BuilderNode对象赋予了创建、更新系统组件及其组件树的能力。

![zh-cn_image_user-defined-node](figures/user-defined-node.png)

## 基本概念

- 系统组件：组件是UI的必要元素，形成了在界面中的样子，由ArkUI直接提供的称为[系统组件](arkts-ui-development-overview.md)。

- 实体节点：系统内部维护了一棵组件树，用于处理组件的属性设置、生命周期等逻辑。该组件树上的节点即为实体节点。开发者通过TS获取或创建的自定义节点，其本质是一个前端对象，持有对应实体节点的引用。

- 自定义节点：使用ArkUI提供的接口，以命令式创建的节点。包括自定义组件节点（FrameNode）、自定义渲染节点（RenderNode）、自定义声明式节点（BuilderNode）、[ComponentContent](../reference/apis-arkui/js-apis-arkui-ComponentContent.md)等。

## 自定义占位节点

自定义占位节点作为系统组件可以在组件树上为自定义节点提供挂载的点。通过自定义占位节点，可以将自定义节点挂载在占位节点上，实现自定义节点与系统组件的混合显示。

## 自定义组件节点 (FrameNode)

FrameNode表示组件的实体节点，具体可以分为两大类能力：完全自定义节点的能力以及系统组件节点代理的能力。

- 完全自定义节点：提供完整的自定义能力，包括自定义测量、布局以及绘制，支持节点的动态增、删，设置通用属性，设置事件回调。适用于不自带渲染引擎，需要依赖系统的布局、事件、动画、渲染等能力的场景。通过FrameNode的[构造函数](../reference/apis-arkui/js-apis-arkui-frameNode.md#constructor)创建的节点或者通过[typeNode](../reference/apis-arkui/js-apis-arkui-frameNode.md#typenode12)的节点创建方法（例如：[createNode('Text')](../reference/apis-arkui/js-apis-arkui-frameNode.md#createnodetext12)、[createNode('Column')](../reference/apis-arkui/js-apis-arkui-frameNode.md#createnodecolumn12)、[createNode('Row')](../reference/apis-arkui/js-apis-arkui-frameNode.md#createnoderow12)等）创建出来的节点属于完全自定义节点。

- 系统组件代理节点：提供系统组件的代理能力，提供遍历节点树的能力，通过组件树上的FrameNode可以遍历整个组件树，并通过节点访问组件的信息或者注册额外的事件监听回调。适用于结合无感监听的接口实现打点、广告SDK、中台DFX等业务。通过FrameNode相关的查询接口（例如：[getChild](../reference/apis-arkui/js-apis-arkui-frameNode.md#getchild12)、[getParent](../reference/apis-arkui/js-apis-arkui-frameNode.md#getparent12)、[getNextSibling](../reference/apis-arkui/js-apis-arkui-frameNode.md#getnextsibling12)、[getAttachedFrameNodeById](../reference/apis-arkui/arkts-apis-uicontext-uicontext.md#getattachedframenodebyid12)等）返回的FrameNode对象，若不属于完全自定义节点则为系统组件代理节点。

## 自定义渲染节点 (RenderNode)

RenderNode作为轻量级的渲染节点，仅提供了设置渲染相关属性、自定义绘制内容以及节点操作的能力。适用于仅依赖系统渲染与动画能力的自定义场景。

## 自定义声明式节点 (BuilderNode)

BuilderNode通过无状态的UI方法[全局自定义构建函数](../ui/state-management/arkts-builder.md#全局自定义构建函数)@Builder生成组件树，组件树内的节点为系统组件。适用于需要基于系统能力创建特定组件树与其他自定义节点进行混合显示的场景。相比较系统组件，BuilderNode具备预创建的优势，可以控制开始创建的时间。由于持有实体节点对象，因此可以同步实现节点的复用，通过占位节点结合FrameNode、RenderNode的节点操作能力控制显示位置。

## 设置自定义节点跨语言属性

ArkUI支持在前端使用ArkTS语言创建命令式节点，即FrameNode节点，也可以在Native侧使用C语言创建命令式节点，并且可以混合使用两类节点构建页面。针对上述场景，ArkUI提供命令式节点跨语言属性设置功能，即使用ArkTS语言创建的命令式节点，可以在Native侧进行属性设置。使用C语言创建的节点，可以在ArkTS侧进行属性设置。