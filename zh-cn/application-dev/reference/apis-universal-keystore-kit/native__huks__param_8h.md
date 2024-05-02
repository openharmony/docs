# native_huks_param.h


## 概述

提供参数集构造、使用和销毁的API。

**起始版本：** 9

**相关模块：**[HuksParamSetApi](_huks_param_set_api.md)


## 汇总


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| struct [OH_Huks_Result](_o_h___huks___result.md) [OH_Huks_InitParamSet](_huks_param_set_api.md#oh_huks_initparamset) (struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*\*paramSet) | 初始化参数集。  | 
| struct [OH_Huks_Result](_o_h___huks___result.md) [OH_Huks_AddParams](_huks_param_set_api.md#oh_huks_addparams) (struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*paramSet, const struct [OH_Huks_Param](_o_h___huks___param.md) \*params, uint32_t paramCnt) | 添加参数到参数集里面。  | 
| struct [OH_Huks_Result](_o_h___huks___result.md) [OH_Huks_BuildParamSet](_huks_param_set_api.md#oh_huks_buildparamset) (struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*\*paramSet) | 构造正式的参数集。  | 
| void [OH_Huks_FreeParamSet](_huks_param_set_api.md#oh_huks_freeparamset) (struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*\*paramSet) | 销毁参数集。  | 
| struct [OH_Huks_Result](_o_h___huks___result.md) [OH_Huks_CopyParamSet](_huks_param_set_api.md#oh_huks_copyparamset) (const struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*fromParamSet, uint32_t fromParamSetSize, struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*\*paramSet) | 复制参数集（深拷贝）。  | 
| struct [OH_Huks_Result](_o_h___huks___result.md) [OH_Huks_GetParam](_huks_param_set_api.md#oh_huks_getparam) (const struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*paramSet, uint32_t tag, struct [OH_Huks_Param](_o_h___huks___param.md) \*\*param) | 从参数集中获取参数。  | 
| struct [OH_Huks_Result](_o_h___huks___result.md) [OH_Huks_FreshParamSet](_huks_param_set_api.md#oh_huks_freshparamset) (struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*paramSet, bool isCopy) | 刷新参数集内[OH_Huks_Blob](_o_h___huks___blob.md)类型的数据。  | 
| struct [OH_Huks_Result](_o_h___huks___result.md) [OH_Huks_IsParamSetTagValid](_huks_param_set_api.md#oh_huks_isparamsettagvalid) (const struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*paramSet) | 检查参数集中的参数是否有效、是否有重复。  | 
| struct [OH_Huks_Result](_o_h___huks___result.md) [OH_Huks_IsParamSetValid](_huks_param_set_api.md#oh_huks_isparamsetvalid) (const struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*paramSet, uint32_t size) | 检查参数集大小是否有效。  | 
| struct [OH_Huks_Result](_o_h___huks___result.md) [OH_Huks_CheckParamMatch](_huks_param_set_api.md#oh_huks_checkparammatch) (const struct [OH_Huks_Param](_o_h___huks___param.md) \*baseParam, const struct [OH_Huks_Param](_o_h___huks___param.md) \*param) | 比较两个参数是否相同。  | 
| void [OH_Huks_FreeKeyAliasSet](_huks_param_set_api.md#oh_huks_freekeyaliasset) (struct [OH_Huks_KeyAliasSet](_o_h___huks___key_alias_set.md) \*keyAliasSet) | 销毁参数集。  | 
