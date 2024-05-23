# ArkUI_NativeModule


## 概述

提供ArkUI在Native侧的UI能力，如UI组件创建销毁、树节点操作，属性设置，事件监听等。

提供ArkUI在Native侧的注册手势回调的能力。

**起始版本：** 12


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [drawable_descriptor.h](drawable__descriptor_8h.md) | 提供NativeDrawableDescriptor接口的类型定义。  <br>**库：** libace_ndk.z.so |
| [native_dialog.h](native__dialog_8h.md) | 提供ArkUI在Native侧的自定义弹窗接口定义集合。  <br>**库：** libace_ndk.z.so| 
| [native_event.h](native__event_8h.md) | 提供ArkUI在Native侧的事件类型定义集合。  <br>**库：** libace_ndk.z.so| 
| [native_gesture.h](native__gesture_8h.md) | 提供NativeGesture接口的类型定义。  <br>**库：** libace_ndk.z.so| 
| [native_interface.h](native__interface_8h.md) | 提供NativeModule接口的统一入口函数。  <br>**库：** libace_ndk.z.so| 
| [native_node.h](native__node_8h.md) | 提供NativeNode接口的类型定义。  <br>**库：** libace_ndk.z.so| 
| [native_node_napi.h](native__node__napi_8h.md) | 提供ArkTS侧的FrameNode转换NodeHandle的方式。  <br>**库：** libace_ndk.z.so| 
| [native_type.h](native__type_8h.md) | 提供NativeModule公共的类型定义。  <br>**库：** libace_ndk.z.so| 
| [native_animate.h](native__animate_8h.md) | 提供ArkUI在Native侧的动画接口定义集合。  <br>**库：** libace_ndk.z.so| 

### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[ArkUI_NativeDialogAPI_1](_ark_u_i___native_dialog_a_p_i__1.md) | ArkUI提供的Native侧自定义弹窗接口集合。  | 
| struct&nbsp;&nbsp;[ArkUI_NativeGestureAPI_1](_ark_u_i___native_gesture_a_p_i__1.md) | 手势模块接口集合。  | 
| struct&nbsp;&nbsp;[ArkUI_AttributeItem](_ark_u_i___attribute_item.md) | 定义setAttribute函数通用入参结构。  | 
| struct&nbsp;&nbsp;[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) | 定义组件回调事件的参数类型。  | 
| struct&nbsp;&nbsp;[ArkUI_StringAsyncEvent](_ark_u_i___string_async_event.md) | 定义组件回调事件使用字符串参数的类型。  | 
| struct&nbsp;&nbsp;[ArkUI_NativeNodeAPI_1](_ark_u_i___native_node_a_p_i__1.md) | ArkUI提供的Native侧Node类型接口集合。  | 
| struct&nbsp;&nbsp;[ArkUI_ContextCallback](_ark_u_i___context_callback.md) | 事件回调类型。  |
| union&nbsp;&nbsp;[ArkUI_NumberValue](union_ark_u_i___number_value.md) | ArkUI在native侧的数字类型定义。  | 
| struct&nbsp;&nbsp;[ARKUI_TextPickerRangeContent](_a_r_k_u_i___text_picker_range_content.md) | 定义单列滑动数据选择器支持图片资源的输入结构体。  | 
| struct&nbsp;&nbsp;[ARKUI_TextPickerCascadeRangeContent](_a_r_k_u_i___text_picker_cascade_range_content.md) | 定义多列带联动能力的滑动数据选择器的输入结构体。  | 
| struct&nbsp;&nbsp;[ArkUI_ColorStop](_ark_u_i___color_stop.md) | 定义渐变色结构。  | 
| struct&nbsp;&nbsp;[ArkUI_Rect](_ark_u_i___rect.md) | 定义遮罩屏蔽区域的范围结构体。  | 
| struct&nbsp;&nbsp;[ArkUI_IntSize](_ark_u_i___int_size.md) | 尺寸类型，用于描述组件的宽高。  | 
| struct&nbsp;&nbsp;[ArkUI_IntOffset](_ark_u_i___int_offset.md) | 位置，用于描述组件的位置。  | 
| struct&nbsp;&nbsp;[ArkUI_ExpectedFrameRateRange](_ark_u_i___expected_frame_rate_range.md) | 设置动画的期望帧率。  | 
| struct&nbsp;&nbsp;[ArkUI_AnimateCompleteCallback](_ark_u_i___animate_complete_callback.md) | 动画播放完成回调类型。  | 
| struct&nbsp;&nbsp;[ArkUI_NativeAnimateAPI_1](_ark_u_i___native_animate_a_p_i__1.md) | ArkUI提供的Native侧动画接口集合。  | 


### 宏定义

| 名称 | 描述 | 
| -------- | -------- |
| [OH_ArkUI_GetModuleInterface](#oh_arkui_getmoduleinterface)(nativeAPIVariantKind, structType, structPtr) | 基于结构体类型获取对应结构体指针的宏函数。  | 
| **MAX_NODE_SCOPE_NUM**&nbsp;&nbsp;&nbsp; |  1000| 
| **MAX_COMPONENT_EVENT_ARG_NUM**&nbsp;&nbsp;&nbsp; |  12| 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef bool(\* [ArkUI_OnWillDismissEvent](#arkui_onwilldismissevent)) (int32_t reason) | 弹窗关闭的回调函数。  | 
| typedef uint32_t [ArkUI_GestureEventActionTypeMask](#arkui_gestureeventactiontypemask) | 定义手势事件类型集合  | 
| typedef uint32_t [ArkUI_GestureDirectionMask](#arkui_gesturedirectionmask) | 定义滑动手势方向集合。  | 
| typedef struct [ArkUI_NodeEvent](#arkui_nodeevent) [ArkUI_NodeEvent](#arkui_nodeevent) | 定义组件事件的通用结构类型。  | 
| typedef struct ArkUI_Node \* [ArkUI_NodeHandle](#arkui_nodehandle) | 定义ArkUI native组件实例对象指针定义。  | 
| typedef struct ArkUI_NativeDialog \* [ArkUI_NativeDialogHandle](#arkui_nativedialoghandle) | 定义ArkUI在Native侧的自定义弹窗控制器对象指针。  | 
| typedef struct [ArkUI_WaterFlowSectionOption](#arkui_waterflowsectionoption) [ArkUI_WaterFlowSectionOption](#arkui_waterflowsectionoption) | 定义FlowItem分组配置信息。  | 
| typedef struct ArkUI_Context \* [ArkUI_ContextHandle](#arkui_contexthandle) | 定义ArkUI native UI的上下文实例对象指针定义。  | 
| typedef struct [ArkUI_AnimateOption](#arkui_animateoption)[ArkUI_AnimateOption](#arkui_animateoption) | 设置动画效果相关参数。  | 
| typedef struct [ArkUI_DrawableDescriptor](#arkui_drawabledescriptor)[ArkUI_DrawableDescriptor](#arkui_drawabledescriptor) | 定义 DrawableDescriptor 对象。  |
| typedef struct OH_PixelmapNative \* [OH_PixelmapNativeHandle](#oh_pixelmapnativehandle) | 定义OH_PixelmapNative对象指针类型。  |
| typedef struct [ArkUI_ListItemSwipeActionItem](#arkui_listitemswipeactionitem)[ArkUI_ListItemSwipeActionItem](#arkui_listitemswipeactionitem) | 定义ListItemSwipeActionOption方法内Item的配置信息。  |
| typedef struct [ArkUI_ListItemSwipeActionOption](#arkui_listitemswipeactionoption)[ArkUI_ListItemSwipeActionOption](#arkui_listitemswipeactionoption) | 定义ListItemSwipeActionOption方法的配置信息。  |


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [ArkUI_DismissReason](#arkui_dismissreason) { DIALOG_DISMISS_BACK_PRESS = 0, DIALOG_DISMISS_TOUCH_OUTSIDE } | 弹窗关闭的触发方式。  | 
| [HitTestMode](#hittestmode) { HTMDEFAULT = 0, HTMBLOCK, HTMTRANSPARENT, HTMNONE } | 定义触摸测试类型的枚举值。  | 
| [ArkUI_GestureEventActionType](#arkui_gestureeventactiontype) { GESTURE_EVENT_ACTION_ACCEPT = 0x01, GESTURE_EVENT_ACTION_UPDATE = 0x02, GESTURE_EVENT_ACTION_END = 0x04, GESTURE_EVENT_ACTION_CANCEL = 0x08 } | 定义手势事件类型。  | 
| [ArkUI_GesturePriority](#arkui_gesturepriority) { NORMAL = 0, PRIORITY = 1, PARALLEL = 2 } | 定义手势事件模式  | 
| [ArkUI_GroupGestureMode](#arkui_groupgesturemode) { SEQUENTIAL_GROUP = 0, PARALLEL_GROUP = 1, EXCLUSIVE_GROUP = 2 } | 定义手势组事件模式。  | 
| [ArkUI_GestureDirection](#arkui_gesturedirection) {<br/>GESTURE_DIRECTION_ALL = 0b1111, GESTURE_DIRECTION_HORIZONTAL = 0b0011, GESTURE_DIRECTION_VERTICAL = 0b1100, GESTURE_DIRECTION_LEFT = 0b0001,<br/>GESTURE_DIRECTION_RIGHT = 0b0010, GESTURE_DIRECTION_UP = 0b0100, GESTURE_DIRECTION_DOWN = 0b1000, GESTURE_DIRECTION_NONE = 0<br/>} | 定义滑动手势方向。  | 
| [ArkUI_GestureMask](#arkui_gesturemask) { NORMAL_GESTURE_MASK = 0, IGNORE_INTERNAL_GESTURE_MASK } | 定义手势屏蔽模式  | 
| [ArkUI_GestureRecognizerType](#arkui_gesturerecognizertype) {<br/>TAP_GESTURE = 0, LONG_PRESS_GESTURE, PAN_GESTURE, PINCH_GESTURE,<br/>ROTATION_GESTURE, SWIPE_GESTURE, GROUP_GESTURE<br/>} | 定义手势类型  | 
| [ArkUI_GestureInterruptResult](#arkui_gestureinterruptresult) { GESTURE_INTERRUPT_RESULT_CONTINUE = 0, GESTURE_INTERRUPT_RESULT_REJECT } | 定义手势打断结果。  | 
| [ArkUI_NativeAPIVariantKind](#arkui_nativeapivariantkind) { ARKUI_NATIVE_NODE, ARKUI_NATIVE_DIALOG, ARKUI_NATIVE_GESTURE, ARKUI_NATIVE_ANIMATE } | 定义Native接口集合类型。  | 
| [ArkUI_NodeType](#arkui_nodetype) {<br/>ARKUI_NODE_CUSTOM = 0, ARKUI_NODE_TEXT = 1, ARKUI_NODE_SPAN = 2, ARKUI_NODE_IMAGE_SPAN = 3,<br/>ARKUI_NODE_IMAGE = 4, ARKUI_NODE_TOGGLE = 5, ARKUI_NODE_LOADING_PROGRESS = 6, ARKUI_NODE_TEXT_INPUT = 7,<br/>ARKUI_NODE_TEXT_AREA = 8, ARKUI_NODE_BUTTON = 9, ARKUI_NODE_PROGRESS = 10, ARKUI_NODE_CHECKBOX = 11,<br/>ARKUI_NODE_XCOMPONENT = 12, ARKUI_NODE_DATE_PICKER = 13, ARKUI_NODE_TIME_PICKER = 14, ARKUI_NODE_TEXT_PICKER = 15,<br/>ARKUI_NODE_CALENDAR_PICKER = 16, ARKUI_NODE_SLIDER = 17, ARKUI_NODE_STACK = MAX_NODE_SCOPE_NUM, ARKUI_NODE_SWIPER,<br/>ARKUI_NODE_SCROLL, ARKUI_NODE_LIST, ARKUI_NODE_LIST_ITEM, ARKUI_NODE_LIST_ITEM_GROUP,<br/>ARKUI_NODE_COLUMN, ARKUI_NODE_ROW, ARKUI_NODE_FLEX, ARKUI_NODE_REFRESH,<br/>ARKUI_NODE_WATER_FLOW<br/>} | 提供ArkUI在Native侧可创建组件类型。  | 
| [ArkUI_NodeAttributeType](#arkui_nodeattributetype) {<br/>NODE_WIDTH = 0, NODE_HEIGHT, NODE_BACKGROUND_COLOR, NODE_BACKGROUND_IMAGE,<br/>NODE_PADDING, NODE_ID, NODE_ENABLED, NODE_MARGIN,<br/>NODE_TRANSLATE, NODE_SCALE, NODE_ROTATE, NODE_BRIGHTNESS,<br/>NODE_SATURATION, NODE_BLUR, NODE_LINEAR_GRADIENT, NODE_ALIGNMENT,<br/>NODE_OPACITY, NODE_BORDER_WIDTH, NODE_BORDER_RADIUS, NODE_BORDER_COLOR,<br/>NODE_BORDER_STYLE, NODE_Z_INDEX, NODE_VISIBILITY, NODE_CLIP,<br/>NODE_CLIP_SHAPE, NODE_TRANSFORM, NODE_HIT_TEST_BEHAVIOR, NODE_POSITION,<br/>NODE_SHADOW, NODE_CUSTOM_SHADOW, NODE_BACKGROUND_IMAGE_SIZE, NODE_BACKGROUND_IMAGE_SIZE_WITH_STYLE,<br/>NODE_BACKGROUND_BLUR_STYLE, NODE_TRANSFORM_CENTER, NODE_OPACITY_TRANSITION, NODE_ROTATE_TRANSITION,<br/>NODE_SCALE_TRANSITION, NODE_TRANSLATE_TRANSITION, NODE_MOVE_TRANSITION, NODE_FOCUSABLE,<br/>NODE_DEFAULT_FOCUS, NODE_RESPONSE_REGION, NODE_OVERLAY, NODE_SWEEP_GRADIENT,<br/>NODE_RADIAL_GRADIENT, NODE_MASK, NODE_BLEND_MODE, NODE_DIRECTION,<br/>NODE_CONSTRAINT_SIZE, NODE_GRAY_SCALE, NODE_INVERT, NODE_SEPIA,<br/>NODE_CONTRAST, NODE_FOREGROUND_COLOR, NODE_OFFSET, NODE_MARK_ANCHOR,<br/>NODE_BACKGROUND_IMAGE_POSITION, NODE_ALIGN_RULES, NODE_ALIGN_SELF, NODE_FLEX_GROW,<br/>NODE_FLEX_SHRINK, NODE_FLEX_BASIS, NODE_ACCESSIBILITY_GROUP, NODE_ACCESSIBILITY_TEXT,<br/>NODE_ACCESSIBILITY_MODE, NODE_ACCESSIBILITY_DESCRIPTION, NODE_FOCUS_STATUS, NODE_ASPECT_RATIO,<br/>NODE_TEXT_CONTENT = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_TEXT, NODE_FONT_COLOR, NODE_FONT_SIZE, NODE_FONT_STYLE,<br/>NODE_FONT_WEIGHT, NODE_TEXT_LINE_HEIGHT, NODE_TEXT_DECORATION, NODE_TEXT_CASE,<br/>NODE_TEXT_LETTER_SPACING, NODE_TEXT_MAX_LINES, NODE_TEXT_ALIGN, NODE_TEXT_OVERFLOW,<br/>NODE_FONT_FAMILY, NODE_TEXT_COPY_OPTION, NODE_TEXT_BASELINE_OFFSET, NODE_TEXT_TEXT_SHADOW,<br/>NODE_TEXT_MIN_FONT_SIZE, NODE_TEXT_MAX_FONT_SIZE, NODE_TEXT_FONT, NODE_TEXT_HEIGHT_ADAPTIVE_POLICY,<br/>NODE_TEXT_INDENT, NODE_TEXT_WORD_BREAK, NODE_TEXT_ELLIPSIS_MODE, NODE_TEXT_LINE_SPACING, NODE_SPAN_CONTENT = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_SPAN,<br/>NODE_SPAN_TEXT_BACKGROUND_STYLE, NODE_IMAGE_SPAN_SRC = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_IMAGE_SPAN, NODE_IMAGE_SPAN_VERTICAL_ALIGNMENT, NODE_IMAGE_SRC = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_IMAGE,<br/>NODE_IMAGE_OBJECT_FIT, NODE_IMAGE_INTERPOLATION, NODE_IMAGE_OBJECT_REPEAT, NODE_IMAGE_COLOR_FILTER,<br/>NODE_IMAGE_AUTO_RESIZE, NODE_IMAGE_ALT, NODE_IMAGE_DRAGGABLE, NODE_IMAGE_RENDER_MODE,<br/>NODE_TOGGLE_SELECTED_COLOR = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_TOGGLE, NODE_TOGGLE_SWITCH_POINT_COLOR, NODE_TOGGLE_VALUE, NODE_LOADING_PROGRESS_COLOR = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_LOADING_PROGRESS,<br/>NODE_LOADING_PROGRESS_ENABLE_LOADING, NODE_TEXT_INPUT_PLACEHOLDER = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_TEXT_INPUT, NODE_TEXT_INPUT_TEXT, NODE_TEXT_INPUT_CARET_COLOR,<br/>NODE_TEXT_INPUT_CARET_STYLE, NODE_TEXT_INPUT_SHOW_UNDERLINE, NODE_TEXT_INPUT_MAX_LENGTH, NODE_TEXT_INPUT_ENTER_KEY_TYPE,<br/>NODE_TEXT_INPUT_PLACEHOLDER_COLOR, NODE_TEXT_INPUT_PLACEHOLDER_FONT, NODE_TEXT_INPUT_ENABLE_KEYBOARD_ON_FOCUS, NODE_TEXT_INPUT_TYPE,<br/>NODE_TEXT_INPUT_SELECTED_BACKGROUND_COLOR, NODE_TEXT_INPUT_SHOW_PASSWORD_ICON, NODE_TEXT_INPUT_EDITING, NODE_TEXT_INPUT_CANCEL_BUTTON,<br/>NODE_TEXT_INPUT_TEXT_SELECTION, NODE_TEXT_AREA_PLACEHOLDER = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_TEXT_AREA, NODE_TEXT_AREA_TEXT, NODE_TEXT_AREA_MAX_LENGTH,<br/>NODE_TEXT_AREA_PLACEHOLDER_COLOR, NODE_TEXT_AREA_PLACEHOLDER_FONT, NODE_TEXT_AREA_CARET_COLOR, NODE_TEXT_AREA_EDITING,<br/>NODE_TEXT_AREA_TYPE, NODE_TEXT_AREA_SHOW_COUNTER, NODE_BUTTON_LABEL = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_BUTTON, NODE_PROGRESS_VALUE = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_PROGRESS,<br/>NODE_PROGRESS_TOTAL, NODE_PROGRESS_COLOR, NODE_PROGRESS_TYPE, NODE_CHECKBOX_SELECT = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_CHECKBOX,<br/>NODE_CHECKBOX_SELECT_COLOR, NODE_CHECKBOX_UNSELECT_COLOR, NODE_CHECKBOX_MARK, NODE_CHECKBOX_SHAPE,<br/>NODE_XCOMPONENT_ID = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_XCOMPONENT, NODE_XCOMPONENT_TYPE, NODE_XCOMPONENT_SURFACE_SIZE, NODE_DATE_PICKER_LUNAR = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_DATE_PICKER,<br/>NODE_DATE_PICKER_START, NODE_DATE_PICKER_END, NODE_DATE_PICKER_SELECTED, NODE_DATE_PICKER_DISAPPEAR_TEXT_STYLE,<br/>NODE_DATE_PICKER_TEXT_STYLE, NODE_DATE_PICKER_SELECTED_TEXT_STYLE, NODE_TIME_PICKER_SELECTED = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_TIME_PICKER, NODE_TIME_PICKER_USE_MILITARY_TIME,<br/>NODE_TIME_PICKER_DISAPPEAR_TEXT_STYLE, NODE_TIME_PICKER_TEXT_STYLE, NODE_TIME_PICKER_SELECTED_TEXT_STYLE, NODE_TEXT_PICKER_OPTION_RANGE = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_TEXT_PICKER,<br/>NODE_TEXT_PICKER_OPTION_SELECTED, NODE_TEXT_PICKER_OPTION_VALUE, NODE_TEXT_PICKER_DISAPPEAR_TEXT_STYLE, NODE_TEXT_PICKER_TEXT_STYLE,<br/>NODE_TEXT_PICKER_SELECTED_TEXT_STYLE, NODE_TEXT_PICKER_SELECTED_INDEX, NODE_TEXT_PICKER_CAN_LOOP, NODE_TEXT_PICKER_DEFAULT_PICKER_ITEM_HEIGHT,<br/>NODE_CALENDAR_PICKER_HINT_RADIUS = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_CALENDAR_PICKER, NODE_CALENDAR_PICKER_SELECTED_DATE, NODE_CALENDAR_PICKER_EDGE_ALIGNMENT, NODE_CALENDAR_PICKER_TEXT_STYLE,<br/>NODE_SLIDER_BLOCK_COLOR = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_SLIDER, NODE_SLIDER_TRACK_COLOR, NODE_SLIDER_SELECTED_COLOR, NODE_SLIDER_SHOW_STEPS,<br/>NODE_SLIDER_BLOCK_STYLE, NODE_SLIDER_VALUE, NODE_SLIDER_MIN_VALUE, NODE_SLIDER_MAX_VALUE,<br/>NODE_SLIDER_STEP, NODE_SLIDER_DIRECTION, NODE_SLIDER_REVERSE, NODE_SLIDER_STYLE,<br/>NODE_STACK_ALIGN_CONTENT = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_STACK, NODE_SCROLL_BAR_DISPLAY_MODE = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_SCROLL, NODE_SCROLL_BAR_WIDTH, NODE_SCROLL_BAR_COLOR,<br/>NODE_SCROLL_SCROLL_DIRECTION, NODE_SCROLL_EDGE_EFFECT, NODE_SCROLL_ENABLE_SCROLL_INTERACTION, NODE_SCROLL_FRICTION,<br/>NODE_SCROLL_SNAP, NODE_SCROLL_NESTED_SCROLL, NODE_SCROLL_OFFSET, NODE_SCROLL_EDGE,<br/>NODE_SCROLL_ENABLE_PAGING, NODE_LIST_DIRECTION = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_LIST, NODE_LIST_STICKY, NODE_LIST_SPACE,<br/>NODE_SWIPER_LOOP = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_SWIPER, NODE_SWIPER_AUTO_PLAY, NODE_SWIPER_SHOW_INDICATOR, NODE_SWIPER_INTERVAL,<br/>NODE_SWIPER_VERTICAL, NODE_SWIPER_DURATION, NODE_SWIPER_CURVE, NODE_SWIPER_ITEM_SPACE,<br/>NODE_SWIPER_INDEX, NODE_SWIPER_DISPLAY_COUNT, NODE_SWIPER_DISABLE_SWIPE, NODE_SWIPER_SHOW_DISPLAY_ARROW,<br/>NODE_SWIPER_EDGE_EFFECT_MODE, NODE_LIST_ITEM_GROUP_SET_HEADER = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_LIST_ITEM_GROUP, NODE_LIST_ITEM_GROUP_SET_FOOTER, NODE_LIST_ITEM_GROUP_SET_DIVIDER,<br/>NODE_COLUMN_ALIGN_ITEMS = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_COLUMN, NODE_COLUMN_JUSTIFY_CONTENT, NODE_ROW_ALIGN_ITEMS = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_ROW, NODE_ROW_JUSTIFY_CONTENT,<br/>NODE_FLEX_OPTION = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_FLEX, NODE_REFRESH_REFRESHING = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_REFRESH, NODE_REFRESH_CONTENT, NODE_WATER_FLOW_LAYOUT_DIRECTION = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_WATER_FLOW,<br/>NODE_WATER_FLOW_COLUMN_TEMPLATE, NODE_WATER_FLOW_ROW_TEMPLATE, NODE_WATER_FLOW_COLUMN_GAP, NODE_WATER_FLOW_ROW_GAP,<br/>NODE_WATER_FLOW_SECTION_OPTION<br/>, NODE_LIST_CACHED_COUNT, NODE_SWIPER_CACHED_COUN, NODE_WATER_FLOW_CACHED_COUN, NODE_LIST_ITEM_SWIPE_ACTION = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_LIST_ITEM} | 定义ArkUI在Native侧可以设置的属性样式集合。  | 
| [ArkUI_NodeEventType](#arkui_nodeeventtype) {<br/>NODE_TOUCH_EVENT = 0, NODE_EVENT_ON_APPEAR, NODE_EVENT_ON_DISAPPEAR, NODE_EVENT_ON_AREA_CHANGE,<br/>NODE_ON_FOCUS, NODE_ON_BLUR, NODE_ON_CLICK, NODE_IMAGE_ON_COMPLETE = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_IMAGE,<br/>NODE_IMAGE_ON_ERROR, NODE_IMAGE_ON_SVG_PLAY_FINISH, NODE_TOGGLE_ON_CHANGE = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_TOGGLE, NODE_TEXT_INPUT_ON_CHANGE = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_TEXT_INPUT,<br/>NODE_TEXT_INPUT_ON_SUBMIT, NODE_TEXT_INPUT_ON_CUT, NODE_TEXT_INPUT_ON_PASTE, NODE_TEXT_INPUT_ON_TEXT_SELECTION_CHANGE,<br/>NODE_TEXT_AREA_ON_CHANGE = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_TEXT_AREA, NODE_TEXT_AREA_ON_PASTE, NODE_TEXT_AREA_ON_TEXT_SELECTION_CHANGE, NODE_CHECKBOX_EVENT_ON_CHANGE = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_CHECKBOX,<br/>NODE_DATE_PICKER_EVENT_ON_DATE_CHANGE = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_DATE_PICKER, NODE_TIME_PICKER_EVENT_ON_CHANGE = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_TIME_PICKER, NODE_TEXT_PICKER_EVENT_ON_CHANGE = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_TEXT_PICKER, NODE_CALENDAR_PICKER_EVENT_ON_CHANGE = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_CALENDAR_PICKER,<br/>NODE_SLIDER_EVENT_ON_CHANGE = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_SLIDER, NODE_SWIPER_EVENT_ON_CHANGE = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_SWIPER, NODE_SWIPER_EVENT_ON_ANIMATION_START, NODE_SWIPER_EVENT_ON_ANIMATION_END,<br/>NODE_SWIPER_EVENT_ON_GESTURE_SWIPE, NODE_SWIPER_EVENT_ON_CONTENT_DID_SCROLL, NODE_SCROLL_EVENT_ON_SCROLL = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_SCROLL, NODE_SCROLL_EVENT_ON_SCROLL_FRAME_BEGIN, NODE_SCROLL_EVENT_ON_SCROLL_START,<br/>NODE_SCROLL_EVENT_ON_SCROLL_STOP, NODE_SCROLL_EVENT_ON_SCROLL_EDGE, NODE_SCROLL_EVENT_ON_WILL_SCROLL, NODE_REFRESH_STATE_CHANGE = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_REFRESH,<br/>NODE_REFRESH_ON_REFRESH<br/>} | 提供NativeNode组件支持的事件类型定义。  | 
| [ArkUI_NodeDirtyFlag](#arkui_nodedirtyflag) { NODE_NEED_MEASURE = 1, NODE_NEED_LAYOUT, NODE_NEED_RENDER } | 自定义组件调用&lt;b&gt;::markDirty是传递的脏区标识类型。  | 
| [ArkUI_NodeCustomEventType](#arkui_nodecustomeventtype) {<br/>ARKUI_NODE_CUSTOM_EVENT_ON_MEASURE = 1 &lt;&lt; 0, ARKUI_NODE_CUSTOM_EVENT_ON_LAYOUT = 1 &lt;&lt; 1, ARKUI_NODE_CUSTOM_EVENT_ON_DRAW = 1 &lt;&lt; 2, ARKUI_NODE_CUSTOM_EVENT_ON_FOREGROUND_DRAW = 1 &lt;&lt; 3,<br/>ARKUI_NODE_CUSTOM_EVENT_ON_OVERLAY_DRAW = 1 &lt;&lt; 4<br/>} | 定义自定义组件事件类型。  | 
| [ArkUI_Alignment](#arkui_alignment) {<br/>ARKUI_ALIGNMENT_TOP_START = 0, ARKUI_ALIGNMENT_TOP, ARKUI_ALIGNMENT_TOP_END, ARKUI_ALIGNMENT_START,<br/>ARKUI_ALIGNMENT_CENTER, ARKUI_ALIGNMENT_END, ARKUI_ALIGNMENT_BOTTOM_START, ARKUI_ALIGNMENT_BOTTOM,<br/>ARKUI_ALIGNMENT_BOTTOM_END<br/>} | 定义布局对齐枚举值。  | 
| [ArkUI_ImageRepeat](#arkui_imagerepeat) { ARKUI_IMAGE_REPEAT_NONE = 0, ARKUI_IMAGE_REPEAT_X, ARKUI_IMAGE_REPEAT_Y, ARKUI_IMAGE_REPEAT_XY } | 定义图片重复铺设枚举值。  | 
| [ArkUI_FontStyle](#arkui_fontstyle) { ARKUI_FONT_STYLE_NORMAL = 0, ARKUI_FONT_STYLE_ITALIC } | 定义字体样式枚举值。  | 
| [ArkUI_FontWeight](#arkui_fontweight) {<br/>ARKUI_FONT_WEIGHT_W100 = 0, ARKUI_FONT_WEIGHT_W200, ARKUI_FONT_WEIGHT_W300, ARKUI_FONT_WEIGHT_W400,<br/>ARKUI_FONT_WEIGHT_W500, ARKUI_FONT_WEIGHT_W600, ARKUI_FONT_WEIGHT_W700, ARKUI_FONT_WEIGHT_W800,<br/>ARKUI_FONT_WEIGHT_W900, ARKUI_FONT_WEIGHT_BOLD, ARKUI_FONT_WEIGHT_NORMAL, ARKUI_FONT_WEIGHT_BOLDER,<br/>ARKUI_FONT_WEIGHT_LIGHTER, ARKUI_FONT_WEIGHT_MEDIUM, ARKUI_FONT_WEIGHT_REGULAR<br/>} | 定义字体粗细/字重枚举值。  | 
| [ArkUI_TextAlignment](#arkui_textalignment) { ARKUI_TEXT_ALIGNMENT_START = 0, ARKUI_TEXT_ALIGNMENT_CENTER, ARKUI_TEXT_ALIGNMENT_END, ARKUI_TEXT_ALIGNMENT_JUSTIFY } | 定义字体水平对齐样式枚举值。  | 
| [ArkUI_EnterKeyType](#arkui_enterkeytype) {<br/>ARKUI_ENTER_KEY_TYPE_GO = 2, ARKUI_ENTER_KEY_TYPE_SEARCH = 3, ARKUI_ENTER_KEY_TYPE_SEND, ARKUI_ENTER_KEY_TYPE_NEXT,<br/>ARKUI_ENTER_KEY_TYPE_DONE, ARKUI_ENTER_KEY_TYPE_PREVIOUS, ARKUI_ENTER_KEY_TYPE_NEW_LINE<br/>} | 定义单行文本输入法回车键类型枚举值。  | 
| [ArkUI_TextInputType](#arkui_textinputtype) {<br/>ARKUI_TEXTINPUT_TYPE_NORMAL = 0, ARKUI_TEXTINPUT_TYPE_NUMBER = 2, ARKUI_TEXTINPUT_TYPE_PHONE_NUMBER = 3, ARKUI_TEXTINPUT_TYPE_EMAIL = 5,<br/>ARKUI_TEXTINPUT_TYPE_PASSWORD = 7, ARKUI_TEXTINPUT_TYPE_NUMBER_PASSWORD = 8, ARKUI_TEXTINPUT_TYPE_SCREEN_LOCK_PASSWORD = 9, ARKUI_TEXTINPUT_TYPE_USER_NAME = 10,<br/>ARKUI_TEXTINPUT_TYPE_NEW_PASSWORD = 11, ARKUI_TEXTINPUT_TYPE_NUMBER_DECIMAL = 12<br/>} | 定义单行文本输入法类型枚举值。  | 
| [ArkUI_TextAreaType](#arkui_textareatype) { ARKUI_TEXTAREA_TYPE_NORMAL = 0, ARKUI_TEXTAREA_TYPE_NUMBER = 2, ARKUI_TEXTAREA_TYPE_PHONE_NUMBER = 3, ARKUI_TEXTAREA_TYPE_EMAIL = 5 } | 定义多行文本输入法类型枚举值。  | 
| [ArkUI_CancelButtonStyle](#arkui_cancelbuttonstyle) { ARKUI_CANCELBUTTON_STYLE_CONSTANT = 0, ARKUI_CANCELBUTTON_STYLE_INVISIBLE, ARKUI_CANCELBUTTON_STYLE_INPUT } | 定义清除按钮样式枚举值。  | 
| [ArkUI_XComponentType](#arkui_xcomponenttype) { ARKUI_XCOMPONENT_TYPE_SURFACE = 0, ARKUI_XCOMPONENT_TYPE_TEXTURE = 2 } | 定义XComponent类型枚举值。  | 
| [ArkUI_ProgressType](#arkui_progresstype) {<br/>ARKUI_PROGRESS_TYPE_LINEAR = 0, ARKUI_PROGRESS_TYPE_RING, ARKUI_PROGRESS_TYPE_ECLIPSE, ARKUI_PROGRESS_TYPE_SCALE_RING,<br/>ARKUI_PROGRESS_TYPE_CAPSULE<br/>} | 定义进度条类型枚举值。  | 
| [ArkUI_TextDecorationType](#arkui_textdecorationtype) { ARKUI_TEXT_DECORATION_TYPE_NONE = 0, ARKUI_TEXT_DECORATION_TYPE_UNDERLINE, ARKUI_TEXT_DECORATION_TYPE_OVERLINE, ARKUI_TEXT_DECORATION_TYPE_LINE_THROUGH } | 定义装饰线样式枚举值。  | 
| [ArkUI_TextCase](#arkui_textcase) { ARKUI_TEXT_CASE_NORMAL = 0, ARKUI_TEXT_CASE_LOWER, ARKUI_TEXT_CASE_UPPER } | 定义文本大小写枚举值。  | 
| [ArkUI_CopyOptions](#arkui_copyoptions) { ARKUI_COPY_OPTIONS_NONE = 0, ARKUI_COPY_OPTIONS_IN_APP, ARKUI_COPY_OPTIONS_LOCAL_DEVICE, ARKUI_COPY_OPTIONS_CROSS_DEVICE } | 定义文本复制黏贴模式枚举值。  | 
| [ArkUI_ShadowType](#arkui_shadowtype) { ARKUI_SHADOW_TYPE_COLOR = 0, ARKUI_SHADOW_TYPE_BLUR } | 定义阴影类型枚举值。  | 
| [ArkUI_TextPickerRangeType](#arkui_textpickerrangetype) { ARKUI_TEXTPICKER_RANGETYPE_SINGLE = 0, ARKUI_TEXTPICKER_RANGETYPE_MULTI, ARKUI_TEXTPICKER_RANGETYPE_RANGE_CONTENT, ARKUI_TEXTPICKER_RANGETYPE_CASCADE_RANGE_CONTENT } | 定义滑动选择文本选择器输入类型。  | 
| [ArkUI_EdgeEffect](#arkui_edgeeffect) { ARKUI_EDGE_EFFECT_SPRING = 0, ARKUI_EDGE_EFFECT_FADE, ARKUI_EDGE_EFFECT_NONE } | 定义边缘滑动效果枚举值。  | 
| [ArkUI_ScrollDirection](#arkui_scrolldirection) { ARKUI_SCROLL_DIRECTION_VERTICAL = 0, ARKUI_SCROLL_DIRECTION_HORIZONTAL, ARKUI_SCROLL_DIRECTION_NONE = 3 } | 定义Scroll组件排列方向枚举值。  | 
| [ArkUI_ScrollSnapAlign](#arkui_scrollsnapalign) { ARKUI_SCROLL_SNAP_ALIGN_NONE = 0, ARKUI_SCROLL_SNAP_ALIGN_START, ARKUI_SCROLL_SNAP_ALIGN_CENTER, ARKUI_SCROLL_SNAP_ALIGN_END } | 定义列表项滚动结束对齐效果枚举值。  | 
| [ArkUI_ScrollBarDisplayMode](#arkui_scrollbardisplaymode) { ARKUI_SCROLL_BAR_DISPLAY_MODE_OFF = 0, ARKUI_SCROLL_BAR_DISPLAY_MODE_AUTO, ARKUI_SCROLL_BAR_DISPLAY_MODE_ON } | 定义滚动条状态枚举值。  | 
| [ArkUI_Axis](#arkui_axis) { ARKUI_AXIS_VERTICAL = 0, ARKUI_AXIS_HORIZONTAL } | 定义滚动方向和List组件排列方向枚举值。  | 
| [ArkUI_StickyStyle](#arkui_stickystyle) { ARKUI_STICKY_STYLE_NONE = 0, ARKUI_STICKY_STYLE_HEADER = 1, ARKUI_STICKY_STYLE_FOOTER = 2, ARKUI_STICKY_STYLE_BOTH = 3 } | 定义列表是否吸顶和吸底枚举值。  | 
| [ArkUI_BorderStyle](#arkui_borderstyle) { ARKUI_BORDER_STYLE_SOLID = 0, ARKUI_BORDER_STYLE_DASHED, ARKUI_BORDER_STYLE_DOTTED } | 边框线条样式枚举值。  | 
| [ArkUI_HitTestMode](#arkui_hittestmode) { ARKUI_HIT_TEST_MODE_DEFAULT = 0, ARKUI_HIT_TEST_MODE_BLOCK, ARKUI_HIT_TEST_MODE_TRANSPARENT, ARKUI_HIT_TEST_MODE_NONE } | 触摸测试控制枚举值。  | 
| [ArkUI_ShadowStyle](#arkui_shadowstyle) {<br/>ARKUI_SHADOW_STYLE_OUTER_DEFAULT_XS = 0, ARKUI_SHADOW_STYLE_OUTER_DEFAULT_SM, ARKUI_SHADOW_STYLE_OUTER_DEFAULT_MD, ARKUI_SHADOW_STYLE_OUTER_DEFAULT_LG,<br/>ARKUI_SHADOW_STYLE_OUTER_FLOATING_SM, ARKUI_SHADOW_STYLE_OUTER_FLOATING_MD<br/>} | 阴影效果枚举值。  | 
| [ArkUI_AnimationCurve](#arkui_animationcurve) {<br/>ARKUI_CURVE_LINEAR = 0, ARKUI_CURVE_EASE, ARKUI_CURVE_EASE_IN, ARKUI_CURVE_EASE_OUT,<br/>ARKUI_CURVE_EASE_IN_OUT, ARKUI_CURVE_FAST_OUT_SLOW_IN, ARKUI_CURVE_LINEAR_OUT_SLOW_IN, ARKUI_CURVE_FAST_OUT_LINEAR_IN,<br/>ARKUI_CURVE_EXTREME_DECELERATION, ARKUI_CURVE_SHARP, ARKUI_CURVE_RHYTHM, ARKUI_CURVE_SMOOTH,<br/>ARKUI_CURVE_FRICTION<br/>} | 动画曲线枚举值。  | 
| [ArkUI_SwiperArrow](#arkui_swiperarrow) { ARKUI_SWIPER_ARROW_HIDE = 0, ARKUI_SWIPER_ARROW_SHOW, ARKUI_SWIPER_ARROW_SHOW_ON_HOVER } | Swiper导航点箭头枚举值。  | 
| [ArkUI_AccessibilityMode](#arkui_accessibilitymode) { ARKUI_ACCESSIBILITY_MODE_AUTO = 0, ARKUI_ACCESSIBILITY_MODE_ENABLED, ARKUI_ACCESSIBILITY_MODE_DISABLED, ARKUI_ACCESSIBILITY_MODE_DISABLED_FOR_DESCENDANTS } | 定义无障碍辅助服务模式。  | 
| [ArkUI_TextCopyOptions](#arkui_textcopyoptions) { ARKUI_TEXT_COPY_OPTIONS_NONE = 0, ARKUI_TEXT_COPY_OPTIONS_IN_APP, ARKUI_TEXT_COPY_OPTIONS_LOCAL_DEVICE, ARKUI_TEXT_COPY_OPTIONS_CROSS_DEVICE } | 定义组件支持设置文本是否可复制粘贴。  | 
| [ArkUI_TextHeightAdaptivePolicy](#arkui_textheightadaptivepolicy) { ARKUI_TEXT_HEIGHT_ADAPTIVE_POLICY_MAX_LINES_FIRST = 0, ARKUI_TEXT_HEIGHT_ADAPTIVE_POLICY_MIN_FONT_SIZE_FIRST, ARKUI_TEXT_HEIGHT_ADAPTIVE_POLICY_LAYOUT_CONSTRAINT_FIRST } | 定义文本自适应高度的方式。  | 
| [ArkUI_ScrollNestedMode](#arkui_scrollnestedmode) { ARKUI_SCROLL_NESTED_MODE_SELF_ONLY = 0, ARKUI_SCROLL_NESTED_MODE_SELF_FIRST, ARKUI_SCROLL_NESTED_MODE_PARENT_FIRST, ARKUI_SCROLL_NESTED_MODE_PARALLEL } | 定义嵌套滚动选项。  | 
| [ArkUI_ScrollEdge](#arkui_scrolledge) { ARKUI_SCROLL_EDGE_TOP = 0, ARKUI_SCROLL_EDGE_BOTTOM, ARKUI_SCROLL_EDGE_START, ARKUI_SCROLL_EDGE_END } | 定义滚动到的边缘位置。  | 
| [ArkUI_SliderBlockStyle](#arkui_sliderblockstyle) { ARKUI_SLIDER_BLOCK_STYLE_DEFAULT = 0, ARKUI_SLIDER_BLOCK_STYLE_IMAGE, ARKUI_SLIDER_BLOCK_STYLE_SHAPE } | 定义滑块形状。  | 
| [ArkUI_SliderDirection](#arkui_sliderdirection) { ARKUI_SLIDER_DIRECTION_VERTICAL = 0, ARKUI_SLIDER_DIRECTION_HORIZONTAL } | 定义滑动条滑动方向。  | 
| [ArkUI_SliderStyle](#arkui_sliderstyle) { ARKUI_SLIDER_STYLE_OUT_SET = 0, ARKUI_SLIDER_STYLE_IN_SET } | 定义滑块与滑轨显示样式。  | 
| [ArkUI_CheckboxShape](#arkui_checkboxshape) { ArkUI_CHECKBOX_SHAPE_CIRCLE = 0, ArkUI_CHECKBOX_SHAPE_ROUNDED_SQUARE } | 定义CheckBox组件形状。  | 
| [ArkUI_AnimationPlayMode](#arkui_animationplaymode) { ARKUI_ANIMATION_PLAY_MODE_NORMAL = 0, ARKUI_ANIMATION_PLAY_MODE_REVERSE, ARKUI_ANIMATION_PLAY_MODE_ALTERNATE, ARKUI_ANIMATION_PLAY_MODE_ALTERNATE_REVERSE } | 定义动画播放模式。  | 
| [ArkUI_ImageSize](#arkui_imagesize) { ARKUI_IMAGE_SIZE_AUTO = 0, ARKUI_IMAGE_SIZE_COVER, ARKUI_IMAGE_SIZE_CONTAIN } | 定义图片宽高样式。  | 
| [ArkUI_AdaptiveColor](#arkui_adaptivecolor) { ARKUI_ADAPTIVE_COLOR_DEFAULT = 0, ARKUI_ADAPTIVE_COLOR_AVERAGE } | 定义取色模式。  | 
| [ArkUI_ColorMode](#arkui_colormode) { ARKUI_COLOR_MODE_SYSTEM = 0, ARKUI_COLOR_MODE_LIGHT, ARKUI_COLOR_MODE_DARK } | 定义深浅色模式。  | 
| [ArkUI_BlurStyle](#arkui_blurstyle) {<br/>ARKUI_BLUR_STYLE_THIN = 0, ARKUI_BLUR_STYLE_REGULAR, ARKUI_BLUR_STYLE_THICK, ARKUI_BLUR_STYLE_BACKGROUND_THIN,<br/>ARKUI_BLUR_STYLE_BACKGROUND_REGULAR, ARKUI_BLUR_STYLE_BACKGROUND_THICK, ARKUI_BLUR_STYLE_BACKGROUND_ULTRA_THICK, ARKUI_BLUR_STYLE_NONE,<br/>ARKUI_BLUR_STYLE_COMPONENT_ULTRA_THIN, ARKUI_BLUR_STYLE_COMPONENT_THIN, ARKUI_BLUR_STYLE_COMPONENT_REGULAR, ARKUI_BLUR_STYLE_COMPONENT_THICK,<br/>ARKUI_BLUR_STYLE_COMPONENT_ULTRA_THICK<br/>} | 定义背景模糊样式。  | 
| [ArkUI_VerticalAlignment](#arkui_verticalalignment) { ARKUI_VERTICAL_ALIGNMENT_TOP = 0, ARKUI_VERTICAL_ALIGNMENT_CENTER, ARKUI_VERTICAL_ALIGNMENT_BOTTOM } | 定义垂直对齐方式。  | 
| [ArkUI_HorizontalAlignment](#arkui_horizontalalignment) { ARKUI_HORIZONTAL_ALIGNMENT_START = 0, ARKUI_HORIZONTAL_ALIGNMENT_CENTER, ARKUI_HORIZONTAL_ALIGNMENT_END } | 定义语言方向对齐方式。  | 
| [ArkUI_TextOverflow](#arkui_textoverflow) { ARKUI_TEXT_OVERFLOW_NONE = 0, ARKUI_TEXT_OVERFLOW_CLIP, ARKUI_TEXT_OVERFLOW_ELLIPSIS, ARKUI_TEXT_OVERFLOW_MARQUEE } | 定义文本超长时的显示方式。  | 
| [ArkUI_ImageSpanAlignment](#arkui_imagespanalignment) { ARKUI_IMAGE_SPAN_ALIGNMENT_BASELINE = 0, ARKUI_IMAGE_SPAN_ALIGNMENT_BOTTOM, ARKUI_IMAGE_SPAN_ALIGNMENT_CENTER, ARKUI_IMAGE_SPAN_ALIGNMENT_TOP } | 定义图片基于文本的对齐方式。  | 
| [ArkUI_ObjectFit](#arkui_objectfit) {<br/>ARKUI_OBJECT_FIT_CONTAIN = 0, ARKUI_OBJECT_FIT_COVER, ARKUI_OBJECT_FIT_AUTO, ARKUI_OBJECT_FIT_FILL,<br/>ARKUI_OBJECT_FIT_SCALE_DOWN, ARKUI_OBJECT_FIT_NONE<br/>} | 定义image填充效果。 ImageSpanAlignment  | 
| [ArkUI_ImageInterpolation](#arkui_imageinterpolation) { ARKUI_IMAGE_INTERPOLATION_NONE = 0, ARKUI_IMAGE_INTERPOLATION_LOW, ARKUI_IMAGE_INTERPOLATION_MEDIUM, ARKUI_IMAGE_INTERPOLATION_HIGH } | 定义图片插值效果。  | 
| [ArkUI_BlendMode](#arkui_blendmode) {<br/>ARKUI_BLEND_MODE_NONE = 0, ARKUI_BLEND_MODE_CLEAR, ARKUI_BLEND_MODE_SRC, ARKUI_BLEND_MODE_DST,<br/>ARKUI_BLEND_MODE_SRC_OVER, ARKUI_BLEND_MODE_DST_OVER, ARKUI_BLEND_MODE_SRC_IN, ARKUI_BLEND_MODE_DST_IN,<br/>ARKUI_BLEND_MODE_SRC_OUT, ARKUI_BLEND_MODE_DST_OUT, ARKUI_BLEND_MODE_SRC_ATOP, ARKUI_BLEND_MODE_DST_ATOP,<br/>ARKUI_BLEND_MODE_XOR, ARKUI_BLEND_MODE_PLUS, ARKUI_BLEND_MODE_MODULATE, ARKUI_BLEND_MODE_SCREEN,<br/>ARKUI_BLEND_MODE_OVERLAY, ARKUI_BLEND_MODE_DARKEN, ARKUI_BLEND_MODE_LIGHTEN, ARKUI_BLEND_MODE_COLOR_DODGE,<br/>ARKUI_BLEND_MODE_COLOR_BURN, ARKUI_BLEND_MODE_HARD_LIGHT, ARKUI_BLEND_MODE_SOFT_LIGHT, ARKUI_BLEND_MODE_DIFFERENCE,<br/>ARKUI_BLEND_MODE_EXCLUSION, ARKUI_BLEND_MODE_MULTIPLY, ARKUI_BLEND_MODE_HUE, ARKUI_BLEND_MODE_SATURATION,<br/>ARKUI_BLEND_MODE_COLOR, ARKUI_BLEND_MODE_LUMINOSITY<br/>} | 混合模式枚举值。  | 
| [ArkUI_Direction](#arkui_direction) { ARKUI_DIRECTION_LTR = 0, ARKUI_DIRECTION_RTL, ARKUI_DIRECTION_AUTO = 3 } | 设置容器元素内主轴方向上的布局枚举值。  | 
| [ArkUI_ItemAlignment](#arkui_itemalignment) {<br/>ARKUI_ITEM_ALIGNMENT_AUTO = 0, ARKUI_ITEM_ALIGNMENT_START, ARKUI_ITEM_ALIGNMENT_CENTER, ARKUI_ITEM_ALIGNMENT_END,<br/>ARKUI_ITEM_ALIGNMENT_STRETCH, ARKUI_ITEM_ALIGNMENT_BASELINE<br/>} | 设置子组件在父容器交叉轴的对齐格式枚举值。  | 
| [ArkUI_ColorStrategy](#arkui_colorstrategy) { ARKUI_COLOR_STRATEGY_INVERT = 0, ARKUI_COLOR_STRATEGY_AVERAGE, ARKUI_COLOR_STRATEGY_PRIMARY } | 前景色枚举值。  | 
| [ArkUI_FlexAlignment](#arkui_flexalignment) {<br/>ARKUI_FLEX_ALIGNMENT_START = 1, ARKUI_FLEX_ALIGNMENT_CENTER = 2, ARKUI_FLEX_ALIGNMENT_END = 3, ARKUI_FLEX_ALIGNMENT_SPACE_BETWEEN = 6,<br/>ARKUI_FLEX_ALIGNMENT_SPACE_AROUND = 7, ARKUI_FLEX_ALIGNMENT_SPACE_EVENLY = 8<br/>} | 定义垂直方向对齐方式。  | 
| [ArkUI_FlexDirection](#arkui_flexdirection) { ARKUI_FLEX_DIRECTION_ROW = 0, ARKUI_FLEX_DIRECTION_COLUMN, ARKUI_FLEX_DIRECTION_ROW_REVERSE, ARKUI_FLEX_DIRECTION_COLUMN_REVERSE } | 定义Flex容器的主轴方向。  | 
| [ArkUI_FlexWrap](#arkui_flexwrap) { ARKUI_FLEX_WRAP_NO_WRAP = 0, ARKUI_FLEX_WRAP_WRAP, ARKUI_FLEX_WRAP_WRAP_REVERSE } | 定义Flex行列布局模式模式。  | 
| [ArkUI_Visibility](#arkui_visibility) { ARKUI_VISIBILITY_VISIBLE = 0, ARKUI_VISIBILITY_HIDDEN, ARKUI_VISIBILITY_NONE } | 控制组件的显隐枚举值。  | 
| [ArkUI_CalendarAlignment](#arkui_calendaralignment) { ARKUI_CALENDAR_ALIGNMENT_START = 0, ARKUI_CALENDAR_ALIGNMENT_CENTER, ARKUI_CALENDAR_ALIGNMENT_END } | 日历选择器与入口组件对齐方式。  | 
| [ArkUI_MaskType](#arkui_masktype) {<br/>ARKUI_MASK_TYPE_RECTANGLE = 0, ARKUI_MASK_TYPE_CIRCLE, ARKUI_MASK_TYPE_ELLIPSE, ARKUI_MASK_TYPE_PATH,<br/>ARKUI_MASK_TYPE_PROGRESS<br/>} | 遮罩类型枚举。  | 
| [ArkUI_ClipType](#arkui_cliptype) { ARKUI_CLIP_TYPE_RECTANGLE = 0, ARKUI_CLIP_TYPE_CIRCLE, ARKUI_CLIP_TYPE_ELLIPSE, ARKUI_CLIP_TYPE_PATH } | 裁剪类型枚举。  | 
| [ArkUI_ShapeType](#arkui_shapetype) { ARKUI_SHAPE_TYPE_RECTANGLE = 0, ARKUI_SHAPE_TYPE_CIRCLE, ARKUI_SHAPE_TYPE_ELLIPSE, ARKUI_SHAPE_TYPE_PATH } | 自定义形状。  | 
| [ArkUI_LinearGradientDirection](#arkui_lineargradientdirection) {<br/>ARKUI_LINEAR_GRADIENT_DIRECTION_LEFT = 0, ARKUI_LINEAR_GRADIENT_DIRECTION_TOP, ARKUI_LINEAR_GRADIENT_DIRECTION_RIGHT, ARKUI_LINEAR_GRADIENT_DIRECTION_BOTTOM,<br/>ARKUI_LINEAR_GRADIENT_DIRECTION_LEFT_TOP, ARKUI_LINEAR_GRADIENT_DIRECTION_LEFT_BOTTOM, ARKUI_LINEAR_GRADIENT_DIRECTION_RIGHT_TOP, ARKUI_LINEAR_GRADIENT_DIRECTION_RIGHT_BOTTOM,<br/>ARKUI_LINEAR_GRADIENT_DIRECTION_NONE, ARKUI_LINEAR_GRADIENT_DIRECTION_CUSTOM<br/>} | 定义渐变方向结构。  | 
| [ArkUI_WordBreak](#arkui_wordbreak) { ARKUI_WORD_BREAK_NORMAL = 0, ARKUI_WORD_BREAK_BREAK_ALL, ARKUI_WORD_BREAK_BREAK_WORD } | 定义文本断行规则。  | 
| [ArkUI_EllipsisMode](#arkui_ellipsismode) { ARKUI_ELLIPSIS_MODE_START = 0, ARKUI_ELLIPSIS_MODE_CENTER, ARKUI_ELLIPSIS_MODE_END } | 定义文本省略位置。  | 
| [ArkUI_ImageRenderMode](#arkui_imagerendermode) { ARKUI_IMAGE_RENDER_MODE_ORIGINAL = 0, ARKUI_IMAGE_RENDER_MODE_TEMPLATE } | 定义图片渲染模式。  | 
| [ArkUI_TransitionEdge](#arkui_transitionedge) { ARKUI_TRANSITION_EDGE_TOP = 0, ARKUI_TRANSITION_EDGE_BOTTOM, ARKUI_TRANSITION_EDGE_START, ARKUI_TRANSITION_EDGE_END } | 定义转场从边缘滑入和滑出的效果。  | 
| [ArkUI_FinishCallbackType](#arkui_finishcallbacktype) { ARKUI_FINISH_CALLBACK_REMOVED = 0, ARKUI_FINISH_CALLBACK_LOGICALLY } | 在动画中定义onFinish回调的类型。  |  
| [ArkUI_BlendApplyType](#arkui_blendapplytype) { BLEND_APPLY_TYPE_FAST = 0, BLEND_APPLY_TYPE_OFFSCREEN } | 指定的混合模式应用于视图的内容选项.  | 
| [ArkUI_LengthMetricUnit](#arkui_lengthmetricunit) { ARKUI_LENGTH_METRIC_UNIT_DEFAULT = -1, ARKUI_LENGTH_METRIC_UNIT_PX = 0, ARKUI_LENGTH_METRIC_UNIT_VP, ARKUI_LENGTH_METRIC_UNIT_FP } | 定义组件的单位模式。  | 
| [ArkUI_SwiperDisplayModeType](#arkui_swiperdisplaymodetype) { ARKUI_SWIPER_DISPLAY_MODE_STRETCH, ARKUI_SWIPER_DISPLAY_MODE_AUTO_LINEAR } | 定义 Swiper 组件的主轴方向上元素排列的模式。  | 
| [ArkUI_ListItemSwipeActionState](#arkui_listitemswipeactionstate) { ARKUI_LIST_ITEM_SWIPE_ACTION_STATE_COLLAPSED = 0, ARKUI_LIST_ITEM_SWIPE_ACTION_STATE_EXPANDED, ARKUI_LIST_ITEM_SWIPE_ACTION_STATE_ACTIONING } | 定义 Listitem 组件SwipeAction方法的显隐模式。  |
| [ArkUI_ListItemSwipeEdgeEffect](#arkui_listitemswipeedgeeffect) { ARKUI_LIST_ITEM_SWIPE_EDGE_EFFECT_SPRING = 0, ARKUI_LIST_ITEM_SWIPE_EDGE_EFFECT_NONE } | 定义 Listitem 组件SwipeAction方法的滚动模式。  |


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| bool [OH_ArkUI_GestureInterruptInfo_GetSystemFlag](#oh_arkui_gestureinterruptinfo_getsystemflag) (const ArkUI_GestureInterruptInfo \*event) | 判断是否组件内置手势。  | 
| ArkUI_GestureRecognizer \* [OH_ArkUI_GestureInterruptInfo_GetRecognizer](#oh_arkui_gestureinterruptinfo_getrecognizer) (const ArkUI_GestureInterruptInfo \*event) | 返回被打断的手势指针。  | 
| ArkUI_GestureEvent \* [OH_ArkUI_GestureInterruptInfo_GetGestureEvent](#oh_arkui_gestureinterruptinfo_getgestureevent) (const ArkUI_GestureInterruptInfo \*event) | 返回打断的手势事件数据。  | 
| [ArkUI_GestureEventActionType](#arkui_gestureeventactiontype) [OH_ArkUI_GestureEvent_GetActionType](#oh_arkui_gestureevent_getactiontype) (const ArkUI_GestureEvent \*event) | 返回手势事件类型。  | 
| const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \* [OH_ArkUI_GestureEvent_GetRawInputEvent](#oh_arkui_gestureevent_getrawinputevent) (const ArkUI_GestureEvent \*event) | 返回手势输入。  | 
| int32_t [OH_ArkUI_LongPress_GetRepeatCount](#oh_arkui_longpress_getrepeatcount) (const ArkUI_GestureEvent \*event) | 返回长按手势定时触发次数。  | 
| float [OH_ArkUI_PanGesture_GetVelocity](#oh_arkui_pangesture_getvelocity) (const ArkUI_GestureEvent \*event) | 滑动手势返回手势主方向速度。  | 
| float [OH_ArkUI_PanGesture_GetVelocityX](#oh_arkui_pangesture_getvelocityx) (const ArkUI_GestureEvent \*event) | 滑动手势返回当前手势的x轴方向速度。  | 
| float [OH_ArkUI_PanGesture_GetVelocityY](#oh_arkui_pangesture_getvelocityy) (const ArkUI_GestureEvent \*event) | 滑动手势返回当前手势的y轴方向速度。  | 
| float [OH_ArkUI_PanGesture_GetOffsetX](#oh_arkui_pangesture_getoffsetx) (const ArkUI_GestureEvent \*event) | 滑动手势返回当前手势事件x轴相对偏移量。  | 
| float [OH_ArkUI_PanGesture_GetOffsetY](#oh_arkui_pangesture_getoffsety) (const ArkUI_GestureEvent \*event) | 滑动手势返回当前手势事件y轴相对偏移量。  | 
| float [OH_ArkUI_SwipeGesture_GetAngle](#oh_arkui_swipegesture_getangle) (const ArkUI_GestureEvent \*event) | 滑动手势返回当前手势事件角度信息。  | 
| float [OH_ArkUI_SwipeGesture_GetVelocity](#oh_arkui_swipegesture_getvelocity) (const ArkUI_GestureEvent \*event) | 滑动手势场景中所有手指滑动平均速度。  | 
| float [OH_ArkUI_RotationGesture_GetAngle](#oh_arkui_rotationgesture_getangle) (const ArkUI_GestureEvent \*event) | 旋转手势返回当前手势事件角度信息。  | 
| float [OH_ArkUI_PinchGesture_GetScale](#oh_arkui_pinchgesture_getscale) (const ArkUI_GestureEvent \*event) | 捏合手势返回当前手势事件缩放信息。  | 
| float [OH_ArkUI_PinchGesture_GetCenterX](#oh_arkui_pinchgesture_getcenterx) (const ArkUI_GestureEvent \*event) | 捏合手势中心点相对于当前组件元素左上角x轴坐标。  | 
| float [OH_ArkUI_PinchGesture_GetCenterY](#oh_arkui_pinchgesture_getcentery) (const ArkUI_GestureEvent \*event) | 捏合手势中心点相对于当前组件元素左上角y轴坐标。  | 
| void \* [OH_ArkUI_QueryModuleInterfaceByName](#oh_arkui_querymoduleinterfacebyname) ([ArkUI_NativeAPIVariantKind](#arkui_nativeapivariantkind) type, const char \*structName) | 获取指定类型的Native模块接口集合。  | 
| [ArkUI_NodeEventType](#arkui_nodeeventtype) [OH_ArkUI_NodeEvent_GetEventType](#oh_arkui_nodeevent_geteventtype) ([ArkUI_NodeEvent](#arkui_nodeevent) \*event) | 获取组件事件类型。  | 
| int32_t [OH_ArkUI_NodeEvent_GetTargetId](#oh_arkui_nodeevent_gettargetid) ([ArkUI_NodeEvent](#arkui_nodeevent) \*event) | 获取事件自定义标识ID。  | 
| [ArkUI_NodeHandle](#arkui_nodehandle) [OH_ArkUI_NodeEvent_GetNodeHandle](#oh_arkui_nodeevent_getnodehandle) ([ArkUI_NodeEvent](#arkui_nodeevent) \*event) | 获取触发该组件的组件对象。  | 
| [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \* [OH_ArkUI_NodeEvent_GetInputEvent](#oh_arkui_nodeevent_getinputevent) ([ArkUI_NodeEvent](#arkui_nodeevent) \*event) | 获取组件事件中的输入事件（如触碰事件）数据。  | 
| [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) \* [OH_ArkUI_NodeEvent_GetNodeComponentEvent](#oh_arkui_nodeevent_getnodecomponentevent) ([ArkUI_NodeEvent](#arkui_nodeevent) \*event) | 获取组件事件中的数字类型数据。  | 
| [ArkUI_StringAsyncEvent](_ark_u_i___string_async_event.md) \* [OH_ArkUI_NodeEvent_GetStringAsyncEvent](#oh_arkui_nodeevent_getstringasyncevent) ([ArkUI_NodeEvent](#arkui_nodeevent) \*event) | 获取组件事件中的字符串数据。  | 
| void \* [OH_ArkUI_NodeEvent_GetUserData](#oh_arkui_nodeevent_getuserdata) ([ArkUI_NodeEvent](#arkui_nodeevent) \*event) | 获取组件事件中的用户自定义数据。  | 
| ArkUI_LayoutConstraint \* [OH_ArkUI_NodeCustomEvent_GetLayoutConstraintInMeasure](#oh_arkui_nodecustomevent_getlayoutconstraintinmeasure) (ArkUI_NodeCustomEvent \*event) | 通过自定义组件事件获取测算过程中的约束尺寸。  | 
| [ArkUI_IntOffset](_ark_u_i___int_offset.md) [OH_ArkUI_NodeCustomEvent_GetPositionInLayout](#oh_arkui_nodecustomevent_getpositioninlayout) (ArkUI_NodeCustomEvent \*event) | 通过自定义组件事件获取在布局阶段期望自身相对父组件的位置。  | 
| ArkUI_DrawContext \* [OH_ArkUI_NodeCustomEvent_GetDrawContextInDraw](#oh_arkui_nodecustomevent_getdrawcontextindraw) (ArkUI_NodeCustomEvent \*event) | 通过自定义组件事件获取绘制上下文。  | 
| int32_t [OH_ArkUI_NodeCustomEvent_GetEventTargetId](#oh_arkui_nodecustomevent_geteventtargetid) (ArkUI_NodeCustomEvent \*event) | 通过自定义组件事件获取自定义事件ID。  | 
| void \* [OH_ArkUI_NodeCustomEvent_GetUserData](#oh_arkui_nodecustomevent_getuserdata) (ArkUI_NodeCustomEvent \*event) | 通过自定义组件事件获取自定义事件参数。  | 
| [ArkUI_NodeHandle](#arkui_nodehandle) [OH_ArkUI_NodeCustomEvent_GetNodeHandle](#oh_arkui_nodecustomevent_getnodehandle) (ArkUI_NodeCustomEvent \*event) | 通过自定义组件事件获取组件对象。  | 
| [ArkUI_NodeCustomEventType](#arkui_nodecustomeventtype) [OH_ArkUI_NodeCustomEvent_GetEventType](#oh_arkui_nodecustomevent_geteventtype) (ArkUI_NodeCustomEvent \*event) | 通过自定义组件事件获取事件类型。  | 
| int32_t [OH_ArkUI_GetNodeHandleFromNapiValue](#oh_arkui_getnodehandlefromnapivalue) (napi_env env, napi_value frameNode, [ArkUI_NodeHandle](#arkui_nodehandle) \*handle) | 获取ArkTS侧创建的FrameNode节点对象映射到native侧的ArkUI_NodeHandle。  | 
| int32_t [OH_ArkUI_GetContextFromNapiValue](#oh_arkui_getcontextfromnapivalue) (napi_env env, napi_value value, [ArkUI_ContextHandle](#arkui_contexthandle) \*context) | 获取ArkTS侧创建的UIContext对象映射到native侧的ArkUI_ContextHandle。  |
| ArkUI_LayoutConstraint \* [OH_ArkUI_LayoutConstraint_Create](#oh_arkui_layoutconstraint_create) () | 创建约束尺寸。  | 
| ArkUI_LayoutConstraint \* [OH_ArkUI_LayoutConstraint_Copy](#oh_arkui_layoutconstraint_copy) (const ArkUI_LayoutConstraint \*Constraint) | 约束尺寸深拷贝。  | 
| void \* [OH_ArkUI_LayoutConstraint_Dispose](#oh_arkui_layoutconstraint_dispose) (ArkUI_LayoutConstraint \*Constraint) | 销毁约束尺寸指针。  | 
| int32_t [OH_ArkUI_LayoutConstraint_GetMaxWidth](#oh_arkui_layoutconstraint_getmaxwidth) (const ArkUI_LayoutConstraint \*Constraint) | 通过约束尺寸获取最大宽度，单位为px。  | 
| int32_t [OH_ArkUI_LayoutConstraint_GetMinWidth](#oh_arkui_layoutconstraint_getminwidth) (const ArkUI_LayoutConstraint \*Constraint) | 通过约束尺寸获取最小宽度，单位为px。  | 
| int32_t [OH_ArkUI_LayoutConstraint_GetMaxHeight](#oh_arkui_layoutconstraint_getmaxheight) (const ArkUI_LayoutConstraint \*Constraint) | 通过约束尺寸获取最大高度，单位为px。  | 
| int32_t [OH_ArkUI_LayoutConstraint_GetMinHeight](#oh_arkui_layoutconstraint_getminheight) (const ArkUI_LayoutConstraint \*Constraint) | 通过约束尺寸获取最小高度，单位为px。  | 
| int32_t [OH_ArkUI_LayoutConstraint_GetPercentReferenceWidth](#oh_arkui_layoutconstraint_getpercentreferencewidth) (const ArkUI_LayoutConstraint \*Constraint) | 通过约束尺寸获取宽度百分比基准，单位为px。  | 
| int32_t [OH_ArkUI_LayoutConstraint_GetPercentReferenceHeight](#oh_arkui_layoutconstraint_getpercentreferenceheight) (const ArkUI_LayoutConstraint \*Constraint) | 通过约束尺寸获取高度百分比基准，单位为px。  | 
| void [OH_ArkUI_LayoutConstraint_SetMaxWidth](#oh_arkui_layoutconstraint_setmaxwidth) (ArkUI_LayoutConstraint \*Constraint, int32_t value) | 设置最大宽度。  | 
| void [OH_ArkUI_LayoutConstraint_SetMinWidth](#oh_arkui_layoutconstraint_setminwidth) (ArkUI_LayoutConstraint \*Constraint, int32_t value) | 设置最小宽度。  | 
| void [OH_ArkUI_LayoutConstraint_SetMaxHeight](#oh_arkui_layoutconstraint_setmaxheight) (ArkUI_LayoutConstraint \*Constraint, int32_t value) | 设置最大高度。  | 
| void [OH_ArkUI_LayoutConstraint_SetMinHeight](#oh_arkui_layoutconstraint_setminheight) (ArkUI_LayoutConstraint \*Constraint, int32_t value) | 设置最小高度。  | 
| void [OH_ArkUI_LayoutConstraint_SetPercentReferenceWidth](#oh_arkui_layoutconstraint_setpercentreferencewidth) (ArkUI_LayoutConstraint \*Constraint, int32_t value) | 设置宽度百分比基准。  | 
| void [OH_ArkUI_LayoutConstraint_SetPercentReferenceHeight](#oh_arkui_layoutconstraint_setpercentreferenceheight) (ArkUI_LayoutConstraint \*Constraint, int32_t value) | 设置高度百分比基准。  | 
| void \* [OH_ArkUI_DrawContext_GetCanvas](#oh_arkui_drawcontext_getcanvas) (ArkUI_DrawContext \*context) | 获取绘制canvas指针，可以转换为图形库的OH_Drawing_Canvas指针进行绘制。  | 
| [ArkUI_IntSize](_ark_u_i___int_size.md) [OH_ArkUI_DrawContext_GetSize](#oh_arkui_drawcontext_getsize) (ArkUI_DrawContext \*context) | 获取可绘制区域大小。  | 
| [ArkUI_WaterFlowSectionOption](#arkui_waterflowsectionoption) \* [OH_ArkUI_WaterFlowSectionOption_Create](#oh_arkui_waterflowsectionoption_create) () | 创建FlowItem分组配置信息。  | 
| void [OH_ArkUI_WaterFlowSectionOption_Dispose](#oh_arkui_waterflowsectionoption_dispose) ([ArkUI_WaterFlowSectionOption](#arkui_waterflowsectionoption) \*option) | 销毁FlowItem分组配置信息指针。  | 
| void [OH_ArkUI_WaterFlowSectionOption_SetItemsCount](#oh_arkui_waterflowsectionoption_setitemscount) ([ArkUI_WaterFlowSectionOption](#arkui_waterflowsectionoption) \*option, int32_t index, int32_t itemsCount) | 设置分组中FlowItem数量。  | 
| void [OH_ArkUI_WaterFlowSectionOption_SetCrossCount](#oh_arkui_waterflowsectionoption_setcrosscount) ([ArkUI_WaterFlowSectionOption](#arkui_waterflowsectionoption) \*option, int32_t index, int32_t crossCount) | 设置布局栅格，纵向布局时为列数，横向布局时为行数。  | 
| void [OH_ArkUI_WaterFlowSectionOption_SetColumnsGap](#oh_arkui_waterflowsectionoption_setcolumnsgap) ([ArkUI_WaterFlowSectionOption](#arkui_waterflowsectionoption) \*option, int32_t index, float columnGap) | 设置分组的列间距。  | 
| void [OH_ArkUI_WaterFlowSectionOption_SetRowsGap](#oh_arkui_waterflowsectionoption_setrowsgap) ([ArkUI_WaterFlowSectionOption](#arkui_waterflowsectionoption) \*option, int32_t index, float rowGap) | 设置分组的行间距。  | 
| void [OH_ArkUI_WaterFlowSectionOption_SetMargin](#oh_arkui_waterflowsectionoption_setmargin) ([ArkUI_WaterFlowSectionOption](#arkui_waterflowsectionoption) \*option, int32_t index, float marginTop, float marginRight, float marginBottom, float marginLeft) | 设置分组的外边距。  | 
| [ArkUI_AnimateOption](#arkui_animateoption) \* [OH_ArkUI_AnimateOption_Create](#oh_arkui_animateoption_create) () | 创建动画效果参数。  | 
| void [OH_ArkUI_AnimateOption_Dispose](#oh_arkui_animateoption_dispose) ([ArkUI_AnimateOption](#arkui_animateoption) \*option) | 销毁动画效果参数指针。  | 
| uint32_t [OH_ArkUI_AnimateOption_GetDuration](#oh_arkui_animateoption_getduration) ([ArkUI_AnimateOption](#arkui_animateoption) \*option) | 获取动画持续时间，单位为ms(毫秒)。  | 
| float [OH_ArkUI_AnimateOption_GetTempo](#oh_arkui_animateoption_gettempo) ([ArkUI_AnimateOption](#arkui_animateoption) \*option) | 获取动画播放速度。  | 
| ArkUI_AnimationCurve [OH_ArkUI_AnimateOption_GetCurve](#oh_arkui_animateoption_getcurve) ([ArkUI_AnimateOption](#arkui_animateoption) \*option) | 获取动画曲线。  | 
| uint32_t [OH_ArkUI_AnimateOption_GetDelay](#oh_arkui_animateoption_getdelay) ([ArkUI_AnimateOption](#arkui_animateoption) \*option) | 获取动画延迟播放时间，单位为ms(毫秒)。  | 
| uint32_t [OH_ArkUI_AnimateOption_GetIterations](#oh_arkui_animateoption_getiterations) ([ArkUI_AnimateOption](#arkui_animateoption) \*option) | 获取动画播放次数。  | 
| ArkUI_AnimationPlayMode [OH_ArkUI_AnimateOption_GetPlayMode](#oh_arkui_animateoption_getplaymode) ([ArkUI_AnimateOption](#arkui_animateoption) \*option) | 获取动画播放模式。  | 
| [ArkUI_ExpectedFrameRateRange](_ark_u_i___expected_frame_rate_range.md) \* [OH_ArkUI_AnimateOption_GetExpectedFrameRateRange](#oh_arkui_animateoption_getexpectedframeraterange) ([ArkUI_AnimateOption](#arkui_animateoption) \*option) | 获取动画的期望帧率。  | 
| void [OH_ArkUI_AnimateOption_SetDuration](#oh_arkui_animateoption_setduration) ([ArkUI_AnimateOption](#arkui_animateoption) \*option, uint32_t value) | 设置动画持续时间。  | 
| void [OH_ArkUI_AnimateOption_SetTempo](#oh_arkui_animateoption_settempo) ([ArkUI_AnimateOption](#arkui_animateoption) \*option, float value) | 设置动画播放速度。  | 
| void [OH_ArkUI_AnimateOption_SetCurve](#oh_arkui_animateoption_setcurve) ([ArkUI_AnimateOption](#arkui_animateoption) \*option, ArkUI_AnimationCurve value) | 设置动画曲线。  | 
| void [OH_ArkUI_AnimateOption_SetDelay](#oh_arkui_animateoption_setdelay) ([ArkUI_AnimateOption](#arkui_animateoption) \*option, uint32_t value) | 设置动画延迟播放时间。  | 
| void [OH_ArkUI_AnimateOption_SetIterations](#oh_arkui_animateoption_setiterations) ([ArkUI_AnimateOption](#arkui_animateoption) \*option, uint32_t value) | 设置动画播放次数。  | 
| void [OH_ArkUI_AnimateOption_SetPlayMode](#oh_arkui_animateoption_setplaymode) ([ArkUI_AnimateOption](#arkui_animateoption) \*option, ArkUI_AnimationPlayMode value) | 设置动画播放模式。  | 
| void [OH_ArkUI_AnimateOption_SetExpectedFrameRateRange](#oh_arkui_animateoption_setexpectedframeraterange) ([ArkUI_AnimateOption](#arkui_animateoption) \*option, [ArkUI_ExpectedFrameRateRange](_ark_u_i___expected_frame_rate_range.md) \*value) | 设置动画的期望帧率。  | 
| int32_t [OH_ArkUI_WaterFlowSectionOption_GetSize](#oh_arkui_waterflowsectionoption_getsize) ([ArkUI_WaterFlowSectionOption](#arkui_waterflowsectionoption) \*option) | 设置FlowItem分组配置信息数组长度。  | 
| void [OH_ArkUI_WaterFlowSectionOption_RegisterGetItemMainSizeCallbackByIndex](#oh_arkui_waterflowsectionoption_registergetitemmainsizecallbackbyindex) ([ArkUI_WaterFlowSectionOption](#arkui_waterflowsectionoption) \*option, int32_t index, float(\*callback)(int32_t itemIndex)) | 通过FlowItem分组配置信息根据flowItemIndex获取指定Item的主轴大小。  | 
| int32_t [OH_ArkUI_GetDrawableDescriptorFromNapiValue](#oh_arkui_getdrawabledescriptorfromnapivalue) (napi_env env, napi_value value, [ArkUI_DrawableDescriptor](#arkui_drawabledescriptor) \*\*drawableDescriptor) |  将ArkTS侧创建的DrawableDescriptor对象映射到native侧的ArkUI_DrawableDescriptor。| 
| int32_t [OH_ArkUI_GetDrawableDescriptorFromResourceNapiValue](#oh_arkui_getdrawabledescriptorfromresourcenapivalue) (napi_env env, napi_value value, [ArkUI_DrawableDescriptor](#arkui_drawabledescriptor) \*\*drawableDescriptor) | 将ArkTS侧创建的$r资源对象映射到native侧的ArkUI_DrawableDescriptor。 | 
| [ArkUI_DrawableDescriptor](#arkui_drawabledescriptor) \* [OH_ArkUI_DrawableDescriptor_CreateFromPixelMap](#oh_arkui_drawabledescriptor_createfrompixelmap) ([OH_PixelmapNativeHandle](#oh_pixelmapnativehandle) pixelMap) | 使用 PixelMap 创建 DrawbleDescriptor 对象。  |
| [ArkUI_DrawableDescriptor](#arkui_drawabledescriptor) \* [OH_ArkUI_DrawableDescriptor_CreateFromAnimatedPixelMap](#oh_arkui_drawabledescriptor_createfromanimatedpixelmap) ([OH_PixelmapNativeHandle](#oh_pixelmapnativehandle) \*array, int32_t size) | 使用 PixelMap 图片数组创建DrawbleDescriptor 对象。  |
| void [OH_ArkUI_DrawableDescriptor_Dispose](#oh_arkui_drawabledescriptor_dispose) ([ArkUI_DrawableDescriptor](#arkui_drawabledescriptor) \*drawableDescriptor) | 销毁 DrawbleDescriptor 对象指针。  |
| [OH_PixelmapNativeHandle](#oh_pixelmapnativehandle)[OH_ArkUI_DrawableDescriptor_GetStaticPixelMap](#oh_arkui_drawabledescriptor_getstaticpixelmap) ([ArkUI_DrawableDescriptor](#arkui_drawabledescriptor) \*drawableDescriptor) | 获取 PixelMap 图片对象指针。  |
| [OH_PixelmapNativeHandle](#oh_pixelmapnativehandle) \* [OH_ArkUI_DrawableDescriptor_GetAnimatedPixelMapArray](#oh_arkui_drawabledescriptor_getanimatedpixelmaparray) ([ArkUI_DrawableDescriptor](#arkui_drawabledescriptor) \*drawableDescriptor) | 获取用于播放动画的 PixelMap 图片数组数据。  |
| int32_t [OH_ArkUI_DrawableDescriptor_GetAnimatedPixelMapArraySize](#oh_arkui_drawabledescriptor_getanimatedpixelmaparraysize) ([ArkUI_DrawableDescriptor](#arkui_drawabledescriptor) \*drawableDescriptor) | 获取用于播放动画的 PixelMap 图片数组数据。  |
| void [OH_ArkUI_DrawableDescriptor_SetAnimationDuration](#oh_arkui_drawabledescriptor_setanimationduration) ([ArkUI_DrawableDescriptor](#arkui_drawabledescriptor) \*drawableDescriptor, int32_t duration) | 设置 PixelMap 图片数组播放总时长。  |
| int32_t [OH_ArkUI_DrawableDescriptor_GetAnimationDuration](#oh_arkui_drawabledescriptor_getanimationduration) ([ArkUI_DrawableDescriptor](#arkui_drawabledescriptor) \*drawableDescriptor) | 获取 PixelMap 图片数组播放总时长。  |
| void [OH_ArkUI_DrawableDescriptor_SetAnimationIteration](#oh_arkui_drawabledescriptor_setanimationiteration) ([ArkUI_DrawableDescriptor](#arkui_drawabledescriptor) \*drawableDescriptor, int32_t iteration) | 设置 PixelMap 图片数组播放次数。  |
| int32_t [OH_ArkUI_DrawableDescriptor_GetAnimationIteration](#oh_arkui_drawabledescriptor_getanimationiteration) ([ArkUI_DrawableDescriptor](#arkui_drawabledescriptor) \*drawableDescriptor) | 获取 PixelMap 图片数组播放次数。  |
| [ArkUI_ListItemSwipeActionItem](#arkui_listitemswipeactionitem) \* [OH_ArkUI_ListItemSwipeActionItem_Create](#oh_arkui_listitemswipeactionitem_create) () | 创建ListItemSwipeActionItem接口设置的配置项。  |
| void [OH_ArkUI_ListItemSwipeActionItem_Dispose](#oh_arkui_listitemswipeactionitem_dispose) ([ArkUI_ListItemSwipeActionItem](#arkui_listitemswipeactionitem) \*item) | 销毁ListItemSwipeActionItem实例。  |
| void [OH_ArkUI_ListItemSwipeActionItem_SetContent](#oh_arkui_listitemswipeactionitem_setcontent) ([ArkUI_ListItemSwipeActionItem](#arkui_listitemswipeactionitem) \*item, ArkUI_NodeHandle node) | 设置ListItemSwipeActionItem的布局内容。  |
| void [OH_ArkUI_ListItemSwipeActionItem_SetActionAreaDistance](#oh_arkui_listitemswipeactionitem_setactionareadistance) ([ArkUI_ListItemSwipeActionItem](#arkui_listitemswipeactionitem) \*item, float distance) | 设置组件长距离滑动删除距离阈值。  |
| float [OH_ArkUI_ListItemSwipeActionItem_GetActionAreaDistance](#oh_arkui_listitemswipeactionitem_getactionareadistance) ([ArkUI_ListItemSwipeActionItem](#arkui_listitemswipeactionitem) \*item) | 获取组件长距离滑动删除距离阈值。  |
| void [OH_ArkUI_ListItemSwipeActionItem_SetOnEnterActionArea](#oh_arkui_listitemswipeactionitem_setonenteractionarea) ([ArkUI_ListItemSwipeActionItem](#arkui_listitemswipeactionitem) \*item, void(\*callback)()) | 设置滑动条目进入删除区域时调用的事件。  |
| void [OH_ArkUI_ListItemSwipeActionItem_SetOnAction](#oh_arkui_listitemswipeactionitem_setonaction) ([ArkUI_ListItemSwipeActionItem](#arkui_listitemswipeactionitem) \*item, void(\*callback)()) | 设置组件进入长距删除区后删除ListItem时调用的事件。  |
| void [OH_ArkUI_ListItemSwipeActionItem_SetOnExitActionArea](#oh_arkui_listitemswipeactionitem_setonexitactionarea) ([ArkUI_ListItemSwipeActionItem](#arkui_listitemswipeactionitem) \*item, void(\*callback)()) | 设置滑动条目退出删除区域时调用的事件。  |
| void [OH_ArkUI_ListItemSwipeActionItem_SetOnStateChange](#oh_arkui_listitemswipeactionitem_setonstatechange) ([ArkUI_ListItemSwipeActionItem](#arkui_listitemswipeactionitem) \*item, void(\*callback)([ArkUI_ListItemSwipeActionState](#arkui_listitemswipeactionstate) swipeActionState)) | 设置列表项滑动状态变化时候触发的事件。  |
| [ArkUI_ListItemSwipeActionOption](#arkui_listitemswipeactionoption) \* [OH_ArkUI_ListItemSwipeActionOption_Create](#oh_arkui_listitemswipeactionoption_create) () | 创建ListItemSwipeActionOption接口设置的配置项。  |
| void [OH_ArkUI_ListItemSwipeActionOption_Dispose](#oh_arkui_listitemswipeactionoption_dispose) ([ArkUI_ListItemSwipeActionOption](#arkui_listitemswipeactionoption) \*option) | 销毁ListItemSwipeActionOption实例。  |
| void [OH_ArkUI_ListItemSwipeActionOption_SetStart](#oh_arkui_listitemswipeactionoption_setstart) ([ArkUI_ListItemSwipeActionOption](#arkui_listitemswipeactionoption) \*option, [ArkUI_ListItemSwipeActionItem](#arkui_listitemswipeactionitem) \*item) | 设置ListItemSwipeActionItem的左侧（垂直布局）或上方（横向布局）布局内容。  |
| void [OH_ArkUI_ListItemSwipeActionOption_SetEnd](#oh_arkui_listitemswipeactionoption_setend) ([ArkUI_ListItemSwipeActionOption](#arkui_listitemswipeactionoption) \*option, [ArkUI_ListItemSwipeActionItem](#arkui_listitemswipeactionitem) \*item) | 设置ListItemSwipeActionItem的右侧（垂直布局）或下方（横向布局）布局内容。  |
| void [OH_ArkUI_ListItemSwipeActionOption_SetEdgeEffect](#oh_arkui_listitemswipeactionoption_setedgeeffect) ([ArkUI_ListItemSwipeActionOption](#arkui_listitemswipeactionoption) \*option, [ArkUI_ListItemSwipeEdgeEffect](#arkui_listitemswipeedgeeffect) edgeEffect) | 设置滑动效果。  |
| int32_t [OH_ArkUI_ListItemSwipeActionOption_GetEdgeEffect](#oh_arkui_listitemswipeactionoption_getedgeeffect) ([ArkUI_ListItemSwipeActionOption](#arkui_listitemswipeactionoption) \*option) | 获取滑动效果。  |
| void [OH_ArkUI_ListItemSwipeActionOption_SetOnOffsetChange](#oh_arkui_listitemswipeactionoption_setonoffsetchange) ([ArkUI_ListItemSwipeActionOption](#arkui_listitemswipeactionoption) \*option, void(\*callback)(float offset)) | 滑动操作偏移量更改时调用的事件。  |

## 宏定义说明


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
**描述：**

基于结构体类型获取对应结构体指针的宏函数。

**起始版本：** 12


## 类型定义说明

### ArkUI_DrawableDescriptor

```
typedef struct ArkUI_DrawableDescriptorArkUI_DrawableDescriptor
```
**描述**
定义 DrawableDescriptor 对象。

**起始版本：** 12


### ArkUI_ListItemSwipeActionItem

```
typedef struct ArkUI_ListItemSwipeActionItemArkUI_ListItemSwipeActionItem
```
**描述**
定义ListItemSwipeActionOption方法内Item的配置信息。

**起始版本：** 12


### ArkUI_ListItemSwipeActionOption

```
typedef struct ArkUI_ListItemSwipeActionOptionArkUI_ListItemSwipeActionOption
```
**描述**
定义ListItemSwipeActionOption方法的配置信息。

**起始版本：** 12


### OH_PixelmapNativeHandle

```
typedef struct OH_PixelmapNative* OH_PixelmapNativeHandle
```
**描述**
定义OH_PixelmapNative对象指针类型。

**起始版本：** 12

### ArkUI_AnimateOption

```
typedef struct ArkUI_AnimateOptionArkUI_AnimateOption
```
**描述**
设置动画效果相关参数。

**起始版本：** 12

### ArkUI_ContextHandle

```
typedef struct ArkUI_Context* ArkUI_ContextHandle
```
**描述**
定义ArkUI native UI的上下文实例对象指针定义。

**起始版本：** 12


### ArkUI_GestureDirectionMask

```
typedef uint32_t ArkUI_GestureDirectionMask
```
**描述：**

定义滑动手势方向集合。

**起始版本：** 12


### ArkUI_GestureEventActionTypeMask

```
typedef uint32_t ArkUI_GestureEventActionTypeMask
```
**描述：**

定义手势事件类型集合

例：ArkUI_GestureEventActionTypeMask actions = GESTURE_EVENT_ACTION_ACCEPT | GESTURE_EVENT_ACTION_UPDATE;

**起始版本：** 12


### ArkUI_NativeDialogHandle

```
typedef struct ArkUI_NativeDialog* ArkUI_NativeDialogHandle
```
**描述：**

定义ArkUI在Native侧的自定义弹窗控制器对象指针。

**起始版本：** 12


### ArkUI_NodeEvent

```
typedef struct ArkUI_NodeEvent ArkUI_NodeEvent
```
**描述：**

定义组件事件的通用结构类型。

**起始版本：** 12


### ArkUI_NodeHandle

```
typedef struct ArkUI_Node* ArkUI_NodeHandle
```
**描述：**

定义ArkUI native组件实例对象指针定义。

**起始版本：** 12


### ArkUI_OnWillDismissEvent

```
typedef bool(* ArkUI_OnWillDismissEvent) (int32_t reason)
```
**描述：**

弹窗关闭的回调函数。

**起始版本：** 12


### ArkUI_WaterFlowSectionOption

```
typedef struct ArkUI_WaterFlowSectionOption ArkUI_WaterFlowSectionOption
```
**描述：**

定义FlowItem分组配置信息。

**起始版本：** 12


## 枚举类型说明


### ArkUI_ListItemSwipeActionState

```
enum ArkUI_ListItemSwipeActionState
```
**描述**
定义 Listitem 组件SwipeAction方法的显隐模式。

**起始版本：** 12

| 枚举值 | 描述 |
| -------- | -------- |
| ARKUI_LIST_ITEM_SWIPE_ACTION_STATE_COLLAPSED  | 收起状态，当ListItem与主轴方向相反滑动时操作项处于隐藏状态。&nbsp;&nbsp; |
| ARKUI_LIST_ITEM_SWIPE_ACTION_STATE_EXPANDED  | 收起状态，当ListItem与主轴方向相反滑动时操作项处于显示状态。&nbsp;&nbsp; |
| ARKUI_LIST_ITEM_SWIPE_ACTION_STATE_ACTIONING  | 长距离状态，当ListItem进入长距删除区后删除ListItem的状态。&nbsp;&nbsp; |


### ArkUI_ListItemSwipeEdgeEffect

```
enum ArkUI_ListItemSwipeEdgeEffect
```
**描述**
定义 Listitem 组件SwipeAction方法的滚动模式。

**起始版本：** 12

| 枚举值 | 描述 |
| -------- | -------- |
| ARKUI_LIST_ITEM_SWIPE_EDGE_EFFECT_SPRING  | ListItem划动距离超过划出组件大小后可以继续划动。&nbsp;&nbsp; |
| ARKUI_LIST_ITEM_SWIPE_EDGE_EFFECT_NONE  | ListItem划动距离不能超过划出组件大小。&nbsp;&nbsp;


### ArkUI_AccessibilityMode

```
enum ArkUI_AccessibilityMode
```
**描述：**

定义无障碍辅助服务模式。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_ACCESSIBILITY_MODE_AUTO  | 根据组件不同会转换为“enabled”或者“disabled”。&nbsp;&nbsp; | 
| ARKUI_ACCESSIBILITY_MODE_ENABLED  | 当前组件可被无障碍辅助服务所识别。&nbsp;&nbsp; | 
| ARKUI_ACCESSIBILITY_MODE_DISABLED  | 当前组件不可被无障碍辅助服务所识别。&nbsp;&nbsp; | 
| ARKUI_ACCESSIBILITY_MODE_DISABLED_FOR_DESCENDANTS  | 当前组件及其所有子组件不可被无障碍辅助服务所识别。&nbsp;&nbsp; | 


### ArkUI_AdaptiveColor

```
enum ArkUI_AdaptiveColor
```
**描述：**

定义取色模式。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_ADAPTIVE_COLOR_DEFAULT  | 不使用取色模糊。&nbsp;&nbsp; | 
| ARKUI_ADAPTIVE_COLOR_AVERAGE  | 使用取色模糊。&nbsp;&nbsp; | 


### ArkUI_Alignment

```
enum ArkUI_Alignment
```
**描述：**

定义布局对齐枚举值。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_ALIGNMENT_TOP_START  | 顶部起始。&nbsp;&nbsp; | 
| ARKUI_ALIGNMENT_TOP  | 顶部居中。&nbsp;&nbsp; | 
| ARKUI_ALIGNMENT_TOP_END  | 顶部尾端。&nbsp;&nbsp; | 
| ARKUI_ALIGNMENT_START  | 起始端纵向居中。&nbsp;&nbsp; | 
| ARKUI_ALIGNMENT_CENTER  | 横向和纵向居中。&nbsp;&nbsp; | 
| ARKUI_ALIGNMENT_END  | 尾端纵向居中。&nbsp;&nbsp; | 
| ARKUI_ALIGNMENT_BOTTOM_START  | 底部起始端。&nbsp;&nbsp; | 
| ARKUI_ALIGNMENT_BOTTOM  | 底部横向居中。&nbsp;&nbsp; | 
| ARKUI_ALIGNMENT_BOTTOM_END  | 底部尾端。&nbsp;&nbsp; | 


### ArkUI_AnimationCurve

```
enum ArkUI_AnimationCurve
```
**描述：**

动画曲线枚举值。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_CURVE_LINEAR  | 动画从头到尾的速度都是相同。&nbsp;&nbsp; | 
| ARKUI_CURVE_EASE  | 动画以低速开始，然后加快，在结束前变慢。&nbsp;&nbsp; | 
| ARKUI_CURVE_EASE_IN  | 动画以低速开始。&nbsp;&nbsp; | 
| ARKUI_CURVE_EASE_OUT  | 动画以低速结束。&nbsp;&nbsp; | 
| ARKUI_CURVE_EASE_IN_OUT  | 动画以低速开始和结束。&nbsp;&nbsp; | 
| ARKUI_CURVE_FAST_OUT_SLOW_IN  | 动画标准曲线。&nbsp;&nbsp; | 
| ARKUI_CURVE_LINEAR_OUT_SLOW_IN  | 动画减速曲线。&nbsp;&nbsp; | 
| ARKUI_CURVE_FAST_OUT_LINEAR_IN  | 动画加速曲线。&nbsp;&nbsp; | 
| ARKUI_CURVE_EXTREME_DECELERATION  | 动画急缓曲线。&nbsp;&nbsp; | 
| ARKUI_CURVE_SHARP  | 动画锐利曲线。&nbsp;&nbsp; | 
| ARKUI_CURVE_RHYTHM  | 动画节奏曲线。&nbsp;&nbsp; | 
| ARKUI_CURVE_SMOOTH  | 动画平滑曲线。&nbsp;&nbsp; | 
| ARKUI_CURVE_FRICTION  | 动画阻尼曲线。&nbsp;&nbsp; | 


### ArkUI_AnimationPlayMode

```
enum ArkUI_AnimationPlayMode
```
**描述：**

定义动画播放模式。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_ANIMATION_PLAY_MODE_NORMAL  | 动画正向播放。&nbsp;&nbsp; | 
| ARKUI_ANIMATION_PLAY_MODE_REVERSE  | 动画反向播放。&nbsp;&nbsp; | 
| ARKUI_ANIMATION_PLAY_MODE_ALTERNATE  | 动画在奇数次（1、3、5...）正向播放，在偶数次（2、4、6...）反向播放。&nbsp;&nbsp; | 
| ARKUI_ANIMATION_PLAY_MODE_ALTERNATE_REVERSE  | 动画在奇数次（1、3、5...）反向播放，在偶数次（2、4、6...）正向播放。&nbsp;&nbsp; | 


### ArkUI_Axis

```
enum ArkUI_Axis
```
**描述：**

定义滚动方向和List组件排列方向枚举值。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_AXIS_VERTICAL  | 仅支持竖直方向滚动。&nbsp;&nbsp; | 
| ARKUI_AXIS_HORIZONTAL  | 仅支持水平方向滚动。&nbsp;&nbsp; | 


### ArkUI_BlendApplyType

```
enum ArkUI_BlendApplyType
```
**描述：**

指定的混合模式应用于视图的内容选项.

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| BLEND_APPLY_TYPE_FAST  | 在目标图像上按顺序混合视图的内容.&nbsp;&nbsp; | 
| BLEND_APPLY_TYPE_OFFSCREEN  | 将此组件和子组件内容绘制到离屏画布上，然后整体进行混合.&nbsp;&nbsp; | 


### ArkUI_BlendMode

```
enum ArkUI_BlendMode
```
**描述：**

混合模式枚举值。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_BLEND_MODE_NONE  | 将上层图像直接覆盖到下层图像上，不进行任何混合操作。&nbsp;&nbsp; | 
| ARKUI_BLEND_MODE_CLEAR  | 将源像素覆盖的目标像素清除为完全透明。&nbsp;&nbsp; | 
| ARKUI_BLEND_MODE_SRC  | r = s，只显示源像素。&nbsp;&nbsp; | 
| ARKUI_BLEND_MODE_DST  | r = d，只显示目标像素。&nbsp;&nbsp; | 
| ARKUI_BLEND_MODE_SRC_OVER  | r = s + (1 - sa) \* d，将源像素按照透明度进行混合，覆盖在目标像素上。&nbsp;&nbsp; | 
| ARKUI_BLEND_MODE_DST_OVER  | r = d + (1 - da) \* s，将目标像素按照透明度进行混合，覆盖在源像素上。&nbsp;&nbsp; | 
| ARKUI_BLEND_MODE_SRC_IN  | r = s \* da，只显示源像素中与目标像素重叠的部分。&nbsp;&nbsp; | 
| ARKUI_BLEND_MODE_DST_IN  | r = d \* sa，只显示目标像素中与源像素重叠的部分。&nbsp;&nbsp; | 
| ARKUI_BLEND_MODE_SRC_OUT  | r = s \* (1 - da)，只显示源像素中与目标像素不重叠的部分。&nbsp;&nbsp; | 
| ARKUI_BLEND_MODE_DST_OUT  | r = d \* (1 - sa)，只显示目标像素中与源像素不重叠的部分。&nbsp;&nbsp; | 
| ARKUI_BLEND_MODE_SRC_ATOP  | r = s \* da + d \* (1 - sa)，在源像素和目标像素重叠的地方绘制源像素，在源像素和目标像素不重叠的地方绘制目标像素。&nbsp;&nbsp; | 
| ARKUI_BLEND_MODE_DST_ATOP  | r = d \* sa + s \* (1 - da)，在源像素和目标像素重叠的地方绘制目标像素，在源像素和目标像素不重叠的地方绘制源像素。&nbsp;&nbsp; | 
| ARKUI_BLEND_MODE_XOR  | r = s \* (1 - da) + d \* (1 - sa)，只显示源像素与目标像素不重叠的部分。&nbsp;&nbsp; | 
| ARKUI_BLEND_MODE_PLUS  | r = min(s + d, 1)，将源像素值与目标像素值相加，并将结果作为新的像素值。&nbsp;&nbsp; | 
| ARKUI_BLEND_MODE_MODULATE  | r = s \* d，将源像素与目标像素进行乘法运算，并将结果作为新的像素值。&nbsp;&nbsp; | 
| ARKUI_BLEND_MODE_SCREEN  | r = s + d - s \* d，将两个图像的像素值相加，然后减去它们的乘积来实现混合。&nbsp;&nbsp; | 
| ARKUI_BLEND_MODE_OVERLAY  | 根据目标像素来决定使用MULTIPLY混合模式还是SCREEN混合模式。&nbsp;&nbsp; | 
| ARKUI_BLEND_MODE_DARKEN  | rc = s + d - max(s \* da, d \* sa), ra = kSrcOver，当两个颜色重叠时，较暗的颜色会覆盖较亮的颜色。&nbsp;&nbsp; | 
| ARKUI_BLEND_MODE_LIGHTEN  | rc = s + d - min(s \* da, d \* sa), ra = kSrcOver，将源图像和目标图像中的像素进行比较，选取两者中较亮的像素作为最终的混合结果。&nbsp;&nbsp; | 
| ARKUI_BLEND_MODE_COLOR_DODGE  | 使目标像素变得更亮来反映源像素。&nbsp;&nbsp; | 
| ARKUI_BLEND_MODE_COLOR_BURN  | 使目标像素变得更暗来反映源像素。&nbsp;&nbsp; | 
| ARKUI_BLEND_MODE_HARD_LIGHT  | 根据源像素的值来决定目标像素变得更亮或者更暗。根据源像素来决定使用MULTIPLY混合模式还是SCREEN混合模式。&nbsp;&nbsp; | 
| ARKUI_BLEND_MODE_SOFT_LIGHT  | 根据源像素来决定使用LIGHTEN混合模式还是DARKEN混合模式。&nbsp;&nbsp; | 
| ARKUI_BLEND_MODE_DIFFERENCE  | rc = s + d - 2 \* (min(s \* da, d \* sa)), ra = kSrcOver，对比源像素和目标像素，亮度更高的像素减去亮度更低的像素，产生高对比度的效果。&nbsp;&nbsp; | 
| ARKUI_BLEND_MODE_EXCLUSION  | rc = s + d - two(s \* d), ra = kSrcOver，对比源像素和目标像素，亮度更高的像素减去亮度更低的像素，产生柔和的效果。&nbsp;&nbsp; | 
| ARKUI_BLEND_MODE_MULTIPLY  | r = s \* (1 - da) + d \* (1 - sa) + s \* d，将源图像与目标图像进行乘法混合，得到一张新的图像。 | 
| ARKUI_BLEND_MODE_HUE  | 保留源图像的亮度和饱和度，但会使用目标图像的色调来替换源图像的色调。&nbsp;&nbsp; | 
| ARKUI_BLEND_MODE_SATURATION  | 保留目标像素的亮度和色调，但会使用源像素的饱和度来替换目标像素的饱和度。&nbsp;&nbsp; | 
| ARKUI_BLEND_MODE_COLOR  | 保留源像素的饱和度和色调，但会使用目标像素的亮度来替换源像素的亮度。&nbsp;&nbsp; | 
| ARKUI_BLEND_MODE_LUMINOSITY  | 保留目标像素的色调和饱和度，但会用源像素的亮度替换目标像素的亮度。&nbsp;&nbsp; | 


### ArkUI_BlurStyle

```
enum ArkUI_BlurStyle
```
**描述：**

定义背景模糊样式。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_BLUR_STYLE_THIN  | 轻薄材质模糊。&nbsp;&nbsp; | 
| ARKUI_BLUR_STYLE_REGULAR  | 普通厚度材质模糊。&nbsp;&nbsp; | 
| ARKUI_BLUR_STYLE_THICK  | 厚材质模糊。&nbsp;&nbsp; | 
| ARKUI_BLUR_STYLE_BACKGROUND_THIN  | 近距景深模糊。&nbsp;&nbsp; | 
| ARKUI_BLUR_STYLE_BACKGROUND_REGULAR  | 中距景深模糊。&nbsp;&nbsp; | 
| ARKUI_BLUR_STYLE_BACKGROUND_THICK  | 远距景深模糊。&nbsp;&nbsp; | 
| ARKUI_BLUR_STYLE_BACKGROUND_ULTRA_THICK  | 超远距景深模糊。&nbsp;&nbsp; | 
| ARKUI_BLUR_STYLE_NONE  | 关闭模糊。&nbsp;&nbsp; | 
| ARKUI_BLUR_STYLE_COMPONENT_ULTRA_THIN  | 组件超轻薄材质模糊。&nbsp;&nbsp; | 
| ARKUI_BLUR_STYLE_COMPONENT_THIN  | 组件轻薄材质模糊。&nbsp;&nbsp; | 
| ARKUI_BLUR_STYLE_COMPONENT_REGULAR  | 组件普通材质模糊。&nbsp;&nbsp; | 
| ARKUI_BLUR_STYLE_COMPONENT_THICK  | 组件厚材质模糊。&nbsp;&nbsp; | 
| ARKUI_BLUR_STYLE_COMPONENT_ULTRA_THICK  | 组件超厚材质模糊。&nbsp;&nbsp; | 


### ArkUI_BorderStyle

```
enum ArkUI_BorderStyle
```
**描述：**

边框线条样式枚举值。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_BORDER_STYLE_SOLID  | 显示为一条实线。&nbsp;&nbsp; | 
| ARKUI_BORDER_STYLE_DASHED  | 显示为一系列短的方形虚线。&nbsp;&nbsp; | 
| ARKUI_BORDER_STYLE_DOTTED  | 显示为一系列圆点。&nbsp;&nbsp; | 


### ArkUI_CalendarAlignment

```
enum ArkUI_CalendarAlignment
```
**描述：**

日历选择器与入口组件对齐方式。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_CALENDAR_ALIGNMENT_START  | 选择器和入口组件左对齐方式。&nbsp;&nbsp; | 
| ARKUI_CALENDAR_ALIGNMENT_CENTER  | 选择器和入口组件居中对齐方式。&nbsp;&nbsp; | 
| ARKUI_CALENDAR_ALIGNMENT_END  | 选择器和入口组件右对齐方式。&nbsp;&nbsp; | 


### ArkUI_CancelButtonStyle

```
enum ArkUI_CancelButtonStyle
```
**描述：**

定义清除按钮样式枚举值。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_CANCELBUTTON_STYLE_CONSTANT  | 清除按钮常显样式。&nbsp;&nbsp; | 
| ARKUI_CANCELBUTTON_STYLE_INVISIBLE  | 清除按钮常隐样式。&nbsp;&nbsp; | 
| ARKUI_CANCELBUTTON_STYLE_INPUT  | 清除按钮输入样式。&nbsp;&nbsp; | 


### ArkUI_CheckboxShape

```
enum ArkUI_CheckboxShape
```
**描述：**

定义CheckBox组件形状。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ArkUI_CHECKBOX_SHAPE_CIRCLE  | 圆形。&nbsp;&nbsp; | 
| ArkUI_CHECKBOX_SHAPE_ROUNDED_SQUARE  | 圆角方形。&nbsp;&nbsp; | 


### ArkUI_ClipType

```
enum ArkUI_ClipType
```
**描述：**

裁剪类型枚举。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_CLIP_TYPE_RECTANGLE  | 矩形类型。&nbsp;&nbsp; | 
| ARKUI_CLIP_TYPE_CIRCLE  | 圆形类型。&nbsp;&nbsp; | 
| ARKUI_CLIP_TYPE_ELLIPSE  | 椭圆形类型。&nbsp;&nbsp; | 
| ARKUI_CLIP_TYPE_PATH  | 路径类型。&nbsp;&nbsp; | 

### ArkUI_ColorMode

```
enum ArkUI_ColorMode
```
**描述：**

定义深浅色模式。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_COLOR_MODE_SYSTEM  | 跟随系统深浅色模式。&nbsp;&nbsp; | 
| ARKUI_COLOR_MODE_LIGHT  | 固定使用浅色模式。&nbsp;&nbsp; | 
| ARKUI_COLOR_MODE_DARK  | 固定使用深色模式。&nbsp;&nbsp; | 


### ArkUI_ColorStrategy

```
enum ArkUI_ColorStrategy
```
**描述：**

前景色枚举值。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_COLOR_STRATEGY_INVERT  | 前景色为控件背景色的反色。&nbsp;&nbsp; | 
| ARKUI_COLOR_STRATEGY_AVERAGE  | 控件背景阴影色为控件背景阴影区域的平均色。&nbsp;&nbsp; | 
| ARKUI_COLOR_STRATEGY_PRIMARY  | 控件背景阴影色为控件背景阴影区域的主色。&nbsp;&nbsp; | 


### ArkUI_CopyOptions

```
enum ArkUI_CopyOptions
```
**描述：**

定义文本复制黏贴模式枚举值。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_COPY_OPTIONS_NONE  | 不支持复制。&nbsp;&nbsp; | 
| ARKUI_COPY_OPTIONS_IN_APP  | 支持应用内复制。&nbsp;&nbsp; | 
| ARKUI_COPY_OPTIONS_LOCAL_DEVICE  | 支持设备内复制。&nbsp;&nbsp; | 
| ARKUI_COPY_OPTIONS_CROSS_DEVICE  | 支持跨设备复制。&nbsp;&nbsp; | 


### ArkUI_Direction

```
enum ArkUI_Direction
```
**描述：**

设置容器元素内主轴方向上的布局枚举值。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_DIRECTION_LTR  | 元素从左到右布局。&nbsp;&nbsp; | 
| ARKUI_DIRECTION_RTL  | 元素从右到左布局。&nbsp;&nbsp; | 
| ARKUI_DIRECTION_AUTO  | 使用系统默认布局方向。&nbsp;&nbsp; | 


### ArkUI_DismissReason

```
enum ArkUI_DismissReason
```
**描述：**

弹窗关闭的触发方式。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| DIALOG_DISMISS_BACK_PRESS  | 系统定义的返回操作、键盘ESC触发。&nbsp;&nbsp; | 
| DIALOG_DISMISS_TOUCH_OUTSIDE  | 点击遮障层触发。&nbsp;&nbsp; | 


### ArkUI_EdgeEffect

```
enum ArkUI_EdgeEffect
```
**描述：**

定义边缘滑动效果枚举值。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_EDGE_EFFECT_SPRING  | 弹性物理动效，滑动到边缘后可以根据初始速度或通过触摸事件继续滑动一段距离，松手后回弹。&nbsp;&nbsp; | 
| ARKUI_EDGE_EFFECT_FADE  | 阴影效果，滑动到边缘后会有圆弧状的阴影。&nbsp;&nbsp; | 
| ARKUI_EDGE_EFFECT_NONE  | 滑动到边缘后无效果。&nbsp;&nbsp; | 


### ArkUI_EllipsisMode

```
enum ArkUI_EllipsisMode
```
**描述：**

定义文本省略位置。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_ELLIPSIS_MODE_START  | 省略行首内容。&nbsp;&nbsp; | 
| ARKUI_ELLIPSIS_MODE_CENTER  | 省略行中内容。&nbsp;&nbsp; | 
| ARKUI_ELLIPSIS_MODE_END  | 省略行末内容。&nbsp;&nbsp; | 


### ArkUI_EnterKeyType

```
enum ArkUI_EnterKeyType
```
**描述：**

定义单行文本输入法回车键类型枚举值。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_ENTER_KEY_TYPE_GO  | 显示为开始样式。&nbsp;&nbsp; | 
| ARKUI_ENTER_KEY_TYPE_SEARCH  | 显示为搜索样式。&nbsp;&nbsp; | 
| ARKUI_ENTER_KEY_TYPE_SEND  | 显示为发送样式。&nbsp;&nbsp; | 
| ARKUI_ENTER_KEY_TYPE_NEXT  | 显示为下一个样式。&nbsp;&nbsp; | 
| ARKUI_ENTER_KEY_TYPE_DONE  | 显示为完成样式。&nbsp;&nbsp; | 
| ARKUI_ENTER_KEY_TYPE_PREVIOUS  | 显示为上一个样式。&nbsp;&nbsp; | 
| ARKUI_ENTER_KEY_TYPE_NEW_LINE  | 显示为换行样式。&nbsp;&nbsp; | 

### ArkUI_FinishCallbackType

```
enum ArkUI_FinishCallbackType
```
**描述**
在动画中定义onFinish回调的类型。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_FINISH_CALLBACK_REMOVED  | 当整个动画结束并立即删除时，将触发回调。&nbsp;&nbsp; | 
| ARKUI_FINISH_CALLBACK_LOGICALLY  | 当动画在逻辑上处于下降状态，但可能仍处于其长尾状态时，将触发回调。&nbsp;&nbsp; | 


### ArkUI_FlexAlignment

```
enum ArkUI_FlexAlignment
```
**描述：**

定义垂直方向对齐方式。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_FLEX_ALIGNMENT_START  | 主轴方向首端对齐。&nbsp;&nbsp; | 
| ARKUI_FLEX_ALIGNMENT_CENTER  | 主轴方向中心对齐。&nbsp;&nbsp; | 
| ARKUI_FLEX_ALIGNMENT_END  | 主轴方向尾部对齐。&nbsp;&nbsp; | 
| ARKUI_FLEX_ALIGNMENT_SPACE_BETWEEN  | Flex主轴方向均匀分配弹性元素，相邻元素之间距离相同，第一个元素行首对齐，最后的元素行尾对齐。&nbsp;&nbsp; | 
| ARKUI_FLEX_ALIGNMENT_SPACE_AROUND  | Flex主轴方向均匀分配弹性元素，相邻元素之间距离相同，第一个元素到行首的距离时相邻元素间距离的一半。&nbsp;&nbsp; | 
| ARKUI_FLEX_ALIGNMENT_SPACE_EVENLY  | Flex主轴方向均匀分配弹性元素，相邻元素之间距离、第一个元素到行首的距离和最后的元素到行尾的距离均相等。&nbsp;&nbsp; | 


### ArkUI_FlexDirection

```
enum ArkUI_FlexDirection
```
**描述：**

定义Flex容器的主轴方向。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_FLEX_DIRECTION_ROW  | 主轴与行方向一致。&nbsp;&nbsp; | 
| ARKUI_FLEX_DIRECTION_COLUMN  | 主轴与列方向一致。&nbsp;&nbsp; | 
| ARKUI_FLEX_DIRECTION_ROW_REVERSE  | 主轴与行方向相反。&nbsp;&nbsp; | 
| ARKUI_FLEX_DIRECTION_COLUMN_REVERSE  | 主轴与列方向相反。&nbsp;&nbsp; | 


### ArkUI_FlexWrap

```
enum ArkUI_FlexWrap
```
**描述：**

定义Flex行列布局模式模式。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_FLEX_WRAP_NO_WRAP  | 单行/单列布局，子项不能超出容器。&nbsp;&nbsp; | 
| ARKUI_FLEX_WRAP_WRAP  | 多行/多列布局，子项允许超出容器。&nbsp;&nbsp; | 
| ARKUI_FLEX_WRAP_WRAP_REVERSE  | 反向多行/多列布局，子项允许超出容器。&nbsp;&nbsp; | 


### ArkUI_FontStyle

```
enum ArkUI_FontStyle
```
**描述：**

定义字体样式枚举值。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_FONT_STYLE_NORMAL  | 标准字体样式。&nbsp;&nbsp; | 
| ARKUI_FONT_STYLE_ITALIC  | 斜体字体样式。&nbsp;&nbsp; | 


### ArkUI_FontWeight

```
enum ArkUI_FontWeight
```
**描述：**

定义字体粗细/字重枚举值。

**起始版本：** 12

| 枚举值 | 描述 | 
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
| ARKUI_FONT_WEIGHT_BOLD  | 字体较粗。&nbsp;&nbsp; | 
| ARKUI_FONT_WEIGHT_NORMAL  | 字体粗细正常&nbsp;&nbsp; | 
| ARKUI_FONT_WEIGHT_BOLDER  | 字体非常粗。&nbsp;&nbsp; | 
| ARKUI_FONT_WEIGHT_LIGHTER  | 字体较细。&nbsp;&nbsp; | 
| ARKUI_FONT_WEIGHT_MEDIUM  | 字体粗细适中。&nbsp;&nbsp; | 
| ARKUI_FONT_WEIGHT_REGULAR  | 字体粗细正常&nbsp;&nbsp; | 


### ArkUI_GestureDirection

```
enum ArkUI_GestureDirection
```
**描述：**

定义滑动手势方向。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| GESTURE_DIRECTION_ALL  | 所有方向。&nbsp;&nbsp; | 
| GESTURE_DIRECTION_HORIZONTAL  | 水平方向。&nbsp;&nbsp; | 
| GESTURE_DIRECTION_VERTICAL  | 竖直方向。&nbsp;&nbsp; | 
| GESTURE_DIRECTION_LEFT  | 向左方向。&nbsp;&nbsp; | 
| GESTURE_DIRECTION_RIGHT  | 向右方向。&nbsp;&nbsp; | 
| GESTURE_DIRECTION_UP  | 向上方向。&nbsp;&nbsp; | 
| GESTURE_DIRECTION_DOWN  | 向下方向。&nbsp;&nbsp; | 
| GESTURE_DIRECTION_NONE  | 任何方向都不触发手势事件。&nbsp;&nbsp; | 


### ArkUI_GestureEventActionType

```
enum ArkUI_GestureEventActionType
```
**描述：**

定义手势事件类型。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| GESTURE_EVENT_ACTION_ACCEPT  | 手势事件触发。&nbsp;&nbsp; | 
| GESTURE_EVENT_ACTION_UPDATE  | 手势事件更新。&nbsp;&nbsp; | 
| GESTURE_EVENT_ACTION_END  | 手势事件结束。&nbsp;&nbsp; | 
| GESTURE_EVENT_ACTION_CANCEL  | 手势事件取消。&nbsp;&nbsp; | 


### ArkUI_GestureInterruptResult

```
enum ArkUI_GestureInterruptResult
```
**描述：**

定义手势打断结果。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| GESTURE_INTERRUPT_RESULT_CONTINUE  | 手势继续。&nbsp;&nbsp; | 
| GESTURE_INTERRUPT_RESULT_REJECT  | 手势打断。&nbsp;&nbsp; | 


### ArkUI_GestureMask

```
enum ArkUI_GestureMask
```
**描述：**

定义手势屏蔽模式

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| NORMAL_GESTURE_MASK  | 不屏蔽子组件的手势，按照默认手势识别顺序进行识别。&nbsp;&nbsp; | 
| IGNORE_INTERNAL_GESTURE_MASK  | 屏蔽子组件的手势，包括子组件上系统内置的手势。&nbsp;&nbsp; | 


### ArkUI_GesturePriority

```
enum ArkUI_GesturePriority
```
**描述：**

定义手势事件模式

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| NORMAL  | 正常手势。&nbsp;&nbsp; | 
| PRIORITY  | 高优先级手势。&nbsp;&nbsp; | 
| PARALLEL  | 并发手势。&nbsp;&nbsp; | 


### ArkUI_GestureRecognizerType

```
enum ArkUI_GestureRecognizerType
```
**描述：**

定义手势类型

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| TAP_GESTURE  | 敲击手势。&nbsp;&nbsp; | 
| LONG_PRESS_GESTURE  | 长按手势。&nbsp;&nbsp; | 
| PAN_GESTURE  | 拖动手势。&nbsp;&nbsp; | 
| PINCH_GESTURE  | 捏合手势。&nbsp;&nbsp; | 
| ROTATION_GESTURE  | 旋转手势。&nbsp;&nbsp; | 
| SWIPE_GESTURE  | 滑动手势。&nbsp;&nbsp; | 
| GROUP_GESTURE  | 手势组合。&nbsp;&nbsp; | 


### ArkUI_GroupGestureMode

```
enum ArkUI_GroupGestureMode
```
**描述：**

定义手势组事件模式。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| PARALLEL_GROUP  | 并发手势模式，注册的手势同时识别，直到所有手势识别结束，手势识别互相不影响。&nbsp;&nbsp; | 
| EXCLUSIVE_GROUP  | 互斥手势模式，注册的手势同时识别，若有一个手势识别成功，则结束手势识别。&nbsp;&nbsp; | 


### ArkUI_HitTestMode

```
enum ArkUI_HitTestMode
```
**描述：**

触摸测试控制枚举值。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_HIT_TEST_MODE_DEFAULT  | 默认触摸测试效果。&nbsp;&nbsp; | 
| ARKUI_HIT_TEST_MODE_BLOCK  | 自身响应触摸测试。&nbsp;&nbsp; | 
| ARKUI_HIT_TEST_MODE_TRANSPARENT  | 自身和子节点都响应触摸测试。&nbsp;&nbsp; | 
| ARKUI_HIT_TEST_MODE_NONE  | 自身不响应触摸测试。&nbsp;&nbsp; | 


### ArkUI_HorizontalAlignment

```
enum ArkUI_HorizontalAlignment
```
**描述：**

定义语言方向对齐方式。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_HORIZONTAL_ALIGNMENT_START  | 按照语言方向起始端对齐。&nbsp;&nbsp; | 
| ARKUI_HORIZONTAL_ALIGNMENT_CENTER  | 居中对齐，默认对齐方式。&nbsp;&nbsp; | 
| ARKUI_HORIZONTAL_ALIGNMENT_END  | 按照语言方向末端对齐。&nbsp;&nbsp; | 


### ArkUI_ImageInterpolation

```
enum ArkUI_ImageInterpolation
```
**描述：**

定义图片插值效果。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_IMAGE_INTERPOLATION_NONE  | 不使用图片插值。&nbsp;&nbsp; | 
| ARKUI_IMAGE_INTERPOLATION_LOW  | 低图片插值。&nbsp;&nbsp; | 
| ARKUI_IMAGE_INTERPOLATION_MEDIUM  | 中图片插值。&nbsp;&nbsp; | 
| ARKUI_IMAGE_INTERPOLATION_HIGH  | 高图片插值，插值质量最高。&nbsp;&nbsp; | 


### ArkUI_ImageRenderMode

```
enum ArkUI_ImageRenderMode
```
**描述：**

定义图片渲染模式。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_IMAGE_RENDER_MODE_ORIGINAL  | 原色渲染模式。&nbsp;&nbsp; | 
| ARKUI_IMAGE_RENDER_MODE_TEMPLATE  | 黑白渲染模式。&nbsp;&nbsp; | 


### ArkUI_ImageRepeat

```
enum ArkUI_ImageRepeat
```
**描述：**

定义图片重复铺设枚举值。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_IMAGE_REPEAT_NONE  | 不重复。&nbsp;&nbsp; | 
| ARKUI_IMAGE_REPEAT_X  | 在X轴方向重复。&nbsp;&nbsp; | 
| ARKUI_IMAGE_REPEAT_Y  | 在Y轴方向重复。&nbsp;&nbsp; | 
| ARKUI_IMAGE_REPEAT_XY  | 在X轴和Y轴方向重复。&nbsp;&nbsp; | 


### ArkUI_ImageSize

```
enum ArkUI_ImageSize
```
**描述：**

定义图片宽高样式。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_IMAGE_SIZE_AUTO  | 保持原图的比例不变。&nbsp;&nbsp; | 
| ARKUI_IMAGE_SIZE_COVER  | 默认值，保持宽高比进行缩小或者放大，使得图片两边都大于或等于显示边界。&nbsp;&nbsp; | 
| ARKUI_IMAGE_SIZE_CONTAIN  | 保持宽高比进行缩小或者放大，使得图片完全显示在显示边界内。&nbsp;&nbsp; | 


### ArkUI_ImageSpanAlignment

```
enum ArkUI_ImageSpanAlignment
```
**描述：**

定义图片基于文本的对齐方式。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_IMAGE_SPAN_ALIGNMENT_BASELINE  | 图片下边沿与文本BaseLine对齐。&nbsp;&nbsp; | 
| ARKUI_IMAGE_SPAN_ALIGNMENT_BOTTOM  | 图片下边沿与文本下边沿对齐。&nbsp;&nbsp; | 
| ARKUI_IMAGE_SPAN_ALIGNMENT_CENTER  | 图片中间与文本中间对齐。&nbsp;&nbsp; | 
| ARKUI_IMAGE_SPAN_ALIGNMENT_TOP  | 图片上边沿与文本上边沿对齐。&nbsp;&nbsp; | 


### ArkUI_ItemAlignment

```
enum ArkUI_ItemAlignment
```
**描述：**

设置子组件在父容器交叉轴的对齐格式枚举值。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_ITEM_ALIGNMENT_AUTO  | 使用Flex容器中默认配置。&nbsp;&nbsp; | 
| ARKUI_ITEM_ALIGNMENT_START  | 元素在Flex容器中，交叉轴方向首部对齐。&nbsp;&nbsp; | 
| ARKUI_ITEM_ALIGNMENT_CENTER  | 元素在Flex容器中，交叉轴方向居中对齐。&nbsp;&nbsp; | 
| ARKUI_ITEM_ALIGNMENT_END  | 元素在Flex容器中，交叉轴方向底部对齐。&nbsp;&nbsp; | 
| ARKUI_ITEM_ALIGNMENT_STRETCH  | 元素在Flex容器中，交叉轴方向拉伸填充。&nbsp;&nbsp; | 
| ARKUI_ITEM_ALIGNMENT_BASELINE  | 元素在Flex容器中，交叉轴方向文本基线对齐。&nbsp;&nbsp; | 

### ArkUI_LengthMetricUnit

```
enum ArkUI_LengthMetricUnit
```
**描述**
定义组件的单位模式。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_LENGTH_METRIC_UNIT_DEFAULT  | 默认，字体类单位为FP，非字体类单位为VP。&nbsp;&nbsp; | 
| ARKUI_LENGTH_METRIC_UNIT_PX  | 单位为PX。&nbsp;&nbsp; | 
| ARKUI_LENGTH_METRIC_UNIT_VP  | 单位为VP。&nbsp;&nbsp; | 
| ARKUI_LENGTH_METRIC_UNIT_FP  | 单位为FP。&nbsp;&nbsp; |


### ArkUI_LinearGradientDirection

```
enum ArkUI_LinearGradientDirection
```
**描述：**

定义渐变方向结构。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_LINEAR_GRADIENT_DIRECTION_LEFT  | 向左渐变。&nbsp;&nbsp; | 
| ARKUI_LINEAR_GRADIENT_DIRECTION_TOP  | 向上渐变。&nbsp;&nbsp; | 
| ARKUI_LINEAR_GRADIENT_DIRECTION_RIGHT  | 向右渐变。&nbsp;&nbsp; | 
| ARKUI_LINEAR_GRADIENT_DIRECTION_BOTTOM  | 向下渐变。&nbsp;&nbsp; | 
| ARKUI_LINEAR_GRADIENT_DIRECTION_LEFT_TOP  | 向左上渐变。&nbsp;&nbsp; | 
| ARKUI_LINEAR_GRADIENT_DIRECTION_LEFT_BOTTOM  | 向左下渐变。&nbsp;&nbsp; | 
| ARKUI_LINEAR_GRADIENT_DIRECTION_RIGHT_TOP  | 向右上渐变。&nbsp;&nbsp; | 
| ARKUI_LINEAR_GRADIENT_DIRECTION_RIGHT_BOTTOM  | 向右下渐变。&nbsp;&nbsp; | 
| ARKUI_LINEAR_GRADIENT_DIRECTION_NONE  | 不渐变。&nbsp;&nbsp; | 
| ARKUI_LINEAR_GRADIENT_DIRECTION_CUSTOM  | 自定义渐变方向.&nbsp;&nbsp; | 


### ArkUI_MaskType

```
enum ArkUI_MaskType
```
**描述：**

遮罩类型枚举。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_MASK_TYPE_RECTANGLE  | 矩形类型。&nbsp;&nbsp; | 
| ARKUI_MASK_TYPE_CIRCLE  | 圆形类型。&nbsp;&nbsp; | 
| ARKUI_MASK_TYPE_ELLIPSE  | 椭圆形类型。&nbsp;&nbsp; | 
| ARKUI_MASK_TYPE_PATH  | 路径类型。&nbsp;&nbsp; | 
| ARKUI_MASK_TYPE_PROGRESS  | 进度类型。&nbsp;&nbsp; | 


### ArkUI_NativeAPIVariantKind

```
enum ArkUI_NativeAPIVariantKind
```
**描述：**

定义Native接口集合类型。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_NATIVE_NODE  | UI组件相关接口类型，详见&lt;arkui/native_node.h&gt;中的结构体类型定义。&nbsp;&nbsp; | 
| ARKUI_NATIVE_DIALOG  | 弹窗相关接口类型，详见&lt;arkui/native_dialog.h&gt;中的结构体类型定义。&nbsp;&nbsp; | 
| ARKUI_NATIVE_GESTURE  | 手势相关接口类型，详见&lt;arkui/native_gesture.h&gt;中的结构体类型定义。&nbsp;&nbsp; | 
| ARKUI_NATIVE_ANIMATE  |  动画相关接口类型，详见<arkui/native_animate.h>中的结构体类型定义。|

### ArkUI_NodeAttributeType

```
enum ArkUI_NodeAttributeType
```
**描述：**

定义ArkUI在Native侧可以设置的属性样式集合。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| NODE_WIDTH  | 宽度属性，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32：宽度数值，单位为vp；<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32：宽度数值，单位为vp； | 
| NODE_HEIGHT  | 高度属性，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32：高度数值，单位为vp；<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32：高度数值，单位为vp； | 
| NODE_BACKGROUND_COLOR  | 背景色属性，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].u32：背景色数值，0xargb格式，形如 0xFFFF0000 表示红色；<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].u32：背景色数值，0xargb格式，形如 0xFFFF0000 表示红色； | 
| NODE_BACKGROUND_IMAGE  | 背景色图片属性，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.string: 图片地址；<br/>.value[0]?.i32：可选值，repeat参数，参数类型[ArkUI_ImageRepeat](#arkui_imagerepeat)，默认值为ARKUI_IMAGE_REPEAT_NONE；<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.string: 图片地址；<br/>.value[0].i32：repeat参数，参数类型[ArkUI_ImageRepeat](#arkui_imagerepeat)； | 
| NODE_PADDING  | 内间距属性，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式有两种：<br/>1：上下左右四个位置的内间距值相等。<br/>.value[0].f32：内间距数值，单位为vp；<br/>2：分别指定上下左右四个位置的内间距值。<br/>.value[0].f32：上内间距数值，单位为vp；<br/>.value[1].f32：右内间距数值，单位为vp；<br/>.value[2].f32：下内间距数值，单位为vp；<br/>.value[3].f32：左内间距数值，单位为vp；<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32：上内间距数值，单位为vp；<br/>.value[1].f32：右内间距数值，单位为vp；<br/>.value[2].f32：下内间距数值，单位为vp；<br/>.value[3].f32：左内间距数值，单位为vp； | 
| NODE_ID  | 组件ID属性，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.string: ID的内容；<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.string: ID的内容； | 
| NODE_ENABLED  | 设置组件是否可交互，支持属性设置，属性重置和属性获取。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：false表示不可交互，true表示可交互；<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：0表示不可交互，1表示可交互； | 
| NODE_MARGIN  | 外间距属性，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式有两种：<br/>1：上下左右四个位置的外间距值相等。<br/>.value[0].f32：外间距数值，单位为vp；<br/>2：分别指定上下左右四个位置的外间距值。<br/>.value[0].f32：上外间距数值，单位为vp；<br/>.value[1].f32：右外间距数值，单位为vp；<br/>.value[2].f32：下外间距数值，单位为vp；<br/>.value[3].f32：左外间距数值，单位为vp；<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32：上外间距数值，单位为vp；<br/>.value[1].f32：右外间距数值，单位为vp；<br/>.value[2].f32：下外间距数值，单位为vp；<br/>.value[3].f32：左外间距数值，单位为vp； | 
| NODE_TRANSLATE  | 设置组件平移，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32： x轴移动距离，单位vp，默认值0；<br/>.value[1].f32： y轴移动距离，单位vp，默认值0；<br/>.value[2].f32： z轴移动距离，单位vp，默认值0。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32： x轴移动距离，单位vp；<br/>.value[1].f32： y轴移动距离，单位vp；<br/>.value[2].f32： z轴移动距离，单位vp。 | 
| NODE_SCALE  | 设置组件缩放，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32： x轴的缩放系数，默认值1；<br/>.value[1].f32： y轴的缩放系数，默认值1。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32： x轴的缩放系数；<br/>.value[1].f32： y轴的缩放系数。 | 
| NODE_ROTATE  | 设置组件旋转，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32： 旋转轴向量x坐标，默认值0；<br/>.value[1].f32： 旋转轴向量y坐标，默认值0；<br/>.value[2].f32： 旋转轴向量z坐标，默认值0；<br/>.value[3].f32： 旋转角度，默认值0；<br/>.value[4].f32： 视距，即视点到z=0平面的距离，单位vp，默认值0。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32： 旋转轴向量x坐标；<br/>.value[1].f32： 旋转轴向量y坐标；<br/>.value[2].f32： 旋转轴向量z坐标；<br/>.value[3].f32： 旋转角度；<br/>.value[4].f32： 视距，即视点到z=0平面的距离，单位vp。 | 
| NODE_BRIGHTNESS  | 设置组件高光效果，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32： 亮度值，默认值1.0，推荐取值范围[0,2]。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32： 亮度值。 | 
| NODE_SATURATION  | 设置组件饱和度效果，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32： 饱和度值，默认值1.0，推荐取值范围[0,FLT_MAX]。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32： 饱和度值。 | 
| NODE_BLUR  | 设置组件内容模糊效果，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32： 模糊半径，模糊半径越大越模糊，为0时不模糊。单位vp，默认值0.0。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32： 模糊半径，模糊半径越大越模糊，为0时不模糊。单位vp。 | 
| NODE_LINEAR_GRADIENT  | 设置组件颜色渐变效果，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32： 线性渐变的起始角度。0点方向顺时针旋转为正向角度，默认值：180；<br/>.value[1].i32：线性渐变的方向，设置angle后不生效。数据类型[ArkUI_LinearGradientDirection](#arkui_lineargradientdirection)<br/>.value[2].i32： 为渐变的颜色重复着色，默认值 false。<br/>.object: 指定某百分比位置处的渐变色颜色，设置非法颜色直接跳过：<br/>colors：渐变色颜色颜色。<br/>stops：渐变位置。<br/>size：颜色个数。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32： 线性渐变的起始角度。<br/>.value[1].i32：线性渐变的方向，设置angle后不生效。<br/>.value[0].i32： 为渐变的颜色重复着色。<br/>.object: 指定某百分比位置处的渐变色颜色，设置非法颜色直接跳过：<br/>colors：渐变色颜色颜色。<br/>stops：渐变位置。<br/>size：颜色个数。 | 
| NODE_ALIGNMENT  | 设置组件内容在元素绘制区域内的对齐方式，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32： 对齐方式，数据类型[ArkUI_Alignment](#arkui_alignment)，默认值ARKUI_ALIGNMENT_CENTER。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32： 对齐方式，数据类型[ArkUI_Alignment](#arkui_alignment)。 | 
| NODE_OPACITY  | 透明度属性，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32：透明度数值，取值范围为0到1。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32：透明度数值，取值范围为0到1。 | 
| NODE_BORDER_WIDTH  | 边框宽度属性，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>1: .value[0].f32：统一设置四条边的边框宽度。<br/>2: .value[0].f32：设置上边框的边框宽度。<br/>.value[1].f32：设置右边框的边框宽度。<br/>.value[2].f32：设置下边框的边框宽度。<br/>.value[3].f32：设置左边框的边框宽度。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32：设置上边框的边框宽度。<br/>.value[1].f32：设置右边框的边框宽度。<br/>.value[2].f32：设置下边框的边框宽度。<br/>.value[3].f32：设置左边框的边框宽度。 | 
| NODE_BORDER_RADIUS  | 边框圆角属性，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>1: .value[0].f32：统一设置四条边的边框圆角。<br/>2: .value[0].f32：设置左上角圆角半径。<br/>.value[1].f32：设置右上角圆角半径。<br/>.value[2].f32：设置左下角圆角半径。<br/>.value[3].f32：设置右下角圆角半径。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32：设置左上角圆角半径。<br/>.value[1].f32：设置右上角圆角半径。<br/>.value[2].f32：设置左下角圆角半径。<br/>.value[3].f32：设置右下角圆角半径。 | 
| NODE_BORDER_COLOR  | 边框颜色属性，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>1: .value[0].u32：统一设置四条边的边框颜色，使用0xargb表示，如0xFFFF11FF。<br/>2: .value[0].u32：设置上侧边框颜色，使用0xargb表示，如0xFFFF11FF。<br/>.value[1].u32：设置右侧边框颜色，使用0xargb表示，如0xFFFF11FF。<br/>.value[2].u32：设置下侧边框颜色，使用0xargb表示，如0xFFFF11FF。<br/>.value[3].u32：设置左侧边框颜色，使用0xargb表示，如0xFFFF11FF。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].u32：设置上侧边框颜色，使用0xargb表示，如0xFFFF11FF。<br/>.value[1].u32：设置右侧边框颜色，使用0xargb表示，如0xFFFF11FF。<br/>.value[2].u32：设置下侧边框颜色，使用0xargb表示，如0xFFFF11FF。<br/>.value[3].u32：设置左侧边框颜色，使用0xargb表示，如0xFFFF11FF。 | 
| NODE_BORDER_STYLE  | 边框线条样式属性，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>1: .value[0].i32：统一设置四条边的边框线条样式，参数类型[ArkUI_BorderStyle](#arkui_borderstyle)，默认值为ARKUI_BORDER_STYLE_SOLID。<br/>2:.value[0].i32：设置上侧边框线条样式，参数类型{\@linkArkUI_BorderStyle}，默认值为ARKUI_BORDER_STYLE_SOLID。<br/>.value[1].i32：设置右侧边框线条样式，参数类型[ArkUI_BorderStyle](#arkui_borderstyle)，默认值为ARKUI_BORDER_STYLE_SOLID。<br/>.value[2].i32：设置下侧边框线条样式，参数类型[ArkUI_BorderStyle](#arkui_borderstyle)，默认值为ARKUI_BORDER_STYLE_SOLID。<br/>.value[3].i32：设置左侧边框线条样式，参数类型[ArkUI_BorderStyle](#arkui_borderstyle)，默认值为ARKUI_BORDER_STYLE_SOLID。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：上侧边框线条样式对应的数值。<br/>.value[1].i32：右侧边框线条样式对应的数值。<br/>.value[2].i32：下侧边框线条样式对应的数值。<br/>.value[3].i32：左侧边框线条样式对应的数值。 | 
| NODE_Z_INDEX  | 组件的堆叠顺序属性，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32：堆叠顺序数值。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32：堆叠顺序数值。 | 
| NODE_VISIBILITY  | 组件是否可见属性，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：控制当前组件显示或隐藏，参数类型[ArkUI_Visibility](#arkui_visibility)，默认值为ARKUI_VISIBILITY_VISIBLE。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：控制当前组件显示或隐藏，参数类型[ArkUI_Visibility](#arkui_visibility)，默认值为ARKUI_VISIBILITY_VISIBLE。 | 
| NODE_CLIP  | 组件进行裁剪、遮罩处理属性，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：控制是否按照父容器边缘轮廓进行裁剪，0表示不裁切，1表示裁切。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：控制是否按照父容器边缘轮廓进行裁剪，0表示不裁切，1表示裁切。 | 
| NODE_CLIP_SHAPE  | 组件上指定形状的裁剪，支持属性设置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式,共有5种类型：<br/>1.rect类型：<br/>.value[0].i32：裁剪类型，参数类型[ArkUI_ClipType](#arkui_cliptype)，ARKUI_CLIP_TYPE_RECTANGLE；<br/>.value[1].f32：矩形宽度；<br/>.value[2].f32：矩形高度；<br/>.value[3].f32：矩形圆角宽度；<br/>.value[4].f32：矩形圆角高度；<br/>2.circle类型：<br/>.value[0].i32：裁剪类型，参数类型[ArkUI_ClipType](#arkui_cliptype)，ARKUI_CLIP_TYPE_CIRCLE；<br/>.value[1].f32：圆形宽度；<br/>.value[2].f32：圆形高度；<br/>3.ellipse类型：<br/>.value[0].i32：裁剪类型，参数类型[ArkUI_ClipType](#arkui_cliptype)，ARKUI_CLIP_TYPE_ELLIPSE；<br/>.value[1].f32：椭圆形宽度；<br/>.value[2].f32：椭圆形高度；<br/>4.path类型：<br/>.value[0].i32：裁剪类型，参数类型[ArkUI_ClipType](#arkui_cliptype)，ARKUI_CLIP_TYPE_PATH；<br/>.value[1].f32：路径宽度；<br/>.value[2].f32：路径高度；<br/>.string：路径绘制的命令字符串；<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式,共有5种类型：<br/>1.rect类型：<br/>.value[0].i32：裁剪类型，参数类型[ArkUI_ClipType](#arkui_cliptype)，ARKUI_CLIP_TYPE_RECTANGLE；<br/>.value[1].f32：矩形宽度；<br/>.value[2].f32：矩形高度；<br/>.value[3].f32：矩形圆角宽度；<br/>.value[4].f32：矩形圆角高度；<br/>2.circle类型：<br/>.value[0].i32：裁剪类型，参数类型[ArkUI_ClipType](#arkui_cliptype)，ARKUI_CLIP_TYPE_CIRCLE；<br/>.value[1].f32：圆形宽度；<br/>.value[2].f32：圆形高度；<br/>3.ellipse类型:：<br/>.value[0].i32：裁剪类型，参数类型[ArkUI_ClipType](#arkui_cliptype)，ARKUI_CLIP_TYPE_ELLIPSE；<br/>.value[1].f32：椭圆形宽度；<br/>.value[2].f32：椭圆形高度；<br/>4.path类型：<br/>.value[0].i32：裁剪类型，参数类型[ArkUI_ClipType](#arkui_cliptype)，ARKUI_CLIP_TYPE_PATH；<br/>.value[1].f32：路径宽度；<br/>.value[2].f32：路径高度；<br/>.string：路径绘制的命令字符串； | 
| NODE_TRANSFORM  | 矩阵变换功能，可对图形进行平移、旋转和缩放等，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.data[0...15].f32: 16个浮点数字。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.data[0...15].f32: 16个浮点数字。 | 
| NODE_HIT_TEST_BEHAVIOR  | 触摸测试类型，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：控制当前组件的触摸测试类型，参数类型[ArkUI_HitTestMode](#arkui_hittestmode)，默认值为ARKUI_HIT_TEST_MODE_DEFAULT。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：控制当前组件的触摸测试类型，参数类型**ArkKUI_HitTestMode**，默认值为ARKUI_HIT_TEST_MODE_DEFAULT。 | 
| NODE_POSITION  | 元素左上角相对于父容器左上角偏移位置，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32：x轴坐标。<br/>.value[1].f32: y轴坐标。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32：x轴坐标。<br/>.value[1].f32: y轴坐标。 | 
| NODE_SHADOW  | 阴影效果属性，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：设置当前组件阴影效果，参数类型[ArkUI_ShadowStyle](#arkui_shadowstyle)。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：设置当前组件阴影效果，参数类型[ArkUI_ShadowStyle](#arkui_shadowstyle)。 | 
| NODE_CUSTOM_SHADOW  | 自定义阴影效果，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0]?.f32：阴影模糊半径，单位为vp；<br/>.value[1]?.i32：是否开启智能取色，0代表不开启，1代表开启，默认不开启；<br/>.value[2]?.f32：阴影X轴偏移量，单位为vp；<br/>.value[3]?.f32：阴影Y轴偏移量，单位为vp；<br/>.value[4]?.i32：阴影类型[ArkUI_ShadowType](#arkui_shadowtype)，默认值为ARKUI_SHADOW_TYPE_COLOR；<br/>.value[5]?.u32：阴影颜色，0xargb格式，形如 0xFFFF0000 表示红色；<br/>.value[6]?.u32：阴影是否内部填充，，0表示不填充，1表示填充；<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32：阴影模糊半径，单位为vp；<br/>.value[1].i32：是否开启智能取色；<br/>.value[2].f32：阴影X轴偏移量，单位为vp；<br/>.value[3].f32：阴影Y轴偏移量，单位为vp；<br/>.value[4].i32：阴影类型[ArkUI_ShadowType](#arkui_shadowtype)，默认值为ARKUI_SHADOW_TYPE_COLOR；<br/>.value[5].u32：阴影颜色，0xargb格式，形如 0xFFFF0000 表示红色；<br/>.value[6].u32：阴影是否内部填充，，0表示不填充，1表示填充； | 
| NODE_BACKGROUND_IMAGE_SIZE  | 背景图片的宽高属性，支持属性设置，属性重置，属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32 表示图片的宽度值，取值范围[0,+∞)，单位为vp。<br/>.value[1].f32 表示图片的高度值，取值范围[0,+∞)，单位为vp。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32 表示图片的宽度值，单位为vp。<br/>.value[1].f32 表示图片的高度值，单位为vp。 | 
| NODE_BACKGROUND_IMAGE_SIZE_WITH_STYLE  | 背景图片的宽高样式属性，支持属性设置，属性重置，属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32 表示背景图片的宽高样式，取[ArkUI_ImageSize](#arkui_imagesize)枚举值。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32 表示背景图片的宽高样式，取[ArkUI_ImageSize](#arkui_imagesize)枚举值。 | 
| NODE_BACKGROUND_BLUR_STYLE  | 背景和内容之间的模糊属性，支持属性设置，属性重置，属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32 表示模糊类型，取[ArkUI_BlurStyle](#arkui_blurstyle)枚举值。<br/>.value[1]?.i32 表示深浅色模式，取[ArkUI_ColorMode](#arkui_colormode)枚举值。<br/>.value[2]?.i32 表示取色模式，取[ArkUI_AdaptiveColor](#arkui_adaptivecolor)枚举值。<br/>.value[3]?.f32 表示模糊效果程度，取[0.0,1.0]范围内的值。<br/>.value[4]?.f32 表示灰阶模糊起始边界。<br/>.value[5]?.f32 表示灰阶模糊终点边界。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32 表示模糊类型，取[ArkUI_BlurStyle](#arkui_blurstyle)枚举值。<br/>.value[1].i32 表示深浅色模式，取[ArkUI_ColorMode](#arkui_colormode)枚举值。<br/>.value[2].i32 表示取色模式，取[ArkUI_AdaptiveColor](#arkui_adaptivecolor)枚举值。<br/>.value[3].f32 表示模糊效果程度，取[0.0,1.0]范围内的值。<br/>.value[4].f32 表示灰阶模糊起始边界。<br/>.value[5].f32 表示灰阶模糊终点边界。 | 
| NODE_TRANSFORM_CENTER  | 图形变换和转场的中心点属性，支持属性设置，属性重置，属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0]?.f32 表示中心点X轴坐标值，单位为vp<br/>.value[1]?.f32 表示中心点Y轴坐标，单位为vp<br/>.value[2]?.f32 表示中心点Z轴坐标，单位为vp<br/>.value[3]?.f32 表示中心点X轴坐标的百分比位置，如0.2表示百分之20的位置，该属性覆盖value[0].f32，默认值:0.5f。<br/>.value[4]?.f32 表示中心点Y轴坐标的百分比位置，如0.2表示百分之20的位置，该属性覆盖value[1].f32，默认值:0.5f。<br/>.value[5]?.f32 表示中心点Z轴坐标的百分比位置，如0.2表示百分之20的位置，该属性覆盖value[2].f32，默认值:0.0f。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32 表示中心点X轴坐标，单位为vp<br/>.value[1].f32 表示中心点Y轴坐标，单位为vp<br/>.value[2].f32 表示中心点Z轴坐标，单位为vp<br/>注：如果设置坐标百分比位置，属性获取方法返回计算后的vp为单位的值。 | 
| NODE_OPACITY_TRANSITION  | 转场时的透明度效果属性，支持属性设置，属性重置，属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32 表示起终点的透明度值<br/>.value[1].i32 表示动画时长，单位ms<br/>.value[2].i32 表示动画曲线类型，取[ArkUI_AnimationCurve](#arkui_animationcurve)枚举值<br/>.value[3]?.i32 表示动画延迟时长，单位ms<br/>.value[4]?.i32 表示动画播放次数<br/>.value[5]?.i32 表示动画播放模式，取[ArkUI_AnimationPlayMode](#arkui_animationplaymode)枚举值<br/>.value[6]?.f32 表示动画播放速度<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32 表示起终点的透明度值<br/>.value[1].i32 表示动画时长，单位ms<br/>.value[2].i32 表示动画曲线类型，取[ArkUI_AnimationCurve](#arkui_animationcurve)枚举值<br/>.value[3].i32 表示动画延迟时长，单位ms<br/>.value[4].i32 表示动画播放次数<br/>.value[5].i32 表示动画播放模式，取[ArkUI_AnimationPlayMode](#arkui_animationplaymode)枚举值<br/>.value[6].f32 表示动画播放速度 | 
| NODE_ROTATE_TRANSITION  | 转场时的旋转效果属性，支持属性设置，属性重置，属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32 表示横向旋转分量。<br/>.value[1].f32 表示纵向的旋转分量。<br/>.value[2].f32 表示竖向的旋转分量。<br/>.value[3].f32 表示角度。<br/>.value[4].f32 表示视距，默认值：0.0f。<br/>.value[5].i32 表示动画时长，单位ms。<br/>.value[6].i32 表示动画曲线类型，取[ArkUI_AnimationCurve](#arkui_animationcurve)枚举值。<br/>.value[7]?.i32 表示动画延迟时长，单位ms。<br/>.value[8]?.i32 表示动画播放次数。<br/>.value[9]?.i32 表示动画播放模式，取[ArkUI_AnimationPlayMode](#arkui_animationplaymode)枚举值。<br/>.value[10]?.f32 表示动画播放速度。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32 表示横向旋转分量。<br/>.value[1].f32 表示纵向的旋转分量。<br/>.value[2].f32 表示竖向的旋转分量。<br/>.value[3].f32 表示角度。<br/>.value[4].f32 表示视距。<br/>.value[5].i32 表示动画时长，单位ms。<br/>.value[6].i32 表示动画曲线类型，取[ArkUI_AnimationCurve](#arkui_animationcurve)枚举值。<br/>.value[7].i32 表示动画延迟时长，单位ms。<br/>.value[8].i32 表示动画播放次数。<br/>.value[9].i32 表示动画播放模式，取[ArkUI_AnimationPlayMode](#arkui_animationplaymode)枚举值。<br/>.value[10].f32 表示动画播放速度。 | 
| NODE_SCALE_TRANSITION  | 转场时的缩放效果属性，支持属性设置，属性重置，属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32 横向放大倍数。<br/>.value[1].f32 纵向放大倍数。<br/>.value[2].f32 竖向放大倍数。<br/>.value[3].i32 表示动画时长，单位ms。<br/>.value[4].i32 表示动画曲线类型，取[ArkUI_AnimationCurve](#arkui_animationcurve)枚举值。<br/>.value[5]?.i32 表示动画延迟时长，单位ms。<br/>.value[6]?.i32 表示动画播放次数。<br/>.value[7]?.i32 表示动画播放模式，取[ArkUI_AnimationPlayMode](#arkui_animationplaymode)枚举值。<br/>.value[8]?.f32 表示动画播放速度。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32 横向放大倍数。<br/>.value[1].f32 纵向放大倍数。<br/>.value[2].f32 竖向放大倍数。<br/>.value[3].i32 表示动画时长，单位ms。<br/>.value[4].i32 表示动画曲线类型，取[ArkUI_AnimationCurve](#arkui_animationcurve)枚举值。<br/>.value[5].i32 表示动画延迟时长，单位ms。<br/>.value[6].i32 表示动画播放次数。<br/>.value[7].i32 表示动画播放模式，取[ArkUI_AnimationPlayMode](#arkui_animationplaymode)枚举值。<br/>.value[8].f32 表示动画播放速度。 | 
| NODE_TRANSLATE_TRANSITION  | 转场时的平移效果属性，支持属性设置，属性重置，属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>value[0].f32 表示横向平移距离值，单位为vp<br/>value[1].f32 表示纵向平移距离值，单位为vp<br/>value[2].f32 表示竖向平移距离值，单位为vp<br/>value[3].i32 表示动画时长，单位ms。<br/>value[4].i32 表示动画曲线类型，取[ArkUI_AnimationCurve](#arkui_animationcurve)枚举值。<br/>value[5]?.i32 表示动画延迟时长，单位ms。<br/>value[6]?.i32 表示动画播放次数。<br/>value[7]?.i32 表示动画播放模式，取[ArkUI_AnimationPlayMode](#arkui_animationplaymode)枚举值。<br/>value[8]?.f32 表示动画播放速度。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>value[0].f32 表示横向平移距离值，单位为vp<br/>value[1].f32 表示纵向平移距离值，单位为vp<br/>value[2].f32 表示竖向平移距离值，单位为vp<br/>value[3].i32 表示动画时长，单位ms。<br/>value[4].i32 表示动画曲线类型，取[ArkUI_AnimationCurve](#arkui_animationcurve)枚举值。<br/>value[5].i32 表示动画延迟时长，单位ms。<br/>value[6].i32 表示动画播放次数。<br/>value[7].i32 表示动画播放模式，取[ArkUI_AnimationPlayMode](#arkui_animationplaymode)枚举值。<br/>value[8].f32 表示动画播放速度。 | 
| NODE_MOVE_TRANSITION  | 转场时从屏幕边缘滑入和滑出的效果属性，支持属性设置，属性重置，属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>value[0].i32 参数类型[ArkUI_TransitionEdge](#arkui_transitionedge)<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>value[0].i32 参数类型[ArkUI_TransitionEdge](#arkui_transitionedge) | 
| NODE_FOCUSABLE  | 获焦属性，支持属性设置，属性重置和属性获取。<br/>属性设置方法[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)参数格式：<br/>.value[0].i32：参数类型为1或者0。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：参数类型为1或者0。 | 
| NODE_DEFAULT_FOCUS  | 默认焦点属性，支持属性设置，属性重置和属性获取。<br/>属性设置方法[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)参数格式：<br/>value[0].i32：参数类型为1或者0。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>value[0].i32：参数类型为1或者0。 | 
| NODE_RESPONSE_REGION  | 触摸热区属性，支持属性设置，属性重置和属性获取。<br/>属性设置方法[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)参数格式：<br/>.data[0].f32：触摸点相对于组件左上角的x轴坐标,单位为vp。<br/>.data[1].f32：触摸点相对于组件左上角的y轴坐标,单位为vp。<br/>.data[2].f32：触摸热区的宽度 ，单位为。<br/>.data[3].f32：触摸热区的高度，单位为。<br/>.data[4...].f32:可以设置多个手势响应区域，顺序和上述一致。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.data[0].f32：触摸点相对于组件左上角的x轴坐标,单位为vp。<br/>.data[1].f32：触摸点相对于组件左上角的y轴坐标,单位为vp。<br/>.data[2].f32：触摸热区的宽度 ，单位为。<br/>.data[3].f32：触摸热区的高度，单位为。<br/>.data[4...].f32:可以设置多个手势响应区域，顺序和上述一致。 | 
| NODE_OVERLAY  | 遮罩文本属性，支持属性设置，属性重置和属性获取。<br/>属性设置方法[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)参数格式：<br/>.string 遮罩文本；<br/>.value[0]?.i32：可选值，浮层相对于组件的位置，参数类型[ArkUI_Alignment](#arkui_alignment)， 默认值为ARKUI_ALIGNMENT_TOP_START。<br/>.value[1]?.f32：可选值，浮层基于自身左上角的偏移量X，单位为vp。<br/>.value[2]?.f32：可选值，浮层基于自身左上角的偏移量Y，单位为vp。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.string 遮罩文本；<br/>.value[0].i32：浮层相对于组件的位置，参数类型[ArkUI_Alignment](#arkui_alignment)， 默认值为ARKUI_ALIGNMENT_TOP_START。<br/>.value[1].f32：浮层基于自身左上角的偏移量X，单位为vp。<br/>.value[2].f32：浮层基于自身左上角的偏移量Y，单位为vp。 | 
| NODE_SWEEP_GRADIENT  | 角度渐变效果，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0]?.f32:为角度渐变的中心点，即相对于当前组件左上角的坐标,X轴坐标<br/>.value[1]?.f32:为角度渐变的中心点，即相对于当前组件左上角的坐标,Y轴坐标<br/>.value[2]?.f32:角度渐变的起点，默认值0。<br/>.value[3]?.f32:角度渐变的终点，默认值0。<br/>.value[4]?.f32:角度渐变的旋转角度，默认值0。<br/>.value[5]?.i32:为渐变的颜色重复着色，0表示不重复着色，1表示重复着色<br/>.object: 指定某百分比位置处的渐变色颜色，设置非法颜色直接跳过：<br/>colors：渐变色颜色颜色。<br/>stops：渐变位置。<br/>size：颜色个数。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32:为角度渐变的中心点，即相对于当前组件左上角的坐标,X轴坐标<br/>.value[1].f32:为角度渐变的中心点，即相对于当前组件左上角的坐标,Y轴坐标<br/>.value[2].f32:角度渐变的起点，默认值0。<br/>.value[3].f32:角度渐变的终点，默认值0。<br/>.value[4].f32:角度渐变的旋转角度，默认值0。<br/>.value[5].i32:为渐变的颜色重复着色，0表示不重复着色，1表示重复着色<br/>.object: 指定某百分比位置处的渐变色颜色，设置非法颜色直接跳过：<br/>colors：渐变色颜色颜色。<br/>stops：渐变位置。<br/>size：颜色个数。 | 
| NODE_RADIAL_GRADIENT  | 径向渐变渐变效果，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0]?.f32:为径向渐变的中心点，即相对于当前组件左上角的坐标,X轴坐标<br/>.value[1]?.f32:为径向渐变的中心点，即相对于当前组件左上角的坐标,Y轴坐标<br/>.value[2]?.f32:径向渐变的半径，默认值0。<br/>.value[3]?.i32:为渐变的颜色重复着色，0表示不重复着色，1表示重复着色<br/>.object: 指定某百分比位置处的渐变色颜色，设置非法颜色直接跳过：<br/>colors：渐变色颜色颜色。<br/>stops：渐变位置。<br/>size：颜色个数。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32:为径向渐变的中心点，即相对于当前组件左上角的坐标,X轴坐标<br/>.value[1].f32:为径向渐变的中心点，即相对于当前组件左上角的坐标,Y轴坐标<br/>.value[2].f32:径向渐变的半径，默认值0。<br/>.value[3].i32:为渐变的颜色重复着色，0表示不重复着色，1表示重复着色<br/>.object: 指定某百分比位置处的渐变色颜色，设置非法颜色直接跳过：<br/>colors：渐变色颜色颜色。<br/>stops：渐变位置。<br/>size：颜色个数。 | 
| NODE_MASK  | 组件上加上指定形状的遮罩，支持属性设置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式,共有5种类型：<br/>1.rect类型：<br/>.value[0].u32：填充颜色，0xargb类型；<br/>.value[1].u32：描边颜色，0xargb类型；<br/>.value[2].f32：描边宽度，单位为vp；<br/>.value[3].i32：遮罩类型，参数类型[ArkUI_MaskType](#arkui_masktype)，ARKUI_MASK_TYPE_RECTANGLE；<br/>.value[4].f32：矩形宽度；<br/>.value[5].f32：矩形高度；<br/>.value[6].f32：矩形圆角宽度；<br/>.value[7].f32：矩形圆角高度；<br/>2.circle类型：<br/>.value[0].u32：填充颜色，0xargb类型；<br/>.value[1].u32：描边颜色，0xargb类型；<br/>.value[2].f32：描边宽度，单位为vp；<br/>.value[3].i32：遮罩类型，参数类型[ArkUI_MaskType](#arkui_masktype)，ARKUI_MASK_TYPE_CIRCLE；<br/>.value[4].f32：圆形宽度；<br/>.value[5].f32：圆形高度；<br/>3.ellipse类型：<br/>.value[0].u32：填充颜色，0xargb类型；<br/>.value[1].u32：描边颜色，0xargb类型；<br/>.value[2].f32：描边宽度，单位为vp；<br/>.value[3].i32：遮罩类型，参数类型[ArkUI_MaskType](#arkui_masktype)，ARKUI_MASK_TYPE_ELLIPSE；<br/>.value[4].f32：椭圆形宽度；<br/>.value[5].f32：椭圆形高度；<br/>4.path类型：<br/>.value[0].u32：填充颜色，0xargb类型；<br/>.value[1].u32：描边颜色，0xargb类型；<br/>.value[2].f32：描边宽度，单位为vp；<br/>.value[3].i32：遮罩类型，参数类型[ArkUI_MaskType](#arkui_masktype)，ARKUI_MASK_TYPE_PATH；<br/>.value[4].f32：路径宽度；<br/>.value[5].f32：路径高度；<br/>.string：路径绘制的命令字符串；<br/>4.progress类型：<br/>.value[0].u32：填充颜色，0xargb类型；<br/>.value[1].u32：描边颜色，0xargb类型；<br/>.value[2].f32：描边宽度，单位为vp；<br/>.value[3].i32：遮罩类型，参数类型[ArkUI_MaskType](#arkui_masktype)，ARKUI_MASK_TYPE_PROSGRESS；<br/>.value[4].f32：进度遮罩的当前值；<br/>.value[5].f32：进度遮罩的最大值；<br/>.value[6].u32：进度遮罩的颜色；<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式,共有5种类型：<br/>1.rect类型：<br/>.value[0].u32：填充颜色，0xargb类型；<br/>.value[1].u32：描边颜色，0xargb类型；<br/>.value[2].f32：描边宽度，单位为vp；<br/>.value[3].i32：遮罩类型；<br/>.value[4].f32：矩形宽度；<br/>.value[5].f32：矩形高度；<br/>.value[6].f32：矩形圆角宽度；<br/>.value[7].f32：矩形圆角高度；<br/>2.circle类型：<br/>.value[0].u32：填充颜色，0xargb类型；<br/>.value[1].u32：描边颜色，0xargb类型；<br/>.value[2].f32：描边宽度，单位为vp；<br/>.value[3].i32：遮罩类型；<br/>.value[4].f32：圆形宽度；<br/>.value[5].f32：圆形高度；<br/>3.ellipse类型：<br/>.value[0].u32：填充颜色，0xargb类型；<br/>.value[1].u32：描边颜色，0xargb类型；<br/>.value[2].f32：描边宽度，单位为vp；<br/>.value[3].i32：遮罩类型；<br/>.value[4].f32：椭圆形宽度；<br/>.value[5].f32：椭圆形高度；<br/>4.path类型：<br/>.value[0].u32：填充颜色，0xargb类型；<br/>.value[1].u32：描边颜色，0xargb类型；<br/>.value[2].f32：描边宽度，单位为vp；<br/>.value[3].i32：遮罩类型；<br/>.value[4].f32：路径宽度；<br/>.value[5].f32：路径高度；<br/>.string：路径绘制的命令字符串；<br/>4.progress类型：<br/>.value[0].i32：遮罩类型；<br/>.value[1].f32：进度遮罩的当前值；<br/>.value[2].f32：进度遮罩的最大值；<br/>.value[3].u32：进度遮罩的颜色； | 
| NODE_BLEND_MODE  | 当前控件背景与子节点内容进行混合，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：控制当前组件的混合模式类型，参数类型[ArkUI_BlendMode](#arkui_blendmode)，默认值为ARKUI_BLEND_MODE_NONE。<br/>.value[1].?i32：blendMode实现方式是否离屏，参数类型[ArkUI_BlendApplyType](#arkui_blendapplytype)，默认值为ARKUI_BLEND_APPLY_TYPE_FAST。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：控制当前组件的混合模式类型，参数类型[ArkUI_BlendMode](#arkui_blendmode)，默认值为ARKUI_BLEND_MODE_NONE。<br/>.value[1].i32：blendMode实现方式是否离屏，参数类型[ArkUI_BlendApplyType](#arkui_blendapplytype)，默认值为ARKUI_BLEND_APPLY_TYPE_FAST。 | 
| NODE_DIRECTION  | 设置容器元素内主轴方向上的布局，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：设置容器元素内主轴方向上的布局类型，<br/>参数类型[ArkUI_Direction](#arkui_direction)，默认值为ARKUI_DIRECTION_AUTO。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：设置容器元素内主轴方向上的布局类型，<br/>参数类型[ArkUI_Direction](#arkui_direction)，默认值为ARKUI_DIRECTION_AUTO。 | 
| NODE_CONSTRAINT_SIZE  | 约束尺寸属性，组件布局时，进行尺寸范围限制，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32：最小宽度，单位vp；<br/>.value[1].f32：最大宽度，单位vp；<br/>.value[2].f32：最小高度，单位vp；<br/>.value[3].f32：最大高度，单位vp；<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32：最小宽度，单位vp；<br/>.value[1].f32：最大宽度，单位vp；<br/>.value[2].f32：最小高度，单位vp；<br/>.value[3].f32：最大高度，单位vp； | 
| NODE_GRAY_SCALE  | 灰度效果属性，支持属性设置，属性重置和属性获取接口.<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32：灰度转换比例，范围0-1之间，比如0.5指按照50进行灰度处理；<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32：灰度转换比例，范围0-1之间； | 
| NODE_INVERT  | 反转输入的图像比例属性，支持属性设置，属性重置和属性获取接口.<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32：图像反转比例，范围0-1之间，比如0.5指按照50进行反转处理；<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32：图像反转比例，范围0-1之间； | 
| NODE_SEPIA  | 图像转换为深褐色比例属性，支持属性设置，属性重置和属性获取接口.<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32：图像转换为深褐色比例，范围0-1之间，比如0.5指按照50进行深褐色处理；<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32：图像转换为深褐色比例，范围0-1之间； | 
| NODE_CONTRAST  | 对比度属性，支持属性设置，属性重置和属性获取接口.<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32：对比度，等于1时为原图，越大则对比度越高，取值范围：[0, 10)；<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32：对比度，取值范围：[0, 10)； | 
| NODE_FOREGROUND_COLOR  | 前景颜色属性，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式，支持两种入参格式：<br/>1：.value[0].u32：颜色数值，0xargb类型，如0xFFFF0000表示红色；<br/>2：.value[0].i32：颜色数值枚举**ArkUI_ColoringStrategy**；<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].u32：颜色数值，0xargb类型； | 
| NODE_OFFSET  | 组件子元素相对组件自身的额外偏移属性，支持属性设置，属性重置，属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32 表示x轴方向的偏移值, 单位为vp。<br/>.value[1].f32 表示y轴方向的偏移值, 单位为vp。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32 表示x轴方向的偏移值, 单位为vp。<br/>.value[1].f32 表示y轴方向的偏移值, 单位为vp。 | 
| NODE_MARK_ANCHOR  | 组件子元素在位置定位时的锚点属性，支持属性设置，属性重置，属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32 表示锚点x坐标值, 单位为vp<br/>.value[1].f32 表示锚点y坐标值, 单位为vp<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32 表示锚点x坐标值, 单位为vp<br/>.value[1].f32 表示锚点y坐标值, 单位为vp | 
| NODE_BACKGROUND_IMAGE_POSITION  | 背景图在组件中显示位置，即相对于组件左上角的坐标，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32 表示x轴方向的位置, 单位为vp。<br/>.value[1].f32 表示y轴方向的位置, 单位为vp。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32 表示x轴方向的位置, 单位为vp。<br/>.value[1].f32 表示y轴方向的位置, 单位为vp。 | 
| NODE_ALIGN_RULES  | 相对容器中子组件的对齐规则属性，支持属性设置，属性重置，获取属性接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0]?.i32 左对齐规则锚点组件id。<br/>.value[1]?.i32 左对齐规则相对锚点组件的对齐方式，取[ArkUI_HorizontalAlignment](#arkui_horizontalalignment)枚举值。<br/>.value[2]?.i32 横向居中规则锚点组件id。<br/>.value[3]?.i32 横向居中规则相对锚点组件的对齐方式，取[ArkUI_HorizontalAlignment](#arkui_horizontalalignment)枚举值。<br/>.value[4]?.i32 右对齐规则锚点组件id。<br/>.value[5]?.i32 右对齐规则相对锚点组件的对齐方式，取[ArkUI_HorizontalAlignment](#arkui_horizontalalignment)枚举值。<br/>.value[6]?.i32 顶部对齐规则锚点组件id。<br/>.value[7]?.i32 顶部对齐规则相对锚点组件的对齐方式，取[ArkUI_VerticalAlignment](#arkui_verticalalignment)枚举值。<br/>.value[8]?.i32 纵向居中规则锚点组件id。<br/>.value[9]?.i32 纵向居中规则相对锚点组件的对齐方式，取[ArkUI_VerticalAlignment](#arkui_verticalalignment)枚举值。<br/>.value[10]?.i32 底部对齐规则锚点组件id。<br/>.value[11]?.i32 底部对齐规则相对锚点组件的对齐方式，取[ArkUI_VerticalAlignment](#arkui_verticalalignment)枚举值。<br/>.value[12]?.f32 水平方向的bias值。<br/>.value[13]?.f32 垂直方向的bias值。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32 左对齐规则锚点组件id。<br/>.value[1].i32 左对齐规则相对锚点组件的对齐方式，取[ArkUI_HorizontalAlignment](#arkui_horizontalalignment)枚举值。<br/>.value[2].i32 横向居中规则锚点组件id。<br/>.value[3].i32 横向居中规则相对锚点组件的对齐方式，取[ArkUI_HorizontalAlignment](#arkui_horizontalalignment)枚举值。<br/>.value[4].i32 右对齐规则锚点组件id。<br/>.value[5].i32 右对齐规则相对锚点组件的对齐方式，取[ArkUI_HorizontalAlignment](#arkui_horizontalalignment)枚举值。<br/>.value[6].i32 顶部对齐规则锚点组件id。<br/>.value[7].i32 顶部对齐规则相对锚点组件的对齐方式，取[ArkUI_VerticalAlignment](#arkui_verticalalignment)枚举值。<br/>.value[8].i32 纵向居中规则锚点组件id。<br/>.value[9].i32 纵向居中规则相对锚点组件的对齐方式，取[ArkUI_VerticalAlignment](#arkui_verticalalignment)枚举值。<br/>.value[10].i32 底部对齐规则锚点组件id。<br/>.value[11].i32 底部对齐规则相对锚点组件的对齐方式，取[ArkUI_VerticalAlignment](#arkui_verticalalignment)枚举值。<br/>.value[12].f32 水平方向的bias值。<br/>.value[13].f32 垂直方向的bias值。 | 
| NODE_ALIGN_SELF  | 设置子组件在父容器交叉轴的对齐格式，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32：设置子组件在父容器交叉轴的对齐格式类型，<br/>参数类型**ArkUI_ItemAlign**，默认值为ARKUI_ITEM_ALIGN_AUTO。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32：设置子组件在父容器交叉轴的对齐格式类型，<br/>参数类型**ArkUI_ItemAlign**，默认值为ARKUI_ITEM_ALIGN_AUTO。 | 
| NODE_FLEX_GROW  | 组件的基准尺寸，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32：组件的基准尺寸数值。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32：组件的基准尺寸数值。 | 
| NODE_FLEX_SHRINK  | 父容器压缩尺寸分配给此属性所在组件的比例，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32：父容器压缩尺寸分配给此属性所在组件的比例数值。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32：父容器压缩尺寸分配给此属性所在组件的比例数值。 | 
| NODE_FLEX_BASIS  | 设置组件的基准尺寸，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32：组件的基准尺寸数值。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32：组件的基准尺寸数值。 | 
| NODE_ACCESSIBILITY_GROUP  | 无障碍组属性, 支持属性设置，属性重置和属性获取。<br/>属性设置方法[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)参数格式：<br/>.value[0].i32：为1时表示该组件及其所有子组件为一整个可以选中的组件 无障碍服务将不再关注其子组件内容。参数类型为1或者0。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：为1时表示该组件及其所有子组件为一整个可以选中的组件 无障碍服务将不再关注其子组件内容。参数类型为1或者0。 | 
| NODE_ACCESSIBILITY_TEXT  | 无障碍文本属性，支持属性设置，属性重置和属性获取。<br/>属性设置方法[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)参数格式：<br/>.string：无障碍文本。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.string：无障碍文本。 | 
| NODE_ACCESSIBILITY_MODE  | 无障碍辅助服务模式，支持属性设置，属性重置和属性获取。<br/>属性设置方法[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)参数格式：<br/>.value[0].i32：辅助服务模式，参数类型[ArkUI_AccessibilityMode](#arkui_accessibilitymode)。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：辅助服务模式，参数类型[ArkUI_AccessibilityMode](#arkui_accessibilitymode)。 | 
| NODE_ACCESSIBILITY_DESCRIPTION  | 无障碍说明属性，支持属性设置，属性重置和属性获取。<br/>属性设置方法[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)参数格式：<br/>.string：无障碍说明。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.string：无障碍说明。 | 
| NODE_FOCUS_STATUS  | 组件获取焦点属性，支持属性设置，属性获取。<br/>属性设置方法[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)参数格式：<br/>.value[0].i32：参数类型为1或者0。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：参数类型为1或者0。 | 
| NODE_ASPECT_RATIO  | 设置组件的宽高比，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32：组件的宽高比，输入值为 width/height。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32：组件的宽高比，width/height的比值。 | 
| NODE_TEXT_CONTENT  | text组件设置文本内容属性，支持属性设置，属性重置，属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.string 表示文本内容<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.string 表示文本内容 | 
| NODE_FONT_COLOR  | 组件字体颜色属性，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].u32：字体颜色数值，0xargb格式，形如 0xFFFF0000 表示红色；<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].u32：字体颜色数值，0xargb格式； | 
| NODE_FONT_SIZE  | 组件字体大小属性，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32：字体大小数值，单位为fp；<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32：字体大小数值，单位为fp； | 
| NODE_FONT_STYLE  | 组件字体样式属性，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：字体样式[ArkUI_FontStyle](#arkui_fontstyle)，默认值为ARKUI_FONT_STYLE_NORMAL；<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：字体样式[ArkUI_FontStyle](#arkui_fontstyle)； | 
| NODE_FONT_WEIGHT  | 组件字体粗细属性，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：字体粗细样式[ArkUI_FontWeight](#arkui_fontweight)，默认值为ARKUI_FONT_WEIGHT_NORMAL；<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：字体粗细样式[ArkUI_FontWeight](#arkui_fontweight)； | 
| NODE_TEXT_LINE_HEIGHT  | 文本行高属性，支持属性设置，属性重置，属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32 表示lineHeight值，单位为fp<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32 表示lineHeight值，单位为fp | 
| NODE_TEXT_DECORATION  | 置文本装饰线样式及其颜色属性，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：文本装饰线样式[ArkUI_TextDecorationType](#arkui_textdecorationtype)，默认值为ARKUI_TEXT_DECORATION_TYPE_NONE；<br/>.value[1]?.u32：可选值，装饰线颜色，0xargb格式，形如 0xFFFF0000 表示红色；<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：文本装饰线样式[ArkUI_TextDecorationType](#arkui_textdecorationtype)；<br/>.value[1].u32：装饰线颜色，0xargb格式。 | 
| NODE_TEXT_CASE  | 文本大小写属性，支持属性设置，属性重置，属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32 表示文本大小写类型<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32 表示文本大小写类型 | 
| NODE_TEXT_LETTER_SPACING  | 文本字符间距属性，支持属性设置，属性重置，属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32 表示字符间距值，单位为fp<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32 表示字符间距值，单位为fp | 
| NODE_TEXT_MAX_LINES  | 文本最大行数属性，支持属性设置，属性重置，属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32 表示最大行数<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32 表示最大行数 | 
| NODE_TEXT_ALIGN  | 文本水平对齐方式, 支持属性设置，属性重置，属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：表示文本水平对齐方式，取[ArkUI_TextAlignment](#arkui_textalignment)枚举值。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：表示文本水平对齐方式，取[ArkUI_TextAlignment](#arkui_textalignment)枚举值。 | 
| NODE_TEXT_OVERFLOW  | 文本超长时的显示方式属性，支持属性设置，属性重置，属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：表示文本超长时的显示方式。{\@ArkUI_TextOverflow}<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：表示文本超长时的显示方式。{\@ArkUI_TextOverflow} | 
| NODE_FONT_FAMILY  | Text字体列表属性，支持属性设置，属性重置和属性获取。<br/>属性设置方法[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)参数格式：<br/>.string：字体字符串，多个用,分隔。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.string：字体字符串，多个用,分隔。 | 
| NODE_TEXT_COPY_OPTION  | 文本复制粘贴属性，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：复制粘贴方式[ArkUI_CopyOptions](#arkui_copyoptions)，默认值为ARKUI_COPY_OPTIONS_NONE；<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：复制粘贴方式[ArkUI_CopyOptions](#arkui_copyoptions)。 | 
| NODE_TEXT_BASELINE_OFFSET  | 文本基线的偏移量属性，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32：偏移量数值，单位为fp；<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32：偏移量数值，单位为fp。 | 
| NODE_TEXT_TEXT_SHADOW  | 文字阴影效果属性，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32：阴影模糊半径，单位为vp；<br/>.value[1].i32：阴影类型[ArkUI_ShadowType](#arkui_shadowtype)，默认值为ARKUI_SHADOW_TYPE_COLOR；<br/>.value[2].u32：阴影颜色，0xargb格式，形如 0xFFFF0000 表示红色；<br/>.value[3].f32：阴影X轴偏移量，单位为vp；<br/>.value[4].f32：阴影Y轴偏移量，单位为vp；<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32：阴影模糊半径，单位为vp；<br/>.value[1].i32：阴影类型[ArkUI_ShadowType](#arkui_shadowtype)；<br/>.value[2].u32：阴影颜色，0xargb格式；<br/>.value[3].f32：阴影X轴偏移量，单位为vp；<br/>.value[4].f32：阴影Y轴偏移量，单位为vp； | 
| NODE_TEXT_MIN_FONT_SIZE  | Text最小显示字号，支持属性设置，属性重置和属性获取。<br/>属性设置方法[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)参数格式：<br/>.value[0].f32：文本最小显示字号，单位FP。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32：文本最小显示字号，单位FP。 | 
| NODE_TEXT_MAX_FONT_SIZE  | Text最大显示字号，支持属性设置，属性重置和属性获取。<br/>属性设置方法[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)参数格式：<br/>.value[0].f32：文本最大显示字号 单位FP。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32：文本最大显示字号 单位FP。 | 
| NODE_TEXT_FONT  | Text样式，支持属性设置，属性重置和属性获取。<br/>属性设置方法[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)参数格式：<br/>.string?：可选值 字体列表，使用多个字体，使用','进行分割。<br/>.value[0].f32：文本尺寸 单位FP。<br/>.value[1]?.i32：可选值，文本的字体粗细，参数类型[ArkUI_FontWeight](#arkui_fontweight)。 默认值为ARKUI_FONT_WEIGHT_NORMAL。<br/>.value[2]?.i32：可选值，字体样式，参数类型[ArkUI_FontStyle](#arkui_fontstyle)。 默认值为ARKUI_FONT_STYLE_NORMAL。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.string：字体列表，使用多个字体，使用','进行分割。<br/>.value[0].f32：文本尺寸 单位FP。<br/>.value[1].i32：文本的字体粗细，参数类型[ArkUI_FontWeight](#arkui_fontweight)。 默认值为ARKUI_FONT_WEIGHT_NORMAL。<br/>.value[2].i32：字体样式，参数类型[ArkUI_FontStyle](#arkui_fontstyle)。 默认值为ARKUI_FONT_STYLE_NORMAL。 | 
| NODE_TEXT_HEIGHT_ADAPTIVE_POLICY  | Text自适应高度的方式，支持属性设置，属性重置和属性获取。<br/>属性设置方法[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)参数格式：<br/>.value[0].i32：参数类型[ArkUI_TextHeightAdaptivePolicy](#arkui_textheightadaptivepolicy)。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：参数类型[ArkUI_TextHeightAdaptivePolicy](#arkui_textheightadaptivepolicy)。 | 
| NODE_TEXT_INDENT  | 文本首行缩进属性，支持属性设置，属性重置，属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32: 表示首行缩进值。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32: 表示首行缩进值。 | 
| NODE_TEXT_WORD_BREAK  | 文本断行规则属性，支持属性设置，属性重置，属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32: 参数类型[ArkUI_WordBreak](#arkui_wordbreak)。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32: 参数类型[ArkUI_WordBreak](#arkui_wordbreak)。 | 
| NODE_TEXT_ELLIPSIS_MODE  | 设置文本省略位置，支持属性设置，属性重置，属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32: 参数类型[ArkUI_EllipsisMode](#arkui_ellipsismode)。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32: 参数类型[ArkUI_EllipsisMode](#arkui_ellipsismode)。 | 
| NODE_TEXT_LINE_SPACING  | 文本行间距属性，支持属性设置，属性重置，属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32 表示lineSpacing值，单位为fp<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32 表示lineSpacing值，单位为fp。 | 
| NODE_SPAN_CONTENT  | 文本内容属性，支持属性设置，属性重置，属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.string 表示span的文本内容。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.string 表示span的文本内容。 | 
| NODE_SPAN_TEXT_BACKGROUND_STYLE  | 文本背景色属性，支持属性设置，属性重置，属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].u32 表示文本背景颜色，0xargb格式，形如0xFFFF0000 表示红色。<br/>第二个参数为文本背景圆角设置，支持如下两种设置方式：<br/>1：.value[1].f32：四个方向的圆角半径统一设置，单位为vp。<br/>2: .value[1].f32：设置左上角圆角半径，单位为vp。<br/>.value[2].f32：设置右上角圆角半径，单位为vp。<br/>.value[3].f32：设置左下角圆角半径，单位为vp。<br/>.value[4].f32：设置右下角圆角半径，单位为vp。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].u32：文本背景颜色，0xargb格式。<br/>.value[1].f32：左上角圆角半径，单位为vp。<br/>.value[2].f32：右上角圆角半径，单位为vp。<br/>.value[3].f32：左下角圆角半径，单位为vp。<br/>.value[4].f32：右下角圆角半径，单位为vp。 | 
| NODE_IMAGE_SPAN_SRC  | imageSpan组件图片地址属性，支持属性设置，属性重置，属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.string 表示imageSpan的图片地址<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.string 表示imageSpan的图片地址 | 
| NODE_IMAGE_SPAN_VERTICAL_ALIGNMENT  | 图片基于文本的对齐方式属性，支持属性设置，属性重置，属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32 表示图片基于文本的对齐方式，取[ArkUI_ImageSpanAlignment](#arkui_imagespanalignment)枚举值。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32 表示图片基于文本的对齐方式，取[ArkUI_ImageSpanAlignment](#arkui_imagespanalignment)枚举值。 | 
| NODE_IMAGE_SRC  | image组件设置图片地址属性，支持属性设置，属性重置，属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.string 表示image组件地址<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.string 表示image组件地址 | 
| NODE_IMAGE_OBJECT_FIT  | 图片填充效果属性，支持属性设置，属性重置，属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32 表示图片填充效果，取[ArkUI_ObjectFit](#arkui_objectfit)枚举值。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32 表示图片填充效果，取[ArkUI_ObjectFit](#arkui_objectfit)枚举值。 | 
| NODE_IMAGE_INTERPOLATION  | 图片插值效果效果属性，支持属性设置，属性重置，属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32 表示插值效果效果，取[ArkUI_ImageInterpolation](#arkui_imageinterpolation)枚举值。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32 表示插值效果效果，取[ArkUI_ImageInterpolation](#arkui_imageinterpolation)枚举值。 | 
| NODE_IMAGE_OBJECT_REPEAT  | 图片重复样式属性，支持属性设置，属性重置，属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32 表示图片重复样式，取[ArkUI_ImageRepeat](#arkui_imagerepeat)枚举值。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32 表示图片重复样式，取[ArkUI_ImageRepeat](#arkui_imagerepeat)枚举值。 | 
| NODE_IMAGE_COLOR_FILTER  | 图片滤镜效果属性，支持属性设置，属性重置，属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32 ~ .value[19].f32 表示滤镜矩阵数组。<br/>.size 表示滤镜数组大小 5\*4。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32 ~ .value[19].f32 表示滤镜矩阵数组。<br/>.size 表示滤镜数组大小 5\*4。 | 
| NODE_IMAGE_AUTO_RESIZE  | 图源自动缩放属性，支持属性设置，属性重置，属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32 表示是否缩放布尔值。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32 表示是否缩放布尔值。 | 
| NODE_IMAGE_ALT  | 占位图地址属性，支持属性设置，属性重置，属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.string 表示image组件占位图地址。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.string 表示image组件占位图地址。 | 
| NODE_IMAGE_DRAGGABLE  | 图片拖拽效果属性，支持属性设置，属性重置，属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32 表示是否支持拖拽，设置为true表示支持。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32 表示是否支持拖拽。 | 
| NODE_IMAGE_RENDER_MODE  | 图片渲染模式属性，支持属性设置，属性重置，属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32 参数类型[ArkUI_ImageRenderMode](#arkui_imagerendermode)。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32 参数类型[ArkUI_ImageRenderMode](#arkui_imagerendermode)。 | 
| NODE_TOGGLE_SELECTED_COLOR  | 组件打开状态的背景颜色属性，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].u32：背景色数值，0xargb格式，形如 0xFFFF0000 表示红色。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].u32：背景色数值，0xargb格式。 | 
| NODE_TOGGLE_SWITCH_POINT_COLOR  | Switch类型的圆形滑块颜色属性，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].u32：圆形滑块颜色数值，0xargb格式，形如 0xFFFF0000 表示红色。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].u32：圆形滑块颜色数值，0xargb格式。 | 
| NODE_TOGGLE_VALUE  | Switch类型的开关值，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：设置开关的值，true表示开启。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：设置开关的值。 | 
| NODE_LOADING_PROGRESS_COLOR  | 加载进度条前景色属性，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].u32：前景颜色数值，0xargb格式，形如 0xFFFF0000 表示红色。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].u32：前景颜色数值，0xargb格式。 | 
| NODE_LOADING_PROGRESS_ENABLE_LOADING  | LoadingProgress动画显示属性，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：false时不显示动画，true时可以显示动画；<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：0时不显示动画，1时可以显示动画。 | 
| NODE_TEXT_INPUT_PLACEHOLDER  | 单行文本输入框的默认提示文本内容属性，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.string：默认提示文本的内容。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.string：默认提示文本的内容。 | 
| NODE_TEXT_INPUT_TEXT  | 单行文本输入框的默认文本内容属性，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.string：默认文本的内。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.string：默认文本的内容。 | 
| NODE_TEXT_INPUT_CARET_COLOR  | 光标颜色属性，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].u32：光标颜色数值，0xargb格式，形如 0xFFFF0000 表示红色；<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].u32：光标颜色数值，0xargb格式。 | 
| NODE_TEXT_INPUT_CARET_STYLE  | 光标风格属性，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32：光标宽度数值，单位为vp；<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32：光标宽度数值，单位为vp。 | 
| NODE_TEXT_INPUT_SHOW_UNDERLINE  | 单行文本输入框下划线属性，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：false表示不展示下划线，true表示展示下划线；<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：0表示不展示下划线，1表示展示下划线。 | 
| NODE_TEXT_INPUT_MAX_LENGTH  | 输入框支持的最大文本数属性，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：最大文本数的数字，无单位。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：最大文本数的数字。 | 
| NODE_TEXT_INPUT_ENTER_KEY_TYPE  | 回车键类型属性，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：回车键类型枚举[ArkUI_EnterKeyType](#arkui_enterkeytype)，默认值为ARKUI_ENTER_KEY_TYPE_DONE。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：回车键类型枚举[ArkUI_EnterKeyType](#arkui_enterkeytype)。 | 
| NODE_TEXT_INPUT_PLACEHOLDER_COLOR  | 无输入时默认提示文本的颜色属性，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].u32：颜色数值，0xargb格式，形如 0xFFFF0000 表示红色。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].u32：颜色数值，0xargb格式。 | 
| NODE_TEXT_INPUT_PLACEHOLDER_FONT  | 无输入时默认提示文本的字体配置（包括大小、字重、样式、字体列表）属性，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0]?.f32：可选字体大小数值，默认值16.0，单位为fp；<br/>.value[1]?.i32：可选字体样式[ArkUI_FontStyle](#arkui_fontstyle)，默认值为ARKUI_FONT_STYLE_NORMAL；<br/>.value[2]?.i32：可选字体粗细样式[ArkUI_FontWeight](#arkui_fontweight)，默认值为ARKUI_FONT_WEIGHT_NORMAL；<br/>?.string: 字体族内容，多个字体族之间使用逗号分隔，形如“字重；字体族1，字体族2”。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32：字体大小数值，单位为fp；<br/>.value[1].i32：字体样式[ArkUI_FontStyle](#arkui_fontstyle)；<br/>.value[2].i32：字体粗细样式[ArkUI_FontWeight](#arkui_fontweight)；<br/>.string: 字体族内容，多个字体族之间使用逗号分隔。 | 
| NODE_TEXT_INPUT_ENABLE_KEYBOARD_ON_FOCUS  | 聚焦时是否绑定输入法属性，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：false表示聚焦不拉起输入法，true表示拉起。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：0表示聚焦不拉起输入法，1表示拉起。 | 
| NODE_TEXT_INPUT_TYPE  | 输入框的类型属性，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：输入框类型枚举[ArkUI_TextInputType](#arkui_textinputtype)，默认值为ARKUI_TEXTINPUT_TYPE_NORMAL。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：输入框类型枚举[ArkUI_TextInputType](#arkui_textinputtype)。 | 
| NODE_TEXT_INPUT_SELECTED_BACKGROUND_COLOR  | 输入框文本选中时的背景色属性，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].u32：颜色数值，0xargb格式，形如 0xFFFF0000 表示红色。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].u32：颜色数值，0xargb格式。 | 
| NODE_TEXT_INPUT_SHOW_PASSWORD_ICON  | 密码输入模式时是否显示末尾图标属性，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：false表示不显示图标，true表示显示图标；<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：0表示不显示图标，1表示显示图标。 | 
| NODE_TEXT_INPUT_EDITING  | 控制单行文本输入框编辑态属性，支持属性设置。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：false表示退出编辑态，true表示维持现状。<br/>属性获取方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：false表示退出编辑态，true表示维持现状。 | 
| NODE_TEXT_INPUT_CANCEL_BUTTON  | 单行文本右侧清除按钮样式属性，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：按钮样式[ArkUI_CancelButtonStyle](#arkui_cancelbuttonstyle)，默认值为ARKUI_CANCELBUTTON_STYLE_INPUT；<br/>.value[1]?.f32：图标大小数值，单位为vp；<br/>.value[2]?.u32：按钮图标颜色数值，0xargb格式，形如 0xFFFF0000 表示红色；<br/>?.string：按钮图标地址，入参内容为图片本地地址，例如 /pages/icon.png。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：按钮样式[ArkUI_CancelButtonStyle](#arkui_cancelbuttonstyle)；<br/>.value[1].f32：图标大小数值，单位为vp；<br/>.value[2].u32：按钮图标颜色数值，0xargb格式；<br/>.string：按钮图标地址。 | 
| NODE_TEXT_INPUT_TEXT_SELECTION  | 单行文本设置文本选中并高亮的区域，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：选中文本的起始位置；<br/>.value[1].i32：选中文本的终止位置；<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：选中文本的起始位置；<br/>.value[1].i32：选中文本的终止位置； | 
| NODE_TEXT_AREA_PLACEHOLDER  | 多行文本输入框的默认提示文本内容属性，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.string：默认提示文本的内容。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.string：默认提示文本的内容。 | 
| NODE_TEXT_AREA_TEXT  | 多行文本输入框的默认文本内容属性，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.string：默认文本的内容。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.string：默认文本的内容。 | 
| NODE_TEXT_AREA_MAX_LENGTH  | 输入框支持的最大文本数属性，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：最大文本数的数字。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：最大文本数的数字。 | 
| NODE_TEXT_AREA_PLACEHOLDER_COLOR  | 无输入时默认提示文本的颜色属性，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].u32：颜色数值，0xargb格式，形如 0xFFFF0000 表示红色。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].u32：颜色数值，0xargb格式。 | 
| NODE_TEXT_AREA_PLACEHOLDER_FONT  | 无输入时默认提示文本的字体配置（包括大小、字重、样式、字体列表）属性，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0]?.f32：可选字体大小数值，默认值16.0，单位为fp；<br/>.value[1]?.i32：可选字体样式[ArkUI_FontStyle](#arkui_fontstyle)，默认值为ARKUI_FONT_STYLE_NORMAL；<br/>.value[2]?.i32：可选字体粗细样式[ArkUI_FontWeight](#arkui_fontweight)，默认值为ARKUI_FONT_WEIGHT_NORMAL；<br/>?.string: 字体族内容，多个字体族之间使用逗号分隔，形如“字重；字体族1，字体族2”。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32：字体大小数值，单位为fp；<br/>.value[1].i32：字体样式[ArkUI_FontStyle](#arkui_fontstyle)；<br/>.value[2].i32：字体粗细样式[ArkUI_FontWeight](#arkui_fontweight)；<br/>.string: 字体族内容，多个字体族之间使用逗号分隔。 | 
| NODE_TEXT_AREA_CARET_COLOR  | 光标颜色属性，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].u32：背景色数值，0xargb格式，形如 0xFFFF0000 表示红色。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].u32：背景色数值，0xargb格式。 | 
| NODE_TEXT_AREA_EDITING  | 控制多行文本输入框编辑态属性，支持属性设置。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：false表示退出编辑态，true表示维持现状。<br/>属性获取方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：false表示退出编辑态，true表示维持现状。 | 
| NODE_TEXT_AREA_TYPE  | 输入框的类型属性，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：输入框类型枚举[ArkUI_TextAreaType](#arkui_textareatype)，默认值为ARKUI_TEXTAREA_TYPE_NORMAL。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：输入框类型枚举[ArkUI_TextAreaType](#arkui_textareatype)。 | 
| NODE_TEXT_AREA_SHOW_COUNTER  | 设置输入的字符数超过阈值时是否显示计数器并设置计数器样式，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：是否开启计数器，值为true时为开启。<br/>.value[1]?.f32：可输入字符数占最大字符限制的百分比值，超过此值时显示计数器，取值范围1-100，小数时向下取整。<br/>.value[2]?.i32：输入字符超出限制时是否高亮边框。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：是否开启计数器。<br/>.value[1].f32：可输入字符数占最大字符限制的百分比值，超过此值时显示计数器，取值范围1-100。<br/>.value[2].i32：输入字符超出限制时是否高亮边框，默认高亮。 | 
| NODE_BUTTON_LABEL  | button按钮的文本内容属性，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.string：默认文本的内容。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.string：默认文本的内容。 | 
| NODE_PROGRESS_VALUE  | 进度条的当前进度值属性，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32：进度条当前值。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32：进度条当前值。 | 
| NODE_PROGRESS_TOTAL  | 进度条的总长属性，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32：进度条总长。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32：进度条总长。 | 
| NODE_PROGRESS_COLOR  | 进度条显示进度值的颜色属性，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].u32：颜色数值，0xargb格式，形如 0xFFFF0000 表示红色。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].u32：颜色数值，0xargb格式。 | 
| NODE_PROGRESS_TYPE  | 进度条的类型属性，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：进度条类型枚举值[ArkUI_ProgressType](#arkui_progresstype)，默认值为ARKUI_PROGRESS_TYPE_LINEAR。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：进度条类型枚举值[ArkUI_ProgressType](#arkui_progresstype)。 | 
| NODE_CHECKBOX_SELECT  | CheckBox多选框是否选中，支持属性设置，属性重置和属性获取。<br/>属性设置方法[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)参数格式：<br/>.value[0].i32：1表示选中，0表示不选中。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：1表示选中，0表示不选中。 | 
| NODE_CHECKBOX_SELECT_COLOR  | CheckBox多选框选中状态颜色，支持属性设置，属性重置和属性获取。<br/>属性设置方法[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)参数格式：<br/>.value[0].u32：多选框选中状态颜色, 类型为0xargb，如0xFF1122FF。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].u32：多选框选中状态颜色, 类型为0xargb，如0xFF1122FF。 | 
| NODE_CHECKBOX_UNSELECT_COLOR  | CheckBox多选框非选中状态边框颜色，支持属性设置，属性重置和属性获取。<br/>属性设置方法[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)参数格式：<br/>.value[0].u32：边框颜色, 类型为0xargb，如0xFF1122FF。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].u32：边框颜色, 类型为0xargb，如0xFF1122FF。 | 
| NODE_CHECKBOX_MARK  | CheckBox多选框内部图标样式，支持属性设置，属性重置和属性获取。<br/>属性设置方法[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)参数格式：<br/>.value[0].u32：边框颜色, 类型为0xargb，如0xFF1122FF；<br/>.value[1]?.f32：可选，内部图标大小，单位vp；<br/>.value[2]?.f32：可选，内部图标粗细，单位vp，默认值2。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].u32：边框颜色, 类型为0xargb，如0xFF1122FF；<br/>.value[1].f32：内部图标大小，单位vp；<br/>.value[2].f32：内部图标粗细，单位vp，默认值2。 | 
| NODE_CHECKBOX_SHAPE  | CheckBox组件形状, 支持属性设置，属性重置和属性获取。<br/>属性设置方法[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)参数格式：<br/>.value[0].i32：组件形状，参数类型[ArkUI_CheckboxShape](#arkui_checkboxshape)。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：组件形状，参数类型[ArkUI_CheckboxShape](#arkui_checkboxshape)。 | 
| NODE_XCOMPONENT_ID  | XComponent组件ID属性，支持属性设置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.string: ID的内容。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.string: ID的内容。 | 
| NODE_XCOMPONENT_TYPE  | XComponent的类型，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：字体样式[ArkUI_XComponentType](#arkui_xcomponenttype)，默认值为ARKUI_XCOMPONENT_TYPE_SURFACE；<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：字体样式[ArkUI_XComponentType](#arkui_xcomponenttype)。 | 
| NODE_XCOMPONENT_SURFACE_SIZE  | 设置XComponent的宽高，支持属性设置和获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].u32：宽数值，单位为px；<br/>.value[1].u32：高数值，单位为px；<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].u32：宽数值，单位为px；<br/>.value[1].u32：高数值，单位为px； | 
| NODE_DATE_PICKER_LUNAR  | 设置日期选择器组件的日期是否显示农历，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32： 是否显示农历，默认值false。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32： 是否显示农历。 | 
| NODE_DATE_PICKER_START  | 设置日期选择器组件选择器的起始日期，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.string： 日期，默认值"1970-1-1"。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.string： 日期。 | 
| NODE_DATE_PICKER_END  | 设置日期选择器组件选择器的结束日期，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.string： 日期，默认值"2100-12-31"。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.string： 日期。 | 
| NODE_DATE_PICKER_SELECTED  | 设置日期选择器组件选中项的日期，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.string： 日期，默认值"2024-01-22"。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.string： 日期。 | 
| NODE_DATE_PICKER_DISAPPEAR_TEXT_STYLE  | 设置日期选择器组件的所有选项中最上和最下两个选项的文本颜色、字号、字体粗细，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.string： 入参5个，格式为字符串，以 ';' 分割：<br/>入参1： 文本颜色，::argb类型<br/>入参2： 文本大小，数字类型，单位fp<br/>入参3： 文本粗细，字符串枚举("bold", "normal", "bolder", "lighter", "medium", "regular")<br/>入参4： 文本字体列表，使用 ',' 进行分割<br/>入参5： 文本样式，字符串枚举("normal", "italic")<br/>如 "\#ff182431;14;normal;Arial,HarmonyOS Sans;normal" 。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.string： 参数5个，格式为字符串，以 ';' 分割：<br/>参数1： 文本颜色，::argb类型<br/>参数2： 文本大小，数字类型，单位fp<br/>参数3： 文本粗细，字符串枚举("bold", "normal", "bolder", "lighter", "medium", "regular")<br/>参数4： 文本字体列表，使用 ',' 进行分割<br/>参数5： 文本样式，字符串枚举("normal", "italic")<br/>如 "\#ff182431;14;normal;Arial,HarmonyOS Sans;normal" 。 | 
| NODE_DATE_PICKER_TEXT_STYLE  | 设置日期选择器组件的所有选项中除了最上、最下及选中项以外的文本颜色、字号、字体粗细，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.string： 入参5个，格式为字符串，以 ';' 分割：<br/>入参1： 文本颜色，::argb类型<br/>入参2： 文本大小，数字类型，单位fp<br/>入参3： 文本粗细，字符串枚举("bold", "normal", "bolder", "lighter", "medium", "regular")<br/>入参4： 文本字体列表，使用 ',' 进行分割<br/>入参5： 文本样式，字符串枚举("normal", "italic")<br/>如 "\#ff182431;14;normal;Arial,HarmonyOS Sans;normal" 。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.string： 参数5个，格式为字符串，以 ';' 分割：<br/>参数1： 文本颜色，::argb类型<br/>参数2： 文本大小，数字类型，单位fp<br/>参数3： 文本粗细，字符串枚举("bold", "normal", "bolder", "lighter", "medium", "regular")<br/>参数4： 文本字体列表，使用 ',' 进行分割<br/>参数5： 文本样式，字符串枚举("normal", "italic")<br/>如 "\#ff182431;14;normal;Arial,HarmonyOS Sans;normal" 。 | 
| NODE_DATE_PICKER_SELECTED_TEXT_STYLE  | 设置日期选择器组件的选中项的文本颜色、字号、字体粗细，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.string： 入参5个，格式为字符串，以 ';' 分割：<br/>入参1： 文本颜色，::argb类型<br/>入参2： 文本大小，数字类型，单位fp<br/>入参3： 文本粗细，字符串枚举("bold", "normal", "bolder", "lighter", "medium", "regular")<br/>入参4： 文本字体列表，使用 ',' 进行分割<br/>入参5： 文本样式，字符串枚举("normal", "italic")<br/>如 "\#ff182431;14;normal;Arial,HarmonyOS Sans;normal" 。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.string： 参数5个，格式为字符串，以 ';' 分割：<br/>参数1： 文本颜色，::argb类型<br/>参数2： 文本大小，数字类型，单位fp<br/>参数3： 文本粗细，字符串枚举("bold", "normal", "bolder", "lighter", "medium", "regular")<br/>参数4： 文本字体列表，使用 ',' 进行分割<br/>参数5： 文本样式，字符串枚举("normal", "italic")<br/>如 "\#ff182431;14;normal;Arial,HarmonyOS Sans;normal" 。 | 
| NODE_TIME_PICKER_SELECTED  | 设置时间选择组件选中项的时间，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.string： 时间，默认值当前系统时间。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.string： 时间。 | 
| NODE_TIME_PICKER_USE_MILITARY_TIME  | 设置时间选择组件展示时间是否为24小时制，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32： 是否为24小时制，默认值false。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32： 是否为24小时制。 | 
| NODE_TIME_PICKER_DISAPPEAR_TEXT_STYLE  | 设置时间选择组件所有选项中最上和最下两个选项的文本颜色、字号、字体粗细，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.string： 入参5个，格式为字符串，以 ';' 分割：<br/>入参1： 文本颜色，::argb类型<br/>入参2： 文本大小，数字类型，单位fp<br/>入参3： 文本粗细，字符串枚举("bold", "normal", "bolder", "lighter", "medium", "regular")<br/>入参4： 文本字体列表，使用 ',' 进行分割<br/>入参5： 文本样式，字符串枚举("normal", "italic")<br/>如 "\#ff182431;14;normal;Arial,HarmonyOS Sans;normal" 。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.string： 参数5个，格式为字符串，以 ';' 分割：<br/>参数1： 文本颜色，::argb类型<br/>参数2： 文本大小，数字类型，单位fp<br/>参数3： 文本粗细，字符串枚举("bold", "normal", "bolder", "lighter", "medium", "regular")<br/>参数4： 文本字体列表，使用 ',' 进行分割<br/>参数5： 文本样式，字符串枚举("normal", "italic")<br/>如 "\#ff182431;14;normal;Arial,HarmonyOS Sans;normal" 。 | 
| NODE_TIME_PICKER_TEXT_STYLE  | 设置时间选择组件所有选项中除了最上、最下及选中项以外的文本颜色、字号、字体粗细，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.string： 入参5个，格式为字符串，以 ';' 分割：<br/>入参1： 文本颜色，::argb类型<br/>入参2： 文本大小，数字类型，单位fp<br/>入参3： 文本粗细，字符串枚举("bold", "normal", "bolder", "lighter", "medium", "regular")<br/>入参4： 文本字体列表，使用 ',' 进行分割<br/>入参5： 文本样式，字符串枚举("normal", "italic")<br/>如 "\#ff182431;14;normal;Arial,HarmonyOS Sans;normal" 。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.string： 参数5个，格式为字符串，以 ';' 分割：<br/>参数1： 文本颜色，::argb类型<br/>参数2： 文本大小，数字类型，单位fp<br/>参数3： 文本粗细，字符串枚举("bold", "normal", "bolder", "lighter", "medium", "regular")<br/>参数4： 文本字体列表，使用 ',' 进行分割<br/>参数5： 文本样式，字符串枚举("normal", "italic")<br/>如 "\#ff182431;14;normal;Arial,HarmonyOS Sans;normal" 。 | 
| NODE_TIME_PICKER_SELECTED_TEXT_STYLE  | 设置时间选择组件选中项的文本颜色、字号、字体粗细，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.string： 入参5个，格式为字符串，以 ';' 分割：<br/>入参1： 文本颜色，::argb类型<br/>入参2： 文本大小，数字类型，单位fp<br/>入参3： 文本粗细，字符串枚举("bold", "normal", "bolder", "lighter", "medium", "regular")<br/>入参4： 文本字体列表，使用 ',' 进行分割<br/>入参5： 文本样式，字符串枚举("normal", "italic")<br/>如 "\#ff182431;14;normal;Arial,HarmonyOS Sans;normal" 。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.string： 参数5个，格式为字符串，以 ';' 分割：<br/>参数1： 文本颜色，::argb类型<br/>参数2： 文本大小，数字类型，单位fp<br/>参数3： 文本粗细，字符串枚举("bold", "normal", "bolder", "lighter", "medium", "regular")<br/>参数4： 文本字体列表，使用 ',' 进行分割<br/>参数5： 文本样式，字符串枚举("normal", "italic")<br/>如 "\#ff182431;14;normal;Arial,HarmonyOS Sans;normal" 。 | 
| NODE_TEXT_PICKER_OPTION_RANGE  | 设置滑动选择文本选择器的选择列表，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：使用的选择器类型[ArkUI_TextPickerRangeType](#arkui_textpickerrangetype)，默认值为ARKUI_TEXTPICKER_RANGETYPE_SINGLE；<br/>?.string：针对不同选择器类型有如下输入范式：<br/>1：单列选择器，入参格式为用分号分隔的一组字符串；<br/>2：多列选择器，支持多对纯文本字符串对，多对之间使用分号分隔，每对内部使用逗号分隔；<br/>?.object：针对不同选择器类型有如下输入范式：<br/>1：单列支持图片的选择器，输入结构体为[ARKUI_TextPickerRangeContent](_a_r_k_u_i___text_picker_range_content.md)；<br/>2：多列联动选择器，输入结构体为[ARKUI_TextPickerCascadeRangeContent](_a_r_k_u_i___text_picker_cascade_range_content.md)；<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：使用的选择器类型[ArkUI_TextPickerRangeType](#arkui_textpickerrangetype)；<br/>?.string：针对不同选择器类型有如下输出范式：<br/>1：单列选择器，输出格式为用分号分隔的一组字符串；<br/>2：多列选择器，输出多对纯文本字符串对，多对之间使用分号分隔，每对内部使用逗号分隔；<br/>?.object：针对不同选择器类型有如下输出范式：<br/>1：单列支持图片的选择器，输出结构体为[ARKUI_TextPickerRangeContent](_a_r_k_u_i___text_picker_range_content.md)；<br/>2：多列联动选择器，输出结构体为[ARKUI_TextPickerCascadeRangeContent](_a_r_k_u_i___text_picker_cascade_range_content.md)； | 
| NODE_TEXT_PICKER_OPTION_SELECTED  | 设置滑动选择文本内容的组件默认选中项在数组中的索引值，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].u32：索引值，如存在多个索引值则逐个添加。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].u32：索引值，如存在多个索引值则逐个添加； | 
| NODE_TEXT_PICKER_OPTION_VALUE  | 设置滑动选择文本内容的组件默认选中项的值，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.string：选中项的值，如存在多个值则逐个添加，用分号分隔。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.string：选中项的值，如存在多个值则逐个添加，用分号分隔； | 
| NODE_TEXT_PICKER_DISAPPEAR_TEXT_STYLE  | 设置滑动选择文本内容的组件所有选项中最上和最下两个选项的文本颜色、字号、字体粗细，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.string： 入参5个，格式为字符串，以 ';' 分割：<br/>入参1： 文本颜色，::argb类型<br/>入参2： 文本大小，数字类型，单位fp<br/>入参3： 文本粗细，字符串枚举("bold", "normal", "bolder", "lighter", "medium", "regular")<br/>入参4： 文本字体列表，使用 ',' 进行分割<br/>入参5： 文本样式，字符串枚举("normal", "italic")<br/>如 "\#ff182431;14;normal;Arial,HarmonyOS Sans;normal" 。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.string： 参数5个，格式为字符串，以 ';' 分割：<br/>参数1： 文本颜色，::argb类型<br/>参数2： 文本大小，数字类型，单位fp<br/>参数3： 文本粗细，字符串枚举("bold", "normal", "bolder", "lighter", "medium", "regular")<br/>参数4： 文本字体列表，使用 ',' 进行分割<br/>参数5： 文本样式，字符串枚举("normal", "italic")<br/>如 "\#ff182431;14;normal;Arial,HarmonyOS Sans;normal" 。 | 
| NODE_TEXT_PICKER_TEXT_STYLE  | 设置滑动选择文本内容的组件所有选项中除了最上、最下及选中项以外的文本颜色、字号、字体粗细，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.string： 入参5个，格式为字符串，以 ';' 分割：<br/>入参1： 文本颜色，::argb类型<br/>入参2： 文本大小，数字类型，单位fp<br/>入参3： 文本粗细，字符串枚举("bold", "normal", "bolder", "lighter", "medium", "regular")<br/>入参4： 文本字体列表，使用 ',' 进行分割<br/>入参5： 文本样式，字符串枚举("normal", "italic")<br/>如 "\#ff182431;14;normal;Arial,HarmonyOS Sans;normal" 。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.string： 参数5个，格式为字符串，以 ';' 分割：<br/>参数1： 文本颜色，::argb类型<br/>参数2： 文本大小，数字类型，单位fp<br/>参数3： 文本粗细，字符串枚举("bold", "normal", "bolder", "lighter", "medium", "regular")<br/>参数4： 文本字体列表，使用 ',' 进行分割<br/>参数5： 文本样式，字符串枚举("normal", "italic")<br/>如 "\#ff182431;14;normal;Arial,HarmonyOS Sans;normal" 。 | 
| NODE_TEXT_PICKER_SELECTED_TEXT_STYLE  | 设置滑动选择文本内容的组件选中项的文本颜色、字号、字体粗细，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.string： 入参5个，格式为字符串，以 ';' 分割：<br/>入参1： 文本颜色，::argb类型；<br/>入参2： 文本大小，数字类型，单位fp；<br/>入参3： 文本粗细，字符串枚举("bold", "normal", "bolder", "lighter", "medium", "regular")；<br/>入参4： 文本字体列表，使用 ',' 进行分割；<br/>入参5： 文本样式，字符串枚举("normal", "italic")；<br/>如 "\#ff182431;14;normal;Arial,HarmonyOS Sans;normal" 。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.string： 参数5个，格式为字符串，以 ';' 分割：<br/>参数1： 文本颜色，::argb类型；<br/>参数2： 文本大小，数字类型，单位fp；<br/>参数3： 文本粗细，字符串枚举("bold", "normal", "bolder", "lighter", "medium", "regular")；<br/>参数4： 文本字体列表，使用 ',' 进行分割；<br/>参数5： 文本样式，字符串枚举("normal", "italic")；<br/>如 "\#ff182431;14;normal;Arial,HarmonyOS Sans;normal" 。 | 
| NODE_TEXT_PICKER_SELECTED_INDEX  | 设置滑动选择文本内容的组件默认选中项在数组中的索引值，支持属性设置，属性重置和属性获取接口。<br/>[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)参数类型：<br/>.value[0...].i32：默认选中项在数组中的索引值数组。 | 
| NODE_TEXT_PICKER_CAN_LOOP  | Picker组件可循环滚动属性，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：false表示不可循环，true表示可循环。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>value[0].i32：0表示不可循环，1表示可循环。 | 
| NODE_TEXT_PICKER_DEFAULT_PICKER_ITEM_HEIGHT  | Picker各选择项的高度属性，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32：子项高度属性，单位为vp。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>value[0].f32：子项高度属性，单位为vp。 | 
| NODE_CALENDAR_PICKER_HINT_RADIUS  | 设置日历选中态底板圆角半径的参数，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32： 日历选中态底板圆角半径，取值范围[0,+∞)，其中取值为0表示底板样式为直角矩形； 取值范围为(0, 16)时，底板样式为圆角矩形；取值范围为[16,+∞)时，底板样式为圆形。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32： 日历选中态底板圆角半径，取值范围[0,+∞)，其中取值为0表示底板样式为直角矩形； 取值范围为(0, 16)时，底板样式为圆角矩形；取值范围为[16,+∞)时，底板样式为圆形。 | 
| NODE_CALENDAR_PICKER_SELECTED_DATE  | 设置日历选择选中日期的参数，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].u32： 选中的年。<br/>.value[1].u32： 选中的月。<br/>.value[2].u32： 选中的日。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].u32： 选中的年。<br/>.value[1].u32： 选中的月。<br/>.value[2].u32： 选中的日。 | 
| NODE_CALENDAR_PICKER_EDGE_ALIGNMENT  | 设置日历选择器与入口组件的对齐方式，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32： 对齐方式类型，参数类型[ArkUI_CalendarAlignment](#arkui_calendaralignment)。<br/>.value[1]?.f32： 按照对齐方式对齐后，选择器相对入口组件的x轴方向相对偏移。<br/>.value[2]?.f32： 按照对齐方式对齐后，选择器相对入口组件的y轴方向相对偏移。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32： 对齐方式类型，参数类型[ArkUI_CalendarAlignment](#arkui_calendaralignment)。<br/>.value[1].f32： 按照对齐方式对齐后，选择器相对入口组件的x轴方向相对偏移。<br/>.value[2].f32： 按照对齐方式对齐后，选择器相对入口组件的y轴方向相对偏移。 | 
| NODE_CALENDAR_PICKER_TEXT_STYLE  | 设置日历选择器入口区的文本颜色、字号、字体粗细。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0]?.u32： 入口区的文本颜色。<br/>.value[1]?.f32： 入口区的文本字号，单位为fp。<br/>.value[2]?.i32： 入口区的文本字体粗细，参数类型[ArkUI_FontWeight](#arkui_fontweight)。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].u32： 入口区的文本颜色。<br/>.value[1].f32： 入口区的文本字号，单位为fp。<br/>.value[2].i32： 入口区的文本字体粗细，参数类型[ArkUI_FontWeight](#arkui_fontweight)。 | 
| NODE_SLIDER_BLOCK_COLOR  | Slider滑块的颜色，支持属性设置，属性重置和属性获取。<br/>属性设置方法[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)参数格式：<br/>.value[0].u32：滑块的颜色, 类型为0xargb，如0xFF1122FF。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].u32：滑块的颜色, 类型为0xargb，如0xFF1122FF。 | 
| NODE_SLIDER_TRACK_COLOR  | Slider滑轨的背景颜色，支持属性设置，属性重置和属性获取。<br/>属性设置方法[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)参数格式：<br/>.value[0].u32：背景颜色, 类型为0xargb，如0xFF1122FF。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].u32：背景颜色, 类型为0xargb，如0xFF1122FF。 | 
| NODE_SLIDER_SELECTED_COLOR  | Slider滑轨的已滑动部分颜色，支持属性设置，属性重置和属性获取。<br/>属性设置方法[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)参数格式：<br/>.value[0].u32：已滑动部分颜色, 类型为0xargb，如0xFF1122FF。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].u32：已滑动部分颜色, 类型为0xargb，如0xFF1122FF。 | 
| NODE_SLIDER_SHOW_STEPS  | 设置是否显示步长刻度值，支持属性设置，属性重置和属性获取。<br/>属性设置方法[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)参数格式：<br/>.value[0].i32：是否显示步长刻度值，1表示显示，0表示不显示，默认值为0。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：是否显示步长刻度值，1表示显示，0表示不显示，默认值为0。 | 
| NODE_SLIDER_BLOCK_STYLE  | Slider滑块形状参数，支持属性设置，属性重置和属性获取。<br/>属性设置方法[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)参数格式：<br/>.value[0].i32：形状参数。参数类型[ArkUI_SliderBlockStyle](#arkui_sliderblockstyle)。<br/>.string? 可选值，根据形状参数而定。<br/>ARKUI_SLIDER_BLOCK_STYLE_IMAGE: 滑块图片资源。如/pages/common/icon.png。<br/>ARKUI_SLIDER_BLOCK_STYLE_SHAPE: 滑块使用的自定义形状。<br/>共有5种类型：<br/>1.rect类型：<br/>.value[1].i32：裁剪类型，参数类型[ArkUI_ShapeType](#arkui_shapetype)，ARKUI_SHAPE_TYPE_RECTANGLE；<br/>.value[2].f32：矩形宽度；<br/>.value[3].f32：矩形高度；<br/>.value[4].f32：矩形圆角宽度；<br/>.value[5].f32：矩形圆角高度；<br/>2.circle类型：<br/>.value[1].i32：裁剪类型，参数类型[ArkUI_ShapeType](#arkui_shapetype)，ARKUI_SHAPE_TYPE_CIRCLE；<br/>.value[2].f32：圆形宽度；<br/>.value[3].f32：圆形高度；<br/>3.ellipse类型：<br/>.value[1].i32：裁剪类型，参数类型[ArkUI_ShapeType](#arkui_shapetype)，ARKUI_SHAPE_TYPE_ELLIPSE；<br/>.value[2].f32：椭圆形宽度；<br/>.value[3].f32：椭圆形高度；<br/>4.path类型：<br/>.value[1].i32：裁剪类型，参数类型[ArkUI_ShapeType](#arkui_shapetype)，ARKUI_SHAPE_TYPE_PATH；<br/>.value[2].f32：路径宽度；<br/>.value[3].f32：路径高度；<br/>.string：路径绘制的命令字符串；<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：形状参数。参数类型[ArkUI_SliderBlockStyle](#arkui_sliderblockstyle)。<br/>.string? 可选值，根据形状参数而定。<br/>ARKUI_SLIDER_BLOCK_STYLE_IMAGE: 滑块图片资源。如/pages/common/icon.png。<br/>ARKUI_SLIDER_BLOCK_STYLE_SHAPE: 滑块使用的自定义形状。<br/>共有5种类型：<br/>1.rect类型：<br/>.value[1].i32：裁剪类型，参数类型[ArkUI_ShapeType](#arkui_shapetype)，ARKUI_SHAPE_TYPE_RECTANGLE；<br/>.value[2].f32：矩形宽度；<br/>.value[3].f32：矩形高度；<br/>.value[4].f32：矩形圆角宽度；<br/>.value[5].f32：矩形圆角高度；<br/>2.circle类型：<br/>.value[1].i32：裁剪类型，参数类型[ArkUI_ShapeType](#arkui_shapetype)，ARKUI_SHAPE_TYPE_CIRCLE；<br/>.value[2].f32：圆形宽度；<br/>.value[3].f32：圆形高度；<br/>3.ellipse类型：<br/>.value[1].i32：裁剪类型，参数类型[ArkUI_ShapeType](#arkui_shapetype)，ARKUI_SHAPE_TYPE_ELLIPSE；<br/>.value[2].f32：椭圆形宽度；<br/>.value[3].f32：椭圆形高度；<br/>4.path类型：<br/>.value[1].i32：裁剪类型，参数类型[ArkUI_ShapeType](#arkui_shapetype)，ARKUI_SHAPE_TYPE_PATH；<br/>.value[2].f32：路径宽度；<br/>.value[3].f32：路径高度；<br/>.string：路径绘制的命令字符串； | 
| NODE_SLIDER_VALUE  | slider进度值，支持属性设置，属性重置和属性获取。<br/>属性设置方法[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)参数格式：<br/>.value[0].f32：进度值。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32：进度值。 | 
| NODE_SLIDER_MIN_VALUE  | slider最小值，支持属性设置，属性重置和属性获取。<br/>属性设置方法[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)参数格式：<br/>.value[0].f32：进度值的最小值。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32：进度值的最小值。 | 
| NODE_SLIDER_MAX_VALUE  | slider最大值，支持属性设置，属性重置和属性获取。<br/>属性设置方法[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)参数格式：<br/>.value[0].f32：进度值的最大值。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32：进度值的最大值。 | 
| NODE_SLIDER_STEP  | Slider滑动步长，支持属性设置，属性重置和属性获取。<br/>属性设置方法[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)参数格式：<br/>.value[0].f32：滑动步长，取值范围：[0.01, 100]。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32：滑动步长，取值范围：[0.01, 100]。 | 
| NODE_SLIDER_DIRECTION  | Slider滑动条滑动方向，支持属性设置，属性重置和属性获取。<br/>属性设置方法[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)参数格式：<br/>.value[0].i32：显示样式，参数类型[ArkUI_SliderDirection](#arkui_sliderdirection)。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：显示样式，参数类型[ArkUI_SliderDirection](#arkui_sliderdirection)。 | 
| NODE_SLIDER_REVERSE  | Slider滑动条取值范围是否反向，支持属性设置，属性重置和属性获取。<br/>属性设置方法[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)参数格式：<br/>.value[0].i32：是否反向，1表示反向，0表示不反向。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：是否反向，1表示反向，0表示不反向。 | 
| NODE_SLIDER_STYLE  | Slider的滑块与滑轨显示样式，支持属性设置，属性重置和属性获取。<br/>属性设置方法[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)参数格式：<br/>.value[0].i32：显示样式，参数类型[ArkUI_SliderStyle](#arkui_sliderstyle)。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：显示样式，参数类型[ArkUI_SliderStyle](#arkui_sliderstyle)。 | 
| NODE_STACK_ALIGN_CONTENT  | 设置子组件在容器内的对齐方式，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32： 对齐方式，数据类型[ArkUI_Alignment](#arkui_alignment)，默认值ARKUI_ALIGNMENT_CENTER。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32： 对齐方式，数据类型[ArkUI_Alignment](#arkui_alignment)。 | 
| NODE_SCROLL_BAR_DISPLAY_MODE  | 设置滚动条状态，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32： 滚动条状态，数据类型[ArkUI_ScrollBarDisplayMode](#arkui_scrollbardisplaymode)，默认值ARKUI_SCROLL_BAR_DISPLAY_MODE_AUTO。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32： 滚动条状态，数据类型[ArkUI_ScrollBarDisplayMode](#arkui_scrollbardisplaymode)。 | 
| NODE_SCROLL_BAR_WIDTH  | 设置滚动条的宽度，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32： 滚动条宽度，单位vp，默认值4。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32： 滚动条宽度，单位vp。 | 
| NODE_SCROLL_BAR_COLOR  | 设置滚动条的颜色，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.data[0].u32： 滚动条颜色，0xargb类型。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.data[0].u32： 滚动条颜色，0xargb类型。 | 
| NODE_SCROLL_SCROLL_DIRECTION  | 设置滚动方向，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：滚动方向，数据类型[ArkUI_ScrollDirection](#arkui_scrolldirection)，默认值ARKUI_SCROLL_DIRECTION_VERTICAL。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：滚动方向，数据类型[ArkUI_ScrollDirection](#arkui_scrolldirection)。 | 
| NODE_SCROLL_EDGE_EFFECT  | 设置边缘滑动效果，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32： 边缘滑动效果，参数类型[ArkUI_EdgeEffect](#arkui_edgeeffect)，默认值ARKUI_EDGE_EFFECT_NONE；<br/>.value[1]?.i32： 可选值，组件内容大小小于组件自身时，设置是否开启滑动效果，开启为1，关闭为0，默认值1。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32： 边缘滑动效果，参数类型[ArkUI_EdgeEffect](#arkui_edgeeffect)；<br/>.value[1].i32： 组件内容大小小于组件自身时，设置是否开启滑动效果，开启为1，关闭为0。 | 
| NODE_SCROLL_ENABLE_SCROLL_INTERACTION  | 设置是否支持滚动手势，当设置为false时，无法通过手指或者鼠标滚动，但不影响控制器的滚动接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32： 是否支持滚动手势，默认值true。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32： 是否支持滚动手势。 | 
| NODE_SCROLL_FRICTION  | 设置摩擦系数，手动划动滚动区域时生效，只对惯性滚动过程有影响，对惯性滚动过程中的链式效果有间接影响。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32： 摩擦系数，默认值：非可穿戴设备为0.6，可穿戴设备为0.9。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32： 摩擦系数。 | 
| NODE_SCROLL_SNAP  | 设置Scroll组件的限位滚动模式，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32： Scroll组件限位滚动时的对其方式，数据类型[ArkUI_ScrollSnapAlign](#arkui_scrollsnapalign)，默认值ARKUI_SCROLL_SNAP_ALIGN_NONE；<br/>.value[1].i32： 在Scroll组件限位滚动模式下，该属性设置为false后，运行Scroll在开头和第一个限位点间自由滑动。默认值true，仅在限位点为多个时生效；<br/>.value[2].i32： 在Scroll组件限位滚动模式下，该属性设置为false后，运行Scroll在最后一个限位点和末尾间自由滑动。默认值true，仅在限位点为多个时生效；<br/>.value[3...].f32： Scroll组件限位滚动时的限位点，限位点即为Scroll组件能滑动停靠的偏移量。可以1个或多个。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32： Scroll组件限位滚动时的对其方式，数据类型[ArkUI_ScrollSnapAlign](#arkui_scrollsnapalign)；<br/>.value[1].i32： 在Scroll组件限位滚动模式下，该属性设置为false后，运行Scroll在开头和第一个限位点间自由滑动；<br/>.value[2].i32： 在Scroll组件限位滚动模式下，该属性设置为false后，运行Scroll在最后一个限位点和末尾间自由滑动；<br/>.value[3...].f32： Scroll组件限位滚动时的限位点，限位点即为Scroll组件能滑动停靠的偏移量。 | 
| NODE_SCROLL_NESTED_SCROLL  | Scroll嵌套滚动选项，支持属性设置，属性重置和属性获取。<br/>属性设置方法[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)参数格式：<br/>.value[0].i32：可滚动组件往末尾端滚动时的嵌套滚动，参数类型[ArkUI_ScrollNestedMode](#arkui_scrollnestedmode)。<br/>.value[1].i32：可滚动组件往起始端滚动时的嵌套滚动，参数类型[ArkUI_ScrollNestedMode](#arkui_scrollnestedmode)。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：可滚动组件往末尾端滚动时的嵌套滚动，参数类型[ArkUI_ScrollNestedMode](#arkui_scrollnestedmode)。<br/>.value[1].i32：可滚动组件往起始端滚动时的嵌套滚动，参数类型[ArkUI_ScrollNestedMode](#arkui_scrollnestedmode)。 | 
| NODE_SCROLL_OFFSET  | Scroll滑动到指定位置，支持属性设置，属性重置和属性获取。<br/>属性设置方法[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)参数格式：<br/>.value[0].f32：水平滑动偏移，单位为vp。<br/>.value[1].f32：垂直滑动偏移，单位为vp。<br/>.value[2]?.i32：可选值，滚动时长，单位为毫秒。<br/>.value[3]?.i32：可选值，滚动曲线，参数类型[ArkUI_AnimationCurve](#arkui_animationcurve)。默认值为ARKUI_CURVE_EASE。<br/>.value[4]?.i32：可选值，是否使能默认弹簧动效，默认值为0不使能。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32：水平滑动偏移，单位为vp。<br/>.value[1].f32：垂直滑动偏移，单位为vp。 | 
| NODE_SCROLL_EDGE  | Scroll滚动到容器边缘，支持属性设置，属性获取。<br/>属性设置方法[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)参数格式：<br/>.value[0].i32：容器边缘，参数类型[ArkUI_ScrollEdge](#arkui_scrolledge)。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：容器是否位于边缘，-1：表示未处于边缘，如果处于边缘状态参数类型[ArkUI_ScrollEdge](#arkui_scrolledge)。 | 
| NODE_SCROLL_ENABLE_PAGING  | 设置是否支持滑动翻页，支持属性设置，属性重置和属性获取接口。<br/>如果同时设置了划动翻页enablePaging和限位滚动scrollSnap，则scrollSnap优先生效，enablePaging不生效。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32： 是否支持划动翻页，默认值false。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32： 是否支持划动翻页。 | 
| NODE_LIST_DIRECTION  | 设置List组件排列方向，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：List组件排列方向，数据类型[ArkUI_Axis](#arkui_axis)，默认值ARKUI_AXIS_VERTICAL。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：List组件排列方向，数据类型[ArkUI_Axis](#arkui_axis)。 | 
| NODE_LIST_STICKY  | 配合ListItemGroup组件使用，设置ListItemGroup中header和footer是否要吸顶或吸底，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：配合ListItemGroup组件使用，设置ListItemGroup中header和footer是否要吸顶或吸底。数据类型[ArkUI_StickyStyle](#arkui_stickystyle)，默认值ARKUI_STICKY_STYLE_NONE。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：配合ListItemGroup组件使用，设置ListItemGroup中header和footer是否要吸顶或吸底。数据类型[ArkUI_StickyStyle](#arkui_stickystyle)。 |
| NODE_LIST_SPACE  | 设置列表项间距，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32： 子组件主轴方向的间隔。默认值0。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32： 子组件主轴方向的间隔。 | 
| NODE_SWIPER_LOOP  | Swiper是否开启循环，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：控制是否开启循环，0表示不循环，1表示循环，默认值为1。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：控制是否开启循环，0表示不循环，1表示循环，默认值为1。 | 
| NODE_SWIPER_AUTO_PLAY  | Swiper子组件是否自动播放，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：控制子组件是否自动播放，0表示不自动播放，1表示自动播放，默认值为0。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：控制子组件是否自动播放，0表示不自动播放，1表示自动播放，默认值为0。 | 
| NODE_SWIPER_SHOW_INDICATOR  | Swiper是否显示导航点指示器，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：是否显示导航点指示器，0表示不显示导航点指示器，1表示显示导航点指示器，默认值为1。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：是否显示导航点指示器，0表示不显示导航点指示器，1表示显示导航点指示器，默认值为1。 | 
| NODE_SWIPER_INTERVAL  | 设置Swiper自动播放时播放的时间间隔，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32：使用自动播放时播放的时间间隔，单位为毫秒。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32：使用自动播放时播放的时间间隔，单位为毫秒。 | 
| NODE_SWIPER_VERTICAL  | 设置Swiper是否为纵向滑动，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：是否为纵向滑动，0表示横向滑动，1表示纵向滑动，默认值为0。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：是否为纵向滑动，0表示横向滑动，1表示纵向滑动，默认值为0。 | 
| NODE_SWIPER_DURATION  | 设置Swiper子组件切换的动画时长，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32：子组件切换的动画时长，单位为毫秒, 默认值为400。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32：子组件切换的动画时长，单位为毫秒, 默认值为400。 | 
| NODE_SWIPER_CURVE  | 设置Swiper的动画曲线，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：设置动画曲线参数，参数类型[ArkUI_AnimationCurve](#arkui_animationcurve)，默认值为ARKUI_CURVE_LINEAR。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：设置动画曲线参数，参数类型[ArkUI_AnimationCurve](#arkui_animationcurve)，默认值为ARKUI_CURVE_LINEAR。 | 
| NODE_SWIPER_ITEM_SPACE  | 设置Swiper子组件与子组件之间间隙，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32：子组件与子组件之间间隙数值。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32：子组件与子组件之间间隙数值。 | 
| NODE_SWIPER_INDEX  | 设置Swiper当前在容器中显示的子组件的索引值，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：子组件的索引值。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：子组件的索引值。 | 
| NODE_SWIPER_DISPLAY_COUNT  | 设置Swiper一页内元素显示个数，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：子组件的索引值。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：子组件的索引值。 | 
| NODE_SWIPER_DISABLE_SWIPE  | 设置Swiper禁用组件滑动切换功能，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：是否禁用组件滑动切换功能，0表示不禁用滑动切换功能，1表示禁用滑动切换功能，默认值为0。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：是否禁用组件滑动切换功能，0表示不禁用滑动切换功能，1表示禁用滑动切换功能，默认值为0。 | 
| NODE_SWIPER_SHOW_DISPLAY_ARROW  | 设置Swiper是否显示导航点箭头，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：设置是否显示导航点箭头，参数类型[ArkUI_SwiperArrow](#arkui_swiperarrow)，<br/>默认值为ARKUI_SWIPER_ARROW_HIDE。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：设置是否显示导航点箭头，参数类型[ArkUI_SwiperArrow](#arkui_swiperarrow)，<br/>默认值为ARKUI_SWIPER_ARROW_HIDE。 | 
| NODE_SWIPER_EDGE_EFFECT_MODE  | 设置Swiper的边缘滑动效果，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32: 边缘滑动效果，参数类型[ArkUI_EdgeEffect](#arkui_edgeeffect)，<br/>默认值为ARKUI_EDGE_EFFECT_SPRING。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32: 边缘滑动效果，参数类型[ArkUI_EdgeEffect](#arkui_edgeeffect)， | 
| NODE_LIST_ITEM_GROUP_SET_HEADER  | 设置 ListItemGroup 头部组件，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.object：使用[ArkUI_NodeHandle](#arkui_nodehandle)对象作为ListItemGroup头部组件。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.object：使用[ArkUI_NodeHandle](#arkui_nodehandle)对象作为ListItemGroup头部组件。 | 
| NODE_LIST_ITEM_GROUP_SET_FOOTER  | 设置 ListItemGroup 尾部组件，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.object：使用[ArkUI_NodeHandle](#arkui_nodehandle)对象作为ListItemGroup尾部组件。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.object：使用[ArkUI_NodeHandle](#arkui_nodehandle)对象作为ListItemGroup尾部组件。 | 
| NODE_LIST_ITEM_GROUP_SET_DIVIDER  | 设置ListItem分割线样式，默认无分割线，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].u32： 颜色，0xargb类型；<br/>.value[1].f32： 分割线宽，单位vp；<br/>.value[2].f32： 分割线距离列表侧边起始端的距离，单位vp；<br/>.value[3].f32： 分割线距离列表侧边结束端的距离，单位vp。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].u32： 颜色，0xargb类型；<br/>.value[1].f32： 分割线宽，单位vp；<br/>.value[2].f32： 分割线距离列表侧边起始端的距离，单位vp；<br/>.value[3].f32： 分割线距离列表侧边结束端的距离，单位vp。 | 
| NODE_COLUMN_ALIGN_ITEMS  | 设置Column子组件在水平方向上的对齐格式，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：子组件在水平方向上的对齐格式，数据类型[ArkUI_HorizontalAlignment](#arkui_horizontalalignment)，<br/>默认值ARKUI_HORIZONTAL_ALIGNMENT_CENTER。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：子组件在水平方向上的对齐格式，数据类型[ArkUI_HorizontalAlignment](#arkui_horizontalalignment)。 | 
| NODE_COLUMN_JUSTIFY_CONTENT  | 设置Column子组件在垂直方向上的对齐格式，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：子组件在垂直方向上的对齐格式，数据类型[ArkUI_FlexAlignment](#arkui_flexalignment)，<br/>默认值ARKUI_FLEX_ALIGNMENT_START。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：子组件在垂直方向上的对齐格式，数据类型[ArkUI_FlexAlignment](#arkui_flexalignment)。 | 
| NODE_ROW_ALIGN_ITEMS  | 设置Row子组件在垂直方向上的对齐格式，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：子组件在垂直方向上的对齐格式，数据类型[ArkUI_VerticalAlignment](#arkui_verticalalignment)，<br/>默认值ARKUI_VERTICAL_ALIGNMENT_CENTER。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：子组件在垂直方向上的对齐格式，数据类型[ArkUI_VerticalAlignment](#arkui_verticalalignment)。 | 
| NODE_ROW_JUSTIFY_CONTENT  | 设置Row子组件在水平方向上的对齐格式，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：子组件在水平方向上的对齐格式，数据类型[ArkUI_FlexAlignment](#arkui_flexalignment)，<br/>默认值ARKUI_FLEX_ALIGNMENT_START。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：子组件在水平方向上的对齐格式，数据类型[ArkUI_FlexAlignment](#arkui_flexalignment)。 | 
| NODE_FLEX_OPTION  | 设置Flex属性，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0]?.i32：子组件在Flex容器上排列的方向[ArkUI_FlexDirection](#arkui_flexdirection)，默认值为ARKUI_FLEX_DIRECTION_ROW；<br/>.value[1]?.i32：排列规则[ArkUI_FlexWrap](#arkui_flexwrap)，默认值为ARKUI_FLEX_WRAP_NO_WRAP；<br/>.value[2]?.i32：主轴上的对齐格式[ArkUI_FlexAlignment](#arkui_flexalignment)，默认值为ARKUI_FLEX_ALIGNMENT_START；<br/>.value[3]?.i32：交叉轴上的对齐格式[ArkUI_ItemAlignment](#arkui_itemalignment)，默认值为ARKUI_ITEM_ALIGNMENT_START；<br/>.value[4]?.i32： 交叉轴中有额外的空间时，多行内容的对齐方式[ArkUI_FlexAlignment](#arkui_flexalignment)，默认值为ARKUI_FLEX_ALIGNMENT_START；<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：子组件在Flex容器上排列的方向的枚举值；<br/>.value[1].i32：排列规则的枚举值；<br/>.value[2].i32：主轴上的对齐格式的枚举值；<br/>.value[3].i32：交叉轴上的对齐格式的枚举值；<br/>.value[4].i32： 交叉轴中有额外的空间时，多行内容的对齐方式的枚举值； | 
| NODE_REFRESH_REFRESHING  | 设置组件是否正在刷新，支持属性设置，属性获取。<br/>属性设置方法[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)参数格式：<br/>.value[0].i32：参数类型为1或者0。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：参数类型为1或者0。 | 
| NODE_REFRESH_CONTENT  | 设置下拉区域的自定义内容，支持属性设置和重置。<br/>属性设置方法[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)参数格式：<br/>.object：参数类型{\@Link ArkUI_NodeHandle}。 | 
| NODE_WATER_FLOW_LAYOUT_DIRECTION  | 定义瀑布流组件布局主轴方向，支持属性设置、重置和获取。<br/>属性设置方法[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)参数格式：<br/>.value[0].i32 主轴方向，参数类型{\@Link ArkUI_FlexDirection}。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32 主轴方向，参数类型{\@Link ArkUI_FlexDirection}。 | 
| NODE_WATER_FLOW_COLUMN_TEMPLATE  | 设置当前瀑布流组件布局列的数量,不设置时默认1列. 例如,'1fr 1fr 2fr' 是将父组件分3列,将父组件允许的宽分为4等份,第一列占1份,第二列占1份,第三列占2份. 可使用columnsTemplate('repeat(auto-fill,track-size)')根据给定的列宽track-size自动计算列数, 其中repeat、auto-fill为关键字,track-size为可设置的宽度,支持的单位包括px、vp、或有效数字，默认单位为vp.<br/>属性设置方法[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)参数格式：<br/>.string: 布局列的数量.<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.string: 布局列的数量. | 
| NODE_WATER_FLOW_ROW_TEMPLATE  | 设置当前瀑布流组件布局行的数量,不设置时默认1行. 例如, '1fr 1fr 2fr'是将父组件分三行,将父组件允许的高分为4等份,第一行占1份,第二行占一份,第三行占2份. 可使用rowsTemplate('repeat(auto-fill,track-size)')根据给定的行高track-size自动计算行数, 其中repeat、auto-fill为关键字,track-size为可设置的高度,支持的单位包括px、vp、或有效数字,默认单位为vp.<br/>属性设置方法[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)参数格式：<br/>.string: 布局行的数量.<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.string: 布局行的数量. | 
| NODE_WATER_FLOW_COLUMN_GAP  | 设置列与列的间距.<br/>属性设置方法[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)参数格式：<br/>.value[0].f32: 列与列的间距, 单位vp.<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32: 列与列的间距, 单位vp. | 
| NODE_WATER_FLOW_ROW_GAP  | 设置行与行的间距.<br/>属性设置方法[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)参数格式：<br/>.value[0].f32: 行与行的间距, 单位vp.<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32: 行与行的间距, 单位vp. | 
| NODE_WATER_FLOW_SECTION_OPTION  | 设置当FlowItem分组配置信息.<br/>属性设置方法[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)参数格式：<br/>.object: 参数格式为{\@ArkUI_WaterFlowSectionOption}.<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.object: 返回值格式为{\@ArkUI_WaterFlowSectionOption}. | 
| NODE_LIST_CACHED_COUNT  | list组件Adapter缓存数量，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：配合List组件Adapter使用，设置adapter中的缓存数量<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32：adapter中的缓存数量。 | 
| NODE_SWIPER_CACHED_COUNT  | swiper组件Adapter缓存数量，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：配合swiper组件Adapter使用，设置adapter中的缓存数量<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：adapter中的缓存数量。 | 
| NODE_WATER_FLOW_CACHED_COUNT  | waterFlow组件Adapter缓存数量，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：配合waterFlow组件Adapter使用，设置adapter中的缓存数量 | 
| NODE_LIST_ITEM_SWIPE_ACTION  | 设置ListItem的划出组件，支持属性设置，属性重置，属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.object：使用[ArkUI_ListItemSwipeActionOption](#arkui_listitemswipeactionoption)对象构造。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.object：使用[ArkUI_ListItemSwipeActionOption](#arkui_listitemswipeactionoption)对象构造。 | 


### ArkUI_NodeCustomEventType

```
enum ArkUI_NodeCustomEventType
```
**描述：**

定义自定义组件事件类型。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_NODE_CUSTOM_EVENT_ON_MEASURE  | measure 类型。&nbsp;&nbsp; | 
| ARKUI_NODE_CUSTOM_EVENT_ON_LAYOUT  | layout 类型。&nbsp;&nbsp; | 
| ARKUI_NODE_CUSTOM_EVENT_ON_DRAW  | draw 类型。&nbsp;&nbsp; | 
| ARKUI_NODE_CUSTOM_EVENT_ON_FOREGROUND_DRAW  | foreground 类型。&nbsp;&nbsp; | 
| ARKUI_NODE_CUSTOM_EVENT_ON_OVERLAY_DRAW  | overlay 类型。&nbsp;&nbsp; | 


### ArkUI_NodeDirtyFlag

```
enum ArkUI_NodeDirtyFlag
```
**描述：**

自定义组件调用&lt;b&gt;::markDirty是传递的脏区标识类型。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| NODE_NEED_MEASURE  | 重新测算大小。<br/>该flag类型触发时，同时也默认会触发重新布局。 | 
| NODE_NEED_LAYOUT  | 重新布局位置。&nbsp;&nbsp; | 
| NODE_NEED_RENDER  | 重新进行绘制。&nbsp;&nbsp; | 


### ArkUI_NodeEventType

```
enum ArkUI_NodeEventType
```
**描述：**

提供NativeNode组件支持的事件类型定义。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| NODE_TOUCH_EVENT  | 手势事件类型。<br/>事件回调发生时，事件参数[ArkUI_NodeEvent](#arkui_nodeevent)对象中的联合体类型为[ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent)。 | 
| NODE_EVENT_ON_APPEAR  | 挂载事件。<br/>触发该事件的条件 ：组件挂载显示时触发此回调。<br/>事件回调发生时，事件参数[ArkUI_NodeEvent](#arkui_nodeevent)对象中的联合体类型为[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)。<br/>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)中不包含参数。 | 
| NODE_EVENT_ON_DISAPPEAR  | 卸载事件。<br/>触发该事件的条件 ：组件卸载时触发此回调。<br/>事件回调发生时，事件参数[ArkUI_NodeEvent](#arkui_nodeevent)对象中的联合体类型为[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)。<br/>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)中不包含参数。 | 
| NODE_EVENT_ON_AREA_CHANGE  | 组件区域变化事件<br/>触发该事件的条件：组件区域变化时触发该回调。<br/>事件回调发生时，事件参数[ArkUI_NodeEvent](#arkui_nodeevent)对象中的联合体类型为[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)。<br/>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)中包含12个参数：<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].f32**：表示过去目标元素的宽度，类型为number，单位vp。<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[1].f32**：表示过去目标元素的高度，类型为number，单位vp。<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[2].f32**：表示过去目标元素左上角相对父元素左上角的位置的x轴坐标，类型为number，单位vp。<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[3].f32**：表示过去目标元素左上角相对父元素左上角的位置的y轴坐标，类型为number，单位vp。<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[4].f32**：表示过去目标元素目标元素左上角相对页面左上角的位置的x轴坐标，类型为number，单位vp。<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[5].f32**：表示过去目标元素目标元素左上角相对页面左上角的位置的y轴坐标，类型为number，单位vp。<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[6].f32**：表示最新目标元素的宽度，类型为number，单位vp。<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[7].f32**：表示最新目标元素的高度，类型为number，单位vp。<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[8].f32**：表示最新目标元素左上角相对父元素左上角的位置的x轴坐标，类型为number，单位vp。<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[9].f32**：表示最新目标元素左上角相对父元素左上角的位置的y轴坐标，类型为number，单位vp。<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[10].f32**：表示最新目标元素目标元素左上角相对页面左上角的位置的x轴坐标，类型为number，单位vp。<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[11].f32**：表示最新目标元素目标元素左上角相对页面左上角的位置的y轴坐标，类型为number，单位vp。 | 
| NODE_ON_FOCUS  | 获焦事件。<br/>触发该事件的条件：组件获焦时触发此回调。<br/>事件回调发生时，事件参数[ArkUI_NodeEvent](#arkui_nodeevent)对象中的联合体类型为[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)。<br/>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)中不包含参数。 | 
| NODE_ON_BLUR  | 失去焦点事件。<br/>触发该事件的条件：组件失去焦点时触发此回调。<br/>事件回调发生时，事件参数[ArkUI_NodeEvent](#arkui_nodeevent)对象中的联合体类型为[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)。<br/>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)中不包含参数。 | 
| NODE_ON_CLICK  | 组件点击事件。<br/>触发该事件的条件：组件被点击时触发此回调。<br/>事件回调发生时，事件参数[ArkUI_NodeEvent](#arkui_nodeevent)对象中的联合体类型为[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)。<br/>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)中包含12个参数：<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].f32**：点击位置相对于被点击元素原始区域左上角的X坐标，单位vp。<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[1].f32**：点击位置相对于被点击元素原始区域左上角的Y坐标，单位vp。<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[2].f32**：事件时间戳。触发事件时距离系统启动的时间间隔，单位微妙。<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[3].i32**：事件输入设备，1表示鼠标，2表示触屏，4表示按键。<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[4].f32**：点击位置相对于应用窗口左上角的X坐标，单位vp。<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[5].f32**：点击位置相对于应用窗口左上角的Y坐标，单位vp。<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[6].f32**：点击位置相对于应用屏幕左上角的X坐标，单位vp。<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[7].f32**：点击位置相对于应用屏幕左上角的Y坐标，单位vp。 | 
| NODE_IMAGE_ON_COMPLETE  | 图片加载成功事件。<br/>触发该事件的条件 ：图片数据加载成功和解码成功均触发该回调。<br/>事件回调发生时，事件参数[ArkUI_NodeEvent](#arkui_nodeevent)对象中的联合体类型为[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)。<br/>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)中包含9个参数：<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].i32**：表示加载状态，0表示数据加载成功，1表示解码成功。<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[1].f32**：表示图片的宽度，单位px。<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[2].f32**：表示图片的高度，单位px。<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[3].f32**：表示当前组件的宽度，单位px。<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[4].f32**：表示当前组件的高度，单位px。<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[5].f32**：图片绘制区域相对组件X轴位置，单位px。<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[6].f32**：图片绘制区域相对组件Y轴位置，单位px。<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[7].f32**：图片绘制区域宽度，单位px。<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[8].f32**：图片绘制区域高度，单位px。 | 
| NODE_IMAGE_ON_ERROR  | 图片加载失败事件。<br/>触发该事件的条件：图片加载异常时触发该回调。<br/>事件回调发生时，事件参数[ArkUI_NodeEvent](#arkui_nodeevent)对象中的联合体类型为[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)。<br/>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)中包含1个参数：<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].i32**错误码信息：<br/>401: 图片路径参数异常，无法获取到图片数据。<br/>103101: 图片格式不支持。 | 
| NODE_IMAGE_ON_SVG_PLAY_FINISH  | SVG图片动效播放完成事件。<br/>触发该事件的条件：带动效的SVG图片动画结束时触发。<br/>事件回调发生时，事件参数[ArkUI_NodeEvent](#arkui_nodeevent)对象中的联合体类型为[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)。<br/>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)中不包含参数。 | 
| NODE_TOGGLE_ON_CHANGE  | 开关状态发生变化时触发给事件。<br/>触发该事件的条件：开关状态发生变化。<br/>事件回调发生时，事件参数[ArkUI_NodeEvent](#arkui_nodeevent)对象中的联合体类型为[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)。<br/>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)中包含1个参数：<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].i32**：当前开关状态，1表示开，0表示关。 | 
| NODE_TEXT_INPUT_ON_CHANGE  | textInput输入内容发生变化时触发该事件。<br/>触发该事件的条件：输入内容发生变化时。<br/>事件回调发生时，事件参数[ArkUI_NodeEvent](#arkui_nodeevent)对象中的联合体类型为[ArkUI_StringAsyncEvent](_ark_u_i___string_async_event.md)。<br/>[ArkUI_StringAsyncEvent](_ark_u_i___string_async_event.md)中包含1个参数：<br/>**[ArkUI_StringAsyncEvent.pStr](_ark_u_i___string_async_event.md#pstr)**：输入的文本内容。 | 
| NODE_TEXT_INPUT_ON_SUBMIT  | textInput按下输入法回车键触发该事件。<br/>触发该事件的条件：按下输入法回车键。<br/>事件回调发生时，事件参数[ArkUI_NodeEvent](#arkui_nodeevent)对象中的联合体类型为[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)。<br/>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)中包含1个参数：<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].i32**：输入法回车键类型。 | 
| NODE_TEXT_INPUT_ON_CUT  | 长按输入框内部区域弹出剪贴板后，点击剪切板剪切按钮，触发该回调。<br/>触发该事件的条件：长按输入框内部区域弹出剪贴板后，点击剪切板剪切按钮。<br/>事件回调发生时，事件参数[ArkUI_NodeEvent](#arkui_nodeevent)对象中的联合体类型为[ArkUI_StringAsyncEvent](_ark_u_i___string_async_event.md)。<br/>[ArkUI_StringAsyncEvent](_ark_u_i___string_async_event.md)中包含1个参数：<br/>**[ArkUI_StringAsyncEvent.pStr](_ark_u_i___string_async_event.md#pstr)**：剪切的文本内容。 | 
| NODE_TEXT_INPUT_ON_PASTE  | 长按输入框内部区域弹出剪贴板后，点击剪切板粘贴按钮，触发该回调。<br/>触发该事件的条件：长按输入框内部区域弹出剪贴板后，点击剪切板粘贴按钮。<br/>事件回调发生时，事件参数[ArkUI_NodeEvent](#arkui_nodeevent)对象中的联合体类型为[ArkUI_StringAsyncEvent](_ark_u_i___string_async_event.md)。<br/>[ArkUI_StringAsyncEvent](_ark_u_i___string_async_event.md)中包含1个参数：<br/>**[ArkUI_StringAsyncEvent.pStr](_ark_u_i___string_async_event.md#pstr)**：粘贴的文本内容。 | 
| NODE_TEXT_INPUT_ON_TEXT_SELECTION_CHANGE  | 文本选择的位置发生变化时，触发该回调。<br/>触发该事件的条件：文本选择的位置发生变化时。<br/>事件回调发生时，事件参数[ArkUI_NodeEvent](#arkui_nodeevent)对象中的联合体类型为[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)。<br/>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)中包含2个参数：<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].i32**：表示所选文本的起始位置。<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[1].i32**：表示所选文本的结束位置。 | 
| NODE_TEXT_AREA_ON_CHANGE  | 输入内容发生变化时，触发该回调。<br/>触发该事件的条件：输入内容发生变化时。<br/>事件回调发生时，事件参数[ArkUI_NodeEvent](#arkui_nodeevent)对象中的联合体类型为[ArkUI_StringAsyncEvent](_ark_u_i___string_async_event.md)。<br/>[ArkUI_StringAsyncEvent](_ark_u_i___string_async_event.md)中包含1个参数：<br/>**[ArkUI_StringAsyncEvent.pStr](_ark_u_i___string_async_event.md#pstr)**：当前输入的文本内容。 | 
| NODE_TEXT_AREA_ON_PASTE  | 长按输入框内部区域弹出剪贴板后，点击剪切板粘贴按钮，触发该回调。<br/>触发该事件的条件：长按输入框内部区域弹出剪贴板后，点击剪切板粘贴按钮。<br/>事件回调发生时，事件参数[ArkUI_NodeEvent](#arkui_nodeevent)对象中的联合体类型为[ArkUI_StringAsyncEvent](_ark_u_i___string_async_event.md)。<br/>[ArkUI_StringAsyncEvent](_ark_u_i___string_async_event.md)中包含1个参数：<br/>**[ArkUI_StringAsyncEvent.pStr](_ark_u_i___string_async_event.md#pstr)**：粘贴的文本内容。 | 
| NODE_TEXT_AREA_ON_TEXT_SELECTION_CHANGE  | 文本选择的位置发生变化时，触发该回调。<br/>触发该事件的条件：文本选择的位置发生变化时。<br/>事件回调发生时，事件参数[ArkUI_NodeEvent](#arkui_nodeevent)对象中的联合体类型为[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)。<br/>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)中包含2个参数：<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].i32**：表示所选文本的起始位置。<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[1].i32**：表示所选文本的结束位置。 | 
| NODE_CHECKBOX_EVENT_ON_CHANGE  | 定义ARKUI_NODE_CHECKBOX当选中状态发生变化时，触发该回调。<br/>事件回调发生时，事件参数[ArkUI_NodeEvent](#arkui_nodeevent)对象中的联合体类型为[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)。<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].i32**1:表示已选中, 0: 表示未选中 | 
| NODE_DATE_PICKER_EVENT_ON_DATE_CHANGE  | 定义ARKUI_NODE_DATE_PICKER列表组件的滚动触摸事件枚举值。<br/>触发该事件的条件：选择日期时触发该事件。<br/>事件回调发生时，事件参数[ArkUI_NodeEvent](#arkui_nodeevent)对象中的联合体类型为[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)。<br/>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)中包含3个参数：<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].i32**：表示选中时间的年。<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[1].i32**：表示选中时间的月，取值范围：[0-11]。<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[2].i32**：表示选中时间的天。 | 
| NODE_TIME_PICKER_EVENT_ON_CHANGE  | 定义ARKUI_NODE_TIME_PICKER列表组件的滚动触摸事件枚举值。<br/>触发该事件的条件：选择时间时触发该事件。<br/>事件回调发生时，事件参数[ArkUI_NodeEvent](#arkui_nodeevent)对象中的联合体类型为[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)。<br/>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)中包含2个参数：<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].i32**：表示选中时间的时，取值范围：[0-23]。<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[1].i32**：表示选中时间的分，取值范围：[0-59]。 | 
| NODE_TEXT_PICKER_EVENT_ON_CHANGE  | 定义ARKUI_NODE_TEXT_PICKER列表组件的滚动触摸事件枚举值。<br/>触发该事件的条件 ：选择时间时触发该事件。<br/>事件回调发生时，事件参数[ArkUI_NodeEvent](#arkui_nodeevent)对象中的联合体类型为[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)。<br/>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)中包含1个参数：<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0...11].i32**表示选中数据的维度。 | 
| NODE_CALENDAR_PICKER_EVENT_ON_CHANGE  | 定义NODE_CALENDAR_PICKER选中日期时触发的事件。<br/>事件回调发生时，事件参数[ArkUI_NodeEvent](#arkui_nodeevent)对象中的联合体类型为[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)。<br/>**ArkUI_NodeComponent.data[0].u32**选中的年。<br/>**ArkUI_NodeComponent.data[1].u32**选中的月。<br/>**ArkUI_NodeComponent.data[2].u32**选中的日。 | 
| NODE_SLIDER_EVENT_ON_CHANGE  | 定义ARKUI_NODE_SLIDER拖动或点击时触发事件回调。<br/>事件回调发生时，事件参数[ArkUI_NodeEvent](#arkui_nodeevent)对象中的联合体类型为[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)。<br/>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)中包含2个参数：<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].f32**：当前滑动进度值。<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[1].i32**：事件触发的相关状态值 | 
| NODE_SWIPER_EVENT_ON_CHANGE  | 定义ARKUI_NODE_SWIPER当前元素索引变化时触发事件回调。<br/>事件回调发生时，事件参数[ArkUI_NodeEvent](#arkui_nodeevent)对象中的联合体类型为[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)。<br/>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)中包含1个参数：<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].i32**：表示当前显示元素的索引。 | 
| NODE_SWIPER_EVENT_ON_ANIMATION_START  | 定义ARKUI_NODE_SWIPER切换动画开始时触发回调。<br/>事件回调发生时，事件参数[ArkUI_NodeEvent](#arkui_nodeevent)对象中的联合体类型为[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)。<br/>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)中包含5个参数：<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].i32**：表示当前显示元素的索引。<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[1].i32**：表示切换动画目标元素的索引。<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[2].f32**：表示主轴方向上当前显示元素相对Swiper起始位置的位移。<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[3].f32**：表示主轴方向上目标元素相对Swiper起始位置的位移。<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[4].f32**：表示离手速度。 | 
| NODE_SWIPER_EVENT_ON_ANIMATION_END  | 定义ARKUI_NODE_SWIPER切换动画结束是触发回调。<br/>事件回调发生时，事件参数[ArkUI_NodeEvent](#arkui_nodeevent)对象中的联合体类型为[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)。<br/>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)中包含2个参数：<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].i32**：表示当前显示元素的索引。<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[1].f32**：表示主轴方向上当前显示元素相对Swiper起始位置的位移。 | 
| NODE_SWIPER_EVENT_ON_GESTURE_SWIPE  | 定义ARKUI_NODE_SWIPER在页面跟手滑动过程中，逐帧触发该回调。<br/>事件回调发生时，事件参数[ArkUI_NodeEvent](#arkui_nodeevent)对象中的联合体类型为[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)。<br/>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)中包含2个参数：<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].i32**：表示当前显示元素的索引。<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[1].f32**：表示主轴方向上当前显示元素相对Swiper起始位置的位移。 | 
| NODE_SWIPER_EVENT_ON_CONTENT_DID_SCROLL  | 定义ARKUI_NODE_SWIPER监听Swiper页面滑动事件。 使用说明 ：<br/>1、设置[ArkUI_SwiperDisplayModeType](#arkui_swiperdisplaymodetype)属性为ARKUI_SWIPER_DISPLAY_MODE_AUTO_LINEAR时，该接口不生效。<br/>2、循环场景下，设置prevMargin和nextMargin属性，使得Swiper前后端显示同一页面时，该接口不生效。<br/>3、在页面滑动过程中，会对视窗内所有页面逐帧触发ContentDidScrollCallback回调。<br/>例如，当视窗内有下标为0、1的两个页面时，会每帧触发两次index值分别为0和1的回调。<br/>4、设置displayCount属性的swipeByGroup参数为true时，若同组中至少有一个页面在视窗内时，<br/>则会对同组中所有页面触发回调。<br/>事件回调发生时，事件参数[ArkUI_NodeEvent](#arkui_nodeevent)对象中的联合体类型为[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)。<br/>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)中包含4个参数：<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].i32**：Swiper组件的索引，和onChange事件中的index值变化保持一致。<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[1].i32**：视窗内某个页面的索引。<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[2].f32**：页面相对于Swiper主轴起始位置（selectedIndex对应页面的起始位置）的移动比例。<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[3].f32**：主轴方向上页面的长度。 | 
| NODE_SCROLL_EVENT_ON_SCROLL  | 定义ARKUI_NODE_SCROLL滚动组件的滚动事件枚举值。<br/>触发该事件的条件 ：<br/>1、滚动组件触发滚动时触发，支持键鼠操作等其他触发滚动的输入设置。<br/>2、通过滚动控制器API接口调用。<br/>3、越界回弹。<br/>事件回调发生时，事件参数[ArkUI_NodeEvent](#arkui_nodeevent)对象中的联合体类型为[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)。<br/>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)中包含2个参数：<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].f32**：表示距离上一次事件触发的X轴增量。<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[1].f32**：表示距离上一次事件触发的Y轴增量。 | 
| NODE_SCROLL_EVENT_ON_SCROLL_FRAME_BEGIN  | 定义ARKUI_NODE_SCROLL滚动组件的滚动帧始事件枚举值。<br/>触发该事件的条件 ：<br/>1、滚动组件触发滚动时触发，包括键鼠操作等其他触发滚动的输入设置。<br/>2、调用控制器接口时不触发。<br/>3、越界回弹不触发。<br/>事件回调发生时，事件参数[ArkUI_NodeEvent](#arkui_nodeevent)对象中的联合体类型为[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)。<br/>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)中包含2个参数：<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].f32**：表示即将发生的滚动量。<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[1].i32**：表示当前滚动状态。<br/>**[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)**中包含1个返回值：<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].f32**：事件处理函数中可根据应用场景计算实际需要的滚动量并存于data[0].f32中，Scroll将按照返回值的实际滚动量进行滚动。 | 
| NODE_SCROLL_EVENT_ON_SCROLL_START  | 定义ARKUI_NODE_SCROLL滚动组件的滚动开始事件枚举值。<br/>触发该事件的条件 ：<br/>1、滚动组件开始滚动时触发，支持键鼠操作等其他触发滚动的输入设置。<br/>2、通过滚动控制器API接口调用后开始，带过渡动效。<br/>事件回调发生时，事件参数[ArkUI_NodeEvent](#arkui_nodeevent)对象中的联合体类型为[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)。<br/>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)中不包含参数。 | 
| NODE_SCROLL_EVENT_ON_SCROLL_STOP  | 定义ARKUI_NODE_SCROLL滚动组件的滚动停止事件枚举值。<br/>触发该事件的条件 ：<br/>1、滚动组件触发滚动后停止，支持键鼠操作等其他触发滚动的输入设置。<br/>2、通过滚动控制器API接口调用后停止，带过渡动效。<br/>事件回调发生时，事件参数[ArkUI_NodeEvent](#arkui_nodeevent)对象中的联合体类型为[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)。<br/>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)中不包含参数。 | 
| NODE_SCROLL_EVENT_ON_SCROLL_EDGE  | 定义ARKUI_NODE_SCROLL滚动组件的滚动边缘事件枚举值。<br/>触发该事件的条件 ：<br/>1、滚动组件滚动到边缘时触发，支持键鼠操作等其他触发滚动的输入设置。<br/>2、通过滚动控制器API接口调用。<br/>3、越界回弹。<br/>事件回调发生时，事件参数[ArkUI_NodeEvent](#arkui_nodeevent)对象中的联合体类型为[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)。<br/>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)中包含1个参数。<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].i32**表示当前碰到的是上下左右哪个边。 | 
| NODE_SCROLL_EVENT_ON_WILL_SCROLL  | 定义ARKUI_NODE_SCROLL滚动组件的滑动前触发事件枚举值。<br/>触发该事件的条件 ：<br/>1、滚动组件滚动到边缘时触发，支持键鼠操作等其他触发滚动的输入设置。<br/>2、通过滚动控制器API接口调用。<br/>3、越界回弹。<br/>事件回调发生时，事件参数[ArkUI_NodeEvent](#arkui_nodeevent)对象中的联合体类型为[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)。<br/>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)中包含2个参数:<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].f32**: 每帧滚动的偏移量，List的内容向上滚动时偏移量为正，向下滚动时偏移量为负.<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[1].f32**: 当前滑动状态. | 
| NODE_REFRESH_STATE_CHANGE  | 定义ARKUI_NODE_REFRESH刷新状态变更触发该事件。<br/>事件回调发生时，事件参数[ArkUI_NodeEvent](#arkui_nodeevent)对象中的联合体类型为[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)。<br/>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)中包含1个参数：<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].i32**：刷新状态。 | 
| NODE_REFRESH_ON_REFRESH  | 定义ARKUI_NODE_REFRESH进入刷新状态时触发该事件。<br/>事件回调发生时，事件参数[ArkUI_NodeEvent](#arkui_nodeevent)对象中的联合体类型为[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)。<br/>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)中不包含参数： | 
| NODE_REFRESH_ON_OFFSET_CHANGE  | 定义ARKUI_NODE_REFRESH下拉距离发生变化时触发该事件。<br/>事件回调发生时，事件参数[ArkUI_NodeEvent](#arkui_nodeevent)对象中的联合体类型为[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)。<br/>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)中包含1个参数：<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].f32**：下拉距离。 | 


### ArkUI_NodeType

```
enum ArkUI_NodeType
```
**描述：**

提供ArkUI在Native侧可创建组件类型。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_NODE_CUSTOM  | 自定义节点。&nbsp;&nbsp; | 
| ARKUI_NODE_TEXT  | 文本。&nbsp;&nbsp; | 
| ARKUI_NODE_SPAN  | 文本段落。&nbsp;&nbsp; | 
| ARKUI_NODE_IMAGE_SPAN  | 文本图片段落。&nbsp;&nbsp; | 
| ARKUI_NODE_IMAGE  | 图片。&nbsp;&nbsp; | 
| ARKUI_NODE_TOGGLE  | 状态开关。&nbsp;&nbsp; | 
| ARKUI_NODE_LOADING_PROGRESS  | 等待图标。&nbsp;&nbsp; | 
| ARKUI_NODE_TEXT_INPUT  | 单行文本输入。&nbsp;&nbsp; | 
| ARKUI_NODE_TEXT_AREA  | 多行文本。&nbsp;&nbsp; | 
| ARKUI_NODE_BUTTON  | 按钮。&nbsp;&nbsp; | 
| ARKUI_NODE_PROGRESS  | 进度条。&nbsp;&nbsp; | 
| ARKUI_NODE_CHECKBOX  | 复选框。&nbsp;&nbsp; | 
| ARKUI_NODE_XCOMPONENT  | XComponent。&nbsp;&nbsp; | 
| ARKUI_NODE_DATE_PICKER  | 日期选择器组件。&nbsp;&nbsp; | 
| ARKUI_NODE_TIME_PICKER  | 时间选择组件。&nbsp;&nbsp; | 
| ARKUI_NODE_TEXT_PICKER  | 滑动选择文本内容的组件。&nbsp;&nbsp; | 
| ARKUI_NODE_CALENDAR_PICKER  | 日历选择器组件。&nbsp;&nbsp; | 
| ARKUI_NODE_SLIDER  | 滑动条组件&nbsp;&nbsp; | 
| ARKUI_NODE_STACK  | 堆叠容器。&nbsp;&nbsp; | 
| ARKUI_NODE_SWIPER  | 翻页容器。&nbsp;&nbsp; | 
| ARKUI_NODE_SCROLL  | 滚动容器。&nbsp;&nbsp; | 
| ARKUI_NODE_LIST  | 列表。&nbsp;&nbsp; | 
| ARKUI_NODE_LIST_ITEM  | 列表项。&nbsp;&nbsp; | 
| ARKUI_NODE_LIST_ITEM_GROUP  | 列表item分组。&nbsp;&nbsp; | 
| ARKUI_NODE_COLUMN  | 垂直布局容器。&nbsp;&nbsp; | 
| ARKUI_NODE_ROW  | 水平布局容器。&nbsp;&nbsp; | 
| ARKUI_NODE_FLEX  | 弹性布局容器。&nbsp;&nbsp; | 
| ARKUI_NODE_REFRESH  | 刷新组件。&nbsp;&nbsp; | 
| ARKUI_NODE_WATER_FLOW  | 瀑布流容器。&nbsp;&nbsp; | 


### ArkUI_ObjectFit

```
enum ArkUI_ObjectFit
```
**描述：**

定义image填充效果。 ImageSpanAlignment

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_OBJECT_FIT_CONTAIN  | 保持宽高比进行缩小或者放大，使得图片完全显示在显示边界内。&nbsp;&nbsp; | 
| ARKUI_OBJECT_FIT_COVER  | 保持宽高比进行缩小或者放大，使得图片两边都大于或等于显示边界。&nbsp;&nbsp; | 
| ARKUI_OBJECT_FIT_AUTO  | 自适应显示。&nbsp;&nbsp; | 
| ARKUI_OBJECT_FIT_FILL  | 不保持宽高比进行放大缩小，使得图片充满显示边界。&nbsp;&nbsp; | 
| ARKUI_OBJECT_FIT_SCALE_DOWN  | 保持宽高比显示，图片缩小或者保持不变。&nbsp;&nbsp; | 
| ARKUI_OBJECT_FIT_NONE  | 保持原有尺寸显示。&nbsp;&nbsp; | 


### ArkUI_ProgressType

```
enum ArkUI_ProgressType
```
**描述：**

定义进度条类型枚举值。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_PROGRESS_TYPE_LINEAR  | 线性样式。&nbsp;&nbsp; | 
| ARKUI_PROGRESS_TYPE_RING  | 环形无刻度样式。&nbsp;&nbsp; | 
| ARKUI_PROGRESS_TYPE_ECLIPSE  | 圆形样式。&nbsp;&nbsp; | 
| ARKUI_PROGRESS_TYPE_SCALE_RING  | 唤醒有刻度样式。&nbsp;&nbsp; | 
| ARKUI_PROGRESS_TYPE_CAPSULE  | 胶囊样式。&nbsp;&nbsp; | 

### ArkUI_ScrollBarDisplayMode

```
enum ArkUI_ScrollBarDisplayMode
```
**描述：**

定义滚动条状态枚举值。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_SCROLL_BAR_DISPLAY_MODE_OFF  | 不显示。&nbsp;&nbsp; | 
| ARKUI_SCROLL_BAR_DISPLAY_MODE_AUTO  | 按需显示(触摸时显示，2s后消失)。&nbsp;&nbsp; | 
| ARKUI_SCROLL_BAR_DISPLAY_MODE_ON  | 常驻显示。&nbsp;&nbsp; | 


### ArkUI_ScrollDirection

```
enum ArkUI_ScrollDirection
```
**描述：**

定义Scroll组件排列方向枚举值。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_SCROLL_DIRECTION_VERTICAL  | 仅支持竖直方向滚动。&nbsp;&nbsp; | 
| ARKUI_SCROLL_DIRECTION_HORIZONTAL  | 仅支持水平方向滚动。&nbsp;&nbsp; | 
| ARKUI_SCROLL_DIRECTION_NONE  | 禁止滚动。&nbsp;&nbsp; | 


### ArkUI_ScrollEdge

```
enum ArkUI_ScrollEdge
```
**描述：**

定义滚动到的边缘位置。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_SCROLL_EDGE_TOP  | 竖直方向上边缘。&nbsp;&nbsp; | 
| ARKUI_SCROLL_EDGE_BOTTOM  | 竖直方向下边缘。&nbsp;&nbsp; | 
| ARKUI_SCROLL_EDGE_START  | 水平方向起始位置。&nbsp;&nbsp; | 
| ARKUI_SCROLL_EDGE_END  | 水平方向末尾位置。&nbsp;&nbsp; | 


### ArkUI_ScrollNestedMode

```
enum ArkUI_ScrollNestedMode
```
**描述：**

定义嵌套滚动选项。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_SCROLL_NESTED_MODE_SELF_ONLY  | 只自身滚动，不与父组件联动。&nbsp;&nbsp; | 
| ARKUI_SCROLL_NESTED_MODE_SELF_FIRST  | 自身先滚动，自身滚动到边缘以后父组件滚动。父组件滚动到边缘以后 如果父组件有边缘效果，则父组件触发边缘效果，否则子组件触发边缘效果。&nbsp;&nbsp; | 
| ARKUI_SCROLL_NESTED_MODE_PARENT_FIRST  | 父组件先滚动，父组件滚动到边缘以后自身滚动。 身滚动到边缘后，如果有边缘效果，会触发自身的边缘效果，否则触发父组件的边缘效果。&nbsp;&nbsp; | 
| ARKUI_SCROLL_NESTED_MODE_PARALLEL  | 自身和父组件同时滚动，自身和父组件都到达边缘以后 如果自身有边缘效果，则自身触发边缘效果，否则父组件触发边缘效果。&nbsp;&nbsp; | 


### ArkUI_ScrollSnapAlign

```
enum ArkUI_ScrollSnapAlign
```
**描述：**

定义列表项滚动结束对齐效果枚举值。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_SCROLL_SNAP_ALIGN_NONE  | 默认无项目滚动对齐效果。&nbsp;&nbsp; | 
| ARKUI_SCROLL_SNAP_ALIGN_START  | 视图中的第一项将在列表的开头对齐。&nbsp;&nbsp; | 
| ARKUI_SCROLL_SNAP_ALIGN_CENTER  | 视图中的中间项将在列表中心对齐。&nbsp;&nbsp; | 
| ARKUI_SCROLL_SNAP_ALIGN_END  | 视图中的最后一项将在列表末尾对齐。&nbsp;&nbsp; | 


### ArkUI_ShadowStyle

```
enum ArkUI_ShadowStyle
```
**描述：**

阴影效果枚举值。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_SHADOW_STYLE_OUTER_DEFAULT_XS  | 超小阴影。&nbsp;&nbsp; | 
| ARKUI_SHADOW_STYLE_OUTER_DEFAULT_SM  | 小阴影。&nbsp;&nbsp; | 
| ARKUI_SHADOW_STYLE_OUTER_DEFAULT_MD  | 中阴影。&nbsp;&nbsp; | 
| ARKUI_SHADOW_STYLE_OUTER_DEFAULT_LG  | 大阴影。&nbsp;&nbsp; | 
| ARKUI_SHADOW_STYLE_OUTER_FLOATING_SM  | 浮动小阴影。&nbsp;&nbsp; | 
| ARKUI_SHADOW_STYLE_OUTER_FLOATING_MD  | 浮动中阴影。&nbsp;&nbsp; | 


### ArkUI_ShadowType

```
enum ArkUI_ShadowType
```
**描述：**

定义阴影类型枚举值。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_SHADOW_TYPE_COLOR  | 颜色。&nbsp;&nbsp; | 
| ARKUI_SHADOW_TYPE_BLUR  | 模糊。&nbsp;&nbsp; | 


### ArkUI_ShapeType

```
enum ArkUI_ShapeType
```
**描述：**

自定义形状。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_SHAPE_TYPE_RECTANGLE  | 矩形类型。&nbsp;&nbsp; | 
| ARKUI_SHAPE_TYPE_CIRCLE  | 圆形类型。&nbsp;&nbsp; | 
| ARKUI_SHAPE_TYPE_ELLIPSE  | 椭圆形类型。&nbsp;&nbsp; | 
| ARKUI_SHAPE_TYPE_PATH  | 路径类型。&nbsp;&nbsp; | 


### ArkUI_SliderBlockStyle

```
enum ArkUI_SliderBlockStyle
```
**描述：**

定义滑块形状。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_SLIDER_BLOCK_STYLE_DEFAULT  | 使用默认滑块（圆形）。&nbsp;&nbsp; | 
| ARKUI_SLIDER_BLOCK_STYLE_IMAGE  | 使用图片资源作为滑块。&nbsp;&nbsp; | 
| ARKUI_SLIDER_BLOCK_STYLE_SHAPE  | 使用自定义形状作为滑块。&nbsp;&nbsp; | 


### ArkUI_SliderDirection

```
enum ArkUI_SliderDirection
```
**描述：**

定义滑动条滑动方向。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_SLIDER_DIRECTION_VERTICAL  | 方向为纵向。&nbsp;&nbsp; | 
| ARKUI_SLIDER_DIRECTION_HORIZONTAL  | 方向为横向。&nbsp;&nbsp; | 


### ArkUI_SliderStyle

```
enum ArkUI_SliderStyle
```
**描述：**

定义滑块与滑轨显示样式。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_SLIDER_STYLE_OUT_SET  | 滑块在滑轨上。&nbsp;&nbsp; | 
| ARKUI_SLIDER_STYLE_IN_SET  | 滑块在滑轨内。&nbsp;&nbsp; | 


### ArkUI_StickyStyle

```
enum ArkUI_StickyStyle
```
**描述：**

定义列表是否吸顶和吸底枚举值。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_STICKY_STYLE_NONE  | ListItemGroup的header不吸顶，footer不吸底。&nbsp;&nbsp; | 
| ARKUI_STICKY_STYLE_HEADER  | ListItemGroup的header吸顶，footer不吸底。&nbsp;&nbsp; | 
| ARKUI_STICKY_STYLE_FOOTER  | ListItemGroup的footer吸底，header不吸顶。&nbsp;&nbsp; | 
| ARKUI_STICKY_STYLE_BOTH  | ListItemGroup的footer吸底，header吸顶。&nbsp;&nbsp; | 

### ArkUI_SwiperDisplayModeType

```
enum ArkUI_SwiperDisplayModeType
```
**描述：**

定义 Swiper 组件的主轴方向上元素排列的模式。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_SWIPER_DISPLAY_MODE_STRETCH  | Swiper滑动一页的宽度为Swiper组件自身的宽度。&nbsp;&nbsp; | 
| ARKUI_SWIPER_DISPLAY_MODE_AUTO_LINEAR  | Swiper滑动一页的宽度为视窗内最左侧子组件的宽度。&nbsp;&nbsp; | 

### ArkUI_SwiperArrow

```
enum ArkUI_SwiperArrow
```
**描述：**

Swiper导航点箭头枚举值。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_SWIPER_ARROW_HIDE  | 不显示swiper中导航点箭头。&nbsp;&nbsp; | 
| ARKUI_SWIPER_ARROW_SHOW  | 显示swiper中导航点箭头。&nbsp;&nbsp; | 
| ARKUI_SWIPER_ARROW_SHOW_ON_HOVER  | 在hover状态下显示swiper中导航点箭头。&nbsp;&nbsp; | 


### ArkUI_TextAlignment

```
enum ArkUI_TextAlignment
```
**描述：**

定义字体水平对齐样式枚举值。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_TEXT_ALIGNMENT_START  | 水平对齐首部。&nbsp;&nbsp; | 
| ARKUI_TEXT_ALIGNMENT_CENTER  | 水平居中对齐。&nbsp;&nbsp; | 
| ARKUI_TEXT_ALIGNMENT_END  | 水平对齐尾部。&nbsp;&nbsp; | 
| ARKUI_TEXT_ALIGNMENT_JUSTIFY  | 双端对齐。&nbsp;&nbsp; | 


### ArkUI_TextAreaType

```
enum ArkUI_TextAreaType
```
**描述：**

定义多行文本输入法类型枚举值。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_TEXTAREA_TYPE_NORMAL  | 基本输入模式。&nbsp;&nbsp; | 
| ARKUI_TEXTAREA_TYPE_NUMBER  | 纯数字模式。&nbsp;&nbsp; | 
| ARKUI_TEXTAREA_TYPE_PHONE_NUMBER  | 电话号码输入模式。&nbsp;&nbsp; | 
| ARKUI_TEXTAREA_TYPE_EMAIL  | 邮箱地址输入模式。&nbsp;&nbsp; | 


### ArkUI_TextCase

```
enum ArkUI_TextCase
```
**描述：**

定义文本大小写枚举值。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_TEXT_CASE_NORMAL  | 保持原有大小写。&nbsp;&nbsp; | 
| ARKUI_TEXT_CASE_LOWER  | 文本全小写。&nbsp;&nbsp; | 
| ARKUI_TEXT_CASE_UPPER  | 文本全大写。&nbsp;&nbsp; | 


### ArkUI_TextCopyOptions

```
enum ArkUI_TextCopyOptions
```
**描述：**

定义组件支持设置文本是否可复制粘贴。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_TEXT_COPY_OPTIONS_NONE  | 不支持复制。&nbsp;&nbsp; | 
| ARKUI_TEXT_COPY_OPTIONS_IN_APP  | 支持应用内复制。&nbsp;&nbsp; | 
| ARKUI_TEXT_COPY_OPTIONS_LOCAL_DEVICE  | 支持设备内复制。&nbsp;&nbsp; | 
| ARKUI_TEXT_COPY_OPTIONS_CROSS_DEVICE  | 支持跨设备复制。&nbsp;&nbsp; | 


### ArkUI_TextDecorationType

```
enum ArkUI_TextDecorationType
```
**描述：**

定义装饰线样式枚举值。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_TEXT_DECORATION_TYPE_NONE  | 不使用装饰线。&nbsp;&nbsp; | 
| ARKUI_TEXT_DECORATION_TYPE_UNDERLINE  | 文字下划线修饰。&nbsp;&nbsp; | 
| ARKUI_TEXT_DECORATION_TYPE_OVERLINE  | 文字上划线修饰。&nbsp;&nbsp; | 
| ARKUI_TEXT_DECORATION_TYPE_LINE_THROUGH  | 穿过文本的修饰线。&nbsp;&nbsp; | 


### ArkUI_TextHeightAdaptivePolicy

```
enum ArkUI_TextHeightAdaptivePolicy
```
**描述：**

定义文本自适应高度的方式。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_TEXT_HEIGHT_ADAPTIVE_POLICY_MAX_LINES_FIRST  | 设置文本高度自适应方式为以MaxLines优先。&nbsp;&nbsp; | 
| ARKUI_TEXT_HEIGHT_ADAPTIVE_POLICY_MIN_FONT_SIZE_FIRST  | 设置文本高度自适应方式为以缩小字体优先。&nbsp;&nbsp; | 
| ARKUI_TEXT_HEIGHT_ADAPTIVE_POLICY_LAYOUT_CONSTRAINT_FIRST  | 设置文本高度自适应方式为以布局约束（高度）优先。&nbsp;&nbsp; | 


### ArkUI_TextInputType

```
enum ArkUI_TextInputType
```
**描述：**

定义单行文本输入法类型枚举值。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_TEXTINPUT_TYPE_NORMAL  | 基本输入模式。&nbsp;&nbsp; | 
| ARKUI_TEXTINPUT_TYPE_NUMBER  | 纯数字模式。&nbsp;&nbsp; | 
| ARKUI_TEXTINPUT_TYPE_PHONE_NUMBER  | 电话号码输入模式。&nbsp;&nbsp; | 
| ARKUI_TEXTINPUT_TYPE_EMAIL  | 邮箱地址输入模式。&nbsp;&nbsp; | 
| ARKUI_TEXTINPUT_TYPE_PASSWORD  | 密码输入模式。&nbsp;&nbsp; | 
| ARKUI_TEXTINPUT_TYPE_NUMBER_PASSWORD  | 纯数字密码输入模式。&nbsp;&nbsp; | 
| ARKUI_TEXTINPUT_TYPE_SCREEN_LOCK_PASSWORD  | 锁屏应用密码输入模式。&nbsp;&nbsp; | 
| ARKUI_TEXTINPUT_TYPE_USER_NAME  | 用户名输入模式。&nbsp;&nbsp; | 
| ARKUI_TEXTINPUT_TYPE_NEW_PASSWORD  | 新密码输入模式。&nbsp;&nbsp; | 
| ARKUI_TEXTINPUT_TYPE_NUMBER_DECIMAL  | 带小数点的数字输入模式。&nbsp;&nbsp; | 


### ArkUI_TextOverflow

```
enum ArkUI_TextOverflow
```
**描述：**

定义文本超长时的显示方式。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_TEXT_OVERFLOW_NONE  | 文本超长时不裁剪显示。&nbsp;&nbsp; | 
| ARKUI_TEXT_OVERFLOW_CLIP  | 文本超长时进行裁剪显示。&nbsp;&nbsp; | 
| ARKUI_TEXT_OVERFLOW_ELLIPSIS  | 文本超长时显示不下的文本用省略号代替。&nbsp;&nbsp; | 
| ARKUI_TEXT_OVERFLOW_MARQUEE  | 文本超长时以跑马灯的方式展示。&nbsp;&nbsp; | 


### ArkUI_TextPickerRangeType

```
enum ArkUI_TextPickerRangeType
```
**描述：**

定义滑动选择文本选择器输入类型。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_TEXTPICKER_RANGETYPE_SINGLE  | 单列数据选择器。&nbsp;&nbsp; | 
| ARKUI_TEXTPICKER_RANGETYPE_MULTI  | 多列数据选择器。&nbsp;&nbsp; | 
| ARKUI_TEXTPICKER_RANGETYPE_RANGE_CONTENT  | 支持图片资源的单列数据选择器。&nbsp;&nbsp; | 
| ARKUI_TEXTPICKER_RANGETYPE_CASCADE_RANGE_CONTENT  | 支持联动的多列数据选择器。&nbsp;&nbsp; | 


### ArkUI_TransitionEdge

```
enum ArkUI_TransitionEdge
```
**描述：**

定义转场从边缘滑入和滑出的效果。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_TRANSITION_EDGE_TOP  | 窗口的上边缘。&nbsp;&nbsp; | 
| ARKUI_TRANSITION_EDGE_BOTTOM  | 窗口的下边缘。&nbsp;&nbsp; | 
| ARKUI_TRANSITION_EDGE_START  | 窗口的左边缘。&nbsp;&nbsp; | 
| ARKUI_TRANSITION_EDGE_END  | 窗口的右边缘。&nbsp;&nbsp; | 


### ArkUI_VerticalAlignment

```
enum ArkUI_VerticalAlignment
```
**描述：**

定义垂直对齐方式。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_VERTICAL_ALIGNMENT_TOP  | 顶部对齐。&nbsp;&nbsp; | 
| ARKUI_VERTICAL_ALIGNMENT_CENTER  | 居中对齐，默认对齐方式。&nbsp;&nbsp; | 
| ARKUI_VERTICAL_ALIGNMENT_BOTTOM  | 底部对齐。&nbsp;&nbsp; | 


### ArkUI_Visibility

```
enum ArkUI_Visibility
```
**描述：**

控制组件的显隐枚举值。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_VISIBILITY_VISIBLE  | 显示。&nbsp;&nbsp; | 
| ARKUI_VISIBILITY_HIDDEN  | 隐藏，但参与布局进行占位。&nbsp;&nbsp; | 
| ARKUI_VISIBILITY_NONE  | 隐藏，但不参与布局，不进行占位。&nbsp;&nbsp; | 


### ArkUI_WordBreak

```
enum ArkUI_WordBreak
```
**描述：**

定义文本断行规则。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_WORD_BREAK_NORMAL  | CJK(中文、日文、韩文)文本可以在任意2个字符间断行，而Non-CJK文本（如英文等）只能在空白符处断行。&nbsp;&nbsp; | 
| ARKUI_WORD_BREAK_BREAK_ALL  | 对于Non-CJK的文本，可在任意2个字符间断行。CJK(中文、日文、韩文)文本可以在任意2个字符间断行。&nbsp;&nbsp; | 
| ARKUI_WORD_BREAK_BREAK_WORD  | 对于Non-CJK的文本可在任意2个字符间断行，一行文本中有断行破发点（如空白符）时，优先按破发点换行。 CJK(中文、日文、韩文)文本可以在任意2个字符间断行&nbsp;&nbsp; | 


### ArkUI_XComponentType

```
enum ArkUI_XComponentType
```
**描述：**

定义XComponent类型枚举值。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_XCOMPONENT_TYPE_SURFACE  | 用于EGL/OpenGLES和媒体数据写入，开发者定制绘制内容单独显示在屏幕上。&nbsp;&nbsp; | 
| ARKUI_XCOMPONENT_TYPE_TEXTURE  | 用于EGL/OpenGLES和媒体数据写入，开发者定制绘制内容和XComponent组件内容合成后展示在屏幕上。&nbsp;&nbsp; | 


### HitTestMode

```
enum HitTestMode
```
**描述：**

定义触摸测试类型的枚举值。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| HTMDEFAULT  | 默认触摸测试效果，自身和子节点都响应触摸测试，但会阻塞兄弟节点的触摸测试。&nbsp;&nbsp; | 
| HTMBLOCK  | 自身响应触摸测试，阻塞子节点和兄弟节点的触摸测试。&nbsp;&nbsp; | 
| HTMTRANSPARENT  | 自身和子节点都响应触摸测试，不会阻塞兄弟节点的触摸测试。&nbsp;&nbsp; | 
| HTMNONE  | 自身不响应触摸测试，不会阻塞子节点和兄弟节点的触摸测试。&nbsp;&nbsp; | 


## 函数说明


### OH_ArkUI_DrawableDescriptor_CreateFromAnimatedPixelMap()

```
ArkUI_DrawableDescriptor* OH_ArkUI_DrawableDescriptor_CreateFromAnimatedPixelMap (OH_PixelmapNativeHandle * array, int32_t size )
```
**描述**
使用 PixelMap 图片数组创建DrawbleDescriptor 对象。

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| array | PixelMap 图片数组对象指针。  |
| size | PixelMap 图片数组大小。  |

**返回：**

返回 DrawableDescriptor 对象指针。


### OH_ArkUI_DrawableDescriptor_CreateFromPixelMap()

```
ArkUI_DrawableDescriptor* OH_ArkUI_DrawableDescriptor_CreateFromPixelMap (OH_PixelmapNativeHandle pixelMap)
```
**描述**
使用 PixelMap 创建 DrawbleDescriptor 对象。

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| pixelMap | PixelMap 对象指针。  |

**返回：**

返回 DrawableDescriptor 对象指针。


### OH_ArkUI_DrawableDescriptor_Dispose()

```
void OH_ArkUI_DrawableDescriptor_Dispose (ArkUI_DrawableDescriptor * drawableDescriptor)
```
**描述**
销毁 DrawbleDescriptor 对象指针。

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| drawableDescriptor | DrawbleDescriptor 对象指针。  |


### OH_ArkUI_DrawableDescriptor_GetAnimatedPixelMapArray()

```
OH_PixelmapNativeHandle* OH_ArkUI_DrawableDescriptor_GetAnimatedPixelMapArray (ArkUI_DrawableDescriptor * drawableDescriptor)
```
**描述**
获取用于播放动画的 PixelMap 图片数组数据。

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| drawableDescriptor | DrawbleDescriptor 对象指针。  |

**返回：**

PixelMap 图片数组指针。


### OH_ArkUI_DrawableDescriptor_GetAnimatedPixelMapArraySize()

```
int32_t OH_ArkUI_DrawableDescriptor_GetAnimatedPixelMapArraySize (ArkUI_DrawableDescriptor * drawableDescriptor)
```
**描述**
获取用于播放动画的 PixelMap 图片数组数据。

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| drawableDescriptor | DrawbleDescriptor 对象指针。  |

**返回：**

PixelMap 图片数组大小。


### OH_ArkUI_DrawableDescriptor_GetAnimationDuration()

```
int32_t OH_ArkUI_DrawableDescriptor_GetAnimationDuration (ArkUI_DrawableDescriptor * drawableDescriptor)
```
**描述**
获取 PixelMap 图片数组播放总时长。

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| drawableDescriptor | DrawbleDescriptor 对象指针。  |

**返回：**

播放总时长，单位毫秒。


### OH_ArkUI_DrawableDescriptor_GetAnimationIteration()

```
int32_t OH_ArkUI_DrawableDescriptor_GetAnimationIteration (ArkUI_DrawableDescriptor * drawableDescriptor)
```
**描述**
获取 PixelMap 图片数组播放次数。

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| drawableDescriptor | DrawbleDescriptor 对象指针。  |

**返回：**

播放次数。


### OH_ArkUI_DrawableDescriptor_GetStaticPixelMap()

```
OH_PixelmapNativeHandle OH_ArkUI_DrawableDescriptor_GetStaticPixelMap (ArkUI_DrawableDescriptor * drawableDescriptor)
```
**描述**
获取 PixelMap 图片对象指针。

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| drawableDescriptor | DrawbleDescriptor 对象指针。  |

**返回：**

PixelMap 对象指针。


### OH_ArkUI_DrawableDescriptor_SetAnimationDuration()

```
void OH_ArkUI_DrawableDescriptor_SetAnimationDuration (ArkUI_DrawableDescriptor * drawableDescriptor, int32_t duration )
```
**描述**
设置 PixelMap 图片数组播放总时长。

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| drawableDescriptor | DrawbleDescriptor 对象指针。  |
| duration | 播放总时长，单位毫秒。  |


### OH_ArkUI_DrawableDescriptor_SetAnimationIteration()

```
void OH_ArkUI_DrawableDescriptor_SetAnimationIteration (ArkUI_DrawableDescriptor * drawableDescriptor, int32_t iteration )
```
**描述**
设置 PixelMap 图片数组播放次数。

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| drawableDescriptor | DrawbleDescriptor 对象指针。  |
| iterations | 播放次数。  |


### OH_ArkUI_ListItemSwipeActionItem_Create()

```
ArkUI_ListItemSwipeActionItem* OH_ArkUI_ListItemSwipeActionItem_Create ()
```
**描述**
创建ListItemSwipeActionItem接口设置的配置项。

**起始版本：** 12

**返回：**

ListItemSwipeActionItem配置项实例。


### OH_ArkUI_ListItemSwipeActionItem_Dispose()

```
void OH_ArkUI_ListItemSwipeActionItem_Dispose (ArkUI_ListItemSwipeActionItem * item)
```
**描述**
销毁ListItemSwipeActionItem实例。

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| item | 要销毁的ListItemSwipeActionItem实例。  |


### OH_ArkUI_ListItemSwipeActionItem_GetActionAreaDistance()

```
float OH_ArkUI_ListItemSwipeActionItem_GetActionAreaDistance (ArkUI_ListItemSwipeActionItem * item)
```
**描述**
获取组件长距离滑动删除距离阈值。

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| item | ListItemSwipeActionItem实例。  |

**返回：**

组件长距离滑动删除距离阈值。异常时返回值：0。


### OH_ArkUI_ListItemSwipeActionItem_SetActionAreaDistance()

```
void OH_ArkUI_ListItemSwipeActionItem_SetActionAreaDistance (ArkUI_ListItemSwipeActionItem * item, float distance )
```
**描述**
设置组件长距离滑动删除距离阈值。

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| item | ListItemSwipeActionItem实例。  |
| distance | 组件长距离滑动删除距离阈值。  |


### OH_ArkUI_ListItemSwipeActionItem_SetContent()

```
void OH_ArkUI_ListItemSwipeActionItem_SetContent (ArkUI_ListItemSwipeActionItem * item, ArkUI_NodeHandle node )
```
**描述**
设置ListItemSwipeActionItem的布局内容。

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| item | ListItemSwipeActionItem实例。  |
| node | 布局信息。  |


### OH_ArkUI_ListItemSwipeActionItem_SetOnAction()

```
void OH_ArkUI_ListItemSwipeActionItem_SetOnAction (ArkUI_ListItemSwipeActionItem * item, void(*)() callback )
```
**描述**
设置组件进入长距删除区后删除ListItem时调用的事件。

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| item | ListItemSwipeActionItem实例。  |
| callback | 回调事件  |


### OH_ArkUI_ListItemSwipeActionItem_SetOnEnterActionArea()

```
void OH_ArkUI_ListItemSwipeActionItem_SetOnEnterActionArea (ArkUI_ListItemSwipeActionItem * item, void(*)() callback )
```
**描述**
设置滑动条目进入删除区域时调用的事件。

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| item | ListItemSwipeActionItem实例。  |
| callback | 回调事件  |


### OH_ArkUI_ListItemSwipeActionItem_SetOnExitActionArea()

```
void OH_ArkUI_ListItemSwipeActionItem_SetOnExitActionArea (ArkUI_ListItemSwipeActionItem * item, void(*)() callback )
```
**描述**
设置滑动条目退出删除区域时调用的事件。

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| item | ListItemSwipeActionItem实例。  |
| callback | 回调事件  |


### OH_ArkUI_ListItemSwipeActionItem_SetOnStateChange()

```
void OH_ArkUI_ListItemSwipeActionItem_SetOnStateChange (ArkUI_ListItemSwipeActionItem * item, void(*)(ArkUI_ListItemSwipeActionState swipeActionState) callback )
```
**描述**
设置列表项滑动状态变化时候触发的事件。

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| item | ListItemSwipeActionItem实例。  |
| callback | 回调事件 swipeActionState 变化后的状态。  |


### OH_ArkUI_ListItemSwipeActionOption_Create()

```
ArkUI_ListItemSwipeActionOption* OH_ArkUI_ListItemSwipeActionOption_Create ()
```
**描述**
创建ListItemSwipeActionOption接口设置的配置项。

**起始版本：** 12

**返回：**

ListItemSwipeActionOption配置项实例。


### OH_ArkUI_ListItemSwipeActionOption_Dispose()

```
void OH_ArkUI_ListItemSwipeActionOption_Dispose (ArkUI_ListItemSwipeActionOption * option)
```
**描述**
销毁ListItemSwipeActionOption实例。

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| option | 要销毁的ListItemSwipeActionOption实例。  |


### OH_ArkUI_ListItemSwipeActionOption_GetEdgeEffect()

```
int32_t OH_ArkUI_ListItemSwipeActionOption_GetEdgeEffect (ArkUI_ListItemSwipeActionOption * option)
```
**描述**
获取滑动效果。

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| option | ListItemSwipeActionItem实例。  |

**返回：**

滑动效果。默认返回值：ARKUI_LIST_ITEM_SWIPE_EDGE_EFFECT_SPRING。


### OH_ArkUI_ListItemSwipeActionOption_SetEdgeEffect()

```
void OH_ArkUI_ListItemSwipeActionOption_SetEdgeEffect (ArkUI_ListItemSwipeActionOption * option, ArkUI_ListItemSwipeEdgeEffect edgeEffect )
```
**描述**
设置滑动效果。

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| option | ListItemSwipeActionItem实例。  |
| edgeEffect | 滑动效果。  |


### OH_ArkUI_ListItemSwipeActionOption_SetEnd()

```
void OH_ArkUI_ListItemSwipeActionOption_SetEnd (ArkUI_ListItemSwipeActionOption * option, ArkUI_ListItemSwipeActionItem * item )
```
**描述**
设置ListItemSwipeActionItem的右侧（垂直布局）或下方（横向布局）布局内容。

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| option | ListItemSwipeActionItem实例。  |
| builder | 布局信息。  |


### OH_ArkUI_ListItemSwipeActionOption_SetOnOffsetChange()

```
void OH_ArkUI_ListItemSwipeActionOption_SetOnOffsetChange (ArkUI_ListItemSwipeActionOption * option, void(*)(float offset) callback )
```
**描述**
滑动操作偏移量更改时调用的事件。

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| option | ListItemSwipeActionItem实例。  |
| callback | 回调事件 offset 滑动偏移量。  |


### OH_ArkUI_ListItemSwipeActionOption_SetStart()

```
void OH_ArkUI_ListItemSwipeActionOption_SetStart (ArkUI_ListItemSwipeActionOption * option, ArkUI_ListItemSwipeActionItem * item )
```
**描述**
设置ListItemSwipeActionItem的左侧（垂直布局）或上方（横向布局）布局内容。

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| option | ListItemSwipeActionItem实例。  |
| builder | 布局信息。  |


### OH_ArkUI_GetDrawableDescriptorFromNapiValue()

```
int32_t OH_ArkUI_GetDrawableDescriptorFromNapiValue (napi_env env, napi_value value, ArkUI_DrawableDescriptor ** drawableDescriptor )
```
**描述：**

将ArkTS侧创建的DrawableDescriptor对象映射到native侧的ArkUI_DrawableDescriptor。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| env | napi的环境指针。  | 
| value | ArkTS侧创建的DrawableDescriptor对象。  | 
| drawableDescriptor | 接受ArkUI_DrawableDescriptor指针的对象  | 

**返回：**

0 - 成功。
401 - 函数参数异常。


### OH_ArkUI_GetDrawableDescriptorFromResourceNapiValue()

```
int32_t OH_ArkUI_GetDrawableDescriptorFromResourceNapiValue (napi_env env, napi_value value, ArkUI_DrawableDescriptor ** drawableDescriptor )
```
**描述：**

将ArkTS侧创建的$r资源对象映射到native侧的ArkUI_DrawableDescriptor。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| env | napi的环境指针。  | 
| value | ArkTS侧创建的$r资源对象。  | 
| drawableDescriptor | 接受ArkUI_DrawableDescriptor指针的对象  | 

**返回：**

0 - 成功。
401 - 函数参数异常。

### OH_ArkUI_WaterFlowSectionOption_RegisterGetItemMainSizeCallbackByIndex()

```
void OH_ArkUI_WaterFlowSectionOption_RegisterGetItemMainSizeCallbackByIndex (ArkUI_WaterFlowSectionOption * option, int32_t index, float(*)(int32_t itemIndex) callback )
```
**描述：**

通过FlowItem分组配置信息根据flowItemIndex获取指定Item的主轴大小。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| option | FlowItem分组配置信息。  | 
| index | FlowItem索引值。  | 
| callback | 根据index获取指定Item的主轴大小。  | 

### OH_ArkUI_WaterFlowSectionOption_GetSize()

```
int32_t OH_ArkUI_WaterFlowSectionOption_GetSize (ArkUI_WaterFlowSectionOption * option)
```
**描述：**

设置FlowItem分组配置信息数组长度。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| option | FlowItem分组配置信息。  | 

**返回：**

数组长度。如果返回-1，则返回失败。失败的原因可能是option参数异常，如空指针。

### OH_ArkUI_AnimateOption_Create()

```
ArkUI_AnimateOption* OH_ArkUI_AnimateOption_Create ()
```
**描述**
创建动画效果参数。

**起始版本：** 12

**返回：**

新的动画效果参数指针。


### OH_ArkUI_AnimateOption_Dispose()

```
void OH_ArkUI_AnimateOption_Dispose (ArkUI_AnimateOption * option)
```
**描述**
销毁动画效果参数指针。

**起始版本：** 12


### OH_ArkUI_AnimateOption_GetCurve()

```
ArkUI_AnimationCurve OH_ArkUI_AnimateOption_GetCurve (ArkUI_AnimateOption * option)
```
**描述**
获取动画曲线。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| option | 动画效果参数。  | 

**返回：**

动画曲线。


### OH_ArkUI_AnimateOption_GetDelay()

```
uint32_t OH_ArkUI_AnimateOption_GetDelay (ArkUI_AnimateOption * option)
```
**描述**
获取动画延迟播放时间，单位为ms(毫秒)。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| option | 动画效果参数。  | 

**返回：**

动画延迟播放时间。


### OH_ArkUI_AnimateOption_GetDuration()

```
uint32_t OH_ArkUI_AnimateOption_GetDuration (ArkUI_AnimateOption * option)
```
**描述**
获取动画持续时间，单位为ms(毫秒)。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| option | 动画效果参数。  | 

**返回：**

持续时间。


### OH_ArkUI_AnimateOption_GetExpectedFrameRateRange()

```
ArkUI_ExpectedFrameRateRange* OH_ArkUI_AnimateOption_GetExpectedFrameRateRange (ArkUI_AnimateOption * option)
```
**描述**
获取动画的期望帧率。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| option | 动画效果参数。  | 

**返回：**

动画的期望帧率。


### OH_ArkUI_AnimateOption_GetIterations()

```
uint32_t OH_ArkUI_AnimateOption_GetIterations (ArkUI_AnimateOption * option)
```
**描述**
获取动画播放次数。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| option | 动画效果参数。  | 

**返回：**

动画播放次数。


### OH_ArkUI_AnimateOption_GetPlayMode()

```
ArkUI_AnimationPlayMode OH_ArkUI_AnimateOption_GetPlayMode (ArkUI_AnimateOption * option)
```
**描述**
获取动画播放模式。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| option | 动画效果参数。  | 

**返回：**

动画播放模式。
### OH_ArkUI_AnimateOption_GetTempo()

```
float OH_ArkUI_AnimateOption_GetTempo (ArkUI_AnimateOption * option)
```
**描述**
获取动画播放速度。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| option | 动画效果参数。  | 

**返回：**

动画播放速度。


### OH_ArkUI_AnimateOption_SetCurve()

```
void OH_ArkUI_AnimateOption_SetCurve (ArkUI_AnimateOption * option, ArkUI_AnimationCurve value )
```
**描述**
设置动画曲线。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| option | 动画效果参数。  | 
| value | 动画曲线。  | 


### OH_ArkUI_AnimateOption_SetDelay()

```
void OH_ArkUI_AnimateOption_SetDelay (ArkUI_AnimateOption * option, uint32_t value )
```
**描述**
设置动画延迟播放时间。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| option | 动画效果参数。  | 
| value | 动画延迟播放时间。  | 


### OH_ArkUI_AnimateOption_SetDuration()

```
void OH_ArkUI_AnimateOption_SetDuration (ArkUI_AnimateOption * option, uint32_t value )
```
**描述**
设置动画持续时间。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| option | 动画效果参数。  | 
| value | 持续时间，单位为ms(毫秒)。  | 


### OH_ArkUI_AnimateOption_SetExpectedFrameRateRange()

```
void OH_ArkUI_AnimateOption_SetExpectedFrameRateRange (ArkUI_AnimateOption * option, ArkUI_ExpectedFrameRateRange * value )
```
**描述**
设置动画的期望帧率。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| option | 动画效果参数。  | 
| value | 动画的期望帧率。  | 


### OH_ArkUI_AnimateOption_SetIterations()

```
void OH_ArkUI_AnimateOption_SetIterations (ArkUI_AnimateOption * option, uint32_t value )
```
**描述**
设置动画播放次数。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| option | 动画效果参数。  | 
| value | 动画播放次数。  | 


### OH_ArkUI_AnimateOption_SetPlayMode()

```
void OH_ArkUI_AnimateOption_SetPlayMode (ArkUI_AnimateOption * option, ArkUI_AnimationPlayMode value )
```
**描述**
设置动画播放模式。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| option | 动画效果参数。  | 
| value | 动画播放模式。  | 


### OH_ArkUI_AnimateOption_SetTempo()

```
void OH_ArkUI_AnimateOption_SetTempo (ArkUI_AnimateOption * option, float value )
```
**描述**
设置动画播放速度。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| option | 动画效果参数。  | 
| value | 动画播放速度。  | 


### OH_ArkUI_DrawContext_GetCanvas()

```
void* OH_ArkUI_DrawContext_GetCanvas (ArkUI_DrawContext * context)
```
**描述：**

获取绘制canvas指针，可以转换为图形库的OH_Drawing_Canvas指针进行绘制。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| context | 绘制上下文。  | 

**返回：**

用于绘制的canvas指针。


### OH_ArkUI_DrawContext_GetSize()

```
ArkUI_IntSize OH_ArkUI_DrawContext_GetSize (ArkUI_DrawContext * context)
```
**描述：**

获取可绘制区域大小。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| context | 绘制上下文。  | 

**返回：**

可绘制区域大小。


### OH_ArkUI_GestureEvent_GetActionType()

```
ArkUI_GestureEventActionType OH_ArkUI_GestureEvent_GetActionType (const ArkUI_GestureEvent * event)
```
**描述：**

返回手势事件类型。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 手势事件。  | 

**返回：**

手势事件类型。


### OH_ArkUI_GestureEvent_GetRawInputEvent()

```
const ArkUI_UIInputEvent* OH_ArkUI_GestureEvent_GetRawInputEvent (const ArkUI_GestureEvent * event)
```
**描述：**

返回手势输入。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 手势事件。  | 

**返回：**

手势事件的原始输入事件。


### OH_ArkUI_GestureInterruptInfo_GetGestureEvent()

```
ArkUI_GestureEvent* OH_ArkUI_GestureInterruptInfo_GetGestureEvent (const ArkUI_GestureInterruptInfo * event)
```
**描述：**

返回打断的手势事件数据。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 打断回调事件。  | 

**返回：**

打断的手势事件数据。


### OH_ArkUI_GestureInterruptInfo_GetRecognizer()

```
ArkUI_GestureRecognizer* OH_ArkUI_GestureInterruptInfo_GetRecognizer (const ArkUI_GestureInterruptInfo * event)
```
**描述：**

返回被打断的手势指针。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 打断回调事件。  | 

**返回：**

被打断的手势指针。


### OH_ArkUI_GestureInterruptInfo_GetSystemFlag()

```
bool OH_ArkUI_GestureInterruptInfo_GetSystemFlag (const ArkUI_GestureInterruptInfo * event)
```
**描述：**

判断是否组件内置手势。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 手势打断回调事件。  | 

**返回：**

true: 系统内置手势； false: 非系统内置手势。

### OH_ArkUI_GetContextFromNapiValue()

```
int32_t OH_ArkUI_GetContextFromNapiValue (napi_env env, napi_value value, ArkUI_ContextHandle * context )
```
**描述**
获取ArkTS侧创建的UIContext对象映射到native侧的ArkUI_ContextHandle。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| env | napi的环境指针。  | 
| value | ArkTS侧创建的context对象。  | 
| context | ArkUI_ContextHandle指针。  | 

**返回：**

0 - 成功。 401 - 函数参数异常。


### OH_ArkUI_GetNodeHandleFromNapiValue()

```
int32_t OH_ArkUI_GetNodeHandleFromNapiValue (napi_env env, napi_value frameNode, ArkUI_NodeHandle * handle )
```
**描述：**

获取ArkTS侧创建的FrameNode节点对象映射到native侧的ArkUI_NodeHandle。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| env | napi的环境指针。  | 
| frameNode | ArkTS侧创建的FrameNode对象。  | 
| handle | ArkUI_NodeHandle指针。  | 

**返回：**

0 - 成功。 401 - 函数参数异常。


### OH_ArkUI_LayoutConstraint_Copy()

```
ArkUI_LayoutConstraint* OH_ArkUI_LayoutConstraint_Copy (const ArkUI_LayoutConstraint * Constraint)
```
**描述：**

约束尺寸深拷贝。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| Constraint | 约束尺寸。  | 

**返回：**

新的约束尺寸指针。


### OH_ArkUI_LayoutConstraint_Create()

```
ArkUI_LayoutConstraint* OH_ArkUI_LayoutConstraint_Create ()
```
**描述：**

创建约束尺寸。

**起始版本：** 12


### OH_ArkUI_LayoutConstraint_Dispose()

```
void* OH_ArkUI_LayoutConstraint_Dispose (ArkUI_LayoutConstraint * Constraint)
```
**描述：**

销毁约束尺寸指针。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| Constraint | 约束尺寸。  | 


### OH_ArkUI_LayoutConstraint_GetMaxHeight()

```
int32_t OH_ArkUI_LayoutConstraint_GetMaxHeight (const ArkUI_LayoutConstraint * Constraint)
```
**描述：**

通过约束尺寸获取最大高度，单位为px。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| Constraint | 约束尺寸。  | 

**返回：**

最大高度。


### OH_ArkUI_LayoutConstraint_GetMaxWidth()

```
int32_t OH_ArkUI_LayoutConstraint_GetMaxWidth (const ArkUI_LayoutConstraint * Constraint)
```
**描述：**

通过约束尺寸获取最大宽度，单位为px。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| Constraint | 约束尺寸。  | 

**返回：**

最大宽度。


### OH_ArkUI_LayoutConstraint_GetMinHeight()

```
int32_t OH_ArkUI_LayoutConstraint_GetMinHeight (const ArkUI_LayoutConstraint * Constraint)
```
**描述：**

通过约束尺寸获取最小高度，单位为px。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| Constraint | 约束尺寸。  | 

**返回：**

最小高度。


### OH_ArkUI_LayoutConstraint_GetMinWidth()

```
int32_t OH_ArkUI_LayoutConstraint_GetMinWidth (const ArkUI_LayoutConstraint * Constraint)
```
**描述：**

通过约束尺寸获取最小宽度，单位为px。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| Constraint | 约束尺寸。  | 

**返回：**

最小宽度。


### OH_ArkUI_LayoutConstraint_GetPercentReferenceHeight()

```
int32_t OH_ArkUI_LayoutConstraint_GetPercentReferenceHeight (const ArkUI_LayoutConstraint * Constraint)
```
**描述：**

通过约束尺寸获取高度百分比基准，单位为px。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| Constraint | 约束尺寸。  | 

**返回：**

高度百分比基准。


### OH_ArkUI_LayoutConstraint_GetPercentReferenceWidth()

```
int32_t OH_ArkUI_LayoutConstraint_GetPercentReferenceWidth (const ArkUI_LayoutConstraint * Constraint)
```
**描述：**

通过约束尺寸获取宽度百分比基准，单位为px。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| Constraint | 约束尺寸。  | 

**返回：**

宽度百分比基准。


### OH_ArkUI_LayoutConstraint_SetMaxHeight()

```
void OH_ArkUI_LayoutConstraint_SetMaxHeight (ArkUI_LayoutConstraint * Constraint, int32_t value )
```
**描述：**

设置最大高度。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| Constraint | 约束尺寸。  | 
| value | 最大高度，单位为px。  | 


### OH_ArkUI_LayoutConstraint_SetMaxWidth()

```
void OH_ArkUI_LayoutConstraint_SetMaxWidth (ArkUI_LayoutConstraint * Constraint, int32_t value )
```
**描述：**

设置最大宽度。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| Constraint | 约束尺寸。  | 
| value | 最大宽度，单位为px。  | 


### OH_ArkUI_LayoutConstraint_SetMinHeight()

```
void OH_ArkUI_LayoutConstraint_SetMinHeight (ArkUI_LayoutConstraint * Constraint, int32_t value )
```
**描述：**

设置最小高度。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| Constraint | 约束尺寸。  | 
| value | 最小高度，单位为px。  | 


### OH_ArkUI_LayoutConstraint_SetMinWidth()

```
void OH_ArkUI_LayoutConstraint_SetMinWidth (ArkUI_LayoutConstraint * Constraint, int32_t value )
```
**描述：**

设置最小宽度。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| Constraint | 约束尺寸。  | 
| value | 最小宽度，单位为px。  | 


### OH_ArkUI_LayoutConstraint_SetPercentReferenceHeight()

```
void OH_ArkUI_LayoutConstraint_SetPercentReferenceHeight (ArkUI_LayoutConstraint * Constraint, int32_t value )
```
**描述：**

设置高度百分比基准。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| Constraint | 约束尺寸。  | 
| value | 高度百分比基准，单位为px。  | 


### OH_ArkUI_LayoutConstraint_SetPercentReferenceWidth()

```
void OH_ArkUI_LayoutConstraint_SetPercentReferenceWidth (ArkUI_LayoutConstraint * Constraint, int32_t value )
```
**描述：**

设置宽度百分比基准。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| Constraint | 约束尺寸。  | 
| value | 宽度百分比基准，单位为px。  | 


### OH_ArkUI_LongPress_GetRepeatCount()

```
int32_t OH_ArkUI_LongPress_GetRepeatCount (const ArkUI_GestureEvent * event)
```
**描述：**

返回长按手势定时触发次数。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 手势事件。  | 

**返回：**

长按手势定时触发次数。


### OH_ArkUI_NodeCustomEvent_GetDrawContextInDraw()

```
ArkUI_DrawContext* OH_ArkUI_NodeCustomEvent_GetDrawContextInDraw (ArkUI_NodeCustomEvent * event)
```
**描述：**

通过自定义组件事件获取绘制上下文。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 自定义组件事件。  | 

**返回：**

绘制上下文。


### OH_ArkUI_NodeCustomEvent_GetEventTargetId()

```
int32_t OH_ArkUI_NodeCustomEvent_GetEventTargetId (ArkUI_NodeCustomEvent * event)
```
**描述：**

通过自定义组件事件获取自定义事件ID。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 自定义组件事件。  | 

**返回：**

自定义事件ID。


### OH_ArkUI_NodeCustomEvent_GetEventType()

```
ArkUI_NodeCustomEventType OH_ArkUI_NodeCustomEvent_GetEventType (ArkUI_NodeCustomEvent * event)
```
**描述：**

通过自定义组件事件获取事件类型。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 自定义组件事件。  | 

**返回：**

组件自定义事件类型。


### OH_ArkUI_NodeCustomEvent_GetLayoutConstraintInMeasure()

```
ArkUI_LayoutConstraint* OH_ArkUI_NodeCustomEvent_GetLayoutConstraintInMeasure (ArkUI_NodeCustomEvent * event)
```
**描述：**

通过自定义组件事件获取测算过程中的约束尺寸。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 自定义组件事件。  | 

**返回：**

约束尺寸指针。


### OH_ArkUI_NodeCustomEvent_GetNodeHandle()

```
ArkUI_NodeHandle OH_ArkUI_NodeCustomEvent_GetNodeHandle (ArkUI_NodeCustomEvent * event)
```
**描述：**

通过自定义组件事件获取组件对象。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 自定义组件事件。  | 

**返回：**

组件对象。


### OH_ArkUI_NodeCustomEvent_GetPositionInLayout()

```
ArkUI_IntOffset OH_ArkUI_NodeCustomEvent_GetPositionInLayout (ArkUI_NodeCustomEvent * event)
```
**描述：**

通过自定义组件事件获取在布局阶段期望自身相对父组件的位置。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 自定义组件事件。  | 

**返回：**

期望自身相对父组件的位置。


### OH_ArkUI_NodeCustomEvent_GetUserData()

```
void* OH_ArkUI_NodeCustomEvent_GetUserData (ArkUI_NodeCustomEvent * event)
```
**描述：**

通过自定义组件事件获取自定义事件参数。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 自定义组件事件。  | 

**返回：**

自定义事件参数。


### OH_ArkUI_NodeEvent_GetEventType()

```
ArkUI_NodeEventType OH_ArkUI_NodeEvent_GetEventType (ArkUI_NodeEvent * event)
```
**描述：**

获取组件事件类型。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 组件事件指针。  | 

**返回：**

ArkUI_NodeEventType 组件事件类型。


### OH_ArkUI_NodeEvent_GetInputEvent()

```
ArkUI_UIInputEvent* OH_ArkUI_NodeEvent_GetInputEvent (ArkUI_NodeEvent * event)
```
**描述：**

获取组件事件中的输入事件（如触碰事件）数据。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 组件事件指针。  | 

**返回：**

ArkUI_UIInputEvent\* 输入事件数据指针。


### OH_ArkUI_NodeEvent_GetNodeComponentEvent()

```
ArkUI_NodeComponentEvent* OH_ArkUI_NodeEvent_GetNodeComponentEvent (ArkUI_NodeEvent * event)
```
**描述：**

获取组件事件中的数字类型数据。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 组件事件指针。  | 

**返回：**

ArkUI_NodeComponentEvent\* 数字类型数据指针。


### OH_ArkUI_NodeEvent_GetNodeHandle()

```
ArkUI_NodeHandle OH_ArkUI_NodeEvent_GetNodeHandle (ArkUI_NodeEvent * event)
```
**描述：**

获取触发该组件的组件对象。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 组件事件指针。  | 

**返回：**

ArkUI_NodeHandle 触发该组件的组件对象。


### OH_ArkUI_NodeEvent_GetStringAsyncEvent()

```
ArkUI_StringAsyncEvent* OH_ArkUI_NodeEvent_GetStringAsyncEvent (ArkUI_NodeEvent * event)
```
**描述：**

获取组件事件中的字符串数据。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 组件事件指针。  | 

**返回：**

ArkUI_StringAsyncEvent\* 字符串数据指针。


### OH_ArkUI_NodeEvent_GetTargetId()

```
int32_t OH_ArkUI_NodeEvent_GetTargetId (ArkUI_NodeEvent * event)
```
**描述：**

获取事件自定义标识ID。

该事件id在调用**registerNodeEvent**函数时作为参数传递进来，可应用于同一事件入口函数**registerNodeEventReceiver**分发逻辑。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 组件事件指针。  | 

**返回：**

int32_t 事件自定义标识ID。


### OH_ArkUI_NodeEvent_GetUserData()

```
void* OH_ArkUI_NodeEvent_GetUserData (ArkUI_NodeEvent * event)
```
**描述：**

获取组件事件中的用户自定义数据。

该自定义参数在调用**registerNodeEvent**函数时作为参数传递进来，可应用于事件触发时的业务逻辑处理。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 组件事件指针。  | 

**返回：**

void\* 用户自定义数据指针。


### OH_ArkUI_PanGesture_GetOffsetX()

```
float OH_ArkUI_PanGesture_GetOffsetX (const ArkUI_GestureEvent * event)
```
**描述：**

滑动手势返回当前手势事件x轴相对偏移量。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 手势事件。  | 

**返回：**

当前手势事件x轴相对偏移量，单位为px。


### OH_ArkUI_PanGesture_GetOffsetY()

```
float OH_ArkUI_PanGesture_GetOffsetY (const ArkUI_GestureEvent * event)
```
**描述：**

滑动手势返回当前手势事件y轴相对偏移量。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 手势事件。  | 

**返回：**

当前手势事件y轴相对偏移量，单位为px。


### OH_ArkUI_PanGesture_GetVelocity()

```
float OH_ArkUI_PanGesture_GetVelocity (const ArkUI_GestureEvent * event)
```
**描述：**

滑动手势返回手势主方向速度。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 手势事件。  | 

**返回：**

当前手势主方向速度，为xy轴方向速度的平方和的算数平方根，单位px/秒。


### OH_ArkUI_PanGesture_GetVelocityX()

```
float OH_ArkUI_PanGesture_GetVelocityX (const ArkUI_GestureEvent * event)
```
**描述：**

滑动手势返回当前手势的x轴方向速度。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 手势事件。  | 

**返回：**

当前手势的x轴方向速度，单位px/秒。


### OH_ArkUI_PanGesture_GetVelocityY()

```
float OH_ArkUI_PanGesture_GetVelocityY (const ArkUI_GestureEvent * event)
```
**描述：**

滑动手势返回当前手势的y轴方向速度。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 手势事件。  | 

**返回：**

当前手势的y轴方向速度，单位px/秒。


### OH_ArkUI_PinchGesture_GetCenterX()

```
float OH_ArkUI_PinchGesture_GetCenterX (const ArkUI_GestureEvent * event)
```
**描述：**

捏合手势中心点相对于当前组件元素左上角x轴坐标。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 手势事件。  | 

**返回：**

捏合手势中心点相对于当前组件元素左上角x轴坐标，单位为px。


### OH_ArkUI_PinchGesture_GetCenterY()

```
float OH_ArkUI_PinchGesture_GetCenterY (const ArkUI_GestureEvent * event)
```
**描述：**

捏合手势中心点相对于当前组件元素左上角y轴坐标。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 手势事件。  | 

**返回：**

捏合手势中心点相对于当前组件元素左上角y轴坐标，单位为px。


### OH_ArkUI_PinchGesture_GetScale()

```
float OH_ArkUI_PinchGesture_GetScale (const ArkUI_GestureEvent * event)
```
**描述：**

捏合手势返回当前手势事件缩放信息。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 手势事件。  | 

**返回：**

缩放比例。


### OH_ArkUI_QueryModuleInterfaceByName()

```
void* OH_ArkUI_QueryModuleInterfaceByName (ArkUI_NativeAPIVariantKind type, const char * structName )
```
**描述：**

获取指定类型的Native模块接口集合。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| type | ArkUI提供的Native接口集合大类，例如UI组件接口类：ARKUI_NATIVE_NODE, 手势类：ARKUI_NATIVE_GESTURE。  | 
| sturctName | native接口结构体的名称，通过查询对应头文件内结构体定义，例如位于&lt;arkui/native_node.h&gt;中的"ArkUI_NativeNodeAPI_1"。  | 

**返回：**

void\* 返回Native接口抽象指针，在转化为具体类型后进行使用。 \#include&lt;arkui/native_interface.h&gt; \#include&lt;arkui/native_node.h&gt; \#include&lt;arkui/native_gesture.h&gt; auto\* anyNativeAPI = [OH_ArkUI_QueryModuleInterfaceByName](#oh_arkui_querymoduleinterfacebyname)(ARKUI_NATIVE_NODE, "ArkUI_NativeNodeAPI_1"); if (anyNativeAPI) { auto nativeNodeApi = reinterpret_cast&lt;[ArkUI_NativeNodeAPI_1](_ark_u_i___native_node_a_p_i__1.md)\*&gt;(anyNativeAPI); } auto anyGestureAPI = OH_ArkUI_QueryModuleInterface(ARKUI_NATIVE_GESTURE, "ArkUI_NativeGestureAPI_1"); if (anyNativeAPI) { auto basicGestureApi = reinterpret_cast&lt;[ArkUI_NativeGestureAPI_1](_ark_u_i___native_gesture_a_p_i__1.md)\*&gt;(anyGestureAPI); }


### OH_ArkUI_RotationGesture_GetAngle()

```
float OH_ArkUI_RotationGesture_GetAngle (const ArkUI_GestureEvent * event)
```
**描述：**

旋转手势返回当前手势事件角度信息。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 手势事件。  | 

**返回：**

旋转角度。


### OH_ArkUI_SwipeGesture_GetAngle()

```
float OH_ArkUI_SwipeGesture_GetAngle (const ArkUI_GestureEvent * event)
```
**描述：**

滑动手势返回当前手势事件角度信息。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 手势事件。  | 

**返回：**

滑动手势的角度，即两根手指间的线段与水平方向的夹角变化的度数。


### OH_ArkUI_SwipeGesture_GetVelocity()

```
float OH_ArkUI_SwipeGesture_GetVelocity (const ArkUI_GestureEvent * event)
```
**描述：**

滑动手势场景中所有手指滑动平均速度。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 手势事件。  | 

**返回：**

滑动手势速度，即所有手指滑动的平均速度，单位为px/秒。


### OH_ArkUI_WaterFlowSectionOption_Create()

```
ArkUI_WaterFlowSectionOption* OH_ArkUI_WaterFlowSectionOption_Create ()
```
**描述：**

创建FlowItem分组配置信息。

**起始版本：** 12


### OH_ArkUI_WaterFlowSectionOption_Dispose()

```
void OH_ArkUI_WaterFlowSectionOption_Dispose (ArkUI_WaterFlowSectionOption * option)
```
**描述：**

销毁FlowItem分组配置信息指针。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| options | FlowItem分组配置信息。  | 


### OH_ArkUI_WaterFlowSectionOption_SetColumnsGap()

```
void OH_ArkUI_WaterFlowSectionOption_SetColumnsGap (ArkUI_WaterFlowSectionOption * option, int32_t index, float columnGap )
```
**描述：**

设置分组的列间距。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| options | FlowItem分组配置信息。  | 
| index | FlowItem索引值。  | 
| columnGap | 列间距。  | 


### OH_ArkUI_WaterFlowSectionOption_SetCrossCount()

```
void OH_ArkUI_WaterFlowSectionOption_SetCrossCount (ArkUI_WaterFlowSectionOption * option, int32_t index, int32_t crossCount )
```
**描述：**

设置布局栅格，纵向布局时为列数，横向布局时为行数。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| options | FlowItem分组配置信息。  | 
| index | FlowItem索引值。  | 
| crossCount | 布局栅格数量。  | 


### OH_ArkUI_WaterFlowSectionOption_SetItemsCount()

```
void OH_ArkUI_WaterFlowSectionOption_SetItemsCount (ArkUI_WaterFlowSectionOption * option, int32_t index, int32_t itemsCount )
```
**描述：**

设置分组中FlowItem数量。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| options | FlowItem分组配置信息。  | 
| index | FlowItem索引值。  | 
| itemsCount | 分组中FlowItem数量。  | 


### OH_ArkUI_WaterFlowSectionOption_SetMargin()

```
void OH_ArkUI_WaterFlowSectionOption_SetMargin (ArkUI_WaterFlowSectionOption * option, int32_t index, float marginTop, float marginRight, float marginBottom, float marginLeft )
```
**描述：**

设置分组的外边距。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| options | FlowItem分组配置信息。  | 
| index | FlowItem索引值。  | 
| marginTop | FlowItem上外边距。  | 
| marginRight | FlowItem右外边距。  | 
| marginBottom | FlowItem下外边距。  | 
| marginLeft | FlowItem左外边距。  | 


### OH_ArkUI_WaterFlowSectionOption_SetRowsGap()

```
void OH_ArkUI_WaterFlowSectionOption_SetRowsGap (ArkUI_WaterFlowSectionOption * option, int32_t index, float rowGap )
```
**描述：**

设置分组的行间距。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| options | FlowItem分组配置信息。  | 
| index | FlowItem索引值。  | 
| rowGap | 行间距。  | 
