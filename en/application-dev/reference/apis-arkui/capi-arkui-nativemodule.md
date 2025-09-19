# ArkUI_NativeModule
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @piggyguy; @xiang-shouxing; @yangfan229-->
<!--Designer: @piggyguy; @xiang-shouxing; @yangfan229-->
<!--Tester: @fredyuan912-->
<!--Adviser: @HelloCrease-->

## Overview

Provides drag and drop APIs of ArkUI on the native side. For details, see [Implementing Unified Drag and Drop](../../ui/ndk-drag-event.md).

Provides the general key event APIs of ArkUI on the native side.

Provides the APIs of ArkUI to register gesture callbacks on the native side. For details, see [Binding Gesture Events](../../ui/ndk-bind-gesture-events.md).

Provides animation callbacks of ArkUI on the native side. For more details, see [Using Animations](../../ui/ndk-use-animation.md).

Provides UI capabilities of ArkUI on the native side, such as UI component creation and destruction, tree node operations, attribute setting, and event listening. For details, see [Integrating with ArkTS Pages](../../ui/ndk-access-the-arkts-page.md).

**Since**: 12

## Files

| Name| Description|
| -- | -- |
| [drag_and_drop.h](capi-drag-and-drop-h.md) | Declares the APIs of **NativeDrag**.|
| [drawable_descriptor.h](capi-drawable-descriptor-h.md) | Declares the APIs of **NativeDrawableDescriptor**.|
| [native_animate.h](capi-native-animate-h.md) | Declares a set of animation APIs of ArkUI on the native side.|
| [native_dialog.h](capi-native-dialog-h.md) | Declares a set of custom dialog box APIs of ArkUI on the native side.|
| [native_gesture.h](capi-native-gesture-h.md) | Declares the APIs of **NativeGesture**.|
| [native_interface.h](capi-native-interface-h.md) | Declares a unified entry for the native module APIs.|
| [native_interface_focus.h](capi-native-interface-focus-h.md) | Declares APIs for focus management, mainly used for actively transferring focus, managing the default focus transfer behavior, and controlling the focus activation state.|
| [native_key_event.h](capi-native-key-event-h.md) | Declares the APIs of **NativeKeyEvent**.|
| [native_node.h](capi-native-node-h.md) | Declares the APIs of **NativeNode**.|
| [native_node_napi.h](capi-native-node-napi-h.md) | Declares the functions used to convert FrameNodes on the ArkTS side into NodeHandles.|
| [native_render.h](capi-native-render-h.md) | Provides type definitions for RenderNode on the native side and the capability to operate RenderNodes.|
| [native_type.h](capi-native-type-h.md) | Defines the common types for the native module.|
| [styled_string.h](capi-styled-string-h.md) | Declares styled string APIs of ArkUI on the native side.|
