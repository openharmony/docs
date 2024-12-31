# crypto_asym_key.h


## 概述

声明非对称密钥接口。

**库：** libohcrypto.so

**系统能力：** SystemCapability.Security.CryptoFramework

**起始版本：** 12

**相关模块：**[CryptoAsymKeyApi](_crypto_asym_key_api.md)


## 汇总


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [OH_CryptoKeyPair](_crypto_asym_key_api.md#oh_cryptokeypair) [OH_CryptoKeyPair](_crypto_asym_key_api.md#oh_cryptokeypair) | 定义密钥对结构体。 | 
| typedef struct [OH_CryptoPubKey](_crypto_asym_key_api.md#oh_cryptopubkey) [OH_CryptoPubKey](_crypto_asym_key_api.md#oh_cryptopubkey) | 定义公钥结构体。 | 
| typedef struct [OH_CryptoAsymKeyGenerator](_crypto_asym_key_api.md#oh_cryptoasymkeygenerator) [OH_CryptoAsymKeyGenerator](_crypto_asym_key_api.md#oh_cryptoasymkeygenerator) | 定义非对称密钥生成器结构体。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [CryptoAsymKey_ParamType](_crypto_asym_key_api.md#cryptoasymkey_paramtype) {<br/>CRYPTO_DSA_P_DATABLOB = 101, CRYPTO_DSA_Q_DATABLOB = 102,<br/>CRYPTO_DSA_G_DATABLOB = 103, CRYPTO_DSA_SK_DATABLOB = 104,<br/>CRYPTO_DSA_PK_DATABLOB = 105, CRYPTO_ECC_FP_P_DATABLOB = 201,<br/>CRYPTO_ECC_A_DATABLOB = 202, CRYPTO_ECC_B_DATABLOB = 203,<br/>CRYPTO_ECC_G_X_DATABLOB = 204, CRYPTO_ECC_G_Y_DATABLOB = 205,<br/>CRYPTO_ECC_N_DATABLOB = 206, CRYPTO_ECC_H_INT = 207,<br/>CRYPTO_ECC_SK_DATABLOB = 208, CRYPTO_ECC_PK_X_DATABLOB = 209,<br/>CRYPTO_ECC_PK_Y_DATABLOB = 210, CRYPTO_ECC_FIELD_TYPE_STR = 211,<br/>CRYPTO_ECC_FIELD_SIZE_INT = 212, CRYPTO_ECC_CURVE_NAME_STR = 213,<br/>CRYPTO_RSA_N_DATABLOB = 301, CRYPTO_RSA_D_DATABLOB = 302,<br/>CRYPTO_RSA_E_DATABLOB = 303, CRYPTO_DH_P_DATABLOB = 401,<br/>CRYPTO_DH_G_DATABLOB = 402, CRYPTO_DH_L_NUM = 403,<br/>CRYPTO_DH_SK_DATABLOB = 404, CRYPTO_DH_PK_DATABLOB = 405,<br/>CRYPTO_ED25519_SK_DATABLOB = 501, CRYPTO_ED25519_PK_DATABLOB = 502,<br/>CRYPTO_X25519_SK_DATABLOB = 601, CRYPTO_X25519_PK_DATABLOB = 602<br/>} | 定义非对称密钥参数类型。 | 
| [Crypto_EncodingType](_crypto_asym_key_api.md#crypto_encodingtype) { CRYPTO_PEM = 0, CRYPTO_DER = 1 } | 定义编码格式。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode) [OH_CryptoAsymKeyGenerator_Create](_crypto_asym_key_api.md#oh_cryptoasymkeygenerator_create) (const char \*algoName, [OH_CryptoAsymKeyGenerator](_crypto_asym_key_api.md#oh_cryptoasymkeygenerator) \*\*ctx) | 通过指定算法名称的字符串，获取相应的非对称密钥生成器实例。 | 
| [OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode) [OH_CryptoAsymKeyGenerator_Generate](_crypto_asym_key_api.md#oh_cryptoasymkeygenerator_generate) ([OH_CryptoAsymKeyGenerator](_crypto_asym_key_api.md#oh_cryptoasymkeygenerator) \*ctx, [OH_CryptoKeyPair](_crypto_asym_key_api.md#oh_cryptokeypair) \*\*keyCtx) | 随机生成非对称密钥（密钥对）。 | 
| [OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode) [OH_CryptoAsymKeyGenerator_Convert](_crypto_asym_key_api.md#oh_cryptoasymkeygenerator_convert) ([OH_CryptoAsymKeyGenerator](_crypto_asym_key_api.md#oh_cryptoasymkeygenerator) \*ctx, [Crypto_EncodingType](_crypto_asym_key_api.md#crypto_encodingtype) type, [Crypto_DataBlob](_crypto___data_blob.md) \*pubKeyData, [Crypto_DataBlob](_crypto___data_blob.md) \*priKeyData, [OH_CryptoKeyPair](_crypto_asym_key_api.md#oh_cryptokeypair) \*\*keyCtx) | 转换非对称密钥数据为密钥对。 | 
| const char \* [OH_CryptoAsymKeyGenerator_GetAlgoName](_crypto_asym_key_api.md#oh_cryptoasymkeygenerator_getalgoname) ([OH_CryptoAsymKeyGenerator](_crypto_asym_key_api.md#oh_cryptoasymkeygenerator) \*ctx) | 获取非对称密钥算法名称。 | 
| void [OH_CryptoAsymKeyGenerator_Destroy](_crypto_asym_key_api.md#oh_cryptoasymkeygenerator_destroy) ([OH_CryptoAsymKeyGenerator](_crypto_asym_key_api.md#oh_cryptoasymkeygenerator) \*ctx) | 销毁非对称密钥生成器实例。 | 
| void [OH_CryptoKeyPair_Destroy](_crypto_asym_key_api.md#oh_cryptokeypair_destroy) ([OH_CryptoKeyPair](_crypto_asym_key_api.md#oh_cryptokeypair) \*keyCtx) | 销毁非对称密钥对实例。 | 
| [OH_CryptoPubKey](_crypto_asym_key_api.md#oh_cryptopubkey) \* [OH_CryptoKeyPair_GetPubKey](_crypto_asym_key_api.md#oh_cryptokeypair_getpubkey) ([OH_CryptoKeyPair](_crypto_asym_key_api.md#oh_cryptokeypair) \*keyCtx) | 从密钥对中获取公钥实例。 | 
| [OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode) [OH_CryptoPubKey_Encode](_crypto_asym_key_api.md#oh_cryptopubkey_encode) ([OH_CryptoPubKey](_crypto_asym_key_api.md#oh_cryptopubkey) \*key, [Crypto_EncodingType](_crypto_asym_key_api.md#crypto_encodingtype) type, const char \*encodingStandard, [Crypto_DataBlob](_crypto___data_blob.md) \*out) | 根据指定的编码格式输出公钥数据。 | 
| [OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode) [OH_CryptoPubKey_GetParam](_crypto_asym_key_api.md#oh_cryptopubkey_getparam) ([OH_CryptoPubKey](_crypto_asym_key_api.md#oh_cryptopubkey) \*key, [CryptoAsymKey_ParamType](_crypto_asym_key_api.md#cryptoasymkey_paramtype) item, [Crypto_DataBlob](_crypto___data_blob.md) \*value) | 从公钥实例获取指定参数。 | 
