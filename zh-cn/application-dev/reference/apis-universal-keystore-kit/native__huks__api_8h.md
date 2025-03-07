# native_huks_api.h


## 概述

声明用于访问HUKS的API。

**起始版本：** 9

**相关模块：**[HuksKeyApi](_huks_key_api.md)


## 汇总


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| struct [OH_Huks_Result](_o_h___huks___result.md)  [OH_Huks_GetSdkVersion](_huks_key_api.md#oh_huks_getsdkversion) (struct [OH_Huks_Blob](_o_h___huks___blob.md) \*sdkVersion) | 获取当前Huks sdk版本号。  | 
| struct [OH_Huks_Result](_o_h___huks___result.md) [OH_Huks_GenerateKeyItem](_huks_key_api.md#oh_huks_generatekeyitem) (const struct [OH_Huks_Blob](_o_h___huks___blob.md) \*keyAlias, const struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*paramSetIn, struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*paramSetOut) | 生成密钥。  | 
| struct [OH_Huks_Result](_o_h___huks___result.md) [OH_Huks_ImportKeyItem](_huks_key_api.md#oh_huks_importkeyitem) (const struct [OH_Huks_Blob](_o_h___huks___blob.md) \*keyAlias, const struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*paramSet, const struct [OH_Huks_Blob](_o_h___huks___blob.md) \*key) | 导入明文密钥。  | 
| struct [OH_Huks_Result](_o_h___huks___result.md) [OH_Huks_ImportWrappedKeyItem](_huks_key_api.md#oh_huks_importwrappedkeyitem) (const struct [OH_Huks_Blob](_o_h___huks___blob.md) \*keyAlias, const struct [OH_Huks_Blob](_o_h___huks___blob.md) \*wrappingKeyAlias, const struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*paramSet, const struct [OH_Huks_Blob](_o_h___huks___blob.md) \*wrappedKeyData) | 导入密文密钥。  | 
| struct [OH_Huks_Result](_o_h___huks___result.md) [OH_Huks_ExportPublicKeyItem](_huks_key_api.md#oh_huks_exportpublickeyitem) (const struct [OH_Huks_Blob](_o_h___huks___blob.md) \*keyAlias, const struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*paramSet, struct [OH_Huks_Blob](_o_h___huks___blob.md) \*key) | 导出公钥。  | 
| struct [OH_Huks_Result](_o_h___huks___result.md) [OH_Huks_DeleteKeyItem](_huks_key_api.md#oh_huks_deletekeyitem) (const struct [OH_Huks_Blob](_o_h___huks___blob.md) \*keyAlias, const struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*paramSet) | 删除密钥。  | 
| struct [OH_Huks_Result](_o_h___huks___result.md) [OH_Huks_GetKeyItemParamSet](_huks_key_api.md#oh_huks_getkeyitemparamset) (const struct [OH_Huks_Blob](_o_h___huks___blob.md) \*keyAlias, const struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*paramSetIn, struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*paramSetOut) | 获取密钥的属性集。  | 
| struct [OH_Huks_Result](_o_h___huks___result.md) [OH_Huks_IsKeyItemExist](_huks_key_api.md#oh_huks_iskeyitemexist) (const struct [OH_Huks_Blob](_o_h___huks___blob.md) \*keyAlias, const struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*paramSet) | 判断密钥是否存在。  | 
| struct [OH_Huks_Result](_o_h___huks___result.md) [OH_Huks_AttestKeyItem](_huks_key_api.md#oh_huks_attestkeyitem) (const struct [OH_Huks_Blob](_o_h___huks___blob.md) \*keyAlias, const struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*paramSet, struct [OH_Huks_CertChain](_o_h___huks___cert_chain.md) \*certChain) | 获取密钥证书链。  | 
| struct [OH_Huks_Result](_o_h___huks___result.md) [OH_Huks_AnonAttestKeyItem](_huks_key_api.md#oh_huks_anonattestkeyitem) (const struct [OH_Huks_Blob](_o_h___huks___blob.md) \*keyAlias, const struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*paramSet, struct [OH_Huks_CertChain](_o_h___huks___cert_chain.md) \*certChain) | 获取密钥证书链。  | 
| struct [OH_Huks_Result](_o_h___huks___result.md) [OH_Huks_InitSession](_huks_key_api.md#oh_huks_initsession) (const struct [OH_Huks_Blob](_o_h___huks___blob.md) \*keyAlias, const struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*paramSet, struct [OH_Huks_Blob](_o_h___huks___blob.md) \*handle, struct [OH_Huks_Blob](_o_h___huks___blob.md) \*token) | 初始化密钥会话接口，并获取一个句柄（必选）和挑战值（可选）。  | 
| struct [OH_Huks_Result](_o_h___huks___result.md) [OH_Huks_UpdateSession](_huks_key_api.md#oh_huks_updatesession) (const struct [OH_Huks_Blob](_o_h___huks___blob.md) \*handle, const struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*paramSet, const struct [OH_Huks_Blob](_o_h___huks___blob.md) \*inData, struct [OH_Huks_Blob](_o_h___huks___blob.md) \*outData) | 分段添加密钥操作的数据并进行相应的密钥操作，输出处理数据。  | 
| struct [OH_Huks_Result](_o_h___huks___result.md) [OH_Huks_FinishSession](_huks_key_api.md#oh_huks_finishsession) (const struct [OH_Huks_Blob](_o_h___huks___blob.md) \*handle, const struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*paramSet, const struct [OH_Huks_Blob](_o_h___huks___blob.md) \*inData, struct [OH_Huks_Blob](_o_h___huks___blob.md) \*outData) | 结束密钥会话并进行相应的密钥操作，输出处理数据。  | 
| struct [OH_Huks_Result](_o_h___huks___result.md) [OH_Huks_AbortSession](_huks_key_api.md#oh_huks_abortsession) (const struct [OH_Huks_Blob](_o_h___huks___blob.md) \*handle, const struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*paramSet) | 取消密钥会话。  | 
| struct [OH_Huks_Result](_o_h___huks___result.md) [OH_Huks_ListAliases](_huks_key_api.md#oh_huks_listaliases) (const struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*paramSet, struct [OH_Huks_KeyAliasSet](_o_h___huks___key_alias_set.md) \*\*outData) | 批量查询密钥别名集。  | 
