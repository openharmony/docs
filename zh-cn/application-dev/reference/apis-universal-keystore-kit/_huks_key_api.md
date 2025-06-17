# HuksKeyApi


## 概述

HUKS向应用提供密钥库能力，支持密钥管理和密钥的密码学操作。应用可以导入密钥或者调用HUKS接口生成密钥。

**系统能力：** SystemCapability.Security.Huks

**起始版本：** 9


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [native_huks_api.h](native__huks__api_8h.md) | 声明用于访问HUKS的API。<br>**引用文件**：<huks/native_huks_api.h> <br>**库**：libhuks_ndk.z.so  | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| struct [OH_Huks_Result](_o_h___huks___result.md) [OH_Huks_GetSdkVersion](#oh_huks_getsdkversion) (struct [OH_Huks_Blob](_o_h___huks___blob.md) \*sdkVersion) | 获取当前Huks sdk版本号。  | 
| struct [OH_Huks_Result](_o_h___huks___result.md) [OH_Huks_GenerateKeyItem](#oh_huks_generatekeyitem) (const struct [OH_Huks_Blob](_o_h___huks___blob.md) \*keyAlias, const struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*paramSetIn, struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*paramSetOut) | 生成密钥。  | 
| struct [OH_Huks_Result](_o_h___huks___result.md) [OH_Huks_ImportKeyItem](#oh_huks_importkeyitem) (const struct [OH_Huks_Blob](_o_h___huks___blob.md) \*keyAlias, const struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*paramSet, const struct [OH_Huks_Blob](_o_h___huks___blob.md) \*key) | 导入明文密钥。  | 
| struct [OH_Huks_Result](_o_h___huks___result.md) [OH_Huks_ImportWrappedKeyItem](#oh_huks_importwrappedkeyitem) (const struct [OH_Huks_Blob](_o_h___huks___blob.md) \*keyAlias, const struct [OH_Huks_Blob](_o_h___huks___blob.md) \*wrappingKeyAlias, const struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*paramSet, const struct [OH_Huks_Blob](_o_h___huks___blob.md) \*wrappedKeyData) | 导入密文密钥。  | 
| struct [OH_Huks_Result](_o_h___huks___result.md) [OH_Huks_ExportPublicKeyItem](#oh_huks_exportpublickeyitem) (const struct [OH_Huks_Blob](_o_h___huks___blob.md) \*keyAlias, const struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*paramSet, struct [OH_Huks_Blob](_o_h___huks___blob.md) \*key) | 导出公钥。  | 
| struct [OH_Huks_Result](_o_h___huks___result.md) [OH_Huks_DeleteKeyItem](#oh_huks_deletekeyitem) (const struct [OH_Huks_Blob](_o_h___huks___blob.md) \*keyAlias, const struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*paramSet) | 删除密钥。  | 
| struct [OH_Huks_Result](_o_h___huks___result.md) [OH_Huks_GetKeyItemParamSet](#oh_huks_getkeyitemparamset) (const struct [OH_Huks_Blob](_o_h___huks___blob.md) \*keyAlias, const struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*paramSetIn, struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*paramSetOut) | 获取密钥的属性集。  | 
| struct [OH_Huks_Result](_o_h___huks___result.md) [OH_Huks_IsKeyItemExist](#oh_huks_iskeyitemexist) (const struct [OH_Huks_Blob](_o_h___huks___blob.md) \*keyAlias, const struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*paramSet) | 判断密钥是否存在。  | 
| struct [OH_Huks_Result](_o_h___huks___result.md) [OH_Huks_AttestKeyItem](#oh_huks_attestkeyitem) (const struct [OH_Huks_Blob](_o_h___huks___blob.md) \*keyAlias, const struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*paramSet, struct [OH_Huks_CertChain](_o_h___huks___cert_chain.md) \*certChain) | 获取密钥证书链。  | 
| struct [OH_Huks_Result](_o_h___huks___result.md) [OH_Huks_AnonAttestKeyItem](#oh_huks_anonattestkeyitem) (const struct [OH_Huks_Blob](_o_h___huks___blob.md) \*keyAlias, const struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*paramSet, struct [OH_Huks_CertChain](_o_h___huks___cert_chain.md) \*certChain) | 获取密钥证书链。  | 
| struct [OH_Huks_Result](_o_h___huks___result.md) [OH_Huks_InitSession](#oh_huks_initsession) (const struct [OH_Huks_Blob](_o_h___huks___blob.md) \*keyAlias, const struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*paramSet, struct [OH_Huks_Blob](_o_h___huks___blob.md) \*handle, struct [OH_Huks_Blob](_o_h___huks___blob.md) \*token) | 初始化密钥会话接口，并获取一个句柄（必选）和挑战值（可选）。  | 
| struct [OH_Huks_Result](_o_h___huks___result.md) [OH_Huks_UpdateSession](#oh_huks_updatesession) (const struct [OH_Huks_Blob](_o_h___huks___blob.md) \*handle, const struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*paramSet, const struct [OH_Huks_Blob](_o_h___huks___blob.md) \*inData, struct [OH_Huks_Blob](_o_h___huks___blob.md) \*outData) | 分段添加密钥操作的数据并进行相应的密钥操作，输出处理数据。  | 
| struct [OH_Huks_Result](_o_h___huks___result.md) [OH_Huks_FinishSession](#oh_huks_finishsession) (const struct [OH_Huks_Blob](_o_h___huks___blob.md) \*handle, const struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*paramSet, const struct [OH_Huks_Blob](_o_h___huks___blob.md) \*inData, struct [OH_Huks_Blob](_o_h___huks___blob.md) \*outData) | 结束密钥会话并进行相应的密钥操作，输出处理数据。  | 
| struct [OH_Huks_Result](_o_h___huks___result.md) [OH_Huks_AbortSession](#oh_huks_abortsession) (const struct [OH_Huks_Blob](_o_h___huks___blob.md) \*handle, const struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*paramSet) | 取消密钥会话。  | 
| struct [OH_Huks_Result](_o_h___huks___result.md) [OH_Huks_ListAliases](#oh_huks_listaliases) (const struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*paramSet, struct [OH_Huks_KeyAliasSet](_o_h___huks___key_alias_set.md) \*\*outData) | 批量查询密钥别名集。  | 


## 函数说明


### OH_Huks_AbortSession()

```
struct OH_Huks_Result OH_Huks_AbortSession (const struct OH_Huks_Blob * handle, const struct OH_Huks_ParamSet * paramSet )
```
**描述**
取消密钥会话。

**起始版本：** 9

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| handle | 密钥会话句柄，通过[OH_Huks_InitSession](#oh_huks_initsession)接口生成的。  | 
| paramSet | 取消密钥会话需要的输入参数集（默认传空）。  | 

**返回：**

返回[OH_HUKS_SUCCESS](_huks_type_api.md#oh_huks_errcode)时接口使用成功，其他时为错误。

**参见：**

[OH_Huks_InitSession](#oh_huks_initsession)

[OH_Huks_UpdateSession](#oh_huks_updatesession)

[OH_Huks_FinishSession](#oh_huks_finishsession)


### OH_Huks_AnonAttestKeyItem()

```
struct OH_Huks_Result OH_Huks_AnonAttestKeyItem (const struct OH_Huks_Blob * keyAlias, const struct OH_Huks_ParamSet * paramSet, struct OH_Huks_CertChain * certChain )
```
**描述**
获取密钥证书链。

<!--RP1--><!--RP1End-->

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| keyAlias | 要获取证书的密钥的别名。  | 
| paramSet | 获取密钥证书需要的参数。  | 
| certChain | 存放输出的密钥证书链。  | 

**返回：**

返回[OH_HUKS_SUCCESS](_huks_type_api.md#oh_huks_errcode)时获取成功，其他时为错误。

**注解：**

这是一个涉及网络的耗时接口，调用方可以通过异步线程获取证书链。


### OH_Huks_AttestKeyItem()

```
struct OH_Huks_Result OH_Huks_AttestKeyItem (const struct OH_Huks_Blob * keyAlias, const struct OH_Huks_ParamSet * paramSet, struct OH_Huks_CertChain * certChain )
```

**描述**
获取密钥证书链。

**需要权限：**
ohos.permission.ATTEST_KEY，该权限仅系统应用可申请。

**起始版本：** 9

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| keyAlias | 要获取证书的密钥的别名。  | 
| paramSet | 获取密钥证书需要的参数。  | 
| certChain | 存放输出的密钥证书链。  | 

**返回：**

返回[OH_HUKS_SUCCESS](_huks_type_api.md#oh_huks_errcode)时获取成功，其他时为错误。


### OH_Huks_DeleteKeyItem()

```
struct OH_Huks_Result OH_Huks_DeleteKeyItem (const struct OH_Huks_Blob * keyAlias, const struct OH_Huks_ParamSet * paramSet )
```
**描述**
删除密钥。

**起始版本：** 9

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| keyAlias | 待删除密钥的别名，应与密钥生成时使用的别名相同。  | 
| paramSet | 删除密钥需要属性参数。 若不指定则默认要删除的密钥存储等级为[OH_HUKS_AUTH_STORAGE_LEVEL_CE](_huks_type_api.md#oh_huks_authstoragelevel)。 | 

**返回：**

返回[OH_HUKS_SUCCESS](_huks_type_api.md#oh_huks_errcode)时接口使用成功，其他时为错误。


### OH_Huks_ExportPublicKeyItem()

```
struct OH_Huks_Result OH_Huks_ExportPublicKeyItem (const struct OH_Huks_Blob * keyAlias, const struct OH_Huks_ParamSet * paramSet, struct OH_Huks_Blob * key )
```
**描述**
导出公钥。

**起始版本：** 9

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| keyAlias | 待导出公钥的密钥别名，应与所用密钥生成时使用的别名相同。  | 
| paramSet | 导出公钥需要的属性参数。  | 
| key | 存放导出的公钥。  | 

**返回：**

返回[OH_HUKS_SUCCESS](_huks_type_api.md#oh_huks_errcode)时接口使用成功，其他时为错误。


### OH_Huks_FinishSession()

```
struct OH_Huks_Result OH_Huks_FinishSession (const struct OH_Huks_Blob * handle, const struct OH_Huks_ParamSet * paramSet, const struct OH_Huks_Blob * inData, struct OH_Huks_Blob * outData )
```
**描述**
结束密钥会话并进行相应的密钥操作，输出处理数据。

**起始版本：** 9

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| handle | 密钥会话句柄，通过[OH_Huks_InitSession](#oh_huks_initsession)接口生成的。  | 
| paramSet | 密钥操作对应的输入参数集。  | 
| inData | 要处理的输入数据。  | 
| outData | 经过对应的密钥操作后输出的数据。  | 

**返回：**

返回[OH_HUKS_SUCCESS](_huks_type_api.md#oh_huks_errcode)时接口使用成功，其他时为错误。

**参见：**

[OH_Huks_InitSession](#oh_huks_initsession)

[OH_Huks_UpdateSession](#oh_huks_updatesession)

[OH_Huks_AbortSession](#oh_huks_abortsession)


### OH_Huks_GenerateKeyItem()

```
struct OH_Huks_Result OH_Huks_GenerateKeyItem (const struct OH_Huks_Blob * keyAlias, const struct OH_Huks_ParamSet * paramSetIn, struct OH_Huks_ParamSet * paramSetOut )
```
**描述**
生成密钥。

**起始版本：** 9

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| keyAlias | 给要生成的密钥的别名，需要保证业务所在进程内唯一，否则会发生覆盖。  | 
| paramSetIn | 生成密钥的属性信息的参数集。  | 
| paramSetOut | 生成密钥为临时类型时，存放着密钥数据；非临时类型可为空。  | 

**返回：**

返回[OH_HUKS_SUCCESS](_huks_type_api.md#oh_huks_errcode)时接口使用成功，其他时为错误。


### OH_Huks_GetKeyItemParamSet()

```
struct OH_Huks_Result OH_Huks_GetKeyItemParamSet (const struct OH_Huks_Blob * keyAlias, const struct OH_Huks_ParamSet * paramSetIn, struct OH_Huks_ParamSet * paramSetOut )
```
**描述**
获取密钥的属性集。

**起始版本：** 9

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| keyAlias | 要获取参数集的密钥别名。  | 
| paramSetIn | 要获取参数集需要的属性TAG（默认传空）。  | 
| paramSetOut | 获取到的输出参数集。  | 

**返回：**

返回[OH_HUKS_SUCCESS](_huks_type_api.md#oh_huks_errcode)时获取成功，其他时为失败。


### OH_Huks_GetSdkVersion()

```
struct OH_Huks_Result OH_Huks_GetSdkVersion (struct OH_Huks_Blob * sdkVersion)
```
**描述**
获取当前Huks sdk版本号。

**起始版本：** 9

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| sdkVersion | 用于存放获取到的版本信息（字符串格式）。  | 

**返回：**

返回[OH_HUKS_SUCCESS](_huks_type_api.md#oh_huks_errcode)时接口使用成功，其他时为错误。


### OH_Huks_ImportKeyItem()

```
struct OH_Huks_Result OH_Huks_ImportKeyItem (const struct OH_Huks_Blob * keyAlias, const struct OH_Huks_ParamSet * paramSet, const struct OH_Huks_Blob * key )
```
**描述**
导入明文密钥。

**起始版本：** 9

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| keyAlias | 待导入密钥的别名，需要保证业务所在进程内唯一，否则会发生覆盖。  | 
| paramSet | 待导入密钥的属性参数。  | 
| key | 待导入密钥数据，需符合Huks的格式要求，具体见[HuksTypeApi](_huks_type_api.md)。  | 

**返回：**

返回[OH_HUKS_SUCCESS](_huks_type_api.md#oh_huks_errcode)时接口使用成功，其他时为错误。


### OH_Huks_ImportWrappedKeyItem()

```
struct OH_Huks_Result OH_Huks_ImportWrappedKeyItem (const struct OH_Huks_Blob * keyAlias, const struct OH_Huks_Blob * wrappingKeyAlias, const struct OH_Huks_ParamSet * paramSet, const struct OH_Huks_Blob * wrappedKeyData )
```
**描述**
导入密文密钥。

**起始版本：** 9

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| keyAlias | 待导入密钥的别名，需要保证业务所在进程内唯一，否则会发生覆盖。  | 
| wrappingKeyAlias | 密钥别名，该对应密钥用于密钥协商出密钥解密待导入密钥。  | 
| paramSet | 待导入加密密钥的属性参数。  | 
| wrappedKeyData | 需要导入的加密的密钥数据，需要符合Huks定义的格式，具体见[OH_Huks_AlgSuite](_huks_type_api.md#oh_huks_algsuite)。 | 

**返回：**

返回[OH_HUKS_SUCCESS](_huks_type_api.md#oh_huks_errcode)时接口使用成功，其他时为错误。


### OH_Huks_InitSession()

```
struct OH_Huks_Result OH_Huks_InitSession (const struct OH_Huks_Blob * keyAlias, const struct OH_Huks_ParamSet * paramSet, struct OH_Huks_Blob * handle, struct OH_Huks_Blob * token )
```
**描述**
初始化密钥会话接口，并获取一个句柄（必选）和挑战值（可选）。

**起始版本：** 9

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| keyAlias | 操作的密钥的别名。  | 
| paramSet | 初始化操作的密钥参数集合。  | 
| handle | 密钥会话的句柄，后续其他操作时传入该句柄，包括[OH_Huks_UpdateSession](#oh_huks_updatesession), [OH_Huks_FinishSession](#oh_huks_finishsession), [OH_Huks_AbortSession](#oh_huks_abortsession)。  | 
| token | 存放安全访问控制时传回的token。  | 

**返回：**

返回[OH_HUKS_SUCCESS](_huks_type_api.md#oh_huks_errcode)时接口使用成功，其他时为错误。

**参见：**

[OH_Huks_UpdateSession](#oh_huks_updatesession)

[OH_Huks_FinishSession](#oh_huks_finishsession)

[OH_Huks_AbortSession](#oh_huks_abortsession)


### OH_Huks_IsKeyItemExist()

```
struct OH_Huks_Result OH_Huks_IsKeyItemExist (const struct OH_Huks_Blob * keyAlias, const struct OH_Huks_ParamSet * paramSet )
```
**描述**
判断密钥是否存在。

**起始版本：** 9

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| keyAlias | 要查找的密钥的别名。  | 
| paramSet | 查询密钥需要的属性TAG（默认传空）。  | 

**返回：**

返回[OH_HUKS_SUCCESS](_huks_type_api.md#oh_huks_errcode)时密钥存在，

返回[OH_Huks_ErrCode#OH_HUKS_ERR_CODE_ITEM_NOT_EXIST](_huks_type_api.md#oh_huks_errcode)不存在，返回其他错误在其他情况。


### OH_Huks_ListAliases()

```
struct OH_Huks_Result OH_Huks_ListAliases (const struct OH_Huks_ParamSet * paramSet, struct OH_Huks_KeyAliasSet ** outData )
```
**描述**
批量查询密钥别名集。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| paramSet | 查询密钥别名需要的属性TAG（默认传空）。  | 
| outData | 经过对应的查询操作后输出的密钥别名集数据。  | 

**返回：**

返回[OH_HUKS_SUCCESS](_huks_type_api.md#oh_huks_errcode)时接口使用成功，其他时为错误。


### OH_Huks_UpdateSession()

```
struct OH_Huks_Result OH_Huks_UpdateSession (const struct OH_Huks_Blob * handle, const struct OH_Huks_ParamSet * paramSet, const struct OH_Huks_Blob * inData, struct OH_Huks_Blob * outData )
```
**描述**
分段添加密钥操作的数据并进行相应的密钥操作，输出处理数据。

**起始版本：** 9

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| handle | 密钥会话句柄，通过[OH_Huks_InitSession](#oh_huks_initsession)接口生成的。  | 
| paramSet | 密钥操作对应的输入参数集。  | 
| inData | 要处理的输入数据，如果数据过大，可分片多次调用。  | 
| outData | 经过对应的密钥操作后输出的数据。  | 

**返回：**

返回[OH_HUKS_SUCCESS](_huks_type_api.md#oh_huks_errcode)时接口使用成功，其他时为错误。

**参见：**

[OH_Huks_InitSession](#oh_huks_initsession)

[OH_Huks_FinishSession](#oh_huks_finishsession)

[OH_Huks_AbortSession](#oh_huks_abortsession)
