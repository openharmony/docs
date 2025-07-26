# 自定义组合

## 概述

自定义组合提供组件粒度的自定义能力，开发者可通过自定义组件组合已有组件来构建特定的符合业务逻辑的高级组件。组件组合的过程中可以使用布局容器和通用布局属性来对子组件进行自定义的位置排布，可以使用Canvas组件完成纯自绘，也可以使用Shape类组件，通过形状的组合，构建几何图形，实现带交互的图形动画。动画模块可针对不同类型的属性，实现灵活的动画效果。

## 基本概念

- 自定义封装：将多个基础组件组合成具有特定功能的复合组件。
- 自定义布局：在对多个组件进行组合的过程中，各个组件的位置、尺寸都应该是符合业务场景，因此开发者需要对各个子组件进行自定义的排布。
- 自定义绘制：通过组合各类组件，还能达成各种绘制效果的高级组件。
- 自定义动画：组合的各类组件可以通过不同的方式定义动画，实现组件位置、尺寸、样式或绘制内容随时间变化的效果。


## 自定义组合的典型场景
|    场景      | 说明     |
|---------------|-----------------------------------------|
| 使用@Component装饰器构建自定义组件   | 自定义封装的代表性方法是[@Component](../ui/state-management/arkts-create-custom-components.md#component)装饰器，可以通过将已有的自定义组件和基础组件进行组装，构成新的自定义组件。通常用于有内部成员方法、状态变量的部件，例如：视频列表里面的每一个视频卡片，卡片内部有自己的视频组件、文本组件、点击事件、跳转链接等等。 |
| 使用@Builder装饰器构建可复用的UI结构   |   相比于[@Component](../ui/state-management/arkts-create-custom-components.md#component)装饰器，[@Builder](../ui/state-management/arkts-builder.md)装饰器更加轻量级，可以将纯粹的UI结构风封装成方法，在各个自定义组件的build方法中进行调用，达成UI结构复用的目的。相当于将[@Component](../ui/state-management/arkts-create-custom-components.md#component)里面的build部分单抽出来，本身不包含状态变量。  |
| 使用Stack容器对子组件进行自定义布局   | 对于子组件明确、结构相对简单的布局场景，可以使用层叠布局，通过[Stack](./arkts-layout-development-stack-layout.md)容器，结合[尺寸](../reference/apis-arkui/arkui-ts/ts-universal-attributes-size.md)和[位置](../reference/apis-arkui/arkui-ts/ts-universal-attributes-location.md)的通用属性，来控制子组件的布局。[Stack](./arkts-layout-development-stack-layout.md)组件中的子元素依次入栈，通过顺序来控制遮盖效果，具有较强的页面层叠能力，常用于实现卡片层叠等效果。  |
| 结合自定义组件的布局生命周期回调方法进行自定义布局     |  对于子组件组成是动态的场景，可结合布局生命周期回调方法实现[自定义组件的自定义布局](../ui/state-management/arkts-page-custom-components-layout.md)，随子组件的动态变化，动态调整子组件的尺寸和位置，形成特定的布局算法。  |
| 组合基础图形实现自定义绘制效果|如果高级组件的UI效果是较为规则化的，例如：矩形、圆形、多边形等基础的图形，以及基础图形组合成的自定义图形，可通过基础的[图形类组件](arkts-geometric-shape-drawing.md)（[Rect](../reference/apis-arkui/arkui-ts/ts-drawing-components-rect.md)、[Path](../reference/apis-arkui/arkui-ts/ts-drawing-components-path.md)、[Circle](../reference/apis-arkui/arkui-ts/ts-drawing-components-circle.md)、[Ellipse](../reference/apis-arkui/arkui-ts/ts-drawing-components-ellipse.md)、[Polyline](../reference/apis-arkui/arkui-ts/ts-drawing-components-polyline.md)、[Polygon](../reference/apis-arkui/arkui-ts/ts-drawing-components-polygon.md)）组合完成。 |
| 使用Canvas组件实现高自由度的自定义绘制|如果高级组件的UI效果是非常复杂或者定制化的，例如存在图像或文本等内容，可通过[Canvas](arkts-drawing-customization-on-canvas.md)组件实现更自由的自定义绘制效果，其接口和W3C标准的Canvas接口相近，适用于移植基于W3C标准的Canvas的绘制库。 |
| 通过属性动画能力实现动画效果|可动画属性在[animation](./arkts-attribute-animation-apis.md)属性前调用，改变该属性的值，可以使`animation`属性的动画效果生效，比如`height`、`width`、`backgroundColor`等。[属性动画](./arkts-attribute-animation-apis.md)是最基础易懂的动画，针对不同的场景，根据需要做动画的属性的数量、动画参数的异同、动画的阶段数量，可以使用不同的动画接口完成对应的效果。 |
| 通过@AnimatableExtend装饰器实现动画效果|不可动画属性无法通过[属性动画](./arkts-attribute-animation-apis.md)实现动画效果。可通过[@AnimatableExtend](../ui/state-management/arkts-animatable-extend.md)装饰器实现动画效果，如果该属性是number类型，那只要将该属性放置在用`@AnimatableExtend`全局定义的方法里面，就可以将其转变为一个可接受`animation`控制的可动画属性；而对于非number类型的属性，可通过实现[AnimatableArithmetic](../ui/state-management/arkts-animatable-extend.md)的子类，实现`plus`、`subtract`、`multiply`、`equals`方法，然后就可以使用`@AnimatableExtend`装饰器实现动画效果。 |
| 通过@ohos.animator动画接口实现动画效果|更加灵活的是帧动画，通过[@ohos.animator](../reference/apis-arkui/js-apis-animator.md)动画接口实现逐帧方法回调，在回调中对节点的属性进行修改，或者结合自定义绘制的能力来调整绘制内容，可以实现帧动画的效果。 |

