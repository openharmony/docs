# native_huks_type.h

<!--Kit: Universal Keystore Kit-->
<!--Subsystem: Security-->
<!--Owner: @wutiantian-gitee-->
<!--Designer: @HighLowWorld-->
<!--Tester: @wxy1234564846-->
<!--Adviser: @zengyawen-->

## Overview

Defines the enums, structs, and macros used in the HUKS functions.

**File to include**: <huks/native_huks_type.h>

**Library**: libhuks_ndk.z.so

**System capability**: SystemCapability.Security.Huks.Core

The preceding system capability is available since API version 20. From API versions 9 to 19, the system capability is **SystemCapability.Security.Huks**.

**Since**: 9

**Related module:** [HuksTypeApi](capi-hukstypeapi.md)

## Summary

### Structs

| Name| Description|
| -- | -- |
| [OH_Huks_Result](capi-hukstypeapi-oh-huks-result.md) | Defines the struct of the returned data, including a status code and related description.|
| [OH_Huks_Blob](capi-hukstypeapi-oh-huks-blob.md) | Defines the struct of a binary large object (BLOB).|
| [OH_Huks_Param](capi-hukstypeapi-oh-huks-param.md) | Defines the struct of the parameters in a parameter set.|
| [OH_Huks_ParamSet](capi-hukstypeapi-oh-huks-paramset.md) | Defines the struct of a parameter set.|
| [OH_Huks_CertChain](capi-hukstypeapi-oh-huks-certchain.md) | Defines the struct of a certificate chain.|
| [OH_Huks_KeyInfo](capi-hukstypeapi-oh-huks-keyinfo.md) | Defines the struct of key information.|
| [OH_Huks_PubKeyInfo](capi-hukstypeapi-oh-huks-pubkeyinfo.md) | Defines the struct of the public key information.|
| [OH_Huks_KeyMaterialRsa](capi-hukstypeapi-oh-huks-keymaterialrsa.md) | Defines the struct of a Rivest-Shamir-Adleman (RSA) key.|
| [OH_Huks_KeyMaterialEcc](capi-hukstypeapi-oh-huks-keymaterialecc.md) | Defines the struct of an Elliptic Curve Cryptography (ECC) key.|
| [OH_Huks_KeyMaterialDsa](capi-hukstypeapi-oh-huks-keymaterialdsa.md) | Defines the struct of a DSA key.|
| [OH_Huks_KeyMaterialDh](capi-hukstypeapi-oh-huks-keymaterialdh.md) | Defines the struct of a Diffie-Hellman (DH) key.|
| [OH_Huks_KeyMaterial25519](capi-hukstypeapi-oh-huks-keymaterial25519.md) | Defines the struct of a 25519 key.|
| [OH_Huks_KeyAliasSet](capi-hukstypeapi-oh-huks-keyaliasset.md) | Defines the struct of a key alias set.|

### Enums

| Name| Description|
| -- | -- |
| [OH_Huks_KeyPurpose](#oh_huks_keypurpose) | Enumerates the key purposes.|
| [OH_Huks_KeyDigest](#oh_huks_keydigest) | Enumerates the digest algorithms.|
| [OH_Huks_KeyPadding](#oh_huks_keypadding) | Enumerates the padding algorithms.|
| [OH_Huks_CipherMode](#oh_huks_ciphermode) | Cipher mode.|
| [OH_Huks_KeySize](#oh_huks_keysize) | Enumerates the key sizes of different algorithms.|
| [OH_Huks_KeyAlg](#oh_huks_keyalg) | Enumerates the algorithms for keys.|
| [OH_Huks_AlgSuite](#oh_huks_algsuite) | Enumerates the algorithm suites that can be used for importing of a key in cipher text.|
| [OH_Huks_KeyGenerateType](#oh_huks_keygeneratetype) | Enumerates the types of the key generated.|
| [OH_Huks_KeyFlag](#oh_huks_keyflag) | Enumerates the key generation types.|
| [OH_Huks_KeyStorageType](#oh_huks_keystoragetype) | Enumerates the key storage types.|
| [OH_Huks_ImportKeyType](#oh_huks_importkeytype) | Enumerates the types of the key to import. By default, a public key is imported. This field is not required when a symmetric key is imported.|
| [OH_Huks_RsaPssSaltLenType](#oh_huks_rsapsssaltlentype) | Enumerates the formats in which a key is stored.|
| [OH_Huks_ErrCode](#oh_huks_errcode) | Enumerates error codes.|
| [OH_Huks_TagType](#oh_huks_tagtype) | Enumerates the mask values of the parameter type in a parameter set.|
| [OH_Huks_UserAuthType](#oh_huks_userauthtype) | Enumerates the user authentication types in key access control.|
| [OH_Huks_AuthAccessType](#oh_huks_authaccesstype) | Enumerates the rules for invalidating a key.|
| [OH_Huks_AuthStorageLevel](#oh_huks_authstoragelevel) | Enumerates the security levels for storing the key generated or imported.|
| [OH_Huks_ChallengeType](#oh_huks_challengetype) | Enumerates the types of the challenge generated when a key is used.|
| [OH_Huks_UserAuthMode](#oh_huks_userauthmode) | Enumerates the user authentication modes in key access control.|
| [OH_Huks_ChallengePosition](#oh_huks_challengeposition) | Enumerates the positions of the 8-byte valid value in a custom challenge generated.|
| [OH_Huks_SecureSignType](#oh_huks_securesigntype) | Enumerates the signature types of the key generated or imported.|
| [OH_Huks_KeyWrapType](#oh_huks_keywraptype) | Enumerates the wrap type of the key generated or imported.|
| [OH_Huks_Tag](#oh_huks_tag) | Enumerates the tags contained in a parameter set.|

## Enum Description

### OH_Huks_KeyPurpose

```
enum OH_Huks_KeyPurpose
```

**Description**

Enumerates the key purposes.

**Since**: 9

| Enum| Description|
| -- | -- |
| OH_HUKS_KEY_PURPOSE_ENCRYPT = 1 | Used to encrypt the plaintext.|
| OH_HUKS_KEY_PURPOSE_DECRYPT = 2 | Used to decrypt the cipher text.|
| OH_HUKS_KEY_PURPOSE_SIGN = 4 | Used for signing.|
| OH_HUKS_KEY_PURPOSE_VERIFY = 8 | Used to verify the signature.|
| OH_HUKS_KEY_PURPOSE_DERIVE = 16 | Used to derive a key.|
| OH_HUKS_KEY_PURPOSE_WRAP = 32 | Used for exporting a key in ciphertext.|
| OH_HUKS_KEY_PURPOSE_UNWRAP = 64 | Used for importing a key in ciphertext.|
| OH_HUKS_KEY_PURPOSE_MAC = 128 | Used to generate a message authentication code (MAC).|
| OH_HUKS_KEY_PURPOSE_AGREE = 256 | Used for key agreement.|

### OH_Huks_KeyDigest

```
enum OH_Huks_KeyDigest
```

**Description**

Enumerates the digest algorithms.

**Since**: 9

| Enum| Description|
| -- | -- |
| OH_HUKS_DIGEST_NONE = 0 | No digest algorithm.|
| OH_HUKS_DIGEST_MD5 = 1 | MD5.|
| OH_HUKS_DIGEST_SM3 = 2 | SM3.|
| OH_HUKS_DIGEST_SHA1 = 10 | SHA-1.|
| OH_HUKS_DIGEST_SHA224 = 11 | SHA-224.|
| OH_HUKS_DIGEST_SHA256 = 12 | SHA-256.|
| OH_HUKS_DIGEST_SHA384 = 13 | SHA-384.|
| OH_HUKS_DIGEST_SHA512 = 14 | SHA-512.|

### OH_Huks_KeyPadding

```
enum OH_Huks_KeyPadding
```

**Description**

Enumerates the padding algorithms.

**Since**: 9

| Enum| Description|
| -- | -- |
| OH_HUKS_PADDING_NONE = 0 | No padding algorithm.|
| OH_HUKS_PADDING_OAEP = 1 | Optimal Asymmetric Encryption Padding (OAEP).|
| OH_HUKS_PADDING_PSS = 2 | Probabilistic Signature Scheme (PSS).|
| OH_HUKS_PADDING_PKCS1_V1_5 = 3 | Public Key Cryptography Standards (PKCS) #1 v1.5.|
| OH_HUKS_PADDING_PKCS5 = 4 | PKCS #5.|
| OH_HUKS_PADDING_PKCS7 = 5 | PKCS #7.|
| OH_HUKS_PADDING_ISO_IEC_9796_2 = 6 | ISO IEC 9796-2.<br>**Since**: 18|
| OH_HUKS_PADDING_ISO_IEC_9797_1 = 7 | ISO IEC 9797-1.<br>**Since**: 18|

### OH_Huks_CipherMode

```
enum OH_Huks_CipherMode
```

**Description**

Cipher mode.

**Since**: 9

| Enum| Description|
| -- | -- |
| OH_HUKS_MODE_ECB = 1 | Electronic Code Block (ECB) mode.|
| OH_HUKS_MODE_CBC = 2 | Cipher Block Chaining (CBC) mode.|
| OH_HUKS_MODE_CTR = 3 | Counter (CTR) mode.|
| OH_HUKS_MODE_OFB = 4 | Output Feedback (OFB) mode.|
| OH_HUKS_MODE_CFB = 5 | Cipher Feedback (CFB) mode.<br>**Since**: 12|
| OH_HUKS_MODE_CCM = 31 | Counter with CBC-MAC (CCM) mode.|
| OH_HUKS_MODE_GCM = 32 | Galois/Counter (GCM) mode.|

### OH_Huks_KeySize

```
enum OH_Huks_KeySize
```

**Description**

Enumerates the key sizes of different algorithms.

**Since**: 9

| Enum| Description|
| -- | -- |
| OH_HUKS_RSA_KEY_SIZE_512 = 512 | RSA key of 512 bits.|
| OH_HUKS_RSA_KEY_SIZE_768 = 768 | RSA key of 768 bits.|
| OH_HUKS_RSA_KEY_SIZE_1024 = 1024 | RSA key of 1024 bits.|
| OH_HUKS_RSA_KEY_SIZE_2048 = 2048 | RSA key of 2048 bits.|
| OH_HUKS_RSA_KEY_SIZE_3072 = 3072 | RSA key of 3072 bits.|
| OH_HUKS_RSA_KEY_SIZE_4096 = 4096 | RSA key of 4096 bits.|
| OH_HUKS_ECC_KEY_SIZE_224 = 224 | ECC key of 224 bits.|
| OH_HUKS_ECC_KEY_SIZE_256 = 256 | ECC key of 256 bits.|
| OH_HUKS_ECC_KEY_SIZE_384 = 384 | ECC key of 384 bits.|
| OH_HUKS_ECC_KEY_SIZE_521 = 521 | ECC key of 521 bits.|
| OH_HUKS_AES_KEY_SIZE_128 = 128 | AES key of 128 bits.|
| OH_HUKS_AES_KEY_SIZE_192 = 192 | AES key of 192 bits.|
| OH_HUKS_AES_KEY_SIZE_256 = 256 | AES key of 256 bits.|
| OH_HUKS_AES_KEY_SIZE_512 = 512 | AES key of 512 bits.|
| OH_HUKS_CURVE25519_KEY_SIZE_256 = 256 | Curve25519 key of 256 bits.|
| OH_HUKS_DH_KEY_SIZE_2048 = 2048 | DH key of 2048 bits.|
| OH_HUKS_DH_KEY_SIZE_3072 = 3072 | DH key of 3072 bits.|
| OH_HUKS_DH_KEY_SIZE_4096 = 4096 | DH key of 4096 bits.|
| OH_HUKS_SM2_KEY_SIZE_256 = 256 | SM2 key of 256 bits.|
| OH_HUKS_SM4_KEY_SIZE_128 = 128 | SM4 key of 128 bits.|
| OH_HUKS_DES_KEY_SIZE_64 = 64 | DES key of 64 bits.<br>**Since**: 18|
| OH_HUKS_3DES_KEY_SIZE_128 = 128 | 3DES key of 128 bits.<br>**Since**: 18|
| OH_HUKS_3DES_KEY_SIZE_192 = 192 | 3DES key of 192 bits.<br>**Since**: 18|

### OH_Huks_KeyAlg

```
enum OH_Huks_KeyAlg
```

**Description**

Enumerates the algorithms for keys.

**Since**: 9

| Enum| Description|
| -- | -- |
| OH_HUKS_ALG_RSA = 1 | RSA.|
| OH_HUKS_ALG_ECC = 2 | ECC.|
| OH_HUKS_ALG_DSA = 3 | DSA.|
| OH_HUKS_ALG_AES = 20 | Advanced Encryption Standard (AES).|
| OH_HUKS_ALG_HMAC = 50 | HMAC algorithm.|
| OH_HUKS_ALG_HKDF = 51 | HKDF.|
| OH_HUKS_ALG_PBKDF2 = 52 | PBKDF2.|
| OH_HUKS_ALG_ECDH = 100 | ECDH.|
| OH_HUKS_ALG_X25519 = 101 | X25519.|
| OH_HUKS_ALG_ED25519 = 102 | Ed25519.|
| OH_HUKS_ALG_DH = 103 | DH.|
| OH_HUKS_ALG_SM2 = 150 | ShangMi2 (SM2).|
| OH_HUKS_ALG_SM3 = 151 | SM3.|
| OH_HUKS_ALG_SM4 = 152 | SM4.|
| OH_HUKS_ALG_DES = 160 | DES.<br>**Since**: 18|
| OH_HUKS_ALG_3DES = 161 | 3DES.<br>**Since**: 18|
| OH_HUKS_ALG_CMAC = 162 | CMAC.<br>**Since**: 18|

### OH_Huks_AlgSuite

```
enum OH_Huks_AlgSuite
```

**Description**

Enumerates the algorithm suites that can be used for importing of a key in ciphertext.

Key material format for **OH_HUKS_UNWRAP_SUITE_X25519_AES_256_GCM_NOPADDING**:

```
| x25519_plain_pubkey_length  (4 Byte) | x25519_plain_pubkey |  agreekey_aad_length (4 Byte) | agreekey_aad
|   agreekey_nonce_length     (4 Byte) |   agreekey_nonce    | agreekey_aead_tag_len(4 Byte) | agreekey_aead_tag 
|    kek_enc_data_length      (4 Byte) |    kek_enc_data     |    kek_aad_length    (4 Byte) | kek_aad     
|      kek_nonce_length       (4 Byte) |      kek_nonce      |   kek_aead_tag_len   (4 Byte) | kek_aead_tag
|   key_material_size_len     (4 Byte) |  key_material_size  |   key_mat_enc_length (4 Byte) | key_mat_enc_data
```

Key material format for **OH_HUKS_UNWRAP_SUITE_ECDH_AES_256_GCM_NOPADDING**:
```
|  ECC_plain_pubkey_length    (4 Byte) |  ECC_plain_pubkey   |  agreekey_aad_length (4 Byte) | agreekey_aad
|   agreekey_nonce_length     (4 Byte) |   agreekey_nonce    | agreekey_aead_tag_len(4 Byte) | agreekey_aead_tag
|    kek_enc_data_length      (4 Byte) |    kek_enc_data     |    kek_aad_length    (4 Byte) | kek_aad 
|      kek_nonce_length       (4 Byte) |      kek_nonce      |   kek_aead_tag_len   (4 Byte) | kek_aead_tag 
|   key_material_size_len     (4 Byte) |  key_material_size  |   key_mat_enc_length (4 Byte) | key_mat_enc_data
```

**Since**: 9

| Enum| Description|
| -- | -- |
| OH_HUKS_UNWRAP_SUITE_X25519_AES_256_GCM_NOPADDING = 1 | Key material in Length-Value format, using X25519 for key agreement and AES-256-GCM for encryption and decryption: For details about the material format, see the preceding description.|
| OH_HUKS_UNWRAP_SUITE_ECDH_AES_256_GCM_NOPADDING = 2 | Key material in Length-Value format, using ECDH-p256 for key agreement and AES-256-GCM for encryption and decryption: For details about the material format, see the preceding description.|

### OH_Huks_KeyGenerateType

```
enum OH_Huks_KeyGenerateType
```

**Description**

Enumerates the types of the key generated.

**Since**: 9

| Enum| Description|
| -- | -- |
| OH_HUKS_KEY_GENERATE_TYPE_DEFAULT = 0 | Key generated by default.|
| OH_HUKS_KEY_GENERATE_TYPE_DERIVE = 1 | Derived key.|
| OH_HUKS_KEY_GENERATE_TYPE_AGREE = 2 | Key generated by key agreement.|

### OH_Huks_KeyFlag

```
enum OH_Huks_KeyFlag
```

**Description**

Enumerates the key generation types.

**Since**: 9

| Enum| Description|
| -- | -- |
| OH_HUKS_KEY_FLAG_IMPORT_KEY = 1 | Import a public key using a function.|
| OH_HUKS_KEY_FLAG_GENERATE_KEY = 2 | Generate a key by using a function.|
| OH_HUKS_KEY_FLAG_AGREE_KEY = 3 | Generate a key by using a key agreement function.|
| OH_HUKS_KEY_FLAG_DERIVE_KEY = 4 | Derive a key by using a function.|

### OH_Huks_KeyStorageType

```
enum OH_Huks_KeyStorageType
```

**Description**

Enumerates the key storage types.

**Since**: 9

| Enum| Description|
| -- | -- |
| OH_HUKS_STORAGE_TEMP = 0 | Return the key to the service via the API.|
| OH_HUKS_STORAGE_PERSISTENT = 1 | Store the key in HUKS.|
| OH_HUKS_STORAGE_ONLY_USED_IN_HUKS = 2 | Store the key generated from key derivation or key agreement in HUKS.|
| OH_HUKS_STORAGE_KEY_EXPORT_ALLOWED = 3 | Return the key generated from key derivation or key agreement to the service.|

### OH_Huks_ImportKeyType

```
enum OH_Huks_ImportKeyType
```

**Description**

Enumerates the types of the key to import. By default, a public key is imported. This field is not required when a symmetric key is imported.

**Since**: 9

| Enum| Description|
| -- | -- |
| OH_HUKS_KEY_TYPE_PUBLIC_KEY = 0 | Public key.|
| OH_HUKS_KEY_TYPE_PRIVATE_KEY = 1 | Private key.|
| OH_HUKS_KEY_TYPE_KEY_PAIR = 2 | Public and private key pair.|

### OH_Huks_RsaPssSaltLenType

```
enum OH_Huks_RsaPssSaltLenType
```

**Description**

Enumerates the formats in which a key is stored.

**Since**: 10

| Enum| Description|
| -- | -- |
| OH_HUKS_RSA_PSS_SALT_LEN_DIGEST = 0 | The salt length is set to the digest length.|
| OH_HUKS_RSA_PSS_SALT_LEN_MAX = 1 | The salt length is set to the maximum length.|

### OH_Huks_ErrCode

```
enum OH_Huks_ErrCode
```

**Description**

Enumerates error codes.

**Since**: 9

| Enum| Description|
| -- | -- |
| OH_HUKS_SUCCESS = 0 | Success.|
| OH_HUKS_ERR_CODE_PERMISSION_FAIL = 201 | Permission verification failed.|
| OH_HUKS_ERR_CODE_ILLEGAL_ARGUMENT = 401 | Invalid parameter (universal).|
| OH_HUKS_ERR_CODE_NOT_SUPPORTED_API = 801 | The API is not supported.|
| OH_HUKS_ERR_CODE_FEATURE_NOT_SUPPORTED = 12000001 | The feature is not supported.|
| OH_HUKS_ERR_CODE_MISSING_CRYPTO_ALG_ARGUMENT = 12000002 | Key algorithm parameters are missing.|
| OH_HUKS_ERR_CODE_INVALID_CRYPTO_ALG_ARGUMENT = 12000003 | Invalid key algorithm parameter.|
| OH_HUKS_ERR_CODE_FILE_OPERATION_FAIL = 12000004 | File operation failed.|
| OH_HUKS_ERR_CODE_COMMUNICATION_FAIL = 12000005 | The process communication failed.|
| OH_HUKS_ERR_CODE_CRYPTO_FAIL = 12000006 | Crypto operation failed.|
| OH_HUKS_ERR_CODE_KEY_AUTH_PERMANENTLY_INVALIDATED = 12000007 | Failed to access the key because the key has expired.|
| OH_HUKS_ERR_CODE_KEY_AUTH_VERIFY_FAILED = 12000008 | Failed to access the key because the authentication has failed.|
| OH_HUKS_ERR_CODE_KEY_AUTH_TIME_OUT = 12000009 | Key access timed out.|
| OH_HUKS_ERR_CODE_SESSION_LIMIT = 12000010 | The number of key operation sessions has reached the limit.|
| OH_HUKS_ERR_CODE_ITEM_NOT_EXIST = 12000011 | The entity does not exist.|
| OH_HUKS_ERR_CODE_INTERNAL_ERROR = 12000012 | Internal error.|
| OH_HUKS_ERR_CODE_CREDENTIAL_NOT_EXIST = 12000013 | The authentication credential does not exist.|
| OH_HUKS_ERR_CODE_INSUFFICIENT_MEMORY = 12000014 | Insufficient memory.|
| OH_HUKS_ERR_CODE_CALL_SERVICE_FAILED = 12000015 | Failed to invoke the service.|
| OH_HUKS_ERR_CODE_DEVICE_PASSWORD_UNSET = 12000016 | The lock screen password required is not set.<br>**Since**: 11|
| OH_HUKS_ERR_CODE_KEY_ALREADY_EXIST = 12000017 | A key with the same name already exists.<br>**Since**: 20|
| OH_HUKS_ERR_CODE_INVALID_ARGUMENT = 12000018 | An input parameter is invalid.<br>**Since**: 20|

### OH_Huks_TagType

```
enum OH_Huks_TagType
```

**Description**

Enumerates the mask values of the parameter type in a parameter set.

**Since**: 9

| Enum| Description|
| -- | -- |
| OH_HUKS_TAG_TYPE_INVALID = 0 << 28 | Invalid tag type.|
| OH_HUKS_TAG_TYPE_INT = 1 << 28 | int32_t.|
| OH_HUKS_TAG_TYPE_UINT = 2 << 28 | uin32_t.|
| OH_HUKS_TAG_TYPE_ULONG = 3 << 28 | uin64_t.|
| OH_HUKS_TAG_TYPE_BOOL = 4 << 28 | Boolean.|
| OH_HUKS_TAG_TYPE_BYTES = 5 << 28 | [OH_Huks_Blob](capi-hukstypeapi-oh-huks-blob.md).|

### OH_Huks_UserAuthType

```
enum OH_Huks_UserAuthType
```

**Description**

Enumerates the user authentication types in key access control.

**Since**: 9

| Enum| Description|
| -- | -- |
| OH_HUKS_USER_AUTH_TYPE_FINGERPRINT = 1 << 0 | Fingerprint authentication.|
| OH_HUKS_USER_AUTH_TYPE_FACE = 1 << 1 | Facial authentication.|
| OH_HUKS_USER_AUTH_TYPE_PIN = 1 << 2 | PIN authentication.|
| OH_HUKS_USER_AUTH_TYPE_TUI_PIN = 1 << 5 | TUI PIN authentication.<br>**Since**: 20|

### OH_Huks_AuthAccessType

```
enum OH_Huks_AuthAccessType
```

**Description**

Enumerates the rules for invalidating a key.

**Since**: 9

| Enum| Description|
| -- | -- |
| OH_HUKS_AUTH_ACCESS_INVALID_CLEAR_PASSWORD = 1 << 0 | The key becomes invalid after the password is cleared.|
| OH_HUKS_AUTH_ACCESS_INVALID_NEW_BIO_ENROLL = 1 << 1 | The key becomes invalid after a new biometric feature is enrolled.|
| OH_HUKS_AUTH_ACCESS_ALWAYS_VALID = 1 << 2 | The key is always valid.<br>**Since**: 11|

### OH_Huks_AuthStorageLevel

```
enum OH_Huks_AuthStorageLevel
```

**Description**

Enumerates the security levels for storing the key generated or imported.

**Since**: 11

| Enum| Description|
| -- | -- |
| OH_HUKS_AUTH_STORAGE_LEVEL_DE = 0 | The key can be accessed only after the device is started.|
| OH_HUKS_AUTH_STORAGE_LEVEL_CE = 1 | The key can be accessed only after the first unlock of the device.|
| OH_HUKS_AUTH_STORAGE_LEVEL_ECE = 2 | The key can be accessed only when the device is unlocked.|

### OH_Huks_ChallengeType

```
enum OH_Huks_ChallengeType
```

**Description**

Enumerates the types of the challenge generated when a key is used.

**Since**: 9

| Enum| Description|
| -- | -- |
| OH_HUKS_CHALLENGE_TYPE_NORMAL = 0 | Normal challenge, which is of 32 bytes by default.|
| OH_HUKS_CHALLENGE_TYPE_CUSTOM = 1 | Custom challenge, which supports one-time authentication for multiple keys. The valid value of a custom challenge is of 8 bytes.|
| OH_HUKS_CHALLENGE_TYPE_NONE = 2 | Challenge is not required.|

### OH_Huks_UserAuthMode

```
enum OH_Huks_UserAuthMode
```

**Description**

Enumerates the user authentication modes in key access control.

**Since**: 12

| Enum| Description|
| -- | -- |
| OH_HUKS_USER_AUTH_MODE_LOCAL = 0 | Local authentication.|
| OH_HUKS_USER_AUTH_MODE_COAUTH = 1 | Cross-device collaborative authentication.|

### OH_Huks_ChallengePosition

```
enum OH_Huks_ChallengePosition
```

**Description**

Enumerates the positions of the 8-byte valid value in a custom challenge generated.

**Since**: 9

| Enum| Description|
| -- | -- |
| OH_HUKS_CHALLENGE_POS_0 = 0 | Bytes 0 to 7.|
| OH_HUKS_CHALLENGE_POS_1 | Bytes 8 to 15.|
| OH_HUKS_CHALLENGE_POS_2 | Bytes 16 to 23.|
| OH_HUKS_CHALLENGE_POS_3 | Bytes 24 to 31.|

### OH_Huks_SecureSignType

```
enum OH_Huks_SecureSignType
```

**Description**

Enumerates the signature types of the key generated or imported.

**Since**: 9

| Enum| Description|
| -- | -- |
| OH_HUKS_SECURE_SIGN_WITH_AUTHINFO = 1 | The signature carries authentication information. This field is specified when a key is generated or imported. When the key is used for signing, the data will be added with the authentication information and then be signed.<br>Note: The carried authentication information includes identity information. You need to describe the purpose, retention policy, and destruction method of the identity information in the privacy statement.|

### OH_Huks_KeyWrapType

```
enum OH_Huks_KeyWrapType
```

**Description**

Enumerates the wrap type of the key generated or imported.

**Since**: 20

| Enum| Description|
| -- | -- |
| OH_HUKS_KEY_WRAP_TYPE_HUK_BASED = 2 | Wrap type of the unique hardware key.|

### OH_Huks_Tag

```
enum OH_Huks_Tag
```

**Description**

Enumerates the tags contained in a parameter set.<br> 1 to 200: key parameter tag values.<br> 301 to 500: tag values related to access control and authentication of key usage.<br> 501 to 600: tag values related to key authentication.<br> 601 to 1000: reserved values for other types of tag values.<br> 1001 to 9999: extended tag values.<br> 11000 to 12000: reserved values.<br> 20001 to N: reserved tag values.

**Since**: 9

| Enum| Description|
| -- | -- |
| OH_HUKS_TAG_ALGORITHM = OH_HUKS_TAG_TYPE_UINT \| 1 | Algorithm type.|
| OH_HUKS_TAG_PURPOSE = OH_HUKS_TAG_TYPE_UINT \| 2 | Key purpose.|
| OH_HUKS_TAG_KEY_SIZE = OH_HUKS_TAG_TYPE_UINT \| 3 | Key length.|
| OH_HUKS_TAG_DIGEST = OH_HUKS_TAG_TYPE_UINT \| 4 | Digest algorithm.|
| OH_HUKS_TAG_PADDING = OH_HUKS_TAG_TYPE_UINT \| 5 | Padding algorithm.|
| OH_HUKS_TAG_BLOCK_MODE = OH_HUKS_TAG_TYPE_UINT \| 6 | Cipher mode.|
| OH_HUKS_TAG_KEY_TYPE = OH_HUKS_TAG_TYPE_UINT \| 7 | Key type.|
| OH_HUKS_TAG_ASSOCIATED_DATA = OH_HUKS_TAG_TYPE_BYTES \| 8 | Associated authentication data.|
| OH_HUKS_TAG_NONCE = OH_HUKS_TAG_TYPE_BYTES \| 9 | Field for key encryption and decryption.|
| OH_HUKS_TAG_IV = OH_HUKS_TAG_TYPE_BYTES \| 10 | Initialized vector (IV).|
| OH_HUKS_TAG_INFO = OH_HUKS_TAG_TYPE_BYTES \| 11 | Information generated during key derivation.|
| OH_HUKS_TAG_SALT = OH_HUKS_TAG_TYPE_BYTES \| 12 | Salt value used for key derivation.|
| OH_HUKS_TAG_ITERATION = OH_HUKS_TAG_TYPE_UINT \| 14 | Number of iterations for key derivation.|
| OH_HUKS_TAG_KEY_GENERATE_TYPE = OH_HUKS_TAG_TYPE_UINT \| 15 | Type of the generated key. For details, see [OH_Huks_KeyGenerateType](#oh_huks_keygeneratetype).|
| OH_HUKS_TAG_AGREE_ALG = OH_HUKS_TAG_TYPE_UINT \| 19 | Algorithm used in key agreement.|
| OH_HUKS_TAG_AGREE_PUBLIC_KEY_IS_KEY_ALIAS = OH_HUKS_TAG_TYPE_BOOL \| 20 | Alias of the public key used for key agreement.|
| OH_HUKS_TAG_AGREE_PRIVATE_KEY_ALIAS = OH_HUKS_TAG_TYPE_BYTES \| 21 | Alias of the private key used for key agreement.|
| OH_HUKS_TAG_AGREE_PUBLIC_KEY = OH_HUKS_TAG_TYPE_BYTES \| 22 | Public key used for key agreement.|
| OH_HUKS_TAG_KEY_ALIAS = OH_HUKS_TAG_TYPE_BYTES \| 23 | Key alias.|
| OH_HUKS_TAG_DERIVE_KEY_SIZE = OH_HUKS_TAG_TYPE_UINT \| 24 | Size of the derived key.|
| OH_HUKS_TAG_IMPORT_KEY_TYPE = OH_HUKS_TAG_TYPE_UINT \| 25 | Type of the key to import. For details, see [OH_Huks_ImportKeyType](#oh_huks_importkeytype).|
| OH_HUKS_TAG_UNWRAP_ALGORITHM_SUITE = OH_HUKS_TAG_TYPE_UINT \| 26 | Algorithm suite used for importing a key in ciphertext.|
| OH_HUKS_TAG_DERIVED_AGREED_KEY_STORAGE_FLAG = OH_HUKS_TAG_TYPE_UINT \| 29 | Storage type of the derived key or key produced after key agreement. It is a value of [OH_Huks_KeyStorageType](#oh_huks_keystoragetype).|
| OH_HUKS_TAG_RSA_PSS_SALT_LEN_TYPE = OH_HUKS_TAG_TYPE_UINT \| 30 | Salt length type when the PSS padding mode is used with the RSA algorithm.|
| OH_HUKS_TAG_ALL_USERS = OH_HUKS_TAG_TYPE_BOOL \| 301 | All users in the multi-user scenario.|
| OH_HUKS_TAG_USER_ID = OH_HUKS_TAG_TYPE_UINT \| 302 | Multi-user ID.|
| OH_HUKS_TAG_NO_AUTH_REQUIRED = OH_HUKS_TAG_TYPE_BOOL \| 303 | Whether key access control is required.|
| OH_HUKS_TAG_USER_AUTH_TYPE = OH_HUKS_TAG_TYPE_UINT \| 304 | User authentication type in key access control.|
| OH_HUKS_TAG_AUTH_TIMEOUT = OH_HUKS_TAG_TYPE_UINT \| 305 | Timeout duration for key access.|
| OH_HUKS_TAG_AUTH_TOKEN = OH_HUKS_TAG_TYPE_BYTES \| 306 | Authentication token for the key.|
| OH_HUKS_TAG_KEY_AUTH_ACCESS_TYPE = OH_HUKS_TAG_TYPE_UINT \| 307 | Key access control type, which must be set together with the user authentication type. It is a value of [OH_Huks_AuthAccessType](#oh_huks_authaccesstype).|
| OH_HUKS_TAG_KEY_SECURE_SIGN_TYPE = OH_HUKS_TAG_TYPE_UINT \| 308 | Signature type of the key generated or imported.|
| OH_HUKS_TAG_CHALLENGE_TYPE = OH_HUKS_TAG_TYPE_UINT \| 309 | Challenge type, which is a value of [OH_Huks_ChallengeType](#oh_huks_challengetype).|
| OH_HUKS_TAG_CHALLENGE_POS = OH_HUKS_TAG_TYPE_UINT \| 310 | Position of the 8-byte valid value in a custom challenge. For details, see [OH_Huks_ChallengePosition](#oh_huks_challengeposition).|
| OH_HUKS_TAG_KEY_AUTH_PURPOSE = OH_HUKS_TAG_TYPE_UINT \| 311 | Type of the key authentication purpose.|
| OH_HUKS_TAG_AUTH_STORAGE_LEVEL = OH_HUKS_TAG_TYPE_UINT \| 316 | Security levels for storing the key. For details, see [OH_Huks_AuthStorageLevel](#oh_huks_authstoragelevel).<br>**Since**: 11|
| OH_HUKS_TAG_USER_AUTH_MODE = OH_HUKS_TAG_TYPE_UINT \| 319 | User authentication mode in key access control. For details, see [OH_Huks_UserAuthMode](#oh_huks_userauthmode).<br>**Since**: 12|
| OH_HUKS_TAG_ATTESTATION_CHALLENGE = OH_HUKS_TAG_TYPE_BYTES \| 501 | Challenge value used in the attestation.|
| OH_HUKS_TAG_ATTESTATION_APPLICATION_ID = OH_HUKS_TAG_TYPE_BYTES \| 502 | ID of the application, to which the key belongs, in key attestation.|
| OH_HUKS_TAG_ATTESTATION_ID_ALIAS = OH_HUKS_TAG_TYPE_BYTES \| 511 | Key alias.|
| OH_HUKS_TAG_ATTESTATION_ID_SEC_LEVEL_INFO = OH_HUKS_TAG_TYPE_BYTES \| 514 | Security level used in key attestation.|
| OH_HUKS_TAG_ATTESTATION_ID_VERSION_INFO = OH_HUKS_TAG_TYPE_BYTES \| 515 | Version information used in key attestation.|
| OH_HUKS_TAG_KEY_OVERRIDE = OH_HUKS_TAG_TYPE_BOOL \| 520 | Whether to overwrite the key with the same name.<br>**Since**: 20|
| OH_HUKS_TAG_IS_KEY_ALIAS = OH_HUKS_TAG_TYPE_BOOL \| 1001 | Whether it is a key alias.|
| OH_HUKS_TAG_KEY_STORAGE_FLAG = OH_HUKS_TAG_TYPE_UINT \| 1002 | Key storage mode. For details, see [OH_Huks_KeyStorageType](#oh_huks_keystoragetype).|
| OH_HUKS_TAG_IS_ALLOWED_WRAP = OH_HUKS_TAG_TYPE_BOOL \| 1003 | Whether to allow the key to be wrapped.|
| OH_HUKS_TAG_KEY_WRAP_TYPE = OH_HUKS_TAG_TYPE_UINT \| 1004 | Key wrap type.|
| OH_HUKS_TAG_KEY_AUTH_ID = OH_HUKS_TAG_TYPE_BYTES \| 1005 | Authentication ID.|
| OH_HUKS_TAG_KEY_ROLE = OH_HUKS_TAG_TYPE_UINT \| 1006 | Role of the key.|
| OH_HUKS_TAG_KEY_FLAG = OH_HUKS_TAG_TYPE_UINT \| 1007 | Key flag. For details, see [OH_Huks_KeyFlag](#oh_huks_keyflag).|
| OH_HUKS_TAG_IS_ASYNCHRONIZED = OH_HUKS_TAG_TYPE_UINT \| 1008 | Whether the invocation is asynchronous.|
| OH_HUKS_TAG_KEY_DOMAIN = OH_HUKS_TAG_TYPE_UINT \| 1011 | Key domain.|
| OH_HUKS_TAG_IS_DEVICE_PASSWORD_SET = OH_HUKS_TAG_TYPE_BOOL \| 1012 | Whether the key is accessible only when the user sets a lock screen password.<br> **True** indicates that the key can be generated and used only when a password is set.<br>**Since**: 11|
| OH_HUKS_TAG_AE_TAG = OH_HUKS_TAG_TYPE_BYTES \| 10009 | AEAD in GCM mode.|
| OH_HUKS_TAG_SYMMETRIC_KEY_DATA = OH_HUKS_TAG_TYPE_BYTES \| 20001 | Symmetric key data.|
| OH_HUKS_TAG_ASYMMETRIC_PUBLIC_KEY_DATA = OH_HUKS_TAG_TYPE_BYTES \| 20002 | Public key data of the asymmetric key pair.|
| OH_HUKS_TAG_ASYMMETRIC_PRIVATE_KEY_DATA = OH_HUKS_TAG_TYPE_BYTES \| 20003 | Private key data of the asymmetric key pair.|
