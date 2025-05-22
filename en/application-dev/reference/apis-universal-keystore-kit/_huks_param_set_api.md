# HuksParamSetApi


## Overview

Defines functions for parameter set lifecycle management, including initializing a parameter set, adding parameters, building a parameter set, and freeing a parameter set, as well as parameter set operations such as obtaining parameters, copying a parameter set, querying a parameter set, and checking the validity of a parameter set.

**System capability**: SystemCapability.Security.Huks

**Since**: 9


## Summary


### File

| Name| Description| 
| -------- | -------- |
| [native_huks_param.h](native__huks__param_8h.md) | Defines the functions for constructing, using, and destroying a parameter set. | 


### Functions

| Name| Description| 
| -------- | -------- |
| struct [OH_Huks_Result](_o_h___huks___result.md) [OH_Huks_InitParamSet](#oh_huks_initparamset) (struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*\*paramSet) | Initializes a parameter set and pre-allocates memory to **paramSet**. | 
| struct [OH_Huks_Result](_o_h___huks___result.md) [OH_Huks_AddParams](#oh_huks_addparams) (struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*paramSet, const struct [OH_Huks_Param](_o_h___huks___param.md) \*params, uint32_t paramCnt) | Adds parameters to a parameter set. Before calling this API, call **OH_Huks_InitParamSet** to initialize **paramSet**. | 
| struct [OH_Huks_Result](_o_h___huks___result.md) [OH_Huks_BuildParamSet](#oh_huks_buildparamset) (struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*\*paramSet) | Builds a parameter set. After adding parameters to **paramSet**, call **OH_Huks_BuildParamSet** to integrate the parameter set. | 
| void [OH_Huks_FreeParamSet](#oh_huks_freeparamset) (struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*\*paramSet) | Frees a parameter set. | 
| struct [OH_Huks_Result](_o_h___huks___result.md) [OH_Huks_CopyParamSet](#oh_huks_copyparamset) (const struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*fromParamSet, uint32_t fromParamSetSize, struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*\*paramSet) | Copies a parameter set (deep copy). | 
| struct [OH_Huks_Result](_o_h___huks___result.md) [OH_Huks_GetParam](#oh_huks_getparam) (const struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*paramSet, uint32_t tag, struct [OH_Huks_Param](_o_h___huks___param.md) \*\*param) | Obtains a parameter from a parameter set. | 
| struct [OH_Huks_Result](_o_h___huks___result.md) [OH_Huks_FreshParamSet](#oh_huks_freshparamset) (struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*paramSet, bool isCopy) | Updates the data of the [OH_Huks_Blob](_o_h___huks___blob.md) type in a parameter set. | 
| struct [OH_Huks_Result](_o_h___huks___result.md) [OH_Huks_IsParamSetTagValid](#oh_huks_isparamsettagvalid) (const struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*paramSet) | Checks whether the parameters in a parameter set are valid. | 
| struct [OH_Huks_Result](_o_h___huks___result.md) [OH_Huks_IsParamSetValid](#oh_huks_isparamsetvalid) (const struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*paramSet, uint32_t size) | Checks whether a parameter set is of the valid size. | 
| struct [OH_Huks_Result](_o_h___huks___result.md) [OH_Huks_CheckParamMatch](#oh_huks_checkparammatch) (const struct [OH_Huks_Param](_o_h___huks___param.md) \*baseParam, const struct [OH_Huks_Param](_o_h___huks___param.md) \*param) | Checks whether two parameters are the same.| 
| void [OH_Huks_FreeKeyAliasSet](#oh_huks_freekeyaliasset) (struct [OH_Huks_KeyAliasSet](_o_h___huks___key_alias_set.md) \*keyAliasSet) | Frees a key alias set. | 


## Function Description


### OH_Huks_AddParams()

```
struct OH_Huks_Result OH_Huks_AddParams (struct OH_Huks_ParamSet * paramSet, const struct OH_Huks_Param * params, uint32_t paramCnt )
```
**Description**
Adds parameters to a parameter set.

**Since**: 9

**Parameters**

| Name| Description| 
| -------- | -------- |
| paramSet | Pointer to the parameter set to which parameters are to be added. | 
| params | Pointer to an array of parameters to add. | 
| paramCnt | Number of parameters to add. | 

**Returns**

Returns [OH_HUKS_SUCCESS](_huks_type_api.md#oh_huks_errcode) if the operation is successful; returns an error code otherwise.


### OH_Huks_BuildParamSet()

```
struct OH_Huks_Result OH_Huks_BuildParamSet (struct OH_Huks_ParamSet ** paramSet)
```
**Description**
Builds a parameter set.

**Since**: 9

**Parameters**

| Name| Description| 
| -------- | -------- |
| paramSet | Double pointer to the parameter set to build. | 

**Returns**

Returns [OH_HUKS_SUCCESS](_huks_type_api.md#oh_huks_errcode) if the operation is successful; returns an error code otherwise.


### OH_Huks_CheckParamMatch()

```
struct OH_Huks_Result OH_Huks_CheckParamMatch (const struct OH_Huks_Param * baseParam, const struct OH_Huks_Param * param )
```
**Description**
Checks whether two parameters are the same.

**Since**: 9

**Parameters**

| Name| Description| 
| -------- | -------- |
| baseParam | Pointer to the first parameter to compare. | 
| param | Pointer to the second parameter to compare. | 

**Returns**

Returns [OH_HUKS_SUCCESS](_huks_type_api.md#oh_huks_errcode) if the two parameters are the same; returns an error code otherwise.


### OH_Huks_CopyParamSet()

```
struct OH_Huks_Result OH_Huks_CopyParamSet (const struct OH_Huks_ParamSet * fromParamSet, uint32_t fromParamSetSize, struct OH_Huks_ParamSet ** paramSet )
```
**Description**
Copies a parameter set (deep copy).

**Since**: 9

**Parameters**

| Name| Description| 
| -------- | -------- |
| fromParamSet | Pointer to the parameter set to copy. | 
| fromParamSetSize | Size of the memory occupied by the copied parameter set. | 
| paramSet | Double pointer to the new parameter set generated. | 

**Returns**

Returns [OH_HUKS_SUCCESS](_huks_type_api.md#oh_huks_errcode) if the operation is successful; returns an error code otherwise.


### OH_Huks_FreeKeyAliasSet()

```
void OH_Huks_FreeKeyAliasSet (struct OH_Huks_KeyAliasSet * keyAliasSet)
```
**Description**
Frees a key alias set.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| keyAliasSet | Pointer to the key alias set to free. | 


### OH_Huks_FreeParamSet()

```
void OH_Huks_FreeParamSet (struct OH_Huks_ParamSet ** paramSet)
```
**Description**
Frees a parameter set.

**Since**: 9

**Parameters**

| Name| Description| 
| -------- | -------- |
| paramSet | Pointer to the parameter set to free. | 


### OH_Huks_FreshParamSet()

```
struct OH_Huks_Result OH_Huks_FreshParamSet (struct OH_Huks_ParamSet * paramSet, bool isCopy )
```
**Description**
Updates the data of the [OH_Huks_Blob](_o_h___huks___blob.md) type in a parameter set.

**Since**: 9

**Parameters**

| Name| Description| 
| -------- | -------- |
| paramSet | Pointer to the parameter set to check. | 
| isCopy | Whether to copy the data. The value **true** means to update the address of the data of the [OH_Huks_Blob](_o_h___huks___blob.md) type and copy the data to the parameter set. The value **false** means only update the address of the data of the [OH_Huks_Blob](_o_h___huks___blob.md) type. | 

**Returns**

Returns [OH_HUKS_SUCCESS](_huks_type_api.md#oh_huks_errcode) if the operation is successful; returns an error code otherwise.


### OH_Huks_GetParam()

```
struct OH_Huks_Result OH_Huks_GetParam (const struct OH_Huks_ParamSet * paramSet, uint32_t tag, struct OH_Huks_Param ** param )
```
**Description**
Obtains a parameter from a parameter set.

**Since**: 9

**Parameters**

| Name| Description| 
| -------- | -------- |
| paramSet | Pointer to the parameter set to check. | 
| tag | Name of the parameter to obtain. | 
| param | Double pointer to the obtained parameter. | 

**Returns**

Returns [OH_HUKS_SUCCESS](_huks_type_api.md#oh_huks_errcode) if the operation is successful; returns an error code otherwise.


### OH_Huks_InitParamSet()

```
struct OH_Huks_Result OH_Huks_InitParamSet (struct OH_Huks_ParamSet ** paramSet)
```
**Description**
Initializes a parameter set.

**Since**: 9

**Parameters**

| Name| Description| 
| -------- | -------- |
| paramSet | Pointer to the parameter set to initialize. | 

**Returns**

Returns [OH_HUKS_SUCCESS](_huks_type_api.md#oh_huks_errcode) if the operation is successful; returns an error code otherwise.


### OH_Huks_IsParamSetTagValid()

```
struct OH_Huks_Result OH_Huks_IsParamSetTagValid (const struct OH_Huks_ParamSet * paramSet)
```
**Description**
Checks whether the parameters in a parameter set are valid.

**Since**: 9

**Parameters**

| Name| Description| 
| -------- | -------- |
| paramSet | Pointer to the parameter set to check. | 

**Returns**

Returns [OH_HUKS_SUCCESS](_huks_type_api.md#oh_huks_errcode) if the parameters are valid. Otherwise, invalid or duplicate parameters are found.


### OH_Huks_IsParamSetValid()

```
struct OH_Huks_Result OH_Huks_IsParamSetValid (const struct OH_Huks_ParamSet * paramSet, uint32_t size )
```
**Description**
Checks whether a parameter set is of the valid size.

**Since**: 9

**Parameters**

| Name| Description| 
| -------- | -------- |
| paramSet | Pointer to the parameter set to check. | 
| size | Memory size occupied by the parameter set. | 

**Returns**

Returns [OH_HUKS_SUCCESS](_huks_type_api.md#oh_huks_errcode) if the size of the parameter set is valid; returns an error code otherwise.
