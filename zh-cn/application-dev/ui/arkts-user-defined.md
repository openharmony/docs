# 自定义能力概述

  自定义能力是ArkUI开发框架提供的对UI界面进行开发和设计的能力。现有的自定义能力包括：自定义节点。ArkUI开发框架提供的不同控制层级的自定义能力用于实现不同场景的应用的开发。自定义能力的控制层级越低接近基础能力，开发的灵活程度越高，开发难度越高、对于开发者能力的要求也越高。

  - 自定义节点：具备底层实体节点的部分基础能力的节点对象，这些节点能够通过[自定义占位节点](./arkts-user-defined-place-hoder.md#自定义占位节点)与原生控件进行混合显示。自定义节可以具备单个节点的测算布局、设置基础属性、设置事件监听、自定义绘制渲染内容的自定义能力。包括[FrameNode](../reference/apis-arkui/js-apis-arkui-frameNode.md)、[RenderNode](../reference/apis-arkui/js-apis-arkui-renderNode.md)、[BuilderNode](../reference/apis-arkui/js-apis-arkui-builderNode.md)三类对象。FrameNode表示了组件的实体节点，RenderNode表示更加轻量级的渲染节点，BuilderNode对象提供了能够创建、更新原生组件以及组件树的能力。
