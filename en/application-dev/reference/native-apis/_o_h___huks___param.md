# OH_Huks_Param


## Overview

Defines the parameter structure in a parameter set.

**Since:**
9

**Related Modules:**

[HuksTypeApi](_huks_type_api.md)


## Summary


### Member Variables

| Name | Description | 
| -------- | -------- |
| [tag](#tag) | Tag value.  | 
|  union { <br>  bool   [boolParam](#boolparam) <br> int32_t   [int32Param](#int32param) <br> uint32_t   [uint32Param](#uint32param) <br> uint64_t   [uint64Param](#uint64param) <br>  struct [OH_Huks_Blob](_o_h___huks___blob.md)[blob](#blob) <br> }; |  boolParam：Parameter of the Boolean type.<br>int32Param：Parameter of the int32_t type.<br>uint32Param：Parameter of the uint32_t type.<br>Parameter of the uint64_t type.<br>blob：Parameter of the struct [OH_Huks_Blob](_o_h___huks___blob.md) type.|


## Member Variable Description 


### blob

  
```
struct OH_Huks_Blob OH_Huks_Param::blob
```
**Description**<br>
Parameter of the struct [OH_Huks_Blob](_o_h___huks___blob.md) type.


### boolParam

  
```
bool OH_Huks_Param::boolParam
```
**Description**<br>
Parameter of the Boolean type.


### int32Param

  
```
int32_t OH_Huks_Param::int32Param
```
**Description**<br>
Parameter of the int32_t type.


### tag

  
```
uint32_t OH_Huks_Param::tag
```
**Description**<br>
Tag value.


### uint32Param

  
```
uint32_t OH_Huks_Param::uint32Param
```
**Description**<br>
Parameter of the uint32_t type.


### uint64Param

  
```
uint64_t OH_Huks_Param::uint64Param
```
**Description**<br>
Parameter of the uint64_t type.
