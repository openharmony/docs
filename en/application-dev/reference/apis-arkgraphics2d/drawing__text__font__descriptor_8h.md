# drawing_text_font_descriptor.h


## Overview

The **drawing_text_font_descriptor.h** file declares the capabilities of font information, such as obtaining font information and searching for a font.

**File to include**: <native_drawing/drawing_text_font_descriptor.h>

**Library**: libnative_drawing.so

**Since**: 14

**Related module**: [Drawing](_drawing.md)


## Summary


### Types

| Name| Description|
| -------- | -------- |
| typedef enum [OH_Drawing_SystemFontType](_drawing.md#oh_drawing_systemfonttype) [OH_Drawing_SystemFontType](_drawing.md#oh_drawing_systemfonttype) | Defines an enum for the system font types. |


### Enums

| Name| Description|
| -------- | -------- |
| [OH_Drawing_SystemFontType](_drawing.md#oh_drawing_systemfonttype-1) { ALL = 1 &lt;&lt; 0, GENERIC = 1 &lt;&lt; 1, STYLISH = 1 &lt;&lt; 2, INSTALLED = 1 &lt;&lt; 3 } | Enumerates the system font types. |


### Functions

| Name| Description|
| -------- | -------- |
| [OH_Drawing_FontDescriptor](_o_h___drawing___font_descriptor.md) \* [OH_Drawing_MatchFontDescriptors](_drawing.md#oh_drawing_matchfontdescriptors) ([OH_Drawing_FontDescriptor](_o_h___drawing___font_descriptor.md) \*, size_t \*) | Obtains all system font descriptors that match a font descriptor. In the [OH_Drawing_FontDescriptor](_o_h___drawing___font_descriptor.md) struct, the **path** field is not used for matching, and other fields are valid only when they are not set to their default values. If all fields in [OH_Drawing_FontDescriptor](_o_h___drawing___font_descriptor.md) are set to their default values, all system font descriptors are obtained. If no matching is found, NULL is returned. |
| void [OH_Drawing_DestroyFontDescriptors](_drawing.md#oh_drawing_destroyfontdescriptors) ([OH_Drawing_FontDescriptor](_o_h___drawing___font_descriptor.md) \*, size_t) | Releases an array of [OH_Drawing_FontDescriptor](_o_h___drawing___font_descriptor.md) objects. |
| [OH_Drawing_FontDescriptor](_o_h___drawing___font_descriptor.md) \* [OH_Drawing_GetFontDescriptorByFullName](_drawing.md#oh_drawing_getfontdescriptorbyfullname) (const [OH_Drawing_String](_o_h___drawing___string.md) \*, [OH_Drawing_SystemFontType](_drawing.md#oh_drawing_systemfonttype)) | Obtains a font descriptor based on the font name and type. System fonts, style fonts, and user-installed fonts are supported. A font descriptor is a data structure that describes font features. It contains details of the font appearance and properties. |
| [OH_Drawing_Array](_drawing.md#oh_drawing_array) \* [OH_Drawing_GetSystemFontFullNamesByType](_drawing.md#oh_drawing_getsystemfontfullnamesbytype) ([OH_Drawing_SystemFontType](_drawing.md#oh_drawing_systemfonttype)) | Obtains an array of font names by font type. |
| const [OH_Drawing_String](_o_h___drawing___string.md) \* [OH_Drawing_GetSystemFontFullNameByIndex](_drawing.md#oh_drawing_getsystemfontfullnamebyindex) ([OH_Drawing_Array](_drawing.md#oh_drawing_array) \*, size_t) | Obtains the font name with the specified index in the font name array. |
| void [OH_Drawing_DestroySystemFontFullNames](_drawing.md#oh_drawing_destroysystemfontfullnames) ([OH_Drawing_Array](_drawing.md#oh_drawing_array) \*) | Releases the memory occupied by the font name array obtained by font type. |
