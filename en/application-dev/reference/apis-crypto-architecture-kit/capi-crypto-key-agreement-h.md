# crypto_key_agreement.h

<!--Kit: Crypto Architecture Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--Designer: @lanming-->
<!--Tester: @PAFT-->
<!--Adviser: @zengyawen-->

## Overview

Defines key agreement APIs.

**Header file**: <CryptoArchitectureKit/crypto_key_agreement.h>

**Library**: libohcrypto.so

**System capability**: SystemCapability.Security.CryptoFramework

**Since**: 20

**Related Module**: [CryptoKeyAgreementApi](capi-cryptokeyagreementapi.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_CryptoKeyAgreement](capi-cryptokeyagreementapi-oh-cryptokeyagreement.md) | OH_CryptoKeyAgreement | Defines a struct for key agreement.|

### Functions

| Name| Description|
| -- | -- |
| [OH_Crypto_ErrCode OH_CryptoKeyAgreement_Create(const char *algoName, OH_CryptoKeyAgreement **ctx)](#oh_cryptokeyagreement_create) | Creates a key agreement instance based on the given algorithm name.|
| [OH_Crypto_ErrCode OH_CryptoKeyAgreement_GenerateSecret(OH_CryptoKeyAgreement *ctx, OH_CryptoPrivKey *privkey,OH_CryptoPubKey *pubkey, Crypto_DataBlob *secret)](#oh_cryptokeyagreement_generatesecret) | Generates the secret value of key agreement.|
| [void OH_CryptoKeyAgreement_Destroy(OH_CryptoKeyAgreement *ctx)](#oh_cryptokeyagreement_destroy) | Destroys a key agreement instance.|

## Function Description

### OH_CryptoKeyAgreement_Create()

```
OH_Crypto_ErrCode OH_CryptoKeyAgreement_Create(const char *algoName, OH_CryptoKeyAgreement **ctx)
```

**Description**

Creates a key agreement instance based on the given algorithm name.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| const char *algoName | Algorithm name of the key agreement instance to be created.<br> For example, **ECC** or **X25519**.|
| [OH_CryptoKeyAgreement](capi-cryptokeyagreementapi-oh-cryptokeyagreement.md) **ctx | Key agreement instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | **CRYPTO_SUCCESS**: The operation is successful.<br>         **CRYPTO_NOT_SUPPORTED**: The operation is not supported.<br>         **CRYPTO_MEMORY_ERROR**: A memory error occurs.<br>         **CRYPTO_PARAMETER_CHECK_FAILED**: The parameter check failed.<br>         **CRYPTO_OPERTION_ERROR**: Failed to call an API of a third-party algorithm library.|

### OH_CryptoKeyAgreement_GenerateSecret()

```
OH_Crypto_ErrCode OH_CryptoKeyAgreement_GenerateSecret(OH_CryptoKeyAgreement *ctx, OH_CryptoPrivKey *privkey,OH_CryptoPubKey *pubkey, Crypto_DataBlob *secret)
```

**Description**

Generates the secret value of key agreement.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoKeyAgreement](capi-cryptokeyagreementapi-oh-cryptokeyagreement.md) *ctx | Key agreement instance.|
| [OH_CryptoPrivKey](capi-cryptoasymkeyapi-oh-cryptoprivkey.md) *privkey | Private key.|
| [OH_CryptoPubKey](capi-cryptoasymkeyapi-oh-cryptopubkey.md) *pubkey | Public key.|
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *secret | Secret value.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | **CRYPTO_SUCCESS**: The operation is successful.<br>         **CRYPTO_NOT_SUPPORTED**: The operation is not supported.<br>         **CRYPTO_MEMORY_ERROR**: A memory error occurs.<br>         **CRYPTO_PARAMETER_CHECK_FAILED**: The parameter check failed.<br>         **CRYPTO_OPERTION_ERROR**: Failed to call an API of a third-party algorithm library.|

### OH_CryptoKeyAgreement_Destroy()

```
void OH_CryptoKeyAgreement_Destroy(OH_CryptoKeyAgreement *ctx)
```

**Description**

Destroys a key agreement instance.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoKeyAgreement](capi-cryptokeyagreementapi-oh-cryptokeyagreement.md) *ctx | Key agreement instance.|
