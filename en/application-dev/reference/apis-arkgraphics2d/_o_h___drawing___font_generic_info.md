# OH_Drawing_FontGenericInfo


## Overview

The OH_Drawing_FontGenericInfo struct describes the information about generic fonts supported by the system.

**Since**: 12

**Related module**: [Drawing](_drawing.md)

**Header file**: [drawing_text_typography.h](drawing__text__typography_8h.md)

## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| char \* [familyName](#familyname) | Pointer to the name of a font family. | 
| size_t [aliasInfoSize](#aliasinfosize) | Number of font aliases. | 
| size_t [adjustInfoSize](#adjustinfosize) | Number of font weight mappings. | 
| [OH_Drawing_FontAliasInfo](_o_h___drawing___font_alias_info.md) \* [aliasInfoSet](#aliasinfoset) | Pointer to a set of font aliases. | 
| [OH_Drawing_FontAdjustInfo](_o_h___drawing___font_adjust_info.md) \* [adjustInfoSet](#adjustinfoset) | Pointer to a set of font weight mappings. | 


## Member Variable Description


### adjustInfoSet

```
OH_Drawing_FontAdjustInfo* OH_Drawing_FontGenericInfo::adjustInfoSet
```
**Description**

Pointer to a set of font weight mappings.


### adjustInfoSize

```
size_t OH_Drawing_FontGenericInfo::adjustInfoSize
```
**Description**

Number of font weight mappings.


### aliasInfoSet

```
OH_Drawing_FontAliasInfo* OH_Drawing_FontGenericInfo::aliasInfoSet
```
**Description**

Pointer to a set of font aliases.


### aliasInfoSize

```
size_t OH_Drawing_FontGenericInfo::aliasInfoSize
```
**Description**

Number of font aliases.


### familyName

```
char* OH_Drawing_FontGenericInfo::familyName
```
**Description**

Pointer to the name of a font family.
