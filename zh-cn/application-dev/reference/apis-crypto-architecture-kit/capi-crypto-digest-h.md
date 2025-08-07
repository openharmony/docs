# crypto_digest.h

<!--Kit: Crypto Architecture Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--SE: @lanming-->
<!--TSE: @PAFT-->

## 概述

定义摘要算法API。

**引用文件：** <CryptoArchitectureKit/crypto_digest.h>

**库：** libohcrypto.so

**系统能力：** SystemCapability.Security.CryptoFramework

**起始版本：** 12

**相关模块：** [CryptoDigestApi](capi-cryptodigestapi.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_CryptoDigest](capi-cryptodigestapi-oh-cryptodigest.md) | OH_CryptoDigest | 定义摘要结构体。 |

### 函数

| 名称 | 描述 |
| -- | -- |
| [OH_Crypto_ErrCode OH_CryptoDigest_Create(const char *algoName, OH_CryptoDigest **ctx)](#oh_cryptodigest_create) | 根据给定的算法名称创建一个摘要实例。 |
| [OH_Crypto_ErrCode OH_CryptoDigest_Update(OH_CryptoDigest *ctx, Crypto_DataBlob *in)](#oh_cryptodigest_update) | 更新摘要数据。 |
| [OH_Crypto_ErrCode OH_CryptoDigest_Final(OH_CryptoDigest *ctx, Crypto_DataBlob *out)](#oh_cryptodigest_final) | 完成摘要计算。 |
| [uint32_t OH_CryptoDigest_GetLength(OH_CryptoDigest *ctx)](#oh_cryptodigest_getlength) | 获取摘要长度。 |
| [const char *OH_CryptoDigest_GetAlgoName(OH_CryptoDigest *ctx)](#oh_cryptodigest_getalgoname) | 获取摘要算法名称。 |
| [void OH_DigestCrypto_Destroy(OH_CryptoDigest *ctx)](#oh_digestcrypto_destroy) | 销毁摘要实例。 |

## 函数说明

### OH_CryptoDigest_Create()

```
OH_Crypto_ErrCode OH_CryptoDigest_Create(const char *algoName, OH_CryptoDigest **ctx)
```

**描述**

根据给定的算法名称创建一个摘要实例。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char *algoName | 用于生成摘要实例的算法名称。<br> 例如"SHA256"。 |
| [OH_CryptoDigest](capi-cryptodigestapi-oh-cryptodigest.md) **ctx | 指向摘要实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | CRYPTO_SUCCESS：操作成功。<br>         CRYPTO_INVALID_PARAMS：参数无效。<br>         CRYPTO_NOT_SUPPORTED：操作不支持。<br>         CRYPTO_MEMORY_ERROR：内存错误。<br>         CRYPTO_OPERTION_ERROR：调用三方算法库API出错。 |

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
| [OH_CryptoDigest](capi-cryptodigestapi-oh-cryptodigest.md) *ctx | 指向摘要实例。 |
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *in | 传入的消息。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | CRYPTO_SUCCESS：操作成功。<br>         CRYPTO_INVALID_PARAMS：参数无效。<br>         CRYPTO_NOT_SUPPORTED：操作不支持。<br>         CRYPTO_MEMORY_ERROR：内存错误。<br>         CRYPTO_OPERTION_ERROR：调用三方算法库API出错。 |

**参考：**

[OH_CryptoDigest_Final](capi-crypto-digest-h.md#oh_cryptodigest_final)


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
| [OH_CryptoDigest](capi-cryptodigestapi-oh-cryptodigest.md) *ctx | 指向摘要实例。 |
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *out | 返回的Md的计算结果。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | CRYPTO_SUCCESS：操作成功。<br>         CRYPTO_INVALID_PARAMS：参数无效。<br>         CRYPTO_NOT_SUPPORTED：操作不支持。<br>         CRYPTO_MEMORY_ERROR：内存错误。<br>         CRYPTO_OPERTION_ERROR：调用三方算法库API出错。 |

**参考：**

[OH_CryptoDigest_Update](capi-crypto-digest-h.md#oh_cryptodigest_update)


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
| [OH_CryptoDigest](capi-cryptodigestapi-oh-cryptodigest.md) *ctx | 指向摘要实例。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| uint32_t | 返回摘要长度。<br>        如果输入参数ctx为NULL，则返回401，其他情况下返回0。 |

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
| [OH_CryptoDigest](capi-cryptodigestapi-oh-cryptodigest.md) *ctx | 指向摘要实例。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| const char * | 返回摘要算法名称。 |

### OH_DigestCrypto_Destroy()

```
void OH_DigestCrypto_Destroy(OH_CryptoDigest *ctx)
```

**描述**

销毁摘要实例。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoDigest](capi-cryptodigestapi-oh-cryptodigest.md) *ctx | 指向摘要实例。 |


