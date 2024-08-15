# CryptoAsymKeyApi


## Overview

Provides APIs for asymmetric keys.

**Since**: 12


## Summary


### Files

| Name | Description |
| -------- | -------- |
| [crypto_asym_key.h](crypto__asym__key_8h.md) | Defines APIs for asymmetric keys. |


### Types

| Name | Description |
| -------- | -------- |
| typedef struct [OH_CryptoKeyPair](#oh_cryptokeypair) [OH_CryptoKeyPair](#oh_cryptokeypair) | Defines a struct for an asymmetric key pair. |
| typedef struct [OH_CryptoPubKey](#oh_cryptopubkey) [OH_CryptoPubKey](#oh_cryptopubkey) | Defines a struct for the public key in an asymmetric key pair. |
| typedef struct [OH_CryptoAsymKeyGenerator](#oh_cryptoasymkeygenerator) [OH_CryptoAsymKeyGenerator](#oh_cryptoasymkeygenerator) | Defines a struct for an asymmetric key generator. |


### Enums

| Name | Description |
| -------- | -------- |
| [CryptoAsymKey_ParamType](#cryptoasymkey_paramtype) {<br>CRYPTO_DSA_P_DATABLOB = 101, CRYPTO_DSA_Q_DATABLOB = 102,<br>CRYPTO_DSA_G_DATABLOB = 103, CRYPTO_DSA_SK_DATABLOB = 104,<br>CRYPTO_DSA_PK_DATABLOB = 105, CRYPTO_ECC_FP_P_DATABLOB = 201,<br>CRYPTO_ECC_A_DATABLOB = 202, CRYPTO_ECC_B_DATABLOB = 203,<br>CRYPTO_ECC_G_X_DATABLOB = 204, CRYPTO_ECC_G_Y_DATABLOB = 205,<br>CRYPTO_ECC_N_DATABLOB = 206, CRYPTO_ECC_H_INT = 207,<br>CRYPTO_ECC_SK_DATABLOB = 208, CRYPTO_ECC_PK_X_DATABLOB = 209,<br>CRYPTO_ECC_PK_Y_DATABLOB = 210, CRYPTO_ECC_FIELD_TYPE_STR = 211,<br>CRYPTO_ECC_FIELD_SIZE_INT = 212, CRYPTO_ECC_CURVE_NAME_STR = 213,<br>CRYPTO_RSA_N_DATABLOB = 301, CRYPTO_RSA_D_DATABLOB = 302,<br>CRYPTO_RSA_E_DATABLOB = 303, CRYPTO_DH_P_DATABLOB = 401,<br>CRYPTO_DH_G_DATABLOB = 402, CRYPTO_DH_L_NUM = 403,<br>CRYPTO_DH_SK_DATABLOB = 404, CRYPTO_DH_PK_DATABLOB = 405,<br>CRYPTO_ED25519_SK_DATABLOB = 501, CRYPTO_ED25519_PK_DATABLOB = 502,<br>CRYPTO_X25519_SK_DATABLOB = 601, CRYPTO_X25519_PK_DATABLOB = 602<br>} | Enumerates the types of the asymmetric key parameters. |
| [Crypto_EncodingType](#crypto_encodingtype) { CRYPTO_PEM = 0, CRYPTO_DER = 1 } | Enumerates the encoding types. |


### Functions

| Name | Description |
| -------- | -------- |
| [OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode) [OH_CryptoAsymKeyGenerator_Create](#oh_cryptoasymkeygenerator_create) (const char \*algoName, [OH_CryptoAsymKeyGenerator](#oh_cryptoasymkeygenerator) \*\*ctx) | Creates an asymmetric key generator instance based on the specified algorithm. |
| [OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode) [OH_CryptoAsymKeyGenerator_Generate](#oh_cryptoasymkeygenerator_generate) ([OH_CryptoAsymKeyGenerator](#oh_cryptoasymkeygenerator) \*ctx, [OH_CryptoKeyPair](#oh_cryptokeypair) \*\*keyCtx) | Randomly generates an asymmetric key pair. |
| [OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode) [OH_CryptoAsymKeyGenerator_Convert](#oh_cryptoasymkeygenerator_convert) ([OH_CryptoAsymKeyGenerator](#oh_cryptoasymkeygenerator) \*ctx, [Crypto_EncodingType](#crypto_encodingtype) type, [Crypto_DataBlob](_crypto___data_blob.md) \*pubKeyData, [Crypto_DataBlob](_crypto___data_blob.md) \*priKeyData, [OH_CryptoKeyPair](#oh_cryptokeypair) \*\*keyCtx) | Converts asymmetric key data into a key pair. |
| const char \* [OH_CryptoAsymKeyGenerator_GetAlgoName](#oh_cryptoasymkeygenerator_getalgoname) ([OH_CryptoAsymKeyGenerator](#oh_cryptoasymkeygenerator) \*ctx) | Obtains the asymmetric key algorithm. |
| void [OH_CryptoAsymKeyGenerator_Destroy](#oh_cryptoasymkeygenerator_destroy) ([OH_CryptoAsymKeyGenerator](#oh_cryptoasymkeygenerator) \*ctx) | Destroys an asymmetric key generator instance. |
| void [OH_CryptoKeyPair_Destroy](#oh_cryptokeypair_destroy) ([OH_CryptoKeyPair](#oh_cryptokeypair) \*keyCtx) | Destroys an asymmetric key pair instance. |
| [OH_CryptoPubKey](#oh_cryptopubkey) \* [OH_CryptoKeyPair_GetPubKey](#oh_cryptokeypair_getpubkey) ([OH_CryptoKeyPair](#oh_cryptokeypair) \*keyCtx) | Obtains the public key instance from a key pair. |
| [OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode) [OH_CryptoPubKey_Encode](#oh_cryptopubkey_encode) ([OH_CryptoPubKey](#oh_cryptopubkey) \*key, [Crypto_EncodingType](#crypto_encodingtype) type, const char \*encodingStandard, [Crypto_DataBlob](_crypto___data_blob.md) \*out) | Encodes the public key data in the specified format. |
| [OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode) [OH_CryptoPubKey_GetParam](#oh_cryptopubkey_getparam) ([OH_CryptoPubKey](#oh_cryptopubkey) \*key, [CryptoAsymKey_ParamType](#cryptoasymkey_paramtype) item, [Crypto_DataBlob](_crypto___data_blob.md) \*value) | Obtains the specified parameter from a public key instance. |


## Type Description


### OH_CryptoAsymKeyGenerator

```
typedef struct OH_CryptoAsymKeyGenerator OH_CryptoAsymKeyGenerator
```

**Description**

Defines a struct for an asymmetric key generator.

**Since**: 12


### OH_CryptoKeyPair

```
typedef struct OH_CryptoKeyPair OH_CryptoKeyPair
```

**Description**

Defines a struct for an asymmetric key pair.

**Since**: 12


### OH_CryptoPubKey

```
typedef struct OH_CryptoPubKey OH_CryptoPubKey
```

**Description**

Defines a struct for the public key in an asymmetric key pair.

**Since**: 12


## Enum Description


### Crypto_EncodingType

```
enum Crypto_EncodingType
```

**Description**

Enumerates the encoding types.

**Since**: 12

| Enum | Description |
| -------- | -------- |
| CRYPTO_PEM | PEM. |
| CRYPTO_DER | DER. |


### CryptoAsymKey_ParamType

```
enum CryptoAsymKey_ParamType
```

**Description**

Enumerates the types of the asymmetric key parameters.

**Since**: 12

| Enum | Description |
| -------- | -------- |
| CRYPTO_DSA_P_DATABLOB | Prime modulus **p** in the DSA algorithm. |
| CRYPTO_DSA_Q_DATABLOB | Parameter **q**, prime factor of (p – 1) in the DSA algorithm. |
| CRYPTO_DSA_G_DATABLOB | Parameter **g** in the DSA algorithm. |
| CRYPTO_DSA_SK_DATABLOB | Private key **sk** in the DSA algorithm. |
| CRYPTO_DSA_PK_DATABLOB | Public key **pk** in the DSA algorithm. |
| CRYPTO_ECC_FP_P_DATABLOB | Prime number **p** in the **Fp** field of the elliptic curve in the ECC algorithm. |
| CRYPTO_ECC_A_DATABLOB | First coefficient **a** of the elliptic curve in the ECC algorithm. |
| CRYPTO_ECC_B_DATABLOB | Second coefficient **b** of the elliptic curve in the ECC algorithm. |
| CRYPTO_ECC_G_X_DATABLOB | X coordinate of the base point **g** in the ECC algorithm. |
| CRYPTO_ECC_G_Y_DATABLOB | Y coordinate of the base point **g** in the ECC algorithm. |
| CRYPTO_ECC_N_DATABLOB | Order **n** of the base point **g** in the ECC algorithm. |
| CRYPTO_ECC_H_INT | Cofactor **h** in the ECC algorithm. |
| CRYPTO_ECC_SK_DATABLOB | Private key **sk** in the ECC algorithm. |
| CRYPTO_ECC_PK_X_DATABLOB | X coordinate of the public key **pk** (a point on the elliptic curve) in the ECC algorithm. |
| CRYPTO_ECC_PK_Y_DATABLOB | Y coordinate of the public key **pk** (a point on the elliptic curve) in the ECC algorithm. |
| CRYPTO_ECC_FIELD_TYPE_STR | Elliptic curve field type in the ECC algorithm. Currently, only the **Fp** field is supported. |
| CRYPTO_ECC_FIELD_SIZE_INT | Size of the field in the ECC algorithm, in bits.<br>**NOTE**: The size of the **Fp** field is the length of the prime **p**, in bits. |
| CRYPTO_ECC_CURVE_NAME_STR | Standards for Efficient Cryptography Group (SECG) curve name in the ECC algorithm. |
| CRYPTO_RSA_N_DATABLOB | Modulus **n** in the RSA algorithm. |
| CRYPTO_RSA_D_DATABLOB | Private key **sk** (private key exponent **d**) in the RSA algorithm. |
| CRYPTO_RSA_E_DATABLOB | Public key **pk** (public key exponent **e**) in the RSA algorithm. |
| CRYPTO_DH_P_DATABLOB | Prime **p** in the DH algorithm. |
| CRYPTO_DH_G_DATABLOB | Parameter **g** in the DH algorithm. |
| CRYPTO_DH_L_NUM | Length of the private key in the DH algorithm, in bits. |
| CRYPTO_DH_SK_DATABLOB | Private key **sk** in the DH algorithm. |
| CRYPTO_DH_PK_DATABLOB | Public key **pk** in the DH algorithm. |
| CRYPTO_ED25519_SK_DATABLOB | Private key **sk** in the Ed25519 algorithm. |
| CRYPTO_ED25519_PK_DATABLOB | Public key **pk** in the Ed25519 algorithm. |
| CRYPTO_X25519_SK_DATABLOB | Private key **sk** in the X25519 algorithm. |
| CRYPTO_X25519_PK_DATABLOB | Public key **pk** in the X25519 algorithm. |


## Function Description


### OH_CryptoAsymKeyGenerator_Convert()

```
OH_Crypto_ErrCode OH_CryptoAsymKeyGenerator_Convert (OH_CryptoAsymKeyGenerator *ctx, Crypto_EncodingType type, Crypto_DataBlob *pubKeyData, Crypto_DataBlob *priKeyData, OH_CryptoKeyPair **keyCtx )
```

**Description**

Converts binary data into an asymmetric key pair.

**Since**: 12

**Parameters**

| Name | Description |
| -------- | -------- |
| ctx | Pointer to the asymmetric key generator instance. |
| type | Encoding type. |
| pubKeyData | Pointer to the public key data to convert. |
| priKeyData | Pointer to the private key data to convert. |
| keyCtx | Pointer to the asymmetric key pair instance. |

**Returns**

[OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode):

**0**: The operation is successful.

**401**: Invalid parameters are detected.

**801**: The operation is not supported.

**17620001**: A memory error occurred.

**17630001**: Failed to call an API of a third-party algorithm library.


### OH_CryptoAsymKeyGenerator_Create()

```
OH_Crypto_ErrCode OH_CryptoAsymKeyGenerator_Create (const char *algoName, OH_CryptoAsymKeyGenerator **ctx )
```

**Description**

Creates an asymmetric key generator instance based on the specified algorithm.

**Since**: 12

**Parameters**

| Name | Description |
| -------- | -------- |
| algoName | Pointer to the algorithm used to create the asymmetric key generator instance. For example, **'RSA1024\|PRIMES_2'**. |
| ctx | Pointer to the asymmetric key generator instance created. |

**Returns**

[OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode):

**0**: The operation is successful.

**401**: Invalid parameters are detected.

**801**: The operation is not supported.

**17620001**: A memory error occurred.

**17630001**: Failed to call an API of a third-party algorithm library.


### OH_CryptoAsymKeyGenerator_Destroy()

```
void OH_CryptoAsymKeyGenerator_Destroy (OH_CryptoAsymKeyGenerator *ctx)
```

**Description**

Destroys an asymmetric key generator instance.

**Since**: 12

**Parameters**

| Name | Description |
| -------- | -------- |
| ctx | Pointer to the asymmetric key generator instance to destroy. |


### OH_CryptoAsymKeyGenerator_Generate()

```
OH_Crypto_ErrCode OH_CryptoAsymKeyGenerator_Generate (OH_CryptoAsymKeyGenerator *ctx, OH_CryptoKeyPair **keyCtx )
```

**Description**

Randomly generates an asymmetric key pair.

**Since**: 12

**Parameters**

| Name | Description |
| -------- | -------- |
| ctx | Pointer to the asymmetric key generator instance. |
| keyCtx | Pointer to the asymmetric key pair instance created. |

**Returns**

[OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode):

**0**: The operation is successful.

**401**: Invalid parameters are detected.

**801**: The operation is not supported.

**17620001**: A memory error occurred.

**17630001**: Failed to call an API of a third-party algorithm library.


### OH_CryptoAsymKeyGenerator_GetAlgoName()

```
const char* OH_CryptoAsymKeyGenerator_GetAlgoName (OH_CryptoAsymKeyGenerator *ctx)
```

**Description**

Obtains the asymmetric key algorithm.

**Since**: 12

**Parameters**

| Name | Description |
| -------- | -------- |
| ctx | Pointer to the asymmetric key generator instance. |

**Returns**

Name of the asymmetric key algorithm obtained.


### OH_CryptoKeyPair_Destroy()

```
void OH_CryptoKeyPair_Destroy (OH_CryptoKeyPair *keyCtx)
```

**Description**

Destroys an asymmetric key pair instance.

**Since**: 12

**Parameters**

| Name | Description |
| -------- | -------- |
| keyCtx | Pointer to the asymmetric key pair instance to destroy. |


### OH_CryptoKeyPair_GetPubKey()

```
OH_CryptoPubKey* OH_CryptoKeyPair_GetPubKey (OH_CryptoKeyPair *keyCtx)
```

**Description**

Obtains the public key from a key pair.

**Since**: 12

**Parameters**

| Name | Description |
| -------- | -------- |
| keyCtx | Pointer to the key pair instance. |

**Returns**

Public key obtained.


### OH_CryptoPubKey_Encode()

```
OH_Crypto_ErrCode OH_CryptoPubKey_Encode (OH_CryptoPubKey *key, Crypto_EncodingType type, const char *encodingStandard, Crypto_DataBlob *out )
```

**Description**

Encodes the public key data in the specified format.

**Since**: 12

**Parameters**

| Name | Description |
| -------- | -------- |
| key | Ponter to the public key data. |
| type | Encoding type. |
| encodingStandard | Encoding format. |
| out | Pointer to the public key encoded in the specified format. |

**Returns**

[OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode):

**0**: The operation is successful.

**401**: Invalid parameters are detected.

**801**: The operation is not supported.

**17620001**: A memory error occurred.

**17630001**: Failed to call an API of a third-party algorithm library.


### OH_CryptoPubKey_GetParam()

```
OH_Crypto_ErrCode OH_CryptoPubKey_GetParam (OH_CryptoPubKey *key, CryptoAsymKey_ParamType item, Crypto_DataBlob *value )
```

**Description**

Obtains the specified parameter from a public key instance.

**Since**: 12

**Parameters**

| Name | Description |
| -------- | -------- |
| key | Ponter to the public key data. |
| item | Type of the asymmetric key parameter to obtain. |
| value | Pointer to the parameter value obtained. |

**Returns**

[OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode): 

**0**: The operation is successful.

**401**: Invalid parameters are detected.

**801**: The operation is not supported.

**17620001**: A memory error occurred.

**17630001**: Failed to call an API of a third-party algorithm library.
