# crypto_sym_cipher.h


## Overview

Provides APIs for symmetric encryption and decryption.

**Library**: libohcrypto.so

**System capability**: SystemCapability.Security.CryptoFramework

**Since**: 12

**Related module**: [CryptoSymCipherApi](_crypto_sym_cipher_api.md)


## Summary


### Types

| Name| Description| 
| -------- | -------- |
| typedef struct [OH_CryptoSymCipher](_crypto_sym_cipher_api.md#oh_cryptosymcipher) [OH_CryptoSymCipher](_crypto_sym_cipher_api.md#oh_cryptosymcipher) | Defines a symmetric encryption and decryption instance.| 
| typedef struct [OH_CryptoSymCipherParams](_crypto_sym_cipher_api.md#oh_cryptosymcipherparams) [OH_CryptoSymCipherParams](_crypto_sym_cipher_api.md#oh_cryptosymcipherparams) | Defines symmetric encryption and decryption parameters.| 


### Enums

| Name| Description| 
| -------- | -------- |
| [CryptoSymCipher_ParamsType](_crypto_sym_cipher_api.md#cryptosymcipher_paramstype) {<br>CRYPTO_IV_DATABLOB = 100,<br>CRYPTO_AAD_DATABLOB = 101,<br>CRYPTO_TAG_DATABLOB = 102<br>} | Enumerates the types of symmetric encryption and decryption parameters.| 


### Functions

| Name| Description| 
| -------- | -------- |
| [OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode) [OH_CryptoSymCipherParams_Create](_crypto_sym_cipher_api.md#oh_cryptosymcipherparams_create) ([OH_CryptoSymCipherParams](_crypto_sym_cipher_api.md#oh_cryptosymcipherparams) \*\*params) | Creates a symmetric encryption/decryption parameter instance.| 
| [OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode) [OH_CryptoSymCipherParams_SetParam](_crypto_sym_cipher_api.md#oh_cryptosymcipherparams_setparam) ([OH_CryptoSymCipherParams](_crypto_sym_cipher_api.md#oh_cryptosymcipherparams) \*params, [CryptoSymCipher_ParamsType](_crypto_sym_cipher_api.md#cryptosymcipher_paramstype) paramsType, [Crypto_DataBlob](_crypto___data_blob.md) \*value) | Sets symmetric encryption/decryption parameters.| 
| void [OH_CryptoSymCipherParams_Destroy](_crypto_sym_cipher_api.md#oh_cryptosymcipherparams_destroy) ([OH_CryptoSymCipherParams](_crypto_sym_cipher_api.md#oh_cryptosymcipherparams) \*params) | Destroys a symmetric encryption/decryption parameter instance.| 
| [OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode) [OH_CryptoSymCipher_Create](_crypto_sym_cipher_api.md#oh_cryptosymcipher_create) (const char \*algoName, [OH_CryptoSymCipher](_crypto_sym_cipher_api.md#oh_cryptosymcipher) \*\*ctx) | Creates a symmetric encryption/decryption instance based on the given algorithm name.| 
| [OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode) [OH_CryptoSymCipher_Init](_crypto_sym_cipher_api.md#oh_cryptosymcipher_init) ([OH_CryptoSymCipher](_crypto_sym_cipher_api.md#oh_cryptosymcipher) \*ctx, [Crypto_CipherMode](_crypto_common_api.md#crypto_ciphermode) mod, [OH_CryptoSymKey](_crypto_sym_key_api.md#oh_cryptosymkey) \*key, [OH_CryptoSymCipherParams](_crypto_sym_cipher_api.md#oh_cryptosymcipherparams) \*params) | Initializes a symmetric encryption/decryption instance.| 
| [OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode) [OH_CryptoSymCipher_Update](_crypto_sym_cipher_api.md#oh_cryptosymcipher_update) ([OH_CryptoSymCipher](_crypto_sym_cipher_api.md#oh_cryptosymcipher) \*ctx, [Crypto_DataBlob](_crypto___data_blob.md) \*in, [Crypto_DataBlob](_crypto___data_blob.md) \*out) | Updates the data to be encrypted or decrypted.| 
| [OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode) [OH_CryptoSymCipher_Final](_crypto_sym_cipher_api.md#oh_cryptosymcipher_final) ([OH_CryptoSymCipher](_crypto_sym_cipher_api.md#oh_cryptosymcipher) \*ctx, [Crypto_DataBlob](_crypto___data_blob.md) \*in, [Crypto_DataBlob](_crypto___data_blob.md) \*out) | Finishes the encryption or decryption operation.| 
| const char \* [OH_CryptoSymCipher_GetAlgoName](_crypto_sym_cipher_api.md#oh_cryptosymcipher_getalgoname) ([OH_CryptoSymCipher](_crypto_sym_cipher_api.md#oh_cryptosymcipher) \*ctx) | Obtains the symmetric encryption/decryption algorithm.| 
| void [OH_CryptoSymCipher_Destroy](_crypto_sym_cipher_api.md#oh_cryptosymcipher_destroy) ([OH_CryptoSymCipher](_crypto_sym_cipher_api.md#oh_cryptosymcipher) \*ctx) | Destroys a symmetric encryption/decryption instance.| 
