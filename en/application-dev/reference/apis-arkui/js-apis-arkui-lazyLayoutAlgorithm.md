# LazyLayoutAlgorithm

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @rongShao-Z; @guozejun-->
<!--Designer: @yangcan18-->
<!--Tester: @leiyuqian-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=8d874d0ed3e2b14fedac21e9dc0520168c6abc51 translatedAt=2026-08-11T09:12:39.174Z pushedAt=2026-08-13T03:38:16.080Z -->

Provides the details about the lazy loading layout algorithms supported by the [LazyDynamicLayout](./arkui-ts/ts-container-lazydynamiclayout.md) component, helping you customize measurement and arrangement of child components, obtain visible area information, and control the active state of child components.

> **NOTE**
>
> The APIs of this module can be used only in the stage model.

**Since:** 26.0.0

## Modules to Import

```ts
import { LazyLayoutAlgorithm, LazyCustomLayoutAlgorithm, LazyLayoutHelper, LazyLayoutDirection } from '@kit.ArkUI';
```

## LazyLayoutAlgorithm

Basic layout algorithm type for the lazy loading dynamic layout container [LazyDynamicLayout](./arkui-ts/ts-container-lazydynamiclayout.md).

> **NOTE**
> This type of variable can be assigned a specific layout algorithm class object, such as an object of the [LazyCustomLayoutAlgorithm](#lazycustomlayoutalgorithm) class.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

## LazyLayoutDirection

Enumerates lazy loading layout directions.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

| Name | Value | Description |
| ---- | ---- | ---- |
| FORWARD | 0 | Forward direction, indicating that the current layout is from the start to the end of the content. |
| BACKWARD | 1 | Backward direction, indicating that the current layout is from the end to the start of the content. |

## LazyLayoutHelper

Lazy loading layout auxiliary class, which provides the layout direction and visible area position information.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

### getViewStart

getViewStart(): number

Obtains the start position of the visible area. It can be used together with [getViewEnd](#getviewend) to determine the visible area range for custom measurement.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type | Description |
| ---- | ---- |
| number | Start position of the visible area.<br>The unit is px. |

### getViewEnd

getViewEnd(): number

Obtains the end position of the visible area. It can be used together with [getViewStart](#getviewstart) to determine the visible area range for custom measurement.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type | Description |
| ---- | ---- |
| number | End position of the visible area.<br>The unit is px. |

### getLazyLayoutDirection

getLazyLayoutDirection(): LazyLayoutDirection

Obtains the lazy loading layout direction. This API can be used to determine whether to start layout from the beginning or end of the content in custom measurement.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type | Description |
| ---- | ---- |
| [LazyLayoutDirection](#lazylayoutdirection) | Lazy loading layout direction. |

### setAdjustedOffset

setAdjustedOffset(offset: number): void

Sets an adjusted offset for lazy loading.

When parameters such as the number of layout columns and spacing change, this API needs to be called to adjust the offset to keep the relative position of the first child component in the visible area unchanged.<br>Take the vertical layout as an example. When the layout direction is **LazyLayoutDirection.FORWARD**, the offset set by this API is the adjustment value of the upper boundary of the container. When the layout direction is **LazyLayoutDirection.BACKWARD**, the offset set by this API is the adjustment value of the lower boundary of the container.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type | Mandatory | Description |
| ---- | ---- | ---- | ---- |
| offset | number | Yes | Adjusted offset. A positive value indicates that the position is adjusted towards the end of the content, and a negative value indicates that the position is adjusted towards the start of the content. The unit is px. |

### setChildrenInactive

setChildrenInactive(children: number[]): void

Sets a child component to the inactive state.

If a child component is generated through [ForEach](./arkui-ts/ts-rendering-control-foreach.md) or [Repeat](./arkui-ts/ts-rendering-control-repeat.md) (with [virtualScroll](./arkui-ts/ts-rendering-control-repeat.md#virtualscroll) disabled), it will not be displayed after being set to the inactive state.<br>
If a child component is generated through [LazyForEach](./arkui-ts/ts-rendering-control-lazyforeach.md) or [Repeat](./arkui-ts/ts-rendering-control-repeat.md) (with [virtualScroll](./arkui-ts/ts-rendering-control-repeat.md#virtualscroll) enabled), it will be destroyed or recycled after being set to the inactive state.<br>
[LazyForEach](./arkui-ts/ts-rendering-control-lazyforeach.md) or [Repeat](./arkui-ts/ts-rendering-control-repeat.md) (with [virtualScroll](./arkui-ts/ts-rendering-control-repeat.md#virtualscroll) enabled) supports only consecutive active child components. Setting a child component to the inactive state between two active child components does not take effect.<br>
Child components outside the visible area are automatically set to the inactive state.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type | Mandatory | Description |
| ---- | ---- | ---- | ---- |
| children | number[] | Yes | Index array of child components to be set to the inactive state. An index must be a non-negative integer within the range [0, Total child components - 1]. The index outside this range does not take effect. |

## LazyCustomLayoutAlgorithm

A custom lazy loading layout algorithm class. It supports custom measurement and arrangement of child components by overriding [onMeasure](#onmeasure) and [onLayout](#onlayout).

> **NOTE**
>
> The object of the **LazyCustomLayoutAlgorithm** class can be used as the input parameter of the [LazyDynamicLayout](./arkui-ts/ts-container-lazydynamiclayout.md) component to specify a layout algorithm.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

### constructor

constructor(option?: LazyCustomLayoutAlgorithmOptions)

Constructor of the custom lazy loading layout algorithm class.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type | Mandatory | Description |
| ---- | ---- | ---- | ---- |
| option | [LazyCustomLayoutAlgorithmOptions](#lazycustomlayoutalgorithmoptions) | No | Input parameters for constructing the custom lazy loading layout algorithm, which are used to set the axis direction of the layout algorithm. This parameter needs to be passed when the main axis direction needs to be specified. If not passed, the main axis direction is **Axis.Vertical**. |

### onMeasure

onMeasure(self: FrameNode, constraint: LayoutConstraint, helper?: LazyLayoutHelper): void

Customizes the size of the child component to be measured. When the size of the lazy loading dynamic layout component is determined, the ArkUI framework will transfer the FrameNode, layout constraint, and lazy loading auxiliary object corresponding to the component to you through **onMeasure**. State variables should not be changed in this callback.

> **NOTE**
>
> - In this callback, you can call the [getChild()](js-apis-arkui-frameNode.md#getchild12) API of [FrameNode](js-apis-arkui-frameNode.md#framenode-1) to obtain the child component FrameNode and call the [measure()](js-apis-arkui-frameNode.md#measure12) API of [FrameNode](js-apis-arkui-frameNode.md#framenode-1) to measure the size of the child component. For details, see [Example 1: Implementing Lazy-Loading Custom Layout](./arkui-ts/ts-container-lazydynamiclayout.md#example-1-implementing-lazy-loading-custom-layout) of the **LazyDynamicLayout** component.
> - When calling [getChild()](js-apis-arkui-frameNode.md#getchild12) in this callback to obtain a child component, you must pass [ExpandMode.LAZY_NOT_EXPAND](js-apis-arkui-frameNode.md#expandmode15) to prevent lazy loading from becoming invalid due to full loading of child components. When calling [getChildrenCount()](js-apis-arkui-frameNode.md#getchildrencount12) to obtain the total number of child components, you must pass [ChildrenCountMode.ALL_NOT_EXPAND](js-apis-arkui-frameNode.md#childrencountmode) to prevent lazy loading from becoming invalid due to full loading of child components.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type | Mandatory | Description |
| ---- | ---- | ---- | ---- |
| self | [FrameNode](js-apis-arkui-frameNode.md#framenode-1) | Yes | Entity node of the lazy loading dynamic layout component in the component tree. |
| constraint | [LayoutConstraint](js-apis-arkui-frameNode.md#layoutconstraint12) | Yes | Layout constraint used when the lazy loading dynamic layout component is measured. |
| helper | [LazyLayoutHelper](#lazylayouthelper) | No | Lazy loading layout auxiliary object, which provides the layout direction and visible area position information. If the value is **undefined**, lazy loading is not supported. The value of **helper** is **undefined** in the following scenarios:<br>1. Lazy loading is not supported when the [WaterFlow](./arkui-ts/ts-container-waterflow.md) component uses the multi-column mode or uses the section mode with any section being in multi-column format.<br>2. Lazy loading is not supported when any of [lanes](./arkui-ts/ts-container-list.md#lanes9), [chainAnimation](./arkui-ts/ts-container-list.md#chainanimation), and [scrollSnapAlign](./arkui-ts/ts-container-list.md#scrollsnapalign10) is set for the [List](./arkui-ts/ts-container-list.md) component. |

### onLayout

onLayout(self: FrameNode, position: Position): void

Customizes the position of the child component to be arranged. When the position of the lazy loading dynamic layout component is determined, the ArkUI framework will transfer the FrameNode and layout position of the component to you through **onLayout**. State variables should not be changed in this callback.

> **NOTE**
>
> - In this callback, you can call the [getChild()](js-apis-arkui-frameNode.md#getchild12) API of [FrameNode](js-apis-arkui-frameNode.md#framenode-1) to obtain the child component FrameNode and call the [layout()](js-apis-arkui-frameNode.md#layout12) API of [FrameNode](js-apis-arkui-frameNode.md#framenode-1) to set the position of the child component. For details, see [Example 1: Implementing Lazy-Loading Custom Layout](./arkui-ts/ts-container-lazydynamiclayout.md#example-1-implementing-lazy-loading-custom-layout) of the **LazyDynamicLayout** component.
> - When calling [getChild()](js-apis-arkui-frameNode.md#getchild12) in this callback to obtain a child component, you must pass [ExpandMode.LAZY_NOT_EXPAND](js-apis-arkui-frameNode.md#expandmode15) to prevent lazy loading from becoming invalid due to full loading of child components. When calling [getChildrenCount()](js-apis-arkui-frameNode.md#getchildrencount12) to obtain the total number of child components, you must pass [ChildrenCountMode.ALL_NOT_EXPAND](js-apis-arkui-frameNode.md#childrencountmode) to prevent lazy loading from becoming invalid due to full loading of child components.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type | Mandatory | Description |
| ---- | ---- | ---- | ---- |
| self | [FrameNode](js-apis-arkui-frameNode.md#framenode-1) | Yes | Entity node of the lazy loading dynamic layout component in the component tree. |
| position | [Position](js-apis-arkui-graphics.md#position) | Yes | Position information used when the lazy loading dynamic layout component is laid out. |

**Example:**

For details, see [Example 1: Implementing Lazy-Loading Custom Layout](./arkui-ts/ts-container-lazydynamiclayout.md#example-1-implementing-lazy-loading-custom-layout) of the **LazyDynamicLayout** component.

## LazyCustomLayoutAlgorithmOptions

Input parameters for constructing the custom lazy loading layout algorithm, which are used to set the main axis direction of the layout algorithm.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

| Name | Type | Read-Only | Optional | Description |
| ---- | ---- | ---- | ---- | ---- |
| axis | [Axis](./arkui-ts/ts-appendix-enums.md#axis) | No | Yes | Main axis direction of the lazy loading layout. **Axis.Vertical** is used for the vertical layout of the main axis, and **Axis.Horizontal** is used for the horizontal layout of the main axis.<br/>Default value: **Axis.Vertical** |