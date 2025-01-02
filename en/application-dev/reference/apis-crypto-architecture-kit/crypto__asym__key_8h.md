# crypto_asym_key.h


## Overview

Provides APIs for asymmetric keys.

**Library**: libohcrypto.z.so

**System capability**: SystemCapability.Security.CryptoFramework

**Since**: 12

**Related module**: [CryptoAsymKeyApi](_crypto_asym_key_api.md)


## Summary


### Types

| Name | Description |
| -------- | -------- |
| typedef struct [OH_CryptoKeyPair](_crypto_asym_key_api.md#oh_cryptokeypair) [OH_CryptoKeyPair](_crypto_asym_key_api.md#oh_cryptokeypair) | Defines an asymmetric key pair. |
| typedef struct [OH_CryptoPubKey](_crypto_asym_key_api.md#oh_cryptopubkey) [OH_CryptoPubKey](_crypto_asym_key_api.md#oh_cryptopubkey) | Defines the public key in an asymmetric key pair. |
| typedef struct [OH_CryptoAsymKeyGenerator](_crypto_asym_key_api.md#oh_cryptoasymkeygenerator) [OH_CryptoAsymKeyGenerator](_crypto_asym_key_api.md#oh_cryptoasymkeygenerator) | Defines an asymmetric key generator. |


### Enums

| Name | Description |
| -------- | -------- |
| [CryptoAsymKey_ParamType](_crypto_asym_key_api.md#cryptoasymkey_paramtype) {<br>CRYPTO_DSA_P_DATABLOB = 101, CRYPTO_DSA_Q_DATABLOB = 102,<br>CRYPTO_DSA_G_DATABLOB = 103, CRYPTO_DSA_SK_DATABLOB = 104,<br>CRYPTO_DSA_PK_DATABLOB = 105, CRYPTO_ECC_FP_P_DATABLOB = 201,<br>CRYPTO_ECC_A_DATABLOB = 202, CRYPTO_ECC_B_DATABLOB = 203,<br>CRYPTO_ECC_G_X_DATABLOB = 204, CRYPTO_ECC_G_Y_DATABLOB = 205,<br>CRYPTO_ECC_N_DATABLOB = 206, CRYPTO_ECC_H_INT = 207,<br>CRYPTO_ECC_SK_DATABLOB = 208, CRYPTO_ECC_PK_X_DATABLOB = 209,<br>CRYPTO_ECC_PK_Y_DATABLOB = 210, CRYPTO_ECC_FIELD_TYPE_STR = 211,<br>CRYPTO_ECC_FIELD_SIZE_INT = 212, CRYPTO_ECC_CURVE_NAME_STR = 213,<br>CRYPTO_RSA_N_DATABLOB = 301, CRYPTO_RSA_D_DATABLOB = 302,<br>CRYPTO_RSA_E_DATABLOB = 303, CRYPTO_DH_P_DATABLOB = 401,<br>CRYPTO_DH_G_DATABLOB = 402, CRYPTO_DH_L_NUM = 403,<br>CRYPTO_DH_SK_DATABLOB = 404, CRYPTO_DH_PK_DATABLOB = 405,<br>CRYPTO_ED25519_SK_DATABLOB = 501, CRYPTO_ED25519_PK_DATABLOB = 502,<br>CRYPTO_X25519_SK_DATABLOB = 601, CRYPTO_X25519_PK_DATABLOB = 602<br>} | Enumerates the types of the asymmetric key parameters. |
| [Crypto_EncodingType](_crypto_asym_key_api.md#crypto_encodingtype) { CRYPTO_PEM = 0, CRYPTO_DER = 1 } | Enumerates the encoding types. |


### Functions

| Name | Description |
| -------- | -------- |
| [OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode) [OH_CryptoAsymKeyGenerator_Create](_crypto_asym_key_api.md#oh_cryptoasymkeygenerator_create) (const char \*algoName, [OH_CryptoAsymKeyGenerator](_crypto_asym_key_api.md#oh_cryptoasymkeygenerator) \*\*ctx) | Creates an asymmetric key generator instance based on the specified algorithm. |
| [OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode) [OH_CryptoAsymKeyGenerator_Generate](_crypto_asym_key_api.md#oh_cryptoasymkeygenerator_generate) ([OH_CryptoAsymKeyGenerator](_crypto_asym_key_api.md#oh_cryptoasymkeygenerator) \*ctx, [OH_CryptoKeyPair](_crypto_asym_key_api.md#oh_cryptokeypair) \*\*keyCtx) | Randomly generates an asymmetric key pair. |
| [OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode) [OH_CryptoAsymKeyGenerator_Convert](_crypto_asym_key_api.md#oh_cryptoasymkeygenerator_convert) ([OH_CryptoAsymKeyGenerator](_crypto_asym_key_api.md#oh_cryptoasymkeygenerator) \*ctx, [Crypto_EncodingType](_crypto_asym_key_api.md#crypto_encodingtype) type, [Crypto_DataBlob](_crypto___data_blob.md) \*pubKeyData, [Crypto_DataBlob](_crypto___data_blob.md) \*priKeyData, [OH_CryptoKeyPair](_crypto_asym_key_api.md#oh_cryptokeypair) \*\*keyCtx) | Converts asymmetric key data into a key pair. |
| const char \* [OH_CryptoAsymKeyGenerator_GetAlgoName](_crypto_asym_key_api.md#oh_cryptoasymkeygenerator_getalgoname) ([OH_CryptoAsymKeyGenerator](_crypto_asym_key_api.md#oh_cryptoasymkeygenerator) \*ctx) | Obtains the asymmetric key algorithm. |
| void [OH_CryptoAsymKeyGenerator_Destroy](_crypto_asym_key_api.md#oh_cryptoasymkeygenerator_destroy) ([OH_CryptoAsymKeyGenerator](_crypto_asym_key_api.md#oh_cryptoasymkeygenerator) \*ctx) | Destroys an asymmetric key generator instance. |
| void [OH_CryptoKeyPair_Destroy](_crypto_asym_key_api.md#oh_cryptokeypair_destroy) ([OH_CryptoKeyPair](_crypto_asym_key_api.md#oh_cryptokeypair) \*keyCtx) | Destroys an asymmetric key pair instance. |
| [OH_CryptoPubKey](_crypto_asym_key_api.md#oh_cryptopubkey) \* [OH_CryptoKeyPair_GetPubKey](_crypto_asym_key_api.md#oh_cryptokeypair_getpubkey) ([OH_CryptoKeyPair](_crypto_asym_key_api.md#oh_cryptokeypair) \*keyCtx) | Obtains the public key instance from a key pair. |
| [OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode) [OH_CryptoPubKey_Encode](_crypto_asym_key_api.md#oh_cryptopubkey_encode) ([OH_CryptoPubKey](_crypto_asym_key_api.md#oh_cryptopubkey) \*key, [Crypto_EncodingType](_crypto_asym_key_api.md#crypto_encodingtype) type, const char \*encodingStandard, [Crypto_DataBlob](_crypto___data_blob.md) \*out) | Obtains public key data in the specified encoding format. |
| [OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode) [OH_CryptoPubKey_GetParam](_crypto_asym_key_api.md#oh_cryptopubkey_getparam) ([OH_CryptoPubKey](_crypto_asym_key_api.md#oh_cryptopubkey) \*key, [CryptoAsymKey_ParamType](_crypto_asym_key_api.md#cryptoasymkey_paramtype) item, [Crypto_DataBlob](_crypto___data_blob.md) \*value) | Obtains the specified parameter from a public key instance. |
