# crypto_mac.h

<!--Kit: Crypto Architecture Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--Designer: @lanming-->
<!--Tester: @PAFT-->
<!--Adviser: @zengyawen-->

## 概述

定义MAC接口。

**引用文件：** <CryptoArchitectureKit/crypto_mac.h>

**库：** libohcrypto.so

**系统能力：** SystemCapability.Security.CryptoFramework

**起始版本：** 20

**相关模块：** [CryptoMacApi](capi-cryptomacapi.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_CryptoMac](capi-cryptomacapi-oh-cryptomac.md) | OH_CryptoMac | 定义MAC结构。 |

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [CryptoMac_ParamType](#cryptomac_paramtype) | CryptoMac_ParamType | 定义MAC算法参数类型。 |

### 函数

| 名称 | 描述 |
| -- | -- |
| [OH_Crypto_ErrCode OH_CryptoMac_Create(const char *algoName, OH_CryptoMac **ctx)](#oh_cryptomac_create) | 根据给定的算法名称创建MAC实例。 |
| [OH_Crypto_ErrCode OH_CryptoMac_SetParam(OH_CryptoMac *ctx, CryptoMac_ParamType type, const Crypto_DataBlob *value)](#oh_cryptomac_setparam) | 设置MAC参数。 |
| [OH_Crypto_ErrCode OH_CryptoMac_Init(OH_CryptoMac *ctx, const OH_CryptoSymKey *key)](#oh_cryptomac_init) | 使用对称密钥初始化MAC实例。 |
| [OH_Crypto_ErrCode OH_CryptoMac_Update(OH_CryptoMac *ctx, const Crypto_DataBlob *in)](#oh_cryptomac_update) | 更新MAC实例。 |
| [OH_Crypto_ErrCode OH_CryptoMac_Final(OH_CryptoMac *ctx, Crypto_DataBlob *out)](#oh_cryptomac_final) | 完成MAC操作。 |
| [OH_Crypto_ErrCode OH_CryptoMac_GetLength(OH_CryptoMac *ctx, uint32_t *length)](#oh_cryptomac_getlength) | 获取MAC长度。 |
| [void OH_CryptoMac_Destroy(OH_CryptoMac *ctx)](#oh_cryptomac_destroy) | 销毁MAC实例。 |

## 枚举类型说明

### CryptoMac_ParamType

```
enum CryptoMac_ParamType
```

**描述**

定义MAC算法参数类型。

**起始版本：** 20

| 枚举项 | 描述 |
| -- | -- |
| CRYPTO_MAC_DIGEST_NAME_STR = 0 | HMAC消息认证码使用的摘要函数的算法名称，例如SHA256。 |
| CRYPTO_MAC_CIPHER_NAME_STR = 1 | CMAC消息认证码使用的对称加密算法名称，例如AES256。 |


## 函数说明

### OH_CryptoMac_Create()

```
OH_Crypto_ErrCode OH_CryptoMac_Create(const char *algoName, OH_CryptoMac **ctx)
```

**描述**

根据给定的算法名称创建MAC实例。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char *algoName | 用于生成MAC实例的算法名称。<br> 例如"HMAC"、"CMAC"。 |
| [OH_CryptoMac](capi-cryptomacapi-oh-cryptomac.md) **ctx | MAC实例。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | CRYPTO_SUCCESS：操作成功。<br>         CRYPTO_NOT_SUPPORTED：操作不支持。<br>         CRYPTO_MEMORY_ERROR：内存错误。<br>         CRYPTO_PARAMETER_CHECK_FAILED：参数检查失败。<br>         CRYPTO_OPERATION_ERROR：调用三方算法库API出错。 |

### OH_CryptoMac_SetParam()

```
OH_Crypto_ErrCode OH_CryptoMac_SetParam(OH_CryptoMac *ctx, CryptoMac_ParamType type, const Crypto_DataBlob *value)
```

**描述**

设置MAC参数。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoMac](capi-cryptomacapi-oh-cryptomac.md) *ctx | MAC实例。 |
| [CryptoMac_ParamType](#cryptomac_paramtype) type | MAC参数类型。 |
| [const Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *value | MAC参数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | CRYPTO_SUCCESS：操作成功。<br>         CRYPTO_NOT_SUPPORTED：操作不支持。<br>         CRYPTO_MEMORY_ERROR：内存错误。<br>         CRYPTO_PARAMETER_CHECK_FAILED：参数检查失败。<br>         CRYPTO_OPERATION_ERROR：调用三方算法库API出错。 |

### OH_CryptoMac_Init()

```
OH_Crypto_ErrCode OH_CryptoMac_Init(OH_CryptoMac *ctx, const OH_CryptoSymKey *key)
```

**描述**

使用对称密钥初始化MAC实例。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoMac](capi-cryptomacapi-oh-cryptomac.md) *ctx | MAC实例。 |
| [const OH_CryptoSymKey](capi-cryptosymkeyapi-oh-cryptosymkey.md) *key | 对称密钥。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | CRYPTO_SUCCESS：操作成功。<br>         CRYPTO_NOT_SUPPORTED：操作不支持。<br>         CRYPTO_MEMORY_ERROR：内存错误。<br>         CRYPTO_PARAMETER_CHECK_FAILED：参数检查失败。<br>         CRYPTO_OPERATION_ERROR：调用三方算法库API出错。 |

**参考：**

[OH_CryptoMac_Update](#oh_cryptomac_update)

[OH_CryptoMac_Final](#oh_cryptomac_final)


### OH_CryptoMac_Update()

```
OH_Crypto_ErrCode OH_CryptoMac_Update(OH_CryptoMac *ctx, const Crypto_DataBlob *in)
```

**描述**

更新MAC实例。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoMac](capi-cryptomacapi-oh-cryptomac.md) *ctx | MAC实例。 |
| [const Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *in | 需要更新的数据。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | CRYPTO_SUCCESS：操作成功。<br>         CRYPTO_NOT_SUPPORTED：操作不支持。<br>         CRYPTO_MEMORY_ERROR：内存错误。<br>         CRYPTO_PARAMETER_CHECK_FAILED：参数检查失败。<br>         CRYPTO_OPERATION_ERROR：调用三方算法库API出错。 |

**参考：**

[OH_CryptoMac_Init](#oh_cryptomac_init)

[OH_CryptoMac_Final](#oh_cryptomac_final)


### OH_CryptoMac_Final()

```
OH_Crypto_ErrCode OH_CryptoMac_Final(OH_CryptoMac *ctx, Crypto_DataBlob *out)
```

**描述**

完成MAC操作。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoMac](capi-cryptomacapi-oh-cryptomac.md) *ctx | MAC实例。 |
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *out | MAC值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | CRYPTO_SUCCESS：操作成功。<br>         CRYPTO_NOT_SUPPORTED：操作不支持。<br>         CRYPTO_MEMORY_ERROR：内存错误。<br>         CRYPTO_PARAMETER_CHECK_FAILED：参数检查失败。<br>         CRYPTO_OPERATION_ERROR：调用三方算法库API出错。 |

**参考：**

[OH_CryptoMac_Init](#oh_cryptomac_init)

[OH_CryptoMac_Update](#oh_cryptomac_update)


### OH_CryptoMac_GetLength()

```
OH_Crypto_ErrCode OH_CryptoMac_GetLength(OH_CryptoMac *ctx, uint32_t *length)
```

**描述**

获取MAC长度。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoMac](capi-cryptomacapi-oh-cryptomac.md) *ctx | MAC实例。 |
| uint32_t *length | MAC长度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | CRYPTO_SUCCESS：操作成功。<br>         CRYPTO_NOT_SUPPORTED：操作不支持。<br>         CRYPTO_MEMORY_ERROR：内存错误。<br>         CRYPTO_PARAMETER_CHECK_FAILED：参数检查失败。<br>         CRYPTO_OPERATION_ERROR：调用三方算法库API出错。 |

### OH_CryptoMac_Destroy()

```
void OH_CryptoMac_Destroy(OH_CryptoMac *ctx)
```

**描述**

销毁MAC实例。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoMac](capi-cryptomacapi-oh-cryptomac.md) *ctx | MAC实例。 |


