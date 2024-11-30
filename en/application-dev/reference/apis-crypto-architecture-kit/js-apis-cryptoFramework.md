# @ohos.security.cryptoFramework (Crypto Framework)

The **cryptoFramework** module shields underlying hardware and algorithm libraries and provides unified APIs for cryptographic operations.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
```

## Result

 Enumerates the operation results.

 **System capability**: SystemCapability.Security.CryptoFramework

| Name                                 |    Value  |   Description                        |
| ------------------------------------- | -------- | ---------------------------- |
| INVALID_PARAMS                        | 401      | Invalid parameter.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                |
| NOT_SUPPORT                           | 801      | Unsupported operation.<br>**Atomic service API**: This API can be used in atomic services since API version 12.                |
| ERR_OUT_OF_MEMORY                     | 17620001 | Memory error.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                  |
| ERR_RUNTIME_ERROR                     | 17620002 | Runtime error.<br>**Atomic service API**: This API can be used in atomic services since API version 12.          |
| ERR_CRYPTO_OPERATION                  | 17630001 | Cryptographic operation error.<br>**Atomic service API**: This API can be used in atomic services since API version 11.    |

## DataBlob

Defines a buffer array of the Binary Large Object (BLOB) type.

 **Atomic service API**: This API can be used in atomic services since API version 11.

 **System capability**: SystemCapability.Security.CryptoFramework

| Name| Type      | Readable| Writable| Description  |
| ---- | ---------- | ---- | ---- | ------ |
| data | Uint8Array | Yes  | Yes  | Binary data array.|

> **NOTE**
>
> The Uint8Array typed array represents an array of 8-bit unsigned integers.

## ParamsSpec

Encapsulates the parameters used for encryption or decryption. You need to construct its child class object and pass it to [init()](#init-2) for symmetric encryption or decryption. 

It applies to the symmetric cipher modes that require parameters such as the initialization vector (IV). If the IV is not required (for example, the ECB mode), pass in **null** to [init()](#init-2).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Cipher

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 9 to 11 and SystemCapability.Security.CryptoFramework.Cipher since API version 12.

| Name   | Type  | Readable| Writable| Description                                                        |
| ------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| algName | string | Yes  | Yes  | Algorithm for symmetric encryption or decryption.<br/>Options:<br>- **IvParamsSpec**: applicable to the CBC, CTR, OFB, and CFB modes.<br>- **GcmParamsSpec**: applicable to the GCM mode.<br>- **CcmParamsSpec**: applicable to the CCM mode. |

> **NOTE**
>
> The **params** parameter in [init()](#init-2) is of the **ParamsSpec** type (parent class). However, a child class object (such as **IvParamsSpec**) needs to be passed in. When constructing the child class object, you need to set **algName** for its parent class **ParamsSpec** to specify the child class object to be passed to **init()**.

## IvParamsSpec

Defines the child class of [ParamsSpec](#paramsspec). It is a parameter of [init()](#init-2) for symmetric encryption or decryption.

**IvParamsSpec** applies to the cipher modes such as CBC, CTR, OFB, and CFB, which use only the IV.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Cipher

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 9 to 11 and SystemCapability.Security.CryptoFramework.Cipher since API version 12.

| Name| Type                 | Readable| Writable| Description                                                        |
| ---- | --------------------- | ---- | ---- | ------------------------------------------------------------ |
| iv   | [DataBlob](#datablob) | Yes  | Yes  | IV for encryption or decryption.<br/>Options:<br>- AES CBC, CTR, OFB, or CFB mode: 16-byte IV<br>- 3DES CBC, OFB, or CFB mode: 8-byte IV<br>- SM4<sup>10+</sup> CBC, CTR, OFB, or CFB mode: 16-byte IV |

> **NOTE**
>
> Before passing **IvParamsSpec** to [init()](#init-2), specify **algName** for its parent class [ParamsSpec](#paramsspec).

## GcmParamsSpec

Defines the child class of [ParamsSpec](#paramsspec). It is a parameter of [init()](#init-2) for symmetric encryption or decryption.

**GcmParamsSpec** applies to the GCM mode.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Cipher

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 9 to 11 and SystemCapability.Security.CryptoFramework.Cipher since API version 12.

| Name   | Type                 | Readable| Writable| Description                                                        |
| ------- | --------------------- | ---- | ---- | ------------------------------------------------------------ |
| iv      | [DataBlob](#datablob) | Yes  | Yes  | IV, which is of 1 to 16 bytes. A 12-byte IV is commonly used.                            |
| aad     | [DataBlob](#datablob) | Yes  | Yes  | Additional authentication data (AAD), which is of 0 to INT_MAX bytes. A 16-byte AAD is commonly used.                            |
| authTag | [DataBlob](#datablob) | Yes  | Yes  | Authentication tag, which is of 16 bytes.<br>If the GCM mode is used for encryption, **authTag** in the parameter **GcmParamsSpec** of [init()](#init-2) or [initSync()](#initsync12) is the last 16 bytes of [DataBlob](#datablob) output by [doFinal()](#dofinal-2) or [doFinalSync()](#dofinalsync12).|

> **NOTE**
>
> - Before passing **GcmParamsSpec** to [init()](#init-2), specify **algName** for its parent class [ParamsSpec](#paramsspec).
> - The IV to use is not length bound. However, the operation result depends on whether the underlying OpenSSL supports the IV.
> - If **aad** is not required or the length of **aad** is **0**, you can set **aad** to an empty Uint8Array, that is, **aad: { data: new Uint8Array() }**.

## CcmParamsSpec

Defines the child class of [ParamsSpec](#paramsspec). It is a parameter of [init()](#init-2) for symmetric encryption or decryption.

**CcmParamsSpec** applies to the CCM mode.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Cipher

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 9 to 11 and SystemCapability.Security.CryptoFramework.Cipher since API version 12.

| Name   | Type                 | Readable| Writable| Description                                                        |
| ------- | --------------------- | ---- | ---- | ------------------------------------------------------------ |
| iv      | [DataBlob](#datablob) | Yes  | Yes  | IV, which is of 7 bytes.                             |
| aad     | [DataBlob](#datablob) | Yes  | Yes  | AAD, which is of 8 bytes.                            |
| authTag | [DataBlob](#datablob) | Yes  | Yes  | Authentication tag, which is of 12 bytes.<br>If the CCM mode is used for encryption, **authTag** in the parameter [CcmParamsSpec](#ccmparamsspec) of [init()](#init-2) or [initSync()](#initsync12) is the last 12 bytes of [DataBlob](#datablob) output by [doFinal()](#dofinal-2) or [doFinalSync()](#dofinalsync12).|

> **NOTE**
>
> Before passing **CcmParamsSpec** to [init()](#init-2), specify **algName** for its parent class [ParamsSpec](#paramsspec).

## CryptoMode

Enumerates the cryptographic operations.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Cipher

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 9 to 11 and SystemCapability.Security.CryptoFramework.Cipher since API version 12.

| Name        | Value  | Description              |
| ------------ | ---- | ------------------ |
| ENCRYPT_MODE | 0    | Encryption.|
| DECRYPT_MODE | 1    | Decryption.|

## AsyKeySpecItem<sup>10+</sup>

Enumerates the asymmetric key parameters.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Key.AsymKey

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 10 to 11 and SystemCapability.Security.CryptoFramework.Key.AsymKey since API version 12.

| Name        | Value  | Description            |
| ------------ | ---- | ---------------- |
| DSA_P_BN | 101 | Prime modulus **p** in the DSA algorithm.|
| DSA_Q_BN | 102 | Parameter **q**, prime factor of (p – 1) in the DSA algorithm.|
| DSA_G_BN | 103 | Parameter **g** in the DSA algorithm.|
| DSA_SK_BN | 104 | Private key **sk** in the DSA algorithm.|
| DSA_PK_BN | 105 | Public key **pk** in the DSA algorithm.|
| ECC_FP_P_BN | 201 | Prime number **p** in the **Fp** field of the elliptic curve in the ECC algorithm.|
| ECC_A_BN | 202 | First coefficient **a** of the elliptic curve in the ECC algorithm.|
| ECC_B_BN | 203 | Second coefficient **b** of the elliptic curve in the ECC algorithm.|
| ECC_G_X_BN | 204 | X coordinate of the base point **g** in the ECC algorithm.|
| ECC_G_Y_BN | 205 | Y coordinate of the base point **g** in the ECC algorithm.|
| ECC_N_BN | 206 | Order **n** of the base point **g** in the ECC algorithm.|
| ECC_H_NUM | 207 | Cofactor **h** in the ECC algorithm.|
| ECC_SK_BN | 208 | Private key **sk** in the ECC algorithm.|
| ECC_PK_X_BN | 209 | X coordinate of the public key **pk** (a point on the elliptic curve) in the ECC algorithm.|
| ECC_PK_Y_BN | 210 | Y coordinate of the public key **pk** (a point on the elliptic curve) in the ECC algorithm.|
| ECC_FIELD_TYPE_STR | 211 | Elliptic curve field type in the ECC algorithm. Currently, only the **Fp** field is supported.|
| ECC_FIELD_SIZE_NUM | 212 | Size of the field in the ECC algorithm, in bits.<br>**NOTE**: The size of the **Fp** field is the length of the prime **p**, in bits.|
| ECC_CURVE_NAME_STR | 213 | Standards for Efficient Cryptography Group (SECG) curve name in the ECC algorithm.|
| RSA_N_BN | 301 | Modulus **n** in the RSA algorithm.|
| RSA_SK_BN | 302 | Private key **sk** (private key exponent **d**) in the RSA algorithm.|
| RSA_PK_BN | 303 | Public key **pk** (public key exponent **e**) in the RSA algorithm.|
| DH_P_BN<sup>11+</sup> | 401 | Prime **p** in the DH algorithm.|
| DH_G_BN<sup>11+</sup> | 402 | Parameter **g** in the DH algorithm.|
| DH_L_NUM<sup>11+</sup> | 403 | Length of the private key in the DH algorithm, in bits.|
| DH_SK_BN<sup>11+</sup> | 404 | Private key **sk** in the DH algorithm.|
| DH_PK_BN<sup>11+</sup> | 405 | Public key **pk** in the DH algorithm.|
| ED25519_SK_BN<sup>11+</sup> | 501 | Private key **sk** in the Ed25519 algorithm.|
| ED25519_PK_BN<sup>11+</sup> | 502 | Public key **pk** in the Ed25519 algorithm.|
| X25519_SK_BN<sup>11+</sup> | 601 | Private key **sk** in the X25519 algorithm.|
| X25519_PK_BN<sup>11+</sup> | 602 | Public key **pk** in the X25519 algorithm.|

## AsyKeySpecType<sup>10+</sup>

Enumerates the key parameter types.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Key.AsymKey

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 10 to 11 and SystemCapability.Security.CryptoFramework.Key.AsymKey since API version 12.

| Name        | Value  | Description            |
| ------------ | ---- | ---------------- |
| COMMON_PARAMS_SPEC | 0 | Common parameter of the public and private keys. You can use [generateKeyPair()](#generatekeypair-2) to randomly generate a key pair based on the parameters of this type.|
| PRIVATE_KEY_SPEC | 1 | Parameter of the private key. You can use [generatePriKey()](#generateprikey) to generate a private key based on the parameters of this type.|
| PUBLIC_KEY_SPEC | 2 | Parameter of the public key. You can use [generatePubKey()](#generatepubkey) to generate a public key based on the parameters of this type.|
| KEY_PAIR_SPEC | 3 | Full parameters of the public and private keys. You can use [generateKeyPair](#generatekeypair-2) to generate a key pair based on the parameters of this type.|

## CipherSpecItem<sup>10+</sup>

Enumerates the cipher parameters. You can use [setCipherSpec](#setcipherspec10) to set cipher parameters, and use [getCipherSpec](#getcipherspec10) to obtain cipher parameters.

Currently, only RSA and SM2 are supported. Since API version 11, the **SM2_MD_NAME_STR** parameter is supported. For details, see [Asymmetric Key Encryption and Decryption Algorithm Specifications](../../security/CryptoArchitectureKit/crypto-asym-encrypt-decrypt-spec.md).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Cipher

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 10 to 11 and SystemCapability.Security.CryptoFramework.Cipher since API version 12.

| Name        | Value  | Description            |
| ------------ | ---- | ---------------- |
| OAEP_MD_NAME_STR | 100 | Message digest (MD) algorithm used with the PKCS1_OAEP padding mode in RSA.|
| OAEP_MGF_NAME_STR | 101 | Mask generation algorithm used with the PKCS1_OAEP padding mode in RSA. Currently, only MGF1 is supported.|
| OAEP_MGF1_MD_STR | 102 | MD algorithm for the MGF1 mask generation used with the PKCS1_OAEP padding mode in RSA.|
| OAEP_MGF1_PSRC_UINT8ARR | 103 | **pSource** byte stream used with the PKCS1_OAEP padding mode in RSA.|
| SM2_MD_NAME_STR<sup>11+</sup> | 104 | MD algorithm used in SM2.|

## SignSpecItem<sup>10+</sup>

Enumerates the parameters for signing and signature verification. You can use [setSignSpec](#setsignspec10) and [setVerifySpec](#setverifyspec10) to set these parameters, and use [getSignSpec](#getsignspec10) and [getVerifySpec](#getverifyspec10) to obtain the parameters.

Currently, only RSA and SM2 are supported. Since API version 11, the **SM2_USER_ID_UINT8ARR** parameter is supported. For details, see [Signing and Signature Verification Overview and Algorithm Specifications](../../security/CryptoArchitectureKit/crypto-sign-sig-verify-overview.md).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Signature

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 10 to 11 and SystemCapability.Security.CryptoFramework.Signature since API version 12.

| Name        | Value  | Description            |
| ------------ | ---- | ---------------- |
| PSS_MD_NAME_STR | 100 | MD algorithm used with the PSS padding mode in RSA.|
| PSS_MGF_NAME_STR | 101 | Mask generation algorithm used with the PSS padding mode in RSA. Currently, only MGF1 is supported.|
| PSS_MGF1_MD_STR | 102 | MD parameters for the MGF1 mask generation used with the PSS padding mode in RSA.|
| PSS_SALT_LEN_NUM | 103 | Length of the salt in bytes used with the PSS padding mode in RSA.|
| PSS_TRAILER_FIELD_NUM | 104 | Trailer field used in the encoding operation when PSS padding mode is used in RSA.|
| SM2_USER_ID_UINT8ARR<sup>11+</sup> | 105 | User ID field in SM2.|

## AsyKeySpec<sup>10+</sup>

Defines the asymmetric key parameters for creating a key generator. You need to construct a child class object and pass it to [createAsyKeyGeneratorBySpec()](#cryptoframeworkcreateasykeygeneratorbyspec10) to create a key generator. When constructing a child class object, use little-endian format for RSA keys and use big-endian format and positive numbers for other key parameters of the bigint type.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Key.AsymKey

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 10 to 11 and SystemCapability.Security.CryptoFramework.Key.AsymKey since API version 12.

| Name   | Type  | Readable| Writable| Description                                                        |
| ------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| algName | string | Yes  | Yes  | Asymmetric key algorithm, for example, **RSA**, **DSA**, **ECC**, **SM2**, **Ed25519**, **X25519**, or **DH**.|
| specType | [AsyKeySpecType](#asykeyspectype10) | Yes  | Yes| Key parameter type, which is used to distinguish public and private key parameters.|

## DSACommonParamsSpec<sup>10+</sup>

Defines a child class of [AsyKeySpec](#asykeyspec10) used to specify the common parameters of the public and private keys in the DSA algorithm. It can be used to randomly generate a public or private key.

To generate a key based on key parameters, pass it to [createAsyKeyGeneratorBySpec()](#cryptoframeworkcreateasykeygeneratorbyspec10) to create a key generator.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Key.AsymKey

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 10 to 11 and SystemCapability.Security.CryptoFramework.Key.AsymKey since API version 12.

| Name   | Type  | Readable| Writable| Description                                                        |
| ------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| p | bigint | Yes  | Yes  | Prime modulus **p** in the DSA algorithm.|
| q | bigint | Yes  | Yes  | Parameter **q**, prime factor of (**p** – 1) in the DSA algorithm.|
| g | bigint | Yes  | Yes  | Parameter **g** in the DSA algorithm.|

## DSAPubKeySpec<sup>10+</sup>

Defines a child class of [AsyKeySpec](#asykeyspec10) used to specify the parameters of the public key in the DSA algorithm. 

To generate a key based on key parameters, pass it to [createAsyKeyGeneratorBySpec()](#cryptoframeworkcreateasykeygeneratorbyspec10) to create a key generator.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Key.AsymKey

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 10 to 11 and SystemCapability.Security.CryptoFramework.Key.AsymKey since API version 12.

| Name   | Type  | Readable| Writable| Description                                                        |
| ------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| params | [DSACommonParamsSpec](#dsacommonparamsspec10) | Yes  | Yes  | Common parameters of the public and private keys in the DSA algorithm.|
| pk | bigint | Yes  | Yes  | Public key in the DSA algorithm.|

## DSAKeyPairSpec<sup>10+</sup>

Defines a child class of [AsyKeySpec](#asykeyspec10) used to specify full parameters of the public and private keys in the DSA algorithm.

To generate a key based on key parameters, pass it to [createAsyKeyGeneratorBySpec()](#cryptoframeworkcreateasykeygeneratorbyspec10) to create a key generator.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Key.AsymKey

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 10 to 11 and SystemCapability.Security.CryptoFramework.Key.AsymKey since API version 12.

| Name   | Type  | Readable| Writable| Description                                                        |
| ------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| params | [DSACommonParamsSpec](#dsacommonparamsspec10) | Yes  | Yes  | Common parameters of the public and private keys in the DSA algorithm.|
| sk | bigint | Yes  | Yes  | Private key **sk** in the DSA algorithm.|
| pk | bigint | Yes  | Yes  | Public key **pk** in the DSA algorithm.|

## ECField<sup>10+</sup>

Defines an elliptic curve field. Currently, only the **Fp** field is supported.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Key.AsymKey

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 10 to 11 and SystemCapability.Security.CryptoFramework.Key.AsymKey since API version 12.

| Name   | Type  | Readable| Writable| Description                                                        |
| ------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| fieldType | string | Yes  | Yes  | Type of the elliptic curve field. Currently, only **Fp** is supported.|

## ECFieldFp<sup>10+</sup>

Defines the prime field of the elliptic curve. It is a child class of [ECField](#ecfield10).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Key.AsymKey

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 10 to 11 and SystemCapability.Security.CryptoFramework.Key.AsymKey since API version 12.

| Name   | Type  | Readable| Writable| Description                                                        |
| ------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| p | bigint | Yes  | Yes  | Prime **p**.|

## Point<sup>10+</sup>

Defines a point on the elliptic curve.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Key.AsymKey

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 10 to 11 and SystemCapability.Security.CryptoFramework.Key.AsymKey since API version 12.

| Name   | Type  | Readable| Writable| Description                                                        |
| ------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| x | bigint | Yes  | Yes  | X coordinate of the point on an elliptic curve.|
| y | bigint | Yes  | Yes  | Y coordinate of the point on an elliptic curve.|

## ECCCommonParamsSpec<sup>10+</sup>

Defines a child class of [AsyKeySpec](#asykeyspec10) used to specify the common parameters of the public and private keys in the ECC algorithm. It can be used to randomly generate a public or private key.

To generate a key based on key parameters, pass it to [createAsyKeyGeneratorBySpec()](#cryptoframeworkcreateasykeygeneratorbyspec10) to create a key generator.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Key.AsymKey

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 10 to 11 and SystemCapability.Security.CryptoFramework.Key.AsymKey since API version 12.

| Name   | Type  | Readable| Writable| Description                                                        |
| ------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| field | [ECField](#ecfield10) | Yes  | Yes  | Field of the elliptic curve. Currently, only **Fp** is supported.|
| a | bigint | Yes  | Yes  | First coefficient **a** of the elliptic curve.|
| b | bigint | Yes  | Yes  | Second coefficient **b** of the elliptic curve.|
| g | [Point](#point10) | Yes  | Yes  | Base point g.|
| n | bigint | Yes  | Yes  | Order **n** of the base point **g**.|
| h | number | Yes  | Yes  | Cofactor **h**.|

## ECCPriKeySpec<sup>10+</sup>

Defines a child class of [AsyKeySpec](#asykeyspec10) used to specify the parameters of the private key in the ECC algorithm.

To generate a key based on key parameters, pass it to [createAsyKeyGeneratorBySpec()](#cryptoframeworkcreateasykeygeneratorbyspec10) to create a key generator.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Key.AsymKey

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 10 to 11 and SystemCapability.Security.CryptoFramework.Key.AsymKey since API version 12.

| Name   | Type  | Readable| Writable| Description                                                        |
| ------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| params | [ECCCommonParamsSpec](#ecccommonparamsspec10) | Yes  | Yes  | Common parameters of the public and private keys in the ECC algorithm.|
| sk | bigint | Yes  | Yes  | Private key **sk** in the ECC algorithm.|

## ECCPubKeySpec<sup>10+</sup>

Defines a child class of [AsyKeySpec](#asykeyspec10) used to specify the parameters of the public key in the ECC algorithm.

To generate a key based on key parameters, pass it to [createAsyKeyGeneratorBySpec()](#cryptoframeworkcreateasykeygeneratorbyspec10) to create a key generator.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Key.AsymKey

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 10 to 11 and SystemCapability.Security.CryptoFramework.Key.AsymKey since API version 12.

| Name   | Type  | Readable| Writable| Description                                                        |
| ------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| params | [ECCCommonParamsSpec](#ecccommonparamsspec10) | Yes  | Yes  | Common parameters of the public and private keys in the ECC algorithm.|
| pk | [Point](#point10) | Yes  | Yes  | Public key **pk** in the ECC algorithm.|

## ECCKeyPairSpec<sup>10+</sup>

Defines a child class of [AsyKeySpec](#asykeyspec10) used to specify full parameters of the public and private keys in the ECC algorithm. 

To generate a key based on key parameters, pass it to [createAsyKeyGeneratorBySpec()](#cryptoframeworkcreateasykeygeneratorbyspec10) to create a key generator.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Key.AsymKey

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 10 to 11 and SystemCapability.Security.CryptoFramework.Key.AsymKey since API version 12.

| Name   | Type  | Readable| Writable| Description                                                        |
| ------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| params | [ECCCommonParamsSpec](#ecccommonparamsspec10) | Yes  | Yes  | Common parameters of the public and private keys in the ECC algorithm.|
| sk | bigint | Yes  | Yes  | Private key **sk** in the ECC algorithm.|
| pk | [Point](#point10) | Yes  | Yes  | Public key **pk** in the ECC algorithm.|

## RSACommonParamsSpec<sup>10+</sup>

Defines a child class of [AsyKeySpec](#asykeyspec10) used to specify the common parameters of the public and private keys in the RSA algorithm. It can be used to randomly generate a public or private key.

To generate a key based on key parameters, pass it to [createAsyKeyGeneratorBySpec()](#cryptoframeworkcreateasykeygeneratorbyspec10) to create a key generator.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Key.AsymKey

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 10 to 11 and SystemCapability.Security.CryptoFramework.Key.AsymKey since API version 12.

| Name   | Type  | Readable| Writable| Description                                                        |
| ------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| n | bigint | Yes  | Yes  | Modulus **n**.|

## RSAPubKeySpec<sup>10+</sup>

Defines a child class of [AsyKeySpec](#asykeyspec10) used to specify the parameters of the public key in the RSA algorithm. 

To generate a key based on key parameters, pass it to [createAsyKeyGeneratorBySpec()](#cryptoframeworkcreateasykeygeneratorbyspec10) to create a key generator.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Key.AsymKey

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 10 to 11 and SystemCapability.Security.CryptoFramework.Key.AsymKey since API version 12.

| Name   | Type  | Readable| Writable| Description                                                        |
| ------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| params | [RSACommonParamsSpec](#rsacommonparamsspec10) | Yes  | Yes  | Common parameters of the public and private keys in the RSA algorithm.|
| pk | bigint | Yes  | Yes  | Public key **pk** in the RSA algorithm.|

## RSAKeyPairSpec<sup>10+</sup>

Defines a child class of [AsyKeySpec](#asykeyspec10) used to specify full parameters of the public and private keys in the RSA algorithm.

To generate a key based on key parameters, pass it to [createAsyKeyGeneratorBySpec()](#cryptoframeworkcreateasykeygeneratorbyspec10) to create a key generator.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Key.AsymKey

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 10 to 11 and SystemCapability.Security.CryptoFramework.Key.AsymKey since API version 12.

| Name   | Type  | Readable| Writable| Description                                                        |
| ------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| params | [RSACommonParamsSpec](#rsacommonparamsspec10) | Yes  | Yes  | Common parameters of the public and private keys in the RSA algorithm.|
| sk | bigint | Yes  | Yes  | Private key **sk** in the RSA algorithm.|
| pk | bigint | Yes  | Yes  | Public key **pk** in the RSA algorithm.|

## ED25519PriKeySpec<sup>11+</sup>

Defines a child class of [AsyKeySpec](#asykeyspec10) used to specify the parameters of the private key in the Ed25519 algorithm.

To generate a key based on key parameters, pass it to [createAsyKeyGeneratorBySpec()](#cryptoframeworkcreateasykeygeneratorbyspec10) to create a key generator.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Key.AsymKey

The supported system capability is SystemCapability.Security.CryptoFramework in API version 11 and SystemCapability.Security.CryptoFramework.Key.AsymKey since API version 12.

| Name| Type  | Readable| Writable| Description                     |
| ---- | ------ | ---- | ---- | ------------------------- |
| sk   | bigint | Yes  | Yes  | Private key **sk** in the Ed25519 algorithm.|

## ED25519PubKeySpec<sup>11+</sup>

Defines a child class of [AsyKeySpec](#asykeyspec10) used to specify the parameters of the public key in the Ed25519 algorithm.

To generate a key based on key parameters, pass it to [createAsyKeyGeneratorBySpec()](#cryptoframeworkcreateasykeygeneratorbyspec10) to create a key generator.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Key.AsymKey

The supported system capability is SystemCapability.Security.CryptoFramework in API version 11 and SystemCapability.Security.CryptoFramework.Key.AsymKey since API version 12.

| Name| Type  | Readable| Writable| Description                     |
| ---- | ------ | ---- | ---- | ------------------------- |
| pk   | bigint | Yes  | Yes  | Public key **pk** in the Ed25519 algorithm.|

## ED25519KeyPairSpec<sup>11+</sup>

Defines a child class of [AsyKeySpec](#asykeyspec10) used to specify full parameters of the public and private keys in the Ed25519 algorithm.

To generate a key based on key parameters, pass it to [createAsyKeyGeneratorBySpec()](#cryptoframeworkcreateasykeygeneratorbyspec10) to create a key generator.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Key.AsymKey

The supported system capability is SystemCapability.Security.CryptoFramework in API version 11 and SystemCapability.Security.CryptoFramework.Key.AsymKey since API version 12.

| Name| Type  | Readable| Writable| Description                     |
| ---- | ------ | ---- | ---- | ------------------------- |
| sk   | bigint | Yes  | Yes  | Private key **sk** in the Ed25519 algorithm.|
| pk   | bigint | Yes  | Yes  | Public key **pk** in the Ed25519 algorithm.|

## X25519PriKeySpec<sup>11+</sup>

Defines a child class of [AsyKeySpec](#asykeyspec10) used to specify the parameters of the private key in the X25519 algorithm.

To generate a key based on key parameters, pass it to [createAsyKeyGeneratorBySpec()](#cryptoframeworkcreateasykeygeneratorbyspec10) to create a key generator.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Key.AsymKey

The supported system capability is SystemCapability.Security.CryptoFramework in API version 11 and SystemCapability.Security.CryptoFramework.Key.AsymKey since API version 12.

| Name| Type  | Readable| Writable| Description                    |
| ---- | ------ | ---- | ---- | ------------------------ |
| sk   | bigint | Yes  | Yes  | Private key **sk** in the X25519 algorithm.|

## X25519PubKeySpec<sup>11+</sup>

Defines a child class of [AsyKeySpec](#asykeyspec10) used to specify the parameters of the public key in the X25519 algorithm.

To generate a key based on key parameters, pass it to [createAsyKeyGeneratorBySpec()](#cryptoframeworkcreateasykeygeneratorbyspec10) to create a key generator.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Key.AsymKey

The supported system capability is SystemCapability.Security.CryptoFramework in API version 11 and SystemCapability.Security.CryptoFramework.Key.AsymKey since API version 12.

| Name| Type  | Readable| Writable| Description                    |
| ---- | ------ | ---- | ---- | ------------------------ |
| pk   | bigint | Yes  | Yes  | Public key **pk** in the X25519 algorithm.|

## X25519KeyPairSpec<sup>11+</sup>

Defines a child class of [AsyKeySpec](#asykeyspec10) used to specify full parameters of the public and private keys in the X25519 algorithm.

To generate a key based on key parameters, pass it to [createAsyKeyGeneratorBySpec()](#cryptoframeworkcreateasykeygeneratorbyspec10) to create a key generator.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Key.AsymKey

The supported system capability is SystemCapability.Security.CryptoFramework in API version 11 and SystemCapability.Security.CryptoFramework.Key.AsymKey since API version 12.

| Name| Type  | Readable| Writable| Description                    |
| ---- | ------ | ---- | ---- | ------------------------ |
| sk   | bigint | Yes  | Yes  | Private key **sk** in the X25519 algorithm.|
| pk   | bigint | Yes  | Yes  | Public key **pk** in the X25519 algorithm.|

## DHCommonParamsSpec<sup>11+</sup>

Defines a child class of [AsyKeySpec](#asykeyspec10) used to specify the parameters of the public and private keys in the DH algorithm.

To generate a key based on key parameters, pass it to [createAsyKeyGeneratorBySpec()](#cryptoframeworkcreateasykeygeneratorbyspec10) to create a key generator.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Key.AsymKey

The supported system capability is SystemCapability.Security.CryptoFramework in API version 11 and SystemCapability.Security.CryptoFramework.Key.AsymKey since API version 12.

| Name| Type  | Readable| Writable| Description                               |
| ---- | ------ | ---- | ---- | ----------------------------------- |
| p    | bigint | Yes  | Yes  | Large prime **p** in the DH algorithm.              |
| g    | bigint | Yes  | Yes  | Parameter **g** in the DH algorithm.                |
| l    | number | Yes  | Yes  | Length of the private key in the DH algorithm, in bits.|

## DHPriKeySpec<sup>11+</sup>

Defines a child class of [AsyKeySpec](#asykeyspec10) used to specify the parameters of the private key in the DH algorithm.

To generate a key based on key parameters, pass it to [createAsyKeyGeneratorBySpec()](#cryptoframeworkcreateasykeygeneratorbyspec10) to create a key generator.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Key.AsymKey

The supported system capability is SystemCapability.Security.CryptoFramework in API version 11 and SystemCapability.Security.CryptoFramework.Key.AsymKey since API version 12.

| Name  | Type              | Readable| Writable| Description                                |
| ------ | ------------------ | ---- | ---- | ------------------------------------ |
| params | [DHCommonParamsSpec](#dhcommonparamsspec11) | Yes  | Yes  | Common parameters of the public and private keys in the DH algorithm.|
| sk     | bigint             | Yes  | Yes  | Private key **sk** in the DH algorithm.                |

## DHPubKeySpec<sup>11+</sup>

Defines a child class of [AsyKeySpec](#asykeyspec10) used to specify the parameters of the public key in the DH algorithm.

To generate a key based on key parameters, pass it to [createAsyKeyGeneratorBySpec()](#cryptoframeworkcreateasykeygeneratorbyspec10) to create a key generator.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Key.AsymKey

The supported system capability is SystemCapability.Security.CryptoFramework in API version 11 and SystemCapability.Security.CryptoFramework.Key.AsymKey since API version 12.

| Name  | Type              | Readable| Writable| Description                                |
| ------ | ------------------ | ---- | ---- | ------------------------------------ |
| params | [DHCommonParamsSpec](#dhcommonparamsspec11) | Yes  | Yes  | Common parameters of the public and private keys in the DH algorithm.|
| pk     | bigint             | Yes  | Yes  | Public key **pk** in the DH algorithm.                |

## DHKeyPairSpec<sup>11+</sup>

Defines a child class of [AsyKeySpec](#asykeyspec10) used to specify full parameters of the public and private keys in the DH algorithm.

To generate a key based on key parameters, pass it to [createAsyKeyGeneratorBySpec()](#cryptoframeworkcreateasykeygeneratorbyspec10) to create a key generator.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Key.AsymKey

The supported system capability is SystemCapability.Security.CryptoFramework in API version 11 and SystemCapability.Security.CryptoFramework.Key.AsymKey since API version 12.

| Name  | Type              | Readable| Writable| Description                                |
| ------ | ------------------ | ---- | ---- | ------------------------------------ |
| params | [DHCommonParamsSpec](#dhcommonparamsspec11) | Yes  | Yes  | Common parameters of the public and private keys in the DH algorithm.|
| sk     | bigint             | Yes  | Yes  | Private key **sk** in the DH algorithm.                |
| pk     | bigint             | Yes  | Yes  | Public key **pk** in the DH algorithm.                |

## KdfSpec<sup>11+</sup>

Defines the parameters of the key derivation function. When the key derivation function is used to derive a key, you need to construct and pass in a child class object of **KdfSpec**.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Kdf

The supported system capability is SystemCapability.Security.CryptoFramework in API version 11 and SystemCapability.Security.CryptoFramework.Kdf since API version 12.

| Name   | Type  | Readable| Writable| Description                                                        |
| ------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| algName | string | Yes  | Yes  | Algorithm of the key derivation function, for example, **PBKDF2**.|

## PBKDF2Spec<sup>11+</sup>

Defines the child class of [KdfSpec](#kdfspec11). It is used as a parameter for PBKDF2 key derivation.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Kdf

The supported system capability is SystemCapability.Security.CryptoFramework in API version 11 and SystemCapability.Security.CryptoFramework.Kdf since API version 12.

| Name   | Type  | Readable| Writable| Description                                                        |
| ------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| password | string \| Uint8Array | Yes  | Yes  | Original password entered by the user.|
| salt | Uint8Array | Yes  | Yes  | Salt value.|
| iterations | number | Yes  | Yes  | Number of iterations. The value must be a positive integer.|
| keySize | number | Yes  | Yes  | Length of the derived key, in bytes.|

> **NOTE**
>
> **password** specifies the original password. If **password** is of the string type, pass in the data used for key derivation rather than a string of the HexString or Base64 type. In addition, the string must be in utf-8 format. Otherwise, the key derived may be different from the one expected.

## HKDFSpec<sup>12+</sup>

Defines the child class of [KdfSpec](#kdfspec11). It is a parameter for HKDF key derivation.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Kdf

| Name   | Type  | Readable| Writable| Description                                                        |
| ------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| key | string \| Uint8Array | Yes  | Yes  | Key material.|
| salt | Uint8Array | Yes  | Yes  | Salt value.|
| info | Uint8Array | Yes  | Yes  | Information used to expand the key.|
| keySize | number | Yes  | Yes  | Length of the derived key, in bytes.|

> **NOTE**
>
> **key** is the original key material entered by the user. **info** and **salt** are optional. An empty string can be passed in based on the mode.
>
> For example, if the mode is **EXTRACT_AND_EXPAND**, all parameter values must be passed in. If the mode is **EXTRACT_ONLY**, **info** can be empty. When **HKDFspec** is constructed, pass in **null** to **info**.
>
> The default mode is **EXTRACT_AND_EXPAND**. The value **HKDF|SHA256|EXTRACT_AND_EXPAND** is equivalent to **HKDF|SHA256**.

## SM2CipherTextSpec<sup>12+</sup>

Represents the SM2 ciphertext parameters. You can use this object to generate SM2 ciphertext in ASN.1 format or obtain SM2 parameters from the SM2 ciphertext in ASN.1 format.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Cipher

| Name   | Type  | Readable| Writable| Description                                                        |
| ------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| xCoordinate | bigint | Yes  | Yes  | Coordinate X.|
| yCoordinate | bigint | Yes  | Yes  | Coordinate Y.|
| cipherTextData | Uint8Array | Yes  | Yes  | Ciphertext.|
| hashData | Uint8Array | Yes  | Yes  | Hash value.|

> **NOTE**
>
> - **hashData** is a value obtained by applying the SM3 algorithm to the plaintext. It has a fixed length of 256 bits.
>
> - **cipherTextData** is the ciphertext with the same length as the plaintext.
> 
> - During the generation of ciphertext in C1C3C2 format, if the length of x (**C1_X**) or y (**C1_Y**) is less than 32 bytes, zeros must be added to the high-order bits to extend them to 32 bytes.

## Key

Provides APIs for key operations. Before performing cryptographic operations (such as encryption and decryption), you need to construct a child class object of **Key** and pass it to [init()](#init-2) of the [Cipher](#cipher) instance.

Keys can be generated by a key generator.

### Attributes

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Key

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 9 to 11 and SystemCapability.Security.CryptoFramework.Key since API version 12.

| Name   | Type  | Readable| Writable| Description                        |
| ------- | ------ | ---- | ---- | ---------------------------- |
| format  | string | Yes  | No  | Format of the key.                |
| algName | string | Yes  | No  | Algorithm to use. This parameter contains the key length if the key is a symmetric key.|

### getEncoded

getEncoded(): DataBlob

Obtains the byte stream of the key data. This API returns the result synchronously. The key can be a symmetric key, public key, or private key. The public key must be in DER encoding format and comply with the ASN.1 syntax and X.509 specifications. The private key must be in DER encoding format and comply with the ASN.1 syntax and PKCS#8 specifications.

> **NOTE**
>
> When a key parameter is used to generate an RSA private key, the private key object does not support **getEncoded()**.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Key

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 9 to 11 and SystemCapability.Security.CryptoFramework.Key since API version 12.

**Return value**

| Type                 | Description                    |
| --------------------- | ------------------------ |
| [DataBlob](#datablob) | Key obtained.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 801 | this operation is not supported. |
| 17620001 | memory error. |
| 17630001 | crypto operation error. |

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';

async function testGenerateAesKey() {
  let symKeyGenerator = cryptoFramework.createSymKeyGenerator('AES256');
  let symKey = await symKeyGenerator.generateSymKey();
  let encodedKey = symKey.getEncoded();
  console.info('key hex:' + encodedKey.data);
}
```

## SymKey

Provides APIs for symmetric key operations. It is a child class of [Key](#key). Its objects need to be passed to [init()](#init-2) of the [Cipher](#cipher) instance in symmetric encryption and decryption.

Symmetric keys can be generated by a [SymKeyGenerator](#symkeygenerator).

### clearMem

clearMem(): void

Clears the keys in the memory. This API returns the result synchronously. You are advised to use this API when symmetric key instances are no longer used.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Key.SymKey

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 9 to 11 and SystemCapability.Security.CryptoFramework.Key.SymKey since API version 12.

**Example**

<!--code_no_check-->
```ts
let key: cryptoFramework.SymKey;    // The key is generated by a symKeyGenerator. The generation process is omitted here.
let encodedKey = key.getEncoded();
console.info('key blob: '+ encodedKey.data);    // Display key content.
key.clearMem();
encodedKey = key.getEncoded();
console.info('key blob: ' + encodedKey.data);  // Display all 0s.
```

## PubKey

Provides APIs for public key operations. **PubKey** is a child class of [Key](#key). It needs to be passed in during asymmetric encryption and decryption, signature verification, and key agreement.

The public key can be generated by using the asymmetric key generator [AsyKeyGenerator](#asykeygenerator) or [AsyKeyGeneratorBySpec](#asykeygeneratorbyspec10).

### getAsyKeySpec<sup>10+</sup>

getAsyKeySpec(itemType: AsyKeySpecItem): bigint | string | number

Obtains a key parameter. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Key.AsymKey

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 10 to 11 and SystemCapability.Security.CryptoFramework.Key.AsymKey since API version 12.

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
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | memory error. |
| 17630001 | crypto operation error. |

**Example**

<!--code_no_check-->
```ts
let key: cryptoFramework.PubKey; // key is a public key object. The generation process is omitted here.
let p = key.getAsyKeySpec(cryptoFramework.AsyKeySpecItem.ECC_FP_P_BN);
console.info('ecc item --- p: ' + p.toString(16));
```

### getEncodedDer<sup>12+</sup>

getEncodedDer(format: string): DataBlob

Obtains the public key data that complies with the ASN.1 syntax and DER encoding based on the specified format (such as the specification to use and whether to compress the key). Currently, only compressed and uncompressed ECC public key data can be obtained.

> **NOTE**
>
> The difference between [Key.getEncoded()](#getencoded) and this API is as follows:<br>
>
> You can specify the format of the data to obtain in this API.
>
> The format of the key to obtain cannot be specified in [Key.getEncoded()](#getencoded). That is, the format of the data obtained must be the same as that of the original data. The original data format is the format of the key object generated by [convertKey](#convertkey-3).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Key.AsymKey

**Parameters**

| Name| Type                 | Mandatory| Description                |
| ---- | --------------------- | ---- | -------------------- |
| format  | string | Yes  | Format of the key. The value can be **X509\|COMPRESSED** or **X509\|UNCOMPRESSED** only.|

**Return value**

| Type                       | Description                             |
| --------------------------- | --------------------------------- |
| [DataBlob](#datablob) | Public key data in the specified format.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | memory error. |
| 17630001 | crypto operation error. |

**Example**

<!--code_no_check-->
```ts
let key: cryptoFramework.PubKey; // Key is a public key object. The generation process is omitted here.
let returnBlob = key.getEncodedDer('X509|UNCOMPRESSED');
console.info('returnBlob data: ' + returnBlob.data);
```

### getEncodedPem<sup>12+</sup>

getEncodedPem(format: string): string

Obtains the key data. This API returns the result synchronously. The key can be an RSA public or private key. The public key must comply with the X.509 specifications, PKCS #1 specifications, and PEM encoding format.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Key.AsymKey

**Parameters**

| Name| Type                 | Mandatory| Description                |
| ---- | --------------------- | ---- | -------------------- |
| format  | string | Yes  | Encoding format of the key data to obtain. The format for a public key can be **'PKCS1'** or **'X509'**.|

**Return value**

| Type                       | Description                             |
| --------------------------- | --------------------------------- |
| string | Key data obtained.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | invalid parameters.  Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | memory error. |
| 17630001 | crypto operation error. |

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';

let publicPkcs1Str1024: string  =
  "-----BEGIN RSA PUBLIC KEY-----\n"
  + "MIGJAoGBALAg3eavbX433pOjGdWdpL7HIr1w1EAeIcaCtuMfDpECPdX6X5ZjrwiE\n"
  + "h7cO51WXMT2gyN45DCQySr/8cLE2UiUVHo7qlrSatdLA9ETtgob3sJ4qTaBg5Lxg\n"
  + "SHy2gC+bvEpuIuRe64yXGuM/aP+ZvmIj9QBIVI9mJD8jLEOvQBBpAgMBAAE=\n"
  + "-----END RSA PUBLIC KEY-----\n";

function TestPubKeyPkcs1ToX509BySync1024() {
  let rsaGenerator = cryptoFramework.createAsyKeyGenerator('RSA1024');
  let keyPair = rsaGenerator.convertPemKeySync(publicPkcs1Str1024, null);
  let pubPemKey = keyPair.pubKey;
  let pubString = pubPemKey.getEncodedPem('X509');
  console.info("[sync]TestPubKeyPkcs1ToX509BySync1024 pubString output is " + pubString);
}
```

## PriKey

Provides APIs for private key operations. **PriKey** is a child class of [Key](#key). It needs to be passed in during asymmetric encryption and decryption, signing, and key agreement.

The private key can be generated by using the asymmetric key generator [AsyKeyGenerator](#asykeygenerator) or [AsyKeyGeneratorBySpec](#asykeygeneratorbyspec10).

### clearMem

clearMem(): void

Clears the private keys in the memory. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Key.AsymKey

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 9 to 11 and SystemCapability.Security.CryptoFramework.Key.AsymKey since API version 12.

**Example**

<!--code_no_check-->
```ts
let key: cryptoFramework.PriKey; // The key is a private key generated by the asymmetric key generator. The generation process is omitted here.
key.clearMem(); // For the asymmetric private key, clearMem() releases the internal key struct. After clearMem is executed, getEncoded() is not supported.
```

### getAsyKeySpec<sup>10+</sup>

getAsyKeySpec(itemType: AsyKeySpecItem): bigint | string | number

Obtains a key parameter. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Key.AsymKey

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 10 to 11 and SystemCapability.Security.CryptoFramework.Key.AsymKey since API version 12.

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
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | memory error. |
| 17630001 | crypto operation error. |

**Example**

<!--code_no_check-->
```ts
let key: cryptoFramework.PriKey; // key is a private key object. The generation process is omitted here.
let p = key.getAsyKeySpec(cryptoFramework.AsyKeySpecItem.ECC_FP_P_BN);
console.info('ecc item --- p: ' + p.toString(16));
```
### getEncodedDer<sup>12+</sup>

getEncodedDer(format: string): DataBlob

Obtains the private key data that complies with the ASN.1 syntax and DER encoding based on the specified format (such as the key specifications). Currently, only the ECC private key data in PKCS #8 format can be obtained.

> **NOTE**
>
> The difference between [Key.getEncoded()](#getencoded) and this API is as follows:<br>
> You can specify the format of the key data to be obtained in this API. Currently, the ECC private key data in PKCS #8 format is supported.
> The format of the key data to be obtained cannot be specified in [Key.getEncoded()](#getencoded).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Key.AsymKey

**Parameters**

| Name| Type                 | Mandatory| Description                |
| ---- | --------------------- | ---- | -------------------- |
| format  | string | Yes  | Format of the key. Currently, only **PKCS8** is supported.|

**Return value**

| Type                       | Description                             |
| --------------------------- | --------------------------------- |
| [DataBlob](#datablob) | Private key data of the specified format obtained.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | memory error. |
| 17630001 | crypto operation error. |

**Example**

<!--code_no_check-->
```ts
let key: cryptoFramework.PriKey; // key is a private key object. The generation process is omitted here.
let returnBlob = key.getEncodedDer('PKCS8');
console.info('returnBlob data: ' + returnBlob.data);
```

### getEncodedPem<sup>12+</sup>

getEncodedPem(format: string): string

Obtains the key data. This API returns the result synchronously. The key can be an RSA public or private key. The private key must comply with PKCS #8 or PKCS #1 specifications and PEM encoding format.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Key.AsymKey

**Parameters**

| Name| Type                 | Mandatory| Description                |
| ---- | --------------------- | ---- | -------------------- |
| format  | string | Yes  | Encoding format of the key data to obtain. The format of a private key can be **PKCS1** or **'PKCS8'**.|

**Return value**

| Type                       | Description                             |
| --------------------------- | --------------------------------- |
| string | Key data obtained.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | invalid parameters.  Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | memory error. |
| 17630001 | crypto operation error. |

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';

let priKeyPkcs1Str1024: string  =
  "-----BEGIN RSA PRIVATE KEY-----\n"
  + "MIICXQIBAAKBgQCwIN3mr21+N96ToxnVnaS+xyK9cNRAHiHGgrbjHw6RAj3V+l+W\n"
  + "Y68IhIe3DudVlzE9oMjeOQwkMkq//HCxNlIlFR6O6pa0mrXSwPRE7YKG97CeKk2g\n"
  + "YOS8YEh8toAvm7xKbiLkXuuMlxrjP2j/mb5iI/UASFSPZiQ/IyxDr0AQaQIDAQAB\n"
  + "AoGAEvBFzBNa+7J4PXnRQlYEK/tvsd0bBZX33ceacMubHl6WVZbphltLq+fMTBPP\n"
  + "LjXmtpC+aJ7Lvmyl+wTi/TsxE9vxW5JnbuRT48rnZ/Xwq0eozDeEeIBRrpsr7Rvr\n"
  + "7ctrgzr4m4yMHq9aDgpxj8IR7oHkfwnmWr0wM3FuiVlj650CQQDineeNZ1hUTkj4\n"
  + "D3O+iCi3mxEVEeJrpqrmSFolRMb+iozrIRKuJlgcOs+Gqi2fHfOTTL7LkpYe8SVg\n"
  + "e3JxUdVLAkEAxvcZXk+byMFoetrnlcMR13VHUpoVeoV9qkv6CAWLlbMdgf7uKmgp\n"
  + "a1Yp3QPDNQQqkPvrqtfR19JWZ4uy1qREmwJALTU3BjyBoH/liqb6fh4HkWk75Som\n"
  + "MzeSjFIOubSYxhq5tgZpBZjcpvUMhV7Zrw54kwASZ+YcUJvmyvKViAm9NQJBAKF7\n"
  + "DyXSKrem8Ws0m1ybM7HQx5As6l3EVhePDmDQT1eyRbKp+xaD74nkJpnwYdB3jyyY\n"
  + "qc7A1tj5J5NmeEFolR0CQQCn76Xp8HCjGgLHw9vg7YyIL28y/XyfFyaZAzzK+Yia\n"
  + "akNwQ6NeGtXSsuGCcyyfpacHp9xy8qXQNKSkw03/5vDO\n"
  + "-----END RSA PRIVATE KEY-----\n";

function TestPriKeyPkcs1ToPkcs8BySync1024() {
  let rsaGenerator = cryptoFramework.createAsyKeyGenerator('RSA1024');
  let keyPair = rsaGenerator.convertPemKeySync(null, priKeyPkcs1Str1024);
  let priPemKey = keyPair.priKey;
  let priString = priPemKey.getEncodedPem('PKCS8');
  console.info("[sync]TestPriKeyPkcs1ToPkcs8BySync1024 priString output is " + priString);
}
```

## KeyPair

Defines an asymmetric key pair, which includes a public key and a private key.

The asymmetric key pair can be generated by using the asymmetric key generator [AsyKeyGenerator](#asykeygenerator) or [AsyKeyGeneratorBySpec](#asykeygeneratorbyspec10).

> **NOTE**
>
> The **pubKey** and **priKey** objects in the **KeyPair** object exist as one parameter in the **KeyPair** object. When **KeyPair** leaves the scope, its internal objects can be destructed.
>
> The service must reference the **KeyPair** object instead of the internal **pubKey** or **priKey** object.

### Attributes

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Key.AsymKey

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 9 to 11 and SystemCapability.Security.CryptoFramework.Key.AsymKey since API version 12.

| Name   | Type  | Readable| Writable| Description          |
| ------- | ------ | ---- | ---- | ------------ |
| priKey  | [PriKey](#prikey) | Yes  | No  | Private key.     |
| pubKey | [PubKey](#pubkey) | Yes  | No  | Public key.      |

## cryptoFramework.createSymKeyGenerator

createSymKeyGenerator(algName: string): SymKeyGenerator

Creates a **symKeyGenerator** instance based on the specified algorithm.

For details about the supported specifications, see [Symmetric Key Generation and Conversion Specifications](../../security/CryptoArchitectureKit/crypto-sym-key-generation-conversion-spec.md).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Key.SymKey

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 9 to 11 and SystemCapability.Security.CryptoFramework.Key.SymKey since API version 12.

**Parameters**

| Name | Type  | Mandatory| Description                                                        |
| ------- | ------ | ---- | ------------------------------------------------------------ |
| algName | string | Yes  | Algorithm used to create the **symKeyGenerator** instance.<br>For details, see **String Parameter** in [Symmetric Key Generation and Conversion Specifications](../../security/CryptoArchitectureKit/crypto-sym-key-generation-conversion-spec.md).|

**Return value**

| Type                               | Description                      |
| ----------------------------------- | -------------------------- |
| [SymKeyGenerator](#symkeygenerator) | **symKeyGenerator** instance created.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 801 | this operation is not supported. |

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';

let symKeyGenerator = cryptoFramework.createSymKeyGenerator('3DES192');
```

## SymKeyGenerator

Provides APIs for using the **symKeyGenerator**.

Before using any API of the **SymKeyGenerator** class, you must create a **SymKeyGenerator** instance by using [createSymKeyGenerator](#cryptoframeworkcreatesymkeygenerator).

### Attributes

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Key.SymKey

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 9 to 11 and SystemCapability.Security.CryptoFramework.Key.SymKey since API version 12.

| Name   | Type  | Readable| Writable| Description                          |
| ------- | ------ | ---- | ---- | ------------------------------ |
| algName | string | Yes  | No  | Algorithm used by the **symKeyGenerator**.|

### generateSymKey

generateSymKey(callback: AsyncCallback\<SymKey>): void

Generates a key randomly. This API uses an asynchronous callback to return the result.

This API can be used only after a **symKeyGenerator** instance is created by using [createSymKeyGenerator](#cryptoframeworkcreatesymkeygenerator).

**RAND_priv_bytes()** of OpenSSL can be used to generate random keys.

> **NOTE**
>
> For the symmetric key used with the HMAC algorithm, if the hash algorithm (for example, **HMAC|SHA256**) is specified when the symmetric key generator is created, a binary key with the same length as the hash value will be randomly generated. For example, if **HMAC|SHA256** is specified, a 256-bit key will be randomly generated.<br>If no hash algorithm is specified when the symmetric key generator is created (for example, only HMAC is specified), symmetric key data cannot be randomly generated. In this case, you can use [convertKey](#convertkey) to generate symmetric key data.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Key.SymKey

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 9 to 11 and SystemCapability.Security.CryptoFramework.Key.SymKey since API version 12.

**Parameters**

| Name    | Type                             | Mandatory| Description                                                        |
| -------- | --------------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback\<[SymKey](#symkey)> | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **undefined** and **data** is the symmetric key generated. Otherwise, **err** is an error object.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message     |
| -------- | ------------- |
| 17620001 | memory error. |

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';

let symKeyGenerator = cryptoFramework.createSymKeyGenerator('3DES192');
  symKeyGenerator.generateSymKey((err, symKey) => {
    console.info('Generate symKey success, algName: ' + symKey.algName);
  });
```

### generateSymKey

generateSymKey(): Promise\<SymKey>

Generates a key randomly. This API uses a promise to return the result.

This API can be used only after a **symKeyGenerator** instance is created by using [createSymKeyGenerator](#cryptoframeworkcreatesymkeygenerator).

**RAND_priv_bytes()** of OpenSSL can be used to generate random keys.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Key.SymKey

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 9 to 11 and SystemCapability.Security.CryptoFramework.Key.SymKey since API version 12.

**Return value**

| Type                       | Description                             |
| --------------------------- | --------------------------------- |
| Promise\<[SymKey](#symkey)> | Promise used to return the symmetric key generated.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message     |
| -------- | ------------- |
| 17620001 | memory error. |

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { BusinessError } from '@kit.BasicServicesKit';

let symKeyGenerator = cryptoFramework.createSymKeyGenerator('AES128');
  symKeyGenerator.generateSymKey()
    .then(symKey => {
      console.info('Generate symKey success, algName: ' + symKey.algName);
    }).catch((error: BusinessError) => {
      console.error(`Generate symKey failed, ${error.code}, ${error.message}`);
    });
```

### generateSymKeySync<sup>12+</sup>

generateSymKeySync(): SymKey

Generates a symmetric key randomly. This API returns the result synchronously.

This API can be used only after a **symKeyGenerator** instance is created by using [createSymKeyGenerator](#cryptoframeworkcreatesymkeygenerator).

**RAND_priv_bytes()** of OpenSSL can be used to generate random keys.

> **NOTE**
>
> For the symmetric key used with the HMAC algorithm, if the hash algorithm (for example, **HMAC|SHA256**) is specified when the symmetric key generator is created, a binary key with the same length as the hash value will be randomly generated. For example, if **HMAC|SHA256** is specified, a 256-bit key will be randomly generated.<br>If no hash algorithm is specified when the symmetric key generator is created (for example, only **HMAC** is specified), symmetric key data cannot be randomly generated. In this case, you can use [convertKeySync](#convertkeysync12) to generate symmetric key data.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Key.SymKey

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message     |
| -------- | ------------- |
| 17620001 | memory error. |

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

Converts data into a symmetric key. This API uses an asynchronous callback to return the result.

This API can be used only after a **symKeyGenerator** instance is created by using [createSymKeyGenerator](#cryptoframeworkcreatesymkeygenerator).

> **NOTE**
>
> For the symmetric key used with the HMAC algorithm, if the hash algorithm (for example, **HMAC|SHA256**) is specified when the symmetric key generator is created, the binary key data to be passed in must be of the same length as the hash. For example, if **HMAC|SHA256** is specified, a 256-bit key must be passed in.<br>If no hash algorithm is specified when the symmetric key generator is created (for example, only HMAC is specified), the length of the binary key data is in the range of [1,4096], in bytes.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Key.SymKey

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 9 to 11 and SystemCapability.Security.CryptoFramework.Key.SymKey since API version 12.

**Parameters**

| Name    | Type         | Mandatory| Description                      |
| -------- | ------------------- | ---- | ---------------------|
| key      | [DataBlob](#datablob)             | Yes  | Data to convert.                                        |
| callback | AsyncCallback\<[SymKey](#symkey)> | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **undefined** and **data** is the symmetric key generated. Otherwise, **err** is an error object.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message                                              |
| -------- | --------------------------------------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | memory error.                                       |

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
    console.info('Convert symKey success, algName: ' + symKey.algName);
  });
}
```

### convertKey

convertKey(key: DataBlob): Promise\<SymKey>

Converts data into a symmetric key. This API uses a promise to return the result.

This API can be used only after a **symKeyGenerator** instance is created by using [createSymKeyGenerator](#cryptoframeworkcreatesymkeygenerator).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Key.SymKey

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 9 to 11 and SystemCapability.Security.CryptoFramework.Key.SymKey since API version 12.

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
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | memory error.                                |

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
      console.info('Convert symKey success, algName: ' + symKey.algName);
    }).catch((error: BusinessError) => {
      console.error(`Convert symKey failed, ${error.code}, ${error.message}`);
    });
}
```

### convertKeySync<sup>12+</sup>

convertKeySync(key: DataBlob): SymKey

Converts data into a symmetric key. This API returns the result synchronously.

This API can be used only after a **symKeyGenerator** instance is created by using [createSymKeyGenerator](#cryptoframeworkcreatesymkeygenerator).

> **NOTE**
>
> For the symmetric key used with the HMAC algorithm, if the hash algorithm (for example, **HMAC|SHA256**) is specified when the symmetric key generator is created, the binary key data to be passed in must be of the same length as the hash. For example, if **HMAC|SHA256** is specified, a 256-bit key must be passed in.<br>If no hash algorithm is specified when the symmetric key generator is created (for example, only HMAC is specified), the length of the binary key data is in the range of [1,4096], in bytes.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Key.SymKey

**Parameters**

| Name    | Type         | Mandatory| Description                      |
| -------- | ------------------- | ---- | ---------------------|
| key      | [DataBlob](#datablob)             | Yes  | Data to convert.                                        |

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message                                              |
| -------- | --------------------------------------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | memory error.                                       |

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { buffer } from '@kit.ArkTS';

function testConvertKeySync() {
  // The symmetric key length is 64 bytes, that is, 512 bits.
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

Creates an **AsyKeyGenerator** instance based on the specified algorithm.

For details about the supported specifications, see [Asymmetric Key Generation and Conversion Specifications](../../security/CryptoArchitectureKit/crypto-asym-key-generation-conversion-spec.md).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Key.AsymKey

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 9 to 11 and SystemCapability.Security.CryptoFramework.Key.AsymKey since API version 12.

**Parameters**

| Name | Type  | Mandatory| Description                            |
| ------- | ------ | ---- | -------------------------------- |
| algName | string | Yes  | Algorithm used to create the **symkeyGenerator**.|

**Return value**

| Type           | Description                        |
| --------------- | ---------------------------- |
| [AsyKeyGenerator](#asykeygenerator) | **AsyKeyGenerator** instance created.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 801 | this operation is not supported. |
| 17620001 | memory error. |

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';

let asyKeyGenerator = cryptoFramework.createAsyKeyGenerator('ECC256');
```

## AsyKeyGenerator

Provides APIs for using the **AsKeyGenerator**. Before using any API of the **AsKeyGenerator** class, you must create an **AsyKeyGenerator** instance by using **createAsyKeyGenerator()**.

### Attributes

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Key.AsymKey

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 9 to 11 and SystemCapability.Security.CryptoFramework.Key.AsymKey since API version 12.

| Name   | Type  | Readable| Writable| Description                            |
| ------- | ------ | ---- | ---- | -------------------------------- |
| algName | string | Yes  | No  | Algorithm used by the **AsKeyGenerator**.|

### generateKeyPair

generateKeyPair(callback: AsyncCallback\<KeyPair>): void

Generates a key pair randomly. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Key.AsymKey

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 9 to 11 and SystemCapability.Security.CryptoFramework.Key.AsymKey since API version 12.

**Parameters**

| Name    | Type                   | Mandatory| Description                          |
| -------- | ----------------------- | ---- | ------------------------------ |
| callback | AsyncCallback\<[KeyPair](#keypair)> | Yes  | Callback invoked to return the key pair obtained.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | invalid parameters. Possible causes: <br>Incorrect parameter types;|
| 17620001 | memory error.          |
| 17630001 | crypto operation error.          |

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';

let asyKeyGenerator = cryptoFramework.createAsyKeyGenerator('ECC256');
asyKeyGenerator.generateKeyPair((err, keyPair) => {
  if (err) {
    console.error("generateKeyPair: error.");
    return;
  }
  console.info('generateKeyPair: success.');
})
```

### generateKeyPair

generateKeyPair(): Promise\<KeyPair>

Generates a key pair randomly. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Key.AsymKey

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 9 to 11 and SystemCapability.Security.CryptoFramework.Key.AsymKey since API version 12.

**Return value**

| Type             | Description                             |
| ----------------- | --------------------------------- |
| Promise\<[KeyPair](#keypair)> | Promise used to return the key pair generated.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.         |
| 17620001 | memory error.          |
| 17630001 | crypto operation error.          |

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { BusinessError } from '@kit.BasicServicesKit';

let asyKeyGenerator = cryptoFramework.createAsyKeyGenerator('ECC256');
let keyGenPromise = asyKeyGenerator.generateKeyPair();
keyGenPromise.then(keyPair => {
  console.info('generateKeyPair success.');
}).catch((error: BusinessError) => {
  console.error("generateKeyPair error.");
});
```

### generateKeyPairSync<sup>12+</sup>

generateKeyPairSync(): KeyPair

Generates a key pair randomly. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Key.AsymKey

**Return value**

| Type             | Description                             |
| ----------------- | --------------------------------- |
| [KeyPair](#keypair) | Asymmetric key pair generated.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.          |
| 17620001 | memory error.          |
| 17630001 | crypto operation error.          |

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';

let asyKeyGenerator = cryptoFramework.createAsyKeyGenerator('ECC256');
try {
  let keyPairData = asyKeyGenerator.generateKeyPairSync();
  if (keyPairData != null) {
    console.info('[Sync]: key pair success');
  } else {
    console.error("[Sync]: get key pair result fail!");
  }
} catch (e) {
  console.error(`sync error, ${e.code}, ${e.message}`);
}
```

### convertKey

convertKey(pubKey: DataBlob | null, priKey: DataBlob | null, callback: AsyncCallback\<KeyPair\>): void

Converts data into an asymmetric key. This API uses an asynchronous callback to return the result. For details, see **Key Conversion**.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Key.AsymKey

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 9 to 11 and SystemCapability.Security.CryptoFramework.Key.AsymKey since API version 12.

**Parameters**

| Name    | Type      | Mandatory| Description                          |
| -------- | ----------- | ---- | ------------------------------ |
| pubKey   | [DataBlob](#datablob) \| null<sup>10+</sup>    | Yes  | Public key material to convert. If no public key is required, set this parameter to **null**. In versions earlier than API version 10, only **DataBlob** is supported. Since API version 10, **null** is also supported.       |
| priKey   | [DataBlob](#datablob) \| null<sup>10+</sup>   | Yes  | Private key material to convert. If no private key is required, set this parameter to **null**. In versions earlier than API version 10, only **DataBlob** is supported. Since API version 10, **null** is also supported.       |
| callback | AsyncCallback\<[KeyPair](#keypair)> | Yes  | Callback invoked to return the key pair obtained.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | memory error.          |
| 17630001 | crypto operation error.          |

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';

let pubKeyArray = new Uint8Array([48, 89, 48, 19, 6, 7, 42, 134, 72, 206, 61, 2, 1, 6, 8, 42, 134, 72, 206, 61, 3, 1, 7, 3, 66, 0, 4, 83, 96, 142, 9, 86, 214, 126, 106, 247, 233, 92, 125, 4, 128, 138, 105, 246, 162, 215, 71, 81, 58, 202, 121, 26, 105, 211, 55, 130, 45, 236, 143, 55, 16, 248, 75, 167, 160, 167, 106, 2, 152, 243, 44, 68, 66, 0, 167, 99, 92, 235, 215, 159, 239, 28, 106, 124, 171, 34, 145, 124, 174, 57, 92]);
let priKeyArray = new Uint8Array([48, 49, 2, 1, 1, 4, 32, 115, 56, 137, 35, 207, 0, 60, 191, 90, 61, 136, 105, 210, 16, 27, 4, 171, 57, 10, 61, 123, 40, 189, 28, 34, 207, 236, 22, 45, 223, 10, 189, 160, 10, 6, 8, 42, 134, 72, 206, 61, 3, 1, 7]);
let pubKeyBlob: cryptoFramework.DataBlob = { data: pubKeyArray }; // Binary data of the public key.
let priKeyBlob: cryptoFramework.DataBlob = { data: priKeyArray }; // Binary data of the private key.
let asyKeyGenerator = cryptoFramework.createAsyKeyGenerator('ECC256');
asyKeyGenerator.convertKey(pubKeyBlob, priKeyBlob, (err, keyPair) => {
  if (err) {
    console.error("convertKey: error.");
    return;
  }
  console.info('convertKey: success.');
});
```

### convertKey

convertKey(pubKey: DataBlob | null, priKey: DataBlob | null): Promise\<KeyPair>

Converts data into an asymmetric key. This API uses a promise to return the result. For details, see **Key Conversion**.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Key.AsymKey

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 9 to 11 and SystemCapability.Security.CryptoFramework.Key.AsymKey since API version 12.

**Parameters**

| Name  | Type   | Mandatory| Description            |
| ------ | -------- | ---- | ---------------- |
| pubKey | [DataBlob](#datablob) \| null<sup>10+</sup> | Yes  | Public key material to convert. If no public key is required, set this parameter to **null**. In versions earlier than API version 10, only **DataBlob** is supported. Since API version 10, **null** is also supported.|
| priKey | [DataBlob](#datablob) \| null<sup>10+</sup> | Yes  | Private key material to convert. If no private key is required, set this parameter to **null**. In versions earlier than API version 10, only **DataBlob** is supported. Since API version 10, **null** is also supported.|

**Return value**

| Type             | Description                             |
| ----------------- | --------------------------------- |
| Promise\<[KeyPair](#keypair)> | Promise used to return the key pair generated.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | memory error.          |
| 17630001 | crypto operation error.          |

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { BusinessError } from '@kit.BasicServicesKit';

let pubKeyArray = new Uint8Array([48, 89, 48, 19, 6, 7, 42, 134, 72, 206, 61, 2, 1, 6, 8, 42, 134, 72, 206, 61, 3, 1, 7, 3, 66, 0, 4, 83, 96, 142, 9, 86, 214, 126, 106, 247, 233, 92, 125, 4, 128, 138, 105, 246, 162, 215, 71, 81, 58, 202, 121, 26, 105, 211, 55, 130, 45, 236, 143, 55, 16, 248, 75, 167, 160, 167, 106, 2, 152, 243, 44, 68, 66, 0, 167, 99, 92, 235, 215, 159, 239, 28, 106, 124, 171, 34, 145, 124, 174, 57, 92]);
let priKeyArray = new Uint8Array([48, 49, 2, 1, 1, 4, 32, 115, 56, 137, 35, 207, 0, 60, 191, 90, 61, 136, 105, 210, 16, 27, 4, 171, 57, 10, 61, 123, 40, 189, 28, 34, 207, 236, 22, 45, 223, 10, 189, 160, 10, 6, 8, 42, 134, 72, 206, 61, 3, 1, 7]);
let pubKeyBlob: cryptoFramework.DataBlob = { data: pubKeyArray }; // Binary data of the public key.
let priKeyBlob: cryptoFramework.DataBlob = { data: priKeyArray }; // Binary data of the private key.
let asyKeyGenerator = cryptoFramework.createAsyKeyGenerator('ECC256');
let keyGenPromise = asyKeyGenerator.convertKey(pubKeyBlob, priKeyBlob);
keyGenPromise.then(keyPair => {
  console.info('convertKey success.');
}).catch((error: BusinessError) => {
  console.error("convertKey error.");
});
```

### convertKeySync<sup>12+</sup>

convertKeySync(pubKey: DataBlob | null, priKey: DataBlob | null): KeyPair

Converts data into an asymmetric key pair. This API returns the result synchronously. For details, see **Key Conversion**.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Key.AsymKey

**Parameters**

| Name  | Type   | Mandatory| Description            |
| ------ | -------- | ---- | ---------------- |
| pubKey | [DataBlob](#datablob) \| null<sup>10+</sup> | Yes  | Public key material to convert. If no public key is required, set this parameter to **null**. In versions earlier than API version 10, only **DataBlob** is supported. Since API version 10, **null** is also supported.|
| priKey | [DataBlob](#datablob) \| null<sup>10+</sup> | Yes  | Private key material to convert. If no private key is required, set this parameter to **null**. In versions earlier than API version 10, only **DataBlob** is supported. Since API version 10, **null** is also supported.|

**Return value**

| Type             | Description                             |
| ----------------- | --------------------------------- |
| [KeyPair](#keypair) | Asymmetric key pair generated.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | memory error.          |
| 17630001 | crypto operation error.          |

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';

let pubKeyArray = new Uint8Array([48, 89, 48, 19, 6, 7, 42, 134, 72, 206, 61, 2, 1, 6, 8, 42, 134, 72, 206, 61, 3, 1, 7, 3, 66, 0, 4, 83, 96, 142, 9, 86, 214, 126, 106, 247, 233, 92, 125, 4, 128, 138, 105, 246, 162, 215, 71, 81, 58, 202, 121, 26, 105, 211, 55, 130, 45, 236, 143, 55, 16, 248, 75, 167, 160, 167, 106, 2, 152, 243, 44, 68, 66, 0, 167, 99, 92, 235, 215, 159, 239, 28, 106, 124, 171, 34, 145, 124, 174, 57, 92]);
let priKeyArray = new Uint8Array([48, 49, 2, 1, 1, 4, 32, 115, 56, 137, 35, 207, 0, 60, 191, 90, 61, 136, 105, 210, 16, 27, 4, 171, 57, 10, 61, 123, 40, 189, 28, 34, 207, 236, 22, 45, 223, 10, 189, 160, 10, 6, 8, 42, 134, 72, 206, 61, 3, 1, 7]);
let pubKeyBlob: cryptoFramework.DataBlob = { data: pubKeyArray }; // Binary data of the public key.
let priKeyBlob: cryptoFramework.DataBlob = { data: priKeyArray }; // Binary data of the private key.
let asyKeyGenerator = cryptoFramework.createAsyKeyGenerator('ECC256');
try {
  let keyPairData = asyKeyGenerator.convertKeySync(pubKeyBlob, priKeyBlob);
  if (keyPairData != null) {
    console.info('[Sync]: key pair success');
  } else {
    console.error("[Sync]: convert key pair result fail!");
  }
} catch (e) {
  console.error(`sync error, ${e.code}, ${e.message}`);
}
```

**Key Conversion**

1. When **getEncoded()** is used to convert an asymmetric key pair (RSA, ECC, or DSA) into binary data, the public key returned is in X.509 format, and the private key is in PKCS #8 format. For an ECC private key, it is in the format defined in RFC 5915. These key data can be transferred across applications and stored persistently.
2. When **convertKey()** is used to convert binary data into an asymmetric key object defined by the Crypto framework, the public key must comply with the ASN.1 syntax, X.509 specifications, and DER encoding format, and the private key must comply with the ASN.1 syntax, PKCS #8 specifications, and DER encoding format.
3. In **convertKey()**, you can pass in either **pubKey** or **priKey**, or both of them. If one of them is passed in, the returned **KeyPair** instance contains only the key converted from the data you passed in.
4. When **convertKey** or **convertKeySync** is used, the system does not verify whether the specifications of the generated key object are the same as the key specifications specified for the asymmetric key generator.

### convertPemKey<sup>12+</sup>

convertPemKey(pubKey: string | null, priKey: string | null): Promise\<KeyPair>

Converts data into an asymmetric key. This API uses a promise to return the result.

> **NOTE**
> 1. When **convertPemKey()** is used to convert an external string into an asymmetric key object defined by the Crypto framework, the public key must comply with the ASN.1 syntax, X.509 specifications, and PEM encoding format, and the private key must comply with the ASN.1 syntax, PKCS #8 specifications, and PEM encoding format.
> 2. In **convertPemKey()**, you can pass in either **pubKey** or **priKey**, or both of them. If one of them is passed in, the returned **KeyPair** instance contains only the key converted from the data you passed in.
> 3. When **convertPemKey** is used to convert an external string into an asymmetric key object defined by the Crypto framework, the system does not verify whether the specifications of the generated key object are the same as the key specifications specified for the asymmetric key generator.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Key.AsymKey

**Parameters**

| Name  | Type   | Mandatory| Description            |
| ------ | -------- | ---- | ---------------- |
| pubKey | string \| null | Yes | Public key material to convert. If no public key is required, set this parameter to **null**.|
| priKey | string \| null | Yes | Private key material to convert. If no private key is required, set this parameter to **null**. <br>**NOTE**: **pubKey** and **priKey** cannot be **null** at the same time.|

**Return value**

| Type             | Description                             |
| ----------------- | --------------------------------- |
| Promise\<[KeyPair](#keypair)> | Promise used to return the key pair generated.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.         |
| 17620001 | memory error.          |
| 17630001 | crypto operation error.          |

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { BusinessError } from '@kit.BasicServicesKit';

let priKeyPkcs1Str1024: string  =
  "-----BEGIN RSA PRIVATE KEY-----\n"
  + "MIICXQIBAAKBgQCwIN3mr21+N96ToxnVnaS+xyK9cNRAHiHGgrbjHw6RAj3V+l+W\n"
  + "Y68IhIe3DudVlzE9oMjeOQwkMkq//HCxNlIlFR6O6pa0mrXSwPRE7YKG97CeKk2g\n"
  + "YOS8YEh8toAvm7xKbiLkXuuMlxrjP2j/mb5iI/UASFSPZiQ/IyxDr0AQaQIDAQAB\n"
  + "AoGAEvBFzBNa+7J4PXnRQlYEK/tvsd0bBZX33ceacMubHl6WVZbphltLq+fMTBPP\n"
  + "LjXmtpC+aJ7Lvmyl+wTi/TsxE9vxW5JnbuRT48rnZ/Xwq0eozDeEeIBRrpsr7Rvr\n"
  + "7ctrgzr4m4yMHq9aDgpxj8IR7oHkfwnmWr0wM3FuiVlj650CQQDineeNZ1hUTkj4\n"
  + "D3O+iCi3mxEVEeJrpqrmSFolRMb+iozrIRKuJlgcOs+Gqi2fHfOTTL7LkpYe8SVg\n"
  + "e3JxUdVLAkEAxvcZXk+byMFoetrnlcMR13VHUpoVeoV9qkv6CAWLlbMdgf7uKmgp\n"
  + "a1Yp3QPDNQQqkPvrqtfR19JWZ4uy1qREmwJALTU3BjyBoH/liqb6fh4HkWk75Som\n"
  + "MzeSjFIOubSYxhq5tgZpBZjcpvUMhV7Zrw54kwASZ+YcUJvmyvKViAm9NQJBAKF7\n"
  + "DyXSKrem8Ws0m1ybM7HQx5As6l3EVhePDmDQT1eyRbKp+xaD74nkJpnwYdB3jyyY\n"
  + "qc7A1tj5J5NmeEFolR0CQQCn76Xp8HCjGgLHw9vg7YyIL28y/XyfFyaZAzzK+Yia\n"
  + "akNwQ6NeGtXSsuGCcyyfpacHp9xy8qXQNKSkw03/5vDO\n"
  + "-----END RSA PRIVATE KEY-----\n";
  let publicPkcs1Str1024: string  =
  "-----BEGIN RSA PUBLIC KEY-----\n"
  + "MIGJAoGBALAg3eavbX433pOjGdWdpL7HIr1w1EAeIcaCtuMfDpECPdX6X5ZjrwiE\n"
  + "h7cO51WXMT2gyN45DCQySr/8cLE2UiUVHo7qlrSatdLA9ETtgob3sJ4qTaBg5Lxg\n"
  + "SHy2gC+bvEpuIuRe64yXGuM/aP+ZvmIj9QBIVI9mJD8jLEOvQBBpAgMBAAE=\n"
  + "-----END RSA PUBLIC KEY-----\n";
async function TestConvertPemKeyByPromise() {
  let asyKeyGenerator = cryptoFramework.createAsyKeyGenerator('RSA1024');
  let keyGenPromise = asyKeyGenerator.convertPemKey(publicPkcs1Str1024, priKeyPkcs1Str1024);
  keyGenPromise.then(keyPair => {
    console.info('convertPemKey success.');
  }).catch((error: BusinessError) => {
    console.error("convertPemKey error.");
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
| pubKey | string \| null| Yes  | Public key material to convert. If no public key is required, set this parameter to **null**.|
| priKey | string \| null| Yes  | Private key material to convert. If no private key is required, set this parameter to **null**. <br>**NOTE**: **pubKey** and **priKey** cannot be **null** at the same time.|

**Return value**

| Type             | Description                             |
| ----------------- | --------------------------------- |
| [KeyPair](#keypair) | Asymmetric key pair generated.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.         |
| 17620001 | memory error.          |
| 17630001 | crypto operation error.          |

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { BusinessError } from '@kit.BasicServicesKit';

let priKeyPkcs1Str1024: string  =
  "-----BEGIN RSA PRIVATE KEY-----\n"
  + "MIICXQIBAAKBgQCwIN3mr21+N96ToxnVnaS+xyK9cNRAHiHGgrbjHw6RAj3V+l+W\n"
  + "Y68IhIe3DudVlzE9oMjeOQwkMkq//HCxNlIlFR6O6pa0mrXSwPRE7YKG97CeKk2g\n"
  + "YOS8YEh8toAvm7xKbiLkXuuMlxrjP2j/mb5iI/UASFSPZiQ/IyxDr0AQaQIDAQAB\n"
  + "AoGAEvBFzBNa+7J4PXnRQlYEK/tvsd0bBZX33ceacMubHl6WVZbphltLq+fMTBPP\n"
  + "LjXmtpC+aJ7Lvmyl+wTi/TsxE9vxW5JnbuRT48rnZ/Xwq0eozDeEeIBRrpsr7Rvr\n"
  + "7ctrgzr4m4yMHq9aDgpxj8IR7oHkfwnmWr0wM3FuiVlj650CQQDineeNZ1hUTkj4\n"
  + "D3O+iCi3mxEVEeJrpqrmSFolRMb+iozrIRKuJlgcOs+Gqi2fHfOTTL7LkpYe8SVg\n"
  + "e3JxUdVLAkEAxvcZXk+byMFoetrnlcMR13VHUpoVeoV9qkv6CAWLlbMdgf7uKmgp\n"
  + "a1Yp3QPDNQQqkPvrqtfR19JWZ4uy1qREmwJALTU3BjyBoH/liqb6fh4HkWk75Som\n"
  + "MzeSjFIOubSYxhq5tgZpBZjcpvUMhV7Zrw54kwASZ+YcUJvmyvKViAm9NQJBAKF7\n"
  + "DyXSKrem8Ws0m1ybM7HQx5As6l3EVhePDmDQT1eyRbKp+xaD74nkJpnwYdB3jyyY\n"
  + "qc7A1tj5J5NmeEFolR0CQQCn76Xp8HCjGgLHw9vg7YyIL28y/XyfFyaZAzzK+Yia\n"
  + "akNwQ6NeGtXSsuGCcyyfpacHp9xy8qXQNKSkw03/5vDO\n"
  + "-----END RSA PRIVATE KEY-----\n";
  let publicPkcs1Str1024: string  =
  "-----BEGIN RSA PUBLIC KEY-----\n"
  + "MIGJAoGBALAg3eavbX433pOjGdWdpL7HIr1w1EAeIcaCtuMfDpECPdX6X5ZjrwiE\n"
  + "h7cO51WXMT2gyN45DCQySr/8cLE2UiUVHo7qlrSatdLA9ETtgob3sJ4qTaBg5Lxg\n"
  + "SHy2gC+bvEpuIuRe64yXGuM/aP+ZvmIj9QBIVI9mJD8jLEOvQBBpAgMBAAE=\n"
  + "-----END RSA PUBLIC KEY-----\n";
function TestConvertPemKeyBySync() {
  let asyKeyGenerator = cryptoFramework.createAsyKeyGenerator('RSA1024');
  try {
    let keyPairData = asyKeyGenerator.convertPemKeySync(publicPkcs1Str1024, priKeyPkcs1Str1024);
    if (keyPairData != null) {
      console.info('[Sync]: convert pem key pair success');
    } else {
      console.error("[Sync]: convert pem key pair result fail!");
    }
  } catch (e) {
    console.error(`Sync error, ${e.code}, ${e.message}`);
  }
}
```

## cryptoFramework.createAsyKeyGeneratorBySpec<sup>10+</sup>

createAsyKeyGeneratorBySpec(asyKeySpec: AsyKeySpec): AsyKeyGeneratorBySpec

Creates an **AsyKeyGenerator** instance based on the specified key parameter.

For details about the supported specifications, see [Asymmetric Key Generation and Conversion Specifications](../../security/CryptoArchitectureKit/crypto-asym-key-generation-conversion-spec.md).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Key.AsymKey

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 10 to 11 and SystemCapability.Security.CryptoFramework.Key.AsymKey since API version 12.

**Parameters**

| Name | Type  | Mandatory| Description                            |
| ------- | ------ | ---- | -------------------------------- |
| asyKeySpec | [AsyKeySpec](#asykeyspec10) | Yes  | Key parameters. The **AsyKeyGenerator** generates the public/private key based on the specified parameters.|

**Return value**

| Type                                           | Description                      |
| ----------------------------------------------- | -------------------------- |
| [AsyKeyGeneratorBySpec](#asykeygeneratorbyspec10) | Returns the **AsyKeyGenerator** instance created.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 801 | this operation is not supported. |
| 17620001 | memory error. |

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';

// Set the common parameters of the DSA1024 public and private keys.
function genDsa1024CommonSpecBigE() {
  let dsaCommonSpec: cryptoFramework.DSACommonParamsSpec = {
    algName: "DSA",
    specType: cryptoFramework.AsyKeySpecType.COMMON_PARAMS_SPEC,
    p: BigInt("0xed1501551b8ab3547f6355ffdc2913856ddeca198833dbd04f020e5f25e47c50e0b3894f7690a0d2ea5ed3a7be25c54292a698e1f086eb3a97deb4dbf04fcad2dafd94a9f35c3ae338ab35477e16981ded6a5b13d5ff20bf55f1b262303ad3a80af71aa6aa2354d20e9c82647664bdb6b333b7bea0a5f49d55ca40bc312a1729"),
    q: BigInt("0xd23304044019d5d382cfeabf351636c7ab219694ac845051f60b047b"),
    g: BigInt("0x2cc266d8bd33c3009bd67f285a257ba74f0c3a7e12b722864632a0ac3f2c17c91c2f3f67eb2d57071ef47aaa8f8e17a21ad2c1072ee1ce281362aad01dcbcd3876455cd17e1dd55d4ed36fa011db40f0bbb8cba01d066f392b5eaa9404bfcb775f2196a6bc20eeec3db32d54e94d87ecdb7a0310a5a017c5cdb8ac78597778bd"),
  }
  return dsaCommonSpec;
}

// Set full parameters of the DSA1024 key pair.
function genDsa1024KeyPairSpecBigE() {
  let dsaCommonSpec = genDsa1024CommonSpecBigE();
  let dsaKeyPairSpec: cryptoFramework.DSAKeyPairSpec = {
    algName: "DSA",
    specType: cryptoFramework.AsyKeySpecType.KEY_PAIR_SPEC,
    params: dsaCommonSpec,
    sk: BigInt("0xa2dd2adb2d11392c2541930f61f1165c370aabd2d78d00342e0a2fd9"),
    pk: BigInt("0xae6b5d5042e758f3fc9a02d009d896df115811a75b5f7b382d8526270dbb3c029403fafb8573ba4ef0314ea86f09d01e82a14d1ebb67b0c331f41049bd6b1842658b0592e706a5e4d20c14b67977e17df7bdd464cce14b5f13bae6607760fcdf394e0b73ac70aaf141fa4dafd736bd0364b1d6e6c0d7683a5de6b9221e7f2d6b"),
  }
  return dsaKeyPairSpec;
}

let asyKeyPairSpec = genDsa1024KeyPairSpecBigE(); // The JS input must be a positive number in big-endian format.
let asyKeyGeneratorBySpec = cryptoFramework.createAsyKeyGeneratorBySpec(asyKeyPairSpec);
```

## AsyKeyGeneratorBySpec<sup>10+</sup>

Provides APIs for using the **AsKeyGenerator**. Before using the APIs of this class, you need to use [createAsyKeyGeneratorBySpec()](#cryptoframeworkcreateasykeygeneratorbyspec10) to create an **AsyKeyGeneratorBySpec** instance.

### Attributes

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Key.AsymKey

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 10 to 11 and SystemCapability.Security.CryptoFramework.Key.AsymKey since API version 12.

| Name   | Type  | Readable| Writable| Description                      |
| ------- | ------ | ---- | ---- | -------------------------- |
| algName | string | Yes  | No  | Algorithm used by the asymmetric key generator.|

### generateKeyPair

generateKeyPair(callback: AsyncCallback\<KeyPair>): void

Generates an asymmetric key pair. This API uses an asynchronous callback to return the result.

If a key parameter of the [COMMON_PARAMS_SPEC](#asykeyspectype10) type is used to create the key generator, a key pair will be randomly generated. If a key parameter of the [KEY_PAIR_SPEC](#asykeyspectype10) type is used to create the key generator, you can obtain a key pair that is consistent with the specified key parameters.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Key.AsymKey

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 9 to 11 and SystemCapability.Security.CryptoFramework.Key.AsymKey since API version 12.

**Parameters**

| Name    | Type                   | Mandatory| Description                          |
| -------- | ----------------------- | ---- | ------------------------------ |
| callback | AsyncCallback\<[KeyPair](#keypair)> | Yes  | Callback invoked to return the key pair obtained.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message               |
| -------- | ----------------------- |
| 401 | invalid parameters. Possible causes: <br>Incorrect parameter types;         |
| 17620001 | memory error.           |
| 17630001 | crypto operation error. |

**Example**

<!--code_no_check-->
```ts
let asyKeyPairSpec: cryptoFramework.DSAKeyPairSpec; // Use DSA as an example. asyKeyPairSpec specifies full parameters of the private and public keys. The generation process is omitted here.
let asyKeyGeneratorBySpec = cryptoFramework.createAsyKeyGeneratorBySpec(asyKeyPairSpec);
asyKeyGeneratorBySpec.generateKeyPair((err, keyPair) => {
  if (err) {
    console.error("generateKeyPair: error.");
    return;
  }
  console.info('generateKeyPair: success.');
})
```

### generateKeyPair

generateKeyPair(): Promise\<KeyPair>

Generates an asymmetric key pair. This API uses a promise to return the result.

If a key parameter of the [COMMON_PARAMS_SPEC](#asykeyspectype10) type is used to create the key generator, a key pair will be randomly generated. If a key parameter of the [KEY_PAIR_SPEC](#asykeyspectype10) type is used to create the key generator, you can obtain a key pair that is consistent with the specified key parameters.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Key.AsymKey

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 9 to 11 and SystemCapability.Security.CryptoFramework.Key.AsymKey since API version 12.

**Return value**

| Type             | Description                             |
| ----------------- | --------------------------------- |
| Promise\<[KeyPair](#keypair)> | Promise used to return the key pair generated.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.        |
| 17620001 | memory error.          |
| 17630001 | crypto operation error. |

**Example**

<!--code_no_check-->
```ts
import { BusinessError } from '@kit.BasicServicesKit';

let asyKeyPairSpec: cryptoFramework.DSAKeyPairSpec; // Use DSA as an example. asyKeyPairSpec specifies full parameters of the private and public keys. The generation process is omitted here.
let asyKeyGeneratorBySpec = cryptoFramework.createAsyKeyGeneratorBySpec(asyKeyPairSpec);
let keyGenPromise = asyKeyGeneratorBySpec.generateKeyPair();
keyGenPromise.then(keyPair => {
  console.info('generateKeyPair success.');
}).catch((error: BusinessError) => {
  console.error("generateKeyPair error.");
});
```

### generateKeyPairSync<sup>12+</sup>

generateKeyPairSync(): KeyPair

Generates an asymmetric key pair. This API returns the result synchronously.

If a key parameter of the [COMMON_PARAMS_SPEC](#asykeyspectype10) type is used to create the key generator, a key pair will be randomly generated. If a key parameter of the [KEY_PAIR_SPEC](#asykeyspectype10) type is used to create the key generator, you can obtain a key pair that is consistent with the specified key parameters.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Key.AsymKey

**Return value**

| Type             | Description                             |
| ----------------- | --------------------------------- |
| [KeyPair](#keypair) | Asymmetric key pair generated.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.         |
| 17620001 | memory error.          |
| 17630001 | crypto operation error. |

**Example**

<!--code_no_check-->
```ts
import { BusinessError } from '@kit.BasicServicesKit';

let asyKeyPairSpec: cryptoFramework.DSAKeyPairSpec; // Use DSA as an example. asyKeyPairSpec specifies full parameters of the private and public keys. The generation process is omitted here.
let asyKeyGeneratorBySpec = cryptoFramework.createAsyKeyGeneratorBySpec(asyKeyPairSpec);
try {
  let keyPairData = asyKeyGeneratorBySpec.generateKeyPairSync();
  if (keyPairData != null) {
    console.info('[Sync]: key pair success');
  } else {
    console.error("[Sync]: get key pair result fail!");
  }
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`sync error, ${e.code}, ${e.message}`);
}
```

### generatePriKey

generatePriKey(callback: AsyncCallback\<PriKey>): void

Generates an asymmetric key pair. This API uses an asynchronous callback to return the result.

If a key parameter of the [PRIVATE_KEY_SPEC](#asykeyspectype10) type is used to create the key generator, the specified private key can be obtained. If a key parameter of the [KEY_PAIR_SPEC](#asykeyspectype10) type is used to create the key generator, you can obtain the specified private key from the key pair generated.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Key.AsymKey

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 9 to 11 and SystemCapability.Security.CryptoFramework.Key.AsymKey since API version 12.

**Parameters**

| Name    | Type                   | Mandatory| Description                          |
| -------- | ----------------------- | ---- | ------------------------------ |
| callback | AsyncCallback\<[PriKey](#prikey)> | Yes  | Callback invoked to return the key pair obtained.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | invalid parameters. Possible causes: <br>Mandatory parameters are left unspecified;         |
| 17620001 | memory error.          |
| 17630001 | crypto operation error. |

**Example**

<!--code_no_check-->
```ts
let asyKeyPairSpec: cryptoFramework.DSAKeyPairSpec; // Use DSA as an example. asyKeyPairSpec specifies full parameters of the private and public keys. The generation process is omitted here.
let asyKeyGeneratorBySpec = cryptoFramework.createAsyKeyGeneratorBySpec(asyKeyPairSpec);
asyKeyGeneratorBySpec.generatePriKey((err, prikey) => {
  if (err) {
    console.error("generatePriKey: error.");
    return;
  }
  console.info('generatePriKey: success.');
})
```

### generatePriKey

generatePriKey(): Promise\<PriKey>

Generates an asymmetric key pair. This API uses a promise to return the result.

If a key parameter of the [PRIVATE_KEY_SPEC](#asykeyspectype10) type is used to create the key generator, the specified private key can be obtained. If a key parameter of the [KEY_PAIR_SPEC](#asykeyspectype10) type is used to create the key generator, you can obtain the specified private key from the key pair generated.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Key.AsymKey

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 9 to 11 and SystemCapability.Security.CryptoFramework.Key.AsymKey since API version 12.

**Return value**

| Type             | Description                             |
| ----------------- | --------------------------------- |
| Promise\<[PriKey](#prikey)> | Promise used to return the key pair generated.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.         |
| 17620001 | memory error.          |
| 17630001 | crypto operation error. |

**Example**

<!--code_no_check-->
```ts
import { BusinessError } from '@kit.BasicServicesKit';

let asyKeyPairSpec: cryptoFramework.DSAKeyPairSpec; // Use DSA as an example. asyKeyPairSpec specifies full parameters of the private and public keys. The generation process is omitted here.
let asyKeyGeneratorBySpec = cryptoFramework.createAsyKeyGeneratorBySpec(asyKeyPairSpec);
let keyGenPromise = asyKeyGeneratorBySpec.generatePriKey();
keyGenPromise.then(priKey => {
  console.info('generatePriKey success.');
}).catch((error: BusinessError) => {
  console.error("generatePriKey error.");
});
```

### generatePriKeySync<sup>12+</sup>

generatePriKeySync(): PriKey

Generates a private key randomly. This API returns the result synchronously.

If a key parameter of the [PRIVATE_KEY_SPEC](#asykeyspectype10) type is used to create the key generator, a private key can be obtained. If a key parameter of the [KEY_PAIR_SPEC](#asykeyspectype10) type is used to create the key generator, you can obtain the private key from the key pair generated.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Key.AsymKey

**Return value**

| Type             | Description                             |
| ----------------- | --------------------------------- |
| [PriKey](#prikey) | Private key generated.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.        |
| 17620001 | memory error.          |
| 17630001 | crypto operation error. |

**Example**

<!--code_no_check-->
```ts
let asyKeyPairSpec: cryptoFramework.DSAKeyPairSpec; // Use DSA as an example. asyKeyPairSpec specifies full parameters of the private and public keys. The generation process is omitted here.
let asyKeyGeneratorBySpec = cryptoFramework.createAsyKeyGeneratorBySpec(asyKeyPairSpec);
try {
  let priKeyData = asyKeyGeneratorBySpec.generatePriKeySync();
  if (priKeyData != null) {
    console.info('[Sync]: pri key success');
  } else {
    console.error("[Sync]: get pri key result fail!");
  }
} catch (e) {
  console.error(`sync error, ${e.code}, ${e.message}`);
}
```

### generatePubKey

generatePubKey(callback: AsyncCallback\<PubKey>): void

Generates an asymmetric key pair. This API uses an asynchronous callback to return the result.

If a key parameter of the [PUBLIC_KEY_SPEC](#asykeyspectype10) type is used to create the key generator, the specified public key can be obtained. If a key parameter of the [KEY_PAIR_SPEC](#asykeyspectype10) type is used to create the key generator, you can obtain the specified public key from the key pair generated.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Key.AsymKey

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 9 to 11 and SystemCapability.Security.CryptoFramework.Key.AsymKey since API version 12.

**Parameters**

| Name    | Type                   | Mandatory| Description                          |
| -------- | ----------------------- | ---- | ------------------------------ |
| callback | AsyncCallback\<[PubKey](#pubkey)> | Yes  | Callback invoked to return the key pair obtained.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | invalid parameters. Possible causes:<br> Incorrect parameter types;        |
| 17620001 | memory error.          |
| 17630001 | crypto operation error. |

**Example**

<!--code_no_check-->
```ts
let asyKeyPairSpec: cryptoFramework.DSAKeyPairSpec; // Use DSA as an example. asyKeyPairSpec specifies full parameters of the private and public keys. The generation process is omitted here.
let asyKeyGeneratorBySpec = cryptoFramework.createAsyKeyGeneratorBySpec(asyKeyPairSpec);
asyKeyGeneratorBySpec.generatePubKey((err, pubKey) => {
  if (err) {
    console.error("generatePubKey: error.");
    return;
  }
  console.info('generatePubKey: success.');
})
```

### generatePubKey

generatePubKey(): Promise\<PubKey>

Generates an asymmetric key pair. This API uses a promise to return the result.

If a key parameter of the [PUBLIC_KEY_SPEC](#asykeyspectype10) type is used to create the key generator, the specified public key can be obtained. If a key parameter of the [KEY_PAIR_SPEC](#asykeyspectype10) type is used to create the key generator, you can obtain the specified public key from the key pair generated.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Key.AsymKey

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 9 to 11 and SystemCapability.Security.CryptoFramework.Key.AsymKey since API version 12.

**Return value**

| Type             | Description                             |
| ----------------- | --------------------------------- |
| Promise\<[PubKey](#pubkey)> | Promise used to return the key pair generated.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.         |
| 17620001 | memory error.          |
| 17630001 | crypto operation error. |

**Example**

<!--code_no_check-->
```ts
import { BusinessError } from '@kit.BasicServicesKit';

let asyKeyPairSpec: cryptoFramework.DSAKeyPairSpec; // Use DSA as an example. asyKeyPairSpec specifies full parameters of the private and public keys. The generation process is omitted here.
let asyKeyGeneratorBySpec = cryptoFramework.createAsyKeyGeneratorBySpec(asyKeyPairSpec);
let keyGenPromise = asyKeyGeneratorBySpec.generatePubKey();
keyGenPromise.then(pubKey => {
  console.info('generatePubKey success.');
}).catch((error: BusinessError) => {
  console.error("generatePubKey error.");
});
```

### generatePubKeySync<sup>12+</sup>

generatePubKeySync(): PubKey

Generates a public key. This API returns the result synchronously.

If a key parameter of the [PUBLIC_KEY_SPEC](#asykeyspectype10) type is used to create the key generator, the specified public key can be obtained. If a key parameter of the [KEY_PAIR_SPEC](#asykeyspectype10) type is used to create the key generator, you can obtain the specified public key from the key pair generated.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Key.AsymKey

**Return value**

| Type             | Description                             |
| ----------------- | --------------------------------- |
| [PubKey](#pubkey) | Private key generated.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.        |
| 17620001 | memory error.          |
| 17630001 | crypto operation error. |

**Example**

<!--code_no_check-->
```ts
let asyKeyPairSpec: cryptoFramework.DSAKeyPairSpec; // Use DSA as an example. asyKeyPairSpec specifies full parameters of the private and public keys. The generation process is omitted here.
let asyKeyGeneratorBySpec = cryptoFramework.createAsyKeyGeneratorBySpec(asyKeyPairSpec);
try {
  let pubKeyData = asyKeyGeneratorBySpec.generatePubKeySync();
  if (pubKeyData != null) {
    console.info('[Sync]: pub key success');
  } else {
    console.error("[Sync]: get pub key result fail!");
  }
} catch (e) {
  console.error(`sync error, ${e.code}, ${e.message}`);
}
```

## ECCKeyUtil<sup>11+</sup>

Provides APIs for generating common parameters for an asymmetric key pair based on the elliptic curve name.

### genECCCommonParamsSpec<sup>11+</sup>

static genECCCommonParamsSpec(curveName: string): ECCCommonParamsSpec

Generates common parameters for an asymmetric key pair based on the specified name identifier (NID) of an elliptic curve. For details, see [ECC](../../security/CryptoArchitectureKit/crypto-asym-key-generation-conversion-spec.md#ecc) and [SM2](../../security/CryptoArchitectureKit/crypto-asym-key-generation-conversion-spec.md#sm2).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Key.AsymKey

The supported system capability is SystemCapability.Security.CryptoFramework in API version 11 and SystemCapability.Security.CryptoFramework.Key.AsymKey since API version 12.

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
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 801      | this operation is not supported. |
| 17620001 | memory error.                    |

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { BusinessError } from '@kit.BasicServicesKit';
try {
    let ECCCommonParamsSpec = cryptoFramework.ECCKeyUtil.genECCCommonParamsSpec('NID_brainpoolP160r1');
    console.info('genECCCommonParamsSpec success');
} catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error(`genECCCommonParamsSpec error, ${e.code}, ${e.message}`);
}
```

### convertPoint<sup>12+</sup>

static convertPoint(curveName: string, encodedPoint: Uint8Array): Point

Converts the specified point data into a **Point** object based on the curve name, that is, Name IDentifier (NID). Currently, compressed and uncompressed point data is supported. 

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
| curveName    | string     | Yes  | Elliptic curve name that is, the NID.|
| encodedPoint | Uint8Array | Yes  | Data of the point on the ECC elliptic curve to convert.|

**Return value**

| Type             | Description                |
| ----------------- | ------------------- |
| [Point](#point10) | **Point** object obtained.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | memory error. |
| 17630001 | crypto operation error. |

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';

// Randomly generated uncompressed point data.
let pkData = new Uint8Array([4, 143, 39, 57, 249, 145, 50, 63, 222, 35, 70, 178, 121, 202, 154, 21, 146, 129, 75, 76, 63, 8, 195, 157, 111, 40, 217, 215, 148, 120, 224, 205, 82, 83, 92, 185, 21, 211, 184, 5, 19, 114, 33, 86, 85, 228, 123, 242, 206, 200, 98, 178, 184, 130, 35, 232, 45, 5, 202, 189, 11, 46, 163, 156, 152]);
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
| curveName    | string            | Yes  | Elliptic curve name that is, the NID.|
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
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | memory error. |
| 17630001 | crypto operation error. |

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

Provides APIs for generating common parameters for a DH key based on the prime **p** length and the private key length.

### genDHCommonParamsSpec<sup>11+</sup>

static genDHCommonParamsSpec(pLen: number, skLen?: number): DHCommonParamsSpec

Generates common parameters for a DH key based on the prime **p** length and the private key length. For details, see [DH](../../security/CryptoArchitectureKit/crypto-asym-key-generation-conversion-spec.md#dh).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Key.AsymKey

The supported system capability is SystemCapability.Security.CryptoFramework in API version 11 and SystemCapability.Security.CryptoFramework.Key.AsymKey since API version 12.

**Parameters**

| Name| Type  | Mandatory| Description                                            |
| ------ | ------ | ---- | ------------------------------------------------ |
| pLen   | number | Yes  | Length of the prime **p**, in bits.|
| skLen  | number | No  | Length of the private key, in bits. |

**Return value**

| Type             | Description                             |
| ----------------- | --------------------------------- |
| [DHCommonParamsSpec](#dhcommonparamsspec11) | DH common parameters generated.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 801      | this operation is not supported. |
| 17620001 | memory error.                    |
| 17630001 | crypto operation error.          |

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { BusinessError } from '@kit.BasicServicesKit';
try {
    let DHCommonParamsSpec = cryptoFramework.DHKeyUtil.genDHCommonParamsSpec(2048);
    console.info('genDHCommonParamsSpec success');
} catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error(`genDHCommonParamsSpec error, ${e.code}, ${e.message}`);
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
| mode  | string | No  | Order of the SM2 parameters in the ciphertext. Currently, only C1C3C2 is supported. |

**Return value**

| Type             | Description                             |
| ----------------- | --------------------------------- |
| [DataBlob](#datablob) | SM2 ciphertext in ASN.1 format.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | memory error.                    |
| 17630001 | crypto operation error.          |

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { BusinessError } from '@kit.BasicServicesKit';
try {
  let spec : cryptoFramework.SM2CipherTextSpec = {
    xCoordinate: BigInt('20625015362595980457695435345498579729138244358573902431560627260141789922999'),
    yCoordinate: BigInt('48563164792857017065725892921053777369510340820930241057309844352421738767712'),
    cipherTextData: new Uint8Array([100,227,78,195,249,179,43,70,242,69,169,10,65,123]),
    hashData: new Uint8Array([87,167,167,247,88,146,203,234,83,126,117,129,52,142,82,54,152,226,201,111,143,115,169,125,128,42,157,31,114,198,109,244]),
  }
  let data = cryptoFramework.SM2CryptoUtil.genCipherTextBySpec(spec, 'C1C3C2');
  console.info('genCipherTextBySpec success');
} catch (err) {
  let e: BusinessError = err as BusinessError;
  console.error(`genCipherTextBySpec error, ${e.code}, ${e.message}`);
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
| cipherText     | [DataBlob](#datablob)                 | Yes  | SM2 ciphertext in ASN.1 format.
| mode  | string | No  | Order of the SM2 parameters in the ciphertext. Currently, only C1C3C2 is supported. |

**Return value**

| Type             | Description                             |
| ----------------- | --------------------------------- |
| [SM2CipherTextSpec](#sm2ciphertextspec12) | SM2 ciphertext parameters obtained.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | memory error.                    |
| 17630001 | crypto operation error.          |

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { BusinessError } from '@kit.BasicServicesKit';
try {
    let cipherTextArray = new Uint8Array([48,118,2,32,45,153,88,82,104,221,226,43,174,21,122,248,5,232,105,41,92,95,102,224,216,149,85,236,110,6,64,188,149,70,70,183,2,32,107,93,198,247,119,18,40,110,90,156,193,158,205,113,170,128,146,109,75,17,181,109,110,91,149,5,110,233,209,78,229,96,4,32,87,167,167,247,88,146,203,234,83,126,117,129,52,142,82,54,152,226,201,111,143,115,169,125,128,42,157,31,114,198,109,244,4,14,100,227,78,195,249,179,43,70,242,69,169,10,65,123]);
    let cipherText : cryptoFramework.DataBlob = {data : cipherTextArray};
    let spec : cryptoFramework.SM2CipherTextSpec = cryptoFramework.SM2CryptoUtil.getCipherTextSpec(cipherText, 'C1C3C2');
    console.info('getCipherTextSpec success');
} catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error(`getCipherTextSpec error, ${e.code}, ${e.message}`);
}
```

## cryptoFramework.createCipher

createCipher(transformation: string): Cipher

Creates a [Cipher](#cipher) instance based on the specified algorithm.

For details about the supported specifications, see [Symmetric Key Encryption and Decryption Algorithm Specifications](../../security/CryptoArchitectureKit/crypto-sym-encrypt-decrypt-spec.md) and [Asymmetric Key Encryption and Decryption Algorithm Specifications](../../security/CryptoArchitectureKit/crypto-asym-encrypt-decrypt-spec.md).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Cipher

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 9 to 11 and SystemCapability.Security.CryptoFramework.Cipher since API version 12.

**Parameters**

| Name        | Type  | Mandatory| Description                                                        |
| -------------- | ------ | ---- | ------------------------------------------------------------ |
| transformation | string | Yes  | Combination of the algorithm name (including the key length), encryption mode, and padding algorithm of the **Cipher** instance to create.|

> **NOTE**
>
> 1. In symmetric encryption and decryption, the implementation of PKCS #5 is the same as that of PKCS #7. PKCS #5 and PKCS #7 use the same padding length and block length. That is, data is padded with 8 bytes in 3DES and 16 bytes in AES. **noPadding** indicates that no padding is performed.
> You need to understand the differences between different block cipher modes and use the correct parameter specifications. For example, padding is required for ECB and CBC. Otherwise, ensure that the plaintext length is an integer multiple of the block size. No padding is recommended for other modes. In this case, the ciphertext length is the same as the plaintext length.
> 2. When RSA or SM2 is used for asymmetric encryption and decryption, create a **Cipher** instance for encryption and decryption respectively. Do not use the same **Cipher** instance for encryption and decryption. For symmetric encryption and decryption, one **cipher** object can be used to perform both encryption and decryption as long as the algorithm specifications are the same.

**Return value**

| Type             | Description                    |
| ----------------- | ------------------------ |
| [Cipher](#cipher) | [Cipher](#cipher) instance created.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 801 | this operation is not supported. |
| 17620001 | memory error.          |

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
  console.error(`sync error, ${e.code}, ${e.message}`);
}
```

## Cipher

Provides APIs for cipher operations. The [init()](#init-1), [update()](#update), and [doFinal()](#dofinal) APIs in this class are called in sequence to implement symmetric encryption or decryption and asymmetric encryption or decryption.

For details about the encryption and decryption process, see [Encryption and Decryption Overview](../../security/CryptoArchitectureKit/crypto-encryption-decryption-overview.md).

A complete symmetric encryption/decryption process is slightly different from the asymmetric encryption/decryption process.

- Symmetric encryption and decryption: **init()** and **doFinal()** are mandatory. **update()** is optional and can be called multiple times to encrypt or decrypt big data. After **doFinal()** is called to complete an encryption or decryption operation, **init()** can be called to start a new encryption or decryption operation.
- RSA or SM2 asymmetric encryption and decryption: **init()** and **doFinal()** are mandatory, and **update()** is not supported. **doFinal()** can be called multiple times to encrypt or decrypt big data. **init()** cannot be called repeatedly. If the encryption/decryption mode or padding mode is changed, a new **Cipher** object must be created.

### Attributes

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Cipher

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 9 to 11 and SystemCapability.Security.CryptoFramework.Cipher since API version 12.

| Name   | Type  | Readable| Writable| Description                        |
| ------- | ------ | ---- | ---- | ---------------------------- |
| algName | string | Yes  | No  | Algorithm.|

### init

init(opMode: CryptoMode, key: Key, params: ParamsSpec | null, callback: AsyncCallback\<void>): void

Initializes a [cipher](#cipher) instance. This API uses an asynchronous callback to return the result. **init**, **update**, and **doFinal** must be used together. **init** and **doFinal** are mandatory, and **update** is optional.

This API can be used only after a [Cipher](#cipher) instance is created by using [createCipher](#cryptoframeworkcreatecipher).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Cipher

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 9 to 11 and SystemCapability.Security.CryptoFramework.Cipher since API version 12.

**Parameters**

| Name    | Type                     | Mandatory| Description                                                        |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| opMode   | [CryptoMode](#cryptomode) | Yes  | Operation (encryption or decryption) to perform.                                          |
| key      | [Key](#key)               | Yes  | Key for encryption or decryption.                                      |
| params   | [ParamsSpec](#paramsspec) \| null<sup>10+</sup> | Yes  | Parameters for encryption or decryption. For algorithm modes without parameters (such as ECB), **null** can be passed in. In versions earlier than API version 10, only **ParamsSpec** is supported. Since API version 10, **null** is also supported.|
| callback | AsyncCallback\<void>      | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.    |

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message                                                |
| -------- | --------------------------------------------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | memory error.                                            |
| 17620002 | runtime error.                                           |
| 17630001 | crypto operation error.|

### init

init(opMode: CryptoMode, key: Key, params: ParamsSpec | null): Promise\<void>

Initializes a [cipher](#cipher) instance. This API uses a promise to return the result. **init**, **update**, and **doFinal** must be used together. **init** and **doFinal** are mandatory, and **update** is optional.

This API can be used only after a [Cipher](#cipher) instance is created by using [createCipher](#cryptoframeworkcreatecipher).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Cipher

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 9 to 11 and SystemCapability.Security.CryptoFramework.Cipher since API version 12.

**Parameters**

| Name  | Type                     | Mandatory| Description                                                        |
| ------ | ------------------------- | ---- | ------------------------------------------------------------ |
| opMode | [CryptoMode](#cryptomode) | Yes  | Operation (encryption or decryption) to perform.                                          |
| key    | [Key](#key)               | Yes  | Key for encryption or decryption.                                      |
| params | [ParamsSpec](#paramsspec) \| null<sup>10+</sup> | Yes  | Parameters for encryption or decryption. For algorithm modes without parameters (such as ECB), **null** can be passed in. In versions earlier than API version 10, only **ParamsSpec** is supported. Since API version 10, **null** is also supported.|

**Return value**

| Type          | Description                                  |
| -------------- | -------------------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | memory error.                                     |
| 17620002 | runtime error.                                    |
| 17630001 | crypto operation error.|

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
| params | [ParamsSpec](#paramsspec)  | Yes  | Parameters for encryption or decryption. For algorithm modes without parameters (such as ECB), **null** can be passed in.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message               |
| -------- | ----------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | memory error.           |
| 17620002 | runtime error.          |
| 17630001 | crypto operation error. |

### update

update(data: DataBlob, callback: AsyncCallback\<DataBlob>): void

Updates the data to encrypt or decrypt by segment. This API uses an asynchronous callback to return the encrypted or decrypted data.

This API can be called only after the [Cipher](#cipher) instance is initialized by using [init()](#init-1).

> **NOTE**
>
> 1. The **update()** and **doFinal()** operation results vary with the block mode used. If you are not familiar with the block modes for symmetric encryption and decryption, add a judgment to determine whether the result of each **update()** and **doFinal()** is null. If the result is not null, obtain and combine the data segments into complete ciphertext or plaintext.  <br>For example, in ECB or CBC mode, data is encrypted or decrypted by block no matter whether the data passed in by **update()** is an integer multiple of the block length, and the data generated by this **update()** is output.<br>That is, data is returned as long as the data passed in by **update()** reaches the size of a block. Otherwise, **null** is returned and the data will be retained until a block is formed in the next **update()**/**doFinal()**.<br>When **doFinal()** is called, the data that has not been encrypted or decrypted will be padded based on the padding mode set in [createCipher](#cryptoframeworkcreatecipher) to an integer multiple of the block length, and then encrypted or decrypted.<br>For a mode in which a block cipher can be converted into a stream cipher, the length of the ciphertext may be the same as that of the plaintext.
> 2. You can use **update()** multiple times or do not use it (use **doFinal()** after **init()**), depending on the data volume.<br>
>    The amount of the data to be passed in by **update** (one-time or accumulative) is not limited. If there is a large amount of data, you are advised to call **update()** multiple times to pass in the data by segment.<br>
>    For details about the sample code for calling **update** multiple times, see [Encryption and Decryption by Segment with an AES Symmetric Key (GCM Mode)](../../security/CryptoArchitectureKit/crypto-aes-sym-encrypt-decrypt-gcm-by-segment.md).
> 3. RSA or SM2 asymmetric encryption and decryption do not support **update()**.
> 4. If CCM is used in symmetric encryption or decryption, **update()** can be called only once. In the encryption process, you can either use **update()** to encrypt data and use **doFinal()** to obtain **authTag** or use **doFinal()** without using **update()**. In the decryption process, you can either use **update()** once or use **doFinal()** to decrypt data and verify the tag.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Cipher

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 9 to 11 and SystemCapability.Security.CryptoFramework.Cipher since API version 12.

**Parameters**

| Name    | Type                                 | Mandatory| Description                                                        |
| -------- | ------------------------------------- | ---- | ------------------------------------------------------------ |
| data     | [DataBlob](#datablob)                 | Yes  | Data to encrypt or decrypt. It cannot be null.          |
| callback | AsyncCallback\<[DataBlob](#datablob)> | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **undefined**, and **data** is **DataBlob** (containing the encrypted or decrypted data). Otherwise, **err** is an error object.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | memory error.                               |
| 17620002 | runtime error.                              |
| 17630001 | crypto operation error.                     |

### update

update(data: DataBlob): Promise\<DataBlob>

Updates the data to encrypt or decrypt by segment. This API uses a promise to return the encrypted or decrypted data.

This API can be called only after the [Cipher](#cipher) instance is initialized by using [init()](#init-2).

> **NOTE**
>
> 1. The **update()** and **doFinal()** operation results vary with the block mode used. If you are not familiar with the block modes for symmetric encryption and decryption, add a judgment to determine whether the result of each **update()** and **doFinal()** is null. If the result is not null, obtain and combine the data segments into complete ciphertext or plaintext.  
> <br>For example, in ECB or CBC mode, data is encrypted or decrypted by block no matter whether the data passed in by **update()** is an integer multiple of the block length, and the data generated by this **update()** is output.<br>That is, data is returned as long as the data passed in by **update()** reaches the size of a block. Otherwise, **null** is returned and the data will be retained until a block is formed in the next **update()**/**doFinal()**.<br>When **doFinal()** is called, the data that has not been encrypted or decrypted will be padded based on the padding mode set in [createCipher](#cryptoframeworkcreatecipher) to an integer multiple of the block length, and then encrypted or decrypted.<br>For a mode in which a block cipher can be converted into a stream cipher, the length of the ciphertext may be the same as that of the plaintext.
> 2. You can use **update()** multiple times or do not use it (use **doFinal()** after **init()**), depending on the data volume.<br>
>    The amount of the data to be passed in by **update()** (one-time or accumulative) is not limited. If there is a large amount of data, you are advised to call **update()** multiple times to pass in the data by segment.<br>
>    For details about the sample code for calling **update()** multiple times, see [Encryption and Decryption by Segment with an AES Symmetric Key (GCM Mode)](../../security/CryptoArchitectureKit/crypto-aes-sym-encrypt-decrypt-gcm-by-segment.md).
> 3. RSA or SM2 asymmetric encryption and decryption do not support **update()**.
> 4. If CCM is used in symmetric encryption or decryption, **update()** can be called only once. In the encryption process, you can either use **update()** to encrypt data and use **doFinal()** to obtain **authTag** or use **doFinal()** without using **update()**. In the decryption process, you can either use **update()** once or use **doFinal()** to decrypt data and verify the tag.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Cipher

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 9 to 11 and SystemCapability.Security.CryptoFramework.Cipher since API version 12.

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
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | memory error.                                |
| 17620002 | runtime error.                               |
| 17630001 | crypto operation error.                      |

### updateSync<sup>12+</sup>

updateSync(data: DataBlob): DataBlob

Updates the data to encrypt or decrypt by segment. This API returns the encrypted or decrypted data synchronously.

This API can be called only after the [Cipher](#cipher) instance is initialized by using [initSync()](#initsync12).

See **NOTE** in **update()** for other precautions.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Cipher

**Parameters**

| Name| Type                 | Mandatory| Description                                                        |
| ------ | --------------------- | ---- | ------------------------------------------------------------ |
| data   | [DataBlob](#datablob) | Yes  | Data to encrypt or decrypt. It cannot be null.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message               |
| -------- | ----------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | memory error.           |
| 17620002 | runtime error.          |
| 17630001 | crypto operation error. |

### doFinal

doFinal(data: DataBlob | null, callback: AsyncCallback\<DataBlob>): void

 (1) Encrypts or decrypts the remaining data (generated by the block cipher mode) and the data passed in by **doFinal()** to finalize the symmetric encryption or decryption. This API uses an asynchronous callback to return the encrypted or decrypted data.<br>If a small amount of data needs to be encrypted or decrypted, you can use **doFinal()** to pass in data without using **update()**. If all the data has been passed in by [update()](#update-4), you can pass in **null** in **data** of **doFinal()**.<br>The output of **doFinal()** varies with the symmetric encryption/decryption mode in use.

- Symmetric encryption in GCM and CCM mode: The result consists of the ciphertext and **authTag** (the last 16 bytes for GCM and the last 12 bytes for CCM). If **null** is passed in by **data** of **doFinal()**, the result of **doFinal()** is **authTag**. **authTag** must be [GcmParamsSpec](#gcmparamsspec) or [CcmParamsSpec](#ccmparamsspec) used for decryption. The ciphertext is the **data** passed in for decryption.
- Symmetric encryption and decryption in other modes and symmetric decryption in GCM and CCM modes: The result is the complete plaintext/ciphertext.

 (2) Encrypts or decrypts the input data for RSA or SM2 asymmetric encryption/decryption. This API uses an asynchronous callback to return the result. If a large amount of data needs to be encrypted/decrypted, call **doFinal()** multiple times and concatenate the result of each **doFinal()** to obtain the complete plaintext/ciphertext.

> **NOTE**
>
>  1. In symmetric encryption and decryption, after **doFinal** is called, the encryption and decryption process is complete and the [Cipher](#cipher) instance is cleared. When a new encryption and decryption process is started, **init()** must be called with a complete parameter list for initialization.<br>Even if the same symmetric key is used to encrypt and decrypt the same **Cipher** instance, the **params** parameter must be set when **init** is called during decryption.
>  2. If a decryption fails, check whether the data to be encrypted and decrypted matches the parameters in **init()**. For the GCM mode, check whether the **authTag** obtained after encryption is obtained from the **GcmParamsSpec** for decryption.
>  3. The result of **doFinal()** may be **null**. To avoid exceptions, determine whether the result is **null** before using the **.data** field to access the **doFinal()** result.
>  4. For details about the sample code for calling **doFinal** multiple times in asymmetric encryption and decryption, see [Encryption and Decryption by Segment with an RSA Asymmetric Key Pair](../../security/CryptoArchitectureKit/crypto-rsa-asym-encrypt-decrypt-by-segment.md). The operations are similar for SM2 and RSA.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Cipher

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 9 to 11 and SystemCapability.Security.CryptoFramework.Cipher since API version 12.

**Parameters**

| Name    | Type                                 | Mandatory| Description                                                        |
| -------- | ------------------------------------- | ---- | ------------------------------------------------------------ |
| data     | [DataBlob](#datablob) \| null<sup>10+</sup>                 | Yes  | Data to encrypt or decrypt. It can be **null** in symmetric encryption or decryption, but cannot be {data:Uint8Array(empty)}. In versions earlier than API version 10, only **DataBlob** is supported. Since API version 10, **null** is also supported.      |
| callback | AsyncCallback\<[DataBlob](#datablob)> | Yes  | Callback invoked to return the result. If the data is successfully encrypted or decrypted, **err** is **undefined**, and **data** is the **DataBlob** (encryption or decryption result of the remaining data). Otherwise, **err** is an error object.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message               |
| -------- | ----------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | memory error.           |
| 17620002 | runtime error.          |
| 17630001 | crypto operation error. |

**Encryption with AES GCM (example)**

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
    algName: "GcmParamsSpec"
  };
  return gcmParamsSpec;
}

function cipherByCallback() {
  let gcmParams = genGcmParamsSpec();
  let symKeyGenerator = cryptoFramework.createSymKeyGenerator('AES128');
  let cipher = cryptoFramework.createCipher('AES128|GCM|PKCS7');
  symKeyGenerator.generateSymKey((err, symKey) => {
    cipher.init(cryptoFramework.CryptoMode.ENCRYPT_MODE, symKey, gcmParams, (err,) => {
      let message = "This is a test";
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

doFinal(data: DataBlob | null): Promise\<DataBlob>

 (1) Encrypts or decrypts the remaining data (generated by the block cipher mode) and the data passed in by **doFinal()** to finalize the symmetric encryption or decryption. This API uses a promise to return the encrypted or decrypted data.<br>If a small amount of data needs to be encrypted or decrypted, you can use **doFinal()** to pass in data without using **update()**. If all the data has been passed in by **update()**, you can pass in **null** in **data** of **doFinal()**.<br>The output of **doFinal()** varies with the symmetric encryption/decryption mode in use.

- Symmetric encryption in GCM and CCM mode: The result consists of the ciphertext and **authTag** (the last 16 bytes for GCM and the last 12 bytes for CCM). If **data** in **doFinal** is null, the result of **doFinal** is **authTag**.<br>Set **authTag** to [GcmParamsSpec](#gcmparamsspec) or [CcmParamsSpec](#ccmparamsspec) for decryption. The ciphertext is used as the input parameter **data** for decryption.
- Symmetric encryption and decryption in other modes and symmetric decryption in GCM and CCM modes: The result is the complete plaintext/ciphertext.

 (2) Encrypts or decrypts the input data for RSA or SM2 asymmetric encryption/decryption. This API uses a promise to return the result. If a large amount of data needs to be encrypted/decrypted, call **doFinal()** multiple times and concatenate the result of each **doFinal()** to obtain the complete plaintext/ciphertext.

> **NOTE**
>
>  1. In symmetric encryption and decryption, after **doFinal** is called, the encryption and decryption process is complete and the [Cipher](#cipher) instance is cleared. When a new encryption and decryption process is started, **init()** must be called with a complete parameter list for initialization.<br>Even if the same symmetric key is used to encrypt and decrypt the same **Cipher** instance, the **params** parameter must be set when **init** is called during decryption.
>  2. If a decryption fails, check whether the data to be encrypted and decrypted matches the parameters in **init()**. For the GCM mode, check whether the **authTag** obtained after encryption is obtained from the **GcmParamsSpec** for decryption.
>  3. The result of **doFinal()** may be **null**. To avoid exceptions, determine whether the result is **null** before using the **.data** field to access the **doFinal()** result.
>  4. For details about the sample code for calling **doFinal** multiple times in asymmetric encryption and decryption, see [Encryption and Decryption by Segment with an RSA Asymmetric Key Pair](../../security/CryptoArchitectureKit/crypto-rsa-asym-encrypt-decrypt-by-segment.md). The operations are similar for SM2 and RSA.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Cipher

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 9 to 11 and SystemCapability.Security.CryptoFramework.Cipher since API version 12.

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
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | memory error.                                |
| 17620002 | runtime error.                               |
| 17630001 | crypto operation error.                      |

**Encryption with AES GCM (example)**

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
    algName: "GcmParamsSpec"
  };
  return gcmParamsSpec;
}

async function cipherByPromise() {
  let gcmParams = genGcmParamsSpec();
  let symKeyGenerator = cryptoFramework.createSymKeyGenerator('AES128');
  let cipher = cryptoFramework.createCipher('AES128|GCM|PKCS7');
  let symKey = await symKeyGenerator.generateSymKey();
  await cipher.init(cryptoFramework.CryptoMode.ENCRYPT_MODE, symKey, gcmParams);
  let message = "This is a test";
  let plainText: cryptoFramework.DataBlob = { data: new Uint8Array(buffer.from(message, 'utf-8').buffer) };
  let encryptUpdate = await cipher.update(plainText);
  gcmParams.authTag = await cipher.doFinal(null);
  console.info('encryptUpdate plainText: ' + encryptUpdate.data);
}
```

### doFinalSync<sup>12+</sup>

doFinalSync(data: DataBlob | null): DataBlob

 (1) Encrypts or decrypts the remaining data (generated by the block cipher mode) and the data passed in by **doFinalSync()** to finalize the symmetric encryption or decryption. This API returns the result synchronously.<br>If the data volume is small, you can pass in all the data in **doFinalSync** without using **updateSync**. If data has been passed using [updateSync](#updatesync12), you can pass in **null** in **doFinalSync**.<br>The output of **doFinalSync** varies with the symmetric cipher mode in use.

- Symmetric encryption in GCM and CCM mode: The result consists of the ciphertext and **authTag** (the last 16 bytes for GCM and the last 12 bytes for CCM). If **data** in **doFinalSync** is **null**, the result of **doFinalSync** is **authTag**.<br>Set **authTag** to [GcmParamsSpec](#gcmparamsspec) or [CcmParamsSpec](#ccmparamsspec) for decryption. The ciphertext is used as the input parameter **data** for decryption.
- Symmetric encryption and decryption in other modes and symmetric decryption in GCM and CCM modes: The result is the complete plaintext/ciphertext, obtained by concatenating the output of each **updateSync** and **doFinalSync**.

 (2) Encrypts or decrypts the input data for RSA or SM2 asymmetric encryption/decryption. This API returns the result synchronously. If a large amount of data needs to be encrypted/decrypted, call **doFinalSync** multiple times and concatenate the result of each **doFinalSync** to obtain the complete plaintext/ciphertext.

See **NOTE** in [doFinal()](#dofinal) for other precautions.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Cipher

**Parameters**

| Name| Type                                       | Mandatory| Description                                                        |
| ------ | ------------------------------------------- | ---- | ------------------------------------------------------------ |
| data   | [DataBlob](#datablob)  | Yes  | Data to encrypt or decrypt. It can be **null** in symmetric encryption or decryption, but cannot be {data:Uint8Array(empty)}.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message               |
| -------- | ----------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | memory error.           |
| 17620002 | runtime error.          |
| 17630001 | crypto operation error. |

**Encryption with AES GCM (example)**

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
    algName: "GcmParamsSpec"
  };
  return gcmParamsSpec;
}

async function cipherBySync() {
  let gcmParams = genGcmParamsSpec();
  let symKeyGenerator = cryptoFramework.createSymKeyGenerator('AES128');
  let cipher = cryptoFramework.createCipher('AES128|GCM|PKCS7');
  let symKey = await symKeyGenerator.generateSymKey();
  await cipher.init(cryptoFramework.CryptoMode.ENCRYPT_MODE, symKey, gcmParams);
  let message = "This is a test";
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

**System capability**: SystemCapability.Security.CryptoFramework.Cipher

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 10 to 11 and SystemCapability.Security.CryptoFramework.Cipher since API version 12.

**Parameters**

| Name  | Type                | Mandatory| Description      |
| -------- | -------------------- | ---- | ---------- |
| itemType     | [CipherSpecItem](#cipherspecitem10)           | Yes  | Cipher parameter to set.|
| itemValue | Uint8Array | Yes  | Value of the parameter to set.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 801 | this operation is not supported.          |
| 17620001 | memory error.          |
| 17630001 | crypto operation error. |

**Example**

<!--code_no_check-->
```ts
let cipher: cryptoFramework.Cipher; // The process of generating the Cipher instance is omitted here.
let pSource = new Uint8Array([1,2,3,4]);
cipher.setCipherSpec(cryptoFramework.CipherSpecItem.OAEP_MGF1_PSRC_UINT8ARR, pSource);
```

### getCipherSpec<sup>10+</sup>

getCipherSpec(itemType: CipherSpecItem): string | Uint8Array

Obtains cipher specifications. Currently, only RSA and SM2 (available since API version 11) are supported.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Cipher

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 10 to 11 and SystemCapability.Security.CryptoFramework.Cipher since API version 12.

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
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 801 | this operation is not supported.          |
| 17620001 | memory error.          |
| 17630001 | crypto operation error. |

**Example**

<!--code_no_check-->
```ts
let cipher: cryptoFramework.Cipher; // The process of generating the Cipher instance is omitted here.
let mdName = cipher.getCipherSpec(cryptoFramework.CipherSpecItem.OAEP_MD_NAME_STR);
```

## cryptoFramework.createSign

createSign(algName: string): Sign

Creates a **Sign** instance.

For details about the supported specifications, see [Signing and Signature Verification Overview and Algorithm Specifications](../../security/CryptoArchitectureKit/crypto-sign-sig-verify-overview.md).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Signature

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 9 to 11 and SystemCapability.Security.CryptoFramework.Signature since API version 12.

**Parameters**

| Name | Type  | Mandatory| Description                                                        |
| ------- | ------ | ---- | ------------------------------------------------------------ |
| algName | string | Yes  | Signing algorithm to use. Currently, RSA, ECC, DSA, SM2<sup>10+</sup> and Ed25519<sup>11+</sup> are supported. <br>If the RSA PKCS1 mode is used, you need to set the digest. If the RSA PSS mode is used, you need to set the digest and mask digest.<br>When RSA is used for signing, you can set **OnlySign** to enable the input data digest to be used only for signing.|

**Return value**

| Type| Description                              |
| ---- | ---------------------------------- |
| Sign | Returns the **Sign** instance created.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 801 | this operation is not supported.          |
| 17620001 | memory error.          |

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

Provides APIs for signing. Before using any API of the **Sign** class, you must create a **Sign** instance by using [createSign(algName: string): Sign](#cryptoframeworkcreatesign). Invoke **init()**, **update()**, and **sign()** in this class in sequence to complete the signing operation. For details about the sample code, see [Signing and Signature Verification with an RSA Key Pair (PKCS1 Mode)](../../security/CryptoArchitectureKit/crypto-rsa-sign-sig-verify-pkcs1.md).

The **Sign** class does not support repeated initialization. When a new key is used for signing, you must create a new **Sign** instance and call **init()** for initialization.

The signing mode is determined in **createSign()**, and the key is set by **init()**.

If the data to be signed is short, you can directly call **sign()** to pass in the original data for signing after **init()**. That is, you do not need to use **update()**.

If the data to be signed is long, you can use **update()** to pass in the data by segment, and then use **sign()** to sign the entire data.

When **update()** is used, the **sign()** API supports only **DataBlob** in versions earlier than API version 10 and starts to support **null** since API version 10. After all the data is passed in by using **update()**, **sign()** can be called to sign the data.

If the DSA algorithm is used for signing and the digest algorithm is **NoHash**, **update()** is not supported. If **update()** is called in this case, **ERR_CRYPTO_OPERATION** will be returned.

### Attributes

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Signature

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 9 to 11 and SystemCapability.Security.CryptoFramework.Signature since API version 12.

| Name   | Type  | Readable| Writable| Description                        |
| ------- | ------ | ---- | ---- | ---------------------------- |
| algName | string | Yes  | No  | Algorithm to use.|

### init

init(priKey: PriKey, callback: AsyncCallback\<void>): void

Initializes the **Sign** instance with a private key. This API uses an asynchronous callback to return the result. **init**, **update**, and **sign** must be used together. **init** and **sign** are mandatory, and **update** is optional.

The **Sign** class does not support repeated use of **init()**.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Signature

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 9 to 11 and SystemCapability.Security.CryptoFramework.Signature since API version 12.

**Parameters**

| Name  | Type                | Mandatory| Description            |
| -------- | -------------------- | ---- | ---------------- |
| priKey   | [PriKey](#prikey)    | Yes  | Private key used for the initialization.|
| callback | AsyncCallback\<void> | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | memory error.          |
| 17620002 | runtime error.          |
| 17630001 | crypto operation error. |

### init

init(priKey: PriKey): Promise\<void>

Initializes the **Sign** instance with a private key. This API uses a promise to return the result. **init**, **update**, and **sign** must be used together. **init** and **sign** are mandatory, and **update** is optional.

The **Sign** class does not support repeated use of **init()**.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Signature

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 9 to 11 and SystemCapability.Security.CryptoFramework.Signature since API version 12.

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
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | memory error.          |
| 17620002 | runtime error.          |
| 17630001 | crypto operation error. |

### initSync<sup>12+</sup>

initSync(priKey: PriKey): void

Initializes the **Sign** instance with a private key. This API returns the result synchronously. **initSync**, **updateSync**, and **signSync** must be used together. **initSync** and **signSync** are mandatory, and **updateSync** is optional.

The **Sign** class does not support repeated use of **initSync()**.

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
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | memory error.          |
| 17620002 | runtime error.          |
| 17630001 | crypto operation error. |

### update

update(data: DataBlob, callback: AsyncCallback\<void>): void

Updates the data to be signed. This API uses an asynchronous callback to return the result.

This API can be called only after the [Sign](#sign) instance is initialized by using [init()](#init-2).

> **NOTE**
>
> You can call **update** multiple times or do not use **update** (call [sign](#sign-1) after [init](#init-2)), depending on the data volume.<br>
> The amount of the data to be passed in by **update()** (one-time or accumulative) is not limited. If there is a large amount of data, you are advised to call **update()** multiple times to pass in the data by segment. This prevents too much memory from being requested at a time.<br>
> For details about the sample code for calling **update()** multiple times in signing, see [Signing and Signature Verification by Segment with an RSA Key Pair (PKCS1 Mode)](../../security/CryptoArchitectureKit/crypto-rsa-sign-sig-verify-pkcs1-by-segment.md). The operations of other algorithms are similar.<br>
> **OnlySign** cannot be used with **update()**. If **OnlySign** is specified, use **sign()** to pass in data.<br>
> If the DSA algorithm is used for signing and the digest algorithm is **NoHash**, **update()** is not supported. If **update()** is called in this case, **ERR_CRYPTO_OPERATION** will be returned.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Signature

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 9 to 11 and SystemCapability.Security.CryptoFramework.Signature since API version 12.

**Parameters**

| Name  | Type                 | Mandatory| Description        |
| -------- | --------------------- | ---- | ------------ |
| data     | [DataBlob](#datablob) | Yes  | Data to pass in.|
| callback | AsyncCallback\<void>  | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | memory error.          |
| 17620002 | runtime error.          |
| 17630001 | crypto operation error. |

### update

update(data: DataBlob): Promise\<void>

Updates the data to be signed. This API uses a promise to return the result.

This API can be called only after the [Sign](#sign) instance is initialized by using [init()](#init-3).

> **NOTE**
>
> You can call **update** multiple times or do not use **update** (call [sign](#sign-2) after [init](#init-3)), depending on the data volume.<br>
> The amount of the data to be passed in by **update()** (one-time or accumulative) is not limited. If there is a large amount of data, you are advised to call **update()** multiple times to pass in the data by segment. This prevents too much memory from being requested at a time.<br>
> For details about the sample code for calling **update()** multiple times in signing, see [Signing and Signature Verification by Segment with an RSA Key Pair (PKCS1 Mode)](../../security/CryptoArchitectureKit/crypto-rsa-sign-sig-verify-pkcs1-by-segment.md). The operations of other algorithms are similar.<br>
> **OnlySign** cannot be used with **update()**. If **OnlySign** is specified, use **sign()** to pass in data.<br>
> If the DSA algorithm is used for signing and the digest algorithm is **NoHash**, **update()** is not supported. If **update()** is called in this case, **ERR_CRYPTO_OPERATION** will be returned.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Signature

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 9 to 11 and SystemCapability.Security.CryptoFramework.Signature since API version 12.

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
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | memory error.          |
| 17620002 | runtime error.          |
| 17630001 | crypto operation error. |

### updateSync<sup>12+</sup>

updateSync(data: DataBlob): void

Updates the data to be signed. This API returns the result synchronously.

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

**Return value**

| Type          | Description         |
| -------------- | ------------- |
| void | No value is returned.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | memory error.          |
| 17620002 | runtime error.          |
| 17630001 | crypto operation error. |

### sign

sign(data: DataBlob | null, callback: AsyncCallback\<DataBlob>): void

Signs the data. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Signature

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 9 to 11 and SystemCapability.Security.CryptoFramework.Signature since API version 12.

**Parameters**

| Name  | Type                | Mandatory| Description      |
| -------- | -------------------- | ---- | ---------- |
| data     | [DataBlob](#datablob) \| null<sup>10+</sup>              | Yes  | Data to pass in. In versions earlier than API version 10, only **DataBlob** is supported. Since API version 10, **null** is also supported.|
| callback | AsyncCallback\<[DataBlob](#datablob)> | Yes  | Callback invoked to return a **DataBlob** object.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | memory error.          |
| 17620002 | runtime error.          |
| 17630001 | crypto operation error. |

### sign

sign(data: DataBlob | null): Promise\<DataBlob>

Signs the data. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Signature

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 9 to 11 and SystemCapability.Security.CryptoFramework.Signature since API version 12.

**Parameters**

| Name| Type    | Mandatory| Description      |
| ------ | -------- | ---- | ---------- |
| data   | [DataBlob](#datablob) \| null<sup>10+</sup>  | Yes  | Data to pass in.|

**Return value**

| Type          | Description         |
| -------------- | ------------- |
| Promise\<[DataBlob](#datablob)> | Promise used to return the signature.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | memory error.          |
| 17620002 | runtime error.          |
| 17630001 | crypto operation error. |

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
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | memory error.          |
| 17620002 | runtime error.          |
| 17630001 | crypto operation error. |

**Example (using the callback-based API)**

For more examples of signing and signature verification, see [Signing and Signature Verification with an RSA Key Pair (PKCS1 Mode)](../../security/CryptoArchitectureKit/crypto-rsa-sign-sig-verify-pkcs1.md).

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { buffer } from '@kit.ArkTS';

function signByCallback() {
  let inputUpdate: cryptoFramework.DataBlob = { data: new Uint8Array(buffer.from("This is Sign test plan1", 'utf-8').buffer) };
  let inputVerify: cryptoFramework.DataBlob = { data: new Uint8Array(buffer.from("This is Sign test plan2", 'utf-8').buffer) };
  let pkData = new Uint8Array([48, 129, 159, 48, 13, 6, 9, 42, 134, 72, 134, 247, 13, 1, 1, 1, 5, 0, 3, 129, 141, 0, 48, 129, 137, 2, 129, 129, 0, 214, 179, 23, 198, 183, 139, 148, 8, 173, 74, 56, 160, 15, 248, 244, 166, 209, 250, 142, 74, 216, 58, 117, 215, 178, 247, 254, 39, 180, 227, 85, 201, 59, 133, 209, 221, 26, 9, 116, 31, 172, 151, 252, 185, 123, 20, 25, 7, 92, 129, 5, 196, 239, 214, 126, 254, 154, 188, 239, 144, 161, 171, 65, 42, 31, 214, 93, 115, 247, 69, 94, 143, 54, 51, 25, 49, 146, 204, 205, 165, 20, 120, 35, 184, 190, 65, 106, 12, 214, 176, 57, 125, 235, 51, 88, 135, 76, 73, 109, 112, 147, 138, 198, 252, 5, 20, 245, 51, 7, 32, 108, 89, 125, 204, 50, 189, 88, 254, 255, 146, 244, 244, 149, 79, 54, 216, 45, 89, 2, 3, 1, 0, 1]);
  let skData = new Uint8Array([48, 130, 2, 120, 2, 1, 0, 48, 13, 6, 9, 42, 134, 72, 134, 247, 13, 1, 1, 1, 5, 0, 4, 130, 2, 98, 48, 130, 2, 94, 2, 1, 0, 2, 129, 129, 0, 214, 179, 23, 198, 183, 139, 148, 8, 173, 74, 56, 160, 15, 248, 244, 166, 209, 250, 142, 74, 216, 58, 117, 215, 178, 247, 254, 39, 180, 227, 85, 201, 59, 133, 209, 221, 26, 9, 116, 31, 172, 151, 252, 185, 123, 20, 25, 7, 92, 129, 5, 196, 239, 214, 126, 254, 154, 188, 239, 144, 161, 171, 65, 42, 31, 214, 93, 115, 247, 69, 94, 143, 54, 51, 25, 49, 146, 204, 205, 165, 20, 120, 35, 184, 190, 65, 106, 12, 214, 176, 57, 125, 235, 51, 88, 135, 76, 73, 109, 112, 147, 138, 198, 252, 5, 20, 245, 51, 7, 32, 108, 89, 125, 204, 50, 189, 88, 254, 255, 146, 244, 244, 149, 79, 54, 216, 45, 89, 2, 3, 1, 0, 1, 2, 129, 129, 0, 152, 111, 145, 203, 10, 88, 116, 163, 112, 126, 9, 20, 68, 34, 235, 121, 98, 14, 182, 102, 151, 125, 114, 91, 210, 122, 215, 29, 212, 5, 176, 203, 238, 146, 5, 190, 41, 21, 91, 56, 125, 239, 111, 133, 53, 200, 192, 56, 132, 202, 42, 145, 120, 3, 224, 40, 223, 46, 148, 29, 41, 92, 17, 40, 12, 72, 165, 69, 192, 211, 142, 233, 81, 202, 177, 235, 156, 27, 179, 48, 18, 85, 154, 101, 193, 45, 218, 91, 24, 143, 196, 248, 16, 83, 177, 198, 136, 77, 111, 134, 60, 219, 95, 246, 23, 5, 45, 14, 83, 29, 137, 248, 159, 28, 132, 142, 205, 99, 226, 213, 84, 232, 57, 130, 156, 81, 191, 237, 2, 65, 0, 255, 158, 212, 13, 43, 132, 244, 135, 148, 161, 232, 219, 20, 81, 196, 102, 103, 44, 110, 71, 100, 62, 73, 200, 32, 138, 114, 209, 171, 150, 179, 92, 198, 5, 190, 218, 79, 227, 227, 37, 32, 57, 159, 252, 107, 211, 139, 198, 202, 248, 137, 143, 186, 205, 106, 81, 85, 207, 134, 148, 110, 204, 243, 27, 2, 65, 0, 215, 4, 181, 121, 57, 224, 170, 168, 183, 159, 152, 8, 74, 233, 80, 244, 146, 81, 48, 159, 194, 199, 36, 187, 6, 181, 182, 223, 115, 133, 151, 171, 78, 219, 90, 161, 248, 69, 6, 207, 173, 3, 81, 161, 2, 60, 238, 204, 177, 12, 138, 17, 220, 179, 71, 113, 200, 248, 159, 153, 252, 150, 180, 155, 2, 65, 0, 190, 202, 185, 211, 170, 171, 238, 40, 84, 84, 21, 13, 144, 57, 7, 178, 183, 71, 126, 120, 98, 229, 235, 4, 40, 229, 173, 149, 185, 209, 29, 199, 29, 54, 164, 161, 38, 8, 30, 62, 83, 179, 47, 42, 165, 0, 156, 207, 160, 39, 169, 229, 81, 180, 136, 170, 116, 182, 20, 233, 45, 90, 100, 9, 2, 65, 0, 152, 255, 47, 198, 15, 201, 238, 133, 89, 11, 133, 153, 184, 252, 37, 239, 177, 65, 118, 80, 231, 190, 222, 66, 250, 118, 72, 166, 221, 67, 156, 245, 119, 138, 28, 6, 142, 107, 71, 122, 116, 200, 156, 199, 237, 152, 191, 239, 4, 184, 64, 114, 143, 81, 62, 48, 23, 233, 217, 95, 47, 221, 104, 171, 2, 64, 30, 219, 1, 230, 241, 70, 246, 243, 121, 174, 67, 66, 11, 99, 202, 17, 52, 234, 78, 29, 3, 57, 51, 123, 149, 86, 64, 192, 73, 199, 108, 101, 55, 232, 41, 114, 153, 237, 253, 52, 205, 148, 45, 86, 186, 241, 182, 183, 42, 77, 252, 195, 29, 158, 173, 3, 182, 207, 254, 61, 71, 184, 167, 184]);
  let pubKeyBlob: cryptoFramework.DataBlob = { data: pkData };
  let priKeyBlob: cryptoFramework.DataBlob = { data: skData };
  let rsaGenerator = cryptoFramework.createAsyKeyGenerator('RSA1024');
  let signer = cryptoFramework.createSign('RSA1024|PKCS1|SHA256');
  rsaGenerator.convertKey(pubKeyBlob, priKeyBlob, (err, keyPair) => {
    signer.init(keyPair.priKey, err => {
      signer.update(inputUpdate, err => {
        signer.sign(inputVerify, (err, signData) => {
          console.info('sign output is ' + signData.data);
        });
      });
    });
  });
}
```

**Example (using the promise-based API)**

For more examples of signing and signature verification, see [Signing and Signature Verification with an RSA Key Pair (PKCS1 Mode)](../../security/CryptoArchitectureKit/crypto-rsa-sign-sig-verify-pkcs1.md).

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { buffer } from '@kit.ArkTS';

async function genKeyPairByData(pubKeyData: Uint8Array, priKeyData: Uint8Array) {
  let pubKeyBlob: cryptoFramework.DataBlob = { data: pubKeyData };
  let priKeyBlob: cryptoFramework.DataBlob = { data: priKeyData };
  let rsaGenerator = cryptoFramework.createAsyKeyGenerator('RSA1024');
  let keyPair = await rsaGenerator.convertKey(pubKeyBlob, priKeyBlob);
  console.info('convertKey success');
  return keyPair;
}

async function signByPromise() {
  let pkData = new Uint8Array([48, 129, 159, 48, 13, 6, 9, 42, 134, 72, 134, 247, 13, 1, 1, 1, 5, 0, 3, 129, 141, 0, 48, 129, 137, 2, 129, 129, 0, 214, 179, 23, 198, 183, 139, 148, 8, 173, 74, 56, 160, 15, 248, 244, 166, 209, 250, 142, 74, 216, 58, 117, 215, 178, 247, 254, 39, 180, 227, 85, 201, 59, 133, 209, 221, 26, 9, 116, 31, 172, 151, 252, 185, 123, 20, 25, 7, 92, 129, 5, 196, 239, 214, 126, 254, 154, 188, 239, 144, 161, 171, 65, 42, 31, 214, 93, 115, 247, 69, 94, 143, 54, 51, 25, 49, 146, 204, 205, 165, 20, 120, 35, 184, 190, 65, 106, 12, 214, 176, 57, 125, 235, 51, 88, 135, 76, 73, 109, 112, 147, 138, 198, 252, 5, 20, 245, 51, 7, 32, 108, 89, 125, 204, 50, 189, 88, 254, 255, 146, 244, 244, 149, 79, 54, 216, 45, 89, 2, 3, 1, 0, 1]);
  let skData = new Uint8Array([48, 130, 2, 120, 2, 1, 0, 48, 13, 6, 9, 42, 134, 72, 134, 247, 13, 1, 1, 1, 5, 0, 4, 130, 2, 98, 48, 130, 2, 94, 2, 1, 0, 2, 129, 129, 0, 214, 179, 23, 198, 183, 139, 148, 8, 173, 74, 56, 160, 15, 248, 244, 166, 209, 250, 142, 74, 216, 58, 117, 215, 178, 247, 254, 39, 180, 227, 85, 201, 59, 133, 209, 221, 26, 9, 116, 31, 172, 151, 252, 185, 123, 20, 25, 7, 92, 129, 5, 196, 239, 214, 126, 254, 154, 188, 239, 144, 161, 171, 65, 42, 31, 214, 93, 115, 247, 69, 94, 143, 54, 51, 25, 49, 146, 204, 205, 165, 20, 120, 35, 184, 190, 65, 106, 12, 214, 176, 57, 125, 235, 51, 88, 135, 76, 73, 109, 112, 147, 138, 198, 252, 5, 20, 245, 51, 7, 32, 108, 89, 125, 204, 50, 189, 88, 254, 255, 146, 244, 244, 149, 79, 54, 216, 45, 89, 2, 3, 1, 0, 1, 2, 129, 129, 0, 152, 111, 145, 203, 10, 88, 116, 163, 112, 126, 9, 20, 68, 34, 235, 121, 98, 14, 182, 102, 151, 125, 114, 91, 210, 122, 215, 29, 212, 5, 176, 203, 238, 146, 5, 190, 41, 21, 91, 56, 125, 239, 111, 133, 53, 200, 192, 56, 132, 202, 42, 145, 120, 3, 224, 40, 223, 46, 148, 29, 41, 92, 17, 40, 12, 72, 165, 69, 192, 211, 142, 233, 81, 202, 177, 235, 156, 27, 179, 48, 18, 85, 154, 101, 193, 45, 218, 91, 24, 143, 196, 248, 16, 83, 177, 198, 136, 77, 111, 134, 60, 219, 95, 246, 23, 5, 45, 14, 83, 29, 137, 248, 159, 28, 132, 142, 205, 99, 226, 213, 84, 232, 57, 130, 156, 81, 191, 237, 2, 65, 0, 255, 158, 212, 13, 43, 132, 244, 135, 148, 161, 232, 219, 20, 81, 196, 102, 103, 44, 110, 71, 100, 62, 73, 200, 32, 138, 114, 209, 171, 150, 179, 92, 198, 5, 190, 218, 79, 227, 227, 37, 32, 57, 159, 252, 107, 211, 139, 198, 202, 248, 137, 143, 186, 205, 106, 81, 85, 207, 134, 148, 110, 204, 243, 27, 2, 65, 0, 215, 4, 181, 121, 57, 224, 170, 168, 183, 159, 152, 8, 74, 233, 80, 244, 146, 81, 48, 159, 194, 199, 36, 187, 6, 181, 182, 223, 115, 133, 151, 171, 78, 219, 90, 161, 248, 69, 6, 207, 173, 3, 81, 161, 2, 60, 238, 204, 177, 12, 138, 17, 220, 179, 71, 113, 200, 248, 159, 153, 252, 150, 180, 155, 2, 65, 0, 190, 202, 185, 211, 170, 171, 238, 40, 84, 84, 21, 13, 144, 57, 7, 178, 183, 71, 126, 120, 98, 229, 235, 4, 40, 229, 173, 149, 185, 209, 29, 199, 29, 54, 164, 161, 38, 8, 30, 62, 83, 179, 47, 42, 165, 0, 156, 207, 160, 39, 169, 229, 81, 180, 136, 170, 116, 182, 20, 233, 45, 90, 100, 9, 2, 65, 0, 152, 255, 47, 198, 15, 201, 238, 133, 89, 11, 133, 153, 184, 252, 37, 239, 177, 65, 118, 80, 231, 190, 222, 66, 250, 118, 72, 166, 221, 67, 156, 245, 119, 138, 28, 6, 142, 107, 71, 122, 116, 200, 156, 199, 237, 152, 191, 239, 4, 184, 64, 114, 143, 81, 62, 48, 23, 233, 217, 95, 47, 221, 104, 171, 2, 64, 30, 219, 1, 230, 241, 70, 246, 243, 121, 174, 67, 66, 11, 99, 202, 17, 52, 234, 78, 29, 3, 57, 51, 123, 149, 86, 64, 192, 73, 199, 108, 101, 55, 232, 41, 114, 153, 237, 253, 52, 205, 148, 45, 86, 186, 241, 182, 183, 42, 77, 252, 195, 29, 158, 173, 3, 182, 207, 254, 61, 71, 184, 167, 184]);
  let keyPair = await genKeyPairByData(pkData, skData);
  let inputUpdate: cryptoFramework.DataBlob = { data: new Uint8Array(buffer.from("This is Sign test plan1", 'utf-8').buffer) };
  let inputSign: cryptoFramework.DataBlob = { data: new Uint8Array(buffer.from("This is Sign test plan2", 'utf-8').buffer) };
  let signer = cryptoFramework.createSign('RSA1024|PKCS1|SHA256');
  await signer.init(keyPair.priKey);
  await signer.update(inputUpdate);
  let signData = await signer.sign(inputSign);
  console.info('signData result: ' + signData.data);
}
```

**Example (using the sync API)**

For more examples of signing and signature verification, see [Signing and Signature Verification with an RSA Key Pair (PKCS1 Mode)](../../security/CryptoArchitectureKit/crypto-rsa-sign-sig-verify-pkcs1.md).

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { buffer } from '@kit.ArkTS';

function genKeyPairByData(pubKeyData: Uint8Array, priKeyData: Uint8Array) {
  let pubKeyBlob: cryptoFramework.DataBlob = { data: pubKeyData };
  let priKeyBlob: cryptoFramework.DataBlob = { data: priKeyData };
  let rsaGenerator = cryptoFramework.createAsyKeyGenerator('RSA1024');
  let keyPair = rsaGenerator.convertKeySync(pubKeyBlob, priKeyBlob);
  console.info('convertKeySync success');
  return keyPair;
}

function signBySync() {
  let pkData = new Uint8Array([48, 129, 159, 48, 13, 6, 9, 42, 134, 72, 134, 247, 13, 1, 1, 1, 5, 0, 3, 129, 141, 0, 48, 129, 137, 2, 129, 129, 0, 214, 179, 23, 198, 183, 139, 148, 8, 173, 74, 56, 160, 15, 248, 244, 166, 209, 250, 142, 74, 216, 58, 117, 215, 178, 247, 254, 39, 180, 227, 85, 201, 59, 133, 209, 221, 26, 9, 116, 31, 172, 151, 252, 185, 123, 20, 25, 7, 92, 129, 5, 196, 239, 214, 126, 254, 154, 188, 239, 144, 161, 171, 65, 42, 31, 214, 93, 115, 247, 69, 94, 143, 54, 51, 25, 49, 146, 204, 205, 165, 20, 120, 35, 184, 190, 65, 106, 12, 214, 176, 57, 125, 235, 51, 88, 135, 76, 73, 109, 112, 147, 138, 198, 252, 5, 20, 245, 51, 7, 32, 108, 89, 125, 204, 50, 189, 88, 254, 255, 146, 244, 244, 149, 79, 54, 216, 45, 89, 2, 3, 1, 0, 1]);
  let skData = new Uint8Array([48, 130, 2, 120, 2, 1, 0, 48, 13, 6, 9, 42, 134, 72, 134, 247, 13, 1, 1, 1, 5, 0, 4, 130, 2, 98, 48, 130, 2, 94, 2, 1, 0, 2, 129, 129, 0, 214, 179, 23, 198, 183, 139, 148, 8, 173, 74, 56, 160, 15, 248, 244, 166, 209, 250, 142, 74, 216, 58, 117, 215, 178, 247, 254, 39, 180, 227, 85, 201, 59, 133, 209, 221, 26, 9, 116, 31, 172, 151, 252, 185, 123, 20, 25, 7, 92, 129, 5, 196, 239, 214, 126, 254, 154, 188, 239, 144, 161, 171, 65, 42, 31, 214, 93, 115, 247, 69, 94, 143, 54, 51, 25, 49, 146, 204, 205, 165, 20, 120, 35, 184, 190, 65, 106, 12, 214, 176, 57, 125, 235, 51, 88, 135, 76, 73, 109, 112, 147, 138, 198, 252, 5, 20, 245, 51, 7, 32, 108, 89, 125, 204, 50, 189, 88, 254, 255, 146, 244, 244, 149, 79, 54, 216, 45, 89, 2, 3, 1, 0, 1, 2, 129, 129, 0, 152, 111, 145, 203, 10, 88, 116, 163, 112, 126, 9, 20, 68, 34, 235, 121, 98, 14, 182, 102, 151, 125, 114, 91, 210, 122, 215, 29, 212, 5, 176, 203, 238, 146, 5, 190, 41, 21, 91, 56, 125, 239, 111, 133, 53, 200, 192, 56, 132, 202, 42, 145, 120, 3, 224, 40, 223, 46, 148, 29, 41, 92, 17, 40, 12, 72, 165, 69, 192, 211, 142, 233, 81, 202, 177, 235, 156, 27, 179, 48, 18, 85, 154, 101, 193, 45, 218, 91, 24, 143, 196, 248, 16, 83, 177, 198, 136, 77, 111, 134, 60, 219, 95, 246, 23, 5, 45, 14, 83, 29, 137, 248, 159, 28, 132, 142, 205, 99, 226, 213, 84, 232, 57, 130, 156, 81, 191, 237, 2, 65, 0, 255, 158, 212, 13, 43, 132, 244, 135, 148, 161, 232, 219, 20, 81, 196, 102, 103, 44, 110, 71, 100, 62, 73, 200, 32, 138, 114, 209, 171, 150, 179, 92, 198, 5, 190, 218, 79, 227, 227, 37, 32, 57, 159, 252, 107, 211, 139, 198, 202, 248, 137, 143, 186, 205, 106, 81, 85, 207, 134, 148, 110, 204, 243, 27, 2, 65, 0, 215, 4, 181, 121, 57, 224, 170, 168, 183, 159, 152, 8, 74, 233, 80, 244, 146, 81, 48, 159, 194, 199, 36, 187, 6, 181, 182, 223, 115, 133, 151, 171, 78, 219, 90, 161, 248, 69, 6, 207, 173, 3, 81, 161, 2, 60, 238, 204, 177, 12, 138, 17, 220, 179, 71, 113, 200, 248, 159, 153, 252, 150, 180, 155, 2, 65, 0, 190, 202, 185, 211, 170, 171, 238, 40, 84, 84, 21, 13, 144, 57, 7, 178, 183, 71, 126, 120, 98, 229, 235, 4, 40, 229, 173, 149, 185, 209, 29, 199, 29, 54, 164, 161, 38, 8, 30, 62, 83, 179, 47, 42, 165, 0, 156, 207, 160, 39, 169, 229, 81, 180, 136, 170, 116, 182, 20, 233, 45, 90, 100, 9, 2, 65, 0, 152, 255, 47, 198, 15, 201, 238, 133, 89, 11, 133, 153, 184, 252, 37, 239, 177, 65, 118, 80, 231, 190, 222, 66, 250, 118, 72, 166, 221, 67, 156, 245, 119, 138, 28, 6, 142, 107, 71, 122, 116, 200, 156, 199, 237, 152, 191, 239, 4, 184, 64, 114, 143, 81, 62, 48, 23, 233, 217, 95, 47, 221, 104, 171, 2, 64, 30, 219, 1, 230, 241, 70, 246, 243, 121, 174, 67, 66, 11, 99, 202, 17, 52, 234, 78, 29, 3, 57, 51, 123, 149, 86, 64, 192, 73, 199, 108, 101, 55, 232, 41, 114, 153, 237, 253, 52, 205, 148, 45, 86, 186, 241, 182, 183, 42, 77, 252, 195, 29, 158, 173, 3, 182, 207, 254, 61, 71, 184, 167, 184]);
  let keyPair =  genKeyPairByData(pkData, skData);
  let inputUpdate: cryptoFramework.DataBlob = { data: new Uint8Array(buffer.from("This is Sign test plan1", 'utf-8').buffer) };
  let inputSign: cryptoFramework.DataBlob = { data: new Uint8Array(buffer.from("This is Sign test plan2", 'utf-8').buffer) };
  let signer = cryptoFramework.createSign('RSA1024|PKCS1|SHA256');
  signer.initSync(keyPair.priKey);
  signer.updateSync(inputUpdate);
  let signData = signer.signSync(inputSign);
  console.info('signData result: ' + signData.data);
}
```

### setSignSpec<sup>10+</sup>

setSignSpec(itemType: SignSpecItem, itemValue: number): void

setSignSpec(itemType: SignSpecItem, itemValue: number \| Uint8Array): void

Sets signing specifications. You can use this API to set signing parameters that cannot be set by [createSign](#cryptoframeworkcreatesign).

Currently, only RSA and SM2 are supported. Since API version 11, SM2 signing parameters can be set.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Signature

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 10 to 11 and SystemCapability.Security.CryptoFramework.Signature since API version 12.

**Parameters**

| Name  | Type                | Mandatory| Description      |
| -------- | -------------------- | ---- | ---------- |
| itemType     | [SignSpecItem](#signspecitem10)              | Yes  | Signing parameter to set.|
| itemValue | number \| Uint8Array<sup>11+</sup> | Yes  | Value of the signing parameter to set.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 801 | this operation is not supported.          |
| 17620001 | memory error.          |
| 17630001 | crypto operation error. |

**Example**

<!--code_no_check-->
```ts
let signer: cryptoFramework.Sign; // The process of generating the Sign instance is omitted here.
let setN = 20;
signer.setSignSpec(cryptoFramework.SignSpecItem.PSS_SALT_LEN_NUM, setN);
```

### getSignSpec<sup>10+</sup>

getSignSpec(itemType: SignSpecItem): string | number

Obtains signing specifications. Currently, only RSA is supported.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Signature

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 10 to 11 and SystemCapability.Security.CryptoFramework.Signature since API version 12.

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
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 801 | this operation is not supported.          |
| 17620001 | memory error.          |
| 17630001 | crypto operation error. |

**Example**

<!--code_no_check-->
```ts
let signer: cryptoFramework.Sign; // The process of generating the Sign instance is omitted here.
let saltLen = signer.getSignSpec(cryptoFramework.SignSpecItem.PSS_SALT_LEN_NUM);
```

## cryptoFramework.createVerify

createVerify(algName: string): Verify

Creates a **Verify** instance.

For details about the supported specifications, see [Signing and Signature Verification Overview and Algorithm Specifications](../../security/CryptoArchitectureKit/crypto-sign-sig-verify-overview.md).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Signature

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 9 to 11 and SystemCapability.Security.CryptoFramework.Signature since API version 12.

**Parameters**

| Name | Type  | Mandatory| Description                                                        |
| ------- | ------ | ---- | ------------------------------------------------------------ |
| algName | string | Yes  | Signing algorithm to use. Currently, RSA, ECC, DSA, SM2<sup>10+</sup> and Ed25519<sup>11+</sup> are supported. <br>If the RSA PKCS1 mode is used, you need to set the digest. If the RSA PSS mode is used, you need to set the digest and mask digest.<br>When the RSA algorithm is used for signature verification, you can use **Recover** to verify and recover the signed data.|

**Return value**

| Type  | Description                                |
| ------ | ------------------------------------ |
| Verify | Returns the **Verify** instance created.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 801 | this operation is not supported.          |
| 17620001 | memory error.          |

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';

let verifyer1 = cryptoFramework.createVerify('RSA1024|PKCS1|SHA256');

let verifyer2 = cryptoFramework.createVerify('RSA1024|PSS|SHA256|MGF1_SHA256');

let verifyer3 = cryptoFramework.createVerify('RSA1024|PKCS1|SHA256|Recover');
```

## Verify

Provides APIs for signature verification. Before using any API of the **Verify** class, you must create a **Verify** instance by using [createVerify(algName: string): Verify](#cryptoframeworkcreateverify). Invoke **init()**, **update()**, and **sign()** in this class in sequence to complete the signature verification. For details about the sample code, see [Signing and Signature Verification with an RSA Key Pair (PKCS1 Mode)](../../security/CryptoArchitectureKit/crypto-rsa-sign-sig-verify-pkcs1.md).

The **Verify** class does not support repeated initialization. When a new key is used for signature verification, you must create a new **Verify** instance and call **init()** for initialization.

The signature verification mode is determined in **createVerify()**, and the key is set by **init()**.

If the signed message is short, you can call **verify()** to pass in the signed message and signature (**signatureData**) for signature verification after **init()**. That is, you do not need to use **update()**.

If the signed message is too long, you can call **update()** multiple times to pass in the signed message by segment, and then call **verify()** to verify the full text of the message. In versions earlier than API version 10, the input parameter **data** of **verify()** supports only **DataBlob**. Since API version 10, **data** also supports **null**. After all the data is passed in by using **update()**, **verify()** can be called to verify the signature data.

If the DSA algorithm is used for signature verification and the digest algorithm is **NoHash**, **update()** is not supported. If **update()** is called in this case, **ERR_CRYPTO_OPERATION** will be returned.

### Attributes

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Signature

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 9 to 11 and SystemCapability.Security.CryptoFramework.Signature since API version 12.

| Name   | Type  | Readable| Writable| Description                        |
| ------- | ------ | ---- | ---- | ---------------------------- |
| algName | string | Yes  | No  | Algorithm to be used for signature verification.|

### init

init(pubKey: PubKey, callback: AsyncCallback\<void>): void

Initializes the **Verify** instance with a public key. This API uses an asynchronous callback to return the result. **init**, **update**, and **verify** must be used together. **init** and **verify** are mandatory, and **update** is optional.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Signature

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 9 to 11 and SystemCapability.Security.CryptoFramework.Signature since API version 12.

**Parameters**

| Name  | Type                | Mandatory| Description                          |
| -------- | -------------------- | ---- | ------------------------------ |
| pubKey   | [PubKey](#pubkey)    | Yes  | Public key used to initialize the **Verify** instance.|
| callback | AsyncCallback\<void> | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object. |

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | memory error.          |
| 17620002 | runtime error.          |
| 17630001 | crypto operation error. |

### init

init(pubKey: PubKey): Promise\<void>

Initializes the **Verify** instance with a public key. This API uses a promise to return the result. **init**, **update**, and **verify** must be used together. **init** and **verify** are mandatory, and **update** is optional.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Signature

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 9 to 11 and SystemCapability.Security.CryptoFramework.Signature since API version 12.

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
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | memory error.          |
| 17620002 | runtime error.          |
| 17630001 | crypto operation error. |

### initSync<sup>12+</sup>

initSync(pubKey: PubKey): void

Initializes the **Verify** instance with a public key. This API returns the result synchronously. **initSync**, **updateSync**, and **verifySync** must be used together. **initSync** and **verifySync** are mandatory, and **updateSync** is optional.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Signature

**Parameters**

| Name| Type| Mandatory| Description                        |
| ------ | ---- | ---- | ---------------------------- |
| pubKey | [PubKey](#pubkey)  | Yes  | Public key used to initialize the **Verify** instance.|

**Return value**

| Type          | Description         |
| -------------- | ------------- |
| void | No value is returned.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | memory error.          |
| 17620002 | runtime error.          |
| 17630001 | crypto operation error. |

### update

update(data: DataBlob, callback: AsyncCallback\<void>): void

Updates the data for signature verification. This API uses an asynchronous callback to return the result.

This API can be called only after the [Verify](#verify) instance is initialized using [init()](#init-4).

> **NOTE**
>
> You can call **update** multiple times or do not use **update** (call [verify](#verify-1) after [init](#init-4)), depending on the data volume.<br>
> The amount of the data to be passed in by **update()** (one-time or accumulative) is not limited. If there is a large amount of data, you are advised to call **update()** multiple times to pass in the data by segment. This prevents too much memory from being requested at a time.<br>
> For details about the sample code for calling **update()** multiple times in signature verification, see [Signing and Signature Verification by Segment with an RSA Key Pair (PKCS1 Mode)](../../security/CryptoArchitectureKit/crypto-rsa-sign-sig-verify-pkcs1-by-segment.md). The operations of other algorithms are similar.<br>
> If the DSA algorithm is used for signature verification and the digest algorithm is **NoHash**, **update()** is not supported. If **update()** is called in this case, **ERR_CRYPTO_OPERATION** will be returned.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Signature

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 9 to 11 and SystemCapability.Security.CryptoFramework.Signature since API version 12.

**Parameters**

| Name  | Type                 | Mandatory| Description        |
| -------- | --------------------- | ---- | ------------ |
| data     | [DataBlob](#datablob) | Yes  | Data to pass in.|
| callback | AsyncCallback\<void>  | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | memory error.          |
| 17620002 | runtime error.          |
| 17630001 | crypto operation error. |

### update

update(data: DataBlob): Promise\<void>

Updates the data for signature verifications. This API uses a promise to return the result.

This API can be called only after the [Verify](#verify) instance is initialized using [init()](#init-5).

> **NOTE**
>
> You can call **update** multiple times or do not use **update** (call [verify](#verify-2) after [init](#init-5)), depending on the data volume.<br>
> The amount of the data to be passed in by **update()** (one-time or accumulative) is not limited. If there is a large amount of data, you are advised to call **update()** multiple times to pass in the data by segment. This prevents too much memory from being requested at a time.<br>
> For details about the sample code for calling **update()** multiple times in signature verification, see [Signing and Signature Verification by Segment with an RSA Key Pair (PKCS1 Mode)](../../security/CryptoArchitectureKit/crypto-rsa-sign-sig-verify-pkcs1-by-segment.md). The operations of other algorithms are similar.<br>
> If the DSA algorithm is used for signature verification and the digest algorithm is **NoHash**, **update()** is not supported. If **update()** is called in this case, **ERR_CRYPTO_OPERATION** will be returned.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Signature

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 9 to 11 and SystemCapability.Security.CryptoFramework.Signature since API version 12.

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
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | memory error.          |
| 17620002 | runtime error.          |
| 17630001 | crypto operation error. |

### updateSync<sup>12+</sup>

updateSync(data: DataBlob): void

Updates the data for signature verifications. This API returns the result synchronously.

This API can be called only after the [Verify](#verify) instance is initialized by using [initSync()](#initsync12-2).

> **NOTE**
>
> You can call **updateSync** multiple times or do not use **updateSync** (call [verifySync](#verifysync12)after [initSync](#initsync12-2)), depending on the data volume.<br>
> The amount of the data to be passed in by **updateSync** (one-time or accumulative) is not limited. If there is a large amount of data, you are advised to call **updateSync** multiple times to pass in the data by segment. This prevents too much memory from being requested at a time.<br>
> For details about the sample code for calling **updateSync** multiple times in signature verification, see [Signing and Signature Verification by Segment with an RSA Key Pair (PKCS1 Mode)](../../security/CryptoArchitectureKit/crypto-rsa-sign-sig-verify-pkcs1-by-segment.md). The operations of other algorithms are similar.<br>
> If the DSA algorithm is used for signature verification and the digest algorithm is **NoHash**, **updateSync** is not supported. If **updateSync** is called in this case, **ERR_CRYPTO_OPERATION** will be returned.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Signature

**Parameters**

| Name| Type    | Mandatory| Description      |
| ------ | -------- | ---- | ---------- |
| data   | [DataBlob](#datablob)  | Yes  | Data to pass in.|

**Return value**

| Type          | Description         |
| -------------- | ------------- |
| void | No value is returned.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | memory error.          |
| 17620002 | runtime error.          |
| 17630001 | crypto operation error. |

### verify

verify(data: DataBlob | null, signatureData: DataBlob, callback: AsyncCallback\<boolean>): void

Verifies the signature. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Signature

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 9 to 11 and SystemCapability.Security.CryptoFramework.Signature since API version 12.

**Parameters**

| Name       | Type                | Mandatory| Description      |
| ------------- | -------------------- | ---- | ---------- |
| data          | [DataBlob](#datablob) \| null<sup>10+</sup>             | Yes  | Data to pass in. In versions earlier than API version 10, only **DataBlob** is supported. Since API version 10, **null** is also supported.|
| signatureData | [DataBlob](#datablob)              | Yes  | Signature data. |
| callback      | AsyncCallback\<boolean> | Yes  | Callback invoked to return the signature verification result.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | memory error.          |
| 17620002 | runtime error.          |
| 17630001 | crypto operation error. |

### verify

verify(data: DataBlob | null, signatureData: DataBlob): Promise\<boolean>

Verifies the signature. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Signature

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 9 to 11 and SystemCapability.Security.CryptoFramework.Signature since API version 12.

**Parameters**

| Name       | Type    | Mandatory| Description      |
| ------------- | -------- | ---- | ---------- |
| data          | [DataBlob](#datablob) \| null<sup>10+</sup>  | Yes  | Data to pass in. In versions earlier than API version 10, only **DataBlob** is supported. Since API version 10, **null** is also supported.|
| signatureData | [DataBlob](#datablob)  | Yes  | Signature data. |

**Return value**

| Type             | Description                          |
| ----------------- | ------------------------------ |
| Promise\<boolean> | Promise used to return the result.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | memory error.          |
| 17620002 | runtime error.          |
| 17630001 | crypto operation error. |

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
| boolean | Signature verification result.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | memory error.          |
| 17620002 | runtime error.          |
| 17630001 | crypto operation error. |

**Example (using the callback-based API)**

For more examples of signing and signature verification, see [Signing and Signature Verification with an RSA Key Pair (PKCS1 Mode)](../../security/CryptoArchitectureKit/crypto-rsa-sign-sig-verify-pkcs1.md).

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { buffer } from '@kit.ArkTS';

function verifyByCallback() {
  let inputUpdate: cryptoFramework.DataBlob = { data: new Uint8Array(buffer.from("This is Sign test plan1", 'utf-8').buffer) };
  let inputVerify: cryptoFramework.DataBlob = { data: new Uint8Array(buffer.from("This is Sign test plan2", 'utf-8').buffer) };
  // Key generated based on the key data and input data for signature verification. If the data in verify() is the same as that in sign(), the signature verification is successful.
  let pkData = new Uint8Array([48, 129, 159, 48, 13, 6, 9, 42, 134, 72, 134, 247, 13, 1, 1, 1, 5, 0, 3, 129, 141, 0, 48, 129, 137, 2, 129, 129, 0, 214, 179, 23, 198, 183, 139, 148, 8, 173, 74, 56, 160, 15, 248, 244, 166, 209, 250, 142, 74, 216, 58, 117, 215, 178, 247, 254, 39, 180, 227, 85, 201, 59, 133, 209, 221, 26, 9, 116, 31, 172, 151, 252, 185, 123, 20, 25, 7, 92, 129, 5, 196, 239, 214, 126, 254, 154, 188, 239, 144, 161, 171, 65, 42, 31, 214, 93, 115, 247, 69, 94, 143, 54, 51, 25, 49, 146, 204, 205, 165, 20, 120, 35, 184, 190, 65, 106, 12, 214, 176, 57, 125, 235, 51, 88, 135, 76, 73, 109, 112, 147, 138, 198, 252, 5, 20, 245, 51, 7, 32, 108, 89, 125, 204, 50, 189, 88, 254, 255, 146, 244, 244, 149, 79, 54, 216, 45, 89, 2, 3, 1, 0, 1]);
  let skData = new Uint8Array([48, 130, 2, 120, 2, 1, 0, 48, 13, 6, 9, 42, 134, 72, 134, 247, 13, 1, 1, 1, 5, 0, 4, 130, 2, 98, 48, 130, 2, 94, 2, 1, 0, 2, 129, 129, 0, 214, 179, 23, 198, 183, 139, 148, 8, 173, 74, 56, 160, 15, 248, 244, 166, 209, 250, 142, 74, 216, 58, 117, 215, 178, 247, 254, 39, 180, 227, 85, 201, 59, 133, 209, 221, 26, 9, 116, 31, 172, 151, 252, 185, 123, 20, 25, 7, 92, 129, 5, 196, 239, 214, 126, 254, 154, 188, 239, 144, 161, 171, 65, 42, 31, 214, 93, 115, 247, 69, 94, 143, 54, 51, 25, 49, 146, 204, 205, 165, 20, 120, 35, 184, 190, 65, 106, 12, 214, 176, 57, 125, 235, 51, 88, 135, 76, 73, 109, 112, 147, 138, 198, 252, 5, 20, 245, 51, 7, 32, 108, 89, 125, 204, 50, 189, 88, 254, 255, 146, 244, 244, 149, 79, 54, 216, 45, 89, 2, 3, 1, 0, 1, 2, 129, 129, 0, 152, 111, 145, 203, 10, 88, 116, 163, 112, 126, 9, 20, 68, 34, 235, 121, 98, 14, 182, 102, 151, 125, 114, 91, 210, 122, 215, 29, 212, 5, 176, 203, 238, 146, 5, 190, 41, 21, 91, 56, 125, 239, 111, 133, 53, 200, 192, 56, 132, 202, 42, 145, 120, 3, 224, 40, 223, 46, 148, 29, 41, 92, 17, 40, 12, 72, 165, 69, 192, 211, 142, 233, 81, 202, 177, 235, 156, 27, 179, 48, 18, 85, 154, 101, 193, 45, 218, 91, 24, 143, 196, 248, 16, 83, 177, 198, 136, 77, 111, 134, 60, 219, 95, 246, 23, 5, 45, 14, 83, 29, 137, 248, 159, 28, 132, 142, 205, 99, 226, 213, 84, 232, 57, 130, 156, 81, 191, 237, 2, 65, 0, 255, 158, 212, 13, 43, 132, 244, 135, 148, 161, 232, 219, 20, 81, 196, 102, 103, 44, 110, 71, 100, 62, 73, 200, 32, 138, 114, 209, 171, 150, 179, 92, 198, 5, 190, 218, 79, 227, 227, 37, 32, 57, 159, 252, 107, 211, 139, 198, 202, 248, 137, 143, 186, 205, 106, 81, 85, 207, 134, 148, 110, 204, 243, 27, 2, 65, 0, 215, 4, 181, 121, 57, 224, 170, 168, 183, 159, 152, 8, 74, 233, 80, 244, 146, 81, 48, 159, 194, 199, 36, 187, 6, 181, 182, 223, 115, 133, 151, 171, 78, 219, 90, 161, 248, 69, 6, 207, 173, 3, 81, 161, 2, 60, 238, 204, 177, 12, 138, 17, 220, 179, 71, 113, 200, 248, 159, 153, 252, 150, 180, 155, 2, 65, 0, 190, 202, 185, 211, 170, 171, 238, 40, 84, 84, 21, 13, 144, 57, 7, 178, 183, 71, 126, 120, 98, 229, 235, 4, 40, 229, 173, 149, 185, 209, 29, 199, 29, 54, 164, 161, 38, 8, 30, 62, 83, 179, 47, 42, 165, 0, 156, 207, 160, 39, 169, 229, 81, 180, 136, 170, 116, 182, 20, 233, 45, 90, 100, 9, 2, 65, 0, 152, 255, 47, 198, 15, 201, 238, 133, 89, 11, 133, 153, 184, 252, 37, 239, 177, 65, 118, 80, 231, 190, 222, 66, 250, 118, 72, 166, 221, 67, 156, 245, 119, 138, 28, 6, 142, 107, 71, 122, 116, 200, 156, 199, 237, 152, 191, 239, 4, 184, 64, 114, 143, 81, 62, 48, 23, 233, 217, 95, 47, 221, 104, 171, 2, 64, 30, 219, 1, 230, 241, 70, 246, 243, 121, 174, 67, 66, 11, 99, 202, 17, 52, 234, 78, 29, 3, 57, 51, 123, 149, 86, 64, 192, 73, 199, 108, 101, 55, 232, 41, 114, 153, 237, 253, 52, 205, 148, 45, 86, 186, 241, 182, 183, 42, 77, 252, 195, 29, 158, 173, 3, 182, 207, 254, 61, 71, 184, 167, 184]);
  let pubKeyBlob: cryptoFramework.DataBlob = { data: pkData };
  let priKeyBlob: cryptoFramework.DataBlob = { data: skData };
  // The data is signData.data in Sign().
  let signMessageBlob: cryptoFramework.DataBlob = { data: new Uint8Array([9, 68, 164, 161, 230, 155, 255, 153, 10, 12, 14, 22, 146, 115, 209, 167, 223, 133, 89, 173, 50, 249, 176, 104, 10, 251, 219, 104, 117, 196, 105, 65, 249, 139, 119, 41, 15, 171, 191, 11, 177, 177, 1, 119, 130, 142, 87, 183, 32, 220, 226, 28, 38, 73, 222, 172, 153, 26, 87, 58, 188, 42, 150, 67, 94, 214, 147, 64, 202, 87, 155, 125, 254, 112, 95, 176, 255, 207, 106, 43, 228, 153, 131, 240, 120, 88, 253, 179, 207, 207, 110, 223, 173, 15, 113, 11, 183, 122, 237, 205, 206, 123, 246, 33, 167, 169, 251, 237, 199, 26, 220, 152, 190, 117, 131, 74, 232, 50, 39, 172, 232, 178, 112, 73, 251, 235, 131, 209]) }
  let rsaGenerator = cryptoFramework.createAsyKeyGenerator('RSA1024');
  let verifyer = cryptoFramework.createVerify('RSA1024|PKCS1|SHA256');
  rsaGenerator.convertKey(pubKeyBlob, priKeyBlob, (err, keyPair) => {
    verifyer.init(keyPair.pubKey, err => {
      verifyer.update(inputUpdate, err => {
        verifyer.verify(inputVerify, signMessageBlob, (err, res) => {
          console.info('verify result is ' + res);
        });
      });
    });
  });
}
```

**Example (using the promise-based API)**

For more examples of signing and signature verification, see [Signing and Signature Verification with an RSA Key Pair (PKCS1 Mode)](../../security/CryptoArchitectureKit/crypto-rsa-sign-sig-verify-pkcs1.md).

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { buffer } from '@kit.ArkTS';

async function genKeyPairByData(pubKeyData: Uint8Array, priKeyData: Uint8Array) {
  let pubKeyBlob: cryptoFramework.DataBlob = { data: pubKeyData };
  let priKeyBlob: cryptoFramework.DataBlob = { data: priKeyData };
  let rsaGenerator = cryptoFramework.createAsyKeyGenerator('RSA1024');
  let keyPair = await rsaGenerator.convertKey(pubKeyBlob, priKeyBlob);
  console.info('convertKey success');
  return keyPair;
}

async function verifyByPromise() {
  // Key generated based on the key data and input data for signature verification. If the data in verify() is the same as that in sign(), the signature verification is successful.
  let pkData = new Uint8Array([48, 129, 159, 48, 13, 6, 9, 42, 134, 72, 134, 247, 13, 1, 1, 1, 5, 0, 3, 129, 141, 0, 48, 129, 137, 2, 129, 129, 0, 214, 179, 23, 198, 183, 139, 148, 8, 173, 74, 56, 160, 15, 248, 244, 166, 209, 250, 142, 74, 216, 58, 117, 215, 178, 247, 254, 39, 180, 227, 85, 201, 59, 133, 209, 221, 26, 9, 116, 31, 172, 151, 252, 185, 123, 20, 25, 7, 92, 129, 5, 196, 239, 214, 126, 254, 154, 188, 239, 144, 161, 171, 65, 42, 31, 214, 93, 115, 247, 69, 94, 143, 54, 51, 25, 49, 146, 204, 205, 165, 20, 120, 35, 184, 190, 65, 106, 12, 214, 176, 57, 125, 235, 51, 88, 135, 76, 73, 109, 112, 147, 138, 198, 252, 5, 20, 245, 51, 7, 32, 108, 89, 125, 204, 50, 189, 88, 254, 255, 146, 244, 244, 149, 79, 54, 216, 45, 89, 2, 3, 1, 0, 1]);
  let skData = new Uint8Array([48, 130, 2, 120, 2, 1, 0, 48, 13, 6, 9, 42, 134, 72, 134, 247, 13, 1, 1, 1, 5, 0, 4, 130, 2, 98, 48, 130, 2, 94, 2, 1, 0, 2, 129, 129, 0, 214, 179, 23, 198, 183, 139, 148, 8, 173, 74, 56, 160, 15, 248, 244, 166, 209, 250, 142, 74, 216, 58, 117, 215, 178, 247, 254, 39, 180, 227, 85, 201, 59, 133, 209, 221, 26, 9, 116, 31, 172, 151, 252, 185, 123, 20, 25, 7, 92, 129, 5, 196, 239, 214, 126, 254, 154, 188, 239, 144, 161, 171, 65, 42, 31, 214, 93, 115, 247, 69, 94, 143, 54, 51, 25, 49, 146, 204, 205, 165, 20, 120, 35, 184, 190, 65, 106, 12, 214, 176, 57, 125, 235, 51, 88, 135, 76, 73, 109, 112, 147, 138, 198, 252, 5, 20, 245, 51, 7, 32, 108, 89, 125, 204, 50, 189, 88, 254, 255, 146, 244, 244, 149, 79, 54, 216, 45, 89, 2, 3, 1, 0, 1, 2, 129, 129, 0, 152, 111, 145, 203, 10, 88, 116, 163, 112, 126, 9, 20, 68, 34, 235, 121, 98, 14, 182, 102, 151, 125, 114, 91, 210, 122, 215, 29, 212, 5, 176, 203, 238, 146, 5, 190, 41, 21, 91, 56, 125, 239, 111, 133, 53, 200, 192, 56, 132, 202, 42, 145, 120, 3, 224, 40, 223, 46, 148, 29, 41, 92, 17, 40, 12, 72, 165, 69, 192, 211, 142, 233, 81, 202, 177, 235, 156, 27, 179, 48, 18, 85, 154, 101, 193, 45, 218, 91, 24, 143, 196, 248, 16, 83, 177, 198, 136, 77, 111, 134, 60, 219, 95, 246, 23, 5, 45, 14, 83, 29, 137, 248, 159, 28, 132, 142, 205, 99, 226, 213, 84, 232, 57, 130, 156, 81, 191, 237, 2, 65, 0, 255, 158, 212, 13, 43, 132, 244, 135, 148, 161, 232, 219, 20, 81, 196, 102, 103, 44, 110, 71, 100, 62, 73, 200, 32, 138, 114, 209, 171, 150, 179, 92, 198, 5, 190, 218, 79, 227, 227, 37, 32, 57, 159, 252, 107, 211, 139, 198, 202, 248, 137, 143, 186, 205, 106, 81, 85, 207, 134, 148, 110, 204, 243, 27, 2, 65, 0, 215, 4, 181, 121, 57, 224, 170, 168, 183, 159, 152, 8, 74, 233, 80, 244, 146, 81, 48, 159, 194, 199, 36, 187, 6, 181, 182, 223, 115, 133, 151, 171, 78, 219, 90, 161, 248, 69, 6, 207, 173, 3, 81, 161, 2, 60, 238, 204, 177, 12, 138, 17, 220, 179, 71, 113, 200, 248, 159, 153, 252, 150, 180, 155, 2, 65, 0, 190, 202, 185, 211, 170, 171, 238, 40, 84, 84, 21, 13, 144, 57, 7, 178, 183, 71, 126, 120, 98, 229, 235, 4, 40, 229, 173, 149, 185, 209, 29, 199, 29, 54, 164, 161, 38, 8, 30, 62, 83, 179, 47, 42, 165, 0, 156, 207, 160, 39, 169, 229, 81, 180, 136, 170, 116, 182, 20, 233, 45, 90, 100, 9, 2, 65, 0, 152, 255, 47, 198, 15, 201, 238, 133, 89, 11, 133, 153, 184, 252, 37, 239, 177, 65, 118, 80, 231, 190, 222, 66, 250, 118, 72, 166, 221, 67, 156, 245, 119, 138, 28, 6, 142, 107, 71, 122, 116, 200, 156, 199, 237, 152, 191, 239, 4, 184, 64, 114, 143, 81, 62, 48, 23, 233, 217, 95, 47, 221, 104, 171, 2, 64, 30, 219, 1, 230, 241, 70, 246, 243, 121, 174, 67, 66, 11, 99, 202, 17, 52, 234, 78, 29, 3, 57, 51, 123, 149, 86, 64, 192, 73, 199, 108, 101, 55, 232, 41, 114, 153, 237, 253, 52, 205, 148, 45, 86, 186, 241, 182, 183, 42, 77, 252, 195, 29, 158, 173, 3, 182, 207, 254, 61, 71, 184, 167, 184]);
  let keyPair = await genKeyPairByData(pkData, skData);
  let inputUpdate: cryptoFramework.DataBlob = { data: new Uint8Array(buffer.from("This is Sign test plan1", 'utf-8').buffer) };
  let inputVerify: cryptoFramework.DataBlob = { data: new Uint8Array(buffer.from("This is Sign test plan2", 'utf-8').buffer) };
  // The data is signData.data in Sign().
  let signMessageBlob: cryptoFramework.DataBlob = { data: new Uint8Array([9, 68, 164, 161, 230, 155, 255, 153, 10, 12, 14, 22, 146, 115, 209, 167, 223, 133, 89, 173, 50, 249, 176, 104, 10, 251, 219, 104, 117, 196, 105, 65, 249, 139, 119, 41, 15, 171, 191, 11, 177, 177, 1, 119, 130, 142, 87, 183, 32, 220, 226, 28, 38, 73, 222, 172, 153, 26, 87, 58, 188, 42, 150, 67, 94, 214, 147, 64, 202, 87, 155, 125, 254, 112, 95, 176, 255, 207, 106, 43, 228, 153, 131, 240, 120, 88, 253, 179, 207, 207, 110, 223, 173, 15, 113, 11, 183, 122, 237, 205, 206, 123, 246, 33, 167, 169, 251, 237, 199, 26, 220, 152, 190, 117, 131, 74, 232, 50, 39, 172, 232, 178, 112, 73, 251, 235, 131, 209]) };
  let verifier = cryptoFramework.createVerify('RSA1024|PKCS1|SHA256');
  await verifier.init(keyPair.pubKey);
  await verifier.update(inputUpdate);
  let res = await verifier.verify(inputVerify, signMessageBlob);
  console.info('verify result: ' + res);
}
```

**Example (using the sync API)**

For more examples of signing and signature verification, see [Signing and Signature Verification with an RSA Key Pair (PKCS1 Mode)](../../security/CryptoArchitectureKit/crypto-rsa-sign-sig-verify-pkcs1.md).

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { buffer } from '@kit.ArkTS';

function genKeyPairByData(pubKeyData: Uint8Array, priKeyData: Uint8Array) {
  let pubKeyBlob: cryptoFramework.DataBlob = { data: pubKeyData };
  let priKeyBlob: cryptoFramework.DataBlob = { data: priKeyData };
  let rsaGenerator = cryptoFramework.createAsyKeyGenerator('RSA1024');
  let keyPair = rsaGenerator.convertKeySync(pubKeyBlob, priKeyBlob);
  console.info('convertKey success');
  return keyPair;
}

function verifyBySync() {
  // Key generated based on the key data and input data for signature verification. If the data in verify() is the same as that in sign(), the signature verification is successful.
  let pkData = new Uint8Array([48, 129, 159, 48, 13, 6, 9, 42, 134, 72, 134, 247, 13, 1, 1, 1, 5, 0, 3, 129, 141, 0, 48, 129, 137, 2, 129, 129, 0, 214, 179, 23, 198, 183, 139, 148, 8, 173, 74, 56, 160, 15, 248, 244, 166, 209, 250, 142, 74, 216, 58, 117, 215, 178, 247, 254, 39, 180, 227, 85, 201, 59, 133, 209, 221, 26, 9, 116, 31, 172, 151, 252, 185, 123, 20, 25, 7, 92, 129, 5, 196, 239, 214, 126, 254, 154, 188, 239, 144, 161, 171, 65, 42, 31, 214, 93, 115, 247, 69, 94, 143, 54, 51, 25, 49, 146, 204, 205, 165, 20, 120, 35, 184, 190, 65, 106, 12, 214, 176, 57, 125, 235, 51, 88, 135, 76, 73, 109, 112, 147, 138, 198, 252, 5, 20, 245, 51, 7, 32, 108, 89, 125, 204, 50, 189, 88, 254, 255, 146, 244, 244, 149, 79, 54, 216, 45, 89, 2, 3, 1, 0, 1]);
  let skData = new Uint8Array([48, 130, 2, 120, 2, 1, 0, 48, 13, 6, 9, 42, 134, 72, 134, 247, 13, 1, 1, 1, 5, 0, 4, 130, 2, 98, 48, 130, 2, 94, 2, 1, 0, 2, 129, 129, 0, 214, 179, 23, 198, 183, 139, 148, 8, 173, 74, 56, 160, 15, 248, 244, 166, 209, 250, 142, 74, 216, 58, 117, 215, 178, 247, 254, 39, 180, 227, 85, 201, 59, 133, 209, 221, 26, 9, 116, 31, 172, 151, 252, 185, 123, 20, 25, 7, 92, 129, 5, 196, 239, 214, 126, 254, 154, 188, 239, 144, 161, 171, 65, 42, 31, 214, 93, 115, 247, 69, 94, 143, 54, 51, 25, 49, 146, 204, 205, 165, 20, 120, 35, 184, 190, 65, 106, 12, 214, 176, 57, 125, 235, 51, 88, 135, 76, 73, 109, 112, 147, 138, 198, 252, 5, 20, 245, 51, 7, 32, 108, 89, 125, 204, 50, 189, 88, 254, 255, 146, 244, 244, 149, 79, 54, 216, 45, 89, 2, 3, 1, 0, 1, 2, 129, 129, 0, 152, 111, 145, 203, 10, 88, 116, 163, 112, 126, 9, 20, 68, 34, 235, 121, 98, 14, 182, 102, 151, 125, 114, 91, 210, 122, 215, 29, 212, 5, 176, 203, 238, 146, 5, 190, 41, 21, 91, 56, 125, 239, 111, 133, 53, 200, 192, 56, 132, 202, 42, 145, 120, 3, 224, 40, 223, 46, 148, 29, 41, 92, 17, 40, 12, 72, 165, 69, 192, 211, 142, 233, 81, 202, 177, 235, 156, 27, 179, 48, 18, 85, 154, 101, 193, 45, 218, 91, 24, 143, 196, 248, 16, 83, 177, 198, 136, 77, 111, 134, 60, 219, 95, 246, 23, 5, 45, 14, 83, 29, 137, 248, 159, 28, 132, 142, 205, 99, 226, 213, 84, 232, 57, 130, 156, 81, 191, 237, 2, 65, 0, 255, 158, 212, 13, 43, 132, 244, 135, 148, 161, 232, 219, 20, 81, 196, 102, 103, 44, 110, 71, 100, 62, 73, 200, 32, 138, 114, 209, 171, 150, 179, 92, 198, 5, 190, 218, 79, 227, 227, 37, 32, 57, 159, 252, 107, 211, 139, 198, 202, 248, 137, 143, 186, 205, 106, 81, 85, 207, 134, 148, 110, 204, 243, 27, 2, 65, 0, 215, 4, 181, 121, 57, 224, 170, 168, 183, 159, 152, 8, 74, 233, 80, 244, 146, 81, 48, 159, 194, 199, 36, 187, 6, 181, 182, 223, 115, 133, 151, 171, 78, 219, 90, 161, 248, 69, 6, 207, 173, 3, 81, 161, 2, 60, 238, 204, 177, 12, 138, 17, 220, 179, 71, 113, 200, 248, 159, 153, 252, 150, 180, 155, 2, 65, 0, 190, 202, 185, 211, 170, 171, 238, 40, 84, 84, 21, 13, 144, 57, 7, 178, 183, 71, 126, 120, 98, 229, 235, 4, 40, 229, 173, 149, 185, 209, 29, 199, 29, 54, 164, 161, 38, 8, 30, 62, 83, 179, 47, 42, 165, 0, 156, 207, 160, 39, 169, 229, 81, 180, 136, 170, 116, 182, 20, 233, 45, 90, 100, 9, 2, 65, 0, 152, 255, 47, 198, 15, 201, 238, 133, 89, 11, 133, 153, 184, 252, 37, 239, 177, 65, 118, 80, 231, 190, 222, 66, 250, 118, 72, 166, 221, 67, 156, 245, 119, 138, 28, 6, 142, 107, 71, 122, 116, 200, 156, 199, 237, 152, 191, 239, 4, 184, 64, 114, 143, 81, 62, 48, 23, 233, 217, 95, 47, 221, 104, 171, 2, 64, 30, 219, 1, 230, 241, 70, 246, 243, 121, 174, 67, 66, 11, 99, 202, 17, 52, 234, 78, 29, 3, 57, 51, 123, 149, 86, 64, 192, 73, 199, 108, 101, 55, 232, 41, 114, 153, 237, 253, 52, 205, 148, 45, 86, 186, 241, 182, 183, 42, 77, 252, 195, 29, 158, 173, 3, 182, 207, 254, 61, 71, 184, 167, 184]);
  let keyPair = genKeyPairByData(pkData, skData);
  let inputUpdate: cryptoFramework.DataBlob = { data: new Uint8Array(buffer.from("This is Sign test plan1", 'utf-8').buffer) };
  let inputVerify: cryptoFramework.DataBlob = { data: new Uint8Array(buffer.from("This is Sign test plan2", 'utf-8').buffer) };
  // The data is signData.data in Sign().
  let signMessageBlob: cryptoFramework.DataBlob = { data: new Uint8Array([9, 68, 164, 161, 230, 155, 255, 153, 10, 12, 14, 22, 146, 115, 209, 167, 223, 133, 89, 173, 50, 249, 176, 104, 10, 251, 219, 104, 117, 196, 105, 65, 249, 139, 119, 41, 15, 171, 191, 11, 177, 177, 1, 119, 130, 142, 87, 183, 32, 220, 226, 28, 38, 73, 222, 172, 153, 26, 87, 58, 188, 42, 150, 67, 94, 214, 147, 64, 202, 87, 155, 125, 254, 112, 95, 176, 255, 207, 106, 43, 228, 153, 131, 240, 120, 88, 253, 179, 207, 207, 110, 223, 173, 15, 113, 11, 183, 122, 237, 205, 206, 123, 246, 33, 167, 169, 251, 237, 199, 26, 220, 152, 190, 117, 131, 74, 232, 50, 39, 172, 232, 178, 112, 73, 251, 235, 131, 209]) };
  let verifier = cryptoFramework.createVerify('RSA1024|PKCS1|SHA256');
  verifier.initSync(keyPair.pubKey);
  verifier.updateSync(inputUpdate);
  let res = verifier.verifySync(inputVerify, signMessageBlob);
  console.info('verify result: ' + res);
}
```

### recover<sup>12+</sup>

recover(signatureData: DataBlob): Promise\<DataBlob | null>

Recovers the original data from a signature. This API uses a promise to return the result.

> **NOTE**
>
> Currently, only RSA is supported.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Signature

**Parameters**

| Name       | Type    | Mandatory| Description      |
| ------------- | -------- | ---- | ---------- |
| signatureData | [DataBlob](#datablob)  | Yes  | Signature data. |

**Return value**

| Type             | Description                          |
| ----------------- | ------------------------------ |
| Promise\<[DataBlob](#datablob)  \| null> | Promise used to return the data restored.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | memory error.          |
| 17620002 | runtime error.          |
| 17630001 | crypto operation error. |

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { buffer } from '@kit.ArkTS';

async function genKeyPairByData(pubKeyData: Uint8Array, priKeyData: Uint8Array) {
  let pubKeyBlob: cryptoFramework.DataBlob = { data: pubKeyData };
  let priKeyBlob: cryptoFramework.DataBlob = { data: priKeyData };
  let rsaGenerator = cryptoFramework.createAsyKeyGenerator('RSA1024');
  let keyPair = await rsaGenerator.convertKey(pubKeyBlob, priKeyBlob);
  console.info('convertKey success');
  return keyPair;
}

async function recoverByPromise() {
  // Key generated based on the key data and input data for signature verification. If the data in verify() is the same as that in sign(), the signature verification is successful.
  let pkData = new Uint8Array([48, 129, 159, 48, 13, 6, 9, 42, 134, 72, 134, 247, 13, 1, 1, 1, 5, 0, 3, 129, 141, 0, 48, 129, 137, 2, 129, 129, 0, 214, 179, 23, 198, 183, 139, 148, 8, 173, 74, 56, 160, 15, 248, 244, 166, 209, 250, 142, 74, 216, 58, 117, 215, 178, 247, 254, 39, 180, 227, 85, 201, 59, 133, 209, 221, 26, 9, 116, 31, 172, 151, 252, 185, 123, 20, 25, 7, 92, 129, 5, 196, 239, 214, 126, 254, 154, 188, 239, 144, 161, 171, 65, 42, 31, 214, 93, 115, 247, 69, 94, 143, 54, 51, 25, 49, 146, 204, 205, 165, 20, 120, 35, 184, 190, 65, 106, 12, 214, 176, 57, 125, 235, 51, 88, 135, 76, 73, 109, 112, 147, 138, 198, 252, 5, 20, 245, 51, 7, 32, 108, 89, 125, 204, 50, 189, 88, 254, 255, 146, 244, 244, 149, 79, 54, 216, 45, 89, 2, 3, 1, 0, 1]);
  let skData = new Uint8Array([48, 130, 2, 120, 2, 1, 0, 48, 13, 6, 9, 42, 134, 72, 134, 247, 13, 1, 1, 1, 5, 0, 4, 130, 2, 98, 48, 130, 2, 94, 2, 1, 0, 2, 129, 129, 0, 214, 179, 23, 198, 183, 139, 148, 8, 173, 74, 56, 160, 15, 248, 244, 166, 209, 250, 142, 74, 216, 58, 117, 215, 178, 247, 254, 39, 180, 227, 85, 201, 59, 133, 209, 221, 26, 9, 116, 31, 172, 151, 252, 185, 123, 20, 25, 7, 92, 129, 5, 196, 239, 214, 126, 254, 154, 188, 239, 144, 161, 171, 65, 42, 31, 214, 93, 115, 247, 69, 94, 143, 54, 51, 25, 49, 146, 204, 205, 165, 20, 120, 35, 184, 190, 65, 106, 12, 214, 176, 57, 125, 235, 51, 88, 135, 76, 73, 109, 112, 147, 138, 198, 252, 5, 20, 245, 51, 7, 32, 108, 89, 125, 204, 50, 189, 88, 254, 255, 146, 244, 244, 149, 79, 54, 216, 45, 89, 2, 3, 1, 0, 1, 2, 129, 129, 0, 152, 111, 145, 203, 10, 88, 116, 163, 112, 126, 9, 20, 68, 34, 235, 121, 98, 14, 182, 102, 151, 125, 114, 91, 210, 122, 215, 29, 212, 5, 176, 203, 238, 146, 5, 190, 41, 21, 91, 56, 125, 239, 111, 133, 53, 200, 192, 56, 132, 202, 42, 145, 120, 3, 224, 40, 223, 46, 148, 29, 41, 92, 17, 40, 12, 72, 165, 69, 192, 211, 142, 233, 81, 202, 177, 235, 156, 27, 179, 48, 18, 85, 154, 101, 193, 45, 218, 91, 24, 143, 196, 248, 16, 83, 177, 198, 136, 77, 111, 134, 60, 219, 95, 246, 23, 5, 45, 14, 83, 29, 137, 248, 159, 28, 132, 142, 205, 99, 226, 213, 84, 232, 57, 130, 156, 81, 191, 237, 2, 65, 0, 255, 158, 212, 13, 43, 132, 244, 135, 148, 161, 232, 219, 20, 81, 196, 102, 103, 44, 110, 71, 100, 62, 73, 200, 32, 138, 114, 209, 171, 150, 179, 92, 198, 5, 190, 218, 79, 227, 227, 37, 32, 57, 159, 252, 107, 211, 139, 198, 202, 248, 137, 143, 186, 205, 106, 81, 85, 207, 134, 148, 110, 204, 243, 27, 2, 65, 0, 215, 4, 181, 121, 57, 224, 170, 168, 183, 159, 152, 8, 74, 233, 80, 244, 146, 81, 48, 159, 194, 199, 36, 187, 6, 181, 182, 223, 115, 133, 151, 171, 78, 219, 90, 161, 248, 69, 6, 207, 173, 3, 81, 161, 2, 60, 238, 204, 177, 12, 138, 17, 220, 179, 71, 113, 200, 248, 159, 153, 252, 150, 180, 155, 2, 65, 0, 190, 202, 185, 211, 170, 171, 238, 40, 84, 84, 21, 13, 144, 57, 7, 178, 183, 71, 126, 120, 98, 229, 235, 4, 40, 229, 173, 149, 185, 209, 29, 199, 29, 54, 164, 161, 38, 8, 30, 62, 83, 179, 47, 42, 165, 0, 156, 207, 160, 39, 169, 229, 81, 180, 136, 170, 116, 182, 20, 233, 45, 90, 100, 9, 2, 65, 0, 152, 255, 47, 198, 15, 201, 238, 133, 89, 11, 133, 153, 184, 252, 37, 239, 177, 65, 118, 80, 231, 190, 222, 66, 250, 118, 72, 166, 221, 67, 156, 245, 119, 138, 28, 6, 142, 107, 71, 122, 116, 200, 156, 199, 237, 152, 191, 239, 4, 184, 64, 114, 143, 81, 62, 48, 23, 233, 217, 95, 47, 221, 104, 171, 2, 64, 30, 219, 1, 230, 241, 70, 246, 243, 121, 174, 67, 66, 11, 99, 202, 17, 52, 234, 78, 29, 3, 57, 51, 123, 149, 86, 64, 192, 73, 199, 108, 101, 55, 232, 41, 114, 153, 237, 253, 52, 205, 148, 45, 86, 186, 241, 182, 183, 42, 77, 252, 195, 29, 158, 173, 3, 182, 207, 254, 61, 71, 184, 167, 184]);
  let keyPair = await genKeyPairByData(pkData, skData);
  // The data is signData.data in Sign().
  let signMessageBlob: cryptoFramework.DataBlob = { data: new Uint8Array([9, 68, 164, 161, 230, 155, 255, 153, 10, 12, 14, 22, 146, 115, 209, 167, 223, 133, 89, 173, 50, 249, 176, 104, 10, 251, 219, 104, 117, 196, 105, 65, 249, 139, 119, 41, 15, 171, 191, 11, 177, 177, 1, 119, 130, 142, 87, 183, 32, 220, 226, 28, 38, 73, 222, 172, 153, 26, 87, 58, 188, 42, 150, 67, 94, 214, 147, 64, 202, 87, 155, 125, 254, 112, 95, 176, 255, 207, 106, 43, 228, 153, 131, 240, 120, 88, 253, 179, 207, 207, 110, 223, 173, 15, 113, 11, 183, 122, 237, 205, 206, 123, 246, 33, 167, 169, 251, 237, 199, 26, 220, 152, 190, 117, 131, 74, 232, 50, 39, 172, 232, 178, 112, 73, 251, 235, 131, 209]) };
  let verifier = cryptoFramework.createVerify('RSA1024|PKCS1|SHA256|Recover');
  await verifier.init(keyPair.pubKey);
  try {
    let rawSignData = await verifier.recover(signMessageBlob);
    if (rawSignData != null) {
      console.info('[Promise]: recover result: ' + rawSignData.data);
    } else {
      console.error("[Promise]: get verify recover result fail!");
    }
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    console.error(`promise error, ${e.code}, ${e.message}`);
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
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | memory error.          |
| 17620002 | runtime error.          |
| 17630001 | crypto operation error. |

### setVerifySpec<sup>10+</sup>

setVerifySpec(itemType: SignSpecItem, itemValue: number): void

setVerifySpec(itemType: SignSpecItem, itemValue: number \| Uint8Array): void

Sets signature verification specifications. You can use this API to set signature verification parameters that cannot be set by [createVerify](#cryptoframeworkcreateverify).

Currently, only RSA and SM2 are supported. Since API version 11, SM2 signing parameters can be set.

The parameters for signature verification must be the same as those for signing.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Signature

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 10 to 11 and SystemCapability.Security.CryptoFramework.Signature since API version 12.

**Parameters**

| Name  | Type                | Mandatory| Description      |
| -------- | -------------------- | ---- | ---------- |
| itemType     | [SignSpecItem](#signspecitem10)              | Yes  | Signature verification parameter to set.|
| itemValue | number \| Uint8Array<sup>11+</sup> | Yes  | Value of the signature verification parameter to set.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 801 | this operation is not supported.          |
| 17620001 | memory error.          |
| 17630001 | crypto operation error. |

**Example**

<!--code_no_check-->
```ts
let verifyer: cryptoFramework.Verify; // The process of generating the Verify instance is omitted here.
let setN = 20;
verifyer.setVerifySpec(cryptoFramework.SignSpecItem.PSS_SALT_LEN_NUM, setN);
```

### getVerifySpec<sup>10+</sup>

getVerifySpec(itemType: SignSpecItem): string | number

Obtains signature verification specifications. Currently, only RSA is supported.

The parameters for signature verification must be the same as those for signing.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Signature

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 10 to 11 and SystemCapability.Security.CryptoFramework.Signature since API version 12.

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
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 801 | this operation is not supported.          |
| 17620001 | memory error.          |
| 17630001 | crypto operation error. |

**Example**

<!--code_no_check-->
```ts
let verifyer: cryptoFramework.Verify; // The process of generating the Verify instance is omitted here.
let saltLen = verifyer.getVerifySpec(cryptoFramework.SignSpecItem.PSS_SALT_LEN_NUM);
```

## cryptoFramework.createKeyAgreement

createKeyAgreement(algName: string): KeyAgreement

Creates a **KeyAgreement** instance.

For details about the supported specifications, see [Key Agreement Overview and Algorithm Specifications](../../security/CryptoArchitectureKit/crypto-key-agreement-overview.md).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.KeyAgreement

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 9 to 11 and SystemCapability.Security.CryptoFramework.KeyAgreement since API version 12.

**Parameters**

| Name | Type  | Mandatory| Description                                                        |
| ------- | ------ | ---- | ------------------------------------------------------------ |
| algName | string | Yes  | Key agreement algorithm to use. In addition to ECC, X25519 and DH are supported since API version 11.|

**Return value**

| Type        | Description                                      |
| ------------ | ------------------------------------------ |
| KeyAgreement | Returns the **KeyAgreement** instance created.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 801 | this operation is not supported.          |
| 17620001 | memory error.          |

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';

let keyAgreement = cryptoFramework.createKeyAgreement('ECC256');
```

## KeyAgreement

Provides APIs for key agreement operations. Before using any API of the **KeyAgreement** class, you must create a **KeyAgreement** instance by using [createKeyAgreement(algName: string): KeyAgreement](#cryptoframeworkcreatekeyagreement).

### Attributes

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.KeyAgreement

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 9 to 11 and SystemCapability.Security.CryptoFramework.KeyAgreement since API version 12.

| Name   | Type  | Readable| Writable| Description                        |
| ------- | ------ | ---- | ---- | ---------------------------- |
| algName | string | Yes  | No  | Algorithm used for key agreement.|

### generateSecret

generateSecret(priKey: PriKey, pubKey: PubKey, callback: AsyncCallback\<DataBlob>): void

Generates a shared secret based on the given private key and public key. This API uses an asynchronous callback to return the shared secret generated.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.KeyAgreement

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 9 to 11 and SystemCapability.Security.CryptoFramework.KeyAgreement since API version 12.

**Parameters**

| Name  | Type                    | Mandatory| Description                  |
| -------- | ------------------------ | ---- | ---------------------- |
| priKey   | [PriKey](#prikey)        | Yes  | Private key used for key agreement.|
| pubKey   | [PubKey](#pubkey)        | Yes  | Public key used for key agreement.|
| callback | AsyncCallback\<[DataBlob](#datablob)> | Yes  | Callback used to return the shared secret.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | memory error.          |
| 17620002 | runtime error.          |
| 17630001 | crypto operation error. |

### generateSecret

generateSecret(priKey: PriKey, pubKey: PubKey): Promise\<DataBlob>

Generates a shared secret based on the given private key and public key. This API uses a promise to return the shared secret generated.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.KeyAgreement

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 9 to 11 and SystemCapability.Security.CryptoFramework.KeyAgreement since API version 12.

**Parameters**

| Name| Type  | Mandatory| Description                  |
| ------ | ------ | ---- | ---------------------- |
| priKey | [PriKey](#prikey) | Yes  | Private key used for key agreement.|
| pubKey | [PubKey](#pubkey) | Yes  | Public key used for key agreement.|

**Return value**

| Type              | Description    |
| ------------------ | -------- |
| Promise\<[DataBlob](#datablob)> | Promise used to return the shared secret. |

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | memory error.          |
| 17620002 | runtime error.          |
| 17630001 | crypto operation error. |

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
|[DataBlob](#datablob) | Shared secret generated.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | memory error.          |
| 17620002 | runtime error.          |
| 17630001 | crypto operation error. |

**Example (using the callback-based API)**

<!--code_no_check-->
```ts
import { BusinessError } from '@kit.BasicServicesKit';

let globalKeyPair: cryptoFramework.KeyPair; // globalKeyPair is an asymmetric key object generated by the asymmetric key generator. The generation process is omitted here.
let keyAgreement = cryptoFramework.createKeyAgreement('ECC256');
keyAgreement.generateSecret(globalKeyPair.priKey, globalKeyPair.pubKey, (err, secret) => {
  if (err) {
    console.error("keyAgreement error.");
    return;
  }
  console.info('keyAgreement output is ' + secret.data);
});
```

**Example (using the promise-based API)**

<!--code_no_check-->
```ts
import { BusinessError } from '@kit.BasicServicesKit';

let globalKeyPair: cryptoFramework.KeyPair; // globalKeyPair is an asymmetric key object generated by the asymmetric key generator. The generation process is omitted here.
let keyAgreement = cryptoFramework.createKeyAgreement('ECC256');
let keyAgreementPromise = keyAgreement.generateSecret(globalKeyPair.priKey, globalKeyPair.pubKey);
keyAgreementPromise.then(secret => {
  console.info('keyAgreement output is ' + secret.data);
}).catch((error: BusinessError) => {
  console.error("keyAgreement error.");
});
```

**Example (using the sync API)**

<!--code_no_check-->
```ts
let asyGenerator = cryptoFramework.CreateAsyKeyGenerator("ECC256");
let globalKeyPair = asyGenerator.generateKeyPairSync();
let keyAgreement = cryptoFramework.createKeyAgreement('ECC256');
let secret = keyAgreement.generateSecretSync(globalKeyPair.priKey, globalKeyPair.pubKey);
console.info("[Sync]keyAgreement output is " + secret.data);
```

## cryptoFramework.createMd

createMd(algName: string): Md

Creates an **Md** instance for MD operations.

For details about the supported specifications, see [Supported Algorithms and Specifications](../../security/CryptoArchitectureKit/crypto-generate-message-digest.md#supported-algorithms-and-specifications).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.MessageDigest

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 9 to 11 and SystemCapability.Security.CryptoFramework.MessageDigest since API version 12.

**Parameters**

| Name | Type  | Mandatory| Description                                                        |
| ------- | ------ | ---- | ------------------------------------------------------------ |
| algName | string | Yes  | MD algorithm to use. For details about the supported algorithms, see [Supported Algorithms and Specifications](../../security/CryptoArchitectureKit/crypto-generate-message-digest.md#supported-algorithms-and-specifications).|

**Return value**

| Type| Description                                   |
| ---- | --------------------------------------- |
| Md   | Returns the [Md](#md) instance created.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message          |
| -------- | ------------------ |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | memory error.       |

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  // Set algName based on the algorithm supported.
  let md = cryptoFramework.createMd('SHA256');
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`sync error, ${e.code}, ${e.message}`);
}
```

## Md

Provides APIs for MD operations. Before using any API of the **Md** class, you must create an **Md** instance by using [createMd](#cryptoframeworkcreatemd).

### Attributes

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.MessageDigest

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 9 to 11 and SystemCapability.Security.CryptoFramework.MessageDigest since API version 12.

| Name   | Type  | Readable| Writable| Description                  |
| ------- | ------ | ---- | ---- | ---------------------- |
| algName | string | Yes  | No  | Digest algorithm.|

### update

update(input: DataBlob, callback: AsyncCallback\<void>): void

Updates the message for MD operations. This API uses an asynchronous callback to return the result. **update** must be used with **digest** together. **digest** is mandatory, and **update** is optional.

> **NOTE**
>
> For details about the code for calling **update** multiple times in an MD operation, see [MD (Passing In Data by Segment)](../../security/CryptoArchitectureKit/crypto-generate-message-digest.md#md-passing-in-data-by-segment).
 
**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.MessageDigest

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 9 to 11 and SystemCapability.Security.CryptoFramework.MessageDigest since API version 12.

**Parameters**

| Name  | Type                 | Mandatory| Description        |
| -------- | --------------------- | ---- | ------------ |
| input    | [DataBlob](#datablob) | Yes  | Data to pass in.|
| callback | AsyncCallback\<void>  | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object. |

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17630001 | crypto operation error. |

### update

update(input: DataBlob): Promise\<void>

Updates the message for MD operations. This API uses a promise to return the result. **update** must be used with **digest** together. **digest** is mandatory, and **update** is optional.

> **NOTE**
>
> For details about the code for calling **update** multiple times in an MD operation, see [MD (Passing In Data by Segment)](../../security/CryptoArchitectureKit/crypto-generate-message-digest.md#md-passing-in-data-by-segment).
 

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.MessageDigest

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 9 to 11 and SystemCapability.Security.CryptoFramework.MessageDigest since API version 12.

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
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17630001 | crypto operation error. |

### updateSync<sup>12+</sup>

updateSync(input: DataBlob): void

Updates the message for MD operations. This API returns the result synchronously. **updateSync** must be used with **digestSync** together. **digestSync** is mandatory, and **updateSync** is optional.

> **NOTE**
>
> For details about the code for calling **updateSync** multiple times in an MD operation, see [MD (Passing In Data by Segment)](../../security/CryptoArchitectureKit/crypto-generate-message-digest.md#md-passing-in-data-by-segment).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.MessageDigest

| Name| Type    | Mandatory| Description        |
| ------ | -------- | ---- | ------------ |
| input  | [DataBlob](#datablob) | Yes  | Data to pass in.|

**Return value**

| Type          | Description         |
| -------------- | ------------- |
| void | No value is returned.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.      |
| 17630001 | crypto operation error. |

### digest

digest(callback: AsyncCallback\<DataBlob>): void

Generates an MD. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.MessageDigest

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 9 to 11 and SystemCapability.Security.CryptoFramework.MessageDigest since API version 12.

| Name  | Type                    | Mandatory| Description      |
| -------- | ------------------------ | ---- | ---------- |
| callback | AsyncCallback\<[DataBlob](#datablob)> | Yes  | Callback invoked to return a **DataBlob** object.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 17620001 | memory error.           |
| 17630001 | crypto operation error. |

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { buffer } from '@kit.ArkTS';

function mdByCallback() {
  let md = cryptoFramework.createMd('SHA256');
  md.update({ data: new Uint8Array(buffer.from("mdTestMessage", 'utf-8').buffer) }, (err,) => {
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

**System capability**: SystemCapability.Security.CryptoFramework.MessageDigest

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 9 to 11 and SystemCapability.Security.CryptoFramework.MessageDigest since API version 12.

**Return value**

| Type              | Description       |
| ------------------ | ----------- |
| Promise\<[DataBlob](#datablob)> | Promise used to return the result.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 17620001 | memory error.           |
| 17630001 | crypto operation error. |

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { buffer } from '@kit.ArkTS';

async function mdByPromise() {
  let md = cryptoFramework.createMd('SHA256');
  await md.update({ data: new Uint8Array(buffer.from("mdTestMessage", 'utf-8').buffer) });
  let mdOutput = await md.digest();
  console.info('[Promise]: MD result: ' + mdOutput.data);
  console.info('[Promise]: MD len: ' + md.getMdLength());
}
```

### digestSync<sup>12+</sup>

digestSync(): DataBlob

Generates an MD. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.MessageDigest

**Return value**

| Type              | Description       |
| ------------------ | ----------- |
| [DataBlob](#datablob) | MD generated.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.         |
| 17620001 | memory error. |
| 17620002 | runtime error. |
| 17630001 | crypto operation error. |

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { buffer } from '@kit.ArkTS';

async function mdBySync() {
  let md = cryptoFramework.createMd('SHA256');
  md.updateSync({ data: new Uint8Array(buffer.from("mdTestMessage", 'utf-8').buffer) });
  let mdOutput = md.digestSync();
  console.info('[Sync]: MD result: ' + mdOutput.data);
  console.info('[Sync]: MD len: ' + md.getMdLength());
}
```

### getMdLength

getMdLength(): number

Obtains the MD length, in bytes.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.MessageDigest

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 9 to 11 and SystemCapability.Security.CryptoFramework.MessageDigest since API version 12.

**Return value**

| Type  | Description                      |
| ------ | -------------------------- |
| number | MD length obtained.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 17630001 | crypto operation error. |

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

Creates a **Mac** instance for message authentication code (MAC) operations.

For details about the supported specifications, see [Supported Algorithms and Specifications](../../security/CryptoArchitectureKit/crypto-compute-mac.md#supported-algorithms-and-specifications).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Mac

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 9 to 11 and SystemCapability.Security.CryptoFramework.Mac since API version 12.

**Parameters**

| Name | Type  | Mandatory| Description                                                        |
| ------- | ------ | ---- | ------------------------------------------------------------ |
| algName | string | Yes  | MD algorithm to use. For details about the supported algorithms, see [Supported Algorithms and Specifications](../../security/CryptoArchitectureKit/crypto-compute-mac.md#supported-algorithms-and-specifications).|

**Return value**

| Type| Description                                     |
| ---- | ----------------------------------------- |
| Mac  | Returns the [Mac](#mac) instance created.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message          |
| -------- | ------------------ |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | memory error.       |

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  // Set algName based on the algorithm supported.
  let mac = cryptoFramework.createMac('SHA256');
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`sync error, ${e.code}, ${e.message}`);
}
```

## Mac

Provides APIs for MAC operations. Before using any API of the **Mac** class, you must create a **Mac** instance by using [createMac](#cryptoframeworkcreatemac).

### Attributes

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Mac

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 9 to 11 and SystemCapability.Security.CryptoFramework.Mac since API version 12.

| Name   | Type  | Readable| Writable| Description                  |
| ------- | ------ | ---- | ---- | ---------------------- |
| algName | string | Yes  | No  | Digest algorithm.|

### init

init(key: SymKey, callback: AsyncCallback\<void>): void

Initializes the MAC computation with a symmetric key. This API uses an asynchronous callback to return the result. **init**, **update**, and **doFinal** must be used together. **init** and **doFinal** are mandatory, and **update** is optional.

  > **NOTE**
  >
  > You are advised to create a symmetric key generator based on the [HMAC key generation specifications](../../security/CryptoArchitectureKit/crypto-sym-key-generation-conversion-spec.md#hmac) and use [generateSymKey](#generatesymkey) to randomly generate a symmetric key or use [convertKey](#convertkey) to convert the binary data (whose length is the same as the key specifications) into a key.<br>If **HMAC** is specified to generate the symmetric key generator, only [convertKey](#convertkey) can be called to pass in a binary key of 1 to 4096 bytes.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Mac

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 9 to 11 and SystemCapability.Security.CryptoFramework.Mac since API version 12.

**Parameters**

| Name  | Type                | Mandatory| Description          |
| -------- | -------------------- | ---- | -------------- |
| key      | [SymKey](#symkey)    | Yes  | Shared symmetric key.|
| callback | AsyncCallback\<void> | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object. |

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17630001 | crypto operation error. |

### init

init(key: SymKey): Promise\<void>

Initializes the MAC computation with a symmetric key. This API uses a promise to return the result. **init**, **update**, and **doFinal** must be used together. **init** and **doFinal** are mandatory, and **update** is optional.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Mac

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 9 to 11 and SystemCapability.Security.CryptoFramework.Mac since API version 12.

**Parameters**

| Name| Type  | Mandatory| Description        |
| ------ | ------ | ---- | ------------ |
| key    | [SymKey](#symkey) | Yes  | Shared symmetric key.|

**Return value**

| Type          | Description         |
| -------------- | ------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17630001 | crypto operation error. |

### initSync<sup>12+</sup>

initSync(key: SymKey): void

Initializes the MAC computation with a symmetric key. This API returns the result synchronously. **initSync**, **updateSync**, and **doFinalSync** must be used together. **initSync** and **doFinalSync** are mandatory, and **updateSync** is optional.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Mac

**Parameters**

| Name| Type  | Mandatory| Description        |
| ------ | ------ | ---- | ------------ |
| key    | [SymKey](#symkey) | Yes  | Shared symmetric key.|

**Return value**

| Type          | Description         |
| -------------- | ------------- |
| void | No value is returned.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.     |
| 17630001 | crypto operation error. |

### update

update(input: DataBlob, callback: AsyncCallback\<void>): void

Updates the message for MAC computation. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> For details about the sample code for calling **update** multiple times in an HMAC operation, see [HMAC (Passing In Data by Segment)](../../security/CryptoArchitectureKit/crypto-compute-mac.md#hmac-passing-in-data-by-segment).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Mac

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 9 to 11 and SystemCapability.Security.CryptoFramework.Mac since API version 12.

**Parameters**

| Name  | Type                 | Mandatory| Description        |
| -------- | --------------------- | ---- | ------------ |
| input    | [DataBlob](#datablob) | Yes  | Data to pass in.|
| callback | AsyncCallback\<void>  | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17630001 | crypto operation error. |

### update

update(input: DataBlob): Promise\<void>

Updates the message for MAC computation. This API uses a promise to return the result.

> **NOTE**
>
> For details about the sample code for calling **update** multiple times in an HMAC operation, see [HMAC (Passing In Data by Segment)](../../security/CryptoArchitectureKit/crypto-compute-mac.md#hmac-passing-in-data-by-segment).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Mac

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 9 to 11 and SystemCapability.Security.CryptoFramework.Mac since API version 12.

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
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17630001 | crypto operation error. |

### updateSync<sup>12+</sup>

updateSync(input: DataBlob): void

Updates the message for MAC computation. This API returns the result synchronously.

> **NOTE**
>
> For details about the sample code for calling **updateSync** multiple times in an HMAC operation, see [HMAC (Passing In Data by Segment)](../../security/CryptoArchitectureKit/crypto-compute-mac.md#hmac-passing-in-data-by-segment).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Mac

**Parameters**

| Name| Type    | Mandatory| Description      |
| ------ | -------- | ---- | ---------- |
| input  | [DataBlob](#datablob) | Yes  | Data to pass in.|

**Return value**

| Type          | Description         |
| -------------- | ------------- |
| void | No value is returned.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.      |
| 17630001 | crypto operation error. |

### doFinal

doFinal(callback: AsyncCallback\<DataBlob>): void

Finishes the MAC computation. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Mac

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 9 to 11 and SystemCapability.Security.CryptoFramework.Mac since API version 12.

**Parameters**

| Name  | Type                    | Mandatory| Description    |
| -------- | ------------------------ | ---- | -------- |
| callback | AsyncCallback\<[DataBlob](#datablob)> | Yes  | Callback invoked to return a **DataBlob** object.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 17620001 | memory error.           |
| 17630001 | crypto operation error. |

**Example**

For more HMAC operation examples, see [MAC Operation](../../security/CryptoArchitectureKit/crypto-compute-mac.md).

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { buffer } from '@kit.ArkTS';

function hmacByCallback() {
  let mac = cryptoFramework.createMac('SHA256');
  let keyBlob: cryptoFramework.DataBlob = { data: new Uint8Array(buffer.from("12345678abcdefgh", 'utf-8').buffer) };
  let symKeyGenerator = cryptoFramework.createSymKeyGenerator('AES128');
  symKeyGenerator.convertKey(keyBlob, (err, symKey) => {
    mac.init(symKey, (err,) => {
      mac.update({ data: new Uint8Array(buffer.from("hmacTestMessage", 'utf-8').buffer) }, (err,) => {
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

Finishes the MAC computation. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Mac

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 9 to 11 and SystemCapability.Security.CryptoFramework.Mac since API version 12.

**Return value**

| Type              | Description       |
| ------------------ | ----------- |
| Promise\<[DataBlob](#datablob)> | Promise used to return the result.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 17620001 | memory error.           |
| 17630001 | crypto operation error. |

**Example**

For more HMAC operation examples, see [MAC Operation](../../security/CryptoArchitectureKit/crypto-compute-mac.md).

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { buffer } from '@kit.ArkTS';

async function hmacByPromise() {
  let mac = cryptoFramework.createMac('SHA256');
  let keyBlob: cryptoFramework.DataBlob = { data: new Uint8Array(buffer.from("12345678abcdefgh", 'utf-8').buffer) };
  let symKeyGenerator = cryptoFramework.createSymKeyGenerator('AES128');
  let symKey = await symKeyGenerator.convertKey(keyBlob);
  await mac.init(symKey);
  await mac.update({ data: new Uint8Array(buffer.from("hmacTestMessage", 'utf-8').buffer) });
  let macOutput = await mac.doFinal();
  console.info('[Promise]: HMAC result: ' + macOutput.data);
  console.info('[Promise]: MAC len: ' + mac.getMacLength());
}
```

### doFinalSync<sup>12+</sup>

doFinalSync(): DataBlob

Finishes the MAC computation. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Mac

**Return value**

| Type              | Description       |
| ------------------ | ----------- |
| [DataBlob](#datablob) | MAC computation result.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.          |
| 17620001 | memory error.           |
| 17620002 | runtime error. |
| 17630001 | crypto operation error. |

**Example**

For more HMAC operation examples, see [MAC Operation](../../security/CryptoArchitectureKit/crypto-compute-mac.md).

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { buffer } from '@kit.ArkTS';

function hmacBySync() {
  let mac = cryptoFramework.createMac('SHA256');
  let keyBlob: cryptoFramework.DataBlob = { data: new Uint8Array(buffer.from("12345678abcdefgh", 'utf-8').buffer) };
  let symKeyGenerator = cryptoFramework.createSymKeyGenerator('AES128');
  let symKey = symKeyGenerator.convertKeySync(keyBlob);
  mac.initSync(symKey);
  mac.updateSync({ data: new Uint8Array(buffer.from("hmacTestMessage", 'utf-8').buffer) });
  let macOutput = mac.doFinalSync();
  console.info('[Sync]: HMAC result: ' + macOutput.data);
  console.info('[Sync]: MAC len: ' + mac.getMacLength());
}
```

### getMacLength

getMacLength(): number

Obtains the MAC length, in bytes.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Mac

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 9 to 11 and SystemCapability.Security.CryptoFramework.Mac since API version 12.

**Return value**

| Type  | Description                       |
| ------ | --------------------------- |
| number | MAC length obtained.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 17630001 | crypto operation error. |

**Example**

<!--code_no_check-->
```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { BusinessError } from '@kit.BasicServicesKit';

let mac = cryptoFramework.createMac('SHA256');
console.info('Mac algName is: ' + mac.algName);
let keyData = new Uint8Array([83, 217, 231, 76, 28, 113, 23, 219, 250, 71, 209, 210, 205, 97, 32, 159]);
let keyBlob: cryptoFramework.DataBlob = { data: keyData };
let symKeyGenerator = cryptoFramework.createSymKeyGenerator('AES128');
let promiseConvertKey = symKeyGenerator.convertKey(keyBlob);
promiseConvertKey.then(symKey => {
  let promiseMacInit = mac.init(symKey);
  return promiseMacInit;
}).then(() => {
  let blob: cryptoFramework.DataBlob = { data : new Uint8Array([83])};
  let promiseMacUpdate = mac.update(blob);
  return promiseMacUpdate;
}).then(() => {
  let promiseMacDoFinal = mac.doFinal();
  return promiseMacDoFinal;
}).then(macOutput => {
  console.info('[Promise]: HMAC result: ' + macOutput.data);
  let macLen = mac.getMacLength();
  console.info('MAC len: ' + macLen);
}).catch((error: BusinessError) => {
  console.error("[Promise]: error: " + error.message);
});
```

## cryptoFramework.createRandom

createRandom(): Random

Creates a **Random** instance for generating random numbers and setting seeds.

For details about the supported specifications, see [Supported Algorithms and Specifications](../../security/CryptoArchitectureKit/crypto-generate-random-number.md#supported-algorithms-and-specifications).

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Security.CryptoFramework.Rand

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 9 to 11 and SystemCapability.Security.CryptoFramework.Rand since API version 12.

**Return value**

| Type  | Description                                           |
| ------ | ----------------------------------------------- |
| Random | Returns the [Random](#random) instance created.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message    |
| -------- | ------------ |
| 17620001 | memory error. |

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let rand = cryptoFramework.createRandom();
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`sync error, ${e.code}, ${e.message}`);
}
```

## Random

Provides APIs for computing random numbers and setting seeds. Before using any API of the **Random** class, you must create a **Random** instance by using [createRandom](#cryptoframeworkcreaterandom).

### Attributes

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Security.CryptoFramework.Rand

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 9 to 11 and SystemCapability.Security.CryptoFramework.Rand since API version 12.

| Name   | Type  | Readable| Writable| Description                |
| ------- | ------ | ---- | ---- | -------------------- |
| algName<sup>10+</sup> | string | Yes  | No  | Algorithm used to generate the random number. Currently, only **CTR_DRBG** is supported.|

### generateRandom

generateRandom(len: number, callback: AsyncCallback\<DataBlob>): void

Generates a random number of the specified length. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Security.CryptoFramework.Rand

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 9 to 11 and SystemCapability.Security.CryptoFramework.Rand since API version 12.

**Parameters**

| Name  | Type                    | Mandatory| Description                |
| -------- | ------------------------ | ---- | -------------------- |
| len      | number                   | Yes  | Length of the random number to generate, in bytes. The value range is [1, INT_MAX].|
| callback | AsyncCallback\<[DataBlob](#datablob)> | Yes  | Callback invoked to return a **DataBlob** object.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | memory error.          |
| 17630001 | crypto operation error. |

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';

let rand = cryptoFramework.createRandom();
rand.generateRandom(12, (err, randData) => {
  if (err) {
    console.error("[Callback] err: " + err.code);
  } else {
    console.info('[Callback]: generate random result: ' + randData.data);
  }
});
```

### generateRandom

generateRandom(len: number): Promise\<DataBlob>

Generates a random number of the specified length. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Security.CryptoFramework.Rand

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 9 to 11 and SystemCapability.Security.CryptoFramework.Rand since API version 12.

**Parameters**

| Name| Type  | Mandatory| Description                                                  |
| ------ | ------ | ---- | ------------------------------------------------------ |
| len    | number | Yes  | Length of the random number to generate, in bytes. The value range is [1, INT_MAX].|

**Return value**

| Type              | Description       |
| ------------------ | ----------- |
| Promise\<[DataBlob](#datablob)> | Promise used to return the result.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | memory error.           |
| 17630001 | crypto operation error. |

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { BusinessError } from '@kit.BasicServicesKit';

let rand = cryptoFramework.createRandom();
let promiseGenerateRand = rand.generateRandom(12);
promiseGenerateRand.then(randData => {
  console.info('[Promise]: rand result: ' + randData.data);
}).catch((error: BusinessError) => {
  console.error("[Promise]: error: " + error.message);
});
```

### generateRandomSync<sup>10+</sup>

generateRandomSync(len: number): DataBlob

Generates a random number of the specified length. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Security.CryptoFramework.Rand

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 10 to 11 and SystemCapability.Security.CryptoFramework.Rand since API version 12.

**Parameters**

| Name| Type  | Mandatory| Description                |
| ------ | ------ | ---- | -------------------- |
| len    | number | Yes  | Length of the random number to generate, in bytes. The value range is [1, INT_MAX].|

**Return value**

| Type              | Description       |
| ------------------ | ----------- |
|[DataBlob](#datablob) | Returns the generated random number.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | memory error.           |
| 17630001 | crypto operation error. |

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { BusinessError } from '@kit.BasicServicesKit';

let rand = cryptoFramework.createRandom();
try {
  let randData = rand.generateRandomSync(12);
  if (randData != null) {
    console.info('[Sync]: rand result: ' + randData.data);
  } else {
    console.error("[Sync]: get rand result fail!");
  }
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`sync error, ${e.code}, ${e.message}`);
}
```

### setSeed

setSeed(seed: DataBlob): void

Sets a seed.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Security.CryptoFramework.Rand

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 9 to 11 and SystemCapability.Security.CryptoFramework.Rand since API version 12.

| Name| Type    | Mandatory| Description        |
| ------ | -------- | ---- | ------------ |
| seed   | [DataBlob](#datablob) | Yes  | Seed to set.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message          |
| -------- | ----------------- |
| 17620001 | memory error.      |

**Example**

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { BusinessError } from '@kit.BasicServicesKit';

let rand = cryptoFramework.createRandom();
rand.generateRandom(12, (err, randData) => {
  if (err) {
    console.error("[Callback] err: " + err.code);
  } else {
    console.info('[Callback]: generate random result: ' + randData.data);
    try {
      rand.setSeed(randData);
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      console.error(`sync error, ${e.code}, ${e.message}`);
    }
  }
});
```

## cryptoFramework.createKdf<sup>11+</sup>

createKdf(algName: string): Kdf

Creates a key derivation function instance.<br>For details about the supported specifications, see [Key Derivation Overview and Algorithm Specifications](../../security/CryptoArchitectureKit/crypto-key-derivation-overview.md).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Kdf

The supported system capability is SystemCapability.Security.CryptoFramework in API version 11 and SystemCapability.Security.CryptoFramework.Kdf since API version 12.

**Parameters**

| Name | Type  | Mandatory| Description                             |
| ------- | ------ | ---- | --------------------------------- |
| algName | string | Yes  | Key derivation algorithm (including the hash function for the HMAC). Currently, only PBKDF2 and HKDF are supported. For example, **PBKDF2\|SHA256** and **HKDF\|SHA256**.  |

**Return value**

| Type        | Description                                      |
| ------------ | ------------------------------------------ |
| [Kdf](#kdf11) | Key derivation function instance created.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 801 | this operation is not supported.          |
| 17620001 | memory error.          |

**Example**
- PBKDF2
```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';

let kdf = cryptoFramework.createKdf('PBKDF2|SHA256');
```

## Kdf<sup>11+</sup>

Defines the key derivation function class. Before using APIs of this class, you need to create an instance of this class by using **createKdf(algName: string): Kdf**.

### Attributes

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Kdf

The supported system capability is SystemCapability.Security.CryptoFramework in API version 11 and SystemCapability.Security.CryptoFramework.Kdf since API version 12.

| Name   | Type  | Readable| Writable| Description                        |
| ------- | ------ | ---- | ---- | ---------------------------- |
| algName | string | Yes  | No  | Algorithm of the key derivation function.|

### generateSecret

generateSecret(params: KdfSpec, callback: AsyncCallback\<DataBlob>): void

Generates a key based on the specified key derivation parameters. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Kdf

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 9 to 11 and SystemCapability.Security.CryptoFramework.Kdf since API version 12.

**Parameters**

| Name  | Type                    | Mandatory| Description                  |
| -------- | ------------------------ | ---- | ---------------------- |
| params   | [KdfSpec](#kdfspec11)        | Yes  | Parameters of the key derivation function.|
| callback | AsyncCallback\<[DataBlob](#datablob)> | Yes  | Callback invoked to return the derived key generated.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | memory error.          |
| 17630001 | crypto operation error. |

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
      console.error("key derivation error.");
      return;
    }
    console.info('key derivation output is ' + secret.data);
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
      console.error("key derivation error.");
      return;
    }
    console.info('key derivation output is ' + secret.data);
  });
  ```

### generateSecret

generateSecret(params: KdfSpec): Promise\<DataBlob>

Generates a key based on the specified key derivation parameters. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.CryptoFramework.Kdf

The supported system capability is SystemCapability.Security.CryptoFramework in API versions 9 to 11 and SystemCapability.Security.CryptoFramework.Kdf since API version 12.

**Parameters**

| Name| Type  | Mandatory| Description                  |
| ------ | ------ | ---- | ---------------------- |
| params   | [KdfSpec](#kdfspec11)        | Yes  | Parameters of the key derivation function.|

**Return value**

| Type              | Description    |
| ------------------ | -------- |
| Promise\<[DataBlob](#datablob)> | Promise used to return the derived key generated.|

**Error codes**
For details about the error codes, see [Crypto Framework Error Codes](errorcode-crypto-framework.md).

| ID| Error Message              |
| -------- | ---------------------- |
| 401 | invalid parameters. Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.|
| 17620001 | memory error.          |
| 17630001 | crypto operation error. |

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
    console.info('key derivation output is ' + secret.data);
  }).catch((error: BusinessError) => {
    console.error("key derivation error, " + error.message);
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
    console.info('key derivation output is ' + secret.data);
  }).catch((error: BusinessError) => {
    console.error("key derivation error, " + error.message);
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
| 401 | invalid parameters.  Possible causes: <br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.  |
| 17620001 | memory error.          |
| 17620002 | runtime error. |
| 17630001 | crypto operation error. |

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
  console.info("[Sync]key derivation output is " + secret.data);
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
  console.info("[Sync]key derivation output is " + secret.data);
  ```
