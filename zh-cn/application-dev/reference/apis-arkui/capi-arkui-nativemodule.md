# ArkUI_NativeModule
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @piggyguy; @wangyang2022-->
<!--Designer: @piggyguy; @wangyang2022-->
<!--Tester: @fredyuan912-->
<!--Adviser: @Brilliantry_Rui-->

## 概述

提供ArkUI在Native侧接入和管理页面交互的能力，适用于使用NDK构建UI、处理输入事件、绑定手势、执行动画和管理节点树等场景。

提供ArkUI在Native侧的基础输入事件能力。更多详细介绍请参考[绑定基础输入事件](../../ui/ndk-bind-input-events.md)。

提供ArkUI在Native侧的通用拖拽及主动发起拖拽能力。更多详细介绍请参考[绑定拖拽事件](../../ui/ndk-drag-event.md)。

提供ArkUI在Native侧的通用按键事件能力。详细介绍请参考[绑定基础输入事件](../../ui/ndk-bind-input-events.md#按键事件)。

提供ArkUI在Native侧注册手势回调的能力。详细介绍请参考[绑定手势事件](../../ui/ndk-bind-gesture-events.md)。

提供ArkUI在Native侧使用动画回调的能力。详细介绍请参考[使用动画](../../ui/ndk-use-animation.md)。

提供ArkUI在Native侧的UI能力，如UI组件创建、销毁、树节点操作、属性设置、事件监听等。详细介绍请参考[接入ArkTS页面](../../ui/ndk-access-the-arkts-page.md)。

上述能力适用于Native侧接入ArkTS页面并处理输入事件、拖拽、手势、动画和UI节点管理的场景，可帮助开发者在Native模块中完成ArkUI页面交互处理和组件树管理。

**起始版本：** 12

## 文件汇总

| 名称 | 描述 |
| -- | -- |
| [common_attributes.h](capi-common-attributes-h.md) | 提供NativeModule通用属性和事件的类型定义。 |
| [embedded_component.h](capi-embedded-component-h.md) | EmbeddedComponent组件相关的结构体和方法定义。 |
| [image.h](capi-image-h.md) | 为NativeNode API提供Image节点类型定义。 |
| [image_animator.h](capi-image-animator-h.md) | 为NativeNode API提供ImageAnimator节点类型定义。 |
| [layout.h](capi-layout-h.md) | 定义布局相关的枚举和接口。 |
| [custom_attributes.h](capi-native-node-node-attributes-custom-attributes-h.md) | 为NativeNode API提供自定义组件的测量、布局和绘制事件类型定义，用于注册和处理测量、布局以及内容层、前景层和浮层的绘制事件。 |
| [grid.h](capi-grid-h.md) | 定义Grid组件的枚举和接口。 |
| [list.h](capi-list-h.md) | 定义List组件的枚举和接口。 |
| [navigation_router.h](capi-navigation-router-h.md) | 定义Navigation或Router组件的枚举和接口。 |
| [scroll.h](capi-scroll-h.md) | 定义Scroll组件相关的枚举。 |
| [swiper.h](capi-swiper-h.md) | 定义Swiper组件的枚举和接口。 |
| [water_flow.h](capi-water-flow-h.md) | 定义WaterFlow组件的枚举和接口。 |
| [drag_and_drop.h](capi-drag-and-drop-h.md) | 提供NativeDrag相关接口定义。 |
| [drawable_descriptor.h](capi-drawable-descriptor-h.md) | 提供NativeDrawableDescriptor接口的类型定义。 |
| [native_animate.h](capi-native-animate-h.md) | 提供ArkUI在Native侧的动画接口定义集合。 |
| [native_dialog.h](capi-native-dialog-h.md) | 提供ArkUI在Native侧的自定义弹窗接口定义集合。 |
| [native_gesture.h](capi-native-gesture-h.md) | 提供NativeGesture接口的类型定义。 |
| [native_interface.h](capi-native-interface-h.md) | 提供NativeModule接口的统一入口函数。 |
| [native_interface_focus.h](capi-native-interface-focus-h.md) | 定义焦点管理的相关接口，主要用于主动转移焦点、管理焦点转移的默认行为以及控制焦点激活态。 |
| [native_key_event.h](capi-native-key-event-h.md) | 提供NativeKeyEvent相关接口定义。 |
| [native_material.h](capi-native-material-h.md) | 提供ArkUI在Native侧的沉浸式材质类型和API声明。 |
| [native_node.h](capi-native-node-h.md) | 提供NativeNode接口的类型定义。 |
| [native_node_napi.h](capi-native-node-napi-h.md) | 提供将ArkTS侧的FrameNode转换为ArkUI_NodeHandle的方式。 |
| [native_type.h](capi-native-type-h.md) | 提供NativeModule公共的类型定义。 |
| [text.h](capi-text-h.md) | 定义Text相关的枚举和接口。 |
| [text_common.h](capi-text-common-h.md) | 定义文本类组件通用的枚举和接口。 |
| [text_input.h](capi-text-input-h.md) | 定义TextInput相关的枚举和接口。 |
| [text_area.h](capi-text-area-h.md) | 定义TextArea相关的枚举和接口。 |
| [image_span.h](capi-image-span-h.md) | 定义ImageSpan相关的枚举和接口。 |
| [progress.h](capi-progress-h.md) | 定义Progress相关的枚举和接口。 |
| [rich_editor.h](capi-rich-editor-h.md) | 定义RichEditor相关的枚举和接口。 |
| [custom_span.h](capi-custom-span-h.md) | 定义CustomSpan相关的枚举和接口。 |
| [picker.h](capi-picker-h.md) | 为NativeNode API提供Picker节点类型定义。 |
| [button.h](capi-button-h.md) | 为NativeNode API提供Button节点类型定义。 |
| [checkbox.h](capi-checkbox-h.md) | 为NativeNode API提供Checkbox节点类型定义。 |
| [slider.h](capi-slider-h.md) | 为NativeNode API提供Slider节点类型定义。 |
| [styled_string.h](capi-styled-string-h.md) | 提供ArkUI在Native侧的属性字符串能力。 |
| [xcomponent.h](capi-xcomponent-h.md) | XComponent组件的枚举类型定义。 |
