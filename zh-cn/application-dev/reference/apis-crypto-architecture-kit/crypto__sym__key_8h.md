# crypto_sym_key.h


## 概述

定义对称密钥接口。

**库：** libohcrypto.so

**系统能力：** SystemCapability.Security.CryptoFramework

**起始版本：** 12

**相关模块：**[CryptoSymKeyApi](_crypto_sym_key_api.md)


## 汇总


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [OH_CryptoSymKey](_crypto_sym_key_api.md#oh_cryptosymkey) [OH_CryptoSymKey](_crypto_sym_key_api.md#oh_cryptosymkey) | 定义对称密钥结构体。 | 
| typedef struct [OH_CryptoSymKeyGenerator](_crypto_sym_key_api.md#oh_cryptosymkeygenerator) [OH_CryptoSymKeyGenerator](_crypto_sym_key_api.md#oh_cryptosymkeygenerator) | 定义对称密钥生成器结构体。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode) [OH_CryptoSymKeyGenerator_Create](_crypto_sym_key_api.md#oh_cryptosymkeygenerator_create) (const char \*algoName, [OH_CryptoSymKeyGenerator](_crypto_sym_key_api.md#oh_cryptosymkeygenerator) \*\*ctx) | 根据给定的算法名称创建对称密钥生成器。 | 
| [OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode) [OH_CryptoSymKeyGenerator_Generate](_crypto_sym_key_api.md#oh_cryptosymkeygenerator_generate) ([OH_CryptoSymKeyGenerator](_crypto_sym_key_api.md#oh_cryptosymkeygenerator) \*ctx, [OH_CryptoSymKey](_crypto_sym_key_api.md#oh_cryptosymkey) \*\*keyCtx) | 随机生成对称密钥。 | 
| [OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode) [OH_CryptoSymKeyGenerator_Convert](_crypto_sym_key_api.md#oh_cryptosymkeygenerator_convert) ([OH_CryptoSymKeyGenerator](_crypto_sym_key_api.md#oh_cryptosymkeygenerator) \*ctx, const [Crypto_DataBlob](_crypto___data_blob.md) \*keyData, [OH_CryptoSymKey](_crypto_sym_key_api.md#oh_cryptosymkey) \*\*keyCtx) | 将对称密钥数据转换为对称密钥。 | 
| const char \* [OH_CryptoSymKeyGenerator_GetAlgoName](_crypto_sym_key_api.md#oh_cryptosymkeygenerator_getalgoname) ([OH_CryptoSymKeyGenerator](_crypto_sym_key_api.md#oh_cryptosymkeygenerator) \*ctx) | 获取对称密钥生成器的算法名称。 | 
| void [OH_CryptoSymKeyGenerator_Destroy](_crypto_sym_key_api.md#oh_cryptosymkeygenerator_destroy) ([OH_CryptoSymKeyGenerator](_crypto_sym_key_api.md#oh_cryptosymkeygenerator) \*ctx) | 销毁对称密钥生成器。 | 
| const char \* [OH_CryptoSymKey_GetAlgoName](_crypto_sym_key_api.md#oh_cryptosymkey_getalgoname) ([OH_CryptoSymKey](_crypto_sym_key_api.md#oh_cryptosymkey) \*keyCtx) | 从对称密钥获取对称密钥算法名称。 | 
| [OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode) [OH_CryptoSymKey_GetKeyData](_crypto_sym_key_api.md#oh_cryptosymkey_getkeydata) ([OH_CryptoSymKey](_crypto_sym_key_api.md#oh_cryptosymkey) \*keyCtx, [Crypto_DataBlob](_crypto___data_blob.md) \*out) | 从密钥实例获取对称密钥数据。 | 
| void [OH_CryptoSymKey_Destroy](_crypto_sym_key_api.md#oh_cryptosymkey_destroy) ([OH_CryptoSymKey](_crypto_sym_key_api.md#oh_cryptosymkey) \*keyCtx) | 销毁对称密钥实例。 | 
