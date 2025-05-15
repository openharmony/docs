# crypto_digest.h

## 概述

定义摘要API。

**库：** libohcrypto.so

**系统能力：** SystemCapability.Security.CryptoFramework

**起始版本：** 12

**相关模块：** [CryptoDigestApi](capi-cryptodigestapi.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_CryptoDigest](capi-oh-cryptodigest.md) | OH_CryptoDigest | 定义摘要结构。 |

### 函数

| 名称 | 描述 |
| -- | -- |
| [OH_Crypto_ErrCode OH_CryptoDigest_Create(const char *algoName, OH_CryptoDigest **ctx)](#oh_cryptodigest_create) | 根据给定的算法名称创建摘要上下文。 |
| [OH_Crypto_ErrCode OH_CryptoDigest_Update(OH_CryptoDigest *ctx, Crypto_DataBlob *in)](#oh_cryptodigest_update) | 更新摘要数据。 |
| [OH_Crypto_ErrCode OH_CryptoDigest_Final(OH_CryptoDigest *ctx, Crypto_DataBlob *out)](#oh_cryptodigest_final) | 完成摘要计算。 |
| [uint32_t OH_CryptoDigest_GetLength(OH_CryptoDigest *ctx)](#oh_cryptodigest_getlength) | 获取摘要长度。 |
| [const char *OH_CryptoDigest_GetAlgoName(OH_CryptoDigest *ctx)](#oh_cryptodigest_getalgoname) | 获取摘要算法名称。 |
| [void OH_DigestCrypto_Destroy(OH_CryptoDigest *ctx)](#oh_digestcrypto_destroy) | 销毁摘要上下文。 |

## 函数说明

### OH_CryptoDigest_Create()

```
OH_Crypto_ErrCode OH_CryptoDigest_Create(const char *algoName, OH_CryptoDigest **ctx)
```

**描述**

根据给定的算法名称创建摘要上下文。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char *algoName | algoName 用于生成摘要上下文的算法名称。\n例如"SHA256"。 |
| [OH_CryptoDigest](capi-oh-cryptodigest.md) **ctx | ctx 指向摘要上下文的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h#oh_crypto_errcode) | [OH_Crypto_ErrCode](capi-crypto-common-h#oh_crypto_errcode): <br>         CRYPTO_SUCCESS = 0 : 操作成功。<br>         CRYPTO_INVALID_PARAMS = 401 : 参数无效。<br>         CRYPTO_NOT_SUPPORTED = 801 : 操作不支持。<br>         CRYPTO_MEMORY_ERROR = 17620001 : 内存错误。<br>         CRYPTO_OPERTION_ERROR = 17630001 : 调用三方算法库API出错。 |

### OH_CryptoDigest_Update()

```
OH_Crypto_ErrCode OH_CryptoDigest_Update(OH_CryptoDigest *ctx, Crypto_DataBlob *in)
```

**描述**

更新摘要数据。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoDigest](capi-oh-cryptodigest.md) *ctx | ctx 指向摘要实例。 |
| [Crypto_DataBlob](capi-crypto-common-hcrypto_datablob.md) *in | in 传入的消息。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h#oh_crypto_errcode) | [OH_Crypto_ErrCode](capi-crypto-common-h#oh_crypto_errcode): <br>         CRYPTO_SUCCESS = 0 : 操作成功。<br>         CRYPTO_INVALID_PARAMS = 401 : 参数无效。<br>         CRYPTO_NOT_SUPPORTED = 801 : 操作不支持。<br>         CRYPTO_MEMORY_ERROR = 17620001 : 内存错误。<br>         CRYPTO_OPERTION_ERROR = 17630001 : 调用三方算法库API出错。 |

**参考：**

[OH_CryptoDigest_Final](#oh_cryptodigest_final)

### OH_CryptoDigest_Final()

```
OH_Crypto_ErrCode OH_CryptoDigest_Final(OH_CryptoDigest *ctx, Crypto_DataBlob *out)
```

**描述**

完成摘要计算。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoDigest](capi-oh-cryptodigest.md) *ctx | ctx 指向摘要实例。 |
| [Crypto_DataBlob](capi-crypto-common-hcrypto_datablob.md) *out | out 返回的Md的计算结果。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h#oh_crypto_errcode) | [OH_Crypto_ErrCode](capi-crypto-common-h#oh_crypto_errcode): <br>         CRYPTO_SUCCESS = 0 : 操作成功。<br>         CRYPTO_INVALID_PARAMS = 401 : 参数无效。<br>         CRYPTO_NOT_SUPPORTED = 801 : 操作不支持。<br>         CRYPTO_MEMORY_ERROR = 17620001 : 内存错误。<br>         CRYPTO_OPERTION_ERROR = 17630001 : 调用三方算法库API出错。 |

**参考：**

[OH_CryptoDigest_Update](#oh_cryptodigest_update)

### OH_CryptoDigest_GetLength()

```
uint32_t OH_CryptoDigest_GetLength(OH_CryptoDigest *ctx)
```

**描述**

获取摘要长度。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoDigest](capi-oh-cryptodigest.md) *ctx | ctx 指向摘要实例。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| uint32_t | [OH_Crypto_ErrCode](capi-crypto-common-h#oh_crypto_errcode): <br>         CRYPTO_SUCCESS = 0 : 操作成功。<br>         CRYPTO_INVALID_PARAMS = 401 : 参数无效。<br>         CRYPTO_NOT_SUPPORTED = 801 : 操作不支持。<br>         CRYPTO_MEMORY_ERROR = 17620001 : 内存错误。<br>         CRYPTO_OPERTION_ERROR = 17630001 : 调用三方算法库API出错。 |

### OH_CryptoDigest_GetAlgoName()

```
const char *OH_CryptoDigest_GetAlgoName(OH_CryptoDigest *ctx)
```

**描述**

获取摘要算法名称。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoDigest](capi-oh-cryptodigest.md) *ctx | ctx 摘要上下文。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| const | 返回摘要算法名称。 |

### OH_DigestCrypto_Destroy()

```
void OH_DigestCrypto_Destroy(OH_CryptoDigest *ctx)
```

**描述**

销毁摘要上下文。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoDigest](capi-oh-cryptodigest.md) *ctx | ctx 指向摘要实例。 |


