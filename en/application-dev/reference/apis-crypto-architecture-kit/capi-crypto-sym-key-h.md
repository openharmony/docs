# crypto_sym_key.h

<!--Kit: Crypto Architecture Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--Designer: @lanming-->
<!--Tester: @PAFT-->
<!--Adviser: @zengyawen-->

## Overview

Provides APIs for symmetric keys.

**Header file**: <CryptoArchitectureKit/crypto_sym_key.h>

**Library**: libohcrypto.so

**System capability**: SystemCapability.Security.CryptoFramework

**Since**: 12

**Related module**: [CryptoSymKeyApi](capi-cryptosymkeyapi.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_CryptoSymKey](capi-cryptosymkeyapi-oh-cryptosymkey.md) | OH_CryptoSymKey | Defines a struct for a symmetric key generator.|
| [OH_CryptoSymKeyGenerator](capi-cryptosymkeyapi-oh-cryptosymkeygenerator.md) | OH_CryptoSymKeyGenerator | Defines a struct for a symmetric key.|

### Functions

| Name| Description|
| -- | -- |
| [OH_Crypto_ErrCode OH_CryptoSymKeyGenerator_Create(const char *algoName, OH_CryptoSymKeyGenerator **ctx)](#oh_cryptosymkeygenerator_create) | Creates a symmetric key generator instance based on the given algorithm name.|
| [OH_Crypto_ErrCode OH_CryptoSymKeyGenerator_Generate(OH_CryptoSymKeyGenerator *ctx, OH_CryptoSymKey **keyCtx)](#oh_cryptosymkeygenerator_generate) | Randomly generates a symmetric key.|
| [OH_Crypto_ErrCode OH_CryptoSymKeyGenerator_Convert(OH_CryptoSymKeyGenerator *ctx,const Crypto_DataBlob *keyData, OH_CryptoSymKey **keyCtx)](#oh_cryptosymkeygenerator_convert) | Converts binary data into a symmetric key.|
| [const char *OH_CryptoSymKeyGenerator_GetAlgoName(OH_CryptoSymKeyGenerator *ctx)](#oh_cryptosymkeygenerator_getalgoname) | Obtains the algorithm of a symmetric key generator instance.|
| [void OH_CryptoSymKeyGenerator_Destroy(OH_CryptoSymKeyGenerator *ctx)](#oh_cryptosymkeygenerator_destroy) | Destroys a symmetric key generator instance.|
| [const char *OH_CryptoSymKey_GetAlgoName(OH_CryptoSymKey *keyCtx)](#oh_cryptosymkey_getalgoname) | Obtains the algorithm of a symmetric key.|
| [OH_Crypto_ErrCode OH_CryptoSymKey_GetKeyData(OH_CryptoSymKey *keyCtx, Crypto_DataBlob *out)](#oh_cryptosymkey_getkeydata) | Obtains symmetric key data from a key instance.|
| [void OH_CryptoSymKey_Destroy(OH_CryptoSymKey *keyCtx)](#oh_cryptosymkey_destroy) | Destroys a symmetric key instance.|

## Function Description

### OH_CryptoSymKeyGenerator_Create()

```
OH_Crypto_ErrCode OH_CryptoSymKeyGenerator_Create(const char *algoName, OH_CryptoSymKeyGenerator **ctx)
```

**Description**

Creates a symmetric key generator instance based on the given algorithm name.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const char *algoName | Pointer the algorithm used to create a generator.<br> For example, **'AES256'**, **'AES128'**, and **'SM4'**.|
| [OH_CryptoSymKeyGenerator](capi-cryptosymkeyapi-oh-cryptosymkeygenerator.md) **ctx | Double pointer to the symmetric key generator instance created.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | **CRYPTO_SUCCESS**: The operation is successful.<br>         **CRYPTO_INVALID_PARAMS**: A parameter is invalid.<br>         **CRYPTO_NOT_SUPPORTED**: The operation is not supported.<br>         **CRYPTO_MEMORY_ERROR**: A memory error occurs.<br>         **CRYPTO_OPERTION_ERROR**: Failed to call an API of a third-party algorithm library.|

### OH_CryptoSymKeyGenerator_Generate()

```
OH_Crypto_ErrCode OH_CryptoSymKeyGenerator_Generate(OH_CryptoSymKeyGenerator *ctx, OH_CryptoSymKey **keyCtx)
```

**Description**

Randomly generates a symmetric key.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoSymKeyGenerator](capi-cryptosymkeyapi-oh-cryptosymkeygenerator.md) *ctx | Pointer to the symmetric key generator instance.|
| [OH_CryptoSymKey](capi-cryptosymkeyapi-oh-cryptosymkey.md) **keyCtx | Pointer to the symmetric key created.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | **CRYPTO_SUCCESS**: The operation is successful.<br>         **CRYPTO_INVALID_PARAMS**: A parameter is invalid.<br>         **CRYPTO_NOT_SUPPORTED**: The operation is not supported.<br>         **CRYPTO_MEMORY_ERROR**: A memory error occurs.<br>         **CRYPTO_OPERTION_ERROR**: Failed to call an API of a third-party algorithm library.|

### OH_CryptoSymKeyGenerator_Convert()

```
OH_Crypto_ErrCode OH_CryptoSymKeyGenerator_Convert(OH_CryptoSymKeyGenerator *ctx,const Crypto_DataBlob *keyData, OH_CryptoSymKey **keyCtx)
```

**Description**

Converts binary data into a symmetric key.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoSymKeyGenerator](capi-cryptosymkeyapi-oh-cryptosymkeygenerator.md) *ctx | Pointer to the symmetric key generator instance.|
| [const Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *keyData | Pointer to the data to convert.|
| [OH_CryptoSymKey](capi-cryptosymkeyapi-oh-cryptosymkey.md) **keyCtx | Pointer to the symmetric key obtained.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | **CRYPTO_SUCCESS**: The operation is successful.<br>         **CRYPTO_INVALID_PARAMS**: A parameter is invalid.<br>         **CRYPTO_NOT_SUPPORTED**: The operation is not supported.<br>         **CRYPTO_MEMORY_ERROR**: A memory error occurs.<br>         **CRYPTO_OPERTION_ERROR**: Failed to call an API of a third-party algorithm library.|

### OH_CryptoSymKeyGenerator_GetAlgoName()

```
const char *OH_CryptoSymKeyGenerator_GetAlgoName(OH_CryptoSymKeyGenerator *ctx)
```

**Description**

Obtains the algorithm of a symmetric key generator instance.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoSymKeyGenerator](capi-cryptosymkeyapi-oh-cryptosymkeygenerator.md) *ctx | Double pointer to the symmetric key generator instance created.|

**Returns**

| Type| Description|
| -- | -- |
| const char * | Algorithm of a symmetric key generator instance.|

### OH_CryptoSymKeyGenerator_Destroy()

```
void OH_CryptoSymKeyGenerator_Destroy(OH_CryptoSymKeyGenerator *ctx)
```

**Description**

Destroys a symmetric key generator instance.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoSymKeyGenerator](capi-cryptosymkeyapi-oh-cryptosymkeygenerator.md) *ctx | Double pointer to the symmetric key generator instance created.|

### OH_CryptoSymKey_GetAlgoName()

```
const char *OH_CryptoSymKey_GetAlgoName(OH_CryptoSymKey *keyCtx)
```

**Description**

Obtains the algorithm of a symmetric key.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoSymKey](capi-cryptosymkeyapi-oh-cryptosymkey.md) *keyCtx | Pointer to the symmetric key instance.|

**Returns**

| Type| Description|
| -- | -- |
| const char * | Symmetric key algorithm obtained.|

### OH_CryptoSymKey_GetKeyData()

```
OH_Crypto_ErrCode OH_CryptoSymKey_GetKeyData(OH_CryptoSymKey *keyCtx, Crypto_DataBlob *out)
```

**Description**

Obtains symmetric key data from a key instance.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoSymKey](capi-cryptosymkeyapi-oh-cryptosymkey.md) *keyCtx | Pointer to the symmetric key instance.|
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *out | Pointer to the data obtained.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | **CRYPTO_SUCCESS**: The operation is successful.<br>         **CRYPTO_INVALID_PARAMS**: A parameter is invalid.<br>         **CRYPTO_NOT_SUPPORTED**: The operation is not supported.<br>         **CRYPTO_MEMORY_ERROR**: A memory error occurs.<br>         **CRYPTO_OPERTION_ERROR**: Failed to call an API of a third-party algorithm library.|

### OH_CryptoSymKey_Destroy()

```
void OH_CryptoSymKey_Destroy(OH_CryptoSymKey *keyCtx)
```

**Description**

Destroys a symmetric key instance.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoSymKey](capi-cryptosymkeyapi-oh-cryptosymkey.md) *keyCtx | Pointer to the symmetric key instance.|
