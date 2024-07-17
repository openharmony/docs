# ArkUI_NativeModule


## Overview

Provides UI capabilities of ArkUI on the native side, such as UI component creation and destruction, tree node operations, attribute setting, and event listening.

Defines APIs for ArkUI to register gesture callbacks on the native side.

Provides animation callbacks of ArkUI on the native side.

**Since**: 12


## Summary


### Files

| Name| Description|
| -------- | -------- |
| [drawable_descriptor.h](drawable__descriptor_8h.md) | Provides type definitions for **NativeDrawableDescriptor** APIs.<br> **Library**: libace_ndk.z.so|
| [native_animate.h](native__animate_8h.md) | Defines a set of animation APIs of ArkUI on the native side.<br> **Library**: libace_ndk.z.so|
| [native_dialog.h](native__dialog_8h.md) | Defines a set of custom dialog box APIs of ArkUI on the native side.<br> **Library**: libace_ndk.z.so|
| [native_gesture.h](native__gesture_8h.md) | Provides type definitions for **NativeGesture** APIs.<br> **Library**: libace_ndk.z.so|
| [native_interface.h](native__interface_8h.md) | Provides a unified entry for the native module APIs.<br> **Library**: libace_ndk.z.so|
| [native_node.h](native__node_8h.md) | Provides type definitions for **NativeNode** APIs.<br> **Library**: libace_ndk.z.so|
| [native_node_napi.h](native__node__napi_8h.md) | Provides FrameNode on the ArkTS side can be converted to the NodeHandle.<br> **Library**: libace_ndk.z.so|
| [native_type.h](native__type_8h.md) | Defines the common types for the native module.<br> **Library**: libace_ndk.z.so|
| [styled_string.h](styled__string_8h.md) | Provides styled string APIs of ArkUI on the native side.<br>**Library**: libace_ndk.z.so|


### Structs

| Name| Description|
| -------- | -------- |
| struct&nbsp;&nbsp;[ArkUI_ExpectedFrameRateRange](_ark_u_i___expected_frame_rate_range.md) | Defines the expected frame rate range of the animation. |
| struct&nbsp;&nbsp;[ArkUI_AnimateCompleteCallback](_ark_u_i___animate_complete_callback.md) | Defines the callback type for when the animation playback is complete. |
| struct&nbsp;&nbsp;[ArkUI_NativeAnimateAPI_1](_ark_u_i___native_animate_a_p_i__1.md) | Implements the native animation APIs provided by ArkUI. |
| struct&nbsp;&nbsp;[ArkUI_NativeDialogAPI_1](_ark_u_i___native_dialog_a_p_i__1.md) | Provides the custom dialog box APIs for the native side. |
| struct&nbsp;&nbsp;[ArkUI_NativeGestureAPI_1](_ark_u_i___native_gesture_a_p_i__1.md) | Defines the gesture APIs. |
| struct&nbsp;&nbsp;[ArkUI_AttributeItem](_ark_u_i___attribute_item.md) | Defines the general input parameter structure of the **setAttribute** function. |
| struct&nbsp;&nbsp;[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) | Defines the parameter type of the component callback event. |
| struct&nbsp;&nbsp;[ArkUI_StringAsyncEvent](_ark_u_i___string_async_event.md) | Defines the string type parameter used by the component callback event. |
| struct&nbsp;&nbsp;[ArkUI_NativeNodeAPI_1](_ark_u_i___native_node_a_p_i__1.md) | Declares a collection of native node APIs provided by ArkUI. |
| struct&nbsp;&nbsp;[ArkUI_ContextCallback](_ark_u_i___context_callback.md) | Defines event callback. |
| union&nbsp;&nbsp;[ArkUI_NumberValue](union_ark_u_i___number_value.md) | Provides the number types of ArkUI in the native code. |
| struct&nbsp;&nbsp;[ARKUI_TextPickerRangeContent](_a_r_k_u_i___text_picker_range_content.md) | Defines the input structure of the single-column text picker with image resources. |
| struct&nbsp;&nbsp;[ARKUI_TextPickerCascadeRangeContent](_a_r_k_u_i___text_picker_cascade_range_content.md) | Defines the input structure of the interconnected multi-column text picker. |
| struct&nbsp;&nbsp;[ArkUI_ColorStop](_ark_u_i___color_stop.md) | Defines a gradient color stop. |
| struct&nbsp;&nbsp;[ArkUI_Rect](_ark_u_i___rect.md) | Defines a mask area. |
| struct&nbsp;&nbsp;[ArkUI_IntSize](_ark_u_i___int_size.md) | Describes the width and height of a component. |
| struct&nbsp;&nbsp;[ArkUI_IntOffset](_ark_u_i___int_offset.md) | Describes the position of a component. |
| struct&nbsp;&nbsp;[ArkUI_Margin](_ark_u_i___margin.md) | Describes the margins of a component. |
| typedef struct [ArkUI_StyledString](#arkui_styledstring) [ArkUI_StyledString](#arkui_styledstring) | Defines a styled string object supported by the text component. |


### Macros

| Name| Description|
| -------- | -------- |
| [OH_ArkUI_GetModuleInterface](#oh_arkui_getmoduleinterface)(nativeAPIVariantKind, structType, structPtr) | Obtains the macro function corresponding to a struct pointer based on the struct type. |
| MAX_NODE_SCOPE_NUM | 1000 |
| MAX_COMPONENT_EVENT_ARG_NUM | 12  |


### Types

| Name| Description|
| -------- | -------- |
| typedef struct [ArkUI_DrawableDescriptor](#arkui_drawabledescriptor) [ArkUI_DrawableDescriptor](#arkui_drawabledescriptor) | Defines a **DrawableDescriptor** object. |
| typedef struct OH_PixelmapNative \* [OH_PixelmapNativeHandle](#oh_pixelmapnativehandle) | Defines the pointer to an **OH_PixelmapNative** object. |
| typedef struct [ArkUI_AnimateOption](#arkui_animateoption) [ArkUI_AnimateOption](#arkui_animateoption) | Defines the animation configuration. |
| typedef bool(\* [ArkUI_OnWillDismissEvent](#arkui_onwilldismissevent)) (int32_t reason) | Invoked when the dialog box is closed. |
| typedef uint32_t [ArkUI_GestureEventActionTypeMask](#arkui_gestureeventactiontypemask) | Defines a set of gesture event types. |
| typedef uint32_t [ArkUI_GestureDirectionMask](#arkui_gesturedirectionmask) | Defines a set of gesture directions. |
| typedef struct [ArkUI_NodeEvent](#arkui_nodeevent) [ArkUI_NodeEvent](#arkui_nodeevent) | Defines the common structure of a component event. |
| typedef struct [ArkUI_NodeCustomEvent](#arkui_nodecustomevent) [ArkUI_NodeCustomEvent](#arkui_nodecustomevent) | Defines the common structure of a custom component event. |
| typedef struct ArkUI_NodeAdapter \* [ArkUI_NodeAdapterHandle](#arkui_nodeadapterhandle) | Defines the component adapter, which is used for lazy loading of elements of scrollable components. |
| typedef struct [ArkUI_NodeAdapterEvent](#arkui_nodeadapterevent) [ArkUI_NodeAdapterEvent](#arkui_nodeadapterevent) | Defines the component adapter event. |
| typedef struct [ArkUI_LayoutConstraint](#arkui_layoutconstraint) [ArkUI_LayoutConstraint](#arkui_layoutconstraint) | Defines the size constraints of a component during component layout. |
| typedef struct [ArkUI_DrawContext](#arkui_drawcontext) [ArkUI_DrawContext](#arkui_drawcontext) | Defines the component drawing context. |
| typedef struct ArkUI_Node \* [ArkUI_NodeHandle](#arkui_nodehandle) | Defines the pointer to the ArkUI native component object. |
| typedef struct ArkUI_NativeDialog \* [ArkUI_NativeDialogHandle](#arkui_nativedialoghandle) | Defines the handle to the custom dialog box controller of ArkUI on the native side. |
| typedef struct [ArkUI_WaterFlowSectionOption](#arkui_waterflowsectionoption) [ArkUI_WaterFlowSectionOption](#arkui_waterflowsectionoption) | Defines the water flow section configuration. |
| typedef struct ArkUI_Context \* [ArkUI_ContextHandle](#arkui_contexthandle) | Defines the handle to the ArkUI native UI context. |
| typedef struct [ArkUI_AlignmentRuleOption](#arkui_alignmentruleoption) [ArkUI_AlignmentRuleOption](#arkui_alignmentruleoption) | Defines the alignment rule in the relative container. |
| typedef struct [ArkUI_GuidelineOption](#arkui_guidelineoption) [ArkUI_GuidelineOption](#arkui_guidelineoption) | Defines the ID, direction, and position of a guideline. |
| typedef struct [ArkUI_BarrierOption](#arkui_barrieroption) [ArkUI_BarrierOption](#arkui_barrieroption) | Defines the ID, direction, and referenced component of a barrier. |
| typedef struct [ArkUI_SwiperIndicator](#arkui_swiperindicator) [ArkUI_SwiperIndicator](#arkui_swiperindicator) | Defines the navigation point indicator style of the **\<Swiper>** component. |
| typedef struct [ArkUI_ListItemSwipeActionItem](#arkui_listitemswipeactionitem)[ArkUI_ListItemSwipeActionItem](#arkui_listitemswipeactionitem) | Defines the item configuration for **ListItemSwipeActionOption**. |
| typedef struct [ArkUI_ListItemSwipeActionOption](#arkui_listitemswipeactionoption)[ArkUI_ListItemSwipeActionOption](#arkui_listitemswipeactionoption) | Defines the configuration for **ListItemSwipeActionOption**. |
| typedef struct [ArkUI_ListChildrenMainSize](#arkui_listchildrenmainsize) [ArkUI_ListChildrenMainSize](#arkui_listchildrenmainsize) | Defines the **ChildrenMainSize** information of the **\<List>** component. |
| typedef struct [ArkUI_ImageAnimatorFrameInfo](#arkui_imageanimatorframeinfo) [ArkUI_ImageAnimatorFrameInfo](#arkui_imageanimatorframeinfo) | Defines the image frame information. |

### Enums

| Name| Description|
| -------- | -------- |
| [ArkUI_DismissReason](#arkui_dismissreason) { DIALOG_DISMISS_BACK_PRESS = 0, DIALOG_DISMISS_TOUCH_OUTSIDE } | Enumerates the actions for triggering closure of the dialog box. |
| [ArkUI_GestureEventActionType](#arkui_gestureeventactiontype) { GESTURE_EVENT_ACTION_ACCEPT = 0x01, GESTURE_EVENT_ACTION_UPDATE = 0x02, GESTURE_EVENT_ACTION_END = 0x04, GESTURE_EVENT_ACTION_CANCEL = 0x08 } | Enumerates gesture event types. |
| [ArkUI_GesturePriority](#arkui_gesturepriority) { NORMAL = 0, PRIORITY = 1, PARALLEL = 2 } | Enumerates gesture event modes. |
| [ArkUI_GroupGestureMode](#arkui_groupgesturemode) { **SEQUENTIAL_GROUP** = 0, PARALLEL_GROUP = 1, EXCLUSIVE_GROUP = 2 } | Enumerates gesture group modes. |
| [ArkUI_GestureDirection](#arkui_gesturedirection) {<br>GESTURE_DIRECTION_ALL = 0b1111, GESTURE_DIRECTION_HORIZONTAL = 0b0011, GESTURE_DIRECTION_VERTICAL = 0b1100, GESTURE_DIRECTION_LEFT = 0b0001,<br>GESTURE_DIRECTION_RIGHT = 0b0010, GESTURE_DIRECTION_UP = 0b0100, GESTURE_DIRECTION_DOWN = 0b1000, GESTURE_DIRECTION_NONE = 0<br>} | Enumerates gesture directions. |
| [ArkUI_GestureMask](#arkui_gesturemask) { NORMAL_GESTURE_MASK = 0, IGNORE_INTERNAL_GESTURE_MASK } | Enumerates gesture masking modes. |
| [ArkUI_GestureRecognizerType](#arkui_gesturerecognizertype) {<br>TAP_GESTURE = 0, LONG_PRESS_GESTURE, PAN_GESTURE, PINCH_GESTURE,<br>ROTATION_GESTURE, SWIPE_GESTURE, GROUP_GESTURE<br>} | Enumerates gesture types. |
| [ArkUI_GestureInterruptResult](#arkui_gestureinterruptresult) { GESTURE_INTERRUPT_RESULT_CONTINUE = 0, GESTURE_INTERRUPT_RESULT_REJECT } | Enumerates gesture interruption results. |
| [ArkUI_NativeAPIVariantKind](#arkui_nativeapivariantkind) { ARKUI_NATIVE_NODE, ARKUI_NATIVE_DIALOG, ARKUI_NATIVE_GESTURE, ARKUI_NATIVE_ANIMATE } | Defines the native API types. |
| [ArkUI_NodeType](#arkui_nodetype) {<br>ARKUI_NODE_CUSTOM = 0, ARKUI_NODE_TEXT = 1, ARKUI_NODE_SPAN = 2, ARKUI_NODE_IMAGE_SPAN = 3,<br>ARKUI_NODE_IMAGE = 4, ARKUI_NODE_TOGGLE = 5, ARKUI_NODE_LOADING_PROGRESS = 6, ARKUI_NODE_TEXT_INPUT = 7,<br>ARKUI_NODE_TEXT_AREA = 8, ARKUI_NODE_BUTTON = 9, ARKUI_NODE_PROGRESS = 10, ARKUI_NODE_CHECKBOX = 11,<br>ARKUI_NODE_XCOMPONENT = 12, ARKUI_NODE_DATE_PICKER = 13, ARKUI_NODE_TIME_PICKER = 14, ARKUI_NODE_TEXT_PICKER = 15,<br>ARKUI_NODE_CALENDAR_PICKER = 16, ARKUI_NODE_SLIDER = 17, ARKUI_NODE_RADIO = 18, ARKUI_NODE_IMAGE_ANIMATOR = 19, ARKUI_NODE_STACK = MAX_NODE_SCOPE_NUM,<br>ARKUI_NODE_SWIPER, ARKUI_NODE_SCROLL, ARKUI_NODE_LIST, ARKUI_NODE_LIST_ITEM,<br>ARKUI_NODE_LIST_ITEM_GROUP, ARKUI_NODE_COLUMN, ARKUI_NODE_ROW, ARKUI_NODE_FLEX,<br>ARKUI_NODE_REFRESH, ARKUI_NODE_WATER_FLOW, ARKUI_NODE_FLOW_ITEM, ARKUI_NODE_RELATIVE_CONTAINER,<br>ARKUI_NODE_GRID, ARKUI_NODE_GRID_ITEM<br>} | Enumerates ArkUI component types that can be created on the native side. |
| [ArkUI_NodeAttributeType](#arkui_nodeattributetype) {<br>NODE_WIDTH = 0, NODE_HEIGHT, NODE_BACKGROUND_COLOR, NODE_BACKGROUND_IMAGE,<br>NODE_PADDING, NODE_ID, NODE_ENABLED, NODE_MARGIN,<br>NODE_TRANSLATE, NODE_SCALE, NODE_ROTATE, NODE_BRIGHTNESS,<br>NODE_SATURATION, NODE_BLUR, NODE_LINEAR_GRADIENT, NODE_ALIGNMENT,<br>NODE_OPACITY, NODE_BORDER_WIDTH, NODE_BORDER_RADIUS, NODE_BORDER_COLOR,<br>NODE_BORDER_STYLE, NODE_Z_INDEX, NODE_VISIBILITY, NODE_CLIP,<br>NODE_CLIP_SHAPE, NODE_TRANSFORM, NODE_HIT_TEST_BEHAVIOR, NODE_POSITION,<br>NODE_SHADOW, NODE_CUSTOM_SHADOW, NODE_BACKGROUND_IMAGE_SIZE, NODE_BACKGROUND_IMAGE_SIZE_WITH_STYLE,<br>NODE_BACKGROUND_BLUR_STYLE, NODE_TRANSFORM_CENTER, NODE_OPACITY_TRANSITION, NODE_ROTATE_TRANSITION,<br>NODE_SCALE_TRANSITION, NODE_TRANSLATE_TRANSITION, NODE_MOVE_TRANSITION, NODE_FOCUSABLE,<br>NODE_DEFAULT_FOCUS, NODE_RESPONSE_REGION, NODE_OVERLAY, NODE_SWEEP_GRADIENT,<br>NODE_RADIAL_GRADIENT, NODE_MASK, NODE_BLEND_MODE, NODE_DIRECTION,<br>NODE_CONSTRAINT_SIZE, NODE_GRAY_SCALE, NODE_INVERT, NODE_SEPIA,<br>NODE_CONTRAST, NODE_FOREGROUND_COLOR, NODE_OFFSET, NODE_MARK_ANCHOR,<br>NODE_BACKGROUND_IMAGE_POSITION, NODE_ALIGN_RULES, NODE_ALIGN_SELF, NODE_FLEX_GROW,<br>NODE_FLEX_SHRINK, NODE_FLEX_BASIS, NODE_ACCESSIBILITY_GROUP, NODE_ACCESSIBILITY_TEXT,<br>NODE_ACCESSIBILITY_MODE, NODE_ACCESSIBILITY_DESCRIPTION, NODE_FOCUS_STATUS, NODE_ASPECT_RATIO,<br>NODE_LAYOUT_WEIGHT, NODE_DISPLAY_PRIORITY, NODE_OUTLINE_WIDTH, NODE_RELATIVE_LAYOUT_CHAIN_MODE,<br>NODE_RENDER_FIT, NODE_OUTLINE_COLOR, NODE_SIZE, NODE_RENDER_GROUP,<br>NODE_COLOR_BLEND, NODE_FOREGROUND_BLUR_STYLE, NODE_GEOMETRY_TRANSITION, NODE_WIDTH_PERCENT,<br>NODE_HEIGHT_PERCENT, NODE_PADDING_PERCENT, NODE_MARGIN_PERCENT, NODE_LAYOUT_RECT,<br>NODE_TEXT_CONTENT = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_TEXT, NODE_FONT_COLOR, NODE_FONT_SIZE, NODE_FONT_STYLE,<br>NODE_FONT_WEIGHT, NODE_TEXT_LINE_HEIGHT, NODE_TEXT_DECORATION, NODE_TEXT_CASE,<br>NODE_TEXT_LETTER_SPACING, NODE_TEXT_MAX_LINES, NODE_TEXT_ALIGN, NODE_TEXT_OVERFLOW,<br>NODE_FONT_FAMILY, NODE_TEXT_COPY_OPTION, NODE_TEXT_BASELINE_OFFSET, NODE_TEXT_TEXT_SHADOW,<br>NODE_TEXT_MIN_FONT_SIZE, NODE_TEXT_MAX_FONT_SIZE, NODE_TEXT_FONT, NODE_TEXT_HEIGHT_ADAPTIVE_POLICY,<br>NODE_TEXT_INDENT, NODE_TEXT_WORD_BREAK, NODE_TEXT_ELLIPSIS_MODE, NODE_TEXT_LINE_SPACING, NODE_TEXT_CONTENT_WITH_STYLED_STRING, NODE_FONT_FEATURE,<br>NODE_TEXT_ENABLE_DATA_DETECTOR, NODE_TEXT_ENABLE_DATA_DETECTOR_CONFIG, NODE_TEXT_SELECTED_BACKGROUND_COLOR, NODE_SPAN_CONTENT = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_SPAN,<br>NODE_SPAN_TEXT_BACKGROUND_STYLE, NODE_IMAGE_SPAN_SRC = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_IMAGE_SPAN, NODE_IMAGE_SPAN_VERTICAL_ALIGNMENT, NODE_IMAGE_SRC = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_IMAGE,<br>NODE_IMAGE_OBJECT_FIT, NODE_IMAGE_INTERPOLATION, NODE_IMAGE_OBJECT_REPEAT, NODE_IMAGE_COLOR_FILTER,<br>NODE_IMAGE_AUTO_RESIZE, NODE_IMAGE_ALT, NODE_IMAGE_DRAGGABLE, NODE_IMAGE_RENDER_MODE,<br>NODE_IMAGE_FIT_ORIGINAL_SIZE, NODE_IMAGE_FILL_COLOR, NODE_IMAGE_RESIZABLE, NODE_TOGGLE_SELECTED_COLOR = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_TOGGLE,<br>NODE_TOGGLE_SWITCH_POINT_COLOR, NODE_TOGGLE_VALUE, NODE_TOGGLE_UNSELECTED_COLOR, NODE_LOADING_PROGRESS_COLOR = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_LOADING_PROGRESS,<br>NODE_LOADING_PROGRESS_ENABLE_LOADING, NODE_TEXT_INPUT_PLACEHOLDER = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_TEXT_INPUT, NODE_TEXT_INPUT_TEXT, NODE_TEXT_INPUT_CARET_COLOR,<br>NODE_TEXT_INPUT_CARET_STYLE, NODE_TEXT_INPUT_SHOW_UNDERLINE, NODE_TEXT_INPUT_MAX_LENGTH, NODE_TEXT_INPUT_ENTER_KEY_TYPE,<br>NODE_TEXT_INPUT_PLACEHOLDER_COLOR, NODE_TEXT_INPUT_PLACEHOLDER_FONT, NODE_TEXT_INPUT_ENABLE_KEYBOARD_ON_FOCUS, NODE_TEXT_INPUT_TYPE,<br>NODE_TEXT_INPUT_SELECTED_BACKGROUND_COLOR, NODE_TEXT_INPUT_SHOW_PASSWORD_ICON, NODE_TEXT_INPUT_EDITING, NODE_TEXT_INPUT_CANCEL_BUTTON,<br>NODE_TEXT_INPUT_TEXT_SELECTION, NODE_TEXT_INPUT_UNDERLINE_COLOR, NODE_TEXT_INPUT_ENABLE_AUTO_FILL, NODE_TEXT_INPUT_CONTENT_TYPE,<br>NODE_TEXT_INPUT_PASSWORD_RULES, NODE_TEXT_INPUT_SELECT_ALL, NODE_TEXT_INPUT_INPUT_FILTER, NODE_TEXT_INPUT_STYLE,<br>NODE_TEXT_INPUT_CARET_OFFSET, NODE_TEXT_INPUT_CONTENT_RECT, NODE_TEXT_INPUT_CONTENT_LINE_COUNT, NODE_TEXT_INPUT_SELECTION_MENU_HIDDEN,<br>NODE_TEXT_INPUT_BLUR_ON_SUBMIT, NODE_TEXT_INPUT_CUSTOM_KEYBOARD, NODE_TEXT_INPUT_WORD_BREAK, NODE_TEXT_INPUT_NUMBER_OF_LINES,<br>NODE_TEXT_INPUT_SHOW_KEYBOARD_ON_FOCUS, NODE_TEXT_AREA_PLACEHOLDER = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_TEXT_AREA, NODE_TEXT_AREA_TEXT, NODE_TEXT_AREA_MAX_LENGTH,<br>NODE_TEXT_AREA_PLACEHOLDER_COLOR, NODE_TEXT_AREA_PLACEHOLDER_FONT, NODE_TEXT_AREA_CARET_COLOR, NODE_TEXT_AREA_EDITING,<br>NODE_TEXT_AREA_TYPE, NODE_TEXT_AREA_SHOW_COUNTER, NODE_TEXT_AREA_SELECTION_MENU_HIDDEN, NODE_TEXT_AREA_BLUR_ON_SUBMIT,<br>NODE_TEXT_AREA_INPUT_FILTER, NODE_TEXT_AREA_SELECTED_BACKGROUND_COLOR, NODE_TEXT_AREA_ENTER_KEY_TYPE, NODE_TEXT_AREA_ENABLE_KEYBOARD_ON_FOCUS,<br>NODE_TEXT_AREA_CARET_OFFSET, NODE_TEXT_AREA_CONTENT_RECT, NODE_TEXT_AREA_CONTENT_LINE_COUNT, NODE_TEXT_AREA_TEXT_SELECTION,<br>NODE_TEXT_AREA_ENABLE_AUTO_FILL, NODE_TEXT_AREA_CONTENT_TYPE, NODE_TEXT_AREA_NUMBER_OF_LINES, NODE_TEXT_AREA_SHOW_KEYBOARD_ON_FOCUS,<br>NODE_BUTTON_LABEL = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_BUTTON, NODE_BUTTON_TYPE, NODE_PROGRESS_VALUE = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_PROGRESS, NODE_PROGRESS_TOTAL,<br>NODE_PROGRESS_COLOR, NODE_PROGRESS_TYPE, NODE_CHECKBOX_SELECT = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_CHECKBOX, NODE_CHECKBOX_SELECT_COLOR,<br>NODE_CHECKBOX_UNSELECT_COLOR, NODE_CHECKBOX_MARK, NODE_CHECKBOX_SHAPE, NODE_XCOMPONENT_ID = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_XCOMPONENT,<br>NODE_XCOMPONENT_TYPE, NODE_XCOMPONENT_SURFACE_SIZE, NODE_DATE_PICKER_LUNAR = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_DATE_PICKER, NODE_DATE_PICKER_START,<br>NODE_DATE_PICKER_END, NODE_DATE_PICKER_SELECTED, NODE_DATE_PICKER_DISAPPEAR_TEXT_STYLE, NODE_DATE_PICKER_TEXT_STYLE,<br>NODE_DATE_PICKER_SELECTED_TEXT_STYLE, NODE_TIME_PICKER_SELECTED = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_TIME_PICKER, NODE_TIME_PICKER_USE_MILITARY_TIME, NODE_TIME_PICKER_DISAPPEAR_TEXT_STYLE,<br>NODE_TIME_PICKER_TEXT_STYLE, NODE_TIME_PICKER_SELECTED_TEXT_STYLE, NODE_TEXT_PICKER_OPTION_RANGE = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_TEXT_PICKER, NODE_TEXT_PICKER_OPTION_SELECTED,<br>NODE_TEXT_PICKER_OPTION_VALUE, NODE_TEXT_PICKER_DISAPPEAR_TEXT_STYLE, NODE_TEXT_PICKER_TEXT_STYLE, NODE_TEXT_PICKER_SELECTED_TEXT_STYLE,<br>NODE_TEXT_PICKER_SELECTED_INDEX, NODE_TEXT_PICKER_CAN_LOOP, NODE_TEXT_PICKER_DEFAULT_PICKER_ITEM_HEIGHT, NODE_CALENDAR_PICKER_HINT_RADIUS = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_CALENDAR_PICKER,<br>NODE_CALENDAR_PICKER_SELECTED_DATE, NODE_CALENDAR_PICKER_EDGE_ALIGNMENT, NODE_CALENDAR_PICKER_TEXT_STYLE, NODE_SLIDER_BLOCK_COLOR = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_SLIDER,<br>NODE_SLIDER_TRACK_COLOR, NODE_SLIDER_SELECTED_COLOR, NODE_SLIDER_SHOW_STEPS, NODE_SLIDER_BLOCK_STYLE,<br>NODE_SLIDER_VALUE, NODE_SLIDER_MIN_VALUE, NODE_SLIDER_MAX_VALUE, NODE_SLIDER_STEP,<br>NODE_SLIDER_DIRECTION, NODE_SLIDER_REVERSE, NODE_SLIDER_STYLE, NODE_SLIDER_TRACK_THICKNESS,<br>NODE_RADIO_CHECKED = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_RADIO, NODE_RADIO_STYLE, NODE_RADIO_VALUE, NODE_RADIO_GROUP,<br>NODE_STACK_ALIGN_CONTENT = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_STACK, NODE_SCROLL_BAR_DISPLAY_MODE = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_SCROLL, NODE_SCROLL_BAR_WIDTH, NODE_SCROLL_BAR_COLOR,<br>NODE_SCROLL_SCROLL_DIRECTION, NODE_SCROLL_EDGE_EFFECT, NODE_SCROLL_ENABLE_SCROLL_INTERACTION, NODE_SCROLL_FRICTION,<br>NODE_SCROLL_SNAP, NODE_SCROLL_NESTED_SCROLL, NODE_SCROLL_OFFSET, NODE_SCROLL_EDGE,<br>NODE_SCROLL_ENABLE_PAGING, NODE_SCROLL_PAGE, NODE_SCROLL_BY, NODE_LIST_DIRECTION = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_LIST,<br>NODE_LIST_STICKY, NODE_LIST_SPACE, NODE_LIST_NODE_ADAPTER, NODE_LIST_CACHED_COUNT,<br>NODE_LIST_SCROLL_TO_INDEX, NODE_LIST_ALIGN_LIST_ITEM, NODE_LIST_CHILDREN_MAIN_SIZE = 1003007, NODE_SWIPER_LOOP = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_SWIPER, NODE_SWIPER_AUTO_PLAY,<br>NODE_SWIPER_SHOW_INDICATOR, NODE_SWIPER_INTERVAL, NODE_SWIPER_VERTICAL, NODE_SWIPER_DURATION,<br>NODE_SWIPER_CURVE, NODE_SWIPER_ITEM_SPACE, NODE_SWIPER_INDEX, NODE_SWIPER_DISPLAY_COUNT,<br>NODE_SWIPER_DISABLE_SWIPE, NODE_SWIPER_SHOW_DISPLAY_ARROW, NODE_SWIPER_EDGE_EFFECT_MODE, NODE_SWIPER_NODE_ADAPTER,<br>NODE_SWIPER_CACHED_COUNT, NODE_SWIPER_PREV_MARGIN, NODE_SWIPER_NEXT_MARGIN, NODE_SWIPER_INDICATOR,<br>NODE_SWIPER_NESTED_SCROLL, NODE_SWIPER_SWIPE_TO_INDEX, NODE_LIST_ITEM_GROUP_SET_HEADER = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_LIST_ITEM_GROUP, NODE_LIST_ITEM_GROUP_SET_FOOTER,<br>NODE_LIST_ITEM_GROUP_SET_DIVIDER, NODE_LIST_ITEM_GROUP_CHILDREN_MAIN_SIZE = 1005003, NODE_COLUMN_ALIGN_ITEMS = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_COLUMN, NODE_COLUMN_JUSTIFY_CONTENT, NODE_ROW_ALIGN_ITEMS = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_ROW,<br>NODE_ROW_JUSTIFY_CONTENT, NODE_FLEX_OPTION = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_FLEX, NODE_REFRESH_REFRESHING = MAX_NODE_SCOPE_NUM \* <br>NODE_REFRESH_PULL_DOWN_RATIO = 1009002,<br>NODE_WATER_FLOW_LAYOUT_DIRECTION = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_WATER_FLOW, NODE_WATER_FLOW_COLUMN_TEMPLATE, NODE_WATER_FLOW_ROW_TEMPLATE, NODE_WATER_FLOW_COLUMN_GAP,<br>NODE_WATER_FLOW_ROW_GAP, NODE_WATER_FLOW_SECTION_OPTION, NODE_WATER_FLOW_NODE_ADAPTER, NODE_WATER_FLOW_CACHED_COUNT,<br>NODE_WATER_FLOW_ITEM_CONSTRAINT_SIZE, NODE_WATER_FLOW_FOOTER, NODE_WATER_FLOW_SCROLL_TO_INDEX, NODE_RELATIVE_CONTAINER_GUIDE_LINE = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_RELATIVE_CONTAINER,<br>NODE_RELATIVE_CONTAINER_BARRIER, NODE_GRID_COLUMN_TEMPLATE = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_GRID, NODE_GRID_ROW_TEMPLATE, NODE_GRID_COLUMN_GAP,<br>NODE_GRID_ROW_GAP, NODE_GRID_NODE_ADAPTER, NODE_GRID_CACHED_COUNT<br>, NODE_LIST_ITEM_SWIPE_ACTION = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_LIST_ITEM, NODE_IMAGE_ANIMATOR_IMAGES = ARKUI_NODE_IMAGE_ANIMATOR \* MAX_NODE_SCOPE_NUM, NODE_IMAGE_ANIMATOR_STATE,<br>NODE_IMAGE_ANIMATOR_DURATION, NODE_IMAGE_ANIMATOR_REVERSE, NODE_IMAGE_ANIMATOR_FIXED_SIZE, NODE_IMAGE_ANIMATOR_FILL_MODE,<br>NODE_IMAGE_ANIMATOR_ITERATION<br>} | Defines the ArkUI style attributes that can be set on the native side. |
| [ArkUI_NodeEventType](#arkui_nodeeventtype) {<br>NODE_TOUCH_EVENT = 0, NODE_EVENT_ON_APPEAR, NODE_EVENT_ON_DISAPPEAR, NODE_EVENT_ON_AREA_CHANGE,<br>NODE_ON_FOCUS, NODE_ON_BLUR, NODE_ON_CLICK, NODE_ON_TOUCH_INTERCEPT,<br>NODE_EVENT_ON_VISIBLE_AREA_CHANGE, NODE_ON_HOVER, NODE_ON_MOUSE, NODE_TEXT_ON_DETECT_RESULT_UPDATE = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_TEXT,<br>NODE_IMAGE_ON_COMPLETE = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_IMAGE, NODE_IMAGE_ON_ERROR, NODE_IMAGE_ON_SVG_PLAY_FINISH, NODE_IMAGE_ON_DOWNLOAD_PROGRESS,<br>NODE_TOGGLE_ON_CHANGE = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_TOGGLE, NODE_TEXT_INPUT_ON_CHANGE = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_TEXT_INPUT, NODE_TEXT_INPUT_ON_SUBMIT, NODE_TEXT_INPUT_ON_CUT,<br>NODE_TEXT_INPUT_ON_PASTE, NODE_TEXT_INPUT_ON_TEXT_SELECTION_CHANGE, NODE_TEXT_INPUT_ON_EDIT_CHANGE, NODE_TEXT_INPUT_ON_INPUT_FILTER_ERROR,<br>NODE_TEXT_INPUT_ON_CONTENT_SCROLL, NODE_TEXT_INPUT_ON_CONTENT_SIZE_CHANGE, NODE_TEXT_AREA_ON_CHANGE = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_TEXT_AREA, NODE_TEXT_AREA_ON_PASTE,<br>NODE_TEXT_AREA_ON_TEXT_SELECTION_CHANGE, NODE_TEXT_AREA_ON_EDIT_CHANGE, NODE_TEXT_AREA_ON_SUBMIT, NODE_TEXT_AREA_ON_INPUT_FILTER_ERROR,<br>NODE_TEXT_AREA_ON_CONTENT_SCROLL, NODE_TEXT_AREA_ON_CONTENT_SIZE_CHANGE, NODE_CHECKBOX_EVENT_ON_CHANGE = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_CHECKBOX, NODE_DATE_PICKER_EVENT_ON_DATE_CHANGE = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_DATE_PICKER,<br>NODE_TIME_PICKER_EVENT_ON_CHANGE = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_TIME_PICKER, NODE_TEXT_PICKER_EVENT_ON_CHANGE = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_TEXT_PICKER, NODE_CALENDAR_PICKER_EVENT_ON_CHANGE = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_CALENDAR_PICKER, NODE_SLIDER_EVENT_ON_CHANGE = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_SLIDER,<br>NODE_RADIO_EVENT_ON_CHANGE = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_RADIO, NODE_SWIPER_EVENT_ON_CHANGE = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_SWIPER, NODE_SWIPER_EVENT_ON_ANIMATION_START, NODE_SWIPER_EVENT_ON_ANIMATION_END,<br>NODE_SWIPER_EVENT_ON_GESTURE_SWIPE, NODE_SWIPER_EVENT_ON_CONTENT_DID_SCROLL, NODE_SCROLL_EVENT_ON_SCROLL = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_SCROLL, NODE_SCROLL_EVENT_ON_SCROLL_FRAME_BEGIN, NODE_SCROLL_EVENT_ON_WILL_SCROLL,<br>NODE_SCROLL_EVENT_ON_DID_SCROLL, NODE_SCROLL_EVENT_ON_SCROLL_START, NODE_SCROLL_EVENT_ON_SCROLL_STOP, NODE_SCROLL_EVENT_ON_SCROLL_EDGE,<br>NODE_SCROLL_EVENT_ON_REACH_END, NODE_SCROLL_EVENT_ON_REACH_START, NODE_LIST_ON_SCROLL_INDEX = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_LIST, NODE_LIST_ON_WILL_SCROLL,<br>NODE_LIST_ON_DID_SCROLL, NODE_REFRESH_STATE_CHANGE = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_REFRESH, NODE_REFRESH_ON_REFRESH, <br>NODE_REFRESH_ON_OFFSET_CHANGE, NODE_WATER_FLOW_ON_WILL_SCROLL = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_WATER_FLOW,<br>NODE_WATER_FLOW_ON_DID_SCROLL, NODE_WATER_FLOW_ON_SCROLL_INDEX, NODE_IMAGE_ANIMATOR_EVENT_ON_START = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_IMAGE_ANIMATOR, NODE_IMAGE_ANIMATOR_EVENT_ON_PAUSE, NODE_IMAGE_ANIMATOR_EVENT_ON_REPEAT, NODE_IMAGE_ANIMATOR_EVENT_ON_CANCEL,<br>NODE_IMAGE_ANIMATOR_EVENT_ON_FINISH<br>} | Enumerates the event types supported by the NativeNode component. |
| [ArkUI_NodeDirtyFlag](#arkui_nodedirtyflag) { NODE_NEED_MEASURE = 1, NODE_NEED_LAYOUT, NODE_NEED_RENDER } | Enumerates the dirty area flags passed in the **::markDirty** API. |
| [ArkUI_NodeCustomEventType](#arkui_nodecustomeventtype) {<br>ARKUI_NODE_CUSTOM_EVENT_ON_MEASURE = 1 &lt;&lt; 0, ARKUI_NODE_CUSTOM_EVENT_ON_LAYOUT = 1 &lt;&lt; 1, ARKUI_NODE_CUSTOM_EVENT_ON_DRAW = 1 &lt;&lt; 2, ARKUI_NODE_CUSTOM_EVENT_ON_FOREGROUND_DRAW = 1 &lt;&lt; 3,<br>ARKUI_NODE_CUSTOM_EVENT_ON_OVERLAY_DRAW = 1 &lt;&lt; 4<br>} | Enumerates the custom component event types. |
| [ArkUI_NodeAdapterEventType](#arkui_nodeadaptereventtype) {<br>NODE_ADAPTER_EVENT_WILL_ATTACH_TO_NODE = 1, NODE_ADAPTER_EVENT_WILL_DETACH_FROM_NODE = 2, NODE_ADAPTER_EVENT_ON_GET_NODE_ID = 3, NODE_ADAPTER_EVENT_ON_ADD_NODE_TO_ADAPTER = 4,<br>NODE_ADAPTER_EVENT_ON_REMOVE_NODE_FROM_ADAPTER = 5<br>} | Enumerates node adapter events. |
| [ArkUI_Alignment](#arkui_alignment) {<br>ARKUI_ALIGNMENT_TOP_START = 0, ARKUI_ALIGNMENT_TOP, ARKUI_ALIGNMENT_TOP_END, ARKUI_ALIGNMENT_START,<br>ARKUI_ALIGNMENT_CENTER, ARKUI_ALIGNMENT_END, ARKUI_ALIGNMENT_BOTTOM_START, ARKUI_ALIGNMENT_BOTTOM,<br>ARKUI_ALIGNMENT_BOTTOM_END<br>} | Enumerates the alignment modes. |
| [ArkUI_ImageRepeat](#arkui_imagerepeat) { ARKUI_IMAGE_REPEAT_NONE = 0, ARKUI_IMAGE_REPEAT_X, ARKUI_IMAGE_REPEAT_Y, ARKUI_IMAGE_REPEAT_XY } | Enumerates the image repeat patterns. |
| [ArkUI_FontStyle](#arkui_fontstyle) { ARKUI_FONT_STYLE_NORMAL = 0, ARKUI_FONT_STYLE_ITALIC } | Enumerates the font styles. |
| [ArkUI_FontWeight](#arkui_fontweight) {<br>ARKUI_FONT_WEIGHT_W100 = 0, ARKUI_FONT_WEIGHT_W200, ARKUI_FONT_WEIGHT_W300, ARKUI_FONT_WEIGHT_W400,<br>ARKUI_FONT_WEIGHT_W500, ARKUI_FONT_WEIGHT_W600, ARKUI_FONT_WEIGHT_W700, ARKUI_FONT_WEIGHT_W800,<br>ARKUI_FONT_WEIGHT_W900, ARKUI_FONT_WEIGHT_BOLD, ARKUI_FONT_WEIGHT_NORMAL, ARKUI_FONT_WEIGHT_BOLDER,<br>ARKUI_FONT_WEIGHT_LIGHTER, ARKUI_FONT_WEIGHT_MEDIUM, ARKUI_FONT_WEIGHT_REGULAR<br>} | Enumerates the font weights. |
| [ArkUI_TextAlignment](#arkui_textalignment) { ARKUI_TEXT_ALIGNMENT_START = 0, ARKUI_TEXT_ALIGNMENT_CENTER, ARKUI_TEXT_ALIGNMENT_END, ARKUI_TEXT_ALIGNMENT_JUSTIFY } | Enumerates the text alignment mode. |
| [ArkUI_EnterKeyType](#arkui_enterkeytype) {<br>ARKUI_ENTER_KEY_TYPE_GO = 2, ARKUI_ENTER_KEY_TYPE_SEARCH = 3, ARKUI_ENTER_KEY_TYPE_SEND, ARKUI_ENTER_KEY_TYPE_NEXT,<br>ARKUI_ENTER_KEY_TYPE_DONE, ARKUI_ENTER_KEY_TYPE_PREVIOUS, ARKUI_ENTER_KEY_TYPE_NEW_LINE<br>} | Enumerates the types of the Enter key for a single-line text box. |
| [ArkUI_TextInputType](#arkui_textinputtype) {<br>ARKUI_TEXTINPUT_TYPE_NORMAL = 0, ARKUI_TEXTINPUT_TYPE_NUMBER = 2, ARKUI_TEXTINPUT_TYPE_PHONE_NUMBER = 3, ARKUI_TEXTINPUT_TYPE_EMAIL = 5,<br>ARKUI_TEXTINPUT_TYPE_PASSWORD = 7, ARKUI_TEXTINPUT_TYPE_NUMBER_PASSWORD = 8, ARKUI_TEXTINPUT_TYPE_SCREEN_LOCK_PASSWORD = 9, ARKUI_TEXTINPUT_TYPE_USER_NAME = 10,<br>ARKUI_TEXTINPUT_TYPE_NEW_PASSWORD = 11, ARKUI_TEXTINPUT_TYPE_NUMBER_DECIMAL = 12<br>} | Enumerates the text input types. |
| [ArkUI_TextAreaType](#arkui_textareatype) { ARKUI_TEXTAREA_TYPE_NORMAL = 0, ARKUI_TEXTAREA_TYPE_NUMBER = 2, ARKUI_TEXTAREA_TYPE_PHONE_NUMBER = 3, ARKUI_TEXTAREA_TYPE_EMAIL = 5 } | Enumerates the text box types. |
| [ArkUI_CancelButtonStyle](#arkui_cancelbuttonstyle) { ARKUI_CANCELBUTTON_STYLE_CONSTANT = 0, ARKUI_CANCELBUTTON_STYLE_INVISIBLE, ARKUI_CANCELBUTTON_STYLE_INPUT } | Enumerates the styles of the Cancel button. |
| [ArkUI_XComponentType](#arkui_xcomponenttype) { ARKUI_XCOMPONENT_TYPE_SURFACE = 0, ARKUI_XCOMPONENT_TYPE_TEXTURE = 2 } | Enumerates the types of the **\<XComponent>**. |
| [ArkUI_ProgressType](#arkui_progresstype) {<br>ARKUI_PROGRESS_TYPE_LINEAR = 0, ARKUI_PROGRESS_TYPE_RING, ARKUI_PROGRESS_TYPE_ECLIPSE, ARKUI_PROGRESS_TYPE_SCALE_RING,<br>ARKUI_PROGRESS_TYPE_CAPSULE<br>} | Enumerates the styles of the progress indicator. |
| [ArkUI_TextDecorationType](#arkui_textdecorationtype) { ARKUI_TEXT_DECORATION_TYPE_NONE = 0, ARKUI_TEXT_DECORATION_TYPE_UNDERLINE, ARKUI_TEXT_DECORATION_TYPE_OVERLINE, ARKUI_TEXT_DECORATION_TYPE_LINE_THROUGH } | Enumerates the text decoration types. |
| [ArkUI_TextDecorationStyle](#arkui_textdecorationstyle) {<br>ARKUI_TEXT_DECORATION_STYLE_SOLID = 0, ARKUI_TEXT_DECORATION_STYLE_DOUBLE, ARKUI_TEXT_DECORATION_STYLE_DOTTED, ARKUI_TEXT_DECORATION_STYLE_DASHED,<br>ARKUI_TEXT_DECORATION_STYLE_WAVY<br>} | Enumerates the text decoration styles. |
| [ArkUI_TextCase](#arkui_textcase) { ARKUI_TEXT_CASE_NORMAL = 0, ARKUI_TEXT_CASE_LOWER, ARKUI_TEXT_CASE_UPPER } | Enumerates the text cases. |
| [ArkUI_CopyOptions](#arkui_copyoptions) { ARKUI_COPY_OPTIONS_NONE = 0, ARKUI_COPY_OPTIONS_IN_APP, ARKUI_COPY_OPTIONS_LOCAL_DEVICE, ARKUI_COPY_OPTIONS_CROSS_DEVICE } | Enumerates the text copy and paste modes. |
| [ArkUI_ShadowType](#arkui_shadowtype) { ARKUI_SHADOW_TYPE_COLOR = 0, ARKUI_SHADOW_TYPE_BLUR } | Enumerates the shadow types. |
| [ArkUI_TextPickerRangeType](#arkui_textpickerrangetype) { ARKUI_TEXTPICKER_RANGETYPE_SINGLE = 0, ARKUI_TEXTPICKER_RANGETYPE_MULTI, ARKUI_TEXTPICKER_RANGETYPE_RANGE_CONTENT, ARKUI_TEXTPICKER_RANGETYPE_CASCADE_RANGE_CONTENT } | Enumerates the types of the text picker. |
| [ArkUI_EdgeEffect](#arkui_edgeeffect) { ARKUI_EDGE_EFFECT_SPRING = 0, ARKUI_EDGE_EFFECT_FADE, ARKUI_EDGE_EFFECT_NONE } | Enumerates the effects used at the edges of the component when the boundary of the scrollable content is reached. |
| [ArkUI_ScrollDirection](#arkui_scrolldirection) { ARKUI_SCROLL_DIRECTION_VERTICAL = 0, ARKUI_SCROLL_DIRECTION_HORIZONTAL, ARKUI_SCROLL_DIRECTION_NONE = 3 } | Enumerates the scroll directions of scrollable components. |
| [ArkUI_ScrollSnapAlign](#arkui_scrollsnapalign) { ARKUI_SCROLL_SNAP_ALIGN_NONE = 0, ARKUI_SCROLL_SNAP_ALIGN_START, ARKUI_SCROLL_SNAP_ALIGN_CENTER, ARKUI_SCROLL_SNAP_ALIGN_END } | Enumerates the alignment modes of list items when scrolling ends. |
| [ArkUI_ScrollBarDisplayMode](#arkui_scrollbardisplaymode) { ARKUI_SCROLL_BAR_DISPLAY_MODE_OFF = 0, ARKUI_SCROLL_BAR_DISPLAY_MODE_AUTO, ARKUI_SCROLL_BAR_DISPLAY_MODE_ON } | Enumerates the scrollbar display modes. |
| [ArkUI_Axis](#arkui_axis) { ARKUI_AXIS_VERTICAL = 0, ARKUI_AXIS_HORIZONTAL } | Enumerates the scroll directions. |
| [ArkUI_StickyStyle](#arkui_stickystyle) { ARKUI_STICKY_STYLE_NONE = 0, ARKUI_STICKY_STYLE_HEADER = 1, ARKUI_STICKY_STYLE_FOOTER = 2, ARKUI_STICKY_STYLE_BOTH = 3 } | Enumerates the modes for pinning the header to the top or the footer to the bottom. |
| [ArkUI_BorderStyle](#arkui_borderstyle) { ARKUI_BORDER_STYLE_SOLID = 0, ARKUI_BORDER_STYLE_DASHED, ARKUI_BORDER_STYLE_DOTTED } | Enumerates the border styles. |
| [ArkUI_HitTestMode](#arkui_hittestmode) { ARKUI_HIT_TEST_MODE_DEFAULT = 0, ARKUI_HIT_TEST_MODE_BLOCK, ARKUI_HIT_TEST_MODE_TRANSPARENT, ARKUI_HIT_TEST_MODE_NONE } | Enumerates the hit test modes. |
| [ArkUI_ShadowStyle](#arkui_shadowstyle) {<br>ARKUI_SHADOW_STYLE_OUTER_DEFAULT_XS = 0, ARKUI_SHADOW_STYLE_OUTER_DEFAULT_SM, ARKUI_SHADOW_STYLE_OUTER_DEFAULT_MD, ARKUI_SHADOW_STYLE_OUTER_DEFAULT_LG,<br>ARKUI_SHADOW_STYLE_OUTER_FLOATING_SM, ARKUI_SHADOW_STYLE_OUTER_FLOATING_MD<br>} | Enumerated value of the shadow effect. |
| [ArkUI_AnimationCurve](#arkui_animationcurve) {<br>ARKUI_CURVE_LINEAR = 0, ARKUI_CURVE_EASE, ARKUI_CURVE_EASE_IN, ARKUI_CURVE_EASE_OUT,<br>ARKUI_CURVE_EASE_IN_OUT, ARKUI_CURVE_FAST_OUT_SLOW_IN, ARKUI_CURVE_LINEAR_OUT_SLOW_IN, ARKUI_CURVE_FAST_OUT_LINEAR_IN,<br>ARKUI_CURVE_EXTREME_DECELERATION, ARKUI_CURVE_SHARP, ARKUI_CURVE_RHYTHM, ARKUI_CURVE_SMOOTH,<br>ARKUI_CURVE_FRICTION<br>} | Enumerates the animation curves. |
| [ArkUI_SwiperArrow](#arkui_swiperarrow) { ARKUI_SWIPER_ARROW_HIDE = 0, ARKUI_SWIPER_ARROW_SHOW, ARKUI_SWIPER_ARROW_SHOW_ON_HOVER } | Enumerates arrow styles of the navigation point indicator. |
| [ArkUI_SwiperNestedScrollMode](#arkui_swipernestedscrollmode) { ARKUI_SWIPER_NESTED_SRCOLL_SELF_ONLY = 0, ARKUI_SWIPER_NESTED_SRCOLL_SELF_FIRST } | Enumerates the nested scrolling mode of the **\<Swiper>**component and its parent container. |
| [ArkUI_AccessibilityMode](#arkui_accessibilitymode) { ARKUI_ACCESSIBILITY_MODE_AUTO = 0, ARKUI_ACCESSIBILITY_MODE_ENABLED, ARKUI_ACCESSIBILITY_MODE_DISABLED, ARKUI_ACCESSIBILITY_MODE_DISABLED_FOR_DESCENDANTS } | Enumerates the accessibility modes. |
| [ArkUI_TextCopyOptions](#arkui_textcopyoptions) { ARKUI_TEXT_COPY_OPTIONS_NONE = 0, ARKUI_TEXT_COPY_OPTIONS_IN_APP, ARKUI_TEXT_COPY_OPTIONS_LOCAL_DEVICE, ARKUI_TEXT_COPY_OPTIONS_CROSS_DEVICE } | Defines whether copy and paste is allowed for text content. |
| [ArkUI_TextHeightAdaptivePolicy](#arkui_textheightadaptivepolicy) { ARKUI_TEXT_HEIGHT_ADAPTIVE_POLICY_MAX_LINES_FIRST = 0, ARKUI_TEXT_HEIGHT_ADAPTIVE_POLICY_MIN_FONT_SIZE_FIRST, ARKUI_TEXT_HEIGHT_ADAPTIVE_POLICY_LAYOUT_CONSTRAINT_FIRST } | Defines how the adaptive height is determined for the text. |
| [ArkUI_ScrollNestedMode](#arkui_scrollnestedmode) { ARKUI_SCROLL_NESTED_MODE_SELF_ONLY = 0, ARKUI_SCROLL_NESTED_MODE_SELF_FIRST, ARKUI_SCROLL_NESTED_MODE_PARENT_FIRST, ARKUI_SCROLL_NESTED_MODE_PARALLEL } | Enumerates the nested scrolling modes. |
| [ArkUI_ScrollEdge](#arkui_scrolledge) { ARKUI_SCROLL_EDGE_TOP = 0, ARKUI_SCROLL_EDGE_BOTTOM, ARKUI_SCROLL_EDGE_START, ARKUI_SCROLL_EDGE_END } | Defines the edge to which the component scrolls. |
| [ArkUI_ScrollAlignment](#arkui_scrollalignment) { ARKUI_SCROLL_ALIGNMENT_START = 0, ARKUI_SCROLL_ALIGNMENT_CENTER, ARKUI_SCROLL_ALIGNMENT_END, ARKUI_SCROLL_ALIGNMENT_AUTO } | Defines how the list item to scroll to is aligned with the container. |
| [ArkUI_ScrollState](#arkui_scrollstate) { ARKUI_SCROLL_STATE_IDLE = 0, ARKUI_SCROLL_STATE_SCROLL, ARKUI_SCROLL_STATE_FLING } | Enumerates the scrolling states. |
| [ArkUI_SliderBlockStyle](#arkui_sliderblockstyle) { ARKUI_SLIDER_BLOCK_STYLE_DEFAULT = 0, ARKUI_SLIDER_BLOCK_STYLE_IMAGE, ARKUI_SLIDER_BLOCK_STYLE_SHAPE } | Enumerates the types of the slider in the block direction. |
| [ArkUI_SliderDirection](#arkui_sliderdirection) { ARKUI_SLIDER_DIRECTION_VERTICAL = 0, ARKUI_SLIDER_DIRECTION_HORIZONTAL } | Enumerates the scroll directions of the slider. |
| [ArkUI_SliderStyle](#arkui_sliderstyle) { ARKUI_SLIDER_STYLE_OUT_SET = 0, ARKUI_SLIDER_STYLE_IN_SET } | Enumerates the slider styles. |
| [ArkUI_CheckboxShape](#arkui_checkboxshape) { ArkUI_CHECKBOX_SHAPE_CIRCLE = 0, ArkUI_CHECKBOX_SHAPE_ROUNDED_SQUARE } | Enumerates the shapes of the check box. |
| [ArkUI_AnimationPlayMode](#arkui_animationplaymode) { ARKUI_ANIMATION_PLAY_MODE_NORMAL = 0, ARKUI_ANIMATION_PLAY_MODE_REVERSE, ARKUI_ANIMATION_PLAY_MODE_ALTERNATE, ARKUI_ANIMATION_PLAY_MODE_ALTERNATE_REVERSE } | Enumerates the animation playback modes. |
| [ArkUI_ImageSize](#arkui_imagesize) { ARKUI_IMAGE_SIZE_AUTO = 0, ARKUI_IMAGE_SIZE_COVER, ARKUI_IMAGE_SIZE_CONTAIN } | Defines the image size. |
| [ArkUI_AdaptiveColor](#arkui_adaptivecolor) { ARKUI_ADAPTIVE_COLOR_DEFAULT = 0, ARKUI_ADAPTIVE_COLOR_AVERAGE } | Enumerates the adaptive color modes. |
| [ArkUI_ColorMode](#arkui_colormode) { ARKUI_COLOR_MODE_SYSTEM = 0, ARKUI_COLOR_MODE_LIGHT, ARKUI_COLOR_MODE_DARK } | Enumerates the color modes. |
| [ArkUI_BlurStyle](#arkui_blurstyle) {<br>ARKUI_BLUR_STYLE_THIN = 0, ARKUI_BLUR_STYLE_REGULAR, ARKUI_BLUR_STYLE_THICK, ARKUI_BLUR_STYLE_BACKGROUND_THIN,<br>ARKUI_BLUR_STYLE_BACKGROUND_REGULAR, ARKUI_BLUR_STYLE_BACKGROUND_THICK, ARKUI_BLUR_STYLE_BACKGROUND_ULTRA_THICK, ARKUI_BLUR_STYLE_NONE,<br>ARKUI_BLUR_STYLE_COMPONENT_ULTRA_THIN, ARKUI_BLUR_STYLE_COMPONENT_THIN, ARKUI_BLUR_STYLE_COMPONENT_REGULAR, ARKUI_BLUR_STYLE_COMPONENT_THICK,<br>ARKUI_BLUR_STYLE_COMPONENT_ULTRA_THICK<br>} | Enumerates the blur styles. |
| [ArkUI_VerticalAlignment](#arkui_verticalalignment) { ARKUI_VERTICAL_ALIGNMENT_TOP = 0, ARKUI_VERTICAL_ALIGNMENT_CENTER, ARKUI_VERTICAL_ALIGNMENT_BOTTOM } | Enumerates the vertical alignment modes. |
| [ArkUI_HorizontalAlignment](#arkui_horizontalalignment) { ARKUI_HORIZONTAL_ALIGNMENT_START = 0, ARKUI_HORIZONTAL_ALIGNMENT_CENTER, ARKUI_HORIZONTAL_ALIGNMENT_END } | Enumerates the alignment mode in the horizontal direction. |
| [ArkUI_TextOverflow](#arkui_textoverflow) { ARKUI_TEXT_OVERFLOW_NONE = 0, ARKUI_TEXT_OVERFLOW_CLIP, ARKUI_TEXT_OVERFLOW_ELLIPSIS, ARKUI_TEXT_OVERFLOW_MARQUEE } | Enumerates the display modes when the text is too long. |
| [ArkUI_ImageSpanAlignment](#arkui_imagespanalignment) { ARKUI_IMAGE_SPAN_ALIGNMENT_BASELINE = 0, ARKUI_IMAGE_SPAN_ALIGNMENT_BOTTOM, ARKUI_IMAGE_SPAN_ALIGNMENT_CENTER, ARKUI_IMAGE_SPAN_ALIGNMENT_TOP } | Enumerates the alignment mode of the image with the text. |
| [ArkUI_ObjectFit](#arkui_objectfit) {<br>ARKUI_OBJECT_FIT_CONTAIN = 0, ARKUI_OBJECT_FIT_COVER, ARKUI_OBJECT_FIT_AUTO, ARKUI_OBJECT_FIT_FILL,<br>ARKUI_OBJECT_FIT_SCALE_DOWN, ARKUI_OBJECT_FIT_NONE<br>} | Defines how the image is resized to fit its container. ImageSpanAlignment  |
| [ArkUI_ImageInterpolation](#arkui_imageinterpolation) { ARKUI_IMAGE_INTERPOLATION_NONE = 0, ARKUI_IMAGE_INTERPOLATION_LOW, ARKUI_IMAGE_INTERPOLATION_MEDIUM, ARKUI_IMAGE_INTERPOLATION_HIGH } | Enumerates the image interpolation effects. |
| [ArkUI_BlendMode](#arkui_blendmode) {<br>ARKUI_BLEND_MODE_NONE = 0, ARKUI_BLEND_MODE_CLEAR, ARKUI_BLEND_MODE_SRC, ARKUI_BLEND_MODE_DST,<br>ARKUI_BLEND_MODE_SRC_OVER, ARKUI_BLEND_MODE_DST_OVER, ARKUI_BLEND_MODE_SRC_IN, ARKUI_BLEND_MODE_DST_IN,<br>ARKUI_BLEND_MODE_SRC_OUT, ARKUI_BLEND_MODE_DST_OUT, ARKUI_BLEND_MODE_SRC_ATOP, ARKUI_BLEND_MODE_DST_ATOP,<br>ARKUI_BLEND_MODE_XOR, ARKUI_BLEND_MODE_PLUS, ARKUI_BLEND_MODE_MODULATE, ARKUI_BLEND_MODE_SCREEN,<br>ARKUI_BLEND_MODE_OVERLAY, ARKUI_BLEND_MODE_DARKEN, ARKUI_BLEND_MODE_LIGHTEN, ARKUI_BLEND_MODE_COLOR_DODGE,<br>ARKUI_BLEND_MODE_COLOR_BURN, ARKUI_BLEND_MODE_HARD_LIGHT, ARKUI_BLEND_MODE_SOFT_LIGHT, ARKUI_BLEND_MODE_DIFFERENCE,<br>ARKUI_BLEND_MODE_EXCLUSION, ARKUI_BLEND_MODE_MULTIPLY, ARKUI_BLEND_MODE_HUE, ARKUI_BLEND_MODE_SATURATION,<br>ARKUI_BLEND_MODE_COLOR, ARKUI_BLEND_MODE_LUMINOSITY<br>} | Enumerates the blend modes. |
| [ArkUI_Direction](#arkui_direction) { ARKUI_DIRECTION_LTR = 0, ARKUI_DIRECTION_RTL, ARKUI_DIRECTION_AUTO = 3 } | Enumerates the modes in which components are laid out along the main axis of the container. |
| [ArkUI_ItemAlignment](#arkui_itemalignment) {<br>ARKUI_ITEM_ALIGNMENT_AUTO = 0, ARKUI_ITEM_ALIGNMENT_START, ARKUI_ITEM_ALIGNMENT_CENTER, ARKUI_ITEM_ALIGNMENT_END,<br>ARKUI_ITEM_ALIGNMENT_STRETCH, ARKUI_ITEM_ALIGNMENT_BASELINE<br>} | Enumerates the modes in which components are laid out along the cross axis of the container. |
| [ArkUI_ColorStrategy](#arkui_colorstrategy) { ARKUI_COLOR_STRATEGY_INVERT = 0, ARKUI_COLOR_STRATEGY_AVERAGE, ARKUI_COLOR_STRATEGY_PRIMARY } | Enumerates the foreground colors. |
| [ArkUI_FlexAlignment](#arkui_flexalignment) {<br>ARKUI_FLEX_ALIGNMENT_START = 1, ARKUI_FLEX_ALIGNMENT_CENTER = 2, ARKUI_FLEX_ALIGNMENT_END = 3, ARKUI_FLEX_ALIGNMENT_SPACE_BETWEEN = 6,<br>ARKUI_FLEX_ALIGNMENT_SPACE_AROUND = 7, ARKUI_FLEX_ALIGNMENT_SPACE_EVENLY = 8<br>} | Enumerates the vertical alignment modes. |
| [ArkUI_FlexDirection](#arkui_flexdirection) { ARKUI_FLEX_DIRECTION_ROW = 0, ARKUI_FLEX_DIRECTION_COLUMN, ARKUI_FLEX_DIRECTION_ROW_REVERSE, ARKUI_FLEX_DIRECTION_COLUMN_REVERSE } | Enumerates the directions of the main axis in the flex container. |
| [ArkUI_FlexWrap](#arkui_flexwrap) { ARKUI_FLEX_WRAP_NO_WRAP = 0, ARKUI_FLEX_WRAP_WRAP, ARKUI_FLEX_WRAP_WRAP_REVERSE } | Defines whether the flex container has a single line or multiple lines. |
| [ArkUI_Visibility](#arkui_visibility) { ARKUI_VISIBILITY_VISIBLE = 0, ARKUI_VISIBILITY_HIDDEN, ARKUI_VISIBILITY_NONE } | Enumerates the visibility values. |
| [ArkUI_CalendarAlignment](#arkui_calendaralignment) { ARKUI_CALENDAR_ALIGNMENT_START = 0, ARKUI_CALENDAR_ALIGNMENT_CENTER, ARKUI_CALENDAR_ALIGNMENT_END } | Enumerates the alignment modes between the calendar picker and the entry component. |
| [ArkUI_MaskType](#arkui_masktype) {<br>ARKUI_MASK_TYPE_RECTANGLE = 0, ARKUI_MASK_TYPE_CIRCLE, ARKUI_MASK_TYPE_ELLIPSE, ARKUI_MASK_TYPE_PATH,<br>ARKUI_MASK_TYPE_PROGRESS<br>} | Enumerates the mask types. |
| [ArkUI_ClipType](#arkui_cliptype) { ARKUI_CLIP_TYPE_RECTANGLE = 0, ARKUI_CLIP_TYPE_CIRCLE, ARKUI_CLIP_TYPE_ELLIPSE, ARKUI_CLIP_TYPE_PATH } | Enumerates the clipping region types. |
| [ArkUI_ShapeType](#arkui_shapetype) { ARKUI_SHAPE_TYPE_RECTANGLE = 0, ARKUI_SHAPE_TYPE_CIRCLE, ARKUI_SHAPE_TYPE_ELLIPSE, ARKUI_SHAPE_TYPE_PATH } | Enumerates custom shape types. |
| [ArkUI_LinearGradientDirection](#arkui_lineargradientdirection) {<br>ARKUI_LINEAR_GRADIENT_DIRECTION_LEFT = 0, ARKUI_LINEAR_GRADIENT_DIRECTION_TOP, ARKUI_LINEAR_GRADIENT_DIRECTION_RIGHT, ARKUI_LINEAR_GRADIENT_DIRECTION_BOTTOM,<br>ARKUI_LINEAR_GRADIENT_DIRECTION_LEFT_TOP, ARKUI_LINEAR_GRADIENT_DIRECTION_LEFT_BOTTOM, ARKUI_LINEAR_GRADIENT_DIRECTION_RIGHT_TOP, ARKUI_LINEAR_GRADIENT_DIRECTION_RIGHT_BOTTOM,<br>ARKUI_LINEAR_GRADIENT_DIRECTION_NONE, ARKUI_LINEAR_GRADIENT_DIRECTION_CUSTOM<br>} | Enumerates the gradient directions. |
| [ArkUI_WordBreak](#arkui_wordbreak) { ARKUI_WORD_BREAK_NORMAL = 0, ARKUI_WORD_BREAK_BREAK_ALL, ARKUI_WORD_BREAK_BREAK_WORD } | Enumerates the word break rules. |
| [ArkUI_EllipsisMode](#arkui_ellipsismode) { ARKUI_ELLIPSIS_MODE_START = 0, ARKUI_ELLIPSIS_MODE_CENTER, ARKUI_ELLIPSIS_MODE_END } | Enumerates the ellipsis positions. |
| [ArkUI_ImageRenderMode](#arkui_imagerendermode) { ARKUI_IMAGE_RENDER_MODE_ORIGINAL = 0, ARKUI_IMAGE_RENDER_MODE_TEMPLATE } | Enumerates the image rendering modes. |
| [ArkUI_TransitionEdge](#arkui_transitionedge) { ARKUI_TRANSITION_EDGE_TOP = 0, ARKUI_TRANSITION_EDGE_BOTTOM, ARKUI_TRANSITION_EDGE_START, ARKUI_TRANSITION_EDGE_END } | Enumerates the slide-in and slide-out positions of the component from the screen edge during transition. |
| [ArkUI_FinishCallbackType](#arkui_finishcallbacktype) { ARKUI_FINISH_CALLBACK_REMOVED = 0, ARKUI_FINISH_CALLBACK_LOGICALLY } | Enumerates the animation **onFinish** callback types. |
| [ArkUI_ListItemAlignment](#arkui_listitemalignment) { ARKUI_LIST_ITEM_ALIGNMENT_START = 0, ARKUI_LIST_ITEM_ALIGNMENT_CENTER, ARKUI_LIST_ITEM_ALIGNMENT_END } | Enumerates the alignment modes of items along the cross axis. |
| [ArkUI_BlendApplyType](#arkui_blendapplytype) { BLEND_APPLY_TYPE_FAST = 0, BLEND_APPLY_TYPE_OFFSCREEN } | Defines how the specified blend mode is applied. |
| [ArkUI_LengthMetricUnit](#arkui_lengthmetricunit) { ARKUI_LENGTH_METRIC_UNIT_DEFAULT = -1, ARKUI_LENGTH_METRIC_UNIT_PX = 0, ARKUI_LENGTH_METRIC_UNIT_VP, ARKUI_LENGTH_METRIC_UNIT_FP } | Enumerates the component units. |
| [ArkUI_TextInputContentType](#arkui_textinputcontenttype) {<br>ARKUI_TEXTINPUT_CONTENT_TYPE_USER_NAME = 0, ARKUI_TEXTINPUT_CONTENT_TYPE_PASSWORD, ARKUI_TEXTINPUT_CONTENT_TYPE_NEW_PASSWORD, ARKUI_TEXTINPUT_CONTENT_TYPE_FULL_STREET_ADDRESS,<br>ARKUI_TEXTINPUT_CONTENT_TYPE_HOUSE_NUMBER, ARKUI_TEXTINPUT_CONTENT_TYPE_DISTRICT_ADDRESS, ARKUI_TEXTINPUT_CONTENT_TYPE_CITY_ADDRESS, ARKUI_TEXTINPUT_CONTENT_TYPE_PROVINCE_ADDRESS,<br>ARKUI_TEXTINPUT_CONTENT_TYPE_COUNTRY_ADDRESS, ARKUI_TEXTINPUT_CONTENT_TYPE_PERSON_FULL_NAME, ARKUI_TEXTINPUT_CONTENT_TYPE_PERSON_LAST_NAME, ARKUI_TEXTINPUT_CONTENT_TYPE_PERSON_FIRST_NAME,<br>ARKUI_TEXTINPUT_CONTENT_TYPE_PHONE_NUMBER, ARKUI_TEXTINPUT_CONTENT_TYPE_PHONE_COUNTRY_CODE, ARKUI_TEXTINPUT_CONTENT_TYPE_FULL_PHONE_NUMBER, ARKUI_TEXTINPUT_CONTENT_EMAIL_ADDRESS,<br>ARKUI_TEXTINPUT_CONTENT_TYPE_BANK_CARD_NUMBER, ARKUI_TEXTINPUT_CONTENT_TYPE_ID_CARD_NUMBER, ARKUI_TEXTINPUT_CONTENT_TYPE_NICKNAME, ARKUI_TEXTINPUT_CONTENT_TYPE_DETAIL_INFO_WITHOUT_STREET,<br>ARKUI_TEXTINPUT_CONTENT_TYPE_FORMAT_ADDRESS<br>} | Enumerates the autofill types. |
| [ArkUI_BarrierDirection](#arkui_barrierdirection) { ARKUI_BARRIER_DIRECTION_START = 0, ARKUI_BARRIER_DIRECTION_END, ARKUI_BARRIER_DIRECTION_TOP, ARKUI_BARRIER_DIRECTION_BOTTOM } | Enumerates the barrier directions. |
| [ArkUI_RelativeLayoutChainStyle](#arkui_relativelayoutchainstyle) { ARKUI_RELATIVE_LAYOUT_CHAIN_STYLE_SPREAD = 0, ARKUI_RELATIVE_LAYOUT_CHAIN_STYLE_SPREAD_INSIDE, ARKUI_RELATIVE_LAYOUT_CHAIN_STYLE_PACKED } | Enumerates the chain styles. |
| [ArkUI_TextInputStyle](#arkui_textinputstyle) { ARKUI_TEXTINPUT_STYLE_DEFAULT = 0, ARKUI_TEXTINPUT_STYLE_INLINE } | Enumerates the text input styles. |
| [ArkUI_TextDataDetectorType](#arkui_textdatadetectortype) { ARKUI_TEXT_DATA_DETECTOR_TYPE_PHONE_NUMBER = 0, ARKUI_TEXT_DATA_DETECTOR_TYPE_URL, ARKUI_TEXT_DATA_DETECTOR_TYPE_EMAIL, ARKUI_TEXT_DATA_DETECTOR_TYPE_ADDRESS } | Enumerates the entity types of text recognition. |
| [ArkUI_ButtonType](#arkui_buttontype) { ARKUI_BUTTON_TYPE_NORMAL = 0, ARKUI_BUTTON_TYPE_CAPSULE, ARKUI_BUTTON_TYPE_CIRCLE } | Enumerates the button types. |
| [ArkUI_RenderFit](#arkui_renderfit) {<br>ARKUI_RENDER_FIT_CENTER = 0, ARKUI_RENDER_FIT_TOP, ARKUI_RENDER_FIT_BOTTOM, ARKUI_RENDER_FIT_LEFT,<br>ARKUI_RENDER_FIT_RIGHT, ARKUI_RENDER_FIT_TOP_LEFT, ARKUI_RENDER_FIT_TOP_RIGHT, ARKUI_RENDER_FIT_BOTTOM_LEFT,<br>ARKUI_RENDER_FIT_BOTTOM_RIGHT, ARKUI_RENDER_FIT_RESIZE_FILL, ARKUI_RENDER_FIT_RESIZE_CONTAIN, ARKUI_RENDER_FIT_RESIZE_CONTAIN_TOP_LEFT,<br>ARKUI_RENDER_FIT_RESIZE_CONTAIN_BOTTOM_RIGHT, ARKUI_RENDER_FIT_RESIZE_COVER, ARKUI_RENDER_FIT_RESIZE_COVER_TOP_LEFT, ARKUI_RENDER_FIT_RESIZE_COVER_BOTTOM_RIGHT<br>} |  |
| [ArkUI_ThemeColorMode](#arkui_themecolormode) { ARKUI_THEME_COLOR_MODE_SYSTEM = 0, ARKUI_THEME_COLOR_MODE_LIGHT, ARKUI_THEME_COLOR_MODE_DARK } |  |
| [ArkUI_SwiperIndicatorType](#arkui_swiperindicatortype) { ARKUI_SWIPER_INDICATOR_TYPE_DOT, ARKUI_SWIPER_INDICATOR_TYPE_DIGIT } | Enumerates the navigation point indicator types of the **\<Swiper>** component. |
| [ArkUI_SwiperDisplayModeType](#arkui_swiperdisplaymodetype) { ARKUI_SWIPER_DISPLAY_MODE_STRETCH, ARKUI_SWIPER_DISPLAY_MODE_AUTO_LINEAR } | Enumerates the modes in which elements are displayed along the main axis of the **\<Swiper>** component. |
| [ArkUI_ListItemSwipeActionState](#arkui_listitemswipeactionstate) { ARKUI_LIST_ITEM_SWIPE_ACTION_STATE_COLLAPSED = 0, ARKUI_LIST_ITEM_SWIPE_ACTION_STATE_EXPANDED, ARKUI_LIST_ITEM_SWIPE_ACTION_STATE_ACTIONING } | Enumerates the swipe action item states of list items. |
| [ArkUI_ListItemSwipeEdgeEffect](#arkui_listitemswipeedgeeffect) { ARKUI_LIST_ITEM_SWIPE_EDGE_EFFECT_SPRING = 0, ARKUI_LIST_ITEM_SWIPE_EDGE_EFFECT_NONE } | Enumerates the swipe action item edge effects of list items. |
| [ArkUI_AnimationStatus](#arkui_animationstatus) { ARKUI_ANIMATION_STATUS_INITIAL, ARKUI_ANIMATION_STATUS_RUNNING, ARKUI_ANIMATION_STATUS_PAUSED, ARKUI_ANIMATION_STATUS_STOPED } | Enumerates the playback states of the frame-by-frame animation. |
| [ArkUI_AnimationFillMode](#arkui_animationfillmode) { ARKUI_ANIMATION_FILL_MODE_NONE, ARKUI_ANIMATION_FILL_MODE_FORWARDS, ARKUI_ANIMATION_FILL_MODE_BACKWARDS, ARKUI_ANIMATION_FILL_MODE_BOTH } | Enumerates the states before and after execution of the frame-by-frame animation. |


### Functions

| Name| Description|
| -------- | -------- |
| [ArkUI_DrawableDescriptor](#arkui_drawabledescriptor) \* [OH_ArkUI_DrawableDescriptor_CreateFromPixelMap](#oh_arkui_drawabledescriptor_createfrompixelmap) ([OH_PixelmapNativeHandle](#oh_pixelmapnativehandle) pixelMap) | Creates a **DrawbleDescriptor** object with a **PixelMap** object. |
| [ArkUI_DrawableDescriptor](#arkui_drawabledescriptor) \* [OH_ArkUI_DrawableDescriptor_CreateFromAnimatedPixelMap](#oh_arkui_drawabledescriptor_createfromanimatedpixelmap) ([OH_PixelmapNativeHandle](#oh_pixelmapnativehandle) \*array, int32_t size) | Creates a **DrawbleDescriptor** object with an array of **PixelMap** objects. |
| void [OH_ArkUI_DrawableDescriptor_Dispose](#oh_arkui_drawabledescriptor_dispose) ([ArkUI_DrawableDescriptor](#arkui_drawabledescriptor) \*drawableDescriptor) | Disposes of the pointer to a **DrawbleDescriptor** object. |
| [OH_PixelmapNativeHandle](#oh_pixelmapnativehandle) [OH_ArkUI_DrawableDescriptor_GetStaticPixelMap](#oh_arkui_drawabledescriptor_getstaticpixelmap) ([ArkUI_DrawableDescriptor](#arkui_drawabledescriptor) \*drawableDescriptor) | Obtains the pointer to a **PixelMap** object. |
| [OH_PixelmapNativeHandle](#oh_pixelmapnativehandle) \* [OH_ArkUI_DrawableDescriptor_GetAnimatedPixelMapArray](#oh_arkui_drawabledescriptor_getanimatedpixelmaparray) ([ArkUI_DrawableDescriptor](#arkui_drawabledescriptor) \*drawableDescriptor) | Obtains an array of **PixelMap** objects for playing an animation. |
| int32_t [OH_ArkUI_DrawableDescriptor_GetAnimatedPixelMapArraySize](#oh_arkui_drawabledescriptor_getanimatedpixelmaparraysize) ([ArkUI_DrawableDescriptor](#arkui_drawabledescriptor) \*drawableDescriptor) | Obtains the size of an array of **PixelMap** objects for playing an animation. |
| void [OH_ArkUI_DrawableDescriptor_SetAnimationDuration](#oh_arkui_drawabledescriptor_setanimationduration) ([ArkUI_DrawableDescriptor](#arkui_drawabledescriptor) \*drawableDescriptor, int32_t duration) | Sets the total playback duration of the PixelMap image array. |
| int32_t [OH_ArkUI_DrawableDescriptor_GetAnimationDuration](#oh_arkui_drawabledescriptor_getanimationduration) ([ArkUI_DrawableDescriptor](#arkui_drawabledescriptor) \*drawableDescriptor) | Obtains the total playback duration of a PixelMap image array. |
| void [OH_ArkUI_DrawableDescriptor_SetAnimationIteration](#oh_arkui_drawabledescriptor_setanimationiteration) ([ArkUI_DrawableDescriptor](#arkui_drawabledescriptor) \*drawableDescriptor, int32_t iteration) | Sets the number of times that the PixelMap image array is played. |
| int32_t [OH_ArkUI_DrawableDescriptor_GetAnimationIteration](#oh_arkui_drawabledescriptor_getanimationiteration) ([ArkUI_DrawableDescriptor](#arkui_drawabledescriptor) \*drawableDescriptor) | Obtains the number of times that the PixelMap image array is played. |
| [ArkUI_AnimateOption](#arkui_animateoption) \* [OH_ArkUI_AnimateOption_Create](#oh_arkui_animateoption_create) () | Create animation effect parameters. |
| void [OH_ArkUI_AnimateOption_Dispose](#oh_arkui_animateoption_dispose) ([ArkUI_AnimateOption](#arkui_animateoption) \*option) | Destroys an animation configuration. |
| uint32_t [OH_ArkUI_AnimateOption_GetDuration](#oh_arkui_animateoption_getduration) ([ArkUI_AnimateOption](#arkui_animateoption) \*option) | Obtains the animation duration, in milliseconds. |
| float [OH_ArkUI_AnimateOption_GetTempo](#oh_arkui_animateoption_gettempo) ([ArkUI_AnimateOption](#arkui_animateoption) \*option) | Obtains the playback speed of an animation. |
| [ArkUI_AnimationCurve](#arkui_animationcurve) [OH_ArkUI_AnimateOption_GetCurve](#oh_arkui_animateoption_getcurve) ([ArkUI_AnimateOption](#arkui_animateoption) \*option) | Obtains the animation curve. |
| uint32_t [OH_ArkUI_AnimateOption_GetDelay](#oh_arkui_animateoption_getdelay) ([ArkUI_AnimateOption](#arkui_animateoption) \*option) | Obtains the animation delay, in milliseconds. |
| uint32_t [OH_ArkUI_AnimateOption_GetIterations](#oh_arkui_animateoption_getiterations) ([ArkUI_AnimateOption](#arkui_animateoption) \*option) | Obtains the number of times that an animation is played. |
| [ArkUI_AnimationPlayMode](#arkui_animationplaymode) [OH_ArkUI_AnimateOption_GetPlayMode](#oh_arkui_animateoption_getplaymode) ([ArkUI_AnimateOption](#arkui_animateoption) \*option) | Obtains the animation playback mode. |
| [ArkUI_ExpectedFrameRateRange](_ark_u_i___expected_frame_rate_range.md) \* [OH_ArkUI_AnimateOption_GetExpectedFrameRateRange](#oh_arkui_animateoption_getexpectedframeraterange) ([ArkUI_AnimateOption](#arkui_animateoption) \*option) | Obtains the expected frame rate range of an animation. |
| void [OH_ArkUI_AnimateOption_SetDuration](#oh_arkui_animateoption_setduration) ([ArkUI_AnimateOption](#arkui_animateoption) \*option, uint32_t value) | Sets the animation duration. |
| void [OH_ArkUI_AnimateOption_SetTempo](#oh_arkui_animateoption_settempo) ([ArkUI_AnimateOption](#arkui_animateoption) \*option, float value) | Sets the playback speed of an animation. |
| void [OH_ArkUI_AnimateOption_SetCurve](#oh_arkui_animateoption_setcurve) ([ArkUI_AnimateOption](#arkui_animateoption) \*option, [ArkUI_AnimationCurve](#arkui_animationcurve) value) | Animation curve. |
| void [OH_ArkUI_AnimateOption_SetDelay](#oh_arkui_animateoption_setdelay) ([ArkUI_AnimateOption](#arkui_animateoption) \*option, uint32_t value) | Sets the animation delay. |
| void [OH_ArkUI_AnimateOption_SetIterations](#oh_arkui_animateoption_setiterations) ([ArkUI_AnimateOption](#arkui_animateoption) \*option, uint32_t value) | Number of times that the frame animation is played. |
| void [OH_ArkUI_AnimateOption_SetPlayMode](#oh_arkui_animateoption_setplaymode) ([ArkUI_AnimateOption](#arkui_animateoption) \*option, [ArkUI_AnimationPlayMode](#arkui_animationplaymode) value) | Sets the animation playing mode. |
| void [OH_ArkUI_AnimateOption_SetExpectedFrameRateRange](#oh_arkui_animateoption_setexpectedframeraterange) ([ArkUI_AnimateOption](#arkui_animateoption) \*option, [ArkUI_ExpectedFrameRateRange](_ark_u_i___expected_frame_rate_range.md) \*value) | Defines the expected frame rate range of the animation. |
| bool [OH_ArkUI_GestureInterruptInfo_GetSystemFlag](#oh_arkui_gestureinterruptinfo_getsystemflag) (const ArkUI_GestureInterruptInfo \*event) | Checks whether a gesture is a built-in gesture of the component. |
| ArkUI_GestureRecognizer \* [OH_ArkUI_GestureInterruptInfo_GetRecognizer](#oh_arkui_gestureinterruptinfo_getrecognizer) (const ArkUI_GestureInterruptInfo \*event) | Obtains the pointer to interrupted gesture recognizer. |
| ArkUI_GestureEvent \* [OH_ArkUI_GestureInterruptInfo_GetGestureEvent](#oh_arkui_gestureinterruptinfo_getgestureevent) (const ArkUI_GestureInterruptInfo \*event) | Obtains the pointer to the interrupted gesture event. |
| int32_t [OH_ArkUI_GestureInterruptInfo_GetSystemRecognizerType](#oh_arkui_gestureinterruptinfo_getsystemrecognizertype) (const ArkUI_GestureInterruptInfo \*event) | Obtains the type of the system gesture to trigger. |
| [ArkUI_GestureEventActionType](#arkui_gestureeventactiontype) [OH_ArkUI_GestureEvent_GetActionType](#oh_arkui_gestureevent_getactiontype) (const ArkUI_GestureEvent \*event) | Returns the gesture event type. |
| const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \* [OH_ArkUI_GestureEvent_GetRawInputEvent](#oh_arkui_gestureevent_getrawinputevent) (const ArkUI_GestureEvent \*event) | Returns gesture input. |
| int32_t [OH_ArkUI_LongPress_GetRepeatCount](#oh_arkui_longpress_getrepeatcount) (const ArkUI_GestureEvent \*event) | Obtains the number of times that a long press gesture is triggered periodically. |
| float [OH_ArkUI_PanGesture_GetVelocity](#oh_arkui_pangesture_getvelocity) (const ArkUI_GestureEvent \*event) | Obtains the velocity of a pan gesture along the main axis. |
| float [OH_ArkUI_PanGesture_GetVelocityX](#oh_arkui_pangesture_getvelocityx) (const ArkUI_GestureEvent \*event) | Obtains the velocity of a pan gesture along the x-axis. |
| float [OH_ArkUI_PanGesture_GetVelocityY](#oh_arkui_pangesture_getvelocityy) (const ArkUI_GestureEvent \*event) | Obtains the velocity of a pan gesture along the y-axis. |
| float [OH_ArkUI_PanGesture_GetOffsetX](#oh_arkui_pangesture_getoffsetx) (const ArkUI_GestureEvent \*event) | Obtains the relative offset of a pan gesture along the x-axis. |
| float [OH_ArkUI_PanGesture_GetOffsetY](#oh_arkui_pangesture_getoffsety) (const ArkUI_GestureEvent \*event) | Obtains the relative offset of a pan gesture along the y-axis. |
| float [OH_ArkUI_SwipeGesture_GetAngle](#oh_arkui_swipegesture_getangle) (const ArkUI_GestureEvent \*event) | Obtains the angle information of the swipe gesture. |
| float [OH_ArkUI_SwipeGesture_GetVelocity](#oh_arkui_swipegesture_getvelocity) (const ArkUI_GestureEvent \*event) | Obtains the average velocity of all fingers used in the swipe gesture. |
| float [OH_ArkUI_RotationGesture_GetAngle](#oh_arkui_rotationgesture_getangle) (const ArkUI_GestureEvent \*event) | Obtains the angle information of a rotation gesture. |
| float [OH_ArkUI_PinchGesture_GetScale](#oh_arkui_pinchgesture_getscale) (const ArkUI_GestureEvent \*event) | Obtains the scale ratio of a pinch gesture. |
| float [OH_ArkUI_PinchGesture_GetCenterX](#oh_arkui_pinchgesture_getcenterx) (const ArkUI_GestureEvent \*event) | Obtains the X coordinate of the center of the pinch gesture, in vp, relative to the upper left corner of the current component. |
| float [OH_ArkUI_PinchGesture_GetCenterY](#oh_arkui_pinchgesture_getcentery) (const ArkUI_GestureEvent \*event) | Obtains the Y coordinate of the center of the pinch gesture, in vp, relative to the upper left corner of the current component. |
| void \* [OH_ArkUI_QueryModuleInterfaceByName](#oh_arkui_querymoduleinterfacebyname) ([ArkUI_NativeAPIVariantKind](#arkui_nativeapivariantkind) type, const char \*structName) | Obtains the native API set of a specified type. |
| [ArkUI_NodeEventType](#arkui_nodeeventtype) [OH_ArkUI_NodeEvent_GetEventType](#oh_arkui_nodeevent_geteventtype) ([ArkUI_NodeEvent](#arkui_nodeevent) \*event) | Obtains the widget event type. |
| int32_t [OH_ArkUI_NodeEvent_GetTargetId](#oh_arkui_nodeevent_gettargetid) ([ArkUI_NodeEvent](#arkui_nodeevent) \*event) | Obtains the custom ID of a component event. |
| [ArkUI_NodeHandle](#arkui_nodehandle) [OH_ArkUI_NodeEvent_GetNodeHandle](#oh_arkui_nodeevent_getnodehandle) ([ArkUI_NodeEvent](#arkui_nodeevent) \*event) | Obtains the component object that triggers a component event. |
| [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \* [OH_ArkUI_NodeEvent_GetInputEvent](#oh_arkui_nodeevent_getinputevent) ([ArkUI_NodeEvent](#arkui_nodeevent) \*event) | Obtains input event (for example, touch event) data for a component event. |
| [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) \* [OH_ArkUI_NodeEvent_GetNodeComponentEvent](#oh_arkui_nodeevent_getnodecomponentevent) ([ArkUI_NodeEvent](#arkui_nodeevent) \*event) | Obtains the numerical data in a component event. |
| [ArkUI_StringAsyncEvent](_ark_u_i___string_async_event.md) \* [OH_ArkUI_NodeEvent_GetStringAsyncEvent](#oh_arkui_nodeevent_getstringasyncevent) ([ArkUI_NodeEvent](#arkui_nodeevent) \*event) | Obtains the string data in a component event. |
| void \* [OH_ArkUI_NodeEvent_GetUserData](#oh_arkui_nodeevent_getuserdata) ([ArkUI_NodeEvent](#arkui_nodeevent) \*event) | Obtains the custom data in a component event. |
| [ArkUI_NodeAdapterHandle](#arkui_nodeadapterhandle) [OH_ArkUI_NodeAdapter_Create](#oh_arkui_nodeadapter_create) () | Creates a component adapter. |
| void [OH_ArkUI_NodeAdapter_Dispose](#oh_arkui_nodeadapter_dispose) ([ArkUI_NodeAdapterHandle](#arkui_nodeadapterhandle) handle) | Destroys a component adapter. |
| int32_t [OH_ArkUI_NodeAdapter_SetTotalNodeCount](#oh_arkui_nodeadapter_settotalnodecount) ([ArkUI_NodeAdapterHandle](#arkui_nodeadapterhandle) handle, uint32_t size) | Sets the total number of elements in the specified adapter. |
| uint32_t [OH_ArkUI_NodeAdapter_GetTotalNodeCount](#oh_arkui_nodeadapter_gettotalnodecount) ([ArkUI_NodeAdapterHandle](#arkui_nodeadapterhandle) handle) | Obtains the total number of elements in the Adapter. |
| int32_t [OH_ArkUI_NodeAdapter_RegisterEventReceiver](#oh_arkui_nodeadapter_registereventreceiver) ([ArkUI_NodeAdapterHandle](#arkui_nodeadapterhandle) handle, void \*userData, void(\*receiver)([ArkUI_NodeAdapterEvent](#arkui_nodeadapterevent) \*event)) | Registers callback events related to the Adapter. |
| void [OH_ArkUI_NodeAdapter_UnregisterEventReceiver](#oh_arkui_nodeadapter_unregistereventreceiver) ([ArkUI_NodeAdapterHandle](#arkui_nodeadapterhandle) handle) | Deregisters Adapter-related callback events. |
| int32_t [OH_ArkUI_NodeAdapter_ReloadAllItems](#oh_arkui_nodeadapter_reloadallitems) ([ArkUI_NodeAdapterHandle](#arkui_nodeadapterhandle) handle) | Instructs the specified adapter to reload all elements. |
| int32_t [OH_ArkUI_NodeAdapter_ReloadItem](#oh_arkui_nodeadapter_reloaditem) ([ArkUI_NodeAdapterHandle](#arkui_nodeadapterhandle) handle, uint32_t startPosition, uint32_t itemCount) | Instructs the specified adapter to reload certain elements. |
| int32_t [OH_ArkUI_NodeAdapter_RemoveItem](#oh_arkui_nodeadapter_removeitem) ([ArkUI_NodeAdapterHandle](#arkui_nodeadapterhandle) handle, uint32_t startPosition, uint32_t itemCount) | Instructs the specified adapter to remove certain elements. |
| int32_t [OH_ArkUI_NodeAdapter_InsertItem](#oh_arkui_nodeadapter_insertitem) ([ArkUI_NodeAdapterHandle](#arkui_nodeadapterhandle) handle, uint32_t startPosition, uint32_t itemCount) | Instructs the specified adapter to insert certain elements. |
| int32_t [OH_ArkUI_NodeAdapter_MoveItem](#oh_arkui_nodeadapter_moveitem) ([ArkUI_NodeAdapterHandle](#arkui_nodeadapterhandle) handle, uint32_t from, uint32_t to) | Instructs the specified adapter to move certain elements. |
| int32_t [OH_ArkUI_NodeAdapter_GetAllItems](#oh_arkui_nodeadapter_getallitems) ([ArkUI_NodeAdapterHandle](#arkui_nodeadapterhandle) handle, [ArkUI_NodeHandle](#arkui_nodehandle) \*\*items, uint32_t \*size) | Obtains all elements stored in the specified adapter. |
| void \* [OH_ArkUI_NodeAdapterEvent_GetUserData](#oh_arkui_nodeadapterevent_getuserdata) ([ArkUI_NodeAdapterEvent](#arkui_nodeadapterevent) \*event) | Obtains the custom data passed in during registration of the specified event. |
| [ArkUI_NodeAdapterEventType](#arkui_nodeadaptereventtype) [OH_ArkUI_NodeAdapterEvent_GetType](#oh_arkui_nodeadapterevent_gettype) ([ArkUI_NodeAdapterEvent](#arkui_nodeadapterevent) \*event) | Obtains the event type. |
| [ArkUI_NodeHandle](#arkui_nodehandle) [OH_ArkUI_NodeAdapterEvent_GetRemovedNode](#oh_arkui_nodeadapterevent_getremovednode) ([ArkUI_NodeAdapterEvent](#arkui_nodeadapterevent) \*event) | Obtains the element to be destroyed in the event to be destroyed. |
| uint32_t [OH_ArkUI_NodeAdapterEvent_GetItemIndex](#oh_arkui_nodeadapterevent_getitemindex) ([ArkUI_NodeAdapterEvent](#arkui_nodeadapterevent) \*event) | Sequence number of the element to be operated when the adapter event is obtained. |
| [ArkUI_NodeHandle](#arkui_nodehandle) [OH_ArkUI_NodeAdapterEvent_GetHostNode](#oh_arkui_nodeadapterevent_gethostnode) ([ArkUI_NodeAdapterEvent](#arkui_nodeadapterevent) \*event) | Obtains the scrolling class container node that uses the adapter. |
| int32_t [OH_ArkUI_NodeAdapterEvent_SetItem](#oh_arkui_nodeadapterevent_setitem) ([ArkUI_NodeAdapterEvent](#arkui_nodeadapterevent) \*event, [ArkUI_NodeHandle](#arkui_nodehandle) node) | Sets the component to be added to the specified adapter. |
| int32_t [OH_ArkUI_NodeAdapterEvent_SetNodeId](#oh_arkui_nodeadapterevent_setnodeid) ([ArkUI_NodeAdapterEvent](#arkui_nodeadapterevent) \*event, int32_t id) | Sets the generated component ID. |
| [ArkUI_LayoutConstraint](#arkui_layoutconstraint) \* [OH_ArkUI_NodeCustomEvent_GetLayoutConstraintInMeasure](#oh_arkui_nodecustomevent_getlayoutconstraintinmeasure) ([ArkUI_NodeCustomEvent](#arkui_nodecustomevent) \*event) | You can customize widget events to obtain the constraint size during calculation. |
| [ArkUI_IntOffset](_ark_u_i___int_offset.md) [OH_ArkUI_NodeCustomEvent_GetPositionInLayout](#oh_arkui_nodecustomevent_getpositioninlayout) ([ArkUI_NodeCustomEvent](#arkui_nodecustomevent) \*event) | You can customize a widget event to obtain the expected position relative to the parent widget in the layout phase. |
| [ArkUI_DrawContext](#arkui_drawcontext) \* [OH_ArkUI_NodeCustomEvent_GetDrawContextInDraw](#oh_arkui_nodecustomevent_getdrawcontextindraw) ([ArkUI_NodeCustomEvent](#arkui_nodecustomevent) \*event) | Obtain the drawing context through the customized widget event. |
| int32_t [OH_ArkUI_NodeCustomEvent_GetEventTargetId](#oh_arkui_nodecustomevent_geteventtargetid) ([ArkUI_NodeCustomEvent](#arkui_nodecustomevent) \*event) | Obtain the customized event ID through the custom component event. |
| void \* [OH_ArkUI_NodeCustomEvent_GetUserData](#oh_arkui_nodecustomevent_getuserdata) ([ArkUI_NodeCustomEvent](#arkui_nodecustomevent) \*event) | This API is used to obtain custom event parameters through custom widget events. |
| [ArkUI_NodeHandle](#arkui_nodehandle) [OH_ArkUI_NodeCustomEvent_GetNodeHandle](#oh_arkui_nodecustomevent_getnodehandle) ([ArkUI_NodeCustomEvent](#arkui_nodecustomevent) \*event) | This interface is used to obtain a widget object by customizing a widget event. |
| [ArkUI_NodeCustomEventType](#arkui_nodecustomeventtype) [OH_ArkUI_NodeCustomEvent_GetEventType](#oh_arkui_nodecustomevent_geteventtype) ([ArkUI_NodeCustomEvent](#arkui_nodecustomevent) \*event) | Obtain the event type by customizing a widget event. |
| int32_t [OH_ArkUI_NodeUtils_GetLayoutSize](#oh_arkui_nodeutils_getlayoutsize) ([ArkUI_NodeHandle](#arkui_nodehandle) node, [ArkUI_IntSize](_ark_u_i___int_size.md) \*size) | Obtains the size of the widget layout area. The layout area size does not contain graphic change attributes, such as scaling. |
| int32_t [OH_ArkUI_NodeUtils_GetLayoutPosition](#oh_arkui_nodeutils_getlayoutposition) ([ArkUI_NodeHandle](#arkui_nodehandle) node, [ArkUI_IntOffset](_ark_u_i___int_offset.md) \*localOffset) | Obtains the position of the component's layout area relative to its parent component. * The relative position does not count in transformation attributes, such as translate. |
| int32_t [OH_ArkUI_NodeUtils_GetLayoutPositionInWindow](#oh_arkui_nodeutils_getlayoutpositioninwindow) ([ArkUI_NodeHandle](#arkui_nodehandle) node, [ArkUI_IntOffset](_ark_u_i___int_offset.md) \*globalOffset) | Obtains the position of the component's layout area relative to the window. * The relative position does not count in transformation attributes, such as translate. |
| int32_t [OH_ArkUI_NodeUtils_GetLayoutPositionInScreen](#oh_arkui_nodeutils_getlayoutpositioninscreen) ([ArkUI_NodeHandle](#arkui_nodehandle) node, [ArkUI_IntOffset](_ark_u_i___int_offset.md) \*screenOffset) | Obtains the position of the component's layout area relative to the screen. * The relative position does not count in transformation attributes, such as translate. |
| int32_t [OH_ArkUI_NodeUtils_GetPositionWithTranslateInWindow](#oh_arkui_nodeutils_getpositionwithtranslateinwindow) ([ArkUI_NodeHandle](#arkui_nodehandle) node, [ArkUI_IntOffset](_ark_u_i___int_offset.md) \*translateOffset) | Obtains the position of the component in the window, including the translate attribute. |
| int32_t [OH_ArkUI_NodeUtils_GetPositionWithTranslateInScreen](#oh_arkui_nodeutils_getpositionwithtranslateinscreen) ([ArkUI_NodeHandle](#arkui_nodehandle) node, [ArkUI_IntOffset](_ark_u_i___int_offset.md) \*translateOffset) | Obtains the position of a component on the screen, including the image translation change attribute. |
| int32_t [OH_ArkUI_GetNodeHandleFromNapiValue](#oh_arkui_getnodehandlefromnapivalue) (napi_env env, napi_value frameNode, [ArkUI_NodeHandle](#arkui_nodehandle) \*handle) | Obtains a **FrameNode** object on the ArkTS side and maps it to an **ArkUI_NodeHandle** object on the native side. |
| int32_t [OH_ArkUI_GetNodeHandleFromNapiValue](#oh_arkui_getnodehandlefromnapivalue) (napi_env env, napi_value frameNode, [ArkUI_NodeHandle](#arkui_nodehandle) \*handle) | Obtains a **FrameNode** object on the ArkTS side and maps it to an **ArkUI_NodeHandle** object on the native side. |
| int32_t [OH_ArkUI_GetContextFromNapiValue](#oh_arkui_getcontextfromnapivalue) (napi_env env, napi_value value, [ArkUI_ContextHandle](#arkui_contexthandle) \*context) | Obtains a **UIContext** object on the ArkTS side and maps it to an **ArkUI_ContextHandle** object on the native side. |
| int32_t [OH_ArkUI_GetDrawableDescriptorFromNapiValue](#oh_arkui_getdrawabledescriptorfromnapivalue) (napi_env env, napi_value value, [ArkUI_DrawableDescriptor](#arkui_drawabledescriptor) \*\*drawableDescriptor) | Maps a **DrawableDescriptor** object on the ArkTS side to an **ArkUI_DrawableDescriptor** object on the native side.|
| int32_t [OH_ArkUI_GetDrawableDescriptorFromResourceNapiValue](#oh_arkui_getdrawabledescriptorfromresourcenapivalue) (napi_env env, napi_value value, [ArkUI_DrawableDescriptor](#arkui_drawabledescriptor) \*\*drawableDescriptor) | Maps an $r resource object on the ArkTS side to an **ArkUI_DrawableDescriptor** object on the native side.|
| [ArkUI_LayoutConstraint](#arkui_layoutconstraint) \* [OH_ArkUI_LayoutConstraint_Create](#oh_arkui_layoutconstraint_create) () | Create a constraint size. |
| [ArkUI_LayoutConstraint](#arkui_layoutconstraint) \* [OH_ArkUI_LayoutConstraint_Copy](#oh_arkui_layoutconstraint_copy) (const [ArkUI_LayoutConstraint](#arkui_layoutconstraint) \*Constraint) | Constraint size deep copy. |
| void \* [OH_ArkUI_LayoutConstraint_Dispose](#oh_arkui_layoutconstraint_dispose) ([ArkUI_LayoutConstraint](#arkui_layoutconstraint) \*Constraint) | Pointer to the size of the destruction constraint. |
| int32_t [OH_ArkUI_LayoutConstraint_GetMaxWidth](#oh_arkui_layoutconstraint_getmaxwidth) (const [ArkUI_LayoutConstraint](#arkui_layoutconstraint) \*Constraint) | Obtains the maximum width for a size contraint, in px. |
| int32_t [OH_ArkUI_LayoutConstraint_GetMinWidth](#oh_arkui_layoutconstraint_getminwidth) (const [ArkUI_LayoutConstraint](#arkui_layoutconstraint) \*Constraint) | Obtains the minimum width for a size contraint, in px. |
| int32_t [OH_ArkUI_LayoutConstraint_GetMaxHeight](#oh_arkui_layoutconstraint_getmaxheight) (const [ArkUI_LayoutConstraint](#arkui_layoutconstraint) \*Constraint) | Obtains the maximum height for a size constraint, in px. |
| int32_t [OH_ArkUI_LayoutConstraint_GetMinHeight](#oh_arkui_layoutconstraint_getminheight) (const [ArkUI_LayoutConstraint](#arkui_layoutconstraint) \*Constraint) | Obtains the minimum height for a size constraint, in px. |
| int32_t [OH_ArkUI_LayoutConstraint_GetPercentReferenceWidth](#oh_arkui_layoutconstraint_getpercentreferencewidth) (const [ArkUI_LayoutConstraint](#arkui_layoutconstraint) \*Constraint) | Obtains the width percentage reference for a size constraint, in px. |
| int32_t [OH_ArkUI_LayoutConstraint_GetPercentReferenceHeight](#oh_arkui_layoutconstraint_getpercentreferenceheight) (const [ArkUI_LayoutConstraint](#arkui_layoutconstraint) \*Constraint) | Obtains the height percentage reference for a size constraint, in px. |
| void [OH_ArkUI_LayoutConstraint_SetMaxWidth](#oh_arkui_layoutconstraint_setmaxwidth) ([ArkUI_LayoutConstraint](#arkui_layoutconstraint) \*Constraint, int32_t value) | Sets the maximum width. |
| void [OH_ArkUI_LayoutConstraint_SetMinWidth](#oh_arkui_layoutconstraint_setminwidth) ([ArkUI_LayoutConstraint](#arkui_layoutconstraint) \*Constraint, int32_t value) | Sets the minimum width. |
| void [OH_ArkUI_LayoutConstraint_SetMaxHeight](#oh_arkui_layoutconstraint_setmaxheight) ([ArkUI_LayoutConstraint](#arkui_layoutconstraint) \*Constraint, int32_t value) | Sets the maximum height. |
| void [OH_ArkUI_LayoutConstraint_SetMinHeight](#oh_arkui_layoutconstraint_setminheight) ([ArkUI_LayoutConstraint](#arkui_layoutconstraint) \*Constraint, int32_t value) | Sets the minimum height. |
| void [OH_ArkUI_LayoutConstraint_SetPercentReferenceWidth](#oh_arkui_layoutconstraint_setpercentreferencewidth) ([ArkUI_LayoutConstraint](#arkui_layoutconstraint) \*Constraint, int32_t value) | Sets the width percentage reference. |
| void [OH_ArkUI_LayoutConstraint_SetPercentReferenceHeight](#oh_arkui_layoutconstraint_setpercentreferenceheight) ([ArkUI_LayoutConstraint](#arkui_layoutconstraint) \*Constraint, int32_t value) | Sets the height percentage reference. |
| void \* [OH_ArkUI_DrawContext_GetCanvas](#oh_arkui_drawcontext_getcanvas) ([ArkUI_DrawContext](#arkui_drawcontext) \*context) | Obtains the drawing canvas pointer, which can be converted into the OH_Drawing_Canvas pointer of the graphics library for drawing. |
| [ArkUI_IntSize](_ark_u_i___int_size.md) [OH_ArkUI_DrawContext_GetSize](#oh_arkui_drawcontext_getsize) ([ArkUI_DrawContext](#arkui_drawcontext) \*context) | Obtains the size of a drawing area. |
| [ArkUI_WaterFlowSectionOption](#arkui_waterflowsectionoption) \* [OH_ArkUI_WaterFlowSectionOption_Create](#oh_arkui_waterflowsectionoption_create) () | Create FlowItem group configuration information. |
| void [OH_ArkUI_WaterFlowSectionOption_Dispose](#oh_arkui_waterflowsectionoption_dispose) ([ArkUI_WaterFlowSectionOption](#arkui_waterflowsectionoption) \*option) | Pointer to the configuration information of the flow item group to be destroyed. |
| void [OH_ArkUI_WaterFlowSectionOption_SetSize](#oh_arkui_waterflowsectionoption_setsize) ([ArkUI_WaterFlowSectionOption](#arkui_waterflowsectionoption) \*option, int32_t size) | Sets the length of the FlowItem group configuration information array. |
| void [OH_ArkUI_WaterFlowSectionOption_SetItemCount](#oh_arkui_waterflowsectionoption_setitemcount) ([ArkUI_WaterFlowSectionOption](#arkui_waterflowsectionoption) \*option, int32_t index, int32_t itemCount) | Set the number of FlowItems in the group. |
| int32_t [OH_ArkUI_WaterFlowSectionOption_GetItemCount](#oh_arkui_waterflowsectionoption_getitemcount) ([ArkUI_WaterFlowSectionOption](#arkui_waterflowsectionoption) \*option, int32_t index) | Obtains the number of flow items under the corresponding index based on the flow item group configuration information. |
| void [OH_ArkUI_WaterFlowSectionOption_SetCrossCount](#oh_arkui_waterflowsectionoption_setcrosscount) ([ArkUI_WaterFlowSectionOption](#arkui_waterflowsectionoption) \*option, int32_t index, int32_t crossCount) | Sets the number of columns (in a vertical layout) or rows (in a horizontal layout) of a water flow. |
| int32_t [OH_ArkUI_WaterFlowSectionOption_GetCrossCount](#oh_arkui_waterflowsectionoption_getcrosscount) ([ArkUI_WaterFlowSectionOption](#arkui_waterflowsectionoption) \*option, int32_t index) | Obtains the number of layout grids under the corresponding index based on the FlowItem group configuration information. |
| void [OH_ArkUI_WaterFlowSectionOption_SetColumnGap](#oh_arkui_waterflowsectionoption_setcolumngap) ([ArkUI_WaterFlowSectionOption](#arkui_waterflowsectionoption) \*, int32_t index, float columnGap) | Set the column spacing for grouping. |
| float [OH_ArkUI_WaterFlowSectionOption_GetColumnGap](#oh_arkui_waterflowsectionoption_getcolumngap) ([ArkUI_WaterFlowSectionOption](#arkui_waterflowsectionoption) \*option, int32_t index) | Obtains the gap between columns in the water flow section that matches the specified index. |
| void [OH_ArkUI_WaterFlowSectionOption_SetRowGap](#oh_arkui_waterflowsectionoption_setrowgap) ([ArkUI_WaterFlowSectionOption](#arkui_waterflowsectionoption) \*option, int32_t index, float rowGap) | Sets the line spacing of a group. |
| float [OH_ArkUI_WaterFlowSectionOption_GetRowGap](#oh_arkui_waterflowsectionoption_getrowgap) ([ArkUI_WaterFlowSectionOption](#arkui_waterflowsectionoption) \*option, int32_t index) | Obtains the gap between rows in the water flow section that matches the specified index. |
| void [OH_ArkUI_WaterFlowSectionOption_SetMargin](#oh_arkui_waterflowsectionoption_setmargin) ([ArkUI_WaterFlowSectionOption](#arkui_waterflowsectionoption) \*option, int32_t index, float marginTop, float marginRight, float marginBottom, float marginLeft) | Sets the outer margin of a group. |
| ArkUI_IntMargin [OH_ArkUI_WaterFlowSectionOption_GetMargin](#oh_arkui_waterflowsectionoption_getmargin) ([ArkUI_WaterFlowSectionOption](#arkui_waterflowsectionoption) \*option, int32_t index) | Obtains the margins of the water flow section that matches the specified index. |
| [ArkUI_GuidelineOption](#arkui_guidelineoption) \* [OH_ArkUI_GuidelineOption_Create](#oh_arkui_guidelineoption_create) (int32_t size) | Creates a guideline configuration for this **<RelativeContainer>**. |
| void [OH_ArkUI_GuidelineOption_Dispose](#oh_arkui_guidelineoption_dispose) ([ArkUI_GuidelineOption](#arkui_guidelineoption) \*guideline) | Destroys auxiliary line information. |
| void [OH_ArkUI_GuidelineOption_SetId](#oh_arkui_guidelineoption_setid) ([ArkUI_GuidelineOption](#arkui_guidelineoption) \*guideline, const char \*value, int32_t index) | Sets the ID of the auxiliary line. |
| void [OH_ArkUI_GuidelineOption_SetDirection](#oh_arkui_guidelineoption_setdirection) ([ArkUI_GuidelineOption](#arkui_guidelineoption) \*guideline, [ArkUI_Axis](#arkui_axis) value, int32_t index) | Sets the direction of the auxiliary line. |
| void [OH_ArkUI_GuidelineOption_SetPositionStart](#oh_arkui_guidelineoption_setpositionstart) ([ArkUI_GuidelineOption](#arkui_guidelineoption) \*guideline, float value, int32_t index) | Sets the distance between a guideline and the left or top of the container. |
| void [OH_ArkUI_GuidelineOption_SetPositionEnd](#oh_arkui_guidelineoption_setpositionend) ([ArkUI_GuidelineOption](#arkui_guidelineoption) \*guideline, float value, int32_t index) | Sets the distance between a guideline and the right or bottom of the container. |
| const char \* [OH_ArkUI_GuidelineOption_GetId](#oh_arkui_guidelineoption_getid) ([ArkUI_GuidelineOption](#arkui_guidelineoption) \*guideline, int32_t index) | Obtains the ID of an auxiliary line. |
| [ArkUI_Axis](#arkui_axis) [OH_ArkUI_GuidelineOption_GetDirection](#oh_arkui_guidelineoption_getdirection) ([ArkUI_GuidelineOption](#arkui_guidelineoption) \*guideline, int32_t index) | Obtains the direction of the auxiliary line. |
| float [OH_ArkUI_GuidelineOption_GetPositionStart](#oh_arkui_guidelineoption_getpositionstart) ([ArkUI_GuidelineOption](#arkui_guidelineoption) \*guideline, int32_t index) | Obtains the distance between a guideline and the left or top of the container. |
| float [OH_ArkUI_GuidelineOption_GetPositionEnd](#oh_arkui_guidelineoption_getpositionend) ([ArkUI_GuidelineOption](#arkui_guidelineoption) \*guideline, int32_t index) | Obtains the distance between a guideline and the right or bottom of the container. |
| [ArkUI_BarrierOption](#arkui_barrieroption) \* [OH_ArkUI_BarrierOption_Create](#oh_arkui_barrieroption_create) (int32_t size) | Create barrier information in the RelativeContaine container. |
| void [OH_ArkUI_BarrierOption_Dispose](#oh_arkui_barrieroption_dispose) ([ArkUI_BarrierOption](#arkui_barrieroption) \*barrierStyle) | Destroy barrier information. |
| void [OH_ArkUI_BarrierOption_SetId](#oh_arkui_barrieroption_setid) ([ArkUI_BarrierOption](#arkui_barrieroption) \*barrierStyle, const char \*value, int32_t index) | Sets the barrier ID. |
| void [OH_ArkUI_BarrierOption_SetDirection](#oh_arkui_barrieroption_setdirection) ([ArkUI_BarrierOption](#arkui_barrieroption) \*barrierStyle, [ArkUI_BarrierDirection](#arkui_barrierdirection) value, int32_t index) | Sets the direction of the barrier. |
| void [OH_ArkUI_BarrierOption_SetReferencedId](#oh_arkui_barrieroption_setreferencedid) ([ArkUI_BarrierOption](#arkui_barrieroption) \*barrierStyle, const char \*value, int32_t index) | Sets the referenced components of a barrier. |
| const char \* [OH_ArkUI_BarrierOption_GetId](#oh_arkui_barrieroption_getid) ([ArkUI_BarrierOption](#arkui_barrieroption) \*barrierStyle, int32_t index) | Obtains the barrier ID. |
| [ArkUI_BarrierDirection](#arkui_barrierdirection) [OH_ArkUI_BarrierOption_GetDirection](#oh_arkui_barrieroption_getdirection) ([ArkUI_BarrierOption](#arkui_barrieroption) \*barrierStyle, int32_t index) | Obtains the direction of the barrier. |
| const char \* [OH_ArkUI_BarrierOption_GetReferencedId](#oh_arkui_barrieroption_getreferencedid) ([ArkUI_BarrierOption](#arkui_barrieroption) \*barrierStyle, int32_t index, int32_t referencedIndex) | Obtains the referenced components of a barrier. |
| int32_t [OH_ArkUI_BarrierOption_GetReferencedIdSize](#oh_arkui_barrieroption_getreferencedidsize) ([ArkUI_BarrierOption](#arkui_barrieroption) \*barrierStyle, int32_t index) | Obtains the number of referenced components of a barrier. |
| [ArkUI_AlignmentRuleOption](#arkui_alignmentruleoption) \* [OH_ArkUI_AlignmentRuleOption_Create](#oh_arkui_alignmentruleoption_create) () | Creates an alignment rule configuration for this **<RelativeContainer>**. |
| void [OH_ArkUI_AlignmentRuleOption_Dispose](#oh_arkui_alignmentruleoption_dispose) ([ArkUI_AlignmentRuleOption](#arkui_alignmentruleoption) \*option) | Destroys the alignment rule information of the child component in the relative container. |
| void [OH_ArkUI_AlignmentRuleOption_SetStart](#oh_arkui_alignmentruleoption_setstart) ([ArkUI_AlignmentRuleOption](#arkui_alignmentruleoption) \*option, const char \*id, [ArkUI_HorizontalAlignment](#arkui_horizontalalignment) alignment) | Left alignment. |
| void [OH_ArkUI_AlignmentRuleOption_SetEnd](#oh_arkui_alignmentruleoption_setend) ([ArkUI_AlignmentRuleOption](#arkui_alignmentruleoption) \*option, const char \*id, [ArkUI_HorizontalAlignment](#arkui_horizontalalignment) alignment) | Right alignment. |
| void [OH_ArkUI_AlignmentRuleOption_SetCenterHorizontal](#oh_arkui_alignmentruleoption_setcenterhorizontal) ([ArkUI_AlignmentRuleOption](#arkui_alignmentruleoption) \*option, const char \*id, [ArkUI_HorizontalAlignment](#arkui_horizontalalignment) alignment) | Center alignment in the horizontal direction. |
| void [OH_ArkUI_AlignmentRuleOption_SetTop](#oh_arkui_alignmentruleoption_settop) ([ArkUI_AlignmentRuleOption](#arkui_alignmentruleoption) \*option, const char \*id, [ArkUI_VerticalAlignment](#arkui_verticalalignment) alignment) | Top alignment. |
| void [OH_ArkUI_AlignmentRuleOption_SetBottom](#oh_arkui_alignmentruleoption_setbottom) ([ArkUI_AlignmentRuleOption](#arkui_alignmentruleoption) \*option, const char \*id, [ArkUI_VerticalAlignment](#arkui_verticalalignment) alignment) | Bottom alignment. |
| void [OH_ArkUI_AlignmentRuleOption_SetCenterVertical](#oh_arkui_alignmentruleoption_setcentervertical) ([ArkUI_AlignmentRuleOption](#arkui_alignmentruleoption) \*option, const char \*id, [ArkUI_VerticalAlignment](#arkui_verticalalignment) alignment) | Center alignment in the vertical direction. |
| void [OH_ArkUI_AlignmentRuleOption_SetBiasHorizontal](#oh_arkui_alignmentruleoption_setbiashorizontal) ([ArkUI_AlignmentRuleOption](#arkui_alignmentruleoption) \*option, float horizontal) | Sets the bias value of the component in the horizontal direction under the anchor constraints. |
| void [OH_ArkUI_AlignmentRuleOption_SetBiasVertical](#oh_arkui_alignmentruleoption_setbiasvertical) ([ArkUI_AlignmentRuleOption](#arkui_alignmentruleoption) \*option, float vertical) | Sets the bias value of the component in the vertical direction under the anchor constraints. |
| const char \* [OH_ArkUI_AlignmentRuleOption_GetStartId](#oh_arkui_alignmentruleoption_getstartid) ([ArkUI_AlignmentRuleOption](#arkui_alignmentruleoption) \*option) | Obtains the ID in the left alignment parameters. |
| [ArkUI_HorizontalAlignment](#arkui_horizontalalignment) [OH_ArkUI_AlignmentRuleOption_GetStartAlignment](#oh_arkui_alignmentruleoption_getstartalignment) ([ArkUI_AlignmentRuleOption](#arkui_alignmentruleoption) \*option) | Obtains the alignment mode of the left alignment parameter. |
| const char \* [OH_ArkUI_AlignmentRuleOption_GetEndId](#oh_arkui_alignmentruleoption_getendid) ([ArkUI_AlignmentRuleOption](#arkui_alignmentruleoption) \*option) | Obtains the right alignment parameter. |
| [ArkUI_HorizontalAlignment](#arkui_horizontalalignment) [OH_ArkUI_AlignmentRuleOption_GetEndAlignment](#oh_arkui_alignmentruleoption_getendalignment) ([ArkUI_AlignmentRuleOption](#arkui_alignmentruleoption) \*option) | Obtains the right alignment parameter. |
| const char \* [OH_ArkUI_AlignmentRuleOption_GetCenterIdHorizontal](#oh_arkui_alignmentruleoption_getcenteridhorizontal) ([ArkUI_AlignmentRuleOption](#arkui_alignmentruleoption) \*option) | Obtains the parameters of the horizontal center alignment mode. |
| [ArkUI_HorizontalAlignment](#arkui_horizontalalignment) [OH_ArkUI_AlignmentRuleOption_GetCenterAlignmentHorizontal](#oh_arkui_alignmentruleoption_getcenteralignmenthorizontal) ([ArkUI_AlignmentRuleOption](#arkui_alignmentruleoption) \*option) | Obtains the parameters of the horizontal center alignment mode. |
| const char \* [OH_ArkUI_AlignmentRuleOption_GetTopId](#oh_arkui_alignmentruleoption_gettopid) ([ArkUI_AlignmentRuleOption](#arkui_alignmentruleoption) \*option) | Obtains top-aligned parameters. |
| [ArkUI_VerticalAlignment](#arkui_verticalalignment) [OH_ArkUI_AlignmentRuleOption_GetTopAlignment](#oh_arkui_alignmentruleoption_gettopalignment) ([ArkUI_AlignmentRuleOption](#arkui_alignmentruleoption) \*option) | Obtains top-aligned parameters. |
| const char \* [OH_ArkUI_AlignmentRuleOption_GetBottomId](#oh_arkui_alignmentruleoption_getbottomid) ([ArkUI_AlignmentRuleOption](#arkui_alignmentruleoption) \*option) | Obtains the bottom-aligned parameters. |
| [ArkUI_VerticalAlignment](#arkui_verticalalignment) [OH_ArkUI_AlignmentRuleOption_GetBottomAlignment](#oh_arkui_alignmentruleoption_getbottomalignment) ([ArkUI_AlignmentRuleOption](#arkui_alignmentruleoption) \*option) | Obtains the bottom-aligned parameters. |
| const char \* [OH_ArkUI_AlignmentRuleOption_GetCenterIdVertical](#oh_arkui_alignmentruleoption_getcenteridvertical) ([ArkUI_AlignmentRuleOption](#arkui_alignmentruleoption) \*option) | Obtains the parameter of the vertical center alignment mode. |
| [ArkUI_VerticalAlignment](#arkui_verticalalignment) [OH_ArkUI_AlignmentRuleOption_GetCenterAlignmentVertical](#oh_arkui_alignmentruleoption_getcenteralignmentvertical) ([ArkUI_AlignmentRuleOption](#arkui_alignmentruleoption) \*option) | Obtains the parameter of the vertical center alignment mode. |
| float [OH_ArkUI_AlignmentRuleOption_GetBiasHorizontal](#oh_arkui_alignmentruleoption_getbiashorizontal) ([ArkUI_AlignmentRuleOption](#arkui_alignmentruleoption) \*option) | Obtains the bias value in the horizontal direction. |
| float [OH_ArkUI_AlignmentRuleOption_GetBiasVertical](#oh_arkui_alignmentruleoption_getbiasvertical) ([ArkUI_AlignmentRuleOption](#arkui_alignmentruleoption) \*option) | Obtains the bias value in the vertical direction. |
| [ArkUI_SwiperIndicator](#arkui_swiperindicator) \* [OH_ArkUI_SwiperIndicator_Create](#oh_arkui_swiperindicator_create) ([ArkUI_SwiperIndicatorType](#arkui_swiperindicatortype) type) | Creates a navigation indicator for the Swiper component. |
| void [OH_ArkUI_SwiperIndicator_Dispose](#oh_arkui_swiperindicator_dispose) ([ArkUI_SwiperIndicator](#arkui_swiperindicator) \*indicator) | Destroys the navigation point indicator of this **<Swiper>** component. |
| void [OH_ArkUI_SwiperIndicator_SetStartPosition](#oh_arkui_swiperindicator_setstartposition) ([ArkUI_SwiperIndicator](#arkui_swiperindicator) \*indicator, float value) | Distance between the navigation point indicator and the left edge of the **\<Swiper>** component. |
| float [OH_ArkUI_SwiperIndicator_GetStartPosition](#oh_arkui_swiperindicator_getstartposition) ([ArkUI_SwiperIndicator](#arkui_swiperindicator) \*indicator) | Obtains the distance between a navigation point indicator and the left edge of the **<Swiper>** component. |
| void [OH_ArkUI_SwiperIndicator_SetTopPosition](#oh_arkui_swiperindicator_settopposition) ([ArkUI_SwiperIndicator](#arkui_swiperindicator) \*indicator, float value) | Distance between the navigation point indicator and the top edge of the **\<Swiper>** component. |
| float [OH_ArkUI_SwiperIndicator_GetTopPosition](#oh_arkui_swiperindicator_gettopposition) ([ArkUI_SwiperIndicator](#arkui_swiperindicator) \*indicator) | Obtains the distance between a navigation point indicator and the top edge of the **<Swiper>** component. |
| void [OH_ArkUI_SwiperIndicator_SetEndPosition](#oh_arkui_swiperindicator_setendposition) ([ArkUI_SwiperIndicator](#arkui_swiperindicator) \*indicator, float value) | Distance between the navigation point indicator and the left edge of the **\<Swiper>** component. |
| float [OH_ArkUI_SwiperIndicator_GetEndPosition](#oh_arkui_swiperindicator_getendposition) ([ArkUI_SwiperIndicator](#arkui_swiperindicator) \*indicator) | Obtains the distance between a navigation point indicator and the right edge of the **<Swiper>** component. |
| void [OH_ArkUI_SwiperIndicator_SetBottomPosition](#oh_arkui_swiperindicator_setbottomposition) ([ArkUI_SwiperIndicator](#arkui_swiperindicator) \*indicator, float value) | Distance between the navigation point indicator and the top edge of the **\<Swiper>** component. |
| float [OH_ArkUI_SwiperIndicator_GetBottomPosition](#oh_arkui_swiperindicator_getbottomposition) ([ArkUI_SwiperIndicator](#arkui_swiperindicator) \*indicator) | Obtains the distance between a navigation point indicator and the bottom edge of the **<Swiper>** component. |
| void [OH_ArkUI_SwiperIndicator_SetItemWidth](#oh_arkui_swiperindicator_setitemwidth) ([ArkUI_SwiperIndicator](#arkui_swiperindicator) \*indicator, float value) | Sets the width of a navigation point indicator of the dot style for the **<Swiper>** component. |
| float [OH_ArkUI_SwiperIndicator_GetItemWidth](#oh_arkui_swiperindicator_getitemwidth) ([ArkUI_SwiperIndicator](#arkui_swiperindicator) \*indicator) | Obtains the width of a navigation point indicator of the dot style of the **<Swiper>** component. |
| void [OH_ArkUI_SwiperIndicator_SetItemHeight](#oh_arkui_swiperindicator_setitemheight) ([ArkUI_SwiperIndicator](#arkui_swiperindicator) \*indicator, float value) | Sets the height of a navigation point indicator of the dot style for the **<Swiper>** component. |
| float [OH_ArkUI_SwiperIndicator_GetItemHeight](#oh_arkui_swiperindicator_getitemheight) ([ArkUI_SwiperIndicator](#arkui_swiperindicator) \*indicator) | Obtains the height of a navigation point indicator of the dot style of the **<Swiper>** component. |
| void [OH_ArkUI_SwiperIndicator_SetSelectedItemWidth](#oh_arkui_swiperindicator_setselecteditemwidth) ([ArkUI_SwiperIndicator](#arkui_swiperindicator) \*indicator, float value) | Sets the width of the selected navigation point indicator of the dot style for the **<Swiper>** component. |
| float [OH_ArkUI_SwiperIndicator_GetSelectedItemWidth](#oh_arkui_swiperindicator_getselecteditemwidth) ([ArkUI_SwiperIndicator](#arkui_swiperindicator) \*indicator) | Obtains the width of the selected navigation point indicator of the dot style of the **<Swiper>** component. |
| void [OH_ArkUI_SwiperIndicator_SetSelectedItemHeight](#oh_arkui_swiperindicator_setselecteditemheight) ([ArkUI_SwiperIndicator](#arkui_swiperindicator) \*indicator, float value) | Sets the height of the selected navigation point indicator of the dot style for the **<Swiper>** component. |
| float [OH_ArkUI_SwiperIndicator_GetSelectedItemHeight](#oh_arkui_swiperindicator_getselecteditemheight) ([ArkUI_SwiperIndicator](#arkui_swiperindicator) \*indicator) | Obtains the height of the selected navigation point indicator of the dot style of the **<Swiper>** component. |
| void [OH_ArkUI_SwiperIndicator_SetMask](#oh_arkui_swiperindicator_setmask) ([ArkUI_SwiperIndicator](#arkui_swiperindicator) \*indicator, int32_t mask) | Sets whether to enable the mask for a navigation point indicator of the dot style for the **<Swiper>** component. |
| int32_t [OH_ArkUI_SwiperIndicator_GetMask](#oh_arkui_swiperindicator_getmask) ([ArkUI_SwiperIndicator](#arkui_swiperindicator) \*indicator) | Obtains whether the mask is enabled for a navigation point indicator of the dot style of the **<Swiper>** component. |
| void [OH_ArkUI_SwiperIndicator_SetColor](#oh_arkui_swiperindicator_setcolor) ([ArkUI_SwiperIndicator](#arkui_swiperindicator) \*indicator, uint32_t color) | Sets the color of a navigation point indicator of the dot style for the **<Swiper>** component. |
| uint32_t [OH_ArkUI_SwiperIndicator_GetColor](#oh_arkui_swiperindicator_getcolor) ([ArkUI_SwiperIndicator](#arkui_swiperindicator) \*indicator) | Obtains the color of a navigation point indicator of the dot style of the **<Swiper>** component. |
| void [OH_ArkUI_SwiperIndicator_SetSelectedColor](#oh_arkui_swiperindicator_setselectedcolor) ([ArkUI_SwiperIndicator](#arkui_swiperindicator) \*indicator, uint32_t selectedColor) | Sets the color of the selected navigation point indicator of the dot style for the **<Swiper>** component. |
| uint32_t [OH_ArkUI_SwiperIndicator_GetSelectedColor](#oh_arkui_swiperindicator_getselectedcolor) ([ArkUI_SwiperIndicator](#arkui_swiperindicator) \*indicator) | Obtains the color of the selected navigation point indicator of the dot style of the **<Swiper>** component. |
| int32_t [OH_ArkUI_WaterFlowSectionOption_GetSize](#oh_arkui_waterflowsectionoption_getsize) ([ArkUI_WaterFlowSectionOption](#arkui_waterflowsectionoption) \*option) | Sets the length of the FlowItem group configuration information array. |
| void [OH_ArkUI_WaterFlowSectionOption_RegisterGetItemMainSizeCallbackByIndex](#oh_arkui_waterflowsectionoption_registergetitemmainsizecallbackbyindex) ([ArkUI_WaterFlowSectionOption](#arkui_waterflowsectionoption) \*option, int32_t index, float(\*callback)(int32_t itemIndex)) | Obtains the main axis size of a specified item based on **flowItemIndex** through a water flow section configuration. |
| [ArkUI_ListItemSwipeActionItem](#arkui_listitemswipeactionitem) \* [OH_ArkUI_ListItemSwipeActionItem_Create](#oh_arkui_listitemswipeactionitem_create) () | Creates an **ListItemSwipeActionItem** instance. |
| void [OH_ArkUI_ListItemSwipeActionItem_Dispose](#oh_arkui_listitemswipeactionitem_dispose) ([ArkUI_ListItemSwipeActionItem](#arkui_listitemswipeactionitem) \*item) | Destroys a ListItemSwipeActionItem instance. |
| void [OH_ArkUI_ListItemSwipeActionItem_SetContent](#oh_arkui_listitemswipeactionitem_setcontent) ([ArkUI_ListItemSwipeActionItem](#arkui_listitemswipeactionitem) \*item, ArkUI_NodeHandle node) | Sets the layout content of ListItemSwipeActionItem. |
| void [OH_ArkUI_ListItemSwipeActionItem_SetActionAreaDistance](#oh_arkui_listitemswipeactionitem_setactionareadistance) ([ArkUI_ListItemSwipeActionItem](#arkui_listitemswipeactionitem) \*item, float distance) | Swipe distance threshold for deleting the list item. |
| float [OH_ArkUI_ListItemSwipeActionItem_GetActionAreaDistance](#oh_arkui_listitemswipeactionitem_getactionareadistance) ([ArkUI_ListItemSwipeActionItem](#arkui_listitemswipeactionitem) \*item) | Obtains the swipe distance threshold for deleting the list item. |
| void [OH_ArkUI_ListItemSwipeActionItem_SetOnEnterActionArea](#oh_arkui_listitemswipeactionitem_setonenteractionarea) ([ArkUI_ListItemSwipeActionItem](#arkui_listitemswipeactionitem) \*item, void(\*callback)()) | Sets the callback invoked each time the list item enters the delete area. |
| void [OH_ArkUI_ListItemSwipeActionItem_SetOnEnterActionAreaWithUserData](#oh_arkui_listitemswipeactionitem_setonenteractionareawithuserdata) ([ArkUI_ListItemSwipeActionItem](#arkui_listitemswipeactionitem) \*item, void \*userData, void(\*callback)(void \*userData)) | Sets the callback invoked each time the list item enters the delete area. |
| void [OH_ArkUI_ListItemSwipeActionItem_SetOnAction](#oh_arkui_listitemswipeactionitem_setonaction) ([ArkUI_ListItemSwipeActionItem](#arkui_listitemswipeactionitem) \*item, void(\*callback)()) | Sets the callback invoked when the list item is deleted while in the delete area. |
| void [OH_ArkUI_ListItemSwipeActionItem_SetOnExitActionArea](#oh_arkui_listitemswipeactionitem_setonexitactionarea) ([ArkUI_ListItemSwipeActionItem](#arkui_listitemswipeactionitem) \*item, void(\*callback)()) | Sets the callback invoked each time the list item exits the delete area. |
| void [OH_ArkUI_ListItemSwipeActionItem_SetOnExitActionAreaWithUserData](#oh_arkui_listitemswipeactionitem_setonexitactionareawithuserdata) ([ArkUI_ListItemSwipeActionItem](#arkui_listitemswipeactionitem) \*item, void \*userData, void(\*callback)(void \*userData)) | Sets the callback invoked each time the list item exits the delete area. |
| void [OH_ArkUI_ListItemSwipeActionItem_SetOnStateChange](#oh_arkui_listitemswipeactionitem_setonstatechange) ([ArkUI_ListItemSwipeActionItem](#arkui_listitemswipeactionitem) \*item, void(\*callback)([ArkUI_ListItemSwipeActionState](#arkui_listitemswipeactionstate) swipeActionState)) | Sets the callback invoked when the swipe state of the list item changes. |
| void [OH_ArkUI_ListItemSwipeActionItem_SetOnStateChangeWithUserData](#oh_arkui_listitemswipeactionitem_setonstatechangewithuserdata) ([ArkUI_ListItemSwipeActionItem](#arkui_listitemswipeactionitem) \*item, void \*userData, void(\*callback)([ArkUI_ListItemSwipeActionState](#arkui_listitemswipeactionstate) swipeActionState, void \*userData)) | Sets the callback invoked when the swipe state of the list item changes. |
| [ArkUI_ListItemSwipeActionOption](#arkui_listitemswipeactionoption) \* [OH_ArkUI_ListItemSwipeActionOption_Create](#oh_arkui_listitemswipeactionoption_create) () | Creates a **ListItemSwipeActionOption** instance. |
| void [OH_ArkUI_ListItemSwipeActionOption_Dispose](#oh_arkui_listitemswipeactionoption_dispose) ([ArkUI_ListItemSwipeActionOption](#arkui_listitemswipeactionoption) \*option) | Destroys a ListItemSwipeActionOption instance. |
| void [OH_ArkUI_ListItemSwipeActionOption_SetStart](#oh_arkui_listitemswipeactionoption_setstart) ([ArkUI_ListItemSwipeActionOption](#arkui_listitemswipeactionoption) \*option, [ArkUI_ListItemSwipeActionItem](#arkui_listitemswipeactionitem) \*item) | Sets the layout content for the left edge (for a vertical layout) or top edge (for a horizontal layout) of a **ListItemSwipeActionOption** instance. |
| void [OH_ArkUI_ListItemSwipeActionOption_SetEnd](#oh_arkui_listitemswipeactionoption_setend) ([ArkUI_ListItemSwipeActionOption](#arkui_listitemswipeactionoption) \*option, [ArkUI_ListItemSwipeActionItem](#arkui_listitemswipeactionitem) \*item) | Sets the layout content for the right edge (for a vertical layout) or bottom edge (for a horizontal layout) of a **ListItemSwipeActionOption** instance. |
| void [OH_ArkUI_ListItemSwipeActionOption_SetEdgeEffect](#oh_arkui_listitemswipeactionoption_setedgeeffect) ([ArkUI_ListItemSwipeActionOption](#arkui_listitemswipeactionoption) \*option, [ArkUI_ListItemSwipeEdgeEffect](#arkui_listitemswipeedgeeffect) edgeEffect) | Sets the sliding effect. |
| int32_t [OH_ArkUI_ListItemSwipeActionOption_GetEdgeEffect](#oh_arkui_listitemswipeactionoption_getedgeeffect) ([ArkUI_ListItemSwipeActionOption](#arkui_listitemswipeactionoption) \*option) | Obtains the sliding effect. |
| void [OH_ArkUI_ListItemSwipeActionOption_SetOnOffsetChange](#oh_arkui_listitemswipeactionoption_setonoffsetchange) ([ArkUI_ListItemSwipeActionOption](#arkui_listitemswipeactionoption) \*option, void(\*callback)(float offset)) | Sets the callback invoked when the scroll offset changes. |
| void [OH_ArkUI_ListItemSwipeActionOption_SetOnOffsetChangeWithUserData](#oh_arkui_listitemswipeactionoption_setonoffsetchangewithuserdata) ([ArkUI_ListItemSwipeActionOption](#arkui_listitemswipeactionoption) \*option, void \*userData, void(\*callback)(float offset, void \*userData)) | Sets the callback invoked when the scroll offset changes. |
| [ArkUI_StyledString](#arkui_styledstring) \* [OH_ArkUI_StyledString_Create](#oh_arkui_styledstring_create) (OH_Drawing_TypographyStyle \*style, OH_Drawing_FontCollection \*collection) | Creates an **OH_Drawing_Typography** object. |
| void [OH_ArkUI_StyledString_Destroy](#oh_arkui_styledstring_destroy) ([ArkUI_StyledString](#arkui_styledstring) \*handle) | Destroys an **OH_Drawing_FontCollection** object and reclaims the memory occupied by the object. |
| void [OH_ArkUI_StyledString_PushTextStyle](#oh_arkui_styledstring_pushtextstyle) ([ArkUI_StyledString](#arkui_styledstring) \*handle, OH_Drawing_TextStyle \*style) | Sets the new typesetting style to the top of the current format string style stack. |
| void [OH_ArkUI_StyledString_AddText](#oh_arkui_styledstring_addtext) ([ArkUI_StyledString](#arkui_styledstring) \*handle, const char \*content) | Sets the text content based on the current format string style. |
| void [OH_ArkUI_StyledString_PopTextStyle](#oh_arkui_styledstring_poptextstyle) ([ArkUI_StyledString](#arkui_styledstring) \*handle) | Removes the top style from the current formatted string object. |
| OH_Drawing_Typography \* [OH_ArkUI_StyledString_CreateTypography](#oh_arkui_styledstring_createtypography) ([ArkUI_StyledString](#arkui_styledstring) \*handle) | Creates a pointer to the OH_Drawing_Typography object based on the format string object for text calculation and typesetting in advance. |
| void [OH_ArkUI_StyledString_AddPlaceholder](#oh_arkui_styledstring_addplaceholder) ([ArkUI_StyledString](#arkui_styledstring) \*handle, OH_Drawing_PlaceholderSpan \*placeholder) | Adds a placeholder. |
| [ArkUI_ListChildrenMainSize](#arkui_listchildrenmainsize) \* [OH_ArkUI_ListChildrenMainSizeOption_Create](#oh_arkui_listchildrenmainsizeoption_create) () | Creates a **ListChildrenMainSize** instance. |
| void [OH_ArkUI_ListChildrenMainSizeOption_Dispose](#oh_arkui_listchildrenmainsizeoption_dispose) ([ArkUI_ListChildrenMainSize](#arkui_listchildrenmainsize) \*option) | Destroys a ListChildrenMainSize instance. |
| int32_t [OH_ArkUI_ListChildrenMainSizeOption_SetDefaultMainSize](#oh_arkui_listchildrenmainsizeoption_setdefaultmainsize) ([ArkUI_ListChildrenMainSize](#arkui_listchildrenmainsize) \*option, float defaultMainSize) | Sets the default size of ChildrenMainSizeOption of the List component. |
| float [OH_ArkUI_ListChildrenMainSizeOption_GetDefaultMainSize](#oh_arkui_listchildrenmainsizeoption_getdefaultmainsize) ([ArkUI_ListChildrenMainSize](#arkui_listchildrenmainsize) \*option) | Obtains the default size in a **ListChildrenMainSize** instance. |
| void [OH_ArkUI_ListChildrenMainSizeOption_Resize](#oh_arkui_listchildrenmainsizeoption_resize) ([ArkUI_ListChildrenMainSize](#arkui_listchildrenmainsize) \*option, int32_t totalSize) | Resets the array size of ChildrenMainSizeOption of the List component. |
| int32_t [OH_ArkUI_ListChildrenMainSizeOption_Splice](#oh_arkui_listchildrenmainsizeoption_splice) ([ArkUI_ListChildrenMainSize](#arkui_listchildrenmainsize) \*option, int32_t index, int32_t deleteCount, int32_t addCount) | The size of the ChildrenMainSizeOption array of the List component is adjusted. |
| int32_t [OH_ArkUI_ListChildrenMainSizeOption_UpdateSize](#oh_arkui_listchildrenmainsizeoption_updatesize) ([ArkUI_ListChildrenMainSize](#arkui_listchildrenmainsize) \*option, int32_t index, float mainSize) | Updates the value of the ChildrenMainSizeOption array of the List component. |
| float [OH_ArkUI_ListChildrenMainSizeOption_GetMainSize](#oh_arkui_listchildrenmainsizeoption_getmainsize) ([ArkUI_ListChildrenMainSize](#arkui_listchildrenmainsize) \*option, int32_t index) | Obtains the value of the ChildrenMainSizeOption array of the List component. |
| int32_t [OH_ArkUI_List_CloseAllSwipeActions](#oh_arkui_list_closeallswipeactions) ([ArkUI_NodeHandle](#arkui_nodehandle) node, void \*userData, void(\*onFinish)(void \*userData)) | Collapse the expanded ListItem. |
| [ArkUI_ImageAnimatorFrameInfo](#arkui_imageanimatorframeinfo) \* [OH_ArkUI_ImageAnimatorFrameInfo_CreateFromString](#oh_arkui_imageanimatorframeinfo_createfromstring) (char \*src) | Creates an image frame information object based on an image path, with the image format being SVG, PNG, or JPG. |
| [ArkUI_ImageAnimatorFrameInfo](#arkui_imageanimatorframeinfo) \* [OH_ArkUI_ImageAnimatorFrameInfo_CreateFromDrawableDescriptor](#oh_arkui_imageanimatorframeinfo_createfromdrawabledescriptor) ([ArkUI_DrawableDescriptor](#arkui_drawabledescriptor) \*drawable) | Use the DrawableDescriptor object to create frame image information. The image formats are Resource and PixelMap. |
| void [OH_ArkUI_ImageAnimatorFrameInfo_Dispose](#oh_arkui_imageanimatorframeinfo_dispose) ([ArkUI_ImageAnimatorFrameInfo](#arkui_imageanimatorframeinfo) \*imageInfo) | Pointer to the frame image object to be destroyed. |
| void [OH_ArkUI_ImageAnimatorFrameInfo_SetWidth](#oh_arkui_imageanimatorframeinfo_setwidth) ([ArkUI_ImageAnimatorFrameInfo](#arkui_imageanimatorframeinfo) \*imageInfo, int32_t width) |     // Set the image width. |
| int32_t [OH_ArkUI_ImageAnimatorFrameInfo_GetWidth](#oh_arkui_imageanimatorframeinfo_getwidth) ([ArkUI_ImageAnimatorFrameInfo](#arkui_imageanimatorframeinfo) \*imageInfo) | Obtains the image width. |
| void [OH_ArkUI_ImageAnimatorFrameInfo_SetHeight](#oh_arkui_imageanimatorframeinfo_setheight) ([ArkUI_ImageAnimatorFrameInfo](#arkui_imageanimatorframeinfo) \*imageInfo, int32_t height) |     // Set the image height. |
| int32_t [OH_ArkUI_ImageAnimatorFrameInfo_GetHeight](#oh_arkui_imageanimatorframeinfo_getheight) ([ArkUI_ImageAnimatorFrameInfo](#arkui_imageanimatorframeinfo) \*imageInfo) | Obtains the image height. |
| void [OH_ArkUI_ImageAnimatorFrameInfo_SetTop](#oh_arkui_imageanimatorframeinfo_settop) ([ArkUI_ImageAnimatorFrameInfo](#arkui_imageanimatorframeinfo) \*imageInfo, int32_t top) | Sets the vertical coordinate of an image relative to the upper left corner of the component. |
| int32_t [OH_ArkUI_ImageAnimatorFrameInfo_GetTop](#oh_arkui_imageanimatorframeinfo_gettop) ([ArkUI_ImageAnimatorFrameInfo](#arkui_imageanimatorframeinfo) \*imageInfo) | Obtains the vertical coordinate of an image relative to the upper left corner of the component. |
| void [OH_ArkUI_ImageAnimatorFrameInfo_SetLeft](#oh_arkui_imageanimatorframeinfo_setleft) ([ArkUI_ImageAnimatorFrameInfo](#arkui_imageanimatorframeinfo) \*imageInfo, int32_t left) | Sets the horizontal coordinate of an image relative to the upper left corner of the component. |
| int32_t [OH_ArkUI_ImageAnimatorFrameInfo_GetLeft](#oh_arkui_imageanimatorframeinfo_getleft) ([ArkUI_ImageAnimatorFrameInfo](#arkui_imageanimatorframeinfo) \*imageInfo) | Obtains the horizontal coordinate of an image relative to the upper left corner of the component. |
| void [OH_ArkUI_ImageAnimatorFrameInfo_SetDuration](#oh_arkui_imageanimatorframeinfo_setduration) ([ArkUI_ImageAnimatorFrameInfo](#arkui_imageanimatorframeinfo) \*imageInfo, int32_t duration) | Sets the playback duration of an image. |
| int32_t [OH_ArkUI_ImageAnimatorFrameInfo_GetDuration](#oh_arkui_imageanimatorframeinfo_getduration) ([ArkUI_ImageAnimatorFrameInfo](#arkui_imageanimatorframeinfo) \*imageInfo) | Obtains the playback duration of an image. |


## Macro Description


### OH_ArkUI_GetModuleInterface

```
#define OH_ArkUI_GetModuleInterface( nativeAPIVariantKind,  structType,  structPtr )
```
**Value:**
```
 do { \
 void* anyNativeAPI = OH_ArkUI_QueryModuleInterfaceByName(nativeAPIVariantKind, #structType); \
 if (anyNativeAPI) { \
 structPtr = (structType*)(anyNativeAPI); \
 } \
 } while (0)
#include<arkui/native_interface.h>
#include<arkui/native_node.h>
 
ArkUI_NativeNodeAPI_1* nativeNodeApi = nullptr;
OH_ArkUI_GetModuleInterface(ARKUI_NATIVE_NODE, ArkUI_NativeNodeAPI_1, nativeNodeApi);
```
**Description**

Obtains the macro function corresponding to a struct pointer based on the struct type.

**Since**: 12


## Type Description

### ArkUI_ImageAnimatorFrameInfo

```
typedef struct ArkUI_ImageAnimatorFrameInfo ArkUI_ImageAnimatorFrameInfo
```
**Description**

Defines the image frame information.

**Since**: 12

### ArkUI_ListChildrenMainSize

```
typedef struct ArkUI_ListChildrenMainSizeArkUI_ListChildrenMainSize
```
**Description**

Defines the **ChildrenMainSize** information of the **\<List>** component.

**Since**: 12

### ArkUI_StyledString

```
typedef struct ArkUI_StyledString ArkUI_StyledString
```
**Description**
Defines a styled string object supported by the text component.

**Since**: 12

### ArkUI_ListItemSwipeActionItem

```
typedef struct ArkUI_ListItemSwipeActionItem ArkUI_ListItemSwipeActionItem
```
**Description**
Defines the item configuration for **ListItemSwipeActionOption**.

**Since**: 12


### ArkUI_ListItemSwipeActionOption

```
typedef struct ArkUI_ListItemSwipeActionOption ArkUI_ListItemSwipeActionOption
```
**Description**
Defines the configuration for **ListItemSwipeActionOption**.

**Since**: 12


### OH_PixelmapNativeHandle

```
typedef struct OH_PixelmapNative* OH_PixelmapNativeHandle
```
**Description**
Defines the pointer to an **OH_PixelmapNative** object.

**Since**: 12


### ArkUI_AlignmentRuleOption

```
typedef struct ArkUI_AlignmentRuleOption ArkUI_AlignmentRuleOption
```
**Description**

Defines the alignment rule in the relative container.

**Since**: 12


### ArkUI_AnimateOption

```
typedef struct ArkUI_AnimateOption ArkUI_AnimateOption
```
**Description**

Defines the animation configuration.

**Since**: 12


### ArkUI_BarrierOption

```
typedef struct ArkUI_BarrierOption ArkUI_BarrierOption
```
**Description**

Defines the ID, direction, and referenced component of a barrier.

**Since**: 12


### ArkUI_ContextHandle

```
typedef struct ArkUI_Context* ArkUI_ContextHandle
```
**Description**

Defines the handle to the ArkUI native UI context.

**Since**: 12


### ArkUI_DrawableDescriptor

```
typedef struct ArkUI_DrawableDescriptor ArkUI_DrawableDescriptor
```
**Description**

Defines a **DrawableDescriptor** object.

**Since**: 12


### ArkUI_DrawContext

```
typedef struct ArkUI_DrawContext ArkUI_DrawContext
```
**Description**

Defines the component drawing context.

**Since**: 12


### ArkUI_GestureDirectionMask

```
typedef uint32_t ArkUI_GestureDirectionMask
```
**Description**

Defines a set of gesture directions.

**Since**: 12


### ArkUI_GestureEventActionTypeMask

```
typedef uint32_t ArkUI_GestureEventActionTypeMask
```
**Description**

Defines a set of gesture event types.

Example: ArkUI_GestureEventActionTypeMask actions = GESTURE_EVENT_ACTION_ACCEPT | GESTURE_EVENT_ACTION_UPDATE;

**Since**: 12


### ArkUI_GuidelineOption

```
typedef struct ArkUI_GuidelineOption ArkUI_GuidelineOption
```
**Description**

Defines the ID, direction, and position of a guideline.

**Since**: 12


### ArkUI_LayoutConstraint

```
typedef struct ArkUI_LayoutConstraint ArkUI_LayoutConstraint
```
**Description**

Size constraints of the component during component layout.

**Since**: 12


### ArkUI_NativeDialogHandle

```
typedef struct ArkUI_NativeDialog* ArkUI_NativeDialogHandle
```
**Description**

Defines the handle to the custom dialog box controller of ArkUI on the native side.

**Since**: 12


### ArkUI_NodeAdapterEvent

```
typedef struct ArkUI_NodeAdapterEvent ArkUI_NodeAdapterEvent
```
**Description**

Defines the component adapter event.

**Since**: 12


### ArkUI_NodeAdapterHandle

```
typedef struct ArkUI_NodeAdapter* ArkUI_NodeAdapterHandle
```
**Description**

Defines the component adapter, which is used for lazy loading of elements of scrollable components.

**Since**: 12


### ArkUI_NodeCustomEvent

```
typedef struct ArkUI_NodeCustomEvent ArkUI_NodeCustomEvent
```
**Description**

Defines the common structure of a custom component event.

**Since**: 12


### ArkUI_NodeEvent

```
typedef struct ArkUI_NodeEvent ArkUI_NodeEvent
```
**Description**

Defines the common structure type of a component event.

**Since**: 12


### ArkUI_NodeHandle

```
typedef struct ArkUI_Node* ArkUI_NodeHandle
```
**Description**

Defines the pointer to the ArkUI native component object.

**Since**: 12


### ArkUI_OnWillDismissEvent

```
typedef bool(* ArkUI_OnWillDismissEvent) (int32_t reason)
```
**Description**

Invoked when the dialog box is closed.

**Since**: 12


### ArkUI_SwiperIndicator

```
typedef struct ArkUI_SwiperIndicator ArkUI_SwiperIndicator
```
**Description**

Defines the navigation point indicator style of the **\<Swiper>** component.

**Since**: 12


### ArkUI_WaterFlowSectionOption

```
typedef struct ArkUI_WaterFlowSectionOption ArkUI_WaterFlowSectionOption
```
**Description**

Defines the water flow section configuration.

**Since**: 12


### OH_PixelmapNativeHandle

```
typedef struct OH_PixelmapNative* OH_PixelmapNativeHandle
```
**Description**

Defines the pointer to an **OH_PixelmapNative** object.

**Since**: 12


## Enum Description

### ArkUI_AnimationFillMode

```
enum ArkUI_AnimationFillMode
```
**Description**

Enumerates the states before and after execution of the frame-by-frame animation.

**Since**: 12

| Value| Description|
| -------- | -------- |
| ARKUI_ANIMATION_FILL_MODE_NONE  | Before execution, the animation does not apply any styles to the target component. After execution, the animation restores the target component to its default state. |
| ARKUI_ANIMATION_FILL_MODE_FORWARDS  | The target component retains the state set by the last keyframe encountered during execution of the animation. |
| ARKUI_ANIMATION_FILL_MODE_BACKWARDS  | The animation applies the values defined in the first relevant keyframe once it is applied to the target component, and retains the values during the period set by **delay**. |
| ARKUI_ANIMATION_FILL_MODE_BOTH  | The animation follows the rules for both **Forwards** and **Backwards**, extending the animation attributes in both directions. |

### ArkUI_AnimationStatus

```
enum ArkUI_AnimationStatus
```
**Description**

Enumerates the playback states of the frame-by-frame animation.

**Since**: 12

| Value| Description|
| -------- | -------- |
| ARKUI_ANIMATION_STATUS_INITIAL  | The animation is in the initial state. |
| ARKUI_ANIMATION_STATUS_RUNNING  | The animation is being played. |
| ARKUI_ANIMATION_STATUS_PAUSED  | The animation is paused. |
| ARKUI_ANIMATION_STATUS_STOPED  | The animation is stopped. |

### ArkUI_ListItemSwipeActionState

```
enum ArkUI_ListItemSwipeActionState
```
**Description**
Enumerates the swipe action item states of list items.

**Since**: 12

| Value| Description|
| -------- | -------- |
| ARKUI_LIST_ITEM_SWIPE_ACTION_STATE_COLLAPSED  | Collapsed state. When the list item is swiped in the opposite direction of the main axis, the swipe action item is hidden.&nbsp;&nbsp; |
| ARKUI_LIST_ITEM_SWIPE_ACTION_STATE_EXPANDED  | Expanded state. When the list item is swiped in the opposite direction of the main axis, the swipe action item is shown.&nbsp;&nbsp; |
| ARKUI_LIST_ITEM_SWIPE_ACTION_STATE_ACTIONING  | In-action state. The list item is in this state when it enters the delete area.&nbsp;&nbsp; |


### ArkUI_ListItemSwipeEdgeEffect

```
enum ArkUI_ListItemSwipeEdgeEffect
```
**Description**
Enumerates the swipe action item edge effects of list items.

**Since**: 12

| Value| Description|
| -------- | -------- |
| ARKUI_LIST_ITEM_SWIPE_EDGE_EFFECT_SPRING  | When the list item scrolls to the edge of the list, it can continue to scroll for a distance.&nbsp;&nbsp; |
| ARKUI_LIST_ITEM_SWIPE_EDGE_EFFECT_NONE  | The list item cannot scroll beyond the edge of the list.&nbsp;&nbsp;|


### ArkUI_AccessibilityMode

```
enum ArkUI_AccessibilityMode
```
**Description**

Enumerates the accessibility modes.

**Since**: 12

| Value| Description|
| -------- | -------- |
| ARKUI_ACCESSIBILITY_MODE_AUTO  | The value is changed to enabled or disabled based on the component.&nbsp;&nbsp; |
| ARKUI_ACCESSIBILITY_MODE_ENABLED  | The component can be identified by the accessibility service.&nbsp;&nbsp; |
| ARKUI_ACCESSIBILITY_MODE_DISABLED  | The component cannot be identified by the accessibility service.&nbsp;&nbsp; |
| ARKUI_ACCESSIBILITY_MODE_DISABLED_FOR_DESCENDANTS  | The component and all its child components cannot be identified by the accessibility service.&nbsp;&nbsp; |


### ArkUI_AdaptiveColor

```
enum ArkUI_AdaptiveColor
```
**Description**

Enumerates the adaptive color modes.

**Since**: 12

| Value| Description|
| -------- | -------- |
| ARKUI_ADAPTIVE_COLOR_DEFAULT  | Adaptive color mode is not used.&nbsp;&nbsp; |
| ARKUI_ADAPTIVE_COLOR_AVERAGE  | Adaptive color mode is used.&nbsp;&nbsp; |


### ArkUI_Alignment

```
enum ArkUI_Alignment
```
**Description**

Enumerates the alignment modes.

**Since**: 12

| Value| Description|
| -------- | -------- |
| ARKUI_ALIGNMENT_TOP_START  | Top start.&nbsp;&nbsp; |
| ARKUI_ALIGNMENT_TOP  | Top center.&nbsp;&nbsp; |
| ARKUI_ALIGNMENT_TOP_END  | Top end.&nbsp;&nbsp; |
| ARKUI_ALIGNMENT_START  | Vertically centered start.&nbsp;&nbsp; |
| ARKUI_ALIGNMENT_CENTER  | Horizontally and vertically centered.&nbsp;&nbsp; |
| ARKUI_ALIGNMENT_END  | Vertically centered end.&nbsp;&nbsp; |
| ARKUI_ALIGNMENT_BOTTOM_START  | Bottom start.&nbsp;&nbsp; |
| ARKUI_ALIGNMENT_BOTTOM  | Horizontally centered on the bottom.&nbsp;&nbsp; |
| ARKUI_ALIGNMENT_BOTTOM_END  | Bottom end.&nbsp;&nbsp; |


### ArkUI_AnimationCurve

```
enum ArkUI_AnimationCurve
```
**Description**

Enumerates the animation curves.

**Since**: 12

| Value| Description|
| -------- | -------- |
| ARKUI_CURVE_LINEAR  | The animation speed keeps unchanged.&nbsp;&nbsp; |
| ARKUI_CURVE_EASE  | The animation starts slowly, accelerates, and then slows down towards the end.&nbsp;&nbsp; |
| ARKUI_CURVE_EASE_IN  | The animation starts at a low speed and then picks up speed until the end.&nbsp;&nbsp; |
| ARKUI_CURVE_EASE_OUT  | The animation ends at a low speed.&nbsp;&nbsp; |
| ARKUI_CURVE_EASE_IN_OUT  | The animation starts and ends at a low speed.&nbsp;&nbsp; |
| ARKUI_CURVE_FAST_OUT_SLOW_IN  | The animation uses the standard curve&nbsp;&nbsp; |
| ARKUI_CURVE_LINEAR_OUT_SLOW_IN  | The animation uses the deceleration curve.&nbsp;&nbsp; |
| ARKUI_CURVE_FAST_OUT_LINEAR_IN  | The animation uses the acceleration curve.&nbsp;&nbsp; |
| ARKUI_CURVE_EXTREME_DECELERATION  | The animation uses the extreme deceleration curve.&nbsp;&nbsp; |
| ARKUI_CURVE_SHARP  | The animation uses the sharp curve.&nbsp;&nbsp; |
| ARKUI_CURVE_RHYTHM  | The animation uses the rhythm curve.&nbsp;&nbsp; |
| ARKUI_CURVE_SMOOTH  | The animation uses the smooth curve.&nbsp;&nbsp; |
| ARKUI_CURVE_FRICTION  | The animation uses the friction curve&nbsp;&nbsp; |


### ArkUI_AnimationPlayMode

```
enum ArkUI_AnimationPlayMode
```
**Description**

Enumerates the animation playback modes.

**Since**: 12

| Value| Description|
| -------- | -------- |
| ARKUI_ANIMATION_PLAY_MODE_NORMAL  | The animation is played forwards.&nbsp;&nbsp; |
| ARKUI_ANIMATION_PLAY_MODE_REVERSE  | The animation is played backwards.&nbsp;&nbsp; |
| ARKUI_ANIMATION_PLAY_MODE_ALTERNATE  | The animation is played forwards for an odd number of times (1, 3, 5...) and backwards for an even number of times (2, 4, 6...).&nbsp;&nbsp; |
| ARKUI_ANIMATION_PLAY_MODE_ALTERNATE_REVERSE  | The animation is played backwards for an odd number of times (1, 3, 5...) and forwards for an even number of times (2, 4, 6...).&nbsp;&nbsp; |


### ArkUI_Axis

```
enum ArkUI_Axis
```
**Description**

Enumerates the scroll directions.

**Since**: 12

| Value| Description|
| -------- | -------- |
| ARKUI_AXIS_VERTICAL  | Only vertical scrolling is supported.&nbsp;&nbsp; |
| ARKUI_AXIS_HORIZONTAL  | Only horizontal scrolling is supported.&nbsp;&nbsp; |


### ArkUI_BarrierDirection

```
enum ArkUI_BarrierDirection
```
**Description**

Defines the direction of a barrier.

**Since**: 12

| Value| Description|
| -------- | -------- |
| ARKUI_BARRIER_DIRECTION_START  | The barrier is on the left side of all the referenced components specified by referencedId.&nbsp;&nbsp; |
| ARKUI_BARRIER_DIRECTION_END  | The barrier is on the right side of all the referenced components specified by referencedId.&nbsp;&nbsp; |
| ARKUI_BARRIER_DIRECTION_TOP  | The barrier is at the top of all the referenced components specified by referencedId.&nbsp;&nbsp; |
| ARKUI_BARRIER_DIRECTION_BOTTOM  | The barrier is at the bottom of all the referenced components specified by referencedId.&nbsp;&nbsp; |

### ArkUI_BlendApplyType

```
enum ArkUI_BlendApplyType
```
**Description**

Defines how the specified blend mode is applied.

**Since**: 12

| Value| Description|
| -------- | -------- |
| BLEND_APPLY_TYPE_FAST  | Mix the contents of the view in sequence on the target image.&nbsp;&nbsp;|
| BLEND_APPLY_TYPE_OFFSCREEN  | Draw the component and its child components on the off-screen canvas, and then mix them as a whole.&nbsp;&nbsp;|


### ArkUI_BlendMode

```
enum ArkUI_BlendMode
```
**Description**

Enumerates the blend modes.

**Since**: 12

| Value| Description|
| -------- | -------- |
| ARKUI_BLEND_MODE_NONE  | The top image is superimposed on the bottom image without any blending.&nbsp;&nbsp; |
| ARKUI_BLEND_MODE_CLEAR  | The target pixels covered by the source pixels are erased by being turned to completely transparent.&nbsp;&nbsp; |
| ARKUI_BLEND_MODE_SRC  | r = s: Only the source pixels are displayed.&nbsp;&nbsp; |
| ARKUI_BLEND_MODE_DST  | r = d: Only the target pixels are displayed.&nbsp;&nbsp; |
| ARKUI_BLEND_MODE_SRC_OVER  | r = s + (1 - sa) \d: The source pixels are blended based on opacity and cover the target pixels.&nbsp;&nbsp; |
| ARKUI_BLEND_MODE_DST_OVER  | r = d + (1 - da) *\ s: The target pixels are blended based on opacity and cover on the source pixels.&nbsp;&nbsp; |
| ARKUI_BLEND_MODE_SRC_IN  | r = s \da: Only the part of the source pixels that overlap with the target pixels is displayed.&nbsp;&nbsp; |
| ARKUI_BLEND_MODE_DST_IN  | r = d \sa: Only the part of the target pixels that overlap with the source pixels is displayed.&nbsp;&nbsp; |
| ARKUI_BLEND_MODE_SRC_OUT  | r = s \(1 - da): Only the part of the source pixels that do not overlap with the target pixels is displayed.&nbsp;&nbsp; |
| ARKUI_BLEND_MODE_DST_OUT  | r = d \(1 - sa): Only the part of the target pixels that do not overlap with the source pixels is displayed.&nbsp;&nbsp; |
| ARKUI_BLEND_MODE_SRC_ATOP  | r = s \da + d \(1 - sa): The part of the source pixels that overlap with the target pixels is displayed and the part of the target pixels that do not overlap with the source pixels are displayed.&nbsp;&nbsp; |
| ARKUI_BLEND_MODE_DST_ATOP  | r = d \sa + s \(1 - da): The part of the target pixels that overlap with the source pixels and the part of the source pixels that do not overlap with the target pixels are displayed.&nbsp;&nbsp; |
| ARKUI_BLEND_MODE_XOR  | r = s \(1 - da) + d \(1 - sa): Only the non-overlapping part between the source pixels and the target pixels is displayed.&nbsp;&nbsp; |
| ARKUI_BLEND_MODE_PLUS  | r = min(s + d, 1): New pixels resulting from adding the source pixels to the target pixels are displayed.&nbsp;&nbsp; |
| ARKUI_BLEND_MODE_MODULATE  | r = s \d: New pixels resulting from multiplying the source pixels with the target pixels are displayed.&nbsp;&nbsp; |
| ARKUI_BLEND_MODE_SCREEN  | r = s + d - s \d: Pixels are blended by adding the source pixels to the target pixels and subtracting the product of their multiplication.&nbsp;&nbsp; |
| ARKUI_BLEND_MODE_OVERLAY  | The MULTIPLY or SCREEN mode is used based on the target pixels.&nbsp;&nbsp; |
| ARKUI_BLEND_MODE_DARKEN  | rc = s + d - max(s \da, d \sa), ra = kSrcOver: When two colors overlap, whichever is darker is used.&nbsp;&nbsp; |
| ARKUI_BLEND_MODE_LIGHTEN  | rc = s + d - min(s \da, d \sa), ra = kSrcOver: The darker of the pixels (source and target) is used.&nbsp;&nbsp; |
| ARKUI_BLEND_MODE_COLOR_DODGE  | The colors of the target pixels are lightened to reflect the source pixels.&nbsp;&nbsp; |
| ARKUI_BLEND_MODE_COLOR_BURN  | The colors of the target pixels are darkened to reflect the source pixels.&nbsp;&nbsp; |
| ARKUI_BLEND_MODE_HARD_LIGHT  | The MULTIPLY or SCREEN mode is used, depending on the source pixels.&nbsp;&nbsp; |
| ARKUI_BLEND_MODE_SOFT_LIGHT  | The LIGHTEN or DARKEN mode is used, depending on the source pixels.&nbsp;&nbsp; |
| ARKUI_BLEND_MODE_DIFFERENCE  | rc = s + d - 2 \(min(s \da, d \sa)), ra = kSrcOver: The final pixel is the result of subtracting the darker of the two pixels (source and target) from the lighter one.&nbsp;&nbsp; |
| ARKUI_BLEND_MODE_EXCLUSION  | rc = s + d - two(s \d), ra = kSrcOver: The final pixel is similar to DIFFERENCE, but with less contrast.&nbsp;&nbsp; |
| ARKUI_BLEND_MODE_MULTIPLY  | r = s \(1 - da) + d \(1 - sa) + s \d: The final pixel is the result of multiplying the source pixel by the target pixel.|
| ARKUI_BLEND_MODE_HUE  | The resultant image is created with the luminance and saturation of the source image and the hue of the target image.&nbsp;&nbsp; |
| ARKUI_BLEND_MODE_SATURATION  | The resultant image is created with the luminance and hue of the target image and the saturation of the source image.&nbsp;&nbsp; |
| ARKUI_BLEND_MODE_COLOR  | The resultant image is created with the saturation and hue of the source image and the luminance of the target image.&nbsp;&nbsp; |
| ARKUI_BLEND_MODE_LUMINOSITY  | The resultant image is created with the saturation and hue of the target image and the luminance of the source image.&nbsp;&nbsp; |


### ArkUI_BlurStyle

```
enum ArkUI_BlurStyle
```
**Description**

Enumerates the blur styles.

**Since**: 12

| Value| Description|
| -------- | -------- |
| ARKUI_BLUR_STYLE_THIN  | Thin material.&nbsp;&nbsp; |
| ARKUI_BLUR_STYLE_REGULAR  | Regular material.&nbsp;&nbsp; |
| ARKUI_BLUR_STYLE_THICK  | Thick material.&nbsp;&nbsp; |
| ARKUI_BLUR_STYLE_BACKGROUND_THIN  | Material that creates the minimum depth of field effect.&nbsp;&nbsp; |
| ARKUI_BLUR_STYLE_BACKGROUND_REGULAR  | Material that creates a medium shallow depth of field effect.&nbsp;&nbsp; |
| ARKUI_BLUR_STYLE_BACKGROUND_THICK  | Material that creates a high shallow depth of field effect.&nbsp;&nbsp; |
| ARKUI_BLUR_STYLE_BACKGROUND_ULTRA_THICK  | Material that creates the maximum depth of field effect.&nbsp;&nbsp; |
| ARKUI_BLUR_STYLE_NONE  | No blur.&nbsp;&nbsp; |
| ARKUI_BLUR_STYLE_COMPONENT_ULTRA_THIN  | Component ultra-thin material.&nbsp;&nbsp; |
| ARKUI_BLUR_STYLE_COMPONENT_THIN  | Component thin material.&nbsp;&nbsp; |
| ARKUI_BLUR_STYLE_COMPONENT_REGULAR  | Component regular material.&nbsp;&nbsp; |
| ARKUI_BLUR_STYLE_COMPONENT_THICK  | Component thick material.&nbsp;&nbsp; |
| ARKUI_BLUR_STYLE_COMPONENT_ULTRA_THICK  | Component ultra-thick material.&nbsp;&nbsp; |

### ArkUI_BorderStyle

```
enum ArkUI_BorderStyle
```
**Description**

Enumerates the border styles.

**Since**: 12

| Value| Description|
| -------- | -------- |
| ARKUI_BORDER_STYLE_SOLID  | Solid border.&nbsp;&nbsp; |
| ARKUI_BORDER_STYLE_DASHED  | Dashed border.&nbsp;&nbsp; |
| ARKUI_BORDER_STYLE_DOTTED  | Dotted border.&nbsp;&nbsp; |


### ArkUI_ButtonType

```
enum ArkUI_ButtonType
```
**Description**

Enumerates the button types.

**Since**: 12

| Value| Description|
| -------- | -------- |
| ARKUI_BUTTON_TYPE_NORMAL  | Normal button (without rounded corners by default).&nbsp;&nbsp; |
| ARKUI_BUTTON_TYPE_CAPSULE  | Capsule-type button (the round corner is half of the height by default).&nbsp;&nbsp; |
| ARKUI_BUTTON_TYPE_CIRCLE  | Circle button.&nbsp;&nbsp; |


### ArkUI_CalendarAlignment

```
enum ArkUI_CalendarAlignment
```
**Description**

Enumerates the alignment modes between the calendar picker and the entry component.

**Since**: 12

| Value| Description|
| -------- | -------- |
| ARKUI_CALENDAR_ALIGNMENT_START  | Left aligned.&nbsp;&nbsp; |
| ARKUI_CALENDAR_ALIGNMENT_CENTER  | Center aligned.&nbsp;&nbsp; |
| ARKUI_CALENDAR_ALIGNMENT_END  | Right aligned.&nbsp;&nbsp; |


### ArkUI_CancelButtonStyle

```
enum ArkUI_CancelButtonStyle
```
**Description**

Enumerates the styles of the Cancel button.

**Since**: 12

| Value| Description|
| -------- | -------- |
| ARKUI_CANCELBUTTON_STYLE_CONSTANT  | The Cancel button is always displayed.&nbsp;&nbsp; |
| ARKUI_CANCELBUTTON_STYLE_INVISIBLE  | The Cancel button is always hidden.&nbsp;&nbsp; |
| ARKUI_CANCELBUTTON_STYLE_INPUT  | The Cancel button is displayed when there is text input.&nbsp;&nbsp; |


### ArkUI_CheckboxShape

```
enum ArkUI_CheckboxShape
```
**Description**

Enumerates the shapes of the check box.

**Since**: 12

| Value| Description|
| -------- | -------- |
| ArkUI_CHECKBOX_SHAPE_CIRCLE  | Circle.&nbsp;&nbsp; |
| ArkUI_CHECKBOX_SHAPE_ROUNDED_SQUARE  | Rounded square.&nbsp;&nbsp; |


### ArkUI_ClipType

```
enum ArkUI_ClipType
```
**Description**

Enumerates the clipping region types.

**Since**: 12

| Value| Description|
| -------- | -------- |
| ARKUI_CLIP_TYPE_RECTANGLE  | Rectangle.&nbsp;&nbsp; |
| ARKUI_CLIP_TYPE_CIRCLE  | Circle.&nbsp;&nbsp; |
| ARKUI_CLIP_TYPE_ELLIPSE  | Ellipse.&nbsp;&nbsp; |
| ARKUI_CLIP_TYPE_PATH  | Path Type&nbsp;&nbsp; |


### ArkUI_ColorMode

```
enum ArkUI_ColorMode
```
**Description**

Enumerates the color modes.

**Since**: 12

| Value| Description|
| -------- | -------- |
| ARKUI_COLOR_MODE_SYSTEM  | Following the system color mode.&nbsp;&nbsp; |
| ARKUI_COLOR_MODE_LIGHT  | Light color mode.&nbsp;&nbsp; |
| ARKUI_COLOR_MODE_DARK  | Dark color mode.&nbsp;&nbsp; |


### ArkUI_ColorStrategy

```
enum ArkUI_ColorStrategy
```
**Description**

Enumerates the foreground colors.

**Since**: 12

| Value| Description|
| -------- | -------- |
| ARKUI_COLOR_STRATEGY_INVERT  | The foreground colors are the inverse of the component background colors.&nbsp;&nbsp; |
| ARKUI_COLOR_STRATEGY_AVERAGE  | The shadow colors of the component are the average color obtained from the component background shadow area.&nbsp;&nbsp; |
| ARKUI_COLOR_STRATEGY_PRIMARY  | The shadow colors of the component are the primary color obtained from the component background shadow area.&nbsp;&nbsp; |


### ArkUI_CopyOptions

```
enum ArkUI_CopyOptions
```
**Description**

Enumerates the text copy and paste modes.

**Since**: 12

| Value| Description|
| -------- | -------- |
| ARKUI_COPY_OPTIONS_NONE  | Copy is not allowed.&nbsp;&nbsp; |
| ARKUI_COPY_OPTIONS_IN_APP  | Intra-application copy is allowed.&nbsp;&nbsp; |
| ARKUI_COPY_OPTIONS_LOCAL_DEVICE  | Intra-device copy is allowed.&nbsp;&nbsp; |
| ARKUI_COPY_OPTIONS_CROSS_DEVICE  | Cross-device copy is allowed.&nbsp;&nbsp; |


### ArkUI_Direction

```
enum ArkUI_Direction
```
**Description**

Enumerates the modes in which components are laid out along the main axis of the container.

**Since**: 12

| Value| Description|
| -------- | -------- |
| ARKUI_DIRECTION_LTR  | Components are arranged from left to right.&nbsp;&nbsp; |
| ARKUI_DIRECTION_RTL  | Components are arranged from right to left.&nbsp;&nbsp; |
| ARKUI_DIRECTION_AUTO  | The default layout direction is used.&nbsp;&nbsp; |


### ArkUI_DismissReason

```
enum ArkUI_DismissReason
```
**Description**

Enumerates the actions for triggering closure of the dialog box.

**Since**: 12

| Value| Description|
| -------- | -------- |
| DIALOG_DISMISS_BACK_PRESS  | Touching the system-defined Back button or pressing the Esc key.&nbsp;&nbsp; |
| DIALOG_DISMISS_TOUCH_OUTSIDE  | Touching the mask.&nbsp;&nbsp; |


### ArkUI_EdgeEffect

```
enum ArkUI_EdgeEffect
```
**Description**

Enumerates the effects used at the edges of the component when the boundary of the scrollable content is reached.

**Since**: 12

| Value| Description|
| -------- | -------- |
| ARKUI_EDGE_EFFECT_SPRING  | Spring effect. When at one of the edges, the component can move beyond the bounds through touches, and produces a bounce effect when the user releases their finger.&nbsp;&nbsp; |
| ARKUI_EDGE_EFFECT_FADE  | Fade effect. When at one of the edges, the component produces a fade effect.&nbsp;&nbsp; |
| ARKUI_EDGE_EFFECT_NONE  | No effect when the component is at one of the edges.&nbsp;&nbsp; |


### ArkUI_EllipsisMode

```
enum ArkUI_EllipsisMode
```
**Description**

Enumerates the ellipsis positions.

**Since**: 12

| Value| Description|
| -------- | -------- |
| ARKUI_ELLIPSIS_MODE_START  | An ellipsis is used at the start of the line of text.&nbsp;&nbsp; |
| ARKUI_ELLIPSIS_MODE_CENTER  | An ellipsis is used at the center of the line of text.&nbsp;&nbsp; |
| ARKUI_ELLIPSIS_MODE_END  | An ellipsis is used at the end of the line of text.&nbsp;&nbsp; |


### ArkUI_EnterKeyType

```
enum ArkUI_EnterKeyType
```
**Description**

Enumerates the types of the Enter key for a single-line text box.

**Since**: 12

| Value| Description|
| -------- | -------- |
| ARKUI_ENTER_KEY_TYPE_GO  | The Enter key is labeled "Go."&nbsp;&nbsp; |
| ARKUI_ENTER_KEY_TYPE_SEARCH  | The Enter key is labeled "Search."&nbsp;&nbsp; |
| ARKUI_ENTER_KEY_TYPE_SEND  | The Enter key is labeled "Send."&nbsp;&nbsp; |
| ARKUI_ENTER_KEY_TYPE_NEXT  | The Enter key is labeled "Next."&nbsp;&nbsp; |
| ARKUI_ENTER_KEY_TYPE_DONE  | The Enter key is labeled "Done."&nbsp;&nbsp; |
| ARKUI_ENTER_KEY_TYPE_PREVIOUS  | The Enter key is labeled "Previous."&nbsp;&nbsp; |
| ARKUI_ENTER_KEY_TYPE_NEW_LINE  | The Enter key is labeled "Return."&nbsp;&nbsp; |


### ArkUI_FinishCallbackType

```
enum ArkUI_FinishCallbackType
```
**Description**

Type of the **onFinish** callback.

**Since**: 12

| Value| Description|
| -------- | -------- |
| ARKUI_FINISH_CALLBACK_REMOVED  | The callback is invoked when the entire animation is removed once it has finished.&nbsp;&nbsp; |
| ARKUI_FINISH_CALLBACK_LOGICALLY  | The callback is invoked when the animation logically enters the falling state, though it may still be in its long tail state.&nbsp;&nbsp; |


### ArkUI_FlexAlignment

```
enum ArkUI_FlexAlignment
```
**Description**

Enumerates the vertical alignment modes.

**Since**: 12

| Value| Description|
| -------- | -------- |
| ARKUI_FLEX_ALIGNMENT_START  | The child components are aligned with the start edge of the main axis.&nbsp;&nbsp; |
| ARKUI_FLEX_ALIGNMENT_CENTER  | The child components are aligned in the center of the main axis.&nbsp;&nbsp; |
| ARKUI_FLEX_ALIGNMENT_END  | The child components are aligned with the end edge of the main axis.&nbsp;&nbsp; |
| ARKUI_FLEX_ALIGNMENT_SPACE_BETWEEN  | The child components are evenly distributed along the main axis. The space between any two adjacent components is the same. The first component is aligned with the main-start, and the last component is aligned with the main-end.&nbsp;&nbsp; |
| ARKUI_FLEX_ALIGNMENT_SPACE_AROUND  | The child components are evenly distributed along the main axis. The space between any two adjacent components is the same. The space between the first component and main-start, and that between the last component and cross-main are both half the size of the space between two adjacent components.&nbsp;&nbsp; |
| ARKUI_FLEX_ALIGNMENT_SPACE_EVENLY  | The child components are evenly distributed along the main axis. The space between the first component and main-start, the space between the last component and main-end, and the space between any two adjacent components are the same.&nbsp;&nbsp; |


### ArkUI_FlexDirection

```
enum ArkUI_FlexDirection
```
**Description**

Enumerates the directions of the main axis in the flex container.

**Since**: 12

| Value| Description|
| -------- | -------- |
| ARKUI_FLEX_DIRECTION_ROW  | The child components are arranged in the same direction as the main axis runs along the rows.&nbsp;&nbsp; |
| ARKUI_FLEX_DIRECTION_COLUMN  | The child components are arranged in the same direction as the main axis runs down the columns.&nbsp;&nbsp; |
| ARKUI_FLEX_DIRECTION_ROW_REVERSE  | The child components are arranged opposite to the **ROW** direction.&nbsp;&nbsp; |
| ARKUI_FLEX_DIRECTION_COLUMN_REVERSE  | The child components are arranged opposite to the **COLUMN** direction.&nbsp;&nbsp; |


### ArkUI_FlexWrap

```
enum ArkUI_FlexWrap
```
**Description**

Defines whether the flex container has a single line or multiple lines.

**Since**: 12

| Value| Description|
| -------- | -------- |
| ARKUI_FLEX_WRAP_NO_WRAP  | The child components in the flex container are arranged in a single line, and they cannot overflow.&nbsp;&nbsp; |
| ARKUI_FLEX_WRAP_WRAP  | The child components in the flex container are arranged in multiple lines, and they may overflow.&nbsp;&nbsp; |
| ARKUI_FLEX_WRAP_WRAP_REVERSE  | The child components in the flex container are reversely arranged in multiple lines, and they may overflow.&nbsp;&nbsp; |


### ArkUI_FontStyle

```
enum ArkUI_FontStyle
```
**Description**

Enumerates the font styles.

**Since**: 12

| Value| Description|
| -------- | -------- |
| ARKUI_FONT_STYLE_NORMAL  | Standard font style.&nbsp;&nbsp; |
| ARKUI_FONT_STYLE_ITALIC  | Italic font style.&nbsp;&nbsp; |


### ArkUI_FontWeight

```
enum ArkUI_FontWeight
```
**Description**

Enumerates the font weights.

**Since**: 12

| Value| Description|
| -------- | -------- |
| ARKUI_FONT_WEIGHT_W100  | 100&nbsp;&nbsp; |
| ARKUI_FONT_WEIGHT_W200  | 200&nbsp;&nbsp; |
| ARKUI_FONT_WEIGHT_W300  | 300&nbsp;&nbsp; |
| ARKUI_FONT_WEIGHT_W400  | 400&nbsp;&nbsp; |
| ARKUI_FONT_WEIGHT_W500  | 500&nbsp;&nbsp; |
| ARKUI_FONT_WEIGHT_W600  | 600&nbsp;&nbsp; |
| ARKUI_FONT_WEIGHT_W700  | 700&nbsp;&nbsp; |
| ARKUI_FONT_WEIGHT_W800  | 800&nbsp;&nbsp; |
| ARKUI_FONT_WEIGHT_W900  | 900&nbsp;&nbsp; |
| ARKUI_FONT_WEIGHT_BOLD  | The font weight is bold.&nbsp;&nbsp; |
| ARKUI_FONT_WEIGHT_NORMAL  | The font thickness is normal. &nbsp;&nbsp;|
| ARKUI_FONT_WEIGHT_BOLDER  | The font weight is bolder.&nbsp;&nbsp; |
| ARKUI_FONT_WEIGHT_LIGHTER  | The font weight is lighter.&nbsp;&nbsp; |
| ARKUI_FONT_WEIGHT_MEDIUM  | The font weight is medium.&nbsp;&nbsp; |
| ARKUI_FONT_WEIGHT_REGULAR  | The font thickness is normal. &nbsp;&nbsp;|


### ArkUI_GestureDirection

```
enum ArkUI_GestureDirection
```
**Description**

Enumerates gesture directions.

**Since**: 12

| Value| Description|
| -------- | -------- |
| GESTURE_DIRECTION_ALL  | All directions.&nbsp;&nbsp; |
| GESTURE_DIRECTION_HORIZONTAL  | Horizontal direction.&nbsp;&nbsp; |
| GESTURE_DIRECTION_VERTICAL  | Vertical direction.&nbsp;&nbsp; |
| GESTURE_DIRECTION_LEFT  | Leftward.&nbsp;&nbsp; |
| GESTURE_DIRECTION_RIGHT  | Rightward.&nbsp;&nbsp; |
| GESTURE_DIRECTION_UP  | Upward.&nbsp;&nbsp; |
| GESTURE_DIRECTION_DOWN  | Downward.&nbsp;&nbsp; |
| GESTURE_DIRECTION_NONE  | None.&nbsp;&nbsp; |


### ArkUI_GestureEventActionType

```
enum ArkUI_GestureEventActionType
```
**Description**

Enumerates gesture event types.

**Since**: 12

| Value| Description|
| -------- | -------- |
| GESTURE_EVENT_ACTION_ACCEPT  | Triggered.&nbsp;&nbsp; |
| GESTURE_EVENT_ACTION_UPDATE  | Updated.&nbsp;&nbsp; |
| GESTURE_EVENT_ACTION_END  | Ended.&nbsp;&nbsp; |
| GESTURE_EVENT_ACTION_CANCEL  | Canceled.&nbsp;&nbsp; |


### ArkUI_GestureInterruptResult

```
enum ArkUI_GestureInterruptResult
```
**Description**

Enumerates gesture interruption results.

**Since**: 12

| Value| Description|
| -------- | -------- |
| GESTURE_INTERRUPT_RESULT_CONTINUE  | The gesture recognition process continues.&nbsp;&nbsp; |
| GESTURE_INTERRUPT_RESULT_REJECT  | The gesture recognition process is paused.&nbsp;&nbsp; |


### ArkUI_GestureMask

```
enum ArkUI_GestureMask
```
**Description**

Enumerates gesture masking modes.

**Since**: 12

| Value| Description|
| -------- | -------- |
| NORMAL_GESTURE_MASK  | The gestures of child components are not masked and are recognized based on the default gesture recognition sequence.&nbsp;&nbsp; |
| IGNORE_INTERNAL_GESTURE_MASK  | The gestures of child components are disabled, including the built-in gestures.&nbsp;&nbsp; |


### ArkUI_GesturePriority

```
enum ArkUI_GesturePriority
```
**Description**

Enumerates gesture event modes.

**Since**: 12

| Value| Description|
| -------- | -------- |
| NORMAL  | Normal.&nbsp;&nbsp; |
| PRIORITY  | High-priority.&nbsp;&nbsp; |
| PARALLEL  | Parallel.&nbsp;&nbsp; |


### ArkUI_GestureRecognizerType

```
enum ArkUI_GestureRecognizerType
```
**Description**

Enumerates gesture types.

**Since**: 12

| Value| Description|
| -------- | -------- |
| TAP_GESTURE  | Tap.&nbsp;&nbsp; |
| LONG_PRESS_GESTURE  | Long press gesture.&nbsp;&nbsp; |
| PAN_GESTURE  | Pan gesture.&nbsp;&nbsp; |
| PINCH_GESTURE  | Pinch gesture.&nbsp;&nbsp; |
| ROTATION_GESTURE  | Rotation gesture.&nbsp;&nbsp; |
| SWIPE_GESTURE  | Swipe gesture.&nbsp;&nbsp; |
| GROUP_GESTURE  | A group of gestures.&nbsp;&nbsp; |


### ArkUI_GroupGestureMode

```
enum ArkUI_GroupGestureMode
```
**Description**

Enumerates gesture group modes.

**Since**: 12

| Value| Description|
| -------- | -------- |
| PARALLEL_GROUP  | Parallel recognition. Registered gestures are recognized concurrently until all gestures are recognized. The recognition result of each gesture does not affect each other.&nbsp;&nbsp; |
| EXCLUSIVE_GROUP  | Exclusive recognition. Registered gestures are identified concurrently. If one gesture is successfully recognized, gesture recognition ends.&nbsp;&nbsp; |


### ArkUI_HitTestMode

```
enum ArkUI_HitTestMode
```
**Description**

Enumerates the hit test modes.

**Since**: 12

| Value| Description|
| -------- | -------- |
| ARKUI_HIT_TEST_MODE_DEFAULT  | Both the node and its child node respond to the hit test of a touch event, but its sibling node is blocked from the hit test.&nbsp;&nbsp; |
| ARKUI_HIT_TEST_MODE_BLOCK  | The node responds to the hit test of a touch event, but its child node and sibling node are blocked from the hit test.&nbsp;&nbsp; |
| ARKUI_HIT_TEST_MODE_TRANSPARENT  | Both the node and its child node respond to the hit test of a touch event, and its sibling node is also considered during the hit test.&nbsp;&nbsp; |
| ARKUI_HIT_TEST_MODE_NONE  | The node does not respond to the hit test of a touch event.&nbsp;&nbsp; |


### ArkUI_HorizontalAlignment

```
enum ArkUI_HorizontalAlignment
```
**Description**

Enumerates the alignment mode in the horizontal direction.

**Since**: 12

| Value| Description|
| -------- | -------- |
| ARKUI_HORIZONTAL_ALIGNMENT_START  | Aligned with the start edge in the same direction as the language in use.&nbsp;&nbsp; |
| ARKUI_HORIZONTAL_ALIGNMENT_CENTER  | Aligned with the center. This is the default alignment mode.&nbsp;&nbsp; |
| ARKUI_HORIZONTAL_ALIGNMENT_END  | Aligned with the end edge in the same direction as the language in use.&nbsp;&nbsp; |


### ArkUI_ImageInterpolation

```
enum ArkUI_ImageInterpolation
```
**Description**

Enumerates the image interpolation effects.

**Since**: 12

| Value| Description|
| -------- | -------- |
| ARKUI_IMAGE_INTERPOLATION_NONE  | No image interpolation.&nbsp;&nbsp; |
| ARKUI_IMAGE_INTERPOLATION_LOW  | Low quality interpolation.&nbsp;&nbsp; |
| ARKUI_IMAGE_INTERPOLATION_MEDIUM  | Medium quality interpolation.&nbsp;&nbsp; |
| ARKUI_IMAGE_INTERPOLATION_HIGH  | High quality interpolation. This mode produces scaled images of the highest possible quality.&nbsp;&nbsp; |


### ArkUI_ImageRenderMode

```
enum ArkUI_ImageRenderMode
```
**Description**

Enumerates the image rendering modes.

**Since**: 12

| Value| Description|
| -------- | -------- |
| ARKUI_IMAGE_RENDER_MODE_ORIGINAL  | Render image pixels as they are in the original source image.&nbsp;&nbsp; |
| ARKUI_IMAGE_RENDER_MODE_TEMPLATE  | Render image pixels to create a monochrome template image.&nbsp;&nbsp; |


### ArkUI_ImageRepeat

```
enum ArkUI_ImageRepeat
```
**Description**

Enumerates the image repeat patterns.

**Since**: 12

| Value| Description|
| -------- | -------- |
| ARKUI_IMAGE_REPEAT_NONE  | The image is not repeatedly drawn.&nbsp;&nbsp; |
| ARKUI_IMAGE_REPEAT_X  | The image is repeatedly drawn only along the x-axis.&nbsp;&nbsp; |
| ARKUI_IMAGE_REPEAT_Y  | The image is repeatedly drawn only along the y-axis.&nbsp;&nbsp; |
| ARKUI_IMAGE_REPEAT_XY  | The image is repeatedly drawn along both axes.&nbsp;&nbsp; |

### ArkUI_ImageSize

```
enum ArkUI_ImageSize
```
**Description**

Defines the image size.

**Since**: 12

| Value| Description|
| -------- | -------- |
| ARKUI_IMAGE_SIZE_AUTO  | The original image aspect ratio is retained.&nbsp;&nbsp; |
| ARKUI_IMAGE_SIZE_COVER  | Default value. The image is scaled with its aspect ratio retained for both sides to be greater than or equal to the display boundaries.&nbsp;&nbsp; |
| ARKUI_IMAGE_SIZE_CONTAIN  | The image is scaled with its aspect ratio retained for the content to be completely displayed within the display boundaries.&nbsp;&nbsp; |


### ArkUI_ImageSpanAlignment

```
enum ArkUI_ImageSpanAlignment
```
**Description**

Enumerates the alignment mode of the image with the text.

**Since**: 12

| Value| Description|
| -------- | -------- |
| ARKUI_IMAGE_SPAN_ALIGNMENT_BASELINE  | The image is bottom aligned with the text baseline.&nbsp;&nbsp; |
| ARKUI_IMAGE_SPAN_ALIGNMENT_BOTTOM  | The image is bottom aligned with the text.&nbsp;&nbsp; |
| ARKUI_IMAGE_SPAN_ALIGNMENT_CENTER  | The image is centered aligned with the text.&nbsp;&nbsp; |
| ARKUI_IMAGE_SPAN_ALIGNMENT_TOP  | The image is top aligned with the text.&nbsp;&nbsp; |


### ArkUI_ItemAlignment

```
enum ArkUI_ItemAlignment
```
**Description**

Enumerates the modes in which components are laid out along the cross axis of the container.

**Since**: 12

| Value| Description|
| -------- | -------- |
| ARKUI_ITEM_ALIGNMENT_AUTO  | The default configuration of the flex container is used.&nbsp;&nbsp; |
| ARKUI_ITEM_ALIGNMENT_START  | The items in the flex container are aligned with the cross-start edge.&nbsp;&nbsp; |
| ARKUI_ITEM_ALIGNMENT_CENTER  | The items in the flex container are centered along the cross axis.&nbsp;&nbsp; |
| ARKUI_ITEM_ALIGNMENT_END  | The items in the flex container are aligned with the cross-end edge.&nbsp;&nbsp; |
| ARKUI_ITEM_ALIGNMENT_STRETCH  | The items in the flex container are stretched and padded along the cross axis.&nbsp;&nbsp; |
| ARKUI_ITEM_ALIGNMENT_BASELINE  | The items in the flex container are aligned in such a manner that their text baselines are aligned along the cross axis.&nbsp;&nbsp; |


### ArkUI_LengthMetricUnit

```
enum ArkUI_LengthMetricUnit
```
**Description**

Enumerates the component units.

**Since**: 12

| Value| Description|
| -------- | -------- |
| ARKUI_LENGTH_METRIC_UNIT_DEFAULT  | Default, which is fp for fonts and vp for non-fonts.&nbsp;&nbsp; |
| ARKUI_LENGTH_METRIC_UNIT_PX  | px.&nbsp;&nbsp; |
| ARKUI_LENGTH_METRIC_UNIT_VP  | vp.&nbsp;&nbsp; |
| ARKUI_LENGTH_METRIC_UNIT_FP  | fp.&nbsp;&nbsp; |


### ArkUI_LinearGradientDirection

```
enum ArkUI_LinearGradientDirection
```
**Description**

Enumerates the gradient directions.

**Since**: 12

| Value| Description|
| -------- | -------- |
| ARKUI_LINEAR_GRADIENT_DIRECTION_LEFT  | From right to left.&nbsp;&nbsp; |
| ARKUI_LINEAR_GRADIENT_DIRECTION_TOP  | From bottom to top.&nbsp;&nbsp; |
| ARKUI_LINEAR_GRADIENT_DIRECTION_RIGHT  | From left to right.&nbsp;&nbsp; |
| ARKUI_LINEAR_GRADIENT_DIRECTION_BOTTOM  | From top to bottom.&nbsp;&nbsp; |
| ARKUI_LINEAR_GRADIENT_DIRECTION_LEFT_TOP  | From lower right to upper left.&nbsp;&nbsp; |
| ARKUI_LINEAR_GRADIENT_DIRECTION_LEFT_BOTTOM  | From upper right to lower left.&nbsp;&nbsp; |
| ARKUI_LINEAR_GRADIENT_DIRECTION_RIGHT_TOP  | From lower left to upper right.&nbsp;&nbsp; |
| ARKUI_LINEAR_GRADIENT_DIRECTION_RIGHT_BOTTOM  | From upper left to lower right.&nbsp;&nbsp; |
| ARKUI_LINEAR_GRADIENT_DIRECTION_NONE  | No gradient.&nbsp;&nbsp; |
| ARKUI_LINEAR_GRADIENT_DIRECTION_CUSTOM  | User-defined gradient direction.&nbsp;&nbsp;|


### ArkUI_ListItemAlignment

```
enum ArkUI_ListItemAlignment
```
**Description**

Alignment mode of list items along the cross axis.

**Since**: 12

| Value| Description|
| -------- | -------- |
| ARKUI_LIST_ITEM_ALIGNMENT_START  | The list items are packed toward the start edge of the **\<List>** component along the cross axis.&nbsp;&nbsp; |
| ARKUI_LIST_ITEM_ALIGNMENT_CENTER  | The list items are centered in the **\<List>** component along the cross axis.&nbsp;&nbsp; |
| ARKUI_LIST_ITEM_ALIGNMENT_END  | The list items are packed toward the end edge of the **\<List>** component along the cross axis.&nbsp;&nbsp; |


### ArkUI_MaskType

```
enum ArkUI_MaskType
```
**Description**

Enumerates the mask types.

**Since**: 12

| Value| Description|
| -------- | -------- |
| ARKUI_MASK_TYPE_RECTANGLE  | Rectangle.&nbsp;&nbsp; |
| ARKUI_MASK_TYPE_CIRCLE  | Circle.&nbsp;&nbsp; |
| ARKUI_MASK_TYPE_ELLIPSE  | Ellipse.&nbsp;&nbsp; |
| ARKUI_MASK_TYPE_PATH  | Path Type&nbsp;&nbsp; |
| ARKUI_MASK_TYPE_PROGRESS  | Progress indicator.&nbsp;&nbsp; |


### ArkUI_NativeAPIVariantKind

```
enum ArkUI_NativeAPIVariantKind
```
**Description**

Defines the native API types.

**Since**: 12

| Value| Description|
| -------- | -------- |
| ARKUI_NATIVE_NODE  | API related to UI components. For details, see the struct definition in <arkui/native_node.h>.&nbsp;&nbsp; |
| ARKUI_NATIVE_DIALOG  | API related to dialog boxes. For details, see the struct definition in <arkui/native_dialog.h>.&nbsp;&nbsp; |
| ARKUI_NATIVE_GESTURE  | API related to gestures. For details, see the struct definition in <arkui/native_gesture.h>.&nbsp;&nbsp; |
| ARKUI_NATIVE_ANIMATE  | API related to animations. For details, see the struct definition in <arkui/native_animate.h>.&nbsp;&nbsp; |


### ArkUI_NodeAdapterEventType

```
enum ArkUI_NodeAdapterEventType
```
**Description**

Enumerates node adapter events.

**Since**: 12

| Value| Description|
| -------- | -------- |
| NODE_ADAPTER_EVENT_WILL_ATTACH_TO_NODE  | This event occurs when the component is attached to the adapter.&nbsp;&nbsp; |
| NODE_ADAPTER_EVENT_WILL_DETACH_FROM_NODE  | This event occurs when the component is detached from the adapter.&nbsp;&nbsp; |
| NODE_ADAPTER_EVENT_ON_GET_NODE_ID  | This event occurs when the adapter obtains the unique ID of the new element to add.&nbsp;&nbsp; |
| NODE_ADAPTER_EVENT_ON_ADD_NODE_TO_ADAPTER  | This event occurs when the adapter obtains the content of the new element to add.&nbsp;&nbsp; |
| NODE_ADAPTER_EVENT_ON_REMOVE_NODE_FROM_ADAPTER  | This event occurs when the adapter removes an element.&nbsp;&nbsp; |

### ArkUI_NodeAttributeType

```
enum ArkUI_NodeAttributeType
```
**Description**

Defines the ArkUI style attributes that can be set on the native side.

**Since**: 12

| Value                                       | Description                                                  |
| ------------------------------------------- | ------------------------------------------------------------ |
| NODE_WIDTH                                  | Defines the width attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: width, in vp.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: width, in vp. |
| NODE_HEIGHT                                 | Defines the height attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: height, in vp.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: height, in vp. |
| NODE_BACKGROUND_COLOR                       | Defines the background color attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].u32: background color, in 0xARGB format. For example, 0xFFFF0000 indicates red.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].u32: background color, in 0xARGB format. For example, 0xFFFF0000 indicates red. |
| NODE_BACKGROUND_IMAGE                       | Defines the background image attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.string: image address.<br>.value[0]?.i32: whether to repeat the image. Optional. The parameter type is [ArkUI_ImageRepeat](#arkui_imagerepeat). The default value is **ARKUI_IMAGE_REPEAT_NONE**.<br>.object: **PixelMap** object. The parameter type is **ArkUI_DrawableDesciptor**.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string: image address.<br>.value[0].i32: whether to repeat the image. The parameter type is [ArkUI_ImageRepeat](#arkui_imagerepeat).<br>.object: **PixelMap** object. The parameter type is **ArkUI_DrawableDesciptor**. Either **.object** or **.string** must be set. |
| NODE_PADDING                                | Defines the padding attribute, which can be set, reset, and obtained as required through APIs.<br>There are two formats of [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) for setting the attribute value:<br>1: Specify the same padding for the four directions.<br>.value[0].f32: padding, in vp.<br>2: Specify different paddings for different directions.<br>.value[0].f32: top padding, in vp.<br>.value[1].f32: right padding, in vp.<br>.value[2].f32: bottom padding, in vp.<br>.value[3].f32: left padding, in vp.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: top padding, in vp.<br>.value[1].f32: right padding, in vp.<br>.value[2].f32: bottom padding, in vp.<br>.value[3].f32: left padding, in vp. |
| NODE_ID                                     | Defines the component ID attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.string: component ID.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string: component ID. |
| NODE_ENABLED                                | Defines the interactivity attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: The value **true** means that the component can interact with users, and **false** means the opposite.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: The value **1** means that the component can interact with users, and **0** means the opposite. |
| NODE_MARGIN                                 | Defines the margin attribute, which can be set, reset, and obtained as required through APIs.<br>There are two formats of [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) for setting the attribute value:<br>1: Specify the same margin for the four directions.<br>.value[0].f32: margin, in vp.<br>2: Specify different margins for different directions.<br>.value[0].f32: top margin, in vp.<br>.value[1].f32: right margin, in vp.<br>.value[2].f32: bottom margin, in vp.<br>.value[3].f32: left margin, in vp.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: top margin, in vp.<br>.value[1].f32: right margin, in vp.<br>.value[2].f32: bottom margin, in vp.<br>.value[3].f32: left margin, in vp. |
| NODE_TRANSLATE                              | Defines the translate attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: distance to translate along the x-axis, in vp. The default value is **0**.<br>.value[1].f32: distance to translate along the y-axis, in vp. The default value is **0**.<br>.value[2].f32: distance to translate along the z-axis, in vp. The default value is **0**.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: distance to translate along the x-axis, in vp.<br>.value[1].f32: distance to translate along the y-axis, in vp.<br>.value[2].f32: distance to translate along the z-axis, in vp. |
| NODE_SCALE                                  | Defines the scale attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: scale factor along the x-axis. The default value is **1**.<br>.value[1].f32: scale factor along the y-axis. The default value is **1**.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: scale factor along the x-axis.<br>.value[1].f32: scale factor along the y-axis. |
| NODE_ROTATE                                 | Defines the rotate attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: X-coordinate of the rotation axis vector. The default value is **0**.<br>.value[1].f32: Y-coordinate of the rotation axis vector. The default value is **0**.<br>.value[2].f32: Z-coordinate of the rotation axis vector. The default value is **0**.<br>.value[3].f32: rotation angle. The default value is **0**.<br>.value[4].f32: line of sight, that is, the distance from the viewpoint to the z=0 plane, in vp. The default value is **0**.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: X-coordinate of the rotation axis vector.<br>.value[1].f32: Y-coordinate of the rotation axis vector.<br>.value[2].f32: Z-coordinate of the rotation axis vector.<br>.value[3].f32: rotation angle.<br>.value[4].f32: line of sight, that is, the distance from the viewpoint to the z=0 plane, in vp. |
| NODE_BRIGHTNESS                             | Sets the brightness attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: brightness value. The default value is **1.0**, and the recommended value range is [0, 2].<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: brightness value. |
| NODE_SATURATION                             | Sets the saturation attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: saturation value. The default value is **1.0**, and the recommended value range is [0, 50).<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: saturation value. |
| NODE_BLUR                                   | Sets the blur attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: blur radius. The larger the fuzzy radius, the more blurred the image. If the value is **0**, the image is not blurred. The unit is vp. The default value is **0.0**.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: blur radius. The larger the fuzzy radius, the more blurred the image. If the value is **0**, the image is not blurred. The unit is vp. |
| NODE_LINEAR_GRADIENT                        | Sets the gradient attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: start angle of the linear gradient. A positive value indicates a clockwise rotation from the origin, (0, 0). The default value is **180**.<br>.value[1].i32: direction of the linear gradient. It does not take effect when **angle** is set. The data type is [ArkUI_LinearGradientDirection](#arkui_lineargradientdirection)<br>*.value[2].i32: whether the colors are repeated. The default value is **false**.<br>.object: array of color stops, each of which consists of a color and its stop position. Invalid colors are automatically skipped. The parameter type is [ArkUI_ColorStop](_ark_u_i___color_stop.md).<br>**colors**: colors of the color stops.<br>**stops**: stop positions of the color stops.<br>**size**: number of colors.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: start angle of the linear gradient.<br>.value[1].i32: direction of the linear gradient. It does not take effect when **angle** is set.<br>.value[2].i32: whether the colors are repeated.<br>.object: array of color stops, each of which consists of a color and its stop position. Invalid colors are automatically skipped. The parameter type is [ArkUI_ColorStop](_ark_u_i___color_stop.md).<br>**colors**: colors of the color stops.<br>**stops**: stop positions of the color stops.<br>**size**: number of colors. |
| NODE_ALIGNMENT                              | Sets the alignment attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: alignment mode. The parameter type is [ArkUI_Alignment](#arkui_alignment). The default value is **ARKUI_ALIGNMENT_CENTER**.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: alignment mode. The parameter type is [ArkUI_Alignment](#arkui_alignment). |
| NODE_OPACITY                                | Defines the opacity attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: opacity value. The value ranges from 0 to 1.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: opacity value. The value ranges from 0 to 1. |
| NODE_BORDER_WIDTH                           | Defines the border width attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>1: .value[0].f32: width of the four borders.<br>2: .value[0].f32: width of the top border.<br>.value[1].f32: width of the right border.<br>.value[2].f32: width of the bottom border.<br>.value[3].f32: width of the left border.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: width of the top border.<br>.value[1].f32: width of the right border.<br>.value[2].f32: width of the bottom border.<br>.value[3].f32: width of the left border. |
| NODE_BORDER_RADIUS                          | Defines the border corner radius attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>1: .value[0].f32: radius of the four corners.<br>2: .value[0].f32: radius of the upper left corner.<br>.value[1].f32: radius of the upper right corner.<br>.value[2].f32: radius of the lower left corner.<br>.value[3].f32: radius of the lower right corner.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: radius of the upper left corner.<br>.value[1].f32: radius of the upper right corner.<br>.value[2].f32: radius of the lower left corner.<br>.value[3].f32: radius of the lower right corner. |
| NODE_BORDER_COLOR                           | Defines the border color attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>1: .value[0].u32: color of the four borders, in 0xARGB format, for example, **0xFFFF11FF**.<br>2: .value[0].u32: color of the top border, in 0xARGB format, for example, **0xFFFF11FF**.<br>.value[1].u32: color of the right border, in 0xARGB format, for example, **0xFFFF11FF**.<br>.value[2].u32: color of the lower border, in 0xARGB format, for example, **0xFFFF11FF**.<br>.value[3].u32: color of the left border, in 0xARGB format, for example, **0xFFFF11FF**.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].u32: color of the top border, in 0xARGB format, for example, **0xFFFF11FF**.<br>.value[1].u32: color of the right border, in 0xARGB format, for example, **0xFFFF11FF**.<br>.value[2].u32: color of the lower border, in 0xARGB format, for example, **0xFFFF11FF**.<br>.value[3].u32: color of the left border, in 0xARGB format, for example, **0xFFFF11FF**. |
| NODE_BORDER_STYLE                           | Defines the border line style attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>1: .value[0].i32: line style of the four borders. The parameter type is [ArkUI_BorderStyle](#arkui_borderstyle). The default value is **ARKUI_BORDER_STYLE_SOLID**.<br>2: .value[0].i32: line style of the top border. The parameter type is {@link ArkUI_BorderStyle}. The default value is **ARKUI_BORDER_STYLE_SOLID**.<br>.value[0].i32: line style of the right border. The parameter type is [ArkUI_BorderStyle](#arkui_borderstyle). The default value is **ARKUI_BORDER_STYLE_SOLID**.<br>.value[2].i32: line style of the bottom border. The parameter type is [ArkUI_BorderStyle](#arkui_borderstyle). The default value is **ARKUI_BORDER_STYLE_SOLID**.<br>.value[3].i32: line style of the left border. The parameter type is [ArkUI_BorderStyle](#arkui_borderstyle). The default value is **ARKUI_BORDER_STYLE_SOLID**.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: line style of the top border.<br>.value[1].i32: line style of the right border.<br>.value[2].i32: line style of the bottom border.<br>.value[3].i32: line style of the left border. |
| NODE_Z_INDEX                                | Defines the z-index attribute for the stack sequence. APIs are provided for setting, resetting, and obtaining the attribute value.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: z-index value.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: z-index value. |
| NODE_VISIBILITY                             | Defines the visibility attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: whether to show or hide the component. The parameter type is [ArkUI_BorderStyle](#arkui_borderstyle). The default value is **ARKUI_VISIBILITY_VISIBLE**.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: whether to show or hide the component. The parameter type is [ArkUI_BorderStyle](#arkui_borderstyle). The default value is **ARKUI_VISIBILITY_VISIBLE**. |
| NODE_CLIP                                   | Defines the clip attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: whether to clip the component based on the parent container bounds. The value **0** means to clip the component, and **1** means the opposite.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: whether to clip the component based on the parent container bounds. The value **0** means to clip the component, and **1** means the opposite. |
| NODE_CLIP_SHAPE                             | Defines the clipping region on the component. This attribute can be set and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute, which supports five types of shapes:<br>1. Rectangle:<br>.value[0].i32: type of shape. The parameter type is [ArkUI_ClipType](#arkui_cliptype). The value is **ARKUI_CLIP_TYPE_RECTANGLE** for the rectangle shape.<br>.value[1].f32: width of the rectangle.<br>.value[2].f32: height of the rectangle.<br>.value[3].f32: width of the rounded corner of the rectangle.<br>.value[4].f32: height of the rounded corner of the rectangle.<br>2. Circle:<br>.value[0].i32: type of shape. The parameter type is [ArkUI_ClipType](#arkui_cliptype). The value is **ARKUI_CLIP_TYPE_CIRCLE** for the circle shape.<br>.value[1].f32: width of the cicle.<br>.value[2].f32: height of the circle.<br>3. Ellipse:<br>.value[0].i32: type of shape. The parameter type is [ArkUI_ClipType](#arkui_cliptype). The value is **ARKUI_CLIP_TYPE_ELLIPSE** for the ellipse shape.<br>.value[1].f32: width of the ellipse.<br>.value[2].f32: height of the ellipse.<br>4. Path:<br>.value[0].i32: type of shape. The parameter type is [ArkUI_ClipType](#arkui_cliptype). The value is **ARKUI_CLIP_TYPE_PATH** for the path shape.<br>.value[1].f32: width of the path.<br>.value[2].f32: height of the path.<br>.string: command for drawing the path.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md), which supports five types of shapes:<br>1. Rectangle:<br>.value[0].i32: type of shape. The parameter type is [ArkUI_ClipType](#arkui_cliptype). The value is **ARKUI_CLIP_TYPE_RECTANGLE** for the rectangle shape.<br>.value[1].f32: width of the rectangle.<br>.value[2].f32: height of the rectangle.<br>.value[3].f32: width of the rounded corner of the rectangle.<br>.value[4].f32: height of the rounded corner of the rectangle.<br>2. Circle:<br>.value[0].i32: type of shape. The parameter type is [ArkUI_ClipType](#arkui_cliptype). The value is **ARKUI_CLIP_TYPE_CIRCLE** for the circle shape.<br>.value[1].f32: width of the cicle.<br>.value[2].f32: height of the circle.<br>3. Ellipse:<br>.value[0].i32: type of shape. The parameter type is [ArkUI_ClipType](#arkui_cliptype). The value is **ARKUI_CLIP_TYPE_ELLIPSE** for the ellipse shape.<br>.value[1].f32: width of the ellipse.<br>.value[2].f32: height of the ellipse.<br>4. Path:<br>.value[0].i32: type of shape. The parameter type is [ArkUI_ClipType](#arkui_cliptype). The value is **ARKUI_CLIP_TYPE_PATH** for the path shape.<br>.value[1].f32: width of the path.<br>.value[2].f32: height of the path.<br>.string: command for drawing the path. |
| NODE_TRANSFORM                              | Defines the transform attribute, which can be used to translate, rotate, and scale images. APIs are provided for setting, resetting, and obtaining the attribute value.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0...15].f32: 16 floating-point numbers.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0...15].f32: 16 floating-point numbers. |
| NODE_HIT_TEST_BEHAVIOR                      | Defines the hit test behavior attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: controls the touch test type of the current widget. The parameter type is [ArkUI_HitTestMode](#arkui_hittestmode). The default value is ARKUI_HIT_TEST_MODE_DEFAULT.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: hit test mode. The parameter type is **ArkKUI_HitTestMode**. The default value is **ARKUI_HIT_TEST_MODE_DEFAULT**. |
| NODE_POSITION                               | Defines the offset attribute, which specifies the offset of the component's upper left corner relative to the parent container's. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: X coordinate.<br>.value[1].f32: Y coordinate.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: X coordinate.<br>.value[1].f32: Y coordinate. |
| NODE_SHADOW                                 | Defines the shadow attribute. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: shadow effect of the current widget. The parameter type is [ArkUI_ShadowStyle](#arkui_shadowstyle).<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: shadow effect of the current widget. The parameter type is [ArkUI_ShadowStyle](#arkui_shadowstyle). |
| NODE_CUSTOM_SHADOW                          | Defines the custom shadow effect. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0]?.f32: blur radius of the shadow, in vp.<br>.value[1]? .i32: whether to enable the coloring strategy. The value **1** means to enable the coloring strategy, and **0** (default value) means the opposite.<br>.value[2]?.f32: offset of the shadow along the x-axis, in vp.<br>.value[3]?.f32: offset of the shadow along the y-axis, in vp.<br>.value[4]?.i32: shadow type [ArkUI_ShadowType](#arkui_shadowtype). The default value is **ARKUI_SHADOW_TYPE_COLOR**.<br>.value[5]?.u32: shadow color, in 0xARGB format. For example, 0xFFFF0000 indicates red.<br>.value[6]?.u32: whether to fill the shadow. The value 1 means to fill the shadow, and 0 means the opposite.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: blur radius of the shadow, in vp.<br>.value[1].i32: whether to enable the coloring strategy. <br>.value[2].f32: offset of the shadow along the x-axis, in vp.<br>.value[3].f32: offset of the shadow along the y-axis, in vp.<br>.value[4].i32: shadow type [ArkUI_ShadowType](#arkui_shadowtype). The default value is **ARKUI_SHADOW_TYPE_COLOR**.<br>.value[5].u32: shadow color, in 0xARGB format. For example, 0xFFFF0000 indicates red.<br>.value[6].u32: whether to fill the shadow. The value **1** means to fill the shadow, and **0** means the opposite. |
| NODE_BACKGROUND_IMAGE_SIZE                  | Defines the background image width and height. APIs are provided for setting, resetting, and obtaining the attribute value.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: width of the image. The value range is [0, +∞), and the unit is vp.<br>.value[1].f32: height of the image. The value range is [0, +∞), and the unit is vp.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: width of the image, in vp.<br>.value[1].f32: height of the image, in vp. |
| NODE_BACKGROUND_IMAGE_SIZE_WITH_STYLE       | Defines the background image size. APIs are provided for setting, resetting, and obtaining the attribute value.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32 indicates the width and height style of the background image. The enumerated values of [ArkUI_ImageSize](#arkui_imagesize) are used.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32 indicates the width and height style of the background image. The enumerated values of [ArkUI_ImageSize](#arkui_imagesize) are used. |
| NODE_BACKGROUND_BLUR_STYLE                  | Defines the background blur attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32 indicates the fuzzy type. The enumerated values of [ArkUI_BlurStyle](#arkui_blurstyle) are used.<br>.value[1]? .i32 indicates the deep and light color mode. The enumerated values of [ArkUI_ColorMode](#arkui_colormode) are used.<br>.value[2]? .i32 indicates the color obtaining mode. The enumerated values of [ArkUI_AdaptiveColor](#arkui_adaptivecolor) are used.<br>.value[3]? .f32: blur degree. The value range is [0.0, 1.0].<br>.value[4]? .f32: start boundary of grayscale blur.<br>.value[5]? .f32: end boundary of grayscale blur.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32 indicates the fuzzy type. The enumerated values of [ArkUI_BlurStyle](#arkui_blurstyle) are used.<br>.value[1].i32 indicates the deep and light color mode. The enumerated values of [ArkUI_ColorMode](#arkui_colormode) are used.<br>.value[2].i32 indicates the color obtaining mode. The enumerated values of [ArkUI_AdaptiveColor](#arkui_adaptivecolor) are used.<br>.value[3].f32: blur degree. The value range is [0.0, 1.0].<br>.value[4].f32: start boundary of grayscale blur.<br>.value[5].f32: end boundary of grayscale blur. |
| NODE_TRANSFORM_CENTER                       | Defines the transform center attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0]? .f32: X coordinate of the center point, in vp.<br>.value[1]? .f32: Y coordinate of the center point, in vp.<br>.value[2]? .f32: Z coordinate of the center point, in vp.<br>.value[3]? .f32 : X coordinate of the center point, expressed in a number that represents a percentage. For example, 0.2 indicates 20%. This attribute overwrites value[0].f32. The default value is 0.5f.<br>.value[4]? .f32 : Y coordinate of the center point, expressed in a number that represents a percentage. For example, 0.2 indicates 20%. This attribute overwrites value[1].f32. The default value is 0.5f.<br>.value[5]? .f32 : Z coordinate of the center point, expressed in a number that represents a percentage. For example, 0.2 indicates 20%. This attribute overwrites value[2].f32. The default value is 0.0f.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: X coordinate of the center point, in vp. <br>.value[1].f32: Y coordinate of the center point, in vp. <br>.value[2].f32: Z coordinate of the center point, in vp. <br>Note: If the coordinate is expressed in a number that represents a percentage, the attribute obtaining API returns the calculated value in vp. |
| NODE_OPACITY_TRANSITION                     | Defines the transition opacity attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: opacity values of the start and end points.<br>value[3].i32: animation duration, in milliseconds.<br>.value[2].i32 indicates the animation curve type. The enumerated values of [ArkUI_AnimationCurve](#arkui_animationcurve) are used.<br>value[5]?.i32: animation delay duration, in milliseconds.<br>value[6]?.i32: number of times that the animation is played.<br>.value[5]? .i32 indicates the animation playing mode. The enumerated values of [ArkUI_AnimationPlayMode](#arkui_animationplaymode) are used.<br>value[8]?.f32: animation playback speed.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: opacity values of the start and end points.<br>value[3].i32: animation duration, in milliseconds.<br>.value[2].i32 indicates the animation curve type. The enumerated values of [ArkUI_AnimationCurve](#arkui_animationcurve) are used.<br>value[5].i32: animation delay duration, in milliseconds.<br>value[6].i32: number of times that the animation is played.<br>.value[5].i32 indicates the animation playing mode. The enumerated values of [ArkUI_AnimationPlayMode](#arkui_animationplaymode) are used.<br>.value[6].f32: animation playback speed. |
| NODE_ROTATE_TRANSITION                      | Defines the transition rotation attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: X-component of the rotation vector.<br>.value[1].f32: Y-component of the rotation vector.<br>.value[2].f32: Z-component of the rotation vector<br>.value[3].f32: angle.<br>.value[4].f32: line of sight. The default value is 0.0f.<br>.value[5].i32: animation duration, in milliseconds.<br>.value[6].i32 indicates the animation curve type, which is the enumerated value of [ArkUI_AnimationCurve](#arkui_animationcurve).<br>.value[7]? .i32: animation delay duration, in milliseconds.<br>.value[8]? .i32: number of times that the animation is played.<br>.value[9]? .i32 indicates the animation playing mode. The enumerated values of [ArkUI_AnimationPlayMode](#arkui_animationplaymode) are used.<br>.value[10]? .f32: animation playback speed.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: X-component of the rotation vector.<br>.value[1].f32: Y-component of the rotation vector.<br>.value[2].f32: Z-component of the rotation vector<br>.value[3].f32: angle.<br>.value[4].f32: line of sight.<br>.value[5].i32: animation duration, in milliseconds.<br>.value[6].i32 indicates the animation curve type, which is the enumerated value of [ArkUI_AnimationCurve](#arkui_animationcurve).<br>.value[7].i32: animation delay duration, in milliseconds.<br>.value[8].i32: number of times that the animation is played.<br>.value[9].i32 indicates the animation playing mode. The enumerated values of [ArkUI_AnimationPlayMode](#arkui_animationplaymode) are used.<br>.value[10].f32: animation playback speed. |
| NODE_SCALE_TRANSITION                       | Defines the transition scaling attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: scale factor along the x-axis.<br>.value[1].f32: scale factor along the y-axis.<br>.value[2].f32: scale factor along the z-axis.<br>value[3].i32: animation duration, in milliseconds.<br>.value[4].i32 indicates the animation curve type, which is the enumerated value of [ArkUI_AnimationCurve](#arkui_animationcurve).<br>value[5]?.i32: animation delay duration, in milliseconds.<br>value[6]?.i32: number of times that the animation is played.<br>.value[7]? .i32 indicates the animation playing mode. The enumerated values of [ArkUI_AnimationPlayMode](#arkui_animationplaymode) are used.<br>value[8]?.f32: animation playback speed.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: scale factor along the x-axis.<br>.value[1].f32: scale factor along the y-axis.<br>.value[2].f32: scale factor along the z-axis.<br>value[3].i32: animation duration, in milliseconds.<br>.value[4].i32 indicates the animation curve type, which is the enumerated value of [ArkUI_AnimationCurve](#arkui_animationcurve).<br>value[5].i32: animation delay duration, in milliseconds.<br>value[6].i32: number of times that the animation is played.<br>.value[7].i32 indicates the animation playing mode. The enumerated values of [ArkUI_AnimationPlayMode](#arkui_animationplaymode) are used.<br>value[8].f32: animation playback speed. |
| NODE_TRANSLATE_TRANSITION                   | Defines the transition translation attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>value[0].f32: translation distance along the x-axis, in vp.<br>value[1].f32: translation distance along the y-axis, in vp.<br>value[2].f32: translation distance along the z-axis, in vp.<br>value[3].i32: animation duration, in milliseconds.<br>value[4].i32 indicates the animation curve type, which is the enumerated value of [ArkUI_AnimationCurve](#arkui_animationcurve).<br>value[5]?.i32: animation delay duration, in milliseconds.<br>value[6]?.i32: number of times that the animation is played.<br>value[7]? .i32 indicates the animation playing mode. The enumerated values of [ArkUI_AnimationPlayMode](#arkui_animationplaymode) are used.<br>value[8]?.f32: animation playback speed.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>value[0].f32: translation distance along the x-axis, in vp.<br>value[1].f32: translation distance along the y-axis, in vp.<br>value[2].f32: translation distance along the z-axis, in vp.<br>value[3].i32: animation duration, in milliseconds.<br>value[4].i32 indicates the animation curve type, which is the enumerated value of [ArkUI_AnimationCurve](#arkui_animationcurve).<br>value[5].i32: animation delay duration, in milliseconds.<br>value[6].i32: number of times that the animation is played.<br>value[7].i32 indicates the animation playing mode. The enumerated values of [ArkUI_AnimationPlayMode](#arkui_animationplaymode) are used.<br>value[8].f32: animation playback speed. |
| NODE_MOVE_TRANSITION                        | @brief Defines the slide-in and slide-out of the component from the screen edge during transition. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>value[0].i32 [ArkUI_TransitionEdge] (#arkui_transitionedge)<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>value[0].i32 [ArkUI_TransitionEdge] (#arkui_transitionedge) |
| NODE_FOCUSABLE                              | Defines the focus attribute, which can be set, reset, and obtained as required through APIs.<br>The parameter format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) method is as follows:<br>value[0].i32: The parameter type is 1 or 0.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>value[0].i32: The parameter type is 1 or 0. |
| NODE_DEFAULT_FOCUS                          | Defines the default focus attribute, which can be set, reset, and obtained as required through APIs.<br>The parameter format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) method is as follows:<br>value[0].i32: The parameter type is 1 or 0.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>value[0].i32: The parameter type is 1 or 0. |
| NODE_RESPONSE_REGION                        | Defines the touch target attribute, which can be set, reset, and obtained as required through APIs.<br>The parameter format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) method is as follows:<br>.data[0].f32: X coordinate of the touch point relative to the upper left corner of the component, in vp.<br>.data[1].f32: Y coordinate of the touch point relative to the upper left corner of the component, in vp.<br>.data[2].f32: width of the touch target, in %.<br>.data[3].f32: height of the touch target, in %.<br>.data[4...].f32: Multiple touch targets can be set. The sequence of the parameters is the same as the preceding.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.data[0].f32: X coordinate of the touch point relative to the upper left corner of the component, in vp.<br>.data[1].f32: Y coordinate of the touch point relative to the upper left corner of the component, in vp.<br>.data[2].f32: width of the touch target, in %.<br>.data[3].f32: height of the touch target, in %.<br>.data[4...].f32: Multiple touch targets can be set. The sequence of the parameters is the same as the preceding. |
| NODE_OVERLAY                                | Defines the overlay attribute, which can be set, reset, and obtained as required through APIs.<br>The parameter format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) method is as follows:<br>.string maskText;<br>.value[0]? .i32: (optional) position of the floating layer relative to the component. The parameter type is [ArkUI_Alignment](#arkui_alignment). The default value is ARKUI_ALIGNMENT_TOP_START.<br>.value[1]?.f32: offset of the overlay relative to the upper left corner of itself on the x-axis, in vp. Optional.<br>.value[2]? .f32: offset of the overlay relative to the upper left corner of itself on the y-axis, in vp. Optional.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string maskText;<br>.value[0].i32: position of the floating layer relative to the component. The parameter type is [ArkUI_Alignment](#arkui_alignment). The default value is ARKUI_ALIGNMENT_TOP_START.<br>*.value[1].f32: offset of the overlay relative to the upper left corner of itself on the x-axis, in vp.<br>.value[2].f32: offset of the overlay relative to the upper left corner of itself on the y-axis, in vp. |
| NODE_SWEEP_GRADIENT                         | Defines the sweep gradient effect. APIs are provided for setting, resetting, and obtaining the attribute value.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0]? .f32: X coordinate of the sweep gradient center relative to the upper left corner of the component.<br>.value[1]?.f32: Y coordinate of the sweep gradient center relative to the upper left corner of the component.<br>.value[2]?.f32: start point of the sweep gradient. The default value is 0.<br>.value[3]?.f32: end point of the sweep gradient. The default value is 0.<br>.value[4]?.f32: rotation angle of the sweep gradient. The default value is 0.<br>.value[5]?.i32: whether the colors are repeated. The value 1 means that the colors are repeated, and 0 means the opposite.<br>.object: The parameter type is [ArkUI_ColorStop](_ark_u_i___color_stop.md). - **colors**: array of color stops, each of which consists of a color and its stop position. Invalid colors are automatically skipped.<br>colors: colors of the color stops.<br>stops: stop positions of the color stops.<br>size: number of colors.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: X coordinate of the sweep gradient center relative to the upper left corner of the component. <br>.value[1].f32: Y coordinate of the sweep gradient center relative to the upper left corner of the component. <br>.value[2].f32: start point of the sweep gradient. The default value is 0.<br>.value[3].f32: end point of the sweep gradient. The default value is 0.<br>.value[4].f32: rotation angle of the sweep gradient. The default value is 0.<br>.value[5].i32: whether the colors are repeated. The value 1 means that the colors are repeated, and 0 means the opposite. <br>.object: The parameter type is [ArkUI_ColorStop](_ark_u_i___color_stop.md). - **colors**: array of color stops, each of which consists of a color and its stop position. Invalid colors are automatically skipped.<br>colors: colors of the color stops.<br>stops: stop positions of the color stops.<br>size: number of colors. |
| NODE_RADIAL_GRADIENT                        | Defines the radial gradient effect. APIs are provided for setting, resetting, and obtaining the attribute value.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0]? .f32: X coordinate of the radial gradient center relative to the upper left corner of the component.<br>.value[1]?.f32: Y coordinate of the radial gradient center relative to the upper left corner of the component.<br>.value[2]?.f32: radius of the radial gradient. The default value is 0.<br>.value[3]?.i32: whether the colors are repeated. The value 1 means that the colors are repeated, and 0 means the opposite.<br>.object: The parameter type is [ArkUI_ColorStop](_ark_u_i___color_stop.md). - **colors**: array of color stops, each of which consists of a color and its stop position. Invalid colors are automatically skipped.<br>colors: colors of the color stops.<br>stops: stop positions of the color stops.<br>size: number of colors.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: X coordinate of the radial gradient center relative to the upper left corner of the component. <br>.value[1].f32: Y coordinate of the radial gradient center relative to the upper left corner of the component. <br>.value[2].f32: radius of the radial gradient. The default value is 0.<br>.value[3].i32: whether the colors are repeated. The value 1 means that the colors are repeated, and 0 means the opposite. <br>.object: The parameter type is [ArkUI_ColorStop](_ark_u_i___color_stop.md). - **colors**: array of color stops, each of which consists of a color and its stop position. Invalid colors are automatically skipped.<br>colors: colors of the color stops.<br>stops: stop positions of the color stops.<br>size: number of colors. |
| NODE_MASK                                   | Adds a mask of the specified shape to the component. APIs are provided for setting and obtaining the attribute value.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute, which supports five types of shapes:<br>1. Rectangle:<br>.value[0].u32 fill color, in 0xARGB format.<br>.value[1].u32: stroke color, in 0xARGB format.<br>.value[2].f32: stroke width, in vp.<br>.value[3].i32: mask type. The parameter type is [ArkUI_MaskType](#arkui_masktype), ARKUI_MASK_TYPE_RECTANGLE.<br>.value[4].f32: rectangleWidth;<br>.value[5].f32: height of rectangle;<br>.value[6].f32: width of the rounded corner of the rectangle.<br>.value[7].f32: height of the rounded corner of the rectangle.<br>2. Circle:<br>.value[0].u32 fill color, in 0xARGB format.<br>.value[1].u32: stroke color, in 0xARGB format.<br>.value[2].f32: stroke width, in vp.<br>.value[3].i32: mask type. The parameter type is [ArkUI_MaskType](#arkui_masktype), ARKUI_MASK_TYPE_CIRCLE.<br>.value[4].f32: circleWidth;<br>.value[5].f32: height of circle;<br>3. Ellipse:<br>.value[0].u32 fill color, in 0xARGB format.<br>.value[1].u32: stroke color, in 0xARGB format.<br>.value[2].f32: stroke width, in vp.<br>.value[3].i32: mask type. The parameter type is [ArkUI_MaskType](#arkui_masktype), ARKUI_MASK_TYPE_ELLIPSE.<br>.value[4].f32: ellipse width;<br>.value[5].f32: height of ellipse;<br>4. Path:<br>.value[0].u32 fill color, in 0xARGB format.<br>.value[1].u32: stroke color, in 0xARGB format.<br>.value[2].f32: stroke width, in vp.<br>.value[3].i32: mask type. The parameter type is [ArkUI_MaskType](#arkui_masktype), ARKUI_MASK_TYPE_PATH.<br>.value[4].f32: pathwidth;<br>.value[5].f32: pathHeight;<br>.string: command for drawing the path.<br>4. Progress type:<br>.value[0].u32 fill color, in 0xARGB format.<br>.value[1].u32: stroke color, in 0xARGB format.<br>.value[2].f32: stroke width, in vp.<br>.value[3].i32: mask type. The parameter type is [ArkUI_MaskType](#arkui_masktype), ARKUI_MASK_TYPE_PROSGRESS.<br>.value[4].f32: current value of the progress indicator.<br>.value[5].f32: maximum value of the progress indicator.<br>.value[6].u32: color of the progress indicator.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md), which supports five types of shapes:<br>1. Rectangle:<br>.value[0].u32 fill color, in 0xARGB format.<br>.value[1].u32: stroke color, in 0xARGB format.<br>.value[2].f32: stroke width, in vp.<br>.value[3].i32: mask type;<br>.value[4].f32: rectangleWidth;<br>.value[5].f32: height of rectangle;<br>.value[6].f32: width of the rounded corner of the rectangle.<br>.value[7].f32: height of the rounded corner of the rectangle.<br>2. Circle:<br>.value[0].u32 fill color, in 0xARGB format.<br>.value[1].u32: stroke color, in 0xARGB format.<br>.value[2].f32: stroke width, in vp.<br>.value[3].i32: mask type;<br>.value[4].f32: circleWidth;<br>.value[5].f32: height of circle;<br>3. Ellipse:<br>.value[0].u32 fill color, in 0xARGB format.<br>.value[1].u32: stroke color, in 0xARGB format.<br>.value[2].f32: stroke width, in vp.<br>.value[3].i32: mask type;<br>.value[4].f32: ellipse width;<br>.value[5].f32: height of ellipse;<br>4. Path:<br>.value[0].u32 fill color, in 0xARGB format.<br>.value[1].u32: stroke color, in 0xARGB format.<br>.value[2].f32: stroke width, in vp.<br>.value[3].i32: mask type;<br>.value[4].f32: pathwidth;<br>.value[5].f32: pathHeight;<br>.string: command for drawing the path.<br>5. Progress type:<br>.value[0].i32: mask type;<br>.value[1].f32: current value of the progress indicator.<br>.value[2].f32: maximum value of the progress indicator.<br>.value[3].u32: color of the progress indicator. |
| NODE_BLEND_MODE                             | Blends the component's background with the content of the component's child node. APIs are provided for setting, resetting, and obtaining the attribute value.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: controls the mixed mode type of the current component. The parameter type is [ArkUI_BlendMode](#arkui_blendmode). The default value is ARKUI_BLEND_MODE_NONE.<br>.value[1].? i32: whether the blendMode implementation mode is off-screen. The parameter type is [ArkUI_BlendApplyType](#arkui_blendapplytype). The default value is ARKUI_BLEND_APPLY_TYPE_FAST.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: controls the mixed mode type of the current component. The parameter type is [ArkUI_BlendMode](#arkui_blendmode). The default value is ARKUI_BLEND_MODE_NONE.<br>.value[1].i32: indicates whether the blendMode implementation mode is off-screen. The parameter type is [ArkUI_BlendApplyType](#arkui_blendapplytype). The default value is ARKUI_BLEND_APPLY_TYPE_FAST. |
| NODE_DIRECTION                              | Sets the direction of the main axis. APIs are provided for setting, resetting, and obtaining the attribute value.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: direction of the main axis.<br>The parameter type is [ArkUI_Direction](#arkui_direction). The default value is ARKUI_DIRECTION_AUTO.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: direction of the main axis.<br>The parameter type is [ArkUI_Direction](#arkui_direction). The default value is ARKUI_DIRECTION_AUTO. |
| NODE_CONSTRAINT_SIZE                        | Defines the size constraints. APIs are provided for setting, resetting, and obtaining the attribute value.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: minimum width, in vp.<br>.value[1].f32: maximum width, in vp.<br>.value[2].f32: minimum height, in vp.<br>.value[3].f32: maximum height, in vp.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: minimum width, in vp.<br>.value[1].f32: maximum width, in vp.<br>.value[2].f32: minimum height, in vp.<br>.value[3].f32: maximum height, in vp. |
| NODE_GRAY_SCALE                             | Defines the grayscale effect. APIs are provided for setting, resetting, and obtaining the attribute value.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: grayscale conversion ratio. The value ranges from 0 to 1. For example, 0.5 indicates a 50% grayscale conversion ratio.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: grayscale conversion ratio. The value ranges from 0 to 1. |
| NODE_INVERT                                 | Inverts the image. APIs are provided for setting, resetting, and obtaining the attribute value.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: image inversion ratio. The value ranges from 0 to 1. For example, 0.5 indicates a 50% image inversion ratio.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: image inversion ratio. The value ranges from 0 to 1. |
| NODE_SEPIA                                  | Defines the sepia conversion ratio. APIs are provided for setting, resetting, and obtaining the attribute value.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: sepia conversion ratio. The value ranges from 0 to 1. For example, 0.5 indicates that a 50% sepia conversion ratio.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: sepia conversion ratio. The value ranges from 0 to 1. |
| NODE_CONTRAST                               | Defines the contrast attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>*.value[0].f32: contrast. If the value is 1, the source image is displayed. A larger value indicates a higher contrast. Value range: [0, 10).<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: contrast. Value range: [0, 10). |
| NODE_FOREGROUND_COLOR                       | Defines the foreground color attribute, which can be set, reset, and obtained as required through APIs.<br>[ArkUI_AttributeItem](_ark_u_i___attribute_item.md) format of the attribute setting method parameter. The following input parameter formats are supported:<br>1: .value[0].u32: color value, in 0xARGB format. For example, 0xFFFF0000 indicates red.<br>2: .value[0].i32: ArkUI_ColoringStrategy;<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].u32: color value, in 0xARGB format. |
| NODE_OFFSET                                 | Defines the offset of the component's child relative to the component. APIs are provided for setting, resetting, and obtaining the attribute value.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32 : offset along the x-axis, in vp.<br>.value[1].f32 : offset along the y-axis, in vp.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32 : offset along the x-axis, in vp.<br>.value[1].f32 : offset along the y-axis, in vp. |
| NODE_MARK_ANCHOR                            | Sets the anchor for locating the component's child. APIs are provided for setting, resetting, and obtaining the attribute value.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: X coordinate of the anchor, in vp.<br>.value[1].f32: Y coordinate of the anchor, in vp.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: X coordinate of the anchor, in vp.<br>.value[1].f32: Y coordinate of the anchor, in vp. |
| NODE_BACKGROUND_IMAGE_POSITION              | Defines the position of the background image in the component, that is, the coordinates relative to the upper left corner of the component. APIs are provided for setting, resetting, and obtaining the attribute value.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: position along the x-axis, in vp.<br>.value[1].f32: position along the y-axis, in vp.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: position along the x-axis, in vp.<br>.value[1].f32: position along the y-axis, in vp. |
| NODE_ALIGN_RULES                            | Sets the alignment rules in the relative container. APIs are provided for setting, resetting, and obtaining the attribute value.<br>.object: Use the [ArkUI_AlignmentRuleOption](#arkui_alignmentruleoption) object as the alignment rule of the component.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.object: Use the [ArkUI_AlignmentRuleOption](#arkui_alignmentruleoption) object as the alignment rule of the component. |
| NODE_ALIGN_SELF                             | Sets the alignment mode of the child components along the cross axis of the parent container. APIs are provided for setting, resetting, and obtaining the attribute value.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: alignment mode of the child components along the cross axis of the parent container. <br>The parameter type is [ArkUI_ItemAlignment](#arkui_itemalignment). The default value is ARKUI_ITEM_ALIGNMENT_AUTO.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: alignment mode of the child components along the cross axis of the parent container. <br>The parameter type is [ArkUI_ItemAlignment](#arkui_itemalignment). The default value is ARKUI_ITEM_ALIGNMENT_AUTO. |
| NODE_FLEX_GROW                              | Sets the percentage of the parent container's remaining space that is allocated to the component. APIs are provided for setting, resetting, and obtaining the attribute value.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: percentage of the parent container's remaining space that is allocated to the component.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: percentage of the parent container's remaining space that is allocated to the component. |
| NODE_FLEX_SHRINK                            | Sets the percentage of the parent container's shrink size that is allocated to the component. APIs are provided for setting, resetting, and obtaining the attribute value.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: percentage of the parent container's shrink size that is allocated to the component.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: percentage of the parent container's shrink size that is allocated to the component. |
| NODE_FLEX_BASIS                             | Sets the base size of the component. APIs are provided for setting, resetting, and obtaining the attribute value.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: percentage of the parent container's remaining space that is allocated to the component.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: percentage of the parent container's remaining space that is allocated to the component. |
| NODE_ACCESSIBILITY_GROUP                    | Sets the accessibility group. APIs are provided for setting, resetting, and obtaining the attribute value.<br>The parameter format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) method is as follows:<br>If **accessible** is set to **true**, the component and all its child components form an entire selectable component, and the accessibility service will no longer available for the content of its child components. The value is 1 or 0.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>If **accessible** is set to **true**, the component and all its child components form an entire selectable component, and the accessibility service will no longer available for the content of its child components. The value is 1 or 0. |
| NODE_ACCESSIBILITY_TEXT                     | Sets the accessibility text. APIs are provided for setting, resetting, and obtaining the attribute value.<br>The parameter format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) method is as follows:<br>.string: accessibility text.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string: accessibility text. |
| NODE_ACCESSIBILITY_MODE                     | @brief Defines the accessibility mode. This attribute can be set, reset, and obtained as required through APIs.<br>The parameter format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) method is as follows:<br>.value[0].i32: auxiliary service mode. The parameter type is [ArkUI_AccessibilityMode](#arkui_accessibilitymode).<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: auxiliary service mode. The parameter type is [ArkUI_AccessibilityMode](#arkui_accessibilitymode). |
| NODE_ACCESSIBILITY_DESCRIPTION              | Sets the accessibility description. APIs are provided for setting, resetting, and obtaining the attribute value.<br>The parameter format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) method is as follows:<br>.string: accessibility description.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string: accessibility description. |
| NODE_FOCUS_STATUS                           | This interface is used to obtain focus attributes. Attributes can be set and obtained.<br>The parameter format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) method is as follows:<br>value[0].i32: The parameter type is 1 or 0.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>value[0].i32: The parameter type is 1 or 0. |
| NODE_ASPECT_RATIO                           | @brief Defines the aspect ratio attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: aspect ratio of the component, in width/height format.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: aspect ratio of the component, in width/height format. |
| NODE_LAYOUT_WEIGHT                          | @brief Defines the weight of the component within its row, column, or flex container for proportional distribution of available space within the container. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].u32: weight of the component along the main axis.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].u32: weight of the component along the main axis. |
| NODE_DISPLAY_PRIORITY                       | @brief Sets the display priority for the component in the row, column, or flex (single-line) container. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].u32: display priority of the component in the container.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].u32: display priority of the component in the container. |
| NODE_OUTLINE_WIDTH                          | @brief Sets the thickness of an element's outline.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: thickness of the left outline.<br>.value[1].f32: thickness of the top outline.<br>.value[2].f32: thickness of the right outline.<br>.value[3].f32: thickness of the bottom outline.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: thickness of the left outline.<br>.value[1].f32: thickness of the top outline.<br>.value[2].f32: thickness of the right outline.<br>.value[3].f32: thickness of the bottom outline. |
| NODE_RELATIVE_LAYOUT_CHAIN_MODE             | Specifies the parameters of the chain formed by the component as the chain head. The attribute setting, attribute resetting, and attribute obtaining interfaces are supported.<br>This attribute has effect only when the parent container is <RelativeContainer>.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: direction of the chain. Enumeration [ArkUI_Axis](#arkui_axis).<br>.value[1].i32: style of the chain. Enumeration [ArkUI_RelativeLayoutChainStyle](#arkui_relativelayoutchainstyle).<br>.value[0].i32: direction of the chain. Enumeration [ArkUI_Axis](#arkui_axis).<br>.value[1].i32: style of the chain. Enumeration [ArkUI_RelativeLayoutChainStyle](#arkui_relativelayoutchainstyle). |
| NODE_RENDER_FIT                             | @brief Sets how the final state of the component's content is rendered during its width and height animation process. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32 Content filling mode. The enumerated values of [ArkUI_RenderFit](#arkui_renderfit) are used.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32 Content filling mode. The enumerated values of [ArkUI_RenderFit](#arkui_renderfit) are used. |
| NODE_OUTLINE_COLOR                          | Defines the border color attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>1: .value[0].u32: color of the four borders, in 0xARGB format, for example, **0xFFFF11FF**.<br>2: .value[0].u32: color of the top border, in 0xARGB format, for example, **0xFFFF11FF**.<br>.value[1].u32: color of the right border, in 0xARGB format, for example, **0xFFFF11FF**.<br>.value[2].u32: color of the lower border, in 0xARGB format, for example, **0xFFFF11FF**.<br>.value[3].u32: color of the left border, in 0xARGB format, for example, **0xFFFF11FF**.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].u32: color of the top border, in 0xARGB format, for example, **0xFFFF11FF**.<br>.value[1].u32: color of the right border, in 0xARGB format, for example, **0xFFFF11FF**.<br>.value[2].u32: color of the lower border, in 0xARGB format, for example, **0xFFFF11FF**.<br>.value[3].u32: color of the left border, in 0xARGB format, for example, **0xFFFF11FF**. |
| NODE_SIZE                                   | @brief Sets the size. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: width, in vp.<br>.value[1].f32: height, in vp.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: width, in vp.<br>.value[1].f32: height, in vp. |
| NODE_RENDER_GROUP                           | @brief Sets whether the component and its child components are rendered off the screen and then drawn together with its parent. This attribute can be set, reset, and obtained as required through APIs.<br>The parameter format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) method is as follows:<br>value[0].i32: The parameter type is 1 or 0.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>value[0].i32: The parameter type is 1 or 0. |
| NODE_COLOR_BLEND                            | The color overlay effect is added to the component. The attribute setting, attribute resetting, and attribute obtaining interfaces are supported.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].u32: color to blend with the component, in 0xARGB format, for example, 0xFFFF11FF.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].u32: color to blend with the component, in 0xARGB format, for example, 0xFFFF11FF. |
| NODE_FOREGROUND_BLUR_STYLE                  | @brief Applies a foreground blur style to the component. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32 indicates the fuzzy content style. The enumerated values of [ArkUI_BlurStyle](#arkui_blurstyle) are used.<br>.value[1]?.i32: color mode used for the foreground blur. The value is an enum of {@link ArkUI_ColorMode}.<br>.value[2]? .i32 indicates the color obtaining mode used by the content blur effect. The enumerated values of [ArkUI_AdaptiveColor](#arkui_adaptivecolor) are used.<br>.value[3]?.i32: grayscale blur parameters. The value range is [0, 127].<br>.value[4]?.i32: grayscale blur parameters. The value range is [0, 127].<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32 indicates the fuzzy content style. The enumerated values of [ArkUI_BlurStyle](#arkui_blurstyle) are used.<br>.value[1].i32: color mode used for the foreground blur. The value is an enum of {@link ArkUI_ColorMode}.<br>.value[2].i32 indicates the color obtaining mode used by the content blur effect. The enumerated values of [ArkUI_AdaptiveColor](#arkui_adaptivecolor) are used.<br>.value[3].i32: grayscale blur parameters. The value range is [0, 127].<br>.value[4].i32: grayscale blur parameters. The value range is [0, 127]. |
| NODE_GEOMETRY_TRANSITION                    | @brief Implements an implicit shared element transition. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>value[0].i32: The parameter type is 1 or 0. Indicates whether to continue to participate in the animation of the shared element when the exit element is not deleted. The default value is false, indicating that the original position remains unchanged.<br>ID used to set up a binding relationship. If this attribute is set to an empty string **""**, the binding relationship is cleared. The value can be dynamically changed to refresh the binding relationship. One ID can be bound to only two components, which function as in and out components.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>value[0].i32: The parameter type is 1 or 0. Indicates whether to continue to participate in the animation of the shared element when the exit element is not deleted. The default value is false, indicating that the original position remains unchanged.<br>ID used to set up a binding relationship. If this attribute is set to an empty string **""**, the binding relationship is cleared. The value can be dynamically changed to refresh the binding relationship. One ID can be bound to only two components, which function as in and out components. |
| NODE_WIDTH_PERCENT                          | Defines the width attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: width, in percentage. <br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: width, in percentage. |
| NODE_HEIGHT_PERCENT                         | Defines the height attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: height, in percentage. <br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: height, in percentage. |
| NODE_PADDING_PERCENT                        | Defines the padding attribute, which can be set, reset, and obtained as required through APIs.<br>There are two formats of [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) for setting the attribute value:<br>1: Specify the same padding for the four directions.<br>.value[0].f32: padding, in percentage. <br>2: Specify different paddings for different directions.<br>.value[0].f32: top padding, in percentage. <br>.value[1].f32: right padding, in percentage. <br>.value[2].f32: bottom padding, in percentage. <br>.value[3].f32: left padding, in percentage. <br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: top padding, in percentage. <br>.value[1].f32: right padding, in percentage. <br>.value[2].f32: bottom padding, in percentage. <br>.value[3].f32: left padding, in percentage. |
| NODE_MARGIN_PERCENT                         | Defines the margin attribute, which can be set, reset, and obtained as required through APIs.<br>There are two formats of [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) for setting the attribute value:<br>1: Specify the same margin for the four directions.<br>.value[0].f32: margin, in percentage. <br>2: Specify different margins for different directions.<br>.value[0].f32: top margin, in percentage. <br>.value[1].f32: right margin, in percentage. <br>.value[2].f32: bottom margin, in percentage. <br>.value[3].f32: left margin, in percentage. <br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: top margin, in percentage. <br>.value[1].f32: right margin, in percentage. <br>.value[2].f32: bottom margin, in percentage. <br>.value[3].f32: left margin, in percentage. |
| NODE_LAYOUT_RECT                            | Component layout size and position attributes, including attribute setting, attribute resetting, and attribute obtaining interfaces.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: X coordinate of the component, in px. <br>.value[1].i32: Y coordinate of the component, in px. <br>.value[2].i32: width of the component, in px. <br>.value[3].i32: height of the component, in px. <br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: X coordinate of the component, in px. <br>.value[1].i32: Y coordinate of the component, in px. <br>.value[2].i32: width of the component, in px. <br>.value[3].i32: height of the component, in px. |
| NODE_TEXT_CONTENT                           | Defines the text content attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.string indicates the text content.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string indicates the text content. |
| NODE_FONT_COLOR                             | Defines the font color attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].u32: font color, in 0xARGB format. For example, 0xFFFF0000 indicates red.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].u32: font color value, in 0xARGB format. |
| NODE_FONT_SIZE                              | Defines the font size attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: font size, in fp.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: font size, in fp. |
| NODE_FONT_STYLE                             | Defines the font style attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: font style [ArkUI_FontStyle](#arkui_fontstyle). The default value is ARKUI_FONT_STYLE_NORMAL.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: font[ArkUI_FontStyle] (#arkui_fontstyle); |
| NODE_FONT_WEIGHT                            | Defines the font weight attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: font width style [ArkUI_FontWeight](#arkui_fontweight). The default value is ARKUI_FONT_WEIGHT_NORMAL.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: [ArkUI_FontWeight] (#arkui_fontweight); |
| NODE_TEXT_LINE_HEIGHT                       | Defines the text line height attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: line height, in fp.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: line height, in fp. |
| NODE_TEXT_DECORATION                        | Defines the text decoration style and color. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: text decoration line type [ArkUI_TextDecorationType](#arkui_textdecorationtype). The default value is ARKUI_TEXT_DECORATION_TYPE_NONE.<br>.value[1]?.u32: text decoration color, in 0xARGB format. For example, 0xFFFF0000 indicates red. Optional. <br>.value[2]? .i32: [ArkUI_TextDecorationStyle] (#arkui_textdecorationstyle);<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: [ArkUI_TextDecorationType] (#arkui_textdecorationtype);<br>.value[1].u32: text decoration color, in 0xARGB format.<br>.value[2].i32: [ArkUI_TextDecorationStyle] (#arkui_textdecorationstyle); |
| NODE_TEXT_CASE                              | Defines the text case attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: text case.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: text case. |
| NODE_TEXT_LETTER_SPACING                    | Defines the letter spacing attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: letter spacing, in fp.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: letter spacing, in fp. |
| NODE_TEXT_MAX_LINES                         | Sets the maximum number of lines in the text. APIs are provided for setting, resetting, and obtaining the attribute value.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: maximum number of lines in the text.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: maximum number of lines in the text. |
| NODE_TEXT_ALIGN                             | Horizontal alignment mode of the text. The interfaces for setting, resetting, and obtaining attributes are supported.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: horizontal alignment mode of the text. The enumerated values of [ArkUI_TextAlignment](#arkui_textalignment) are used.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: horizontal alignment mode of the text. The enumerated values of [ArkUI_TextAlignment](#arkui_textalignment) are used. |
| NODE_TEXT_OVERFLOW                          | Defines the text overflow attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: display mode when the text is too long.{\@ArkUI_TextOverflow}<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: display mode when the text is too long.{\@ArkUI_TextOverflow} |
| NODE_FONT_FAMILY                            | Defines the font family attribute, which can be set, reset, and obtained as required through APIs.<br>The parameter format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) method is as follows:<br>.string: fonts, separated by commas (,).<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string: fonts, separated by commas (,). |
| NODE_TEXT_COPY_OPTION                       | Defines the copy option attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: copy and paste mode [ArkUI_CopyOptions](#arkui_copyoptions). The default value is ARKUI_COPY_OPTIONS_NONE.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: [ArkUI_CopyOptions] (#arkui_copyoptions) |
| NODE_TEXT_BASELINE_OFFSET                   | Defines the text baseline offset attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: baseline offset, in fp.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: baseline offset, in fp. |
| NODE_TEXT_TEXT_SHADOW                       | Defines the text shadow attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: blur radius of the shadow, in vp.<br>.value[1].i32: shadow type [ArkUI_ShadowType](#arkui_shadowtype). The default value is ARKUI_SHADOW_TYPE_COLOR.<br>.value[2].u32: shadow color, in 0xARGB format. For example, 0xFFFF0000 indicates red.<br>.value[3].f32: offset of the shadow along the x-axis, in vp.<br>.value[4].f32: offset of the shadow along the y-axis, in vp.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: blur radius of the shadow, in vp.<br>.value[1].i32: ShadowType[ArkUI_ShadowType] (#arkui_shadowtype);<br>.value[2].u32: shadow color, in 0xARGB format.<br>.value[3].f32: offset of the shadow along the x-axis, in vp.<br>.value[4].f32: offset of the shadow along the y-axis, in vp. |
| NODE_TEXT_MIN_FONT_SIZE                     | Defines the minimum font size attribute, which can be set, reset, and obtained as required through APIs.<br>The parameter format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) method is as follows:<br>.value[0].f32: minimum font size, in fp.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: minimum font size, in fp. |
| NODE_TEXT_MAX_FONT_SIZE                     | Defines the maximum font size attribute, which can be set, reset, and obtained as required through APIs.<br>The parameter format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) method is as follows:<br>.value[0].f32: maximum font size, in fp.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: maximum font size, in fp. |
| NODE_TEXT_FONT                              | Defines the text style attribute, which can be set, reset, and obtained as required through APIs.<br>The parameter format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) method is as follows:<br>.string?: font family. Optional. Use commas (,) to separate multiple fonts.<br>.value[0].f32: font size, in fp.<br>.value[1]? .i32: (optional) font weight of the text. The parameter type is [ArkUI_FontWeight](#arkui_fontweight). The default value is ARKUI_FONT_WEIGHT_NORMAL.<br>.value[2]? .i32: (optional) font style. The parameter type is [ArkUI_FontStyle](#arkui_fontstyle). The default value is ARKUI_FONT_STYLE_NORMAL.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string: font family. Use commas (,) to separate multiple fonts.<br>.value[0].f32: font size, in fp.<br>.value[1].i32: font weight of the text. The parameter type is [ArkUI_FontWeight](#arkui_fontweight). The default value is ARKUI_FONT_WEIGHT_NORMAL.<br>.value[2].i32: font style. The parameter type is [ArkUI_FontStyle](#arkui_fontstyle). The default value is ARKUI_FONT_STYLE_NORMAL. |
| NODE_TEXT_HEIGHT_ADAPTIVE_POLICY            | Defines how the adaptive height is determined for the text. This attribute can be set, reset, and obtained as required through APIs.<br>The parameter format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) method is as follows:<br>.value[0].i32: parameter type [ArkUI_TextHeightAdaptivePolicy](#arkui_textheightadaptivepolicy).<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: parameter type [ArkUI_TextHeightAdaptivePolicy](#arkui_textheightadaptivepolicy). |
| NODE_TEXT_INDENT                            | Defines the indentation of the first line. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: indentation of the first line.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: indentation of the first line. |
| NODE_TEXT_WORD_BREAK                        | @brief Defines the line break rule. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: [ArkUI_WordBreak] (#arkui_wordbreak)<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: [ArkUI_WordBreak] (#arkui_wordbreak) |
| NODE_TEXT_ELLIPSIS_MODE                     | @brief Defines the ellipsis position. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: [ArkUI_EllipsisMode] (#arkui_ellipsismode)<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: [ArkUI_EllipsisMode] (#arkui_ellipsismode) |
| NODE_TEXT_LINE_SPACING                      | @brief Defines the line spacing attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: line spacing, in fp. <br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: line spacing, in fp. |
| NODE_FONT_FEATURE                           | Sets the text feature effect. Set the NODE_FONT_FEATURE attribute. NODE_FONT_FEATURE is the advanced typesetting capability of OpenType fonts,<br>Features such as hyphenation and number width are generally used in customized fonts. The capabilities of these features require the support of the font itself. The interfaces for setting, resetting, and obtaining attributes are supported.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.string: string that complies with the text feature format. The format is normal\. |
| NODE_TEXT_ENABLE_DATA_DETECTOR              | Sets whether to enable text recognition.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: whether to enable text recognition. The default value is false.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: whether to enable text recognition. |
| NODE_TEXT_ENABLE_DATA_DETECTOR_CONFIG       | Configures text recognition settings.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0...].i32: entity type array. The parameter type is [ArkUI_TextDataDetectorType](#arkui_textdatadetectortype).<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0...].i32: entity type array. The parameter type is [ArkUI_TextDataDetectorType](#arkui_textdatadetectortype). |
| NODE_TEXT_SELECTED_BACKGROUND_COLOR         | @brief Defines the background color of the selected text. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].u32: color value, in 0xARGB format. For example, 0xFFFF0000 indicates red.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].u32: color value, in 0xARGB format. |
| NODE_SPAN_CONTENT                           | Defines the text content attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.string: content of the text span.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string: content of the text span. |
| NODE_TEXT_CONTENT_WITH_STYLED_STRING        | @brief Sets the string to use in the styled string. This attribute can be set and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.object: string to use in the styled string. The parameter type is {@link ArkUI_StyledString}.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.object: string to use in the styled string. The parameter type is {@link ArkUI_StyledString}. |
| NODE_SPAN_TEXT_BACKGROUND_STYLE             | @brief Defines the text background style. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].u32: color of the text background, in 0xARGB format, for example, 0xFFFF0000 indicating red.<br>The second parameter is used to set the rounded corner of the text background. The options are as follows:<br>1: .value[1].f32: The radiuses of rounded corners in the four directions are set in a unified manner. The unit is vp.<br>2: .value[1].f32: radius of the upper left corner, in vp.<br>.value[2].f32: radius of the upper right corner, in vp.<br>.value[3].f32: radius of the lower left corner, in vp.<br>.value[4].f32: radius of the lower right corner, in vp.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].u32: color of the text background, in 0xARGB format.<br>.value[1].f32: radius of the upper left corner, in vp.<br>.value[2].f32: radius of the upper right corner, in vp.<br>.value[3].f32: radius of the lower left corner, in vp.<br>.value[4].f32: radius of the lower right corner, in vp. |
| NODE_IMAGE_SPAN_SRC                         | Defines the image source of the image span. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.string: image address of the image span.<br>.object: PixelMap object. The parameter type is {@link ArkUI_DrawableDesciptor}.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string: image address of the image span.<br>.object: PixelMap object. The parameter type is {@link ArkUI_DrawableDesciptor}. Either .object or .string must be set. |
| NODE_IMAGE_SPAN_VERTICAL_ALIGNMENT          | Defines the alignment mode of the image with the text. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32 indicates the text-based image alignment mode. The enumerated values of [ArkUI_ImageSpanAlignment](#arkui_imagespanalignment) are used.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32 indicates the text-based image alignment mode. The enumerated values of [ArkUI_ImageSpanAlignment](#arkui_imagespanalignment) are used. |
| NODE_IMAGE_SRC                              | Defines the image source of the <Image> component. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.string: image source.<br>.object: PixelMap object. The parameter type is {@link ArkUI_DrawableDesciptor}. Either .object or .string must be set.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string: image source.<br>.object: PixelMap object. The parameter type is {@link ArkUI_DrawableDesciptor}. |
| NODE_IMAGE_OBJECT_FIT                       | Defines how the image is resized to fit its container. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32 indicates the image filling effect. The enumerated values of [ArkUI_ObjectFit](#arkui_objectfit) are used.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32 indicates the image filling effect. The enumerated values of [ArkUI_ObjectFit](#arkui_objectfit) are used. |
| NODE_IMAGE_INTERPOLATION                    | Defines the interpolation effect of the image. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32 indicates the interpolation effect. The enumerated values of [ArkUI_ImageInterpolation](#arkui_imageinterpolation) are used.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32 indicates the interpolation effect. The enumerated values of [ArkUI_ImageInterpolation](#arkui_imageinterpolation) are used. |
| NODE_IMAGE_OBJECT_REPEAT                    | Defines how the image is repeated. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32 indicates the image repetition style. The enumerated values of [ArkUI_ImageRepeat](#arkui_imagerepeat) are used.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32 indicates the image repetition style. The enumerated values of [ArkUI_ImageRepeat](#arkui_imagerepeat) are used. |
| NODE_IMAGE_COLOR_FILTER                     | Defines the color filter of the image. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32 to .value[19].f32: filter matrix array.<br>.size: 5 x 4 filter array size.<br>.object: pointer to the color filter. The parameter type is {@link OH_Drawing_ColorFilter}. Either .object or .size can be set.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32 to .value[19].f32: filter matrix array.<br>.size: 5 x 4 filter array size.<br>.object: pointer to the color filter. The parameter type is {@link OH_Drawing_ColorFilter}. |
| NODE_IMAGE_AUTO_RESIZE                      | Defines the auto resize attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32 : whether to resize the image source.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32 : whether to resize the image source. |
| NODE_IMAGE_ALT                              | Defines the placeholder image source. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.string: placeholder image source.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string: placeholder image source. |
| NODE_IMAGE_DRAGGABLE                        | @brief Defines whether the image is draggable. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: whether the image is draggable. The value true means that the image is draggable.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: whether the image is draggable. |
| NODE_IMAGE_RENDER_MODE                      | @brief Defines the image rendering mode. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32 [ArkUI_ImageRenderMode] (#arkui_imagerendermode)<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32 [ArkUI_ImageRenderMode] (#arkui_imagerendermode) |
| NODE_IMAGE_FIT_ORIGINAL_SIZE                | @brief Sets whether to fit the component to the size of the image source when the component size is not set. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: indicates whether the display size of an image follows the size of the image source. The value 1 indicates that the display size follows the size of the image source, and the value 0 indicates that the display size does not follow the size of the image source. The default value is 0.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: The value 1 means to fit the component to the size of the image source, and 0 means the opposite. |
| NODE_IMAGE_FILL_COLOR                       | @brief Sets the fill color to be superimposed on the image. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].u32: fill color. The value is in 0xARGB format. For example, 0xFFFF0000 indicates red.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].u32: fill color. The value is in 0xARGB format. |
| NODE_IMAGE_RESIZABLE                        | Sets the resizable image options.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: width of the left edge. The unit is vp.<br>.value[1].f32: width of the top edge. The unit is vp.<br>.value[2].f32: width of the right edge. The unit is vp.<br>.value[3].f32: width of the bottom edge. The unit is vp.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: width of the left edge. The unit is vp.<br>.value[1].f32: width of the top edge. The unit is vp.<br>.value[2].f32: width of the right edge. The unit is vp.<br>.value[3].f32: width of the bottom edge. The unit is vp. |
| NODE_TOGGLE_SELECTED_COLOR                  | Defines the color of the component when it is selected. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].u32: background color, in 0xARGB format. For example, 0xFFFF0000 indicates red.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].u32: background color, in 0xARGB format. |
| NODE_TOGGLE_SWITCH_POINT_COLOR              | Defines the color of the circular slider for the component of the switch type. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].u32: color of the circular slider, in 0xARGB format. For example, 0xFFFF0000 indicates red.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].u32: color of the circular slider, in 0xARGB format. |
| NODE_TOGGLE_VALUE                           | @brief Defines the toggle switch value. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: whether to enable the toggle. The value true means to enable the toggle.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: whether to enable the toggle. |
| NODE_TOGGLE_UNSELECTED_COLOR                | @brief Defines the color of the component when it is deselected. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].u32: background color, in 0xARGB format. For example, 0xFFFF0000 indicates red.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].u32: background color, in 0xARGB format. |
| NODE_LOADING_PROGRESS_COLOR                 | Defines the foreground color of the loading progress bar. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].u32: foreground color, in 0xARGB format. For example, 0xFFFF0000 indicates red.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].u32: foreground color, in 0xARGB format. |
| NODE_LOADING_PROGRESS_ENABLE_LOADING        | Defines whether to show the loading animation for the <LoadingProgress> component. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: whether to show the loading animation. The value true means to show the loading animation, and false means the opposite.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: The value 1 means to show the loading animation, and 0 means the opposite. |
| NODE_TEXT_INPUT_PLACEHOLDER                 | Defines the default placeholder text of the single-line text box. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.string: default placeholder text.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string: default placeholder text. |
| NODE_TEXT_INPUT_TEXT                        | Defines the default text content of the single-line text box. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.string: default text content.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string: default text content. |
| NODE_TEXT_INPUT_CARET_COLOR                 | Defines the caret color attribute. APIs are provided for setting, resetting, and obtaining the attribute value.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].u32: caret color, in 0xARGB format. For example, 0xFFFF0000 indicates red.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].u32: caret color, in 0xARGB format. |
| NODE_TEXT_INPUT_CARET_STYLE                 | Defines the caret style attribute. APIs are provided for setting, resetting, and obtaining the attribute value.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: caret width, in vp.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: caret width, in vp. |
| NODE_TEXT_INPUT_SHOW_UNDERLINE              | Defines the underline attribute of the single-line text box. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: whether to show an underline. The value true means to show an underline, and false means the opposite.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: The value 1 means to show an underline, and 0 means the opposite. |
| NODE_TEXT_INPUT_MAX_LENGTH                  | Defines the maximum number of characters in the text input. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: maximum number of characters in the text input, without a unit.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: maximum number of characters in the text input. |
| NODE_TEXT_INPUT_ENTER_KEY_TYPE              | Defines the type of the Enter key. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: Enter key type enumeration [ArkUI_EnterKeyType](#arkui_enterkeytype). The default value is ARKUI_ENTER_KEY_TYPE_DONE.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: [ArkUI_EnterKeyType] (#arkui_enterkeytype) |
| NODE_TEXT_INPUT_PLACEHOLDER_COLOR           | Defines the placeholder text color. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].u32: color value, in 0xARGB format. For example, 0xFFFF0000 indicates red.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].u32: color value, in 0xARGB format. |
| NODE_TEXT_INPUT_PLACEHOLDER_FONT            | Defines the placeholder text font. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0]? .f32: font size, in fp. Optional. The default value is 16.0.<br>.value[1]? .i32: optional font style [ArkUI_FontStyle](#arkui_fontstyle). The default value is ARKUI_FONT_STYLE_NORMAL.<br>.value[2]? .i32: optional font weight style [ArkUI_FontWeight](#arkui_fontweight). The default value is ARKUI_FONT_WEIGHT_NORMAL.<br>?.string: font family. Multiple font families are separated by commas (,). For example, "font weight; font family 1, font family 2".<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: font size, in fp.<br>.value[1].i32: font[ArkUI_FontStyle] (#arkui_fontstyle);<br>.value[2].i32: [ArkUI_FontWeight] (#arkui_fontweight);<br>.string: font family. Multiple font families are separated by commas (,). |
| NODE_TEXT_INPUT_ENABLE_KEYBOARD_ON_FOCUS    | Defines whether to enable the input method when the component obtains focus. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: whether to enable the input method when the component obtains focus. The value true means to enable the input method, and false means the opposite.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br> .value[0].i32: The value 1 means to enable the input method when the component obtains focus, and 0 means the opposite. |
| NODE_TEXT_INPUT_TYPE                        | Defines the text box type. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: input box type enumeration [ArkUI_TextInputType](#arkui_textinputtype). The default value is ARKUI_TEXTINPUT_TYPE_NORMAL.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: input box type enumeration [ArkUI_TextInputType](#arkui_textinputtype). |
| NODE_TEXT_INPUT_SELECTED_BACKGROUND_COLOR   | Defines the background color of the selected text. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].u32: color value, in 0xARGB format. For example, 0xFFFF0000 indicates red.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].u32: color value, in 0xARGB format. |
| NODE_TEXT_INPUT_SHOW_PASSWORD_ICON          | Defines whether to display the password icon at the end of the password text box. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: whether to display the password icon at the end of the password text box. The value true means to display the password icon, and false means the opposite.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: The value 1 means to display the password icon at the end of the password text box, and 0 means the opposite. |
| NODE_TEXT_INPUT_EDITING                     | Defines the editable state for the single-line text box. This attribute can be set as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: whether to remain in the editable state. The value true means to remain in the editable state, and false means to exit the editable state.<br>The format of the attribute obtaining method parameter [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) is as follows:<br>.value[0].i32: whether to remain in the editable state. The value true means to remain in the editable state, and false means to exit the editable state. |
| NODE_TEXT_INPUT_CANCEL_BUTTON               | Defines the style of the cancel button on the right of the single-line text box. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: button style [ArkUI_CancelButtonStyle](#arkui_cancelbuttonstyle). The default value is ARKUI_CANCELBUTTON_STYLE_INPUT.<br>.value[1]? .f32: button icon size, in vp.<br>.value[2]? .u32: button icon color, in 0xARGB format. For example, 0xFFFF0000 indicates red.<br>?.string: button icon image source. The value is the local address of the image, for example, /pages/icon.png.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: ButtonStyle[ArkUI_CancelButtonStyle] (#arkui_cancelbuttonstyle);<br>.value[1].f32: icon size, in vp.<br>.value[2].u32: button icon color, in 0xARGB format.<br>.string: button icon image source. |
| NODE_TEXT_INPUT_TEXT_SELECTION              | @brief Sets the text selection area, which will be highlighted. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: start position of the text selection. <br>.value[1].i32: end position of the text selection. <br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: start position of the text selection. <br>.value[1].i32: end position of the text selection. |
| NODE_TEXT_INPUT_UNDERLINE_COLOR             | Sets the color of the underline when it is shown.<br>The default underline color configured for the theme is '0x33182431'.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].u32: color of the underline applied to the text being typed in. The value is in 0xARGB format. <br>.value[1].u32: color of the underline applied to the text in the normal state. The value is in 0xARGB format. <br>.value[2].u32: color of the underline applied to the text when an error is detected. The value is in 0xARGB format. <br>.value[3].u32: color of the underline applied to the text when it is disabled. The value is in 0xARGB format. <br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].u32: color of the underline applied to the text being typed in. The value is in 0xARGB format. <br>.value[1].u32: color of the underline applied to the text in the normal state. The value is in 0xARGB format. <br>.value[2].u32: color of the underline applied to the text when an error is detected. The value is in 0xARGB format. <br>.value[3].u32: color of the underline applied to the text when it is disabled. The value is in 0xARGB format. |
| NODE_TEXT_INPUT_ENABLE_AUTO_FILL            | Sets whether to enable autofill.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: whether to enable autofill. The default value is true.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: whether to enable autofill. |
| NODE_TEXT_INPUT_CONTENT_TYPE                | Enumerates the content types for autofill.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: [ArkUI_TextInputContentType] (#arkui_textinputcontenttype)<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: [ArkUI_TextInputContentType] (#arkui_textinputcontenttype) |
| NODE_TEXT_INPUT_PASSWORD_RULES              | Rules for generating passwords. When autofill is used, these rules are transparently transmitted to Password Vault for generating a new password.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.string: rules for generating passwords.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string: rules for generating passwords. |
| NODE_TEXT_INPUT_SELECT_ALL                  | Sets whether to select all text in the initial state. This attribute is not available for the inline input style.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: whether to select all text in the initial state. The default value is b>false.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: whether to select all text in the initial state. |
| NODE_TEXT_INPUT_INPUT_FILTER                | Sets the regular expression for input filtering. Only inputs that comply with the regular expression can be displayed. Other inputs are filtered out. The specified regular expression can match single characters, but not strings.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.string: regular expression.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string: regular expression. |
| NODE_TEXT_INPUT_STYLE                       | @brief Sets the text box to the default style or inline input style.<br>For the inline input style, only InputType.Normal is supported.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: [ArkUI_TextInputStyle] (#arkui_textinputstyle)<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: [ArkUI_TextInputStyle] (#arkui_textinputstyle) |
| NODE_TEXT_INPUT_CARET_OFFSET                | @brief Sets or obtains the caret position.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>Sets the position of the caret. **value**: indicates the length from the start of the string to the position where the input cursor is located.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>Returns the position information of the caret. If this API is called when the cursor position is updated in the current frame, value[0].i32 (index value of the cursor position) does not take effect.<br>value[1].f32: X coordinate of the cursor relative to the text box.<br>value[2].f32: Y coordinate of the cursor relative to the text box. |
| NODE_TEXT_INPUT_CONTENT_RECT                | Position of the edited text area relative to the component and its size.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>value[0].f32: horizontal coordinate.<br>value[1].f32: vertical coordinate.<br>value[2].f32: content width.<br>value[3].f32: content height. |
| NODE_TEXT_INPUT_CONTENT_LINE_COUNT          | Obtains the number of lines of the edited text.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>value[0].i32: number of lines in the edited text. |
| NODE_TEXT_INPUT_SELECTION_MENU_HIDDEN       | @brief Sets whether to hide the text selection menu when the text box is long-pressed, double-click, or right-clicked. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: whether to hide the text selection menu when the text box is long-pressed, double-click, or right-clicked. The default value is false.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: whether to hide the text selection menu when the text box is long-pressed, double-click, or right-clicked. |
| NODE_TEXT_INPUT_BLUR_ON_SUBMIT              | @brief Sets whether the text box loses focus after the Enter key is pressed to submit information.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: whether the text box loses focus.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: whether the text box loses focus. |
| NODE_TEXT_INPUT_CUSTOM_KEYBOARD             | Sets a custom keyboard.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.object: custom keyboard. The parameter type is {@link ArkUI_NodeHandle}.<br>.value[0]?.i32: whether the custom keyboard supports avoidance. The default value is false.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.object: custom keyboard. The parameter type is {@link ArkUI_NodeHandle}.<br>.value[0].i32: whether the custom keyboard supports avoidance. |
| NODE_TEXT_INPUT_WORD_BREAK                  | @brief Defines the line break rule. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: [ArkUI_WordBreak] (#arkui_wordbreak)<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: [ArkUI_WordBreak] (#arkui_wordbreak) |
| NODE_TEXT_INPUT_NUMBER_OF_LINES             | @brief Sets the number of lines in <TextInput> component, which can be used to work out the height of the component.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: number of lines.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: number of lines. |
| NODE_TEXT_INPUT_SHOW_KEYBOARD_ON_FOCUS      | @brief Sets whether to show the keyboard when the text box obtains focus. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: whether to show the keyboard when the text box obtains focus.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: whether to show the keyboard when the text box obtains focus. |
| NODE_TEXT_AREA_PLACEHOLDER                  | Defines the default placeholder text for the multi-line text box. The attribute setting, attribute resetting, and attribute obtaining interfaces are supported.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.string: default placeholder text.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string: default placeholder text. |
| NODE_TEXT_AREA_TEXT                         | Defines the default text content for the multi-line text box. The attribute setting, attribute resetting, and attribute obtaining interfaces are supported.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.string: default text content.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string: default text content. |
| NODE_TEXT_AREA_MAX_LENGTH                   | Defines the maximum number of characters in the text input. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: maximum number of characters in the text input.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: maximum number of characters in the text input. |
| NODE_TEXT_AREA_PLACEHOLDER_COLOR            | Defines the placeholder text color. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].u32: color value, in 0xARGB format. For example, 0xFFFF0000 indicates red.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].u32: color value, in 0xARGB format. |
| NODE_TEXT_AREA_PLACEHOLDER_FONT             | Defines the placeholder text font. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0]? .f32: font size, in fp. Optional. The default value is 16.0.<br>.value[1]? .i32: optional font style [ArkUI_FontStyle](#arkui_fontstyle). The default value is ARKUI_FONT_STYLE_NORMAL.<br>.value[2]? .i32: optional font weight style [ArkUI_FontWeight](#arkui_fontweight). The default value is ARKUI_FONT_WEIGHT_NORMAL.<br>?.string: font family. Multiple font families are separated by commas (,). For example, "font weight; font family 1, font family 2".<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: font size, in fp.<br>.value[1].i32: font[ArkUI_FontStyle] (#arkui_fontstyle);<br>.value[2].i32: [ArkUI_FontWeight] (#arkui_fontweight);<br>.string: font family. Multiple font families are separated by commas (,). |
| NODE_TEXT_AREA_CARET_COLOR                  | Defines the caret color attribute. APIs are provided for setting, resetting, and obtaining the attribute value.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].u32: background color, in 0xARGB format. For example, 0xFFFF0000 indicates red.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].u32: background color, in 0xARGB format. |
| NODE_TEXT_AREA_EDITING                      | Defines the editable state for the multi-line text box. This attribute can be set as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: whether to remain in the editable state. The value true means to remain in the editable state, and false means to exit the editable state.<br>The format of the attribute obtaining method parameter [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) is as follows:<br>.value[0].i32: whether to remain in the editable state. The value true means to remain in the editable state, and false means to exit the editable state. |
| NODE_TEXT_AREA_TYPE                         | Defines the text box type. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: input box type enumeration [ArkUI_TextAreaType](#arkui_textareatype). The default value is ARKUI_TEXTAREA_TYPE_NORMAL.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: input box type enumeration [ArkUI_TextAreaType](#arkui_textareatype). |
| NODE_TEXT_AREA_SHOW_COUNTER                 | @brief Defines the counter settings. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: whether to show a character counter. The value true means to show a character counter.<br>.value[1]? .f32: threshold percentage for displaying the character counter. The character counter is displayed when the number of characters that have been entered is greater than the maximum number of characters multiplied by the threshold percentage value. The value range is 1 to 100. If the value is a decimal, it is rounded down.<br>.value[2]? .i32: whether to highlight the border when the number of entered characters reaches the maximum.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: whether to show a character counter.<br>.value[1].f32: threshold percentage for displaying the character counter. The character counter is displayed when the number of characters that have been entered is greater than the maximum number of characters multiplied by the threshold percentage value. The value range is 1 to 100.<br>.value[2].i32: whether to highlight the border when the number of entered characters reaches the maximum. The default value is true. |
| NODE_TEXT_AREA_SELECTION_MENU_HIDDEN        | @brief Sets whether to hide the text selection menu when the text box is long-pressed, double-click, or right-clicked. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: whether to hide the text selection menu when the text box is long-pressed, double-click, or right-clicked. The default value is false.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: whether to hide the text selection menu when the text box is long-pressed, double-click, or right-clicked. |
| NODE_TEXT_AREA_BLUR_ON_SUBMIT               | @brief Sets whether the multi-line text box loses focus after the Enter key is pressed to submit information.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: whether the text box loses focus.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: whether the text box loses focus. |
| NODE_TEXT_AREA_INPUT_FILTER                 | Sets the regular expression for input filtering. Only inputs that comply with the regular expression can be displayed. Other inputs are filtered out. The specified regular expression can match single characters, but not strings.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.string: regular expression.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string: regular expression. |
| NODE_TEXT_AREA_SELECTED_BACKGROUND_COLOR    | @brief Sets the background color of the selected text. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].u32: color value, in 0xARGB format. For example, 0xFFFF0000 indicates red.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].u32: color value, in 0xARGB format. |
| NODE_TEXT_AREA_ENTER_KEY_TYPE               | @brief Defines the type of the Enter key. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: Enter key type enumeration [ArkUI_EnterKeyType](#arkui_enterkeytype). The default value is ARKUI_ENTER_KEY_TYPE_DONE.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: [ArkUI_EnterKeyType] (#arkui_enterkeytype) |
| NODE_TEXT_AREA_ENABLE_KEYBOARD_ON_FOCUS     | @brief Sets whether to enable the input method when the multi-line text box obtains focus in a way other than clicking. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: whether to enable the input method when the multi-line text box obtains focus in a way other than clicking. The value true means to enable the input method, and false means the opposite. The default value is false.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br> .value[0].i32: The value 1 means to enable the input method when the component obtains focus, and 0 means the opposite. |
| NODE_TEXT_AREA_CARET_OFFSET                 | @brief Sets or obtains the caret position.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>Sets the position of the caret. **value**: indicates the length from the start of the string to the position where the input cursor is located.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>Returns the position information of the caret. If this API is called when the cursor position is updated in the current frame, value[0].i32 (index value of the cursor position) does not take effect.<br>value[1].f32: X coordinate of the cursor relative to the text box.<br>value[2].f32: Y coordinate of the cursor relative to the text box. |
| NODE_TEXT_AREA_CONTENT_RECT                 | Position of the edited text area relative to the component and its size.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>value[0].f32: horizontal coordinate.<br>value[1].f32: vertical coordinate.<br>value[2].f32: content width.<br>value[3].f32: content height. |
| NODE_TEXT_AREA_CONTENT_LINE_COUNT           | Obtains the number of lines of the edited text.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>value[0].i32: number of lines in the edited text. |
| NODE_TEXT_AREA_TEXT_SELECTION               | Sets the text selection range and highlights the selected text when the component is focused. This API works only when the value of **selectionStart** is less than that of **selectionEnd**.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: start position of the text selection. <br>.value[1].i32: end position of the text selection. <br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: start position of the text selection. <br>.value[1].i32: end position of the text selection. |
| NODE_TEXT_AREA_ENABLE_AUTO_FILL             | Sets whether to enable autofill.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: whether to enable autofill. The default value is true.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: whether to enable autofill. |
| NODE_TEXT_AREA_CONTENT_TYPE                 | Enumerates the content types for autofill.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: [ArkUI_TextInputContentType] (#arkui_textinputcontenttype)<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: [ArkUI_TextInputContentType] (#arkui_textinputcontenttype) |
| NODE_TEXT_AREA_NUMBER_OF_LINES              | @brief Sets the number of lines in <TextArea> component, which can be used to work out the height of the component.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: number of lines.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: number of lines. |
| NODE_TEXT_AREA_SHOW_KEYBOARD_ON_FOCUS       | @brief Sets whether to show the keyboard when the text box obtains focus. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: whether to show the keyboard when the text box obtains focus.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: whether to show the keyboard when the text box obtains focus. |
| NODE_BUTTON_LABEL                           | Defines the button text content. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.string: default text content.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string: default text content. |
| NODE_BUTTON_TYPE                            | @brief Sets the button type. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: button style. The parameter type is [ArkUI_ButtonType](#arkui_buttontype). The default value is ARKUI_BUTTON_TYPE_CAPSULE.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: Obtains the style of the button. The parameter type is [ArkUI_ButtonType](#arkui_buttontype). The default value is ARKUI_BUTTON_TYPE_CAPSULE. |
| NODE_PROGRESS_VALUE                         | Defines the current value of the progress indicator. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: current value of the progress indicator.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: current value of the progress indicator. |
| NODE_PROGRESS_TOTAL                         | Defines the total value of the progress indicator. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: total value of the progress indicator.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: total value of the progress indicator. |
| NODE_PROGRESS_COLOR                         | Defines the color for the progress value on the progress indicator. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].u32: color value, in 0xARGB format. For example, 0xFFFF0000 indicates red.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].u32: color value, in 0xARGB format. |
| NODE_PROGRESS_TYPE                          | Defines the type of the progress indicator. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: progress bar type. The enumerated value is [ArkUI_ProgressType](#arkui_progresstype). The default value is ARKUI_PROGRESS_TYPE_LINEAR.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: progress bar type enumeration value [ArkUI_ProgressType](#arkui_progresstype). |
| NODE_CHECKBOX_SELECT                        | Defines whether the check box is selected. This attribute can be set, reset, and obtained as required through APIs.<br>The parameter format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) method is as follows:<br>.value[0].i32: whether the check box is selected. The value 1 means that the check box is selected, and 0 means the opposite.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: whether the check box is selected. The value 1 means that the check box is selected, and 0 means the opposite. |
| NODE_CHECKBOX_SELECT_COLOR                  | Defines the color of the check box when it is selected. This attribute can be set, reset, and obtained as required through APIs.<br>The parameter format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) method is as follows:<br>.value[0].u32: color of the check box when it is selected, in 0xARGB format, for example, 0xFF1122FF.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].u32: color of the check box when it is selected, in 0xARGB format, for example, 0xFF1122FF. |
| NODE_CHECKBOX_UNSELECT_COLOR                | Defines the border color of the check box when it is not selected. This attribute can be set, reset, and obtained as required through APIs.<br>The parameter format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) method is as follows:<br>.value[0].u32: border color, in 0xARGB format, for example, 0xFF1122FF.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].u32: border color, in 0xARGB format, for example, 0xFF1122FF. |
| NODE_CHECKBOX_MARK                          | Defines the internal icon style of the check box. This attribute can be set, reset, and obtained as required through APIs.<br>The parameter format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) method is as follows:<br>.value[0].u32: border color, in 0xARGB format, for example, 0xFF1122FF.<br>.value[1]? .f32: size of the internal mark, in vp. Optional.<br>.value[2]? .f32: stroke width of the internal mark, in vp. Optional. The default value is 2.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].u32: border color, in 0xARGB format, for example, 0xFF1122FF.<br>.value[1].f32: size of the internal mark, in vp. <br>.value[2].f32: stroke width of the internal mark, in vp. The default value is 2. |
| NODE_CHECKBOX_SHAPE                         | Defines the shape of the check box. This attribute can be set, reset, and obtained as required through APIs.<br>The parameter format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) method is as follows:<br>.value[0].i32: component shape. The parameter type is [ArkUI_CheckboxShape](#arkui_checkboxshape).<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: component shape. The parameter type is [ArkUI_CheckboxShape](#arkui_checkboxshape). |
| NODE_XCOMPONENT_ID                          | Defines the ID of the <XComponent> component. This attribute can be set and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.string: component ID.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string: component ID. |
| NODE_XCOMPONENT_TYPE                        | Defines the type of the <XComponent> component. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: font style [ArkUI_XComponentType](#arkui_xcomponenttype). The default value is ARKUI_XCOMPONENT_TYPE_SURFACE.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: [ArkUI_XComponentType] (#arkui_xcomponenttype) |
| NODE_XCOMPONENT_SURFACE_SIZE                | Defines the width and height of the <XComponent> component. This attribute can be set and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].u32: width, in px. <br>.value[1].u32: height, in px. <br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].u32: width, in px. <br>.value[1].u32: height, in px. |
| NODE_DATE_PICKER_LUNAR                      | Defines whether to display the lunar calendar in the date picker. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: whether to display the lunar calendar in the date picker. The default value is false.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: whether to display the lunar calendar in the date picker. |
| NODE_DATE_PICKER_START                      | Defines the start date of the date picker. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.string: date. The default value is "1970-1-1".<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string: date. |
| NODE_DATE_PICKER_END                        | Defines the end date of the date picker. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.string: date. The default value is "2100-12-31".<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string: date. |
| NODE_DATE_PICKER_SELECTED                   | Defines the selected date of the date picker. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.string: date. The default value is "2024-01-22".<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string: date. |
| NODE_DATE_PICKER_DISAPPEAR_TEXT_STYLE       | Defines the font color, font size, and font weight for the top and bottom items in the date picker. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.string: array of five parameters of the string type, separated by semicolons (;).<br>Input parameter 1: text color. The value is of the argb type.<br>Input parameter 2: text size, in fp. The value is a number.<br>Parameter 3: font weight. Available options are ("bold", "normal", "bolder", "lighter", "medium", "regular")..<br>Input parameter 4: text font list, which is separated by commas (,).<br>Input parameter 5: text style, string enumeration ("normal", "italic")<br>Example: "#ff182431;14;normal;Arial,HarmonyOS Sans;normal".<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string: array of five parameters of the string type, separated by semicolons (;).<br>Parameter 1: text color,::argb type<br>Parameter 2: text size, in fp. The value is a number.<br>Parameter 3: font weight. Available options are ("bold", "normal", "bolder", "lighter", "medium", "regular")..<br>Parameter 4: text font list, which is separated by commas (,).<br>Parameter 5: text style, string enumeration ("normal", "italic")<br>Example: "#ff182431;14;normal;Arial,HarmonyOS Sans;normal". |
| NODE_DATE_PICKER_TEXT_STYLE                 | Defines the font color, font size, and font weight of all items except the top, bottom, and selected items in the date picker. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.string: array of five parameters of the string type, separated by semicolons (;).<br>Input parameter 1: text color. The value is of the argb type.<br>Input parameter 2: text size, in fp. The value is a number.<br>Parameter 3: font weight. Available options are ("bold", "normal", "bolder", "lighter", "medium", "regular")..<br>Input parameter 4: text font list, which is separated by commas (,).<br>Input parameter 5: text style, string enumeration ("normal", "italic")<br>Example: "#ff182431;14;normal;Arial,HarmonyOS Sans;normal".<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string: array of five parameters of the string type, separated by semicolons (;).<br>Parameter 1: text color,::argb type<br>Parameter 2: text size, in fp. The value is a number.<br>Parameter 3: font weight. Available options are ("bold", "normal", "bolder", "lighter", "medium", "regular")..<br>Parameter 4: text font list, which is separated by commas (,).<br>Parameter 5: text style, string enumeration ("normal", "italic")<br>Example: "#ff182431;14;normal;Arial,HarmonyOS Sans;normal". |
| NODE_DATE_PICKER_SELECTED_TEXT_STYLE        | Defines the font color, font size, and font weight of the selected item in the date picker. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.string: array of five parameters of the string type, separated by semicolons (;).<br>Input parameter 1: text color. The value is of the argb type.<br>Input parameter 2: text size, in fp. The value is a number.<br>Parameter 3: font weight. Available options are ("bold", "normal", "bolder", "lighter", "medium", "regular")..<br>Input parameter 4: text font list, which is separated by commas (,).<br>Input parameter 5: text style, string enumeration ("normal", "italic")<br>Example: "#ff182431;14;normal;Arial,HarmonyOS Sans;normal".<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string: array of five parameters of the string type, separated by semicolons (;).<br>Parameter 1: text color,::argb type<br>Parameter 2: text size, in fp. The value is a number.<br>Parameter 3: font weight. Available options are ("bold", "normal", "bolder", "lighter", "medium", "regular")..<br>Parameter 4: text font list, which is separated by commas (,).<br>Parameter 5: text style, string enumeration ("normal", "italic")<br>Example: "#ff182431;14;normal;Arial,HarmonyOS Sans;normal". |
| NODE_TIME_PICKER_SELECTED                   | Defines the time of the selected item. in the timer picker. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.string: time. The default value is the current system time.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string: time. |
| NODE_TIME_PICKER_USE_MILITARY_TIME          | Defines whether the display time is in 24-hour format. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: whether the display time is in 24-hour format. The default value is false.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: whether the display time is in 24-hour format. |
| NODE_TIME_PICKER_DISAPPEAR_TEXT_STYLE       | Defines the font color, font size, and font weight for the top and bottom items in the time picker. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.string: array of five parameters of the string type, separated by semicolons (;).<br>Input parameter 1: text color. The value is of the argb type.<br>Input parameter 2: text size, in fp. The value is a number.<br>Parameter 3: font weight. Available options are ("bold", "normal", "bolder", "lighter", "medium", "regular")..<br>Input parameter 4: text font list, which is separated by commas (,).<br>Input parameter 5: text style, string enumeration ("normal", "italic")<br>Example: "#ff182431;14;normal;Arial,HarmonyOS Sans;normal".<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string: array of five parameters of the string type, separated by semicolons (;).<br>Parameter 1: text color,::argb type<br>Parameter 2: text size, in fp. The value is a number.<br>Parameter 3: font weight. Available options are ("bold", "normal", "bolder", "lighter", "medium", "regular")..<br>Parameter 4: text font list, which is separated by commas (,).<br>Parameter 5: text style, string enumeration ("normal", "italic")<br>Example: "#ff182431;14;normal;Arial,HarmonyOS Sans;normal". |
| NODE_TIME_PICKER_TEXT_STYLE                 | Defines the font color, font size, and font weight of all items except the top, bottom, and selected items in the time picker. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.string: array of five parameters of the string type, separated by semicolons (;).<br>Input parameter 1: text color. The value is of the argb type.<br>Input parameter 2: text size, in fp. The value is a number.<br>Parameter 3: font weight. Available options are ("bold", "normal", "bolder", "lighter", "medium", "regular")..<br>Input parameter 4: text font list, which is separated by commas (,).<br>Input parameter 5: text style, string enumeration ("normal", "italic")<br>Example: "#ff182431;14;normal;Arial,HarmonyOS Sans;normal".<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string: array of five parameters of the string type, separated by semicolons (;).<br>Parameter 1: text color,::argb type<br>Parameter 2: text size, in fp. The value is a number.<br>Parameter 3: font weight. Available options are ("bold", "normal", "bolder", "lighter", "medium", "regular")..<br>Parameter 4: text font list, which is separated by commas (,).<br>Parameter 5: text style, string enumeration ("normal", "italic")<br>Example: "#ff182431;14;normal;Arial,HarmonyOS Sans;normal". |
| NODE_TIME_PICKER_SELECTED_TEXT_STYLE        | Defines the font color, font size, and font weight of the selected item in the time picker. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.string: array of five parameters of the string type, separated by semicolons (;).<br>Input parameter 1: text color. The value is of the argb type.<br>Input parameter 2: text size, in fp. The value is a number.<br>Parameter 3: font weight. Available options are ("bold", "normal", "bolder", "lighter", "medium", "regular")..<br>Input parameter 4: text font list, which is separated by commas (,).<br>Input parameter 5: text style, string enumeration ("normal", "italic")<br>Example: "#ff182431;14;normal;Arial,HarmonyOS Sans;normal".<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string: array of five parameters of the string type, separated by semicolons (;).<br>Parameter 1: text color,::argb type<br>Parameter 2: text size, in fp. The value is a number.<br>Parameter 3: font weight. Available options are ("bold", "normal", "bolder", "lighter", "medium", "regular")..<br>Parameter 4: text font list, which is separated by commas (,).<br>Parameter 5: text style, string enumeration ("normal", "italic")<br>Example: "#ff182431;14;normal;Arial,HarmonyOS Sans;normal". |
| NODE_TEXT_PICKER_OPTION_RANGE               | Defines the data selection range of the text picker. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: type of the used selector [ArkUI_TextPickerRangeType](#arkui_textpickerrangetype). The default value is ARKUI_TEXTPICKER_RANGETYPE_SINGLE.<br>?.string: string input, whose format varies by picker type.<br>1: single-column picker. The input format is a group of strings separated by semicolons (;).<br>2: multi-column picker. Multiple pairs of plain text strings are supported. The pairs are separated by semicolons (;), and strings within each pair are separated by commas (,).<br>?.object: Object input, whose format varies by picker type.<br>1: A single column supports the image selector. The input structure is [ARKUI_TextPickerRangeContent](_a_r_k_u_i___text_picker_range_content.md).<br>2: multi-column linkage selector. The input structure is [ARKUI_TextPickerCascadeRangeContent](_a_r_k_u_i___text_picker_cascade_range_content.md).<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: [ArkUI_TextPickerRangeType] (#arkui_textpickerrangetype);<br>?.string: string output, whose format varies by picker type.<br>1: single-column picker. The output format is a group of strings separated by semicolons (;).<br>2: multi-column picker. Multiple pairs of plain text strings are supported. The pairs are separated by semicolons (;), and strings within each pair are separated by commas (,).<br>?.string: Object output, whose format varies by picker type.<br>1: A single column supports the image selector. The output structure is [ARKUI_TextPickerRangeContent](_a_r_k_u_i___text_picker_range_content.md).<br>2: multi-column linkage selector. The output structure is [ARKUI_TextPickerCascadeRangeContent](_a_r_k_u_i___text_picker_cascade_range_content.md). |
| NODE_TEXT_PICKER_OPTION_SELECTED            | Defines the index of the default selected item in the data selection range of the text picker. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].u32: index. If there are multiple index values, add them one by one.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].u32: index. If there are multiple index values, add them one by one. |
| NODE_TEXT_PICKER_OPTION_VALUE               | Defines the value of the default selected item in the text picker. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.string: value of the selected item. If there are multiple values, add them one by one and separate them with semicolons (;).<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string: value of the selected item. If there are multiple values, add them one by one and separate them with semicolons (;). |
| NODE_TEXT_PICKER_DISAPPEAR_TEXT_STYLE       | Defines the font color, font size, and font weight for the top and bottom items in the text picker. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.string: array of five parameters of the string type, separated by semicolons (;).<br>Input parameter 1: text color. The value is of the argb type.<br>Input parameter 2: text size, in fp. The value is a number.<br>Parameter 3: font weight. Available options are ("bold", "normal", "bolder", "lighter", "medium", "regular")..<br>Input parameter 4: text font list, which is separated by commas (,).<br>Input parameter 5: text style, string enumeration ("normal", "italic")<br>Example: "#ff182431;14;normal;Arial,HarmonyOS Sans;normal".<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string: array of five parameters of the string type, separated by semicolons (;).<br>Parameter 1: text color,::argb type<br>Parameter 2: text size, in fp. The value is a number.<br>Parameter 3: font weight. Available options are ("bold", "normal", "bolder", "lighter", "medium", "regular")..<br>Parameter 4: text font list, which is separated by commas (,).<br>Parameter 5: text style, string enumeration ("normal", "italic")<br>Example: "#ff182431;14;normal;Arial,HarmonyOS Sans;normal". |
| NODE_TEXT_PICKER_TEXT_STYLE                 | Defines the font color, font size, and font weight for all items except the top, bottom, and selected items in the text picker. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.string: array of five parameters of the string type, separated by semicolons (;).<br>Input parameter 1: text color. The value is of the argb type.<br>Input parameter 2: text size, in fp. The value is a number.<br>Parameter 3: font weight. Available options are ("bold", "normal", "bolder", "lighter", "medium", "regular")..<br>Input parameter 4: text font list, which is separated by commas (,).<br>Input parameter 5: text style, string enumeration ("normal", "italic")<br>Example: "#ff182431;14;normal;Arial,HarmonyOS Sans;normal".<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string: array of five parameters of the string type, separated by semicolons (;).<br>Parameter 1: text color,::argb type<br>Parameter 2: text size, in fp. The value is a number.<br>Parameter 3: font weight. Available options are ("bold", "normal", "bolder", "lighter", "medium", "regular")..<br>Parameter 4: text font list, which is separated by commas (,).<br>Parameter 5: text style, string enumeration ("normal", "italic")<br>Example: "#ff182431;14;normal;Arial,HarmonyOS Sans;normal". |
| NODE_TEXT_PICKER_SELECTED_TEXT_STYLE        | Defines the font color, font size, and font weight for the selected item in the text picker. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.string: array of five parameters of the string type, separated by semicolons (;).<br>Input parameter 1: text color. The value is of the argb type.<br>Input parameter 2: text size, in fp. The value is a number.<br>Parameter 3: font weight. Available options are ("bold", "normal", "bolder", "lighter", "medium", "regular")..<br>Input parameter 4: text font list, which is separated by commas (,).<br>Input parameter 5: text style, string enumeration ("normal", "italic")<br>Example: "#ff182431;14;normal;Arial,HarmonyOS Sans;normal".<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string: array of five parameters of the string type, separated by semicolons (;).<br>Parameter 1: text color. The value is of the argb type.<br>Parameter 2: text size. The value is a number, and the unit is fp.<br>Parameter 3: font weight. Available options are ("bold", "normal", "bolder", "lighter", "medium", "regular")..<br>Parameter 4: text font list, which is separated by commas (,).<br>Parameter 5: text style, string enumeration ("normal", "italic")<br>Example: "#ff182431;14;normal;Arial,HarmonyOS Sans;normal". |
| NODE_TEXT_PICKER_SELECTED_INDEX             | Defines the index of the default selected item in the data selection range of the text picker. This attribute can be set, reset, and obtained as required through APIs.<br>[ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter type. The options are as follows:<br>.value[0...].i32: index of the default item in the data selection range. |
| NODE_TEXT_PICKER_CAN_LOOP                   | Defines whether to support scroll looping for the text picker. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: whether to support scroll looping. The value true means to support scroll looping, and false means the opposite.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>value[0].i32: The value 1 means to support scroll looping, and 0 means the opposite. |
| NODE_TEXT_PICKER_DEFAULT_PICKER_ITEM_HEIGHT | Defines the height of each item in the picker. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>value[0].f32: item height, in vp.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>value[0].f32: item height, in vp. |
| NODE_CALENDAR_PICKER_HINT_RADIUS            | Defines the style of the background in the selected state of the calendar picker. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: radius of the rounded corner of the bottom plate when the calendar is selected. The value range is [0, +∞). The value 0 indicates that the bottom plate style is a right-angle rectangle. The value range is (0, 16), indicating that the bottom plate style is a rounded rectangle. If the value range is [16, +∞), the bottom plate style is round.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: radius of the rounded corner of the bottom plate when the calendar is selected. The value range is [0, +∞). The value 0 indicates that the bottom plate style is a right-angle rectangle. The value range is (0, 16), indicating that the bottom plate style is a rounded rectangle. If the value range is [16, +∞), the bottom plate style is round. |
| NODE_CALENDAR_PICKER_SELECTED_DATE          | Defines the date of the selected item in the calendar picker. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].u32: year of the selected date.<br>.value[1].u32: month of the selected date.<br>.value[2].u32: day of the selected date.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].u32: year of the selected date.<br>.value[1].u32: month of the selected date.<br>.value[2].u32: day of the selected date. |
| NODE_CALENDAR_PICKER_EDGE_ALIGNMENT         | Defines how the calendar picker is aligned with the entry component. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: alignment mode type. The parameter type is [ArkUI_CalendarAlignment](#arkui_calendaralignment).<br>.value[1].f32: offset of the picker relative to the entry component along the x-axis after alignment based on the specified alignment mode.<br>.value[2].f32: offset of the picker relative to the entry component along the y-axis after alignment based on the specified alignment mode.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: alignment mode type. The parameter type is [ArkUI_CalendarAlignment](#arkui_calendaralignment).<br>.value[1].f32: offset of the picker relative to the entry component along the x-axis after alignment based on the specified alignment mode.<br>.value[2].f32: offset of the picker relative to the entry component along the y-axis after alignment based on the specified alignment mode. |
| NODE_CALENDAR_PICKER_TEXT_STYLE             | Defines the font color, font size, and font weight in the entry area of the calendar picker.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0]? .u32: font color of the entry area.<br>.value[1]? .f32: font size of the entry area, in fp.<br>.value[2]? .i32: font weight of the text in the entry area. The parameter type is [ArkUI_FontWeight](#arkui_fontweight).<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].u32: font color of the entry area.<br>.value[1].f32: font size of the entry area, in fp.<br>.value[2].i32: font weight of the text in the entry area. The parameter type is [ArkUI_FontWeight](#arkui_fontweight). |
| NODE_SLIDER_BLOCK_COLOR                     | Defines the color of the slider. This attribute can be set, reset, and obtained as required through APIs.<br>The parameter format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) method is as follows:<br>.value[0].u32: color of the slider, in 0xARGB format, for example, 0xFF1122FF.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].u32: color of the slider, in 0xARGB format, for example, 0xFF1122FF. |
| NODE_SLIDER_TRACK_COLOR                     | Defines the background color of the slider. This attribute can be set, reset, and obtained as required through APIs.<br>The parameter format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) method is as follows:<br>.value[0].u32: background color, in 0xARGB format, for example, 0xFF1122FF.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].u32: background color, in 0xARGB format, for example, 0xFF1122FF. |
| NODE_SLIDER_SELECTED_COLOR                  | Defines the color of the selected part of the slider track. This attribute can be set, reset, and obtained as required through APIs.<br>The parameter format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) method is as follows:<br>.value[0].u32: color of the selected part of the slider track, in 0xARGB format, for example, 0xFF1122FF.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].u32: color of the selected part of the slider track, in 0xARGB format, for example, 0xFF1122FF. |
| NODE_SLIDER_SHOW_STEPS                      | Sets whether to display the step scale value. Attributes can be set, reset, and obtained.<br>The parameter format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) method is as follows:<br>.value[0].i32: whether to display the stepping value. The value 1 means to display the stepping value, and 0 (default value) means the opposite.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: whether to display the stepping value. The value 1 means to display the stepping value, and 0 (default value) means the opposite. |
| NODE_SLIDER_BLOCK_STYLE                     | Defines the slider shape, which can be set, reset, and obtained as required through APIs.<br>The parameter format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) method is as follows:<br>.value[0].i32: shape. [ArkUI_SliderBlockStyle] (#arkui_sliderblockstyle)<br>.string? depending on the shape. Optional.<br>ARKUI_SLIDER_BLOCK_STYLE_IMAGE: image resource of the slider. Example: /pages/common/icon.png.<br>ARKUI_SLIDER_BLOCK_STYLE_SHAPE: custom shape of the slider.<br>There are five types:<br>1. Rectangle:<br>.value[1].i32: cropping type. The parameter type is [ArkUI_ShapeType](#arkui_shapetype), ARKUI_SHAPE_TYPE_RECTANGLE.<br>.value[2].f32: rectangleWidth;<br>.value[3].f32: height of rectangle;<br>.value[4].f32: width of the rounded corner of the rectangle.<br>.value[5].f32: height of the rounded corner of the rectangle.<br>2. Circle:<br>.value[1].i32: cropping type. The parameter type is [ArkUI_ShapeType](#arkui_shapetype), ARKUI_SHAPE_TYPE_CIRCLE.<br>.value[2].f32: circleWidth;<br>.value[3].f32: height of circle;<br>3. Ellipse:<br>.value[1].i32: cropping type. The parameter type is [ArkUI_ShapeType](#arkui_shapetype), ARKUI_SHAPE_TYPE_ELLIPSE.<br>.value[2].f32: ellipse width;<br>.value[3].f32: height of ellipse;<br>4. Path:<br>.value[1].i32: cropping type. The parameter type is [ArkUI_ShapeType](#arkui_shapetype), ARKUI_SHAPE_TYPE_PATH.<br>.value[2].f32: pathwidth;<br>.value[3].f32: pathHeight;<br>.string: command for drawing the path.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: shape. [ArkUI_SliderBlockStyle] (#arkui_sliderblockstyle)<br>.string? depending on the shape. Optional.<br>ARKUI_SLIDER_BLOCK_STYLE_IMAGE: image resource of the slider. Example: /pages/common/icon.png.<br>ARKUI_SLIDER_BLOCK_STYLE_SHAPE: custom shape of the slider.<br>There are five types:<br>1. Rectangle:<br>.value[1].i32: cropping type. The parameter type is [ArkUI_ShapeType](#arkui_shapetype), ARKUI_SHAPE_TYPE_RECTANGLE.<br>.value[2].f32: rectangleWidth;<br>.value[3].f32: height of rectangle;<br>.value[4].f32: width of the rounded corner of the rectangle.<br>.value[5].f32: height of the rounded corner of the rectangle.<br>2. Circle:<br>.value[1].i32: cropping type. The parameter type is [ArkUI_ShapeType](#arkui_shapetype), ARKUI_SHAPE_TYPE_CIRCLE.<br>.value[2].f32: circleWidth;<br>.value[3].f32: height of circle;<br>3. Ellipse:<br>.value[1].i32: cropping type. The parameter type is [ArkUI_ShapeType](#arkui_shapetype), ARKUI_SHAPE_TYPE_ELLIPSE.<br>.value[2].f32: ellipse width;<br>.value[3].f32: height of ellipse;<br>4. Path:<br>.value[1].i32: cropping type. The parameter type is [ArkUI_ShapeType](#arkui_shapetype), ARKUI_SHAPE_TYPE_PATH.<br>.value[2].f32: pathwidth;<br>.value[3].f32: pathHeight;<br>.string: command for drawing the path. |
| NODE_SLIDER_VALUE                           | Defines the current value of the slider. This attribute can be set, reset, and obtained as required through APIs.<br>The parameter format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) method is as follows:<br>.value[0].f32: current value.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: current value. |
| NODE_SLIDER_MIN_VALUE                       | Defines the minimum value of the slider. This attribute can be set, reset, and obtained as required through APIs.<br>The parameter format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) method is as follows:<br>.value[0].f32: minimum value.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: minimum value. |
| NODE_SLIDER_MAX_VALUE                       | Defines the maximum value of the slider. This attribute can be set, reset, and obtained as required through APIs.<br>The parameter format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) method is as follows:<br>.value[0].f32: maximum value.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: maximum value. |
| NODE_SLIDER_STEP                            | Defines the step of the slider. This attribute can be set, reset, and obtained as required through APIs.<br>The parameter format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) method is as follows:<br>.value[0].f32: step. The value range is [0.01, 100].<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: step. The value range is [0.01, 100]. |
| NODE_SLIDER_DIRECTION                       | Defines whether the slider moves horizontally or vertically. This attribute can be set, reset, and obtained as required through APIs.<br>The parameter format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) method is as follows:<br>.value[0].i32: display style. The parameter type is [ArkUI_SliderDirection](#arkui_sliderdirection).<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: display style. The parameter type is [ArkUI_SliderDirection](#arkui_sliderdirection). |
| NODE_SLIDER_REVERSE                         | Defines whether the slider values are reversed. This attribute can be set, reset, and obtained as required through APIs.<br>The parameter format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) method is as follows:<br>.value[0].i32: whether the slider values are reversed. The value 1 means that the slider values are reversed, and 0 means the opposite.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: whether the slider values are reversed. The value 1 means that the slider values are reversed, and 0 means the opposite. |
| NODE_SLIDER_STYLE                           | Defines the style of the slider thumb and track. This attribute can be set, reset, and obtained as required through APIs.<br>The parameter format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) method is as follows:<br>.value[0].i32: display style. The parameter type is [ArkUI_SliderStyle](#arkui_sliderstyle).<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: display style. The parameter type is [ArkUI_SliderStyle](#arkui_sliderstyle). |
| NODE_SLIDER_TRACK_THICKNESS                 | @brief Sets the track thickness of the slider. This attribute can be set, reset, and obtained as required through APIs.<br>The parameter format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) method is as follows:<br>.value[0].f32: track thickness of the slider, in vp. The default value is 4.0 vp when NODE_SLIDER_STYLE is set to ARKUI_SLIDER_STYLE_OUT_SET and 20.0 vp when NODE_SLIDER_STYLE is set to ARKUI_SLIDER_STYLE_IN_SET. <br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: track thickness of the slider, in vp. |
| NODE_RADIO_CHECKED                          | @brief Sets whether the radio button is selected. This attribute can be set, reset, and obtained as required through APIs.<br>The parameter format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) method is as follows:<br>.value[0].i32: whether the radio button is selected. The default value is false. Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: whether the radio button is selected. |
| NODE_RADIO_STYLE                            | @brief Sets the style of the radio button in selected or deselected state. This attribute can be set, reset, and obtained as required through APIs.<br>The parameter format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) method is as follows:<br>.value[0]?.u32: color of the background when the radio button is selected, in 0xARGB format. The default value is 0xFF007DFF.<br>.value[1]?.u32: color of the border when the radio button is deselected, in 0xARGB format. The default value is 0xFF182431.<br>.value[2]?.u32: color of the indicator when the radio button is selected, in 0xARGB format. The default value is 0xFFFFFFFF.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].u32: color of the background when the radio button is selected, in 0xARGB format. The default value is 0xFF007DFF.<br>.value[1].u32: color of the border when the radio button is deselected, in 0xARGB format. The default value is 0xFF182431.<br>.value[2]?.u32: color of the indicator when the radio button is selected, in 0xARGB format. The default value is 0xFFFFFFFF. |
| NODE_RADIO_VALUE                            | @brief Sets the current value of the radio button. This attribute can be set, reset, and obtained as required through APIs.<br>The parameter format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) method is as follows:<br>.string: value of the option button.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string: value of the option button. |
| NODE_RADIO_GROUP                            | @brief Sets the name of the group to which the radio button belongs. Only one radio button in a given group can be selected at a time. This attribute can be set, reset, and obtained as required through APIs.<br>The parameter format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) method is as follows:<br>.string: name of the group to which the radio button belongs. <br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string: name of the group to which the radio button belongs. |
| NODE_STACK_ALIGN_CONTENT                    | Defines the alignment mode of the child components in the container. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: alignment mode. The parameter type is [ArkUI_Alignment](#arkui_alignment). The default value is **ARKUI_ALIGNMENT_CENTER**.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: alignment mode. The data type is [ArkUI_Alignment](#arkui_alignment). |
| NODE_SCROLL_BAR_DISPLAY_MODE                | Defines the scrollbar status. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: scroll bar status. The data type is [ArkUI_ScrollBarDisplayMode](#arkui_scrollbardisplaymode), and the default value is ARKUI_SCROLL_BAR_DISPLAY_MODE_AUTO.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: scroll bar status. The data type is [ArkUI_ScrollBarDisplayMode](#arkui_scrollbardisplaymode). |
| NODE_SCROLL_BAR_WIDTH                       | Defines the width of the scrollbar. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: width of the scrollbar, in vp. The default value is 4.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: width of the scrollbar, in vp. |
| NODE_SCROLL_BAR_COLOR                       | Defines the color of the scrollbar. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.data[0].u32: color of the scrollbar, in 0xARGB format.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.data[0].u32: color of the scrollbar, in 0xARGB format. |
| NODE_SCROLL_SCROLL_DIRECTION                | Defines the scroll direction. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: scrolling direction. The data type is [ArkUI_ScrollDirection](#arkui_scrolldirection), and the default value is ARKUI_SCROLL_DIRECTION_VERTICAL.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: scrolling direction. The data type is [ArkUI_ScrollDirection](#arkui_scrolldirection). |
| NODE_SCROLL_EDGE_EFFECT                     | Defines the effect used at the edges of the component when the boundary of the scrollable content is reached. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: edge sliding effect. The parameter type is [ArkUI_EdgeEffect](#arkui_edgeeffect). The default value is ARKUI_EDGE_EFFECT_NONE.<br>.value[1]? .i32: whether to enable the scroll effect when the component content size is smaller than the component itself. Optional. The value 1 means to enable the scroll effect, and 0 means the opposite. The default value is 1.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: edge sliding effect. The parameter type is [ArkUI_EdgeEffect](#arkui_edgeeffect).<br>.value[1].i32: whether to enable the scroll effect when the component content size is smaller than the component itself. The value 1 means to enable the scroll effect, and 0 means the opposite. |
| NODE_SCROLL_ENABLE_SCROLL_INTERACTION       | Sets whether to support scroll gestures. When this attribute is set to **false**, scrolling by finger or mouse is not supported, but the scroll controller API is not affected.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: whether to support scroll gestures. The default value is true.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: whether to support scroll gestures. |
| NODE_SCROLL_FRICTION                        | Sets the friction coefficient. It applies only to gestures in the scrolling area, and it affects only indirectly the scroll chaining during the inertial scrolling process.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: friction coefficient. The default value is 0.6 for non-wearable devices and 0.9 for wearable devices.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: friction coefficient. |
| NODE_SCROLL_SNAP                            | Defines the scroll snapping mode. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: limit scrolling mode of the scroll component. The data type is [ArkUI_ScrollSnapAlign](#arkui_scrollsnapalign), and the default value is ARKUI_SCROLL_SNAP_ALIGN_NONE.<br>.value[1].i32: whether to enable the snap to start feature. When scroll snapping is defined for the <Scroll> component, setting this attribute to false enables the component to scroll between the start edge and the first snap point. The default value is true. It is valid only when there are multiple snap points.<br>.value[2].i32: Whether to enable the snap to end feature. When scroll snapping is defined for the <Scroll> component, setting this attribute to false enables the component to scroll between the end edge and the last snap point. The default value is true. It is valid only when there are multiple snap points.<br>.value[3...].f32: snap points for the <Scroll> component. Each snap point defines the offset from an edge to which the <Scroll> component can scroll. The value can be one or more.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: limit scrolling mode of the scroll component. The data type is [ArkUI_ScrollSnapAlign](#arkui_scrollsnapalign).<br>.value[1].i32: whether to enable the snap to start feature. When scroll snapping is defined for the <Scroll> component, setting this attribute to false enables the component to scroll between the start edge and the first snap point.<br>.value[2].i32: Whether to enable the snap to end feature. When scroll snapping is defined for the <Scroll> component, setting this attribute to false enables the component to scroll between the end edge and the last snap point.<br>.value[3...].f32: snap points for the <Scroll> component. Each snap point defines the offset from an edge to which the <Scroll> component can scroll. |
| NODE_SCROLL_NESTED_SCROLL                   | Defines the nested scrolling options. This attribute can be set, reset, and obtained as required through APIs.<br>The parameter format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) method is as follows:<br>.value[0].i32: nested scrolling when the scrollable component scrolls to the end. The parameter type is [ArkUI_ScrollNestedMode](#arkui_scrollnestedmode).<br>.value[1].i32: nested scrolling when the scrollable component scrolls to the start end. The parameter type is [ArkUI_ScrollNestedMode](#arkui_scrollnestedmode).<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: nested scrolling when the scrollable component scrolls to the end. The parameter type is [ArkUI_ScrollNestedMode](#arkui_scrollnestedmode).<br>.value[1].i32: nested scrolling when the scrollable component scrolls to the start end. The parameter type is [ArkUI_ScrollNestedMode](#arkui_scrollnestedmode). |
| NODE_SCROLL_OFFSET                          | Defines the specified position to scroll to. This attribute can be set, reset, and obtained as required through APIs.<br>The parameter format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) method is as follows:<br>.value[0].f32: horizontal scrolling offset, in vp.<br>.value[1].f32: vertical scrolling offset, in vp.<br>.value[2]?.i32: scrolling duration, in milliseconds. Optional.<br>.value[3]? .i32: (optional) scrolling curve. The parameter type is [ArkUI_AnimationCurve](#arkui_animationcurve). The default value is ARKUI_CURVE_EASE.<br>.value[4]?.i32: whether to enable the default spring animation. Optional. The default value 0 means not to enable the default spring animation.<br>.value[5]?.i32: whether to enable overscroll. Optional.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: horizontal scrolling offset, in vp.<br>.value[1].f32: vertical scrolling offset, in vp. |
| NODE_SCROLL_EDGE                            | @brief Defines the edge position to scroll to. This attribute can be set and obtained as required through APIs.<br>The parameter format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) method is as follows:<br>.value[0].i32: container edge. The parameter type is [ArkUI_ScrollEdge](#arkui_scrolledge).<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: indicates whether the container is on the edge. The value -1 indicates that the container is not on the edge. If the container is on the edge, the status parameter type is [ArkUI_ScrollEdge](#arkui_scrolledge). |
| NODE_SCROLL_ENABLE_PAGING                   | Defines whether to enable the swipe-to-turn-pages feature. This attribute can be set, reset, and obtained as required through APIs.<br>If both **enablePaging** and **scrollSnap** are set, **scrollSnap** takes effect, but **enablePaging** does not.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: whether to enable the swipe-to-turn-pages feature. The default value is false.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: whether to enable the swipe-to-turn-pages feature. |
| NODE_SCROLL_PAGE                            | Scrolls to the next or previous page.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: whether to scroll to the next page. The value 1 means to scroll to the next page, and 0 means to scroll to the previous page.<br>.value[1]?.i32: whether to enable the page turning animation. The value 1 means to enable the page turning animation, and 0 means the opposite. Default value: **0** |
| NODE_SCROLL_BY                              | Scrolls by the specified amount.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: amount to scroll by in the horizontal direction, in vp. <br>.value[1].f32: amount to scroll by in the vertical direction, in vp. |
| NODE_LIST_DIRECTION                         | Defines the direction in which the list items are arranged. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: List component arrangement direction. The data type is [ArkUI_Axis](#arkui_axis). The default value is ARKUI_AXIS_VERTICAL.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: List component arrangement direction. The data type is [ArkUI_Axis](#arkui_axis). |
| NODE_LIST_STICKY                            | This interface is used together with the ListItemGroup component to set whether the header and footer in the ListItemGroup need to be ceiling-mounted or bottom-mounted. The attribute setting, attribute resetting, and attribute obtaining interfaces are supported.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: whether to pin the header to the top or the footer to the bottom in the <ListItemGroup> component. It is used together with the <ListItemGroup> component. Data type [ArkUI_StickyStyle](#arkui_stickystyle). The default value is ARKUI_STICKY_STYLE_NONE.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: whether to pin the header to the top or the footer to the bottom in the <ListItemGroup> component. It is used together with the <ListItemGroup> component. Data type [ArkUI_StickyStyle](#arkui_stickystyle). |
| NODE_LIST_SPACE                             | Defines the spacing between list items. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: spacing between list items along the main axis. The default value is 0.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: spacing between list items along the main axis. |
| NODE_LIST_NODE_ADAPTER                      | @brief Defines the list adapter. The attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.object: {@link ArkUI_NodeAdapter} object as the adapter.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.object: The format of the return value is ArkUI_NodeAdapter. |
| NODE_LIST_CACHED_COUNT                      | @brief Sets the number of cached items in the list adapter. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: number of cached items in the list adapter. <br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: number of cached items in the list adapter. |
| NODE_LIST_SCROLL_TO_INDEX                   | Slide to the specified index.<br>When **smooth** is set to **true**, all passed items are loaded and counted in layout calculation. This may result in performance issues if a large number of items are involved.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: index of the item to be scrolled to in the container.<br>.value[1]?.i32: whether to enable the smooth animation for scrolling to the item with the specified index. The value 1 means to enable the animation, and 0 means the opposite. Default value: 0.<br>.value[2]? .i32: alignment mode between the sliding element and the current container. The parameter type is [ArkUI_ScrollAlignment](#arkui_scrollalignment). The default value is ARKUI_SCROLL_ALIGNMENT_START. |
| NODE_LIST_ALIGN_LIST_ITEM                   | Sets the layout mode of list items in the list cross axis direction when the width of the list cross axis direction is greater than the width of the list item cross axis\*lanes. The interfaces for setting, resetting, and obtaining attributes are supported.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: alignment mode of list items along the cross axis. Type ArkUI_ListItemAlign<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: alignment mode of list items along the cross axis. Type ArkUI_ListItemAlign |
| NODE_LIST_CHILDREN_MAIN_SIZE                | Sets the default spindle size of the List child component.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>object: The parameter format is {\@ArkUI_ListChildrenMainSize}.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.object: The parameter format is {\@ArkUI_ListChildrenMainSize}. |
| NODE_SWIPER_LOOP                            | Defines whether to enable loop playback for the swiper. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: whether to enable loop playback. The value 1 means to enable loop playback, and 0 means the opposite. The default value is 1.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: whether to enable loop playback. The value 1 means to enable loop playback, and 0 means the opposite. The default value is 1. |
| NODE_SWIPER_AUTO_PLAY                       | Defines whether to enable automatic playback for child component switching in the swiper. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: whether to enable automatic playback for child component switching. The value 1 means to enable automatic playback, and 0 means the opposite. The default value is 0.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: whether to enable automatic playback for child component switching. The value 1 means to enable automatic playback, and 0 means the opposite. The default value is 0. |
| NODE_SWIPER_SHOW_INDICATOR                  | Defines whether to enable the navigation point indicator for the swiper. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: whether to enable the navigation point indicator. The value 1 means to enable the navigation point indicator, and 0 means the opposite. The default value is 1.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: whether to enable the navigation point indicator. The value 1 means to enable the navigation point indicator, and 0 means the opposite. The default value is 1. |
| NODE_SWIPER_INTERVAL                        | Defines the interval for automatic playback. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: interval for automatic playback, in milliseconds.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: interval for automatic playback, in milliseconds. |
| NODE_SWIPER_VERTICAL                        | Defines whether vertical swiping is used for the swiper. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: whether vertical swiping is used. The value 1 means that vertical swiping is used, and 0 means the opposite. The default value is 0.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: whether vertical swiping is used. The value 1 means that vertical swiping is used, and 0 means the opposite. The default value is 0. |
| NODE_SWIPER_DURATION                        | Defines the duration of the animation for switching child components. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: duration of the animation for switching child components, in milliseconds. The default value is 400.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: duration of the animation for switching child components, in milliseconds. The default value is 400. |
| NODE_SWIPER_CURVE                           | Defines the animation curve for the swiper. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: Sets the animation curve parameter. The parameter type is [ArkUI_AnimationCurve](#arkui_animationcurve). The default value is ARKUI_CURVE_LINEAR.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: Sets the animation curve parameter. The parameter type is [ArkUI_AnimationCurve](#arkui_animationcurve). The default value is ARKUI_CURVE_LINEAR. |
| NODE_SWIPER_ITEM_SPACE                      | Defines the spacing between child components in the swiper. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: spacing between child components.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: spacing between child components. |
| NODE_SWIPER_INDEX                           | Defines the index of the child component currently displayed in the swiper. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: number of elements to display per page.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: number of elements to display per page. |
| NODE_SWIPER_DISPLAY_COUNT                   | Defines the number of elements to display per page. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: number of elements to display per page.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: number of elements to display per page. |
| NODE_SWIPER_DISABLE_SWIPE                   | This interface is used to disable the sliding switching function of the Swiper component. The attribute setting, attribute resetting, and attribute obtaining interfaces are supported.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: whether to disable the swipe feature. The value 1 means to disable the swipe feature, and 0 means the opposite. The default value is 0.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: whether to disable the swipe feature. The value 1 means to disable the swipe feature, and 0 means the opposite. The default value is 0. |
| NODE_SWIPER_SHOW_DISPLAY_ARROW              | Defines whether to show the arrow when the mouse pointer hovers over the navigation point indicator. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: indicates whether to display the navigation arrow. The parameter type is [ArkUI_SwiperArrow](#arkui_swiperarrow).<br>The default value is ARKUI_SWIPER_ARROW_HIDE.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: indicates whether to display the navigation arrow. The parameter type is [ArkUI_SwiperArrow](#arkui_swiperarrow).<br>The default value is ARKUI_SWIPER_ARROW_HIDE. |
| NODE_SWIPER_EDGE_EFFECT_MODE                | @brief Defines the effect used at the edges of the swiper when the boundary of the scrollable content is reached. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: edge sliding effect. The parameter type is [ArkUI_EdgeEffect](#arkui_edgeeffect).<br>The default value is ARKUI_EDGE_EFFECT_SPRING.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: edge sliding effect. The parameter type is [ArkUI_EdgeEffect](#arkui_edgeeffect). |
| NODE_SWIPER_NODE_ADAPTER                    | @brief Defines the swiper adapter. The attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.object: {@link ArkUI_NodeAdapter} object as the adapter.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.object: The format of the return value is ArkUI_NodeAdapter. |
| NODE_SWIPER_CACHED_COUNT                    | @brief Sets the number of cached items in the swiper adapter. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: number of cached items in the swiper adapter. <br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: number of cached items in the list adapter. |
| NODE_SWIPER_PREV_MARGIN                     | @brief Sets the previous margin of the swiper. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: previous margin, in vp. The default value is 0.<br>.value[1].i32: whether to ignore blank areas. The value 1 means to ignore blank areas, and 0 means the opposite.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: previous margin, in vp. .value[1].i32: whether to ignore blank areas. The value 1 means to ignore blank areas, and 0 means the opposite. |
| NODE_SWIPER_NEXT_MARGIN                     | @brief Sets the next margin of the swiper. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: next margin, in vp. The default value is 0.<br>.value[1].i32: whether to ignore blank areas. The value 1 means to ignore blank areas, and 0 means the opposite.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: next margin, in vp. .value[1].i32: whether to ignore blank areas. The value 1 means to ignore blank areas, and 0 means the opposite. |
| NODE_SWIPER_INDICATOR                       | Sets the navigation indicator type of the Swiper component. The attribute setting, attribute resetting, and attribute obtaining interfaces are supported.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: navigation indicator type. The parameter type is [ArkUI_SwiperIndicatorType](#arkui_swiperindicatortype).<br>.object: The parameter type is [ArkUI_SwiperIndicator](#arkui_swiperindicator).<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: navigation indicator type. The parameter type is [ArkUI_SwiperIndicatorType](#arkui_swiperindicatortype).<br>.object: The parameter type is [ArkUI_SwiperIndicator](#arkui_swiperindicator). |
| NODE_SWIPER_NESTED_SCROLL                   | Sets the nested scrolling mode of the **\<Swiper>** component and its parent container.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: nested scrolling mode of the Swiper component and parent component. The parameter type is [ArkUI_SwiperNestedScrollMode](#arkui_swipernestedscrollmode).<br>Default value: ARKUI_SWIPER_NESTED_SRCOLL_SELF_ONLY<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: nested scrolling mode of the Swiper component and parent component. The parameter type is [ArkUI_SwiperNestedScrollMode](#arkui_swipernestedscrollmode). |
| NODE_SWIPER_SWIPE_TO_INDEX                  | @brief Sets the swiper to switch to the specified page.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: index of the target page in the swiper.<br>.value[1]? .i32: indicates whether the specified page takes effect. The value 1 indicates that the dynamic effect is enabled, and the value 0 indicates that the dynamic effect is disabled. The default value is 0. |
| NODE_LIST_ITEM_GROUP_SET_HEADER             | Defines the header of the list item group. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.object: Use the [ArkUI_NodeHandle](#arkui_nodehandle) object as the ListItemGroup header component.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.object: Use the [ArkUI_NodeHandle](#arkui_nodehandle) object as the ListItemGroup header component. |
| NODE_LIST_ITEM_GROUP_SET_FOOTER             | Defines the footer of the list item group. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.object: Use the [ArkUI_NodeHandle](#arkui_nodehandle) object as the tail component of ListItemGroup.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.object: Use the [ArkUI_NodeHandle](#arkui_nodehandle) object as the tail component of ListItemGroup. |
| NODE_LIST_ITEM_GROUP_SET_DIVIDER            | Defines the style of the divider for the list items. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].u32: color of the divider, in 0xARGB format.<br>.value[1].f32: stroke width of the divider, in vp.<br>.value[2].f32: distance between the divider and the start of the list, in vp.<br>.value[3].f32: distance between the divider and the end of the list, in vp.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].u32: color of the divider, in 0xARGB format.<br>.value[1].f32: stroke width of the divider, in vp.<br>.value[2].f32: distance between the divider and the start of the list, in vp.<br>.value[3].f32: distance between the divider and the end of the list, in vp. |
| NODE_LIST_ITEM_GROUP_CHILDREN_MAIN_SIZE     | Sets the default spindle size of the ListItemGroup child component.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>object: The parameter format is {\@ArkUI_ListChildrenMainSize}.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.object: The parameter format is {\@ArkUI_ListChildrenMainSize}. |
| NODE_COLUMN_ALIGN_ITEMS                     | @brief Defines the horizontal alignment mode of child components in the column. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: horizontal alignment format of a child component. The data type is [ArkUI_HorizontalAlignment](#arkui_horizontalalignment).<br>Default value: ARKUI_HORIZONTAL_ALIGNMENT_CENTER.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: horizontal alignment format of a child component. The data type is [ArkUI_HorizontalAlignment](#arkui_horizontalalignment). |
| NODE_COLUMN_JUSTIFY_CONTENT                 | @brief Defines the vertical alignment mode of child components in the column. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: vertical alignment format of the child component. The data type is [ArkUI_FlexAlignment](#arkui_flexalignment).<br>Default value: ARKUI_FLEX_ALIGNMENT_START.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: vertical alignment format of a child component. The data type is [ArkUI_FlexAlignment](#arkui_flexalignment). |
| NODE_ROW_ALIGN_ITEMS                        | @brief Defines the vertical alignment mode of child components in the row. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: vertical alignment format of a child component. The data type is [ArkUI_VerticalAlignment](#arkui_verticalalignment).<br>Default value: ARKUI_VERTICAL_ALIGNMENT_CENTER.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: vertical alignment format of a child component. The data type is [ArkUI_VerticalAlignment](#arkui_verticalalignment). |
| NODE_ROW_JUSTIFY_CONTENT                    | @brief Defines the horizontal alignment mode of child components in the row. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: horizontal alignment format of a child component. The data type is [ArkUI_FlexAlignment](#arkui_flexalignment).<br>Default value: ARKUI_FLEX_ALIGNMENT_START.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: horizontal alignment format of a child component. The data type is [ArkUI_FlexAlignment](#arkui_flexalignment). |
| NODE_FLEX_OPTION                            | Defines the opacity attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0]? .i32: arrangement direction of child components on the Flex container [ArkUI_FlexDirection](#arkui_flexdirection). The default value is ARKUI_FLEX_DIRECTION_ROW.<br>.value[1]? .i32: arrangement rule [ArkUI_FlexWrap](#arkui_flexwrap). The default value is ARKUI_FLEX_WRAP_NO_WRAP.<br>.value[2]? .i32: alignment format on the principal axis [ArkUI_FlexAlignment](#arkui_flexalignment). The default value is ARKUI_FLEX_ALIGNMENT_START.<br>.value[3]? .i32: alignment format on the cross axis [ArkUI_ItemAlignment](#arkui_itemalignment). The default value is ARKUI_ITEM_ALIGNMENT_START.<br>.value[4]? .i32: alignment mode of multiple lines when there is extra space in the cross axis [ArkUI_FlexAlignment](#arkui_flexalignment). The default value is ARKUI_FLEX_ALIGNMENT_START.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: direction in which flex items are arranged. <br>.value[1].i32: how the flex items are wrapped. <br>.value[2].i32: alignment mode along the main axis. <br>.value[3].i32: alignment mode along the cross axis. <br>.value[4].i32: alignment mode along the cross axis for multi-line content. |
| NODE_REFRESH_REFRESHING                     | Sets whether a component is being refreshed. Attributes can be set and obtained.<br>The parameter format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) method is as follows:<br>value[0].i32: The parameter type is 1 or 0.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>value[0].i32: The parameter type is 1 or 0. |
| NODE_REFRESH_CONTENT                        | @brief Sets the custom content in the pull-down area. This attribute can be set, reset, and obtained as required through APIs.<br>The parameter format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) method is as follows:<br>.object: The parameter type is {@Link ArkUI_NodeHandle}. |
| NODE_REFRESH_PULL_DOWN_RATIO                | Sets the pull-down and hand coefficients. The interfaces for setting, resetting, and obtaining attributes are supported.<br>The parameter format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) method is as follows:<br>.value[0].f32: pull-down ratio. The value is in the range from 0 to 1.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: pull-down ratio. The value is in the range from 0 to 1. |
| NODE_WATER_FLOW_LAYOUT_DIRECTION            | Defines the main axis direction of the waterfall component layout. Attributes can be set, reset, and obtained.<br>The parameter format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) method is as follows:<br>.value[0].i32: main axis direction. The parameter type is {@Link ArkUI_FlexDirection}.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: main axis direction. The parameter type is {@Link ArkUI_FlexDirection}. |
| NODE_WATER_FLOW_COLUMN_TEMPLATE             | @brief Sets the number of columns in the water flow layout. If this parameter is not set, one column is used by default. This attribute can be set, reset, and obtained as required through APIs. For example, '1fr 1fr 2fr' indicates three columns, with the first column taking up 1/4 of the parent component's full width, the second column 1/4, and the third column 2/4. You can use **rowsTemplate('repeat(auto-fill,track-size)')** to automatically calculate the number of rows based on the specified row height **track-size**. **repeat** and **auto-fill** are keywords. The units for **track-size** can be px, vp (default), %, or a valid number.<br>The parameter format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) method is as follows:<br>.string: number of layout columns.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string: number of layout columns. |
| NODE_WATER_FLOW_ROW_TEMPLATE                | @brief Sets the number of rows in the water flow layout. If this parameter is not set, one row is used by default. This attribute can be set, reset, and obtained as required through APIs. For example, '1fr 1fr 2fr' indicates three rows, with the first row taking up 1/4 of the parent component's full height, the second row 1/4, and the third row 2/4. You can use **rowsTemplate('repeat(auto-fill,track-size)')** to automatically calculate the number of rows based on the specified row height **track-size**. **repeat** and **auto-fill** are keywords. The units for **track-size** can be px, vp (default), %, or a valid number.<br>The parameter format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) method is as follows:<br>.string: number of layout rows.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string: number of layout rows. |
| NODE_WATER_FLOW_COLUMN_GAP                  | @brief Sets the gap between columns. This attribute can be set, reset, and obtained as required through APIs.<br>The parameter format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) method is as follows:<br>.value[0].f32: gap between columns, in vp.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: gap between columns, in vp. |
| NODE_WATER_FLOW_ROW_GAP                     | @brief Sets the gap between rows. This attribute can be set, reset, and obtained as required through APIs.<br>The parameter format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) method is as follows:<br>.value[0].f32: gap between lines, in vp.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: gap between lines, in vp. |
| NODE_WATER_FLOW_SECTION_OPTION              | @brief Defines the water flow section configuration. This attribute can be set, reset, and obtained as required through APIs.<br>The parameter format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) method is as follows:<br>.value[0].i32: zero-based index of the water flow item section to update. The value is converted to an integer. <br>.object: The parameter format is {\@ArkUI_WaterFlowSectionOption}.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.object: The format of the return value is {\@ArkUI_WaterFlowSectionOption}. |
| NODE_WATER_FLOW_NODE_ADAPTER                | @brief Defines the water flow adapter. The attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.object: {@link ArkUI_NodeAdapter} object as the adapter.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.object: The format of the return value is ArkUI_NodeAdapter. |
| NODE_WATER_FLOW_CACHED_COUNT                | @brief Sets the number of cached items in the water flow adapter. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: number of cached items in the water flow adapter. |
| NODE_LIST_ITEM_SWIPE_ACTION                 | @brief Sets the swipe action item displayed when the list item is swiped out from the screen edge. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.object: constructed using the [ArkUI_ListItemSwipeActionOption](#arkui_listitemswipeactionoption) object.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.object: constructed using the [ArkUI_ListItemSwipeActionOption](#arkui_listitemswipeactionoption) object. |
| NODE_WATER_FLOW_ITEM_CONSTRAINT_SIZE        | @brief Defines the size constraints to apply to water flow items. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: minimum width. The value -1 indicates that the minimum width is not set. <br>.value[1].f32: maximum width. The value -1 indicates that the maximum width is not set. <br>.value[2].f32: minimum height. The value -1 indicates that the minimum height is not set. <br>.value[3].f32: maximum height. The value -1 indicates that the maximum height is not set. <br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: minimum width. The value -1 indicates that the minimum width is not set. <br>.value[1].f32: maximum width. The value -1 indicates that the maximum width is not set. <br>.value[2].f32: minimum height. The value -1 indicates that the minimum height is not set. <br>.value[3].f32: maximum height. The value -1 indicates that the maximum height is not set. |
| NODE_WATER_FLOW_FOOTER                      | Set the custom display widget at the end of the waterfall widget.<br>The parameter format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) method is as follows:<br>.object: [ArkUI_NodeHandle] (#arkui_nodehandle) |
| NODE_WATER_FLOW_SCROLL_TO_INDEX             | Slide to the specified index.<br>When **smooth** is set to **true**, all passed items are loaded and counted in layout calculation. This may result in performance issues if a large number of items are involved.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: index of the item to be scrolled to in the container.<br>.value[1]?.i32: whether to enable the smooth animation for scrolling to the item with the specified index. The value 1 means to enable the animation, and 0 means the opposite. Default value: 0.<br>.value[2]? .i32: alignment mode between the sliding element and the current container. The parameter type is [ArkUI_ScrollAlignment](#arkui_scrollalignment). The default value is ARKUI_SCROLL_ALIGNMENT_START. |
| NODE_RELATIVE_CONTAINER_GUIDE_LINE          | @brief Sets the guideline in the <RelativeContainer>. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.object: guideline in the <RelativeContainer>. <br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.object: guideline in the <RelativeContainer>. |
| NODE_RELATIVE_CONTAINER_BARRIER             | @brief Sets the barrier in the <RelativeContainer>. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.object: guideline in the <RelativeContainer>. <br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.object: barrier in RelativeContaine container: |
| NODE_GRID_COLUMN_TEMPLATE                   | @brief Sets the number of columns in the water flow layout. If this parameter is not set, one column is used by default. This attribute can be set, reset, and obtained as required through APIs. For example, '1fr 1fr 2fr' indicates three columns, with the first column taking up 1/4 of the parent component's full width, the second column 1/4, and the third column 2/4. You can use **rowsTemplate('repeat(auto-fill,track-size)')** to automatically calculate the number of rows based on the specified row height **track-size**. **repeat** and **auto-fill** are keywords. The units for **track-size** can be px, vp (default), %, or a valid number.<br>The parameter format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) method is as follows:<br>.string: number of layout columns.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string: number of layout columns. |
| NODE_GRID_ROW_TEMPLATE                      | @brief Sets the number of rows or the minimum row height in the grid layout. If this parameter is not set, one row is used by default. This attribute can be set, reset, and obtained as required through APIs. For example, '1fr 1fr 2fr' indicates three rows, with the first row taking up 1/4 of the parent component's full height, the second row 1/4, and the third row 2/4. You can use **rowsTemplate('repeat(auto-fill,track-size)')** to automatically calculate the number of rows based on the specified row height **track-size**. **repeat** and **auto-fill** are keywords. The units for **track-size** can be px, vp (default), %, or a valid number.<br>The parameter format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) method is as follows:<br>.string: number of layout rows.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string: number of layout rows. |
| NODE_GRID_COLUMN_GAP                        | @brief Sets the gap between columns. This attribute can be set, reset, and obtained as required through APIs.<br>The parameter format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) method is as follows:<br>.value[0].f32: gap between columns, in vp.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: gap between columns, in vp. |
| NODE_GRID_ROW_GAP                           | @brief Sets the gap between rows. This attribute can be set, reset, and obtained as required through APIs.<br>The parameter format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) method is as follows:<br>.value[0].f32: gap between lines, in vp.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: gap between lines, in vp. |
| NODE_GRID_NODE_ADAPTER                      | @brief Defines the grid adapter. The attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.object: {@link ArkUI_NodeAdapter} object as the adapter.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.object: The format of the return value is ArkUI_NodeAdapter. |
| NODE_GRID_CACHED_COUNT                      | @brief Sets the number of cached items in the grid adapter. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: number of cached items in the water flow adapter. |
| NODE_IMAGE_ANIMATOR_IMAGES                  | Sets the image frame information set of the frame animation component. Dynamic update is not supported. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.size: number of image frames;<br>.object: image frame array. The parameter type is {@link ArkUI_ImageAnimatorFrameInfo}. <br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.size: number of image frames;<br>.object: image frame array. The parameter type is {@link ArkUI_ImageAnimatorFrameInfo}. |
| NODE_IMAGE_ANIMATOR_STATE                   | @brief Sets the playback status of the frame-by-frame animation. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: controls the playing status of the animation. The parameter type is [ArkUI_AnimationStatus](#arkui_animationstatus). The default value is the initial status.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: controls the playing status of the animation. The parameter type is [ArkUI_AnimationStatus](#arkui_animationstatus). |
| NODE_IMAGE_ANIMATOR_DURATION                | @brief Sets the playback duration of the frame-by-frame animation. This attribute does not take effect when a separate duration is set for any of the image frames. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: playback duration, in milliseconds. The default value is 1000.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: playback duration, in milliseconds. The default value is 1000. |
| NODE_IMAGE_ANIMATOR_REVERSE                 | @brief Sets the playback direction of the frame-by-frame animation. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: playback direction. The value 0 indicates that images are played from the first one to the last one, and 1 indicates that images are played from the last one to the first one. The default value is 0.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: playback direction. The value 0 indicates that images are played from the first one to the last one, and 1 indicates that images are played from the last one to the first one. |
| NODE_IMAGE_ANIMATOR_FIXED_SIZE              | Whether the image size is fixed at the component size.<br> This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: whether the image size is the fixed at the component size. The value 1 indicates that the image size is fixed at the component size. The value 0 indicates that the width, height, top, and left attributes of each image must be set separately. The default value is 1.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: whether the image size is the fixed at the component size. The value 1 indicates that the image size is fixed at the component size. The value 0 indicates that the width, height, top, and left attributes of each image must be set separately. |
| NODE_IMAGE_ANIMATOR_FILL_MODE               | @brief Sets the status before and after execution of the frame-by-frame animation in the current playback direction. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: status before and after execution of the frame-by-frame animation in the current playback direction. The parameter type is {@link ArkUI_AnimationFillMode}. The default value is FORWARDS.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: status before and after execution of the frame-by-frame animation in the current playback direction. The parameter type is {@link ArkUI_AnimationFillMode}. |
| NODE_IMAGE_ANIMATOR_ITERATION               | Number of times that the frame animation is played. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: number of times that the animation is played.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: number of times that the animation is played. |

### ArkUI_NodeCustomEventType

```
enum ArkUI_NodeCustomEventType
```
**Description**

Enumerates the custom component event types.

**Since**: 12

| Value                                      | Description             |
| ------------------------------------------ | ----------------------- |
| ARKUI_NODE_CUSTOM_EVENT_ON_MEASURE         | Measure.&nbsp;&nbsp;    |
| ARKUI_NODE_CUSTOM_EVENT_ON_LAYOUT          | Layout.&nbsp;&nbsp;     |
| ARKUI_NODE_CUSTOM_EVENT_ON_DRAW            | Draw.&nbsp;&nbsp;       |
| ARKUI_NODE_CUSTOM_EVENT_ON_FOREGROUND_DRAW | Foreground.&nbsp;&nbsp; |
| ARKUI_NODE_CUSTOM_EVENT_ON_OVERLAY_DRAW    | Overlay.&nbsp;&nbsp;    |


### ArkUI_NodeDirtyFlag

```
enum ArkUI_NodeDirtyFlag
```
**Description**

Enumerates the dirty area flags passed in the **::markDirty** API.

**Since**: 12

| Value             | Description                                                  |
| ----------------- | ------------------------------------------------------------ |
| NODE_NEED_MEASURE | Recalculate the size.<br>When this type of flag is specified, re-layout is triggered by default. |
| NODE_NEED_LAYOUT  | Re-layout.&nbsp;&nbsp;                                       |
| NODE_NEED_RENDER  | Re-rendering.&nbsp;&nbsp;                                    |


### ArkUI_NodeEventType

```
enum ArkUI_NodeEventType
```
**Description**

Enumerates the event types supported by the NativeNode component.

**Since**: 12

| Value                                    | Description                                                  |
| ---------------------------------------- | ------------------------------------------------------------ |
| NODE_TOUCH_EVENT                         | Enumerates gesture types.<br>When the event callback occurs, the union type in the event parameter [ArkUI_NodeEvent](#arkui_nodeevent) object is [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent). |
| NODE_EVENT_ON_APPEAR                     | Mount event.<br>This event is triggered when the component is mounted and displayed.<br>When the event callback occurs, the union type in the event parameter [ArkUI_NodeEvent](#arkui_nodeevent) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) does not contain parameters. |
| NODE_EVENT_ON_DISAPPEAR                  | Uninstallation event.<br>This event is triggered when the component obtains the focus.<br>When the event callback occurs, the union type in the event parameter [ArkUI_NodeEvent](#arkui_nodeevent) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) does not contain parameters. |
| NODE_EVENT_ON_AREA_CHANGE                | Component Area Change Event<br>The area change event is triggered when the component's size, position, or any other attribute that may affect its display area changes.<br>When the event callback occurs, the union type in the event parameter [ArkUI_NodeEvent](#arkui_nodeevent) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) contains the following 12 parameters:<br>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].f32**: original width of the target element, in vp. The value is a number.<br>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[1].f32**: original height of the target element, in vp. The value is a number.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[2].f32: X coordinate of the upper left corner of the target element relative to the upper left corner of the parent element. The value type is number and the unit is vp.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[3].f32: Y-axis coordinate of the upper left corner of the target element relative to the upper left corner of the parent element. The value type is number, and the unit is vp.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[4].f32: X coordinate of the upper left corner of the target element relative to the upper left corner of the page. The value type is number and the unit is vp.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[5].f32: y-axis coordinate of the upper left corner of the target element relative to the upper left corner of the page. The value type is number, and the unit is vp.<br>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].f32**: original width of the target element, in vp. The value is a number.<br>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[1].f32**: original height of the target element, in vp. The value is a number.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[8].f32: X coordinate of the upper left corner of the latest target element relative to the upper left corner of the parent element. The value type is number and the unit is vp.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[9].f32: Y coordinate of the upper left corner of the latest target element relative to the upper left corner of the parent element. The value type is number, and the unit is vp.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[10].f32: X coordinate of the upper left corner of the latest target element relative to the upper left corner of the page. The value type is number, and the unit is vp.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[11].f32: Y coordinate of the upper left corner of the latest target element relative to the upper left corner of the page. The value type is number, and the unit is vp. |
| NODE_ON_FOCUS                            | Focus obtaining event.<br>This event is triggered when the component obtains the focus.<br>When the event callback occurs, the union type in the event parameter [ArkUI_NodeEvent](#arkui_nodeevent) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) does not contain parameters. |
| NODE_ON_BLUR                             | Event of losing the focus.<br>This event is triggered when the component loses the focus.<br>When the event callback occurs, the union type in the event parameter [ArkUI_NodeEvent](#arkui_nodeevent) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) does not contain parameters. |
| NODE_ON_CLICK                            | Widget click event.<br>This event is triggered when the component is clicked.<br>When the event callback occurs, the union type in the event parameter [ArkUI_NodeEvent](#arkui_nodeevent) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) contains the following 12 parameters:<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].f32: X coordinate of the clicked position relative to the upper left corner of the original area of the clicked element, in vp.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[1].f32: Y coordinate of the clicked position relative to the upper left corner of the original area of the clicked element, in vp.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[2].f32: event timestamp. It is the interval between the time when the event is triggered and the time when the system starts, in microseconds.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[3].i32: event input device. The value 1 indicates the mouse, 2 indicates the touchscreen, and 4 indicates the key.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[4].f32: X coordinate of the clicked position relative to the upper left corner of the application window, in vp.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[5].f32: Y coordinate of the clicked position relative to the upper left corner of the application window, in vp.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[6].f32: X coordinate of the clicked position relative to the upper left corner of the application screen, in vp.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[7].f32: Y coordinate of the clicked position relative to the upper left corner of the application screen, in vp. |
| NODE_ON_TOUCH_INTERCEPT                  | Intercepts customized events of the widget.<br>This event is triggered when the component is clicked.<br>When the event callback occurs, the union type in the event parameter [ArkUI_NodeEvent](#arkui_nodeevent) object is [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent). |
| NODE_EVENT_ON_VISIBLE_AREA_CHANGE        | Visible Area Change Event<br>Condition for triggering the event: The callback is triggered when the ratio of the visible area of the widget to its own area is close to the configured threshold.<br>The format of the input parameter [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) is as follows:<br>* .value[0...].f32: threshold array. Each threshold represents a ratio of the component's visible area to the component's total area. The value range of the threshold is [0.0, 1.0]. \n<br>When the event callback occurs, the union type in the event parameter [ArkUI_NodeEvent](#arkui_nodeevent) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) contains the following parameters:<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].i32: indicates the ratio of the visible area to the widget area compared with the last change. The value 1 indicates that the ratio increases, and the value 0 indicates that the ratio decreases.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[1].f32: ratio of the visible area of the widget to its own area when callback is triggered. |
| NODE_ON_HOVER                            | Defines the event triggered when the mouse pointer is moved over or away from the component.<br>Condition for triggering the event: The callback is triggered when the mouse enters or exits the component.<br>When the event callback occurs, the union type in the event parameter [ArkUI_NodeEvent](#arkui_nodeevent) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) contains the following parameters:<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].i32: indicates whether the mouse pointer is hovered over the component. The value 1 indicates that the mouse pointer is hovered over the component, and the value 0 indicates that the mouse pointer is hovered over the component. |
| NODE_ON_MOUSE                            | Widget click event.<br>* This event is triggered when the component is clicked by a mouse device button or when the mouse pointer moves within the component.<br>When the event callback occurs, the union type in the event parameter [ArkUI_NodeEvent](#arkui_nodeevent) object is [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent). |
| NODE_TEXT_ON_DETECT_RESULT_UPDATE        | Defines the event triggered when text recognition with the configured **TextDataDetectorConfig** settings succeeds.<br>Condition for triggering this event: TextDataDetectorConfig is set for the text and the recognition is successful.<br>When the event callback occurs, the union type in the event parameter [ArkUI_NodeEvent](#arkui_nodeevent) object is [ArkUI_StringAsyncEvent](_ark_u_i___string_async_event.md).<br>[ArkUI_StringAsyncEvent](_ark_u_i___string_async_event.md) contains the following parameters:<br>[ArkUI_StringAsyncEvent.pStr](_ark_u_i___string_async_event.md#pstr): indicates the text recognition result in JSON format. |
| NODE_IMAGE_ON_COMPLETE                   | Image loading success event.<br>This event is triggered when an image is successfully loaded or decoded.<br>When the event callback occurs, the union type in the event parameter [ArkUI_NodeEvent](#arkui_nodeevent) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) contains the following nine parameters:<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].i32: indicates the loading status. The value 0 indicates that the data is loaded successfully, and the value 1 indicates that the decoding is successful.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[1].f32: width of the image, in pixels.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[2].f32: height of the image, in pixels.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[3].f32: width of the current component, in pixels.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[4].f32: height of the current widget, in pixels.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[5].f32: position of the image drawing area relative to the X axis of the widget, in pixels.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[6].f32: position of the image drawing area relative to the Y axis of the widget, in pixels.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[7].f32: width of the image drawing area, in pixels.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[8].f32: height of the image drawing area, in pixels. |
| NODE_IMAGE_ON_ERROR                      | Image loading failure event.<br>This event is triggered when an error occurs during image loading.<br>When the event callback occurs, the union type in the event parameter [ArkUI_NodeEvent](#arkui_nodeevent) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) contains the following parameters:<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].i32 error code information:<br>401: The image could not be obtained because the image path is invalid.<br>103101: The image format is not supported. |
| NODE_IMAGE_ON_SVG_PLAY_FINISH            | Defines the SVG animation playback completion event.<br>This event is triggered when the animation playback in the loaded SVG image is complete.<br>When the event callback occurs, the union type in the event parameter [ArkUI_NodeEvent](#arkui_nodeevent) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) does not contain parameters. |
| NODE_IMAGE_ON_DOWNLOAD_PROGRESS          | Defines the event triggered during image download.<br>Condition for triggering this event: This event is triggered when the page component downloads a web page image.<br>When the event callback occurs, the union type in the event parameter [ArkUI_NodeEvent](#arkui_nodeevent) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) contains the following parameters:<br>Number of bytes that have been downloaded by the [ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].u32: so far.<br>Total number of bytes of images to be downloaded by the [ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[1].u32:. |
| NODE_TOGGLE_ON_CHANGE                    | Defines the event triggered when the toggle status changes.<br>This event is triggered when the switch status changes.<br>When the event callback occurs, the union type in the event parameter [ArkUI_NodeEvent](#arkui_nodeevent) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) contains the following parameters:<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].i32: current switch status. The value 1 indicates that the switch is turned on, and the value 0 indicates that the switch is turned off. |
| NODE_TEXT_INPUT_ON_CHANGE                | Defines the event triggered when the text input content changes.<br>Condition for triggering the event: The input content changes.<br>When the event callback occurs, the union type in the event parameter [ArkUI_NodeEvent](#arkui_nodeevent) object is [ArkUI_StringAsyncEvent](_ark_u_i___string_async_event.md).<br>[ArkUI_StringAsyncEvent](_ark_u_i___string_async_event.md) contains the following parameters:<br>[ArkUI_StringAsyncEvent.pStr](_ark_u_i___string_async_event.md#pstr): input text content. |
| NODE_TEXT_INPUT_ON_SUBMIT                | This event is triggered when the Enter key of the textInput input method is pressed.<br>This event is triggered when the Enter key of the input method is pressed.<br>When the event callback occurs, the union type in the event parameter [ArkUI_NodeEvent](#arkui_nodeevent) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) contains the following parameters:<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].i32: Enter key type of the input method. |
| NODE_TEXT_INPUT_ON_CUT                   | Called when the cut button on the pasteboard, which displays when the text box is long pressed, is clicked.<br>Condition for triggering this event: Touch and hold the internal area of the text box to display the clipboard, and touch the clipboard cut button.<br>When the event callback occurs, the union type in the event parameter [ArkUI_NodeEvent](#arkui_nodeevent) object is [ArkUI_StringAsyncEvent](_ark_u_i___string_async_event.md).<br>[ArkUI_StringAsyncEvent](_ark_u_i___string_async_event.md) contains the following parameters:<br>[ArkUI_StringAsyncEvent.pStr](_ark_u_i___string_async_event.md#pstr): cut text content. |
| NODE_TEXT_INPUT_ON_PASTE                 | Called when the paste button on the pasteboard, which displays when the text box is long pressed, is clicked.<br>Condition for triggering this event: Touch and hold the internal area of the text box to display the clipboard, and touch the clipboard paste button.<br>When the event callback occurs, the union type in the event parameter [ArkUI_NodeEvent](#arkui_nodeevent) object is [ArkUI_StringAsyncEvent](_ark_u_i___string_async_event.md).<br>[ArkUI_StringAsyncEvent](_ark_u_i___string_async_event.md) contains the following parameters:<br>[ArkUI_StringAsyncEvent.pStr](_ark_u_i___string_async_event.md#pstr): text content to be pasted. |
| NODE_TEXT_INPUT_ON_TEXT_SELECTION_CHANGE | Called when the text selection position changes.<br>Condition for triggering this event: The position of the selected text changes.<br>When the event callback occurs, the union type in the event parameter [ArkUI_NodeEvent](#arkui_nodeevent) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) contains the following parameters:<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].i32: indicates the start position of the selected text.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[1].i32: indicates the end position of the selected text. |
| NODE_TEXT_INPUT_ON_EDIT_CHANGE           | Called when the input status changes.<br>Condition for triggering this event: The input status changes.<br>When the event callback occurs, the union type in the event parameter [ArkUI_NodeEvent](#arkui_nodeevent) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) contains the following parameters:<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].i32: indicates that the value is true, indicating that the value is being entered. |
| NODE_TEXT_INPUT_ON_INPUT_FILTER_ERROR    | Defines the event triggered when matching with the regular expression specified by **NODE_TEXT_INPUT_INPUT_FILTER** fails.<br>Condition for triggering the event: The regular expression fails to be matched.<br>When the event callback occurs, the union type in the event parameter [ArkUI_NodeEvent](#arkui_nodeevent) object is [ArkUI_StringAsyncEvent](_ark_u_i___string_async_event.md).<br>[ArkUI_StringAsyncEvent](_ark_u_i___string_async_event.md) contains the following parameters:<br>[ArkUI_StringAsyncEvent.pStr](_ark_u_i___string_async_event.md#pstr): content that is filtered out when regular expression matching fails. |
| NODE_TEXT_INPUT_ON_CONTENT_SCROLL        | Called when the text content is scrolled.<br>Condition for triggering this event: The text content is scrolled.<br>When the event callback occurs, the union type in the event parameter [ArkUI_NodeEvent](#arkui_nodeevent) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) contains the following parameters:<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].i32: horizontal coordinate offset of the text in the content area.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[1].i32: vertical coordinate offset of the text in the content area. |
| NODE_TEXT_INPUT_ON_CONTENT_SIZE_CHANGE   | Defines the event triggered when the text input content changes.<br>Condition for triggering the event: The input content changes.<br>When the event callback occurs, the union type in the event parameter [ArkUI_NodeEvent](#arkui_nodeevent) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) contains the following parameters:<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].f32: indicates the width of the text.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[1].f32: height of the text. |
| NODE_TEXT_AREA_ON_CHANGE                 | Called when the input in the text box changes.<br>Condition for triggering the event: The input content changes.<br>When the event callback occurs, the union type in the event parameter [ArkUI_NodeEvent](#arkui_nodeevent) object is [ArkUI_StringAsyncEvent](_ark_u_i___string_async_event.md).<br>[ArkUI_StringAsyncEvent](_ark_u_i___string_async_event.md) contains the following parameters:<br>[ArkUI_StringAsyncEvent.pStr](_ark_u_i___string_async_event.md#pstr): text content that is being entered. |
| NODE_TEXT_AREA_ON_PASTE                  | Called when the paste button on the pasteboard, which displays when the text box is long pressed, is clicked.<br>Condition for triggering this event: Touch and hold the internal area of the text box to display the clipboard, and touch the clipboard paste button.<br>When the event callback occurs, the union type in the event parameter [ArkUI_NodeEvent](#arkui_nodeevent) object is [ArkUI_StringAsyncEvent](_ark_u_i___string_async_event.md).<br>[ArkUI_StringAsyncEvent](_ark_u_i___string_async_event.md) contains the following parameters:<br>[ArkUI_StringAsyncEvent.pStr](_ark_u_i___string_async_event.md#pstr): text content to be pasted. |
| NODE_TEXT_AREA_ON_TEXT_SELECTION_CHANGE  | Called when the text selection position changes.<br>Condition for triggering this event: The position of the selected text changes.<br>When the event callback occurs, the union type in the event parameter [ArkUI_NodeEvent](#arkui_nodeevent) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) contains the following parameters:<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].i32: indicates the start position of the selected text.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[1].i32: indicates the end position of the selected text. |
| NODE_TEXT_AREA_ON_EDIT_CHANGE            | Called when the input status changes.<br>Condition for triggering this event: The input status changes.<br>When the event callback occurs, the union type in the event parameter [ArkUI_NodeEvent](#arkui_nodeevent) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) contains the following parameters:<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].i32: indicates that the value is true, indicating that the value is being entered. |
| NODE_TEXT_AREA_ON_SUBMIT                 | Defines the event triggered when the Enter key on the keyboard is pressed for the multi-line text box.<br>This event is triggered when the Enter key of the input method is pressed. This event is not triggered when keyType is set to ARKUI_ENTER_KEY_TYPE_NEW_LINE.<br>When the event callback occurs, the union type in the event parameter [ArkUI_NodeEvent](#arkui_nodeevent) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) contains the following parameters:<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].i32: Enter key type of the input method. |
| NODE_TEXT_AREA_ON_INPUT_FILTER_ERROR     | Defines the event triggered when matching with the regular expression specified by **NODE_TEXT_AREA_INPUT_FILTER** fails.<br>Condition for triggering the event: The regular expression fails to be matched.<br>When the event callback occurs, the union type in the event parameter [ArkUI_NodeEvent](#arkui_nodeevent) object is [ArkUI_StringAsyncEvent](_ark_u_i___string_async_event.md).<br>[ArkUI_StringAsyncEvent](_ark_u_i___string_async_event.md) contains the following parameters:<br>[ArkUI_StringAsyncEvent.pStr](_ark_u_i___string_async_event.md#pstr): content that is filtered out when regular expression matching fails. |
| NODE_TEXT_AREA_ON_CONTENT_SCROLL         | Called when the text content is scrolled.<br>Condition for triggering this event: The text content is scrolled.<br>When the event callback occurs, the union type in the event parameter [ArkUI_NodeEvent](#arkui_nodeevent) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) contains the following parameters:<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].i32: horizontal coordinate offset of the text in the content area.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[1].i32: vertical coordinate offset of the text in the content area. |
| NODE_TEXT_AREA_ON_CONTENT_SIZE_CHANGE    | Defines the event triggered when the text input content changes in the **<TextArea>** component.<br>Condition for triggering the event: The input content changes.<br>When the event callback occurs, the union type in the event parameter [ArkUI_NodeEvent](#arkui_nodeevent) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) contains the following parameters:<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].f32: indicates the width of the text.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[1].f32: height of the text. |
| NODE_CHECKBOX_EVENT_ON_CHANGE            | Defines the event triggered when the selected status of the ARKUI_NODE_CHECKBOX component changes.<br>When the event callback occurs, the union type in the event parameter [ArkUI_NodeEvent](#arkui_nodeevent) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].i321: selected; 0: not selected |
| NODE_DATE_PICKER_EVENT_ON_DATE_CHANGE    | Defines the event triggered when a date is selected in the ARKUI_NODE_DATE_PICKER component.<br>Condition for triggering the event: The event is triggered when a date is selected.<br>When the event callback occurs, the union type in the event parameter [ArkUI_NodeEvent](#arkui_nodeevent) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) contains the following parameters:<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].i32: indicates the year of the selected time.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[1].i32: month of the selected time. The options are as follows: [0-11].<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[2].i32: indicates the day of the selected time. |
| NODE_TIME_PICKER_EVENT_ON_CHANGE         | Defines the event triggered when a time is selected in the ARKUI_NODE_TIME_PICKER component.<br>Condition for triggering the event: The event is triggered when the time is selected.<br>When the event callback occurs, the union type in the event parameter [ArkUI_NodeEvent](#arkui_nodeevent) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) contains the following parameters:<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].i32: indicates the time when the time is selected. The options are as follows: [0-23].<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[1].i32: minute of the selected time. The options are as follows: [0-59]. |
| NODE_TEXT_PICKER_EVENT_ON_CHANGE         | Defines the event triggered when an item is selected in the ARKUI_NODE_TEXT_PICKER component.<br>Condition for triggering the event: The event is triggered when the time is selected.<br>When the event callback occurs, the union type in the event parameter [ArkUI_NodeEvent](#arkui_nodeevent) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) contains the following parameters:<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0...11].i32 indicates the dimension of the selected data. |
| NODE_CALENDAR_PICKER_EVENT_ON_CHANGE     | Defines the event triggered when a date is selected in the NODE_CALENDAR_PICKER.<br>When the event callback occurs, the union type in the event parameter [ArkUI_NodeEvent](#arkui_nodeevent) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>ArkUI_NodeComponent.data[0].u32 selected year.<br>ArkUI_NodeComponent.data[1].u32 selected month.<br>ArkUI_NodeComponent.data[2].u32 selected day. |
| NODE_SLIDER_EVENT_ON_CHANGE              | Defines the event triggered when the ARKUI_NODE_SLIDER component is dragged or clicked.<br>When the event callback occurs, the union type in the event parameter [ArkUI_NodeEvent](#arkui_nodeevent) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) contains the following parameters:<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].f32: current sliding progress.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[1].i32: status value related to event triggering |
| NODE_RADIO_EVENT_ON_CHANGE               | Defines the event triggered when the ARKUI_NODE_SLIDER component is dragged or clicked.<br>When the event callback occurs, the union type in the event parameter [ArkUI_NodeEvent](#arkui_nodeevent) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) contains the following parameters:<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].i32: status of an option button. |
| NODE_SWIPER_EVENT_ON_CHANGE              | Defines the event triggered when the index of the currently displayed element of this **ARKUI_NODE_SWIPER** instance changes.<br>When the event callback occurs, the union type in the event parameter [ArkUI_NodeEvent](#arkui_nodeevent) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) contains the following parameters:<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].i32: indicates the index of the currently displayed element. |
| NODE_SWIPER_EVENT_ON_ANIMATION_START     | Defines the callback triggered when the ARKUI_NODE_SWIPER switching animation starts.<br>When the event callback occurs, the union type in the event parameter [ArkUI_NodeEvent](#arkui_nodeevent) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) contains the following 5 parameters:<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].i32: indicates the index of the currently displayed element.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[1].i32: index of the target element of the switching animation.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[2].f32: offset of the current displayed element relative to the start position of the Swiper in the direction of the principal axis.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[3].f32: offset of the target element relative to the start position of the Swiper in the direction of the principal axis.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[4].f32: indicates the off-hand speed. |
| NODE_SWIPER_EVENT_ON_ANIMATION_END       | Defines the event triggered when the switching animation of this **ARKUI_NODE_SWIPER** instance ends.<br>When the event callback occurs, the union type in the event parameter [ArkUI_NodeEvent](#arkui_nodeevent) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) contains the following parameters:<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].i32: indicates the index of the currently displayed element.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[1].f32: offset of the current displayed element relative to the start position of the Swiper in the direction of the principal axis. |
| NODE_SWIPER_EVENT_ON_CONTENT_DID_SCROLL  | Define ARKUI_NODE_SWIPER to listen on Swiper page sliding events. How to Use<br>1. When [ArkUI_SwiperDisplayModeType](#arkui_swiperdisplaymodetype) is set to ARKUI_SWIPER_DISPLAY_MODE_AUTO_LINEAR, this API does not take effect.<br>2. This API does not work when **prevMargin** and **nextMargin** are set in such a way that the **\<Swiper>** frontend and backend display the same page during loop playback.<br>* 3. During page scrolling, the **ContentDidScrollCallback** callback is invoked for all pages in the viewport on a frame-by-frame basis.<br>For example, when there are two pages whose subscripts are 0 and 1 in the viewport, two callbacks whose indexes are 0 and 1 are invoked in each frame.<br>4. When the swipeByGroup parameter of the displayCount attribute is set to true and at least one page in the same group is in the window:<br>Callback is triggered for all pages in the same group.<br>When the event callback occurs, the union type in the event parameter [ArkUI_NodeEvent](#arkui_nodeevent) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) contains the following 4 parameters:<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].i32: index of the Swiper component, which is the same as the index value in the onChange event.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[1].i32: index of a page in the window.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[2].f32: moving ratio of the page relative to the start position of the Swiper major axis (the start position of the page corresponding to selectedIndex).<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[3].f32: page length in the principal axis direction. |
| NODE_SWIPER_EVENT_ON_GESTURE_SWIPE       | Triggered on a frame-by-frame basis when the tab is switched by a swipe.<br>When the event callback occurs, the union type in the event parameter [ArkUI_NodeEvent](#arkui_nodeevent) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) contains the following parameters:<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].i32: indicates the index of the currently displayed element.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[1].f32: offset of the current displayed element relative to the start position of the Swiper in the direction of the principal axis. |
| NODE_SCROLL_EVENT_ON_SCROLL              | Defines the scrolling event enumeration values of the scrolling container component.<br>**NOTE**<br>1. This event is triggered when scrolling is started by the **\<Scroll>** component or other input settings, such as keyboard and mouse operations.<br>2. This event is triggered when the controller API is called.<br>3. This event supports the out-of-bounds bounce effect.<br>When the event callback occurs, the union type in the event parameter [ArkUI_NodeEvent](#arkui_nodeevent) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) contains the following parameters:<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].f32: increment on the X axis since the last event is triggered.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[1].f32: increment on the Y axis since the last event is triggered. |
| NODE_SCROLL_EVENT_ON_SCROLL_FRAME_BEGIN  | Defines the event triggered when the container starts scrolling.<br>**NOTE**<br>1. This event is triggered when scrolling is started by the **\<Scroll>** component or other input settings, such as keyboard and mouse operations.<br>2. This event is not triggered when the controller API is called.<br>3. This event does not support the out-of-bounds bounce effect.<br>When the event callback occurs, the union type in the event parameter [ArkUI_NodeEvent](#arkui_nodeevent) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) contains the following parameters:<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].f32: indicates the upcoming scrolling amount.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[1].i32: current scrolling status.<br>The [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) parameter contains the following return values:<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].f32: In the event processing function, the required scrolling amount can be calculated based on the application scenario and stored in data[0].f32. The scrolling is performed based on the actual scrolling amount of the return value. |
| NODE_SCROLL_EVENT_ON_WILL_SCROLL         | Defines the event triggered when the container is about to scroll.<br>**NOTE**<br>1. This event is triggered when scrolling is started by the **\<Scroll>** component or other input settings, such as keyboard and mouse operations.<br>2. This event is triggered when the controller API is called.<br>3. This event supports the out-of-bounds bounce effect.<br>When the event callback occurs, the union type in the event parameter [ArkUI_NodeEvent](#arkui_nodeevent) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) contains the following parameters:<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].f32:: scrolling offset of each frame. The offset is positive when the content scrolls leftwards and negative when the content scrolls rightwards. The unit is vp.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[1].f32: Scrolling offset of each frame. The offset is positive when the content scrolls up and negative when the content scrolls down. The unit is vp.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[2].i32:: current sliding status. The parameter type is [ArkUI_ScrollState](#arkui_scrollstate). |
| NODE_SCROLL_EVENT_ON_DID_SCROLL          | Defines the event triggered when the container scrolls.<br>**NOTE**<br>1. This event is triggered when scrolling is started by the **\<Scroll>** component or other input settings, such as keyboard and mouse operations.<br>2. This event is triggered when the controller API is called.<br>3. This event supports the out-of-bounds bounce effect.<br>When the event callback occurs, the union type in the event parameter [ArkUI_NodeEvent](#arkui_nodeevent) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) contains the following parameters:<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].f32:: scrolling offset of each frame. The offset is positive when the content scrolls leftwards and negative when the content scrolls rightwards. The unit is vp.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[1].f32: Scrolling offset of each frame. The offset is positive when the content scrolls up and negative when the content scrolls down. The unit is vp.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[2].i32:: current sliding status. The parameter type is [ArkUI_ScrollState](#arkui_scrollstate). |
| NODE_SCROLL_EVENT_ON_SCROLL_START        | Defines the event triggered when the container starts scrolling.<br>**NOTE**<br>1. This event is triggered when scrolling is started by the **\<Scroll>** component or other input settings, such as keyboard and mouse operations.<br>2. This event is triggered when the controller API is called, accompanied by a transition animation.<br>When the event callback occurs, the union type in the event parameter [ArkUI_NodeEvent](#arkui_nodeevent) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) does not contain parameters. |
| NODE_SCROLL_EVENT_ON_SCROLL_STOP         | Defines the event triggered when the container stops scrolling.<br>**NOTE**<br>1. This event is triggered when scrolling is stopped by the **\<Scroll>** component or other input settings, such as keyboard and mouse operations.<br>2. This event is triggered when the controller API is called, accompanied by a transition animation.<br>When the event callback occurs, the union type in the event parameter [ArkUI_NodeEvent](#arkui_nodeevent) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) does not contain parameters. |
| NODE_SCROLL_EVENT_ON_SCROLL_EDGE         | Defines the scrolling edge event enumeration values of the scrolling container component.<br>**NOTE**<br>1. This event is triggered when scrolling reaches the edge after being started by the **\<Scroll>** component or other input settings, such as keyboard and mouse operations.<br>2. This event is triggered when the controller API is called.<br>3. This event supports the out-of-bounds bounce effect.<br>When the event callback occurs, the union type in the event parameter [ArkUI_NodeEvent](#arkui_nodeevent) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) contains one parameter.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].i32 indicates the top, bottom, left, and right edges that are touched. |
| NODE_SCROLL_EVENT_ON_REACH_END           | Defines the callback triggered when the scrolling container component is at the end.<br>**NOTE**<br>1. This event is triggered when the component is at the end.<br>When the event callback occurs, the union type in the event parameter [ArkUI_NodeEvent](#arkui_nodeevent) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) does not contain parameters. |
| NODE_SCROLL_EVENT_ON_REACH_START         | Defines that the callback is triggered when the scrolling container component reaches the start position.<br>**NOTE**<br>1. This event is triggered when the widget reaches the start position.<br>When the event callback occurs, the union type in the event parameter [ArkUI_NodeEvent](#arkui_nodeevent) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) does not contain parameters. |
| NODE_LIST_ON_SCROLL_INDEX                | Defines the event triggered when a child component enters or leaves the list display area.<br>**NOTE**<br>* This event is triggered once when the list is initialized and when the index of the first child component or the next child component in the list display area changes.<br>When the event callback occurs, the union type in the event parameter [ArkUI_NodeEvent](#arkui_nodeevent) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) contains the following parameters:<br>Index value of the first child component in the [ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].i32: List display area.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[1].i32: List displays the index value of the last child component in the area.<br>Index value of the child component in the middle of the [ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[2].i32: List display area. |
| NODE_LIST_ON_WILL_SCROLL                 | Defines the event triggered when the list is about to scroll.<br>**NOTE**<br>1. This event is triggered when scrolling is started by the **\<Scroll>** component or other input settings, such as keyboard and mouse operations.<br>2. This event is triggered when the controller API is called.<br>3. This event supports the out-of-bounds bounce effect.<br>When the event callback occurs, the union type in the event parameter [ArkUI_NodeEvent](#arkui_nodeevent) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) contains the following parameters:<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].f32: Scrolling offset of each frame. When the list content scrolls up, the offset is positive. When the list content scrolls down, the offset is negative.<br>Current sliding status of the [ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[1].i32:. |
| NODE_LIST_ON_DID_SCROLL                  | Defines the event triggered when the list scrolls.<br>**NOTE**<br>1. This event is triggered when scrolling is started by the **\<Scroll>** component or other input settings, such as keyboard and mouse operations.<br>2. This event is triggered when the controller API is called.<br>3. This event supports the out-of-bounds bounce effect.<br>When the event callback occurs, the union type in the event parameter [ArkUI_NodeEvent](#arkui_nodeevent) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) contains the following parameters:<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].f32: Scrolling offset of each frame. When the list content scrolls up, the offset is positive. When the list content scrolls down, the offset is negative.<br>Current sliding status of the [ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[1].i32:. |
| NODE_REFRESH_STATE_CHANGE                | This event is triggered when the ARKUI_NODE_REFRESH refresh status changes.<br>When the event callback occurs, the union type in the event parameter [ArkUI_NodeEvent](#arkui_nodeevent) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) contains the following parameters:<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].i32: refresh status. |
| NODE_REFRESH_ON_REFRESH                  | This event is triggered when ARKUI_NODE_REFRESH enters the refresh state.<br>When the event callback occurs, the union type in the event parameter [ArkUI_NodeEvent](#arkui_nodeevent) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) does not contain parameters. |
| NODE_REFRESH_ON_OFFSET_CHANGE            | This event is triggered when the pull-down distance of ARKUI_NODE_REFRESH changes.<br>When the event callback occurs, the union type in the event parameter [ArkUI_NodeEvent](#arkui_nodeevent) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) contains the following parameters:<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].f32: pull-down distance. |
| NODE_WATER_FLOW_ON_WILL_SCROLL           | Defines the event triggered when the water flow container is about to scroll.<br>**NOTE**<br>1. This event is triggered when scrolling is started by the **\<Scroll>** component or other input settings, such as keyboard and mouse operations.<br>2. This event is triggered when the controller API is called.<br>3. This event supports the out-of-bounds bounce effect.<br>When the event callback occurs, the union type in the event parameter [ArkUI_NodeEvent](#arkui_nodeevent) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) contains the following parameters:<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].f32: Offset of scrolling each frame. The offset is positive when the content scrolls up and negative when the content scrolls down.<br>Current sliding status of the [ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[1].i32:. |
| NODE_WATER_FLOW_ON_DID_SCROLL            | Defines the event triggered when the water flow container scrolls.<br>**NOTE**<br>1. This event is triggered when scrolling is started by the **\<Scroll>** component or other input settings, such as keyboard and mouse operations.<br>2. This event is triggered when the controller API is called.<br>3. This event supports the out-of-bounds bounce effect.<br>When the event callback occurs, the union type in the event parameter [ArkUI_NodeEvent](#arkui_nodeevent) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) contains the following parameters:<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].f32: Offset of scrolling each frame. The offset is positive when the content scrolls up and negative when the content scrolls down.<br>Current sliding status of the [ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[1].i32:. |
| NODE_WATER_FLOW_ON_SCROLL_INDEX          | Defines the event triggered when the first or last item displayed in the water flow container changes.<br>**NOTE**<br>This event is triggered when either of the preceding indexes changes.<br>When the event callback occurs, the union type in the event parameter [ArkUI_NodeEvent](#arkui_nodeevent) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) contains the following parameters:<br>Index of the start position of the water flow displayed on the [ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].i32:.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[1].i32: Index of the end position of the waterfall currently displayed. |
| NODE_IMAGE_ANIMATOR_EVENT_ON_START       | Defines the event triggered when the frame-by-frame animation starts to play.<br>This event is triggered when any of the following conditions is met:<br>1. When the frame animation starts to play.<br>When the event callback occurs, the union type in the event parameter [ArkUI_NodeEvent](#arkui_nodeevent) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) does not contain parameters. |
| NODE_IMAGE_ANIMATOR_EVENT_ON_PAUSE       | Defines the event triggered when the frame-by-frame animation playback is paused.<br>This event is triggered when any of the following conditions is met:<br>1. The frame animation is paused.<br>When the event callback occurs, the union type in the event parameter [ArkUI_NodeEvent](#arkui_nodeevent) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) does not contain parameters. |
| NODE_IMAGE_ANIMATOR_EVENT_ON_REPEAT      | Defines the event triggered when the frame-by-frame animation playback is repeated.<br>This event is triggered when any of the following conditions is met:<br>1. The frame animation is played repeatedly.<br>When the event callback occurs, the union type in the event parameter [ArkUI_NodeEvent](#arkui_nodeevent) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) does not contain parameters. |
| NODE_IMAGE_ANIMATOR_EVENT_ON_CANCEL      | Defines the event triggered when the frame-by-frame animation playback returns to the initial state.<br>This event is triggered when any of the following conditions is met:<br>1. When the frame animation returns to the initial state.<br>When the event callback occurs, the union type in the event parameter [ArkUI_NodeEvent](#arkui_nodeevent) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) does not contain parameters. |
| NODE_IMAGE_ANIMATOR_EVENT_ON_FINISH      | Defines the event triggered when the frame-by-frame animation playback is complete or stopped.<br>This event is triggered when any of the following conditions is met:<br>1. The frame animation is played completely or stopped.<br>When the event callback occurs, the union type in the event parameter [ArkUI_NodeEvent](#arkui_nodeevent) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) does not contain parameters. |


### ArkUI_NodeType

```
enum ArkUI_NodeType
```
**Description**

Enumerates ArkUI component types that can be created on the native side.

**Since**: 12

| Value                         | Description                                                  |
| ----------------------------- | ------------------------------------------------------------ |
| ARKUI_NODE_CUSTOM             | *Custom nodes*&nbsp;&nbsp;                                   |
| ARKUI_NODE_TEXT               | Text to insert.&nbsp;&nbsp;                                  |
| ARKUI_NODE_SPAN               | Text span.&nbsp;&nbsp;                                       |
| ARKUI_NODE_IMAGE_SPAN         | Image span.&nbsp;&nbsp;                                      |
| ARKUI_NODE_IMAGE              | Image.&nbsp;&nbsp;                                           |
| ARKUI_NODE_TOGGLE             | Status switch&nbsp;&nbsp;                                    |
| ARKUI_NODE_LOADING_PROGRESS   | Loading icon.&nbsp;&nbsp;                                    |
| ARKUI_NODE_TEXT_INPUT         | Single-line Text Input&nbsp;&nbsp;                           |
| ARKUI_NODE_TEXT_AREA          | Multi-line text&nbsp;&nbsp;                                  |
| ARKUI_NODE_BUTTON             | Icon&nbsp;&nbsp;                                             |
| ARKUI_NODE_PROGRESS           | The **<progress>** component is used to provide a progress bar.&nbsp;&nbsp; |
| ARKUI_NODE_CHECKBOX           | Check box&nbsp;&nbsp;                                        |
| ARKUI_NODE_XCOMPONENT         | XComponent.&nbsp;&nbsp;                                      |
| ARKUI_NODE_DATE_PICKER        | Date picker.&nbsp;&nbsp;                                     |
| ARKUI_NODE_TIME_PICKER        | Time picker.&nbsp;&nbsp;                                     |
| ARKUI_NODE_TEXT_PICKER        | A component that allows users to scroll to select text.&nbsp;&nbsp; |
| ARKUI_NODE_CALENDAR_PICKER    | Calendar picker.&nbsp;&nbsp;                                 |
| ARKUI_NODE_SLIDER             | Sliding bar component &nbsp;&nbsp;                           |
| ARKUI_NODE_RADIO              | Option button &nbsp;&nbsp;                                   |
| ARKUI_NODE_IMAGE_ANIMATOR     | Frame animation component &nbsp;&nbsp;                       |
| ARKUI_NODE_STACK              | Stack container.&nbsp;&nbsp;                                 |
| ARKUI_NODE_SWIPER             | Swiper.&nbsp;&nbsp;                                          |
| ARKUI_NODE_SCROLL             | Scrolling container.&nbsp;&nbsp;                             |
| ARKUI_NODE_LIST               | Table&nbsp;&nbsp;                                            |
| ARKUI_NODE_LIST_ITEM          | List item&nbsp;&nbsp;                                        |
| ARKUI_NODE_LIST_ITEM_GROUP    | List item group.&nbsp;&nbsp;                                 |
| ARKUI_NODE_COLUMN             | Column container.&nbsp;&nbsp;                                |
| ARKUI_NODE_ROW                | Row container.&nbsp;&nbsp;                                   |
| ARKUI_NODE_FLEX               | Flex container.&nbsp;&nbsp;                                  |
| ARKUI_NODE_REFRESH            | Refresh component.&nbsp;&nbsp;                               |
| ARKUI_NODE_WATER_FLOW         | Water flow container.&nbsp;&nbsp;                            |
| ARKUI_NODE_FLOW_ITEM          | Water flow item.&nbsp;&nbsp;                                 |
| ARKUI_NODE_RELATIVE_CONTAINER | Relative layout component.&nbsp;&nbsp;                       |
| ARKUI_NODE_GRID               | Grid.&nbsp;&nbsp;                                            |
| ARKUI_NODE_GRID_ITEM          | Grid item.&nbsp;&nbsp;                                       |
### ArkUI_ObjectFit

```
enum ArkUI_ObjectFit
```
**Description**

Defines the image filling effect. ImageSpanAlignment

**Since**: 12

| Value                       | Description                                                  |
| --------------------------- | ------------------------------------------------------------ |
| ARKUI_OBJECT_FIT_CONTAIN    | The image is scaled with its aspect ratio retained for the content to be completely displayed within the display boundaries.&nbsp;&nbsp; |
| ARKUI_OBJECT_FIT_COVER      | The image is scaled with its aspect ratio retained for both sides to be greater than or equal to the display boundaries.&nbsp;&nbsp; |
| ARKUI_OBJECT_FIT_AUTO       | The image is scaled automatically to fit the display area.&nbsp;&nbsp; |
| ARKUI_OBJECT_FIT_FILL       | The image is scaled to fill the display area, and its aspect ratio is not retained.&nbsp;&nbsp; |
| ARKUI_OBJECT_FIT_SCALE_DOWN | The image is displayed with its aspect ratio retained, in a size smaller than or equal to the original size.&nbsp;&nbsp; |
| ARKUI_OBJECT_FIT_NONE       | The original size is retained.&nbsp;&nbsp;                   |


### ArkUI_ProgressType

```
enum ArkUI_ProgressType
```
**Description**

Enumerates the styles of the progress indicator.

**Since**: 12

| Value                          | Description                           |
| ------------------------------ | ------------------------------------- |
| ARKUI_PROGRESS_TYPE_LINEAR     | Linear type.&nbsp;&nbsp;              |
| ARKUI_PROGRESS_TYPE_RING       | Indeterminate ring style.&nbsp;&nbsp; |
| ARKUI_PROGRESS_TYPE_ECLIPSE    | Eclipse style.&nbsp;&nbsp;            |
| ARKUI_PROGRESS_TYPE_SCALE_RING | Determinate ring style.&nbsp;&nbsp;   |
| ARKUI_PROGRESS_TYPE_CAPSULE    | Capsule style.&nbsp;&nbsp;            |


### ArkUI_RelativeLayoutChainStyle

```
enum ArkUI_RelativeLayoutChainStyle
```
**Description**

Enumerates the chain styles.

**Since**: 12

| Value                                           | Description                                                  |
| ----------------------------------------------- | ------------------------------------------------------------ |
| ARKUI_RELATIVE_LAYOUT_CHAIN_STYLE_SPREAD        | Child components are evenly distributed among constraint anchors.&nbsp;&nbsp; |
| ARKUI_RELATIVE_LAYOUT_CHAIN_STYLE_SPREAD_INSIDE | All child components except the first and last ones are evenly distributed among constraint anchors.&nbsp;&nbsp; |
| ARKUI_RELATIVE_LAYOUT_CHAIN_STYLE_PACKED        | There is no gap between child components in the chain.&nbsp;&nbsp; |


### ArkUI_RenderFit

```
enum ArkUI_RenderFit
```

| Value                                        | Description                                                  |
| -------------------------------------------- | ------------------------------------------------------------ |
| ARKUI_RENDER_FIT_CENTER                      | The component's content stays at the final size and always aligned with the center of the component.&nbsp;&nbsp; |
| ARKUI_RENDER_FIT_TOP                         | The component's content stays at the final size and always aligned with the top center of the component.&nbsp;&nbsp; |
| ARKUI_RENDER_FIT_BOTTOM                      | The component's content stays at the final size and always aligned with the bottom center of the component.&nbsp;&nbsp; |
| ARKUI_RENDER_FIT_LEFT                        | The component's content stays at the final size and always aligned with the left of the component.&nbsp;&nbsp; |
| ARKUI_RENDER_FIT_RIGHT                       | The component's content stays at the final size and always aligned with the right of the component.&nbsp;&nbsp; |
| ARKUI_RENDER_FIT_TOP_LEFT                    | The component's content stays at the final size and always aligned with the upper left corner of the component.&nbsp;&nbsp; |
| ARKUI_RENDER_FIT_TOP_RIGHT                   | The component's content stays at the final size and always aligned with the upper right corner of the component.&nbsp;&nbsp; |
| ARKUI_RENDER_FIT_BOTTOM_LEFT                 | The component's content stays at the final size and always aligned with the lower left corner of the component.&nbsp;&nbsp; |
| ARKUI_RENDER_FIT_BOTTOM_RIGHT                | The component's content stays at the final size and always aligned with the lower right corner of the component.&nbsp;&nbsp; |
| ARKUI_RENDER_FIT_RESIZE_FILL                 | The component's content is always resized to fill the component's content box, without considering its aspect ratio in the final state.&nbsp;&nbsp; |
| ARKUI_RENDER_FIT_RESIZE_CONTAIN              | While maintaining its aspect ratio in the final state, the component's content is scaled to fit within the component's content box. It is always aligned with the center of the component.&nbsp;&nbsp; |
| ARKUI_RENDER_FIT_RESIZE_CONTAIN_TOP_LEFT     | While maintaining its aspect ratio in the final state, the component's content is scaled to fit within the component's content box. When there is remaining space in the width direction of the component, the content is left-aligned with the component. When there is remaining space in the height direction of the component, the content is top-aligned with the component.&nbsp;&nbsp; |
| ARKUI_RENDER_FIT_RESIZE_CONTAIN_BOTTOM_RIGHT | While maintaining its aspect ratio in the final state, the component's content is scaled to fit within the component's content box. When there is remaining space in the width direction of the component, the content is right-aligned with the component. When there is remaining space in the height direction of the component, the content is bottom-aligned with the component.&nbsp;&nbsp; |
| ARKUI_RENDER_FIT_RESIZE_COVER                | While maintaining its aspect ratio in the final state, the component's content is scaled to cover the component's entire content box. It is always aligned with the center of the component, so that its middle part is displayed.&nbsp;&nbsp; |
| ARKUI_RENDER_FIT_RESIZE_COVER_TOP_LEFT       | While maintaining its aspect ratio in the final state, the component's content is scaled to cover the component's entire content box. When there is remaining space in the width direction, the content is left-aligned with the component, so that its left part is displayed. When there is remaining space in the height direction, the content is top-aligned with the component, so that its top part is displayed.&nbsp;&nbsp; |
| ARKUI_RENDER_FIT_RESIZE_COVER_BOTTOM_RIGHT   | While maintaining its aspect ratio in the final state, the component's content is scaled to cover the component's entire content box. When there is remaining space in the width direction, the content is right-aligned with the component, so that its right part is displayed. When there is remaining space in the height direction, the content is bottom-aligned with the component, so that its bottom part is displayed.&nbsp;&nbsp; |


### ArkUI_ScrollAlignment

```
enum ArkUI_ScrollAlignment
```
**Description**

Defines how the list item to scroll to is aligned with the container.

**Since**: 12

| Value                         | Description                                                  |
| ----------------------------- | ------------------------------------------------------------ |
| ARKUI_SCROLL_ALIGNMENT_START  | The start edge of the list item is flush with the start edge of the container.&nbsp;&nbsp; |
| ARKUI_SCROLL_ALIGNMENT_CENTER | The list item is centered along Specifies that the principal axis of an item is center-aligned to the container.&nbsp;&nbsp; |
| ARKUI_SCROLL_ALIGNMENT_END    | The end edge of the list item Aligns the tail of an item with that of a container.&nbsp;&nbsp; |
| ARKUI_SCROLL_ALIGNMENT_AUTO   | The list item is automatically aligned. If the item is fully contained within the display area, no adjustment is performed. Otherwise, the item is aligned so that its start or end edge is flush with the start or end edge of the container, whichever requires a shorter scrolling distance.&nbsp;&nbsp; |

### ArkUI_ScrollBarDisplayMode

```
enum ArkUI_ScrollBarDisplayMode
```
**Description**

Enumerates the scrollbar display modes.

**Since**: 12

| Value                              | Description                                                  |
| ---------------------------------- | ------------------------------------------------------------ |
| ARKUI_SCROLL_BAR_DISPLAY_MODE_OFF  | Not displayed.&nbsp;&nbsp;                                   |
| ARKUI_SCROLL_BAR_DISPLAY_MODE_AUTO | Displayed when the screen is touched and hidden after 2s.&nbsp;&nbsp; |
| ARKUI_SCROLL_BAR_DISPLAY_MODE_ON   | Always displayed.&nbsp;&nbsp;                                |


### ArkUI_ScrollDirection

```
enum ArkUI_ScrollDirection
```
**Description**

Enumerates the scroll directions of scrollable components.

**Since**: 12

| Value                             | Description                                         |
| --------------------------------- | --------------------------------------------------- |
| ARKUI_SCROLL_DIRECTION_VERTICAL   | Only vertical scrolling is supported.&nbsp;&nbsp;   |
| ARKUI_SCROLL_DIRECTION_HORIZONTAL | Only horizontal scrolling is supported.&nbsp;&nbsp; |
| ARKUI_SCROLL_DIRECTION_NONE       | Scrolling is forbidden.&nbsp;&nbsp;                 |


### ArkUI_ScrollEdge

```
enum ArkUI_ScrollEdge
```
**Description**

Defines the edge to which the component scrolls.

**Since**: 12

| Value                    | Description                                             |
| ------------------------ | ------------------------------------------------------- |
| ARKUI_SCROLL_EDGE_TOP    | Top edge in the vertical direction.&nbsp;&nbsp;         |
| ARKUI_SCROLL_EDGE_BOTTOM | Bottom edge in the vertical direction.&nbsp;&nbsp;      |
| ARKUI_SCROLL_EDGE_START  | Start position in the horizontal direction.&nbsp;&nbsp; |
| ARKUI_SCROLL_EDGE_END    | End position in the horizontal direction.&nbsp;&nbsp;   |


### ArkUI_ScrollNestedMode

```
enum ArkUI_ScrollNestedMode
```
**Description**

Defines nested scrolling options.

**Since**: 12

| Value                                 | Description                                                  |
| ------------------------------------- | ------------------------------------------------------------ |
| ARKUI_SCROLL_NESTED_MODE_SELF_ONLY    | The scrolling is contained within the component, and no scroll chaining occurs, that is, the parent component does not scroll when the component scrolling reaches the boundary.&nbsp;&nbsp; |
| ARKUI_SCROLL_NESTED_MODE_SELF_FIRST   | The component scrolls first, and when it hits the boundary, the parent component scrolls. When the parent component hits the boundary, its edge effect is displayed. If no edge effect is specified for the parent component, the edge effect of the child component is displayed instead.&nbsp;&nbsp; |
| ARKUI_SCROLL_NESTED_MODE_PARENT_FIRST | The parent component scrolls first, and when it hits the boundary, the component scrolls. When the component hits the boundary, its edge effect is displayed. If no edge effect is specified for the component, the edge effect of the parent component is displayed instead.&nbsp;&nbsp; |
| ARKUI_SCROLL_NESTED_MODE_PARALLEL     | The component and its parent component scroll at the same time. When both the component and its parent component hit the boundary, the edge effect of the component is displayed. If no edge effect is specified for the component, the edge effect of the parent component is displayed instead.&nbsp;&nbsp; |


### ArkUI_ScrollSnapAlign

```
enum ArkUI_ScrollSnapAlign
```
**Description**

Enumerates the alignment modes of list items when scrolling ends.

**Since**: 12

| Value                          | Description                                                  |
| ------------------------------ | ------------------------------------------------------------ |
| ARKUI_SCROLL_SNAP_ALIGN_NONE   | No alignment. This is the default value.&nbsp;&nbsp;         |
| ARKUI_SCROLL_SNAP_ALIGN_START  | The first item in the view is aligned at the start of the list.&nbsp;&nbsp; |
| ARKUI_SCROLL_SNAP_ALIGN_CENTER | The middle items in the view are aligned in the center of the list.&nbsp;&nbsp; |
| ARKUI_SCROLL_SNAP_ALIGN_END    | The last item in the view is aligned at the end of the list.&nbsp;&nbsp; |


### ArkUI_ScrollState

```
enum ArkUI_ScrollState
```
**Description**

Enumerates the scrolling states.

**Since**: 12

| Value                     | Description                                                  |
| ------------------------- | ------------------------------------------------------------ |
| ARKUI_SCROLL_STATE_IDLE   | Idle. The container enters this state when an API in the controller is used to scroll the container or when the scrollbar is dragged.&nbsp;&nbsp; |
| ARKUI_SCROLL_STATE_SCROLL | Scrolling. The container enters this state when the user drags the container to scroll.&nbsp;&nbsp; |
| ARKUI_SCROLL_STATE_FLING  | Inertial scrolling. The container enters this state when inertial scrolling occurs or when the container bounces back after being released from a fling.&nbsp;&nbsp; |


### ArkUI_ShadowStyle

```
enum ArkUI_ShadowStyle
```
**Description**

Enumerated value of the shadow effect.

**Since**: 12

| Value                                | Description                         |
| ------------------------------------ | ----------------------------------- |
| ARKUI_SHADOW_STYLE_OUTER_DEFAULT_XS  | Mini shadow.&nbsp;&nbsp;            |
| ARKUI_SHADOW_STYLE_OUTER_DEFAULT_SM  | Small shadow.&nbsp;&nbsp;           |
| ARKUI_SHADOW_STYLE_OUTER_DEFAULT_MD  | Medium shadow.&nbsp;&nbsp;          |
| ARKUI_SHADOW_STYLE_OUTER_DEFAULT_LG  | Large shadow.&nbsp;&nbsp;           |
| ARKUI_SHADOW_STYLE_OUTER_FLOATING_SM | Floating small shadow.&nbsp;&nbsp;  |
| ARKUI_SHADOW_STYLE_OUTER_FLOATING_MD | Floating medium shadow.&nbsp;&nbsp; |


### ArkUI_ShadowType

```
enum ArkUI_ShadowType
```
**Description**

Defines the enumerated values of the shadow type.

**Since**: 12

| Value                   | Description        |
| ----------------------- | ------------------ |
| ARKUI_SHADOW_TYPE_COLOR | Color.&nbsp;&nbsp; |
| ARKUI_SHADOW_TYPE_BLUR  | Blur.&nbsp;&nbsp;  |


### ArkUI_ShapeType

```
enum ArkUI_ShapeType
```
**Description**

Enumerates custom shape types.

**Since**: 12

| Value                      | Description            |
| -------------------------- | ---------------------- |
| ARKUI_SHAPE_TYPE_RECTANGLE | Rectangle.&nbsp;&nbsp; |
| ARKUI_SHAPE_TYPE_CIRCLE    | Circle.&nbsp;&nbsp;    |
| ARKUI_SHAPE_TYPE_ELLIPSE   | Ellipse.&nbsp;&nbsp;   |
| ARKUI_SHAPE_TYPE_PATH      | Path Type&nbsp;&nbsp;  |


### ArkUI_SliderBlockStyle

```
enum ArkUI_SliderBlockStyle
```
**Description**

Defines the shape of the slider.

**Since**: 12

| Value                            | Description                                  |
| -------------------------------- | -------------------------------------------- |
| ARKUI_SLIDER_BLOCK_STYLE_DEFAULT | Round slider.&nbsp;&nbsp;                    |
| ARKUI_SLIDER_BLOCK_STYLE_IMAGE   | Slider with an image background.&nbsp;&nbsp; |
| ARKUI_SLIDER_BLOCK_STYLE_SHAPE   | Slider in a custom shape.&nbsp;&nbsp;        |


### ArkUI_SliderDirection

```
enum ArkUI_SliderDirection
```
**Description**

Enumerates the scroll directions of the slider.

**Since**: 12

| Value                             | Description                       |
| --------------------------------- | --------------------------------- |
| ARKUI_SLIDER_DIRECTION_VERTICAL   | Vertical direction.&nbsp;&nbsp;   |
| ARKUI_SLIDER_DIRECTION_HORIZONTAL | Horizontal direction.&nbsp;&nbsp; |


### ArkUI_SliderStyle

```
enum ArkUI_SliderStyle
```
**Description**

Enumerates the slider styles.

**Since**: 12

| Value                      | Description                                   |
| -------------------------- | --------------------------------------------- |
| ARKUI_SLIDER_STYLE_OUT_SET | The slider is on the slider rail.&nbsp;&nbsp; |
| ARKUI_SLIDER_STYLE_IN_SET  | The slider is in the slider rail.&nbsp;&nbsp; |


### ArkUI_StickyStyle

```
enum ArkUI_StickyStyle
```
**Description**

Enumerates the modes for pinning the header to the top or the footer to the bottom.

**Since**: 12

| Value                     | Description                                                  |
| ------------------------- | ------------------------------------------------------------ |
| ARKUI_STICKY_STYLE_NONE   | In the **\<ListItemGroup>** component, the header is not pinned to the top, and the footer is not pinned to the bottom.&nbsp;&nbsp; |
| ARKUI_STICKY_STYLE_HEADER | In the **\<ListItemGroup>** component, the header is pinned to the top, and the footer is not pinned to the bottom.&nbsp;&nbsp; |
| ARKUI_STICKY_STYLE_FOOTER | In the **\<ListItemGroup>** component, the footer is pinned to the bottom, and the header is not pinned to the top.&nbsp;&nbsp; |
| ARKUI_STICKY_STYLE_BOTH   | In the list item group, the footer is pinned to the bottom, and the header is pinned to the top.&nbsp;&nbsp; |

### ArkUI_SwiperDisplayModeType

```
enum ArkUI_SwiperDisplayModeType
```
**Description**

Enumerates the modes in which elements are displayed along the main axis of the **\<Swiper>** component.

**Since**: 12

| Value                                 | Description                                                  |
| ------------------------------------- | ------------------------------------------------------------ |
| ARKUI_SWIPER_DISPLAY_MODE_STRETCH     | The slide width of the **\<Swiper>** component is equal to the width of the component.&nbsp;&nbsp; |
| ARKUI_SWIPER_DISPLAY_MODE_AUTO_LINEAR | The slide width of the **\<Swiper>** component is equal to the width of the leftmost child component in the viewport.&nbsp;&nbsp; |


### ArkUI_SwiperArrow

```
enum ArkUI_SwiperArrow
```
**Description**

Enumerates arrow styles of the navigation point indicator.

**Since**: 12

| Value                            | Description                                                  |
| -------------------------------- | ------------------------------------------------------------ |
| ARKUI_SWIPER_ARROW_HIDE          | The arrow is not displayed for the navigation point indicator.&nbsp;&nbsp; |
| ARKUI_SWIPER_ARROW_SHOW          | The arrow is displayed for the navigation point indicator.&nbsp;&nbsp; |
| ARKUI_SWIPER_ARROW_SHOW_ON_HOVER | The arrow is displayed only when the mouse pointer hovers over the navigation point indicator.&nbsp;&nbsp; |


### ArkUI_SwiperIndicatorType

```
enum ArkUI_SwiperIndicatorType
```
**Description**

Enumerates the navigation point indicator types of the **\<Swiper>** component.

**Since**: 12

| Value                             | Description             |
| --------------------------------- | ----------------------- |
| ARKUI_SWIPER_INDICATOR_TYPE_DOT   | Dot type.&nbsp;&nbsp;   |
| ARKUI_SWIPER_INDICATOR_TYPE_DIGIT | Digit type.&nbsp;&nbsp; |


### ArkUI_SwiperNestedScrollMode

```
enum ArkUI_SwiperNestedScrollMode
```
**Description**

Nested scrolling mode of the **\<Swiper>** component and its parent container.

**Since**: 12

| Value                                 | Description                                                  |
| ------------------------------------- | ------------------------------------------------------------ |
| ARKUI_SWIPER_NESTED_SRCOLL_SELF_ONLY  | The scrolling is contained within the **\<Swiper>** component, and no scroll chaining occurs, that is, the parent container does not scroll when the component scrolling reaches the boundary.&nbsp;&nbsp; |
| ARKUI_SWIPER_NESTED_SRCOLL_SELF_FIRST | The **\<Swiper>** component scrolls first, and when it hits the boundary, the parent container scrolls. When the parent container hits the boundary, its edge effect is displayed. If no edge effect is specified for the parent container, the edge effect of the child component is displayed instead.&nbsp;&nbsp; |


### ArkUI_TextAlignment

```
enum ArkUI_TextAlignment
```
**Description**

Enumerates the text alignment mode.

**Since**: 12

| Value                        | Description                            |
| ---------------------------- | -------------------------------------- |
| ARKUI_TEXT_ALIGNMENT_START   | Aligned with the start.&nbsp;&nbsp;    |
| ARKUI_TEXT_ALIGNMENT_CENTER  | Horizontally centered.&nbsp;&nbsp;     |
| ARKUI_TEXT_ALIGNMENT_END     | Aligned with the end.&nbsp;&nbsp;      |
| ARKUI_TEXT_ALIGNMENT_JUSTIFY | Aligned with both margins.&nbsp;&nbsp; |


### ArkUI_TextAreaType

```
enum ArkUI_TextAreaType
```
**Description**

Enumerates the text box types.

**Since**: 12

| Value                            | Description                           |
| -------------------------------- | ------------------------------------- |
| ARKUI_TEXTAREA_TYPE_NORMAL       | Normal input mode.&nbsp;&nbsp;        |
| ARKUI_TEXTAREA_TYPE_NUMBER       | Number input mode.&nbsp;&nbsp;        |
| ARKUI_TEXTAREA_TYPE_PHONE_NUMBER | Phone number input mode.&nbsp;&nbsp;  |
| ARKUI_TEXTAREA_TYPE_EMAIL        | Email address input mode.&nbsp;&nbsp; |


### ArkUI_TextCase

```
enum ArkUI_TextCase
```
**Description**

Defines the enumerated values of text case.

**Since**: 12

| Value                  | Description                                            |
| ---------------------- | ------------------------------------------------------ |
| ARKUI_TEXT_CASE_NORMAL | The original case of the text is retained.&nbsp;&nbsp; |
| ARKUI_TEXT_CASE_LOWER  | All letters in the text are in lowercase.&nbsp;&nbsp;  |
| ARKUI_TEXT_CASE_UPPER  | All letters in the text are in uppercase.&nbsp;&nbsp;  |


### ArkUI_TextCopyOptions

```
enum ArkUI_TextCopyOptions
```
**Description**

Defines whether copy and paste is allowed for text content.

**Since**: 12

| Value                                | Description                                    |
| ------------------------------------ | ---------------------------------------------- |
| ARKUI_TEXT_COPY_OPTIONS_NONE         | Copy is not allowed.&nbsp;&nbsp;               |
| ARKUI_TEXT_COPY_OPTIONS_IN_APP       | Intra-application copy is allowed.&nbsp;&nbsp; |
| ARKUI_TEXT_COPY_OPTIONS_LOCAL_DEVICE | Intra-device copy is allowed.&nbsp;&nbsp;      |
| ARKUI_TEXT_COPY_OPTIONS_CROSS_DEVICE | Cross-device copy is allowed.&nbsp;&nbsp;      |


### ArkUI_TextDataDetectorType

```
enum ArkUI_TextDataDetectorType
```
**Description**

Enumerates the entity types of text recognition.

**Since**: 12

| Value                                      | Description                  |
| ------------------------------------------ | ---------------------------- |
| ARKUI_TEXT_DATA_DETECTOR_TYPE_PHONE_NUMBER | Phone number.&nbsp;&nbsp;    |
| ARKUI_TEXT_DATA_DETECTOR_TYPE_URL          | Link&nbsp;&nbsp;             |
| ARKUI_TEXT_DATA_DETECTOR_TYPE_EMAIL        | Email address.&nbsp;&nbsp;   |
| ARKUI_TEXT_DATA_DETECTOR_TYPE_ADDRESS      | Network address.&nbsp;&nbsp; |


### ArkUI_TextDecorationStyle

```
enum ArkUI_TextDecorationStyle
```
**Description**

Enumerates the text decoration styles.

**Since**: 12

| Value                              | Description                    |
| ---------------------------------- | ------------------------------ |
| ARKUI_TEXT_DECORATION_STYLE_SOLID  | Single solid line.&nbsp;&nbsp; |
| ARKUI_TEXT_DECORATION_STYLE_DOUBLE | Double solid line.&nbsp;&nbsp; |
| ARKUI_TEXT_DECORATION_STYLE_DOTTED | Dotted&nbsp;&nbsp;             |
| ARKUI_TEXT_DECORATION_STYLE_DASHED | Dashed&nbsp;&nbsp;             |
| ARKUI_TEXT_DECORATION_STYLE_WAVY   | Wavy style.&nbsp;&nbsp;        |


### ArkUI_TextDecorationType

```
enum ArkUI_TextDecorationType
```
**Description**

Enumerates the text decoration types.

**Since**: 12

| Value                                   | Description                        |
| --------------------------------------- | ---------------------------------- |
| ARKUI_TEXT_DECORATION_TYPE_NONE         | No text decoration.&nbsp;&nbsp;    |
| ARKUI_TEXT_DECORATION_TYPE_UNDERLINE    | Line under the text.&nbsp;&nbsp;   |
| ARKUI_TEXT_DECORATION_TYPE_OVERLINE     | Line over the text.&nbsp;&nbsp;    |
| ARKUI_TEXT_DECORATION_TYPE_LINE_THROUGH | Line through the text.&nbsp;&nbsp; |


### ArkUI_TextHeightAdaptivePolicy

```
enum ArkUI_TextHeightAdaptivePolicy
```
**Description**

Defines how the adaptive height is determined for the text.

**Since**: 12

| Value                                                     | Description                                                  |
| --------------------------------------------------------- | ------------------------------------------------------------ |
| ARKUI_TEXT_HEIGHT_ADAPTIVE_POLICY_MAX_LINES_FIRST         | Prioritize the **maxLines** settings.&nbsp;&nbsp;            |
| ARKUI_TEXT_HEIGHT_ADAPTIVE_POLICY_MIN_FONT_SIZE_FIRST     | Prioritize the **minFontSize** settings.&nbsp;&nbsp;         |
| ARKUI_TEXT_HEIGHT_ADAPTIVE_POLICY_LAYOUT_CONSTRAINT_FIRST | Prioritize the layout constraint settings in terms of height.&nbsp;&nbsp; |


### ArkUI_TextInputContentType

```
enum ArkUI_TextInputContentType
```
**Description**

Enumerates the autofill types.

**Since**: 12

| Value                                                   | Description                                                  |
| ------------------------------------------------------- | ------------------------------------------------------------ |
| ARKUI_TEXTINPUT_CONTENT_TYPE_USER_NAME                  | Username. Password Vault, when enabled, can automatically save and fill in usernames.&nbsp;&nbsp; |
| ARKUI_TEXTINPUT_CONTENT_TYPE_PASSWORD                   | Password. Password Vault, when enabled, can automatically save and fill in passwords.&nbsp;&nbsp; |
| ARKUI_TEXTINPUT_CONTENT_TYPE_NEW_PASSWORD               | New password. Password Vault, when enabled, can automatically generate a new password.&nbsp;&nbsp; |
| ARKUI_TEXTINPUT_CONTENT_TYPE_FULL_STREET_ADDRESS        | Full street address. The scenario-based autofill feature, when enabled, can automatically save and fill in full street addresses.&nbsp;&nbsp; |
| ARKUI_TEXTINPUT_CONTENT_TYPE_HOUSE_NUMBER               | House number. The scenario-based autofill feature, when enabled, can automatically save and fill in house numbers.&nbsp;&nbsp; |
| ARKUI_TEXTINPUT_CONTENT_TYPE_DISTRICT_ADDRESS           | District and county. The scenario-based autofill feature, when enabled, can automatically save and fill in districts and counties.&nbsp;&nbsp; |
| ARKUI_TEXTINPUT_CONTENT_TYPE_CITY_ADDRESS               | City. The scenario-based autofill feature, when enabled, can automatically save and fill in cities.&nbsp;&nbsp; |
| ARKUI_TEXTINPUT_CONTENT_TYPE_PROVINCE_ADDRESS           | Province. The scenario-based autofill feature, when enabled, can automatically save and fill in provinces.&nbsp;&nbsp; |
| ARKUI_TEXTINPUT_CONTENT_TYPE_COUNTRY_ADDRESS            | Country. The scenario-based autofill feature, when enabled, can automatically save and fill in countries.&nbsp;&nbsp; |
| ARKUI_TEXTINPUT_CONTENT_TYPE_PERSON_FULL_NAME           | Full name. The scenario-based autofill feature, when enabled, can automatically save and fill in full names.&nbsp;&nbsp; |
| ARKUI_TEXTINPUT_CONTENT_TYPE_PERSON_LAST_NAME           | Last name. The scenario-based autofill feature, when enabled, can automatically save and fill in last names.&nbsp;&nbsp; |
| ARKUI_TEXTINPUT_CONTENT_TYPE_PERSON_FIRST_NAME          | First name. The scenario-based autofill feature, when enabled, can automatically save and fill in first names.&nbsp;&nbsp; |
| ARKUI_TEXTINPUT_CONTENT_TYPE_PHONE_NUMBER               | Phone number. The scenario-based autofill feature, when enabled, can automatically save and fill in phone numbers.&nbsp;&nbsp; |
| ARKUI_TEXTINPUT_CONTENT_TYPE_PHONE_COUNTRY_CODE         | Country code. The scenario-based autofill feature, when enabled, can automatically save and fill in country codes.&nbsp;&nbsp; |
| ARKUI_TEXTINPUT_CONTENT_TYPE_FULL_PHONE_NUMBER          | Phone number with country code. The scenario-based autofill feature, when enabled, can automatically save and fill in phone numbers with country codes.&nbsp;&nbsp; |
| ARKUI_TEXTINPUT_CONTENT_EMAIL_ADDRESS                   | Email address. The scenario-based autofill feature, when enabled, can automatically save and fill in email addresses.&nbsp;&nbsp; |
| ARKUI_TEXTINPUT_CONTENT_TYPE_BANK_CARD_NUMBER           | Bank card number. The scenario-based autofill feature, when enabled, can automatically save and fill in bank card numbers.&nbsp;&nbsp; |
| ARKUI_TEXTINPUT_CONTENT_TYPE_ID_CARD_NUMBER             | ID card number. The scenario-based autofill feature, when enabled, can automatically save and fill in ID card numbers.&nbsp;&nbsp; |
| ARKUI_TEXTINPUT_CONTENT_TYPE_NICKNAME                   | Nickname. The scenario-based autofill feature, when enabled, can automatically save and fill in nicknames.&nbsp;&nbsp; |
| ARKUI_TEXTINPUT_CONTENT_TYPE_DETAIL_INFO_WITHOUT_STREET | Address information without street address. The scenario-based autofill feature, when enabled, can automatically save and fill in address information without street addresses.&nbsp;&nbsp; |
| ARKUI_TEXTINPUT_CONTENT_TYPE_FORMAT_ADDRESS             | Standard address. The scenario-based autofill feature, when enabled, can automatically save and fill in standard addresses.&nbsp;&nbsp; |


### ArkUI_TextInputStyle

```
enum ArkUI_TextInputStyle
```
**Description**

Enumerates the text input styles.

**Since**: 12

| Value                         | Description                                                  |
| ----------------------------- | ------------------------------------------------------------ |
| ARKUI_TEXTINPUT_STYLE_DEFAULT | Default style. The caret width is fixed at 1.5 vp, and the caret height is subject to the background height and font size of the selected text.&nbsp;&nbsp; |
| ARKUI_TEXTINPUT_STYLE_INLINE  | Inline input style. The background height of the selected text is the same as the height of the text box.&nbsp;&nbsp; |


### ArkUI_TextInputType

```
enum ArkUI_TextInputType
```
**Description**

Enumerates the text input types.

**Since**: 12

| Value                                     | Description                                         |
| ----------------------------------------- | --------------------------------------------------- |
| ARKUI_TEXTINPUT_TYPE_NORMAL               | Normal input mode.&nbsp;&nbsp;                      |
| ARKUI_TEXTINPUT_TYPE_NUMBER               | Number input mode.&nbsp;&nbsp;                      |
| ARKUI_TEXTINPUT_TYPE_PHONE_NUMBER         | Phone number input mode.&nbsp;&nbsp;                |
| ARKUI_TEXTINPUT_TYPE_EMAIL                | Email address input mode.&nbsp;&nbsp;               |
| ARKUI_TEXTINPUT_TYPE_PASSWORD             | Password input mode.&nbsp;&nbsp;                    |
| ARKUI_TEXTINPUT_TYPE_NUMBER_PASSWORD      | Numeric password input mode.&nbsp;&nbsp;            |
| ARKUI_TEXTINPUT_TYPE_SCREEN_LOCK_PASSWORD | Lock screen password input mode.&nbsp;&nbsp;        |
| ARKUI_TEXTINPUT_TYPE_USER_NAME            | Username input mode.&nbsp;&nbsp;                    |
| ARKUI_TEXTINPUT_TYPE_NEW_PASSWORD         | New password input mode.&nbsp;&nbsp;                |
| ARKUI_TEXTINPUT_TYPE_NUMBER_DECIMAL       | Number input mode with a decimal point.&nbsp;&nbsp; |


### ArkUI_TextOverflow

```
enum ArkUI_TextOverflow
```
**Description**

Enumerates the display modes when the text is too long.

**Since**: 12

| Value                        | Description                                                  |
| ---------------------------- | ------------------------------------------------------------ |
| ARKUI_TEXT_OVERFLOW_NONE     | Extra-long text is not clipped.&nbsp;&nbsp;                  |
| ARKUI_TEXT_OVERFLOW_CLIP     | Extra-long text is clipped.&nbsp;&nbsp;                      |
| ARKUI_TEXT_OVERFLOW_ELLIPSIS | An ellipsis (...) is used to represent text overflow.&nbsp;&nbsp; |
| ARKUI_TEXT_OVERFLOW_MARQUEE  | Text continuously scrolls when text overflow occurs.&nbsp;&nbsp; |


### ArkUI_TextPickerRangeType

```
enum ArkUI_TextPickerRangeType
```
**Description**

Enumerates the types of the text picker.

**Since**: 12

| Value                                            | Description                                                 |
| ------------------------------------------------ | ----------------------------------------------------------- |
| ARKUI_TEXTPICKER_RANGETYPE_SINGLE                | Single-column text picker.&nbsp;&nbsp;                      |
| ARKUI_TEXTPICKER_RANGETYPE_MULTI                 | Multi-column text picker.&nbsp;&nbsp;                       |
| ARKUI_TEXTPICKER_RANGETYPE_RANGE_CONTENT         | Single-column text picker with image resources.&nbsp;&nbsp; |
| ARKUI_TEXTPICKER_RANGETYPE_CASCADE_RANGE_CONTENT | Interconnected multi-column text picker.&nbsp;&nbsp;        |


### ArkUI_ThemeColorMode

```
enum ArkUI_ThemeColorMode
```

| Value                         | Description                                  |
| ----------------------------- | -------------------------------------------- |
| ARKUI_THEME_COLOR_MODE_SYSTEM | Following the system color mode.&nbsp;&nbsp; |
| ARKUI_THEME_COLOR_MODE_LIGHT  | Light color mode.&nbsp;&nbsp;                |
| ARKUI_THEME_COLOR_MODE_DARK   | Dark color mode.&nbsp;&nbsp;                 |


### ArkUI_TransitionEdge

```
enum ArkUI_TransitionEdge
```
**Description**

Enumerates the slide-in and slide-out positions of the component from the screen edge during transition.

**Since**: 12

| Value                        | Description                            |
| ---------------------------- | -------------------------------------- |
| ARKUI_TRANSITION_EDGE_TOP    | Top edge of the window.&nbsp;&nbsp;    |
| ARKUI_TRANSITION_EDGE_BOTTOM | Bottom edge of the window.&nbsp;&nbsp; |
| ARKUI_TRANSITION_EDGE_START  | Left edge of the window.&nbsp;&nbsp;   |
| ARKUI_TRANSITION_EDGE_END    | Right edge of the window.&nbsp;&nbsp;  |


### ArkUI_VerticalAlignment

```
enum ArkUI_VerticalAlignment
```
**Description**

Defines the vertical alignment mode.

**Since**: 12

| Value                           | Description                                                  |
| ------------------------------- | ------------------------------------------------------------ |
| ARKUI_VERTICAL_ALIGNMENT_TOP    | Top aligned.&nbsp;&nbsp;                                     |
| ARKUI_VERTICAL_ALIGNMENT_CENTER | Aligned with the center. This is the default alignment mode.&nbsp;&nbsp; |
| ARKUI_VERTICAL_ALIGNMENT_BOTTOM | Bottom aligned.&nbsp;&nbsp;                                  |


### ArkUI_Visibility

```
enum ArkUI_Visibility
```
**Description**

Enumerates the visibility values.

**Since**: 12

| Value                    | Description                                                  |
| ------------------------ | ------------------------------------------------------------ |
| ARKUI_VISIBILITY_VISIBLE | The component is visible.&nbsp;&nbsp;                        |
| ARKUI_VISIBILITY_HIDDEN  | The component is hidden, and a placeholder is used for it in the layout.&nbsp;&nbsp; |
| ARKUI_VISIBILITY_NONE    | The component is hidden. It is not involved in the layout, and no placeholder is used for it.&nbsp;&nbsp; |


### ArkUI_WordBreak

```
enum ArkUI_WordBreak
```
**Description**

Enumerates the word break rules.

**Since**: 12

| Value                       | Description                                                  |
| --------------------------- | ------------------------------------------------------------ |
| ARKUI_WORD_BREAK_NORMAL     | Word breaks can occur between any two characters for Chinese, Japanese, and Korean (CJK) text, but can occur only at a space character for non-CJK text (such as English).&nbsp;&nbsp; |
| ARKUI_WORD_BREAK_BREAK_ALL  | Word breaks can occur between any two characters for non-CJK text. CJK text behavior is the same as for **NORMAL**.&nbsp;&nbsp; |
| ARKUI_WORD_BREAK_BREAK_WORD | This option has the same effect as **BREAK_ALL** for non-CJK text, except that if it preferentially wraps lines at appropriate characters (for example, spaces) whenever possible. CJK text behavior is the same as for **NORMAL**. */ |

### ArkUI_XComponentType

```
enum ArkUI_XComponentType
```
**Description**

Defines the enumerated values of the XComponent type.

**Since**: 12

| Value                         | Description                                                  |
| ----------------------------- | ------------------------------------------------------------ |
| ARKUI_XCOMPONENT_TYPE_SURFACE | The custom content of EGL/OpenGL ES and media data is displayed individually on the screen.&nbsp;&nbsp; |
| ARKUI_XCOMPONENT_TYPE_TEXTURE | The custom content of EGL/OpenGL ES and media data is grouped and displayed together with content of the component.&nbsp;&nbsp; |


## Function Description


### OH_ArkUI_ImageAnimatorFrameInfo_CreateFromDrawableDescriptor()

```
ArkUI_ImageAnimatorFrameInfo* OH_ArkUI_ImageAnimatorFrameInfo_CreateFromDrawableDescriptor (ArkUI_DrawableDescriptor * drawable)
```
**Description**

Use the DrawableDescriptor object to create frame image information. The image formats are Resource and PixelMap.

**Since**: 12

**Parameters**

| Name     | Description                                                  |
| -------- | ------------------------------------------------------------ |
| drawable | Pointer to the ArkUI_DrawableDescriptor object created using Resource or PixelMap. |

**Returns**

Pointer to the frame image object.


### OH_ArkUI_ImageAnimatorFrameInfo_CreateFromString()

```
ArkUI_ImageAnimatorFrameInfo* OH_ArkUI_ImageAnimatorFrameInfo_CreateFromString (char * src)
```
**Description**

Creates an image frame information object based on an image path, with the image format being SVG, PNG, or JPG.

**Since**: 12

**Parameters**

| Name | Description |
| ---- | ----------- |
| src  | Image path. |

**Returns**

Pointer to the frame image object.


### OH_ArkUI_ImageAnimatorFrameInfo_Dispose()

```
void OH_ArkUI_ImageAnimatorFrameInfo_Dispose (ArkUI_ImageAnimatorFrameInfo * imageInfo)
```
**Description**

Pointer to the frame image object to be destroyed.

**Since**: 12

**Parameters**

| Name      | Description                        |
| --------- | ---------------------------------- |
| imageInfo | Pointer to the frame image object. |


### OH_ArkUI_ImageAnimatorFrameInfo_GetDuration()

```
int32_t OH_ArkUI_ImageAnimatorFrameInfo_GetDuration (ArkUI_ImageAnimatorFrameInfo * imageInfo)
```
**Description**

Obtains the playback duration of an image.

**Since**: 12

**Parameters**

| Name      | Description                        |
| --------- | ---------------------------------- |
| imageInfo | Pointer to the frame image object. |

**Returns**

* @return Returns the playback duration of the image, in milliseconds. If **imageInfo** is a null pointer, **0** is returned.


### OH_ArkUI_ImageAnimatorFrameInfo_GetHeight()

```
int32_t OH_ArkUI_ImageAnimatorFrameInfo_GetHeight (ArkUI_ImageAnimatorFrameInfo * imageInfo)
```
**Description**

Obtains the image height.

**Since**: 12

**Parameters**

| Name      | Description                        |
| --------- | ---------------------------------- |
| imageInfo | Pointer to the frame image object. |

**Returns**

* @return Returns the image height, in PX. If **imageInfo** is a null pointer, **0** is returned.


### OH_ArkUI_ImageAnimatorFrameInfo_GetLeft()

```
int32_t OH_ArkUI_ImageAnimatorFrameInfo_GetLeft (ArkUI_ImageAnimatorFrameInfo * imageInfo)
```
**Description**

Obtains the horizontal coordinate of an image relative to the upper left corner of the component.

**Since**: 12

**Parameters**

| Name      | Description                        |
| --------- | ---------------------------------- |
| imageInfo | Pointer to the frame image object. |

**Returns**

* @return Returns the horizontal coordinate of the image relative to the upper left corner of the component, in PX. If **imageInfo** is a null pointer, **0** is returned.

### OH_ArkUI_ImageAnimatorFrameInfo_GetTop()

```
int32_t OH_ArkUI_ImageAnimatorFrameInfo_GetTop (ArkUI_ImageAnimatorFrameInfo * imageInfo)
```
**Description**

Obtains the vertical coordinate of an image relative to the upper left corner of the component.

**Since**: 12

**Parameters**

| Name      | Description                        |
| --------- | ---------------------------------- |
| imageInfo | Pointer to the frame image object. |

**Returns**

* @return Returns the vertical coordinate of the image relative to the upper left corner of the component, in PX. If **imageInfo** is a null pointer, **0** is returned.


### OH_ArkUI_ImageAnimatorFrameInfo_GetWidth()

```
int32_t OH_ArkUI_ImageAnimatorFrameInfo_GetWidth (ArkUI_ImageAnimatorFrameInfo * imageInfo)
```
**Description**

Obtains the image width.

**Since**: 12

**Parameters**

| Name      | Description                        |
| --------- | ---------------------------------- |
| imageInfo | Pointer to the frame image object. |

**Returns**

* @return Returns the image width, in PX. If **imageInfo** is a null pointer, **0** is returned.


### OH_ArkUI_ImageAnimatorFrameInfo_SetDuration()

```
void OH_ArkUI_ImageAnimatorFrameInfo_SetDuration (ArkUI_ImageAnimatorFrameInfo * imageInfo, int32_t duration )
```
**Description**

Sets the playback duration of an image.

**Since**: 12

**Parameters**

| Name      | Description                                     |
| --------- | ----------------------------------------------- |
| imageInfo | Pointer to the frame image object.              |
| duration  | Playback duration of an image, in milliseconds. |


### OH_ArkUI_ImageAnimatorFrameInfo_SetHeight()

```
void OH_ArkUI_ImageAnimatorFrameInfo_SetHeight (ArkUI_ImageAnimatorFrameInfo * imageInfo, int32_t height )
```
**Description**

    // Set the image height.

**Since**: 12

**Parameters**

| Name      | Description                        |
| --------- | ---------------------------------- |
| imageInfo | Pointer to the frame image object. |
| height    | Image height, in PX.               |


### OH_ArkUI_ImageAnimatorFrameInfo_SetLeft()

```
void OH_ArkUI_ImageAnimatorFrameInfo_SetLeft (ArkUI_ImageAnimatorFrameInfo * imageInfo, int32_t left )
```
**Description**

Sets the horizontal coordinate of an image relative to the upper left corner of the component.

**Since**: 12

**Parameters**

| Name      | Description                                                  |
| --------- | ------------------------------------------------------------ |
| imageInfo | Pointer to the frame image object.                           |
| left      | Horizontal coordinate of the image relative to the upper left corner of the widget, in PX. |


### OH_ArkUI_ImageAnimatorFrameInfo_SetTop()

```
void OH_ArkUI_ImageAnimatorFrameInfo_SetTop (ArkUI_ImageAnimatorFrameInfo * imageInfo, int32_t top )
```
**Description**

Sets the vertical coordinate of an image relative to the upper left corner of the component.

**Since**: 12

**Parameters**

| Name      | Description                                                  |
| --------- | ------------------------------------------------------------ |
| imageInfo | Pointer to the frame image object.                           |
| top       | Vertical coordinate of the image relative to the upper left corner of the widget, in PX. |


### OH_ArkUI_ImageAnimatorFrameInfo_SetWidth()

```
void OH_ArkUI_ImageAnimatorFrameInfo_SetWidth (ArkUI_ImageAnimatorFrameInfo * imageInfo, int32_t width )
```
**Description**

    // Set the image width.

**Since**: 12

**Parameters**

| Name      | Description                        |
| --------- | ---------------------------------- |
| imageInfo | Pointer to the frame image object. |
| width     | Image width, in PX.                |


### OH_ArkUI_List_CloseAllSwipeActions()

```
int32_t OH_ArkUI_List_CloseAllSwipeActions (ArkUI_NodeHandle node, void * userData, void(*)(void *userData) onFinish )
```
**Description**

Collapse the expanded ListItem.

**Since**: 12

**Parameters**

| Name     | Description                                                  |
| -------- | ------------------------------------------------------------ |
| node     | Node object for which an event needs to be registered.       |
| userData | Customized event parameter, which is carried in the callback parameter when an event is triggered. |
| onFinish | Callback triggered after the collapse animation is complete. |

**Returns**

 The ARKUI_ERROR_CODE_NO_ERROR is successful. The parameter of the ARKUI_ERROR_CODE_PARAM_INVALID function is abnormal. The ARKUI_ERROR_CODE_ATTRIBUTE_OR_EVENT_NOT_SUPPORTED component does not support this event.

### OH_ArkUI_ListChildrenMainSizeOption_Dispose()

```
void OH_ArkUI_ListChildrenMainSizeOption_Dispose (ArkUI_ListChildrenMainSize * option)
```
**Description**

Destroys a ListChildrenMainSize instance.

**Since**: 12

**Parameters**

| Name   | Description                                    |
| ------ | ---------------------------------------------- |
| option | ListChildrenMainSize instance to be destroyed. |

### OH_ArkUI_ListChildrenMainSizeOption_Create()

```
ArkUI_ListChildrenMainSize* OH_ArkUI_ListChildrenMainSizeOption_Create ()
```
**Description**

Creates a **ListChildrenMainSize** instance.

**Since**: 12

**Returns**

ListChildrenMainSize configuration item instance.


### OH_ArkUI_ListChildrenMainSizeOption_Dispose()

```
void OH_ArkUI_ListChildrenMainSizeOption_Dispose (ArkUI_ListChildrenMainSize * option)
```
**Description**

Destroys a ListChildrenMainSize instance.

**Since**: 12

**Parameters**

| Name   | Description                                    |
| ------ | ---------------------------------------------- |
| option | ListChildrenMainSize instance to be destroyed. |


### OH_ArkUI_ListChildrenMainSizeOption_GetDefaultMainSize()

```
float OH_ArkUI_ListChildrenMainSizeOption_GetDefaultMainSize (ArkUI_ListChildrenMainSize * option)
```
**Description**

Obtains the default size in a **ListChildrenMainSize**instance.

**Since**: 12

**Parameters**

| Name   | Description                    |
| ------ | ------------------------------ |
| option | ListChildrenMainSize instance. |

**Returns**

* @return Returns the default size, in vp. The default value is **0**. If **option** is a null pointer, **-1** is returned.


### OH_ArkUI_ListChildrenMainSizeOption_GetMainSize()

```
float OH_ArkUI_ListChildrenMainSizeOption_GetMainSize (ArkUI_ListChildrenMainSize * option, int32_t index )
```
**Description**

Obtains the value of the ChildrenMainSizeOption array of the List component.

**Since**: 12

**Parameters**

| Name   | Description                                     |
| ------ | ----------------------------------------------- |
| option | ListChildrenMainSize instance.                  |
| index  | Subscript position of the value to be obtained. |

**Returns**

Value of the specific position of the array. *         If a parameter error occurs, **-1** is returned.


### OH_ArkUI_ListChildrenMainSizeOption_Resize()

```
void OH_ArkUI_ListChildrenMainSizeOption_Resize (ArkUI_ListChildrenMainSize * option, int32_t totalSize )
```
**Description**

Resets the array size of ChildrenMainSizeOption of the List component.

**Since**: 12

**Parameters**

| Name      | Description                    |
| --------- | ------------------------------ |
| option    | ListChildrenMainSize instance. |
| totalSize | Array size.                    |


### OH_ArkUI_ListChildrenMainSizeOption_SetDefaultMainSize()

```
int32_t OH_ArkUI_ListChildrenMainSizeOption_SetDefaultMainSize (ArkUI_ListChildrenMainSize * option, float defaultMainSize )
```
**Description**

Sets the default size of ChildrenMainSizeOption of the List component.

**Since**: 12

**Parameters**

| Name            | Description                                            |
| --------------- | ------------------------------------------------------ |
| option          | ListChildrenMainSize instance.                         |
| defaultMainSize | Default size of a list item in a list. The unit is vp. |

**Returns**

 The ARKUI_ERROR_CODE_NO_ERROR is successful. The parameter of the ARKUI_ERROR_CODE_PARAM_INVALID function is abnormal.

 ### OH_ArkUI_ListChildrenMainSizeOption_Splice()

```
int32_t OH_ArkUI_ListChildrenMainSizeOption_Splice (ArkUI_ListChildrenMainSize * option, int32_t index, int32_t deleteCount, int32_t addCount )
```
**Description**

The size of the ChildrenMainSizeOption array of the List component is adjusted.

**Since**: 12

**Parameters**

| Name        | Description                                                  |
| ----------- | ------------------------------------------------------------ |
| option      | ListChildrenMainSize instance.                               |
| index       | Start position of the array whose MainSize is to be modified. |
| deleteCount | Number of MainSize arrays to be deleted starting from index. |
| addCount    | Number of MainSize arrays to be added starting from index.   |

**Returns**

 The ARKUI_ERROR_CODE_NO_ERROR is successful. The parameter of the ARKUI_ERROR_CODE_PARAM_INVALID function is abnormal.


### OH_ArkUI_ListChildrenMainSizeOption_UpdateSize()

```
int32_t OH_ArkUI_ListChildrenMainSizeOption_UpdateSize (ArkUI_ListChildrenMainSize * option, int32_t index, float mainSize )
```
**Description**

Updates the value of the ChildrenMainSizeOption array of the List component.

**Since**: 12

**Parameters**

| Name     | Description                                                  |
| -------- | ------------------------------------------------------------ |
| option   | ListChildrenMainSize instance.                               |
| index    | Start position of the array whose MainSize is to be modified. |
| mainSize | Indicates the actual value.                                  |

**Returns**

 The ARKUI_ERROR_CODE_NO_ERROR is successful. The parameter of the ARKUI_ERROR_CODE_PARAM_INVALID function is abnormal.


### OH_ArkUI_NodeUtils_GetLayoutPosition()

```
int32_t OH_ArkUI_NodeUtils_GetLayoutPosition (ArkUI_NodeHandle node, ArkUI_IntOffset * localOffset )
```
**Description**

Obtains the position of the component's layout area relative to its parent component. * The relative position does not count in transformation attributes, such as translate.

**Since**: 12

**Parameters**

| Name        | Description                                                  |
| ----------- | ------------------------------------------------------------ |
| node        | ArkUI_NodeHandle pointer.                                    |
| localOffset | Offset of the component handle relative to the parent component, in pixels. |

**Returns**

 The ARKUI_ERROR_CODE_NO_ERROR is successful. The parameter of the ARKUI_ERROR_CODE_PARAM_INVALID function is abnormal.


### OH_ArkUI_NodeUtils_GetLayoutPositionInScreen()

```
int32_t OH_ArkUI_NodeUtils_GetLayoutPositionInScreen (ArkUI_NodeHandle node, ArkUI_IntOffset * screenOffset )
```
**Description**

Obtains the position of the component's layout area relative to the screen. * The relative position does not count in transformation attributes, such as translate.

**Since**: 12

**Parameters**

| Name         | Description                                                  |
| ------------ | ------------------------------------------------------------ |
| node         | ArkUI_NodeHandle pointer.                                    |
| screenOffset | Offset of the component handle relative to the screen, in pixels. |

**Returns**

 The ARKUI_ERROR_CODE_NO_ERROR is successful. The parameter of the ARKUI_ERROR_CODE_PARAM_INVALID function is abnormal.


### OH_ArkUI_NodeUtils_GetLayoutPositionInWindow()

```
int32_t OH_ArkUI_NodeUtils_GetLayoutPositionInWindow (ArkUI_NodeHandle node, ArkUI_IntOffset * globalOffset )
```
**Description**

Obtains the position of the component's layout area relative to the window. * The relative position does not count in transformation attributes, such as translate.

**Since**: 12

**Parameters**

| Name         | Description                                                  |
| ------------ | ------------------------------------------------------------ |
| node         | ArkUI_NodeHandle pointer.                                    |
| globalOffset | Offset of the component handle relative to the window, in pixels. |

**Returns**

 The ARKUI_ERROR_CODE_NO_ERROR is successful. The parameter of the ARKUI_ERROR_CODE_PARAM_INVALID function is abnormal.


### OH_ArkUI_NodeUtils_GetLayoutSize()

```
int32_t OH_ArkUI_NodeUtils_GetLayoutSize (ArkUI_NodeHandle node, ArkUI_IntSize * size )
```
**Description**

Obtains the size of the widget layout area. The layout area size does not contain graphic change attributes, such as scaling.

**Since**: 12

**Parameters**

| Name | Description                                               |
| ---- | --------------------------------------------------------- |
| node | ArkUI_NodeHandle pointer.                                 |
| size | Size of the drawing area of the widget handle, in pixels. |

**Returns**

 The ARKUI_ERROR_CODE_NO_ERROR is successful. The parameter of the ARKUI_ERROR_CODE_PARAM_INVALID function is abnormal.


### OH_ArkUI_NodeUtils_GetPositionWithTranslateInScreen()

```
int32_t OH_ArkUI_NodeUtils_GetPositionWithTranslateInScreen (ArkUI_NodeHandle node, ArkUI_IntOffset * translateOffset )
```
**Description**

Obtains the position of a component on the screen, including the image translation change attribute.

**Since**: 12

**Parameters**

| Name            | Description                                                  |
| --------------- | ------------------------------------------------------------ |
| node            | ArkUI_NodeHandle pointer.                                    |
| translateOffset | * @param translateOffset Indicates the accumulated offset of the component, its parent component, and its ancestor node, in px. |

**Returns**

 The ARKUI_ERROR_CODE_NO_ERROR is successful. The parameter of the ARKUI_ERROR_CODE_PARAM_INVALID function is abnormal.


### OH_ArkUI_NodeUtils_GetPositionWithTranslateInWindow()

```
int32_t OH_ArkUI_NodeUtils_GetPositionWithTranslateInWindow (ArkUI_NodeHandle node, ArkUI_IntOffset * translateOffset )
```
**Description**

Obtains the position of the component in the window, including the translate attribute.

**Since**: 12

**Parameters**

| Name            | Description                                                  |
| --------------- | ------------------------------------------------------------ |
| node            | ArkUI_NodeHandle pointer.                                    |
| translateOffset | * @param translateOffset Indicates the accumulated offset of the component, its parent component, and its ancestor node, in px. |

**Returns**

 The ARKUI_ERROR_CODE_NO_ERROR is successful. The parameter of the ARKUI_ERROR_CODE_PARAM_INVALID function is abnormal.


### OH_ArkUI_StyledString_AddPlaceholder()

```
void OH_ArkUI_StyledString_AddPlaceholder (ArkUI_StyledString * handle, OH_Drawing_PlaceholderSpan * placeholder )
```
**Description**
Adds a placeholder. 

**Since**: 12

**Parameters**

| Name        | Description                                          |
| ----------- | ---------------------------------------------------- |
| handle      | Pointer to an **OH_Drawing_FontCollection** object.  |
| placeholder | Pointer to an **OH_Drawing_PlaceholderSpan** object. |


### OH_ArkUI_StyledString_AddText()

```
void OH_ArkUI_StyledString_AddText (ArkUI_StyledString * handle, const char * content )
```
**Description**
Sets the text content based on the current format string style.

**Since**: 12

**Parameters**

| Name    | Description                                         |
| ------- | --------------------------------------------------- |
| handle  | Pointer to an **OH_Drawing_FontCollection** object. |
| content | Pointer to the text content.                        |


### OH_ArkUI_StyledString_Create()

```
ArkUI_StyledString* OH_ArkUI_StyledString_Create (OH_Drawing_TypographyStyle * style, OH_Drawing_FontCollection * collection )
```
**Description**
Creates an **OH_Drawing_Typography** object.

**Since**: 12

**Parameters**

| Name       | Description                                                  |
| ---------- | ------------------------------------------------------------ |
| style      | Pointer to an **OH_Drawing_TypographyStyle** object, which is obtained by calling **OH_Drawing_CreateTypographyStyle**. |
| collection | Pointer to an **OH_Drawing_FontCollection** object, which is obtained by calling **OH_Drawing_CreateFontCollection**. |

**Returns**

Creates an **OH_Drawing_Typography** object. If the object returns a null pointer, the creation fails. The possible cause is that the English address space is full, or the style or collection parameter is abnormal, for example, a null pointer.


### OH_ArkUI_StyledString_CreateTypography()

```
OH_Drawing_Typography* OH_ArkUI_StyledString_CreateTypography (ArkUI_StyledString * handle)
```
**Description**
Creates a pointer to the OH_Drawing_Typography object based on the format string object for text calculation and typesetting in advance.

**Since**: 12

**Parameters**

| Name   | Description                                         |
| ------ | --------------------------------------------------- |
| handle | Pointer to an **OH_Drawing_FontCollection** object. |

**Returns**

Returns the pointer to the **OH_Drawing_Typography** object created. If the object returns a null pointer, it indicates that the creation fails. The possible cause is that the handle parameter is abnormal, for example, the null pointer.


### OH_ArkUI_StyledString_Destroy()

```
void OH_ArkUI_StyledString_Destroy (ArkUI_StyledString * handle)
```
**Description**
Destroys an **OH_Drawing_TypographyCreate** object and reclaims the memory occupied by the object.

**Since**: 12

**Parameters**

| Name   | Description                                         |
| ------ | --------------------------------------------------- |
| handle | Pointer to an **OH_Drawing_FontCollection** object. |


### OH_ArkUI_StyledString_PopTextStyle()

```
void OH_ArkUI_StyledString_PopTextStyle (ArkUI_StyledString * handle)
```
**Description**
Removes the top style from the current formatted string object.

**Since**: 12

**Parameters**

| Name   | Description                                         |
| ------ | --------------------------------------------------- |
| handle | Pointer to an **OH_Drawing_FontCollection** object. |


### OH_ArkUI_StyledString_PushTextStyle()

```
void OH_ArkUI_StyledString_PushTextStyle (ArkUI_StyledString * handle, OH_Drawing_TextStyle * style )
```
**Description**
Sets the new typesetting style to the top of the current format string style stack.

**Since**: 12

**Parameters**

| Name   | Description                                         |
| ------ | --------------------------------------------------- |
| handle | Pointer to an **OH_Drawing_FontCollection** object. |
| style  | Pointer to an **OH_Drawing_TextStyle** object.      |

### OH_ArkUI_WaterFlowSectionOption_RegisterGetItemMainSizeCallbackByIndex()

```
void OH_ArkUI_WaterFlowSectionOption_RegisterGetItemMainSizeCallbackByIndex (ArkUI_WaterFlowSectionOption * option, int32_t index, float(*)(int32_t itemIndex) callback )
```
**Description**

Obtains the main axis size of a specified item based on **flowItemIndex** through a water flow section configuration.

**Since**: 12

**Parameters**

| Name     | Description                                                  |
| -------- | ------------------------------------------------------------ |
| option   | Describes the configuraiton of the water flow item section.  |
| index    | FlowItem index.                                              |
| callback | Obtains the spindle size of a specified item based on the index. |

### OH_ArkUI_WaterFlowSectionOption_GetSize()

```
int32_t OH_ArkUI_WaterFlowSectionOption_GetSize (ArkUI_WaterFlowSectionOption * option)
```
**Description**

Sets the length of the FlowItem group configuration information array.

**Since**: 12

**Parameters**

| Name   | Description                                                 |
| ------ | ----------------------------------------------------------- |
| option | Describes the configuraiton of the water flow item section. |

**Returns**

Size of the array. If -1 is returned, an error code indicating failure is returned. The possible cause is that the **option** parameter is abnormal, for example, a null pointer.

### OH_ArkUI_ListItemSwipeActionItem_Create()

```
ArkUI_ListItemSwipeActionItem* OH_ArkUI_ListItemSwipeActionItem_Create ()
```
**Description**
Creates an **ListItemSwipeActionItem** instance.

**Since**: 12

**Returns**

ListItemSwipeActionItem configuration item instance.


### OH_ArkUI_ListItemSwipeActionItem_Dispose()

```
void OH_ArkUI_ListItemSwipeActionItem_Dispose (ArkUI_ListItemSwipeActionItem * item)
```
**Description**
Destroys a ListItemSwipeActionItem instance.

**Since**: 12

**Parameters**

| Name | Description                                  |
| ---- | -------------------------------------------- |
| item | ListItemSwipeActionItem instance to destroy. |


### OH_ArkUI_ListItemSwipeActionItem_GetActionAreaDistance()

```
float OH_ArkUI_ListItemSwipeActionItem_GetActionAreaDistance (ArkUI_ListItemSwipeActionItem * item)
```
**Description**
Obtains the swipe distance threshold for deleting the list item.

**Since**: 12

**Parameters**

| Name | Description                       |
| ---- | --------------------------------- |
| item | ListItemSwipeActionItem instance. |

**Returns**

* @return Returns the swipe distance threshold for deleting the list item. Return **0** if an error occurs.


### OH_ArkUI_ListItemSwipeActionItem_SetActionAreaDistance()

```
void OH_ArkUI_ListItemSwipeActionItem_SetActionAreaDistance (ArkUI_ListItemSwipeActionItem * item, float distance )
```
**Description**
Swipe distance threshold for deleting the list item.

**Since**: 12

**Parameters**

| Name     | Description                                                  |
| -------- | ------------------------------------------------------------ |
| item     | ListItemSwipeActionItem instance.                            |
| distance | * @return Returns the swipe distance threshold for deleting the list item. |


### OH_ArkUI_ListItemSwipeActionItem_SetContent()

```
void OH_ArkUI_ListItemSwipeActionItem_SetContent (ArkUI_ListItemSwipeActionItem * item, ArkUI_NodeHandle node )
```
**Description**
Sets the layout content of ListItemSwipeActionItem.

**Since**: 12

**Parameters**

| Name | Description                       |
| ---- | --------------------------------- |
| item | ListItemSwipeActionItem instance. |
| node | Layout information                |


### OH_ArkUI_ListItemSwipeActionItem_SetOnAction()

```
void OH_ArkUI_ListItemSwipeActionItem_SetOnAction (ArkUI_ListItemSwipeActionItem * item, void(*)() callback )
```
**Description**
Sets the callback invoked when the list item is deleted while in the delete area.

**Since**: 12

**Parameters**

| Name     | Description                                                  |
| -------- | ------------------------------------------------------------ |
| item     | ListItemSwipeActionItem instance.                            |
| callback | Callback to invoke when an event of the specified type occurs. |


### OH_ArkUI_ListItemSwipeActionItem_SetOnEnterActionArea()

```
void OH_ArkUI_ListItemSwipeActionItem_SetOnEnterActionArea (ArkUI_ListItemSwipeActionItem * item, void(*)() callback )
```
**Description**
Sets the callback invoked each time the list item enters the delete area.

**Since**: 12

**Parameters**

| Name     | Description                                                  |
| -------- | ------------------------------------------------------------ |
| item     | ListItemSwipeActionItem instance.                            |
| callback | Callback to invoke when an event of the specified type occurs. |

### OH_ArkUI_ListItemSwipeActionItem_SetOnEnterActionAreaWithUserData()

```
void OH_ArkUI_ListItemSwipeActionItem_SetOnEnterActionAreaWithUserData (ArkUI_ListItemSwipeActionItem * item, void * userData, void(*)(void *userData) callback )
```
**Description**

Sets the callback invoked each time the list item enters the delete area.

**Since**: 12

**Parameters**

| Name     | Description                                                  |
| -------- | ------------------------------------------------------------ |
| item     | ListItemSwipeActionItem instance.                            |
| userData | User-defined data.                                           |
| callback | Callback to invoke when an event of the specified type occurs. |


### OH_ArkUI_ListItemSwipeActionItem_SetOnExitActionArea()

```
void OH_ArkUI_ListItemSwipeActionItem_SetOnExitActionArea (ArkUI_ListItemSwipeActionItem * item, void(*)() callback )
```
**Description**
Sets the callback invoked each time the list item exits the delete area.

**Since**: 12

**Parameters**

| Name     | Description                                                  |
| -------- | ------------------------------------------------------------ |
| item     | ListItemSwipeActionItem instance.                            |
| callback | Callback to invoke when an event of the specified type occurs. |

### OH_ArkUI_ListItemSwipeActionItem_SetOnExitActionAreaWithUserData()

```
void OH_ArkUI_ListItemSwipeActionItem_SetOnExitActionAreaWithUserData (ArkUI_ListItemSwipeActionItem * item, void * userData, void(*)(void *userData) callback )
```
**Description**

Sets the callback invoked each time the list item exits the delete area.

**Since**: 12

**Parameters**

| Name     | Description                                                  |
| -------- | ------------------------------------------------------------ |
| item     | ListItemSwipeActionItem instance.                            |
| userData | User-defined data.                                           |
| callback | Callback to invoke when an event of the specified type occurs. |


### OH_ArkUI_ListItemSwipeActionItem_SetOnStateChange()

```
void OH_ArkUI_ListItemSwipeActionItem_SetOnStateChange (ArkUI_ListItemSwipeActionItem * item, void(*)(ArkUI_ListItemSwipeActionState swipeActionState) callback )
```
**Description**
Sets the callback invoked when the swipe state of the list item changes.

**Since**: 12

**Parameters**

| Name     | Description                                               |
| -------- | --------------------------------------------------------- |
| item     | ListItemSwipeActionItem instance.                         |
| callback | Status after the callback event swipeActionState changes. |

### OH_ArkUI_ListItemSwipeActionItem_SetOnStateChangeWithUserData()

```
void OH_ArkUI_ListItemSwipeActionItem_SetOnStateChangeWithUserData (ArkUI_ListItemSwipeActionItem * item, void * userData, void(*)(ArkUI_ListItemSwipeActionState swipeActionState, void *userData) callback )
```
**Description**

Sets the callback invoked when the swipe state of the list item changes.

**Since**: 12

**Parameters**

| Name     | Description                                               |
| -------- | --------------------------------------------------------- |
| item     | ListItemSwipeActionItem instance.                         |
| userData | User-defined data.                                        |
| callback | Status after the callback event swipeActionState changes. |


### OH_ArkUI_ListItemSwipeActionOption_Create()

```
ArkUI_ListItemSwipeActionOption* OH_ArkUI_ListItemSwipeActionOption_Create ()
```
**Description**
Creates a **ListItemSwipeActionOption** instance.

**Since**: 12

**Returns**

ListItemSwipeActionOption configuration item instance.


### OH_ArkUI_ListItemSwipeActionOption_Dispose()

```
void OH_ArkUI_ListItemSwipeActionOption_Dispose (ArkUI_ListItemSwipeActionOption * option)
```
**Description**
Destroys a ListItemSwipeActionOption instance.

**Since**: 12

**Parameters**

| Name   | Description                                    |
| ------ | ---------------------------------------------- |
| option | ListItemSwipeActionOption instance to destroy. |


### OH_ArkUI_ListItemSwipeActionOption_GetEdgeEffect()

```
int32_t OH_ArkUI_ListItemSwipeActionOption_GetEdgeEffect (ArkUI_ListItemSwipeActionOption * option)
```
**Description**
Obtains the sliding effect.

**Since**: 12

**Parameters**

| Name   | Description                       |
| ------ | --------------------------------- |
| option | ListItemSwipeActionItem instance. |

**Returns**

Scroll effect. Default value to be returned: **ARKUI_LIST_ITEM_SWIPE_EDGE_EFFECT_SPRING**


### OH_ArkUI_ListItemSwipeActionOption_SetEdgeEffect()

```
void OH_ArkUI_ListItemSwipeActionOption_SetEdgeEffect (ArkUI_ListItemSwipeActionOption * option, ArkUI_ListItemSwipeEdgeEffect edgeEffect )
```
**Description**
Sets the sliding effect.

**Since**: 12

**Parameters**

| Name       | Description                       |
| ---------- | --------------------------------- |
| option     | ListItemSwipeActionItem instance. |
| edgeEffect | Scroll effect.                    |


### OH_ArkUI_ListItemSwipeActionOption_SetEnd()

```
void OH_ArkUI_ListItemSwipeActionOption_SetEnd (ArkUI_ListItemSwipeActionOption * option, ArkUI_ListItemSwipeActionItem * item )
```
**Description**
Sets the layout content for the right edge (for a vertical layout) or bottom edge (for a horizontal layout) of a **ListItemSwipeActionOption** instance.

**Since**: 12

**Parameters**

| Name    | Description                       |
| ------- | --------------------------------- |
| option  | ListItemSwipeActionItem instance. |
| builder | Layout information                |


### OH_ArkUI_ListItemSwipeActionOption_SetOnOffsetChange()

```
void OH_ArkUI_ListItemSwipeActionOption_SetOnOffsetChange (ArkUI_ListItemSwipeActionOption * option, void(*)(float offset) callback )
```
**Description**
Sets the callback invoked when the scroll offset changes.

**Since**: 12

**Parameters**

| Name     | Description                                  |
| -------- | -------------------------------------------- |
| option   | ListItemSwipeActionItem instance.            |
| callback | Sliding offset of the callback event offset. |


### OH_ArkUI_ListItemSwipeActionOption_SetOnOffsetChangeWithUserData()

```
void OH_ArkUI_ListItemSwipeActionOption_SetOnOffsetChangeWithUserData (ArkUI_ListItemSwipeActionOption * option, void * userData, void(*)(float offset, void *userData) callback )
```
**Description**

Sets the callback invoked when the scroll offset changes.

**Since**: 12

**Parameters**

| Name     | Description                                  |
| -------- | -------------------------------------------- |
| option   | ListItemSwipeActionItem instance.            |
| userData | User-defined data.                           |
| callback | Sliding offset of the callback event offset. |


### OH_ArkUI_ListItemSwipeActionOption_SetStart()

```
void OH_ArkUI_ListItemSwipeActionOption_SetStart (ArkUI_ListItemSwipeActionOption * option, ArkUI_ListItemSwipeActionItem * item )
```
**Description**
Sets the layout content for the left edge (for a vertical layout) or top edge (for a horizontal layout) of a **ListItemSwipeActionOption** instance.

**Since**: 12

**Parameters**

| Name    | Description                       |
| ------- | --------------------------------- |
| option  | ListItemSwipeActionItem instance. |
| builder | Layout information                |



### OH_ArkUI_AlignmentRuleOption_Create()

```
ArkUI_AlignmentRuleOption* OH_ArkUI_AlignmentRuleOption_Create ()
```
**Description**

Creates an alignment rule configuration for this **<RelativeContainer>**.

**Since**: 12

**Returns**

Alignment rule information.


### OH_ArkUI_AlignmentRuleOption_Dispose()

```
void OH_ArkUI_AlignmentRuleOption_Dispose (ArkUI_AlignmentRuleOption * option)
```
**Description**

Destroys the alignment rule information of the child component in the relative container.

**Since**: 12

**Parameters**

| Name   | Description                                                  |
| ------ | ------------------------------------------------------------ |
| option | Alignment rule information of a child component in a relative container. |


### OH_ArkUI_AlignmentRuleOption_GetBiasHorizontal()

```
float OH_ArkUI_AlignmentRuleOption_GetBiasHorizontal (ArkUI_AlignmentRuleOption * option)
```
**Description**

Obtains the bias value in the horizontal direction.

**Since**: 12

**Parameters**

| Name   | Description                                                  |
| ------ | ------------------------------------------------------------ |
| option | Alignment rule information of a child component in a relative container. |

**Returns**

Bias value in the horizontal direction.


### OH_ArkUI_AlignmentRuleOption_GetBiasVertical()

```
float OH_ArkUI_AlignmentRuleOption_GetBiasVertical (ArkUI_AlignmentRuleOption * option)
```
**Description**

Obtains the bias value in the vertical direction.

**Since**: 12

**Parameters**

| Name   | Description                                                  |
| ------ | ------------------------------------------------------------ |
| option | Alignment rule information of a child component in a relative container. |

**Returns**

Bias value in the vertical direction.


### OH_ArkUI_AlignmentRuleOption_GetBottomAlignment()

```
ArkUI_VerticalAlignment OH_ArkUI_AlignmentRuleOption_GetBottomAlignment (ArkUI_AlignmentRuleOption * option)
```
**Description**

Obtains the bottom-aligned parameters.

**Since**: 12

**Parameters**

| Name   | Description                                                  |
| ------ | ------------------------------------------------------------ |
| option | Alignment rule information of a child component in a relative container. |

**Returns**

Alignment mode of bottom-aligned parameters.

### OH_ArkUI_AlignmentRuleOption_GetBottomId()

```
const char* OH_ArkUI_AlignmentRuleOption_GetBottomId (ArkUI_AlignmentRuleOption * option)
```
**Description**

Obtains the bottom-aligned parameters.

**Since**: 12

**Parameters**

| Name   | Description                                                  |
| ------ | ------------------------------------------------------------ |
| option | Alignment rule information of a child component in a relative container. |

**Returns**

ID of the bottom-aligned parameter.


### OH_ArkUI_AlignmentRuleOption_GetCenterAlignmentHorizontal()

```
ArkUI_HorizontalAlignment OH_ArkUI_AlignmentRuleOption_GetCenterAlignmentHorizontal (ArkUI_AlignmentRuleOption * option)
```
**Description**

Obtains the parameters of the horizontal center alignment mode.

**Since**: 12

**Parameters**

| Name   | Description                                                  |
| ------ | ------------------------------------------------------------ |
| option | Alignment rule information of a child component in a relative container. |

**Returns**

Alignment mode of the parameter in horizontal center alignment mode.


### OH_ArkUI_AlignmentRuleOption_GetCenterAlignmentVertical()

```
ArkUI_VerticalAlignment OH_ArkUI_AlignmentRuleOption_GetCenterAlignmentVertical (ArkUI_AlignmentRuleOption * option)
```
**Description**

Obtains the parameter of the vertical center alignment mode.

**Since**: 12

**Parameters**

| Name   | Description                                                  |
| ------ | ------------------------------------------------------------ |
| option | Alignment rule information of a child component in a relative container. |

**Returns**

Alignment mode of the parameter in vertical center alignment mode.


### OH_ArkUI_AlignmentRuleOption_GetCenterIdHorizontal()

```
const char* OH_ArkUI_AlignmentRuleOption_GetCenterIdHorizontal (ArkUI_AlignmentRuleOption * option)
```
**Description**

Obtains the parameters of the horizontal center alignment mode.

**Since**: 12

**Parameters**

| Name   | Description                                                  |
| ------ | ------------------------------------------------------------ |
| option | Alignment rule information of a child component in a relative container. |

**Returns**

ID of the parameter in horizontal center alignment mode.


### OH_ArkUI_AlignmentRuleOption_GetCenterIdVertical()

```
const char* OH_ArkUI_AlignmentRuleOption_GetCenterIdVertical (ArkUI_AlignmentRuleOption * option)
```
**Description**

Obtains the parameter of the vertical center alignment mode.

**Since**: 12

**Parameters**

| Name   | Description                                                  |
| ------ | ------------------------------------------------------------ |
| option | Alignment rule information of a child component in a relative container. |

**Returns**

ID of the parameter in vertical center alignment mode.


### OH_ArkUI_AlignmentRuleOption_GetEndAlignment()

```
ArkUI_HorizontalAlignment OH_ArkUI_AlignmentRuleOption_GetEndAlignment (ArkUI_AlignmentRuleOption * option)
```
**Description**

Obtains the right alignment parameter.

**Since**: 12

**Parameters**

| Name   | Description                                                  |
| ------ | ------------------------------------------------------------ |
| option | Alignment rule information of a child component in a relative container. |

**Returns**

Alignment mode of the right alignment parameter.


### OH_ArkUI_AlignmentRuleOption_GetEndId()

```
const char* OH_ArkUI_AlignmentRuleOption_GetEndId (ArkUI_AlignmentRuleOption * option)
```
**Description**

Obtains the right alignment parameter.

**Since**: 12

**Parameters**

| Name   | Description                                                  |
| ------ | ------------------------------------------------------------ |
| option | Alignment rule information of a child component in a relative container. |

**Returns**

Right-aligned parameter ID.


### OH_ArkUI_AlignmentRuleOption_GetStartAlignment()

```
ArkUI_HorizontalAlignment OH_ArkUI_AlignmentRuleOption_GetStartAlignment (ArkUI_AlignmentRuleOption * option)
```
**Description**

Obtains the alignment mode of the left alignment parameter.

**Since**: 12

**Parameters**

| Name   | Description                                                  |
| ------ | ------------------------------------------------------------ |
| option | Alignment rule information of a child component in a relative container. |

**Returns**

Alignment mode of a parameter.


### OH_ArkUI_AlignmentRuleOption_GetStartId()

```
const char* OH_ArkUI_AlignmentRuleOption_GetStartId (ArkUI_AlignmentRuleOption * option)
```
**Description**

Obtains the ID in the left alignment parameters.

**Since**: 12

**Parameters**

| Name   | Description                                                  |
| ------ | ------------------------------------------------------------ |
| option | Alignment rule information of a child component in a relative container. |

**Returns**

ID of the anchor component.


### OH_ArkUI_AlignmentRuleOption_GetTopAlignment()

```
ArkUI_VerticalAlignment OH_ArkUI_AlignmentRuleOption_GetTopAlignment (ArkUI_AlignmentRuleOption * option)
```
**Description**

Obtains top-aligned parameters.

**Since**: 12

**Parameters**

| Name   | Description                                                  |
| ------ | ------------------------------------------------------------ |
| option | Alignment rule information of a child component in a relative container. |

**Returns**

Alignment mode of the top-aligned parameter.


### OH_ArkUI_AlignmentRuleOption_GetTopId()

```
const char* OH_ArkUI_AlignmentRuleOption_GetTopId (ArkUI_AlignmentRuleOption * option)
```
**Description**

Obtains top-aligned parameters.

**Since**: 12

**Parameters**

| Name   | Description                                                  |
| ------ | ------------------------------------------------------------ |
| option | Alignment rule information of a child component in a relative container. |

**Returns**

ID of the top-aligned parameter.


### OH_ArkUI_AlignmentRuleOption_SetBiasHorizontal()

```
void OH_ArkUI_AlignmentRuleOption_SetBiasHorizontal (ArkUI_AlignmentRuleOption * option, float horizontal )
```
**Description**

Sets the bias value of the component in the horizontal direction under the anchor constraints.

**Since**: 12

**Parameters**

| Name       | Description                                                  |
| ---------- | ------------------------------------------------------------ |
| option     | Alignment rule information of a child component in a relative container. |
| horizontal | Bias value in the horizontal direction.                      |


### OH_ArkUI_AlignmentRuleOption_SetBiasVertical()

```
void OH_ArkUI_AlignmentRuleOption_SetBiasVertical (ArkUI_AlignmentRuleOption * option, float vertical )
```
**Description**

Sets the bias value of the component in the vertical direction under the anchor constraints.

**Since**: 12

**Parameters**

| Name       | Description                                                  |
| ---------- | ------------------------------------------------------------ |
| option     | Alignment rule information of a child component in a relative container. |
| horizontal | Bias value in the vertical direction.                        |


### OH_ArkUI_AlignmentRuleOption_SetBottom()

```
void OH_ArkUI_AlignmentRuleOption_SetBottom (ArkUI_AlignmentRuleOption * option, const char * id, ArkUI_VerticalAlignment alignment )
```
**Description**

Bottom alignment.

**Since**: 12

**Parameters**

| Name   | Description                                                  |
| ------ | ------------------------------------------------------------ |
| option | Alignment rule information of a child component in a relative container. |
| id     | ID of the anchor component.                                  |
| value  | Alignment mode relative to the anchor component              |


### OH_ArkUI_AlignmentRuleOption_SetCenterHorizontal()

```
void OH_ArkUI_AlignmentRuleOption_SetCenterHorizontal (ArkUI_AlignmentRuleOption * option, const char * id, ArkUI_HorizontalAlignment alignment )
```
**Description**

Center alignment in the horizontal direction.

**Since**: 12

**Parameters**

| Name   | Description                                                  |
| ------ | ------------------------------------------------------------ |
| option | Alignment rule information of a child component in a relative container. |
| id     | ID of the anchor component.                                  |
| value  | Alignment mode relative to the anchor component              |


### OH_ArkUI_AlignmentRuleOption_SetCenterVertical()

```
void OH_ArkUI_AlignmentRuleOption_SetCenterVertical (ArkUI_AlignmentRuleOption * option, const char * id, ArkUI_VerticalAlignment alignment )
```
**Description**

Center alignment in the vertical direction.

**Since**: 12

**Parameters**

| Name   | Description                                                  |
| ------ | ------------------------------------------------------------ |
| option | Alignment rule information of a child component in a relative container. |
| id     | ID of the anchor component.                                  |
| value  | Alignment mode relative to the anchor component.             |


### OH_ArkUI_AlignmentRuleOption_SetEnd()

```
void OH_ArkUI_AlignmentRuleOption_SetEnd (ArkUI_AlignmentRuleOption * option, const char * id, ArkUI_HorizontalAlignment alignment )
```
**Description**

Right alignment.

**Since**: 12

**Parameters**

| Name   | Description                                                  |
| ------ | ------------------------------------------------------------ |
| option | Alignment rule information of a child component in a relative container. |
| id     | ID of the anchor component.                                  |
| value  | Alignment mode relative to the anchor component.             |


### OH_ArkUI_AlignmentRuleOption_SetStart()

```
void OH_ArkUI_AlignmentRuleOption_SetStart (ArkUI_AlignmentRuleOption * option, const char * id, ArkUI_HorizontalAlignment alignment )
```
**Description**

Left alignment.

**Since**: 12

**Parameters**

| Name   | Description                                                  |
| ------ | ------------------------------------------------------------ |
| option | Alignment rule information of a child component in a relative container. |
| id     | ID of the anchor component.                                  |
| value  | Alignment mode relative to the anchor component.             |


### OH_ArkUI_AlignmentRuleOption_SetTop()

```
void OH_ArkUI_AlignmentRuleOption_SetTop (ArkUI_AlignmentRuleOption * option, const char * id, ArkUI_VerticalAlignment alignment )
```
**Description**

Top alignment.

**Since**: 12

**Parameters**

| Name   | Description                                                  |
| ------ | ------------------------------------------------------------ |
| option | Alignment rule information of a child component in a relative container. |
| id     | ID of the anchor component.                                  |
| value  | Alignment mode relative to the anchor component              |


### OH_ArkUI_AnimateOption_Create()

```
ArkUI_AnimateOption* OH_ArkUI_AnimateOption_Create ()
```
**Description**

Create animation effect parameters.

**Since**: 12

**Returns**

* @return Returns the pointer to the created animation configuration.


### OH_ArkUI_AnimateOption_Dispose()

```
void OH_ArkUI_AnimateOption_Dispose (ArkUI_AnimateOption * option)
```
**Description**

Destroys an animation configuration.

**Since**: 12


### OH_ArkUI_AnimateOption_GetCurve()

```
ArkUI_AnimationCurve OH_ArkUI_AnimateOption_GetCurve (ArkUI_AnimateOption * option)
```
**Description**

Obtains the animation curve.

**Since**: 12

**Parameters**

| Name   | Description                 |
| ------ | --------------------------- |
| option | Animation effect parameter. |

**Returns**

Animation curve.


### OH_ArkUI_AnimateOption_GetDelay()

```
uint32_t OH_ArkUI_AnimateOption_GetDelay (ArkUI_AnimateOption * option)
```
**Description**

Obtains the animation delay, in milliseconds.

**Since**: 12

**Parameters**

| Name   | Description                 |
| ------ | --------------------------- |
| option | Animation effect parameter. |

**Returns**

Delay of animation playback.


### OH_ArkUI_AnimateOption_GetDuration()

```
uint32_t OH_ArkUI_AnimateOption_GetDuration (ArkUI_AnimateOption * option)
```
**Description**

Obtains the animation duration, in milliseconds.

**Since**: 12

**Parameters**

| Name   | Description                 |
| ------ | --------------------------- |
| option | Animation effect parameter. |

**Returns**

Duration,


### OH_ArkUI_AnimateOption_GetExpectedFrameRateRange()

```
ArkUI_ExpectedFrameRateRange* OH_ArkUI_AnimateOption_GetExpectedFrameRateRange (ArkUI_AnimateOption * option)
```
**Description**

Obtains the expected frame rate range of an animation.

**Since**: 12

**Parameters**

| Name   | Description                 |
| ------ | --------------------------- |
| option | Animation effect parameter. |

**Returns**

Expected frame rate of the animation.


### OH_ArkUI_AnimateOption_GetIterations()

```
uint32_t OH_ArkUI_AnimateOption_GetIterations (ArkUI_AnimateOption * option)
```
**Description**

Obtains the number of times that an animation is played.

**Since**: 12

**Parameters**

| Name   | Description                 |
| ------ | --------------------------- |
| option | Animation effect parameter. |

**Returns**

Number of times that the animation is played.


### OH_ArkUI_AnimateOption_GetPlayMode()

```
ArkUI_AnimationPlayMode OH_ArkUI_AnimateOption_GetPlayMode (ArkUI_AnimateOption * option)
```
**Description**

Obtains the animation playback mode.

**Since**: 12

**Parameters**

| Name   | Description                 |
| ------ | --------------------------- |
| option | Animation effect parameter. |

**Returns**

Animation playback mode.


### OH_ArkUI_AnimateOption_GetTempo()

```
float OH_ArkUI_AnimateOption_GetTempo (ArkUI_AnimateOption * option)
```
**Description**

Obtains the playback speed of an animation.

**Since**: 12

**Parameters**

| Name   | Description                 |
| ------ | --------------------------- |
| option | Animation effect parameter. |

**Returns**

Animation playback speed.


### OH_ArkUI_AnimateOption_SetCurve()

```
void OH_ArkUI_AnimateOption_SetCurve (ArkUI_AnimateOption * option, ArkUI_AnimationCurve value )
```
**Description**

Animation curve.

**Since**: 12

**Parameters**

| Name   | Description                 |
| ------ | --------------------------- |
| option | Animation effect parameter. |
| value  | Animation curve.            |


### OH_ArkUI_AnimateOption_SetDelay()

```
void OH_ArkUI_AnimateOption_SetDelay (ArkUI_AnimateOption * option, uint32_t value )
```
**Description**

Sets the animation delay.

**Since**: 12

**Parameters**

| Name   | Description                  |
| ------ | ---------------------------- |
| option | Animation effect parameter.  |
| value  | Delay of animation playback. |


### OH_ArkUI_AnimateOption_SetDuration()

```
void OH_ArkUI_AnimateOption_SetDuration (ArkUI_AnimateOption * option, uint32_t value )
```
**Description**

Sets the animation duration.

**Since**: 12

**Parameters**

| Name   | Description                 |
| ------ | --------------------------- |
| option | Animation effect parameter. |
| value  | Duration, in milliseconds.  |

### OH_ArkUI_AnimateOption_SetExpectedFrameRateRange()

```
void OH_ArkUI_AnimateOption_SetExpectedFrameRateRange (ArkUI_AnimateOption * option, ArkUI_ExpectedFrameRateRange * value )
```
**Description**

Defines the expected frame rate range of the animation.

**Since**: 12

**Parameters**

| Name   | Description                           |
| ------ | ------------------------------------- |
| option | Animation effect parameter.           |
| value  | Expected frame rate of the animation. |


### OH_ArkUI_AnimateOption_SetIterations()

```
void OH_ArkUI_AnimateOption_SetIterations (ArkUI_AnimateOption * option, uint32_t value )
```
**Description**

Number of times that the frame animation is played.

**Since**: 12

**Parameters**

| Name   | Description                                   |
| ------ | --------------------------------------------- |
| option | Animation effect parameter.                   |
| value  | Number of times that the animation is played. |


### OH_ArkUI_AnimateOption_SetPlayMode()

```
void OH_ArkUI_AnimateOption_SetPlayMode (ArkUI_AnimateOption * option, ArkUI_AnimationPlayMode value )
```
**Description**

Sets the animation playing mode.

**Since**: 12

**Parameters**

| Name   | Description                 |
| ------ | --------------------------- |
| option | Animation effect parameter. |
| value  | Animation playback mode.    |


### OH_ArkUI_AnimateOption_SetTempo()

```
void OH_ArkUI_AnimateOption_SetTempo (ArkUI_AnimateOption * option, float value )
```
**Description**

Sets the playback speed of an animation.

**Since**: 12

**Parameters**

| Name   | Description                 |
| ------ | --------------------------- |
| option | Animation effect parameter. |
| value  | Animation playback speed.   |


### OH_ArkUI_BarrierOption_Create()

```
ArkUI_BarrierOption* OH_ArkUI_BarrierOption_Create (int32_t size)
```
**Description**

Create barrier information in the RelativeContaine container.

**Since**: 12

**Parameters**

| Name | Description         |
| ---- | ------------------- |
| size | Number of barriers. |

**Returns**

Barrier information.


### OH_ArkUI_BarrierOption_Dispose()

```
void OH_ArkUI_BarrierOption_Dispose (ArkUI_BarrierOption * barrierStyle)
```
**Description**

Destroy barrier information.

**Since**: 12

**Parameters**

| Name         | Description          |
| ------------ | -------------------- |
| barrierStyle | Barrier information. |


### OH_ArkUI_BarrierOption_GetDirection()

```
ArkUI_BarrierDirection OH_ArkUI_BarrierOption_GetDirection (ArkUI_BarrierOption * barrierStyle, int32_t index )
```
**Description**

Obtains the direction of the barrier.

**Since**: 12

**Parameters**

| Name         | Description                                |
| ------------ | ------------------------------------------ |
| barrierStyle | Auxiliary line information.                |
| index        | Indicates the index of the auxiliary line. |

**Returns**

The direction of the barrier.


### OH_ArkUI_BarrierOption_GetId()

```
const char* OH_ArkUI_BarrierOption_GetId (ArkUI_BarrierOption * barrierStyle, int32_t index )
```
**Description**

Obtains the barrier ID.

**Since**: 12

**Parameters**

| Name         | Description                                |
| ------------ | ------------------------------------------ |
| barrierStyle | Auxiliary line information.                |
| index        | Indicates the index of the auxiliary line. |

**Returns**

ID of a barrier.


### OH_ArkUI_BarrierOption_GetReferencedId()

```
const char* OH_ArkUI_BarrierOption_GetReferencedId (ArkUI_BarrierOption * barrierStyle, int32_t index, int32_t referencedIndex )
```
**Description**

Obtains the referenced components of a barrier.

**Since**: 12

**Parameters**

| Name            | Description                                |
| --------------- | ------------------------------------------ |
| barrierStyle    | Auxiliary line information.                |
| index           | Indicates the index of the auxiliary line. |
| referencedIndex | ID index of the dependent component.       |

**Returns**

Component on which the barrier depends.


### OH_ArkUI_BarrierOption_GetReferencedIdSize()

```
int32_t OH_ArkUI_BarrierOption_GetReferencedIdSize (ArkUI_BarrierOption * barrierStyle, int32_t index )
```
**Description**

Obtains the number of referenced components of a barrier.

**Since**: 12

**Parameters**

| Name         | Description                                |
| ------------ | ------------------------------------------ |
| barrierStyle | Auxiliary line information.                |
| index        | Indicates the index of the auxiliary line. |

**Returns**

* @return Returns the number of referenced components of the barrier.


### OH_ArkUI_BarrierOption_SetDirection()

```
void OH_ArkUI_BarrierOption_SetDirection (ArkUI_BarrierOption * barrierStyle, ArkUI_BarrierDirection value, int32_t index )
```
**Description**

Sets the direction of the barrier.

**Since**: 12

**Parameters**

| Name         | Description          |
| ------------ | -------------------- |
| barrierStyle | Barrier information. |
| value        | Direction.           |
| index        | Barrier index.       |


### OH_ArkUI_BarrierOption_SetId()

```
void OH_ArkUI_BarrierOption_SetId (ArkUI_BarrierOption * barrierStyle, const char * value, int32_t index )
```
**Description**

Sets the barrier ID.

**Since**: 12

**Parameters**

| Name         | Description                                                  |
| ------------ | ------------------------------------------------------------ |
| barrierStyle | Barrier information.                                         |
| value        | ID of the barrier, which must be unique and cannot be the same as the name of any component in the container. |
| index        | Barrier index.                                               |


### OH_ArkUI_BarrierOption_SetReferencedId()

```
void OH_ArkUI_BarrierOption_SetReferencedId (ArkUI_BarrierOption * barrierStyle, const char * value, int32_t index )
```
**Description**

Sets the referenced components of a barrier.

**Since**: 12

**Parameters**

| Name         | Description                    |
| ------------ | ------------------------------ |
| barrierStyle | Barrier information.           |
| value        | ID of the dependent component. |
| index        | Barrier index.                 |


### OH_ArkUI_DrawableDescriptor_CreateFromAnimatedPixelMap()

```
ArkUI_DrawableDescriptor* OH_ArkUI_DrawableDescriptor_CreateFromAnimatedPixelMap (OH_PixelmapNativeHandle * array, int32_t size )
```
**Description**

Creates a **DrawbleDescriptor** object with an array of **PixelMap** objects.

**Since**: 12

**Parameters**

| Name  | Description                                 |
| ----- | ------------------------------------------- |
| array | Pointer to the PixelMap image array object. |
| size  | Size of the PixelMap image array.           |

**Returns**

The DrawableDescriptor object pointer is returned.


### OH_ArkUI_DrawableDescriptor_CreateFromPixelMap()

```
ArkUI_DrawableDescriptor* OH_ArkUI_DrawableDescriptor_CreateFromPixelMap (OH_PixelmapNativeHandle pixelMap)
```
**Description**

Creates a **DrawbleDescriptor** object with a **PixelMap** object.

**Since**: 12

**Parameters**

| Name     | Description                     |
| -------- | ------------------------------- |
| pixelMap | Pointer to the PixelMap object. |

**Returns**

The DrawableDescriptor object pointer is returned.


### OH_ArkUI_DrawableDescriptor_Dispose()

```
void OH_ArkUI_DrawableDescriptor_Dispose (ArkUI_DrawableDescriptor * drawableDescriptor)
```
**Description**

Disposes of the pointer to a **DrawbleDescriptor** object.

**Since**: 12

**Parameters**

| Name               | Description                              |
| ------------------ | ---------------------------------------- |
| drawableDescriptor | Pointer to the DrawbleDescriptor object. |


### OH_ArkUI_DrawableDescriptor_GetAnimatedPixelMapArray()

```
OH_PixelmapNativeHandle* OH_ArkUI_DrawableDescriptor_GetAnimatedPixelMapArray (ArkUI_DrawableDescriptor * drawableDescriptor)
```
**Description**

Obtains an array of **PixelMap** objects for playing an animation.

**Since**: 12

**Parameters**

| Name               | Description                              |
| ------------------ | ---------------------------------------- |
| drawableDescriptor | Pointer to the DrawbleDescriptor object. |

**Returns**

Pointer to the PixelMap image array.


### OH_ArkUI_DrawableDescriptor_GetAnimatedPixelMapArraySize()

```
int32_t OH_ArkUI_DrawableDescriptor_GetAnimatedPixelMapArraySize (ArkUI_DrawableDescriptor * drawableDescriptor)
```
**Description**

Obtains an array of **PixelMap** objects for playing an animation.

**Since**: 12

**Parameters**

| Name               | Description                              |
| ------------------ | ---------------------------------------- |
| drawableDescriptor | Pointer to the DrawbleDescriptor object. |

**Returns**

Size of the PixelMap image array.


### OH_ArkUI_DrawableDescriptor_GetAnimationDuration()

```
int32_t OH_ArkUI_DrawableDescriptor_GetAnimationDuration (ArkUI_DrawableDescriptor * drawableDescriptor)
```
**Description**

Obtains the total playback duration of a PixelMap image array.

**Since**: 12

**Parameters**

| Name               | Description                              |
| ------------------ | ---------------------------------------- |
| drawableDescriptor | Pointer to the DrawbleDescriptor object. |

**Returns**

Total playback duration, in milliseconds.


### OH_ArkUI_DrawableDescriptor_GetAnimationIteration()

```
int32_t OH_ArkUI_DrawableDescriptor_GetAnimationIteration (ArkUI_DrawableDescriptor * drawableDescriptor)
```
**Description**

Obtains the number of times that the PixelMap image array is played.

**Since**: 12

**Parameters**

| Name               | Description                              |
| ------------------ | ---------------------------------------- |
| drawableDescriptor | Pointer to the DrawbleDescriptor object. |

**Returns**

Playbacks


### OH_ArkUI_DrawableDescriptor_GetStaticPixelMap()

```
OH_PixelmapNativeHandle OH_ArkUI_DrawableDescriptor_GetStaticPixelMap (ArkUI_DrawableDescriptor * drawableDescriptor)
```
**Description**

Obtains the pointer to a **PixelMap** object.

**Since**: 12

**Parameters**

| Name               | Description                              |
| ------------------ | ---------------------------------------- |
| drawableDescriptor | Pointer to the DrawbleDescriptor object. |

**Returns**

Pointer to the PixelMap object.


### OH_ArkUI_DrawableDescriptor_SetAnimationDuration()

```
void OH_ArkUI_DrawableDescriptor_SetAnimationDuration (ArkUI_DrawableDescriptor * drawableDescriptor, int32_t duration )
```
**Description**

Sets the total playback duration of the PixelMap image array.

**Since**: 12

**Parameters**

| Name               | Description                               |
| ------------------ | ----------------------------------------- |
| drawableDescriptor | Pointer to the DrawbleDescriptor object.  |
| duration           | Total playback duration, in milliseconds. |


### OH_ArkUI_DrawableDescriptor_SetAnimationIteration()

```
void OH_ArkUI_DrawableDescriptor_SetAnimationIteration (ArkUI_DrawableDescriptor * drawableDescriptor, int32_t iteration )
```
**Description**

Sets the number of times that the PixelMap image array is played.

**Since**: 12

**Parameters**

| Name               | Description                              |
| ------------------ | ---------------------------------------- |
| drawableDescriptor | Pointer to the DrawbleDescriptor object. |
| iterations         | Playbacks                                |


### OH_ArkUI_DrawContext_GetCanvas()

```
void* OH_ArkUI_DrawContext_GetCanvas (ArkUI_DrawContext * context)
```
**Description**

Obtains the drawing canvas pointer, which can be converted into the OH_Drawing_Canvas pointer of the graphics library for drawing.

**Since**: 12

**Parameters**

| Name    | Description   |
| ------- | ------------- |
| context | Draw context. |

**Returns**

Pointer to the canvas for drawing.


### OH_ArkUI_DrawContext_GetSize()

```
ArkUI_IntSize OH_ArkUI_DrawContext_GetSize (ArkUI_DrawContext * context)
```
**Description**

Obtains the size of a drawing area.

**Since**: 12

**Parameters**

| Name    | Description   |
| ------- | ------------- |
| context | Draw context. |

**Returns**

Size of the area that can be drawn.


### OH_ArkUI_GestureEvent_GetActionType()

```
ArkUI_GestureEventActionType OH_ArkUI_GestureEvent_GetActionType (const ArkUI_GestureEvent * event)
```
**Description**

Returns the gesture event type.

**Since**: 12

**Parameters**

| Name  | Description        |
| ----- | ------------------ |
| event | The gesture event. |

**Returns**

Enumerates gesture types.


### OH_ArkUI_GestureEvent_GetRawInputEvent()

```
const ArkUI_UIInputEvent* OH_ArkUI_GestureEvent_GetRawInputEvent (const ArkUI_GestureEvent * event)
```
**Description**

Returns gesture input.

**Since**: 12

**Parameters**

| Name  | Description        |
| ----- | ------------------ |
| event | The gesture event. |

**Returns**

* @return Returns the pointer to the input event of the gesture event.


### OH_ArkUI_GestureInterruptInfo_GetGestureEvent()

```
ArkUI_GestureEvent* OH_ArkUI_GestureInterruptInfo_GetGestureEvent (const ArkUI_GestureInterruptInfo * event)
```
**Description**

Obtains the pointer to the interrupted gesture event.

**Since**: 12

**Parameters**

| Name  | Description               |
| ----- | ------------------------- |
| event | Interrupt callback event. |

**Returns**

* @return Returns the pointer to the interrupted gesture event.


### OH_ArkUI_GestureInterruptInfo_GetRecognizer()

```
ArkUI_GestureRecognizer* OH_ArkUI_GestureInterruptInfo_GetRecognizer (const ArkUI_GestureInterruptInfo * event)
```
**Description**

Obtains the pointer to interrupted gesture recognizer.

**Since**: 12

**Parameters**

| Name  | Description               |
| ----- | ------------------------- |
| event | Interrupt callback event. |

**Returns**

Pointer to the interrupted gesture.


### OH_ArkUI_GestureInterruptInfo_GetSystemFlag()

```
bool OH_ArkUI_GestureInterruptInfo_GetSystemFlag (const ArkUI_GestureInterruptInfo * event)
```
**Description**

Checks whether a gesture is a built-in gesture of the component.

**Since**: 12

**Parameters**

| Name  | Description                       |
| ----- | --------------------------------- |
| event | Gesture interrupt callback event. |

**Returns**

true: built-in gestures; false: non-built-in gestures.


### OH_ArkUI_GestureInterruptInfo_GetSystemRecognizerType()

```
int32_t OH_ArkUI_GestureInterruptInfo_GetSystemRecognizerType (const ArkUI_GestureInterruptInfo * event)
```
**Description**

Obtains the type of the system gesture to trigger.

**Since**: 12

**Parameters**

| Name  | Description               |
| ----- | ------------------------- |
| event | Interrupt callback event. |

**Returns**

* @return Returns the type of the system gesture to trigger. If the gesture to trigger is not a system gesture, **-1** is returned.


### OH_ArkUI_GetContextFromNapiValue()

```
int32_t OH_ArkUI_GetContextFromNapiValue (napi_env env, napi_value value, ArkUI_ContextHandle * context )
```
**Description**

Obtains a **UIContext** object on the ArkTS side and maps it to an **ArkUI_ContextHandle** object on the native side.

**Since**: 12

**Parameters**

| Name    | Description                               |
| ------- | ----------------------------------------- |
| env     | Pointer to the NAPI environment.          |
| value   | Context object created on the ArkTS side. |
| context | ArkUI_ContextHandle pointer.              |

**Returns**

0 - The operation is successful. * Returns 401 if a parameter exception occurs.


### OH_ArkUI_GetDrawableDescriptorFromNapiValue()

```
int32_t OH_ArkUI_GetDrawableDescriptorFromNapiValue (napi_env env, napi_value value, ArkUI_DrawableDescriptor ** drawableDescriptor )
```
**Description**

Maps a **DrawableDescriptor** object on the ArkTS side to an **ArkUI_DrawableDescriptor** object on the native side.

**Since**: 12

**Parameters**

| Name               | Description                                               |
| ------------------ | --------------------------------------------------------- |
| env                | Pointer to the NAPI environment.                          |
| value              | DrawableDescriptor object created on the ArkTS side.      |
| drawableDescriptor | Object that receives the ArkUI_DrawableDescriptor pointer |

**Returns**

0 - The operation is successful. * Returns 401 if a parameter exception occurs.


### OH_ArkUI_GetDrawableDescriptorFromResourceNapiValue()

```
int32_t OH_ArkUI_GetDrawableDescriptorFromResourceNapiValue (napi_env env, napi_value value, ArkUI_DrawableDescriptor ** drawableDescriptor )
```
**Description**

Maps an $r resource object on the ArkTS side to an **ArkUI_DrawableDescriptor** object on the native side.

**Since**: 12

**Parameters**

| Name               | Description                                               |
| ------------------ | --------------------------------------------------------- |
| env                | Pointer to the NAPI environment.                          |
| value              | $r resource object created on ArkTS.                      |
| drawableDescriptor | Object that receives the ArkUI_DrawableDescriptor pointer |

**Returns**

0 - The operation is successful. * Returns 401 if a parameter exception occurs.

### OH_ArkUI_GetNodeHandleFromNapiValue()

```
int32_t OH_ArkUI_GetNodeHandleFromNapiValue (napi_env env, napi_value frameNode, ArkUI_NodeHandle * handle )
```
**Description**

Obtains a **FrameNode** object on the ArkTS side and maps it to an **ArkUI_NodeHandle** object on the native side.

**Since**: 12

**Parameters**

| Name      | Description                                 |
| --------- | ------------------------------------------- |
| env       | Pointer to the NAPI environment.            |
| frameNode | FrameNode object created on the ArkTS side. |
| handle    | ArkUI_NodeHandle pointer.                   |

**Returns**

0 - The operation is successful. * Returns 401 if a parameter exception occurs.


### OH_ArkUI_GuidelineOption_Create()

```
ArkUI_GuidelineOption* OH_ArkUI_GuidelineOption_Create (int32_t size)
```
**Description**

Creates a guideline configuration for this **<RelativeContainer>**.

**Since**: 12

**Parameters**

| Name | Description                              |
| ---- | ---------------------------------------- |
| size | Indicates the number of auxiliary lines. |

**Returns**

Auxiliary line information.


### OH_ArkUI_GuidelineOption_Dispose()

```
void OH_ArkUI_GuidelineOption_Dispose (ArkUI_GuidelineOption * guideline)
```
**Description**

Destroys auxiliary line information.

**Since**: 12

**Parameters**

| Name      | Description                 |
| --------- | --------------------------- |
| guideline | Auxiliary line information. |


### OH_ArkUI_GuidelineOption_GetDirection()

```
ArkUI_Axis OH_ArkUI_GuidelineOption_GetDirection (ArkUI_GuidelineOption * guideline, int32_t index )
```
**Description**

Obtains the direction of the auxiliary line.

**Since**: 12

**Parameters**

| Name      | Description                                |
| --------- | ------------------------------------------ |
| guideline | Auxiliary line information.                |
| index     | Indicates the index of the auxiliary line. |

**Returns**

Direction. 


### OH_ArkUI_GuidelineOption_GetId()

```
const char* OH_ArkUI_GuidelineOption_GetId (ArkUI_GuidelineOption * guideline, int32_t index )
```
**Description**

Obtains the ID of an auxiliary line.

**Since**: 12

**Parameters**

| Name      | Description                                |
| --------- | ------------------------------------------ |
| guideline | Auxiliary line information.                |
| index     | Indicates the index of the auxiliary line. |

**Returns**

Id.


### OH_ArkUI_GuidelineOption_GetPositionEnd()

```
float OH_ArkUI_GuidelineOption_GetPositionEnd (ArkUI_GuidelineOption * guideline, int32_t index )
```
**Description**

Obtains the distance between a guideline and the right or bottom of the container.

**Since**: 12

**Parameters**

| Name      | Description                                |
| --------- | ------------------------------------------ |
| guideline | Auxiliary line information.                |
| index     | Indicates the index of the auxiliary line. |

**Returns**

Distance between the guideline and the right or bottom of the container.


### OH_ArkUI_GuidelineOption_GetPositionStart()

```
float OH_ArkUI_GuidelineOption_GetPositionStart (ArkUI_GuidelineOption * guideline, int32_t index )
```
**Description**

Obtains the distance between a guideline and the left or top of the container.

**Since**: 12

**Parameters**

| Name      | Description                                |
| --------- | ------------------------------------------ |
| guideline | Auxiliary line information.                |
| index     | Indicates the index of the auxiliary line. |

**Returns**

Distance between the guideline and the left or top of the container.


### OH_ArkUI_GuidelineOption_SetDirection()

```
void OH_ArkUI_GuidelineOption_SetDirection (ArkUI_GuidelineOption * guideline, ArkUI_Axis value, int32_t index )
```
**Description**

Sets the direction of the auxiliary line.

**Since**: 12

**Parameters**

| Name      | Description                                |
| --------- | ------------------------------------------ |
| guideline | Auxiliary line information.                |
| value     | Direction.                                 |
| index     | Indicates the index of the auxiliary line. |


### OH_ArkUI_GuidelineOption_SetId()

```
void OH_ArkUI_GuidelineOption_SetId (ArkUI_GuidelineOption * guideline, const char * value, int32_t index )
```
**Description**

Sets the ID of the auxiliary line.

**Since**: 12

**Parameters**

| Name      | Description                                                  |
| --------- | ------------------------------------------------------------ |
| guideline | Auxiliary line information.                                  |
| value     | ID of the barrier, which must be unique and cannot be the same as the name of any component in the container. |
| index     | Indicates the index of the auxiliary line.                   |


### OH_ArkUI_GuidelineOption_SetPositionEnd()

```
void OH_ArkUI_GuidelineOption_SetPositionEnd (ArkUI_GuidelineOption * guideline, float value, int32_t index )
```
**Description**

Sets the distance between a guideline and the right or bottom of the container.

**Since**: 12

**Parameters**

| Name      | Description                                                  |
| --------- | ------------------------------------------------------------ |
| guideline | Auxiliary line information.                                  |
| value     | Distance between the guideline and the right or bottom of the container. |
| index     | Indicates the index of the auxiliary line.                   |


### OH_ArkUI_GuidelineOption_SetPositionStart()

```
void OH_ArkUI_GuidelineOption_SetPositionStart (ArkUI_GuidelineOption * guideline, float value, int32_t index )
```
**Description**

Sets the distance between a guideline and the left or top of the container.

**Since**: 12

**Parameters**

| Name      | Description                                                  |
| --------- | ------------------------------------------------------------ |
| guideline | Auxiliary line information.                                  |
| value     | Distance between the guideline and the left or top of the container. |
| index     | Indicates the index of the auxiliary line.                   |


### OH_ArkUI_LayoutConstraint_Copy()

```
ArkUI_LayoutConstraint* OH_ArkUI_LayoutConstraint_Copy (const ArkUI_LayoutConstraint * Constraint)
```
**Description**

Constraint size deep copy.

**Since**: 12

**Parameters**

| Name       | Description      |
| ---------- | ---------------- |
| Constraint | Size constraint. |

**Returns**

Pointer to the new constraint size.


### OH_ArkUI_LayoutConstraint_Create()

```
ArkUI_LayoutConstraint* OH_ArkUI_LayoutConstraint_Create ()
```
**Description**

Create a constraint size.

**Since**: 12


### OH_ArkUI_LayoutConstraint_Dispose()

```
void* OH_ArkUI_LayoutConstraint_Dispose (ArkUI_LayoutConstraint * Constraint)
```
**Description**

Pointer to the size of the destruction constraint.

**Since**: 12

**Parameters**

| Name       | Description      |
| ---------- | ---------------- |
| Constraint | Size constraint. |


### OH_ArkUI_LayoutConstraint_GetMaxHeight()

```
int32_t OH_ArkUI_LayoutConstraint_GetMaxHeight (const ArkUI_LayoutConstraint * Constraint)
```
**Description**

Obtains the maximum height for a size constraint, in px.

**Since**: 12

**Parameters**

| Name       | Description      |
| ---------- | ---------------- |
| Constraint | Size constraint. |

**Returns**

Maximum height.


### OH_ArkUI_LayoutConstraint_GetMaxWidth()

```
int32_t OH_ArkUI_LayoutConstraint_GetMaxWidth (const ArkUI_LayoutConstraint * Constraint)
```
**Description**

Obtains the maximum width for a size contraint, in px.

**Since**: 12

**Parameters**

| Name       | Description      |
| ---------- | ---------------- |
| Constraint | Size constraint. |

**Returns**

Maximum width.


### OH_ArkUI_LayoutConstraint_GetMinHeight()

```
int32_t OH_ArkUI_LayoutConstraint_GetMinHeight (const ArkUI_LayoutConstraint * Constraint)
```
**Description**

Obtains the minimum height for a size constraint, in px.

**Since**: 12

**Parameters**

| Name       | Description      |
| ---------- | ---------------- |
| Constraint | Size constraint. |

**Returns**

Minimum Height


### OH_ArkUI_LayoutConstraint_GetMinWidth()

```
int32_t OH_ArkUI_LayoutConstraint_GetMinWidth (const ArkUI_LayoutConstraint * Constraint)
```
**Description**

Obtains the minimum width for a size contraint, in px.

**Since**: 12

**Parameters**

| Name       | Description      |
| ---------- | ---------------- |
| Constraint | Size constraint. |

**Returns**

Minimum Width


### OH_ArkUI_LayoutConstraint_GetPercentReferenceHeight()

```
int32_t OH_ArkUI_LayoutConstraint_GetPercentReferenceHeight (const ArkUI_LayoutConstraint * Constraint)
```
**Description**

Obtains the height percentage reference for a size constraint, in px.

**Since**: 12

**Parameters**

| Name       | Description      |
| ---------- | ---------------- |
| Constraint | Size constraint. |

**Returns**

Height percentage benchmark.


### OH_ArkUI_LayoutConstraint_GetPercentReferenceWidth()

```
int32_t OH_ArkUI_LayoutConstraint_GetPercentReferenceWidth (const ArkUI_LayoutConstraint * Constraint)
```
**Description**

Obtains the width percentage reference for a size constraint, in px.

**Since**: 12

**Parameters**

| Name       | Description      |
| ---------- | ---------------- |
| Constraint | Size constraint. |

**Returns**

Width percentage reference.


### OH_ArkUI_LayoutConstraint_SetMaxHeight()

```
void OH_ArkUI_LayoutConstraint_SetMaxHeight (ArkUI_LayoutConstraint * Constraint, int32_t value )
```
**Description**

Sets the maximum height.

**Since**: 12

**Parameters**

| Name       | Description                |
| ---------- | -------------------------- |
| Constraint | Size constraint.           |
| value      | Maximum height, in pixels. |


### OH_ArkUI_LayoutConstraint_SetMaxWidth()

```
void OH_ArkUI_LayoutConstraint_SetMaxWidth (ArkUI_LayoutConstraint * Constraint, int32_t value )
```
**Description**

Sets the maximum width.

**Since**: 12

**Parameters**

| Name       | Description               |
| ---------- | ------------------------- |
| Constraint | Size constraint.          |
| value      | Maximum width, in pixels. |


### OH_ArkUI_LayoutConstraint_SetMinHeight()

```
void OH_ArkUI_LayoutConstraint_SetMinHeight (ArkUI_LayoutConstraint * Constraint, int32_t value )
```
**Description**

Sets the minimum height.

**Since**: 12

**Parameters**

| Name       | Description                |
| ---------- | -------------------------- |
| Constraint | Size constraint.           |
| value      | Minimum height, in pixels. |


### OH_ArkUI_LayoutConstraint_SetMinWidth()

```
void OH_ArkUI_LayoutConstraint_SetMinWidth (ArkUI_LayoutConstraint * Constraint, int32_t value )
```
**Description**

Sets the minimum width.

**Since**: 12

**Parameters**

| Name       | Description               |
| ---------- | ------------------------- |
| Constraint | Size constraint.          |
| value      | Minimum width, in pixels. |


### OH_ArkUI_LayoutConstraint_SetPercentReferenceHeight()

```
void OH_ArkUI_LayoutConstraint_SetPercentReferenceHeight (ArkUI_LayoutConstraint * Constraint, int32_t value )
```
**Description**

Sets the height percentage reference.

**Since**: 12

**Parameters**

| Name       | Description                    |
| ---------- | ------------------------------ |
| Constraint | Size constraint.               |
| value      | Height percentage base, in px. |


### OH_ArkUI_LayoutConstraint_SetPercentReferenceWidth()

```
void OH_ArkUI_LayoutConstraint_SetPercentReferenceWidth (ArkUI_LayoutConstraint * Constraint, int32_t value )
```
**Description**

Sets the width percentage reference.

**Since**: 12

**Parameters**

| Name       | Description                        |
| ---------- | ---------------------------------- |
| Constraint | Size constraint.                   |
| value      | Width percentage benchmark, in px. |


### OH_ArkUI_LongPress_GetRepeatCount()

```
int32_t OH_ArkUI_LongPress_GetRepeatCount (const ArkUI_GestureEvent * event)
```
**Description**

Obtains the number of times that a long press gesture is triggered periodically.

**Since**: 12

**Parameters**

| Name  | Description        |
| ----- | ------------------ |
| event | The gesture event. |

**Returns**

* @return Returns the number of times that the long press gesture is triggered periodically.


### OH_ArkUI_NodeAdapter_Create()

```
ArkUI_NodeAdapterHandle OH_ArkUI_NodeAdapter_Create ()
```
**Description**

Creates a component adapter.

**Since**: 12


### OH_ArkUI_NodeAdapter_Dispose()

```
void OH_ArkUI_NodeAdapter_Dispose (ArkUI_NodeAdapterHandle handle)
```
**Description**

Destroys a component adapter.

**Since**: 12

**Parameters**

| Name   | Description               |
| ------ | ------------------------- |
| handle | Component adapter object. |


### OH_ArkUI_NodeAdapter_GetAllItems()

```
int32_t OH_ArkUI_NodeAdapter_GetAllItems (ArkUI_NodeAdapterHandle handle, ArkUI_NodeHandle ** items, uint32_t * size )
```
**Description**

Obtains all elements stored in the specified adapter.

When the API is called, the array object pointer of the element is returned. The memory data pointed by the pointer needs to be manually released by developers.

**Since**: 12

**Parameters**

| Name   | Description                    |
| ------ | ------------------------------ |
| handle | Component adapter object.      |
| items  | Array of nodes in the adapter. |
| size   | Number of elements.            |

**Returns**

0 - The operation is successful. * Returns 401 if a parameter exception occurs.


### OH_ArkUI_NodeAdapter_GetTotalNodeCount()

```
uint32_t OH_ArkUI_NodeAdapter_GetTotalNodeCount (ArkUI_NodeAdapterHandle handle)
```
**Description**

Obtains the total number of elements in the Adapter.

**Since**: 12

**Parameters**

| Name   | Description               |
| ------ | ------------------------- |
| handle | Component adapter object. |

**Returns**

Total number of elements in the Adapter.


### OH_ArkUI_NodeAdapter_InsertItem()

```
int32_t OH_ArkUI_NodeAdapter_InsertItem (ArkUI_NodeAdapterHandle handle, uint32_t startPosition, uint32_t itemCount )
```
**Description**

Instructs the specified adapter to insert certain elements.

**Since**: 12

**Parameters**

| Name          | Description                              |
| ------------- | ---------------------------------------- |
| handle        | Component adapter object.                |
| startPosition | Start position for inserting an element. |
| itemCount     | Number of inserted elements.             |

**Returns**

0 - The operation is successful. * Returns 401 if a parameter exception occurs.


### OH_ArkUI_NodeAdapter_MoveItem()

```
int32_t OH_ArkUI_NodeAdapter_MoveItem (ArkUI_NodeAdapterHandle handle, uint32_t from, uint32_t to )
```
**Description**

Instructs the specified adapter to move certain elements.

**Since**: 12

**Parameters**

| Name   | Description                          |
| ------ | ------------------------------------ |
| handle | Component adapter object.            |
| from   | Start position of the element shift. |
| to     | End position of the element shift.   |

**Returns**

0 - The operation is successful. * Returns 401 if a parameter exception occurs.


### OH_ArkUI_NodeAdapter_RegisterEventReceiver()

```
int32_t OH_ArkUI_NodeAdapter_RegisterEventReceiver (ArkUI_NodeAdapterHandle handle, void * userData, void(*)(ArkUI_NodeAdapterEvent *event) receiver )
```
**Description**

Registers callback events related to the Adapter.

**Since**: 12

**Parameters**

| Name     | Description               |
| -------- | ------------------------- |
| handle   | Component adapter object. |
| userData | Custom data.              |
| receiver | Event receiving callback. |

**Returns**

0 - The operation is successful. * Returns 401 if a parameter exception occurs.


### OH_ArkUI_NodeAdapter_ReloadAllItems()

```
int32_t OH_ArkUI_NodeAdapter_ReloadAllItems (ArkUI_NodeAdapterHandle handle)
```
**Description**

Instructs the specified adapter to reload all elements.

**Since**: 12

**Parameters**

| Name   | Description               |
| ------ | ------------------------- |
| handle | Component adapter object. |

**Returns**

0 - The operation is successful. * Returns 401 if a parameter exception occurs.


### OH_ArkUI_NodeAdapter_ReloadItem()

```
int32_t OH_ArkUI_NodeAdapter_ReloadItem (ArkUI_NodeAdapterHandle handle, uint32_t startPosition, uint32_t itemCount )
```
**Description**

Instructs the specified adapter to reload certain elements.

**Since**: 12

**Parameters**

| Name          | Description                          |
| ------------- | ------------------------------------ |
| handle        | Component adapter object.            |
| startPosition | Start position of an element change. |
| itemCount     | Number of changed elements.          |

**Returns**

0 - The operation is successful. * Returns 401 if a parameter exception occurs.


### OH_ArkUI_NodeAdapter_RemoveItem()

```
int32_t OH_ArkUI_NodeAdapter_RemoveItem (ArkUI_NodeAdapterHandle handle, uint32_t startPosition, uint32_t itemCount )
```
**Description**

Instructs the specified adapter to remove certain elements.

**Since**: 12

**Parameters**

| Name          | Description                             |
| ------------- | --------------------------------------- |
| handle        | Component adapter object.               |
| startPosition | Start position for deleting an element. |
| itemCount     | Number of deleted elements.             |

**Returns**

0 - The operation is successful. * Returns 401 if a parameter exception occurs.


### OH_ArkUI_NodeAdapter_SetTotalNodeCount()

```
int32_t OH_ArkUI_NodeAdapter_SetTotalNodeCount (ArkUI_NodeAdapterHandle handle, uint32_t size )
```
**Description**

Sets the total number of elements in the specified adapter.

**Since**: 12

**Parameters**

| Name   | Description               |
| ------ | ------------------------- |
| handle | Component adapter object. |
| size   | Number of elements.       |

**Returns**

0 - The operation is successful. * Returns 401 if a parameter exception occurs.


### OH_ArkUI_NodeAdapter_UnregisterEventReceiver()

```
void OH_ArkUI_NodeAdapter_UnregisterEventReceiver (ArkUI_NodeAdapterHandle handle)
```
**Description**

Deregisters Adapter-related callback events.

**Since**: 12

**Parameters**

| Name   | Description               |
| ------ | ------------------------- |
| handle | Component adapter object. |


### OH_ArkUI_NodeAdapterEvent_GetHostNode()

```
ArkUI_NodeHandle OH_ArkUI_NodeAdapterEvent_GetHostNode (ArkUI_NodeAdapterEvent * event)
```
**Description**

Obtains the scrolling class container node that uses the adapter.

**Since**: 12

**Parameters**

| Name  | Description           |
| ----- | --------------------- |
| event | Adapter event object. |

**Returns**

0 - The operation is successful. * Returns 401 if a parameter exception occurs.


### OH_ArkUI_NodeAdapterEvent_GetItemIndex()

```
uint32_t OH_ArkUI_NodeAdapterEvent_GetItemIndex (ArkUI_NodeAdapterEvent * event)
```
**Description**

Sequence number of the element to be operated when the adapter event is obtained.

**Since**: 12

**Parameters**

| Name  | Description           |
| ----- | --------------------- |
| event | Adapter event object. |

**Returns**

Sequence number of an element.


### OH_ArkUI_NodeAdapterEvent_GetRemovedNode()

```
ArkUI_NodeHandle OH_ArkUI_NodeAdapterEvent_GetRemovedNode (ArkUI_NodeAdapterEvent * event)
```
**Description**

Obtains the element to be destroyed in the event to be destroyed.

**Since**: 12

**Parameters**

| Name  | Description           |
| ----- | --------------------- |
| event | Adapter event object. |

**Returns**

Element to be destroyed.


### OH_ArkUI_NodeAdapterEvent_GetType()

```
ArkUI_NodeAdapterEventType OH_ArkUI_NodeAdapterEvent_GetType (ArkUI_NodeAdapterEvent * event)
```
**Description**

Obtains the event type.

**Since**: 12

**Parameters**

| Name  | Description           |
| ----- | --------------------- |
| event | Adapter event object. |

**Returns**

Event type, which can be a click or impression event.


### OH_ArkUI_NodeAdapterEvent_GetUserData()

```
void* OH_ArkUI_NodeAdapterEvent_GetUserData (ArkUI_NodeAdapterEvent * event)
```
**Description**

Obtains the custom data passed in during registration of the specified event.

**Since**: 12

**Parameters**

| Name  | Description           |
| ----- | --------------------- |
| event | Adapter event object. |


### OH_ArkUI_NodeAdapterEvent_SetItem()

```
int32_t OH_ArkUI_NodeAdapterEvent_SetItem (ArkUI_NodeAdapterEvent * event, ArkUI_NodeHandle node )
```
**Description**

Sets the component to be added to the specified adapter.

**Since**: 12

**Parameters**

| Name  | Description            |
| ----- | ---------------------- |
| event | Adapter event object.  |
| node  | Component to be added. |

**Returns**

0 - The operation is successful. * Returns 401 if a parameter exception occurs.


### OH_ArkUI_NodeAdapterEvent_SetNodeId()

```
int32_t OH_ArkUI_NodeAdapterEvent_SetNodeId (ArkUI_NodeAdapterEvent * event, int32_t id )
```
**Description**

Sets the generated component ID.

**Since**: 12

**Parameters**

| Name  | Description                     |
| ----- | ------------------------------- |
| event | Adapter event object.           |
| id    | Sets the returned component ID. |

**Returns**

0 - The operation is successful. * Returns 401 if a parameter exception occurs.


### OH_ArkUI_NodeCustomEvent_GetDrawContextInDraw()

```
ArkUI_DrawContext* OH_ArkUI_NodeCustomEvent_GetDrawContextInDraw (ArkUI_NodeCustomEvent * event)
```
**Description**

Obtain the drawing context through the customized widget event.

**Since**: 12

**Parameters**

| Name  | Description              |
| ----- | ------------------------ |
| event | Customize widget events. |

**Returns**

Draw context.


### OH_ArkUI_NodeCustomEvent_GetEventTargetId()

```
int32_t OH_ArkUI_NodeCustomEvent_GetEventTargetId (ArkUI_NodeCustomEvent * event)
```
**Description**

Obtain the customized event ID through the custom component event.

**Since**: 12

**Parameters**

| Name  | Description              |
| ----- | ------------------------ |
| event | Customize widget events. |

**Returns**

Custom event ID


### OH_ArkUI_NodeCustomEvent_GetEventType()

```
ArkUI_NodeCustomEventType OH_ArkUI_NodeCustomEvent_GetEventType (ArkUI_NodeCustomEvent * event)
```
**Description**

Obtain the event type by customizing a widget event.

**Since**: 12

**Parameters**

| Name  | Description              |
| ----- | ------------------------ |
| event | Customize widget events. |

**Returns**

Customized event type of the widget.


### OH_ArkUI_NodeCustomEvent_GetLayoutConstraintInMeasure()

```
ArkUI_LayoutConstraint* OH_ArkUI_NodeCustomEvent_GetLayoutConstraintInMeasure (ArkUI_NodeCustomEvent * event)
```
**Description**

You can customize widget events to obtain the constraint size during calculation.

**Since**: 12

**Parameters**

| Name  | Description              |
| ----- | ------------------------ |
| event | Customize widget events. |

**Returns**

Pointer to the constraint size.


### OH_ArkUI_NodeCustomEvent_GetNodeHandle()

```
ArkUI_NodeHandle OH_ArkUI_NodeCustomEvent_GetNodeHandle (ArkUI_NodeCustomEvent * event)
```
**Description**

This interface is used to obtain a widget object by customizing a widget event.

**Since**: 12

**Parameters**

| Name  | Description              |
| ----- | ------------------------ |
| event | Customize widget events. |

**Returns**

Component object.


### OH_ArkUI_NodeCustomEvent_GetPositionInLayout()

```
ArkUI_IntOffset OH_ArkUI_NodeCustomEvent_GetPositionInLayout (ArkUI_NodeCustomEvent * event)
```
**Description**

You can customize a widget event to obtain the expected position relative to the parent widget in the layout phase.

**Since**: 12

**Parameters**

| Name  | Description              |
| ----- | ------------------------ |
| event | Customize widget events. |

**Returns**

Expected position relative to the parent component.


### OH_ArkUI_NodeCustomEvent_GetUserData()

```
void* OH_ArkUI_NodeCustomEvent_GetUserData (ArkUI_NodeCustomEvent * event)
```
**Description**

This API is used to obtain custom event parameters through custom widget events.

**Since**: 12

**Parameters**

| Name  | Description              |
| ----- | ------------------------ |
| event | Customize widget events. |

**Returns**

Customized Events and Parameters


### OH_ArkUI_NodeEvent_GetEventType()

```
ArkUI_NodeEventType OH_ArkUI_NodeEvent_GetEventType (ArkUI_NodeEvent * event)
```
**Description**

Obtains the widget event type.

**Since**: 12

**Parameters**

| Name  | Description                     |
| ----- | ------------------------------- |
| event | Pointer to the component event. |

**Returns**

ArkUI_NodeEventType Component event type.


### OH_ArkUI_NodeEvent_GetInputEvent()

```
ArkUI_UIInputEvent* OH_ArkUI_NodeEvent_GetInputEvent (ArkUI_NodeEvent * event)
```
**Description**

Obtains input event (for example, touch event) data for a component event.

**Since**: 12

**Parameters**

| Name  | Description                     |
| ----- | ------------------------------- |
| event | Pointer to the component event. |

**Returns**

* @return Returns the pointer to the input event data.


### OH_ArkUI_NodeEvent_GetNodeComponentEvent()

```
ArkUI_NodeComponentEvent* OH_ArkUI_NodeEvent_GetNodeComponentEvent (ArkUI_NodeEvent * event)
```
**Description**

Obtains the numerical data in a component event.

**Since**: 12

**Parameters**

| Name  | Description                     |
| ----- | ------------------------------- |
| event | Pointer to the component event. |

**Returns**

* @return Returns the pointer to the numerical data.


### OH_ArkUI_NodeEvent_GetNodeHandle()

```
ArkUI_NodeHandle OH_ArkUI_NodeEvent_GetNodeHandle (ArkUI_NodeEvent * event)
```
**Description**

Obtains the component object that triggers a component event.

**Since**: 12

**Parameters**

| Name  | Description                     |
| ----- | ------------------------------- |
| event | Pointer to the component event. |

**Returns**

Component object that triggers the event.


### OH_ArkUI_NodeEvent_GetStringAsyncEvent()

```
ArkUI_StringAsyncEvent* OH_ArkUI_NodeEvent_GetStringAsyncEvent (ArkUI_NodeEvent * event)
```
**Description**

Obtains the string data in a component event.

**Since**: 12

**Parameters**

| Name  | Description                     |
| ----- | ------------------------------- |
| event | Pointer to the component event. |

**Returns**

ArkUI_StringAsyncEvent\* Pointer to string data.


### OH_ArkUI_NodeEvent_GetTargetId()

```
int32_t OH_ArkUI_NodeEvent_GetTargetId (ArkUI_NodeEvent * event)
```
**Description**

Obtains the custom ID of a component event.

The event ID is transferred as a parameter when the registerNodeEvent function is called and can be used in the distribution logic of the same event entry function registerNodeEventReceiver.

**Since**: 12

**Parameters**

| Name  | Description                     |
| ----- | ------------------------------- |
| event | Pointer to the component event. |

**Returns**

* @return Returns the custom ID of the component event.


### OH_ArkUI_NodeEvent_GetUserData()

```
void* OH_ArkUI_NodeEvent_GetUserData (ArkUI_NodeEvent * event)
```
**Description**

Obtains the custom data in a component event.

* This parameter is passed in {@link registerNodeEvent} and can be applied to the service logic when the event is triggered.

**Since**: 12

**Parameters**

| Name  | Description                     |
| ----- | ------------------------------- |
| event | Pointer to the component event. |

**Returns**

* @return Returns the pointer to user data.


### OH_ArkUI_PanGesture_GetOffsetX()

```
float OH_ArkUI_PanGesture_GetOffsetX (const ArkUI_GestureEvent * event)
```
**Description**

Obtains the relative offset of a pan gesture along the x-axis.

**Since**: 12

**Parameters**

| Name  | Description        |
| ----- | ------------------ |
| event | The gesture event. |

**Returns**

* @return Returns the relative offset of the gesture along the x-axis, in px.


### OH_ArkUI_PanGesture_GetOffsetY()

```
float OH_ArkUI_PanGesture_GetOffsetY (const ArkUI_GestureEvent * event)
```
**Description**

Obtains the relative offset of a pan gesture along the y-axis.

**Since**: 12

**Parameters**

| Name  | Description        |
| ----- | ------------------ |
| event | The gesture event. |

**Returns**

* @return Returns the relative offset of the gesture along the y-axis, in px.


### OH_ArkUI_PanGesture_GetVelocity()

```
float OH_ArkUI_PanGesture_GetVelocity (const ArkUI_GestureEvent * event)
```
**Description**

Obtains the velocity of a pan gesture along the main axis.

**Since**: 12

**Parameters**

| Name  | Description        |
| ----- | ------------------ |
| event | The gesture event. |

**Returns**

* @return Returns the velocity of the pan gesture along the main axis, in px/s. The value is the square root of the sum of the squares of the velocity on the x-axis and y-axis.


### OH_ArkUI_PanGesture_GetVelocityX()

```
float OH_ArkUI_PanGesture_GetVelocityX (const ArkUI_GestureEvent * event)
```
**Description**

Obtains the velocity of a pan gesture along the x-axis.

**Since**: 12

**Parameters**

| Name  | Description        |
| ----- | ------------------ |
| event | The gesture event. |

**Returns**

* @return Returns the velocity of the pan gesture along the x-axis, in px/s.


### OH_ArkUI_PanGesture_GetVelocityY()

```
float OH_ArkUI_PanGesture_GetVelocityY (const ArkUI_GestureEvent * event)
```
**Description**

Obtains the velocity of a pan gesture along the y-axis.

**Since**: 12

**Parameters**

| Name  | Description        |
| ----- | ------------------ |
| event | The gesture event. |

**Returns**

* @return Returns the velocity of the pan gesture along the y-axis, in px/s.


### OH_ArkUI_PinchGesture_GetCenterX()

```
float OH_ArkUI_PinchGesture_GetCenterX (const ArkUI_GestureEvent * event)
```
**Description**

Obtains the X coordinate of the center of the pinch gesture, in vp, relative to the upper left corner of the current component.

**Since**: 12

**Parameters**

| Name  | Description        |
| ----- | ------------------ |
| event | The gesture event. |

**Returns**

* @return Returns the X coordinate of the center of the pinch gesture, in vp, relative to the upper left corner of the current component.


### OH_ArkUI_PinchGesture_GetCenterY()

```
float OH_ArkUI_PinchGesture_GetCenterY (const ArkUI_GestureEvent * event)
```
**Description**

Obtains the Y coordinate of the center of the pinch gesture, in vp, relative to the upper left corner of the current component.

**Since**: 12

**Parameters**

| Name  | Description        |
| ----- | ------------------ |
| event | The gesture event. |

**Returns**

* @return Returns the Y coordinate of the center of the pinch gesture, in vp, relative to the upper left corner of the current component.


### OH_ArkUI_PinchGesture_GetScale()

```
float OH_ArkUI_PinchGesture_GetScale (const ArkUI_GestureEvent * event)
```
**Description**

Obtains the scale ratio of a pinch gesture.

**Since**: 12

**Parameters**

| Name  | Description        |
| ----- | ------------------ |
| event | The gesture event. |

**Returns**

Scale.


### OH_ArkUI_QueryModuleInterfaceByName()

```
void* OH_ArkUI_QueryModuleInterfaceByName (ArkUI_NativeAPIVariantKind type, const char * structName )
```
**Description**

Obtains the native API set of a specified type.

**Since**: 12

**Parameters**

| Name       | Description                                                  |
| ---------- | ------------------------------------------------------------ |
| type       | * @param type Indicates the type of the native API set provided by ArkUI, for example, **ARKUI_NATIVE_NODE** and **ARKUI_NATIVE_GESTURE**. |
| sturctName | * @param sturctName Indicates the name of a native struct defined in the corresponding header file, for example, **ArkUI_NativeNodeAPI_1** in <arkui/native_node.h>. |

**Returns**

void\* Returns the abstract pointer of the Native interface, which is used after being converted into a specific type. \#include&lt;arkui/native_interface.h&gt; \#include&lt;arkui/native_node.h&gt; \#include&lt;arkui/native_gesture.h&gt; auto\* anyNativeAPI = [OH_ArkUI_QueryModuleInterfaceByName](#oh_arkui_querymoduleinterfacebyname)(ARKUI_NATIVE_NODE, "ArkUI_NativeNodeAPI_1"); if (anyNativeAPI) { auto nativeNodeApi = reinterpret_cast&lt;[ArkUI_NativeNodeAPI_1](_ark_u_i___native_node_a_p_i__1.md)\*&gt;(anyNativeAPI); } auto anyGestureAPI = OH_ArkUI_QueryModuleInterface(ARKUI_NATIVE_GESTURE, "ArkUI_NativeGestureAPI_1"); if (anyNativeAPI) { auto basicGestureApi = reinterpret_cast&lt;[ArkUI_NativeGestureAPI_1](_ark_u_i___native_gesture_a_p_i__1.md)\*&gt;(anyGestureAPI); }


### OH_ArkUI_RotationGesture_GetAngle()

```
float OH_ArkUI_RotationGesture_GetAngle (const ArkUI_GestureEvent * event)
```
**Description**

Obtains the angle information of a rotation gesture.

**Since**: 12

**Parameters**

| Name  | Description        |
| ----- | ------------------ |
| event | The gesture event. |

**Returns**

Rotation angle.


### OH_ArkUI_SwipeGesture_GetAngle()

```
float OH_ArkUI_SwipeGesture_GetAngle (const ArkUI_GestureEvent * event)
```
**Description**

Obtains the angle information of the swipe gesture.

**Since**: 12

**Parameters**

| Name  | Description        |
| ----- | ------------------ |
| event | The gesture event. |

**Returns**

* @return Returns the angle of the swipe gesture, which is the result obtained based on the aforementioned formula.


### OH_ArkUI_SwipeGesture_GetVelocity()

```
float OH_ArkUI_SwipeGesture_GetVelocity (const ArkUI_GestureEvent * event)
```
**Description**

Obtains the average velocity of all fingers used in the swipe gesture.

**Since**: 12

**Parameters**

| Name  | Description        |
| ----- | ------------------ |
| event | The gesture event. |

**Returns**

* @return Returns the average velocity of all fingers used in the swipe gesture, in px/s.


### OH_ArkUI_SwiperIndicator_Create()

```
ArkUI_SwiperIndicator* OH_ArkUI_SwiperIndicator_Create (ArkUI_SwiperIndicatorType type)
```
**Description**

Creates a navigation indicator for the Swiper component.

**Since**: 12

**Parameters**

| Name | Description                       |
| ---- | --------------------------------- |
| type | Type of the navigation indicator. |

**Returns**

* @return Returns the pointer to the navigation point indicator.


### OH_ArkUI_SwiperIndicator_Dispose()

```
void OH_ArkUI_SwiperIndicator_Dispose (ArkUI_SwiperIndicator * indicator)
```
**Description**

Destroys the navigation point indicator of this **<Swiper>** component.

**Since**: 12

**Parameters**

| Name      | Description                                                  |
| --------- | ------------------------------------------------------------ |
| indicator | * @return Returns the pointer to the navigation point indicator. |


### OH_ArkUI_SwiperIndicator_GetBottomPosition()

```
float OH_ArkUI_SwiperIndicator_GetBottomPosition (ArkUI_SwiperIndicator * indicator)
```
**Description**

Obtains the distance between a navigation point indicator and the bottom edge of the **<Swiper>** component.

**Since**: 12

**Parameters**

| Name      | Description                                                  |
| --------- | ------------------------------------------------------------ |
| indicator | * @return Returns the pointer to the navigation point indicator. |

**Returns**

* @return Returns the distance between a navigation point indicator and the bottom edge of the **<Swiper>** component.


### OH_ArkUI_SwiperIndicator_GetColor()

```
uint32_t OH_ArkUI_SwiperIndicator_GetColor (ArkUI_SwiperIndicator * indicator)
```
**Description**

Obtains the color of a navigation point indicator of the dot style of the **<Swiper>** component.

**Since**: 12

**Parameters**

| Name      | Description                                                  |
| --------- | ------------------------------------------------------------ |
| indicator | * @return Returns the pointer to the navigation point indicator. |

**Returns**

* @return Returns the color, in 0xARGB format. For example, 0xFFFF0000 indicates red.


### OH_ArkUI_SwiperIndicator_GetItemHeight()

```
float OH_ArkUI_SwiperIndicator_GetItemHeight (ArkUI_SwiperIndicator * indicator)
```
**Description**

Obtains the height of a navigation point indicator of the dot style of the **<Swiper>** component.

**Since**: 12

**Parameters**

| Name      | Description                                                  |
| --------- | ------------------------------------------------------------ |
| indicator | * @return Returns the pointer to the navigation point indicator. |

**Returns**

* @return Returns the height of the navigation point indicator of the dot style.


### OH_ArkUI_SwiperIndicator_GetItemWidth()

```
float OH_ArkUI_SwiperIndicator_GetItemWidth (ArkUI_SwiperIndicator * indicator)
```
**Description**

Obtains the width of a navigation point indicator of the dot style of the **<Swiper>** component.

**Since**: 12

**Parameters**

| Name      | Description                                                  |
| --------- | ------------------------------------------------------------ |
| indicator | * @return Returns the pointer to the navigation point indicator. |

**Returns**

* @return Returns the width of the navigation point indicator of the dot style.


### OH_ArkUI_SwiperIndicator_GetStartPosition()

```
float OH_ArkUI_SwiperIndicator_GetStartPosition (ArkUI_SwiperIndicator * indicator)
```
**Description**

Obtains the distance between a navigation point indicator and the left edge of the **<Swiper>** component.

**Since**: 12

**Parameters**

| Name      | Description                                                  |
| --------- | ------------------------------------------------------------ |
| indicator | * @return Returns the pointer to the navigation point indicator. |

**Returns**

* @return Returns the distance between the navigation point indicator and the left edge of the **<Swiper>** component.


### OH_ArkUI_SwiperIndicator_GetMask()

```
int32_t OH_ArkUI_SwiperIndicator_GetMask (ArkUI_SwiperIndicator * indicator)
```
**Description**

Obtains whether the mask is enabled for a navigation point indicator of the dot style of the **<Swiper>** component.

**Since**: 12

**Parameters**

| Name      | Description                                                  |
| --------- | ------------------------------------------------------------ |
| indicator | * @return Returns the pointer to the navigation point indicator. |

**Returns**

* @return Returns **1** if the mask is enabled; returns **0** otherwise.


### OH_ArkUI_SwiperIndicator_GetEndPosition()

```
float OH_ArkUI_SwiperIndicator_GetEndPosition (ArkUI_SwiperIndicator * indicator)
```
**Description**

Obtains the distance between a navigation point indicator and the right edge of the **<Swiper>** component.

**Since**: 12

**Parameters**

| Name      | Description                                                  |
| --------- | ------------------------------------------------------------ |
| indicator | * @return Returns the pointer to the navigation point indicator. |

**Returns**

* @return Returns the distance between the navigation point indicator and the right edge of the **<Swiper>** component.


### OH_ArkUI_SwiperIndicator_GetSelectedColor()

```
uint32_t OH_ArkUI_SwiperIndicator_GetSelectedColor (ArkUI_SwiperIndicator * indicator)
```
**Description**

Obtains the color of the selected navigation point indicator of the dot style of the **<Swiper>** component.

**Since**: 12

**Parameters**

| Name      | Description                                                  |
| --------- | ------------------------------------------------------------ |
| indicator | * @return Returns the pointer to the navigation point indicator. |

**Returns**

* @return Returns the color, in 0xARGB format. For example, 0xFFFF0000 indicates red.


### OH_ArkUI_SwiperIndicator_GetSelectedItemHeight()

```
float OH_ArkUI_SwiperIndicator_GetSelectedItemHeight (ArkUI_SwiperIndicator * indicator)
```
**Description**

Obtains the height of the selected navigation point indicator of the dot style of the **<Swiper>** component.

**Since**: 12

**Parameters**

| Name      | Description                                                  |
| --------- | ------------------------------------------------------------ |
| indicator | * @return Returns the pointer to the navigation point indicator. |

**Returns**

* @return Returns the height of the navigation point indicator of the dot style.


### OH_ArkUI_SwiperIndicator_GetSelectedItemWidth()

```
float OH_ArkUI_SwiperIndicator_GetSelectedItemWidth (ArkUI_SwiperIndicator * indicator)
```
**Description**

Obtains the width of the selected navigation point indicator of the dot style of the **<Swiper>** component.

**Since**: 12

**Parameters**

| Name      | Description                                                  |
| --------- | ------------------------------------------------------------ |
| indicator | * @return Returns the pointer to the navigation point indicator. |

**Returns**

* @return Returns the width of the navigation point indicator of the dot style.


### OH_ArkUI_SwiperIndicator_GetTopPosition()

```
float OH_ArkUI_SwiperIndicator_GetTopPosition (ArkUI_SwiperIndicator * indicator)
```
**Description**

Obtains the distance between a navigation point indicator and the top edge of the **<Swiper>** component.

**Since**: 12

**Parameters**

| Name      | Description                                                  |
| --------- | ------------------------------------------------------------ |
| indicator | * @return Returns the pointer to the navigation point indicator. |

**Returns**

* @return Returns the distance between a navigation point indicator and the top edge of the **<Swiper>** component.


### OH_ArkUI_SwiperIndicator_SetBottomPosition()

```
void OH_ArkUI_SwiperIndicator_SetBottomPosition (ArkUI_SwiperIndicator * indicator, float value )
```
**Description**

Distance between the navigation point indicator and the top edge of the **\<Swiper>** component.

**Since**: 12

**Parameters**

| Name      | Description                                                  |
| --------- | ------------------------------------------------------------ |
| indicator | * @return Returns the pointer to the navigation point indicator. |
| value     | * @return Returns the distance between a navigation point indicator and the bottom edge of the **<Swiper>** component. |


### OH_ArkUI_SwiperIndicator_SetColor()

```
void OH_ArkUI_SwiperIndicator_SetColor (ArkUI_SwiperIndicator * indicator, uint32_t color )
```
**Description**

Sets the color of a navigation point indicator of the dot style for the **<Swiper>** component.

**Since**: 12

**Parameters**

| Name      | Description                                                  |
| --------- | ------------------------------------------------------------ |
| indicator | * @return Returns the pointer to the navigation point indicator. |
| color     | * @return Returns the color, in 0xARGB format. For example, 0xFFFF0000 indicates red. |


### OH_ArkUI_SwiperIndicator_SetItemHeight()

```
void OH_ArkUI_SwiperIndicator_SetItemHeight (ArkUI_SwiperIndicator * indicator, float value )
```
**Description**

Sets the height of a navigation point indicator of the dot style for the **<Swiper>** component.

**Since**: 12

**Parameters**

| Name      | Description                                                  |
| --------- | ------------------------------------------------------------ |
| indicator | * @return Returns the pointer to the navigation point indicator. |
| value     | * @return Returns the height of the navigation point indicator of the dot style. |


### OH_ArkUI_SwiperIndicator_SetItemWidth()

```
void OH_ArkUI_SwiperIndicator_SetItemWidth (ArkUI_SwiperIndicator * indicator, float value )
```
**Description**

Sets the width of a navigation point indicator of the dot style for the **<Swiper>** component.

**Since**: 12

**Parameters**

| Name      | Description                                                  |
| --------- | ------------------------------------------------------------ |
| indicator | * @return Returns the pointer to the navigation point indicator. |
| value     | * @return Returns the width of the navigation point indicator of the dot style. |


### OH_ArkUI_SwiperIndicator_SetStartPosition()

```
void OH_ArkUI_SwiperIndicator_SetStartPosition (ArkUI_SwiperIndicator * indicator, float value )
```
**Description**

Distance between the navigation point indicator and the left edge of the **\<Swiper>** component.

**Since**: 12

**Parameters**

| Name      | Description                                                  |
| --------- | ------------------------------------------------------------ |
| indicator | * @return Returns the pointer to the navigation point indicator. |
| value     | * @return Returns the distance between the navigation point indicator and the left edge of the **<Swiper>** component. |


### OH_ArkUI_SwiperIndicator_SetMask()

```
void OH_ArkUI_SwiperIndicator_SetMask (ArkUI_SwiperIndicator * indicator, int32_t mask )
```
**Description**

Sets whether to enable the mask for a navigation point indicator of the dot style for the **<Swiper>** component.

**Since**: 12

**Parameters**

| Name      | Description                                                  |
| --------- | ------------------------------------------------------------ |
| indicator | * @return Returns the pointer to the navigation point indicator. |
| mask      | Indicates whether to display the mask style. The value 1 indicates that the mask style is displayed, and the value 0 indicates that the mask style is not displayed. |


### OH_ArkUI_SwiperIndicator_SetEndPosition()

```
void OH_ArkUI_SwiperIndicator_SetEndPosition (ArkUI_SwiperIndicator * indicator, float value )
```
**Description**

Distance between the navigation point indicator and the left edge of the **\<Swiper>** component.

**Since**: 12

**Parameters**

| Name      | Description                                                  |
| --------- | ------------------------------------------------------------ |
| indicator | * @return Returns the pointer to the navigation point indicator. |
| value     | * @return Returns the distance between the navigation point indicator and the right edge of the **<Swiper>** component. |


### OH_ArkUI_SwiperIndicator_SetSelectedColor()

```
void OH_ArkUI_SwiperIndicator_SetSelectedColor (ArkUI_SwiperIndicator * indicator, uint32_t selectedColor )
```
**Description**

Sets the color of the selected navigation point indicator of the dot style for the **<Swiper>** component.

**Since**: 12

**Parameters**

| Name          | Description                                                  |
| ------------- | ------------------------------------------------------------ |
| indicator     | * @return Returns the pointer to the navigation point indicator. |
| selectedColor | * @return Returns the color, in 0xARGB format. For example, 0xFFFF0000 indicates red. |


### OH_ArkUI_SwiperIndicator_SetSelectedItemHeight()

```
void OH_ArkUI_SwiperIndicator_SetSelectedItemHeight (ArkUI_SwiperIndicator * indicator, float value )
```
**Description**

Sets the height of the selected navigation point indicator of the dot style for the **<Swiper>** component.

**Since**: 12

**Parameters**

| Name      | Description                                                  |
| --------- | ------------------------------------------------------------ |
| indicator | * @return Returns the pointer to the navigation point indicator. |
| value     | * @return Returns the height of the navigation point indicator of the dot style. |


### OH_ArkUI_SwiperIndicator_SetSelectedItemWidth()

```
void OH_ArkUI_SwiperIndicator_SetSelectedItemWidth (ArkUI_SwiperIndicator * indicator, float value )
```
**Description**

Sets the width of the selected navigation point indicator of the dot style for the **<Swiper>** component.

**Since**: 12

**Parameters**

| Name      | Description                                                  |
| --------- | ------------------------------------------------------------ |
| indicator | * @return Returns the pointer to the navigation point indicator. |
| value     | * @return Returns the width of the navigation point indicator of the dot style. |


### OH_ArkUI_SwiperIndicator_SetTopPosition()

```
void OH_ArkUI_SwiperIndicator_SetTopPosition (ArkUI_SwiperIndicator * indicator, float value )
```
**Description**

Distance between the navigation point indicator and the top edge of the **\<Swiper>** component.

**Since**: 12

**Parameters**

| Name      | Description                                                  |
| --------- | ------------------------------------------------------------ |
| indicator | * @return Returns the pointer to the navigation point indicator. |
| value     | * @return Returns the distance between a navigation point indicator and the top edge of the **<Swiper>** component. |


### OH_ArkUI_WaterFlowSectionOption_Create()

```
ArkUI_WaterFlowSectionOption* OH_ArkUI_WaterFlowSectionOption_Create ()
```
**Description**

Create FlowItem group configuration information.

**Since**: 12

**Returns**

Describes the configuraiton of the water flow item section.


### OH_ArkUI_WaterFlowSectionOption_Dispose()

```
void OH_ArkUI_WaterFlowSectionOption_Dispose (ArkUI_WaterFlowSectionOption * option)
```
**Description**

Pointer to the configuration information of the flow item group to be destroyed.

**Since**: 12

**Parameters**

| Name   | Description                                                 |
| ------ | ----------------------------------------------------------- |
| option | Describes the configuraiton of the water flow item section. |


### OH_ArkUI_WaterFlowSectionOption_GetColumnGap()

```
float OH_ArkUI_WaterFlowSectionOption_GetColumnGap (ArkUI_WaterFlowSectionOption * option, int32_t index )
```
**Description**

Obtains the gap between columns in the water flow section that matches the specified index.

**Since**: 12

**Parameters**

| Name   | Description                                                 |
| ------ | ----------------------------------------------------------- |
| option | Describes the configuraiton of the water flow item section. |
| index  | FlowItem index.                                             |

**Returns**

Column spacing.


### OH_ArkUI_WaterFlowSectionOption_GetCrossCount()

```
int32_t OH_ArkUI_WaterFlowSectionOption_GetCrossCount (ArkUI_WaterFlowSectionOption * option, int32_t index )
```
**Description**

Obtains the number of layout grids under the corresponding index based on the FlowItem group configuration information.

**Since**: 12

**Parameters**

| Name   | Description                                                 |
| ------ | ----------------------------------------------------------- |
| option | Describes the configuraiton of the water flow item section. |
| index  | FlowItem index.                                             |

**Returns**

Number of layout grids.


### OH_ArkUI_WaterFlowSectionOption_GetItemCount()

```
int32_t OH_ArkUI_WaterFlowSectionOption_GetItemCount (ArkUI_WaterFlowSectionOption * option, int32_t index )
```
**Description**

Obtains the number of flow items under the corresponding index based on the flow item group configuration information.

**Since**: 12

**Parameters**

| Name   | Description                                                 |
| ------ | ----------------------------------------------------------- |
| option | Describes the configuraiton of the water flow item section. |
| index  | FlowItem index.                                             |

**Returns**

Number of FlowItems in a group.


### OH_ArkUI_WaterFlowSectionOption_GetMargin()

```
ArkUI_IntMargin OH_ArkUI_WaterFlowSectionOption_GetMargin (ArkUI_WaterFlowSectionOption * option, int32_t index )
```
**Description**

Obtains the margins of the water flow section that matches the specified index.

**Since**: 12

**Parameters**

| Name   | Description                                                 |
| ------ | ----------------------------------------------------------- |
| option | Describes the configuraiton of the water flow item section. |
| index  | FlowItem index.                                             |

**Returns**

Margin of the component.


### OH_ArkUI_WaterFlowSectionOption_GetRowGap()

```
float OH_ArkUI_WaterFlowSectionOption_GetRowGap (ArkUI_WaterFlowSectionOption * option, int32_t index )
```
**Description**

Obtains the gap between rows in the water flow section that matches the specified index.

**Since**: 12

**Parameters**

| Name   | Description                                                 |
| ------ | ----------------------------------------------------------- |
| option | Describes the configuraiton of the water flow item section. |
| index  | FlowItem index.                                             |

**Returns**

Line spacing.


### OH_ArkUI_WaterFlowSectionOption_SetColumnGap()

```
void OH_ArkUI_WaterFlowSectionOption_SetColumnGap (ArkUI_WaterFlowSectionOption * , int32_t index, float columnGap )
```
**Description**

Set the column spacing for grouping.

**Since**: 12

**Parameters**

| Name      | Description                                                 |
| --------- | ----------------------------------------------------------- |
| option    | Describes the configuraiton of the water flow item section. |
| index     | FlowItem index.                                             |
| columnGap | Column spacing.                                             |


### OH_ArkUI_WaterFlowSectionOption_SetCrossCount()

```
void OH_ArkUI_WaterFlowSectionOption_SetCrossCount (ArkUI_WaterFlowSectionOption * option, int32_t index, int32_t crossCount )
```
**Description**

Sets the number of columns (in a vertical layout) or rows (in a horizontal layout) of a water flow.

**Since**: 12

**Parameters**

| Name       | Description                                                 |
| ---------- | ----------------------------------------------------------- |
| option     | Describes the configuraiton of the water flow item section. |
| index      | FlowItem index.                                             |
| crossCount | Number of layout grids.                                     |


### OH_ArkUI_WaterFlowSectionOption_SetItemCount()

```
void OH_ArkUI_WaterFlowSectionOption_SetItemCount (ArkUI_WaterFlowSectionOption * option, int32_t index, int32_t itemCount )
```
**Description**

Set the number of FlowItems in the group.

**Since**: 12

**Parameters**

| Name      | Description                                                 |
| --------- | ----------------------------------------------------------- |
| option    | Describes the configuraiton of the water flow item section. |
| index     | FlowItem index.                                             |
| itemCount | Number of FlowItems in a group.                             |


### OH_ArkUI_WaterFlowSectionOption_SetMargin()

```
void OH_ArkUI_WaterFlowSectionOption_SetMargin (ArkUI_WaterFlowSectionOption * option, int32_t index, float marginTop, float marginRight, float marginBottom, float marginLeft )
```
**Description**

Sets the outer margin of a group.

**Since**: 12

**Parameters**

| Name         | Description                                                 |
| ------------ | ----------------------------------------------------------- |
| option       | Describes the configuraiton of the water flow item section. |
| index        | FlowItem index.                                             |
| marginTop    | Top margin of a flow item.                                  |
| marginRight  | Right margin of a flow item.                                |
| marginBottom | Bottom margin of a flow item.                               |
| marginLeft   | Left margin of a flow item.                                 |


### OH_ArkUI_WaterFlowSectionOption_SetRowGap()

```
void OH_ArkUI_WaterFlowSectionOption_SetRowGap (ArkUI_WaterFlowSectionOption * option, int32_t index, float rowGap )
```
**Description**

Sets the line spacing of a group.

**Since**: 12

**Parameters**

| Name   | Description                                                 |
| ------ | ----------------------------------------------------------- |
| option | Describes the configuraiton of the water flow item section. |
| index  | FlowItem index.                                             |
| rowGap | Interline spacing.                                          |


### OH_ArkUI_WaterFlowSectionOption_SetSize()

```
void OH_ArkUI_WaterFlowSectionOption_SetSize (ArkUI_WaterFlowSectionOption * option, int32_t size )
```
**Description**

Sets the length of the FlowItem group configuration information array.

**Since**: 12

**Parameters**

| Name   | Description                                                 |
| ------ | ----------------------------------------------------------- |
| option | Describes the configuraiton of the water flow item section. |
| size   | Size of the array.                                          |