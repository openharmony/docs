# crypto_asym_key.h

## Overview

Defines APIs for asymmetric keys.

**Library**: libohcrypto.so

**Header file**: <CryptoArchitectureKit/crypto_asym_key.h>

**System capability**: SystemCapability.Security.CryptoFramework

**Since**: 12

**Related module**: [CryptoAsymKeyApi](capi-cryptoasymkeyapi.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_CryptoKeyPair](capi-oh-cryptokeypair.md) | OH_CryptoKeyPair | Defines a struct for an asymmetric key pair.|
| [OH_CryptoPubKey](capi-oh-cryptopubkey.md) | OH_CryptoPubKey | Defines a struct for the public key in an asymmetric key pair.|
| [OH_CryptoAsymKeyGenerator](capi-oh-cryptoasymkeygenerator.md) | OH_CryptoAsymKeyGenerator | Defines a struct for an asymmetric key generator.|

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [CryptoAsymKey_ParamType](#cryptoasymkey_paramtype) | CryptoAsymKey_ParamType | Enumerates the types of the asymmetric key parameters.|
| [Crypto_EncodingType](#crypto_encodingtype) | Crypto_EncodingType | Enumerates the encoding types.|

### Functions

| Name| Description|
| -- | -- |
| [OH_Crypto_ErrCode OH_CryptoAsymKeyGenerator_Create(const char *algoName, OH_CryptoAsymKeyGenerator **ctx)](#oh_cryptoasymkeygenerator_create) | Creates an asymmetric key generator instance based on the specified algorithm.|
| [OH_Crypto_ErrCode OH_CryptoAsymKeyGenerator_Generate(OH_CryptoAsymKeyGenerator *ctx, OH_CryptoKeyPair **keyCtx)](#oh_cryptoasymkeygenerator_generate) | Randomly generates an asymmetric key pair.|
| [OH_Crypto_ErrCode OH_CryptoAsymKeyGenerator_Convert(OH_CryptoAsymKeyGenerator *ctx, Crypto_EncodingType type,Crypto_DataBlob *pubKeyData, Crypto_DataBlob *priKeyData, OH_CryptoKeyPair **keyCtx)](#oh_cryptoasymkeygenerator_convert) | Converts asymmetric key data into a key pair.|
| [const char *OH_CryptoAsymKeyGenerator_GetAlgoName(OH_CryptoAsymKeyGenerator *ctx)](#oh_cryptoasymkeygenerator_getalgoname) | Obtains the asymmetric key algorithm.|
| [void OH_CryptoAsymKeyGenerator_Destroy(OH_CryptoAsymKeyGenerator *ctx)](#oh_cryptoasymkeygenerator_destroy) | Destroys an asymmetric key generator instance.|
| [void OH_CryptoKeyPair_Destroy(OH_CryptoKeyPair *keyCtx)](#oh_cryptokeypair_destroy) | Destroys an asymmetric key pair instance.|
| [OH_CryptoPubKey *OH_CryptoKeyPair_GetPubKey(OH_CryptoKeyPair *keyCtx)](#oh_cryptokeypair_getpubkey) | Obtains the public key from a key pair.|
| [OH_Crypto_ErrCode OH_CryptoPubKey_Encode(OH_CryptoPubKey *key, Crypto_EncodingType type,const char *encodingStandard, Crypto_DataBlob *out)](#oh_cryptopubkey_encode) | Encodes the public key data in the specified format.|
| [OH_Crypto_ErrCode OH_CryptoPubKey_GetParam(OH_CryptoPubKey *key, CryptoAsymKey_ParamType item, Crypto_DataBlob *value)](#oh_cryptopubkey_getparam) | Obtains the specified parameter from a public key instance.|

## Enum Description

### CryptoAsymKey_ParamType

```
enum CryptoAsymKey_ParamType
```

Description

Enumerates the types of the asymmetric key parameters.

**Since**: 12

| Enum Item| Description|
| -- | -- |
| CRYPTO_DSA_P_DATABLOB = 101 | Prime modulus **p** in the DSA algorithm.|
| CRYPTO_DSA_Q_DATABLOB = 102 | Parameter **q**, prime factor of (p – 1) in the DSA algorithm.|
| CRYPTO_DSA_G_DATABLOB = 103 | Parameter **g** in the DSA algorithm.|
| CRYPTO_DSA_SK_DATABLOB = 104 | Private key **sk** in the DSA algorithm.|
| CRYPTO_DSA_PK_DATABLOB = 105 | Public key **pk** in the DSA algorithm.|
| CRYPTO_ECC_FP_P_DATABLOB = 201 | Prime number **p** in the **Fp** field of the elliptic curve in the ECC algorithm.|
| CRYPTO_ECC_A_DATABLOB = 202 | First coefficient **a** of the elliptic curve in the ECC algorithm.|
| CRYPTO_ECC_B_DATABLOB = 203 | Second coefficient **b** of the elliptic curve in the ECC algorithm.|
| CRYPTO_ECC_G_X_DATABLOB = 204 | X coordinate of the base point **g** in the ECC algorithm.|
| CRYPTO_ECC_G_Y_DATABLOB = 205 | Y coordinate of the base point **g** in the ECC algorithm.|
| CRYPTO_ECC_N_DATABLOB = 206 | Order **n** of the base point **g** in the ECC algorithm.|
| CRYPTO_ECC_H_INT = 207 | Cofactor **h** in the ECC algorithm.|
| CRYPTO_ECC_SK_DATABLOB = 208 | Private key **sk** in the ECC algorithm.|
| CRYPTO_ECC_PK_X_DATABLOB = 209 | X coordinate of the public key **pk** (a point on the elliptic curve) in the ECC algorithm.|
| CRYPTO_ECC_PK_Y_DATABLOB = 210 | Y coordinate of the public key **pk** (a point on the elliptic curve) in the ECC algorithm.|
| CRYPTO_ECC_FIELD_TYPE_STR = 211 | Elliptic curve field type in the ECC algorithm. Currently, only the **Fp** field is supported.|
| CRYPTO_ECC_FIELD_SIZE_INT = 212 | Size of the field in the ECC algorithm, in bits.<br>**NOTE**: The size of the **Fp** field is the length of the prime **p**, in bits.|
| CRYPTO_ECC_CURVE_NAME_STR = 213 | Standards for Efficient Cryptography Group (SECG) curve name in the ECC algorithm.|
| CRYPTO_RSA_N_DATABLOB = 301 | Modulus **n** in the RSA algorithm.|
| CRYPTO_RSA_D_DATABLOB = 302 | Private key **sk** (private key exponent **d**) in the RSA algorithm.|
| CRYPTO_RSA_E_DATABLOB = 303 | Public key **pk** (public key exponent **e**) in the RSA algorithm.|
| CRYPTO_DH_P_DATABLOB = 401 | Prime **p** in the DH algorithm.|
| CRYPTO_DH_G_DATABLOB = 402 | Parameter **g** in the DH algorithm.|
| CRYPTO_DH_L_INT = 403 | Length of the private key in the DH algorithm, in bits.|
| CRYPTO_DH_SK_DATABLOB = 404 | Private key **sk** in the DH algorithm.|
| CRYPTO_DH_PK_DATABLOB = 405 | Public key **pk** in the DH algorithm.|
| CRYPTO_ED25519_SK_DATABLOB = 501 | Private key **sk** in the Ed25519 algorithm.|
| CRYPTO_ED25519_PK_DATABLOB = 502 | Public key **pk** in the Ed25519 algorithm.|
| CRYPTO_X25519_SK_DATABLOB = 601 | Private key **sk** in the X25519 algorithm.|
| CRYPTO_X25519_PK_DATABLOB = 602 | Public key **pk** in the X25519 algorithm.|

### Crypto_EncodingType

```
enum Crypto_EncodingType
```

Description

Enumerates the encoding types.

**Since**: 12

| Enum Item| Description|
| -- | -- |
| CRYPTO_PEM = 0 | PEM.|
| CRYPTO_DER = 1 | DER.|

## Function Description

### OH_CryptoAsymKeyGenerator_Create()

```
OH_Crypto_ErrCode OH_CryptoAsymKeyGenerator_Create(const char *algoName, OH_CryptoAsymKeyGenerator **ctx)
```

Description

Creates an asymmetric key generator instance based on the specified algorithm.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const char *algoName |  Pointer the algorithm used to create a generator.<br>For example, **RSA1024\PRIMES_2**.| |
| [OH_CryptoAsymKeyGenerator](capi-oh-cryptoasymkeygenerator.md) **ctx |  Pointer to the asymmetric key generator context created.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) |  CRYPTO_SUCCESS = 0: Operation succeeded.<br>         CRYPTO_INVALID_PARAMS = 401: invalid parameter.<br>         CRYPTO_NOT_SUPPORTED = 801: The operation is not supported.<br>         CRYPTO_MEMORY_ERROR = 17620001: memory error.<br>         CRYPTO_OPERTION_ERROR = 17630001: Failed to call an API of a third-party algorithm library.|

### OH_CryptoAsymKeyGenerator_Generate()

```
OH_Crypto_ErrCode OH_CryptoAsymKeyGenerator_Generate(OH_CryptoAsymKeyGenerator *ctx, OH_CryptoKeyPair **keyCtx)
```

Description

Randomly generates an asymmetric key pair.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoAsymKeyGenerator](capi-oh-cryptoasymkeygenerator.md) *ctx |  Pointer to the asymmetric key generator instance.|
| [OH_CryptoKeyPair](capi-oh-cryptokeypair.md) **keyCtx |  Pointer to the asymmetric key pair instance created.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) |  CRYPTO_SUCCESS = 0: Operation succeeded.<br>         CRYPTO_INVALID_PARAMS = 401: invalid parameter.<br>         CRYPTO_NOT_SUPPORTED = 801: The operation is not supported.<br>         CRYPTO_MEMORY_ERROR = 17620001: memory error.<br>         CRYPTO_OPERTION_ERROR = 17630001: Failed to call an API of a third-party algorithm library.|

### OH_CryptoAsymKeyGenerator_Convert()

```
OH_Crypto_ErrCode OH_CryptoAsymKeyGenerator_Convert(OH_CryptoAsymKeyGenerator *ctx, Crypto_EncodingType type,Crypto_DataBlob *pubKeyData, Crypto_DataBlob *priKeyData, OH_CryptoKeyPair **keyCtx)
```

Description

Converts asymmetric key data into a key pair.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoAsymKeyGenerator](capi-oh-cryptoasymkeygenerator.md) *ctx |  Pointer to the asymmetric key generator instance.|
| [Crypto_EncodingType](#crypto_encodingtype) type | Pointer to the encoding format.|
| [Crypto_DataBlob](capi-crypto-datablob.md) *pubKeyData |  Pointer to the public key data to convert.|
| [Crypto_DataBlob](capi-crypto-datablob.md) *priKeyData |  Pointer to the private key data to convert.|
| [OH_CryptoKeyPair](capi-oh-cryptokeypair.md) **keyCtx |  Pointer to the asymmetric key pair instance created.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) |  CRYPTO_SUCCESS = 0: Operation succeeded.<br>         CRYPTO_INVALID_PARAMS = 401: invalid parameter.<br>         CRYPTO_NOT_SUPPORTED = 801: The operation is not supported.<br>         CRYPTO_MEMORY_ERROR = 17620001: memory error.<br>         CRYPTO_OPERTION_ERROR = 17630001: Failed to call an API of a third-party algorithm library.|

### OH_CryptoAsymKeyGenerator_GetAlgoName()

```
const char *OH_CryptoAsymKeyGenerator_GetAlgoName(OH_CryptoAsymKeyGenerator *ctx)
```

Description

Obtains the asymmetric key algorithm.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoAsymKeyGenerator](capi-oh-cryptoasymkeygenerator.md) *ctx | Pointer to the asymmetric key generator instance.|

**Returns**

| Type| Description|
| -- | -- |
| const char | Name of the asymmetric key algorithm obtained.|

### OH_CryptoAsymKeyGenerator_Destroy()

```
void OH_CryptoAsymKeyGenerator_Destroy(OH_CryptoAsymKeyGenerator *ctx)
```

Description

Destroys an asymmetric key generator instance.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoAsymKeyGenerator](capi-oh-cryptoasymkeygenerator.md) *ctx |  Pointer to the asymmetric key generator instance.|

### OH_CryptoKeyPair_Destroy()

```
void OH_CryptoKeyPair_Destroy(OH_CryptoKeyPair *keyCtx)
```

Description

Destroys an asymmetric key pair instance.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoKeyPair](capi-oh-cryptokeypair.md) *keyCtx |  Pointer to the key pair instance.|

### OH_CryptoKeyPair_GetPubKey()

```
OH_CryptoPubKey *OH_CryptoKeyPair_GetPubKey(OH_CryptoKeyPair *keyCtx)
```

Description

Obtains the public key from a key pair.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoKeyPair](capi-oh-cryptokeypair.md) *keyCtx | Pointer to the key pair instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_CryptoPubKey](capi-oh-cryptopubkey.md) | Public key obtained.|

### OH_CryptoPubKey_Encode()

```
OH_Crypto_ErrCode OH_CryptoPubKey_Encode(OH_CryptoPubKey *key, Crypto_EncodingType type,const char *encodingStandard, Crypto_DataBlob *out)
```

Description

Encodes the public key data in the specified format.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoPubKey](capi-oh-cryptopubkey.md) *key | Pointer to the public key data.|
| [Crypto_EncodingType](#crypto_encodingtype) type | Encoding type.|
| const char *encodingStandard |  Pointer to the encoding format.|
| [Crypto_DataBlob](capi-crypto-datablob.md) *out |  Pointer to the public key encoded in the specified format.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) |  CRYPTO_SUCCESS = 0: Operation succeeded.<br>         CRYPTO_INVALID_PARAMS = 401: invalid parameter.<br>         CRYPTO_NOT_SUPPORTED = 801: The operation is not supported.<br>         CRYPTO_MEMORY_ERROR = 17620001: memory error.<br>         CRYPTO_OPERTION_ERROR = 17630001: Failed to call an API of a third-party algorithm library.|

### OH_CryptoPubKey_GetParam()

```
OH_Crypto_ErrCode OH_CryptoPubKey_GetParam(OH_CryptoPubKey *key, CryptoAsymKey_ParamType item, Crypto_DataBlob *value)
```

Description

Obtains the specified parameter from a public key instance.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoPubKey](capi-oh-cryptopubkey.md) *key | Pointer to the public key data.|
| [CryptoAsymKey_ParamType](#cryptoasymkey_paramtype) item | Type of the asymmetric key parameter to obtain.|
| [Crypto_DataBlob](capi-crypto-datablob.md) *value |  Pointer to the parameter value obtained.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) |  CRYPTO_SUCCESS = 0: Operation succeeded.<br>         CRYPTO_INVALID_PARAMS = 401: invalid parameter.<br>         CRYPTO_NOT_SUPPORTED = 801: The operation is not supported.<br>         CRYPTO_MEMORY_ERROR = 17620001: memory error.<br>         CRYPTO_OPERTION_ERROR = 17630001: Failed to call an API of a third-party algorithm library.|
