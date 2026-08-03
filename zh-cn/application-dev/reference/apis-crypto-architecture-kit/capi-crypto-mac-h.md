# crypto_mac.h

<!--Kit: Crypto Architecture Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--Designer: @lanming-->
<!--Tester: @PAFT-->
<!--Adviser: @zengyawen-->

## 概述

定义消息认证码接口。

**引用文件：** <CryptoArchitectureKit/crypto_mac.h>

**库：** libohcrypto.so

**系统能力：** SystemCapability.Security.CryptoFramework

**起始版本：** 20

**相关模块：** [CryptoMacApi](capi-cryptomacapi.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_CryptoMac](capi-cryptomacapi-oh-cryptomac.md) | OH_CryptoMac | MAC结构体，表示MAC上下文。 |

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [CryptoMac_ParamType](#cryptomac_paramtype) | CryptoMac_ParamType | 定义MAC算法参数类型。 |

### 函数

| 名称 | 描述 |
| -- | -- |
| [OH_Crypto_ErrCode OH_CryptoMac_Create(const char *algoName, OH_CryptoMac **ctx)](#oh_cryptomac_create) | 根据给定的算法名称创建MAC上下文。<br> 注意：创建的资源必须通过[OH_CryptoMac_Destroy](capi-crypto-mac-h.md#oh_cryptomac_destroy)销毁。  |
| [OH_Crypto_ErrCode OH_CryptoMac_SetParam(OH_CryptoMac *ctx, CryptoMac_ParamType type, const Crypto_DataBlob *value)](#oh_cryptomac_setparam) | 设置MAC上下文的指定参数。 |
| [OH_Crypto_ErrCode OH_CryptoMac_Init(OH_CryptoMac *ctx, const OH_CryptoSymKey *key)](#oh_cryptomac_init) | 使用对称密钥初始化MAC上下文。 |
| [OH_Crypto_ErrCode OH_CryptoMac_Update(OH_CryptoMac *ctx, const Crypto_DataBlob *in)](#oh_cryptomac_update) | 更新MAC数据。 |
| [OH_Crypto_ErrCode OH_CryptoMac_Final(OH_CryptoMac *ctx, Crypto_DataBlob *out)](#oh_cryptomac_final) | 结束MAC操作。<br> 注意：使用完成后必须通过[OH_Crypto_FreeDataBlob](capi-crypto-common-h.md#oh_crypto_freedatablob)释放out内存。 |
| [OH_Crypto_ErrCode OH_CryptoMac_GetLength(OH_CryptoMac *ctx, uint32_t *length)](#oh_cryptomac_getlength) | 获取MAC结果的长度。 |
| [void OH_CryptoMac_Destroy(OH_CryptoMac *ctx)](#oh_cryptomac_destroy) | 销毁MAC上下文。 |

## 枚举类型说明

### CryptoMac_ParamType

```c
enum CryptoMac_ParamType
```

**描述**

定义MAC算法参数类型。

**起始版本：** 20

| 枚举项 | 描述 |
| -- | -- |
| CRYPTO_MAC_DIGEST_NAME_STR = 0 | HMAC的消息摘要算法名称，通过[OH_CryptoMac_SetParam](capi-crypto-mac-h.md#oh_cryptomac_setparam)设置。取值："SHA1"、"SHA224"、"SHA256"、"SHA384"、"SHA512"、"SM3"、"MD5"。从API version 26.0.0开始支持"SHA3-256"、"SHA3-384"、"SHA3-512"。<br>**起始版本：** 20 |
| CRYPTO_MAC_CIPHER_NAME_STR = 1 | CMAC的对称加密算法名称，通过[OH_CryptoMac_SetParam](capi-crypto-mac-h.md#oh_cryptomac_setparam)设置。取值："AES128"、"AES256"。<br>**起始版本：** 20 |


## 函数说明

### OH_CryptoMac_Create()

```c
OH_Crypto_ErrCode OH_CryptoMac_Create(const char *algoName, OH_CryptoMac **ctx)
```

**描述**

根据给定的算法名称创建MAC上下文。

注意：创建的资源必须通过[OH_CryptoMac_Destroy](capi-crypto-mac-h.md#oh_cryptomac_destroy)销毁。

**起始版本：** 20

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char *algoName | [in] MAC算法名称，不能为NULL。支持“HMAC”和“CMAC”。 |
| [OH_CryptoMac](capi-cryptomacapi-oh-cryptomac.md) **ctx | [out] 指向MAC上下文指针的指针。ctx不能为NULL，*ctx必须为NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | CRYPTO_SUCCESS：操作成功。<br>CRYPTO_PARAMETER_CHECK_FAILED：algoName或ctx为NULL，或algoName不是"HMAC"或"CMAC"。<br>CRYPTO_NOT_SUPPORTED：不支持的操作或算法。<br>CRYPTO_MEMORY_ERROR：内存操作失败。<br>CRYPTO_OPERTION_ERROR：密码操作失败。 |

**参考：**

[OH_CryptoMac_SetParam](capi-crypto-mac-h.md#oh_cryptomac_setparam) 设置MAC上下文的指定参数。


### OH_CryptoMac_SetParam()

```c
OH_Crypto_ErrCode OH_CryptoMac_SetParam(OH_CryptoMac *ctx, CryptoMac_ParamType type, const Crypto_DataBlob *value)
```

**描述**

设置MAC上下文的指定参数。

**起始版本：** 20

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoMac](capi-cryptomacapi-oh-cryptomac.md) *ctx | [in] MAC上下文。不能为NULL。 |
| [CryptoMac_ParamType](capi-crypto-mac-h.md#cryptomac_paramtype) type | [in] MAC参数类型。 |
| [const Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *value | [in] 参数值。本接口会对value中的数据进行深拷贝，调用者在接口返回后可立即释放value。不能为NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | CRYPTO_SUCCESS：操作成功。<br>CRYPTO_PARAMETER_CHECK_FAILED：ctx、value或value->data为NULL，type对当前MAC算法无效，或摘要/加密算法名称不支持。<br>CRYPTO_NOT_SUPPORTED：不支持的操作或算法。<br>CRYPTO_MEMORY_ERROR：参数拷贝内存分配失败。<br>CRYPTO_OPERTION_ERROR：密码操作失败。 |

**参考：**

[OH_CryptoMac_Init](capi-crypto-mac-h.md#oh_cryptomac_init) 使用对称密钥初始化MAC上下文。


### OH_CryptoMac_Init()

```c
OH_Crypto_ErrCode OH_CryptoMac_Init(OH_CryptoMac *ctx, const OH_CryptoSymKey *key)
```

**描述**

使用对称密钥初始化MAC上下文。

**起始版本：** 20

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoMac](capi-cryptomacapi-oh-cryptomac.md) *ctx | [in] MAC上下文。不能为NULL。 |
| [const OH_CryptoSymKey](capi-cryptosymkeyapi-oh-cryptosymkey.md) *key | [in] 对称密钥。不能为NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | CRYPTO_SUCCESS：操作成功。<br>CRYPTO_PARAMETER_CHECK_FAILED：ctx或key为NULL。<br>CRYPTO_NOT_SUPPORTED：不支持的操作或算法。<br>CRYPTO_MEMORY_ERROR：内存操作失败。<br>CRYPTO_OPERTION_ERROR：MAC初始化失败。可能的原因：密钥长度与算法不匹配（例如CMAC使用AES-128需要16字节密钥）。 |

**参考：**

[OH_CryptoMac_Update](capi-crypto-mac-h.md#oh_cryptomac_update) 更新MAC数据。


### OH_CryptoMac_Update()

```c
OH_Crypto_ErrCode OH_CryptoMac_Update(OH_CryptoMac *ctx, const Crypto_DataBlob *in)
```

**描述**

更新MAC数据。

**起始版本：** 20

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoMac](capi-cryptomacapi-oh-cryptomac.md) *ctx | [in] MAC上下文。不能为NULL。 |
| [const Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *in | [in] 待更新的数据。不能为NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | CRYPTO_SUCCESS：操作成功。<br>CRYPTO_PARAMETER_CHECK_FAILED：ctx或in为NULL。<br>CRYPTO_NOT_SUPPORTED：不支持的操作或算法。<br>CRYPTO_MEMORY_ERROR：内存操作失败。<br>CRYPTO_OPERTION_ERROR：MAC更新失败。 |

**参考：**

[OH_CryptoMac_Final](capi-crypto-mac-h.md#oh_cryptomac_final) 结束MAC操作。


### OH_CryptoMac_Final()

```c
OH_Crypto_ErrCode OH_CryptoMac_Final(OH_CryptoMac *ctx, Crypto_DataBlob *out)
```

**描述**

结束MAC操作。

注意：使用完成后必须通过[OH_Crypto_FreeDataBlob](capi-crypto-common-h.md#oh_crypto_freedatablob)释放out内存。

**起始版本：** 20

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoMac](capi-cryptomacapi-oh-cryptomac.md) *ctx | [in] MAC上下文。不能为NULL。 |
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *out | [out] 指向用于存储MAC结果的Crypto_DataBlob结构体的指针。不能为NULL。调用前需将out初始化为{0}，不要预分配out->data内存。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | CRYPTO_SUCCESS：操作成功。<br>CRYPTO_PARAMETER_CHECK_FAILED：ctx或out为NULL。<br>CRYPTO_NOT_SUPPORTED：不支持的操作或算法。<br>CRYPTO_MEMORY_ERROR：内存操作失败。<br>CRYPTO_OPERTION_ERROR：MAC完成操作失败。 |

### OH_CryptoMac_GetLength()

```c
OH_Crypto_ErrCode OH_CryptoMac_GetLength(OH_CryptoMac *ctx, uint32_t *length)
```

**描述**

获取MAC结果的长度。

**起始版本：** 20

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoMac](capi-cryptomacapi-oh-cryptomac.md) *ctx | [in] MAC上下文。不能为NULL。 |
| uint32_t *length | [out] MAC结果的字节长度。不能为NULL。由调用者分配内存。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | CRYPTO_SUCCESS：操作成功。<br>CRYPTO_PARAMETER_CHECK_FAILED：ctx或length为NULL。<br>CRYPTO_NOT_SUPPORTED：不支持的操作或算法。<br>CRYPTO_MEMORY_ERROR：内存操作失败。<br>CRYPTO_OPERTION_ERROR：密码操作失败。 |

### OH_CryptoMac_Destroy()

```c
void OH_CryptoMac_Destroy(OH_CryptoMac *ctx)
```

**描述**

销毁MAC上下文。

**起始版本：** 20

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoMac](capi-cryptomacapi-oh-cryptomac.md) *ctx | [in] MAC上下文。 |


