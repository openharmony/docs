# CryptoSymKeyApi


## Overview

Provides APIs for symmetric key operations.

**Since**: 12


## Summary


### Files

| Name | Description | 
| -------- | -------- |
| [crypto_sym_key.h](crypto__sym__key_8h.md) | Defines APIs for symmetric key operations. | 


### Types

| Name | Description | 
| -------- | -------- |
| typedef struct [OH_CryptoSymKey](#oh_cryptosymkey) [OH_CryptoSymKey](#oh_cryptosymkey) | Defines a struct for a symmetric key. | 
| typedef struct [OH_CryptoSymKeyGenerator](#oh_cryptosymkeygenerator) [OH_CryptoSymKeyGenerator](#oh_cryptosymkeygenerator) | Defines a struct for a symmetric key generator. | 


### Functions

| Name | Description | 
| -------- | -------- |
| [OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode) [OH_CryptoSymKeyGenerator_Create](#oh_cryptosymkeygenerator_create) (const char \*algoName, [OH_CryptoSymKeyGenerator](#oh_cryptosymkeygenerator) \*\*ctx) | Creates a symmetric key generator instance based on the given algorithm name. | 
| [OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode) [OH_CryptoSymKeyGenerator_Generate](#oh_cryptosymkeygenerator_generate) ([OH_CryptoSymKeyGenerator](#oh_cryptosymkeygenerator) \*ctx, [OH_CryptoSymKey](#oh_cryptosymkey) \*\*keyCtx) | Randomly generates a symmetric key. | 
| [OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode) [OH_CryptoSymKeyGenerator_Convert](#oh_cryptosymkeygenerator_convert) ([OH_CryptoSymKeyGenerator](#oh_cryptosymkeygenerator) \*ctx, const [Crypto_DataBlob](_crypto___data_blob.md) \*keyData, [OH_CryptoSymKey](#oh_cryptosymkey) \*\*keyCtx) | Converts binary data into a symmetric key. | 
| const char \* [OH_CryptoSymKeyGenerator_GetAlgoName](#oh_cryptosymkeygenerator_getalgoname) ([OH_CryptoSymKeyGenerator](#oh_cryptosymkeygenerator) \*ctx) | Obtains the algorithm of a symmetric key generator instance. | 
| void [OH_CryptoSymKeyGenerator_Destroy](#oh_cryptosymkeygenerator_destroy) ([OH_CryptoSymKeyGenerator](#oh_cryptosymkeygenerator) \*ctx) | Destroys a symmetric key generator instance. | 
| const char \* [OH_CryptoSymKey_GetAlgoName](#oh_cryptosymkey_getalgoname) ([OH_CryptoSymKey](#oh_cryptosymkey) \*keyCtx) | Obtains the algorithm of a symmetric key. | 
| [OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode) [OH_CryptoSymKey_GetKeyData](#oh_cryptosymkey_getkeydata) ([OH_CryptoSymKey](#oh_cryptosymkey) \*keyCtx, [Crypto_DataBlob](_crypto___data_blob.md) \*out) | Obtains symmetric key data from a key instance. | 
| void [OH_CryptoSymKey_Destroy](#oh_cryptosymkey_destroy) ([OH_CryptoSymKey](#oh_cryptosymkey) \*keyCtx) | Destroys a symmetric key instance. | 


## Type Description


### OH_CryptoSymKey

```
typedef struct OH_CryptoSymKeyOH_CryptoSymKey
```

**Description**

Defines a struct for a symmetric key.

**Since**: 12


### OH_CryptoSymKeyGenerator

```
typedef struct OH_CryptoSymKeyGeneratorOH_CryptoSymKeyGenerator
```

**Description**

Defines a struct for a symmetric key generator.

**Since**: 12


## Function Description


### OH_CryptoSymKey_Destroy()

```
void OH_CryptoSymKey_Destroy (OH_CryptoSymKey *keyCtx)
```

**Description**

Destroys a symmetric key instance.

**Since**: 12

**Parameters**

| Name | Description | 
| -------- | -------- |
| keyCtx | Pointer to the symmetric key instance to destroy. | 


### OH_CryptoSymKey_GetAlgoName()

```
const char* OH_CryptoSymKey_GetAlgoName (OH_CryptoSymKey *keyCtx)
```

**Description**

Obtains the algorithm of a symmetric key.

**Since**: 12

**Parameters**

| Name | Description | 
| -------- | -------- |
| keyCtx | Pointer to the symmetric key instance. | 

**Returns**

Symmetric key algorithm obtained.


### OH_CryptoSymKey_GetKeyData()

```
OH_Crypto_ErrCode OH_CryptoSymKey_GetKeyData (OH_CryptoSymKey *keyCtx, Crypto_DataBlob *out )
```

**Description**

Obtains symmetric key data from a key instance.

**Since**: 12

**Parameters**

| Name | Description | 
| -------- | -------- |
| keyCtx | Pointer to the symmetric key instance. | 
| out | Pointer to the data obtained. | 

**Returns**

[OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode):

**0**: The operation is successful.

**401**: Invalid parameters are detected.

**801**: The operation is not supported.

**17620001**: A memory error occurred.

**17630001**: Failed to call an API of a third-party algorithm library.


### OH_CryptoSymKeyGenerator_Convert()

```
OH_Crypto_ErrCode OH_CryptoSymKeyGenerator_Convert (OH_CryptoSymKeyGenerator *ctx, const Crypto_DataBlob *keyData, OH_CryptoSymKey **keyCtx )
```

**Description**

Converts binary data into a symmetric key.

**Since**: 12

**Parameters**

| Name | Description | 
| -------- | -------- |
| ctx | Pointer to the symmetric key generator instance. | 
| keyData | Pointer to the data to convert. | 
| keyCtx | Pointer to the symmetric key obtained. | 

**Returns**

[OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode):

**0**: The operation is successful.

**401**: Invalid parameters are detected.

**801**: The operation is not supported.

**17620001**: A memory error occurred.

**17630001**: Failed to call an API of a third-party algorithm library.


### OH_CryptoSymKeyGenerator_Create()

```
OH_Crypto_ErrCode OH_CryptoSymKeyGenerator_Create (const char *algoName, OH_CryptoSymKeyGenerator **ctx )
```

**Description**

Creates a symmetric key generator instance based on the given algorithm name.

**Since**: 12

**Parameters**

| Name | Description | 
| -------- | -------- |
| algoName | Pointer to the algorithm used to generate the symmetric key. For example, **'AES256'**. | 
| ctx | Double pointer to the symmetric key generator instance created. | 

**Returns**

[OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode):

**0**: The operation is successful.

**401**: Invalid parameters are detected.

**801**: The operation is not supported.

**17620001**: A memory error occurred.

**17630001**: Failed to call an API of a third-party algorithm library.


### OH_CryptoSymKeyGenerator_Destroy()

```
void OH_CryptoSymKeyGenerator_Destroy (OH_CryptoSymKeyGenerator *ctx)
```

**Description**

Destroys a symmetric key generator instance.

**Since**: 12

**Parameters**

| Name | Description | 
| -------- | -------- |
| ctx | Pointer to the symmetric key generator instance to destroy. | 


### OH_CryptoSymKeyGenerator_Generate()

```
OH_Crypto_ErrCode OH_CryptoSymKeyGenerator_Generate (OH_CryptoSymKeyGenerator *ctx, OH_CryptoSymKey **keyCtx )
```

**Description**

Randomly generates a symmetric key.

**Since**: 12

**Parameters**

| Name | Description | 
| -------- | -------- |
| ctx | Pointer to the symmetric key generator instance. | 
| keyCtx | Pointer to the symmetric key created. | 

**Returns**

[OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode):

**0**: The operation is successful.

**401**: Invalid parameters are detected.

**801**: The operation is not supported.

**17620001**: A memory error occurred.

**17630001**: Failed to call an API of a third-party algorithm library.


### OH_CryptoSymKeyGenerator_GetAlgoName()

```
const char* OH_CryptoSymKeyGenerator_GetAlgoName (OH_CryptoSymKeyGenerator *ctx)
```

**Description**

Obtains the algorithm of a symmetric key generator instance.

**Since**: 12

**Parameters**

| Name | Description | 
| -------- | -------- |
| ctx | Pointer to the symmetric key generator instance. | 

**Returns**

Symmetric key algorithm obtained.
