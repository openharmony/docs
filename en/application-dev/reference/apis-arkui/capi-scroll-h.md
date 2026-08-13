# scroll.h

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @shengu_lancer; @rongShao-Z-->
<!--Designer: @yangcan18-->
<!--Tester: @leiyuqian-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=8d874d0ed3e2b14fedac21e9dc0520168c6abc51 translatedAt=2026-08-11T09:10:27.857Z pushedAt=2026-08-12T06:21:09.263Z -->

## Overview

Defines the enumerations related to the **Scroll** component, such as the scrolling direction, edge effect, scrollbar state, content clipping, nested scrolling, scrolling state, and scrolling source, which are used to configure and listen for the behavior of the **Scroll** component and related scrollable components.

**File to include:** <arkui/node_attributes/scroll.h>

**Library:** libace_ndk.z.so

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Since:** 12

**Related module:** [ArkUI_NativeModule](capi-arkui-nativemodule.md)

**Sample**: <!--RP1-->[ScrollableNDK](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/ArkUISample/ScrollableNDK)<!--RP1End-->

## Summary

### Enums

| Name | typedef Keyword | Description |
| -- | -- | -- |
| [ArkUI_EdgeEffect](#arkui_edgeeffect) | ArkUI_EdgeEffect | Enumerates the effects used at the edges of the component when the boundary of the scrollable content is reached. |
| [ArkUI_BarState](#arkui_barstate) | ArkUI_BarState | Enumerates the scrollbar states of the **TextArea** and **TextEditor** components. |
| [ArkUI_EffectEdge](#arkui_effectedge) | ArkUI_EffectEdge | Enumerates the edges for which the effect takes effect when the boundary of the scrollable content is reached. |
| [ArkUI_ScrollDirection](#arkui_scrolldirection) | ArkUI_ScrollDirection | Enumerates the scrolling directions of the [Scroll](../apis-arkui/arkui-ts/ts-container-scroll.md) component. |
| [ArkUI_ScrollSnapAlign](#arkui_scrollsnapalign) | ArkUI_ScrollSnapAlign | Enumerates the alignment modes of list items when scrolling ends. |
| [ArkUI_ScrollBarDisplayMode](#arkui_scrollbardisplaymode) | ArkUI_ScrollBarDisplayMode | Enumerates the scrollbar display modes. |
| [ArkUI_ContentClipMode](#arkui_contentclipmode) | ArkUI_ContentClipMode | Enumerates the content clipping modes of scrollable components. |
| [ArkUI_ScrollNestedMode](#arkui_scrollnestedmode) | ArkUI_ScrollNestedMode | Enumerates nested scrolling modes. |
| [ArkUI_ScrollEdge](#arkui_scrolledge) | ArkUI_ScrollEdge | Enumerates the edges to which the component scrolls. |
| [ArkUI_ScrollAlignment](#arkui_scrollalignment) | ArkUI_ScrollAlignment | Enumerates how the list item to scroll to is aligned with the container. |
| [ArkUI_ScrollState](#arkui_scrollstate) | ArkUI_ScrollState | Enumerates the scrolling states. |
| [ArkUI_ScrollSource](#arkui_scrollsource) | ArkUI_ScrollSource | Enumerates scroll sources. |
| [ArkUI_ScrollSnapAnimationSpeed](#arkui_scrollsnapanimationspeed) | ArkUI_ScrollSnapAnimationSpeed | Enumerates scroll snap animation speeds for list components. |

## Enum Description

### ArkUI_EdgeEffect

```c
enum ArkUI_EdgeEffect
```

**Description**

Enumerates the effects used at the edges of the component when the boundary of the scrollable content is reached. The default value is **ARKUI_EDGE_EFFECT_NONE** for the **Grid**, **Scroll**, and **WaterFlow** components, and **ARKUI_EDGE_EFFECT_SPRING** for the **List** component.

**Since:** 12

| Value | Description |
| -- | -- |
| ARKUI_EDGE_EFFECT_SPRING = 0 | Spring effect. When at one of the edges, the component can move beyond the bounds based on the initial speed or through touches, and produces a bounce effect when the user releases their finger. |
| ARKUI_EDGE_EFFECT_FADE = 1 | Fade effect. When at one of the edges, the component produces a fade effect. |
| ARKUI_EDGE_EFFECT_NONE = 2 | No effect when the component is at one of the edges. |

### ArkUI_BarState

```c
enum ArkUI_BarState
```

**Description**

Enumerates the scrollbar states of the **TextArea** and **TextEditor** components.

**Since:** 22

| Value | Description |
| -- | -- |
| ARKUI_BAR_STATE_OFF = 0 | Not displayed. |
| ARKUI_BAR_STATE_AUTO = 1 | Displayed on demand (The scrollbar is displayed when being touched and disappears 2 seconds later.) |
| ARKUI_BAR_STATE_ON = 2 | Always displayed. |

### ArkUI_EffectEdge

```c
enum ArkUI_EffectEdge
```

**Description**

Enumerates the edges for which the effect takes effect when the boundary of the scrollable content is reached.

**Since:** 18

| Value | Description |
| -- | -- |
| ARKUI_EFFECT_EDGE_START = 1 | Start edge. |
| ARKUI_EFFECT_EDGE_END = 2 | End edge. |

### ArkUI_ScrollDirection

```c
enum ArkUI_ScrollDirection
```

**Description**

Enumerates the scrolling directions of the [Scroll](../apis-arkui/arkui-ts/ts-container-scroll.md) component.

**Since:** 12

| Value | Description |
| -- | -- |
| ARKUI_SCROLL_DIRECTION_VERTICAL = 0 | Vertical scrolling only. |
| ARKUI_SCROLL_DIRECTION_HORIZONTAL = 1 | Horizontal scrolling only. |
| ARKUI_SCROLL_DIRECTION_NONE = 3 | Scrolling disabled. |
| ARKUI_SCROLL_DIRECTION_FREE = 4 | Free scrolling. This value supports both vertical and horizontal scrolling, and is available only in the **Scroll** component.<br>**Since:** 20 |

### ArkUI_ScrollSnapAlign

```c
enum ArkUI_ScrollSnapAlign
```

**Description**

Enumerates the alignment modes of list items when scrolling ends.

**Since:** 12

| Value | Description |
| -- | -- |
| ARKUI_SCROLL_SNAP_ALIGN_NONE = 0 | No alignment mode. |
| ARKUI_SCROLL_SNAP_ALIGN_START = 1 | The first item in the view is aligned at the start of the list. |
| ARKUI_SCROLL_SNAP_ALIGN_CENTER = 2 | The middle items in the view are aligned in the center of the list. |
| ARKUI_SCROLL_SNAP_ALIGN_END = 3 | The last item in the view is aligned at the end of the list. |

### ArkUI_ScrollBarDisplayMode

```c
enum ArkUI_ScrollBarDisplayMode
```

**Description**

Enumerates the scrollbar display modes.

**Since:** 12

| Value | Description |
| -- | -- |
| ARKUI_SCROLL_BAR_DISPLAY_MODE_OFF = 0 | Not displayed. |
| ARKUI_SCROLL_BAR_DISPLAY_MODE_AUTO = 1 | Displayed when the screen is touched and hidden after 2s. |
| ARKUI_SCROLL_BAR_DISPLAY_MODE_ON = 2 | Always displayed. |

### ArkUI_ContentClipMode

```c
enum ArkUI_ContentClipMode
```

**Description**

Enumerates the content clipping modes of scrollable components.

**Since:** 18

| Value | Description |
| -- | -- |
| ARKUI_CONTENT_CLIP_MODE_CONTENT_ONLY = 0 | Clip to the content area only. |
| ARKUI_CONTENT_CLIP_MODE_BOUNDARY = 1 | Clip to the component's boundary area. |
| ARKUI_CONTENT_CLIP_MODE_SAFE_AREA = 2 | Clip to the [safe area](./arkui-ts/ts-universal-attributes-expand-safe-area.md) configured for the component. |

### ArkUI_ScrollNestedMode

```c
enum ArkUI_ScrollNestedMode
```

**Description**

Enumerates nested scrolling modes.

**Since:** 12

| Value | Description |
| -- | -- |
| ARKUI_SCROLL_NESTED_MODE_SELF_ONLY = 0 | The scrolling is contained within the component, and no scroll chaining occurs, that is, the parent component does not scroll when the component scrolling reaches the boundary. |
| ARKUI_SCROLL_NESTED_MODE_SELF_FIRST = 1 | The component scrolls first, and when it hits the boundary, the parent component scrolls. When the parent component hits the boundary, its edge effect is displayed. If no edge effect is specified for the parent component, the edge effect of the child component is displayed instead. |
| ARKUI_SCROLL_NESTED_MODE_PARENT_FIRST = 2 | The parent component scrolls first, and when it hits the boundary, the component scrolls. When the component hits the boundary, its edge effect is displayed. If no edge effect is specified for the component, the edge effect of the parent component is displayed instead. |
| ARKUI_SCROLL_NESTED_MODE_PARALLEL = 3 | The component and its parent component scroll at the same time. When both the component and its parent component hit the boundary, the edge effect of the component is displayed. If no edge effect is specified for the component, the edge effect of the parent component is displayed instead. |

### ArkUI_ScrollEdge

```c
enum ArkUI_ScrollEdge
```

**Description**

Enumerates the edges to which the component scrolls.

**Since:** 12

| Value | Description |
| -- | -- |
| ARKUI_SCROLL_EDGE_TOP = 0 | Top edge in the vertical direction. |
| ARKUI_SCROLL_EDGE_BOTTOM = 1 | Bottom edge in the vertical direction. |
| ARKUI_SCROLL_EDGE_START = 2 | Start position in the horizontal direction. |
| ARKUI_SCROLL_EDGE_END = 3 | End position in the horizontal direction. |

### ArkUI_ScrollAlignment

```c
enum ArkUI_ScrollAlignment
```

**Description**

Enumerates how the list item to scroll to is aligned with the container.

**Since:** 12

| Value | Description |
| -- | -- |
| ARKUI_SCROLL_ALIGNMENT_START = 0 | The start edge of the list item is flush with the start edge of the container. |
| ARKUI_SCROLL_ALIGNMENT_CENTER = 1 | The list item is centered along the main axis of the container. |
| ARKUI_SCROLL_ALIGNMENT_END = 2 | The end edge of the list item is flush with the end edge of the container. |
| ARKUI_SCROLL_ALIGNMENT_AUTO = 3 | The list item is automatically aligned. If the item is fully contained within the display area, no adjustment is performed. Otherwise, the item is aligned so that its start or end edge is flush with the start or end edge of the container, whichever requires a shorter scrolling distance. |

### ArkUI_ScrollState

```c
enum ArkUI_ScrollState
```

**Description**

Enumerates the scrolling states.

**Since:** 12

| Value | Description |
| -- | -- |
| ARKUI_SCROLL_STATE_IDLE = 0 | Idle. The container enters this state when an API in the controller is used to scroll the container or when the scrollbar is dragged. |
| ARKUI_SCROLL_STATE_SCROLL = 1 | Scrolling. The container enters this state when the user drags the container to scroll. |
| ARKUI_SCROLL_STATE_FLING = 2 | Inertial scrolling. The container enters this state when inertial scrolling occurs or when the container bounces back after being released from a fling. |

### ArkUI_ScrollSource

```c
enum ArkUI_ScrollSource
```

**Description**

Enumerates scroll sources.

**Since:** 12

| Value | Description |
| -- | -- |
| ARKUI_SCROLL_SOURCE_DRAG = 0 | Finger dragging. |
| ARKUI_SCROLL_SOURCE_FLING = 1 | Inertia scrolling after finger dragging. |
| ARKUI_SCROLL_SOURCE_EDGE_EFFECT = 2 | [EdgeEffect.Spring](../apis-arkui/arkui-ts/ts-appendix-enums.md#edgeeffect) for boundary crossing. |
| ARKUI_SCROLL_SOURCE_OTHER_USER_INPUT = 3 | User input other than dragging, such as mouse wheel and keyboard events. |
| ARKUI_SCROLL_SOURCE_SCROLL_BAR = 4 | Scrollbar dragging. |
| ARKUI_SCROLL_SOURCE_SCROLL_BAR_FLING = 5 | Inertial scrolling after scrollbar dragging. |
| ARKUI_SCROLL_SOURCE_SCROLLER = 6 | Scrolling by the scroll controller (without animation). |
| ARKUI_SCROLL_SOURCE_ANIMATION = 7 | Scrolling by the scroll controller (with animation). |

### ArkUI_ScrollSnapAnimationSpeed

```c
enum ArkUI_ScrollSnapAnimationSpeed
```

**Description**

Enumerates scroll snap animation speeds for list components.

**Since:** 22

| Value | Description |
| -- | -- |
| ARKUI_SCROLL_SNAP_ANIMATION_NORMAL = 0 | Normal snap scroll animation speed. |
| ARKUI_SCROLL_SNAP_ANIMATION_SLOW = 1 | Slow snap scroll animation speed. |