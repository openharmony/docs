# native_interface.h


## Overview

Provides a unified entry for the native module APIs.

**Library**: libace_ndk.z.so

**File to include**: <arkui/native_interface.h>

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Since**: 12

**Related module**: [ArkUI_NativeModule](_ark_u_i___native_module.md)


## Summary


### Macros

| Name | Description | 
| -------- | -------- |
| [OH_ArkUI_GetModuleInterface](_ark_u_i___native_module.md#oh_arkui_getmoduleinterface)(nativeAPIVariantKind, structType, structPtr) | Obtains the macro function corresponding to a struct pointer based on the struct type. | 


### Enums

| Name | Description | 
| -------- | -------- |
| [ArkUI_NativeAPIVariantKind](_ark_u_i___native_module.md#arkui_nativeapivariantkind) { [ARKUI_NATIVE_NODE](_ark_u_i___native_module.md), [ARKUI_NATIVE_DIALOG](_ark_u_i___native_module.md), [ARKUI_NATIVE_GESTURE](_ark_u_i___native_module.md), [ARKUI_NATIVE_ANIMATE](_ark_u_i___native_module.md) } | Defines the native API types. | 


### Functions

| Name | Description | 
| -------- | -------- |
| void \* [OH_ArkUI_QueryModuleInterfaceByName](_ark_u_i___native_module.md#oh_arkui_querymoduleinterfacebyname) ([ArkUI_NativeAPIVariantKind](_ark_u_i___native_module.md#arkui_nativeapivariantkind) type, const char \*structName) | Obtains the native API set of a specified type. | 
