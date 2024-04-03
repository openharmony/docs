# ArkUI_NativeModule


## 概述

提供ArkUI在Native侧的UI能力，如UI组件创建销毁、树节点操作，属性设置，事件监听等。

**起始版本：** 12


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [native_event.h](native__event_8h.md) | 提供ArkUI在Native侧的事件类型定义集合。<br>**库：** libace_ndk.z.so  | 
| [native_interface.h](native__interface_8h.md) | 提供NativeModule接口的统一入口函数。<br>**库：** libace_ndk.z.so  | 
| [native_node.h](native__node_8h.md) | 提供NativeNode接口的类型定义。<br>**库：** libace_ndk.z.so  | 
| [native_type.h](native__type_8h.md) | 提供NativeModule公共的类型定义。<br>**库：** libace_ndk.z.so  | 


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct [ArkUI_NodeTouchPoint](_ark_u_i___node_touch_point.md) | 定义Touch事件触控点信息的数据结构。  | 
| struct [ArkUI_NodeHistoricalTouchPoint](_ark_u_i___node_historical_touch_point.md) | 定义历史点信息的结构类型。  | 
| struct [ArkUI_NodeTouchEvent](_ark_u_i___node_touch_event.md) | 定义Touch事件的结构类型。  | 
| struct [ArkUI_AnyNativeAPI](_ark_u_i___any_native_a_p_i.md) | 定义任意版本的Native接口类型。  | 
| struct [ArkUI_AttributeItem](_ark_u_i___attribute_item.md) | 定义**setAttribute**函数通用入参结构。  | 
| struct [ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md) | 定义组件回调事件的参数类型。  | 
| struct [ArkUI_StringAsyncEvent](_ark_u_i___string_async_event.md) | 定义组件回调事件使用字符串参数的类型。  | 
| struct [ArkUI_NodeEvent](_ark_u_i___node_event.md) | 定义组件事件的通用结构类型。  | 
| struct [ArkUI_NativeNodeAPI_1](_ark_u_i___native_node_a_p_i__1.md) | ArkUI提供的Native侧Node类型接口集合。  | 
| union [ArkUI_NumberValue](union_ark_u_i___number_value.md) | ArkUI在native侧的数字类型定义。  | 
| struct [ARKUI_TextPickerRangeContent](_a_r_k_u_i___text_picker_range_content.md) | 定义单列滑动数据选择器支持图片资源的输入结构体。  | 
| struct [ARKUI_TextPickerCascadeRangeContent](_a_r_k_u_i___text_picker_cascade_range_content.md) | 定义多列带联动能力的滑动数据选择器的输入结构体。  | 
| struct [ArkUI_ColorStop](_ark_u_i___color_stop.md) | 定义渐变色结构。  | 



### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct ArkUI_Node \* [ArkUI_NodeHandle](#arkui_nodehandle) | 定义ArkUI native组件实例对象指针定义。  | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [ArkUI_NodeToolType](#arkui_nodetooltype) { NODE_TOOL_TYPE_UNKNOWN = -1, NODE_TOOL_TYPE_FINGER = 0, NODE_TOOL_TYPE_STYLUS = 1 } | Touch事件的工具类型定义。  | 
| [ArkUI_NodeSourceType](#arkui_nodesourcetype) { NODE_SOURCE_TYPE_UNKNOWN = -1, NODE_SOURCE_TYPE_TOUCH_SCREEN = 0, NODE_SOURCE_TYPE_STYLUS = 1, NODE_SOURCE_TYPE_TOUCHPAD = 2 } | 产生Touch事件的来源类型定义。  | 
| [ArkUI_NodeTouchEventAction](#arkui_nodetoucheventaction) { NODE_ACTION_CANCEL = 0, NODE_ACTION_DOWN = 1, NODE_ACTION_MOVE = 2, NODE_ACTION_UP = 3 } | 定义触屏事件类型的枚举值。  | 
| [ArkUI_NativeAPIVariantKind](#arkui_nativeapivariantkind) { ARKUI_NATIVE_NODE } | 定义Native接口集合类型。  | 
| [ArkUI_NativeNodeAPIVersion](#arkui_nativenodeapiversion) { ARKUI_NATIVE_NODE_VERSION_1 } | 定义ARKUI_NATIVE_NODE类型支持的版本号信息。  | 
| [ArkUI_NodeType](#arkui_nodetype) {<br/>ARKUI_NODE_CUSTOM = 0, ARKUI_NODE_TEXT = 1, ARKUI_NODE_SPAN = 2, ARKUI_NODE_IMAGE_SPAN = 3,<br/>ARKUI_NODE_IMAGE = 4, ARKUI_NODE_TOGGLE = 5, ARKUI_NODE_LOADING_PROGRESS = 6, ARKUI_NODE_TEXT_INPUT = 7,<br/>ARKUI_NODE_TEXT_AREA = 8, ARKUI_NODE_BUTTON = 9, ARKUI_NODE_PROGRESS = 10, ARKUI_NODE_CHECKBOX = 11,<br/>ARKUI_NODE_XCOMPONENT = 12, ARKUI_NODE_DATE_PICKER = 13, ARKUI_NODE_TIME_PICKER = 14, ARKUI_NODE_TEXT_PICKER = 15,<br/>ARKUI_NODE_CALENDAR_PICKER = 16, ARKUI_NODE_SLIDER = 17, ARKUI_NODE_STACK = MAX_NODE_SCOPE_NUM, ARKUI_NODE_SWIPER,<br/>ARKUI_NODE_SCROLL, ARKUI_NODE_LIST, ARKUI_NODE_LIST_ITEM, ARKUI_NODE_LIST_ITEM_GROUP,<br/>ARKUI_NODE_COLUMN, ARKUI_NODE_ROW, ARKUI_NODE_FLEX, ARKUI_NODE_REFRESH, ARKUI_NODE_EATER_FLOW<br/>} | 提供ArkUI在Native侧可创建组件类型。  | 
| [ArkUI_NodeAttributeType](#arkui_nodeattributetype) {<br/>NODE_WIDTH = 0, NODE_HEIGHT, NODE_BACKGROUND_COLOR, NODE_BACKGROUND_IMAGE,<br/>NODE_PADDING, NODE_ID, NODE_ENABLED, NODE_MARGIN,<br/>NODE_TRANSLATE, NODE_SCALE, NODE_ROTATE, NODE_BRIGHTNESS,<br/>NODE_SATURATION, NODE_BLUR, NODE_LINEAR_GRADIENT, NODE_ALIGNMENT,<br/>NODE_OPACITY, NODE_BORDER_WIDTH, NODE_BORDER_RADIUS, NODE_BORDER_COLOR,<br/>NODE_BORDER_STYLE, NODE_Z_INDEX, NODE_VISIBILITY, NODE_CLIP,<br/>NODE_CLIP_SHAPE, NODE_TRANSFORM, NODE_HIT_TEST_BEHAVIOR, NODE_POSITION,<br/>NODE_SHADOW, NODE_CUSTOM_SHADOW, NODE_BACKGROUND_IMAGE_SIZE, NODE_BACKGROUND_IMAGE_SIZE_WITH_STYLE,<br/>NODE_BACKGROUND_BLUR_STYLE, NODE_TRANSFORM_CENTER, NODE_OPACITY_TRANSITION, NODE_ROTATE_TRANSITION,<br/>NODE_SCALE_TRANSITION, NODE_TRANSLATE_TRANSITION, NODE_FOCUSABLE, NODE_DEFAULT_FOCUS,<br/>NODE_RESPONSE_REGION, NODE_OVERLAY, NODE_SWEEP_GRADIENT, NODE_RADIAL_GRADIENT,<br/>NODE_MASK, NODE_BLEND_MODE, NODE_DIRECTION, NODE_CONSTRAINT_SIZE,<br/>NODE_GRAY_SCALE, NODE_INVERT, NODE_SEPIA, NODE_CONTRAST,<br/>NODE_FOREGROUND_COLOR, NODE_OFFSET, NODE_MARK_ANCHOR, NODE_BACKGROUND_IMAGE_POSITION,<br/>NODE_ALIGN_RULES, NODE_ALIGN_SELF, NODE_FLEX_GROW, NODE_FLEX_SHRINK,<br/>NODE_FLEX_BASIS, NODE_ACCESSIBILITY_GROUP, NODE_ACCESSIBILITY_TEXT, NODE_ACCESSIBILITY_MODE,<br/>NODE_ACCESSIBILITY_DESCRIPTION, NODE_FOCUS_STATUS, NODE_TEXT_CONTENT = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_TEXT, NODE_FONT_COLOR,<br/>NODE_FONT_SIZE, NODE_FONT_STYLE, NODE_FONT_WEIGHT, NODE_TEXT_LINE_HEIGHT,<br/>NODE_TEXT_DECORATION, NODE_TEXT_CASE, NODE_TEXT_LETTER_SPACING, NODE_TEXT_MAX_LINES,<br/>NODE_TEXT_ALIGN, NODE_TEXT_OVERFLOW, NODE_FONT_FAMILY, NODE_TEXT_COPY_OPTION,<br/>NODE_TEXT_BASELINE_OFFSET, NODE_TEXT_TEXT_SHADOW, NODE_TEXT_MIN_FONT_SIZE, NODE_TEXT_MAX_FONT_SIZE,<br/>NODE_TEXT_FONT, NODE_TEXT_HEIGHT_ADAPTIVE_POLICY, NODE_TEXT_INDENT, NODE_SPAN_CONTENT = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_SPAN,<br/>NODE_IMAGE_SPAN_SRC = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_IMAGE_SPAN, NODE_IMAGE_SPAN_VERTICAL_ALIGNMENT, NODE_IMAGE_SRC = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_IMAGE, NODE_IMAGE_OBJECT_FIT,<br/>NODE_IMAGE_INTERPOLATION, NODE_IMAGE_OBJECT_REPEAT, NODE_IMAGE_COLOR_FILTER, NODE_IMAGE_AUTO_RESIZE,<br/>NODE_IMAGE_ALT, NODE_TOGGLE_SELECTED_COLOR = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_TOGGLE, NODE_TOGGLE_SWITCH_POINT_COLOR, NODE_LOADING_PROGRESS_COLOR = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_LOADING_PROGRESS,<br/>NODE_LOADING_PROGRESS_ENABLE_LOADING, NODE_TEXT_INPUT_PLACEHOLDER = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_TEXT_INPUT, NODE_TEXT_INPUT_TEXT, NODE_TEXT_INPUT_CARET_COLOR,<br/>NODE_TEXT_INPUT_CARET_STYLE, NODE_TEXT_INPUT_SHOW_UNDERLINE, NODE_TEXT_INPUT_MAX_LENGTH, NODE_TEXT_INPUT_ENTER_KEY_TYPE,<br/>NODE_TEXT_INPUT_PLACEHOLDER_COLOR, NODE_TEXT_INPUT_PLACEHOLDER_FONT, NODE_TEXT_INPUT_ENABLE_KEYBOARD_ON_FOCUS, NODE_TEXT_INPUT_TYPE,<br/>NODE_TEXT_INPUT_SELECTED_BACKGROUND_COLOR, NODE_TEXT_INPUT_SHOW_PASSWORD_ICON, NODE_TEXT_INPUT_EDITING, NODE_TEXT_INPUT_CANCEL_BUTTON,<br/>NODE_TEXT_AREA_PLACEHOLDER = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_TEXT_AREA, NODE_TEXT_AREA_TEXT, NODE_TEXT_AREA_MAX_LENGTH, NODE_TEXT_AREA_PLACEHOLDER_COLOR,<br/>NODE_TEXT_AREA_PLACEHOLDER_FONT, NODE_TEXT_AREA_CARET_COLOR, NODE_TEXT_AREA_EDITING, NODE_BUTTON_LABEL = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_BUTTON,<br/>NODE_PROGRESS_VALUE = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_PROGRESS, NODE_PROGRESS_TOTAL, NODE_PROGRESS_COLOR, NODE_PROGRESS_TYPE,<br/>NODE_CHECKBOX_SELECT = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_CHECKBOX, NODE_CHECKBOX_SELECT_COLOR, NODE_CHECKBOX_UNSELECT_COLOR, NODE_CHECKBOX_MARK,<br/>NODE_CHECKBOX_SHAPE, NODE_XCOMPONENT_ID = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_XCOMPONENT, NODE_XCOMPONENT_TYPE, NODE_XCOMPONENT_SURFACE_SIZE,<br/>NODE_DATE_PICKER_LUNAR = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_DATE_PICKER, NODE_DATE_PICKER_START, NODE_DATE_PICKER_END, NODE_DATE_PICKER_SELECTED,<br/>NODE_DATE_PICKER_DISAPPEAR_TEXT_STYLE, NODE_DATE_PICKER_TEXT_STYLE, NODE_DATE_PICKER_SELECTED_TEXT_STYLE, NODE_TIME_PICKER_SELECTED = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_TIME_PICKER,<br/>NODE_TIME_PICKER_USE_MILITARY_TIME, NODE_TIME_PICKER_DISAPPEAR_TEXT_STYLE, NODE_TIME_PICKER_TEXT_STYLE, NODE_TIME_PICKER_SELECTED_TEXT_STYLE,<br/>NODE_TEXT_PICKER_OPTION_RANGE = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_TEXT_PICKER, NODE_TEXT_PICKER_OPTION_SELECTED, NODE_TEXT_PICKER_OPTION_VALUE, NODE_TEXT_PICKER_DISAPPEAR_TEXT_STYLE,<br/>NODE_TEXT_PICKER_TEXT_STYLE, NODE_TEXT_PICKER_SELECTED_TEXT_STYLE, NODE_TEXT_PICKER_SELECTED_INDEX, NODE_TEXT_PICKER_CAN_LOOP,<br/>NODE_TEXT_PICKER_DEFAULT_PICKER_ITEM_HEIGHT, NODE_CALENDAR_PICKER_HINT_RADIUS = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_CALENDAR_PICKER, NODE_CALENDAR_PICKER_SELECTED_DATE, NODE_CALENDAR_PICKER_EDGE_ALIGNMENT,<br/>NODE_CALENDAR_PICKER_TEXT_STYLE, NODE_SLIDER_BLOCK_COLOR = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_SLIDER, NODE_SLIDER_TRACK_COLOR, NODE_SLIDER_SELECTED_COLOR,<br/>NODE_SLIDER_SHOW_STEPS, NODE_SLIDER_BLOCK_STYLE, NODE_SLIDER_VALUE, NODE_SLIDER_MIN_VALUE,<br/>NODE_SLIDER_MAX_VALUE, NODE_SLIDER_STEP, NODE_SLIDER_DIRECTION, NODE_SLIDER_REVERSE,<br/>NODE_SLIDER_STYLE, NODE_STACK_ALIGN_CONTENT = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_STACK, NODE_SCROLL_BAR_DISPLAY_MODE = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_SCROLL, NODE_SCROLL_BAR_WIDTH,<br/>NODE_SCROLL_BAR_COLOR, NODE_SCROLL_SCROLL_DIRECTION, NODE_SCROLL_EDGE_EFFECT, NODE_SCROLL_ENABLE_SCROLL_INTERACTION,<br/>NODE_SCROLL_FRICTION, NODE_SCROLL_SNAP, NODE_SCROLL_NESTED_SCROLL, NODE_SCROLL_OFFSET,<br/>NODE_SCROLL_EDGE, NODE_SCROLL_ENABLE_PAGING, NODE_LIST_DIRECTION = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_LIST, NODE_LIST_STICKY,<br/>NODE_LIST_SPACE, NODE_SWIPER_LOOP = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_SWIPER, NODE_SWIPER_AUTO_PLAY, NODE_SWIPER_SHOW_INDICATOR,<br/>NODE_SWIPER_INTERVAL, NODE_SWIPER_VERTICAL, NODE_SWIPER_DURATION, NODE_SWIPER_CURVE,<br/>NODE_SWIPER_ITEM_SPACE, NODE_SWIPER_INDEX, NODE_SWIPER_DISPLAY_COUNT, NODE_SWIPER_DISABLE_SWIPE,<br/>NODE_SWIPER_SHOW_DISPLAY_ARROW, NODE_LIST_ITEM_GROUP_SET_HEADER = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_LIST_ITEM_GROUP, NODE_LIST_ITEM_GROUP_SET_FOOTER, NODE_LIST_ITEM_GROUP_SET_DIVIDER,<br/>NODE_COLUMN_ALIGN_ITEMS = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_COLUMN, NODE_COLUMN_JUSTIFY_CONTENT, NODE_ROW_ALIGN_ITEMS = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_ROW, NODE_ROW_JUSTIFY_CONTENT,<br/>NODE_FLEX_OPTION = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_FLEX, NODE_REFRESH_REFRESHING = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_REFRESH<br/>} | 定义ArkUI在Native侧可以设置的属性样式集合。  | 
| [ArkUI_NodeEventType](#arkui_nodeeventtype) {<br/>NODE_TOUCH_EVENT = 0, NODE_EVENT_ON_APPEAR, NODE_EVENT_ON_AREA_CHANGE, NODE_ON_FOCUS,<br/>NODE_ON_BLUR, NODE_ON_CLICK, NODE_IMAGE_ON_COMPLETE = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_IMAGE, NODE_IMAGE_ON_ERROR,<br/>NODE_IMAGE_ON_SVG_PLAY_FINISH, NODE_TOGGLE_ON_CHANGE = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_TOGGLE, NODE_TEXT_INPUT_ON_CHANGE = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_TEXT_INPUT, NODE_TEXT_INPUT_ON_SUBMIT,<br/>NODE_TEXT_INPUT_ON_CUT, NODE_TEXT_INPUT_ON_PASTE, NODE_TEXT_AREA_ON_CHANGE = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_TEXT_AREA, NODE_CHECKBOX_EVENT_ON_CHANGE = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_CHECKBOX,<br/>NODE_DATE_PICKER_EVENT_ON_DATE_CHANGE = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_DATE_PICKER, NODE_TIME_PICKER_EVENT_ON_CHANGE = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_TIME_PICKER, NODE_TEXT_PICKER_EVENT_ON_CHANGE = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_TEXT_PICKER, NODE_CALENDAR_PICKER_EVENT_ON_CHANGE = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_CALENDAR_PICKER,<br/>NODE_SLIDER_EVENT_ON_CHANGE = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_SLIDER, NODE_SCROLL_EVENT_ON_SCROLL = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_SCROLL, NODE_SCROLL_EVENT_ON_SCROLL_FRAME_BEGIN, NODE_SCROLL_EVENT_ON_SCROLL_START,<br/>NODE_SCROLL_EVENT_ON_SCROLL_STOP, NODE_SCROLL_EVENT_ON_SCROLL_EDGE, NODE_REFRESH_STATE_CHANGE = MAX_NODE_SCOPE_NUM \* ARKUI_NODE_REFRESH, NODE_REFRESH_ON_REFRESH<br/>} | 提供NativeNode组件支持的事件类型定义。  | 
| [ArkUI_NodeDirtyFlag](#arkui_nodedirtyflag) { NODE_NEED_MEASURE = 1, NODE_NEED_LAYOUT, NODE_NEED_RENDER } | 自定义组件调用&lt;b&gt;::markDirty是传递的藏区标识类型。  | 
| [ArkUI_Alignment](#arkui_alignment) {<br/>ARKUI_ALIGNMENT_TOP_START = 0, ARKUI_ALIGNMENT_TOP, ARKUI_ALIGNMENT_TOP_END, ARKUI_ALIGNMENT_START,<br/>ARKUI_ALIGNMENT_CENTER, ARKUI_ALIGNMENT_END, ARKUI_ALIGNMENT_BOTTOM_START, ARKUI_ALIGNMENT_BOTTOM,<br/>ARKUI_ALIGNMENT_BOTTOM_END<br/>} | 定义布局对齐枚举值。  | 
| [ArkUI_ImageRepeat](#arkui_imagerepeat) { ARKUI_IMAGE_REPEAT_NONE = 0, ARKUI_IMAGE_REPEAT_X, ARKUI_IMAGE_REPEAT_Y, ARKUI_IMAGE_REPEAT_XY } | 定义图片重复铺设枚举值。  | 
| [ArkUI_FontStyle](#arkui_fontstyle) { ARKUI_FONT_STYLE_NORMAL = 0, ARKUI_FONT_STYLE_ITALIC } | 定义字体样式枚举值。  | 
| [ArkUI_FontWeight](#arkui_fontweight) {<br/>ARKUI_FONT_WEIGHT_W100 = 0, ARKUI_FONT_WEIGHT_W200, ARKUI_FONT_WEIGHT_W300, ARKUI_FONT_WEIGHT_W400,<br/>ARKUI_FONT_WEIGHT_W500, ARKUI_FONT_WEIGHT_W600, ARKUI_FONT_WEIGHT_W700, ARKUI_FONT_WEIGHT_W800,<br/>ARKUI_FONT_WEIGHT_W900, ARKUI_FONT_WEIGHT_BOLD, ARKUI_FONT_WEIGHT_NORMAL, ARKUI_FONT_WEIGHT_BOLDER,<br/>ARKUI_FONT_WEIGHT_LIGHTER, ARKUI_FONT_WEIGHT_MEDIUM, ARKUI_FONT_WEIGHT_REGULAR<br/>} | 定义字体粗细/字重枚举值。  | 
| [ArkUI_TextAlignment](#arkui_textalignment) { ARKUI_TEXT_ALIGNMENT_START = 0, ARKUI_TEXT_ALIGNMENT_CENTER, ARKUI_TEXT_ALIGNMENT_END, ARKUI_TEXT_ALIGNMENT_JUSTIFY } | 定义字体水平对齐样式枚举值。  | 
| [ArkUI_EnterKeyType](#arkui_enterkeytype) {<br/>ARKUI_ENTER_KEY_TYPE_GO = 2, ARKUI_ENTER_KEY_TYPE_SEARCH = 3, ARKUI_ENTER_KEY_TYPE_SEND, ARKUI_ENTER_KEY_TYPE_NEXT,<br/>ARKUI_ENTER_KEY_TYPE_DONE, ARKUI_ENTER_KEY_TYPE_PREVIOUS, ARKUI_ENTER_KEY_TYPE_NEW_LINE<br/>} | 定义单行文本输入法回车键类型枚举值。  | 
| [ArkUI_TextInputType](#arkui_textinputtype) {<br/>ARKUI_TEXTINPUT_TYPE_NORMAL = 0, ARKUI_TEXTINPUT_TYPE_NUMBER = 2, ARKUI_TEXTINPUT_TYPE_PHONE_NUMBER = 3, ARKUI_TEXTINPUT_TYPE_EMAIL = 5,<br/>ARKUI_TEXTINPUT_TYPE_PASSWORD = 7, ARKUI_TEXTINPUT_TYPE_NUMBER_PASSWORD = 8, ARKUI_TEXTINPUT_TYPE_SCREEN_LOCK_PASSWORD = 9, ARKUI_TEXTINPUT_TYPE_USER_NAME = 10,<br/>ARKUI_TEXTINPUT_TYPE_NEW_PASSWORD = 11, ARKUI_TEXTINPUT_TYPE_NUMBER_DECIMAL = 12<br/>} | 定义单行文本输入法类型枚举值。  | 
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
| [ArkUI_LinearGradientDirection](#arkui_lineargradientdirection) {<br/>ARKUI_LINEAR_GRADIENT_DIRECTION_LEFT = 0, ARKUI_LINEAR_GRADIENT_DIRECTION_TOP, ARKUI_LINEAR_GRADIENT_DIRECTION_RIGHT, ARKUI_LINEAR_GRADIENT_DIRECTION_BOTTOM,<br/>ARKUI_LINEAR_GRADIENT_DIRECTION_LEFT_TOP, ARKUI_LINEAR_GRADIENT_DIRECTION_LEFT_BOTTOM, ARKUI_LINEAR_GRADIENT_DIRECTION_RIGHT_TOP, ARKUI_LINEAR_GRADIENT_DIRECTION_RIGHT_BOTTOM,<br/>ARKUI_LINEAR_GRADIENT_DIRECTION_NONE<br/>} | 定义渐变方向结构。  | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [ArkUI_AnyNativeAPI](_ark_u_i___any_native_a_p_i.md) \* [OH_ArkUI_GetNativeAPI](#oh_arkui_getnativeapi) ([ArkUI_NativeAPIVariantKind](#arkui_nativeapivariantkind) type, int32_t version) | 获取指定版本的Native接口集合。  | 
| [ArkUI_AnyNativeAPI](_ark_u_i___any_native_a_p_i.md) \* [OH_ArkUI_QueryModuleInterface](#oh_arkui_querymoduleinterface) ([ArkUI_NativeAPIVariantKind](#arkui_nativeapivariantkind) type, int32_t version) | 获取指定版本的Native模块接口集合。  | 


## 类型定义说明


### ArkUI_NodeHandle

```
typedef struct ArkUI_Node* ArkUI_NodeHandle
```
**描述：**

定义ArkUI native组件实例对象指针定义。

**起始版本：** 12


## 枚举类型说明


### ArkUI_AccessibilityMode

```
enum ArkUI_AccessibilityMode
```
**描述：**

定义无障碍重要性。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_ACCESSIBILITY_MODE_AUTO  | 根据组件不同会转换为“enabled”或者“disabled”。 |
| ARKUI_ACCESSIBILITY_MODE_ENABLED  | 当前组件可被无障碍辅助服务所识别。 | 
| ARKUI_ACCESSIBILITY_MODE_DISABLED  | 当前组件不可被无障碍辅助服务所识别。 | 
| ARKUI_ACCESSIBILITY_MODE_DISABLED_FOR_DESCENDANTS  | 当前组件及其所有子组件不可被无障碍辅助服务所识别。 | 


### ArkUI_AdaptiveColor

```
enum ArkUI_AdaptiveColor
```
**描述：**

定义取色模式。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_ADAPTIVE_COLOR_DEFAULT  | 不使用取色模糊。 | 
| ARKUI_ADAPTIVE_COLOR_AVERAGE  | 使用取色模糊。 | 


### ArkUI_Alignment

```
enum ArkUI_Alignment
```
**描述：**

定义布局对齐枚举值。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_ALIGNMENT_TOP_START  | 顶部起始。 | 
| ARKUI_ALIGNMENT_TOP  | 顶部居中。 | 
| ARKUI_ALIGNMENT_TOP_END  | 顶部尾端。 | 
| ARKUI_ALIGNMENT_START  | 起始端纵向居中。 | 
| ARKUI_ALIGNMENT_CENTER  | 横向和纵向居中。 | 
| ARKUI_ALIGNMENT_END  | 尾端纵向居中。 | 
| ARKUI_ALIGNMENT_BOTTOM_START  | 底部起始端。 | 
| ARKUI_ALIGNMENT_BOTTOM  | 底部横向居中。 | 
| ARKUI_ALIGNMENT_BOTTOM_END  | 底部尾端。 | 


### ArkUI_AnimationCurve

```
enum ArkUI_AnimationCurve
```
**描述：**

动画曲线枚举值。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_CURVE_LINEAR  | 动画从头到尾的速度都是相同。 | 
| ARKUI_CURVE_EASE  | 动画以低速开始，然后加快，在结束前变慢。 | 
| ARKUI_CURVE_EASE_IN  | 动画以低速开始。 | 
| ARKUI_CURVE_EASE_OUT  | 动画以低速结束。 | 
| ARKUI_CURVE_EASE_IN_OUT  | 动画以低速开始和结束。 | 
| ARKUI_CURVE_FAST_OUT_SLOW_IN  | 动画标准曲线。 | 
| ARKUI_CURVE_LINEAR_OUT_SLOW_IN  | 动画减速曲线。 | 
| ARKUI_CURVE_FAST_OUT_LINEAR_IN  | 动画加速曲线。 | 
| ARKUI_CURVE_EXTREME_DECELERATION  | 动画急缓曲线。 | 
| ARKUI_CURVE_SHARP  | 动画锐利曲线。 | 
| ARKUI_CURVE_RHYTHM  | 动画节奏曲线。 | 
| ARKUI_CURVE_SMOOTH  | 动画平滑曲线。 | 
| ARKUI_CURVE_FRICTION  | 动画阻尼曲线。 | 


### ArkUI_AnimationPlayMode

```
enum ArkUI_AnimationPlayMode
```
**描述：**

定义动画播放模式。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_ANIMATION_PLAY_MODE_NORMAL  | 动画正向播放。 | 
| ARKUI_ANIMATION_PLAY_MODE_REVERSE  | 动画反向播放。 | 
| ARKUI_ANIMATION_PLAY_MODE_ALTERNATE  | 动画在奇数次（1、3、5...）正向播放，在偶数次（2、4、6...）反向播放。 | 
| ARKUI_ANIMATION_PLAY_MODE_ALTERNATE_REVERSE  | 动画在奇数次（1、3、5...）反向播放，在偶数次（2、4、6...）正向播放。 | 


### ArkUI_Axis

```
enum ArkUI_Axis
```
**描述：**

定义滚动方向和List组件排列方向枚举值。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_AXIS_VERTICAL  | 仅支持竖直方向滚动。 | 
| ARKUI_AXIS_HORIZONTAL  | 仅支持水平方向滚动。 | 


### ArkUI_BlendMode

```
enum ArkUI_BlendMode
```
**描述：**

混合模式枚举值。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_BLEND_MODE_NONE  | 将上层图像直接覆盖到下层图像上，不进行任何混合操作。 | 
| ARKUI_BLEND_MODE_CLEAR  | 将源像素覆盖的目标像素清除为完全透明。 | 
| ARKUI_BLEND_MODE_SRC  | r = s，只显示源像素。 | 
| ARKUI_BLEND_MODE_DST  | r = d，只显示目标像素。 | 
| ARKUI_BLEND_MODE_SRC_OVER  | r = s + (1 - sa) \* d，将源像素按照透明度进行混合，覆盖在目标像素上。 | 
| ARKUI_BLEND_MODE_DST_OVER  | r = d + (1 - da) \* s，将目标像素按照透明度进行混合，覆盖在源像素上。 | 
| ARKUI_BLEND_MODE_SRC_IN  | r = s \* da，只显示源像素中与目标像素重叠的部分。 | 
| ARKUI_BLEND_MODE_DST_IN  | r = d \* sa，只显示目标像素中与源像素重叠的部分。 | 
| ARKUI_BLEND_MODE_SRC_OUT  | r = s \* (1 - da)，只显示源像素中与目标像素不重叠的部分。 | 
| ARKUI_BLEND_MODE_DST_OUT  | r = d \* (1 - sa)，只显示目标像素中与源像素不重叠的部分。 | 
| ARKUI_BLEND_MODE_SRC_ATOP  | r = s \* da + d \* (1 - sa)，在源像素和目标像素重叠的地方绘制源像素，在源像素和目标像素不重叠的地方绘制目标像素。 | 
| ARKUI_BLEND_MODE_DST_ATOP  | r = d \* sa + s \* (1 - da)，在源像素和目标像素重叠的地方绘制目标像素，在源像素和目标像素不重叠的地方绘制源像素。 | 
| ARKUI_BLEND_MODE_XOR  | r = s \* (1 - da) + d \* (1 - sa)，只显示源像素与目标像素不重叠的部分。 | 
| ARKUI_BLEND_MODE_PLUS  | r = min(s + d, 1)，将源像素值与目标像素值相加，并将结果作为新的像素值。 | 
| ARKUI_BLEND_MODE_MODULATE  | r = s \* d，将源像素与目标像素进行乘法运算，并将结果作为新的像素值。 | 
| ARKUI_BLEND_MODE_SCREEN  | r = s + d - s \* d，将两个图像的像素值相加，然后减去它们的乘积来实现混合。 | 
| ARKUI_BLEND_MODE_OVERLAY  | 根据目标像素来决定使用MULTIPLY混合模式还是SCREEN混合模式。 | 
| ARKUI_BLEND_MODE_DARKEN  | rc = s + d - max(s \* da, d \* sa), ra = kSrcOver，当两个颜色重叠时，较暗的颜色会覆盖较亮的颜色。 | 
| ARKUI_BLEND_MODE_LIGHTEN  | rc = s + d - min(s \* da, d \* sa), ra = kSrcOver，将源图像和目标图像中的像素进行比较，选取两者中较亮的像素作为最终的混合结果。 | 
| ARKUI_BLEND_MODE_COLOR_DODGE  | 使目标像素变得更亮来反映源像素。 | 
| ARKUI_BLEND_MODE_COLOR_BURN  | 使目标像素变得更暗来反映源像素。 | 
| ARKUI_BLEND_MODE_HARD_LIGHT  | 根据源像素的值来决定目标像素变得更亮或者更暗。根据源像素来决定使用MULTIPLY混合模式还是SCREEN混合模式。 | 
| ARKUI_BLEND_MODE_SOFT_LIGHT  | 根据源像素来决定使用LIGHTEN混合模式还是DARKEN混合模式。 | 
| ARKUI_BLEND_MODE_DIFFERENCE  | rc = s + d - 2 \* (min(s \* da, d \* sa)), ra = kSrcOver，对比源像素和目标像素，亮度更高的像素减去亮度更低的像素，产生高对比度的效果。 | 
| ARKUI_BLEND_MODE_EXCLUSION  | rc = s + d - two(s \* d), ra = kSrcOver，对比源像素和目标像素，亮度更高的像素减去亮度更低的像素，产生柔和的效果。 | 
| ARKUI_BLEND_MODE_MULTIPLY  | r = s \* (1 - da) + d \* (1 - sa) + s \* d，将源图像与目标图像进行乘法混合，得到一张新的图像。 | 
| ARKUI_BLEND_MODE_HUE  | 保留源图像的亮度和饱和度，但会使用目标图像的色调来替换源图像的色调。 | 
| ARKUI_BLEND_MODE_SATURATION  | 保留目标像素的亮度和色调，但会使用源像素的饱和度来替换目标像素的饱和度。 | 
| ARKUI_BLEND_MODE_COLOR  | 保留源像素的饱和度和色调，但会使用目标像素的亮度来替换源像素的亮度。 | 
| ARKUI_BLEND_MODE_LUMINOSITY  | 保留目标像素的色调和饱和度，但会用源像素的亮度替换目标像素的亮度。 | 


### ArkUI_BlurStyle

```
enum ArkUI_BlurStyle
```
**描述：**

定义背景模糊样式。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_BLUR_STYLE_THIN  | 轻薄材质模糊。 | 
| ARKUI_BLUR_STYLE_REGULAR  | 普通厚度材质模糊。 | 
| ARKUI_BLUR_STYLE_THICK  | 厚材质模糊。 | 
| ARKUI_BLUR_STYLE_BACKGROUND_THIN  | 近距景深模糊。 | 
| ARKUI_BLUR_STYLE_BACKGROUND_REGULAR  | 中距景深模糊。 | 
| ARKUI_BLUR_STYLE_BACKGROUND_THICK  | 远距景深模糊。 | 
| ARKUI_BLUR_STYLE_BACKGROUND_ULTRA_THICK  | 超远距景深模糊。 | 
| ARKUI_BLUR_STYLE_NONE  | 关闭模糊。 | 
| ARKUI_BLUR_STYLE_COMPONENT_ULTRA_THIN  | 组件超轻薄材质模糊。 | 
| ARKUI_BLUR_STYLE_COMPONENT_THIN  | 组件轻薄材质模糊。 | 
| ARKUI_BLUR_STYLE_COMPONENT_REGULAR  | 组件普通材质模糊。 | 
| ARKUI_BLUR_STYLE_COMPONENT_THICK  | 组件厚材质模糊。 | 
| ARKUI_BLUR_STYLE_COMPONENT_ULTRA_THICK  | 组件超厚材质模糊。 | 


### ArkUI_BorderStyle

```
enum ArkUI_BorderStyle
```
**描述：**

边框线条样式枚举值。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_BORDER_STYLE_SOLID  | 显示为一条实线。 | 
| ARKUI_BORDER_STYLE_DASHED  | 显示为一系列短的方形虚线。 | 
| ARKUI_BORDER_STYLE_DOTTED  | 显示为一系列圆点。 | 


### ArkUI_CalendarAlignment

```
enum ArkUI_CalendarAlignment
```
**描述：**

日历选择器与入口组件对齐方式。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_CALENDAR_ALIGNMENT_START  | 选择器和入口组件左对齐方式。 | 
| ARKUI_CALENDAR_ALIGNMENT_CENTER  | 选择器和入口组件居中对齐方式。 | 
| ARKUI_CALENDAR_ALIGNMENT_END  | 选择器和入口组件右对齐方式。 | 


### ArkUI_CancelButtonStyle

```
enum ArkUI_CancelButtonStyle
```
**描述：**

定义清除按钮样式枚举值。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_CANCELBUTTON_STYLE_CONSTANT  | 清除按钮常显样式。 | 
| ARKUI_CANCELBUTTON_STYLE_INVISIBLE  | 清除按钮常隐样式。 | 
| ARKUI_CANCELBUTTON_STYLE_INPUT  | 清除按钮输入样式。 | 


### ArkUI_CheckboxShape

```
enum ArkUI_CheckboxShape
```
**描述：**

定义CheckBox组件形状。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ArkUI_CHECKBOX_SHAPE_CIRCLE  | 圆形。 | 
| ArkUI_CHECKBOX_SHAPE_ROUNDED_SQUARE  | 圆角方形。 | 


### ArkUI_ClipType

```
enum ArkUI_ClipType
```
**描述：**

裁剪类型枚举。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_CLIP_TYPE_RECTANGLE  | 矩形类型。 | 
| ARKUI_CLIP_TYPE_CIRCLE  | 圆形类型。 | 
| ARKUI_CLIP_TYPE_ELLIPSE  | 椭圆形类型。 | 
| ARKUI_CLIP_TYPE_PATH  | 路径类型。 | 


### ArkUI_ColorMode

```
enum ArkUI_ColorMode
```
**描述：**

定义深浅色模式。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_COLOR_MODE_SYSTEM  | 跟随系统深浅色模式。 | 
| ARKUI_COLOR_MODE_LIGHT  | 固定使用浅色模式。 | 
| ARKUI_COLOR_MODE_DARK  | 固定使用深色模式。 | 


### ArkUI_ColorStrategy

```
enum ArkUI_ColorStrategy
```
**描述：**

前景色枚举值。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_COLOR_STRATEGY_INVERT  | 前景色为控件背景色的反色。 | 
| ARKUI_COLOR_STRATEGY_AVERAGE  | 控件背景阴影色为控件背景阴影区域的平均色。 | 
| ARKUI_COLOR_STRATEGY_PRIMARY  | 控件背景阴影色为控件背景阴影区域的主色。 | 


### ArkUI_CopyOptions

```
enum ArkUI_CopyOptions
```
**描述：**

定义文本复制黏贴模式枚举值。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_COPY_OPTIONS_NONE  | 不支持复制。 | 
| ARKUI_COPY_OPTIONS_IN_APP  | 支持应用内复制。 | 
| ARKUI_COPY_OPTIONS_LOCAL_DEVICE  | 支持设备内复制。 | 
| ARKUI_COPY_OPTIONS_CROSS_DEVICE  | 支持跨设备复制。 | 


### ArkUI_Direction

```
enum ArkUI_Direction
```
**描述：**

设置容器元素内主轴方向上的布局枚举值。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_DIRECTION_LTR  | 元素从左到右布局。 | 
| ARKUI_DIRECTION_RTL  | 元素从右到左布局。 | 
| ARKUI_DIRECTION_AUTO  | 使用系统默认布局方向。 | 


### ArkUI_EdgeEffect

```
enum ArkUI_EdgeEffect
```
**描述：**

定义边缘滑动效果枚举值。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_EDGE_EFFECT_SPRING  | 弹性物理动效，滑动到边缘后可以根据初始速度或通过触摸事件继续滑动一段距离，松手后回弹。 | 
| ARKUI_EDGE_EFFECT_FADE  | 阴影效果，滑动到边缘后会有圆弧状的阴影。 | 
| ARKUI_EDGE_EFFECT_NONE  | 滑动到边缘后无效果。 | 


### ArkUI_EnterKeyType

```
enum ArkUI_EnterKeyType
```
**描述：**

定义单行文本输入法回车键类型枚举值。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_ENTER_KEY_TYPE_GO  | 显示为开始样式。 | 
| ARKUI_ENTER_KEY_TYPE_SEARCH  | 显示为搜索样式。 | 
| ARKUI_ENTER_KEY_TYPE_SEND  | 显示为发送样式。 | 
| ARKUI_ENTER_KEY_TYPE_NEXT  | 显示为下一个样式。 | 
| ARKUI_ENTER_KEY_TYPE_DONE  | 显示为完成样式。 | 
| ARKUI_ENTER_KEY_TYPE_PREVIOUS  | 显示为上一个样式。 | 
| ARKUI_ENTER_KEY_TYPE_NEW_LINE  | 显示为换行样式。 | 


### ArkUI_FlexAlignment

```
enum ArkUI_FlexAlignment
```
**描述：**

定义垂直方向对齐方式。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_FLEX_ALIGNMENT_START  | 主轴方向首端对齐。 | 
| ARKUI_FLEX_ALIGNMENT_CENTER  | 主轴方向中心对齐。 | 
| ARKUI_FLEX_ALIGNMENT_END  | 主轴方向尾部对齐。 | 
| ARKUI_FLEX_ALIGNMENT_SPACE_BETWEEN  | Flex主轴方向均匀分配弹性元素，相邻元素之间距离相同，第一个元素行首对齐，最后的元素行尾对齐。 | 
| ARKUI_FLEX_ALIGNMENT_SPACE_AROUND  | Flex主轴方向均匀分配弹性元素，相邻元素之间距离相同，第一个元素到行首的距离时相邻元素间距离的一半。 | 
| ARKUI_FLEX_ALIGNMENT_SPACE_EVENLY  | Flex主轴方向均匀分配弹性元素，相邻元素之间距离、第一个元素到行首的距离和最后的元素到行尾的距离均相等。 | 


### ArkUI_FlexDirection

```
enum ArkUI_FlexDirection
```
**描述：**

定义Flex容器的主轴方向。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_FLEX_DIRECTION_ROW  | 主轴与行方向一致。 | 
| ARKUI_FLEX_DIRECTION_COLUMN  | 主轴与列方向一致。 | 
| ARKUI_FLEX_DIRECTION_ROW_REVERSE  | 主轴与行方向相反。 | 
| ARKUI_FLEX_DIRECTION_COLUMN_REVERSE  | 主轴与列方向相反。 | 


### ArkUI_FlexWrap

```
enum ArkUI_FlexWrap
```
**描述：**

定义Flex行列布局模式模式。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_FLEX_WRAP_NO_WRAP  | 单行/单列布局，子项不能超出容器。 | 
| ARKUI_FLEX_WRAP_WRAP  | 多行/多列布局，子项允许超出容器。 | 
| ARKUI_FLEX_WRAP_WRAP_REVERSE  | 反向多行/多列布局，子项允许超出容器。 | 


### ArkUI_FontStyle

```
enum ArkUI_FontStyle
```
**描述：**

定义字体样式枚举值。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_FONT_STYLE_NORMAL  | 标准字体样式。 | 
| ARKUI_FONT_STYLE_ITALIC  | 斜体字体样式。 | 


### ArkUI_FontWeight

```
enum ArkUI_FontWeight
```
**描述：**

定义字体粗细/字重枚举值。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_FONT_WEIGHT_W100  | 100 | 
| ARKUI_FONT_WEIGHT_W200  | 200 | 
| ARKUI_FONT_WEIGHT_W300  | 300 | 
| ARKUI_FONT_WEIGHT_W400  | 400 | 
| ARKUI_FONT_WEIGHT_W500  | 500 | 
| ARKUI_FONT_WEIGHT_W600  | 600 | 
| ARKUI_FONT_WEIGHT_W700  | 700 | 
| ARKUI_FONT_WEIGHT_W800  | 800 | 
| ARKUI_FONT_WEIGHT_W900  | 900 | 
| ARKUI_FONT_WEIGHT_BOLD  | 字体较粗。 | 
| ARKUI_FONT_WEIGHT_NORMAL  | 字体粗细正常 | 
| ARKUI_FONT_WEIGHT_BOLDER  | 字体非常粗。 | 
| ARKUI_FONT_WEIGHT_LIGHTER  | 字体较细。 | 
| ARKUI_FONT_WEIGHT_MEDIUM  | 字体粗细适中。 | 
| ARKUI_FONT_WEIGHT_REGULAR  | 字体粗细正常 | 


### ArkUI_HitTestMode

```
enum ArkUI_HitTestMode
```
**描述：**

触摸测试控制枚举值。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_HIT_TEST_MODE_DEFAULT  | 默认触摸测试效果。 | 
| ARKUI_HIT_TEST_MODE_BLOCK  | 自身响应触摸测试。 | 
| ARKUI_HIT_TEST_MODE_TRANSPARENT  | 自身和子节点都响应触摸测试。 | 
| ARKUI_HIT_TEST_MODE_NONE  | 自身不响应触摸测试。 | 


### ArkUI_HorizontalAlignment

```
enum ArkUI_HorizontalAlignment
```
**描述：**

定义语言方向对齐方式。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_HORIZONTAL_ALIGNMENT_START  | 按照语言方向起始端对齐。 | 
| ARKUI_HORIZONTAL_ALIGNMENT_CENTER  | 居中对齐，默认对齐方式。 | 
| ARKUI_HORIZONTAL_ALIGNMENT_END  | 按照语言方向末端对齐。 | 


### ArkUI_ImageInterpolation

```
enum ArkUI_ImageInterpolation
```
**描述：**

定义图片插值效果。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_IMAGE_INTERPOLATION_NONE  | 不使用图片插值。 | 
| ARKUI_IMAGE_INTERPOLATION_LOW  | 低图片插值。 | 
| ARKUI_IMAGE_INTERPOLATION_MEDIUM  | 中图片插值。 | 
| ARKUI_IMAGE_INTERPOLATION_HIGH  | 高图片插值，插值质量最高。 | 


### ArkUI_ImageRepeat

```
enum ArkUI_ImageRepeat
```
**描述：**

定义图片重复铺设枚举值。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_IMAGE_REPEAT_NONE  | 不重复。 | 
| ARKUI_IMAGE_REPEAT_X  | 在X轴方向重复。 | 
| ARKUI_IMAGE_REPEAT_Y  | 在Y轴方向重复。 | 
| ARKUI_IMAGE_REPEAT_XY  | 在X轴和Y轴方向重复。 | 


### ArkUI_ImageSize

```
enum ArkUI_ImageSize
```
**描述：**

定义图片宽高样式。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_IMAGE_SIZE_AUTO  | 保持原图的比例不变。 | 
| ARKUI_IMAGE_SIZE_COVER  | 默认值，保持宽高比进行缩小或者放大，使得图片两边都大于或等于显示边界。 | 
| ARKUI_IMAGE_SIZE_CONTAIN  | 保持宽高比进行缩小或者放大，使得图片完全显示在显示边界内。 | 


### ArkUI_ImageSpanAlignment

```
enum ArkUI_ImageSpanAlignment
```
**描述：**

定义图片基于文本的对齐方式。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_IMAGE_SPAN_ALIGNMENT_BASELINE  | 图片下边沿与文本BaseLine对齐。 | 
| ARKUI_IMAGE_SPAN_ALIGNMENT_BOTTOM  | 图片下边沿与文本下边沿对齐。 | 
| ARKUI_IMAGE_SPAN_ALIGNMENT_CENTER  | 图片中间与文本中间对齐。 | 
| ARKUI_IMAGE_SPAN_ALIGNMENT_TOP  | 图片上边沿与文本上边沿对齐。 | 


### ArkUI_ItemAlignment

```
enum ArkUI_ItemAlignment
```
**描述：**

设置子组件在父容器交叉轴的对齐格式枚举值。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_ITEM_ALIGNMENT_AUTO  | 使用Flex容器中默认配置。 | 
| ARKUI_ITEM_ALIGNMENT_START  | 元素在Flex容器中，交叉轴方向首部对齐。 | 
| ARKUI_ITEM_ALIGNMENT_CENTER  | 元素在Flex容器中，交叉轴方向居中对齐。 | 
| ARKUI_ITEM_ALIGNMENT_END  | 元素在Flex容器中，交叉轴方向底部对齐。 | 
| ARKUI_ITEM_ALIGNMENT_STRETCH  | 元素在Flex容器中，交叉轴方向拉伸填充。 | 
| ARKUI_ITEM_ALIGNMENT_BASELINE  | 元素在Flex容器中，交叉轴方向文本基线对齐。 | 


### ArkUI_LinearGradientDirection

```
enum ArkUI_LinearGradientDirection
```
**描述：**

定义渐变方向结构。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_LINEAR_GRADIENT_DIRECTION_LEFT  | 向左渐变。 | 
| ARKUI_LINEAR_GRADIENT_DIRECTION_TOP  | 向上渐变。 | 
| ARKUI_LINEAR_GRADIENT_DIRECTION_RIGHT  | 向右渐变。 | 
| ARKUI_LINEAR_GRADIENT_DIRECTION_BOTTOM  | 向下渐变。 | 
| ARKUI_LINEAR_GRADIENT_DIRECTION_LEFT_TOP  | 向左上渐变。 | 
| ARKUI_LINEAR_GRADIENT_DIRECTION_LEFT_BOTTOM  | 向左下渐变。 | 
| ARKUI_LINEAR_GRADIENT_DIRECTION_RIGHT_TOP  | 向右上渐变。 | 
| ARKUI_LINEAR_GRADIENT_DIRECTION_RIGHT_BOTTOM  | 向右下渐变。 | 
| ARKUI_LINEAR_GRADIENT_DIRECTION_NONE  | 不渐变。 | 


### ArkUI_MaskType

```
enum ArkUI_MaskType
```
**描述：**

遮罩类型枚举。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_MASK_TYPE_RECTANGLE  | 矩形类型。 | 
| ARKUI_MASK_TYPE_CIRCLE  | 圆形类型。 | 
| ARKUI_MASK_TYPE_ELLIPSE  | 椭圆形类型。 | 
| ARKUI_MASK_TYPE_PATH  | 路径类型。 | 
| ARKUI_MASK_TYPE_PROGRESS  | 进度类型。 | 


### ArkUI_NativeAPIVariantKind

```
enum ArkUI_NativeAPIVariantKind
```
**描述：**

定义Native接口集合类型。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_NATIVE_NODE  | UI组件相关接口类型。 | 
### ArkUI_NativeNodeAPIVersion

```
enum ArkUI_NativeNodeAPIVersion
```
**描述：**

定义ARKUI_NATIVE_NODE类型支持的版本号信息。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_NATIVE_NODE_VERSION_1  | ARKUI_NATIVE_NODE类型支持版本1的结构体[ArkUI_NativeNodeAPI_1](_ark_u_i___native_node_a_p_i__1.md)。 | 


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
| NODE_FOCUSABLE  | 获焦属性，支持属性设置，属性重置和属性获取。<br/>属性设置方法[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)参数格式：<br/>.value[0].i32：参数类型为1或者0。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：参数类型为1或者0。 | 
| NODE_DEFAULT_FOCUS  | 默认焦点属性，支持属性设置，属性重置和属性获取。<br/>属性设置方法[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)参数格式：<br/>value[0].i32：参数类型为1或者0。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>value[0].i32：参数类型为1或者0。 | 
| NODE_RESPONSE_REGION  | 触摸热区属性，支持属性设置，属性重置和属性获取。<br/>属性设置方法[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)参数格式：<br/>.data[0].f32：触摸点相对于组件左上角的x轴坐标,单位为vp。<br/>.data[1].f32：触摸点相对于组件左上角的y轴坐标,单位为vp。<br/>.data[2].f32：触摸热区的宽度 ，单位为。<br/>.data[3].f32：触摸热区的高度，单位为。<br/>.data[4...].f32:可以设置多个手势响应区域，顺序和上述一致。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.data[0].f32：触摸点相对于组件左上角的x轴坐标,单位为vp。<br/>.data[1].f32：触摸点相对于组件左上角的y轴坐标,单位为vp。<br/>.data[2].f32：触摸热区的宽度 ，单位为。<br/>.data[3].f32：触摸热区的高度，单位为。<br/>.data[4...].f32:可以设置多个手势响应区域，顺序和上述一致。 | 
| NODE_OVERLAY  | 遮罩文本属性，支持属性设置，属性重置和属性获取。<br/>属性设置方法[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)参数格式：<br/>.string 遮罩文本；<br/>.value[0]?.i32：可选值，浮层相对于组件的位置，参数类型[ArkUI_Alignment](#arkui_alignment)， 默认值为ARKUI_ALIGNMENT_TOP_START。<br/>.value[1]?.f32：可选值，浮层基于自身左上角的偏移量X，单位为vp。<br/>.value[2]?.f32：可选值，浮层基于自身左上角的偏移量Y，单位为vp。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.string 遮罩文本；<br/>.value[0].i32：浮层相对于组件的位置，参数类型[ArkUI_Alignment](#arkui_alignment)， 默认值为ARKUI_ALIGNMENT_TOP_START。<br/>.value[1].f32：浮层基于自身左上角的偏移量X，单位为vp。<br/>.value[2].f32：浮层基于自身左上角的偏移量Y，单位为vp。 | 
| NODE_SWEEP_GRADIENT  | 角度渐变效果，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0]?.f32:为角度渐变的中心点，即相对于当前组件左上角的坐标,X轴坐标<br/>.value[1]?.f32:为角度渐变的中心点，即相对于当前组件左上角的坐标,Y轴坐标<br/>.value[2]?.f32:角度渐变的起点，默认值0。<br/>.value[3]?.f32:角度渐变的终点，默认值0。<br/>.value[4]?.f32:角度渐变的旋转角度，默认值0。<br/>.value[5]?.i32:为渐变的颜色重复着色，0表示不重复着色，1表示重复着色<br/>.object: 指定某百分比位置处的渐变色颜色，设置非法颜色直接跳过：<br/>colors：渐变色颜色颜色。<br/>stops：渐变位置。<br/>size：颜色个数。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32:为角度渐变的中心点，即相对于当前组件左上角的坐标,X轴坐标<br/>.value[1].f32:为角度渐变的中心点，即相对于当前组件左上角的坐标,Y轴坐标<br/>.value[2].f32:角度渐变的起点，默认值0。<br/>.value[3].f32:角度渐变的终点，默认值0。<br/>.value[4].f32:角度渐变的旋转角度，默认值0。<br/>.value[5].i32:为渐变的颜色重复着色，0表示不重复着色，1表示重复着色<br/>.object: 指定某百分比位置处的渐变色颜色，设置非法颜色直接跳过：<br/>colors：渐变色颜色颜色。<br/>stops：渐变位置。<br/>size：颜色个数。 | 
| NODE_RADIAL_GRADIENT  | 径向渐变渐变效果，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0]?.f32:为径向渐变的中心点，即相对于当前组件左上角的坐标,X轴坐标<br/>.value[1]?.f32:为径向渐变的中心点，即相对于当前组件左上角的坐标,Y轴坐标<br/>.value[2]?.f32:径向渐变的半径，默认值0。<br/>.value[3]?.i32:为渐变的颜色重复着色，0表示不重复着色，1表示重复着色<br/>.object: 指定某百分比位置处的渐变色颜色，设置非法颜色直接跳过：<br/>colors：渐变色颜色颜色。<br/>stops：渐变位置。<br/>size：颜色个数。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32:为径向渐变的中心点，即相对于当前组件左上角的坐标,X轴坐标<br/>.value[1].f32:为径向渐变的中心点，即相对于当前组件左上角的坐标,Y轴坐标<br/>.value[2].f32:径向渐变的半径，默认值0。<br/>.value[3].i32:为渐变的颜色重复着色，0表示不重复着色，1表示重复着色<br/>.object: 指定某百分比位置处的渐变色颜色，设置非法颜色直接跳过：<br/>colors：渐变色颜色颜色。<br/>stops：渐变位置。<br/>size：颜色个数。 | 
| NODE_MASK  | 组件上加上指定形状的遮罩，支持属性设置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式,共有5种类型：<br/>1.rect类型：<br/>.value[0].u32：填充颜色，0xargb类型；<br/>.value[1].u32：描边颜色，0xargb类型；<br/>.value[2].f32：描边宽度，单位为vp；<br/>.value[3].i32：遮罩类型，参数类型[ArkUI_MaskType](#arkui_masktype)，ARKUI_MASK_TYPE_RECTANGLE；<br/>.value[4].f32：矩形宽度；<br/>.value[5].f32：矩形高度；<br/>.value[6].f32：矩形圆角宽度；<br/>.value[7].f32：矩形圆角高度；<br/>2.circle类型：<br/>.value[0].u32：填充颜色，0xargb类型；<br/>.value[1].u32：描边颜色，0xargb类型；<br/>.value[2].f32：描边宽度，单位为vp；<br/>.value[3].i32：遮罩类型，参数类型[ArkUI_MaskType](#arkui_masktype)，ARKUI_MASK_TYPE_CIRCLE；<br/>.value[4].f32：圆形宽度；<br/>.value[5].f32：圆形高度；<br/>3.ellipse类型：<br/>.value[0].u32：填充颜色，0xargb类型；<br/>.value[1].u32：描边颜色，0xargb类型；<br/>.value[2].f32：描边宽度，单位为vp；<br/>.value[3].i32：遮罩类型，参数类型[ArkUI_MaskType](#arkui_masktype)，ARKUI_MASK_TYPE_ELLIPSE；<br/>.value[4].f32：椭圆形宽度；<br/>.value[5].f32：椭圆形高度；<br/>4.path类型：<br/>.value[0].u32：填充颜色，0xargb类型；<br/>.value[1].u32：描边颜色，0xargb类型；<br/>.value[2].f32：描边宽度，单位为vp；<br/>.value[3].i32：遮罩类型，参数类型[ArkUI_MaskType](#arkui_masktype)，ARKUI_MASK_TYPE_PATH；<br/>.value[4].f32：路径宽度；<br/>.value[5].f32：路径高度；<br/>.string：路径绘制的命令字符串；<br/>4.progress类型：<br/>.value[0].u32：填充颜色，0xargb类型；<br/>.value[1].u32：描边颜色，0xargb类型；<br/>.value[2].f32：描边宽度，单位为vp；<br/>.value[3].i32：遮罩类型，参数类型[ArkUI_MaskType](#arkui_masktype)，ARKUI_MASK_TYPE_PROSGRESS；<br/>.value[4].f32：进度遮罩的当前值；<br/>.value[5].f32：进度遮罩的最大值；<br/>.value[6].u32：进度遮罩的颜色；<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式,共有5种类型：<br/>1.rect类型：<br/>.value[0].u32：填充颜色，0xargb类型；<br/>.value[1].u32：描边颜色，0xargb类型；<br/>.value[2].f32：描边宽度，单位为vp；<br/>.value[3].i32：遮罩类型；<br/>.value[4].f32：矩形宽度；<br/>.value[5].f32：矩形高度；<br/>.value[6].f32：矩形圆角宽度；<br/>.value[7].f32：矩形圆角高度；<br/>2.circle类型：<br/>.value[0].u32：填充颜色，0xargb类型；<br/>.value[1].u32：描边颜色，0xargb类型；<br/>.value[2].f32：描边宽度，单位为vp；<br/>.value[3].i32：遮罩类型；<br/>.value[4].f32：圆形宽度；<br/>.value[5].f32：圆形高度；<br/>3.ellipse类型：<br/>.value[0].u32：填充颜色，0xargb类型；<br/>.value[1].u32：描边颜色，0xargb类型；<br/>.value[2].f32：描边宽度，单位为vp；<br/>.value[3].i32：遮罩类型；<br/>.value[4].f32：椭圆形宽度；<br/>.value[5].f32：椭圆形高度；<br/>4.path类型：<br/>.value[0].u32：填充颜色，0xargb类型；<br/>.value[1].u32：描边颜色，0xargb类型；<br/>.value[2].f32：描边宽度，单位为vp；<br/>.value[3].i32：遮罩类型；<br/>.value[4].f32：路径宽度；<br/>.value[5].f32：路径高度；<br/>.string：路径绘制的命令字符串；<br/>4.progress类型：<br/>.value[0].i32：遮罩类型；<br/>.value[1].f32：进度遮罩的当前值；<br/>.value[2].f32：进度遮罩的最大值；<br/>.value[3].u32：进度遮罩的颜色； | 
| NODE_BLEND_MODE  | 当前控件背景与子节点内容进行混合，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：控制当前组件的混合模式类型，参数类型[ArkUI_BlendMode](#arkui_blendmode)，默认值为ARKUI_BLEND_MODE_NONE。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：控制当前组件的混合模式类型，参数类型[ArkUI_BlendMode](#arkui_blendmode)，默认值为ARKUI_BLEND_MODE_NONE。 | 
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
| NODE_TEXT_OVERFLOW  | 文本超长时的显示方式属性，支持属性设置，属性重置，属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：表示文本超长时的显示方式。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：表示文本超长时的显示方式。 | 
| NODE_FONT_FAMILY  | Text字体列表属性，支持属性设置，属性重置和属性获取。<br/>属性设置方法[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)参数格式：<br/>.string：字体字符串，多个用,分隔。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.string：字体字符串，多个用,分隔。 | 
| NODE_TEXT_COPY_OPTION  | 文本复制粘贴属性，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：复制粘贴方式[ArkUI_CopyOptions](#arkui_copyoptions)，默认值为ARKUI_COPY_OPTIONS_NONE；<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：复制粘贴方式[ArkUI_CopyOptions](#arkui_copyoptions)。 | 
| NODE_TEXT_BASELINE_OFFSET  | 文本基线的偏移量属性，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32：偏移量数值，单位为fp；<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32：偏移量数值，单位为fp。 | 
| NODE_TEXT_TEXT_SHADOW  | 文字阴影效果属性，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32：阴影模糊半径，单位为vp；<br/>.value[1].i32：阴影类型[ArkUI_ShadowType](#arkui_shadowtype)，默认值为ARKUI_SHADOW_TYPE_COLOR；<br/>.value[2].u32：阴影颜色，0xargb格式，形如 0xFFFF0000 表示红色；<br/>.value[3].f32：阴影X轴偏移量，单位为vp；<br/>.value[4].f32：阴影Y轴偏移量，单位为vp；<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32：阴影模糊半径，单位为vp；<br/>.value[1].i32：阴影类型[ArkUI_ShadowType](#arkui_shadowtype)；<br/>.value[2].u32：阴影颜色，0xargb格式；<br/>.value[3].f32：阴影X轴偏移量，单位为vp；<br/>.value[4].f32：阴影Y轴偏移量，单位为vp； | 
| NODE_TEXT_MIN_FONT_SIZE  | Text最小显示字号，支持属性设置，属性重置和属性获取。<br/>属性设置方法[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)参数格式：<br/>.value[0].f32：文本最小显示字号，单位FP。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32：文本最小显示字号，单位FP。 | 
| NODE_TEXT_MAX_FONT_SIZE  | Text最大显示字号，支持属性设置，属性重置和属性获取。<br/>属性设置方法[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)参数格式：<br/>.value[0].f32：文本最大显示字号 单位FP。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32：文本最大显示字号 单位FP。 | 
| NODE_TEXT_FONT  | Text样式，支持属性设置，属性重置和属性获取。<br/>属性设置方法[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)参数格式：<br/>.string?：可选值 字体列表，使用多个字体，使用','进行分割。<br/>.value[0].f32：文本尺寸 单位FP。<br/>.value[1]?.i32：可选值，文本的字体粗细，参数类型[ArkUI_FontWeight](#arkui_fontweight)。 默认值为ARKUI_FONT_WEIGHT_NORMAL。<br/>.value[2]?.i32：可选值，字体样式，参数类型[ArkUI_FontStyle](#arkui_fontstyle)。 默认值为ARKUI_FONT_STYLE_NORMAL。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.string：字体列表，使用多个字体，使用','进行分割。<br/>.value[0].f32：文本尺寸 单位FP。<br/>.value[1].i32：文本的字体粗细，参数类型[ArkUI_FontWeight](#arkui_fontweight)。 默认值为ARKUI_FONT_WEIGHT_NORMAL。<br/>.value[2].i32：字体样式，参数类型[ArkUI_FontStyle](#arkui_fontstyle)。 默认值为ARKUI_FONT_STYLE_NORMAL。 | 
| NODE_TEXT_HEIGHT_ADAPTIVE_POLICY  | Text自适应高度的方式，支持属性设置，属性重置和属性获取。<br/>属性设置方法[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)参数格式：<br/>.value[0].i32：参数类型[ArkUI_TextHeightAdaptivePolicy](#arkui_textheightadaptivepolicy)。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：参数类型[ArkUI_TextHeightAdaptivePolicy](#arkui_textheightadaptivepolicy)。 | 
| NODE_TEXT_INDENT  | 文本首行缩进属性，支持属性设置，属性重置，属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32: 表示首行缩进值。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32: 表示首行缩进值。 | 
| NODE_SPAN_CONTENT  | 文本内容属性，支持属性设置，属性重置，属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.string 表示span的文本内容。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.string 表示span的文本内容。 | 
| NODE_IMAGE_SPAN_SRC  | imageSpan组件图片地址属性，支持属性设置，属性重置，属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.string 表示imageSpan的图片地址<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.string 表示imageSpan的图片地址 | 
| NODE_IMAGE_SPAN_VERTICAL_ALIGNMENT  | 图片基于文本的对齐方式属性，支持属性设置，属性重置，属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32 表示图片基于文本的对齐方式，取[ArkUI_ImageSpanAlignment](#arkui_imagespanalignment)枚举值。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32 表示图片基于文本的对齐方式，取[ArkUI_ImageSpanAlignment](#arkui_imagespanalignment)枚举值。 | 
| NODE_IMAGE_SRC  | image组件设置图片地址属性，支持属性设置，属性重置，属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.string 表示image组件地址<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.string 表示image组件地址 | 
| NODE_IMAGE_OBJECT_FIT  | 图片填充效果属性，支持属性设置，属性重置，属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32 表示图片填充效果，取[ArkUI_ObjectFit](#arkui_objectfit)枚举值。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32 表示图片填充效果，取[ArkUI_ObjectFit](#arkui_objectfit)枚举值。 | 
| NODE_IMAGE_INTERPOLATION  | 图片插值效果效果属性，支持属性设置，属性重置，属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32 表示插值效果效果，取[ArkUI_ImageInterpolation](#arkui_imageinterpolation)枚举值。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32 表示插值效果效果，取[ArkUI_ImageInterpolation](#arkui_imageinterpolation)枚举值。 | 
| NODE_IMAGE_OBJECT_REPEAT  | 图片重复样式属性，支持属性设置，属性重置，属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32 表示图片重复样式，取[ArkUI_ImageRepeat](#arkui_imagerepeat)枚举值。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32 表示图片重复样式，取[ArkUI_ImageRepeat](#arkui_imagerepeat)枚举值。 | 
| NODE_IMAGE_COLOR_FILTER  | 图片滤镜效果属性，支持属性设置，属性重置，属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32 ~ .value[19].i32 表示滤镜矩阵数组。<br/>.size 表示滤镜数组大小 5\*4。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32 ~ .value[19].i32 表示滤镜矩阵数组。<br/>.size 表示滤镜数组大小 5\*4。 | 
| NODE_IMAGE_AUTO_RESIZE  | 图源自动缩放属性，支持属性设置，属性重置，属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32 表示是否缩放布尔值。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32 表示是否缩放布尔值。 | 
| NODE_IMAGE_ALT  | 占位图地址属性，支持属性设置，属性重置，属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.string 表示image组件占位图地址。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.string 表示image组件占位图地址。 | 
| NODE_TOGGLE_SELECTED_COLOR  | 组件打开状态的背景颜色属性，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].u32：背景色数值，0xargb格式，形如 0xFFFF0000 表示红色。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].u32：背景色数值，0xargb格式。 | 
| NODE_TOGGLE_SWITCH_POINT_COLOR  | Switch类型的圆形滑块颜色属性，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].u32：圆形滑块颜色数值，0xargb格式，形如 0xFFFF0000 表示红色。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].u32：圆形滑块颜色数值，0xargb格式。 | 
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
| NODE_TEXT_AREA_PLACEHOLDER  | 多行文本输入框的默认提示文本内容属性，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.string：默认提示文本的内容。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.string：默认提示文本的内容。 | 
| NODE_TEXT_AREA_TEXT  | 多行文本输入框的默认文本内容属性，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.string：默认文本的内容。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.string：默认文本的内容。 | 
| NODE_TEXT_AREA_MAX_LENGTH  | 输入框支持的最大文本数属性，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：最大文本数的数字。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：最大文本数的数字。 | 
| NODE_TEXT_AREA_PLACEHOLDER_COLOR  | 无输入时默认提示文本的颜色属性，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].u32：颜色数值，0xargb格式，形如 0xFFFF0000 表示红色。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].u32：颜色数值，0xargb格式。 | 
| NODE_TEXT_AREA_PLACEHOLDER_FONT  | 无输入时默认提示文本的字体配置（包括大小、字重、样式、字体列表）属性，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0]?.f32：可选字体大小数值，默认值16.0，单位为fp；<br/>.value[1]?.i32：可选字体样式[ArkUI_FontStyle](#arkui_fontstyle)，默认值为ARKUI_FONT_STYLE_NORMAL；<br/>.value[2]?.i32：可选字体粗细样式[ArkUI_FontWeight](#arkui_fontweight)，默认值为ARKUI_FONT_WEIGHT_NORMAL；<br/>?.string: 字体族内容，多个字体族之间使用逗号分隔，形如“字重；字体族1，字体族2”。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].f32：字体大小数值，单位为fp；<br/>.value[1].i32：字体样式[ArkUI_FontStyle](#arkui_fontstyle)；<br/>.value[2].i32：字体粗细样式[ArkUI_FontWeight](#arkui_fontweight)；<br/>.string: 字体族内容，多个字体族之间使用逗号分隔。 | 
| NODE_TEXT_AREA_CARET_COLOR  | 光标颜色属性，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].u32：背景色数值，0xargb格式，形如 0xFFFF0000 表示红色。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].u32：背景色数值，0xargb格式。 | 
| NODE_TEXT_AREA_EDITING  | 控制多行文本输入框编辑态属性，支持属性设置。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：false表示退出编辑态，true表示维持现状。<br/>属性获取方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：false表示退出编辑态，true表示维持现状。 | 
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
| NODE_LIST_ITEM_GROUP_SET_HEADER  | 设置 ListItemGroup 头部组件，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.object：使用[ArkUI_NodeHandle](#arkui_nodehandle)对象作为ListItemGroup头部组件。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.object：使用[ArkUI_NodeHandle](#arkui_nodehandle)对象作为ListItemGroup头部组件。 | 
| NODE_LIST_ITEM_GROUP_SET_FOOTER  | 设置 ListItemGroup 尾部组件，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.object：使用[ArkUI_NodeHandle](#arkui_nodehandle)对象作为ListItemGroup尾部组件。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.object：使用[ArkUI_NodeHandle](#arkui_nodehandle)对象作为ListItemGroup尾部组件。 | 
| NODE_LIST_ITEM_GROUP_SET_DIVIDER  | 设置ListItem分割线样式，默认无分割线，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].u32： 颜色，0xargb类型；<br/>.value[1].f32： 分割线宽，单位vp；<br/>.value[2].f32： 分割线距离列表侧边起始端的距离，单位vp；<br/>.value[3].f32： 分割线距离列表侧边结束端的距离，单位vp。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].u32： 颜色，0xargb类型；<br/>.value[1].f32： 分割线宽，单位vp；<br/>.value[2].f32： 分割线距离列表侧边起始端的距离，单位vp；<br/>.value[3].f32： 分割线距离列表侧边结束端的距离，单位vp。 | 
| NODE_COLUMN_ALIGN_ITEMS  | 设置Column子组件在水平方向上的对齐格式，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：子组件在水平方向上的对齐格式，数据类型[ArkUI_HorizontalAlignment](#arkui_horizontalalignment)，<br/>默认值ARKUI_HORIZONTAL_ALIGNMENT_CENTER。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：子组件在水平方向上的对齐格式，数据类型[ArkUI_HorizontalAlignment](#arkui_horizontalalignment)。 | 
| NODE_COLUMN_JUSTIFY_CONTENT  | 设置Column子组件在垂直方向上的对齐格式，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：子组件在垂直方向上的对齐格式，数据类型[ArkUI_FlexAlignment](#arkui_flexalignment)，<br/>默认值ARKUI_FLEX_ALIGNMENT_START。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：子组件在垂直方向上的对齐格式，数据类型[ArkUI_FlexAlignment](#arkui_flexalignment)。 | 
| NODE_ROW_ALIGN_ITEMS  | 设置Row子组件在垂直方向上的对齐格式，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：子组件在垂直方向上的对齐格式，数据类型[ArkUI_VerticalAlignment](#arkui_verticalalignment)，<br/>默认值ARKUI_VERTICAL_ALIGNMENT_CENTER。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：子组件在垂直方向上的对齐格式，数据类型[ArkUI_VerticalAlignment](#arkui_verticalalignment)。 | 
| NODE_ROW_JUSTIFY_CONTENT  | 设置Row子组件在水平方向上的对齐格式，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：子组件在水平方向上的对齐格式，数据类型[ArkUI_FlexAlignment](#arkui_flexalignment)，<br/>默认值ARKUI_FLEX_ALIGNMENT_START。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：子组件在水平方向上的对齐格式，数据类型[ArkUI_FlexAlignment](#arkui_flexalignment)。 | 
| NODE_FLEX_OPTION  | 设置Flex属性，支持属性设置，属性重置和属性获取接口。<br/>属性设置方法参数[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0]?.i32：子组件在Flex容器上排列的方向[ArkUI_FlexDirection](#arkui_flexdirection)，默认值为ARKUI_FLEX_DIRECTION_ROW；<br/>.value[1]?.i32：排列规则[ArkUI_FlexWrap](#arkui_flexwrap)，默认值为ARKUI_FLEX_WRAP_NO_WRAP；<br/>.value[2]?.i32：主轴上的对齐格式[ArkUI_FlexAlignment](#arkui_flexalignment)，默认值为ARKUI_FLEX_ALIGNMENT_START；<br/>.value[3]?.i32：交叉轴上的对齐格式[ArkUI_ItemAlignment](#arkui_itemalignment)，默认值为ARKUI_ITEM_ALIGNMENT_START；<br/>.value[4]?.i32： 交叉轴中有额外的空间时，多行内容的对齐方式[ArkUI_FlexAlignment](#arkui_flexalignment)，默认值为ARKUI_FLEX_ALIGNMENT_START；<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：子组件在Flex容器上排列的方向的枚举值；<br/>.value[1].i32：排列规则的枚举值；<br/>.value[2].i32：主轴上的对齐格式的枚举值；<br/>.value[3].i32：交叉轴上的对齐格式的枚举值；<br/>.value[4].i32： 交叉轴中有额外的空间时，多行内容的对齐方式的枚举值； | 
| NODE_REFRESH_REFRESHING  | 设置组件是否正在刷新，支持属性设置，属性获取。<br/>属性设置方法[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)参数格式：<br/>.value[0].i32：参数类型为1或者0。<br/>属性获取方法返回值[ArkUI_AttributeItem](_ark_u_i___attribute_item.md)格式：<br/>.value[0].i32：参数类型为1或者0。 | 


### ArkUI_NodeDirtyFlag

```
enum ArkUI_NodeDirtyFlag
```
**描述：**

自定义组件调用&lt;b&gt;::markDirty是传递的藏区标识类型。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| NODE_NEED_MEASURE  | 重新测算大小。<br/>该flag类型触发时，同时也默认会触发重新布局。 | 
| NODE_NEED_LAYOUT  | 重新布局位置。 | 
| NODE_NEED_RENDER  | 重新进行绘制。 | 


### ArkUI_NodeEventType

```
enum ArkUI_NodeEventType
```
**描述：**

提供NativeNode组件支持的事件类型定义。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| NODE_TOUCH_EVENT  | 手势事件类型。<br/>事件回调发生时，事件参数[ArkUI_NodeEvent](_ark_u_i___node_event.md)对象中的联合体类型为**ArkUI_TouchEvent**。 | 
| NODE_EVENT_ON_APPEAR  | 挂载事件。<br/>触发该事件的条件 ：组件挂载显示时触发此回调。<br/>事件回调发生时，事件参数[ArkUI_NodeEvent](_ark_u_i___node_event.md)对象中的联合体类型为[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)。<br/>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)中不包含参数。 | 
| NODE_EVENT_ON_AREA_CHANGE  | 组件区域变化事件<br/>触发该事件的条件：组件区域变化时触发该回调。<br/>事件回调发生时，事件参数[ArkUI_NodeEvent](_ark_u_i___node_event.md)对象中的联合体类型为[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)。<br/>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)中包含12个参数：<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].f32**：表示过去目标元素的宽度，类型为number，单位vp。<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[1].f32**：表示过去目标元素的高度，类型为number，单位vp。<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[2].f32**：表示过去目标元素左上角相对父元素左上角的位置的x轴坐标，类型为number，单位vp。<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[3].f32**：表示过去目标元素左上角相对父元素左上角的位置的y轴坐标，类型为number，单位vp。<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[4].f32**：表示过去目标元素目标元素左上角相对页面左上角的位置的x轴坐标，类型为number，单位vp。<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[5].f32**：表示过去目标元素目标元素左上角相对页面左上角的位置的y轴坐标，类型为number，单位vp。<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[6].f32**：表示最新目标元素的宽度，类型为number，单位vp。<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[7].f32**：表示最新目标元素的高度，类型为number，单位vp。<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[8].f32**：表示最新目标元素左上角相对父元素左上角的位置的x轴坐标，类型为number，单位vp。<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[9].f32**：表示最新目标元素左上角相对父元素左上角的位置的y轴坐标，类型为number，单位vp。<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[10].f32**：表示最新目标元素目标元素左上角相对页面左上角的位置的x轴坐标，类型为number，单位vp。<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[11].f32**：表示最新目标元素目标元素左上角相对页面左上角的位置的y轴坐标，类型为number，单位vp。 | 
| NODE_ON_FOCUS  | 获焦事件。<br/>触发该事件的条件：组件获焦时触发此回调。<br/>事件回调发生时，事件参数[ArkUI_NodeEvent](_ark_u_i___node_event.md)对象中的联合体类型为[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)。<br/>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)中不包含参数。 | 
| NODE_ON_BLUR  | 失去焦点事件。<br/>触发该事件的条件：组件失去焦点时触发此回调。<br/>事件回调发生时，事件参数[ArkUI_NodeEvent](_ark_u_i___node_event.md)对象中的联合体类型为[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)。<br/>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)中不包含参数。 | 
| NODE_ON_CLICK  | 组件点击事件。<br/>触发该事件的条件：组件被点击时触发此回调。<br/>事件回调发生时，事件参数[ArkUI_NodeEvent](_ark_u_i___node_event.md)对象中的联合体类型为[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)。<br/>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)中包含12个参数：<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].f32**：点击位置相对于被点击元素原始区域左上角的X坐标，单位vp。<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[1].f32**：点击位置相对于被点击元素原始区域左上角的Y坐标，单位vp。<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[2].f32**：事件时间戳。触发事件时距离系统启动的时间间隔，单位微妙。<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[3].i32**：事件输入设备，1表示鼠标，2表示触屏，4表示按键。<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[4].f32**：点击位置相对于应用窗口左上角的X坐标，单位vp。<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[5].f32**：点击位置相对于应用窗口左上角的Y坐标，单位vp。<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[6].f32**：点击位置相对于应用屏幕左上角的X坐标，单位vp。<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[7].f32**：点击位置相对于应用屏幕左上角的Y坐标，单位vp。 | 
| NODE_IMAGE_ON_COMPLETE  | 图片加载成功事件。<br/>触发该事件的条件 ：图片数据加载成功和解码成功均触发该回调。<br/>事件回调发生时，事件参数[ArkUI_NodeEvent](_ark_u_i___node_event.md)对象中的联合体类型为[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)。<br/>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)中包含9个参数：<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].i32**：表示加载状态，0表示数据加载成功，1表示解码成功。<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[1].f32**：表示图片的宽度，单位px。<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[2].f32**：表示图片的高度，单位px。<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[3].f32**：表示当前组件的宽度，单位px。<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[4].f32**：表示当前组件的高度，单位px。<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[5].f32**：图片绘制区域相对组件X轴位置，单位px。<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[6].f32**：图片绘制区域相对组件Y轴位置，单位px。<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[7].f32**：图片绘制区域宽度，单位px。<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[8].f32**：图片绘制区域高度，单位px。 | 
| NODE_IMAGE_ON_ERROR  | 图片加载失败事件。<br/>触发该事件的条件：图片加载异常时触发该回调。<br/>事件回调发生时，事件参数[ArkUI_NodeEvent](_ark_u_i___node_event.md)对象中的联合体类型为[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)。<br/>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)中包含1个参数：<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].i32**错误码信息：<br/>401: 图片路径参数异常，无法获取到图片数据。<br/>103101: 图片格式不支持。 | 
| NODE_IMAGE_ON_SVG_PLAY_FINISH  | SVG图片动效播放完成事件。<br/>触发该事件的条件：带动效的SVG图片动画结束时触发。<br/>事件回调发生时，事件参数[ArkUI_NodeEvent](_ark_u_i___node_event.md)对象中的联合体类型为[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)。<br/>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)中不包含参数。 | 
| NODE_TOGGLE_ON_CHANGE  | 开关状态发生变化时触发给事件。<br/>触发该事件的条件：开关状态发生变化。<br/>事件回调发生时，事件参数[ArkUI_NodeEvent](_ark_u_i___node_event.md)对象中的联合体类型为[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)。<br/>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)中包含1个参数：<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].i32**：当前开关状态，1表示开，0表示关。 | 
| NODE_TEXT_INPUT_ON_CHANGE  | textInput输入内容发生变化时触发该事件。<br/>触发该事件的条件：输入内容发生变化时。<br/>事件回调发生时，事件参数[ArkUI_NodeEvent](_ark_u_i___node_event.md)对象中的联合体类型为[ArkUI_StringAsyncEvent](_ark_u_i___string_async_event.md)。<br/>[ArkUI_StringAsyncEvent](_ark_u_i___string_async_event.md)中包含1个参数：<br/>**[ArkUI_StringAsyncEvent.pStr](_ark_u_i___string_async_event.md#pstr)**：输入的文本内容。 | 
| NODE_TEXT_INPUT_ON_SUBMIT  | textInput按下输入法回车键触发该事件。<br/>触发该事件的条件：按下输入法回车键。<br/>事件回调发生时，事件参数[ArkUI_NodeEvent](_ark_u_i___node_event.md)对象中的联合体类型为[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)。<br/>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)中包含1个参数：<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].i32**：输入法回车键类型。 | 
| NODE_TEXT_INPUT_ON_CUT  | 长按输入框内部区域弹出剪贴板后，点击剪切板剪切按钮，触发该回调。<br/>触发该事件的条件：长按输入框内部区域弹出剪贴板后，点击剪切板剪切按钮。<br/>事件回调发生时，事件参数[ArkUI_NodeEvent](_ark_u_i___node_event.md)对象中的联合体类型为[ArkUI_StringAsyncEvent](_ark_u_i___string_async_event.md)。<br/>[ArkUI_StringAsyncEvent](_ark_u_i___string_async_event.md)中包含1个参数：<br/>**[ArkUI_StringAsyncEvent.pStr](_ark_u_i___string_async_event.md#pstr)**：剪切的文本内容。 | 
| NODE_TEXT_INPUT_ON_PASTE  | 长按输入框内部区域弹出剪贴板后，点击剪切板粘贴按钮，触发该回调。<br/>触发该事件的条件：长按输入框内部区域弹出剪贴板后，点击剪切板粘贴按钮。<br/>事件回调发生时，事件参数[ArkUI_NodeEvent](_ark_u_i___node_event.md)对象中的联合体类型为[ArkUI_StringAsyncEvent](_ark_u_i___string_async_event.md)。<br/>[ArkUI_StringAsyncEvent](_ark_u_i___string_async_event.md)中包含1个参数：<br/>**[ArkUI_StringAsyncEvent.pStr](_ark_u_i___string_async_event.md#pstr)**：粘贴的文本内容。 | 
| NODE_TEXT_AREA_ON_CHANGE  | 输入内容发生变化时，触发该回调。<br/>触发该事件的条件：输入内容发生变化时。<br/>事件回调发生时，事件参数[ArkUI_NodeEvent](_ark_u_i___node_event.md)对象中的联合体类型为[ArkUI_StringAsyncEvent](_ark_u_i___string_async_event.md)。<br/>[ArkUI_StringAsyncEvent](_ark_u_i___string_async_event.md)中包含1个参数：<br/>**[ArkUI_StringAsyncEvent.pStr](_ark_u_i___string_async_event.md#pstr)**：当前输入的文本内容。 | 
| NODE_CHECKBOX_EVENT_ON_CHANGE  | 定义ARKUI_NODE_CHECKBOX当选中状态发生变化时，触发该回调。<br/>事件回调发生时，事件参数[ArkUI_NodeEvent](_ark_u_i___node_event.md)对象中的联合体类型为[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)。<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].i32**1:表示已选中, 0: 表示未选中 | 
| NODE_DATE_PICKER_EVENT_ON_DATE_CHANGE  | 定义ARKUI_NODE_DATE_PICKER列表组件的滚动触摸事件枚举值。<br/>触发该事件的条件：选择日期时触发该事件。<br/>事件回调发生时，事件参数[ArkUI_NodeEvent](_ark_u_i___node_event.md)对象中的联合体类型为[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)。<br/>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)中包含3个参数：<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].i32**：表示选中时间的年。<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[1].i32**：表示选中时间的月，取值范围：[0-11]。<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[2].i32**：表示选中时间的天。 | 
| NODE_TIME_PICKER_EVENT_ON_CHANGE  | 定义ARKUI_NODE_TIME_PICKER列表组件的滚动触摸事件枚举值。<br/>触发该事件的条件：选择时间时触发该事件。<br/>事件回调发生时，事件参数[ArkUI_NodeEvent](_ark_u_i___node_event.md)对象中的联合体类型为[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)。<br/>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)中包含2个参数：<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].i32**：表示选中时间的时，取值范围：[0-23]。<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[1].i32**：表示选中时间的分，取值范围：[0-59]。 | 
| NODE_TEXT_PICKER_EVENT_ON_CHANGE  | 定义ARKUI_NODE_TEXT_PICKER列表组件的滚动触摸事件枚举值。<br/>触发该事件的条件 ：选择时间时触发该事件。<br/>事件回调发生时，事件参数[ArkUI_NodeEvent](_ark_u_i___node_event.md)对象中的联合体类型为[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)。<br/>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)中包含1个参数：<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0...11].i32**表示选中数据的维度。 | 
| NODE_CALENDAR_PICKER_EVENT_ON_CHANGE  | 定义NODE_CALENDAR_PICKER选中日期时触发的事件。<br/>事件回调发生时，事件参数[ArkUI_NodeEvent](_ark_u_i___node_event.md)对象中的联合体类型为[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)。<br/>**ArkUI_NodeComponent.data[0].u32**选中的年。<br/>**ArkUI_NodeComponent.data[1].u32**选中的月。<br/>**ArkUI_NodeComponent.data[2].u32**选中的日。 | 
| NODE_SLIDER_EVENT_ON_CHANGE  | 定义ARKUI_NODE_SLIDER拖动或点击时触发事件回调。<br/>事件回调发生时，事件参数[ArkUI_NodeEvent](_ark_u_i___node_event.md)对象中的联合体类型为[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)。<br/>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)中包含2个参数：<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].f32**：当前滑动进度值。<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[1].i32**：事件触发的相关状态值 | 
| NODE_SCROLL_EVENT_ON_SCROLL  | 定义ARKUI_NODE_SCROLL滚动组件的滚动事件枚举值。<br/>触发该事件的条件 ：<br/>1、滚动组件触发滚动时触发，支持键鼠操作等其他触发滚动的输入设置。<br/>2、通过滚动控制器API接口调用。<br/>3、越界回弹。<br/>事件回调发生时，事件参数[ArkUI_NodeEvent](_ark_u_i___node_event.md)对象中的联合体类型为[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)。<br/>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)中包含2个参数：<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].f32**：表示距离上一次事件触发的X轴增量。<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[1].f32**：表示距离上一次事件触发的Y轴增量。 | 
| NODE_SCROLL_EVENT_ON_SCROLL_FRAME_BEGIN  | 定义ARKUI_NODE_SCROLL滚动组件的滚动帧始事件枚举值。<br/>触发该事件的条件 ：<br/>1、滚动组件触发滚动时触发，包括键鼠操作等其他触发滚动的输入设置。<br/>2、调用控制器接口时不触发。<br/>3、越界回弹不触发。<br/>事件回调发生时，事件参数[ArkUI_NodeEvent](_ark_u_i___node_event.md)对象中的联合体类型为[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)。<br/>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)中包含2个参数：<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].f32**：表示即将发生的滚动量。<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[1].i32**：表示当前滚动状态。<br/>**[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)**中包含1个返回值：<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].f32**：事件处理函数中可根据应用场景计算实际需要的滚动量并存于data[0].f32中，Scroll将按照返回值的实际滚动量进行滚动。 | 
| NODE_SCROLL_EVENT_ON_SCROLL_START  | 定义ARKUI_NODE_SCROLL滚动组件的滚动开始事件枚举值。<br/>触发该事件的条件 ：<br/>1、滚动组件开始滚动时触发，支持键鼠操作等其他触发滚动的输入设置。<br/>2、通过滚动控制器API接口调用后开始，带过渡动效。<br/>事件回调发生时，事件参数[ArkUI_NodeEvent](_ark_u_i___node_event.md)对象中的联合体类型为[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)。<br/>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)中不包含参数。 | 
| NODE_SCROLL_EVENT_ON_SCROLL_STOP  | 定义ARKUI_NODE_SCROLL滚动组件的滚动停止事件枚举值。<br/>触发该事件的条件 ：<br/>1、滚动组件触发滚动后停止，支持键鼠操作等其他触发滚动的输入设置。<br/>2、通过滚动控制器API接口调用后停止，带过渡动效。<br/>事件回调发生时，事件参数[ArkUI_NodeEvent](_ark_u_i___node_event.md)对象中的联合体类型为[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)。<br/>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)中不包含参数。 | 
| NODE_SCROLL_EVENT_ON_SCROLL_EDGE  | 定义ARKUI_NODE_SCROLL滚动组件的滚动边缘事件枚举值。<br/>触发该事件的条件 ：<br/>1、滚动组件滚动到边缘时触发，支持键鼠操作等其他触发滚动的输入设置。<br/>2、通过滚动控制器API接口调用。<br/>3、越界回弹。<br/>事件回调发生时，事件参数[ArkUI_NodeEvent](_ark_u_i___node_event.md)对象中的联合体类型为[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)。<br/>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)中包含1个参数。<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].i32**表示当前碰到的是上下左右哪个边。 | 
| NODE_REFRESH_STATE_CHANGE  | 定义ARKUI_NODE_REFRESH刷新状态变更触发该事件。<br/>事件回调发生时，事件参数[ArkUI_NodeEvent](_ark_u_i___node_event.md)对象中的联合体类型为[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)。<br/>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)中包含1个参数：<br/>**[ArkUI_NodeComponentEvent.data](_ark_u_i___node_component_event.md#data)[0].i32**：刷新状态。 | 
| NODE_REFRESH_ON_REFRESH  | 定义ARKUI_NODE_REFRESH进入刷新状态时触发该事件。<br/>事件回调发生时，事件参数[ArkUI_NodeEvent](_ark_u_i___node_event.md)对象中的联合体类型为[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)。<br/>[ArkUI_NodeComponentEvent](_ark_u_i___node_component_event.md)中不包含参数： | 


### ArkUI_NodeSourceType

```
enum ArkUI_NodeSourceType
```
**描述：**

产生Touch事件的来源类型定义。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| NODE_SOURCE_TYPE_UNKNOWN  | 不支持的来源类型。 | 
| NODE_SOURCE_TYPE_TOUCH_SCREEN  | 触摸屏。 | 
| NODE_SOURCE_TYPE_STYLUS  | 手写笔。 | 
| NODE_SOURCE_TYPE_TOUCHPAD  | 触控板。 | 


### ArkUI_NodeToolType

```
enum ArkUI_NodeToolType
```
**描述：**

Touch事件的工具类型定义。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| NODE_TOOL_TYPE_UNKNOWN  | 不支持的工具类型。 | 
| NODE_TOOL_TYPE_FINGER  | 手指。 | 
| NODE_TOOL_TYPE_STYLUS  | 笔。 | 


### ArkUI_NodeTouchEventAction

```
enum ArkUI_NodeTouchEventAction
```
**描述：**

定义触屏事件类型的枚举值。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| NODE_ACTION_CANCEL  | 触摸取消。 | 
| NODE_ACTION_DOWN  | 触摸按下。 | 
| NODE_ACTION_MOVE  | 触摸移动。 | 
| NODE_ACTION_UP  | 触摸抬起。 | 


### ArkUI_NodeType

```
enum ArkUI_NodeType
```
**描述：**

提供ArkUI在Native侧可创建组件类型。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_NODE_CUSTOM  | 自定义节点。 | 
| ARKUI_NODE_TEXT  | 文本。 | 
| ARKUI_NODE_SPAN  | 文本段落。 | 
| ARKUI_NODE_IMAGE_SPAN  | 文本图片段落。 | 
| ARKUI_NODE_IMAGE  | 图片。 | 
| ARKUI_NODE_TOGGLE  | 状态开关。 | 
| ARKUI_NODE_LOADING_PROGRESS  | 等待图标。 | 
| ARKUI_NODE_TEXT_INPUT  | 单行文本输入。 | 
| ARKUI_NODE_TEXT_AREA  | 多行文本。 | 
| ARKUI_NODE_BUTTON  | 按钮。 | 
| ARKUI_NODE_PROGRESS  | 进度条。 | 
| ARKUI_NODE_CHECKBOX  | 复选框。 | 
| ARKUI_NODE_XCOMPONENT  | XComponent。 | 
| ARKUI_NODE_DATE_PICKER  | 日期选择器组件。 | 
| ARKUI_NODE_TIME_PICKER  | 时间选择组件。 | 
| ARKUI_NODE_TEXT_PICKER  | 滑动选择文本内容的组件。 | 
| ARKUI_NODE_CALENDAR_PICKER  | 日历选择器组件。 | 
| ARKUI_NODE_SLIDER  | 滑动条组件 | 
| ARKUI_NODE_STACK  | 堆叠容器。 | 
| ARKUI_NODE_SWIPER  | 翻页容器。 | 
| ARKUI_NODE_SCROLL  | 滚动容器。 | 
| ARKUI_NODE_LIST  | 列表。 | 
| ARKUI_NODE_LIST_ITEM  | 列表项。 | 
| ARKUI_NODE_LIST_ITEM_GROUP  | 列表item分组。 | 
| ARKUI_NODE_COLUMN  | 垂直布局容器。 | 
| ARKUI_NODE_ROW  | 水平布局容器。 | 
| ARKUI_NODE_FLEX  | 弹性布局容器。 | 
| ARKUI_NODE_REFRESH  | 刷新组件。 | 
| ARKUI_NODE_EATER_FLOW | 瀑布流组件。 |


### ArkUI_ObjectFit

```
enum ArkUI_ObjectFit
```
**描述：**

定义image填充效果。 ImageSpanAlignment

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_OBJECT_FIT_CONTAIN  | 保持宽高比进行缩小或者放大，使得图片完全显示在显示边界内。 | 
| ARKUI_OBJECT_FIT_COVER  | 保持宽高比进行缩小或者放大，使得图片两边都大于或等于显示边界。 | 
| ARKUI_OBJECT_FIT_AUTO  | 自适应显示。 | 
| ARKUI_OBJECT_FIT_FILL  | 不保持宽高比进行放大缩小，使得图片充满显示边界。 | 
| ARKUI_OBJECT_FIT_SCALE_DOWN  | 保持宽高比显示，图片缩小或者保持不变。 | 
| ARKUI_OBJECT_FIT_NONE  | 保持原有尺寸显示。 | 


### ArkUI_ProgressType

```
enum ArkUI_ProgressType
```
**描述：**

定义进度条类型枚举值。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_PROGRESS_TYPE_LINEAR  | 线性样式。 | 
| ARKUI_PROGRESS_TYPE_RING  | 环形无刻度样式。 | 
| ARKUI_PROGRESS_TYPE_ECLIPSE  | 圆形样式。 | 
| ARKUI_PROGRESS_TYPE_SCALE_RING  | 唤醒有刻度样式。 | 
| ARKUI_PROGRESS_TYPE_CAPSULE  | 胶囊样式。 | 


### ArkUI_ScrollBarDisplayMode

```
enum ArkUI_ScrollBarDisplayMode
```
**描述：**

定义滚动条状态枚举值。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_SCROLL_BAR_DISPLAY_MODE_OFF  | 不显示。 | 
| ARKUI_SCROLL_BAR_DISPLAY_MODE_AUTO  | 按需显示(触摸时显示，2s后消失)。 | 
| ARKUI_SCROLL_BAR_DISPLAY_MODE_ON  | 常驻显示。 | 


### ArkUI_ScrollDirection

```
enum ArkUI_ScrollDirection
```
**描述：**

定义Scroll组件排列方向枚举值。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_SCROLL_DIRECTION_VERTICAL  | 仅支持竖直方向滚动。 | 
| ARKUI_SCROLL_DIRECTION_HORIZONTAL  | 仅支持水平方向滚动。 | 
| ARKUI_SCROLL_DIRECTION_NONE  | 禁止滚动。 | 


### ArkUI_ScrollEdge

```
enum ArkUI_ScrollEdge
```
**描述：**

定义滚动到的边缘位置。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_SCROLL_EDGE_TOP  | 竖直方向上边缘。 | 
| ARKUI_SCROLL_EDGE_BOTTOM  | 竖直方向下边缘。 | 
| ARKUI_SCROLL_EDGE_START  | 水平方向起始位置。 | 
| ARKUI_SCROLL_EDGE_END  | 水平方向末尾位置。 | 


### ArkUI_ScrollNestedMode

```
enum ArkUI_ScrollNestedMode
```
**描述：**

定义嵌套滚动选项。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_SCROLL_NESTED_MODE_SELF_ONLY  | 只自身滚动，不与父组件联动。 | 
| ARKUI_SCROLL_NESTED_MODE_SELF_FIRST  | 自身先滚动，自身滚动到边缘以后父组件滚动。父组件滚动到边缘以后 如果父组件有边缘效果，则父组件触发边缘效果，否则子组件触发边缘效果。 | 
| ARKUI_SCROLL_NESTED_MODE_PARENT_FIRST  | 父组件先滚动，父组件滚动到边缘以后自身滚动。 身滚动到边缘后，如果有边缘效果，会触发自身的边缘效果，否则触发父组件的边缘效果。 | 
| ARKUI_SCROLL_NESTED_MODE_PARALLEL  | 自身和父组件同时滚动，自身和父组件都到达边缘以后 如果自身有边缘效果，则自身触发边缘效果，否则父组件触发边缘效果。 | 


### ArkUI_ScrollSnapAlign

```
enum ArkUI_ScrollSnapAlign
```
**描述：**

定义列表项滚动结束对齐效果枚举值。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_SCROLL_SNAP_ALIGN_NONE  | 默认无项目滚动对齐效果。 | 
| ARKUI_SCROLL_SNAP_ALIGN_START  | 视图中的第一项将在列表的开头对齐。 | 
| ARKUI_SCROLL_SNAP_ALIGN_CENTER  | 视图中的中间项将在列表中心对齐。 | 
| ARKUI_SCROLL_SNAP_ALIGN_END  | 视图中的最后一项将在列表末尾对齐。 | 


### ArkUI_ShadowStyle

```
enum ArkUI_ShadowStyle
```
**描述：**

阴影效果枚举值。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_SHADOW_STYLE_OUTER_DEFAULT_XS  | 超小阴影。 | 
| ARKUI_SHADOW_STYLE_OUTER_DEFAULT_SM  | 小阴影。 | 
| ARKUI_SHADOW_STYLE_OUTER_DEFAULT_MD  | 中阴影。 | 
| ARKUI_SHADOW_STYLE_OUTER_DEFAULT_LG  | 大阴影。 | 
| ARKUI_SHADOW_STYLE_OUTER_FLOATING_SM  | 浮动小阴影。 | 
| ARKUI_SHADOW_STYLE_OUTER_FLOATING_MD  | 浮动中阴影。 | 


### ArkUI_ShadowType

```
enum ArkUI_ShadowType
```
**描述：**

定义阴影类型枚举值。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_SHADOW_TYPE_COLOR  | 颜色。 | 
| ARKUI_SHADOW_TYPE_BLUR  | 模糊。 | 


### ArkUI_ShapeType

```
enum ArkUI_ShapeType
```
**描述：**

自定义形状。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_SHAPE_TYPE_RECTANGLE  | 矩形类型。 | 
| ARKUI_SHAPE_TYPE_CIRCLE  | 圆形类型。 | 
| ARKUI_SHAPE_TYPE_ELLIPSE  | 椭圆形类型。 | 
| ARKUI_SHAPE_TYPE_PATH  | 路径类型。 | 


### ArkUI_SliderBlockStyle

```
enum ArkUI_SliderBlockStyle
```
**描述：**

定义滑块形状。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_SLIDER_BLOCK_STYLE_DEFAULT  | 使用默认滑块（圆形）。 | 
| ARKUI_SLIDER_BLOCK_STYLE_IMAGE  | 使用图片资源作为滑块。 | 
| ARKUI_SLIDER_BLOCK_STYLE_SHAPE  | 使用自定义形状作为滑块。 | 


### ArkUI_SliderDirection

```
enum ArkUI_SliderDirection
```
**描述：**

定义滑动条滑动方向。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_SLIDER_DIRECTION_VERTICAL  | 方向为纵向。 | 
| ARKUI_SLIDER_DIRECTION_HORIZONTAL  | 方向为横向。 | 


### ArkUI_SliderStyle

```
enum ArkUI_SliderStyle
```
**描述：**

定义滑块与滑轨显示样式。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_SLIDER_STYLE_OUT_SET  | 滑块在滑轨上。 | 
| ARKUI_SLIDER_STYLE_IN_SET  | 滑块在滑轨内。 | 


### ArkUI_StickyStyle

```
enum ArkUI_StickyStyle
```
**描述：**

定义列表是否吸顶和吸底枚举值。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_STICKY_STYLE_NONE  | ListItemGroup的header不吸顶，footer不吸底。 | 
| ARKUI_STICKY_STYLE_HEADER  | ListItemGroup的header吸顶，footer不吸底。 | 
| ARKUI_STICKY_STYLE_FOOTER  | ListItemGroup的footer吸底，header不吸顶。 | 
| ARKUI_STICKY_STYLE_BOTH  | ListItemGroup的footer吸底，header吸顶。 | 


### ArkUI_SwiperArrow

```
enum ArkUI_SwiperArrow
```
**描述：**

Swiper导航点箭头枚举值。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_SWIPER_ARROW_HIDE  | 不显示swiper中导航点箭头。 | 
| ARKUI_SWIPER_ARROW_SHOW  | 显示swiper中导航点箭头。 | 
| ARKUI_SWIPER_ARROW_SHOW_ON_HOVER  | 在hover状态下显示swiper中导航点箭头。 | 


### ArkUI_TextAlignment

```
enum ArkUI_TextAlignment
```
**描述：**

定义字体水平对齐样式枚举值。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_TEXT_ALIGNMENT_START  | 水平对齐首部。 | 
| ARKUI_TEXT_ALIGNMENT_CENTER  | 水平居中对齐。 | 
| ARKUI_TEXT_ALIGNMENT_END  | 水平对齐尾部。 | 
| ARKUI_TEXT_ALIGNMENT_JUSTIFY  | 双端对齐。 | 


### ArkUI_TextCase

```
enum ArkUI_TextCase
```
**描述：**

定义文本大小写枚举值。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_TEXT_CASE_NORMAL  | 保持原有大小写。 | 
| ARKUI_TEXT_CASE_LOWER  | 文本全小写。 | 
| ARKUI_TEXT_CASE_UPPER  | 文本全大写。 | 


### ArkUI_TextCopyOptions

```
enum ArkUI_TextCopyOptions
```
**描述：**

定义组件支持设置文本是否可复制粘贴。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_TEXT_COPY_OPTIONS_NONE  | 不支持复制。 | 
| ARKUI_TEXT_COPY_OPTIONS_IN_APP  | 支持应用内复制。 | 
| ARKUI_TEXT_COPY_OPTIONS_LOCAL_DEVICE  | 支持设备内复制。 | 
| ARKUI_TEXT_COPY_OPTIONS_CROSS_DEVICE  | 支持跨设备复制。 | 


### ArkUI_TextDecorationType

```
enum ArkUI_TextDecorationType
```
**描述：**

定义装饰线样式枚举值。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_TEXT_DECORATION_TYPE_NONE  | 不使用装饰线。 | 
| ARKUI_TEXT_DECORATION_TYPE_UNDERLINE  | 文字下划线修饰。 | 
| ARKUI_TEXT_DECORATION_TYPE_OVERLINE  | 文字上划线修饰。 | 
| ARKUI_TEXT_DECORATION_TYPE_LINE_THROUGH  | 穿过文本的修饰线。 | 


### ArkUI_TextHeightAdaptivePolicy

```
enum ArkUI_TextHeightAdaptivePolicy
```
**描述：**

定义文本自适应高度的方式。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_TEXT_HEIGHT_ADAPTIVE_POLICY_MAX_LINES_FIRST  | 设置文本高度自适应方式为以MaxLines优先。 | 
| ARKUI_TEXT_HEIGHT_ADAPTIVE_POLICY_MIN_FONT_SIZE_FIRST  | 设置文本高度自适应方式为以缩小字体优先。 | 
| ARKUI_TEXT_HEIGHT_ADAPTIVE_POLICY_LAYOUT_CONSTRAINT_FIRST  | 设置文本高度自适应方式为以布局约束（高度）优先。 | 


### ArkUI_TextInputType

```
enum ArkUI_TextInputType
```
**描述：**

定义单行文本输入法类型枚举值。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_TEXTINPUT_TYPE_NORMAL  | 基本输入模式。 | 
| ARKUI_TEXTINPUT_TYPE_NUMBER  | 纯数字模式。 | 
| ARKUI_TEXTINPUT_TYPE_PHONE_NUMBER  | 电话号码输入模式。 | 
| ARKUI_TEXTINPUT_TYPE_EMAIL  | 邮箱地址输入模式。 | 
| ARKUI_TEXTINPUT_TYPE_PASSWORD  | 密码输入模式。 | 
| ARKUI_TEXTINPUT_TYPE_NUMBER_PASSWORD  | 纯数字密码输入模式。 | 
| ARKUI_TEXTINPUT_TYPE_SCREEN_LOCK_PASSWORD  | 锁屏应用密码输入模式。 | 
| ARKUI_TEXTINPUT_TYPE_USER_NAME  | 用户名输入模式。 | 
| ARKUI_TEXTINPUT_TYPE_NEW_PASSWORD  | 新密码输入模式。 | 
| ARKUI_TEXTINPUT_TYPE_NUMBER_DECIMAL  | 带小数点的数字输入模式。 | 


### ArkUI_TextOverflow

```
enum ArkUI_TextOverflow
```
**描述：**

定义文本超长时的显示方式。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_TEXT_OVERFLOW_NONE  | 文本超长时不裁剪显示。 | 
| ARKUI_TEXT_OVERFLOW_CLIP  | 文本超长时进行裁剪显示。 | 
| ARKUI_TEXT_OVERFLOW_ELLIPSIS  | 文本超长时显示不下的文本用省略号代替。 | 
| ARKUI_TEXT_OVERFLOW_MARQUEE  | 文本超长时以跑马灯的方式展示。 | 


### ArkUI_TextPickerRangeType

```
enum ArkUI_TextPickerRangeType
```
**描述：**

定义滑动选择文本选择器输入类型。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_TEXTPICKER_RANGETYPE_SINGLE  | 单列数据选择器。 | 
| ARKUI_TEXTPICKER_RANGETYPE_MULTI  | 多列数据选择器。 | 
| ARKUI_TEXTPICKER_RANGETYPE_RANGE_CONTENT  | 支持图片资源的单列数据选择器。 | 
| ARKUI_TEXTPICKER_RANGETYPE_CASCADE_RANGE_CONTENT  | 支持联动的多列数据选择器。 | 


### ArkUI_VerticalAlignment

```
enum ArkUI_VerticalAlignment
```

**描述：**

定义垂直对齐方式。


**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_VERTICAL_ALIGNMENT_TOP  | 顶部对齐。 | 
| ARKUI_VERTICAL_ALIGNMENT_CENTER  | 居中对齐，默认对齐方式。 | 
| ARKUI_VERTICAL_ALIGNMENT_BOTTOM  | 底部对齐。 | 


### ArkUI_Visibility

```
enum ArkUI_Visibility
```
**描述：**

控制组件的显隐枚举值。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_VISIBILITY_VISIBLE  | 显示。 | 
| ARKUI_VISIBILITY_HIDDEN  | 隐藏，但参与布局进行占位。 | 
| ARKUI_VISIBILITY_NONE  | 隐藏，但不参与布局，不进行占位。 | 


### ArkUI_XComponentType

```
enum ArkUI_XComponentType
```
**描述：**

定义XComponent类型枚举值。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_XCOMPONENT_TYPE_SURFACE  | 用于EGL/OpenGLES和媒体数据写入，开发者定制绘制内容单独显示在屏幕上。 | 
| ARKUI_XCOMPONENT_TYPE_TEXTURE  | 用于EGL/OpenGLES和媒体数据写入，开发者定制绘制内容和XComponent组件内容合成后展示在屏幕上。 | 


## 函数说明


### OH_ArkUI_GetNativeAPI()

```
ArkUI_AnyNativeAPI* OH_ArkUI_GetNativeAPI (ArkUI_NativeAPIVariantKind type, int32_t version )
```
**描述：**

获取指定版本的Native接口集合。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| type | ArkUI提供的Native接口集合大类，例如UI组件接口类：ARKUI_NATIVE_NODE。  | 
| version | native接口结构体的版本信息，通过结构体定义的后缀获得，如版本1的UI组件结构体：ArkUI_NativeNodeAPI_1。  | 

**返回：**

返回携带版本的Native接口抽象对象。 


### OH_ArkUI_QueryModuleInterface()

```
ArkUI_AnyNativeAPI* OH_ArkUI_QueryModuleInterface (ArkUI_NativeAPIVariantKind type, int32_t version )
```
**描述：**

获取指定版本的Native模块接口集合。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| type | ArkUI提供的Native接口集合大类，例如UI组件接口类：ARKUI_NATIVE_NODE。  | 
| version | native接口结构体的版本信息，通过结构体支持的版本枚举获得，如ARKUI_NATIVE_NODE的可用版本[ArkUI_NativeNodeAPIVersion](#arkui_nativenodeapiversion)。  | 

**返回：**

返回携带版本的Native接口抽象对象。 
