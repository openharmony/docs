# crypto_sym_key.h


## Overview

Provides APIs for symmetric key operations.

**Library**: libohcrypto.so

**System capability**: SystemCapability.Security.CryptoFramework

**Since**: 12

**Related module**: [CryptoSymKeyApi](_crypto_sym_key_api.md)


## Summary


### Types

| Name| Description| 
| -------- | -------- |
| typedef struct [OH_CryptoSymKey](_crypto_sym_key_api.md#oh_cryptosymkey) [OH_CryptoSymKey](_crypto_sym_key_api.md#oh_cryptosymkey) | Defines a struct for a symmetric key.| 
| typedef struct [OH_CryptoSymKeyGenerator](_crypto_sym_key_api.md#oh_cryptosymkeygenerator) [OH_CryptoSymKeyGenerator](_crypto_sym_key_api.md#oh_cryptosymkeygenerator) | Defines a struct for a symmetric key generator.| 


### Functions

| Name| Description| 
| -------- | -------- |
| [OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode) [OH_CryptoSymKeyGenerator_Create](_crypto_sym_key_api.md#oh_cryptosymkeygenerator_create) (const char \*algoName, [OH_CryptoSymKeyGenerator](_crypto_sym_key_api.md#oh_cryptosymkeygenerator) \*\*ctx) | Creates a symmetric key generator instance based on the given algorithm name.| 
| [OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode) [OH_CryptoSymKeyGenerator_Generate](_crypto_sym_key_api.md#oh_cryptosymkeygenerator_generate) ([OH_CryptoSymKeyGenerator](_crypto_sym_key_api.md#oh_cryptosymkeygenerator) \*ctx, [OH_CryptoSymKey](_crypto_sym_key_api.md#oh_cryptosymkey) \*\*keyCtx) | Randomly generates a symmetric key.| 
| [OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode) [OH_CryptoSymKeyGenerator_Convert](_crypto_sym_key_api.md#oh_cryptosymkeygenerator_convert) ([OH_CryptoSymKeyGenerator](_crypto_sym_key_api.md#oh_cryptosymkeygenerator) \*ctx, const [Crypto_DataBlob](_crypto___data_blob.md) \*keyData, [OH_CryptoSymKey](_crypto_sym_key_api.md#oh_cryptosymkey) \*\*keyCtx) | Converts binary data into a symmetric key.| 
| const char \* [OH_CryptoSymKeyGenerator_GetAlgoName](_crypto_sym_key_api.md#oh_cryptosymkeygenerator_getalgoname) ([OH_CryptoSymKeyGenerator](_crypto_sym_key_api.md#oh_cryptosymkeygenerator) \*ctx) | Obtains the algorithm of a symmetric key generator instance.| 
| void [OH_CryptoSymKeyGenerator_Destroy](_crypto_sym_key_api.md#oh_cryptosymkeygenerator_destroy) ([OH_CryptoSymKeyGenerator](_crypto_sym_key_api.md#oh_cryptosymkeygenerator) \*ctx) | Destroys a symmetric key generator instance.| 
| const char \* [OH_CryptoSymKey_GetAlgoName](_crypto_sym_key_api.md#oh_cryptosymkey_getalgoname) ([OH_CryptoSymKey](_crypto_sym_key_api.md#oh_cryptosymkey) \*keyCtx) | Obtains the algorithm of a symmetric key.| 
| [OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode) [OH_CryptoSymKey_GetKeyData](_crypto_sym_key_api.md#oh_cryptosymkey_getkeydata) ([OH_CryptoSymKey](_crypto_sym_key_api.md#oh_cryptosymkey) \*keyCtx, [Crypto_DataBlob](_crypto___data_blob.md) \*out) | Obtains symmetric key data from a key instance.| 
| void [OH_CryptoSymKey_Destroy](_crypto_sym_key_api.md#oh_cryptosymkey_destroy) ([OH_CryptoSymKey](_crypto_sym_key_api.md#oh_cryptosymkey) \*keyCtx) | Destroys a symmetric key instance.| 
