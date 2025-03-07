# crypto_signature.h


## Overview

Provides APIs for signature verification.

**Library**: libohcrypto.so

**System capability**: SystemCapability.Security.CryptoFramework

**Since**: 12

**Related module**: [CryptoSignatureApi](_crypto_signature_api.md)


## Summary


### Types

| Name| Description| 
| -------- | -------- |
| typedef struct [OH_CryptoVerify](_crypto_signature_api.md#oh_cryptoverify) [OH_CryptoVerify](_crypto_signature_api.md#oh_cryptoverify) | Defines the data used for signature verification.| 


### Enums

| Name| Description| 
| -------- | -------- |
| [CryptoSignature_ParamType](_crypto_signature_api.md#cryptosignature_paramtype) {<br>CRYPTO_PSS_MD_NAME_STR = 100, CRYPTO_PSS_MGF_NAME_STR = 101,<br>CRYPTO_PSS_MGF1_NAME_STR = 102, CRYPTO_PSS_SALT_LEN_INT = 103,<br>CRYPTO_PSS_TRAILER_FIELD_INT = 104, CRYPTO_SM2_USER_ID_DATABLOB = 105<br>} | Enumerates the types of signature verification parameters.| 


### Functions

| Name| Description| 
| -------- | -------- |
| [OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode) [OH_CryptoVerify_Create](_crypto_signature_api.md#oh_cryptoverify_create) (const char \*algoName, [OH_CryptoVerify](_crypto_signature_api.md#oh_cryptoverify) \*\*verify) | Creates a **Verify** instance for signature verification.| 
| [OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode) [OH_CryptoVerify_Init](_crypto_signature_api.md#oh_cryptoverify_init) ([OH_CryptoVerify](_crypto_signature_api.md#oh_cryptoverify) \*ctx, [OH_CryptoPubKey](_crypto_asym_key_api.md#oh_cryptopubkey) \*pubKey) | Initializes a **Verify** instance by using the public key.| 
| [OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode) [OH_CryptoVerify_Update](_crypto_signature_api.md#oh_cryptoverify_update) ([OH_CryptoVerify](_crypto_signature_api.md#oh_cryptoverify) \*ctx, [Crypto_DataBlob](_crypto___data_blob.md) \*in) | Updates the data to be verified.| 
| bool [OH_CryptoVerify_Final](_crypto_signature_api.md#oh_cryptoverify_final) ([OH_CryptoVerify](_crypto_signature_api.md#oh_cryptoverify) \*ctx, [Crypto_DataBlob](_crypto___data_blob.md) \*in, [Crypto_DataBlob](_crypto___data_blob.md) \*signData) | Verifies the signature of the data.| 
| [OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode) [OH_CryptoVerify_Recover](_crypto_signature_api.md#oh_cryptoverify_recover) ([OH_CryptoVerify](_crypto_signature_api.md#oh_cryptoverify) \*ctx, [Crypto_DataBlob](_crypto___data_blob.md) \*signData, [Crypto_DataBlob](_crypto___data_blob.md) \*rawSignData) | Restores the signature data.| 
| const char \* [OH_CryptoVerify_GetAlgoName](_crypto_signature_api.md#oh_cryptoverify_getalgoname) ([OH_CryptoVerify](_crypto_signature_api.md#oh_cryptoverify) \*ctx) | Obtains the signature verification algorithm.| 
| [OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode) [OH_CryptoVerify_SetParam](_crypto_signature_api.md#oh_cryptoverify_setparam) ([OH_CryptoVerify](_crypto_signature_api.md#oh_cryptoverify) \*ctx, [CryptoSignature_ParamType](_crypto_signature_api.md#cryptosignature_paramtype) type, [Crypto_DataBlob](_crypto___data_blob.md) \*value) | Sets signature verification parameters.| 
| [OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode) [OH_CryptoVerify_GetParam](_crypto_signature_api.md#oh_cryptoverify_getparam) ([OH_CryptoVerify](_crypto_signature_api.md#oh_cryptoverify) \*ctx, [CryptoSignature_ParamType](_crypto_signature_api.md#cryptosignature_paramtype) type, [Crypto_DataBlob](_crypto___data_blob.md) \*value) | Obtains signature verification parameters.| 
| void [OH_CryptoVerify_Destroy](_crypto_signature_api.md#oh_cryptoverify_destroy) ([OH_CryptoVerify](_crypto_signature_api.md#oh_cryptoverify) \*ctx) | Destroys a **Verify** instance.| 
