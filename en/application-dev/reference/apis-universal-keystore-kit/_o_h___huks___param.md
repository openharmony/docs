# OH_Huks_Param


## Overview

Defines the types of the parameters in a parameter set.

**Since**: 9

**Related module**: [HuksTypeApi](_huks_type_api.md)


## Summary


### Member Variables

| Name| Description|
| -------- | -------- |
| [tag](#tag) | Tag value. |
| union { <br>bool   [boolParam](#boolparam); <br>int32_t   [int32Param](#int32param); <br>uint32_t   [uint32Param](#uint32param); <br>uint64_t   [uint64Param](#uint64param); <br>struct [OH_Huks_Blob](_o_h___huks___blob.md) [blob](#blob);} | **boolParam**: The parameter is a Boolean value.<br>**int32Param**: The parameter is of the int32_t type.<br>**uint32Param**: The parameter is of the uint32_t type.<br>**uint64Param**: The parameter is of the uint64_t type.<br>**blob**: The parameter is of the OH_Huks_Blob type.|


## Member Variable Description


### blob

```
struct OH_Huks_Blob OH_Huks_Param::blob
```
**Description**

Parameter of the OH_Huks_Blob type.


### boolParam

```
bool OH_Huks_Param::boolParam
```
**Description**

Parameter of the Boolean type.


### int32Param

```
int32_t OH_Huks_Param::int32Param
```
**Description**

Parameter of the int32_t type.


### tag

```
uint32_t OH_Huks_Param::tag
```
**Description**

Tag value.


### uint32Param

```
uint32_t OH_Huks_Param::uint32Param
```
**Description**

Parameter of the uint32_t type.


### uint64Param

```
uint64_t OH_Huks_Param::uint64Param
```
**Description**

Parameter of the uint64_t type.