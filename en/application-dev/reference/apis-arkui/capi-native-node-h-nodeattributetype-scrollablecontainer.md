# ArkUI_NodeAttributeType (Scrollable Container Component Attribute)
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @shengu_lancer; @yylong; @yangcan18-->
<!--Designer: @yylong;@guozejun-->
<!--Tester: @leiyuqian-->
<!--Adviser: @Brilliantry_Rui-->

```c
enum ArkUI_NodeAttributeType
```

## Overview

Enumerates the attribute types that can be set by ArkUI on the native side for scrollable container components including the **Scroll**, **List**, **ListItem**, **ListItemGroup**, **Refresh**, **WaterFlow**, **Grid**, and **GridItem** components.

**Since**: 12

**Related module**: [ArkUI_NativeModule](capi-arkui-nativemodule.md)

**Header file**: [native_node.h](capi-native-node-h.md)

## NODE_SCROLL_BAR_DISPLAY_MODE

```c
NODE_SCROLL_BAR_DISPLAY_MODE = MAX_NODE_SCOPE_NUM * ARKUI_NODE_SCROLL = 1002000
```

Scrollbar display mode. This attribute can be set, reset, and obtained as required through APIs. [List](arkui-ts/ts-container-list.md), [Scroll](arkui-ts/ts-container-scroll.md), and [WaterFlow](arkui-ts/ts-container-waterflow.md) support this attribute since API version 12, and [Grid](arkui-ts/ts-container-grid.md) supports this attribute since API version 22.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| .value[0].i32 | Scrollbar display mode. The parameter type is [ArkUI_ScrollBarDisplayMode](capi-native-type-h.md#arkui_scrollbardisplaymode). The default value is [ARKUI_SCROLL_BAR_DISPLAY_MODE_AUTO](capi-native-type-h.md#arkui_scrollbardisplaymode) for **List** and **Grid**, and [ARKUI_SCROLL_BAR_DISPLAY_MODE_OFF](capi-native-type-h.md#arkui_scrollbardisplaymode) for **WaterFlow**.|

**Returns**

| Type| Description|
| -- | -- |
| .value[0].i32 | Scrollbar display mode. The parameter type is [ArkUI_ScrollBarDisplayMode](capi-native-type-h.md#arkui_scrollbardisplaymode).|

## NODE_SCROLL_BAR_WIDTH

```c
NODE_SCROLL_BAR_WIDTH = 1002001
```

Width of the scrollbar. This attribute can be set, reset, and obtained as required through APIs. [List](arkui-ts/ts-container-list.md), [Scroll](arkui-ts/ts-container-scroll.md), and [WaterFlow](arkui-ts/ts-container-waterflow.md) support this attribute since API version 12, and [Grid](arkui-ts/ts-container-grid.md) supports this attribute since API version 22.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| .value[0].f32 | Width of the scrollbar, in vp. The default value is **4**.<br>If this parameter is set to a value less than or equal to 0, the default value is used. The value **0** means not to show the scrollbar.|

**Returns**

| Type| Description|
| -- | -- |
| .value[0].f32 | Width of the scrollbar, in vp.|

## NODE_SCROLL_BAR_COLOR

```c
NODE_SCROLL_BAR_COLOR = 1002002
```

Color of the scrollbar. This attribute can be set, reset, and obtained as required through APIs. [List](arkui-ts/ts-container-list.md), [Scroll](arkui-ts/ts-container-scroll.md), and [WaterFlow](arkui-ts/ts-container-waterflow.md) support this attribute since API version 12, and [Grid](arkui-ts/ts-container-grid.md) supports this attribute since API version 22.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| .data[0].u32 | Color of the scrollbar, in 0xARGB format. The default value is **0x66182431**.|

**Returns**

| Type| Description|
| -- | -- |
| .data[0].u32 | Color of the scrollbar, in 0xARGB format.|

## NODE_SCROLL_SCROLL_DIRECTION

```c
NODE_SCROLL_SCROLL_DIRECTION = 1002003
```

Scroll direction. This attribute can be set, reset, and obtained as required through APIs.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| .value[0].i32 | Scroll direction. The parameter type is [ArkUI_ScrollDirection](capi-native-type-h.md#arkui_scrolldirection). The default value is [ARKUI_SCROLL_DIRECTION_VERTICAL](capi-native-type-h.md#arkui_scrolldirection).|

**Returns**

| Type| Description|
| -- | -- |
| .value[0].i32 | Scroll direction. The parameter type is [ArkUI_ScrollDirection](capi-native-type-h.md#arkui_scrolldirection).|

## NODE_SCROLL_EDGE_EFFECT

```c
NODE_SCROLL_EDGE_EFFECT = 1002004
```

Effect used at the edges of the component when the boundary of the scrollable content is reached. This attribute can be set, reset, and obtained as required through APIs.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| .value[0].i32 | Effect used at the edges of the component when the boundary of the scrollable content is reached. The parameter type is [ArkUI_EdgeEffect](capi-native-type-h.md#arkui_edgeeffect). The default value is [ARKUI_EDGE_EFFECT_NONE](capi-native-type-h.md#arkui_edgeeffect) for **Grid**, **Scroll** and **WaterFlow**, and [ARKUI_EDGE_EFFECT_SPRING](capi-native-type-h.md#arkui_edgeeffect) for **List**.|
| .value[1]?.i32 | Whether to enable the scroll effect when the component content size is smaller than the component itself. This parameter is optional. The value **1** means to enable the scroll effect, and **0** means the opposite. The default value is **0** for **List**, **Grid**, and **WaterFlow**, and **1** for **Scroll**.|
| .value[2]?.i32 | Direction where the edge effect takes effect. The parameter type is [ArkUI_EffectEdge](capi-native-type-h.md#arkui_effectedge). The default value is [ARKUI_EFFECT_EDGE_START](capi-native-type-h.md#arkui_effectedge)  \| [ARKUI_EFFECT_EDGE_END](capi-native-type-h.md#arkui_effectedge).<br> This parameter is supported since API version 18.|

**Returns**

| Type| Description|
| -- | -- |
| .value[0].i32 | Effect used at the edges of the component when the boundary of the scrollable content is reached. The parameter type is [ArkUI_EdgeEffect](capi-native-type-h.md#arkui_edgeeffect).|
| .value[1].i32 | Whether the scroll effect is enabled when the component content size is smaller than the component itself. The value **1** indicates that the scroll effect is enabled, and **0** indicates the opposite.|
| .value[2].i32 | Direction where the edge effect takes effect. The parameter type is [ArkUI_EffectEdge](capi-native-type-h.md#arkui_effectedge). This parameter is supported since API version 18.|

## NODE_SCROLL_ENABLE_SCROLL_INTERACTION

```c
NODE_SCROLL_ENABLE_SCROLL_INTERACTION = 1002005
```

Whether to support scroll gestures. When this attribute is set to **0**, scrolling by finger or mouse is not supported, but the scrolling controller API is not affected.<br>The **List**, **Scroll**, and **WaterFlow** components support this attribute since API version 12, and the **Grid** component supports this attribute since API version 22.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| .value[0].i32 | Whether to support scroll gestures. The default value is **1**. The value **1** means to support, and **0** means the opposite.|

**Returns**

| Type| Description|
| -- | -- |
| .value[0].i32 | Whether scroll gestures are supported.|

## NODE_SCROLL_FRICTION

```c
NODE_SCROLL_FRICTION = 1002006
```

Friction coefficient. It applies only to gestures in the scrolling area, and it affects only indirectly the scroll chaining during the inertial scrolling process.<br>The **List**, **Scroll**, and **WaterFlow** components support this attribute since API version 12, and the **Grid** component supports this attribute since API version 22.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| .value[0].f32 | Friction coefficient. The default value is **0.6** for non-wearable devices and **0.9** for wearable devices. Value range: (0, +∞). If this parameter is set to a value less than or equal to 0, the default value is used.|

**Returns**

| Type| Description|
| -- | -- |
| .value[0].f32 | Friction coefficient.|

## NODE_SCROLL_SNAP

```c
NODE_SCROLL_SNAP = 1002007
```

Scroll snapping mode of the [Scroll](arkui-ts/ts-container-scroll.md) component. This attribute can be set, reset, and obtained as required through APIs.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| .value[0].i32 | Alignment mode for scroll snapping in the **Scroll** component. The parameter type is [ArkUI_ScrollSnapAlign](capi-native-type-h.md#arkui_scrollsnapalign). The default value is [ARKUI_SCROLL_SNAP_ALIGN_NONE](capi-native-type-h.md#arkui_scrollsnapalign).|
| .value[1].i32 | Whether to enable the snap to start feature. When scroll snapping is defined for the **Scroll** component, setting this attribute to **false** enables the component to scroll between the start edge and the first snap point. The default value is **true**. It is valid only when there are multiple snap points.|
| .value[2].i32 | Whether to enable the snap to end feature. When scroll snapping is defined for the **Scroll** component, setting this attribute to **false** enables the component to scroll between the end edge and the last snap point. The default value is **true**. It is valid only when there are multiple snap points.|
| .value[3...].f32 | Snap points for the **Scroll** component. Each snap point defines the offset from an edge to which the **Scroll** component can scroll. One or more snap points are supported.|

**Returns**

| Type| Description|
| -- | -- |
| .value[0].i32 | Alignment mode for scroll snapping in the **Scroll** component. The parameter type is [ArkUI_ScrollSnapAlign](capi-native-type-h.md#arkui_scrollsnapalign).|
| .value[1].i32 | Whether the snap to start feature is enabled. When scroll snapping is defined for the **Scroll** component, setting this attribute to **false** enables the component to scroll between the start edge and the first snap point. The default value is **true**. It is valid only when there are multiple snap points.|
| .value[2].i32 | Whether the snap to end feature is enabled. When scroll snapping is defined for the **Scroll** component, setting this attribute to **false** enables the component to scroll between the end edge and the last snap point. The default value is **true**. It is valid only when there are multiple snap points.|
| .value[3...].f32 | Snap points for the **Scroll** component. Each snap point defines the offset from an edge to which the **Scroll** component can scroll.|

## NODE_SCROLL_NESTED_SCROLL

```c
NODE_SCROLL_NESTED_SCROLL = 1002008
```

Nested scrolling attribute, which can be set, reset, and obtained as required through APIs. The **List**, **Scroll**, and **WaterFlow** components support this attribute since API version 12, and the **Grid** component supports this attribute since API version 22.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| .value[0].i32 | Nested scrolling behavior when the scrollable component scrolls toward the end edge. The parameter type is [ArkUI_ScrollNestedMode](capi-native-type-h.md#arkui_scrollnestedmode).|
| .value[1].i32 | Nested scrolling behavior when the scrollable component scrolls toward the start edge. The parameter type is [ArkUI_ScrollNestedMode](capi-native-type-h.md#arkui_scrollnestedmode).|

**Returns**

| Type| Description|
| -- | -- |
| .value[0].i32 | Nested scrolling behavior when the scrollable component scrolls toward the end edge. The parameter type is [ArkUI_ScrollNestedMode](capi-native-type-h.md#arkui_scrollnestedmode).|
| .value[1].i32 | Nested scrolling behavior when the scrollable component scrolls toward the start edge. The parameter type is [ArkUI_ScrollNestedMode](capi-native-type-h.md#arkui_scrollnestedmode).|

## NODE_SCROLL_OFFSET

```c
NODE_SCROLL_OFFSET = 1002009
```

Position to scroll to for the [Scroll](../apis-arkui/arkui-ts/ts-container-scroll.md) component. This attribute can be set, reset, and obtained as required through APIs.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| .value[0].f32 | Horizontal scrolling offset, in vp. Value range: If the value is less than 0, the offset will be 0 for non-animated scrolling. A value greater than 0 indicates scrolling with animation. By default, the scrolling stops when it reaches the start position. You can set the **animation** parameter in **ScrollOptions** to enable a bounce effect when the scroll exceeds the content bounds.|
| .value[1].f32 | Vertical scrolling offset, in vp. Value range: If the value is less than 0, the offset will be 0 for non-animated scrolling. A value greater than 0 indicates scrolling with animation. By default, the scrolling stops when it reaches the start position. You can set the **animation** parameter to enable a bounce effect when the scroll exceeds the content bounds.|
| .value[2]?.i32 | Scrolling duration, in milliseconds. The default value is **1000**. This parameter is optional.|
| .value[3]?.i32 | Scrolling curve. The parameter type is [ArkUI_AnimationCurve](capi-native-type-visual-h.md#arkui_animationcurve). This parameter is optional. The default value is [ARKUI_CURVE_EASE](capi-native-type-visual-h.md#arkui_animationcurve).|
| .value[4]?.i32 | Whether to enable the default spring animation. This parameter is optional. The default value is **0**, indicating not to enable the default spring animation.|
| .value[5]?.i32 | Whether to convert the scroll animation to an overshoot animation when the boundary is reached. The default value is **0**, meaning not to convert the scroll animation to an overshoot animation when the boundary is reached. This parameter is optional.|
| .value[6]?.i32 | Whether the component can stop at an overscrolled position. The default value is **0**, meaning that the component cannot stop at an overscrolled position. This parameter is optional. This parameter is supported since API version 20.|

**Returns**

| Type| Description|
| -- | -- |
| .value[0].f32 | Horizontal scrolling offset, in vp.|
| .value[1].f32 | Vertical scrolling offset, in vp.|

## NODE_SCROLL_EDGE

```c
NODE_SCROLL_EDGE = 1002010
```

Edge position to scroll to for the [Scroll](./apis-arkui/arkui-ts/ts-container-scroll.md) component. This attribute can be set and obtained as required through APIs.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| .value[0].i32 | Edge position to scroll to. The parameter type is [ArkUI_ScrollEdge](capi-native-type-h.md#arkui_scrolledge).|

**Returns**

| Type| Description|
| -- | -- |
| .value[0].i32 | Whether the container is at the edge. The value **-1** indicates that the container is not at the edge. If the container is at the edge, the parameter type is [ArkUI_ScrollEdge](capi-native-type-h.md#arkui_scrolledge).|

## NODE_SCROLL_ENABLE_PAGING

```c
NODE_SCROLL_ENABLE_PAGING = 1002011
```

Whether to enable the swipe-to-turn-pages feature. This attribute can be set, reset, and obtained as required through APIs. If both [enablePaging](../apis-arkui/arkui-ts/ts-container-scroll.md#enablepaging11) and [scrollSnap](../apis-arkui/arkui-ts/ts-container-scroll.md#scrollsnap10) are set, [scrollSnap](../apis-arkui/arkui-ts/ts-container-scroll.md#scrollsnap10) takes effect preferentially, and [enablePaging](../apis-arkui/arkui-ts/ts-container-scroll.md#enablepaging11) does not take effect.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| .value[0].i32 | Whether to enable the swipe-to-turn-pages feature. The default value is **0**. **0**: disable; **1**: enable.|

**Returns**

| Type| Description|
| -- | -- |
| .value[0].i32 | Whether the swipe-to-turn-pages feature is enabled. **0**: The swipe-to-turn-pages feature is disabled; **1**: The swipe-to-turn-pages feature is enabled.|

## NODE_SCROLL_PAGE

```c
NODE_SCROLL_PAGE = 1002012
```

Scrolls to the next or previous page.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute is as follows.<br>

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| .value[0].i32 | Whether to scroll to the next page. The value **0** means to scroll to the next page, and **1** means to scroll to the previous page.|
| .value[1]?.i32 | Whether to enable the page-turning animation. The value **1** means to enable the page turning animation, and **0** means the opposite. The default value is **0**.|

## NODE_SCROLL_BY

```c
NODE_SCROLL_BY = 1002013
```

Scrolling distance. The **List**, **Scroll**, and **WaterFlow** components support this attribute since API version 12. The **Grid** component supports this attribute since API version 26.0.0.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute is as follows.<br>

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| .value[0].f32 | Horizontal scrolling distance, in vp by default.|
| .value[1].f32 | Vertical scrolling distance, in vp by default.|

## NODE_SCROLL_FLING

```c
NODE_SCROLL_FLING = 1002014
```

Performs inertial scrolling based on the initial velocity passed in.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute is as follows.<br>

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| .value[0].f32 | Initial velocity of inertial scrolling. The default unit is vp/s. If the value specified is 0, it is considered as invalid, and the scrolling for this instance will not take effect. If the value is positive, the scroll will move downward; if the value is negative, the scroll will move upward.|

## NODE_SCROLL_FADING_EDGE

```c
NODE_SCROLL_FADING_EDGE = 1002015
```

Edge fade effect for the scrollable component.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 14


**Parameters**

| Name| Description|
| -- | -- |
| .value[0].i32 | Whether to enable the edge fade effect. **0**: Disable the edge fade effect. **1**: Enable the edge fade effect. The default value is **0**.|
| .value[1]?.f32 | Length of the edge fade effect. The unit is vp. The default value is **32**.|

**Returns**

| Type| Description|
| -- | -- |
| .value[0].i32 | Whether the edge fade effect is enabled. **0**: The edge fade effect is disabled. **1**: The edge fade effect is enabled.|
| .value[1].f32 | Length of the edge fade effect. The unit is vp.|

## NODE_SCROLL_SIZE

```c
NODE_SCROLL_SIZE = 1002016
```

Total size of all child components when fully expanded in the scrollable component.<br>
The format of the return value [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) is as follows.<br>

**Since**: 14


**Returns**

| Type| Description|
| -- | -- |
| .value[0].f32 | Total width of all child components when fully expanded in the scrollable component. The default unit is vp.|
| .value[1].f32 | Total height of all child components when fully expanded in the scrollable component. The default unit is vp.<br>When **NODE_PADDING**, **NODE_MARGIN**, or **NODE_BORDER_WIDTH** is set, the values are rounded to the nearest pixel when being converted from vp to px. The return values are calculated based on these rounded pixel values.|

## NODE_SCROLL_CONTENT_START_OFFSET

```c
NODE_SCROLL_CONTENT_START_OFFSET = 1002017
```

Offset from the start of the content of the scrollable component. [List](arkui-ts/ts-container-list.md) supports this attribute since API version 15, and [Grid](arkui-ts/ts-container-grid.md), [Scroll](arkui-ts/ts-container-scroll.md), and [WaterFlow](arkui-ts/ts-container-waterflow.md) support this attribute since API version 22.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| .value[0].f32 | Offset from the start of the content, in vp.|

**Returns**

| Type| Description|
| -- | -- |
| .value[0].f32 | Offset from the start of the content, in vp.|

## NODE_SCROLL_CONTENT_END_OFFSET

```c
NODE_SCROLL_CONTENT_END_OFFSET = 1002018
```

Offset from the end of the content of the scrollable component. [List](arkui-ts/ts-container-list.md) supports this attribute since API version 15, and [Grid](arkui-ts/ts-container-grid.md), [Scroll](arkui-ts/ts-container-scroll.md), and [WaterFlow](arkui-ts/ts-container-waterflow.md) support this attribute since API version 22.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| .value[0].f32 | Offset from the end of the content, in vp.|

**Returns**

| Type| Description|
| -- | -- |
| .value[0].f32 | Offset from the end of the content, in vp.|

## NODE_SCROLL_FLING_SPEED_LIMIT

```c
NODE_SCROLL_FLING_SPEED_LIMIT = 1002019
```

Maximum initial velocity at the start of the fling animation that occurs after gesture-driven scrolling ends. This attribute can be set, reset, and obtained as required through APIs.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| .value[0].f32 | Maximum initial velocity at the start of the fling animation, in vp/s.|

**Returns**

| Type| Description|
| -- | -- |
| .value[0].f32 | Maximum initial velocity at the start of the fling animation.|

## NODE_SCROLL_CLIP_CONTENT

```c
NODE_SCROLL_CLIP_CONTENT = 1002020
```

Content clipping area for the scrollable component. This attribute can be set, reset, and obtained as required through APIs.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| .value[0].i32 | Content clipping mode. The parameter type is [ArkUI_ContentClipMode](capi-native-type-h.md#arkui_contentclipmode). The default value is [ARKUI_CONTENT_CLIP_MODE_BOUNDARY](capi-native-type-h.md#arkui_contentclipmode) for [Grid](arkui-ts/ts-container-grid.md) and [Scroll](arkui-ts/ts-container-scroll.md), and [ARKUI_CONTENT_CLIP_MODE_CONTENT_ONLY](capi-native-type-h.md#arkui_contentclipmode) for [List](arkui-ts/ts-container-list.md) and [WaterFlow](arkui-ts/ts-container-waterflow.md).|

**Returns**

| Type| Description|
| -- | -- |
| .value[0].i32 | Content clipping mode. The parameter type is [ArkUI_ContentClipMode](capi-native-type-h.md#arkui_contentclipmode).|

## NODE_SCROLL_BACK_TO_TOP

```c
NODE_SCROLL_BACK_TO_TOP = 1002021
```

Whether to scroll back to the top when the status bar is clicked for the scrollable component. This attribute can be set, reset, and obtained as required through APIs.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| .value[0].i32 | Whether to scroll back to the top. The value **1** means to scroll back to the top, and **0** means to stay at the current position. The default value is 0 for API versions earlier than 18. The default value for API version 18 and later is as follows: **0** for the horizontal scroll direction, and **1** for the vertical scroll direction.|

**Returns**

| Type| Description|
| -- | -- |
| .value[0].i32 | Whether scrolling back to the top is supported.|

## NODE_SCROLL_BAR_MARGIN

```c
NODE_SCROLL_BAR_MARGIN = 1002022
```

Margin of the scrollbar. This attribute can be set, reset, and obtained as required through APIs.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| .value[0].f32 | Start margin of the scrollbar, in vp. The default value is **0**.|
| .value[1].f32 | End margin of the scrollbar, in vp. The default value is **0**.|

**Returns**

| Type| Description|
| -- | -- |
| .value[0].f32 | Start margin of the scrollbar, in vp.|
| .value[1].f32 | End margin of the scrollbar, in vp.|

## NODE_SCROLL_MAX_ZOOM_SCALE

```c
NODE_SCROLL_MAX_ZOOM_SCALE = 1002023
```

Maximum zoom scale for scrollable content.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| .value[0].f32 | Maximum zoom scale for scrollable content. The default value is **1**.<br>Value range: (0, +∞). If the value is less than or equal to 0, the default value is used.|

**Returns**

| Type| Description|
| -- | -- |
| .value[0].f32 | Maximum zoom scale for scrollable content.|

## NODE_SCROLL_MIN_ZOOM_SCALE

```c
NODE_SCROLL_MIN_ZOOM_SCALE = 1002024
```

Minimum zoom scale for scrollable content.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| .value[0].f32 | Minimum zoom scale for scrollable content. The default value is **1**.<br>Value range: (0, NODE_SCROLL_MAX_ZOOM_SCALE]. If the value is less than or equal to 0, the default value **1** is used. If the value is greater than **NODE_SCROLL_MAX_ZOOM_SCALE**, **NODE_SCROLL_MAX_ZOOM_SCALE** is used.|

**Returns**

| Type| Description|
| -- | -- |
| .value[0].f32 | Minimum zoom scale for scrollable content.|

## NODE_SCROLL_ZOOM_SCALE

```c
NODE_SCROLL_ZOOM_SCALE = 1002025
```

Zoom scale for scrollable content.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| .value[0].f32 | Zoom scale for scrollable content. The default value is **1**.<br>Value range: (0, +∞). If the value is less than or equal to 0, the default value is used.|

**Returns**

| Type| Description|
| -- | -- |
| .value[0].f32 | Zoom scale for scrollable content.|

## NODE_SCROLL_ENABLE_BOUNCES_ZOOM

```c
NODE_SCROLL_ENABLE_BOUNCES_ZOOM = 1002026
```

Whether to enable the zoom bounce effect when the scaling exceeds the limits.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| .value[0].i32 | Whether to enable the zoom bounce effect when the scaling exceeds the limits. The value **1** means to enable the effect, and **0** means the opposite. The default value is **1**.|

**Returns**

| Type| Description|
| -- | -- |
| .value[0].i32 | Whether the zoom bounce effect is enabled when the scaling exceeds the limits. The value **1** means that the effect is enabled, and **0** means the opposite.|

## NODE_SCROLL_ENABLE_SCROLL_WITH_MOUSE

```c
NODE_SCROLL_ENABLE_SCROLL_WITH_MOUSE = 1002027
```

Whether to support scroll using the left button on the mouse. This attribute can be set, reset, and obtained as required through APIs.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 26.0.0


**Parameters**

| Name       | Description                                                        |
| ------------- | ------------------------------------------------------------ |
| .value[0].i32 | Whether to support scroll using the left button on the mouse. The value **1** indicates to support, and **0** indicates the opposite. The default value is **0**.|

**Returns**

| Type         | Description                                                        |
| ------------- | ------------------------------------------------------------ |
| .value[0].i32 | Whether scroll using the left button on the mouse is supported. The value **1** indicates scroll using the left button on the mouse is supported, and **0** indicates the opposite.|

## NODE_SCROLL_AUTO_ADJUST_MARGIN

```c
NODE_SCROLL_AUTO_ADJUST_MARGIN = 1002028
```

Whether the scrollbar automatically adjusts its margin to avoid the area of the **NODE_PADDING**, **NODE_SCROLL_CONTENT_START_OFFSET**, or **NODE_SCROLL_CONTENT_END_OFFSET** component. This attribute can be set, reset, and obtained as required through APIs.<br>

The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| .value[0].i32 | Whether the scrollbar automatically adjusts its margin. The value **0** indicates that the scrollbar automatically adjusts its margin, and **1** indicates the opposite. The default value is **0**.|

**Returns**

| Type| Description|
| -- | -- |
| .value[0].i32 | Whether the scrollbar automatically adjusts its margin. The value **0** indicates that the scrollbar automatically adjusts its margin, and **1** indicates the opposite.|


## NODE_SCROLL_BAR_HEIGHT

```c
NODE_SCROLL_BAR_HEIGHT = 1002029
```

Scrollbar height. This attribute can be set, reset, and obtained as required through APIs.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| .value[0].f32 | Scrollbar height, in vp. Default value: auto-adjusted height of the scroll component.<br>Value range: The value must be greater than or equal to 0. If the value is less than 0, the default value is used. For kids' smartwatches, the default value is restored to 37 vp. The value **0** means not to show the scrollbar.|

**Returns**

| Type| Description|
| -- | -- |
| .value[0].f32 | Scrollbar height, in vp.|

## NODE_LIST_DIRECTION

```c
NODE_LIST_DIRECTION = MAX_NODE_SCOPE_NUM * ARKUI_NODE_LIST = 1003000
```

Direction in which the [list](arkui-ts/ts-container-list.md) items are arranged. This attribute can be set, reset, and obtained as required through APIs.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| .value[0].i32 | Direction in which the list items are arranged. The parameter type is [ArkUI_Axis](capi-native-type-h.md#arkui_axis). The default value is **ARKUI_AXIS_VERTICAL**.|

**Returns**

| Type| Description|
| -- | -- |
| .value[0].i32 | Direction in which the list items are arranged. The parameter type is [ArkUI_Axis](capi-native-type-h.md#arkui_axis).|

## NODE_LIST_STICKY

```c
NODE_LIST_STICKY = 1003001
```

Whether to pin the header to the top or the footer to the bottom in the [ListItemGroup](arkui-ts/ts-container-listitemgroup.md) component. It is used together with the **ListItemGroup** component. This attribute can be set, reset, and obtained as required through APIs.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| .value[0].i32 | Whether to pin the header to the top or the footer to the bottom in the **ListItemGroup** component. It is used together with the **ListItemGroup** component. The parameter type is [ArkUI_StickyStyle](capi-native-type-h.md#arkui_stickystyle). The default value is **ARKUI_STICKY_STYLE_NONE**.|

**Returns**

| Type| Description|
| -- | -- |
| .value[0].i32 | Whether the header is pinned to the top or the footer to the bottom in the **ListItemGroup** component. It is used together with the **ListItemGroup** component. The parameter type is [ArkUI_StickyStyle](capi-native-type-h.md#arkui_stickystyle).|

## NODE_LIST_SPACE

```c
NODE_LIST_SPACE = 1003002
```

Spacing between list items. This attribute can be set, reset, and obtained as required through APIs.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| .value[0].f32 | Spacing between list items along the main axis. The default value is **0**.|

**Returns**

| Type| Description|
| -- | -- |
| .value[0].f32 | Spacing between list items along the main axis.|

## NODE_LIST_NODE_ADAPTER

```c
NODE_LIST_NODE_ADAPTER = 1003003
```

Adapter of the **List** component. This attribute can be set, reset, and obtained as required through APIs.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| .object | [ArkUI_NodeAdapter](capi-arkui-nativemodule-arkui-nodeadapter8h.md) object used as the adapter.|

**Returns**

| Type| Description|
| -- | -- |
| .object | [ArkUI_NodeAdapter](capi-arkui-nativemodule-arkui-nodeadapter8h.md) object.|

## NODE_LIST_CACHED_COUNT

```c
NODE_LIST_CACHED_COUNT = 1003004
```

Number of cached items in the adapter of the **List** component. This attribute can be set, reset, and obtained as required through APIs.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| .value[0].i32 | Number of cached items in the **List** component's adapter.|
| .value[1]?.i32 | Whether to show cached items. The value **0** means to hide cached items, and **1** means to show cached items. The default value is **0**. This parameter is supported since API version 15.|
| .value[2]?.i32 | Maximum number of cached items in the **List** component. The default value is the same as that of the first parameter. This parameter is supported since API version 22.|

**Returns**

| Type| Description|
| -- | -- |
| .value[0].i32 | Number of cached items in the adapter.|
| .value[1].i32 | Whether cached items are shown. The value **0** means that cached items are hidden, and **1** means that cached items are shown. This parameter is supported since API version 15.|
| .value[2]?.i32 | Maximum number of cached items in the **List** component. This parameter is supported since API version 22.|

## NODE_LIST_SCROLL_TO_INDEX

```c
NODE_LIST_SCROLL_TO_INDEX = 1003005
```

Scrolls to the item with the specified index. When **smooth** is set to **true**, all passed items are loaded and counted in layout calculation. This may result in performance issues if a large number of items are involved.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute is as follows.<br>

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| .value[0].i32 | Index of the item to be scrolled to in the container. If the value is **-1**, the last item in the container is scrolled to.|
| .value[1]?.i32 | Whether to enable the smooth animation for scrolling to the item with the specified index. The value **1** means to enable the smooth animation, and **0** means the opposite. The default value is **0**.|
| .value[2]?.i32 | How the item to scroll to is aligned with the container. The parameter type is [ArkUI_ScrollAlignment](capi-native-type-h.md#arkui_scrollalignment). The default value is [ARKUI_SCROLL_ALIGNMENT_START](capi-native-type-h.md#arkui_scrollalignment).|
| .value[3]?.f32 | Extra offset, in vp. The default value is **0**. This parameter is supported since API version 15.|

## NODE_LIST_ALIGN_LIST_ITEM

```c
NODE_LIST_ALIGN_LIST_ITEM = 1003006
```

Alignment mode of list items along the cross axis when the cross-axis width of the list is greater than the cross-axis width of list items multiplied by the value of lanes. This attribute can be set, reset, and obtained as required through APIs.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| .value[0].i32 | Alignment mode of list items along the cross axis. The parameter type is [ArkUI_ListItemAlign](capi-native-type-h.md#arkui_listitemalignment). The default value is **ARKUI_LIST_ITEM_ALIGNMENT_START**.|

**Returns**

| Type| Description|
| -- | -- |
| .value[0].i32 | Alignment mode of list items along the cross axis. The parameter type is [ArkUI_ListItemAlign](capi-native-type-h.md#arkui_listitemalignment).|

## NODE_LIST_CHILDREN_MAIN_SIZE

```c
NODE_LIST_CHILDREN_MAIN_SIZE = 1003007
```

Default main axis size of the child component in **List**.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| .object | The parameter type is [ArkUI_ListChildrenMainSize](capi-arkui-nativemodule-arkui-listchildrenmainsize.md).|

**Returns**

| Type| Description|
| -- | -- |
| .object | The parameter type is [ArkUI_ListChildrenMainSize](capi-arkui-nativemodule-arkui-listchildrenmainsize.md).|

## NODE_LIST_INITIAL_INDEX

```c
NODE_LIST_INITIAL_INDEX = 1003008
```

Index of the item displayed at the beginning of the viewport when the current list is loaded for the first time. This attribute can be set, reset, and obtained as required through APIs.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| .value[0].i32 | Index of the item displayed at the beginning of the viewport when the current list is loaded for the first time. The default value is **0**.|

**Returns**

| Type| Description|
| -- | -- |
| .value[0].i32 | Index of the item displayed at the beginning of the viewport when the current list is loaded for the first time.|

## NODE_LIST_DIVIDER

```c
NODE_LIST_DIVIDER = 1003009
```

Style of the divider for the list items. This attribute can be set, reset, and obtained as required through APIs.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| .value[0].u32 | Color of the divider, in 0xARGB format. The default value is **0x08000000**.|
| .value[1].f32 | Stroke width of the divider, in vp. The default value is **0**.|
| .value[2].f32 | Distance between the divider and the start of the list, in vp. The default value is **0**.|
| .value[3].f32 | Distance between the divider and the end of the list, in vp. The default value is **0**.|

**Returns**

| Type| Description|
| -- | -- |
| .value[0].u32 | Color of the divider, in 0xARGB format.|
| .value[1].f32 | Stroke width of the divider.|
| .value[2].f32 | Distance between the divider and the start of the list, in vp.|
| .value[3].f32 | Distance between the divider and the end of the list, in vp.|

## NODE_LIST_SCROLL_TO_INDEX_IN_GROUP

```c
NODE_LIST_SCROLL_TO_INDEX_IN_GROUP = 1003010
```

Scrolls to the item with the specified index in the specified [list item group](./arkui-ts/ts-container-listitemgroup.md). When **smooth** is set to **true**, all passed items are loaded and counted in layout calculation. This may result in performance issues if a large number of items are involved.<br><br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute is as follows.<br>

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| .value[0].i32 | Index of the target [list item group](./arkui-ts/ts-container-listitemgroup.md) in the current [list](./arkui-ts/ts-container-list.md).|
| .value[1].i32 | Index of the target [list item](./arkui-ts/ts-container-listitem.md) in the [list item group](./arkui-ts/ts-container-listitemgroup.md).|
| .value[2]?.i32 | Whether to enable the smooth animation for scrolling to the item with the specified index. The value **1** means to enable the smooth animation, and **0** means the opposite. The default value is **0**.|
| .value[3]?.i32 | How the item to scroll to is aligned with the container. The parameter type is [ArkUI_ScrollAlignment](capi-native-type-h.md#arkui_scrollalignment). The default value is [ARKUI_SCROLL_ALIGNMENT_START](capi-native-type-h.md#arkui_scrollalignment).|

## NODE_LIST_LANES

```c
NODE_LIST_LANES = 1003011
```

Number of lanes in the list. (The number of columns is used when the list is scrolled vertically, and the number of rows is used when the list is scrolled horizontally.) This attribute can be set, reset, and obtained as required through APIs.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| .value[0].u32 | Number of lanes in the list. If the maximum and minimum lane widths are set, setting the number of lanes will not take effect. The default value is **1**. The value range is [1, +∞). If an abnormal value is set, the default value is used.|
| .value[1]?.f32 | Minimum lane width, in vp.|
| .value[2]?.f32 | Maximum lane width, in vp.|
| .value[3]?.f32 | Lane spacing, in vp. The default value is **0**.|

**Returns**

| Type| Description|
| -- | -- |
| .value[0].u32 | Number of lanes in the list.|
| .value[1].f32 | Minimum lane width, in vp.|
| .value[2].f32 | Maximum lane width, in vp.|
| .value[3].f32 | Lane spacing, in vp.|

## NODE_LIST_SCROLL_SNAP_ALIGN

```c
NODE_LIST_SCROLL_SNAP_ALIGN = 1003012
```

Alignment mode for scroll snapping in the **List** component.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| .value[0].i32 | Alignment mode for scroll snapping in the **List** component. The parameter type is [ArkUI_ScrollSnapAlign](capi-native-type-h.md#arkui_scrollsnapalign). The default value is [ARKUI_SCROLL_SNAP_ALIGN_NONE](capi-native-type-h.md#arkui_scrollsnapalign).|

**Returns**

| Type| Description|
| -- | -- |
| .value[0].i32 | Alignment mode for scroll snapping in the **List** component. The parameter type is [ArkUI_ScrollSnapAlign](capi-native-type-h.md#arkui_scrollsnapalign).|

## NODE_LIST_MAINTAIN_VISIBLE_CONTENT_POSITION

```c
NODE_LIST_MAINTAIN_VISIBLE_CONTENT_POSITION = 1003013
```

Whether to maintain the visible content's position when data is inserted or deleted outside the display area of the **List** component.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| .value[0].i32 | Whether to maintain the visible content's position when data is inserted or deleted outside the display area of the **List** component. The value **1** means to maintain the visible content's position, and **0** means the opposite. The default value is **0**.|

**Returns**

| Type| Description|
| -- | -- |
| .value[0].i32 | Whether the visible content's position is maintained when data is inserted or deleted outside the display area of the **List** component. The value **1** means that the visible content's position is maintained, and **0** means the opposite. The default value is **0**.|

## NODE_LIST_STACK_FROM_END

```c
NODE_LIST_STACK_FROM_END = 1003014
```

Whether the **List** component starts layout from the end.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| .value[0].i32 | Whether the **List** component starts layout from the end. The value **0** means layout starts from the top, and **1** means layout starts from the end. The default value is **0**.|

**Returns**

| Type| Description|
| -- | -- |
| .value[0].i32 | Whether the **List** component starts layout from the end. The value **0** means layout starts from the top, and **1** means layout starts from the end. The default value is **0**.|

## NODE_LIST_FOCUS_WRAP_MODE

```c
NODE_LIST_FOCUS_WRAP_MODE = 1003015
```

Focus wrap mode of the **List** component. This attribute can be set, reset, and obtained as required through APIs.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| .value[0].i32 | Focus wrap mode of the **List** component. The parameter type is [ArkUI_FocusWrapMode](capi-native-type-h.md#arkui_focuswrapmode). The default value is **ARKUI_FOCUS_WRAP_MODE_DEFAULT**.|

**Returns**

| Type| Description|
| -- | -- |
| .value[0].i32 | Focus wrap mode of the **List** component. The parameter type is [ArkUI_FocusWrapMode](capi-native-type-h.md#arkui_focuswrapmode).|

## NODE_LIST_SYNC_LOAD

```c
NODE_LIST_SYNC_LOAD = 1003016
```

Whether the **List** component loads child nodes synchronously. This attribute can be set, reset, and obtained as required through APIs.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| .value[0].i32 | Whether the **List** component loads child nodes synchronously. **0**: frame-by-frame loading. **1**: synchronous loading. The default value is **1**.|

**Returns**

| Type| Description|
| -- | -- |
| .value[0].i32 | Whether the **List** component loads child nodes synchronously. **0**: frame-by-frame loading. **1**: synchronous loading.|

## NODE_LIST_SCROLL_SNAP_ANIMATION_SPEED

```c
NODE_LIST_SCROLL_SNAP_ANIMATION_SPEED = 1003017
```

Scroll snap animation speed for the **List** component. This attribute can be set, reset, and obtained as required through APIs.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 22


**Parameters**

| Name| Description|
| -- | -- |
| .value[0].i32 | Scroll snap animation speed for the **List** component. The parameter type is [ArkUI_ScrollSnapAnimationSpeed](capi-native-type-h.md#arkui_scrollsnapanimationspeed). The default value is **ARKUI_SCROLL_SNAP_ANIMATION_NORMAL**.|

**Returns**

| Type| Description|
| -- | -- |
| .value[0].i32 | Scroll snap animation speed for the **List** component. The parameter type is [ArkUI_ScrollSnapAnimationSpeed](capi-native-type-h.md#arkui_scrollsnapanimationspeed).|

## NODE_LIST_LANES_ITEMFILLPOLICY

```c
NODE_LIST_LANES_ITEMFILLPOLICY = 1003018
```

Responsive lane layout policy of the **List** component. This attribute can be set, reset, and obtained as required through APIs.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 22


**Parameters**

| Name| Description|
| -- | -- |
| .value[0].i32 | Number of lanes at different breakpoint specifications. The parameter type is [ArkUI_ItemFillPolicy](capi-native-type-h.md#arkui_itemfillpolicy).|
| .value[1]?.f32 | Lane spacing, in vp. The default value is **0**.|

**Returns**

| Type| Description|
| -- | -- |
| .value[0].i32 | Number of lanes at different breakpoint specifications. The parameter type is [ArkUI_ItemFillPolicy](capi-native-type-h.md#arkui_itemfillpolicy).|
| .value[1].f32 | Lane spacing, in vp.|

## NODE_LIST_SUPPORT_EMPTY_BRANCH_IN_LAZY_LOADING

```c
NODE_LIST_SUPPORT_EMPTY_BRANCH_IN_LAZY_LOADING = 1003019
```

Whether the **List** component supports the generation of empty branch nodes that do not contain any child components using the **if/else** rendering control syntax in **LazyForEach** or **Repeat**.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 23


**Parameters**

| Name| Description|
| -- | -- |
| .value[0].i32 | Whether the **List** component supports the generation of empty branches. **0**: no; **1**: yes. The default value is **0**.|

**Returns**

| Type| Description|
| -- | -- |
| .value[0].i32 | Whether the **List** component supports the generation of empty branches. **0**: no; **1**: yes.|

## NODE_LIST_BACK_PRESS_BEHAVIOR

```c
NODE_LIST_BACK_PRESS_BEHAVIOR = 1003020
```

Behavior of the system back button for the **List** component. This attribute can be set, reset, and obtained as required through APIs.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 26.0.0


**Parameters**

| Name| Description|
| -- | -- |
| .value[0].i32 | Whether to collapse the swipe-out component of **ListItem** when the system back button takes effect. **0**: no; **1**: yes. The default value is **1**.|

**Returns**

| Type| Description|
| -- | -- |
| .value[0].i32 | Whether the swipe-out component of **ListItem** is collapsed when the system back button takes effect. **0**: no; **1**: yes.|

## NODE_LIST_ITEM_SWIPE_ACTION

```c
NODE_LIST_ITEM_SWIPE_ACTION = MAX_NODE_SCOPE_NUM * ARKUI_NODE_LIST_ITEM = 1004000
```

Swipe-out component of **ListItem**. This attribute can be set, reset, and obtained as required through APIs.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| .object | [ArkUI_ListItemSwipeActionOption](capi-arkui-nativemodule-arkui-listitemswipeactionoption.md) object.|

**Returns**

| Type| Description|
| -- | -- |
| .object | [ArkUI_ListItemSwipeActionOption](capi-arkui-nativemodule-arkui-listitemswipeactionoption.md) object.|

## NODE_LIST_ITEM_GROUP_SET_HEADER

```c
NODE_LIST_ITEM_GROUP_SET_HEADER = MAX_NODE_SCOPE_NUM * ARKUI_NODE_LIST_ITEM_GROUP = 1005000
```

Header component of **ListItemGroup**. This attribute can be set, reset, and obtained as required through APIs.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| .object | [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) object used as the header component of **ListItemGroup**.|

**Returns**

| Type| Description|
| -- | -- |
| .object | [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) object used as the header component of **ListItemGroup**.|

## NODE_LIST_ITEM_GROUP_SET_FOOTER

```c
NODE_LIST_ITEM_GROUP_SET_FOOTER = 1005001
```

Footer component of **ListItemGroup**. This attribute can be set, reset, and obtained as required through APIs.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| .object | [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) object used as the footer component of **ListItemGroup**.|

**Returns**

| Type| Description|
| -- | -- |
| .object | [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) object used as the footer component of **ListItemGroup**.|

## NODE_LIST_ITEM_GROUP_SET_DIVIDER

```c
NODE_LIST_ITEM_GROUP_SET_DIVIDER = 1005002
```

Style of the divider for the list items. This attribute can be set, reset, and obtained as required through APIs.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| .value[0].u32 | Color, in 0xARGB format. The default value is **0x08000000**.|
| .value[1].f32 | Stroke width of the divider, in vp. The default value is **0**.|
| .value[2].f32 | Distance between the divider and the start of the list, in vp. The default value is **0**.|
| .value[3].f32 | Distance between the divider and the end of the list, in vp. The default value is **0**.|

**Returns**

| Type| Description|
| -- | -- |
| .value[0].u32 | Color, in 0xARGB format.|
| .value[1].f32 | Stroke width of the divider, in vp.|
| .value[2].f32 | Distance between the divider and the start of the list, in vp.|
| .value[3].f32 | Distance between the divider and the end of the list, in vp.|

## NODE_LIST_ITEM_GROUP_CHILDREN_MAIN_SIZE

```c
NODE_LIST_ITEM_GROUP_CHILDREN_MAIN_SIZE = 1005003
```

Default main axis size of the **ListItemGroup** child components.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| .object | The parameter type is [ArkUI_ListChildrenMainSize](capi-arkui-nativemodule-arkui-listchildrenmainsize.md).|

**Returns**

| Type| Description|
| -- | -- |
| .object | The parameter type is [ArkUI_ListChildrenMainSize](capi-arkui-nativemodule-arkui-listchildrenmainsize.md).|

## NODE_LIST_ITEM_GROUP_NODE_ADAPTER

```c
NODE_LIST_ITEM_GROUP_NODE_ADAPTER = 1005004
```

Adapter of the [ListItemGroup](arkui-ts/ts-container-listitemgroup.md) component. This attribute can be set, reset, and obtained as required through APIs.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| .object | [ArkUI_NodeAdapter](capi-arkui-nativemodule-arkui-nodeadapter8h.md) object used as the adapter.|

**Returns**

| Type| Description|
| -- | -- |
| .object | [ArkUI_NodeAdapter](capi-arkui-nativemodule-arkui-nodeadapter8h.md) object.|

## NODE_REFRESH_REFRESHING

```c
NODE_REFRESH_REFRESHING = MAX_NODE_SCOPE_NUM * ARKUI_NODE_REFRESH = 1009000
```

Whether the component is being refreshed. This attribute can be set and obtained as required through APIs.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| .value[0].i32 | Whether the component is being refreshed. **1**: being refreshed. **0**: not being refreshed. The default value is **0**. The default value is **0**.|

**Returns**

| Type| Description|
| -- | -- |
| .value[0].i32 | Whether the component is being refreshed. **1**: being refreshed. **0**: not being refreshed. The default value is **0**.|

## NODE_REFRESH_CONTENT

```c
NODE_REFRESH_CONTENT = 1009001
```

Custom content in the pull-down area. This attribute can be set, reset, and obtained as required through APIs.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute is as follows.<br>

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| .object | The parameter type is [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md).|

## NODE_REFRESH_PULL_DOWN_RATIO

```c
NODE_REFRESH_PULL_DOWN_RATIO = 1009002
```

Pull-down follow ratio. This attribute can be set, reset, and obtained as required through APIs.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| .value[0].f32 | Pull-down follow ratio. The value is in the range from 0 to 1.|

**Returns**

| Type| Description|
| -- | -- |
| .value[0].f32 | Pull-down follow ratio. The value is in the range from 0 to 1.|

## NODE_REFRESH_OFFSET

```c
NODE_REFRESH_OFFSET = 1009003
```

Pull-down offset that triggers refresh. This attribute can be set, reset, and obtained as required through APIs.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| .value[0].f32 | Pull-down offset, in vp. The default value is **64**.|

**Returns**

| Type| Description|
| -- | -- |
| .value[0].f32 | Pull-down offset, in vp. The default value is **64**.|

## NODE_REFRESH_PULL_TO_REFRESH

```c
NODE_REFRESH_PULL_TO_REFRESH = 1009004
```

Whether to initiate a refresh when the pull-down distance exceeds the value of [refreshOffset](../apis-arkui/arkui-ts/ts-container-refresh.md#refreshoffset12). This attribute can be set, reset, and obtained as required through APIs.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| .value[0].i32 | Whether to trigger a refresh. **1**: yes; **0**: no. The default value is **1**.|

**Returns**

| Type| Description|
| -- | -- |
| .value[0].i32 | Whether a refresh is triggered. The value **1** means a refresh is triggered, and **0** means the opposite.|

## NODE_REFRESH_MAX_PULL_DOWN_DISTANCE

```c
NODE_REFRESH_MAX_PULL_DOWN_DISTANCE = 1009005
```

Maximum pull-down distance for refreshing. This attribute can be set, reset, and obtained as required through APIs.<br>
The format of the return value [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) is as follows.<br>

**Since**: 20

**Parameters**

| Name| Description|
| -- | -- |
| .value[0].f32 | Maximum pull-down distance, in vp.|


**Returns**

| Type| Description|
| -- | -- |
| .value[0].f32 | Maximum pull-down distance, in vp.|

## NODE_REFRESH_PULL_UP_TO_CANCEL_REFRESH

```c
NODE_REFRESH_PULL_UP_TO_CANCEL_REFRESH = 1009006
```

Whether to enable the pull-up-to-cancel gesture for refreshing operations. This attribute can be set, reset, and obtained as required through APIs.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 23


**Parameters**

| Name| Description|
| -- | -- |
| .value[0].i32 | Whether to enable the pull-up-to-cancel gesture for refreshing operations. **0**: disable; **1**: enable. The default value is **1**.|

**Returns**

| Type| Description|
| -- | -- |
| .value[0].i32 | Whether the pull-up-to-cancel gesture is enabled for refreshing operations. **0**: The pull-up-to-cancel gesture is disabled; **1**: The pull-up-to-cancel gesture is enabled.|

## NODE_WATER_FLOW_LAYOUT_DIRECTION

```c
NODE_WATER_FLOW_LAYOUT_DIRECTION = MAX_NODE_SCOPE_NUM * ARKUI_NODE_WATER_FLOW = 1010000
```

Main axis direction of the **WaterFlow** component layout. This attribute can be set, reset, and obtained as required through APIs.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| .value[0].i32 | Direction of the main axis. The parameter type is [ArkUI_FlexDirection](capi-native-type-h.md#arkui_flexdirection). The default value is [ARKUI_FLEX_DIRECTION_COLUMN](capi-native-type-h.md#arkui_flexdirection).|

**Returns**

| Type| Description|
| -- | -- |
| .value[0].i32 | Direction of the main axis. The parameter type is [ArkUI_FlexDirection](capi-native-type-h.md#arkui_flexdirection).|

## NODE_WATER_FLOW_COLUMN_TEMPLATE

```c
NODE_WATER_FLOW_COLUMN_TEMPLATE = 1010001
```

Number of columns in the water flow layout. If this attribute is not set, one column is used by default. This attribute can be set, reset, and obtained as required through APIs. For example, **'1fr 1fr 2fr'** indicates three columns, with the first column taking up 1/4 of the parent component's full width, the second column 1/4, and the third column 2/4. You can use [columnsTemplate](../apis-arkui/arkui-ts/ts-container-waterflow.md#columnstemplate)('repeat(auto-fill,track-size)') to automatically calculate the number of columns based on the specified column width (using **track-size**). **repeat** and **auto-fill** are keywords. The units for **track-size** can be px, vp (default), %, or a valid number.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| .string | Number of columns in the layout. The default value is **'1fr'**.|

**Returns**

| Type| Description|
| -- | -- |
| .string | Number of columns in the layout.|

## NODE_WATER_FLOW_ROW_TEMPLATE

```c
NODE_WATER_FLOW_ROW_TEMPLATE = 1010002
```

Number of rows in the water flow layout. If this attribute is not set, one row is used by default. This attribute can be set, reset, and obtained as required through APIs. For example, **'1fr 1fr 2fr'** indicates three rows, with the first row taking up 1/4 of the parent component's full height, the second row 1/4, and the third row 2/4. You can use [rowsTemplate](../apis-arkui/arkui-ts/ts-container-waterflow.md#rowstemplate)('repeat(auto-fill,track-size)') to automatically calculate the number of rows based on the specified row height (using **track-size**). **repeat** and **auto-fill** are keywords. The units for **track-size** can be px, vp (default), %, or a valid number.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| .string | Number of rows in the layout. The default value is **'1fr'**.|

**Returns**

| Type| Description|
| -- | -- |
| .string | Number of rows in the layout.|

## NODE_WATER_FLOW_COLUMN_GAP

```c
NODE_WATER_FLOW_COLUMN_GAP = 1010003
```

Gap between columns. This attribute can be set, reset, and obtained as required through APIs.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| .value[0].f32 | Gap between columns, in vp. The default value is **0**. Value range: [0, +∞).|

**Returns**

| Type| Description|
| -- | -- |
| .value[0].f32 | Gap between columns, in vp.|

## NODE_WATER_FLOW_ROW_GAP

```c
NODE_WATER_FLOW_ROW_GAP = 1010004
```

Gap between rows. This attribute can be set, reset, and obtained as required through APIs.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| .value[0].f32 | Gap between rows, in vp. The default value is **0**. Value range: [0, +∞).|

**Returns**

| Type| Description|
| -- | -- |
| .value[0].f32 | Gap between rows, in vp.|

## NODE_WATER_FLOW_SECTION_OPTION

```c
NODE_WATER_FLOW_SECTION_OPTION = 1010005
```

Water flow section configuration. This attribute can be set, reset, and obtained as required through APIs.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| .value[0].i32 | Zero-based index at which the changing starts. The value is converted to an integer.|
| .object | The parameter format is [ArkUI_WaterFlowSectionOption](capi-arkui-nativemodule-arkui-waterflowsectionoption.md).|

**Returns**

| Type| Description|
| -- | -- |
| .object | [ArkUI_WaterFlowSectionOption](capi-arkui-nativemodule-arkui-waterflowsectionoption.md) object.|

## NODE_WATER_FLOW_NODE_ADAPTER

```c
NODE_WATER_FLOW_NODE_ADAPTER = 1010006
```

Adapter of the [WaterFlow](arkui-ts/ts-container-waterflow.md) component. This attribute can be set, reset, and obtained as required through APIs.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| .object | [ArkUI_NodeAdapter](capi-arkui-nativemodule-arkui-nodeadapter8h.md) object used as the adapter.|

**Returns**

| Type| Description|
| -- | -- |
| .object | [ArkUI_NodeAdapter](capi-arkui-nativemodule-arkui-nodeadapter8h.md) object.|

## NODE_WATER_FLOW_CACHED_COUNT

```c
NODE_WATER_FLOW_CACHED_COUNT = 1010007
```

Number of cached items in the adapter of the [WaterFlow](arkui-ts/ts-container-waterflow.md) component. This attribute can be set, reset, and obtained as required through APIs.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| .value[0].i32 | Number of cached items in the **WaterFlow** component's adapter.|
| .value[1]?.i32 | Whether to show cached items. The value **0** means to hide cached items, and **1** means to show cached items. The default value is **0**. This parameter is supported since API version 16.|

**Returns**

| Type| Description|
| -- | -- |
| .value[0].i32 | Number of cached items in the adapter.|
| .value[1].i32 | Whether cached items are shown. The value **0** means that cached items are hidden, and **1** means that cached items are shown. This parameter is supported since API version 16.|

## NODE_WATER_FLOW_FOOTER

```c
NODE_WATER_FLOW_FOOTER = 1010008
```

Custom footer for the **WaterFlow** component.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute is as follows.<br>

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| .object | The parameter type is [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md).|

## NODE_WATER_FLOW_SCROLL_TO_INDEX

```c
NODE_WATER_FLOW_SCROLL_TO_INDEX = 1010009
```

Scrolls to the item with the specified index. When **smooth** is set to **true**, all passed items are loaded and counted in layout calculation. This may result in performance issues if a large number of items are involved.<br><br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute is as follows.<br>

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| .value[0].i32 | Index of the item to be scrolled to in the container.|
| .value[1]?.i32 | Whether to enable the smooth animation for scrolling to the item with the specified index. The value **1** means to enable the smooth animation, and **0** means the opposite. The default value is **0**.|
| .value[2]?.i32 | How the item to scroll to is aligned with the container. The parameter type is [ArkUI_ScrollAlignment](capi-native-type-h.md#arkui_scrollalignment). The default value is [ARKUI_SCROLL_ALIGNMENT_START](capi-native-type-h.md#arkui_scrollalignment).|
| .value[3]?.f32 | Extra offset after the target item is scrolled to, in vp. The default value is **0**. A positive value offsets the scroll position downward (or toward the end); a negative value offsets it upward (or toward the start). This parameter is supported since API version 23.|

## NODE_WATER_FLOW_ITEM_CONSTRAINT_SIZE

```c
NODE_WATER_FLOW_ITEM_CONSTRAINT_SIZE = 1010010
```

Size constraints to apply to water flow items. This attribute can be set, reset, and obtained as required through APIs.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| .value[0].f32 | Minimum width. The value **-1** indicates that the minimum width is not set.|
| .value[1].f32 | Maximum width. The value **-1** indicates that the maximum width is not set.|
| .value[2].f32 | Minimum height. The value **-1** indicates that the minimum height is not set.|
| .value[3].f32 | Maximum height. The value **-1** indicates that the maximum height is not set.|

**Returns**

| Type| Description|
| -- | -- |
| .value[0].f32 | Minimum width. The value **-1** indicates that the minimum width is not set.|
| .value[1].f32 | Maximum width. The value **-1** indicates that the maximum width is not set.|
| .value[2].f32 | Minimum height. The value **-1** indicates that the minimum height is not set.|
| .value[3].f32 | Maximum height. The value **-1** indicates that the maximum height is not set.|

## NODE_WATER_FLOW_LAYOUT_MODE

```c
NODE_WATER_FLOW_LAYOUT_MODE = 1010011
```

Layout mode for the **WaterFlow** component. This attribute can be set, reset, and obtained as required through APIs.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| .value[0].i32 | Layout mode. The parameter type is [ArkUI_WaterFlowLayoutMode](capi-native-type-h.md#arkui_waterflowlayoutmode). The default value is [ARKUI_WATER_FLOW_LAYOUT_MODE_ALWAYS_TOP_DOWN](capi-native-type-h.md#arkui_waterflowlayoutmode).|

**Returns**

| Type| Description|
| -- | -- |
| .value[0].i32 | Layout mode. The parameter type is [ArkUI_WaterFlowLayoutMode](capi-native-type-h.md#arkui_waterflowlayoutmode).|

## NODE_WATER_FLOW_SYNC_LOAD

```c
NODE_WATER_FLOW_SYNC_LOAD = 1010012
```

Whether the **WaterFlow** component loads child nodes synchronously. This attribute can be set, reset, and obtained as required through APIs.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| .value[0].i32 | Whether the **WaterFlow** component loads child nodes synchronously. **0**: frame-by-frame loading. **1**: synchronous loading. The default value is **1**.|

**Returns**

| Type| Description|
| -- | -- |
| .value[0].i32 | Whether the **WaterFlow** component loads child nodes synchronously. **0**: frame-by-frame loading. **1**: synchronous loading.|

## NODE_WATER_FLOW_COLUMN_TEMPLATE_ITEMFILLPOLICY

```c
NODE_WATER_FLOW_COLUMN_TEMPLATE_ITEMFILLPOLICY  = 1010013
```

Responsive column layout policy of the **WaterFlow** component. This attribute can be set, reset, and obtained as required through APIs.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 22


**Parameters**

| Name| Description|
| -- | -- |
| .value[0].i32 | Number of columns at different breakpoint specifications. The parameter type is [ArkUI_ItemFillPolicy](capi-native-type-h.md#arkui_itemfillpolicy).|

**Returns**

| Type| Description|
| -- | -- |
| .value[0].i32 | Number of columns at different breakpoint specifications. The parameter type is [ArkUI_ItemFillPolicy](capi-native-type-h.md#arkui_itemfillpolicy).|

## NODE_WATER_FLOW_SUPPORT_EMPTY_BRANCH_IN_LAZY_LOADING

```c
NODE_WATER_FLOW_SUPPORT_EMPTY_BRANCH_IN_LAZY_LOADING = 1010014
```

Whether the **WaterFlow** component supports the generation of empty branch nodes that do not contain any child components using the **if/else** rendering control syntax in **LazyForEach** or **Repeat**.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

> **NOTE**
>
> If the [ArkUI_WaterFlowSectionOption](capi-arkui-nativemodule-arkui-waterflowsectionoption.md) section is set through [NODE_WATER_FLOW_SECTION_OPTION](capi-native-node-h-nodeattributetype-scrollablecontainer.md#node_water_flow_section_option) or the [ARKUI_WATER_FLOW_LAYOUT_MODE_SLIDING_WINDOW](capi-native-type-h.md#arkui_waterflowlayoutmode) layout mode is set through [NODE_WATER_FLOW_LAYOUT_MODE](capi-native-node-h-nodeattributetype-scrollablecontainer.md#node_water_flow_layout_mode), setting this parameter to **0** or **1** will display all **FlowItem**s after the empty branches.

**Since**: 26.0.0


**Parameters**

| Name| Description|
| -- | -- |
| .value[0].i32 | Whether the **WaterFlow** component supports the generation of empty branches. **0**: no; **1**: yes. The default value is **0**.|

**Returns**

| Type| Description|
| -- | -- |
| .value[0].i32 | Whether the **WaterFlow** component supports the generation of empty branches. **0**: no; **1**: yes.|

## NODE_GRID_COLUMN_TEMPLATE

```c
NODE_GRID_COLUMN_TEMPLATE = MAX_NODE_SCOPE_NUM * ARKUI_NODE_GRID = 1013000
```

Number of columns in the **Grid** component. If this attribute is not set, one column is used by default. This attribute can be set, reset, and obtained as required through APIs. For example, **'1fr 1fr 2fr'** indicates three columns, with the first column taking up 1/4 of the parent component's full width, the second column 1/4, and the third column 2/4. You can use [columnsTemplate](../apis-arkui/arkui-ts/ts-container-grid.md#columnstemplate)('repeat(auto-fill,track-size)') to automatically calculate the number of columns based on the specified column width (using **track-size**). **repeat** and **auto-fill** are keywords. The units for **track-size** can be px, vp (default), %, or a valid number.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| .string | Number of columns in the layout.|

**Returns**

| Type| Description|
| -- | -- |
| .string | Number of columns in the layout.|

## NODE_GRID_ROW_TEMPLATE

```c
NODE_GRID_ROW_TEMPLATE = 1013001
```

Number of rows or the minimum row height in the **Grid** component. If this parameter is not set, one row is used by default. This attribute can be set, reset, and obtained as required through APIs. For example, **'1fr 1fr 2fr'** indicates three rows, with the first row taking up 1/4 of the parent component's full height, the second row 1/4, and the third row 2/4. You can use [rowsTemplate](../apis-arkui/arkui-ts/ts-container-grid.md#rowstemplate)('repeat(auto-fill,track-size)') to automatically calculate the number of rows based on the specified row height (using **track-size**). **repeat** and **auto-fill** are keywords. The units for **track-size** can be px, vp (default), %, or a valid number.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| .string | Number of rows in the layout.|

**Returns**

| Type| Description|
| -- | -- |
| .string | Number of rows in the layout.|

## NODE_GRID_COLUMN_GAP

```c
NODE_GRID_COLUMN_GAP = 1013002
```

Gap between columns. This attribute can be set, reset, and obtained as required through APIs.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| .value[0].f32 | Gap between columns, in vp. The default value is **0**. Value range: [0, +∞).|

**Returns**

| Type| Description|
| -- | -- |
| .value[0].f32 | Gap between columns, in vp.|

## NODE_GRID_ROW_GAP

```c
NODE_GRID_ROW_GAP = 1013003
```

Gap between rows. This attribute can be set, reset, and obtained as required through APIs.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| .value[0].f32 | Gap between rows, in vp. The default value is **0**. Value range: [0, +∞).|

**Returns**

| Type| Description|
| -- | -- |
| .value[0].f32 | Gap between rows, in vp.|

## NODE_GRID_NODE_ADAPTER

```c
NODE_GRID_NODE_ADAPTER = 1013004
```

Adapter of the [Grid](arkui-ts/ts-container-grid.md) component. This attribute can be set, reset, and obtained as required through APIs.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| .object | [ArkUI_NodeAdapter](capi-arkui-nativemodule-arkui-nodeadapter8h.md) object used as the adapter.|

**Returns**

| Type| Description|
| -- | -- |
| .object | [ArkUI_NodeAdapter](capi-arkui-nativemodule-arkui-nodeadapter8h.md) object.|

## NODE_GRID_CACHED_COUNT

```c
NODE_GRID_CACHED_COUNT = 1013005
```

Number of cached items in the adapter of the [Grid](arkui-ts/ts-container-grid.md) component. This attribute can be set, reset, and obtained as required through APIs.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute is as follows.<br>

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| .value[0].i32 | Number of cached items of [ArkUI_NodeAdapter](capi-arkui-nativemodule-arkui-nodeadapter8h.md), which is used with the **Grid** component.|
| .value[1].i32 | Whether to show cached items. The value **0** means to hide cached items, and **1** means to show cached items. This parameter is optional. The default value is **0**. This parameter is supported since API version 26.0.0.|

**Returns**

| Type| Description|
| -- | -- |
| .value[0].i32 | Number of cached items in the **Grid** component adapter.|
| .value[1].i32 | Whether cached items are shown. The value **0** means that cached items are hidden, and **1** means that cached items are shown. This parameter is supported since API version 26.0.0.|

## NODE_GRID_FOCUS_WRAP_MODE

```c
NODE_GRID_FOCUS_WRAP_MODE = 1013006
```

Focus wrap mode of the [Grid](arkui-ts/ts-container-grid.md) component. This attribute can be set, reset, and obtained as required through APIs.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| .value[0].i32 | Focus wrap mode of the **Grid** component. The parameter type is [ArkUI_FocusWrapMode](capi-native-type-h.md#arkui_focuswrapmode). The default value is [FOCUS_WRAP_MODE_DEFAULT](capi-native-type-h.md#arkui_focuswrapmode).|

**Returns**

| Type| Description|
| -- | -- |
| .value[0].i32 | Focus wrap mode of the **Grid** component. The parameter type is [ArkUI_FocusWrapMode](capi-native-type-h.md#arkui_focuswrapmode).|

## NODE_GRID_SYNC_LOAD

```c
NODE_GRID_SYNC_LOAD = 1013007
```

Whether the [Grid](arkui-ts/ts-container-grid.md) component synchronously loads child nodes. This attribute can be set, reset, and obtained as required through APIs.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| .value[0].i32 | Whether the **Grid** component loads child nodes synchronously. **0**: frame-by-frame loading. **1**: synchronous loading. The default value is **1**.|

**Returns**

| Type| Description|
| -- | -- |
| .value[0].i32 | Whether the **Grid** component loads child nodes synchronously. **0**: frame-by-frame loading. **1**: synchronous loading.|

## NODE_GRID_ALIGN_ITEMS

```c
NODE_GRID_ALIGN_ITEMS = 1013008
```

Alignment mode of [GridItem](arkui-ts/ts-container-griditem.md) in **Grid**. This attribute can be set, reset, and obtained as required through APIs.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 22


**Parameters**

| Name| Description|
| -- | -- |
| .value[0].i32 | Alignment mode of **GridItem** in **Grid**. The parameter type is [ArkUI_GridItemAlignment](capi-native-type-h.md#arkui_griditemalignment). The default value is [GRID_ITEM_ALIGNMENT_DEFAULT](capi-native-type-h.md#arkui_griditemalignment).|

**Returns**

| Type| Description|
| -- | -- |
| .value[0].i32 | Alignment mode of **GridItem** in **Grid**. The parameter type is [ArkUI_GridItemAlignment](capi-native-type-h.md#arkui_griditemalignment).|

## NODE_GRID_LAYOUT_OPTIONS

```c
NODE_GRID_LAYOUT_OPTIONS = 1013009
```

Layout options of **Grid**. This attribute can be set, reset, and obtained as required through APIs.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 22


**Parameters**

| Name| Description|
| -- | -- |
| .object | The parameter type is [ArkUI_GridLayoutOptions](capi-arkui-nativemodule-arkui-gridlayoutoptions.md).|

**Returns**

| Type| Description|
| -- | -- |
| .object | [ArkUI_GridLayoutOptions](capi-arkui-nativemodule-arkui-gridlayoutoptions.md) object.|

## NODE_GRID_COLUMN_TEMPLATE_ITEMFILLPOLICY

```c
NODE_GRID_COLUMN_TEMPLATE_ITEMFILLPOLICY = 1013010
```

Responsive column layout policy of the **Grid** component. This attribute can be set, reset, and obtained as required through APIs.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 22


**Parameters**

| Name| Description|
| -- | -- |
| .value[0].i32 | Number of columns at different breakpoint specifications. The parameter type is [ArkUI_ItemFillPolicy](capi-native-type-h.md#arkui_itemfillpolicy).|

**Returns**

| Type| Description|
| -- | -- |
| .value[0].i32 | Number of columns at different breakpoint specifications. The parameter type is [ArkUI_ItemFillPolicy](capi-native-type-h.md#arkui_itemfillpolicy).|

## NODE_GRID_EDIT_MODE

```c
NODE_GRID_EDIT_MODE = 1013011
```

Whether the **Grid** component enters the editing mode. After the component enters the editing mode, you can drag **GridItem** by using the **NODE_GRID_ON_ITEM_DRAG_START** event. This attribute can be set, reset, and obtained as required through APIs.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 23


**Parameters**

| Name| Description|
| -- | -- |
| .value[0].i32 | Whether the **Grid** component enters the editing mode. **0**: The component does not enter the editing mode. **1**: The component enters the editing mode. The default value is **0**.|

**Returns**

| Type| Description|
| -- | -- |
| .value[0].i32 | Whether the **Grid** component enters the editing mode. **0**: The component does not enter the editing mode. **1**: The component enters the editing mode.|

## NODE_GRID_DRAG_ANIMATION

```c
NODE_GRID_DRAG_ANIMATION = 1013012
```

Whether to enable the drag animation for **GridItem** in the **Grid** component. This attribute can be set, reset, and obtained as required through APIs.<br>
The animation is supported only when the scrolling mode is used (only one of **NODE_GRID_ROW_TEMPLATE** and **NODE_GRID_COLUMN_TEMPLATE** is set).<br>
Drag animations are only supported in grids with fixed size rules; scenarios involving spanning across rows or columns are not supported.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 23


**Parameters**

| Name| Description|
| -- | -- |
| .value[0].i32 | Whether to enable the drag animation for **GridItem** in the **Grid** component. **0**: disable; **1**: enable. The default value is **0**.|

**Returns**

| Type| Description|
| -- | -- |
| .value[0].i32 | Whether the drag animation is enabled for **GridItem** in the **Grid** component. **0**: disabled; **1**: enabled.|

## NODE_GRID_MULTI_SELECTABLE

```c
NODE_GRID_MULTI_SELECTABLE = 1013013
```

Whether to enable mouse-based multi-selection for the **Grid** component. This attribute can be set, reset, and obtained as required through APIs.<br>
After enabled, mouse-based multi-selection within the grid will trigger the [NODE_GRID_ITEM_ON_SELECT](./capi-native-node-h.md#arkui_nodeeventtype) event of the grid item.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 23


**Parameters**

| Name| Description|
| -- | -- |
| .value[0].i32 | Whether to enable mouse-based multi-selection for the **Grid** component. **0**: disable; **1**: enable. The default value is **0**.|

**Returns**

| Type| Description|
| -- | -- |
| .value[0].i32 | Whether mouse-based multi-selection is enabled for the **Grid** component. **0**: disabled; **1**: enabled.|

## NODE_GRID_SCROLL_TO_INDEX

```c
NODE_GRID_SCROLL_TO_INDEX = 1013014
```

Scrolls to the item with the specified index.<br>
When the animation is enabled, all passed child components are loaded and counted in layout calculation. This may result in performance issues if a large number of child components are involved.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute is as follows.<br>

**Since**: 23


**Parameters**

| Name| Description|
| -- | -- |
| .value[0].i32 | Index of the item to be scrolled to in the container.|
| .value[1]?.i32 | Whether to enable the animation for scrolling to the target item. The value **1** means to enable, and **0** means the opposite. The default value is **0**.|
| .value[2]?.i32 | How the item to scroll to is aligned with the container. The parameter type is [ArkUI_ScrollAlignment](capi-native-type-h.md#arkui_scrollalignment). The default value is **ARKUI_SCROLL_ALIGNMENT_AUTO**.|
| .value[3]?.f32 | Extra offset after the target item is scrolled to, in vp. The default value is **0**. A positive value offsets the scroll position downward (or toward the end); a negative value offsets it upward (or toward the start).|

## NODE_GRID_SUPPORT_EMPTY_BRANCH_IN_LAZY_LOADING

```c
NODE_GRID_SUPPORT_EMPTY_BRANCH_IN_LAZY_LOADING = 1013015
```

Whether the **Grid** component supports the generation of empty branch nodes that do not contain any child components using the **if/else** rendering control syntax in **LazyForEach** or **Repeat**.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 23


**Parameters**

| Name| Description|
| -- | -- |
| .value[0].i32 | Whether the **Grid** component supports the generation of empty branches. **0**: no; **1**: yes. The default value is **0**.|

**Returns**

| Type| Description|
| -- | -- |
| .value[0].i32 | Whether the **Grid** component supports the generation of empty branches. **0**: no; **1**: yes.|

## NODE_GRID_ITEM_STYLE

```c
NODE_GRID_ITEM_STYLE = MAX_NODE_SCOPE_NUM * ARKUI_NODE_GRID_ITEM = 1014000
```

Style for **GridItem**. This attribute can be set, reset, and obtained as required through APIs.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 22


**Parameters**

| Name| Description|
| -- | -- |
| .value[0].i32 | Style for **GridItem**. The parameter type is [ArkUI_GridItemStyle](capi-native-type-h.md#arkui_griditemstyle). The default value is [GRID_ITEM_STYLE_NONE](capi-native-type-h.md#arkui_griditemstyle).|

**Returns**

| Type| Description|
| -- | -- |
| .value[0].i32 | Style for **GridItem**. The parameter type is [ArkUI_GridItemStyle](capi-native-type-h.md#arkui_griditemstyle).|

## NODE_GRID_ITEM_SELECTABLE

```c
NODE_GRID_ITEM_SELECTABLE = 1014001
```

Whether **GridItem** can be selected using mouse-based multi-selection. This attribute can be set, reset, and obtained as required through APIs.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 23


**Parameters**

| Name| Description|
| -- | -- |
| .value[0].i32 | Whether **GridItem** can be selected using mouse-based multi-selection. **0**: not selectable. **1**: selectable. The default value is **1**.|

**Returns**

| Type| Description|
| -- | -- |
| .value[0].i32 | Whether **GridItem** can be selected using mouse-based multi-selection. **0**: not selectable. **1**: selectable.|

## NODE_GRID_ITEM_SELECTED

```c
NODE_GRID_ITEM_SELECTED = 1014002
```

Selection status of **GridItem**. This attribute can be set, reset, and obtained as required through APIs.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 23


**Parameters**

| Name| Description|
| -- | -- |
| .value[0].i32 | Selection status of **GridItem**. **0**: not selected. **1**: selected. The default value is **0**.|

**Returns**

| Type| Description|
| -- | -- |
| .value[0].i32 | Selection status of **GridItem**. **0**: not selected. **1**: selected.|

## NODE_ARC_LIST_DIGITAL_CROWN_SENSITIVITY

```c
NODE_ARC_LIST_DIGITAL_CROWN_SENSITIVITY = MAX_NODE_SCOPE_NUM * ARKUI_NODE_ARC_LIST = 1019000
```

Crown sensitivity of the **ArcList** component, which can be set, reset, and obtained as required through APIs.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| .value[0].i32 | Crown sensitivity type. The parameter type is [ArkUI_CrownSensitivity](capi-native-type-h.md#arkui_crownsensitivity). The default value is [ARKUI_CROWN_SENSITIVITY_MEDIUM](capi-native-type-h.md#arkui_crownsensitivity).|

**Returns**

| Type| Description|
| -- | -- |
| .value[0].i32 | Crown sensitivity type. The parameter type is [ArkUI_CrownSensitivity](capi-native-type-h.md#arkui_crownsensitivity).|

## NODE_ARC_LIST_SPACE

```c
NODE_ARC_LIST_SPACE = 1019001
```

Spacing between the **ArcList** child components in the main axis direction. This attribute can be set, reset, and obtained as required through APIs.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| .value[0].f32 | Spacing between the child components in the main axis direction, in vp. The default value is **0**.|

**Returns**

| Type| Description|
| -- | -- |
| .value[0].f32 | Spacing between list items along the main axis.|

## NODE_ARC_LIST_CACHED_COUNT

```c
NODE_ARC_LIST_CACHED_COUNT = 1019002
```

Number of cached items of the **ArcList** component. This attribute can be set, reset, and obtained as required through APIs.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| .value[0].i32 | Number of cached items.|

**Returns**

| Type| Description|
| -- | -- |
| .value[0].i32 | Number of cached items.|

## NODE_ARC_LIST_SCROLL_TO_INDEX

```c
NODE_ARC_LIST_SCROLL_TO_INDEX = 1019003
```

Scrolls to the list item corresponding to a specified index value. When the animation is enabled, all passed list items are loaded and counted in layout calculation. This may result in performance issues if a large number of list items are involved.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute is as follows.<br>

**Since**: 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| .value[0].i32 | Index of the item to be scrolled to in the container. If the value is **-1**, the last item in the container is scrolled to.|
| .value[1]?.i32 | Whether there is an animation effect when the list item corresponding to the specified index value is scrolled to. The value **1** indicates there is an animation effect, and **0** indicates the opposite. The default value is **0**.|
| .value[2]?.i32 | How the list item to scroll to is aligned with the container. The parameter type is [ArkUI_ScrollAlignment](capi-native-type-h.md#arkui_scrollalignment). The default value is [ARKUI_SCROLL_ALIGNMENT_START](capi-native-type-h.md#arkui_scrollalignment).|
| .value[3]?.f32 | Extra offset, in vp. The default value is **0**.|

## NODE_ARC_LIST_CHAIN_ANIMATION

```c
NODE_ARC_LIST_CHAIN_ANIMATION = 1019004
```

Whether to enable the chain animation effect for the **ArcList** component. This attribute can be set, reset, and obtained as required through APIs.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute is as follows.<br>

**Since**: 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| .value[0].i32 | Whether to enable the chain animation effect. The value **1** means to enable, and **0** means the opposite. The default value is **0**.|

**Returns**

| Type| Description|
| -- | -- |
| .value[0].i32 | Whether the chain animation effect is enabled.|

## NODE_ARC_LIST_CHILDREN_MAIN_SIZE

```c
NODE_ARC_LIST_CHILDREN_MAIN_SIZE = 1019005
```

Default main axis size of the **ArcList** child component. The attribute can be set and reset through APIs.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute is as follows.<br>

**Since**: 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| .object | The parameter type is [ArkUI_ListChildrenMainSize](capi-arkui-nativemodule-arkui-listchildrenmainsize.md).|

## NODE_ARC_LIST_SET_HEADER

```c
NODE_ARC_LIST_SET_HEADER = 1019006
```

Header component of **ArcList**. This attribute can be set, reset, and obtained as required through APIs.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| .object | [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) object used as the header component of **ArcList**.|

**Returns**

| Type| Description|
| -- | -- |
| .object | [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) object used as the header component of **ArcList**.|


## NODE_ARC_LIST_SCROLL_BAR

```c
NODE_ARC_LIST_SCROLL_BAR = 1019007
```

Scroll bar display mode of the **ArcList** component. This attribute can be set, reset, and obtained as required through APIs.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| .value[0].i32 | Scroll bar display mode. The parameter type is [ArkUI_ScrollBarDisplayMode](capi-native-type-h.md#arkui_scrollbardisplaymode). The default value is [ARKUI_SCROLL_BAR_DISPLAY_MODE_AUTO](capi-native-type-h.md#arkui_scrollbardisplaymode).|

**Returns**

| Type| Description|
| -- | -- |
| .value[0].i32 | Scrollbar display mode. The parameter type is [ArkUI_ScrollBarDisplayMode](capi-native-type-h.md#arkui_scrollbardisplaymode).|

## NODE_ARC_LIST_SCROLL_BAR_COLOR

```c
NODE_ARC_LIST_SCROLL_BAR_COLOR = 1019008
```

Scroll bar color of the **ArcList** component. This attribute can be set, reset, and obtained as required through APIs.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| .data[0].u32 | Color of the scrollbar, in 0xARGB format. The default value is **0x66182431**.|

**Returns**

| Type| Description|
| -- | -- |
| .data[0].u32 | Color of the scrollbar, in 0xARGB format.|


## NODE_ARC_LIST_SCROLL_BAR_WIDTH

```c
NODE_ARC_LIST_SCROLL_BAR_WIDTH = 1019009
```

Scroll bar width of the **ArcList** component. This attribute can be set, reset, and obtained as required through APIs.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| .value[0].f32 | Width of the scrollbar, in vp. The default value is **4**.<br>If this parameter is set to a value less than or equal to 0, the default value is used. The value **0** means not to show the scrollbar.|

**Returns**

| Type| Description|
| -- | -- |
| .value[0].f32 | Width of the scrollbar, in vp.|

## NODE_ARC_LIST_ENABLE_SCROLL_INTERACTION

```c
NODE_ARC_LIST_ENABLE_SCROLL_INTERACTION = 1019010
```

Whether the **ArcList** component supports scroll gestures. This attribute can be set, reset, and obtained as required through APIs.
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| .value[0].i32 | Whether to support scroll gestures. The default value is **1**. The value **1** means to support, and **0** means the opposite.|

**Returns**

| Type| Description|
| -- | -- |
| .value[0].i32 | Whether scroll gestures are supported.|


## NODE_ARC_LIST_FADING_EDGE

```c
NODE_ARC_LIST_FADING_EDGE = 1019011
```

Edge fade effect of the **ArcList** component. This attribute can be set, reset, and obtained as required through APIs.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| .value[0].i32 | Whether to enable the edge fade effect. **0**: The edge fade effect is disabled. **1**: The edge fade effect is enabled. The default value is **0**.|
| .value[1]?.f32 | Length of the edge fade effect. The unit is vp. The default value is **32**.|

**Returns**

| Type| Description|
| -- | -- |
| .value[0].i32 | Whether the edge fade effect is enabled. **0**: The edge fade effect is disabled. **1**: The edge fade effect is enabled.|
| .value[1].f32 | Length of the edge fade effect. The unit is vp.|

## NODE_ARC_LIST_FRICTION

```c
NODE_ARC_LIST_FRICTION = 1019012
```

Friction coefficient of the **ArcList** component, which can be set, reset, and obtained as required through APIs.<br>The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| .value[0].f32 | Friction coefficient. The default value is **0.8**. Value range: (0, +∞). If this parameter is set to a value less than or equal to 0, the default value is used.|

**Returns**

| Type| Description|
| -- | -- |
| .value[0].f32 | Friction coefficient.|


## NODE_ARC_LIST_FLING_SPEED_LIMIT

```c
NODE_ARC_LIST_FLING_SPEED_LIMIT = 1019013
```

Maximum initial speed of the fling animation in the **ArcList** component. This attribute can be set, reset, and obtained as required through APIs.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| .value[0].f32 | Maximum initial velocity at the start of the fling animation, in vp/s. Default value: **9000**.|

**Returns**

| Type| Description|
| -- | -- |
| .value[0].f32 | Maximum initial velocity at the start of the fling animation.|


## NODE_ARC_LIST_ITEM_AUTO_SCALE

```c
NODE_ARC_LIST_ITEM_AUTO_SCALE = MAX_NODE_SCOPE_NUM * ARKUI_NODE_ARC_LIST_ITEM = 1020000
```

Whether to enable automatic scaling for **ArcListItem**. This attribute can be set, reset, and obtained as required through APIs.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| .value[0].i32 | Whether to enable automatic scaling. The value **1** means to enable, and **0** means the opposite. The default value is **1**.|

**Returns**

| Type| Description|
| -- | -- |
| .value[0].i32 | Whether automatic scaling is enabled.|


## NODE_ARC_LIST_ITEM_SWIPE_ACTION

```c
NODE_ARC_LIST_ITEM_SWIPE_ACTION = 1020001
```

Swipe-out component of **ArcListItem**. This attribute can be set and reset as required through APIs.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute is as follows.<br>

**Since**: 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| .object | [ArkUI_ListItemSwipeActionOption](capi-arkui-nativemodule-arkui-listitemswipeactionoption.md) object.|

## NODE_ARC_SCROLL_BAR_BIND_SCROLLABLE

```c
NODE_ARC_SCROLL_BAR_BIND_SCROLLABLE = MAX_NODE_SCOPE_NUM * ARKUI_NODE_ARC_SCROLL_BAR = 1021000
```

Scrollable component bound to **ArcScrollBar**. This attribute can be set, reset, and obtained as required through APIs.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| .object | [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) object used as the scrollable component bound to **ArcScrollBar**.|

**Returns**

| Type| Description|
| -- | -- |
| .object | [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) object used as the scrollable component bound to **ArcScrollBar**.|


## NODE_ARC_SCROLL_BAR_DISPLAY_MODE

```c
NODE_ARC_SCROLL_BAR_DISPLAY_MODE = 1021001
```

Scroll bar display mode of **ArcScrollBar**. This attribute can be set, reset, and obtained as required through APIs.<br>
The format of the [ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md) parameter for setting the attribute and the format of the return value **ArkUI_AttributeItem** are as follows.<br>

**Since**: 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| .value[0].i32 | Scroll bar display mode. The parameter type is [ArkUI_ScrollBarDisplayMode](capi-native-type-h.md#arkui_scrollbardisplaymode). The default value is **ARKUI_SCROLL_BAR_DISPLAY_MODE_AUTO**.|

**Returns**

| Type| Description|
| -- | -- |
| .value[0].i32 | Scrollbar display mode. The parameter type is [ArkUI_ScrollBarDisplayMode](capi-native-type-h.md#arkui_scrollbardisplaymode).|
