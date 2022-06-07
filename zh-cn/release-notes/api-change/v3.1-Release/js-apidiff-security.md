# 安全子系统JS API变更

OpenHarmony 3.1 Release版本相较于OpenHarmony 3.0 LTS版本，安全子系统的API变更如下:

## 接口变更

| 模块名 | 类名 | 方法/属性/枚举/常量 | 变更类型 |
|---|---|---|---|
| ohos.security.huks | HuksTag | HUKS_TAG_ASYMMETRIC_PRIVATE_KEY_DATA = HuksTagType.HUKS_TAG_TYPE_BYTES \| 20003 | 新增 |
| ohos.security.huks | HuksTag | HUKS_TAG_ASYMMETRIC_PUBLIC_KEY_DATA = HuksTagType.HUKS_TAG_TYPE_BYTES \| 20002 | 新增 |
| ohos.security.huks | HuksTag | HUKS_TAG_SYMMETRIC_KEY_DATA = HuksTagType.HUKS_TAG_TYPE_BYTES \| 20001 | 新增 |
| ohos.security.huks | HuksTag | HUKS_TAG_OS_PATCHLEVEL = HuksTagType.HUKS_TAG_TYPE_UINT \| 10102 | 新增 |
| ohos.security.huks | HuksTag | HUKS_TAG_OS_VERSION = HuksTagType.HUKS_TAG_TYPE_UINT \| 10101 | 新增 |
| ohos.security.huks | HuksTag | HUKS_TAG_IS_KEY_HANDLE = HuksTagType.HUKS_TAG_TYPE_ULONG \| 10010 | 新增 |
| ohos.security.huks | HuksTag | HUKS_TAG_AE_TAG = HuksTagType.HUKS_TAG_TYPE_BYTES \| 10009 | 新增 |
| ohos.security.huks | HuksTag | HUKS_TAG_PAYLOAD_LEN = HuksTagType.HUKS_TAG_TYPE_UINT \| 10008 | 新增 |
| ohos.security.huks | HuksTag | HUKS_TAG_KEY_VERSION = HuksTagType.HUKS_TAG_TYPE_UINT \| 10007 | 新增 |
| ohos.security.huks | HuksTag | HUKS_TAG_KEY = HuksTagType.HUKS_TAG_TYPE_BYTES \| 10006 | 新增 |
| ohos.security.huks | HuksTag | HUKS_TAG_CRYPTO_CTX = HuksTagType.HUKS_TAG_TYPE_ULONG \| 10005 | 新增 |
| ohos.security.huks | HuksTag | HUKS_TAG_USES_TIME = HuksTagType.HUKS_TAG_TYPE_UINT \| 10004 | 新增 |
| ohos.security.huks | HuksTag | HUKS_TAG_ACCESS_TIME = HuksTagType.HUKS_TAG_TYPE_UINT \| 10003 | 新增 |
| ohos.security.huks | HuksTag | HUKS_TAG_PACKAGE_NAME = HuksTagType.HUKS_TAG_TYPE_BYTES \| 10002 | 新增 |
| ohos.security.huks | HuksTag | HUKS_TAG_PROCESS_NAME = HuksTagType.HUKS_TAG_TYPE_BYTES \| 10001 | 新增 |
| ohos.security.huks | HuksTag | HUKS_TAG_KEY_DOMAIN = HuksTagType.HUKS_TAG_TYPE_UINT \| 1011 | 新增 |
| ohos.security.huks | HuksTag | HUKS_TAG_SECURE_KEY_UUID = HuksTagType.HUKS_TAG_TYPE_BYTES \| 1010 | 新增 |
| ohos.security.huks | HuksTag | HUKS_TAG_SECURE_KEY_ALIAS = HuksTagType.HUKS_TAG_TYPE_BOOL \| 1009 | 新增 |
| ohos.security.huks | HuksTag | HUKS_TAG_IS_ASYNCHRONIZED = HuksTagType.HUKS_TAG_TYPE_UINT \| 1008 | 新增 |
| ohos.security.huks | HuksTag | HUKS_TAG_KEY_FLAG = HuksTagType.HUKS_TAG_TYPE_UINT \| 1007 | 新增 |
| ohos.security.huks | HuksTag | HUKS_TAG_KEY_ROLE = HuksTagType.HUKS_TAG_TYPE_UINT \| 1006 | 新增 |
| ohos.security.huks | HuksTag | HUKS_TAG_KEY_AUTH_ID = HuksTagType.HUKS_TAG_TYPE_BYTES \| 1005 | 新增 |
| ohos.security.huks | HuksTag | HUKS_TAG_KEY_WRAP_TYPE = HuksTagType.HUKS_TAG_TYPE_UINT \| 1004 | 新增 |
| ohos.security.huks | HuksTag | HUKS_TAG_IS_ALLOWED_WRAP = HuksTagType.HUKS_TAG_TYPE_BOOL \| 1003 | 新增 |
| ohos.security.huks | HuksTag | HUKS_TAG_KEY_STORAGE_FLAG = HuksTagType.HUKS_TAG_TYPE_UINT \| 1002 | 新增 |
| ohos.security.huks | HuksTag | HUKS_TAG_IS_KEY_ALIAS = HuksTagType.HUKS_TAG_TYPE_BOOL \| 1001 | 新增 |
| ohos.security.huks | HuksTag | HUKS_TAG_ATTESTATION_ID_VERSION_INFO = HuksTagType.HUKS_TAG_TYPE_BYTES \| 515 | 新增 |
| ohos.security.huks | HuksTag | HUKS_TAG_ATTESTATION_ID_SEC_LEVEL_INFO = HuksTagType.HUKS_TAG_TYPE_BYTES \| 514 | 新增 |
| ohos.security.huks | HuksTag | HUKS_TAG_ATTESTATION_ID_UDID = HuksTagType.HUKS_TAG_TYPE_BYTES \| 513 | 新增 |
| ohos.security.huks | HuksTag | HUKS_TAG_ATTESTATION_ID_SOCID = HuksTagType.HUKS_TAG_TYPE_BYTES \| 512 | 新增 |
| ohos.security.huks | HuksTag | HUKS_TAG_ATTESTATION_ID_ALIAS = HuksTagType.HUKS_TAG_TYPE_BYTES \| 511 | 新增 |
| ohos.security.huks | HuksTag | HUKS_TAG_ATTESTATION_ID_MODEL = HuksTagType.HUKS_TAG_TYPE_BYTES \| 510 | 新增 |
| ohos.security.huks | HuksTag | HUKS_TAG_ATTESTATION_ID_MANUFACTURER = HuksTagType.HUKS_TAG_TYPE_BYTES \| 509 | 新增 |
| ohos.security.huks | HuksTag | HUKS_TAG_ATTESTATION_ID_MEID = HuksTagType.HUKS_TAG_TYPE_BYTES \| 508 | 新增 |
| ohos.security.huks | HuksTag | HUKS_TAG_ATTESTATION_ID_IMEI = HuksTagType.HUKS_TAG_TYPE_BYTES \| 507 | 新增 |
| ohos.security.huks | HuksTag | HUKS_TAG_ATTESTATION_ID_SERIAL = HuksTagType.HUKS_TAG_TYPE_BYTES \| 506 | 新增 |
| ohos.security.huks | HuksTag | HUKS_TAG_ATTESTATION_ID_PRODUCT = HuksTagType.HUKS_TAG_TYPE_BYTES \| 505 | 新增 |
| ohos.security.huks | HuksTag | HUKS_TAG_ATTESTATION_ID_DEVICE = HuksTagType.HUKS_TAG_TYPE_BYTES \| 504 | 新增 |
| ohos.security.huks | HuksTag | HUKS_TAG_ATTESTATION_ID_BRAND = HuksTagType.HUKS_TAG_TYPE_BYTES \| 503 | 新增 |
| ohos.security.huks | HuksTag | HUKS_TAG_ATTESTATION_APPLICATION_ID = HuksTagType.HUKS_TAG_TYPE_BYTES \| 502 | 新增 |
| ohos.security.huks | HuksTag | HUKS_TAG_ATTESTATION_CHALLENGE = HuksTagType.HUKS_TAG_TYPE_BYTES \| 501 | 新增 |
| ohos.security.huks | HuksTag | HUKS_TAG_AUTH_TOKEN = HuksTagType.HUKS_TAG_TYPE_BYTES \| 306 | 新增 |
| ohos.security.huks | HuksTag | HUKS_TAG_AUTH_TIMEOUT = HuksTagType.HUKS_TAG_TYPE_UINT \| 305 | 新增 |
| ohos.security.huks | HuksTag | HUKS_TAG_USER_AUTH_TYPE = HuksTagType.HUKS_TAG_TYPE_UINT \| 304 | 新增 |
| ohos.security.huks | HuksTag | HUKS_TAG_NO_AUTH_REQUIRED = HuksTagType.HUKS_TAG_TYPE_BOOL \| 303 | 新增 |
| ohos.security.huks | HuksTag | HUKS_TAG_USER_ID = HuksTagType.HUKS_TAG_TYPE_UINT \| 302 | 新增 |
| ohos.security.huks | HuksTag | HUKS_TAG_ALL_USERS = HuksTagType.HUKS_TAG_TYPE_BOOL \| 301 | 新增 |
| ohos.security.huks | HuksTag | HUKS_TAG_CREATION_DATETIME = HuksTagType.HUKS_TAG_TYPE_ULONG \| 204 | 新增 |
| ohos.security.huks | HuksTag | HUKS_TAG_USAGE_EXPIRE_DATETIME = HuksTagType.HUKS_TAG_TYPE_ULONG \| 203 | 新增 |
| ohos.security.huks | HuksTag | HUKS_TAG_ORIGINATION_EXPIRE_DATETIME = HuksTagType.HUKS_TAG_TYPE_ULONG \| 202 | 新增 |
| ohos.security.huks | HuksTag | HUKS_TAG_ACTIVE_DATETIME = HuksTagType.HUKS_TAG_TYPE_ULONG \| 201 | 新增 |
| ohos.security.huks | HuksTag | HUKS_TAG_DERIVE_KEY_SIZE = HuksTagType.HUKS_TAG_TYPE_UINT \| 24 | 新增 |
| ohos.security.huks | HuksTag | HUKS_TAG_KEY_ALIAS = HuksTagType.HUKS_TAG_TYPE_BYTES \| 23 | 新增 |
| ohos.security.huks | HuksTag | HUKS_TAG_AGREE_PUBLIC_KEY = HuksTagType.HUKS_TAG_TYPE_BYTES \| 22 | 新增 |
| ohos.security.huks | HuksTag | HUKS_TAG_AGREE_PRIVATE_KEY_ALIAS = HuksTagType.HUKS_TAG_TYPE_BYTES \| 21 | 新增 |
| ohos.security.huks | HuksTag | HUKS_TAG_AGREE_PUBLIC_KEY_IS_KEY_ALIAS = HuksTagType.HUKS_TAG_TYPE_BOOL \| 20 | 新增 |
| ohos.security.huks | HuksTag | HUKS_TAG_AGREE_ALG = HuksTagType.HUKS_TAG_TYPE_UINT \| 19 | 新增 |
| ohos.security.huks | HuksTag | HUKS_TAG_DERIVE_ALG = HuksTagType.HUKS_TAG_TYPE_UINT \| 18 | 新增 |
| ohos.security.huks | HuksTag | HUKS_TAG_DERIVE_FACTOR = HuksTagType.HUKS_TAG_TYPE_BYTES \| 17 | 新增 |
| ohos.security.huks | HuksTag | HUKS_TAG_DERIVE_MAIN_KEY = HuksTagType.HUKS_TAG_TYPE_BYTES \| 16 | 新增 |
| ohos.security.huks | HuksTag | HUKS_TAG_KEY_GENERATE_TYPE = HuksTagType.HUKS_TAG_TYPE_UINT \| 15 | 新增 |
| ohos.security.huks | HuksTag | HUKS_TAG_ITERATION = HuksTagType.HUKS_TAG_TYPE_UINT \| 14 | 新增 |
| ohos.security.huks | HuksTag | HUKS_TAG_PWD = HuksTagType.HUKS_TAG_TYPE_BYTES \| 13 | 新增 |
| ohos.security.huks | HuksTag | HUKS_TAG_SALT = HuksTagType.HUKS_TAG_TYPE_BYTES \| 12 | 新增 |
| ohos.security.huks | HuksTag | HUKS_TAG_INFO = HuksTagType.HUKS_TAG_TYPE_BYTES \| 11 | 新增 |
| ohos.security.huks | HuksTag | HUKS_TAG_IV = HuksTagType.HUKS_TAG_TYPE_BYTES \| 10 | 新增 |
| ohos.security.huks | HuksTag | HUKS_TAG_NONCE = HuksTagType.HUKS_TAG_TYPE_BYTES \| 9 | 新增 |
| ohos.security.huks | HuksTag | HUKS_TAG_ASSOCIATED_DATA = HuksTagType.HUKS_TAG_TYPE_BYTES \| 8 | 新增 |
| ohos.security.huks | HuksTag | HUKS_TAG_KEY_TYPE = HuksTagType.HUKS_TAG_TYPE_UINT \| 7 | 新增 |
| ohos.security.huks | HuksTag | HUKS_TAG_BLOCK_MODE = HuksTagType.HUKS_TAG_TYPE_UINT \| 6 | 新增 |
| ohos.security.huks | HuksTag | HUKS_TAG_PADDING = HuksTagType.HUKS_TAG_TYPE_UINT \| 5 | 新增 |
| ohos.security.huks | HuksTag | HUKS_TAG_DIGEST = HuksTagType.HUKS_TAG_TYPE_UINT \| 4 | 新增 |
| ohos.security.huks | HuksTag | HUKS_TAG_KEY_SIZE = HuksTagType.HUKS_TAG_TYPE_UINT \| 3 | 新增 |
| ohos.security.huks | HuksTag | HUKS_TAG_PURPOSE = HuksTagType.HUKS_TAG_TYPE_UINT \| 2 | 新增 |
| ohos.security.huks | HuksTag | HUKS_TAG_ALGORITHM = HuksTagType.HUKS_TAG_TYPE_UINT \| 1 | 新增 |
| ohos.security.huks | HuksTag | HUKS_TAG_INVALID = HuksTagType.HUKS_TAG_TYPE_INVALID \| 0 | 新增 |
| ohos.security.huks | HuksTagType | HUKS_TAG_TYPE_BYTES = 5 \<\< 28 | 新增 |
| ohos.security.huks | HuksTagType | HUKS_TAG_TYPE_BOOL = 4 \<\< 28 | 新增 |
| ohos.security.huks | HuksTagType | HUKS_TAG_TYPE_ULONG = 3 \<\< 28 | 新增 |
| ohos.security.huks | HuksTagType | HUKS_TAG_TYPE_UINT = 2 \<\< 28 | 新增 |
| ohos.security.huks | HuksTagType | HUKS_TAG_TYPE_INT = 1 \<\< 28 | 新增 |
| ohos.security.huks | HuksTagType | HUKS_TAG_TYPE_INVALID = 0 \<\< 28 | 新增 |
| ohos.security.huks | HuksSendType | HUKS_SEND_TYPE_SYNC = 1 | 新增 |
| ohos.security.huks | HuksSendType | HUKS_SEND_TYPE_ASYNC = 0 | 新增 |
| ohos.security.huks | HuksKeyStorageType | HUKS_STORAGE_PERSISTENT = 1 | 新增 |
| ohos.security.huks | HuksKeyStorageType | HUKS_STORAGE_TEMP = 0 | 新增 |
| ohos.security.huks | HuksKeyFlag | HUKS_KEY_FLAG_DERIVE_KEY = 4 | 新增 |
| ohos.security.huks | HuksKeyFlag | HUKS_KEY_FLAG_AGREE_KEY = 3 | 新增 |
| ohos.security.huks | HuksKeyFlag | HUKS_KEY_FLAG_GENERATE_KEY = 2 | 新增 |
| ohos.security.huks | HuksKeyFlag | HUKS_KEY_FLAG_IMPORT_KEY = 1 | 新增 |
| ohos.security.huks | HuksKeyGenerateType | HUKS_KEY_GENERATE_TYPE_AGREE = 2 | 新增 |
| ohos.security.huks | HuksKeyGenerateType | HUKS_KEY_GENERATE_TYPE_DERIVE = 1 | 新增 |
| ohos.security.huks | HuksKeyGenerateType | HUKS_KEY_GENERATE_TYPE_DEFAULT = 0 | 新增 |
| ohos.security.huks | HuksKeyAlg | HUKS_ALG_DH = 103 | 新增 |
| ohos.security.huks | HuksKeyAlg | HUKS_ALG_ED25519 = 102 | 新增 |
| ohos.security.huks | HuksKeyAlg | HUKS_ALG_X25519 = 101 | 新增 |
| ohos.security.huks | HuksKeyAlg | HUKS_ALG_ECDH = 100 | 新增 |
| ohos.security.huks | HuksKeyAlg | HUKS_ALG_PBKDF2 = 52 | 新增 |
| ohos.security.huks | HuksKeyAlg | HUKS_ALG_HKDF = 51 | 新增 |
| ohos.security.huks | HuksKeyAlg | HUKS_ALG_HMAC = 50 | 新增 |
| ohos.security.huks | HuksKeyAlg | HUKS_ALG_AES = 20 | 新增 |
| ohos.security.huks | HuksKeyAlg | HUKS_ALG_DSA = 3 | 新增 |
| ohos.security.huks | HuksKeyAlg | HUKS_ALG_ECC = 2 | 新增 |
| ohos.security.huks | HuksKeyAlg | HUKS_ALG_RSA = 1 | 新增 |
| ohos.security.huks | HuksKeySize | HUKS_DH_KEY_SIZE_4096 = 4096 | 新增 |
| ohos.security.huks | HuksKeySize | HUKS_DH_KEY_SIZE_3072 = 3072 | 新增 |
| ohos.security.huks | HuksKeySize | HUKS_DH_KEY_SIZE_2048 = 2048 | 新增 |
| ohos.security.huks | HuksKeySize | HUKS_CURVE25519_KEY_SIZE_256 = 256 | 新增 |
| ohos.security.huks | HuksKeySize | HUKS_AES_KEY_SIZE_512 = 512 | 新增 |
| ohos.security.huks | HuksKeySize | HUKS_AES_KEY_SIZE_256 = 256 | 新增 |
| ohos.security.huks | HuksKeySize | HUKS_AES_KEY_SIZE_192 = 192 | 新增 |
| ohos.security.huks | HuksKeySize | HUKS_AES_KEY_SIZE_128 = 128 | 新增 |
| ohos.security.huks | HuksKeySize | HUKS_ECC_KEY_SIZE_521 = 521 | 新增 |
| ohos.security.huks | HuksKeySize | HUKS_ECC_KEY_SIZE_384 = 384 | 新增 |
| ohos.security.huks | HuksKeySize | HUKS_ECC_KEY_SIZE_256 = 256 | 新增 |
| ohos.security.huks | HuksKeySize | HUKS_ECC_KEY_SIZE_224 = 224 | 新增 |
| ohos.security.huks | HuksKeySize | HUKS_RSA_KEY_SIZE_4096 = 4096 | 新增 |
| ohos.security.huks | HuksKeySize | HUKS_RSA_KEY_SIZE_3072 = 3072 | 新增 |
| ohos.security.huks | HuksKeySize | HUKS_RSA_KEY_SIZE_2048 = 2048 | 新增 |
| ohos.security.huks | HuksKeySize | HUKS_RSA_KEY_SIZE_1024 = 1024 | 新增 |
| ohos.security.huks | HuksKeySize | HUKS_RSA_KEY_SIZE_768 = 768 | 新增 |
| ohos.security.huks | HuksKeySize | HUKS_RSA_KEY_SIZE_512 = 512 | 新增 |
| ohos.security.huks | HuksCipherMode | HUKS_MODE_GCM = 32 | 新增 |
| ohos.security.huks | HuksCipherMode | HUKS_MODE_CCM = 31 | 新增 |
| ohos.security.huks | HuksCipherMode | HUKS_MODE_OFB = 4 | 新增 |
| ohos.security.huks | HuksCipherMode | HUKS_MODE_CTR = 3 | 新增 |
| ohos.security.huks | HuksCipherMode | HUKS_MODE_CBC = 2 | 新增 |
| ohos.security.huks | HuksCipherMode | HUKS_MODE_ECB = 1 | 新增 |
| ohos.security.huks | HuksKeyPadding | HUKS_PADDING_PKCS7 = 5 | 新增 |
| ohos.security.huks | HuksKeyPadding | HUKS_PADDING_PKCS5 = 4 | 新增 |
| ohos.security.huks | HuksKeyPadding | HUKS_PADDING_PKCS1_V1_5 = 3 | 新增 |
| ohos.security.huks | HuksKeyPadding | HUKS_PADDING_PSS = 2 | 新增 |
| ohos.security.huks | HuksKeyPadding | HUKS_PADDING_OAEP = 1 | 新增 |
| ohos.security.huks | HuksKeyPadding | HUKS_PADDING_NONE = 0 | 新增 |
| ohos.security.huks | HuksKeyDigest | HUKS_DIGEST_SHA512 = 14 | 新增 |
| ohos.security.huks | HuksKeyDigest | HUKS_DIGEST_SHA384 = 13 | 新增 |
| ohos.security.huks | HuksKeyDigest | HUKS_DIGEST_SHA256 = 12 | 新增 |
| ohos.security.huks | HuksKeyDigest | HUKS_DIGEST_SHA224 = 11 | 新增 |
| ohos.security.huks | HuksKeyDigest | HUKS_DIGEST_SHA1 = 10 | 新增 |
| ohos.security.huks | HuksKeyDigest | HUKS_DIGEST_MD5 = 1 | 新增 |
| ohos.security.huks | HuksKeyDigest | HUKS_DIGEST_NONE = 0 | 新增 |
| ohos.security.huks | HuksKeyPurpose | HUKS_KEY_PURPOSE_AGREE = 256 | 新增 |
| ohos.security.huks | HuksKeyPurpose | HUKS_KEY_PURPOSE_MAC = 128 | 新增 |
| ohos.security.huks | HuksKeyPurpose | HUKS_KEY_PURPOSE_UNWRAP = 64 | 新增 |
| ohos.security.huks | HuksKeyPurpose | HUKS_KEY_PURPOSE_WRAP = 32 | 新增 |
| ohos.security.huks | HuksKeyPurpose | HUKS_KEY_PURPOSE_DERIVE = 16 | 新增 |
| ohos.security.huks | HuksKeyPurpose | HUKS_KEY_PURPOSE_VERIFY = 8 | 新增 |
| ohos.security.huks | HuksKeyPurpose | HUKS_KEY_PURPOSE_SIGN = 4 | 新增 |
| ohos.security.huks | HuksKeyPurpose | HUKS_KEY_PURPOSE_DECRYPT = 2 | 新增 |
| ohos.security.huks | HuksKeyPurpose | HUKS_KEY_PURPOSE_ENCRYPT = 1 | 新增 |
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_UNKNOWN_ERROR = -1000 | 新增 |
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_INTERNAL_ERROR = -999 | 新增 |
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_INVALID_OPERATION = -125 | 新增 |
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_INVALID_ITERATION = -124 | 新增 |
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_INVALID_SALT = -123 | 新增 |
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_INVALID_AE_TAG = -122 | 新增 |
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_INVALID_NONCE = -121 | 新增 |
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_INVALID_AAD = -120 | 新增 |
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_INVALID_IV = -119 | 新增 |
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_INVALID_SIGNATURE_SIZE = -118 | 新增 |
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_INVALID_DIGEST =  -117 | 新增 |
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_INVALID_MODE = -116 | 新增 |
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_INVALID_PURPOSE = -115 | 新增 |
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_INVALID_PADDING = -114 | 新增 |
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_INVALID_KEY_SIZE = -113 | 新增 |
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_INVALID_ALGORITHM = -112 | 新增 |
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_CHECK_GET_ITERATION_FAIL = -111 | 新增 |
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_CHECK_GET_SALT_FAIL = -110 | 新增 |
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_CHECK_GET_AE_TAG_FAIL = -109 | 新增 |
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_CHECK_GET_IV_FAIL = -108 | 新增 |
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_CHECK_GET_AAD_FAIL = -107 | 新增 |
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_CHECK_GET_NONCE_FAIL = -106 | 新增 |
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_CHECK_GET_MODE_FAIL = -105 | 新增 |
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_CHECK_GET_DIGEST_FAIL =  -104 | 新增 |
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_CHECK_GET_PURPOSE_FAIL = -103 | 新增 |
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_CHECK_GET_PADDING_FAIL = -102 | 新增 |
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_CHECK_GET_KEY_SIZE_FAIL = -101 | 新增 |
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_CHECK_GET_ALG_FAIL = -100 | 新增 |
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_VERIFICATION_FAILED = -38 | 新增 |
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_UPDATE_ROOT_KEY_MATERIAL_FAIL = -37 | 新增 |
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_NEW_ROOT_KEY_MATERIAL_EXIST = -36 | 新增 |
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_EFUSE_READ_FAIL = -35 | 新增 |
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_IPC_DLOPEN_FAIL = -34 | 新增 |
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_IPC_INIT_FAIL = -33 | 新增 |
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_COMMUNICATION_TIMEOUT = -32 | 新增 |
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_CRYPTO_ENGINE_ERROR = -31 | 新增 |
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_PARAM_NOT_EXIST = -30 | 新增 |
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_REQUEST_OVERFLOWS = -29 | 新增 |
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_IPC_MSG_FAIL = -28 | 新增 |
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_INVALID_KEY_FILE = -27 | 新增 |
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_MAKE_DIR_FAIL = -26 | 新增 |
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_CLOSE_FILE_FAIL = -25 | 新增 |
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_OPEN_FILE_FAIL = -24 | 新增 |
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_REMOVE_FILE_FAIL = -23 | 新增 |
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_WRITE_FILE_FAIL = -22 | 新增 |
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_MALLOC_FAIL = -21 | 新增 |
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_HASH_NOT_EQUAL = -20 | 新增 |
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_INVALID_KEY_INFO = -19 | 新增 |
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_INVALID_PRIVATE_KEY = -18 | 新增 |
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_INVALID_PUBLIC_KEY = -17 | 新增 |
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_READ_FILE_FAIL = -16 | 新增 |
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_FILE_SIZE_FAIL = -15 | 新增 |
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_NULL_POINTER = -14 | 新增 |
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_NOT_EXIST = -13 | 新增 |
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_ALREADY_EXISTS = -12 | 新增 |
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_HARDWARE_FAILURE = -11 | 新增 |
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_STORAGE_FAILURE = -10 | 新增 |
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_COMMUNICATION_FAILURE = -9 | 新增 |
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_INSUFFICIENT_MEMORY = -8 | 新增 |
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_BUFFER_TOO_SMALL = -7 | 新增 |
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_INSUFFICIENT_DATA = -6 | 新增 |
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_NO_PERMISSION = -5 | 新增 |
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_NOT_SUPPORTED = -4 | 新增 |
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_INVALID_ARGUMENT = -3 | 新增 |
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_BAD_STATE = -2 | 新增 |
| ohos.security.huks | HuksErrorCode | HUKS_FAILURE = -1 | 新增 |
| ohos.security.huks | HuksErrorCode | HUKS_SUCCESS = 0 | 新增 |
| ohos.security.huks | HuksResult | certChains?: Array\<string>; | 新增 |
| ohos.security.huks | HuksResult | properties?: Array\<HuksParam>; | 新增 |
| ohos.security.huks | HuksResult | outData?: Uint8Array; | 新增 |
| ohos.security.huks | HuksResult | errorCode: number; | 新增 |
| ohos.security.huks | HuksOptions | inData?: Uint8Array; | 新增 |
| ohos.security.huks | HuksOptions | properties?: Array\<HuksParam>; | 新增 |
| ohos.security.huks | HuksHandle | token?: Uint8Array; | 新增 |
| ohos.security.huks | HuksHandle | handle: number; | 新增 |
| ohos.security.huks | HuksHandle | errorCode: number; | 新增 |
| ohos.security.huks | HuksParam | value: boolean \| number \| bigint \| Uint8Array; | 新增 |
| ohos.security.huks | HuksParam | tag: HuksTag; | 新增 |
| ohos.security.huks | huks | getSdkVersion(options: HuksOptions) : string; | 新增 |
| ohos.security.huks | huks | abort(handle: number, options: HuksOptions, callback: AsyncCallback\<HuksResult>) : void;<br>abort(handle: number, options: HuksOptions) : Promise\<HuksResult>; | 新增 |
| ohos.security.huks | huks | finish(handle: number, options: HuksOptions, callback: AsyncCallback\<HuksResult>) : void;<br>finish(handle: number, options: HuksOptions) : Promise\<HuksResult>; | 新增 |
| ohos.security.huks | huks | update(handle: number, token?: Uint8Array, options: HuksOptions, callback: AsyncCallback\<HuksResult>) : void;<br>update(handle: number, token?: Uint8Array, options: HuksOptions) : Promise\<HuksResult>; | 新增 |
| ohos.security.huks | huks | init(keyAlias: string, options: HuksOptions, callback: AsyncCallback\<HuksHandle>) : void;<br>init(keyAlias: string, options: HuksOptions) : Promise\<HuksHandle>; | 新增 |
| ohos.security.huks | huks | isKeyExist(keyAlias: string, options: HuksOptions, callback: AsyncCallback\<boolean>) : void;<br>isKeyExist(keyAlias: string, options: HuksOptions) : Promise\<boolean>; | 新增 |
| ohos.security.huks | huks | getKeyProperties(keyAlias: string, options: HuksOptions, callback: AsyncCallback\<HuksResult>) : void;<br>getKeyProperties(keyAlias: string, options: HuksOptions) : Promise\<HuksResult>; | 新增 |
| ohos.security.huks | huks | exportKey(keyAlias: string, options: HuksOptions, callback: AsyncCallback\<HuksResult>) : void;<br>exportKey(keyAlias: string, options: HuksOptions) : Promise\<HuksResult>; | 新增 |
| ohos.security.huks | huks | importKey(keyAlias: string, options: HuksOptions, callback: AsyncCallback\<HuksResult>) : void;<br>importKey(keyAlias: string, options: HuksOptions) : Promise\<HuksResult>; | 新增 |
| ohos.security.huks | huks | deleteKey(keyAlias: string, options: HuksOptions, callback: AsyncCallback\<HuksResult>) : void;<br>deleteKey(keyAlias: string, options: HuksOptions) : Promise\<HuksResult>; | 新增 |
| ohos.security.huks | huks | generateKey(keyAlias: string, options: HuksOptions, callback: AsyncCallback\<HuksResult>) : void;<br>generateKey(keyAlias: string, options: HuksOptions) : Promise\<HuksResult>; | 新增 |
