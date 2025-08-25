# crypto_asym_key.h

<!--Kit: Crypto Architecture Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--Designer: @lanming-->
<!--Tester: @PAFT-->
<!--Adviser: @zengyawen-->

## Overview

Defines APIs for asymmetric keys.

**Header file**: <CryptoArchitectureKit/crypto_asym_key.h>

**Library**: libohcrypto.so

**System capability**: SystemCapability.Security.CryptoFramework

**Since**: 12

**Related module**: [CryptoAsymKeyApi](capi-cryptoasymkeyapi.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_CryptoKeyPair](capi-cryptoasymkeyapi-oh-cryptokeypair.md) | OH_CryptoKeyPair | Defines a struct for an asymmetric key pair.|
| [OH_CryptoPubKey](capi-cryptoasymkeyapi-oh-cryptopubkey.md) | OH_CryptoPubKey | Defines a struct for the public key in an asymmetric key pair.|
| [OH_CryptoPrivKey](capi-cryptoasymkeyapi-oh-cryptoprivkey.md) | OH_CryptoPrivKey | Defines a struct for a private key.|
| [OH_CryptoAsymKeyGenerator](capi-cryptoasymkeyapi-oh-cryptoasymkeygenerator.md) | OH_CryptoAsymKeyGenerator | Defines a struct for an asymmetric key generator.|
| [OH_CryptoPrivKeyEncodingParams](capi-cryptoasymkeyapi-oh-cryptoprivkeyencodingparams.md) | OH_CryptoPrivKeyEncodingParams | Defines a struct for private key encoding parameters.|
| [OH_CryptoAsymKeySpec](capi-cryptoasymkeyapi-oh-cryptoasymkeyspec.md) | OH_CryptoAsymKeySpec | Defines a struct for asymmetric key specifications.|
| [OH_CryptoAsymKeyGeneratorWithSpec](capi-cryptoasymkeyapi-oh-cryptoasymkeygeneratorwithspec.md) | OH_CryptoAsymKeyGeneratorWithSpec | Defines a struct for an asymmetric key generator with specifications.|
| [OH_CryptoEcPoint](capi-cryptoasymkeyapi-oh-cryptoecpoint.md) | OH_CryptoEcPoint | Defines a struct for an EC point.|

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [CryptoAsymKey_ParamType](#cryptoasymkey_paramtype) | CryptoAsymKey_ParamType | Enumerates the types of the asymmetric key parameters.|
| [Crypto_EncodingType](#crypto_encodingtype) | Crypto_EncodingType | Enumerates the encoding types.|
| [CryptoPrivKeyEncoding_ParamType](#cryptoprivkeyencoding_paramtype) | CryptoPrivKeyEncoding_ParamType | Defines the parameter type for private key encoding.|
| [CryptoAsymKeySpec_Type](#cryptoasymkeyspec_type) | CryptoAsymKeySpec_Type | Defines the specification type of an asymmetric key.|

### Functions

| Name| Description|
| -- | -- |
| [OH_Crypto_ErrCode OH_CryptoAsymKeyGenerator_Create(const char *algoName, OH_CryptoAsymKeyGenerator **ctx)](#oh_cryptoasymkeygenerator_create) | Creates an asymmetric key generator instance based on the specified algorithm.|
| [OH_Crypto_ErrCode OH_CryptoAsymKeyGenerator_Generate(OH_CryptoAsymKeyGenerator *ctx, OH_CryptoKeyPair **keyCtx)](#oh_cryptoasymkeygenerator_generate) | Randomly generates an asymmetric key pair.|
| [OH_Crypto_ErrCode OH_CryptoAsymKeyGenerator_Convert(OH_CryptoAsymKeyGenerator *ctx, Crypto_EncodingType type,Crypto_DataBlob *pubKeyData, Crypto_DataBlob *priKeyData, OH_CryptoKeyPair **keyCtx)](#oh_cryptoasymkeygenerator_convert) | Converts asymmetric key data into a key pair.|
| [const char *OH_CryptoAsymKeyGenerator_GetAlgoName(OH_CryptoAsymKeyGenerator *ctx)](#oh_cryptoasymkeygenerator_getalgoname) | Obtains the asymmetric key algorithm.|
| [void OH_CryptoAsymKeyGenerator_Destroy(OH_CryptoAsymKeyGenerator *ctx)](#oh_cryptoasymkeygenerator_destroy) | Destroys an asymmetric key generator instance.|
| [void OH_CryptoKeyPair_Destroy(OH_CryptoKeyPair *keyCtx)](#oh_cryptokeypair_destroy) | Destroys an asymmetric key pair instance.|
| [OH_CryptoPubKey *OH_CryptoKeyPair_GetPubKey(OH_CryptoKeyPair *keyCtx)](#oh_cryptokeypair_getpubkey) | Obtains the public key instance from a key pair.|
| [OH_CryptoPrivKey *OH_CryptoKeyPair_GetPrivKey(OH_CryptoKeyPair *keyCtx)](#oh_cryptokeypair_getprivkey) | Obtains the private key of a key pair.|
| [OH_Crypto_ErrCode OH_CryptoPubKey_Encode(OH_CryptoPubKey *key, Crypto_EncodingType type,const char *encodingStandard, Crypto_DataBlob *out)](#oh_cryptopubkey_encode) | Encodes the public key data in the specified format.|
| [OH_Crypto_ErrCode OH_CryptoPubKey_GetParam(OH_CryptoPubKey *key, CryptoAsymKey_ParamType item, Crypto_DataBlob *value)](#oh_cryptopubkey_getparam) | Obtains the specified parameter from a public key instance.|
| [OH_Crypto_ErrCode OH_CryptoAsymKeyGenerator_SetPassword(OH_CryptoAsymKeyGenerator *ctx, const unsigned char *password,uint32_t passwordLen)](#oh_cryptoasymkeygenerator_setpassword) | Sets the password of the asymmetric key generator context.|
| [OH_Crypto_ErrCode OH_CryptoPrivKeyEncodingParams_Create(OH_CryptoPrivKeyEncodingParams **ctx)](#oh_cryptoprivkeyencodingparams_create) | Creates private key encoding parameters.|
| [OH_Crypto_ErrCode OH_CryptoPrivKeyEncodingParams_SetParam(OH_CryptoPrivKeyEncodingParams *ctx,CryptoPrivKeyEncoding_ParamType type, Crypto_DataBlob *value)](#oh_cryptoprivkeyencodingparams_setparam) | Sets a private key encoding parameter.|
| [void OH_CryptoPrivKeyEncodingParams_Destroy(OH_CryptoPrivKeyEncodingParams *ctx)](#oh_cryptoprivkeyencodingparams_destroy) | Destroys a private key encoding parameter.|
| [OH_Crypto_ErrCode OH_CryptoPrivKey_Encode(OH_CryptoPrivKey *key, Crypto_EncodingType type,const char *encodingStandard, OH_CryptoPrivKeyEncodingParams *params, Crypto_DataBlob *out)](#oh_cryptoprivkey_encode) | Obtains the specified parameter from a private key instance.|
| [OH_Crypto_ErrCode OH_CryptoPrivKey_GetParam(OH_CryptoPrivKey *key, CryptoAsymKey_ParamType item,Crypto_DataBlob *value)](#oh_cryptoprivkey_getparam) | Obtains the specified parameter of a private key.|
| [OH_Crypto_ErrCode OH_CryptoAsymKeySpec_GenEcCommonParamsSpec(const char *curveName, OH_CryptoAsymKeySpec **spec)](#oh_cryptoasymkeyspec_geneccommonparamsspec) | Generates EC common parameter specifications.|
| [OH_Crypto_ErrCode OH_CryptoAsymKeySpec_GenDhCommonParamsSpec(int pLen, int skLen, OH_CryptoAsymKeySpec **spec)](#oh_cryptoasymkeyspec_gendhcommonparamsspec) | Generates DH common parameter specifications.|
| [OH_Crypto_ErrCode OH_CryptoAsymKeySpec_Create(const char *algoName, CryptoAsymKeySpec_Type type,OH_CryptoAsymKeySpec **spec)](#oh_cryptoasymkeyspec_create) | Creates asymmetric key specifications based on the given algorithm name and specification type.|
| [OH_Crypto_ErrCode OH_CryptoAsymKeySpec_SetParam(OH_CryptoAsymKeySpec *spec, CryptoAsymKey_ParamType type,Crypto_DataBlob *value)](#oh_cryptoasymkeyspec_setparam) | Sets the specified parameters for asymmetric key specifications.|
| [OH_Crypto_ErrCode OH_CryptoAsymKeySpec_SetCommonParamsSpec(OH_CryptoAsymKeySpec *spec,OH_CryptoAsymKeySpec *commonParamsSpec)](#oh_cryptoasymkeyspec_setcommonparamsspec) | Sets the common parameter specifications for asymmetric key specifications.|
| [OH_Crypto_ErrCode OH_CryptoAsymKeySpec_GetParam(OH_CryptoAsymKeySpec *spec, CryptoAsymKey_ParamType type,Crypto_DataBlob *value)](#oh_cryptoasymkeyspec_getparam) | Obtains the specified parameters for asymmetric key specifications.|
| [void OH_CryptoAsymKeySpec_Destroy(OH_CryptoAsymKeySpec *spec)](#oh_cryptoasymkeyspec_destroy) | Destroys asymmetric key specifications.|
| [OH_Crypto_ErrCode OH_CryptoAsymKeyGeneratorWithSpec_Create(OH_CryptoAsymKeySpec *keySpec,OH_CryptoAsymKeyGeneratorWithSpec **generator)](#oh_cryptoasymkeygeneratorwithspec_create) | Creates a struct for an asymmetric key generator with specifications.|
| [OH_Crypto_ErrCode OH_CryptoAsymKeyGeneratorWithSpec_GenKeyPair(OH_CryptoAsymKeyGeneratorWithSpec *generator,OH_CryptoKeyPair **keyPair)](#oh_cryptoasymkeygeneratorwithspec_genkeypair) | Generates a key pair based on asymmetric key specifications.|
| [void OH_CryptoAsymKeyGeneratorWithSpec_Destroy(OH_CryptoAsymKeyGeneratorWithSpec *generator)](#oh_cryptoasymkeygeneratorwithspec_destroy) | Destroys a struct for an asymmetric key generator with specifications.|
| [OH_Crypto_ErrCode OH_CryptoEcPoint_Create(const char *curveName, Crypto_DataBlob *ecKeyData, OH_CryptoEcPoint **point)](#oh_cryptoecpoint_create) | Creates an EC point.|
| [OH_Crypto_ErrCode OH_CryptoEcPoint_GetCoordinate(OH_CryptoEcPoint *point, Crypto_DataBlob *x, Crypto_DataBlob *y)](#oh_cryptoecpoint_getcoordinate) | Obtains the X and Y coordinates of an EC point.|
| [OH_Crypto_ErrCode OH_CryptoEcPoint_SetCoordinate(OH_CryptoEcPoint *point, Crypto_DataBlob *x, Crypto_DataBlob *y)](#oh_cryptoecpoint_setcoordinate) | Sets the X and Y coordinates of an EC point.|
| [OH_Crypto_ErrCode OH_CryptoEcPoint_Encode(OH_CryptoEcPoint *point, const char *format, Crypto_DataBlob *out)](#oh_cryptoecpoint_encode) | Encodes an EC point in a specified format.|
| [void OH_CryptoEcPoint_Destroy(OH_CryptoEcPoint *point)](#oh_cryptoecpoint_destroy) | Destroys an EC point.|

## Enum Description

### CryptoAsymKey_ParamType

```
enum CryptoAsymKey_ParamType
```

**Description**

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

**Description**

Enumerates the encoding types.

**Since**: 12

| Enum Item| Description|
| -- | -- |
| CRYPTO_PEM = 0 | PEM.|
| CRYPTO_DER = 1 | DER.|

### CryptoPrivKeyEncoding_ParamType

```
enum CryptoPrivKeyEncoding_ParamType
```

**Description**

Defines the parameter type for private key encoding.

**Since**: 20

| Enum Item| Description|
| -- | -- |
| CRYPTO_PRIVATE_KEY_ENCODING_PASSWORD_STR = 0 | Password string.|
| CRYPTO_PRIVATE_KEY_ENCODING_SYMMETRIC_CIPHER_STR = 1 | Symmetric cipher string.|

### CryptoAsymKeySpec_Type

```
enum CryptoAsymKeySpec_Type
```

**Description**

Defines the specification type of an asymmetric key.

**Since**: 20

| Enum Item| Description|
| -- | -- |
| CRYPTO_ASYM_KEY_COMMON_PARAMS_SPEC = 0 | Common parameter specifications.|
| CRYPTO_ASYM_KEY_PRIVATE_KEY_SPEC = 1 | Private key specifications.|
| CRYPTO_ASYM_KEY_PUBLIC_KEY_SPEC = 2 | Public key specifications.|
| CRYPTO_ASYM_KEY_KEY_PAIR_SPEC = 3 | Key pair specifications.|


## Function Description

### OH_CryptoAsymKeyGenerator_Create()

```
OH_Crypto_ErrCode OH_CryptoAsymKeyGenerator_Create(const char *algoName, OH_CryptoAsymKeyGenerator **ctx)
```

**Description**

Creates an asymmetric key generator instance based on the specified algorithm.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const char *algoName | Pointer the algorithm used to create a generator.<br> For example, **'RSA1024\|PRIMES_2'**.| |
| [OH_CryptoAsymKeyGenerator](capi-cryptoasymkeyapi-oh-cryptoasymkeygenerator.md) **ctx | Pointer to the asymmetric key generator context created.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | **CRYPTO_SUCCESS**: The operation is successful.<br>         **CRYPTO_INVALID_PARAMS**: A parameter is invalid.<br>         **CRYPTO_NOT_SUPPORTED**: The operation is not supported.<br>         **CRYPTO_MEMORY_ERROR**: A memory error occurs.<br>         **CRYPTO_OPERTION_ERROR**: Failed to call an API of a third-party algorithm library.|

### OH_CryptoAsymKeyGenerator_Generate()

```
OH_Crypto_ErrCode OH_CryptoAsymKeyGenerator_Generate(OH_CryptoAsymKeyGenerator *ctx, OH_CryptoKeyPair **keyCtx)
```

**Description**

Randomly generates an asymmetric key pair.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoAsymKeyGenerator](capi-cryptoasymkeyapi-oh-cryptoasymkeygenerator.md) *ctx | Pointer to the asymmetric key generator instance.|
| [OH_CryptoKeyPair](capi-cryptoasymkeyapi-oh-cryptokeypair.md) **keyCtx | Pointer to the asymmetric key pair instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | **CRYPTO_SUCCESS**: The operation is successful.<br>         **CRYPTO_INVALID_PARAMS**: A parameter is invalid.<br>         **CRYPTO_NOT_SUPPORTED**: The operation is not supported.<br>         **CRYPTO_MEMORY_ERROR**: A memory error occurs.<br>         **CRYPTO_OPERTION_ERROR**: Failed to call an API of a third-party algorithm library.|

### OH_CryptoAsymKeyGenerator_Convert()

```
OH_Crypto_ErrCode OH_CryptoAsymKeyGenerator_Convert(OH_CryptoAsymKeyGenerator *ctx, Crypto_EncodingType type,Crypto_DataBlob *pubKeyData, Crypto_DataBlob *priKeyData, OH_CryptoKeyPair **keyCtx)
```

**Description**

Converts asymmetric key data into a key pair.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoAsymKeyGenerator](capi-cryptoasymkeyapi-oh-cryptoasymkeygenerator.md) *ctx | Pointer to the asymmetric key generator instance.|
| [Crypto_EncodingType](#crypto_encodingtype) type | Encoding type.|
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *pubKeyData | Pointer to the public key data to convert.|
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *priKeyData | Pointer to the private key data to convert.|
| [OH_CryptoKeyPair](capi-cryptoasymkeyapi-oh-cryptokeypair.md) **keyCtx | Pointer to the asymmetric key pair instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | **CRYPTO_SUCCESS**: The operation is successful.<br>         **CRYPTO_INVALID_PARAMS**: A parameter is invalid.<br>         **CRYPTO_NOT_SUPPORTED**: The operation is not supported.<br>         **CRYPTO_MEMORY_ERROR**: A memory error occurs.<br>         **CRYPTO_OPERTION_ERROR**: Failed to call an API of a third-party algorithm library.|

### OH_CryptoAsymKeyGenerator_GetAlgoName()

```
const char *OH_CryptoAsymKeyGenerator_GetAlgoName(OH_CryptoAsymKeyGenerator *ctx)
```

**Description**

Obtains the asymmetric key algorithm.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoAsymKeyGenerator](capi-cryptoasymkeyapi-oh-cryptoasymkeygenerator.md) *ctx | Pointer to the asymmetric key generator instance.|

**Returns**

| Type| Description|
| -- | -- |
| const char * | Name of the asymmetric key algorithm obtained.|

### OH_CryptoAsymKeyGenerator_Destroy()

```
void OH_CryptoAsymKeyGenerator_Destroy(OH_CryptoAsymKeyGenerator *ctx)
```

**Description**

Destroys an asymmetric key generator instance.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoAsymKeyGenerator](capi-cryptoasymkeyapi-oh-cryptoasymkeygenerator.md) *ctx | Pointer to the asymmetric key generator instance.|

### OH_CryptoKeyPair_Destroy()

```
void OH_CryptoKeyPair_Destroy(OH_CryptoKeyPair *keyCtx)
```

**Description**

Destroys an asymmetric key pair instance.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoKeyPair](capi-cryptoasymkeyapi-oh-cryptokeypair.md) *keyCtx | Pointer to the key pair instance.|

### OH_CryptoKeyPair_GetPubKey()

```
OH_CryptoPubKey *OH_CryptoKeyPair_GetPubKey(OH_CryptoKeyPair *keyCtx)
```

**Description**

Obtains the public key from a key pair.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoKeyPair](capi-cryptoasymkeyapi-oh-cryptokeypair.md) *keyCtx | Pointer to the key pair instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_CryptoPubKey](capi-cryptoasymkeyapi-oh-cryptopubkey.md) * | Public key obtained.|

### OH_CryptoKeyPair_GetPrivKey()

```
OH_CryptoPrivKey *OH_CryptoKeyPair_GetPrivKey(OH_CryptoKeyPair *keyCtx)
```

**Description**

Obtains the private key of a key pair.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoKeyPair](capi-cryptoasymkeyapi-oh-cryptokeypair.md) *keyCtx | Pointer to the key pair instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_CryptoPrivKey](capi-cryptoasymkeyapi-oh-cryptoprivkey.md) * | Private key obtained.|

### OH_CryptoPubKey_Encode()

```
OH_Crypto_ErrCode OH_CryptoPubKey_Encode(OH_CryptoPubKey *key, Crypto_EncodingType type,const char *encodingStandard, Crypto_DataBlob *out)
```

**Description**

Encodes the public key data in the specified format.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoPubKey](capi-cryptoasymkeyapi-oh-cryptopubkey.md) *key | Ponter to the public key data.|
| [Crypto_EncodingType](#crypto_encodingtype) type | Encoding type.|
| const char *encodingStandard | Encoding type.|
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *out | Pointer to the public key encoded in the specified format.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | **CRYPTO_SUCCESS**: The operation is successful.<br>         **CRYPTO_INVALID_PARAMS**: A parameter is invalid.<br>         **CRYPTO_NOT_SUPPORTED**: The operation is not supported.<br>         **CRYPTO_MEMORY_ERROR**: A memory error occurs.<br>         **CRYPTO_OPERTION_ERROR**: Failed to call an API of a third-party algorithm library.|

### OH_CryptoPubKey_GetParam()

```
OH_Crypto_ErrCode OH_CryptoPubKey_GetParam(OH_CryptoPubKey *key, CryptoAsymKey_ParamType item, Crypto_DataBlob *value)
```

**Description**

Obtains the specified parameter from a public key instance.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoPubKey](capi-cryptoasymkeyapi-oh-cryptopubkey.md) *key | Ponter to the public key data.|
| [CryptoAsymKey_ParamType](#cryptoasymkey_paramtype) item | Type of the asymmetric key parameter to obtain.|
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *value | Pointer to the parameter value obtained.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | **CRYPTO_SUCCESS**: The operation is successful.<br>         **CRYPTO_INVALID_PARAMS**: A parameter is invalid.<br>         **CRYPTO_NOT_SUPPORTED**: The operation is not supported.<br>         **CRYPTO_MEMORY_ERROR**: A memory error occurs.<br>         **CRYPTO_OPERTION_ERROR**: Failed to call an API of a third-party algorithm library.|

### OH_CryptoAsymKeyGenerator_SetPassword()

```
OH_Crypto_ErrCode OH_CryptoAsymKeyGenerator_SetPassword(OH_CryptoAsymKeyGenerator *ctx, const unsigned char *password,uint32_t passwordLen)
```

**Description**

Sets the password of the asymmetric key generator context.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoAsymKeyGenerator](capi-cryptoasymkeyapi-oh-cryptoasymkeygenerator.md) *ctx | Pointer to the asymmetric encryption context.|
| const unsigned char *password | Pointer to the password.|
| uint32_t passwordLen | Password length.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | **CRYPTO_SUCCESS**: The operation is successful.<br>         **CRYPTO_NOT_SUPPORTED**: The operation is not supported.<br>         **CRYPTO_MEMORY_ERROR**: A memory error occurs.<br>         **CRYPTO_PARAMETER_CHECK_FAILED**: The parameter check failed.<br>         **CRYPTO_OPERTION_ERROR**: Failed to call an API of a third-party algorithm library.|

### OH_CryptoPrivKeyEncodingParams_Create()

```
OH_Crypto_ErrCode OH_CryptoPrivKeyEncodingParams_Create(OH_CryptoPrivKeyEncodingParams **ctx)
```

**Description**

Creates private key encoding parameters.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoPrivKeyEncodingParams](capi-cryptoasymkeyapi-oh-cryptoprivkeyencodingparams.md) **ctx | Pointer to the private key encoding parameters.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | **CRYPTO_SUCCESS**: The operation is successful.<br>         **CRYPTO_NOT_SUPPORTED**: The operation is not supported.<br>         **CRYPTO_MEMORY_ERROR**: A memory error occurs.<br>         **CRYPTO_PARAMETER_CHECK_FAILED**: The parameter check failed.<br>         **CRYPTO_OPERTION_ERROR**: Failed to call an API of a third-party algorithm library.|

### OH_CryptoPrivKeyEncodingParams_SetParam()

```
OH_Crypto_ErrCode OH_CryptoPrivKeyEncodingParams_SetParam(OH_CryptoPrivKeyEncodingParams *ctx,CryptoPrivKeyEncoding_ParamType type, Crypto_DataBlob *value)
```

**Description**

Sets a private key encoding parameter.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoPrivKeyEncodingParams](capi-cryptoasymkeyapi-oh-cryptoprivkeyencodingparams.md) *ctx | Pointer to the private key encoding parameters.|
| [CryptoPrivKeyEncoding_ParamType](#cryptoprivkeyencoding_paramtype) type | Parameter type for private key encoding.|
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *value | Pointer to the parameter values for private key encoding.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | **CRYPTO_SUCCESS**: The operation is successful.<br>         **CRYPTO_NOT_SUPPORTED**: The operation is not supported.<br>         **CRYPTO_MEMORY_ERROR**: A memory error occurs.<br>         **CRYPTO_PARAMETER_CHECK_FAILED**: The parameter check failed.<br>         **CRYPTO_OPERTION_ERROR**: Failed to call an API of a third-party algorithm library.|

### OH_CryptoPrivKeyEncodingParams_Destroy()

```
void OH_CryptoPrivKeyEncodingParams_Destroy(OH_CryptoPrivKeyEncodingParams *ctx)
```

**Description**

Destroys a private key encoding parameter.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoPrivKeyEncodingParams](capi-cryptoasymkeyapi-oh-cryptoprivkeyencodingparams.md) *ctx | Pointer to the private key encoding parameters.|

### OH_CryptoPrivKey_Encode()

```
OH_Crypto_ErrCode OH_CryptoPrivKey_Encode(OH_CryptoPrivKey *key, Crypto_EncodingType type,const char *encodingStandard, OH_CryptoPrivKeyEncodingParams *params, Crypto_DataBlob *out)
```

**Description**

Obtains the specified parameter from a private key instance.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoPrivKey](capi-cryptoasymkeyapi-oh-cryptoprivkey.md) *key | Pointer to the private key.|
| [Crypto_EncodingType](#crypto_encodingtype) type | Private key encoding type.|
| const char *encodingStandard | Pointer to the encoding standard,<br> for example, **PKCS8**.|
| [OH_CryptoPrivKeyEncodingParams](capi-cryptoasymkeyapi-oh-cryptoprivkeyencodingparams.md) *params | Pointer to the private key encoding parameters, which can be **NULL**. Set this parameter if you need to encrypt a private key.|
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *out | Pointer to the encoding output.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | **CRYPTO_SUCCESS**: The operation is successful.<br>         **CRYPTO_NOT_SUPPORTED**: The operation is not supported.<br>         **CRYPTO_MEMORY_ERROR**: A memory error occurs.<br>         **CRYPTO_PARAMETER_CHECK_FAILED**: The parameter check failed.<br>         **CRYPTO_OPERTION_ERROR**: Failed to call an API of a third-party algorithm library.|

### OH_CryptoPrivKey_GetParam()

```
OH_Crypto_ErrCode OH_CryptoPrivKey_GetParam(OH_CryptoPrivKey *key, CryptoAsymKey_ParamType item,Crypto_DataBlob *value)
```

**Description**

Obtains the specified parameter of a private key.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoPrivKey](capi-cryptoasymkeyapi-oh-cryptoprivkey.md) *key | Pointer to the private key.|
| [CryptoAsymKey_ParamType](#cryptoasymkey_paramtype) item | Type of the asymmetric key parameter to obtain.|
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *value | Pointer to the output data.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | **CRYPTO_SUCCESS**: The operation is successful.<br>         **CRYPTO_NOT_SUPPORTED**: The operation is not supported.<br>         **CRYPTO_MEMORY_ERROR**: A memory error occurs.<br>         **CRYPTO_PARAMETER_CHECK_FAILED**: The parameter check failed.<br>         **CRYPTO_OPERTION_ERROR**: Failed to call an API of a third-party algorithm library.|

### OH_CryptoAsymKeySpec_GenEcCommonParamsSpec()

```
OH_Crypto_ErrCode OH_CryptoAsymKeySpec_GenEcCommonParamsSpec(const char *curveName, OH_CryptoAsymKeySpec **spec)
```

**Description**

Generates EC common parameter specifications.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| const char *curveName | Pointer to the ECC curve name.|
| [OH_CryptoAsymKeySpec](capi-cryptoasymkeyapi-oh-cryptoasymkeyspec.md) **spec | Pointer to the EC common parameter specifications.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | **CRYPTO_SUCCESS**: The operation is successful.<br>         **CRYPTO_NOT_SUPPORTED**: The operation is not supported.<br>         **CRYPTO_MEMORY_ERROR**: A memory error occurs.<br>         **CRYPTO_PARAMETER_CHECK_FAILED**: The parameter check failed.<br>         **CRYPTO_OPERTION_ERROR**: Failed to call an API of a third-party algorithm library.|

### OH_CryptoAsymKeySpec_GenDhCommonParamsSpec()

```
OH_Crypto_ErrCode OH_CryptoAsymKeySpec_GenDhCommonParamsSpec(int pLen, int skLen, OH_CryptoAsymKeySpec **spec)
```

**Description**

Generates DH common parameter specifications.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| int pLen | Length of the prime number **p**, in bytes.|
| int skLen | Length of the private key, in bytes.|
| [OH_CryptoAsymKeySpec](capi-cryptoasymkeyapi-oh-cryptoasymkeyspec.md) **spec | Pointer to the DH common parameter specifications.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | **CRYPTO_SUCCESS**: The operation is successful.<br>         **CRYPTO_NOT_SUPPORTED**: The operation is not supported.<br>         **CRYPTO_MEMORY_ERROR**: A memory error occurs.<br>         **CRYPTO_PARAMETER_CHECK_FAILED**: The parameter check failed.<br>         **CRYPTO_OPERTION_ERROR**: Failed to call an API of a third-party algorithm library.|

### OH_CryptoAsymKeySpec_Create()

```
OH_Crypto_ErrCode OH_CryptoAsymKeySpec_Create(const char *algoName, CryptoAsymKeySpec_Type type,OH_CryptoAsymKeySpec **spec)
```

**Description**

Creates asymmetric key specifications based on the given algorithm name and specification type.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| const char *algoName | Pointer to the algorithm used to generate specifications.<br> For example, **'RSA'**.|
| [CryptoAsymKeySpec_Type](#cryptoasymkeyspec_type) type | Specification type of an asymmetric key.|
| [OH_CryptoAsymKeySpec](capi-cryptoasymkeyapi-oh-cryptoasymkeyspec.md) **spec | Pointer to the asymmetric key specifications.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | **CRYPTO_SUCCESS**: The operation is successful.<br>         **CRYPTO_NOT_SUPPORTED**: The operation is not supported.<br>         **CRYPTO_MEMORY_ERROR**: A memory error occurs.<br>         **CRYPTO_PARAMETER_CHECK_FAILED**: The parameter check failed.<br>         **CRYPTO_OPERTION_ERROR**: Failed to call an API of a third-party algorithm library.|

### OH_CryptoAsymKeySpec_SetParam()

```
OH_Crypto_ErrCode OH_CryptoAsymKeySpec_SetParam(OH_CryptoAsymKeySpec *spec, CryptoAsymKey_ParamType type,Crypto_DataBlob *value)
```

**Description**

Sets the specified parameters for asymmetric key specifications.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoAsymKeySpec](capi-cryptoasymkeyapi-oh-cryptoasymkeyspec.md) *spec | Pointer to the asymmetric key specifications.|
| [CryptoAsymKey_ParamType](#cryptoasymkey_paramtype) type | Type of the asymmetric key parameter to obtain.|
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *value | Pointer to the input data.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | **CRYPTO_SUCCESS**: The operation is successful.<br>         **CRYPTO_NOT_SUPPORTED**: The operation is not supported.<br>         **CRYPTO_MEMORY_ERROR**: A memory error occurs.<br>         **CRYPTO_PARAMETER_CHECK_FAILED**: The parameter check failed.<br>         **CRYPTO_OPERTION_ERROR**: Failed to call an API of a third-party algorithm library.|

### OH_CryptoAsymKeySpec_SetCommonParamsSpec()

```
OH_Crypto_ErrCode OH_CryptoAsymKeySpec_SetCommonParamsSpec(OH_CryptoAsymKeySpec *spec,OH_CryptoAsymKeySpec *commonParamsSpec)
```

**Description**

Sets the common parameter specifications for asymmetric key specifications.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoAsymKeySpec](capi-cryptoasymkeyapi-oh-cryptoasymkeyspec.md) *spec | Pointer to the asymmetric key specifications.|
| [OH_CryptoAsymKeySpec](capi-cryptoasymkeyapi-oh-cryptoasymkeyspec.md) *commonParamsSpec | Pointer to the common parameter specifications.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | **CRYPTO_SUCCESS**: The operation is successful.<br>         **CRYPTO_NOT_SUPPORTED**: The operation is not supported.<br>         **CRYPTO_MEMORY_ERROR**: A memory error occurs.<br>         **CRYPTO_PARAMETER_CHECK_FAILED**: The parameter check failed.<br>         **CRYPTO_OPERTION_ERROR**: Failed to call an API of a third-party algorithm library.|

### OH_CryptoAsymKeySpec_GetParam()

```
OH_Crypto_ErrCode OH_CryptoAsymKeySpec_GetParam(OH_CryptoAsymKeySpec *spec, CryptoAsymKey_ParamType type,Crypto_DataBlob *value)
```

**Description**

Obtains the specified parameters for asymmetric key specifications.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoAsymKeySpec](capi-cryptoasymkeyapi-oh-cryptoasymkeyspec.md) *spec | Pointer to the asymmetric key specifications.|
| [CryptoAsymKey_ParamType](#cryptoasymkey_paramtype) type | Type of the asymmetric key parameter to obtain.|
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *value | Pointer to the output data.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | **CRYPTO_SUCCESS**: The operation is successful.<br>         **CRYPTO_NOT_SUPPORTED**: The operation is not supported.<br>         **CRYPTO_MEMORY_ERROR**: A memory error occurs.<br>         **CRYPTO_PARAMETER_CHECK_FAILED**: The parameter check failed.<br>         **CRYPTO_OPERTION_ERROR**: Failed to call an API of a third-party algorithm library.|

### OH_CryptoAsymKeySpec_Destroy()

```
void OH_CryptoAsymKeySpec_Destroy(OH_CryptoAsymKeySpec *spec)
```

**Description**

Destroys asymmetric key specifications.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoAsymKeySpec](capi-cryptoasymkeyapi-oh-cryptoasymkeyspec.md) *spec | Pointer to the asymmetric key specifications.|

### OH_CryptoAsymKeyGeneratorWithSpec_Create()

```
OH_Crypto_ErrCode OH_CryptoAsymKeyGeneratorWithSpec_Create(OH_CryptoAsymKeySpec *keySpec,OH_CryptoAsymKeyGeneratorWithSpec **generator)
```

**Description**

Creates a struct for an asymmetric key generator with specifications.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoAsymKeySpec](capi-cryptoasymkeyapi-oh-cryptoasymkeyspec.md) *keySpec | Pointer to the asymmetric key specifications.|
| [OH_CryptoAsymKeyGeneratorWithSpec](capi-cryptoasymkeyapi-oh-cryptoasymkeygeneratorwithspec.md) **generator | Pointer to the asymmetric key generator with specifications.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | **CRYPTO_SUCCESS**: The operation is successful.<br>         **CRYPTO_NOT_SUPPORTED**: The operation is not supported.<br>         **CRYPTO_MEMORY_ERROR**: A memory error occurs.<br>         **CRYPTO_PARAMETER_CHECK_FAILED**: The parameter check failed.<br>         **CRYPTO_OPERTION_ERROR**: Failed to call an API of a third-party algorithm library.|

### OH_CryptoAsymKeyGeneratorWithSpec_GenKeyPair()

```
OH_Crypto_ErrCode OH_CryptoAsymKeyGeneratorWithSpec_GenKeyPair(OH_CryptoAsymKeyGeneratorWithSpec *generator,OH_CryptoKeyPair **keyPair)
```

**Description**

Generates a key pair based on asymmetric key specifications.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoAsymKeyGeneratorWithSpec](capi-cryptoasymkeyapi-oh-cryptoasymkeygeneratorwithspec.md) *generator | Pointer to the asymmetric key generator with specifications.|
| [OH_CryptoKeyPair](capi-cryptoasymkeyapi-oh-cryptokeypair.md) **keyPair | Pointer to the key pair.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | **CRYPTO_SUCCESS**: The operation is successful.<br>         **CRYPTO_NOT_SUPPORTED**: The operation is not supported.<br>         **CRYPTO_MEMORY_ERROR**: A memory error occurs.<br>         **CRYPTO_PARAMETER_CHECK_FAILED**: The parameter check failed.<br>         **CRYPTO_OPERTION_ERROR**: Failed to call an API of a third-party algorithm library.|

### OH_CryptoAsymKeyGeneratorWithSpec_Destroy()

```
void OH_CryptoAsymKeyGeneratorWithSpec_Destroy(OH_CryptoAsymKeyGeneratorWithSpec *generator)
```

**Description**

Destroys a struct for an asymmetric key generator with specifications.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoAsymKeyGeneratorWithSpec](capi-cryptoasymkeyapi-oh-cryptoasymkeygeneratorwithspec.md) *generator | Pointer to the asymmetric key generator with specifications.|

### OH_CryptoEcPoint_Create()

```
OH_Crypto_ErrCode OH_CryptoEcPoint_Create(const char *curveName, Crypto_DataBlob *ecKeyData, OH_CryptoEcPoint **point)
```

**Description**

Creates an EC point.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| const char *curveName | Pointer to the curve name.|
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *ecKeyData | Pointer to the EC point data, in **'04 \|\| x \|\| y'**, **'02 \|\| x'**, or **'03 \|\| x'** format.<br>| |  | |  | |  | |  If **ecKeyData** is **NULL**, an empty EC point specification is created.|
| [OH_CryptoEcPoint](capi-cryptoasymkeyapi-oh-cryptoecpoint.md) **point | Pointer to the EC point.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | **CRYPTO_SUCCESS**: The operation is successful.<br>         **CRYPTO_NOT_SUPPORTED**: The operation is not supported.<br>         **CRYPTO_MEMORY_ERROR**: A memory error occurs.<br>         **CRYPTO_PARAMETER_CHECK_FAILED**: The parameter check failed.<br>         **CRYPTO_OPERTION_ERROR**: Failed to call an API of a third-party algorithm library.|

### OH_CryptoEcPoint_GetCoordinate()

```
OH_Crypto_ErrCode OH_CryptoEcPoint_GetCoordinate(OH_CryptoEcPoint *point, Crypto_DataBlob *x, Crypto_DataBlob *y)
```

**Description**

Obtains the X and Y coordinates of an EC point.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoEcPoint](capi-cryptoasymkeyapi-oh-cryptoecpoint.md) *point | Pointer to the EC point.|
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *x | Pointer to the X coordinate of an EC point. The value can be **NULL**.|
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *y | Pointer to the Y coordinate of an EC point. The value can be **NULL**.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | **CRYPTO_SUCCESS**: The operation is successful.<br>         **CRYPTO_NOT_SUPPORTED**: The operation is not supported.<br>         **CRYPTO_MEMORY_ERROR**: A memory error occurs.<br>         **CRYPTO_PARAMETER_CHECK_FAILED**: The parameter check failed.<br>         **CRYPTO_OPERTION_ERROR**: Failed to call an API of a third-party algorithm library.|

### OH_CryptoEcPoint_SetCoordinate()

```
OH_Crypto_ErrCode OH_CryptoEcPoint_SetCoordinate(OH_CryptoEcPoint *point, Crypto_DataBlob *x, Crypto_DataBlob *y)
```

**Description**

Sets the X and Y coordinates of an EC point.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoEcPoint](capi-cryptoasymkeyapi-oh-cryptoecpoint.md) *point | Pointer to the EC point.|
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *x | Pointer to the X coordinate of the EC point.|
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *y | Pointer to the Y coordinate of the EC point.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | **CRYPTO_SUCCESS**: The operation is successful.<br>         **CRYPTO_NOT_SUPPORTED**: The operation is not supported.<br>         **CRYPTO_MEMORY_ERROR**: A memory error occurs.<br>         **CRYPTO_PARAMETER_CHECK_FAILED**: The parameter check failed.<br>         **CRYPTO_OPERTION_ERROR**: Failed to call an API of a third-party algorithm library.|

### OH_CryptoEcPoint_Encode()

```
OH_Crypto_ErrCode OH_CryptoEcPoint_Encode(OH_CryptoEcPoint *point, const char *format, Crypto_DataBlob *out)
```

**Description**

Encodes an EC point in a specified format.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoEcPoint](capi-cryptoasymkeyapi-oh-cryptoecpoint.md) *point | Pointer to the EC point.|
| const char *format | Pointer to the encoding format. The value can be **UNCOMPRESSED** or **COMPRESSED**.|
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *out | Pointer to the encoded EC point data.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | **CRYPTO_SUCCESS**: The operation is successful.<br>         **CRYPTO_NOT_SUPPORTED**: The operation is not supported.<br>         **CRYPTO_MEMORY_ERROR**: A memory error occurs.<br>         **CRYPTO_PARAMETER_CHECK_FAILED**: The parameter check failed.<br>         **CRYPTO_OPERTION_ERROR**: Failed to call an API of a third-party algorithm library.|

### OH_CryptoEcPoint_Destroy()

```
void OH_CryptoEcPoint_Destroy(OH_CryptoEcPoint *point)
```

**Description**

Destroys an EC point.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_CryptoEcPoint](capi-cryptoasymkeyapi-oh-cryptoecpoint.md) *point | Pointer to the EC point.|
