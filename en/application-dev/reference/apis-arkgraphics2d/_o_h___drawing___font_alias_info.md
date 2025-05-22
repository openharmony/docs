# OH_Drawing_FontAliasInfo


## Overview

The OH_Drawing_FontAliasInfo struct describes the information about a font alias.

**Since**: 12

**Related module**: [Drawing](_drawing.md)

**Header file**: [drawing_text_typography.h](drawing__text__typography_8h.md)

## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| char \* [familyName](#familyname) | Pointer to the name of a font family. | 
| int [weight](#weight) | Font weight. If the value is greater than 0, only the fonts with the specified weight in the font family are contained. If the value is 0, all the fonts in the font family are contained. | 


## Member Variable Description


### familyName

```
char* OH_Drawing_FontAliasInfo::familyName
```
**Description**

Pointer to the name of a font family.


### weight

```
int OH_Drawing_FontAliasInfo::weight
```
**Description**

Font weight. If the value is greater than 0, only the fonts with the specified weight in the font family are contained. If the value is 0, all the fonts in the font family are contained.
