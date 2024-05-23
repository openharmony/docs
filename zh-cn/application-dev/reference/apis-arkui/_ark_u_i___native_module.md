# ArkUI_NativeModule


## 概述

提供ArkUI在Native侧的UI能力，如UI组件创建销毁、树节点操作，属性设置，事件监听等。

提供ArkUI在Native侧的注册手势回调的能力。

提供ArkUI在Native侧动画回调的能力。

**起始版本：** 12


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [drawable_descriptor.h](drawable__descriptor_8h.md) | 提供NativeDrawableDescriptor接口的类型定义。  <br> **库：** libace_ndk.z.so| 
| [native_animate.h](native__animate_8h.md) | 提供ArkUI在Native侧的动画接口定义集合。 <br> **库：** libace_ndk.z.so | 
| [native_dialog.h](native__dialog_8h.md) | 提供ArkUI在Native侧的自定义弹窗接口定义集合。  <br> **库：** libace_ndk.z.so| 
| [native_gesture.h](native__gesture_8h.md) | 提供NativeGesture接口的类型定义。  <br> **库：** libace_ndk.z.so| 
| [native_interface.h](native__interface_8h.md) | 提供NativeModule接口的统一入口函数。  <br> **库：** libace_ndk.z.so| 
| [native_node.h](native__node_8h.md) | 提供NativeNode接口的类型定义。 <br> **库：** libace_ndk.z.so | 
| [native_node_napi.h](native__node__napi_8h.md) | 提供ArkTS侧的FrameNode转换NodeHandle的方式。  <br> **库：** libace_ndk.z.so| 
| [native_type.h](native__type_8h.md) | 提供NativeModule公共的类型定义。  <br> **库：** libace_ndk.z.so| 


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[ArkUI_ExpectedFrameRateRange](_ark_u_i___expected_frame_rate_range.md) | 设置动画的期望帧率。  | 
| struct&nbsp;&nbsp;[ArkUI_AnimateCompleteCallback](_ark_u_i___animate_complete_callback.md) | 动画播放完成回调类型。  | 
| struct&nbsp;&nbsp;[ArkUI_NativeAnimateAPI_1](_ark_u_i___native_animate_a_p_i__1.md) | ArkUI提供的Native侧动画接口集合。  | 
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
| struct&nbsp;&nbsp;[ArkUI_Margin](_ark_u_i___margin.md) | 外边距属性，用于描述组件的外边距属性。  | 


### 宏定义

| 名称 | 描述 | 
| -------- | -------- |
| [OH_ArkUI_GetModuleInterface](#oh_arkui_getmoduleinterface)(nativeAPIVariantKind, structType, structPtr) | 基于结构体类型获取对应结构体指针的宏函数。  | 
| **MAX_NODE_SCOPE_NUM**&nbsp;&nbsp;&nbsp; |  1000| 
| **MAX_COMPONENT_EVENT_ARG_NUM**&nbsp;&nbsp;&nbsp; |  12| 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [ArkUI_DrawableDescriptor](#arkui_drawabledescriptor) [ArkUI_DrawableDescriptor](#arkui_drawabledescriptor) | 定义 DrawableDescriptor 对象。  | 
| typedef struct OH_PixelmapNative \* [OH_PixelmapNativeHandle](#oh_pixelmapnativehandle) | 定义OH_PixelmapNative对象指针类型。  | 
| typedef struct [ArkUI_AnimateOption](#arkui_animateoption) [ArkUI_AnimateOption](#arkui_animateoption) | 设置动画效果相关参数。  | 
| typedef bool(\* [ArkUI_OnWillDismissEvent](#arkui_onwilldismissevent)) (int32_t reason) | 弹窗关闭的回调函数。  | 
| typedef uint32_t [ArkUI_GestureEventActionTypeMask](#arkui_gestureeventactiontypemask) | 定义手势事件类型集合  | 
| typedef uint32_t [ArkUI_GestureDirectionMask](#arkui_gesturedirectionmask) | 定义滑动手势方向集合。  | 
| typedef struct [ArkUI_NodeEvent](#arkui_nodeevent) [ArkUI_NodeEvent](#arkui_nodeevent) | 定义组件事件的通用结构类型。  | 
| typedef struct [ArkUI_NodeCustomEvent](#arkui_nodecustomevent) [ArkUI_NodeCustomEvent](#arkui_nodecustomevent) | 定义自定义组件事件的通用结构类型。  | 
| typedef struct ArkUI_NodeAdapter \* [ArkUI_NodeAdapterHandle](#arkui_nodeadapterhandle) | 定义组件适配器对象，用于滚动类组件的元素懒加载。  | 
| typedef struct [ArkUI_NodeAdapterEvent](#arkui_nodeadapterevent) [ArkUI_NodeAdapterEvent](#arkui_nodeadapterevent) | 定义适配器事件对象。  | 
| typedef struct [ArkUI_LayoutConstraint](#arkui_layoutconstraint) [ArkUI_LayoutConstraint](#arkui_layoutconstraint) | 约束尺寸，组件布局时，进行尺寸范围限制。  | 
| typedef struct [ArkUI_DrawContext](#arkui_drawcontext) [ArkUI_DrawContext](#arkui_drawcontext) | 定义组件绘制上下文类型结构。  | 
| typedef struct ArkUI_Node \* [ArkUI_NodeHandle](#arkui_nodehandle) | 定义ArkUI native组件实例对象指针定义。  | 
| typedef struct ArkUI_NativeDialog \* [ArkUI_NativeDialogHandle](#arkui_nativedialoghandle) | 定义ArkUI在Native侧的自定义弹窗控制器对象指针。  | 
| typedef struct [ArkUI_WaterFlowSectionOption](#arkui_waterflowsectionoption) [ArkUI_WaterFlowSectionOption](#arkui_waterflowsectionoption) | 定义FlowItem分组配置信息。  | 
| typedef struct [ArkUI_ListItemSwipeActionItem](#arkui_listitemswipeactionitem) [ArkUI_ListItemSwipeActionItem](#arkui_listitemswipeactionitem) | 定义ListItemSwipeActionOption方法内Item的配置信息。  | 
| typedef struct [ArkUI_ListItemSwipeActionOption](#arkui_listitemswipeactionoption) [ArkUI_ListItemSwipeActionOption](#arkui_listitemswipeactionoption) | 定义ListItemSwipeActionOption方法的配置信息。  | 
| typedef struct ArkUI_Context \* [ArkUI_ContextHandle](#arkui_contexthandle) | 定义ArkUI native UI的上下文实例对象指针定义。  | 
| typedef struct [ArkUI_AlignmentRuleOption](#arkui_alignmentruleoption) [ArkUI_AlignmentRuleOption](#arkui_alignmentruleoption) | 指定设置在相对容器中子组件的对齐规则。  | 
| typedef struct [ArkUI_GuidelineOption](#arkui_guidelineoption) [ArkUI_GuidelineOption](#arkui_guidelineoption) | guideLine参数，用于定义guideline的id、方向和位置。  | 
| typedef struct [ArkUI_BarrierOption](#arkui_barrieroption) [ArkUI_BarrierOption](#arkui_barrieroption) | barrier参数，用于定义barrier的id、方向和生成时所依赖的组件。  | 
| typedef struct [ArkUI_ImageAnimatorFrameInfo](#arkui_imageanimatorframeinfo) [ArkUI_ImageAnimatorFrameInfo](#arkui_imageanimatorframeinfo) | 定义图片帧信息。  | 
| typedef struct [ArkUI_AccessibilityState](#arkui_accessibilitystate) [ArkUI_AccessibilityState](#arkui_accessibilitystate) | 定义组件无障碍状态。  | 
| typedef struct [ArkUI_AccessibilityValue](#arkui_accessibilityvalue) [ArkUI_AccessibilityValue](#arkui_accessibilityvalue) | 定义组件无障碍信息值。  | 
| typedef struct [ArkUI_SwiperIndicator](#arkui_swiperindicator) [ArkUI_SwiperIndicator](#arkui_swiperindicator) | 定义 Swiper 组件的导航指示器风格。  | 