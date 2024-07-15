# drawing_font_mgr.h


## Overview

The **drawing_font_mgr.h** file declares the functions related to font management in the drawing module. The functions can be used to load fonts and match available fonts in the system.

**File to include**: &lt;native_drawing/drawing_font_mgr.h&gt;

**Library**: libnative_drawing.so

**Since**: 12

**Related module**: [Drawing](_drawing.md)


## Summary


### Functions

| Name| Description| 
| -------- | -------- |
| [OH_Drawing_FontMgr](_drawing.md#oh_drawing_fontmgr) \* [OH_Drawing_FontMgrCreate](_drawing.md#oh_drawing_fontmgrcreate) (void) | Creates an **OH_Drawing_FontMgr** object.| 
| void [OH_Drawing_FontMgrDestroy](_drawing.md#oh_drawing_fontmgrdestroy) ([OH_Drawing_FontMgr](_drawing.md#oh_drawing_fontmgr) \*) | Destroys an **OH_Drawing_FontMgr** object and reclaims the memory occupied by the object.| 
| int [OH_Drawing_FontMgrGetFamilyCount](_drawing.md#oh_drawing_fontmgrgetfamilycount) ([OH_Drawing_FontMgr](_drawing.md#oh_drawing_fontmgr) \*) | Obtains the number of font families.| 
| char \* [OH_Drawing_FontMgrGetFamilyName](_drawing.md#oh_drawing_fontmgrgetfamilyname) ([OH_Drawing_FontMgr](_drawing.md#oh_drawing_fontmgr) \*, int index) | Obtains the font family name based on an index.| 
| void [OH_Drawing_FontMgrDestroyFamilyName](_drawing.md#oh_drawing_fontmgrdestroyfamilyname) (char \*familyName) | Reclaims the memory occupied by a font family name.| 
| [OH_Drawing_FontStyleSet](_drawing.md#oh_drawing_fontstyleset) \* [OH_Drawing_FontMgrCreateFontStyleSet](_drawing.md#oh_drawing_fontmgrcreatefontstyleset) ([OH_Drawing_FontMgr](_drawing.md#oh_drawing_fontmgr) \*, int index) | Creates a font style set from an **OH_Drawing_FontMgr** object.| 
| void [OH_Drawing_FontMgrDestroyFontStyleSet](_drawing.md#oh_drawing_fontmgrdestroyfontstyleset) ([OH_Drawing_FontStyleSet](_drawing.md#oh_drawing_fontstyleset) \*) | Reclaims the memory occupied by a font style set.| 
| [OH_Drawing_FontStyleSet](_drawing.md#oh_drawing_fontstyleset) \* [OH_Drawing_FontMgrMatchFamily](_drawing.md#oh_drawing_fontmgrmatchfamily) ([OH_Drawing_FontMgr](_drawing.md#oh_drawing_fontmgr) \*, const char \*familyName) | Obtains a font style set based on a font family name.| 
| [OH_Drawing_Typeface](_drawing.md#oh_drawing_typeface) \* [OH_Drawing_FontMgrMatchFamilyStyle](_drawing.md#oh_drawing_fontmgrmatchfamilystyle) ([OH_Drawing_FontMgr](_drawing.md#oh_drawing_fontmgr) \*, const char \*familyName, [OH_Drawing_FontStyleStruct](_o_h___drawing___font_style_struct.md)) | Obtains a typeface based on the font style information and font family name.| 
| [OH_Drawing_Typeface](_drawing.md#oh_drawing_typeface) \* [OH_Drawing_FontMgrMatchFamilyStyleCharacter](_drawing.md#oh_drawing_fontmgrmatchfamilystylecharacter) ([OH_Drawing_FontMgr](_drawing.md#oh_drawing_fontmgr) \*, const char \*familyName, [OH_Drawing_FontStyleStruct](_o_h___drawing___font_style_struct.md), const char \*bcp47[], int bcp47Count, int32_t character) | Obtains a typeface for the specified character.| 
| [OH_Drawing_Typeface](_drawing.md#oh_drawing_typeface) \* [OH_Drawing_FontStyleSetCreateTypeface](_drawing.md#oh_drawing_fontstylesetcreatetypeface) ([OH_Drawing_FontStyleSet](_drawing.md#oh_drawing_fontstyleset) \*, int index) | Obtains a typeface for the specified index.| 
| [OH_Drawing_FontStyleStruct](_o_h___drawing___font_style_struct.md) [OH_Drawing_FontStyleSetGetStyle](_drawing.md#oh_drawing_fontstylesetgetstyle) ([OH_Drawing_FontStyleSet](_drawing.md#oh_drawing_fontstyleset) \*, int32_t index, char \*\*styleName) | Obtains the font style.| 
| void [OH_Drawing_FontStyleSetFreeStyleName](_drawing.md#oh_drawing_fontstylesetfreestylename) (char \*\*styleName) | Reclaims the memory occupied by a font style.| 
| [OH_Drawing_Typeface](_drawing.md#oh_drawing_typeface) \* [OH_Drawing_FontStyleSetMatchStyle](_drawing.md#oh_drawing_fontstylesetmatchstyle) ([OH_Drawing_FontStyleSet](_drawing.md#oh_drawing_fontstyleset) \*, [OH_Drawing_FontStyleStruct](_o_h___drawing___font_style_struct.md) fontStyleStruct) | Obtains the typeface closest to the font style.| 
| int [OH_Drawing_FontStyleSetCount](_drawing.md#oh_drawing_fontstylesetcount) ([OH_Drawing_FontStyleSet](_drawing.md#oh_drawing_fontstyleset) \*) | Obtains the number of fonts in the font style set.| 
