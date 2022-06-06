# 通用密钥库系统

> **说明**
>
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

向应用提供密钥库能力，包括密钥管理及密钥的密码学操作等功能。
HUKS所管理的密钥可以由应用导入或者由应用调用HUKS接口生成。

## 导入模块

```js
import huks from '@ohos.security.huks'
```
## HuksErrorCode

表示错误码的枚举。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Security.Huks。

| 名称                       | 值    | 说明 |
| -------------------------- | ----- | ---- |
| HUKS_SUCCESS | 0     |表示成功。|
| HUKS_FAILURE | -1    |表示失败。|
| HUKS_ERROR_BAD_STATE | -2    |表示错误的状态。|
| HUKS_ERROR_INVALID_ARGUMENT | -3    |表示无效的数据。|
| HUKS_ERROR_NOT_SUPPORTED | -4    |表示不支持。|
| HUKS_ERROR_NO_PERMISSION | -5    |表示没有许可。|
| HUKS_ERROR_INSUFFICIENT_DATA | -6    |表示数据不足。|
| HUKS_ERROR_BUFFER_TOO_SMALL | -7    |表示缓冲区太小。|
| HUKS_ERROR_INSUFFICIENT_MEMORY | -8    |表示内存不足。|
| HUKS_ERROR_COMMUNICATION_FAILURE | -9    |表示通讯失败。|
| HUKS_ERROR_STORAGE_FAILURE | -10   |表示存储故障。|
| HUKS_ERROR_HARDWARE_FAILURE | -11   |表示硬件故障。|
| HUKS_ERROR_ALREADY_EXISTS | -12   |表示已经存在。|
| HUKS_ERROR_NOT_EXIST | -13   |表示不存在。|
| HUKS_ERROR_NULL_POINTER | -14   |表示空指针。|
| HUKS_ERROR_FILE_SIZE_FAIL | -15   |表示文件大小失败。|
| HUKS_ERROR_READ_FILE_FAIL | -16   |表示读取文件失败。|
| HUKS_ERROR_INVALID_PUBLIC_KEY | -17   |表示无效的公钥。|
| HUKS_ERROR_INVALID_PRIVATE_KEY | -18   |表示无效的私钥。|
| HUKS_ERROR_INVALID_KEY_INFO | -19   |表示无效的密钥信息。|
| HUKS_ERROR_HASH_NOT_EQUAL | -20   |表示哈希不相等。|
| HUKS_ERROR_MALLOC_FAIL | -21   |表示MALLOC 失败。|
| HUKS_ERROR_WRITE_FILE_FAIL | -22   |表示写文件失败。|
| HUKS_ERROR_REMOVE_FILE_FAIL | -23   |表示删除文件失败。|
| HUKS_ERROR_OPEN_FILE_FAIL | -24   |表示打开文件失败。|
| HUKS_ERROR_CLOSE_FILE_FAIL | -25   |表示关闭文件失败。|
| HUKS_ERROR_MAKE_DIR_FAIL | -26   |表示创建目录失败。|
| HUKS_ERROR_INVALID_KEY_FILE | -27   |表示无效的密钥文件。|
| HUKS_ERROR_IPC_MSG_FAIL | -28   |表示IPC 信息失败。|
| HUKS_ERROR_REQUEST_OVERFLOWS | -29   |表示请求溢出。|
| HUKS_ERROR_PARAM_NOT_EXIST | -30   |表示参数不存在。|
| HUKS_ERROR_CRYPTO_ENGINE_ERROR | -31   |表示CRYPTO ENGINE错误。|
| HUKS_ERROR_COMMUNICATION_TIMEOUT | -32   |表示通讯超时。|
| HUKS_ERROR_IPC_INIT_FAIL | -33   |表示IPC 初始化失败。|
| HUKS_ERROR_IPC_DLOPEN_FAIL | -34   |表示IPC DLOPEN 失败。|
| HUKS_ERROR_EFUSE_READ_FAIL | -35   |表示EFUSE 读取失败。|
| HUKS_ERROR_NEW_ROOT_KEY_MATERIAL_EXIST | -36   |表示存在新的根密钥材料。|
| HUKS_ERROR_UPDATE_ROOT_KEY_MATERIAL_FAIL | -37   |表示更新根密钥材料失败。|
| HUKS_ERROR_VERIFICATION_FAILED | -38   |表示验证证书链失败。|
| HUKS_ERROR_CHECK_GET_ALG_FAIL | -100  |表示检查获取 ALG 失败。|
| HUKS_ERROR_CHECK_GET_KEY_SIZE_FAIL | -101  |表示检查获取密钥大小失败。|
| HUKS_ERROR_CHECK_GET_PADDING_FAIL | -102  |表示检查获取填充失败。|
| HUKS_ERROR_CHECK_GET_PURPOSE_FAIL | -103  |表示检查获取目的失败。|
| HUKS_ERROR_CHECK_GET_DIGEST_FAIL | -104  |表示检查获取摘要失败。|
| HUKS_ERROR_CHECK_GET_MODE_FAIL | -105  |表示检查获取模式失败。|
| HUKS_ERROR_CHECK_GET_NONCE_FAIL | -106  |表示检查获取随机数失败。|
| HUKS_ERROR_CHECK_GET_AAD_FAIL | -107  |表示检查获取 AAD 失败。|
| HUKS_ERROR_CHECK_GET_IV_FAIL | -108  |表示检查 GET IV 失败。|
| HUKS_ERROR_CHECK_GET_AE_TAG_FAIL | -109  |表示检查获取 AE 标记失败。|
| HUKS_ERROR_CHECK_GET_SALT_FAIL | -110  |表示检查获取SALT失败。|
| HUKS_ERROR_CHECK_GET_ITERATION_FAIL | -111  |表示检查获取迭代失败。|
| HUKS_ERROR_INVALID_ALGORITHM | -112  |表示无效的算法。|
| HUKS_ERROR_INVALID_KEY_SIZE | -113  |表示无效的密钥大小。|
| HUKS_ERROR_INVALID_PADDING | -114  |表示无效的填充。|
| HUKS_ERROR_INVALID_PURPOSE | -115  |表示无效的目的。|
| HUKS_ERROR_INVALID_MODE | -116  |表示无效模式。|
| HUKS_ERROR_INVALID_DIGEST | -117  |表示无效的摘要。|
| HUKS_ERROR_INVALID_SIGNATURE_SIZE | -118  |表示签名大小无效。|
| HUKS_ERROR_INVALID_IV | -119  |表示无效的 IV。|
| HUKS_ERROR_INVALID_AAD | -120  |表示无效的 AAD。|
| HUKS_ERROR_INVALID_NONCE | -121  |表示无效的随机数。|
| HUKS_ERROR_INVALID_AE_TAG | -122  |表示无效的 AE 标签。|
| HUKS_ERROR_INVALID_SALT | -123  |表示无效SALT。|
| HUKS_ERROR_INVALID_ITERATION | -124  |表示无效的迭代。|
| HUKS_ERROR_INVALID_OPERATION | -125  |表示无效操作。|
| HUKS_ERROR_INVALID_WRAPPED_FORMAT<sup>9+</sup> | -126 |表示导入加密密钥时，密钥格式错误。|
| HUKS_ERROR_INVALID_USAGE_OF_KEY<sup>9+</sup> | -127 |表示导入加密密钥时，密钥用途错误。|
| HUKS_ERROR_INTERNAL_ERROR | -999  |表示内部错误。|
| HUKS_ERROR_UNKNOWN_ERROR | -1000 |表示未知错误。|


## HuksKeyPurpose

表示密钥用途。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Security.Huks。

| 名称                     | 值   | 说明                             |
| ------------------------ | ---- | -------------------------------- |
| HUKS_KEY_PURPOSE_ENCRYPT | 1    | 表示密钥用于对明文进行加密操作。 |
| HUKS_KEY_PURPOSE_DECRYPT | 2    | 表示密钥用于对密文进行解密操作。 |
| HUKS_KEY_PURPOSE_SIGN    | 4    | 表示密钥用于对数据进行签名。     |
| HUKS_KEY_PURPOSE_VERIFY  | 8    | 表示密钥用于验证签名后的数据。   |
| HUKS_KEY_PURPOSE_DERIVE  | 16   | 表示密钥用于派生密钥。           |
| HUKS_KEY_PURPOSE_WRAP    | 32   | 表示密钥用于加密导入。           |
| HUKS_KEY_PURPOSE_UNWRAP  | 64   | 表示密钥加密导出。               |
| HUKS_KEY_PURPOSE_MAC     | 128  | 表示密钥用于生成mac消息验证码。  |
| HUKS_KEY_PURPOSE_AGREE   | 256  | 表示密钥用于进行密钥协商。       |

## HuksKeyDigest

表示摘要算法。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Security.Huks。

| 名称                   | 值   | 说明                                     |
| ---------------------- | ---- | ---------------------------------------- |
| HUKS_DIGEST_NONE       | 0   | 表示无摘要算法。 |
| HUKS_DIGEST_MD5        | 1    | 表示MD5摘要算法。 |
| HUKS_DIGEST_SM3<sup>9+</sup> | 2 | 表示SM3摘要算法。 |
| HUKS_DIGEST_SHA1       | 10   | 表示SHA1摘要算法。 |
| HUKS_DIGEST_SHA224 | 11   | 表示SHA224摘要算法。 |
| HUKS_DIGEST_SHA256 | 12  | 表示SHA256摘要算法。 |
| HUKS_DIGEST_SHA384  | 13  | 表示SHA384摘要算法。 |
| HUKS_DIGEST_SHA512 | 14  | 表示SHA512摘要算法。 |

## HuksKeyPadding

表示补齐算法。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Security.Huks。

| 名称                   | 值   | 说明                                     |
| ---------------------- | ---- | ---------------------------------------- |
| HUKS_PADDING_NONE | 0    | 表示不使用补齐算法。 |
| HUKS_PADDING_OAEP | 1    | 表示使用OAEP补齐算法。 |
| HUKS_PADDING_PSS | 2    | 表示使用PSS补齐算法。 |
| HUKS_PADDING_PKCS1_V1_5 | 3    | 表示使用PKCS1_V1_5补齐算法。 |
| HUKS_PADDING_PKCS5 | 4   | 表示使用PKCS5补齐算法。 |
| HUKS_PADDING_PKCS7 | 5   | 表示使用PKCS7补齐算法。 |

## HuksCipherMode

表示加密模式。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Security.Huks。

| 名称          | 值   | 说明                  |
| ------------- | ---- | --------------------- |
| HUKS_MODE_ECB | 1    | 表示使用ECB加密模式。 |
| HUKS_MODE_CBC | 2    | 表示使用CBC加密模式。 |
| HUKS_MODE_CTR | 3    | 表示使用CTR加密模式。 |
| HUKS_MODE_OFB | 4    | 表示使用OFB加密模式。 |
| HUKS_MODE_CCM | 31   | 表示使用CCM加密模式。 |
| HUKS_MODE_GCM | 32   | 表示使用GCM加密模式。 |

## HuksKeySize

表示密钥长度。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Security.Huks。

| 名称                               | 值   | 说明                                       |
| ---------------------------------- | ---- | ------------------------------------------ |
| HUKS_RSA_KEY_SIZE_512              | 512  | 表示使用RSA算法的密钥长度为512bit。        |
| HUKS_RSA_KEY_SIZE_768              | 768  | 表示使用RSA算法的密钥长度为768bit。        |
| HUKS_RSA_KEY_SIZE_1024             | 1024 | 表示使用RSA算法的密钥长度为1024bit。       |
| HUKS_RSA_KEY_SIZE_2048             | 2048 | 表示使用RSA算法的密钥长度为2048bit。       |
| HUKS_RSA_KEY_SIZE_3072             | 3072 | 表示使用RSA算法的密钥长度为3072bit。       |
| HUKS_RSA_KEY_SIZE_4096             | 4096 | 表示使用RSA算法的密钥长度为4096bit。       |
| HUKS_ECC_KEY_SIZE_224              | 224  | 表示使用ECC算法的密钥长度为224bit。        |
| HUKS_ECC_KEY_SIZE_256              | 256  | 表示使用ECC算法的密钥长度为256bit。        |
| HUKS_ECC_KEY_SIZE_384              | 384  | 表示使用ECC算法的密钥长度为384bit。        |
| HUKS_ECC_KEY_SIZE_521              | 521  | 表示使用ECC算法的密钥长度为521bit。        |
| HUKS_AES_KEY_SIZE_128              | 128  | 表示使用AES算法的密钥长度为128bit。        |
| HUKS_AES_KEY_SIZE_192              | 196  | 表示使用AES算法的密钥长度为196bit。        |
| HUKS_AES_KEY_SIZE_256              | 256  | 表示使用AES算法的密钥长度为256bit。        |
| HUKS_AES_KEY_SIZE_512              | 512  | 表示使用AES算法的密钥长度为512bit。        |
| HUKS_CURVE25519_KEY_SIZE_256       | 256  | 表示使用CURVE25519算法的密钥长度为256bit。 |
| HUKS_DH_KEY_SIZE_2048              | 2048 | 表示使用DH算法的密钥长度为2048bit。        |
| HUKS_DH_KEY_SIZE_3072              | 3072 | 表示使用DH算法的密钥长度为3072bit。        |
| HUKS_DH_KEY_SIZE_4096              | 4096 | 表示使用DH算法的密钥长度为4096bit。        |
| HUKS_SM2_KEY_SIZE_256<sup>9+</sup> | 256  | 表示SM2算法的密钥长度为256bit。            |
| HUKS_SM4_KEY_SIZE_128<sup>9+</sup> | 128  | 表示SM4算法的密钥长度为128bit。            |

## HuksKeyAlg

表示密钥使用的算法。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Security.Huks。

| 名称                      | 值   | 说明                  |
| ------------------------- | ---- | --------------------- |
| HUKS_ALG_RSA              | 1    | 表示使用RSA算法。     |
| HUKS_ALG_ECC              | 2    | 表示使用ECC算法。     |
| HUKS_ALG_DSA              | 3    | 表示使用DSA算法。     |
| HUKS_ALG_AES              | 20   | 表示使用AES算法。     |
| HUKS_ALG_HMAC             | 50   | 表示使用HMAC算法。    |
| HUKS_ALG_HKDF             | 51   | 表示使用HKDF算法。    |
| HUKS_ALG_PBKDF2           | 52   | 表示使用PBKDF2算法。  |
| HUKS_ALG_ECDH             | 100  | 表示使用ECDH算法。    |
| HUKS_ALG_X25519           | 101  | 表示使用X25519算法。  |
| HUKS_ALG_ED25519          | 102  | 表示使用ED25519算法。 |
| HUKS_ALG_DH               | 103  | 表示使用DH算法。      |
| HUKS_ALG_SM2<sup>9+</sup> | 150  | 表示使用SM2算法。     |
| HUKS_ALG_SM3<sup>9+</sup> | 151  | 表示使用SM3算法。     |
| HUKS_ALG_SM4<sup>9+</sup> | 152  | 表示使用SM4算法。     |

## HuksKeyGenerateType

表示生成密钥的类型。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Security.Huks。

| 名称                           | 值   | 说明             |
| ------------------------------ | ---- | ---------------- |
| HUKS_KEY_GENERATE_TYPE_DEFAULT | 0    | 默认生成的密钥。 |
| HUKS_KEY_GENERATE_TYPE_DERIVE  | 1    | 派生生成的密钥。 |
| HUKS_KEY_GENERATE_TYPE_AGREE   | 2    | 协商生成的密钥。 |

## HuksKeyFlag

表示密钥的产生方式。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Security.Huks。

| 名称                       | 值   | 说明                                 |
| -------------------------- | ---- | ------------------------------------ |
| HUKS_KEY_FLAG_IMPORT_KEY   | 1    | 表示通过导入公钥接口导入的密钥。     |
| HUKS_KEY_FLAG_GENERATE_KEY | 2    | 表示通过生成密钥接口生成的密钥。     |
| HUKS_KEY_FLAG_AGREE_KEY    | 3    | 表示通过生成密钥协商接口生成的密钥。 |
| HUKS_KEY_FLAG_DERIVE_KEY   | 4    | 表示通过生成密钥派生接口生成的密钥。 |

## HuksKeyStorageType

表示密钥存储方式。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Security.Huks。

| 名称                    | 值   | 说明                           |
| ----------------------- | ---- | ------------------------------ |
| HUKS_STORAGE_TEMP       | 0    | 表示通过本地直接管理密钥。     |
| HUKS_STORAGE_PERSISTENT | 1    | 表示通过HUKS service管理密钥。 |

## HuksSendType

表示发送Tag的方式。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Security.Huks。

| 名称                 | 值   | 说明              |
| -------------------- | ---- | ----------------- |
| HUKS_SEND_TYPE_ASYNC | 0    | 表示异步发送TAG。 |
| HUKS_SEND_TYPE_SYNC  | 1    | 表示同步发送TAG。 |

## HuksUnwrapSuite<sup>9+</sup>

表示导入加密密钥的算法套件。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Security.Huks。

| 名称                                           | 值   | 说明                                                  |
| ---------------------------------------------- | ---- | ----------------------------------------------------- |
| HUKS_UNWRAP_SUITE_X25519_AES_256_GCM_NOPADDING | 1    | 导入加密密钥时，X25519密钥协商后使用AES-256 GCM加密。 |
| HUKS_UNWRAP_SUITE_ECDH_AES_256_GCM_NOPADDING   | 2    | 导入加密密钥时，ECDH密钥协商后使用AES-256 GCM加密。   |

##  HuksImportKeyType<sup>9+</sup>

表示导入密钥的密钥类型，默认为导入公钥，导入对称密钥时不需要该字段。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Security.Huks。

| 名称                      | 值   | 说明                           |
| ------------------------- | ---- | ------------------------------ |
| HUKS_KEY_TYPE_PUBLIC_KEY  | 0    | 表示导入的密钥类型为公钥。     |
| HUKS_KEY_TYPE_PRIVATE_KEY | 1    | 表示导入的密钥类型为私钥。     |
| HUKS_KEY_TYPE_KEY_PAIR    | 2    | 表示导入的密钥类型为公私钥对。 |

## HuksTagType

表示Tag的数据类型。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Security.Huks。


| 名称                  | 值      | 说明                                    |
| --------------------- | ------- | --------------------------------------- |
| HUKS_TAG_TYPE_INVALID | 0 << 28 | 表示非法的Tag类型。                     |
| HUKS_TAG_TYPE_INT     | 1 << 28 | 表示该Tag的数据类型为int类型的number。  |
| HUKS_TAG_TYPE_UINT    | 2 << 28 | 表示该Tag的数据类型为uint类型的number。 |
| HUKS_TAG_TYPE_ULONG   | 3 << 28 | 表示该Tag的数据类型为bigint。           |
| HUKS_TAG_TYPE_BOOL    | 4 << 28 | 表示该Tag的数据类型为boolean。          |
| HUKS_TAG_TYPE_BYTES   | 5 << 28 | 表示该Tag的数据类型为Uint8Array。       |

## HuksTag

表示调用参数的Tag。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Security.Huks。

| 名称                                         | 值                                       | 说明                                   |
| -------------------------------------------- | ---------------------------------------- | -------------------------------------- |
| HUKS_TAG_INVALID                             | HuksTagType.HUKS_TAG_TYPE_INVALID \| 0   | 表示非法的Tag。                        |
| HUKS_TAG_ALGORITHM                           | HUKS_TAG_TYPE_UINT \| 1                  | 表示算法的Tag。                        |
| HUKS_TAG_PURPOSE                             | HuksTagType.HUKS_TAG_TYPE_UINT \| 2      | 表示密钥用途的Tag。                    |
| HUKS_TAG_KEY_SIZE                            | HuksTagType.HUKS_TAG_TYPE_UINT \| 3      | 表示密钥长度的Tag。                    |
| HUKS_TAG_DIGEST                              | HuksTagType.HUKS_TAG_TYPE_UINT \| 4      | 表示摘要算法的Tag。                    |
| HUKS_TAG_PADDING                             | HuksTagType.HUKS_TAG_TYPE_UINT \| 5      | 表示补齐算法的Tag。                    |
| HUKS_TAG_BLOCK_MODE                          | HuksTagType.HUKS_TAG_TYPE_UINT \| 6      | 表示加密模式的Tag。                    |
| HUKS_TAG_KEY_TYPE                            | HuksTagType.HUKS_TAG_TYPE_UINT \| 7      | 表示密钥类型的Tag。                    |
| HUKS_TAG_ASSOCIATED_DATA                     | HuksTagType.HUKS_TAG_TYPE_BYTES \| 8     | 表示附加身份验证数据的Tag。            |
| HUKS_TAG_NONCE                               | HuksTagType.HUKS_TAG_TYPE_BYTES \| 9     | 表示密钥加解密的字段。                 |
| HUKS_TAG_IV                                  | HuksTagType.HUKS_TAG_TYPE_BYTES \| 10    | 表示密钥初始化的向量。                 |
| HUKS_TAG_INFO                                | HuksTagType.HUKS_TAG_TYPE_BYTES \| 11    | 表示密钥派生时的info。                 |
| HUKS_TAG_SALT                                | HuksTagType.HUKS_TAG_TYPE_BYTES \| 12    | 表示密钥派生时的盐值。                 |
| HUKS_TAG_PWD                                 | HuksTagType.HUKS_TAG_TYPE_BYTES \| 13    | 表示密钥派生时的password。             |
| HUKS_TAG_ITERATION                           | HuksTagType.HUKS_TAG_TYPE_UINT \| 14     | 表示密钥派生时的迭代次数。             |
| HUKS_TAG_KEY_GENERATE_TYPE                   | HuksTagType.HUKS_TAG_TYPE_UINT \| 15     | 表示生成密钥类型的Tag。                |
| HUKS_TAG_DERIVE_MAIN_KEY                     | HuksTagType.HUKS_TAG_TYPE_BYTES \| 16    | 表示密钥派生时的主密钥。               |
| HUKS_TAG_DERIVE_FACTOR                       | HuksTagType.HUKS_TAG_TYPE_BYTES \| 17    | 表示密钥派生时的派生因子。             |
| HUKS_TAG_DERIVE_ALG                          | HuksTagType.HUKS_TAG_TYPE_UINT \| 18     | 表示密钥派生时的算法类型。             |
| HUKS_TAG_AGREE_ALG                           | HuksTagType.HUKS_TAG_TYPE_UINT \| 19     | 表示密钥协商时的算法类型。             |
| HUKS_TAG_AGREE_PUBLIC_KEY_IS_KEY_ALIAS       | HuksTagType.HUKS_TAG_TYPE_BOOL \| 20     | 表示密钥协商时的公钥别名。             |
| HUKS_TAG_AGREE_PRIVATE_KEY_ALIAS             | HuksTagType.HUKS_TAG_TYPE_BYTES \| 21    | 表示密钥协商时的私钥别名。             |
| HUKS_TAG_AGREE_PUBLIC_KEY                    | HuksTagType.HUKS_TAG_TYPE_BYTES \| 22    | 表示密钥协商时的公钥。                 |
| HUKS_TAG_KEY_ALIAS                           | HuksTagType.HUKS_TAG_TYPE_BYTES \| 23    | 表示密钥别名。                         |
| HUKS_TAG_DERIVE_KEY_SIZE                     | HuksTagType.HUKS_TAG_TYPE_UINT \| 24     | 表示派生密钥的大小。                   |
| HUKS_TAG_IMPORT_KEY_TYPE<sup>9+</sup>        | HuksTagType.HUKS_TAG_TYPE_UINT \| 25     | 表示导入的密钥类型                     |
| HUKS_TAG_UNWRAP_ALGORITHM_SUITE<sup>9+</sup> | HuksTagType.HUKS_TAG_TYPE_UINT \| 26     | 表示导入加密密钥的套件                 |
| HUKS_TAG_ACTIVE_DATETIME                     | HuksTagType.HUKS_TAG_TYPE_ULONG \| 201   | 预留。                                 |
| HUKS_TAG_ORIGINATION_EXPIRE_DATETIME         | HuksTagType.HUKS_TAG_TYPE_ULONG \| 202   | 预留。                                 |
| HUKS_TAG_USAGE_EXPIRE_DATETIME               | HuksTagType.HUKS_TAG_TYPE_ULONG \| 203   | 预留。                                 |
| HUKS_TAG_CREATION_DATETIME                   | HuksTagType.HUKS_TAG_TYPE_ULONG \| 204   | 预留。                                 |
| HUKS_TAG_ALL_USERS                           | ksTagType.HUKS_TAG_TYPE_BOOL \| 301      | 预留。                                 |
| HUKS_TAG_USER_ID                             | HuksTagType.HUKS_TAG_TYPE_UINT \| 302    | 预留。                                 |
| HUKS_TAG_NO_AUTH_REQUIRED                    | HuksTagType.HUKS_TAG_TYPE_BOOL \| 303    | 预留。                                 |
| HUKS_TAG_USER_AUTH_TYPE                      | HuksTagType.HUKS_TAG_TYPE_UINT \| 304    | 预留。                                 |
| HUKS_TAG_AUTH_TIMEOUT                        | HuksTagType.HUKS_TAG_TYPE_UINT \| 305    | 预留。                                 |
| HUKS_TAG_AUTH_TOKEN                          | HuksTagType.HUKS_TAG_TYPE_BYTES \| 306   | 预留。                                 |
| HUKS_TAG_ATTESTATION_CHALLENGE               | HuksTagType.HUKS_TAG_TYPE_BYTES \| 501   | 表示attestation时的挑战值。            |
| HUKS_TAG_ATTESTATION_APPLICATION_ID          | HuksTagType.HUKS_TAG_TYPE_BYTES \| 502   | 表示attestation时的application Id。    |
| HUKS_TAG_ATTESTATION_ID_BRAND                | HuksTagType.HUKS_TAG_TYPE_BYTES \| 503   | 表示设备的brand。                      |
| HUKS_TAG_ATTESTATION_ID_DEVICE               | HuksTagType.HUKS_TAG_TYPE_BYTES \| 504   | 表示设备的device。                     |
| HUKS_TAG_ATTESTATION_ID_PRODUCT              | HuksTagType.HUKS_TAG_TYPE_BYTES \| 505   | 表示设备的product。                    |
| HUKS_TAG_ATTESTATION_ID_SERIAL               | HuksTagType.HUKS_TAG_TYPE_BYTES \| 506   | 表示设备的SN号。                       |
| HUKS_TAG_ATTESTATION_ID_IMEI                 | HuksTagType.HUKS_TAG_TYPE_BYTES \| 507   | 表示设备的IMEI号。                     |
| HUKS_TAG_ATTESTATION_ID_MEID                 | HuksTagType.HUKS_TAG_TYPE_BYTES \| 508   | 表示设备的MEID号。                     |
| HUKS_TAG_ATTESTATION_ID_MANUFACTURER         | HuksTagType.HUKS_TAG_TYPE_BYTES \| 509   | 表示设备的制造商。                     |
| HUKS_TAG_ATTESTATION_ID_MODEL                | HuksTagType.HUKS_TAG_TYPE_BYTES \| 510   | 表示设备的型号。                       |
| HUKS_TAG_ATTESTATION_ID_ALIAS                | HuksTagType.HUKS_TAG_TYPE_BYTES \| 511   | 表示attestation时的密钥别名。          |
| HUKS_TAG_ATTESTATION_ID_SOCID                | HuksTagType.HUKS_TAG_TYPE_BYTES \| 512   | 表示设备的SOCID。                      |
| HUKS_TAG_ATTESTATION_ID_UDID                 | HuksTagType.HUKS_TAG_TYPE_BYTES \| 513   | 表示设备的UDID。                       |
| HUKS_TAG_ATTESTATION_ID_SEC_LEVEL_INFO       | HuksTagType.HUKS_TAG_TYPE_BYTES \| 514   | 表示attestation时的安全凭据。          |
| HUKS_TAG_ATTESTATION_ID_VERSION_INFO         | HuksTagType.HUKS_TAG_TYPE_BYTES \| 515   | 表示attestation时的版本号。            |
| HUKS_TAG_IS_KEY_ALIAS                        | HuksTagType.HUKS_TAG_TYPE_BOOL \| 1001   | 表示是否使用生成key时传入的别名的Tag。 |
| HUKS_TAG_KEY_STORAGE_FLAG                    | HuksTagType.HUKS_TAG_TYPE_UINT \| 1002   | 表示密钥存储方式的Tag。                |
| HUKS_TAG_IS_ALLOWED_WRAP                     | HuksTagType.HUKS_TAG_TYPE_BOOL \| 1003   | 预留。                                 |
| HUKS_TAG_KEY_WRAP_TYPE                       | HuksTagType.HUKS_TAG_TYPE_UINT \| 1004   | 预留。                                 |
| HUKS_TAG_KEY_AUTH_ID                         | HuksTagType.HUKS_TAG_TYPE_BYTES \| 1005  | 预留。                                 |
| HUKS_TAG_KEY_ROLE                            | HuksTagType.HUKS_TAG_TYPE_UINT \| 1006   | 预留。                                 |
| HUKS_TAG_KEY_FLAG                            | HuksTagType.HUKS_TAG_TYPE_UINT \| 1007   | 表示密钥标志的Tag。                    |
| HUKS_TAG_IS_ASYNCHRONIZED                    | HuksTagType.HUKS_TAG_TYPE_UINT \| 1008   | 预留。                                 |
| HUKS_TAG_SECURE_KEY_ALIAS                    | HuksTagType.HUKS_TAG_TYPE_BOOL \| 1009   | 预留。                                 |
| HUKS_TAG_SECURE_KEY_UUID                     | HuksTagType.HUKS_TAG_TYPE_BYTES \| 1010  | 预留。                                 |
| HUKS_TAG_KEY_DOMAIN                          | HuksTagType.HUKS_TAG_TYPE_UINT \| 1011   | 预留。                                 |
| HUKS_TAG_PROCESS_NAME                        | HuksTagType.HUKS_TAG_TYPE_BYTES \| 10001 | 表示进程名称的Tag。                    |
| HUKS_TAG_PACKAGE_NAME                        | HuksTagType.HUKS_TAG_TYPE_BYTES \| 10002 | 预留。                                 |
| HUKS_TAG_ACCESS_TIME                         | HuksTagType.HUKS_TAG_TYPE_UINT \| 10003  | 预留。                                 |
| HUKS_TAG_USES_TIME                           | HuksTagType.HUKS_TAG_TYPE_UINT \| 10004  | 预留。                                 |
| HUKS_TAG_CRYPTO_CTX                          | HuksTagType.HUKS_TAG_TYPE_ULONG \| 10005 | 预留。                                 |
| HUKS_TAG_KEY                                 | HuksTagType.HUKS_TAG_TYPE_BYTES \| 10006 | 预留。                                 |
| HUKS_TAG_KEY_VERSION                         | HuksTagType.HUKS_TAG_TYPE_UINT \| 10007  | 表示密钥版本的Tag。                    |
| HUKS_TAG_PAYLOAD_LEN                         | HuksTagType.HUKS_TAG_TYPE_UINT \| 10008  | 预留。                                 |
| HUKS_TAG_AE_TAG                              | HuksTagType.HUKS_TAG_TYPE_BYTES \| 10009 | 预留。                                 |
| HUKS_TAG_IS_KEY_HANDLE                       | HuksTagType.HUKS_TAG_TYPE_ULONG \| 10010 | 预留。                                 |
| HUKS_TAG_OS_VERSION                          | HuksTagType.HUKS_TAG_TYPE_UINT \| 10101  | 表示操作系统版本的Tag。                |
| HUKS_TAG_OS_PATCHLEVEL                       | HuksTagType.HUKS_TAG_TYPE_UINT \| 10102  | 表示操作系统补丁级别的Tag。            |
| HUKS_TAG_SYMMETRIC_KEY_DATA                  | HuksTagType.HUKS_TAG_TYPE_BYTES \| 20001 | 预留。                                 |
| HUKS_TAG_ASYMMETRIC_PUBLIC_KEY_DATA          | HuksTagType.HUKS_TAG_TYPE_BYTES \| 20002 | 预留。                                 |
| HUKS_TAG_ASYMMETRIC_PRIVATE_KEY_DATA         | HuksTagType.HUKS_TAG_TYPE_BYTES \| 20003 | 预留。                                 |

## huks.generateKey

generateKey(keyAlias: string, options: HuksOptions, callback: AsyncCallback\<HuksResult>) : void

生成密钥，使用Callback回调异步返回结果。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Security.Huks。

**参数：** 

| 参数名   | 类型                                      | 必填 | 说明                                                         |
| -------- | ----------------------------------------- | ---- | ------------------------------------------------------------ |
| keyAlias | string                                    | 是   | 别名。                                                       |
| options  | [HuksOptions](#huksoptions)               | 是   | 用于存放生成key所需TAG。                                     |
| callback | AsyncCallback\<[HuksResult](#huksresult)> | 是   | 返回HUKS_SUCCESS时表示接口使用成功，其余结果请参考HuksResult进行错误码查询。 |

**示例：**

```js
/* 以生成RSA512密钥为例 */
var keyAlias = 'keyAlias';
var properties = new Array();
properties[0] = {
  tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
  value: huks.HuksKeyAlg.HUKS_ALG_RSA
};
properties[1] = {
  tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
  value: huks.HuksKeySize.HUKS_RSA_KEY_SIZE_512
};
properties[2] = {
  tag: huks.HuksTag.HUKS_TAG_PURPOSE,
  value:
huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT |
huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DECRYPT
};
properties[3] = {
  tag: huks.HuksTag.HUKS_TAG_PADDING,
  value: huks.HuksKeyPadding.HUKS_PADDING_OAEP
};
properties[4] = {
  tag: huks.HuksTag.HUKS_TAG_DIGEST,
  value: huks.HuksKeyDigest.HUKS_DIGEST_SHA256
};
var options = {
  properties: properties
};
huks.generateKey(keyAlias, options, function (err, data){}); 
```

## huks.generateKey

generateKey(keyAlias: string, options: HuksOptions) : Promise\<HuksResult>

生成密钥，使用Promise方式异步返回结果。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Security.Huks。

**参数：** 

| 参数名   | 类型                        | 必填 | 说明                     |
| -------- | --------------------------- | ---- | ------------------------ |
| keyAlias | string                      | 是   | 密钥别名。               |
| options  | [HuksOptions](#huksoptions) | 是   | 用于存放生成key所需TAG。 |

**返回值**：（可选，如不涉及可删除）

| 类型                                | 说明                                               |
| ----------------------------------- | -------------------------------------------------- |
| Promise\<[HuksResult](#huksresult)> | 返回HUKS_SUCCESS时表示接口使用成功，其他时为错误。 |

**示例：**

```js
/* 以生成ECC256密钥为例 */
var keyAlias = 'keyAlias';
var properties = new Array();
properties[0] = {
  tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
  value: huks.HuksKeyAlg.HUKS_ALG_ECC
};
properties[1] = {
  tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
  value: huks.HuksKeySize.HUKS_ECC_KEY_SIZE_256
};
properties[2] = {
  tag: huks.HuksTag.HUKS_TAG_PURPOSE,
  value:
huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_SIGN |
huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_VERIFY
};
properties[3] = {
  tag: huks.HuksTag.HUKS_TAG_DIGEST,
  value: huks.HuksKeyDigest.HUKS_DIGEST_SHA256
};
var options = {
  properties: properties
};
var result = huks.generateKey(keyAlias, options);
```

## huks.deleteKey

deleteKey(keyAlias: string, options: HuksOptions, callback: AsyncCallback\<HuksResult>) : void

删除密钥，使用Callback回调异步返回结果。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Security.Huks。

**参数：**

| 参数名   | 类型                                      | 必填 | 说明                                               |
| -------- | ----------------------------------------- | ---- | -------------------------------------------------- |
| keyAlias | string                                    | 是   | 密钥别名，应为生成key时传入的别名。                |
| options  | [HuksOptions](#huksoptions)               | 是   | 空对象（此处传空即可）。                           |
| callback | AsyncCallback\<[HuksResult](#huksresult)> | 是   | 返回HUKS_SUCCESS时表示接口使用成功，其他时为错误。 |

**示例：**

```js
/* 此处options选择emptyOptions传空 */
var keyAlias = 'keyAlias';
var emptyOptions = {
  properties: []
};
huks.deleteKey(keyAlias, emptyOptions, function (err, data) {});
```

## huks.deleteKey

deleteKey(keyAlias: string, options: HuksOptions) : Promise\<HuksResult>

删除密钥，使用Promise方式异步返回结果。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Security.Huks。

**参数：**

| 参数名   | 类型        | 必填 | 说明                                                  |
| -------- | ----------- | ---- | ----------------------------------------------------- |
| keyAlias | string      | 是   | 密钥别名，应为生成key时传入的别名。 |
| options | [HuksOptions](#huksoptions) | 是   | 空对象（此处传空即可）。 |

**返回值：**

| 类型                                | 说明                                               |
| ----------------------------------- | -------------------------------------------------- |
| Promise\<[HuksResult](#huksresult)> | 返回HUKS_SUCCESS时表示接口使用成功，其他时为错误。 |

**示例：**

```js
/* 此处options选择emptyOptions传空 */
var keyAlias = 'keyAlias';
var emptyOptions = {
  properties: []
};
var result = huks.deleteKey(keyAlias, emptyOptions);
```

## huks.getSdkVersion

getSdkVersion(options: HuksOptions) : string

获取当前系统sdk版本。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Security.Huks。

**参数：**

| 参数名  | 类型       | 必填 | 说明                      |
| ------- | ---------- | ---- | ------------------------- |
| options | [HuksOptions](#huksoptions) | 是   | 空对象，用于存放sdk版本。 |

**返回值：**

| 类型   | 说明          |
| ------ | ------------- |
| string | 返回sdk版本。 |

**示例：**

```js
/* 此处options选择emptyOptions传空 */
var emptyOptions = {
  properties: []
};
var result = huks.getSdkVersion(emptyOptions);
```

## huks.importKey

importKey(keyAlias: string, options: HuksOptions, callback: AsyncCallback\<HuksResult>) : void

导入明文密钥，使用Callback方式回调异步返回结果 。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Security.Huks。

**参数：**

| 参数名   | 类型                     | 必填 | 说明                                              |
| -------- | ------------------------ | ---- | ------------------------------------------------- |
| keyAlias | string                   | 是   | 密钥别名，用于存放所需密钥。 |
| options  | [HuksOptions](#huksoptions) | 是   | 用于导入时所需TAG和需要导入的密钥。 |
| callback | AsyncCallback\<[HuksResult](#huksresult)> | 是   | 返回HUKS_SUCCESS时表示接口使用成功，其他时为错误。 |

**示例：**

```js
/* 以导入AES256密钥为例 */
var plainTextSize32 = makeRandomArr(32);
function makeRandomArr(size) {
    var arr = new Uint8Array(size);
    for (var i = 0; i < size; i++) {
        arr[i] = Math.floor(Math.random() * 10);
    }
    return arr;
};
var keyAlias = 'keyAlias';
var properties = new Array();
properties[0] = {
  tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
  value: huks.HuksKeyAlg.HUKS_ALG_AES
};
properties[1] = {
  tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
  value: huks.HuksKeySize.HUKS_AES_KEY_SIZE_256
};
properties[2] = {
  tag: huks.HuksTag.HUKS_TAG_PURPOSE,
  value:
huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT | huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DECRYPT
};
properties[3] = {
  tag: huks.HuksTag.HUKS_TAG_PADDING,
  value:huks.HuksKeyPadding.HUKS_PADDING_PKCS7
};
properties[4] = {
  tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
  value: huks.HuksCipherMode.HUKS_MODE_ECB
};
var options = {
  properties: properties,
  inData: plainTextSize32
};
huks.importKey(keyAlias, options, function (err, data){});
```

## huks.importKey

importKey(keyAlias: string, options: HuksOptions) : Promise\<HuksResult>

导入明文密钥，使用Promise方式异步返回结果。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Security.Huks。

**参数：**

| 参数名   | 类型        | 必填 | 说明                                 |
| -------- | ----------- | ---- | ------------------------------------ |
| keyAlias | string      | 是   | 密钥别名，用于存放所需密钥。 |
| options  | [HuksOptions](#huksoptions) | 是   | 用于导入时所需TAG和需要导入的密钥。 |

**返回值：**

| 类型                                | 说明                                               |
| ----------------------------------- | -------------------------------------------------- |
| Promise\<[HuksResult](#huksresult)> | 返回HUKS_SUCCESS时表示接口使用成功，其他时为错误。 |

**示例：**

```js
/* 以导入AES128为例 */
var plainTextSize32 = makeRandomArr(32);

function makeRandomArr(size) {
    var arr = new Uint8Array(size);
    for (var i = 0; i < size; i++) {
        arr[i] = Math.floor(Math.random() * 10);
    }
    return arr;
};

/*第一步：生成密钥*/
var keyAlias = 'keyAlias';
var properties = new Array();
properties[0] = {
  tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
  value: huks.HuksKeyAlg.HUKS_ALG_AES
};
properties[1] = {
  tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
  value: huks.HuksKeySize.HUKS_AES_KEY_SIZE_128
};
properties[2] = {
  tag: huks.HuksTag.HUKS_TAG_PURPOSE,
  value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT | huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DECRYPT
};
properties[3] = {
  tag: huks.HuksTag.HUKS_TAG_PADDING,
  value:huks.HuksKeyPadding.HUKS_PADDING_PKCS7
};
properties[4] = {
  tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
  value: huks.HuksCipherMode.HUKS_MODE_ECB
};
var huksoptions = {
  properties: properties,
  inData: plainTextSize32
};
var result = huks.importKey(keyAlias, huksoptions);
```

## huks.importWrappedKey<sup>9+</sup>

importWrappedKey(keyAlias: string, wrappingKeyAlias: string, options: HuksOptions, callback: AsyncCallback\<HuksResult>) : void

导入加密密钥，使用Callback方式回调异步返回结果 。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Security.Huks。

**参数：**

| 参数名           | 类型                                      | 必填 | 说明                                               |
| ---------------- | ----------------------------------------- | ---- | -------------------------------------------------- |
| keyAlias         | string                                    | 是   | 密钥别名，存放待导入密钥的别名。                   |
| wrappingKeyAlias | string                                    | 是   | 密钥别名，对应密钥用于解密加密的密钥数据。         |
| options          | [HuksOptions](#huksoptions)               | 是   | 用于导入时所需TAG和需要导入的加密的密钥数据。      |
| callback         | AsyncCallback\<[HuksResult](#huksresult)> | 是   | 返回HUKS_SUCCESS时表示接口使用成功，其他时为错误。 |

**示例：**

```js
var exportWrappingKey;
var alias1 = "importAlias";
var alias2 = "wrappingKeyAlias";

async function TestGenFunc(alias, options) {
  await genKey(alias, options)
    .then((data) => {
      console.log(`test genKey data: ${JSON.stringify(data)}`);
    })
    .catch((err) => {
      console.log('test genKey err information: ' + JSON.stringify(err));
    });
}

function genKey(alias, options) {
  return new Promise((resolve, reject) => {
    huks.generateKey(alias, options, function (err, data) {
      console.log(`test genKey data: ${JSON.stringify(data)}`);
      if (err.code !== 0) {
        console.log('test genKey err information: ' + JSON.stringify(err));
        reject(err);
      } else {
        resolve(data);
      }
    });
  });
}

async function TestExportFunc(alias, options) {
  await exportKey(alias, options)
    .then((data) => {
      console.log(`test exportKey data: ${JSON.stringify(data)}`);
    })
    .catch((err) => {
      console.log('test exportKey err information: ' + JSON.stringify(err));
    });
}

function exportKey(alias, options) {
  return new Promise((resolve, reject) => {
    huks.exportKey(alias, options, function (err, data) {
      console.log(`test exportKey data: ${JSON.stringify(data)}`);
      if (err.code !== 0) {
        console.log('test exportKey err information: ' + JSON.stringify(err));
        reject(err);
      } else {
        exportWrappingKey = data.outData;
        resolve(data);
      }
    });
  });
}

async function TestImportWrappedFunc(alias, wrappingAlias, options) {
  await importWrappedKey(alias, wrappingAlias, options)
    .then((data) => {
      console.log(`TestImportWrappedFunc data: ${JSON.stringify(data)}`);
    })
    .catch((err) => {
      console.log('test importWrappedKey err information: ' + JSON.stringify(err));
    });
}

function importWrappedKey(alias, wrappingAlias, options) {
  return new Promise((resolve, reject) => {
    huks.importWrappedKey(alias, wrappingAlias, options, function (err, data) {
      console.log(`importWrappedKey data: ${JSON.stringify(data)}`);
      if (err.code !== 0) {
        console.log('importWrappedKey err information: ' + JSON.stringify(err));
        reject(err);
      } else {
        resolve(data);
      }
    });
  });
}

async function TestImportWrappedKeyFunc(
  alias,
  wrappingAlias,
  genOptions,
  importOptions
) {
    await TestGenFunc(wrappingAlias, genOptions);
    await TestExportFunc(wrappingAlias, genOptions);

    /* 以下操作不需要调用HUKS接口，此处不给出具体实现。
     * 假设待导入的密钥为keyA
     * 1.生成ECC公私钥keyB，公钥为keyB_pub, 私钥为keyB_pri
     * 2.使用keyB_pri和wrappingAlias密钥中获取的公钥进行密钥协商，协商出共享密钥share_key
     * 3.随机生成密钥kek，用于加密keyA，采用AES-GCM加密，加密过程中需要记录：nonce1/aad1/加密后的密文keyA_enc/加密后的tag1。
     * 4.使用share_key加密kek，采用AES-GCM加密，加密过程中需要记录：nonce2/aad2/加密后的密文kek_enc/加密后的tag2。
     * 5.拼接importOptions.inData字段，满足以下格式:
     * keyB_pub的长度（4字节） + keyB_pub的数据 + aad2的长度（4字节） + aad2的数据 +
     * nonce2的长度（4字节）   + nonce2的数据   + tag2的长度（4字节） + tag2的数据 +
     * kek_enc的长度（4字节）  + kek_enc的数据  + aad1的长度（4字节） + aad1的数据 +
     * nonce1的长度（4字节）   + nonce1的数据   + tag1的长度（4字节） + tag1的数据 +
     * keyA长度占用的内存长度（4字节）  + keyA的长度     + keyA_enc的长度（4字节） + keyA_enc的数据
     */
    var inputKey = new Uint8Array([0x02, 0x00, 0x00, 0x00]);
    importOptions.inData = inputKey;
    await TestImportWrappedFunc(alias, wrappingAlias, importOptions);
}

function makeGenerateOptions() {
  var properties = new Array();
  properties[0] = {
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_ECC
  };
  properties[1] = {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_ECC_KEY_SIZE_256
  };
  properties[2] = {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_UNWRAP
  };
  properties[3] = {
    tag: huks.HuksTag.HUKS_TAG_DIGEST,
    value: huks.HuksKeyDigest.HUKS_DIGEST_SHA256
  };
  var options = {
    properties: properties
  };
  return options;
};

function makeImportOptions() {
  var properties = new Array();
  properties[0] = {
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_AES
  };
  properties[1] = {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_AES_KEY_SIZE_256
  };
  properties[2] = {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT | huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DECRYPT
  };
  properties[3] = {
    tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
    value: huks.HuksCipherMode.HUKS_MODE_CBC
  };
  properties[4] = {
    tag: huks.HuksTag.HUKS_TAG_UNWRAP_ALGORITHM_SUITE,
    value: huks.HuksUnwrapSuite.HUKS_UNWRAP_SUITE_ECDH_AES_256_GCM_NOPADDING
  };
  var options = {
    properties: properties
  };
  return options;
};

function huksImportWrappedKey() {
  var genOptions = makeGenerateOptions();
  var importOptions = makeImportOptions();
  TestImportWrappedKeyFunc(
    alias1,
    alias2,
    genOptions,
    importOptions
  );
}
```

## huks.importWrappedKey<sup>9+</sup>

importWrappedKey(keyAlias: string, wrappingKeyAlias: string, options: HuksOptions) : Promise\<HuksResult>

导入加密密钥，使用Promise方式异步返回结果。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Security.Huks。

**参数：**

| 参数名           | 类型                        | 必填 | 说明                                          |
| ---------------- | --------------------------- | ---- | --------------------------------------------- |
| keyAlias         | string                      | 是   | 密钥别名，存放待导入密钥的别名。              |
| wrappingKeyAlias | string                      | 是   | 密钥别名，对应密钥用于解密加密的密钥数据。    |
| options          | [HuksOptions](#huksoptions) | 是   | 用于导入时所需TAG和需要导入的加密的密钥数据。 |

**返回值：**

| 类型                                | 说明                                               |
| ----------------------------------- | -------------------------------------------------- |
| Promise\<[HuksResult](#huksresult)> | 返回HUKS_SUCCESS时表示接口使用成功，其他时为错误。 |

**示例：**

```js
/* 处理流程与callback类似，主要差异点为如下函数： */
async function TestImportWrappedFunc(alias, wrappingAlias, options) {
  var result = await huks.importWrappedKey(alias, wrappingAlias, options);
  if (result.errorCode === 0) {
    console.log('test importWrappedKey success');
  } else {
    console.log('test importWrappedKey fail');
  }
}
```

## huks.exportKey

exportKey(keyAlias: string, options: HuksOptions, callback: AsyncCallback\<HuksResult>) : void

导出密钥，使用Callback方式回调异步返回的结果。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Security.Huks。

**参数：**

| 参数名   | 类型                                      | 必填 | 说明                                                         |
| -------- | ----------------------------------------- | ---- | ------------------------------------------------------------ |
| keyAlias | string                                    | 是   | 密钥别名，应与所用密钥生成时使用的别名相同。                 |
| options  | [HuksOptions](#huksoptions)               | 是   | 空对象（此处传空即可）。                                     |
| callback | AsyncCallback\<[HuksResult](#huksresult)> | 是   | 返回HUKS_SUCCESS时表示接口使用成功，其他时为错误。outData：返回从密钥中导出的公钥。 |

**示例：**

```js
/* 此处options选择emptyOptions来传空 */
var keyAlias = 'keyAlias';
var emptyOptions = {
  properties: []
};
huks.exportKey(keyAlias, emptyOptions, function (err, data){});
```

## huks.exportKey

exportKey(keyAlias: string, options: HuksOptions) : Promise\<HuksResult>

导出密钥，使用Promise方式回调异步返回的结果。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Security.Huks。

**参数：**

| 参数名   | 类型        | 必填 | 说明                                                         |
| -------- | ----------- | ---- | ------------------------------------------------------------ |
| keyAlias | string      | 是   | 密钥别名，应与所用密钥生成时使用的别名相同。 |
| options  | [HuksOptions](#huksoptions) | 是   | 空对象（此处传空即可）。 |

**返回值：**

| 类型                                | 说明                                                         |
| ----------------------------------- | ------------------------------------------------------------ |
| Promise\<[HuksResult](#huksresult)> | 返回HUKS_SUCCESS时表示接口使用成功，其他时为错误。outData：返回从密钥中导出的公钥。 |

**示例：**

```js
/* 此处options选择emptyOptions来传空 */
var keyAlias = 'keyAlias';
var emptyOptions = {
  properties: []
};
var result = huks.exportKey(keyAlias, emptyOptions);
```

## huks.getKeyProperties

getKeyProperties(keyAlias: string, options: HuksOptions, callback: AsyncCallback\<HuksResult>) : void

获取密钥属性，使用Callback回调异步返回结果。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Security.Huks。

**参数：**

| 参数名   | 类型                                      | 必填 | 说明                                                         |
| -------- | ----------------------------------------- | ---- | ------------------------------------------------------------ |
| keyAlias | string                                    | 是   | 密钥别名，应与所用密钥生成时使用的别名相同。                 |
| options  | [HuksOptions](#huksoptions)               | 是   | 空对象（此处传空即可）。                                     |
| callback | AsyncCallback\<[HuksResult](#huksresult)> | 是   | errorCode：返回HUKS_SUCCESS时表示接口使用成功，其他时为错误。 |

**示例：**

```js
/* 此处options选择emptyOptions来传空 */
var keyAlias = 'keyAlias';
var emptyOptions = {
  properties: []
};
huks.getKeyProperties(keyAlias, emptyOptions, function (err, data){});
```

## huks.getKeyProperties

getKeyProperties(keyAlias: string, options: HuksOptions) : Promise\<HuksResult>

获取密钥属性，使用Promise回调异步返回结果。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Security.Huks。

**参数：**

| 参数名   | 类型        | 必填 | 说明                                                         |
| -------- | ----------- | ---- | ------------------------------------------------------------ |
| keyAlias | string      | 是   | 密钥别名，应与所用密钥生成时使用的别名相同。 |
| options  | [HuksOptions](#huksoptions) | 是   | 空对象（此处传空即可）。 |

**返回值：**

| 类型               | 说明                                                         |
| ------------------ | ------------------------------------------------------------ |
| Promise\<[HuksResult](#huksoptions)> | errorCode：返回HUKS_SUCCESS时表示接口使用成功，其他时为错误。properties：返回值为生成密钥时所需参数。 |

**示例：**

```js
/* 此处options选择emptyOptions来传空 */
var keyAlias = 'keyAlias';
var emptyOptions = {
  properties: []
};
var result = huks.getKeyProperties(keyAlias, emptyOptions);
```

## huks.isKeyExist

isKeyExist(keyAlias: string, options: HuksOptions, callback: AsyncCallback\<boolean>) : void

判断密钥是否存在，使用Callback回调异步返回结果 。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Security.Huks。

**参数：**

| 参数名   | 类型                   | 必填 | 说明                                  |
| -------- | ---------------------- | ---- | ------------------------------------- |
| keyAlias | string                 | 是   | 所需查找的密钥的别名。 |
| options  | [HuksOptions](#huksoptions) | 是   | 空对象（此处传空即可）。 |
| callback | AsyncCallback\<boolean> | 是   | FALSE代表密钥不存在，TRUE代表密钥存在。 |

**示例：**

```js
/* 此处options选择emptyOptions来传空 */
var keyAlias = 'keyAlias';
var emptyOptions = {
  properties: []
};
huks.isKeyExist(keyAlias, emptyOptions, function (err, data){});
```

## huks.isKeyExist

isKeyExist(keyAlias: string, options: HuksOptions) : Promise\<boolean>

判断密钥是否存在，使用Promise回调异步返回结果 。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Security.Huks。

**参数：**

| 参数名   | 类型        | 必填 | 说明                             |
| -------- | ----------- | ---- | -------------------------------- |
| keyAlias | string      | 是   | 所需查找的密钥的别名。 |
| options  | [HuksOptions](#huksoptions) | 是   | 空对象（此处传空即可）。 |

**返回值：**

| 类型              | 说明                                    |
| ----------------- | --------------------------------------- |
| Promise\<boolean> | FALSE代表密钥不存在，TRUE代表密钥存在。 |

**示例：**

```js
/* 此处options选择emptyOptions来传空 */
var keyAlias = 'keyAlias';
var emptyOptions = {
  properties: []
};
var result = huks.isKeyExist(keyAlias, emptyOptions);
```



## huks.init

init(keyAlias: string, options: HuksOptions, callback: AsyncCallback\<HuksHandle>) : void

init操作密钥接口，使用Callback回调异步返回结果 。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Security.Huks。

**参数：**

| 参数名   | 类型                   | 必填 | 说明                                  |
| -------- | ---------------------- | ---- | ------------------------------------- |
| keyAlias | string                 | 是   | Init操作密钥的别名。 |
| options  | [HuksOptions](#huksoptions) | 是   | Init操作的参数集合。 |
| callback | AsyncCallback\<[HuksHandle](#hukshandle)> | 是   | 将Init操作操作返回的handle添加到密钥管理系统的回调。 |


## huks.init

init(keyAlias: string, options: HuksOptions) : Promise\<HuksHandle>

init操作密钥接口，使用Promise方式异步返回结果。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Security.Huks。

**参数：**

| 参数名   | 类型                   | 必填 | 说明                                  |
| -------- | ---------------------- | ---- | ------------------------------------- |
| keyAlias | string                 | 是   | Init操作密钥的别名。 |
| options  | [HuksOptions](#huksoptions) | 是   | Init参数集合。 |
| promise | Promise\<[HuksHandle](#hukshandle)> | 是   | 将Init操作返回的handle添加到密钥管理系统的回调。 |


## huks.update

update(handle: number, token?: Uint8Array, options: HuksOptions, callback: AsyncCallback\<HuksResult>) : void

update操作密钥接口，使用Callback回调异步返回结果 。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Security.Huks。

**参数：**

| 参数名   | 类型                   | 必填 | 说明                                  |
| -------- | ---------------------- | ---- | ------------------------------------- |
| handle | number           | 是   | Update操作的handle。 |
| token | Uint8Array | 否 | Update操作的token。 |
| options  | [HuksOptions](#huksoptions) | 是   | Update的参数集合。 |
| callback | AsyncCallback\<[HuksResult](#huksresult)> | 是 | 将Update操作的结果添加到密钥管理系统的回调。 |


## huks.update

update(handle: number, token?: Uint8Array, options: HuksOptions) : Promise\<HuksResult>

update操作密钥接口，使用Promise方式异步返回结果。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Security.Huks。

**参数：**

| 参数名   | 类型                   | 必填 | 说明                                  |
| -------- | ---------------------- | ---- | ------------------------------------- |
| handle | number           | 是   | Update操作的handle。 |
| token | Uint8Array | 否 | Update操作的token。 |
| options  | [HuksOptions](#huksoptions) | 是   | Update操作的参数集合。 |
| promise | Promise\<[HuksResult](#huksresult)> | 是 | 将Update操作的结果添加到密钥管理系统的回调。 |


## huks.finish

finish(handle: number, options: HuksOptions, callback: AsyncCallback\<HuksResult>) : void

finish操作密钥接口，使用Callback回调异步返回结果 。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Security.Huks。

**参数：**

| 参数名   | 类型                   | 必填 | 说明                                  |
| -------- | ---------------------- | ---- | ------------------------------------- |
| handle | number           | 是   | Finish操作的handle。 |
| options  | [HuksOptions](#huksoptions) | 是   | Finish的参数集合。 |
| callback | AsyncCallback\<[HuksResult](#huksresult)> | 是 | 将Finish操作的结果添加到密钥管理系统的回调。 |


## huks.finish

finish(handle: number, options: HuksOptions) : Promise\<HuksResult>

finish操作密钥接口，使用Promise方式异步返回结果。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Security.Huks。

**参数：**

| 参数名   | 类型                   | 必填 | 说明                                  |
| -------- | ---------------------- | ---- | ------------------------------------- |
| handle | number           | 是   | Finish操作的handle。 |
| options  | [HuksOptions](#huksoptions) | 是   | Finish操作的参数集合。 |
| promise | Promise\<[HuksResult](#HuksResult)> | 是 | promise实例，用于获取异步返回结果。 |


## huks.abort

abort(handle: number, options: HuksOptions, callback: AsyncCallback\<HuksResult>) : void

abort操作密钥接口，使用Callback回调异步返回结果 。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Security.Huks。

**参数：**

| 参数名   | 类型                   | 必填 | 说明                                  |
| -------- | ---------------------- | ---- | ------------------------------------- |
| handle | number           | 是   | Abort操作的handle。 |
| options  | [HuksOptions](#huksoptions) | 是   | Abort操作的参数集合。 |
| callback | AsyncCallback\<[HuksResult](#huksresult)> | 是 | 将Abort操作的结果添加到密钥管理系统的回调。 |

**示例：**

```js
/* huks.init, huks.update, huks.finish为三段式接口，需要一起使用，当huks.init和huks.update
 * 以及huks.finish操作中的任一阶段发生错误时，都需要调用huks.abort来终止密钥的使用。
 *
 * 以下以RSA1024密钥的callback操作使用为例
 */
import router from '@system.router';
import huks from '@ohos.security.huks';

async function routePage() {
  let options = {
    uri: 'pages/second'
  }
  try {
    await router.push(options)
  } catch (err) {
    console.error(`fail callback, code: ${err.code}, msg: ${err.msg}`)
  }
}
var keyalias = "HuksDemoRSA";
var properties = new Array();
var options = {
  properties: properties,
  inData: new Uint8Array(0)
};
var handle;
var resultMessage = "";
async function generateKey() {
  properties[0] = {
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_RSA
  };
  properties[1] = {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_RSA_KEY_SIZE_1024
  };
  properties[2] = {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT
  };
  properties[3] = {
    tag: huks.HuksTag.HUKS_TAG_PADDING,
    value: huks.HuksKeyPadding.HUKS_PADDING_OAEP
  };
  properties[4] = {
    tag: huks.HuksTag.HUKS_TAG_DIGEST,
    value: huks.HuksKeyDigest.HUKS_DIGEST_SHA256
  };
  huks.generateKey(keyalias, options);
}
function stringToUint8Array(str) {
  var arr = [];
  for (var i = 0, j = str.length; i < j; ++i) {
    arr.push(str.charCodeAt(i));
  }
  var tmpUint8Array = new Uint8Array(arr);
  return tmpUint8Array;
}
async function huksInit() {
  await huks.init(keyalias, options).then((data) => {
    console.log(`test init data: ${JSON.stringify(data)}`);
    handle = data.handle;
  }).catch((err) => {
    console.log("test init err information: " + JSON.stringify(err))
  })
}
async function huksUpdate() {
    options.inData = stringToUint8Array("huksHmacTest");
    await huks.update(handle, options).then((data) => {
      if (data.errorCode === 0) {
        resultMessage += "update success!";
      } else {
        resultMessage += "update fail!";
      }
    });
    console.log(resultMessage);
}
function huksFinish() {
  options.inData = stringToUint8Array("HuksDemoHMAC");
  huks.finish(handle, options).then((data) => {
    if (data.errorCode === 0) {
      resultMessage = "finish success!";
    } else {
      resultMessage = "finish fail errorCode: " + data.errorCode;
    }
  }).catch((err) => {
    resultMessage = "finish fail， catch errorMessage:" + JSON.stringify(err)
  });
  console.log(resultMessage);
}
async function huksAbort() {
  huks.abort(handle, options).then((data) => {
    if (data.errorCode === 0) {
      resultMessage = "abort success!";
    } else {
      resultMessage = "abort fail errorCode: " + data.errorCode;
    }
  }).catch((err) => {
    resultMessage = "abort fail， catch errorMessage:" + JSON.stringify(err)
  });
  console.log(resultMessage);
}

@Entry
@Component
struct Index {
  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
      Text('Hello World')
        .fontSize(50)
        .fontWeight(FontWeight.Bold)
      Button() {
        Text('Tocallback')
          .fontSize(25)
          .fontWeight(FontWeight.Bold)
      }.type(ButtonType.Capsule)
      .margin({
        top: 20
      })
      .width('50%')
      .height('10%')
      .backgroundColor('#0D9FFB')
      .onClick(() => {
        routePage()
      })
      Button() {
        Text('generateKey')
          .fontSize(25)
          .fontWeight(FontWeight.Bold)
      }.type(ButtonType.Capsule)
      .margin({
        top: 20
      })
      .width('50%')
      .height('10%')
      .backgroundColor('#0D9FFB')
      .onClick(() => {
        generateKey()
      })
      Button() {
        Text('Init')
          .fontSize(25)
          .fontWeight(FontWeight.Bold)
      }.type(ButtonType.Capsule)
      .margin({
        top: 20
      })
      .width('50%')
      .height('10%')
      .backgroundColor('#0D9FFB')
      .onClick(() => {
        huksInit()
      })
      Button() {
        Text('Update')
          .fontSize(25)
          .fontWeight(FontWeight.Bold)
      }.type(ButtonType.Capsule)
      .margin({
        top: 20
      })
      .width('50%')
      .height('10%')
      .backgroundColor('#0D9FFB')
      .onClick(() => {
        huksUpdate()
      })
      Button() {
        Text('Finish')
          .fontSize(25)
          .fontWeight(FontWeight.Bold)
      }.type(ButtonType.Capsule)
      .margin({
        top: 20
      })
      .width('50%')
      .height('10%')
      .backgroundColor('#0D9FFB')
      .onClick(() => {
        huksFinish()
      })
      Button() {
        Text('Abort')
          .fontSize(25)
          .fontWeight(FontWeight.Bold)
      }.type(ButtonType.Capsule)
      .margin({
        top: 20
      })
      .width('50%')
      .height('10%')
      .backgroundColor('#0D9FFB')
      .onClick(() => {
        huksAbort()
      })
    }
    .width('100%')
    .height('100%')
  }
}
```

## huks.abort

abort(handle: number, options: HuksOptions) : Promise\<HuksResult>;

abort操作密钥接口，使用Promise方式异步返回结果。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Security.Huks。

**参数：**

| 参数名   | 类型                   | 必填 | 说明                                  |
| -------- | ---------------------- | ---- | ------------------------------------- |
| handle | number           | 是   | Abort操作的handle。 |
| options  | [HuksOptions](#huksoptions) | 是   | Abort操作的参数集合。 |
| promise | Promise\<[HuksResult](#huksresult)> | 是 | 将Abort操作的结果添加到密钥管理系统的回调。 |

**示例：**

```js
/* huks.init, huks.update, huks.finish为三段式接口，需要一起使用，当huks.init和huks.update
 * 以及huks.finish操作中的任一阶段发生错误时，都需要调用huks.abort来终止密钥的使用。
 *
 * 以下以RSA1024密钥的promise操作使用为例
 */
import router from '@system.router';
import huks from '@ohos.security.huks';

async function routePage() {
  let options = {
    uri: 'pages/second'
  }
  try {
    await router.push(options)
  } catch (err) {
    console.error(`fail callback, code: ${err.code}, msg: ${err.msg}`)
  }
}

var keyalias = "HuksDemoRSA";
var properties = new Array();
var options = {
  properties: properties,
  inData: new Uint8Array(0)
};
var handle;
var resultMessage = "";
function stringToUint8Array(str) {
  var arr = [];
  for (var i = 0, j = str.length; i < j; ++i) {
    arr.push(str.charCodeAt(i));
  }
  var tmpUint8Array = new Uint8Array(arr);
  return tmpUint8Array;
}

async function generateKey() {
  properties[0] = {
    tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
    value: huks.HuksKeyAlg.HUKS_ALG_RSA
  };
  properties[1] = {
    tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
    value: huks.HuksKeySize.HUKS_RSA_KEY_SIZE_1024
  };
  properties[2] = {
    tag: huks.HuksTag.HUKS_TAG_PURPOSE,
    value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT
  };
  properties[3] = {
    tag: huks.HuksTag.HUKS_TAG_PADDING,
    value: huks.HuksKeyPadding.HUKS_PADDING_OAEP
  };
  properties[4] = {
    tag: huks.HuksTag.HUKS_TAG_DIGEST,
    value: huks.HuksKeyDigest.HUKS_DIGEST_SHA256
  };
  huks.generateKey(keyalias, options, function (err, data) { });
}
async function huksInit() {
  return new Promise((resolve, reject) => {
    huks.init(keyalias, options, async function (err, data) {
      if (data.errorCode === 0) {
        resultMessage = "init success!"
        handle = data.handle;
      } else {
        resultMessage = "init fail errorCode: " + data.errorCode
      }
    });
  });
}

async function huksUpdate() {
    options.inData = stringToUint8Array("huksHmacTest");
    new Promise((resolve, reject) => {
      huks.update(handle, options, function (err, data) {
        if (data.errorCode === 0) {
          resultMessage += "update success!";
        } else {
          resultMessage += "update fail!";
        }
      });
    });
    console.log(resultMessage);

}

async function huksFinish() {
  options.inData = stringToUint8Array("0");
  new Promise((resolve, reject) => {
    huks.finish(handle, options, function (err, data) {
      if (data.errorCode === 0) {
        resultMessage = "finish success!";
      } else {
        resultMessage =  "finish fail errorCode: " + data.errorCode;
      }
    });
  });
}

function huksAbort() {
  new Promise((resolve, reject) => {
    huks.abort(handle, options, function (err, data) {
      console.log(`Huks_Demo hmac huksAbort1 data ${JSON.stringify(data)}`);
      console.log(`Huks_Demo hmac huksAbort1 err ${JSON.stringify(err)}`);
    });
  });
}
@Entry
@Component
struct Index {
  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
      Text('Hello World')
        .fontSize(50)
        .fontWeight(FontWeight.Bold)
      Button() {
        Text('to Promise')
          .fontSize(20)
          .fontWeight(FontWeight.Bold)
      }.type(ButtonType.Capsule)
      .margin({
        top: 20
      })
      .width('50%')
      .height('10%')
      .backgroundColor('#0D9FFB')
      .onClick(() => {
        router.back()
      })
      Button() {
        Text('generateKey')
          .fontSize(25)
          .fontWeight(FontWeight.Bold)
      }.type(ButtonType.Capsule)
      .margin({
        top: 20
      })
      .width('50%')
      .height('10%')
      .backgroundColor('#0D9FFB')
      .onClick(() => {
        generateKey()
      })
      Button() {
        Text('Init')
          .fontSize(25)
          .fontWeight(FontWeight.Bold)
      }.type(ButtonType.Capsule)
      .margin({
        top: 20
      })
      .width('50%')
      .height('10%')
      .backgroundColor('#0D9FFB')
      .onClick(() => {
        huksInit()
      })
      Button() {
        Text('Update')
          .fontSize(25)
          .fontWeight(FontWeight.Bold)
      }.type(ButtonType.Capsule)
      .margin({
        top: 20
      })
      .width('50%')
      .height('10%')
      .backgroundColor('#0D9FFB')
      .onClick(() => {
        huksUpdate()
      })
      Button() {
        Text('Finish')
          .fontSize(25)
          .fontWeight(FontWeight.Bold)
      }.type(ButtonType.Capsule)
      .margin({
        top: 20
      })
      .width('50%')
      .height('10%')
      .backgroundColor('#0D9FFB')
      .onClick(() => {
        huksFinish()
      })
      Button() {
        Text('Abort')
          .fontSize(25)
          .fontWeight(FontWeight.Bold)
      }.type(ButtonType.Capsule)
      .margin({
        top: 20
      })
      .width('50%')
      .height('10%')
      .backgroundColor('#0D9FFB')
      .onClick(() => {
        huksAbort()
      })
    }
    .width('100%')
    .height('100%')
  }
}
```

## HuksParam

调用接口使用的options中的properties数组中的param。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Security.Huks。

| 参数名 | 类型                                | 必填 | 说明       |
| ------ | ----------------------------------- | ---- | ---------- |
| tag    | HuksTag                             | 是   | 标签       |
| value  | boolean\|number\|bigint\|Uint8Array | 是   | 标签对应值 |

## HuksOptions

调用接口使用的options。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Security.Huks。

| 参数名     | 类型              | 必填 | 说明                     |
| ---------- | ----------------- | ---- | ------------------------ |
| properties | Array\<HuksParam> | 否   | 属性,存HuksParam的数组。 |
| inData     | Uint8Array        | 否   | 输入数据。               |

## HuksHandle

huks Handle结构体。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Security.Huks。

| 参数名     | 类型             | 必填 | 说明     |
| ---------- | ---------------- | ---- | -------- |
| errorCode  | number           | 是   | 错误码 |
| handle    | number       | 是 | handle值 |
| token | Uint8Array | 否 | 预留字段 |


## HuksResult

调用接口返回的result。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Security.Huks。



| 参数名     | 类型              | 必填 | 说明     |
| ---------- | ----------------- | ---- | -------- |
| errorCode  | number            | 是   | 错误码   |
| outData    | Uint8Array        | 否   | 输出数据 |
| properties | Array\<HuksParam> | 否   | 属性     |
| certChains | Array\<string>    | 否   | 证书链   |

