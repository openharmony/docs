# crypto_signature.h

<!--Kit: Crypto Architecture Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--Designer: @lanming-->
<!--Tester: @PAFT-->
<!--Adviser: @zengyawen-->

## Overview

Defines APIs for signature verification.

**Header file**: <CryptoArchitectureKit/crypto_signature.h>

**Library**: libohcrypto.so

**System capability**: SystemCapability.Security.CryptoFramework

**Since**: 12

**Related module**: [CryptoSignatureApi](capi-cryptosignatureapi.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_CryptoVerify](capi-cryptosignatureapi-oh-cryptoverify.md) | OH_CryptoVerify | Defines the data used for signature verification.|
| [OH_CryptoSign](capi-cryptosignatureapi-oh-cryptosign.md) | OH_CryptoSign | Defines a struct for signing.|
| [OH_CryptoEccSignatureSpec](capi-cryptosignatureapi-oh-cryptoeccsignaturespec.md) | OH_CryptoEccSignatureSpec | Defines a struct for ECC signing specifications.|

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
| [OH_Crypto_ErrCode OH_CryptoSign_Create(const char *algoName, OH_CryptoSign **sign)](#oh_cryptosign_create) | Creates a signature instance based on the given algorithm name.|
| [OH_Crypto_ErrCode OH_CryptoSign_Init(OH_CryptoSign *ctx, OH_CryptoPrivKey *privKey)](#oh_cryptosign_init) | Initializes a signature instance.|
| [OH_Crypto_ErrCode OH_CryptoSign_Update(OH_CryptoSign *ctx, const Crypto_DataBlob *in)](#oh_cryptosign_update) | Updates the data to be signed.|
| [OH_Crypto_ErrCode OH_CryptoSign_Final(OH_CryptoSign *ctx, const Crypto_DataBlob *in, Crypto_DataBlob *out)](#oh_cryptosign_final) | Finalizes the signing operation.|
| [const char *OH_CryptoSign_GetAlgoName(OH_CryptoSign *ctx)](#oh_cryptosign_getalgoname) | Obtains the algorithm name of a signature instance.|
| [OH_Crypto_ErrCode OH_CryptoSign_SetParam(OH_CryptoSign *ctx, CryptoSignature_ParamType type,const Crypto_DataBlob *value)](#oh_cryptosign_setparam) | Sets parameters for a signature instance.|
| [OH_Crypto_ErrCode OH_CryptoSign_GetParam(OH_CryptoSign *ctx, CryptoSignature_ParamType type, Crypto_DataBlob *value)](#oh_cryptosign_getparam) | Obtains the specified parameter from a signature instance.|
| [void OH_CryptoSign_Destroy(OH_CryptoSign *ctx)](#oh_cryptosign_destroy) | Destroys a signature instance.|
| [OH_Crypto_ErrCode OH_CryptoEccSignatureSpec_Create(Crypto_DataBlob *eccSignature,OH_CryptoEccSignatureSpec **spec)](#oh_cryptoeccsignaturespec_create) | Creates ECC signing specifications.|
| [OH_Crypto_ErrCode OH_CryptoEccSignatureSpec_GetRAndS(OH_CryptoEccSignatureSpec *spec, Crypto_DataBlob *r,Crypto_DataBlob *s)](#oh_cryptoeccsignaturespec_getrands) | Obtains the **r** and **s** values of an ECC signature.|
| [OH_Crypto_ErrCode OH_CryptoEccSignatureSpec_SetRAndS(OH_CryptoEccSignatureSpec *spec, Crypto_DataBlob *r,Crypto_DataBlob *s)](#oh_cryptoeccsignaturespec_setrands) | Sets the **r** and **s** values of an ECC signature.|
| [OH_Crypto_ErrCode OH_CryptoEccSignatureSpec_Encode(OH_CryptoEccSignatureSpec *spec, Crypto_DataBlob *out)](#oh_cryptoeccsignaturespec_encode) | Encodes ECC signing specifications into a signature in DER format.|
| [void OH_CryptoEccSignatureSpec_Destroy(OH_CryptoEccSignatureSpec *spec)](#oh_cryptoeccsignaturespec_destroy) | Destroys ECC signing specifications.|

## Enum Description

### CryptoSignature_ParamType

```
enum CryptoSignature_ParamType
```

**Description**

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

**Description**

Creates a **Verify** instance for signature verification.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const char *algoName | Pointer to the algorithm used to generate the **Verify** instance.<br> For example, **'RSA1024\|PKCS1\|SHA256'**.| | |
| [OH_CryptoVerify](capi-cryptosignatureapi-oh-cryptoverify.md) **verify | Pointer to the **Verify** instance created.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | **CRYPTO_SUCCESS**: The operation is successful.<br>         **CRYPTO_INVALID_PARAMS**: A parameter is invalid.<br>         **CRYPTO_NOT_SUPPORTED**: The operation is not supported.<br>         **CRYPTO_MEMORY_ERROR**: A memory error occurs.<br>         **CRYPTO_OPERATION_ERROR**: An error occurs when the API of a third-party algorithm library is called.|

### OH_CryptoVerify_Init()

```
OH_Crypto_ErrCode OH_CryptoVerify_Init(OH_CryptoVerify *ctx, OH_CryptoPubKey *pubKey)
```

**Description**

Initializes a **Verify** instance by using the public key.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoVerify](capi-cryptosignatureapi-oh-cryptoverify.md) *ctx | Pointer to the **Verify** instance.|
| [OH_CryptoPubKey](capi-cryptoasymkeyapi-oh-cryptopubkey.md) *pubKey | Pointer to the public key.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | **CRYPTO_SUCCESS**: The operation is successful.<br>         **CRYPTO_INVALID_PARAMS**: A parameter is invalid.<br>         **CRYPTO_NOT_SUPPORTED**: The operation is not supported.<br>         **CRYPTO_MEMORY_ERROR**: A memory error occurs.<br>         **CRYPTO_OPERATION_ERROR**: An error occurs when the API of a third-party algorithm library is called.|

**Reference**

[OH_CryptoVerify_Update](#oh_cryptoverify_update)

[OH_CryptoVerify_Final](#oh_cryptoverify_final)


### OH_CryptoVerify_Update()

```
OH_Crypto_ErrCode OH_CryptoVerify_Update(OH_CryptoVerify *ctx, Crypto_DataBlob *in)
```

**Description**

Updates the data to be verified.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoVerify](capi-cryptosignatureapi-oh-cryptoverify.md) *ctx | Pointer to the **Verify** instance.|
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *in | Pointer to the data to pass in.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | **CRYPTO_SUCCESS**: The operation is successful.<br>         **CRYPTO_INVALID_PARAMS**: A parameter is invalid.<br>         **CRYPTO_NOT_SUPPORTED**: The operation is not supported.<br>         **CRYPTO_MEMORY_ERROR**: A memory error occurs.<br>         **CRYPTO_OPERATION_ERROR**: An error occurs when the API of a third-party algorithm library is called.|

**Reference**

[OH_CryptoVerify_Init](#oh_cryptoverify_init)

[OH_CryptoVerify_Final](#oh_cryptoverify_final)


### OH_CryptoVerify_Final()

```
bool OH_CryptoVerify_Final(OH_CryptoVerify *ctx, Crypto_DataBlob *in, Crypto_DataBlob *signData)
```

**Description**

Verifies the signature of the data.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoVerify](capi-cryptosignatureapi-oh-cryptoverify.md) *ctx | Pointer to the **Verify** instance.|
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *in | Pointer to the data passed in.|
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *signData | Pointer to the signature data.|

**Returns**

| Type| Description|
| -- | -- |
| bool | Whether the signature verification is successful.|

**Reference**

[OH_CryptoVerify_Init](#oh_cryptoverify_init)

[OH_CryptoVerify_Update](#oh_cryptoverify_update)


### OH_CryptoVerify_Recover()

```
OH_Crypto_ErrCode OH_CryptoVerify_Recover(OH_CryptoVerify *ctx, Crypto_DataBlob *signData,Crypto_DataBlob *rawSignData)
```

**Description**

Restores the raw signature data.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoVerify](capi-cryptosignatureapi-oh-cryptoverify.md) *ctx | Pointer to the **Verify** instance.|
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *signData | Pointer to the signature data.|
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *rawSignData | Pointer to the raw data restored.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | **CRYPTO_SUCCESS**: The operation is successful.<br>         **CRYPTO_INVALID_PARAMS**: A parameter is invalid.<br>         **CRYPTO_NOT_SUPPORTED**: The operation is not supported.<br>         **CRYPTO_MEMORY_ERROR**: A memory error occurs.<br>         **CRYPTO_OPERATION_ERROR**: An error occurs when the API of a third-party algorithm library is called.|

### OH_CryptoVerify_GetAlgoName()

```
const char *OH_CryptoVerify_GetAlgoName(OH_CryptoVerify *ctx)
```

**Description**

Obtains the signature verification algorithm.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoVerify](capi-cryptosignatureapi-oh-cryptoverify.md) *ctx | Pointer to the **Verify** instance.|

**Returns**

| Type| Description|
| -- | -- |
| const char * | Signature verification algorithm obtained.|

### OH_CryptoVerify_SetParam()

```
OH_Crypto_ErrCode OH_CryptoVerify_SetParam(OH_CryptoVerify *ctx, CryptoSignature_ParamType type,Crypto_DataBlob *value)
```

**Description**

Sets a signature verification parameter.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoVerify](capi-cryptosignatureapi-oh-cryptoverify.md) *ctx | Pointer to the **Verify** instance.|
| [CryptoSignature_ParamType](#cryptosignature_paramtype) type | Name of the signature verification parameter to set.|
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *value | Pointer to the value of the signature verification parameter to set.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | **CRYPTO_SUCCESS**: The operation is successful.<br>         **CRYPTO_INVALID_PARAMS**: A parameter is invalid.<br>         **CRYPTO_NOT_SUPPORTED**: The operation is not supported.<br>         **CRYPTO_MEMORY_ERROR**: A memory error occurs.<br>         **CRYPTO_OPERATION_ERROR**: An error occurs when the API of a third-party algorithm library is called.|

### OH_CryptoVerify_GetParam()

```
OH_Crypto_ErrCode OH_CryptoVerify_GetParam(OH_CryptoVerify *ctx, CryptoSignature_ParamType type,Crypto_DataBlob *value)
```

**Description**

Obtains a signature verification parameter.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoVerify](capi-cryptosignatureapi-oh-cryptoverify.md) *ctx | Pointer to the **Verify** instance.|
| [CryptoSignature_ParamType](#cryptosignature_paramtype) type | Name of the signature verification parameter to obtain.|
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *value | Pointer to the parameter value obtained.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | **CRYPTO_SUCCESS**: The operation is successful.<br>         **CRYPTO_INVALID_PARAMS**: A parameter is invalid.<br>         **CRYPTO_NOT_SUPPORTED**: The operation is not supported.<br>         **CRYPTO_MEMORY_ERROR**: A memory error occurs.<br>         **CRYPTO_OPERATION_ERROR**: An error occurs when the API of a third-party algorithm library is called.|

### OH_CryptoVerify_Destroy()

```
void OH_CryptoVerify_Destroy(OH_CryptoVerify *ctx)
```

**Description**

Destroys a **Verify** instance.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoVerify](capi-cryptosignatureapi-oh-cryptoverify.md) *ctx | Pointer to the **Verify** instance.|

### OH_CryptoSign_Create()

```
OH_Crypto_ErrCode OH_CryptoSign_Create(const char *algoName, OH_CryptoSign **sign)
```

**Description**

Creates a signature instance based on the given algorithm name.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| const char *algoName | Pointer to the algorithm used to generate the signature instance.<br> For example, **'RSA\|PKCS1\|SHA384'**, **'ECC\|SHA84'**| | | |
| [OH_CryptoSign](capi-cryptosignatureapi-oh-cryptosign.md) **sign | Pointer to the signature instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | **CRYPTO_SUCCESS**: The operation is successful.<br>         **CRYPTO_NOT_SUPPORTED**: The operation is not supported.<br>         **CRYPTO_MEMORY_ERROR**: A memory error occurs.<br>         **CRYPTO_PARAMETER_CHECK_FAILED**: The parameter check failed.<br>         **CRYPTO_OPERATION_ERROR**: An error occurs when the API of a third-party algorithm library is called.|

### OH_CryptoSign_Init()

```
OH_Crypto_ErrCode OH_CryptoSign_Init(OH_CryptoSign *ctx, OH_CryptoPrivKey *privKey)
```

**Description**

Initializes a signature instance.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoSign](capi-cryptosignatureapi-oh-cryptosign.md) *ctx | Pointer to the signature instance.|
| [OH_CryptoPrivKey](capi-cryptoasymkeyapi-oh-cryptoprivkey.md) *privKey | Pointer to the private key.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | **CRYPTO_SUCCESS**: The operation is successful.<br>         **CRYPTO_NOT_SUPPORTED**: The operation is not supported.<br>         **CRYPTO_MEMORY_ERROR**: A memory error occurs.<br>         **CRYPTO_PARAMETER_CHECK_FAILED**: The parameter check failed.<br>         **CRYPTO_OPERATION_ERROR**: An error occurs when the API of a third-party algorithm library is called.|

**Reference**

[OH_CryptoSign_Update](#oh_cryptosign_update)

[OH_CryptoSign_Final](#oh_cryptosign_final)


### OH_CryptoSign_Update()

```
OH_Crypto_ErrCode OH_CryptoSign_Update(OH_CryptoSign *ctx, const Crypto_DataBlob *in)
```

**Description**

Updates the data to be signed.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoSign](capi-cryptosignatureapi-oh-cryptosign.md) *ctx | Pointer to the signature instance.|
| [const Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *in | Pointer to the data to be signed.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | **CRYPTO_SUCCESS**: The operation is successful.<br>         **CRYPTO_NOT_SUPPORTED**: The operation is not supported.<br>         **CRYPTO_MEMORY_ERROR**: A memory error occurs.<br>         **CRYPTO_PARAMETER_CHECK_FAILED**: The parameter check failed.<br>         **CRYPTO_OPERATION_ERROR**: An error occurs when the API of a third-party algorithm library is called.|

**Reference**

[OH_CryptoSign_Init](#oh_cryptosign_init)

[OH_CryptoSign_Final](#oh_cryptosign_final)


### OH_CryptoSign_Final()

```
OH_Crypto_ErrCode OH_CryptoSign_Final(OH_CryptoSign *ctx, const Crypto_DataBlob *in, Crypto_DataBlob *out)
```

**Description**

Finalizes the signing operation.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoSign](capi-cryptosignatureapi-oh-cryptosign.md) *ctx | Pointer to the signature instance.|
| [const Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *in | Pointer to the data to be signed.|
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *out | Pointer to the signing result.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | **CRYPTO_SUCCESS**: The operation is successful.<br>         **CRYPTO_NOT_SUPPORTED**: The operation is not supported.<br>         **CRYPTO_MEMORY_ERROR**: A memory error occurs.<br>         **CRYPTO_PARAMETER_CHECK_FAILED**: The parameter check failed.<br>         **CRYPTO_OPERATION_ERROR**: An error occurs when the API of a third-party algorithm library is called.|

**Reference**

[OH_CryptoSign_Init](#oh_cryptosign_init)

[OH_CryptoSign_Update](#oh_cryptosign_update)


### OH_CryptoSign_GetAlgoName()

```
const char *OH_CryptoSign_GetAlgoName(OH_CryptoSign *ctx)
```

**Description**

Obtains the algorithm name of a signature instance.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoSign](capi-cryptosignatureapi-oh-cryptosign.md) *ctx | Pointer to the signature instance.|

**Returns**

| Type| Description|
| -- | -- |
| const char * | Algorithm name of the signature instance.|

### OH_CryptoSign_SetParam()

```
OH_Crypto_ErrCode OH_CryptoSign_SetParam(OH_CryptoSign *ctx, CryptoSignature_ParamType type,const Crypto_DataBlob *value)
```

**Description**

Sets parameters for a signature instance.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoSign](capi-cryptosignatureapi-oh-cryptosign.md) *ctx | Pointer to the signature instance.|
| [CryptoSignature_ParamType](#cryptosignature_paramtype) type | Pointer to the signature parameter type.|
| [const Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *value | Pointer to the input data.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | **CRYPTO_SUCCESS**: The operation is successful.<br>         **CRYPTO_NOT_SUPPORTED**: The operation is not supported.<br>         **CRYPTO_MEMORY_ERROR**: A memory error occurs.<br>         **CRYPTO_PARAMETER_CHECK_FAILED**: The parameter check failed.<br>         **CRYPTO_OPERATION_ERROR**: An error occurs when the API of a third-party algorithm library is called.|

### OH_CryptoSign_GetParam()

```
OH_Crypto_ErrCode OH_CryptoSign_GetParam(OH_CryptoSign *ctx, CryptoSignature_ParamType type, Crypto_DataBlob *value)
```

**Description**

Obtains the specified parameter from a signature instance.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoSign](capi-cryptosignatureapi-oh-cryptosign.md) *ctx | Pointer to the signature instance.|
| [CryptoSignature_ParamType](#cryptosignature_paramtype) type | Pointer to the signature parameter type.|
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *value | Pointer to the output data.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | **CRYPTO_SUCCESS**: The operation is successful.<br>         **CRYPTO_NOT_SUPPORTED**: The operation is not supported.<br>         **CRYPTO_MEMORY_ERROR**: A memory error occurs.<br>         **CRYPTO_PARAMETER_CHECK_FAILED**: The parameter check failed.<br>         **CRYPTO_OPERATION_ERROR**: An error occurs when the API of a third-party algorithm library is called.|

### OH_CryptoSign_Destroy()

```
void OH_CryptoSign_Destroy(OH_CryptoSign *ctx)
```

**Description**

Destroys a signature instance.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoSign](capi-cryptosignatureapi-oh-cryptosign.md) *ctx | Pointer to the signature instance.|

### OH_CryptoEccSignatureSpec_Create()

```
OH_Crypto_ErrCode OH_CryptoEccSignatureSpec_Create(Crypto_DataBlob *eccSignature,OH_CryptoEccSignatureSpec **spec)
```

**Description**

Creates ECC signing specifications.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *eccSignature | Pointer to the ECC signature (in DER format). If **EccSignature** is **NULL**, an empty ECC signing specification is created.|
| [OH_CryptoEccSignatureSpec](capi-cryptosignatureapi-oh-cryptoeccsignaturespec.md) **spec | Pointer to the ECC signing specifications.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | **CRYPTO_SUCCESS**: The operation is successful.<br>         **CRYPTO_NOT_SUPPORTED**: The operation is not supported.<br>         **CRYPTO_MEMORY_ERROR**: A memory error occurs.<br>         **CRYPTO_PARAMETER_CHECK_FAILED**: The parameter check failed.<br>         **CRYPTO_OPERATION_ERROR**: An error occurs when the API of a third-party algorithm library is called.|

### OH_CryptoEccSignatureSpec_GetRAndS()

```
OH_Crypto_ErrCode OH_CryptoEccSignatureSpec_GetRAndS(OH_CryptoEccSignatureSpec *spec, Crypto_DataBlob *r,Crypto_DataBlob *s)
```

**Description**

Obtains the **r** and **s** values of an ECC signature.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoEccSignatureSpec](capi-cryptosignatureapi-oh-cryptoeccsignaturespec.md) *spec | Pointer to the ECC signing specifications.|
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *r | Pointer to the **r** value.|
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *s | Pointer to the **s** value.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | **CRYPTO_SUCCESS**: The operation is successful.<br>         **CRYPTO_NOT_SUPPORTED**: The operation is not supported.<br>         **CRYPTO_MEMORY_ERROR**: A memory error occurs.<br>         **CRYPTO_PARAMETER_CHECK_FAILED**: The parameter check failed.<br>         **CRYPTO_OPERATION_ERROR**: An error occurs when the API of a third-party algorithm library is called.|

### OH_CryptoEccSignatureSpec_SetRAndS()

```
OH_Crypto_ErrCode OH_CryptoEccSignatureSpec_SetRAndS(OH_CryptoEccSignatureSpec *spec, Crypto_DataBlob *r,Crypto_DataBlob *s)
```

**Description**

Sets the **r** and **s** values of an ECC signature.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoEccSignatureSpec](capi-cryptosignatureapi-oh-cryptoeccsignaturespec.md) *spec | Pointer to the ECC signing specifications.|
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *r | Pointer to the **r** value.|
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *s | Pointer to the **s** value.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | **CRYPTO_SUCCESS**: The operation is successful.<br>         **CRYPTO_NOT_SUPPORTED**: The operation is not supported.<br>         **CRYPTO_MEMORY_ERROR**: A memory error occurs.<br>         **CRYPTO_PARAMETER_CHECK_FAILED**: The parameter check failed.<br>         **CRYPTO_OPERATION_ERROR**: An error occurs when the API of a third-party algorithm library is called.|

### OH_CryptoEccSignatureSpec_Encode()

```
OH_Crypto_ErrCode OH_CryptoEccSignatureSpec_Encode(OH_CryptoEccSignatureSpec *spec, Crypto_DataBlob *out)
```

**Description**

Encodes ECC signing specifications into a signature in DER format.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoEccSignatureSpec](capi-cryptosignatureapi-oh-cryptoeccsignaturespec.md) *spec | Pointer to the ECC signing specifications.|
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *out | Pointer to the output data.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | **CRYPTO_SUCCESS**: The operation is successful.<br>         **CRYPTO_NOT_SUPPORTED**: The operation is not supported.<br>         **CRYPTO_MEMORY_ERROR**: A memory error occurs.<br>         **CRYPTO_PARAMETER_CHECK_FAILED**: The parameter check failed.<br>         **CRYPTO_OPERATION_ERROR**: An error occurs when the API of a third-party algorithm library is called.|

### OH_CryptoEccSignatureSpec_Destroy()

```
void OH_CryptoEccSignatureSpec_Destroy(OH_CryptoEccSignatureSpec *spec)
```

**Description**

Destroys ECC signing specifications.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoEccSignatureSpec](capi-cryptosignatureapi-oh-cryptoeccsignaturespec.md) *spec | Pointer to the ECC signing specifications.|
