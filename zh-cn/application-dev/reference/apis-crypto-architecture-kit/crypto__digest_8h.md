# crypto_digest.h


## 概述

定义摘要算法API。

**库：** libohcrypto.z.so

**系统能力：** SystemCapability.Security.CryptoFramework

**起始版本：** 12

**相关模块：**[CryptoDigestApi](_crypto_digest_api.md)


## 汇总


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [OH_CryptoDigest](_crypto_digest_api.md#oh_cryptodigest) [OH_CryptoDigest](_crypto_digest_api.md#oh_cryptodigest) | 定义摘要结构体。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode) [OH_CryptoDigest_Create](_crypto_digest_api.md#oh_cryptodigest_create) (const char \*algoName, [OH_CryptoDigest](_crypto_digest_api.md#oh_cryptodigest) \*\*ctx) | 根据给定的算法名称创建一个摘要实例。 | 
| [OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode) [OH_CryptoDigest_Update](_crypto_digest_api.md#oh_cryptodigest_update) ([OH_CryptoDigest](_crypto_digest_api.md#oh_cryptodigest) \*ctx, [Crypto_DataBlob](_crypto___data_blob.md) \*in) | 传入消息进行摘要更新计算。 | 
| [OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode) [OH_CryptoDigest_Final](_crypto_digest_api.md#oh_cryptodigest_final) ([OH_CryptoDigest](_crypto_digest_api.md#oh_cryptodigest) \*ctx, [Crypto_DataBlob](_crypto___data_blob.md) \*out) | 计算最终摘要。 | 
| uint32_t [OH_CryptoDigest_GetLength](_crypto_digest_api.md#oh_cryptodigest_getlength) ([OH_CryptoDigest](_crypto_digest_api.md#oh_cryptodigest) \*ctx) | 获取摘要长度。 | 
| const char \* [OH_CryptoDigest_GetAlgoName](_crypto_digest_api.md#oh_cryptodigest_getalgoname) ([OH_CryptoDigest](_crypto_digest_api.md#oh_cryptodigest) \*ctx) | 获取摘要算法。 | 
| void [OH_DigestCrypto_Destroy](_crypto_digest_api.md#oh_digestcrypto_destroy) ([OH_CryptoDigest](_crypto_digest_api.md#oh_cryptodigest) \*ctx) | 销毁摘要实例。 | 
