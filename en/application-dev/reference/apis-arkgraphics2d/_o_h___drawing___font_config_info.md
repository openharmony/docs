# OH_Drawing_FontConfigInfo


## Overview

The OH_Drawing_FontConfigInfo struct describes the information about a system font configuration.

**Since**: 12

**Related module**: [Drawing](_drawing.md)

**Header file**: [drawing_text_typography.h](drawing__text__typography_8h.md)

## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| size_t [fontDirSize](#fontdirsize) | Number of system font file paths.| 
| size_t [fontGenericInfoSize](#fontgenericinfosize) | Number of generic fonts.| 
| size_t [fallbackGroupSize](#fallbackgroupsize) | Number of font fallbacks.| 
| char \*\* [fontDirSet](#fontdirset) | Double pointer to the system font file paths.| 
| [OH_Drawing_FontGenericInfo](_o_h___drawing___font_generic_info.md) \* [fontGenericInfoSet](#fontgenericinfoset) | Pointer to a set of generic fonts.| 
| [OH_Drawing_FontFallbackGroup](_o_h___drawing___font_fallback_group.md) \* [fallbackGroupSet](#fallbackgroupset) | Pointer to a set of font fallbacks.| 


## Member Variable Description


### fallbackGroupSet

```
OH_Drawing_FontFallbackGroup* OH_Drawing_FontConfigInfo::fallbackGroupSet
```

**Description**

Pointer to a set of font fallbacks.


### fallbackGroupSize

```
size_t OH_Drawing_FontConfigInfo::fallbackGroupSize
```

**Description**

Number of font fallbacks.


### fontDirSet

```
char** OH_Drawing_FontConfigInfo::fontDirSet
```

**Description**

Double pointer to the system font file paths.


### fontDirSize

```
size_t OH_Drawing_FontConfigInfo::fontDirSize
```

**Description**

Number of system font file paths.


### fontGenericInfoSet

```
OH_Drawing_FontGenericInfo* OH_Drawing_FontConfigInfo::fontGenericInfoSet
```

**Description**

Pointer to a set of generic fonts.


### fontGenericInfoSize

```
size_t OH_Drawing_FontConfigInfo::fontGenericInfoSize
```

**Description**

Number of generic font sets.
