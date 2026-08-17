# InputMethod_CursorInfo

<!--Kit: IME Kit-->
<!--Subsystem: MiscServices-->
<!--Owner: @codexu62-->
<!--Designer: @andeszhang-->
<!--Tester: @murphy84-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=4c244f2ed12456a4c6059eccff764e442d7872b9 translatedAt=2026-08-12T08:24:35.676Z pushedAt=2026-08-13T12:06:31.996Z -->

```c
typedef struct InputMethod_CursorInfo InputMethod_CursorInfo
```

## Overview

**InputMethod_CursorInfo** is an opaque type for cursor information. It describes the position and size of the cursor on the physical screen during text input, including the horizontal coordinate (**left**), vertical coordinate (**top**), width (**width**), and height (**height**) of the cursor.

Purpose: Supplies the input method service with precise position and size information of the cursor. The input method relies on this information to implement the following features:

- Cursor tracking: The keyboard panel adjusts its display position based on the cursor position to avoid obscuring the region where the cursor resides.

- Candidate word positioning: The input method displays the candidate word region near the cursor to deliver an accurate input experience.

- Region avoidance calculation: The input method calculates the region to be avoided according to the cursor height and position.

Usage scenarios:

1. Carrying cursor information in **TextConfig**: When the app returns **TextConfig** in the [OH_TextEditorProxy_GetTextConfigFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_gettextconfigfunc) callback, the **CursorInfo** contained in it informs the input method of the current cursor position and size.

2. Active notification of cursor updates: When the cursor position changes (for example, the user moves the cursor or text insertion shifts the cursor), the app actively notifies the input method of the latest cursor position via [OH_InputMethodProxy_NotifyCursorUpdate](capi-inputmethod-inputmethod-proxy-capi-h.md#oh_inputmethodproxy_notifycursorupdate).

Related functions

| Function | Description |
| -- | -- |
| [OH_CursorInfo_Create](capi-inputmethod-cursor-info-capi-h.md#oh_cursorinfo_create) | Creates a **CursorInfo** instance. The values of **left**, **top**, **width**, and **height** need to be passed in. |
| [OH_CursorInfo_Destroy](capi-inputmethod-cursor-info-capi-h.md#oh_cursorinfo_destroy) | Destroys a **CursorInfo** instance. |
| [OH_CursorInfo_SetRect](capi-inputmethod-cursor-info-capi-h.md#oh_cursorinfo_setrect) | Sets the position and size of the cursor. |
| [OH_CursorInfo_GetRect](capi-inputmethod-cursor-info-capi-h.md#oh_cursorinfo_getrect) | Obtains the position and size of the cursor. |

Relationship with other structs:

- Relationship with **InputMethod_TextConfig**: **CursorInfo** is a sub-property of **TextConfig**. When the app returns **TextConfig** in the [OH_TextEditorProxy_GetTextConfigFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_gettextconfigfunc) callback, **TextConfig** contains **CursorInfo**. The input method obtains cursor information via [OH_TextConfig_GetCursorInfo](capi-inputmethod-text-config-capi-h.md#oh_textconfig_getcursorinfo). Therefore, you need to first create a **CursorInfo** instance and set valid cursor coordinates, and then assign the **CursorInfo** to **TextConfig** within the **GetTextConfig** callback.

- Relationship with **OH_InputMethodProxy_NotifyCursorUpdate**: **CursorInfo** is passed directly as a parameter of **NotifyCursorUpdate** to actively notify the input method of cursor position changes. After **CursorInfo** is created and updated, the app sends the latest cursor information to the input method through **NotifyCursorUpdate**.

- Relationship with **InputMethod_InputMethodProxy**: The **NotifyCursorUpdate** function requires both **InputMethod_InputMethodProxy** (returned by the attach function) and **InputMethod_CursorInfo**. **inputMethodProxy** identifies the interaction channel while **cursorInfo** carries cursor data.

**Since**: 12

**Related module**: [InputMethod](capi-inputmethod.md)

**Header file**: [inputmethod_cursor_info_capi.h](capi-inputmethod-cursor-info-capi-h.md)