# CryptoCommonApi


## Overview

Provides common APIs for cryptographic operations.

**Since**: 12


## Summary


### Files

| Name | Description | 
| -------- | -------- |
| [crypto_common.h](crypto__common_8h.md) | Defines common APIs for cryptographic operations. | 


### Structs

| Name | Description | 
| -------- | -------- |
| struct  [Crypto_DataBlob](_crypto___data_blob.md) | Defines the data used for encryption and decryption. | 


### Types

| Name | Description | 
| -------- | -------- |
| typedef struct [Crypto_DataBlob](_crypto___data_blob.md) [Crypto_DataBlob](#crypto_datablob) | Defines a struct for the data used for encryption and decryption. | 


### Enums

| Name | Description | 
| -------- | -------- |
| [OH_Crypto_ErrCode](#oh_crypto_errcode) {<br>CRYPTO_SUCCESS = 0, CRYPTO_INVALID_PARAMS = 401,<br>CRYPTO_NOT_SUPPORT = 801, CRYPTO_MEMORY_ERROR = 17620001,<br>CRYPTO_OPERTION_ERROR = 17630001<br>} | Enumerates the encryption and decryption error codes. | 
| [Crypto_CipherMode](#crypto_ciphermode) {<br>CRYPTO_ENCRYPT_MODE = 0,<br>CRYPTO_DECRYPT_MODE = 1<br>} | Enumerates the cryptographic operation types. | 


### Functions

| Name | Description | 
| -------- | -------- |
| void [OH_Crypto_FreeDataBlob](#oh_crypto_freedatablob) ([Crypto_DataBlob](_crypto___data_blob.md) \*dataBlob) | Releases a **dataBlob** instance. | 


## Type Description


### Crypto_DataBlob

```
typedef struct Crypto_DataBlob Crypto_DataBlob
```

**Description**

Defines a struct for the data used for encryption and decryption.

**Since**: 12


## Enum Description


### Crypto_CipherMode

```
enum Crypto_CipherMode
```

**Description**

Enumerates the cryptographic operation types.

**Since**: 12

| Enum | Description | 
| -------- | -------- |
| CRYPTO_ENCRYPT_MODE | Encrypt data. | 
| CRYPTO_DECRYPT_MODE | Decrypt data. | 


### OH_Crypto_ErrCode

```
enum OH_Crypto_ErrCode
```

**Description**

Enumerates the encryption and decryption error codes.

**Since**: 12

| Enum | Description | 
| -------- | -------- |
| CRYPTO_SUCCESS | The operation is successful. | 
| CRYPTO_INVALID_PARAMS | Invalid parameters are detected. | 
| CRYPTO_NOT_SUPPORT | The function or algorithm is not supported. | 
| CRYPTO_MEMORY_ERROR | A memory error occurred. | 
| CRYPTO_OPERTION_ERROR | The encryption or decryption operation fails. | 


## Function Description


### OH_Crypto_FreeDataBlob()

```
void OH_Crypto_FreeDataBlob (Crypto_DataBlob *dataBlob)
```

**Description**

Releases a **dataBlob** instance.

**Since**: 12

**Parameters**

| Name | Description | 
| -------- | -------- |
| dataBlob | Pointer to the **dataBlob** instance to release. | 
