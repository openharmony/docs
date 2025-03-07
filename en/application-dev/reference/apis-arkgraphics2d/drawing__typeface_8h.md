# drawing_typeface.h


## Overview

The **drawing_typeface.h** file declares the functions related to the typeface in the drawing module. Different platforms have their own default typefaces. You can also parse the .ttf file to obtain the typefaces specified by the third party, such as SimSun and SimHei.

**File to include**: &lt;native_drawing/drawing_typeface.h&gt;;

**Library**: libnative_drawing.so

**Since**: 11

**Related module**: [Drawing](_drawing.md)


## Summary


### Functions

| Name| Description|
| -------- | -------- |
| [OH_Drawing_Typeface](_drawing.md#oh_drawing_typeface) \* [OH_Drawing_TypefaceCreateDefault](_drawing.md#oh_drawing_typefacecreatedefault) (void) | Creates a default **OH_Drawing_Typeface** object.|
| [OH_Drawing_Typeface](_drawing.md#oh_drawing_typeface) \* [OH_Drawing_TypefaceCreateFromFile](_drawing.md#oh_drawing_typefacecreatefromfile) (const char \*path, int index) | Creates an **OH_Drawing_Typeface** object through a file.|
| [OH_Drawing_Typeface](_drawing.md#oh_drawing_typeface) \* [OH_Drawing_TypefaceCreateFromFileWithArguments](_drawing.md#oh_drawing_typefacecreatefromfilewitharguments) (const char \*path, const [OH_Drawing_FontArguments](_drawing.md#oh_drawing_fontarguments) \*fontArguments) | Creates an **OH_Drawing_Typeface** object with font arguments through a file. If the **OH_Drawing_Typeface** object does not support the variation described in the font arguments, this function creates an **OH_Drawing_Typeface** object with the default font arguments. In this case, this function provides the same capability as [OH_Drawing_TypefaceCreateFromFile](_drawing.md#oh_drawing_typefacecreatefromfile).| 
| [OH_Drawing_Typeface](_drawing.md#oh_drawing_typeface) \* [OH_Drawing_TypefaceCreateFromCurrent](_drawing.md#oh_drawing_typefacecreatefromcurrent) (const [OH_Drawing_Typeface](_drawing.md#oh_drawing_typeface) \*current, const [OH_Drawing_FontArguments](_drawing.md#oh_drawing_fontarguments) \*fontArguments) | Creates an **OH_Drawing_Typeface** object with font arguments based on an existing **OH_Drawing_Typeface** object.| 
| [OH_Drawing_Typeface](_drawing.md#oh_drawing_typeface) \* [OH_Drawing_TypefaceCreateFromStream](_drawing.md#oh_drawing_typefacecreatefromstream) ([OH_Drawing_MemoryStream](_drawing.md#oh_drawing_memorystream) \*, int32_t index) | Creates an **OH_Drawing_Typeface** object through a memory stream. If the memory stream is an invalid font file, a null pointer is returned. After the memory stream is passed in, the ownership is transferred and you cannot release it.|
| void [OH_Drawing_TypefaceDestroy](_drawing.md#oh_drawing_typefacedestroy) ([OH_Drawing_Typeface](_drawing.md#oh_drawing_typeface) \*) | Destroys an **OH_Drawing_Typeface** object and reclaims the memory occupied by the object.|
| [OH_Drawing_FontArguments](_drawing.md#oh_drawing_fontarguments) \* [OH_Drawing_FontArgumentsCreate](_drawing.md#oh_drawing_fontargumentscreate) (void) | Creates an **OH_Drawing_FontArguments** object. The font arguments are used to create an **OH_Drawing_Typeface** object with custom attributes.| 
| [OH_Drawing_ErrorCode](_drawing.md#oh_drawing_errorcode) [OH_Drawing_FontArgumentsAddVariation](_drawing.md#oh_drawing_fontargumentsaddvariation) ([OH_Drawing_FontArguments](_drawing.md#oh_drawing_fontarguments) \*fontArguments, const char \*axis, float value) | Adds a variation to an **OH_Drawing_FontArguments** object.| 
| [OH_Drawing_ErrorCode](_drawing.md#oh_drawing_errorcode) [OH_Drawing_FontArgumentsDestroy](_drawing.md#oh_drawing_fontargumentsdestroy) ([OH_Drawing_FontArguments](_drawing.md#oh_drawing_fontarguments) \*fontArguments) | Destroys an **OH_Drawing_FontArguments** object.| 
