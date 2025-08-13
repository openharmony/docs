# inputmethod_cursor_info_capi.h
<!--Kit: IME Kit-->
<!--Subsystem: MiscServices-->
<!--Owner: @illybyy-->
<!--SE: @andeszhang-->
<!--TSE: @murphy1984-->

## Overview

Provides methods for creating, destroying, reading, and writing cursor information objects.

**File to include**: <inputmethod/inputmethod_cursor_info_capi.h>

**Library**: libohinputmethod.so

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Since**: 12

**Related module**: [InputMethod](capi-inputmethod.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [InputMethod_CursorInfo](capi-inputmethod-inputmethod-cursorinfo.md) | InputMethod_CursorInfo | Represents the cursor information, including the coordinates, width, and height of the cursor.|

### Function

| Name| Description                                        |
| -- |--------------------------------------------|
| [InputMethod_CursorInfo *OH_CursorInfo_Create(double left, double top, double width, double height)](#oh_cursorinfo_create) | Creates an [InputMethod_CursorInfo](capi-inputmethod-inputmethod-cursorinfo.md) instance.|
| [void OH_CursorInfo_Destroy(InputMethod_CursorInfo *cursorInfo)](#oh_cursorinfo_destroy) | Destroys an [InputMethod_CursorInfo](capi-inputmethod-inputmethod-cursorinfo.md) instance.     |
| [InputMethod_ErrorCode OH_CursorInfo_SetRect(InputMethod_CursorInfo *cursorInfo, double left, double top, double width, double height)](#oh_cursorinfo_setrect) | Sets the cursor information.                                 |
| [InputMethod_ErrorCode OH_CursorInfo_GetRect(InputMethod_CursorInfo *cursorInfo, double *left, double *top, double *width, double *height)](#oh_cursorinfo_getrect) | Obtains the cursor information.                                 |

## Function Description

### OH_CursorInfo_Create()

```
InputMethod_CursorInfo *OH_CursorInfo_Create(double left, double top, double width, double height)
```

**Description**

Creates an [InputMethod_CursorInfo](capi-inputmethod-inputmethod-cursorinfo.md) instance.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| double left | Absolute value of the distance between the cursor's leftmost point and the left edge of the physical screen.|
| double top | Absolute value of the distance between the cursor's top vertex and the top edge of the physical screen.|
| double width | Width.|
| double height | Height.|

**Returns**

| Type| Description|
| -- | -- |
| [InputMethod_CursorInfo](capi-inputmethod-inputmethod-cursorinfo.md) * | If the operation is successful, a pointer to the created [InputMethod_CursorInfo](capi-inputmethod-inputmethod-cursorinfo.md) instance is returned.<br>  If the operation failed, **NULL** is returned, which may be caused by insufficient application address space.|

### OH_CursorInfo_Destroy()

```
void OH_CursorInfo_Destroy(InputMethod_CursorInfo *cursorInfo)
```

**Description**

Destroys an [InputMethod_CursorInfo](capi-inputmethod-inputmethod-cursorinfo.md) instance.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [InputMethod_CursorInfo](capi-inputmethod-inputmethod-cursorinfo.md) *cursorInfo | Pointer to the [InputMethod_CursorInfo](capi-inputmethod-inputmethod-cursorinfo.md) instance to be destroyed.|

### OH_CursorInfo_SetRect()

```
InputMethod_ErrorCode OH_CursorInfo_SetRect(InputMethod_CursorInfo *cursorInfo, double left, double top, double width, double height)
```

**Description**

Sets the cursor information.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [InputMethod_CursorInfo](capi-inputmethod-inputmethod-cursorinfo.md) *cursorInfo | Pointer to the [InputMethod_CursorInfo](capi-inputmethod-inputmethod-cursorinfo.md) instance.|
| double left | Absolute value of the distance between the cursor's leftmost point and the left edge of the physical screen.|
| double top | Absolute value of the distance between the cursor's top vertex and the top edge of the physical screen.|
| double width | Width.|
| double height | Height.|

**Returns**

| Type| Description|
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | An error code.<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - Success.<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - An unexpected null pointer.<br> For details about the error codes, see [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode).|

### OH_CursorInfo_GetRect()

```
InputMethod_ErrorCode OH_CursorInfo_GetRect(InputMethod_CursorInfo *cursorInfo, double *left, double *top, double *width, double *height)
```

**Description**

Obtains the cursor information.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [InputMethod_CursorInfo](capi-inputmethod-inputmethod-cursorinfo.md) *cursorInfo | Pointer to the [InputMethod_CursorInfo](capi-inputmethod-inputmethod-cursorinfo.md) instance.|
| double *left | Absolute value of the distance between the cursor's leftmost point and the left edge of the physical screen.|
| double *top | Absolute value of the distance between the cursor's top vertex and the top edge of the physical screen.|
| double *width | Width.|
| double *height | Height.|

**Returns**

| Type| Description|
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | An error code.<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - Success.<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - An unexpected null pointer.<br> For details about the error codes, see [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode).|
