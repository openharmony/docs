# layout.h

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @fenglinbailu-->
<!--Designer: @fenglinbailu-->
<!--Tester: @l30014443-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=85ddf9069ee1869f9713e2aedfa1415c47293c39 translatedAt=2026-08-11T09:12:25.708Z pushedAt=2026-08-12T03:42:01.647Z -->

## Overview

Defines layout-related enumerations and APIs.

**File to include:** <arkui/node_attributes/layout.h>

**Library:** libace_ndk.z.so

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Since:** 12

**Related module:** [ArkUI_NativeModule](capi-arkui-nativemodule.md)

**Sample:** <!--RP1-->[LayoutSample](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/ArkUISample/LayoutSample)<!--RP1End-->

## Summary

### Structs

| Name | typedef Keyword | Description |
| -- | -- | -- |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md) | ArkUI_AlignmentRuleOption | Defines the alignment rule of the child components in the relative container. |
| [ArkUI_GuidelineOption](capi-arkui-nativemodule-arkui-guidelineoption.md) | ArkUI_GuidelineOption | Defines guideline configuration options, which specify the ID, direction, and position of a guideline (a guideline in the **RelativeContainer** component). |
| [ArkUI_BarrierOption](capi-arkui-nativemodule-arkui-barrieroption.md) | ArkUI_BarrierOption | Defines the ID, direction, and referenced component of a barrier. |
| [ArkUI_PixelRoundPolicy](capi-arkui-nativemodule-arkui-pixelroundpolicy.md) | ArkUI_PixelRoundPolicy | Defines a component pixel rounding policy. |
| [ArkUI_PositionEdges](capi-arkui-nativemodule-arkui-positionedges.md) | ArkUI_PositionEdges | Provides position parameters relative to the boundaries of the container's content area. |

### Enums

| Name | typedef Keyword | Description |
| -- | -- | -- |
| [ArkUI_Alignment](#arkui_alignment) | ArkUI_Alignment | Enumerates the alignment modes. |
| [ArkUI_ItemAlignment](#arkui_itemalignment) | ArkUI_ItemAlignment | Enumerates the modes in which components are laid out along the cross axis of the container. |
| [ArkUI_FlexAlignment](#arkui_flexalignment) | ArkUI_FlexAlignment | Enumerates the vertical alignment modes of the flex container. |
| [ArkUI_FlexDirection](#arkui_flexdirection) | ArkUI_FlexDirection | Enumerates the directions of the main axis in the flex container. |
| [ArkUI_FlexWrap](#arkui_flexwrap) | ArkUI_FlexWrap | Enumerates the layout modes for rows and columns of the flex container. |
| [ArkUI_Direction](#arkui_direction) | ArkUI_Direction | Enumerates the modes in which components are laid out along the main axis of the container. |
| [ArkUI_Axis](#arkui_axis) | ArkUI_Axis | Enumerates the directions or the directions in which the **List** component is arranged. |
| [ArkUI_VerticalAlignment](#arkui_verticalalignment) | ArkUI_VerticalAlignment | Enumerates the vertical alignment modes. |
| [ArkUI_HorizontalAlignment](#arkui_horizontalalignment) | ArkUI_HorizontalAlignment | Enumerates the alignment mode in the horizontal direction. |
| [ArkUI_BarrierDirection](#arkui_barrierdirection) | ArkUI_BarrierDirection | Enumerates the barrier directions. |
| [ArkUI_RelativeLayoutChainStyle](#arkui_relativelayoutchainstyle) | ArkUI_RelativeLayoutChainStyle | Enumerates the chain styles. |
| [ArkUI_SafeAreaEdge](#arkui_safeareaedge) | ArkUI_SafeAreaEdge | Enumerates the edges for expanding the safe area. |
| [ArkUI_LayoutSafeAreaType](#arkui_layoutsafeareatype) | ArkUI_LayoutSafeAreaType | Enumerates the types of expanded safe areas. |
| [ArkUI_LayoutSafeAreaEdge](#arkui_layoutsafeareaedge) | ArkUI_LayoutSafeAreaEdge | Enumerates the edges for expanding the safe area. |
| [ArkUI_LocalizedAlignment](#arkui_localizedalignment) | ArkUI_LocalizedAlignment | Enumerates the alignment rules of child components in the **Stack** container. |
| [ArkUI_LayoutPolicy](#arkui_layoutpolicy) | ArkUI_LayoutPolicy | Enumerates layout policies. |
| [ArkUI_PixelRoundCalcPolicy](#arkui_pixelroundcalcpolicy) | ArkUI_PixelRoundCalcPolicy | Enumerates pixel rounding calculation policies. |

### Functions

| Name | Description |
| -- | -- |
| [ArkUI_GuidelineOption* OH_ArkUI_GuidelineOption_Create(int32_t size)](#oh_arkui_guidelineoption_create) | Creates a guideline configuration for this **RelativeContainer** component. |
| [void OH_ArkUI_GuidelineOption_Dispose(ArkUI_GuidelineOption* guideline)](#oh_arkui_guidelineoption_dispose) | Disposes of a guideline configuration. |
| [void OH_ArkUI_GuidelineOption_SetId(ArkUI_GuidelineOption* guideline, const char* value, int32_t index)](#oh_arkui_guidelineoption_setid) | Sets the ID of a guideline. |
| [void OH_ArkUI_GuidelineOption_SetDirection(ArkUI_GuidelineOption* guideline, ArkUI_Axis value, int32_t index)](#oh_arkui_guidelineoption_setdirection) | Sets the direction of a guideline. |
| [void OH_ArkUI_GuidelineOption_SetPositionStart(ArkUI_GuidelineOption* guideline, float value, int32_t index)](#oh_arkui_guidelineoption_setpositionstart) | Sets the distance between a guideline and the left or top of the container. |
| [void OH_ArkUI_GuidelineOption_SetPositionEnd(ArkUI_GuidelineOption* guideline, float value, int32_t index)](#oh_arkui_guidelineoption_setpositionend) | Sets the distance between a guideline and the right or bottom of the container. |
| [const char* OH_ArkUI_GuidelineOption_GetId(ArkUI_GuidelineOption* guideline, int32_t index)](#oh_arkui_guidelineoption_getid) | Obtains the ID of a guideline. |
| [ArkUI_Axis OH_ArkUI_GuidelineOption_GetDirection(ArkUI_GuidelineOption* guideline, int32_t index)](#oh_arkui_guidelineoption_getdirection) | Obtains the direction of a guideline. |
| [float OH_ArkUI_GuidelineOption_GetPositionStart(ArkUI_GuidelineOption* guideline, int32_t index)](#oh_arkui_guidelineoption_getpositionstart) | Obtains the distance between the guideline and the left or top of the container. |
| [float OH_ArkUI_GuidelineOption_GetPositionEnd(ArkUI_GuidelineOption* guideline, int32_t index)](#oh_arkui_guidelineoption_getpositionend) | Obtains the distance between the guideline and the right or bottom of the container. |
| [ArkUI_BarrierOption* OH_ArkUI_BarrierOption_Create(int32_t size)](#oh_arkui_barrieroption_create) | Creates a barrier configuration for this **RelativeContainer** component. |
| [void OH_ArkUI_BarrierOption_Dispose(ArkUI_BarrierOption* barrierStyle)](#oh_arkui_barrieroption_dispose) | Disposes of a barrier configuration. |
| [void OH_ArkUI_BarrierOption_SetId(ArkUI_BarrierOption* barrierStyle, const char* value, int32_t index)](#oh_arkui_barrieroption_setid) | Sets the ID of a barrier. |
| [void OH_ArkUI_BarrierOption_SetDirection(ArkUI_BarrierOption* barrierStyle, ArkUI_BarrierDirection value, int32_t index)](#oh_arkui_barrieroption_setdirection) | Sets the direction of a barrier. |
| [void OH_ArkUI_BarrierOption_SetReferencedId(ArkUI_BarrierOption* barrierStyle, const char* value, int32_t index)](#oh_arkui_barrieroption_setreferencedid) | Sets the referenced components of a barrier. |
| [const char* OH_ArkUI_BarrierOption_GetId(ArkUI_BarrierOption* barrierStyle, int32_t index)](#oh_arkui_barrieroption_getid) | Obtains the ID of a barrier. |
| [ArkUI_BarrierDirection OH_ArkUI_BarrierOption_GetDirection(ArkUI_BarrierOption* barrierStyle, int32_t index)](#oh_arkui_barrieroption_getdirection) | Obtains the direction of a barrier. |
| [const char* OH_ArkUI_BarrierOption_GetReferencedId(ArkUI_BarrierOption* barrierStyle, int32_t index , int32_t referencedIndex)](#oh_arkui_barrieroption_getreferencedid) | Obtains the referenced components of a barrier. |
| [int32_t OH_ArkUI_BarrierOption_GetReferencedIdSize(ArkUI_BarrierOption* barrierStyle, int32_t index)](#oh_arkui_barrieroption_getreferencedidsize) | Obtains the number of referenced components of a barrier. |
| [ArkUI_AlignmentRuleOption* OH_ArkUI_AlignmentRuleOption_Create()](#oh_arkui_alignmentruleoption_create) | Creates an alignment rule configuration for this **RelativeContainer** component. |
| [void OH_ArkUI_AlignmentRuleOption_Dispose(ArkUI_AlignmentRuleOption* option)](#oh_arkui_alignmentruleoption_dispose) | Disposes of an alignment rule configuration of this **RelativeContainer** component. |
| [void OH_ArkUI_AlignmentRuleOption_SetStart(ArkUI_AlignmentRuleOption* option, const char* id, ArkUI_HorizontalAlignment alignment)](#oh_arkui_alignmentruleoption_setstart) | Sets the left alignment mode of a relative layout. |
| [void OH_ArkUI_AlignmentRuleOption_SetEnd(ArkUI_AlignmentRuleOption* option, const char* id, ArkUI_HorizontalAlignment alignment)](#oh_arkui_alignmentruleoption_setend) | Sets the right alignment mode of a relative layout. |
| [void OH_ArkUI_AlignmentRuleOption_SetCenterHorizontal(ArkUI_AlignmentRuleOption* option, const char* id, ArkUI_HorizontalAlignment alignment)](#oh_arkui_alignmentruleoption_setcenterhorizontal) | Sets the horizontal center alignment mode of a relative layout. |
| [void OH_ArkUI_AlignmentRuleOption_SetTop(ArkUI_AlignmentRuleOption* option, const char* id, ArkUI_VerticalAlignment alignment)](#oh_arkui_alignmentruleoption_settop) | Sets the top alignment mode of a relative layout. |
| [void OH_ArkUI_AlignmentRuleOption_SetBottom(ArkUI_AlignmentRuleOption* option, const char* id, ArkUI_VerticalAlignment alignment)](#oh_arkui_alignmentruleoption_setbottom) | Sets the bottom alignment mode of a relative layout. |
| [void OH_ArkUI_AlignmentRuleOption_SetCenterVertical(ArkUI_AlignmentRuleOption* option, const char* id, ArkUI_VerticalAlignment alignment)](#oh_arkui_alignmentruleoption_setcentervertical) | Sets the vertical center alignment mode of a relative layout. |
| [void OH_ArkUI_AlignmentRuleOption_SetBiasHorizontal(ArkUI_AlignmentRuleOption* option, float horizontal)](#oh_arkui_alignmentruleoption_setbiashorizontal) | Sets the bias value of the component in the horizontal direction under the anchor constraints. |
| [void OH_ArkUI_AlignmentRuleOption_SetBiasVertical(ArkUI_AlignmentRuleOption* option, float vertical)](#oh_arkui_alignmentruleoption_setbiasvertical) | Sets the bias value of the component in the vertical direction under the anchor constraints. |
| [const char* OH_ArkUI_AlignmentRuleOption_GetStartId(ArkUI_AlignmentRuleOption* option)](#oh_arkui_alignmentruleoption_getstartid) | Obtains the ID in left alignment parameters. |
| [ArkUI_HorizontalAlignment OH_ArkUI_AlignmentRuleOption_GetStartAlignment(ArkUI_AlignmentRuleOption* option)](#oh_arkui_alignmentruleoption_getstartalignment) | Obtains the alignment mode in left alignment parameters. |
| [const char* OH_ArkUI_AlignmentRuleOption_GetEndId(ArkUI_AlignmentRuleOption* option)](#oh_arkui_alignmentruleoption_getendid) | Obtains the ID in right alignment parameters. |
| [ArkUI_HorizontalAlignment OH_ArkUI_AlignmentRuleOption_GetEndAlignment(ArkUI_AlignmentRuleOption* option)](#oh_arkui_alignmentruleoption_getendalignment) | Obtains the alignment mode in right alignment parameters. |
| [const char* OH_ArkUI_AlignmentRuleOption_GetCenterIdHorizontal(ArkUI_AlignmentRuleOption* option)](#oh_arkui_alignmentruleoption_getcenteridhorizontal) | Obtains the ID in horizontal center alignment parameters. |
| [ArkUI_HorizontalAlignment OH_ArkUI_AlignmentRuleOption_GetCenterAlignmentHorizontal(ArkUI_AlignmentRuleOption* option)](#oh_arkui_alignmentruleoption_getcenteralignmenthorizontal) | Obtains the alignment mode in horizontal center alignment parameters. |
| [const char* OH_ArkUI_AlignmentRuleOption_GetTopId(ArkUI_AlignmentRuleOption* option)](#oh_arkui_alignmentruleoption_gettopid) | Obtains the ID in top alignment parameters. |
| [ArkUI_VerticalAlignment OH_ArkUI_AlignmentRuleOption_GetTopAlignment(ArkUI_AlignmentRuleOption* option)](#oh_arkui_alignmentruleoption_gettopalignment) | Obtains the alignment mode in top alignment parameters. |
| [const char* OH_ArkUI_AlignmentRuleOption_GetBottomId(ArkUI_AlignmentRuleOption* option)](#oh_arkui_alignmentruleoption_getbottomid) | Obtains the ID in bottom alignment parameters. |
| [ArkUI_VerticalAlignment OH_ArkUI_AlignmentRuleOption_GetBottomAlignment(ArkUI_AlignmentRuleOption* option)](#oh_arkui_alignmentruleoption_getbottomalignment) | Obtains the alignment mode in bottom alignment parameters. |
| [const char* OH_ArkUI_AlignmentRuleOption_GetCenterIdVertical(ArkUI_AlignmentRuleOption* option)](#oh_arkui_alignmentruleoption_getcenteridvertical) | Obtains the ID in vertical center alignment parameters. |
| [ArkUI_VerticalAlignment OH_ArkUI_AlignmentRuleOption_GetCenterAlignmentVertical(ArkUI_AlignmentRuleOption* option)](#oh_arkui_alignmentruleoption_getcenteralignmentvertical) | Obtains the alignment mode in vertical center alignment parameters. |
| [float OH_ArkUI_AlignmentRuleOption_GetBiasHorizontal(ArkUI_AlignmentRuleOption* option)](#oh_arkui_alignmentruleoption_getbiashorizontal) | Obtains the bias value in the horizontal direction. |
| [float OH_ArkUI_AlignmentRuleOption_GetBiasVertical(ArkUI_AlignmentRuleOption* option)](#oh_arkui_alignmentruleoption_getbiasvertical) | Obtains the bias value in the vertical direction. |
| [ArkUI_PositionEdges* OH_ArkUI_PositionEdges_Create()](#oh_arkui_positionedges_create) | Creates a **PositionEdges** object. |
| [ArkUI_PositionEdges* OH_ArkUI_PositionEdges_Copy(const ArkUI_PositionEdges* edges)](#oh_arkui_positionedges_copy) | Deeply copies a **PositionEdges** object. |
| [void OH_ArkUI_PositionEdges_Dispose(ArkUI_PositionEdges* edges)](#oh_arkui_positionedges_dispose) | Disposes of the **PositionEdges** object. |
| [void OH_ArkUI_PositionEdges_SetTop(ArkUI_PositionEdges* edges, float value)](#oh_arkui_positionedges_settop) | Sets the value of the **PositionEdges** object in the top direction. |
| [int32_t OH_ArkUI_PositionEdges_GetTop(ArkUI_PositionEdges* edges, float* value)](#oh_arkui_positionedges_gettop) | Obtains the value of the **PositionEdges** object in the top direction. |
| [void OH_ArkUI_PositionEdges_SetLeft(ArkUI_PositionEdges* edges, float value)](#oh_arkui_positionedges_setleft) | Sets the value of the **PositionEdges** object in the left direction. |
| [int32_t OH_ArkUI_PositionEdges_GetLeft(ArkUI_PositionEdges* edges, float* value)](#oh_arkui_positionedges_getleft) | Obtains the value of the **PositionEdges** object in the left direction. |
| [void OH_ArkUI_PositionEdges_SetBottom(ArkUI_PositionEdges* edges, float value)](#oh_arkui_positionedges_setbottom) | Sets the value of the **PositionEdges** object in the bottom direction. |
| [int32_t OH_ArkUI_PositionEdges_GetBottom(ArkUI_PositionEdges* edges, float* value)](#oh_arkui_positionedges_getbottom) | Obtains the value of the **PositionEdges** object in the bottom direction. |
| [void OH_ArkUI_PositionEdges_SetRight(ArkUI_PositionEdges* edges, float value)](#oh_arkui_positionedges_setright) | Sets the value of the **PositionEdges** object in the right direction. |
| [int32_t OH_ArkUI_PositionEdges_GetRight(ArkUI_PositionEdges* edges, float* value)](#oh_arkui_positionedges_getright) | Obtains the value of the **PositionEdges** object in the right direction. |
| [ArkUI_PixelRoundPolicy* OH_ArkUI_PixelRoundPolicy_Create()](#oh_arkui_pixelroundpolicy_create) | Creates a **PixelRoundPolicy** object. |
| [void OH_ArkUI_PixelRoundPolicy_Dispose(ArkUI_PixelRoundPolicy* policy)](#oh_arkui_pixelroundpolicy_dispose) | Disposes of the **PixelRoundPolicy** object. |
| [void OH_ArkUI_PixelRoundPolicy_SetTop(ArkUI_PixelRoundPolicy* policy, ArkUI_PixelRoundCalcPolicy value)](#oh_arkui_pixelroundpolicy_settop) | Sets the top edge pixel rounding policy for the **PixelRoundPolicy** object. |
| [int32_t OH_ArkUI_PixelRoundPolicy_GetTop(ArkUI_PixelRoundPolicy* policy, ArkUI_PixelRoundCalcPolicy* value)](#oh_arkui_pixelroundpolicy_gettop) | Obtains the top edge pixel rounding policy from the **PixelRoundPolicy** object. |
| [void OH_ArkUI_PixelRoundPolicy_SetStart(ArkUI_PixelRoundPolicy* policy, ArkUI_PixelRoundCalcPolicy value)](#oh_arkui_pixelroundpolicy_setstart) | Sets the start edge pixel rounding policy for the **PixelRoundPolicy** object. |
| [int32_t OH_ArkUI_PixelRoundPolicy_GetStart(ArkUI_PixelRoundPolicy* policy, ArkUI_PixelRoundCalcPolicy* value)](#oh_arkui_pixelroundpolicy_getstart) | Obtains the start edge pixel rounding policy from the **PixelRoundPolicy** object. |
| [void OH_ArkUI_PixelRoundPolicy_SetBottom(ArkUI_PixelRoundPolicy* policy, ArkUI_PixelRoundCalcPolicy value)](#oh_arkui_pixelroundpolicy_setbottom) | Sets the bottom edge pixel rounding policy for the **PixelRoundPolicy** object. |
| [int32_t OH_ArkUI_PixelRoundPolicy_GetBottom(ArkUI_PixelRoundPolicy* policy, ArkUI_PixelRoundCalcPolicy* value)](#oh_arkui_pixelroundpolicy_getbottom) | Obtains the bottom edge pixel rounding policy from the **PixelRoundPolicy** object. |
| [void OH_ArkUI_PixelRoundPolicy_SetEnd(ArkUI_PixelRoundPolicy* policy, ArkUI_PixelRoundCalcPolicy value)](#oh_arkui_pixelroundpolicy_setend) | Sets the end edge pixel rounding policy for the **PixelRoundPolicy** object. |
| [int32_t OH_ArkUI_PixelRoundPolicy_GetEnd(ArkUI_PixelRoundPolicy* policy, ArkUI_PixelRoundCalcPolicy* value)](#oh_arkui_pixelroundpolicy_getend) | Obtains the end edge pixel rounding policy from the **PixelRoundPolicy** object. |

## Enum Description

### ArkUI_Alignment

```c
enum ArkUI_Alignment
```

**Description**

Enumerates the alignment modes.

**Since:** 12

| Value | Description |
| -- | -- |
| ARKUI_ALIGNMENT_TOP_START = 0 | Top start. This is the default value. |
| ARKUI_ALIGNMENT_TOP | Top center. |
| ARKUI_ALIGNMENT_TOP_END | Top end. |
| ARKUI_ALIGNMENT_START | Vertically centered start. |
| ARKUI_ALIGNMENT_CENTER | Horizontally and vertically centered. |
| ARKUI_ALIGNMENT_END | Vertically centered end. |
| ARKUI_ALIGNMENT_BOTTOM_START | Bottom start. |
| ARKUI_ALIGNMENT_BOTTOM | Horizontally centered on the bottom. |
| ARKUI_ALIGNMENT_BOTTOM_END | Bottom end. |

### ArkUI_ItemAlignment

```c
enum ArkUI_ItemAlignment
```

**Description**

Enumerates the modes in which components are laid out along the cross axis of the container.

**Since:** 12

| Value | Description |
| -- | -- |
| ARKUI_ITEM_ALIGNMENT_AUTO = 0 | The default configuration in the flex container is used. This is the default value. |
| ARKUI_ITEM_ALIGNMENT_START | The items in the flex container are aligned with the cross-start edge. |
| ARKUI_ITEM_ALIGNMENT_CENTER | The items in the flex container are centered along the cross axis. |
| ARKUI_ITEM_ALIGNMENT_END | The items in the flex container are aligned with the cross-end edge. |
| ARKUI_ITEM_ALIGNMENT_STRETCH | The items in the flex container are stretched and padded along the cross axis. |
| ARKUI_ITEM_ALIGNMENT_BASELINE | The items in the flex container are aligned in such a manner that their text baselines are aligned along the cross axis. |

### ArkUI_FlexAlignment

```c
enum ArkUI_FlexAlignment
```

**Description**

Enumerates the vertical alignment modes of the flex container.

**Since:** 12

| Value | Description |
| -- | -- |
| ARKUI_FLEX_ALIGNMENT_START = 1 | The child components are aligned with the start edge of the main axis. This is the default value. |
| ARKUI_FLEX_ALIGNMENT_CENTER = 2 | The child components are aligned in the center of the main axis. |
| ARKUI_FLEX_ALIGNMENT_END = 3 | The child components are aligned with the end edge of the main axis. |
| ARKUI_FLEX_ALIGNMENT_SPACE_BETWEEN = 6 | The child components are evenly distributed along the main axis. The space between any two adjacent components is the same. The first component is aligned with the main-start, and the last component is aligned with the main-end. |
| ARKUI_FLEX_ALIGNMENT_SPACE_AROUND = 7 | The child components are evenly distributed along the main axis. The space between any two adjacent components is the same. The space between the first component and main-start is half the size of the space between two adjacent components. |
| ARKUI_FLEX_ALIGNMENT_SPACE_EVENLY = 8 | The child components are evenly distributed along the main axis. The space between the first component and main-start, the space between the last component and main-end, and the space between any two adjacent components are the same. |

### ArkUI_FlexDirection

```c
enum ArkUI_FlexDirection
```

**Description**

Enumerates the directions of the main axis in the flex container.

**Since:** 12

| Value | Description |
| -- | -- |
| ARKUI_FLEX_DIRECTION_ROW = 0 | The child components are arranged in the same direction as the main axis runs down the rows. This is the default value. |
| ARKUI_FLEX_DIRECTION_COLUMN | The child components are arranged in the same direction as the main axis runs down the columns. |
| ARKUI_FLEX_DIRECTION_ROW_REVERSE | The child components are arranged opposite to the **ROW** direction. |
| ARKUI_FLEX_DIRECTION_COLUMN_REVERSE | The child components are arranged opposite to the **COLUMN** direction. |

### ArkUI_FlexWrap

```c
enum ArkUI_FlexWrap
```

**Description**

Enumerates the layout modes for rows and columns of the flex container.

**Since:** 12

| Value | Description |
| -- | -- |
| ARKUI_FLEX_WRAP_NO_WRAP = 0 | The child components in the flex container are arranged in a single row/column, and they cannot overflow. This is the default value. |
| ARKUI_FLEX_WRAP_WRAP | The child components in the flex container are arranged in multiple rows/columns, and they may overflow. |
| ARKUI_FLEX_WRAP_WRAP_REVERSE | The child components in the flex container are reversely arranged in multiple rows/columns, and they may overflow. |

### ArkUI_Direction

```c
enum ArkUI_Direction
```

**Description**

Enumerates the modes in which components are laid out along the main axis of the container.

**Since:** 12

| Value | Description |
| -- | -- |
| ARKUI_DIRECTION_LTR = 0 | Components are arranged from left to right. This is the default value. |
| ARKUI_DIRECTION_RTL | Components are arranged from right to left. |
| ARKUI_DIRECTION_AUTO = 3 | The system layout direction is used. |

### ArkUI_Axis

```c
enum ArkUI_Axis
```

**Description**

Enumerates the directions or the directions in which the [List](./arkui-ts/ts-container-list.md) component is arranged.

**Since:** 12

| Value | Description |
| -- | -- |
| ARKUI_AXIS_VERTICAL = 0 | Vertical direction, or vertical scrolling only. This is the default value. |
| ARKUI_AXIS_HORIZONTAL | Horizontal direction, or horizontal scrolling only. |

### ArkUI_VerticalAlignment

```c
enum ArkUI_VerticalAlignment
```

**Description**

Enumerates the vertical alignment modes.

**Since:** 12

| Value | Description |
| -- | -- |
| ARKUI_VERTICAL_ALIGNMENT_TOP = 0 | Top aligned. |
| ARKUI_VERTICAL_ALIGNMENT_CENTER | Aligned with the center. This is the default alignment mode. |
| ARKUI_VERTICAL_ALIGNMENT_BOTTOM | Bottom aligned. |

### ArkUI_HorizontalAlignment

```c
enum ArkUI_HorizontalAlignment
```

**Description**

Enumerates the alignment mode in the horizontal direction.

**Since:** 12

| Value | Description |
| -- | -- |
| ARKUI_HORIZONTAL_ALIGNMENT_START = 0 | Aligned with the start edge in the same direction as the language in use. |
| ARKUI_HORIZONTAL_ALIGNMENT_CENTER | Aligned with the center. This is the default alignment mode. |
| ARKUI_HORIZONTAL_ALIGNMENT_END | Aligned with the end edge in the same direction as the language in use. |

### ArkUI_BarrierDirection

```c
enum ArkUI_BarrierDirection
```

**Description**

Enumerates the barrier directions.

**Since:** 12

| Value | Description |
| -- | -- |
| ARKUI_BARRIER_DIRECTION_START = 0 | The barrier is on the left side of all the referenced components specified by **referencedId**. |
| ARKUI_BARRIER_DIRECTION_END | The barrier is on the right side of all the referenced components specified by **referencedId**. |
| ARKUI_BARRIER_DIRECTION_TOP | The barrier is at the top of all the referenced components specified by **referencedId**. |
| ARKUI_BARRIER_DIRECTION_BOTTOM | The barrier is at the bottom of all the referenced components specified by **referencedId**. |

### ArkUI_RelativeLayoutChainStyle

```c
enum ArkUI_RelativeLayoutChainStyle
```

**Description**

Enumerates the chain styles.

**Since:** 12

| Value | Description |
| -- | -- |
| ARKUI_RELATIVE_LAYOUT_CHAIN_STYLE_SPREAD = 0 | Child components are evenly distributed among constraint anchors. This is the default value. |
| ARKUI_RELATIVE_LAYOUT_CHAIN_STYLE_SPREAD_INSIDE | All child components except the first and last ones are evenly distributed among constraint anchors. |
| ARKUI_RELATIVE_LAYOUT_CHAIN_STYLE_PACKED | There is no gap between child components in the chain. |

### ArkUI_SafeAreaEdge

```c
enum ArkUI_SafeAreaEdge
```

**Description**

Enumerates the edges for expanding the safe area.

**Since:** 12

| Value | Description |
| -- | -- |
| ARKUI_SAFE_AREA_EDGE_TOP = 1 | Top edge. This is the default value. |
| ARKUI_SAFE_AREA_EDGE_BOTTOM = 1 << 1 | Bottom edge. |
| ARKUI_SAFE_AREA_EDGE_START = 1 << 2 | Front edge. |
| ARKUI_SAFE_AREA_EDGE_END = 1 << 3 | End edge. |

### ArkUI_LayoutSafeAreaType

```c
enum ArkUI_LayoutSafeAreaType
```

**Description**

Enumerates the types of expanded safe areas.

**Since:** 23

| Value | Description |
| -- | -- |
| ARKUI_LAYOUT_SAFE_AREA_TYPE_SYSTEM = 1 | Default non-safe area of the system, including the status bar and navigation bar. |

### ArkUI_LayoutSafeAreaEdge

```c
enum ArkUI_LayoutSafeAreaEdge
```

**Description**

Enumerates the edges for expanding the safe area.

**Since:** 23

| Value | Description |
| -- | -- |
| ARKUI_LAYOUT_SAFE_AREA_EDGE_TOP = 1 | Top edge. |
| ARKUI_LAYOUT_SAFE_AREA_EDGE_BOTTOM = 1 << 1 | Bottom edge. |
| ARKUI_LAYOUT_SAFE_AREA_EDGE_START = 1 << 2 | Start edge. |
| ARKUI_LAYOUT_SAFE_AREA_EDGE_END = 1 << 3 | End edge. |
| ARKUI_LAYOUT_SAFE_AREA_EDGE_VERTICAL = ARKUI_LAYOUT_SAFE_AREA_EDGE_TOP \| ARKUI_LAYOUT_SAFE_AREA_EDGE_BOTTOM | Vertical edge. |
| ARKUI_LAYOUT_SAFE_AREA_EDGE_HORIZONTAL = ARKUI_LAYOUT_SAFE_AREA_EDGE_START \| ARKUI_LAYOUT_SAFE_AREA_EDGE_END | Horizontal edge. |
| ARKUI_LAYOUT_SAFE_AREA_EDGE_ALL = ARKUI_LAYOUT_SAFE_AREA_EDGE_VERTICAL \| ARKUI_LAYOUT_SAFE_AREA_EDGE_HORIZONTAL | All edges. |

### ArkUI_LocalizedAlignment

```c
enum ArkUI_LocalizedAlignment
```

**Description**

Enumerates the alignment rules of child components in the **Stack** container.

**Since:** 23

| Value | Description |
| -- | -- |
| ARKUI_LOCALIZED_ALIGNMENT_TOP_START = 0 | Top start. |
| ARKUI_LOCALIZED_ALIGNMENT_TOP | Top center. |
| ARKUI_LOCALIZED_ALIGNMENT_TOP_END | Top end. |
| ARKUI_LOCALIZED_ALIGNMENT_START | Vertically centered start. |
| ARKUI_LOCALIZED_ALIGNMENT_CENTER | Horizontally and vertically centered. |
| ARKUI_LOCALIZED_ALIGNMENT_END | Vertically centered end. |
| ARKUI_LOCALIZED_ALIGNMENT_BOTTOM_START | Bottom start. |
| ARKUI_LOCALIZED_ALIGNMENT_BOTTOM | Horizontally centered on the bottom. |
| ARKUI_LOCALIZED_ALIGNMENT_BOTTOM_END | Bottom end. |

### ArkUI_LayoutPolicy

```c
enum ArkUI_LayoutPolicy
```

**Description**

Enumerates layout policies.

**Since:** 21

| Value | Description |
| -- | -- |
| ARKUI_LAYOUTPOLICY_MATCHPARENT = 0 | The component size matches parent container dimensions. |
| ARKUI_LAYOUTPOLICY_WRAPCONTENT | The component size wraps its content, constrained by parent container bounds. |
| ARKUI_LAYOUTPOLICY_FIXATIDEALSIZE | The component size wraps its content, unconstrained by parent container bounds. |

### ArkUI_PixelRoundCalcPolicy

```c
enum ArkUI_PixelRoundCalcPolicy
```

**Description**

Enumerates pixel rounding calculation policies.

**Since:** 21

| Value | Description |
| -- | -- |
| ARKUI_PIXELROUNDCALCPOLICY_NOFORCEROUND = 0 | No forced rounding calculation. |
| ARKUI_PIXELROUNDCALCPOLICY_FORCECEIL | Round-up calculation. |
| ARKUI_PIXELROUNDCALCPOLICY_FORCEFLOOR | Round-down calculation. |

## Function Description

### OH_ArkUI_GuidelineOption_Create()

```c
ArkUI_GuidelineOption* OH_ArkUI_GuidelineOption_Create(int32_t size)
```

**Description**

Creates a guideline configuration for this **RelativeContainer** component.

**Since:** 12

**Parameters**

| Name | Description |
| -- | -- |
| int32_t size | Number of guidelines. |

**Returns**

| Type | Description |
| -- | -- |
| [ArkUI_GuidelineOption*](capi-arkui-nativemodule-arkui-guidelineoption.md) | Pointer to a guideline configuration. |

### OH_ArkUI_GuidelineOption_Dispose()

```c
void OH_ArkUI_GuidelineOption_Dispose(ArkUI_GuidelineOption* guideline)
```

**Description**

Disposes of a guideline configuration.

**Since:** 12

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_GuidelineOption](capi-arkui-nativemodule-arkui-guidelineoption.md)* guideline | Pointer to a guideline configuration. |

### OH_ArkUI_GuidelineOption_SetId()

```c
void OH_ArkUI_GuidelineOption_SetId(ArkUI_GuidelineOption* guideline, const char* value, int32_t index)
```

**Description**

Sets the ID of a guideline.

**Since:** 12

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_GuidelineOption](capi-arkui-nativemodule-arkui-guidelineoption.md)* guideline | Pointer to a guideline configuration. |
| const char* value | Pointer to the ID, which must be unique and cannot be the same as the name of any component in the container. |
| int32_t index | Index of the guideline. |

### OH_ArkUI_GuidelineOption_SetDirection()

```c
void OH_ArkUI_GuidelineOption_SetDirection(ArkUI_GuidelineOption* guideline, ArkUI_Axis value, int32_t index)
```

**Description**

Sets the direction of a guideline.

**Since:** 12

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_GuidelineOption](capi-arkui-nativemodule-arkui-guidelineoption.md)* guideline | Pointer to a guideline configuration. |
| [ArkUI_Axis](capi-layout-h.md#arkui_axis) value | Direction. |
| int32_t index | Index of the guideline. |

### OH_ArkUI_GuidelineOption_SetPositionStart()

```c
void OH_ArkUI_GuidelineOption_SetPositionStart(ArkUI_GuidelineOption* guideline, float value, int32_t index)
```

**Description**

Sets the distance between a guideline and the left or top of the container.

**Since:** 12

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_GuidelineOption](capi-arkui-nativemodule-arkui-guidelineoption.md)* guideline | Pointer to a guideline configuration. |
| float value | Distance between the guideline and the left or top of the container. |
| int32_t index | Index of the guideline. |

### OH_ArkUI_GuidelineOption_SetPositionEnd()

```c
void OH_ArkUI_GuidelineOption_SetPositionEnd(ArkUI_GuidelineOption* guideline, float value, int32_t index)
```

**Description**

Sets the distance between a guideline and the right or bottom of the container.

**Since:** 12

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_GuidelineOption](capi-arkui-nativemodule-arkui-guidelineoption.md)* guideline | Pointer to a guideline configuration. |
| float value | Distance between the guideline and the right or bottom of the container. |
| int32_t index | Index of the guideline. |

### OH_ArkUI_GuidelineOption_GetId()

```c
const char* OH_ArkUI_GuidelineOption_GetId(ArkUI_GuidelineOption* guideline, int32_t index)
```

**Description**

Obtains the ID of a guideline.

**Since:** 12

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_GuidelineOption](capi-arkui-nativemodule-arkui-guidelineoption.md)* guideline | Pointer to a guideline configuration. |
| int32_t index | Index of the guideline. |

**Returns**

| Type | Description |
| -- | -- |
| const char* | Pointer to the ID. |

### OH_ArkUI_GuidelineOption_GetDirection()

```c
ArkUI_Axis OH_ArkUI_GuidelineOption_GetDirection(ArkUI_GuidelineOption* guideline, int32_t index)
```

**Description**

Obtains the direction of a guideline.

**Since:** 12

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_GuidelineOption](capi-arkui-nativemodule-arkui-guidelineoption.md)* guideline | Pointer to a guideline configuration. |
| int32_t index | Index of the guideline. |

**Returns**

| Type | Description |
| -- | -- |
| [ArkUI_Axis](capi-layout-h.md#arkui_axis) | Direction. |

### OH_ArkUI_GuidelineOption_GetPositionStart()

```c
float OH_ArkUI_GuidelineOption_GetPositionStart(ArkUI_GuidelineOption* guideline, int32_t index)
```

**Description**

Obtains the distance between the guideline and the left or top of the container.

**Since:** 12

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_GuidelineOption](capi-arkui-nativemodule-arkui-guidelineoption.md)* guideline | Pointer to a guideline configuration. |
| int32_t index | Index of the guideline. |

**Returns**

| Type | Description |
| -- | -- |
| float | Distance between the guideline and the left or top of the container. The unit is vp. |

### OH_ArkUI_GuidelineOption_GetPositionEnd()

```c
float OH_ArkUI_GuidelineOption_GetPositionEnd(ArkUI_GuidelineOption* guideline, int32_t index)
```

**Description**

Obtains the distance between the guideline and the right or bottom of the container.

**Since:** 12

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_GuidelineOption](capi-arkui-nativemodule-arkui-guidelineoption.md)* guideline | Pointer to a guideline configuration. |
| int32_t index | Index of the guideline. |

**Returns**

| Type | Description |
| -- | -- |
| float | Distance between the guideline and the right or bottom of the container. The unit is vp. |

### OH_ArkUI_BarrierOption_Create()

```c
ArkUI_BarrierOption* OH_ArkUI_BarrierOption_Create(int32_t size)
```

**Description**

Creates a barrier configuration for this **RelativeContainer** component.

**Since:** 12

**Parameters**

| Name | Description |
| -- | -- |
| int32_t size | Number of barriers. |

**Returns**

| Type | Description |
| -- | -- |
| [ArkUI_BarrierOption*](capi-arkui-nativemodule-arkui-barrieroption.md) | Pointer to a barrier configuration. |

### OH_ArkUI_BarrierOption_Dispose()

```c
void OH_ArkUI_BarrierOption_Dispose(ArkUI_BarrierOption* barrierStyle)
```

**Description**

Disposes of a barrier configuration.

**Since:** 12

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_BarrierOption](capi-arkui-nativemodule-arkui-barrieroption.md)* barrierStyle | Pointer to a barrier configuration. |

### OH_ArkUI_BarrierOption_SetId()

```c
void OH_ArkUI_BarrierOption_SetId(ArkUI_BarrierOption* barrierStyle, const char* value, int32_t index)
```

**Description**

Sets the ID of a barrier.

**Since:** 12

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_BarrierOption](capi-arkui-nativemodule-arkui-barrieroption.md)* barrierStyle | Pointer to a barrier configuration. |
| const char* value | Pointer to the ID, which must be unique and cannot be the same as the name of any component in the container. |
| int32_t index | Index of the barrier. |

### OH_ArkUI_BarrierOption_SetDirection()

```c
void OH_ArkUI_BarrierOption_SetDirection(ArkUI_BarrierOption* barrierStyle, ArkUI_BarrierDirection value, int32_t index)
```

**Description**

Sets the direction of a barrier.

**Since:** 12

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_BarrierOption](capi-arkui-nativemodule-arkui-barrieroption.md)* barrierStyle | Pointer to a barrier configuration. |
| [ArkUI_BarrierDirection](capi-layout-h.md#arkui_barrierdirection) value | Direction. |
| int32_t index | Index of the barrier. |

### OH_ArkUI_BarrierOption_SetReferencedId()

```c
void OH_ArkUI_BarrierOption_SetReferencedId(ArkUI_BarrierOption* barrierStyle, const char* value, int32_t index)
```

**Description**

Sets the referenced components of a barrier.

**Since:** 12

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_BarrierOption](capi-arkui-nativemodule-arkui-barrieroption.md)* barrierStyle | Pointer to a barrier configuration. |
| const char* value | Pointer to the referenced component ID array. |
| int32_t index | Index of the barrier. |

### OH_ArkUI_BarrierOption_GetId()

```c
const char* OH_ArkUI_BarrierOption_GetId(ArkUI_BarrierOption* barrierStyle, int32_t index)
```

**Description**

Obtains the ID of a barrier.

**Since:** 12

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_BarrierOption](capi-arkui-nativemodule-arkui-barrieroption.md)* barrierStyle | Pointer to a barrier configuration. |
| int32_t index | Index of the barrier. |

**Returns**

| Type | Description |
| -- | -- |
| const char* | Pointer to the ID of the barrier. |

### OH_ArkUI_BarrierOption_GetDirection()

```c
ArkUI_BarrierDirection OH_ArkUI_BarrierOption_GetDirection(ArkUI_BarrierOption* barrierStyle, int32_t index)
```

**Description**

Obtains the direction of a barrier.

**Since:** 12

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_BarrierOption](capi-arkui-nativemodule-arkui-barrieroption.md)* barrierStyle | Pointer to a barrier configuration. |
| int32_t index | Index of the barrier. |

**Returns**

| Type | Description |
| -- | -- |
| [ArkUI_BarrierDirection](capi-layout-h.md#arkui_barrierdirection) | Direction of the barrier. |

### OH_ArkUI_BarrierOption_GetReferencedId()

```c
const char* OH_ArkUI_BarrierOption_GetReferencedId(ArkUI_BarrierOption* barrierStyle, int32_t index , int32_t referencedIndex)
```

**Description**

Obtains the referenced components of a barrier.

**Since:** 12

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_BarrierOption](capi-arkui-nativemodule-arkui-barrieroption.md)* barrierStyle | Pointer to a barrier configuration. |
| index | Index of the barrier. |
| int32_t referencedIndex | Index of the referenced component ID. |

**Returns**

| Type | Description |
| -- | -- |
| const char* | Pointer to the referenced component array of the barrier. |

### OH_ArkUI_BarrierOption_GetReferencedIdSize()

```c
int32_t OH_ArkUI_BarrierOption_GetReferencedIdSize(ArkUI_BarrierOption* barrierStyle, int32_t index)
```

**Description**

Obtains the number of referenced components of a barrier.

**Since:** 12

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_BarrierOption](capi-arkui-nativemodule-arkui-barrieroption.md)* barrierStyle | Pointer to a barrier configuration. |
| int32_t index | Index of the barrier. |

**Returns**

| Type | Description |
| -- | -- |
| int32_t | Number of referenced components of the barrier. |

### OH_ArkUI_AlignmentRuleOption_Create()

```c
ArkUI_AlignmentRuleOption* OH_ArkUI_AlignmentRuleOption_Create()
```

**Description**

Creates an alignment rule configuration for this **RelativeContainer** component.

**Since:** 12

**Returns**

| Type | Description |
| -- | -- |
| [ArkUI_AlignmentRuleOption*](capi-arkui-nativemodule-arkui-alignmentruleoption.md) | Pointer to the alignment rule configuration. |

### OH_ArkUI_AlignmentRuleOption_Dispose()

```c
void OH_ArkUI_AlignmentRuleOption_Dispose(ArkUI_AlignmentRuleOption* option)
```

**Description**

Disposes of an alignment rule configuration of this **RelativeContainer** component.

**Since:** 12

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)* option | Pointer to an alignment rule configuration. |

### OH_ArkUI_AlignmentRuleOption_SetStart()

```c
void OH_ArkUI_AlignmentRuleOption_SetStart(ArkUI_AlignmentRuleOption* option, const char* id, ArkUI_HorizontalAlignment alignment)
```

**Description**

Sets the left alignment mode of a relative layout.

**Since:** 12

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)* option | Pointer to an alignment rule configuration. |
| const char* id | Pointer to the ID of the left-aligned anchor component. |
| value | Alignment mode relative to the anchor component. |

### OH_ArkUI_AlignmentRuleOption_SetEnd()

```c
void OH_ArkUI_AlignmentRuleOption_SetEnd(ArkUI_AlignmentRuleOption* option, const char* id, ArkUI_HorizontalAlignment alignment)
```

**Description**

Sets the right alignment mode of a relative layout.

**Since:** 12

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)* option | Pointer to an alignment rule configuration. |
| const char* id | Pointer to the ID of the right-aligned anchor component. |
| value | Alignment mode relative to the anchor component. |

### OH_ArkUI_AlignmentRuleOption_SetCenterHorizontal()

```c
void OH_ArkUI_AlignmentRuleOption_SetCenterHorizontal(ArkUI_AlignmentRuleOption* option, const char* id, ArkUI_HorizontalAlignment alignment)
```

**Description**

Sets the horizontal center alignment mode of a relative layout.

**Since:** 12

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)* option | Pointer to an alignment rule configuration. |
| const char* id | Pointer to the ID of the horizontally-centered anchor component. |
| value | Alignment mode relative to the anchor component. |

### OH_ArkUI_AlignmentRuleOption_SetTop()

```c
void OH_ArkUI_AlignmentRuleOption_SetTop(ArkUI_AlignmentRuleOption* option, const char* id, ArkUI_VerticalAlignment alignment)
```

**Description**

Sets the top alignment mode of a relative layout.

**Since:** 12

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)* option | Pointer to an alignment rule configuration. |
| const char* id | Pointer to the ID of the top-aligned anchor component. |
| value | Alignment mode relative to the anchor component. |

### OH_ArkUI_AlignmentRuleOption_SetBottom()

```c
void OH_ArkUI_AlignmentRuleOption_SetBottom(ArkUI_AlignmentRuleOption* option, const char* id, ArkUI_VerticalAlignment alignment)
```

**Description**

Sets the bottom alignment mode of a relative layout.

**Since:** 12

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)* option | Pointer to an alignment rule configuration. |
| const char* id | Pointer to the ID of the bottom-aligned anchor component. |
| value | Alignment mode relative to the anchor component. |

### OH_ArkUI_AlignmentRuleOption_SetCenterVertical()

```c
void OH_ArkUI_AlignmentRuleOption_SetCenterVertical(ArkUI_AlignmentRuleOption* option, const char* id, ArkUI_VerticalAlignment alignment)
```

**Description**

Sets the vertical center alignment mode of a relative layout.

**Since:** 12

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)* option | Pointer to an alignment rule configuration. |
| const char* id | Pointer to the ID of the vertically-centered anchor component. |
| value | Alignment mode relative to the anchor component. |

### OH_ArkUI_AlignmentRuleOption_SetBiasHorizontal()

```c
void OH_ArkUI_AlignmentRuleOption_SetBiasHorizontal(ArkUI_AlignmentRuleOption* option, float horizontal)
```

**Description**

Sets the bias value of the component in the horizontal direction under the anchor constraints.

**Since:** 12

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)* option | Pointer to an alignment rule configuration. |
| float horizontal | Bias value in the horizontal direction. |

### OH_ArkUI_AlignmentRuleOption_SetBiasVertical()

```c
void OH_ArkUI_AlignmentRuleOption_SetBiasVertical(ArkUI_AlignmentRuleOption* option, float vertical)
```

**Description**

Sets the bias value of the component in the vertical direction under the anchor constraints.

**Since:** 12

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)* option | Pointer to an alignment rule configuration. |
| horizontal | Bias value in the vertical direction. |

### OH_ArkUI_AlignmentRuleOption_GetStartId()

```c
const char* OH_ArkUI_AlignmentRuleOption_GetStartId(ArkUI_AlignmentRuleOption* option)
```

**Description**

Obtains the ID in left alignment parameters.

**Since:** 12

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)* option | Pointer to an alignment rule configuration. |

**Returns**

| Type | Description |
| -- | -- |
| const char* | Pointer to the ID of the anchor component. |

### OH_ArkUI_AlignmentRuleOption_GetStartAlignment()

```c
ArkUI_HorizontalAlignment OH_ArkUI_AlignmentRuleOption_GetStartAlignment(ArkUI_AlignmentRuleOption* option)
```

**Description**

Obtains the alignment mode in left alignment parameters.

**Since:** 12

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)* option | Pointer to an alignment rule configuration. |

**Returns**

| Type | Description |
| -- | -- |
| [ArkUI_HorizontalAlignment](capi-layout-h.md#arkui_horizontalalignment) | Alignment mode in the left alignment parameters. |

### OH_ArkUI_AlignmentRuleOption_GetEndId()

```c
const char* OH_ArkUI_AlignmentRuleOption_GetEndId(ArkUI_AlignmentRuleOption* option)
```

**Description**

Obtains the ID in right alignment parameters.

**Since:** 12

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)* option | Pointer to an alignment rule configuration. |

**Returns**

| Type | Description |
| -- | -- |
| const char* | Pointer to the ID in the right alignment parameters. |

### OH_ArkUI_AlignmentRuleOption_GetEndAlignment()

```c
ArkUI_HorizontalAlignment OH_ArkUI_AlignmentRuleOption_GetEndAlignment(ArkUI_AlignmentRuleOption* option)
```

**Description**

Obtains the alignment mode in right alignment parameters.

**Since:** 12

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)* option | Pointer to an alignment rule configuration. |

**Returns**

| Type | Description |
| -- | -- |
| [ArkUI_HorizontalAlignment](capi-layout-h.md#arkui_horizontalalignment) | Alignment mode in the right alignment parameters. |

### OH_ArkUI_AlignmentRuleOption_GetCenterIdHorizontal()

```c
const char* OH_ArkUI_AlignmentRuleOption_GetCenterIdHorizontal(ArkUI_AlignmentRuleOption* option)
```

**Description**

Obtains the ID in horizontal center alignment parameters.

**Since:** 12

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)* option | Pointer to an alignment rule configuration. |

**Returns**

| Type | Description |
| -- | -- |
| const char* | Pointer to the ID in the horizontal center alignment parameters. |

### OH_ArkUI_AlignmentRuleOption_GetCenterAlignmentHorizontal()

```c
ArkUI_HorizontalAlignment OH_ArkUI_AlignmentRuleOption_GetCenterAlignmentHorizontal(ArkUI_AlignmentRuleOption* option)
```

**Description**

Obtains the alignment mode in horizontal center alignment parameters.

**Since:** 12

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)* option | Pointer to an alignment rule configuration. |

**Returns**

| Type | Description |
| -- | -- |
| [ArkUI_HorizontalAlignment](capi-layout-h.md#arkui_horizontalalignment) | Alignment mode in the horizontal center alignment parameters. |

### OH_ArkUI_AlignmentRuleOption_GetTopId()

```c
const char* OH_ArkUI_AlignmentRuleOption_GetTopId(ArkUI_AlignmentRuleOption* option)
```

**Description**

Obtains the ID in top alignment parameters.

**Since:** 12

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)* option | Pointer to an alignment rule configuration. |

**Returns**

| Type | Description |
| -- | -- |
| const char* | Pointer to the ID in the top alignment parameters. |

### OH_ArkUI_AlignmentRuleOption_GetTopAlignment()

```c
ArkUI_VerticalAlignment OH_ArkUI_AlignmentRuleOption_GetTopAlignment(ArkUI_AlignmentRuleOption* option)
```

**Description**

Obtains the alignment mode in top alignment parameters.

**Since:** 12

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)* option | Pointer to an alignment rule configuration. |

**Returns**

| Type | Description |
| -- | -- |
| [ArkUI_VerticalAlignment](capi-layout-h.md#arkui_verticalalignment) | Alignment mode in the top alignment parameters. |

### OH_ArkUI_AlignmentRuleOption_GetBottomId()

```c
const char* OH_ArkUI_AlignmentRuleOption_GetBottomId(ArkUI_AlignmentRuleOption* option)
```

**Description**

Obtains the ID in bottom alignment parameters.

**Since:** 12

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)* option | Pointer to an alignment rule configuration. |

**Returns**

| Type | Description |
| -- | -- |
| const char* | Pointer to the ID in the bottom alignment parameters. |

### OH_ArkUI_AlignmentRuleOption_GetBottomAlignment()

```c
ArkUI_VerticalAlignment OH_ArkUI_AlignmentRuleOption_GetBottomAlignment(ArkUI_AlignmentRuleOption* option)
```

**Description**

Obtains the alignment mode in bottom alignment parameters.

**Since:** 12

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)* option | Pointer to an alignment rule configuration. |

**Returns**

| Type | Description |
| -- | -- |
| [ArkUI_VerticalAlignment](capi-layout-h.md#arkui_verticalalignment) | Alignment mode in the bottom alignment parameters. |

### OH_ArkUI_AlignmentRuleOption_GetCenterIdVertical()

```c
const char* OH_ArkUI_AlignmentRuleOption_GetCenterIdVertical(ArkUI_AlignmentRuleOption* option)
```

**Description**

Obtains the ID in vertical center alignment parameters.

**Since:** 12

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)* option | Pointer to an alignment rule configuration. |

**Returns**

| Type | Description |
| -- | -- |
| const char* | Pointer to the ID in the vertical center alignment parameters. |

### OH_ArkUI_AlignmentRuleOption_GetCenterAlignmentVertical()

```c
ArkUI_VerticalAlignment OH_ArkUI_AlignmentRuleOption_GetCenterAlignmentVertical(ArkUI_AlignmentRuleOption* option)
```

**Description**

Obtains the alignment mode in vertical center alignment parameters.

**Since:** 12

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)* option | Pointer to an alignment rule configuration. |

**Returns**

| Type | Description |
| -- | -- |
| [ArkUI_VerticalAlignment](capi-layout-h.md#arkui_verticalalignment) | Alignment mode in the vertical center alignment parameters. |

### OH_ArkUI_AlignmentRuleOption_GetBiasHorizontal()

```c
float OH_ArkUI_AlignmentRuleOption_GetBiasHorizontal(ArkUI_AlignmentRuleOption* option)
```

**Description**

Obtains the bias value in the horizontal direction.

**Since:** 12

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)* option | Pointer to an alignment rule configuration. |

**Returns**

| Type | Description |
| -- | -- |
| float | Bias value in the horizontal direction. |

### OH_ArkUI_AlignmentRuleOption_GetBiasVertical()

```c
float OH_ArkUI_AlignmentRuleOption_GetBiasVertical(ArkUI_AlignmentRuleOption* option)
```

**Description**

Obtains the bias value in the vertical direction.

**Since:** 12

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)* option | Pointer to an alignment rule configuration. |

**Returns**

| Type | Description |
| -- | -- |
| float | Bias value in the vertical direction. |

### OH_ArkUI_PositionEdges_Create()

```c
ArkUI_PositionEdges* OH_ArkUI_PositionEdges_Create()
```

**Description**

Creates a **PositionEdges** object.

**Since:** 21

**Returns**

| Type | Description |
| -- | -- |
| [ArkUI_PositionEdges*](capi-arkui-nativemodule-arkui-positionedges.md) | Pointer to the **PositionEdges** object. |

### OH_ArkUI_PositionEdges_Copy()

```c
ArkUI_PositionEdges* OH_ArkUI_PositionEdges_Copy(const ArkUI_PositionEdges* edges)
```

**Description**

Deeply copies a **PositionEdges** object.

**Since:** 21

**Parameters**

| Name | Description |
| -- | -- |
| [const ArkUI_PositionEdges](capi-arkui-nativemodule-arkui-positionedges.md)* edges | Pointer to the **PositionEdges** object. |

**Returns**

| Type | Description |
| -- | -- |
| [ArkUI_PositionEdges*](capi-arkui-nativemodule-arkui-positionedges.md) | Pointer to the new **PositionEdges** object. |

### OH_ArkUI_PositionEdges_Dispose()

```c
void OH_ArkUI_PositionEdges_Dispose(ArkUI_PositionEdges* edges)
```

**Description**

Disposes of the **PositionEdges** object.

**Since:** 21

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_PositionEdges](capi-arkui-nativemodule-arkui-positionedges.md)* edges | Pointer to the **PositionEdges** object. |

### OH_ArkUI_PositionEdges_SetTop()

```c
void OH_ArkUI_PositionEdges_SetTop(ArkUI_PositionEdges* edges, float value)
```

**Description**

Sets the value of the **PositionEdges** object in the top direction.

**Since:** 21

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_PositionEdges](capi-arkui-nativemodule-arkui-positionedges.md)* edges | Pointer to the **PositionEdges** object. |
| float value | Value of the **PositionEdges** object in the corresponding direction, in vp. |

### OH_ArkUI_PositionEdges_GetTop()

```c
int32_t OH_ArkUI_PositionEdges_GetTop(ArkUI_PositionEdges* edges, float* value)
```

**Description**

Obtains the value of the **PositionEdges** object in the top direction.

**Since:** 21

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_PositionEdges](capi-arkui-nativemodule-arkui-positionedges.md)* edges | Pointer to the **PositionEdges** object. |
| float* value | Pointer to the value of the **PositionEdges** object in the corresponding direction, in vp. |

**Returns**

| Type | Description |
| -- | -- |
| int32_t | Result code.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs. |

### OH_ArkUI_PositionEdges_SetLeft()

```c
void OH_ArkUI_PositionEdges_SetLeft(ArkUI_PositionEdges* edges, float value)
```

**Description**

Sets the value of the **PositionEdges** object in the left direction.

**Since:** 21

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_PositionEdges](capi-arkui-nativemodule-arkui-positionedges.md)* edges | Pointer to the **PositionEdges** object. |
| float value | Value of the **PositionEdges** object in the corresponding direction, in vp. |

### OH_ArkUI_PositionEdges_GetLeft()

```c
int32_t OH_ArkUI_PositionEdges_GetLeft(ArkUI_PositionEdges* edges, float* value)
```

**Description**

Obtains the value of the **PositionEdges** object in the left direction.

**Since:** 21

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_PositionEdges](capi-arkui-nativemodule-arkui-positionedges.md)* edges | Pointer to the **PositionEdges** object. |
| float* value | Pointer to the value of the **PositionEdges** object in the corresponding direction, in vp. |

**Returns**

| Type | Description |
| -- | -- |
| int32_t | Result code.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs. |

### OH_ArkUI_PositionEdges_SetBottom()

```c
void OH_ArkUI_PositionEdges_SetBottom(ArkUI_PositionEdges* edges, float value)
```

**Description**

Sets the value of the **PositionEdges** object in the bottom direction.

**Since:** 21

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_PositionEdges](capi-arkui-nativemodule-arkui-positionedges.md)* edges | Pointer to the **PositionEdges** object. |
| float value | Value of the **PositionEdges** object in the corresponding direction, in vp. |

### OH_ArkUI_PositionEdges_GetBottom()

```c
int32_t OH_ArkUI_PositionEdges_GetBottom(ArkUI_PositionEdges* edges, float* value)
```

**Description**

Obtains the value of the **PositionEdges** object in the bottom direction.

**Since:** 21

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_PositionEdges](capi-arkui-nativemodule-arkui-positionedges.md)* edges | Pointer to the **PositionEdges** object. |
| float* value | Pointer to the value of the **PositionEdges** object in the corresponding direction, in vp. |

**Returns**

| Type | Description |
| -- | -- |
| int32_t | Result code.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs. |

### OH_ArkUI_PositionEdges_SetRight()

```c
void OH_ArkUI_PositionEdges_SetRight(ArkUI_PositionEdges* edges, float value)
```

**Description**

Sets the value of the **PositionEdges** object in the right direction.

**Since:** 21

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_PositionEdges](capi-arkui-nativemodule-arkui-positionedges.md)* edges | Pointer to the **PositionEdges** object. |
| float value | Value of the **PositionEdges** object in the corresponding direction, in vp. |

### OH_ArkUI_PositionEdges_GetRight()

```c
int32_t OH_ArkUI_PositionEdges_GetRight(ArkUI_PositionEdges* edges, float* value)
```

**Description**

Obtains the value of the **PositionEdges** object in the right direction.

**Since:** 21

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_PositionEdges](capi-arkui-nativemodule-arkui-positionedges.md)* edges | Pointer to the **PositionEdges** object. |
| float* value | Pointer to the value of the **PositionEdges** object in the corresponding direction, in vp. |

**Returns**

| Type | Description |
| -- | -- |
| int32_t | Result code.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs. |

### OH_ArkUI_PixelRoundPolicy_Create()

```c
ArkUI_PixelRoundPolicy* OH_ArkUI_PixelRoundPolicy_Create()
```

**Description**

Creates a **PixelRoundPolicy** object.

**Since:** 21

**Returns**

| Type | Description |
| -- | -- |
| [ArkUI_PixelRoundPolicy*](capi-arkui-nativemodule-arkui-pixelroundpolicy.md) | Pointer to the **PixelRoundPolicy** object. |

### OH_ArkUI_PixelRoundPolicy_Dispose()

```c
void OH_ArkUI_PixelRoundPolicy_Dispose(ArkUI_PixelRoundPolicy* policy)
```

**Description**

Disposes of the **PixelRoundPolicy** object.

**Since:** 21

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_PixelRoundPolicy](capi-arkui-nativemodule-arkui-pixelroundpolicy.md)* policy | Pointer to the target **PixelRoundPolicy** object. |

### OH_ArkUI_PixelRoundPolicy_SetTop()

```c
void OH_ArkUI_PixelRoundPolicy_SetTop(ArkUI_PixelRoundPolicy* policy, ArkUI_PixelRoundCalcPolicy value)
```

**Description**

Sets the top edge pixel rounding policy for the **PixelRoundPolicy** object.

**Since:** 21

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_PixelRoundPolicy](capi-arkui-nativemodule-arkui-pixelroundpolicy.md)* policy | Pointer to the **PixelRoundPolicy** object. |
| [ArkUI_PixelRoundCalcPolicy](capi-layout-h.md#arkui_pixelroundcalcpolicy) value | Specific pixel rounding policy. |

### OH_ArkUI_PixelRoundPolicy_GetTop()

```c
int32_t OH_ArkUI_PixelRoundPolicy_GetTop(ArkUI_PixelRoundPolicy* policy, ArkUI_PixelRoundCalcPolicy* value)
```

**Description**

Obtains the top edge pixel rounding policy from the **PixelRoundPolicy** object.

**Since:** 21

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_PixelRoundPolicy](capi-arkui-nativemodule-arkui-pixelroundpolicy.md)* policy | Pointer to the **PixelRoundPolicy** object. |
| [ArkUI_PixelRoundCalcPolicy](capi-layout-h.md#arkui_pixelroundcalcpolicy)* value | Pointer to the specific pixel rounding policy. |

**Returns**

| Type | Description |
| -- | -- |
| int32_t | Result code.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs. |

### OH_ArkUI_PixelRoundPolicy_SetStart()

```c
void OH_ArkUI_PixelRoundPolicy_SetStart(ArkUI_PixelRoundPolicy* policy, ArkUI_PixelRoundCalcPolicy value)
```

**Description**

Sets the start edge pixel rounding policy for the **PixelRoundPolicy** object.

**Since:** 21

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_PixelRoundPolicy](capi-arkui-nativemodule-arkui-pixelroundpolicy.md)* policy | Pointer to the **PixelRoundPolicy** object. |
| [ArkUI_PixelRoundCalcPolicy](capi-layout-h.md#arkui_pixelroundcalcpolicy) value | Specific pixel rounding policy. |

### OH_ArkUI_PixelRoundPolicy_GetStart()

```c
int32_t OH_ArkUI_PixelRoundPolicy_GetStart(ArkUI_PixelRoundPolicy* policy, ArkUI_PixelRoundCalcPolicy* value)
```

**Description**

Obtains the start edge pixel rounding policy from the **PixelRoundPolicy** object.

**Since:** 21

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_PixelRoundPolicy](capi-arkui-nativemodule-arkui-pixelroundpolicy.md)* policy | Pointer to the **PixelRoundPolicy** object. |
| [ArkUI_PixelRoundCalcPolicy](capi-layout-h.md#arkui_pixelroundcalcpolicy)* value | Pointer to the specific pixel rounding policy. |

**Returns**

| Type | Description |
| -- | -- |
| int32_t | Result code.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs. |

### OH_ArkUI_PixelRoundPolicy_SetBottom()

```c
void OH_ArkUI_PixelRoundPolicy_SetBottom(ArkUI_PixelRoundPolicy* policy, ArkUI_PixelRoundCalcPolicy value)
```

**Description**

Sets the bottom edge pixel rounding policy for the **PixelRoundPolicy** object.

**Since:** 21

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_PixelRoundPolicy](capi-arkui-nativemodule-arkui-pixelroundpolicy.md)* policy | Pointer to the **PixelRoundPolicy** object. |
| [ArkUI_PixelRoundCalcPolicy](capi-layout-h.md#arkui_pixelroundcalcpolicy) value | Specific pixel rounding policy. |

### OH_ArkUI_PixelRoundPolicy_GetBottom()

```c
int32_t OH_ArkUI_PixelRoundPolicy_GetBottom(ArkUI_PixelRoundPolicy* policy, ArkUI_PixelRoundCalcPolicy* value)
```

**Description**

Obtains the bottom edge pixel rounding policy from the **PixelRoundPolicy** object.

**Since:** 21

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_PixelRoundPolicy](capi-arkui-nativemodule-arkui-pixelroundpolicy.md)* policy | Pointer to the **PixelRoundPolicy** object. |
| [ArkUI_PixelRoundCalcPolicy](capi-layout-h.md#arkui_pixelroundcalcpolicy)* value | Pointer to the specific pixel rounding policy. |

**Returns**

| Type | Description |
| -- | -- |
| int32_t | Result code.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs. |

### OH_ArkUI_PixelRoundPolicy_SetEnd()

```c
void OH_ArkUI_PixelRoundPolicy_SetEnd(ArkUI_PixelRoundPolicy* policy, ArkUI_PixelRoundCalcPolicy value)
```

**Description**

Sets the end edge pixel rounding policy for the **PixelRoundPolicy** object.

**Since:** 21

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_PixelRoundPolicy](capi-arkui-nativemodule-arkui-pixelroundpolicy.md)* policy | Pointer to the **PixelRoundPolicy** object. |
| [ArkUI_PixelRoundCalcPolicy](capi-layout-h.md#arkui_pixelroundcalcpolicy) value | Specific pixel rounding policy. |

### OH_ArkUI_PixelRoundPolicy_GetEnd()

```c
int32_t OH_ArkUI_PixelRoundPolicy_GetEnd(ArkUI_PixelRoundPolicy* policy, ArkUI_PixelRoundCalcPolicy* value)
```

**Description**

Obtains the end edge pixel rounding policy from the **PixelRoundPolicy** object.

**Since:** 21

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_PixelRoundPolicy](capi-arkui-nativemodule-arkui-pixelroundpolicy.md)* policy | Pointer to the **PixelRoundPolicy** object. |
| [ArkUI_PixelRoundCalcPolicy](capi-layout-h.md#arkui_pixelroundcalcpolicy)* value | Pointer to the specific pixel rounding policy. |

**Returns**

| Type | Description |
| -- | -- |
| int32_t | Result code.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs. |