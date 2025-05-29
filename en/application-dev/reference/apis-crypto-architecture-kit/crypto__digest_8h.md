# crypto_digest.h


## Overview

Provides APIs for message digest (MD) algorithms.

**Library**: libohcrypto.so

**System capability**: SystemCapability.Security.CryptoFramework

**Since**: 12

**Related module**: [CryptoDigestApi](_crypto_digest_api.md)


## Summary


### Types

| Name| Description| 
| -------- | -------- |
| typedef struct [OH_CryptoDigest](_crypto_digest_api.md#oh_cryptodigest) [OH_CryptoDigest](_crypto_digest_api.md#oh_cryptodigest) | Defines an MD.| 


### Functions

| Name| Description| 
| -------- | -------- |
| [OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode) [OH_CryptoDigest_Create](_crypto_digest_api.md#oh_cryptodigest_create) (const char \*algoName, [OH_CryptoDigest](_crypto_digest_api.md#oh_cryptodigest) \*\*ctx) | Creates an MD instance based on the given algorithm name.| 
| [OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode) [OH_CryptoDigest_Update](_crypto_digest_api.md#oh_cryptodigest_update) ([OH_CryptoDigest](_crypto_digest_api.md#oh_cryptodigest) \*ctx, [Crypto_DataBlob](_crypto___data_blob.md) \*in) | Updates the data used for generating an MD.| 
| [OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode) [OH_CryptoDigest_Final](_crypto_digest_api.md#oh_cryptodigest_final) ([OH_CryptoDigest](_crypto_digest_api.md#oh_cryptodigest) \*ctx, [Crypto_DataBlob](_crypto___data_blob.md) \*out) | Generates an MD.| 
| uint32_t [OH_CryptoDigest_GetLength](_crypto_digest_api.md#oh_cryptodigest_getlength) ([OH_CryptoDigest](_crypto_digest_api.md#oh_cryptodigest) \*ctx) | Obtains the length of an MD.| 
| const char \* [OH_CryptoDigest_GetAlgoName](_crypto_digest_api.md#oh_cryptodigest_getalgoname) ([OH_CryptoDigest](_crypto_digest_api.md#oh_cryptodigest) \*ctx) | Obtains the digest algorithm.| 
| void [OH_DigestCrypto_Destroy](_crypto_digest_api.md#oh_digestcrypto_destroy) ([OH_CryptoDigest](_crypto_digest_api.md#oh_cryptodigest) \*ctx) | Destroys an MD instance.| 
