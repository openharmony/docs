# crypto_sym_cipher.h


## 概述

定义对称密钥加解密接口。

**库：** libohcrypto.so

**系统能力：** SystemCapability.Security.CryptoFramework

**起始版本：** 12

**相关模块：**[CryptoSymCipherApi](_crypto_sym_cipher_api.md)


## 汇总


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [OH_CryptoSymCipher](_crypto_sym_cipher_api.md#oh_cryptosymcipher) [OH_CryptoSymCipher](_crypto_sym_cipher_api.md#oh_cryptosymcipher) | 定义对称加解密结构体。 | 
| typedef struct [OH_CryptoSymCipherParams](_crypto_sym_cipher_api.md#oh_cryptosymcipherparams) [OH_CryptoSymCipherParams](_crypto_sym_cipher_api.md#oh_cryptosymcipherparams) | 定义对称加解密参数结构体。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [CryptoSymCipher_ParamsType](_crypto_sym_cipher_api.md#cryptosymcipher_paramstype) {<br/>CRYPTO_IV_DATABLOB = 100,<br/>CRYPTO_AAD_DATABLOB = 101,<br/>CRYPTO_TAG_DATABLOB = 102<br/>} | 定义对称加解密参数类型。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode) [OH_CryptoSymCipherParams_Create](_crypto_sym_cipher_api.md#oh_cryptosymcipherparams_create) ([OH_CryptoSymCipherParams](_crypto_sym_cipher_api.md#oh_cryptosymcipherparams) \*\*params) | 创建对称密钥加解密参数实例。 | 
| [OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode) [OH_CryptoSymCipherParams_SetParam](_crypto_sym_cipher_api.md#oh_cryptosymcipherparams_setparam) ([OH_CryptoSymCipherParams](_crypto_sym_cipher_api.md#oh_cryptosymcipherparams) \*params, [CryptoSymCipher_ParamsType](_crypto_sym_cipher_api.md#cryptosymcipher_paramstype) paramsType, [Crypto_DataBlob](_crypto___data_blob.md) \*value) | 设置对称密钥加解密参数。 | 
| void [OH_CryptoSymCipherParams_Destroy](_crypto_sym_cipher_api.md#oh_cryptosymcipherparams_destroy) ([OH_CryptoSymCipherParams](_crypto_sym_cipher_api.md#oh_cryptosymcipherparams) \*params) | 销毁对称密钥加解密参数实例。 | 
| [OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode) [OH_CryptoSymCipher_Create](_crypto_sym_cipher_api.md#oh_cryptosymcipher_create) (const char \*algoName, [OH_CryptoSymCipher](_crypto_sym_cipher_api.md#oh_cryptosymcipher) \*\*ctx) | 根据给定的算法名称创建对称密钥加解密实例。 | 
| [OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode) [OH_CryptoSymCipher_Init](_crypto_sym_cipher_api.md#oh_cryptosymcipher_init) ([OH_CryptoSymCipher](_crypto_sym_cipher_api.md#oh_cryptosymcipher) \*ctx, [Crypto_CipherMode](_crypto_common_api.md#crypto_ciphermode) mod, [OH_CryptoSymKey](_crypto_sym_key_api.md#oh_cryptosymkey) \*key, [OH_CryptoSymCipherParams](_crypto_sym_cipher_api.md#oh_cryptosymcipherparams) \*params) | 初始化对称密钥加解密实例。 | 
| [OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode) [OH_CryptoSymCipher_Update](_crypto_sym_cipher_api.md#oh_cryptosymcipher_update) ([OH_CryptoSymCipher](_crypto_sym_cipher_api.md#oh_cryptosymcipher) \*ctx, [Crypto_DataBlob](_crypto___data_blob.md) \*in, [Crypto_DataBlob](_crypto___data_blob.md) \*out) | 更新加密或者解密数据操作。 | 
| [OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode) [OH_CryptoSymCipher_Final](_crypto_sym_cipher_api.md#oh_cryptosymcipher_final) ([OH_CryptoSymCipher](_crypto_sym_cipher_api.md#oh_cryptosymcipher) \*ctx, [Crypto_DataBlob](_crypto___data_blob.md) \*in, [Crypto_DataBlob](_crypto___data_blob.md) \*out) | 输出加/解密（分组模式产生的）剩余数据，最后结束加密或者解密数据操作。 | 
| const char \* [OH_CryptoSymCipher_GetAlgoName](_crypto_sym_cipher_api.md#oh_cryptosymcipher_getalgoname) ([OH_CryptoSymCipher](_crypto_sym_cipher_api.md#oh_cryptosymcipher) \*ctx) | 获取对称密钥加解密实例的算法名称。 | 
| void [OH_CryptoSymCipher_Destroy](_crypto_sym_cipher_api.md#oh_cryptosymcipher_destroy) ([OH_CryptoSymCipher](_crypto_sym_cipher_api.md#oh_cryptosymcipher) \*ctx) | 销毁对称密钥加解密实例。 | 
