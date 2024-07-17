# styled_string.h


## Overview

Provides styled string APIs of ArkUI on the native side.

**Library**: libace_ndk.z.so

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Since**: 12

**Related module**: [ArkUI_NativeModule](_ark_u_i___native_module.md)


## Summary


### Types

| Name | Description |
| -------- | -------- |
| typedef struct [ArkUI_StyledString](_ark_u_i___native_module.md#arkui_styledstring)[ArkUI_StyledString](_ark_u_i___native_module.md#arkui_styledstring) | Defines a styled string object supported by the text component. |


### Callback

| Name | Description of the component. |
| -------- | -------- |
| [ArkUI_StyledString](_ark_u_i___native_module.md#arkui_styledstring) \* [OH_ArkUI_StyledString_Create](_ark_u_i___native_module.md#oh_arkui_styledstring_create) (OH_Drawing_TypographyStyle \*style, OH_Drawing_FontCollection \*collection) | Creates an **OH_Drawing_Typography** object. |
| void [OH_ArkUI_StyledString_Destroy](_ark_u_i___native_module.md#oh_arkui_styledstring_destroy) ([ArkUI_StyledString](_ark_u_i___native_module.md#arkui_styledstring) \*handle) | Destroys an **OH_Drawing_FontCollection** object and reclaims the memory occupied by the object. |
| void [OH_ArkUI_StyledString_PushTextStyle](_ark_u_i___native_module.md#oh_arkui_styledstring_pushtextstyle) ([ArkUI_StyledString](_ark_u_i___native_module.md#arkui_styledstring) \*handle, OH_Drawing_TextStyle \*style) | Sets the new typesetting style to the top of the current format string style stack. |
| void [OH_ArkUI_StyledString_AddText](_ark_u_i___native_module.md#oh_arkui_styledstring_addtext) ([ArkUI_StyledString](_ark_u_i___native_module.md#arkui_styledstring) \*handle, const char \*content) | Sets the text content based on the current format string style. |
| void [OH_ArkUI_StyledString_PopTextStyle](_ark_u_i___native_module.md#oh_arkui_styledstring_poptextstyle) ([ArkUI_StyledString](_ark_u_i___native_module.md#arkui_styledstring) \*handle) | Removes the top style from the current formatted string object. |
| OH_Drawing_Typography \* [OH_ArkUI_StyledString_CreateTypography](_ark_u_i___native_module.md#oh_arkui_styledstring_createtypography) ([ArkUI_StyledString](_ark_u_i___native_module.md#arkui_styledstring) \*handle) | Creates a pointer to the OH_Drawing_Typography object based on the format string object for text calculation and typesetting in advance. |
| void [OH_ArkUI_StyledString_AddPlaceholder](_ark_u_i___native_module.md#oh_arkui_styledstring_addplaceholder) ([ArkUI_StyledString](_ark_u_i___native_module.md#arkui_styledstring) \*handle, OH_Drawing_PlaceholderSpan \*placeholder) | Adds a placeholder. |
