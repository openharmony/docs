# inputmethod_cursor_info_capi.h


## Overview

Provides methods for creating, destroying, reading, and writing cursor information objects.

**Library**: libohinputmethod.so

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Since**: 12

**Related module**: [InputMethod](_input_method.md)


## Summary


### Types

| Name| Description| 
| -------- | -------- |
| [InputMethod_CursorInfo](_input_method.md#inputmethod_cursorinfo) | Cursor information.| 


### Functions

| Name| Description| 
| -------- | -------- |
| [InputMethod_CursorInfo](_input_method.md#inputmethod_cursorinfo) \* [OH_CursorInfo_Create](_input_method.md#oh_cursorinfo_create) (double left, double top, double width, double height) | Creates an [InputMethod_CursorInfo](_input_method.md#inputmethod_cursorinfo) instance.| 
| void [OH_CursorInfo_Destroy](_input_method.md#oh_cursorinfo_destroy) ([InputMethod_CursorInfo](_input_method.md#inputmethod_cursorinfo) \*cursorInfo) | Destroys an [InputMethod_CursorInfo](_input_method.md#inputmethod_cursorinfo) instance.| 
| [InputMethod_ErrorCode](_input_method.md#inputmethod_errorcode) [OH_CursorInfo_SetRect](_input_method.md#oh_cursorinfo_setrect) ([InputMethod_CursorInfo](_input_method.md#inputmethod_cursorinfo) \*cursorInfo, double left, double top, double width, double height) | Sets the cursor information.| 
| [InputMethod_ErrorCode](_input_method.md#inputmethod_errorcode) [OH_CursorInfo_GetRect](_input_method.md#oh_cursorinfo_getrect) ([InputMethod_CursorInfo](_input_method.md#inputmethod_cursorinfo) \*cursorInfo, double \*left, double \*top, double \*width, double \*height) | Obtains the cursor information.| 
