# HuksParamSetApi


## Overview

Defines the capabilities of OpenHarmony Universal KeyStore (HUKS) parameter sets. The HUKS APIs can be used to perform parameter set lifecycle management, including initializing a parameter set, adding parameters to a parameter set, constructing a parameter set, and destroying a parameter set. They can also be used to obtain parameters, copy parameter sets, and check parameter validity.

\@syscap SystemCapability.Security.Huks

**Since:**
9


## Summary


### Files

| Name | Description | 
| -------- | -------- |
| [native_huks_param.h](native__huks__param_8h.md) | Provides APIs for constructing, using, and destroying parameter sets. <br>File to Include: <huks/native_huks/native_huks_param.h> | 


### Functions

| Name | Description | 
| -------- | -------- |
| [OH_Huks_InitParamSet](#oh_huks_initparamset) (struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*\*paramSet) | Initializes a parameter set.  | 
| [OH_Huks_AddParams](#oh_huks_addparams) (struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*paramSet, const struct [OH_Huks_Param](_o_h___huks___param.md) \*params, uint32_t paramCnt) | Adds parameters to a parameter set.  | 
| [OH_Huks_BuildParamSet](#oh_huks_buildparamset) (struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*\*paramSet) | Constructs a parameter set.  | 
| [OH_Huks_FreeParamSet](#oh_huks_freeparamset) (struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*\*paramSet) | Destroys a parameter set.  | 
| [OH_Huks_CopyParamSet](#oh_huks_copyparamset) (const struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*fromParamSet, uint32_t fromParamSetSize, struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*\*paramSet) | Copies a parameter set (deep copy).  | 
| [OH_Huks_GetParam](#oh_huks_getparam) (const struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*paramSet, uint32_t tag, struct [OH_Huks_Param](_o_h___huks___param.md) \*\*param) | Obtains parameters from a parameter set.  | 
| [OH_Huks_FreshParamSet](#oh_huks_freshparamset) (struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*paramSet, bool isCopy) | Refreshes data of the **Blob** type in a parameter set.  | 
| [OH_Huks_isParamSetTagValid](#oh_huks_isparamsettagvalid) (const struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*paramSet) | Checks whether the parameters in a parameter set are valid.  | 
| [OH_Huks_isParamSetValid](#oh_huks_isparamsetvalid) (const struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*paramSet, uint32_t size) | Checks whether a parameter set is of the valid size.  | 
| [OH_Huks_CheckParamMatch](#oh_huks_checkparammatch) (const struct [OH_Huks_Param](_o_h___huks___param.md) \*baseParam, const struct [OH_Huks_Param](_o_h___huks___param.md) \*param) | Checks whether two parameters are the same.  | 


## Function Description


### OH_Huks_AddParams()

  
```
int32_t OH_Huks_AddParams (struct OH_Huks_ParamSet * paramSet, const struct OH_Huks_Param * params, uint32_t paramCnt )
```
**Description**<br>
Adds parameters to a parameter set.

 **Parameters**

| Name | Description | 
| -------- | -------- |
| paramSet | Indicates the pointer to the parameter set to which parameters are to be added.  | 
| params | Indicates the pointer to the array of parameters to add.  | 
| paramCnt | Indicates the number of parameters to add.  | 

**Returns**

Returns [OH_Huks_ErrCode#OH_HUKS_SUCCESS](_huks_type_api.md) if the operation is successful; returns an error code otherwise.


### OH_Huks_BuildParamSet()

  
```
int32_t OH_Huks_BuildParamSet (struct OH_Huks_ParamSet ** paramSet)
```
**Description**<br>
Constructs a parameter set.

 **Parameters**

| Name | Description | 
| -------- | -------- |
| paramSet | Indicates the double pointer to the parameter set to construct.  | 

**Returns**

Returns [OH_Huks_ErrCode#OH_HUKS_SUCCESS](_huks_type_api.md) if the operation is successful; returns an error code otherwise.


### OH_Huks_CheckParamMatch()

  
```
int32_t OH_Huks_CheckParamMatch (const struct OH_Huks_Param * baseParam, const struct OH_Huks_Param * param )
```
**Description**<br>
Checks whether two parameters are the same.

 **Parameters**

| Name | Description | 
| -------- | -------- |
| baseParam | Indicates the pointer to the first parameter.  | 
| param | Indicates the pointer to the second parameter.  | 

**Returns**

Returns [OH_Huks_ErrCode#OH_HUKS_SUCCESS](_huks_type_api.md) if the two parameters are the same; returns an error code otherwise.


### OH_Huks_CopyParamSet()

  
```
int32_t OH_Huks_CopyParamSet (const struct OH_Huks_ParamSet * fromParamSet, uint32_t fromParamSetSize, struct OH_Huks_ParamSet ** paramSet )
```
**Description**<br>
Copies a parameter set (deep copy).

 **Parameters**

| Name | Description | 
| -------- | -------- |
| fromParamSet | Indicates the pointer to the parameter set to copy.  | 
| fromParamSetSize | Indicates the memory size occupied by the source parameter set.  | 
| paramSet | Indicates the double pointer to the new parameter set generated.  | 

**Returns**

Returns [OH_Huks_ErrCode#OH_HUKS_SUCCESS](_huks_type_api.md) if the operation is successful; returns an error code otherwise.


### OH_Huks_FreeParamSet()

  
```
void OH_Huks_FreeParamSet (struct OH_Huks_ParamSet ** paramSet)
```
**Description**<br>
Destroys a parameter set.

 **Parameters**

| Name | Description | 
| -------- | -------- |
| paramSet | Indicates the double pointer to the parameter set to destroy.  | 


### OH_Huks_FreshParamSet()

  
```
int32_t OH_Huks_FreshParamSet (struct OH_Huks_ParamSet * paramSet, bool isCopy )
```
**Description**<br>
Refreshes data of the **Blob** type in a parameter set.

 **Parameters**

| Name | Description | 
| -------- | -------- |
| paramSet | Indicates the pointer to the target parameter set.  | 
| isCopy | Specifies whether to copy the data of the **Blob** type to the parameter set. If yes, the data of the **Blob** type will be copied to the parameter set. Otherwise, only the address of the **Blob** data will be refreshed.  | 

**Returns**

Returns [OH_Huks_ErrCode#OH_HUKS_SUCCESS](_huks_type_api.md) if operation is successful; returns an error code otherwise.


### OH_Huks_GetParam()

  
```
int32_t OH_Huks_GetParam (const struct OH_Huks_ParamSet * paramSet, uint32_t tag, struct OH_Huks_Param ** param )
```
**Description**<br>
Obtains parameters from a parameter set.

 **Parameters**

| Name | Description | 
| -------- | -------- |
| paramSet | Indicates the pointer to the target parameter set.  | 
| tag | Indicates the value of the parameter to be obtained.  | 
| param | Indicates the double pointer to the parameter obtained.  | 

**Returns**

Returns [OH_Huks_ErrCode#OH_HUKS_SUCCESS](_huks_type_api.md) if the operation is successful, returns an error code otherwise.


### OH_Huks_InitParamSet()

  
```
int32_t OH_Huks_InitParamSet (struct OH_Huks_ParamSet ** paramSet)
```
**Description**<br>
Initializes a parameter set.

 **Parameters**

| Name | Description | 
| -------- | -------- |
| paramSet | Indicates the double pointer to the parameter set to initialize.  | 

**Returns**

Returns [OH_Huks_ErrCode#OH_HUKS_SUCCESS](_huks_type_api.md) if the initialization is successful; returns an error code otherwise.


### OH_Huks_isParamSetTagValid()

  
```
int32_t OH_Huks_isParamSetTagValid (const struct OH_Huks_ParamSet * paramSet)
```
**Description**<br>
Checks whether the parameters in a parameter set are valid.

 **Parameters**

| Name | Description | 
| -------- | -------- |
| paramSet | Indicates the pointer to the parameter set to check.  | 

**Returns**

Returns [OH_Huks_ErrCode#OH_HUKS_SUCCESS](_huks_type_api.md) if the parameters in the parameter set are valid; returns other values if the parameter set has invalid, duplicate, or incorrect parameters.


### OH_Huks_isParamSetValid()

  
```
int32_t OH_Huks_isParamSetValid (const struct OH_Huks_ParamSet * paramSet, uint32_t size )
```
**Description**<br>
Checks whether a parameter set is of the valid size.

 **Parameters**

| Name | Description | 
| -------- | -------- |
| paramSet | Indicates the pointer to the parameter set to check.  | 
| size | Indicates the memory size occupied by the parameter set.  | 

**Returns**

Returns [OH_Huks_ErrCode#OH_HUKS_SUCCESS](_huks_type_api.md) if the parameter set is of the valid size; returns an error code otherwise.
