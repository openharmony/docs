# native_huks_param.h


## Overview

Provides APIs for constructing, using, and destroying parameter sets.

**Since:**
9

**Related Modules:**

[HuksParamSetApi](_huks_param_set_api.md)


## Summary


### Functions

| Name | Description | 
| -------- | -------- |
| [OH_Huks_InitParamSet](_huks_param_set_api.md#oh_huks_initparamset) (struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*\*paramSet) | Initializes a parameter set.  | 
| [OH_Huks_AddParams](_huks_param_set_api.md#oh_huks_addparams) (struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*paramSet, const struct [OH_Huks_Param](_o_h___huks___param.md) \*params, uint32_t paramCnt) | Adds parameters to a parameter set.  | 
| [OH_Huks_BuildParamSet](_huks_param_set_api.md#oh_huks_buildparamset) (struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*\*paramSet) | Constructs a parameter set.  | 
| [OH_Huks_FreeParamSet](_huks_param_set_api.md#oh_huks_freeparamset) (struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*\*paramSet) | Destroys a parameter set.  | 
| [OH_Huks_CopyParamSet](_huks_param_set_api.md#oh_huks_copyparamset) (const struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*fromParamSet, uint32_t fromParamSetSize, struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*\*paramSet) | Copies a parameter set (deep copy).  | 
| [OH_Huks_GetParam](_huks_param_set_api.md#oh_huks_getparam) (const struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*paramSet, uint32_t tag, struct [OH_Huks_Param](_o_h___huks___param.md) \*\*param) | Obtains parameters from a parameter set.  | 
| [OH_Huks_FreshParamSet](_huks_param_set_api.md#oh_huks_freshparamset) (struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*paramSet, bool isCopy) | Refreshes data of the **Blob** type in a parameter set.  | 
| [OH_Huks_isParamSetTagValid](_huks_param_set_api.md#oh_huks_isparamsettagvalid) (const struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*paramSet) | Checks whether the parameters in a parameter set are valid.  | 
| [OH_Huks_isParamSetValid](_huks_param_set_api.md#oh_huks_isparamsetvalid) (const struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*paramSet, uint32_t size) | Checks whether a parameter set is of the valid size.  | 
| [OH_Huks_CheckParamMatch](_huks_param_set_api.md#oh_huks_checkparammatch) (const struct [OH_Huks_Param](_o_h___huks___param.md) \*baseParam, const struct [OH_Huks_Param](_o_h___huks___param.md) \*param) | Checks whether two parameters are the same.  | 
