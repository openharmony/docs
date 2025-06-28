# crypto_signature.h

## Overview

Defines APIs for signature verification.

**Library**: libohcrypto.so

**Header file**: <CryptoArchitectureKit/crypto_signature.h>

**System capability**: SystemCapability.Security.CryptoFramework

**Since**: 12

**Related module**: [CryptoSignatureApi](capi-cryptosignatureapi.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_CryptoVerify](capi-oh-cryptoverify.md) | OH_CryptoVerify | Defines the data used for signature verification.|

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [CryptoSignature_ParamType](#cryptosignature_paramtype) | CryptoSignature_ParamType | Enumerates the types of signature verification parameters.|

### Functions

| Name| Description|
| -- | -- |
| [OH_Crypto_ErrCode OH_CryptoVerify_Create(const char *algoName, OH_CryptoVerify **verify)](#oh_cryptoverify_create) | Creates a **Verify** instance for signature verification.|
| [OH_Crypto_ErrCode OH_CryptoVerify_Init(OH_CryptoVerify *ctx, OH_CryptoPubKey *pubKey)](#oh_cryptoverify_init) | Initializes a **Verify** instance by using the public key.|
| [OH_Crypto_ErrCode OH_CryptoVerify_Update(OH_CryptoVerify *ctx, Crypto_DataBlob *in)](#oh_cryptoverify_update) | Updates the data to be verified.|
| [bool OH_CryptoVerify_Final(OH_CryptoVerify *ctx, Crypto_DataBlob *in, Crypto_DataBlob *signData)](#oh_cryptoverify_final) | Verifies the signature of the data.|
| [OH_Crypto_ErrCode OH_CryptoVerify_Recover(OH_CryptoVerify *ctx, Crypto_DataBlob *signData,Crypto_DataBlob *rawSignData)](#oh_cryptoverify_recover) | Restores the raw signature data.|
| [const char *OH_CryptoVerify_GetAlgoName(OH_CryptoVerify *ctx)](#oh_cryptoverify_getalgoname) | Obtains the signature verification algorithm.|
| [OH_Crypto_ErrCode OH_CryptoVerify_SetParam(OH_CryptoVerify *ctx, CryptoSignature_ParamType type,Crypto_DataBlob *value)](#oh_cryptoverify_setparam) | Sets a signature verification parameter.|
| [OH_Crypto_ErrCode OH_CryptoVerify_GetParam(OH_CryptoVerify *ctx, CryptoSignature_ParamType type,Crypto_DataBlob *value)](#oh_cryptoverify_getparam) | Obtains a signature verification parameter.|
| [void OH_CryptoVerify_Destroy(OH_CryptoVerify *ctx)](#oh_cryptoverify_destroy) | Destroys a **Verify** instance.|

## Enum Description

### CryptoSignature_ParamType

```
enum CryptoSignature_ParamType
```

Description

Enumerates the types of signature verification parameters.

**Since**: 12

| Enum Item| Description|
| -- | -- |
| CRYPTO_PSS_MD_NAME_STR = 100 | MD algorithm used with the PSS padding mode in RSA.|
| CRYPTO_PSS_MGF_NAME_STR = 101 | Mask generation algorithm used with the PSS padding mode in RSA. Currently, only MGF1 is supported.|
| CRYPTO_PSS_MGF1_NAME_STR = 102 | MD parameters for the MGF1 mask generation used with the PSS padding mode in RSA.|
| CRYPTO_PSS_SALT_LEN_INT = 103 | Length of the salt in bytes used with the PSS padding mode in RSA.|
| CRYPTO_PSS_TRAILER_FIELD_INT = 104 | Trailer field used in the encoding operation when PSS padding mode is used in RSA. The value is **1**.|
| CRYPTO_SM2_USER_ID_DATABLOB = 105 | User ID field in SM2.|


## Function Description

### OH_CryptoVerify_Create()

```
OH_Crypto_ErrCode OH_CryptoVerify_Create(const char *algoName, OH_CryptoVerify **verify)
```

Description

Creates a **Verify** instance for signature verification.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const char *algoName | Pointer to the algorithm used to generate the **Verify** instance.<br>For example, **RSA1024\PKCS1\SHA256**.| | |
| [OH_CryptoVerify](capi-oh-cryptoverify.md) **verify | Pointer to the **Verify** instance created.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) |  CRYPTO_SUCCESS = 0: Operation succeeded.<br>         CRYPTO_INVALID_PARAMS = 401: invalid parameters.<br>         CRYPTO_NOT_SUPPORTED = 801: The operation is not supported.<br>         CRYPTO_MEMORY_ERROR = 17620001: memory error.<br>         CRYPTO_OPERTION_ERROR = 17630001: Failed to call an API of a third-party algorithm library.|

### OH_CryptoVerify_Init()

```
OH_Crypto_ErrCode OH_CryptoVerify_Init(OH_CryptoVerify *ctx, OH_CryptoPubKey *pubKey)
```

Description

Initializes a **Verify** instance by using the public key.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoVerify](capi-oh-cryptoverify.md) *ctx | Pointer to the **Verify** instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) |  CRYPTO_SUCCESS = 0: Operation succeeded.<br>         CRYPTO_INVALID_PARAMS = 401: invalid parameters.<br>         CRYPTO_NOT_SUPPORTED = 801: The operation is not supported.<br>         CRYPTO_MEMORY_ERROR = 17620001: memory error.<br>         CRYPTO_OPERTION_ERROR = 17630001: Failed to call an API of a third-party algorithm library.|

**See also**

[OH_CryptoVerify_Final](#oh_cryptoverify_final)

### OH_CryptoVerify_Update()

```
OH_Crypto_ErrCode OH_CryptoVerify_Update(OH_CryptoVerify *ctx, Crypto_DataBlob *in)
```

Description

Updates the data to be verified.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoVerify](capi-oh-cryptoverify.md) *ctx | Pointer to the **Verify** instance.|
| [Crypto_DataBlob](capi-crypto-datablob.md) *in | Pointer to the data to pass in.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) |  CRYPTO_SUCCESS = 0: Operation succeeded.<br>         CRYPTO_INVALID_PARAMS = 401: invalid parameters.<br>         CRYPTO_NOT_SUPPORTED = 801: The operation is not supported.<br>         CRYPTO_MEMORY_ERROR = 17620001: memory error.<br>         CRYPTO_OPERTION_ERROR = 17630001: Failed to call an API of a third-party algorithm library.|

**See also**

[OH_CryptoVerify_Final](#oh_cryptoverify_final)

### OH_CryptoVerify_Final()

```
bool OH_CryptoVerify_Final(OH_CryptoVerify *ctx, Crypto_DataBlob *in, Crypto_DataBlob *signData)
```

Description

Verifies the signature of the data.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoVerify](capi-oh-cryptoverify.md) *ctx | Pointer to the **Verify** instance.|
| [Crypto_DataBlob](capi-crypto-datablob.md) *in | Pointer to the data passed in.|
| [Crypto_DataBlob](capi-crypto-datablob.md) *signData | Signature data.|

**Returns**

| Type| Description|
| -- | -- |
| bool | Whether the signature verification is successful.|

**See also**

[OH_CryptoVerify_Update](#oh_cryptoverify_update)

### OH_CryptoVerify_Recover()

```
OH_Crypto_ErrCode OH_CryptoVerify_Recover(OH_CryptoVerify *ctx, Crypto_DataBlob *signData,Crypto_DataBlob *rawSignData)
```

Description

Restores the raw signature data.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoVerify](capi-oh-cryptoverify.md) *ctx | Pointer to the **Verify** instance.|
| [Crypto_DataBlob](capi-crypto-datablob.md) *signData | Signature data.|
| [Crypto_DataBlob](capi-crypto-datablob.md) *rawSignData |  Data restored.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) |  CRYPTO_SUCCESS = 0: Operation succeeded.<br>         CRYPTO_INVALID_PARAMS = 401: invalid parameters.<br>         CRYPTO_NOT_SUPPORTED = 801: The operation is not supported.<br>         CRYPTO_MEMORY_ERROR = 17620001: memory error.<br>         CRYPTO_OPERTION_ERROR = 17630001: Failed to call an API of a third-party algorithm library.|

### OH_CryptoVerify_GetAlgoName()

```
const char *OH_CryptoVerify_GetAlgoName(OH_CryptoVerify *ctx)
```

Description

Obtains the signature verification algorithm.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoVerify](capi-oh-cryptoverify.md) *ctx | Pointer to the **Verify** instance.|

**Returns**

| Type| Description|
| -- | -- |
| const char | Signature verification algorithm obtained.|

### OH_CryptoVerify_SetParam()

```
OH_Crypto_ErrCode OH_CryptoVerify_SetParam(OH_CryptoVerify *ctx, CryptoSignature_ParamType type,Crypto_DataBlob *value)
```

Description

Sets a signature verification parameter.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoVerify](capi-oh-cryptoverify.md) *ctx | Pointer to the **Verify** instance.|
| [CryptoSignature_ParamType](#cryptosignature_paramtype) type | Signature verification parameter to set.|
| [Crypto_DataBlob](capi-crypto-datablob.md) *value | Value of the signature verification parameter to set.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) |  CRYPTO_SUCCESS = 0: Operation succeeded.<br>         CRYPTO_INVALID_PARAMS = 401: invalid parameters.<br>         CRYPTO_NOT_SUPPORTED = 801: The operation is not supported.<br>         CRYPTO_MEMORY_ERROR = 17620001: memory error.<br>         CRYPTO_OPERTION_ERROR = 17630001: Failed to call an API of a third-party algorithm library.|

### OH_CryptoVerify_GetParam()

```
OH_Crypto_ErrCode OH_CryptoVerify_GetParam(OH_CryptoVerify *ctx, CryptoSignature_ParamType type,Crypto_DataBlob *value)
```

Description

Obtains a signature verification parameter.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoVerify](capi-oh-cryptoverify.md) *ctx | Pointer to the **Verify** instance.|
| [CryptoSignature_ParamType](#cryptosignature_paramtype) type | Signature verification parameter to obtain.|
| [Crypto_DataBlob](capi-crypto-datablob.md) *value | Returns the value of the parameter obtained.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) |  CRYPTO_SUCCESS = 0: Operation succeeded.<br>         CRYPTO_INVALID_PARAMS = 401: invalid parameters.<br>         CRYPTO_NOT_SUPPORTED = 801: The operation is not supported.<br>         CRYPTO_MEMORY_ERROR = 17620001: memory error.<br>         CRYPTO_OPERTION_ERROR = 17630001: Failed to call an API of a third-party algorithm library.|

### OH_CryptoVerify_Destroy()

```
void OH_CryptoVerify_Destroy(OH_CryptoVerify *ctx)
```

Description

Destroys a **Verify** instance.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoVerify](capi-oh-cryptoverify.md) *ctx | Pointer to the **Verify** instance.|
