# crypto_digest.h

<!--Kit: Crypto Architecture Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--Designer: @lanming-->
<!--Tester: @PAFT-->
<!--Adviser: @zengyawen-->

## 概述

定义摘要算法接口。

**引用文件：** <CryptoArchitectureKit/crypto_digest.h>

**库：** libohcrypto.so

**系统能力：** SystemCapability.Security.CryptoFramework

**起始版本：** 12

**相关模块：** [CryptoDigestApi](capi-cryptodigestapi.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_CryptoDigest](capi-cryptodigestapi-oh-cryptodigest.md) | OH_CryptoDigest | 摘要结构体，表示摘要上下文。 |

### 函数

| 名称 | 描述 |
| -- | -- |
| [OH_Crypto_ErrCode OH_CryptoDigest_Create(const char *algoName, OH_CryptoDigest **ctx)](#oh_cryptodigest_create) | 根据给定的算法名称创建摘要上下文。<br> 注意：创建的资源必须通过[OH_DigestCrypto_Destroy](capi-crypto-digest-h.md#oh_digestcrypto_destroy)销毁。  |
| [OH_Crypto_ErrCode OH_CryptoDigest_Update(OH_CryptoDigest *ctx, Crypto_DataBlob *in)](#oh_cryptodigest_update) | 更新摘要数据。 |
| [OH_Crypto_ErrCode OH_CryptoDigest_Final(OH_CryptoDigest *ctx, Crypto_DataBlob *out)](#oh_cryptodigest_final) | 完成摘要操作，输出摘要结果。<br> 注意：使用完成后必须通过[OH_Crypto_FreeDataBlob](capi-crypto-common-h.md#oh_crypto_freedatablob)释放out内存。 |
| [uint32_t OH_CryptoDigest_GetLength(OH_CryptoDigest *ctx)](#oh_cryptodigest_getlength) | 获取摘要结果的长度。 |
| [const char *OH_CryptoDigest_GetAlgoName(OH_CryptoDigest *ctx)](#oh_cryptodigest_getalgoname) | 获取摘要上下文的算法名称。 |
| [void OH_DigestCrypto_Destroy(OH_CryptoDigest *ctx)](#oh_digestcrypto_destroy) | 销毁摘要上下文。 |

## 函数说明

### OH_CryptoDigest_Create()

```c
OH_Crypto_ErrCode OH_CryptoDigest_Create(const char *algoName, OH_CryptoDigest **ctx)
```

**描述**

根据给定的算法名称创建摘要上下文。

注意：创建的资源必须通过[OH_DigestCrypto_Destroy](capi-crypto-digest-h.md#oh_digestcrypto_destroy)销毁。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char *algoName | [in] 摘要算法名称，不能为NULL。取值如下：<br>- 从API version 12开始支持"SHA1"、"SHA224"、"SHA256"、"SHA384"、"SHA512"、"MD5"、"SM3"。<br>- 从API version 22开始支持"SHA3-256"、"SHA3-384"、"SHA3-512"。 |
| [OH_CryptoDigest](capi-cryptodigestapi-oh-cryptodigest.md) **ctx | [out] 指向摘要上下文指针的指针。ctx不能为NULL，*ctx必须为NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | CRYPTO_SUCCESS：操作成功。<br>CRYPTO_INVALID_PARAMS：ctx为NULL、algoName为NULL、或algoName不是支持的摘要算法名称。<br>CRYPTO_NOT_SUPPORTED：不支持的操作或算法。<br>CRYPTO_MEMORY_ERROR：内存分配失败。<br>CRYPTO_OPERTION_ERROR：摘要操作失败。 |

**参考：**

[OH_CryptoDigest_Update](capi-crypto-digest-h.md#oh_cryptodigest_update) 更新摘要数据。


### OH_CryptoDigest_Update()

```c
OH_Crypto_ErrCode OH_CryptoDigest_Update(OH_CryptoDigest *ctx, Crypto_DataBlob *in)
```

**描述**

更新摘要数据。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoDigest](capi-cryptodigestapi-oh-cryptodigest.md) *ctx | [in] 摘要上下文。不能为NULL。 |
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *in | [in] 待计算摘要的数据。不能为NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | CRYPTO_SUCCESS：操作成功。<br>CRYPTO_INVALID_PARAMS：ctx或in为NULL。<br>CRYPTO_NOT_SUPPORTED：不支持的操作或算法。<br>CRYPTO_MEMORY_ERROR：内存操作失败。<br>CRYPTO_OPERTION_ERROR：摘要更新失败。 |

**参考：**

[OH_CryptoDigest_Final](capi-crypto-digest-h.md#oh_cryptodigest_final) 完成摘要操作，输出摘要结果。


### OH_CryptoDigest_Final()

```c
OH_Crypto_ErrCode OH_CryptoDigest_Final(OH_CryptoDigest *ctx, Crypto_DataBlob *out)
```

**描述**

完成摘要操作，输出摘要结果。

注意：使用完成后必须通过[OH_Crypto_FreeDataBlob](capi-crypto-common-h.md#oh_crypto_freedatablob)释放out内存。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoDigest](capi-cryptodigestapi-oh-cryptodigest.md) *ctx | [in] 摘要上下文。不能为NULL。 |
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *out | [out] 指向用于存储摘要结果的Crypto_DataBlob结构体的指针。不能为NULL。调用前需将out初始化为{0}，不要预分配out->data内存。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | CRYPTO_SUCCESS：操作成功。<br>CRYPTO_INVALID_PARAMS：ctx或out为NULL。<br>CRYPTO_NOT_SUPPORTED：不支持的操作或算法。<br>CRYPTO_MEMORY_ERROR：内存操作失败。<br>CRYPTO_OPERTION_ERROR：摘要完成操作失败。 |

### OH_CryptoDigest_GetLength()

```c
uint32_t OH_CryptoDigest_GetLength(OH_CryptoDigest *ctx)
```

**描述**

获取摘要结果的长度。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoDigest](capi-cryptodigestapi-oh-cryptodigest.md) *ctx | [in] 摘要上下文。不能为NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| uint32_t | 返回摘要结果的字节长度。 特殊说明：如果输入参数ctx为NULL，返回401；其他失败场景返回0。 |

### OH_CryptoDigest_GetAlgoName()

```c
const char *OH_CryptoDigest_GetAlgoName(OH_CryptoDigest *ctx)
```

**描述**

获取摘要上下文的算法名称。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoDigest](capi-cryptodigestapi-oh-cryptodigest.md) *ctx | [in] 摘要上下文。不能为NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| const char * | 返回摘要算法名称，不需要调用者释放，在上下文销毁后不可使用。 |

### OH_DigestCrypto_Destroy()

```c
void OH_DigestCrypto_Destroy(OH_CryptoDigest *ctx)
```

**描述**

销毁摘要上下文。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoDigest](capi-cryptodigestapi-oh-cryptodigest.md) *ctx | [in] 摘要上下文。 |


