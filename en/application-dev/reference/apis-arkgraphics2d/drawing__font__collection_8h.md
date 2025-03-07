# drawing_font_collection.h


## Overview

The **drawing_font_collection.h** file declares the functions related to the font collection in the drawing module.

**File to include**: &lt;native_drawing/drawing_font_collection.h&gt;

**Library**: libnative_drawing.so

**Since**: 8

**Related module**: [Drawing](_drawing.md)


## Summary


### Functions

| Name| Description| 
| -------- | -------- |
| [OH_Drawing_FontCollection](_drawing.md#oh_drawing_fontcollection) \* [OH_Drawing_CreateFontCollection](_drawing.md#oh_drawing_createfontcollection) (void) | Creates an [OH_Drawing_FontCollection](_drawing.md#oh_drawing_fontcollection) object. The [OH_Drawing_FontCollection](_drawing.md#oh_drawing_fontcollection) object created by this function can be used by only one [OH_Drawing_TypographyCreate](_drawing.md#oh_drawing_typographycreate) object. To share an [OH_Drawing_FontCollection](_drawing.md#oh_drawing_fontcollection) object among multiple [OH_Drawing_TypographyCreate](_drawing.md#oh_drawing_typographycreate) objects, use [OH_Drawing_CreateSharedFontCollection](_drawing.md#oh_drawing_createsharedfontcollection) to create it.| 
| void [OH_Drawing_DestroyFontCollection](_drawing.md#oh_drawing_destroyfontcollection) ([OH_Drawing_FontCollection](_drawing.md#oh_drawing_fontcollection) \*) | Destroys an **OH_Drawing_FontCollection** object and reclaims the memory occupied by the object.| 
| void [OH_Drawing_DisableFontCollectionFallback](_drawing.md#oh_drawing_disablefontcollectionfallback) ([OH_Drawing_FontCollection](_drawing.md#oh_drawing_fontcollection) \*fontCollection) | Disables the alternate fonts.| 
| void [OH_Drawing_DisableFontCollectionSystemFont](_drawing.md#oh_drawing_disablefontcollectionsystemfont) ([OH_Drawing_FontCollection](_drawing.md#oh_drawing_fontcollection) \*fontCollection) | Disables the system fonts.| 
| [OH_Drawing_FontCollection](_drawing.md#oh_drawing_fontcollection) \* [OH_Drawing_CreateSharedFontCollection](_drawing.md#oh_drawing_createsharedfontcollection) (void) | Creates an [OH_Drawing_FontCollection](_drawing.md#oh_drawing_fontcollection) object that is shareable.| 
| void [OH_Drawing_ClearFontCaches](_drawing.md#oh_drawing_clearfontcaches) ([OH_Drawing_FontCollection](_drawing.md#oh_drawing_fontcollection) \*) | Clears the font cache. (The font cache has a memory limit and a clearing mechanism. It occupies limited memory. You are not advised to clear it unless otherwise required.)|
| OH_Drawing_FontCollection \* [OH_Drawing_GetFontCollectionGlobalInstance](_drawing.md#oh_drawing_getfontcollectionglobalinstance) (void) | Obtains the global **OH_Drawing_FontCollection** object, which can be used to sense the theme font information. Do not release the object. | 
