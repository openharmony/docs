# crypto_signature.h


## 概述

定义验签接口。

**库：** libohcrypto.z.so

**系统能力：** SystemCapability.Security.CryptoFramework

**起始版本：** 12

**相关模块：**[CryptoSignatureApi](_crypto_signature_api.md)


## 汇总


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [OH_CryptoVerify](_crypto_signature_api.md#oh_cryptoverify) [OH_CryptoVerify](_crypto_signature_api.md#oh_cryptoverify) | 定义验签结构体。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [CryptoSignature_ParamType](_crypto_signature_api.md#cryptosignature_paramtype) {<br/>CRYPTO_PSS_MD_NAME_STR = 100, CRYPTO_PSS_MGF_NAME_STR = 101,<br/>CRYPTO_PSS_MGF1_NAME_STR = 102, CRYPTO_PSS_SALT_LEN_INT = 103,<br/>CRYPTO_PSS_TRAILER_FIELD_INT = 104, CRYPTO_SM2_USER_ID_DATABLOB = 105<br/>} | 定义签名验签参数类型。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode) [OH_CryptoVerify_Create](_crypto_signature_api.md#oh_cryptoverify_create) (const char \*algoName, [OH_CryptoVerify](_crypto_signature_api.md#oh_cryptoverify) \*\*verify) | 创建验签实例。 | 
| [OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode) [OH_CryptoVerify_Init](_crypto_signature_api.md#oh_cryptoverify_init) ([OH_CryptoVerify](_crypto_signature_api.md#oh_cryptoverify) \*ctx, [OH_CryptoPubKey](_crypto_asym_key_api.md#oh_cryptopubkey) \*pubKey) | 传入公钥初始化验签实例。 | 
| [OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode) [OH_CryptoVerify_Update](_crypto_signature_api.md#oh_cryptoverify_update) ([OH_CryptoVerify](_crypto_signature_api.md#oh_cryptoverify) \*ctx, [Crypto_DataBlob](_crypto___data_blob.md) \*in) | 追加待验签数据。 | 
| bool [OH_CryptoVerify_Final](_crypto_signature_api.md#oh_cryptoverify_final) ([OH_CryptoVerify](_crypto_signature_api.md#oh_cryptoverify) \*ctx, [Crypto_DataBlob](_crypto___data_blob.md) \*in, [Crypto_DataBlob](_crypto___data_blob.md) \*signData) | 对数据进行验签。 | 
| [OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode) [OH_CryptoVerify_Recover](_crypto_signature_api.md#oh_cryptoverify_recover) ([OH_CryptoVerify](_crypto_signature_api.md#oh_cryptoverify) \*ctx, [Crypto_DataBlob](_crypto___data_blob.md) \*signData, [Crypto_DataBlob](_crypto___data_blob.md) \*rawSignData) | 对签名数据进行恢复操作。 | 
| const char \* [OH_CryptoVerify_GetAlgoName](_crypto_signature_api.md#oh_cryptoverify_getalgoname) ([OH_CryptoVerify](_crypto_signature_api.md#oh_cryptoverify) \*ctx) | 获取验签算法名称。 | 
| [OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode) [OH_CryptoVerify_SetParam](_crypto_signature_api.md#oh_cryptoverify_setparam) ([OH_CryptoVerify](_crypto_signature_api.md#oh_cryptoverify) \*ctx, [CryptoSignature_ParamType](_crypto_signature_api.md#cryptosignature_paramtype) type, [Crypto_DataBlob](_crypto___data_blob.md) \*value) | 设置验签参数。 | 
| [OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode) [OH_CryptoVerify_GetParam](_crypto_signature_api.md#oh_cryptoverify_getparam) ([OH_CryptoVerify](_crypto_signature_api.md#oh_cryptoverify) \*ctx, [CryptoSignature_ParamType](_crypto_signature_api.md#cryptosignature_paramtype) type, [Crypto_DataBlob](_crypto___data_blob.md) \*value) | 获取验签参数。 | 
| void [OH_CryptoVerify_Destroy](_crypto_signature_api.md#oh_cryptoverify_destroy) ([OH_CryptoVerify](_crypto_signature_api.md#oh_cryptoverify) \*ctx) | 销毁验签实例。 | 
