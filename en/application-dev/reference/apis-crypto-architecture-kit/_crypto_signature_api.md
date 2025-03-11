# CryptoSignatureApi


## Overview

Provides APIs for signature verification.

**Since**: 12


## Summary


### Files

| Name| Description| 
| -------- | -------- |
| [crypto_signature.h](crypto__signature_8h.md) | Defines APIs for signature verification.| 


### Types

| Name| Description| 
| -------- | -------- |
| typedef struct [OH_CryptoVerify](#oh_cryptoverify) [OH_CryptoVerify](#oh_cryptoverify) | Defines the data used for signature verification.| 


### Enums

| Name| Description| 
| -------- | -------- |
| [CryptoSignature_ParamType](#cryptosignature_paramtype) {<br>CRYPTO_PSS_MD_NAME_STR = 100, CRYPTO_PSS_MGF_NAME_STR = 101,<br>CRYPTO_PSS_MGF1_NAME_STR = 102, CRYPTO_PSS_SALT_LEN_INT = 103,<br>CRYPTO_PSS_TRAILER_FIELD_INT = 104, CRYPTO_SM2_USER_ID_DATABLOB = 105<br>} | Enumerates the types of signature verification parameters.| 


### Functions

| Name| Description| 
| -------- | -------- |
| [OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode) [OH_CryptoVerify_Create](#oh_cryptoverify_create) (const char \*algoName, [OH_CryptoVerify](#oh_cryptoverify) \*\*verify) | Creates a **Verify** instance for signature verification.| 
| [OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode) [OH_CryptoVerify_Init](#oh_cryptoverify_init) ([OH_CryptoVerify](#oh_cryptoverify) \*ctx, [OH_CryptoPubKey](_crypto_asym_key_api.md#oh_cryptopubkey) \*pubKey) | Initializes a **Verify** instance by using the public key.| 
| [OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode) [OH_CryptoVerify_Update](#oh_cryptoverify_update) ([OH_CryptoVerify](#oh_cryptoverify) \*ctx, [Crypto_DataBlob](_crypto___data_blob.md) \*in) | Updates the data to be verified.| 
| bool [OH_CryptoVerify_Final](#oh_cryptoverify_final) ([OH_CryptoVerify](#oh_cryptoverify) \*ctx, [Crypto_DataBlob](_crypto___data_blob.md) \*in, [Crypto_DataBlob](_crypto___data_blob.md) \*signData) | Verifies the signature of the data.| 
| [OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode) [OH_CryptoVerify_Recover](#oh_cryptoverify_recover) ([OH_CryptoVerify](#oh_cryptoverify) \*ctx, [Crypto_DataBlob](_crypto___data_blob.md) \*signData, [Crypto_DataBlob](_crypto___data_blob.md) \*rawSignData) | Restores the raw signature data.| 
| const char \* [OH_CryptoVerify_GetAlgoName](#oh_cryptoverify_getalgoname) ([OH_CryptoVerify](#oh_cryptoverify) \*ctx) | Obtains the signature verification algorithm.| 
| [OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode) [OH_CryptoVerify_SetParam](#oh_cryptoverify_setparam) ([OH_CryptoVerify](#oh_cryptoverify) \*ctx, [CryptoSignature_ParamType](#cryptosignature_paramtype) type, [Crypto_DataBlob](_crypto___data_blob.md) \*value) | Sets a signature verification parameter.| 
| [OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode) [OH_CryptoVerify_GetParam](#oh_cryptoverify_getparam) ([OH_CryptoVerify](#oh_cryptoverify) \*ctx, [CryptoSignature_ParamType](#cryptosignature_paramtype) type, [Crypto_DataBlob](_crypto___data_blob.md) \*value) | Obtains a signature verification parameter.| 
| void [OH_CryptoVerify_Destroy](#oh_cryptoverify_destroy) ([OH_CryptoVerify](#oh_cryptoverify) \*ctx) | Destroys a **Verify** instance.| 


## Type Description


### OH_CryptoVerify

```
typedef struct OH_CryptoVerifyOH_CryptoVerify
```

**Description**

Defines the data used for signature verification.

**Since**: 12


## Enum Description


### CryptoSignature_ParamType

```
enum CryptoSignature_ParamType
```

**Description**

Enumerates the types of signature verification parameters.

**Since**: 12

| Enum| Description| 
| -------- | -------- |
| CRYPTO_PSS_MD_NAME_STR | MD algorithm used with the PSS padding mode in RSA.| 
| CRYPTO_PSS_MGF_NAME_STR | Mask generation algorithm used with the PSS padding mode in RSA. Currently, only MGF1 is supported.| 
| CRYPTO_PSS_MGF1_NAME_STR | MD parameters for the MGF1 mask generation used with the PSS padding mode in RSA.| 
| CRYPTO_PSS_SALT_LEN_INT | Length of the salt in bytes used with the PSS padding mode in RSA.| 
| CRYPTO_PSS_TRAILER_FIELD_INT | Trailer field used in the encoding operation when PSS padding mode is used in RSA. The value is **1**.| 
| CRYPTO_SM2_USER_ID_DATABLOB | User ID field in SM2.| 


## Function Description


### OH_CryptoVerify_Create()

```
OH_Crypto_ErrCode OH_CryptoVerify_Create (const char *algoName, OH_CryptoVerify **verify )
```

**Description**

Creates a **Verify** instance for signature verification.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| algoName | Pointer to the algorithm used to generate the **Verify** instance. For example, **'RSA1024\|PKCS1\|SHA256'**.| | | 
| verify | Pointer to the **Verify** instance created.| 

**Returns**

[OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode):

**0**: The operation is successful.

**401**: Invalid parameters are detected.

**801**: The operation is not supported.

**17620001**: A memory error occurred.

**17630001**: Failed to call an API of a third-party algorithm library.


### OH_CryptoVerify_Destroy()

```
void OH_CryptoVerify_Destroy (OH_CryptoVerify *ctx)
```

**Description**

Destroys a **Verify** instance.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| ctx | Pointer to the **Verify** instance to destroy.| 


### OH_CryptoVerify_Final()

```
bool OH_CryptoVerify_Final (OH_CryptoVerify *ctx, Crypto_DataBlob *in, Crypto_DataBlob *signData )
```

**Description**

Verifies the signature of the data.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| ctx | Pointer to the **Verify** instance.| 
| in | Pointer to the data passed in.| 
| out | Pointer to the signature data.| 

**Returns**

Returns a boolean value, indicating whether the signature verification is successful.

**See**

[OH_CryptoVerify_Init](#oh_cryptoverify_init)

[OH_CryptoVerify_Update](#oh_cryptoverify_update)


### OH_CryptoVerify_GetAlgoName()

```
const char* OH_CryptoVerify_GetAlgoName (OH_CryptoVerify *ctx)
```

**Description**

Obtains the signature verification algorithm.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| ctx | Pointer to the **Verify** instance.| 

**Returns**

Signature verification algorithm obtained.


### OH_CryptoVerify_GetParam()

```
OH_Crypto_ErrCode OH_CryptoVerify_GetParam (OH_CryptoVerify *ctx, CryptoSignature_ParamType type, Crypto_DataBlob *value )
```

**Description**

Obtains a signature verification parameter.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| ctx | Pointer to the **Verify** instance.| 
| type | Name of the signature verification parameter to obtain.| 
| value | Pointer to the parameter value obtained.| 

**Returns**

[OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode):

**0**: The operation is successful.

**401**: Invalid parameters are detected.

**801**: The operation is not supported.

**17620001**: A memory error occurred.

**17630001**: Failed to call an API of a third-party algorithm library.


### OH_CryptoVerify_Init()

```
OH_Crypto_ErrCode OH_CryptoVerify_Init (OH_CryptoVerify *ctx, OH_CryptoPubKey *pubKey )
```

**Description**

Initializes a **Verify** instance by using the public key.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| ctx | Pointer to the **Verify** instance.| 
| pubKey | Pointer to the public key.| 

**Returns**

[OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode):

**0**: The operation is successful.

**401**: Invalid parameters are detected.

**801**: The operation is not supported.

**17620001**: A memory error occurred.

**17630001**: Failed to call an API of a third-party algorithm library.

**See**

[OH_CryptoVerify_Update](#oh_cryptoverify_update)

[OH_CryptoVerify_Final](#oh_cryptoverify_final)


### OH_CryptoVerify_Recover()

```
OH_Crypto_ErrCode OH_CryptoVerify_Recover (OH_CryptoVerify *ctx, Crypto_DataBlob *signData, Crypto_DataBlob *rawSignData )
```

**Description**

Restores the signature data.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| ctx | Pointer to the **Verify** instance.| 
| signData | Pointer to the signature data to be restored.| 
| rawSignData | Pointer to the raw data restored.| 

**Returns**

[OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode):

**0**: The operation is successful.

**401**: Invalid parameters are detected.

**801**: The operation is not supported.

**17620001**: A memory error occurred.

**17630001**: Failed to call an API of a third-party algorithm library.


### OH_CryptoVerify_SetParam()

```
OH_Crypto_ErrCode OH_CryptoVerify_SetParam (OH_CryptoVerify *ctx, CryptoSignature_ParamType type, Crypto_DataBlob *value )
```

**Description**

Sets a signature verification parameter.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| ctx | Pointer to the **Verify** instance.| 
| type | Name of the signature verification parameter to set.| 
| value | Pointer to the value of the signature verification parameter to set.| 

**Returns**

[OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode):

**0**: The operation is successful.

**401**: Invalid parameters are detected.

**801**: The operation is not supported.

**17620001**: A memory error occurred.

**17630001**: Failed to call an API of a third-party algorithm library.


### OH_CryptoVerify_Update()

```
OH_Crypto_ErrCode OH_CryptoVerify_Update (OH_CryptoVerify *ctx, Crypto_DataBlob *in )
```

**Description**

Updates the data to be verified.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| ctx | Pointer to the **Verify** instance.| 
| in | Pointer to the data to pass in.| 

**Returns**

[OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode):

**0**: The operation is successful.

**401**: Invalid parameters are detected.

**801**: The operation is not supported.

**17620001**: A memory error occurred.

**17630001**: Failed to call an API of a third-party algorithm library.

**See**

[OH_CryptoVerify_Init](#oh_cryptoverify_init)

[OH_CryptoVerify_Final](#oh_cryptoverify_final)
