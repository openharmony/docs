# drawable_descriptor.h


## Overview

Provides type definitions for **NativeDrawableDescriptor** APIs.

**Library**: libace_ndk.z.so

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Since**: 12

**Related module**: [ArkUI_NativeModule](_ark_u_i___native_module.md)


## Summary


### Types

| Name | Description | 
| -------- | -------- |
| typedef struct [ArkUI_DrawableDescriptor](_ark_u_i___native_module.md#arkui_drawabledescriptor) [ArkUI_DrawableDescriptor](_ark_u_i___native_module.md#arkui_drawabledescriptor) | Defines a **DrawableDescriptor** object. | 
| typedef struct OH_PixelmapNative \* [OH_PixelmapNativeHandle](_ark_u_i___native_module.md#oh_pixelmapnativehandle) | Defines the pointer to an **OH_PixelmapNative** object. | 


### Callback

| Name | Description | 
| -------- | -------- |
| [ArkUI_DrawableDescriptor](_ark_u_i___native_module.md#arkui_drawabledescriptor) \* [OH_ArkUI_DrawableDescriptor_CreateFromPixelMap](_ark_u_i___native_module.md#oh_arkui_drawabledescriptor_createfrompixelmap) ([OH_PixelmapNativeHandle](_ark_u_i___native_module.md#oh_pixelmapnativehandle) pixelMap) | Creates a **DrawbleDescriptor** object with a **PixelMap** object. | 
| [ArkUI_DrawableDescriptor](_ark_u_i___native_module.md#arkui_drawabledescriptor) \* [OH_ArkUI_DrawableDescriptor_CreateFromAnimatedPixelMap](_ark_u_i___native_module.md#oh_arkui_drawabledescriptor_createfromanimatedpixelmap) ([OH_PixelmapNativeHandle](_ark_u_i___native_module.md#oh_pixelmapnativehandle) \*array, int32_t size) | Creates a **DrawbleDescriptor** object with an array of **PixelMap** objects. | 
| void [OH_ArkUI_DrawableDescriptor_Dispose](_ark_u_i___native_module.md#oh_arkui_drawabledescriptor_dispose) ([ArkUI_DrawableDescriptor](_ark_u_i___native_module.md#arkui_drawabledescriptor) \*drawableDescriptor) | Disposes of the pointer to a **DrawbleDescriptor** object. | 
| [OH_PixelmapNativeHandle](_ark_u_i___native_module.md#oh_pixelmapnativehandle) [OH_ArkUI_DrawableDescriptor_GetStaticPixelMap](_ark_u_i___native_module.md#oh_arkui_drawabledescriptor_getstaticpixelmap) ([ArkUI_DrawableDescriptor](_ark_u_i___native_module.md#arkui_drawabledescriptor) \*drawableDescriptor) | Obtains the pointer to a **PixelMap** object. | 
| [OH_PixelmapNativeHandle](_ark_u_i___native_module.md#oh_pixelmapnativehandle) \* [OH_ArkUI_DrawableDescriptor_GetAnimatedPixelMapArray](_ark_u_i___native_module.md#oh_arkui_drawabledescriptor_getanimatedpixelmaparray) ([ArkUI_DrawableDescriptor](_ark_u_i___native_module.md#arkui_drawabledescriptor) \*drawableDescriptor) | Obtains an array of **PixelMap** objects for playing an animation. | 
| int32_t [OH_ArkUI_DrawableDescriptor_GetAnimatedPixelMapArraySize](_ark_u_i___native_module.md#oh_arkui_drawabledescriptor_getanimatedpixelmaparraysize) ([ArkUI_DrawableDescriptor](_ark_u_i___native_module.md#arkui_drawabledescriptor) \*drawableDescriptor) | Obtains an array of **PixelMap** objects for playing an animation. | 
| void [OH_ArkUI_DrawableDescriptor_SetAnimationDuration](_ark_u_i___native_module.md#oh_arkui_drawabledescriptor_setanimationduration) ([ArkUI_DrawableDescriptor](_ark_u_i___native_module.md#arkui_drawabledescriptor) \*drawableDescriptor, int32_t duration) | Sets the total playback duration of the PixelMap image array. | 
| int32_t [OH_ArkUI_DrawableDescriptor_GetAnimationDuration](_ark_u_i___native_module.md#oh_arkui_drawabledescriptor_getanimationduration) ([ArkUI_DrawableDescriptor](_ark_u_i___native_module.md#arkui_drawabledescriptor) \*drawableDescriptor) | Obtains the total playback duration of a PixelMap image array. | 
| void [OH_ArkUI_DrawableDescriptor_SetAnimationIteration](_ark_u_i___native_module.md#oh_arkui_drawabledescriptor_setanimationiteration) ([ArkUI_DrawableDescriptor](_ark_u_i___native_module.md#arkui_drawabledescriptor) \*drawableDescriptor, int32_t iteration) | Sets the number of times that the PixelMap image array is played. | 
| int32_t [OH_ArkUI_DrawableDescriptor_GetAnimationIteration](_ark_u_i___native_module.md#oh_arkui_drawabledescriptor_getanimationiteration) ([ArkUI_DrawableDescriptor](_ark_u_i___native_module.md#arkui_drawabledescriptor) \*drawableDescriptor) | Obtains the number of times that the PixelMap image array is played. | 
