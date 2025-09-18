# drawable_descriptor.h

## Overview

Declares the APIs of **NativeDrawableDescriptor**.

**File to include**: <arkui/drawable_descriptor.h>

**Library**: libace_ndk.z.so

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Since**: 12

**Related module**: [ArkUI_NativeModule](capi-arkui-nativemodule.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [ArkUI_DrawableDescriptor](capi-arkui-nativemodule-arkui-drawabledescriptor.md) | ArkUI_DrawableDescriptor | Defines a struct for the **DrawableDescriptor** object.|
| [OH_PixelmapNative*](capi-arkui-nativemodule-oh-pixelmapnative8h.md) | OH_PixelmapNativeHandle | Defines a struct for the pointer to an **OH_PixelmapNative** object.|

### Functions

| Name| Description|
| -- | -- |
| [ArkUI_DrawableDescriptor* OH_ArkUI_DrawableDescriptor_CreateFromPixelMap(OH_PixelmapNativeHandle pixelMap)](#oh_arkui_drawabledescriptor_createfrompixelmap) | Creates a **DrawableDescriptor** object from a **PixelMap** object.|
| [ArkUI_DrawableDescriptor* OH_ArkUI_DrawableDescriptor_CreateFromAnimatedPixelMap(OH_PixelmapNativeHandle* array, int32_t size)](#oh_arkui_drawabledescriptor_createfromanimatedpixelmap) | Creates a **DrawableDescriptor** object from an array of **PixelMap** objects.|
| [void OH_ArkUI_DrawableDescriptor_Dispose(ArkUI_DrawableDescriptor* drawableDescriptor)](#oh_arkui_drawabledescriptor_dispose) | Disposes the pointer to a **DrawableDescriptor** object.|
| [OH_PixelmapNativeHandle OH_ArkUI_DrawableDescriptor_GetStaticPixelMap(ArkUI_DrawableDescriptor* drawableDescriptor)](#oh_arkui_drawabledescriptor_getstaticpixelmap) | Obtains the pointer to a **PixelMap** object.|
| [OH_PixelmapNativeHandle* OH_ArkUI_DrawableDescriptor_GetAnimatedPixelMapArray(ArkUI_DrawableDescriptor* drawableDescriptor)](#oh_arkui_drawabledescriptor_getanimatedpixelmaparray) | Obtains an array of **PixelMap** objects for playing an animation.|
| [int32_t OH_ArkUI_DrawableDescriptor_GetAnimatedPixelMapArraySize(ArkUI_DrawableDescriptor* drawableDescriptor)](#oh_arkui_drawabledescriptor_getanimatedpixelmaparraysize) | Obtains an array of **PixelMap** objects for playing an animation.|
| [void OH_ArkUI_DrawableDescriptor_SetAnimationDuration(ArkUI_DrawableDescriptor* drawableDescriptor, int32_t duration)](#oh_arkui_drawabledescriptor_setanimationduration) | Sets the total playback duration for an array of **PixelMap** objects.|
| [int32_t OH_ArkUI_DrawableDescriptor_GetAnimationDuration(ArkUI_DrawableDescriptor* drawableDescriptor)](#oh_arkui_drawabledescriptor_getanimationduration) | Obtains the total playback duration for an array of **PixelMap** objects.|
| [void OH_ArkUI_DrawableDescriptor_SetAnimationIteration(ArkUI_DrawableDescriptor* drawableDescriptor, int32_t iteration)](#oh_arkui_drawabledescriptor_setanimationiteration) | Sets the number of times that an array of **PixelMap** objects is played.|
| [int32_t OH_ArkUI_DrawableDescriptor_GetAnimationIteration(ArkUI_DrawableDescriptor* drawableDescriptor)](#oh_arkui_drawabledescriptor_getanimationiteration) | Obtains the number of times that an array of **PixelMap** objects is played.|

## Function Description

### OH_ArkUI_DrawableDescriptor_CreateFromPixelMap()

```
ArkUI_DrawableDescriptor* OH_ArkUI_DrawableDescriptor_CreateFromPixelMap(OH_PixelmapNativeHandle pixelMap)
```

**Description**


Creates a **DrawableDescriptor** object from a **PixelMap** object.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_PixelmapNativeHandle](capi-arkui-nativemodule-oh-pixelmapnative8h.md) pixelMap | Pointer to a **PixelMap** object.|

**Return value**

| Type                           | Description|
|-------------------------------| -- |
| [ArkUI_DrawableDescriptor](capi-arkui-nativemodule-arkui-drawabledescriptor.md)* | Pointer to the **DrawableDescriptor** object.|

### OH_ArkUI_DrawableDescriptor_CreateFromAnimatedPixelMap()

```
ArkUI_DrawableDescriptor* OH_ArkUI_DrawableDescriptor_CreateFromAnimatedPixelMap(OH_PixelmapNativeHandle* array, int32_t size)
```

**Description**


Creates a **DrawableDescriptor** object from an array of **PixelMap** objects.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_PixelmapNativeHandle](capi-arkui-nativemodule-oh-pixelmapnative8h.md)* array | Pointer to the array of **PixelMap** objects.|
| int32_t size | Size of the **PixelMap** object array.|

**Return value**

| Type| Description|
| -- | -- |
| [ArkUI_DrawableDescriptor](capi-arkui-nativemodule-arkui-drawabledescriptor.md)* | Pointer to the **DrawableDescriptor** object.|

### OH_ArkUI_DrawableDescriptor_Dispose()

```
void OH_ArkUI_DrawableDescriptor_Dispose(ArkUI_DrawableDescriptor* drawableDescriptor)
```

**Description**


Disposes the pointer to a **DrawableDescriptor** object.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_DrawableDescriptor](capi-arkui-nativemodule-arkui-drawabledescriptor.md)* drawableDescriptor | Pointer to a **DrawableDescriptor** object.|

### OH_ArkUI_DrawableDescriptor_GetStaticPixelMap()

```
OH_PixelmapNativeHandle OH_ArkUI_DrawableDescriptor_GetStaticPixelMap(ArkUI_DrawableDescriptor* drawableDescriptor)
```

**Description**


Obtains the pointer to a **PixelMap** object.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_DrawableDescriptor](capi-arkui-nativemodule-arkui-drawabledescriptor.md)* drawableDescriptor | Pointer to a **DrawableDescriptor** object.|

**Return value**

| Type| Description|
| -- | -- |
| [OH_PixelmapNativeHandle](capi-arkui-nativemodule-oh-pixelmapnative8h.md) | Pointer to a **PixelMap** object.|

### OH_ArkUI_DrawableDescriptor_GetAnimatedPixelMapArray()

```
OH_PixelmapNativeHandle* OH_ArkUI_DrawableDescriptor_GetAnimatedPixelMapArray(ArkUI_DrawableDescriptor* drawableDescriptor)
```

**Description**


Obtains an array of **PixelMap** objects for playing an animation.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_DrawableDescriptor](capi-arkui-nativemodule-arkui-drawabledescriptor.md)* drawableDescriptor | Pointer to a **DrawableDescriptor** object.|

**Return value**

| Type                          | Description|
|------------------------------| -- |
| [OH_PixelmapNativeHandle](capi-arkui-nativemodule-oh-pixelmapnative8h.md)* | Pointer to the array of **PixelMap** objects.|

### OH_ArkUI_DrawableDescriptor_GetAnimatedPixelMapArraySize()

```
int32_t OH_ArkUI_DrawableDescriptor_GetAnimatedPixelMapArraySize(ArkUI_DrawableDescriptor* drawableDescriptor)
```

**Description**


Obtains an array of **PixelMap** objects for playing an animation.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_DrawableDescriptor](capi-arkui-nativemodule-arkui-drawabledescriptor.md)* drawableDescriptor | Pointer to a **DrawableDescriptor** object.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Size of the **PixelMap** object array.|

### OH_ArkUI_DrawableDescriptor_SetAnimationDuration()

```
void OH_ArkUI_DrawableDescriptor_SetAnimationDuration(ArkUI_DrawableDescriptor* drawableDescriptor, int32_t duration)
```

**Description**


Sets the total playback duration for an array of **PixelMap** objects.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_DrawableDescriptor](capi-arkui-nativemodule-arkui-drawabledescriptor.md)* drawableDescriptor | Pointer to a **DrawableDescriptor** object.|
| int32_t duration | Total playback duration, in milliseconds.|

### OH_ArkUI_DrawableDescriptor_GetAnimationDuration()

```
int32_t OH_ArkUI_DrawableDescriptor_GetAnimationDuration(ArkUI_DrawableDescriptor* drawableDescriptor)
```

**Description**


Obtains the total playback duration for an array of **PixelMap** objects.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_DrawableDescriptor](capi-arkui-nativemodule-arkui-drawabledescriptor.md)* drawableDescriptor | Pointer to a **DrawableDescriptor** object.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Total playback duration, in milliseconds.|

### OH_ArkUI_DrawableDescriptor_SetAnimationIteration()

```
void OH_ArkUI_DrawableDescriptor_SetAnimationIteration(ArkUI_DrawableDescriptor* drawableDescriptor, int32_t iteration)
```

**Description**


Sets the number of times that an array of **PixelMap** objects is played.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_DrawableDescriptor](capi-arkui-nativemodule-arkui-drawabledescriptor.md)* drawableDescriptor | Pointer to a **DrawableDescriptor** object.|
| int32_t iteration | Number of playback times.|

### OH_ArkUI_DrawableDescriptor_GetAnimationIteration()

```
int32_t OH_ArkUI_DrawableDescriptor_GetAnimationIteration(ArkUI_DrawableDescriptor* drawableDescriptor)
```

**Description**


Obtains the number of times that an array of **PixelMap** objects is played.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_DrawableDescriptor](capi-arkui-nativemodule-arkui-drawabledescriptor.md)* drawableDescriptor | Pointer to a **DrawableDescriptor** object.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Number of playback times.|
