# ArkUI_NativeModule
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @piggyguy; @wangyang2022-->
<!--Designer: @piggyguy; @wangyang2022-->
<!--Tester: @fredyuan912-->
<!--Adviser: @Brilliantry_Rui-->

## Overview

Provides drag and drop APIs of ArkUI on the native side. For details, see [Drag Event](../../ui/ndk-drag-event.md).

Provides the general key event APIs of ArkUI on the native side.

Provides ArkUI APIs for registering gesture callbacks on the native side. For details, see [Binding Gesture Events](../../ui/ndk-bind-gesture-events.md).

Provides ArkUI animation callbacks for native-side implementations. For more details, see [Using Animations](../../ui/ndk-use-animation.md).

Provides UI capabilities of ArkUI on the native side, such as UI component creation and destruction, tree node operations, attribute setting, and event listening. For details, see [Integrating with ArkTS Pages](../../ui/ndk-access-the-arkts-page.md).

**Since**: 12

## Files

| Name| Description|
| -- | -- |
| [embedded_component.h](capi-embedded-component-h.md) | Defines the structs and APIs of the **EmbeddedComponent** component.|
| [image.h](capi-image-h.md) | Defines **Image** node types for **NativeNode** APIs.|
| [image_animator.h](capi-image-animator-h.md) | Defines **ImageAnimator** node types for **NativeNode** APIs.|
| node_attr_custom.h | Declares the custom node events for **NativeNode** APIs.|
| [navigation_router.h](capi-navigation-router-h.md) | Defines the enumerations and APIs of the **Navigation** or **Router** component.|
| [swiper.h](capi-swiper-h.md) | Defines the enumerations and APIs of the **Swiper** component.|
| [drag_and_drop.h](capi-drag-and-drop-h.md) | Declares the APIs of **NativeDrag**.|
| [drawable_descriptor.h](capi-drawable-descriptor-h.md) | Declares the APIs of **NativeDrawableDescriptor**.|
| [native_animate.h](capi-native-animate-h.md) | Declares a set of animation APIs of ArkUI on the native side.|
| [native_dialog.h](capi-native-dialog-h.md) | Declares a set of custom dialog box APIs of ArkUI on the native side.|
| [native_gesture.h](capi-native-gesture-h.md) | Declares the APIs of **NativeGesture**.|
| [native_interface.h](capi-native-interface-h.md) | Declares a unified entry for the native module APIs.|
| [native_interface_focus.h](capi-native-interface-focus-h.md) | Declares APIs for focus management, mainly used for actively transferring focus, managing the default focus transfer behavior, and controlling the focus activation state.|
| [native_key_event.h](capi-native-key-event-h.md) | Declares the APIs of **NativeKeyEvent**.|
| [native_material.h](capi-native-material-h.md) | Provides immersive material types and API declarations for ArkUI on the native side.|
| [native_node.h](capi-native-node-h.md) | Declares the APIs of **NativeNode**.|
| [native_node_napi.h](capi-native-node-napi-h.md) | Declares the functions used to convert FrameNodes on the ArkTS side into NodeHandles.|
| [native_type.h](capi-native-type-h.md) | Defines the common types for the native module.|
| [picker.h](capi-picker-h.md) | Defines **Picker** node types for **NativeNode** APIs.|
| [styled_string.h](capi-styled-string-h.md) | Declares styled string APIs of ArkUI on the native side.|
| [xcomponent.h](capi-xcomponent-h.md) | Defines the enumerations of the **XComponent** component.|
