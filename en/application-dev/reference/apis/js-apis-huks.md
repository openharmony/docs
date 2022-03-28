# HUKS

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**<br/>
>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

Openharmony Universal KeyStore (HUKS) provides KeyStore (KS) capabilities for applications, including key management and key cryptography operations.
HUKS also provides APIs for applications to import or generate keys.

## Modules to Import

```js
import huks from '@ohos.security.huks'
```
## HuksErrorCode

Enumerates error codes.

**System capability**: SystemCapability.Security.Huks

| Name                      | Value   | Description|
| -------------------------- | ----- | ---- |
| HUKS_SUCCESS | 0     |Success.|
| HUKS_FAILURE | -1    |Failure.|
| HUKS_ERROR_BAD_STATE | -2    |Incorrect state.|
| HUKS_ERROR_INVALID_ARGUMENT | -3    |Invalid argument.|
| HUKS_ERROR_NOT_SUPPORTED | -4    |Not supported.|
| HUKS_ERROR_NO_PERMISSION | -5    |No permission.|
| HUKS_ERROR_INSUFFICIENT_DATA | -6    |Insufficient data.|
| HUKS_ERROR_BUFFER_TOO_SMALL | -7    |Insufficient buffer.|
| HUKS_ERROR_INSUFFICIENT_MEMORY | -8    |Insufficient memory.|
| HUKS_ERROR_COMMUNICATION_FAILURE | -9    |Communication failed.|
| HUKS_ERROR_STORAGE_FAILURE | -10   |Storage failure.|
| HUKS_ERROR_HARDWARE_FAILURE | -11   |Hardware fault.|
| HUKS_ERROR_ALREADY_EXISTS | -12   |The object already exists.|
| HUKS_ERROR_NOT_EXIST | -13   |The object does not exist.|
| HUKS_ERROR_NULL_POINTER | -14   |Null pointer.|
| HUKS_ERROR_FILE_SIZE_FAIL | -15   |Incorrect file size.|
| HUKS_ERROR_READ_FILE_FAIL | -16   |Failed to read the file.|
| HUKS_ERROR_INVALID_PUBLIC_KEY | -17   |Invalid public key.|
| HUKS_ERROR_INVALID_PRIVATE_KEY | -18   |Invalid private key.|
| HUKS_ERROR_INVALID_KEY_INFO | -19   |Invalid key information.|
| HUKS_ERROR_HASH_NOT_EQUAL | -20   |The hash values are not equal.|
| HUKS_ERROR_MALLOC_FAIL | -21   |MALLOC failed.|
| HUKS_ERROR_WRITE_FILE_FAIL | -22   |Failed to write the file.|
| HUKS_ERROR_REMOVE_FILE_FAIL | -23   |Failed to delete the file.|
| HUKS_ERROR_OPEN_FILE_FAIL | -24   |Failed to open the file.|
| HUKS_ERROR_CLOSE_FILE_FAIL | -25   |Failed to close the file.|
| HUKS_ERROR_MAKE_DIR_FAIL | -26   |Failed to create the directory.|
| HUKS_ERROR_INVALID_KEY_FILE | -27   |Invalid key file.|
| HUKS_ERROR_IPC_MSG_FAIL | -28   |Incorrect IPC information.|
| HUKS_ERROR_REQUEST_OVERFLOWS | -29   |Request overflows.|
| HUKS_ERROR_PARAM_NOT_EXIST | -30   |The parameter does not exist.|
| HUKS_ERROR_CRYPTO_ENGINE_ERROR | -31   |CRYPTO ENGINE error.|
| HUKS_ERROR_COMMUNICATION_TIMEOUT | -32   |Communication timed out.|
| HUKS_ERROR_IPC_INIT_FAIL | -33   |IPC initialization failed.|
| HUKS_ERROR_IPC_DLOPEN_FAIL | -34   |IPC DLOPEN failed.|
| HUKS_ERROR_EFUSE_READ_FAIL | -35   |Failed to read eFUSE.|
| HUKS_ERROR_NEW_ROOT_KEY_MATERIAL_EXIST | -36   |New root key material exists.|
| HUKS_ERROR_UPDATE_ROOT_KEY_MATERIAL_FAIL | -37   |Failed to update the root key material.|
| HUKS_ERROR_VERIFICATION_FAILED | -38   |Failed to verify the certificate chain.|
| HUKS_ERROR_CHECK_GET_ALG_FAIL | -100  |Failed to check whether the ALG is obtained. |
| HUKS_ERROR_CHECK_GET_KEY_SIZE_FAIL | -101  |Failed to check whether the key size is obtained.|
| HUKS_ERROR_CHECK_GET_PADDING_FAIL | -102  |Failed to check whether padding is obtained.|
| HUKS_ERROR_CHECK_GET_PURPOSE_FAIL | -103  |Failed to check whether the purpose is obtained.|
| HUKS_ERROR_CHECK_GET_DIGEST_FAIL | -104  |Failed to check whether digest is obtained.|
| HUKS_ERROR_CHECK_GET_MODE_FAIL | -105  |Failed to check whether the mode is obtained.|
| HUKS_ERROR_CHECK_GET_NONCE_FAIL | -106  |Failed to check whether the nonce is obtained.|
| HUKS_ERROR_CHECK_GET_AAD_FAIL | -107  |Failed to check whether the AAD is obtained.|
| HUKS_ERROR_CHECK_GET_IV_FAIL | -108  |Failed to check whether the initialization vector (IV) is obtained.|
| HUKS_ERROR_CHECK_GET_AE_TAG_FAIL | -109  |Failed to check whether the AE flag is obtained.|
| HUKS_ERROR_CHECK_GET_SALT_FAIL | -110  |Failed to check whether the SALT is obtained.|
| HUKS_ERROR_CHECK_GET_ITERATION_FAIL | -111  |Failed to check whether the iteration is obtained.|
| HUKS_ERROR_INVALID_ALGORITHM | -112  |Invalid algorithm.|
| HUKS_ERROR_INVALID_KEY_SIZE | -113  |Invalid key size.|
| HUKS_ERROR_INVALID_PADDING | -114  |Invalid padding.|
| HUKS_ERROR_INVALID_PURPOSE | -115  |Invalid purpose.|
| HUKS_ERROR_INVALID_MODE | -116  |Invalid mode.|
| HUKS_ERROR_INVALID_DIGEST | -117  |Invalid digest.|
| HUKS_ERROR_INVALID_SIGNATURE_SIZE | -118  |Invalid signature size.|
| HUKS_ERROR_INVALID_IV | -119  |Invalid IV.|
| HUKS_ERROR_INVALID_AAD | -120  |Invalid AAD.|
| HUKS_ERROR_INVALID_NONCE | -121  |Invalid nonce.|
| HUKS_ERROR_INVALID_AE_TAG | -122  |Invalid AE tag.|
| HUKS_ERROR_INVALID_SALT | -123  |Invalid SALT.|
| HUKS_ERROR_INVALID_ITERATION | -124  |Invalid iteration.|
| HUKS_ERROR_INVALID_OPERATION | -125  |Invalid operation.|
| HUKS_ERROR_INTERNAL_ERROR | -999  |Internal error.|
| HUKS_ERROR_UNKNOWN_ERROR | -1000 |Unknown error.|


## HuksKeyPurpose

Represents the purpose (usage) of a key or key pair.

**System capability**: SystemCapability.Security.Huks

| Name                    | Value  | Description                                      |
| ------------------------ | ---- | ------------------------------------------ |
| HUKS_KEY_PURPOSE_ENCRYPT | 1    | The key (key pair) is used to encrypt the plaintext.|
| HUKS_KEY_PURPOSE_DECRYPT | 2    | The key (key pair) is used to decrypt the ciphertext.|
| HUKS_KEY_PURPOSE_SIGN    | 4    | The key pair is used to sign data.            |
| HUKS_KEY_PURPOSE_VERIFY  | 8    | The key pair is used to verify signed data.          |
| HUKS_KEY_PURPOSE_DERIVE  | 16   | The key is used to derive a key.                    |
| HUKS_KEY_PURPOSE_WRAP    | 32   | The key is used for encrypted import.                    |
| HUKS_KEY_PURPOSE_UNWRAP  | 64   | The key is exported in encrypted mode.                        |
| HUKS_KEY_PURPOSE_MAC     | 128  | The key is used to generate a message authentication code (MAC).           |
| HUKS_KEY_PURPOSE_AGREE   | 256  | The key pair is used for key agreement.              |

## HuksKeyDigest

Enumerates the digest algorithms.

**System capability**: SystemCapability.Security.Huks

| Name                  | Value  | Description                                    |
| ---------------------- | ---- | ---------------------------------------- |
| HUKS_DIGEST_NONE       | 0   | No digest algorithm.|
| HUKS_DIGEST_MD5        | 1    | MD5.|
| HUKS_DIGEST_SHA1       | 10   | SHA1.|
| HUKS_DIGEST_SHA224 | 11   | SHA-224.|
| HUKS_DIGEST_SHA256 | 12  | SHA-256.|
| HUKS_DIGEST_SHA384  | 13  | SHA-384.|
| HUKS_DIGEST_SHA512 | 14  | SHA-512.|

## HuksKeyPadding

Enumerates the padding algorithms.

**System capability**: SystemCapability.Security.Huks

| Name                  | Value  | Description                                    |
| ---------------------- | ---- | ---------------------------------------- |
| HUKS_PADDING_NONE | 0    | No padding algorithm.|
| HUKS_PADDING_OAEP | 1    | Optimal Asymmetric Encryption Padding (OAEP).|
| HUKS_PADDING_PSS | 2    | Probabilistic Signature Scheme (PSS).|
| HUKS_PADDING_PKCS1_V1_5 | 3    | PKCS1_V1_5.|
| HUKS_PADDING_PKCS5 | 4   | Public Key Cryptography Standards (PKCS)#5.|
| HUKS_PADDING_PKCS7 | 5   | PKCS#7|

## HuksCipherMode

Enumerates the cipher modes.

**System capability**: SystemCapability.Security.Huks

| Name         | Value  | Description                 |
| ------------- | ---- | --------------------- |
| HUKS_MODE_ECB | 1    | Electronic Code BLock (ECB) mode.|
| HUKS_MODE_CBC | 2    | Cipher Block Chaining (CBC) mode.|
| HUKS_MODE_CTR | 3    | Counter (CTR) mode.|
| HUKS_MODE_OFB | 4    | Output Feedback (OFB) mode.|
| HUKS_MODE_CCM | 31   | Counter with CBC-MAC (CCM) mode.|
| HUKS_MODE_GCM | 32   | Galois/Counter (GCM) mode.|

## HuksKeySize

Enumerates the key (key pair) sizes.

**System capability**: SystemCapability.Security.Huks

| Name                        | Value  | Description                                        |
| ---------------------------- | ---- | -------------------------------------------- |
| HUKS_RSA_KEY_SIZE_512        | 512  | Rivest-Shamir-Adleman (RSA) key pair of 512 bits.       |
| HUKS_RSA_KEY_SIZE_768        | 768  | RSA key pair of 768 bits.       |
| HUKS_RSA_KEY_SIZE_1024       | 1024 | RSA key pair of 1024 bits.      |
| HUKS_RSA_KEY_SIZE_2048       | 2048 | RSA key pair of 2048 bits.      |
| HUKS_RSA_KEY_SIZE_3072       | 3072 | RSA key pair of 3072 bits.      |
| HUKS_RSA_KEY_SIZE_4096       | 4096 | RSA key pair of 4096 bits.      |
| HUKS_ECC_KEY_SIZE_224        | 224  | ECC key pair of 224 bits.       |
| HUKS_ECC_KEY_SIZE_256        | 256  | ECC key pair of 256 bits.       |
| HUKS_ECC_KEY_SIZE_384        | 384  | ECC key pair of 384 bits.       |
| HUKS_ECC_KEY_SIZE_521        | 521  | ECC key pair of 521 bits.       |
| HUKS_AES_KEY_SIZE_128        | 128  | AES key of 128 bits.         |
| HUKS_AES_KEY_SIZE_192        | 196  | AES key of 196 bits.         |
| HUKS_AES_KEY_SIZE_256        | 256  | AES key of 256 bits.         |
| HUKS_AES_KEY_SIZE_512        | 512  | AES key of 512 bits.         |
| HUKS_CURVE25519_KEY_SIZE_256 | 256  | Curve25519 key pair of 256 bits.|
| HUKS_DH_KEY_SIZE_2048        | 2048 | DH key pair of 2048 bits.       |
| HUKS_DH_KEY_SIZE_3072        | 3072 | DH key pair of 3072 bits.       |
| HUKS_DH_KEY_SIZE_4096        | 4096 | The DH key pair is 4096 bits.       |

## HuksKeyAlg

Represents the algorithm used by a key.

**System capability**: SystemCapability.Security.Huks

| Name            | Value  | Description                 |
| ---------------- | ---- | --------------------- |
| HUKS_ALG_RSA     | 1    | RSA.    |
| HUKS_ALG_ECC     | 2    | ECC.    |
| HUKS_ALG_DSA     | 3    | DSA.    |
| HUKS_ALG_AES     | 20   | AES.    |
| HUKS_ALG_HMAC    | 50   | HMAC.   |
| HUKS_ALG_HKDF    | 51   | HKDF.   |
| HUKS_ALG_PBKDF2  | 52   | PBKDF2. |
| HUKS_ALG_ECDH    | 100  | ECDH.   |
| HUKS_ALG_X25519  | 101  | X25519 algorithm. |
| HUKS_ALG_ED25519 | 102  | ED25519 algorithm.|
| HUKS_ALG_DH      | 103  | DH.     |

## HuksKeyGenerateType

Enumerates the key generation types.

**System capability**: SystemCapability.Security.Huks

| Name                          | Value  | Description            |
| ------------------------------ | ---- | ---------------- |
| HUKS_KEY_GENERATE_TYPE_DEFAULT | 0    | Key generated by default.|
| HUKS_KEY_GENERATE_TYPE_DERIVE  | 1    | Derived key.|
| HUKS_KEY_GENERATE_TYPE_AGREE   | 2    | Key generated by agreement.|

## HuksKeyFlag

Enumerates the key generation modes.

**System capability**: SystemCapability.Security.Huks

| Name                      | Value  | Description                                |
| -------------------------- | ---- | ------------------------------------ |
| HUKS_KEY_FLAG_IMPORT_KEY   | 1    | The key is imported by using the public key import API.    |
| HUKS_KEY_FLAG_GENERATE_KEY | 2    | The key is generated by using the private key generation API.    |
| HUKS_KEY_FLAG_AGREE_KEY    | 3    | The key is generated by using the key agreement API.|
| HUKS_KEY_FLAG_DERIVE_KEY   | 4    | The key is generated by using the key derivation API.|

## HuksKeyStorageType

Enumerates the key storage modes.

**System capability**: SystemCapability.Security.Huks

| Name                   | Value  | Description                          |
| ----------------------- | ---- | ------------------------------ |
| HUKS_STORAGE_TEMP       | 0    | The key is managed locally.    |
| HUKS_STORAGE_PERSISTENT | 1    | The key is managed by the HUKS service.|

## HuksSendType

Enumerates the tag transfer modes.

**System capability**: SystemCapability.Security.Huks

| Name                | Value  | Description             |
| -------------------- | ---- | ----------------- |
| HUKS_SEND_TYPE_ASYNC | 0    | Send the tag asynchronously.|
| HUKS_SEND_TYPE_SYNC  | 1    | Send the tag synchronously.|

## HuksTagType

Enumerates the tag data types.

**System capability**: SystemCapability.Security.Huks


| Name                 | Value     | Description                             |
| --------------------- | ------- | --------------------------------- |
| HUKS_TAG_TYPE_INVALID | 0 << 28 | Invalid tag type.              |
| HUKS_TAG_TYPE_INT     | 1 << 28 | int.    |
| HUKS_TAG_TYPE_UINT    | 2 << 28 | uint.    |
| HUKS_TAG_TYPE_ULONG   | 3 << 28 | bigint.    |
| HUKS_TAG_TYPE_BOOL    | 4 << 28 | Boolean.   |
| HUKS_TAG_TYPE_BYTES   | 5 << 28 | Uint8Array.|

## HuksTag

Enumerates the tags used to invoke parameters.

**System capability**: SystemCapability.Security.Huks

| Name                                  | Value                                      | Description                                  |
| -------------------------------------- | ---------------------------------------- | -------------------------------------- |
| HUKS_TAG_INVALID                       | HuksTagType.HUKS_TAG_TYPE_INVALID \| 0   | Invalid tag.                       |
| HUKS_TAG_ALGORITHM                     | HUKS_TAG_TYPE_UINT \| 1                  | Indicates the algorithm.                       |
| HUKS_TAG_PURPOSE                       | HuksTagType.HUKS_TAG_TYPE_UINT \| 2      | Indicates the purpose (usage) of a key or key pair.         |
| HUKS_TAG_KEY_SIZE                      | HuksTagType.HUKS_TAG_TYPE_UINT \| 3      | Indicates the key (key pair) length.         |
| HUKS_TAG_DIGEST                        | HuksTagType.HUKS_TAG_TYPE_UINT \| 4      | Indicates the digest algorithm.                   |
| HUKS_TAG_PADDING                       | HuksTagType.HUKS_TAG_TYPE_UINT \| 5      | Indicates the padding algorithm.                   |
| HUKS_TAG_BLOCK_MODE                    | HuksTagType.HUKS_TAG_TYPE_UINT \| 6      | Indicates the cipher mode.                   |
| HUKS_TAG_KEY_TYPE                      | HuksTagType.HUKS_TAG_TYPE_UINT \| 7      | Indicates the key type.                   |
| HUKS_TAG_ASSOCIATED_DATA               | HuksTagType.HUKS_TAG_TYPE_BYTES \| 8     | Indicates the associated authentication data.       |
| HUKS_TAG_NONCE                         | HuksTagType.HUKS_TAG_TYPE_BYTES \| 9     | Indicates the nonce.             |
| HUKS_TAG_IV                            | HuksTagType.HUKS_TAG_TYPE_BYTES \| 10    | Indicates the IV.             |
| HUKS_TAG_INFO                          | HuksTagType.HUKS_TAG_TYPE_BYTES \| 11    | Indicates the information generated during key derivation.                |
| HUKS_TAG_SALT                          | HuksTagType.HUKS_TAG_TYPE_BYTES \| 12    | Indicates the salt value used for key derivation.                |
| HUKS_TAG_PWD                           | HuksTagType.HUKS_TAG_TYPE_BYTES \| 13    | Indicates the password used for key derivation.            |
| HUKS_TAG_ITERATION                     | HuksTagType.HUKS_TAG_TYPE_UINT \| 14     | Indicates the number of iterations for key derivation.            |
| HUKS_TAG_KEY_GENERATE_TYPE             | HuksTagType.HUKS_TAG_TYPE_UINT \| 15     | Indicates the key generation type.               |
| HUKS_TAG_DERIVE_MAIN_KEY               | HuksTagType.HUKS_TAG_TYPE_BYTES \| 16    | Indicates the main key for key derivation.              |
| HUKS_TAG_DERIVE_FACTOR                 | HuksTagType.HUKS_TAG_TYPE_BYTES \| 17    | Indicates the factor for key derivation.            |
| HUKS_TAG_DERIVE_ALG                    | HuksTagType.HUKS_TAG_TYPE_UINT \| 18     | Indicates the type of the algorithm used for key derivation.            |
| HUKS_TAG_AGREE_ALG                     | HuksTagType.HUKS_TAG_TYPE_UINT \| 19     | Indicates the type of the algorithm used in key agreement.            |
| HUKS_TAG_AGREE_PUBLIC_KEY_IS_KEY_ALIAS | HuksTagType.HUKS_TAG_TYPE_BOOL \| 20     | Indicates the alias of the public key during key agreement.            |
| HUKS_TAG_AGREE_PRIVATE_KEY_ALIAS       | HuksTagType.HUKS_TAG_TYPE_BYTES \| 21    | Indicates the private key alias used in key agreement.            |
| HUKS_TAG_AGREE_PUBLIC_KEY              | HuksTagType.HUKS_TAG_TYPE_BYTES \| 22    | Indicates the public key used in key agreement.                |
| HUKS_TAG_KEY_ALIAS                     | HuksTagType.HUKS_TAG_TYPE_BYTES \| 23    | Indicates the key alias.                        |
| HUKS_TAG_DERIVE_KEY_SIZE               | HuksTagType.HUKS_TAG_TYPE_UINT \| 24     | Indicates the size of the derived key.                  |
| HUKS_TAG_ACTIVE_DATETIME               | HuksTagType.HUKS_TAG_TYPE_ULONG \| 201   | Reserved.                                |
| HUKS_TAG_ORIGINATION_EXPIRE_DATETIME   | HuksTagType.HUKS_TAG_TYPE_ULONG \| 202   | Reserved.                                |
| HUKS_TAG_USAGE_EXPIRE_DATETIME         | HuksTagType.HUKS_TAG_TYPE_ULONG \| 203   | Reserved.                                |
| HUKS_TAG_CREATION_DATETIME             | HuksTagType.HUKS_TAG_TYPE_ULONG \| 204   | Reserved.                                |
| HUKS_TAG_ALL_USERS                     | ksTagType.HUKS_TAG_TYPE_BOOL \| 301      | Reserved.                                |
| HUKS_TAG_USER_ID                       | HuksTagType.HUKS_TAG_TYPE_UINT \| 302    | Reserved.                                |
| HUKS_TAG_NO_AUTH_REQUIRED              | HuksTagType.HUKS_TAG_TYPE_BOOL \| 303    | Reserved.                                |
| HUKS_TAG_USER_AUTH_TYPE                | HuksTagType.HUKS_TAG_TYPE_UINT \| 304    | Reserved.                                |
| HUKS_TAG_AUTH_TIMEOUT                  | HuksTagType.HUKS_TAG_TYPE_UINT \| 305    | Reserved.                                |
| HUKS_TAG_AUTH_TOKEN                    | HuksTagType.HUKS_TAG_TYPE_BYTES \| 306   | Reserved.                                |
| HUKS_TAG_ATTESTATION_CHALLENGE         | HuksTagType.HUKS_TAG_TYPE_BYTES \| 501   | Indicates the challenge value used in the attestation.           |
| HUKS_TAG_ATTESTATION_APPLICATION_ID    | HuksTagType.HUKS_TAG_TYPE_BYTES \| 502   | Indicates the application ID used in the attestation.   |
| HUKS_TAG_ATTESTATION_ID_BRAND          | HuksTagType.HUKS_TAG_TYPE_BYTES \| 503   | Indicates the device brand.                     |
| HUKS_TAG_ATTESTATION_ID_DEVICE         | HuksTagType.HUKS_TAG_TYPE_BYTES \| 504   | Indicates the device.                    |
| HUKS_TAG_ATTESTATION_ID_PRODUCT        | HuksTagType.HUKS_TAG_TYPE_BYTES \| 505   | Indicates the product.                   |
| HUKS_TAG_ATTESTATION_ID_SERIAL         | HuksTagType.HUKS_TAG_TYPE_BYTES \| 506   | Indicates the device SN.                      |
| HUKS_TAG_ATTESTATION_ID_IMEI           | HuksTagType.HUKS_TAG_TYPE_BYTES \| 507   | Indicates the device IMEI.                    |
| HUKS_TAG_ATTESTATION_ID_MEID           | HuksTagType.HUKS_TAG_TYPE_BYTES \| 508   | Indicates the device MEID.                    |
| HUKS_TAG_ATTESTATION_ID_MANUFACTURER   | HuksTagType.HUKS_TAG_TYPE_BYTES \| 509   | Indicates the device manufacturer.                    |
| HUKS_TAG_ATTESTATION_ID_MODEL          | HuksTagType.HUKS_TAG_TYPE_BYTES \| 510   | Indicates the device model.                      |
| HUKS_TAG_ATTESTATION_ID_ALIAS          | HuksTagType.HUKS_TAG_TYPE_BYTES \| 511   | Indicates the key alias used in the attestation.         |
| HUKS_TAG_ATTESTATION_ID_SOCID          | HuksTagType.HUKS_TAG_TYPE_BYTES \| 512   | Indicates the device SOCID.                     |
| HUKS_TAG_ATTESTATION_ID_UDID           | HuksTagType.HUKS_TAG_TYPE_BYTES \| 513   | Indicates the device UDID.                      |
| HUKS_TAG_ATTESTATION_ID_SEC_LEVEL_INFO | HuksTagType.HUKS_TAG_TYPE_BYTES \| 514   | Indicates the security credential used for the attestation.         |
| HUKS_TAG_ATTESTATION_ID_VERSION_INFO   | HuksTagType.HUKS_TAG_TYPE_BYTES \| 515   | Indicates the version information used in the attestation.           |
| HUKS_TAG_IS_KEY_ALIAS                  | HuksTagType.HUKS_TAG_TYPE_BOOL \| 1001   | Indicates whether to use the tag of the alias passed during key generation.|
| HUKS_TAG_KEY_STORAGE_FLAG              | HuksTagType.HUKS_TAG_TYPE_UINT \| 1002   | Indicates the key storage mode.               |
| HUKS_TAG_IS_ALLOWED_WRAP               | HuksTagType.HUKS_TAG_TYPE_BOOL \| 1003   | Reserved.                                |
| HUKS_TAG_KEY_WRAP_TYPE                 | HuksTagType.HUKS_TAG_TYPE_UINT \| 1004   | Reserved.                                |
| HUKS_TAG_KEY_AUTH_ID                   | HuksTagType.HUKS_TAG_TYPE_BYTES \| 1005  | Reserved.                                |
| HUKS_TAG_KEY_ROLE                      | HuksTagType.HUKS_TAG_TYPE_UINT \| 1006   | Reserved.                                |
| HUKS_TAG_KEY_FLAG                      | HuksTagType.HUKS_TAG_TYPE_UINT \| 1007   | Indicates the flag of the key.                   |
| HUKS_TAG_IS_ASYNCHRONIZED              | HuksTagType.HUKS_TAG_TYPE_UINT \| 1008   | Reserved.                                |
| HUKS_TAG_SECURE_KEY_ALIAS              | HuksTagType.HUKS_TAG_TYPE_BOOL \| 1009   | Reserved.                                |
| HUKS_TAG_SECURE_KEY_UUID               | HuksTagType.HUKS_TAG_TYPE_BYTES \| 1010  | Reserved.                                |
| HUKS_TAG_KEY_DOMAIN                    | HuksTagType.HUKS_TAG_TYPE_UINT \| 1011   | Reserved.                                |
| HUKS_TAG_PROCESS_NAME                  | HuksTagType.HUKS_TAG_TYPE_BYTES \| 10001 | Indicates the process name.                   |
| HUKS_TAG_PACKAGE_NAME                  | HuksTagType.HUKS_TAG_TYPE_BYTES \| 10002 | Reserved.                                |
| HUKS_TAG_ACCESS_TIME                   | HuksTagType.HUKS_TAG_TYPE_UINT \| 10003  | Reserved.                                |
| HUKS_TAG_USES_TIME                     | HuksTagType.HUKS_TAG_TYPE_UINT \| 10004  | Reserved.                                |
| HUKS_TAG_CRYPTO_CTX                    | HuksTagType.HUKS_TAG_TYPE_ULONG \| 10005 | Reserved.                                |
| HUKS_TAG_KEY                           | HuksTagType.HUKS_TAG_TYPE_BYTES \| 10006 | Reserved.                                |
| HUKS_TAG_KEY_VERSION                   | HuksTagType.HUKS_TAG_TYPE_UINT \| 10007  | Indicates the key version.                   |
| HUKS_TAG_PAYLOAD_LEN                   | HuksTagType.HUKS_TAG_TYPE_UINT \| 10008  | Reserved.                                |
| HUKS_TAG_AE_TAG                        | HuksTagType.HUKS_TAG_TYPE_BYTES \| 10009 | Reserved.                                |
| HUKS_TAG_IS_KEY_HANDLE                 | HuksTagType.HUKS_TAG_TYPE_ULONG \| 10010 | Reserved.                                |
| HUKS_TAG_OS_VERSION                    | HuksTagType.HUKS_TAG_TYPE_UINT \| 10101  | Indicates the operating system version.               |
| HUKS_TAG_OS_PATCHLEVEL                 | HuksTagType.HUKS_TAG_TYPE_UINT \| 10102  | Indicates the operating system patch level.           |
| HUKS_TAG_SYMMETRIC_KEY_DATA            | HuksTagType.HUKS_TAG_TYPE_BYTES \| 20001 | Reserved.                                |
| HUKS_TAG_ASYMMETRIC_PUBLIC_KEY_DATA    | HuksTagType.HUKS_TAG_TYPE_BYTES \| 20002 | Reserved.                                |
| HUKS_TAG_ASYMMETRIC_PRIVATE_KEY_DATA   | HuksTagType.HUKS_TAG_TYPE_BYTES \| 20003 | Reserved.                                |

## huks.generateKey

generateKey(keyAlias: string, options: HuksOptions, callback: AsyncCallback\<HuksResult>) : void

Generates a key (key pair). This method uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Security.Huks

**Parameters**

| Name  | Type                                     | Mandatory| Description                                                        |
| -------- | ----------------------------------------- | ---- | ------------------------------------------------------------ |
| keyAlias | string                                    | Yes  | Alias of the key.                                                       |
| options  | [HuksOptions](#huksoptions)               | Yes  | Tags required for generating the key.                                    |
| callback | AsyncCallback\<[HuksResult](#huksresult)> | Yes  | Callback used to return the result. If the operation is successful, **HUKS_SUCCESS** will be returned. If the operation fails, an error code will be returned. For details about the error codes, see **HuksResult**. |

**Example**

```js
var alias = 'alias';
var properties = new Array();
properties[0] = {
  tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
  value: huksHuksKeyAlg.HUKS_ALG_RSA
};
properties[1] = {
  tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
  value: huks.HuksKeySize.HUKS_RSA_KEY_SIZE_512
};
properties[2] = {
  tag: huks.HuksTag.HUKS_TAG_PURPOSE,
  value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT | huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DECRYPT
};
properties[3] = {
  tag: huks.HuksTag.HUKS_TAG_PADDING,
  value: huks.HuksKeyPadding.HUKS_PADDING_NONE
};
properties[4] = {
  tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
  value: huks.HuksCipherMode.HUKS_MODE_ECB
};
properties[5] = {
  tag: huks.HuksTag.HUKS_TAG_DIGEST,
  value: huks.HuksKeyDigest.HUKS_DIGEST_NONE
};
var options = {
  properties: properties
};
huks.generateKey(alias, options, function (err, data){}); 
```

## huks.generateKey

generateKey(keyAlias: string, options: HuksOptions) : Promise\<HuksResult>

Generates a key (key pair). This method uses a promise to return the result.

**System capability**: SystemCapability.Security.Huks

**Parameters**

| Name  | Type                       | Mandatory| Description                    |
| -------- | --------------------------- | ---- | ------------------------ |
| keyAlias | string                      | Yes  | Alias of the key.              |
| options  | [HuksOptions](#huksoptions) | Yes  | Tags required for generating the key.|

**Return value**

| Type                               | Description                                              |
| ----------------------------------- | -------------------------------------------------- |
| Promise\<[HuksResult](#huksresult)> | Promise used to return the result. If the operation is successful, **HUKS_SUCCESS** will be returned. If the operation fails, an error code will be returned. For details about the error codes, see **HuksResult**. |

**Example**

```js
var alias = 'alias';
var properties = new Array();
properties[0] = {
  tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
  value: huksHuksKeyAlg.HUKS_ALG_RSA
};
properties[1] = {
  tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
  value: huks.HuksKeySize.HUKS_RSA_KEY_SIZE_512
};
properties[2] = {
  tag: huks.HuksTag.HUKS_TAG_PURPOSE,
  value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT | huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DECRYPT
};
properties[3] = {
  tag: huks.HuksTag.HUKS_TAG_PADDING,
  value: huks.HuksKeyPadding.HUKS_PADDING_NONE
};
properties[4] = {
  tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
  value: huks.HuksCipherMode.HUKS_MODE_ECB
};
properties[5] = {
  tag: huks.HuksTag.HUKS_TAG_DIGEST,
  value: huks.HuksKeyDigest.HUKS_DIGEST_NONE
};
var options = {
  properties: properties
};
var result = huks.generateKey(alias, options);
```

## huks.deleteKey

deleteKey(keyAlias: string, options: HuksOptions, callback: AsyncCallback\<HuksResult>) : void

Deletes a key. This method uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Security.Huks

**Parameters**

| Name  | Type                                     | Mandatory| Description                                              |
| -------- | ----------------------------------------- | ---- | -------------------------------------------------- |
| keyAlias | string                                    | Yes  | Key alias passed in when the key was generated.               |
| options  | [HuksOptions](#huksoptions)               | Yes  | Empty object (leave this parameter empty).                          |
| callback | AsyncCallback\<[HuksResult](#huksresult)> | Yes  | Callback used to return the result. If the operation is successful, **HUKS_SUCCESS** will be returned. If the operation fails, an error code will be returned. For details about the error codes, see **HuksResult**. |

**Example**

```js
var alias = 'alias';
var emptyOptions = {
  properties: []
};
huks.deleteKey(alias, emptyOptions, function (err, data) {});
```

## huks.deleteKey

deleteKey(keyAlias: string, options: HuksOptions) : Promise\<HuksResult>

Deletes a key. This method uses a promise to return the result.

**System capability**: SystemCapability.Security.Huks

**Parameters**

| Name  | Type       | Mandatory| Description                                                 |
| -------- | ----------- | ---- | ----------------------------------------------------- |
| keyAlias | string      | Yes  | Key alias passed in when the key was generated.|
| options  | [HuksOptions](#huksoptions) | Yes  | Empty object (leave this parameter empty).|

**Return value**

| Type                               | Description                                              |
| ----------------------------------- | -------------------------------------------------- |
| Promise\<[HuksResult](#huksresult)> | Promise used to return the result. If the operation is successful, **HUKS_SUCCESS** will be returned. If the operation fails, an error code will be returned. For details about the error codes, see **HuksResult**. |

**Example**

```js
var alias = 'alias';
var emptyOptions = {
  properties: []
};
var result = huks.deleteKey(alias, emptyOptions);
```

## huks.getSdkVersion

getSdkVersion(options: HuksOptions) : string

Obtains the SDK version of the current system.

**System capability**: SystemCapability.Security.Huks

**Parameters**

| Name | Type      | Mandatory| Description                     |
| ------- | ---------- | ---- | ------------------------- |
| options | [HuksOptions](#huksoptions) | Yes  | Empty object, which is used to hold the SDK version.|

**Return value**

| Type  | Description                                                        |
| ------ | ------------------------------------------------------------ |
| string | SDK version obtained. |

**Example**

```js
var emptyOptions = {
  properties: []
};
var result = huks.getSdkVersion(emptyOptions);
```

## huks.importKey

importKey(keyAlias: string, options: HuksOptions, callback: AsyncCallback\<HuksResult>) : void

Imports a key pair. This method uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Security.Huks

**Parameters**

| Name  | Type                    | Mandatory| Description                                             |
| -------- | ------------------------ | ---- | ------------------------------------------------- |
| keyAlias | string                   | Yes  | Key alias, which is used to hold the key pair.|
| options  | [HuksOptions](#huksoptions) | Yes  | Tags required for the import and key pair to import.|
| callback | AsyncCallback\<[HuksResult](#huksresult)> | Yes  | Callback used to return the result. If the operation is successful, **HUKS_SUCCESS** will be returned. If the operation fails, an error code will be returned. For details about the error codes, see **HuksResult**. |

**Example**

```js
var keyAlias = 'keyAlias';
var properties = new Array();
properties[0] = {
  tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
  value: huks.HuksKeyAlg.HUKS_ALG_DSA
};
properties[1] = {
  tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
  value: 1024
};
properties[2] = {
  tag: huks.HuksTag.HUKS_TAG_PURPOSE,
  value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_VERIFY
};
properties[3] = {
  tag: huks.HuksTag.HUKS_TAG_PADDING,
  value: huks.HuksKeyPadding.HUKS_PADDING_NONE
};
properties[4] = {
  tag: huks.HuksTag.HUKS_TAG_DIGEST,
  value: HUKS_DIGEST_SHA1
};
var options = {
  properties: properties,
  inData: importText
};
huks.importKey(keyAlias, options, function (err, data){});
```

## huks.importKey

importKey(keyAlias: string, options: HuksOptions) : Promise\<HuksResult>

Imports a key pair. This method uses a promise to return the result.

**System capability**: SystemCapability.Security.Huks

**Parameters**

| Name  | Type       | Mandatory| Description                                |
| -------- | ----------- | ---- | ------------------------------------ |
| keyAlias | string      | Yes  | Key alias, which is used to hold the key pair.|
| options  | [HuksOptions](#huksoptions) | Yes  | Tags required for the import and key pair to import.|

**Return value**

| Type                               | Description                                              |
| ----------------------------------- | -------------------------------------------------- |
| Promise\<[HuksResult](#huksresult)> | Promise used to return the result. If the operation is successful, **HUKS_SUCCESS** will be returned. If the operation fails, an error code will be returned. For details about the error codes, see **HuksResult**. |

**Example**

```js
var keyAlias = 'keyAlias';
var properties = new Array();
properties[0] = {
  tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
  value: huks.HuksKeyAlg.HUKS_ALG_DSA
};
properties[1] = {
  tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
  value: 1024
};
properties[2] = {
  tag: huks.HuksTag.HUKS_TAG_PURPOSE,
  value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_VERIFY
};
properties[3] = {
  tag: huks.HuksTag.HUKS_TAG_PADDING,
  value: huks.HuksKeyPadding.HUKS_PADDING_NONE
};
properties[4] = {
  tag: huks.HuksTag.HUKS_TAG_DIGEST,
  value: HUKS_DIGEST_SHA1
};
var options = {
  properties: properties,
  inData: importText
};
var result = huks.importKey(keyAlias, options);
```

## huks.exportKey

exportKey(keyAlias: string, options: HuksOptions, callback: AsyncCallback\<HuksResult>) : void

Exports a key pair. This method uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Security.Huks

**Parameters**

| Name  | Type                                     | Mandatory| Description                                                        |
| -------- | ----------------------------------------- | ---- | ------------------------------------------------------------ |
| keyAlias | string                                    | Yes  | Key alias, which must be the same as the alias used when the key was generated.                |
| options  | [HuksOptions](#huksoptions)               | Yes  | Empty object (leave this parameter empty).                                    |
| callback | AsyncCallback\<[HuksResult](#huksresult)> | Yes  | Callback used to return the result. If the operation is successful, **HUKS_SUCCESS** will be returned. If the operation fails, an error code will be returned. For details about the error codes, see **HuksResult**. **outData** contains the public key exported. |

**Example**

```js
var keyAlias = 'keyAlias';
var emptyOptions = {
  properties: []
};
huks.exportKey(keyAlias, emptyOptions, function (err, data){});
```

## huks.exportKey

exportKey(keyAlias: string, options: HuksOptions) : Promise\<HuksResult>

Exports a key pair. This method uses a promise to return the result.

**System capability**: SystemCapability.Security.Huks

**Parameters**

| Name  | Type       | Mandatory| Description                                                        |
| -------- | ----------- | ---- | ------------------------------------------------------------ |
| keyAlias | string      | Yes  | Key alias, which must be the same as the alias used when the key was generated.|
| options  | [HuksOptions](#huksoptions) | Yes  | Empty object (leave this parameter empty).|

**Return value**

| Type                               | Description                                                        |
| ----------------------------------- | ------------------------------------------------------------ |
| Promise\<[HuksResult](#huksresult)> | Promise used to return the result. If the operation is successful, **HUKS_SUCCESS** will be returned. If the operation fails, an error code will be returned. For details about the error codes, see **HuksResult**.<br/> **outData** contains the public key exported. |

**Example**

```js
var keyAlias = 'keyAlias';
var emptyOptions = {
  properties: []
};
var result = huks.exportKey(keyAlias, emptyOptions);
```

## huks.getKeyProperties

getKeyProperties(keyAlias: string, options: HuksOptions, callback: AsyncCallback\<HuksResult>) : void

Obtains key properties. This method uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Security.Huks

**Parameters**

| Name  | Type                                     | Mandatory| Description                                                        |
| -------- | ----------------------------------------- | ---- | ------------------------------------------------------------ |
| keyAlias | string                                    | Yes  | Key alias, which must be the same as the alias used when the key was generated.                |
| options  | [HuksOptions](#huksoptions)               | Yes  | Empty object (leave this parameter empty).                                    |
| callback | AsyncCallback\<[HuksResult](#huksresult)> | Yes  | Callback used to return the result. In **errorCode**, **HUKS_SUCCESS** will be returned if the operation is successful; an error code will be returned otherwise. |

**Example**

```js
var keyAlias = 'keyAlias';
var emptyOptions = {
  properties: []
};
huks.getKeyProperties(keyAlias, emptyOptions, function (err, data){});
```

## huks.getKeyProperties

getKeyProperties(keyAlias: string, options: HuksOptions) : Promise\<HuksResult>

Obtains key properties. This method uses a promise to return the result.

**System capability**: SystemCapability.Security.Huks

**Parameters**

| Name  | Type       | Mandatory| Description                                                        |
| -------- | ----------- | ---- | ------------------------------------------------------------ |
| keyAlias | string      | Yes  | Key alias, which must be the same as the alias used when the key was generated. |
| options  | [HuksOptions](#huksoptions) | Yes  | Empty object (leave this parameter empty). |

**Return value**

| Type              | Description                                                        |
| ------------------ | ------------------------------------------------------------ |
| Promise\<[HuksResult](#huksoptions)> | Promise used to return the result. In **errorCode**, **HUKS_SUCCESS** will be returned if the operation is successful; an error code will be returned otherwise. For details about the error codes, see **HuksResult**. |

**Example**

```js
var keyAlias = 'keyAlias';
var emptyOptions = {
  properties: []
};
var result = huks.getKeyProperties(keyAlias, emptyOptions);
```

## huks.isKeyExist

isKeyExist(keyAlias: string, options: HuksOptions, callback: AsyncCallback\<boolean>) : void

Checks whether a key exists. This method uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Security.Huks

**Parameters**

| Name  | Type                  | Mandatory| Description                                 |
| -------- | ---------------------- | ---- | ------------------------------------- |
| keyAlias | string                 | Yes  | Alias of the key to check.|
| options  | [HuksOptions](#huksoptions) | Yes  | Empty object (leave this parameter empty).|
| callback | AsyncCallback\<boolean> | Yes  | Callback used to return the result. **TRUE** means that the key exists; **FALSE** means the opposite.|

**Example**

```js
var keyAlias = 'keyAlias';
var emptyOptions = {
  properties: []
};
huks.isKeyExist(keyAlias, emptyOptions, function (err, data){});
```

## huks.isKeyExist

isKeyExist(keyAlias: string, options: HuksOptions) : Promise\<boolean>

Checks whether a key exists. This method uses a promise to return the result.

**System capability**: SystemCapability.Security.Huks

**Parameters**

| Name  | Type       | Mandatory| Description                            |
| -------- | ----------- | ---- | -------------------------------- |
| keyAlias | string      | Yes  | Alias of the key to check.|
| options  | [HuksOptions](#huksoptions) | Yes  | Empty object (leave this parameter empty).|

**Return value**

| Type             | Description                                   |
| ----------------- | --------------------------------------- |
| Promise\<boolean> | Promise used to return the result. **TRUE** means that the key exists; **FALSE** means the opposite.|

**Example**

```js
var keyAlias = 'keyAlias';
var emptyOptions = {
  properties: []
};
var result = huks.isKeyExist(keyAlias, emptyOptions);
```


## huks.init

init(keyAlias: string, options: HuksOptions, callback: AsyncCallback\<HuksHandle>) : void

Initializes a key. This method uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Security.Huks

**Parameters**

| Name  | Type                  | Mandatory| Description                                 |
| -------- | ---------------------- | ---- | ------------------------------------- |
| keyAlias | string                 | Yes  | Alias of the target key.|
| options  | [HuksOptions](#huksoptions) | Yes  | Parameter set of the **Init** operation.|
| callback | AsyncCallback\<[HuksHandle](#hukshandle)> | Yes  | Callback used to return the handle of the **Init** operation.|

**Example**

```js
var alias = 'test001'
var properties = new Array();
properties[0] = {
  tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
  value: huks.HksKeyAlg.HKS_ALG_DH
};
properties[1] = {
  tag: huks.HksTag.HKS_TAG_PURPOSE,
  value: huks.HksKeyPurpose.HKS_KEY_PURPOSE_AGREE
};
properties[2] = {
  tag: huks.HksTag.HKS_TAG_KEY_SIZE,
  value: huks.HksKeySize.HKS_DH_KEY_SIZE_4096
};
var options = {
  properties: properties
};
huks.init(alias, options, function(err, data) {
    if (err.code !== 0) {
        console.log("test init err information: " + JSON.stringify(err));
    } else {
        console.log(`test init data: ${JSON.stringify(data)}`);
    }
})
```

## huks.init

init(keyAlias: string, options: HuksOptions) : Promise\<HuksHandle>

Initializes a key. This method uses a promise to return the result.

**System capability**: SystemCapability.Security.Huks

**Parameters**

| Name  | Type                  | Mandatory| Description                                 |
| -------- | ---------------------- | ---- | ------------------------------------- |
| keyAlias | string                 | Yes  | Alias of the target key.|
| options  | [HuksOptions](#huksoptions) | Yes  | Parameter set of the **Init** operation.|
| promise | Promise\<[HuksHandle](#hukshandle)> | Yes  | Promise used to return the handle of the **Init** operation.|

**Example**

```js
var alias = 'test001'
var properties = new Array();
properties[0] = {
  tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
  value: huks.HksKeyAlg.HKS_ALG_DH
};
properties[1] = {
  tag: huks.HksTag.HKS_TAG_PURPOSE,
  value: huks.HksKeyPurpose.HKS_KEY_PURPOSE_AGREE
};
properties[2] = {
  tag: huks.HksTag.HKS_TAG_KEY_SIZE,
  value: huks.HksKeySize.HKS_DH_KEY_SIZE_4096
};
var options = {
  properties: properties
};
huks.init(alias, options).then((data) => {
    console.log(`test init data: ${JSON.stringify(data)}`);
    handle1 = data.handle1;
    handle2 = data.handle2;
    handle = {
        "handle1": handle1,
        "handle2": handle2
    };
}).catch((err) => {
    console.log("test init err information: " + JSON.stringify(err))
}) 
```


## huks.update

update(handle: number, token?: Uint8Array, options: HuksOptions, callback: AsyncCallback\<HuksResult>) : void

Updates a key. This method uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Security.Huks

**Parameters**

| Name  | Type                  | Mandatory| Description                                 |
| -------- | ---------------------- | ---- | ------------------------------------- |
| handle | number           | Yes  | Handle of the **Update** operation.|
| token | Uint8Array | No| Token of the **Update** operation.|
| options  | [HuksOptions](#huksoptions) | Yes  | Parameter set of the **Update** operation.|
| callback | AsyncCallback\<[HksResult](#hksresult)> | Yes| Callback used to return the operation result.|

**Example**

```js
var properties = new Array();
properties[0] = {
  tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
  value: huks.HksKeyAlg.HKS_ALG_DH
};
properties[1] = {
  tag: huks.HksTag.HKS_TAG_PURPOSE,
  value: huks.HksKeyPurpose.HKS_KEY_PURPOSE_AGREE
};
properties[2] = {
  tag: huks.HksTag.HKS_TAG_KEY_SIZE,
  value: huks.HksKeySize.HKS_DH_KEY_SIZE_4096
};
var options = {
  properties: properties
};
huks.update(handle, options, function (err, data){}); 
```

## huks.update

update(handle: number, token?: Uint8Array, options: HuksOptions) : Promise\<HuksResult>

Updates a key. This method uses a promise to return the result.

**System capability**: SystemCapability.Security.Huks

**Parameters**

| Name  | Type                  | Mandatory| Description                                 |
| -------- | ---------------------- | ---- | ------------------------------------- |
| handle | number           | Yes  | Handle of the **Update** operation.|
| token | Uint8Array | No| Token of the **Update** operation.|
| options  | [HuksOptions](#huksoptions) | Yes  | Parameter set of the **Update** operation.|
| promise | Promise\<[HuksResult](#huksresult)> | Yes| Promise used to return the operation result.|

**Example**

```js
var properties = new Array();
properties[0] = {
  tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
  value: huks.HksKeyAlg.HKS_ALG_DH
};
properties[1] = {
  tag: huks.HksTag.HKS_TAG_PURPOSE,
  value: huks.HksKeyPurpose.HKS_KEY_PURPOSE_AGREE
};
properties[2] = {
  tag: huks.HksTag.HKS_TAG_KEY_SIZE,
  value: huks.HksKeySize.HKS_DH_KEY_SIZE_4096
};
var options = {
  properties: properties
};
var result = huks.update(handle, options)
```

## huks.finish

finish(handle: number, options: HuksOptions, callback: AsyncCallback\<HuksResult>) : void

Completes the operation and then releases resources. This method uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Security.Huks

**Parameters**

| Name  | Type                  | Mandatory| Description                                 |
| -------- | ---------------------- | ---- | ------------------------------------- |
| handle | number           | Yes  | Handle of the **Finish** operation.|
| options  | [HuksOptions](#huksoptions) | Yes  | Parameter set of the **Finish** operation.|
| callback | AsyncCallback\<[HuksResult](#huksresult)> | Yes| Callback used to return the operation result.|

**Example**

```js
var properties = new Array();
properties[0] = {
  tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
  value: huks.HksKeyAlg.HKS_ALG_DH
};
properties[1] = {
  tag: huks.HksTag.HKS_TAG_PURPOSE,
  value: huks.HksKeyPurpose.HKS_KEY_PURPOSE_AGREE
};
properties[2] = {
  tag: huks.HksTag.HKS_TAG_KEY_SIZE,
  value: huks.HksKeySize.HKS_DH_KEY_SIZE_4096
};
var options = {
  properties: properties
};
huks.finish(handle, options, function (err, data){}); 
```

## huks.finish

finish(handle: number, options: HuksOptions) : Promise\<HuksResult>

Completes the operation and then releases resources. This method uses a promise to return the result.

**System capability**: SystemCapability.Security.Huks

**Parameters**

| Name  | Type                  | Mandatory| Description                                 |
| -------- | ---------------------- | ---- | ------------------------------------- |
| handle | number           | Yes  | Handle of the **Finish** operation.|
| options  | [HuksOptions](#huksoptions) | Yes  | Parameter set of the **Finish** operation.|
| promise | Promise\<[HuksResult](#HuksResult)> | Yes| Promise used to return the operation result.|

**Example**

```js
var properties = new Array();
properties[0] = {
  tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
  value: huks.HksKeyAlg.HKS_ALG_DH
};
properties[1] = {
  tag: huks.HksTag.HKS_TAG_PURPOSE,
  value: huks.HksKeyPurpose.HKS_KEY_PURPOSE_AGREE
};
properties[2] = {
  tag: huks.HksTag.HKS_TAG_KEY_SIZE,
  value: huks.HksKeySize.HKS_DH_KEY_SIZE_4096
};
var options = {
  properties: properties
};
var result = huks.finish(handle, options)
```


## huks.abort

abort(handle: number, options: HuksOptions, callback: AsyncCallback\<HuksResult>) : void

Aborts the use of the key. This method uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Security.Huks

**Parameters**

| Name  | Type                  | Mandatory| Description                                 |
| -------- | ---------------------- | ---- | ------------------------------------- |
| handle | number           | Yes  | Handle of the **Abort** operation.|
| options  | [HuksOptions](#huksoptions) | Yes  | Parameter set of the **Abort** operation.|
| callback | AsyncCallback\<[HuksResult](#huksresult)> | Yes| Callback used to return the operation result.|

**Example**

```js
var properties = new Array();
properties[0] = {
  tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
  value: huks.HksKeyAlg.HKS_ALG_DH
};
properties[1] = {
  tag: huks.HksTag.HKS_TAG_PURPOSE,
  value: huks.HksKeyPurpose.HKS_KEY_PURPOSE_AGREE
};
properties[2] = {
  tag: huks.HksTag.HKS_TAG_KEY_SIZE,
  value: huks.HksKeySize.HKS_DH_KEY_SIZE_4096
};
var options = {
  properties: properties
};
huks.abort(handle, options, function (err, data){}); 
```

## huks.abort

abort(handle: number, options: HuksOptions) : Promise\<HuksResult>;

Aborts the use of the key. This method uses a promise to return the result.

**System capability**: SystemCapability.Security.Huks

**Parameters**

| Name  | Type                  | Mandatory| Description                                 |
| -------- | ---------------------- | ---- | ------------------------------------- |
| handle | number           | Yes  | Handle of the **Abort** operation.|
| options  | [HuksOptions](#huksoptions) | Yes  | Parameter set of the **Abort** operation.|
| promise | Promise\<[HuksResult](#huksresult)> | Yes| Promise used to return the operation result.|

**Example**

```js
var properties = new Array();
properties[0] = {
  tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
  value: huks.HksKeyAlg.HKS_ALG_DH
};
properties[1] = {
  tag: huks.HksTag.HKS_TAG_PURPOSE,
  value: huks.HksKeyPurpose.HKS_KEY_PURPOSE_AGREE
};
properties[2] = {
  tag: huks.HksTag.HKS_TAG_KEY_SIZE,
  value: huks.HksKeySize.HKS_DH_KEY_SIZE_4096
};
var options = {
  properties: properties
};
var result = huks.abort(handle, options);
```

## HuksParam

Defines the **param** in the **properties** array of **options** used in the APIs.

**System capability**: SystemCapability.Security.Huks

| Name| Type                               | Mandatory| Description      |
| ------ | ----------------------------------- | ---- | ---------- |
| tag    | HuksTag                             | Yes  | Tag.      |
| value  | boolean\|number\|bigint\|Uint8Array | Yes  | Value of the tag.|

## HuksOptions

Defines the **options** used in the APIs. 

**System capability**: SystemCapability.Security.Huks

| Name    | Type             | Mandatory| Description                    |
| ---------- | ----------------- | ---- | ------------------------ |
| properties | Array\<HuksParam> | No  | Array used to hold **HuksParam**.|
| inData     | Uint8Array        | No  | Input data.              |

## HuksHandle

Defines the HUKS handle structure.

**System capability**: SystemCapability.Security.Huks

| Name    | Type            | Mandatory| Description    |
| ---------- | ---------------- | ---- | -------- |
| errorCode  | number           | Yes  | Error code.|
| handle    | number       | Yes| Value of the handle.|
| token | Uint8Array | No| Reserved field.|


## HuksResult

Defines the **HuksResult** structure.

**System capability**: SystemCapability.Security.Huks



| Name    | Type             | Mandatory| Description    |
| ---------- | ----------------- | ---- | -------- |
| errorCode  | number            | Yes  | Error code.  |
| outData    | Uint8Array        | No  | Output data.|
| properties | Array\<HuksParam> | No  | Properties.    |
| certChains | Array\<string>    | No  | Certificate chain.  |
