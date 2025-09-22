# native_interface.h
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @xiang-shouxing-->
<!--Designer: @xiang-shouxing-->
<!--Tester: @sally__-->
<!--Adviser: @HelloCrease-->

## Overview

Provides a unified entry for the native module APIs.

**File to include**: <arkui/native_interface.h>

**Library**: libace_ndk.z.so

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Since**: 12

**Related module**: [ArkUI_NativeModule](capi-arkui-nativemodule.md)

## Summary

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [ArkUI_NativeAPIVariantKind](#arkui_nativeapivariantkind) | ArkUI_NativeAPIVariantKind | Enumerates the types of native API collections.|

### Functions

| Name | Description  |
|--------------|-----------|
| [void* OH_ArkUI_QueryModuleInterfaceByName(ArkUI_NativeAPIVariantKind type, const char* structName)](#oh_arkui_querymoduleinterfacebyname)        | Initializes the C-API environment and obtains the native module API collection of the specified type.|

### Macros

| Name | Description  |
|--------------|-----------|
| [OH_ArkUI_GetModuleInterface(nativeAPIVariantKind, structType, structPtr)](#oh_arkui_getmoduleinterface)      | Obtains the corresponding struct pointer based on the struct type.|

## Enum Description

### ArkUI_NativeAPIVariantKind

```
enum ArkUI_NativeAPIVariantKind
```

**Description**


Enumerates the types of native API collections.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_NATIVE_NODE | API related to UI components. For details, see the struct definition in <arkui/native_node.h>.|
| ARKUI_NATIVE_DIALOG | API related to dialog boxes. For details, see the [struct](capi-native-dialog-h.md#structs) definition in **native_dialog.h**.|
| ARKUI_NATIVE_GESTURE | API related to gestures. For details, see the [struct](capi-native-gesture-h.md#structs) definition in **native_gesture.h**.|
| ARKUI_NATIVE_ANIMATE | API related to animations. For details, see the [struct](capi-native-animate-h.md#structs) definition in **native_animate.h**.|
| ARKUI_MULTI_THREAD_NATIVE_NODE | API related to multi-threaded UI components. For details, see the struct definition in <arkui/native_node.h>.|


## Function Description

### OH_ArkUI_QueryModuleInterfaceByName()

```
void* OH_ArkUI_QueryModuleInterfaceByName(ArkUI_NativeAPIVariantKind type, const char* structName)
```

**Description**


Initializes the C-API environment and obtains the native module API collection of the specified type.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NativeAPIVariantKind](capi-native-interface-h.md#arkui_nativeapivariantkind) type | Type of the native API collection provided by ArkUI, for example, **ARKUI_NATIVE_NODE** or **ARKUI_NATIVE_GESTURE**.|
| const char* structName | Name of a native struct, obtained by querying the struct definitions in the corresponding header file, for example, **ArkUI_NativeNodeAPI_1** in <arkui/native_node.h>.|

**Return value**

| Type| Description|
| -- | -- |
| void* | Void pointer to the native API abstraction, which must be cast to the specific type for use.|

### OH_ArkUI_GetModuleInterface()

```
OH_ArkUI_GetModuleInterface(nativeAPIVariantKind, structType, structPtr)                             \
do {                                                                                                 \
        void* anyNativeAPI = OH_ArkUI_QueryModuleInterfaceByName(nativeAPIVariantKind, #structType); \
        if (anyNativeAPI) {                                                                          \
            structPtr = (structType*)(anyNativeAPI);                                                 \
        }                                                                                            \
    } while (0)                                                                      
```

**Description**


Obtains the corresponding struct pointer based on the struct type.

**Since**: 12
