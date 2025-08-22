# crypto_asym_cipher.h

<!--Kit: Crypto Architecture Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--Designer: @lanming-->
<!--Tester: @PAFT-->
<!--Adviser: @zengyawen-->

## Overview

Defines APIs for encrypting and decrypting asymmetric keys.

**Header file**: <CryptoArchitectureKit/crypto_asym_cipher.h>

**Library**: libohcrypto.so

**System capability**: SystemCapability.Security.CryptoFramework

**Since**: 20

**Related Module**: [CryptoAsymCipherApi](capi-cryptoasymcipherapi.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_CryptoAsymCipher](capi-cryptoasymcipherapi-oh-cryptoasymcipher.md) | OH_CryptoAsymCipher | Defines a struct for asymmetric encryption.|
| [OH_CryptoSm2CiphertextSpec](capi-cryptoasymcipherapi-oh-cryptosm2ciphertextspec.md) | OH_CryptoSm2CiphertextSpec | Defines a struct for SM2 ciphertext specifications.|

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [CryptoSm2CiphertextSpec_item](#cryptosm2ciphertextspec_item) | CryptoSm2CiphertextSpec_item | Defines the type of SM2 ciphertext specification items.|

### Functions

| Name| Description|
| -- | -- |
| [OH_Crypto_ErrCode OH_CryptoAsymCipher_Create(const char *algoName, OH_CryptoAsymCipher **ctx)](#oh_cryptoasymcipher_create) | Creates an asymmetric encryption instance based on the given algorithm name.|
| [OH_Crypto_ErrCode OH_CryptoAsymCipher_Init(OH_CryptoAsymCipher *ctx, Crypto_CipherMode mode, OH_CryptoKeyPair *key)](#oh_cryptoasymcipher_init) | Initializes asymmetric encryption.|
| [OH_Crypto_ErrCode OH_CryptoAsymCipher_Final(OH_CryptoAsymCipher *ctx, const Crypto_DataBlob *in,Crypto_DataBlob *out)](#oh_cryptoasymcipher_final) | Finalizes asymmetric encryption.|
| [void OH_CryptoAsymCipher_Destroy(OH_CryptoAsymCipher *ctx)](#oh_cryptoasymcipher_destroy) | Destroys an asymmetric encryption context.|
| [OH_Crypto_ErrCode OH_CryptoSm2CiphertextSpec_Create(Crypto_DataBlob *sm2Ciphertext, OH_CryptoSm2CiphertextSpec **spec)](#oh_cryptosm2ciphertextspec_create) | Creates SM2 ciphertext specifications.|
| [OH_Crypto_ErrCode OH_CryptoSm2CiphertextSpec_GetItem(OH_CryptoSm2CiphertextSpec *spec,CryptoSm2CiphertextSpec_item item, Crypto_DataBlob *out)](#oh_cryptosm2ciphertextspec_getitem) | Obtains a specified item in SM2 ciphertext specifications.|
| [OH_Crypto_ErrCode OH_CryptoSm2CiphertextSpec_SetItem(OH_CryptoSm2CiphertextSpec *spec,CryptoSm2CiphertextSpec_item item, Crypto_DataBlob *in)](#oh_cryptosm2ciphertextspec_setitem) | Sets a specified item in SM2 ciphertext specifications.|
| [OH_Crypto_ErrCode OH_CryptoSm2CiphertextSpec_Encode(OH_CryptoSm2CiphertextSpec *spec, Crypto_DataBlob *out)](#oh_cryptosm2ciphertextspec_encode) | Encodes SM2 ciphertext specifications into DER ciphertext.|
| [void OH_CryptoSm2CiphertextSpec_Destroy(OH_CryptoSm2CiphertextSpec *spec)](#oh_cryptosm2ciphertextspec_destroy) | Destroys SM2 ciphertext specifications.|

## Enum Description

### CryptoSm2CiphertextSpec_item

```
enum CryptoSm2CiphertextSpec_item
```

**Description**

Defines the type of SM2 ciphertext specification items.

**Since**: 20

| Enum Item| Description|
| -- | -- |
| CRYPTO_SM2_CIPHERTEXT_C1_X = 0 | Public key x, also called C1x.|
| CRYPTO_SM2_CIPHERTEXT_C1_Y = 1 | Public key y, also called C1y.|
| CRYPTO_SM2_CIPHERTEXT_C2 = 2 | Hash value, also called C2.|
| CRYPTO_SM2_CIPHERTEXT_C3 = 3 | Ciphertext data, also called C3.|


## Function Description

### OH_CryptoAsymCipher_Create()

```
OH_Crypto_ErrCode OH_CryptoAsymCipher_Create(const char *algoName, OH_CryptoAsymCipher **ctx)
```

**Description**

Creates an asymmetric encryption instance based on the given algorithm name.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| const char *algoName | Pointer to the algorithm used to generate an encryption instance.<br>For example, **'RSA\|PKCS1_OAEP\|SHA384\|MGF1_SHA384'**, **'SM2\|SM3'**| | | | |
| [OH_CryptoAsymCipher](capi-cryptoasymcipherapi-oh-cryptoasymcipher.md) **ctx | Pointer to the asymmetric encryption context.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | **CRYPTO_SUCCESS**: The operation is successful.<br>         **CRYPTO_NOT_SUPPORTED**: The operation is not supported.<br>         **CRYPTO_MEMORY_ERROR**: A memory error occurs.<br>         **CRYPTO_PARAMETER_CHECK_FAILED**: The parameter check failed.<br>         **CRYPTO_OPERTION_ERROR**: Failed to call an API of a third-party algorithm library.|

### OH_CryptoAsymCipher_Init()

```
OH_Crypto_ErrCode OH_CryptoAsymCipher_Init(OH_CryptoAsymCipher *ctx, Crypto_CipherMode mode, OH_CryptoKeyPair *key)
```

**Description**

Initializes asymmetric encryption.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoAsymCipher](capi-cryptoasymcipherapi-oh-cryptoasymcipher.md) *ctx | Pointer to the asymmetric encryption context.|
| [Crypto_CipherMode](capi-crypto-common-h.md#crypto_ciphermode) mode | Cipher mode (encryption or decryption).|
| [OH_CryptoKeyPair](capi-cryptoasymkeyapi-oh-cryptokeypair.md) *key | Pointer to the asymmetric key.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | **CRYPTO_SUCCESS**: The operation is successful.<br>         **CRYPTO_NOT_SUPPORTED**: The operation is not supported.<br>         **CRYPTO_MEMORY_ERROR**: A memory error occurs.<br>         **CRYPTO_PARAMETER_CHECK_FAILED**: The parameter check failed.<br>         **CRYPTO_OPERTION_ERROR**: Failed to call an API of a third-party algorithm library.|

**Reference**

[OH_CryptoAsymCipher_Final](#oh_cryptoasymcipher_final)


### OH_CryptoAsymCipher_Final()

```
OH_Crypto_ErrCode OH_CryptoAsymCipher_Final(OH_CryptoAsymCipher *ctx, const Crypto_DataBlob *in,Crypto_DataBlob *out)
```

**Description**

Finalizes asymmetric encryption.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoAsymCipher](capi-cryptoasymcipherapi-oh-cryptoasymcipher.md) *ctx | Pointer to the asymmetric encryption context.|
| [const Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *in | Pointer to the data to be encrypted or decrypted.|
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *out | Pointer to the encrypted or decrypted data.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | **CRYPTO_SUCCESS**: The operation is successful.<br>         **CRYPTO_NOT_SUPPORTED**: The operation is not supported.<br>         **CRYPTO_MEMORY_ERROR**: A memory error occurs.<br>         **CRYPTO_PARAMETER_CHECK_FAILED**: The parameter check failed.<br>         **CRYPTO_OPERTION_ERROR**: Failed to call an API of a third-party algorithm library.|

**Reference**

[OH_CryptoAsymCipher_Init](#oh_cryptoasymcipher_init)


### OH_CryptoAsymCipher_Destroy()

```
void OH_CryptoAsymCipher_Destroy(OH_CryptoAsymCipher *ctx)
```

**Description**

Destroys an asymmetric encryption context.

**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoAsymCipher](capi-cryptoasymcipherapi-oh-cryptoasymcipher.md) *ctx | Pointer to the asymmetric encryption context.|

### OH_CryptoSm2CiphertextSpec_Create()

```
OH_Crypto_ErrCode OH_CryptoSm2CiphertextSpec_Create(Crypto_DataBlob *sm2Ciphertext, OH_CryptoSm2CiphertextSpec **spec)
```

**Description**

Creates SM2 ciphertext specifications.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *sm2Ciphertext | Pointer to the SM2 ciphertext in DER format. If the value is **NULL**, an empty SM2 ciphertext specification is created.|
| [OH_CryptoSm2CiphertextSpec](capi-cryptoasymcipherapi-oh-cryptosm2ciphertextspec.md) **spec | Pointer to the output SM2 ciphertext specifications.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | **CRYPTO_SUCCESS**: The operation is successful.<br>         **CRYPTO_NOT_SUPPORTED**: The operation is not supported.<br>         **CRYPTO_MEMORY_ERROR**: A memory error occurs.<br>         **CRYPTO_PARAMETER_CHECK_FAILED**: The parameter check failed.<br>         **CRYPTO_OPERTION_ERROR**: Failed to call an API of a third-party algorithm library.|

### OH_CryptoSm2CiphertextSpec_GetItem()

```
OH_Crypto_ErrCode OH_CryptoSm2CiphertextSpec_GetItem(OH_CryptoSm2CiphertextSpec *spec,CryptoSm2CiphertextSpec_item item, Crypto_DataBlob *out)
```

**Description**

Obtains a specified item in SM2 ciphertext specifications.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoSm2CiphertextSpec](capi-cryptoasymcipherapi-oh-cryptosm2ciphertextspec.md) *spec | Pointer to the SM2 ciphertext specifications.|
| [CryptoSm2CiphertextSpec_item](#cryptosm2ciphertextspec_item) item | SM2 ciphertext specification item.|
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *out | Pointer to the output data.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | **CRYPTO_SUCCESS**: The operation is successful.<br>         **CRYPTO_NOT_SUPPORTED**: The operation is not supported.<br>         **CRYPTO_MEMORY_ERROR**: A memory error occurs.<br>         **CRYPTO_PARAMETER_CHECK_FAILED**: The parameter check failed.<br>         **CRYPTO_OPERTION_ERROR**: Failed to call an API of a third-party algorithm library.|

### OH_CryptoSm2CiphertextSpec_SetItem()

```
OH_Crypto_ErrCode OH_CryptoSm2CiphertextSpec_SetItem(OH_CryptoSm2CiphertextSpec *spec,CryptoSm2CiphertextSpec_item item, Crypto_DataBlob *in)
```

**Description**

Sets a specified item in SM2 ciphertext specifications.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoSm2CiphertextSpec](capi-cryptoasymcipherapi-oh-cryptosm2ciphertextspec.md) *spec | Pointer to the SM2 ciphertext specifications.|
| [CryptoSm2CiphertextSpec_item](#cryptosm2ciphertextspec_item) item | SM2 ciphertext specification item.|
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *in | Pointer to the input data.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | **CRYPTO_SUCCESS**: The operation is successful.<br>         **CRYPTO_NOT_SUPPORTED**: The operation is not supported.<br>         **CRYPTO_MEMORY_ERROR**: A memory error occurs.<br>         **CRYPTO_PARAMETER_CHECK_FAILED**: The parameter check failed.<br>         **CRYPTO_OPERTION_ERROR**: Failed to call an API of a third-party algorithm library.|

### OH_CryptoSm2CiphertextSpec_Encode()

```
OH_Crypto_ErrCode OH_CryptoSm2CiphertextSpec_Encode(OH_CryptoSm2CiphertextSpec *spec, Crypto_DataBlob *out)
```

**Description**

Encodes SM2 ciphertext specifications into DER ciphertext.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoSm2CiphertextSpec](capi-cryptoasymcipherapi-oh-cryptosm2ciphertextspec.md) *spec | Pointer to the SM2 ciphertext specifications.|
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *out | Pointer to the output data.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | **CRYPTO_SUCCESS**: The operation is successful.<br>         **CRYPTO_NOT_SUPPORTED**: The operation is not supported.<br>         **CRYPTO_MEMORY_ERROR**: A memory error occurs.<br>         **CRYPTO_PARAMETER_CHECK_FAILED**: The parameter check failed.<br>         **CRYPTO_OPERTION_ERROR**: Failed to call an API of a third-party algorithm library.|

### OH_CryptoSm2CiphertextSpec_Destroy()

```
void OH_CryptoSm2CiphertextSpec_Destroy(OH_CryptoSm2CiphertextSpec *spec)
```

**Description**

Destroys SM2 ciphertext specifications.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoSm2CiphertextSpec](capi-cryptoasymcipherapi-oh-cryptosm2ciphertextspec.md) *spec | Pointer to the SM2 ciphertext specifications.|
