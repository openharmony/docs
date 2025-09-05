# crypto_mac.h

<!--Kit: Crypto Architecture Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--Designer: @lanming-->
<!--Tester: @PAFT-->
<!--Adviser: @zengyawen-->

## Overview

Define message authentication code (MAC) APIs.

**Header file**: <CryptoArchitectureKit/crypto_mac.h>

**Library**: libohcrypto.so

**System capability**: SystemCapability.Security.CryptoFramework

**Since**: 20

**Related Module**: [CryptoMacApi](capi-cryptomacapi.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_CryptoMac](capi-cryptomacapi-oh-cryptomac.md) | OH_CryptoMac | Defines a struct for a MAC.|

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [CryptoMac_ParamType](#cryptomac_paramtype) | CryptoMac_ParamType | Defines the parameter type for the MAC algorithm.|

### Functions

| Name| Description|
| -- | -- |
| [OH_Crypto_ErrCode OH_CryptoMac_Create(const char *algoName, OH_CryptoMac **ctx)](#oh_cryptomac_create) | Creates a MAC instance based on the given algorithm name.|
| [OH_Crypto_ErrCode OH_CryptoMac_SetParam(OH_CryptoMac *ctx, CryptoMac_ParamType type, const Crypto_DataBlob *value)](#oh_cryptomac_setparam) | Sets MAC parameters.|
| [OH_Crypto_ErrCode OH_CryptoMac_Init(OH_CryptoMac *ctx, const OH_CryptoSymKey *key)](#oh_cryptomac_init) | Initializes a MAC instance using a symmetric key.|
| [OH_Crypto_ErrCode OH_CryptoMac_Update(OH_CryptoMac *ctx, const Crypto_DataBlob *in)](#oh_cryptomac_update) | Updates a MAC instance.|
| [OH_Crypto_ErrCode OH_CryptoMac_Final(OH_CryptoMac *ctx, Crypto_DataBlob *out)](#oh_cryptomac_final) | Finalizes a MAC operation.|
| [OH_Crypto_ErrCode OH_CryptoMac_GetLength(OH_CryptoMac *ctx, uint32_t *length)](#oh_cryptomac_getlength) | Obtains the MAC length.|
| [void OH_CryptoMac_Destroy(OH_CryptoMac *ctx)](#oh_cryptomac_destroy) | Destroys a MAC instance.|

## Enum Description

### CryptoMac_ParamType

```
enum CryptoMac_ParamType
```

**Description**

Defines the parameter type for the MAC algorithm.

**Since**: 20

| Enum Item| Description|
| -- | -- |
| CRYPTO_MAC_DIGEST_NAME_STR = 0 | Algorithm name of the digest function used by the HMAC, for example, **SHA256**.|
| CRYPTO_MAC_CIPHER_NAME_STR = 1 | Name of the symmetric encryption algorithm used by the CMAC, for example, **AES256.**|


## Function Description

### OH_CryptoMac_Create()

```
OH_Crypto_ErrCode OH_CryptoMac_Create(const char *algoName, OH_CryptoMac **ctx)
```

**Description**

Creates a MAC instance based on the given algorithm name.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| const char *algoName | Pointer to the algorithm used to generate the MAC instance.<br> For example, **HMAC** or **CMAC**.|
| [OH_CryptoMac](capi-cryptomacapi-oh-cryptomac.md) **ctx | MAC instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | **CRYPTO_SUCCESS**: The operation is successful.<br>         **CRYPTO_NOT_SUPPORTED**: The operation is not supported.<br>         **CRYPTO_MEMORY_ERROR**: A memory error occurs.<br>         **CRYPTO_PARAMETER_CHECK_FAILED**: The parameter check failed.<br>         **CRYPTO_OPERATION_ERROR**: An error occurs when the API of a third-party algorithm library is called.|

### OH_CryptoMac_SetParam()

```
OH_Crypto_ErrCode OH_CryptoMac_SetParam(OH_CryptoMac *ctx, CryptoMac_ParamType type, const Crypto_DataBlob *value)
```

**Description**

Sets MAC parameters.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoMac](capi-cryptomacapi-oh-cryptomac.md) *ctx | MAC instance.|
| [CryptoMac_ParamType](#cryptomac_paramtype) type | MAC parameter type.|
| [const Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *value | MAC parameters.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | **CRYPTO_SUCCESS**: The operation is successful.<br>         **CRYPTO_NOT_SUPPORTED**: The operation is not supported.<br>         **CRYPTO_MEMORY_ERROR**: A memory error occurs.<br>         **CRYPTO_PARAMETER_CHECK_FAILED**: The parameter check failed.<br>         **CRYPTO_OPERATION_ERROR**: An error occurs when the API of a third-party algorithm library is called.|

### OH_CryptoMac_Init()

```
OH_Crypto_ErrCode OH_CryptoMac_Init(OH_CryptoMac *ctx, const OH_CryptoSymKey *key)
```

**Description**

Initializes a MAC instance using a symmetric key.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoMac](capi-cryptomacapi-oh-cryptomac.md) *ctx | MAC instance.|
| [const OH_CryptoSymKey](capi-cryptosymkeyapi-oh-cryptosymkey.md) *key | Symmetric key obtained.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | **CRYPTO_SUCCESS**: The operation is successful.<br>         **CRYPTO_NOT_SUPPORTED**: The operation is not supported.<br>         **CRYPTO_MEMORY_ERROR**: A memory error occurs.<br>         **CRYPTO_PARAMETER_CHECK_FAILED**: The parameter check failed.<br>         **CRYPTO_OPERATION_ERROR**: An error occurs when the API of a third-party algorithm library is called.|

**Reference**

[OH_CryptoMac_Update](#oh_cryptomac_update)

[OH_CryptoMac_Final](#oh_cryptomac_final)


### OH_CryptoMac_Update()

```
OH_Crypto_ErrCode OH_CryptoMac_Update(OH_CryptoMac *ctx, const Crypto_DataBlob *in)
```

**Description**

Updates a MAC instance.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoMac](capi-cryptomacapi-oh-cryptomac.md) *ctx | MAC instance.|
| [const Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *in | Data to be updated.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | **CRYPTO_SUCCESS**: The operation is successful.<br>         **CRYPTO_NOT_SUPPORTED**: The operation is not supported.<br>         **CRYPTO_MEMORY_ERROR**: A memory error occurs.<br>         **CRYPTO_PARAMETER_CHECK_FAILED**: The parameter check failed.<br>         **CRYPTO_OPERATION_ERROR**: An error occurs when the API of a third-party algorithm library is called.|

**Reference**

[OH_CryptoMac_Init](#oh_cryptomac_init)

[OH_CryptoMac_Final](#oh_cryptomac_final)


### OH_CryptoMac_Final()

```
OH_Crypto_ErrCode OH_CryptoMac_Final(OH_CryptoMac *ctx, Crypto_DataBlob *out)
```

**Description**

Finalizes a MAC operation.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoMac](capi-cryptomacapi-oh-cryptomac.md) *ctx | MAC instance.|
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *out | MAC value.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | **CRYPTO_SUCCESS**: The operation is successful.<br>         **CRYPTO_NOT_SUPPORTED**: The operation is not supported.<br>         **CRYPTO_MEMORY_ERROR**: A memory error occurs.<br>         **CRYPTO_PARAMETER_CHECK_FAILED**: The parameter check failed.<br>         **CRYPTO_OPERATION_ERROR**: An error occurs when the API of a third-party algorithm library is called.|

**Reference**

[OH_CryptoMac_Init](#oh_cryptomac_init)

[OH_CryptoMac_Update](#oh_cryptomac_update)


### OH_CryptoMac_GetLength()

```
OH_Crypto_ErrCode OH_CryptoMac_GetLength(OH_CryptoMac *ctx, uint32_t *length)
```

**Description**

Obtains the MAC length.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoMac](capi-cryptomacapi-oh-cryptomac.md) *ctx | MAC instance.|
| uint32_t *length | MAC length.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | **CRYPTO_SUCCESS**: The operation is successful.<br>         **CRYPTO_NOT_SUPPORTED**: The operation is not supported.<br>         **CRYPTO_MEMORY_ERROR**: A memory error occurs.<br>         **CRYPTO_PARAMETER_CHECK_FAILED**: The parameter check failed.<br>         **CRYPTO_OPERATION_ERROR**: An error occurs when the API of a third-party algorithm library is called.|

### OH_CryptoMac_Destroy()

```
void OH_CryptoMac_Destroy(OH_CryptoMac *ctx)
```

**Description**

Destroys a MAC instance.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoMac](capi-cryptomacapi-oh-cryptomac.md) *ctx | MAC instance.|
