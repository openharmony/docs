# inputmethod_text_avoid_info_capi.h


## Overview

Provides methods for creating, destroying, reading, and writing the text box avoidance information objects.

**Library**: libohinputmethod.so

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Since**: 12

**Related module**: [InputMethod](_input_method.md)


## Summary


### Types

| Name| Description| 
| -------- | -------- |
| [InputMethod_TextAvoidInfo](_input_method.md#inputmethod_textavoidinfo) | Text box avoidance information.| 


### Functions

| Name| Description| 
| -------- | -------- |
| [InputMethod_TextAvoidInfo](_input_method.md#inputmethod_textavoidinfo) \* [OH_TextAvoidInfo_Create](_input_method.md#oh_textavoidinfo_create) (double positionY, double height) | Creates an [InputMethod_TextAvoidInfo](_input_method.md#inputmethod_textavoidinfo) instance.| 
| void [OH_TextAvoidInfo_Destroy](_input_method.md#oh_textavoidinfo_destroy) ([InputMethod_TextAvoidInfo](_input_method.md#inputmethod_textavoidinfo) \*info) | Destroys an [InputMethod_TextAvoidInfo](_input_method.md#inputmethod_textavoidinfo) instance.| 
| [InputMethod_ErrorCode](_input_method.md#inputmethod_errorcode) [OH_TextAvoidInfo_SetPositionY](_input_method.md#oh_textavoidinfo_setpositiony) ([InputMethod_TextAvoidInfo](_input_method.md#inputmethod_textavoidinfo) \*info, double positionY) | Sets the Y coordinate in [InputMethod_TextAvoidInfo](_input_method.md#inputmethod_textavoidinfo).| 
| [InputMethod_ErrorCode](_input_method.md#inputmethod_errorcode) [OH_TextAvoidInfo_SetHeight](_input_method.md#oh_textavoidinfo_setheight) ([InputMethod_TextAvoidInfo](_input_method.md#inputmethod_textavoidinfo) \*info, double height) | Sets the height in [InputMethod_TextAvoidInfo](_input_method.md#inputmethod_textavoidinfo).| 
| [InputMethod_ErrorCode](_input_method.md#inputmethod_errorcode) [OH_TextAvoidInfo_GetPositionY](_input_method.md#oh_textavoidinfo_getpositiony) ([InputMethod_TextAvoidInfo](_input_method.md#inputmethod_textavoidinfo) \*info, double \*positionY) | Obtains the Y coordinate from [InputMethod_TextAvoidInfo](_input_method.md#inputmethod_textavoidinfo).| 
| [InputMethod_ErrorCode](_input_method.md#inputmethod_errorcode) [OH_TextAvoidInfo_GetHeight](_input_method.md#oh_textavoidinfo_getheight) ([InputMethod_TextAvoidInfo](_input_method.md#inputmethod_textavoidinfo) \*info, double \*height) | Obtains the height from [InputMethod_TextAvoidInfo](_input_method.md#inputmethod_textavoidinfo).| 
