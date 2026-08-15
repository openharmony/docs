# inputmethod_cursor_info_capi.h

<!--Kit: IME Kit-->
<!--Subsystem: MiscServices-->
<!--Owner: @codexu62-->
<!--Designer: @andeszhang-->
<!--Tester: @murphy84-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=4c244f2ed12456a4c6059eccff764e442d7872b9 translatedAt=2026-08-12T08:25:47.668Z pushedAt=2026-08-13T12:06:25.638Z -->

## Overview

Provides methods for creating, destroying, reading, and writing cursor information objects.

Functionality: Creates and manages **InputMethod_CursorInfo** instances which describe the position and size of the cursor on the physical screen during text input. Cursor information serves as critical data for the input method service to determine the cursor region, support precise input, and implement cursor tracking.

Usage scenarios: **CursorInfo** is used in the following scenarios:

1. Setting cursor information within **TextConfig**: When the app returns **TextConfig** in the **GetTextConfig** callback, the contained **CursorInfo** informs the input method of the current cursor position, based on which the input method locates the cursor region.

2. Proactively notifying cursor updates: When the cursor position changes (such as when the user moves the cursor or text insertion shifts the cursor), the app proactively notifies the input method of the latest cursor position via **OH_InputMethodProxy_NotifyCursorUpdate**.

Use effect: The input method adjusts the position of the keyboard panel according to the cursor coordinates stored in **CursorInfo** to achieve cursor tracking, and displays the candidate word region near the cursor.

**File to include**: <inputmethod/inputmethod_cursor_info_capi.h>

**Library**: libohinputmethod.so

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Since**: 12

**Related module**: [InputMethod](capi-inputmethod.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [InputMethod_CursorInfo](capi-inputmethod-inputmethod-cursorinfo.md) | InputMethod_CursorInfo | Cursor information describing the position and size of the cursor on the physical screen. This is an opaque type. You cannot directly access its member variables and can only work with functions provided in this header file. Coordinates shall be absolute coordinates of the physical screen, in px. |

### Functions

| Name| Description                                        |
| -- |--------------------------------------------|
| [InputMethod_CursorInfo *OH_CursorInfo_Create(double left, double top, double width, double height)](#oh_cursorinfo_create) | Creates a new **InputMethod_CursorInfo** instance. Must be called in pair with **OH_CursorInfo_Destroy**. |
| [void OH_CursorInfo_Destroy(InputMethod_CursorInfo *cursorInfo)](#oh_cursorinfo_destroy) | Destroys an **InputMethod_CursorInfo** instance and releases memory allocated by the create function. |
| [InputMethod_ErrorCode OH_CursorInfo_SetRect(InputMethod_CursorInfo *cursorInfo, double left, double top, double width, double height)](#oh_cursorinfo_setrect) | Sets the content of cursor information. Coordinates shall be absolute coordinates of the physical screen in px with a value range ≥ 0. |
| [InputMethod_ErrorCode OH_CursorInfo_GetRect(InputMethod_CursorInfo *cursorInfo, double *left, double *top, double *width, double *height)](#oh_cursorinfo_getrect) | Obtains cursor information. Output values are absolute physical screen coordinates in px with a value range ≥ 0. |

## Function Description

### OH_CursorInfo_Create()

```c
InputMethod_CursorInfo *OH_CursorInfo_Create(double left, double top, double width, double height)
```

**Description**

Creates a new [InputMethod_CursorInfo](capi-inputmethod-inputmethod-cursorinfo.md) instance and initializes cursor position and size information.

Paired calls: Must be called in pair with [OH_CursorInfo_Destroy](#oh_cursorinfo_destroy). Objects created via this create function shall be destroyed via the destroy function; otherwise, memory leaks will occur.

Lifecycle management:

- After creation, cursor information can be modified via **SetRect** and read via **GetRect**.

- The **CursorInfo** instance can be passed to the input method as a property of **TextConfig** (returned within the **GetTextConfig** callback).

- The **CursorInfo** instance can also be used as an argument of **NotifyCursorUpdate** to proactively notify the input method of cursor updates.

- In both scenarios, memory for **CursorInfo** is managed by you. The input method only reads data during callback execution or the calling of **NotifyCursorUpdate**, and does not retain references after the operation completes.

- It shall be destroyed via the destroy function when no longer required.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| double left | Input parameter, indicating the absolute distance from the left edge of the cursor to the left side of the physical screen.<br>Usage scenarios: Identifies the horizontal starting position of the cursor on the screen, based on which the input method locates the cursor region.<br>Use effect: The input method determines the horizontal cursor position from the **left** value to implement cursor tracking for the keyboard panel.<br>Unit: px (physical pixel).<br>Value range: ≥ 0.<br>Constraints: Must be an absolute coordinate of the physical screen. Relative coordinates (such as coordinates relative to a parent component or window) are prohibited. Absolute physical screen coordinates shall still be used in multi-window scenarios.<br>Effective mechanism: The input method service calculates the actual cursor position on the screen based on this value. |
| double top | Input parameter, indicating the absolute distance from the top edge of the cursor to the top side of the physical screen.<br>Usage scenarios: Identifies the vertical starting position of the cursor on the screen.<br>Use effect: The input method determines the vertical cursor position from the **top** value for keyboard avoidance calculation and candidate word positioning.<br>Unit: px (physical pixel).<br>Value range: ≥ 0.<br>Constraints: Must be an absolute coordinate of the physical screen. Relative coordinates are prohibited. |
| double width | Input parameter, indicating the width of the cursor.<br>Usage scenarios: Describes the horizontal dimension of the cursor, based on which the input method determines the size of the cursor region.<br>Use effect: The input method adjusts the positioning of the candidate word region according to cursor width.<br>Unit: px (physical pixel).<br>Value range: ≥ 0.<br>Constraints: Normally set to the actual displayed width of the cursor. A single-character cursor is typically 1–2 px wide; a selection cursor uses the width of the selected text. |
| double height | Input parameter, indicating the height of the cursor.<br>Usage scenarios: Describes the vertical dimension of the cursor, based on which the input method determines the cursor region size and calculates the avoidance region.<br>Use effect: The input method adjusts the avoidance region for the keyboard panel according to cursor height.<br>Unit: px (physical pixel).<br>Value range: ≥ 0.<br>Constraints: Normally set to the actual displayed height of the cursor and consistent with the text line height. |

**Returns**

| Type| Description|
| -- | -- |
| [InputMethod_CursorInfo](capi-inputmethod-inputmethod-cursorinfo.md) * | Pointer type.<br>Creation succeeded: Returns a pointer to a newly created **InputMethod_CursorInfo** instance. The pointer is valid and available for subsequent operations.<br>Creation failed: Returns **NULL**. Possible causes include exhaustion of the app address space (insufficient memory).<br>Null check: You shall verify whether the return value is **NULL** before use. If the value is **NULL**, the pointer shall not be used. You shall check memory status or retry later.<br>Memory management: Memory for the returned pointer is allocated internally by the create function. You shall release it via **OH_CursorInfo_Destroy** and shall not use **free()** or other release methods. |

### OH_CursorInfo_Destroy()

```c
void OH_CursorInfo_Destroy(InputMethod_CursorInfo *cursorInfo)
```

**Description**

Destroys an [InputMethod_CursorInfo](capi-inputmethod-inputmethod-cursorinfo.md) instance and releases memory resources allocated by the create function.

Paired calls: Must be called in pair with **OH_CursorInfo_Create**. Each instance created via the create function shall be destroyed exactly once via the destroy function.

Lifecycle management:

- After the destroy function is called, the **cursorInfo** pointer becomes invalid and shall not be used further.

- Do not call the destroy function twice with the same **cursorInfo** pointer; otherwise, a double-free error will occur.

- If **cursorInfo** is in use within an input method callback (for example, during execution of the **GetTextConfig** callback), the destroy function shall not be called at this time. Destruction shall be performed after the callback returns.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [InputMethod_CursorInfo](capi-inputmethod-inputmethod-cursorinfo.md) *cursorInfo | Input pointer pointing to the **InputMethod_CursorInfo** instance to be destroyed.<br>Usage scenarios: Called when the **CursorInfo** is no longer required. Typical timing is after **NotifyCursorUpdate** completes or upon app exit.<br>Use effect: Memory referenced by **cursorInfo** is released, and the pointer becomes invalid.<br>Null pointer handling: If **cursorInfo** is **NULL**, the destroy function performs no operation (built-in null safety) and will not cause crashes. However, you are advised to avoid passing **NULL**.<br>Memory release responsibility: You are responsible for calling the destroy function at the appropriate time to release the memory. |

### OH_CursorInfo_SetRect()

```c
InputMethod_ErrorCode OH_CursorInfo_SetRect(InputMethod_CursorInfo *cursorInfo, double left, double top, double width, double height)
```

**Description**

Sets cursor information to update the position and size of the cursor. This function is used to modify cursor information on an existing **CursorInfo** instance without recreating an instance.

Precondition: **cursorInfo** shall be a valid instance created via **OH_CursorInfo_Create**.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [InputMethod_CursorInfo](capi-inputmethod-inputmethod-cursorinfo.md) *cursorInfo | Input pointer pointing to an **InputMethod_CursorInfo** instance.<br>Null pointer handling: Must not be **NULL**. Passing **NULL** returns **IME_ERR_NULL_POINTER**.<br>Precondition: Must be a valid instance created via **OH_CursorInfo_Create**. |
| double left | Input parameter, indicating the absolute distance from the left edge of the cursor to the left side of the physical screen.<br>Unit: px (physical pixel).<br>Value range: ≥0.<br>Constraints: Must be an absolute coordinate of the physical screen. Relative coordinates are prohibited.<br>Effective mechanism: After the parameter is set, the original **left** value is overwritten, and the next **GetRect** call will return the new value. |
| double top | Input parameter, indicating the absolute distance from the top edge of the cursor to the top side of the physical screen.<br>Unit: px (physical pixel).<br>Value range: ≥0.<br>Constraints: Must be an absolute coordinate of the physical screen. Relative coordinates are prohibited. |
| double width | Input parameter, indicating the width of the cursor.<br>Usage scenarios: Describes the horizontal dimension of the cursor, based on which the input method determines the size of the cursor region.<br>Use effect: The input method adjusts the positioning of the candidate word region according to cursor width.<br>Unit: px (physical pixel).<br>Value range: ≥ 0.<br>Constraints: Normally set to the actual displayed width of the cursor. A single-character cursor is typically 1–2 px wide; a selection cursor uses the width of the selected text. |
| double height | Input parameter, indicating the height of the cursor.<br>Usage scenarios: Describes the vertical dimension of the cursor, based on which the input method determines the cursor region size and calculates the avoidance region.<br>Use effect: The input method adjusts the avoidance region for the keyboard panel according to cursor height.<br>Parameter unit: px (physical pixel).<br>Value range: ≥ 0.<br>Constraints: Normally set to the actual displayed height of the cursor and consistent with the text line height. |

**Returns**

| Type| Description|
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | Returns a specific error code.<br>- [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode): Success. Cursor information has been updated.<br>- [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode): Unexpected null pointer. Returned when **cursorInfo** is **NULL**. Ensure **cursorInfo** is a valid pointer before invocation.<br>Error handling suggestions: If **IME_ERR_NULL_POINTER** is returned, verify whether **cursorInfo** is a valid pointer. For details about the error codes, see [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode). |

### OH_CursorInfo_GetRect()

```c
InputMethod_ErrorCode OH_CursorInfo_GetRect(InputMethod_CursorInfo *cursorInfo, double *left, double *top, double *width, double *height)
```

**Description**

Obtains cursor information to read the position and size of the cursor.

Precondition: **cursorInfo** shall be a valid instance created via **OH_CursorInfo_Create**.
**left**, **top**, **width**, and **height** shall point to valid double variables.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [InputMethod_CursorInfo](capi-inputmethod-inputmethod-cursorinfo.md) *cursorInfo | Input pointer pointing to an **InputMethod_CursorInfo** instance.<br>Null pointer handling: Must not be **NULL**. Passing **NULL** returns **IME_ERR_NULL_POINTER**.<br>Precondition: Must be a valid instance created via **OH_CursorInfo_Create**. |
| double *left | Output pointer storing the absolute distance from the left edge of the cursor to the left side of the physical screen.<br>Unit: px (physical pixel).<br>Output value range: ≥0.<br>Null pointer handling: Must not be **NULL**. Passing **NULL** returns **IME_ERR_NULL_POINTER**.<br>Memory allocation responsibility: You shall allocate memory for the **double** variable. **GetRect** writes the value into the memory supplied by you and does not allocate memory. |
| double *top | Output pointer storing the absolute distance from the top edge of the cursor to the top side of the physical screen.<br>Unit: px (physical pixel).<br>Output value range: ≥0.<br>Null pointer handling: Must not be **NULL**.<br>Memory allocation responsibility: You shall allocate memory for the **double** variable. |
| double *width | Output pointer storing the width of the cursor.<br>Unit: px (physical pixel).<br>Output value range: ≥0.<br>Null pointer handling: Must not be **NULL**.<br>Memory allocation responsibility: You shall allocate memory for the **double** variable. |
| double *height | Output pointer storing the height of the cursor.<br>Unit: px (physical pixel).<br>Output value range: ≥0.<br>Null pointer handling: Must not be **NULL**.<br>Memory allocation responsibility: You shall allocate memory for the **double** variable. |

**Returns**

| Type| Description|
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | Returns a specific error code.<br>- [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode): Success. **left**, **top**, **width**, and **height** are assigned valid cursor information.<br>- [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode): Unexpected null pointer. Returned when **cursorInfo**, **left**, **top**, **width**, or **height** is **NULL**. Ensure all parameters are valid pointers before invocation.<br>Error handling suggestions: If **IME_ERR_NULL_POINTER** is returned, verify whether all parameters are valid pointers. If **IME_ERR_OK** is returned, the four output parameters carry valid cursor information values. For details about the error codes, see [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode). |