# crypto_kdf.h

<!--Kit: Crypto Architecture Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--Designer: @lanming-->
<!--Tester: @PAFT-->
<!--Adviser: @zengyawen-->

## Overview

Defines key derivation function (KDF) APIs.

**Header file**: <CryptoArchitectureKit/crypto_kdf.h>

**Library**: libohcrypto.so

**System capability**: SystemCapability.Security.CryptoFramework

**Since**: 20

**Related module**: [CryptoKdfApi](capi-cryptokdfapi.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_CryptoKdf](capi-cryptokdfapi-oh-cryptokdf.md) | OH_CryptoKdf | Defines a KDF.|
| [OH_CryptoKdfParams](capi-cryptokdfapi-oh-cryptokdfparams.md) | OH_CryptoKdfParams | Defines KDF parameters.|

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [CryptoKdf_ParamType](#cryptokdf_paramtype) | CryptoKdf_ParamType | Defines KDF parameter types.|

### Functions

| Name| Description|
| -- | -- |
| [OH_Crypto_ErrCode OH_CryptoKdfParams_Create(const char *algoName, OH_CryptoKdfParams **params)](#oh_cryptokdfparams_create) | Creates KDF parameters.|
| [OH_Crypto_ErrCode OH_CryptoKdfParams_SetParam(OH_CryptoKdfParams *params, CryptoKdf_ParamType type,Crypto_DataBlob *value)](#oh_cryptokdfparams_setparam) | Sets KDF parameters.|
| [void OH_CryptoKdfParams_Destroy(OH_CryptoKdfParams *params)](#oh_cryptokdfparams_destroy) | Destroys KDF parameters.|
| [OH_Crypto_ErrCode OH_CryptoKdf_Create(const char *algoName, OH_CryptoKdf **ctx)](#oh_cryptokdf_create) | Creates a KDF instance.|
| [OH_Crypto_ErrCode OH_CryptoKdf_Derive(OH_CryptoKdf *ctx, const OH_CryptoKdfParams *params, int keyLen,Crypto_DataBlob *key)](#oh_cryptokdf_derive) | Derives a key.|
| [void OH_CryptoKdf_Destroy(OH_CryptoKdf *ctx)](#oh_cryptokdf_destroy) | Destroys a KDF instance.|

## Enum Description

### CryptoKdf_ParamType

```
enum CryptoKdf_ParamType
```

**Description**

Defines KDF parameter types.

**Since**: 20

| Enum Item| Description|
| -- | -- |
| CRYPTO_KDF_KEY_DATABLOB = 0 | Key or password of the KDF.|
| CRYPTO_KDF_SALT_DATABLOB = 1 | Salt value of the KDF.|
| CRYPTO_KDF_INFO_DATABLOB = 2 | Information of the KDF.|
| CRYPTO_KDF_ITER_COUNT_INT = 3 | Iteration count of PBKDF2.|
| CRYPTO_KDF_SCRYPT_N_UINT64 = 4 | Parameter **n** of the SCRYPT KDF.|
| CRYPTO_KDF_SCRYPT_R_UINT64 = 5 | Parameter **r** of the SCRYPT KDF.|
| CRYPTO_KDF_SCRYPT_P_UINT64 = 6 | Parameter **p** of the SCRYPT KDF.|
| CRYPTO_KDF_SCRYPT_MAX_MEM_UINT64 = 7 | Maximum memory usage of the SCRYPT KDF.|


## Function Description

### OH_CryptoKdfParams_Create()

```
OH_Crypto_ErrCode OH_CryptoKdfParams_Create(const char *algoName, OH_CryptoKdfParams **params)
```

**Description**

Creates KDF parameters.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| const char *algoName | KDF algorithm name.<br> For example, HKDF\|SHA384\|EXTRACT_AND_EXPAND; PBKDF2\|SHA-384.|
| [OH_CryptoKdfParams](capi-cryptokdfapi-oh-cryptokdfparams.md) **params | KDF parameters.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | **CRYPTO_SUCCESS**: The operation is successful.<br>         **CRYPTO_NOT_SUPPORTED**: The operation is not supported.<br>         **CRYPTO_MEMORY_ERROR**: A memory error occurs.<br>         **CRYPTO_PARAMETER_CHECK_FAILED**: The parameter check failed.<br>         **CRYPTO_OPERTION_ERROR**: Failed to call an API of a third-party algorithm library.|

### OH_CryptoKdfParams_SetParam()

```
OH_Crypto_ErrCode OH_CryptoKdfParams_SetParam(OH_CryptoKdfParams *params, CryptoKdf_ParamType type,Crypto_DataBlob *value)
```

**Description**

Sets KDF parameters.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoKdfParams](capi-cryptokdfapi-oh-cryptokdfparams.md) *params | KDF parameters.|
| [CryptoKdf_ParamType](#cryptokdf_paramtype) type | KDF parameter type.|
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *value | KDF parameter values.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | **CRYPTO_SUCCESS**: The operation is successful.<br>         **CRYPTO_NOT_SUPPORTED**: The operation is not supported.<br>         **CRYPTO_MEMORY_ERROR**: A memory error occurs.<br>         **CRYPTO_PARAMETER_CHECK_FAILED**: The parameter check failed.<br>         **CRYPTO_OPERTION_ERROR**: Failed to call an API of a third-party algorithm library.|

### OH_CryptoKdfParams_Destroy()

```
void OH_CryptoKdfParams_Destroy(OH_CryptoKdfParams *params)
```

**Description**

Destroys KDF parameters.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoKdfParams](capi-cryptokdfapi-oh-cryptokdfparams.md) *params | KDF parameters.|

### OH_CryptoKdf_Create()

```
OH_Crypto_ErrCode OH_CryptoKdf_Create(const char *algoName, OH_CryptoKdf **ctx)
```

**Description**

Creates a KDF instance.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| const char *algoName | KDF algorithm name.|
| [OH_CryptoKdf](capi-cryptokdfapi-oh-cryptokdf.md) **ctx | KDF instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | **CRYPTO_SUCCESS**: The operation is successful.<br>         **CRYPTO_NOT_SUPPORTED**: The operation is not supported.<br>         **CRYPTO_MEMORY_ERROR**: A memory error occurs.<br>         **CRYPTO_PARAMETER_CHECK_FAILED**: The parameter check failed.<br>         **CRYPTO_OPERTION_ERROR**: Failed to call an API of a third-party algorithm library.|

### OH_CryptoKdf_Derive()

```
OH_Crypto_ErrCode OH_CryptoKdf_Derive(OH_CryptoKdf *ctx, const OH_CryptoKdfParams *params, int keyLen,Crypto_DataBlob *key)
```

**Description**

Derives a key.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoKdf](capi-cryptokdfapi-oh-cryptokdf.md) *ctx | KDF instance.|
| [const OH_CryptoKdfParams](capi-cryptokdfapi-oh-cryptokdfparams.md) *params | KDF parameters.|
| int keyLen | Length of the derived key.|
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *key | Derived key.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | **CRYPTO_SUCCESS**: The operation is successful.<br>         **CRYPTO_NOT_SUPPORTED**: The operation is not supported.<br>         **CRYPTO_MEMORY_ERROR**: A memory error occurs.<br>         **CRYPTO_PARAMETER_CHECK_FAILED**: The parameter check failed.<br>         **CRYPTO_OPERTION_ERROR**: Failed to call an API of a third-party algorithm library.|

### OH_CryptoKdf_Destroy()

```
void OH_CryptoKdf_Destroy(OH_CryptoKdf *ctx)
```

**Description**

Destroys a KDF instance.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoKdf](capi-cryptokdfapi-oh-cryptokdf.md) *ctx | KDF instance.|
