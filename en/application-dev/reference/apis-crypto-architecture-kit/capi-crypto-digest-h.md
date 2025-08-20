# crypto_digest.h

<!--Kit: Crypto Architecture Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--Designer: @lanming-->
<!--Tester: @PAFT-->
<!--Adviser: @zengyawen-->

## Overview

Defines APIs for MD algorithms.

**Header file**: <CryptoArchitectureKit/crypto_digest.h>

**Library**: libohcrypto.so

**System capability**: SystemCapability.Security.CryptoFramework

**Since**: 12

**Related module**: [CryptoDigestApi](capi-cryptodigestapi.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_CryptoDigest](capi-cryptodigestapi-oh-cryptodigest.md) | OH_CryptoDigest | Defines an MD.|

### Functions

| Name| Description|
| -- | -- |
| [OH_Crypto_ErrCode OH_CryptoDigest_Create(const char *algoName, OH_CryptoDigest **ctx)](#oh_cryptodigest_create) | Creates an MD instance based on the given algorithm name.|
| [OH_Crypto_ErrCode OH_CryptoDigest_Update(OH_CryptoDigest *ctx, Crypto_DataBlob *in)](#oh_cryptodigest_update) | Updates MD data.|
| [OH_Crypto_ErrCode OH_CryptoDigest_Final(OH_CryptoDigest *ctx, Crypto_DataBlob *out)](#oh_cryptodigest_final) | Implements MD calculation.|
| [uint32_t OH_CryptoDigest_GetLength(OH_CryptoDigest *ctx)](#oh_cryptodigest_getlength) | Obtains the length of an MD.|
| [const char *OH_CryptoDigest_GetAlgoName(OH_CryptoDigest *ctx)](#oh_cryptodigest_getalgoname) | Obtains the name of an MD algorithm.|
| [void OH_DigestCrypto_Destroy(OH_CryptoDigest *ctx)](#oh_digestcrypto_destroy) | Destroys an MD instance.|

## Function Description

### OH_CryptoDigest_Create()

```
OH_Crypto_ErrCode OH_CryptoDigest_Create(const char *algoName, OH_CryptoDigest **ctx)
```

**Description**

Creates an MD instance based on the given algorithm name.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const char *algoName | Pointer to the algorithm used to generate the MD instance.<br> For example, **'SHA256'**.|
| [OH_CryptoDigest](capi-cryptodigestapi-oh-cryptodigest.md) **ctx | Pointer to the MD instance created.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | **CRYPTO_SUCCESS**: The operation is successful.<br>         **CRYPTO_INVALID_PARAMS**: A parameter is invalid.<br>         **CRYPTO_NOT_SUPPORTED**: The operation is not supported.<br>         **CRYPTO_MEMORY_ERROR**: A memory error occurs.<br>         **CRYPTO_OPERTION_ERROR**: Failed to call an API of a third-party algorithm library.|

### OH_CryptoDigest_Update()

```
OH_Crypto_ErrCode OH_CryptoDigest_Update(OH_CryptoDigest *ctx, Crypto_DataBlob *in)
```

**Description**

Updates MD data.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoDigest](capi-cryptodigestapi-oh-cryptodigest.md) *ctx | Pointer to the MD instance.|
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *in | Pointer to the data to pass in.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | **CRYPTO_SUCCESS**: The operation is successful.<br>         **CRYPTO_INVALID_PARAMS**: A parameter is invalid.<br>         **CRYPTO_NOT_SUPPORTED**: The operation is not supported.<br>         **CRYPTO_MEMORY_ERROR**: A memory error occurs.<br>         **CRYPTO_OPERTION_ERROR**: Failed to call an API of a third-party algorithm library.|

**See also**

[OH_CryptoDigest_Final](capi-crypto-digest-h.md#oh_cryptodigest_final)


### OH_CryptoDigest_Final()

```
OH_Crypto_ErrCode OH_CryptoDigest_Final(OH_CryptoDigest *ctx, Crypto_DataBlob *out)
```

**Description**

Implements MD calculation.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoDigest](capi-cryptodigestapi-oh-cryptodigest.md) *ctx | Pointer to the MD instance.|
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *out | Pointer to the MD generated.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | **CRYPTO_SUCCESS**: The operation is successful.<br>         **CRYPTO_INVALID_PARAMS**: A parameter is invalid.<br>         **CRYPTO_NOT_SUPPORTED**: The operation is not supported.<br>         **CRYPTO_MEMORY_ERROR**: A memory error occurs.<br>         **CRYPTO_OPERTION_ERROR**: Failed to call an API of a third-party algorithm library.|

**See also**

[OH_CryptoDigest_Update](capi-crypto-digest-h.md#oh_cryptodigest_update)


### OH_CryptoDigest_GetLength()

```
uint32_t OH_CryptoDigest_GetLength(OH_CryptoDigest *ctx)
```

**Description**

Obtains the length of an MD.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoDigest](capi-cryptodigestapi-oh-cryptodigest.md) *ctx | Pointer to the MD instance.|

**Returns**

| Type| Description|
| -- | -- |
| uint32_t | Digest length.<br>        If the input parameter **ctx** is **NULL**, **401** is returned. In other cases, **0** is returned.|

### OH_CryptoDigest_GetAlgoName()

```
const char *OH_CryptoDigest_GetAlgoName(OH_CryptoDigest *ctx)
```

**Description**

Obtains the name of an MD algorithm.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoDigest](capi-cryptodigestapi-oh-cryptodigest.md) *ctx | Pointer to the MD instance.|

**Returns**

| Type| Description|
| -- | -- |
| const char * | MD algorithm name.|

### OH_DigestCrypto_Destroy()

```
void OH_DigestCrypto_Destroy(OH_CryptoDigest *ctx)
```

**Description**

Destroys an MD instance.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoDigest](capi-cryptodigestapi-oh-cryptodigest.md) *ctx | Pointer to the MD instance.|
