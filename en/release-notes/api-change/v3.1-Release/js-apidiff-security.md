# JS API Changes of the Security Subsystem

The table below lists the APIs changes of the security subsystem in OpenHarmony 3.1 Release over OpenHarmony 3.0 LTS.

## API Changes

| Module| Class| Method/Attribute/Enumeration/Constant| Change Type|
|---|---|---|---|
| ohos.security.huks | HuksTag | HUKS_TAG_ASYMMETRIC_PRIVATE_KEY_DATA = HuksTagType.HUKS_TAG_TYPE_BYTES \| 20003 | Added|
| ohos.security.huks | HuksTag | HUKS_TAG_ASYMMETRIC_PUBLIC_KEY_DATA = HuksTagType.HUKS_TAG_TYPE_BYTES \| 20002 | Added|
| ohos.security.huks | HuksTag | HUKS_TAG_SYMMETRIC_KEY_DATA = HuksTagType.HUKS_TAG_TYPE_BYTES \| 20001 | Added|
| ohos.security.huks | HuksTag | HUKS_TAG_OS_PATCHLEVEL = HuksTagType.HUKS_TAG_TYPE_UINT \| 10102 | Added|
| ohos.security.huks | HuksTag | HUKS_TAG_OS_VERSION = HuksTagType.HUKS_TAG_TYPE_UINT \| 10101 | Added|
| ohos.security.huks | HuksTag | HUKS_TAG_IS_KEY_HANDLE = HuksTagType.HUKS_TAG_TYPE_ULONG \| 10010 | Added|
| ohos.security.huks | HuksTag | HUKS_TAG_AE_TAG = HuksTagType.HUKS_TAG_TYPE_BYTES \| 10009 | Added|
| ohos.security.huks | HuksTag | HUKS_TAG_PAYLOAD_LEN = HuksTagType.HUKS_TAG_TYPE_UINT \| 10008 | Added|
| ohos.security.huks | HuksTag | HUKS_TAG_KEY_VERSION = HuksTagType.HUKS_TAG_TYPE_UINT \| 10007 | Added|
| ohos.security.huks | HuksTag | HUKS_TAG_KEY = HuksTagType.HUKS_TAG_TYPE_BYTES \| 10006 | Added|
| ohos.security.huks | HuksTag | HUKS_TAG_CRYPTO_CTX = HuksTagType.HUKS_TAG_TYPE_ULONG \| 10005 | Added|
| ohos.security.huks | HuksTag | HUKS_TAG_USES_TIME = HuksTagType.HUKS_TAG_TYPE_UINT \| 10004 | Added|
| ohos.security.huks | HuksTag | HUKS_TAG_ACCESS_TIME = HuksTagType.HUKS_TAG_TYPE_UINT \| 10003 | Added|
| ohos.security.huks | HuksTag | HUKS_TAG_PACKAGE_NAME = HuksTagType.HUKS_TAG_TYPE_BYTES \| 10002 | Added|
| ohos.security.huks | HuksTag | HUKS_TAG_PROCESS_NAME = HuksTagType.HUKS_TAG_TYPE_BYTES \| 10001 | Added|
| ohos.security.huks | HuksTag | HUKS_TAG_KEY_DOMAIN = HuksTagType.HUKS_TAG_TYPE_UINT \| 1011 | Added|
| ohos.security.huks | HuksTag | HUKS_TAG_SECURE_KEY_UUID = HuksTagType.HUKS_TAG_TYPE_BYTES \| 1010 | Added|
| ohos.security.huks | HuksTag | HUKS_TAG_SECURE_KEY_ALIAS = HuksTagType.HUKS_TAG_TYPE_BOOL \| 1009 | Added|
| ohos.security.huks | HuksTag | HUKS_TAG_IS_ASYNCHRONIZED = HuksTagType.HUKS_TAG_TYPE_UINT \| 1008 | Added|
| ohos.security.huks | HuksTag | HUKS_TAG_KEY_FLAG = HuksTagType.HUKS_TAG_TYPE_UINT \| 1007 | Added|
| ohos.security.huks | HuksTag | HUKS_TAG_KEY_ROLE = HuksTagType.HUKS_TAG_TYPE_UINT \| 1006 | Added|
| ohos.security.huks | HuksTag | HUKS_TAG_KEY_AUTH_ID = HuksTagType.HUKS_TAG_TYPE_BYTES \| 1005 | Added|
| ohos.security.huks | HuksTag | HUKS_TAG_KEY_WRAP_TYPE = HuksTagType.HUKS_TAG_TYPE_UINT \| 1004 | Added|
| ohos.security.huks | HuksTag | HUKS_TAG_IS_ALLOWED_WRAP = HuksTagType.HUKS_TAG_TYPE_BOOL \| 1003 | Added|
| ohos.security.huks | HuksTag | HUKS_TAG_KEY_STORAGE_FLAG = HuksTagType.HUKS_TAG_TYPE_UINT \| 1002 | Added|
| ohos.security.huks | HuksTag | HUKS_TAG_IS_KEY_ALIAS = HuksTagType.HUKS_TAG_TYPE_BOOL \| 1001 | Added|
| ohos.security.huks | HuksTag | HUKS_TAG_ATTESTATION_ID_VERSION_INFO = HuksTagType.HUKS_TAG_TYPE_BYTES \| 515 | Added|
| ohos.security.huks | HuksTag | HUKS_TAG_ATTESTATION_ID_SEC_LEVEL_INFO = HuksTagType.HUKS_TAG_TYPE_BYTES \| 514 | Added|
| ohos.security.huks | HuksTag | HUKS_TAG_ATTESTATION_ID_UDID = HuksTagType.HUKS_TAG_TYPE_BYTES \| 513 | Added|
| ohos.security.huks | HuksTag | HUKS_TAG_ATTESTATION_ID_SOCID = HuksTagType.HUKS_TAG_TYPE_BYTES \| 512 | Added|
| ohos.security.huks | HuksTag | HUKS_TAG_ATTESTATION_ID_ALIAS = HuksTagType.HUKS_TAG_TYPE_BYTES \| 511 | Added|
| ohos.security.huks | HuksTag | HUKS_TAG_ATTESTATION_ID_MODEL = HuksTagType.HUKS_TAG_TYPE_BYTES \| 510 | Added|
| ohos.security.huks | HuksTag | HUKS_TAG_ATTESTATION_ID_MANUFACTURER = HuksTagType.HUKS_TAG_TYPE_BYTES \| 509 | Added|
| ohos.security.huks | HuksTag | HUKS_TAG_ATTESTATION_ID_MEID = HuksTagType.HUKS_TAG_TYPE_BYTES \| 508 | Added|
| ohos.security.huks | HuksTag | HUKS_TAG_ATTESTATION_ID_IMEI = HuksTagType.HUKS_TAG_TYPE_BYTES \| 507 | Added|
| ohos.security.huks | HuksTag | HUKS_TAG_ATTESTATION_ID_SERIAL = HuksTagType.HUKS_TAG_TYPE_BYTES \| 506 | Added|
| ohos.security.huks | HuksTag | HUKS_TAG_ATTESTATION_ID_PRODUCT = HuksTagType.HUKS_TAG_TYPE_BYTES \| 505 | Added|
| ohos.security.huks | HuksTag | HUKS_TAG_ATTESTATION_ID_DEVICE = HuksTagType.HUKS_TAG_TYPE_BYTES \| 504 | Added|
| ohos.security.huks | HuksTag | HUKS_TAG_ATTESTATION_ID_BRAND = HuksTagType.HUKS_TAG_TYPE_BYTES \| 503 | Added|
| ohos.security.huks | HuksTag | HUKS_TAG_ATTESTATION_APPLICATION_ID = HuksTagType.HUKS_TAG_TYPE_BYTES \| 502 | Added|
| ohos.security.huks | HuksTag | HUKS_TAG_ATTESTATION_CHALLENGE = HuksTagType.HUKS_TAG_TYPE_BYTES \| 501 | Added|
| ohos.security.huks | HuksTag | HUKS_TAG_AUTH_TOKEN = HuksTagType.HUKS_TAG_TYPE_BYTES \| 306 | Added|
| ohos.security.huks | HuksTag | HUKS_TAG_AUTH_TIMEOUT = HuksTagType.HUKS_TAG_TYPE_UINT \| 305 | Added|
| ohos.security.huks | HuksTag | HUKS_TAG_USER_AUTH_TYPE = HuksTagType.HUKS_TAG_TYPE_UINT \| 304 | Added|
| ohos.security.huks | HuksTag | HUKS_TAG_NO_AUTH_REQUIRED = HuksTagType.HUKS_TAG_TYPE_BOOL \| 303 | Added|
| ohos.security.huks | HuksTag | HUKS_TAG_USER_ID = HuksTagType.HUKS_TAG_TYPE_UINT \| 302 | Added|
| ohos.security.huks | HuksTag | HUKS_TAG_ALL_USERS = HuksTagType.HUKS_TAG_TYPE_BOOL \| 301 | Added|
| ohos.security.huks | HuksTag | HUKS_TAG_CREATION_DATETIME = HuksTagType.HUKS_TAG_TYPE_ULONG \| 204 | Added|
| ohos.security.huks | HuksTag | HUKS_TAG_USAGE_EXPIRE_DATETIME = HuksTagType.HUKS_TAG_TYPE_ULONG \| 203 | Added|
| ohos.security.huks | HuksTag | HUKS_TAG_ORIGINATION_EXPIRE_DATETIME = HuksTagType.HUKS_TAG_TYPE_ULONG \| 202 | Added|
| ohos.security.huks | HuksTag | HUKS_TAG_ACTIVE_DATETIME = HuksTagType.HUKS_TAG_TYPE_ULONG \| 201 | Added|
| ohos.security.huks | HuksTag | HUKS_TAG_DERIVE_KEY_SIZE = HuksTagType.HUKS_TAG_TYPE_UINT \| 24 | Added|
| ohos.security.huks | HuksTag | HUKS_TAG_KEY_ALIAS = HuksTagType.HUKS_TAG_TYPE_BYTES \| 23 | Added|
| ohos.security.huks | HuksTag | HUKS_TAG_AGREE_PUBLIC_KEY = HuksTagType.HUKS_TAG_TYPE_BYTES \| 22 | Added|
| ohos.security.huks | HuksTag | HUKS_TAG_AGREE_PRIVATE_KEY_ALIAS = HuksTagType.HUKS_TAG_TYPE_BYTES \| 21 | Added|
| ohos.security.huks | HuksTag | HUKS_TAG_AGREE_PUBLIC_KEY_IS_KEY_ALIAS = HuksTagType.HUKS_TAG_TYPE_BOOL \| 20 | Added|
| ohos.security.huks | HuksTag | HUKS_TAG_AGREE_ALG = HuksTagType.HUKS_TAG_TYPE_UINT \| 19 | Added|
| ohos.security.huks | HuksTag | HUKS_TAG_DERIVE_ALG = HuksTagType.HUKS_TAG_TYPE_UINT \| 18 | Added|
| ohos.security.huks | HuksTag | HUKS_TAG_DERIVE_FACTOR = HuksTagType.HUKS_TAG_TYPE_BYTES \| 17 | Added|
| ohos.security.huks | HuksTag | HUKS_TAG_DERIVE_MAIN_KEY = HuksTagType.HUKS_TAG_TYPE_BYTES \| 16 | Added|
| ohos.security.huks | HuksTag | HUKS_TAG_KEY_GENERATE_TYPE = HuksTagType.HUKS_TAG_TYPE_UINT \| 15 | Added|
| ohos.security.huks | HuksTag | HUKS_TAG_ITERATION = HuksTagType.HUKS_TAG_TYPE_UINT \| 14 | Added|
| ohos.security.huks | HuksTag | HUKS_TAG_PWD = HuksTagType.HUKS_TAG_TYPE_BYTES \| 13 | Added|
| ohos.security.huks | HuksTag | HUKS_TAG_SALT = HuksTagType.HUKS_TAG_TYPE_BYTES \| 12 | Added|
| ohos.security.huks | HuksTag | HUKS_TAG_INFO = HuksTagType.HUKS_TAG_TYPE_BYTES \| 11 | Added|
| ohos.security.huks | HuksTag | HUKS_TAG_IV = HuksTagType.HUKS_TAG_TYPE_BYTES \| 10 | Added|
| ohos.security.huks | HuksTag | HUKS_TAG_NONCE = HuksTagType.HUKS_TAG_TYPE_BYTES \| 9 | Added|
| ohos.security.huks | HuksTag | HUKS_TAG_ASSOCIATED_DATA = HuksTagType.HUKS_TAG_TYPE_BYTES \| 8 | Added|
| ohos.security.huks | HuksTag | HUKS_TAG_KEY_TYPE = HuksTagType.HUKS_TAG_TYPE_UINT \| 7 | Added|
| ohos.security.huks | HuksTag | HUKS_TAG_BLOCK_MODE = HuksTagType.HUKS_TAG_TYPE_UINT \| 6 | Added|
| ohos.security.huks | HuksTag | HUKS_TAG_PADDING = HuksTagType.HUKS_TAG_TYPE_UINT \| 5 | Added|
| ohos.security.huks | HuksTag | HUKS_TAG_DIGEST = HuksTagType.HUKS_TAG_TYPE_UINT \| 4 | Added|
| ohos.security.huks | HuksTag | HUKS_TAG_KEY_SIZE = HuksTagType.HUKS_TAG_TYPE_UINT \| 3 | Added|
| ohos.security.huks | HuksTag | HUKS_TAG_PURPOSE = HuksTagType.HUKS_TAG_TYPE_UINT \| 2 | Added|
| ohos.security.huks | HuksTag | HUKS_TAG_ALGORITHM = HuksTagType.HUKS_TAG_TYPE_UINT \| 1 | Added|
| ohos.security.huks | HuksTag | HUKS_TAG_INVALID = HuksTagType.HUKS_TAG_TYPE_INVALID \| 0 | Added|
| ohos.security.huks | HuksTagType | HUKS_TAG_TYPE_BYTES = 5 \<\< 28 | Added|
| ohos.security.huks | HuksTagType | HUKS_TAG_TYPE_BOOL = 4 \<\< 28 | Added|
| ohos.security.huks | HuksTagType | HUKS_TAG_TYPE_ULONG = 3 \<\< 28 | Added|
| ohos.security.huks | HuksTagType | HUKS_TAG_TYPE_UINT = 2 \<\< 28 | Added|
| ohos.security.huks | HuksTagType | HUKS_TAG_TYPE_INT = 1 \<\< 28 | Added|
| ohos.security.huks | HuksTagType | HUKS_TAG_TYPE_INVALID = 0 \<\< 28 | Added|
| ohos.security.huks | HuksSendType | HUKS_SEND_TYPE_SYNC = 1 | Added|
| ohos.security.huks | HuksSendType | HUKS_SEND_TYPE_ASYNC = 0 | Added|
| ohos.security.huks | HuksKeyStorageType | HUKS_STORAGE_PERSISTENT = 1 | Added|
| ohos.security.huks | HuksKeyStorageType | HUKS_STORAGE_TEMP = 0 | Added|
| ohos.security.huks | HuksKeyFlag | HUKS_KEY_FLAG_DERIVE_KEY = 4 | Added|
| ohos.security.huks | HuksKeyFlag | HUKS_KEY_FLAG_AGREE_KEY = 3 | Added|
| ohos.security.huks | HuksKeyFlag | HUKS_KEY_FLAG_GENERATE_KEY = 2 | Added|
| ohos.security.huks | HuksKeyFlag | HUKS_KEY_FLAG_IMPORT_KEY = 1 | Added|
| ohos.security.huks | HuksKeyGenerateType | HUKS_KEY_GENERATE_TYPE_AGREE = 2 | Added|
| ohos.security.huks | HuksKeyGenerateType | HUKS_KEY_GENERATE_TYPE_DERIVE = 1 | Added|
| ohos.security.huks | HuksKeyGenerateType | HUKS_KEY_GENERATE_TYPE_DEFAULT = 0 | Added|
| ohos.security.huks | HuksKeyAlg | HUKS_ALG_DH = 103 | Added|
| ohos.security.huks | HuksKeyAlg | HUKS_ALG_ED25519 = 102 | Added|
| ohos.security.huks | HuksKeyAlg | HUKS_ALG_X25519 = 101 | Added|
| ohos.security.huks | HuksKeyAlg | HUKS_ALG_ECDH = 100 | Added|
| ohos.security.huks | HuksKeyAlg | HUKS_ALG_PBKDF2 = 52 | Added|
| ohos.security.huks | HuksKeyAlg | HUKS_ALG_HKDF = 51 | Added|
| ohos.security.huks | HuksKeyAlg | HUKS_ALG_HMAC = 50 | Added|
| ohos.security.huks | HuksKeyAlg | HUKS_ALG_AES = 20 | Added|
| ohos.security.huks | HuksKeyAlg | HUKS_ALG_DSA = 3 | Added|
| ohos.security.huks | HuksKeyAlg | HUKS_ALG_ECC = 2 | Added|
| ohos.security.huks | HuksKeyAlg | HUKS_ALG_RSA = 1 | Added|
| ohos.security.huks | HuksKeySize | HUKS_DH_KEY_SIZE_4096 = 4096 | Added|
| ohos.security.huks | HuksKeySize | HUKS_DH_KEY_SIZE_3072 = 3072 | Added|
| ohos.security.huks | HuksKeySize | HUKS_DH_KEY_SIZE_2048 = 2048 | Added|
| ohos.security.huks | HuksKeySize | HUKS_CURVE25519_KEY_SIZE_256 = 256 | Added|
| ohos.security.huks | HuksKeySize | HUKS_AES_KEY_SIZE_512 = 512 | Added|
| ohos.security.huks | HuksKeySize | HUKS_AES_KEY_SIZE_256 = 256 | Added|
| ohos.security.huks | HuksKeySize | HUKS_AES_KEY_SIZE_192 = 192 | Added|
| ohos.security.huks | HuksKeySize | HUKS_AES_KEY_SIZE_128 = 128 | Added|
| ohos.security.huks | HuksKeySize | HUKS_ECC_KEY_SIZE_521 = 521 | Added|
| ohos.security.huks | HuksKeySize | HUKS_ECC_KEY_SIZE_384 = 384 | Added|
| ohos.security.huks | HuksKeySize | HUKS_ECC_KEY_SIZE_256 = 256 | Added|
| ohos.security.huks | HuksKeySize | HUKS_ECC_KEY_SIZE_224 = 224 | Added|
| ohos.security.huks | HuksKeySize | HUKS_RSA_KEY_SIZE_4096 = 4096 | Added|
| ohos.security.huks | HuksKeySize | HUKS_RSA_KEY_SIZE_3072 = 3072 | Added|
| ohos.security.huks | HuksKeySize | HUKS_RSA_KEY_SIZE_2048 = 2048 | Added|
| ohos.security.huks | HuksKeySize | HUKS_RSA_KEY_SIZE_1024 = 1024 | Added|
| ohos.security.huks | HuksKeySize | HUKS_RSA_KEY_SIZE_768 = 768 | Added|
| ohos.security.huks | HuksKeySize | HUKS_RSA_KEY_SIZE_512 = 512 | Added|
| ohos.security.huks | HuksCipherMode | HUKS_MODE_GCM = 32 | Added|
| ohos.security.huks | HuksCipherMode | HUKS_MODE_CCM = 31 | Added|
| ohos.security.huks | HuksCipherMode | HUKS_MODE_OFB = 4 | Added|
| ohos.security.huks | HuksCipherMode | HUKS_MODE_CTR = 3 | Added|
| ohos.security.huks | HuksCipherMode | HUKS_MODE_CBC = 2 | Added|
| ohos.security.huks | HuksCipherMode | HUKS_MODE_ECB = 1 | Added|
| ohos.security.huks | HuksKeyPadding | HUKS_PADDING_PKCS7 = 5 | Added|
| ohos.security.huks | HuksKeyPadding | HUKS_PADDING_PKCS5 = 4 | Added|
| ohos.security.huks | HuksKeyPadding | HUKS_PADDING_PKCS1_V1_5 = 3 | Added|
| ohos.security.huks | HuksKeyPadding | HUKS_PADDING_PSS = 2 | Added|
| ohos.security.huks | HuksKeyPadding | HUKS_PADDING_OAEP = 1 | Added|
| ohos.security.huks | HuksKeyPadding | HUKS_PADDING_NONE = 0 | Added|
| ohos.security.huks | HuksKeyDigest | HUKS_DIGEST_SHA512 = 14 | Added|
| ohos.security.huks | HuksKeyDigest | HUKS_DIGEST_SHA384 = 13 | Added|
| ohos.security.huks | HuksKeyDigest | HUKS_DIGEST_SHA256 = 12 | Added|
| ohos.security.huks | HuksKeyDigest | HUKS_DIGEST_SHA224 = 11 | Added|
| ohos.security.huks | HuksKeyDigest | HUKS_DIGEST_SHA1 = 10 | Added|
| ohos.security.huks | HuksKeyDigest | HUKS_DIGEST_MD5 = 1 | Added|
| ohos.security.huks | HuksKeyDigest | HUKS_DIGEST_NONE = 0 | Added|
| ohos.security.huks | HuksKeyPurpose | HUKS_KEY_PURPOSE_AGREE = 256 | Added|
| ohos.security.huks | HuksKeyPurpose | HUKS_KEY_PURPOSE_MAC = 128 | Added|
| ohos.security.huks | HuksKeyPurpose | HUKS_KEY_PURPOSE_UNWRAP = 64 | Added|
| ohos.security.huks | HuksKeyPurpose | HUKS_KEY_PURPOSE_WRAP = 32 | Added|
| ohos.security.huks | HuksKeyPurpose | HUKS_KEY_PURPOSE_DERIVE = 16 | Added|
| ohos.security.huks | HuksKeyPurpose | HUKS_KEY_PURPOSE_VERIFY = 8 | Added|
| ohos.security.huks | HuksKeyPurpose | HUKS_KEY_PURPOSE_SIGN = 4 | Added|
| ohos.security.huks | HuksKeyPurpose | HUKS_KEY_PURPOSE_DECRYPT = 2 | Added|
| ohos.security.huks | HuksKeyPurpose | HUKS_KEY_PURPOSE_ENCRYPT = 1 | Added|
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_UNKNOWN_ERROR = -1000 | Added|
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_INTERNAL_ERROR = -999 | Added|
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_INVALID_OPERATION = -125 | Added|
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_INVALID_ITERATION = -124 | Added|
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_INVALID_SALT = -123 | Added|
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_INVALID_AE_TAG = -122 | Added|
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_INVALID_NONCE = -121 | Added|
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_INVALID_AAD = -120 | Added|
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_INVALID_IV = -119 | Added|
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_INVALID_SIGNATURE_SIZE = -118 | Added|
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_INVALID_DIGEST =  -117 | Added|
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_INVALID_MODE = -116 | Added|
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_INVALID_PURPOSE = -115 | Added|
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_INVALID_PADDING = -114 | Added|
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_INVALID_KEY_SIZE = -113 | Added|
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_INVALID_ALGORITHM = -112 | Added|
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_CHECK_GET_ITERATION_FAIL = -111 | Added|
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_CHECK_GET_SALT_FAIL = -110 | Added|
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_CHECK_GET_AE_TAG_FAIL = -109 | Added|
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_CHECK_GET_IV_FAIL = -108 | Added|
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_CHECK_GET_AAD_FAIL = -107 | Added|
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_CHECK_GET_NONCE_FAIL = -106 | Added|
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_CHECK_GET_MODE_FAIL = -105 | Added|
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_CHECK_GET_DIGEST_FAIL =  -104 | Added|
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_CHECK_GET_PURPOSE_FAIL = -103 | Added|
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_CHECK_GET_PADDING_FAIL = -102 | Added|
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_CHECK_GET_KEY_SIZE_FAIL = -101 | Added|
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_CHECK_GET_ALG_FAIL = -100 | Added|
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_VERIFICATION_FAILED = -38 | Added|
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_UPDATE_ROOT_KEY_MATERIAL_FAIL = -37 | Added|
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_NEW_ROOT_KEY_MATERIAL_EXIST = -36 | Added|
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_EFUSE_READ_FAIL = -35 | Added|
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_IPC_DLOPEN_FAIL = -34 | Added|
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_IPC_INIT_FAIL = -33 | Added|
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_COMMUNICATION_TIMEOUT = -32 | Added|
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_CRYPTO_ENGINE_ERROR = -31 | Added|
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_PARAM_NOT_EXIST = -30 | Added|
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_REQUEST_OVERFLOWS = -29 | Added|
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_IPC_MSG_FAIL = -28 | Added|
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_INVALID_KEY_FILE = -27 | Added|
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_MAKE_DIR_FAIL = -26 | Added|
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_CLOSE_FILE_FAIL = -25 | Added|
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_OPEN_FILE_FAIL = -24 | Added|
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_REMOVE_FILE_FAIL = -23 | Added|
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_WRITE_FILE_FAIL = -22 | Added|
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_MALLOC_FAIL = -21 | Added|
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_HASH_NOT_EQUAL = -20 | Added|
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_INVALID_KEY_INFO = -19 | Added|
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_INVALID_PRIVATE_KEY = -18 | Added|
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_INVALID_PUBLIC_KEY = -17 | Added|
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_READ_FILE_FAIL = -16 | Added|
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_FILE_SIZE_FAIL = -15 | Added|
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_NULL_POINTER = -14 | Added|
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_NOT_EXIST = -13 | Added|
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_ALREADY_EXISTS = -12 | Added|
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_HARDWARE_FAILURE = -11 | Added|
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_STORAGE_FAILURE = -10 | Added|
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_COMMUNICATION_FAILURE = -9 | Added|
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_INSUFFICIENT_MEMORY = -8 | Added|
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_BUFFER_TOO_SMALL = -7 | Added|
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_INSUFFICIENT_DATA = -6 | Added|
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_NO_PERMISSION = -5 | Added|
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_NOT_SUPPORTED = -4 | Added|
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_INVALID_ARGUMENT = -3 | Added|
| ohos.security.huks | HuksErrorCode | HUKS_ERROR_BAD_STATE = -2 | Added|
| ohos.security.huks | HuksErrorCode | HUKS_FAILURE = -1 | Added|
| ohos.security.huks | HuksErrorCode | HUKS_SUCCESS = 0 | Added|
| ohos.security.huks | HuksResult | certChains?: Array\<string>; | Added|
| ohos.security.huks | HuksResult | properties?: Array\<HuksParam>; | Added|
| ohos.security.huks | HuksResult | outData?: Uint8Array; | Added|
| ohos.security.huks | HuksResult | errorCode: number; | Added|
| ohos.security.huks | HuksOptions | inData?: Uint8Array; | Added|
| ohos.security.huks | HuksOptions | properties?: Array\<HuksParam>; | Added|
| ohos.security.huks | HuksHandle | token?: Uint8Array; | Added|
| ohos.security.huks | HuksHandle | handle: number; | Added|
| ohos.security.huks | HuksHandle | errorCode: number; | Added|
| ohos.security.huks | HuksParam | value: boolean \| number \| bigint \| Uint8Array; | Added|
| ohos.security.huks | HuksParam | tag: HuksTag; | Added|
| ohos.security.huks | huks | getSdkVersion(options: HuksOptions) : string; | Added|
| ohos.security.huks | huks | abort(handle: number, options: HuksOptions, callback: AsyncCallback\<HuksResult>) : void;<br>abort(handle: number, options: HuksOptions) : Promise\<HuksResult>; | Added|
| ohos.security.huks | huks | finish(handle: number, options: HuksOptions, callback: AsyncCallback\<HuksResult>) : void;<br>finish(handle: number, options: HuksOptions) : Promise\<HuksResult>; | Added|
| ohos.security.huks | huks | update(handle: number, token?: Uint8Array, options: HuksOptions, callback: AsyncCallback\<HuksResult>) : void;<br>update(handle: number, token?: Uint8Array, options: HuksOptions) : Promise\<HuksResult>; | Added|
| ohos.security.huks | huks | init(keyAlias: string, options: HuksOptions, callback: AsyncCallback\<HuksHandle>) : void;<br>init(keyAlias: string, options: HuksOptions) : Promise\<HuksHandle>; | Added|
| ohos.security.huks | huks | isKeyExist(keyAlias: string, options: HuksOptions, callback: AsyncCallback\<boolean>) : void;<br>isKeyExist(keyAlias: string, options: HuksOptions) : Promise\<boolean>; | Added|
| ohos.security.huks | huks | getKeyProperties(keyAlias: string, options: HuksOptions, callback: AsyncCallback\<HuksResult>) : void;<br>getKeyProperties(keyAlias: string, options: HuksOptions) : Promise\<HuksResult>; | Added|
| ohos.security.huks | huks | exportKey(keyAlias: string, options: HuksOptions, callback: AsyncCallback\<HuksResult>) : void;<br>exportKey(keyAlias: string, options: HuksOptions) : Promise\<HuksResult>; | Added|
| ohos.security.huks | huks | importKey(keyAlias: string, options: HuksOptions, callback: AsyncCallback\<HuksResult>) : void;<br>importKey(keyAlias: string, options: HuksOptions) : Promise\<HuksResult>; | Added|
| ohos.security.huks | huks | deleteKey(keyAlias: string, options: HuksOptions, callback: AsyncCallback\<HuksResult>) : void;<br>deleteKey(keyAlias: string, options: HuksOptions) : Promise\<HuksResult>; | Added|
| ohos.security.huks | huks | generateKey(keyAlias: string, options: HuksOptions, callback: AsyncCallback\<HuksResult>) : void;<br>generateKey(keyAlias: string, options: HuksOptions) : Promise\<HuksResult>; | Added|
