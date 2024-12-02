# ArkUI_NativeModule


## Overview

Provides drag and drop APIs of ArkUI on the native side.

Provides the APIs of ArkUI to register gesture callbacks on the native side.

Provides animation callbacks of ArkUI on the native side.

Provides UI capabilities of ArkUI on the native side, such as UI component creation and destruction, tree node operations, attribute setting, and event listening.

**Since**: 12


## Summary


### Files

| Name | Description |
| -------- | -------- |
| [drag_and_drop.h](drag__and__drop_8h.md) | Declares the APIs of **NativeDrag**.<br> **Library**: libace_ndk.z.so|
| [drawable_descriptor.h](drawable__descriptor_8h.md) | Declares the APIs of **NativeDrawableDescriptor**.<br> **Library**: libace_ndk.z.so|
| [native_animate.h](native__animate_8h.md) | Declares a set of animation APIs of ArkUI on the native side.<br> **Library**: libace_ndk.z.so|
| [native_dialog.h](native__dialog_8h.md) | Declares a set of custom dialog box APIs of ArkUI on the native side.<br> **Library**: libace_ndk.z.so|
| [native_gesture.h](native__gesture_8h.md) | Declares the APIs of **NativeGesture**.<br> **Library**: libace_ndk.z.so|
| [native_interface.h](native__interface_8h.md) | Declares a unified entry for the native module APIs.<br> **Library**: libace_ndk.z.so|
| [native_node.h](native__node_8h.md) | Declares the APIs of **NativeNode**.<br> **Library**: libace_ndk.z.so|
| [native_node_napi.h](native__node__napi_8h.md) | Declares the functions used to convert FrameNodes on the ArkTS side into NodeHandles.<br> **Library**: libace_ndk.z.so|
| [native_type.h](native__type_8h.md) | Defines the common types for the native module.<br> **Library**: libace_ndk.z.so|
| [styled_string.h](styled__string_8h.md) | Declares styled string APIs of ArkUI on the native side.<br> **Library**: libace_ndk.z.so|


### Structs

| Name | Description |
| -------- | -------- |
| struct  [ArkUI_ExpectedFrameRateRange](_ark_u_i___expected_frame_rate_range.md) | Defines a struct for the expected frame rate range of the animation. |
| struct  [ArkUI_AnimateCompleteCallback](_ark_u_i___animate_complete_callback.md) | Defines a struct for the callback type for when the animation playback is complete. |
| struct  [ArkUI_NativeAnimateAPI_1](_ark_u_i___native_animate_a_p_i__1.md) | Defines a struct for the animation APIs of ArkUI on the native side. |
| struct  [ArkUI_NativeDialogAPI_1](_ark_u_i___native_dialog_a_p_i__1.md) | Defines a struct for the custom dialog box APIs on the native side. |
| struct  [ArkUI_NativeGestureAPI_1](_ark_u_i___native_gesture_a_p_i__1.md) | Defines a struct for the gesture APIs. |
| struct  [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) | Defines the general input parameter structure of the **setAttribute** function. |
| struct  [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) | Defines a struct for the parameter type of the component callback event. |
| struct  [ArkUI_StringAsyncEvent](_ark_u_i___string_async_event.md) | Defines the string type parameter used by the component callback event. |
| struct  [ArkUI_NativeNodeAPI_1](_ark_u_i___native_node_a_p_i__1.md) | Defines a struct for node APIs of ArkUI on the native side. |
| struct  [ArkUI_ContextCallback](_ark_u_i___context_callback.md) | Defines event callback. |
| union  [ArkUI_NumberValue](union_ark_u_i___number_value.md) | Provides the number types of ArkUI in the native code. |
| struct  [ARKUI_TextPickerRangeContent](_a_r_k_u_i___text_picker_range_content.md) | Defines the input structure of the single-column text picker with image resources. |
| struct  [ARKUI_TextPickerCascadeRangeContent](_a_r_k_u_i___text_picker_cascade_range_content.md) | Defines the input structure of the interconnected multi-column text picker. |
| struct  [ArkUI_ColorStop](_ark_u_i___color_stop.md) | Defines a gradient color stop. |
| struct  [ArkUI_Rect](_ark_u_i___rect.md) | Defines a mask area. |
| struct  [ArkUI_IntSize](_ark_u_i___int_size.md) | Describes the width and height of a component. |
| struct  [ArkUI_IntOffset](_ark_u_i___int_offset.md) | Describes the position of a component. |
| struct  [ArkUI_Margin](_ark_u_i___margin.md) | Describes the margins of a component. |
| struct  [ArkUI_TranslationOptions](_ark_u_i___translation_options.md) | Defines the translation options for component transition. |
| struct  [ArkUI_ScaleOptions](_ark_u_i___scale_options.md) | Defines the scaling options for component transition. |
| struct  [ArkUI_RotationOptions](_ark_u_i___rotation_options.md) | Defines the rotation options for component transition. |


### Macros

| Name | Description |
| -------- | -------- |
| [OH_ArkUI_GetModuleInterface](#oh_arkui_getmoduleinterface)(nativeAPIVariantKind, structType, structPtr) | Obtains the macro function corresponding to a struct pointer based on the struct type. |
| **MAX_NODE_SCOPE_NUM**  | 1000 |
| **MAX_COMPONENT_EVENT_ARG_NUM** | 12 |


### Types

| Name | Description |
| -------- | -------- |
| typedef struct [ArkUI_NodeEvent](#arkui_nodeevent-12) [ArkUI_NodeEvent](#arkui_nodeevent-12) | Defines a struct for a component event. |
| typedef struct [ArkUI_Context](#arkui_context) [ArkUI_Context](#arkui_context) | Defines a struct for a UI context object. |
| typedef struct [ArkUI_Context](#arkui_context) \* [ArkUI_ContextHandle](#arkui_contexthandle-12) | Defines a struct for the handle to the ArkUI native UI context. |
| typedef struct [ArkUI_DragEvent](#arkui_dragevent) [ArkUI_DragEvent](#arkui_dragevent) | Defines a struct for a drag event. |
| typedef struct [ArkUI_DragPreviewOption](#arkui_dragpreviewoption) [ArkUI_DragPreviewOption](#arkui_dragpreviewoption) | Defines a struct for custom drag preview options. |
| typedef struct [ArkUI_DragAction](#arkui_dragaction) [ArkUI_DragAction](#arkui_dragaction) | Defines a struct for a drag action. |
| typedef struct [ArkUI_DragAndDropInfo](#arkui_draganddropinfo) [ArkUI_DragAndDropInfo](#arkui_draganddropinfo) | Defines a struct for drag and drop information returned through a drag status listener. |
| typedef struct [OH_UdmfData](#oh_udmfdata) [OH_UdmfData](#oh_udmfdata) | Defines a struct for UDMF unified data. |
| typedef struct [OH_PixelmapNative](#oh_pixelmapnative) [OH_PixelmapNative](#oh_pixelmapnative) | Defines the **Pixelmap** struct, which is used to perform operations related to a pixel map. |
| typedef struct [ArkUI_DrawableDescriptor](#arkui_drawabledescriptor) [ArkUI_DrawableDescriptor](#arkui_drawabledescriptor) | Defines a struct for the **DrawableDescriptor** object. |
| typedef struct [OH_PixelmapNative](#oh_pixelmapnative) \* [OH_PixelmapNativeHandle](#oh_pixelmapnativehandle) | Defines a struct for the pointer to an **OH_PixelmapNative** object. |
| typedef struct [ArkUI_AnimateOption](#arkui_animateoption) [ArkUI_AnimateOption](#arkui_animateoption) | Defines a struct for the animation configuration. |
| typedef struct ArkUI_Curve \* [ArkUI_CurveHandle](#arkui_curvehandle) | Defines a struct for the pointer to an interpolation curve. |
| typedef struct [ArkUI_KeyframeAnimateOption](#arkui_keyframeanimateoption) [ArkUI_KeyframeAnimateOption](#arkui_keyframeanimateoption) | Defines a struct for the keyframe animation parameter object. |
| typedef struct [ArkUI_AnimatorOption](#arkui_animatoroption) [ArkUI_AnimatorOption](#arkui_animatoroption) | Defines the animator parameter object. |
| typedef struct ArkUI_Animator \* [ArkUI_AnimatorHandle](#arkui_animatorhandle) | Defines a struct for the pointer to an animator object. |
| typedef struct [ArkUI_TransitionEffect](#arkui_transitioneffect) [ArkUI_TransitionEffect](#arkui_transitioneffect) | Defines a struct for the transition effect. |
| typedef bool(\* [ArkUI_OnWillDismissEvent](#arkui_onwilldismissevent)) (int32_t reason) | Defines a pointer to the callback invoked when the dialog box is closed. |
| typedef struct [ArkUI_DialogDismissEvent](#arkui_dialogdismissevent) [ArkUI_DialogDismissEvent](#arkui_dialogdismissevent) | Defines a struct for a dialog box dismiss event. |
| typedef uint32_t [ArkUI_GestureEventActionTypeMask](#arkui_gestureeventactiontypemask) | Defines a set of gesture event types. |
| typedef uint32_t [ArkUI_GestureDirectionMask](#arkui_gesturedirectionmask) | Defines a set of gesture directions. |
| typedef ArkUI_GestureRecognizer \* [ArkUI_GestureRecognizerHandle](#arkui_gesturerecognizerhandle) | Defines the gesture recognizer handle. |
| typedef [ArkUI_GestureRecognizerHandle](#arkui_gesturerecognizerhandle) \* [ArkUI_GestureRecognizerHandleArray](#arkui_gesturerecognizerhandlearray) | Defines the gesture recognizer handle array. |
| typedef struct [ArkUI_GestureEventTargetInfo](#arkui_gestureeventtargetinfo) [ArkUI_GestureEventTargetInfo](#arkui_gestureeventtargetinfo) | Defines a struct for a **GestureEventTargetInfo** object that provides information about a gesture event target. |
| typedef struct [ArkUI_ParallelInnerGestureEvent](#arkui_parallelinnergestureevent) [ArkUI_ParallelInnerGestureEvent](#arkui_parallelinnergestureevent) | Defines a parallel internal gesture event. |
| typedef void(\* [ArkUI_GestureRecognizerDestructNotifyCallback](#arkui_gesturerecognizerdestructnotifycallback)) (ArkUI_GestureRecognizer \*recognizer, void \*userData) | Defines a callback function for notifying gesture recognizer destruction. |
| typedef struct [ArkUI_NodeEvent](#arkui_nodeevent-12) [ArkUI_NodeEvent](#arkui_nodeevent-12) | Defines the common structure of a component event. |
| typedef struct [ArkUI_NodeCustomEvent](#arkui_nodecustomevent) [ArkUI_NodeCustomEvent](#arkui_nodecustomevent) | Defines the common structure of a custom component event. |
| typedef struct ArkUI_NodeAdapter \* [ArkUI_NodeAdapterHandle](#arkui_nodeadapterhandle) | Defines the component adapter, which is used for lazy loading of elements of scrollable components. |
| typedef struct [ArkUI_NodeAdapterEvent](#arkui_nodeadapterevent) [ArkUI_NodeAdapterEvent](#arkui_nodeadapterevent) | Defines the component adapter event. |
| typedef struct [ArkUI_NodeContentEvent](#arkui_nodecontentevent) [ArkUI_NodeContentEvent](#arkui_nodecontentevent) | Defines the common structure type of a NodeContent event. |
| typedef void(\* [ArkUI_NodeContentCallback](#arkui_nodecontentcallback)) ([ArkUI_NodeContentEvent](#arkui_nodecontentevent) \*event) | Defines the callback for the NodeContent event. |
| typedef struct [ArkUI_LayoutConstraint](#arkui_layoutconstraint) [ArkUI_LayoutConstraint](#arkui_layoutconstraint) | Defines the size constraints of a component during component layout. |
| typedef struct [ArkUI_DrawContext](#arkui_drawcontext) [ArkUI_DrawContext](#arkui_drawcontext) | Defines the component drawing context. |
| typedef struct ArkUI_Node \* [ArkUI_NodeHandle](#arkui_nodehandle) | Defines the pointer to the ArkUI native component object. |
| typedef struct ArkUI_NativeDialog \* [ArkUI_NativeDialogHandle](#arkui_nativedialoghandle) | Defines the handle to the custom dialog box controller of ArkUI on the native side. |
| typedef struct [ArkUI_WaterFlowSectionOption](#arkui_waterflowsectionoption) [ArkUI_WaterFlowSectionOption](#arkui_waterflowsectionoption) | Defines the water flow section configuration. |
| typedef struct [ArkUI_ListItemSwipeActionItem](#arkui_listitemswipeactionitem) [ArkUI_ListItemSwipeActionItem](#arkui_listitemswipeactionitem) | Defines the item configuration for **ListItemSwipeActionOption**. |
| typedef struct [ArkUI_ListItemSwipeActionOption](#arkui_listitemswipeactionoption) [ArkUI_ListItemSwipeActionOption](#arkui_listitemswipeactionoption) | Defines the configuration for **ListItemSwipeActionOption**. |
| typedef struct [ArkUI_Context](#arkui_context) \* [ArkUI_ContextHandle](#arkui_contexthandle-12) | Defines the handle to the ArkUI native UI context. |
| typedef struct ArkUI_NodeContent \* [ArkUI_NodeContentHandle](#arkui_nodecontenthandle) | Defines the handle to the ArkUI NodeContent instance on the native side. |
| typedef struct [ArkUI_AlignmentRuleOption](#arkui_alignmentruleoption) [ArkUI_AlignmentRuleOption](#arkui_alignmentruleoption) | Defines the alignment rule in the relative container. |
| typedef struct [ArkUI_GuidelineOption](#arkui_guidelineoption) [ArkUI_GuidelineOption](#arkui_guidelineoption) | Defines the ID, direction, and position of a guideline. |
| typedef struct [ArkUI_BarrierOption](#arkui_barrieroption) [ArkUI_BarrierOption](#arkui_barrieroption) | Defines the ID, direction, and referenced component of a barrier. |
| typedef struct [ArkUI_ImageAnimatorFrameInfo](#arkui_imageanimatorframeinfo) [ArkUI_ImageAnimatorFrameInfo](#arkui_imageanimatorframeinfo) | Defines the image frame information. |
| typedef struct [ArkUI_ListChildrenMainSize](#arkui_listchildrenmainsize) [ArkUI_ListChildrenMainSize](#arkui_listchildrenmainsize) | Defines the **ChildrenMainSize** information of the **List** component. |
| typedef struct [ArkUI_AccessibilityState](#arkui_accessibilitystate) [ArkUI_AccessibilityState](#arkui_accessibilitystate) | Defines a struct for the component accessibility state. |
| typedef struct [ArkUI_AccessibilityValue](#arkui_accessibilityvalue) [ArkUI_AccessibilityValue](#arkui_accessibilityvalue) | Defines a struct for the component accessibility value. |
| typedef struct [ArkUI_SystemFontStyleEvent](#arkui_systemfontstyleevent) [ArkUI_SystemFontStyleEvent](#arkui_systemfontstyleevent) | Defines a struct for the system font style event. |
| typedef struct [ArkUI_CustomSpanMeasureInfo](#arkui_customspanmeasureinfo) [ArkUI_CustomSpanMeasureInfo](#arkui_customspanmeasureinfo) | Defines a struct for the measurement information of a custom span. |
| typedef struct [ArkUI_CustomSpanMetrics](#arkui_customspanmetrics) [ArkUI_CustomSpanMetrics](#arkui_customspanmetrics) | Defines a struct for the measurement metrics of a custom span. |
| typedef struct [ArkUI_CustomSpanDrawInfo](#arkui_customspandrawinfo) [ArkUI_CustomSpanDrawInfo](#arkui_customspandrawinfo) | Defines a struct for the drawing information of a custom span. |
| typedef struct [ArkUI_SwiperIndicator](#arkui_swiperindicator) [ArkUI_SwiperIndicator](#arkui_swiperindicator) | Defines the navigation point indicator style of the **Swiper** component. |
| typedef struct [ArkUI_StyledString](#arkui_styledstring) [ArkUI_StyledString](#arkui_styledstring) | Defines a struct for the styled string object supported by the text component. |


### Enums

| Name | Description |
| -------- | -------- |
| [ArkUI_DragResult](#arkui_dragresult) { ARKUI_DRAG_RESULT_SUCCESSFUL, ARKUI_DRAG_RESULT_FAILED, ARKUI_DRAG_RESULT_CANCELED } | Defines an enum for drag results, which are set by the data receiver and transferred by the system to the drag source so that the drag source is aware of the data processing result of the receiver. |
| [ArkUI_DropProposal](#arkui_dropproposal) { ARKUI_DROP_PROPOSAL_COPY, ARKUI_DROP_PROPOSAL_MOVE } | Defines an enum for data processing modes used when data is dropped, which affects the display of the badge. |
| [ArkUI_PreDragStatus](#arkui_predragstatus) {<br>ARKUI_PRE_DRAG_STATUS_UNKNOWN = -1, ARKUI_PRE_DRAG_STATUS_ACTION_DETECTING, ARKUI_PRE_DRAG_STATUS_READY_TO_TRIGGER_DRAG, ARKUI_PRE_DRAG_STATUS_PREVIEW_LIFT_STARTED,<br>ARKUI_PRE_DRAG_STATUS_PREVIEW_LIFT_FINISHED, ARKUI_PRE_DRAG_STATUS_PREVIEW_LANDING_STARTED, ARKUI_PRE_DRAG_STATUS_PREVIEW_LANDING_FINISHED, ARKUI_PRE_DRAG_STATUS_CANCELED_BEFORE_DRAG<br>} | Defines an enum for interaction states prior to a drop and drop operation. |
| [ArkUI_DragPreviewScaleMode](#arkui_dragpreviewscalemode) { ARKUI_DRAG_PREVIEW_SCALE_AUTO, ARKUI_DRAG_PREVIEW_SCALE_DISABLED } | Defines an enum for drag preview scale modes. |
| [ArkUI_DragStatus](#arkui_dragstatus) { ArkUI_DRAG_STATUS_UNKNOWN, ArkUI_DRAG_STATUS_STARTED, ArkUI_DRAG_STATUS_ENDED } | Enumerates dragging states. |
| [ArkUI_DismissReason](#arkui_dismissreason) { DIALOG_DISMISS_BACK_PRESS = 0, DIALOG_DISMISS_TOUCH_OUTSIDE, DIALOG_DISMISS_CLOSE_BUTTON, DIALOG_DISMISS_SLIDE_DOWN } | Enumerates the actions for triggering closure of the dialog box. |
| [ArkUI_GestureEventActionType](#arkui_gestureeventactiontype) { GESTURE_EVENT_ACTION_ACCEPT = 0x01, GESTURE_EVENT_ACTION_UPDATE = 0x02, GESTURE_EVENT_ACTION_END = 0x04, GESTURE_EVENT_ACTION_CANCEL = 0x08 } | Enumerates gesture event types. |
| [ArkUI_GesturePriority](#arkui_gesturepriority) { NORMAL = 0, PRIORITY = 1, PARALLEL = 2 } | Enumerates gesture event modes. |
| [ArkUI_GroupGestureMode](#arkui_groupgesturemode) { SEQUENTIAL_GROUP = 0, PARALLEL_GROUP = 1, EXCLUSIVE_GROUP = 2 } | Enumerates gesture group modes. |
| [ArkUI_GestureDirection](#arkui_gesturedirection) {<br>GESTURE_DIRECTION_ALL = 0b1111, GESTURE_DIRECTION_HORIZONTAL = 0b0011, GESTURE_DIRECTION_VERTICAL = 0b1100, GESTURE_DIRECTION_LEFT = 0b0001,<br>GESTURE_DIRECTION_RIGHT = 0b0010, GESTURE_DIRECTION_UP = 0b0100, GESTURE_DIRECTION_DOWN = 0b1000, GESTURE_DIRECTION_NONE = 0<br>} | Enumerates gesture directions. |
| [ArkUI_GestureMask](#arkui_gesturemask) { NORMAL_GESTURE_MASK = 0, IGNORE_INTERNAL_GESTURE_MASK } | Enumerates gesture masking modes. |
| [ArkUI_GestureRecognizerType](#arkui_gesturerecognizertype) {<br>TAP_GESTURE = 0, LONG_PRESS_GESTURE, PAN_GESTURE, PINCH_GESTURE,<br>ROTATION_GESTURE, SWIPE_GESTURE, GROUP_GESTURE<br>} | Enumerates gesture recognizer types. |
| [ArkUI_GestureInterruptResult](#arkui_gestureinterruptresult) { GESTURE_INTERRUPT_RESULT_CONTINUE = 0, GESTURE_INTERRUPT_RESULT_REJECT } | Enumerates gesture interruption results. |
| [ArkUI_GestureRecognizerState](#arkui_gesturerecognizerstate) {<br>ARKUI_GESTURE_RECOGNIZER_STATE_REDAY = 0, ARKUI_GESTURE_RECOGNIZER_STATE_DETECTING = 1, ARKUI_GESTURE_RECOGNIZER_STATE_PENDING = 2, ARKUI_GESTURE_RECOGNIZER_STATE_BLOCKED = 3,<br>ARKUI_GESTURE_RECOGNIZER_STATE_SUCCESSFUL = 4, ARKUI_GESTURE_RECOGNIZER_STATE_FAILED = 5<br>} | Enumerates the gesture recognizer states. |
| [ArkUI_NativeAPIVariantKind](#arkui_nativeapivariantkind) { ARKUI_NATIVE_NODE, ARKUI_NATIVE_DIALOG, ARKUI_NATIVE_GESTURE, ARKUI_NATIVE_ANIMATE } | Defines the native API types. |
| [ArkUI_NodeType](#arkui_nodetype) {<br>ARKUI_NODE_CUSTOM = 0, ARKUI_NODE_TEXT = 1, ARKUI_NODE_SPAN = 2, ARKUI_NODE_IMAGE_SPAN = 3,<br>ARKUI_NODE_IMAGE = 4, ARKUI_NODE_TOGGLE = 5, ARKUI_NODE_LOADING_PROGRESS = 6, ARKUI_NODE_TEXT_INPUT = 7,<br>ARKUI_NODE_TEXT_AREA = 8, ARKUI_NODE_BUTTON = 9, ARKUI_NODE_PROGRESS = 10, ARKUI_NODE_CHECKBOX = 11,<br>ARKUI_NODE_XCOMPONENT = 12, ARKUI_NODE_DATE_PICKER = 13, ARKUI_NODE_TIME_PICKER = 14, ARKUI_NODE_TEXT_PICKER = 15,<br>ARKUI_NODE_CALENDAR_PICKER = 16, ARKUI_NODE_SLIDER = 17, ARKUI_NODE_RADIO = 18, ARKUI_NODE_IMAGE_ANIMATOR = 19,<br>ARKUI_NODE_STACK = MAX_NODE_SCOPE_NUM, ARKUI_NODE_SWIPER, ARKUI_NODE_SCROLL, ARKUI_NODE_LIST,<br>ARKUI_NODE_LIST_ITEM, ARKUI_NODE_LIST_ITEM_GROUP, ARKUI_NODE_COLUMN, ARKUI_NODE_ROW,<br>ARKUI_NODE_FLEX, ARKUI_NODE_REFRESH, ARKUI_NODE_WATER_FLOW, ARKUI_NODE_FLOW_ITEM,<br>ARKUI_NODE_RELATIVE_CONTAINER, ARKUI_NODE_GRID, ARKUI_NODE_GRID_ITEM, ARKUI_NODE_CUSTOM_SPAN<br>} | Enumerates ArkUI component types that can be created on the native side. |
| [ArkUI_NodeAttributeType](#arkui_nodeattributetype) {<br>NODE_WIDTH = 0, NODE_HEIGHT, NODE_BACKGROUND_COLOR, NODE_BACKGROUND_IMAGE,<br>NODE_PADDING, NODE_ID, NODE_ENABLED, NODE_MARGIN,<br>NODE_TRANSLATE, NODE_SCALE, NODE_ROTATE, NODE_BRIGHTNESS,<br>NODE_SATURATION, NODE_BLUR, NODE_LINEAR_GRADIENT, NODE_ALIGNMENT,<br>NODE_OPACITY, NODE_BORDER_WIDTH, NODE_BORDER_RADIUS, NODE_BORDER_COLOR,<br>NODE_BORDER_STYLE, NODE_Z_INDEX, NODE_VISIBILITY, NODE_CLIP,<br>NODE_CLIP_SHAPE, NODE_TRANSFORM, NODE_HIT_TEST_BEHAVIOR, NODE_POSITION,<br>NODE_SHADOW, NODE_CUSTOM_SHADOW, NODE_BACKGROUND_IMAGE_SIZE, NODE_BACKGROUND_IMAGE_SIZE_WITH_STYLE,<br>NODE_BACKGROUND_BLUR_STYLE, NODE_TRANSFORM_CENTER, NODE_OPACITY_TRANSITION, NODE_ROTATE_TRANSITION,<br>NODE_SCALE_TRANSITION, NODE_TRANSLATE_TRANSITION, NODE_MOVE_TRANSITION, NODE_FOCUSABLE,<br>NODE_DEFAULT_FOCUS, NODE_RESPONSE_REGION, NODE_OVERLAY, NODE_SWEEP_GRADIENT,<br>NODE_RADIAL_GRADIENT, NODE_MASK, NODE_BLEND_MODE, NODE_DIRECTION,<br>NODE_CONSTRAINT_SIZE, NODE_GRAY_SCALE, NODE_INVERT, NODE_SEPIA,<br>NODE_CONTRAST, NODE_FOREGROUND_COLOR, NODE_OFFSET, NODE_MARK_ANCHOR,<br>NODE_BACKGROUND_IMAGE_POSITION, NODE_ALIGN_RULES, NODE_ALIGN_SELF, NODE_FLEX_GROW,<br>NODE_FLEX_SHRINK, NODE_FLEX_BASIS, NODE_ACCESSIBILITY_GROUP, NODE_ACCESSIBILITY_TEXT,<br>NODE_ACCESSIBILITY_MODE, NODE_ACCESSIBILITY_DESCRIPTION, NODE_FOCUS_STATUS, NODE_ASPECT_RATIO,<br>NODE_LAYOUT_WEIGHT, NODE_DISPLAY_PRIORITY, NODE_OUTLINE_WIDTH, NODE_WIDTH_PERCENT,<br>NODE_HEIGHT_PERCENT, NODE_PADDING_PERCENT, NODE_MARGIN_PERCENT, NODE_GEOMETRY_TRANSITION,<br>NODE_RELATIVE_LAYOUT_CHAIN_MODE, NODE_RENDER_FIT, NODE_OUTLINE_COLOR, NODE_SIZE,<br>NODE_RENDER_GROUP, NODE_COLOR_BLEND, NODE_FOREGROUND_BLUR_STYLE, NODE_LAYOUT_RECT,<br>NODE_FOCUS_ON_TOUCH, NODE_BORDER_WIDTH_PERCENT, NODE_BORDER_RADIUS_PERCENT, NODE_ACCESSIBILITY_ID = 87,<br>NODE_ACCESSIBILITY_ACTIONS = 88, NODE_ACCESSIBILITY_ROLE = 89, NODE_ACCESSIBILITY_STATE = 90, NODE_ACCESSIBILITY_VALUE = 91,<br>NODE_EXPAND_SAFE_AREA = 92, NODE_VISIBLE_AREA_CHANGE_RATIO = 93, NODE_TRANSITION = 94, NODE_UNIQUE_ID = 95,<br>NODE_CLICK_DISTANCE = 96, NODE_TEXT_CONTENT = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_TEXT, NODE_FONT_COLOR, NODE_FONT_SIZE,<br>NODE_FONT_STYLE, NODE_FONT_WEIGHT, NODE_TEXT_LINE_HEIGHT, NODE_TEXT_DECORATION,<br>NODE_TEXT_CASE, NODE_TEXT_LETTER_SPACING, NODE_TEXT_MAX_LINES, NODE_TEXT_ALIGN,<br>NODE_TEXT_OVERFLOW, NODE_FONT_FAMILY, NODE_TEXT_COPY_OPTION, NODE_TEXT_BASELINE_OFFSET,<br>NODE_TEXT_TEXT_SHADOW, NODE_TEXT_MIN_FONT_SIZE, NODE_TEXT_MAX_FONT_SIZE, NODE_TEXT_FONT,<br>NODE_TEXT_HEIGHT_ADAPTIVE_POLICY, NODE_TEXT_INDENT, NODE_TEXT_WORD_BREAK, NODE_TEXT_ELLIPSIS_MODE,<br>NODE_TEXT_LINE_SPACING, NODE_FONT_FEATURE, NODE_TEXT_ENABLE_DATA_DETECTOR, NODE_TEXT_ENABLE_DATA_DETECTOR_CONFIG,<br>NODE_TEXT_SELECTED_BACKGROUND_COLOR, NODE_TEXT_CONTENT_WITH_STYLED_STRING, NODE_TEXT_HALF_LEADING = 1029, NODE_SPAN_CONTENT = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_SPAN,<br>NODE_SPAN_TEXT_BACKGROUND_STYLE, NODE_SPAN_BASELINE_OFFSET, NODE_IMAGE_SPAN_SRC = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_IMAGE_SPAN, NODE_IMAGE_SPAN_VERTICAL_ALIGNMENT,<br>NODE_IMAGE_SPAN_ALT, NODE_IMAGE_SPAN_BASELINE_OFFSET = 3003, NODE_IMAGE_SRC = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_IMAGE, NODE_IMAGE_OBJECT_FIT,<br>NODE_IMAGE_INTERPOLATION, NODE_IMAGE_OBJECT_REPEAT, NODE_IMAGE_COLOR_FILTER, NODE_IMAGE_AUTO_RESIZE,<br>NODE_IMAGE_ALT, NODE_IMAGE_DRAGGABLE, NODE_IMAGE_RENDER_MODE, NODE_IMAGE_FIT_ORIGINAL_SIZE,<br>NODE_IMAGE_FILL_COLOR, NODE_IMAGE_RESIZABLE, NODE_TOGGLE_SELECTED_COLOR = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_TOGGLE, NODE_TOGGLE_SWITCH_POINT_COLOR,<br>NODE_TOGGLE_VALUE, NODE_TOGGLE_UNSELECTED_COLOR, NODE_LOADING_PROGRESS_COLOR = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_LOADING_PROGRESS, NODE_LOADING_PROGRESS_ENABLE_LOADING,<br>NODE_TEXT_INPUT_PLACEHOLDER = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_TEXT_INPUT, NODE_TEXT_INPUT_TEXT, NODE_TEXT_INPUT_CARET_COLOR, NODE_TEXT_INPUT_CARET_STYLE,<br>NODE_TEXT_INPUT_SHOW_UNDERLINE, NODE_TEXT_INPUT_MAX_LENGTH, NODE_TEXT_INPUT_ENTER_KEY_TYPE, NODE_TEXT_INPUT_PLACEHOLDER_COLOR,<br>NODE_TEXT_INPUT_PLACEHOLDER_FONT, NODE_TEXT_INPUT_ENABLE_KEYBOARD_ON_FOCUS, NODE_TEXT_INPUT_TYPE, NODE_TEXT_INPUT_SELECTED_BACKGROUND_COLOR,<br>NODE_TEXT_INPUT_SHOW_PASSWORD_ICON, NODE_TEXT_INPUT_EDITING, NODE_TEXT_INPUT_CANCEL_BUTTON, NODE_TEXT_INPUT_TEXT_SELECTION,<br>NODE_TEXT_INPUT_UNDERLINE_COLOR, NODE_TEXT_INPUT_ENABLE_AUTO_FILL, NODE_TEXT_INPUT_CONTENT_TYPE, NODE_TEXT_INPUT_PASSWORD_RULES,<br>NODE_TEXT_INPUT_SELECT_ALL, NODE_TEXT_INPUT_INPUT_FILTER, NODE_TEXT_INPUT_STYLE, NODE_TEXT_INPUT_CARET_OFFSET,<br>NODE_TEXT_INPUT_CONTENT_RECT, NODE_TEXT_INPUT_CONTENT_LINE_COUNT, NODE_TEXT_INPUT_SELECTION_MENU_HIDDEN, NODE_TEXT_INPUT_BLUR_ON_SUBMIT,<br>NODE_TEXT_INPUT_CUSTOM_KEYBOARD, NODE_TEXT_INPUT_WORD_BREAK, NODE_TEXT_INPUT_NUMBER_OF_LINES, NODE_TEXT_INPUT_SHOW_KEYBOARD_ON_FOCUS,<br>NODE_TEXT_AREA_PLACEHOLDER = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_TEXT_AREA, NODE_TEXT_AREA_TEXT, NODE_TEXT_AREA_MAX_LENGTH, NODE_TEXT_AREA_PLACEHOLDER_COLOR,<br>NODE_TEXT_AREA_PLACEHOLDER_FONT, NODE_TEXT_AREA_CARET_COLOR, NODE_TEXT_AREA_EDITING, NODE_TEXT_AREA_TYPE,<br>NODE_TEXT_AREA_SHOW_COUNTER, NODE_TEXT_AREA_SELECTION_MENU_HIDDEN, NODE_TEXT_AREA_BLUR_ON_SUBMIT, NODE_TEXT_AREA_INPUT_FILTER,<br>NODE_TEXT_AREA_SELECTED_BACKGROUND_COLOR, NODE_TEXT_AREA_ENTER_KEY_TYPE, NODE_TEXT_AREA_ENABLE_KEYBOARD_ON_FOCUS, NODE_TEXT_AREA_CARET_OFFSET,<br>NODE_TEXT_AREA_CONTENT_RECT, NODE_TEXT_AREA_CONTENT_LINE_COUNT, NODE_TEXT_AREA_TEXT_SELECTION, NODE_TEXT_AREA_ENABLE_AUTO_FILL,<br>NODE_TEXT_AREA_CONTENT_TYPE, NODE_TEXT_AREA_NUMBER_OF_LINES, NODE_TEXT_AREA_SHOW_KEYBOARD_ON_FOCUS, NODE_BUTTON_LABEL = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_BUTTON,<br>NODE_BUTTON_TYPE, NODE_PROGRESS_VALUE = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_PROGRESS, NODE_PROGRESS_TOTAL, NODE_PROGRESS_COLOR,<br>NODE_PROGRESS_TYPE, NODE_CHECKBOX_SELECT = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_CHECKBOX, NODE_CHECKBOX_SELECT_COLOR, NODE_CHECKBOX_UNSELECT_COLOR,<br>NODE_CHECKBOX_MARK, NODE_CHECKBOX_SHAPE, NODE_XCOMPONENT_ID = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_XCOMPONENT, NODE_XCOMPONENT_TYPE,<br>NODE_XCOMPONENT_SURFACE_SIZE, NODE_DATE_PICKER_LUNAR = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_DATE_PICKER, NODE_DATE_PICKER_START, NODE_DATE_PICKER_END,<br>NODE_DATE_PICKER_SELECTED, NODE_DATE_PICKER_DISAPPEAR_TEXT_STYLE, NODE_DATE_PICKER_TEXT_STYLE, NODE_DATE_PICKER_SELECTED_TEXT_STYLE,<br>NODE_TIME_PICKER_SELECTED = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_TIME_PICKER, NODE_TIME_PICKER_USE_MILITARY_TIME, NODE_TIME_PICKER_DISAPPEAR_TEXT_STYLE, NODE_TIME_PICKER_TEXT_STYLE,<br>NODE_TIME_PICKER_SELECTED_TEXT_STYLE, NODE_TEXT_PICKER_OPTION_RANGE = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_TEXT_PICKER, NODE_TEXT_PICKER_OPTION_SELECTED, NODE_TEXT_PICKER_OPTION_VALUE,<br>NODE_TEXT_PICKER_DISAPPEAR_TEXT_STYLE, NODE_TEXT_PICKER_TEXT_STYLE, NODE_TEXT_PICKER_SELECTED_TEXT_STYLE, NODE_TEXT_PICKER_SELECTED_INDEX,<br>NODE_TEXT_PICKER_CAN_LOOP, NODE_TEXT_PICKER_DEFAULT_PICKER_ITEM_HEIGHT, NODE_CALENDAR_PICKER_HINT_RADIUS = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_CALENDAR_PICKER, NODE_CALENDAR_PICKER_SELECTED_DATE,<br>NODE_CALENDAR_PICKER_EDGE_ALIGNMENT, NODE_CALENDAR_PICKER_TEXT_STYLE, NODE_SLIDER_BLOCK_COLOR = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_SLIDER, NODE_SLIDER_TRACK_COLOR,<br>NODE_SLIDER_SELECTED_COLOR, NODE_SLIDER_SHOW_STEPS, NODE_SLIDER_BLOCK_STYLE, NODE_SLIDER_VALUE,<br>NODE_SLIDER_MIN_VALUE, NODE_SLIDER_MAX_VALUE, NODE_SLIDER_STEP, NODE_SLIDER_DIRECTION,<br>NODE_SLIDER_REVERSE, NODE_SLIDER_STYLE, NODE_SLIDER_TRACK_THICKNESS, NODE_RADIO_CHECKED = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_RADIO,<br>NODE_RADIO_STYLE, NODE_RADIO_VALUE, NODE_RADIO_GROUP, NODE_STACK_ALIGN_CONTENT = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_STACK,<br>NODE_SCROLL_BAR_DISPLAY_MODE = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_SCROLL, NODE_SCROLL_BAR_WIDTH, NODE_SCROLL_BAR_COLOR, NODE_SCROLL_SCROLL_DIRECTION,<br>NODE_SCROLL_EDGE_EFFECT, NODE_SCROLL_ENABLE_SCROLL_INTERACTION, NODE_SCROLL_FRICTION, NODE_SCROLL_SNAP,<br>NODE_SCROLL_NESTED_SCROLL, NODE_SCROLL_OFFSET, NODE_SCROLL_EDGE, NODE_SCROLL_ENABLE_PAGING,<br>NODE_SCROLL_PAGE, NODE_SCROLL_BY, NODE_SCROLL_FLING, NODE_SCROLL_FADING_EDGE,<br>NODE_LIST_DIRECTION = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_LIST, NODE_LIST_STICKY, NODE_LIST_SPACE, NODE_LIST_NODE_ADAPTER,<br>NODE_LIST_CACHED_COUNT, NODE_LIST_SCROLL_TO_INDEX, NODE_LIST_ALIGN_LIST_ITEM, NODE_LIST_CHILDREN_MAIN_SIZE = 1003007,<br>NODE_LIST_INITIAL_INDEX = 1003008, NODE_LIST_DIVIDER = 1003009, NODE_SWIPER_LOOP = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_SWIPER, NODE_SWIPER_AUTO_PLAY,<br>NODE_SWIPER_SHOW_INDICATOR, NODE_SWIPER_INTERVAL, NODE_SWIPER_VERTICAL, NODE_SWIPER_DURATION,<br>NODE_SWIPER_CURVE, NODE_SWIPER_ITEM_SPACE, NODE_SWIPER_INDEX, NODE_SWIPER_DISPLAY_COUNT,<br>NODE_SWIPER_DISABLE_SWIPE, NODE_SWIPER_SHOW_DISPLAY_ARROW, NODE_SWIPER_EDGE_EFFECT_MODE, NODE_SWIPER_NODE_ADAPTER,<br>NODE_SWIPER_CACHED_COUNT, NODE_SWIPER_PREV_MARGIN, NODE_SWIPER_NEXT_MARGIN, NODE_SWIPER_INDICATOR,<br>NODE_SWIPER_NESTED_SCROLL, NODE_SWIPER_SWIPE_TO_INDEX, NODE_SWIPER_INDICATOR_INTERACTIVE, NODE_LIST_ITEM_SWIPE_ACTION = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_LIST_ITEM,<br>NODE_LIST_ITEM_GROUP_SET_HEADER = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_LIST_ITEM_GROUP, NODE_LIST_ITEM_GROUP_SET_FOOTER, NODE_LIST_ITEM_GROUP_SET_DIVIDER, NODE_LIST_ITEM_GROUP_CHILDREN_MAIN_SIZE = 1005003,<br>NODE_COLUMN_ALIGN_ITEMS = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_COLUMN, NODE_COLUMN_JUSTIFY_CONTENT, NODE_ROW_ALIGN_ITEMS = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_ROW, NODE_ROW_JUSTIFY_CONTENT,<br>NODE_FLEX_OPTION = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_FLEX, NODE_REFRESH_REFRESHING = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_REFRESH, NODE_REFRESH_CONTENT, NODE_REFRESH_PULL_DOWN_RATIO = 1009002,<br>NODE_REFRESH_OFFSET = 1009003, NODE_REFRESH_PULL_TO_REFRESH = 1009004, NODE_WATER_FLOW_LAYOUT_DIRECTION = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_WATER_FLOW, NODE_WATER_FLOW_COLUMN_TEMPLATE,<br>NODE_WATER_FLOW_ROW_TEMPLATE, NODE_WATER_FLOW_COLUMN_GAP, NODE_WATER_FLOW_ROW_GAP, NODE_WATER_FLOW_SECTION_OPTION,<br>NODE_WATER_FLOW_NODE_ADAPTER, NODE_WATER_FLOW_CACHED_COUNT, NODE_WATER_FLOW_FOOTER, NODE_WATER_FLOW_SCROLL_TO_INDEX,<br>NODE_WATER_FLOW_ITEM_CONSTRAINT_SIZE, NODE_RELATIVE_CONTAINER_GUIDE_LINE = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_RELATIVE_CONTAINER, NODE_RELATIVE_CONTAINER_BARRIER, NODE_GRID_COLUMN_TEMPLATE = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_GRID,<br>NODE_GRID_ROW_TEMPLATE, NODE_GRID_COLUMN_GAP, NODE_GRID_ROW_GAP, NODE_GRID_NODE_ADAPTER,<br>NODE_GRID_CACHED_COUNT, NODE_IMAGE_ANIMATOR_IMAGES = ARKUI_NODE_IMAGE_ANIMATOR \* MAX_NODE_SCOPE_NUM, NODE_IMAGE_ANIMATOR_STATE, NODE_IMAGE_ANIMATOR_DURATION,<br>NODE_IMAGE_ANIMATOR_REVERSE, NODE_IMAGE_ANIMATOR_FIXED_SIZE, NODE_IMAGE_ANIMATOR_FILL_MODE, NODE_IMAGE_ANIMATOR_ITERATION<br>} | Defines the ArkUI style attributes that can be set on the native side. |
| [ArkUI_NodeEventType](#arkui_nodeeventtype) {<br>NODE_TOUCH_EVENT = 0, NODE_EVENT_ON_APPEAR, NODE_EVENT_ON_DISAPPEAR, NODE_EVENT_ON_AREA_CHANGE,<br>NODE_ON_FOCUS, NODE_ON_BLUR, NODE_ON_CLICK, NODE_ON_TOUCH_INTERCEPT,<br>NODE_EVENT_ON_VISIBLE_AREA_CHANGE, NODE_ON_HOVER, NODE_ON_MOUSE, NODE_EVENT_ON_ATTACH,<br>NODE_EVENT_ON_DETACH, NODE_ON_ACCESSIBILITY_ACTIONS = 13, NODE_ON_PRE_DRAG = 14, NODE_ON_DRAG_START = 15,<br>NODE_ON_DRAG_ENTER = 16, NODE_ON_DRAG_MOVE = 17, NODE_ON_DRAG_LEAVE = 18, NODE_ON_DROP = 19,<br>NODE_ON_DRAG_END = 20, NODE_TEXT_ON_DETECT_RESULT_UPDATE = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_TEXT, NODE_IMAGE_ON_COMPLETE = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_IMAGE, NODE_IMAGE_ON_ERROR,<br>NODE_IMAGE_ON_SVG_PLAY_FINISH, NODE_IMAGE_ON_DOWNLOAD_PROGRESS, NODE_TOGGLE_ON_CHANGE = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_TOGGLE, NODE_TEXT_INPUT_ON_CHANGE = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_TEXT_INPUT,<br>NODE_TEXT_INPUT_ON_SUBMIT, NODE_TEXT_INPUT_ON_CUT, NODE_TEXT_INPUT_ON_PASTE, NODE_TEXT_INPUT_ON_TEXT_SELECTION_CHANGE,<br>NODE_TEXT_INPUT_ON_EDIT_CHANGE, NODE_TEXT_INPUT_ON_INPUT_FILTER_ERROR, NODE_TEXT_INPUT_ON_CONTENT_SCROLL, NODE_TEXT_INPUT_ON_CONTENT_SIZE_CHANGE,<br>NODE_TEXT_INPUT_ON_WILL_INSERT = 7009, NODE_TEXT_INPUT_ON_DID_INSERT = 7010, NODE_TEXT_INPUT_ON_WILL_DELETE = 7011, NODE_TEXT_INPUT_ON_DID_DELETE = 7012,<br>NODE_TEXT_AREA_ON_CHANGE = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_TEXT_AREA, NODE_TEXT_AREA_ON_PASTE, NODE_TEXT_AREA_ON_TEXT_SELECTION_CHANGE, NODE_TEXT_AREA_ON_EDIT_CHANGE,<br>NODE_TEXT_AREA_ON_SUBMIT, NODE_TEXT_AREA_ON_INPUT_FILTER_ERROR, NODE_TEXT_AREA_ON_CONTENT_SCROLL, NODE_TEXT_AREA_ON_CONTENT_SIZE_CHANGE,<br>NODE_TEXT_AREA_ON_WILL_INSERT = 8008, NODE_TEXT_AREA_ON_DID_INSERT = 8009, NODE_TEXT_AREA_ON_WILL_DELETE = 8010, NODE_TEXT_AREA_ON_DID_DELETE = 8011,<br>NODE_CHECKBOX_EVENT_ON_CHANGE = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_CHECKBOX, NODE_DATE_PICKER_EVENT_ON_DATE_CHANGE = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_DATE_PICKER, NODE_TIME_PICKER_EVENT_ON_CHANGE = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_TIME_PICKER, NODE_TEXT_PICKER_EVENT_ON_CHANGE = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_TEXT_PICKER,<br>NODE_CALENDAR_PICKER_EVENT_ON_CHANGE = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_CALENDAR_PICKER, NODE_SLIDER_EVENT_ON_CHANGE = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_SLIDER, NODE_RADIO_EVENT_ON_CHANGE = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_RADIO, NODE_IMAGE_ANIMATOR_EVENT_ON_START = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_IMAGE_ANIMATOR,<br>NODE_IMAGE_ANIMATOR_EVENT_ON_PAUSE, NODE_IMAGE_ANIMATOR_EVENT_ON_REPEAT, NODE_IMAGE_ANIMATOR_EVENT_ON_CANCEL, NODE_IMAGE_ANIMATOR_EVENT_ON_FINISH,<br>NODE_SWIPER_EVENT_ON_CHANGE = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_SWIPER, NODE_SWIPER_EVENT_ON_ANIMATION_START, NODE_SWIPER_EVENT_ON_ANIMATION_END, NODE_SWIPER_EVENT_ON_GESTURE_SWIPE,<br>NODE_SWIPER_EVENT_ON_CONTENT_DID_SCROLL, NODE_SCROLL_EVENT_ON_SCROLL = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_SCROLL, NODE_SCROLL_EVENT_ON_SCROLL_FRAME_BEGIN, NODE_SCROLL_EVENT_ON_WILL_SCROLL,<br>NODE_SCROLL_EVENT_ON_DID_SCROLL, NODE_SCROLL_EVENT_ON_SCROLL_START, NODE_SCROLL_EVENT_ON_SCROLL_STOP, NODE_SCROLL_EVENT_ON_SCROLL_EDGE,<br>NODE_SCROLL_EVENT_ON_REACH_START, NODE_SCROLL_EVENT_ON_REACH_END, NODE_LIST_ON_SCROLL_INDEX = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_LIST, NODE_LIST_ON_WILL_SCROLL,<br>NODE_LIST_ON_DID_SCROLL, NODE_REFRESH_STATE_CHANGE = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_REFRESH, NODE_REFRESH_ON_REFRESH, NODE_REFRESH_ON_OFFSET_CHANGE,<br>NODE_ON_WILL_SCROLL = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_WATER_FLOW, NODE_WATER_FLOW_ON_DID_SCROLL, NODE_WATER_FLOW_ON_SCROLL_INDEX<br>} | Enumerates the event types supported by the NativeNode component. |
| [ArkUI_NodeDirtyFlag](#arkui_nodedirtyflag) { NODE_NEED_MEASURE = 1, NODE_NEED_LAYOUT, NODE_NEED_RENDER } | Enumerates the dirty area flags passed in the **::markDirty** API. |
| [ArkUI_NodeCustomEventType](#arkui_nodecustomeventtype) {<br>ARKUI_NODE_CUSTOM_EVENT_ON_MEASURE = 1 &lt;&lt; 0, ARKUI_NODE_CUSTOM_EVENT_ON_LAYOUT = 1 &lt;&lt; 1, ARKUI_NODE_CUSTOM_EVENT_ON_DRAW = 1 &lt;&lt; 2, ARKUI_NODE_CUSTOM_EVENT_ON_FOREGROUND_DRAW = 1 &lt;&lt; 3,<br>ARKUI_NODE_CUSTOM_EVENT_ON_OVERLAY_DRAW = 1 &lt;&lt; 4<br>} | Enumerates the custom component event types. |
| [ArkUI_NodeAdapterEventType](#arkui_nodeadaptereventtype) {<br>NODE_ADAPTER_EVENT_WILL_ATTACH_TO_NODE = 1, NODE_ADAPTER_EVENT_WILL_DETACH_FROM_NODE = 2, NODE_ADAPTER_EVENT_ON_GET_NODE_ID = 3, NODE_ADAPTER_EVENT_ON_ADD_NODE_TO_ADAPTER = 4,<br>NODE_ADAPTER_EVENT_ON_REMOVE_NODE_FROM_ADAPTER = 5<br>} | Enumerates node adapter events. |
| [ArkUI_NodeContentEventType](#arkui_nodecontenteventtype) { NODE_CONTENT_EVENT_ON_ATTACH_TO_WINDOW = 0, NODE_CONTENT_EVENT_ON_DETACH_FROM_WINDOW = 1 } | Defines the NodeContent event type. |
| [ArkUI_Alignment](#arkui_alignment) {<br>ARKUI_ALIGNMENT_TOP_START = 0, ARKUI_ALIGNMENT_TOP, ARKUI_ALIGNMENT_TOP_END, ARKUI_ALIGNMENT_START,<br>ARKUI_ALIGNMENT_CENTER, ARKUI_ALIGNMENT_END, ARKUI_ALIGNMENT_BOTTOM_START, ARKUI_ALIGNMENT_BOTTOM,<br>ARKUI_ALIGNMENT_BOTTOM_END<br>} | Enumerates the alignment modes. |
| [ArkUI_ImageRepeat](#arkui_imagerepeat) { ARKUI_IMAGE_REPEAT_NONE = 0, ARKUI_IMAGE_REPEAT_X, ARKUI_IMAGE_REPEAT_Y, ARKUI_IMAGE_REPEAT_XY } | Enumerates the image repeat patterns. |
| [ArkUI_FontStyle](#arkui_fontstyle) { ARKUI_FONT_STYLE_NORMAL = 0, ARKUI_FONT_STYLE_ITALIC } | Enumerates the font styles. |
| [ArkUI_FontWeight](#arkui_fontweight) {<br>ARKUI_FONT_WEIGHT_W100 = 0, ARKUI_FONT_WEIGHT_W200, ARKUI_FONT_WEIGHT_W300, ARKUI_FONT_WEIGHT_W400,<br>ARKUI_FONT_WEIGHT_W500, ARKUI_FONT_WEIGHT_W600, ARKUI_FONT_WEIGHT_W700, ARKUI_FONT_WEIGHT_W800,<br>ARKUI_FONT_WEIGHT_W900, ARKUI_FONT_WEIGHT_BOLD, ARKUI_FONT_WEIGHT_NORMAL, ARKUI_FONT_WEIGHT_BOLDER,<br>ARKUI_FONT_WEIGHT_LIGHTER, ARKUI_FONT_WEIGHT_MEDIUM, ARKUI_FONT_WEIGHT_REGULAR<br>} | Enumerates the font weights. |
| [ArkUI_TextAlignment](#arkui_textalignment) { ARKUI_TEXT_ALIGNMENT_START = 0, ARKUI_TEXT_ALIGNMENT_CENTER, ARKUI_TEXT_ALIGNMENT_END, ARKUI_TEXT_ALIGNMENT_JUSTIFY } | Enumerates the text alignment mode. |
| [ArkUI_EnterKeyType](#arkui_enterkeytype) {<br>ARKUI_ENTER_KEY_TYPE_GO = 2, ARKUI_ENTER_KEY_TYPE_SEARCH = 3, ARKUI_ENTER_KEY_TYPE_SEND, ARKUI_ENTER_KEY_TYPE_NEXT,<br>ARKUI_ENTER_KEY_TYPE_DONE, ARKUI_ENTER_KEY_TYPE_PREVIOUS, ARKUI_ENTER_KEY_TYPE_NEW_LINE<br>} | Enumerates the types of the Enter key for a single-line text box. |
| [ArkUI_TextInputType](#arkui_textinputtype) {<br>ARKUI_TEXTINPUT_TYPE_NORMAL = 0, ARKUI_TEXTINPUT_TYPE_NUMBER = 2, ARKUI_TEXTINPUT_TYPE_PHONE_NUMBER = 3, ARKUI_TEXTINPUT_TYPE_EMAIL = 5,<br>ARKUI_TEXTINPUT_TYPE_PASSWORD = 7, ARKUI_TEXTINPUT_TYPE_NUMBER_PASSWORD = 8, ARKUI_TEXTINPUT_TYPE_SCREEN_LOCK_PASSWORD = 9, ARKUI_TEXTINPUT_TYPE_USER_NAME = 10,<br>ARKUI_TEXTINPUT_TYPE_NEW_PASSWORD = 11, ARKUI_TEXTINPUT_TYPE_NUMBER_DECIMAL = 12<br>} | Enumerates the text input types. |
| [ArkUI_TextAreaType](#arkui_textareatype) { ARKUI_TEXTAREA_TYPE_NORMAL = 0, ARKUI_TEXTAREA_TYPE_NUMBER = 2, ARKUI_TEXTAREA_TYPE_PHONE_NUMBER = 3, ARKUI_TEXTAREA_TYPE_EMAIL = 5 } | Enumerates the text box types. |
| [ArkUI_CancelButtonStyle](#arkui_cancelbuttonstyle) { ARKUI_CANCELBUTTON_STYLE_CONSTANT = 0, ARKUI_CANCELBUTTON_STYLE_INVISIBLE, ARKUI_CANCELBUTTON_STYLE_INPUT } | Enumerates the styles of the Cancel button. |
| [ArkUI_XComponentType](#arkui_xcomponenttype) { ARKUI_XCOMPONENT_TYPE_SURFACE = 0, ARKUI_XCOMPONENT_TYPE_TEXTURE = 2 } | Enumerates the types of the XComponent type. |
| [ArkUI_ProgressType](#arkui_progresstype) {<br>ARKUI_PROGRESS_TYPE_LINEAR = 0, ARKUI_PROGRESS_TYPE_RING, ARKUI_PROGRESS_TYPE_ECLIPSE, ARKUI_PROGRESS_TYPE_SCALE_RING,<br>ARKUI_PROGRESS_TYPE_CAPSULE<br>} | Enumerates the styles of the progress indicator. |
| [ArkUI_TextDecorationType](#arkui_textdecorationtype) { ARKUI_TEXT_DECORATION_TYPE_NONE = 0, ARKUI_TEXT_DECORATION_TYPE_UNDERLINE, ARKUI_TEXT_DECORATION_TYPE_OVERLINE, ARKUI_TEXT_DECORATION_TYPE_LINE_THROUGH } | Enumerates the text decoration types. |
| [ArkUI_TextDecorationStyle](#arkui_textdecorationstyle) {<br>ARKUI_TEXT_DECORATION_STYLE_SOLID = 0, ARKUI_TEXT_DECORATION_STYLE_DOUBLE, ARKUI_TEXT_DECORATION_STYLE_DOTTED, ARKUI_TEXT_DECORATION_STYLE_DASHED,<br>ARKUI_TEXT_DECORATION_STYLE_WAVY<br>} | Enumerates the text decoration styles. |
| [ArkUI_TextCase](#arkui_textcase) { ARKUI_TEXT_CASE_NORMAL = 0, ARKUI_TEXT_CASE_LOWER, ARKUI_TEXT_CASE_UPPER } | Enumerates the text cases. |
| [ArkUI_CopyOptions](#arkui_copyoptions) { ARKUI_COPY_OPTIONS_NONE = 0, ARKUI_COPY_OPTIONS_IN_APP, ARKUI_COPY_OPTIONS_LOCAL_DEVICE, ARKUI_COPY_OPTIONS_CROSS_DEVICE } | Enumerates the text copy and paste modes. |
| [ArkUI_ShadowType](#arkui_shadowtype) { ARKUI_SHADOW_TYPE_COLOR = 0, ARKUI_SHADOW_TYPE_BLUR } | Enumerates the shadow types. |
| [ArkUI_TextPickerRangeType](#arkui_textpickerrangetype) { ARKUI_TEXTPICKER_RANGETYPE_SINGLE = 0, ARKUI_TEXTPICKER_RANGETYPE_MULTI, ARKUI_TEXTPICKER_RANGETYPE_RANGE_CONTENT, ARKUI_TEXTPICKER_RANGETYPE_CASCADE_RANGE_CONTENT } | Enumerates the types of the text picker. |
| [ArkUI_AccessibilityCheckedState](#arkui_accessibilitycheckedstate) { ARKUI_ACCESSIBILITY_UNCHECKED = 0, ARKUI_ACCESSIBILITY_CHECKED } | Enumerates the accessibility check box states. |
| [ArkUI_AccessibilityActionType](#arkui_accessibilityactiontype) {<br>ARKUI_ACCESSIBILITY_ACTION_CLICK = 1 &lt;&lt; 0, ARKUI_ACCESSIBILITY_ACTION_LONG_CLICK = 1 &lt;&lt; 1, ARKUI_ACCESSIBILITY_ACTION_CUT = 1 &lt;&lt; 2, ARKUI_ACCESSIBILITY_ACTION_COPY = 1 &lt;&lt; 3,<br>ARKUI_ACCESSIBILITY_ACTION_PASTE = 1 &lt;&lt; 4<br>} | Defines an enum for the accessibility action types. |
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
| [ArkUI_SwiperNestedScrollMode](#arkui_swipernestedscrollmode) { ARKUI_SWIPER_NESTED_SRCOLL_SELF_ONLY = 0, ARKUI_SWIPER_NESTED_SRCOLL_SELF_FIRST } | Enumerates the nested scrolling mode of the **Swiper** component and its parent container. |
| [ArkUI_AccessibilityMode](#arkui_accessibilitymode) { ARKUI_ACCESSIBILITY_MODE_AUTO = 0, ARKUI_ACCESSIBILITY_MODE_ENABLED, ARKUI_ACCESSIBILITY_MODE_DISABLED, ARKUI_ACCESSIBILITY_MODE_DISABLED_FOR_DESCENDANTS } | Enumerates the accessibility modes. |
| [ArkUI_TextCopyOptions](#arkui_textcopyoptions) { ARKUI_TEXT_COPY_OPTIONS_NONE = 0, ARKUI_TEXT_COPY_OPTIONS_IN_APP, ARKUI_TEXT_COPY_OPTIONS_LOCAL_DEVICE, ARKUI_TEXT_COPY_OPTIONS_CROSS_DEVICE } | Enumerates copy options, which define whether copy and paste is allowed for text content. |
| [ArkUI_TextHeightAdaptivePolicy](#arkui_textheightadaptivepolicy) { ARKUI_TEXT_HEIGHT_ADAPTIVE_POLICY_MAX_LINES_FIRST = 0, ARKUI_TEXT_HEIGHT_ADAPTIVE_POLICY_MIN_FONT_SIZE_FIRST, ARKUI_TEXT_HEIGHT_ADAPTIVE_POLICY_LAYOUT_CONSTRAINT_FIRST } | Defines how the adaptive height is determined for the text. |
| [ArkUI_ScrollNestedMode](#arkui_scrollnestedmode) { ARKUI_SCROLL_NESTED_MODE_SELF_ONLY = 0, ARKUI_SCROLL_NESTED_MODE_SELF_FIRST, ARKUI_SCROLL_NESTED_MODE_PARENT_FIRST, ARKUI_SCROLL_NESTED_MODE_PARALLEL } | Enumerates the nested scrolling modes. |
| [ArkUI_ScrollEdge](#arkui_scrolledge) { ARKUI_SCROLL_EDGE_TOP = 0, ARKUI_SCROLL_EDGE_BOTTOM, ARKUI_SCROLL_EDGE_START, ARKUI_SCROLL_EDGE_END } | Defines the edge to which the component scrolls. |
| [ArkUI_ScrollAlignment](#arkui_scrollalignment) { ARKUI_SCROLL_ALIGNMENT_START = 0, ARKUI_SCROLL_ALIGNMENT_CENTER, ARKUI_SCROLL_ALIGNMENT_END, ARKUI_SCROLL_ALIGNMENT_AUTO } | Defines how the list item to scroll to is aligned with the container. |
| [ArkUI_ScrollState](#arkui_scrollstate) { ARKUI_SCROLL_STATE_IDLE = 0, ARKUI_SCROLL_STATE_SCROLL, ARKUI_SCROLL_STATE_FLING } | Enumerates the scrolling states. |
| [ArkUI_SliderBlockStyle](#arkui_sliderblockstyle) { ARKUI_SLIDER_BLOCK_STYLE_DEFAULT = 0, ARKUI_SLIDER_BLOCK_STYLE_IMAGE, ARKUI_SLIDER_BLOCK_STYLE_SHAPE } | Enumerates the styles of the slider in the block direction. |
| [ArkUI_SliderDirection](#arkui_sliderdirection) { ARKUI_SLIDER_DIRECTION_VERTICAL = 0, ARKUI_SLIDER_DIRECTION_HORIZONTAL } | Enumerates the scroll directions of the slider. |
| [ArkUI_SliderStyle](#arkui_sliderstyle) { ARKUI_SLIDER_STYLE_OUT_SET = 0, ARKUI_SLIDER_STYLE_IN_SET, ARKUI_SLIDER_STYLE_NONE } | Enumerates the slider styles. |
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
| [ArkUI_ObjectFit](#arkui_objectfit) {<br>ARKUI_OBJECT_FIT_CONTAIN = 0, ARKUI_OBJECT_FIT_COVER, ARKUI_OBJECT_FIT_AUTO, ARKUI_OBJECT_FIT_FILL,<br>ARKUI_OBJECT_FIT_SCALE_DOWN, ARKUI_OBJECT_FIT_NONE, ARKUI_OBJECT_FIT_NONE_AND_ALIGN_TOP_START, ARKUI_OBJECT_FIT_NONE_AND_ALIGN_TOP,<br>ARKUI_OBJECT_FIT_NONE_AND_ALIGN_TOP_END, ARKUI_OBJECT_FIT_NONE_AND_ALIGN_START, ARKUI_OBJECT_FIT_NONE_AND_ALIGN_CENTER, ARKUI_OBJECT_FIT_NONE_AND_ALIGN_END,<br>ARKUI_OBJECT_FIT_NONE_AND_ALIGN_BOTTOM_START, ARKUI_OBJECT_FIT_NONE_AND_ALIGN_BOTTOM, ARKUI_OBJECT_FIT_NONE_AND_ALIGN_BOTTOM_END<br>} | Enumerates the image filling effects.  |
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
| [ArkUI_SwiperIndicatorType](#arkui_swiperindicatortype) { ARKUI_SWIPER_INDICATOR_TYPE_DOT, ARKUI_SWIPER_INDICATOR_TYPE_DIGIT } | Enumerates the navigation point indicator types of the **Swiper** component. |
| [ArkUI_AnimationDirection](#arkui_animationdirection) { ARKUI_ANIMATION_DIRECTION_NORMAL = 0, ARKUI_ANIMATION_DIRECTION_REVERSE, ARKUI_ANIMATION_DIRECTION_ALTERNATE, ARKUI_ANIMATION_DIRECTION_ALTERNATE_REVERSE } | Enumerates the animation playback modes. |
| [ArkUI_AnimationFill](#arkui_animationfill) { ARKUI_ANIMATION_FILL_NONE = 0, ARKUI_ANIMATION_FILL_FORWARDS, ARKUI_ANIMATION_FILL_BACKWARDS, ARKUI_ANIMATION_FILL_BOTH } | Enumerates the state of the animated target after the animation is executed. |
| [ArkUI_SwiperDisplayModeType](#arkui_swiperdisplaymodetype) { ARKUI_SWIPER_DISPLAY_MODE_STRETCH, ARKUI_SWIPER_DISPLAY_MODE_AUTO_LINEAR } | Enumerates the modes in which elements are displayed along the main axis of the **Swiper** component. |
| [ArkUI_ListItemSwipeActionState](#arkui_listitemswipeactionstate) { ARKUI_LIST_ITEM_SWIPE_ACTION_STATE_COLLAPSED = 0, ARKUI_LIST_ITEM_SWIPE_ACTION_STATE_EXPANDED, ARKUI_LIST_ITEM_SWIPE_ACTION_STATE_ACTIONING } | Enumerates the swipe action item states of list items. |
| [ArkUI_ListItemSwipeEdgeEffect](#arkui_listitemswipeedgeeffect) { ARKUI_LIST_ITEM_SWIPE_EDGE_EFFECT_SPRING = 0, ARKUI_LIST_ITEM_SWIPE_EDGE_EFFECT_NONE } | Enumerates the swipe action item edge effects of list items. |
| [ArkUI_AnimationStatus](#arkui_animationstatus) { ARKUI_ANIMATION_STATUS_INITIAL, ARKUI_ANIMATION_STATUS_RUNNING, ARKUI_ANIMATION_STATUS_PAUSED, ARKUI_ANIMATION_STATUS_STOPPED } | Enumerates the playback states of the frame-by-frame animation. |
| [ArkUI_AnimationFillMode](#arkui_animationfillmode) { ARKUI_ANIMATION_FILL_MODE_NONE, ARKUI_ANIMATION_FILL_MODE_FORWARDS, ARKUI_ANIMATION_FILL_MODE_BACKWARDS, ARKUI_ANIMATION_FILL_MODE_BOTH } | Enumerates the states before and after execution of the frame-by-frame animation. |
| [ArkUI_ErrorCode](#arkui_errorcode) {<br>ARKUI_ERROR_CODE_NO_ERROR = 0, ARKUI_ERROR_CODE_PARAM_INVALID = 401, ARKUI_ERROR_CODE_ATTRIBUTE_OR_EVENT_NOT_SUPPORTED = 106102, ARKUI_ERROR_CODE_NOT_SUPPROTED_FOR_ARKTS_NODE = 106103,<br>ARKUI_ERROR_CODE_NODE_ADAPTER_NONE_HOST = 106104, ARKUI_ERROR_CODE_NODE_ADAPTER_EXIST_IN_HOST = 106105, ARKUI_ERROR_CODE_NODE_ADAPTER_CHILD_NODE_EXIST = 106106, ARKUI_ERROR_CODE_NODE_EVENT_PARAM_INDEX_OUT_OF_RANGE = 106107,<br>ARKUI_ERROR_CODE_NODE_EVENT_PARAM_INVALID = 106108, ARKUI_ERROR_CODE_NODE_EVENT_NO_RETURN = 106109, ARKUI_ERROR_CODE_NODE_INDEX_INVALID = 106200, ARKUI_ERROR_CODE_GET_INFO_FAILED = 106201,<br>ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR = 106202<br>} | Defines an enum for the error codes. |
| [ArkUI_ScrollSource](#arkui_scrollsource) {<br>ARKUI_SCROLL_SOURCE_DRAG = 0, ARKUI_SCROLL_SOURCE_FLING, ARKUI_SCROLL_SOURCE_EDGE_EFFECT, ARKUI_SCROLL_SOURCE_OTHER_USER_INPUT,<br>ARKUI_SCROLL_SOURCE_SCROLL_BAR, ARKUI_SCROLL_SOURCE_SCROLL_BAR_FLING, ARKUI_SCROLL_SOURCE_SCROLLER, ARKUI_SCROLL_SOURCE_ANIMATION<br>} | Enumerates the scrolling sources. |
| [ArkUI_SafeAreaType](#arkui_safeareatype) { ARKUI_SAFE_AREA_TYPE_SYSTEM = 1, ARKUI_SAFE_AREA_TYPE_CUTOUT = 1 &lt;&lt; 1, ARKUI_SAFE_AREA_TYPE_KEYBOARD = 1 &lt;&lt; 2 } | Enumerates the types of expanded safe areas. |
| [ArkUI_SafeAreaEdge](#arkui_safeareaedge) { ARKUI_SAFE_AREA_EDGE_TOP = 1, ARKUI_SAFE_AREA_EDGE_BOTTOM = 1 &lt;&lt; 1, ARKUI_SAFE_AREA_EDGE_START = 1 &lt;&lt; 2, ARKUI_SAFE_AREA_EDGE_END = 1 &lt;&lt; 3 } | Enumerates the edges for expanding the safe area. |
| [ArkUI_NavDestinationState](#arkui_navdestinationstate) {<br>ARKUI_NAV_DESTINATION_STATE_ON_SHOW = 0, ARKUI_NAV_DESTINATION_STATE_ON_HIDE = 1, ARKUI_NAV_DESTINATION_STATE_ON_APPEAR = 2, ARKUI_NAV_DESTINATION_STATE_ON_DISAPPEAR = 3,<br>ARKUI_NAV_DESTINATION_STATE_ON_WILL_SHOW = 4, ARKUI_NAV_DESTINATION_STATE_ON_WILL_HIDE = 5, ARKUI_NAV_DESTINATION_STATE_ON_WILL_APPEAR = 6, ARKUI_NAV_DESTINATION_STATE_ON_WILL_DISAPPEAR = 7,<br>ARKUI_NAV_DESTINATION_STATE_ON_BACK_PRESS = 100<br>} | Defines an enum for the **NavDestination** component states. |
| [ArkUI_RouterPageState](#arkui_routerpagestate) {<br>ARKUI_ROUTER_PAGE_STATE_ON_WILL_APPEAR = 0, ARKUI_ROUTER_PAGE_STATE_ON_WILL_DISAPPEAR = 1, ARKUI_ROUTER_PAGE_STATE_ON_SHOW = 2, ARKUI_ROUTER_PAGE_STATE_ON_HIDE = 3,<br>ARKUI_ROUTER_PAGE_STATE_ON_BACK_PRESS = 4<br>} | Enumerates the states of a page during routing. |


### Functions

| Name | Description |
| -------- | -------- |
| [ArkUI_DragEvent](#arkui_dragevent) \* [OH_ArkUI_NodeEvent_GetDragEvent](#oh_arkui_nodeevent_getdragevent) ([ArkUI_NodeEvent](#arkui_nodeevent-12) \*nodeEvent) | Obtains a **DragEvent** object from the specified **NodeEvent** object. |
| [ArkUI_PreDragStatus](#arkui_predragstatus) [OH_ArkUI_NodeEvent_GetPreDragStatus](#oh_arkui_nodeevent_getpredragstatus) ([ArkUI_NodeEvent](#arkui_nodeevent-12) \*nodeEvent) | Obtains the state prior to a drop and drop operation. |
| int32_t [OH_ArkUI_DragEvent_DisableDefaultDropAnimation](#oh_arkui_dragevent_disabledefaultdropanimation) ([ArkUI_DragEvent](#arkui_dragevent) \*event, bool disable) | Sets whether to disable the default drop animation, which is enabled by default. Use this API to apply a custom drop animation. |
| int32_t [OH_ArkUI_DragEvent_SetSuggestedDropOperation](#oh_arkui_dragevent_setsuggesteddropoperation) ([ArkUI_DragEvent](#arkui_dragevent) \*event, [ArkUI_DropProposal](#arkui_dropproposal) proposal) | Sets the data processing mode. |
| int32_t [OH_ArkUI_DragEvent_SetDragResult](#oh_arkui_dragevent_setdragresult) ([ArkUI_DragEvent](#arkui_dragevent) \*event, [ArkUI_DragResult](#arkui_dragresult) result) | Sets the result for a drag event. |
| int32_t [OH_ArkUI_DragEvent_SetData](#oh_arkui_dragevent_setdata) ([ArkUI_DragEvent](#arkui_dragevent) \*event, [OH_UdmfData](#oh_udmfdata) \*data) | Sets drag data for a drag event. |
| int32_t [OH_ArkUI_DragEvent_GetUdmfData](#oh_arkui_dragevent_getudmfdata) ([ArkUI_DragEvent](#arkui_dragevent) \*event, [OH_UdmfData](#oh_udmfdata) \*data) | Obtains the default drag data from a drag event. |
| int32_t [OH_ArkUI_DragEvent_GetDataTypesCount](#oh_arkui_dragevent_getdatatypescount) ([ArkUI_DragEvent](#arkui_dragevent) \*event, int32_t \*count) | Obtains the number of drag data types from a drag event. |
| int32_t [OH_ArkUI_DragEvent_GetDataTypes](#oh_arkui_dragevent_getdatatypes) ([ArkUI_DragEvent](#arkui_dragevent) \*event, char \*\*result[], int32_t length) | Obtains the type list of drag data types from a drag event. |
| int32_t [OH_ArkUI_DragEvent_GetDragResult](#oh_arkui_dragevent_getdragresult) ([ArkUI_DragEvent](#arkui_dragevent) \*event, [ArkUI_DragResult](#arkui_dragresult) \*result) | Obtains the drag and drop result from the drag event. |
| float [OH_ArkUI_DragEvent_GetPreviewTouchPointX](#oh_arkui_dragevent_getpreviewtouchpointx) ([ArkUI_DragEvent](#arkui_dragevent) \*event) | Obtains the X coordinate of the touch point for a drag preview from a drag event. |
| float [OH_ArkUI_DragEvent_GetPreviewTouchPointY](#oh_arkui_dragevent_getpreviewtouchpointy) ([ArkUI_DragEvent](#arkui_dragevent) \*event) | Obtains the Y coordinate of the touch point for a drag preview from a drag event. |
| float [OH_ArkUI_DragEvent_GetPreviewRectWidth](#oh_arkui_dragevent_getpreviewrectwidth) ([ArkUI_DragEvent](#arkui_dragevent) \*event) | Obtains the width of a drag preview from a drag event. |
| float [OH_ArkUI_DragEvent_GetPreviewRectHeight](#oh_arkui_dragevent_getpreviewrectheight) ([ArkUI_DragEvent](#arkui_dragevent) \*event) | Obtains the height of a drag preview from a drag event. |
| float [OH_ArkUI_DragEvent_GetTouchPointXToWindow](#oh_arkui_dragevent_gettouchpointxtowindow) ([ArkUI_DragEvent](#arkui_dragevent) \*event) | Obtains the X coordinate of the touch point relative to the window from a drag event. |
| float [OH_ArkUI_DragEvent_GetTouchPointYToWindow](#oh_arkui_dragevent_gettouchpointytowindow) ([ArkUI_DragEvent](#arkui_dragevent) \*event) | Obtains the Y coordinate of the touch point relative to the window from a drag event. |
| float [OH_ArkUI_DragEvent_GetTouchPointXToDisplay](#oh_arkui_dragevent_gettouchpointxtodisplay) ([ArkUI_DragEvent](#arkui_dragevent) \*event) | Obtains the X coordinate of the touch point relative to the display from a drag event. |
| float [OH_ArkUI_DragEvent_GetTouchPointYToDisplay](#oh_arkui_dragevent_gettouchpointytodisplay) ([ArkUI_DragEvent](#arkui_dragevent) \*event) | Obtains the Y coordinate of the touch point relative to the display from a drag event. |
| float [OH_ArkUI_DragEvent_GetVelocityX](#oh_arkui_dragevent_getvelocityx) ([ArkUI_DragEvent](#arkui_dragevent) \*event) | Obtains the dragging velocity along the x-axis. |
| float [OH_ArkUI_DragEvent_GetVelocityY](#oh_arkui_dragevent_getvelocityy) ([ArkUI_DragEvent](#arkui_dragevent) \*event) | Obtains the dragging velocity along the y-axis. |
| float [OH_ArkUI_DragEvent_GetVelocity](#oh_arkui_dragevent_getvelocity) ([ArkUI_DragEvent](#arkui_dragevent) \*event) | Obtains the dragging velocity along the main axis. |
| int32_t [OH_ArkUI_DragEvent_GetModifierKeyStates](#oh_arkui_dragevent_getmodifierkeystates) ([ArkUI_DragEvent](#arkui_dragevent) \*event, int64_t \*keys) | Obtains the pressed status of modifier keys from a drag event. |
| int32_t [OH_ArkUI_SetDragEventStrictReportWithNode](#oh_arkui_setdrageventstrictreportwithnode) ([ArkUI_NodeHandle](#arkui_nodehandle) node, bool enabled) | Sets whether to enable strict reporting on drag events. This feature is disabled by default, and you are advised to enable it. If this feature is disabled, the parent component is not notified when an item in it is dragged over its child component. If this feature is enabled, the component is notified of the dragged item's leaving, and the child component to which the dragged item is dropped is notified of the item's entering. This configuration is related to a specific UI instance. You can pass in a specific component node on the current UI instance for association. |
| int32_t [OH_ArkUI_SetDragEventStrictReportWithContext](#oh_arkui_setdrageventstrictreportwithcontext) ([ArkUI_ContextHandle](#arkui_contexthandle-12) uiContext, bool enabled) | Sets whether to enable strict reporting on drag events. This feature is disabled by default, and you are advised to enable it. If this feature is disabled, the parent component is not notified when an item in it is dragged over its child component. If this feature is enabled, the component is notified of the dragged item's leaving, and the child component to which the dragged item is dropped is notified of the item's entering. This configuration is related to a specific UI instance. You can pass in a specific UI instance for association. |
| int32_t [OH_ArkUI_SetNodeAllowedDropDataTypes](#oh_arkui_setnodealloweddropdatatypes) ([ArkUI_NodeHandle](#arkui_nodehandle) node, const char \*typesArray[], int32_t count) | Sets the types of data that can be dropped to the specified component. This API resets the settings configured through [OH_ArkUI_DisallowNodeAnyDropDataTypes](#oh_arkui_disallownodeanydropdatatypes) or [OH_ArkUI_AllowNodeAllDropDataTypes](#oh_arkui_allownodealldropdatatypes). |
| int32_t [OH_ArkUI_DisallowNodeAnyDropDataTypes](#oh_arkui_disallownodeanydropdatatypes) ([ArkUI_NodeHandle](#arkui_nodehandle) node) | Configures the specified component to disallow any data types. This API resets the settings configured through [OH_ArkUI_SetNodeAllowedDropDataTypes](#oh_arkui_setnodealloweddropdatatypes). |
| int32_t [OH_ArkUI_AllowNodeAllDropDataTypes](#oh_arkui_allownodealldropdatatypes) ([ArkUI_NodeHandle](#arkui_nodehandle) node) | Configures the specified component to allow any data types. This API resets the settings configured through [OH_ArkUI_SetNodeAllowedDropDataTypes](#oh_arkui_setnodealloweddropdatatypes). |
| int32_t [OH_ArkUI_SetNodeDraggable](#oh_arkui_setnodedraggable) ([ArkUI_NodeHandle](#arkui_nodehandle) node, bool enabled) | Sets whether the component is draggable. |
| int32_t [OH_ArkUI_SetNodeDragPreview](#oh_arkui_setnodedragpreview) ([ArkUI_NodeHandle](#arkui_nodehandle) node, [OH_PixelmapNative](#oh_pixelmapnative) \*preview) | Sets a custom drag preview for the specified component. |
| [ArkUI_DragPreviewOption](#arkui_dragpreviewoption) \* [OH_ArkUI_CreateDragPreviewOption](#oh_arkui_createdragpreviewoption) (void) | Creates an **ArkUI_DragPreviewOption** object. |
| void [OH_ArkUI_DragPreviewOption_Dispose](#oh_arkui_dragpreviewoption_dispose) ([ArkUI_DragPreviewOption](#arkui_dragpreviewoption) \*option) | Disposes of an **ArkUI_DragPreviewOption** object. |
| int32_t [OH_ArkUI_DragPreviewOption_SetScaleMode](#oh_arkui_dragpreviewoption_setscalemode) ([ArkUI_DragPreviewOption](#arkui_dragpreviewoption) \*option, [ArkUI_DragPreviewScaleMode](#arkui_dragpreviewscalemode) scaleMode) | Sets the scale mode for an **ArkUI_DragPreviewOption** object. |
| int32_t [OH_ArkUI_DragPreviewOption_SetDefaultShadowEnabled](#oh_arkui_dragpreviewoption_setdefaultshadowenabled) ([ArkUI_DragPreviewOption](#arkui_dragpreviewoption) \*option, bool enabled) | Sets whether to enable the shadow effect for an **ArkUI_DragPreviewOption** object. The shadow effect is enabled by default. |
| int32_t [OH_ArkUI_DragPreviewOption_SetDefaultRadiusEnabled](#oh_arkui_dragpreviewoption_setdefaultradiusenabled) ([ArkUI_DragPreviewOption](#arkui_dragpreviewoption) \*option, bool enabled) | Sets whether to enable the rounded corner effect for an **ArkUI_DragPreviewOption** object. The rounded corner effect is enabled by default. |
| int32_t [OH_ArkUI_DragPreviewOption_SetNumberBadgeEnabled](#oh_arkui_dragpreviewoption_setnumberbadgeenabled) ([ArkUI_DragPreviewOption](#arkui_dragpreviewoption) \*option, bool enabled) | Sets whether to enable the badge for an **ArkUI_DragPreviewOption** object. If this feature is enabled, a badge that contains the number of dragged items is displayed. |
| int32_t [OH_ArkUI_DragPreviewOption_SetBadgeNumber](#oh_arkui_dragpreviewoption_setbadgenumber) ([ArkUI_DragPreviewOption](#arkui_dragpreviewoption) \*option, uint32_t forcedNumber) | Sets the count on the badge. The settings will overwrite the value in the **SetDragPreviewNumberBadgeEnabled** API. |
| int32_t [OH_ArkUI_DragPreviewOption_SetDefaultAnimationBeforeLiftingEnabled](#oh_arkui_dragpreviewoption_setdefaultanimationbeforeliftingenabled) ([ArkUI_DragPreviewOption](#arkui_dragpreviewoption) \*option, bool enabled) | Sets whether to enable the default animation on a click or touch. |
| int32_t [OH_ArkUI_SetNodeDragPreviewOption](#oh_arkui_setnodedragpreviewoption) ([ArkUI_NodeHandle](#arkui_nodehandle) node, [ArkUI_DragPreviewOption](#arkui_dragpreviewoption) \*option) | Sets an **ArkUI_DragPreviewOption** object for the specified component. |
| [ArkUI_DragAction](#arkui_dragaction) \* [OH_ArkUI_CreateDragActionWithNode](#oh_arkui_createdragactionwithnode) ([ArkUI_NodeHandle](#arkui_nodehandle) node) | Creates a drag action object. The object needs to be associated with a UI instance, which can be specified by passing in a component node of the current UI instance. |
| [ArkUI_DragAction](#arkui_dragaction) \* [OH_ArkUI_CreateDragActionWithContext](#oh_arkui_createdragactionwithcontext) ([ArkUI_ContextHandle](#arkui_contexthandle-12) uiContext) | Creates a drag action object for the specified UI instance. |
| void [OH_ArkUI_DragAction_Dispose](#oh_arkui_dragaction_dispose) ([ArkUI_DragAction](#arkui_dragaction) \*dragAction) | Disposes of an **ArkUI_DragAction** object. |
| int32_t [OH_ArkUI_DragAction_SetPointerId](#oh_arkui_dragaction_setpointerid) ([ArkUI_DragAction](#arkui_dragaction) \*dragAction, int32_t pointer) | Sets the pointer ID. If only one finger is operating on the screen, the pointer ID is 0. In general cases, you can set the pointer ID to 0. |
| int32_t [OH_ArkUI_DragAction_SetPixelMaps](#oh_arkui_dragaction_setpixelmaps) ([ArkUI_DragAction](#arkui_dragaction) \*dragAction, [OH_PixelmapNative](#oh_pixelmapnative) \*pixelmapArray[], int32_t size) | Sets the drag previews for a drag action. |
| int32_t [OH_ArkUI_DragAction_SetTouchPointX](#oh_arkui_dragaction_settouchpointx) ([ArkUI_DragAction](#arkui_dragaction) \*dragAction, float x) | Sets the touch point relative to the upper left corner of the first drag preview (pixel map). |
| int32_t [OH_ArkUI_DragAction_SetTouchPointY](#oh_arkui_dragaction_settouchpointy) ([ArkUI_DragAction](#arkui_dragaction) \*dragAction, float y) | Sets the touch point relative to the upper left corner of the first drag preview (pixel map). |
| int32_t [OH_ArkUI_DragAction_SetData](#oh_arkui_dragaction_setdata) ([ArkUI_DragAction](#arkui_dragaction) \*dragAction, [OH_UdmfData](#oh_udmfdata) \*data) | Sets the drag data. |
| int32_t [OH_ArkUI_DragAction_SetDragPreviewOption](#oh_arkui_dragaction_setdragpreviewoption) ([ArkUI_DragAction](#arkui_dragaction) \*dragAction, [ArkUI_DragPreviewOption](#arkui_dragpreviewoption) \*option) | Sets an **ArkUI_DragPreviewOption** object for the specified drag action object. |
| int32_t [OH_ArkUI_DragAction_RegisterStatusListener](#oh_arkui_dragaction_registerstatuslistener) ([ArkUI_DragAction](#arkui_dragaction) \*dragAction, void \*userData, void(\*listener)([ArkUI_DragAndDropInfo](#arkui_draganddropinfo) \*dragAndDropInfo, void \*userData)) | Registers a drag status listener. This listener can be used to check whether the data is successfully received and processed. |
| void [OH_ArkUI_DragAction_UnregisterStatusListener](#oh_arkui_dragaction_unregisterstatuslistener) ([ArkUI_DragAction](#arkui_dragaction) \*dragAction) | Unregisters a drag status listener. |
| [ArkUI_DragStatus](#arkui_dragstatus) [OH_ArkUI_DragAndDropInfo_GetDragStatus](#oh_arkui_draganddropinfo_getdragstatus) ([ArkUI_DragAndDropInfo](#arkui_draganddropinfo) \*dragAndDropInfo) | Obtains the drag status of a drag action. |
| [ArkUI_DragEvent](#arkui_dragevent) \* [OH_ArkUI_DragAndDropInfo_GetDragEvent](#oh_arkui_draganddropinfo_getdragevent) ([ArkUI_DragAndDropInfo](#arkui_draganddropinfo) \*dragAndDropInfo) | Obtains a drag event based on the specified drag and drop information. The drag event can then be used to obtain the drag result. |
| int32_t [OH_ArkUI_StartDrag](#oh_arkui_startdrag) ([ArkUI_DragAction](#arkui_dragaction) \*dragAction) | Initiates a drag action through the specified **DragAction** object. |
| [ArkUI_DrawableDescriptor](#arkui_drawabledescriptor) \* [OH_ArkUI_DrawableDescriptor_CreateFromPixelMap](#oh_arkui_drawabledescriptor_createfrompixelmap) ([OH_PixelmapNativeHandle](#oh_pixelmapnativehandle) pixelMap) | Creates a **DrawableDescriptor** object from a **PixelMap** object. |
| [ArkUI_DrawableDescriptor](#arkui_drawabledescriptor) \* [OH_ArkUI_DrawableDescriptor_CreateFromAnimatedPixelMap](#oh_arkui_drawabledescriptor_createfromanimatedpixelmap) ([OH_PixelmapNativeHandle](#oh_pixelmapnativehandle) \*array, int32_t size) | Creates a **DrawableDescriptor** object from an array of **PixelMap** objects. |
| void [OH_ArkUI_DrawableDescriptor_Dispose](#oh_arkui_drawabledescriptor_dispose) ([ArkUI_DrawableDescriptor](#arkui_drawabledescriptor) \*drawableDescriptor) | Disposes of the pointer to a **DrawableDescriptor** object. |
| [OH_PixelmapNativeHandle](#oh_pixelmapnativehandle) [OH_ArkUI_DrawableDescriptor_GetStaticPixelMap](#oh_arkui_drawabledescriptor_getstaticpixelmap) ([ArkUI_DrawableDescriptor](#arkui_drawabledescriptor) \*drawableDescriptor) | Obtains the pointer to a **PixelMap** object. |
| [OH_PixelmapNativeHandle](#oh_pixelmapnativehandle) \* [OH_ArkUI_DrawableDescriptor_GetAnimatedPixelMapArray](#oh_arkui_drawabledescriptor_getanimatedpixelmaparray) ([ArkUI_DrawableDescriptor](#arkui_drawabledescriptor) \*drawableDescriptor) | Obtains an array of **PixelMap** objects for playing an animation. |
| int32_t [OH_ArkUI_DrawableDescriptor_GetAnimatedPixelMapArraySize](#oh_arkui_drawabledescriptor_getanimatedpixelmaparraysize) ([ArkUI_DrawableDescriptor](#arkui_drawabledescriptor) \*drawableDescriptor) | Obtains an array of **PixelMap** objects for playing an animation. |
| void [OH_ArkUI_DrawableDescriptor_SetAnimationDuration](#oh_arkui_drawabledescriptor_setanimationduration) ([ArkUI_DrawableDescriptor](#arkui_drawabledescriptor) \*drawableDescriptor, int32_t duration) | Sets the total playback duration for a pixel map image array. |
| int32_t [OH_ArkUI_DrawableDescriptor_GetAnimationDuration](#oh_arkui_drawabledescriptor_getanimationduration) ([ArkUI_DrawableDescriptor](#arkui_drawabledescriptor) \*drawableDescriptor) | Obtains the total playback duration for a pixel map image array. |
| void [OH_ArkUI_DrawableDescriptor_SetAnimationIteration](#oh_arkui_drawabledescriptor_setanimationiteration) ([ArkUI_DrawableDescriptor](#arkui_drawabledescriptor) \*drawableDescriptor, int32_t iteration) | Sets the number of times that a pixel map image array is played. |
| int32_t [OH_ArkUI_DrawableDescriptor_GetAnimationIteration](#oh_arkui_drawabledescriptor_getanimationiteration) ([ArkUI_DrawableDescriptor](#arkui_drawabledescriptor) \*drawableDescriptor) | Obtains the number of times that a pixel map image array is played. |
| [ArkUI_AnimateOption](#arkui_animateoption) \* [OH_ArkUI_AnimateOption_Create](#oh_arkui_animateoption_create) () | Creates an animation configuration. |
| void [OH_ArkUI_AnimateOption_Dispose](#oh_arkui_animateoption_dispose) ([ArkUI_AnimateOption](#arkui_animateoption) \*option) | Destroys an animation configuration. |
| int32_t [OH_ArkUI_AnimateOption_GetDuration](#oh_arkui_animateoption_getduration) ([ArkUI_AnimateOption](#arkui_animateoption) \*option) | Obtains the animation duration, in milliseconds. |
| float [OH_ArkUI_AnimateOption_GetTempo](#oh_arkui_animateoption_gettempo) ([ArkUI_AnimateOption](#arkui_animateoption) \*option) | Obtains the playback speed of an animation. |
| [ArkUI_AnimationCurve](#arkui_animationcurve) [OH_ArkUI_AnimateOption_GetCurve](#oh_arkui_animateoption_getcurve) ([ArkUI_AnimateOption](#arkui_animateoption) \*option) | Obtains an animation curve. |
| int32_t [OH_ArkUI_AnimateOption_GetDelay](#oh_arkui_animateoption_getdelay) ([ArkUI_AnimateOption](#arkui_animateoption) \*option) | Obtains the animation delay, in milliseconds. |
| int32_t [OH_ArkUI_AnimateOption_GetIterations](#oh_arkui_animateoption_getiterations) ([ArkUI_AnimateOption](#arkui_animateoption) \*option) | Obtains the number of times that an animation is played. |
| [ArkUI_AnimationPlayMode](#arkui_animationplaymode) [OH_ArkUI_AnimateOption_GetPlayMode](#oh_arkui_animateoption_getplaymode) ([ArkUI_AnimateOption](#arkui_animateoption) \*option) | Obtains the playback mode of an animation. |
| [ArkUI_ExpectedFrameRateRange](_ark_u_i___expected_frame_rate_range.md) \* [OH_ArkUI_AnimateOption_GetExpectedFrameRateRange](#oh_arkui_animateoption_getexpectedframeraterange) ([ArkUI_AnimateOption](#arkui_animateoption) \*option) | Obtains the expected frame rate range of an animation. |
| void [OH_ArkUI_AnimateOption_SetDuration](#oh_arkui_animateoption_setduration) ([ArkUI_AnimateOption](#arkui_animateoption) \*option, int32_t value) | Sets the animation duration. |
| void [OH_ArkUI_AnimateOption_SetTempo](#oh_arkui_animateoption_settempo) ([ArkUI_AnimateOption](#arkui_animateoption) \*option, float value) | Sets the playback speed of an animation. |
| void [OH_ArkUI_AnimateOption_SetCurve](#oh_arkui_animateoption_setcurve) ([ArkUI_AnimateOption](#arkui_animateoption) \*option, [ArkUI_AnimationCurve](#arkui_animationcurve) value) | Animation curve. |
| void [OH_ArkUI_AnimateOption_SetDelay](#oh_arkui_animateoption_setdelay) ([ArkUI_AnimateOption](#arkui_animateoption) \*option, int32_t value) | Sets the animation delay. |
| void [OH_ArkUI_AnimateOption_SetIterations](#oh_arkui_animateoption_setiterations) ([ArkUI_AnimateOption](#arkui_animateoption) \*option, int32_t value) | Number of times that the frame animation is played. |
| void [OH_ArkUI_AnimateOption_SetPlayMode](#oh_arkui_animateoption_setplaymode) ([ArkUI_AnimateOption](#arkui_animateoption) \*option, [ArkUI_AnimationPlayMode](#arkui_animationplaymode) value) | Sets the playback mode for an animation. |
| void [OH_ArkUI_AnimateOption_SetExpectedFrameRateRange](#oh_arkui_animateoption_setexpectedframeraterange) ([ArkUI_AnimateOption](#arkui_animateoption) \*option, [ArkUI_ExpectedFrameRateRange](_ark_u_i___expected_frame_rate_range.md) \*value) | Defines the expected frame rate range of the animation. |
| void [OH_ArkUI_AnimateOption_SetICurve](#oh_arkui_animateoption_seticurve) ([ArkUI_AnimateOption](#arkui_animateoption) \*option, [ArkUI_CurveHandle](#arkui_curvehandle) value) | Sets the animation curve for an animation. |
| [ArkUI_CurveHandle](#arkui_curvehandle) [OH_ArkUI_AnimateOption_GetICurve](#oh_arkui_animateoption_geticurve) ([ArkUI_AnimateOption](#arkui_animateoption) \*option) | Obtains the animation curve of an animation. |
| [ArkUI_KeyframeAnimateOption](#arkui_keyframeanimateoption) \* [OH_ArkUI_KeyframeAnimateOption_Create](#oh_arkui_keyframeanimateoption_create) (int32_t size) | Obtains the keyframe animation parameters. |
| void [OH_ArkUI_KeyframeAnimateOption_Dispose](#oh_arkui_keyframeanimateoption_dispose) ([ArkUI_KeyframeAnimateOption](#arkui_keyframeanimateoption) \*option) | Destroys a keyframe animation parameter object. |
| int32_t [OH_ArkUI_KeyframeAnimateOption_SetDelay](#oh_arkui_keyframeanimateoption_setdelay) ([ArkUI_KeyframeAnimateOption](#arkui_keyframeanimateoption) \*option, int32_t value) | Sets the overall delay of a keyframe animation, in milliseconds. By default, the keyframe animation is played without delay. |
| int32_t [OH_ArkUI_KeyframeAnimateOption_SetIterations](#oh_arkui_keyframeanimateoption_setiterations) ([ArkUI_KeyframeAnimateOption](#arkui_keyframeanimateoption) \*option, int32_t value) | Sets the number of times that the keyframe animation is played. By default, the animation is played once. The value **-1** indicates that the animation is played for an unlimited number of times. The value **0** indicates that there is no animation. |
| int32_t [OH_ArkUI_KeyframeAnimateOption_RegisterOnFinishCallback](#oh_arkui_keyframeanimateoption_registeronfinishcallback) ([ArkUI_KeyframeAnimateOption](#arkui_keyframeanimateoption) \*option, void \*userData, void(\*onFinish)(void \*userData)) | Sets the callback invoked when the keyframe animation playback is complete. This API is called after the keyframe animation has played for the specified number of times. |
| int32_t [OH_ArkUI_KeyframeAnimateOption_SetDuration](#oh_arkui_keyframeanimateoption_setduration) ([ArkUI_KeyframeAnimateOption](#arkui_keyframeanimateoption) \*option, int32_t value, int32_t index) | Sets the duration of a keyframe animation, in milliseconds. |
| int32_t [OH_ArkUI_KeyframeAnimateOption_SetCurve](#oh_arkui_keyframeanimateoption_setcurve) ([ArkUI_KeyframeAnimateOption](#arkui_keyframeanimateoption) \*option, [ArkUI_CurveHandle](#arkui_curvehandle) value, int32_t index) | Sets the animation curve for a specific keyframe in a keyframe animation. |
| int32_t [OH_ArkUI_KeyframeAnimateOption_RegisterOnEventCallback](#oh_arkui_keyframeanimateoption_registeroneventcallback) ([ArkUI_KeyframeAnimateOption](#arkui_keyframeanimateoption) \*option, void \*userData, void(\*event)(void \*userData), int32_t index) | Sets the closure function of the state at the time of the keyframe, that is, the state to be reached at the time of the keyframe. |
| int32_t [OH_ArkUI_KeyframeAnimateOption_GetDelay](#oh_arkui_keyframeanimateoption_getdelay) ([ArkUI_KeyframeAnimateOption](#arkui_keyframeanimateoption) \*option) | Obtains the overall delay of a keyframe animation |
| int32_t [OH_ArkUI_KeyframeAnimateOption_GetIterations](#oh_arkui_keyframeanimateoption_getiterations) ([ArkUI_KeyframeAnimateOption](#arkui_keyframeanimateoption) \*option) | Obtains the number of times that a keyframe animation is played. |
| int32_t [OH_ArkUI_KeyframeAnimateOption_GetDuration](#oh_arkui_keyframeanimateoption_getduration) ([ArkUI_KeyframeAnimateOption](#arkui_keyframeanimateoption) \*option, int32_t index) | Obtains the duration of a specific state in a keyframe animation. |
| [ArkUI_CurveHandle](#arkui_curvehandle) [OH_ArkUI_KeyframeAnimateOption_GetCurve](#oh_arkui_keyframeanimateoption_getcurve) ([ArkUI_KeyframeAnimateOption](#arkui_keyframeanimateoption) \*option, int32_t index) | Obtains the animation curve of a specific state in a keyframe animation. |
| [ArkUI_AnimatorOption](#arkui_animatoroption) \* [OH_ArkUI_AnimatorOption_Create](#oh_arkui_animatoroption_create) (int32_t keyframeSize) | Creates an animator parameter object. |
| void [OH_ArkUI_AnimatorOption_Dispose](#oh_arkui_animatoroption_dispose) ([ArkUI_AnimatorOption](#arkui_animatoroption) \*option) | Destroys an animator parameter object. |
| int32_t [OH_ArkUI_AnimatorOption_SetDuration](#oh_arkui_animatoroption_setduration) ([ArkUI_AnimatorOption](#arkui_animatoroption) \*option, int32_t value) | Sets the duration of an animation, in milliseconds. |
| int32_t [OH_ArkUI_AnimatorOption_SetDelay](#oh_arkui_animatoroption_setdelay) ([ArkUI_AnimatorOption](#arkui_animatoroption) \*option, int32_t value) | Sets the delay of animation playback, in milliseconds. |
| int32_t [OH_ArkUI_AnimatorOption_SetIterations](#oh_arkui_animatoroption_setiterations) ([ArkUI_AnimatorOption](#arkui_animatoroption) \*option, int32_t value) | Number of times that the frame animation is played. The value **0** means not to play the animation, and **-1** means to play the animation for an unlimited number of times. |
| int32_t [OH_ArkUI_AnimatorOption_SetFill](#oh_arkui_animatoroption_setfill) ([ArkUI_AnimatorOption](#arkui_animatoroption) \*option, [ArkUI_AnimationFill](#arkui_animationfill) value) | Sets whether the animator animation is restored to the initial state after being executed. |
| int32_t [OH_ArkUI_AnimatorOption_SetDirection](#oh_arkui_animatoroption_setdirection) ([ArkUI_AnimatorOption](#arkui_animatoroption) \*option, [ArkUI_AnimationDirection](#arkui_animationdirection) value) | Sets the playback direction. |
| int32_t [OH_ArkUI_AnimatorOption_SetCurve](#oh_arkui_animatoroption_setcurve) ([ArkUI_AnimatorOption](#arkui_animatoroption) \*option, [ArkUI_CurveHandle](#arkui_curvehandle) value) | Sets the interpolation curve for the animation of an animator. |
| int32_t [OH_ArkUI_AnimatorOption_SetBegin](#oh_arkui_animatoroption_setbegin) ([ArkUI_AnimatorOption](#arkui_animatoroption) \*option, float value) | Sets the interpolation start point for the animation of an animator. |
| int32_t [OH_ArkUI_AnimatorOption_SetEnd](#oh_arkui_animatoroption_setend) ([ArkUI_AnimatorOption](#arkui_animatoroption) \*option, float value) | Sets the interpolation end point for the animation of an animator. |
| int32_t [OH_ArkUI_AnimatorOption_SetExpectedFrameRateRange](#oh_arkui_animatoroption_setexpectedframeraterange) ([ArkUI_AnimatorOption](#arkui_animatoroption) \*option, [ArkUI_ExpectedFrameRateRange](_ark_u_i___expected_frame_rate_range.md) \*value) | Sets the expected frame rate range of an animation. |
| int32_t [OH_ArkUI_AnimatorOption_SetKeyframe](#oh_arkui_animatoroption_setkeyframe) ([ArkUI_AnimatorOption](#arkui_animatoroption) \*option, float time, float value, int32_t index) | Sets the keyframe parameters of an animation. |
| int32_t [OH_ArkUI_AnimatorOption_SetKeyframeCurve](#oh_arkui_animatoroption_setkeyframecurve) ([ArkUI_AnimatorOption](#arkui_animatoroption) \*option, [ArkUI_CurveHandle](#arkui_curvehandle) value, int32_t index) | Sets the keyframe curve type for the animation of an animator. |
| int32_t [OH_ArkUI_AnimatorOption_GetDuration](#oh_arkui_animatoroption_getduration) ([ArkUI_AnimatorOption](#arkui_animatoroption) \*option) | Obtains the duration for playing an animation. |
| int32_t [OH_ArkUI_AnimatorOption_GetDelay](#oh_arkui_animatoroption_getdelay) ([ArkUI_AnimatorOption](#arkui_animatoroption) \*option) | Obtains the delay for playing an animation. |
| int32_t [OH_ArkUI_AnimatorOption_GetIterations](#oh_arkui_animatoroption_getiterations) ([ArkUI_AnimatorOption](#arkui_animatoroption) \*option) | Obtains the number of times that an animation is played. |
| [ArkUI_AnimationFill](#arkui_animationfill) [OH_ArkUI_AnimatorOption_GetFill](#oh_arkui_animatoroption_getfill) ([ArkUI_AnimatorOption](#arkui_animatoroption) \*option) | Obtains whether the animator animation is restored to the initial state after being executed. |
| [ArkUI_AnimationDirection](#arkui_animationdirection) [OH_ArkUI_AnimatorOption_GetDirection](#oh_arkui_animatoroption_getdirection) ([ArkUI_AnimatorOption](#arkui_animatoroption) \*option) | Obtains the playback direction of an animation. |
| [ArkUI_CurveHandle](#arkui_curvehandle) [OH_ArkUI_AnimatorOption_GetCurve](#oh_arkui_animatoroption_getcurve) ([ArkUI_AnimatorOption](#arkui_animatoroption) \*option) | Obtains the interpolation curve of the animation of an animator. |
| float [OH_ArkUI_AnimatorOption_GetBegin](#oh_arkui_animatoroption_getbegin) ([ArkUI_AnimatorOption](#arkui_animatoroption) \*option) | Obtains the interpolation start point of an animation. |
| float [OH_ArkUI_AnimatorOption_GetEnd](#oh_arkui_animatoroption_getend) ([ArkUI_AnimatorOption](#arkui_animatoroption) \*option) | Obtains the interpolation end point of an animation. |
| [ArkUI_ExpectedFrameRateRange](_ark_u_i___expected_frame_rate_range.md) \* [OH_ArkUI_AnimatorOption_GetExpectedFrameRateRange](#oh_arkui_animatoroption_getexpectedframeraterange) ([ArkUI_AnimatorOption](#arkui_animatoroption) \*option) | Obtains the expected frame rate range of an animation. |
| float [OH_ArkUI_AnimatorOption_GetKeyframeTime](#oh_arkui_animatoroption_getkeyframetime) ([ArkUI_AnimatorOption](#arkui_animatoroption) \*option, int32_t index) | Obtains the keyframe time of an animation. |
| float [OH_ArkUI_AnimatorOption_GetKeyframeValue](#oh_arkui_animatoroption_getkeyframevalue) ([ArkUI_AnimatorOption](#arkui_animatoroption) \*option, int32_t index) | Obtains the keyframe value of an animation. |
| [ArkUI_CurveHandle](#arkui_curvehandle) [OH_ArkUI_AnimatorOption_GetKeyframeCurve](#oh_arkui_animatoroption_getkeyframecurve) ([ArkUI_AnimatorOption](#arkui_animatoroption) \*option, int32_t index) | Obtains the interpolation curve for a keyframe in the animation of an animator. |
| void \* [OH_ArkUI_AnimatorEvent_GetUserData](#oh_arkui_animatorevent_getuserdata) (ArkUI_AnimatorEvent \*event) | Obtains the custom object in an animation event object. |
| void \* [OH_ArkUI_AnimatorOnFrameEvent_GetUserData](#oh_arkui_animatoronframeevent_getuserdata) (ArkUI_AnimatorOnFrameEvent \*event) | Obtains the custom object in an animation event object. |
| float [OH_ArkUI_AnimatorOnFrameEvent_GetValue](#oh_arkui_animatoronframeevent_getvalue) (ArkUI_AnimatorOnFrameEvent \*event) | Obtains the current progress in an animation event object. |
| int32_t [OH_ArkUI_AnimatorOption_RegisterOnFrameCallback](#oh_arkui_animatoroption_registeronframecallback) ([ArkUI_AnimatorOption](#arkui_animatoroption) \*option, void \*userData, void(\*callback)(ArkUI_AnimatorOnFrameEvent \*event)) | Sets the callback invoked when the animator receives a frame. |
| int32_t [OH_ArkUI_AnimatorOption_RegisterOnFinishCallback](#oh_arkui_animatoroption_registeronfinishcallback) ([ArkUI_AnimatorOption](#arkui_animatoroption) \*option, void \*userData, void(\*callback)(ArkUI_AnimatorEvent \*event)) | Sets the callback invoked when the animation playback is complete. |
| int32_t [OH_ArkUI_AnimatorOption_RegisterOnCancelCallback](#oh_arkui_animatoroption_registeroncancelcallback) ([ArkUI_AnimatorOption](#arkui_animatoroption) \*option, void \*userData, void(\*callback)(ArkUI_AnimatorEvent \*event)) | Sets the callback invoked when the animation playback is canceled. |
| int32_t [OH_ArkUI_AnimatorOption_RegisterOnRepeatCallback](#oh_arkui_animatoroption_registeronrepeatcallback) ([ArkUI_AnimatorOption](#arkui_animatoroption) \*option, void \*userData, void(\*callback)(ArkUI_AnimatorEvent \*event)) | Sets the callback invoked when the animation playback is repeated. |
| int32_t [OH_ArkUI_Animator_ResetAnimatorOption](#oh_arkui_animator_resetanimatoroption) ([ArkUI_AnimatorHandle](#arkui_animatorhandle) animator, [ArkUI_AnimatorOption](#arkui_animatoroption) \*option) | Resets an animator configuration. |
| int32_t [OH_ArkUI_Animator_Play](#oh_arkui_animator_play) ([ArkUI_AnimatorHandle](#arkui_animatorhandle) animator) | Starts the animation of an animator. |
| int32_t [OH_ArkUI_Animator_Finish](#oh_arkui_animator_finish) ([ArkUI_AnimatorHandle](#arkui_animatorhandle) animator) | Ends the animation of an animator. |
| int32_t [OH_ArkUI_Animator_Pause](#oh_arkui_animator_pause) ([ArkUI_AnimatorHandle](#arkui_animatorhandle) animator) | Pauses the animation of an animator. |
| int32_t [OH_ArkUI_Animator_Cancel](#oh_arkui_animator_cancel) ([ArkUI_AnimatorHandle](#arkui_animatorhandle) animator) | Cancels the animation of an animator. |
| int32_t [OH_ArkUI_Animator_Reverse](#oh_arkui_animator_reverse) ([ArkUI_AnimatorHandle](#arkui_animatorhandle) animator) | Plays this animation in reverse order. |
| [ArkUI_CurveHandle](#arkui_curvehandle) [OH_ArkUI_Curve_CreateCurveByType](#oh_arkui_curve_createcurvebytype) ([ArkUI_AnimationCurve](#arkui_animationcurve) curve) | Implements initialization for the interpolation curve, which is used to create an interpolation curve based on the input parameter. |
| [ArkUI_CurveHandle](#arkui_curvehandle) [OH_ArkUI_Curve_CreateStepsCurve](#oh_arkui_curve_createstepscurve) (int32_t count, bool end) | Creates a step curve. |
| [ArkUI_CurveHandle](#arkui_curvehandle) [OH_ArkUI_Curve_CreateCubicBezierCurve](#oh_arkui_curve_createcubicbeziercurve) (float x1, float y1, float x2, float y2) | Creates a cubic Bezier curve. |
| [ArkUI_CurveHandle](#arkui_curvehandle) [OH_ArkUI_Curve_CreateSpringCurve](#oh_arkui_curve_createspringcurve) (float velocity, float mass, float stiffness, float damping) | Creates a spring curve. The curve shape is subject to the spring parameters, and the animation duration is subject to the **duration** parameter in **animation** and **animateTo**. |
| [ArkUI_CurveHandle](#arkui_curvehandle) [OH_ArkUI_Curve_CreateSpringMotion](#oh_arkui_curve_createspringmotion) (float response, float dampingFraction, float overlapDuration) | Creates a spring animation curve. If multiple spring animations are applied to the same attribute of an object, each animation replaces their predecessor and inherits the velocity. |
| [ArkUI_CurveHandle](#arkui_curvehandle) [OH_ArkUI_Curve_CreateResponsiveSpringMotion](#oh_arkui_curve_createresponsivespringmotion) (float response, float dampingFraction, float overlapDuration) | Creates a responsive spring animation curve. It is a special case of **springMotion**, with the only difference in the default values. It can be used together with **springMotion**. |
| [ArkUI_CurveHandle](#arkui_curvehandle) [OH_ArkUI_Curve_CreateInterpolatingSpring](#oh_arkui_curve_createinterpolatingspring) (float velocity, float mass, float stiffness, float damping) | Creates an interpolating spring curve animated from 0 to 1. The actual animation value is calculated based on the curve. |
| [ArkUI_CurveHandle](#arkui_curvehandle) [OH_ArkUI_Curve_CreateCustomCurve](#oh_arkui_curve_createcustomcurve) (void \*userData, float(\*interpolate)(float fraction, void \*userdata)) | Creates a custom curve. |
| void [OH_ArkUI_Curve_DisposeCurve](#oh_arkui_curve_disposecurve) ([ArkUI_CurveHandle](#arkui_curvehandle) curveHandle) | Disposes of a custom curve. |
| [ArkUI_TransitionEffect](#arkui_transitioneffect) \* [OH_ArkUI_CreateOpacityTransitionEffect](#oh_arkui_createopacitytransitioneffect) (float opacity) | Creates an opacity object for component transition. |
| [ArkUI_TransitionEffect](#arkui_transitioneffect) \* [OH_ArkUI_CreateTranslationTransitionEffect](#oh_arkui_createtranslationtransitioneffect) ([ArkUI_TranslationOptions](_ark_u_i___translation_options.md) \*translate) | Creates a translation object for component transition. |
| [ArkUI_TransitionEffect](#arkui_transitioneffect) \* [OH_ArkUI_CreateScaleTransitionEffect](#oh_arkui_createscaletransitioneffect) ([ArkUI_ScaleOptions](_ark_u_i___scale_options.md) \*scale) | Creates a scaling object for component transition. |
| [ArkUI_TransitionEffect](#arkui_transitioneffect) \* [OH_ArkUI_CreateRotationTransitionEffect](#oh_arkui_createrotationtransitioneffect) ([ArkUI_RotationOptions](_ark_u_i___rotation_options.md) \*rotate) | Creates a rotation object for component transition. |
| [ArkUI_TransitionEffect](#arkui_transitioneffect) \* [OH_ArkUI_CreateMovementTransitionEffect](#oh_arkui_createmovementtransitioneffect) ([ArkUI_TransitionEdge](#arkui_transitionedge) move) | Creates a movement object for component transition. |
| [ArkUI_TransitionEffect](#arkui_transitioneffect) \* [OH_ArkUI_CreateAsymmetricTransitionEffect](#oh_arkui_createasymmetrictransitioneffect) ([ArkUI_TransitionEffect](#arkui_transitioneffect) \*appear, [ArkUI_TransitionEffect](#arkui_transitioneffect) \*disappear) | Creates an asymmetric transition effect. |
| void [OH_ArkUI_TransitionEffect_Dispose](#oh_arkui_transitioneffect_dispose) ([ArkUI_TransitionEffect](#arkui_transitioneffect) \*option) | Disposes of a transition effect. |
| int32_t [OH_ArkUI_TransitionEffect_Combine](#oh_arkui_transitioneffect_combine) ([ArkUI_TransitionEffect](#arkui_transitioneffect) \*option, [ArkUI_TransitionEffect](#arkui_transitioneffect) \*combine) | Sets a combination of transition effects. |
| int32_t [OH_ArkUI_TransitionEffect_SetAnimation](#oh_arkui_transitioneffect_setanimation) ([ArkUI_TransitionEffect](#arkui_transitioneffect) \*option, [ArkUI_AnimateOption](#arkui_animateoption) \*animation) | Sets transition effect animation settings. |
| void [OH_ArkUI_DialogDismissEvent_SetShouldBlockDismiss](#oh_arkui_dialogdismissevent_setshouldblockdismiss) ([ArkUI_DialogDismissEvent](#arkui_dialogdismissevent) \*event, bool shouldBlockDismiss) | Sets whether to block the system behavior of dismissing a dialog box. |
| void \* [OH_ArkUI_DialogDismissEvent_GetUserData](#oh_arkui_dialogdismissevent_getuserdata) ([ArkUI_DialogDismissEvent](#arkui_dialogdismissevent) \*event) | Obtains the pointer to user data in a dialog box dismiss event object. |
| int32_t [OH_ArkUI_DialogDismissEvent_GetDismissReason](#oh_arkui_dialogdismissevent_getdismissreason) ([ArkUI_DialogDismissEvent](#arkui_dialogdismissevent) \*event) | Obtains the dismissal reason from a dialog box dismiss event object. |
| bool [OH_ArkUI_GestureInterruptInfo_GetSystemFlag](#oh_arkui_gestureinterruptinfo_getsystemflag) (const ArkUI_GestureInterruptInfo \*event) | Checks whether a gesture is a built-in gesture of the component. |
| ArkUI_GestureRecognizer \* [OH_ArkUI_GestureInterruptInfo_GetRecognizer](#oh_arkui_gestureinterruptinfo_getrecognizer) (const ArkUI_GestureInterruptInfo \*event) | Obtains the pointer to interrupted gesture recognizer. |
| ArkUI_GestureEvent \* [OH_ArkUI_GestureInterruptInfo_GetGestureEvent](#oh_arkui_gestureinterruptinfo_getgestureevent) (const ArkUI_GestureInterruptInfo \*event) | Obtains the pointer to the interrupted gesture event. |
| int32_t [OH_ArkUI_GestureInterruptInfo_GetSystemRecognizerType](#oh_arkui_gestureinterruptinfo_getsystemrecognizertype) (const ArkUI_GestureInterruptInfo \*event) | Obtains the type of the system gesture to trigger. |
| [ArkUI_GestureEventActionType](#arkui_gestureeventactiontype) [OH_ArkUI_GestureEvent_GetActionType](#oh_arkui_gestureevent_getactiontype) (const ArkUI_GestureEvent \*event) | Obtains the gesture event type. |
| [ArkUI_NodeHandle](#arkui_nodehandle) [OH_ArkUI_GestureEvent_GetResponseNode](#oh_arkui_gestureevent_getresponsenode) (ArkUI_GestureEvent \*event) | Obtains the node that responds to the gesture. |
| const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \* [OH_ArkUI_GestureEvent_GetRawInputEvent](#oh_arkui_gestureevent_getrawinputevent) (const ArkUI_GestureEvent \*event) | Obtains gesture input. |
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
| [ArkUI_NodeHandle](#arkui_nodehandle) [OH_ArkUI_GestureEvent_GetNode](#oh_arkui_gestureevent_getnode) (const ArkUI_GestureEvent \*event) | Obtains the ArkUI component to which the gesture is bound. |
| int32_t [OH_ArkUI_GetResponseRecognizersFromInterruptInfo](#oh_arkui_getresponserecognizersfrominterruptinfo) (const ArkUI_GestureInterruptInfo \*event, [ArkUI_GestureRecognizerHandleArray](#arkui_gesturerecognizerhandlearray) \*responseChain, int32_t \*count) | Obtains information about a gesture response chain. |
| int32_t [OH_ArkUI_SetGestureRecognizerEnabled](#oh_arkui_setgesturerecognizerenabled) (ArkUI_GestureRecognizer \*recognizer, bool enabled) | Sets the enabled state of a gesture recognizer. |
| bool [OH_ArkUI_GetGestureRecognizerEnabled](#oh_arkui_getgesturerecognizerenabled) (ArkUI_GestureRecognizer \*recognizer) | Obtains the enabled state of a gesture recognizer. |
| int32_t [OH_ArkUI_GetGestureRecognizerState](#oh_arkui_getgesturerecognizerstate) (ArkUI_GestureRecognizer \*recognizer, [ArkUI_GestureRecognizerState](#arkui_gesturerecognizerstate) \*state) | Obtains the state of a gesture recognizer. |
| int32_t [OH_ArkUI_GetGestureEventTargetInfo](#oh_arkui_getgestureeventtargetinfo) (ArkUI_GestureRecognizer \*recognizer, [ArkUI_GestureEventTargetInfo](#arkui_gestureeventtargetinfo) \*\*info) | Obtains the information about a gesture event target. |
| int32_t [OH_ArkUI_GestureEventTargetInfo_IsScrollBegin](#oh_arkui_gestureeventtargetinfo_isscrollbegin) ([ArkUI_GestureEventTargetInfo](#arkui_gestureeventtargetinfo) \*info, bool \*ret) | Obtains whether this scroll container is scrolled to the top. |
| int32_t [OH_ArkUI_GestureEventTargetInfo_IsScrollEnd](#oh_arkui_gestureeventtargetinfo_isscrollend) ([ArkUI_GestureEventTargetInfo](#arkui_gestureeventtargetinfo) \*info, bool \*ret) | Obtains whether this scroll container is scrolled to the bottom. |
| int32_t [OH_ArkUI_GetPanGestureDirectionMask](#oh_arkui_getpangesturedirectionmask) (ArkUI_GestureRecognizer \*recognizer, [ArkUI_GestureDirectionMask](#arkui_gesturedirectionmask) \*directionMask) | Obtains the direction of a pan gesture. |
| bool [OH_ArkUI_IsBuiltInGesture](#oh_arkui_isbuiltingesture) (ArkUI_GestureRecognizer \*recognizer) | Obtains whether a gesture is a built-in gesture. |
| int32_t [OH_ArkUI_GetGestureTag](#oh_arkui_getgesturetag) (ArkUI_GestureRecognizer \*recognizer, char \*buffer, int32_t bufferSize, int32_t \*result) | Obtains the tag of a gesture recognizer. |
| int32_t [OH_ArkUI_GetGestureBindNodeId](#oh_arkui_getgesturebindnodeid) (ArkUI_GestureRecognizer \*recognizer, char \*nodeId, int32_t size, int32_t \*result) | Obtains the ID of the component linked to a gesture recognizer. |
| bool [OH_ArkUI_IsGestureRecognizerValid](#oh_arkui_isgesturerecognizervalid) (ArkUI_GestureRecognizer \*recognizer) | Obtains whether a gesture recognizer is valid. |
| void \* [OH_ArkUI_ParallelInnerGestureEvent_GetUserData](#oh_arkui_parallelinnergestureevent_getuserdata) ([ArkUI_ParallelInnerGestureEvent](#arkui_parallelinnergestureevent) \*event) | Obtains custom data in the parallel internal gesture event. |
| ArkUI_GestureRecognizer \* [OH_ArkUI_ParallelInnerGestureEvent_GetCurrentRecognizer](#oh_arkui_parallelinnergestureevent_getcurrentrecognizer) ([ArkUI_ParallelInnerGestureEvent](#arkui_parallelinnergestureevent) \*event) | Obtains the current gesture recognizer in a parallel internal gesture event. |
| int32_t [OH_ArkUI_ParallelInnerGestureEvent_GetConflictRecognizers](#oh_arkui_parallelinnergestureevent_getconflictrecognizers) ([ArkUI_ParallelInnerGestureEvent](#arkui_parallelinnergestureevent) \*event, [ArkUI_GestureRecognizerHandleArray](#arkui_gesturerecognizerhandlearray) \*array, int32_t \*size) | Obtains the conflicting gesture recognizers in a parallel internal gesture event. |
| int32_t [OH_ArkUI_SetArkUIGestureRecognizerDisposeNotify](#oh_arkui_setarkuigesturerecognizerdisposenotify) (ArkUI_GestureRecognizer \*recognizer, [ArkUI_GestureRecognizerDestructNotifyCallback](#arkui_gesturerecognizerdestructnotifycallback) callback, void \*userData) | Sets a callback function for notifying gesture recognizer destruction. |
| void \* [OH_ArkUI_QueryModuleInterfaceByName](#oh_arkui_querymoduleinterfacebyname) ([ArkUI_NativeAPIVariantKind](#arkui_nativeapivariantkind) type, const char \*structName) | Obtains the native API set of a specified type. |
| [ArkUI_NodeEventType](#arkui_nodeeventtype) [OH_ArkUI_NodeEvent_GetEventType](#oh_arkui_nodeevent_geteventtype) ([ArkUI_NodeEvent](#arkui_nodeevent-12) \*event) | Obtains the type of a component event. |
| int32_t [OH_ArkUI_NodeEvent_GetTargetId](#oh_arkui_nodeevent_gettargetid) ([ArkUI_NodeEvent](#arkui_nodeevent-12) \*event) | Obtains the custom ID of a component event. |
| [ArkUI_NodeHandle](#arkui_nodehandle) [OH_ArkUI_NodeEvent_GetNodeHandle](#oh_arkui_nodeevent_getnodehandle) ([ArkUI_NodeEvent](#arkui_nodeevent-12) \*event) | Obtains the component object that triggers an event. |
| [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \* [OH_ArkUI_NodeEvent_GetInputEvent](#oh_arkui_nodeevent_getinputevent) ([ArkUI_NodeEvent](#arkui_nodeevent-12) \*event) | Obtains input event (for example, touch event) data for a component event. |
| [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) \* [OH_ArkUI_NodeEvent_GetNodeComponentEvent](#oh_arkui_nodeevent_getnodecomponentevent) ([ArkUI_NodeEvent](#arkui_nodeevent-12) \*event) | Obtains the numerical data in a component event. |
| [ArkUI_StringAsyncEvent](_ark_u_i___string_async_event.md) \* [OH_ArkUI_NodeEvent_GetStringAsyncEvent](#oh_arkui_nodeevent_getstringasyncevent) ([ArkUI_NodeEvent](#arkui_nodeevent-12) \*event) | Obtains the string data in a component event. |
| void \* [OH_ArkUI_NodeEvent_GetUserData](#oh_arkui_nodeevent_getuserdata) ([ArkUI_NodeEvent](#arkui_nodeevent-12) \*event) | Obtains the custom data in a component event. |
| int32_t [OH_ArkUI_NodeEvent_GetNumberValue](#oh_arkui_nodeevent_getnumbervalue) ([ArkUI_NodeEvent](#arkui_nodeevent-12) \*event, int32_t index, [ArkUI_NumberValue](union_ark_u_i___number_value.md) \*value) | Obtains the numeric-type parameter of a component event. |
| int32_t [OH_ArkUI_NodeEvent_GetStringValue](#oh_arkui_nodeevent_getstringvalue) ([ArkUI_NodeEvent](#arkui_nodeevent-12) \*event, int32_t index, char \*\*string, int32_t \*stringSize) | Obtains the string-type parameter of a component event. The string data is valid only during an event callback. To use it outside an event callback, you are advised to copy the string data. |
| int32_t [OH_ArkUI_NodeEvent_SetReturnNumberValue](#oh_arkui_nodeevent_setreturnnumbervalue) ([ArkUI_NodeEvent](#arkui_nodeevent-12) \*event, [ArkUI_NumberValue](union_ark_u_i___number_value.md) \*value, int32_t size) | Sets the return value for a component event. |
| [ArkUI_NodeAdapterHandle](#arkui_nodeadapterhandle) [OH_ArkUI_NodeAdapter_Create](#oh_arkui_nodeadapter_create) () | Creates a component adapter. |
| void [OH_ArkUI_NodeAdapter_Dispose](#oh_arkui_nodeadapter_dispose) ([ArkUI_NodeAdapterHandle](#arkui_nodeadapterhandle) handle) | Destroys a component adapter. |
| int32_t [OH_ArkUI_NodeAdapter_SetTotalNodeCount](#oh_arkui_nodeadapter_settotalnodecount) ([ArkUI_NodeAdapterHandle](#arkui_nodeadapterhandle) handle, uint32_t size) | Sets the total number of elements in the specified adapter. |
| uint32_t [OH_ArkUI_NodeAdapter_GetTotalNodeCount](#oh_arkui_nodeadapter_gettotalnodecount) ([ArkUI_NodeAdapterHandle](#arkui_nodeadapterhandle) handle) | Obtains the total number of elements in the specified adapter. |
| int32_t [OH_ArkUI_NodeAdapter_RegisterEventReceiver](#oh_arkui_nodeadapter_registereventreceiver) ([ArkUI_NodeAdapterHandle](#arkui_nodeadapterhandle) handle, void \*userData, void(\*receiver)([ArkUI_NodeAdapterEvent](#arkui_nodeadapterevent) \*event)) | Registers an event callback for the specified adapter. |
| void [OH_ArkUI_NodeAdapter_UnregisterEventReceiver](#oh_arkui_nodeadapter_unregistereventreceiver) ([ArkUI_NodeAdapterHandle](#arkui_nodeadapterhandle) handle) | Unregisters an event callback for the specified adapter. |
| int32_t [OH_ArkUI_NodeAdapter_ReloadAllItems](#oh_arkui_nodeadapter_reloadallitems) ([ArkUI_NodeAdapterHandle](#arkui_nodeadapterhandle) handle) | Instructs the specified adapter to reload all elements. |
| int32_t [OH_ArkUI_NodeAdapter_ReloadItem](#oh_arkui_nodeadapter_reloaditem) ([ArkUI_NodeAdapterHandle](#arkui_nodeadapterhandle) handle, uint32_t startPosition, uint32_t itemCount) | Instructs the specified adapter to reload certain elements. |
| int32_t [OH_ArkUI_NodeAdapter_RemoveItem](#oh_arkui_nodeadapter_removeitem) ([ArkUI_NodeAdapterHandle](#arkui_nodeadapterhandle) handle, uint32_t startPosition, uint32_t itemCount) | Instructs the specified adapter to remove certain elements. |
| int32_t [OH_ArkUI_NodeAdapter_InsertItem](#oh_arkui_nodeadapter_insertitem) ([ArkUI_NodeAdapterHandle](#arkui_nodeadapterhandle) handle, uint32_t startPosition, uint32_t itemCount) | Instructs the specified adapter to insert certain elements. |
| int32_t [OH_ArkUI_NodeAdapter_MoveItem](#oh_arkui_nodeadapter_moveitem) ([ArkUI_NodeAdapterHandle](#arkui_nodeadapterhandle) handle, uint32_t from, uint32_t to) | Instructs the specified adapter to move certain elements. |
| int32_t [OH_ArkUI_NodeAdapter_GetAllItems](#oh_arkui_nodeadapter_getallitems) ([ArkUI_NodeAdapterHandle](#arkui_nodeadapterhandle) handle, [ArkUI_NodeHandle](#arkui_nodehandle) \*\*items, uint32_t \*size) | Obtains all elements stored in the specified adapter. |
| void \* [OH_ArkUI_NodeAdapterEvent_GetUserData](#oh_arkui_nodeadapterevent_getuserdata) ([ArkUI_NodeAdapterEvent](#arkui_nodeadapterevent) \*event) | Obtains the custom data passed in during registration of the specified event. |
| [ArkUI_NodeAdapterEventType](#arkui_nodeadaptereventtype) [OH_ArkUI_NodeAdapterEvent_GetType](#oh_arkui_nodeadapterevent_gettype) ([ArkUI_NodeAdapterEvent](#arkui_nodeadapterevent) \*event) | Obtains the event type. |
| [ArkUI_NodeHandle](#arkui_nodehandle) [OH_ArkUI_NodeAdapterEvent_GetRemovedNode](#oh_arkui_nodeadapterevent_getremovednode) ([ArkUI_NodeAdapterEvent](#arkui_nodeadapterevent) \*event) | Obtains the element to be removed for the event to be destroyed. |
| uint32_t [OH_ArkUI_NodeAdapterEvent_GetItemIndex](#oh_arkui_nodeadapterevent_getitemindex) ([ArkUI_NodeAdapterEvent](#arkui_nodeadapterevent) \*event) | Obtains the index of the element to be operated for the specified adapter event. |
| [ArkUI_NodeHandle](#arkui_nodehandle) [OH_ArkUI_NodeAdapterEvent_GetHostNode](#oh_arkui_nodeadapterevent_gethostnode) ([ArkUI_NodeAdapterEvent](#arkui_nodeadapterevent) \*event) | Obtains the scrollable container node that uses the specified adapter. |
| int32_t [OH_ArkUI_NodeAdapterEvent_SetItem](#oh_arkui_nodeadapterevent_setitem) ([ArkUI_NodeAdapterEvent](#arkui_nodeadapterevent) \*event, [ArkUI_NodeHandle](#arkui_nodehandle) node) | Sets the component to be added to the specified adapter. |
| int32_t [OH_ArkUI_NodeAdapterEvent_SetNodeId](#oh_arkui_nodeadapterevent_setnodeid) ([ArkUI_NodeAdapterEvent](#arkui_nodeadapterevent) \*event, int32_t id) | Sets the component ID to be generated. |
| [ArkUI_LayoutConstraint](#arkui_layoutconstraint) \* [OH_ArkUI_NodeCustomEvent_GetLayoutConstraintInMeasure](#oh_arkui_nodecustomevent_getlayoutconstraintinmeasure) ([ArkUI_NodeCustomEvent](#arkui_nodecustomevent) \*event) | Obtains the size constraint for measurement through a custom component event. |
| [ArkUI_IntOffset](_ark_u_i___int_offset.md) [OH_ArkUI_NodeCustomEvent_GetPositionInLayout](#oh_arkui_nodecustomevent_getpositioninlayout) ([ArkUI_NodeCustomEvent](#arkui_nodecustomevent) \*event) | Obtains the expected position of a component relative to its parent component in the layout phase through a custom component event. |
| [ArkUI_DrawContext](#arkui_drawcontext) \* [OH_ArkUI_NodeCustomEvent_GetDrawContextInDraw](#oh_arkui_nodecustomevent_getdrawcontextindraw) ([ArkUI_NodeCustomEvent](#arkui_nodecustomevent) \*event) | Obtains the drawing context through a custom component event. |
| int32_t [OH_ArkUI_NodeCustomEvent_GetEventTargetId](#oh_arkui_nodecustomevent_geteventtargetid) ([ArkUI_NodeCustomEvent](#arkui_nodecustomevent) \*event) | Obtains the ID of a custom component event. |
| void \* [OH_ArkUI_NodeCustomEvent_GetUserData](#oh_arkui_nodecustomevent_getuserdata) ([ArkUI_NodeCustomEvent](#arkui_nodecustomevent) \*event) | Obtains custom event parameters through a custom component event. |
| [ArkUI_NodeHandle](#arkui_nodehandle) [OH_ArkUI_NodeCustomEvent_GetNodeHandle](#oh_arkui_nodecustomevent_getnodehandle) ([ArkUI_NodeCustomEvent](#arkui_nodecustomevent) \*event) | Obtains a component object through a custom component event. |
| [ArkUI_NodeCustomEventType](#arkui_nodecustomeventtype) [OH_ArkUI_NodeCustomEvent_GetEventType](#oh_arkui_nodecustomevent_geteventtype) ([ArkUI_NodeCustomEvent](#arkui_nodecustomevent) \*event) | Obtains the event type through a custom component event. |
| int32_t [OH_ArkUI_NodeCustomEvent_GetCustomSpanMeasureInfo](#oh_arkui_nodecustomevent_getcustomspanmeasureinfo) ([ArkUI_NodeCustomEvent](#arkui_nodecustomevent) \*event, [ArkUI_CustomSpanMeasureInfo](#arkui_customspanmeasureinfo) \*info) | Obtains the measurement information of a custom span through a custom component event. |
| int32_t [OH_ArkUI_NodeCustomEvent_SetCustomSpanMetrics](#oh_arkui_nodecustomevent_setcustomspanmetrics) ([ArkUI_NodeCustomEvent](#arkui_nodecustomevent) \*event, [ArkUI_CustomSpanMetrics](#arkui_customspanmetrics) \*metrics) | Sets the measurement metrics of a custom span through a custom component event. |
| int32_t [OH_ArkUI_NodeCustomEvent_GetCustomSpanDrawInfo](#oh_arkui_nodecustomevent_getcustomspandrawinfo) ([ArkUI_NodeCustomEvent](#arkui_nodecustomevent) \*event, [ArkUI_CustomSpanDrawInfo](#arkui_customspandrawinfo) \*info) | Obtains the drawing information of a custom span through a custom component event. |
| int32_t [OH_ArkUI_NodeContent_RegisterCallback](#oh_arkui_nodecontent_registercallback) ([ArkUI_NodeContentHandle](#arkui_nodecontenthandle) content, [ArkUI_NodeContentCallback](#arkui_nodecontentcallback) callback) | Registers the callback for the NodeContent event. |
| [ArkUI_NodeContentEventType](#arkui_nodecontenteventtype) [OH_ArkUI_NodeContentEvent_GetEventType](#oh_arkui_nodecontentevent_geteventtype) ([ArkUI_NodeContentEvent](#arkui_nodecontentevent) \*event) | Obtains the type of the specified NodeContent event. |
| [ArkUI_NodeContentHandle](#arkui_nodecontenthandle) [OH_ArkUI_NodeContentEvent_GetNodeContentHandle](#oh_arkui_nodecontentevent_getnodecontenthandle) ([ArkUI_NodeContentEvent](#arkui_nodecontentevent) \*event) | Obtains the object that triggers the specified NodeContent event. |
| int32_t [OH_ArkUI_NodeContent_SetUserData](#oh_arkui_nodecontent_setuserdata) ([ArkUI_NodeContentHandle](#arkui_nodecontenthandle) content, void \*userData) | Saves custom data to the specified NodeContent object. |
| void \* [OH_ArkUI_NodeContent_GetUserData](#oh_arkui_nodecontent_getuserdata) ([ArkUI_NodeContentHandle](#arkui_nodecontenthandle) content) | Obtains the custom data saved on the specified NodeContent object. |
| int32_t [OH_ArkUI_NodeContent_AddNode](#oh_arkui_nodecontent_addnode) ([ArkUI_NodeContentHandle](#arkui_nodecontenthandle) content, [ArkUI_NodeHandle](#arkui_nodehandle) node) | Adds an ArkUI component node to the specified NodeContent object. |
| int32_t [OH_ArkUI_NodeContent_RemoveNode](#oh_arkui_nodecontent_removenode) ([ArkUI_NodeContentHandle](#arkui_nodecontenthandle) content, [ArkUI_NodeHandle](#arkui_nodehandle) node) | Removes an ArkUI component node from the specified NodeContent object. |
| int32_t [OH_ArkUI_NodeContent_InsertNode](#oh_arkui_nodecontent_insertnode) ([ArkUI_NodeContentHandle](#arkui_nodecontenthandle) content, [ArkUI_NodeHandle](#arkui_nodehandle) node, int32_t position) | Inserts an ArkUI component node into a specific position of the specified NodeContent object. |
| int32_t [OH_ArkUI_NodeUtils_GetLayoutSize](#oh_arkui_nodeutils_getlayoutsize) ([ArkUI_NodeHandle](#arkui_nodehandle) node, [ArkUI_IntSize](_ark_u_i___int_size.md) \*size) | Obtains the layout area size of a component. The size does not count in transformation attributes, such as scale. |
| int32_t [OH_ArkUI_NodeUtils_GetLayoutPosition](#oh_arkui_nodeutils_getlayoutposition) ([ArkUI_NodeHandle](#arkui_nodehandle) node, [ArkUI_IntOffset](_ark_u_i___int_offset.md) \*localOffset) | Obtains the position of the component's layout area relative to its parent component. The relative position does not count in transformation attributes, such as translate. |
| int32_t [OH_ArkUI_NodeUtils_GetLayoutPositionInWindow](#oh_arkui_nodeutils_getlayoutpositioninwindow) ([ArkUI_NodeHandle](#arkui_nodehandle) node, [ArkUI_IntOffset](_ark_u_i___int_offset.md) \*globalOffset) | Obtains the position of the component's layout area relative to the window. The relative position does not count in transformation attributes, such as translate. |
| int32_t [OH_ArkUI_NodeUtils_GetLayoutPositionInScreen](#oh_arkui_nodeutils_getlayoutpositioninscreen) ([ArkUI_NodeHandle](#arkui_nodehandle) node, [ArkUI_IntOffset](_ark_u_i___int_offset.md) \*screenOffset) | Obtains the position of the component's layout area relative to the screen. The relative position does not count in transformation attributes, such as translate. |
| int32_t [OH_ArkUI_NodeUtils_GetPositionWithTranslateInWindow](#oh_arkui_nodeutils_getpositionwithtranslateinwindow) ([ArkUI_NodeHandle](#arkui_nodehandle) node, [ArkUI_IntOffset](_ark_u_i___int_offset.md) \*translateOffset) | Obtains the position of the component in the window, including the translate attribute. |
| int32_t [OH_ArkUI_NodeUtils_GetPositionWithTranslateInScreen](#oh_arkui_nodeutils_getpositionwithtranslateinscreen) ([ArkUI_NodeHandle](#arkui_nodehandle) node, [ArkUI_IntOffset](_ark_u_i___int_offset.md) \*translateOffset) | Obtains the position of the component on the screen, including the translate attribute. |
| int32_t [OH_ArkUI_List_CloseAllSwipeActions](#oh_arkui_list_closeallswipeactions) ([ArkUI_NodeHandle](#arkui_nodehandle) node, void \*userData, void(\*onFinish)(void \*userData)) | Collapses the list items in the expanded state. |
| [ArkUI_ContextHandle](#arkui_contexthandle-12) [OH_ArkUI_GetContextByNode](#oh_arkui_getcontextbynode) ([ArkUI_NodeHandle](#arkui_nodehandle) node) | Obtains the pointer to the UI context object of the specified node. |
| int32_t [OH_ArkUI_RegisterSystemColorModeChangeEvent](#oh_arkui_registersystemcolormodechangeevent) ([ArkUI_NodeHandle](#arkui_nodehandle) node, void \*userData, void(\*onColorModeChange)([ArkUI_SystemColorMode](#arkui_systemcolormode) colorMode, void \*userData)) | Registers an event listener for system color mode changes. A single component can only register one callback for system color mode changes. |
| void [OH_ArkUI_UnregisterSystemColorModeChangeEvent](#oh_arkui_unregistersystemcolormodechangeevent) ([ArkUI_NodeHandle](#arkui_nodehandle) node) | Unregisters the event listener for system color mode changes. |
| int32_t [OH_ArkUI_RegisterSystemFontStyleChangeEvent](#oh_arkui_registersystemfontstylechangeevent) ([ArkUI_NodeHandle](#arkui_nodehandle) node, void \*userData, void(\*onFontStyleChange)([ArkUI_SystemFontStyleEvent](#arkui_systemfontstyleevent) \*event, void \*userData)) | Registers an event listener for system font style changes. A single component can only register one callback for system font style changes. |
| void [OH_ArkUI_UnregisterSystemFontStyleChangeEvent](#oh_arkui_unregistersystemfontstylechangeevent) ([ArkUI_NodeHandle](#arkui_nodehandle) node) | Unregisters the event listener for system font style changes. |
| float [OH_ArkUI_SystemFontStyleEvent_GetFontSizeScale](#oh_arkui_systemfontstyleevent_getfontsizescale) (const [ArkUI_SystemFontStyleEvent](#arkui_systemfontstyleevent) \*event) | Obtains the font size from the system font style change event. |
| float [OH_ArkUI_SystemFontStyleEvent_GetFontWeightScale](#oh_arkui_systemfontstyleevent_getfontweightscale) (const [ArkUI_SystemFontStyleEvent](#arkui_systemfontstyleevent) \*event) | Obtains the font weight from the system font style change event. |
| int32_t [OH_ArkUI_GetNodeHandleFromNapiValue](#oh_arkui_getnodehandlefromnapivalue) (napi_env env, napi_value frameNode, [ArkUI_NodeHandle](#arkui_nodehandle) \*handle) | Obtains a **FrameNode** object on the ArkTS side and maps it to an **ArkUI_NodeHandle** object on the native side. |
| int32_t [OH_ArkUI_GetContextFromNapiValue](#oh_arkui_getcontextfromnapivalue) (napi_env env, napi_value value, [ArkUI_ContextHandle](#arkui_contexthandle-12) \*context) | Obtains a **UIContext** object on the ArkTS side and maps it to an **ArkUI_ContextHandle** object on the native side. |
| int32_t [OH_ArkUI_GetNodeContentFromNapiValue](#oh_arkui_getnodecontentfromnapivalue) (napi_env env, napi_value value, [ArkUI_NodeContentHandle](#arkui_nodecontenthandle) \*content) | Obtains a **NodeContent** object on the ArkTS side and maps it to an **ArkUI_NodeContentHandle** object on the native side. |
| int32_t [OH_ArkUI_GetDrawableDescriptorFromNapiValue](#oh_arkui_getdrawabledescriptorfromnapivalue) (napi_env env, napi_value value, [ArkUI_DrawableDescriptor](#arkui_drawabledescriptor) \*\*drawableDescriptor) | Maps a **DrawableDescriptor** object on the ArkTS side to an **ArkUI_DrawableDescriptor** object on the native side. |
| int32_t [OH_ArkUI_GetDrawableDescriptorFromResourceNapiValue](#oh_arkui_getdrawabledescriptorfromresourcenapivalue) (napi_env env, napi_value value, [ArkUI_DrawableDescriptor](#arkui_drawabledescriptor) \*\*drawableDescriptor) | Maps an $r resource object on the ArkTS side to an **ArkUI_DrawableDescriptor** object on the native side. |
| [ArkUI_ErrorCode](#arkui_errorcode) [OH_ArkUI_GetNavigationId](#oh_arkui_getnavigationid) ([ArkUI_NodeHandle](#arkui_nodehandle) node, char \*buffer, int32_t bufferSize, int32_t \*writeLength) | Obtains the ID of the **Navigation** component where the specified node is located. |
| [ArkUI_ErrorCode](#arkui_errorcode) [OH_ArkUI_GetNavDestinationName](#oh_arkui_getnavdestinationname) ([ArkUI_NodeHandle](#arkui_nodehandle) node, char \*buffer, int32_t bufferSize, int32_t \*writeLength) | Obtains the name of the **NavDestination** component where the specified node is located. |
| [ArkUI_ErrorCode](#arkui_errorcode) [OH_ArkUI_GetNavStackLength](#oh_arkui_getnavstacklength) ([ArkUI_NodeHandle](#arkui_nodehandle) node, int32_t \*length) | Obtains the length of the navigation stack where the specified node is located. |
| [ArkUI_ErrorCode](#arkui_errorcode) [OH_ArkUI_GetNavDestinationNameByIndex](#oh_arkui_getnavdestinationnamebyindex) ([ArkUI_NodeHandle](#arkui_nodehandle) node, int32_t index, char \*buffer, int32_t bufferSize, int32_t \*writeLength) | Obtains the page name that matches the specified index in the navigation stack where the specified node is located. The index starts from 0, which indicates the bottom of the stack. |
| [ArkUI_ErrorCode](#arkui_errorcode) [OH_ArkUI_GetNavDestinationId](#oh_arkui_getnavdestinationid) ([ArkUI_NodeHandle](#arkui_nodehandle) node, char \*buffer, int32_t bufferSize, int32_t \*writeLength) | Obtains the ID of the **NavDestination** component where the specified node is located. |
| [ArkUI_ErrorCode](#arkui_errorcode) [OH_ArkUI_GetNavDestinationState](#oh_arkui_getnavdestinationstate) ([ArkUI_NodeHandle](#arkui_nodehandle) node, [ArkUI_NavDestinationState](#arkui_navdestinationstate) \*state) | Obtains the state of the **NavDestination** component where the specified node is located. |
| [ArkUI_ErrorCode](#arkui_errorcode) [OH_ArkUI_GetNavDestinationIndex](#oh_arkui_getnavdestinationindex) ([ArkUI_NodeHandle](#arkui_nodehandle) node, int32_t \*index) | Obtains the index of the **NavDestination** component where the specified node is located in the navigation stack. |
| napi_value [OH_ArkUI_GetNavDestinationParam](#oh_arkui_getnavdestinationparam) ([ArkUI_NodeHandle](#arkui_nodehandle) node) | Obtains the parameters of the **NavDestination** component where the specified node is located. |
| [ArkUI_ErrorCode](#arkui_errorcode) [OH_ArkUI_GetRouterPageIndex](#oh_arkui_getrouterpageindex) ([ArkUI_NodeHandle](#arkui_nodehandle) node, int32_t \*index) | Obtains the index of the page where the specified node is located in the page stack for routing. |
| [ArkUI_ErrorCode](#arkui_errorcode) [OH_ArkUI_GetRouterPageName](#oh_arkui_getrouterpagename) ([ArkUI_NodeHandle](#arkui_nodehandle) node, char \*buffer, int32_t bufferSize, int32_t \*writeLength) | Obtains the name of the page where the specified node is located. |
| [ArkUI_ErrorCode](#arkui_errorcode) [OH_ArkUI_GetRouterPagePath](#oh_arkui_getrouterpagepath) ([ArkUI_NodeHandle](#arkui_nodehandle) node, char \*buffer, int32_t bufferSize, int32_t \*writeLength) | Obtains the path to the page where the specified node is located. |
| [ArkUI_ErrorCode](#arkui_errorcode) [OH_ArkUI_GetRouterPageState](#oh_arkui_getrouterpagestate) ([ArkUI_NodeHandle](#arkui_nodehandle) node, [ArkUI_RouterPageState](#arkui_routerpagestate) \*state) | Obtains the state of the page where the specified node is located. |
| [ArkUI_ErrorCode](#arkui_errorcode) [OH_ArkUI_GetRouterPageId](#oh_arkui_getrouterpageid) ([ArkUI_NodeHandle](#arkui_nodehandle) node, char \*buffer, int32_t bufferSize, int32_t \*writeLength) | Obtains the ID of the page where the specified node is located. |
| [ArkUI_LayoutConstraint](#arkui_layoutconstraint) \* [OH_ArkUI_LayoutConstraint_Create](#oh_arkui_layoutconstraint_create) () | Creates a size constraint. |
| [ArkUI_LayoutConstraint](#arkui_layoutconstraint) \* [OH_ArkUI_LayoutConstraint_Copy](#oh_arkui_layoutconstraint_copy) (const [ArkUI_LayoutConstraint](#arkui_layoutconstraint) \*Constraint) | Performs a deep copy of a size constraint. |
| void \* [OH_ArkUI_LayoutConstraint_Dispose](#oh_arkui_layoutconstraint_dispose) ([ArkUI_LayoutConstraint](#arkui_layoutconstraint) \*Constraint) | Disposes of the pointer to a size constraint. |
| int32_t [OH_ArkUI_LayoutConstraint_GetMaxWidth](#oh_arkui_layoutconstraint_getmaxwidth) (const [ArkUI_LayoutConstraint](#arkui_layoutconstraint) \*Constraint) | Obtains the maximum width for a size constraint, in px. |
| int32_t [OH_ArkUI_LayoutConstraint_GetMinWidth](#oh_arkui_layoutconstraint_getminwidth) (const [ArkUI_LayoutConstraint](#arkui_layoutconstraint) \*Constraint) | Obtains the minimum width for a size constraint, in px. |
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
| void \* [OH_ArkUI_DrawContext_GetCanvas](#oh_arkui_drawcontext_getcanvas) ([ArkUI_DrawContext](#arkui_drawcontext) \*context) | Obtains the pointer to a canvas for drawing, which can be converted into the **OH_Drawing_Canvas** in the **Drawing** module. |
| [ArkUI_IntSize](_ark_u_i___int_size.md) [OH_ArkUI_DrawContext_GetSize](#oh_arkui_drawcontext_getsize) ([ArkUI_DrawContext](#arkui_drawcontext) \*context) | Obtains the size of a drawing area. |
| [ArkUI_WaterFlowSectionOption](#arkui_waterflowsectionoption) \* [OH_ArkUI_WaterFlowSectionOption_Create](#oh_arkui_waterflowsectionoption_create) () | Creates a water flow section configuration. |
| void [OH_ArkUI_WaterFlowSectionOption_Dispose](#oh_arkui_waterflowsectionoption_dispose) ([ArkUI_WaterFlowSectionOption](#arkui_waterflowsectionoption) \*option) | Disposes of the pointer to a water flow section configuration. |
| void [OH_ArkUI_WaterFlowSectionOption_SetSize](#oh_arkui_waterflowsectionoption_setsize) ([ArkUI_WaterFlowSectionOption](#arkui_waterflowsectionoption) \*option, int32_t size) | Sets the array length for a water flow section configuration. |
| int32_t [OH_ArkUI_WaterFlowSectionOption_GetSize](#oh_arkui_waterflowsectionoption_getsize) ([ArkUI_WaterFlowSectionOption](#arkui_waterflowsectionoption) \*option) | Sets the array length for a water flow section configuration. |
| void [OH_ArkUI_WaterFlowSectionOption_SetItemCount](#oh_arkui_waterflowsectionoption_setitemcount) ([ArkUI_WaterFlowSectionOption](#arkui_waterflowsectionoption) \*option, int32_t index, int32_t itemCount) | Sets the number of items in a water flow section. |
| int32_t [OH_ArkUI_WaterFlowSectionOption_GetItemCount](#oh_arkui_waterflowsectionoption_getitemcount) ([ArkUI_WaterFlowSectionOption](#arkui_waterflowsectionoption) \*option, int32_t index) | Obtains the number of items in the water flow section that matches the specified index. |
| void [OH_ArkUI_WaterFlowSectionOption_SetCrossCount](#oh_arkui_waterflowsectionoption_setcrosscount) ([ArkUI_WaterFlowSectionOption](#arkui_waterflowsectionoption) \*option, int32_t index, int32_t crossCount) | Sets the number of columns (in a vertical layout) or rows (in a horizontal layout) of a water flow. |
| int32_t [OH_ArkUI_WaterFlowSectionOption_GetCrossCount](#oh_arkui_waterflowsectionoption_getcrosscount) ([ArkUI_WaterFlowSectionOption](#arkui_waterflowsectionoption) \*option, int32_t index) | Obtains the number of columns (in a vertical layout) or rows (in a horizontal layout) of a water flow. |
| void [OH_ArkUI_WaterFlowSectionOption_SetColumnGap](#oh_arkui_waterflowsectionoption_setcolumngap) ([ArkUI_WaterFlowSectionOption](#arkui_waterflowsectionoption) \*, int32_t index, float columnGap) | Sets the gap between columns in the specified water flow section. |
| float [OH_ArkUI_WaterFlowSectionOption_GetColumnGap](#oh_arkui_waterflowsectionoption_getcolumngap) ([ArkUI_WaterFlowSectionOption](#arkui_waterflowsectionoption) \*option, int32_t index) | Obtains the gap between columns in the water flow section that matches the specified index. |
| void [OH_ArkUI_WaterFlowSectionOption_SetRowGap](#oh_arkui_waterflowsectionoption_setrowgap) ([ArkUI_WaterFlowSectionOption](#arkui_waterflowsectionoption) \*option, int32_t index, float rowGap) | Sets the gap between rows in the specified water flow section. |
| float [OH_ArkUI_WaterFlowSectionOption_GetRowGap](#oh_arkui_waterflowsectionoption_getrowgap) ([ArkUI_WaterFlowSectionOption](#arkui_waterflowsectionoption) \*option, int32_t index) | Obtains the gap between rows in the water flow section that matches the specified index. |
| void [OH_ArkUI_WaterFlowSectionOption_SetMargin](#oh_arkui_waterflowsectionoption_setmargin) ([ArkUI_WaterFlowSectionOption](#arkui_waterflowsectionoption) \*option, int32_t index, float marginTop, float marginRight, float marginBottom, float marginLeft) | Sets the margins for the specified water flow section. |
| [ArkUI_Margin](_ark_u_i___margin.md) [OH_ArkUI_WaterFlowSectionOption_GetMargin](#oh_arkui_waterflowsectionoption_getmargin) ([ArkUI_WaterFlowSectionOption](#arkui_waterflowsectionoption) \*option, int32_t index) | Obtains the margins of the water flow section that matches the specified index. |
| void [OH_ArkUI_WaterFlowSectionOption_RegisterGetItemMainSizeCallbackByIndex](#oh_arkui_waterflowsectionoption_registergetitemmainsizecallbackbyindex) ([ArkUI_WaterFlowSectionOption](#arkui_waterflowsectionoption) \*option, int32_t index, float(\*callback)(int32_t itemIndex)) | Obtains the main axis size of a specified item based on **flowItemIndex** through a water flow section configuration. |
| void [OH_ArkUI_WaterFlowSectionOption_RegisterGetItemMainSizeCallbackByIndexWithUserData](#oh_arkui_waterflowsectionoption_registergetitemmainsizecallbackbyindexwithuserdata) ([ArkUI_WaterFlowSectionOption](#arkui_waterflowsectionoption) \*option, int32_t index, void \*userData, float(\*callback)(int32_t itemIndex, void \*userData)) | Obtains the main axis size of a specified item based on **flowItemIndex** through a water flow section configuration. |
| [ArkUI_GuidelineOption](#arkui_guidelineoption) \* [OH_ArkUI_GuidelineOption_Create](#oh_arkui_guidelineoption_create) (int32_t size) | Creates a guideline configuration for this **RelativeContainer** component. |
| void [OH_ArkUI_GuidelineOption_Dispose](#oh_arkui_guidelineoption_dispose) ([ArkUI_GuidelineOption](#arkui_guidelineoption) \*guideline) | Disposes of a guideline configuration. |
| void [OH_ArkUI_GuidelineOption_SetId](#oh_arkui_guidelineoption_setid) ([ArkUI_GuidelineOption](#arkui_guidelineoption) \*guideline, const char \*value, int32_t index) | Sets the ID of a guideline. |
| void [OH_ArkUI_GuidelineOption_SetDirection](#oh_arkui_guidelineoption_setdirection) ([ArkUI_GuidelineOption](#arkui_guidelineoption) \*guideline, [ArkUI_Axis](#arkui_axis) value, int32_t index) | Sets the direction of a guideline. |
| void [OH_ArkUI_GuidelineOption_SetPositionStart](#oh_arkui_guidelineoption_setpositionstart) ([ArkUI_GuidelineOption](#arkui_guidelineoption) \*guideline, float value, int32_t index) | Sets the distance between a guideline and the left or top of the container. |
| void [OH_ArkUI_GuidelineOption_SetPositionEnd](#oh_arkui_guidelineoption_setpositionend) ([ArkUI_GuidelineOption](#arkui_guidelineoption) \*guideline, float value, int32_t index) | Sets the distance between a guideline and the right or bottom of the container. |
| const char \* [OH_ArkUI_GuidelineOption_GetId](#oh_arkui_guidelineoption_getid) ([ArkUI_GuidelineOption](#arkui_guidelineoption) \*guideline, int32_t index) | Obtains the ID of a guideline. |
| [ArkUI_Axis](#arkui_axis) [OH_ArkUI_GuidelineOption_GetDirection](#oh_arkui_guidelineoption_getdirection) ([ArkUI_GuidelineOption](#arkui_guidelineoption) \*guideline, int32_t index) | Obtains the direction of a guideline. |
| float [OH_ArkUI_GuidelineOption_GetPositionStart](#oh_arkui_guidelineoption_getpositionstart) ([ArkUI_GuidelineOption](#arkui_guidelineoption) \*guideline, int32_t index) | Obtains the distance between a guideline and the left or top of the container. |
| float [OH_ArkUI_GuidelineOption_GetPositionEnd](#oh_arkui_guidelineoption_getpositionend) ([ArkUI_GuidelineOption](#arkui_guidelineoption) \*guideline, int32_t index) | Obtains the distance between a guideline and the right or bottom of the container. |
| [ArkUI_BarrierOption](#arkui_barrieroption) \* [OH_ArkUI_BarrierOption_Create](#oh_arkui_barrieroption_create) (int32_t size) | Creates a barrier configuration for this **RelativeContainer** component. |
| void [OH_ArkUI_BarrierOption_Dispose](#oh_arkui_barrieroption_dispose) ([ArkUI_BarrierOption](#arkui_barrieroption) \*barrierStyle) | Disposes of a barrier configuration. |
| void [OH_ArkUI_BarrierOption_SetId](#oh_arkui_barrieroption_setid) ([ArkUI_BarrierOption](#arkui_barrieroption) \*barrierStyle, const char \*value, int32_t index) | Sets the ID of a barrier. |
| void [OH_ArkUI_BarrierOption_SetDirection](#oh_arkui_barrieroption_setdirection) ([ArkUI_BarrierOption](#arkui_barrieroption) \*barrierStyle, [ArkUI_BarrierDirection](#arkui_barrierdirection) value, int32_t index) | Sets the direction of a barrier. |
| void [OH_ArkUI_BarrierOption_SetReferencedId](#oh_arkui_barrieroption_setreferencedid) ([ArkUI_BarrierOption](#arkui_barrieroption) \*barrierStyle, const char \*value, int32_t index) | Sets the referenced components of a barrier. |
| const char \* [OH_ArkUI_BarrierOption_GetId](#oh_arkui_barrieroption_getid) ([ArkUI_BarrierOption](#arkui_barrieroption) \*barrierStyle, int32_t index) | Obtains the ID of a barrier. |
| [ArkUI_BarrierDirection](#arkui_barrierdirection) [OH_ArkUI_BarrierOption_GetDirection](#oh_arkui_barrieroption_getdirection) ([ArkUI_BarrierOption](#arkui_barrieroption) \*barrierStyle, int32_t index) | Obtains the direction of a barrier. |
| const char \* [OH_ArkUI_BarrierOption_GetReferencedId](#oh_arkui_barrieroption_getreferencedid) ([ArkUI_BarrierOption](#arkui_barrieroption) \*barrierStyle, int32_t index, int32_t referencedIndex) | Obtains the referenced components of a barrier. |
| int32_t [OH_ArkUI_BarrierOption_GetReferencedIdSize](#oh_arkui_barrieroption_getreferencedidsize) ([ArkUI_BarrierOption](#arkui_barrieroption) \*barrierStyle, int32_t index) | Obtains the number of referenced components of a barrier. |
| [ArkUI_AlignmentRuleOption](#arkui_alignmentruleoption) \* [OH_ArkUI_AlignmentRuleOption_Create](#oh_arkui_alignmentruleoption_create) () | Creates an alignment rule configuration for this **RelativeContainer** component. |
| void [OH_ArkUI_AlignmentRuleOption_Dispose](#oh_arkui_alignmentruleoption_dispose) ([ArkUI_AlignmentRuleOption](#arkui_alignmentruleoption) \*option) | Disposes of an alignment rule configuration of this **RelativeContainer** component. |
| void [OH_ArkUI_AlignmentRuleOption_SetStart](#oh_arkui_alignmentruleoption_setstart) ([ArkUI_AlignmentRuleOption](#arkui_alignmentruleoption) \*option, const char \*id, [ArkUI_HorizontalAlignment](#arkui_horizontalalignment) alignment) | Sets the left alignment parameters. |
| void [OH_ArkUI_AlignmentRuleOption_SetEnd](#oh_arkui_alignmentruleoption_setend) ([ArkUI_AlignmentRuleOption](#arkui_alignmentruleoption) \*option, const char \*id, [ArkUI_HorizontalAlignment](#arkui_horizontalalignment) alignment) | Sets the right alignment parameters. |
| void [OH_ArkUI_AlignmentRuleOption_SetCenterHorizontal](#oh_arkui_alignmentruleoption_setcenterhorizontal) ([ArkUI_AlignmentRuleOption](#arkui_alignmentruleoption) \*option, const char \*id, [ArkUI_HorizontalAlignment](#arkui_horizontalalignment) alignment) | Sets the horizontal center alignment parameters. |
| void [OH_ArkUI_AlignmentRuleOption_SetTop](#oh_arkui_alignmentruleoption_settop) ([ArkUI_AlignmentRuleOption](#arkui_alignmentruleoption) \*option, const char \*id, [ArkUI_VerticalAlignment](#arkui_verticalalignment) alignment) | Sets the top alignment parameters. |
| void [OH_ArkUI_AlignmentRuleOption_SetBottom](#oh_arkui_alignmentruleoption_setbottom) ([ArkUI_AlignmentRuleOption](#arkui_alignmentruleoption) \*option, const char \*id, [ArkUI_VerticalAlignment](#arkui_verticalalignment) alignment) | Sets the bottom alignment parameters. |
| void [OH_ArkUI_AlignmentRuleOption_SetCenterVertical](#oh_arkui_alignmentruleoption_setcentervertical) ([ArkUI_AlignmentRuleOption](#arkui_alignmentruleoption) \*option, const char \*id, [ArkUI_VerticalAlignment](#arkui_verticalalignment) alignment) | Sets the vertical center alignment parameters. |
| void [OH_ArkUI_AlignmentRuleOption_SetBiasHorizontal](#oh_arkui_alignmentruleoption_setbiashorizontal) ([ArkUI_AlignmentRuleOption](#arkui_alignmentruleoption) \*option, float horizontal) | Sets the bias value of the component in the horizontal direction under the anchor constraints. |
| void [OH_ArkUI_AlignmentRuleOption_SetBiasVertical](#oh_arkui_alignmentruleoption_setbiasvertical) ([ArkUI_AlignmentRuleOption](#arkui_alignmentruleoption) \*option, float vertical) | Sets the bias value of the component in the vertical direction under the anchor constraints. |
| const char \* [OH_ArkUI_AlignmentRuleOption_GetStartId](#oh_arkui_alignmentruleoption_getstartid) ([ArkUI_AlignmentRuleOption](#arkui_alignmentruleoption) \*option) | Obtains the ID in the left alignment parameters. |
| [ArkUI_HorizontalAlignment](#arkui_horizontalalignment) [OH_ArkUI_AlignmentRuleOption_GetStartAlignment](#oh_arkui_alignmentruleoption_getstartalignment) ([ArkUI_AlignmentRuleOption](#arkui_alignmentruleoption) \*option) | Obtains the alignment mode in left alignment parameters. |
| const char \* [OH_ArkUI_AlignmentRuleOption_GetEndId](#oh_arkui_alignmentruleoption_getendid) ([ArkUI_AlignmentRuleOption](#arkui_alignmentruleoption) \*option) | Obtains the ID in the right alignment parameters. |
| [ArkUI_HorizontalAlignment](#arkui_horizontalalignment) [OH_ArkUI_AlignmentRuleOption_GetEndAlignment](#oh_arkui_alignmentruleoption_getendalignment) ([ArkUI_AlignmentRuleOption](#arkui_alignmentruleoption) \*option) | Obtains the ID in the right alignment parameters. |
| const char \* [OH_ArkUI_AlignmentRuleOption_GetCenterIdHorizontal](#oh_arkui_alignmentruleoption_getcenteridhorizontal) ([ArkUI_AlignmentRuleOption](#arkui_alignmentruleoption) \*option) | Obtains the ID in horizontal center alignment parameters. |
| [ArkUI_HorizontalAlignment](#arkui_horizontalalignment) [OH_ArkUI_AlignmentRuleOption_GetCenterAlignmentHorizontal](#oh_arkui_alignmentruleoption_getcenteralignmenthorizontal) ([ArkUI_AlignmentRuleOption](#arkui_alignmentruleoption) \*option) | Obtains the ID in horizontal center alignment parameters. |
| const char \* [OH_ArkUI_AlignmentRuleOption_GetTopId](#oh_arkui_alignmentruleoption_gettopid) ([ArkUI_AlignmentRuleOption](#arkui_alignmentruleoption) \*option) | Obtains the ID in top alignment parameters. |
| [ArkUI_VerticalAlignment](#arkui_verticalalignment) [OH_ArkUI_AlignmentRuleOption_GetTopAlignment](#oh_arkui_alignmentruleoption_gettopalignment) ([ArkUI_AlignmentRuleOption](#arkui_alignmentruleoption) \*option) | Obtains the ID in top alignment parameters. |
| const char \* [OH_ArkUI_AlignmentRuleOption_GetBottomId](#oh_arkui_alignmentruleoption_getbottomid) ([ArkUI_AlignmentRuleOption](#arkui_alignmentruleoption) \*option) | Obtains the ID in bottom alignment parameters. |
| [ArkUI_VerticalAlignment](#arkui_verticalalignment) [OH_ArkUI_AlignmentRuleOption_GetBottomAlignment](#oh_arkui_alignmentruleoption_getbottomalignment) ([ArkUI_AlignmentRuleOption](#arkui_alignmentruleoption) \*option) | Obtains the ID in bottom alignment parameters. |
| const char \* [OH_ArkUI_AlignmentRuleOption_GetCenterIdVertical](#oh_arkui_alignmentruleoption_getcenteridvertical) ([ArkUI_AlignmentRuleOption](#arkui_alignmentruleoption) \*option) | Obtains the ID in vertical center alignment parameters. |
| [ArkUI_VerticalAlignment](#arkui_verticalalignment) [OH_ArkUI_AlignmentRuleOption_GetCenterAlignmentVertical](#oh_arkui_alignmentruleoption_getcenteralignmentvertical) ([ArkUI_AlignmentRuleOption](#arkui_alignmentruleoption) \*option) | Obtains the ID in vertical center alignment parameters. |
| float [OH_ArkUI_AlignmentRuleOption_GetBiasHorizontal](#oh_arkui_alignmentruleoption_getbiashorizontal) ([ArkUI_AlignmentRuleOption](#arkui_alignmentruleoption) \*option) | Obtains the bias value in the horizontal direction. |
| float [OH_ArkUI_AlignmentRuleOption_GetBiasVertical](#oh_arkui_alignmentruleoption_getbiasvertical) ([ArkUI_AlignmentRuleOption](#arkui_alignmentruleoption) \*option) | Obtains the bias value in the vertical direction. |
| [ArkUI_SwiperIndicator](#arkui_swiperindicator) \* [OH_ArkUI_SwiperIndicator_Create](#oh_arkui_swiperindicator_create) ([ArkUI_SwiperIndicatorType](#arkui_swiperindicatortype) type) | Creates a navigation point indicator for this **Swiper** component. |
| void [OH_ArkUI_SwiperIndicator_Dispose](#oh_arkui_swiperindicator_dispose) ([ArkUI_SwiperIndicator](#arkui_swiperindicator) \*indicator) | Disposes of the navigation point indicator of this **Swiper** component. |
| void [OH_ArkUI_SwiperIndicator_SetStartPosition](#oh_arkui_swiperindicator_setstartposition) ([ArkUI_SwiperIndicator](#arkui_swiperindicator) \*indicator, float value) | Sets the distance between the navigation point indicator and the left edge of the **Swiper** component. |
| float [OH_ArkUI_SwiperIndicator_GetStartPosition](#oh_arkui_swiperindicator_getstartposition) ([ArkUI_SwiperIndicator](#arkui_swiperindicator) \*indicator) | Obtains the distance between a navigation point indicator and the left edge of the **Swiper** component. |
| void [OH_ArkUI_SwiperIndicator_SetTopPosition](#oh_arkui_swiperindicator_settopposition) ([ArkUI_SwiperIndicator](#arkui_swiperindicator) \*indicator, float value) | Sets the distance between the navigation point indicator and the top edge of the **Swiper** component. |
| float [OH_ArkUI_SwiperIndicator_GetTopPosition](#oh_arkui_swiperindicator_gettopposition) ([ArkUI_SwiperIndicator](#arkui_swiperindicator) \*indicator) | Obtains the distance between the navigation point indicator and the top edge of the **Swiper** component. |
| void [OH_ArkUI_SwiperIndicator_SetEndPosition](#oh_arkui_swiperindicator_setendposition) ([ArkUI_SwiperIndicator](#arkui_swiperindicator) \*indicator, float value) | Sets the distance between the navigation point indicator and the right edge of the **Swiper** component. |
| float [OH_ArkUI_SwiperIndicator_GetEndPosition](#oh_arkui_swiperindicator_getendposition) ([ArkUI_SwiperIndicator](#arkui_swiperindicator) \*indicator) | Obtains the distance between the navigation point indicator and the right edge of the **Swiper** component. |
| void [OH_ArkUI_SwiperIndicator_SetBottomPosition](#oh_arkui_swiperindicator_setbottomposition) ([ArkUI_SwiperIndicator](#arkui_swiperindicator) \*indicator, float value) | Sets the distance between the navigation point indicator and the bottom edge of the **Swiper** component. |
| float [OH_ArkUI_SwiperIndicator_GetBottomPosition](#oh_arkui_swiperindicator_getbottomposition) ([ArkUI_SwiperIndicator](#arkui_swiperindicator) \*indicator) | Obtains the distance between the navigation point indicator and the bottom edge of the **Swiper** component. |
| void [OH_ArkUI_SwiperIndicator_SetItemWidth](#oh_arkui_swiperindicator_setitemwidth) ([ArkUI_SwiperIndicator](#arkui_swiperindicator) \*indicator, float value) | Sets the width of a navigation point indicator of the dot style for the **Swiper** component. |
| float [OH_ArkUI_SwiperIndicator_GetItemWidth](#oh_arkui_swiperindicator_getitemwidth) ([ArkUI_SwiperIndicator](#arkui_swiperindicator) \*indicator) | Obtains the width of a navigation point indicator of the dot style of the **Swiper** component. |
| void [OH_ArkUI_SwiperIndicator_SetItemHeight](#oh_arkui_swiperindicator_setitemheight) ([ArkUI_SwiperIndicator](#arkui_swiperindicator) \*indicator, float value) | Sets the height of a navigation point indicator of the dot style for the **Swiper** component. |
| float [OH_ArkUI_SwiperIndicator_GetItemHeight](#oh_arkui_swiperindicator_getitemheight) ([ArkUI_SwiperIndicator](#arkui_swiperindicator) \*indicator) | Obtains the height of a navigation point indicator of the dot style of the **Swiper** component. |
| void [OH_ArkUI_SwiperIndicator_SetSelectedItemWidth](#oh_arkui_swiperindicator_setselecteditemwidth) ([ArkUI_SwiperIndicator](#arkui_swiperindicator) \*indicator, float value) | Sets the width of the selected navigation point indicator of the dot style for the **Swiper** component. |
| float [OH_ArkUI_SwiperIndicator_GetSelectedItemWidth](#oh_arkui_swiperindicator_getselecteditemwidth) ([ArkUI_SwiperIndicator](#arkui_swiperindicator) \*indicator) | Obtains the width of the selected navigation point indicator of the dot style of the **Swiper** component. |
| void [OH_ArkUI_SwiperIndicator_SetSelectedItemHeight](#oh_arkui_swiperindicator_setselecteditemheight) ([ArkUI_SwiperIndicator](#arkui_swiperindicator) \*indicator, float value) | Sets the height of the selected navigation point indicator of the dot style for the **Swiper** component. |
| float [OH_ArkUI_SwiperIndicator_GetSelectedItemHeight](#oh_arkui_swiperindicator_getselecteditemheight) ([ArkUI_SwiperIndicator](#arkui_swiperindicator) \*indicator) | Obtains the height of the selected navigation point indicator of the dot style of the **Swiper** component. |
| void [OH_ArkUI_SwiperIndicator_SetMask](#oh_arkui_swiperindicator_setmask) ([ArkUI_SwiperIndicator](#arkui_swiperindicator) \*indicator, int32_t mask) | Sets whether to enable the mask for a navigation point indicator of the dot style for the **Swiper** component. |
| int32_t [OH_ArkUI_SwiperIndicator_GetMask](#oh_arkui_swiperindicator_getmask) ([ArkUI_SwiperIndicator](#arkui_swiperindicator) \*indicator) | Obtains whether the mask is enabled for a navigation point indicator of the dot style of the **Swiper** component. |
| void [OH_ArkUI_SwiperIndicator_SetColor](#oh_arkui_swiperindicator_setcolor) ([ArkUI_SwiperIndicator](#arkui_swiperindicator) \*indicator, uint32_t color) | Sets the color of a navigation point indicator of the dot style for the **Swiper** component. |
| uint32_t [OH_ArkUI_SwiperIndicator_GetColor](#oh_arkui_swiperindicator_getcolor) ([ArkUI_SwiperIndicator](#arkui_swiperindicator) \*indicator) | Obtains the color of a navigation point indicator of the dot style of the **Swiper** component. |
| void [OH_ArkUI_SwiperIndicator_SetSelectedColor](#oh_arkui_swiperindicator_setselectedcolor) ([ArkUI_SwiperIndicator](#arkui_swiperindicator) \*indicator, uint32_t selectedColor) | Sets the color of the selected navigation point indicator of the dot style for the **Swiper** component. |
| uint32_t [OH_ArkUI_SwiperIndicator_GetSelectedColor](#oh_arkui_swiperindicator_getselectedcolor) ([ArkUI_SwiperIndicator](#arkui_swiperindicator) \*indicator) | Obtains the color of the selected navigation point indicator of the dot style of the **Swiper** component. |
| int32_t [OH_ArkUI_SwiperIndicator_SetMaxDisplayCount](#oh_arkui_swiperindicator_setmaxdisplaycount) ([ArkUI_SwiperIndicator](#arkui_swiperindicator) \*indicator, int32_t maxDisplayCount) | Sets the maximum number of dots for the navigation point indicator of the dot style. |
| int32_t [OH_ArkUI_SwiperIndicator_GetMaxDisplayCount](#oh_arkui_swiperindicator_getmaxdisplaycount) ([ArkUI_SwiperIndicator](#arkui_swiperindicator) \*indicator) | Obtains the maximum number of points for the navigation point indicator. |
| [ArkUI_ListItemSwipeActionItem](#arkui_listitemswipeactionitem) \* [OH_ArkUI_ListItemSwipeActionItem_Create](#oh_arkui_listitemswipeactionitem_create) () | Creates a **ListItemSwipeActionItem** instance. |
| void [OH_ArkUI_ListItemSwipeActionItem_Dispose](#oh_arkui_listitemswipeactionitem_dispose) ([ArkUI_ListItemSwipeActionItem](#arkui_listitemswipeactionitem) \*item) | Disposes of a **ListItemSwipeActionItem** instance. |
| void [OH_ArkUI_ListItemSwipeActionItem_SetContent](#oh_arkui_listitemswipeactionitem_setcontent) ([ArkUI_ListItemSwipeActionItem](#arkui_listitemswipeactionitem) \*item, [ArkUI_NodeHandle](#arkui_nodehandle) node) | Sets the layout content for a **ListItemSwipeActionItem** instance. |
| void [OH_ArkUI_ListItemSwipeActionItem_SetActionAreaDistance](#oh_arkui_listitemswipeactionitem_setactionareadistance) ([ArkUI_ListItemSwipeActionItem](#arkui_listitemswipeactionitem) \*item, float distance) | Sets the swipe distance threshold for deleting the list item. |
| float [OH_ArkUI_ListItemSwipeActionItem_GetActionAreaDistance](#oh_arkui_listitemswipeactionitem_getactionareadistance) ([ArkUI_ListItemSwipeActionItem](#arkui_listitemswipeactionitem) \*item) | Obtains the swipe distance threshold for deleting the list item. |
| void [OH_ArkUI_ListItemSwipeActionItem_SetOnEnterActionArea](#oh_arkui_listitemswipeactionitem_setonenteractionarea) ([ArkUI_ListItemSwipeActionItem](#arkui_listitemswipeactionitem) \*item, void(\*callback)()) | Sets the callback invoked each time the list item enters the delete area. |
| void [OH_ArkUI_ListItemSwipeActionItem_SetOnEnterActionAreaWithUserData](#oh_arkui_listitemswipeactionitem_setonenteractionareawithuserdata) ([ArkUI_ListItemSwipeActionItem](#arkui_listitemswipeactionitem) \*item, void \*userData, void(\*callback)(void \*userData)) | Sets the callback invoked each time the list item enters the delete area. |
| void [OH_ArkUI_ListItemSwipeActionItem_SetOnAction](#oh_arkui_listitemswipeactionitem_setonaction) ([ArkUI_ListItemSwipeActionItem](#arkui_listitemswipeactionitem) \*item, void(\*callback)()) | Sets the callback invoked when the list item is deleted while in the delete area. |
| void [OH_ArkUI_ListItemSwipeActionItem_SetOnActionWithUserData](#oh_arkui_listitemswipeactionitem_setonactionwithuserdata) ([ArkUI_ListItemSwipeActionItem](#arkui_listitemswipeactionitem) \*item, void \*userData, void(\*callback)(void \*userData)) | Sets the callback invoked when the list item is deleted while in the delete area. |
| void [OH_ArkUI_ListItemSwipeActionItem_SetOnExitActionArea](#oh_arkui_listitemswipeactionitem_setonexitactionarea) ([ArkUI_ListItemSwipeActionItem](#arkui_listitemswipeactionitem) \*item, void(\*callback)()) | Sets the callback invoked each time the list item exits the delete area. |
| void [OH_ArkUI_ListItemSwipeActionItem_SetOnExitActionAreaWithUserData](#oh_arkui_listitemswipeactionitem_setonexitactionareawithuserdata) ([ArkUI_ListItemSwipeActionItem](#arkui_listitemswipeactionitem) \*item, void \*userData, void(\*callback)(void \*userData)) | Sets the callback invoked each time the list item exits the delete area. |
| void [OH_ArkUI_ListItemSwipeActionItem_SetOnStateChange](#oh_arkui_listitemswipeactionitem_setonstatechange) ([ArkUI_ListItemSwipeActionItem](#arkui_listitemswipeactionitem) \*item, void(\*callback)([ArkUI_ListItemSwipeActionState](#arkui_listitemswipeactionstate) swipeActionState)) | Sets the callback invoked when the swipe state of the list item changes. |
| void [OH_ArkUI_ListItemSwipeActionItem_SetOnStateChangeWithUserData](#oh_arkui_listitemswipeactionitem_setonstatechangewithuserdata) ([ArkUI_ListItemSwipeActionItem](#arkui_listitemswipeactionitem) \*item, void \*userData, void(\*callback)([ArkUI_ListItemSwipeActionState](#arkui_listitemswipeactionstate) swipeActionState, void \*userData)) | Sets the callback invoked when the swipe state of the list item changes. |
| [ArkUI_ListItemSwipeActionOption](#arkui_listitemswipeactionoption) \* [OH_ArkUI_ListItemSwipeActionOption_Create](#oh_arkui_listitemswipeactionoption_create) () | Creates a **ListItemSwipeActionOption** instance. |
| void [OH_ArkUI_ListItemSwipeActionOption_Dispose](#oh_arkui_listitemswipeactionoption_dispose) ([ArkUI_ListItemSwipeActionOption](#arkui_listitemswipeactionoption) \*option) | Disposes of a **ListItemSwipeActionOption** instance. |
| void [OH_ArkUI_ListItemSwipeActionOption_SetStart](#oh_arkui_listitemswipeactionoption_setstart) ([ArkUI_ListItemSwipeActionOption](#arkui_listitemswipeactionoption) \*option, [ArkUI_ListItemSwipeActionItem](#arkui_listitemswipeactionitem) \*item) | Sets the layout content for the left edge (for a vertical layout) or top edge (for a horizontal layout) of a **ListItemSwipeActionOption** instance. |
| void [OH_ArkUI_ListItemSwipeActionOption_SetEnd](#oh_arkui_listitemswipeactionoption_setend) ([ArkUI_ListItemSwipeActionOption](#arkui_listitemswipeactionoption) \*option, [ArkUI_ListItemSwipeActionItem](#arkui_listitemswipeactionitem) \*item) | Sets the layout content for the right edge (for a vertical layout) or bottom edge (for a horizontal layout) of a **ListItemSwipeActionItem** instance. |
| void [OH_ArkUI_ListItemSwipeActionOption_SetEdgeEffect](#oh_arkui_listitemswipeactionoption_setedgeeffect) ([ArkUI_ListItemSwipeActionOption](#arkui_listitemswipeactionoption) \*option, [ArkUI_ListItemSwipeEdgeEffect](#arkui_listitemswipeedgeeffect) edgeEffect) | Sets the edge effect used when the boundary of the scrolling area is reached. |
| int32_t [OH_ArkUI_ListItemSwipeActionOption_GetEdgeEffect](#oh_arkui_listitemswipeactionoption_getedgeeffect) ([ArkUI_ListItemSwipeActionOption](#arkui_listitemswipeactionoption) \*option) | Obtains the edge effect used when the boundary of the scrolling area is reached. |
| void [OH_ArkUI_ListItemSwipeActionOption_SetOnOffsetChange](#oh_arkui_listitemswipeactionoption_setonoffsetchange) ([ArkUI_ListItemSwipeActionOption](#arkui_listitemswipeactionoption) \*option, void(\*callback)(float offset)) | Sets the callback invoked when the scroll offset changes. |
| void [OH_ArkUI_ListItemSwipeActionOption_SetOnOffsetChangeWithUserData](#oh_arkui_listitemswipeactionoption_setonoffsetchangewithuserdata) ([ArkUI_ListItemSwipeActionOption](#arkui_listitemswipeactionoption) \*option, void \*userData, void(\*callback)(float offset, void \*userData)) | Sets the callback invoked when the scroll offset changes. |
| [ArkUI_AccessibilityState](#arkui_accessibilitystate) \* [OH_ArkUI_AccessibilityState_Create](#oh_arkui_accessibilitystate_create) (void) | Creates an accessibility state. |
| void [OH_ArkUI_AccessibilityState_Dispose](#oh_arkui_accessibilitystate_dispose) ([ArkUI_AccessibilityState](#arkui_accessibilitystate) \*state) | Disposes of the pointer to an accessibility state. |
| void [OH_ArkUI_AccessibilityState_SetDisabled](#oh_arkui_accessibilitystate_setdisabled) ([ArkUI_AccessibilityState](#arkui_accessibilitystate) \*state, int32_t isDisabled) | Sets whether an accessibility state is disabled. |
| int32_t [OH_ArkUI_AccessibilityState_IsDisabled](#oh_arkui_accessibilitystate_isdisabled) ([ArkUI_AccessibilityState](#arkui_accessibilitystate) \*state) | Obtains whether an accessibility state is disabled. |
| void [OH_ArkUI_AccessibilityState_SetSelected](#oh_arkui_accessibilitystate_setselected) ([ArkUI_AccessibilityState](#arkui_accessibilitystate) \*state, int32_t isSelected) | Sets whether an accessibility state is selected. |
| int32_t [OH_ArkUI_AccessibilityState_IsSelected](#oh_arkui_accessibilitystate_isselected) ([ArkUI_AccessibilityState](#arkui_accessibilitystate) \*state) | Obtains whether an accessibility state is selected. |
| void [OH_ArkUI_AccessibilityState_SetCheckedState](#oh_arkui_accessibilitystate_setcheckedstate) ([ArkUI_AccessibilityState](#arkui_accessibilitystate) \*state, int32_t checkedState) | Sets the check box state of an accessibility state. |
| int32_t [OH_ArkUI_AccessibilityState_GetCheckedState](#oh_arkui_accessibilitystate_getcheckedstate) ([ArkUI_AccessibilityState](#arkui_accessibilitystate) \*state) | Obtains the check box state of an accessibility state. |
| [ArkUI_AccessibilityValue](#arkui_accessibilityvalue) \* [OH_ArkUI_AccessibilityValue_Create](#oh_arkui_accessibilityvalue_create) (void) | Creates an **AccessibilityValue** instance. |
| void [OH_ArkUI_AccessibilityValue_Dispose](#oh_arkui_accessibilityvalue_dispose) ([ArkUI_AccessibilityValue](#arkui_accessibilityvalue) \*value) | Disposes of the pointer to an **AccessibilityValue** instance. |
| void [OH_ArkUI_AccessibilityValue_SetMin](#oh_arkui_accessibilityvalue_setmin) ([ArkUI_AccessibilityValue](#arkui_accessibilityvalue) \*value, int32_t min) | Sets the minimum accessibility value. |
| int32_t [OH_ArkUI_AccessibilityValue_GetMin](#oh_arkui_accessibilityvalue_getmin) ([ArkUI_AccessibilityValue](#arkui_accessibilityvalue) \*value) | Obtains the minimum accessibility value. |
| void [OH_ArkUI_AccessibilityValue_SetMax](#oh_arkui_accessibilityvalue_setmax) ([ArkUI_AccessibilityValue](#arkui_accessibilityvalue) \*value, int32_t max) | Sets the maximum accessibility value. |
| int32_t [OH_ArkUI_AccessibilityValue_GetMax](#oh_arkui_accessibilityvalue_getmax) ([ArkUI_AccessibilityValue](#arkui_accessibilityvalue) \*value) | Obtains the maximum accessibility value. |
| void [OH_ArkUI_AccessibilityValue_SetCurrent](#oh_arkui_accessibilityvalue_setcurrent) ([ArkUI_AccessibilityValue](#arkui_accessibilityvalue) \*value, int32_t current) | Sets the current accessibility value. |
| int32_t [OH_ArkUI_AccessibilityValue_GetCurrent](#oh_arkui_accessibilityvalue_getcurrent) ([ArkUI_AccessibilityValue](#arkui_accessibilityvalue) \*value) | Obtains the current accessibility value. |
| void [OH_ArkUI_AccessibilityValue_SetText](#oh_arkui_accessibilityvalue_settext) ([ArkUI_AccessibilityValue](#arkui_accessibilityvalue) \*value, const char \*text) | Sets the text description of an **AccessibilityValue** instance. |
| const char \* [OH_ArkUI_AccessibilityValue_GetText](#oh_arkui_accessibilityvalue_gettext) ([ArkUI_AccessibilityValue](#arkui_accessibilityvalue) \*value) | Obtains the text description of an **AccessibilityValue** instance. |
| [ArkUI_ImageAnimatorFrameInfo](#arkui_imageanimatorframeinfo) \* [OH_ArkUI_ImageAnimatorFrameInfo_CreateFromString](#oh_arkui_imageanimatorframeinfo_createfromstring) (char \*src) | Creates an image frame information object based on an image path, with the image format being SVG, PNG, or JPG. |
| [ArkUI_ImageAnimatorFrameInfo](#arkui_imageanimatorframeinfo) \* [OH_ArkUI_ImageAnimatorFrameInfo_CreateFromDrawableDescriptor](#oh_arkui_imageanimatorframeinfo_createfromdrawabledescriptor) ([ArkUI_DrawableDescriptor](#arkui_drawabledescriptor) \*drawable) | Creates an image frame information object based on a **DrawableDescriptor** object, with the image format being Resource or PixelMap. |
| void [OH_ArkUI_ImageAnimatorFrameInfo_Dispose](#oh_arkui_imageanimatorframeinfo_dispose) ([ArkUI_ImageAnimatorFrameInfo](#arkui_imageanimatorframeinfo) \*imageInfo) | Disposes of the pointer to an image frame information object. |
| void [OH_ArkUI_ImageAnimatorFrameInfo_SetWidth](#oh_arkui_imageanimatorframeinfo_setwidth) ([ArkUI_ImageAnimatorFrameInfo](#arkui_imageanimatorframeinfo) \*imageInfo, int32_t width) | Sets the image width. |
| int32_t [OH_ArkUI_ImageAnimatorFrameInfo_GetWidth](#oh_arkui_imageanimatorframeinfo_getwidth) ([ArkUI_ImageAnimatorFrameInfo](#arkui_imageanimatorframeinfo) \*imageInfo) | Obtains the image width. |
| void [OH_ArkUI_ImageAnimatorFrameInfo_SetHeight](#oh_arkui_imageanimatorframeinfo_setheight) ([ArkUI_ImageAnimatorFrameInfo](#arkui_imageanimatorframeinfo) \*imageInfo, int32_t height) | Sets the image height. |
| int32_t [OH_ArkUI_ImageAnimatorFrameInfo_GetHeight](#oh_arkui_imageanimatorframeinfo_getheight) ([ArkUI_ImageAnimatorFrameInfo](#arkui_imageanimatorframeinfo) \*imageInfo) | Obtains the image height. |
| void [OH_ArkUI_ImageAnimatorFrameInfo_SetTop](#oh_arkui_imageanimatorframeinfo_settop) ([ArkUI_ImageAnimatorFrameInfo](#arkui_imageanimatorframeinfo) \*imageInfo, int32_t top) | Sets the vertical coordinate of an image relative to the upper left corner of the component. |
| int32_t [OH_ArkUI_ImageAnimatorFrameInfo_GetTop](#oh_arkui_imageanimatorframeinfo_gettop) ([ArkUI_ImageAnimatorFrameInfo](#arkui_imageanimatorframeinfo) \*imageInfo) | Obtains the vertical coordinate of an image relative to the upper left corner of the component. |
| void [OH_ArkUI_ImageAnimatorFrameInfo_SetLeft](#oh_arkui_imageanimatorframeinfo_setleft) ([ArkUI_ImageAnimatorFrameInfo](#arkui_imageanimatorframeinfo) \*imageInfo, int32_t left) | Sets the horizontal coordinate of an image relative to the upper left corner of the component. |
| int32_t [OH_ArkUI_ImageAnimatorFrameInfo_GetLeft](#oh_arkui_imageanimatorframeinfo_getleft) ([ArkUI_ImageAnimatorFrameInfo](#arkui_imageanimatorframeinfo) \*imageInfo) | Obtains the horizontal coordinate of an image relative to the upper left corner of the component. |
| void [OH_ArkUI_ImageAnimatorFrameInfo_SetDuration](#oh_arkui_imageanimatorframeinfo_setduration) ([ArkUI_ImageAnimatorFrameInfo](#arkui_imageanimatorframeinfo) \*imageInfo, int32_t duration) | Sets the playback duration of an image. |
| int32_t [OH_ArkUI_ImageAnimatorFrameInfo_GetDuration](#oh_arkui_imageanimatorframeinfo_getduration) ([ArkUI_ImageAnimatorFrameInfo](#arkui_imageanimatorframeinfo) \*imageInfo) | Obtains the playback duration of an image. |
| [ArkUI_ListChildrenMainSize](#arkui_listchildrenmainsize) \* [OH_ArkUI_ListChildrenMainSizeOption_Create](#oh_arkui_listchildrenmainsizeoption_create) () | Creates a **ListChildrenMainSize** instance. |
| void [OH_ArkUI_ListChildrenMainSizeOption_Dispose](#oh_arkui_listchildrenmainsizeoption_dispose) ([ArkUI_ListChildrenMainSize](#arkui_listchildrenmainsize) \*option) | Disposes of a **ListChildrenMainSize** instance. |
| int32_t [OH_ArkUI_ListChildrenMainSizeOption_SetDefaultMainSize](#oh_arkui_listchildrenmainsizeoption_setdefaultmainsize) ([ArkUI_ListChildrenMainSize](#arkui_listchildrenmainsize) \*option, float defaultMainSize) | Sets the default size in a **ListChildrenMainSize** instance. |
| float [OH_ArkUI_ListChildrenMainSizeOption_GetDefaultMainSize](#oh_arkui_listchildrenmainsizeoption_getdefaultmainsize) ([ArkUI_ListChildrenMainSize](#arkui_listchildrenmainsize) \*option) | Obtains the default size in a **ListChildrenMainSize** instance. |
| void [OH_ArkUI_ListChildrenMainSizeOption_Resize](#oh_arkui_listchildrenmainsizeoption_resize) ([ArkUI_ListChildrenMainSize](#arkui_listchildrenmainsize) \*option, int32_t totalSize) | Resets the array size in a **ListChildrenMainSize** instance. |
| int32_t [OH_ArkUI_ListChildrenMainSizeOption_Splice](#oh_arkui_listchildrenmainsizeoption_splice) ([ArkUI_ListChildrenMainSize](#arkui_listchildrenmainsize) \*option, int32_t index, int32_t deleteCount, int32_t addCount) | Changes the content of a **ChildrenMainSizeOption** array. |
| int32_t [OH_ArkUI_ListChildrenMainSizeOption_UpdateSize](#oh_arkui_listchildrenmainsizeoption_updatesize) ([ArkUI_ListChildrenMainSize](#arkui_listchildrenmainsize) \*option, int32_t index, float mainSize) | Updates the values of a **ChildrenMainSizeOption** array. |
| float [OH_ArkUI_ListChildrenMainSizeOption_GetMainSize](#oh_arkui_listchildrenmainsizeoption_getmainsize) ([ArkUI_ListChildrenMainSize](#arkui_listchildrenmainsize) \*option, int32_t index) | Obtains the values of a **ChildrenMainSizeOption** array. |
| [ArkUI_CustomSpanMeasureInfo](#arkui_customspanmeasureinfo) \* [OH_ArkUI_CustomSpanMeasureInfo_Create](#oh_arkui_customspanmeasureinfo_create) (void) | Creates measurement information for this custom span. |
| void [OH_ArkUI_CustomSpanMeasureInfo_Dispose](#oh_arkui_customspanmeasureinfo_dispose) ([ArkUI_CustomSpanMeasureInfo](#arkui_customspanmeasureinfo) \*info) | Disposes of measurement information of a custom span. |
| float [OH_ArkUI_CustomSpanMeasureInfo_GetFontSize](#oh_arkui_customspanmeasureinfo_getfontsize) ([ArkUI_CustomSpanMeasureInfo](#arkui_customspanmeasureinfo) \*info) | Obtains the font size of the parent text node of a custom span. |
| [ArkUI_CustomSpanMetrics](#arkui_customspanmetrics) \* [OH_ArkUI_CustomSpanMetrics_Create](#oh_arkui_customspanmetrics_create) (void) | Creates measurement metrics for this custom span. |
| void [OH_ArkUI_CustomSpanMetrics_Dispose](#oh_arkui_customspanmetrics_dispose) ([ArkUI_CustomSpanMetrics](#arkui_customspanmetrics) \*metrics) | Disposes of measurement metrics of this custom span. |
| int32_t [OH_ArkUI_CustomSpanMetrics_SetWidth](#oh_arkui_customspanmetrics_setwidth) ([ArkUI_CustomSpanMetrics](#arkui_customspanmetrics) \*metrics, float width) | Sets the width for a custom span. |
| int32_t [OH_ArkUI_CustomSpanMetrics_SetHeight](#oh_arkui_customspanmetrics_setheight) ([ArkUI_CustomSpanMetrics](#arkui_customspanmetrics) \*metrics, float height) | Sets the height for a custom span. |
| [ArkUI_CustomSpanDrawInfo](#arkui_customspandrawinfo) \* [OH_ArkUI_CustomSpanDrawInfo_Create](#oh_arkui_customspandrawinfo_create) (void) | Creates drawing information for this custom span. |
| void [OH_ArkUI_CustomSpanDrawInfo_Dispose](#oh_arkui_customspandrawinfo_dispose) ([ArkUI_CustomSpanDrawInfo](#arkui_customspandrawinfo) \*info) | Disposes of drawing information for this custom span. |
| float [OH_ArkUI_CustomSpanDrawInfo_GetXOffset](#oh_arkui_customspandrawinfo_getxoffset) ([ArkUI_CustomSpanDrawInfo](#arkui_customspandrawinfo) \*info) | Obtains the x-axis offset of the custom span relative to the mounted component. |
| float [OH_ArkUI_CustomSpanDrawInfo_GetLineTop](#oh_arkui_customspandrawinfo_getlinetop) ([ArkUI_CustomSpanDrawInfo](#arkui_customspandrawinfo) \*info) | Obtains the top margin of the custom span relative to the mounted component. |
| float [OH_ArkUI_CustomSpanDrawInfo_GetLineBottom](#oh_arkui_customspandrawinfo_getlinebottom) ([ArkUI_CustomSpanDrawInfo](#arkui_customspandrawinfo) \*info) | Obtains the bottom margin of the custom span relative to the mounted component. |
| float [OH_ArkUI_CustomSpanDrawInfo_GetBaseline](#oh_arkui_customspandrawinfo_getbaseline) ([ArkUI_CustomSpanDrawInfo](#arkui_customspandrawinfo) \*info) | Obtains the baseline offset of the custom span relative to the mounted component. |
| [ArkUI_StyledString](#arkui_styledstring) \* [OH_ArkUI_StyledString_Create](#oh_arkui_styledstring_create) (OH_Drawing_TypographyStyle \*style, OH_Drawing_FontCollection \*collection) | Creates an **OH_Drawing_TextStyle** object. |
| void [OH_ArkUI_StyledString_Destroy](#oh_arkui_styledstring_destroy) ([ArkUI_StyledString](#arkui_styledstring) \*handle) | Destroys an **OH_Drawing_FontCollection** object and reclaims the memory occupied by the object. |
| void [OH_ArkUI_StyledString_PushTextStyle](#oh_arkui_styledstring_pushtextstyle) ([ArkUI_StyledString](#arkui_styledstring) \*handle, OH_Drawing_TextStyle \*style) | Pushes a text style to the top of the style stack of a styled string. |
| void [OH_ArkUI_StyledString_AddText](#oh_arkui_styledstring_addtext) ([ArkUI_StyledString](#arkui_styledstring) \*handle, const char \*content) | Adds text for a styled string. |
| void [OH_ArkUI_StyledString_PopTextStyle](#oh_arkui_styledstring_poptextstyle) ([ArkUI_StyledString](#arkui_styledstring) \*handle) | Pops the style at the top of the style stack of a styled string. |
| OH_Drawing_Typography \* [OH_ArkUI_StyledString_CreateTypography](#oh_arkui_styledstring_createtypography) ([ArkUI_StyledString](#arkui_styledstring) \*handle) | Creates an **OH_Drawing_Typography** object based on an **ArkUI_StyledString** object. |
| void [OH_ArkUI_StyledString_AddPlaceholder](#oh_arkui_styledstring_addplaceholder) ([ArkUI_StyledString](#arkui_styledstring) \*handle, OH_Drawing_PlaceholderSpan \*placeholder) | Adds a placeholder. |


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


### ArkUI_AccessibilityState

```
typedef struct ArkUI_AccessibilityState ArkUI_AccessibilityState
```
**Description**

Defines a struct for the component accessibility state.

**Since**: 12


### ArkUI_AccessibilityValue

```
typedef struct ArkUI_AccessibilityValue ArkUI_AccessibilityValue
```
**Description**

Defines a struct for the component accessibility value.

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

Defines a struct for the animation configuration.

**Since**: 12


### ArkUI_AnimatorHandle

```
typedef struct ArkUI_Animator* ArkUI_AnimatorHandle
```
**Description**

Defines a struct for the pointer to an animator object.

**Since**: 12


### ArkUI_AnimatorOption

```
typedef struct ArkUI_AnimatorOption ArkUI_AnimatorOption
```
**Description**

Defines the animator parameter object.

**Since**: 12


### ArkUI_BarrierOption

```
typedef struct ArkUI_BarrierOption ArkUI_BarrierOption
```
**Description**

Defines the ID, direction, and referenced component of a barrier.

**Since**: 12


### ArkUI_Context

```
typedef struct ArkUI_Context ArkUI_Context
```
**Description**

Defines a struct for a UI context object.

**Since**: 12


### ArkUI_ContextHandle [1/2]

```
typedef struct ArkUI_Context* ArkUI_ContextHandle
```
**Description**

Defines a struct for the handle to the ArkUI native UI context.

**Since**: 12


### ArkUI_ContextHandle [2/2]

```
typedef struct ArkUI_Context* ArkUI_ContextHandle
```
**Description**

Defines the handle to the ArkUI native UI context.

**Since**: 12


### ArkUI_CurveHandle

```
typedef struct ArkUI_Curve* ArkUI_CurveHandle
```
**Description**

Defines a struct for the pointer to an interpolation curve.

**Since**: 12


### ArkUI_CustomSpanDrawInfo

```
typedef struct ArkUI_CustomSpanDrawInfo ArkUI_CustomSpanDrawInfo
```
**Description**

Defines a struct for the drawing information of a custom span.

**Since**: 12


### ArkUI_CustomSpanMeasureInfo

```
typedef struct ArkUI_CustomSpanMeasureInfo ArkUI_CustomSpanMeasureInfo
```
**Description**

Defines a struct for the measurement information of a custom span.

**Since**: 12


### ArkUI_CustomSpanMetrics

```
typedef struct ArkUI_CustomSpanMetrics ArkUI_CustomSpanMetrics
```
**Description**

Defines a struct for the measurement metrics of a custom span.

**Since**: 12


### ArkUI_DialogDismissEvent

```
typedef struct ArkUI_DialogDismissEvent ArkUI_DialogDismissEvent
```
**Description**

Defines a struct for a dialog box dismiss event.

**Since**: 12


### ArkUI_DragAction

```
typedef struct ArkUI_DragAction ArkUI_DragAction
```
**Description**

Defines a struct for a drag action.

**Since**: 12


### ArkUI_DragAndDropInfo

```
typedef struct ArkUI_DragAndDropInfo ArkUI_DragAndDropInfo
```
**Description**

Defines a struct for drag and drop information returned through a drag status listener.

**Since**: 12


### ArkUI_DragEvent

```
typedef struct ArkUI_DragEvent ArkUI_DragEvent
```
**Description**

Defines a struct for a drag event.

**Since**: 12


### ArkUI_DragPreviewOption

```
typedef struct ArkUI_DragPreviewOption ArkUI_DragPreviewOption
```
**Description**

Defines a struct for custom drag preview options.

**Since**: 12


### ArkUI_DrawableDescriptor

```
typedef struct ArkUI_DrawableDescriptor ArkUI_DrawableDescriptor
```
**Description**

Defines a struct for the **DrawableDescriptor** object.

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

Example: **ArkUI_GestureEventActionTypeMask actions = GESTURE_EVENT_ACTION_ACCEPT | GESTURE_EVENT_ACTION_UPDATE**

**Since**: 12


### ArkUI_GestureEventTargetInfo

```
typedef struct ArkUI_GestureEventTargetInfo ArkUI_GestureEventTargetInfo
```
**Description**

Defines a struct for a **GestureEventTargetInfo** object that provides information about a gesture event target.

**Since**: 12


### ArkUI_GestureRecognizerDestructNotifyCallback

```
typedef void(* ArkUI_GestureRecognizerDestructNotifyCallback) (ArkUI_GestureRecognizer *recognizer, void *userData)
```
**Description**

Defines a callback function for notifying gesture recognizer destruction.

**Since**: 12


### ArkUI_GestureRecognizerHandle

```
typedef ArkUI_GestureRecognizer* ArkUI_GestureRecognizerHandle
```
**Description**

Defines the gesture recognizer handle.

**Since**: 12


### ArkUI_GestureRecognizerHandleArray

```
typedef ArkUI_GestureRecognizerHandle* ArkUI_GestureRecognizerHandleArray
```
**Description**

Defines the gesture recognizer handle array.

**Since**: 12


### ArkUI_GuidelineOption

```
typedef struct ArkUI_GuidelineOption ArkUI_GuidelineOption
```
**Description**

Defines the ID, direction, and position of a guideline.

**Since**: 12


### ArkUI_ImageAnimatorFrameInfo

```
typedef struct ArkUI_ImageAnimatorFrameInfo ArkUI_ImageAnimatorFrameInfo
```
**Description**

Defines the image frame information.

**Since**: 12


### ArkUI_KeyframeAnimateOption

```
typedef struct ArkUI_KeyframeAnimateOption ArkUI_KeyframeAnimateOption
```
**Description**

Defines a struct for the keyframe animation parameter object.

**Since**: 12


### ArkUI_LayoutConstraint

```
typedef struct ArkUI_LayoutConstraint ArkUI_LayoutConstraint
```
**Description**

Defines the size constraints of a component during component layout.

**Since**: 12


### ArkUI_ListChildrenMainSize

```
typedef struct ArkUI_ListChildrenMainSize ArkUI_ListChildrenMainSize
```
**Description**

Defines the **ChildrenMainSize** information of the **List** component.

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


### ArkUI_NodeContentCallback

```
typedef void(* ArkUI_NodeContentCallback) (ArkUI_NodeContentEvent *event)
```
**Description**

Defines the callback for the NodeContent event.

**Since**: 12


### ArkUI_NodeContentEvent

```
typedef struct ArkUI_NodeContentEvent ArkUI_NodeContentEvent
```
**Description**

Defines the common structure type of a NodeContent event.

**Since**: 12


### ArkUI_NodeContentHandle

```
typedef struct ArkUI_NodeContent* ArkUI_NodeContentHandle
```
**Description**

Defines the handle to the ArkUI NodeContent instance on the native side.

**Since**: 12


### ArkUI_NodeCustomEvent

```
typedef struct ArkUI_NodeCustomEvent ArkUI_NodeCustomEvent
```
**Description**

Defines the common structure of a custom component event.

**Since**: 12


### ArkUI_NodeEvent [1/2]

```
typedef struct ArkUI_NodeEvent ArkUI_NodeEvent
```
**Description**

Defines a struct for a component event.

**Since**: 12


### ArkUI_NodeEvent [2/2]

```
typedef struct ArkUI_NodeEventArkUI_NodeEvent
```
**Description**

Defines the common structure of a component event.

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

Defines a pointer to the callback invoked when the dialog box is closed.

**Since**: 12


### ArkUI_ParallelInnerGestureEvent

```
typedef struct ArkUI_ParallelInnerGestureEvent ArkUI_ParallelInnerGestureEvent
```
**Description**

Defines a parallel internal gesture event.

**Since**: 12


### ArkUI_StyledString

```
typedef struct ArkUI_StyledString ArkUI_StyledString
```
**Description**

Defines a struct for the styled string object supported by the text component.

**Since**: 12


### ArkUI_SwiperIndicator

```
typedef struct ArkUI_SwiperIndicator ArkUI_SwiperIndicator
```
**Description**

Defines the navigation point indicator style of the **Swiper** component.

**Since**: 12


### ArkUI_SystemFontStyleEvent

```
typedef struct ArkUI_SystemFontStyleEvent ArkUI_SystemFontStyleEvent
```
**Description**

Defines a struct for the system font style event.

**Since**: 12


### ArkUI_TransitionEffect

```
typedef struct ArkUI_TransitionEffect ArkUI_TransitionEffect
```
**Description**

Defines a struct for the transition effect.

**Since**: 12


### ArkUI_WaterFlowSectionOption

```
typedef struct ArkUI_WaterFlowSectionOption ArkUI_WaterFlowSectionOption
```
**Description**

Defines the water flow section configuration.

**Since**: 12


### OH_PixelmapNative

```
typedef struct OH_PixelmapNative OH_PixelmapNative
```
**Description**

Defines the **Pixelmap** struct, which is used to perform operations related to a pixel map.

**Since**: 12


### OH_PixelmapNativeHandle

```
typedef struct OH_PixelmapNative* OH_PixelmapNativeHandle
```
**Description**

Defines a struct for the pointer to an **OH_PixelmapNative** object.

**Since**: 12


### OH_UdmfData

```
typedef struct OH_UdmfData OH_UdmfData
```
**Description**

Defines a struct for UDMF unified data.

**Since**: 12

## Enum Description


### ArkUI_AccessibilityActionType

```
enum ArkUI_AccessibilityActionType
```

**Description**

Defines an enum for the accessibility action types.

**Since**: 12

| Enum| Description|
| -------- | -------- |
| ARKUI_ACCESSIBILITY_ACTION_CLICK  | Tapping |
| ARKUI_ACCESSIBILITY_ACTION_LONG_CLICK  | Long press |
| ARKUI_ACCESSIBILITY_ACTION_CUT  | Cut. |
| ARKUI_ACCESSIBILITY_ACTION_COPY  |   |
| ARKUI_ACCESSIBILITY_ACTION_PASTE  | Paste. |


### ArkUI_AccessibilityCheckedState

```
enum ArkUI_AccessibilityCheckedState
```

**Description**

Enumerates the accessibility check box states.

**Since**: 12

| Enum                          | Description                    |
| ----------------------------- | ------------------------------ |
| ARKUI_ACCESSIBILITY_UNCHECKED | The check box is not selected. |
| ARKUI_ACCESSIBILITY_CHECKED   | The check box is selected.     |


### ArkUI_AccessibilityMode

```
enum ArkUI_AccessibilityMode
```

**Description**

Enumerates the accessibility modes.

**Since**: 12

| Enum| Description|
| -------- | -------- |
| ARKUI_ACCESSIBILITY_MODE_AUTO  | The mode is automatically set to enabled or disabled based on the component. |
| ARKUI_ACCESSIBILITY_MODE_ENABLED  | The component can be identified by the accessibility service. |
| ARKUI_ACCESSIBILITY_MODE_DISABLED  | The component cannot be identified by the accessibility service. |
| ARKUI_ACCESSIBILITY_MODE_DISABLED_FOR_DESCENDANTS  | The component and all its child components cannot be identified by the accessibility service. |


### ArkUI_AdaptiveColor

```
enum ArkUI_AdaptiveColor
```

**Description**

Enumerates the adaptive color modes.

**Since**: 12

| Enum                         | Description                      |
| ---------------------------- | -------------------------------- |
| ARKUI_ADAPTIVE_COLOR_DEFAULT | Adaptive color mode is not used. |
| ARKUI_ADAPTIVE_COLOR_AVERAGE | Adaptive color mode is used.     |


### ArkUI_Alignment

```
enum ArkUI_Alignment
```

**Description**

Enumerates the alignment modes.

**Since**: 12

| Enum| Description|
| -------- | -------- |
| ARKUI_ALIGNMENT_TOP_START  | Top start. |
| ARKUI_ALIGNMENT_TOP  | Top center. |
| ARKUI_ALIGNMENT_TOP_END  | Top end. |
| ARKUI_ALIGNMENT_START  | Vertically centered start. |
| ARKUI_ALIGNMENT_CENTER  | Horizontally and vertically centered. |
| ARKUI_ALIGNMENT_END  | Vertically centered end. |
| ARKUI_ALIGNMENT_BOTTOM_START  | Bottom start. |
| ARKUI_ALIGNMENT_BOTTOM  | Horizontally centered on the bottom. |
| ARKUI_ALIGNMENT_BOTTOM_END  | Bottom end. |


### ArkUI_AnimationCurve

```
enum ArkUI_AnimationCurve
```

**Description**

Enumerates the animation curves.

**Since**: 12

| Enum| Description|
| -------- | -------- |
| ARKUI_CURVE_LINEAR  | The animation speed keeps unchanged. |
| ARKUI_CURVE_EASE  | The animation starts slowly, accelerates, and then slows down towards the end. |
| ARKUI_CURVE_EASE_IN  | The animation starts at a low speed and then picks up speed until the end. |
| ARKUI_CURVE_EASE_OUT  | The animation ends at a low speed. |
| ARKUI_CURVE_EASE_IN_OUT  | The animation starts and ends at a low speed. |
| ARKUI_CURVE_FAST_OUT_SLOW_IN  | The animation uses the standard curve |
| ARKUI_CURVE_LINEAR_OUT_SLOW_IN  | The animation uses the deceleration curve. |
| ARKUI_CURVE_FAST_OUT_LINEAR_IN  | The animation uses the acceleration curve. |
| ARKUI_CURVE_EXTREME_DECELERATION  | The animation uses the extreme deceleration curve. |
| ARKUI_CURVE_SHARP  | The animation uses the sharp curve. |
| ARKUI_CURVE_RHYTHM  | The animation uses the rhythm curve. |
| ARKUI_CURVE_SMOOTH  | The animation uses the smooth curve. |
| ARKUI_CURVE_FRICTION  | The animation uses the friction curve |


### ArkUI_AnimationDirection

```
enum ArkUI_AnimationDirection
```

**Description**

Enumerates the animation playback modes.

**Since**: 12

| Enum                                        | Description                                                  |
| -------- | -------- |
| ARKUI_ANIMATION_DIRECTION_NORMAL            | The animation plays in forward loop mode.                    |
| ARKUI_ANIMATION_DIRECTION_REVERSE           | The animation plays in reverse loop mode.                    |
| ARKUI_ANIMATION_DIRECTION_ALTERNATE         | The animation plays in alternating loop mode. When the animation is played for an odd number of times, the playback is in forward direction. When the animation is played for an even number of times, the playback is in reverse direction. |
| ARKUI_ANIMATION_DIRECTION_ALTERNATE_REVERSE | The animation plays in reverse alternating loop mode. When the animation is played for an odd number of times, the playback is in reverse direction. When the animation is played for an even number of times, the playback is in forward direction. |


### ArkUI_AnimationFill

```
enum ArkUI_AnimationFill
```

**Description**

Enumerates the state of the animated target after the animation is executed.

**Since**: 12

| Enum| Description|
| -------- | -------- |
| ARKUI_ANIMATION_FILL_NONE  | No style is applied to the target before or after the animation is executed. |
| ARKUI_ANIMATION_FILL_FORWARDS  | The target keeps the state at the end of the animation (defined in the last key frame) after the animation is executed. |
| ARKUI_ANIMATION_FILL_BACKWARDS  | The animation uses the value defined in the first key frame during the duration defined by **animation-delay**. |
| ARKUI_ANIMATION_FILL_BOTH  | The animation follows the **forwards** and **backwards** rules. |


### ArkUI_AnimationFillMode

```
enum ArkUI_AnimationFillMode

```

**Description**

Enumerates the states before and after execution of the frame-by-frame animation.

**Since**: 12

| Enum                                | Description                                                  |
| ----------------------------------- | ------------------------------------------------------------ |
| ARKUI_ANIMATION_FILL_MODE_NONE      | Before execution, the animation does not apply any styles to the target component. After execution, the animation restores the target component to its default state. |
| ARKUI_ANIMATION_FILL_MODE_FORWARDS  | The target component retains the state set by the last keyframe encountered during execution of the animation. |
| ARKUI_ANIMATION_FILL_MODE_BACKWARDS | The animation applies the values defined in the first relevant keyframe once it is applied to the target component, and retains the values during the period set by **delay**. |
| ARKUI_ANIMATION_FILL_MODE_BOTH      | The animation follows the rules for both **Forwards** and **Backwards**, extending the animation attributes in both directions. |


### ArkUI_AnimationPlayMode

```
enum ArkUI_AnimationPlayMode

```

**Description**

Enumerates the animation playback modes.

**Since**: 12

| Enum                                        | Description                                                  |
| ------------------------------------------- | ------------------------------------------------------------ |
| ARKUI_ANIMATION_PLAY_MODE_NORMAL            | The animation is played forwards.                            |
| ARKUI_ANIMATION_PLAY_MODE_REVERSE           | The animation is played backwards.                           |
| ARKUI_ANIMATION_PLAY_MODE_ALTERNATE         | The animation is played forwards for an odd number of times (1, 3, 5...) and backwards for an even number of times (2, 4, 6...). |
| ARKUI_ANIMATION_PLAY_MODE_ALTERNATE_REVERSE | The animation is played backwards for an odd number of times (1, 3, 5...) and forwards for an even number of times (2, 4, 6...). |


### ArkUI_AnimationStatus

```
enum ArkUI_AnimationStatus

```

**Description**

Enumerates the playback states of the frame-by-frame animation.

**Since**: 12

| Enum                           | Description                            |
| ------------------------------ | -------------------------------------- |
| ARKUI_ANIMATION_STATUS_INITIAL | The animation is in the initial state. |
| ARKUI_ANIMATION_STATUS_RUNNING | The animation is being played.         |
| ARKUI_ANIMATION_STATUS_PAUSED  | The animation is paused.               |
| ARKUI_ANIMATION_STATUS_STOPPED | The animation is stopped.              |


### ArkUI_Axis

```
enum ArkUI_Axis

```

**Description**

Enumerates the scroll directions.

**Since**: 12

| Enum                  | Description                             |
| --------------------- | --------------------------------------- |
| ARKUI_AXIS_VERTICAL   | Only vertical scrolling is supported.   |
| ARKUI_AXIS_HORIZONTAL | Only horizontal scrolling is supported. |


### ArkUI_BarrierDirection

```
enum ArkUI_BarrierDirection

```

**Description**

Enumerates the barrier directions.

**Since**: 12

| Enum                           | Description                                                  |
| ------------------------------ | ------------------------------------------------------------ |
| ARKUI_BARRIER_DIRECTION_START  | The barrier is on the left side of all the referenced components specified by referencedId. |
| ARKUI_BARRIER_DIRECTION_END    | The barrier is on the right side of all the referenced components specified by referencedId. |
| ARKUI_BARRIER_DIRECTION_TOP    | The barrier is at the top of all the referenced components specified by referencedId. |
| ARKUI_BARRIER_DIRECTION_BOTTOM | The barrier is at the bottom of all the referenced components specified by referencedId. |


### ArkUI_BlendApplyType

```
enum ArkUI_BlendApplyType

```

**Description**

Defines how the specified blend mode is applied.

**Since**: 12

| Enum                       | Description                                                  |
| -------------------------- | ------------------------------------------------------------ |
| BLEND_APPLY_TYPE_FAST      | The content of the view is blended in sequence on the target image. |
| BLEND_APPLY_TYPE_OFFSCREEN | The content of the component and its child components are drawn on the offscreen canvas, and then blended with the existing content on the canvas. |


### ArkUI_BlendMode

```
enum ArkUI_BlendMode

```

**Description**

Enumerates the blend modes.

**Since**: 12

| Enum                         | Description                                                  |
| ---------------------------- | ------------------------------------------------------------ |
| ARKUI_BLEND_MODE_NONE        | The top image is superimposed on the bottom image without any blending. |
| ARKUI_BLEND_MODE_CLEAR       | The target pixels covered by the source pixels are erased by being turned to completely transparent. |
| ARKUI_BLEND_MODE_SRC         | r = s: Only the source pixels are displayed.                 |
| ARKUI_BLEND_MODE_DST         | r = d: Only the target pixels are displayed.                 |
| ARKUI_BLEND_MODE_SRC_OVER    | r = s + (1 - sa) \d: The source pixels are blended based on opacity and cover the target pixels. |
| ARKUI_BLEND_MODE_DST_OVER    | r = d + (1 - da) *\ s: The target pixels are blended based on opacity and cover on the source pixels. |
| ARKUI_BLEND_MODE_SRC_IN      | r = s \* da: Only the part of the source pixels that overlap with the target pixels is displayed. |
| ARKUI_BLEND_MODE_DST_IN      | r = d \* sa: Only the part of the target pixels that overlap with the source pixels is displayed. |
| ARKUI_BLEND_MODE_SRC_OUT     | r = s \* (1 - da): Only the part of the source pixels that do not overlap with the target pixels is displayed. |
| ARKUI_BLEND_MODE_DST_OUT     | r = d \* (1 - sa): Only the part of the target pixels that do not overlap with the source pixels is displayed. |
| ARKUI_BLEND_MODE_SRC_ATOP    | r = s \da + d \(1 - sa): The part of the source pixels that overlap with the target pixels is displayed and the part of the target pixels that do not overlap with the source pixels are displayed. |
| ARKUI_BLEND_MODE_DST_ATOP    | r = d \sa + s \(1 - da): The part of the target pixels that overlap with the source pixels and the part of the source pixels that do not overlap with the target pixels are displayed. |
| ARKUI_BLEND_MODE_XOR         | r = s \* (1 - da) + d \* (1 - sa): Only the non-overlapping part between the source pixels and the target pixels is displayed. |
| ARKUI_BLEND_MODE_PLUS        | r = min(s + d, 1): New pixels resulting from adding the source pixels to the target pixels are displayed. |
| ARKUI_BLEND_MODE_MODULATE    | r = s \* d: New pixels resulting from multiplying the source pixels with the target pixels are displayed. |
| ARKUI_BLEND_MODE_SCREEN      | r = s + d - s \* d: Pixels are blended by adding the source pixels to the target pixels and subtracting the product of their multiplication. |
| ARKUI_BLEND_MODE_OVERLAY     | The MULTIPLY or SCREEN mode is used based on the target pixels. |
| ARKUI_BLEND_MODE_DARKEN      | rc = s + d - max(s \da, d \sa), ra = kSrcOver: When two colors overlap, whichever is darker is used. |
| ARKUI_BLEND_MODE_LIGHTEN     | rc = s + d - min(s \da, d \sa), ra = kSrcOver: The darker of the pixels (source and target) is used. |
| ARKUI_BLEND_MODE_COLOR_DODGE | The colors of the target pixels are lightened to reflect the source pixels. |
| ARKUI_BLEND_MODE_COLOR_BURN  | The colors of the target pixels are darkened to reflect the source pixels. |
| ARKUI_BLEND_MODE_HARD_LIGHT  | The MULTIPLY or SCREEN mode is used, depending on the source pixels. |
| ARKUI_BLEND_MODE_SOFT_LIGHT  | The LIGHTEN or DARKEN mode is used, depending on the source pixels. |
| ARKUI_BLEND_MODE_DIFFERENCE  | rc = s + d - 2 \* (min(s \* da, d \vsa)), ra = kSrcOver: The final pixel is the result of subtracting the darker of the two pixels (source and target) from the lighter one. |
| ARKUI_BLEND_MODE_EXCLUSION   | rc = s + d - two(s \* d), ra = kSrcOver: The final pixel is similar to **DIFFERENCE**, but with less contrast. |
| ARKUI_BLEND_MODE_MULTIPLY    | r = s \* (1 - da) + d \* (1 - sa) + s \* d: The final pixel is the result of multiplying the source pixel by the target pixel. |
| ARKUI_BLEND_MODE_HUE         | The resultant image is created with the luminance and saturation of the source image and the hue of the target image. |
| ARKUI_BLEND_MODE_SATURATION  | The resultant image is created with the luminance and hue of the target image and the saturation of the source image. |
| ARKUI_BLEND_MODE_COLOR       | The resultant image is created with the saturation and hue of the source image and the luminance of the target image. |
| ARKUI_BLEND_MODE_LUMINOSITY  | The resultant image is created with the saturation and hue of the target image and the luminance of the source image. |


### ArkUI_BlurStyle

```
enum ArkUI_BlurStyle

```

**Description**

Enumerates the blur styles.

**Since**: 12

| Enum                                    | Description                                                  |
| --------------------------------------- | ------------------------------------------------------------ |
| ARKUI_BLUR_STYLE_THIN                   | Thin material.                                               |
| ARKUI_BLUR_STYLE_REGULAR                | Regular material.                                            |
| ARKUI_BLUR_STYLE_THICK                  | Thick material.                                              |
| ARKUI_BLUR_STYLE_BACKGROUND_THIN        | Material that creates the minimum depth of field effect.     |
| ARKUI_BLUR_STYLE_BACKGROUND_REGULAR     | Material that creates a medium shallow depth of field effect. |
| ARKUI_BLUR_STYLE_BACKGROUND_THICK       | Material that creates a high shallow depth of field effect.  |
| ARKUI_BLUR_STYLE_BACKGROUND_ULTRA_THICK | Material that creates the maximum depth of field effect.     |
| ARKUI_BLUR_STYLE_NONE                   | No blur.                                                     |
| ARKUI_BLUR_STYLE_COMPONENT_ULTRA_THIN   | Component ultra-thin material.                               |
| ARKUI_BLUR_STYLE_COMPONENT_THIN         | Component thin material.                                     |
| ARKUI_BLUR_STYLE_COMPONENT_REGULAR      | Component regular material.                                  |
| ARKUI_BLUR_STYLE_COMPONENT_THICK        | Component thick material.                                    |
| ARKUI_BLUR_STYLE_COMPONENT_ULTRA_THICK  | Component ultra-thick material.                              |


### ArkUI_BorderStyle

```
enum ArkUI_BorderStyle

```

**Description**

Enumerates the border styles.

**Since**: 12

| Enum                      | Description    |
| ------------------------- | -------------- |
| ARKUI_BORDER_STYLE_SOLID  | Solid border.  |
| ARKUI_BORDER_STYLE_DASHED | Dashed border. |
| ARKUI_BORDER_STYLE_DOTTED | Dotted border. |


### ArkUI_ButtonType

```
enum ArkUI_ButtonType

```

**Description**

Enumerates the button types.

**Since**: 12

| Enum                      | Description                                                  |
| ------------------------- | ------------------------------------------------------------ |
| ARKUI_BUTTON_TYPE_NORMAL  | Normal button (without rounded corners by default).          |
| ARKUI_BUTTON_TYPE_CAPSULE | Capsule-type button (the round corner is half of the height by default). |
| ARKUI_BUTTON_TYPE_CIRCLE  | Circle button.                                               |


### ArkUI_CalendarAlignment

```
enum ArkUI_CalendarAlignment

```

**Description**

Enumerates the alignment modes between the calendar picker and the entry component.

**Since**: 12

| Enum                            | Description     |
| ------------------------------- | --------------- |
| ARKUI_CALENDAR_ALIGNMENT_START  | Left aligned.   |
| ARKUI_CALENDAR_ALIGNMENT_CENTER | Center aligned. |
| ARKUI_CALENDAR_ALIGNMENT_END    | Right aligned.  |


### ArkUI_CancelButtonStyle

```
enum ArkUI_CancelButtonStyle
```

**Description**

Enumerates the styles of the Cancel button.

**Since**: 12

| Enum                               | Description                                              |
| ---------------------------------- | -------------------------------------------------------- |
| ARKUI_CANCELBUTTON_STYLE_CONSTANT  | The Cancel button is always displayed.                   |
| ARKUI_CANCELBUTTON_STYLE_INVISIBLE | The Cancel button is always hidden.                      |
| ARKUI_CANCELBUTTON_STYLE_INPUT     | The Cancel button is displayed when there is text input. |


### ArkUI_CheckboxShape

```
enum ArkUI_CheckboxShape
```

**Description**

Enumerates the shapes of the check box.

**Since**: 12

| Enum                                | Description     |
| ----------------------------------- | --------------- |
| ArkUI_CHECKBOX_SHAPE_CIRCLE         | Circle.         |
| ArkUI_CHECKBOX_SHAPE_ROUNDED_SQUARE | Rounded square. |


### ArkUI_ClipType

```
enum ArkUI_ClipType
```

**Description**

Enumerates the clipping region types.

**Since**: 12

| Enum                      | Description  |
| ------------------------- | ------------ |
| ARKUI_CLIP_TYPE_RECTANGLE | Rectangle.   |
| ARKUI_CLIP_TYPE_CIRCLE    | **(circle)** |
| ARKUI_CLIP_TYPE_ELLIPSE   | Ellipse.     |
| ARKUI_CLIP_TYPE_PATH      | Path Type    |


### ArkUI_ColorMode

```
enum ArkUI_ColorMode
```

**Description**

Enumerates the color modes.

**Since**: 12

| Enum                    | Description                      |
| ----------------------- | -------------------------------- |
| ARKUI_COLOR_MODE_SYSTEM | Following the system color mode. |
| ARKUI_COLOR_MODE_LIGHT  | Light color mode.                |
| ARKUI_COLOR_MODE_DARK   | Dark color mode.                 |


### ArkUI_ColorStrategy

```
enum ArkUI_ColorStrategy

```

**Description**

Enumerates the foreground colors.

**Since**: 12

| Enum                         | Description                                                  |
| ---------------------------- | ------------------------------------------------------------ |
| ARKUI_COLOR_STRATEGY_INVERT  | The foreground colors are the inverse of the component background colors. |
| ARKUI_COLOR_STRATEGY_AVERAGE | The shadow colors of the component are the average color obtained from the component background shadow area. |
| ARKUI_COLOR_STRATEGY_PRIMARY | The shadow colors of the component are the primary color obtained from the component background shadow area. |


### ArkUI_CopyOptions

```
enum ArkUI_CopyOptions

```

**Description**

Enumerates the text copy and paste modes.

**Since**: 12

| Enum                            | Description                        |
| ------------------------------- | ---------------------------------- |
| ARKUI_COPY_OPTIONS_NONE         | Copy is not allowed.               |
| ARKUI_COPY_OPTIONS_IN_APP       | Intra-application copy is allowed. |
| ARKUI_COPY_OPTIONS_LOCAL_DEVICE | Intra-device copy is allowed.      |
| ARKUI_COPY_OPTIONS_CROSS_DEVICE | Cross-device copy is allowed.      |


### ArkUI_Direction

```
enum ArkUI_Direction

```

**Description**

Enumerates the modes in which components are laid out along the main axis of the container.

**Since**: 12

| Enum                 | Description                                 |
| -------------------- | ------------------------------------------- |
| ARKUI_DIRECTION_LTR  | Components are arranged from left to right. |
| ARKUI_DIRECTION_RTL  | Components are arranged from right to left. |
| ARKUI_DIRECTION_AUTO | The default layout direction is used.       |


### ArkUI_DismissReason

```
enum ArkUI_DismissReason

```

**Description**

Enumerates the actions for triggering closure of the dialog box.

**Since**: 12

| Enum                         | Description                                                  |
| ---------------------------- | ------------------------------------------------------------ |
| DIALOG_DISMISS_BACK_PRESS    | Touching the system-defined Back button or pressing the Esc key. |
| DIALOG_DISMISS_TOUCH_OUTSIDE | Touching the mask.                                           |
| DIALOG_DISMISS_CLOSE_BUTTON  | Touching the Close button. |
| DIALOG_DISMISS_SLIDE_DOWN  | Sliding down. |


### ArkUI_DragPreviewScaleMode

```
enum ArkUI_DragPreviewScaleMode

```

**Description**

Defines an enum for drag preview scale modes.

**Since**: 12

| Enum                              | Description                                                  |
| --------------------------------- | ------------------------------------------------------------ |
| ARKUI_DRAG_PREVIEW_SCALE_AUTO     | The system automatically changes the position of the dragged point based on the scenario and scales the drag preview based on set rules. |
| ARKUI_DRAG_PREVIEW_SCALE_DISABLED | The system does not scale the drag preview.                  |


### ArkUI_DragResult

```
enum ArkUI_DragResult

```

**Description**

Defines an enum for drag results, which are set by the data receiver and transferred by the system to the drag source so that the drag source is aware of the data processing result of the receiver.

**Since**: 12

| Enum| Description|
| -------- | -------- |
| ARKUI_DRAG_RESULT_SUCCESSFUL  | The drag and drop operation succeeded. |
| ARKUI_DRAG_RESULT_FAILED  | The drag and drop operation failed. |
| ARKUI_DRAG_RESULT_CANCELED  | The drag and drop operation was canceled. |


### ArkUI_DragStatus

```
enum ArkUI_DragStatus

```

**Description**

Enumerates dragging states.

**Since**: 12

| Enum                      | Description |
| ------------------------- | ----------- |
| ArkUI_DRAG_STATUS_UNKNOWN | Unknown.    |
| ArkUI_DRAG_STATUS_STARTED | Started.    |
| ArkUI_DRAG_STATUS_ENDED   | Ended.      |


### ArkUI_DropProposal

```
enum ArkUI_DropProposal

```

**Description**

Defines an enum for data processing modes used when data is dropped, which affects the display of the badge.

**Since**: 12

| Enum                     | Description |
| ------------------------ | ----------- |
| ARKUI_DROP_PROPOSAL_COPY | Copy.       |
| ARKUI_DROP_PROPOSAL_MOVE | Cut.        |


### ArkUI_EdgeEffect

```
enum ArkUI_EdgeEffect

```

**Description**

Enumerates the effects used at the edges of the component when the boundary of the scrollable content is reached.

**Since**: 12

| Enum                     | Description                                                  |
| ------------------------ | ------------------------------------------------------------ |
| ARKUI_EDGE_EFFECT_SPRING | Spring effect. When at one of the edges, the component can move beyond the bounds through touches, and produces a bounce effect when the user releases their finger. |
| ARKUI_EDGE_EFFECT_FADE   | Fade effect. When at one of the edges, the component produces a fade effect. |
| ARKUI_EDGE_EFFECT_NONE   | No effect when the component is at one of the edges.         |


### ArkUI_EllipsisMode

```
enum ArkUI_EllipsisMode

```

**Description**

Enumerates the ellipsis positions.

**Since**: 12

| Enum                       | Description                                            |
| -------------------------- | ------------------------------------------------------ |
| ARKUI_ELLIPSIS_MODE_START  | An ellipsis is used at the start of the line of text.  |
| ARKUI_ELLIPSIS_MODE_CENTER | An ellipsis is used at the center of the line of text. |
| ARKUI_ELLIPSIS_MODE_END    | An ellipsis is used at the end of the line of text.    |


### ArkUI_EnterKeyType

```
enum ArkUI_EnterKeyType

```

**Description**

Enumerates the types of the Enter key for a single-line text box.

**Since**: 12

| Enum                          | Description                          |
| ----------------------------- | ------------------------------------ |
| ARKUI_ENTER_KEY_TYPE_GO       | The Enter key is labeled "Go."       |
| ARKUI_ENTER_KEY_TYPE_SEARCH   | The Enter key is labeled "Search."   |
| ARKUI_ENTER_KEY_TYPE_SEND     | The Enter key is labeled "Send."     |
| ARKUI_ENTER_KEY_TYPE_NEXT     | The Enter key is labeled "Next."     |
| ARKUI_ENTER_KEY_TYPE_DONE     | The Enter key is labeled "Done."     |
| ARKUI_ENTER_KEY_TYPE_PREVIOUS | The Enter key is labeled "Previous." |
| ARKUI_ENTER_KEY_TYPE_NEW_LINE | The Enter key is labeled "Return."   |


### ArkUI_ErrorCode

```
enum ArkUI_ErrorCode

```

**Description**

Defines an enum for the error codes.

**Since**: 12

| Enum                                                 | Description                                                  |
| ---------------------------------------------------- | ------------------------------------------------------------ |
| ARKUI_ERROR_CODE_NO_ERROR                            | No error.                                                    |
| ARKUI_ERROR_CODE_PARAM_INVALID                       | Parameter error.                                             |
| ARKUI_ERROR_CODE_ATTRIBUTE_OR_EVENT_NOT_SUPPORTED    | The component does not support specific attributes or events. |
| ARKUI_ERROR_CODE_NOT_SUPPROTED_FOR_ARKTS_NODE        | The specific operation is not allowed on the node created by ArkTS. |
| ARKUI_ERROR_CODE_NODE_ADAPTER_NONE_HOST              | The adapter for lazy loading is not bound to the component.  |
| ARKUI_ERROR_CODE_NODE_ADAPTER_EXIST_IN_HOST          | The adapter already exists.                                  |
| ARKUI_ERROR_CODE_NODE_ADAPTER_CHILD_NODE_EXIST       | Failed to add the adapter because the corresponding node already has a subnode. |
| ARKUI_ERROR_CODE_NODE_EVENT_PARAM_INDEX_OUT_OF_RANGE | The parameter length in the parameter event exceeds the limit. |
| ARKUI_ERROR_CODE_NODE_EVENT_PARAM_INVALID            | The data does not exist in the component event.              |
| ARKUI_ERROR_CODE_NODE_EVENT_NO_RETURN                | The component event does not support return values.          |
| ARKUI_ERROR_CODE_NODE_INDEX_INVALID                  | Invalid index.                                               |
| ARKUI_ERROR_CODE_GET_INFO_FAILED                     | Failed to obtain the route navigation information.           |
| ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR                   | Buffer size error.                                           |
| ARKUI_ERROR_CODE_NON_SCROLLABLE_CONTAINER  | The component is not a scrollable container. |
| ARKUI_ERROR_CODE_BUFFER_SIZE_NOT_ENOUGH  | The buffer is not large enough. |


### ArkUI_FinishCallbackType

```
enum ArkUI_FinishCallbackType

```

**Description**

Enumerates the animation **onFinish** callback types.

**Since**: 12

| Enum                            | Description                                                  |
| ------------------------------- | ------------------------------------------------------------ |
| ARKUI_FINISH_CALLBACK_REMOVED   | The callback is invoked when the entire animation is removed once it has finished. |
| ARKUI_FINISH_CALLBACK_LOGICALLY | The callback is invoked when the animation logically enters the falling state, though it may still be in its long tail state. |


### ArkUI_FlexAlignment

```
enum ArkUI_FlexAlignment

```

**Description**

Enumerates the vertical alignment modes.

**Since**: 12

| Enum                               | Description                                                  |
| ---------------------------------- | ------------------------------------------------------------ |
| ARKUI_FLEX_ALIGNMENT_START         | The child components are aligned with the start edge of the main axis. |
| ARKUI_FLEX_ALIGNMENT_CENTER        | The child components are aligned in the center of the main axis. |
| ARKUI_FLEX_ALIGNMENT_END           | The child components are aligned with the end edge of the main axis. |
| ARKUI_FLEX_ALIGNMENT_SPACE_BETWEEN | The child components are evenly distributed along the main axis. The space between any two adjacent components is the same. The first component is aligned with the main-start, and the last component is aligned with the main-end. |
| ARKUI_FLEX_ALIGNMENT_SPACE_AROUND  | The child components are evenly distributed along the main axis. The space between any two adjacent components is the same. The space between the first component and main-start, and that between the last component and cross-main are both half the size of the space between two adjacent components. |
| ARKUI_FLEX_ALIGNMENT_SPACE_EVENLY  | The child components are evenly distributed along the main axis. The space between the first component and main-start, the space between the last component and main-end, and the space between any two adjacent components are the same. |


### ArkUI_FlexDirection

```
enum ArkUI_FlexDirection

```

**Description**

Enumerates the directions of the main axis in the flex container.

**Since**: 12

| Enum                                | Description                                                  |
| ----------------------------------- | ------------------------------------------------------------ |
| ARKUI_FLEX_DIRECTION_ROW            | The child components are arranged in the same direction as the main axis runs along the rows. |
| ARKUI_FLEX_DIRECTION_COLUMN         | The child components are arranged in the same direction as the main axis runs down the columns. |
| ARKUI_FLEX_DIRECTION_ROW_REVERSE    | The child components are arranged opposite to the **ROW** direction. |
| ARKUI_FLEX_DIRECTION_COLUMN_REVERSE | The child components are arranged opposite to the **COLUMN** direction. |


### ArkUI_FlexWrap

```
enum ArkUI_FlexWrap

```

**Description**

Defines whether the flex container has a single line or multiple lines.

**Since**: 12

| Enum                         | Description                                                  |
| ---------------------------- | ------------------------------------------------------------ |
| ARKUI_FLEX_WRAP_NO_WRAP      | The child components in the flex container are arranged in a single line, and they cannot overflow. |
| ARKUI_FLEX_WRAP_WRAP         | The child components in the flex container are arranged in multiple lines, and they may overflow. |
| ARKUI_FLEX_WRAP_WRAP_REVERSE | The child components in the flex container are reversely arranged in multiple lines, and they may overflow. |


### ArkUI_FontStyle

```
enum ArkUI_FontStyle

```

**Description**

Enumerates the font styles.

**Since**: 12

| Enum                    | Description          |
| ----------------------- | -------------------- |
| ARKUI_FONT_STYLE_NORMAL | Standard font style. |
| ARKUI_FONT_STYLE_ITALIC | Italic font style.   |


### ArkUI_FontWeight

```
enum ArkUI_FontWeight

```

**Description**

Enumerates the font weights.

**Since**: 12

| Enum                      | Description                 |
| ------------------------- | --------------------------- |
| ARKUI_FONT_WEIGHT_W100    | 100                         |
| ARKUI_FONT_WEIGHT_W200    | 200                         |
| ARKUI_FONT_WEIGHT_W300    | 300                         |
| ARKUI_FONT_WEIGHT_W400    | 400                         |
| ARKUI_FONT_WEIGHT_W500    | 500                         |
| ARKUI_FONT_WEIGHT_W600    | 600                         |
| ARKUI_FONT_WEIGHT_W700    | 700                         |
| ARKUI_FONT_WEIGHT_W800    | 800                         |
| ARKUI_FONT_WEIGHT_W900    | 900                         |
| ARKUI_FONT_WEIGHT_BOLD    | The font weight is bold.    |
| ARKUI_FONT_WEIGHT_NORMAL  | The font weight is normal.  |
| ARKUI_FONT_WEIGHT_BOLDER  | The font weight is bolder.  |
| ARKUI_FONT_WEIGHT_LIGHTER | The font weight is lighter. |
| ARKUI_FONT_WEIGHT_MEDIUM  | The font weight is medium.  |
| ARKUI_FONT_WEIGHT_REGULAR | The font weight is normal.  |


### ArkUI_GestureDirection

```
enum ArkUI_GestureDirection

```

**Description**

Enumerates gesture directions.

**Since**: 12

| Enum                         | Description           |
| ---------------------------- | --------------------- |
| GESTURE_DIRECTION_ALL        | All directions.       |
| GESTURE_DIRECTION_HORIZONTAL | Horizontal direction. |
| GESTURE_DIRECTION_VERTICAL   | Vertical direction.   |
| GESTURE_DIRECTION_LEFT       | Leftward.             |
| GESTURE_DIRECTION_RIGHT      | Rightward.            |
| GESTURE_DIRECTION_UP         | Upward.               |
| GESTURE_DIRECTION_DOWN       | Downward.             |
| GESTURE_DIRECTION_NONE       | None.                 |


### ArkUI_GestureEventActionType

```
enum ArkUI_GestureEventActionType
```

**Description**

Enumerates gesture event types.

**Since**: 12

| Enum                        | Description |
| --------------------------- | ----------- |
| GESTURE_EVENT_ACTION_ACCEPT | Triggered.  |
| GESTURE_EVENT_ACTION_UPDATE | Updated.    |
| GESTURE_EVENT_ACTION_END    | Ended.      |
| GESTURE_EVENT_ACTION_CANCEL | Canceled.   |


### ArkUI_GestureInterruptResult

```
enum ArkUI_GestureInterruptResult
```

**Description**

Enumerates gesture interruption results.

**Since**: 12

| Enum                              | Description                                |
| --------------------------------- | ------------------------------------------ |
| GESTURE_INTERRUPT_RESULT_CONTINUE | The gesture recognition process continues. |
| GESTURE_INTERRUPT_RESULT_REJECT   | The gesture recognition process is paused. |


### ArkUI_GestureMask

```
enum ArkUI_GestureMask
```

**Description**

Enumerates gesture masking modes.

**Since**: 12

| Enum                         | Description                                                  |
| ---------------------------- | ------------------------------------------------------------ |
| NORMAL_GESTURE_MASK          | The gestures of child components are enabled and recognized based on the default gesture recognition sequence. |
| IGNORE_INTERNAL_GESTURE_MASK | The gestures of child components are disabled, including the built-in gestures. |


### ArkUI_GesturePriority

```
enum ArkUI_GesturePriority
```

**Description**

Enumerates gesture event modes.

**Since**: 12

| Enum     | Description    |
| -------- | -------------- |
| NORMAL   | Normal.        |
| PRIORITY | High-priority. |
| PARALLEL | Parallel.      |


### ArkUI_GestureRecognizerState

```
enum ArkUI_GestureRecognizerState
```

**Description**

Enumerates the gesture recognizer states.

**Since**: 12

| Enum                                      | Description      |
| ----------------------------------------- | ---------------- |
| ARKUI_GESTURE_RECOGNIZER_STATE_REDAY      | Prepared.        |
| ARKUI_GESTURE_RECOGNIZER_STATE_DETECTING  | Check status.    |
| ARKUI_GESTURE_RECOGNIZER_STATE_PENDING    | Waiting          |
| ARKUI_GESTURE_RECOGNIZER_STATE_BLOCKED    | Blocked.         |
| ARKUI_GESTURE_RECOGNIZER_STATE_SUCCESSFUL | (Success status) |
| ARKUI_GESTURE_RECOGNIZER_STATE_FAILED     | Failed.          |


### ArkUI_GestureRecognizerType

```
enum ArkUI_GestureRecognizerType
```

**Description**

Enumerates gesture recognizer types.

**Since**: 12

| Enum               | Description          |
| ------------------ | -------------------- |
| TAP_GESTURE        | Tap.                 |
| LONG_PRESS_GESTURE | Long press gesture.  |
| PAN_GESTURE        | Pan gesture.         |
| PINCH_GESTURE      | Pinch gesture.       |
| ROTATION_GESTURE   | Rotation gesture.    |
| SWIPE_GESTURE      | Swipe gesture.       |
| GROUP_GESTURE      | A group of gestures. |


### ArkUI_GroupGestureMode

```
enum ArkUI_GroupGestureMode

```

**Description**

Enumerates gesture group modes.

**Since**: 12

| Enum| Description|
| -------- | -------- |
| SEQUENTIAL_GROUP  | Sequential recognition. Gestures are recognized in the registration sequence until all gestures are recognized successfully. Once one gesture fails to be recognized, all subsequent gestures fail to be recognized. Only the last gesture in the gesture group can respond to the end event. |
| PARALLEL_GROUP  | Parallel recognition. Registered gestures are recognized concurrently until all gestures are recognized. The recognition result of each gesture does not affect each other. |
| EXCLUSIVE_GROUP | Exclusive recognition. Registered gestures are identified concurrently. If one gesture is successfully recognized, gesture recognition ends. |


### ArkUI_HitTestMode

```
enum ArkUI_HitTestMode

```

**Description**

Enumerates the hit test modes.

**Since**: 12

| Enum                            | Description                                                  |
| ------------------------------- | ------------------------------------------------------------ |
| ARKUI_HIT_TEST_MODE_DEFAULT     | Both the node and its child node respond to the hit test of a touch event, but its sibling node is blocked from the hit test. |
| ARKUI_HIT_TEST_MODE_BLOCK       | The node responds to the hit test of a touch event, but its child node and sibling node are blocked from the hit test. |
| ARKUI_HIT_TEST_MODE_TRANSPARENT | Both the node and its child node respond to the hit test of a touch event, and its sibling node is also considered during the hit test. |
| ARKUI_HIT_TEST_MODE_NONE        | The node does not respond to the hit test of a touch event.  |


### ArkUI_HorizontalAlignment

```
enum ArkUI_HorizontalAlignment

```

**Description**

Enumerates the alignment mode in the horizontal direction.

**Since**: 12

| Enum                              | Description                                                  |
| --------------------------------- | ------------------------------------------------------------ |
| ARKUI_HORIZONTAL_ALIGNMENT_START  | Aligned with the start edge in the same direction as the language in use. |
| ARKUI_HORIZONTAL_ALIGNMENT_CENTER | Aligned with the center. This is the default alignment mode. |
| ARKUI_HORIZONTAL_ALIGNMENT_END    | Aligned with the end edge in the same direction as the language in use. |


### ArkUI_ImageInterpolation

```
enum ArkUI_ImageInterpolation

```

**Description**

Enumerates the image interpolation effects.

**Since**: 12

| Enum                             | Description                                                  |
| -------------------------------- | ------------------------------------------------------------ |
| ARKUI_IMAGE_INTERPOLATION_NONE   | No image interpolation.                                      |
| ARKUI_IMAGE_INTERPOLATION_LOW    | Low quality interpolation.                                   |
| ARKUI_IMAGE_INTERPOLATION_MEDIUM | Medium quality interpolation.                                |
| ARKUI_IMAGE_INTERPOLATION_HIGH   | High quality interpolation. This mode produces scaled images of the highest possible quality. |


### ArkUI_ImageRenderMode

```
enum ArkUI_ImageRenderMode

```

**Description**

Enumerates the image rendering modes.

**Since**: 12

| Enum                             | Description                                                  |
| -------------------------------- | ------------------------------------------------------------ |
| ARKUI_IMAGE_RENDER_MODE_ORIGINAL | Render image pixels as they are in the original source image. |
| ARKUI_IMAGE_RENDER_MODE_TEMPLATE | Render image pixels to create a monochrome template image.   |


### ArkUI_ImageRepeat

```
enum ArkUI_ImageRepeat

```

**Description**

Enumerates the image repeat patterns.

**Since**: 12

| Enum                    | Description                                          |
| ----------------------- | ---------------------------------------------------- |
| ARKUI_IMAGE_REPEAT_NONE | The image is not repeatedly drawn.                   |
| ARKUI_IMAGE_REPEAT_X    | The image is repeatedly drawn only along the x-axis. |
| ARKUI_IMAGE_REPEAT_Y    | The image is repeatedly drawn only along the y-axis. |
| ARKUI_IMAGE_REPEAT_XY   | The image is repeatedly drawn along both axes.       |


### ArkUI_ImageSize

```
enum ArkUI_ImageSize

```

**Description**

Defines the image size.

**Since**: 12

| Enum                     | Description                                                  |
| ------------------------ | ------------------------------------------------------------ |
| ARKUI_IMAGE_SIZE_AUTO    | The original image aspect ratio is retained.                 |
| ARKUI_IMAGE_SIZE_COVER   | Default value. The image is scaled with its aspect ratio retained for both sides to be greater than or equal to the display boundaries. |
| ARKUI_IMAGE_SIZE_CONTAIN | The image is scaled with its aspect ratio retained for the content to be completely displayed within the display boundaries. |


### ArkUI_ImageSpanAlignment

```
enum ArkUI_ImageSpanAlignment

```

**Description**

Enumerates the alignment mode of the image with the text.

**Since**: 12

| Enum                                | Description                                         |
| ----------------------------------- | --------------------------------------------------- |
| ARKUI_IMAGE_SPAN_ALIGNMENT_BASELINE | The image is bottom aligned with the text baseline. |
| ARKUI_IMAGE_SPAN_ALIGNMENT_BOTTOM   | The image is bottom aligned with the text.          |
| ARKUI_IMAGE_SPAN_ALIGNMENT_CENTER   | The image is centered aligned with the text.        |
| ARKUI_IMAGE_SPAN_ALIGNMENT_TOP      | The image is top aligned with the text.             |


### ArkUI_ItemAlignment

```
enum ArkUI_ItemAlignment

```

**Description**

Enumerates the modes in which components are laid out along the cross axis of the container.

**Since**: 12

| Enum                          | Description                                                  |
| ----------------------------- | ------------------------------------------------------------ |
| ARKUI_ITEM_ALIGNMENT_AUTO     | The default configuration of the flex container is used.     |
| ARKUI_ITEM_ALIGNMENT_START    | The items in the flex container are aligned with the cross-start edge. |
| ARKUI_ITEM_ALIGNMENT_CENTER   | The items in the flex container are centered along the cross axis. |
| ARKUI_ITEM_ALIGNMENT_END      | The items in the flex container are aligned with the cross-end edge. |
| ARKUI_ITEM_ALIGNMENT_STRETCH  | The items in the flex container are stretched and padded along the cross axis. |
| ARKUI_ITEM_ALIGNMENT_BASELINE | The items in the flex container are aligned in such a manner that their text baselines are aligned along the cross axis. |


### ArkUI_LengthMetricUnit

```
enum ArkUI_LengthMetricUnit

```

**Description**

Enumerates the component units.

**Since**: 12

| Enum                             | Description                                          |
| -------------------------------- | ---------------------------------------------------- |
| ARKUI_LENGTH_METRIC_UNIT_DEFAULT | Default, which is fp for fonts and vp for non-fonts. |
| ARKUI_LENGTH_METRIC_UNIT_PX      | px.                                                  |
| ARKUI_LENGTH_METRIC_UNIT_VP      | vp.                                                  |
| ARKUI_LENGTH_METRIC_UNIT_FP      | fp.                                                  |


### ArkUI_LinearGradientDirection

```
enum ArkUI_LinearGradientDirection

```

**Description**

Enumerates the gradient directions.

**Since**: 12

| Enum                                         | Description                     |
| -------------------------------------------- | ------------------------------- |
| ARKUI_LINEAR_GRADIENT_DIRECTION_LEFT         | From right to left.             |
| ARKUI_LINEAR_GRADIENT_DIRECTION_TOP          | From bottom to top.             |
| ARKUI_LINEAR_GRADIENT_DIRECTION_RIGHT        | From left to right.             |
| ARKUI_LINEAR_GRADIENT_DIRECTION_BOTTOM       | From top to bottom.             |
| ARKUI_LINEAR_GRADIENT_DIRECTION_LEFT_TOP     | From lower right to upper left. |
| ARKUI_LINEAR_GRADIENT_DIRECTION_LEFT_BOTTOM  | From upper right to lower left. |
| ARKUI_LINEAR_GRADIENT_DIRECTION_RIGHT_TOP    | From lower left to upper right. |
| ARKUI_LINEAR_GRADIENT_DIRECTION_RIGHT_BOTTOM | From upper left to lower right. |
| ARKUI_LINEAR_GRADIENT_DIRECTION_NONE         | No gradient.                    |
| ARKUI_LINEAR_GRADIENT_DIRECTION_CUSTOM       | Custom direction.               |


### ArkUI_ListItemAlignment

```
enum ArkUI_ListItemAlignment

```

**Description**

Enumerates the alignment modes of items along the cross axis.

**Since**: 12

| Enum                             | Description                                                  |
| -------------------------------- | ------------------------------------------------------------ |
| ARKUI_LIST_ITEM_ALIGNMENT_START  | The list items are packed toward the start edge of the **List** component along the cross axis. |
| ARKUI_LIST_ITEM_ALIGNMENT_CENTER | The list items are centered in the **List** component along the cross axis. |
| ARKUI_LIST_ITEM_ALIGNMENT_END    | The list items are packed toward the end edge of the **List** component along the cross axis. |


### ArkUI_ListItemSwipeActionState

```
enum ArkUI_ListItemSwipeActionState

```

**Description**

Enumerates the swipe action item states of list items.

**Since**: 12

| Enum                                         | Description                                                  |
| -------------------------------------------- | ------------------------------------------------------------ |
| ARKUI_LIST_ITEM_SWIPE_ACTION_STATE_COLLAPSED | Collapsed state. When the list item is swiped in the opposite direction of the main axis, the swipe action item is hidden. |
| ARKUI_LIST_ITEM_SWIPE_ACTION_STATE_EXPANDED  | Expanded state. When the list item is swiped in the opposite direction of the main axis, the swipe action item is shown. |
| ARKUI_LIST_ITEM_SWIPE_ACTION_STATE_ACTIONING | In-action state. The list item is in this state when it enters the delete area. |


### ArkUI_ListItemSwipeEdgeEffect

```
enum ArkUI_ListItemSwipeEdgeEffect

```

**Description**

Enumerates the swipe action item edge effects of list items.

**Since**: 12

| Enum                                     | Description                                                  |
| ---------------------------------------- | ------------------------------------------------------------ |
| ARKUI_LIST_ITEM_SWIPE_EDGE_EFFECT_SPRING | When the list item scrolls to the edge of the list, it can continue to scroll for a distance. |
| ARKUI_LIST_ITEM_SWIPE_EDGE_EFFECT_NONE   | The list item cannot scroll beyond the edge of the list.     |


### ArkUI_MaskType

```
enum ArkUI_MaskType

```

**Description**

Enumerates the mask types.

**Since**: 12

| Enum                      | Description         |
| ------------------------- | ------------------- |
| ARKUI_MASK_TYPE_RECTANGLE | Rectangle.          |
| ARKUI_MASK_TYPE_CIRCLE    | **(circle)**        |
| ARKUI_MASK_TYPE_ELLIPSE   | Ellipse.            |
| ARKUI_MASK_TYPE_PATH      | Path Type           |
| ARKUI_MASK_TYPE_PROGRESS  | Progress indicator. |


### ArkUI_NativeAPIVariantKind

```
enum ArkUI_NativeAPIVariantKind

```

**Description**

Defines the native API types.

**Since**: 12

| Enum| Description|
| -------------------- | ------------------------------------------------------------ |
| ARKUI_NATIVE_NODE    | API related to UI components. For details, see the struct definition in &lt;arkui/native_node.h&gt;. |
| ARKUI_NATIVE_DIALOG  | API related to dialog boxes. For details, see the struct definition in &lt;arkui/native_node.h&gt;. |
| ARKUI_NATIVE_GESTURE | API related to gestures. For details, see the struct definition in &lt;arkui/native_node.h&gt;. |
| ARKUI_NATIVE_ANIMATE | API related to animations. For details, see the struct definition in &lt;arkui/native_animate.h&gt;. |


### ArkUI_NavDestinationState

```
enum ArkUI_NavDestinationState

```

**Description**

Defines an enum for the **NavDestination** component states.

**Since**: 12

| Enum                                          | Description                                                  |
| --------------------------------------------- | ------------------------------------------------------------ |
| ARKUI_NAV_DESTINATION_STATE_ON_SHOW           | The **NavDestination** component is displayed.               |
| ARKUI_NAV_DESTINATION_STATE_ON_HIDE           | The **NavDestination** component is hidden.                  |
| ARKUI_NAV_DESTINATION_STATE_ON_APPEAR         | The **NavDestination** component is mounted to the component tree. |
| ARKUI_NAV_DESTINATION_STATE_ON_DISAPPEAR      | The **NavDestination** component is unmounted from the component tree. |
| ARKUI_NAV_DESTINATION_STATE_ON_WILL_SHOW      | The **NavDestination** is about to be displayed.             |
| ARKUI_NAV_DESTINATION_STATE_ON_WILL_HIDE      | The **NavDestination** is about to be hidden.                |
| ARKUI_NAV_DESTINATION_STATE_ON_WILL_APPEAR    | The **NavDestination** is about to be mounted to the component tree. |
| ARKUI_NAV_DESTINATION_STATE_ON_WILL_DISAPPEAR | The **NavDestination** component is about to be unmounted from the component tree. |
| ARKUI_NAV_DESTINATION_STATE_ON_BACK_PRESS     | The back button is pressed for the **NavDestination** component. |


### ArkUI_NodeAdapterEventType

```
enum ArkUI_NodeAdapterEventType
```

**Description**

Enumerates node adapter events.

**Since**: 12

| Enum                                           | Description                                                  |
| ---------------------------------------------- | ------------------------------------------------------------ |
| NODE_ADAPTER_EVENT_WILL_ATTACH_TO_NODE         | This event occurs when the component is attached to the adapter. |
| NODE_ADAPTER_EVENT_WILL_DETACH_FROM_NODE       | This event occurs when the component is detached from the adapter. |
| NODE_ADAPTER_EVENT_ON_GET_NODE_ID              | This event occurs when the adapter obtains the unique ID of the new element to add. |
| NODE_ADAPTER_EVENT_ON_ADD_NODE_TO_ADAPTER      | This event occurs when the adapter obtains the content of the new element to add. |
| NODE_ADAPTER_EVENT_ON_REMOVE_NODE_FROM_ADAPTER | This event occurs when the adapter removes an element.       |

### ArkUI_NodeAttributeType

```
enum ArkUI_NodeAttributeType
```

**Description**

Defines the ArkUI style attributes that can be set on the native side.

**Since**: 12

| Enum                                        | Description                                                  |
| ------------------------------------------- | ------------------------------------------------------------ |
| NODE_WIDTH                                  | Defines the width attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: width, in vp.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: width, in vp.|
| NODE_HEIGHT                                 | Defines the height attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: height, in vp.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: height, in vp.|
| NODE_BACKGROUND_COLOR                       | Defines the background color attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].u32: background color, in 0xARGB format. For example, 0xFFFF0000 indicates red.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].u32: background color, in 0xARGB format. For example, 0xFFFF0000 indicates red.|
| NODE_BACKGROUND_IMAGE                       | Defines the background image attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.string: image address.<br>.value[0]?.i32: whether to repeat the image. Optional. The parameter type is [ArkUI_ImageRepeat](#arkui_imagerepeat). The default value is **ARKUI_IMAGE_REPEAT_NONE**.<br>.object: **PixelMap** object. The parameter type is [ArkUI_DrawableDescriptor](#arkui_drawabledescriptor).<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string: image address.<br>.value[0].i32: whether to repeat the image. The parameter type is [ArkUI_ImageRepeat](#arkui_imagerepeat).<br>.object: **PixelMap** object. The parameter type is [ArkUI_DrawableDescriptor](#arkui_drawabledescriptor). Either **.object** or **.string** must be set.|
| NODE_PADDING                                | Defines the padding attribute, which can be set, reset, and obtained as required through APIs.<br>There are two formats of [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) for setting the attribute value:<br>1: Specify the same padding for the four directions.<br>.value[0].f32: padding, in vp.<br>2: Specify different paddings for different directions.<br>.value[0].f32: top padding, in vp.<br>.value[1].f32: right padding, in vp.<br>.value[2].f32: bottom padding, in vp.<br>.value[3].f32: left padding, in vp.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: top padding, in vp.<br>.value[1].f32: right padding, in vp.<br>.value[2].f32: bottom padding, in vp.<br>.value[3].f32: left padding, in vp.|
| NODE_ID                                     | Defines the component ID attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.string: component ID.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string: component ID.|
| NODE_ENABLED                                | Defines the interactivity attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: The value **true** means that the component can interact with users, and **false** means the opposite.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: The value **1** means that the component can interact with users, and **0** means the opposite. |
| NODE_MARGIN                                 | Defines the margin attribute, which can be set, reset, and obtained as required through APIs.<br>There are two formats of [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) for setting the attribute value:<br>1: Specify the same margin for the four directions.<br>.value[0].f32: margin, in vp.<br>2: Specify different margins for different directions.<br>.value[0].f32: top margin, in vp.<br>.value[1].f32: right margin, in vp.<br>.value[2].f32: bottom margin, in vp.<br>.value[3].f32: left margin, in vp.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: top margin, in vp.<br>.value[1].f32: right margin, in vp.<br>.value[2].f32: bottom margin, in vp.<br>.value[3].f32: left margin, in vp.|
| NODE_TRANSLATE                              | Defines the translate attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: distance to translate along the x-axis, in vp. The default value is **0**.<br>.value[1].f32: distance to translate along the y-axis, in vp. The default value is **0**.<br>.value[2].f32: distance to translate along the z-axis, in vp. The default value is **0**.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: distance to translate along the x-axis, in vp.<br>.value[1].f32: distance to translate along the y-axis, in vp.<br>.value[2].f32: distance to translate along the z-axis, in vp.|
| NODE_SCALE                                  | Defines the scale attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: scale factor along the x-axis. The default value is **1**.<br>.value[1].f32: scale factor along the y-axis. The default value is **1**.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: scale factor along the x-axis.<br>.value[1].f32: scale factor along the y-axis.|
| NODE_ROTATE                                 | Defines the rotate attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: X-coordinate of the rotation axis vector. The default value is **0**.<br>.value[1].f32: Y-coordinate of the rotation axis vector. The default value is **0**.<br>.value[2].f32: Z-coordinate of the rotation axis vector. The default value is **0**.<br>.value[3].f32: rotation angle. The default value is **0**.<br>.value[4].f32: line of sight, that is, the distance from the viewpoint to the z=0 plane, in vp. The default value is **0**.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: X-coordinate of the rotation axis vector.<br>.value[1].f32: Y-coordinate of the rotation axis vector.<br>.value[2].f32: Z-coordinate of the rotation axis vector.<br>.value[3].f32: rotation angle.<br>.value[4].f32: line of sight, that is, the distance from the viewpoint to the z=0 plane, in vp.|
| NODE_BRIGHTNESS                             | Sets the brightness attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: brightness value. The default value is **1.0**, and the recommended value range is [0, 2].<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: brightness value.|
| NODE_SATURATION                             | Sets the saturation attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: saturation value. The default value is **1.0**, and the recommended value range is [0, 50).<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: saturation value.|
| NODE_BLUR                                   | Sets the blur attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: blur radius. The larger the fuzzy radius, the more blurred the image. If the value is **0**, the image is not blurred. The unit is px. The default value is **0.0**.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: blur radius. The larger the fuzzy radius, the more blurred the image. If the value is **0**, the image is not blurred. The unit is px.|
| NODE_LINEAR_GRADIENT                        | Sets the gradient attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: start angle of the linear gradient. This attribute takes effect only when [ArkUI_LinearGradientDirection](#arkui_lineargradientdirection) is set to **ARKUI_LINEAR_GRADIENT_DIRECTION_CUSTOM**. A positive value indicates a clockwise rotation from the origin, (0, 0). The default value is **180**.<br>.value[1].i32: direction of the linear gradient. When it is set, the **angle** attribute does not take effect. The data type is [ArkUI_LinearGradientDirection](#arkui_lineargradientdirection)<br>.value[2].i32: whether the colors are repeated. The default value is **false**.<br>.object: The parameter type is [ArkUI_ColorStop](_ark_u_i___color_stop.md). - **colors**: array of color stops, each of which consists of a color and its stop position. Invalid colors are automatically skipped.<br>**colors**: colors of the color stops.<br>**stops**: stop positions of the color stops.<br>**size**: number of colors.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: start angle of the linear gradient. The set value is used only when **ArkUI_LinearGradientDirection** is set to **ARKUI_LINEAR_GRADIENT_DIRECTION_CUSTOM**. In other cases, the default value is used.<br>.value[1].i32: direction of the linear gradient.<br>.value[2].i32: whether the colors are repeated.<br>.object: array of color stops, each of which consists of a color and its stop position. Invalid colors are automatically skipped. The parameter type is [ArkUI_ColorStop](_ark_u_i___color_stop.md).<br>**colors**: colors of the color stops.<br>**stops**: stop positions of the color stops.<br>**size**: number of colors.|
| NODE_ALIGNMENT                              | Sets the alignment attribute, which can be set, reset, and obtained as required through APIs.<br>In the **Stack** component, this attribute has the same effect as **NODE_STACK_ALIGN_CONTENT**, which means that it sets the alignment mode of child components in the container.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: alignment mode. The parameter type is [ArkUI_Alignment](#arkui_alignment). The default value is **ARKUI_ALIGNMENT_CENTER**.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: alignment mode. The parameter type is [ArkUI_Alignment](#arkui_alignment).|
| NODE_OPACITY                                | Defines the opacity attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: opacity value. The value ranges from 0 to 1.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: opacity value. The value ranges from 0 to 1.|
| NODE_BORDER_WIDTH                           | Defines the border width attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>1: .value[0].f32: width of the four borders.<br>2: .value[0].f32: width of the top border.<br>.value[1].f32: width of the right border.<br>.value[2].f32: width of the bottom border.<br>.value[3].f32: width of the left border.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: width of the top border.<br>.value[1].f32: width of the right border.<br>.value[2].f32: width of the bottom border.<br>.value[3].f32: width of the left border.|
| NODE_BORDER_RADIUS                          | Defines the border corner radius attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>1: .value[0].f32: radius of the four corners.<br>2: .value[0].f32: radius of the upper left corner.<br>.value[1].f32: radius of the upper right corner.<br>.value[2].f32: radius of the lower left corner.<br>.value[3].f32: radius of the lower right corner.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: radius of the upper left corner.<br>.value[1].f32: radius of the upper right corner.<br>.value[2].f32: radius of the lower left corner.<br>.value[3].f32: radius of the lower right corner.|
| NODE_BORDER_COLOR                           | Defines the border color attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>1: .value[0].u32: color of the four borders, in 0xARGB format, for example, **0xFFFF11FF**.<br>2: .value[0].u32: color of the top border, in 0xARGB format, for example, **0xFFFF11FF**.<br>.value[1].u32: color of the right border, in 0xARGB format, for example, **0xFFFF11FF**.<br>.value[2].u32: color of the lower border, in 0xARGB format, for example, **0xFFFF11FF**.<br>.value[3].u32: color of the left border, in 0xARGB format, for example, **0xFFFF11FF**.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].u32: color of the top border, in 0xARGB format, for example, **0xFFFF11FF**.<br>.value[1].u32: color of the right border, in 0xARGB format, for example, **0xFFFF11FF**.<br>.value[2].u32: color of the lower border, in 0xARGB format, for example, **0xFFFF11FF**.<br>.value[3].u32: color of the left border, in 0xARGB format, for example, **0xFFFF11FF**.|
| NODE_BORDER_STYLE                           | Defines the border line style attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>1: .value[0].i32: line style of the four borders. The parameter type is [ArkUI_BorderStyle](#arkui_borderstyle). The default value is **ARKUI_BORDER_STYLE_SOLID**.<br>2: .value[0].i32: line style of the top border. The parameter type is **ArkUI_BorderStyle**. The default value is **ARKUI_BORDER_STYLE_SOLID**.<br>.value[1].i32: line style of the right border. The parameter type is [ArkUI_BorderStyle](#arkui_borderstyle). The default value is **ARKUI_BORDER_STYLE_SOLID**.<br>.value[2].i32: line style of the bottom border. The parameter type is [ArkUI_BorderStyle](#arkui_borderstyle). The default value is **ARKUI_BORDER_STYLE_SOLID**.<br>.value[3].i32: line style of the left border. The parameter type is [ArkUI_BorderStyle](#arkui_borderstyle). The default value is **ARKUI_BORDER_STYLE_SOLID**.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: line style of the top border.<br>.value[1].i32: line style of the right border.<br>.value[2].i32: line style of the bottom border.<br>.value[3].i32: line style of the left border.|
| NODE_Z_INDEX                                | Defines the z-index attribute for the stack sequence. APIs are provided for setting, resetting, and obtaining the attribute value.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: z-index value.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: z-index value.|
| NODE_VISIBILITY                             | Defines the visibility attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: whether to show or hide the component. The parameter type is [ArkUI_Visibility](#arkui_visibility). The default value is **ARKUI_VISIBILITY_VISIBLE**.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: whether to show or hide the component. The parameter type is [ArkUI_Visibility](#arkui_visibility). The default value is **ARKUI_VISIBILITY_VISIBLE**.|
| NODE_CLIP                                   | Defines the clip attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: whether to clip the component based on the parent container bounds. The value **0** means to clip the component, and **1** means the opposite.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: whether to clip the component based on the parent container bounds. The value **0** means to clip the component, and **1** means the opposite.|
| NODE_CLIP_SHAPE                             | Defines the clipping region on the component. This attribute can be set and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute, which supports five types of shapes:<br>1. Rectangle:<br>.value[0].i32: type of shape. The parameter type is [ArkUI_ClipType](#arkui_cliptype). The value is **ARKUI_CLIP_TYPE_RECTANGLE** for the rectangle shape.<br>.value[1].f32: width of the rectangle.<br>.value[2].f32: height of the rectangle.<br>.value[3].f32: width of the rounded corner of the rectangle.<br>.value[4].f32: height of the rounded corner of the rectangle.<br>.value[5]?.f32: radius of the upper left corner of the rectangle. <br>.value[6]?.f32: radius of the lower left corner of the rectangle. <br>.value[7]?.f32: radius of the upper right corner of the rectangle. <br>.value[8]?.f32: radius of the lower right corner of the rectangle. <br>2. Circle:<br>.value[0].i32: type of shape. The parameter type is [ArkUI_ClipType](#arkui_cliptype). The value is **ARKUI_CLIP_TYPE_CIRCLE** for the circle shape.<br>.value[1].f32: width of the circle.<br>.value[2].f32: height of the circle.<br>3. Ellipse:<br>.value[0].i32: type of shape. The parameter type is [ArkUI_ClipType](#arkui_cliptype). The value is **ARKUI_CLIP_TYPE_ELLIPSE** for the ellipse shape.<br>.value[1].f32: width of the ellipse.<br>.value[2].f32: height of the ellipse.<br>4. Path:<br>.value[0].i32: type of shape. The parameter type is [ArkUI_ClipType](#arkui_cliptype). The value is **ARKUI_CLIP_TYPE_PATH** for the path shape.<br>.value[1].f32: width of the path.<br>.value[2].f32: height of the path.<br>.string: command for drawing the path.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md), which supports five types of shapes:<br>1. Rectangle:<br>.value[0].i32: type of shape. The parameter type is [ArkUI_ClipType](#arkui_cliptype). The value is **ARKUI_CLIP_TYPE_RECTANGLE** for the rectangle shape.<br>.value[1].f32: width of the rectangle.<br>.value[2].f32: height of the rectangle.<br>.value[3].f32: width of the rounded corner of the rectangle.<br>.value[4].f32: height of the rounded corner of the rectangle.<br>.value[5]?.f32: radius of the upper left corner of the rectangle. <br>.value[6]?.f32: radius of the lower left corner of the rectangle. <br>.value[7]?.f32: radius of the upper right corner of the rectangle. <br>.value[8]?.f32: radius of the lower right corner of the rectangle. <br>2. Circle:<br>.value[0].i32: type of shape. The parameter type is [ArkUI_ClipType](#arkui_cliptype). The value is **ARKUI_CLIP_TYPE_CIRCLE** for the circle shape.<br>.value[1].f32: width of the circle.<br>.value[2].f32: height of the circle.<br>3. Ellipse:<br>.value[0].i32: type of shape. The parameter type is [ArkUI_ClipType](#arkui_cliptype). The value is **ARKUI_CLIP_TYPE_ELLIPSE** for the ellipse shape.<br>.value[1].f32: width of the ellipse.<br>.value[2].f32: height of the ellipse.<br>4. Path:<br>.value[0].i32: type of shape. The parameter type is [ArkUI_ClipType](#arkui_cliptype). The value is **ARKUI_CLIP_TYPE_PATH** for the path shape.<br>.value[1].f32: width of the path.<br>.value[2].f32: height of the path.<br>.string: command for drawing the path.|
| NODE_TRANSFORM                              | Defines the transform attribute, which can be used to translate, rotate, and scale images. APIs are provided for setting, resetting, and obtaining the attribute value.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0...15].f32: 16 floating-point numbers.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0...15].f32: 16 floating-point numbers.|
| NODE_HIT_TEST_BEHAVIOR                      | Defines the hit test behavior attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: hit test mode. The parameter type is [ArkUI_HitTestMode](#arkui_hittestmode). The default value is **ARKUI_HIT_TEST_MODE_DEFAULT**.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: hit test mode. The parameter type is **ArkKUI_HitTestMode**. The default value is **ARKUI_HIT_TEST_MODE_DEFAULT**.|
| NODE_POSITION                               | Defines the offset attribute, which specifies the offset of the component's upper left corner relative to the parent container's. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: X coordinate.<br>.value[1].f32: Y coordinate.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: X coordinate.<br>.value[1].f32: Y coordinate.|
| NODE_SHADOW                                 | Defines the shadow attribute. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: shadow effect. The parameter type is [ArkUI_ShadowStyle](#arkui_shadowstyle).<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: shadow effect. The parameter type is [ArkUI_ShadowStyle](#arkui_shadowstyle).|
| NODE_CUSTOM_SHADOW                          | Defines the custom shadow effect. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0]?.f32: blur radius of the shadow, in vp.<br>.value[1]?.i32: whether to enable the coloring strategy. The value **1** means to enable the coloring strategy, and **0** (default value) means the opposite.<br>.value[2]?.f32: offset of the shadow along the x-axis, in px.<br>.value[3]?.f32: offset of the shadow along the y-axis, in px.<br>.value[4]?.i32: shadow type [ArkUI_ShadowType](#arkui_shadowtype). The default value is **ARKUI_SHADOW_TYPE_COLOR**.<br>.value[5]?.u32: shadow color, in 0xARGB format. For example, 0xFFFF0000 indicates red.<br>.value[6]?.u32: whether to fill the shadow. The value 1 means to fill the shadow, and 0 means the opposite.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: blur radius of the shadow, in vp.<br>.value[1].i32: whether to enable the coloring strategy. <br>.value[2].f32: offset of the shadow along the x-axis, in px.<br>.value[3].f32: offset of the shadow along the y-axis, in px.<br>.value[4].i32: shadow type [ArkUI_ShadowType](#arkui_shadowtype). The default value is **ARKUI_SHADOW_TYPE_COLOR**.<br>.value[5].u32: shadow color, in 0xARGB format. For example, 0xFFFF0000 indicates red.<br>.value[6].u32: whether to fill the shadow. The value **1** means to fill the shadow, and **0** means the opposite.|
| NODE_BACKGROUND_IMAGE_SIZE                  | Defines the background image width and height. APIs are provided for setting, resetting, and obtaining the attribute value.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: width of the image. The value range is [0, +∞), and the unit is vp.<br>.value[1].f32: height of the image. The value range is [0, +∞), and the unit is vp.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: width of the image, in vp.<br>.value[1].f32: height of the image, in vp.|
| NODE_BACKGROUND_IMAGE_SIZE_WITH_STYLE       | Defines the background image size. APIs are provided for setting, resetting, and obtaining the attribute value.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: size of the background image. The value is an enumerated value of [ArkUI_ImageSize](#arkui_imagesize).<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: size of the background image. The value is an enumerated value of [ArkUI_ImageSize](#arkui_imagesize).|
| NODE_BACKGROUND_BLUR_STYLE                  | Defines the background blur attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: blur type. The value is an enumerated value of [ArkUI_BlurStyle](#arkui_blurstyle).<br>.value[1]?.i32: color mode. The value is an enumerated value of [ArkUI_ColorMode](#arkui_colormode).<br>.value[2]?.i32: adaptive color mode. The value is an enumerated value of [ArkUI_AdaptiveColor](#arkui_adaptivecolor).<br>.value[3]?.f32: blur degree. The value range is [0.0, 1.0].<br>.value[4]?.f32: start boundary of grayscale blur.<br>.value[5]?.f32: end boundary of grayscale blur.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: blur type. The value is an enumerated value of [ArkUI_BlurStyle](#arkui_blurstyle).<br>.value[1].i32: color mode. The value is an enumerated value of [ArkUI_ColorMode](#arkui_colormode).<br>.value[2].i32: adaptive color mode. The value is an enumerated value of [ArkUI_AdaptiveColor](#arkui_adaptivecolor).<br>.value[3].f32: blur degree. The value range is [0.0, 1.0].<br>.value[4].f32: start boundary of grayscale blur.<br>.value[5].f32: end boundary of grayscale blur.|
| NODE_TRANSFORM_CENTER                       | Defines the transform center attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0]?.f32: X coordinate of the center point, in vp.<br>.value[1]?.f32: Y coordinate of the center point, in vp.<br>.value[2]?.f32: Z coordinate of the center point, in vp.<br>.value[3]?.f32 : X coordinate of the center point, expressed in a number that represents a percentage. For example, 0.2 indicates 20%. This attribute overwrites value[0].f32. The default value is **0.5f**.<br>.value[4]?.f32 : Y coordinate of the center point, expressed in a number that represents a percentage. For example, 0.2 indicates 20%. This attribute overwrites value[1].f32. The default value is **0.5f**.<br>.value[5]?.f32 : Z coordinate of the center point, expressed in a number that represents a percentage. For example, 0.2 indicates 20%. This attribute overwrites value[2].f32. The default value is **0.0f**.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: X coordinate of the center point, in vp. <br>.value[1].f32: Y coordinate of the center point, in vp. <br>.value[2].f32: Z coordinate of the center point, in vp. <br>Note: If the coordinate is expressed in a number that represents a percentage, the attribute obtaining API returns the calculated value in vp.|
| NODE_OPACITY_TRANSITION                     | Defines the transition opacity attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: opacity values of the start and end points.<br>.value[1].i32: animation duration, in milliseconds.<br>.value[2].i32: animation curve type. The value is an enumerated value of [ArkUI_AnimationCurve](#arkui_animationcurve).<br>.value[3]?.i32: animation delay duration, in milliseconds.<br>.value[4]?.i32: number of times that the animation is played.<br>.value[5]?.i32: animation playback mode. The value is an enumerated value of [ArkUI_AnimationPlayMode](#arkui_animationplaymode).<br>.value[6]?.f32: animation playback speed.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: opacity values of the start and end points.<br>.value[1].i32: animation duration, in milliseconds.<br>.value[2].i32: animation curve type. The value is an enumerated value of [ArkUI_AnimationCurve](#arkui_animationcurve).<br>.value[3].i32: animation delay duration, in milliseconds.<br>.value[4].i32: number of times that the animation is played.<br>.value[5].i32: animation playback mode. The value is an enumerated value of [ArkUI_AnimationPlayMode](#arkui_animationplaymode).<br>.value[6].f32: animation playback speed.|
| NODE_ROTATE_TRANSITION                      | Defines the transition rotation attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: X-component of the rotation vector.<br>.value[1].f32: Y-component of the rotation vector.<br>.value[2].f32: Z-component of the rotation vector<br>.value[3].f32: angle.<br>.value[4].f32: line of sight. The default value is **0.0f**.<br>.value[5].i32: animation duration, in milliseconds.<br>.value[6].i32: animation curve type. The value is an enumerated value of [ArkUI_AnimationCurve](#arkui_animationcurve).<br>.value[7]?.i32: animation delay duration, in milliseconds.<br>.value[8]?.i32: number of times that the animation is played.<br>.value[9]?.i32: animation playback mode. The value is an enumerated value of [ArkUI_AnimationPlayMode](#arkui_animationplaymode).<br>.value[10]?.f32: animation playback speed.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: X-component of the rotation vector.<br>.value[1].f32: Y-component of the rotation vector.<br>.value[2].f32: Z-component of the rotation vector<br>.value[3].f32: angle.<br>.value[4].f32: line of sight.<br>.value[5].i32: animation duration, in milliseconds.<br>.value[6].i32: animation curve type. The value is an enumerated value of [ArkUI_AnimationCurve](#arkui_animationcurve).<br>.value[7].i32: animation delay duration, in milliseconds.<br>.value[8].i32: number of times that the animation is played.<br>.value[9].i32: animation playback mode. The value is an enumerated value of [ArkUI_AnimationPlayMode](#arkui_animationplaymode).<br>.value[10].f32: animation playback speed.|
| NODE_SCALE_TRANSITION                       | Defines the transition scaling attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: scale factor along the x-axis.<br>.value[1].f32: scale factor along the y-axis.<br>.value[2].f32: scale factor along the z-axis.<br>value[3].i32: animation duration, in milliseconds.<br>.value[4].i32: animation curve type. The value is an enumerated value of [ArkUI_AnimationCurve](#arkui_animationcurve).<br>.value[5]?.i32: animation delay duration, in milliseconds.<br>.value[6]?.i32: number of times that the animation is played.<br>.value[7]?.i32: animation playback mode. The value is an enumerated value of [ArkUI_AnimationPlayMode](#arkui_animationplaymode).<br>value[8]?.f32: animation playback speed.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: scale factor along the x-axis.<br>.value[1].f32: scale factor along the y-axis.<br>.value[2].f32: scale factor along the z-axis.<br>value[3].i32: animation duration, in milliseconds.<br>.value[4].i32: animation curve type. The value is an enumerated value of [ArkUI_AnimationCurve](#arkui_animationcurve).<br>value[5].i32: animation delay duration, in milliseconds.<br>value[6].i32: number of times that the animation is played.<br>.value[7].i32: animation playback mode. The value is an enumerated value of [ArkUI_AnimationPlayMode](#arkui_animationplaymode).<br>value[8].f32: animation playback speed.|
| NODE_TRANSLATE_TRANSITION                   | Defines the transition translation attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>value[0].f32: translation distance along the x-axis, in vp.<br>value[1].f32: translation distance along the y-axis, in vp.<br>value[2].f32: translation distance along the z-axis, in vp.<br>value[3].i32: animation duration, in milliseconds.<br>value[4].i32: animation curve type. The value is an enumerated value of [ArkUI_AnimationCurve](#arkui_animationcurve).<br>value[5]?.i32: animation delay duration, in milliseconds.<br>value[6]?.i32: number of times that the animation is played.<br>value[7]?.i32: animation playback mode. The value is an enumerated value of [ArkUI_AnimationPlayMode](#arkui_animationplaymode).<br>value[8]?.f32: animation playback speed.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>value[0].f32: translation distance along the x-axis, in vp.<br>value[1].f32: translation distance along the y-axis, in vp.<br>value[2].f32: translation distance along the z-axis, in vp.<br>value[3].i32: animation duration, in milliseconds.<br>value[4].i32: animation curve type. The value is an enumerated value of [ArkUI_AnimationCurve](#arkui_animationcurve).<br>value[5].i32: animation delay duration, in milliseconds.<br>value[6].i32: number of times that the animation is played.<br>value[7].i32: animation playback mode. The value is an enumerated value of [ArkUI_AnimationPlayMode](#arkui_animationplaymode).<br>value[8].f32: animation playback speed.|
| NODE_MOVE_TRANSITION                        | Defines the slide-in and slide-out of the component from the screen edge during transition. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: [ArkUI_TransitionEdge](#arkui_transitionedge) type.<br>.value[1].i32: animation duration, in milliseconds.<br>.value[2].i32: animation curve type. The value is an enumerated value of [ArkUI_AnimationCurve](#arkui_animationcurve).<br>.value[3]?.i32: animation delay duration, in milliseconds.<br>.value[4]?.i32: number of times that the animation is played.<br>.value[5]?.i32: animation playback mode. The value is an enumerated value of [ArkUI_AnimationPlayMode](#arkui_animationplaymode).<br>.value[6]?.f32: animation playback speed.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: [ArkUI_TransitionEdge](#arkui_transitionedge) type.<br>.value[1].i32: animation duration, in milliseconds.<br>.value[2].i32: animation curve type. The value is an enumerated value of [ArkUI_AnimationCurve](#arkui_animationcurve).<br>.value[3].i32: animation delay duration, in milliseconds.<br>.value[4].i32: number of times that the animation is played.<br>.value[5].i32: animation playback mode. The value is an enumerated value of [ArkUI_AnimationPlayMode](#arkui_animationplaymode).<br>.value[6].f32: animation playback speed.|
| NODE_FOCUSABLE                              | Defines the focus attribute, which can be set, reset, and obtained as required through APIs.<br>Parameter format of the attribute setting method [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: The parameter type is 1 or 0.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: The parameter type is 1 or 0.|
| NODE_DEFAULT_FOCUS                          | Defines the default focus attribute, which can be set, reset, and obtained as required through APIs.<br>Parameter format of the attribute setting method [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>value[0].i32: The parameter type is 1 or 0.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>value[0].i32: The parameter type is 1 or 0.|
| NODE_RESPONSE_REGION                        | Defines the touch target attribute, which can be set, reset, and obtained as required through APIs.<br>Parameter format of the attribute setting method [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.data[0].f32: X coordinate of the touch point relative to the upper left corner of the component, in vp.<br>.data[1].f32: Y coordinate of the touch point relative to the upper left corner of the component, in vp.<br>.data[2].f32: width of the touch target, in percentage.<br>.data[3].f32: height of the touch target, in percentage.<br>.data[4...].f32: Multiple touch targets can be set. The sequence of the parameters is the same as the preceding.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.data[0].f32: X coordinate of the touch point relative to the upper left corner of the component, in vp.<br>.data[1].f32: Y coordinate of the touch point relative to the upper left corner of the component, in vp.<br>.data[2].f32: width of the touch target, in percentage.<br>.data[3].f32: height of the touch target, in percentage.<br>.data[4...].f32: Multiple touch targets can be set. The sequence of the parameters is the same as the preceding.|
| NODE_OVERLAY                                | Defines the overlay attribute, which can be set, reset, and obtained as required through APIs.<br>Parameter format of the attribute setting method [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string: mask text.<br>.value[0]?.i32: position of the overlay relative to the component. Optional. The parameter type is [ArkUI_Alignment](#arkui_alignment). The default value is **ARKUI_ALIGNMENT_TOP_START**.<br>.value[1]?.f32: offset of the overlay relative to the upper left corner of itself on the x-axis, in vp. Optional.<br>.value[2]?.f32: offset of the overlay relative to the upper left corner of itself on the y-axis, in vp. Optional.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string: mask text.<br>.value[0].i32: position of the overlay relative to the component. The parameter type is [ArkUI_Alignment](#arkui_alignment). The default value is **ARKUI_ALIGNMENT_TOP_START**.<br>.value[1].f32: offset of the overlay relative to the upper left corner of itself on the x-axis, in vp.<br>.value[2].f32: offset of the overlay relative to the upper left corner of itself on the y-axis, in vp.|
| NODE_SWEEP_GRADIENT                         | Defines the sweep gradient effect. APIs are provided for setting, resetting, and obtaining the attribute value.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0]?.f32: X coordinate of the sweep gradient center relative to the upper left corner of the component.<br>.value[1]?.f32: Y coordinate of the sweep gradient center relative to the upper left corner of the component.<br>.value[2]?.f32: start point of the sweep gradient. The default value is **0**.<br>.value[3]?.f32: end point of the sweep gradient. The default value is **0**.<br>.value[4]?.f32: rotation angle of the sweep gradient. The default value is **0**.<br>.value[5]?.i32: whether the colors are repeated. The value **1** means that the colors are repeated, and **0** means the opposite.<br>.object: The parameter type is [ArkUI_ColorStop](_ark_u_i___color_stop.md). - **colors**: array of color stops, each of which consists of a color and its stop position. Invalid colors are automatically skipped.<br>**colors**: colors of the color stops.<br>**stops**: stop positions of the color stops.<br>**size**: number of colors.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: X coordinate of the sweep gradient center relative to the upper left corner of the component. <br>.value[1].f32: Y coordinate of the sweep gradient center relative to the upper left corner of the component. <br>.value[2].f32: start point of the sweep gradient. The default value is **0**.<br>.value[3].f32: end point of the sweep gradient. The default value is **0**.<br>.value[4].f32: rotation angle of the sweep gradient. The default value is **0**.<br>.value[5].i32: whether the colors are repeated. The value **1** means that the colors are repeated, and **0** means the opposite. <br>.object: The parameter type is [ArkUI_ColorStop](_ark_u_i___color_stop.md). - **colors**: array of color stops, each of which consists of a color and its stop position. Invalid colors are automatically skipped.<br>**colors**: colors of the color stops.<br>**stops**: stop positions of the color stops.<br>**size**: number of colors.|
| NODE_RADIAL_GRADIENT                        | Defines the radial gradient effect. APIs are provided for setting, resetting, and obtaining the attribute value.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0]?.f32: X coordinate of the radial gradient center relative to the upper left corner of the component.<br>.value[1]?.f32: Y coordinate of the radial gradient center relative to the upper left corner of the component.<br>.value[2]?.f32: radius of the radial gradient. The default value is **0**.<br>.value[3]?.i32: whether the colors are repeated. The value **1** means that the colors are repeated, and **0** means the opposite.<br>.object: The parameter type is [ArkUI_ColorStop](_ark_u_i___color_stop.md). - **colors**: array of color stops, each of which consists of a color and its stop position. Invalid colors are automatically skipped.<br>**colors**: colors of the color stops.<br>**stops**: stop positions of the color stops.<br>**size**: number of colors.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: X coordinate of the radial gradient center relative to the upper left corner of the component. <br>.value[1].f32: Y coordinate of the radial gradient center relative to the upper left corner of the component. <br>.value[2].f32: radius of the radial gradient. The default value is **0**.<br>.value[3].i32: whether the colors are repeated. The value **1** means that the colors are repeated, and **0** means the opposite. <br>.object: The parameter type is [ArkUI_ColorStop](_ark_u_i___color_stop.md). - **colors**: array of color stops, each of which consists of a color and its stop position. Invalid colors are automatically skipped.<br>**colors**: colors of the color stops.<br>**stops**: stop positions of the color stops.<br>**size**: number of colors.|
| NODE_MASK                                   | Adds a mask of the specified shape to the component. APIs are provided for setting and obtaining the attribute value.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute, which supports five types of shapes:<br>1. Rectangle:<br>.value[0].u32 fill color, in 0xARGB format.<br>.value[1].u32: stroke color, in 0xARGB format.<br>.value[2].f32: stroke width, in vp.<br>.value[3].i32: mask type. The parameter type is [ArkUI_MaskType](#arkui_masktype). The value is **ARKUI_MASK_TYPE_RECTANGLE** for the rectangle shape.<br>.value[4].f32: width of the rectangle.<br>.value[5].f32: height of the rectangle.<br>.value[6].f32: width of the rounded corner of the rectangle.<br>.value[7].f32: height of the rounded corner of the rectangle.<br>.value[8]?.f32: radius of the upper left corner of the rectangle. <br>.value[9]?.f32: radius of the lower left corner of the rectangle. <br>.value[10]?.f32: radius of the upper right corner of the rectangle. <br>.value[11]?.f32: radius of the lower right corner of the rectangle. <br>2. Circle:<br>.value[0].u32 fill color, in 0xARGB format.<br>.value[1].u32: stroke color, in 0xARGB format.<br>.value[2].f32: stroke width, in vp.<br>.value[3].i32: mask type. The parameter type is [ArkUI_MaskType](#arkui_masktype). The value is **ARKUI_MASK_TYPE_CIRCLE** for the circle shape.<br>.value[4].f32: width of the circle.<br>.value[5].f32: height of the circle.<br>3. Ellipse:<br>.value[0].u32 fill color, in 0xARGB format.<br>.value[1].u32: stroke color, in 0xARGB format.<br>.value[2].f32: stroke width, in vp.<br>.value[3].i32: mask type. The parameter type is [ArkUI_MaskType](#arkui_masktype). The value is **ARKUI_MASK_TYPE_ELLIPSE** for the ellipse shape.<br>.value[4].f32: width of the ellipse.<br>.value[5].f32: height of the ellipse.<br>4. Path:<br>.value[0].u32 fill color, in 0xARGB format.<br>.value[1].u32: stroke color, in 0xARGB format.<br>.value[2].f32: stroke width, in vp.<br>.value[3].i32: mask type. The parameter type is [ArkUI_MaskType](#arkui_masktype). The value is **ARKUI_MASK_TYPE_PATH** for the path shape.<br>.value[4].f32: width of the path.<br>.value[5].f32: height of the path.<br>.string: command for drawing the path.<br>5. Progress:<br>.value[0].i32: mask type. The parameter type is [ArkUI_MaskType](#arkui_masktype). The value is **ARKUI_MASK_TYPE_PROGRESS** for the progress shape.<br>.value[1].f32: current value of the progress indicator.<br>.value[2].f32: maximum value of the progress indicator.<br>.value[3].u32: color of the progress indicator.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md), which supports five types of shapes:<br>1. Rectangle:<br>.value[0].u32 fill color, in 0xARGB format.<br>.value[1].u32: stroke color, in 0xARGB format.<br>.value[2].f32: stroke width, in vp.<br>.value[3].i32: mask type.<br>.value[4].f32: width of the rectangle.<br>.value[5].f32: height of the rectangle.<br>.value[6].f32: width of the rounded corner of the rectangle.<br>.value[7].f32: height of the rounded corner of the rectangle.<br>.value[8]?.f32: radius of the upper left corner of the rectangle. <br>.value[9]?.f32: radius of the lower left corner of the rectangle. <br>.value[10]?.f32: radius of the upper right corner of the rectangle. <br>.value[11]?.f32: radius of the lower right corner of the rectangle. <br>2. Circle:<br>.value[0].u32 fill color, in 0xARGB format.<br>.value[1].u32: stroke color, in 0xARGB format.<br>.value[2].f32: stroke width, in vp.<br>.value[3].i32: mask type.<br>.value[4].f32: width of the circle.<br>.value[5].f32: height of the circle.<br>3. Ellipse:<br>.value[0].u32 fill color, in 0xARGB format.<br>.value[1].u32: stroke color, in 0xARGB format.<br>.value[2].f32: stroke width, in vp.<br>.value[3].i32: mask type.<br>.value[4].f32: width of the ellipse.<br>.value[5].f32: height of the ellipse.<br>4. Path:<br>.value[0].u32 fill color, in 0xARGB format.<br>.value[1].u32: stroke color, in 0xARGB format.<br>.value[2].f32: stroke width, in vp.<br>.value[3].i32: mask type.<br>.value[4].f32: width of the path.<br>.value[5].f32: height of the path.<br>.string: command for drawing the path.<br>5. Progress:<br>.value[0].i32: mask type.<br>.value[1].f32: current value of the progress indicator.<br>.value[2].f32: maximum value of the progress indicator.<br>.value[3].u32: color of the progress indicator.|
| NODE_BLEND_MODE                             | Blends the component's background with the content of the component's child node. APIs are provided for setting, resetting, and obtaining the attribute value.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: blend mode. The parameter type is [ArkUI_BlendMode](#arkui_blendmode). The default value is **ARKUI_BLEND_MODE_NONE**.<br>.value[1].?i32: how the specified blend mode is applied. The parameter type is [ArkUI_BlendApplyType](#arkui_blendapplytype). The default value is **BLEND_APPLY_TYPE_FAST**.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: blend mode. The parameter type is [ArkUI_BlendMode](#arkui_blendmode). The default value is **ARKUI_BLEND_MODE_NONE**.<br>.value[1].i32: how the specified blend mode is applied. The parameter type is [ArkUI_BlendApplyType](#arkui_blendapplytype). The default value is **BLEND_APPLY_TYPE_FAST**.|
| NODE_DIRECTION                              | Sets the direction of the main axis. APIs are provided for setting, resetting, and obtaining the attribute value.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: direction of the main axis.<br>The parameter type is [ArkUI_Direction](#arkui_direction). The default value is **ARKUI_DIRECTION_AUTO**.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: direction of the main axis.<br>The parameter type is [ArkUI_Direction](#arkui_direction). The default value is **ARKUI_DIRECTION_AUTO**. |
| NODE_CONSTRAINT_SIZE                        | Defines the size constraints. APIs are provided for setting, resetting, and obtaining the attribute value.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: minimum width, in vp.<br>.value[1].f32: maximum width, in vp.<br>.value[2].f32: minimum height, in vp.<br>.value[3].f32: maximum height, in vp.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: minimum width, in vp.<br>.value[1].f32: maximum width, in vp.<br>.value[2].f32: minimum height, in vp.<br>.value[3].f32: maximum height, in vp. |
| NODE_GRAY_SCALE                             | Defines the grayscale effect. APIs are provided for setting, resetting, and obtaining the attribute value.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: grayscale conversion ratio. The value ranges from 0 to 1. For example, 0.5 indicates a 50% grayscale conversion ratio.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: grayscale conversion ratio. The value ranges from 0 to 1. |
| NODE_INVERT                                 | Inverts the image. APIs are provided for setting, resetting, and obtaining the attribute value.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: image inversion ratio. The value ranges from 0 to 1. For example, 0.5 indicates a 50% image inversion ratio.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: image inversion ratio. The value ranges from 0 to 1. |
| NODE_SEPIA                                  | Defines the sepia conversion ratio. APIs are provided for setting, resetting, and obtaining the attribute value.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: sepia conversion ratio. The value ranges from 0 to 1. For example, 0.5 indicates that a 50% sepia conversion ratio.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: sepia conversion ratio. The value ranges from 0 to 1. |
| NODE_CONTRAST                               | Defines the contrast attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: contrast. If the value is **1**, the source image is displayed. A larger value indicates a higher contrast. Value range: [0, 10).<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: contrast. Value range: [0, 10).|
| NODE_FOREGROUND_COLOR                       | Defines the border color attribute, which can be set, reset, and obtained as required through APIs.<br>There are two parameter formats of [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) for setting the attribute:\n<br>1: .value[0].u32: color value, in 0xARGB format. For example, 0xFFFF0000 indicates red.<br>2: .value[0].i32: color enum **ArkUI_ColoringStrategy**.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].u32: color value, in 0xARGB format. |
| NODE_OFFSET                                 | Defines the offset of the component's child relative to the component. APIs are provided for setting, resetting, and obtaining the attribute value.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32 : offset along the x-axis, in vp.<br>.value[1].f32 : offset along the y-axis, in vp.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32 : offset along the x-axis, in vp.<br>.value[1].f32 : offset along the y-axis, in vp. |
| NODE_MARK_ANCHOR                            | Sets the anchor for locating the component's child. APIs are provided for setting, resetting, and obtaining the attribute value.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: X coordinate of the anchor, in vp.<br>.value[1].f32: Y coordinate of the anchor, in vp.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: X coordinate of the anchor, in vp.<br>.value[1].f32: Y coordinate of the anchor, in vp. |
| NODE_BACKGROUND_IMAGE_POSITION              | Defines the position of the background image in the component, that is, the coordinates relative to the upper left corner of the component. APIs are provided for setting, resetting, and obtaining the attribute value.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: position along the x-axis, in px.<br>.value[1].f32: position along the y-axis, in px.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: position along the x-axis, in px.<br>.value[1].f32: position along the y-axis, in px. |
| NODE_ALIGN_RULES                            | Sets the alignment rules in the relative container. APIs are provided for setting, resetting, and obtaining the attribute value.<br>.object: [ArkUI_AlignmentRuleOption](#arkui_alignmentruleoption) object that defines the alignment rules.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.object: [ArkUI_AlignmentRuleOption](#arkui_alignmentruleoption) object that defines the alignment rules. |
| NODE_ALIGN_SELF                             | Sets the alignment mode of the child components along the cross axis of the parent container. APIs are provided for setting, resetting, and obtaining the attribute value.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: alignment mode of the child components along the cross axis of the parent container. <br>The parameter type is [ArkUI_ItemAlignment](#arkui_itemalignment). The default value is **ARKUI_ITEM_ALIGNMENT_AUTO**.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: alignment mode of the child components along the cross axis of the parent container. <br>The parameter type is [ArkUI_ItemAlignment](#arkui_itemalignment). The default value is **ARKUI_ITEM_ALIGNMENT_AUTO**. |
| NODE_FLEX_GROW                              | Sets the percentage of the parent container's remaining space that is allocated to the component. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: percentage of the parent container's remaining space that is allocated to the component.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: percentage of the parent container's remaining space that is allocated to the component. |
| NODE_FLEX_SHRINK                            | Sets the percentage of the parent container's shrink size that is allocated to the component. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: percentage of the parent container's shrink size that is allocated to the component.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: percentage of the parent container's shrink size that is allocated to the component. |
| NODE_FLEX_BASIS                             | Sets the base size of the component. APIs are provided for setting, resetting, and obtaining the attribute value.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: base size of the component on the main axis of the parent container.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: base size of the component on the main axis of the parent container. |
| NODE_ACCESSIBILITY_GROUP                    | Sets the accessibility group. APIs are provided for setting, resetting, and obtaining the attribute value.<br>Parameter format of the attribute setting method [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: If the value is **1**, the component and all its child components form an entire selectable component, and the accessibility service will no longer available for the content of its child components. The value is **1** or **0**.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: If the value is **1**, the component and all its child components form an entire selectable component, and the accessibility service will no longer available for the content of its child components. The value is **1** or **0**. |
| NODE_ACCESSIBILITY_TEXT                     | Sets the accessibility text. APIs are provided for setting, resetting, and obtaining the attribute value.<br>Parameter format of the attribute setting method [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string: accessibility text.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string: accessibility text. |
| NODE_ACCESSIBILITY_MODE                     | Defines the accessibility mode. This attribute can be set, reset, and obtained as required through APIs.<br>Parameter format of the attribute setting method [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: auxiliary service mode. The parameter type is [ArkUI_AccessibilityMode](#arkui_accessibilitymode).<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: auxiliary service mode. The parameter type is [ArkUI_AccessibilityMode](#arkui_accessibilitymode). |
| NODE_ACCESSIBILITY_DESCRIPTION              | Sets the accessibility description. APIs are provided for setting, resetting, and obtaining the attribute value.<br>Parameter format of the attribute setting method [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string: accessibility description.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string: accessibility description. |
| NODE_FOCUS_STATUS                           | This interface is used to obtain focus attributes. Attributes can be set and obtained.<br>**NOTE**<br>Setting the parameter to **0** shifts focus from the currently focused component on the current level of the page to the root container.<br>Parameter format of the attribute setting method [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: The parameter type is 1 or 0.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>value[0].i32: The parameter type is 1 or 0.|
| NODE_ASPECT_RATIO                           | Defines the aspect ratio attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: aspect ratio of the component, in width/height format.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: aspect ratio of the component, in width/height format. |
| NODE_LAYOUT_WEIGHT                          | Defines the weight of the component within its row, column, or flex container for proportional distribution of available space within the container. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].u32: weight of the component along the main axis.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].u32: weight of the component along the main axis. |
| NODE_DISPLAY_PRIORITY                       | Sets the display priority for the component in the row, column, or flex (single-line) container. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].u32: display priority of the component in the container.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].u32: display priority of the component in the container. |
| NODE_OUTLINE_WIDTH                          | Sets the thickness of an element's outline.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: thickness of the left outline.<br>.value[1].f32: thickness of the top outline.<br>.value[2].f32: thickness of the right outline.<br>.value[3].f32: thickness of the bottom outline.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: thickness of the left outline.<br>.value[1].f32: thickness of the top outline.<br>.value[2].f32: thickness of the right outline.<br>.value[3].f32: thickness of the bottom outline. |
| NODE_WIDTH_PERCENT                          | Defines the width attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: width, in percentage. <br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: width, in percentage. |
| NODE_HEIGHT_PERCENT                         | Defines the height attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: height, in percentage. <br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: height, in percentage. |
| NODE_PADDING_PERCENT                        | Defines the padding attribute, which can be set, reset, and obtained as required through APIs.<br>There are two formats of [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) for setting the attribute value:<br>1: Specify the same padding for the four directions.<br>.value[0].f32: padding, in percentage. <br>2: Specify different paddings for different directions.<br>.value[0].f32: top padding, in percentage. <br>.value[1].f32: right padding, in percentage. <br>.value[2].f32: bottom padding, in percentage. <br>.value[3].f32: left padding, in percentage. <br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: top padding, in percentage. <br>.value[1].f32: right padding, in percentage. <br>.value[2].f32: bottom padding, in percentage. <br>.value[3].f32: left padding, in percentage. |
| NODE_MARGIN_PERCENT                         | Defines the margin attribute, which can be set, reset, and obtained as required through APIs.<br>There are two formats of [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) for setting the attribute value:<br>1: Specify the same margin for the four directions.<br>.value[0].f32: margin, in percentage. <br>2: Specify different margins for different directions.<br>.value[0].f32: top margin, in percentage. <br>.value[1].f32: right margin, in percentage. <br>.value[2].f32: bottom margin, in percentage. <br>.value[3].f32: left margin, in percentage. <br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: top margin, in percentage. <br>.value[1].f32: right margin, in percentage. <br>.value[2].f32: bottom margin, in percentage. <br>.value[3].f32: left margin, in percentage. |
| NODE_GEOMETRY_TRANSITION                    | Implements an implicit shared element transition. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: two components bound to the shared element. The parameter type is 1 or 0. By default, the out component does not continue to participate in the shared element animation when not yet deleted, which means that it stays in its original position.<br>.string: ID used to set up a binding relationship. If this attribute is set to an empty string **""**, the binding relationship is cleared. The value can be dynamically changed to refresh the binding relationship. One ID can be bound to only two components, which function as in and out components.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: two components bound to the shared element. The parameter type is 1 or 0. By default, the out component does not continue to participate in the shared element animation when not yet deleted, which means that it stays in its original position.<br>.string: ID used to set up a binding relationship. If this attribute is set to an empty string **""**, the binding relationship is cleared. The value can be dynamically changed to refresh the binding relationship. One ID can be bound to only two components, which function as in and out components. |
| NODE_RELATIVE_LAYOUT_CHAIN_MODE             | Specifies the parameters of the chain formed by the component as the chain head. The attribute setting, attribute resetting, and attribute obtaining interfaces are supported.<br>This attribute has effect only when the parent container is **RelativeContainer**.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: direction of the chain. Enumeration [ArkUI_Axis](#arkui_axis).<br>.value[1].i32: style of the chain. Enumeration [ArkUI_RelativeLayoutChainStyle](#arkui_relativelayoutchainstyle).<br>.value[0].i32: direction of the chain. Enumeration [ArkUI_Axis](#arkui_axis).<br>.value[1].i32: style of the chain. Enumeration [ArkUI_RelativeLayoutChainStyle](#arkui_relativelayoutchainstyle). |
| NODE_RENDER_FIT                             | Sets how the final state of the component's content is rendered during its width and height animation process. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32 Content filling mode. The enumerated values of [ArkUI_RenderFit](#arkui_renderfit) are used.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32 Content filling mode. The enumerated values of [ArkUI_RenderFit](#arkui_renderfit) are used. |
| NODE_OUTLINE_COLOR                          | Defines the border color attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>1: .value[0].u32: color of the four borders, in 0xARGB format, for example, **0xFFFF11FF**.<br>2: .value[0].u32: color of the top border, in 0xARGB format, for example, **0xFFFF11FF**.<br>.value[1].u32: color of the right border, in 0xARGB format, for example, **0xFFFF11FF**.<br>.value[2].u32: color of the lower border, in 0xARGB format, for example, **0xFFFF11FF**.<br>.value[3].u32: color of the left border, in 0xARGB format, for example, **0xFFFF11FF**.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].u32: color of the top border, in 0xARGB format, for example, **0xFFFF11FF**.<br>.value[1].u32: color of the right border, in 0xARGB format, for example, **0xFFFF11FF**.<br>.value[2].u32: color of the lower border, in 0xARGB format, for example, **0xFFFF11FF**.<br>.value[3].u32: color of the left border, in 0xARGB format, for example, **0xFFFF11FF**. |
| NODE_SIZE                                   | Sets the size. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: width, in vp.<br>.value[1].f32: height, in vp.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: width, in vp.<br>.value[1].f32: height, in vp. |
| NODE_RENDER_GROUP                           | Sets whether the component and its child components are rendered off the screen and then drawn together with its parent. This attribute can be set, reset, and obtained as required through APIs.<br>Parameter format of the attribute setting method [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: The parameter type is 1 or 0.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>value[0].i32: The parameter type is 1 or 0.|
| NODE_COLOR_BLEND                            | The color overlay effect is added to the component. The attribute setting, attribute resetting, and attribute obtaining interfaces are supported.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].u32: color to blend with the component, in 0xARGB format, for example, **0xFFFF11FF**.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].u32: color to blend with the component, in 0xARGB format, for example, **0xFFFF11FF**. |
| NODE_FOREGROUND_BLUR_STYLE                  | Applies a foreground blur style to the component. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: foreground blur style. The value is an enum of [ArkUI_BlurStyle](#arkui_blurstyle).<br>.value[1]?.i32: color mode used for the foreground blur. The value is an enum of [ArkUI_ColorMode](#arkui_colormode).<br>.value[2]?.i32: adaptive color mode used for the foreground blur. The value is an enum of [ArkUI_AdaptiveColor](#arkui_adaptivecolor).<br>.value[3]?.f32: blur degree. The value range is [0.0, 1.0].<br>.value[4]?.i32: brightness of black in the grayscale blur. The value range is [0, 127].<br>.value[5]?.i32: degree of darkening the white color in the grayscale blur. The value range is [0, 127].<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: foreground blur style. The value is an enum of [ArkUI_BlurStyle](#arkui_blurstyle).<br>.value[1].i32: color mode used for the foreground blur. The value is an enum of [ArkUI_ColorMode](#arkui_colormode).<br>.value[2].i32: adaptive color mode used for the foreground blur. The value is an enum of [ArkUI_AdaptiveColor](#arkui_adaptivecolor).<br>.value[3].f32: blur degree. The value range is [0.0, 1.0].<br>.value[4].i32: brightness of black in the grayscale blur. The value range is [0, 127].<br>.value[5].i32: degree of darkening the white color in the grayscale blur. The value range is [0, 127]. |
| NODE_LAYOUT_RECT                            | Defines the component size and position for layout. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: X coordinate of the component, in px. <br>.value[1].i32: Y coordinate of the component, in px. <br>.value[2].i32: width of the component, in px. <br>.value[3].i32: height of the component, in px. <br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: X coordinate of the component, in px. <br>.value[1].i32: Y coordinate of the component, in px. <br>.value[2].i32: width of the component, in px. <br>.value[3].i32: height of the component, in px. |
| NODE_FOCUS_ON_TOUCH                         | Sets whether the component is focusable on touch. This attribute can be set, reset, and obtained as required through APIs.<br>Parameter format of the attribute setting method [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: The parameter type is 1 or 0.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>value[0].i32: The parameter type is 1 or 0.|
| NODE_BORDER_WIDTH_PERCENT                   | Defines the border width attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>1: .value[0].f32: width of the four borders, in percentage.<br>2: .value[0].f32: width of the top border, in percentage.<br>.value[1].f32: width of the right border, in percentage.<br>.value[2].f32: width of the bottom border, in percentage.<br>.value[3].f32: width of the left border, in percentage.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: width of the top border, in percentage.<br>.value[1].f32: width of the right border, in percentage.<br>.value[2].f32: width of the bottom border, in percentage.<br>.value[3].f32: width of the left border, in percentage. |
| NODE_BORDER_RADIUS_PERCENT                  | Defines the border corner radius attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>1: .value[0].f32: radius of the four corners, in percentage.<br>2: .value[0].f32: radius of the upper left corner, in percentage.<br>.value[1].f32: radius of the upper right corner, in percentage.<br>.value[2].f32: radius of the lower left corner, in percentage.<br>.value[3].f32: radius of the lower right corner, in percentage.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: radius of the upper left corner, in percentage.<br>.value[1].f32: radius of the upper right corner, in percentage.<br>.value[2].f32: radius of the lower left corner, in percentage.<br>.value[3].f32: radius of the lower right corner, in percentage. |
| NODE_ACCESSIBILITY_ID                       | Sets the custom accessibility ID. This attribute can be obtained.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: custom accessibility ID. |
| NODE_ACCESSIBILITY_ACTIONS                  | Sets the accessibility action type. This attribute can be set, reset, and obtained as required through APIs.<br>Parameter format of the attribute setting method [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].u32: accessibility operation type. The parameter type is [ArkUI_AccessibilityActionType](#arkui_accessibilityactiontype).<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].u32: accessibility operation type. The parameter type is [ArkUI_AccessibilityActionType](#arkui_accessibilityactiontype). |
| NODE_ACCESSIBILITY_ROLE                     | Defines supported accessibility component types. This attribute can be set, reset, and obtained as required through APIs.<br>Parameter format of the attribute setting method [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].u32: Accessibility component type. The parameter type is [ArkUI_NodeType](#arkui_nodetype).<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].u32: Accessibility component type. The parameter type is [ArkUI_NodeType](#arkui_nodetype). |
| NODE_ACCESSIBILITY_STATE                    | Sets the accessibility state. This attribute can be set, reset, and obtained as required through APIs.<br>Parameter format of the attribute setting method [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.object: accessibility state. The parameter type is [ArkUI_AccessibilityState](#arkui_accessibilitystate).<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.object: accessibility state. The parameter type is [ArkUI_AccessibilityState](#arkui_accessibilitystate). |
| NODE_ACCESSIBILITY_VALUE                    | Sets the accessibility value. This attribute can be set, reset, and obtained as required through APIs.<br>Parameter format of the attribute setting method [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.object: accessibility value. The parameter type is [ArkUI_AccessibilityValue](#arkui_accessibilityvalue).<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.object: accessibility value. The parameter type is [ArkUI_AccessibilityValue](#arkui_accessibilityvalue). |
| NODE_EXPAND_SAFE_AREA                       | Sets the safe area to be expanded to. This attribute can be set, reset, and obtained as required through APIs.<br>Parameter format of the attribute setting method [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0]?.u32: types of the expanded safe area, which are enumerated values of [ArkUI_SafeAreaType](#arkui_safeareatype). Example: ARKUI_SAFE_AREA_TYPE_SYSTEM \| ARKUI_SAFE_AREA_TYPE_CUTOUT.<br>.value[1]?.u32: edges for expanding the safe area, which are enumerated values of [ArkUI_SafeAreaEdge](#arkui_safeareaedge).<br>Example: ARKUI_SAFE_AREA_EDGE_TOP \| ARKUI_SAFE_AREA_EDGE_BOTTOM.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].u32: expanded safe area.<br>.<br>.value[1].u32: edges for expanding the safe area.<br> |
| NODE_VISIBLE_AREA_CHANGE_RATIO              | Defines the visible area ratio (visible area/total area of the component) threshold for invoking the visible area change event of the component.<br>Parameter format of the attribute setting method [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[...].f32: threshold array. The value ranges from 0 to 1.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[...].f32: threshold array.<br> |
| NODE_TRANSITION                             | Sets the transition effect when the component is inserted or deleted. This attribute can be set and obtained as required through APIs.<br>Parameter format of the attribute setting method [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.object: transition effect. The parameter type is [ArkUI_TransitionEffect](#arkui_transitioneffect).<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.object: transition effect. The parameter type is [ArkUI_TransitionEffect](#arkui_transitioneffect). |
| NODE_TEXT_CONTENT                           | Defines the text content attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.string: text content.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string: text content. |
| NODE_FONT_COLOR                             | Defines the font color attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].u32: font color, in 0xARGB format. For example, 0xFFFF0000 indicates red.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].u32: font color value, in 0xARGB format. |
| NODE_FONT_SIZE                              | Defines the font size attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: font size, in fp.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: font size, in fp. |
| NODE_FONT_STYLE                             | Defines the font style attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: font style [ArkUI_FontStyle](#arkui_fontstyle). The default value is **ARKUI_FONT_STYLE_NORMAL**.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: font style [ArkUI_FontStyle](#arkui_fontstyle). |
| NODE_FONT_WEIGHT                            | Defines the font weight attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: font weight [ArkUI_FontWeight](#arkui_fontweight). The default value is **ARKUI_FONT_WEIGHT_NORMAL**.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: font weight [ArkUI_FontWeight](#arkui_fontweight). |
| NODE_TEXT_LINE_HEIGHT                       | Defines the text line height attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: line height, in fp.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: line height, in fp. |
| NODE_TEXT_DECORATION                        | Defines the text decoration style and color. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: text decoration type [ArkUI_TextDecorationType](#arkui_textdecorationtype). The default value is **ARKUI_TEXT_DECORATION_TYPE_NONE**.<br>.value[1]?.u32: text decoration color, in 0xARGB format. For example, 0xFFFF0000 indicates red. Optional. <br>.value[2]?.i32: text decoration style [ArkUI_TextDecorationStyle](#arkui_textdecorationstyle).<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: text decoration type [ArkUI_TextDecorationType](#arkui_textdecorationtype).<br>.value[1].u32: text decoration color, in 0xARGB format.<br>.value[2].i32: text decoration style [ArkUI_TextDecorationStyle](#arkui_textdecorationstyle). |
| NODE_TEXT_CASE                              | Defines the text case attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: text case.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: text case. |
| NODE_TEXT_LETTER_SPACING                    | Defines the letter spacing attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: letter spacing, in fp.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: letter spacing, in fp. |
| NODE_TEXT_MAX_LINES                         | Sets the maximum number of lines in the text. APIs are provided for setting, resetting, and obtaining the attribute value.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: maximum number of lines in the text.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: maximum number of lines in the text. |
| NODE_TEXT_ALIGN                             | Horizontal alignment mode of the text. The interfaces for setting, resetting, and obtaining attributes are supported.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: horizontal alignment mode of the text. The value is an enum of [ArkUI_TextAlignment](#arkui_textalignment).<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: horizontal alignment mode of the text. The value is an enum of [ArkUI_TextAlignment](#arkui_textalignment). |
| NODE_TEXT_OVERFLOW                          | Defines the text overflow attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: display mode when the text is too long.{\@ArkUI_TextOverflow}<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: display mode when the text is too long.{\@ArkUI_TextOverflow} |
| NODE_FONT_FAMILY                            | Defines the font family attribute, which can be set, reset, and obtained as required through APIs.<br>Parameter format of the attribute setting method [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string: fonts, separated by commas (,).<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string: fonts, separated by commas (,). |
| NODE_TEXT_COPY_OPTION                       | Defines the copy option attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: copy option [ArkUI_CopyOptions](#arkui_copyoptions). The default value is **ARKUI_COPY_OPTIONS_NONE**.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: copy option [ArkUI_CopyOptions](#arkui_copyoptions). |
| NODE_TEXT_BASELINE_OFFSET                   | Defines the text baseline offset attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: baseline offset, in fp.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: baseline offset, in fp. |
| NODE_TEXT_TEXT_SHADOW                       | Defines the shadow attribute. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: blur radius of the shadow, in vp.<br>.value[1].i32: shadow type [ArkUI_ShadowType](#arkui_shadowtype). The default value is **ARKUI_SHADOW_TYPE_COLOR**.<br>.value[2].u32: shadow color, in 0xARGB format. For example, 0xFFFF0000 indicates red.<br>.value[3].f32: offset of the shadow along the x-axis, in vp.<br>.value[4].f32: offset of the shadow along the y-axis, in vp.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: blur radius of the shadow, in vp.<br>.value[1].i32: shadow type [ArkUI_ShadowType](#arkui_shadowtype).<br>.value[2].u32: shadow color, in 0xARGB format.<br>.value[3].f32: offset of the shadow along the x-axis, in vp.<br>.value[4].f32: offset of the shadow along the y-axis, in vp.|
| NODE_TEXT_MIN_FONT_SIZE                     | Defines the minimum font size attribute, which can be set, reset, and obtained as required through APIs.<br>Parameter format of the attribute setting method [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: minimum font size, in fp.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: minimum font size, in fp. |
| NODE_TEXT_MAX_FONT_SIZE                     | Defines the maximum font size attribute, which can be set, reset, and obtained as required through APIs.<br>Parameter format of the attribute setting method [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: maximum font size, in fp.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: maximum font size, in fp. |
| NODE_TEXT_FONT                              | Defines the text style attribute, which can be set, reset, and obtained as required through APIs.<br>Parameter format of the attribute setting method [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string?: font family. Optional. Use commas (,) to separate multiple fonts.<br>.value[0].f32: font size, in fp.<br>.value[1]? .i32: font weight. Optional. The parameter type is [ArkUI_FontWeight](#arkui_fontweight). The default value is **ARKUI_FONT_WEIGHT_NORMAL**.<br>.value[2]?.i32: font style. Optional. The parameter type is [ArkUI_FontStyle](#arkui_fontstyle). The default value is **ARKUI_FONT_STYLE_NORMAL**.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string: font family. Use commas (,) to separate multiple fonts.<br>.value[0].f32: font size, in fp.<br>.value[1].i32: font weight. The parameter type is [ArkUI_FontWeight](#arkui_fontweight). The default value is **ARKUI_FONT_WEIGHT_NORMAL**.<br>.value[2].i32: font style. The parameter type is [ArkUI_FontStyle](#arkui_fontstyle). The default value is **ARKUI_FONT_STYLE_NORMAL**. |
| NODE_TEXT_HEIGHT_ADAPTIVE_POLICY            | Defines how the adaptive height is determined for the text. This attribute can be set, reset, and obtained as required through APIs.<br>Parameter format of the attribute setting method [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: how the adaptive height is determined for the text. The parameter type is [ArkUI_TextHeightAdaptivePolicy](#arkui_textheightadaptivepolicy).<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: how the adaptive height is determined for the text. The parameter type is [ArkUI_TextHeightAdaptivePolicy](#arkui_textheightadaptivepolicy). |
| NODE_TEXT_INDENT                            | Defines the indentation of the first line. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: indentation of the first line.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: indentation of the first line. |
| NODE_TEXT_WORD_BREAK                        | Defines the line break rule. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: line break rule. The parameter type is [ArkUI_WordBreak](#arkui_wordbreak).<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: line break rule. The parameter type is [ArkUI_WordBreak](#arkui_wordbreak). |
| NODE_TEXT_ELLIPSIS_MODE                     | Defines the ellipsis position. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: ellipsis position. The parameter type is [ArkUI_EllipsisMode](#arkui_ellipsismode).<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: ellipsis position. The parameter type is [ArkUI_EllipsisMode](#arkui_ellipsismode). |
| NODE_TEXT_LINE_SPACING                      | Defines the line spacing attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: line spacing, in fp. <br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: line spacing, in fp. |
| NODE_FONT_FEATURE                           | Sets the font feature. **NODE_FONT_FEATURE** provides advanced typographic features in OpenType fonts.<br>These features such as hyphenation and monospace are generally used in custom fonts and require support from the respective fonts. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.string: string that complies with the text feature format. The format is normal\. |
| NODE_TEXT_ENABLE_DATA_DETECTOR              | Sets whether to enable text recognition.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: whether to enable text recognition. The default value is **false**.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: whether to enable text recognition. |
| NODE_TEXT_ENABLE_DATA_DETECTOR_CONFIG       | Configures text recognition settings.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0...].i32: entity type array. The parameter type is [ArkUI_TextDataDetectorType](#arkui_textdatadetectortype).<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0...].i32: entity type array. The parameter type is [ArkUI_TextDataDetectorType](#arkui_textdatadetectortype). |
| NODE_TEXT_SELECTED_BACKGROUND_COLOR         | Defines the background color of the selected text. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].u32: color value, in 0xARGB format. For example, 0xFFFF0000 indicates red.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].u32: color value, in 0xARGB format. |
| NODE_TEXT_CONTENT_WITH_STYLED_STRING        | Sets the string to use in the styled string. This attribute can be set and obtained as required through APIs. When a custom **OH_Drawing_Typography** object is configured for a **Text** component, the layout measurement phase of the **Text** component is skipped. Below are some tips to handle this issue:<br>1. Ensure that the lifecycle of the **OH_ArkUI_StyledString** object and the **OH_Drawing_Typography** object follows that of the **Text** component. Reset the **OH_ArkUI_StyledString** object when the **Text** component is destroyed; otherwise, a null pointer crash may occur in the application.<br>2. Ensure that the **OH_Drawing_TypographyLayout** API is called before the layout measurement of the **Text** component.<br>3. When releasing the **OH_ArkUI_StyledString** object and the **OH_Drawing_Typography** object, call the **reset** API of the **Text** component. Otherwise, a null pointer crash may occur in the application<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.object: string to use in the styled string. The parameter type is [ArkUI_StyledString](#arkui_styledstring).<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.object: string to use in the styled string. The parameter type is [ArkUI_StyledString](#arkui_styledstring).|
| NODE_TEXT_HALF_LEADING                      | Sets whether to center text vertically in the **Text** component.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: whether to center text vertically. The default value is **false**.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: whether to center text vertically.|
| NODE_SPAN_CONTENT                           | Defines the text content attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.string: content of the text span.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string: content of the text span. |
| NODE_SPAN_TEXT_BACKGROUND_STYLE             | Defines the text background style. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].u32: color of the text background, in 0xARGB format, for example, **0xFFFF0000** indicating red.<br>The second parameter is used to set the rounded corner of the text background. The options are as follows:<br>1: .value[1].f32: The radiuses of rounded corners in the four directions are set in a unified manner. The unit is vp.<br>2: .value[1].f32: radius of the upper left corner, in vp.<br>.value[2].f32: radius of the upper right corner, in vp.<br>.value[3].f32: radius of the lower left corner, in vp.<br>.value[4].f32: radius of the lower right corner, in vp.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].u32: color of the text background, in 0xARGB format.<br>.value[1].f32: radius of the upper left corner, in vp.<br>.value[2].f32: radius of the upper right corner, in vp.<br>.value[3].f32: radius of the lower left corner, in vp.<br>.value[4].f32: radius of the lower right corner, in vp. |
| NODE_SPAN_BASELINE_OFFSET                   | Defines the text baseline offset attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: baseline offset, in fp.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: baseline offset, in fp. |
| NODE_IMAGE_SPAN_SRC                         | Defines the image source for an image span. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.string: image address of the image span.<br>.object: **PixelMap** object. The parameter type is [ArkUI_DrawableDescriptor](#arkui_drawabledescriptor).<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string: image address of the image span.<br>.object: **PixelMap** object. The parameter type is [ArkUI_DrawableDescriptor](#arkui_drawabledescriptor). Either **.object** or **.string** must be set.|
| NODE_IMAGE_SPAN_VERTICAL_ALIGNMENT          | Defines the alignment mode of the image with the text. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32 indicates the text-based image alignment mode. The enumerated values of [ArkUI_ImageSpanAlignment](#arkui_imagespanalignment) are used.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32 indicates the text-based image alignment mode. The enumerated values of [ArkUI_ImageSpanAlignment](#arkui_imagespanalignment) are used. |
| NODE_IMAGE_SPAN_ALT                         | Defines the image source for an image span. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.string: placeholder image address for the image span. GIF images are not supported.<br>.object: **PixelMap** object. The parameter type is [ArkUI_DrawableDescriptor](#arkui_drawabledescriptor). Either **.object** or **.string** must be set.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string: image source for the image span.<br>.object: **PixelMap** object. The parameter type is [ArkUI_DrawableDescriptor](#arkui_drawabledescriptor).|
| NODE_IMAGE_SPAN_BASELINE_OFFSET             | Defines the baseline offset attribute of the **ImageSpan** component. This attribute can be set, reset, and obtained as required through APIs. A positive value means an upward offset, while a negative value means a downward offset. The default value is **0**, and the unit is fp.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: baseline offset, in fp.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: baseline offset, in fp.|
| NODE_IMAGE_SRC                              | Defines the image source of the **Image** component. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.string: image source.<br>.object: **PixelMap** object. The parameter type is [ArkUI_DrawableDescriptor](#arkui_drawabledescriptor). Either **.object** or **.string** must be set.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string: image source.<br>.object: **PixelMap** object. The parameter type is [ArkUI_DrawableDescriptor](#arkui_drawabledescriptor).|
| NODE_IMAGE_OBJECT_FIT                       | Defines how the image is resized to fit its container. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32 indicates the image filling effect. The enumerated values of [ArkUI_ObjectFit](#arkui_objectfit) are used.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32 indicates the image filling effect. The enumerated values of [ArkUI_ObjectFit](#arkui_objectfit) are used. |
| NODE_IMAGE_INTERPOLATION                    | Defines the interpolation effect of the image. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32 indicates the interpolation effect. The enumerated values of [ArkUI_ImageInterpolation](#arkui_imageinterpolation) are used.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32 indicates the interpolation effect. The enumerated values of [ArkUI_ImageInterpolation](#arkui_imageinterpolation) are used. |
| NODE_IMAGE_OBJECT_REPEAT                    | Defines how the image is repeated. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32 indicates the image repetition style. The enumerated values of [ArkUI_ImageRepeat](#arkui_imagerepeat) are used.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32 indicates the image repetition style. The enumerated values of [ArkUI_ImageRepeat](#arkui_imagerepeat) are used. |
| NODE_IMAGE_COLOR_FILTER                     | Defines the color filter of the image. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32 to .value[19].f32: filter matrix array.<br>.size: 5 x 4 filter array size.<br>.object: pointer to the color filter. The parameter type is **OH_Drawing_ColorFilter**. Either .object or .size can be set.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32 to .value[19].f32: filter matrix array.<br>.size: 5 x 4 filter array size.<br>.object: pointer to the color filter. The parameter type is **OH_Drawing_ColorFilter**. |
| NODE_IMAGE_AUTO_RESIZE                      | Defines the auto resize attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32 : whether to resize the image source.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32 : whether to resize the image source. |
| NODE_IMAGE_ALT                              | Defines the placeholder image source. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.string: image source for the image span.<br>.object: **PixelMap** object. The parameter type is [ArkUI_DrawableDescriptor](#arkui_drawabledescriptor). Either **.object** or **.string** must be set.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string: image source for the image span.<br>.object: **PixelMap** object. The parameter type is [ArkUI_DrawableDescriptor](#arkui_drawabledescriptor).|
| NODE_IMAGE_DRAGGABLE                        | Defines whether the image is draggable. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: whether the image is draggable. The value **true** means that the image is draggable.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: whether the image is draggable. |
| NODE_IMAGE_RENDER_MODE                      | Defines the image rendering mode. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: The parameter type is [ArkUI_ImageRenderMode](#arkui_imagerendermode).<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: The parameter type is [ArkUI_ImageRenderMode](#arkui_imagerendermode). |
| NODE_IMAGE_FIT_ORIGINAL_SIZE                | Sets whether to fit the component to the size of the image source when the component size is not set. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: indicates whether the display size of an image follows the size of the image source. The value 1 indicates that the display size follows the size of the image source, and the value 0 indicates that the display size does not follow the size of the image source. The default value is 0.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: The value **1** means to fit the component to the size of the image source, and **0** means the opposite. |
| NODE_IMAGE_FILL_COLOR                       | Sets the fill color to be superimposed on the image. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].u32: fill color. The value is in 0xARGB format. For example, 0xFFFF0000 indicates red.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].u32: fill color. The value is in 0xARGB format. |
| NODE_IMAGE_RESIZABLE                        | Sets the resizable image options.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: width of the left edge. The unit is vp.<br>.value[1].f32: width of the top edge. The unit is vp.<br>.value[2].f32: width of the right edge. The unit is vp.<br>.value[3].f32: width of the bottom edge. The unit is vp.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: width of the left edge. The unit is vp.<br>.value[1].f32: width of the top edge. The unit is vp.<br>.value[2].f32: width of the right edge. The unit is vp.<br>.value[3].f32: width of the bottom edge. The unit is vp. |
| NODE_TOGGLE_SELECTED_COLOR                  | Defines the color of the component when it is selected. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].u32: background color, in 0xARGB format. For example, 0xFFFF0000 indicates red.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].u32: background color, in 0xARGB format. |
| NODE_TOGGLE_SWITCH_POINT_COLOR              | Defines the color of the circular slider for the component of the switch type. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].u32: color of the circular slider, in 0xARGB format. For example, 0xFFFF0000 indicates red.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].u32: color of the circular slider, in 0xARGB format. |
| NODE_TOGGLE_VALUE                           | Defines the toggle switch value. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: whether to enable the toggle. The value **true** means to enable the toggle.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: whether to enable the toggle. |
| NODE_TOGGLE_UNSELECTED_COLOR                | Defines the color of the component when it is deselected. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].u32: background color, in 0xARGB format. For example, 0xFFFF0000 indicates red.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].u32: background color, in 0xARGB format. |
| NODE_LOADING_PROGRESS_COLOR                 | Defines the foreground color of the loading progress bar. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].u32: foreground color, in 0xARGB format. For example, 0xFFFF0000 indicates red.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].u32: foreground color, in 0xARGB format. |
| NODE_LOADING_PROGRESS_ENABLE_LOADING        | Defines whether to show the loading animation for the **LoadingProgress** component. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: whether to show the loading animation. The value **true** means to show the loading animation, and **false** means the opposite.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: whether to show the loading animation. The value **true** means to show the loading animation, and **false** means the opposite. |
| NODE_TEXT_INPUT_PLACEHOLDER                 | Defines the default placeholder text of the single-line text box. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.string: default placeholder text.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string: default placeholder text. |
| NODE_TEXT_INPUT_TEXT                        | Defines the default text content of the single-line text box. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.string: default text content.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string: default text content. |
| NODE_TEXT_INPUT_CARET_COLOR                 | Defines the border color attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].u32: caret color, in 0xARGB format. For example, 0xFFFF0000 indicates red.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].u32: caret color, in 0xARGB format. |
| NODE_TEXT_INPUT_CARET_STYLE                 | Defines the caret style attribute. APIs are provided for setting, resetting, and obtaining the attribute value.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: caret width, in vp.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: caret width, in vp. |
| NODE_TEXT_INPUT_SHOW_UNDERLINE              | Defines the underline attribute of the single-line text box. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: whether to show an underline. The value **true** means to show an underline, and **false** means the opposite.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: The value **1** means to show an underline, and **0** means the opposite. |
| NODE_TEXT_INPUT_MAX_LENGTH                  | Defines the maximum number of characters in the text input. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: maximum number of characters in the text input, without a unit.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: maximum number of characters in the text input. |
| NODE_TEXT_INPUT_ENTER_KEY_TYPE              | Defines the type of the Enter key. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: Enter key type enumeration [ArkUI_EnterKeyType](#arkui_enterkeytype). The default value is ARKUI_ENTER_KEY_TYPE_DONE.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: type of the Enter key. The value is an enum of [ArkUI_EnterKeyType](#arkui_enterkeytype). |
| NODE_TEXT_INPUT_PLACEHOLDER_COLOR           | Defines the placeholder text color. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].u32: color value, in 0xARGB format. For example, 0xFFFF0000 indicates red.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].u32: color value, in 0xARGB format. |
| NODE_TEXT_INPUT_PLACEHOLDER_FONT            | Defines the placeholder text font. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0]?.f32: font size, in fp. Optional. The default value is **16.0**.<br>.value[1]?.i32: font style [ArkUI_FontStyle](#arkui_fontstyle). Optional. The default value is **ARKUI_FONT_STYLE_NORMAL**.<br>.value[2]?.i32: font weight [ArkUI_FontWeight](#arkui_fontweight). Optional. The default value is **ARKUI_FONT_WEIGHT_NORMAL**.<br>?.string: font family. Multiple font families are separated by commas (,). For example, "font weight; font family 1, font family 2".<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: font size, in fp.<br>.value[1].i32: font style [ArkUI_FontStyle](#arkui_fontstyle).<br>.value[2].i32: font weight [ArkUI_FontWeight](#arkui_fontweight).<br>.string: font family. Multiple font families are separated by commas (,). |
| NODE_TEXT_INPUT_ENABLE_KEYBOARD_ON_FOCUS    | Defines whether to enable the input method when the component obtains focus. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: whether to enable the input method when the component obtains focus. The value **true** means to enable the input method, and **false** means the opposite.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br> *.value[0].i32: The value **1** means to enable the input method when the component obtains focus, and **0** means the opposite. |
| NODE_TEXT_INPUT_TYPE                        | Defines the text box type. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: input box type enumeration [ArkUI_TextInputType](#arkui_textinputtype). The default value is ARKUI_TEXTINPUT_TYPE_NORMAL.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: input box type enumeration [ArkUI_TextInputType](#arkui_textinputtype). |
| NODE_TEXT_INPUT_SELECTED_BACKGROUND_COLOR   | Defines the background color of the selected text. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].u32: color value, in 0xARGB format. For example, 0xFFFF0000 indicates red.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].u32: color value, in 0xARGB format. |
| NODE_TEXT_INPUT_SHOW_PASSWORD_ICON          | Defines whether to display the password icon at the end of the password text box. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: whether to display the password icon at the end of the password text box. The value **true** means to display the password icon, and **false** means the opposite.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: The value **1** means to display the password icon at the end of the password text box, and **0** means the opposite. |
| NODE_TEXT_INPUT_EDITING                     | Defines the editable state for the single-line text box. This attribute can be set as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: whether to remain in the editable state. The value **true** means to remain in the editable state, and **false** means to exit the editable state.<br>The format of the attribute obtaining method parameter [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) is as follows:<br>.value[0].i32: whether to remain in the editable state. The value **true** means to remain in the editable state, and **false** means to exit the editable state. |
| NODE_TEXT_INPUT_CANCEL_BUTTON               | Defines the style of the cancel button on the right of the single-line text box. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: button style [ArkUI_CancelButtonStyle](#arkui_cancelbuttonstyle). The default value is ARKUI_CANCELBUTTON_STYLE_INPUT.<br>.value[1]?.f32: button icon size, in vp.<br>.value[2]?.u32: button icon color, in 0xARGB format. For example, 0xFFFF0000 indicates red.<br>?.string: button icon image source. The value is the local address of the image, for example, /pages/icon.png.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: button style [ArkUI_CancelButtonStyle](#arkui_cancelbuttonstyle).<br>.value[1].f32: icon size, in vp.<br>.value[2].u32: button icon color, in 0xARGB format.<br>.string: button icon image source. |
| NODE_TEXT_INPUT_TEXT_SELECTION              | Sets the text selection area, which will be highlighted. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: start position of the text selection. <br>.value[1].i32: end position of the text selection. <br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: start position of the text selection. <br>.value[1].i32: end position of the text selection. |
| NODE_TEXT_INPUT_UNDERLINE_COLOR             | Sets the color of the underline when it is shown.<br>The default underline color configured for the theme is **'0x33182431'**.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].u32: color of the underline applied to the text being typed in. The value is in 0xARGB format. <br>.value[1].u32: color of the underline applied to the text in the normal state. The value is in 0xARGB format. <br>.value[2].u32: color of the underline applied to the text when an error is detected. The value is in 0xARGB format. <br>.value[3].u32: color of the underline applied to the text when it is disabled. The value is in 0xARGB format. <br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].u32: color of the underline applied to the text being typed in. The value is in 0xARGB format. <br>.value[1].u32: color of the underline applied to the text in the normal state. The value is in 0xARGB format. <br>.value[2].u32: color of the underline applied to the text when an error is detected. The value is in 0xARGB format. <br>.value[3].u32: color of the underline applied to the text when it is disabled. The value is in 0xARGB format. |
| NODE_TEXT_INPUT_ENABLE_AUTO_FILL            | Sets whether to enable autofill.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: whether to enable autofill. The default value is **true**.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: whether to enable autofill. |
| NODE_TEXT_INPUT_CONTENT_TYPE                | Sets the autofill type.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: autofill type. The parameter type is [ArkUI_TextInputContentType](#arkui_textinputcontenttype).<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: autofill type. The parameter type is [ArkUI_TextInputContentType](#arkui_textinputcontenttype). |
| NODE_TEXT_INPUT_PASSWORD_RULES              | Defines the rules for generating passwords. When autofill is used, these rules are transparently transmitted to Password Vault for generating a new password.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.string: rules for generating passwords.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string: rules for generating passwords. |
| NODE_TEXT_INPUT_SELECT_ALL                  | Sets whether to select all text in the initial state. This attribute is not available for the inline input style.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: whether to select all text in the initial state. The default value is b>false</b>.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: whether to select all text in the initial state. |
| NODE_TEXT_INPUT_INPUT_FILTER                | Sets the regular expression for input filtering. Only inputs that comply with the regular expression can be displayed. Other inputs are filtered out. The specified regular expression can match single characters, but not strings.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.string: regular expression.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string: regular expression. |
| NODE_TEXT_INPUT_STYLE                       | Sets the text box to the default style or inline input style.<br>For the inline input style, only **InputType.Normal** is supported.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: text input style. The parameter type is [ArkUI_TextInputStyle](#arkui_textinputstyle).<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: text input style. The parameter type is [ArkUI_TextInputStyle](#arkui_textinputstyle). |
| NODE_TEXT_INPUT_CARET_OFFSET                | Sets or obtains the caret position.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>Sets the position of the caret. .value[0].i32: length from the start of the string to the position where the input cursor is located.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>Returns the position information of the caret. If this API is called when the cursor position is updated in the current frame, value[0].i32 (index value of the cursor position) does not take effect.<br>value[1].f32: X coordinate of the cursor relative to the text box.<br>value[2].f32: Y coordinate of the cursor relative to the text box. |
| NODE_TEXT_INPUT_CONTENT_RECT                | Position of the edited text area relative to the component and its size.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>value[0].f32: horizontal coordinate.<br>value[1].f32: vertical coordinate.<br>value[2].f32: content width.<br>value[3].f32: content height. |
| NODE_TEXT_INPUT_CONTENT_LINE_COUNT          | Obtains the number of lines of the edited text.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>value[0].i32: number of lines in the edited text. |
| NODE_TEXT_INPUT_SELECTION_MENU_HIDDEN       | Sets whether to hide the text selection menu when the text box is long-pressed, double-click, or right-clicked. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: whether to hide the text selection menu when the text box is long-pressed, double-click, or right-clicked. The default value is **false**.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: whether to hide the text selection menu when the text box is long-pressed, double-click, or right-clicked. |
| NODE_TEXT_INPUT_BLUR_ON_SUBMIT              | Sets whether the text box loses focus after the Enter key is pressed to submit information.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: whether the text box loses focus.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: whether the text box loses focus. |
| NODE_TEXT_INPUT_CUSTOM_KEYBOARD             | Sets a custom keyboard.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.object: custom keyboard. The parameter type is **ArkUI_NodeHandle**.<br>.value[0]?.i32: whether the custom keyboard supports avoidance. The default value is **false**.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.object: custom keyboard. The parameter type is **ArkUI_NodeHandle**.<br>.value[0].i32: whether the custom keyboard supports avoidance. |
| NODE_TEXT_INPUT_WORD_BREAK                  | Defines the line break rule. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: line break rule. The parameter type is [ArkUI_WordBreak](#arkui_wordbreak).<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: line break rule. The parameter type is [ArkUI_WordBreak](#arkui_wordbreak). |
| NODE_TEXT_INPUT_NUMBER_OF_LINES             | Sets the number of lines in **TextInput** component, which can be used to work out the height of the component.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: number of lines.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: number of lines. |
| NODE_TEXT_INPUT_SHOW_KEYBOARD_ON_FOCUS      | Sets whether to show the keyboard when the text box obtains focus. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: whether to show the keyboard when the text box obtains focus.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: whether to show the keyboard when the text box obtains focus. |
| NODE_TEXT_AREA_PLACEHOLDER                  | Defines the default placeholder text of the single-line text box. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.string: default placeholder text.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string: default placeholder text. |
| NODE_TEXT_AREA_TEXT                         | Defines the default text content for the multi-line text box. The attribute setting, attribute resetting, and attribute obtaining interfaces are supported.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.string: default text content.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string: default text content. |
| NODE_TEXT_AREA_MAX_LENGTH                   | Defines the maximum number of characters in the text input. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: maximum number of characters in the text input.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: maximum number of characters in the text input. |
| NODE_TEXT_AREA_PLACEHOLDER_COLOR            | Defines the placeholder text color. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].u32: color value, in 0xARGB format. For example, 0xFFFF0000 indicates red.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].u32: color value, in 0xARGB format. |
| NODE_TEXT_AREA_PLACEHOLDER_FONT             | Defines the placeholder text font. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0]?.f32: font size, in fp. Optional. The default value is **16.0**.<br>.value[1]?.i32: font style [ArkUI_FontStyle](#arkui_fontstyle). Optional. The default value is **ARKUI_FONT_STYLE_NORMAL**.<br>.value[2]?.i32: font weight [ArkUI_FontWeight](#arkui_fontweight). Optional. The default value is **ARKUI_FONT_WEIGHT_NORMAL**.<br>?.string: font family. Multiple font families are separated by commas (,). For example, "font weight; font family 1, font family 2".<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: font size, in fp.<br>.value[1].i32: font style [ArkUI_FontStyle](#arkui_fontstyle).<br>.value[2].i32: font weight [ArkUI_FontWeight](#arkui_fontweight).<br>.string: font family. Multiple font families are separated by commas (,). |
| NODE_TEXT_AREA_CARET_COLOR                  | Defines the border color attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].u32: background color, in 0xARGB format. For example, 0xFFFF0000 indicates red.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].u32: background color, in 0xARGB format. |
| NODE_TEXT_AREA_EDITING                      | Defines the editable state for the multi-line text box. This attribute can be set as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: whether to remain in the editable state. The value **true** means to remain in the editable state, and **false** means to exit the editable state.<br>The format of the attribute obtaining method parameter [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) is as follows:<br>.value[0].i32: whether to remain in the editable state. The value **true** means to remain in the editable state, and **false** means to exit the editable state. |
| NODE_TEXT_AREA_TYPE                         | Defines the text box type. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: input box type enumeration [ArkUI_TextAreaType](#arkui_textareatype). The default value is ARKUI_TEXTAREA_TYPE_NORMAL.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: input box type enumeration [ArkUI_TextAreaType](#arkui_textareatype). |
| NODE_TEXT_AREA_SHOW_COUNTER                 | Defines the counter settings. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: whether to show a character counter. The value **true** means to show a character counter.<br>.value[1]?.f32: threshold percentage for displaying the character counter. The character counter is displayed when the number of characters that have been entered is greater than the maximum number of characters multiplied by the threshold percentage value. The value range is 1 to 100. If the value is a decimal, it is rounded down.<br>.value[2]?.i32: whether to highlight the border when the number of entered characters reaches the maximum.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: whether to show a character counter.<br>.value[1].f32: threshold percentage for displaying the character counter. The character counter is displayed when the number of characters that have been entered is greater than the maximum number of characters multiplied by the threshold percentage value. The value range is 1 to 100.<br>.value[2].i32: whether to highlight the border when the number of entered characters reaches the maximum. The default value is **true**. |
| NODE_TEXT_AREA_SELECTION_MENU_HIDDEN        | Sets whether to hide the text selection menu when the text box is long-pressed, double-click, or right-clicked. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: whether to hide the text selection menu when the text box is long-pressed, double-click, or right-clicked. The default value is **false**.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: whether to hide the text selection menu when the text box is long-pressed, double-click, or right-clicked. |
| NODE_TEXT_AREA_BLUR_ON_SUBMIT               | Sets whether the multi-line text box loses focus after the Enter key is pressed to submit information.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: whether the text box loses focus.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: whether the text box loses focus. |
| NODE_TEXT_AREA_INPUT_FILTER                 | Sets the regular expression for input filtering. Only inputs that comply with the regular expression can be displayed. Other inputs are filtered out. The specified regular expression can match single characters, but not strings.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.string: regular expression.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string: regular expression. |
| NODE_TEXT_AREA_SELECTED_BACKGROUND_COLOR    | Sets the background color of the selected text. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].u32: color value, in 0xARGB format. For example, 0xFFFF0000 indicates red.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].u32: color value, in 0xARGB format. |
| NODE_TEXT_AREA_ENTER_KEY_TYPE               | Defines the type of the Enter key. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: Enter key type enumeration [ArkUI_EnterKeyType](#arkui_enterkeytype). The default value is ARKUI_ENTER_KEY_TYPE_DONE.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: type of the Enter key. The value is an enum of [ArkUI_EnterKeyType](#arkui_enterkeytype). |
| NODE_TEXT_AREA_ENABLE_KEYBOARD_ON_FOCUS     | Sets whether to enable the input method when the multi-line text box obtains focus in a way other than clicking. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: whether to enable the input method when the multi-line text box obtains focus in a way other than clicking. The value **true** means to enable the input method, and **false** means the opposite. The default value is **false**.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br> *.value[0].i32: The value **1** means to enable the input method when the component obtains focus, and **0** means the opposite. |
| NODE_TEXT_AREA_CARET_OFFSET                 | Sets or obtains the caret position.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>Sets the position of the caret. .value[0].i32: length from the start of the string to the position where the input cursor is located.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>Returns the position information of the caret. In the case of obtaining the caret position: If this API is called when the caret position is updated in the current frame, it will not take effect.<br>.value[0].i32: index of the caret position.<br>value[1].f32: X coordinate of the cursor relative to the text box.<br>value[2].f32: Y coordinate of the cursor relative to the text box. |
| NODE_TEXT_AREA_CONTENT_RECT                 | Position of the edited text area relative to the component and its size.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>value[0].f32: horizontal coordinate.<br>value[1].f32: vertical coordinate.<br>value[2].f32: content width.<br>value[3].f32: content height. |
| NODE_TEXT_AREA_CONTENT_LINE_COUNT           | Obtains the number of lines of the edited text.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>value[0].i32: number of lines in the edited text. |
| NODE_TEXT_AREA_TEXT_SELECTION               | Sets the text selection range and highlights the selected text when the component is focused. This API works only when the value of **selectionStart** is less than that of **selectionEnd**.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: start position of the text selection. <br>.value[1].i32: end position of the text selection. <br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: start position of the text selection. <br>.value[1].i32: end position of the text selection. |
| NODE_TEXT_AREA_ENABLE_AUTO_FILL             | Sets whether to enable autofill.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: whether to enable autofill. The default value is **true**.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: whether to enable autofill. |
| NODE_TEXT_AREA_CONTENT_TYPE                 | Enumerates the content types for autofill.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: autofill type. The parameter type is [ArkUI_TextInputContentType](#arkui_textinputcontenttype).<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: autofill type. The parameter type is [ArkUI_TextInputContentType](#arkui_textinputcontenttype). |
| NODE_TEXT_AREA_NUMBER_OF_LINES              | Sets the number of lines in **TextArea** component, which can be used to work out the height of the component.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: number of lines.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: number of lines. |
| NODE_TEXT_AREA_SHOW_KEYBOARD_ON_FOCUS       | Sets whether to show the keyboard when the text box obtains focus. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: whether to show the keyboard when the text box obtains focus.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: whether to show the keyboard when the text box obtains focus. |
| NODE_BUTTON_LABEL                           | Defines the button text content. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.string: default text content.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string: default text content. |
| NODE_BUTTON_TYPE                            | Sets the button type. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: button style. The parameter type is [ArkUI_ButtonType](#arkui_buttontype). The default value is ARKUI_BUTTON_TYPE_CAPSULE.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: Obtains the style of the button. The parameter type is [ArkUI_ButtonType](#arkui_buttontype). The default value is ARKUI_BUTTON_TYPE_CAPSULE. |
| NODE_PROGRESS_VALUE                         | Defines the current value of the progress indicator. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: current value of the progress indicator.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: current value of the progress indicator. |
| NODE_PROGRESS_TOTAL                         | Defines the total value of the progress indicator. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: total value of the progress indicator.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: total value of the progress indicator. |
| NODE_PROGRESS_COLOR                         | Defines the color for the progress value on the progress indicator. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].u32: color value, in 0xARGB format. For example, 0xFFFF0000 indicates red.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].u32: color value, in 0xARGB format. |
| NODE_PROGRESS_TYPE                          | Defines the type of the progress indicator. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: progress bar type. The enumerated value is [ArkUI_ProgressType](#arkui_progresstype). The default value is ARKUI_PROGRESS_TYPE_LINEAR.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: progress bar type enumeration value [ArkUI_ProgressType](#arkui_progresstype). |
| NODE_CHECKBOX_SELECT                        | Defines whether the check box is selected. This attribute can be set, reset, and obtained as required through APIs.<br>Parameter format of the attribute setting method [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: whether the check box is selected. The value **1** means that the check box is selected, and **0** means the opposite.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: whether the check box is selected. The value **1** means that the check box is selected, and **0** means the opposite. |
| NODE_CHECKBOX_SELECT_COLOR                  | Defines the color of the check box when it is selected. This attribute can be set, reset, and obtained as required through APIs.<br>Parameter format of the attribute setting method [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>*.value[0].u32: color of the check box when it is selected, in 0xARGB format, for example, **0xFF1122FF**.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>*.value[0].u32: color of the check box when it is selected, in 0xARGB format, for example, **0xFF1122FF**. |
| NODE_CHECKBOX_UNSELECT_COLOR                | Defines the border color of the check box when it is not selected. This attribute can be set, reset, and obtained as required through APIs.<br>Parameter format of the attribute setting method [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].u32: border color, in 0xARGB format, for example, **0xFF1122FF**.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].u32: border color, in 0xARGB format, for example, **0xFF1122FF**. |
| NODE_CHECKBOX_MARK                          | Defines the internal icon style of the check box. This attribute can be set, reset, and obtained as required through APIs.<br>Parameter format of the attribute setting method [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].u32: border color, in 0xARGB format, for example, **0xFF1122FF**.<br>.value[1]?.f32: size of the internal mark, in vp. Optional.<br>.value[2]?.f32: stroke width of the internal mark, in vp. Optional. The default value is **2**.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].u32: border color, in 0xARGB format, for example, **0xFF1122FF**.<br>.value[1].f32: size of the internal mark, in vp. <br>.value[2].f32: stroke width of the internal mark, in vp. The default value is **2**. |
| NODE_CHECKBOX_SHAPE                         | Defines the shape of the check box. This attribute can be set, reset, and obtained as required through APIs.<br>Parameter format of the attribute setting method [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: component shape. The parameter type is [ArkUI_CheckboxShape](#arkui_checkboxshape).<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: component shape. The parameter type is [ArkUI_CheckboxShape](#arkui_checkboxshape). |
| NODE_XCOMPONENT_ID                          | Defines the ID of the **XComponent** component. This attribute can be set and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.string: component ID.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string: component ID. |
| NODE_XCOMPONENT_TYPE                        | Defines the type of the **XComponent** component. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: type. The parameter type is [ArkUI_XComponentType](#arkui_xcomponenttype). The default value is **ARKUI_XCOMPONENT_TYPE_SURFACE**.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: type. The parameter type is [ArkUI_XComponentType](#arkui_xcomponenttype). |
| NODE_XCOMPONENT_SURFACE_SIZE                | Defines the width and height of the **XComponent** component. This attribute can be set and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].u32: width, in px. <br>.value[1].u32: height, in px. <br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].u32: width, in px. <br>.value[1].u32: height, in px. |
| NODE_DATE_PICKER_LUNAR                      | Defines whether to display the lunar calendar in the date picker. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: whether to display the lunar calendar in the date picker. The default value is **false**.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: whether to display the lunar calendar in the date picker. |
| NODE_DATE_PICKER_START                      | Defines the start date of the date picker. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.string: date. The default value is **"1970-1-1"**.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string: date. |
| NODE_DATE_PICKER_END                        | Defines the end date of the date picker. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>*.string: date. The default value is **"2100-12-31"**.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string: date. |
| NODE_DATE_PICKER_SELECTED                   | Defines the selected date of the date picker. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.string: date. The default value is **"2024-01-22"**.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string: date. |
| NODE_DATE_PICKER_DISAPPEAR_TEXT_STYLE       | Defines the font color, font size, and font weight for the top and bottom items in the date picker. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.string: array of five parameters of the string type, separated by semicolons (;).<br>Parameter 1: font color, in ::argb format.<br>Parameter 2: font size, in fp. The value is a number.<br>Parameter 3: font weight. Available options are ("bold", "normal", "bolder", "lighter", "medium", "regular").<br>Parameter 4: fonts, separated by commas (,).<br>Parameter 5: font style. Available options are ("normal", "italic").<br>Example: **"\#ff182431;14;normal;Arial,HarmonyOS Sans;normal"**.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string: array of five parameters of the string type, separated by semicolons (;).<br>Parameter 1: font color, in ::argb format.<br>Parameter 2: font size, in fp. The value is a number.<br>Parameter 3: font weight. Available options are ("bold", "normal", "bolder", "lighter", "medium", "regular").<br>Parameter 4: fonts, separated by commas (,).<br>Parameter 5: font style. Available options are ("normal", "italic").<br>Example: **"\#ff182431;14;normal;Arial,HarmonyOS Sans;normal"**. |
| NODE_DATE_PICKER_TEXT_STYLE                 | Defines the font color, font size, and font weight of all items except the top, bottom, and selected items in the date picker. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.string: array of five parameters of the string type, separated by semicolons (;).<br>Parameter 1: font color, in ::argb format.<br>Parameter 2: font size, in fp. The value is a number.<br>Parameter 3: font weight. Available options are ("bold", "normal", "bolder", "lighter", "medium", "regular").<br>Parameter 4: fonts, separated by commas (,).<br>Parameter 5: font style. Available options are ("normal", "italic").<br>Example: **"\#ff182431;14;normal;Arial,HarmonyOS Sans;normal"**.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string: array of five parameters of the string type, separated by semicolons (;).<br>Parameter 1: font color, in ::argb format.<br>Parameter 2: font size, in fp. The value is a number.<br>Parameter 3: font weight. Available options are ("bold", "normal", "bolder", "lighter", "medium", "regular").<br>Parameter 4: fonts, separated by commas (,).<br>Parameter 5: font style. Available options are ("normal", "italic").<br>Example: **"\#ff182431;14;normal;Arial,HarmonyOS Sans;normal"**. |
| NODE_DATE_PICKER_SELECTED_TEXT_STYLE        | Defines the font color, font size, and font weight of the selected item in the date picker. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.string: array of five parameters of the string type, separated by semicolons (;).<br>Parameter 1: font color, in ::argb format.<br>Parameter 2: font size, in fp. The value is a number.<br>Parameter 3: font weight. Available options are ("bold", "normal", "bolder", "lighter", "medium", "regular").<br>Parameter 4: fonts, separated by commas (,).<br>Parameter 5: font style. Available options are ("normal", "italic").<br>Example: **"\#ff182431;14;normal;Arial,HarmonyOS Sans;normal"**.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string: array of five parameters of the string type, separated by semicolons (;).<br>Parameter 1: font color, in ::argb format.<br>Parameter 2: font size, in fp. The value is a number.<br>Parameter 3: font weight. Available options are ("bold", "normal", "bolder", "lighter", "medium", "regular").<br>Parameter 4: fonts, separated by commas (,).<br>Parameter 5: font style. Available options are ("normal", "italic").<br>Example: **"\#ff182431;14;normal;Arial,HarmonyOS Sans;normal"**. |
| NODE_TIME_PICKER_SELECTED                   | Defines the time of the selected item. in the timer picker. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.string: time. The default value is the current system time.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string: time. |
| NODE_TIME_PICKER_USE_MILITARY_TIME          | Defines whether the display time is in 24-hour format. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: whether the display time is in 24-hour format. The default value is **false**.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>*.value[0].i32: whether the display time is in 24-hour format. |
| NODE_TIME_PICKER_DISAPPEAR_TEXT_STYLE       | Defines the font color, font size, and font weight for the top and bottom items in the time picker. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.string: array of five parameters of the string type, separated by semicolons (;).<br>Parameter 1: font color, in ::argb format.<br>Parameter 2: font size, in fp. The value is a number.<br>Parameter 3: font weight. Available options are ("bold", "normal", "bolder", "lighter", "medium", "regular").<br>Parameter 4: fonts, separated by commas (,).<br>Parameter 5: font style. Available options are ("normal", "italic").<br>Example: **"\#ff182431;14;normal;Arial,HarmonyOS Sans;normal"**.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string: array of five parameters of the string type, separated by semicolons (;).<br>Parameter 1: font color, in ::argb format.<br>Parameter 2: font size, in fp. The value is a number.<br>Parameter 3: font weight. Available options are ("bold", "normal", "bolder", "lighter", "medium", "regular").<br>Parameter 4: fonts, separated by commas (,).<br>Parameter 5: font style. Available options are ("normal", "italic").<br>Example: **"\#ff182431;14;normal;Arial,HarmonyOS Sans;normal"**. |
| NODE_TIME_PICKER_TEXT_STYLE                 | Defines the font color, font size, and font weight of all items except the top, bottom, and selected items in the time picker. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.string: array of five parameters of the string type, separated by semicolons (;).<br>Parameter 1: font color, in ::argb format.<br>Parameter 2: font size, in fp. The value is a number.<br>Parameter 3: font weight. Available options are ("bold", "normal", "bolder", "lighter", "medium", "regular").<br>Parameter 4: fonts, separated by commas (,).<br>Parameter 5: font style. Available options are ("normal", "italic").<br>Example: **"\#ff182431;14;normal;Arial,HarmonyOS Sans;normal"**.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string: array of five parameters of the string type, separated by semicolons (;).<br>Parameter 1: font color, in ::argb format.<br>Parameter 2: font size, in fp. The value is a number.<br>Parameter 3: font weight. Available options are ("bold", "normal", "bolder", "lighter", "medium", "regular").<br>Parameter 4: fonts, separated by commas (,).<br>Parameter 5: font style. Available options are ("normal", "italic").<br>Example: **"\#ff182431;14;normal;Arial,HarmonyOS Sans;normal"**. |
| NODE_TIME_PICKER_SELECTED_TEXT_STYLE        | Defines the font color, font size, and font weight of the selected item in the time picker. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.string: array of five parameters of the string type, separated by semicolons (;).<br>Parameter 1: font color, in ::argb format.<br>Parameter 2: font size, in fp. The value is a number.<br>Parameter 3: font weight. Available options are ("bold", "normal", "bolder", "lighter", "medium", "regular").<br>Parameter 4: fonts, separated by commas (,).<br>Parameter 5: font style. Available options are ("normal", "italic").<br>Example: **"\#ff182431;14;normal;Arial,HarmonyOS Sans;normal"**.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string: array of five parameters of the string type, separated by semicolons (;).<br>Parameter 1: font color, in ::argb format.<br>Parameter 2: font size, in fp. The value is a number.<br>Parameter 3: font weight. Available options are ("bold", "normal", "bolder", "lighter", "medium", "regular").<br>Parameter 4: fonts, separated by commas (,).<br>Parameter 5: font style. Available options are ("normal", "italic").<br>Example: **"\#ff182431;14;normal;Arial,HarmonyOS Sans;normal"**. |
| NODE_TEXT_PICKER_OPTION_RANGE               | Defines the data selection range of the text picker. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: type of the used selector [ArkUI_TextPickerRangeType](#arkui_textpickerrangetype). The default value is ARKUI_TEXTPICKER_RANGETYPE_SINGLE.<br>?.string: string input, whose format varies by picker type.<br>1: single-column picker. The input format is a group of strings separated by semicolons (;).<br>2: multi-column picker. Multiple pairs of plain text strings are supported. The pairs are separated by semicolons (;), and strings within each pair are separated by commas (,).<br>?.object: Object input, whose format varies by picker type.<br>1: A single column supports the image selector. The input structure is [ARKUI_TextPickerRangeContent](_a_r_k_u_i___text_picker_range_content.md).<br>2: multi-column linkage selector. The input structure is [ARKUI_TextPickerCascadeRangeContent](_a_r_k_u_i___text_picker_cascade_range_content.md).<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: type of the text picker [ArkUI_TextPickerRangeType](#arkui_textpickerrangetype).<br>?.string: string output, whose format varies by picker type.<br>1: single-column picker. The output format is a group of strings separated by semicolons (;).<br>2: multi-column picker. Multiple pairs of plain text strings are supported. The pairs are separated by semicolons (;), and strings within each pair are separated by commas (,).<br>?.string: Object output, whose format varies by picker type.<br>1: A single column supports the image selector. The output structure is [ARKUI_TextPickerRangeContent](_a_r_k_u_i___text_picker_range_content.md).<br>2: multi-column linkage selector. The output structure is [ARKUI_TextPickerCascadeRangeContent](_a_r_k_u_i___text_picker_cascade_range_content.md). |
| NODE_TEXT_PICKER_OPTION_SELECTED            | Defines the index of the default selected item in the data selection range of the text picker. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].u32: index. If there are multiple index values, add them one by one.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].u32: index. If there are multiple index values, add them one by one. |
| NODE_TEXT_PICKER_OPTION_VALUE               | Defines the value of the default selected item in the text picker. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.string: value of the selected item. If there are multiple values, add them one by one and separate them with semicolons (;).<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string: value of the selected item. If there are multiple values, add them one by one and separate them with semicolons (;). |
| NODE_TEXT_PICKER_DISAPPEAR_TEXT_STYLE       | Defines the font color, font size, and font weight for the top and bottom items in the text picker. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.string: array of five parameters of the string type, separated by semicolons (;).<br>Parameter 1: font color, in ::argb format.<br>Parameter 2: font size, in fp. The value is a number.<br>Parameter 3: font weight. Available options are ("bold", "normal", "bolder", "lighter", "medium", "regular").<br>Parameter 4: fonts, separated by commas (,).<br>Parameter 5: font style. Available options are ("normal", "italic").<br>Example: **"\#ff182431;14;normal;Arial,HarmonyOS Sans;normal"**.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string: array of five parameters of the string type, separated by semicolons (;).<br>Parameter 1: font color, in ::argb format.<br>Parameter 2: font size, in fp. The value is a number.<br>Parameter 3: font weight. Available options are ("bold", "normal", "bolder", "lighter", "medium", "regular").<br>Parameter 4: fonts, separated by commas (,).<br>Parameter 5: font style. Available options are ("normal", "italic").<br>Example: **"\#ff182431;14;normal;Arial,HarmonyOS Sans;normal"**. |
| NODE_TEXT_PICKER_TEXT_STYLE                 | Defines the font color, font size, and font weight for all items except the top, bottom, and selected items in the text picker. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.string: array of five parameters of the string type, separated by semicolons (;).<br>Parameter 1: font color, in ::argb format.<br>Parameter 2: font size, in fp. The value is a number.<br>Parameter 3: font weight. Available options are ("bold", "normal", "bolder", "lighter", "medium", "regular").<br>Parameter 4: fonts, separated by commas (,).<br>Parameter 5: font style. Available options are ("normal", "italic").<br>Example: **"\#ff182431;14;normal;Arial,HarmonyOS Sans;normal"**.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string: array of five parameters of the string type, separated by semicolons (;).<br>Parameter 1: font color, in ::argb format.<br>Parameter 2: font size, in fp. The value is a number.<br>Parameter 3: font weight. Available options are ("bold", "normal", "bolder", "lighter", "medium", "regular").<br>Parameter 4: fonts, separated by commas (,).<br>Parameter 5: font style. Available options are ("normal", "italic").<br>Example: **"\#ff182431;14;normal;Arial,HarmonyOS Sans;normal"**. |
| NODE_TEXT_PICKER_SELECTED_TEXT_STYLE        | Defines the font color, font size, and font weight for the selected item in the text picker. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.string: array of five parameters of the string type, separated by semicolons (;).<br>Input parameter 1: text color. The value is of the argb type.<br>Input parameter 2: text size, in fp. The value is a number.<br>Parameter 3: font weight. Available options are ("bold", "normal", "bolder", "lighter", "medium", "regular").<br>Parameter 4: fonts, separated by commas (,).<br>Parameter 5: font style. Available options are ("normal", "italic").<br>Example: **"\#ff182431;14;normal;Arial,HarmonyOS Sans;normal"**.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string: array of five parameters of the string type, separated by semicolons (;).<br>Parameter 1: text color. The value is of the argb type.<br>Parameter 2: text size. The value is a number, and the unit is fp.<br>Parameter 3: font weight. Available options are ("bold", "normal", "bolder", "lighter", "medium", "regular").<br>Parameter 4: text font list, which is separated by commas (,).<br>Parameter 5: text style, string enumeration ("normal", "italic")<br>Example: **"\#ff182431;14;normal;Arial,HarmonyOS Sans;normal"**. |
| NODE_TEXT_PICKER_SELECTED_INDEX             | Defines the index of the default selected item in the data selection range of the text picker. This attribute can be set, reset, and obtained as required through APIs.<br>[ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter type. The options are as follows:<br>.value[0...].i32: index of the default item in the data selection range. |
| NODE_TEXT_PICKER_CAN_LOOP                   | Defines whether to support scroll looping for the text picker. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: whether to support scroll looping. The value **true** means to support scroll looping, and **false** means the opposite.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>value[0].i32: The value **1** means to support scroll looping, and **0** means the opposite. |
| NODE_TEXT_PICKER_DEFAULT_PICKER_ITEM_HEIGHT | Defines the height of each item in the picker. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>value[0].f32: item height, in vp.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>value[0].f32: item height, in vp. |
| NODE_CALENDAR_PICKER_HINT_RADIUS            | Defines the style of the background in the selected state of the calendar picker. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: radius of the rounded corner of the bottom plate when the calendar is selected. The value range is [0, +∞). The value 0 indicates that the bottom plate style is a right-angle rectangle. The value range is (0, 16), indicating that the bottom plate style is a rounded rectangle. If the value range is [16, +∞), the bottom plate style is round.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: radius of the rounded corner of the bottom plate when the calendar is selected. The value range is [0, +∞). The value 0 indicates that the bottom plate style is a right-angle rectangle. The value range is (0, 16), indicating that the bottom plate style is a rounded rectangle. If the value range is [16, +∞), the bottom plate style is round. |
| NODE_CALENDAR_PICKER_SELECTED_DATE          | Defines the date of the selected item in the calendar picker. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].u32: year of the selected date.<br>.value[1].u32: month of the selected date.<br>.value[2].u32: day of the selected date.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].u32: year of the selected date.<br>.value[1].u32: month of the selected date.<br>.value[2].u32: day of the selected date. |
| NODE_CALENDAR_PICKER_EDGE_ALIGNMENT         | Defines how the calendar picker is aligned with the entry component. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: alignment mode type. The parameter type is [ArkUI_CalendarAlignment](#arkui_calendaralignment).<br>.value[1].f32: offset of the picker relative to the entry component along the x-axis after alignment based on the specified alignment mode.<br>.value[2].f32: offset of the picker relative to the entry component along the y-axis after alignment based on the specified alignment mode.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: alignment mode type. The parameter type is [ArkUI_CalendarAlignment](#arkui_calendaralignment).<br>.value[1].f32: offset of the picker relative to the entry component along the x-axis after alignment based on the specified alignment mode.<br>.value[2].f32: offset of the picker relative to the entry component along the y-axis after alignment based on the specified alignment mode. |
| NODE_CALENDAR_PICKER_TEXT_STYLE             | Defines the font color, font size, and font weight in the entry area of the calendar picker.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0]?.u32: font color of the entry area.<br>.value[1]?.f32: font size of the entry area, in fp.<br>.value[2]?.i32: font weight of the text in the entry area. The parameter type is [ArkUI_FontWeight](#arkui_fontweight).<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].u32: font color of the entry area.<br>.value[1].f32: font size of the entry area, in fp.<br>.value[2].i32: font weight of the text in the entry area. The parameter type is [ArkUI_FontWeight](#arkui_fontweight). |
| NODE_SLIDER_BLOCK_COLOR                     | Defines the color of the slider. This attribute can be set, reset, and obtained as required through APIs.<br>Parameter format of the attribute setting method [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>*.value[0].u32: color of the slider, in 0xARGB format, for example, **0xFF1122FF**.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>*.value[0].u32: color of the slider, in 0xARGB format, for example, **0xFF1122FF**. |
| NODE_SLIDER_TRACK_COLOR                     | Defines the background color of the slider. This attribute can be set, reset, and obtained as required through APIs.<br>Parameter format of the attribute setting method [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].u32: background color, in 0xARGB format, for example, **0xFF1122FF**.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].u32: background color, in 0xARGB format, for example, **0xFF1122FF**. |
| NODE_SLIDER_SELECTED_COLOR                  | Defines the color of the selected part of the slider track. This attribute can be set, reset, and obtained as required through APIs.<br>Parameter format of the attribute setting method [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].u32: color of the selected part of the slider track, in 0xARGB format, for example, **0xFF1122FF**.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].u32: color of the selected part of the slider track, in 0xARGB format, for example, **0xFF1122FF**. |
| NODE_SLIDER_SHOW_STEPS                      | Sets whether to display the step scale value. Attributes can be set, reset, and obtained.<br>Parameter format of the attribute setting method [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: whether to display the stepping value. The value **1** means to display the stepping value, and **0** (default value) means the opposite.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: whether to display the stepping value. The value **1** means to display the stepping value, and **0** (default value) means the opposite. |
| NODE_SLIDER_BLOCK_STYLE                     | Defines the slider shape, which can be set, reset, and obtained as required through APIs.<br>Parameter format of the attribute setting method [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: shape. The parameter type is [ArkUI_SliderBlockStyle](#arkui_sliderblockstyle).<br>.string? depending on the shape. Optional.<br>ARKUI_SLIDER_BLOCK_STYLE_IMAGE: image resource of the slider. Example: /pages/common/icon.png.<br>ARKUI_SLIDER_BLOCK_STYLE_SHAPE: custom shape of the slider.<br>There are five types:<br>1. Rectangle:<br>.value[1].i32: cropping type. The parameter type is [ArkUI_ShapeType](#arkui_shapetype), ARKUI_SHAPE_TYPE_RECTANGLE.<br>.value[2].f32: height of the rectangle.<br>.value[3].f32: height of the rectangle.<br>.value[4].f32: height of the rounded corner of the rectangle.<br>.value[5].f32: height of the rounded corner of the rectangle.<br>2. Circle:<br>.value[1].i32: cropping type. The parameter type is [ArkUI_ShapeType](#arkui_shapetype), ARKUI_SHAPE_TYPE_CIRCLE.<br>.value[2].f32: height of the circle.<br>.value[3].f32: height of the circle.<br>3. Ellipse:<br>.value[1].i32: cropping type. The parameter type is [ArkUI_ShapeType](#arkui_shapetype), ARKUI_SHAPE_TYPE_ELLIPSE.<br>.value[2].f32: height of the ellipse.<br>.value[3].f32: height of the ellipse.<br>4. Path:<br>.value[1].i32: cropping type. The parameter type is [ArkUI_ShapeType](#arkui_shapetype), ARKUI_SHAPE_TYPE_PATH.<br>.value[2].f32: width of the path.<br>.value[3].f32: height of the path.<br>.string: command for drawing the path.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: shape. The parameter type is [ArkUI_SliderBlockStyle](#arkui_sliderblockstyle).<br>.string? depending on the shape. Optional.<br>ARKUI_SLIDER_BLOCK_STYLE_IMAGE: image resource of the slider. Example: /pages/common/icon.png.<br>ARKUI_SLIDER_BLOCK_STYLE_SHAPE: custom shape of the slider.<br>There are five types:<br>1. Rectangle:<br>.value[1].i32: cropping type. The parameter type is [ArkUI_ShapeType](#arkui_shapetype), ARKUI_SHAPE_TYPE_RECTANGLE.<br>.value[2].f32: height of the rectangle.<br>.value[3].f32: height of the rectangle.<br>.value[4].f32: height of the rounded corner of the rectangle.<br>.value[5].f32: height of the rounded corner of the rectangle.<br>2. Circle:<br>.value[1].i32: cropping type. The parameter type is [ArkUI_ShapeType](#arkui_shapetype), ARKUI_SHAPE_TYPE_CIRCLE.<br>.value[2].f32: height of the circle.<br>.value[3].f32: height of the circle.<br>3. Ellipse:<br>.value[1].i32: cropping type. The parameter type is [ArkUI_ShapeType](#arkui_shapetype), ARKUI_SHAPE_TYPE_ELLIPSE.<br>.value[2].f32: height of the ellipse.<br>.value[3].f32: height of the ellipse.<br>4. Path:<br>.value[1].i32: cropping type. The parameter type is [ArkUI_ShapeType](#arkui_shapetype), ARKUI_SHAPE_TYPE_PATH.<br>.value[2].f32: width of the path.<br>.value[3].f32: height of the path.<br>.string: command for drawing the path. |
| NODE_SLIDER_VALUE                           | Defines the current value of the slider. This attribute can be set, reset, and obtained as required through APIs.<br>Parameter format of the attribute setting method [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: current value.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: current value. |
| NODE_SLIDER_MIN_VALUE                       | Defines the minimum value of the slider. This attribute can be set, reset, and obtained as required through APIs.<br>Parameter format of the attribute setting method [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: minimum value.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: minimum value. |
| NODE_SLIDER_MAX_VALUE                       | Defines the maximum value of the slider. This attribute can be set, reset, and obtained as required through APIs.<br>Parameter format of the attribute setting method [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: maximum value.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: maximum value. |
| NODE_SLIDER_STEP                            | Defines the step of the slider. This attribute can be set, reset, and obtained as required through APIs.<br>Parameter format of the attribute setting method [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: step. The value range is [0.01, 100].<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: step. The value range is [0.01, 100]. |
| NODE_SLIDER_DIRECTION                       | Defines whether the slider moves horizontally or vertically. This attribute can be set, reset, and obtained as required through APIs.<br>Parameter format of the attribute setting method [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: display style. The parameter type is [ArkUI_SliderDirection](#arkui_sliderdirection).<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: display style. The parameter type is [ArkUI_SliderDirection](#arkui_sliderdirection). |
| NODE_SLIDER_REVERSE                         | Defines whether the slider values are reversed. This attribute can be set, reset, and obtained as required through APIs.<br>Parameter format of the attribute setting method [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: whether the slider values are reversed. The value **1** means that the slider values are reversed, and **0** means the opposite.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: whether the slider values are reversed. The value **1** means that the slider values are reversed, and **0** means the opposite. |
| NODE_SLIDER_STYLE                           | Defines the style of the slider thumb and track. This attribute can be set, reset, and obtained as required through APIs.<br>Parameter format of the attribute setting method [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: display style. The parameter type is [ArkUI_SliderStyle](#arkui_sliderstyle).<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: display style. The parameter type is [ArkUI_SliderStyle](#arkui_sliderstyle). |
| NODE_SLIDER_TRACK_THICKNESS                 | Sets the track thickness of the slider. This attribute can be set, reset, and obtained as required through APIs.<br>Parameter format of the attribute setting method [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: track thickness of the slider, in vp. The default value is 4.0 vp when **NODE_SLIDER_STYLE** is set to **ARKUI_SLIDER_STYLE_OUT_SET** and 20.0 vp when **NODE_SLIDER_STYLE** is set to **ARKUI_SLIDER_STYLE_IN_SET**. <br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: track thickness of the slider, in vp. |
| NODE_RADIO_CHECKED                          | Sets whether the radio button is selected. This attribute can be set, reset, and obtained as required through APIs.<br>Parameter format of the attribute setting method [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: whether the radio button is selected. The default value is **false**. Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: whether the radio button is selected. |
| NODE_RADIO_STYLE                            | Sets the style of the radio button in selected or deselected state. This attribute can be set, reset, and obtained as required through APIs.<br>Parameter format of the attribute setting method [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0]?.u32: color of the background when the radio button is selected, in 0xARGB format. The default value is **0xFF007DFF**.<br>.value[1]?.u32: color of the border when the radio button is deselected, in 0xARGB format. The default value is **0xFF182431**.<br>.value[2]?.u32: color of the indicator when the radio button is selected, in 0xARGB format. The default value is **0xFFFFFFFF**.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].u32: color of the background when the radio button is selected, in 0xARGB format. The default value is **0xFF007DFF**.<br>.value[1].u32: color of the border when the radio button is deselected, in 0xARGB format. The default value is **0xFF182431**.<br>.value[2].u32: color of the indicator when the radio button is selected, in 0xARGB format. The default value is **0xFFFFFFF**. |
| NODE_RADIO_VALUE                            | Sets the current value of the radio button. This attribute can be set, reset, and obtained as required through APIs.<br>Parameter format of the attribute setting method [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string: value of the option button.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string: value of the option button. |
| NODE_RADIO_GROUP                            | Sets the name of the group to which the radio button belongs. Only one radio button in a given group can be selected at a time. This attribute can be set, reset, and obtained as required through APIs.<br>Parameter format of the attribute setting method [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string: name of the group to which the radio button belongs. <br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string: name of the group to which the radio button belongs. |
| NODE_STACK_ALIGN_CONTENT                    | Defines the alignment mode of the child components in the container. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: alignment mode. The parameter type is [ArkUI_Alignment](#arkui_alignment). The default value is **ARKUI_ALIGNMENT_CENTER**.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: alignment mode. The parameter type is [ArkUI_Alignment](#arkui_alignment). |
| NODE_SCROLL_BAR_DISPLAY_MODE                | Defines the scrollbar status. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: scroll bar status. The data type is [ArkUI_ScrollBarDisplayMode](#arkui_scrollbardisplaymode), and the default value is ARKUI_SCROLL_BAR_DISPLAY_MODE_AUTO.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: scroll bar status. The data type is [ArkUI_ScrollBarDisplayMode](#arkui_scrollbardisplaymode). |
| NODE_SCROLL_BAR_WIDTH                       | Defines the width of the scrollbar. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: width of the scrollbar, in vp. The default value is **4**.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>*.value[0].f32: width of the scrollbar, in vp. |
| NODE_SCROLL_BAR_COLOR                       | Defines the color of the scrollbar. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.data[0].u32: color of the scrollbar, in 0xARGB format.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.data[0].u32: color of the scrollbar, in 0xARGB format. |
| NODE_SCROLL_SCROLL_DIRECTION                | Defines the scroll direction. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: scrolling direction. The data type is [ArkUI_ScrollDirection](#arkui_scrolldirection), and the default value is ARKUI_SCROLL_DIRECTION_VERTICAL.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: scrolling direction. The data type is [ArkUI_ScrollDirection](#arkui_scrolldirection). |
| NODE_SCROLL_EDGE_EFFECT                     | Defines the effect used at the edges of the component when the boundary of the scrollable content is reached. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: edge sliding effect. The parameter type is [ArkUI_EdgeEffect](#arkui_edgeeffect). The default value is ARKUI_EDGE_EFFECT_NONE.<br>.value[1]?.i32: whether to enable the scroll effect when the component content size is smaller than the component itself. Optional. The value **1** means to enable the scroll effect, and **0** means the opposite. The default value is **1**.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: edge sliding effect. The parameter type is [ArkUI_EdgeEffect](#arkui_edgeeffect).<br>.value[1].i32: whether to enable the scroll effect when the component content size is smaller than the component itself. The value **1** means to enable the scroll effect, and **0** means the opposite. |
| NODE_SCROLL_ENABLE_SCROLL_INTERACTION       | Sets whether to support scroll gestures. When this attribute is set to **false**, scrolling by finger or mouse is not supported, but the scroll controller API is not affected.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: whether to support scroll gestures. The default value is **true**.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: whether to support scroll gestures. |
| NODE_SCROLL_FRICTION                        | Sets the friction coefficient. It applies only to gestures in the scrolling area, and it affects only indirectly the scroll chaining during the inertial scrolling process.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: friction coefficient. The default value is **0.6** for non-wearable devices and **0.9** for wearable devices.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: friction coefficient. |
| NODE_SCROLL_SNAP                            | Defines the scroll snapping mode. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: limit scrolling mode of the scroll component. The data type is [ArkUI_ScrollSnapAlign](#arkui_scrollsnapalign), and the default value is ARKUI_SCROLL_SNAP_ALIGN_NONE.<br>.value[1].i32: whether to enable the snap to start feature. When scroll snapping is defined for the **Scroll** component, setting this attribute to **false** enables the component to scroll between the start edge and the first snap point. The default value is **true**. It is valid only when there are multiple snap points.<br>.value[2].i32: Whether to enable the snap to end feature. When scroll snapping is defined for the **Scroll** component, setting this attribute to **false** enables the component to scroll between the end edge and the last snap point. The default value is **true**. It is valid only when there are multiple snap points.<br>.value[3...].f32: snap points for the **Scroll** component. Each snap point defines the offset from an edge to which the **Scroll** component can scroll. The value can be one or more.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: alignment mode for the scroll snap position. The parameter type is [ArkUI_ScrollSnapAlign](#arkui_scrollsnapalign).<br>.value[1].i32: whether to enable the snap to start feature. When scroll snapping is defined for the **Scroll** component, setting this attribute to **false** enables the component to scroll between the start edge and the first snap point.<br>.value[2].i32: Whether to enable the snap to end feature. When scroll snapping is defined for the **Scroll** component, setting this attribute to **false** enables the component to scroll between the end edge and the last snap point.<br>.value[3...].f32: snap points for the **Scroll** component. Each snap point defines the offset from an edge to which the **Scroll** component can scroll. |
| NODE_SCROLL_NESTED_SCROLL                   | Defines the nested scrolling options. This attribute can be set, reset, and obtained as required through APIs.<br>Parameter format of the attribute setting method [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: nested scrolling when the scrollable component scrolls to the end. The parameter type is [ArkUI_ScrollNestedMode](#arkui_scrollnestedmode).<br>.value[1].i32: nested scrolling when the scrollable component scrolls to the start end. The parameter type is [ArkUI_ScrollNestedMode](#arkui_scrollnestedmode).<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: nested scrolling when the scrollable component scrolls to the end. The parameter type is [ArkUI_ScrollNestedMode](#arkui_scrollnestedmode).<br>.value[1].i32: nested scrolling when the scrollable component scrolls to the start end. The parameter type is [ArkUI_ScrollNestedMode](#arkui_scrollnestedmode). |
| NODE_SCROLL_OFFSET                          | Defines the specified position to scroll to. This attribute can be set, reset, and obtained as required through APIs.<br>Parameter format of the attribute setting method [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: horizontal scrolling offset, in vp.<br>.value[1].f32: vertical scrolling offset, in vp.<br>.value[2]?.i32: scrolling duration, in milliseconds. Optional.<br>.value[3]?.i32: (optional) scrolling curve. The parameter type is [ArkUI_AnimationCurve](#arkui_animationcurve). The default value is **ARKUI_CURVE_EASE**.<br>.value[4]?.i32: whether to enable the default spring animation. Optional. The default value **0** means not to enable the default spring animation.<br>.value[5]?.i32: whether to enable overscroll. Optional.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: horizontal scrolling offset, in vp.<br>.value[1].f32: vertical scrolling offset, in vp. |
| NODE_SCROLL_EDGE                            | Defines the edge position to scroll to. This attribute can be set and obtained as required through APIs.<br>Parameter format of the attribute setting method [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: container edge. The parameter type is [ArkUI_ScrollEdge](#arkui_scrolledge).<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: indicates whether the container is on the edge. The value -1 indicates that the container is not on the edge. If the container is on the edge, the status parameter type is [ArkUI_ScrollEdge](#arkui_scrolledge). |
| NODE_SCROLL_ENABLE_PAGING                   | Defines whether to enable the swipe-to-turn-pages feature. This attribute can be set, reset, and obtained as required through APIs.<br>If both **enablePaging** and **scrollSnap** are set, **scrollSnap** takes effect, but **enablePaging** does not.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: whether to enable the swipe-to-turn-pages feature. The default value is **false**.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: whether to enable the swipe-to-turn-pages feature. |
| NODE_SCROLL_PAGE                            | Scrolls to the next or previous page.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: whether to scroll to the next page. The value **1** means to scroll to the next page, and **0** means to scroll to the previous page.<br>.value[1]?.i32: whether to enable the page turning animation. The value **1** means to enable the page turning animation, and **0** means the opposite. Default value: 0. |
| NODE_SCROLL_BY                              | Scrolls by the specified amount.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: amount to scroll by in the horizontal direction, in vp by default. <br>.value[1].f32: amount to scroll by in the vertical direction, in vp by default. |
| NODE_LIST_DIRECTION                         | Defines the direction in which the list items are arranged. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: direction in which the list items are arranged. The parameter type is [ArkUI_Axis](#arkui_axis). The default value is **ARKUI_AXIS_VERTICAL**.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: direction in which the list items are arranged. The parameter type is [ArkUI_Axis](#arkui_axis). |
| NODE_LIST_STICKY                            | Defines whether to pin the header to the top or the footer to the bottom in the **ListItemGroup** component. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: whether to pin the header to the top or the footer to the bottom in the **ListItemGroup** component. It is used together with the **ListItemGroup** component. Data type [ArkUI_StickyStyle](#arkui_stickystyle). The default value is **ARKUI_STICKY_STYLE_NONE**.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: whether to pin the header to the top or the footer to the bottom in the **ListItemGroup** component. It is used together with the **ListItemGroup** component. The parameter type is [ArkUI_StickyStyle](#arkui_stickystyle). |
| NODE_LIST_SPACE                             | Defines the spacing between list items. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: spacing between list items along the main axis. The default value is **0**.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: spacing between list items along the main axis. |
| NODE_LIST_NODE_ADAPTER                      | Defines the list adapter. The attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.object: **ArkUI_NodeAdapter** object as the adapter.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.object: **ArkUI_NodeAdapter** object. |
| NODE_LIST_CACHED_COUNT                      | Sets the number of cached items in the list adapter. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: number of cached items in the list adapter. <br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: number of cached items in the list adapter. |
| NODE_LIST_SCROLL_TO_INDEX                   | Slide to the specified index.<br>When **smooth** is set to **true**, all passed items are loaded and counted in layout calculation. This may result in performance issues if a large number of items are involved.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: index of the item to be scrolled to in the container.<br>.value[1]?.i32: whether to enable the smooth animation for scrolling to the item with the specified index. The value **1** means to enable the animation, and **0** means the opposite. Default value: 0.<br>.value[2]?.i32: how the item to scroll to is aligned with the container. The parameter type is [ArkUI_ScrollAlignment](#arkui_scrollalignment). The default value is **ARKUI_SCROLL_ALIGNMENT_START**. |
| NODE_LIST_ALIGN_LIST_ITEM                   | Sets the alignment mode of list items along the cross axis when the cross-axis width of the list is greater than the cross-axis width of list items multiplied by the value of lanes. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: alignment mode of list items along the cross axis. The parameter type is **ArkUI_ListItemAlign**.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: alignment mode of list items along the cross axis. The parameter type is **ArkUI_ListItemAlign**. |
| NODE_LIST_CHILDREN_MAIN_SIZE                | Sets the default main axis size of the child components in this list.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>object: **ArkUI_ListChildrenMainSize** object.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.object: The parameter format is **ArkUI_ListChildrenMainSize**. |
| NODE_LIST_INITIAL_INDEX                     | Sets the item displayed at the beginning of the viewport when the current list is loaded for the first time, that is, the first item to be displayed. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: index value the item displayed at the beginning of the viewport when the current list is loaded for the first time. The default value is **0**.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: index value the item displayed at the beginning of the viewport when the current list is loaded for the first time. The default value is **0**. |
| NODE_LIST_DIVIDER                           | Defines the style of the divider for the list items. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].u32: color of the divider, in 0xARGB format. <br>.value[1].f32: stroke width of the divider.<br>.value[2].f32: distance between the divider and the start of the list, in vp.<br>.value[3].f32: distance between the divider and the end of the list, in vp.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].u32: color of the divider, in 0xARGB format. <br>.value[1].f32: stroke width of the divider.<br>.value[2].f32: distance between the divider and the start of the list, in vp.<br>.value[3].f32: distance between the divider and the end of the list, in vp. |
| NODE_SWIPER_LOOP                            | Defines whether to enable loop playback for the swiper. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: whether to enable loop playback. The value **1** means to enable loop playback, and **0** means the opposite. The default value is **1**.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: whether to enable loop playback. The value **1** means to enable loop playback, and **0** means the opposite. The default value is **1**. |
| NODE_SWIPER_AUTO_PLAY                       | Defines whether to enable automatic playback for child component switching in the swiper. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: whether to enable automatic playback for child component switching. The value **1** means to enable automatic playback, and **0** means the opposite. The default value is **0**.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: whether to enable automatic playback for child component switching. The value **1** means to enable automatic playback, and **0** means the opposite. The default value is **0**. |
| NODE_SWIPER_SHOW_INDICATOR                  | Defines whether to enable the navigation point indicator for the swiper. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: whether to enable the navigation point indicator. The value **1** means to enable the navigation point indicator, and **0** means the opposite. The default value is **1**.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: whether to enable the navigation point indicator. The value **1** means to enable the navigation point indicator, and **0** means the opposite. The default value is **1**. |
| NODE_SWIPER_INTERVAL                        | Defines the interval for automatic playback. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: interval for automatic playback, in milliseconds.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: interval for automatic playback, in milliseconds. |
| NODE_SWIPER_VERTICAL                        | Defines whether vertical swiping is used for the swiper. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: whether vertical swiping is used. The value **1** means that vertical swiping is used, and **0** means the opposite. The default value is **0**.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: whether vertical swiping is used. The value **1** means that vertical swiping is used, and **0** means the opposite. The default value is **0**. |
| NODE_SWIPER_DURATION                        | Defines the duration of the animation for switching child components. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: duration of the animation for switching child components, in milliseconds. The default value is **400**.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: duration of the animation for switching child components, in milliseconds. The default value is **400**. |
| NODE_SWIPER_CURVE                           | Defines the animation curve for the swiper. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: Sets the animation curve parameter. The parameter type is [ArkUI_AnimationCurve](#arkui_animationcurve). The default value is ARKUI_CURVE_LINEAR.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: Sets the animation curve parameter. The parameter type is [ArkUI_AnimationCurve](#arkui_animationcurve). The default value is ARKUI_CURVE_LINEAR. |
| NODE_SWIPER_ITEM_SPACE                      | Defines the spacing between child components in the swiper. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: spacing between child components.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: spacing between child components. |
| NODE_SWIPER_INDEX                           | Defines the index of the child component currently displayed in the swiper. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: number of elements to display per page.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: number of elements to display per page. |
| NODE_SWIPER_DISPLAY_COUNT                   | Defines the number of elements to display per page. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: number of elements to display per page.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: number of elements to display per page. |
| NODE_SWIPER_DISABLE_SWIPE                   | This interface is used to disable the sliding switching function of the Swiper component. The attribute setting, attribute resetting, and attribute obtaining interfaces are supported.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: whether to disable the swipe feature. The value **1** means to disable the swipe feature, and **0** means the opposite. The default value is **0**.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: whether to disable the swipe feature. The value **1** means to disable the swipe feature, and **0** means the opposite. The default value is **0**. |
| NODE_SWIPER_SHOW_DISPLAY_ARROW              | Defines whether to show the arrow when the mouse pointer hovers over the navigation point indicator. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: indicates whether to display the navigation arrow. The parameter type is [ArkUI_SwiperArrow](#arkui_swiperarrow).<br>The default value is **ARKUI_SWIPER_ARROW_HIDE**.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: indicates whether to display the navigation arrow. The parameter type is [ArkUI_SwiperArrow](#arkui_swiperarrow).<br>The default value is **ARKUI_SWIPER_ARROW_HIDE**. |
| NODE_SWIPER_EDGE_EFFECT_MODE                | Defines the effect used at the edges of the swiper when the boundary of the scrollable content is reached. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: effect used at the edges of the swiper when the boundary of the scrollable content is reached. The parameter type is [ArkUI_EdgeEffect](#arkui_edgeeffect).<br>The default value is **ARKUI_EDGE_EFFECT_SPRING**.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: effect used at the edges of the swiper when the boundary of the scrollable content is reached. The parameter type is [ArkUI_EdgeEffect](#arkui_edgeeffect). |
| NODE_SWIPER_NODE_ADAPTER                    | Defines the swiper adapter. The attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.object: **ArkUI_NodeAdapter** object as the adapter.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.object: The format of the return value is ArkUI_NodeAdapter. |
| NODE_SWIPER_CACHED_COUNT                    | Sets the number of cached items in the swiper adapter. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: number of cached items in the swiper adapter. <br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: number of cached items in the list adapter. |
| NODE_SWIPER_PREV_MARGIN                     | Sets the previous margin of the swiper. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: previous margin, in vp. The default value is **0**.<br>.value[1].i32: whether to ignore blank areas. The value **1** means to ignore blank areas, and **0** means the opposite.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: previous margin, in vp. .value[1].i32: whether to ignore blank areas. The value **1** means to ignore blank areas, and **0** means the opposite. |
| NODE_SWIPER_NEXT_MARGIN                     | Sets the next margin of the swiper. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: next margin, in vp. The default value is **0**.<br>.value[1].i32: whether to ignore blank areas. The value **1** means to ignore blank areas, and **0** means the opposite.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: next margin, in vp. .value[1].i32: whether to ignore blank areas. The value **1** means to ignore blank areas, and **0** means the opposite. |
| NODE_SWIPER_INDICATOR                       | Sets the navigation indicator type of the Swiper component. The attribute setting, attribute resetting, and attribute obtaining interfaces are supported.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: navigation indicator type. The parameter type is [ArkUI_SwiperIndicatorType](#arkui_swiperindicatortype).<br>.object: The parameter type is [ArkUI_SwiperIndicator](#arkui_swiperindicator).<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: navigation indicator type. The parameter type is [ArkUI_SwiperIndicatorType](#arkui_swiperindicatortype).<br>.object: The parameter type is [ArkUI_SwiperIndicator](#arkui_swiperindicator). |
| NODE_SWIPER_NESTED_SCROLL                   | Sets the nested scrolling mode of the **Swiper** component and its parent container.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: nested scrolling mode of the Swiper component and parent component. The parameter type is [ArkUI_SwiperNestedScrollMode](#arkui_swipernestedscrollmode).<br>The default value is **ARKUI_SWIPER_NESTED_SCROLL_SELF_ONLY**.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: nested scrolling mode of the Swiper component and parent component. The parameter type is [ArkUI_SwiperNestedScrollMode](#arkui_swipernestedscrollmode). |
| NODE_SWIPER_SWIPE_TO_INDEX                  | Sets the swiper to switch to the specified page.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: index of the target page in the swiper.<br>.value[1]?.i32: whether to use an animation for when the target page is reached. The value 1 indicates that the dynamic effect is enabled, and the value 0 indicates that the dynamic effect is disabled. The default value is 0. |
| NODE_SWIPER_INDICATOR_INTERACTIVE           | Sets whether the navigation point indicator is interactive.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: whether the navigation point indicator is interactive. The default value **true** means that the navigation point indicator is interactive.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: whether the navigation point indicator is interactive. |
| NODE_LIST_ITEM_SWIPE_ACTION                 | Sets the swipe action item displayed when the list item is swiped out from the screen edge. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.object: [ArkUI_ListItemSwipeActionOption](#arkui_listitemswipeactionoption) object.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.object: [ArkUI_ListItemSwipeActionOption](#arkui_listitemswipeactionoption) object. |
| NODE_LIST_ITEM_GROUP_SET_HEADER             | Defines the header of the list item group. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.object: Use the [ArkUI_NodeHandle](#arkui_nodehandle) object as the ListItemGroup header component.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.object: Use the [ArkUI_NodeHandle](#arkui_nodehandle) object as the ListItemGroup header component. |
| NODE_LIST_ITEM_GROUP_SET_FOOTER             | Defines the footer of the list item group. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.object: [ArkUI_NodeHandle](#arkui_nodehandle) object to be used as the footer of the list item group.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.object: [ArkUI_NodeHandle](#arkui_nodehandle) object to be used as the footer of the list item group. |
| NODE_LIST_ITEM_GROUP_SET_DIVIDER            | Defines the style of the divider for the list items. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].u32: color of the divider, in 0xARGB format.<br>.value[1].f32: stroke width of the divider, in vp.<br>.value[2].f32: distance between the divider and the start of the list, in vp.<br>.value[3].f32: distance between the divider and the end of the list, in vp.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].u32: color of the divider, in 0xARGB format.<br>.value[1].f32: stroke width of the divider, in vp.<br>.value[2].f32: distance between the divider and the start of the list, in vp.<br>.value[3].f32: distance between the divider and the end of the list, in vp. |
| NODE_LIST_ITEM_GROUP_CHILDREN_MAIN_SIZE     | Sets the default spindle size of the ListItemGroup child component.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>object: **ArkUI_ListChildrenMainSize** object.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.object: **ArkUI_ListChildrenMainSize** object. |
| NODE_COLUMN_ALIGN_ITEMS                     | Defines the horizontal alignment mode of child components in the column. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: horizontal alignment format of a child component. The data type is [ArkUI_HorizontalAlignment](#arkui_horizontalalignment).<br>Default value: **ARKUI_HORIZONTAL_ALIGNMENT_CENTER**.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: horizontal alignment format of a child component. The data type is [ArkUI_HorizontalAlignment](#arkui_horizontalalignment). |
| NODE_COLUMN_JUSTIFY_CONTENT                 | Defines the vertical alignment mode of child components in the column. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: vertical alignment format of the child component. The data type is [ArkUI_FlexAlignment](#arkui_flexalignment).<br>Default value: **ARKUI_FLEX_ALIGNMENT_START**.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: vertical alignment format of a child component. The data type is [ArkUI_FlexAlignment](#arkui_flexalignment). |
| NODE_ROW_ALIGN_ITEMS                        | Defines the vertical alignment mode of child components in the row. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: vertical alignment format of a child component. The data type is [ArkUI_VerticalAlignment](#arkui_verticalalignment).<br>Default value: **ARKUI_VERTICAL_ALIGNMENT_CENTER**.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: vertical alignment format of a child component. The data type is [ArkUI_VerticalAlignment](#arkui_verticalalignment). |
| NODE_ROW_JUSTIFY_CONTENT                    | Defines the horizontal alignment mode of child components in the row. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: horizontal alignment format of a child component. The data type is [ArkUI_FlexAlignment](#arkui_flexalignment).<br>Default value: **ARKUI_FLEX_ALIGNMENT_START**.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: horizontal alignment format of a child component. The data type is [ArkUI_FlexAlignment](#arkui_flexalignment). |
| NODE_FLEX_OPTION                            | Defines the opacity attribute, which can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0]?.i32: arrangement direction of child components on the Flex container [ArkUI_FlexDirection](#arkui_flexdirection). The default value is ARKUI_FLEX_DIRECTION_ROW.<br>.value[1]?.i32: arrangement rule [ArkUI_FlexWrap](#arkui_flexwrap). The default value is ARKUI_FLEX_WRAP_NO_WRAP.<br>.value[2]?.i32: alignment format on the principal axis [ArkUI_FlexAlignment](#arkui_flexalignment). The default value is ARKUI_FLEX_ALIGNMENT_START.<br>.value[3]?.i32: alignment format on the cross axis [ArkUI_ItemAlignment](#arkui_itemalignment). The default value is ARKUI_ITEM_ALIGNMENT_START.<br>.value[4]?.i32: alignment mode of multiple lines when there is extra space in the cross axis [ArkUI_FlexAlignment](#arkui_flexalignment). The default value is ARKUI_FLEX_ALIGNMENT_START.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: direction in which flex items are arranged. <br>.value[1].i32: how the flex items are wrapped. <br>.value[2].i32: alignment mode along the main axis. <br>.value[3].i32: alignment mode along the cross axis. <br>.value[4].i32: alignment mode along the cross axis for multi-line content. |
| NODE_REFRESH_REFRESHING                     | Sets whether a component is being refreshed. Attributes can be set and obtained.<br>Parameter format of the attribute setting method [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: The parameter type is 1 or 0.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>value[0].i32: The parameter type is 1 or 0.|
| NODE_REFRESH_CONTENT                        | Sets the custom content in the pull-down area. This attribute can be set, reset, and obtained as required through APIs.<br>Parameter format of the attribute setting method [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.object: The parameter type is **ArkUI_NodeHandle**. |
| NODE_REFRESH_PULL_DOWN_RATIO                | Sets the pull-down and hand coefficients. The interfaces for setting, resetting, and obtaining attributes are supported.<br>Parameter format of the attribute setting method [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: pull-down ratio. The value is in the range from 0 to 1.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: pull-down ratio. The value is in the range from 0 to 1. |
| NODE_REFRESH_OFFSET                         | Sets the pull-down offset that initiates a refresh. This attribute can be set, reset, and obtained as required through APIs.<br>Parameter format of the attribute setting method [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: pull-down offset, in vp. The default value is 64 vp.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: pull-down offset, in vp. The default value is 64 vp.|
| NODE_REFRESH_PULL_TO_REFRESH                | Sets whether to initiate a refresh when the pull-down distance exceeds the value of **refreshOffset**. This attribute can be set, reset, and obtained as required through APIs.<br>Parameter format of the attribute setting method [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: whether to initiate a refresh. The value **true** means to initiate a refresh, and **false** means the opposite.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: whether to initiate a refresh. The value **1** means to initiate a refresh, and **0** means the opposite. |
| NODE_WATER_FLOW_LAYOUT_DIRECTION            | Defines the main axis direction of the waterfall component layout. Attributes can be set, reset, and obtained.<br>Parameter format of the attribute setting method [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: main axis direction. The parameter type is **ArkUI_FlexDirection**.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: main axis direction. The parameter type is **ArkUI_FlexDirection**. |
| NODE_WATER_FLOW_COLUMN_TEMPLATE             | Sets the number of columns in the water flow layout. If this parameter is not set, one column is used by default. This attribute can be set, reset, and obtained as required through APIs. For example, **'1fr 1fr 2fr'** indicates three columns, with the first column taking up 1/4 of the parent component's full width, the second column 1/4, and the third column 2/4. You can use **columnsTemplate('repeat(auto-fill,track-size)')** to automatically calculate the number of rows based on the specified row height **track-size**. **repeat** and **auto-fill** are keywords. The units for **track-size** can be px, vp (default), %, or a valid number.<br>Parameter format of the attribute setting method [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string: number of layout columns.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string: number of layout columns.|
| NODE_WATER_FLOW_ROW_TEMPLATE                | Sets the number of rows in the water flow layout. If this parameter is not set, one row is used by default. This attribute can be set, reset, and obtained as required through APIs. For example, **'1fr 1fr 2fr'** indicates three rows, with the first row taking up 1/4 of the parent component's full height, the second row 1/4, and the third row 2/4. You can use **rowsTemplate('repeat(auto-fill,track-size)')** to automatically calculate the number of rows based on the specified row height **track-size**. **repeat** and **auto-fill** are keywords. The units for **track-size** can be px, vp (default), %, or a valid number.<br>Parameter format of the attribute setting method [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string: number of layout rows.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string: number of layout rows. |
| NODE_WATER_FLOW_COLUMN_GAP                  | Sets the gap between columns. This attribute can be set, reset, and obtained as required through APIs.<br>Parameter format of the attribute setting method [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: gap between columns, in vp.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: gap between columns, in vp. |
| NODE_WATER_FLOW_ROW_GAP                     | Sets the gap between rows. This attribute can be set, reset, and obtained as required through APIs.<br>Parameter format of the attribute setting method [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: gap between lines, in vp.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: gap between lines, in vp. |
| NODE_WATER_FLOW_SECTION_OPTION              | Defines the water flow section configuration. This attribute can be set, reset, and obtained as required through APIs.<br>Parameter format of the attribute setting method [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: zero-based index of the water flow item section to update. The value is converted to an integer. <br>.object: **ArkUI_WaterFlowSectionOption** object.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.object: **ArkUI_WaterFlowSectionOption** object. |
| NODE_WATER_FLOW_NODE_ADAPTER                | Defines the water flow adapter. The attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.object: **ArkUI_NodeAdapter** object as the adapter.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.object: **ArkUI_NodeAdapter** object. |
| NODE_WATER_FLOW_CACHED_COUNT                | Sets the number of cached items in the water flow adapter. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: number of cached items in the water flow adapter. |
| NODE_WATER_FLOW_FOOTER                      | Sets the custom footer for the water flow container.<br>Parameter format of the attribute setting method [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.object: custom footer. The parameter type is [ArkUI_NodeHandle](#arkui_nodehandle). |
| NODE_WATER_FLOW_SCROLL_TO_INDEX             | Scrolls to the item with the specified index.<br>When **smooth** is set to **true**, all passed items are loaded and counted in layout calculation. This may result in performance issues if a large number of items are involved.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: index of the item to be scrolled to in the container.<br>.value[1]?.i32: whether to enable the smooth animation for scrolling to the item with the specified index. The value **1** means to enable the animation, and **0** means the opposite. The default value is **0**.<br>.value[2]?.i32: how the item to scroll to is aligned with the container. The parameter type is [ArkUI_ScrollAlignment](#arkui_scrollalignment). The default value is **ARKUI_SCROLL_ALIGNMENT_START**. |
| NODE_WATER_FLOW_ITEM_CONSTRAINT_SIZE        | Defines the size constraints to apply to water flow items. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].f32: minimum width. The value **-1** indicates that the minimum width is not set. <br>.value[1].f32: maximum width. The value **-1** indicates that the maximum width is not set. <br>.value[2].f32: minimum height. The value **-1** indicates that the minimum height is not set. <br>.value[3].f32: maximum height. The value **-1** indicates that the maximum height is not set. <br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: minimum width. The value **-1** indicates that the minimum width is not set. <br>.value[1].f32: maximum width. The value **-1** indicates that the maximum width is not set. <br>.value[2].f32: minimum height. The value **-1** indicates that the minimum height is not set. <br>.value[3].f32: maximum height. The value **-1** indicates that the maximum height is not set. |
| NODE_RELATIVE_CONTAINER_GUIDE_LINE          | Sets the guideline in the **RelativeContainer**. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.object: guideline in the **RelativeContainer**.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.object: guideline in the **RelativeContainer**. |
| NODE_RELATIVE_CONTAINER_BARRIER             | Sets the barrier in the **RelativeContainer**. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.object: guideline in the **RelativeContainer**.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.object: barrier in the **RelativeContainer** component. |
| NODE_GRID_COLUMN_TEMPLATE                   | Sets the number of columns in the water flow layout. If this parameter is not set, one column is used by default. This attribute can be set, reset, and obtained as required through APIs. For example, **'1fr 1fr 2fr'** indicates three columns, with the first column taking up 1/4 of the parent component's full width, the second column 1/4, and the third column 2/4. You can use **columnsTemplate('repeat(auto-fill,track-size)')** to automatically calculate the number of rows based on the specified row height **track-size**. **repeat** and **auto-fill** are keywords. The units for **track-size** can be px, vp (default), %, or a valid number.<br>Parameter format of the attribute setting method [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string: number of layout columns.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string: number of layout columns.|
| NODE_GRID_ROW_TEMPLATE                      | Sets the number of rows or the minimum row height in the grid layout. If this parameter is not set, one row is used by default. This attribute can be set, reset, and obtained as required through APIs. For example, **'1fr 1fr 2fr'** indicates three rows, with the first row taking up 1/4 of the parent component's full height, the second row 1/4, and the third row 2/4. You can use **rowsTemplate('repeat(auto-fill,track-size)')** to automatically calculate the number of rows based on the specified row height **track-size**. **repeat** and **auto-fill** are keywords. The units for **track-size** can be px, vp (default), %, or a valid number.<br>Parameter format of the attribute setting method [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string: number of layout rows.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.string: number of layout rows. |
| NODE_GRID_COLUMN_GAP                        | Sets the gap between columns. This attribute can be set, reset, and obtained as required through APIs.<br>Parameter format of the attribute setting method [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: gap between columns, in vp.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: gap between columns, in vp. |
| NODE_GRID_ROW_GAP                           | Sets the gap between rows. This attribute can be set, reset, and obtained as required through APIs.<br>Parameter format of the attribute setting method [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: gap between lines, in vp.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].f32: gap between lines, in vp. |
| NODE_GRID_NODE_ADAPTER                      | Defines the grid adapter. The attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.object: **ArkUI_NodeAdapter** object as the adapter.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.object: The format of the return value is ArkUI_NodeAdapter. |
| NODE_GRID_CACHED_COUNT                      | Sets the number of cached items in the grid adapter. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: number of cached items in the water flow adapter. |
| NODE_IMAGE_ANIMATOR_IMAGES                  | Sets the image frame information set of the frame animation component. Dynamic update is not supported. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.size: number of image frames;<br>.object: image frame array. The parameter type is **ArkUI_ImageAnimatorFrameInfo**. <br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.size: number of image frames;<br>.object: image frame array. The parameter type is **ArkUI_ImageAnimatorFrameInfo**. |
| NODE_IMAGE_ANIMATOR_STATE                   | Sets the playback status of the frame-by-frame animation. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: controls the playing status of the animation. The parameter type is [ArkUI_AnimationStatus](#arkui_animationstatus). The default value is the initial status.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: controls the playing status of the animation. The parameter type is [ArkUI_AnimationStatus](#arkui_animationstatus). |
| NODE_IMAGE_ANIMATOR_DURATION                | Sets the playback duration of the frame-by-frame animation. This attribute does not take effect when a separate duration is set for any of the image frames. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: playback duration, in milliseconds. The default value is **1000**.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: playback duration, in milliseconds. The default value is **1000**. |
| NODE_IMAGE_ANIMATOR_REVERSE                 | Sets the playback direction of the frame-by-frame animation. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: playback direction. The value **0** indicates that images are played from the first one to the last one, and **1** indicates that images are played from the last one to the first one. The default value is **0**.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: playback direction. The value **0** indicates that images are played from the first one to the last one, and **1** indicates that images are played from the last one to the first one. |
| NODE_IMAGE_ANIMATOR_FIXED_SIZE              | Whether the image size is fixed at the component size.<br> This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: whether the image size is the fixed at the component size. The value **1** indicates that the image size is fixed at the component size. The value **0** indicates that the width, height, top, and left attributes of each image must be set separately. The default value is **1**.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: whether the image size is the fixed at the component size. The value **1** indicates that the image size is fixed at the component size. The value **0** indicates that the width, height, top, and left attributes of each image must be set separately. |
| NODE_IMAGE_ANIMATOR_FILL_MODE               | Sets the status before and after execution of the frame-by-frame animation in the current playback direction. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: status before and after execution of the frame-by-frame animation in the current playback direction. The parameter type is **ArkUI_AnimationFillMode**. The default value is **FORWARDS**.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: status before and after execution of the frame-by-frame animation in the current playback direction. The parameter type is **ArkUI_AnimationFillMode**. |
| NODE_IMAGE_ANIMATOR_ITERATION               | Number of times that the frame animation is played. This attribute can be set, reset, and obtained as required through APIs.<br>Format of the [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) parameter for setting the attribute:<br>.value[0].i32: number of times that the animation is played.<br>Format of the return value [ArkUI_AttributeItem](_ark_u_i___attribute_item.md):<br>.value[0].i32: number of times that the animation is played. |


### ArkUI_NodeContentEventType

```
enum ArkUI_NodeContentEventType
```

**Description**

Defines the NodeContent event type.

**Since**: 12

| Enum                                     | Description   |
| ---------------------------------------- | ------------- |
| NODE_CONTENT_EVENT_ON_ATTACH_TO_WINDOW   | Attach event. |
| NODE_CONTENT_EVENT_ON_DETACH_FROM_WINDOW | Detach event. |


### ArkUI_NodeCustomEventType

```
enum ArkUI_NodeCustomEventType
```

**Description**

Enumerates the custom component event types.

**Since**: 12

| Enum                                       | Description |
| ------------------------------------------ | ----------- |
| ARKUI_NODE_CUSTOM_EVENT_ON_MEASURE         | Measure.    |
| ARKUI_NODE_CUSTOM_EVENT_ON_LAYOUT          | Layout.     |
| ARKUI_NODE_CUSTOM_EVENT_ON_DRAW            | Draw.       |
| ARKUI_NODE_CUSTOM_EVENT_ON_FOREGROUND_DRAW | Foreground. |
| ARKUI_NODE_CUSTOM_EVENT_ON_OVERLAY_DRAW    | Overlay.    |


### ArkUI_NodeDirtyFlag

```
enum ArkUI_NodeDirtyFlag
```

**Description**

Enumerates the dirty area flags passed in the **::markDirty** API.

**Since**: 12

| Enum              | Description                                                  |
| ----------------- | ------------------------------------------------------------ |
| NODE_NEED_MEASURE | Recalculate the size.<br>When this type of flag is specified, re-layout is triggered by default. |
| NODE_NEED_LAYOUT  | Re-layout.                                                   |
| NODE_NEED_RENDER  | Re-rendering.                                                |

### ArkUI_NodeEventType

```
enum ArkUI_NodeEventType
```

**Description**

Enumerates the event types supported by the NativeNode component.

**Since**: 12

| Enum| Description|
| -------- | -------- |
| NODE_TOUCH_EVENT  | Gesture event.<br>When the event callback occurs, the union type in the event parameter [ArkUI_NodeEvent](#arkui_nodeevent-12) object is [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent).|
| NODE_EVENT_ON_APPEAR  | Mount event.<br>This event is triggered when the component is mounted to the component tree and displayed.<br>When the event callback occurs, the union type in the [ArkUI_NodeEvent](#arkui_nodeevent-12) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) does not contain parameters.|
| NODE_EVENT_ON_DISAPPEAR  | Unmount event.<br>This event is triggered when the component is unmounted from the component tree and disappears.<br>When the event callback occurs, the union type in the [ArkUI_NodeEvent](#arkui_nodeevent-12) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) does not contain parameters.|
| NODE_EVENT_ON_AREA_CHANGE  | Component area change event.<br>This event is triggered when the component's size, position, or any other attribute that may affect its display area changes.<br>When the event callback occurs, the union type in the [ArkUI_NodeEvent](#arkui_nodeevent-12) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) contains the following parameters:<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].f32: original width of the target element, in vp. The value is a number.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[1].f32: original height of the target element, in vp. The value is a number.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[2].f32: X coordinate of the upper left corner of the target element relative to the upper left corner of the parent element. The value type is number and the unit is vp.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[3].f32: Y-axis coordinate of the upper left corner of the target element relative to the upper left corner of the parent element. The value type is number, and the unit is vp.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[4].f32: X coordinate of the upper left corner of the target element relative to the upper left corner of the page. The value type is number, and the unit is vp.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[5].f32: Y coordinate of the upper left corner of the target element relative to the upper left corner of the page. The value type is number, and the unit is vp.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[6].f32: new width of the target element, in vp. The value is a number.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[1].f32: original height of the target element, in vp. The value is a number.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[8].f32: X coordinate of the upper left corner of the latest target element relative to the upper left corner of the parent element. The value type is number and the unit is vp.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[9].f32: Y coordinate of the upper left corner of the latest target element relative to the upper left corner of the parent element. The value type is number, and the unit is vp.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[10].f32: X coordinate of the upper left corner of the latest target element relative to the upper left corner of the page. The value type is number, and the unit is vp.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[11].f32: Y coordinate of the upper left corner of the latest target element relative to the upper left corner of the page. The value type is number, and the unit is vp.|
| NODE_ON_FOCUS  | Event of obtaining the focus.<br>This event is triggered when the component obtains the focus.<br>When the event callback occurs, the union type in the [ArkUI_NodeEvent](#arkui_nodeevent-12) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) does not contain parameters.|
| NODE_ON_BLUR  | Event of losing the focus.<br>This event is triggered when the component loses the focus.<br>When the event callback occurs, the union type in the [ArkUI_NodeEvent](#arkui_nodeevent-12) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) does not contain parameters.|
| NODE_ON_CLICK  | Click event.<br>This event is triggered when the component is clicked.<br>When the event callback occurs, the union type in the [ArkUI_NodeEvent](#arkui_nodeevent-12) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) contains the following parameters:<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].f32: X coordinate of the clicked position relative to the upper left corner of the original area of the clicked element, in vp.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[1].f32: Y coordinate of the clicked position relative to the upper left corner of the original area of the clicked element, in vp.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[2].f32: event timestamp. It is the interval between the time when the event is triggered and the time when the system starts, in microseconds.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[3].i32: event input device. The value 1 indicates the mouse, 2 indicates the touchscreen, and 4 indicates the key.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[4].f32: X coordinate of the clicked position relative to the upper left corner of the application window, in vp.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[5].f32: Y coordinate of the clicked position relative to the upper left corner of the application window, in vp.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[6].f32: X coordinate of the clicked position relative to the upper left corner of the application screen, in vp.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[7].f32: Y coordinate of the clicked position relative to the upper left corner of the application screen, in vp.|
| NODE_ON_TOUCH_INTERCEPT  | Custom component event interception.<br>This event is triggered when the component is clicked.<br>When the event callback occurs, the union type in the event parameter [ArkUI_NodeEvent](#arkui_nodeevent-12) object is [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent).|
| NODE_EVENT_ON_VISIBLE_AREA_CHANGE  | Visible area change event.<br>This event is triggered when the ratio of the component's visible area to its total area is greater than or less than the threshold. Before registering the event, you need to use **NODE_VISIBLE_AREA_CHANGE_RATIO** to configure the threshold.<br>When the event callback occurs, the union type in the [ArkUI_NodeEvent](#arkui_nodeevent-12) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) contains the following parameters:<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].i32: whether the component's visible area has increased or decreased relative to its total area since the last update. The value **1** indicates that the visible area has increased, and **0** indicates that the visible area has decreased.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[1].f32: ratio of the component's visible area to its total area at the time the callback is triggered.|
| NODE_ON_HOVER  | Called when the mouse pointer is moved over or away from the component.<br>When the event callback occurs, the union type in the [ArkUI_NodeEvent](#arkui_nodeevent-12) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) contains the following parameters:<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].i32: indicates whether the mouse pointer is hovered over the component. The value 1 indicates that the mouse pointer is hovered over the component, and the value 0 indicates that the mouse pointer is hovered over the component.|
| NODE_ON_MOUSE  | Mouse event.<br>This event is triggered when the component is clicked by a mouse device button or when the mouse pointer moves within the component.<br>When the event callback occurs, the union type in the event parameter [ArkUI_NodeEvent](#arkui_nodeevent-12) object is [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent).|
| NODE_EVENT_ON_ATTACH  | Attach event.<br>This event is triggered when the component is attached to the component tree.<br>When the event callback occurs, the union type in the [ArkUI_NodeEvent](#arkui_nodeevent-12) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) does not contain parameters.|
| NODE_EVENT_ON_DETACH  | Detach event.<br>This event is triggered when the component is detached from the component tree.<br>When the event callback occurs, the union type in the [ArkUI_NodeEvent](#arkui_nodeevent-12) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) does not contain parameters.|
| NODE_ON_ACCESSIBILITY_ACTIONS  | Accessibility action.<br>This event is triggered when an accessibility action is performed after the corresponding accessibility action type is set.<br>When the event callback occurs, the union type in the [ArkUI_NodeEvent](#arkui_nodeevent-12) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) contains the following parameters:<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].u32:: operation type for triggering callback. The parameter type is [ArkUI_AccessibilityActionType](#arkui_accessibilityactiontype).|
| NODE_ON_PRE_DRAG  | Notifies the listener of the interaction state prior to a drop and drop operation.<br>This event is triggered when a component is draggable and when a long press, lift, or drag initiation occurs.<br>When the event callback occurs, the union type in the [ArkUI_NodeEvent](#arkui_nodeevent-12) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) contains the following parameters:<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].i32: corresponds to [ArkUI_PreDragStatus](#arkui_predragstatus).|
| NODE_ON_DRAG_START  | Called when the user starts to drag an item.<br>A drag operation is recognized only when the dragged item is moved far enough.<br>When the event callback occurs, you can obtain [ArkUI_DragEvent](#arkui_dragevent) from the [ArkUI_NodeEvent](#arkui_nodeevent-12) object.|
| NODE_ON_DRAG_ENTER  | Called when a dragged item enters the boundaries of the current component.<br>The current component refers to the component that listens for this event.<br>When the event callback occurs, you can obtain [ArkUI_DragEvent](#arkui_dragevent) from the [ArkUI_NodeEvent](#arkui_nodeevent-12) object.|
| NODE_ON_DRAG_MOVE  | Called  when a dragged item moves in the current component.<br>The current component refers to the component that listens for this event.<br>When the event callback occurs, you can obtain [ArkUI_DragEvent](#arkui_dragevent) from the [ArkUI_NodeEvent](#arkui_nodeevent-12) object.|
| NODE_ON_DRAG_LEAVE  | Called when a dragged item leaves the boundaries of the current component.<br>The current component refers to the component that listens for this event.<br>When the event callback occurs, you can obtain [ArkUI_DragEvent](#arkui_dragevent) from the [ArkUI_NodeEvent](#arkui_nodeevent-12) object.|
| NODE_ON_DROP  | Called when a dragged item is dropped on the current component. The component can obtain the drag data for processing through the callback.<br>The current component refers to the component that listens for this event.<br>When the event callback occurs, you can obtain [ArkUI_DragEvent](#arkui_dragevent) from the [ArkUI_NodeEvent](#arkui_nodeevent-12) object.|
| NODE_ON_DRAG_END  | Called when a drag operation ends. The drag source can obtain the drag result by registering this callback.<br>A drag operation ends when the dragged item is released. When the event callback occurs, the [ArkUI_DragEvent](#arkui_dragevent) object can be obtained from the [ArkUI_NodeEvent](#arkui_nodeevent-12) object.|
| NODE_TEXT_ON_DETECT_RESULT_UPDATE  | Called when text recognition with the configured **TextDataDetectorConfig** settings succeeds.<br>When the event callback occurs, the union type in the [ArkUI_NodeEvent](#arkui_nodeevent-12) object is [ArkUI_StringAsyncEvent](_ark_u_i___string_async_event.md).<br>[ArkUI_StringAsyncEvent](_ark_u_i___string_async_event.md) contains the following parameters:<br>[ArkUI_StringAsyncEvent.pStr](_ark_u_i___string_async_event.md#pstr): text recognition result in JSON format. |
| NODE_IMAGE_ON_COMPLETE  | Image loading success event.<br>This event is triggered when an image is successfully loaded or decoded.<br>When the event callback occurs, the union type in the [ArkUI_NodeEvent](#arkui_nodeevent-12) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) contains the following parameters:<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].i32: loading status. The value **0** indicates that the image is loaded successfully, and the value **1** indicates that the image is decoded successfully.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[1].f32: width of the image, in px.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[2].f32: height of the image, in px.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[3].f32: width of the component, in px.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[4].f32: height of the component, in px.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[5].f32: offset of the rendered content relative to the component on the x-axis, in px.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[6].f32: offset of the rendered content relative to the component on the y-axis, in px.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[7].f32: actual rendered width of the image, in px.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[8].f32:actual rendered height of the image, in px.|
| NODE_IMAGE_ON_ERROR  | Image loading failure event.<br>This event is triggered when an error occurs during image loading.<br>When the event callback occurs, the union type in the [ArkUI_NodeEvent](#arkui_nodeevent-12) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) contains the following parameters:<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].i32 error code information:<br>401: The image could not be obtained because the image path is invalid.<br>103101: The image format is not supported.|
| NODE_IMAGE_ON_SVG_PLAY_FINISH  | Defines the SVG animation playback completion event.<br>This event is triggered when the animation playback in the loaded SVG image is complete.<br>When the event callback occurs, the union type in the [ArkUI_NodeEvent](#arkui_nodeevent-12) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) does not contain parameters.|
| NODE_IMAGE_ON_DOWNLOAD_PROGRESS  | Called during image download.<br>Condition for triggering this event: This event is triggered when the page component downloads a web page image.<br>When the event callback occurs, the union type in the [ArkUI_NodeEvent](#arkui_nodeevent-12) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) contains the following parameters:<br>Number of bytes that have been downloaded by the [ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].u32: so far.<br>Total number of bytes of images to be downloaded by the [ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[1].u32:.|
| NODE_TOGGLE_ON_CHANGE  | Called when the toggle status changes.<br>This event is triggered when the switch status changes.<br>When the event callback occurs, the union type in the [ArkUI_NodeEvent](#arkui_nodeevent-12) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) contains the following parameters:<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].i32: current switch status. The value 1 indicates that the switch is turned on, and the value 0 indicates that the switch is turned off.|
| NODE_TEXT_INPUT_ON_CHANGE  | Called when the text input content changes.<br>Condition for triggering the event: The input content changes.<br>When the event callback occurs, the union type in the [ArkUI_NodeEvent](#arkui_nodeevent-12) object is [ArkUI_StringAsyncEvent](_ark_u_i___string_async_event.md).<br>[ArkUI_StringAsyncEvent](_ark_u_i___string_async_event.md) contains the following parameters:<br>[ArkUI_StringAsyncEvent.pStr](_ark_u_i___string_async_event.md#pstr): input text content.|
| NODE_TEXT_INPUT_ON_SUBMIT  | This event is triggered when the Enter key of the textInput input method is pressed.<br>This event is triggered when the Enter key of the input method is pressed.<br>When the event callback occurs, the union type in the [ArkUI_NodeEvent](#arkui_nodeevent-12) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) contains the following parameters:<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].i32: type of the Enter key.|
| NODE_TEXT_INPUT_ON_CUT  | Called when the cut button on the pasteboard, which displays when the text box is long pressed, is clicked.<br>Condition for triggering this event: Touch and hold the internal area of the text box to display the clipboard, and touch the clipboard cut button.<br>When the event callback occurs, the union type in the [ArkUI_NodeEvent](#arkui_nodeevent-12) object is [ArkUI_StringAsyncEvent](_ark_u_i___string_async_event.md).<br>[ArkUI_StringAsyncEvent](_ark_u_i___string_async_event.md) contains the following parameters:<br>[ArkUI_StringAsyncEvent.pStr](_ark_u_i___string_async_event.md#pstr): cut text content.|
| NODE_TEXT_INPUT_ON_PASTE  | Called when the paste button on the pasteboard, which displays when the text box is long pressed, is clicked.<br>When the event callback occurs, the union type in the [ArkUI_NodeEvent](#arkui_nodeevent-12) object is [ArkUI_StringAsyncEvent](_ark_u_i___string_async_event.md).<br>[ArkUI_StringAsyncEvent](_ark_u_i___string_async_event.md) contains the following parameters:<br>[ArkUI_StringAsyncEvent.pStr](_ark_u_i___string_async_event.md#pstr): text pasted.|
| NODE_TEXT_INPUT_ON_TEXT_SELECTION_CHANGE  | Called when the text selection position changes.<br>When the event callback occurs, the union type in the [ArkUI_NodeEvent](#arkui_nodeevent-12) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) contains the following parameters:<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].i32: indicates the start position of the selected text.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[1].i32: indicates the end position of the selected text.|
| NODE_TEXT_INPUT_ON_EDIT_CHANGE  | Called when the input status changes.<br>Condition for triggering this event: The input status changes.<br>When the event callback occurs, the union type in the [ArkUI_NodeEvent](#arkui_nodeevent-12) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) contains the following parameters:<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].i32: **true** indicates that text input is in progress.|
| NODE_TEXT_INPUT_ON_INPUT_FILTER_ERROR  | Called when matching with the regular expression specified by **NODE_TEXT_INPUT_INPUT_FILTER** fails.<br>Condition for triggering the event: The regular expression fails to be matched.<br>When the event callback occurs, the union type in the [ArkUI_NodeEvent](#arkui_nodeevent-12) object is [ArkUI_StringAsyncEvent](_ark_u_i___string_async_event.md).<br>[ArkUI_StringAsyncEvent](_ark_u_i___string_async_event.md) contains the following parameters:<br>[ArkUI_StringAsyncEvent.pStr](_ark_u_i___string_async_event.md#pstr): content that is filtered out when regular expression matching fails.|
| NODE_TEXT_INPUT_ON_CONTENT_SCROLL  | Called when the text content is scrolled.<br>Condition for triggering this event: The text content is scrolled.<br>When the event callback occurs, the union type in the [ArkUI_NodeEvent](#arkui_nodeevent-12) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) contains the following parameters:<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].i32: horizontal coordinate offset of the text in the content area.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[1].i32: offset in the Y coordinate of the text in the content area.|
| NODE_TEXT_INPUT_ON_CONTENT_SIZE_CHANGE  | Called when the text input content changes.<br>Condition for triggering the event: The input content changes.<br>When the event callback occurs, the union type in the [ArkUI_NodeEvent](#arkui_nodeevent-12) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) contains the following parameters:<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].f32: indicates the width of the text.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[1].f32: height of the text.|
| NODE_TEXT_INPUT_ON_WILL_INSERT  | Called when text is about to be entered.<br>The event parameter is [ArkUI_NodeEvent](#arkui_nodeevent-12).<br>value.f32: position of the text, with the index of **0**; obtained using **OH_ArkUI_NodeEvent_GetNumberValue**.<br>buffer: string value of the text, with the index of **0**; obtained using **OH_ArkUI_NodeEvent_GetStringValue**.<br> <br>It returns **true** if the text is inserted; returns **false** otherwise. You can set the return value using **OH_ArkUI_NodeEvent_SetReturnNumberValue**.|
| NODE_TEXT_INPUT_ON_DID_INSERT  | Called when text is entered.<br>The event parameter is [ArkUI_NodeEvent](#arkui_nodeevent-12).<br>value.f32: position of the text, with the index of **0**; obtained using **OH_ArkUI_NodeEvent_GetNumberValue**.<br>buffer: string value of the text, with the index of **0**; obtained using **OH_ArkUI_NodeEvent_GetStringValue**.|
| NODE_TEXT_INPUT_ON_WILL_DELETE  | Called when text is about to be deleted.<br>The event parameter is [ArkUI_NodeEvent](#arkui_nodeevent-12).<br>value.f32: position of the text deleted, with the index of **0**; obtained using **OH_ArkUI_NodeEvent_GetNumberValue**.<br>value.i32: direction for deleting the text, with the index of **1**; obtained using **OH_ArkUI_NodeEvent_GetNumberValue**. The value **0** indicates backward-delete, and **1** indicates forward-delete.<br>buffer: string value of the text, with the index of **0**; obtained using **OH_ArkUI_NodeEvent_GetStringValue**.<br> <br>It returns **true** if the text is inserted; returns **false** otherwise.<br>You can set the return value using **OH_ArkUI_NodeEvent_SetReturnNumberValue**.|
| NODE_TEXT_INPUT_ON_DID_DELETE  | Called when text is deleted.<br>The event parameter is [ArkUI_NodeEvent](#arkui_nodeevent-12).<br>value.f32: position of the text deleted, with the index of **0**; obtained using **OH_ArkUI_NodeEvent_GetNumberValue**.<br>value.i32: direction for deleting the text, with the index of **1**; obtained using **OH_ArkUI_NodeEvent_GetNumberValue**. The value **0** indicates backward-delete, and **1** indicates forward-delete.<br>buffer: string value of the text, with the index of **0**; obtained using **OH_ArkUI_NodeEvent_GetStringValue**.|
| NODE_TEXT_AREA_ON_CHANGE  | Called when the input in the text box changes.<br> <br>When the event callback occurs, the union type in the [ArkUI_NodeEvent](#arkui_nodeevent-12) object is [ArkUI_StringAsyncEvent](_ark_u_i___string_async_event.md).<br>[ArkUI_StringAsyncEvent](_ark_u_i___string_async_event.md) contains the following parameters:<br>[ArkUI_StringAsyncEvent.pStr](_ark_u_i___string_async_event.md#pstr): text entered.|
| NODE_TEXT_AREA_ON_PASTE  | Called when the paste button on the pasteboard, which displays when the text box is long pressed, is clicked.<br>Condition for triggering this event: Touch and hold the internal area of the text box to display the clipboard, and touch the clipboard paste button.<br>When the event callback occurs, the union type in the [ArkUI_NodeEvent](#arkui_nodeevent-12) object is [ArkUI_StringAsyncEvent](_ark_u_i___string_async_event.md).<br>[ArkUI_StringAsyncEvent](_ark_u_i___string_async_event.md) contains the following parameters:<br>[ArkUI_StringAsyncEvent.pStr](_ark_u_i___string_async_event.md#pstr): text pasted.|
| NODE_TEXT_AREA_ON_TEXT_SELECTION_CHANGE  | Called when the text selection position changes.<br>Condition for triggering this event: The position of the selected text changes.<br>When the event callback occurs, the union type in the [ArkUI_NodeEvent](#arkui_nodeevent-12) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) contains the following parameters:<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].i32: indicates the start position of the selected text.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[1].i32: end position of the text selection area.|
| NODE_TEXT_AREA_ON_EDIT_CHANGE  | Called when the input status changes.<br>Condition for triggering this event: The input status changes.<br>When the event callback occurs, the union type in the [ArkUI_NodeEvent](#arkui_nodeevent-12) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) contains the following parameters:<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].i32: **true** indicates that text input is in progress.|
| NODE_TEXT_AREA_ON_SUBMIT  | Called when the Enter key on the keyboard is pressed for the multi-line text box.<br>This event is not triggered when **keyType** is **ARKUI_ENTER_KEY_TYPE_NEW_LINE**.<br>When the event callback occurs, the union type in the [ArkUI_NodeEvent](#arkui_nodeevent-12) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) contains the following parameters:<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].i32: type of the Enter key.|
| NODE_TEXT_AREA_ON_INPUT_FILTER_ERROR  | Called when matching with the regular expression specified by **NODE_TEXT_AREA_INPUT_FILTER** fails.<br> <br>When the event callback occurs, the union type in the [ArkUI_NodeEvent](#arkui_nodeevent-12) object is [ArkUI_StringAsyncEvent](_ark_u_i___string_async_event.md).<br>[ArkUI_StringAsyncEvent](_ark_u_i___string_async_event.md) contains the following parameters:<br>[ArkUI_StringAsyncEvent.pStr](_ark_u_i___string_async_event.md#pstr): content that is filtered out when regular expression matching fails.|
| NODE_TEXT_AREA_ON_CONTENT_SCROLL  | Called when the text content is scrolled.<br>Condition for triggering this event: The text content is scrolled.<br>When the event callback occurs, the union type in the [ArkUI_NodeEvent](#arkui_nodeevent-12) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) contains the following parameters:<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].i32: horizontal coordinate offset of the text in the content area.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[1].i32: offset in the Y coordinate of the text in the content area.|
| NODE_TEXT_AREA_ON_CONTENT_SIZE_CHANGE  | Called when the text input content changes in the **TextArea**. component.<br> <br>When the event callback occurs, the union type in the [ArkUI_NodeEvent](#arkui_nodeevent-12) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) contains the following parameters:<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].f32: indicates the width of the text.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[1].f32: height of the text.|
| NODE_TEXT_AREA_ON_WILL_INSERT  | Called when text is about to be entered.<br>The event parameter is [ArkUI_NodeEvent](#arkui_nodeevent-12).<br>value.f32: position of the text, with the index of **0**; obtained using **OH_ArkUI_NodeEvent_GetNumberValue**.<br>buffer: string value of the text, with the index of **0**; obtained using **OH_ArkUI_NodeEvent_GetStringValue**.<br> <br>It returns **true** if the text is inserted; returns **false** otherwise. You can set the return value using **OH_ArkUI_NodeEvent_SetReturnNumberValue**.|
| NODE_TEXT_AREA_ON_DID_INSERT  | Called when text is entered.<br>The event parameter is [ArkUI_NodeEvent](#arkui_nodeevent-12).<br>value.f32: position of the text, with the index of **0**; obtained using **OH_ArkUI_NodeEvent_GetNumberValue**.<br>buffer: string value of the text, with the index of **0**; obtained using **OH_ArkUI_NodeEvent_GetStringValue**.|
| NODE_TEXT_AREA_ON_WILL_DELETE  | Called when text is about to be deleted.<br>The event parameter is [ArkUI_NodeEvent](#arkui_nodeevent-12).<br>value.f32: position of the text deleted, with the index of **0**; obtained using **OH_ArkUI_NodeEvent_GetNumberValue**.<br>value.i32: direction for deleting the text, with the index of **1**; obtained using **OH_ArkUI_NodeEvent_GetNumberValue**. The value **0** indicates backward-delete, and **1** indicates forward-delete.<br>buffer: string value of the text, with the index of **0**; obtained using **OH_ArkUI_NodeEvent_GetStringValue**.<br> <br>It returns **true** if the text is inserted; returns **false** otherwise.<br>You can set the return value using **OH_ArkUI_NodeEvent_SetReturnNumberValue**.|
| NODE_TEXT_AREA_ON_DID_DELETE  | Called when text is deleted.<br>The event parameter is [ArkUI_NodeEvent](#arkui_nodeevent-12).<br>value.f32: position of the text deleted, with the index of **0**; obtained using **OH_ArkUI_NodeEvent_GetNumberValue**.<br>value.i32: direction for deleting the text, with the index of **1**; obtained using **OH_ArkUI_NodeEvent_GetNumberValue**. The value **0** indicates backward-delete, and **1** indicates forward-delete.<br>buffer: string value of the text, with the index of **0**; obtained using **OH_ArkUI_NodeEvent_GetStringValue**.|
| NODE_CHECKBOX_EVENT_ON_CHANGE  | Called when the selected status of the **ARKUI_NODE_CHECKBOX** component changes.<br>When the event callback occurs, the union type in the [ArkUI_NodeEvent](#arkui_nodeevent-12) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].i32: **1**: selected; **0**: not selected|
| NODE_DATE_PICKER_EVENT_ON_DATE_CHANGE  | Called when a date is selected in the **ARKUI_NODE_DATE_PICKER** component.<br> <br>When the event callback occurs, the union type in the [ArkUI_NodeEvent](#arkui_nodeevent-12) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) contains the following parameters:<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].i32: year of the selected date.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[1].i32: month of the selected date. Value range: 0–11.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[2].i32: day of the selected date.|
| NODE_TIME_PICKER_EVENT_ON_CHANGE  | Called when a time is selected in the **ARKUI_NODE_TIME_PICKER** component.<br> <br>When the event callback occurs, the union type in the [ArkUI_NodeEvent](#arkui_nodeevent-12) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) contains the following parameters:<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].i32: hour of the selected time. Value range: 0-23.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[1].i32: minute of the selected time. Value range: 0-59.|
| NODE_TEXT_PICKER_EVENT_ON_CHANGE  | Called when an item is selected in the **ARKUI_NODE_TEXT_PICKER** component.<br> <br>When the event callback occurs, the union type in the [ArkUI_NodeEvent](#arkui_nodeevent-12) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) contains the following parameters:<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0...11].i32: value of the selected item.|
| NODE_CALENDAR_PICKER_EVENT_ON_CHANGE  | Called when a date is selected in the **NODE_CALENDAR_PICKER**.<br>When the event callback occurs, the union type in the [ArkUI_NodeEvent](#arkui_nodeevent-12) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>**ArkUI_NodeComponent.data[0].u32**: year of the selected date.<br>**ArkUI_NodeComponent.data[1].u32**: month of the selected date.<br>**ArkUI_NodeComponent.data[2].u32**: day of the selected date.|
| NODE_SLIDER_EVENT_ON_CHANGE  | Called when the **ARKUI_NODE_SLIDER** component is dragged or clicked.<br>When the event callback occurs, the union type in the [ArkUI_NodeEvent](#arkui_nodeevent-12) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) contains the following parameters:<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].f32: current slider value.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[1].i32: state triggered by the event.|
| NODE_RADIO_EVENT_ON_CHANGE  | Called when the **ARKUI_NODE_RADIO** component is dragged or clicked.<br>When the event callback occurs, the union type in the [ArkUI_NodeEvent](#arkui_nodeevent-12) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) contains the following parameters:<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].i32: status of the radio button.|
| NODE_IMAGE_ANIMATOR_EVENT_ON_START  | Called when the frame-by-frame animation starts to play.<br> <br> <br>When the event callback occurs, the union type in the [ArkUI_NodeEvent](#arkui_nodeevent-12) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) does not contain parameters.|
| NODE_IMAGE_ANIMATOR_EVENT_ON_PAUSE  | Called when the frame-by-frame animation playback is paused.<br> <br> <br>When the event callback occurs, the union type in the [ArkUI_NodeEvent](#arkui_nodeevent-12) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) does not contain parameters.|
| NODE_IMAGE_ANIMATOR_EVENT_ON_REPEAT  | Called when the frame-by-frame animation playback is repeated.<br> <br> <br>When the event callback occurs, the union type in the [ArkUI_NodeEvent](#arkui_nodeevent-12) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) does not contain parameters.|
| NODE_IMAGE_ANIMATOR_EVENT_ON_CANCEL  | Called when the frame-by-frame animation playback returns to the initial state.<br> <br> <br>When the event callback occurs, the union type in the [ArkUI_NodeEvent](#arkui_nodeevent-12) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) does not contain parameters.|
| NODE_IMAGE_ANIMATOR_EVENT_ON_FINISH  | Called when the frame-by-frame animation playback is complete or stopped.<br> <br> <br>When the event callback occurs, the union type in the [ArkUI_NodeEvent](#arkui_nodeevent-12) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) does not contain parameters.|
| NODE_SWIPER_EVENT_ON_CHANGE  | Called when the index of the currently displayed element of this **ARKUI_NODE_SWIPER** instance changes.<br>When the event callback occurs, the union type in the [ArkUI_NodeEvent](#arkui_nodeevent-12) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) contains the following parameters:<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].i32: index of the currently displayed element.|
| NODE_SWIPER_EVENT_ON_ANIMATION_START  | Called when the switching animation of this **ARKUI_NODE_SWIPER** instance starts.<br>When the event callback occurs, the union type in the [ArkUI_NodeEvent](#arkui_nodeevent-12) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) contains the following parameters:<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].i32: index of the currently displayed element.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[1].i32: index of the target element to switch to.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[2].f32: offset of the currently displayed element relative to the start position of the swiper along the main axis.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[3].f32: offset of the target element relative to the start position of the swiper along the main axis.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[4].f32: hands-off velocity.|
| NODE_SWIPER_EVENT_ON_ANIMATION_END  | Called when the switching animation of this **ARKUI_NODE_SWIPER** instance ends.<br>When the event callback occurs, the union type in the [ArkUI_NodeEvent](#arkui_nodeevent-12) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) contains the following parameters:<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].i32: index of the currently displayed element.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[1].f32: offset of the currently displayed element relative to the start position of the swiper along the main axis.|
| NODE_SWIPER_EVENT_ON_GESTURE_SWIPE  | Triggered on a frame-by-frame basis when the page is turned by a swipe.<br>When the event callback occurs, the union type in the [ArkUI_NodeEvent](#arkui_nodeevent-12) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) contains the following parameters:<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].i32: index of the currently displayed element.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[1].f32: offset of the currently displayed element relative to the start position of the swiper along the main axis.|
| NODE_SWIPER_EVENT_ON_CONTENT_DID_SCROLL  | Called when content in the **ARKUI_NODE_SWIPER** component scrolls. Instructions:<br>1. When [ArkUI_SwiperDisplayModeType](#arkui_swiperdisplaymodetype) is set to ARKUI_SWIPER_DISPLAY_MODE_AUTO_LINEAR, this API does not take effect.<br>2. This API does not work when **prevMargin** and **nextMargin** are set in such a way that the **Swiper** frontend and backend display the same page during loop playback.<br>3. During page scrolling, the </b>ContentDidScrollCallback</b> callback is invoked for all pages in the viewport on a frame-by-frame basis.<br>For example, when there are two pages whose subscripts are 0 and 1 in the viewport, two callbacks whose indexes are 0 and 1 are invoked in each frame.<br>4. When the swipeByGroup parameter of the displayCount attribute is set to true and at least one page in the same group is in the window:<br>Callback is triggered for all pages in the same group.<br>When the event callback occurs, the union type in the [ArkUI_NodeEvent](#arkui_nodeevent-12) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) contains the following parameters:<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].i32: index of the Swiper component, which is the same as the index value in the onChange event.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[1].i32: index of a page in the window.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[2].f32: moving ratio of the page relative to the start position of the Swiper major axis (the start position of the page corresponding to selectedIndex).<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[3].f32: page length in the principal axis direction.|
| NODE_SCROLL_EVENT_ON_SCROLL  | Defines the scrolling event enumeration values of the scrolling container component.<br>**NOTE**<br>1. This event is triggered when scrolling is started by the **Scroll** component or other input settings, such as keyboard and mouse operations.<br>2. This event is triggered when the controller API is called.<br>3. This event supports the out-of-bounds bounce effect.<br>When the event callback occurs, the union type in the [ArkUI_NodeEvent](#arkui_nodeevent-12) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) contains the following parameters:<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].f32: horizontal scrolling offset.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[1].f32: vertical scrolling offset.|
| NODE_SCROLL_EVENT_ON_SCROLL_FRAME_BEGIN  | Called when the container starts scrolling.<br>**NOTE**<br>1. This event is triggered when scrolling is started by the **Scroll** component or other input settings, such as keyboard and mouse operations.<br>2. This event is not triggered when the controller API is called.<br>3. This event does not support the out-of-bounds bounce effect.<br>When the event callback occurs, the union type in the [ArkUI_NodeEvent](#arkui_nodeevent-12) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) contains the following parameters:<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].f32: indicates the upcoming scrolling amount.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[1].i32: current scroll state.<br>The [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) parameter contains the following return value:<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].f32: The event handler can work out the amount by which the component needs to scroll based on the real-world situation and return the result in this parameter.|
| NODE_SCROLL_EVENT_ON_WILL_SCROLL  | Called when the container is about to scroll.<br>**NOTE**<br>1. This event is triggered when scrolling is started by the **Scroll** component or other input settings, such as keyboard and mouse operations.<br>2. This event is triggered when the controller API is called.<br>3. This event supports the out-of-bounds bounce effect.<br>When the event callback occurs, the union type in the [ArkUI_NodeEvent](#arkui_nodeevent-12) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) contains the following parameters:<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].f32:: scrolling offset of each frame. The offset is positive when the content scrolls leftwards and negative when the content scrolls rightwards. The unit is vp.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[1].f32: Scrolling offset of each frame. The offset is positive when the content scrolls up and negative when the content scrolls down. The unit is vp.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[2].i32: current scroll state. The parameter type is [ArkUI_ScrollState](#arkui_scrollstate).<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[3].i32: scroll source. The parameter type is [ArkUI_ScrollSource](#arkui_scrollsource).<br>**Returns**<br>Returns one or no number to indicate the actual amount by which the scroll component scrolls.|
| NODE_SCROLL_EVENT_ON_DID_SCROLL  | Called when the container scrolls.<br>**NOTE**<br>1. This event is triggered when scrolling is started by the **Scroll** component or other input settings, such as keyboard and mouse operations.<br>2. This event is triggered when the controller API is called.<br>3. This event supports the out-of-bounds bounce effect.<br>When the event callback occurs, the union type in the [ArkUI_NodeEvent](#arkui_nodeevent-12) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) contains the following parameters:<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].f32:: scrolling offset of each frame. The offset is positive when the content scrolls leftwards and negative when the content scrolls rightwards. The unit is vp.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[1].f32: Scrolling offset of each frame. The offset is positive when the content scrolls up and negative when the content scrolls down. The unit is vp.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[2].i32: current scroll state. The parameter type is [ArkUI_ScrollState](#arkui_scrollstate).|
| NODE_SCROLL_EVENT_ON_SCROLL_START  | Called when the container starts scrolling.<br>**NOTE**<br>1. This event is triggered when scrolling is started by the **Scroll** component or other input settings, such as keyboard and mouse operations.<br>2. This event is triggered when the controller API is called, accompanied by a transition animation.<br>When the event callback occurs, the union type in the [ArkUI_NodeEvent](#arkui_nodeevent-12) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) does not contain parameters.|
| NODE_SCROLL_EVENT_ON_SCROLL_STOP  | Called when the container stops scrolling.<br>**NOTE**<br>1. This event is triggered when scrolling is stopped by the **Scroll** component or other input settings, such as keyboard and mouse operations.<br>2. This event is triggered when the controller API is called, accompanied by a transition animation.<br>When the event callback occurs, the union type in the [ArkUI_NodeEvent](#arkui_nodeevent-12) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) does not contain parameters.|
| NODE_SCROLL_EVENT_ON_SCROLL_EDGE  | Defines the scrolling edge event enumeration values of the scrolling container component.<br>**NOTE**<br>1. This event is triggered when scrolling reaches the edge after being started by the **Scroll** component or other input settings, such as keyboard and mouse operations.<br>2. This event is triggered when the controller API is called.<br>3. This event supports the out-of-bounds bounce effect.<br>When the event callback occurs, the union type in the [ArkUI_NodeEvent](#arkui_nodeevent-12) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) contains the following parameters:<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].i32 indicates the top, bottom, left, and right edges that are touched.|
| NODE_SCROLL_EVENT_ON_REACH_START  | Called when the container reaches the start edge.<br>**NOTE**<br>This event is triggered when scrolling hits the start edge.<br>When the event callback occurs, the union type in the [ArkUI_NodeEvent](#arkui_nodeevent-12) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) does not contain parameters.|
| NODE_SCROLL_EVENT_ON_REACH_END  | Called when the container reaches the end edge.<br>**NOTE**<br>This event is triggered when scrolling hits the end edge.<br>When the event callback occurs, the union type in the [ArkUI_NodeEvent](#arkui_nodeevent-12) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) does not contain parameters.|
| NODE_LIST_ON_SCROLL_INDEX  | Called when a child component enters or leaves the list display area.<br>**NOTE**<br>This event is triggered once when the list is initialized and when the index of the first child component or the next child component in the list display area changes.<br>When the event callback occurs, the union type in the [ArkUI_NodeEvent](#arkui_nodeevent-12) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) contains the following parameters:<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].i32: index of the first child component in the list display area.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[1].i32: index of the last child component in the list display area.<br>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[2].i32**: index of the center child component in the list display area.|
| NODE_LIST_ON_WILL_SCROLL  | Called when the list is about to scroll.<br>**NOTE**<br>1. This event is triggered when scrolling is started by the **Scroll** component or other input settings, such as keyboard and mouse operations.<br>2. This event is triggered when the controller API is called.<br>3. This event supports the out-of-bounds bounce effect.<br>When the event callback occurs, the union type in the [ArkUI_NodeEvent](#arkui_nodeevent-12) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) contains the following parameters:<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].f32: Scrolling offset of each frame. When the list content scrolls up, the offset is positive. When the list content scrolls down, the offset is negative.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[1].i32: current scroll state. The parameter type is [ArkUI_ScrollState](#arkui_scrollstate).<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[2].i32: scroll source. The parameter type is [ArkUI_ScrollSource](#arkui_scrollsource).<br>**Returns**<br>Returns one or no number to indicate the actual amount by which the scroll component scrolls.|
| NODE_LIST_ON_DID_SCROLL  | Called when the list scrolls.<br>**NOTE**<br>1. This event is triggered when scrolling is started by the scrollable component or other input settings, such as keyboard and mouse operations.<br>2. Scrolling can be initiated by calling the controller API.<br>3. The out-of-bounds bounce effect is supported.<br>When the event callback occurs, the union type in the [ArkUI_NodeEvent](#arkui_nodeevent-12) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) contains the following parameters:<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].f32: scroll offset of each frame. The offset is positive when the list is scrolled up and negative when the list is scrolled down.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[1].i32: current scroll state.|
| NODE_REFRESH_STATE_CHANGE  | Called when the refresh state of the **ARKUI_NODE_REFRESH** object changes.<br>When the event callback occurs, the union type in the [ArkUI_NodeEvent](#arkui_nodeevent-12) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) contains the following parameters:<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].i32: refresh state.|
| NODE_REFRESH_ON_REFRESH  | Called when the **ARKUI_NODE_REFRESH** object enters the refresh state.<br>When the event callback occurs, the union type in the [ArkUI_NodeEvent](#arkui_nodeevent-12) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) does not contain parameters.|
| NODE_REFRESH_ON_OFFSET_CHANGE  | Called when the pull-down distance of the **ARKUI_NODE_REFRESH** object changes.<br>When the event callback occurs, the union type in the [ArkUI_NodeEvent](#arkui_nodeevent-12) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) contains the following parameters:<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].f32: pull-down distance.|
| NODE_ON_WILL_SCROLL  | Called when the water flow container is about to scroll.<br>**NOTE**<br>1. This event is triggered when scrolling is started by the scrollable component or other input settings, such as keyboard and mouse operations.<br>2. Scrolling can be initiated by calling the controller API.<br>3. The out-of-bounds bounce effect is supported.<br>When the event callback occurs, the union type in the [ArkUI_NodeEvent](#arkui_nodeevent-12) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) contains the following parameters:<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].f32: scroll offset of each frame. The offset is positive when the component is scrolled up and negative when the component is scrolled down.<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[1].i32: current scroll state. The parameter type is [ArkUI_ScrollState](#arkui_scrollstate).<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[2].i32: scroll source. The parameter type is [ArkUI_ScrollSource](#arkui_scrollsource).<br>**Returns**<br>Returns one or no number to indicate the actual amount by which the scroll component scrolls.|
| NODE_WATER_FLOW_ON_DID_SCROLL  | Called when the water flow container scrolls.<br>**NOTE**<br>1. This event is triggered when scrolling is started by the scrollable component or other input settings, such as keyboard and mouse operations.<br>2. Scrolling can be initiated by calling the controller API.<br>3. The out-of-bounds bounce effect is supported.<br>When the event callback occurs, the union type in the [ArkUI_NodeEvent](#arkui_nodeevent-12) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) contains the following parameters:<br>[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].f32: Offset of scrolling each frame. The offset is positive when the content scrolls up and negative when the content scrolls down.<br>Current sliding status of the [ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[1].i32:.|
| NODE_WATER_FLOW_ON_SCROLL_INDEX  | Called when the first or last item displayed in the water flow container changes.<br>**NOTE**<br>This event is triggered when either of the preceding indexes changes.<br>When the event callback occurs, the union type in the [ArkUI_NodeEvent](#arkui_nodeevent-12) object is [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md).<br>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) contains the following parameters:<br>Index of the start position of the water flow displayed on the [ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].i32:.<br>Index of the end position of the waterfall currently displayed on the [ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[1].i32:.|


### ArkUI_NodeType

```
enum ArkUI_NodeType
```

**Description**

Enumerates ArkUI component types that can be created on the native side.

**Since**: 12

| Enum| Description|
| -------- | -------- |
| ARKUI_NODE_CUSTOM  | Custom node. |
| ARKUI_NODE_TEXT  | Text to insert. |
| ARKUI_NODE_SPAN  | Text span. |
| ARKUI_NODE_IMAGE_SPAN  | Image span. |
| ARKUI_NODE_IMAGE  | Image. |
| ARKUI_NODE_TOGGLE  | Toggle. |
| ARKUI_NODE_LOADING_PROGRESS  | Loading icon. |
| ARKUI_NODE_TEXT_INPUT  | Single-line text input. |
| ARKUI_NODE_TEXT_AREA  | Multi-line text input. |
| ARKUI_NODE_BUTTON  | Icon. |
| ARKUI_NODE_PROGRESS  | Progress indicator. |
| ARKUI_NODE_CHECKBOX  | Check box |
| ARKUI_NODE_XCOMPONENT  | XComponent. |
| ARKUI_NODE_DATE_PICKER  | Date picker. |
| ARKUI_NODE_TIME_PICKER  | Time picker. |
| ARKUI_NODE_TEXT_PICKER  | Text picker. |
| ARKUI_NODE_CALENDAR_PICKER  | Calendar picker. |
| ARKUI_NODE_SLIDER  | Slider. |
| ARKUI_NODE_RADIO  | Radio button. |
| ARKUI_NODE_IMAGE_ANIMATOR  | Frame-by-frame animation component. |
| ARKUI_NODE_STACK  | Stack container. |
| ARKUI_NODE_SWIPER  | Swiper. |
| ARKUI_NODE_SCROLL  | Scrolling container. |
| ARKUI_NODE_LIST  | List. |
| ARKUI_NODE_LIST_ITEM  | List item. |
| ARKUI_NODE_LIST_ITEM_GROUP    | List item group.                                             |
| ARKUI_NODE_COLUMN             | Column container.                                            |
| ARKUI_NODE_ROW                | Row container.                                               |
| ARKUI_NODE_FLEX               | Flex container.                                              |
| ARKUI_NODE_REFRESH            | Refresh component.                                           |
| ARKUI_NODE_WATER_FLOW         | Water flow container.                                        |
| ARKUI_NODE_FLOW_ITEM          | Water flow item.                                             |
| ARKUI_NODE_RELATIVE_CONTAINER | Relative layout component.                                   |
| ARKUI_NODE_GRID               | Grid.                                                        |
| ARKUI_NODE_GRID_ITEM          | Grid item.                                                   |
| ARKUI_NODE_CUSTOM_SPAN  | Custom span. |

### ArkUI_ObjectFit

```
enum ArkUI_ObjectFit
```

**Description**

Enumerates the image filling effects. ImageSpanAlignment

**Since**: 12

| Enum                                         | Description                                                  |
| -------------------------------------------- | ------------------------------------------------------------ |
| ARKUI_OBJECT_FIT_CONTAIN                     | The image is scaled with its aspect ratio retained for the content to be completely displayed within the display boundaries. |
| ARKUI_OBJECT_FIT_COVER                       | The image is scaled with its aspect ratio retained for both sides to be greater than or equal to the display boundaries. |
| ARKUI_OBJECT_FIT_AUTO                        | The image is scaled automatically to fit the display area.   |
| ARKUI_OBJECT_FIT_FILL                        | The image is scaled to fill the display area, and its aspect ratio is not retained. |
| ARKUI_OBJECT_FIT_SCALE_DOWN                  | The image is displayed with its aspect ratio retained, in a size smaller than or equal to the original size. |
| ARKUI_OBJECT_FIT_NONE                        | The original size is retained.                               |
| ARKUI_OBJECT_FIT_NONE_AND_ALIGN_TOP_START    | Not resized, the image is aligned with the start edge of the top of the container. |
| ARKUI_OBJECT_FIT_NONE_AND_ALIGN_TOP          | Not resized, the image is horizontally centered at the top of the container. |
| ARKUI_OBJECT_FIT_NONE_AND_ALIGN_TOP_END      | Not resized, the image is aligned with the end edge at the top of the container. |
| ARKUI_OBJECT_FIT_NONE_AND_ALIGN_START        | Not resized, the image is vertically centered on the start edge of the container. |
| ARKUI_OBJECT_FIT_NONE_AND_ALIGN_CENTER       | Not resized, the image is horizontally and vertically centered in the container. |
| ARKUI_OBJECT_FIT_NONE_AND_ALIGN_END          | Not resized, the image is vertically centered on the end edge of the container. |
| ARKUI_OBJECT_FIT_NONE_AND_ALIGN_BOTTOM_START | Not resized, the image is aligned with the start edge at the bottom of the container. |
| ARKUI_OBJECT_FIT_NONE_AND_ALIGN_BOTTOM       | Not resized, the image is horizontally centered at the bottom of the container. |
| ARKUI_OBJECT_FIT_NONE_AND_ALIGN_BOTTOM_END   | Not resized, the image is aligned with the end edge at the bottom of the container. |


### ArkUI_PreDragStatus

```
enum ArkUI_PreDragStatus
```

**Description**

Defines an enum for interaction states prior to a drop and drop operation.

**Since**: 12

| Enum                                           | Description                           |
| ---------------------------------------------- | ------------------------------------- |
| ARKUI_PRE_DRAG_STATUS_UNKNOWN                  | Unknown.                              |
| ARKUI_PRE_DRAG_STATUS_ACTION_DETECTING         | A drag gesture is being detected.     |
| ARKUI_PRE_DRAG_STATUS_READY_TO_TRIGGER_DRAG    | The component is ready to be dragged. |
| ARKUI_PRE_DRAG_STATUS_PREVIEW_LIFT_STARTED     | A lift animation is started.          |
| ARKUI_PRE_DRAG_STATUS_PREVIEW_LIFT_FINISHED    | A lift animation is finished.         |
| ARKUI_PRE_DRAG_STATUS_PREVIEW_LANDING_STARTED  | A drop animation is started.          |
| ARKUI_PRE_DRAG_STATUS_PREVIEW_LANDING_FINISHED | A drop animation is finished.         |
| ARKUI_PRE_DRAG_STATUS_CANCELED_BEFORE_DRAG     | A drop animation is terminated.       |


### ArkUI_ProgressType

```
enum ArkUI_ProgressType
```

**Description**

Enumerates the styles of the progress indicator.

**Since**: 12

| Enum                           | Description               |
| ------------------------------ | ------------------------- |
| ARKUI_PROGRESS_TYPE_LINEAR     | Linear type.              |
| ARKUI_PROGRESS_TYPE_RING       | Indeterminate ring style. |
| ARKUI_PROGRESS_TYPE_ECLIPSE    | Eclipse style.            |
| ARKUI_PROGRESS_TYPE_SCALE_RING | Determinate ring style.   |
| ARKUI_PROGRESS_TYPE_CAPSULE    | Capsule style.            |


### ArkUI_RelativeLayoutChainStyle

```
enum ArkUI_RelativeLayoutChainStyle
```

**Description**

Enumerates the chain styles.

**Since**: 12

| Enum                                            | Description                                                  |
| ----------------------------------------------- | ------------------------------------------------------------ |
| ARKUI_RELATIVE_LAYOUT_CHAIN_STYLE_SPREAD        | Child components are evenly distributed among constraint anchors. |
| ARKUI_RELATIVE_LAYOUT_CHAIN_STYLE_SPREAD_INSIDE | All child components except the first and last ones are evenly distributed among constraint anchors. |
| ARKUI_RELATIVE_LAYOUT_CHAIN_STYLE_PACKED        | There is no gap between child components in the chain.       |


### ArkUI_RenderFit

```
enum ArkUI_RenderFit
```

| Enum                                         | Description                                                  |
| -------------------------------------------- | ------------------------------------------------------------ |
| ARKUI_RENDER_FIT_CENTER                      | The component's content stays at the final size and always aligned with the center of the component. |
| ARKUI_RENDER_FIT_TOP                         | The component's content stays at the final size and always aligned with the top center of the component. |
| ARKUI_RENDER_FIT_BOTTOM                      | The component's content stays at the final size and always aligned with the bottom center of the component. |
| ARKUI_RENDER_FIT_LEFT                        | The component's content stays at the final size and always aligned with the left of the component. |
| ARKUI_RENDER_FIT_RIGHT                       | The component's content stays at the final size and always aligned with the right of the component. |
| ARKUI_RENDER_FIT_TOP_LEFT                    | The component's content stays at the final size and always aligned with the upper left corner of the component. |
| ARKUI_RENDER_FIT_TOP_RIGHT                   | The component's content stays at the final size and always aligned with the upper right corner of the component. |
| ARKUI_RENDER_FIT_BOTTOM_LEFT                 | The component's content stays at the final size and always aligned with the lower left corner of the component. |
| ARKUI_RENDER_FIT_BOTTOM_RIGHT                | The component's content stays at the final size and always aligned with the lower right corner of the component. |
| ARKUI_RENDER_FIT_RESIZE_FILL                 | The component's content is always resized to fill the component's content box, without considering its aspect ratio in the final state. |
| ARKUI_RENDER_FIT_RESIZE_CONTAIN              | While maintaining its aspect ratio in the final state, the component's content is scaled to fit within the component's content box. It is always aligned with the center of the component. |
| ARKUI_RENDER_FIT_RESIZE_CONTAIN_TOP_LEFT     | While maintaining its aspect ratio in the final state, the component's content is scaled to fit within the component's content box. When there is remaining space in the width direction of the component, the content is left-aligned with the component. When there is remaining space in the height direction of the component, the content is top-aligned with the component. |
| ARKUI_RENDER_FIT_RESIZE_CONTAIN_BOTTOM_RIGHT | While maintaining its aspect ratio in the final state, the component's content is scaled to fit within the component's content box. When there is remaining space in the width direction of the component, the content is right-aligned with the component. When there is remaining space in the height direction of the component, the content is bottom-aligned with the component. |
| ARKUI_RENDER_FIT_RESIZE_COVER                | While maintaining its aspect ratio in the final state, the component's content is scaled to cover the component's entire content box. It is always aligned with the center of the component, so that its middle part is displayed. |
| ARKUI_RENDER_FIT_RESIZE_COVER_TOP_LEFT       | While maintaining its aspect ratio in the final state, the component's content is scaled to cover the component's entire content box. When there is remaining space in the width direction, the content is left-aligned with the component, so that its left part is displayed. When there is remaining space in the height direction, the content is top-aligned with the component, so that its top part is displayed. |
| ARKUI_RENDER_FIT_RESIZE_COVER_BOTTOM_RIGHT   | While maintaining its aspect ratio in the final state, the component's content is scaled to cover the component's entire content box. When there is remaining space in the width direction, the content is right-aligned with the component, so that its right part is displayed. When there is remaining space in the height direction, the content is bottom-aligned with the component, so that its bottom part is displayed. |


### ArkUI_RouterPageState

```
enum ArkUI_RouterPageState
```

**Description**

Enumerates the states of a page during routing.

**Since**: 12

| Enum                                      | Description                              |
| ----------------------------------------- | ---------------------------------------- |
| ARKUI_ROUTER_PAGE_STATE_ON_WILL_APPEAR    | The page is about to be displayed.       |
| ARKUI_ROUTER_PAGE_STATE_ON_WILL_DISAPPEAR | The page is about to be destroyed.       |
| ARKUI_ROUTER_PAGE_STATE_ON_SHOW           | The page is displayed.                   |
| ARKUI_ROUTER_PAGE_STATE_ON_HIDE           | The page is hidden.                      |
| ARKUI_ROUTER_PAGE_STATE_ON_BACK_PRESS     | The back button is pressed for the page. |


### ArkUI_SafeAreaEdge

```
enum ArkUI_SafeAreaEdge
```

**Description**

Enumerates the edges for expanding the safe area.

**Since**: 12

| Enum                        | Description  |
| --------------------------- | ------------ |
| ARKUI_SAFE_AREA_EDGE_TOP    | Top edge.    |
| ARKUI_SAFE_AREA_EDGE_BOTTOM | Bottom edge. |
| ARKUI_SAFE_AREA_EDGE_START  | Start edge.  |
| ARKUI_SAFE_AREA_EDGE_END    | End edge.    |


### ArkUI_SafeAreaType

```
enum ArkUI_SafeAreaType
```

**Description**

Enumerates the types of expanded safe areas.

**Since**: 12

| Enum                          | Description                                                  |
| ----------------------------- | ------------------------------------------------------------ |
| ARKUI_SAFE_AREA_TYPE_SYSTEM   | Default non-safe area of the system, including the status bar and navigation bar. |
| ARKUI_SAFE_AREA_TYPE_CUTOUT   | Non-safe area of the device, for example, the notch area.    |
| ARKUI_SAFE_AREA_TYPE_KEYBOARD | Soft keyboard area.                                          |


### ArkUI_ScrollAlignment

```
enum ArkUI_ScrollAlignment
```

**Description**

Defines how the list item to scroll to is aligned with the container.

**Since**: 12

| Enum                          | Description                                                  |
| ----------------------------- | ------------------------------------------------------------ |
| ARKUI_SCROLL_ALIGNMENT_START  | The start edge of the list item is flush with the start edge of the container. |
| ARKUI_SCROLL_ALIGNMENT_CENTER | The list item is centered along the main axis of the list.   |
| ARKUI_SCROLL_ALIGNMENT_END    | The end edge of the list item Aligns the tail of an item with that of a container. |
| ARKUI_SCROLL_ALIGNMENT_AUTO   | The list item is automatically aligned. If the item is fully contained within the display area, no adjustment is performed. Otherwise, the item is aligned so that its start or end edge is flush with the start or end edge of the container, whichever requires a shorter scrolling distance. |


### ArkUI_ScrollBarDisplayMode

```
enum ArkUI_ScrollBarDisplayMode
```

**Description**

Enumerates the scrollbar display modes.

**Since**: 12

| Enum                               | Description                                               |
| ---------------------------------- | --------------------------------------------------------- |
| ARKUI_SCROLL_BAR_DISPLAY_MODE_OFF  | Not displayed.                                            |
| ARKUI_SCROLL_BAR_DISPLAY_MODE_AUTO | Displayed when the screen is touched and hidden after 2s. |
| ARKUI_SCROLL_BAR_DISPLAY_MODE_ON   | Always displayed.                                         |


### ArkUI_ScrollDirection

```
enum ArkUI_ScrollDirection

```

**Description**

Enumerates the scroll directions of scrollable components.

**Since**: 12

| Enum                              | Description                             |
| --------------------------------- | --------------------------------------- |
| ARKUI_SCROLL_DIRECTION_VERTICAL   | Only vertical scrolling is supported.   |
| ARKUI_SCROLL_DIRECTION_HORIZONTAL | Only horizontal scrolling is supported. |
| ARKUI_SCROLL_DIRECTION_NONE       | Scrolling is forbidden.                 |


### ArkUI_ScrollEdge

```
enum ArkUI_ScrollEdge

```

**Description**

Defines the edge to which the component scrolls.

**Since**: 12

| Enum                     | Description                                 |
| ------------------------ | ------------------------------------------- |
| ARKUI_SCROLL_EDGE_TOP    | Top edge in the vertical direction.         |
| ARKUI_SCROLL_EDGE_BOTTOM | Bottom edge in the vertical direction.      |
| ARKUI_SCROLL_EDGE_START  | Start position in the horizontal direction. |
| ARKUI_SCROLL_EDGE_END    | End position in the horizontal direction.   |


### ArkUI_ScrollNestedMode

```
enum ArkUI_ScrollNestedMode

```

**Description**

Enumerates nested scrolling options.

**Since**: 12

| Enum                                  | Description                                                  |
| ------------------------------------- | ------------------------------------------------------------ |
| ARKUI_SCROLL_NESTED_MODE_SELF_ONLY    | The scrolling is contained within the component, and no scroll chaining occurs, that is, the parent component does not scroll when the component scrolling reaches the boundary. |
| ARKUI_SCROLL_NESTED_MODE_SELF_FIRST   | The component scrolls first, and when it hits the boundary, the parent component scrolls. When the parent component hits the boundary, its edge effect is displayed. If no edge effect is specified for the parent component, the edge effect of the child component is displayed instead. |
| ARKUI_SCROLL_NESTED_MODE_PARENT_FIRST | The parent component scrolls first, and when it hits the boundary, the component scrolls. When the component hits the boundary, its edge effect is displayed. If no edge effect is specified for the component, the edge effect of the parent component is displayed instead. |
| ARKUI_SCROLL_NESTED_MODE_PARALLEL     | The component and its parent component scroll at the same time. When both the component and its parent component hit the boundary, the edge effect of the component is displayed. If no edge effect is specified for the component, the edge effect of the parent component is displayed instead. |


### ArkUI_ScrollSnapAlign

```
enum ArkUI_ScrollSnapAlign

```

**Description**

Enumerates the alignment modes of list items when scrolling ends.

**Since**: 12

| Enum                           | Description                                                  |
| ------------------------------ | ------------------------------------------------------------ |
| ARKUI_SCROLL_SNAP_ALIGN_NONE   | No alignment. This is the default value.                     |
| ARKUI_SCROLL_SNAP_ALIGN_START  | The first item in the view is aligned at the start of the list. |
| ARKUI_SCROLL_SNAP_ALIGN_CENTER | The middle items in the view are aligned in the center of the list. |
| ARKUI_SCROLL_SNAP_ALIGN_END    | The last item in the view is aligned at the end of the list. |


### ArkUI_ScrollSource

```
enum ArkUI_ScrollSource

```

**Description**

Enumerates the scrolling sources.

**Since**: 12

| Enum                                 | Description                                                  |
| ------------------------------------ | ------------------------------------------------------------ |
| ARKUI_SCROLL_SOURCE_DRAG             | Drag your finger.                                            |
| ARKUI_SCROLL_SOURCE_FLING            | Inertia scrolling after finger dragging.                     |
| ARKUI_SCROLL_SOURCE_EDGE_EFFECT      | Executes the EdgeEffect.Spring edge special effect when the boundary is crossed. |
| ARKUI_SCROLL_SOURCE_OTHER_USER_INPUT | User input other than dragging, such as mouse wheel and keyboard events. |
| ARKUI_SCROLL_SOURCE_SCROLL_BAR       | Scrollbar dragging                                           |
| ARKUI_SCROLL_SOURCE_SCROLL_BAR_FLING | Inertial scrolling after the scroll bar is dragged.          |
| ARKUI_SCROLL_SOURCE_SCROLLER         | Scrolling by the scroll controller (without animation).      |
| ARKUI_SCROLL_SOURCE_ANIMATION        | Scrolling by the scroll controller (with animation).         |


### ArkUI_ScrollState

```
enum ArkUI_ScrollState

```

**Description**

Enumerates the scrolling states.

**Since**: 12

| Enum                      | Description                                                  |
| ------------------------- | ------------------------------------------------------------ |
| ARKUI_SCROLL_STATE_IDLE   | Idle. The container enters this state when an API in the controller is used to scroll the container or when the scrollbar is dragged. |
| ARKUI_SCROLL_STATE_SCROLL | Scrolling. The container enters this state when the user drags the container to scroll. |
| ARKUI_SCROLL_STATE_FLING  | Inertial scrolling. The container enters this state when inertial scrolling occurs or when the container bounces back after being released from a fling. |


### ArkUI_ShadowStyle

```
enum ArkUI_ShadowStyle

```

**Description**

Enumerated value of the shadow effect.

**Since**: 12

| Enum                                 | Description             |
| ------------------------------------ | ----------------------- |
| ARKUI_SHADOW_STYLE_OUTER_DEFAULT_XS  | Mini shadow.            |
| ARKUI_SHADOW_STYLE_OUTER_DEFAULT_SM  | Small shadow.           |
| ARKUI_SHADOW_STYLE_OUTER_DEFAULT_MD  | Medium shadow.          |
| ARKUI_SHADOW_STYLE_OUTER_DEFAULT_LG  | Large shadow.           |
| ARKUI_SHADOW_STYLE_OUTER_FLOATING_SM | Floating small shadow.  |
| ARKUI_SHADOW_STYLE_OUTER_FLOATING_MD | Floating medium shadow. |


### ArkUI_ShadowType

```
enum ArkUI_ShadowType

```

**Description**

Defines the enumerated values of the shadow type.

**Since**: 12

| Enum                    | Description |
| ----------------------- | ----------- |
| ARKUI_SHADOW_TYPE_COLOR | Color.      |
| ARKUI_SHADOW_TYPE_BLUR  | Blur.       |


### ArkUI_ShapeType

```
enum ArkUI_ShapeType

```

**Description**

Enumerates custom shape types.

**Since**: 12

| Enum                       | Description  |
| -------------------------- | ------------ |
| ARKUI_SHAPE_TYPE_RECTANGLE | Rectangle.   |
| ARKUI_SHAPE_TYPE_CIRCLE    | **(circle)** |
| ARKUI_SHAPE_TYPE_ELLIPSE   | Ellipse.     |
| ARKUI_SHAPE_TYPE_PATH      | Path Type    |


### ArkUI_SliderBlockStyle

```
enum ArkUI_SliderBlockStyle

```

**Description**

Enumerates the styles of the slider in the block direction.

**Since**: 12

| Enum                             | Description                      |
| -------------------------------- | -------------------------------- |
| ARKUI_SLIDER_BLOCK_STYLE_DEFAULT | Round slider.                    |
| ARKUI_SLIDER_BLOCK_STYLE_IMAGE   | Slider with an image background. |
| ARKUI_SLIDER_BLOCK_STYLE_SHAPE   | Slider in a custom shape.        |


### ArkUI_SliderDirection

```
enum ArkUI_SliderDirection

```

**Description**

Enumerates the scroll directions of the slider.

**Since**: 12

| Enum                              | Description           |
| --------------------------------- | --------------------- |
| ARKUI_SLIDER_DIRECTION_VERTICAL   | Vertical direction.   |
| ARKUI_SLIDER_DIRECTION_HORIZONTAL | Horizontal direction. |


### ArkUI_SliderStyle

```
enum ArkUI_SliderStyle

```

**Description**

Enumerates the slider styles.

**Since**: 12

| Enum                       | Description                       |
| -------------------------- | --------------------------------- |
| ARKUI_SLIDER_STYLE_OUT_SET | The slider is on the slider rail. |
| ARKUI_SLIDER_STYLE_IN_SET  | The slider is in the slider rail. |
| ARKUI_SLIDER_STYLE_NONE    | There is no thumb.                |


### ArkUI_StickyStyle

```
enum ArkUI_StickyStyle

```

**Description**

Enumerates the modes for pinning the header to the top or the footer to the bottom.

**Since**: 12

| Enum                      | Description                                                  |
| ------------------------- | ------------------------------------------------------------ |
| ARKUI_STICKY_STYLE_NONE   | In the list item group, the header is not pinned to the top, and the footer is not pinned to the bottom. |
| ARKUI_STICKY_STYLE_HEADER | In the list item group, the header is pinned to the top, and the footer is not pinned to the bottom. |
| ARKUI_STICKY_STYLE_FOOTER | In the list item group, the footer is pinned to the bottom, and the header is not pinned to the top. |
| ARKUI_STICKY_STYLE_BOTH   | In the list item group, the footer is pinned to the bottom, and the header is pinned to the top. |


### ArkUI_SwiperArrow

```
enum ArkUI_SwiperArrow

```

**Description**

Enumerates arrow styles of the navigation point indicator.

**Since**: 12

| Enum                             | Description                                                  |
| -------------------------------- | ------------------------------------------------------------ |
| ARKUI_SWIPER_ARROW_HIDE          | The arrow is not displayed for the navigation point indicator. |
| ARKUI_SWIPER_ARROW_SHOW          | The arrow is displayed for the navigation point indicator.   |
| ARKUI_SWIPER_ARROW_SHOW_ON_HOVER | The arrow is displayed only when the mouse pointer hovers over the navigation point indicator. |


### ArkUI_SwiperDisplayModeType

```
enum ArkUI_SwiperDisplayModeType

```

**Description**

Enumerates the modes in which elements are displayed along the main axis of the **Swiper** component.

**Since**: 12

| Enum                                  | Description                                                  |
| ------------------------------------- | ------------------------------------------------------------ |
| ARKUI_SWIPER_DISPLAY_MODE_STRETCH     | The slide width of the **Swiper** component is equal to the width of the component. |
| ARKUI_SWIPER_DISPLAY_MODE_AUTO_LINEAR | The slide width of the **Swiper** component is equal to the width of the leftmost child component in the viewport. |


### ArkUI_SwiperIndicatorType

```
enum ArkUI_SwiperIndicatorType

```

**Description**

Enumerates the navigation point indicator types of the **Swiper** component.

**Since**: 12

| Enum                              | Description |
| --------------------------------- | ----------- |
| ARKUI_SWIPER_INDICATOR_TYPE_DOT   | Dot type.   |
| ARKUI_SWIPER_INDICATOR_TYPE_DIGIT | Digit type. |


### ArkUI_SwiperNestedScrollMode

```
enum ArkUI_SwiperNestedScrollMode

```

**Description**

Enumerates the nested scrolling mode of the **Swiper** component and its parent container.

**Since**: 12

| Enum                                  | Description                                                  |
| ------------------------------------- | ------------------------------------------------------------ |
| ARKUI_SWIPER_NESTED_SRCOLL_SELF_ONLY  | The scrolling is contained within the **Swiper** component, and no scroll chaining occurs, that is, the parent container does not scroll when the component scrolling reaches the boundary. |
| ARKUI_SWIPER_NESTED_SRCOLL_SELF_FIRST | The **Swiper** component scrolls first, and when it hits the boundary, the parent container scrolls. When the parent container hits the boundary, its edge effect is displayed. If no edge effect is specified for the parent container, the edge effect of the child component is displayed instead. |


### ArkUI_SystemColorMode

```
enum ArkUI_SystemColorMode
```
**Description**

Enumerates the system color modes.

**Since**: 12

| Enum| Description|
| -------- | -------- |
| ARKUI_SYSTEM_COLOR_MODE_LIGHT  | Light mode. |
| ARKUI_SYSTEM_COLOR_MODE_DARK  | Dark mode. |


### ArkUI_TextAlignment

```
enum ArkUI_TextAlignment
```
**Description**

Enumerates the text alignment mode.

**Since**: 12

| Enum| Description|
| -------- | -------- |
| ARKUI_TEXT_ALIGNMENT_START  | Aligned with the start. |
| ARKUI_TEXT_ALIGNMENT_CENTER  | Horizontally centered. |
| ARKUI_TEXT_ALIGNMENT_END  | Aligned with the end. |
| ARKUI_TEXT_ALIGNMENT_JUSTIFY  | Aligned with both margins. |


### ArkUI_TextAreaType

```
enum ArkUI_TextAreaType
```
**Description**

Enumerates the text box types.

**Since**: 12

| Enum| Description|
| -------- | -------- |
| ARKUI_TEXTAREA_TYPE_NORMAL  | Normal input mode. |
| ARKUI_TEXTAREA_TYPE_NUMBER  | Number input mode. |
| ARKUI_TEXTAREA_TYPE_PHONE_NUMBER  | Phone number input mode. |
| ARKUI_TEXTAREA_TYPE_EMAIL  | Email address input mode. |


### ArkUI_TextCase

```
enum ArkUI_TextCase
```
**Description**

Defines the enumerated values of text case.

**Since**: 12

| Enum| Description|
| -------- | -------- |
| ARKUI_TEXT_CASE_NORMAL  | The original case of the text is retained. |
| ARKUI_TEXT_CASE_LOWER  | All letters in the text are in lowercase. |
| ARKUI_TEXT_CASE_UPPER  | All letters in the text are in uppercase. |


### ArkUI_TextCopyOptions

```
enum ArkUI_TextCopyOptions
```
**Description**

Enumerates copy options, which define whether copy and paste is allowed for text content.

**Since**: 12

| Enum| Description|
| -------- | -------- |
| ARKUI_TEXT_COPY_OPTIONS_NONE  | Copy is not allowed. |
| ARKUI_TEXT_COPY_OPTIONS_IN_APP  | Intra-application copy is allowed. |
| ARKUI_TEXT_COPY_OPTIONS_LOCAL_DEVICE  | Intra-device copy is allowed. |
| ARKUI_TEXT_COPY_OPTIONS_CROSS_DEVICE  | Cross-device copy is allowed. |


### ArkUI_TextDataDetectorType

```
enum ArkUI_TextDataDetectorType
```
**Description**

Enumerates the entity types of text recognition.

**Since**: 12

| Enum| Description|
| -------- | -------- |
| ARKUI_TEXT_DATA_DETECTOR_TYPE_PHONE_NUMBER  | Phone number. |
| ARKUI_TEXT_DATA_DETECTOR_TYPE_URL  | Link. |
| ARKUI_TEXT_DATA_DETECTOR_TYPE_EMAIL  | Email  |
| ARKUI_TEXT_DATA_DETECTOR_TYPE_ADDRESS  | Network address. |


### ArkUI_TextDecorationStyle

```
enum ArkUI_TextDecorationStyle
```
**Description**

Enumerates the text decoration styles.

**Since**: 12

| Enum| Description|
| -------- | -------- |
| ARKUI_TEXT_DECORATION_STYLE_SOLID  | Single solid line. |
| ARKUI_TEXT_DECORATION_STYLE_DOUBLE  | Double solid line. |
| ARKUI_TEXT_DECORATION_STYLE_DOTTED  | Dotted line. |
| ARKUI_TEXT_DECORATION_STYLE_DASHED  | Dashed style. |
| ARKUI_TEXT_DECORATION_STYLE_WAVY  | Wavy line. |


### ArkUI_TextDecorationType

```
enum ArkUI_TextDecorationType
```
**Description**

Enumerates the text decoration types.

**Since**: 12

| Enum| Description|
| -------- | -------- |
| ARKUI_TEXT_DECORATION_TYPE_NONE  | No text decoration. |
| ARKUI_TEXT_DECORATION_TYPE_UNDERLINE  | Line under the text. |
| ARKUI_TEXT_DECORATION_TYPE_OVERLINE  | Line over the text. |
| ARKUI_TEXT_DECORATION_TYPE_LINE_THROUGH  | Line through the text. |


### ArkUI_TextHeightAdaptivePolicy

```
enum ArkUI_TextHeightAdaptivePolicy
```
**Description**

Defines how the adaptive height is determined for the text.

**Since**: 12

| Enum| Description|
| -------- | -------- |
| ARKUI_TEXT_HEIGHT_ADAPTIVE_POLICY_MAX_LINES_FIRST  | Prioritize the **maxLines** settings. |
| ARKUI_TEXT_HEIGHT_ADAPTIVE_POLICY_MIN_FONT_SIZE_FIRST  | Prioritize the **minFontSize** settings. |
| ARKUI_TEXT_HEIGHT_ADAPTIVE_POLICY_LAYOUT_CONSTRAINT_FIRST  | Prioritize the layout constraint settings in terms of height. |


### ArkUI_TextInputContentType

```
enum ArkUI_TextInputContentType
```
**Description**

Enumerates the autofill types.

**Since**: 12

| Enum| Description|
| -------- | -------- |
| ARKUI_TEXTINPUT_CONTENT_TYPE_USER_NAME  | Username. Password Vault, when enabled, can automatically save and fill in usernames. |
| ARKUI_TEXTINPUT_CONTENT_TYPE_PASSWORD  | Password. Password Vault, when enabled, can automatically save and fill in passwords. |
| ARKUI_TEXTINPUT_CONTENT_TYPE_NEW_PASSWORD  | New password. Password Vault, when enabled, can automatically generate a new password. |
| ARKUI_TEXTINPUT_CONTENT_TYPE_FULL_STREET_ADDRESS  | Full street address. The scenario-based autofill feature, when enabled, can automatically save and fill in full street addresses. |
| ARKUI_TEXTINPUT_CONTENT_TYPE_HOUSE_NUMBER  | House number. The scenario-based autofill feature, when enabled, can automatically save and fill in house numbers. |
| ARKUI_TEXTINPUT_CONTENT_TYPE_DISTRICT_ADDRESS  | District and county. The scenario-based autofill feature, when enabled, can automatically save and fill in districts and counties. |
| ARKUI_TEXTINPUT_CONTENT_TYPE_CITY_ADDRESS  | City. The scenario-based autofill feature, when enabled, can automatically save and fill in cities. |
| ARKUI_TEXTINPUT_CONTENT_TYPE_PROVINCE_ADDRESS  | Province. The scenario-based autofill feature, when enabled, can automatically save and fill in provinces. |
| ARKUI_TEXTINPUT_CONTENT_TYPE_COUNTRY_ADDRESS  | Country. The scenario-based autofill feature, when enabled, can automatically save and fill in countries. |
| ARKUI_TEXTINPUT_CONTENT_TYPE_PERSON_FULL_NAME  | Full name. The scenario-based autofill feature, when enabled, can automatically save and fill in full names. |
| ARKUI_TEXTINPUT_CONTENT_TYPE_PERSON_LAST_NAME  | Last name. The scenario-based autofill feature, when enabled, can automatically save and fill in last names. |
| ARKUI_TEXTINPUT_CONTENT_TYPE_PERSON_FIRST_NAME  | First name. The scenario-based autofill feature, when enabled, can automatically save and fill in first names. |
| ARKUI_TEXTINPUT_CONTENT_TYPE_PHONE_NUMBER  | Phone number. The scenario-based autofill feature, when enabled, can automatically save and fill in phone numbers. |
| ARKUI_TEXTINPUT_CONTENT_TYPE_PHONE_COUNTRY_CODE  | Country code. The scenario-based autofill feature, when enabled, can automatically save and fill in country codes. |
| ARKUI_TEXTINPUT_CONTENT_TYPE_FULL_PHONE_NUMBER  | Phone number with country code. The scenario-based autofill feature, when enabled, can automatically save and fill in phone numbers with country codes. |
| ARKUI_TEXTINPUT_CONTENT_EMAIL_ADDRESS  | Email address. The scenario-based autofill feature, when enabled, can automatically save and fill in email addresses. |
| ARKUI_TEXTINPUT_CONTENT_TYPE_BANK_CARD_NUMBER  | Bank card number. The scenario-based autofill feature, when enabled, can automatically save and fill in bank card numbers. |
| ARKUI_TEXTINPUT_CONTENT_TYPE_ID_CARD_NUMBER  | ID card number. The scenario-based autofill feature, when enabled, can automatically save and fill in ID card numbers. |
| ARKUI_TEXTINPUT_CONTENT_TYPE_NICKNAME  | Nickname. The scenario-based autofill feature, when enabled, can automatically save and fill in nicknames. |
| ARKUI_TEXTINPUT_CONTENT_TYPE_DETAIL_INFO_WITHOUT_STREET  | Address information without street address. The scenario-based autofill feature, when enabled, can automatically save and fill in address information without street addresses. |
| ARKUI_TEXTINPUT_CONTENT_TYPE_FORMAT_ADDRESS  | Standard address. The scenario-based autofill feature, when enabled, can automatically save and fill in standard addresses. |


### ArkUI_TextInputStyle

```
enum ArkUI_TextInputStyle
```
**Description**

Enumerates the text input styles.

**Since**: 12

| Enum| Description|
| -------- | -------- |
| ARKUI_TEXTINPUT_STYLE_DEFAULT  | Default style. The caret width is fixed at 1.5 vp, and the caret height is subject to the background height and font size of the selected text. |
| ARKUI_TEXTINPUT_STYLE_INLINE  | Inline input style. The background height of the selected text is the same as the height of the text box. |


### ArkUI_TextInputType

```
enum ArkUI_TextInputType
```
**Description**

Enumerates the text input types.

**Since**: 12

| Enum| Description|
| -------- | -------- |
| ARKUI_TEXTINPUT_TYPE_NORMAL  | Normal input mode. |
| ARKUI_TEXTINPUT_TYPE_NUMBER  | Number input mode. |
| ARKUI_TEXTINPUT_TYPE_PHONE_NUMBER  | Phone number input mode. |
| ARKUI_TEXTINPUT_TYPE_EMAIL  | Email address input mode. |
| ARKUI_TEXTINPUT_TYPE_PASSWORD  | Password input mode. |
| ARKUI_TEXTINPUT_TYPE_NUMBER_PASSWORD  | Numeric password input mode. |
| ARKUI_TEXTINPUT_TYPE_SCREEN_LOCK_PASSWORD  | Lock screen password input mode. |
| ARKUI_TEXTINPUT_TYPE_USER_NAME  | Username input mode. |
| ARKUI_TEXTINPUT_TYPE_NEW_PASSWORD  | New password input mode. |
| ARKUI_TEXTINPUT_TYPE_NUMBER_DECIMAL  | Number input mode with a decimal point. |


### ArkUI_TextOverflow

```
enum ArkUI_TextOverflow
```
**Description**

Enumerates the display modes when the text is too long.

**Since**: 12

| Enum| Description|
| -------- | -------- |
| ARKUI_TEXT_OVERFLOW_NONE  | Extra-long text is not clipped. |
| ARKUI_TEXT_OVERFLOW_CLIP  | Extra-long text is clipped. |
| ARKUI_TEXT_OVERFLOW_ELLIPSIS  | An ellipsis (...) is used to represent text overflow. |
| ARKUI_TEXT_OVERFLOW_MARQUEE  | Text continuously scrolls when text overflow occurs. |


### ArkUI_TextPickerRangeType

```
enum ArkUI_TextPickerRangeType
```
**Description**

Enumerates the types of the text picker.

**Since**: 12

| Enum| Description|
| -------- | -------- |
| ARKUI_TEXTPICKER_RANGETYPE_SINGLE  | Single-column text picker. |
| ARKUI_TEXTPICKER_RANGETYPE_MULTI  | Multi-column text picker. |
| ARKUI_TEXTPICKER_RANGETYPE_RANGE_CONTENT  | Single-column text picker with image resources. |
| ARKUI_TEXTPICKER_RANGETYPE_CASCADE_RANGE_CONTENT  | Interconnected multi-column text picker. |


### ArkUI_ThemeColorMode

```
enum ArkUI_ThemeColorMode
```

| Enum| Description|
| -------- | -------- |
| ARKUI_THEME_COLOR_MODE_SYSTEM  | Following the system color mode. |
| ARKUI_THEME_COLOR_MODE_LIGHT  | Light color mode. |
| ARKUI_THEME_COLOR_MODE_DARK  | Dark color mode. |


### ArkUI_TransitionEdge

```
enum ArkUI_TransitionEdge
```
**Description**

Enumerates the slide-in and slide-out positions of the component from the screen edge during transition.

**Since**: 12

| Enum| Description|
| -------- | -------- |
| ARKUI_TRANSITION_EDGE_TOP  | Top edge of the window. |
| ARKUI_TRANSITION_EDGE_BOTTOM  | Bottom edge of the window. |
| ARKUI_TRANSITION_EDGE_START  | Left edge of the window. |
| ARKUI_TRANSITION_EDGE_END  | Right edge of the window. |


### ArkUI_VerticalAlignment

```
enum ArkUI_VerticalAlignment
```
**Description**

Enumerates the vertical alignment modes.

**Since**: 12

| Enum| Description|
| -------- | -------- |
| ARKUI_VERTICAL_ALIGNMENT_TOP  | Top aligned. |
| ARKUI_VERTICAL_ALIGNMENT_CENTER  | Aligned with the center. This is the default alignment mode. |
| ARKUI_VERTICAL_ALIGNMENT_BOTTOM  | Bottom aligned. |


### ArkUI_Visibility

```
enum ArkUI_Visibility
```
**Description**

Enumerates the visibility values.

**Since**: 12

| Enum| Description|
| -------- | -------- |
| ARKUI_VISIBILITY_VISIBLE  | Display |
| ARKUI_VISIBILITY_HIDDEN  | The component is hidden, and a placeholder is used for it in the layout. |
| ARKUI_VISIBILITY_NONE  | The component is hidden. It is not involved in the layout, and no placeholder is used for it. |


### ArkUI_WordBreak

```
enum ArkUI_WordBreak
```
**Description**

Enumerates the word break rules.

**Since**: 12

| Enum| Description|
| -------- | -------- |
| ARKUI_WORD_BREAK_NORMAL  | Word breaks can occur between any two characters for Chinese, Japanese, and Korean (CJK) text, but can occur only at a space character for non-CJK text (such as English). |
| ARKUI_WORD_BREAK_BREAK_ALL  | Word breaks can occur between any two characters for non-CJK text. CJK text behavior is the same as for **NORMAL**. |
| ARKUI_WORD_BREAK_BREAK_WORD  | This option has the same effect as **BREAK_ALL** for non-CJK text, except that if it preferentially wraps lines at appropriate characters (for example, spaces) whenever possible. CJK text behavior is the same as for **NORMAL**. |


### ArkUI_XComponentType

```
enum ArkUI_XComponentType
```
**Description**

Defines the enumerated values of the XComponent type.

**Since**: 12

| Enum| Description|
| -------- | -------- |
| ARKUI_XCOMPONENT_TYPE_SURFACE  | The custom content of EGL/OpenGL ES and media data is displayed individually on the screen. |
| ARKUI_XCOMPONENT_TYPE_TEXTURE  | The custom content of EGL/OpenGL ES and media data is grouped and displayed together with content of the component. |


## Function Description


### OH_ArkUI_AccessibilityState_Create()

```
ArkUI_AccessibilityState* OH_ArkUI_AccessibilityState_Create (void )
```
**Description**

Creates an accessibility state.

**Since**: 12

**Returns**

Returns the pointer to the created accessibility state object. If a null pointer is returned, the creation fails. A possible cause is that the application address space is full.


### OH_ArkUI_AccessibilityState_Dispose()

```
void OH_ArkUI_AccessibilityState_Dispose (ArkUI_AccessibilityState * state)
```
**Description**

Disposes of the pointer to an accessibility state.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| state | Pointer to an accessibility state object. |


### OH_ArkUI_AccessibilityState_GetCheckedState()

```
int32_t OH_ArkUI_AccessibilityState_GetCheckedState (ArkUI_AccessibilityState * state)
```
**Description**

Obtains the check box state of an accessibility state.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| state | Pointer to an accessibility state object. |

**Returns**

Returns the check box state. The parameter type is [ArkUI_AccessibilityCheckedState](#arkui_accessibilitycheckedstate). The default value is **ARKUI_ACCESSIBILITY_UNCHECKED**. If a parameter error occurs, the default value is returned.


### OH_ArkUI_AccessibilityState_IsDisabled()

```
int32_t OH_ArkUI_AccessibilityState_IsDisabled (ArkUI_AccessibilityState * state)
```
**Description**

Obtains whether an accessibility state is disabled.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| state | Pointer to an accessibility state object. |

**Returns**

Returns whether the accessibility state is disabled. The value **1** means that the accessibility state is disabled, and **0** means the opposite. The default value is **0**. If the value of **state** is empty, the default value is returned.


### OH_ArkUI_AccessibilityState_IsSelected()

```
int32_t OH_ArkUI_AccessibilityState_IsSelected (ArkUI_AccessibilityState * state)
```
**Description**

Obtains whether an accessibility state is selected.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| state | Pointer to an accessibility state object. |

**Returns**

Returns whether the accessibility state is selected. The value **1** means that the accessibility state is selected, and **0** means the opposite. The default value is **0**. If the value of **state** is empty, the default value is returned.


### OH_ArkUI_AccessibilityState_SetCheckedState()

```
void OH_ArkUI_AccessibilityState_SetCheckedState (ArkUI_AccessibilityState * state, int32_t checkedState )
```
**Description**

Sets the check box state of an accessibility state.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| state | Pointer to an accessibility state object. |
| checkedState | Check box status. The parameter type is [ArkUI_AccessibilityCheckedState](#arkui_accessibilitycheckedstate). The default value is **ARKUI_ACCESSIBILITY_UNCHECKED**. |


### OH_ArkUI_AccessibilityState_SetDisabled()

```
void OH_ArkUI_AccessibilityState_SetDisabled (ArkUI_AccessibilityState * state, int32_t isDisabled )
```
**Description**

Sets whether an accessibility state is disabled.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| state | Pointer to an accessibility state object. |
| isDisabled | Whether the accessibility state is disabled. The value **1** means that the accessibility state is disabled, and **0** means the opposite. The default value is **0**. |


### OH_ArkUI_AccessibilityState_SetSelected()

```
void OH_ArkUI_AccessibilityState_SetSelected (ArkUI_AccessibilityState * state, int32_t isSelected )
```
**Description**

Sets whether an accessibility state is selected.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| state | Pointer to an accessibility state object. |
| isSelected | Whether the accessibility state is selected. The value **1** means that the accessibility state is selected, and **0** means the opposite. The default value is **0**. |


### OH_ArkUI_AccessibilityValue_Create()

```
ArkUI_AccessibilityValue* OH_ArkUI_AccessibilityValue_Create (void )
```
**Description**

Creates an **AccessibilityValue** instance.

**Since**: 12

**Returns**

Returns the pointer to the created **AccessibilityValue** instance.


### OH_ArkUI_AccessibilityValue_Dispose()

```
void OH_ArkUI_AccessibilityValue_Dispose (ArkUI_AccessibilityValue * value)
```
**Description**

Disposes of the pointer to an **AccessibilityValue** instance.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| state | Pointer to an **AccessibilityValue** instance. |


### OH_ArkUI_AccessibilityValue_GetCurrent()

```
int32_t OH_ArkUI_AccessibilityValue_GetCurrent (ArkUI_AccessibilityValue * value)
```
**Description**

Obtains the current accessibility value.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| value | Pointer to an **AccessibilityValue** instance. |

**Returns**

Returns the current value based on the range component. The default value is **-1**. If a parameter error occurs, **-1** is returned.


### OH_ArkUI_AccessibilityValue_GetMax()

```
int32_t OH_ArkUI_AccessibilityValue_GetMax (ArkUI_AccessibilityValue * value)
```
**Description**

Obtains the maximum accessibility value.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| value | Pointer to an **AccessibilityValue** instance. |

**Returns**

Returns the maximum value based on the range component. The default value is **-1**. If a parameter error occurs, **-1** is returned.


### OH_ArkUI_AccessibilityValue_GetMin()

```
int32_t OH_ArkUI_AccessibilityValue_GetMin (ArkUI_AccessibilityValue * value)
```
**Description**

Obtains the minimum accessibility value.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| value | Pointer to an **AccessibilityValue** instance. |

**Returns**

Returns the minimum value based on the range component. The default value is **-1**. If a parameter error occurs, **-1** is returned.


### OH_ArkUI_AccessibilityValue_GetText()

```
const char* OH_ArkUI_AccessibilityValue_GetText (ArkUI_AccessibilityValue * value)
```
**Description**

Obtains the text description of an **AccessibilityValue** instance.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| value | Pointer to an **AccessibilityValue** instance. |

**Returns**

Returns the text description. The default value is an empty string. If a parameter error occurs, a null pointer is returned.


### OH_ArkUI_AccessibilityValue_SetCurrent()

```
void OH_ArkUI_AccessibilityValue_SetCurrent (ArkUI_AccessibilityValue * value, int32_t current )
```
**Description**

Sets the current accessibility value.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| value | Pointer to an **AccessibilityValue** instance. |
| current | Current value based on the range component. The default value is **-1**. |


### OH_ArkUI_AccessibilityValue_SetMax()

```
void OH_ArkUI_AccessibilityValue_SetMax (ArkUI_AccessibilityValue * value, int32_t max )
```
**Description**

Sets the maximum accessibility value.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| value | Pointer to an **AccessibilityValue** instance. |
| max | Maximum value based on the range component. The default value is **-1**. |


### OH_ArkUI_AccessibilityValue_SetMin()

```
void OH_ArkUI_AccessibilityValue_SetMin (ArkUI_AccessibilityValue * value, int32_t min )
```
**Description**

Sets the minimum accessibility value.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| value | Pointer to an **AccessibilityValue** instance. |
| min | Minimum value based on the range component. The default value is **-1**. |


### OH_ArkUI_AccessibilityValue_SetText()

```
void OH_ArkUI_AccessibilityValue_SetText (ArkUI_AccessibilityValue * value, const char * text )
```
**Description**

Sets the text description of an **AccessibilityValue** instance.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| value | Pointer to an **AccessibilityValue** instance. |
| text | Text description. The default value is an empty string. |


### OH_ArkUI_AlignmentRuleOption_Create()

```
ArkUI_AlignmentRuleOption* OH_ArkUI_AlignmentRuleOption_Create ()
```
**Description**

Creates an alignment rule configuration for this **RelativeContainer** component.

**Since**: 12

**Returns**

Alignment rule information.


### OH_ArkUI_AlignmentRuleOption_Dispose()

```
void OH_ArkUI_AlignmentRuleOption_Dispose (ArkUI_AlignmentRuleOption * option)
```
**Description**

Disposes of an alignment rule configuration of this **RelativeContainer** component.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Pointer to an alignment rule configuration. |


### OH_ArkUI_AlignmentRuleOption_GetBiasHorizontal()

```
float OH_ArkUI_AlignmentRuleOption_GetBiasHorizontal (ArkUI_AlignmentRuleOption * option)
```
**Description**

Obtains the bias value in the horizontal direction.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Pointer to an alignment rule configuration. |

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

| Name| Description|
| -------- | -------- |
| option | Pointer to an alignment rule configuration. |

**Returns**

Returns the bias value in the vertical direction.


### OH_ArkUI_AlignmentRuleOption_GetBottomAlignment()

```
ArkUI_VerticalAlignment OH_ArkUI_AlignmentRuleOption_GetBottomAlignment (ArkUI_AlignmentRuleOption * option)
```
**Description**

Obtains the alignment mode in bottom alignment parameters.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Pointer to an alignment rule configuration. |

**Returns**

Returns the alignment mode in bottom alignment parameters.


### OH_ArkUI_AlignmentRuleOption_GetBottomId()

```
const char* OH_ArkUI_AlignmentRuleOption_GetBottomId (ArkUI_AlignmentRuleOption * option)
```
**Description**

Obtains the alignment mode in bottom alignment parameters.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Pointer to an alignment rule configuration. |

**Returns**

Returns the ID in bottom alignment parameters.


### OH_ArkUI_AlignmentRuleOption_GetCenterAlignmentHorizontal()

```
ArkUI_HorizontalAlignment OH_ArkUI_AlignmentRuleOption_GetCenterAlignmentHorizontal (ArkUI_AlignmentRuleOption * option)
```
**Description**

Obtains the alignment mode in horizontal center alignment parameters.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Pointer to an alignment rule configuration. |

**Returns**

Returns the alignment mode in horizontal center alignment parameters.

### OH_ArkUI_AlignmentRuleOption_GetCenterAlignmentVertical()

```
ArkUI_VerticalAlignment OH_ArkUI_AlignmentRuleOption_GetCenterAlignmentVertical (ArkUI_AlignmentRuleOption * option)
```
**Description**

Obtains the ID in vertical center alignment parameters.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Pointer to an alignment rule configuration. |

**Returns**

Returns the vertical center alignment parameters.


### OH_ArkUI_AlignmentRuleOption_GetCenterIdHorizontal()

```
const char* OH_ArkUI_AlignmentRuleOption_GetCenterIdHorizontal (ArkUI_AlignmentRuleOption * option)
```
**Description**

Obtains the ID in horizontal center alignment parameters.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Pointer to an alignment rule configuration. |

**Returns**

Returns the ID in horizontal center alignment parameters.


### OH_ArkUI_AlignmentRuleOption_GetCenterIdVertical()

```
const char* OH_ArkUI_AlignmentRuleOption_GetCenterIdVertical (ArkUI_AlignmentRuleOption * option)
```
**Description**

Obtains the ID in vertical center alignment parameters.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Pointer to an alignment rule configuration. |

**Returns**

Returns the ID in vertical center alignment parameters.


### OH_ArkUI_AlignmentRuleOption_GetEndAlignment()

```
ArkUI_HorizontalAlignment OH_ArkUI_AlignmentRuleOption_GetEndAlignment (ArkUI_AlignmentRuleOption * option)
```
**Description**

Obtains the alignment mode in the right alignment parameters.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Pointer to an alignment rule configuration. |

**Returns**

Returns the alignment mode in the right alignment parameters.


### OH_ArkUI_AlignmentRuleOption_GetEndId()

```
const char* OH_ArkUI_AlignmentRuleOption_GetEndId (ArkUI_AlignmentRuleOption * option)
```
**Description**

Obtains the alignment mode in the right alignment parameters.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Pointer to an alignment rule configuration. |

**Returns**

Returns the ID in the right alignment parameters.


### OH_ArkUI_AlignmentRuleOption_GetStartAlignment()

```
ArkUI_HorizontalAlignment OH_ArkUI_AlignmentRuleOption_GetStartAlignment (ArkUI_AlignmentRuleOption * option)
```
**Description**

Obtains the alignment mode in left alignment parameters.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Pointer to an alignment rule configuration. |

**Returns**

Returns the alignment mode in left alignment parameters.


### OH_ArkUI_AlignmentRuleOption_GetStartId()

```
const char* OH_ArkUI_AlignmentRuleOption_GetStartId (ArkUI_AlignmentRuleOption * option)
```
**Description**

Obtains the ID in the left alignment parameters.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Pointer to an alignment rule configuration. |

**Returns**

Returns the ID in left alignment parameters.


### OH_ArkUI_AlignmentRuleOption_GetTopAlignment()

```
ArkUI_VerticalAlignment OH_ArkUI_AlignmentRuleOption_GetTopAlignment (ArkUI_AlignmentRuleOption * option)
```
**Description**

Obtains the alignment mode in top alignment parameters.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Pointer to an alignment rule configuration. |

**Returns**

Returns the alignment mode in top alignment parameters.


### OH_ArkUI_AlignmentRuleOption_GetTopId()

```
const char* OH_ArkUI_AlignmentRuleOption_GetTopId (ArkUI_AlignmentRuleOption * option)
```
**Description**

Obtains the alignment mode in top alignment parameters.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Pointer to an alignment rule configuration. |

**Returns**

Returns the ID in top alignment parameters.


### OH_ArkUI_AlignmentRuleOption_SetBiasHorizontal()

```
void OH_ArkUI_AlignmentRuleOption_SetBiasHorizontal (ArkUI_AlignmentRuleOption * option, float horizontal )
```
**Description**

Sets the bias value of the component in the horizontal direction under the anchor constraints.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Pointer to an alignment rule configuration. |
| horizontal | Bias value in the horizontal direction. |


### OH_ArkUI_AlignmentRuleOption_SetBiasVertical()

```
void OH_ArkUI_AlignmentRuleOption_SetBiasVertical (ArkUI_AlignmentRuleOption * option, float vertical )
```
**Description**

Sets the bias value of the component in the vertical direction under the anchor constraints.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Pointer to an alignment rule configuration. |
| horizontal | Bias value in the vertical direction. |


### OH_ArkUI_AlignmentRuleOption_SetBottom()

```
void OH_ArkUI_AlignmentRuleOption_SetBottom (ArkUI_AlignmentRuleOption * option, const char * id, ArkUI_VerticalAlignment alignment )
```
**Description**

Sets the bottom alignment parameters.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Pointer to an alignment rule configuration. |
| id | ID of the anchor component. |
| value | Alignment mode relative to the anchor component. |


### OH_ArkUI_AlignmentRuleOption_SetCenterHorizontal()

```
void OH_ArkUI_AlignmentRuleOption_SetCenterHorizontal (ArkUI_AlignmentRuleOption * option, const char * id, ArkUI_HorizontalAlignment alignment )
```
**Description**

Sets the horizontal center alignment parameters.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Pointer to an alignment rule configuration. |
| id | ID of the anchor component. |
| value | Alignment mode relative to the anchor component. |


### OH_ArkUI_AlignmentRuleOption_SetCenterVertical()

```
void OH_ArkUI_AlignmentRuleOption_SetCenterVertical (ArkUI_AlignmentRuleOption * option, const char * id, ArkUI_VerticalAlignment alignment )
```
**Description**

Sets the vertical center alignment parameters.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Pointer to an alignment rule configuration. |
| id | ID of the anchor component. |
| value | Alignment mode relative to the anchor component. |


### OH_ArkUI_AlignmentRuleOption_SetEnd()

```
void OH_ArkUI_AlignmentRuleOption_SetEnd (ArkUI_AlignmentRuleOption * option, const char * id, ArkUI_HorizontalAlignment alignment )
```
**Description**

Sets the right alignment parameters.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Pointer to an alignment rule configuration. |
| id | ID of the anchor component. |
| value | Alignment mode relative to the anchor component. |


### OH_ArkUI_AlignmentRuleOption_SetStart()

```
void OH_ArkUI_AlignmentRuleOption_SetStart (ArkUI_AlignmentRuleOption * option, const char * id, ArkUI_HorizontalAlignment alignment )
```
**Description**

Sets the left alignment parameters.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Pointer to an alignment rule configuration. |
| id | ID of the anchor component. |
| value | Alignment mode relative to the anchor component. |


### OH_ArkUI_AlignmentRuleOption_SetTop()

```
void OH_ArkUI_AlignmentRuleOption_SetTop (ArkUI_AlignmentRuleOption * option, const char * id, ArkUI_VerticalAlignment alignment )
```
**Description**

Sets the top alignment parameters.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Pointer to an alignment rule configuration. |
| id | ID of the anchor component. |
| value | Alignment mode relative to the anchor component. |


### OH_ArkUI_AllowNodeAllDropDataTypes()

```
int32_t OH_ArkUI_AllowNodeAllDropDataTypes (ArkUI_NodeHandle node)
```
**Description**

Configures the specified component to allow any data types. This API resets the settings configured through [OH_ArkUI_SetNodeAllowedDropDataTypes](#oh_arkui_setnodealloweddropdatatypes).

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| node | Pointer to a component node. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs.


### OH_ArkUI_AnimateOption_Create()

```
ArkUI_AnimateOption* OH_ArkUI_AnimateOption_Create ()
```
**Description**

Creates an animation configuration.

**Since**: 12

**Returns**

Returns the pointer to the created animation configuration.


### OH_ArkUI_AnimateOption_Dispose()

```
void OH_ArkUI_AnimateOption_Dispose (ArkUI_AnimateOption * option)
```
**Description**

Disposes of an animation configuration.

**Since**: 12


### OH_ArkUI_AnimateOption_GetCurve()

```
ArkUI_AnimationCurve OH_ArkUI_AnimateOption_GetCurve (ArkUI_AnimateOption * option)
```
**Description**

Obtains an animation curve.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Pointer to an animation configuration. |

**Returns**

Returns the animation curve.


### OH_ArkUI_AnimateOption_GetDelay()

```
int32_t OH_ArkUI_AnimateOption_GetDelay (ArkUI_AnimateOption * option)
```
**Description**

Obtains the animation delay, in milliseconds.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Pointer to an animation configuration. |

**Returns**

Returns the animation delay.


### OH_ArkUI_AnimateOption_GetDuration()

```
int32_t OH_ArkUI_AnimateOption_GetDuration (ArkUI_AnimateOption * option)
```
**Description**

Obtains the animation duration, in milliseconds.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Pointer to an animation configuration. |

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

| Name| Description|
| -------- | -------- |
| option | Pointer to an animation configuration. |

**Returns**

Returns the expected frame rate range.


### OH_ArkUI_AnimateOption_GetICurve()

```
ArkUI_CurveHandle OH_ArkUI_AnimateOption_GetICurve (ArkUI_AnimateOption * option)
```
**Description**

Obtains the animation curve of an animation.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Pointer to an animation configuration. |

**Returns**

Returns the animation curve of the specified animation.


### OH_ArkUI_AnimateOption_GetIterations()

```
int32_t OH_ArkUI_AnimateOption_GetIterations (ArkUI_AnimateOption * option)
```
**Description**

Obtains the number of times that an animation is played.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Pointer to an animation configuration. |

**Returns**

Returns the number of times that the animation is played.


### OH_ArkUI_AnimateOption_GetPlayMode()

```
ArkUI_AnimationPlayMode OH_ArkUI_AnimateOption_GetPlayMode (ArkUI_AnimateOption * option)
```
**Description**

Obtains the playback mode of an animation.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Pointer to an animation configuration. |

**Returns**

Returns the animation playback mode.


### OH_ArkUI_AnimateOption_GetTempo()

```
float OH_ArkUI_AnimateOption_GetTempo (ArkUI_AnimateOption * option)
```
**Description**

Obtains the playback speed of an animation.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Pointer to an animation configuration. |

**Returns**

Animation playback speed.


### OH_ArkUI_AnimateOption_SetCurve()

```
void OH_ArkUI_AnimateOption_SetCurve (ArkUI_AnimateOption * option, ArkUI_AnimationCurve value )
```
**Description**

Sets the animation curve.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Pointer to an animation configuration. |
| value | Returns the animation curve. Default value: **ARKUI_CURVE_LINEAR**. |


### OH_ArkUI_AnimateOption_SetDelay()

```
void OH_ArkUI_AnimateOption_SetDelay (ArkUI_AnimateOption * option, int32_t value )
```
**Description**

Sets the animation delay.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Pointer to an animation configuration. |
| value | Delay of animation playback. |


### OH_ArkUI_AnimateOption_SetDuration()

```
void OH_ArkUI_AnimateOption_SetDuration (ArkUI_AnimateOption * option, int32_t value )
```
**Description**

Sets the animation duration.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Pointer to an animation configuration. |
| value | Duration, in milliseconds. |


### OH_ArkUI_AnimateOption_SetExpectedFrameRateRange()

```
void OH_ArkUI_AnimateOption_SetExpectedFrameRateRange (ArkUI_AnimateOption * option, ArkUI_ExpectedFrameRateRange * value )
```
**Description**

Sets the expected frame rate range of the animation.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Pointer to an animation configuration. |
| value | Expected frame rate range of the animation. |


### OH_ArkUI_AnimateOption_SetICurve()

```
void OH_ArkUI_AnimateOption_SetICurve (ArkUI_AnimateOption * option, ArkUI_CurveHandle value )
```
**Description**

Sets the animation curve for an animation.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Pointer to an animation configuration. |
| value | Animation curve settings. |

**NOTE**

This API is preferred over the value set by **OH_ArkUI_AnimateOption_SetCurve**.


### OH_ArkUI_AnimateOption_SetIterations()

```
void OH_ArkUI_AnimateOption_SetIterations (ArkUI_AnimateOption * option, int32_t value )
```
**Description**

Sets the number of times that an animation is played.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Pointer to an animation configuration. |
| value | Number of times that the animation is played. |


### OH_ArkUI_AnimateOption_SetPlayMode()

```
void OH_ArkUI_AnimateOption_SetPlayMode (ArkUI_AnimateOption * option, ArkUI_AnimationPlayMode value )
```
**Description**

Sets the playback mode for an animation.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Pointer to an animation configuration. |
| value | Animation playback mode. |


### OH_ArkUI_AnimateOption_SetTempo()

```
void OH_ArkUI_AnimateOption_SetTempo (ArkUI_AnimateOption * option, float value )
```
**Description**

Sets the playback speed of an animation.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Pointer to an animation configuration. |
| value | Animation playback speed. |


### OH_ArkUI_Animator_Cancel()

```
int32_t OH_ArkUI_Animator_Cancel (ArkUI_AnimatorHandle animator)
```
**Description**

Cancels the animation of an animator.

**Parameters**

| Name| Description|
| -------- | -------- |
| animator | Animator object. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs.


### OH_ArkUI_Animator_Finish()

```
int32_t OH_ArkUI_Animator_Finish (ArkUI_AnimatorHandle animator)
```
**Description**

Ends the animation of an animator.

**Parameters**

| Name| Description|
| -------- | -------- |
| animator | Animator object. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs.


### OH_ArkUI_Animator_Pause()

```
int32_t OH_ArkUI_Animator_Pause (ArkUI_AnimatorHandle animator)
```
**Description**

Pauses the animation of an animator.

**Parameters**

| Name| Description|
| -------- | -------- |
| animator | Animator object. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs.


### OH_ArkUI_Animator_Play()

```
int32_t OH_ArkUI_Animator_Play (ArkUI_AnimatorHandle animator)
```
**Description**

Starts the animation of an animator.

**Parameters**

| Name| Description|
| -------- | -------- |
| animator | Animator object. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs.


### OH_ArkUI_Animator_ResetAnimatorOption()

```
int32_t OH_ArkUI_Animator_ResetAnimatorOption (ArkUI_AnimatorHandle animator, ArkUI_AnimatorOption * option )
```
**Description**

Resets an animator configuration.

**Parameters**

| Name| Description|
| -------- | -------- |
| animator | Animator object. |
| option | Pointer to an animation configuration. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs.


### OH_ArkUI_Animator_Reverse()

```
int32_t OH_ArkUI_Animator_Reverse (ArkUI_AnimatorHandle animator)
```
**Description**

Plays the animation of an animator in reverse order.

**Parameters**

| Name| Description|
| -------- | -------- |
| animator | Animator object. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs.


### OH_ArkUI_AnimatorEvent_GetUserData()

```
void* OH_ArkUI_AnimatorEvent_GetUserData (ArkUI_AnimatorEvent * event)
```
**Description**

Obtains the custom object in an animation event object.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| event | Animation event object. |

**Returns**

Returns the custom object.


### OH_ArkUI_AnimatorOnFrameEvent_GetUserData()

```
void* OH_ArkUI_AnimatorOnFrameEvent_GetUserData (ArkUI_AnimatorOnFrameEvent * event)
```
**Description**

Obtains the custom object in an animation event object.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| event | Animation event object. |

**Returns**

Returns the custom object.


### OH_ArkUI_AnimatorOnFrameEvent_GetValue()

```
float OH_ArkUI_AnimatorOnFrameEvent_GetValue (ArkUI_AnimatorOnFrameEvent * event)
```
**Description**

Obtains the current progress in an animation event object.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| event | Animation event object. |

**Returns**

Returns the animation progress.


### OH_ArkUI_AnimatorOption_Create()

```
ArkUI_AnimatorOption* OH_ArkUI_AnimatorOption_Create (int32_t keyframeSize)
```
**Description**

Creates an animator parameter object.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| keyframeSize | Number of keyframes. |

**NOTE**

If the value of **keyframeSize** is greater than 0, the animation interpolation start point is 0, and the animation interpolation end point is 1; no setting is allowed.

**Returns**

Returns the pointer to the animator parameter object.


### OH_ArkUI_AnimatorOption_Dispose()

```
void OH_ArkUI_AnimatorOption_Dispose (ArkUI_AnimatorOption * option)
```
**Description**

Disposes of an **AnimatorOption** object.

**Since**: 12


### OH_ArkUI_AnimatorOption_GetBegin()

```
float OH_ArkUI_AnimatorOption_GetBegin (ArkUI_AnimatorOption * option)
```
**Description**

Obtains the interpolation start point of an animation.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Pointer to an animation configuration. |

**Returns**

Returns the start point of the animation interpolation.


### OH_ArkUI_AnimatorOption_GetCurve()

```
ArkUI_CurveHandle OH_ArkUI_AnimatorOption_GetCurve (ArkUI_AnimatorOption * option)
```
**Description**

Obtains the interpolation curve of the animation of an animator.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Pointer to an animation configuration. |

**Returns**

Returns the interpolation curve of the animation.


### OH_ArkUI_AnimatorOption_GetDelay()

```
int32_t OH_ArkUI_AnimatorOption_GetDelay (ArkUI_AnimatorOption * option)
```
**Description**

Obtains the delay for playing an animation.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Pointer to an animation configuration. |

**Returns**

Returns the delay for playing the animation, in milliseconds.


### OH_ArkUI_AnimatorOption_GetDirection()

```
ArkUI_AnimationDirection OH_ArkUI_AnimatorOption_GetDirection (ArkUI_AnimatorOption * option)
```
**Description**

Obtains the playback direction of an animation.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Pointer to an animation configuration. |

**Returns**

Returns the animation playback direction.


### OH_ArkUI_AnimatorOption_GetDuration()

```
int32_t OH_ArkUI_AnimatorOption_GetDuration (ArkUI_AnimatorOption * option)
```
**Description**

Obtains the duration for playing an animation.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Pointer to an animation configuration. |

**Returns**

Returns the duration for playing the animation, in milliseconds.


### OH_ArkUI_AnimatorOption_GetEnd()

```
float OH_ArkUI_AnimatorOption_GetEnd (ArkUI_AnimatorOption * option)
```
**Description**

Obtains the interpolation end point of an animation.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Pointer to an animation configuration. |

**Returns**

Returns the interpolation end point of the animation.


### OH_ArkUI_AnimatorOption_GetExpectedFrameRateRange()

```
ArkUI_ExpectedFrameRateRange* OH_ArkUI_AnimatorOption_GetExpectedFrameRateRange (ArkUI_AnimatorOption * option)
```
**Description**

Obtains the expected frame rate range of an animation.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Pointer to an animation configuration. |

**Returns**

Returns the pointer to the expected frame rate range object.


### OH_ArkUI_AnimatorOption_GetFill()

```
ArkUI_AnimationFill OH_ArkUI_AnimatorOption_GetFill (ArkUI_AnimatorOption * option)
```
**Description**

Obtains whether the animator animation is restored to the initial state after being executed.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Pointer to an animation configuration. |

**Returns**

Returns whether the animator animation is restored to the initial state after being executed.


### OH_ArkUI_AnimatorOption_GetIterations()

```
int32_t OH_ArkUI_AnimatorOption_GetIterations (ArkUI_AnimatorOption * option)
```
**Description**

Obtains the number of times that an animation is played.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Pointer to an **AnimatorOption** object. |

**Returns**

Number of times that the animation is played.

### OH_ArkUI_AnimatorOption_GetKeyframeCurve()

```
ArkUI_CurveHandle OH_ArkUI_AnimatorOption_GetKeyframeCurve (ArkUI_AnimatorOption * option, int32_t index )
```
**Description**

Obtains the interpolation curve for a keyframe in the animation of an animator.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Pointer to an **AnimatorOption** object. |
| index | Keyframe index. |

**Returns**

Returns the interpolation curve.


### OH_ArkUI_AnimatorOption_GetKeyframeTime()

```
float OH_ArkUI_AnimatorOption_GetKeyframeTime (ArkUI_AnimatorOption * option, int32_t index )
```
**Description**

Obtains the keyframe time of an animation.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Pointer to an **AnimatorOption** object. |
| index | Keyframe index. |

**Returns**

Keyframe time.


### OH_ArkUI_AnimatorOption_GetKeyframeValue()

```
float OH_ArkUI_AnimatorOption_GetKeyframeValue (ArkUI_AnimatorOption * option, int32_t index )
```
**Description**

Obtains the keyframe value of an animation.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Pointer to an **AnimatorOption** object. |
| index | Keyframe index. |

**Returns**

Keyframe value.


### OH_ArkUI_AnimatorOption_RegisterOnCancelCallback()

```
int32_t OH_ArkUI_AnimatorOption_RegisterOnCancelCallback (ArkUI_AnimatorOption * option, void * userData, void(*)(ArkUI_AnimatorEvent *event) callback )
```
**Description**

Sets the callback invoked when the animation playback is canceled.

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Pointer to an animation configuration. |
| userData | Custom parameter. |
| callback | Callback used to return the result. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs.


### OH_ArkUI_AnimatorOption_RegisterOnFinishCallback()

```
int32_t OH_ArkUI_AnimatorOption_RegisterOnFinishCallback (ArkUI_AnimatorOption * option, void * userData, void(*)(ArkUI_AnimatorEvent *event) callback )
```
**Description**

Sets the callback invoked when the animation playback is complete.

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Pointer to an animation configuration. |
| userData | Custom parameter. |
| callback | Callback used to return the result. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs.


### OH_ArkUI_AnimatorOption_RegisterOnFrameCallback()

```
int32_t OH_ArkUI_AnimatorOption_RegisterOnFrameCallback (ArkUI_AnimatorOption * option, void * userData, void(*)(ArkUI_AnimatorOnFrameEvent *event) callback )
```
**Description**

Sets the callback invoked when the animator receives a frame.

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Pointer to an animation configuration. |
| userData | Custom parameter. |
| callback | Callback used to return the result. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs.


### OH_ArkUI_AnimatorOption_RegisterOnRepeatCallback()

```
int32_t OH_ArkUI_AnimatorOption_RegisterOnRepeatCallback (ArkUI_AnimatorOption * option, void * userData, void(*)(ArkUI_AnimatorEvent *event) callback )
```
**Description**

Sets the callback invoked when the animation playback is repeated.

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Pointer to an animation configuration. |
| userData | Custom parameter. |
| callback | Callback used to return the result. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs.


### OH_ArkUI_AnimatorOption_SetBegin()

```
int32_t OH_ArkUI_AnimatorOption_SetBegin (ArkUI_AnimatorOption * option, float value )
```
**Description**

Sets the interpolation start point for the animation of an animator.

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Pointer to an **AnimatorOption** object. |
| value | Start point of the animation interpolation. |

**NOTE**

This API does not take effect when the animation is a keyframe animation.

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs.


### OH_ArkUI_AnimatorOption_SetCurve()

```
int32_t OH_ArkUI_AnimatorOption_SetCurve (ArkUI_AnimatorOption * option, ArkUI_CurveHandle value )
```
**Description**

Sets the interpolation curve for the animation of an animator.

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Pointer to an **AnimatorOption** object. |
| value | Returns the interpolation curve of the animation. Default value: **ARKUI_CURVE_LINEAR**. |

**NOTE**

The **springCurve**, **springMotion**, **responsiveSpringMotion**, and **interpolatingSpring customCurve** curves are not supported.

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs.


### OH_ArkUI_AnimatorOption_SetDelay()

```
int32_t OH_ArkUI_AnimatorOption_SetDelay (ArkUI_AnimatorOption * option, int32_t value )
```
**Description**

Sets the delay of animation playback, in milliseconds.

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Pointer to an **AnimatorOption** object. |
| value | Animation delay, in milliseconds. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs.


### OH_ArkUI_AnimatorOption_SetDirection()

```
int32_t OH_ArkUI_AnimatorOption_SetDirection (ArkUI_AnimatorOption * option, ArkUI_AnimationDirection value )
```
**Description**

Sets the playback direction.

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Pointer to an **AnimatorOption** object. |
| value | Animation playback direction. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs.


### OH_ArkUI_AnimatorOption_SetDuration()

```
int32_t OH_ArkUI_AnimatorOption_SetDuration (ArkUI_AnimatorOption * option, int32_t value )
```
**Description**

Sets the duration of an animation, in milliseconds.

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Pointer to an **AnimatorOption** object. |
| value | Duration for playing the animation, in milliseconds. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs.


### OH_ArkUI_AnimatorOption_SetEnd()

```
int32_t OH_ArkUI_AnimatorOption_SetEnd (ArkUI_AnimatorOption * option, float value )
```
**Description**

Sets the interpolation end point for the animation of an animator.

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Pointer to an **AnimatorOption** object. |
| value | End point of animation interpolation. |

**NOTE**

This API does not take effect when the animation is a keyframe animation.

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs.


### OH_ArkUI_AnimatorOption_SetExpectedFrameRateRange()

```
int32_t OH_ArkUI_AnimatorOption_SetExpectedFrameRateRange (ArkUI_AnimatorOption * option, ArkUI_ExpectedFrameRateRange * value )
```
**Description**

Sets the expected frame rate range of an animation.

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Pointer to an **AnimatorOption** object. |
| value | Expected frame rate range. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs.


### OH_ArkUI_AnimatorOption_SetFill()

```
int32_t OH_ArkUI_AnimatorOption_SetFill (ArkUI_AnimatorOption * option, ArkUI_AnimationFill value )
```
**Description**

Sets whether the animator animation is restored to the initial state after being executed.

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Pointer to an **AnimatorOption** object. |
| value | Whether to restore the animation to the initial state after the animation is executed. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs.


### OH_ArkUI_AnimatorOption_SetIterations()

```
int32_t OH_ArkUI_AnimatorOption_SetIterations (ArkUI_AnimatorOption * option, int32_t value )
```
**Description**

Sets the number of times that the frame animation is played. The value **0** means not to play the animation, and **-1** means to play the animation for an unlimited number of times.

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Pointer to an **AnimatorOption** object. |
| value | Number of times that the animation is played. |

**NOTE**

If this parameter is set to a negative value other than **-1**, the value is invalid. In this case, the animation is played once.

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs.


### OH_ArkUI_AnimatorOption_SetKeyframe()

```
int32_t OH_ArkUI_AnimatorOption_SetKeyframe (ArkUI_AnimatorOption * option, float time, float value, int32_t index )
```
**Description**

Sets the keyframe parameters of an animation.

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Pointer to an **AnimatorOption** object. |
| time | Keyframe time. Value range: [0, 1]. The value must be in ascending order. |
| value | Keyframe value. |
| index | Keyframe index. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs.


### OH_ArkUI_AnimatorOption_SetKeyframeCurve()

```
int32_t OH_ArkUI_AnimatorOption_SetKeyframeCurve (ArkUI_AnimatorOption * option, ArkUI_CurveHandle value, int32_t index )
```
**Description**

Sets the keyframe curve type for the animation of an animator.

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Pointer to an **AnimatorOption** object. |
| value | Animation interpolation curve. |
| index | Keyframe index. |

**NOTE**

The **springCurve**, **springMotion**, **responsiveSpringMotion**, and **interpolatingSpring customCurve** curves are not supported.

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs.


### OH_ArkUI_BarrierOption_Create()

```
ArkUI_BarrierOption* OH_ArkUI_BarrierOption_Create (int32_t size)
```
**Description**

Creates a barrier configuration for this **RelativeContainer** component.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| size | Number of barriers. |

**Returns**

Returns the barrier configuration.


### OH_ArkUI_BarrierOption_Dispose()

```
void OH_ArkUI_BarrierOption_Dispose (ArkUI_BarrierOption * barrierStyle)
```
**Description**

Disposes of a barrier configuration.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| barrierStyle | Pointer to a barrier configuration. |


### OH_ArkUI_BarrierOption_GetDirection()

```
ArkUI_BarrierDirection OH_ArkUI_BarrierOption_GetDirection (ArkUI_BarrierOption * barrierStyle, int32_t index )
```
**Description**

Obtains the direction of a barrier.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| barrierStyle | Pointer to a barrier configuration. |
| index | Index of the barrier. |

**Returns**

Returns the direction of the barrier.


### OH_ArkUI_BarrierOption_GetId()

```
const char* OH_ArkUI_BarrierOption_GetId (ArkUI_BarrierOption * barrierStyle, int32_t index )
```
**Description**

Obtains the ID of a barrier.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| barrierStyle | Pointer to a barrier configuration. |
| index | Index of the barrier. |

**Returns**

Returns the ID of the barrier.


### OH_ArkUI_BarrierOption_GetReferencedId()

```
const char* OH_ArkUI_BarrierOption_GetReferencedId (ArkUI_BarrierOption * barrierStyle, int32_t index, int32_t referencedIndex )
```
**Description**

Obtains the referenced components of a barrier.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| barrierStyle | Pointer to a barrier configuration. |
| index | Index of the barrier. |
| referencedIndex | Index of the referenced component ID. |

**Returns**

Returns the referenced components of the barrier.


### OH_ArkUI_BarrierOption_GetReferencedIdSize()

```
int32_t OH_ArkUI_BarrierOption_GetReferencedIdSize (ArkUI_BarrierOption * barrierStyle, int32_t index )
```
**Description**

Obtains the number of referenced components of a barrier.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| barrierStyle | Pointer to a barrier configuration. |
| index | Index of the barrier. |

**Returns**

Returns the number of referenced components of the barrier.


### OH_ArkUI_BarrierOption_SetDirection()

```
void OH_ArkUI_BarrierOption_SetDirection (ArkUI_BarrierOption * barrierStyle, ArkUI_BarrierDirection value, int32_t index )
```
**Description**

Sets the direction of a barrier.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| barrierStyle | Pointer to a barrier configuration. |
| value | Direction.  |
| index | Index of the barrier. |


### OH_ArkUI_BarrierOption_SetId()

```
void OH_ArkUI_BarrierOption_SetId (ArkUI_BarrierOption * barrierStyle, const char * value, int32_t index )
```
**Description**

Sets the ID of a barrier.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| barrierStyle | Pointer to a barrier configuration. |
| value | ID of the barrier, which must be unique and cannot be the same as the name of any component in the container. |
| index | Index of the barrier. |


### OH_ArkUI_BarrierOption_SetReferencedId()

```
void OH_ArkUI_BarrierOption_SetReferencedId (ArkUI_BarrierOption * barrierStyle, const char * value, int32_t index )
```
**Description**

Sets the referenced components of a barrier.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| barrierStyle | Pointer to a barrier configuration. |
| value | Referenced component IDs. |
| index | Index of the barrier. |


### OH_ArkUI_CreateAsymmetricTransitionEffect()

```
ArkUI_TransitionEffect* OH_ArkUI_CreateAsymmetricTransitionEffect (ArkUI_TransitionEffect * appear, ArkUI_TransitionEffect * disappear )
```
**Description**

Creates an asymmetric transition effect.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| appear | Transition effect for appearance. |
| disappear | Transition effect for disappearance. |

**NOTE**

If the **asymmetric** function is not used for constructing **TransitionEffect**, the transition effect takes effect for both appearance and disappearance of the component.

**Returns**

Returns the asymmetric transition effect; returns **NULL** if a parameter error occurs.


### OH_ArkUI_CreateDragActionWithContext()

```
ArkUI_DragAction* OH_ArkUI_CreateDragActionWithContext (ArkUI_ContextHandle uiContext)
```
**Description**

Creates a drag action object for the specified UI instance.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| uiContext | Pointer to the UI instance object. |

**Returns**

Returns the pointer to the created drag action object; returns null if the operation fails.


### OH_ArkUI_CreateDragActionWithNode()

```
ArkUI_DragAction* OH_ArkUI_CreateDragActionWithNode (ArkUI_NodeHandle node)
```
**Description**

Creates a drag action object. The object needs to be associated with a UI instance, which can be specified by passing in a component node of the current UI instance.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| node | Pointer to a component node. |

**Returns**

Returns the pointer to the created drag action object; returns null if the operation fails.


### OH_ArkUI_CreateDragPreviewOption()

```
ArkUI_DragPreviewOption* OH_ArkUI_CreateDragPreviewOption (void )
```
**Description**

Creates an **ArkUI_DragPreviewOption** object.

**Since**: 12

**Returns**

ArkUI_DragPreviewOption object.


### OH_ArkUI_CreateMovementTransitionEffect()

```
ArkUI_TransitionEffect* OH_ArkUI_CreateMovementTransitionEffect (ArkUI_TransitionEdge move)
```
**Description**

Creates a movement object for component transition.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| move | Panning type. |

**Returns**

Returns the movement object created for component transition; returns **NULL** if a parameter error occurs.


### OH_ArkUI_CreateOpacityTransitionEffect()

```
ArkUI_TransitionEffect* OH_ArkUI_CreateOpacityTransitionEffect (float opacity)
```
**Description**

Creates an opacity object for component transition.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| opacity | Opacity. The value range is [0, 1]. |

**NOTE**

If the value specified is less than 0, the value **0** is used. If the value specified is greater than 1, the value **1** is used.

**Returns**

Returns the created opacity object for component transition.


### OH_ArkUI_CreateRotationTransitionEffect()

```
ArkUI_TransitionEffect* OH_ArkUI_CreateRotationTransitionEffect (ArkUI_RotationOptions * rotate)
```
**Description**

Creates a rotation object for component transition.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| rotate | Rotation parameter object during component transition. |

**Returns**

Returns the rotation object created for component transition; returns **NULL** if a parameter error occurs.


### OH_ArkUI_CreateScaleTransitionEffect()

```
ArkUI_TransitionEffect* OH_ArkUI_CreateScaleTransitionEffect (ArkUI_ScaleOptions * scale)
```
**Description**

Creates a scaling transition effect object.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| scale | Scaling settings for component transition. |

**Returns**

Returns the created scaling transition effect object; returns **NULL** if a parameter error occurs.


### OH_ArkUI_CreateTranslationTransitionEffect()

```
ArkUI_TransitionEffect* OH_ArkUI_CreateTranslationTransitionEffect (ArkUI_TranslationOptions * translate)
```
**Description**

Creates a translation transition effect object.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| translate | Translation settings for component transition. |

**Returns**

Returns the created translation transition effect object; returns **NULL** if a parameter error occurs.


### OH_ArkUI_Curve_CreateCubicBezierCurve()

```
ArkUI_CurveHandle OH_ArkUI_Curve_CreateCubicBezierCurve (float x1, float y1, float x2, float y2 )
```
**Description**

Creates a cubic Bezier curve.

**Parameters**

| Name| Description|
| -------- | -------- |
| x1 | X coordinate of the first point on the Bezier curve. Value range: [0, 1]. A value less than 0 evaluates to the value **0**. A value greater than 1 evaluates to the value **1**. |
| y1 | Y coordinate of the first point on the Bezier curve. |
| x2 | X coordinate of the second point on the Bezier curve. Value range: [0, 1]. A value less than 0 evaluates to the value **0**. A value greater than 1 evaluates to the value **1**. |
| y2 | Y coordinate of the second point on the Bezier curve. |

**Returns**

Returns the pointer to the interpolation object of the curve; returns **NULL** if a parameter error occurs.


### OH_ArkUI_Curve_CreateCurveByType()

```
ArkUI_CurveHandle OH_ArkUI_Curve_CreateCurveByType (ArkUI_AnimationCurve curve)
```
**Description**

Implements initialization for the interpolation curve, which is used to create an interpolation curve based on the input parameter.

**Parameters**

| Name| Description|
| -------- | -------- |
| curve | Curve type. |

**Returns**

Returns the pointer to the interpolation object of the curve; returns **NULL** if a parameter error occurs.


### OH_ArkUI_Curve_CreateCustomCurve()

```
ArkUI_CurveHandle OH_ArkUI_Curve_CreateCustomCurve (void * userData, float(*)(float fraction, void *userdata) interpolate )
```
**Description**

Creates a custom curve.

**Parameters**

| Name| Description|
| -------- | -------- |
| userData | Custom data. |
| interpolate | Custom interpolation callback. **fraction** indicates the input x value for interpolation when the animation starts; value range: [0,1]. The return value is the **y** value of the curve; value range: [0,1]. If **fraction** is **0**, the return value **0** corresponds to the animation start point; any other return value means that the animation jumps at the start point. If **fraction** is **1**, the return value **1** corresponds to the animation end point; any other return value means that the end value of the animation is not the value of the state variable, which will result in an effect of transition from that end value to the value of the state variable. |

**Returns**

Returns the pointer to the interpolation object of the curve; returns **NULL** if a parameter error occurs.


### OH_ArkUI_Curve_CreateInterpolatingSpring()

```
ArkUI_CurveHandle OH_ArkUI_Curve_CreateInterpolatingSpring (float velocity, float mass, float stiffness, float damping )
```
**Description**

Creates an interpolating spring curve animated from 0 to 1. The actual animation value is calculated based on the curve.

**Parameters**

| Name| Description|
| -------- | -------- |
| velocity | Initial velocity. It is applied by external factors to the spring animation, designed to help ensure the smooth transition from the previous motion state. The velocity is the normalized velocity, and its value is equal to the actual velocity at the beginning of the animation divided by the animation attribute change value. |
| mass | Mass, which influences the inertia in the spring system. The greater the mass, the greater the amplitude of the oscillation, and the slower the speed of restoring to the equilibrium position. |
| stiffness | Stiffness. It is the degree to which an object deforms by resisting the force applied. In an elastic system, the greater the stiffness, the stronger the ability to resist deformation, and the faster the speed of restoring to the equilibrium position. |
| damping | Damping. It is used to describe the oscillation and attenuation of the system after being disturbed. The larger the damping, the smaller the number of oscillations of elastic motion, and the smaller the oscillation amplitude. |

**NOTE**

The animation duration is subject to the curve parameters, rather than the **duration** parameter in **animation** or **animateTo**.

**Returns**

Returns the pointer to the interpolation object of the curve; returns **NULL** if a parameter error occurs.


### OH_ArkUI_Curve_CreateResponsiveSpringMotion()

```
ArkUI_CurveHandle OH_ArkUI_Curve_CreateResponsiveSpringMotion (float response, float dampingFraction, float overlapDuration )
```
**Description**

Creates a responsive spring animation curve. It is a special case of **springMotion**, with the only difference in the default values. It can be used together with **springMotion**.

**Parameters**

| Name| Description|
| -------- | -------- |
| response | Duration of one complete oscillation. |
| dampingFraction | Damping coefficient. If the value is greater than 0 and less than 1, the value is underdamped and exceeds the target value during motion. If the value is equal to 1, the value is critical damping. If the value is greater than 1, the value is overdamped and gradually approaches the target value during motion. |
| overlapDuration | Duration for animations to overlap, in seconds. When animations overlap, the **response** values of these animations will transit smoothly over this duration if they are different. |

**NOTE**

The animation duration is subject to the curve parameters, rather than the **duration** parameter in **animation** or **animateTo**.

**Returns**

Returns the pointer to the interpolation object of the curve; returns **NULL** if a parameter error occurs.


### OH_ArkUI_Curve_CreateSpringCurve()

```
ArkUI_CurveHandle OH_ArkUI_Curve_CreateSpringCurve (float velocity, float mass, float stiffness, float damping )
```
**Description**

Creates a spring curve. The curve shape is subject to the spring parameters, and the animation duration is subject to the **duration** parameter in **animation** and **animateTo**.

**Parameters**

| Name| Description|
| -------- | -------- |
| velocity | Initial velocity. It is applied by external factors to the spring animation, designed to help ensure the smooth transition from the previous motion state. The velocity is the normalized velocity, and its value is equal to the actual velocity at the beginning of the animation divided by the animation attribute change value. |
| mass | Mass, which influences the inertia in the spring system. The greater the mass, the greater the amplitude of the oscillation, and the slower the speed of restoring to the equilibrium position. |
| stiffness | Stiffness. It is the degree to which an object deforms by resisting the force applied. In an elastic system, the greater the stiffness, the stronger the ability to resist deformation, and the faster the speed of restoring to the equilibrium position. |
| damping | Damping. It is used to describe the oscillation and attenuation of the system after being disturbed. The larger the damping, the smaller the number of oscillations of elastic motion, and the smaller the oscillation amplitude. |

**Returns**

Returns the pointer to the interpolation object of the curve; returns **NULL** if a parameter error occurs.


### OH_ArkUI_Curve_CreateSpringMotion()

```
ArkUI_CurveHandle OH_ArkUI_Curve_CreateSpringMotion (float response, float dampingFraction, float overlapDuration )
```
**Description**

Creates a spring animation curve. If multiple spring animations are applied to the same attribute of an object, each animation replaces their predecessor and inherits the velocity.

**Parameters**

| Name| Description|
| -------- | -------- |
| response | Duration of one complete oscillation. |
| dampingFraction | Damping coefficient. If the value is greater than 0 and less than 1, the value is underdamped and exceeds the target value during motion. If the value is equal to 1, the value is critical damping. If the value is greater than 1, the value is overdamped and gradually approaches the target value during motion. |
| overlapDuration | Duration for animations to overlap, in seconds. When animations overlap, the **response** values of these animations will transit smoothly over this duration if they are different. |

**NOTE**

The animation duration is subject to the curve parameters, rather than the **duration** parameter in **animation** or **animateTo**.

**Returns**

Returns the pointer to the interpolation object of the curve; returns **NULL** if a parameter error occurs.


### OH_ArkUI_Curve_CreateStepsCurve()

```
ArkUI_CurveHandle OH_ArkUI_Curve_CreateStepsCurve (int32_t count, bool end )
```
**Description**

Creates a step curve.

**Parameters**

| Name| Description|
| -------- | -------- |
| count | Number of tiers. The value must be a positive integer. Value range: [1, +∞). |
| end | Step change occurs at the start point or end point of each interval. true: Step change occurs at the end point. false: Step change occurs at the start point. |

**Returns**

Returns the pointer to the interpolation object of the curve; returns **NULL** if a parameter error occurs.


### OH_ArkUI_Curve_DisposeCurve()

```
void OH_ArkUI_Curve_DisposeCurve (ArkUI_CurveHandle curveHandle)
```
**Description**

Disposes of a custom curve.

**Parameters**

| Name| Description|
| -------- | -------- |
| curve | Returns the pointer to the interpolation object of the curve; |


### OH_ArkUI_CustomSpanDrawInfo_Create()

```
ArkUI_CustomSpanDrawInfo* OH_ArkUI_CustomSpanDrawInfo_Create (void )
```
**Description**

Creates drawing information for this custom span.

**Since**: 12

**Returns**

Returns a **CustomSpanDrawInfo** instance. If a null pointer is returned, the memory may be insufficient.


### OH_ArkUI_CustomSpanDrawInfo_Dispose()

```
void OH_ArkUI_CustomSpanDrawInfo_Dispose (ArkUI_CustomSpanDrawInfo * info)
```
**Description**

Disposes of drawing information for this custom span.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| info | Pointer to the drawing information of a custom span. |


### OH_ArkUI_CustomSpanDrawInfo_GetBaseline()

```
float OH_ArkUI_CustomSpanDrawInfo_GetBaseline (ArkUI_CustomSpanDrawInfo * info)
```
**Description**

Obtains the baseline offset of the custom span relative to the mounted component.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| info | Pointer to the drawing information of a custom span. |

**Returns**

Returns the baseline offset. If a parameter error occurs, **0.0f** is returned. A possible cause is that mandatory parameters are left unspecified.


### OH_ArkUI_CustomSpanDrawInfo_GetLineBottom()

```
float OH_ArkUI_CustomSpanDrawInfo_GetLineBottom (ArkUI_CustomSpanDrawInfo * info)
```
**Description**

Obtains the bottom margin of the custom span relative to the mounted component.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| info | Pointer to the drawing information of a custom span. |

**Returns**

Returns the bottom margin. If a parameter error occurs, **0.0f** is returned. A possible cause is that mandatory parameters are left unspecified.


### OH_ArkUI_CustomSpanDrawInfo_GetLineTop()

```
float OH_ArkUI_CustomSpanDrawInfo_GetLineTop (ArkUI_CustomSpanDrawInfo * info)
```
**Description**

Obtains the top margin of the custom span relative to the mounted component.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| info | Pointer to the drawing information of a custom span. |

**Returns**

Returns the top margin. If a parameter error occurs, **0.0f** is returned. A possible cause is that mandatory parameters are left unspecified.


### OH_ArkUI_CustomSpanDrawInfo_GetXOffset()

```
float OH_ArkUI_CustomSpanDrawInfo_GetXOffset (ArkUI_CustomSpanDrawInfo * info)
```
**Description**

Obtains the x-axis offset of the custom span relative to the mounted component.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| info | Pointer to the drawing information of a custom span. |

**Returns**

Returns the x-axis offset. If a parameter error occurs, **0.0f** is returned. A possible cause is that mandatory parameters are left unspecified.


### OH_ArkUI_CustomSpanMeasureInfo_Create()

```
ArkUI_CustomSpanMeasureInfo* OH_ArkUI_CustomSpanMeasureInfo_Create (void )
```
**Description**

Creates measurement information for this custom span.

**Since**: 12

**Returns**

Returns a **CustomSpanMeasureInfo** instance. If a null pointer is returned, the memory may be insufficient.


### OH_ArkUI_CustomSpanMeasureInfo_Dispose()

```
void OH_ArkUI_CustomSpanMeasureInfo_Dispose (ArkUI_CustomSpanMeasureInfo * info)
```
**Description**

Disposes of measurement information of a custom span.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| info | Pointer to the measurement information of a custom span. |


### OH_ArkUI_CustomSpanMeasureInfo_GetFontSize()

```
float OH_ArkUI_CustomSpanMeasureInfo_GetFontSize (ArkUI_CustomSpanMeasureInfo * info)
```
**Description**

Obtains the font size of the parent text node of a custom span.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| info | Pointer to the measurement information of a custom span. |

**Returns**

Returns the font size of the parent text node. If a parameter error occurs, **0.0f** is returned. A possible cause is that mandatory parameters are left unspecified.


### OH_ArkUI_CustomSpanMetrics_Create()

```
ArkUI_CustomSpanMetrics* OH_ArkUI_CustomSpanMetrics_Create (void )
```
**Description**

Creates measurement metrics for this custom span.

**Since**: 12

**Returns**

Returns a **CustomSpanMetrics** instance. If a null pointer is returned, the memory may be insufficient.


### OH_ArkUI_CustomSpanMetrics_Dispose()

```
void OH_ArkUI_CustomSpanMetrics_Dispose (ArkUI_CustomSpanMetrics * metrics)
```
**Description**

Disposes of measurement metrics of this custom span.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| metrics | Returns a **CustomSpanMetrics** instance. |


### OH_ArkUI_CustomSpanMetrics_SetHeight()

```
int32_t OH_ArkUI_CustomSpanMetrics_SetHeight (ArkUI_CustomSpanMetrics * metrics, float height )
```
**Description**

Sets the height for a custom span.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| metrics | Returns a **CustomSpanMetrics** instance. |
| height | Height, in vp. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs. A possible cause is that mandatory parameters are left unspecified.


### OH_ArkUI_CustomSpanMetrics_SetWidth()

```
int32_t OH_ArkUI_CustomSpanMetrics_SetWidth (ArkUI_CustomSpanMetrics * metrics, float width )
```
**Description**

Sets the width for a custom span.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| metrics | Returns a **CustomSpanMetrics** instance. |
| width | Width, in vp. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs. A possible cause is that mandatory parameters are left unspecified.


### OH_ArkUI_DialogDismissEvent_GetDismissReason()

```
int32_t OH_ArkUI_DialogDismissEvent_GetDismissReason (ArkUI_DialogDismissEvent * event)
```
**Description**

Obtains the dismissal reason from a dialog box dismiss event object.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| event | Pointer to a dialog box dismiss event object.|

**Returns**

Returns the dismissal reason. Returns **-1** if an exception occurs.<br> **DIALOG_DISMISS_BACK_PRESS**: touching the Back button, swiping left or right on the screen, or pressing the Esc key.<br> **DIALOG_DISMISS_TOUCH_OUTSIDE**: touching the mask.<br> **DIALOG_DISMISS_CLOSE_BUTTON**: touching the Close button.<br> **DIALOG_DISMISS_SLIDE_DOWN**: sliding down.

### OH_ArkUI_DialogDismissEvent_GetUserData()

```
void* OH_ArkUI_DialogDismissEvent_GetUserData (ArkUI_DialogDismissEvent * event)
```
**Description**

Obtains the pointer to user data in a dialog box dismiss event object.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| event | Pointer to a dialog box dismiss event object.|

**Returns**

Returns the pointer to user data.


### OH_ArkUI_DialogDismissEvent_SetShouldBlockDismiss()

```
void OH_ArkUI_DialogDismissEvent_SetShouldBlockDismiss (ArkUI_DialogDismissEvent * event, bool shouldBlockDismiss )
```
**Description**

Sets whether to block the system behavior of dismissing a dialog box.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| event | Pointer to a dialog box dismiss event object. |
| shouldBlockDismiss | Whether to block the system behavior of dismissing the dialog box. The value **true** means to block the system behavior, and **false** means the opposite. |


### OH_ArkUI_DisallowNodeAnyDropDataTypes()

```
int32_t OH_ArkUI_DisallowNodeAnyDropDataTypes (ArkUI_NodeHandle node)
```
**Description**

The configuration component is not allowed to accept any data type. This interface resets the data type configured through [OH_ArkUI_SetNodeAllowedDropDataTypes](#oh_arkui_setnodealloweddropdatatypes).

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| node | Pointer to a component node. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs.


### OH_ArkUI_DragAction_Dispose()

```
void OH_ArkUI_DragAction_Dispose (ArkUI_DragAction * dragAction)
```
**Description**

Disposes of an **ArkUI_DragAction** object.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| dragAction | Pointer to the target drag action object. |


### OH_ArkUI_DragAction_RegisterStatusListener()

```
int32_t OH_ArkUI_DragAction_RegisterStatusListener (ArkUI_DragAction * dragAction, void * userData, void(*)(ArkUI_DragAndDropInfo *dragAndDropInfo, void *userData) listener )
```
**Description**

Registers a drag status listener. This listener can be used to check whether the data is successfully received and processed.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| dragAction | Pointer to the target drag action object. |
| userData | Custom user data. |
| listener | Listener to register. When the callback is invoked, the system returns a pointer to the drag status object. The pointer is destroyed after the callback is complete and the application should not hold it anymore. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs.


### OH_ArkUI_DragAction_SetData()

```
int32_t OH_ArkUI_DragAction_SetData (ArkUI_DragAction * dragAction, OH_UdmfData * data )
```
**Description**

Sets the drag data.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| dragAction | Pointer to the target drag action object. |
| data | Drag data. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs.


### OH_ArkUI_DragAction_SetDragPreviewOption()

```
int32_t OH_ArkUI_DragAction_SetDragPreviewOption (ArkUI_DragAction * dragAction, ArkUI_DragPreviewOption * option )
```
**Description**

Sets an **ArkUI_DragPreviewOption** object for the specified drag action object.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| dragAction | Pointer to the target drag action object. |
| option | Custom parameters. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs.


### OH_ArkUI_DragAction_SetPixelMaps()

```
int32_t OH_ArkUI_DragAction_SetPixelMaps (ArkUI_DragAction * dragAction, OH_PixelmapNative * pixelmapArray[], int32_t size )
```
**Description**

Sets the drag previews for a drag action.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| dragAction | Pointer to the target drag action object. |
| pixelmapArray | Drag the bitmap array of the follower map. |
| size | Number of drag-and-drop images. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs.


### OH_ArkUI_DragAction_SetPointerId()

```
int32_t OH_ArkUI_DragAction_SetPointerId (ArkUI_DragAction * dragAction, int32_t pointer )
```
**Description**

Sets the pointer ID. If only one finger is operating on the screen, the pointer ID is 0. In general cases, you can set the pointer ID to 0.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| dragAction | Pointer to the target drag action object. |
| pointer | Pointer ID. The value ranges from 0 to 9. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs.


### OH_ArkUI_DragAction_SetTouchPointX()

```
int32_t OH_ArkUI_DragAction_SetTouchPointX (ArkUI_DragAction * dragAction, float x )
```
**Description**

Sets the touch point relative to the upper left corner of the first drag preview (pixel map).

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| dragAction | Pointer to the target drag action object. |
| x | X value of the hand point coordinate. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs.


### OH_ArkUI_DragAction_SetTouchPointY()

```
int32_t OH_ArkUI_DragAction_SetTouchPointY (ArkUI_DragAction * dragAction, float y )
```
**Description**

Sets the touch point relative to the upper left corner of the first drag preview (pixel map).

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| dragAction | Pointer to the target drag action object. |
| y | Y value of the hand point coordinate. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs.


### OH_ArkUI_DragAction_UnregisterStatusListener()

```
void OH_ArkUI_DragAction_UnregisterStatusListener (ArkUI_DragAction * dragAction)
```
**Description**

Unregisters a drag status listener.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| dragAction | Pointer to the target drag action object. |


### OH_ArkUI_DragAndDropInfo_GetDragEvent()

```
ArkUI_DragEvent* OH_ArkUI_DragAndDropInfo_GetDragEvent (ArkUI_DragAndDropInfo * dragAndDropInfo)
```
**Description**

Obtains a drag event based on the specified drag and drop information. The drag event can then be used to obtain the drag result.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| dragAndDropInfo | Drag-related information returned by the drag status listener. |

**Returns**

Returns an **ArkUI_DragEvent** object; returns null if an error occurs. 


### OH_ArkUI_DragAndDropInfo_GetDragStatus()

```
ArkUI_DragStatus OH_ArkUI_DragAndDropInfo_GetDragStatus (ArkUI_DragAndDropInfo * dragAndDropInfo)
```
**Description**

Obtains the drag status of a drag action.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| dragAndDropInfo | Drag-related information returned by the drag status listener. |

**Returns**

Returns an **ArkUI_DragStatus** object; returns **ArkUI_DRAG_STATUS_UNKNOWN** if an error occurs.


### OH_ArkUI_DragEvent_DisableDefaultDropAnimation()

```
int32_t OH_ArkUI_DragEvent_DisableDefaultDropAnimation (ArkUI_DragEvent * event, bool disable )
```
**Description**

Sets whether to disable the default drop animation, which is enabled by default. Use this API to apply a custom drop animation.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| event | Pointer to an **ArkUI_DragEvent** object. |
| disable | Whether to disable the default drop animation. The value **true** means to disable the default drop animation, and **false** means the opposite. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs.


### OH_ArkUI_DragEvent_GetDataTypes()

```
int32_t OH_ArkUI_DragEvent_GetDataTypes (ArkUI_DragEvent * event, char ** result[], int32_t length )
```
**Description**

Obtains the type list of drag data types from a drag event.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| event | Pointer to an **ArkUI_DragEvent** object. |
| char | \*\*result[] Returns the type list of the dragged data. You need to create a string array first. |
| length | The total length of the array must be greater than or equal to the number obtained by using [OH_ArkUI_DragEvent_GetDataTypesCount](#oh_arkui_dragevent_getdatatypescount). |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs.


### OH_ArkUI_DragEvent_GetDataTypesCount()

```
int32_t OH_ArkUI_DragEvent_GetDataTypesCount (ArkUI_DragEvent * event, int32_t * count )
```
**Description**

Obtains the number of drag data types from a drag event.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| event | Pointer to an **ArkUI_DragEvent** object. |
| count | Output parameter, which returns the number of types of dragged data. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs.


### OH_ArkUI_DragEvent_GetDragResult()

```
int32_t OH_ArkUI_DragEvent_GetDragResult (ArkUI_DragEvent * event, ArkUI_DragResult * result )
```
**Description**

Obtains the drag and drop result from the drag event.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| event | Pointer to an **ArkUI_DragEvent** object. |
| result | Output parameter, which returns the drag result corresponding to the drag event. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs.


### OH_ArkUI_DragEvent_GetModifierKeyStates()

```
int32_t OH_ArkUI_DragEvent_GetModifierKeyStates (ArkUI_DragEvent * event, int64_t * keys )
```
**Description**

Obtains the pressed status of modifier keys from a drag event.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| event | Pointer to an **ArkUI_DragEvent** object. |
| keys | Returns the modifier key combination that is currently pressed. The application can determine the modifier key combination through bitwise operations. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs.


### OH_ArkUI_DragEvent_GetPreviewRectHeight()

```
float OH_ArkUI_DragEvent_GetPreviewRectHeight (ArkUI_DragEvent * event)
```
**Description**

Obtains the height of a drag preview from a drag event.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| event | Pointer to an **ArkUI_DragEvent** object. |

**Returns**

Returns the height of the drag preview, in px; returns the default value **0** if the input parameter is invalid.


### OH_ArkUI_DragEvent_GetPreviewRectWidth()

```
float OH_ArkUI_DragEvent_GetPreviewRectWidth (ArkUI_DragEvent * event)
```
**Description**

Obtains the width of a drag preview from a drag event.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| event | Pointer to an **ArkUI_DragEvent** object. |

**Returns**

Returns the width of the drag preview, in px; returns the default value **0** if the input parameter is invalid.


### OH_ArkUI_DragEvent_GetPreviewTouchPointX()

```
float OH_ArkUI_DragEvent_GetPreviewTouchPointX (ArkUI_DragEvent * event)
```
**Description**

Obtains the X coordinate of the touch point for a drag preview from a drag event.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| event | Pointer to an **ArkUI_DragEvent** object. |

**Returns**

Returns the X coordinate of the touch point, in px; returns the default value **0** if the input parameter is invalid.


### OH_ArkUI_DragEvent_GetPreviewTouchPointY()

```
float OH_ArkUI_DragEvent_GetPreviewTouchPointY (ArkUI_DragEvent * event)
```
**Description**

Obtains the Y coordinate of the touch point for a drag preview from a drag event.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| event | ArkUI_DragEvent event pointer. The unit is PX. If the input parameter is invalid, the default value 0 is returned. |

**Returns**

float returns the y-axis coordinate of the drag and hand point.


### OH_ArkUI_DragEvent_GetTouchPointXToDisplay()

```
float OH_ArkUI_DragEvent_GetTouchPointXToDisplay (ArkUI_DragEvent * event)
```
**Description**

Obtains the X coordinate of the touch point relative to the display from a drag event.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| event | Pointer to an **ArkUI_DragEvent** object. |

**Returns**

Returns the X coordinate of the touch point relative to the display, in px; returns the default value **0** if the input parameter is invalid.


### OH_ArkUI_DragEvent_GetTouchPointXToWindow()

```
float OH_ArkUI_DragEvent_GetTouchPointXToWindow (ArkUI_DragEvent * event)
```
**Description**

Obtains the X coordinate of the touch point relative to the window from a drag event.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| event | Pointer to an **ArkUI_DragEvent** object. |

**Returns**

Returns the X coordinate of the touch point relative to the window, in px; returns the default value **0** if the input parameter is invalid.


### OH_ArkUI_DragEvent_GetTouchPointYToDisplay()

```
float OH_ArkUI_DragEvent_GetTouchPointYToDisplay (ArkUI_DragEvent * event)
```
**Description**

Obtains the Y coordinate of the touch point relative to the display from a drag event.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| event | Pointer to an **ArkUI_DragEvent** object. |

**Returns**

Returns the Y coordinate of the touch point relative to the display, in px; returns the default value **0** if the input parameter is invalid.


### OH_ArkUI_DragEvent_GetTouchPointYToWindow()

```
float OH_ArkUI_DragEvent_GetTouchPointYToWindow (ArkUI_DragEvent * event)
```
**Description**

Obtains the Y coordinate of the touch point relative to the window from a drag event.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| event | Pointer to an **ArkUI_DragEvent** object. |

**Returns**

Returns the Y coordinate of the touch point relative to the window, in px; returns the default value **0** if the input parameter is invalid.


### OH_ArkUI_DragEvent_GetUdmfData()

```
int32_t OH_ArkUI_DragEvent_GetUdmfData (ArkUI_DragEvent * event, OH_UdmfData * data )
```
**Description**

Obtain the default drag-and-drop data from ArkUI_DragEvent.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| event | Pointer to an **ArkUI_DragEvent** object. |
| data | Pointer to the dragged data of OH_UdmfData. When receiving data, the application needs to create a pointer for receiving data by using the OH_UdmfData_Create method. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs.


### OH_ArkUI_DragEvent_GetVelocity()

```
float OH_ArkUI_DragEvent_GetVelocity (ArkUI_DragEvent * event)
```
**Description**

Obtains the dragging velocity along the main axis.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| event | Pointer to an **ArkUI_DragEvent** object. |

**Returns**

Returns the dragging velocity along the main axis, in px; returns the default value **0** if the input parameter is invalid.


### OH_ArkUI_DragEvent_GetVelocityX()

```
float OH_ArkUI_DragEvent_GetVelocityX (ArkUI_DragEvent * event)
```
**Description**

Obtains the dragging velocity along the x-axis.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| event | Pointer to an **ArkUI_DragEvent** object. |

**Returns**

Returns the dragging velocity along the x-axis, in px; returns the default value **0** if the input parameter is invalid.


### OH_ArkUI_DragEvent_GetVelocityY()

```
float OH_ArkUI_DragEvent_GetVelocityY (ArkUI_DragEvent * event)
```
**Description**

Obtains the dragging velocity along the y-axis.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| event | Pointer to an **ArkUI_DragEvent** object. |

**Returns**

Returns the dragging velocity along the y-axis, in px; returns the default value **0** if the input parameter is invalid.


### OH_ArkUI_DragEvent_SetData()

```
int32_t OH_ArkUI_DragEvent_SetData (ArkUI_DragEvent * event, OH_UdmfData * data )
```
**Description**

Sets drag data for a drag event.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| event | Pointer to an **ArkUI_DragEvent** object. |
| data | Drag data. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs.


### OH_ArkUI_DragEvent_SetDragResult()

```
int32_t OH_ArkUI_DragEvent_SetDragResult (ArkUI_DragEvent * event, ArkUI_DragResult result )
```
**Description**

Sets the result for a drag event.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| event | Pointer to an **ArkUI_DragEvent** object. |
| result | Drag the data processing result. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs.


### OH_ArkUI_DragEvent_SetSuggestedDropOperation()

```
int32_t OH_ArkUI_DragEvent_SetSuggestedDropOperation (ArkUI_DragEvent * event, ArkUI_DropProposal proposal )
```
**Description**

Sets the data processing mode.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| proposal | Recommended data processing mode |
| proposal | Type of the badge display status. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs.


### OH_ArkUI_DragPreviewOption_Dispose()

```
void OH_ArkUI_DragPreviewOption_Dispose (ArkUI_DragPreviewOption * option)
```
**Description**

Disposes of an **ArkUI_DragPreviewOption** object.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Custom parameters. |


### OH_ArkUI_DragPreviewOption_SetBadgeNumber()

```
int32_t OH_ArkUI_DragPreviewOption_SetBadgeNumber (ArkUI_DragPreviewOption * option, uint32_t forcedNumber )
```
**Description**

Sets the count on the badge. The settings will overwrite the value in the **SetDragPreviewNumberBadgeEnabled** API.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Custom parameters. |
| forcedNumber | Number of corner marks. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs.


### OH_ArkUI_DragPreviewOption_SetDefaultAnimationBeforeLiftingEnabled()

```
int32_t OH_ArkUI_DragPreviewOption_SetDefaultAnimationBeforeLiftingEnabled (ArkUI_DragPreviewOption * option, bool enabled )
```
**Description**

Sets whether to enable the default animation on a click or touch.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Custom parameters. |
| enabled | Whether to enable the default click effect. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs.


### OH_ArkUI_DragPreviewOption_SetDefaultRadiusEnabled()

```
int32_t OH_ArkUI_DragPreviewOption_SetDefaultRadiusEnabled (ArkUI_DragPreviewOption * option, bool enabled )
```
**Description**

Sets whether to enable the default corner radius effect for an **ArkUI_DragPreviewOption** object. The effect is enabled by default.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Custom parameters. |
| enabled | Whether to enable the default corner radius effect. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs.


### OH_ArkUI_DragPreviewOption_SetDefaultShadowEnabled()

```
int32_t OH_ArkUI_DragPreviewOption_SetDefaultShadowEnabled (ArkUI_DragPreviewOption * option, bool enabled )
```
**Description**

Sets whether to enable the default shadow effect for an **ArkUI_DragPreviewOption** object. The effect is enabled by default.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Custom parameters. |
| enabled | Whether to enable the default shadow effect. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs.


### OH_ArkUI_DragPreviewOption_SetNumberBadgeEnabled()

```
int32_t OH_ArkUI_DragPreviewOption_SetNumberBadgeEnabled (ArkUI_DragPreviewOption * option, bool enabled )
```
**Description**

Sets whether to enable the badge for an **ArkUI_DragPreviewOption** object. If this feature is enabled, a badge that contains the number of dragged items is displayed.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Custom parameters. |
| enabled | Whether to enable the badge. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs.


### OH_ArkUI_DragPreviewOption_SetScaleMode()

```
int32_t OH_ArkUI_DragPreviewOption_SetScaleMode (ArkUI_DragPreviewOption * option, ArkUI_DragPreviewScaleMode scaleMode )
```
**Description**

Sets the scale mode for an **ArkUI_DragPreviewOption** object.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Custom parameters. |
| scaleMode | Scale mode to set. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs.


### OH_ArkUI_DrawableDescriptor_CreateFromAnimatedPixelMap()

```
ArkUI_DrawableDescriptor* OH_ArkUI_DrawableDescriptor_CreateFromAnimatedPixelMap (OH_PixelmapNativeHandle * array, int32_t size )
```
**Description**

Creates a **DrawableDescriptor** object from an array of **PixelMap** objects.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| array | Pointer to the array of **PixelMap** objects. |
| size | Size of the **PixelMap** object array. |

**Returns**

Returns the pointer to the created **DrawableDescriptor** object.


### OH_ArkUI_DrawableDescriptor_CreateFromPixelMap()

```
ArkUI_DrawableDescriptor* OH_ArkUI_DrawableDescriptor_CreateFromPixelMap (OH_PixelmapNativeHandle pixelMap)
```
**Description**

Creates a **DrawableDescriptor** object from a **PixelMap** object.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| pixelMap | Pointer to the **PixelMap** object. |

**Returns**

Returns the pointer to the created **DrawableDescriptor** object.


### OH_ArkUI_DrawableDescriptor_Dispose()

```
void OH_ArkUI_DrawableDescriptor_Dispose (ArkUI_DrawableDescriptor * drawableDescriptor)
```
**Description**

Disposes of the pointer to a **DrawableDescriptor** object.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| drawableDescriptor | Pointer to the **DrawableDescriptor** object. |


### OH_ArkUI_DrawableDescriptor_GetAnimatedPixelMapArray()

```
OH_PixelmapNativeHandle* OH_ArkUI_DrawableDescriptor_GetAnimatedPixelMapArray (ArkUI_DrawableDescriptor * drawableDescriptor)
```
**Description**

Obtains an array of **PixelMap** objects for playing an animation.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| drawableDescriptor | Pointer to a **DrawableDescriptor** object. |

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

| Name| Description|
| -------- | -------- |
| drawableDescriptor | Pointer to a **DrawableDescriptor** object. |

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

| Name| Description|
| -------- | -------- |
| drawableDescriptor | Pointer to a **DrawableDescriptor** object. |

**Returns**

Total playback duration, in milliseconds.


### OH_ArkUI_DrawableDescriptor_GetAnimationIteration()

```
int32_t OH_ArkUI_DrawableDescriptor_GetAnimationIteration (ArkUI_DrawableDescriptor * drawableDescriptor)
```
**Description**

Obtains the number of times that a **PixelMap** object array is played.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| drawableDescriptor | Pointer to a **DrawableDescriptor** object. |

**Returns**

Returns the number of playback times.


### OH_ArkUI_DrawableDescriptor_GetStaticPixelMap()

```
OH_PixelmapNativeHandle OH_ArkUI_DrawableDescriptor_GetStaticPixelMap (ArkUI_DrawableDescriptor * drawableDescriptor)
```
**Description**

Obtains the pointer to a **PixelMap** object.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| drawableDescriptor | Pointer to a **DrawableDescriptor** object. |

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

| Name| Description|
| -------- | -------- |
| drawableDescriptor | Pointer to a **DrawableDescriptor** object. |
| duration | Total playback duration, in milliseconds. |


### OH_ArkUI_DrawableDescriptor_SetAnimationIteration()

```
void OH_ArkUI_DrawableDescriptor_SetAnimationIteration (ArkUI_DrawableDescriptor * drawableDescriptor, int32_t iteration )
```
**Description**

Sets the number of times that a pixel map image array is played.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| drawableDescriptor | Pointer to a **DrawableDescriptor** object. |
| iterations | Number of playback times. |


### OH_ArkUI_DrawContext_GetCanvas()

```
void* OH_ArkUI_DrawContext_GetCanvas (ArkUI_DrawContext * context)
```
**Description**

Obtains the drawing canvas pointer, which can be converted into the OH_Drawing_Canvas pointer of the graphics library for drawing.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
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

| Name| Description|
| -------- | -------- |
| context | Draw context. |

**Returns**

Size of the area that can be drawn.


### OH_ArkUI_GestureEvent_GetActionType()

```
ArkUI_GestureEventActionType OH_ArkUI_GestureEvent_GetActionType (const ArkUI_GestureEvent * event)
```
**Description**

Obtains the gesture event type.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| event | Gesture event. |

**Returns**

Returns the gesture event type.


### OH_ArkUI_GestureEvent_GetNode()

```
ArkUI_NodeHandle OH_ArkUI_GestureEvent_GetNode (const ArkUI_GestureEvent * event)
```
**Description**

Obtains the ArkUI component to which the gesture is bound.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| event | Gesture event. |

**Returns**

Returns the ArkUI component.


### OH_ArkUI_GestureEvent_GetRawInputEvent()

```
const ArkUI_UIInputEvent* OH_ArkUI_GestureEvent_GetRawInputEvent (const ArkUI_GestureEvent * event)
```
**Description**

Obtains gesture input.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| event | Gesture event. |

**Returns**

Returns the pointer to the input event of the gesture event.


### OH_ArkUI_GestureEvent_GetResponseNode()

```
ArkUI_NodeHandle OH_ArkUI_GestureEvent_GetResponseNode (ArkUI_GestureEvent * event)
```
**Description**

Obtains the node that responds to the gesture.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| event | Gesture event. |

**Returns**

Returns the pointer to the node if the node exists; returns **NULL** otherwise.


### OH_ArkUI_GestureEventTargetInfo_IsScrollBegin()

```
int32_t OH_ArkUI_GestureEventTargetInfo_IsScrollBegin (ArkUI_GestureEventTargetInfo * info, bool * ret )
```
**Description**

Obtains whether this scroll container is scrolled to the top.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| info | Gesture event target information. |
| ret | Obtains whether this scroll container is scrolled to the top. |

**Returns**

Returns **0** if the operation is successful. Returns **401** if a parameter error occurs. Returns **180001** if the component is not a scroll container.


### OH_ArkUI_GestureEventTargetInfo_IsScrollEnd()

```
int32_t OH_ArkUI_GestureEventTargetInfo_IsScrollEnd (ArkUI_GestureEventTargetInfo * info, bool * ret )
```
**Description**

Obtains whether this scroll container is scrolled to the bottom.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| info | Gesture event target information. |
| ret | Obtains whether this scroll container is scrolled to the bottom. |

**Returns**

Returns **0** if the operation is successful. Returns **401** if a parameter error occurs. Returns **180001** if the component is not a scroll container.


### OH_ArkUI_GestureInterruptInfo_GetGestureEvent()

```
ArkUI_GestureEvent* OH_ArkUI_GestureInterruptInfo_GetGestureEvent (const ArkUI_GestureInterruptInfo * event)
```
**Description**

Obtains the pointer to the interrupted gesture event.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| event | Interrupt callback event. |

**Returns**

Returns the pointer to the interrupted gesture event.


### OH_ArkUI_GestureInterruptInfo_GetRecognizer()

```
ArkUI_GestureRecognizer* OH_ArkUI_GestureInterruptInfo_GetRecognizer (const ArkUI_GestureInterruptInfo * event)
```
**Description**

Returns the pointer to interrupted gesture recognizer.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
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

| Name| Description|
| -------- | -------- |
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

| Name| Description|
| -------- | -------- |
| event | Interrupt callback event. |

**Returns**

Returns the type of the system gesture to trigger. If the gesture to trigger is not a system gesture, **-1** is returned.


### OH_ArkUI_GetContextByNode()

```
ArkUI_ContextHandle OH_ArkUI_GetContextByNode (ArkUI_NodeHandle node)
```
**Description**

Obtains the pointer to the UI context object of the specified node.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| node | Specified node. |

**Returns**

Returns the pointer to the UI context object.


### OH_ArkUI_GetContextFromNapiValue()

```
int32_t OH_ArkUI_GetContextFromNapiValue (napi_env env, napi_value value, ArkUI_ContextHandle * context )
```
**Description**

Obtains a **UIContext** object on the ArkTS side and maps it to an **ArkUI_ContextHandle** object on the native side.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| env | Pointer to the NAPI environment. |
| value | Context object created on the ArkTS side. |
| context | ArkUI_ContextHandle pointer. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs.


### OH_ArkUI_GetDrawableDescriptorFromNapiValue()

```
int32_t OH_ArkUI_GetDrawableDescriptorFromNapiValue (napi_env env, napi_value value, ArkUI_DrawableDescriptor ** drawableDescriptor )
```
**Description**

Maps a **DrawableDescriptor** object on the ArkTS side to an **ArkUI_DrawableDescriptor** object on the native side.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| env | Pointer to the NAPI environment. |
| value | **DrawableDescriptor** object created on the ArkTS side. |
| drawableDescriptor | Object that receives the pointer to the **ArkUI_DrawableDescriptor** object. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs.


### OH_ArkUI_GetDrawableDescriptorFromResourceNapiValue()

```
int32_t OH_ArkUI_GetDrawableDescriptorFromResourceNapiValue (napi_env env, napi_value value, ArkUI_DrawableDescriptor ** drawableDescriptor )
```
**Description**

Maps an $r resource object on the ArkTS side to an **ArkUI_DrawableDescriptor** object on the native side.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| env | Pointer to the NAPI environment. |
| value | $r resource object created on ArkTS. |
| drawableDescriptor | Object that receives the pointer to the **ArkUI_DrawableDescriptor** object. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs.


### OH_ArkUI_GetGestureBindNodeId()

```
int32_t OH_ArkUI_GetGestureBindNodeId (ArkUI_GestureRecognizer * recognizer, char * nodeId, int32_t size, int32_t * result )
```
**Description**

Obtains the ID of the component linked to a gesture recognizer.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| recognizer | Pointer to the gesture recognizer. |
| nodeId | ID of a component. |
| size | Size of the storage area. |
| result | Length of the string to be copied. |

**Returns**

Returns **0** if the operation is successful. Returns **401** if a parameter error occurs. Returns **180002** if the buffer is not large enough.


### OH_ArkUI_GetGestureEventTargetInfo()

```
int32_t OH_ArkUI_GetGestureEventTargetInfo (ArkUI_GestureRecognizer * recognizer, ArkUI_GestureEventTargetInfo ** info )
```
**Description**

Obtains the information about a gesture event target.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| recognizer | Pointer to the gesture recognizer. |
| info | Gesture event target information. |

**Returns**

Returns **0** if the operation is successful. Returns **401** if a parameter error occurs.


### OH_ArkUI_GetGestureRecognizerEnabled()

```
bool OH_ArkUI_GetGestureRecognizerEnabled (ArkUI_GestureRecognizer * recognizer)
```
**Description**

Obtains the enabled state of a gesture recognizer.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| recognizer | Pointer to the gesture recognizer. |

**Returns**

**true**: enabled false: disabled


### OH_ArkUI_GetGestureRecognizerState()

```
int32_t OH_ArkUI_GetGestureRecognizerState (ArkUI_GestureRecognizer * recognizer, ArkUI_GestureRecognizerState * state )
```
**Description**

Obtains the state of a gesture recognizer.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| recognizer | Pointer to the gesture recognizer. |
| state | Status of the gesture recognizer. |

**Returns**

Returns **0** if the operation is successful. Returns **401** if a parameter error occurs.


### OH_ArkUI_GetGestureTag()

```
int32_t OH_ArkUI_GetGestureTag (ArkUI_GestureRecognizer * recognizer, char * buffer, int32_t bufferSize, int32_t * result )
```
**Description**

Obtains the mark of the gesture recognizer.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| recognizer | Pointer to the gesture recognizer. |
| buffer | Storage zone |
| bufferSize | Size of the storage area. |
| result | Length of the string to be copied. |

**Returns**

Returns **0** if the operation is successful. Returns **401** if a parameter error occurs. Returns **180002** if the buffer is not large enough.


### OH_ArkUI_GetNavDestinationId()

```
ArkUI_ErrorCode OH_ArkUI_GetNavDestinationId (ArkUI_NodeHandle node, char * buffer, int32_t bufferSize, int32_t * writeLength )
```
**Description**

Obtains the ID of the **NavDestination** component where the specified node is located.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| node | Specified node. |
| buffer | buffer. NavDestinationID is written to this memory area. |
| bufferSize | Pointer to the buffer size. |
| writeLength | When ARKUI_ERROR_CODE_NO_ERROR is returned, this parameter indicates the length of the string written to the buffer. When ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR is returned, this parameter indicates the minimum buffer size that can hold the target. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. The ARKUI_ERROR_CODE_GET_INFO_FAILED fails to query information. The possible cause is that the current node is not in Navigation. The buffer size specified by ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR is less than the minimum buffer size that can hold the target.


### OH_ArkUI_GetNavDestinationIndex()

```
ArkUI_ErrorCode OH_ArkUI_GetNavDestinationIndex (ArkUI_NodeHandle node, int32_t * index )
```
**Description**

Obtains the index of the **NavDestination** component where the specified node is located in the navigation stack.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| node | Specified node. |
| index | Returns the index, starting from 0. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. The ARKUI_ERROR_CODE_GET_INFO_FAILED fails to query information. The possible cause is that the current node is not in Navigation.


### OH_ArkUI_GetNavDestinationName()

```
ArkUI_ErrorCode OH_ArkUI_GetNavDestinationName (ArkUI_NodeHandle node, char * buffer, int32_t bufferSize, int32_t * writeLength )
```
**Description**

Obtains the name of the **NavDestination** component where the specified node is located.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| node | Specified node. |
| buffer | Buffer. The queried NavDestination name is written to this memory area. |
| bufferSize | Pointer to the buffer size. |
| writeLength | When ARKUI_ERROR_CODE_NO_ERROR is returned, this parameter indicates the length of the string written to the buffer. When ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR is returned, this parameter indicates the minimum buffer size that can hold the target. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. The ARKUI_ERROR_CODE_GET_INFO_FAILED fails to query information. The possible cause is that the current node is not in Navigation. The buffer size specified by ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR is less than the minimum buffer size that can hold the target.


### OH_ArkUI_GetNavDestinationNameByIndex()

```
ArkUI_ErrorCode OH_ArkUI_GetNavDestinationNameByIndex (ArkUI_NodeHandle node, int32_t index, char * buffer, int32_t bufferSize, int32_t * writeLength )
```
**Description**

Obtains the page name that matches the specified index in the navigation stack where the specified node is located.        The index starts from 0, which indicates the bottom of the stack.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| node | Specified node. |
| index | Index of the queried NavDestination in the stack. |
| buffer | Buffer. The name of the queried page is written to this memory area. |
| bufferSize | Pointer to the buffer size. |
| writeLength | When ARKUI_ERROR_CODE_NO_ERROR is returned, this parameter indicates the length of the string written to the buffer. When ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR is returned, this parameter indicates the minimum buffer size that can hold the target. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. The value of ARKUI_ERROR_CODE_NODE_INDEX_INVALID index is invalid. The ARKUI_ERROR_CODE_GET_INFO_FAILED fails to query information. The possible cause is that the current node is not in Navigation. The buffer size specified by ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR is less than the minimum buffer size that can hold the target.


### OH_ArkUI_GetNavDestinationParam()

```
napi_value OH_ArkUI_GetNavDestinationParam (ArkUI_NodeHandle node)
```
**Description**

Obtains the parameters of the **NavDestination** component where the specified node is located.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| node | Specified node. |

**Returns**

Parameter object.


### OH_ArkUI_GetNavDestinationState()

```
ArkUI_ErrorCode OH_ArkUI_GetNavDestinationState (ArkUI_NodeHandle node, ArkUI_NavDestinationState * state )
```
**Description**

Obtains the state of the **NavDestination** component where the specified node is located.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| node | Specified node. |
| state | The status value of NavDestination is written back to this parameter. |

**Returns**

The error code ARKUI_ERROR_CODE_NO_ERROR is returned. The ARKUI_ERROR_CODE_GET_INFO_FAILED fails to query information. The possible cause is that the current node is not in Navigation.


### OH_ArkUI_GetNavigationId()

```
ArkUI_ErrorCode OH_ArkUI_GetNavigationId (ArkUI_NodeHandle node, char * buffer, int32_t bufferSize, int32_t * writeLength )
```
**Description**

Obtains the ID of the **Navigation** component where the specified node is located.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| node | Specified node. |
| buffer | buffer. The NavigationID is written to this memory area. |
| bufferSize | Pointer to the buffer size. |
| writeLength | When ARKUI_ERROR_CODE_NO_ERROR is returned, this parameter indicates the length of the string written to the buffer. When ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR is returned, this parameter indicates the minimum buffer size that can hold the target. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. The ARKUI_ERROR_CODE_GET_INFO_FAILED fails to query information. The possible cause is that the current node is not in Navigation. The buffer size specified by ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR is less than the minimum buffer size that can hold the target.


### OH_ArkUI_GetNavStackLength()

```
ArkUI_ErrorCode OH_ArkUI_GetNavStackLength (ArkUI_NodeHandle node, int32_t * length )
```
**Description**

Obtains the length of the navigation stack where the specified node is located.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| node | Specified node. |
| length | Length of the stack. The result, if obtained successfully, is written back to this parameter. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. The ARKUI_ERROR_CODE_GET_INFO_FAILED fails to query information. The possible cause is that the current node is not in Navigation.


### OH_ArkUI_GetNodeContentFromNapiValue()

```
int32_t OH_ArkUI_GetNodeContentFromNapiValue (napi_env env, napi_value value, ArkUI_NodeContentHandle * content )
```
**Description**

Obtains a **NodeContent** object on the ArkTS side and maps it to an **ArkUI_NodeContentHandle** object on the native side.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| env | Pointer to the NAPI environment. |
| value | NodeContent object created on ArkTS. |
| context | ArkUI_NodeContentHandle pointer. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs.


### OH_ArkUI_GetNodeHandleFromNapiValue()

```
int32_t OH_ArkUI_GetNodeHandleFromNapiValue (napi_env env, napi_value frameNode, ArkUI_NodeHandle * handle )
```
**Description**

Obtains a **FrameNode** object on the ArkTS side and maps it to an **ArkUI_NodeHandle** object on the native side.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| env | Pointer to the NAPI environment. |
| frameNode | FrameNode object created on the ArkTS side. |
| handle | **ArkUI_NodeHandle** pointer. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs.

### OH_ArkUI_GetPanGestureDirectionMask()

```
int32_t OH_ArkUI_GetPanGestureDirectionMask (ArkUI_GestureRecognizer * recognizer, ArkUI_GestureDirectionMask * directionMask )
```
**Description**

Obtains the direction of a pan gesture.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| recognizer | Pointer to the gesture recognizer. |
| directionMask | Sliding direction of the sliding gesture. |

**Returns**

Returns **0** if the operation is successful. Returns **401** if a parameter error occurs.


### OH_ArkUI_GetResponseRecognizersFromInterruptInfo()

```
int32_t OH_ArkUI_GetResponseRecognizersFromInterruptInfo (const ArkUI_GestureInterruptInfo * event, ArkUI_GestureRecognizerHandleArray * responseChain, int32_t * count )
```
**Description**

Obtains information about a gesture response chain.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| event | Gesture interrupt callback event. |
| responseChain | Gesture recognizer on the response chain component. |
| count | Number of gesture recognizers on the response chain component. |

**Returns**

Returns **0** if the operation is successful. Returns **401** if a parameter error occurs.


### OH_ArkUI_GetRouterPageId()

```
ArkUI_ErrorCode OH_ArkUI_GetRouterPageId (ArkUI_NodeHandle node, char * buffer, int32_t bufferSize, int32_t * writeLength )
```
**Description**

Obtains the ID of the page where the specified node is located.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| node | Specified node. |
| buffer | buffer. Page Id is written to this memory area. |
| bufferSize | Pointer to the buffer size. |
| writeLength | When ARKUI_ERROR_CODE_NO_ERROR is returned, this parameter indicates the length of the string written to the buffer. When ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR is returned, this parameter indicates the minimum buffer size that can hold the target. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. The ARKUI_ERROR_CODE_GET_INFO_FAILED fails to query information. The buffer size specified by ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR is less than the minimum buffer size that can hold the target.


### OH_ArkUI_GetRouterPageIndex()

```
ArkUI_ErrorCode OH_ArkUI_GetRouterPageIndex (ArkUI_NodeHandle node, int32_t * index )
```
**Description**

Obtains the index of the page where the specified node is located in the page stack for routing.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| node | Specified node. |
| index | Returns the index, starting from 1. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. The ARKUI_ERROR_CODE_GET_INFO_FAILED fails to query information. The possible cause is that the current node is not in Navigation.


### OH_ArkUI_GetRouterPageName()

```
ArkUI_ErrorCode OH_ArkUI_GetRouterPageName (ArkUI_NodeHandle node, char * buffer, int32_t bufferSize, int32_t * writeLength )
```
**Description**

Obtains the name of the page where the specified node is located.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| node | Specified node. |
| buffer | Buffer. The page name is written to this memory area. |
| bufferSize | Pointer to the buffer size. |
| writeLength | When ARKUI_ERROR_CODE_NO_ERROR is returned, this parameter indicates the length of the string written to the buffer. When ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR is returned, this parameter indicates the minimum buffer size that can hold the target. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. The ARKUI_ERROR_CODE_GET_INFO_FAILED fails to query information. The buffer size specified by ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR is less than the minimum buffer size that can hold the target.


### OH_ArkUI_GetRouterPagePath()

```
ArkUI_ErrorCode OH_ArkUI_GetRouterPagePath (ArkUI_NodeHandle node, char * buffer, int32_t bufferSize, int32_t * writeLength )
```
**Description**

Obtains the path to the page where the specified node is located.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| node | Specified node. |
| buffer | buffer. Page Path is written to this memory area. |
| bufferSize | Pointer to the buffer size. |
| writeLength | When ARKUI_ERROR_CODE_NO_ERROR is returned, this parameter indicates the length of the string written to the buffer. When ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR is returned, this parameter indicates the minimum buffer size that can hold the target. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. The ARKUI_ERROR_CODE_GET_INFO_FAILED fails to query information. The buffer size specified by ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR is less than the minimum buffer size that can hold the target.


### OH_ArkUI_GetRouterPageState()

```
ArkUI_ErrorCode OH_ArkUI_GetRouterPageState (ArkUI_NodeHandle node, ArkUI_RouterPageState * state )
```
**Description**

Obtains the state of the page where the specified node is located.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| node | Specified node. |
| state | The status value of Router Page is written back to this parameter. |

**Returns**

The error code ARKUI_ERROR_CODE_NO_ERROR is returned. The ARKUI_ERROR_CODE_GET_INFO_FAILED fails to query information.


### OH_ArkUI_GuidelineOption_Create()

```
ArkUI_GuidelineOption* OH_ArkUI_GuidelineOption_Create (int32_t size)
```
**Description**

Creates a guideline configuration for this **RelativeContainer**.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| size | Number of guidelines. |

**Returns**

Returns the guideline configuration.


### OH_ArkUI_GuidelineOption_Dispose()

```
void OH_ArkUI_GuidelineOption_Dispose (ArkUI_GuidelineOption * guideline)
```
**Description**

Destroys auxiliary line information.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| guideline | Pointer to a guideline configuration. |


### OH_ArkUI_GuidelineOption_GetDirection()

```
ArkUI_Axis OH_ArkUI_GuidelineOption_GetDirection (ArkUI_GuidelineOption * guideline, int32_t index )
```
**Description**

Obtains the direction of a guideline.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| guideline | Pointer to a guideline configuration. |
| index | Index of the guideline. |

**Returns**

Returns the direction of the guideline.


### OH_ArkUI_GuidelineOption_GetId()

```
const char* OH_ArkUI_GuidelineOption_GetId (ArkUI_GuidelineOption * guideline, int32_t index )
```
**Description**

Obtains the ID of a guideline.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| guideline | Pointer to a guideline configuration. |
| index | Index of the guideline. |

**Returns**

Returns the ID of the guideline.


### OH_ArkUI_GuidelineOption_GetPositionEnd()

```
float OH_ArkUI_GuidelineOption_GetPositionEnd (ArkUI_GuidelineOption * guideline, int32_t index )
```
**Description**

Obtains the distance between a guideline and the right or bottom of the container.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| guideline | Pointer to a guideline configuration. |
| index | Index of the guideline. |

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

| Name| Description|
| -------- | -------- |
| guideline | Pointer to a guideline configuration. |
| index | Index of the guideline. |

**Returns**

Distance between the guideline and the left or top of the container.


### OH_ArkUI_GuidelineOption_SetDirection()

```
void OH_ArkUI_GuidelineOption_SetDirection (ArkUI_GuidelineOption * guideline, ArkUI_Axis value, int32_t index )
```
**Description**

Sets the direction of a guideline.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| guideline | Pointer to a guideline configuration. |
| value | Direction.  |
| index | Index of the guideline. |


### OH_ArkUI_GuidelineOption_SetId()

```
void OH_ArkUI_GuidelineOption_SetId (ArkUI_GuidelineOption * guideline, const char * value, int32_t index )
```
**Description**

Sets the ID of a guideline.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| guideline | Pointer to a guideline configuration. |
| value | ID of the guideline, which must be unique and cannot be the same as the name of any component in the container. |
| index | Index of the guideline. |


### OH_ArkUI_GuidelineOption_SetPositionEnd()

```
void OH_ArkUI_GuidelineOption_SetPositionEnd (ArkUI_GuidelineOption * guideline, float value, int32_t index )
```
**Description**

Sets the distance between a guideline and the right or bottom of the container.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| guideline | Pointer to a guideline configuration. |
| value | Distance between the guideline and the right or bottom of the container. |
| index | Index of the guideline. |


### OH_ArkUI_GuidelineOption_SetPositionStart()

```
void OH_ArkUI_GuidelineOption_SetPositionStart (ArkUI_GuidelineOption * guideline, float value, int32_t index )
```
**Description**

Sets the distance between a guideline and the left or top of the container.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| guideline | Pointer to a guideline configuration. |
| value | Distance between the guideline and the left or top of the container. |
| index | Index of the guideline. |


### OH_ArkUI_ImageAnimatorFrameInfo_CreateFromDrawableDescriptor()

```
ArkUI_ImageAnimatorFrameInfo* OH_ArkUI_ImageAnimatorFrameInfo_CreateFromDrawableDescriptor (ArkUI_DrawableDescriptor * drawable)
```
**Description**

Creates an image frame information object based on a **DrawableDescriptor** object, with the image format being Resource or PixelMap.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| drawable | Pointer to an **ArkUI_DrawableDescriptor** object created using Resource or PixelMap. |

**Returns**

Returns the pointer to the created frame image object.


### OH_ArkUI_ImageAnimatorFrameInfo_CreateFromString()

```
ArkUI_ImageAnimatorFrameInfo* OH_ArkUI_ImageAnimatorFrameInfo_CreateFromString (char * src)
```
**Description**

Creates an image frame information object based on an image path, with the image format being SVG, PNG, or JPG.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| src | Image path. |

**Returns**

Returns the pointer to the created frame image object.


### OH_ArkUI_ImageAnimatorFrameInfo_Dispose()

```
void OH_ArkUI_ImageAnimatorFrameInfo_Dispose (ArkUI_ImageAnimatorFrameInfo * imageInfo)
```
**Description**

Disposes of the pointer to an image frame information object.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| imageInfo | Pointer to the frame image object. |


### OH_ArkUI_ImageAnimatorFrameInfo_GetDuration()

```
int32_t OH_ArkUI_ImageAnimatorFrameInfo_GetDuration (ArkUI_ImageAnimatorFrameInfo * imageInfo)
```
**Description**

Obtains the playback duration of an image.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| imageInfo | Pointer to the frame image object. |

**Returns**

Returns the playback duration of the image, in milliseconds. If **imageInfo** is a null pointer, **0** is returned.


### OH_ArkUI_ImageAnimatorFrameInfo_GetHeight()

```
int32_t OH_ArkUI_ImageAnimatorFrameInfo_GetHeight (ArkUI_ImageAnimatorFrameInfo * imageInfo)
```
**Description**

Obtains the image height.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| imageInfo | Pointer to the frame image object. |

**Returns**

Returns the image height, in PX. If **imageInfo** is a null pointer, **0** is returned.


### OH_ArkUI_ImageAnimatorFrameInfo_GetLeft()

```
int32_t OH_ArkUI_ImageAnimatorFrameInfo_GetLeft (ArkUI_ImageAnimatorFrameInfo * imageInfo)
```
**Description**

Obtains the horizontal coordinate of an image relative to the upper left corner of the component.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| imageInfo | Pointer to the frame image object. |

**Returns**

Returns the horizontal coordinate of the image relative to the upper left corner of the component, in px. If **imageInfo** is a null pointer, **0** is returned.


### OH_ArkUI_ImageAnimatorFrameInfo_GetTop()

```
int32_t OH_ArkUI_ImageAnimatorFrameInfo_GetTop (ArkUI_ImageAnimatorFrameInfo * imageInfo)
```
**Description**

Obtains the vertical coordinate of an image relative to the upper left corner of the component.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| imageInfo | Pointer to the frame image object. |

**Returns**

Returns the vertical coordinate of the image relative to the upper left corner of the component, in px. If **imageInfo** is a null pointer, **0** is returned.


### OH_ArkUI_ImageAnimatorFrameInfo_GetWidth()

```
int32_t OH_ArkUI_ImageAnimatorFrameInfo_GetWidth (ArkUI_ImageAnimatorFrameInfo * imageInfo)
```
**Description**

Obtains the image width.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| imageInfo | Pointer to the frame image object. |

**Returns**

Returns the image width, in PX. If **imageInfo** is a null pointer, **0** is returned.


### OH_ArkUI_ImageAnimatorFrameInfo_SetDuration()

```
void OH_ArkUI_ImageAnimatorFrameInfo_SetDuration (ArkUI_ImageAnimatorFrameInfo * imageInfo, int32_t duration )
```
**Description**

Sets the playback duration of an image.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| imageInfo | Pointer to the frame image object. |
| duration | Playback duration of an image, in milliseconds. |


### OH_ArkUI_ImageAnimatorFrameInfo_SetHeight()

```
void OH_ArkUI_ImageAnimatorFrameInfo_SetHeight (ArkUI_ImageAnimatorFrameInfo * imageInfo, int32_t height )
```
**Description**

Sets the image height.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| imageInfo | Pointer to the frame image object. |
| height | Image height, in px. |


### OH_ArkUI_ImageAnimatorFrameInfo_SetLeft()

```
void OH_ArkUI_ImageAnimatorFrameInfo_SetLeft (ArkUI_ImageAnimatorFrameInfo * imageInfo, int32_t left )
```
**Description**

Sets the horizontal coordinate of an image relative to the upper left corner of the component.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| imageInfo | Pointer to the frame image object. |
| left | Horizontal coordinate of the image relative to the upper left corner of the component, in px. |


### OH_ArkUI_ImageAnimatorFrameInfo_SetTop()

```
void OH_ArkUI_ImageAnimatorFrameInfo_SetTop (ArkUI_ImageAnimatorFrameInfo * imageInfo, int32_t top )
```
**Description**

Sets the vertical coordinate of an image relative to the upper left corner of the component.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| imageInfo | Pointer to the frame image object. |
| top | Vertical coordinate of the image relative to the upper left corner of the component, in px. |


### OH_ArkUI_ImageAnimatorFrameInfo_SetWidth()

```
void OH_ArkUI_ImageAnimatorFrameInfo_SetWidth (ArkUI_ImageAnimatorFrameInfo * imageInfo, int32_t width )
```
**Description**

Sets the image width.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| imageInfo | Pointer to the frame image object. |
| width | Image width, in px. |


### OH_ArkUI_IsBuiltInGesture()

```
bool OH_ArkUI_IsBuiltInGesture (ArkUI_GestureRecognizer * recognizer)
```
**Description**

Obtains whether a gesture is a built-in gesture.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| recognizer | Pointer to the gesture recognizer. |

**Returns**

true: built-in gestures. false: The gesture is not a built-in gesture.


### OH_ArkUI_IsGestureRecognizerValid()

```
bool OH_ArkUI_IsGestureRecognizerValid (ArkUI_GestureRecognizer * recognizer)
```
**Description**

Obtains whether a gesture recognizer is valid.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| recognizer | Pointer to the gesture recognizer. |

**Returns**

true: The gesture recognizer is valid. Returns **false** if the gesture recognizer is invalid.


### OH_ArkUI_KeyframeAnimateOption_Create()

```
ArkUI_KeyframeAnimateOption* OH_ArkUI_KeyframeAnimateOption_Create (int32_t size)
```
**Description**

Obtains the keyframe animation parameters.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| size | Number of key frame animation states. |

**Returns**

Returns the keyframe animation parameter object; returns **NULL** if the value of **size** is less than 0.


### OH_ArkUI_KeyframeAnimateOption_Dispose()

```
void OH_ArkUI_KeyframeAnimateOption_Dispose (ArkUI_KeyframeAnimateOption * option)
```
**Description**

Destroys a keyframe animation parameter object.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Returns the keyframe animation parameter object; |


### OH_ArkUI_KeyframeAnimateOption_GetCurve()

```
ArkUI_CurveHandle OH_ArkUI_KeyframeAnimateOption_GetCurve (ArkUI_KeyframeAnimateOption * option, int32_t index )
```
**Description**

Obtains the animation curve of a specific state in a keyframe animation.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Keyframe animation parameters. |
| index | Status index. |

**Returns**

Returns the animation curve.


### OH_ArkUI_KeyframeAnimateOption_GetDelay()

```
int32_t OH_ArkUI_KeyframeAnimateOption_GetDelay (ArkUI_KeyframeAnimateOption * option)
```
**Description**

Obtains the overall delay of a keyframe animation

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Keyframe animation parameters. |

**Returns**

Returns the overall delay.


### OH_ArkUI_KeyframeAnimateOption_GetDuration()

```
int32_t OH_ArkUI_KeyframeAnimateOption_GetDuration (ArkUI_KeyframeAnimateOption * option, int32_t index )
```
**Description**

Obtains the duration of a specific state in a keyframe animation.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Keyframe animation parameters. |
| index | Status index. |

**Returns**

Duration, in milliseconds.


### OH_ArkUI_KeyframeAnimateOption_GetIterations()

```
int32_t OH_ArkUI_KeyframeAnimateOption_GetIterations (ArkUI_KeyframeAnimateOption * option)
```
**Description**

Obtains the number of times that a keyframe animation is played.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Keyframe animation parameters. |

**Returns**

Number of times that the animation is played.


### OH_ArkUI_KeyframeAnimateOption_RegisterOnEventCallback()

```
int32_t OH_ArkUI_KeyframeAnimateOption_RegisterOnEventCallback (ArkUI_KeyframeAnimateOption * option, void * userData, void(*)(void *userData) event, int32_t index )
```
**Description**

Sets the closure function of the state at the time of the keyframe, that is, the state to be reached at the time of the keyframe.

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Keyframe animation parameters. |
| event | Closure function. |
| userData | Pointer to a custom object. |
| index | Status index. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs.


### OH_ArkUI_KeyframeAnimateOption_RegisterOnFinishCallback()

```
int32_t OH_ArkUI_KeyframeAnimateOption_RegisterOnFinishCallback (ArkUI_KeyframeAnimateOption * option, void * userData, void(*)(void *userData) onFinish )
```
**Description**

Sets the callback invoked when the keyframe animation playback is complete. This API is called after the keyframe animation has played for the specified number of times.

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Keyframe animation parameters. |
| userData | Pointer to a custom object. |
| onFinish | Callback used to return the result. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs.


### OH_ArkUI_KeyframeAnimateOption_SetCurve()

```
int32_t OH_ArkUI_KeyframeAnimateOption_SetCurve (ArkUI_KeyframeAnimateOption * option, ArkUI_CurveHandle value, int32_t index )
```
**Description**

Sets the animation curve for a specific keyframe in a keyframe animation.

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Keyframe animation parameters. |
| value | Animation curve used by the key frame. Default value: **EASE_IN_OUT**. |
| index | Status index. |

**NOTE**

Because the **springMotion**, **responsiveSpringMotion**, and **interpolatingSpring** curves do not have effective duration settings, they are not supported.

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs.


### OH_ArkUI_KeyframeAnimateOption_SetDelay()

```
int32_t OH_ArkUI_KeyframeAnimateOption_SetDelay (ArkUI_KeyframeAnimateOption * option, int32_t value )
```
**Description**

Sets the overall delay of a keyframe animation, in milliseconds. By default, the keyframe animation is played without delay.

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Keyframe animation parameters. |
| value | Delay time, in milliseconds. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs.


### OH_ArkUI_KeyframeAnimateOption_SetDuration()

```
int32_t OH_ArkUI_KeyframeAnimateOption_SetDuration (ArkUI_KeyframeAnimateOption * option, int32_t value, int32_t index )
```
**Description**

Sets the duration of a keyframe animation, in milliseconds.

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Keyframe animation parameters. |
| value | Duration, in milliseconds. |
| index | Status index. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs.


### OH_ArkUI_KeyframeAnimateOption_SetIterations()

```
int32_t OH_ArkUI_KeyframeAnimateOption_SetIterations (ArkUI_KeyframeAnimateOption * option, int32_t value )
```
**Description**

Sets the number of times that the keyframe animation is played. By default, the animation is played once. The value **-1** indicates that the animation is played for an unlimited number of times. The value **0** indicates that there is no animation.

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Keyframe animation parameters. |
| value | Number of times that the animation is played. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs.


### OH_ArkUI_LayoutConstraint_Copy()

```
ArkUI_LayoutConstraint* OH_ArkUI_LayoutConstraint_Copy (const ArkUI_LayoutConstraint * Constraint)
```
**Description**

Constraint size deep copy.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
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

| Name| Description|
| -------- | -------- |
| Constraint | Size constraint. |


### OH_ArkUI_LayoutConstraint_GetMaxHeight()

```
int32_t OH_ArkUI_LayoutConstraint_GetMaxHeight (const ArkUI_LayoutConstraint * Constraint)
```
**Description**

Obtains the maximum height for a size constraint, in px.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| Constraint | Size constraint. |

**Returns**

Maximum height.


### OH_ArkUI_LayoutConstraint_GetMaxWidth()

```
int32_t OH_ArkUI_LayoutConstraint_GetMaxWidth (const ArkUI_LayoutConstraint * Constraint)
```
**Description**

Obtains the maximum width for a size constraint, in px.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
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

| Name| Description|
| -------- | -------- |
| Constraint | Size constraint. |

**Returns**

Minimum Height


### OH_ArkUI_LayoutConstraint_GetMinWidth()

```
int32_t OH_ArkUI_LayoutConstraint_GetMinWidth (const ArkUI_LayoutConstraint * Constraint)
```
**Description**

Obtains the minimum width for a size constraint, in px.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
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

| Name| Description|
| -------- | -------- |
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

| Name| Description|
| -------- | -------- |
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

| Name| Description|
| -------- | -------- |
| Constraint | Size constraint. |
| value | Maximum height, in pixels. |


### OH_ArkUI_LayoutConstraint_SetMaxWidth()

```
void OH_ArkUI_LayoutConstraint_SetMaxWidth (ArkUI_LayoutConstraint * Constraint, int32_t value )
```
**Description**

Sets the maximum width.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| Constraint | Size constraint. |
| value | Maximum width, in pixels. |


### OH_ArkUI_LayoutConstraint_SetMinHeight()

```
void OH_ArkUI_LayoutConstraint_SetMinHeight (ArkUI_LayoutConstraint * Constraint, int32_t value )
```
**Description**

Sets the minimum height.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| Constraint | Size constraint. |
| value | Minimum height, in pixels. |


### OH_ArkUI_LayoutConstraint_SetMinWidth()

```
void OH_ArkUI_LayoutConstraint_SetMinWidth (ArkUI_LayoutConstraint * Constraint, int32_t value )
```
**Description**

Sets the minimum width.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| Constraint | Size constraint. |
| value | Minimum width, in pixels. |


### OH_ArkUI_LayoutConstraint_SetPercentReferenceHeight()

```
void OH_ArkUI_LayoutConstraint_SetPercentReferenceHeight (ArkUI_LayoutConstraint * Constraint, int32_t value )
```
**Description**

Sets the height percentage reference.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| Constraint | Size constraint. |
| value | Height percentage base, in px. |


### OH_ArkUI_LayoutConstraint_SetPercentReferenceWidth()

```
void OH_ArkUI_LayoutConstraint_SetPercentReferenceWidth (ArkUI_LayoutConstraint * Constraint, int32_t value )
```
**Description**

Sets the width percentage reference.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| Constraint | Size constraint. |
| value | Width percentage benchmark, in px. |


### OH_ArkUI_List_CloseAllSwipeActions()

```
int32_t OH_ArkUI_List_CloseAllSwipeActions (ArkUI_NodeHandle node, void * userData, void(*)(void *userData) onFinish )
```
**Description**

Collapse the expanded ListItem.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| node | Node object for which an event needs to be registered. |
| userData | Custom event parameter, which is passed in the callback when the event is triggered. |
| onFinish | Callback triggered after the collapse animation is complete. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs. Returns **ARKUI_ERROR_CODE_ATTRIBUTE_OR_EVENT_NOT_SUPPORTED** if the event is not supported.


### OH_ArkUI_ListChildrenMainSizeOption_Create()

```
ArkUI_ListChildrenMainSize* OH_ArkUI_ListChildrenMainSizeOption_Create ()
```
**Description**

Creates a **ListChildrenMainSize** instance.

**Since**: 12

**Returns**

Returns the created **ListChildrenMainSize** instance.


### OH_ArkUI_ListChildrenMainSizeOption_Dispose()

```
void OH_ArkUI_ListChildrenMainSizeOption_Dispose (ArkUI_ListChildrenMainSize * option)
```
**Description**

Destroys a ListChildrenMainSize instance.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| option | ListChildrenMainSize instance to be destroyed. |


### OH_ArkUI_ListChildrenMainSizeOption_GetDefaultMainSize()

```
float OH_ArkUI_ListChildrenMainSizeOption_GetDefaultMainSize (ArkUI_ListChildrenMainSize * option)
```
**Description**

Obtains the default size in a **ListChildrenMainSize** instance.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| option | **ListChildrenMainSize** instance. |

**Returns**

Returns the default size, in vp. The default value is **0**. If **option** is a null pointer, **-1** is returned.


### OH_ArkUI_ListChildrenMainSizeOption_GetMainSize()

```
float OH_ArkUI_ListChildrenMainSizeOption_GetMainSize (ArkUI_ListChildrenMainSize * option, int32_t index )
```
**Description**

Obtains the value of the ChildrenMainSizeOption array of the List component.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| option | **ListChildrenMainSize** instance. |
| index | Subscript position of the value to be obtained. |

**Returns**

Value of the specific position of the array. If a parameter error occurs, **-1** is returned.


### OH_ArkUI_ListChildrenMainSizeOption_Resize()

```
void OH_ArkUI_ListChildrenMainSizeOption_Resize (ArkUI_ListChildrenMainSize * option, int32_t totalSize )
```
**Description**

Resets the array size of ChildrenMainSizeOption of the List component.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| option | **ListChildrenMainSize** instance. |
| totalSize | Array size. |


### OH_ArkUI_ListChildrenMainSizeOption_SetDefaultMainSize()

```
int32_t OH_ArkUI_ListChildrenMainSizeOption_SetDefaultMainSize (ArkUI_ListChildrenMainSize * option, float defaultMainSize )
```
**Description**

Sets the default size in a **ListChildrenMainSize** instance.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| option | **ListChildrenMainSize** instance. |
| defaultMainSize | Default size of a list item in a list. The unit is vp. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs.


### OH_ArkUI_ListChildrenMainSizeOption_Splice()

```
int32_t OH_ArkUI_ListChildrenMainSizeOption_Splice (ArkUI_ListChildrenMainSize * option, int32_t index, int32_t deleteCount, int32_t addCount )
```
**Description**

The size of the ChildrenMainSizeOption array of the List component is adjusted.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| option | **ListChildrenMainSize** instance. |
| index | Start position of the array whose MainSize is to be modified. |
| deleteCount | Number of MainSize arrays to be deleted starting from index. |
| addCount | Number of MainSize arrays to be added starting from index. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs.


### OH_ArkUI_ListChildrenMainSizeOption_UpdateSize()

```
int32_t OH_ArkUI_ListChildrenMainSizeOption_UpdateSize (ArkUI_ListChildrenMainSize * option, int32_t index, float mainSize )
```
**Description**

Updates the values in a **ChildrenMainSizeOption** array of a List component.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| option | **ListChildrenMainSize** instance. |
| index | Index at which to start changing the values in the array. |
| mainSize | New size value to set at the specified index. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs.


### OH_ArkUI_ListItemSwipeActionItem_Create()

```
ArkUI_ListItemSwipeActionItem* OH_ArkUI_ListItemSwipeActionItem_Create ()
```
**Description**

Creates a **ListItemSwipeActionItem** instance.

**Since**: 12

**Returns**

Returns the created **ListItemSwipeActionItem** instance.


### OH_ArkUI_ListItemSwipeActionItem_Dispose()

```
void OH_ArkUI_ListItemSwipeActionItem_Dispose (ArkUI_ListItemSwipeActionItem * item)
```
**Description**

Disposes of a **ListItemSwipeActionItem** instance.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| item | **ListItemSwipeActionItem** instance to dispose of. |


### OH_ArkUI_ListItemSwipeActionItem_GetActionAreaDistance()

```
float OH_ArkUI_ListItemSwipeActionItem_GetActionAreaDistance (ArkUI_ListItemSwipeActionItem * item)
```
**Description**

Obtains the swipe distance threshold for deleting the list item.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| item | Target **ListItemSwipeActionItem** instance. |

**Returns**

Returns the swipe distance threshold for deleting the list item. Return **0** if an error occurs.


### OH_ArkUI_ListItemSwipeActionItem_SetActionAreaDistance()

```
void OH_ArkUI_ListItemSwipeActionItem_SetActionAreaDistance (ArkUI_ListItemSwipeActionItem * item, float distance )
```
**Description**

Swipe distance threshold for deleting the list item.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| item | Target **ListItemSwipeActionItem** instance. |
| distance | Returns the swipe distance threshold for deleting the list item. |


### OH_ArkUI_ListItemSwipeActionItem_SetContent()

```
void OH_ArkUI_ListItemSwipeActionItem_SetContent (ArkUI_ListItemSwipeActionItem * item, ArkUI_NodeHandle node )
```
**Description**

Sets the layout content of ListItemSwipeActionItem.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| item | Target **ListItemSwipeActionItem** instance. |
| node | Layout information |


### OH_ArkUI_ListItemSwipeActionItem_SetOnAction()

```
void OH_ArkUI_ListItemSwipeActionItem_SetOnAction (ArkUI_ListItemSwipeActionItem * item, void(*)() callback )
```
**Description**

Sets the callback invoked when the list item is deleted while in the delete area.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| item | Target **ListItemSwipeActionItem** instance. |
| callback | Callback to invoke when an event of the specified type occurs. |


### OH_ArkUI_ListItemSwipeActionItem_SetOnActionWithUserData()

```
void OH_ArkUI_ListItemSwipeActionItem_SetOnActionWithUserData (ArkUI_ListItemSwipeActionItem * item, void * userData, void(*)(void *userData) callback )
```
**Description**

Sets the callback invoked when the list item is deleted while in the delete area.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| item | Target **ListItemSwipeActionItem** instance. |
| userData | Custom data. |
| callback | Callback to invoke when an event of the specified type occurs. |


### OH_ArkUI_ListItemSwipeActionItem_SetOnEnterActionArea()

```
void OH_ArkUI_ListItemSwipeActionItem_SetOnEnterActionArea (ArkUI_ListItemSwipeActionItem * item, void(*)() callback )
```
**Description**

Sets the callback invoked each time the list item enters the delete area.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| item | Target **ListItemSwipeActionItem** instance. |
| callback | Callback to invoke when an event of the specified type occurs. |


### OH_ArkUI_ListItemSwipeActionItem_SetOnEnterActionAreaWithUserData()

```
void OH_ArkUI_ListItemSwipeActionItem_SetOnEnterActionAreaWithUserData (ArkUI_ListItemSwipeActionItem * item, void * userData, void(*)(void *userData) callback )
```
**Description**

Sets the callback invoked each time the list item enters the delete area.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| item | Target **ListItemSwipeActionItem** instance. |
| userData | Custom data. |
| callback | Callback to invoke when an event of the specified type occurs. |


### OH_ArkUI_ListItemSwipeActionItem_SetOnExitActionArea()

```
void OH_ArkUI_ListItemSwipeActionItem_SetOnExitActionArea (ArkUI_ListItemSwipeActionItem * item, void(*)() callback )
```
**Description**

Sets the callback invoked each time the list item exits the delete area.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| item | Target **ListItemSwipeActionItem** instance. |
| callback | Callback to invoke when an event of the specified type occurs. |


### OH_ArkUI_ListItemSwipeActionItem_SetOnExitActionAreaWithUserData()

```
void OH_ArkUI_ListItemSwipeActionItem_SetOnExitActionAreaWithUserData (ArkUI_ListItemSwipeActionItem * item, void * userData, void(*)(void *userData) callback )
```
**Description**

Sets the callback invoked each time the list item exits the delete area.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| item | Target **ListItemSwipeActionItem** instance. |
| userData | Custom data. |
| callback | Callback to invoke when an event of the specified type occurs. |

### OH_ArkUI_ListItemSwipeActionItem_SetOnStateChange()

```
void OH_ArkUI_ListItemSwipeActionItem_SetOnStateChange (ArkUI_ListItemSwipeActionItem * item, void(*)(ArkUI_ListItemSwipeActionState swipeActionState) callback )
```
**Description**

Sets the callback invoked when the swipe state of the list item changes.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| item | Target **ListItemSwipeActionItem** instance. |
| callback | Status after the callback event swipeActionState changes. |


### OH_ArkUI_ListItemSwipeActionItem_SetOnStateChangeWithUserData()

```
void OH_ArkUI_ListItemSwipeActionItem_SetOnStateChangeWithUserData (ArkUI_ListItemSwipeActionItem * item, void * userData, void(*)(ArkUI_ListItemSwipeActionState swipeActionState, void *userData) callback )
```
**Description**

Sets the callback invoked when the swipe state of the list item changes.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| item | Target **ListItemSwipeActionItem** instance. |
| userData | Custom data. |
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

| Name| Description|
| -------- | -------- |
| option | ListItemSwipeActionOption instance to destroy. |


### OH_ArkUI_ListItemSwipeActionOption_GetEdgeEffect()

```
int32_t OH_ArkUI_ListItemSwipeActionOption_GetEdgeEffect (ArkUI_ListItemSwipeActionOption * option)
```
**Description**

Obtains the sliding effect.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Target **ListItemSwipeActionItem** instance. |

**Returns**

Scroll effect. The default return value is **ARKUI_LIST_ITEM_SWIPE_EDGE_EFFECT_SPRING**.


### OH_ArkUI_ListItemSwipeActionOption_SetEdgeEffect()

```
void OH_ArkUI_ListItemSwipeActionOption_SetEdgeEffect (ArkUI_ListItemSwipeActionOption * option, ArkUI_ListItemSwipeEdgeEffect edgeEffect )
```
**Description**

Sets the sliding effect.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Target **ListItemSwipeActionItem** instance. |
| edgeEffect | Scroll effect. |


### OH_ArkUI_ListItemSwipeActionOption_SetEnd()

```
void OH_ArkUI_ListItemSwipeActionOption_SetEnd (ArkUI_ListItemSwipeActionOption * option, ArkUI_ListItemSwipeActionItem * item )
```
**Description**

Sets the layout content for the right edge (for a vertical layout) or bottom edge (for a horizontal layout) of a **ListItemSwipeActionItem** instance.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Target **ListItemSwipeActionItem** instance. |
| builder | Layout information |


### OH_ArkUI_ListItemSwipeActionOption_SetOnOffsetChange()

```
void OH_ArkUI_ListItemSwipeActionOption_SetOnOffsetChange (ArkUI_ListItemSwipeActionOption * option, void(*)(float offset) callback )
```
**Description**

Sets the callback invoked when the scroll offset changes.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Target **ListItemSwipeActionItem** instance. |
| callback | Sliding offset of the callback event offset. |


### OH_ArkUI_ListItemSwipeActionOption_SetOnOffsetChangeWithUserData()

```
void OH_ArkUI_ListItemSwipeActionOption_SetOnOffsetChangeWithUserData (ArkUI_ListItemSwipeActionOption * option, void * userData, void(*)(float offset, void *userData) callback )
```
**Description**

Sets the callback invoked when the scroll offset changes.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Target **ListItemSwipeActionItem** instance. |
| userData | Custom data. |
| callback | Sliding offset of the callback event offset. |


### OH_ArkUI_ListItemSwipeActionOption_SetStart()

```
void OH_ArkUI_ListItemSwipeActionOption_SetStart (ArkUI_ListItemSwipeActionOption * option, ArkUI_ListItemSwipeActionItem * item )
```
**Description**

Sets the layout content for the left edge (for a vertical layout) or top edge (for a horizontal layout) of a **ListItemSwipeActionItem** instance.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Target **ListItemSwipeActionItem** instance. |
| builder | Layout information |


### OH_ArkUI_LongPress_GetRepeatCount()

```
int32_t OH_ArkUI_LongPress_GetRepeatCount (const ArkUI_GestureEvent * event)
```
**Description**

Obtains the number of times that a long press gesture is triggered periodically.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| event | Gesture event. |

**Returns**

Returns the number of times that the long press gesture is triggered periodically.


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

| Name| Description|
| -------- | -------- |
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

| Name| Description|
| -------- | -------- |
| handle | Component adapter object. |
| items | Array of nodes in the adapter. |
| size | Number of elements. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs.


### OH_ArkUI_NodeAdapter_GetTotalNodeCount()

```
uint32_t OH_ArkUI_NodeAdapter_GetTotalNodeCount (ArkUI_NodeAdapterHandle handle)
```
**Description**

Obtains the total number of elements in the Adapter.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
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

| Name| Description|
| -------- | -------- |
| handle | Component adapter object. |
| startPosition | Start position for inserting an element. |
| itemCount | Number of inserted elements. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs.


### OH_ArkUI_NodeAdapter_MoveItem()

```
int32_t OH_ArkUI_NodeAdapter_MoveItem (ArkUI_NodeAdapterHandle handle, uint32_t from, uint32_t to )
```
**Description**

Instructs the specified adapter to move certain elements.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| handle | Component adapter object. |
| from | Start position of the element shift. |
| to | End position of the element shift. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs.


### OH_ArkUI_NodeAdapter_RegisterEventReceiver()

```
int32_t OH_ArkUI_NodeAdapter_RegisterEventReceiver (ArkUI_NodeAdapterHandle handle, void * userData, void(*)(ArkUI_NodeAdapterEvent *event) receiver )
```
**Description**

Registers callback events related to the Adapter.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| handle | Component adapter object. |
| userData | Custom data. |
| receiver | Event receiving callback. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs.


### OH_ArkUI_NodeAdapter_ReloadAllItems()

```
int32_t OH_ArkUI_NodeAdapter_ReloadAllItems (ArkUI_NodeAdapterHandle handle)
```
**Description**

Instructs the specified adapter to reload all elements.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| handle | Component adapter object. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs.


### OH_ArkUI_NodeAdapter_ReloadItem()

```
int32_t OH_ArkUI_NodeAdapter_ReloadItem (ArkUI_NodeAdapterHandle handle, uint32_t startPosition, uint32_t itemCount )
```
**Description**

Instructs the specified adapter to reload certain elements.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| handle | Component adapter object. |
| startPosition | Start position of an element change. |
| itemCount | Number of changed elements. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs.


### OH_ArkUI_NodeAdapter_RemoveItem()

```
int32_t OH_ArkUI_NodeAdapter_RemoveItem (ArkUI_NodeAdapterHandle handle, uint32_t startPosition, uint32_t itemCount )
```
**Description**

Instructs the specified adapter to remove certain elements.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| handle | Component adapter object. |
| startPosition | Start position for deleting an element. |
| itemCount | Number of deleted elements. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs.


### OH_ArkUI_NodeAdapter_SetTotalNodeCount()

```
int32_t OH_ArkUI_NodeAdapter_SetTotalNodeCount (ArkUI_NodeAdapterHandle handle, uint32_t size )
```
**Description**

Sets the total number of elements in the specified adapter.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| handle | Component adapter object. |
| size | Number of elements. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs.


### OH_ArkUI_NodeAdapter_UnregisterEventReceiver()

```
void OH_ArkUI_NodeAdapter_UnregisterEventReceiver (ArkUI_NodeAdapterHandle handle)
```
**Description**

Deregisters Adapter-related callback events.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| handle | Component adapter object. |


### OH_ArkUI_NodeAdapterEvent_GetHostNode()

```
ArkUI_NodeHandle OH_ArkUI_NodeAdapterEvent_GetHostNode (ArkUI_NodeAdapterEvent * event)
```
**Description**

Obtains the scrolling class container node that uses the adapter.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| event | Adapter event object. |

**Returns**

Returns the scrollable container node that uses the specified adapter.


### OH_ArkUI_NodeAdapterEvent_GetItemIndex()

```
uint32_t OH_ArkUI_NodeAdapterEvent_GetItemIndex (ArkUI_NodeAdapterEvent * event)
```
**Description**

Sequence number of the element to be operated when the adapter event is obtained.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
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

| Name| Description|
| -------- | -------- |
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

| Name| Description|
| -------- | -------- |
| event | Adapter event object. |

**Returns**

Represents an event type.


### OH_ArkUI_NodeAdapterEvent_GetUserData()

```
void* OH_ArkUI_NodeAdapterEvent_GetUserData (ArkUI_NodeAdapterEvent * event)
```
**Description**

Obtains the custom data passed in during registration of the specified event.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| event | Adapter event object. |


### OH_ArkUI_NodeAdapterEvent_SetItem()

```
int32_t OH_ArkUI_NodeAdapterEvent_SetItem (ArkUI_NodeAdapterEvent * event, ArkUI_NodeHandle node )
```
**Description**

Sets the component to be added to the specified adapter.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| event | Adapter event object. |
| node | Component to be added. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs.


### OH_ArkUI_NodeAdapterEvent_SetNodeId()

```
int32_t OH_ArkUI_NodeAdapterEvent_SetNodeId (ArkUI_NodeAdapterEvent * event, int32_t id )
```
**Description**

Sets the generated component ID.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| event | Adapter event object. |
| id | Sets the returned component ID. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs.


### OH_ArkUI_NodeContent_AddNode()

```
int32_t OH_ArkUI_NodeContent_AddNode (ArkUI_NodeContentHandle content, ArkUI_NodeHandle node )
```
**Description**

Adds an ArkUI component node to the specified NodeContent object.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| content | NodeContent object to which a node is to be added. |
| node | Node to be added. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs.


### OH_ArkUI_NodeContent_GetUserData()

```
void* OH_ArkUI_NodeContent_GetUserData (ArkUI_NodeContentHandle content)
```
**Description**

Obtains the user-defined data saved on the NodeContent object.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| content | NodeContent object whose user-defined data needs to be saved. |

**Returns**

Custom data.


### OH_ArkUI_NodeContent_InsertNode()

```
int32_t OH_ArkUI_NodeContent_InsertNode (ArkUI_NodeContentHandle content, ArkUI_NodeHandle node, int32_t position )
```
**Description**

Inserts an ArkUI component node into a specific location of the corresponding NodeContent object.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| content | NodeContent object of the node to be inserted. |
| node | Node to be inserted. |
| position | Start time for an asset to be inserted, |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs.


### OH_ArkUI_NodeContent_RegisterCallback()

```
int32_t OH_ArkUI_NodeContent_RegisterCallback (ArkUI_NodeContentHandle content, ArkUI_NodeContentCallback callback )
```
**Description**

Registers the NodeContent event function.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| content | NodeContent object for which an event needs to be registered. |
| callback | Function callback to be executed when an event is triggered. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs.


### OH_ArkUI_NodeContent_RemoveNode()

```
int32_t OH_ArkUI_NodeContent_RemoveNode (ArkUI_NodeContentHandle content, ArkUI_NodeHandle node )
```
**Description**

Removes an ArkUI component node from the specified NodeContent object.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| content | NodeContent object of the node to be deleted. |
| node | Node to be deleted. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs.


### OH_ArkUI_NodeContent_SetUserData()

```
int32_t OH_ArkUI_NodeContent_SetUserData (ArkUI_NodeContentHandle content, void * userData )
```
**Description**

Saves user-defined data on the NodeContent object.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| content | NodeContent object whose user-defined data needs to be saved. |
| userData | User-defined data to be saved. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs.


### OH_ArkUI_NodeContentEvent_GetEventType()

```
ArkUI_NodeContentEventType OH_ArkUI_NodeContentEvent_GetEventType (ArkUI_NodeContentEvent * event)
```
**Description**

Obtains the type of the specified NodeContent event.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| event | Pointer to the NodeContent event. |

**Returns**

NodeContent event type.


### OH_ArkUI_NodeContentEvent_GetNodeContentHandle()

```
ArkUI_NodeContentHandle OH_ArkUI_NodeContentEvent_GetNodeContentHandle (ArkUI_NodeContentEvent * event)
```
**Description**

Obtains the object that triggers the specified NodeContent event.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| event | Pointer to the NodeContent event. |

**Returns**

Returns the NodeContent object that triggers the event.


### OH_ArkUI_NodeCustomEvent_GetCustomSpanDrawInfo()

```
int32_t OH_ArkUI_NodeCustomEvent_GetCustomSpanDrawInfo (ArkUI_NodeCustomEvent * event, ArkUI_CustomSpanDrawInfo * info )
```
**Description**

Obtains the drawing information of a custom span through a custom component event.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| event | Pointer to the custom component event. |
| info | Drawing information to obtain. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs. A possible cause is that mandatory parameters are left unspecified.


### OH_ArkUI_NodeCustomEvent_GetCustomSpanMeasureInfo()

```
int32_t OH_ArkUI_NodeCustomEvent_GetCustomSpanMeasureInfo (ArkUI_NodeCustomEvent * event, ArkUI_CustomSpanMeasureInfo * info )
```
**Description**

Obtains the measurement information of a custom span through a custom component event.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| event | Pointer to the custom component event. |
| info | Measurement information to obtain. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs. A possible cause is that mandatory parameters are left unspecified.


### OH_ArkUI_NodeCustomEvent_GetDrawContextInDraw()

```
ArkUI_DrawContext* OH_ArkUI_NodeCustomEvent_GetDrawContextInDraw (ArkUI_NodeCustomEvent * event)

```

**Description**

Obtains the drawing context through a custom component event.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| event | Pointer to the custom component event. |

**Returns**

Returns the drawing context.


### OH_ArkUI_NodeCustomEvent_GetEventTargetId()

```
int32_t OH_ArkUI_NodeCustomEvent_GetEventTargetId (ArkUI_NodeCustomEvent * event)
```
**Description**

Obtains the ID of a custom component event.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| event | Pointer to the custom component event. |

**Returns**

Returns the custom event ID.


### OH_ArkUI_NodeCustomEvent_GetEventType()

```
ArkUI_NodeCustomEventType OH_ArkUI_NodeCustomEvent_GetEventType (ArkUI_NodeCustomEvent * event)
```
**Description**

Obtains the event type through a custom component event.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| event | Pointer to the custom component event. |

**Returns**

Returns the type of the custom component event.


### OH_ArkUI_NodeCustomEvent_GetLayoutConstraintInMeasure()

```
ArkUI_LayoutConstraint* OH_ArkUI_NodeCustomEvent_GetLayoutConstraintInMeasure (ArkUI_NodeCustomEvent * event)

```

**Description**

Obtains the size constraint for measurement through a custom component event.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| event | Pointer to the custom component event. |

**Returns**

Pointer to the constraint size.


### OH_ArkUI_NodeCustomEvent_GetNodeHandle()

```
ArkUI_NodeHandle OH_ArkUI_NodeCustomEvent_GetNodeHandle (ArkUI_NodeCustomEvent * event)
```
**Description**

Obtains a component object through a custom component event.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| event | Pointer to the custom component event. |

**Returns**

Returns the obtained component object.


### OH_ArkUI_NodeCustomEvent_GetPositionInLayout()

```
ArkUI_IntOffset OH_ArkUI_NodeCustomEvent_GetPositionInLayout (ArkUI_NodeCustomEvent * event)
```
**Description**

Obtains the expected position of a component relative to its parent component in the layout phase through a custom component event.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| event | Pointer to the custom component event. |

**Returns**

Returns the expected position relative to the parent component.


### OH_ArkUI_NodeCustomEvent_GetUserData()

```
void* OH_ArkUI_NodeCustomEvent_GetUserData (ArkUI_NodeCustomEvent * event)
```
**Description**

Obtains custom event parameters through a custom component event.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| event | Pointer to the custom component event. |

**Returns**

Returns the custom event parameters.


### OH_ArkUI_NodeCustomEvent_SetCustomSpanMetrics()

```
int32_t OH_ArkUI_NodeCustomEvent_SetCustomSpanMetrics (ArkUI_NodeCustomEvent * event, ArkUI_CustomSpanMetrics * metrics )
```
**Description**

Sets the measurement metrics of a custom span through a custom component event.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| event | Pointer to the custom component event. |
| metrics | Measurement metrics to set. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs. A possible cause is that mandatory parameters are left unspecified.


### OH_ArkUI_NodeEvent_GetDragEvent()

```
ArkUI_DragEvent* OH_ArkUI_NodeEvent_GetDragEvent (ArkUI_NodeEvent * nodeEvent)
```
**Description**

Obtains an **ArkUI_DragEvent** object from the specified **ArkUI_DragEvent** object.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| node | Pointer to an **ArkUI_NodeEvent** object. |

**Returns**

Returns the pointer to an **ArkUI_DragEvent** object; returns null if the parameter passed in is invalid or is not a drag-related event.


### OH_ArkUI_NodeEvent_GetEventType()

```
ArkUI_NodeEventType OH_ArkUI_NodeEvent_GetEventType (ArkUI_NodeEvent * event)
```
**Description**

Obtains the type of a component event.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| event | Pointer to the component event. |

**Returns**

Returns the type of the component event.


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

Returns the pointer to the input event data.


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

Returns the pointer to the numerical data.


### OH_ArkUI_NodeEvent_GetNodeHandle()

```
ArkUI_NodeHandle OH_ArkUI_NodeEvent_GetNodeHandle (ArkUI_NodeEvent * event)

```

**Description**

Obtains the component object that triggers an event.

**Since**: 12

**Parameters**

| Name  | Description                     |
| ----- | ------------------------------- |
| event | Pointer to the component event. |

**Returns**

ArkUI_NodeHandle Component object that triggers the event.


### OH_ArkUI_NodeEvent_GetNumberValue()

```
int32_t OH_ArkUI_NodeEvent_GetNumberValue (ArkUI_NodeEvent * event, int32_t index, ArkUI_NumberValue * value )

```

**Description**

Obtains the numeric-type parameter of a component event.

**Since**: 12

**Parameters**

| Name  | Description                     |
| ----- | ------------------------------- |
| event | Pointer to the component event. |
| index | Return value index.             |
| value | Return value.                   |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_NODE_EVENT_PARAM_INDEX_OUT_OF_RANGE** if the parameter length in the parameter event exceeds the limit. Returns **ARKUI_ERROR_CODE_NODE_EVENT_PARAM_INVALID** if the data does not exist in the component event.


### OH_ArkUI_NodeEvent_GetPreDragStatus()

```
ArkUI_PreDragStatus OH_ArkUI_NodeEvent_GetPreDragStatus (ArkUI_NodeEvent * nodeEvent)

```

**Description**

Obtains the state prior to a drop and drop operation.

**Since**: 12

**Parameters**

| Name | Description                  |
| ---- | ---------------------------- |
| node | ArkUI_NodeEvent node object. |

**Returns**

Returns the state prior to the drop and drop operation.


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

ArkUI_StringAsyncEvent\Pointer to string data.


### OH_ArkUI_NodeEvent_GetStringValue()

```
int32_t OH_ArkUI_NodeEvent_GetStringValue (ArkUI_NodeEvent * event, int32_t index, char ** string, int32_t * stringSize )

```

**Description**

Obtains the string-type parameter of the component callback event. The string data is valid only during event callback and needs to be used outside event callback. You are advised to copy the string data.

**Since**: 12

**Parameters**

| Name       | Description                     |
| ---------- | ------------------------------- |
| event      | Pointer to the component event. |
| index      | Return value index.             |
| string     | Pointer to the string array.    |
| stringSize | Length of the string array.     |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_NODE_EVENT_PARAM_INDEX_OUT_OF_RANGE** if the parameter length in the parameter event exceeds the limit. Returns **ARKUI_ERROR_CODE_NODE_EVENT_PARAM_INVALID** if the data does not exist in the component event.


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

Returns the custom ID of the component event.


### OH_ArkUI_NodeEvent_GetUserData()

```
void* OH_ArkUI_NodeEvent_GetUserData (ArkUI_NodeEvent * event)

```

**Description**

Obtains the custom data in a component event.

This parameter is passed in **registerNodeEvent** and can be applied to the service logic when the event is triggered.

**Since**: 12

**Parameters**

| Name  | Description                     |
| ----- | ------------------------------- |
| event | Pointer to the component event. |

**Returns**

Returns the pointer to user data.


### OH_ArkUI_NodeEvent_SetReturnNumberValue()

```
int32_t OH_ArkUI_NodeEvent_SetReturnNumberValue (ArkUI_NodeEvent * event, ArkUI_NumberValue * value, int32_t size )

```

**Description**

Sets the return value for a component event.

**Since**: 12

**Parameters**

| Name  | Description                     |
| ----- | ------------------------------- |
| event | Pointer to the component event. |
| value | Event numeric type array.       |
| size  | Size of the array.              |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. The component event does not support return values. Returns **ARKUI_ERROR_CODE_NODE_EVENT_PARAM_INVALID** if the data does not exist in the component event.


### OH_ArkUI_NodeUtils_GetLayoutPosition()

```
int32_t OH_ArkUI_NodeUtils_GetLayoutPosition (ArkUI_NodeHandle node, ArkUI_IntOffset * localOffset )
```
**Description**

Obtains the position of the component's layout area relative to its parent component. The relative position does not count in transformation attributes, such as translate.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| node | **ArkUI_NodeHandle** pointer. |
| localOffset | Offset of the component handle relative to the parent component, in pixels. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs.


### OH_ArkUI_NodeUtils_GetLayoutPositionInScreen()

```
int32_t OH_ArkUI_NodeUtils_GetLayoutPositionInScreen (ArkUI_NodeHandle node, ArkUI_IntOffset * screenOffset )
```
**Description**

Obtains the position of the component's layout area relative to the screen. The relative position does not count in transformation attributes, such as translate.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| node | **ArkUI_NodeHandle** pointer. |
| screenOffset | Offset of the component handle relative to the screen, in pixels. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs.


### OH_ArkUI_NodeUtils_GetLayoutPositionInWindow()

```
int32_t OH_ArkUI_NodeUtils_GetLayoutPositionInWindow (ArkUI_NodeHandle node, ArkUI_IntOffset * globalOffset )
```
**Description**

Obtains the position of the component's layout area relative to the window. The relative position does not count in transformation attributes, such as translate.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| node | **ArkUI_NodeHandle** pointer. |
| globalOffset | Offset of the component handle relative to the window, in pixels. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs.


### OH_ArkUI_NodeUtils_GetLayoutSize()

```
int32_t OH_ArkUI_NodeUtils_GetLayoutSize (ArkUI_NodeHandle node, ArkUI_IntSize * size )
```
**Description**

Obtains the layout area size of a component. The size does not count in transformation attributes, such as scale.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| node | **ArkUI_NodeHandle** pointer. |
| size | Size of the layout area, in px. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs.


### OH_ArkUI_NodeUtils_GetPositionWithTranslateInScreen()

```
int32_t OH_ArkUI_NodeUtils_GetPositionWithTranslateInScreen (ArkUI_NodeHandle node, ArkUI_IntOffset * translateOffset )
```
**Description**

Obtains the position of a component on the screen, including the translate attribute.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| node | **ArkUI_NodeHandle** pointer. |
| translateOffset | Accumulated offset of the component, its parent component, and its ancestor node, in px. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs.


### OH_ArkUI_NodeUtils_GetPositionWithTranslateInWindow()

```
int32_t OH_ArkUI_NodeUtils_GetPositionWithTranslateInWindow (ArkUI_NodeHandle node, ArkUI_IntOffset * translateOffset )
```

**Description**

Obtains the position of a component in the window, including the translate attribute.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| node | **ArkUI_NodeHandle** pointer. |
| translateOffset | Accumulated offset of the component, its parent component, and its ancestor node, in px. |

**Returns**

 Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs.

### OH_ArkUI_PanGesture_GetOffsetX()

```
float OH_ArkUI_PanGesture_GetOffsetX (const ArkUI_GestureEvent * event)

```

**Description**

Obtains the relative offset of a pan gesture along the x-axis.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| event | Gesture event. |

**Returns**

Returns the relative offset of the gesture along the x-axis, in px.

### OH_ArkUI_PanGesture_GetOffsetY()

```
float OH_ArkUI_PanGesture_GetOffsetY (const ArkUI_GestureEvent * event)
```
**Description**

Obtains the relative offset of a pan gesture along the y-axis.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| event | Gesture event. |

**Returns**

Returns the relative offset of the gesture along the y-axis, in px.

### OH_ArkUI_PanGesture_GetVelocity()

```
float OH_ArkUI_PanGesture_GetVelocity (const ArkUI_GestureEvent * event)

```

**Description**

Obtains the velocity of a pan gesture along the main axis.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| event | Gesture event. |

**Returns**

Returns the velocity of the pan gesture along the main axis, in px/s. The value is the square root of the sum of the squares of the velocity on the x-axis and y-axis.


### OH_ArkUI_PanGesture_GetVelocityX()

```
float OH_ArkUI_PanGesture_GetVelocityX (const ArkUI_GestureEvent * event)

```

**Description**

Obtains the velocity of a pan gesture along the x-axis.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| event | Gesture event. |

**Returns**

Returns the velocity of the pan gesture along the x-axis, in px/s.


### OH_ArkUI_PanGesture_GetVelocityY()

```
float OH_ArkUI_PanGesture_GetVelocityY (const ArkUI_GestureEvent * event)

```

**Description**

Obtains the velocity of a pan gesture along the y-axis.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| event | Gesture event. |

**Returns**

Returns the velocity of the pan gesture along the y-axis, in px/s.


### OH_ArkUI_ParallelInnerGestureEvent_GetConflictRecognizers()

```
int32_t OH_ArkUI_ParallelInnerGestureEvent_GetConflictRecognizers (ArkUI_ParallelInnerGestureEvent * event, ArkUI_GestureRecognizerHandleArray * array, int32_t * size )

```

**Description**

Obtains the conflicting gesture recognizers in a parallel internal gesture event.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| event | Parallel internal gesture event. |
| array | Array of conflicting gesture recognizers. |
| size | Size of the conflicting gesture recognizer array. |

**Returns**

Returns **0** if the operation is successful. Returns **401** if a parameter error occurs.


### OH_ArkUI_ParallelInnerGestureEvent_GetCurrentRecognizer()

```
ArkUI_GestureRecognizer* OH_ArkUI_ParallelInnerGestureEvent_GetCurrentRecognizer (ArkUI_ParallelInnerGestureEvent * event)

```

**Description**

Obtains the current gesture recognizer in a parallel internal gesture event.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| event | Parallel internal gesture event. |

**Returns**

Returns the pointer to the current gesture recognizer.


### OH_ArkUI_ParallelInnerGestureEvent_GetUserData()

```
void* OH_ArkUI_ParallelInnerGestureEvent_GetUserData (ArkUI_ParallelInnerGestureEvent * event)

```

**Description**

Obtains custom data in the parallel internal gesture event.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| event | Parallel internal gesture event. |

**Returns**

Returns the pointer to custom data.


### OH_ArkUI_PinchGesture_GetCenterX()

```
float OH_ArkUI_PinchGesture_GetCenterX (const ArkUI_GestureEvent * event)

```

**Description**

Obtains the X coordinate of the center of the pinch gesture, in vp, relative to the upper left corner of the current component.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| event | Gesture event. |

**Returns**

Returns the X coordinate of the center of the pinch gesture, in vp, relative to the upper left corner of the current component.


### OH_ArkUI_PinchGesture_GetCenterY()

```
float OH_ArkUI_PinchGesture_GetCenterY (const ArkUI_GestureEvent * event)

```

**Description**

Obtains the Y coordinate of the center of the pinch gesture, in vp, relative to the upper left corner of the current component.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| event | Gesture event. |

**Returns**

Returns the Y coordinate of the center of the pinch gesture, in vp, relative to the upper left corner of the current component.


### OH_ArkUI_PinchGesture_GetScale()

```
float OH_ArkUI_PinchGesture_GetScale (const ArkUI_GestureEvent * event)

```

**Description**

Obtains the scale ratio of a pinch gesture.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| event | Gesture event. |

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

| Name| Description|
| -------- | -------- |
| type | Type of the native API set provided by ArkUI, for example, **ARKUI_NATIVE_NODE** or **ARKUI_NATIVE_GESTURE**. |
| sturctName | Name of a native struct defined in the corresponding header file, for example, **ArkUI_NativeNodeAPI_1** in &lt;arkui/native_node.h&gt. |

**Returns**

Returns the pointer to the abstract native API, which can be used after being converted into a specific type. \#include&lt;arkui/native_interface.h&gt; \#include&lt;arkui/native_node.h&gt; \#include&lt;arkui/native_gesture.h&gt; auto\* anyNativeAPI = [OH_ArkUI_QueryModuleInterfaceByName](#oh_arkui_querymoduleinterfacebyname)(ARKUI_NATIVE_NODE, "ArkUI_NativeNodeAPI_1"); if (anyNativeAPI) { auto nativeNodeApi = reinterpret_cast&lt;[ArkUI_NativeNodeAPI_1](_ark_u_i___native_node_a_p_i__1.md)\*&gt;(anyNativeAPI); } auto anyGestureAPI = OH_ArkUI_QueryModuleInterface(ARKUI_NATIVE_GESTURE, "ArkUI_NativeGestureAPI_1"); if (anyNativeAPI) { auto basicGestureApi = reinterpret_cast&lt;[ArkUI_NativeGestureAPI_1](_ark_u_i___native_gesture_a_p_i__1.md)\*&gt;(anyGestureAPI); }


### OH_ArkUI_RegisterSystemColorModeChangeEvent()

```
int32_t OH_ArkUI_RegisterSystemColorModeChangeEvent (ArkUI_NodeHandle node, void * userData, void(*)(ArkUI_SystemColorMode colorMode, void *userData) onColorModeChange )
```
**Description**

Registers an event listener for system color mode changes. A single component can only register one callback for system color mode changes.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| node | Specified node. |
| userData | Custom event parameter, which is passed in the callback when the event is triggered. |
| onColorModeChange | Callback to be executed when the event is triggered. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs. Returns **ARKUI_ERROR_CODE_ATTRIBUTE_OR_EVENT_NOT_SUPPORTED** if the event is not supported.


### OH_ArkUI_RegisterSystemFontStyleChangeEvent()

```
int32_t OH_ArkUI_RegisterSystemFontStyleChangeEvent (ArkUI_NodeHandle node, void * userData, void(*)(ArkUI_SystemFontStyleEvent *event, void *userData) onFontStyleChange )
```
**Description**

Registers an event listener for system font style changes. A single component can only register one callback for system font style changes.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| node | Specified node. |
| userData | Custom event parameter, which is passed in the callback when the event is triggered. |
| onFontStyleChange | Callback to be executed when the event is triggered. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs. Returns **ARKUI_ERROR_CODE_ATTRIBUTE_OR_EVENT_NOT_SUPPORTED** if the event is not supported.


### OH_ArkUI_RotationGesture_GetAngle()

```
float OH_ArkUI_RotationGesture_GetAngle (const ArkUI_GestureEvent * event)

```

**Description**

Obtains the angle information of a rotation gesture.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| event | Gesture event. |

**Returns**

Rotation angle.


### OH_ArkUI_SetArkUIGestureRecognizerDisposeNotify()

```
int32_t OH_ArkUI_SetArkUIGestureRecognizerDisposeNotify (ArkUI_GestureRecognizer * recognizer, ArkUI_GestureRecognizerDestructNotifyCallback callback, void * userData )
```
**Description**

Sets a callback function for notifying gesture recognizer destruction.

**Parameters**

| Name| Description|
| -------- | -------- |
| recognizer | Pointer to the gesture recognizer. |
| callback | Callback function for notifying gesture recognizer destruction. |
| userData | Custom data. |

**Returns**

Returns **0** if the operation is successful. Returns **401** if a parameter error occurs.


### OH_ArkUI_SetDragEventStrictReportWithContext()

```
int32_t OH_ArkUI_SetDragEventStrictReportWithContext (ArkUI_ContextHandle uiContext, bool enabled )
```
**Description**

Sets whether to enable strict reporting on drag events. This feature is disabled by default, and you are advised to enable it. If this feature is disabled, the parent component is not notified when an item in it is dragged over its child component. If this feature is enabled, the component is notified of the dragged item's leaving, and the child component to which the dragged item is dropped is notified of the item's entering. This configuration is related to a specific UI instance. You can pass in a UI instance for association.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| uiContext | Pointer to the UI instance. |
| enabled | Whether to enable strict reporting on drag events. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs.


### OH_ArkUI_SetDragEventStrictReportWithNode()

```
int32_t OH_ArkUI_SetDragEventStrictReportWithNode (ArkUI_NodeHandle node, bool enabled )
```
**Description**

Sets whether to enable strict reporting on drag events. This feature is disabled by default, and you are advised to enable it. If this feature is disabled, the parent component is not notified when an item in it is dragged over its child component. If this feature is enabled, the component is notified of the dragged item's leaving, and the child component to which the dragged item is dropped is notified of the item's entering. This configuration is related to a specific UI instance. You can pass in a specific component node on the current UI instance for association.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| node | Pointer to a component node. |
| enabled | Whether to enable strict reporting on drag events. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs.


### OH_ArkUI_SetGestureRecognizerEnabled()

```
int32_t OH_ArkUI_SetGestureRecognizerEnabled (ArkUI_GestureRecognizer * recognizer, bool enabled )
```
**Description**

Sets the enabled state of a gesture recognizer.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| recognizer | Pointer to the gesture recognizer. |
| enabled | Whether to enable notification. |

**Returns**

Returns **0** if the operation is successful. Returns **401** if a parameter error occurs.


### OH_ArkUI_SetNodeAllowedDropDataTypes()

```
int32_t OH_ArkUI_SetNodeAllowedDropDataTypes (ArkUI_NodeHandle node, const char * typesArray[], int32_t count )
```
**Description**

Sets the types of data that can be dropped to the specified component. This API resets the settings configured through [OH_ArkUI_DisallowNodeAnyDropDataTypes](#oh_arkui_disallownodeanydropdatatypes) or [OH_ArkUI_AllowNodeAllDropDataTypes](#oh_arkui_allownodealldropdatatypes).

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| node | Pointer to a component node. |
| typesArray | Array of data types that can fall into. |
| count | Length of an array. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs.


### OH_ArkUI_SetNodeDraggable()

```
int32_t OH_ArkUI_SetNodeDraggable (ArkUI_NodeHandle node, bool enabled )
```
**Description**

Sets whether the component is draggable.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| node | Pointer to a component node. |
| bool | Whether the component is draggable. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs.


### OH_ArkUI_SetNodeDragPreview()

```
int32_t OH_ArkUI_SetNodeDragPreview (ArkUI_NodeHandle node, OH_PixelmapNative * preview )
```
**Description**

Sets a custom drag preview for the specified component.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| node | Pointer to the target component node. |
| preview | Custom drag preview, which is a pixel map. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs.


### OH_ArkUI_SetNodeDragPreviewOption()

```
int32_t OH_ArkUI_SetNodeDragPreviewOption (ArkUI_NodeHandle node, ArkUI_DragPreviewOption * option )
```
**Description**

Sets an **ArkUI_DragPreviewOption** object for the specified component.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| node | Pointer to a component node. |
| option | Custom parameters. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs.


### OH_ArkUI_StartDrag()

```
int32_t OH_ArkUI_StartDrag (ArkUI_DragAction * dragAction)
```
**Description**

Initiates a drag action through the specified drag action object.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| dragAction | Drag action object. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs.


### OH_ArkUI_StyledString_AddPlaceholder()

```
void OH_ArkUI_StyledString_AddPlaceholder (ArkUI_StyledString * handle, OH_Drawing_PlaceholderSpan * placeholder )
```
**Description**

Adds a placeholder. 

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| handle | Pointer to an **ArkUI_StyledString** object. |
| placeholder | Pointer to an **OH_Drawing_PlaceholderSpan** object. |


### OH_ArkUI_StyledString_AddText()

```
void OH_ArkUI_StyledString_AddText (ArkUI_StyledString * handle, const char * content )
```
**Description**

Sets the text content based on the current format string style.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| handle | Pointer to an **ArkUI_StyledString** object. |
| content | Pointer to the text content. |


### OH_ArkUI_StyledString_Create()

```
ArkUI_StyledString* OH_ArkUI_StyledString_Create (OH_Drawing_TypographyStyle * style, OH_Drawing_FontCollection * collection )
```
**Description**

Creates an **ArkUI_StyledString** object.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| style | Pointer to an **OH_Drawing_TypographyStyle** object, which is obtained by calling **OH_Drawing_CreateTypographyStyle**. |
| collection | Pointer to an **OH_Drawing_FontCollection** object, which is obtained by calling **OH_Drawing_CreateFontCollection**. |

**Returns**

Returns the pointer to the **ArkUI_StyledString** object created. If a null pointer is returned, the creation fails. A possible cause is that the application address space is full, or a parameter error, for example, a null pointer for the **style** or **collection** parameter, occurs.


### OH_ArkUI_StyledString_CreateTypography()

```
OH_Drawing_Typography* OH_ArkUI_StyledString_CreateTypography (ArkUI_StyledString * handle)
```
**Description**

Creates an **OH_Drawing_Typography** object based on an **ArkUI_StyledString** object.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| handle | Pointer to an **ArkUI_StyledString** object. |

**Returns**

Returns the pointer to the **OH_Drawing_Typography** object created. If a null pointer is returned, the creation fails. A possible cause is that a parameter error, for example, a null pointer for the **handle** parameter, occurs.


### OH_ArkUI_StyledString_Destroy()

```
void OH_ArkUI_StyledString_Destroy (ArkUI_StyledString * handle)
```
**Description**

Destroys an **OH_Drawing_TextStyle** object and reclaims the memory occupied by the object.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| handle | Pointer to an **ArkUI_StyledString** object. |


### OH_ArkUI_StyledString_PopTextStyle()

```
void OH_ArkUI_StyledString_PopTextStyle (ArkUI_StyledString * handle)
```
**Description**

Removes the top style from the current formatted string object.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| handle | Pointer to an **ArkUI_StyledString** object. |


### OH_ArkUI_StyledString_PushTextStyle()

```
void OH_ArkUI_StyledString_PushTextStyle (ArkUI_StyledString * handle, OH_Drawing_TextStyle * style )
```
**Description**

Sets the new typesetting style to the top of the current format string style stack.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| handle | Pointer to an **ArkUI_StyledString** object. |
| style | Pointer to an **OH_Drawing_TextStyle** object. |


### OH_ArkUI_SwipeGesture_GetAngle()

```
float OH_ArkUI_SwipeGesture_GetAngle (const ArkUI_GestureEvent * event)
```
**Description**

Obtains the angle information of the swipe gesture.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| event | Gesture event. |

**Returns**

Returns the angle of the swipe gesture, which is the result obtained based on the aforementioned formula.


### OH_ArkUI_SwipeGesture_GetVelocity()

```
float OH_ArkUI_SwipeGesture_GetVelocity (const ArkUI_GestureEvent * event)
```
**Description**

Obtains the average velocity of all fingers used in the swipe gesture.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| event | Gesture event. |

**Returns**

Returns the average velocity of all fingers used in the swipe gesture, in px/s.


### OH_ArkUI_SwiperIndicator_Create()

```
ArkUI_SwiperIndicator* OH_ArkUI_SwiperIndicator_Create (ArkUI_SwiperIndicatorType type)
```
**Description**

Creates a navigation indicator for the Swiper component.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| type | Type of the navigation indicator. |

**Returns**

Returns the pointer to the navigation point indicator.


### OH_ArkUI_SwiperIndicator_Dispose()

```
void OH_ArkUI_SwiperIndicator_Dispose (ArkUI_SwiperIndicator * indicator)
```
**Description**

Disposes of the navigation point indicator of this **Swiper** component.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| indicator | Returns the pointer to the navigation point indicator. |


### OH_ArkUI_SwiperIndicator_GetBottomPosition()

```
float OH_ArkUI_SwiperIndicator_GetBottomPosition (ArkUI_SwiperIndicator * indicator)
```
**Description**

Obtains the distance between the navigation point indicator and the bottom edge of the **Swiper** component.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| indicator | Returns the pointer to the navigation point indicator. |

**Returns**

Returns the distance between a navigation point indicator and the bottom edge of the **Swiper** component.


### OH_ArkUI_SwiperIndicator_GetColor()

```
uint32_t OH_ArkUI_SwiperIndicator_GetColor (ArkUI_SwiperIndicator * indicator)
```
**Description**

Obtains the color of a navigation point indicator of the dot style of the **Swiper** component.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| indicator | Returns the pointer to the navigation point indicator. |

**Returns**

Returns the color, in 0xARGB format. For example, 0xFFFF0000 indicates red.


### OH_ArkUI_SwiperIndicator_GetEndPosition()

```
float OH_ArkUI_SwiperIndicator_GetEndPosition (ArkUI_SwiperIndicator * indicator)
```
**Description**

Obtains the distance between a navigation point indicator and the right edge of the **Swiper** component.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| indicator | Returns the pointer to the navigation point indicator. |

**Returns**

Returns the distance between the navigation point indicator and the right edge of the **Swiper** component.


### OH_ArkUI_SwiperIndicator_GetItemHeight()

```
float OH_ArkUI_SwiperIndicator_GetItemHeight (ArkUI_SwiperIndicator * indicator)
```
**Description**

Obtains the height of a navigation point indicator of the dot style of the **Swiper** component.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| indicator | Returns the pointer to the navigation point indicator. |

**Returns**

Returns the height of the navigation point indicator of the dot style.


### OH_ArkUI_SwiperIndicator_GetItemWidth()

```
float OH_ArkUI_SwiperIndicator_GetItemWidth (ArkUI_SwiperIndicator * indicator)
```
**Description**

Obtains the width of a navigation point indicator of the dot style of the **Swiper** component.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| indicator | Returns the pointer to the navigation point indicator. |

**Returns**

Returns the width of the navigation point indicator of the dot style.


### OH_ArkUI_SwiperIndicator_GetMask()

```
int32_t OH_ArkUI_SwiperIndicator_GetMask (ArkUI_SwiperIndicator * indicator)
```
**Description**

Obtains whether the mask is enabled for a navigation point indicator of the dot style of the **Swiper** component.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| indicator | Returns the pointer to the navigation point indicator. |

**Returns**

Returns **1** if the mask is enabled; returns **0** otherwise.


### OH_ArkUI_SwiperIndicator_GetMaxDisplayCount()

```
int32_t OH_ArkUI_SwiperIndicator_GetMaxDisplayCount (ArkUI_SwiperIndicator * indicator)
```
**Description**

Obtains the maximum number of dots for the navigation point indicator of the dot style.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| indicator | Pointer to the navigation point indicator. |

**Returns**

Returns the maximum number of dots. The value ranges from 6 to 9.


### OH_ArkUI_SwiperIndicator_GetSelectedColor()

```
uint32_t OH_ArkUI_SwiperIndicator_GetSelectedColor (ArkUI_SwiperIndicator * indicator)
```
**Description**

Obtains the color of the selected navigation point indicator of the dot style of the **Swiper** component.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| indicator | Returns the pointer to the navigation point indicator. |

**Returns**

Returns the color, in 0xARGB format. For example, 0xFFFF0000 indicates red.


### OH_ArkUI_SwiperIndicator_GetSelectedItemHeight()

```
float OH_ArkUI_SwiperIndicator_GetSelectedItemHeight (ArkUI_SwiperIndicator * indicator)
```
**Description**

Obtains the height of the selected navigation point indicator of the dot style of the **Swiper** component.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| indicator | Returns the pointer to the navigation point indicator. |

**Returns**

Returns the height of the navigation point indicator of the dot style.


### OH_ArkUI_SwiperIndicator_GetSelectedItemWidth()

```
float OH_ArkUI_SwiperIndicator_GetSelectedItemWidth (ArkUI_SwiperIndicator * indicator)
```
**Description**

Obtains the width of the selected navigation point indicator of the dot style of the **Swiper** component.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| indicator | Returns the pointer to the navigation point indicator. |

**Returns**

Returns the width of the navigation point indicator of the dot style.


### OH_ArkUI_SwiperIndicator_GetStartPosition()

```
float OH_ArkUI_SwiperIndicator_GetStartPosition (ArkUI_SwiperIndicator * indicator)
```
**Description**

Obtains the distance between a navigation point indicator and the left edge of the **Swiper** component.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| indicator | Returns the pointer to the navigation point indicator. |

**Returns**

Returns the distance between the navigation point indicator and the left edge of the **Swiper** component.


### OH_ArkUI_SwiperIndicator_GetTopPosition()

```
float OH_ArkUI_SwiperIndicator_GetTopPosition (ArkUI_SwiperIndicator * indicator)
```
**Description**

Obtains the distance between the navigation point indicator and the top edge of the **Swiper** component.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| indicator | Returns the pointer to the navigation point indicator. |

**Returns**

Returns the distance between a navigation point indicator and the top edge of the **Swiper** component.


### OH_ArkUI_SwiperIndicator_SetBottomPosition()

```
void OH_ArkUI_SwiperIndicator_SetBottomPosition (ArkUI_SwiperIndicator * indicator, float value )
```
**Description**

Distance between the navigation point indicator and the bottom edge of the **Swiper** component.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| indicator | Returns the pointer to the navigation point indicator. |
| value | Returns the distance between a navigation point indicator and the bottom edge of the **Swiper** component. |


### OH_ArkUI_SwiperIndicator_SetColor()

```
void OH_ArkUI_SwiperIndicator_SetColor (ArkUI_SwiperIndicator * indicator, uint32_t color )
```
**Description**

Sets the color of a navigation point indicator of the dot style for the **Swiper** component.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| indicator | Returns the pointer to the navigation point indicator. |
| color | Returns the color, in 0xARGB format. For example, 0xFFFF0000 indicates red. |


### OH_ArkUI_SwiperIndicator_SetEndPosition()

```
void OH_ArkUI_SwiperIndicator_SetEndPosition (ArkUI_SwiperIndicator * indicator, float value )
```
**Description**

Distance between the navigation point indicator and the left edge of the **Swiper** component.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| indicator | Returns the pointer to the navigation point indicator. |
| value | Returns the distance between the navigation point indicator and the right edge of the **Swiper** component. |


### OH_ArkUI_SwiperIndicator_SetItemHeight()

```
void OH_ArkUI_SwiperIndicator_SetItemHeight (ArkUI_SwiperIndicator * indicator, float value )
```
**Description**

Sets the height of a navigation point indicator of the dot style for the **Swiper** component.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| indicator | Returns the pointer to the navigation point indicator. |
| value | Returns the height of the navigation point indicator of the dot style. |


### OH_ArkUI_SwiperIndicator_SetItemWidth()

```
void OH_ArkUI_SwiperIndicator_SetItemWidth (ArkUI_SwiperIndicator * indicator, float value )
```
**Description**

Sets the width of a navigation point indicator of the dot style for the **Swiper** component.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| indicator | Returns the pointer to the navigation point indicator. |
| value | Returns the width of the navigation point indicator of the dot style. |


### OH_ArkUI_SwiperIndicator_SetMask()

```
void OH_ArkUI_SwiperIndicator_SetMask (ArkUI_SwiperIndicator * indicator, int32_t mask )
```
**Description**

Sets whether to enable the mask for a navigation point indicator of the dot style for the **Swiper** component.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| indicator | Pointer to a navigation point indicator. |
| mask | Whether to enable the mask. The value **1** means to enable the mask, and **0** means the opposite. |


### OH_ArkUI_SwiperIndicator_SetMaxDisplayCount()

```
int32_t OH_ArkUI_SwiperIndicator_SetMaxDisplayCount (ArkUI_SwiperIndicator * indicator, int32_t maxDisplayCount )
```
**Description**

Sets the maximum number of dots for the navigation point indicator of the dot style.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| indicator | Pointer to a navigation point indicator. |
| maxDisplayCount | Maximum number of navigation points. The value ranges from 6 to 9. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if **maxDisplayCount** is set to an invalid value.


### OH_ArkUI_SwiperIndicator_SetSelectedColor()

```
void OH_ArkUI_SwiperIndicator_SetSelectedColor (ArkUI_SwiperIndicator * indicator, uint32_t selectedColor )
```
**Description**

Sets the color of the selected navigation point indicator of the dot style for the **Swiper** component.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| indicator | Pointer to a navigation point indicator. |
| selectedColor | Color, in 0xARGB format. For example, 0xFFFF0000 indicates red. |


### OH_ArkUI_SwiperIndicator_SetSelectedItemHeight()

```
void OH_ArkUI_SwiperIndicator_SetSelectedItemHeight (ArkUI_SwiperIndicator * indicator, float value )
```
**Description**

Sets the height of the selected navigation point indicator of the dot style for the **Swiper** component.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| indicator | Pointer to a navigation point indicator. |
| value | Height of the navigation point indicator of the dot style. |


### OH_ArkUI_SwiperIndicator_SetSelectedItemWidth()

```
void OH_ArkUI_SwiperIndicator_SetSelectedItemWidth (ArkUI_SwiperIndicator * indicator, float value )
```
**Description**

Sets the width of the selected navigation point indicator of the dot style for the **Swiper** component.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| indicator | Pointer to a navigation point indicator. |
| value | Width of the navigation point indicator of the dot style. |


### OH_ArkUI_SwiperIndicator_SetStartPosition()

```
void OH_ArkUI_SwiperIndicator_SetStartPosition (ArkUI_SwiperIndicator * indicator, float value )
```
**Description**

Sets the distance between the navigation point indicator and the left edge of the **Swiper** component.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| indicator | Pointer to a navigation point indicator. |
| value | Distance between the navigation point indicator and the left edge of the **Swiper** component. |


### OH_ArkUI_SwiperIndicator_SetTopPosition()

```
void OH_ArkUI_SwiperIndicator_SetTopPosition (ArkUI_SwiperIndicator * indicator, float value )
```
**Description**

Sets the distance between the navigation point indicator and the top edge of the **Swiper** component.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| indicator | Pointer to a navigation point indicator. |
| value | Distance between a navigation point indicator and the top edge of the **Swiper** component. |


### OH_ArkUI_SystemFontStyleEvent_GetFontSizeScale()

```
float OH_ArkUI_SystemFontStyleEvent_GetFontSizeScale (const ArkUI_SystemFontStyleEvent * event)
```
**Description**

Obtains the font size scale from the system font style change event.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| event | Pointer to the current system font style change event. |

**Returns**

Returns the font size scale after the change. Default value: **1.0**.


### OH_ArkUI_SystemFontStyleEvent_GetFontWeightScale()

```
float OH_ArkUI_SystemFontStyleEvent_GetFontWeightScale (const ArkUI_SystemFontStyleEvent * event)
```
**Description**

Obtains the font weight scale from the system font style change event.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| event | Pointer to the current system font style change event. |

**Returns**

Returns the font weight scale after the change. Default value: **1.0**.


### OH_ArkUI_TransitionEffect_Combine()

```
int32_t OH_ArkUI_TransitionEffect_Combine (ArkUI_TransitionEffect * option, ArkUI_TransitionEffect * combine )
```
**Description**

Sets a combination of transition effects.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Transition effect options. |
| combine | Combination of transition effects. |

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs.


### OH_ArkUI_TransitionEffect_Dispose()

```
void OH_ArkUI_TransitionEffect_Dispose (ArkUI_TransitionEffect * option)
```
**Description**

Destroys a transition effect object.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Transition effect object. |


### OH_ArkUI_TransitionEffect_SetAnimation()

```
int32_t OH_ArkUI_TransitionEffect_SetAnimation (ArkUI_TransitionEffect * option, ArkUI_AnimateOption * animation )
```
**Description**

Sets transition effect animation settings.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Transition effect options. |
| animation | Animation settings. |

**NOTE**

If **combine** is used for combining transition effects, the animation settings of a transition effect are applicable to the one following it.

**Returns**

Returns **ARKUI_ERROR_CODE_NO_ERROR** if the operation is successful. Returns **ARKUI_ERROR_CODE_PARAM_INVALID** if a parameter error occurs.


### OH_ArkUI_UnregisterSystemColorModeChangeEvent()

```
void OH_ArkUI_UnregisterSystemColorModeChangeEvent (ArkUI_NodeHandle node)
```
**Description**

Unregisters the event listener for system color mode changes.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| node | Specified node. |


### OH_ArkUI_UnregisterSystemFontStyleChangeEvent()

```
void OH_ArkUI_UnregisterSystemFontStyleChangeEvent (ArkUI_NodeHandle node)
```
**Description**

Unregisters the event listener for system font style changes.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| node | Specified node. |


### OH_ArkUI_WaterFlowSectionOption_Create()

```
ArkUI_WaterFlowSectionOption* OH_ArkUI_WaterFlowSectionOption_Create ()
```
**Description**

Creates a water flow section configuration.

**Since**: 12

**Returns**

Return the pointer to the created water flow section configuration.


### OH_ArkUI_WaterFlowSectionOption_Dispose()

```
void OH_ArkUI_WaterFlowSectionOption_Dispose (ArkUI_WaterFlowSectionOption * option)
```
**Description**

Disposes of the pointer to a water flow section configuration.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Pointer to a water flow section configuration. |


### OH_ArkUI_WaterFlowSectionOption_GetColumnGap()

```
float OH_ArkUI_WaterFlowSectionOption_GetColumnGap (ArkUI_WaterFlowSectionOption * option, int32_t index )
```
**Description**

Obtains the gap between columns in the water flow section that matches the specified index.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Pointer to a water flow section configuration. |
| index | Index of the target water flow section. |

**Returns**

Column spacing.


### OH_ArkUI_WaterFlowSectionOption_GetCrossCount()

```
int32_t OH_ArkUI_WaterFlowSectionOption_GetCrossCount (ArkUI_WaterFlowSectionOption * option, int32_t index )
```
**Description**

Obtains the number of columns (in a vertical layout) or rows (in a horizontal layout) of a water flow.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Pointer to a water flow section configuration. |
| index | Index of the target water flow section. |

**Returns**

Returns the number of columns (in a vertical layout) or rows (in a horizontal layout) of a water flow.


### OH_ArkUI_WaterFlowSectionOption_GetItemCount()

```
int32_t OH_ArkUI_WaterFlowSectionOption_GetItemCount (ArkUI_WaterFlowSectionOption * option, int32_t index )
```
**Description**

Obtains the number of items in the water flow section that matches the specified index.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Pointer to a water flow section configuration. |
| index | Index of the target water flow section. |

**Returns**

Returns the number of items in the water flow section.


### OH_ArkUI_WaterFlowSectionOption_GetMargin()

```
ArkUI_Margin OH_ArkUI_WaterFlowSectionOption_GetMargin (ArkUI_WaterFlowSectionOption * option, int32_t index )
```
**Description**

Obtains the margins of the water flow section that matches the specified index.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Pointer to a water flow section configuration. |
| index | Index of the target water flow section. |

**Returns**

Returns the margins.


### OH_ArkUI_WaterFlowSectionOption_GetRowGap()

```
float OH_ArkUI_WaterFlowSectionOption_GetRowGap (ArkUI_WaterFlowSectionOption * option, int32_t index )
```
**Description**

Obtains the gap between rows in the water flow section that matches the specified index.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Pointer to a water flow section configuration. |
| index | Index of the target water flow section. |

**Returns**

Returns the gap between rows.


### OH_ArkUI_WaterFlowSectionOption_GetSize()

```
int32_t OH_ArkUI_WaterFlowSectionOption_GetSize (ArkUI_WaterFlowSectionOption * option)
```
**Description**

Sets the array length for a water flow section configuration.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Pointer to a water flow section configuration. |

**Returns**

Returns the array length. If **-1** is returned, an error code indicating failure is returned. The possible cause is that the **option** parameter is abnormal, for example, a null pointer.


### OH_ArkUI_WaterFlowSectionOption_RegisterGetItemMainSizeCallbackByIndex()

```
void OH_ArkUI_WaterFlowSectionOption_RegisterGetItemMainSizeCallbackByIndex (ArkUI_WaterFlowSectionOption * option, int32_t index, float(*)(int32_t itemIndex) callback )
```
**Description**

Obtains the main axis size of a specified item based on **flowItemIndex** through a water flow section configuration.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Pointer to a water flow section configuration. |
| index | Index of the target water flow section. |
| callback | Callback used to return the result. |


### OH_ArkUI_WaterFlowSectionOption_RegisterGetItemMainSizeCallbackByIndexWithUserData()

```
void OH_ArkUI_WaterFlowSectionOption_RegisterGetItemMainSizeCallbackByIndexWithUserData (ArkUI_WaterFlowSectionOption * option, int32_t index, void * userData, float(*)(int32_t itemIndex, void *userData) callback )
```
**Description**

Obtains the main axis size of a specified item based on **flowItemIndex** through a water flow section configuration.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Pointer to a water flow section configuration. |
| index | Index of the target water flow section. |
| userData | Custom data of the water flow item. |
| callback | Callback used to return the result. |


### OH_ArkUI_WaterFlowSectionOption_SetColumnGap()

```
void OH_ArkUI_WaterFlowSectionOption_SetColumnGap (ArkUI_WaterFlowSectionOption * , int32_t index, float columnGap )
```
**Description**

Sets the gap between columns in the specified water flow section.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Pointer to a water flow section configuration. |
| index | Index of the target water flow section. |
| columnGap | Gap between columns. |


### OH_ArkUI_WaterFlowSectionOption_SetCrossCount()

```
void OH_ArkUI_WaterFlowSectionOption_SetCrossCount (ArkUI_WaterFlowSectionOption * option, int32_t index, int32_t crossCount )
```
**Description**

Sets the number of columns (in a vertical layout) or rows (in a horizontal layout) of a water flow.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Pointer to a water flow section configuration. |
| index | Index of the target water flow section. |
| crossCount | Number of columns or rows, depending on the layout direction. |


### OH_ArkUI_WaterFlowSectionOption_SetItemCount()

```
void OH_ArkUI_WaterFlowSectionOption_SetItemCount (ArkUI_WaterFlowSectionOption * option, int32_t index, int32_t itemCount )
```
**Description**

Sets the number of items in a water flow section.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Pointer to a water flow section configuration. |
| index | Index of the target water flow section. |
| itemCount | Number of items in the water flow section. |


### OH_ArkUI_WaterFlowSectionOption_SetMargin()

```
void OH_ArkUI_WaterFlowSectionOption_SetMargin (ArkUI_WaterFlowSectionOption * option, int32_t index, float marginTop, float marginRight, float marginBottom, float marginLeft )
```
**Description**

Sets the margins for the specified water flow section.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Pointer to a water flow section configuration. |
| index | Index of the target water flow section. |
| marginTop | Top margin of the water flow section. |
| marginRight | Right margin of the water flow section. |
| marginBottom | Bottom margin of the water flow section. |
| marginLeft | Left margin of the water flow section. |


### OH_ArkUI_WaterFlowSectionOption_SetRowGap()

```
void OH_ArkUI_WaterFlowSectionOption_SetRowGap (ArkUI_WaterFlowSectionOption * option, int32_t index, float rowGap )
```
**Description**

Sets the gap between rows in the specified water flow section.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Pointer to a water flow section configuration. |
| index | Index of the target water flow section. |
| rowGap | Gap between rows to set. |


### OH_ArkUI_WaterFlowSectionOption_SetSize()

```
void OH_ArkUI_WaterFlowSectionOption_SetSize (ArkUI_WaterFlowSectionOption * option, int32_t size )
```
**Description**

Sets the array length for a water flow section configuration.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| option | Pointer to a water flow section configuration. |
| size | Array length. |
