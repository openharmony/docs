# crypto_rand.h

<!--Kit: Crypto Architecture Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--Designer: @lanming-->
<!--Tester: @PAFT-->
<!--Adviser: @zengyawen-->

## Overview

Defines APIs for a random number generator.

**Header file**: <CryptoArchitectureKit/crypto_rand.h>

**Library**: libohcrypto.so

**System capability**: SystemCapability.Security.CryptoFramework

**Since**: 20

**Related Module**: [CryptoRandApi](capi-cryptorandapi.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_CryptoRand](capi-cryptorandapi-oh-cryptorand.md) | OH_CryptoRand | Defines a struct for a random number generator.|

### Functions

| Name| Description|
| -- | -- |
| [OH_Crypto_ErrCode OH_CryptoRand_Create(OH_CryptoRand **ctx)](#oh_cryptorand_create) | Creates a random number generator.|
| [OH_Crypto_ErrCode OH_CryptoRand_GenerateRandom(OH_CryptoRand *ctx, int len, Crypto_DataBlob *out)](#oh_cryptorand_generaterandom) | Generates random numbers.|
| [const char *OH_CryptoRand_GetAlgoName(OH_CryptoRand *ctx)](#oh_cryptorand_getalgoname) | Obtains the algorithm name of a random number generator instance.|
| [OH_Crypto_ErrCode OH_CryptoRand_SetSeed(OH_CryptoRand *ctx, Crypto_DataBlob *seed)](#oh_cryptorand_setseed) | Sets the seed of a random number generator.|
| [void OH_CryptoRand_Destroy(OH_CryptoRand *ctx)](#oh_cryptorand_destroy) | Destroys a random number generator instance.|

## Function Description

### OH_CryptoRand_Create()

```
OH_Crypto_ErrCode OH_CryptoRand_Create(OH_CryptoRand **ctx)
```

**Description**

Creates a random number generator.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoRand](capi-cryptorandapi-oh-cryptorand.md) **ctx | Pointer to the random number generator instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | **CRYPTO_SUCCESS**: The operation is successful.<br>         **CRYPTO_NOT_SUPPORTED**: The operation is not supported.<br>         **CRYPTO_MEMORY_ERROR**: A memory error occurs.<br>         **CRYPTO_PARAMETER_CHECK_FAILED**: The parameter check failed.<br>         **CRYPTO_OPERTION_ERROR**: Failed to call an API of a third-party algorithm library.|

### OH_CryptoRand_GenerateRandom()

```
OH_Crypto_ErrCode OH_CryptoRand_GenerateRandom(OH_CryptoRand *ctx, int len, Crypto_DataBlob *out)
```

**Description**

Generates random numbers.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoRand](capi-cryptorandapi-oh-cryptorand.md) *ctx | Random number generator instance.|
| int len | Length of the random number to generate, in bytes. The value range is [1, INT_MAX].|
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *out | Pointer to the random number.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | **CRYPTO_SUCCESS**: The operation is successful.<br>         **CRYPTO_NOT_SUPPORTED**: The operation is not supported.<br>         **CRYPTO_MEMORY_ERROR**: A memory error occurs.<br>         **CRYPTO_PARAMETER_CHECK_FAILED**: The parameter check failed.<br>         **CRYPTO_OPERTION_ERROR**: Failed to call an API of a third-party algorithm library.|

### OH_CryptoRand_GetAlgoName()

```
const char *OH_CryptoRand_GetAlgoName(OH_CryptoRand *ctx)
```

**Description**

Obtains the algorithm name of a random number generator instance.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoRand](capi-cryptorandapi-oh-cryptorand.md) *ctx | Pointer to the random number generator instance.|

**Returns**

| Type| Description|
| -- | -- |
| const char * | Algorithm name of a random number generator instance.|

### OH_CryptoRand_SetSeed()

```
OH_Crypto_ErrCode OH_CryptoRand_SetSeed(OH_CryptoRand *ctx, Crypto_DataBlob *seed)
```

**Description**

Sets the seed of a random number generator.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoRand](capi-cryptorandapi-oh-cryptorand.md) *ctx | Random number generator instance.|
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *seed | Seed data.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | **CRYPTO_SUCCESS**: The operation is successful.<br>         **CRYPTO_NOT_SUPPORTED**: The operation is not supported.<br>         **CRYPTO_MEMORY_ERROR**: A memory error occurs.<br>         **CRYPTO_PARAMETER_CHECK_FAILED**: The parameter check failed.<br>         **CRYPTO_OPERTION_ERROR**: Failed to call an API of a third-party algorithm library.|

### OH_CryptoRand_Destroy()

```
void OH_CryptoRand_Destroy(OH_CryptoRand *ctx)
```

**Description**

Destroys a random number generator instance.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoRand](capi-cryptorandapi-oh-cryptorand.md) *ctx | Random number generator instance.|
