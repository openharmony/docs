# crypto_common.h


## Overview

Provides common APIs for cryptographic operations.

**Library**: libohcrypto.z.so

**System capability**: SystemCapability.Security.CryptoFramework

**Since**: 12

**Related module**: [CryptoCommonApi](_crypto_common_api.md)


## Summary


### Structs

| Name | Description |
| -------- | -------- |
| struct  [Crypto_DataBlob](_crypto___data_blob.md) | Defines the data used for encryption and decryption. |


### Types

| Name | Description |
| -------- | -------- |
| typedef struct [Crypto_DataBlob](_crypto___data_blob.md) [Crypto_DataBlob](_crypto_common_api.md#crypto_datablob) | Defines a struct for the data used for encryption and decryption. |


### Enums

| Name | Description |
| -------- | -------- |
| [OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode) {<br>CRYPTO_SUCCESS = 0, CRYPTO_INVALID_PARAMS = 401,<br>CRYPTO_NOT_SUPPORT = 801, CRYPTO_MEMORY_ERROR = 17620001,<br>CRYPTO_OPERTION_ERROR = 17630001<br>} | Enumerates the encryption and decryption error codes. |
| [Crypto_CipherMode](_crypto_common_api.md#crypto_ciphermode) {<br>CRYPTO_ENCRYPT_MODE = 0,<br>CRYPTO_DECRYPT_MODE = 1<br>} | Enumerates the cryptographic operation types. |


### Functions

| Name | Description |
| -------- | -------- |
| void [OH_Crypto_FreeDataBlob](_crypto_common_api.md#oh_crypto_freedatablob) ([Crypto_DataBlob](_crypto___data_blob.md) \*dataBlob) | Releases a **dataBlob** instance. |
