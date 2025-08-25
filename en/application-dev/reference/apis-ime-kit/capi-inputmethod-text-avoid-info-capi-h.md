# inputmethod_text_avoid_info_capi.h
<!--Kit: IME Kit-->
<!--Subsystem: MiscServices-->
<!--Owner: @illybyy-->
<!--Designer: @andeszhang-->
<!--Tester: @murphy1984-->
<!--Adviser: @zhang_yixin13-->

## Overview

Provides methods for creating, destroying, reading, and writing the text box avoidance information objects.

**File to include**: <inputmethod/inputmethod_text_avoid_info_capi.h>

**Library**: libohinputmethod.so

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Since**: 12

**Related module**: [InputMethod](capi-inputmethod.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [InputMethod_TextAvoidInfo](capi-inputmethod-inputmethod-textavoidinfo.md) | InputMethod_TextAvoidInfo | Represents the information used by the input box to avoid the keyboard.|

### Function

| Name| Description                                           |
| -- |-----------------------------------------------|
| [InputMethod_TextAvoidInfo *OH_TextAvoidInfo_Create(double positionY, double height)](#oh_textavoidinfo_create) | Creates an [InputMethod_TextAvoidInfo](capi-inputmethod-inputmethod-textavoidinfo.md) instance.|
| [void OH_TextAvoidInfo_Destroy(InputMethod_TextAvoidInfo *info)](#oh_textavoidinfo_destroy) | Destroys an [InputMethod_TextAvoidInfo](capi-inputmethod-inputmethod-textavoidinfo.md) instance.     |
| [InputMethod_ErrorCode OH_TextAvoidInfo_SetPositionY(InputMethod_TextAvoidInfo *info, double positionY)](#oh_textavoidinfo_setpositiony) | Sets the Y coordinate in [InputMethod_TextAvoidInfo](capi-inputmethod-inputmethod-textavoidinfo.md).   |
| [InputMethod_ErrorCode OH_TextAvoidInfo_SetHeight(InputMethod_TextAvoidInfo *info, double height)](#oh_textavoidinfo_setheight) | Sets the height in [InputMethod_TextAvoidInfo](capi-inputmethod-inputmethod-textavoidinfo.md).    |
| [InputMethod_ErrorCode OH_TextAvoidInfo_GetPositionY(InputMethod_TextAvoidInfo *info, double *positionY)](#oh_textavoidinfo_getpositiony) | Obtains the Y coordinate from [InputMethod_TextAvoidInfo](capi-inputmethod-inputmethod-textavoidinfo.md).    |
| [InputMethod_ErrorCode OH_TextAvoidInfo_GetHeight(InputMethod_TextAvoidInfo *info, double *height)](#oh_textavoidinfo_getheight) | Obtains the height from [InputMethod_TextAvoidInfo](capi-inputmethod-inputmethod-textavoidinfo.md).     |

## Function Description

### OH_TextAvoidInfo_Create()

```
InputMethod_TextAvoidInfo *OH_TextAvoidInfo_Create(double positionY, double height)
```

**Description**

Creates an [InputMethod_TextAvoidInfo](capi-inputmethod-inputmethod-textavoidinfo.md) instance.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| double positionY | Y coordinate of the text box.|
| double height | Height of the text box.|

**Returns**

| Type| Description|
| -- | -- |
| [InputMethod_TextAvoidInfo](capi-inputmethod-inputmethod-textavoidinfo.md) * | If the operation is successful, a pointer to the created [InputMethod_TextAvoidInfo](capi-inputmethod-inputmethod-textavoidinfo.md) instance is returned.<br> If the operation failed, **NULL** is returned, which may be caused by insufficient application address space.|

### OH_TextAvoidInfo_Destroy()

```
void OH_TextAvoidInfo_Destroy(InputMethod_TextAvoidInfo *info)
```

**Description**

Destroys an [InputMethod_TextAvoidInfo](capi-inputmethod-inputmethod-textavoidinfo.md) instance.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [InputMethod_TextAvoidInfo](capi-inputmethod-inputmethod-textavoidinfo.md) *info | Pointer to the [InputMethod_TextAvoidInfo](capi-inputmethod-inputmethod-textavoidinfo.md) instance to be destroyed.|

### OH_TextAvoidInfo_SetPositionY()

```
InputMethod_ErrorCode OH_TextAvoidInfo_SetPositionY(InputMethod_TextAvoidInfo *info, double positionY)
```

**Description**

Sets the Y coordinate in [InputMethod_TextAvoidInfo](capi-inputmethod-inputmethod-textavoidinfo.md).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [InputMethod_TextAvoidInfo](capi-inputmethod-inputmethod-textavoidinfo.md) *info | Pointer to the [InputMethod_TextAvoidInfo](capi-inputmethod-inputmethod-textavoidinfo.md) instance whose value is to be set.|
| double positionY | Absolute value of the distance between the text box's top vertex and the top edge of the physical screen.|

**Returns**

| Type| Description|
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | An error code.<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - Success.<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - An unexpected null pointer.<br> For details about the error codes, see [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode).|

### OH_TextAvoidInfo_SetHeight()

```
InputMethod_ErrorCode OH_TextAvoidInfo_SetHeight(InputMethod_TextAvoidInfo *info, double height)
```

**Description**

Sets the height in [InputMethod_TextAvoidInfo](capi-inputmethod-inputmethod-textavoidinfo.md).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [InputMethod_TextAvoidInfo](capi-inputmethod-inputmethod-textavoidinfo.md) *info | Pointer to the [InputMethod_TextAvoidInfo](capi-inputmethod-inputmethod-textavoidinfo.md) instance whose value is to be set.|
| double height | Height.|

**Returns**

| Type| Description|
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | An error code.<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - Success.<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - An unexpected null pointer.<br> For details about the error codes, see [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode).|

### OH_TextAvoidInfo_GetPositionY()

```
InputMethod_ErrorCode OH_TextAvoidInfo_GetPositionY(InputMethod_TextAvoidInfo *info, double *positionY)
```

**Description**

Obtains the Y coordinate from [InputMethod_TextAvoidInfo](capi-inputmethod-inputmethod-textavoidinfo.md).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [InputMethod_TextAvoidInfo](capi-inputmethod-inputmethod-textavoidinfo.md) *info | Pointer to the [InputMethod_TextAvoidInfo](capi-inputmethod-inputmethod-textavoidinfo.md) instance whose value is to be obtained.|
| double *positionY | Absolute value of the distance between the text box's top vertex and the top edge of the physical screen.|

**Returns**

| Type| Description|
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | An error code.<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - Success.<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - An unexpected null pointer.<br> For details about the error codes, see [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode).|

### OH_TextAvoidInfo_GetHeight()

```
InputMethod_ErrorCode OH_TextAvoidInfo_GetHeight(InputMethod_TextAvoidInfo *info, double *height)
```

**Description**

Obtains the height from [InputMethod_TextAvoidInfo](capi-inputmethod-inputmethod-textavoidinfo.md).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [InputMethod_TextAvoidInfo](capi-inputmethod-inputmethod-textavoidinfo.md) *info | Pointer to the [InputMethod_TextAvoidInfo](capi-inputmethod-inputmethod-textavoidinfo.md) instance whose value is to be obtained.|
| double *height | Height of the text box.|

**Returns**

| Type| Description|
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | An error code.<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - Success.<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - An unexpected null pointer.<br> For details about the error codes, see [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode).|
