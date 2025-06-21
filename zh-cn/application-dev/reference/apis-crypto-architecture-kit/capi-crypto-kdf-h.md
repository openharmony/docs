# crypto_kdf.h

## 概述

定义密钥派生接口。 

**库：** libohcrypto.so

**引用文件：** <CryptoArchitectureKit/crypto_kdf.h>

**系统能力：** SystemCapability.Security.CryptoFramework

**起始版本：** 20

**相关模块：** [CryptoKdfApi](capi-cryptokdfapi.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_CryptoKdf](capi-oh-cryptokdf.md) | OH_CryptoKdf | 定义密钥派生函数（KDF）结构。 |
| [OH_CryptoKdfParams](capi-oh-cryptokdfparams.md) | OH_CryptoKdfParams | 定义密钥派生函数（KDF）参数结构。 |

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [CryptoKdf_ParamType](#cryptokdf_paramtype) | CryptoKdf_ParamType | 定义密钥派生函数（KDF）参数类型。 |

### 函数

| 名称 | 描述 |
| -- | -- |
| [OH_Crypto_ErrCode OH_CryptoKdfParams_Create(const char *algoName, OH_CryptoKdfParams **params)](#oh_cryptokdfparams_create) | 创建密钥派生函数（KDF）参数。 |
| [OH_Crypto_ErrCode OH_CryptoKdfParams_SetParam(OH_CryptoKdfParams *params, CryptoKdf_ParamType type,Crypto_DataBlob *value)](#oh_cryptokdfparams_setparam) | 设置密钥派生函数（KDF）参数。 |
| [void OH_CryptoKdfParams_Destroy(OH_CryptoKdfParams *params)](#oh_cryptokdfparams_destroy) | 销毁密钥派生函数（KDF）参数。 |
| [OH_Crypto_ErrCode OH_CryptoKdf_Create(const char *algoName, OH_CryptoKdf **ctx)](#oh_cryptokdf_create) | 创建密钥派生函数（KDF）实例。 |
| [OH_Crypto_ErrCode OH_CryptoKdf_Derive(OH_CryptoKdf *ctx, const OH_CryptoKdfParams *params, int keyLen,Crypto_DataBlob *key)](#oh_cryptokdf_derive) | 派生密钥。 |
| [void OH_CryptoKdf_Destroy(OH_CryptoKdf *ctx)](#oh_cryptokdf_destroy) | 销毁密钥派生函数（KDF）实例。 |

## 枚举类型说明

### CryptoKdf_ParamType

```
enum CryptoKdf_ParamType
```

**描述**

定义密钥派生函数（KDF）参数类型。

**起始版本：** 20

| 枚举项 | 描述 |
| -- | -- |
| CRYPTO_KDF_KEY_DATABLOB = 0 | 表示KDF的密钥或密码。 |
| CRYPTO_KDF_SALT_DATABLOB = 1 | 表示KDF的盐值。 |
| CRYPTO_KDF_INFO_DATABLOB = 2 | 表示KDF的信息。 |
| CRYPTO_KDF_ITER_COUNT_INT = 3 | 表示PBKDF2的迭代次数。 |
| CRYPTO_KDF_SCRYPT_N_UINT64 = 4 | 表示SCRYPT KDF的n参数。 |
| CRYPTO_KDF_SCRYPT_R_UINT64 = 5 | 表示SCRYPT KDF的r参数。 |
| CRYPTO_KDF_SCRYPT_P_UINT64 = 6 | 表示SCRYPT KDF的p参数。 |
| CRYPTO_KDF_SCRYPT_MAX_MEM_UINT64 = 7 | 表示SCRYPT KDF的最大内存使用量。 |


## 函数说明

### OH_CryptoKdfParams_Create()

```
OH_Crypto_ErrCode OH_CryptoKdfParams_Create(const char *algoName, OH_CryptoKdfParams **params)
```

**描述**

创建密钥派生函数（KDF）参数。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char *algoName | KDF算法名称。<br>例如"HKDF\|SHA384\|EXTRACT_AND_EXPAND"、"PBKDF2\|SHA384"。 |
| [OH_CryptoKdfParams](capi-oh-cryptokdfparams.md) **params | KDF参数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | CRYPTO_SUCCESS = 0 : 操作成功。<br>         CRYPTO_INVALID_PARAMS = 401 : 参数无效。<br>         CRYPTO_NOT_SUPPORTED = 801 : 操作不支持。<br>         CRYPTO_MEMORY_ERROR = 17620001 : 内存错误。<br>         CRYPTO_OPERTION_ERROR = 17630001 : 调用三方算法库API出错。 |

### OH_CryptoKdfParams_SetParam()

```
OH_Crypto_ErrCode OH_CryptoKdfParams_SetParam(OH_CryptoKdfParams *params, CryptoKdf_ParamType type,Crypto_DataBlob *value)
```

**描述**

设置密钥派生函数（KDF）参数。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoKdfParams](capi-oh-cryptokdfparams.md) *params | KDF参数。 |
| [CryptoKdf_ParamType](#cryptokdf_paramtype) type | KDF参数类型。 |
| [Crypto_DataBlob](capi-crypto-datablob.md) *value | KDF参数值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) |     CRYPTO_SUCCESS = 0 : 操作成功。<br>         CRYPTO_INVALID_PARAMS = 401 : 参数无效。<br>         CRYPTO_NOT_SUPPORTED = 801 : 操作不支持。<br>         CRYPTO_MEMORY_ERROR = 17620001 : 内存错误。<br>         CRYPTO_OPERTION_ERROR = 17630001 : 调用三方算法库API出错。 |

### OH_CryptoKdfParams_Destroy()

```
void OH_CryptoKdfParams_Destroy(OH_CryptoKdfParams *params)
```

**描述**

销毁密钥派生函数（KDF）参数。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoKdfParams](capi-oh-cryptokdfparams.md) *params | KDF参数。 |

### OH_CryptoKdf_Create()

```
OH_Crypto_ErrCode OH_CryptoKdf_Create(const char *algoName, OH_CryptoKdf **ctx)
```

**描述**

创建密钥派生函数（KDF）实例。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char *algoName | KDF算法名称。 |
| [OH_CryptoKdf](capi-oh-cryptokdf.md) **ctx | KDF实例。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) |     CRYPTO_SUCCESS = 0 : 操作成功。<br>         CRYPTO_INVALID_PARAMS = 401 : 参数无效。<br>         CRYPTO_NOT_SUPPORTED = 801 : 操作不支持。<br>         CRYPTO_MEMORY_ERROR = 17620001 : 内存错误。<br>         CRYPTO_OPERTION_ERROR = 17630001 : 调用三方算法库API出错。 |

### OH_CryptoKdf_Derive()

```
OH_Crypto_ErrCode OH_CryptoKdf_Derive(OH_CryptoKdf *ctx, const OH_CryptoKdfParams *params, int keyLen,Crypto_DataBlob *key)
```

**描述**

派生密钥。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoKdf](capi-oh-cryptokdf.md) *ctx |KDF实例。 |
| const [OH_CryptoKdfParams](capi-oh-cryptokdfparams.md) *params | KDF参数。 |
| int keyLen | 密钥派生长度。 |
| [Crypto_DataBlob](capi-crypto-datablob.md) key | 派生出的密钥。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) |     CRYPTO_SUCCESS = 0 : 操作成功。<br>         CRYPTO_INVALID_PARAMS = 401 : 参数无效。<br>         CRYPTO_NOT_SUPPORTED = 801 : 操作不支持。<br>         CRYPTO_MEMORY_ERROR = 17620001 : 内存错误。<br>         CRYPTO_OPERTION_ERROR = 17630001 : 调用三方算法库API出错。 |

### OH_CryptoKdf_Destroy()

```
void OH_CryptoKdf_Destroy(OH_CryptoKdf *ctx)
```

**描述**

销毁密钥派生函数（KDF）实例。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoKdf](capi-oh-cryptokdf.md) *ctx |KDF实例。 |


