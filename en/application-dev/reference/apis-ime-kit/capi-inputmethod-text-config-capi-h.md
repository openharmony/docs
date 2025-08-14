# inputmethod_text_config_capi.h
<!--Kit: IME Kit-->
<!--Subsystem: MiscServices-->
<!--Owner: @illybyy-->
<!--SE: @andeszhang-->
<!--TSE: @murphy1984-->

## Overview

Provides methods for creating, destroying, reading, and writing the text box configuration information objects.

**File to include**: <inputmethod/inputmethod_text_config_capi.h>

**Library**: libohinputmethod.so

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Since**: 12

**Related module**: [InputMethod](capi-inputmethod.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [InputMethod_TextConfig](capi-inputmethod-inputmethod-textconfig.md) | InputMethod_TextConfig | Represents the text box configuration information.  |

### Function

| Name| Description|
| -- | -- |
| [InputMethod_TextConfig *OH_TextConfig_Create(void)](#oh_textconfig_create) | Creates an [InputMethod_TextConfig](capi-inputmethod-inputmethod-textconfig.md) instance.|
| [void OH_TextConfig_Destroy(InputMethod_TextConfig *config)](#oh_textconfig_destroy) | Destroys an [InputMethod_TextConfig](capi-inputmethod-inputmethod-textconfig.md) instance.|
| [InputMethod_ErrorCode OH_TextConfig_SetInputType(InputMethod_TextConfig *config, InputMethod_TextInputType inputType)](#oh_textconfig_setinputtype) | Sets the text box type.|
| [InputMethod_ErrorCode OH_TextConfig_SetEnterKeyType(InputMethod_TextConfig *config, InputMethod_EnterKeyType enterKeyType)](#oh_textconfig_setenterkeytype) | Sets the Enter key type.|
| [InputMethod_ErrorCode OH_TextConfig_SetPreviewTextSupport(InputMethod_TextConfig *config, bool supported)](#oh_textconfig_setpreviewtextsupport) | Sets the text preview feature.|
| [InputMethod_ErrorCode OH_TextConfig_SetSelection(InputMethod_TextConfig *config, int32_t start, int32_t end)](#oh_textconfig_setselection) | Sets the selected text area.|
| [InputMethod_ErrorCode OH_TextConfig_SetWindowId(InputMethod_TextConfig *config, int32_t windowId)](#oh_textconfig_setwindowid) | Sets the window ID.|
| [InputMethod_ErrorCode OH_TextConfig_SetPlaceholder(InputMethod_TextConfig *config, const char16_t *placeholder,size_t length)](#oh_textconfig_setplaceholder) | Sets the placeholder text.|
| [InputMethod_ErrorCode OH_TextConfig_SetAbilityName(InputMethod_TextConfig *config, const char16_t *abilityName,size_t length)](#oh_textconfig_setabilityname) | Sets the ability name.|
| [InputMethod_ErrorCode OH_TextConfig_GetInputType(InputMethod_TextConfig *config, InputMethod_TextInputType *inputType)](#oh_textconfig_getinputtype) | Obtains the text box type.|
| [InputMethod_ErrorCode OH_TextConfig_GetEnterKeyType(InputMethod_TextConfig *config, InputMethod_EnterKeyType *enterKeyType)](#oh_textconfig_getenterkeytype) | Obtains the Enter key type.|
| [InputMethod_ErrorCode OH_TextConfig_IsPreviewTextSupported(InputMethod_TextConfig *config, bool *supported)](#oh_textconfig_ispreviewtextsupported) | Obtains whether the text preview feature is supported.|
| [InputMethod_ErrorCode OH_TextConfig_GetCursorInfo(InputMethod_TextConfig *config, InputMethod_CursorInfo **cursorInfo)](#oh_textconfig_getcursorinfo) | Obtains the cursor information.|
| [InputMethod_ErrorCode OH_TextConfig_GetTextAvoidInfo(InputMethod_TextConfig *config, InputMethod_TextAvoidInfo **avoidInfo)](#oh_textconfig_gettextavoidinfo) | Obtains the avoidance information.|
| [InputMethod_ErrorCode OH_TextConfig_GetSelection(InputMethod_TextConfig *config, int32_t *start, int32_t *end)](#oh_textconfig_getselection) | Obtains the selected text area.|
| [InputMethod_ErrorCode OH_TextConfig_GetWindowId(InputMethod_TextConfig *config, int32_t *windowId)](#oh_textconfig_getwindowid) | Obtains the window ID.|
| [InputMethod_ErrorCode OH_TextConfig_GetPlaceholder(InputMethod_TextConfig *config, char16_t *placeholder,size_t *length)](#oh_textconfig_getplaceholder) | Obtains the placeholder text.|
| [InputMethod_ErrorCode OH_TextConfig_GetAbilityName(InputMethod_TextConfig *config, char16_t *abilityName,size_t *length)](#oh_textconfig_getabilityname) | Obtains the ability name.|

## Function Description

### OH_TextConfig_Create()

```
InputMethod_TextConfig *OH_TextConfig_Create(void)
```

**Description**

Creates an [InputMethod_TextConfig](capi-inputmethod-inputmethod-textconfig.md) instance.

**Since**: 12

**Returns**

| Type| Description|
| -- | -- |
| [InputMethod_TextConfig](capi-inputmethod-inputmethod-textconfig.md) * | If the operation is successful, a pointer to the created [InputMethod_TextConfig](capi-inputmethod-inputmethod-textconfig.md) instance is returned.<br> If the operation failed, **NULL** is returned, which may be caused by insufficient application address space.|

### OH_TextConfig_Destroy()

```
void OH_TextConfig_Destroy(InputMethod_TextConfig *config)
```

**Description**

Destroys an [InputMethod_TextConfig](capi-inputmethod-inputmethod-textconfig.md) instance.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [InputMethod_TextConfig](capi-inputmethod-inputmethod-textconfig.md) *config | Pointer to the [InputMethod_TextConfig](capi-inputmethod-inputmethod-textconfig.md) instance to be destroyed.|

### OH_TextConfig_SetInputType()

```
InputMethod_ErrorCode OH_TextConfig_SetInputType(InputMethod_TextConfig *config, InputMethod_TextInputType inputType)
```

**Description**

Sets the text box type.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [InputMethod_TextConfig](capi-inputmethod-inputmethod-textconfig.md) *config | Pointer to the [InputMethod_TextConfig](capi-inputmethod-inputmethod-textconfig.md) instance whose value is to be set.|
| [InputMethod_TextInputType](capi-inputmethod-types-capi-h.md#inputmethod_textinputtype) inputType | Input type of the text box.|

**Returns**

| Type| Description|
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | An error code.<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - Success.<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - An unexpected null pointer.<br> For details about the error codes, see [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode).|

### OH_TextConfig_SetEnterKeyType()

```
InputMethod_ErrorCode OH_TextConfig_SetEnterKeyType(InputMethod_TextConfig *config, InputMethod_EnterKeyType enterKeyType)
```

**Description**

Sets the Enter key type.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [InputMethod_TextConfig](capi-inputmethod-inputmethod-textconfig.md) *config | Pointer to the [InputMethod_TextConfig](capi-inputmethod-inputmethod-textconfig.md) instance whose value is to be set.|
| [InputMethod_EnterKeyType](capi-inputmethod-types-capi-h.md#inputmethod_enterkeytype) enterKeyType | Enter key type.|

**Returns**

| Type| Description|
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | An error code.<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - Success.<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - An unexpected null pointer.<br> For details about the error codes, see [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode).|

### OH_TextConfig_SetPreviewTextSupport()

```
InputMethod_ErrorCode OH_TextConfig_SetPreviewTextSupport(InputMethod_TextConfig *config, bool supported)
```

**Description**

Sets the text preview feature.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [InputMethod_TextConfig](capi-inputmethod-inputmethod-textconfig.md) *config | Pointer to the [InputMethod_TextConfig](capi-inputmethod-inputmethod-textconfig.md) instance whose value is to be set.|
| bool supported | Whether text preview is supported.|

**Returns**

| Type| Description|
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | An error code.<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - Success.<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - An unexpected null pointer.<br> For details about the error codes, see [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode).|

### OH_TextConfig_SetSelection()

```
InputMethod_ErrorCode OH_TextConfig_SetSelection(InputMethod_TextConfig *config, int32_t start, int32_t end)
```

**Description**

Sets the selected text area.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [InputMethod_TextConfig](capi-inputmethod-inputmethod-textconfig.md) *config | Pointer to the [InputMethod_TextConfig](capi-inputmethod-inputmethod-textconfig.md) instance whose value is to be set.|
| int32_t start | Start position of the selected text.|
| int32_t end | End position of the selected text.|

**Returns**

| Type| Description|
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | An error code.<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - Success.<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - An unexpected null pointer.<br> For details about the error codes, see [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode).|

### OH_TextConfig_SetWindowId()

```
InputMethod_ErrorCode OH_TextConfig_SetWindowId(InputMethod_TextConfig *config, int32_t windowId)
```

**Description**

Sets the window ID.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [InputMethod_TextConfig](capi-inputmethod-inputmethod-textconfig.md) *config | Pointer to the [InputMethod_TextConfig](capi-inputmethod-inputmethod-textconfig.md) instance whose value is to be set.|
| int32_t windowId | Window ID of the application bound to the input method.|

**Returns**

| Type| Description|
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | An error code.<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - Success.<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - An unexpected null pointer.<br> For details about the error codes, see [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode).|

### OH_TextConfig_SetPlaceholder()

```
InputMethod_ErrorCode OH_TextConfig_SetPlaceholder(InputMethod_TextConfig *config, const char16_t *placeholder,size_t length)
```

**Description**

Sets the placeholder text.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [InputMethod_TextConfig](capi-inputmethod-inputmethod-textconfig.md) *config | Pointer to the [InputMethod_TextConfig](capi-inputmethod-inputmethod-textconfig.md) instance whose value is to be set.|
| const char16_t *placeholder | Pointer to a UTF-16 encoded double-byte string. If a null pointer is passed, the placeholder text is an empty string.|
| size_t length | Number of elements in the memory to which **placeholder** points, including the null character of the double-byte string.1. If **length** is **0**, the placeholder text is an empty string.2. The maximum length of UTF-16 encoding is 255 characters (the null character of the string is not included in the count). If the length exceeds 255 characters, the extra characters will be truncated.|

**Returns**

| Type| Description|
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode):<br>     **IME_ERR_OK** = **0**: indicates success.<br>     **IME_ERR_NULL_POINTER** = **12802000**: indicates an unexpected null pointer.|

### OH_TextConfig_SetAbilityName()

```
InputMethod_ErrorCode OH_TextConfig_SetAbilityName(InputMethod_TextConfig *config, const char16_t *abilityName,size_t length)
```

**Description**

Sets the ability name.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [InputMethod_TextConfig](capi-inputmethod-inputmethod-textconfig.md) *config | Pointer to the [InputMethod_TextConfig](capi-inputmethod-inputmethod-textconfig.md) instance whose value is to be set.|
| const char16_t *abilityName | Pointer to a UTF-16 encoded double-byte string. If a null pointer is passed, the ability name is an empty string.|
| size_t length | Number of elements in the memory to which **abilityName** points, including the null character of the double-byte string.1. If **length** is **0**, the ability name is set to an empty string.2. The maximum length of UTF-16 encoding is 127 characters (the null character of the string is not included in the count). If the length exceeds 127 characters, the extra characters will be truncated.|

**Returns**

| Type| Description|
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode):<br>     **IME_ERR_OK** = **0**: indicates success.<br>     **IME_ERR_NULL_POINTER** = **12802000**: indicates an unexpected null pointer.|

### OH_TextConfig_GetInputType()

```
InputMethod_ErrorCode OH_TextConfig_GetInputType(InputMethod_TextConfig *config, InputMethod_TextInputType *inputType)
```

**Description**

Obtains the text box type.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [InputMethod_TextConfig](capi-inputmethod-inputmethod-textconfig.md) *config | Pointer to the [InputMethod_TextConfig](capi-inputmethod-inputmethod-textconfig.md) instance whose value is to be obtained.|
| [InputMethod_TextInputType](capi-inputmethod-types-capi-h.md#inputmethod_textinputtype) *inputType | Pointer to the [InputMethod_TextInputType](capi-inputmethod-types-capi-h.md#inputmethod_textinputtype) instance. Input type of the text box.|

**Returns**

| Type| Description|
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | An error code.<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - Success.<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - An unexpected null pointer.<br> For details about the error codes, see [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode).|

### OH_TextConfig_GetEnterKeyType()

```
InputMethod_ErrorCode OH_TextConfig_GetEnterKeyType(InputMethod_TextConfig *config, InputMethod_EnterKeyType *enterKeyType)
```

**Description**

Obtains the Enter key type.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [InputMethod_TextConfig](capi-inputmethod-inputmethod-textconfig.md) *config | Pointer to the [InputMethod_TextConfig](capi-inputmethod-inputmethod-textconfig.md) instance whose value is to be obtained.|
| [InputMethod_EnterKeyType](capi-inputmethod-types-capi-h.md#inputmethod_enterkeytype) *enterKeyType | Pointer to the [InputMethod_EnterKeyType](capi-inputmethod-types-capi-h.md#inputmethod_enterkeytype) instance. Enter key type of the text box.|

**Returns**

| Type| Description|
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | An error code.<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - Success.<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - An unexpected null pointer.<br> For details about the error codes, see [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode).|

### OH_TextConfig_IsPreviewTextSupported()

```
InputMethod_ErrorCode OH_TextConfig_IsPreviewTextSupported(InputMethod_TextConfig *config, bool *supported)
```

**Description**

Obtains whether the text preview feature is supported.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [InputMethod_TextConfig](capi-inputmethod-inputmethod-textconfig.md) *config | Pointer to the [InputMethod_TextConfig](capi-inputmethod-inputmethod-textconfig.md) instance whose value is to be obtained.|
| bool *supported | Whether text preview is supported.|

**Returns**

| Type| Description|
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | An error code.<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - Success.<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - An unexpected null pointer.<br> For details about the error codes, see [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode).|

### OH_TextConfig_GetCursorInfo()

```
InputMethod_ErrorCode OH_TextConfig_GetCursorInfo(InputMethod_TextConfig *config, InputMethod_CursorInfo **cursorInfo)
```

**Description**

Obtains the cursor information.

**Since**: 12


**Parameters**

| Name                                                                         | Description|
|------------------------------------------------------------------------------| -- |
| [InputMethod_TextConfig](capi-inputmethod-inputmethod-textconfig.md) *config | Pointer to the [InputMethod_TextConfig](capi-inputmethod-inputmethod-textconfig.md) instance whose value is to be obtained.|
| [InputMethod_CursorInfo](capi-inputmethod-inputmethod-cursorinfo.md) **cursorInfo                                      | Cursor information.|

**Returns**

| Type| Description|
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | An error code.<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - Success.<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - An unexpected null pointer.<br> For details about the error codes, see [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode).|

### OH_TextConfig_GetTextAvoidInfo()

```
InputMethod_ErrorCode OH_TextConfig_GetTextAvoidInfo(InputMethod_TextConfig *config, InputMethod_TextAvoidInfo **avoidInfo)
```

**Description**

Obtains the avoidance information.

**Since**: 12


**Parameters**

| Name                                                                         | Description|
|------------------------------------------------------------------------------| -- |
| [InputMethod_TextConfig](capi-inputmethod-inputmethod-textconfig.md) *config | Text configuration information.|
| [InputMethod_TextAvoidInfo](capi-inputmethod-inputmethod-textavoidinfo.md) **avoidInfo                                    | Text box avoidance information.|

**Returns**

| Type| Description|
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | An error code.<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - Success.<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - An unexpected null pointer.<br> For details about the error codes, see [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode).<br>|

### OH_TextConfig_GetSelection()

```
InputMethod_ErrorCode OH_TextConfig_GetSelection(InputMethod_TextConfig *config, int32_t *start, int32_t *end)
```

**Description**

Obtains the selected text area.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [InputMethod_TextConfig](capi-inputmethod-inputmethod-textconfig.md) *config | Pointer to the [InputMethod_TextConfig](capi-inputmethod-inputmethod-textconfig.md) instance whose value is to be obtained.|
| int32_t *start | Start position of the selected text.|
| int32_t *end | End position of the selected text.|

**Returns**

| Type| Description|
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | An error code.<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - Success.<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - An unexpected null pointer.<br> For details about the error codes, see [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode).|

### OH_TextConfig_GetWindowId()

```
InputMethod_ErrorCode OH_TextConfig_GetWindowId(InputMethod_TextConfig *config, int32_t *windowId)
```

**Description**

Obtains the window ID.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [InputMethod_TextConfig](capi-inputmethod-inputmethod-textconfig.md) *config | Pointer to the [InputMethod_TextConfig](capi-inputmethod-inputmethod-textconfig.md) instance whose value is to be obtained.|
| int32_t *windowId | Window ID of the application bound to the input method.|

**Returns**

| Type| Description|
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | An error code.<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - Success.<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - An unexpected null pointer.<br> For details about the error codes, see [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode).|

### OH_TextConfig_GetPlaceholder()

```
InputMethod_ErrorCode OH_TextConfig_GetPlaceholder(InputMethod_TextConfig *config, char16_t *placeholder,size_t *length)
```

**Description**

Obtains the placeholder text.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [InputMethod_TextConfig](capi-inputmethod-inputmethod-textconfig.md) *config | Pointer to the [InputMethod_TextConfig](capi-inputmethod-inputmethod-textconfig.md) instance whose value is to be obtained.|
| char16_t *placeholder | Pointer to the placeholder text. The memory of this pointer is maintained by the caller.|
| size_t *length | Pointer to the length of the placeholder text, in double bytes. The length includes the null character of the string.1. As an input parameter, **length** indicates the available length of the memory to which **placeholder** points. As an output parameter, it indicates the actual length of the placeholder text.2. If **placeholder** is a null pointer and **length** points to valid memory, **length** will be set to the actual length of the placeholder text, and an error will be thrown.3. If both **placeholder** and **length** point to valid memory, but the value of **length** is less than the actual length of the placeholder text, **length** will be set to the actual length of the placeholder text, and an error will be thrown.|

**Returns**

| Type| Description|
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode):<br>     **IME_ERR_OK** = **0**: indicates success.<br>     **IME_ERR_PARAMCHECK** = **401**: indicates that parameter check failed.<br>     **IME_ERR_NULL_POINTER** = **12802000**: indicates an unexpected null pointer.|

### OH_TextConfig_GetAbilityName()

```
InputMethod_ErrorCode OH_TextConfig_GetAbilityName(InputMethod_TextConfig *config, char16_t *abilityName,size_t *length)
```

**Description**

Obtains the ability name.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [InputMethod_TextConfig](capi-inputmethod-inputmethod-textconfig.md) *config | Pointer to the [InputMethod_TextConfig](capi-inputmethod-inputmethod-textconfig.md) instance whose value is to be obtained.|
| char16_t *abilityName | Pointer to the ability name. The memory of this pointer is maintained by the caller.|
| size_t *length | Pointer to the length of the ability name, in double bytes. The length includes the null character of the string.1. As an input parameter, **length** indicates the available length of the memory to which **abilityName** points. As an output parameter, it indicates the actual length of the ability name.2. If **abilityName** is a null pointer and **length** points to valid memory, **length** will be set to the actual length of the ability name, and an error will be thrown.3. If both **abilityName** and **length** point to valid memory, but the value of **length** is less than the actual length of the ability name, **length** will be set to the actual length of the ability name, and an error will be thrown.|

**Returns**

| Type| Description|
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode):<br>     **IME_ERR_OK** = **0**: indicates success.<br>     **IME_ERR_PARAMCHECK** = **401**: indicates that parameter check failed.<br>     **IME_ERR_NULL_POINTER** = **12802000**: indicates an unexpected null pointer.|
