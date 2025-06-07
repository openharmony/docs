# OH_Drawing_FontFallbackGroup


## Overview

The OH_Drawing_FontFallbackInfo struct describes the information about a font fallback group.

**Since**: 12

**Related module**: [Drawing](_drawing.md)

**Header file**: [drawing_text_typography.h](drawing__text__typography_8h.md)

## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| char \* [groupName](#groupname) | Pointer to the name of the group corresponding to the font fallback group. If null is passed in, all fonts in the font fallback group can be used. | 
| size_t [fallbackInfoSize](#fallbackinfosize) | Number of font fallbacks. | 
| [OH_Drawing_FontFallbackInfo](_o_h___drawing___font_fallback_info.md) \* [fallbackInfoSet](#fallbackinfoset) | Pointer to a set of font fallbacks. | 


## Member Variable Description


### fallbackInfoSet

```
OH_Drawing_FontFallbackInfo* OH_Drawing_FontFallbackGroup::fallbackInfoSet
```
**Description**

Pointer to a set of font fallbacks.


### fallbackInfoSize

```
size_t OH_Drawing_FontFallbackGroup::fallbackInfoSize
```
**Description**

Number of font fallbacks.


### groupName

```
char* OH_Drawing_FontFallbackGroup::groupName
```
**Description**

Pointer to the name of the group corresponding to the font fallback group. If null is passed in, all fonts in the font fallback group can be used.
