# crypto_common.h

<!--Kit: Crypto Architecture Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--Designer: @lanming-->
<!--Tester: @PAFT-->
<!--Adviser: @zengyawen-->

## **Overview**

Defines common APIs for cryptographic operations.

**Header file**: <CryptoArchitectureKit/crypto_common.h>

**Library**: libohcrypto.so

**System capability**: SystemCapability.Security.CryptoFramework

**Since**: 12

**Related module**: [CryptoCommonApi](capi-cryptocommonapi.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) | Crypto_DataBlob | Defines the data used for encryption and decryption.|

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_Crypto_ErrCode](#oh_crypto_errcode) | OH_Crypto_ErrCode | Enumerates the encryption and decryption error codes.|
| [Crypto_CipherMode](#crypto_ciphermode) | Crypto_CipherMode | Enumerates the cryptographic operation types.|

### Functions

| Name| Description|
| -- | -- |
| [void OH_Crypto_FreeDataBlob(Crypto_DataBlob *dataBlob)](#oh_crypto_freedatablob) | Releases a **dataBlob** instance.|

## Enum Description

### OH_Crypto_ErrCode

```
enum OH_Crypto_ErrCode
```

**Description**

Enumerates the encryption and decryption error codes.

**Since**: 12

| Enum Item| Description|
| -- | -- |
| CRYPTO_SUCCESS = 0 | The operation is successful.|
| CRYPTO_INVALID_PARAMS = 401 | The input parameter is invalid.|
| CRYPTO_NOT_SUPPORTED = 801 | The function or algorithm is not supported.|
| CRYPTO_MEMORY_ERROR = 17620001 | Memory error.|
| CRYPTO_PARAMETER_CHECK_FAILED = 17620003 | Parameter check failed.<br>**Since**: 20 |
| CRYPTO_OPERTION_ERROR = 17630001 | The encryption or decryption operation fails.|

### Crypto_CipherMode

```
enum Crypto_CipherMode
```

**Description**

Enumerates the cryptographic operation types.

**Since**: 12

| Enum Item| Description|
| -- | -- |
| CRYPTO_ENCRYPT_MODE = 0 | Encryption.|
| CRYPTO_DECRYPT_MODE = 1 | Decryption.|


## Function Description

### OH_Crypto_FreeDataBlob()

```
void OH_Crypto_FreeDataBlob(Crypto_DataBlob *dataBlob)
```

**Description**

Releases a **dataBlob** instance.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *dataBlob | Pointer to the **dataBlob** instance to release.|
