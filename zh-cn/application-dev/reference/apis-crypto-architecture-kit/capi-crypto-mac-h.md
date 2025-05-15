# crypto_mac.h

## 概述

定义MAC接口。

**库：** libohcrypto.so

**系统能力：** SystemCapability.Security.CryptoFramework

**起始版本：** 20

**相关模块：** [CryptoMacApi](capi-cryptomacapi.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_CryptoMac](capi-oh-cryptomac.md) | OH_CryptoMac | 定义MAC结构。 |

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [CryptoMac_ParamType](#cryptomac_paramtype) | CryptoMac_ParamType | Defines the MAC algorithm parameter type. |

### 函数

| 名称 | 描述 |
| -- | -- |
| [OH_Crypto_ErrCode OH_CryptoMac_Create(const char *algoName, OH_CryptoMac **ctx)](#oh_cryptomac_create) | 根据给定的算法名称创建MAC上下文。 |
| [OH_Crypto_ErrCode OH_CryptoMac_SetParam(OH_CryptoMac *ctx, CryptoMac_ParamType type, const Crypto_DataBlob *value)](#oh_cryptomac_setparam) | 设置MAC参数。 |
| [OH_Crypto_ErrCode OH_CryptoMac_Init(OH_CryptoMac *ctx, const OH_CryptoSymKey *key)](#oh_cryptomac_init) | 使用对称密钥初始化MAC上下文。 |
| [OH_Crypto_ErrCode OH_CryptoMac_Update(OH_CryptoMac *ctx, const Crypto_DataBlob *in)](#oh_cryptomac_update) | 更新MAC上下文。 |
| [OH_Crypto_ErrCode OH_CryptoMac_Final(OH_CryptoMac *ctx, Crypto_DataBlob *out)](#oh_cryptomac_final) | 完成MAC操作。 |
| [OH_Crypto_ErrCode OH_CryptoMac_GetLength(OH_CryptoMac *ctx, uint32_t *length)](#oh_cryptomac_getlength) | 获取MAC长度。 |
| [void OH_CryptoMac_Destroy(OH_CryptoMac *ctx)](#oh_cryptomac_destroy) | 销毁MAC上下文。 |

## 枚举类型说明

### CryptoMac_ParamType

```
enum CryptoMac_ParamType
```

**描述**

Defines the MAC algorithm parameter type.

**起始版本：** 20

| 枚举项 | 描述 |
| -- | -- |
| CRYPTO_MAC_DIGEST_NAME_STR = 0 | Indicates the algorithm name of the message digest function for HMAC. e.g. "SHA256". |
| CRYPTO_MAC_CIPHER_NAME_STR = 1 | Indicates the algorithm name of the symmetric cipher function for CMAC. e.g. "AES256". |


## 函数说明

### OH_CryptoMac_Create()

```
OH_Crypto_ErrCode OH_CryptoMac_Create(const char *algoName, OH_CryptoMac **ctx)
```

**描述**

根据给定的算法名称创建MAC上下文。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char *algoName | algoName 用于生成MAC上下文的算法名称。\n例如"HMAC"、"CMAC"。 |
| [OH_CryptoMac](capi-oh-cryptomac.md) **ctx | ctx MAC上下文。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h#oh_crypto_errcode) | [OH_Crypto_ErrCode](capi-crypto-common-h#oh_crypto_errcode): <br>         CRYPTO_SUCCESS = 0 : 操作成功。<br>         CRYPTO_INVALID_PARAMS = 401 : 参数无效。<br>         CRYPTO_NOT_SUPPORTED = 801 : 操作不支持。<br>         CRYPTO_MEMORY_ERROR = 17620001 : 内存错误。<br>         CRYPTO_OPERTION_ERROR = 17630001 : 调用三方算法库API出错。 |

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
| [OH_CryptoMac](capi-oh-cryptomac.md) *ctx | ctx MAC上下文。 |
| [CryptoMac_ParamType](#cryptomac_paramtype) type | MAC参数类型. |
| const [Crypto_DataBlob](capi-crypto-common-hcrypto_datablob.md) *value | value 参数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h#oh_crypto_errcode) | [OH_Crypto_ErrCode](capi-crypto-common-h#oh_crypto_errcode): <br>         CRYPTO_SUCCESS = 0 : 操作成功。<br>         CRYPTO_INVALID_PARAMS = 401 : 参数无效。<br>         CRYPTO_NOT_SUPPORTED = 801 : 操作不支持。<br>         CRYPTO_MEMORY_ERROR = 17620001 : 内存错误。<br>         CRYPTO_OPERTION_ERROR = 17630001 : 调用三方算法库API出错。 |

### OH_CryptoMac_Init()

```
OH_Crypto_ErrCode OH_CryptoMac_Init(OH_CryptoMac *ctx, const OH_CryptoSymKey *key)
```

**描述**

使用对称密钥初始化MAC上下文。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoMac](capi-oh-cryptomac.md) *ctx | ctx MAC上下文。 |
| const [OH_CryptoSymKey](capi-crypto-sym-key-hoh_cryptosymkey.md) *key | key 对称密钥。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h#oh_crypto_errcode) | [OH_Crypto_ErrCode](capi-crypto-common-h#oh_crypto_errcode): <br>         CRYPTO_SUCCESS = 0 : 操作成功。<br>         CRYPTO_INVALID_PARAMS = 401 : 参数无效。<br>         CRYPTO_NOT_SUPPORTED = 801 : 操作不支持。<br>         CRYPTO_MEMORY_ERROR = 17620001 : 内存错误。<br>         CRYPTO_OPERTION_ERROR = 17630001 : 调用三方算法库API出错。 |

**参考：**

[OH_CryptoMac_Final](#oh_cryptomac_final)

### OH_CryptoMac_Update()

```
OH_Crypto_ErrCode OH_CryptoMac_Update(OH_CryptoMac *ctx, const Crypto_DataBlob *in)
```

**描述**

更新MAC上下文。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoMac](capi-oh-cryptomac.md) *ctx | ctx MAC上下文。 |
| const [Crypto_DataBlob](capi-crypto-common-hcrypto_datablob.md) *in | in 数据。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h#oh_crypto_errcode) | [OH_Crypto_ErrCode](capi-crypto-common-h#oh_crypto_errcode): <br>         CRYPTO_SUCCESS = 0 : 操作成功。<br>         CRYPTO_INVALID_PARAMS = 401 : 参数无效。<br>         CRYPTO_NOT_SUPPORTED = 801 : 操作不支持。<br>         CRYPTO_MEMORY_ERROR = 17620001 : 内存错误。<br>         CRYPTO_OPERTION_ERROR = 17630001 : 调用三方算法库API出错。 |

**参考：**

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
| [OH_CryptoMac](capi-oh-cryptomac.md) *ctx | ctx MAC上下文。 |
| mac | MAC值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h#oh_crypto_errcode) | [OH_Crypto_ErrCode](capi-crypto-common-h#oh_crypto_errcode): <br>         CRYPTO_SUCCESS = 0 : 操作成功。<br>         CRYPTO_INVALID_PARAMS = 401 : 参数无效。<br>         CRYPTO_NOT_SUPPORTED = 801 : 操作不支持。<br>         CRYPTO_MEMORY_ERROR = 17620001 : 内存错误。<br>         CRYPTO_OPERTION_ERROR = 17630001 : 调用三方算法库API出错。 |

**参考：**

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
| [OH_CryptoMac](capi-oh-cryptomac.md) *ctx | ctx 指向MAC上下文。 |
| uint32_t *length | length MAC长度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h#oh_crypto_errcode) | [OH_Crypto_ErrCode](capi-crypto-common-h#oh_crypto_errcode): <br>         CRYPTO_SUCCESS = 0 : 操作成功。<br>         CRYPTO_INVALID_PARAMS = 401 : 参数无效。<br>         CRYPTO_NOT_SUPPORTED = 801 : 操作不支持。<br>         CRYPTO_MEMORY_ERROR = 17620001 : 内存错误。<br>         CRYPTO_OPERTION_ERROR = 17630001 : 调用三方算法库API出错。 |

### OH_CryptoMac_Destroy()

```
void OH_CryptoMac_Destroy(OH_CryptoMac *ctx)
```

**描述**

销毁MAC上下文。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoMac](capi-oh-cryptomac.md) *ctx | ctx MAC上下文。 |


