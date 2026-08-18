# @ohos.security.cryptoFramework (Crypto Framework)

<!--Kit: Crypto Architecture Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--Designer: @lanming-->
<!--Tester: @PAFT-->
<!--Adviser: @zengyawen-->

The **cryptoFramework** module provides APIs for cryptographic operations, shielding the underlying hardware and algorithm library.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
```

## Result

 Enumerates the operation results.

 **System capability**: SystemCapability.Security.CryptoFramework

| Name                                 |    Value  |   Description                        |
| ------------------------------------- | -------- | ---------------------------- |
| INVALID_PARAMS                        | 401      | Invalid parameter.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br> **Model restriction**:<br>API version 12+: This API can be used in both the stage and FA models.<br>API versions 9 to 11: This API can be used only in the stage model.               |
| NOT_SUPPORT                           | 801      | Unsupported operation.<br>**Atomic service API**: This API can be used in atomic services since API version 12.<br> **Model restriction**:<br>API version 12+: This API can be used in both the stage and FA models.<br>API versions 9 to 11: This API can be used only in the stage model.                |
| ERR_OUT_OF_MEMORY                     | 17620001 | Memory operation failed.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br> **Model restriction**:<br>API version 12+: This API can be used in both the stage and FA models.<br>API versions 9 to 11: This API can be used only in the stage model.                  |
| ERR_RUNTIME_ERROR                     | 17620002 | The **Native** object fails to be obtained or the parameter conversion fails.<br>**Atomic service API**: This API can be used in atomic services since API version 12.<br> **Model restriction**:<br>API version 12+: This API can be used in both the stage and FA models.<br>API versions 9 to 11: This API can be used only in the stage model.         |
| ERR_PARAMETER_CHECK_FAILED<sup>20+</sup>            | 17620003 | The parameter check failed.<br>**Atomic service API**: This API can be used in atomic services since API version 20.<br>**Model restriction**: This API can be used only in the stage model.           |
| ERR_INVALID_CALL          | 17620004 | Invalid function call.<br>**Since**: 26.0.0<br>**Atomic service API**: This API can be used in atomic services since API version 26.0.0.<br>**Model restriction**: This API can be used only in the stage model.         |
| ERR_CRYPTO_OPERATION                  | 17630001 | Incorrect password operation.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br> **Model restriction**:<br>API version 12+: This API can be used in both the stage and FA models.<br>API versions 9 to 11: This API can be used only in the stage model.  |

## DataBlob

Encapsulates binary data. The core field **data** is of the Uint8Array type.

 **Atomic service API**: This API can be used in atomic services since API version 11.

 **Model restriction**:
 - API version 12+: This API can be used in both the stage and FA models.
 - API versions 9 to 11: This API can be used only in the stage model.

 **System capability**: SystemCapability.Security.CryptoFramework

| Name| Type      | Read-Only| Optional| Description  |
| ---- | ---------- | ---- | ---- | ------ |
| data | Uint8Array | No  | No  | Binary data array.|

> **NOTE**
>
> The Uint8Array typed array represents an array of 8-bit unsigned integers.

## ParamsSpec

Encapsulates the parameters used for encryption or decryption. You need to construct its child class object and pass it to [init()](#init-1) for symmetric encryption or decryption.

It applies to the symmetric block cipher modes that require parameters such as the initialization vector (IV). If the IV is not required (for example, the ECB mode), pass in **null** to [init()](#init-1).

> **NOTE**
>
> An initialization vector (IV) is a byte sequence used to introduce randomness or uniqueness in symmetric encryption modes (such as CBC, CTR, OFB, CFB, GCM, CCM, and ChaCha20-Poly1305). It ensures that different ciphertexts are generated for the same plaintext under the same key.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Cipher
- API versions 9 to 11: SystemCapability.Security.CryptoFramework

| Name   | Type  | Read-Only| Optional| Description                                                        |
| ------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| algName | string | No  | No  | Algorithm for symmetric encryption or decryption. The value can be:<br> - **IvParamsSpec**: applicable to the CBC, CTR, OFB, and CFB modes.<br> - **GcmParamsSpec**: applicable to the GCM mode.<br> - **CcmParamsSpec**: applicable to the CCM mode.<br>- **AeadParamsSpec**: applicable to the AES-GCM, AES-CCM, SM4-GCM, and ChaCha20-Poly1305 algorithms.|

> **NOTE**
>
> The **params** parameter in [init()](#init-1) is of the **ParamsSpec** type (parent class). However, a child class object (such as [IvParamsSpec](#ivparamsspec)) needs to be passed in. When constructing the child class object, you must set **algName** for its parent class **ParamsSpec** to specify the child class object to be passed to **init()**.

## IvParamsSpec

Encapsulates the parameters for encryption or decryption using a block cipher mode that requires an IV. It is a child class of [ParamsSpec](#paramsspec) and used as a parameter in [init()](#init-1) for symmetric encryption or decryption.

This class is applicable to block cipher modes that require an IV, such as CBC, CTR, OFB, and CFB.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Cipher
- API versions 9 to 11: SystemCapability.Security.CryptoFramework

| Name| Type                 | Read-Only| Optional| Description                                                        |
| ---- | --------------------- | ---- | ---- | ------------------------------------------------------------ |
| iv   | [DataBlob](#datablob) | No  | No | Initialization vector (IV). The common lengths are as follows:<br>- In the CBC, CTR, OFB, or CFB mode of AES: The IV length is 16 bytes.<br>- In the CBC, OFB, or CFB mode of 3DES: The IV length is 8 bytes.<br>- In the CBC, CTR, OFB, or CFB mode of SM4<sup>10+</sup>: The IV length is 16 bytes.|

> **NOTE**
>
> Before passing a value to [init()](#init-1), specify **algName** for its parent class [ParamsSpec](#paramsspec).

## GcmParamsSpec

Encapsulates the parameters for encryption or decryption using the GCM AEAD mode that requires **IV**, **AAD**, and the authentication label. It is a child class of [ParamsSpec](#paramsspec) and used as a parameter in [init()](#init-1) for symmetric encryption or decryption.

**GcmParamsSpec** applies to the GCM mode.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Cipher
- API versions 9 to 11: SystemCapability.Security.CryptoFramework

| Name   | Type                 | Read-Only| Optional| Description                                                        |
| ------- | --------------------- | ---- | ---- | ------------------------------------------------------------ |
| iv      | [DataBlob](#datablob) | No  | No  | IV, which is of 1 to 128 bytes. A 12-byte IV is commonly used.                            |
| aad     | [DataBlob](#datablob) | No  | No  | AAD, which is of 0 to **INT_MAX** bytes.                            |
| authTag | [DataBlob](#datablob) | No  | No  | Authentication tag, which is of 16 bytes.<br>When GCM mode is used for encryption, you need to extract the last 16 bytes from the [DataBlob](#datablob) returned by [doFinal()](#dofinal) or [doFinalSync()](#dofinalsync12) and use them as **authTag** in **GcmParamsSpec** for [init()](#init-1) or [initSync()](#initsync12).|

> **NOTE**
>
> 1. Before passing a value to [init()](#init-1), specify **algName** for its parent class [ParamsSpec](#paramsspec).
> 2. If **aad** is not required or the **aad** length is 0, you can set its **data** attribute to an empty Uint8Array in the **aad: { data: new Uint8Array() }** format when constructing **GcmParamsSpec**.

## CcmParamsSpec

Encapsulates the parameters for encryption or decryption using the CCM AEAD mode that requires **IV**, **AAD**, and the authentication label. It is a child class of [ParamsSpec](#paramsspec) and used as a parameter in [init()](#init-1) for symmetric encryption or decryption.

**CcmParamsSpec** applies to the CCM mode.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Cipher
- API versions 9 to 11: SystemCapability.Security.CryptoFramework

| Name   | Type                 | Read-Only| Optional| Description                                                        |
| ------- | --------------------- | ---- | ---- | ------------------------------------------------------------ |
| iv      | [DataBlob](#datablob) | No  | No  | IV, which is of 7 bytes. If the length of the input **iv** parameter exceeds 7 bytes, the excess part will be truncated.                             |
| aad     | [DataBlob](#datablob) | No  | No  | AAD for encryption and decryption. The AAD value contains 1 to 2,048 bytes.                           |
| authTag | [DataBlob](#datablob) | No  | No  | Authentication tag, which is of 12 bytes.<br>When CCM mode is used for encryption, you need to extract the last 12 bytes from the [DataBlob](#datablob) returned by [doFinal()](#dofinal) or [doFinalSync()](#dofinalsync12) and use them as **authTag** in [CcmParamsSpec](#ccmparamsspec) for [init()](#init-1) or [initSync()](#initsync12).|

> **NOTE**
>
> Before passing a value to [init()](#init-1), specify **algName** for its parent class [ParamsSpec](#paramsspec).

## Poly1305ParamsSpec<sup>22+</sup>

Encapsulates the parameters for encryption or decryption using the ChaCha20-Poly1305 AEAD mode that requires **Nonce**, **AAD**, and the authentication label. It is a child class of [ParamsSpec](#paramsspec) and used as a parameter in [init()](#init-1) for symmetric encryption or decryption.

Applicable to the Poly1305 mode of [ChaCha20](../../security/CryptoArchitectureKit/crypto-sym-encrypt-decrypt-spec.md#chacha20).

**Atomic service API**: This API can be used in atomic services since API version 22.

**System capability**: SystemCapability.Security.CryptoFramework.Cipher

| Name   | Type                 | Read-Only| Optional| Description                                                        |
| ------- | --------------------- | ---- | ---- | ------------------------------------------------------------ |
| iv      | [DataBlob](#datablob) | No  | No  | Nonce, which is passed through the **iv** field. The length is 12 bytes.                             |
| aad     | [DataBlob](#datablob) | No  | No  | AAD for encryption and decryption.                            |
| authTag | [DataBlob](#datablob) | No  | No  | Authentication tag, which is of 16 bytes.|

> **NOTE**
>
> Before passing a value to [init()](#init-1), specify **algName** for its parent class [ParamsSpec](#paramsspec).
>
> When the Poly1305 mode is used for encryption, you need to extract the last 16 bytes from the [DataBlob](#datablob) returned by [doFinal()](#dofinal) or [doFinalSync()](#dofinalsync12) and use them as **authTag** in [Poly1305ParamsSpec](#poly1305paramsspec22) for [init()](#init-1) or [initSync()](#initsync12) during decryption.

## AeadParamsSpec

Describes parameters in [init()](#init-1) for symmetric encryption and decryption using authenticated encryption with association data (AEAD). It Inherits from [ParamsSpec](#paramsspec).

It is applicable to [AES](../../security/CryptoArchitectureKit/crypto-sym-encrypt-decrypt-spec.md#aes) in CCM and GCM modes, SM4 in GCM mode, and ChaCha20 in Poly1305 mode.

> **NOTE**
>
> When **AeadParamsSpec** is used for encryption:
> - If **tagLen** is specified during encryption, the same length must be specified during decryption.
> - Only one of [update](#update) and [doFinal](#dofinal) can be called for encryption or decryption in CCM mode. Each method can be called only once.
> - For AES in GCM mode and SM4 in GCM mode, **tagLen** can be set to **4**, **8**, **12**, **13**, **14**, **15**, or **16**. If this parameter is not specified, the default value **16** is used.
> - For AES in CCM mode, **tagLen** can be set to **4**, **6**, **8**, **10**, **12**, **14**, or **16**. If this parameter is not specified, the default value **12** is used.
> - For ChaCha20 in Poly1305 mode, **tagLen** can only be set to **16**.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.Security.CryptoFramework.Cipher

| Name   | Type                 | Read-Only| Optional| Description                                                        |
| ------- | --------------------- | ---- | ---- | ------------------------------------------------------------ |
| nonce      | Uint8Array | No  | No  | Nonce for encryption and decryption.<br>**NOTE**<br>For AES-CCM, the nonce length ranges from 7 to 13 bytes.<br>For AES-GCM, the nonce length ranges from 1 to 128 bytes. The recommended length is 12 bytes.<br>For SM4-GCM, the nonce length ranges from 1 to 128 bytes. The recommended length is 12 bytes.<br>For ChaCha20-Poly1305, the nonce length must be 12 bytes.    |
| authenticatedData     | Uint8Array | No  | Yes  | Additional authentication data specified.                            |
| tagLen | number | No  | Yes  | Length of the authentication label, in bytes.<br>During encryption, the label is added to the end of the ciphertext.<br>During decryption, the label should be at the end of the ciphertext.<br>The value must be an integer.<br>**NOTE**<br>For AES-CCM, the default value is **12**. The value can be **4**, **6**, **8**, **10**, **12**, **14**, or **16**.<br>For AES-GCM, the default value is **16**. The value can be **4**, **8**, **12**, **13**, **14**, **15**, or **16**.<br>For SM4-GCM, the default value is **16**. The value can be **4**, **8**, **12**, **13**, **14**, **15**, or **16**.<br>For ChaCha20-Poly1305, the default value is **16**. The value can be **16**.|

## CryptoMode

Enumerates the password operation modes for encryption and decryption.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Cipher
- API versions 9 to 11: SystemCapability.Security.CryptoFramework

| Name        | Value  | Description              |
| ------------ | ---- | ------------------ |
| ENCRYPT_MODE | 0    | Encryption.|
| DECRYPT_MODE | 1    | Decryption.|

## AsyKeySpecItem<sup>10+</sup>

Enumerates the asymmetric key parameters.

**Atomic service API**: This API can be used in atomic services since API version 12.

| Name        | Value  | Description            |
| ------------ | ---- | ---------------- |
| DSA_P_BN | 101 | Prime modulus **p** in the DSA algorithm.<br>**System capability**:<br>API versions 12+: SystemCapability.Security.CryptoFramework.Key.AsymKey<br>API versions 10 to 11: SystemCapability.Security.CryptoFramework|
| DSA_Q_BN | 102 | Parameter **q**, prime factor of (p – 1) in the DSA algorithm.<br>**System capability**:<br>API versions 12+: SystemCapability.Security.CryptoFramework.Key.AsymKey<br>API versions 10 to 11: SystemCapability.Security.CryptoFramework|
| DSA_G_BN | 103 | Parameter **g** in the DSA algorithm.<br>**System capability**:<br>API versions 12+: SystemCapability.Security.CryptoFramework.Key.AsymKey<br>API versions 10 to 11: SystemCapability.Security.CryptoFramework|
| DSA_SK_BN | 104 | Private key **sk** in the DSA algorithm.<br>**System capability**:<br>API versions 12+: SystemCapability.Security.CryptoFramework.Key.AsymKey<br>API versions 10 to 11: SystemCapability.Security.CryptoFramework|
| DSA_PK_BN | 105 | Public key **pk** in the DSA algorithm.<br>**System capability**:<br>API versions 12+: SystemCapability.Security.CryptoFramework.Key.AsymKey<br>API versions 10 to 11: SystemCapability.Security.CryptoFramework|
| ECC_FP_P_BN | 201 | Prime number **p** in the **Fp** field of the elliptic curve in the ECC algorithm.<br>**System capability**:<br>API versions 12+: SystemCapability.Security.CryptoFramework.Key.AsymKey<br>API versions 10 to 11: SystemCapability.Security.CryptoFramework|
| ECC_A_BN | 202 | First coefficient **a** of the elliptic curve in the ECC algorithm.<br>**System capability**:<br>API versions 12+: SystemCapability.Security.CryptoFramework.Key.AsymKey<br>API versions 10 to 11: SystemCapability.Security.CryptoFramework|
| ECC_B_BN | 203 | Second coefficient **b** of the elliptic curve in the ECC algorithm.<br>**System capability**:<br>API versions 12+: SystemCapability.Security.CryptoFramework.Key.AsymKey<br>API versions 10 to 11: SystemCapability.Security.CryptoFramework|
| ECC_G_X_BN | 204 | X coordinate of the base point **g** in the ECC algorithm.<br>**System capability**:<br>API versions 12+: SystemCapability.Security.CryptoFramework.Key.AsymKey<br>API versions 10 to 11: SystemCapability.Security.CryptoFramework|
| ECC_G_Y_BN | 205 | Y coordinate of the base point **g** in the ECC algorithm.<br>**System capability**:<br>API versions 12+: SystemCapability.Security.CryptoFramework.Key.AsymKey<br>API versions 10 to 11: SystemCapability.Security.CryptoFramework|
| ECC_N_BN | 206 | Order **n** of the base point **g** in the ECC algorithm.<br>**System capability**:<br>API versions 12+: SystemCapability.Security.CryptoFramework.Key.AsymKey<br>API versions 10 to 11: SystemCapability.Security.CryptoFramework|
| ECC_H_NUM | 207 | Cofactor **h** in the ECC algorithm.<br>**System capability**:<br>API versions 12+: SystemCapability.Security.CryptoFramework.Key.AsymKey<br>API versions 10 to 11: SystemCapability.Security.CryptoFramework|
| ECC_SK_BN | 208 | Private key **sk** in the ECC algorithm.<br>**System capability**:<br>API versions 12+: SystemCapability.Security.CryptoFramework.Key.AsymKey<br>API versions 10 to 11: SystemCapability.Security.CryptoFramework|
| ECC_PK_X_BN | 209 | X coordinate of the public key **pk** (a point on the elliptic curve) in the ECC algorithm.<br>**System capability**:<br>API versions 12+: SystemCapability.Security.CryptoFramework.Key.AsymKey<br>API versions 10 to 11: SystemCapability.Security.CryptoFramework|
| ECC_PK_Y_BN | 210 | Y coordinate of the public key **pk** (a point on the elliptic curve) in the ECC algorithm.<br>**System capability**:<br>API versions 12+: SystemCapability.Security.CryptoFramework.Key.AsymKey<br>API versions 10 to 11: SystemCapability.Security.CryptoFramework|
| ECC_FIELD_TYPE_STR | 211 | Elliptic curve field type in the ECC algorithm. Currently, only the **Fp** field is supported.<br>**System capability**:<br>API versions 12+: SystemCapability.Security.CryptoFramework.Key.AsymKey<br>API versions 10 to 11: SystemCapability.Security.CryptoFramework|
| ECC_FIELD_SIZE_NUM | 212 | Size of the field in the ECC algorithm, in bits.<br>Note: The size of the **Fp** field is the length of the prime **p**, in bits.<br>**System capability**:<br>API versions 12+: SystemCapability.Security.CryptoFramework.Key.AsymKey<br>API versions 10 to 11: SystemCapability.Security.CryptoFramework|
| ECC_CURVE_NAME_STR | 213 | Standards for Efficient Cryptography Group (SECG) curve name in the ECC algorithm.<br>**System capability**:<br>API versions 12+: SystemCapability.Security.CryptoFramework.Key.AsymKey<br>API versions 10 to 11: SystemCapability.Security.CryptoFramework|
| RSA_N_BN | 301 | Modulus **n** in the RSA algorithm.<br>**System capability**:<br>API versions 12+: SystemCapability.Security.CryptoFramework.Key.AsymKey<br>API versions 10 to 11: SystemCapability.Security.CryptoFramework|
| RSA_SK_BN | 302 | Private key **sk** (private key exponent **d**) in the RSA algorithm.<br>**System capability**:<br>API versions 12+: SystemCapability.Security.CryptoFramework.Key.AsymKey<br>API versions 10 to 11: SystemCapability.Security.CryptoFramework|
| RSA_PK_BN | 303 | Public key **pk** (public key exponent **e**) in the RSA algorithm.<br>**System capability**:<br>API versions 12+: SystemCapability.Security.CryptoFramework.Key.AsymKey<br>API versions 10 to 11: SystemCapability.Security.CryptoFramework|
| DH_P_BN<sup>11+</sup> | 401 | Prime **p** in the DH algorithm.<br>**System capability**:<br>API versions 12+: SystemCapability.Security.CryptoFramework.Key.AsymKey<br>API version 11: SystemCapability.Security.CryptoFramework|
| DH_G_BN<sup>11+</sup> | 402 | Parameter **g** in the DH algorithm.<br>**System capability**:<br>API versions 12+: SystemCapability.Security.CryptoFramework.Key.AsymKey<br>API version 11: SystemCapability.Security.CryptoFramework|
| DH_L_NUM<sup>11+</sup> | 403 | Length of the private key in the DH algorithm, in bits.<br>**System capability**:<br>API versions 12+: SystemCapability.Security.CryptoFramework.Key.AsymKey<br>API version 11: SystemCapability.Security.CryptoFramework|
| DH_SK_BN<sup>11+</sup> | 404 | Private key **sk** in the DH algorithm.<br>**System capability**:<br>API versions 12+: SystemCapability.Security.CryptoFramework.Key.AsymKey<br>API version 11: SystemCapability.Security.CryptoFramework|
| DH_PK_BN<sup>11+</sup> | 405 | Public key **pk** in the DH algorithm.<br>**System capability**:<br>API versions 12+: SystemCapability.Security.CryptoFramework.Key.AsymKey<br>API version 11: SystemCapability.Security.CryptoFramework|
| ED25519_SK_BN<sup>11+</sup> | 501 | Private key **sk** in the Ed25519 algorithm.<br>**System capability**:<br>API versions 12+: SystemCapability.Security.CryptoFramework.Key.AsymKey<br>API version 11: SystemCapability.Security.CryptoFramework|
| ED25519_PK_BN<sup>11+</sup> | 502 | Public key **pk** in the Ed25519 algorithm.<br>**System capability**:<br>API versions 12+: SystemCapability.Security.CryptoFramework.Key.AsymKey<br>API version 11: SystemCapability.Security.CryptoFramework|
| X25519_SK_BN<sup>11+</sup> | 601 | Private key **sk** in the X25519 algorithm.<br>**System capability**:<br>API versions 12+: SystemCapability.Security.CryptoFramework.Key.AsymKey<br>API version 11: SystemCapability.Security.CryptoFramework|
| X25519_PK_BN<sup>11+</sup> | 602 | Public key **pk** in the X25519 algorithm.<br>**System capability**:<br>API versions 12+: SystemCapability.Security.CryptoFramework.Key.AsymKey<br>API version 11: SystemCapability.Security.CryptoFramework|

## AsyKeyDataItem

Enumerates the asymmetric key data types.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.Security.CryptoFramework.Key.AsymKey

| Name        | Value  | Description            |
| ------------ | ---- | ---------------- |
| ML_DSA_PRIVATE_SEED | 0 | Private key seed of the Module-Lattice-Based Digital Signature Algorithm (ML-DSA).|
| ML_DSA_PRIVATE_RAW | 1 | Raw private key data of the ML-DSA private key.|
| ML_DSA_PUBLIC_RAW | 2 | Raw public key data of the ML-DSA public key.|
| ML_KEM_PRIVATE_SEED | 3 | Private key seed of the Module-Lattice-Based Key-Encapsulation Mechanism (ML-KEM).|
| ML_KEM_PRIVATE_RAW | 4 | Raw private key data of the ML-KEM private key.|
| ML_KEM_PUBLIC_RAW | 5 | Raw public key data of the ML-KEM public key.|
| EC_PRIVATE_K | 6 | Private key number **K** on the elliptic curve (EC).|
| EC_PRIVATE_04_X_Y_K | 7 | Key **04\|\|X\|\|Y\|\|K** on the EC, where **04\|\|X\|\|Y** is an uncompressed public key point and **K** is a private key number.|
| EC_PUBLIC_X_Y | 8 | Public key **X\|\|Y** on the EC.|
| EC_PUBLIC_04_X_Y | 9 | Public key **04\|\|X\|\|Y** on the EC.|
| EC_PUBLIC_COMPRESS_X | 10 | Public key **02\|\|X** or **03\|\|X** on the EC.|

## AsyKeySpecType<sup>10+</sup>

Enumerates the key parameter types.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Key.AsymKey
- API versions 10 to 11: SystemCapability.Security.CryptoFramework

| Name        | Value  | Description            |
| ------------ | ---- | ---------------- |
| COMMON_PARAMS_SPEC | 0 | Common parameter of the public and private keys. You can use [generateKeyPair](#generatekeypair10) to randomly generate a key pair based on the parameters of this type.|
| PRIVATE_KEY_SPEC | 1 | Parameter of the private key. You can use [generatePriKey](#generateprikey10) to generate a private key based on the parameters of this type.|
| PUBLIC_KEY_SPEC | 2 | Parameter of the public key. You can use [generatePubKey](#generatepubkey10) to generate a public key based on the parameters of this type.|
| KEY_PAIR_SPEC | 3 | Full parameters of the public and private keys. You can use [generateKeyPair](#generatekeypair10) to generate a key pair based on the parameters of this type.|

## CipherSpecItem<sup>10+</sup>

Enumerates encryption and decryption parameters, which can be set by using [setCipherSpec](#setcipherspec10) and obtained by using [getCipherSpec](#getcipherspec10).

Currently, only RSA and SM2 are supported. For details, see [Asymmetric Key Encryption and Decryption Algorithm Specifications](../../security/CryptoArchitectureKit/crypto-asym-encrypt-decrypt-spec.md).

**Atomic service API**: This API can be used in atomic services since API version 12.

| Name        | Value  | Description            |
| ------------ | ---- | ---------------- |
| OAEP_MD_NAME_STR | 100 | Message digest (MD) algorithm used with the PKCS1_OAEP padding mode in RSA.<br>**System capability**:<br>API versions 12+: SystemCapability.Security.CryptoFramework.Cipher<br>API versions 10 to 11: SystemCapability.Security.CryptoFramework|
| OAEP_MGF_NAME_STR | 101 | Mask generation algorithm used with the PKCS1_OAEP padding mode in RSA. Currently, only MGF1 is supported.<br>**System capability**:<br>API versions 12+: SystemCapability.Security.CryptoFramework.Cipher<br>API versions 10 to 11: SystemCapability.Security.CryptoFramework|
| OAEP_MGF1_MD_STR | 102 | MD algorithm for the MGF1 mask generation used with the PKCS1_OAEP padding mode in RSA.<br>**System capability**:<br>API versions 12+: SystemCapability.Security.CryptoFramework.Cipher<br>API versions 10 to 11: SystemCapability.Security.CryptoFramework|
| OAEP_MGF1_PSRC_UINT8ARR | 103 | **pSource** byte stream used with the PKCS1_OAEP padding mode in RSA.<br>**System capability**:<br>API versions 12+: SystemCapability.Security.CryptoFramework.Cipher<br>API versions 10 to 11: SystemCapability.Security.CryptoFramework|
| SM2_MD_NAME_STR<sup>11+</sup> | 104 | MD algorithm used in SM2.<br>**System capability**:<br>API versions 12+: SystemCapability.Security.CryptoFramework.Cipher<br>API version 11: SystemCapability.Security.CryptoFramework |

## SignSpecItem<sup>10+</sup>

Enumerates the signing and signature verification parameters, which can be set by using [setSignSpec](#setsignspec10) and [setVerifySpec](#setverifyspec10), and obtained by using [getSignSpec](#getsignspec10) and [getVerifySpec](#getverifyspec10).

Currently, only RSA and SM2 are supported. ML-DSA is supported since API version 26.0.0. For details about the specifications, see [Signing and Signature Verification Overview and Algorithm Specifications](../../security/CryptoArchitectureKit/crypto-sign-sig-verify-overview.md).

| Name        | Value  | Description            |
| ------------ | ---- | ---------------- |
| PSS_MD_NAME_STR | 100 | MD algorithm used with the PSS padding mode in RSA.<br>**System capability**:<br>API versions 12+: SystemCapability.Security.CryptoFramework.Signature<br>API versions 10 to 11: SystemCapability.Security.CryptoFramework<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| PSS_MGF_NAME_STR | 101 | MD algorithm used with the PSS padding mode in RSA. Currently, only MGF1 is supported.<br>**System capability**:<br>API versions 12+: SystemCapability.Security.CryptoFramework.Signature<br>API versions 10 to 11: SystemCapability.Security.CryptoFramework<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| PSS_MGF1_MD_STR | 102 | MD algorithm for the MGF1 mask generation used with the PSS padding mode in RSA.<br>**System capability**:<br>API versions 12+: SystemCapability.Security.CryptoFramework.Signature<br>API versions 10 to 11: SystemCapability.Security.CryptoFramework<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| PSS_SALT_LEN_NUM | 103 | Length of the salt in bytes used with the PSS padding mode in RSA.<br>**System capability**:<br>API versions 12+: SystemCapability.Security.CryptoFramework.Signature<br>API versions 10 to 11: SystemCapability.Security.CryptoFramework<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| PSS_TRAILER_FIELD_NUM | 104 | Trailer field used in the encoding operation when PSS padding mode is used in RSA.<br>**System capability**:<br>API versions 12+: SystemCapability.Security.CryptoFramework.Signature<br>API versions 10 to 11: SystemCapability.Security.CryptoFramework<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| SM2_USER_ID_UINT8ARR<sup>11+</sup> | 105 | User ID field in SM2.<br>**System capability**:<br>API versions 12+: SystemCapability.Security.CryptoFramework.Signature<br>API version 11: SystemCapability.Security.CryptoFramework<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| ML_DSA_DETERMINISTIC_BOOL | 106 | Whether deterministic signatures are used for signing and signature verification in ML-DSA. If this parameter is not set, the default value **false** is used.<br>**System capability**:<br>SystemCapability.Security.CryptoFramework.Signature <br> **Since**: 26.0.0<br> **Model restriction**: This API can be used only in the stage model.<br> **Atomic service API**: This API can be used in atomic services since API version 26.0.0.|
| ML_DSA_MU_BOOL | 107 | The **MU** parameter used for signing and signature verification in ML-DSA. The default value is **false**. If this parameter is set to **true**, the data to be signed must be a 64-byte hash value.<br>**System capability**:<br>SystemCapability.Security.CryptoFramework.Signature <br> **Since**: 26.0.0<br> **Model restriction**: This API can be used only in the stage model.<br> **Atomic service API**: This API can be used in atomic services since API version 26.0.0.|
| ML_DSA_CONTEXT_UINT8ARR | 108 | Context data used for signing and signature verification in ML-DSA, with a maximum length of 255 bytes. This parameter is used to identify the signature verification scenario. This parameter is invalid when **ML_DSA_MU_BOOL** is set to **true**. If this parameter is not set, the default value is an empty string.<br>**System capability**:<br>SystemCapability.Security.CryptoFramework.Signature <br> **Since**: 26.0.0<br> **Model restriction**: This API can be used only in the stage model.<br> **Atomic service API**: This API can be used in atomic services since API version 26.0.0.|

## AsyKeySpec<sup>10+</sup>

Defines the asymmetric key parameters for creating a key generator. You need to construct a child class object and pass it to [createAsyKeyGeneratorBySpec()](#cryptoframeworkcreateasykeygeneratorbyspec10) to create a key generator. When constructing a child class object, use little-endian format for RSA keys and use big-endian format and positive numbers for other key parameters of the bigint type.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Key.AsymKey
- API versions 10 to 11: SystemCapability.Security.CryptoFramework

| Name   | Type  | Read-Only| Optional| Description                                                        |
| ------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| algName | string | No  | No  | Asymmetric key algorithm, for example, **RSA**, **DSA**, **ECC**, **SM2**, **Ed25519**, **X25519**, or **DH**.|
| specType | [AsyKeySpecType](#asykeyspectype10) | No  | No| Key parameter type, which is used to distinguish public and private key parameters.|

## DSACommonParamsSpec<sup>10+</sup>

Defines a child class of [AsyKeySpec](#asykeyspec10) used to specify the common parameters of the public and private keys in the DSA algorithm. It can be used to randomly generate a public or private key.

To generate a key based on key parameters, pass it to [createAsyKeyGeneratorBySpec()](#cryptoframeworkcreateasykeygeneratorbyspec10) to create a key generator.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Key.AsymKey
- API versions 10 to 11: SystemCapability.Security.CryptoFramework

| Name   | Type  | Read-Only| Optional| Description                                                        |
| ------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| p | bigint | No  | No  | Prime modulus **p** in the DSA algorithm.|
| q | bigint | No  | No  | Parameter **q**, prime factor of (**p** – 1) in the DSA algorithm.|
| g | bigint | No  | No  | Parameter **g** in the DSA algorithm.|

## DSAPubKeySpec<sup>10+</sup>

Defines a child class of [AsyKeySpec](#asykeyspec10) used to specify the parameters of the public key in the DSA algorithm. 

To generate a key based on key parameters, pass it to [createAsyKeyGeneratorBySpec()](#cryptoframeworkcreateasykeygeneratorbyspec10) to create a key generator.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Key.AsymKey
- API versions 10 to 11: SystemCapability.Security.CryptoFramework

| Name   | Type  | Read-Only| Optional| Description                                                        |
| ------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| params | [DSACommonParamsSpec](#dsacommonparamsspec10) | No  | No  | Common parameters of the public and private keys in the DSA algorithm.|
| pk | bigint | No  | No  | Public key in the DSA algorithm.|

## DSAKeyPairSpec<sup>10+</sup>

Defines a child class of [AsyKeySpec](#asykeyspec10) used to specify full parameters of the public and private keys in the DSA algorithm.

To generate a key based on key parameters, pass it to [createAsyKeyGeneratorBySpec()](#cryptoframeworkcreateasykeygeneratorbyspec10) to create a key generator.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Key.AsymKey
- API versions 10 to 11: SystemCapability.Security.CryptoFramework

| Name   | Type  | Read-Only| Optional| Description                                                        |
| ------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| params | [DSACommonParamsSpec](#dsacommonparamsspec10) | No  | No  | Common parameters of the public and private keys in the DSA algorithm.|
| sk | bigint | No  | No  | Private key **sk** in the DSA algorithm.|
| pk | bigint | No  | No  | Public key in the DSA algorithm.|

## ECField<sup>10+</sup>

Defines the field type of an elliptic curve. Currently, only the **Fp** field is supported.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Key.AsymKey
- API versions 10 to 11: SystemCapability.Security.CryptoFramework

| Name   | Type  | Read-Only| Optional| Description                                                        |
| ------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| fieldType | string | No  | No  | Type of the elliptic curve field. Currently, only **Fp** is supported.|

## ECFieldFp<sup>10+</sup>

Defines the prime field of the elliptic curve. It is a child class of [ECField](#ecfield10).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Key.AsymKey
- API versions 10 to 11: SystemCapability.Security.CryptoFramework

| Name   | Type  | Read-Only| Optional| Description                                                        |
| ------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| p | bigint | No  | No  | Value of the prime number **p**.|

## Point<sup>10+</sup>

Defines a point on the elliptic curve.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Key.AsymKey
- API versions 10 to 11: SystemCapability.Security.CryptoFramework

| Name   | Type  | Read-Only| Optional| Description                                                        |
| ------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| x | bigint | No  | No  | X coordinate of the point on an elliptic curve.|
| y | bigint | No  | No  | Y coordinate of the point on an elliptic curve.|

## ECCCommonParamsSpec<sup>10+</sup>

Defines a child class of [AsyKeySpec](#asykeyspec10) used to specify the common parameters of the public and private keys in the ECC algorithm. It can be used to randomly generate a public or private key.

To generate a key based on key parameters, pass it to [createAsyKeyGeneratorBySpec()](#cryptoframeworkcreateasykeygeneratorbyspec10) to create a key generator.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Key.AsymKey
- API versions 10 to 11: SystemCapability.Security.CryptoFramework

| Name   | Type  | Read-Only| Optional| Description                                                        |
| ------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| field | [ECField](#ecfield10) | No  | No  | Field of the elliptic curve. Currently, only **Fp** is supported.|
| a | bigint | No  | No  | First coefficient **a** of the elliptic curve.|
| b | bigint | No  | No  | Second coefficient **b** of the elliptic curve.|
| g | [Point](#point10) | No  | No  | Base point g.|
| n | bigint | No  | No  | Order **n** of the base point **g**.|
| h | number | No  | No  | Cofactor **h**.|

## ECCPriKeySpec<sup>10+</sup>

Defines a child class of [AsyKeySpec](#asykeyspec10) used to specify the parameters of the private key in the ECC algorithm.

To generate a key based on key parameters, pass it to [createAsyKeyGeneratorBySpec()](#cryptoframeworkcreateasykeygeneratorbyspec10) to create a key generator.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Key.AsymKey
- API versions 10 to 11: SystemCapability.Security.CryptoFramework

| Name   | Type  | Read-Only| Optional| Description                                                        |
| ------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| params | [ECCCommonParamsSpec](#ecccommonparamsspec10) | No  | No  | Common parameters of the public and private keys in the ECC algorithm.|
| sk | bigint | No  | No  | Private key **sk** in the ECC algorithm.|

## ECCPubKeySpec<sup>10+</sup>

Defines a child class of [AsyKeySpec](#asykeyspec10) used to specify the parameters of the public key in the ECC algorithm.

To generate a key based on key parameters, pass it to [createAsyKeyGeneratorBySpec()](#cryptoframeworkcreateasykeygeneratorbyspec10) to create a key generator.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Key.AsymKey
- API versions 10 to 11: SystemCapability.Security.CryptoFramework

| Name   | Type  | Read-Only| Optional| Description                                                        |
| ------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| params | [ECCCommonParamsSpec](#ecccommonparamsspec10) | No  | No  | Common parameters of the public and private keys in the ECC algorithm.|
| pk | [Point](#point10) | No  | No  | Public key **pk** in the ECC algorithm.|

## ECCKeyPairSpec<sup>10+</sup>

Defines a child class of [AsyKeySpec](#asykeyspec10) used to specify full parameters of the public and private keys in the ECC algorithm. 

To generate a key based on key parameters, pass it to [createAsyKeyGeneratorBySpec()](#cryptoframeworkcreateasykeygeneratorbyspec10) to create a key generator.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Key.AsymKey
- API versions 10 to 11: SystemCapability.Security.CryptoFramework

| Name   | Type  | Read-Only| Optional| Description                                                        |
| ------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| params | [ECCCommonParamsSpec](#ecccommonparamsspec10) | No  | No  | Common parameters of the public and private keys in the ECC algorithm.|
| sk | bigint | No  | No  | Private key **sk** in the ECC algorithm.|
| pk | [Point](#point10) | No  | No  | Public key **pk** in the ECC algorithm.|

## RSACommonParamsSpec<sup>10+</sup>

Defines a child class of [AsyKeySpec](#asykeyspec10) used to specify the common parameters of the public and private keys in the RSA algorithm. It can be used to randomly generate a public or private key.

To generate a key based on key parameters, pass it to [createAsyKeyGeneratorBySpec()](#cryptoframeworkcreateasykeygeneratorbyspec10) to create a key generator.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Key.AsymKey
- API versions 10 to 11: SystemCapability.Security.CryptoFramework

| Name   | Type  | Read-Only| Optional| Description                                                        |
| ------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| n | bigint | No  | No  | Modulus **n**.|

## RSAPubKeySpec<sup>10+</sup>

Defines a child class of [AsyKeySpec](#asykeyspec10) used to specify the parameters of the public key in the RSA algorithm. 

To generate a key based on key parameters, pass it to [createAsyKeyGeneratorBySpec()](#cryptoframeworkcreateasykeygeneratorbyspec10) to create a key generator.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Key.AsymKey
- API versions 10 to 11: SystemCapability.Security.CryptoFramework

| Name   | Type  | Read-Only| Optional| Description                                                        |
| ------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| params | [RSACommonParamsSpec](#rsacommonparamsspec10) | No  | No  | Common parameters of the public and private keys in the RSA algorithm.|
| pk | bigint | No  | No  | Public key **pk** in the RSA algorithm.|

## RSAKeyPairSpec<sup>10+</sup>

Defines a child class of [AsyKeySpec](#asykeyspec10) used to specify full parameters of the public and private keys in the RSA algorithm.

To generate a key based on key parameters, pass it to [createAsyKeyGeneratorBySpec()](#cryptoframeworkcreateasykeygeneratorbyspec10) to create a key generator.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Key.AsymKey
- API versions 10 to 11: SystemCapability.Security.CryptoFramework

| Name   | Type  | Read-Only| Optional| Description                                                        |
| ------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| params | [RSACommonParamsSpec](#rsacommonparamsspec10) | No  | No  | Common parameters of the public and private keys in the RSA algorithm.|
| sk | bigint | No  | No  | Private key **sk** in the RSA algorithm.|
| pk | bigint | No  | No  | Public key **pk** in the RSA algorithm.|

## ED25519PriKeySpec<sup>11+</sup>

Defines a child class of [AsyKeySpec](#asykeyspec10) used to specify the parameters of the private key in the Ed25519 algorithm.

To generate a key based on key parameters, pass it to [createAsyKeyGeneratorBySpec()](#cryptoframeworkcreateasykeygeneratorbyspec10) to create a key generator.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Key.AsymKey
- API version 11: SystemCapability.Security.CryptoFramework

| Name| Type  | Read-Only| Optional| Description                     |
| ---- | ------ | ---- | ---- | ------------------------- |
| sk   | bigint | No  | No  | Private key **sk** in the Ed25519 algorithm.|

## ED25519PubKeySpec<sup>11+</sup>

Defines a child class of [AsyKeySpec](#asykeyspec10) used to specify the parameters of the public key in the Ed25519 algorithm.

To generate a key based on key parameters, pass it to [createAsyKeyGeneratorBySpec()](#cryptoframeworkcreateasykeygeneratorbyspec10) to create a key generator.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Key.AsymKey
- API version 11: SystemCapability.Security.CryptoFramework

| Name| Type  | Read-Only| Optional| Description                     |
| ---- | ------ | ---- | ---- | ------------------------- |
| pk   | bigint | No  | No  | Public key **pk** in the Ed25519 algorithm.|

## ED25519KeyPairSpec<sup>11+</sup>

Defines a child class of [AsyKeySpec](#asykeyspec10) used to specify full parameters of the public and private keys in the Ed25519 algorithm.

To generate a key based on key parameters, pass it to [createAsyKeyGeneratorBySpec()](#cryptoframeworkcreateasykeygeneratorbyspec10) to create a key generator.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Key.AsymKey
- API version 11: SystemCapability.Security.CryptoFramework

| Name| Type  | Read-Only| Optional| Description                     |
| ---- | ------ | ---- | ---- | ------------------------- |
| sk   | bigint | No  | No  | Private key **sk** in the Ed25519 algorithm.|
| pk   | bigint | No  | No  | Public key **pk** in the Ed25519 algorithm.|

## X25519PriKeySpec<sup>11+</sup>

Defines a child class of [AsyKeySpec](#asykeyspec10) used to specify the parameters of the private key in the X25519 algorithm.

To generate a key based on key parameters, pass it to [createAsyKeyGeneratorBySpec()](#cryptoframeworkcreateasykeygeneratorbyspec10) to create a key generator.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Key.AsymKey
- API version 11: SystemCapability.Security.CryptoFramework

| Name| Type  | Read-Only| Optional| Description                    |
| ---- | ------ | ---- | ---- | ------------------------ |
| sk   | bigint | No  | No  | Private key **sk** in the X25519 algorithm.|

## X25519PubKeySpec<sup>11+</sup>

Defines a child class of [AsyKeySpec](#asykeyspec10) used to specify the parameters of the public key in the X25519 algorithm.

To generate a key based on key parameters, pass it to [createAsyKeyGeneratorBySpec()](#cryptoframeworkcreateasykeygeneratorbyspec10) to create a key generator.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Key.AsymKey
- API version 11: SystemCapability.Security.CryptoFramework

| Name| Type  | Read-Only| Optional| Description                    |
| ---- | ------ | ---- | ---- | ------------------------ |
| pk   | bigint | No  | No  | Public key **pk** in the X25519 algorithm.|

## X25519KeyPairSpec<sup>11+</sup>

Defines a child class of [AsyKeySpec](#asykeyspec10) used to specify full parameters of the public and private keys in the X25519 algorithm.

To generate a key based on key parameters, pass it to [createAsyKeyGeneratorBySpec()](#cryptoframeworkcreateasykeygeneratorbyspec10) to create a key generator.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Key.AsymKey
- API version 11: SystemCapability.Security.CryptoFramework

| Name| Type  | Read-Only| Optional| Description                    |
| ---- | ------ | ---- | ---- | ------------------------ |
| sk   | bigint | No  | No  | Private key **sk** in the X25519 algorithm.|
| pk   | bigint | No  | No  | Public key **pk** in the X25519 algorithm.|

## DHCommonParamsSpec<sup>11+</sup>

Defines a child class of [AsyKeySpec](#asykeyspec10) used to specify the public parameters of the public and private keys in the DH algorithm.

To generate a key based on key parameters, pass it to [createAsyKeyGeneratorBySpec()](#cryptoframeworkcreateasykeygeneratorbyspec10) to create a key generator.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Key.AsymKey
- API version 11: SystemCapability.Security.CryptoFramework

| Name| Type  | Read-Only| Optional| Description                               |
| ---- | ------ | ---- | ---- | ----------------------------------- |
| p    | bigint | No  | No  | Large prime **p** in the DH algorithm.              |
| g    | bigint | No  | No  | Parameter **g** in the DH algorithm.                |
| l    | number | No  | No  | Length of the private key in the DH algorithm, in bits.|

## DHPriKeySpec<sup>11+</sup>

Defines a child class of [AsyKeySpec](#asykeyspec10) used to specify the parameters of the private key in the DH algorithm.

To generate a key based on key parameters, pass it to [createAsyKeyGeneratorBySpec()](#cryptoframeworkcreateasykeygeneratorbyspec10) to create a key generator.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Key.AsymKey
- API version 11: SystemCapability.Security.CryptoFramework

| Name  | Type              | Read-Only| Optional| Description                                |
| ------ | ------------------ | ---- | ---- | ------------------------------------ |
| params | [DHCommonParamsSpec](#dhcommonparamsspec11) | No  | No  | Common parameters of the public and private keys in the DH algorithm.|
| sk     | bigint             | No  | No  | Private key **sk** in the DH algorithm.                |

## DHPubKeySpec<sup>11+</sup>

Defines a child class of [AsyKeySpec](#asykeyspec10) used to specify the parameters of the public key in the DH algorithm.

To generate a key based on key parameters, pass it to [createAsyKeyGeneratorBySpec()](#cryptoframeworkcreateasykeygeneratorbyspec10) to create a key generator.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Key.AsymKey
- API version 11: SystemCapability.Security.CryptoFramework

| Name  | Type              | Read-Only| Optional| Description                                |
| ------ | ------------------ | ---- | ---- | ------------------------------------ |
| params | [DHCommonParamsSpec](#dhcommonparamsspec11) | No  | No  | Common parameters of the public and private keys in the DH algorithm.|
| pk     | bigint             | No  | No  | Public key **pk** in the DH algorithm.                |

## DHKeyPairSpec<sup>11+</sup>

Defines a child class of [AsyKeySpec](#asykeyspec10) used to specify full parameters of the public and private keys in the DH algorithm.

To generate a key based on key parameters, pass it to [createAsyKeyGeneratorBySpec()](#cryptoframeworkcreateasykeygeneratorbyspec10) to create a key generator.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Key.AsymKey
- API version 11: SystemCapability.Security.CryptoFramework

| Name  | Type              | Read-Only| Optional| Description                                |
| ------ | ------------------ | ---- | ---- | ------------------------------------ |
| params | [DHCommonParamsSpec](#dhcommonparamsspec11) | No  | No  | Common parameters of the public and private keys in the DH algorithm.|
| sk     | bigint             | No  | No  | Private key **sk** in the DH algorithm.                |
| pk     | bigint             | No  | No  | Public key **pk** in the DH algorithm.                |

## KdfSpec<sup>11+</sup>

Defines the parameters of the key derivation function. When the key derivation function is used to derive a key, you need to construct and pass in a child class object of **KdfSpec**.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Kdf
- API version 11: SystemCapability.Security.CryptoFramework

| Name   | Type  | Read-Only| Optional| Description                                                        |
| ------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| algName | string | No  | No  | Algorithm of the key derivation function, for example, **PBKDF2**.|

## PBKDF2Spec<sup>11+</sup>

Defines the child class of [KdfSpec](#kdfspec11). It is used as a parameter for PBKDF2 key derivation.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Kdf
- API version 11: SystemCapability.Security.CryptoFramework

| Name   | Type  | Read-Only| Optional| Description                                                        |
| ------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| password | string \| Uint8Array | No  | No  | Original password entered by the user.|
| salt | Uint8Array | No  | No  | Salt value.|
| iterations | number | No  | No  | Number of iterations. The value must be a positive integer.|
| keySize | number | No  | No  | Length of the derived key, in bytes. The value must be a positive integer.|

> **NOTE**
>
>  **password** is the original password. If **password** of the string type is used, pass in the actual data for key derivation, rather than a HexString or Base64-encoded value. In addition, the string must be encoded in UTF-8, as other encodings may alter the derivation outcome.

## HKDFSpec<sup>12+</sup>

Defines the child class of [KdfSpec](#kdfspec11). It is a parameter for HKDF key derivation.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Kdf

| Name   | Type  | Read-Only| Optional| Description                                                        |
| ------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| key | string \| Uint8Array | No  | No  | Key material.|
| salt | Uint8Array | No  | No  | Salt value.|
| info | Uint8Array | No  | No  | Extended information.|
| keySize | number | No  | No  | Length of the derived key, in bytes. The value must be a positive integer.|

> **NOTE**
>
> **key** is the original key material entered by the user. An empty string can be passed in for **info** and **salt** based on the mode.
>
> For example, if the mode is **EXTRACT_AND_EXPAND**, all parameter values must be passed in. If the mode is **EXTRACT_ONLY**, **info** can be empty. When **HKDFSpec** is constructed, pass in **null** to **info**.
>
> The default mode is **EXTRACT_AND_EXPAND**. The value **HKDF\|SHA256\|EXTRACT_AND_EXPAND** is equivalent to **HKDF\|SHA256**.

## ScryptSpec<sup>18+</sup>

Defines the child class of [KdfSpec](#kdfspec11). It is a parameter for scrypt key derivation function (KDF).

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Security.CryptoFramework.Kdf

| Name   | Type  | Read-Only| Optional| Description                                                        |
| ------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| passphrase | string \| Uint8Array | No  | No  | Original password entered by the user.|
| salt | Uint8Array | No  | No  | Salt value.|
| n | number | No  | No  | CPU/memory overhead. The value must be a positive integer.|
| p | number | No  | No  | Parallelization parameter. The value must be a positive integer.|
| r | number | No  | No  | Block size. The value must be a positive integer.|
| maxMemory | number | No  | No  | Maximum memory size, in bytes. The value must be a positive integer.|
| keySize | number | No  | No  | Length of the derived key, in bytes. The value must be a positive integer.|

> **NOTE**
>
> **passphrase** specifies the original password. If **password** is of the string type, pass in the data used for key derivation rather than a string of the HexString or Base64 type. In addition, the string must be in UTF-8 format. Otherwise, the key derived may be different from the one expected.

## X963KdfSpec<sup>22+</sup>

Defines the child class of [KdfSpec](#kdfspec11). It is a parameter for X963KDF key derivation function (KDF).

**Atomic service API**: This API can be used in atomic services since API version 22.

**System capability**: SystemCapability.Security.CryptoFramework.Kdf

| Name   | Type  | Read-Only| Optional| Description                                                        |
| ------- | ------ | ---- | ---- | ------------ |
| key | string \| Uint8Array | No  | No  | Key material.|
| info | Uint8Array | No  | No  | Shared information.|
| keySize | number | No  | No  | Length of the derived key, in bytes. The value must be a positive integer.|

> **NOTE**
>
> **key** is the original key material entered by the user.

## SM2CipherTextSpec<sup>12+</sup>

Represents the SM2 ciphertext parameters. You can use this object to generate SM2 ciphertext in ASN.1 format or obtain SM2 parameters from the SM2 ciphertext in ASN.1 format.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Cipher

| Name   | Type  | Read-Only| Optional| Description                                                        |
| ------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| xCoordinate | bigint | No  | No  | Coordinate X.|
| yCoordinate | bigint | No  | No  | Coordinate Y.|
| cipherTextData | Uint8Array | No  | No  | Ciphertext.|
| hashData | Uint8Array | No  | No  | Hash value.|

> **NOTE**
>
> - **hashData** is a value obtained by applying the SM3 algorithm to the plaintext. It has a fixed length of 256 bits.
>
> - **cipherTextData** is the ciphertext with the same length as the plaintext.
> 
> - During the generation of ciphertext in C1C3C2 format, if the length of x (**C1_X**) or y (**C1_Y**) is less than 32 bytes, zeros must be added to the high-order bits to extend them to 32 bytes.

## KeyEncodingConfig<sup>18+</sup>
Represents the RSA private key encoding parameters. You can use it to generate an encoded private key string with the specified algorithm and password.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Security.CryptoFramework.Key.AsymKey

| Name   | Type  | Read-Only| Optional| Description                                                        |
| ------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| password | string | No  | No  | Password used for encoding the private key.|
| cipherName | string | No  | No  | Symmetric cryptographic algorithm used to encode the private key.|

> **NOTE**
>
> - **password** specifies the password used for encoding the private key. It is mandatory.
>
> - **cipherName** specifies the algorithm used for encoding. It is mandatory. Currently, only **AES-128-CBC**, **AES-192-CBC**, **AES-256-CBC**, and **DES-EDE3-CBC** are supported.

## MacSpec<sup>18+</sup>
Represents the message authentication code (MAC) parameters. You need to construct a child class object and use it as a parameter when generating an HMAC or a CMAC.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Security.CryptoFramework.Mac

| Name   | Type  | Read-Only| Optional| Description                                                        |
| ------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| algName | string | No  | No  | Name of the MAC algorithm.|

> **NOTE**
>
> **algName** is mandatory, which specifies the MAC algorithm.

## HmacSpec<sup>18+</sup>
Represents the child class of [MacSpec](#macspec18). It is used as an input parameter for HMAC generation.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Security.CryptoFramework.Mac

| Name   | Type  | Read-Only| Optional| Description                                                        |
| ------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| mdName | string | No  | No  | MD algorithm to use.|

> **NOTE**
>
> **mdName** specifies the HMAC digest algorithm. It is mandatory.

## CmacSpec<sup>18+</sup>
Represents the child class of [MacSpec](#macspec18). It is used as an input parameter for CMAC generation.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Security.CryptoFramework.Mac

| Name   | Type  | Read-Only| Optional| Description                                                        |
| ------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| cipherName | string | No  | No  | Name of the symmetric cryptographic algorithm used by CMAC.|

> **NOTE**
>
> **cipherName** specifies the CMAC symmetric encryption algorithm. It is mandatory.

## EccSignatureSpec<sup>20+</sup>

Represents the ECC/SM2 signature data object that contains (r, s).

> **NOTE**
>
> **r** and **s** are each 256 bits long.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Security.CryptoFramework.Signature

| Name   | Type  | Read-Only| Optional| Description                                                        |
| ------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| r | bigint | No  | No  | Randomized value derived from the elliptic curve calculation using the ephemeral private key during signature generation.|
| s | bigint | No  | No  | Signature component, computed using the signer's private key, r, and the hashed message.|

## Key

Provides APIs for key operations. Before performing cryptographic operations (such as encryption and decryption), you need to construct a child class object of **Key** and pass it to [init()](#init-1) of the [Cipher](#cipher) instance.

Keys can be generated by a child class key generator. For details, see the child class description. The child classes include [SymKey](#symkey), [PubKey](#pubkey), and [PriKey](#prikey).

### Attributes

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Key
- API versions 9 to 11: SystemCapability.Security.CryptoFramework

| Name   | Type  | Read-Only| Optional| Description                        |
| ------- | ------ | ---- | ---- | ---------------------------- |
| format  | string | Yes  | No  | Format of the key.                |
| algName | string | Yes  | No  | Algorithm to use. This parameter contains the key length if the key is a symmetric key.|

### getEncoded

getEncoded(): DataBlob

Obtains the byte stream of the key data. This API returns the result synchronously. The key can be a symmetric key, public key, or private key. The public key must comply with the ASN.1 syntax, X.509 specifications, and DER encoding. The private key must comply with the ASN.1 syntax, PKCS #8 specifications, and DER encoding.

> **NOTE**
>
> When the RSA algorithm generates a private key using key parameters, **getEncoded** is available for the private key object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Key
- API versions 9 to 11: SystemCapability.Security.CryptoFramework

**Return value**

| Type                 | Description                    |
| --------------------- | ------------------------ |
| [DataBlob](#datablob) | Key obtained.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 801 | This operation is not supported. |
| 17620001 | Memory operation failed. |
| 17630001 | Crypto operation error. |

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';

async function testGenerateAesKey() {
  let symKeyGenerator = cryptoFramework.createSymKeyGenerator('AES256');
  let symKey = await symKeyGenerator.generateSymKey();
  let encodedKey = symKey.getEncoded();
  console.info('key hex: ' + encodedKey.data);
}
```

### getKeySize

getKeySize(): number

Obtains the key size, in bits. The key can be a symmetric key, public key, or private key.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.Security.CryptoFramework.Key

**Return value**

| Type                 | Description             |
| --------------------- | ------------------------ |
| number | Key size, in bits.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message             |
| -------- | ---------------------- |
| 17620001 | Memory operation failed. |
| 17620002 | Failed to obtain the native object or convert parameters. |
| 17630001 | Crypto operation error. |

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';

async function testGenerateAesKey() {
  let symKeyGenerator = cryptoFramework.createSymKeyGenerator('AES256');
  let symKey = await symKeyGenerator.generateSymKey();
  let symKeyLen = symKey.getKeySize();
  console.info('keysize is: ' + symKeyLen);
}
```

## SymKey

Provides APIs for symmetric key operations. It is a child class of [Key](#key). Its objects need to be passed to [init()](#init-1) of the [Cipher](#cipher) instance in symmetric encryption and decryption.

Symmetric keys can be generated by a [SymKeyGenerator](#symkeygenerator).

### clearMem

clearMem(): void

Clears the key data in memory. This API returns the result synchronously. Call this API when the symmetric key instance is no longer required.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Key.SymKey
- API versions 9 to 11: SystemCapability.Security.CryptoFramework

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';

async function testGenerateAesKeyFun() {
  let symKeyGenerator = cryptoFramework.createSymKeyGenerator('AES256');
  let key = await symKeyGenerator.generateSymKey();
  let encodedKey = key.getEncoded();
  console.info('key blob: '+ encodedKey.data);
  key.clearMem();
  encodedKey = key.getEncoded();
  console.info('key blob: ' + encodedKey.data);
}
```

## PubKey

Provides APIs for public key operations. **PubKey** is a child class of [Key](#key). It needs to be passed in during asymmetric encryption, signature verification, and key agreement.

The public key can be generated by using the asymmetric key generator [AsyKeyGenerator](#asykeygenerator) or [AsyKeyGeneratorBySpec](#asykeygeneratorbyspec10).

### getAsyKeySpec<sup>10+</sup>

getAsyKeySpec(itemType: AsyKeySpecItem): bigint | string | number

Obtains a key parameter. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Key.AsymKey
- API versions 10 to 11: SystemCapability.Security.CryptoFramework

**Parameters**

| Name| Type                 | Mandatory| Description                |
| ---- | --------------------- | ---- | -------------------- |
| itemType  | [AsyKeySpecItem](#asykeyspecitem10) | Yes  | Key parameter to obtain.|

**Return value**

| Type                       | Description                             |
| --------------------------- | --------------------------------- |
| bigint \| string \| number | Content of the key parameter obtained.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 801 | This operation is not supported. <br>Applicable versions: 12+        |
| 17620001 | Memory operation failed. |
| 17630001 | Crypto operation error. |
| 17620003 | Parameter check failed. <br>Applicable versions: 26.0.0+|

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';

// Construct the EccCommonSpec struct, which defines the common parameters of the ECC public and private keys.
function genEccCommonSpec(): cryptoFramework.ECCCommonParamsSpec {
  let fieldFp: cryptoFramework.ECFieldFp = {
    fieldType: 'Fp',
    p: BigInt('0xffffffffffffffffffffffffffffffff000000000000000000000001')
  }
  let G: cryptoFramework.Point = {
    x: BigInt('0xb70e0cbd6bb4bf7f321390b94a03c1d356c21122343280d6115c1d21'),
    y: BigInt('0xbd376388b5f723fb4c22dfe6cd4375a05a07476444d5819985007e34')
  }
  let eccCommonSpec: cryptoFramework.ECCCommonParamsSpec = {
    algName: 'ECC',
    specType: cryptoFramework.AsyKeySpecType.COMMON_PARAMS_SPEC,
    field: fieldFp,
    a: BigInt('0xfffffffffffffffffffffffffffffffefffffffffffffffffffffffe'),
    b: BigInt('0xb4050a850c04b3abf54132565044b0b7d7bfd8ba270b39432355ffb4'),
    g: G,
    n: BigInt('0xffffffffffffffffffffffffffff16a2e0b8f03e13dd29455c5c2a3d'),
    h: 1
  }
  return eccCommonSpec;
}

async function testgetAsyKeySpec() {
  let commKeySpec = genEccCommonSpec(); // Construct the EccCommonSpec object.
  let generatorBySpec = cryptoFramework.createAsyKeyGeneratorBySpec(commKeySpec); // Create an AsyKeyGenerator instance based on the EccCommonSpec object.
  let keyPair = await generatorBySpec.generateKeyPair();
  let pubKey = keyPair.pubKey;
  let eccPrimeP = pubKey.getAsyKeySpec(cryptoFramework.AsyKeySpecItem.ECC_FP_P_BN);
  console.info('ecc item --- p: ' + eccPrimeP.toString(16));
}
```

### getEncodedDer<sup>12+</sup>

getEncodedDer(format: string): DataBlob

Obtains the public key data that complies with the ASN.1 syntax and DER encoding format based on the specified key format (such as the specifications and compression status).

> **NOTE**
>
> The difference between [Key.getEncoded()](#getencoded) and this API is as follows:
>
> 1. You can specify the format of the data to be obtained in this API.
> 2. The format of the key data to be obtained cannot be specified in [Key.getEncoded()](#getencoded).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Key.AsymKey

**Parameters**

| Name| Type                 | Mandatory| Description                |
| ---- | --------------------- | ---- | -------------------- |
| format  | string | Yes  | Format of the key. EC keys are supported. The value can be **X509\|COMPRESSED** or **X509\|UNCOMPRESSED**.<br>Since API version 26.0.0, RSA public keys are supported. The value can be **PKCS1** or **X509**.<br>Since API version 26.0.0, ML-DSA and ML-KEM keys are supported. The value can be **X509**.|

**Return value**

| Type                       | Description                             |
| --------------------------- | --------------------------------- |
| [DataBlob](#datablob) | Public key data obtained.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | Memory operation failed. |
| 17630001 | Crypto operation error. |
| 17620003 | Parameter check failed. <br>Applicable versions: 26.0.0+|

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';

async function testGetEncodedDer() {
  let pkData = new Uint8Array([48, 90, 48, 20, 6, 7, 42, 134, 72, 206, 61, 2, 1, 6, 9, 43, 36, 3, 3, 2, 8, 1, 1, 7, 3, 66, 0, 4, 143, 39, 57, 249, 145, 50, 63, 222, 35, 70, 178, 121, 202, 154, 21, 146, 129, 75, 76, 63, 8, 195, 157, 111, 40, 217, 215, 148, 120, 224, 205, 82, 83, 92, 185, 21, 211, 184, 5, 19, 114, 33, 86, 85, 228, 123, 242, 206, 200, 98, 178, 184, 130, 35, 232, 45, 5, 202, 189, 11, 46, 163, 156, 152]);
  let pubKeyBlob: cryptoFramework.DataBlob = { data: pkData };
  let generator = cryptoFramework.createAsyKeyGenerator('ECC_BrainPoolP256r1');
  let keyPair = await generator.convertKey(pubKeyBlob, null);
  let key = keyPair.pubKey;
  let returnBlob = key.getEncodedDer('X509|UNCOMPRESSED');
  console.info('returnBlob data: ' + returnBlob.data);
}
```

### getEncodedPem<sup>12+</sup>

getEncodedPem(format: string): string

Obtains the key data. This API returns the result synchronously. The key can be an RSA public or private key. The public key must comply with the X.509 and PKCS #1 specifications and be encoded in PEM.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Key.AsymKey

**Parameters**

| Name| Type                 | Mandatory| Description                |
| ---- | --------------------- | ---- | -------------------- |
| format  | string | Yes  | Encoding format of the key data to obtain. RSA keys are supported. The value can be **X509** or **PKCS1**.<br>Since API version 26.0.0, EC, ML-DSA, and ML-KEM keys are supported. The value can be **X509**.|

**Return value**

| Type                       | Description                             |
| --------------------------- | --------------------------------- |
| string | Public key data in PEM format.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | Invalid parameters.  Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | Memory operation failed. |
| 17630001 | Crypto operation error. |
| 17620003 | Parameter check failed. <br>Applicable versions: 26.0.0+|

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';

let publicPkcs1Str1024: string =
  '-----BEGIN RSA PUBLIC KEY-----\n'
    + 'MIGJAoGBALAg3eavbX433pOjGdWdpL7HIr1w1EAeIcaCtuMfDpECPdX6X5ZjrwiE\n'
    + 'h7cO51WXMT2gyN45DCQySr/8cLE2UiUVHo7qlrSatdLA9ETtgob3sJ4qTaBg5Lxg\n'
    + 'SHy2gC+bvEpuIuRe64yXGuM/aP+ZvmIj9QBIVI9mJD8jLEOvQBBpAgMBAAE=\n'
    + '-----END RSA PUBLIC KEY-----\n';

function TestPubKeyPkcs1ToX509BySync1024() {
  let rsaGenerator = cryptoFramework.createAsyKeyGenerator('RSA1024');
  let keyPair = rsaGenerator.convertPemKeySync(publicPkcs1Str1024, null);
  let pubPemKey = keyPair.pubKey;
  let pubString = pubPemKey.getEncodedPem('X509');
  console.info('[sync]TestPubKeyPkcs1ToX509BySync1024 pubString output = ' + pubString);
}
```

### getKeyData

getKeyData(itemType: AsyKeyDataItem): Promise\<Uint8Array>

Defines the key data type, which is used to obtain public key data of the corresponding type. This API uses a promise to return the result.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.Security.CryptoFramework.Key.AsymKey

**Parameters**

| Name| Type                 | Mandatory| Description                |
| ---- | --------------------- | ---- | -------------------- |
| itemType  | [AsyKeyDataItem](#asykeydataitem) | Yes  | Key data type.|

**Return value**

| Type                       | Description                             |
| --------------------------- | --------------------------------- |
| Promise\<Uint8Array> | Promise used to return the public key data of the specified key data type.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 17620001 | Memory operation failed. |
| 17620002 | Failed to obtain the native object or convert parameters. |
| 17620003 | Parameter check failed. |
| 17630001 | Crypto operation error. |

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';

async function eccGetKeyDataTest() {
  let eccGenerator = cryptoFramework.createAsyKeyGenerator('ECC_BrainPoolP256r1');
  let keyPair = await eccGenerator.generateKeyPair();
  let returnBlob = await keyPair.pubKey.getKeyData(cryptoFramework.AsyKeyDataItem.EC_PUBLIC_X_Y);
  console.info('EC_PUBLIC_X_Y data: ' + returnBlob);
}
```

### getKeyDataSync

getKeyDataSync(itemType: AsyKeyDataItem): Uint8Array

Defines the key data type, which is used to obtain public key data of the corresponding type. This API returns the result synchronously.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.Security.CryptoFramework.Key.AsymKey

**Parameters**

| Name| Type                 | Mandatory| Description                |
| ---- | --------------------- | ---- | -------------------- |
| itemType  | [AsyKeyDataItem](#asykeydataitem) | Yes  | Key data type.|

**Return value**

| Type                       | Description                             |
| --------------------------- | --------------------------------- |
| Uint8Array | Public key data of the specified key data type.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 17620001 | Memory operation failed. |
| 17620002 | Failed to obtain the native object or convert parameters. |
| 17620003 | Parameter check failed. |
| 17630001 | Crypto operation error. |

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';

function eccGetKeyDataTest() {
  let eccGenerator = cryptoFramework.createAsyKeyGenerator('ECC_BrainPoolP256r1');
  let keyPair = eccGenerator.generateKeyPairSync();
  let returnBlob = keyPair.pubKey.getKeyDataSync(cryptoFramework.AsyKeyDataItem.EC_PUBLIC_X_Y);
  console.info('EC_PUBLIC_X_Y data: ' + returnBlob);
}
```

## PriKey

Provides APIs for private key operations. **PriKey** is a child class of [Key](#key). It needs to be passed in during asymmetric decryption, signing, and key agreement.

The private key can be generated by using the asymmetric key generator [AsyKeyGenerator](#asykeygenerator) or [AsyKeyGeneratorBySpec](#asykeygeneratorbyspec10).

### clearMem

clearMem(): void

Clear the key data in memory. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Key.AsymKey
- API versions 9 to 11: SystemCapability.Security.CryptoFramework

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';

async function testClearMem() {
  let eccGenerator = cryptoFramework.createAsyKeyGenerator('ECC256');
  // Use AsyKeyGenerator to randomly generate an asymmetric key pair.
  let keyGenPromise = eccGenerator.generateKeyPair();
  keyGenPromise.then(keyPair => {
    let priKey = keyPair.priKey;
    let returnBlob = priKey.getEncodedDer('PKCS8');
    console.info('returnBlob data: ' + returnBlob.data);
    priKey.clearMem(); // For an asymmetric private key, clearMem() releases the internal key structure. After clearMem is executed, getEncoded() is not supported.
  });
}
```

### getAsyKeySpec<sup>10+</sup>

getAsyKeySpec(itemType: AsyKeySpecItem): bigint | string | number

Obtains a key parameter. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Key.AsymKey
- API versions 10 to 11: SystemCapability.Security.CryptoFramework

**Parameters**

| Name| Type                 | Mandatory| Description                |
| ---- | --------------------- | ---- | -------------------- |
| itemType  | [AsyKeySpecItem](#asykeyspecitem10) | Yes  | Key parameter type to obtain.|

**Return value**

| Type                       | Description                             |
| --------------------------- | --------------------------------- |
| bigint \| string \| number | Content of the key parameter obtained.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 801 | This operation is not supported.          |
| 17620001 | Memory operation failed. |
| 17630001 | Crypto operation error. |
| 17620003 | Parameter check failed. <br>Applicable versions: 26.0.0+|

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
// Construct the EccCommonSpec struct, which defines the common parameters of the ECC public and private keys.
function genEccCommonSpec(): cryptoFramework.ECCCommonParamsSpec {
  let fieldFp: cryptoFramework.ECFieldFp = {
    fieldType: 'Fp',
    p: BigInt('0xffffffffffffffffffffffffffffffff000000000000000000000001')
  }
  let G: cryptoFramework.Point = {
    x: BigInt('0xb70e0cbd6bb4bf7f321390b94a03c1d356c21122343280d6115c1d21'),
    y: BigInt('0xbd376388b5f723fb4c22dfe6cd4375a05a07476444d5819985007e34')
  }
  let eccCommonSpec: cryptoFramework.ECCCommonParamsSpec = {
    algName: 'ECC',
    specType: cryptoFramework.AsyKeySpecType.COMMON_PARAMS_SPEC,
    field: fieldFp,
    a: BigInt('0xfffffffffffffffffffffffffffffffefffffffffffffffffffffffe'),
    b: BigInt('0xb4050a850c04b3abf54132565044b0b7d7bfd8ba270b39432355ffb4'),
    g: G,
    n: BigInt('0xffffffffffffffffffffffffffff16a2e0b8f03e13dd29455c5c2a3d'),
    h: 1
  }
  return eccCommonSpec;
}

async function testgetAsyKeySpec() {
  let commKeySpec = genEccCommonSpec(); // Construct the EccCommonSpec object.
  let generatorBySpec = cryptoFramework.createAsyKeyGeneratorBySpec(commKeySpec); // Create an AsyKeyGenerator instance based on the EccCommonSpec object.
  let keyPair = await generatorBySpec.generateKeyPair();
  let pirKey = keyPair.priKey;
  let eccPrimeP = pirKey.getAsyKeySpec(cryptoFramework.AsyKeySpecItem.ECC_FP_P_BN);
  console.info('ecc item --- p: ' + eccPrimeP.toString(16));
}
```
### getEncodedDer<sup>12+</sup>

getEncodedDer(format: string): DataBlob

Obtains the private key data that complies with the ASN.1 syntax and DER encoding based on the specified format (such as the key specifications).

> **NOTE**
>
> The difference between [Key.getEncoded()](#getencoded) and this API is as follows:<br>
> 1. You can specify the format of the data to be obtained in this API.
> 2. The format of the key data to be obtained cannot be specified in [Key.getEncoded()](#getencoded).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Key.AsymKey

**Parameters**

| Name| Type                 | Mandatory| Description                |
| ---- | --------------------- | ---- | -------------------- |
| format  | string | Yes  | Format of the key. EC keys are supported. The value can be **PKCS8**.<br>Since API version 26.0.0, RSA private keys are supported. The value can be **PKCS1** or **PKCS8**.<br>Since API version 26.0.0, ML-DSA and ML-KEM keys are supported. The value can be **PKCS8**.|

**Return value**

| Type                       | Description                             |
| --------------------------- | --------------------------------- |
| [DataBlob](#datablob) | Private key data in DER format.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | Memory operation failed. |
| 17630001 | Crypto operation error. |
| 17620003 | Parameter check failed. <br>Applicable versions: 26.0.0+|

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';

async function testGetEncodedDer() {
  let eccGenerator = cryptoFramework.createAsyKeyGenerator('ECC256');
  // Use AsyKeyGenerator to randomly generate an asymmetric key pair.
  let keyGenPromise = eccGenerator.generateKeyPair();
  keyGenPromise.then(keyPair => {
    let priKey = keyPair.priKey;
    let returnBlob = priKey.getEncodedDer('PKCS8');
    console.info('returnBlob data: ' + returnBlob.data);
  });
}
```

### getEncodedPem<sup>12+</sup>

getEncodedPem(format: string): string

Obtains the key data. This API returns the result synchronously. The key can be an RSA public or private key. The private key must comply with the PKCS #8 and PKCS #1 specifications and be encoded in PEM.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Key.AsymKey

**Parameters**

| Name| Type                 | Mandatory| Description                |
| ---- | --------------------- | ---- | -------------------- |
| format  | string | Yes  | Encoding format of the key data to obtain. RSA keys are supported. The value can be **PKCS8** or **PKCS1**.<br>Since API version 26.0.0, EC keys are supported. The value can be **PKCS8** or **EC**.<br>Since API version 26.0.0, ML-DSA and ML-KEM keys are supported. The value can be **PKCS8**.|

**Return value**

| Type                       | Description                             |
| --------------------------- | --------------------------------- |
| string | Private key data in PEM format.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | Invalid parameters.  Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | Memory operation failed. |
| 17630001 | Crypto operation error. |
| 17620003 | Parameter check failed. <br>Applicable versions: 26.0.0+|

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';

let priKeyPkcs1Str1024: string =
  '-----BEGIN RSA PRIVATE KEY-----\n'
    + 'MIICXQIBAAKBgQCwIN3mr21+N96ToxnVnaS+xyK9cNRAHiHGgrbjHw6RAj3V+l+W\n'
    + 'Y68IhIe3DudVlzE9oMjeOQwkMkq//HCxNlIlFR6O6pa0mrXSwPRE7YKG97CeKk2g\n'
    + 'YOS8YEh8toAvm7xKbiLkXuuMlxrjP2j/mb5iI/UASFSPZiQ/IyxDr0AQaQIDAQAB\n'
    + 'AoGAEvBFzBNa+7J4PXnRQlYEK/tvsd0bBZX33ceacMubHl6WVZbphltLq+fMTBPP\n'
    + 'LjXmtpC+aJ7Lvmyl+wTi/TsxE9vxW5JnbuRT48rnZ/Xwq0eozDeEeIBRrpsr7Rvr\n'
    + '7ctrgzr4m4yMHq9aDgpxj8IR7oHkfwnmWr0wM3FuiVlj650CQQDineeNZ1hUTkj4\n'
    + 'D3O+iCi3mxEVEeJrpqrmSFolRMb+iozrIRKuJlgcOs+Gqi2fHfOTTL7LkpYe8SVg\n'
    + 'e3JxUdVLAkEAxvcZXk+byMFoetrnlcMR13VHUpoVeoV9qkv6CAWLlbMdgf7uKmgp\n'
    + 'a1Yp3QPDNQQqkPvrqtfR19JWZ4uy1qREmwJALTU3BjyBoH/liqb6fh4HkWk75Som\n'
    + 'MzeSjFIOubSYxhq5tgZpBZjcpvUMhV7Zrw54kwASZ+YcUJvmyvKViAm9NQJBAKF7\n'
    + 'DyXSKrem8Ws0m1ybM7HQx5As6l3EVhePDmDQT1eyRbKp+xaD74nkJpnwYdB3jyyY\n'
    + 'qc7A1tj5J5NmeEFolR0CQQCn76Xp8HCjGgLHw9vg7YyIL28y/XyfFyaZAzzK+Yia\n'
    + 'akNwQ6NeGtXSsuGCcyyfpacHp9xy8qXQNKSkw03/5vDO\n'
    + '-----END RSA PRIVATE KEY-----\n';

function TestPriKeyPkcs1ToPkcs8BySync1024() {
  let rsaGenerator = cryptoFramework.createAsyKeyGenerator('RSA1024');
  let keyPair = rsaGenerator.convertPemKeySync(null, priKeyPkcs1Str1024);
  let priPemKey = keyPair.priKey;
  let priString = priPemKey.getEncodedPem('PKCS8');
  console.info('[sync]TestPriKeyPkcs1ToPkcs8BySync1024 priString output = ' + priString);
}
```

### getEncodedPem<sup>18+</sup>

getEncodedPem(format: string, config: KeyEncodingConfig): string

Obtains the key data. This API returns the result synchronously. The key can be an RSA public or private key. The private key must comply with PKCS #8 or PKCS #1 specifications and be encoded in PEM.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Security.CryptoFramework.Key.AsymKey

**Parameters**

| Name| Type                 | Mandatory| Description                |
| ---- | --------------------- | ---- | -------------------- |
| format  | string | Yes  | Encoding format of the key data to obtain. The format of a private key can be **'PKCS1'** or **'PKCS8'**.|
| config | [KeyEncodingConfig](#keyencodingconfig18) | Yes| Parameter used to encrypt the private key.|

**Return value**

| Type                       | Description                             |
| --------------------------- | --------------------------------- |
| string | Encrypted private key data in PEM format.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | Invalid parameters.  Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 801 | This operation is not supported.          |
| 17620001 | Memory operation failed. |
| 17630001 | Crypto operation error. |

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';

let priKeyPkcs1Str1024: string =
  '-----BEGIN RSA PRIVATE KEY-----\n'
    + 'MIICXQIBAAKBgQCwIN3mr21+N96ToxnVnaS+xyK9cNRAHiHGgrbjHw6RAj3V+l+W\n'
    + 'Y68IhIe3DudVlzE9oMjeOQwkMkq//HCxNlIlFR6O6pa0mrXSwPRE7YKG97CeKk2g\n'
    + 'YOS8YEh8toAvm7xKbiLkXuuMlxrjP2j/mb5iI/UASFSPZiQ/IyxDr0AQaQIDAQAB\n'
    + 'AoGAEvBFzBNa+7J4PXnRQlYEK/tvsd0bBZX33ceacMubHl6WVZbphltLq+fMTBPP\n'
    + 'LjXmtpC+aJ7Lvmyl+wTi/TsxE9vxW5JnbuRT48rnZ/Xwq0eozDeEeIBRrpsr7Rvr\n'
    + '7ctrgzr4m4yMHq9aDgpxj8IR7oHkfwnmWr0wM3FuiVlj650CQQDineeNZ1hUTkj4\n'
    + 'D3O+iCi3mxEVEeJrpqrmSFolRMb+iozrIRKuJlgcOs+Gqi2fHfOTTL7LkpYe8SVg\n'
    + 'e3JxUdVLAkEAxvcZXk+byMFoetrnlcMR13VHUpoVeoV9qkv6CAWLlbMdgf7uKmgp\n'
    + 'a1Yp3QPDNQQqkPvrqtfR19JWZ4uy1qREmwJALTU3BjyBoH/liqb6fh4HkWk75Som\n'
    + 'MzeSjFIOubSYxhq5tgZpBZjcpvUMhV7Zrw54kwASZ+YcUJvmyvKViAm9NQJBAKF7\n'
    + 'DyXSKrem8Ws0m1ybM7HQx5As6l3EVhePDmDQT1eyRbKp+xaD74nkJpnwYdB3jyyY\n'
    + 'qc7A1tj5J5NmeEFolR0CQQCn76Xp8HCjGgLHw9vg7YyIL28y/XyfFyaZAzzK+Yia\n'
    + 'akNwQ6NeGtXSsuGCcyyfpacHp9xy8qXQNKSkw03/5vDO\n'
    + '-----END RSA PRIVATE KEY-----\n';

function TestPriKeyPkcs1Encoded() {
  let rsaGenerator = cryptoFramework.createAsyKeyGenerator('RSA1024');
  let keyPair = rsaGenerator.convertPemKeySync(null, priKeyPkcs1Str1024);
  let options: cryptoFramework.KeyEncodingConfig = {
    password: '123456',
    cipherName: 'AES-128-CBC'
  }
  let priPemKey = keyPair.priKey;
  let priString = priPemKey.getEncodedPem('PKCS1', options);
  console.info('[sync]TestPriKeyPkcs1Encoded priString output = ' + priString);
}
```

### getPubKey<sup>23+</sup>

getPubKey(): Promise\<PubKey>

Obtains a public key from a private key. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 23.

**System capability**: SystemCapability.Security.CryptoFramework.Key.AsymKey

**Return value**

| Type                       | Description                             |
| --------------------------- | --------------------------------- |
| Promise\<[PubKey](#pubkey)> | Promise used to return the **PubKey** object.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 17620001 | Memory operation failed. |
| 17620002 | Failed to obtain the native object or convert parameters. |
| 17630001 | Crypto operation error. |

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { buffer } from '@kit.ArkTS';

function compareUint8Array(a: Uint8Array, b: Uint8Array): boolean {
  let buf1 = buffer.from(a);
  let buf2 = buffer.from(b);
  if (buf1.compare(buf2, 0, b.length, 0, a.length) == 0) {
    return true;
  } else {
    return false;
  }
}

async function generateAsyKey() {
  let skData =
    new Uint8Array([48, 130, 2, 119, 2, 1, 0, 48, 13, 6, 9, 42, 134, 72, 134, 247, 13, 1, 1, 1, 5, 0, 4, 130, 2, 97, 48,
      130, 2, 93, 2, 1, 0, 2, 129, 129, 0, 199, 32, 218, 8, 4, 63, 103, 229, 64, 128, 83, 31, 23, 156, 30, 168, 101, 22,
      80, 100, 197, 243, 217, 60, 127, 110, 127, 242, 8, 251, 87, 127, 235, 38, 226, 149, 149, 108, 54, 202, 53, 1, 21,
      91, 118, 246, 97, 93, 147, 117, 162, 71, 215, 70, 9, 175, 205, 241, 230, 187, 64, 170, 154, 67, 67, 254, 71, 1,
      114, 10, 91, 195, 34, 199, 85, 172, 255, 87, 95, 159, 43, 117, 73, 73, 199, 97, 198, 117, 217, 7, 188, 196, 30,
      248, 9, 181, 150, 243, 41, 145, 91, 8, 226, 161, 251, 12, 120, 28, 36, 146, 3, 196, 48, 243, 136, 201, 207, 131,
      171, 22, 15, 7, 12, 172, 135, 196, 30, 93, 2, 3, 1, 0, 1, 2, 129, 128, 109, 100, 83, 194, 225, 170, 127, 134, 6,
      184, 56, 113, 181, 67, 179, 231, 232, 152, 168, 147, 163, 215, 193, 56, 165, 252, 235, 86, 232, 174, 67, 52, 103,
      215, 149, 212, 125, 32, 212, 188, 162, 255, 180, 94, 233, 236, 146, 50, 153, 6, 159, 158, 253, 217, 97, 10, 238,
      133, 124, 174, 211, 232, 165, 19, 100, 186, 218, 62, 46, 124, 30, 19, 251, 3, 206, 105, 255, 236, 224, 178, 148,
      103, 44, 132, 71, 83, 28, 221, 27, 189, 72, 44, 59, 253, 139, 232, 234, 14, 112, 121, 43, 142, 193, 179, 140, 200,
      97, 234, 110, 63, 205, 24, 88, 116, 86, 184, 8, 19, 254, 204, 77, 84, 66, 238, 240, 69, 72, 21, 2, 65, 0, 233,
      103, 239, 11, 215, 10, 103, 66, 46, 155, 193, 79, 37, 64, 90, 12, 167, 189, 129, 8, 131, 94, 195, 8, 210, 236, 87,
      158, 140, 2, 82, 105, 80, 253, 13, 26, 140, 202, 194, 117, 59, 57, 197, 108, 50, 20, 46, 89, 248, 132, 120, 30,
      149, 180, 135, 134, 196, 156, 160, 123, 38, 253, 15, 7, 2, 65, 0, 218, 103, 122, 117, 154, 149, 213, 110, 24, 149,
      175, 208, 136, 249, 88, 91, 89, 180, 30, 243, 69, 130, 97, 252, 177, 216, 55, 46, 67, 15, 124, 56, 113, 57, 242,
      233, 185, 193, 254, 218, 76, 165, 184, 16, 109, 190, 93, 195, 227, 37, 58, 110, 243, 142, 152, 252, 226, 91, 59,
      145, 218, 35, 106, 123, 2, 65, 0, 210, 131, 88, 58, 32, 144, 148, 131, 63, 144, 97, 112, 165, 211, 125, 164, 110,
      97, 224, 16, 50, 148, 116, 105, 239, 251, 20, 39, 190, 117, 149, 168, 193, 80, 10, 210, 136, 107, 147, 169, 178,
      106, 47, 162, 159, 36, 78, 141, 253, 52, 85, 54, 152, 165, 131, 154, 204, 151, 203, 178, 103, 126, 212, 95, 2, 65,
      0, 193, 254, 80, 3, 205, 255, 112, 200, 142, 5, 199, 88, 207, 145, 203, 45, 185, 12, 8, 193, 196, 231, 254, 233,
      89, 126, 215, 228, 187, 164, 49, 142, 96, 228, 60, 35, 230, 223, 173, 227, 113, 89, 113, 153, 6, 33, 165, 95, 173,
      143, 15, 204, 37, 130, 111, 217, 143, 165, 193, 207, 215, 150, 197, 169, 2, 64, 7, 37, 152, 14, 232, 168, 102,
      169, 167, 97, 161, 33, 86, 178, 77, 140, 12, 114, 78, 129, 47, 103, 87, 217, 177, 80, 156, 91, 240, 149, 254, 90,
      69, 232, 10, 56, 232, 63, 59, 148, 254, 101, 63, 146, 66, 96, 25, 31, 37, 154, 77, 145, 201, 213, 122, 245, 90,
      251, 219, 42, 131, 248, 148, 151
  ])
  let expectPkdata =
    new Uint8Array([48, 129, 159, 48, 13, 6, 9, 42, 134, 72, 134, 247, 13, 1, 1, 1, 5, 0, 3, 129, 141, 0, 48, 129, 137,
      2, 129, 129, 0, 199, 32, 218, 8, 4, 63, 103, 229, 64, 128, 83, 31, 23, 156, 30, 168, 101, 22, 80, 100, 197, 243,
      217, 60, 127, 110, 127, 242, 8, 251, 87, 127, 235, 38, 226, 149, 149, 108, 54, 202, 53, 1, 21, 91, 118, 246, 97,
      93, 147, 117, 162, 71, 215, 70, 9, 175, 205, 241, 230, 187, 64, 170, 154, 67, 67, 254, 71, 1, 114, 10, 91, 195,
      34, 199, 85, 172, 255, 87, 95, 159, 43, 117, 73, 73, 199, 97, 198, 117, 217, 7, 188, 196, 30, 248, 9, 181, 150,
      243, 41, 145, 91, 8, 226, 161, 251, 12, 120, 28, 36, 146, 3, 196, 48, 243, 136, 201, 207, 131, 171, 22, 15, 7, 12,
      172, 135, 196, 30, 93, 2, 3, 1, 0, 1
  ])
  let skDataBlob: cryptoFramework.DataBlob = { data: skData };
  let rsaGenerator = cryptoFramework.createAsyKeyGenerator('RSA1024');
  try {
    let keyPair = rsaGenerator.convertKeySync(null, skDataBlob);
    let priKey = keyPair.priKey;
    let pubkey = await priKey.getPubKey();
    let pkBlob = pubkey.getEncoded();
    console.info('pk1 bin data ' + pkBlob.data);
    let ret: boolean = compareUint8Array(pkBlob.data, expectPkdata);
    console.info('result = ' + ret);
  } catch (e) {
    console.error(`get pubkey from prikey failed, ${e.code}, ${e.message}`);
  }
}
```

### getPubKeySync<sup>23+</sup>

getPubKeySync(): PubKey

Obtains a public key from a private key in synchronous mode.

**Atomic service API**: This API can be used in atomic services since API version 23.

**System capability**: SystemCapability.Security.CryptoFramework.Key.AsymKey

**Return value**

| Type                       | Description                             |
| --------------------------- | --------------------------------- |
| [PubKey](#pubkey) | Public key object.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 17620001 | Memory operation failed. |
| 17620002 | Failed to obtain the native object or convert parameters. |
| 17630001 | Crypto operation error. |

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { buffer } from '@kit.ArkTS';

function compareUint8Array(a: Uint8Array, b: Uint8Array): boolean {
  let buf1 = buffer.from(a);
  let buf2 = buffer.from(b);
  if (buf1.compare(buf2, 0, b.length, 0, a.length) == 0) {
    return true;
  } else {
    return false;
  }
}

function generateAsyKey() {
  let skData =
    new Uint8Array([48, 130, 2, 119, 2, 1, 0, 48, 13, 6, 9, 42, 134, 72, 134, 247, 13, 1, 1, 1, 5, 0, 4, 130, 2, 97, 48,
      130, 2, 93, 2, 1, 0, 2, 129, 129, 0, 199, 32, 218, 8, 4, 63, 103, 229, 64, 128, 83, 31, 23, 156, 30, 168, 101, 22,
      80, 100, 197, 243, 217, 60, 127, 110, 127, 242, 8, 251, 87, 127, 235, 38, 226, 149, 149, 108, 54, 202, 53, 1, 21,
      91, 118, 246, 97, 93, 147, 117, 162, 71, 215, 70, 9, 175, 205, 241, 230, 187, 64, 170, 154, 67, 67, 254, 71, 1,
      114, 10, 91, 195, 34, 199, 85, 172, 255, 87, 95, 159, 43, 117, 73, 73, 199, 97, 198, 117, 217, 7, 188, 196, 30,
      248, 9, 181, 150, 243, 41, 145, 91, 8, 226, 161, 251, 12, 120, 28, 36, 146, 3, 196, 48, 243, 136, 201, 207, 131,
      171, 22, 15, 7, 12, 172, 135, 196, 30, 93, 2, 3, 1, 0, 1, 2, 129, 128, 109, 100, 83, 194, 225, 170, 127, 134, 6,
      184, 56, 113, 181, 67, 179, 231, 232, 152, 168, 147, 163, 215, 193, 56, 165, 252, 235, 86, 232, 174, 67, 52, 103,
      215, 149, 212, 125, 32, 212, 188, 162, 255, 180, 94, 233, 236, 146, 50, 153, 6, 159, 158, 253, 217, 97, 10, 238,
      133, 124, 174, 211, 232, 165, 19, 100, 186, 218, 62, 46, 124, 30, 19, 251, 3, 206, 105, 255, 236, 224, 178, 148,
      103, 44, 132, 71, 83, 28, 221, 27, 189, 72, 44, 59, 253, 139, 232, 234, 14, 112, 121, 43, 142, 193, 179, 140, 200,
      97, 234, 110, 63, 205, 24, 88, 116, 86, 184, 8, 19, 254, 204, 77, 84, 66, 238, 240, 69, 72, 21, 2, 65, 0, 233,
      103, 239, 11, 215, 10, 103, 66, 46, 155, 193, 79, 37, 64, 90, 12, 167, 189, 129, 8, 131, 94, 195, 8, 210, 236, 87,
      158, 140, 2, 82, 105, 80, 253, 13, 26, 140, 202, 194, 117, 59, 57, 197, 108, 50, 20, 46, 89, 248, 132, 120, 30,
      149, 180, 135, 134, 196, 156, 160, 123, 38, 253, 15, 7, 2, 65, 0, 218, 103, 122, 117, 154, 149, 213, 110, 24, 149,
      175, 208, 136, 249, 88, 91, 89, 180, 30, 243, 69, 130, 97, 252, 177, 216, 55, 46, 67, 15, 124, 56, 113, 57, 242,
      233, 185, 193, 254, 218, 76, 165, 184, 16, 109, 190, 93, 195, 227, 37, 58, 110, 243, 142, 152, 252, 226, 91, 59,
      145, 218, 35, 106, 123, 2, 65, 0, 210, 131, 88, 58, 32, 144, 148, 131, 63, 144, 97, 112, 165, 211, 125, 164, 110,
      97, 224, 16, 50, 148, 116, 105, 239, 251, 20, 39, 190, 117, 149, 168, 193, 80, 10, 210, 136, 107, 147, 169, 178,
      106, 47, 162, 159, 36, 78, 141, 253, 52, 85, 54, 152, 165, 131, 154, 204, 151, 203, 178, 103, 126, 212, 95, 2, 65,
      0, 193, 254, 80, 3, 205, 255, 112, 200, 142, 5, 199, 88, 207, 145, 203, 45, 185, 12, 8, 193, 196, 231, 254, 233,
      89, 126, 215, 228, 187, 164, 49, 142, 96, 228, 60, 35, 230, 223, 173, 227, 113, 89, 113, 153, 6, 33, 165, 95, 173,
      143, 15, 204, 37, 130, 111, 217, 143, 165, 193, 207, 215, 150, 197, 169, 2, 64, 7, 37, 152, 14, 232, 168, 102,
      169, 167, 97, 161, 33, 86, 178, 77, 140, 12, 114, 78, 129, 47, 103, 87, 217, 177, 80, 156, 91, 240, 149, 254, 90,
      69, 232, 10, 56, 232, 63, 59, 148, 254, 101, 63, 146, 66, 96, 25, 31, 37, 154, 77, 145, 201, 213, 122, 245, 90,
      251, 219, 42, 131, 248, 148, 151
    ])
  let expectPkdata =
    new Uint8Array([48, 129, 159, 48, 13, 6, 9, 42, 134, 72, 134, 247, 13, 1, 1, 1, 5, 0, 3, 129, 141, 0, 48, 129, 137,
      2, 129, 129, 0, 199, 32, 218, 8, 4, 63, 103, 229, 64, 128, 83, 31, 23, 156, 30, 168, 101, 22, 80, 100, 197, 243,
      217, 60, 127, 110, 127, 242, 8, 251, 87, 127, 235, 38, 226, 149, 149, 108, 54, 202, 53, 1, 21, 91, 118, 246, 97,
      93, 147, 117, 162, 71, 215, 70, 9, 175, 205, 241, 230, 187, 64, 170, 154, 67, 67, 254, 71, 1, 114, 10, 91, 195,
      34, 199, 85, 172, 255, 87, 95, 159, 43, 117, 73, 73, 199, 97, 198, 117, 217, 7, 188, 196, 30, 248, 9, 181, 150,
      243, 41, 145, 91, 8, 226, 161, 251, 12, 120, 28, 36, 146, 3, 196, 48, 243, 136, 201, 207, 131, 171, 22, 15, 7, 12,
      172, 135, 196, 30, 93, 2, 3, 1, 0, 1
    ])
  let skDataBlob: cryptoFramework.DataBlob = { data: skData };
  let rsaGenerator = cryptoFramework.createAsyKeyGenerator('RSA1024');
  try {
    let keyPair = rsaGenerator.convertKeySync(null, skDataBlob);
    let priKey = keyPair.priKey;
    let pubkey = priKey.getPubKeySync();
    let pkBlob = pubkey.getEncoded();
    console.info('pk1 bin data' + pkBlob.data);
    let ret: boolean = compareUint8Array(pkBlob.data, expectPkdata);
    console.info('result = ' + ret);
  } catch (e) {
    console.error(`get pubkey from prikey failed, ${e.code}, ${e.message}`);
  }
}
```

### getKeyData

getKeyData(itemType: AsyKeyDataItem): Promise\<Uint8Array>

Defines the key data type, which is used to obtain public key data of the corresponding type. This API uses a promise to return the result.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.Security.CryptoFramework.Key.AsymKey

**Parameters**

| Name| Type                 | Mandatory| Description                |
| ---- | --------------------- | ---- | -------------------- |
| itemType  | [AsyKeyDataItem](#asykeydataitem) | Yes  | Key data type.|

**Return value**

| Type                       | Description                             |
| --------------------------- | --------------------------------- |
| Promise\<Uint8Array> | Promise used to return the private key data of the specified key data type.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 17620001 | Memory operation failed. |
| 17620002 | Failed to obtain the native object or convert parameters. |
| 17620003 | Parameter check failed. |
| 17630001 | Crypto operation error. |

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';

async function eccGetKeyDataTest() {
  let eccGenerator = cryptoFramework.createAsyKeyGenerator('ECC_BrainPoolP256r1');
  let keyPair = await eccGenerator.generateKeyPair();
  let returnBlob = await keyPair.priKey.getKeyData(cryptoFramework.AsyKeyDataItem.EC_PRIVATE_04_X_Y_K);
  console.info('EC_PRIVATE_04_X_Y_K data: ' + returnBlob);
}
```

### getKeyDataSync

getKeyDataSync(itemType: AsyKeyDataItem): Uint8Array

Defines the key data type, which is used to obtain private key data of the corresponding type. This API returns the result synchronously.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.Security.CryptoFramework.Key.AsymKey

**Parameters**

| Name| Type                 | Mandatory| Description                |
| ---- | --------------------- | ---- | -------------------- |
| itemType  | [AsyKeyDataItem](#asykeydataitem) | Yes  | Key data type.|

**Return value**

| Type                       | Description                             |
| --------------------------- | --------------------------------- |
| Uint8Array | Private key data of the specified key data type.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 17620001 | Memory operation failed. |
| 17620002 | Failed to obtain the native object or convert parameters. |
| 17620003 | Parameter check failed. |
| 17630001 | Crypto operation error. |

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';

function eccGetKeyDataTest() {
  let eccGenerator = cryptoFramework.createAsyKeyGenerator('ECC_BrainPoolP256r1');
  let keyPair = eccGenerator.generateKeyPairSync();
  let returnBlob = keyPair.priKey.getKeyDataSync(cryptoFramework.AsyKeyDataItem.EC_PRIVATE_04_X_Y_K);
  console.info('EC_PRIVATE_04_X_Y_K data: ' + returnBlob);
}
```

## KeyPair

Defines an asymmetric key pair, which includes a public key and a private key.

The asymmetric key pair can be generated by using the asymmetric key generator [AsyKeyGenerator](#asykeygenerator) or [AsyKeyGeneratorBySpec](#asykeygeneratorbyspec10).

> **NOTE**
>
> The **pubKey** and **priKey** objects are members of the **KeyPair** object. When the **KeyPair** object is out of the scope, its **pubKey** and **priKey** objects will be destructed.
>
> The service must reference the **KeyPair** object instead of the internal **pubKey** or **priKey** object.

### Attributes

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Key.AsymKey
- API versions 9 to 11: SystemCapability.Security.CryptoFramework

| Name   | Type  | Read-Only| Optional| Description          |
| ------- | ------ | ---- | ---- | ------------ |
| priKey  | [PriKey](#prikey) | Yes  | No  | Private key.     |
| pubKey | [PubKey](#pubkey) | Yes  | No  | Public key.      |

## cryptoFramework.createSymKeyGenerator

createSymKeyGenerator(algName: string): SymKeyGenerator

Creates a **SymKeyGenerator** instance for the specified algorithm.

For details about the supported specifications, see [Symmetric Key Generation and Conversion Specifications](../../security/CryptoArchitectureKit/crypto-sym-key-generation-conversion-spec.md).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Key.SymKey
- API versions 9 to 11: SystemCapability.Security.CryptoFramework

**Parameters**

| Name | Type  | Mandatory| Description                                                        |
| ------- | ------ | ---- | ------------------------------------------------------------ |
| algName | string | Yes  | Algorithm to be used by the **symKeyGenerator** instance.<br>For details, see **String Parameter** in [Symmetric Key Generation and Conversion Specifications](../../security/CryptoArchitectureKit/crypto-sym-key-generation-conversion-spec.md).|

**Return value**

| Type                               | Description                      |
| ----------------------------------- | -------------------------- |
| [SymKeyGenerator](#symkeygenerator) | Returns the **SymKeyGenerator** instance created.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 801 | This operation is not supported. |

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';

let symKeyGenerator = cryptoFramework.createSymKeyGenerator('3DES192');
```

## SymKeyGenerator

Defines the method for generating a symmetric key. Before calling this method, you need to create a **SymKeyGenerator** instance by using the [createSymKeyGenerator](#cryptoframeworkcreatesymkeygenerator) method.

### Attributes

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Key.SymKey
- API versions 9 to 11: SystemCapability.Security.CryptoFramework

| Name   | Type  | Read-Only| Optional| Description                          |
| ------- | ------ | ---- | ---- | ------------------------------ |
| algName | string | Yes  | No  | Algorithm used by the **symKeyGenerator**.|

### generateSymKey

generateSymKey(callback: AsyncCallback\<SymKey>): void

Generates a random key using this symmetric key generator. This API uses an asynchronous callback to return the result.

**RAND_priv_bytes()** of OpenSSL can be used to generate random keys.

> **NOTE**
>
> For symmetric keys used in the HMAC algorithm, if a hash algorithm (for example, **HMAC\|SHA256**) is specified when the symmetric key generator is created, a binary key matching the hash length (for example, a 256-bit key) will be randomly generated. If no hash algorithm is specified, for example, only **HMAC** is specified, random symmetric key generation is not supported. You can generate symmetric key data using [convertKey](#convertkey).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Key.SymKey
- API versions 9 to 11: SystemCapability.Security.CryptoFramework

**Parameters**

| Name    | Type                             | Mandatory| Description                                                        |
| -------- | --------------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback\<[SymKey](#symkey)> | Yes  | Callback used to return the result. If the symmetric key is successfully generated, **err** is **undefined** and **data** is the symmetric key generated. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message     |
| -------- | ------------- |
| 17620001 | Memory operation failed. |
| 17620004 | Invalid function call. <br>Applicable versions: 26.0.0+|

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';

let symKeyGenerator = cryptoFramework.createSymKeyGenerator('3DES192');
  symKeyGenerator.generateSymKey((err, symKey) => {
    console.info('Generate symKey result: success, algName: ' + symKey.algName);
  });
```

### generateSymKey

generateSymKey(): Promise\<SymKey>

Generates a random key using this symmetric key generator. This API uses a promise to return the result.

**RAND_priv_bytes()** of OpenSSL can be used to generate random keys.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Key.SymKey
- API versions 9 to 11: SystemCapability.Security.CryptoFramework

**Return value**

| Type                       | Description                             |
| --------------------------- | --------------------------------- |
| Promise\<[SymKey](#symkey)> | Promise used to return the symmetric key generated.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message     |
| -------- | ------------- |
| 17620001 | Memory operation failed. |
| 17620004 | Invalid function call. <br>Applicable versions: 26.0.0+|

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { BusinessError } from '@kit.BasicServicesKit';

let symKeyGenerator = cryptoFramework.createSymKeyGenerator('AES128');
  symKeyGenerator.generateSymKey()
    .then(symKey => {
      console.info('Generate symKey result: success, algName: ' + symKey.algName);
    }).catch((error: BusinessError) => {
      console.error(`Generate symKey failed, ${error.code}, ${error.message}`);
    });
```

### generateSymKeySync<sup>12+</sup>

generateSymKeySync(): SymKey

Generates a random key using this symmetric key generator. This API returns the result synchronously.

**RAND_priv_bytes()** of OpenSSL can be used to generate random keys.

> **NOTE**
>
> For symmetric keys used in the HMAC algorithm, if a hash algorithm (for example, **HMAC\|SHA256**) is specified when the symmetric key generator is created, a binary key matching the hash length (for example, a 256-bit key) will be randomly generated.<br>If no hash algorithm is specified, for example, only **HMAC** is specified, random symmetric key generation is not supported. You can generate symmetric key data using [convertKeySync](#convertkeysync12).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Key.SymKey

**Return value**

| Type                       | Description                             |
| --------------------------- | --------------------------------- |
| [SymKey](#symkey) | Symmetric key generated.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message     |
| -------- | ------------- |
| 17620001 | Memory operation failed. |
| 17620004 | Invalid function call. <br>Applicable versions: 26.0.0+|

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';

function testGenerateSymKeySync() {
  // Create a SymKeyGenerator instance.
  let symKeyGenerator = cryptoFramework.createSymKeyGenerator('AES256');
  // Use SymKeyGenerator to randomly generate a symmetric key.
  let key = symKeyGenerator.generateSymKeySync();
  let encodedKey = key.getEncoded();
  console.info('key hex:' + encodedKey.data);
}
```

### convertKey

convertKey(key: DataBlob, callback: AsyncCallback\<SymKey>): void

Converts specified data into a symmetric key. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> For symmetric keys used in the HMAC algorithm, if a hash algorithm (for example, **HMAC\|SHA256**) is specified when the symmetric key generator is created, the binary key data passed in must match the hash length (for example, a 256-bit key for SHA256).<br>If no hash algorithm is specified when the symmetric key generator is created (for example, only **HMAC** is specified), any binary key data with a length of 1 to 4,096 bytes is supported.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Key.SymKey
- API versions 9 to 11: SystemCapability.Security.CryptoFramework

**Parameters**

| Name    | Type         | Mandatory| Description                      |
| -------- | ------------------- | ---- | ---------------------|
| key      | [DataBlob](#datablob)             | Yes  | Data to convert.                                        |
| callback | AsyncCallback\<[SymKey](#symkey)> | Yes  | Callback used to return the result. If the symmetric key is successfully generated, **err** is **undefined** and **data** is the symmetric key generated. Otherwise, **err** is an error object.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message                                              |
| -------- | --------------------------------------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | Memory operation failed.                                       |
| 17620003 | Parameter check failed. <br>Applicable versions: 26.0.0+                               |

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';

function genKeyMaterialBlob(): cryptoFramework.DataBlob {
  let arr = [
    0xba, 0x3d, 0xc2, 0x71, 0x21, 0x1e, 0x30, 0x56,
    0xad, 0x47, 0xfc, 0x5a, 0x46, 0x39, 0xee, 0x7c,
    0xba, 0x3b, 0xc2, 0x71, 0xab, 0xa0, 0x30, 0x72]; // keyLen = 192 (24 bytes)
  let keyMaterial = new Uint8Array(arr);
  return { data: keyMaterial };
}

function testConvertKey() {
  let symKeyGenerator = cryptoFramework.createSymKeyGenerator('3DES192');
  let keyMaterialBlob = genKeyMaterialBlob();
  symKeyGenerator.convertKey(keyMaterialBlob, (err, symKey) => {
    console.info('Convert symKey result: success, algName: ' + symKey.algName);
  });
}
```

### convertKey

convertKey(key: DataBlob): Promise\<SymKey>

Converts specified data into a symmetric key. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Key.SymKey
- API versions 9 to 11: SystemCapability.Security.CryptoFramework

**Parameters**

| Name| Type                 | Mandatory| Description                |
| ---- | --------------------- | ---- | -------------------- |
| key  | [DataBlob](#datablob) | Yes  | Data to convert.|

**Return value**

| Type                       | Description                             |
| --------------------------- | --------------------------------- |
| Promise\<[SymKey](#symkey)> | Promise used to return the symmetric key generated.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message                                         |
| -------- | --------------------------------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | Memory operation failed.                                |
| 17620003 | Parameter check failed. <br>Applicable versions: 26.0.0+                               |

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { BusinessError } from '@kit.BasicServicesKit';

function genKeyMaterialBlob(): cryptoFramework.DataBlob {
  let arr = [
    0xba, 0x3d, 0xc2, 0x71, 0x21, 0x1e, 0x30, 0x56,
    0xad, 0x47, 0xfc, 0x5a, 0x46, 0x39, 0xee, 0x7c,
    0xba, 0x3b, 0xc2, 0x71, 0xab, 0xa0, 0x30, 0x72]; // keyLen = 192 (24 bytes)
  let keyMaterial = new Uint8Array(arr);
  return { data: keyMaterial };
}

function testConvertKey() {
  let symKeyGenerator = cryptoFramework.createSymKeyGenerator('3DES192');
  let keyMaterialBlob = genKeyMaterialBlob();
  symKeyGenerator.convertKey(keyMaterialBlob)
    .then(symKey => {
      console.info('Convert symKey result: success, algName: ' + symKey.algName);
    }).catch((error: BusinessError) => {
      console.error(`Convert symKey failed, ${error.code}, ${error.message}`);
    });
}
```

### convertKeySync<sup>12+</sup>

convertKeySync(key: DataBlob): SymKey

Converts specified data into a symmetric key.

> **NOTE**
>
> For symmetric keys used in the HMAC algorithm, if a hash algorithm (for example, **HMAC\|SHA256**) is specified when the symmetric key generator is created, the binary key data passed in must match the hash length (for example, a 256-bit key for SHA256). If no hash algorithm is specified when the symmetric key generator is created (for example, only **HMAC** is specified), any binary key data with a length of 1 to 4,096 bytes is supported.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Key.SymKey

**Parameters**

| Name    | Type         | Mandatory| Description                      |
| -------- | ------------------- | ---- | ---------------------|
| key      | [DataBlob](#datablob)             | Yes  | Data to convert.                                        |

**Return value**

| Type                       | Description                             |
| --------------------------- | --------------------------------- |
| [SymKey](#symkey) | Symmetric key obtained.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message                                              |
| -------- | --------------------------------------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | Memory operation failed.                                       |
| 17620003 | Parameter check failed. <br>Applicable versions: 26.0.0+                                    |

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { buffer } from '@kit.ArkTS';

function testConvertKeySync() {
  // The symmetric key length is 64 bytes (512 bits).
  let keyMessage = '87654321abcdefgh87654321abcdefgh87654321abcdefgh87654321abcdefgh';
  let keyBlob: cryptoFramework.DataBlob = {
    data : new Uint8Array(buffer.from(keyMessage, 'utf-8').buffer)
  }
  let symKeyGenerator = cryptoFramework.createSymKeyGenerator('HMAC');
  let key = symKeyGenerator.convertKeySync(keyBlob);
  let encodedKey = key.getEncoded();
  console.info('key encoded data: ' + encodedKey.data);
}
```

## cryptoFramework.createAsyKeyGenerator

createAsyKeyGenerator(algName: string): AsyKeyGenerator

Creates an **AsyKeyGenerator** instance for the specified algorithm.

For details about the supported specifications, see [Asymmetric Key Generation and Conversion Specifications](../../security/CryptoArchitectureKit/crypto-asym-key-generation-conversion-spec.md).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Key.AsymKey
- API versions 9 to 11: SystemCapability.Security.CryptoFramework

**Parameters**

| Name | Type  | Mandatory| Description                            |
| ------- | ------ | ---- | -------------------------------- |
| algName | string | Yes  | Algorithm used by the asymmetric keys. For details, see the string parameters in [Asymmetric Key Generation and Conversion Specifications](../../security/CryptoArchitectureKit/crypto-asym-key-generation-conversion-spec.md).|

**Return value**

| Type           | Description                        |
| --------------- | ---------------------------- |
| [AsyKeyGenerator](#asykeygenerator) | **AsyKeyGenerator** instance created. |

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 801 | This operation is not supported. |
| 17620001 | Memory operation failed. |

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';

let asyKeyGenerator = cryptoFramework.createAsyKeyGenerator('ECC256');
```

## AsyKeyGenerator

Defines the method for generating an asymmetric key. Before calling this method, you need to create an **AsyKeyGenerator** instance by calling [createAsyKeyGenerator](#cryptoframeworkcreateasykeygenerator).

### Attributes

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Key.AsymKey
- API versions 9 to 11: SystemCapability.Security.CryptoFramework

| Name   | Type  | Read-Only| Optional| Description                            |
| ------- | ------ | ---- | ---- | -------------------------------- |
| algName | string | Yes  | No  | Algorithm used by the **AsKeyGenerator**.|

### generateKeyPair

generateKeyPair(callback: AsyncCallback\<KeyPair>): void

Generates a random key pair using this asymmetric key generator. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Key.AsymKey
- API versions 9 to 11: SystemCapability.Security.CryptoFramework

**Parameters**

| Name    | Type                   | Mandatory| Description                          |
| -------- | ----------------------- | ---- | ------------------------------ |
| callback | AsyncCallback\<[KeyPair](#keypair)> | Yes  | Callback used to return the result. If the asymmetric key is successfully obtained, **err** is **undefined** and **data** is the key pair generated. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | Invalid parameters. Possible causes: <br>Incorrect parameter types;|
| 17620001 | Memory operation failed.          |
| 17630001 | Crypto operation error.          |

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';

let asyKeyGenerator = cryptoFramework.createAsyKeyGenerator('ECC256');
asyKeyGenerator.generateKeyPair((err, keyPair) => {
  if (err) {
    console.error(`generateKeyPair failed, errCode: ${err.code}, errMsg: ${err.message}`);
    return;
  }
  console.info('generateKeyPair result: success.');
})
```

### generateKeyPair

generateKeyPair(): Promise\<KeyPair>

Generates a random key pair using this asymmetric key generator. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Key.AsymKey
- API versions 9 to 11: SystemCapability.Security.CryptoFramework

**Return value**

| Type             | Description                             |
| ----------------- | --------------------------------- |
| Promise\<[KeyPair](#keypair)> | Promise used to return the asymmetric key pair.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.         |
| 17620001 | Memory operation failed.          |
| 17630001 | Crypto operation error.          |

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { BusinessError } from '@kit.BasicServicesKit';

let asyKeyGenerator = cryptoFramework.createAsyKeyGenerator('ECC256');
let keyGenPromise = asyKeyGenerator.generateKeyPair();
keyGenPromise.then(keyPair => {
  console.info('generateKeyPair result: success.');
}).catch((error: BusinessError) => {
  console.error(`generateKeyPair failed, ${error.code}, ${error.message}`);
});
```

### generateKeyPairSync<sup>12+</sup>

generateKeyPairSync(): KeyPair

Generates a random key pair using this asymmetric key generator. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Key.AsymKey

**Return value**

| Type             | Description                             |
| ----------------- | --------------------------------- |
| [KeyPair](#keypair) | Asymmetric key pair.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.          |
| 17620001 | Memory operation failed.          |
| 17630001 | Crypto operation error.          |

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';

let asyKeyGenerator = cryptoFramework.createAsyKeyGenerator('ECC256');
try {
  let keyPairData = asyKeyGenerator.generateKeyPairSync();
  if (keyPairData != null) {
    console.info('[Sync]: key pair result: success.');
  } else {
    console.error('[Sync]: get key pair result: fail.');
  }
} catch (e) {
  console.error(`sync failed: errCode: ${e.code}, errMsg: ${e.message}`);
}
```

### convertKey

convertKey(pubKey: DataBlob, priKey: DataBlob, callback: AsyncCallback\<KeyPair\>): void

Converts the key data into an asymmetric key pair object. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Key.AsymKey
- API versions 9 to 11: SystemCapability.Security.CryptoFramework

**Parameters**

| Name  | Type                     | Mandatory| Description                                                        |
| ------ | ------------------------- | ---- | ------------------------------------------------------------ |
| pubKey | [DataBlob](#datablob)     | Yes  | Pointer to the public key data to convert.                                          |
| priKey | [DataBlob](#datablob)     | Yes  | Pointer to the private key data to convert.                                          |
| callback | AsyncCallback\<[KeyPair](#keypair)\> | Yes  | Callback used to return the result. If the conversion is successful, **err** is **undefined** and **data** is the converted key pair. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes,see [Universal Error Codes](../errorcode-universal.md) and [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message                                                |
| -------- | --------------------------------------------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | Memory operation failed.          |
| 17620003 | Parameter check failed. <br>Applicable versions: 26.0.0+|
| 17630001 | Crypto operation error.          |

### convertKey<sup>10+</sup>

convertKey(pubKey: DataBlob | null, priKey: DataBlob | null, callback: AsyncCallback\<KeyPair\>): void

Parses the key data and generates an asymmetric key object. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Key.AsymKey
- API versions 10 to 11: SystemCapability.Security.CryptoFramework

**Parameters**

| Name    | Type      | Mandatory| Description                          |
| -------- | ----------- | ---- | ------------------------------ |
| pubKey   | [DataBlob](#datablob) \| null<sup>10+</sup>    | Yes  | Public key material to convert. If no public key needs to be converted, set this parameter to **null**. In versions earlier than API version 10, only **DataBlob** is supported. Since API version 10, **null** is also supported.       |
| priKey   | [DataBlob](#datablob) \| null<sup>10+</sup>   | Yes  | Private key material to convert. If no private key needs to be converted, set this parameter to **null**. In versions earlier than API version 10, only **DataBlob** is supported. Since API version 10, **null** is also supported.       |
| callback | AsyncCallback\<[KeyPair](#keypair)> | Yes  | Callback used to return the result. If the asymmetric key is successfully obtained, **err** is **undefined** and **data** is the key pair generated. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | Memory operation failed.          |
| 17630001 | Crypto operation error.          |
| 17620003 | Parameter check failed. <br>Applicable versions: 26.0.0+|

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';

let pubKeyArray =
  new Uint8Array([48, 89, 48, 19, 6, 7, 42, 134, 72, 206, 61, 2, 1, 6, 8, 42, 134, 72, 206, 61, 3, 1, 7, 3, 66, 0, 4,
    83, 96, 142, 9, 86, 214, 126, 106, 247, 233, 92, 125, 4, 128, 138, 105, 246, 162, 215, 71, 81, 58, 202, 121, 26,
    105, 211, 55, 130, 45, 236, 143, 55, 16, 248, 75, 167, 160, 167, 106, 2, 152, 243, 44, 68, 66, 0, 167, 99, 92, 235,
    215, 159, 239, 28, 106, 124, 171, 34, 145, 124, 174, 57, 92]);
let priKeyArray =
  new Uint8Array([48, 49, 2, 1, 1, 4, 32, 115, 56, 137, 35, 207, 0, 60, 191, 90, 61, 136, 105, 210, 16, 27, 4, 171, 57,
    10, 61, 123, 40, 189, 28, 34, 207, 236, 22, 45, 223, 10, 189, 160, 10, 6, 8, 42, 134, 72, 206, 61, 3, 1, 7]);
let pubKeyBlob: cryptoFramework.DataBlob = { data: pubKeyArray }; // Binary data of the public key.
let priKeyBlob: cryptoFramework.DataBlob = { data: priKeyArray }; // Binary data of the private key.
let asyKeyGenerator = cryptoFramework.createAsyKeyGenerator('ECC256');
asyKeyGenerator.convertKey(pubKeyBlob, priKeyBlob, (err, keyPair) => {
  if (err) {
    console.error(`convertKey failed, errCode: ${err.code}, errMsg: ${err.message}`);
    return;
  }
  console.info('convertKey result: success.');
});
```

### convertKey

convertKey(pubKey: DataBlob, priKey: DataBlob): Promise\<KeyPair\>

Converts the key data into an asymmetric key pair object. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Key.AsymKey
- API versions 9 to 11: SystemCapability.Security.CryptoFramework

**Parameters**

| Name  | Type                     | Mandatory| Description                                                        |
| ------ | ------------------------- | ---- | ------------------------------------------------------------ |
| pubKey | [DataBlob](#datablob)     | Yes  | Pointer to the public key data to convert.                                          |
| priKey | [DataBlob](#datablob)     | Yes  | Pointer to the private key data to convert.                                          |

**Return value**

| Type                           | Description                                            |
| ------------------------------- | ------------------------------------------------ |
| Promise\<[KeyPair](#keypair)\> | Promise used to return the obtained asymmetric key pair.|

**Error codes**

For details about the error codes,see [Universal Error Codes](../errorcode-universal.md) and [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | Memory operation failed.                                     |
| 17620003 | Parameter check failed. <br>Applicable versions: 26.0.0+|
| 17630001 | Crypto operation error.          |

### convertKey<sup>10+</sup>

convertKey(pubKey: DataBlob | null, priKey: DataBlob | null): Promise\<KeyPair>

Parses the key data and generates an asymmetric key object. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Key.AsymKey
- API versions 10 to 11: SystemCapability.Security.CryptoFramework

**Parameters**

| Name  | Type   | Mandatory| Description            |
| ------ | -------- | ---- | ---------------- |
| pubKey | [DataBlob](#datablob) \| null<sup>10+</sup> | Yes  | Public key material to convert. If no public key needs to be converted, set this parameter to **null**. In versions earlier than API version 10, only **DataBlob** is supported. Since API version 10, **null** is also supported.|
| priKey | [DataBlob](#datablob) \| null<sup>10+</sup> | Yes  | Private key material to convert. If no private key needs to be converted, set this parameter to **null**. In versions earlier than API version 10, only **DataBlob** is supported. Since API version 10, **null** is also supported.|

**Return value**

| Type             | Description                             |
| ----------------- | --------------------------------- |
| Promise\<[KeyPair](#keypair)> | Promise used to return the asymmetric key pair.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | Memory operation failed.          |
| 17630001 | Crypto operation error.          |
| 17620003 | Parameter check failed. <br>Applicable versions: 26.0.0+|

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { BusinessError } from '@kit.BasicServicesKit';

let pubKeyArray =
  new Uint8Array([48, 89, 48, 19, 6, 7, 42, 134, 72, 206, 61, 2, 1, 6, 8, 42, 134, 72, 206, 61, 3, 1, 7, 3, 66, 0, 4,
    83, 96, 142, 9, 86, 214, 126, 106, 247, 233, 92, 125, 4, 128, 138, 105, 246, 162, 215, 71, 81, 58, 202, 121, 26,
    105, 211, 55, 130, 45, 236, 143, 55, 16, 248, 75, 167, 160, 167, 106, 2, 152, 243, 44, 68, 66, 0, 167, 99, 92, 235,
    215, 159, 239, 28, 106, 124, 171, 34, 145, 124, 174, 57, 92]);
let priKeyArray =
  new Uint8Array([48, 49, 2, 1, 1, 4, 32, 115, 56, 137, 35, 207, 0, 60, 191, 90, 61, 136, 105, 210, 16, 27, 4, 171, 57,
    10, 61, 123, 40, 189, 28, 34, 207, 236, 22, 45, 223, 10, 189, 160, 10, 6, 8, 42, 134, 72, 206, 61, 3, 1, 7]);
let pubKeyBlob: cryptoFramework.DataBlob = { data: pubKeyArray }; // Binary data of the public key.
let priKeyBlob: cryptoFramework.DataBlob = { data: priKeyArray }; // Binary data of the private key.
let asyKeyGenerator = cryptoFramework.createAsyKeyGenerator('ECC256');
let keyGenPromise = asyKeyGenerator.convertKey(pubKeyBlob, priKeyBlob);
keyGenPromise.then(keyPair => {
  console.info('convertKey result: success.');
}).catch((error: BusinessError) => {
  console.error(`convertKey failed, errCode: ${error.code}, errMsg: ${error.message}`);
});
```

### convertKeySync<sup>12+</sup>

convertKeySync(pubKey: DataBlob | null, priKey: DataBlob | null): KeyPair

Parses the key data and generates an asymmetric key object. This API is synchronous.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Key.AsymKey

**Parameters**

| Name  | Type   | Mandatory| Description            |
| ------ | -------- | ---- | ---------------- |
| pubKey | [DataBlob](#datablob) \| null<sup>10+</sup> | Yes  | Public key material. If no public key needs to be converted, set this parameter to **null**. Before API version 10, only **DataBlob** is supported. Since API version 10s, **null** can be passed in.|
| priKey | [DataBlob](#datablob) \| null<sup>10+</sup> | Yes  | Private key material. If no private key needs to be converted, set this parameter to **null**. Before API version 10, only **DataBlob** is supported. Since API version 10s, **null** can be passed in.|

**Return value**

| Type             | Description                             |
| ----------------- | --------------------------------- |
| [KeyPair](#keypair) | Asymmetric key pair.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | Memory operation failed.          |
| 17630001 | Crypto operation error.          |
| 17620003 | Parameter check failed. <br>Applicable versions: 26.0.0+|

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';

let pubKeyArray =
  new Uint8Array([48, 89, 48, 19, 6, 7, 42, 134, 72, 206, 61, 2, 1, 6, 8, 42, 134, 72, 206, 61, 3, 1, 7, 3, 66, 0, 4,
    83, 96, 142, 9, 86, 214, 126, 106, 247, 233, 92, 125, 4, 128, 138, 105, 246, 162, 215, 71, 81, 58, 202, 121, 26,
    105, 211, 55, 130, 45, 236, 143, 55, 16, 248, 75, 167, 160, 167, 106, 2, 152, 243, 44, 68, 66, 0, 167, 99, 92, 235,
    215, 159, 239, 28, 106, 124, 171, 34, 145, 124, 174, 57, 92]);
let priKeyArray =
  new Uint8Array([48, 49, 2, 1, 1, 4, 32, 115, 56, 137, 35, 207, 0, 60, 191, 90, 61, 136, 105, 210, 16, 27, 4, 171, 57,
    10, 61, 123, 40, 189, 28, 34, 207, 236, 22, 45, 223, 10, 189, 160, 10, 6, 8, 42, 134, 72, 206, 61, 3, 1, 7]);
let pubKeyBlob: cryptoFramework.DataBlob = { data: pubKeyArray }; // Binary data of the public key.
let priKeyBlob: cryptoFramework.DataBlob = { data: priKeyArray }; // Binary data of the private key.
let asyKeyGenerator = cryptoFramework.createAsyKeyGenerator('ECC256');
try {
  let keyPairData = asyKeyGenerator.convertKeySync(pubKeyBlob, priKeyBlob);
  if (keyPairData != null) {
    console.info('[Sync]: key pair result: success.');
  } else {
    console.error('[Sync]: convert key pair result: fail.');
  }
} catch (e) {
  console.error(`sync failed: errCode: ${e.code}, errMsg: ${e.message}`);
}
```

### convertPemKey<sup>12+</sup>

convertPemKey(pubKey: string | null, priKey: string | null): Promise\<KeyPair>

Parses the key data and generates an asymmetric key object. This API uses a promise to return the result.

> **NOTE**
> 1. When **convertPemKey()** is used to convert an external string into an asymmetric key object defined by the Crypto framework, the public key must comply with the ASN.1 syntax, X.509 specifications, and PEM encoding format, and the private key must comply with the ASN.1 syntax, PKCS #8 specifications, and PEM encoding format.
> 2. In **convertPemKey()**, you can pass in either **pubKey** or **priKey**, or both of them. If one of them is passed in, the returned **KeyPair** instance contains only the key converted from the data you passed in.
> 3. When **convertPemKey** is used to convert an external string into an asymmetric key object defined by the Crypto framework, the system does not verify whether the specifications of the generated key object are the same as the key specifications specified for the asymmetric key generator.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Key.AsymKey

**Parameters**

| Name  | Type   | Mandatory| Description            |
| ------ | -------- | ---- | ---------------- |
| pubKey | string \| null | Yes | Public key material to convert. If no public key needs to be converted, set this parameter to **null**.|
| priKey | string \| null | Yes | Private key material to convert. If no private key needs to be converted, set this parameter to **null**.<br>Note: The public key and private key materials cannot be both null or empty strings.|

**Return value**

| Type             | Description                             |
| ----------------- | --------------------------------- |
| Promise\<[KeyPair](#keypair)> | Promise used to return the asymmetric key pair.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.         |
| 17620001 | Memory operation failed.          |
| 17630001 | Crypto operation error.          |
| 17620003 | Parameter check failed. <br>Applicable versions: 26.0.0+|

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { BusinessError } from '@kit.BasicServicesKit';

let priKeyPkcs1Str1024: string =
  '-----BEGIN RSA PRIVATE KEY-----\n'
    + 'MIICXQIBAAKBgQCwIN3mr21+N96ToxnVnaS+xyK9cNRAHiHGgrbjHw6RAj3V+l+W\n'
    + 'Y68IhIe3DudVlzE9oMjeOQwkMkq//HCxNlIlFR6O6pa0mrXSwPRE7YKG97CeKk2g\n'
    + 'YOS8YEh8toAvm7xKbiLkXuuMlxrjP2j/mb5iI/UASFSPZiQ/IyxDr0AQaQIDAQAB\n'
    + 'AoGAEvBFzBNa+7J4PXnRQlYEK/tvsd0bBZX33ceacMubHl6WVZbphltLq+fMTBPP\n'
    + 'LjXmtpC+aJ7Lvmyl+wTi/TsxE9vxW5JnbuRT48rnZ/Xwq0eozDeEeIBRrpsr7Rvr\n'
    + '7ctrgzr4m4yMHq9aDgpxj8IR7oHkfwnmWr0wM3FuiVlj650CQQDineeNZ1hUTkj4\n'
    + 'D3O+iCi3mxEVEeJrpqrmSFolRMb+iozrIRKuJlgcOs+Gqi2fHfOTTL7LkpYe8SVg\n'
    + 'e3JxUdVLAkEAxvcZXk+byMFoetrnlcMR13VHUpoVeoV9qkv6CAWLlbMdgf7uKmgp\n'
    + 'a1Yp3QPDNQQqkPvrqtfR19JWZ4uy1qREmwJALTU3BjyBoH/liqb6fh4HkWk75Som\n'
    + 'MzeSjFIOubSYxhq5tgZpBZjcpvUMhV7Zrw54kwASZ+YcUJvmyvKViAm9NQJBAKF7\n'
    + 'DyXSKrem8Ws0m1ybM7HQx5As6l3EVhePDmDQT1eyRbKp+xaD74nkJpnwYdB3jyyY\n'
    + 'qc7A1tj5J5NmeEFolR0CQQCn76Xp8HCjGgLHw9vg7YyIL28y/XyfFyaZAzzK+Yia\n'
    + 'akNwQ6NeGtXSsuGCcyyfpacHp9xy8qXQNKSkw03/5vDO\n'
    + '-----END RSA PRIVATE KEY-----\n';
let publicPkcs1Str1024: string =
  '-----BEGIN RSA PUBLIC KEY-----\n'
    + 'MIGJAoGBALAg3eavbX433pOjGdWdpL7HIr1w1EAeIcaCtuMfDpECPdX6X5ZjrwiE\n'
    + 'h7cO51WXMT2gyN45DCQySr/8cLE2UiUVHo7qlrSatdLA9ETtgob3sJ4qTaBg5Lxg\n'
    + 'SHy2gC+bvEpuIuRe64yXGuM/aP+ZvmIj9QBIVI9mJD8jLEOvQBBpAgMBAAE=\n'
    + '-----END RSA PUBLIC KEY-----\n';

async function TestConvertPemKeyByPromise() {
  let asyKeyGenerator = cryptoFramework.createAsyKeyGenerator('RSA1024');
  asyKeyGenerator.convertPemKey(publicPkcs1Str1024, priKeyPkcs1Str1024)
    .then(keyPair => {
      console.info('convertPemKey result: success.');
    }).catch((error: BusinessError) => {
    console.error(`convertPemKey failed: errCode: ${error.code}, errMsg: ${error.message}`);
  });
}
```

### convertPemKey<sup>18+</sup>

convertPemKey(pubKey: string | null, priKey: string | null, password: string): Promise\<KeyPair>

Parses the key data and generates an asymmetric key object. Encrypted private keys are supported. The private key password is synchronously passed to decrypt the private key. This API uses a promise to return the result.

> **NOTE**
> 1. When **convertPemKey()** is used to convert an external string into an asymmetric key object defined by the Crypto framework, the public key must comply with the ASN.1 syntax, X.509 specifications, and PEM encoding format, and the private key must comply with the ASN.1 syntax, PKCS #8 specifications, and PEM encoding format.
> 2. In **convertPemKey()**, you can pass in either **pubKey** or **priKey**, or both of them. If one of them is passed in, the returned **KeyPair** instance contains only the key converted from the data you passed in.
> 3. When **convertPemKey** is used to convert an external string into an asymmetric key object defined by the Crypto framework, the system does not verify whether the specifications of the generated key object are the same as the key specifications specified for the asymmetric key generator.
> 4. If **password** is passed in, it can be used to decrypt the encrypted private key.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Security.CryptoFramework.Key.AsymKey

**Parameters**

| Name  | Type   | Mandatory| Description            |
| ------ | -------- | ---- | ---------------- |
| pubKey | string \| null | Yes | Public key material to convert. If no public key needs to be converted, set this parameter to **null**.|
| priKey | string \| null | Yes | Private key material to convert. If no private key needs to be converted, set this parameter to **null**.<br>Note: The public key and private key materials cannot be both null or empty strings.|
| password | string | Yes| Password used to decrypt the private key.|

**Return value**

| Type             | Description                             |
| ----------------- | --------------------------------- |
| Promise\<[KeyPair](#keypair)> | Promise used to return the asymmetric key pair.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.         |
| 17620001 | Memory operation failed.          |
| 17630001 | Crypto operation error.          |

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { BusinessError } from '@kit.BasicServicesKit';

let priKeyPkcs1EncodingStr: string =
  '-----BEGIN RSA PRIVATE KEY-----\n'
    + 'Proc-Type: 4,ENCRYPTED\n'
    + 'DEK-Info: AES-128-CBC,815A066131BF05CF87CE610A59CC69AE\n\n'
    + '7Jd0vmOmYGFZ2yRY8fqRl3+6rQlFtNcMILvcb5KWHDSrxA0ULmJE7CW0DSRikHoA\n'
    + 't0KgafhYXeQXh0dRy9lvVRAFSLHCLJVjchx90V7ZSivBFEq7+iTozVp4AlbgYsJP\n'
    + 'vx/1sfZD2WAcyMJ7IDmJyft7xnpVSXsyWGTT4f3eaHJIh1dqjwrso7ucAW0FK6rp\n'
    + '/TONyOoXNfXtRbVtxNyCWBxt4HCSclDZFvS9y8fz9ZwmCUV7jei/YdzyQI2wnE13\n'
    + 'W8cKlpzRFL6BWi8XPrUtAw5MWeHBAPUgPWMfcmiaeyi5BJFhQCrHLi+Gj4EEJvp7\n'
    + 'mP5cbnQAx6+paV5z9m71SKrI/WSc4ixsYYdVmlL/qwAK9YliFfoPl030YJWW6rFf\n'
    + 'T7J9BUlHGUJ0RB2lURNNLakM+UZRkeE9TByzCzgTxuQtyv5Lwsh2mAk3ia5x0kUO\n'
    + 'LHg3Eoabhdh+YZA5hHaxnpF7VjspB78E0F9Btq+A41rSJ6zDOdToHey4MJ2nxdey\n'
    + 'Z3bi81TZ6Fp4IuROrvZ2B/Xl3uNKR7n+AHRKnaAO87ywzyltvjwSh2y3xhJueiRs\n'
    + 'BiYkyL3/fnocD3pexTdN6h3JgQGgO5GV8zw/NrxA85mw8o9im0HreuFObmNj36T9\n'
    + 'k5N+R/QIXW83cIQOLaWK1ThYcluytf0tDRiMoKqULiaA6HvDMigExLxuhCtnoF8I\n'
    + 'iOLN1cPdEVQjzwDHLqXP2DbWW1z9iRepLZlEm1hLRLEmOrTGKezYupVv306SSa6J\n'
    + 'OA55lAeXMbyjFaYCr54HWrpt4NwNBX1efMUURc+1LcHpzFrBTTLbfjIyq6as49pH\n'
    + '-----END RSA PRIVATE KEY-----\n'

async function TestConvertPemKeyByPromise() {
  let asyKeyGenerator = cryptoFramework.createAsyKeyGenerator('RSA1024');
  asyKeyGenerator.convertPemKey(null, priKeyPkcs1EncodingStr, '123456')
    .then(keyPair => {
      console.info('convertPemKey result: success.');
    }).catch((error: BusinessError) => {
    console.error(`convertPemKey failed: errCode: ${error.code}, errMsg: ${error.message}`);
  });
}
```

### convertPemKeySync<sup>12+</sup>

convertPemKeySync(pubKey: string | null, priKey: string | null): KeyPair

Converts data into an asymmetric key pair. This API returns the result synchronously.

> **NOTE**
> The precautions for using **convertPemKeySync** are the same as those for **convertPemKey**. For details, see the description of [convertPemKey](#convertpemkey12).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Key.AsymKey

**Parameters**

| Name  | Type   | Mandatory| Description            |
| ------ | -------- | ---- | ---------------- |
| pubKey | string \| null| Yes  | Public key material to convert. If no public key needs to be converted, set this parameter to **null**.|
| priKey | string \| null| Yes  | Private key material. If no private key needs to be converted, set this parameter to **null**.<br>Note: The public key and private key materials cannot be both null or empty strings.|

**Return value**

| Type             | Description                             |
| ----------------- | --------------------------------- |
| [KeyPair](#keypair) | Asymmetric key pair.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.         |
| 17620001 | Memory operation failed.          |
| 17630001 | Crypto operation error.          |
| 17620003 | Parameter check failed. <br>Applicable versions: 26.0.0+|

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';

let priKeyPkcs1Str1024: string =
  '-----BEGIN RSA PRIVATE KEY-----\n'
    + 'MIICXQIBAAKBgQCwIN3mr21+N96ToxnVnaS+xyK9cNRAHiHGgrbjHw6RAj3V+l+W\n'
    + 'Y68IhIe3DudVlzE9oMjeOQwkMkq//HCxNlIlFR6O6pa0mrXSwPRE7YKG97CeKk2g\n'
    + 'YOS8YEh8toAvm7xKbiLkXuuMlxrjP2j/mb5iI/UASFSPZiQ/IyxDr0AQaQIDAQAB\n'
    + 'AoGAEvBFzBNa+7J4PXnRQlYEK/tvsd0bBZX33ceacMubHl6WVZbphltLq+fMTBPP\n'
    + 'LjXmtpC+aJ7Lvmyl+wTi/TsxE9vxW5JnbuRT48rnZ/Xwq0eozDeEeIBRrpsr7Rvr\n'
    + '7ctrgzr4m4yMHq9aDgpxj8IR7oHkfwnmWr0wM3FuiVlj650CQQDineeNZ1hUTkj4\n'
    + 'D3O+iCi3mxEVEeJrpqrmSFolRMb+iozrIRKuJlgcOs+Gqi2fHfOTTL7LkpYe8SVg\n'
    + 'e3JxUdVLAkEAxvcZXk+byMFoetrnlcMR13VHUpoVeoV9qkv6CAWLlbMdgf7uKmgp\n'
    + 'a1Yp3QPDNQQqkPvrqtfR19JWZ4uy1qREmwJALTU3BjyBoH/liqb6fh4HkWk75Som\n'
    + 'MzeSjFIOubSYxhq5tgZpBZjcpvUMhV7Zrw54kwASZ+YcUJvmyvKViAm9NQJBAKF7\n'
    + 'DyXSKrem8Ws0m1ybM7HQx5As6l3EVhePDmDQT1eyRbKp+xaD74nkJpnwYdB3jyyY\n'
    + 'qc7A1tj5J5NmeEFolR0CQQCn76Xp8HCjGgLHw9vg7YyIL28y/XyfFyaZAzzK+Yia\n'
    + 'akNwQ6NeGtXSsuGCcyyfpacHp9xy8qXQNKSkw03/5vDO\n'
    + '-----END RSA PRIVATE KEY-----\n';
let publicPkcs1Str1024: string =
  '-----BEGIN RSA PUBLIC KEY-----\n'
    + 'MIGJAoGBALAg3eavbX433pOjGdWdpL7HIr1w1EAeIcaCtuMfDpECPdX6X5ZjrwiE\n'
    + 'h7cO51WXMT2gyN45DCQySr/8cLE2UiUVHo7qlrSatdLA9ETtgob3sJ4qTaBg5Lxg\n'
    + 'SHy2gC+bvEpuIuRe64yXGuM/aP+ZvmIj9QBIVI9mJD8jLEOvQBBpAgMBAAE=\n'
    + '-----END RSA PUBLIC KEY-----\n';

function TestConvertPemKeyBySync() {
  let asyKeyGenerator = cryptoFramework.createAsyKeyGenerator('RSA1024');
  try {
    let keyPairData = asyKeyGenerator.convertPemKeySync(publicPkcs1Str1024, priKeyPkcs1Str1024);
    if (keyPairData != null) {
      console.info('[Sync]: convert pem key pair result: success.');
    } else {
      console.error('[Sync]: convert pem key pair result: fail.');
    }
  } catch (e) {
    console.error(`Sync failed: errCode: ${e.code}, errMsg: ${e.message}`);
  }
}
```

### convertPemKeySync<sup>18+</sup>

convertPemKeySync(pubKey: string | null, priKey: string | null, password: string): KeyPair

Parses the key data and generates an asymmetric key object. Encrypted private keys are supported. The private key password is synchronously passed to decrypt the private key.

> **NOTE**
> The precautions for using **convertPemKeySync** are the same as those for [convertPemKey](#convertpemkey18).

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Security.CryptoFramework.Key.AsymKey

**Parameters**

| Name  | Type   | Mandatory| Description            |
| ------ | -------- | ---- | ---------------- |
| pubKey | string \| null| Yes  | Public key material to convert. If no public key needs to be converted, set this parameter to **null**.|
| priKey | string \| null| Yes  | Private key material. If no private key needs to be converted, set this parameter to **null**. <br>Note: **pubKey** and **priKey** cannot be **null** at the same time.|
| password | string | Yes| Password used to decrypt the private key.|

**Return value**

| Type             | Description                             |
| ----------------- | --------------------------------- |
| [KeyPair](#keypair) | Asymmetric key pair.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.         |
| 17620001 | Memory operation failed.          |
| 17630001 | Crypto operation error.          |

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';

let priKeyPkcs1EncodingStr: string =
  '-----BEGIN RSA PRIVATE KEY-----\n'
    + 'Proc-Type: 4,ENCRYPTED\n'
    + 'DEK-Info: AES-128-CBC,815A066131BF05CF87CE610A59CC69AE\n\n'
    + '7Jd0vmOmYGFZ2yRY8fqRl3+6rQlFtNcMILvcb5KWHDSrxA0ULmJE7CW0DSRikHoA\n'
    + 't0KgafhYXeQXh0dRy9lvVRAFSLHCLJVjchx90V7ZSivBFEq7+iTozVp4AlbgYsJP\n'
    + 'vx/1sfZD2WAcyMJ7IDmJyft7xnpVSXsyWGTT4f3eaHJIh1dqjwrso7ucAW0FK6rp\n'
    + '/TONyOoXNfXtRbVtxNyCWBxt4HCSclDZFvS9y8fz9ZwmCUV7jei/YdzyQI2wnE13\n'
    + 'W8cKlpzRFL6BWi8XPrUtAw5MWeHBAPUgPWMfcmiaeyi5BJFhQCrHLi+Gj4EEJvp7\n'
    + 'mP5cbnQAx6+paV5z9m71SKrI/WSc4ixsYYdVmlL/qwAK9YliFfoPl030YJWW6rFf\n'
    + 'T7J9BUlHGUJ0RB2lURNNLakM+UZRkeE9TByzCzgTxuQtyv5Lwsh2mAk3ia5x0kUO\n'
    + 'LHg3Eoabhdh+YZA5hHaxnpF7VjspB78E0F9Btq+A41rSJ6zDOdToHey4MJ2nxdey\n'
    + 'Z3bi81TZ6Fp4IuROrvZ2B/Xl3uNKR7n+AHRKnaAO87ywzyltvjwSh2y3xhJueiRs\n'
    + 'BiYkyL3/fnocD3pexTdN6h3JgQGgO5GV8zw/NrxA85mw8o9im0HreuFObmNj36T9\n'
    + 'k5N+R/QIXW83cIQOLaWK1ThYcluytf0tDRiMoKqULiaA6HvDMigExLxuhCtnoF8I\n'
    + 'iOLN1cPdEVQjzwDHLqXP2DbWW1z9iRepLZlEm1hLRLEmOrTGKezYupVv306SSa6J\n'
    + 'OA55lAeXMbyjFaYCr54HWrpt4NwNBX1efMUURc+1LcHpzFrBTTLbfjIyq6as49pH\n'
    + '-----END RSA PRIVATE KEY-----\n'

function TestConvertPemKeyBySync() {
  let asyKeyGenerator = cryptoFramework.createAsyKeyGenerator('RSA1024');
  try {
    let keyPairData = asyKeyGenerator.convertPemKeySync(null, priKeyPkcs1EncodingStr, '123456');
    if (keyPairData != null) {
      console.info('[Sync]: convert pem key pair result: success.');
    } else {
      console.error('[Sync]: convert pem key pair result: fail.');
    }
  } catch (e) {
    console.error(`Sync failed: errCode: ${e.code}, errMsg: ${e.message}`);
  }
}
```

## cryptoFramework.createAsyKeyGeneratorBySpec<sup>10+</sup>

createAsyKeyGeneratorBySpec(asyKeySpec: AsyKeySpec): AsyKeyGeneratorBySpec

Creates an **AsyKeyGenerator** instance with specified key specifications.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Key.AsymKey
- API versions 10 to 11: SystemCapability.Security.CryptoFramework

**Parameters**

| Name | Type  | Mandatory| Description                            |
| ------- | ------ | ---- | -------------------------------- |
| asyKeySpec | [AsyKeySpec](#asykeyspec10) | Yes  | Key parameters. The **AsyKeyGenerator** generates the public/private key based on the specified parameters.<br>For details about the supported specifications, see [Asymmetric Key Generation and Conversion Specifications](../../security/CryptoArchitectureKit/crypto-asym-key-generation-conversion-spec.md).|

**Return value**

| Type                                           | Description                      |
| ----------------------------------------------- | -------------------------- |
| [AsyKeyGeneratorBySpec](#asykeygeneratorbyspec10) | **AsyKeyGeneratorBySpec** instance.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 801 | This operation is not supported. |
| 17620001 | Memory operation failed. |

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';

// Set the common parameters of the DSA1024 public and private keys.
function genDsa1024CommonSpecBigE() {
  let dsaCommonSpec: cryptoFramework.DSACommonParamsSpec = {
    algName: 'DSA',
    specType: cryptoFramework.AsyKeySpecType.COMMON_PARAMS_SPEC,
    p: BigInt('0xed1501551b8ab3547f6355ffdc2913856ddeca198833dbd04f020e5f25e47c50e0b3894f7690a0d2ea5ed3a7be25c54292a698e1f086eb3a97deb4dbf04fcad2dafd94a9f35c3ae338ab35477e16981ded6a5b13d5ff20bf55f1b262303ad3a80af71aa6aa2354d20e9c82647664bdb6b333b7bea0a5f49d55ca40bc312a1729'),
    q: BigInt('0xd23304044019d5d382cfeabf351636c7ab219694ac845051f60b047b'),
    g: BigInt('0x2cc266d8bd33c3009bd67f285a257ba74f0c3a7e12b722864632a0ac3f2c17c91c2f3f67eb2d57071ef47aaa8f8e17a21ad2c1072ee1ce281362aad01dcbcd3876455cd17e1dd55d4ed36fa011db40f0bbb8cba01d066f392b5eaa9404bfcb775f2196a6bc20eeec3db32d54e94d87ecdb7a0310a5a017c5cdb8ac78597778bd'),
  }
  return dsaCommonSpec;
}

// Set full parameters of the DSA1024 key pair.
function genDsa1024KeyPairSpecBigE() {
  let dsaCommonSpec = genDsa1024CommonSpecBigE();
  let dsaKeyPairSpec: cryptoFramework.DSAKeyPairSpec = {
    algName: 'DSA',
    specType: cryptoFramework.AsyKeySpecType.KEY_PAIR_SPEC,
    params: dsaCommonSpec,
    sk: BigInt('0xa2dd2adb2d11392c2541930f61f1165c370aabd2d78d00342e0a2fd9'),
    pk: BigInt('0xae6b5d5042e758f3fc9a02d009d896df115811a75b5f7b382d8526270dbb3c029403fafb8573ba4ef0314ea86f09d01e82a14d1ebb67b0c331f41049bd6b1842658b0592e706a5e4d20c14b67977e17df7bdd464cce14b5f13bae6607760fcdf394e0b73ac70aaf141fa4dafd736bd0364b1d6e6c0d7683a5de6b9221e7f2d6b'),
  }
  return dsaKeyPairSpec;
}

let asyKeyPairSpec = genDsa1024KeyPairSpecBigE(); // The input in JS must be a positive number in big-endian format.
let asyKeyGeneratorBySpec = cryptoFramework.createAsyKeyGeneratorBySpec(asyKeyPairSpec);
```

## AsyKeyGeneratorBySpec<sup>10+</sup>

Defines the method for generating an asymmetric key based on the specified key specifications. Before calling this method, you need to create an **AsyKeyGeneratorBySpec** instance by using the [createAsyKeyGeneratorBySpec()](#cryptoframeworkcreateasykeygeneratorbyspec10) method.

### Attributes

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Key.AsymKey
- API versions 10 to 11: SystemCapability.Security.CryptoFramework

| Name   | Type  | Read-Only| Optional| Description                      |
| ------- | ------ | ---- | ---- | -------------------------- |
| algName | string | Yes  | No  | Algorithm used by the asymmetric key generator.|

### generateKeyPair<sup>10+</sup>

generateKeyPair(callback: AsyncCallback\<KeyPair>): void

Generates a key pair using this asymmetric key generator. This API uses an asynchronous callback to return the result.

If a key parameter of the [COMMON_PARAMS_SPEC](#asykeyspectype10) type is used to create the key generator, a key pair will be randomly generated. If a key parameter of the [KEY_PAIR_SPEC](#asykeyspectype10) type is used to create the key generator, you can obtain a key pair that is consistent with the specified key parameters.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Key.AsymKey
- API versions 10 to 11: SystemCapability.Security.CryptoFramework

**Parameters**

| Name    | Type                   | Mandatory| Description                          |
| -------- | ----------------------- | ---- | ------------------------------ |
| callback | AsyncCallback\<[KeyPair](#keypair)> | Yes  | Callback used to return the result. If the asymmetric key is successfully obtained, **err** is **undefined** and **data** is the key pair generated. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message               |
| -------- | ----------------------- |
| 401 | Invalid parameters. Possible causes: <br>Incorrect parameter types;         |
| 17620001 | Memory operation failed.           |
| 17630001 | Crypto operation error. |

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';

// Set the common parameters of the DSA1024 public and private keys.
function genDsa1024CommonSpecBigE() {
  let dsaCommonSpec: cryptoFramework.DSACommonParamsSpec = {
    algName: 'DSA',
    specType: cryptoFramework.AsyKeySpecType.COMMON_PARAMS_SPEC,
    p: BigInt('0xed1501551b8ab3547f6355ffdc2913856ddeca198833dbd04f020e5f25e47c50e0b3894f7690a0d2ea5ed3a7be25c54292a698e1f086eb3a97deb4dbf04fcad2dafd94a9f35c3ae338ab35477e16981ded6a5b13d5ff20bf55f1b262303ad3a80af71aa6aa2354d20e9c82647664bdb6b333b7bea0a5f49d55ca40bc312a1729'),
    q: BigInt('0xd23304044019d5d382cfeabf351636c7ab219694ac845051f60b047b'),
    g: BigInt('0x2cc266d8bd33c3009bd67f285a257ba74f0c3a7e12b722864632a0ac3f2c17c91c2f3f67eb2d57071ef47aaa8f8e17a21ad2c1072ee1ce281362aad01dcbcd3876455cd17e1dd55d4ed36fa011db40f0bbb8cba01d066f392b5eaa9404bfcb775f2196a6bc20eeec3db32d54e94d87ecdb7a0310a5a017c5cdb8ac78597778bd'),
  }
  return dsaCommonSpec;
}

// Set full parameters of the DSA1024 key pair.
function genDsa1024KeyPairSpecBigE() {
  let dsaCommonSpec = genDsa1024CommonSpecBigE();
  let dsaKeyPairSpec: cryptoFramework.DSAKeyPairSpec = {
    algName: 'DSA',
    specType: cryptoFramework.AsyKeySpecType.KEY_PAIR_SPEC,
    params: dsaCommonSpec,
    sk: BigInt('0xa2dd2adb2d11392c2541930f61f1165c370aabd2d78d00342e0a2fd9'),
    pk: BigInt('0xae6b5d5042e758f3fc9a02d009d896df115811a75b5f7b382d8526270dbb3c029403fafb8573ba4ef0314ea86f09d01e82a14d1ebb67b0c331f41049bd6b1842658b0592e706a5e4d20c14b67977e17df7bdd464cce14b5f13bae6607760fcdf394e0b73ac70aaf141fa4dafd736bd0364b1d6e6c0d7683a5de6b9221e7f2d6b'),
  }
  return dsaKeyPairSpec;
}

function testGenerateKeyPair() {
  let asyKeyPairSpec = genDsa1024KeyPairSpecBigE(); // The input in JS must be a positive number in big-endian format.
  let asyKeyGeneratorBySpec = cryptoFramework.createAsyKeyGeneratorBySpec(asyKeyPairSpec);
  asyKeyGeneratorBySpec.generateKeyPair((err, keyPair) => {
    if (err) {
      console.error(`generateKeyPair failed, errCode: ${err.code}, errMsg: ${err.message}`);
      return;
    }
    console.info('generateKeyPair result: success.');
  })
}
```

### generateKeyPair<sup>10+</sup>

generateKeyPair(): Promise\<KeyPair>

Generates a key pair using this asymmetric key generator. This API uses a promise to return the result.

If a key parameter of the [COMMON_PARAMS_SPEC](#asykeyspectype10) type is used to create the key generator, a key pair will be randomly generated. If a key parameter of the [KEY_PAIR_SPEC](#asykeyspectype10) type is used to create the key generator, you can obtain a key pair that is consistent with the specified key parameters.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Key.AsymKey
- API versions 10 to 11: SystemCapability.Security.CryptoFramework

**Return value**

| Type             | Description                             |
| ----------------- | --------------------------------- |
| Promise\<[KeyPair](#keypair)> | Promise used to return the asymmetric key pair.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.        |
| 17620001 | Memory operation failed.          |
| 17630001 | Crypto operation error. |

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Set the common parameters of the DSA1024 public and private keys.
function genDsa1024CommonSpecBigE() {
  let dsaCommonSpec: cryptoFramework.DSACommonParamsSpec = {
    algName: 'DSA',
    specType: cryptoFramework.AsyKeySpecType.COMMON_PARAMS_SPEC,
    p: BigInt('0xed1501551b8ab3547f6355ffdc2913856ddeca198833dbd04f020e5f25e47c50e0b3894f7690a0d2ea5ed3a7be25c54292a698e1f086eb3a97deb4dbf04fcad2dafd94a9f35c3ae338ab35477e16981ded6a5b13d5ff20bf55f1b262303ad3a80af71aa6aa2354d20e9c82647664bdb6b333b7bea0a5f49d55ca40bc312a1729'),
    q: BigInt('0xd23304044019d5d382cfeabf351636c7ab219694ac845051f60b047b'),
    g: BigInt('0x2cc266d8bd33c3009bd67f285a257ba74f0c3a7e12b722864632a0ac3f2c17c91c2f3f67eb2d57071ef47aaa8f8e17a21ad2c1072ee1ce281362aad01dcbcd3876455cd17e1dd55d4ed36fa011db40f0bbb8cba01d066f392b5eaa9404bfcb775f2196a6bc20eeec3db32d54e94d87ecdb7a0310a5a017c5cdb8ac78597778bd'),
  }
  return dsaCommonSpec;
}

// Set full parameters of the DSA1024 key pair.
function genDsa1024KeyPairSpecBigE() {
  let dsaCommonSpec = genDsa1024CommonSpecBigE();
  let dsaKeyPairSpec: cryptoFramework.DSAKeyPairSpec = {
    algName: 'DSA',
    specType: cryptoFramework.AsyKeySpecType.KEY_PAIR_SPEC,
    params: dsaCommonSpec,
    sk: BigInt('0xa2dd2adb2d11392c2541930f61f1165c370aabd2d78d00342e0a2fd9'),
    pk: BigInt('0xae6b5d5042e758f3fc9a02d009d896df115811a75b5f7b382d8526270dbb3c029403fafb8573ba4ef0314ea86f09d01e82a14d1ebb67b0c331f41049bd6b1842658b0592e706a5e4d20c14b67977e17df7bdd464cce14b5f13bae6607760fcdf394e0b73ac70aaf141fa4dafd736bd0364b1d6e6c0d7683a5de6b9221e7f2d6b'),
  }
  return dsaKeyPairSpec;
}

function testGenerateKeyPair() {
  let asyKeyPairSpec = genDsa1024KeyPairSpecBigE(); // The input in JS must be a positive number in big-endian format.
  let asyKeyGeneratorBySpec = cryptoFramework.createAsyKeyGeneratorBySpec(asyKeyPairSpec);
  let keyGenPromise = asyKeyGeneratorBySpec.generateKeyPair();
  keyGenPromise.then(keyPair => {
    console.info('generateKeyPair result: success.');
  }).catch((error: BusinessError) => {
    console.error(`generateKeyPair failed: errCode: ${error.code}, errMsg: ${error.message}`);
  });
}
```

### generateKeyPairSync<sup>12+</sup>

generateKeyPairSync(): KeyPair

Generates a key pair using this asymmetric key generator. This API returns the result synchronously.

If a key parameter of the [COMMON_PARAMS_SPEC](#asykeyspectype10) type is used to create the key generator, a key pair will be randomly generated. If a key parameter of the [KEY_PAIR_SPEC](#asykeyspectype10) type is used to create the key generator, you can obtain a key pair that is consistent with the specified key parameters.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Key.AsymKey

**Return value**

| Type             | Description                             |
| ----------------- | --------------------------------- |
| [KeyPair](#keypair) | Asymmetric key pair.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.         |
| 17620001 | Memory operation failed.          |
| 17630001 | Crypto operation error. |

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Set the common parameters of the DSA1024 public and private keys.
function genDsa1024CommonSpecBigE() {
  let dsaCommonSpec: cryptoFramework.DSACommonParamsSpec = {
    algName: 'DSA',
    specType: cryptoFramework.AsyKeySpecType.COMMON_PARAMS_SPEC,
    p: BigInt('0xed1501551b8ab3547f6355ffdc2913856ddeca198833dbd04f020e5f25e47c50e0b3894f7690a0d2ea5ed3a7be25c54292a698e1f086eb3a97deb4dbf04fcad2dafd94a9f35c3ae338ab35477e16981ded6a5b13d5ff20bf55f1b262303ad3a80af71aa6aa2354d20e9c82647664bdb6b333b7bea0a5f49d55ca40bc312a1729'),
    q: BigInt('0xd23304044019d5d382cfeabf351636c7ab219694ac845051f60b047b'),
    g: BigInt('0x2cc266d8bd33c3009bd67f285a257ba74f0c3a7e12b722864632a0ac3f2c17c91c2f3f67eb2d57071ef47aaa8f8e17a21ad2c1072ee1ce281362aad01dcbcd3876455cd17e1dd55d4ed36fa011db40f0bbb8cba01d066f392b5eaa9404bfcb775f2196a6bc20eeec3db32d54e94d87ecdb7a0310a5a017c5cdb8ac78597778bd'),
  }
  return dsaCommonSpec;
}

// Set full parameters of the DSA1024 key pair.
function genDsa1024KeyPairSpecBigE() {
  let dsaCommonSpec = genDsa1024CommonSpecBigE();
  let dsaKeyPairSpec: cryptoFramework.DSAKeyPairSpec = {
    algName: 'DSA',
    specType: cryptoFramework.AsyKeySpecType.KEY_PAIR_SPEC,
    params: dsaCommonSpec,
    sk: BigInt('0xa2dd2adb2d11392c2541930f61f1165c370aabd2d78d00342e0a2fd9'),
    pk: BigInt('0xae6b5d5042e758f3fc9a02d009d896df115811a75b5f7b382d8526270dbb3c029403fafb8573ba4ef0314ea86f09d01e82a14d1ebb67b0c331f41049bd6b1842658b0592e706a5e4d20c14b67977e17df7bdd464cce14b5f13bae6607760fcdf394e0b73ac70aaf141fa4dafd736bd0364b1d6e6c0d7683a5de6b9221e7f2d6b'),
  }
  return dsaKeyPairSpec;
}

function testGenerateKeyPairSync() {
  let asyKeyPairSpec = genDsa1024KeyPairSpecBigE(); // The input in JS must be a positive number in big-endian format.
  let asyKeyGeneratorBySpec = cryptoFramework.createAsyKeyGeneratorBySpec(asyKeyPairSpec);
  try {
    let keyPairData = asyKeyGeneratorBySpec.generateKeyPairSync();
    if (keyPairData != null) {
      console.info('[Sync]: key pair result: success.');
    } else {
      console.error('[Sync]: get key pair result: fail.');
    }
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    console.error(`sync failed: errCode: ${error.code}, errMsg: ${error.message}`);
  }
}
```

### generatePriKey<sup>10+</sup>

generatePriKey(callback: AsyncCallback\<PriKey>): void

Generates a private key using this asymmetric key generator. This API uses an asynchronous callback to return the result.

If [PRIVATE_KEY_SPEC](#asykeyspectype10) is used to create a key generator, the key generator generates the specified private key. If [KEY_PAIR_SPEC](#asykeyspectype10) is used to create a key generator, you can obtain the specified private key from the key pair generated.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Key.AsymKey
- API versions 10 to 11: SystemCapability.Security.CryptoFramework

**Parameters**

| Name    | Type                   | Mandatory| Description                          |
| -------- | ----------------------- | ---- | ------------------------------ |
| callback | AsyncCallback\<[PriKey](#prikey)> | Yes  | Callback used to return the result. If the asymmetric key is successfully obtained, **err** is **undefined** and **data** is the private key generated. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | Invalid parameters. Possible causes: <br>Mandatory parameters are left unspecified;         |
| 17620001 | Memory operation failed.          |
| 17630001 | Crypto operation error. |

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';

// Set the common parameters of the DSA1024 public and private keys.
function genDsa1024CommonSpecBigE() {
  let dsaCommonSpec: cryptoFramework.DSACommonParamsSpec = {
    algName: 'DSA',
    specType: cryptoFramework.AsyKeySpecType.COMMON_PARAMS_SPEC,
    p: BigInt('0xed1501551b8ab3547f6355ffdc2913856ddeca198833dbd04f020e5f25e47c50e0b3894f7690a0d2ea5ed3a7be25c54292a698e1f086eb3a97deb4dbf04fcad2dafd94a9f35c3ae338ab35477e16981ded6a5b13d5ff20bf55f1b262303ad3a80af71aa6aa2354d20e9c82647664bdb6b333b7bea0a5f49d55ca40bc312a1729'),
    q: BigInt('0xd23304044019d5d382cfeabf351636c7ab219694ac845051f60b047b'),
    g: BigInt('0x2cc266d8bd33c3009bd67f285a257ba74f0c3a7e12b722864632a0ac3f2c17c91c2f3f67eb2d57071ef47aaa8f8e17a21ad2c1072ee1ce281362aad01dcbcd3876455cd17e1dd55d4ed36fa011db40f0bbb8cba01d066f392b5eaa9404bfcb775f2196a6bc20eeec3db32d54e94d87ecdb7a0310a5a017c5cdb8ac78597778bd'),
  }
  return dsaCommonSpec;
}

// Set full parameters of the DSA1024 key pair.
function genDsa1024KeyPairSpecBigE() {
  let dsaCommonSpec = genDsa1024CommonSpecBigE();
  let dsaKeyPairSpec: cryptoFramework.DSAKeyPairSpec = {
    algName: 'DSA',
    specType: cryptoFramework.AsyKeySpecType.KEY_PAIR_SPEC,
    params: dsaCommonSpec,
    sk: BigInt('0xa2dd2adb2d11392c2541930f61f1165c370aabd2d78d00342e0a2fd9'),
    pk: BigInt('0xae6b5d5042e758f3fc9a02d009d896df115811a75b5f7b382d8526270dbb3c029403fafb8573ba4ef0314ea86f09d01e82a14d1ebb67b0c331f41049bd6b1842658b0592e706a5e4d20c14b67977e17df7bdd464cce14b5f13bae6607760fcdf394e0b73ac70aaf141fa4dafd736bd0364b1d6e6c0d7683a5de6b9221e7f2d6b'),
  }
  return dsaKeyPairSpec;
}

function testGeneratePriKey() {
  let asyKeyPairSpec = genDsa1024KeyPairSpecBigE(); // The input in JS must be a positive number in big-endian format.
  let asyKeyGeneratorBySpec = cryptoFramework.createAsyKeyGeneratorBySpec(asyKeyPairSpec);
  asyKeyGeneratorBySpec.generatePriKey((err, prikey) => {
    if (err) {
      console.error(`generateKeyPair failed, errCode: ${err.code}, errMsg: ${err.message}`);
      return;
    }
    console.info('generatePriKey result: success.');
  })
}
```

### generatePriKey<sup>10+</sup>

generatePriKey(): Promise\<PriKey>

Generates a private key using this asymmetric key generator. This API uses a promise to return the result.

If a key parameter of the [PRIVATE_KEY_SPEC](#asykeyspectype10) type is used to create the key generator, a private key can be obtained. If a key parameter of the [KEY_PAIR_SPEC](#asykeyspectype10) type is used to create the key generator, you can obtain the private key from the key pair generated.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Key.AsymKey
- API versions 10 to 11: SystemCapability.Security.CryptoFramework

**Return value**

| Type             | Description                             |
| ----------------- | --------------------------------- |
| Promise\<[PriKey](#prikey)> | Promise used to return the private key.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.         |
| 17620001 | Memory operation failed.          |
| 17630001 | Crypto operation error. |

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Set the common parameters of the DSA1024 public and private keys.
function genDsa1024CommonSpecBigE() {
  let dsaCommonSpec: cryptoFramework.DSACommonParamsSpec = {
    algName: 'DSA',
    specType: cryptoFramework.AsyKeySpecType.COMMON_PARAMS_SPEC,
    p: BigInt('0xed1501551b8ab3547f6355ffdc2913856ddeca198833dbd04f020e5f25e47c50e0b3894f7690a0d2ea5ed3a7be25c54292a698e1f086eb3a97deb4dbf04fcad2dafd94a9f35c3ae338ab35477e16981ded6a5b13d5ff20bf55f1b262303ad3a80af71aa6aa2354d20e9c82647664bdb6b333b7bea0a5f49d55ca40bc312a1729'),
    q: BigInt('0xd23304044019d5d382cfeabf351636c7ab219694ac845051f60b047b'),
    g: BigInt('0x2cc266d8bd33c3009bd67f285a257ba74f0c3a7e12b722864632a0ac3f2c17c91c2f3f67eb2d57071ef47aaa8f8e17a21ad2c1072ee1ce281362aad01dcbcd3876455cd17e1dd55d4ed36fa011db40f0bbb8cba01d066f392b5eaa9404bfcb775f2196a6bc20eeec3db32d54e94d87ecdb7a0310a5a017c5cdb8ac78597778bd'),
  }
  return dsaCommonSpec;
}

// Set full parameters of the DSA1024 key pair.
function genDsa1024KeyPairSpecBigE() {
  let dsaCommonSpec = genDsa1024CommonSpecBigE();
  let dsaKeyPairSpec: cryptoFramework.DSAKeyPairSpec = {
    algName: 'DSA',
    specType: cryptoFramework.AsyKeySpecType.KEY_PAIR_SPEC,
    params: dsaCommonSpec,
    sk: BigInt('0xa2dd2adb2d11392c2541930f61f1165c370aabd2d78d00342e0a2fd9'),
    pk: BigInt('0xae6b5d5042e758f3fc9a02d009d896df115811a75b5f7b382d8526270dbb3c029403fafb8573ba4ef0314ea86f09d01e82a14d1ebb67b0c331f41049bd6b1842658b0592e706a5e4d20c14b67977e17df7bdd464cce14b5f13bae6607760fcdf394e0b73ac70aaf141fa4dafd736bd0364b1d6e6c0d7683a5de6b9221e7f2d6b'),
  }
  return dsaKeyPairSpec;
}

function testGeneratePriKey() {
  let asyKeyPairSpec = genDsa1024KeyPairSpecBigE(); // The input in JS must be a positive number in big-endian format.
  let asyKeyGeneratorBySpec = cryptoFramework.createAsyKeyGeneratorBySpec(asyKeyPairSpec);
  let keyGenPromise = asyKeyGeneratorBySpec.generatePriKey();
  keyGenPromise.then(priKey => {
    console.info('generatePriKey result: success.');
  }).catch((error: BusinessError) => {
    console.error(`generatePriKey failed: errCode: ${error.code}, errMsg: ${error.message}`);
  });
}
```

### generatePriKeySync<sup>12+</sup>

generatePriKeySync(): PriKey

Generates a private key using this asymmetric key generator. This API returns the result synchronously.

If a key parameter of the [PRIVATE_KEY_SPEC](#asykeyspectype10) type is used to create the key generator, a private key can be obtained. If a key parameter of the [KEY_PAIR_SPEC](#asykeyspectype10) type is used to create the key generator, you can obtain the private key from the key pair generated.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Key.AsymKey

**Return value**

| Type             | Description                             |
| ----------------- | --------------------------------- |
| [PriKey](#prikey) | Private key.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.        |
| 17620001 | Memory operation failed.          |
| 17630001 | Crypto operation error. |

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';

// Set the common parameters of the DSA1024 public and private keys.
function genDsa1024CommonSpecBigE() {
  let dsaCommonSpec: cryptoFramework.DSACommonParamsSpec = {
    algName: 'DSA',
    specType: cryptoFramework.AsyKeySpecType.COMMON_PARAMS_SPEC,
    p: BigInt('0xed1501551b8ab3547f6355ffdc2913856ddeca198833dbd04f020e5f25e47c50e0b3894f7690a0d2ea5ed3a7be25c54292a698e1f086eb3a97deb4dbf04fcad2dafd94a9f35c3ae338ab35477e16981ded6a5b13d5ff20bf55f1b262303ad3a80af71aa6aa2354d20e9c82647664bdb6b333b7bea0a5f49d55ca40bc312a1729'),
    q: BigInt('0xd23304044019d5d382cfeabf351636c7ab219694ac845051f60b047b'),
    g: BigInt('0x2cc266d8bd33c3009bd67f285a257ba74f0c3a7e12b722864632a0ac3f2c17c91c2f3f67eb2d57071ef47aaa8f8e17a21ad2c1072ee1ce281362aad01dcbcd3876455cd17e1dd55d4ed36fa011db40f0bbb8cba01d066f392b5eaa9404bfcb775f2196a6bc20eeec3db32d54e94d87ecdb7a0310a5a017c5cdb8ac78597778bd'),
  }
  return dsaCommonSpec;
}

// Set full parameters of the DSA1024 key pair.
function genDsa1024KeyPairSpecBigE() {
  let dsaCommonSpec = genDsa1024CommonSpecBigE();
  let dsaKeyPairSpec: cryptoFramework.DSAKeyPairSpec = {
    algName: 'DSA',
    specType: cryptoFramework.AsyKeySpecType.KEY_PAIR_SPEC,
    params: dsaCommonSpec,
    sk: BigInt('0xa2dd2adb2d11392c2541930f61f1165c370aabd2d78d00342e0a2fd9'),
    pk: BigInt('0xae6b5d5042e758f3fc9a02d009d896df115811a75b5f7b382d8526270dbb3c029403fafb8573ba4ef0314ea86f09d01e82a14d1ebb67b0c331f41049bd6b1842658b0592e706a5e4d20c14b67977e17df7bdd464cce14b5f13bae6607760fcdf394e0b73ac70aaf141fa4dafd736bd0364b1d6e6c0d7683a5de6b9221e7f2d6b'),
  }
  return dsaKeyPairSpec;
}

function testGeneratePriKeySync() {
  let asyKeyPairSpec = genDsa1024KeyPairSpecBigE(); // The input in JS must be a positive number in big-endian format.
  let asyKeyGeneratorBySpec = cryptoFramework.createAsyKeyGeneratorBySpec(asyKeyPairSpec);
  try {
    let priKeyData = asyKeyGeneratorBySpec.generatePriKeySync();
    if (priKeyData != null) {
      console.info('[Sync]: pri key result: success.');
    } else {
      console.error('[Sync]: get pri key result: fail.');
    }
  } catch (e) {
    console.error(`sync failed: errCode: ${e.code}, errMsg: ${e.message}`);
  }
}
```

### generatePubKey<sup>10+</sup>

generatePubKey(callback: AsyncCallback\<PubKey>): void

Generates a public key using this asymmetric key generator. This API uses an asynchronous callback to return the result.

If a key parameter of the [PUBLIC_KEY_SPEC](#asykeyspectype10) type is used to create the key generator, the specified public key can be obtained. If a key parameter of the [KEY_PAIR_SPEC](#asykeyspectype10) type is used to create the key generator, you can obtain the specified public key from the key pair generated.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Key.AsymKey
- API versions 10 to 11: SystemCapability.Security.CryptoFramework

**Parameters**

| Name    | Type                   | Mandatory| Description                          |
| -------- | ----------------------- | ---- | ------------------------------ |
| callback | AsyncCallback\<[PubKey](#pubkey)> | Yes  | Callback used to return the result. If the asymmetric key is successfully obtained, **err** is **undefined** and **data** is the public key generated. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | Invalid parameters. Possible causes:<br> Incorrect parameter types;        |
| 17620001 | Memory operation failed.          |
| 17630001 | Crypto operation error. |

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';

// Set the common parameters of the DSA1024 public and private keys.
function genDsa1024CommonSpecBigE() {
  let dsaCommonSpec: cryptoFramework.DSACommonParamsSpec = {
    algName: 'DSA',
    specType: cryptoFramework.AsyKeySpecType.COMMON_PARAMS_SPEC,
    p: BigInt('0xed1501551b8ab3547f6355ffdc2913856ddeca198833dbd04f020e5f25e47c50e0b3894f7690a0d2ea5ed3a7be25c54292a698e1f086eb3a97deb4dbf04fcad2dafd94a9f35c3ae338ab35477e16981ded6a5b13d5ff20bf55f1b262303ad3a80af71aa6aa2354d20e9c82647664bdb6b333b7bea0a5f49d55ca40bc312a1729'),
    q: BigInt('0xd23304044019d5d382cfeabf351636c7ab219694ac845051f60b047b'),
    g: BigInt('0x2cc266d8bd33c3009bd67f285a257ba74f0c3a7e12b722864632a0ac3f2c17c91c2f3f67eb2d57071ef47aaa8f8e17a21ad2c1072ee1ce281362aad01dcbcd3876455cd17e1dd55d4ed36fa011db40f0bbb8cba01d066f392b5eaa9404bfcb775f2196a6bc20eeec3db32d54e94d87ecdb7a0310a5a017c5cdb8ac78597778bd'),
  }
  return dsaCommonSpec;
}

// Set full parameters of the DSA1024 key pair.
function genDsa1024KeyPairSpecBigE() {
  let dsaCommonSpec = genDsa1024CommonSpecBigE();
  let dsaKeyPairSpec: cryptoFramework.DSAKeyPairSpec = {
    algName: 'DSA',
    specType: cryptoFramework.AsyKeySpecType.KEY_PAIR_SPEC,
    params: dsaCommonSpec,
    sk: BigInt('0xa2dd2adb2d11392c2541930f61f1165c370aabd2d78d00342e0a2fd9'),
    pk: BigInt('0xae6b5d5042e758f3fc9a02d009d896df115811a75b5f7b382d8526270dbb3c029403fafb8573ba4ef0314ea86f09d01e82a14d1ebb67b0c331f41049bd6b1842658b0592e706a5e4d20c14b67977e17df7bdd464cce14b5f13bae6607760fcdf394e0b73ac70aaf141fa4dafd736bd0364b1d6e6c0d7683a5de6b9221e7f2d6b'),
  }
  return dsaKeyPairSpec;
}

function testGeneratePubKey() {
  let asyKeyPairSpec = genDsa1024KeyPairSpecBigE(); // The input in JS must be a positive number in big-endian format.
  let asyKeyGeneratorBySpec = cryptoFramework.createAsyKeyGeneratorBySpec(asyKeyPairSpec);
  asyKeyGeneratorBySpec.generatePubKey((err, pubKey) => {
    if (err) {
      console.error(`generatePubKey failed, errCode: ${err.code}, errMsg: ${err.message}`);
      return;
    }
    console.info('generatePubKey result: success.');
  })
}
```

### generatePubKey<sup>10+</sup>

generatePubKey(): Promise\<PubKey>

Generates a public key using this asymmetric key generator. This API uses a promise to return the result.

If a key parameter of the [PUBLIC_KEY_SPEC](#asykeyspectype10) type is used to create the key generator, the specified public key can be obtained. If a key parameter of the [KEY_PAIR_SPEC](#asykeyspectype10) type is used to create the key generator, you can obtain the specified public key from the key pair generated.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Key.AsymKey
- API versions 10 to 11: SystemCapability.Security.CryptoFramework

**Return value**

| Type             | Description                             |
| ----------------- | --------------------------------- |
| Promise\<[PubKey](#pubkey)> | Promise used to return the public key.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.         |
| 17620001 | Memory operation failed.          |
| 17630001 | Crypto operation error. |

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Set the common parameters of the DSA1024 public and private keys.
function genDsa1024CommonSpecBigE() {
  let dsaCommonSpec: cryptoFramework.DSACommonParamsSpec = {
    algName: 'DSA',
    specType: cryptoFramework.AsyKeySpecType.COMMON_PARAMS_SPEC,
    p: BigInt('0xed1501551b8ab3547f6355ffdc2913856ddeca198833dbd04f020e5f25e47c50e0b3894f7690a0d2ea5ed3a7be25c54292a698e1f086eb3a97deb4dbf04fcad2dafd94a9f35c3ae338ab35477e16981ded6a5b13d5ff20bf55f1b262303ad3a80af71aa6aa2354d20e9c82647664bdb6b333b7bea0a5f49d55ca40bc312a1729'),
    q: BigInt('0xd23304044019d5d382cfeabf351636c7ab219694ac845051f60b047b'),
    g: BigInt('0x2cc266d8bd33c3009bd67f285a257ba74f0c3a7e12b722864632a0ac3f2c17c91c2f3f67eb2d57071ef47aaa8f8e17a21ad2c1072ee1ce281362aad01dcbcd3876455cd17e1dd55d4ed36fa011db40f0bbb8cba01d066f392b5eaa9404bfcb775f2196a6bc20eeec3db32d54e94d87ecdb7a0310a5a017c5cdb8ac78597778bd'),
  }
  return dsaCommonSpec;
}

// Set full parameters of the DSA1024 key pair.
function genDsa1024KeyPairSpecBigE() {
  let dsaCommonSpec = genDsa1024CommonSpecBigE();
  let dsaKeyPairSpec: cryptoFramework.DSAKeyPairSpec = {
    algName: 'DSA',
    specType: cryptoFramework.AsyKeySpecType.KEY_PAIR_SPEC,
    params: dsaCommonSpec,
    sk: BigInt('0xa2dd2adb2d11392c2541930f61f1165c370aabd2d78d00342e0a2fd9'),
    pk: BigInt('0xae6b5d5042e758f3fc9a02d009d896df115811a75b5f7b382d8526270dbb3c029403fafb8573ba4ef0314ea86f09d01e82a14d1ebb67b0c331f41049bd6b1842658b0592e706a5e4d20c14b67977e17df7bdd464cce14b5f13bae6607760fcdf394e0b73ac70aaf141fa4dafd736bd0364b1d6e6c0d7683a5de6b9221e7f2d6b'),
  }
  return dsaKeyPairSpec;
}

function testGeneratePubKey() {
  let asyKeyPairSpec = genDsa1024KeyPairSpecBigE(); // The input in JS must be a positive number in big-endian format.
  let asyKeyGeneratorBySpec = cryptoFramework.createAsyKeyGeneratorBySpec(asyKeyPairSpec);
  let keyGenPromise = asyKeyGeneratorBySpec.generatePubKey();
  keyGenPromise.then(pubKey => {
    console.info('generatePubKey result: success.');
  }).catch((error: BusinessError) => {
    console.error(`generatePubKey failed: errCode: ${error.code}, errMsg: ${error.message}`);
  });
}
```

### generatePubKeySync<sup>12+</sup>

generatePubKeySync(): PubKey

Generates a public key using this asymmetric key generator. This API returns the result synchronously.

If [PUBLIC_KEY_SPEC](#asykeyspectype10) is used to create a key generator, the key generator generates the specified public key. If [KEY_PAIR_SPEC](#asykeyspectype10) is used to create a key generator, you can obtain the specified public key from the key pair generated.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Key.AsymKey

**Return value**

| Type             | Description                             |
| ----------------- | --------------------------------- |
| [PubKey](#pubkey) | Public key.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.        |
| 17620001 | Memory operation failed.          |
| 17630001 | Crypto operation error. |

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';

// Set the common parameters of the DSA1024 public and private keys.
function genDsa1024CommonSpecBigE() {
  let dsaCommonSpec: cryptoFramework.DSACommonParamsSpec = {
    algName: 'DSA',
    specType: cryptoFramework.AsyKeySpecType.COMMON_PARAMS_SPEC,
    p: BigInt('0xed1501551b8ab3547f6355ffdc2913856ddeca198833dbd04f020e5f25e47c50e0b3894f7690a0d2ea5ed3a7be25c54292a698e1f086eb3a97deb4dbf04fcad2dafd94a9f35c3ae338ab35477e16981ded6a5b13d5ff20bf55f1b262303ad3a80af71aa6aa2354d20e9c82647664bdb6b333b7bea0a5f49d55ca40bc312a1729'),
    q: BigInt('0xd23304044019d5d382cfeabf351636c7ab219694ac845051f60b047b'),
    g: BigInt('0x2cc266d8bd33c3009bd67f285a257ba74f0c3a7e12b722864632a0ac3f2c17c91c2f3f67eb2d57071ef47aaa8f8e17a21ad2c1072ee1ce281362aad01dcbcd3876455cd17e1dd55d4ed36fa011db40f0bbb8cba01d066f392b5eaa9404bfcb775f2196a6bc20eeec3db32d54e94d87ecdb7a0310a5a017c5cdb8ac78597778bd'),
  }
  return dsaCommonSpec;
}

// Set full parameters of the DSA1024 key pair.
function genDsa1024KeyPairSpecBigE() {
  let dsaCommonSpec = genDsa1024CommonSpecBigE();
  let dsaKeyPairSpec: cryptoFramework.DSAKeyPairSpec = {
    algName: 'DSA',
    specType: cryptoFramework.AsyKeySpecType.KEY_PAIR_SPEC,
    params: dsaCommonSpec,
    sk: BigInt('0xa2dd2adb2d11392c2541930f61f1165c370aabd2d78d00342e0a2fd9'),
    pk: BigInt('0xae6b5d5042e758f3fc9a02d009d896df115811a75b5f7b382d8526270dbb3c029403fafb8573ba4ef0314ea86f09d01e82a14d1ebb67b0c331f41049bd6b1842658b0592e706a5e4d20c14b67977e17df7bdd464cce14b5f13bae6607760fcdf394e0b73ac70aaf141fa4dafd736bd0364b1d6e6c0d7683a5de6b9221e7f2d6b'),
  }
  return dsaKeyPairSpec;
}

function testGeneratePubKeySync() {
  let asyKeyPairSpec = genDsa1024KeyPairSpecBigE(); // The input in JS must be a positive number in big-endian format.
  let asyKeyGeneratorBySpec = cryptoFramework.createAsyKeyGeneratorBySpec(asyKeyPairSpec);
  try {
    let pubKeyData = asyKeyGeneratorBySpec.generatePubKeySync();
    if (pubKeyData != null) {
      console.info('[Sync]: pub key result: success.');
    } else {
      console.error('[Sync]: get pub key result: fail.');
    }
  } catch (e) {
    console.error(`sync failed: errCode: ${e.code}, errMsg: ${e.message}`);
  }
}
```

## ECCKeyUtil<sup>11+</sup>

Provides tools for generating ECC key parameters and converting points based on a specified elliptic curve.

### genECCCommonParamsSpec<sup>11+</sup>

static genECCCommonParamsSpec(curveName: string): ECCCommonParamsSpec

Generates common parameters for an asymmetric key pair based on the specified name identifier (NID) of an elliptic curve. For details, see [ECC](../../security/CryptoArchitectureKit/crypto-asym-key-generation-conversion-spec.md#ecc) and [SM2](../../security/CryptoArchitectureKit/crypto-asym-key-generation-conversion-spec.md#sm2).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Key.AsymKey
- API version 11: SystemCapability.Security.CryptoFramework

**Parameters**

| Name | Type  | Mandatory| Description                                          |
| ------- | ------ | ---- | ---------------------------------------------- |
| curveName | string | Yes  | NID of the elliptic curve.|

**Return value**

| Type             | Description                             |
| ----------------- | --------------------------------- |
| [ECCCommonParamsSpec](#ecccommonparamsspec10) | ECC common parameters generated.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 801      | This operation is not supported. |
| 17620001 | Memory operation failed.                    |

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { BusinessError } from '@kit.BasicServicesKit';
try {
  let ECCCommonParamsSpec = cryptoFramework.ECCKeyUtil.genECCCommonParamsSpec('NID_brainpoolP160r1');
  console.info('genECCCommonParamsSpec result: success.');
} catch (err) {
  let e: BusinessError = err as BusinessError;
  console.error(`genECCCommonParamsSpec failed: errCode: ${e.code}, errMsg: ${e.message}`);
}
```

### convertPoint<sup>12+</sup>

static convertPoint(curveName: string, encodedPoint: Uint8Array): Point

Converts the specified point data into a **Point** object based on the curve name (NID). Currently, compressed and uncompressed point data is supported. 

> **NOTE**
>
> According to section 2.2 in RFC 5480:<br>
> 1. The uncompressed point data is represented as **0x04**\|x coordinate\|y coordinate.
> 2. The compressed point data in the **Fp** field (the **F2m** field is not supported currently) is represented as follows: **0x03**\|x coordinate (when the coordinate y is an odd number); **0x02**\|x coordinate (when the coordinate y is an even number).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Key.AsymKey

**Parameters**

| Name      | Type       | Mandatory| Description                                          |
| ------------ | ---------- | ---- | ---------------------------------------------- |
| curveName    | string     | Yes  | Elliptic curve name, that is, the NID.|
| encodedPoint | Uint8Array | Yes  | Data of the point on the ECC elliptic curve to convert.|

**Return value**

| Type             | Description                |
| ----------------- | ------------------- |
| [Point](#point10) | **Point** object obtained.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | Memory operation failed. |
| 17630001 | Crypto operation error. |

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';

// Randomly generated uncompressed point data.
let pkData =
  new Uint8Array([4, 143, 39, 57, 249, 145, 50, 63, 222, 35, 70, 178, 121, 202, 154, 21, 146, 129, 75, 76, 63, 8, 195,
    157, 111, 40, 217, 215, 148, 120, 224, 205, 82, 83, 92, 185, 21, 211, 184, 5, 19, 114, 33, 86, 85, 228, 123, 242,
    206, 200, 98, 178, 184, 130, 35, 232, 45, 5, 202, 189, 11, 46, 163, 156, 152]);
let returnPoint = cryptoFramework.ECCKeyUtil.convertPoint('NID_brainpoolP256r1', pkData);
console.info('returnPoint: ' + returnPoint.x.toString(16));
```

### getEncodedPoint<sup>12+</sup>

static getEncodedPoint(curveName: string, point: Point, format: string): Uint8Array

Obtains the point data in the specified format from a **Point** object. Currently, compressed and uncompressed point data is supported.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Key.AsymKey

**Parameters**

| Name      | Type              | Mandatory| Description                                          |
| ------------ | ----------------- | ---- | ---------------------------------------------- |
| curveName    | string            | Yes  | Elliptic curve name, that is, the NID.|
| point        | [Point](#point10) | Yes  | **Point** object of the elliptic curve.|
| format       | string            | Yes  | Format of the point data to obtain. Currently, the value can be **COMPRESSED** or **UNCOMPRESSED** only.|

**Return value**

| Type             | Description                             |
| ----------------- | --------------------------------- |
| Uint8Array | Point data in the specified format.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | Memory operation failed. |
| 17630001 | Crypto operation error. |

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';

async function doTest() {
  let generator = cryptoFramework.createAsyKeyGenerator('ECC_BrainPoolP256r1');
  let keyPair = await generator.generateKeyPair();
  let eccPkX = keyPair.pubKey.getAsyKeySpec(cryptoFramework.AsyKeySpecItem.ECC_PK_X_BN);
  let eccPkY = keyPair.pubKey.getAsyKeySpec(cryptoFramework.AsyKeySpecItem.ECC_PK_Y_BN);
  console.info('ECC_PK_X_BN 16: ' + eccPkX.toString(16));
  console.info('ECC_PK_Y_BN 16: ' + eccPkY.toString(16));
  // Place eccPkX.toString(16) in x and eccPkY.toString(16) in y.
  let returnPoint: cryptoFramework.Point = {
    x: BigInt('0x' + eccPkX.toString(16)),
    y: BigInt('0x' + eccPkY.toString(16))
  };
  let returnData = cryptoFramework.ECCKeyUtil.getEncodedPoint('NID_brainpoolP256r1', returnPoint, 'UNCOMPRESSED');
  console.info('returnData: ' + returnData);
}
```

## DHKeyUtil<sup>11+</sup>

Generates common parameters for a DH key based on the prime **p** length and the private key length.

### genDHCommonParamsSpec<sup>11+</sup>

static genDHCommonParamsSpec(pLen: number, skLen?: number): DHCommonParamsSpec

Generates common parameters for a DH key based on the prime **p** length and the private key length. For details, see [DH](../../security/CryptoArchitectureKit/crypto-asym-key-generation-conversion-spec.md#dh).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Key.AsymKey
- API version 11: SystemCapability.Security.CryptoFramework

**Parameters**

| Name| Type  | Mandatory| Description                                            |
| ------ | ------ | ---- | ------------------------------------------------ |
| pLen   | number | Yes  | Length of the prime **p**, in bits.|
| skLen  | number | No  | Maximum length of the generated DH private key, in bits. The default value is **0**.<br>When this parameter is set to **0**, the maximum length of the generated DH private key is as follows:<br>ffdhe2048: 255 bits.<br>ffdhe3072: 275 bits.<br>ffdhe4096: 325 bits.<br>ffdhe6144: 375 bits.<br>ffdhe8192: 400 bits.|

**Return value**

| Type             | Description                             |
| ----------------- | --------------------------------- |
| [DHCommonParamsSpec](#dhcommonparamsspec11) | DH common parameters generated.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 801      | This operation is not supported. |
| 17620001 | Memory operation failed.                    |
| 17630001 | Crypto operation error.          |

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { BusinessError } from '@kit.BasicServicesKit';
try {
  let DHCommonParamsSpec = cryptoFramework.DHKeyUtil.genDHCommonParamsSpec(2048);
  console.info('genDHCommonParamsSpec result: success.');
} catch (err) {
  let e: BusinessError = err as BusinessError;
  console.error(`genDHCommonParamsSpec failed: errCode: ${e.code}, errMsg: ${e.message}`);
}
```

## SM2CryptoUtil<sup>12+</sup>

Provides APIs for SM2 cryptographic operations.

### genCipherTextBySpec<sup>12+</sup>

static genCipherTextBySpec(spec: SM2CipherTextSpec, mode?: string): DataBlob

Generates SM2 ciphertext in ASN.1 format.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Cipher

**Parameters**

| Name| Type  | Mandatory| Description                                            |
| ------ | ------ | ---- | ------------------------------------------------ |
| spec   | [SM2CipherTextSpec](#sm2ciphertextspec12) | Yes  | SM2 ciphertext parameters.|
| mode  | string | No  | Order of the SM2 parameters in the ciphertext. Currently, only C1C3C2 is supported. If this parameter is left empty or is an empty string, the default value is used.|

**Return value**

| Type             | Description                             |
| ----------------- | --------------------------------- |
| [DataBlob](#datablob) | SM2 ciphertext in ASN.1 format.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | Memory operation failed.                    |
| 17630001 | Crypto operation error.          |

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let spec: cryptoFramework.SM2CipherTextSpec = {
    xCoordinate: BigInt('20625015362595980457695435345498579729138244358573902431560627260141789922999'),
    yCoordinate: BigInt('48563164792857017065725892921053777369510340820930241057309844352421738767712'),
    cipherTextData: new Uint8Array([100, 227, 78, 195, 249, 179, 43, 70, 242, 69, 169, 10, 65, 123]),
    hashData: new Uint8Array([87, 167, 167, 247, 88, 146, 203, 234, 83, 126, 117, 129, 52, 142, 82, 54, 152, 226, 201,
      111, 143, 115, 169, 125, 128, 42, 157, 31, 114, 198, 109, 244]),
  }
  let data = cryptoFramework.SM2CryptoUtil.genCipherTextBySpec(spec, 'C1C3C2');
  console.info('genCipherTextBySpec result: success.');
} catch (err) {
  let e: BusinessError = err as BusinessError;
  console.error(`genCipherTextBySpec failed: errCode: ${e.code}, errMsg: ${e.message}`);
}
```

### getCipherTextSpec<sup>12+</sup>

static getCipherTextSpec(cipherText: DataBlob, mode?: string): SM2CipherTextSpec

Obtains SM2 ciphertext parameters from the SM2 ciphertext in ASN.1 format.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Cipher

**Parameters**

| Name| Type  | Mandatory| Description                                            |
| ------ | ------ | ---- | ------------------------------------------------ |
| cipherText     | [DataBlob](#datablob)                 | Yes  | SM2 ciphertext in ASN.1 format.|
| mode  | string | No  | Order of the SM2 parameters in the ciphertext. Currently, only C1C3C2 is supported. If this parameter is left empty or is an empty string, the default value is used.|

**Return value**

| Type             | Description                             |
| ----------------- | --------------------------------- |
| [SM2CipherTextSpec](#sm2ciphertextspec12) | SM2 ciphertext parameters obtained.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | Memory operation failed.                    |
| 17630001 | Crypto operation error.          |

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let cipherTextArray =
    new Uint8Array([48, 118, 2, 32, 45, 153, 88, 82, 104, 221, 226, 43, 174, 21, 122, 248, 5, 232, 105, 41, 92, 95, 102,
      224, 216, 149, 85, 236, 110, 6, 64, 188, 149, 70, 70, 183, 2, 32, 107, 93, 198, 247, 119, 18, 40, 110, 90, 156,
      193, 158, 205, 113, 170, 128, 146, 109, 75, 17, 181, 109, 110, 91, 149, 5, 110, 233, 209, 78, 229, 96, 4, 32, 87,
      167, 167, 247, 88, 146, 203, 234, 83, 126, 117, 129, 52, 142, 82, 54, 152, 226, 201, 111, 143, 115, 169, 125, 128,
      42, 157, 31, 114, 198, 109, 244, 4, 14, 100, 227, 78, 195, 249, 179, 43, 70, 242, 69, 169, 10, 65, 123]);
  let cipherText: cryptoFramework.DataBlob = { data: cipherTextArray };
  let spec: cryptoFramework.SM2CipherTextSpec = cryptoFramework.SM2CryptoUtil.getCipherTextSpec(cipherText, 'C1C3C2');
  console.info('getCipherTextSpec result: success.');
} catch (err) {
  let e: BusinessError = err as BusinessError;
  console.error(`getCipherTextSpec failed: errCode: ${e.code}, errMsg: ${e.message}`);
}
```

## cryptoFramework.createCipher

createCipher(transformation: string): Cipher

Create a **Cipher** instance.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Cipher
- API versions 9 to 11: SystemCapability.Security.CryptoFramework

**Parameters**

| Name        | Type  | Mandatory| Description                                                        |
| -------------- | ------ | ---- | ------------------------------------------------------------ |
| transformation | string | Yes  | Combination of the algorithm name (including the key length), encryption mode, and padding algorithm of the **Cipher** instance to create.<br>For details about the supported specifications, see [Symmetric Key Encryption and Decryption Algorithm Specifications](../../security/CryptoArchitectureKit/crypto-sym-encrypt-decrypt-spec.md) and [Asymmetric Key Encryption and Decryption Algorithm Specifications](../../security/CryptoArchitectureKit/crypto-asym-encrypt-decrypt-spec.md).|

> **NOTE**
>
> In symmetric encryption and decryption, PKCS #5 and PKCS #7 share the same implementation, with padding length and block size remaining consistent. In 3DES, padding is applied in 8-byte blocks; in AES, padding is applied in 16-byte blocks. **NoPadding** means no padding is applied.
> <br>You need to understand the differences between different block cipher modes and use the correct parameter specifications. For example, padding is required for ECB and CBC. Otherwise, ensure that the plaintext length is an integer multiple of the block size. No padding is recommended for other modes. In this case, the ciphertext length is the same as the plaintext length.

**Return value**

| Type             | Description                    |
| ----------------- | ------------------------ |
| [Cipher](#cipher) | **Cipher** instance of the corresponding algorithm.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 801 | This operation is not supported. |
| 17620001 | Memory operation failed.          |

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { BusinessError } from '@kit.BasicServicesKit';

let cipherAlgName = '3DES192|ECB|PKCS7';
try {
  let cipher = cryptoFramework.createCipher(cipherAlgName);
  console.info('cipher algName: ' + cipher.algName);
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`sync failed: errCode: ${e.code}, errMsg: ${e.message}`);
}
```

## Cipher

Provides an encryption and decryption API, which defines symmetric and asymmetric encryption and decryption methods. Before calling this API, you must use the [createCipher(transformation: string): Cipher](#cryptoframeworkcreatecipher) method to create a **Cipher** instance. The [init()](#init-1), [update()](#update), and [doFinal()](#dofinal) methods in the **Cipher** instance are called in sequence to implement symmetric encryption or decryption and asymmetric encryption or decryption.

For details about the complete encryption and decryption process, see [Encryption and Decryption Overview](../../security/CryptoArchitectureKit/crypto-encryption-decryption-overview.md).

A complete symmetric encryption/decryption process is slightly different from the asymmetric encryption/decryption process.

- Symmetric encryption and decryption: **init()** and **doFinal()** are mandatory. **update()** is optional and can be called multiple times to encrypt or decrypt big data. After **doFinal()** is called to complete an encryption or decryption operation, **init()** can be called to start a new encryption or decryption operation.
- RSA or SM2 asymmetric encryption and decryption: **init()** and **doFinal()** are mandatory, and **update()** is not supported. **doFinal()** can be called multiple times to encrypt or decrypt big data. **init()** cannot be called repeatedly. If the encryption/decryption mode or padding mode is changed, a new **Cipher** object must be created.

### Attributes

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Cipher
- API versions 9 to 11: SystemCapability.Security.CryptoFramework

| Name   | Type  | Read-Only| Optional| Description                        |
| ------- | ------ | ---- | ---- | ---------------------------- |
| algName | string | Yes  | No  | Algorithm.|

### init

init(opMode: CryptoMode, key: Key, params: ParamsSpec, callback: AsyncCallback\<void>): void

Initializes the [cipher](#cipher) object for encryption and decryption. This API uses an asynchronous callback to return the result. **init**, **update**, and **doFinal** must be used together. **init** and **doFinal** are mandatory, and **update** is optional.

This API can be used only after a [Cipher](#cipher) instance is created by using [createCipher](#cryptoframeworkcreatecipher).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Cipher
- API versions 9 to 11: SystemCapability.Security.CryptoFramework

**Parameters**

| Name    | Type                     | Mandatory| Description                                                        |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| opMode   | [CryptoMode](#cryptomode) | Yes  | Operation (encryption or decryption) to perform.                                          |
| key      | [Key](#key)               | Yes  | Key for encryption or decryption.                                      |
| params   | [ParamsSpec](#paramsspec) | Yes  | Parameters for encryption or decryption, for example, **IV**.                              |
| callback | AsyncCallback\<void>      | Yes  | Callback used to return the result. If the object for encryption and decryption is successfully initialized, **err** is **undefined**. Otherwise, **err** is an error object.    |

**Error codes**

For details about the error codes,see [Universal Error Codes](../errorcode-universal.md) and [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message                                                |
| -------- | --------------------------------------------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | Memory operation failed.                                            |
| 17620002 | Failed to obtain the native object or convert parameters.                                          |
| 17620003 | Parameter check failed. Possible causes: <br>1. Invalid opMode value;<br>2. Invalid iv length;<br>3. Invalid key length. <br>Applicable versions: 22+|
| 17630001 | Crypto operation error.|

### init<sup>10+</sup>

init(opMode: CryptoMode, key: Key, params: ParamsSpec | null, callback: AsyncCallback\<void>): void

Initializes the [cipher](#cipher) object for encryption and decryption. This API uses an asynchronous callback to return the result. **init**, **update**, and **doFinal** must be used together. **init** and **doFinal** are mandatory, and **update** is optional.

This API can be used only after a [Cipher](#cipher) instance is created by using [createCipher](#cryptoframeworkcreatecipher).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Cipher
- API versions 10 to 11: SystemCapability.Security.CryptoFramework

**Parameters**

| Name    | Type                     | Mandatory| Description                                                        |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| opMode   | [CryptoMode](#cryptomode) | Yes  | Encryption or decryption operation to be performed.                                          |
| key      | [Key](#key)               | Yes  | Key for encryption or decryption.                                      |
| params   | [ParamsSpec](#paramsspec) \| null | Yes  | Parameters for encryption or decryption. For algorithm modes without parameters (such as ECB), set this parameter to **null**. In versions earlier than API version 10, only **ParamsSpec** is supported. Since API version 10, **null** is also supported.|
| callback | AsyncCallback\<void>      | Yes  | Callback used to return the result. If the object for encryption and decryption is successfully initialized, **err** is **undefined**. Otherwise, **err** is an error object.    |

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message                                                |
| -------- | --------------------------------------------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | Memory operation failed.                                            |
| 17620002 | Failed to obtain the native object or convert parameters.                                          |
| 17620003 | Parameter check failed. Possible causes: <br>1. Invalid opMode value;<br>2. Invalid iv length;<br>3. Invalid key length. <br>Applicable versions: 22+|
| 17630001 | Crypto operation error.|

### init

init(opMode: CryptoMode, key: Key, params: ParamsSpec): Promise\<void>

Initializes the cipher object for encryption and decryption. This API uses a promise to return the result. **init**, **update**, and **doFinal** must be used together. **init** and **doFinal** are mandatory, and **update** is optional.

This API can be used only after a [Cipher](#cipher) instance is created by using [createCipher](#cryptoframeworkcreatecipher).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Cipher
- API versions 9 to 11: SystemCapability.Security.CryptoFramework

**Parameters**

| Name  | Type                     | Mandatory| Description                                                        |
| ------ | ------------------------- | ---- | ------------------------------------------------------------ |
| opMode | [CryptoMode](#cryptomode) | Yes  | Operation (encryption or decryption) to perform.                                          |
| key    | [Key](#key)               | Yes  | Key for encryption or decryption.                                      |
| params | [ParamsSpec](#paramsspec) | Yes  | Parameters for encryption or decryption, for example, **IV**.                              |

**Return value**

| Type          | Description                                  |
| -------------- | -------------------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes,see [Universal Error Codes](../errorcode-universal.md) and [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | Memory operation failed.                                     |
| 17620002 | Failed to obtain the native object or convert parameters.                                    |
| 17620003 | Parameter check failed. Possible causes: <br>1. Invalid opMode value;<br>2. Invalid iv length;<br>3. Invalid key length. <br>Applicable versions: 22+|
| 17630001 | Crypto operation error.|

### init<sup>10+</sup>

init(opMode: CryptoMode, key: Key, params: ParamsSpec | null): Promise\<void>

Initializes the cipher object for encryption and decryption. This API uses a promise to return the result. **init**, **update**, and **doFinal** must be used together. **init** and **doFinal** are mandatory, and **update** is optional.

This API can be used only after a [Cipher](#cipher) instance is created by using [createCipher](#cryptoframeworkcreatecipher).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Cipher
- API versions 10 to 11: SystemCapability.Security.CryptoFramework

**Parameters**

| Name  | Type                     | Mandatory| Description                                                        |
| ------ | ------------------------- | ---- | ------------------------------------------------------------ |
| opMode | [CryptoMode](#cryptomode) | Yes  | Encryption or decryption operation to be performed.                                          |
| key    | [Key](#key)               | Yes  | Key for encryption or decryption.                                      |
| params | [ParamsSpec](#paramsspec) \| null | Yes  | Parameters for encryption or decryption. For algorithm modes without parameters (such as ECB), set this parameter to **null**. In versions earlier than API version 10, only **ParamsSpec** is supported. Since API version 10, **null** is also supported.|

**Return value**

| Type          | Description                                  |
| -------------- | -------------------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | Memory operation failed.                                     |
| 17620002 | Failed to obtain the native object or convert parameters.                                    |
| 17620003 | Parameter check failed. Possible causes: <br>1. Invalid opMode value;<br>2. Invalid iv length;<br>3. Invalid key length. <br>Applicable versions: 22+|
| 17630001 | Crypto operation error.|

### initSync<sup>12+</sup>

initSync(opMode: CryptoMode, key: Key, params: ParamsSpec | null): void

Initializes a [cipher](#cipher) instance. This API returns the result synchronously. **initSync**, **updateSync**, and **doFinalSync** must be used together. **initSync** and **doFinalSync** are mandatory, and **updateSync** is optional.

This API can be used only after a [Cipher](#cipher) instance is created by using [createCipher](#cryptoframeworkcreatecipher).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Cipher

**Parameters**

| Name| Type                                           | Mandatory| Description                                                        |
| ------ | ----------------------------------------------- | ---- | ------------------------------------------------------------ |
| opMode | [CryptoMode](#cryptomode)                       | Yes  | Operation (encryption or decryption) to perform.                                          |
| key    | [Key](#key)                                     | Yes  | Key for encryption or decryption.                                      |
| params | [ParamsSpec](#paramsspec)  \| null| Yes  | Parameters for encryption or decryption. For algorithm modes without parameters (such as ECB), set this parameter to **null**.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message               |
| -------- | ----------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | Memory operation failed.           |
| 17620002 | Failed to obtain the native object or convert parameters.         |
| 17620003 | Parameter check failed. Possible causes: <br>1. Invalid opMode value;<br>2. Invalid iv length;<br>3. Invalid key length. <br>Applicable versions: 22+|
| 17630001 | Crypto operation error. |

### update

update(data: DataBlob, callback: AsyncCallback\<DataBlob>): void

Updates the data to encrypt or decrypt by segment. This API uses an asynchronous callback to return the result.

This API can be called only after the [Cipher](#cipher) instance is initialized by using [init()](#init-1).

> **NOTE**
>
> 1. The results of **update()** and **doFinal()** may vary with the block mode used. If you are not familiar with the block modes, you are advised to check each **update()** and **doFinal()** result to ensure that the results are not **null**. When a valid result is returned, extract and concatenate the data to form a complete ciphertext or plaintext.  
>
>    For example, in ECB and CBC modes, encryption and decryption are performed by block regardless of whether the data input by **update()** is an integer multiple of the block size, and **update()** returns the newly processed block data.
>
>    That is, data is returned as long as the data passed in by **update()** reaches the size of a block. Otherwise, **null** is returned and the data will be retained until a block is formed in the next **update()** or **doFinal()**.
>
>    In the final **doFinal()** operation, the remaining unprocessed data is padded based on the padding mode set in [createCipher](#cryptoframeworkcreatecipher) to the integer multiple of the block size to produce the final encrypted or decrypted data.
>
>    For block cipher modes that can be converted to stream mode, the ciphertext length may be the same as the plaintext length.
>
> 2. You can call **update()** multiple times or skip calling **update()** (call **doFinal()** directly after **init()**), depending on the data volume.
>
>    The amount of the data to be passed in by **update()** (one-time or accumulative) is not limited. If there is a large amount of data, you are advised to pass data in multiple **update()** calls rather than processing it all at once.
>
>    For details about the sample code for passing data in multiple **update()** calls, see [Encryption and Decryption by Segment with an AES Symmetric Key (GCM Mode)](../../security/CryptoArchitectureKit/crypto-aes-sym-encrypt-decrypt-gcm-by-segment.md).
> 3. RSA or SM2 asymmetric encryption and decryption do not support **update()**.
> 4. If CCM is used in symmetric encryption or decryption, **update()** can be called only once. In the encryption process, you can either use **update()** to encrypt data and use **doFinal()** to obtain **authTag** or use **doFinal()** without using **update()**. In the decryption process, you can either use **update()** or **doFinal()** once to decrypt data and verify the tag.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Cipher
- API versions 9 to 11: SystemCapability.Security.CryptoFramework

**Parameters**

| Name    | Type                                 | Mandatory| Description                                                        |
| -------- | ------------------------------------- | ---- | ------------------------------------------------------------ |
| data     | [DataBlob](#datablob)                 | Yes  | Data to be encrypted or decrypted. It cannot be null.          |
| callback | AsyncCallback\<[DataBlob](#datablob)> | Yes  | Callback used to return the result. If the encrypted or decrypted data is updated successfully, **err** is **undefined**, and **data** is the encryption or decryption result **DataBlob**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | Memory operation failed.                               |
| 17620002 | Failed to obtain the native object or convert parameters.                            |
| 17620003 | Parameter check failed. Possible causes: <br>1. The data is too long. <br>Applicable versions: 22+|
| 17630001 | Crypto operation error.                     |

### update

update(data: DataBlob): Promise\<DataBlob>

Updates the data to encrypt or decrypt by segment. This API uses a promise to return the result.

This API can be called only after the [Cipher](#cipher) instance is initialized by using [init()](#init-1).

> **NOTE**
>
> 1. The results of **update()** and **doFinal()** may vary with the block mode used. If you are not familiar with the block modes, you are advised to check each update() and doFinal() result to ensure that the results are not null. When a valid result is returned, extract and concatenate the data to form a complete ciphertext or plaintext.  
> <br>For example, in ECB and CBC modes, encryption and decryption are performed by block regardless of whether the data input by **update()** is an integer multiple of the block size, and **update()** returns the newly processed block data.<br>That is, data is returned as long as the data passed in by **update()** reaches the size of a block. Otherwise, **null** is returned and the data will be retained until a block is formed in the next **update()** or **doFinal()**.<br>In the final **doFinal()** operation, the remaining unprocessed data is padded based on the padding mode set in [createCipher](#cryptoframeworkcreatecipher) to the integer multiple of the block size to produce the final encrypted or decrypted data.<br>For block cipher modes that can be converted to stream mode, the ciphertext length may be the same as the plaintext length.
> 2. You can call **update()** multiple times or skip calling **update()** (call **doFinal()** directly after **init()**), depending on the data volume.<br>
>    The amount of the data to be passed in by **update()** (one-time or accumulative) is not limited. If there is a large amount of data, you are advised to pass data in multiple **update()** calls rather than processing it all at once.<br>
>    For details about the sample code for passing data in multiple **update()** calls, see [Encryption and Decryption by Segment with an AES Symmetric Key (GCM Mode)](../../security/CryptoArchitectureKit/crypto-aes-sym-encrypt-decrypt-gcm-by-segment.md).
> 3. RSA or SM2 asymmetric encryption and decryption do not support **update()**.
> 4. If CCM is used in symmetric encryption or decryption, **update()** can be called only once. In the encryption process, you can either use **update()** to encrypt data and use **doFinal()** to obtain **authTag** or use **doFinal()** without using **update()**. In the decryption process, you can either use **update()** or **doFinal()** once to decrypt data and verify the tag.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Cipher
- API versions 9 to 11: SystemCapability.Security.CryptoFramework

**Parameters**

| Name| Type                 | Mandatory| Description                |
| ---- | --------------------- | ---- | -------------------- |
| data | [DataBlob](#datablob) | Yes  | Data to encrypt or decrypt. It cannot be null.|

**Return value**

| Type                           | Description                                            |
| ------------------------------- | ------------------------------------------------ |
| Promise\<[DataBlob](#datablob)> | Promise used to return the **DataBlob** (containing the encrypted or decrypted data).|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message                                    |
| -------- | -------------------------------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | Memory operation failed.                                |
| 17620002 | Failed to obtain the native object or convert parameters.                               |
| 17620003 | Parameter check failed. Possible causes: <br>1. The data is too long. <br>Applicable versions: 22+|
| 17630001 | Crypto operation error.                      |

### updateSync<sup>12+</sup>

updateSync(data: DataBlob): DataBlob

Updates the data to encrypt or decrypt by segment. This API uses an asynchronous callback to return the encrypted or decrypted data.

This API can be called only after the [Cipher](#cipher) instance is initialized by using [initSync()](#initsync12).

See **NOTE** in **update()** for other precautions.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Cipher

**Parameters**

| Name| Type                 | Mandatory| Description                                                        |
| ------ | --------------------- | ---- | ------------------------------------------------------------ |
| data   | [DataBlob](#datablob) | Yes  | Data to encrypt or decrypt. It cannot be null.|

**Return value**

| Type                           | Description                                            |
| ------------------------------- | ------------------------------------------------ |
| [DataBlob](#datablob) | Encryption/decryption result.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message               |
| -------- | ----------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | Memory operation failed.           |
| 17620002 | Failed to obtain the native object or convert parameters.         |
| 17620003 | Parameter check failed. Possible causes: <br>1. The data is too long. <br>Applicable versions: 22+|
| 17630001 | Crypto operation error. |

### doFinal

doFinal(data: DataBlob, callback: AsyncCallback\<DataBlob>): void

Encrypts or decrypts the input data and returns the output data. After the encryption or decryption operation is complete, the data cannot be updated. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Cipher
- API versions 9 to 11: SystemCapability.Security.CryptoFramework

**Parameters**

| Name    | Type                                 | Mandatory| Description                                                        |
| -------- | ------------------------------------- | ---- | ------------------------------------------------------------ |
| data     | [DataBlob](#datablob)                 | Yes  | Data to encrypt or decrypt. **{data:Uint8Array (empty)}** cannot be passed.      |
| callback | AsyncCallback\<[DataBlob](#datablob)> | Yes  | Callback used to return the result. If the encryption or decryption is successful, **err** is **undefined**, and **data** is the encryption or decryption result **DataBlob**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes,see [Universal Error Codes](../errorcode-universal.md) and [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message               |
| -------- | ----------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | Memory operation failed.           |
| 17620002 | Failed to obtain the native object or convert parameters.          |
| 17620003 | Parameter check failed. Possible causes: <br>1. The data is too long. <br>Applicable versions: 22+|
| 17630001 | Crypto operation error. |

### doFinal<sup>10+</sup>

doFinal(data: DataBlob | null, callback: AsyncCallback\<DataBlob>): void

(1) Processes the remaining data and the data passed in this time, and completes the encryption or decryption operation for symmetric encryption and decryption. This API uses an asynchronous callback to return the encrypted or decrypted data. If a small amount of data needs to be encrypted or decrypted, you can use **doFinal()** to pass in all the data without using **update()**. If all the data has been passed in by [update()](#update), you can pass in **null** in **data** of **doFinal()**. The output of **doFinal()** varies with the symmetric block cipher mode in use.

- In a single encryption process with GCM or CCM mode, concatenating the results of each **update()** and **doFinal()** procedures the ciphertext and **authTag**. In GCM mode, **authTag** is the last 16 bytes. In CCM mode, **authTag** is the last 12 bytes. The rest part is the ciphertext. If **data** passed to **doFinal()** is **null**, the **doFinal()** result is only the **authTag**. During decryption, **authTag** must be set in [GcmParamsSpec](#gcmparamsspec) or [CcmParamsSpec](#ccmparamsspec), and the ciphertext must be set in **data**.
- For other symmetric encryption and decryption modes and GCM and CCM decryption modes, concatenating the results of **update()** and **doFinal()** throughout the process will yield the complete plaintext or ciphertext.


(2) Encrypts or decrypts the data passed in this time in RSA and SM2 asymmetric encryption or decryption. This API uses an asynchronous callback to return the encrypted or decrypted data. If a large amount of data needs to be encrypted/decrypted, call **doFinal()** multiple times and concatenate the result of each **doFinal()** to obtain the complete plaintext/ciphertext.

> **NOTE**
>
>  1. In symmetric encryption and decryption, after **doFinal** is called, the encryption and decryption process is complete and the [Cipher](#cipher) instance is cleared. When a new encryption and decryption process is started, **init()** must be called with a complete parameter list for initialization.<br>Even if the same symmetric key is used to encrypt and decrypt the same **Cipher** instance, the **params** parameter must be set when **init** is called during decryption.
>  2. If a decryption fails, check whether the data to be encrypted and decrypted matches the parameters in **init()**. For the GCM mode, check whether the **authTag** obtained after encryption is obtained from the **GcmParamsSpec** for decryption.
>  3. The result of **doFinal()** may be **null**. To avoid exceptions, determine whether the result is **null** before using the **.data** field to access the **doFinal()** result.<br>
>    For encryption in CFB, OFB, or CTR mode, if **doFinal()** passes in **null**, the returned result is **null**.<br>
>    For decryption in GCM, CCM, CFB, OFB, or CTR mode, if **doFinal()** passes in **null**, the returned result is **null**. For decryption in other modes, if **update** is called to pass in all the plaintext, which is an integer multiple of the encryption block size, and **doFinal()** is called to pass in **null**, the returned result is **null**.<br>
>  4. For details about the sample code for calling **doFinal** multiple times in asymmetric encryption and decryption, see [Encryption and Decryption by Segment with an RSA Asymmetric Key Pair](../../security/CryptoArchitectureKit/crypto-rsa-asym-encrypt-decrypt-by-segment.md). The operations are similar for SM2 and RSA.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Cipher
- API versions 10 to 11: SystemCapability.Security.CryptoFramework

**Parameters**

| Name    | Type                                 | Mandatory| Description                                                        |
| -------- | ------------------------------------- | ---- | ------------------------------------------------------------ |
| data     | [DataBlob](#datablob) \| null<sup>10+</sup>                 | Yes  | Data to encrypt or decrypt. In symmetric encryption and decryption, this parameter can be **null**, but **{data: Uint8Array (empty)}** cannot be passed in. Before API version 10, only **DataBlob** is supported. Since API version 10, **null** is also supported.      |
| callback | AsyncCallback\<[DataBlob](#datablob)> | Yes  | Callback used to return the result. If the encryption or decryption is successful, **err** is **undefined**, and **data** is the encryption or decryption result **DataBlob**. Otherwise, **err** is an error object.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message               |
| -------- | ----------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | Memory operation failed.           |
| 17620002 | Failed to obtain the native object or convert parameters.          |
| 17620003 | Parameter check failed. Possible causes: <br>1. The data is too long.|
| 17630001 | Crypto operation error. |

**Example**

For more encryption and decryption examples, see [Encryption and Decryption with an AES Symmetric Key (GCM Mode)](../../security/CryptoArchitectureKit/crypto-aes-sym-encrypt-decrypt-gcm.md).

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { buffer } from '@kit.ArkTS';

function generateRandom(len: number) {
  let rand = cryptoFramework.createRandom();
  let generateRandSync = rand.generateRandomSync(len);
  return generateRandSync;
}

function genGcmParamsSpec() {
  let ivBlob = generateRandom(12);
  let arr = [1, 2, 3, 4, 5, 6, 7, 8];
  let dataAad = new Uint8Array(arr);
  let aadBlob: cryptoFramework.DataBlob = { data: dataAad };
  arr = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0];
  let dataTag = new Uint8Array(arr);
  let tagBlob: cryptoFramework.DataBlob = {
    data: dataTag
  };
  let gcmParamsSpec: cryptoFramework.GcmParamsSpec = {
    iv: ivBlob,
    aad: aadBlob,
    authTag: tagBlob,
    algName: 'GcmParamsSpec'
  };
  return gcmParamsSpec;
}

function cipherByCallback() {
  let gcmParams = genGcmParamsSpec();
  let symKeyGenerator = cryptoFramework.createSymKeyGenerator('AES128');
  let cipher = cryptoFramework.createCipher('AES128|GCM|PKCS7');
  symKeyGenerator.generateSymKey((err, symKey) => {
    cipher.init(cryptoFramework.CryptoMode.ENCRYPT_MODE, symKey, gcmParams, (err) => {
      let message = 'This is a test';
      let plainText: cryptoFramework.DataBlob = { data: new Uint8Array(buffer.from(message, 'utf-8').buffer) };
      cipher.update(plainText, (err, encryptUpdate) => {
        cipher.doFinal(null, (err, tag) => {
          gcmParams.authTag = tag;
          console.info('encryptUpdate plainText: ' + encryptUpdate.data);
        });
      });
    });
  });
}
```

### doFinal

doFinal(data: DataBlob): Promise\<DataBlob>

Encrypts or decrypts the input data and returns the output data. After the encryption or decryption operation is complete, the data cannot be updated. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Cipher
- API versions 9 to 11: SystemCapability.Security.CryptoFramework

**Parameters**

| Name| Type                 | Mandatory| Description                |
| ---- | --------------------- | ---- | -------------------- |
| data | [DataBlob](#datablob) | Yes  | Data to encrypt or decrypt. **{data:Uint8Array (empty)}** cannot be passed.|

**Return value**

| Type                           | Description                                            |
| ------------------------------- | ------------------------------------------------ |
| Promise\<[DataBlob](#datablob)> | Promise used to return the **DataBlob**, which is the encryption or decryption result of the remaining data.|

**Error codes**

For details about the error codes,see [Universal Error Codes](../errorcode-universal.md) and [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message                                    |
| -------- | -------------------------------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | Memory operation failed.                                |
| 17620002 | Failed to obtain the native object or convert parameters.                               |
| 17620003 | Parameter check failed. Possible causes: <br>1. The data is too long. <br>Applicable versions: 22+|
| 17630001 | Crypto operation error.                      |

### doFinal<sup>10+</sup>

doFinal(data: DataBlob | null): Promise\<DataBlob>

(1) Encrypts or decrypts the remaining data (generated by the block cipher mode) and the data passed in this time to finalize the symmetric encryption or decryption. This API uses a promise to return the encrypted or decrypted data.<br>If a small amount of data needs to be encrypted or decrypted, you can use **doFinal()** to pass in data without using **update()**. If all the data has been passed in by **update()**, you can pass in **null** in **data** of **doFinal()**.<br>The output of **doFinal()** varies with the symmetric encryption/decryption mode in use.

- Symmetric encryption in GCM and CCM mode: The result consists of the ciphertext and **authTag** (the last 16 bytes for GCM and the last 12 bytes for CCM). If **data** in **doFinal** is null, the result of **doFinal** is **authTag**.<br>During decryption, **authTag** must be set in [GcmParamsSpec](#gcmparamsspec) or [CcmParamsSpec](#ccmparamsspec), and the ciphertext must be set in **data**.
- For other symmetric encryption and decryption modes and GCM and CCM decryption modes, concatenating the results of **update()** and **doFinal()** throughout the process will yield the complete plaintext or ciphertext.

(2) Encrypts or decrypts the data passed in RSA and SM2 asymmetric encryption or decryption. This API uses a promise to return the encrypted or decrypted data. If a large amount of data is to be processed, call **doFinal()** multiple times and concatenate the results to obtain the complete plaintext or ciphertext.

> **NOTE**
>
>  1. In symmetric encryption and decryption, calling **doFinal()** indicates the completion of an encryption and decryption process, meaning the [Cipher](#cipher) instance status is cleared. When a new encryption or decryption process is started, **init()** must be called again with a full set of parameters.
>
>     Even if the same **Cipher** instance and symmetric key are used for encryption and decryption, the **params** parameter must be set in **init()** instead of being **null**.
>  2. If decryption fails, check whether the data matches the parameters in **ini()**, for example, check whether **authTag** obtained during encryption in GCM mode is filled in **GcmParamsSpec** during decryption.
>  3. The result of **doFinal()** may be **null**. To avoid exceptions, determine whether the result is **null** before using the **.data** field to access the **doFinal()** result.
>
>     For encryption in CFB, OFB, or CTR mode, if **doFinal()** passes in **null**, the returned result is **null**.
>
>     For decryption in GCM, CCM, CFB, OFB, or CTR mode, if **doFinal()** passes in **null**, the returned result is **null**. For decryption in other modes, if **update** is called to pass in all the plaintext, which is an integer multiple of the encryption block size, and **doFinal()** is called to pass in **null**, the returned result is **null**.
>  4. For details about the sample code for calling **doFinal** multiple times in asymmetric encryption and decryption, see [Encryption and Decryption by Segment with an RSA Asymmetric Key Pair](../../security/CryptoArchitectureKit/crypto-rsa-asym-encrypt-decrypt-by-segment.md). The operations are similar for SM2 and RSA.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Cipher
- API versions 10 to 11: SystemCapability.Security.CryptoFramework

**Parameters**

| Name| Type                 | Mandatory| Description                |
| ---- | --------------------- | ---- | -------------------- |
| data | [DataBlob](#datablob) \| null<sup>10+</sup> | Yes  | Data to encrypt or decrypt. It can be **null**, but cannot be {data:Uint8Array(empty)}. In versions earlier than API version 10, only **DataBlob** is supported. Since API version 10, **null** is also supported.|

**Return value**

| Type                           | Description                                            |
| ------------------------------- | ------------------------------------------------ |
| Promise\<[DataBlob](#datablob)> | Promise used to return the **DataBlob**, which is the encryption or decryption result of the remaining data.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message                                    |
| -------- | -------------------------------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | Memory operation failed.                                |
| 17620002 | Failed to obtain the native object or convert parameters.                               |
| 17620003 | Parameter check failed. Possible causes: <br>1. The data is too long. <br>Applicable versions: 22+|
| 17630001 | Crypto operation error.                      |

**Example**

For more encryption and decryption examples, see [Encryption and Decryption with an AES Symmetric Key (GCM Mode)](../../security/CryptoArchitectureKit/crypto-aes-sym-encrypt-decrypt-gcm.md).

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { buffer } from '@kit.ArkTS';

function generateRandom(len: number) {
  let rand = cryptoFramework.createRandom();
  let generateRandSync = rand.generateRandomSync(len);
  return generateRandSync;
}

function genGcmParamsSpec() {
  let ivBlob = generateRandom(12);
  let arr = [1, 2, 3, 4, 5, 6, 7, 8];
  let dataAad = new Uint8Array(arr);
  let aadBlob: cryptoFramework.DataBlob = { data: dataAad };
  arr = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0];
  let dataTag = new Uint8Array(arr);
  let tagBlob: cryptoFramework.DataBlob = {
    data: dataTag
  };
  let gcmParamsSpec: cryptoFramework.GcmParamsSpec = {
    iv: ivBlob,
    aad: aadBlob,
    authTag: tagBlob,
    algName: 'GcmParamsSpec'
  };
  return gcmParamsSpec;
}

async function cipherByPromise() {
  let gcmParams = genGcmParamsSpec();
  let symKeyGenerator = cryptoFramework.createSymKeyGenerator('AES128');
  let cipher = cryptoFramework.createCipher('AES128|GCM|PKCS7');
  let symKey = await symKeyGenerator.generateSymKey();
  await cipher.init(cryptoFramework.CryptoMode.ENCRYPT_MODE, symKey, gcmParams);
  let message = 'This is a test';
  let plainText: cryptoFramework.DataBlob = { data: new Uint8Array(buffer.from(message, 'utf-8').buffer) };
  let encryptUpdate = await cipher.update(plainText);
  gcmParams.authTag = await cipher.doFinal(null);
  console.info('encryptUpdate plainText: ' + encryptUpdate.data);
}
```

### doFinalSync<sup>12+</sup>

doFinalSync(data: DataBlob | null): DataBlob

(1) Processes the remaining data and the data passed in this time, and completes the encryption or decryption operation for symmetric encryption and decryption. This API returns the encrypted or decrypted data synchronously.

If a small amount of data is to be processed, you can pass in all the data at a time in **doFinalSync()** without using **updateSync()**. If data has been passed in by using [updateSync](#updatesync12) in the current encryption and decryption process, you can pass in **null** to the **data** parameter of **doFinalSync()**.

The output of **doFinalSync()** varies with the symmetric block cipher mode in use.

- In a single encryption process with GCM or CCM mode, concatenating the results of each **updateSync()** and **doFinalSync()** procedures the ciphertext and **authTag**. In GCM mode, **authTag** is the last 16 bytes. In CCM mode, **authTag** is the last 12 bytes. The rest part is the ciphertext. If **data** in **doFinalSync()** is **null**, the result of **doFinalSync()** is **authTag**.

  During decryption, **authTag** must be set in [GcmParamsSpec](#gcmparamsspec) or [CcmParamsSpec](#ccmparamsspec), and the ciphertext must be set in **data**.
- For other symmetric encryption and decryption modes and GCM and CCM decryption modes, concatenating the results of **updateSync()** and **doFinalSync()** throughout the process will yield the complete plaintext or ciphertext.

(2) Encrypts or decrypts the input data for RSA or SM2 asymmetric encryption/decryption. This API returns the encrypted or decrypted data synchronously. If a large amount of data is to be processed, call **doFinalSync()** multiple times and concatenate the results to obtain the complete plaintext or ciphertext.

See **NOTE** in [doFinal()](#dofinal) for other precautions.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Cipher

**Parameters**

| Name| Type                                       | Mandatory| Description                                                        |
| ------ | ------------------------------------------- | ---- | ------------------------------------------------------------ |
| data   | [DataBlob](#datablob)  \| null| Yes  | Data to encrypt or decrypt. It can be **null** in symmetric encryption or decryption, but cannot be {data:Uint8Array(empty)}.|

**Return value**

| Type                           | Description                                            |
| ------------------------------- | ------------------------------------------------ |
| [DataBlob](#datablob) | Encrypted or decrypted data.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message               |
| -------- | ----------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | Memory operation failed.           |
| 17620002 | Failed to obtain the native object or convert parameters.          |
| 17620003 | Parameter check failed. Possible causes: <br>1. The data is too long.|
| 17630001 | Crypto operation error. |

**Example**

For more encryption and decryption examples, see [Encryption and Decryption with an AES Symmetric Key (GCM Mode)](../../security/CryptoArchitectureKit/crypto-aes-sym-encrypt-decrypt-gcm.md).

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { buffer } from '@kit.ArkTS';

function generateRandom(len: number) {
  let rand = cryptoFramework.createRandom();
  let generateRandSync = rand.generateRandomSync(len);
  return generateRandSync;
}

function genGcmParamsSpec() {
  let ivBlob = generateRandom(12);
  let arr = [1, 2, 3, 4, 5, 6, 7, 8];
  let dataAad = new Uint8Array(arr);
  let aadBlob: cryptoFramework.DataBlob = { data: dataAad };
  arr = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0];
  let dataTag = new Uint8Array(arr);
  let tagBlob: cryptoFramework.DataBlob = {
    data: dataTag
  };
  let gcmParamsSpec: cryptoFramework.GcmParamsSpec = {
    iv: ivBlob,
    aad: aadBlob,
    authTag: tagBlob,
    algName: 'GcmParamsSpec'
  };
  return gcmParamsSpec;
}

async function cipherBySync() {
  let gcmParams = genGcmParamsSpec();
  let symKeyGenerator = cryptoFramework.createSymKeyGenerator('AES128');
  let cipher = cryptoFramework.createCipher('AES128|GCM|PKCS7');
  let symKey = await symKeyGenerator.generateSymKey();
  await cipher.init(cryptoFramework.CryptoMode.ENCRYPT_MODE, symKey, gcmParams);
  let message = 'This is a test';
  let plainText: cryptoFramework.DataBlob = { data: new Uint8Array(buffer.from(message, 'utf-8').buffer) };
  let encryptUpdate = cipher.updateSync(plainText);
  gcmParams.authTag = cipher.doFinalSync(null);
  console.info('encryptUpdate plainText: ' + encryptUpdate.data);
}
```

### setCipherSpec<sup>10+</sup>

setCipherSpec(itemType: CipherSpecItem, itemValue: Uint8Array): void

Sets cipher specifications. You can use this API to set cipher specifications that cannot be set by [createCipher](#cryptoframeworkcreatecipher). Currently, only RSA is supported.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Cipher
- API versions 10 to 11: SystemCapability.Security.CryptoFramework

**Parameters**

| Name  | Type                | Mandatory| Description      |
| -------- | -------------------- | ---- | ---------- |
| itemType     | [CipherSpecItem](#cipherspecitem10)           | Yes  | Cipher parameter to set.|
| itemValue | Uint8Array | Yes  | Value of the parameter to set.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 801 | This operation is not supported.          |
| 17620001 | Memory operation failed.          |
| 17620003 | Parameter check failed. Possible causes: <br>1. Unsupported itemType.|
| 17630001 | Crypto operation error. |

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';

function testsetCipherSpec() {
  let cipher = cryptoFramework.createCipher('RSA2048|PKCS1_OAEP|SHA256|MGF1_SHA1');
  let pSource = new Uint8Array([1, 2, 3, 4]);
  cipher.setCipherSpec(cryptoFramework.CipherSpecItem.OAEP_MGF1_PSRC_UINT8ARR, pSource);
}
```

### getCipherSpec<sup>10+</sup>

getCipherSpec(itemType: CipherSpecItem): string | Uint8Array

Obtains cipher specifications. Currently, only RSA and SM2 (available since API version 11) are supported.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Cipher
- API versions 10 to 11: SystemCapability.Security.CryptoFramework

**Parameters**

| Name| Type    | Mandatory| Description      |
| ------ | -------- | ---- | ---------- |
| itemType   | [CipherSpecItem](#cipherspecitem10) | Yes  | Cipher parameter to obtain.|

**Return value**

| Type          | Description       |
| -------------- | ----------- |
| string \| Uint8Array | Returns the value of the cipher parameter obtained.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 801 | This operation is not supported.          |
| 17620001 | Memory operation failed.          |
| 17620003 | Parameter check failed. Possible causes: <br>1. Unsupported itemType.|
| 17630001 | Crypto operation error. |

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';

function testGetCipherSpec() {
  let cipher = cryptoFramework.createCipher('RSA2048|PKCS1_OAEP|SHA256|MGF1_SHA1');
  let mdName = cipher.getCipherSpec(cryptoFramework.CipherSpecItem.OAEP_MD_NAME_STR);
  console.info('getCipherSpec: mdName =' + mdName);
}
```

## cryptoFramework.createSign

createSign(algName: string): Sign

Creates a signing instance.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Signature
- API versions 9 to 11: SystemCapability.Security.CryptoFramework

**Parameters**

| Name | Type  | Mandatory| Description                                                        |
| ------- | ------ | ---- | ------------------------------------------------------------ |
| algName | string | Yes  | Signing algorithm to use. Currently, RSA, ECC, DSA, SM2<sup>10+</sup>, Ed25519<sup>11+</sup>, and ML-DSA<sup>26.0.0+</sup> are supported. If RSA PKCS1 is used, you must set the digest. If RSA PSS is used, you must set the digest and mask digest. For signing, you can set **OnlySign** to enable the data digest to be used for signing only.<br>For details about the supported specifications, see [Signing and Signature Verification Overview and Algorithm Specifications](../../security/CryptoArchitectureKit/crypto-sign-sig-verify-overview.md).|

**Return value**

| Type| Description                              |
| ---- | ---------------------------------- |
| [Sign](#sign) | **Sign** instance of the corresponding algorithm.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 801 | This operation is not supported.          |
| 17620001 | Memory operation failed.          |

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';

let signer1 = cryptoFramework.createSign('RSA1024|PKCS1|SHA256');

let signer2 = cryptoFramework.createSign('RSA1024|PSS|SHA256|MGF1_SHA256');

let signer3 = cryptoFramework.createSign('ECC224|SHA256');

let signer4 = cryptoFramework.createSign('DSA2048|SHA256');

let signer5 = cryptoFramework.createSign('RSA1024|PKCS1|SHA256|OnlySign');
```

## Sign

Provides a signing API for signing data based on a private key. Before calling this API, you need to construct this instance using [createSign(algName: string): Sign](#cryptoframeworkcreatesign). Invoke **init()**, **update()**, and **sign()** in this class in sequence to complete the signing operation. For details about the sample code, see [Signing and Signature Verification with an RSA Key Pair (PKCS1 Mode)](../../security/CryptoArchitectureKit/crypto-rsa-sign-sig-verify-pkcs1.md).

The **Sign** instance does not support repeated initialization. When a new key is used for signing, you must create a new **Sign** instance and call **init()** for initialization.

The signing mode is determined by **createSign()**, and the key is set by **init()**.

If a small amount of data is to be signed, you can directly call **sign()** to pass in the data for signing after **ini()**.

If a large amount of data is to be signed, you can use **update()** to pass in the data by segment, and then use **sign()** to sign the entire data.

When **update()** is used, the **sign()** API supports only **DataBlob** in versions earlier than API version 10 and starts to support **null** since API version 10. After all the data is passed in by using **update()**, call **sign()** to sign the data.

If the DSA algorithm is used for signing and the digest algorithm is **NoHash**, the **update()** operation is not supported. If **update()** is called in this case, the error code **ERR_CRYPTO_OPERATION** will be returned.

### Attributes

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Signature
- API versions 9 to 11: SystemCapability.Security.CryptoFramework

| Name   | Type  | Read-Only| Optional| Description                        |
| ------- | ------ | ---- | ---- | ---------------------------- |
| algName | string | Yes  | No  | Algorithm to use.|

### init

init(priKey: PriKey, callback: AsyncCallback\<void>): void

Initializes the **Sign** instance using a private key. This API uses an asynchronous callback to return the result. **init**, **update**, and **sign** must be used together. **init** and **sign** are mandatory, and **update** is optional.

The **Sign** instance does not support repeated initialization.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Signature
- API versions 9 to 11: SystemCapability.Security.CryptoFramework

**Parameters**

| Name  | Type                | Mandatory| Description            |
| -------- | -------------------- | ---- | ---------------- |
| priKey   | [PriKey](#prikey)    | Yes  | Private key used for the initialization.|
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. If the signing object is successfully initialized, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | Memory operation failed.          |
| 17620002 | Failed to obtain the native object or convert parameters.         |
| 17630001 | Crypto operation error. |
| 17620003 | Parameter check failed. Possible causes: <br>1. Incorrect key type. <br>Applicable versions: 26.0.0+|

### init

init(priKey: PriKey): Promise\<void>

Initializes the **Sign** instance using a private key. This API uses a promise to return the result. **init**, **update**, and **sign** must be used together. **init** and **sign** are mandatory, and **update** is optional.

The **Sign** instance does not support repeated initialization.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Signature
- API versions 9 to 11: SystemCapability.Security.CryptoFramework

**Parameters**

| Name| Type| Mandatory| Description            |
| ------ | ---- | ---- | ---------------- |
| priKey | [PriKey](#prikey)  | Yes  | Private key used for the initialization.|

**Return value**

| Type          | Description         |
| -------------- | ------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | Memory operation failed.          |
| 17620002 | Failed to obtain the native object or convert parameters.         |
| 17630001 | Crypto operation error. |
| 17620003 | Parameter check failed. Possible causes: <br>1. Incorrect key type. <br>Applicable versions: 26.0.0+|

### initSync<sup>12+</sup>

initSync(priKey: PriKey): void

Initializes the **Sign** instance with a private key. This API returns the result synchronously. **initSync**, **updateSync**, and **signSync** must be used together. **initSync** and **signSync** are mandatory, and **updateSync** is optional.

The **Sign** instance does not support repeated use of **initSync**.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Signature

**Parameters**

| Name| Type| Mandatory| Description            |
| ------ | ---- | ---- | ---------------- |
| priKey | [PriKey](#prikey)  | Yes  | Private key used for the initialization.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | Memory operation failed.          |
| 17620002 | Failed to obtain the native object or convert parameters.         |
| 17630001 | Crypto operation error. |
| 17620003 | Parameter check failed. Possible causes: <br>1. Incorrect key type. <br>Applicable versions: 26.0.0+|

### update

update(data: DataBlob, callback: AsyncCallback\<void>): void

Updates data to be signed. This API uses an asynchronous callback to return the result.

This API can be called only after the [Sign](#sign) instance is initialized by using [init()](#init-2).

> **NOTE**
>
> You can call **update** multiple times or do not use **update** (call [sign](#sign-1) after [init](#init-2)), depending on the data volume.<br>
> The amount of the data to be passed in by **update()** (one-time or accumulative) is not limited. If there is a large amount of data, you are advised to call **update()** multiple times to pass in the data by segment. This prevents too much memory from being requested at a time.<br>
> For details about the sample code for calling **update()** multiple times in signing, see [Signing and Signature Verification by Segment with an RSA Key Pair (PKCS1 Mode)](../../security/CryptoArchitectureKit/crypto-rsa-sign-sig-verify-pkcs1-by-segment.md). The operations of other algorithms are similar.<br>
> **OnlySign** cannot be used with **update()**. If **OnlySign** is specified, use **sign()** to pass in data.<br>
> If the DSA algorithm is used for signing and the digest algorithm is **NoHash**, **update()** is not supported. If **update()** is called in this case, **ERR_CRYPTO_OPERATION** will be returned.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Signature
- API versions 9 to 11: SystemCapability.Security.CryptoFramework

**Parameters**

| Name  | Type                 | Mandatory| Description        |
| -------- | --------------------- | ---- | ------------ |
| data     | [DataBlob](#datablob) | Yes  | Data to pass in.|
| callback | AsyncCallback\<void>  | Yes  | Callback used to return the result. If the signature update is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | Memory operation failed.          |
| 17620002 | Failed to obtain the native object or convert parameters.          |
| 17620004 | Invalid function call. <br>Applicable versions: 26.0.0+|
| 17630001 | Crypto operation error. |

### update

update(data: DataBlob): Promise\<void>

Updates data to be signed. This API uses a promise to return the result.

Before using this API, you must use [init()](#init-3) to initialize the [Sign](#sign) instance.

> **NOTE**
>
> You can call **update** multiple times or do not use **update** (call [sign](#sign-2) after [init](#init-3)), depending on the data volume.<br>
> The amount of the data to be passed in by **update()** (one-time or accumulative) is not limited. If there is a large amount of data, you are advised to call **update()** multiple times to pass in the data by segment. This prevents too much memory from being requested at a time.
> For details about the sample code for calling **update()** multiple times in signing, see [Signing and Signature Verification by Segment with an RSA Key Pair (PKCS1 Mode)](../../security/CryptoArchitectureKit/crypto-rsa-sign-sig-verify-pkcs1-by-segment.md). The operations of other algorithms are similar.<br>
> **OnlySign** cannot be used with **update()**. If **OnlySign** is specified, use **sign()** to pass in data.<br>
> If the DSA algorithm is used for signing and the digest algorithm is **NoHash**, **update()** is not supported. If **update()** is called in this case, **ERR_CRYPTO_OPERATION** will be returned.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Signature
- API versions 9 to 11: SystemCapability.Security.CryptoFramework

**Parameters**

| Name| Type    | Mandatory| Description      |
| ------ | -------- | ---- | ---------- |
| data   | [DataBlob](#datablob)  | Yes  | Data to pass in.|

**Return value**

| Type          | Description         |
| -------------- | ------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | Memory operation failed.          |
| 17620002 | Failed to obtain the native object or convert parameters.         |
| 17620004 | Invalid function call. <br>Applicable versions: 26.0.0+|
| 17630001 | Crypto operation error. |

### updateSync<sup>12+</sup>

updateSync(data: DataBlob): void

Updates data to be signed. This API returns the result synchronously.

This API can be called only after the [Sign](#sign) instance is initialized by using [initSync()](#initsync12-1).

> **NOTE**
>
> You can call **updateSync** multiple times or do not use **updateSync** (call [signSync](#signsync12) after [initSync](#initsync12-1)), depending on the data volume.<br>
> The amount of the data to be passed in by **updateSync** (one-time or accumulative) is not limited. If there is a large amount of data, you are advised to call **updateSync** multiple times to pass in the data by segment. This prevents too much memory from being requested at a time.<br>
> For details about the sample code for calling **updateSync** multiple times in signing, see [Signing and Signature Verification by Segment with an RSA Key Pair (PKCS1 Mode)](../../security/CryptoArchitectureKit/crypto-rsa-sign-sig-verify-pkcs1-by-segment.md). The operations of other algorithms are similar.<br>
> **OnlySign** cannot be used with **updateSync**. If **OnlySign** is specified, use **signSync** to pass in data.<br>
> If the DSA algorithm is used for signing and the digest algorithm is **NoHash**, **updateSync** is not supported. If **updateSync** is called in this case, **ERR_CRYPTO_OPERATION** will be returned.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Signature

**Parameters**

| Name| Type    | Mandatory| Description      |
| ------ | -------- | ---- | ---------- |
| data   | [DataBlob](#datablob)  | Yes  | Data to pass in.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | Memory operation failed.          |
| 17620002 | Failed to obtain the native object or convert parameters.         |
| 17620004 | Invalid function call. <br>Applicable versions: 26.0.0+|
| 17630001 | Crypto operation error. |

### sign

sign(data: DataBlob, callback: AsyncCallback\<DataBlob>): void

Verifies the signature. This API uses an asynchronous callback to return the result. The **Sign** class does not support repeated use of **sign**.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Signature
- API versions 9 to 11: SystemCapability.Security.CryptoFramework

**Parameters**

| Name    | Type                     | Mandatory| Description                                                        |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| data     | [DataBlob](#datablob)     | Yes  | Data to be signed.                                              |
| callback | AsyncCallback\<[DataBlob](#datablob)> | Yes  | Callback used to return the result. If the signing is successful, **err** is **undefined**, and **data** is the signing result obtained. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes,see [Universal Error Codes](../errorcode-universal.md) and [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message                                                |
| -------- | --------------------------------------------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | Memory operation failed.          |
| 17620002 | Failed to obtain the native object or convert parameters.         |
| 17620003 | Parameter check failed. <br>Applicable versions: 26.0.0+|
| 17630001 | crypto operation error. |

### sign<sup>10+</sup>

sign(data: DataBlob | null, callback: AsyncCallback\<DataBlob>): void

Signs data. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Signature
- API versions 10 to 11: SystemCapability.Security.CryptoFramework

**Parameters**

| Name  | Type                | Mandatory| Description      |
| -------- | -------------------- | ---- | ---------- |
| data     | [DataBlob](#datablob) \| null<sup>10+</sup>              | Yes  | Data to pass in. In versions earlier than API version 10, only **DataBlob** is supported. Since API version 10, **null** is also supported.|
| callback | AsyncCallback\<[DataBlob](#datablob)> | Yes  | Callback used to return **DataBlob**, which is the signing result. If the signing is successful, **err** is **undefined**, and **data** is the signing result obtained. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | Memory operation failed.          |
| 17620002 | Failed to obtain the native object or convert parameters.         |
| 17620003 | Parameter check failed. <br>Applicable versions: 26.0.0+|
| 17630001 | Crypto operation error. |

### sign

sign(data: DataBlob): Promise\<DataBlob>

Verifies the signature. This API uses a promise to return the result. The **Sign** class does not support repeated use of **sign**.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Signature
- API versions 9 to 11: SystemCapability.Security.CryptoFramework

**Parameters**

| Name| Type                 | Mandatory| Description              |
| ---- | --------------------- | ---- | -------------------- |
| data | [DataBlob](#datablob) | Yes  | Data to be signed.      |

**Return value**

| Type                           | Description                                            |
| ------------------------------- | ------------------------------------------------ |
| Promise\<[DataBlob](#datablob)> | Promise used to return the signing result.|

**Error codes**

For details about the error codes,see [Universal Error Codes](../errorcode-universal.md) and [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | Memory operation failed.                                     |
| 17620002 | Failed to obtain the native object or convert parameters.                                    |
| 17620003 | Parameter check failed. <br>Applicable versions: 26.0.0+|
| 17630001 | crypto operation error. |

### sign<sup>10+</sup>

sign(data: DataBlob | null): Promise\<DataBlob>

Signs data. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Signature
- API versions 10 to 11: SystemCapability.Security.CryptoFramework

**Parameters**

| Name| Type    | Mandatory| Description      |
| ------ | -------- | ---- | ---------- |
| data   | [DataBlob](#datablob) \| null<sup>10+</sup>  | Yes  | Data to pass in.|

**Return value**

| Type          | Description         |
| -------------- | ------------- |
| Promise\<[DataBlob](#datablob)> | Promise used to return the signing result.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | Memory operation failed.          |
| 17620002 | Failed to obtain the native object or convert parameters.         |
| 17630001 | Crypto operation error. |
| 17620003 | Parameter check failed. <br>Applicable versions: 26.0.0+|

### signSync<sup>12+</sup>

signSync(data: DataBlob | null): DataBlob

Signs the data. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Signature

**Parameters**

| Name| Type    | Mandatory| Description      |
| ------ | -------- | ---- | ---------- |
| data   | [DataBlob](#datablob) \| null  | Yes  | Data to pass in.|

**Return value**

| Type          | Description         |
| -------------- | ------------- |
| [DataBlob](#datablob) | Signature.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | Memory operation failed.          |
| 17620002 | Failed to obtain the native object or convert parameters.         |
| 17630001 | Crypto operation error. |
| 17620003 | Parameter check failed. <br>Applicable versions: 26.0.0+|

**Example**

For more examples of signing and signature verification, see [Signing and Signature Verification with an RSA Key Pair (PKCS1 Mode)](../../security/CryptoArchitectureKit/crypto-rsa-sign-sig-verify-pkcs1.md).

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { buffer } from '@kit.ArkTS';

function signByCallback() {
  let inputUpdate: cryptoFramework.DataBlob =
    { data: new Uint8Array(buffer.from('This is Sign test plan1', 'utf-8').buffer) };
  let inputVerify: cryptoFramework.DataBlob =
    { data: new Uint8Array(buffer.from('This is Sign test plan2', 'utf-8').buffer) };
  let pkData =
    new Uint8Array([48, 129, 159, 48, 13, 6, 9, 42, 134, 72, 134, 247, 13, 1, 1, 1, 5, 0, 3, 129, 141, 0, 48, 129, 137,
      2, 129, 129, 0, 214, 179, 23, 198, 183, 139, 148, 8, 173, 74, 56, 160, 15, 248, 244, 166, 209, 250, 142, 74, 216,
      58, 117, 215, 178, 247, 254, 39, 180, 227, 85, 201, 59, 133, 209, 221, 26, 9, 116, 31, 172, 151, 252, 185, 123,
      20, 25, 7, 92, 129, 5, 196, 239, 214, 126, 254, 154, 188, 239, 144, 161, 171, 65, 42, 31, 214, 93, 115, 247, 69,
      94, 143, 54, 51, 25, 49, 146, 204, 205, 165, 20, 120, 35, 184, 190, 65, 106, 12, 214, 176, 57, 125, 235, 51, 88,
      135, 76, 73, 109, 112, 147, 138, 198, 252, 5, 20, 245, 51, 7, 32, 108, 89, 125, 204, 50, 189, 88, 254, 255, 146,
      244, 244, 149, 79, 54, 216, 45, 89, 2, 3, 1, 0, 1]);
  let skData =
    new Uint8Array([48, 130, 2, 120, 2, 1, 0, 48, 13, 6, 9, 42, 134, 72, 134, 247, 13, 1, 1, 1, 5, 0, 4, 130, 2, 98, 48,
      130, 2, 94, 2, 1, 0, 2, 129, 129, 0, 214, 179, 23, 198, 183, 139, 148, 8, 173, 74, 56, 160, 15, 248, 244, 166,
      209, 250, 142, 74, 216, 58, 117, 215, 178, 247, 254, 39, 180, 227, 85, 201, 59, 133, 209, 221, 26, 9, 116, 31,
      172, 151, 252, 185, 123, 20, 25, 7, 92, 129, 5, 196, 239, 214, 126, 254, 154, 188, 239, 144, 161, 171, 65, 42, 31,
      214, 93, 115, 247, 69, 94, 143, 54, 51, 25, 49, 146, 204, 205, 165, 20, 120, 35, 184, 190, 65, 106, 12, 214, 176,
      57, 125, 235, 51, 88, 135, 76, 73, 109, 112, 147, 138, 198, 252, 5, 20, 245, 51, 7, 32, 108, 89, 125, 204, 50,
      189, 88, 254, 255, 146, 244, 244, 149, 79, 54, 216, 45, 89, 2, 3, 1, 0, 1, 2, 129, 129, 0, 152, 111, 145, 203, 10,
      88, 116, 163, 112, 126, 9, 20, 68, 34, 235, 121, 98, 14, 182, 102, 151, 125, 114, 91, 210, 122, 215, 29, 212, 5,
      176, 203, 238, 146, 5, 190, 41, 21, 91, 56, 125, 239, 111, 133, 53, 200, 192, 56, 132, 202, 42, 145, 120, 3, 224,
      40, 223, 46, 148, 29, 41, 92, 17, 40, 12, 72, 165, 69, 192, 211, 142, 233, 81, 202, 177, 235, 156, 27, 179, 48,
      18, 85, 154, 101, 193, 45, 218, 91, 24, 143, 196, 248, 16, 83, 177, 198, 136, 77, 111, 134, 60, 219, 95, 246, 23,
      5, 45, 14, 83, 29, 137, 248, 159, 28, 132, 142, 205, 99, 226, 213, 84, 232, 57, 130, 156, 81, 191, 237, 2, 65, 0,
      255, 158, 212, 13, 43, 132, 244, 135, 148, 161, 232, 219, 20, 81, 196, 102, 103, 44, 110, 71, 100, 62, 73, 200,
      32, 138, 114, 209, 171, 150, 179, 92, 198, 5, 190, 218, 79, 227, 227, 37, 32, 57, 159, 252, 107, 211, 139, 198,
      202, 248, 137, 143, 186, 205, 106, 81, 85, 207, 134, 148, 110, 204, 243, 27, 2, 65, 0, 215, 4, 181, 121, 57, 224,
      170, 168, 183, 159, 152, 8, 74, 233, 80, 244, 146, 81, 48, 159, 194, 199, 36, 187, 6, 181, 182, 223, 115, 133,
      151, 171, 78, 219, 90, 161, 248, 69, 6, 207, 173, 3, 81, 161, 2, 60, 238, 204, 177, 12, 138, 17, 220, 179, 71,
      113, 200, 248, 159, 153, 252, 150, 180, 155, 2, 65, 0, 190, 202, 185, 211, 170, 171, 238, 40, 84, 84, 21, 13, 144,
      57, 7, 178, 183, 71, 126, 120, 98, 229, 235, 4, 40, 229, 173, 149, 185, 209, 29, 199, 29, 54, 164, 161, 38, 8, 30,
      62, 83, 179, 47, 42, 165, 0, 156, 207, 160, 39, 169, 229, 81, 180, 136, 170, 116, 182, 20, 233, 45, 90, 100, 9, 2,
      65, 0, 152, 255, 47, 198, 15, 201, 238, 133, 89, 11, 133, 153, 184, 252, 37, 239, 177, 65, 118, 80, 231, 190, 222,
      66, 250, 118, 72, 166, 221, 67, 156, 245, 119, 138, 28, 6, 142, 107, 71, 122, 116, 200, 156, 199, 237, 152, 191,
      239, 4, 184, 64, 114, 143, 81, 62, 48, 23, 233, 217, 95, 47, 221, 104, 171, 2, 64, 30, 219, 1, 230, 241, 70, 246,
      243, 121, 174, 67, 66, 11, 99, 202, 17, 52, 234, 78, 29, 3, 57, 51, 123, 149, 86, 64, 192, 73, 199, 108, 101, 55,
      232, 41, 114, 153, 237, 253, 52, 205, 148, 45, 86, 186, 241, 182, 183, 42, 77, 252, 195, 29, 158, 173, 3, 182,
      207, 254, 61, 71, 184, 167, 184]);
  let pubKeyBlob: cryptoFramework.DataBlob = { data: pkData };
  let priKeyBlob: cryptoFramework.DataBlob = { data: skData };
  let rsaGenerator = cryptoFramework.createAsyKeyGenerator('RSA1024');
  let signer = cryptoFramework.createSign('RSA1024|PKCS1|SHA256');
  rsaGenerator.convertKey(pubKeyBlob, priKeyBlob, (err, keyPair) => {
    signer.init(keyPair.priKey, err => {
      signer.update(inputUpdate, err => {
        signer.sign(inputVerify, (err, signData) => {
          console.info('sign output = ' + signData.data);
        });
      });
    });
  });
}
```

**Example**

For more examples of signing and signature verification, see [Signing and Signature Verification with an RSA Key Pair (PKCS1 Mode)](../../security/CryptoArchitectureKit/crypto-rsa-sign-sig-verify-pkcs1.md).

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { buffer } from '@kit.ArkTS';

async function genKeyPairByData(pubKeyData: Uint8Array, priKeyData: Uint8Array) {
  let pubKeyBlob: cryptoFramework.DataBlob = { data: pubKeyData };
  let priKeyBlob: cryptoFramework.DataBlob = { data: priKeyData };
  let rsaGenerator = cryptoFramework.createAsyKeyGenerator('RSA1024');
  let keyPair = await rsaGenerator.convertKey(pubKeyBlob, priKeyBlob);
  console.info('convertKey result: success.');
  return keyPair;
}

async function signByPromise() {
  let pkData =
    new Uint8Array([48, 129, 159, 48, 13, 6, 9, 42, 134, 72, 134, 247, 13, 1, 1, 1, 5, 0, 3, 129, 141, 0, 48, 129, 137,
      2, 129, 129, 0, 214, 179, 23, 198, 183, 139, 148, 8, 173, 74, 56, 160, 15, 248, 244, 166, 209, 250, 142, 74, 216,
      58, 117, 215, 178, 247, 254, 39, 180, 227, 85, 201, 59, 133, 209, 221, 26, 9, 116, 31, 172, 151, 252, 185, 123,
      20, 25, 7, 92, 129, 5, 196, 239, 214, 126, 254, 154, 188, 239, 144, 161, 171, 65, 42, 31, 214, 93, 115, 247, 69,
      94, 143, 54, 51, 25, 49, 146, 204, 205, 165, 20, 120, 35, 184, 190, 65, 106, 12, 214, 176, 57, 125, 235, 51, 88,
      135, 76, 73, 109, 112, 147, 138, 198, 252, 5, 20, 245, 51, 7, 32, 108, 89, 125, 204, 50, 189, 88, 254, 255, 146,
      244, 244, 149, 79, 54, 216, 45, 89, 2, 3, 1, 0, 1]);
  let skData =
    new Uint8Array([48, 130, 2, 120, 2, 1, 0, 48, 13, 6, 9, 42, 134, 72, 134, 247, 13, 1, 1, 1, 5, 0, 4, 130, 2, 98, 48,
      130, 2, 94, 2, 1, 0, 2, 129, 129, 0, 214, 179, 23, 198, 183, 139, 148, 8, 173, 74, 56, 160, 15, 248, 244, 166,
      209, 250, 142, 74, 216, 58, 117, 215, 178, 247, 254, 39, 180, 227, 85, 201, 59, 133, 209, 221, 26, 9, 116, 31,
      172, 151, 252, 185, 123, 20, 25, 7, 92, 129, 5, 196, 239, 214, 126, 254, 154, 188, 239, 144, 161, 171, 65, 42, 31,
      214, 93, 115, 247, 69, 94, 143, 54, 51, 25, 49, 146, 204, 205, 165, 20, 120, 35, 184, 190, 65, 106, 12, 214, 176,
      57, 125, 235, 51, 88, 135, 76, 73, 109, 112, 147, 138, 198, 252, 5, 20, 245, 51, 7, 32, 108, 89, 125, 204, 50,
      189, 88, 254, 255, 146, 244, 244, 149, 79, 54, 216, 45, 89, 2, 3, 1, 0, 1, 2, 129, 129, 0, 152, 111, 145, 203, 10,
      88, 116, 163, 112, 126, 9, 20, 68, 34, 235, 121, 98, 14, 182, 102, 151, 125, 114, 91, 210, 122, 215, 29, 212, 5,
      176, 203, 238, 146, 5, 190, 41, 21, 91, 56, 125, 239, 111, 133, 53, 200, 192, 56, 132, 202, 42, 145, 120, 3, 224,
      40, 223, 46, 148, 29, 41, 92, 17, 40, 12, 72, 165, 69, 192, 211, 142, 233, 81, 202, 177, 235, 156, 27, 179, 48,
      18, 85, 154, 101, 193, 45, 218, 91, 24, 143, 196, 248, 16, 83, 177, 198, 136, 77, 111, 134, 60, 219, 95, 246, 23,
      5, 45, 14, 83, 29, 137, 248, 159, 28, 132, 142, 205, 99, 226, 213, 84, 232, 57, 130, 156, 81, 191, 237, 2, 65, 0,
      255, 158, 212, 13, 43, 132, 244, 135, 148, 161, 232, 219, 20, 81, 196, 102, 103, 44, 110, 71, 100, 62, 73, 200,
      32, 138, 114, 209, 171, 150, 179, 92, 198, 5, 190, 218, 79, 227, 227, 37, 32, 57, 159, 252, 107, 211, 139, 198,
      202, 248, 137, 143, 186, 205, 106, 81, 85, 207, 134, 148, 110, 204, 243, 27, 2, 65, 0, 215, 4, 181, 121, 57, 224,
      170, 168, 183, 159, 152, 8, 74, 233, 80, 244, 146, 81, 48, 159, 194, 199, 36, 187, 6, 181, 182, 223, 115, 133,
      151, 171, 78, 219, 90, 161, 248, 69, 6, 207, 173, 3, 81, 161, 2, 60, 238, 204, 177, 12, 138, 17, 220, 179, 71,
      113, 200, 248, 159, 153, 252, 150, 180, 155, 2, 65, 0, 190, 202, 185, 211, 170, 171, 238, 40, 84, 84, 21, 13, 144,
      57, 7, 178, 183, 71, 126, 120, 98, 229, 235, 4, 40, 229, 173, 149, 185, 209, 29, 199, 29, 54, 164, 161, 38, 8, 30,
      62, 83, 179, 47, 42, 165, 0, 156, 207, 160, 39, 169, 229, 81, 180, 136, 170, 116, 182, 20, 233, 45, 90, 100, 9, 2,
      65, 0, 152, 255, 47, 198, 15, 201, 238, 133, 89, 11, 133, 153, 184, 252, 37, 239, 177, 65, 118, 80, 231, 190, 222,
      66, 250, 118, 72, 166, 221, 67, 156, 245, 119, 138, 28, 6, 142, 107, 71, 122, 116, 200, 156, 199, 237, 152, 191,
      239, 4, 184, 64, 114, 143, 81, 62, 48, 23, 233, 217, 95, 47, 221, 104, 171, 2, 64, 30, 219, 1, 230, 241, 70, 246,
      243, 121, 174, 67, 66, 11, 99, 202, 17, 52, 234, 78, 29, 3, 57, 51, 123, 149, 86, 64, 192, 73, 199, 108, 101, 55,
      232, 41, 114, 153, 237, 253, 52, 205, 148, 45, 86, 186, 241, 182, 183, 42, 77, 252, 195, 29, 158, 173, 3, 182,
      207, 254, 61, 71, 184, 167, 184]);
  let keyPair = await genKeyPairByData(pkData, skData);
  let inputUpdate: cryptoFramework.DataBlob =
    { data: new Uint8Array(buffer.from('This is Sign test plan1', 'utf-8').buffer) };
  let inputSign: cryptoFramework.DataBlob =
    { data: new Uint8Array(buffer.from('This is Sign test plan2', 'utf-8').buffer) };
  let signer = cryptoFramework.createSign('RSA1024|PKCS1|SHA256');
  await signer.init(keyPair.priKey);
  await signer.update(inputUpdate);
  let signData = await signer.sign(inputSign);
  console.info('signData result: ' + signData.data);
}
```

**Example**

For more examples of signing and signature verification, see [Signing and Signature Verification with an RSA Key Pair (PKCS1 Mode)](../../security/CryptoArchitectureKit/crypto-rsa-sign-sig-verify-pkcs1.md).

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { buffer } from '@kit.ArkTS';

function genKeyPairByData(pubKeyData: Uint8Array, priKeyData: Uint8Array) {
  let pubKeyBlob: cryptoFramework.DataBlob = { data: pubKeyData };
  let priKeyBlob: cryptoFramework.DataBlob = { data: priKeyData };
  let rsaGenerator = cryptoFramework.createAsyKeyGenerator('RSA1024');
  let keyPair = rsaGenerator.convertKeySync(pubKeyBlob, priKeyBlob);
  console.info('convertKeySync result: success.');
  return keyPair;
}

function signBySync() {
  let pkData =
    new Uint8Array([48, 129, 159, 48, 13, 6, 9, 42, 134, 72, 134, 247, 13, 1, 1, 1, 5, 0, 3, 129, 141, 0, 48, 129, 137,
      2, 129, 129, 0, 214, 179, 23, 198, 183, 139, 148, 8, 173, 74, 56, 160, 15, 248, 244, 166, 209, 250, 142, 74, 216,
      58, 117, 215, 178, 247, 254, 39, 180, 227, 85, 201, 59, 133, 209, 221, 26, 9, 116, 31, 172, 151, 252, 185, 123,
      20, 25, 7, 92, 129, 5, 196, 239, 214, 126, 254, 154, 188, 239, 144, 161, 171, 65, 42, 31, 214, 93, 115, 247, 69,
      94, 143, 54, 51, 25, 49, 146, 204, 205, 165, 20, 120, 35, 184, 190, 65, 106, 12, 214, 176, 57, 125, 235, 51, 88,
      135, 76, 73, 109, 112, 147, 138, 198, 252, 5, 20, 245, 51, 7, 32, 108, 89, 125, 204, 50, 189, 88, 254, 255, 146,
      244, 244, 149, 79, 54, 216, 45, 89, 2, 3, 1, 0, 1]);
  let skData =
    new Uint8Array([48, 130, 2, 120, 2, 1, 0, 48, 13, 6, 9, 42, 134, 72, 134, 247, 13, 1, 1, 1, 5, 0, 4, 130, 2, 98, 48,
      130, 2, 94, 2, 1, 0, 2, 129, 129, 0, 214, 179, 23, 198, 183, 139, 148, 8, 173, 74, 56, 160, 15, 248, 244, 166,
      209, 250, 142, 74, 216, 58, 117, 215, 178, 247, 254, 39, 180, 227, 85, 201, 59, 133, 209, 221, 26, 9, 116, 31,
      172, 151, 252, 185, 123, 20, 25, 7, 92, 129, 5, 196, 239, 214, 126, 254, 154, 188, 239, 144, 161, 171, 65, 42, 31,
      214, 93, 115, 247, 69, 94, 143, 54, 51, 25, 49, 146, 204, 205, 165, 20, 120, 35, 184, 190, 65, 106, 12, 214, 176,
      57, 125, 235, 51, 88, 135, 76, 73, 109, 112, 147, 138, 198, 252, 5, 20, 245, 51, 7, 32, 108, 89, 125, 204, 50,
      189, 88, 254, 255, 146, 244, 244, 149, 79, 54, 216, 45, 89, 2, 3, 1, 0, 1, 2, 129, 129, 0, 152, 111, 145, 203, 10,
      88, 116, 163, 112, 126, 9, 20, 68, 34, 235, 121, 98, 14, 182, 102, 151, 125, 114, 91, 210, 122, 215, 29, 212, 5,
      176, 203, 238, 146, 5, 190, 41, 21, 91, 56, 125, 239, 111, 133, 53, 200, 192, 56, 132, 202, 42, 145, 120, 3, 224,
      40, 223, 46, 148, 29, 41, 92, 17, 40, 12, 72, 165, 69, 192, 211, 142, 233, 81, 202, 177, 235, 156, 27, 179, 48,
      18, 85, 154, 101, 193, 45, 218, 91, 24, 143, 196, 248, 16, 83, 177, 198, 136, 77, 111, 134, 60, 219, 95, 246, 23,
      5, 45, 14, 83, 29, 137, 248, 159, 28, 132, 142, 205, 99, 226, 213, 84, 232, 57, 130, 156, 81, 191, 237, 2, 65, 0,
      255, 158, 212, 13, 43, 132, 244, 135, 148, 161, 232, 219, 20, 81, 196, 102, 103, 44, 110, 71, 100, 62, 73, 200,
      32, 138, 114, 209, 171, 150, 179, 92, 198, 5, 190, 218, 79, 227, 227, 37, 32, 57, 159, 252, 107, 211, 139, 198,
      202, 248, 137, 143, 186, 205, 106, 81, 85, 207, 134, 148, 110, 204, 243, 27, 2, 65, 0, 215, 4, 181, 121, 57, 224,
      170, 168, 183, 159, 152, 8, 74, 233, 80, 244, 146, 81, 48, 159, 194, 199, 36, 187, 6, 181, 182, 223, 115, 133,
      151, 171, 78, 219, 90, 161, 248, 69, 6, 207, 173, 3, 81, 161, 2, 60, 238, 204, 177, 12, 138, 17, 220, 179, 71,
      113, 200, 248, 159, 153, 252, 150, 180, 155, 2, 65, 0, 190, 202, 185, 211, 170, 171, 238, 40, 84, 84, 21, 13, 144,
      57, 7, 178, 183, 71, 126, 120, 98, 229, 235, 4, 40, 229, 173, 149, 185, 209, 29, 199, 29, 54, 164, 161, 38, 8, 30,
      62, 83, 179, 47, 42, 165, 0, 156, 207, 160, 39, 169, 229, 81, 180, 136, 170, 116, 182, 20, 233, 45, 90, 100, 9, 2,
      65, 0, 152, 255, 47, 198, 15, 201, 238, 133, 89, 11, 133, 153, 184, 252, 37, 239, 177, 65, 118, 80, 231, 190, 222,
      66, 250, 118, 72, 166, 221, 67, 156, 245, 119, 138, 28, 6, 142, 107, 71, 122, 116, 200, 156, 199, 237, 152, 191,
      239, 4, 184, 64, 114, 143, 81, 62, 48, 23, 233, 217, 95, 47, 221, 104, 171, 2, 64, 30, 219, 1, 230, 241, 70, 246,
      243, 121, 174, 67, 66, 11, 99, 202, 17, 52, 234, 78, 29, 3, 57, 51, 123, 149, 86, 64, 192, 73, 199, 108, 101, 55,
      232, 41, 114, 153, 237, 253, 52, 205, 148, 45, 86, 186, 241, 182, 183, 42, 77, 252, 195, 29, 158, 173, 3, 182,
      207, 254, 61, 71, 184, 167, 184]);
  let keyPair = genKeyPairByData(pkData, skData);
  let inputUpdate: cryptoFramework.DataBlob =
    { data: new Uint8Array(buffer.from('This is Sign test plan1', 'utf-8').buffer) };
  let inputSign: cryptoFramework.DataBlob =
    { data: new Uint8Array(buffer.from('This is Sign test plan2', 'utf-8').buffer) };
  let signer = cryptoFramework.createSign('RSA1024|PKCS1|SHA256');
  signer.initSync(keyPair.priKey);
  signer.updateSync(inputUpdate);
  let signData = signer.signSync(inputSign);
  console.info('signData result: ' + signData.data);
}
```

### setSignSpec<sup>10+</sup>

setSignSpec(itemType: SignSpecItem, itemValue: number): void

Sets signing specifications. You can use this API to set signing parameters that cannot be set by [createSign](#cryptoframeworkcreatesign).

Currently, only RSA and SM2 are supported. Since API version 11, SM2 signing parameters can be set.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Signature
- API versions 10 to 11: SystemCapability.Security.CryptoFramework

**Parameters**

| Name  | Type                | Mandatory| Description      |
| -------- | -------------------- | ---- | ---------- |
| itemType     | [SignSpecItem](#signspecitem10)              | Yes  | Signing parameter to set.|
| itemValue | number | Yes  | Value of the signing parameter to set.|

**Error codes**

For details about the error codes,see [Universal Error Codes](../errorcode-universal.md) and [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 801 | This operation is not supported.          |
| 17620001 | Memory operation failed.          |
| 17630001 | Crypto operation error. |
| 17620003 | Parameter check failed. <br>Applicable versions: 26.0.0+|

### setSignSpec<sup>11+</sup>

setSignSpec(itemType: SignSpecItem, itemValue: number \| Uint8Array): void

Sets signing specifications. You can use this API to set signing parameters that cannot be set by [createSign](#cryptoframeworkcreatesign).


Currently, only RSA and SM2 are supported. Since API version 11, SM2 signing parameters can be set.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Signature
- API version 11: SystemCapability.Security.CryptoFramework

**Parameters**

| Name  | Type                | Mandatory| Description      |
| -------- | -------------------- | ---- | ---------- |
| itemType     | [SignSpecItem](#signspecitem10)              | Yes  | Signing parameter to set.|
| itemValue | number \| Uint8Array<sup>11+</sup> | Yes  | Value of the signing parameter to set.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 801 | This operation is not supported.          |
| 17620001 | Memory operation failed.          |
| 17630001 | Crypto operation error. |
| 17620002 | Failed to obtain the native object or convert parameters. <br>Applicable versions: 26.0.0+|
| 17620003 | Parameter check failed. <br>Applicable versions: 26.0.0+|
| 17620004 | Invalid function call. <br>Applicable versions: 26.0.0+|

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';

function testSetSignSpec() {
  let signer = cryptoFramework.createSign('RSA|PSS|SHA256|MGF1_SHA256');
  let setN = 20;
  signer.setSignSpec(cryptoFramework.SignSpecItem.PSS_SALT_LEN_NUM, setN);
}
```

### setSignSpec

setSignSpec(itemType: SignSpecItem, itemValue: number \| Uint8Array \| boolean): void

Sets signing specifications. String parameters of the signing algorithm are specified using [createSign](#cryptoframeworkcreatesign). The ML-DSA parameters are set using this API, including whether to use deterministic signatures, whether to use external mu pre-hashing, and the context string.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.Security.CryptoFramework.Signature

**Parameters**

| Name  | Type                | Mandatory| Description      |
| -------- | -------------------- | ---- | ---------- |
| itemType     | [SignSpecItem](#signspecitem10)              | Yes  | Signing parameter to set.|
| itemValue | number \| Uint8Array \| boolean | Yes  | Value of the signing parameter to set. For details about the parameters, see [SignSpecItem](#signspecitem10).|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 801 | This operation is not supported. |
| 17620001 | Memory operation failed. |
| 17620002 | Failed to obtain the native object or convert parameters. |
| 17620003 | Parameter check failed. |
| 17620004 | Invalid function call. |
| 17630001 | Crypto operation error. |

**Example**
```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';

function testSetSignSpec() {
  let signer = cryptoFramework.createSign('ML-DSA');
  signer.setSignSpec(cryptoFramework.SignSpecItem.ML_DSA_DETERMINISTIC_BOOL, true);
}
```

### getSignSpec<sup>10+</sup>

getSignSpec(itemType: SignSpecItem): string | number

Obtains signing specifications. Currently, only RSA is supported.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Signature
- API versions 10 to 11: SystemCapability.Security.CryptoFramework

**Parameters**

| Name| Type    | Mandatory| Description      |
| ------ | -------- | ---- | ---------- |
| itemType | [SignSpecItem](#signspecitem10)  | Yes  | Signing parameter to obtain.|

**Return value**

| Type          | Description       |
| -------------- | ----------- |
| string \| number | Returns the value of the signing parameter obtained.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 801 | This operation is not supported.          |
| 17620001 | Memory operation failed.          |
| 17630001 | Crypto operation error. |
| 17620003 | Parameter check failed. <br>Applicable versions: 26.0.0+|

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';

function testGetSignSpec() {
  let signer = cryptoFramework.createSign('RSA|PSS|SHA256|MGF1_SHA256');
  let setN = 32;
  signer.setSignSpec(cryptoFramework.SignSpecItem.PSS_SALT_LEN_NUM, setN);
  signer.getSignSpec(cryptoFramework.SignSpecItem.PSS_SALT_LEN_NUM);
}
```

## cryptoFramework.createVerify

createVerify(algName: string): Verify

Creates a signature verification instance.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Signature
- API versions 9 to 11: SystemCapability.Security.CryptoFramework

**Parameters**

| Name | Type  | Mandatory| Description                                                        |
| ------- | ------ | ---- | ------------------------------------------------------------ |
| algName | string | Yes  | Signature verification algorithm to use. Currently, RSA, ECC, DSA, SM2<sup>10+</sup>, Ed25519<sup>11+</sup>, and ML-DSA<sup>26.0.0+</sup> are supported. If RSA PKCS1 is used, you must set the digest. If RSA PSS is used, you must set the digest and mask digest. When the RSA algorithm is used for signature verification, you can use **Recover** to verify and recover the signed data.<br>For details about the supported specifications, see [Signing and Signature Verification Overview and Algorithm Specifications](../../security/CryptoArchitectureKit/crypto-sign-sig-verify-overview.md).|

**Return value**

| Type  | Description                                |
| ------ | ------------------------------------ |
| [Verify](#verify) | **Verify** instance of the corresponding algorithm.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 801 | This operation is not supported.          |
| 17620001 | Memory operation failed.          |

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';

let verifier1 = cryptoFramework.createVerify('RSA1024|PKCS1|SHA256');

let verifier2 = cryptoFramework.createVerify('RSA1024|PSS|SHA256|MGF1_SHA256');

let verifier3 = cryptoFramework.createVerify('RSA1024|PKCS1|SHA256|Recover');
```

## Verify

Provides a signature verification API for verifying signature data based on the public key. Before calling this API, you need to construct this instance using [createVerify(algName: string): Verify](#cryptoframeworkcreateverify). Invoke **init()**, **update()**, and **verify()** in this class in sequence to complete the signature verification. For details about the sample code, see [Signing and Signature Verification with an RSA Key Pair (PKCS1 Mode)](../../security/CryptoArchitectureKit/crypto-rsa-sign-sig-verify-pkcs1.md).

The **Verify** instance does not support repeated initialization. When a new key is used for signature verification, you must create a new **Verify** instance and call **init()** for initialization.

The signature verification mode is determined in **createVerify()**, and the key is set by **init()**.

If the signed message is short, you can call **verify()** to pass in the signed message and signature (**signatureData**) for signature verification after **init()**. That is, you do not need to use **update()**.

If the signed message is too long, you can call **update()** multiple times to pass in the signed message by segment, and then call **verify()** to verify the full text of the message. In versions earlier than API version 10, the input parameter **data** of **verify()** supports only **DataBlob**. Since API version 10, **data** also supports **null**. After all the data is passed in by using **update()**, **verify()** can be called to verify the signature data.

If the DSA algorithm is used for signature verification and the digest algorithm is **NoHash**, **update()** is not supported. If **update()** is called in this case, **ERR_CRYPTO_OPERATION** will be returned.

### Attributes

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Signature
- API versions 9 to 11: SystemCapability.Security.CryptoFramework

| Name   | Type  | Read-Only| Optional| Description                        |
| ------- | ------ | ---- | ---- | ---------------------------- |
| algName | string | Yes  | No  | Algorithm to be used for signature verification.|

### init

init(pubKey: PubKey, callback: AsyncCallback\<void>): void

Initializes a **Verify** instance by using the public key. This API uses an asynchronous callback to return the result. **init**, **update**, and **verify** must be used together. **init** and **verify** are mandatory, and **update** is optional.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Signature
- API versions 9 to 11: SystemCapability.Security.CryptoFramework

**Parameters**

| Name  | Type                | Mandatory| Description                          |
| -------- | -------------------- | ---- | ------------------------------ |
| pubKey   | [PubKey](#pubkey)    | Yes  | Public key used to initialize the **Verify** instance.|
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. If the signature verification objects is successfully initialized, **err** is **undefined**. Otherwise, **err** is an error object. |

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | Memory operation failed.          |
| 17620002 | Failed to obtain the native object or convert parameters.         |
| 17620003 | Parameter check failed. Possible causes: <br>1. Incorrect key type. <br>Applicable versions: 26.0.0+|
| 17630001 | Crypto operation error. |

### init

init(pubKey: PubKey): Promise\<void>

Initializes a **Verify** instance by using the public key. This API uses a promise to return the result. **init**, **update**, and **verify** must be used together. **init** and **verify** are mandatory, and **update** is optional.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Signature
- API versions 9 to 11: SystemCapability.Security.CryptoFramework

**Parameters**

| Name| Type| Mandatory| Description                        |
| ------ | ---- | ---- | ---------------------------- |
| pubKey | [PubKey](#pubkey)  | Yes  | Public key used to initialize the **Verify** instance.|

**Return value**

| Type          | Description         |
| -------------- | ------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | Memory operation failed.          |
| 17620002 | Failed to obtain the native object or convert parameters.         |
| 17630001 | Crypto operation error. |
| 17620003 | Parameter check failed. Possible causes: <br>1. Incorrect key type. <br>Applicable versions: 26.0.0+|

### initSync<sup>12+</sup>

initSync(pubKey: PubKey): void

Initializes the **Verify** instance with a public key. This API returns the result synchronously. **initSync**, **updateSync**, and **verifySync** must be used together. **initSync** and **verifySync** are mandatory, and **updateSync** is optional.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Signature

**Parameters**

| Name| Type| Mandatory| Description                        |
| ------ | ---- | ---- | ---------------------------- |
| pubKey | [PubKey](#pubkey)  | Yes  | Public key used to initialize the **Verify** instance.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | Memory operation failed.          |
| 17620002 | Failed to obtain the native object or convert parameters.         |
| 17630001 | Crypto operation error. |
| 17620003 | Parameter check failed. Possible causes: <br>1. Incorrect key type. <br>Applicable versions: 26.0.0+|

### update

update(data: DataBlob, callback: AsyncCallback\<void>): void

Updates the data for signature verifications. This API uses an asynchronous callback to return the result.

This API can be called only after the [Verify](#verify) instance is initialized using [init](#init-4).

> **NOTE**
>
> You can call **update** multiple times or do not use **update** (call [verify](#verify-1) after [init](#init-4)), depending on the data volume.<br>
> The amount of the data to be passed in by **update()** (one-time or accumulative) is not limited. If there is a large amount of data, you are advised to call **update()** multiple times to pass in the data by segment. This prevents too much memory from being requested at a time.<br>
> For details about the sample code for calling **update()** multiple times in signature verification, see [Signing and Signature Verification by Segment with an RSA Key Pair (PKCS1 Mode)](../../security/CryptoArchitectureKit/crypto-rsa-sign-sig-verify-pkcs1-by-segment.md). The operations of other algorithms are similar.<br>
> **OnlyVerify** cannot be used with **update()**. If **OnlyVerify** is specified, use **verify()** to pass in data.<br>
> If the DSA algorithm is used for signature verification and the digest algorithm is **NoHash**, **update()** is not supported. If **update()** is called in this case, **ERR_CRYPTO_OPERATION** will be returned.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Signature
- API versions 9 to 11: SystemCapability.Security.CryptoFramework

**Parameters**

| Name  | Type                 | Mandatory| Description        |
| -------- | --------------------- | ---- | ------------ |
| data     | [DataBlob](#datablob) | Yes  | Data to pass in.|
| callback | AsyncCallback\<void>  | Yes  | Callback used to return the result. If the signature verification update is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | Memory operation failed.          |
| 17620002 | Failed to obtain the native object or convert parameters.         |
| 17620004 | Invalid function call. <br>Applicable versions: 26.0.0+|
| 17630001 | Crypto operation error. |

### update

update(data: DataBlob): Promise\<void>

Updates the data for signature verifications. This API uses a promise to return the result.

This API can be called only after the [Verify](#verify) instance is initialized using [init()](#init-5).

> **NOTE**
>
> You can call **update** multiple times or do not use **update** (call [verify](#verify-2) after [init](#init-5)), depending on the data volume.<br>
> The amount of the data to be passed in by **update()** (one-time or accumulative) is not limited. If there is a large amount of data, you are advised to call **update()** multiple times to pass in the data by segment. This prevents too much memory from being requested at a time.<br>
> For details about the sample code for calling **update()** multiple times in signature verification, see [Signing and Signature Verification by Segment with an RSA Key Pair (PKCS1 Mode)](../../security/CryptoArchitectureKit/crypto-rsa-sign-sig-verify-pkcs1-by-segment.md). The operations of other algorithms are similar.<br>
> **OnlyVerify** cannot be used with **update()**. If **OnlyVerify** is specified, use **verify()** to pass in data.<br>
> If the DSA algorithm is used for signature verification and the digest algorithm is **NoHash**, **update()** is not supported. If **update()** is called in this case, **ERR_CRYPTO_OPERATION** will be returned.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Signature
- API versions 9 to 11: SystemCapability.Security.CryptoFramework

**Parameters**

| Name| Type    | Mandatory| Description      |
| ------ | -------- | ---- | ---------- |
| data   | [DataBlob](#datablob)  | Yes  | Data to pass in.|

**Return value**

| Type          | Description         |
| -------------- | ------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | Memory operation failed.          |
| 17620002 | Failed to obtain the native object or convert parameters.         |
| 17620004 | Invalid function call. <br>Applicable versions: 26.0.0+|
| 17630001 | Crypto operation error. |

### updateSync<sup>12+</sup>

updateSync(data: DataBlob): void

Updates the data for signature verifications. This API returns the result synchronously.

This API can be called only after the [Verify](#verify) instance is initialized by using [initSync()](#initsync12-2).

> **NOTE**
>
> You can call **updateSync** multiple times or do not use **updateSync** (call [verifySync](#verifysync12) after [initSync](#initsync12-2)), depending on the data volume.<br>
> The amount of the data to be passed in by **updateSync** (one-time or accumulative) is not limited. If there is a large amount of data, you are advised to call **updateSync** multiple times to pass in the data by segment. This prevents too much memory from being requested at a time.<br>
> For details about the sample code for calling **updateSync** multiple times in signature verification, see [Signing and Signature Verification by Segment with an RSA Key Pair (PKCS1 Mode)](../../security/CryptoArchitectureKit/crypto-rsa-sign-sig-verify-pkcs1-by-segment.md). The operations of other algorithms are similar.<br>
> **OnlyVerify** cannot be used with **updateSync**. If **OnlyVerify** is specified, use **verifySync()** to pass in data.<br>
> If the DSA algorithm is used for signature verification and the digest algorithm is **NoHash**, **updateSync** is not supported. If **updateSync** is called in this case, **ERR_CRYPTO_OPERATION** will be returned.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Signature

**Parameters**

| Name| Type    | Mandatory| Description      |
| ------ | -------- | ---- | ---------- |
| data   | [DataBlob](#datablob)  | Yes  | Data to pass in.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | Memory operation failed.          |
| 17620002 | Failed to obtain the native object or convert parameters.         |
| 17620004 | Invalid function call. <br>Applicable versions: 26.0.0+|
| 17630001 | Crypto operation error. |

### verify

verify(data: DataBlob, signatureData: DataBlob, callback: AsyncCallback\<boolean>): void

Verifies the signature. This API returns the verification result. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Signature
- API versions 9 to 11: SystemCapability.Security.CryptoFramework

**Parameters**

| Name       | Type                     | Mandatory| Description                                                        |
| ------------ | ------------------------- | ---- | ------------------------------------------------------------ |
| data         | [DataBlob](#datablob)     | Yes  | Pointer to the data with the signature to be verified.                                              |
| signatureData | [DataBlob](#datablob)     | Yes  | Signature data.                                                  |
| callback     | AsyncCallback\<boolean>   | Yes  | Callback used to return the signature verification result. **true** means that the signature verification is successful; **false** otherwise.|

**Error codes**

For details about the error codes,see [Universal Error Codes](../errorcode-universal.md) and [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message                                                |
| -------- | --------------------------------------------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | Memory operation failed.          |
| 17620002 | Failed to obtain the native object or convert parameters.         |
| 17620003 | Parameter check failed. <br>Applicable versions: 26.0.0+|
| 17630001 | crypto operation error. |

### verify<sup>10+</sup>

verify(data: DataBlob | null, signatureData: DataBlob, callback: AsyncCallback\<boolean>): void

Verifies the signature of the data. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Signature
- API versions 10 to 11: SystemCapability.Security.CryptoFramework

**Parameters**

| Name       | Type                | Mandatory| Description      |
| ------------- | -------------------- | ---- | ---------- |
| data          | [DataBlob](#datablob) \| null<sup>10+</sup>             | Yes  | Data to pass in. In versions earlier than API version 10, only **DataBlob** is supported. Since API version 10, **null** is also supported.|
| signatureData | [DataBlob](#datablob)              | Yes  | Signature data. |
| callback      | AsyncCallback\<boolean> | Yes  | Callback used to return the signature verification result. **true** means that the signature verification is successful; **false** otherwise.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | Memory operation failed.          |
| 17620002 | Failed to obtain the native object or convert parameters.         |
| 17620003 | Parameter check failed. <br>Applicable versions: 26.0.0+|
| 17630001 | Crypto operation error. |

### verify

verify(data: DataBlob, signatureData: DataBlob): Promise\<boolean>

Verifies the signature. This API returns the verification result. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Signature
- API versions 9 to 11: SystemCapability.Security.CryptoFramework

**Parameters**

| Name       | Type                 | Mandatory| Description              |
| ------------ | --------------------- | ---- | -------------------- |
| data         | [DataBlob](#datablob) | Yes  | Pointer to the data with the signature to be verified.      |
| signatureData | [DataBlob](#datablob) | Yes  | Signature data.          |

**Return value**

| Type            | Description                                            |
| ---------------- | ------------------------------------------------ |
| Promise\<boolean> | Promise used to return the verification result. **true** if the signature verification is successful; **false** otherwise.|

**Error codes**

For details about the error codes,see [Universal Error Codes](../errorcode-universal.md) and [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | Memory operation failed.                                     |
| 17620002 | Failed to obtain the native object or convert parameters.                                    |
| 17620003 | Parameter check failed. <br>Applicable versions: 26.0.0+|
| 17630001 | crypto operation error. |

### verify<sup>10+</sup>

verify(data: DataBlob | null, signatureData: DataBlob): Promise\<boolean>

Verifies the signature of the data. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Signature
- API versions 10 to 11: SystemCapability.Security.CryptoFramework

**Parameters**

| Name       | Type    | Mandatory| Description      |
| ------------- | -------- | ---- | ---------- |
| data          | [DataBlob](#datablob) \| null<sup>10+</sup>  | Yes  | Data to pass in. In versions earlier than API version 10, only **DataBlob** is supported. Since API version 10, **null** is also supported.|
| signatureData | [DataBlob](#datablob)  | Yes  | Signature data. |

**Return value**

| Type             | Description                          |
| ----------------- | ------------------------------ |
| Promise\<boolean> | Promise used to return the signature verification result. The value **true** indicates that the signature verification is successful, and **false** indicates the opposite.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | Memory operation failed.          |
| 17620002 | Failed to obtain the native object or convert parameters.         |
| 17630001 | Crypto operation error. |
| 17620003 | Parameter check failed. <br>Applicable versions: 26.0.0+|

### verifySync<sup>12+</sup>

verifySync(data: DataBlob | null, signatureData: DataBlob): boolean

Verifies the signature. This API returns the verification result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Signature

**Parameters**

| Name       | Type    | Mandatory| Description      |
| ------------- | -------- | ---- | ---------- |
| data          | [DataBlob](#datablob) \| null  | Yes  | Data to pass in.|
| signatureData | [DataBlob](#datablob)  | Yes  | Signature data. |

**Return value**

| Type             | Description                          |
| ----------------- | ------------------------------ |
| boolean | Signature verification result. **true**: passed; **false**: failed.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | Memory operation failed.          |
| 17620002 | Failed to obtain the native object or convert parameters.         |
| 17630001 | Crypto operation error. |
| 17620003 | Parameter check failed. <br>Applicable versions: 26.0.0+|

**Example**

For more examples of signing and signature verification, see [Signing and Signature Verification with an RSA Key Pair (PKCS1 Mode)](../../security/CryptoArchitectureKit/crypto-rsa-sign-sig-verify-pkcs1.md).

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { buffer } from '@kit.ArkTS';

function verifyByCallback() {
  let inputUpdate: cryptoFramework.DataBlob =
    { data: new Uint8Array(buffer.from('This is Sign test plan1', 'utf-8').buffer) };
  let inputVerify: cryptoFramework.DataBlob =
    { data: new Uint8Array(buffer.from('This is Sign test plan2', 'utf-8').buffer) };
  // Key generated based on the key data and input data for signature verification. If the data in verify() is the same as that in sign(), the signature verification is successful.
  let pkData =
    new Uint8Array([48, 129, 159, 48, 13, 6, 9, 42, 134, 72, 134, 247, 13, 1, 1, 1, 5, 0, 3, 129, 141, 0, 48, 129, 137,
      2, 129, 129, 0, 214, 179, 23, 198, 183, 139, 148, 8, 173, 74, 56, 160, 15, 248, 244, 166, 209, 250, 142, 74, 216,
      58, 117, 215, 178, 247, 254, 39, 180, 227, 85, 201, 59, 133, 209, 221, 26, 9, 116, 31, 172, 151, 252, 185, 123,
      20, 25, 7, 92, 129, 5, 196, 239, 214, 126, 254, 154, 188, 239, 144, 161, 171, 65, 42, 31, 214, 93, 115, 247, 69,
      94, 143, 54, 51, 25, 49, 146, 204, 205, 165, 20, 120, 35, 184, 190, 65, 106, 12, 214, 176, 57, 125, 235, 51, 88,
      135, 76, 73, 109, 112, 147, 138, 198, 252, 5, 20, 245, 51, 7, 32, 108, 89, 125, 204, 50, 189, 88, 254, 255, 146,
      244, 244, 149, 79, 54, 216, 45, 89, 2, 3, 1, 0, 1]);
  let skData =
    new Uint8Array([48, 130, 2, 120, 2, 1, 0, 48, 13, 6, 9, 42, 134, 72, 134, 247, 13, 1, 1, 1, 5, 0, 4, 130, 2, 98, 48,
      130, 2, 94, 2, 1, 0, 2, 129, 129, 0, 214, 179, 23, 198, 183, 139, 148, 8, 173, 74, 56, 160, 15, 248, 244, 166,
      209, 250, 142, 74, 216, 58, 117, 215, 178, 247, 254, 39, 180, 227, 85, 201, 59, 133, 209, 221, 26, 9, 116, 31,
      172, 151, 252, 185, 123, 20, 25, 7, 92, 129, 5, 196, 239, 214, 126, 254, 154, 188, 239, 144, 161, 171, 65, 42, 31,
      214, 93, 115, 247, 69, 94, 143, 54, 51, 25, 49, 146, 204, 205, 165, 20, 120, 35, 184, 190, 65, 106, 12, 214, 176,
      57, 125, 235, 51, 88, 135, 76, 73, 109, 112, 147, 138, 198, 252, 5, 20, 245, 51, 7, 32, 108, 89, 125, 204, 50,
      189, 88, 254, 255, 146, 244, 244, 149, 79, 54, 216, 45, 89, 2, 3, 1, 0, 1, 2, 129, 129, 0, 152, 111, 145, 203, 10,
      88, 116, 163, 112, 126, 9, 20, 68, 34, 235, 121, 98, 14, 182, 102, 151, 125, 114, 91, 210, 122, 215, 29, 212, 5,
      176, 203, 238, 146, 5, 190, 41, 21, 91, 56, 125, 239, 111, 133, 53, 200, 192, 56, 132, 202, 42, 145, 120, 3, 224,
      40, 223, 46, 148, 29, 41, 92, 17, 40, 12, 72, 165, 69, 192, 211, 142, 233, 81, 202, 177, 235, 156, 27, 179, 48,
      18, 85, 154, 101, 193, 45, 218, 91, 24, 143, 196, 248, 16, 83, 177, 198, 136, 77, 111, 134, 60, 219, 95, 246, 23,
      5, 45, 14, 83, 29, 137, 248, 159, 28, 132, 142, 205, 99, 226, 213, 84, 232, 57, 130, 156, 81, 191, 237, 2, 65, 0,
      255, 158, 212, 13, 43, 132, 244, 135, 148, 161, 232, 219, 20, 81, 196, 102, 103, 44, 110, 71, 100, 62, 73, 200,
      32, 138, 114, 209, 171, 150, 179, 92, 198, 5, 190, 218, 79, 227, 227, 37, 32, 57, 159, 252, 107, 211, 139, 198,
      202, 248, 137, 143, 186, 205, 106, 81, 85, 207, 134, 148, 110, 204, 243, 27, 2, 65, 0, 215, 4, 181, 121, 57, 224,
      170, 168, 183, 159, 152, 8, 74, 233, 80, 244, 146, 81, 48, 159, 194, 199, 36, 187, 6, 181, 182, 223, 115, 133,
      151, 171, 78, 219, 90, 161, 248, 69, 6, 207, 173, 3, 81, 161, 2, 60, 238, 204, 177, 12, 138, 17, 220, 179, 71,
      113, 200, 248, 159, 153, 252, 150, 180, 155, 2, 65, 0, 190, 202, 185, 211, 170, 171, 238, 40, 84, 84, 21, 13, 144,
      57, 7, 178, 183, 71, 126, 120, 98, 229, 235, 4, 40, 229, 173, 149, 185, 209, 29, 199, 29, 54, 164, 161, 38, 8, 30,
      62, 83, 179, 47, 42, 165, 0, 156, 207, 160, 39, 169, 229, 81, 180, 136, 170, 116, 182, 20, 233, 45, 90, 100, 9, 2,
      65, 0, 152, 255, 47, 198, 15, 201, 238, 133, 89, 11, 133, 153, 184, 252, 37, 239, 177, 65, 118, 80, 231, 190, 222,
      66, 250, 118, 72, 166, 221, 67, 156, 245, 119, 138, 28, 6, 142, 107, 71, 122, 116, 200, 156, 199, 237, 152, 191,
      239, 4, 184, 64, 114, 143, 81, 62, 48, 23, 233, 217, 95, 47, 221, 104, 171, 2, 64, 30, 219, 1, 230, 241, 70, 246,
      243, 121, 174, 67, 66, 11, 99, 202, 17, 52, 234, 78, 29, 3, 57, 51, 123, 149, 86, 64, 192, 73, 199, 108, 101, 55,
      232, 41, 114, 153, 237, 253, 52, 205, 148, 45, 86, 186, 241, 182, 183, 42, 77, 252, 195, 29, 158, 173, 3, 182,
      207, 254, 61, 71, 184, 167, 184]);
  let pubKeyBlob: cryptoFramework.DataBlob = { data: pkData };
  let priKeyBlob: cryptoFramework.DataBlob = { data: skData };
  // The data is signData.data in Sign().
  let signMessageBlob: cryptoFramework.DataBlob = {
    data: new Uint8Array([9, 68, 164, 161, 230, 155, 255, 153, 10, 12, 14, 22, 146, 115, 209, 167, 223, 133, 89, 173,
      50, 249, 176, 104, 10, 251, 219, 104, 117, 196, 105, 65, 249, 139, 119, 41, 15, 171, 191, 11, 177, 177, 1, 119,
      130, 142, 87, 183, 32, 220, 226, 28, 38, 73, 222, 172, 153, 26, 87, 58, 188, 42, 150, 67, 94, 214, 147, 64, 202,
      87, 155, 125, 254, 112, 95, 176, 255, 207, 106, 43, 228, 153, 131, 240, 120, 88, 253, 179, 207, 207, 110, 223,
      173, 15, 113, 11, 183, 122, 237, 205, 206, 123, 246, 33, 167, 169, 251, 237, 199, 26, 220, 152, 190, 117, 131, 74,
      232, 50, 39, 172, 232, 178, 112, 73, 251, 235, 131, 209])
  }
  let rsaGenerator = cryptoFramework.createAsyKeyGenerator('RSA1024');
  let verifier = cryptoFramework.createVerify('RSA1024|PKCS1|SHA256');
  rsaGenerator.convertKey(pubKeyBlob, priKeyBlob, (err, keyPair) => {
    verifier.init(keyPair.pubKey, err => {
      verifier.update(inputUpdate, err => {
        verifier.verify(inputVerify, signMessageBlob, (err, res) => {
          console.info('verify result = ' + res);
        });
      });
    });
  });
}
```

**Example**

For more examples, see [Signing and Signature Verification with an RSA Key Pair](../../security/CryptoArchitectureKit/crypto-rsa-sign-sig-verify-pkcs1.md).

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { buffer } from '@kit.ArkTS';

async function genKeyPairByData(pubKeyData: Uint8Array, priKeyData: Uint8Array) {
  let pubKeyBlob: cryptoFramework.DataBlob = { data: pubKeyData };
  let priKeyBlob: cryptoFramework.DataBlob = { data: priKeyData };
  let rsaGenerator = cryptoFramework.createAsyKeyGenerator('RSA1024');
  let keyPair = await rsaGenerator.convertKey(pubKeyBlob, priKeyBlob);
  console.info('convertKey result: success.');
  return keyPair;
}

async function verifyByPromise() {
  // Key generated based on the key data and input data for signature verification. If the data in verify() is the same as that in sign(), the signature verification is successful.
  let pkData =
    new Uint8Array([48, 129, 159, 48, 13, 6, 9, 42, 134, 72, 134, 247, 13, 1, 1, 1, 5, 0, 3, 129, 141, 0, 48, 129, 137,
      2, 129, 129, 0, 214, 179, 23, 198, 183, 139, 148, 8, 173, 74, 56, 160, 15, 248, 244, 166, 209, 250, 142, 74, 216,
      58, 117, 215, 178, 247, 254, 39, 180, 227, 85, 201, 59, 133, 209, 221, 26, 9, 116, 31, 172, 151, 252, 185, 123,
      20, 25, 7, 92, 129, 5, 196, 239, 214, 126, 254, 154, 188, 239, 144, 161, 171, 65, 42, 31, 214, 93, 115, 247, 69,
      94, 143, 54, 51, 25, 49, 146, 204, 205, 165, 20, 120, 35, 184, 190, 65, 106, 12, 214, 176, 57, 125, 235, 51, 88,
      135, 76, 73, 109, 112, 147, 138, 198, 252, 5, 20, 245, 51, 7, 32, 108, 89, 125, 204, 50, 189, 88, 254, 255, 146,
      244, 244, 149, 79, 54, 216, 45, 89, 2, 3, 1, 0, 1]);
  let skData =
    new Uint8Array([48, 130, 2, 120, 2, 1, 0, 48, 13, 6, 9, 42, 134, 72, 134, 247, 13, 1, 1, 1, 5, 0, 4, 130, 2, 98, 48,
      130, 2, 94, 2, 1, 0, 2, 129, 129, 0, 214, 179, 23, 198, 183, 139, 148, 8, 173, 74, 56, 160, 15, 248, 244, 166,
      209, 250, 142, 74, 216, 58, 117, 215, 178, 247, 254, 39, 180, 227, 85, 201, 59, 133, 209, 221, 26, 9, 116, 31,
      172, 151, 252, 185, 123, 20, 25, 7, 92, 129, 5, 196, 239, 214, 126, 254, 154, 188, 239, 144, 161, 171, 65, 42, 31,
      214, 93, 115, 247, 69, 94, 143, 54, 51, 25, 49, 146, 204, 205, 165, 20, 120, 35, 184, 190, 65, 106, 12, 214, 176,
      57, 125, 235, 51, 88, 135, 76, 73, 109, 112, 147, 138, 198, 252, 5, 20, 245, 51, 7, 32, 108, 89, 125, 204, 50,
      189, 88, 254, 255, 146, 244, 244, 149, 79, 54, 216, 45, 89, 2, 3, 1, 0, 1, 2, 129, 129, 0, 152, 111, 145, 203, 10,
      88, 116, 163, 112, 126, 9, 20, 68, 34, 235, 121, 98, 14, 182, 102, 151, 125, 114, 91, 210, 122, 215, 29, 212, 5,
      176, 203, 238, 146, 5, 190, 41, 21, 91, 56, 125, 239, 111, 133, 53, 200, 192, 56, 132, 202, 42, 145, 120, 3, 224,
      40, 223, 46, 148, 29, 41, 92, 17, 40, 12, 72, 165, 69, 192, 211, 142, 233, 81, 202, 177, 235, 156, 27, 179, 48,
      18, 85, 154, 101, 193, 45, 218, 91, 24, 143, 196, 248, 16, 83, 177, 198, 136, 77, 111, 134, 60, 219, 95, 246, 23,
      5, 45, 14, 83, 29, 137, 248, 159, 28, 132, 142, 205, 99, 226, 213, 84, 232, 57, 130, 156, 81, 191, 237, 2, 65, 0,
      255, 158, 212, 13, 43, 132, 244, 135, 148, 161, 232, 219, 20, 81, 196, 102, 103, 44, 110, 71, 100, 62, 73, 200,
      32, 138, 114, 209, 171, 150, 179, 92, 198, 5, 190, 218, 79, 227, 227, 37, 32, 57, 159, 252, 107, 211, 139, 198,
      202, 248, 137, 143, 186, 205, 106, 81, 85, 207, 134, 148, 110, 204, 243, 27, 2, 65, 0, 215, 4, 181, 121, 57, 224,
      170, 168, 183, 159, 152, 8, 74, 233, 80, 244, 146, 81, 48, 159, 194, 199, 36, 187, 6, 181, 182, 223, 115, 133,
      151, 171, 78, 219, 90, 161, 248, 69, 6, 207, 173, 3, 81, 161, 2, 60, 238, 204, 177, 12, 138, 17, 220, 179, 71,
      113, 200, 248, 159, 153, 252, 150, 180, 155, 2, 65, 0, 190, 202, 185, 211, 170, 171, 238, 40, 84, 84, 21, 13, 144,
      57, 7, 178, 183, 71, 126, 120, 98, 229, 235, 4, 40, 229, 173, 149, 185, 209, 29, 199, 29, 54, 164, 161, 38, 8, 30,
      62, 83, 179, 47, 42, 165, 0, 156, 207, 160, 39, 169, 229, 81, 180, 136, 170, 116, 182, 20, 233, 45, 90, 100, 9, 2,
      65, 0, 152, 255, 47, 198, 15, 201, 238, 133, 89, 11, 133, 153, 184, 252, 37, 239, 177, 65, 118, 80, 231, 190, 222,
      66, 250, 118, 72, 166, 221, 67, 156, 245, 119, 138, 28, 6, 142, 107, 71, 122, 116, 200, 156, 199, 237, 152, 191,
      239, 4, 184, 64, 114, 143, 81, 62, 48, 23, 233, 217, 95, 47, 221, 104, 171, 2, 64, 30, 219, 1, 230, 241, 70, 246,
      243, 121, 174, 67, 66, 11, 99, 202, 17, 52, 234, 78, 29, 3, 57, 51, 123, 149, 86, 64, 192, 73, 199, 108, 101, 55,
      232, 41, 114, 153, 237, 253, 52, 205, 148, 45, 86, 186, 241, 182, 183, 42, 77, 252, 195, 29, 158, 173, 3, 182,
      207, 254, 61, 71, 184, 167, 184]);
  let keyPair = await genKeyPairByData(pkData, skData);
  let inputUpdate: cryptoFramework.DataBlob =
    { data: new Uint8Array(buffer.from('This is Sign test plan1', 'utf-8').buffer) };
  let inputVerify: cryptoFramework.DataBlob =
    { data: new Uint8Array(buffer.from('This is Sign test plan2', 'utf-8').buffer) };
  // The data is signData.data in Sign().
  let signMessageBlob: cryptoFramework.DataBlob = {
    data: new Uint8Array([9, 68, 164, 161, 230, 155, 255, 153, 10, 12, 14, 22, 146, 115, 209, 167, 223, 133, 89, 173,
      50, 249, 176, 104, 10, 251, 219, 104, 117, 196, 105, 65, 249, 139, 119, 41, 15, 171, 191, 11, 177, 177, 1, 119,
      130, 142, 87, 183, 32, 220, 226, 28, 38, 73, 222, 172, 153, 26, 87, 58, 188, 42, 150, 67, 94, 214, 147, 64, 202,
      87, 155, 125, 254, 112, 95, 176, 255, 207, 106, 43, 228, 153, 131, 240, 120, 88, 253, 179, 207, 207, 110, 223,
      173, 15, 113, 11, 183, 122, 237, 205, 206, 123, 246, 33, 167, 169, 251, 237, 199, 26, 220, 152, 190, 117, 131, 74,
      232, 50, 39, 172, 232, 178, 112, 73, 251, 235, 131, 209])
  };
  let verifier = cryptoFramework.createVerify('RSA1024|PKCS1|SHA256');
  await verifier.init(keyPair.pubKey);
  await verifier.update(inputUpdate);
  let res = await verifier.verify(inputVerify, signMessageBlob);
  console.info('verify result: ' + res);
}
```

**Example**

For more examples of signing and signature verification, see [Signing and Signature Verification with an RSA Key Pair (PKCS1 Mode)](../../security/CryptoArchitectureKit/crypto-rsa-sign-sig-verify-pkcs1.md).

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { buffer } from '@kit.ArkTS';

function genKeyPairByData(pubKeyData: Uint8Array, priKeyData: Uint8Array) {
  let pubKeyBlob: cryptoFramework.DataBlob = { data: pubKeyData };
  let priKeyBlob: cryptoFramework.DataBlob = { data: priKeyData };
  let rsaGenerator = cryptoFramework.createAsyKeyGenerator('RSA1024');
  let keyPair = rsaGenerator.convertKeySync(pubKeyBlob, priKeyBlob);
  console.info('convertKey result: success.');
  return keyPair;
}

function verifyBySync() {
  // Key generated based on the key data and input data for signature verification. If the data in verify() is the same as that in sign(), the signature verification is successful.
  let pkData =
    new Uint8Array([48, 129, 159, 48, 13, 6, 9, 42, 134, 72, 134, 247, 13, 1, 1, 1, 5, 0, 3, 129, 141, 0, 48, 129, 137,
      2, 129, 129, 0, 214, 179, 23, 198, 183, 139, 148, 8, 173, 74, 56, 160, 15, 248, 244, 166, 209, 250, 142, 74, 216,
      58, 117, 215, 178, 247, 254, 39, 180, 227, 85, 201, 59, 133, 209, 221, 26, 9, 116, 31, 172, 151, 252, 185, 123,
      20, 25, 7, 92, 129, 5, 196, 239, 214, 126, 254, 154, 188, 239, 144, 161, 171, 65, 42, 31, 214, 93, 115, 247, 69,
      94, 143, 54, 51, 25, 49, 146, 204, 205, 165, 20, 120, 35, 184, 190, 65, 106, 12, 214, 176, 57, 125, 235, 51, 88,
      135, 76, 73, 109, 112, 147, 138, 198, 252, 5, 20, 245, 51, 7, 32, 108, 89, 125, 204, 50, 189, 88, 254, 255, 146,
      244, 244, 149, 79, 54, 216, 45, 89, 2, 3, 1, 0, 1]);
  let skData =
    new Uint8Array([48, 130, 2, 120, 2, 1, 0, 48, 13, 6, 9, 42, 134, 72, 134, 247, 13, 1, 1, 1, 5, 0, 4, 130, 2, 98, 48,
      130, 2, 94, 2, 1, 0, 2, 129, 129, 0, 214, 179, 23, 198, 183, 139, 148, 8, 173, 74, 56, 160, 15, 248, 244, 166,
      209, 250, 142, 74, 216, 58, 117, 215, 178, 247, 254, 39, 180, 227, 85, 201, 59, 133, 209, 221, 26, 9, 116, 31,
      172, 151, 252, 185, 123, 20, 25, 7, 92, 129, 5, 196, 239, 214, 126, 254, 154, 188, 239, 144, 161, 171, 65, 42, 31,
      214, 93, 115, 247, 69, 94, 143, 54, 51, 25, 49, 146, 204, 205, 165, 20, 120, 35, 184, 190, 65, 106, 12, 214, 176,
      57, 125, 235, 51, 88, 135, 76, 73, 109, 112, 147, 138, 198, 252, 5, 20, 245, 51, 7, 32, 108, 89, 125, 204, 50,
      189, 88, 254, 255, 146, 244, 244, 149, 79, 54, 216, 45, 89, 2, 3, 1, 0, 1, 2, 129, 129, 0, 152, 111, 145, 203, 10,
      88, 116, 163, 112, 126, 9, 20, 68, 34, 235, 121, 98, 14, 182, 102, 151, 125, 114, 91, 210, 122, 215, 29, 212, 5,
      176, 203, 238, 146, 5, 190, 41, 21, 91, 56, 125, 239, 111, 133, 53, 200, 192, 56, 132, 202, 42, 145, 120, 3, 224,
      40, 223, 46, 148, 29, 41, 92, 17, 40, 12, 72, 165, 69, 192, 211, 142, 233, 81, 202, 177, 235, 156, 27, 179, 48,
      18, 85, 154, 101, 193, 45, 218, 91, 24, 143, 196, 248, 16, 83, 177, 198, 136, 77, 111, 134, 60, 219, 95, 246, 23,
      5, 45, 14, 83, 29, 137, 248, 159, 28, 132, 142, 205, 99, 226, 213, 84, 232, 57, 130, 156, 81, 191, 237, 2, 65, 0,
      255, 158, 212, 13, 43, 132, 244, 135, 148, 161, 232, 219, 20, 81, 196, 102, 103, 44, 110, 71, 100, 62, 73, 200,
      32, 138, 114, 209, 171, 150, 179, 92, 198, 5, 190, 218, 79, 227, 227, 37, 32, 57, 159, 252, 107, 211, 139, 198,
      202, 248, 137, 143, 186, 205, 106, 81, 85, 207, 134, 148, 110, 204, 243, 27, 2, 65, 0, 215, 4, 181, 121, 57, 224,
      170, 168, 183, 159, 152, 8, 74, 233, 80, 244, 146, 81, 48, 159, 194, 199, 36, 187, 6, 181, 182, 223, 115, 133,
      151, 171, 78, 219, 90, 161, 248, 69, 6, 207, 173, 3, 81, 161, 2, 60, 238, 204, 177, 12, 138, 17, 220, 179, 71,
      113, 200, 248, 159, 153, 252, 150, 180, 155, 2, 65, 0, 190, 202, 185, 211, 170, 171, 238, 40, 84, 84, 21, 13, 144,
      57, 7, 178, 183, 71, 126, 120, 98, 229, 235, 4, 40, 229, 173, 149, 185, 209, 29, 199, 29, 54, 164, 161, 38, 8, 30,
      62, 83, 179, 47, 42, 165, 0, 156, 207, 160, 39, 169, 229, 81, 180, 136, 170, 116, 182, 20, 233, 45, 90, 100, 9, 2,
      65, 0, 152, 255, 47, 198, 15, 201, 238, 133, 89, 11, 133, 153, 184, 252, 37, 239, 177, 65, 118, 80, 231, 190, 222,
      66, 250, 118, 72, 166, 221, 67, 156, 245, 119, 138, 28, 6, 142, 107, 71, 122, 116, 200, 156, 199, 237, 152, 191,
      239, 4, 184, 64, 114, 143, 81, 62, 48, 23, 233, 217, 95, 47, 221, 104, 171, 2, 64, 30, 219, 1, 230, 241, 70, 246,
      243, 121, 174, 67, 66, 11, 99, 202, 17, 52, 234, 78, 29, 3, 57, 51, 123, 149, 86, 64, 192, 73, 199, 108, 101, 55,
      232, 41, 114, 153, 237, 253, 52, 205, 148, 45, 86, 186, 241, 182, 183, 42, 77, 252, 195, 29, 158, 173, 3, 182,
      207, 254, 61, 71, 184, 167, 184]);
  let keyPair = genKeyPairByData(pkData, skData);
  let inputUpdate: cryptoFramework.DataBlob =
    { data: new Uint8Array(buffer.from('This is Sign test plan1', 'utf-8').buffer) };
  let inputVerify: cryptoFramework.DataBlob =
    { data: new Uint8Array(buffer.from('This is Sign test plan2', 'utf-8').buffer) };
  // The data is signData.data in Sign().
  let signMessageBlob: cryptoFramework.DataBlob = {
    data: new Uint8Array([9, 68, 164, 161, 230, 155, 255, 153, 10, 12, 14, 22, 146, 115, 209, 167, 223, 133, 89, 173,
      50, 249, 176, 104, 10, 251, 219, 104, 117, 196, 105, 65, 249, 139, 119, 41, 15, 171, 191, 11, 177, 177, 1, 119,
      130, 142, 87, 183, 32, 220, 226, 28, 38, 73, 222, 172, 153, 26, 87, 58, 188, 42, 150, 67, 94, 214, 147, 64, 202,
      87, 155, 125, 254, 112, 95, 176, 255, 207, 106, 43, 228, 153, 131, 240, 120, 88, 253, 179, 207, 207, 110, 223,
      173, 15, 113, 11, 183, 122, 237, 205, 206, 123, 246, 33, 167, 169, 251, 237, 199, 26, 220, 152, 190, 117, 131, 74,
      232, 50, 39, 172, 232, 178, 112, 73, 251, 235, 131, 209])
  };
  let verifier = cryptoFramework.createVerify('RSA1024|PKCS1|SHA256');
  verifier.initSync(keyPair.pubKey);
  verifier.updateSync(inputUpdate);
  let res = verifier.verifySync(inputVerify, signMessageBlob);
  console.info('verify result: ' + res);
}
```

### recover<sup>12+</sup>

recover(signatureData: DataBlob): Promise\<DataBlob | null>

Recovers the original data from a signature. This API returns the result synchronously. This API uses a promise to return the result.

> **NOTE**
>
> - Currently, only RSA is supported.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Signature

**Parameters**

| Name       | Type    | Mandatory| Description      |
| ------------- | -------- | ---- | ---------- |
| signatureData | [DataBlob](#datablob)  | Yes  | Signature data. |

**Return value**

| Type             | Description                          |
| ----------------- | ------------------------------ |
| Promise\<[DataBlob](#datablob)  \| null> | Promise used to return the raw data recovered from the signature.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | Memory operation failed.          |
| 17620002 | Failed to obtain the native object or convert parameters.         |
| 17620004 | Invalid function call. <br>Applicable versions: 26.0.0+|
| 17630001 | Crypto operation error. |

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function genKeyPairByData(pubKeyData: Uint8Array, priKeyData: Uint8Array) {
  let pubKeyBlob: cryptoFramework.DataBlob = { data: pubKeyData };
  let priKeyBlob: cryptoFramework.DataBlob = { data: priKeyData };
  let rsaGenerator = cryptoFramework.createAsyKeyGenerator('RSA1024');
  let keyPair = await rsaGenerator.convertKey(pubKeyBlob, priKeyBlob);
  console.info('convertKey result: success.');
  return keyPair;
}

async function recoverByPromise() {
  // Key generated based on the key data and input data for signature verification. If the data in verify() is the same as that in sign(), the signature verification is successful.
  let pkData =
    new Uint8Array([48, 129, 159, 48, 13, 6, 9, 42, 134, 72, 134, 247, 13, 1, 1, 1, 5, 0, 3, 129, 141, 0, 48, 129, 137,
      2, 129, 129, 0, 214, 179, 23, 198, 183, 139, 148, 8, 173, 74, 56, 160, 15, 248, 244, 166, 209, 250, 142, 74, 216,
      58, 117, 215, 178, 247, 254, 39, 180, 227, 85, 201, 59, 133, 209, 221, 26, 9, 116, 31, 172, 151, 252, 185, 123,
      20, 25, 7, 92, 129, 5, 196, 239, 214, 126, 254, 154, 188, 239, 144, 161, 171, 65, 42, 31, 214, 93, 115, 247, 69,
      94, 143, 54, 51, 25, 49, 146, 204, 205, 165, 20, 120, 35, 184, 190, 65, 106, 12, 214, 176, 57, 125, 235, 51, 88,
      135, 76, 73, 109, 112, 147, 138, 198, 252, 5, 20, 245, 51, 7, 32, 108, 89, 125, 204, 50, 189, 88, 254, 255, 146,
      244, 244, 149, 79, 54, 216, 45, 89, 2, 3, 1, 0, 1]);
  let skData =
    new Uint8Array([48, 130, 2, 120, 2, 1, 0, 48, 13, 6, 9, 42, 134, 72, 134, 247, 13, 1, 1, 1, 5, 0, 4, 130, 2, 98, 48,
      130, 2, 94, 2, 1, 0, 2, 129, 129, 0, 214, 179, 23, 198, 183, 139, 148, 8, 173, 74, 56, 160, 15, 248, 244, 166,
      209, 250, 142, 74, 216, 58, 117, 215, 178, 247, 254, 39, 180, 227, 85, 201, 59, 133, 209, 221, 26, 9, 116, 31,
      172, 151, 252, 185, 123, 20, 25, 7, 92, 129, 5, 196, 239, 214, 126, 254, 154, 188, 239, 144, 161, 171, 65, 42, 31,
      214, 93, 115, 247, 69, 94, 143, 54, 51, 25, 49, 146, 204, 205, 165, 20, 120, 35, 184, 190, 65, 106, 12, 214, 176,
      57, 125, 235, 51, 88, 135, 76, 73, 109, 112, 147, 138, 198, 252, 5, 20, 245, 51, 7, 32, 108, 89, 125, 204, 50,
      189, 88, 254, 255, 146, 244, 244, 149, 79, 54, 216, 45, 89, 2, 3, 1, 0, 1, 2, 129, 129, 0, 152, 111, 145, 203, 10,
      88, 116, 163, 112, 126, 9, 20, 68, 34, 235, 121, 98, 14, 182, 102, 151, 125, 114, 91, 210, 122, 215, 29, 212, 5,
      176, 203, 238, 146, 5, 190, 41, 21, 91, 56, 125, 239, 111, 133, 53, 200, 192, 56, 132, 202, 42, 145, 120, 3, 224,
      40, 223, 46, 148, 29, 41, 92, 17, 40, 12, 72, 165, 69, 192, 211, 142, 233, 81, 202, 177, 235, 156, 27, 179, 48,
      18, 85, 154, 101, 193, 45, 218, 91, 24, 143, 196, 248, 16, 83, 177, 198, 136, 77, 111, 134, 60, 219, 95, 246, 23,
      5, 45, 14, 83, 29, 137, 248, 159, 28, 132, 142, 205, 99, 226, 213, 84, 232, 57, 130, 156, 81, 191, 237, 2, 65, 0,
      255, 158, 212, 13, 43, 132, 244, 135, 148, 161, 232, 219, 20, 81, 196, 102, 103, 44, 110, 71, 100, 62, 73, 200,
      32, 138, 114, 209, 171, 150, 179, 92, 198, 5, 190, 218, 79, 227, 227, 37, 32, 57, 159, 252, 107, 211, 139, 198,
      202, 248, 137, 143, 186, 205, 106, 81, 85, 207, 134, 148, 110, 204, 243, 27, 2, 65, 0, 215, 4, 181, 121, 57, 224,
      170, 168, 183, 159, 152, 8, 74, 233, 80, 244, 146, 81, 48, 159, 194, 199, 36, 187, 6, 181, 182, 223, 115, 133,
      151, 171, 78, 219, 90, 161, 248, 69, 6, 207, 173, 3, 81, 161, 2, 60, 238, 204, 177, 12, 138, 17, 220, 179, 71,
      113, 200, 248, 159, 153, 252, 150, 180, 155, 2, 65, 0, 190, 202, 185, 211, 170, 171, 238, 40, 84, 84, 21, 13, 144,
      57, 7, 178, 183, 71, 126, 120, 98, 229, 235, 4, 40, 229, 173, 149, 185, 209, 29, 199, 29, 54, 164, 161, 38, 8, 30,
      62, 83, 179, 47, 42, 165, 0, 156, 207, 160, 39, 169, 229, 81, 180, 136, 170, 116, 182, 20, 233, 45, 90, 100, 9, 2,
      65, 0, 152, 255, 47, 198, 15, 201, 238, 133, 89, 11, 133, 153, 184, 252, 37, 239, 177, 65, 118, 80, 231, 190, 222,
      66, 250, 118, 72, 166, 221, 67, 156, 245, 119, 138, 28, 6, 142, 107, 71, 122, 116, 200, 156, 199, 237, 152, 191,
      239, 4, 184, 64, 114, 143, 81, 62, 48, 23, 233, 217, 95, 47, 221, 104, 171, 2, 64, 30, 219, 1, 230, 241, 70, 246,
      243, 121, 174, 67, 66, 11, 99, 202, 17, 52, 234, 78, 29, 3, 57, 51, 123, 149, 86, 64, 192, 73, 199, 108, 101, 55,
      232, 41, 114, 153, 237, 253, 52, 205, 148, 45, 86, 186, 241, 182, 183, 42, 77, 252, 195, 29, 158, 173, 3, 182,
      207, 254, 61, 71, 184, 167, 184]);
  let keyPair = await genKeyPairByData(pkData, skData);
  // The data is signData.data in Sign().
  let signMessageBlob: cryptoFramework.DataBlob = {
    data: new Uint8Array([9, 68, 164, 161, 230, 155, 255, 153, 10, 12, 14, 22, 146, 115, 209, 167, 223, 133, 89, 173,
      50, 249, 176, 104, 10, 251, 219, 104, 117, 196, 105, 65, 249, 139, 119, 41, 15, 171, 191, 11, 177, 177, 1, 119,
      130, 142, 87, 183, 32, 220, 226, 28, 38, 73, 222, 172, 153, 26, 87, 58, 188, 42, 150, 67, 94, 214, 147, 64, 202,
      87, 155, 125, 254, 112, 95, 176, 255, 207, 106, 43, 228, 153, 131, 240, 120, 88, 253, 179, 207, 207, 110, 223,
      173, 15, 113, 11, 183, 122, 237, 205, 206, 123, 246, 33, 167, 169, 251, 237, 199, 26, 220, 152, 190, 117, 131, 74,
      232, 50, 39, 172, 232, 178, 112, 73, 251, 235, 131, 209])
  };
  let verifier = cryptoFramework.createVerify('RSA1024|PKCS1|SHA256|Recover');
  await verifier.init(keyPair.pubKey);
  try {
    let rawSignData = await verifier.recover(signMessageBlob);
    if (rawSignData != null) {
      console.info('[Promise]: recover result: ' + rawSignData.data);
    } else {
      console.error('[Promise]: get verify recover result: fail.');
    }
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    console.error(`promise failed: errCode: ${e.code}, errMsg: ${e.message}`);
  }
}
```

### recoverSync<sup>12+</sup>

recoverSync(signatureData: DataBlob): DataBlob | null

Recovers the original data from a signature. This API returns the result synchronously.

> **NOTE**
>
> - Currently, only RSA is supported.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Signature

**Parameters**

| Name       | Type    | Mandatory| Description      |
| ------------- | -------- | ---- | ---------- |
| signatureData | [DataBlob](#datablob)  | Yes  | Signature data. |

**Return value**

| Type             | Description                          |
| ----------------- | ------------------------------ |
| [DataBlob](#datablob)  \| null | Data restored.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | Memory operation failed.          |
| 17620002 | Failed to obtain the native object or convert parameters.         |
| 17620004 | Invalid function call. <br>Applicable versions: 26.0.0+|
| 17630001 | Crypto operation error. |

### setVerifySpec<sup>10+</sup>

setVerifySpec(itemType: SignSpecItem, itemValue: number): void

Sets signature verification specifications. You can use this API to set signature verification parameters that cannot be set by [createVerify](#cryptoframeworkcreateverify).

Currently, only RSA and SM2 are supported. Since API version 11, SM2 signature verification parameters can be set.

The parameters for signature verification must be the same as those for signing.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Signature
- API versions 10 to 11: SystemCapability.Security.CryptoFramework

**Parameters**

| Name  | Type                | Mandatory| Description      |
| -------- | -------------------- | ---- | ---------- |
| itemType     | [SignSpecItem](#signspecitem10)              | Yes  | Signature verification parameter to set.|
| itemValue | number | Yes  | Value of the signature verification parameter to set.|

**Error codes**

For details about the error codes,see [Universal Error Codes](../errorcode-universal.md) and [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 801 | This operation is not supported.          |
| 17620001 | Memory operation failed.          |
| 17620003 | Parameter check failed. <br>Applicable versions: 26.0.0+|
| 17630001 | Crypto operation error. |

### setVerifySpec<sup>11+</sup>

setVerifySpec(itemType: SignSpecItem, itemValue: number \| Uint8Array): void

Sets signature verification specifications. You can use this API to set signature verification parameters that cannot be set by [createVerify](#cryptoframeworkcreateverify).

Currently, only RSA and SM2 are supported. Since API version 11, SM2 signature verification parameters can be set.

The parameters for signature verification must be the same as those for signing.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Signature
- API version 11: SystemCapability.Security.CryptoFramework

**Parameters**

| Name  | Type                | Mandatory| Description      |
| -------- | -------------------- | ---- | ---------- |
| itemType     | [SignSpecItem](#signspecitem10)              | Yes  | Signature verification parameter to set.|
| itemValue | number \| Uint8Array<sup>11+</sup> | Yes  | Value of the signature verification parameter to set.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 801 | This operation is not supported.          |
| 17620001 | Memory operation failed.          |
| 17630001 | Crypto operation error. |
| 17620002 | Failed to obtain the native object or convert parameters. <br>Applicable versions: 26.0.0+|
| 17620003 | Parameter check failed. <br>Applicable versions: 26.0.0+|
| 17620004 | Invalid function call. <br>Applicable versions: 26.0.0+|

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';

function testSetVerifySpec() {
  let verifier = cryptoFramework.createVerify('RSA2048|PSS|SHA256|MGF1_SHA256');
  let setN = 20;
  verifier.setVerifySpec(cryptoFramework.SignSpecItem.PSS_SALT_LEN_NUM, setN);
}
```

### setVerifySpec

setVerifySpec(itemType: SignSpecItem, itemValue: number \| Uint8Array \| boolean): void

Sets signature verification specifications. String parameters of the signature verification algorithm are specified using [createVerify](#cryptoframeworkcreateverify). The ML-DSA parameters are set using this API, including whether to use external mu pre-hashing and the context string.

The parameters for signature verification must be the same as those for signing.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.Security.CryptoFramework.Signature

**Parameters**

| Name  | Type                | Mandatory| Description      |
| -------- | -------------------- | ---- | ---------- |
| itemType     | [SignSpecItem](#signspecitem10)              | Yes  | Signature verification parameter to set.|
| itemValue | number \| Uint8Array \| boolean | Yes  | Value of the signature verification parameter to set. For details about the parameters, see [SignSpecItem](#signspecitem10).|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 801 | This operation is not supported. |
| 17620001 | Memory operation failed. |
| 17620002 | Failed to obtain the native object or convert parameters. |
| 17620003 | Parameter check failed. |
| 17620004 | Invalid function call. |
| 17630001 | Crypto operation error. |

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';

function testSetVerifySpec() {
  let verifier = cryptoFramework.createVerify('ML-DSA');
  verifier.setVerifySpec(cryptoFramework.SignSpecItem.ML_DSA_MU_BOOL, false);
}
```

### getVerifySpec<sup>10+</sup>

getVerifySpec(itemType: SignSpecItem): string | number

Obtains signature verification specifications. Currently, only RSA is supported.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Signature
- API versions 10 to 11: SystemCapability.Security.CryptoFramework

**Parameters**

| Name| Type    | Mandatory| Description      |
| ------ | -------- | ---- | ---------- |
| itemType   | [SignSpecItem](#signspecitem10)  | Yes  | Signature verification parameter to obtain.|

**Return value**

| Type          | Description       |
| -------------- | ----------- |
| string \| number | Returns the value of the parameter obtained.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 801 | This operation is not supported.          |
| 17620001 | Memory operation failed.          |
| 17630001 | Crypto operation error. |
| 17620003 | Parameter check failed. <br>Applicable versions: 26.0.0+|

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';

function testGetVerifySpec() {
  let verifier = cryptoFramework.createVerify('RSA2048|PSS|SHA256|MGF1_SHA256');
  let setN = 20;
  verifier.setVerifySpec(cryptoFramework.SignSpecItem.PSS_SALT_LEN_NUM, setN);
  verifier.getVerifySpec(cryptoFramework.SignSpecItem.PSS_SALT_LEN_NUM);
}
```

## cryptoFramework.createKeyAgreement

createKeyAgreement(algName: string): KeyAgreement

Creates a key agreement instance.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.KeyAgreement
- API versions 9 to 11: SystemCapability.Security.CryptoFramework

**Parameters**

| Name | Type  | Mandatory| Description                                                        |
| ------- | ------ | ---- | ------------------------------------------------------------ |
| algName | string | Yes  | Key agreement algorithm to use. In addition to ECDH, X25519 and DH are supported since API version 11.<br>For details about the supported specifications, see [Key Agreement Overview and Algorithm Specifications](../../security/CryptoArchitectureKit/crypto-key-agreement-overview.md).|

**Return value**

| Type        | Description                                      |
| ------------ | ------------------------------------------ |
| KeyAgreement | **KeyAgreement** instance of the corresponding algorithm.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 801 | This operation is not supported.          |
| 17620001 | Memory operation failed.          |

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';

let keyAgreement = cryptoFramework.createKeyAgreement('ECC256');
```

## KeyAgreement

Defines the key agreement API for generating a shared key based on an asymmetric key pair. Before calling this API, you need to construct this instance using [createKeyAgreement(algName: string): KeyAgreement](#cryptoframeworkcreatekeyagreement).

### Attributes

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.KeyAgreement
- API versions 9 to 11: SystemCapability.Security.CryptoFramework

| Name   | Type  | Read-Only| Optional| Description                        |
| ------- | ------ | ---- | ---- | ---------------------------- |
| algName | string | Yes  | No  | Name of the algorithm used for key agreement.|

### generateSecret

generateSecret(priKey: PriKey, pubKey: PubKey, callback: AsyncCallback\<DataBlob>): void

Generates a shared secret based on the given private key and public key. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.KeyAgreement
- API versions 9 to 11: SystemCapability.Security.CryptoFramework

**Parameters**

| Name  | Type                    | Mandatory| Description                  |
| -------- | ------------------------ | ---- | ---------------------- |
| priKey   | [PriKey](#prikey)        | Yes  | Private key used for key agreement.|
| pubKey   | [PubKey](#pubkey)        | Yes  | Public key used for key agreement.|
| callback | AsyncCallback\<[DataBlob](#datablob)> | Yes  | Callback used to return the key agreement result. If key agreement is successful, **err** is **undefined** and **data** is the shared key. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | Memory operation failed.          |
| 17620002 | Failed to obtain the native object or convert parameters.         |
| 17630001 | Crypto operation error. |

### generateSecret

generateSecret(priKey: PriKey, pubKey: PubKey): Promise\<DataBlob>

Generates a shared secret based on the given private key and public key. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.KeyAgreement
- API versions 9 to 11: SystemCapability.Security.CryptoFramework

**Parameters**

| Name| Type  | Mandatory| Description                  |
| ------ | ------ | ---- | ---------------------- |
| priKey | [PriKey](#prikey) | Yes  | Private key used for key agreement.|
| pubKey | [PubKey](#pubkey) | Yes  | Public key used for key agreement.|

**Return value**

| Type              | Description    |
| ------------------ | -------- |
| Promise\<[DataBlob](#datablob)> | Promise used to return the shared key of key agreement.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | Memory operation failed.          |
| 17620002 | Failed to obtain the native object or convert parameters.          |
| 17630001 | Crypto operation error. |

### generateSecretSync<sup>12+</sup>

generateSecretSync(priKey: PriKey, pubKey: PubKey): DataBlob

Generates a shared secret based on the given private key and public key. This API returns the shared secret generated synchronously.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.KeyAgreement

**Parameters**

| Name| Type  | Mandatory| Description                  |
| ------ | ------ | ---- | ---------------------- |
| priKey | [PriKey](#prikey) | Yes  | Private key used for key agreement.|
| pubKey | [PubKey](#pubkey) | Yes  | Public key used for key agreement.|

**Return value**

| Type              | Description    |
| ------------------ | -------- |
|[DataBlob](#datablob) | Promise used to return the shared secret generated.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | Memory operation failed.          |
| 17620002 | Failed to obtain the native object or convert parameters.         |
| 17630001 | Crypto operation error. |

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';

async function testGenerateSecret() {
  let eccGen = cryptoFramework.createAsyKeyGenerator('ECC256');
  let globalKeyPair = await eccGen.generateKeyPair();
  let keyAgreement = cryptoFramework.createKeyAgreement('ECC256');
  keyAgreement.generateSecret(globalKeyPair.priKey, globalKeyPair.pubKey, (err, secret) => {
    if (err) {
      console.error(`keyAgreement failed, errCode: ${err.code}, errMsg: ${err.message}`);
      return;
    }
    console.info('keyAgreement output = ' + secret.data);
  });
}
```

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function testGenerateSecret() {
  let eccGen = cryptoFramework.createAsyKeyGenerator('ECC256');
  let globalKeyPair = await eccGen.generateKeyPair();
  let keyAgreement = cryptoFramework.createKeyAgreement('ECC256');
  let keyAgreementPromise = keyAgreement.generateSecret(globalKeyPair.priKey, globalKeyPair.pubKey);
  keyAgreementPromise.then(secret => {
    console.info('keyAgreement output = ' + secret.data);
  }).catch((error: BusinessError) => {
    console.error(`keyAgreement failed: errCode: ${error.code}, errMsg: ${error.message}`);
  });
}
```

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';

async function testGenerateSecretSync() {
  let eccGen = cryptoFramework.createAsyKeyGenerator('ECC256');
  let globalKeyPair = await eccGen.generateKeyPair();
  let keyAgreement = cryptoFramework.createKeyAgreement('ECC256');
  let secret = keyAgreement.generateSecretSync(globalKeyPair.priKey, globalKeyPair.pubKey);
  console.info('[Sync]keyAgreement output = ' + secret.data);
}
```

## cryptoFramework.createMd

createMd(algName: string): Md

Creates an MD instance.

For details about the supported specifications, see [Supported Algorithms and Specifications](../../security/CryptoArchitectureKit/crypto-generate-message-digest-overview.md#supported-algorithms-and-specifications).

**Atomic service API**: This API can be used in atomic services since API version 12.

**Model restriction**:
- API version 12+: This API can be used in both the stage and FA models.
- API versions 9 to 11: This API can be used only in the stage model.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.MessageDigest
- API versions 9 to 11: SystemCapability.Security.CryptoFramework

**Parameters**

| Name | Type  | Mandatory| Description                                                        |
| ------- | ------ | ---- | ------------------------------------------------------------ |
| algName | string | Yes  | MD algorithm to use. For details about the supported algorithms, see [Supported Algorithms and Specifications](../../security/CryptoArchitectureKit/crypto-generate-message-digest-overview.md#supported-algorithms-and-specifications).|

**Return value**

| Type| Description                                   |
| ---- | --------------------------------------- |
| [Md](#md)  | **Md** instance of the corresponding algorithm.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message          |
| -------- | ------------------ |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | Memory operation failed.       |

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let md = cryptoFramework.createMd('SHA256');
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`sync failed: errCode: ${e.code}, errMsg: ${e.message}`);
}
```

## Md

Defines the MD API for calculating the message digest. Before calling this API, you need to create an **Md** instance by calling [createMd](#cryptoframeworkcreatemd).

### Attributes

**Atomic service API**: This API can be used in atomic services since API version 12.

**Model restriction**: This API can be used only in the stage model.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.MessageDigest
- API versions 9 to 11: SystemCapability.Security.CryptoFramework

| Name   | Type  | Read-Only| Optional| Description                  |
| ------- | ------ | ---- | ---- | ---------------------- |
| algName | string | Yes  | No  | Digest algorithm.|

### update

update(input: DataBlob, callback: AsyncCallback\<void>): void

Updates the MD status. This API uses an asynchronous callback to return the result. **update** must be used with **digest** together. **digest** is mandatory, and **update** is optional.

> **NOTE**
>
> For details about the code for calling **update** multiple times in an MD operation, see [Generating an MD by Passing In Data by Segment](../../security/CryptoArchitectureKit/crypto-generate-message-digest.md#generating-an-md-by-passing-in-data-by-segment).

**Atomic service API**: This API can be used in atomic services since API version 12.

**Model restriction**:
- API version 12+: This API can be used in both the stage and FA models.
- API versions 9 to 11: This API can be used only in the stage model.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.MessageDigest
- API versions 9 to 11: SystemCapability.Security.CryptoFramework

**Parameters**

| Name  | Type                 | Mandatory| Description        |
| -------- | --------------------- | ---- | ------------ |
| input    | [DataBlob](#datablob) | Yes  | Data to pass in.|
| callback | AsyncCallback\<void>  | Yes  | Callback used to return the result. If the MD status update is successful, **err** is **undefined**. Otherwise, **err** is an error object. |

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001| Memory operation failed. |
| 17630001 | Crypto operation error. |

### update

update(input: DataBlob): Promise\<void>

Updates the MD status. This API uses a promise to return the result. **update** must be used with **digest** together. **digest** is mandatory, and **update** is optional.

> **NOTE**
>
> For details about the code for calling **update** multiple times in an MD operation, see [Generating an MD by Passing In Data by Segment](../../security/CryptoArchitectureKit/crypto-generate-message-digest.md#generating-an-md-by-passing-in-data-by-segment).

**Atomic service API**: This API can be used in atomic services since API version 12.

**Model restriction**: This API can be used only in the stage model.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.MessageDigest
- API versions 9 to 11: SystemCapability.Security.CryptoFramework

**Differentiated device support**: This API runs properly on phones, PCs/2-in-1 devices, tablets, TVs, and wearables. However, if it is called on a lite wearable, **undefined** is returned.

**Parameters**

| Name| Type    | Mandatory| Description        |
| ------ | -------- | ---- | ------------ |
| input  | [DataBlob](#datablob) | Yes  | Data to pass in.|

**Return value**

| Type          | Description         |
| -------------- | ------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001| Memory operation failed. |
| 17630001 | Crypto operation error. |

### updateSync<sup>12+</sup>

updateSync(input: DataBlob): void

Updates the MD digest status. This API returns the result synchronously. **updateSync** must be used with **digestSync** together. **digestSync** is mandatory, and **updateSync** is optional.

> **NOTE**
>
> For details about the code for calling **updateSync** multiple times in an MD operation, see [Generating an MD by Passing In Data by Segment](../../security/CryptoArchitectureKit/crypto-generate-message-digest.md#generating-an-md-by-passing-in-data-by-segment).

**Atomic service API**: This API can be used in atomic services since API version 12.

**Model restriction**: This API can be used in both the stage and FA models.

**System capability**: SystemCapability.Security.CryptoFramework.MessageDigest

**Parameters**

| Name| Type    | Mandatory| Description        |
| ------ | -------- | ---- | ------------ |
| input  | [DataBlob](#datablob) | Yes  | Data to pass in.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.      |
| 17620001| Memory operation failed. |
| 17630001 | Crypto operation error. |

### digest

digest(callback: AsyncCallback\<DataBlob>): void

Generates a message digest (MD). This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**Model restriction**:
- API version 12+: This API can be used in both the stage and FA models.
- API versions 9 to 11: This API can be used only in the stage model.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.MessageDigest
- API versions 9 to 11: SystemCapability.Security.CryptoFramework

**Parameters**

| Name  | Type                    | Mandatory| Description      |
| -------- | ------------------------ | ---- | ---------- |
| callback | AsyncCallback\<[DataBlob](#datablob)> | Yes  | Callback used to return the MD generated. If the MD calculation is successful, **err** is **undefined**, and **data** is the MD obtained. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).


| ID| Error Message              |
| -------- | ---------------------- |
| 17620001 | Memory operation failed.           |
| 17630001 | Crypto operation error. |

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { buffer } from '@kit.ArkTS';

function mdByCallback() {
  let md = cryptoFramework.createMd('SHA256');
  md.update({ data: new Uint8Array(buffer.from('mdTestMessage', 'utf-8').buffer) }, (err) => {
    md.digest((err, digestOutput) => {
      console.info('[Callback]: MD result: ' + digestOutput.data);
      console.info('[Callback]: MD len: ' + md.getMdLength());
    });
  });
}
```

### digest

digest(): Promise\<DataBlob>

Generates an MD. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**Model restriction**: This API can be used only in the stage model.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.MessageDigest
- API versions 9 to 11: SystemCapability.Security.CryptoFramework

**Differentiated device support**: This API runs properly on phones, PCs/2-in-1 devices, tablets, TVs, and wearables. However, if it is called on a lite wearable, **undefined** is returned.

**Return value**

| Type              | Description       |
| ------------------ | ----------- |
| Promise\<[DataBlob](#datablob)> | Promise used to return the MD generated.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 17620001 | Memory operation failed.           |
| 17630001 | Crypto operation error. |

**Example**

ArkTS example:

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { buffer } from '@kit.ArkTS';

async function mdByPromise() {
  let md = cryptoFramework.createMd('SHA256');
  await md.update({ data: new Uint8Array(buffer.from('mdTestMessage', 'utf-8').buffer) });
  let mdOutput = await md.digest();
  console.info('[Promise]: MD result: ' + mdOutput.data);
  console.info('[Promise]: MD len: ' + md.getMdLength());
}
```

JS example:

```xml
<div class="container">
    <text class="TestTitle">Crypto test</text>
    <input class="btn" @click="MdTest">Md asynchronous test</input>
</div>
```

```css
.container {
  width: 100%;
  height: 2000px;
  align-items: center;
  background-color: #fffefcfc;
  flex-direction: column;
  display: flex;
}

.TestTitle {
  width: 300px;
  height: 80px;
  text-align: center;
  background-color: white;
  color: #fff61515;
  font-size: 15fp;
}

.btn {
  width: 90%;
  height: 80px;
  text-align: center;
  background-color: #fff17f04;
  margin-top: 3px;
  color: white;
  font-size: 20fp;
}
```

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

function StringToUint8Array(str) {
    let arr = [];
    for (let i = 0, j = str.length; i < j; ++i) {
        arr.push(str.charCodeAt(i));
    }
    return new Uint8Array(arr);
}

let plainText = "123456";

function mdTest() {
    let inData = StringToUint8Array(plainText);
    let md = cryptoFramework.createMd('SHA256');
    console.info('createMd ' + typeof md);

    md.update({data: inData}, function (finishErr) {
        if (finishErr) {
            console.error('Digest update failed. Code: ' + finishErr.code + " : " + finishErr.message);
        } else {
            console.info('Digest update successfully.');
        }
    })

    md.digest(function (finishErr, digestOutput){
        if (finishErr) {
            console.error('Digest failed. Code: ' + finishErr.code + " : " + finishErr.message);
        } else {
            console.info('Digest successfully:' + digestOutput);
        }
    })
}

export default {
    data: {
        result: ''
    },
    MdTest() {
        mdTest();
    }
};
```

### digestSync<sup>12+</sup>

digestSync(): DataBlob

Generates an MD. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 12.

**Model restriction**: This API can be used in both the stage and FA models.

**System capability**: SystemCapability.Security.CryptoFramework.MessageDigest

**Return value**

| Type              | Description       |
| ------------------ | ----------- |
| [DataBlob](#datablob) | MD generated.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.         |
| 17620001 | Memory operation failed. |
| 17620002 | Failed to obtain the native object or convert parameters. |
| 17630001 | Crypto operation error. |

**Example**

ArkTS example:

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { buffer } from '@kit.ArkTS';

function mdBySync() {
  let md = cryptoFramework.createMd('SHA256');
  md.updateSync({ data: new Uint8Array(buffer.from('mdTestMessage', 'utf-8').buffer) });
  let mdOutput = md.digestSync();
  console.info('[Sync]: MD result: ' + mdOutput.data);
  console.info('[Sync]: MD len: ' + md.getMdLength());
}
```

JS example:

```xml
<div class="container">
    <text class="TestTitle">Crypto test</text>
    <input class="btn" @click="MdTestSync">Md synchronous test</input>
</div>
```

```css
.container {
  width: 100%;
  height: 2000px;
  align-items: center;
  background-color: #fffefcfc;
  flex-direction: column;
  display: flex;
}

.TestTitle {
  width: 300px;
  height: 80px;
  text-align: center;
  background-color: white;
  color: #fff61515;
  font-size: 15fp;
}

.btn {
  width: 90%;
  height: 80px;
  text-align: center;
  background-color: #fff17f04;
  margin-top: 3px;
  color: white;
  font-size: 20fp;
}
```

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

function StringToUint8Array(str) {
    let arr = [];
    for (let i = 0, j = str.length; i < j; ++i) {
        arr.push(str.charCodeAt(i));
    }
    return new Uint8Array(arr);
}

function mdTestSync() {
    let mdAlgName = 'SHA256';
    let message = 'mdTestMessage';
    let md = cryptoFramework.createMd(mdAlgName);
    md.updateSync({ data: StringToUint8Array(message) });
    let mdResult = md.digestSync();
    console.info('Digest successfully. result:' + mdResult.data);
    let mdLen = md.getMdLength();
    console.info('Digest successfully. md len: ' + mdLen);
}

export default {
    data: {
        result: ''
    },
    MdTestSync() {
        mdTestSync();
    }
};
```

### getMdLength

getMdLength(): number

Obtains the MD length, in bytes.

**Atomic service API**: This API can be used in atomic services since API version 12.

**Model restriction**:
- API version 12+: This API can be used in both the stage and FA models.
- API versions 9 to 11: This API can be used only in the stage model.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.MessageDigest
- API versions 9 to 11: SystemCapability.Security.CryptoFramework

**Return value**

| Type  | Description                      |
| ------ | -------------------------- |
| number | MD length obtained.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 17630001 | Crypto operation error. |

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';

function getLength() {
  let md = cryptoFramework.createMd('SHA256');
  console.info('[Promise]: MD len: ' + md.getMdLength());
}
```

## cryptoFramework.createMac

createMac(algName: string): Mac

Creates a MAC instance.

For details about the supported specifications, see [MAC Overview and Algorithm Specifications](../../security/CryptoArchitectureKit/crypto-compute-mac-overview.md).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Mac
- API versions 9 to 11: SystemCapability.Security.CryptoFramework

**Parameters**

| Name | Type  | Mandatory| Description                                                        |
| ------- | ------ | ---- | ------------------------------------------------------------ |
| algName | string | Yes  | Specifies the digest algorithm. For details about the supported algorithms, see [MAC Overview and Algorithm Specifications](../../security/CryptoArchitectureKit/crypto-compute-mac-overview.md).|

**Return value**

| Type| Description                                     |
| ---- | ----------------------------------------- |
| [Mac](#mac) | **Mac** instance of the corresponding algorithm.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message          |
| -------- | ------------------ |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | Memory operation failed.       |

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  // Set algName based on the algorithm supported.
  let mac = cryptoFramework.createMac('SHA256');
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`sync failed: errCode: ${e.code}, errMsg: ${e.message}`);
}
```

## cryptoFramework.createMac<sup>18+</sup>

createMac(macSpec: MacSpec): Mac

Creates a MAC instance.

For details about the supported specifications, see [MAC Overview and Algorithm Specifications](../../security/CryptoArchitectureKit/crypto-compute-mac-overview.md).

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Security.CryptoFramework.Mac

**Parameters**

| Name | Type  | Mandatory| Description                                                        |
| ------- | ------ | ---- | ------------------------------------------------------------ |
| macSpec | [MacSpec](#macspec18) | Yes  | Specifies the input parameters based on the MAC algorithm. For details about the supported algorithms, see [MAC Overview and Algorithm Specifications](../../security/CryptoArchitectureKit/crypto-compute-mac-overview.md).|

**Return value**

| Type| Description                                     |
| ---- | ----------------------------------------- |
| [Mac](#mac)  | **Mac** instance of the corresponding algorithm.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message          |
| -------- | ------------------ |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | Memory operation failed.       |
| 17620002 | Failed to obtain the native object or convert parameters.      |
| 17630001 | Crypto operation error.       |

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  // Set algName based on the algorithm supported.
  let spec: cryptoFramework.HmacSpec = {
    algName: 'HMAC',
    mdName: 'SHA256',
  };
  let mac = cryptoFramework.createMac(spec);
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`sync failed: errCode: ${error.code}, errMsg: ${error.message}`);
}
```

## Mac

Defines the MAC API for calculating the message authentication code based on the symmetric key. Before calling this API, you need to create a **Mac** instance by calling [createMac](#cryptoframeworkcreatemac).

### Attributes

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Mac
- API versions 9 to 11: SystemCapability.Security.CryptoFramework

| Name   | Type  | Read-Only| Optional| Description                  |
| ------- | ------ | ---- | ---- | ---------------------- |
| algName | string | Yes  | No  | Digest algorithm.|

### init

init(key: SymKey, callback: AsyncCallback\<void>): void

Initializes the MAC computation using a symmetric key. This API uses an asynchronous callback to return the result. **init**, **update**, and **doFinal** must be used together. **init** and **doFinal** are mandatory, and **update** is optional.

  > **NOTE**
  >
  > You are advised to create a symmetric key generator based on the [HMAC key generation specifications](../../security/CryptoArchitectureKit/crypto-sym-key-generation-conversion-spec.md#hmac) and use [generateSymKey](#generatesymkey) to randomly generate a symmetric key or use [convertKey](#convertkey) to convert the binary data (whose length is the same as the key specifications) into a key.<br>If **HMAC** is specified to generate the symmetric key generator, only [convertKey](#convertkey) can be called to pass in a binary key of 1 to 4,096 bytes.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Mac
- API versions 9 to 11: SystemCapability.Security.CryptoFramework

**Parameters**

| Name  | Type                | Mandatory| Description          |
| -------- | -------------------- | ---- | -------------- |
| key      | [SymKey](#symkey)    | Yes  | Symmetric key obtained.|
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. If the HMAC initialization is successful, **err** is **undefined**. Otherwise, **err** is an error object. |

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001| Memory operation failed. |
| 17630001 | Crypto operation error. |

### init

init(key: SymKey): Promise\<void>

Initializes the MAC computation using a symmetric key. This API uses a promise to return the result. **init**, **update**, and **doFinal** must be used together. **init** and **doFinal** are mandatory, and **update** is optional.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Mac
- API versions 9 to 11: SystemCapability.Security.CryptoFramework

**Parameters**

| Name| Type  | Mandatory| Description        |
| ------ | ------ | ---- | ------------ |
| key    | [SymKey](#symkey) | Yes  | Symmetric key obtained.|

**Return value**

| Type          | Description         |
| -------------- | ------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001| Memory operation failed. |
| 17630001 | Crypto operation error. |

### initSync<sup>12+</sup>

initSync(key: SymKey): void

Initializes the MAC computation using a symmetric key. This API returns the result synchronously. **initSync**, **updateSync**, and **doFinalSync** must be used together. **initSync** and **doFinalSync** are mandatory, and **updateSync** is optional.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Mac

**Parameters**

| Name| Type  | Mandatory| Description        |
| ------ | ------ | ---- | ------------ |
| key    | [SymKey](#symkey) | Yes  | Symmetric key obtained.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.     |
| 17620001| Memory operation failed. |
| 17630001 | Crypto operation error. |

### update

update(input: DataBlob, callback: AsyncCallback\<void>): void

Updates the MAC status. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> For details about the sample code for calling **update** multiple times in an HMAC operation, see [Generating an HMAC by Passing In Data by Segment](../../security/CryptoArchitectureKit/crypto-compute-hmac.md#generating-an-hmac-by-passing-in-data-by-segment).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Mac
- API versions 9 to 11: SystemCapability.Security.CryptoFramework

**Parameters**

| Name  | Type                 | Mandatory| Description        |
| -------- | --------------------- | ---- | ------------ |
| input    | [DataBlob](#datablob) | Yes  | Data to pass in.|
| callback | AsyncCallback\<void>  | Yes  | Callback used to return the result. If the HMAC update is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001| Memory operation failed. |
| 17630001 | Crypto operation error. |

### update

update(input: DataBlob): Promise\<void>

Updates the MAC status. This API uses a promise to return the result.

> **NOTE**
>
> For details about the sample code for calling **update** multiple times in an HMAC operation, see [Generating an HMAC by Passing In Data by Segment](../../security/CryptoArchitectureKit/crypto-compute-hmac.md#generating-an-hmac-by-passing-in-data-by-segment).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Mac
- API versions 9 to 11: SystemCapability.Security.CryptoFramework

**Parameters**

| Name| Type    | Mandatory| Description      |
| ------ | -------- | ---- | ---------- |
| input  | [DataBlob](#datablob) | Yes  | Data to pass in.|

**Return value**

| Type          | Description         |
| -------------- | ------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001| Memory operation failed. |
| 17630001 | Crypto operation error. |

### updateSync<sup>12+</sup>

updateSync(input: DataBlob): void

Updates the MAC status. This API returns the result synchronously.

> **NOTE**
>
> For details about the sample code for calling **updateSync** multiple times in an HMAC operation, see [Generating an HMAC by Passing In Data by Segment](../../security/CryptoArchitectureKit/crypto-compute-hmac.md#generating-an-hmac-by-passing-in-data-by-segment).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Mac

**Parameters**

| Name| Type    | Mandatory| Description      |
| ------ | -------- | ---- | ---------- |
| input  | [DataBlob](#datablob) | Yes  | Data to pass in.|


**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.      |
| 17620001| Memory operation failed. |
| 17630001 | Crypto operation error. |

### doFinal

doFinal(callback: AsyncCallback\<DataBlob>): void

Finalizes MAC calculation and obtains the result. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Mac
- API versions 9 to 11: SystemCapability.Security.CryptoFramework

**Parameters**

| Name  | Type                    | Mandatory| Description    |
| -------- | ------------------------ | ---- | -------- |
| callback | AsyncCallback\<[DataBlob](#datablob)> | Yes  | Callback used to return the MAC computation result. If the MAC calculation is successful, **err** is **undefined**, and **data** is the MAC calculation result. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 17620001 | Memory operation failed.           |
| 17630001 | Crypto operation error. |

**Example**

For more HMAC operation examples, see [Generating an HMAC by Passing In Data by Segment](../../security/CryptoArchitectureKit/crypto-compute-hmac.md#generating-an-hmac-by-passing-in-data-by-segment).

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { buffer } from '@kit.ArkTS';

function hmacByCallback() {
  let mac = cryptoFramework.createMac('SHA256');
  let keyBlob: cryptoFramework.DataBlob = { data: new Uint8Array(buffer.from('12345678abcdefgh', 'utf-8').buffer) };
  let symKeyGenerator = cryptoFramework.createSymKeyGenerator('AES128');
  symKeyGenerator.convertKey(keyBlob, (err, symKey) => {
    mac.init(symKey, (err) => {
      mac.update({ data: new Uint8Array(buffer.from('hmacTestMessage', 'utf-8').buffer) }, (err) => {
        mac.doFinal((err, output) => {
          console.info('[Callback]: HMAC result: ' + output.data);
          console.info('[Callback]: MAC len: ' + mac.getMacLength());
        });
      });
    });
  });
}
```

### doFinal

doFinal(): Promise\<DataBlob>

Finalizes MAC calculation and obtains the result. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Mac
- API versions 9 to 11: SystemCapability.Security.CryptoFramework

**Return value**

| Type              | Description       |
| ------------------ | ----------- |
| Promise\<[DataBlob](#datablob)> | Promise used to return the MAC calculation result.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 17620001 | Memory operation failed.           |
| 17630001 | Crypto operation error. |

**Example**

For more HMAC operation examples, see [Generating an HMAC by Passing In Data by Segment](../../security/CryptoArchitectureKit/crypto-compute-hmac.md#generating-an-hmac-by-passing-in-data-by-segment).

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { buffer } from '@kit.ArkTS';

async function hmacByPromise() {
  let mac = cryptoFramework.createMac('SHA256');
  let keyBlob: cryptoFramework.DataBlob = { data: new Uint8Array(buffer.from('12345678abcdefgh', 'utf-8').buffer) };
  let symKeyGenerator = cryptoFramework.createSymKeyGenerator('AES128');
  let symKey = await symKeyGenerator.convertKey(keyBlob);
  await mac.init(symKey);
  await mac.update({ data: new Uint8Array(buffer.from('hmacTestMessage', 'utf-8').buffer) });
  let macOutput = await mac.doFinal();
  console.info('[Promise]: HMAC result: ' + macOutput.data);
  console.info('[Promise]: MAC len: ' + mac.getMacLength());
}
```

### doFinalSync<sup>12+</sup>

doFinalSync(): DataBlob

Finalizes MAC calculation and obtains the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Mac

**Return value**

| Type              | Description       |
| ------------------ | ----------- |
| [DataBlob](#datablob) | MAC calculation result.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.          |
| 17620001 | Memory operation failed.           |
| 17620002 | Failed to obtain the native object or convert parameters. |
| 17630001 | Crypto operation error. |

**Example**

For more HMAC operation examples, see [Generating an HMAC by Passing In Data by Segment](../../security/CryptoArchitectureKit/crypto-compute-hmac.md#generating-an-hmac-by-passing-in-data-by-segment).

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { buffer } from '@kit.ArkTS';

function hmacBySync() {
  let mac = cryptoFramework.createMac('SHA256');
  let keyBlob: cryptoFramework.DataBlob = { data: new Uint8Array(buffer.from('12345678abcdefgh', 'utf-8').buffer) };
  let symKeyGenerator = cryptoFramework.createSymKeyGenerator('AES128');
  let symKey = symKeyGenerator.convertKeySync(keyBlob);
  mac.initSync(symKey);
  mac.updateSync({ data: new Uint8Array(buffer.from('hmacTestMessage', 'utf-8').buffer) });
  let macOutput = mac.doFinalSync();
  console.info('[Sync]: HMAC result: ' + macOutput.data);
  console.info('[Sync]: MAC len: ' + mac.getMacLength());
}
```

### getMacLength

getMacLength(): number

Obtains the MAC length, in bytes.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Mac
- API versions 9 to 11: SystemCapability.Security.CryptoFramework

**Return value**

| Type  | Description                       |
| ------ | --------------------------- |
| number | MAC length obtained.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 17630001 | Crypto operation error. |

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { BusinessError } from '@kit.BasicServicesKit';

function testGetMacLength() {
  let mac = cryptoFramework.createMac('SHA256');
  console.info('Mac algName is: ' + mac.algName);
  let keyData = new Uint8Array([83, 217, 231, 76, 28, 113, 23, 219, 250, 71, 209, 210, 205, 97, 32, 159]);
  let keyBlob: cryptoFramework.DataBlob = { data: keyData };
  let symKeyGenerator = cryptoFramework.createSymKeyGenerator('AES128');
  let promiseConvertKey = symKeyGenerator.convertKey(keyBlob);
  promiseConvertKey.then(symKey => {
    let promiseMacInit = mac.init(symKey);
    return promiseMacInit;
  })
    .then(() => {
      let blob: cryptoFramework.DataBlob = { data: new Uint8Array([83]) };
      let promiseMacUpdate = mac.update(blob);
      return promiseMacUpdate;
    })
    .then(() => {
      let promiseMacDoFinal = mac.doFinal();
      return promiseMacDoFinal;
    })
    .then(macOutput => {
      console.info('[Promise]: HMAC result: ' + macOutput.data);
      let macLen = mac.getMacLength();
      console.info('MAC len: ' + macLen);
    })
    .catch((error: BusinessError) => {
      console.error(`[Promise] failed: errCode: ${error.code}, errMsg: ${error.message}`);
    });
}
```

## cryptoFramework.createRandom

createRandom(): Random

Creates a random number instance.

**Atomic service API**: This API can be used in atomic services since API version 11.

**Model restriction**:
- API version 12+: This API can be used in both the stage and FA models.
- API versions 9 to 11: This API can be used only in the stage model.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Rand
- API versions 9 to 11: SystemCapability.Security.CryptoFramework

**Return value**

| Type  | Description                                           |
| ------ | ----------------------------------------------- |
| [Random](#random) | **Random** instance.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message    |
| -------- | ------------ |
| 17620001 | Memory operation failed. |

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let rand = cryptoFramework.createRandom();
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`sync failed: errCode: ${e.code}, errMsg: ${e.message}`);
}
```

## Random

Defines an API for generating random numbers. Before calling this API, you need to create a **Random** instance by calling [createRandom](#cryptoframeworkcreaterandom).

### Attributes

**Atomic service API**: This API can be used in atomic services since API version 11.

**Model restriction**: This API can be used only in the stage model.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Rand
- API versions 10 to 11: SystemCapability.Security.CryptoFramework

| Name   | Type  | Read-Only| Optional| Description                |
| ------- | ------ | ---- | ---- | -------------------- |
| algName<sup>10+</sup> | string | Yes  | No  | Algorithm used to generate the random number. Currently, only **CTR_DRBG** is supported.|

### generateRandom

generateRandom(len: number, callback: AsyncCallback\<DataBlob>): void

Generates a random number of the specified length. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**Model restriction**:
- API version 12+: This API can be used in both the stage and FA models.
- API versions 9 to 11: This API can be used only in the stage model.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Rand
- API versions 9 to 11: SystemCapability.Security.CryptoFramework

**Parameters**

| Name  | Type                    | Mandatory| Description                |
| -------- | ------------------------ | ---- | -------------------- |
| len      | number                   | Yes  | Length of the random number to generate, in bytes. The value ranges from 1 to **INT_MAX**.|
| callback | AsyncCallback\<[DataBlob](#datablob)> | Yes  | Callback used to return the random number generated. If a random number is successfully generated, **err** is **undefined** and **data** is the random number generated. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | Memory operation failed.          |
| 17630001 | Crypto operation error. |

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';

let rand = cryptoFramework.createRandom();
rand.generateRandom(12, (err, randData) => {
  if (err) {
    console.error(`[Callback] generate random failed, errCode: ${err.code}, errMsg: ${err.message}`);
  } else {
    console.info('[Callback]: generate random result: ' + randData.data);
  }
});
```

### generateRandom

generateRandom(len: number): Promise\<DataBlob>

Generates a random number of the specified length. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**Model restriction**: This API can be used only in the stage model.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Rand
- API versions 9 to 11: SystemCapability.Security.CryptoFramework

**Differentiated device support**: This API runs properly on phones, PCs/2-in-1 devices, tablets, TVs, and wearables. However, if it is called on a lite wearable, **undefined** is returned.

**Parameters**

| Name| Type  | Mandatory| Description                                                  |
| ------ | ------ | ---- | ------------------------------------------------------ |
| len    | number | Yes  | Length of the random number to generate, in bytes. The value ranges from 1 to **INT_MAX**.|

**Return value**

| Type              | Description       |
| ------------------ | ----------- |
| Promise\<[DataBlob](#datablob)> | Promise used to return the random number generated.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | Memory operation failed.           |
| 17630001 | Crypto operation error. |

**Example**

ArkTS example:

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { BusinessError } from '@kit.BasicServicesKit';

let rand = cryptoFramework.createRandom();
let promiseGenerateRand = rand.generateRandom(12);
promiseGenerateRand.then(randData => {
  console.info('[Promise]: rand result: ' + randData.data);
}).catch((error: BusinessError) => {
  console.error(`[Promise] failed: errCode: ${error.code}, errMsg: ${error.message}`);
});
```

JS example:

```xml
<div class="container">
    <text class="TestTitle">Crypto test</text>
    <input class="btn" @click="RandTest">Rand asynchronous test</input>
</div>
```

```css
.container {
  width: 100%;
  height: 2000px;
  align-items: center;
  background-color: #fffefcfc;
  flex-direction: column;
  display: flex;
}

.TestTitle {
  width: 300px;
  height: 80px;
  text-align: center;
  background-color: white;
  color: #fff61515;
  font-size: 15fp;
}

.btn {
  width: 90%;
  height: 80px;
  text-align: center;
  background-color: #fff17f04;
  margin-top: 3px;
  color: white;
  font-size: 20fp;
}
```

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

function randTest() {
    let rand = cryptoFramework.createRandom();
    let seed = new Uint8Array([1, 2, 3]);
    rand.setSeed({ data : seed });

    rand.generateRandom(12, function (finishErr, randData) {
        if (finishErr) {
            console.error('GenerateRandom failed. Code:' + finishErr.code + ' : ' + finishErr.message);
        } else {
            console.info('GenerateRandom successfully: ' + randData);
        }
    })
}

export default {
    data: {
        result: ''
    },
    RandTest() {
        randTest();
    }
};
```

### generateRandomSync<sup>10+</sup>

generateRandomSync(len: number): DataBlob

Generates a random number of the specified length. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 11.

**Model restriction**:
- API version 12+: This API can be used in both the stage and FA models.
- API versions 10 to 11: This API can be used only in the stage model.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Rand
- API versions 10 to 11: SystemCapability.Security.CryptoFramework

**Parameters**

| Name| Type  | Mandatory| Description                |
| ------ | ------ | ---- | -------------------- |
| len    | number | Yes  | Length of the random number to generate, in bytes. The value ranges from 1 to **INT_MAX**.|

**Return value**

| Type              | Description       |
| ------------------ | ----------- |
|[DataBlob](#datablob) | Returns the generated random number.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | Memory operation failed.           |
| 17630001 | Crypto operation error. |

**Example**

ArkTS example:

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { BusinessError } from '@kit.BasicServicesKit';

let rand = cryptoFramework.createRandom();
try {
  let randData = rand.generateRandomSync(12);
  if (randData != null) {
    console.info('[Sync]: rand result: ' + randData.data);
  } else {
    console.error('[Sync]: get rand result: fail.');
  }
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`sync failed: errCode: ${e.code}, errMsg: ${e.message}`);
}
```

JS example:

```xml
<div class="container">
    <text class="TestTitle">Crypto test</text>
    <input class="btn" @click="RandTestSync">Rand synchronous test</input>
</div>
```

```css
.container {
  width: 100%;
  height: 2000px;
  align-items: center;
  background-color: #fffefcfc;
  flex-direction: column;
  display: flex;
}

.TestTitle {
  width: 300px;
  height: 80px;
  text-align: center;
  background-color: white;
  color: #fff61515;
  font-size: 15fp;
}

.btn {
  width: 90%;
  height: 80px;
  text-align: center;
  background-color: #fff17f04;
  margin-top: 3px;
  color: white;
  font-size: 20fp;
}
```

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

function randTestSync() {
    let rand = cryptoFramework.createRandom();
    let randLen = 24;
    try {
        let randData = rand.generateRandomSync(randLen);
        if (randData != null) {
            console.info('GenerateRandom successfully: ' + randData.data);
        } else {
            console.error('GenerateRandom failed!');
        }
    } catch (error) {
        console.error(`GenerateRandom random number failed. Code: ${error.code}, message: ${error.message}`);
    }
}

export default {
    data: {
        result: ''
    },
    RandTestSync() {
        randTestSync();
    }
};
```

### enableHardwareEntropy<sup>21+</sup>

enableHardwareEntropy(): void

Enables the hardware entropy source. Secure random numbers obtained from the TEE are used as the entropy source of the **Random** instance.

**Atomic service API**: This API can be used in atomic services since API version 21.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Security.CryptoFramework.Rand

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message          |
| -------- | ----------------- |
| 801 | This operation is not supported.          |
| 17620001 | Memory operation failed.      |
| 17620002 | Failed to obtain the native object or convert parameters. |
| 17630001 | Crypto operation error. |

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { BusinessError } from '@kit.BasicServicesKit';

let rand = cryptoFramework.createRandom();
rand.enableHardwareEntropy();
rand.generateRandom(12, (err, randData) => {
  if (err) {
    console.error(`[Callback] generate random failed, errCode: ${err.code}, errMsg: ${err.message}`);
  } else {
    console.info('[Callback]: generate random result: ' + randData.data);
    try {
      rand.setSeed(randData);
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      console.error(`sync failed: errCode: ${e.code}, errMsg: ${e.message}`);
    }
  }
});
```

### setSeed

setSeed(seed: DataBlob): void

Sets a seed.

**Atomic service API**: This API can be used in atomic services since API version 11.

**Model restriction**:
- API version 12+: This API can be used in both the stage and FA models.
- API versions 9 to 11: This API can be used only in the stage model.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Rand
- API versions 9 to 11: SystemCapability.Security.CryptoFramework

**Parameters**

| Name| Type    | Mandatory| Description        |
| ------ | -------- | ---- | ------------ |
| seed   | [DataBlob](#datablob) | Yes  | Seed to set.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message          |
| -------- | ----------------- |
| 17620001 | Memory operation failed.      |

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { BusinessError } from '@kit.BasicServicesKit';

let rand = cryptoFramework.createRandom();
rand.generateRandom(12, (err, randData) => {
  if (err) {
    console.error(`[Callback] generate random failed, errCode: ${err.code}, errMsg: ${err.message}`);
  } else {
    console.info('[Callback]: generate random result: ' + randData.data);
    try {
      rand.setSeed(randData);
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      console.error(`sync failed: errCode: ${e.code}, errMsg: ${e.message}`);
    }
  }
});
```

## cryptoFramework.createKdf<sup>11+</sup>

createKdf(algName: string): Kdf

Creates a KDF instance.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Kdf
- API version 11: SystemCapability.Security.CryptoFramework

**Parameters**

| Name | Type  | Mandatory| Description                             |
| ------- | ------ | ---- | --------------------------------- |
| algName | string | Yes  | Key derivation algorithm (including the hash function for the HMAC). Currently, only PBKDF2, HKDF, and scrypt are supported. For example, **PBKDF2\|SHA256**, **HKDF\|SHA256**, **SCRYPT**., or **X963KDF\|SHA256**.<br>For details about the supported specifications, see [Key Derivation Overview and Algorithm Specifications](../../security/CryptoArchitectureKit/crypto-key-derivation-overview.md).|

**Return value**

| Type        | Description                                      |
| ------------ | ------------------------------------------ |
| [Kdf](#kdf11) | **Kdf** instance of the corresponding algorithm.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 801 | This operation is not supported.          |
| 17620001 | Memory operation failed.          |

**Example**
- PBKDF2
```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';

let kdf = cryptoFramework.createKdf('PBKDF2|SHA256');
```

## Kdf<sup>11+</sup>

Defines the key derivation function (KDF) API for deriving a key based on key derivation parameters. Before calling this API, you need to construct this instance using [createKdf](#cryptoframeworkcreatekdf11).

### Attributes

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Kdf
- API version 11: SystemCapability.Security.CryptoFramework

| Name   | Type  | Read-Only| Optional| Description                        |
| ------- | ------ | ---- | ---- | ---------------------------- |
| algName | string | Yes  | No  | Algorithm of the key derivation function.|

### generateSecret<sup>11+</sup>

generateSecret(params: KdfSpec, callback: AsyncCallback\<DataBlob>): void

Generates a key based on the specified key derivation parameters. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Kdf
- API version 11: SystemCapability.Security.CryptoFramework

**Parameters**

| Name  | Type                    | Mandatory| Description                  |
| -------- | ------------------------ | ---- | ---------------------- |
| params   | [KdfSpec](#kdfspec11)        | Yes  | Parameters of the key derivation function.|
| callback | AsyncCallback\<[DataBlob](#datablob)> | Yes  | Callback used to return the key generated. If key derivation is successful, **err** is **undefined** and **data** is the key generated. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | Memory operation failed.          |
| 17620003 | Parameter check failed. Possible causes: <br>1. Invalid key length in the params;<br>2. Invalid info length in the params;<br>3. Invalid keySize in the params. <br>Applicable versions: 22+|
| 17630001 | Crypto operation error. |

**Example**

- PBKDF2
  ```ts
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';

  let spec: cryptoFramework.PBKDF2Spec = {
    algName: 'PBKDF2',
    password: '123456',
    salt: new Uint8Array(16),
    iterations: 10000,
    keySize: 32
  };
  let kdf = cryptoFramework.createKdf('PBKDF2|SHA256');
  kdf.generateSecret(spec, (err, secret) => {
    if (err) {
      console.error(`key derivation failed, errCode: ${err.code}, errMsg: ${err.message}`);
      return;
    }
    console.info('key derivation output = ' + secret.data);
  });
  ```

- HKDF
  ```ts
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';

  let spec: cryptoFramework.HKDFSpec = {
    algName: 'HKDF',
    key: '123456',
    salt: new Uint8Array(16),
    info: new Uint8Array(16),
    keySize: 32
  };
  let kdf = cryptoFramework.createKdf('HKDF|SHA256|EXTRACT_AND_EXPAND');
  kdf.generateSecret(spec, (err, secret) => {
    if (err) {
      console.error(`key derivation failed, errCode: ${err.code}, errMsg: ${err.message}`);
      return;
    }
    console.info('key derivation output = ' + secret.data);
  });
  ```

### generateSecret<sup>11+</sup>

generateSecret(params: KdfSpec): Promise\<DataBlob>

Generates a key based on the specified key derivation parameters. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**:
- API versions 12+: SystemCapability.Security.CryptoFramework.Kdf
- API version 11: SystemCapability.Security.CryptoFramework

**Parameters**

| Name| Type  | Mandatory| Description                  |
| ------ | ------ | ---- | ---------------------- |
| params   | [KdfSpec](#kdfspec11)        | Yes  | Parameters of the key derivation function.|

**Return value**

| Type              | Description    |
| ------------------ | -------- |
| Promise\<[DataBlob](#datablob)> | Promise used to return the key generated.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | Invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | Memory operation failed.          |
| 17620003 | Parameter check failed. Possible causes: <br>1. Invalid key length in the params;<br>2. Invalid info length in the params;<br>3. Invalid keySize in the params. <br>Applicable versions: 22+|
| 17630001 | Crypto operation error. |

**Example**

- PBKDF2
  ```ts
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let spec: cryptoFramework.PBKDF2Spec = {
    algName: 'PBKDF2',
    password: '123456',
    salt: new Uint8Array(16),
    iterations: 10000,
    keySize: 32
  };
  let kdf = cryptoFramework.createKdf('PBKDF2|SHA256');
  let kdfPromise = kdf.generateSecret(spec);
  kdfPromise.then(secret => {
    console.info('key derivation output = ' + secret.data);
  }).catch((error: BusinessError) => {
    console.error(`key derivation failed: errCode: ${error.code}, errMsg: ${error.message}`);
  });
  ```

- HKDF
  ```ts
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let spec: cryptoFramework.HKDFSpec = {
    algName: 'HKDF',
    key: '123456',
    salt: new Uint8Array(16),
    info: new Uint8Array(16),
    keySize: 32
  };
  let kdf = cryptoFramework.createKdf('HKDF|SHA256|EXTRACT_AND_EXPAND');
  let kdfPromise = kdf.generateSecret(spec);
  kdfPromise.then(secret => {
    console.info('key derivation output = ' + secret.data);
  }).catch((error: BusinessError) => {
    console.error(`key derivation failed: errCode: ${error.code}, errMsg: ${error.message}`);
  });
  ```

### generateSecretSync<sup>12+</sup>

generateSecretSync(params: KdfSpec): DataBlob

Generates a key based on the specified key derivation parameters. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Kdf

**Parameters**

| Name| Type  | Mandatory| Description                  |
| ------ | ------ | ---- | ---------------------- |
| params   | [KdfSpec](#kdfspec11)        | Yes  | Parameters of the key derivation function.|

**Return value**

| Type              | Description    |
| ------------------ | -------- |
| [DataBlob](#datablob) | Key derived.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | Invalid parameters.  Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.  |
| 17620001 | Memory operation failed.          |
| 17620002 | Failed to obtain the native object or convert parameters. |
| 17620003 | Parameter check failed. Possible causes: <br>1. Invalid key length in the params;<br>2. Invalid info length in the params;<br>3. Invalid keySize in the params. <br>Applicable versions: 22+|
| 17630001 | Crypto operation error. |

**Example**

- PBKDF2
  ```ts
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';

  let spec: cryptoFramework.PBKDF2Spec = {
    algName: 'PBKDF2',
    password: '123456',
    salt: new Uint8Array(16),
    iterations: 10000,
    keySize: 32
  };
  let kdf = cryptoFramework.createKdf('PBKDF2|SHA256');
  let secret = kdf.generateSecretSync(spec);
  console.info('[Sync]key derivation output = ' + secret.data);
  ```

- HKDF
  ```ts
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';

  let spec: cryptoFramework.HKDFSpec = {
    algName: 'HKDF',
    key: '123456',
    salt: new Uint8Array(16),
    info: new Uint8Array(16),
    keySize: 32
  };
  let kdf = cryptoFramework.createKdf('HKDF|SHA256|EXTRACT_AND_EXPAND');
  let secret = kdf.generateSecretSync(spec);
  console.info('[Sync]key derivation output = ' + secret.data);
  ```

## SignatureUtils<sup>20+</sup>

Provides utilities for converting SM2 data.

### genEccSignatureSpec<sup>20+</sup>

static genEccSignatureSpec(data: Uint8Array): EccSignatureSpec

Generates r and s from the ECC/SM2 signature data encoded in ASN.1 DER format.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Security.CryptoFramework.Signature

**Parameters**

| Name| Type  | Mandatory| Description                  |
| ------ | ------ | ---- | ---------------------- |
| data   | Uint8Array        | Yes  | Signature data encoded in ASN.1 DER format.|

**Return value**

| Type              | Description    |
| ------------------ | -------- |
| [EccSignatureSpec](#eccsignaturespec20) | Data object that contains r and s.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 17620001 | Memory operation failed.          |
| 17620002 | Failed to obtain the native object or convert parameters. |
| 17620003 | Parameter check failed. Possible causes: <br>1. The length of the data parameter is 0 or too large. |
| 17630001 | Crypto operation error. |

**Example**

  ```ts
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  function testGenEccSignatureSpec() {
    try {
      let data =
        new Uint8Array([48, 69, 2, 33, 0, 216, 15, 76, 238, 158, 165, 108, 76, 72, 63, 115, 52, 255, 51, 149, 54, 224,
          179, 49, 225, 70, 36, 117, 88, 154, 154, 27, 194, 161, 3, 1, 115, 2, 32, 51, 9, 53, 55, 248, 82, 7, 159, 179,
          144, 57, 151, 195, 17, 31, 106, 123, 32, 139, 219, 6, 253, 62, 240, 181, 134, 214, 107, 27, 230, 175, 40])
      let spec: cryptoFramework.EccSignatureSpec = cryptoFramework.SignatureUtils.genEccSignatureSpec(data)
      console.info('genEccSignatureSpec result: success.');
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error(`ecc failed: errCode: ${e.code}, errMsg: ${e.message}`);
    }
  }
  ```


### genEccSignature<sup>20+</sup>

static genEccSignature(spec: EccSignatureSpec): Uint8Array;

Converts an ECC/SM2 signature (r, s) to the ASN.1 DER format.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Security.CryptoFramework.Signature

**Parameters**

| Name| Type  | Mandatory| Description                  |
| ------ | ------ | ---- | ---------------------- |
| spec   | [EccSignatureSpec](#eccsignaturespec20)        | Yes  | ECC/SM2 signature data that contains (r, s).|

**Return value**

| Type              | Description    |
| ------------------ | -------- |
| Uint8Array | Signature data encoded in ASN.1 DER format.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 17620001 | Memory operation failed.          |
| 17620002 | Failed to obtain the native object or convert parameters. |
| 17620003 | Parameter check failed. Possible causes: <br>1. The r or s value of the spec parameter is 0 or too large. |
| 17630001 | Crypto operation error. |

**Example**

  ```ts
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  function testGenEccSignature() {
    try {
      let spec: cryptoFramework.EccSignatureSpec = {
        r: BigInt('97726608965854271693043443511967021777934035174185659091642456228829830775155'),
        s: BigInt('23084224202834231287427338597254751764391338275617140205467537273296855150376'),
      }

      let data = cryptoFramework.SignatureUtils.genEccSignature(spec)
      console.info('genEccSignature result: success.');
      console.info('data = ' + data)
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error(`ecc failed: errCode: ${e.code}, errMsg: ${e.message}`);
    }
  }
  ```

## KemAlgNameId

Enumerates the key-encapsulation mechanism (KEM) algorithms.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.Security.CryptoFramework.Cipher

| Name         | Value  | Description                       |
| ------------- | ---- | --------------------------- |
| ML_KEM_512    | 0    | Name ID of ML-KEM-512. |
| ML_KEM_768    | 1    | Name ID of ML-KEM-768. |
| ML_KEM_1024   | 2    | Name ID of ML-KEM-1024.|

## KemEncapResult

Indicates the key encapsulation result.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.Security.CryptoFramework.Cipher

| Name        | Type      | Read-Only| Optional| Description                    |
| ------------ | ---------- | ---- | ---- | ------------------------ |
| sharedSecret | Uint8Array | No  | No  | Shared key generated during key encapsulation.|
| wrappedKey   | Uint8Array | No  | No  | Wrapped key generated during key encapsulation.|

## cryptoFramework.createKem

createKem(algNameId: KemAlgNameId): Kem

Creates a KEM instance for key encapsulation and decapsulation.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.Security.CryptoFramework.Cipher

**Parameters**

| Name   | Type                             | Mandatory| Description                         |
| --------- | --------------------------------- | ---- | ----------------------------- |
| algNameId | [KemAlgNameId](#kemalgnameid)     | Yes  | Name ID of the key encapsulation algorithm.   |

**Return value**

| Type       | Description                         |
| ----------- | ----------------------------- |
| [Kem](#kem) | **Kem** instance of the corresponding algorithm.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message                                                 |
| -------- | --------------------------------------------------------- |
| 17620001 | Memory operation failed.                                  |
| 17620002 | Failed to obtain the native object or convert parameters.         |
| 17620003 | Parameter check failed.                                   |
| 17630001 | Crypto operation error.                                   |

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { BusinessError } from '@kit.BasicServicesKit';

function createKem() {
  try {
    let kem = cryptoFramework.createKem(cryptoFramework.KemAlgNameId.ML_KEM_768);
    console.info('create kem success');
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error(`create kem failed: errCode: ${e.code}, errMsg: ${e.message}`);
  }
}
```

## Kem

Defines an API for key encapsulation and decapsulation based on the key encapsulation mechanism (KEM). Before calling this API, you must use the [createKem(algNameId: KemAlgNameId): Kem](#cryptoframeworkcreatekem) method to create a Kem instance.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Security.CryptoFramework.Cipher

### encapsulate

encapsulate(pubKey: PubKey, ikme: Uint8Array | null): Promise\<KemEncapResult>

Encapsulates a key based on the given public key. This API uses a promise to return the result.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.Security.CryptoFramework.Cipher

**Parameters**

| Name| Type               | Mandatory| Description                                                        |
| ------ | ------------------- | ---- | ------------------------------------------------------------ |
| pubKey | [PubKey](#pubkey)   | Yes  | Public key used for key encapsulation.                                        |
| ikme   | Uint8Array \| null  | Yes  | **ikme** used to generate a temporary key. If **null** is passed, the value is randomly generated by the algorithm library.|

**Return value**

| Type                                         | Description                      |
| --------------------------------------------- | -------------------------- |
| Promise\<[KemEncapResult](#kemencapresult)>   | Promise used to return the key encapsulation result.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message                                                 |
| -------- | --------------------------------------------------------- |
| 17620001 | Memory operation failed.                                  |
| 17620002 | Failed to obtain the native object or convert parameters.         |
| 17620003 | Parameter check failed.                                   |
| 17630001 | Crypto operation error.                                   |

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function kemEncapsulate() {
  try {
    let asyKeyGenerator = cryptoFramework.createAsyKeyGenerator('ML-KEM-768');
    let keyPair = await asyKeyGenerator.generateKeyPair();
    let kem = cryptoFramework.createKem(cryptoFramework.KemAlgNameId.ML_KEM_768);
    let encapResult = await kem.encapsulate(keyPair.pubKey, null);
    console.info('encapsulate success');
    console.info('sharedSecret length: ' + encapResult.sharedSecret.length);
    console.info('wrappedKey length: ' + encapResult.wrappedKey.length);
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error(`encapsulate failed: errCode: ${e.code}, errMsg: ${e.message}`);
  }
}
```

### encapsulateSync

encapsulateSync(pubKey: PubKey, ikme: Uint8Array | null): KemEncapResult

Encapsulates a key based on the given public key. This API returns the result synchronously.

> **NOTE**
>
> You are advised to preferentially use the asynchronous API [encapsulate](#encapsulate) in a child thread. A synchronous API may block the main thread due to long execution time caused by the busy system or a high load.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.Security.CryptoFramework.Cipher

**Parameters**

| Name| Type               | Mandatory| Description                                                        |
| ------ | ------------------- | ---- | ------------------------------------------------------------ |
| pubKey | [PubKey](#pubkey)   | Yes  | Public key used for key encapsulation.                                        |
| ikme   | Uint8Array \| null  | Yes  | **ikme** used to generate a temporary key. If **null** is passed, the value is randomly generated by the algorithm library.|

**Return value**

| Type                               | Description              |
| ----------------------------------- | ------------------ |
| [KemEncapResult](#kemencapresult)   | Key encapsulation result.  |

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message                                                 |
| -------- | --------------------------------------------------------- |
| 17620001 | Memory operation failed.                                  |
| 17620002 | Failed to obtain the native object or convert parameters.         |
| 17620003 | Parameter check failed.                                   |
| 17630001 | Crypto operation error.                                   |

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { BusinessError } from '@kit.BasicServicesKit';

function kemEncapsulateSync() {
  try {
    let asyKeyGenerator = cryptoFramework.createAsyKeyGenerator('ML-KEM-768');
    let keyPair = asyKeyGenerator.generateKeyPairSync();
    let kem = cryptoFramework.createKem(cryptoFramework.KemAlgNameId.ML_KEM_768);
    let encapResult = kem.encapsulateSync(keyPair.pubKey, null);
    console.info('encapsulateSync success');
    console.info('sharedSecret length: ' + encapResult.sharedSecret.length);
    console.info('wrappedKey length: ' + encapResult.wrappedKey.length);
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error(`encapsulateSync failed: errCode: ${e.code}, errMsg: ${e.message}`);
  }
}
```

### decapsulate

decapsulate(priKey: PriKey, wrappedKey: Uint8Array): Promise\<Uint8Array>

Decapsulates a key based on the given private key and wrapped key. This API uses a promise to return the result.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.Security.CryptoFramework.Cipher

**Parameters**

| Name    | Type             | Mandatory| Description                            |
| ---------- | ----------------- | ---- | -------------------------------- |
| priKey     | [PriKey](#prikey) | Yes  | Private key used for key decapsulation.          |
| wrappedKey | Uint8Array        | Yes  | Wrapped key generated during key encapsulation.|

**Return value**

| Type                 | Description                                |
| --------------------- | ------------------------------------ |
| Promise\<Uint8Array>  | Promise used to return the shared key obtained through key decapsulation.|

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message                                                 |
| -------- | --------------------------------------------------------- |
| 17620001 | Memory operation failed.                                  |
| 17620002 | Failed to obtain the native object or convert parameters.         |
| 17620003 | Parameter check failed.                                   |
| 17630001 | Crypto operation error.                                   |

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function kemDecapsulate() {
  try {
    let asyKeyGenerator = cryptoFramework.createAsyKeyGenerator('ML-KEM-768');
    let keyPair = await asyKeyGenerator.generateKeyPair();
    let kem = cryptoFramework.createKem(cryptoFramework.KemAlgNameId.ML_KEM_768);
    let encapResult = await kem.encapsulate(keyPair.pubKey, null);
    let sharedSecret = await kem.decapsulate(keyPair.priKey, encapResult.wrappedKey);
    console.info('decapsulate success');
    console.info('sharedSecret length: ' + sharedSecret.length);
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error(`decapsulate failed: errCode: ${e.code}, errMsg: ${e.message}`);
  }
}
```

### decapsulateSync

decapsulateSync(priKey: PriKey, wrappedKey: Uint8Array): Uint8Array

Decapsulates a key based on the given private key and wrapped key. This API returns the result synchronously.

> **NOTE**
>
> You are advised to preferentially use the asynchronous API [decapsulate](#decapsulate) in a child thread. A synchronous API may block the main thread due to long execution time caused by the busy system or a high load.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.Security.CryptoFramework.Cipher

**Parameters**

| Name    | Type             | Mandatory| Description                            |
| ---------- | ----------------- | ---- | -------------------------------- |
| priKey     | [PriKey](#prikey) | Yes  | Private key used for key decapsulation.          |
| wrappedKey | Uint8Array        | Yes  | Wrapped key generated during key encapsulation.|

**Return value**

| Type      | Description                          |
| ---------- | ------------------------------ |
| Uint8Array | Shared key obtained through key decapsulation.    |

**Error codes**

For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message                                                 |
| -------- | --------------------------------------------------------- |
| 17620001 | Memory operation failed.                                  |
| 17620002 | Failed to obtain the native object or convert parameters.         |
| 17620003 | Parameter check failed.                                   |
| 17630001 | Crypto operation error.                                   |

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { BusinessError } from '@kit.BasicServicesKit';

function kemDecapsulateSync() {
  try {
    let asyKeyGenerator = cryptoFramework.createAsyKeyGenerator('ML-KEM-768');
    let keyPair = asyKeyGenerator.generateKeyPairSync();
    let kem = cryptoFramework.createKem(cryptoFramework.KemAlgNameId.ML_KEM_768);
    let encapResult = kem.encapsulateSync(keyPair.pubKey, null);
    let sharedSecret = kem.decapsulateSync(keyPair.priKey, encapResult.wrappedKey);
    console.info('decapsulateSync success');
    console.info('sharedSecret length: ' + sharedSecret.length);
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error(`decapsulateSync failed: errCode: ${e.code}, errMsg: ${e.message}`);
  }
}
```
