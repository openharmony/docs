# Custom Composition
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @xiang-shouxing-->
<!--Designer: @xiang-shouxing-->
<!--Tester: @sally__-->
<!--Adviser: @HelloCrease-->

## Overview

Custom composition provides component-level customization capabilities, allowing you to create advanced components with service logic by combining existing components. During composition, you can: (1) Use layout containers and common layout attributes to arrange child component positions. (2) Utilize the **Canvas** component for pure custom drawing. (3) Employ the **Shape** component to construct geometric shapes through shape combinations for interactive graphics and animations. (4) Apply the animation module to create flexible animation effects across different attribute types.

## Basic Concepts

- Custom encapsulation: combining multiple basic components into a composite component with specific functionality.
- Custom layout: arranging child component positions and sizes based on service scenarios during composition.
- Custom drawing: combining various components to create advanced components with diverse drawing effects.
- Custom animation: defining components in different ways to achieve time-based changes in position, size, style, or drawing content.


## Typical Custom Composition Scenarios
|    Scenario     | Description    |
|---------------|-----------------------------------------|
| Using the @Component decorator to build custom components  | [@Component](../ui/state-management/arkts-create-custom-components.md#component) represents a typical custom encapsulation approach. You can assemble existing custom components and basic components to form new custom components. These components typically include internal member methods and state variables, for example, each video card in a video list, which contains its own video component, text component, click event, and redirection link.|
| Using the @Builder decorator to build reusable UI structures  |   Compared with the [@Component](../ui/state-management/arkts-create-custom-components.md#component) decorator, the [@Builder](../ui/state-management/arkts-builder.md) decorator is more lightweight. It encapsulates pure UI structures into methods, which can then be called in the **build** method of custom components to reuse UI structures. It extracts the build logic from @Component and does not contain state variables. |
| Using the Stack container for custom child component layout  | For scenarios with clear child components and simple structures, use stack layout. The [Stack](./arkts-layout-development-stack-layout.md) container, combined with common [size](../reference/apis-arkui/arkui-ts/ts-universal-attributes-size.md) and [location](../reference/apis-arkui/arkui-ts/ts-universal-attributes-location.md) attributes, controls child component layout. Child elements in the **Stack** component are stacked sequentially, with layering controlled by order, which is ideal for card stacking effects. |
| Implementing custom layout based on custom component layout lifecycle callbacks    |  For dynamically composed child components, use layout lifecycle callbacks to implement [custom component layout](../ui/state-management/arkts-page-custom-components-layout.md). Dynamically adjust child component sizes and positions as they change, forming specific layout algorithms. |
| Combining basic shapes for custom drawing effects|For advanced components with regular UI effects (basic shapes like rectangles, circles, polygons, or custom shapes composed of basic shapes), use basic shape components ([Rect](../reference/apis-arkui/arkui-ts/ts-drawing-components-rect.md), [Path](../reference/apis-arkui/arkui-ts/ts-drawing-components-path.md), [Circle](../reference/apis-arkui/arkui-ts/ts-drawing-components-circle.md), [Ellipse](../reference/apis-arkui/arkui-ts/ts-drawing-components-ellipse.md), [Polyline](../reference/apis-arkui/arkui-ts/ts-drawing-components-polyline.md), [Polygon](../reference/apis-arkui/arkui-ts/ts-drawing-components-polygon.md)) to achieve UI effects.|
| Using the **Canvas** component for custom drawing|For complex or highly customized UI effects (for example, image or text display), use the [Canvas](arkts-drawing-customization-on-canvas.md) component. The **Canvas** component is similar to W3C standard **Canvas** component and is suitable for porting W3C-based drawing libraries.|
| Using the property animation capability for animation effects|Apply property animation capabilities before the [animation](./arkts-attribute-animation-apis.md) property to change values of animatable properties, such as **height**, **width**, and **backgroundColor**. Property animation effects then take effect. [Property animation](./arkts-attribute-animation-apis.md) is the most basic and intuitive type of animation. You can select different animation APIs to achieve the desired effect based on factors like the number of animated properties, differences in animation parameters, and the number of animation phases in different scenarios.|
| Using the @AnimatableExtend decorator for animation effects|For non-animatable attributes, use the [@AnimatableExtend](../ui/state-management/arkts-animatable-extend.md) decorator. For numeric attributes, simply place them in globally defined @AnimatableExtend methods to make them animatable. For non-numeric attributes, implement **plus**, **subtract**, **multiply**, and **equals** APIs by creating a child class of [AnimatableArithmetic](../ui/state-management/arkts-animatable-extend.md), then use @AnimatableExtend for animation effects.|
| Using the @ohos.animator animation API for animation effects|For more flexible frame animation, use the [@ohos.animator](../reference/apis-arkui/js-apis-animator.md) animation API to implement frame-by-frame callbacks. Modify node attributes or adjust drawing content based on custom drawing capabilities within callbacks to achieve frame animation effects.|
