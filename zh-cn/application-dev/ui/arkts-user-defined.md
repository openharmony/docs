# 自定义能力概述

## 自定义能力分层
  自定义能力是ArkUI开发框架提供的对UI界面进行开发和定制化的能力。ArkUI开发框架提供的不同控制层级的自定义能力用于实现不同场景的应用的开发。自定义能力的开放层次越低，表示越接近底层基础能力，开发的灵活程度越高，开发难度越高、对于开发者能力的要求也越高。

  当前开放的自定义能力由低到高包括以下几个层次：
  - **自定义组合**：ArkUI框架提供的最基础的自定义方式，通过内置组件和自定义组件的基础能力，将这些能力进行组合，复用已有组件，进一步封装新的组件。具体包括：封装、布局、绘制和动画等基础能力。
  - **自定义扩展**：ArkUI框架提供一系列基于Modifier的自定义扩展能力，通过与UI分离的方式，对已有UI组件的属性、手势、内容进行扩展修改。包括[AttributeModifier](../reference/apis-arkui/arkui-ts/ts-universal-attributes-attribute-modifier.md)、[GestureModifier](../reference/apis-arkui/arkui-ts/ts-universal-attributes-gesture-modifier.md#gesturemodifier-1)、[DrawModifier](../reference/apis-arkui/arkui-ts/ts-universal-attributes-draw-modifier.md#drawmodifier-1)等扩展能力。
  - **自定义节点**：具备底层实体节点的部分基础能力的节点对象（[FrameNode](../reference/apis-arkui/js-apis-arkui-frameNode.md)、[RenderNode](../reference/apis-arkui/js-apis-arkui-renderNode.md)、[BuilderNode](../reference/apis-arkui/js-apis-arkui-builderNode.md)），这些节点能够通过[自定义占位节点](./arkts-user-defined-place-hoder.md#自定义占位节点)与系统组件进行混合显示。自定义节点可以具备单个节点的测算布局、设置基础属性、设置事件监听、自定义绘制渲染内容的自定义能力。
  - **自定义渲染**：通过[XComponent](napi-xcomponent-guidelines.md)的“surface”模式暴露出的NativeWindow，使用NDK接口，可以将EGL/OpenGLES生成的显示数据或其它方式解码生成的媒体流数据写入到NativeWindow中，可以实现渲染内容的自定义。

## 自定义能力导览
  上述提到自定义能力层次不同，使用场景也不同。通过以下导览，可快速了解各种自定义能力的说明以及使用场景和建议。

  |自定义层次|自定义能力|能力说明及适用场景 |
  |--|--|--|
  |自定义组合|自定义封装| [@Component](../quick-start/arkts-create-custom-components.md#component)装饰器：提供了最基础的组件封装能力，通过组合已有组件封装为新的自定义组件。<br> [@Builder](../quick-start/arkts-builder.md)装饰器：提供更轻量的UI封装和复用机制，可以将重复使用的UI结构抽象成一个Builder方法，在组件的build方法中调用。 |
  |自定义组合|自定义布局| [层叠布局（Stack）](./arkts-layout-development-stack-layout.md)：通过Stack容器，结合[尺寸设置](../reference/apis-arkui/arkui-ts/ts-universal-attributes-size.md)和[位置设置](../reference/apis-arkui/arkui-ts/ts-universal-attributes-location.md)的通用属性，可对子组件进行自定义的排布。适用于子组件明确、相对简单的布局场景。<br> [自定义组件的自定义布局](../quick-start/arkts-page-custom-components-layout.md)：通过自定义组件的布局生命周期回调方法，对组件内子组件的位置进行调整。适用于封装一个特定布局算法的自定义组件。 |
  |自定义组合|自定义绘制| [Canvas](arkts-drawing-customization-on-canvas.md)组件：通过Canvas组件的能力进行自定义绘制，通过组合的方式集成到自定义组件中，其接口和W3C标准的Canvas接口相近，在性能不敏感的场景下，适用于熟悉Web开发的开发者，可用于移植基于W3C的Canvas的绘制库。<br>[Shape](arkts-geometric-shape-drawing.md)类组件：通过基础的图形类组件（[Rect](../reference/apis-arkui/arkui-ts/ts-drawing-components-rect.md)、[Path](../reference/apis-arkui/arkui-ts/ts-drawing-components-path.md)、[Circle](../reference/apis-arkui/arkui-ts/ts-drawing-components-circle.md)、[Ellipse](../reference/apis-arkui/arkui-ts/ts-drawing-components-ellipse.md)、[Polyline](../reference/apis-arkui/arkui-ts/ts-drawing-components-polyline.md)、[Polygon](../reference/apis-arkui/arkui-ts/ts-drawing-components-polygon.md)）进行组合，构建出自定义的图形。类似SVG矢量图的能力，适用于比较简单的图形组合，并可以结合动画的能力，实现一些交互的图形动画。 |
  |自定义组合|自定义动画| [属性动画](./arkts-attribute-animation-apis.md)：对于组件的可动画属性，通过属性动画的能力，可组合实现自定义的动画效果。<br>[@AnimatableExtend](../quick-start/arkts-animatable-extend.md)装饰器：对于组件的不可动画属性，通过@AnimatableExtend装饰器，使不可动画属性能实现自定义动画效果。<br>[@ohos.animator](../reference/apis-arkui/js-apis-animator.md) 接口：通过动画接口可实现逐帧修改属性或结合自定义绘制的能力，实现类似帧动画的自定义动画效果。|
  |自定义扩展|属性扩展| [AttributeModifier](../reference/apis-arkui/arkui-ts/ts-universal-attributes-attribute-modifier.md#attributemodifier)：通过AttributeModifier可以实现UI与样式分离，实现属性、事件的动态设置与更新，同时支持跨文件的导出与复用。可用于组件封装，通过暴露Modifier实现属性的扩展。<br>[自定义Modifier](../reference/apis-arkui/arkui-ts/ts-universal-attributes-attribute-modifier.md#自定义modifier)：通过框架提供封装的组件Modifier类，直接在Modifier对象上暴露组件的属性和方法，可以简化组件封装时属性的传递与扩展。<br> [AttributeUpdater](../reference/apis-arkui/js-apis-arkui-AttributeUpdater.md)：在AttributeModifier的基础上增加直接设置属性的能力，避免通过状态变量更新带来的性能损耗。适用于大量组件频繁更新某些属性的场景，提升属性设置的性能。 |
  |自定义扩展|手势扩展| [GestureModifier](../reference/apis-arkui/arkui-ts/ts-universal-attributes-gesture-modifier.md#gesturemodifier-1)：与AttributeModifier的能力类似，支持对手势进行扩展，动态的添加、删除手势，同样可以支持跨文件的导出与复用。适用于需要对自定义手势处理的通用逻辑进行封装和复用的场景。 |
  |自定义扩展|内容扩展| [DrawModifier](../reference/apis-arkui/arkui-ts/ts-universal-attributes-draw-modifier.md#drawmodifier-1)：通过DrawModifier可以在原生组件的基础之上，扩展叠加绘制自定义的内容，或者完全替换组件默认的绘制内容。<br>[ContentModifier](../reference/apis-arkui/arkui-ts/ts-universal-attributes-content-modifier.md#contentmodifiert)：在一些内容区和交互明确的内置组件上，通过ContentModifier可以实现使用自定义的Builder方法替换组件的内容。 |
  |自定义节点|组件节点| [FrameNode](arkts-user-defined-arktsNode-frameNode.md): 表示组件的实体节点，主要提供以下两类能力：<br>完全自定义节点能力：提供完整的自定义能力，包括自定义测量、布局以及绘制，支持节点的动态增加、删除，并且可以为节点设置通用属性和事件。适用于不带渲染引擎，但需要依赖系统的布局、事件、动画及渲染等能力，实现语言为高级语言的三方框架对接。<br>组件代理节点能力：提供声明式组件的代理能力，提供遍历节点树的能力，通过FrameNode可以遍历整个组件树，并通过节点访问组件的信息或者注册额外的事件监听回调。适用于结合无感监听的接口实现打点、广告SDK、中台DFX等业务。<br>[TypedFrameNode](../reference/apis-arkui/js-apis-arkui-frameNode.md#typedframenode12)：通过typeNode提供的接口，可创建具体类型的FrameNode能力。创建出具体组件类型的FrameNode，可通过FrameNode的接口，进行自定义的挂载，生成一棵自定义的组件树。适用于高效对接高级语言开发的动态化框架。 |
  |自定义节点|渲染节点| [RenderNode](arkts-user-defined-arktsNode-renderNode.md)：表示轻量级的渲染节点RenderNode，仅提供了设置渲染相关属性、自定义绘制内容以及节点操作的能力。可以向三方框架提供基础的渲染、动画能力。适用于不带渲染引擎，只依赖系统的基础动画、渲染的三方框架对接。 |
  |自定义节点| 原生组件混合 | [BuilderNode](arkts-user-defined-arktsNode-builderNode.md)：BuilderNode对象提供了能够创建、更新原生组件以及组件树的能力。用于在自定义的FrameNode或RenderNode树结构中嵌入声明式的组件结构，实现原生组件与自定义节点的混合显示。另外还提供了对Builder内容进行纹理导出的能力，可实现在XComponent创建的渲染环境中进行同层渲染显示。 |
  |自定义渲染| 独立渲染 | [XComponent](napi-xcomponent-guidelines.md)：XComponent的“surface”模式会暴露出NativeWindow，通过NDK接口配合NativeWindow可创建独立的渲染环境，将EGL/OpenGLES生成的显示数据或其它方式解码生成的媒体流数据写入到NativeWindow中，不依赖ArkUI框架提供的其它组件能力即可进行自定义的渲染。适用于自带渲染引擎的框架，如游戏引擎、地图、相机等场景。 |
