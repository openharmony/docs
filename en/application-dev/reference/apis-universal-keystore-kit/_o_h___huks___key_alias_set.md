# OH_Huks_KeyAliasSet


## Overview

Defines a key alias set.

**Since**: 12

**Related module**: [HuksTypeApi](_huks_type_api.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| uint32_t [aliasesCnt](#aliasescnt) | Number of key aliases. | 
| struct [OH_Huks_Blob](_o_h___huks___blob.md) \* [aliases](#aliases) | Pointer to the key alias set. | 


## Member Variable Description


### aliases

```
struct OH_Huks_Blob* OH_Huks_KeyAliasSet::aliases
```
**Description**
Pointer to the key alias set.


### aliasesCnt

```
uint32_t OH_Huks_KeyAliasSet::aliasesCnt
```
**Description**
Number of key aliases.
