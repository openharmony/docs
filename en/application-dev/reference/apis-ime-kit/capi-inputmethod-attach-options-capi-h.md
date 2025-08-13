# inputmethod_attach_options_capi.h
<!--Kit: IME Kit-->
<!--Subsystem: MiscServices-->
<!--Owner: @illybyy-->
<!--SE: @andeszhang-->
<!--TSE: @murphy1984-->

## Overview

Provides methods for creating, destroying, reading, and writing the option object bound to the input method.

**File to include**: <inputmethod/inputmethod_attach_options_capi.h>

**Library**: libohinputmethod.so

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Since**: 12

**Related module**: [InputMethod](capi-inputmethod.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [InputMethod_AttachOptions](capi-inputmethod-inputmethod-attachoptions.md) | InputMethod_AttachOptions | Options for binding the input method.  |

### Function

| Name| Description                                            |
| -- |------------------------------------------------|
| [InputMethod_AttachOptions *OH_AttachOptions_Create(bool showKeyboard)](#oh_attachoptions_create) | Creates an [InputMethod_AttachOptions](capi-inputmethod-inputmethod-attachoptions.md) instance.    |
| [InputMethod_AttachOptions *OH_AttachOptions_CreateWithRequestKeyboardReason(bool showKeyboard, InputMethod_RequestKeyboardReason requestKeyboardReason)](#oh_attachoptions_createwithrequestkeyboardreason) | Creates an [InputMethod_AttachOptions](capi-inputmethod-inputmethod-attachoptions.md) instance.    |
| [void OH_AttachOptions_Destroy(InputMethod_AttachOptions *options)](#oh_attachoptions_destroy) | Destroys an [InputMethod_AttachOptions](capi-inputmethod-inputmethod-attachoptions.md) instance.   |
| [InputMethod_ErrorCode OH_AttachOptions_IsShowKeyboard(InputMethod_AttachOptions *options, bool *showKeyboard)](#oh_attachoptions_isshowkeyboard) | Obtains the value that indicates whether to display the keyboard from [InputMethod_AttachOptions](capi-inputmethod-inputmethod-attachoptions.md).|
| [InputMethod_ErrorCode OH_AttachOptions_GetRequestKeyboardReason(InputMethod_AttachOptions *options, int *requestKeyboardReason)](#oh_attachoptions_getrequestkeyboardreason) | Obtains the value that indicates whether to display the keyboard from [InputMethod_AttachOptions](capi-inputmethod-inputmethod-attachoptions.md).|

## Function Description

### OH_AttachOptions_Create()

```
InputMethod_AttachOptions *OH_AttachOptions_Create(bool showKeyboard)
```

**Description**

Creates an [InputMethod_AttachOptions](capi-inputmethod-inputmethod-attachoptions.md) instance.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| bool showKeyboard | Whether to display the keyboard.|

**Returns**

| Type| Description|
| -- | -- |
| [InputMethod_AttachOptions](capi-inputmethod-inputmethod-attachoptions.md) * | If the operation is successful, a pointer to the created [InputMethod_AttachOptions](capi-inputmethod-inputmethod-attachoptions.md) instance is returned.<br> If the operation failed, **NULL** is returned, which may be caused by insufficient application address space.|

### OH_AttachOptions_CreateWithRequestKeyboardReason()

```
InputMethod_AttachOptions *OH_AttachOptions_CreateWithRequestKeyboardReason(bool showKeyboard, InputMethod_RequestKeyboardReason requestKeyboardReason)
```

**Description**

Creates an [InputMethod_AttachOptions](capi-inputmethod-inputmethod-attachoptions.md) instance.

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| bool showKeyboard | Whether to display the keyboard.|
| [InputMethod_RequestKeyboardReason](capi-inputmethod-types-capi-h.md#inputmethod_requestkeyboardreason) requestKeyboardReason |  Reason for requesting the keyboard.|

**Returns**

| Type| Description|
| -- | -- |
| [InputMethod_AttachOptions](capi-inputmethod-inputmethod-attachoptions.md) * | If the operation is successful, a pointer to the created [InputMethod_AttachOptions](capi-inputmethod-inputmethod-attachoptions.md) instance is returned.<br> If the operation failed, **NULL** is returned, which may be caused by insufficient application address space.|

### OH_AttachOptions_Destroy()

```
void OH_AttachOptions_Destroy(InputMethod_AttachOptions *options)
```

**Description**

Destroys an [InputMethod_AttachOptions](capi-inputmethod-inputmethod-attachoptions.md) instance.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [InputMethod_AttachOptions](capi-inputmethod-inputmethod-attachoptions.md) *options | [InputMethod_AttachOptions](capi-inputmethod-inputmethod-attachoptions.md) instance to be destroyed.|

### OH_AttachOptions_IsShowKeyboard()

```
InputMethod_ErrorCode OH_AttachOptions_IsShowKeyboard(InputMethod_AttachOptions *options, bool *showKeyboard)
```

**Description**

Obtains the value that indicates whether to display the keyboard from [InputMethod_AttachOptions](capi-inputmethod-inputmethod-attachoptions.md).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [InputMethod_AttachOptions](capi-inputmethod-inputmethod-attachoptions.md) *options | Pointer to the [InputMethod_AttachOptions](capi-inputmethod-inputmethod-attachoptions.md) instance whose value is to be read.|
| bool *showKeyboard | Pointer to whether to display the keyboard during binding. **true**: The keyboard is displayed after the binding is complete. **false**: The keyboard is hidden after the binding is complete.|

**Returns**

| Type| Description|
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | An error code.<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - Success.<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - An unexpected null pointer.<br> For details about the error codes, see [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode).|

### OH_AttachOptions_GetRequestKeyboardReason()

```
InputMethod_ErrorCode OH_AttachOptions_GetRequestKeyboardReason(InputMethod_AttachOptions *options, int *requestKeyboardReason)
```

**Description**

Obtains the value that indicates whether to display the keyboard from [InputMethod_AttachOptions](capi-inputmethod-inputmethod-attachoptions.md).

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| [InputMethod_AttachOptions](capi-inputmethod-inputmethod-attachoptions.md) *options | Pointer to the [InputMethod_AttachOptions](capi-inputmethod-inputmethod-attachoptions.md) instance whose value is to be read.|
| int *requestKeyboardReason |  Pointer to the [InputMethod_AttachOptions](capi-inputmethod-inputmethod-attachoptions.md) instance. It indicates the reason for requesting the keyboard.|

**Returns**

| Type| Description|
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | An error code.<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - Success.<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - An unexpected null pointer.<br> For details about the error codes, see [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode).|
