# CryptoDigestApi


## Overview

Provides APIs for message digest (MD) algorithms.

**Since**: 12


## Summary


### Files

| Name | Description | 
| -------- | -------- |
| [crypto_digest.h](crypto__digest_8h.md) | Defines APIs for MD algorithms. | 


### Types

| Name | Description | 
| -------- | -------- |
| typedef struct [OH_CryptoDigest](#oh_cryptodigest) [OH_CryptoDigest](#oh_cryptodigest) | Defines an MD. | 


### Functions

| Name | Description | 
| -------- | -------- |
| [OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode) [OH_CryptoDigest_Create](#oh_cryptodigest_create) (const char \*algoName, [OH_CryptoDigest](#oh_cryptodigest) \*\*ctx) | Creates an MD instance based on the given algorithm name. | 
| [OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode) [OH_CryptoDigest_Update](#oh_cryptodigest_update) ([OH_CryptoDigest](#oh_cryptodigest) \*ctx, [Crypto_DataBlob](_crypto___data_blob.md) \*in) | Updates the data used for generating an MD. | 
| [OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode) [OH_CryptoDigest_Final](#oh_cryptodigest_final) ([OH_CryptoDigest](#oh_cryptodigest) \*ctx, [Crypto_DataBlob](_crypto___data_blob.md) \*out) | Generates an MD. | 
| uint32_t [OH_CryptoDigest_GetLength](#oh_cryptodigest_getlength) ([OH_CryptoDigest](#oh_cryptodigest) \*ctx) | Obtains the length of an MD. | 
| const char \* [OH_CryptoDigest_GetAlgoName](#oh_cryptodigest_getalgoname) ([OH_CryptoDigest](#oh_cryptodigest) \*ctx) | Obtains the digest algorithm. | 
| void [OH_DigestCrypto_Destroy](#oh_digestcrypto_destroy) ([OH_CryptoDigest](#oh_cryptodigest) \*ctx) | Destroys an MD instance. | 


## Type Description


### OH_CryptoDigest

```
typedef struct OH_CryptoDigestOH_CryptoDigest
```

**Description**

Defines an MD.

**Since**: 12


## Function Description


### OH_CryptoDigest_Create()

```
OH_Crypto_ErrCode OH_CryptoDigest_Create (const char *algoName, OH_CryptoDigest **ctx )
```

**Description**

Creates an MD instance based on the given algorithm name.

**Since**: 12

**Parameters**

| Name | Description | 
| -------- | -------- |
| algoName | Pointer to the algorithm used to generate the MD instance. For example, **'SHA256'**. | 
| ctx | Pointer to the MD instance created. | 

**Returns**

[OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode):

**0**: The operation is successful.

**401**: Invalid parameters are detected.

**801**: The operation is not supported.

**17620001**: A memory error occurred.

**17630001**: Failed to call an API of a third-party algorithm library.


### OH_CryptoDigest_Final()

```
OH_Crypto_ErrCode OH_CryptoDigest_Final (OH_CryptoDigest *ctx, Crypto_DataBlob *out )
```

**Description**

Generates an MD.

**Since**: 12

**Parameters**

| Name | Description | 
| -------- | -------- |
| ctx | Pointer to the MD instance. | 
| out | Pointer to the MD generated. | 

**Returns**

[OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode):

**0**: The operation is successful.

**401**: Invalid parameters are detected.

**801**: The operation is not supported.

**17620001**: A memory error occurred.

**17630001**: Failed to call an API of a third-party algorithm library.

**See**

[OH_CryptoDigest_Update](#oh_cryptodigest_update)


### OH_CryptoDigest_GetAlgoName()

```
const char* OH_CryptoDigest_GetAlgoName (OH_CryptoDigest *ctx)
```

**Description**

Obtains the digest algorithm.

**Since**: 12

**Parameters**

| Name | Description | 
| -------- | -------- |
| ctx | Pointer to the MD instance. | 

**Returns**

MD algorithm obtained.


### OH_CryptoDigest_GetLength()

```
uint32_t OH_CryptoDigest_GetLength (OH_CryptoDigest *ctx)
```

**Description**

Obtains the length of an MD.

**Since**: 12

**Parameters**

| Name | Description | 
| -------- | -------- |
| ctx | Pointer to the MD instance. | 

**Returns**

[OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode):

**0**: The operation is successful.

**401**: Invalid parameters are detected.

**801**: The operation is not supported.

**17620001**: A memory error occurred.

**17630001**: Failed to call an API of a third-party algorithm library.


### OH_CryptoDigest_Update()

```
OH_Crypto_ErrCode OH_CryptoDigest_Update (OH_CryptoDigest *ctx, Crypto_DataBlob *in )
```

**Description**

Updates the data used for generating an MD.

**Since**: 12

**Parameters**

| Name | Description | 
| -------- | -------- |
| ctx | Pointer to the MD instance. | 
| in | Pointer to the data to pass in. | 

**Returns**

[OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode):

**0**: The operation is successful.

**401**: Invalid parameters are detected.

**801**: The operation is not supported.

**17620001**: A memory error occurred.

**17630001**: Failed to call an API of a third-party algorithm library.

**See**

[OH_CryptoDigest_Final](#oh_cryptodigest_final)


### OH_DigestCrypto_Destroy()

```
void OH_DigestCrypto_Destroy (OH_CryptoDigest *ctx)
```

**Description**

Destroys an MD instance.

**Since**: 12

**Parameters**

| Name | Description | 
| -------- | -------- |
| ctx | Pointer to the MD instance. | 

**Returns**

[OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode):

**0**: The operation is successful.

**401**: Invalid parameters are detected.

**801**: The operation is not supported.

**17620001**: A memory error occurred.

**17630001**: Failed to call an API of a third-party algorithm library.
