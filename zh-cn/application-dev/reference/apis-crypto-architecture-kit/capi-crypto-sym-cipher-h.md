# crypto_sym_cipher.h

<!--Kit: Crypto Architecture Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--Designer: @lanming-->
<!--Tester: @PAFT-->
<!--Adviser: @zengyawen-->

## 概述

定义对称密钥加密API。

**引用文件：** <CryptoArchitectureKit/crypto_sym_cipher.h>

**库：** libohcrypto.so

**系统能力：** SystemCapability.Security.CryptoFramework

**起始版本：** 12

**相关模块：** [CryptoSymCipherApi](capi-cryptosymcipherapi.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_CryptoSymCipher](capi-cryptosymcipherapi-oh-cryptosymcipher.md) | OH_CryptoSymCipher | 定义对称加解密结构体。 |
| [OH_CryptoSymCipherParams](capi-cryptosymcipherapi-oh-cryptosymcipherparams.md) | OH_CryptoSymCipherParams | 定义对称加解密参数结构体。 |

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [CryptoSymCipher_ParamsType](#cryptosymcipher_paramstype) | CryptoSymCipher_ParamsType | 定义对称加解密参数类型。 |

### 函数

| 名称 | 描述 |
| -- | -- |
| [OH_Crypto_ErrCode OH_CryptoSymCipherParams_Create(OH_CryptoSymCipherParams **params)](#oh_cryptosymcipherparams_create) | 创建对称密钥加解密参数实例。 |
| [OH_Crypto_ErrCode OH_CryptoSymCipherParams_SetParam(OH_CryptoSymCipherParams *params, CryptoSymCipher_ParamsType paramsType, Crypto_DataBlob *value)](#oh_cryptosymcipherparams_setparam) | 设置对称密钥加解密参数。 |
| [void OH_CryptoSymCipherParams_Destroy(OH_CryptoSymCipherParams *params)](#oh_cryptosymcipherparams_destroy) | 销毁对称密钥加解密参数实例。 |
| [OH_Crypto_ErrCode OH_CryptoSymCipher_Create(const char *algoName, OH_CryptoSymCipher **ctx)](#oh_cryptosymcipher_create) | 根据给定的算法名称创建对称密钥加解密实例。 |
| [OH_Crypto_ErrCode OH_CryptoSymCipher_Init(OH_CryptoSymCipher *ctx, Crypto_CipherMode mod, OH_CryptoSymKey *key, OH_CryptoSymCipherParams *params)](#oh_cryptosymcipher_init) | 初始化对称密钥加解密实例。 |
| [OH_Crypto_ErrCode OH_CryptoSymCipher_Update(OH_CryptoSymCipher *ctx, Crypto_DataBlob *in, Crypto_DataBlob *out)](#oh_cryptosymcipher_update) | 更新加密或者解密数据操作。 |
| [OH_Crypto_ErrCode OH_CryptoSymCipher_Final(OH_CryptoSymCipher *ctx, Crypto_DataBlob *in, Crypto_DataBlob *out)](#oh_cryptosymcipher_final) | 输出加/解密（分组模式产生的）剩余数据，最后结束加密或者解密数据操作。 |
| [const char *OH_CryptoSymCipher_GetAlgoName(OH_CryptoSymCipher *ctx)](#oh_cryptosymcipher_getalgoname) | 获取对称密钥加解密实例的算法名称。 |
| [void OH_CryptoSymCipher_Destroy(OH_CryptoSymCipher *ctx)](#oh_cryptosymcipher_destroy) | 销毁对称密钥加解密实例。 |

## 枚举类型说明

### CryptoSymCipher_ParamsType

```
enum CryptoSymCipher_ParamsType
```

**描述**

定义对称加解密参数类型。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| CRYPTO_IV_DATABLOB = 100 | 表示iv等参数。 |
| CRYPTO_AAD_DATABLOB = 101 | 表示GCM模式下的附加认证数据。 |
| CRYPTO_TAG_DATABLOB = 102 | 表示加密操作的输出标签,用于完整性检查。 |


## 函数说明

### OH_CryptoSymCipherParams_Create()

```
OH_Crypto_ErrCode OH_CryptoSymCipherParams_Create(OH_CryptoSymCipherParams **params)
```

**描述**

创建对称密钥加解密参数实例。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoSymCipherParams](capi-cryptosymcipherapi-oh-cryptosymcipherparams.md) **params | 指向对称加解密参数实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | CRYPTO_SUCCESS：操作成功。<br>         CRYPTO_INVALID_PARAMS：参数无效。<br>         CRYPTO_NOT_SUPPORTED：操作不支持。<br>         CRYPTO_MEMORY_ERROR：内存错误。<br>         CRYPTO_OPERTION_ERROR：调用三方算法库API出错。 |

### OH_CryptoSymCipherParams_SetParam()

```
OH_Crypto_ErrCode OH_CryptoSymCipherParams_SetParam(OH_CryptoSymCipherParams *params,CryptoSymCipher_ParamsType paramsType, Crypto_DataBlob *value)
```

**描述**

设置对称密钥加解密参数。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoSymCipherParams](capi-cryptosymcipherapi-oh-cryptosymcipherparams.md) *params | 指向对称密钥加解密参数实例。 |
| [CryptoSymCipher_ParamsType](#cryptosymcipher_paramstype) paramsType | 设置对称密钥加解密参数类型。 |
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *value | 设置的参数值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | CRYPTO_SUCCESS：操作成功。<br>         CRYPTO_INVALID_PARAMS：参数无效。<br>         CRYPTO_NOT_SUPPORTED：操作不支持。<br>         CRYPTO_MEMORY_ERROR：内存错误。<br>         CRYPTO_OPERTION_ERROR：调用三方算法库API出错。 |

### OH_CryptoSymCipherParams_Destroy()

```
void OH_CryptoSymCipherParams_Destroy(OH_CryptoSymCipherParams *params)
```

**描述**

销毁对称密钥加解密参数实例。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoSymCipherParams](capi-cryptosymcipherapi-oh-cryptosymcipherparams.md) *params | 指向对称密钥加解密参数实例。 |

### OH_CryptoSymCipher_Create()

```
OH_Crypto_ErrCode OH_CryptoSymCipher_Create(const char *algoName, OH_CryptoSymCipher **ctx)
```

**描述**

根据给定的算法名称创建对称密钥加解密实例。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char *algoName | 用于生成加密实例的算法名称。<br> 例如"AES128\|GCM\|PKCS7"。 |
| [OH_CryptoSymCipher](capi-cryptosymcipherapi-oh-cryptosymcipher.md) **ctx | 指向对称密钥加密实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | CRYPTO_SUCCESS：操作成功。<br>         CRYPTO_INVALID_PARAMS：参数无效。<br>         CRYPTO_NOT_SUPPORTED：操作不支持。<br>         CRYPTO_MEMORY_ERROR：内存错误。<br>         CRYPTO_OPERTION_ERROR：调用三方算法库API出错。 |

### OH_CryptoSymCipher_Init()

```
OH_Crypto_ErrCode OH_CryptoSymCipher_Init(OH_CryptoSymCipher *ctx, Crypto_CipherMode mod,OH_CryptoSymKey *key, OH_CryptoSymCipherParams *params)
```

**描述**

初始化对称密钥加解密实例。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoSymCipher](capi-cryptosymcipherapi-oh-cryptosymcipher.md) *ctx | 对称密钥加密实例。 |
| [Crypto_CipherMode](capi-crypto-common-h.md#crypto_ciphermode) mod | 加解密模式。 |
| [OH_CryptoSymKey](capi-cryptosymkeyapi-oh-cryptosymkey.md) *key | 对称密钥。 |
| [OH_CryptoSymCipherParams](capi-cryptosymcipherapi-oh-cryptosymcipherparams.md) *params | 指向对称密钥参数实例。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | CRYPTO_SUCCESS：操作成功。<br>         CRYPTO_INVALID_PARAMS：参数无效。<br>         CRYPTO_NOT_SUPPORTED：操作不支持。<br>         CRYPTO_MEMORY_ERROR：内存错误。<br>         CRYPTO_OPERTION_ERROR：调用三方算法库API出错。 |

**参考：**

[OH_CryptoSymCipher_Update](#oh_cryptosymcipher_update)

[OH_CryptoSymCipher_Final](#oh_cryptosymcipher_final)


### OH_CryptoSymCipher_Update()

```
OH_Crypto_ErrCode OH_CryptoSymCipher_Update(OH_CryptoSymCipher *ctx, Crypto_DataBlob *in, Crypto_DataBlob *out)
```

**描述**

更新加密或者解密数据操作。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoSymCipher](capi-cryptosymcipherapi-oh-cryptosymcipher.md) *ctx | 指向对称密钥加解密实例。 |
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *in | 加密或者解密的数据。 |
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *out | 更新的结果。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | CRYPTO_SUCCESS：操作成功。<br>         CRYPTO_INVALID_PARAMS：参数无效。<br>         CRYPTO_NOT_SUPPORTED：操作不支持。<br>         CRYPTO_MEMORY_ERROR：内存错误。<br>         CRYPTO_OPERTION_ERROR：调用三方算法库API出错。 |

**参考：**

[OH_CryptoSymCipher_Init](#oh_cryptosymcipher_init)

[OH_CryptoSymCipher_Final](#oh_cryptosymcipher_final)


### OH_CryptoSymCipher_Final()

```
OH_Crypto_ErrCode OH_CryptoSymCipher_Final(OH_CryptoSymCipher *ctx, Crypto_DataBlob *in, Crypto_DataBlob *out)
```

**描述**

输出加/解密（分组模式产生的）剩余数据，最后结束加密或者解密数据操作。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoSymCipher](capi-cryptosymcipherapi-oh-cryptosymcipher.md) *ctx | 对称密钥加密实例。 |
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *in | 要加密或解密的数据。 |
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *out | 返回剩余数据的加/解密结果。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | CRYPTO_SUCCESS：操作成功。<br>         CRYPTO_INVALID_PARAMS：参数无效。<br>         CRYPTO_NOT_SUPPORTED：操作不支持。<br>         CRYPTO_MEMORY_ERROR：内存错误。<br>         CRYPTO_OPERTION_ERROR：调用三方算法库API出错。 |

**参考：**

[OH_CryptoSymCipher_Init](#oh_cryptosymcipher_init)

[OH_CryptoSymCipher_Update](#oh_cryptosymcipher_update)


### OH_CryptoSymCipher_GetAlgoName()

```
const char *OH_CryptoSymCipher_GetAlgoName(OH_CryptoSymCipher *ctx)
```

**描述**

获取对称密钥加解密实例的算法名称。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoSymCipher](capi-cryptosymcipherapi-oh-cryptosymcipher.md) *ctx | 指向对称密钥加解密实例。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| const char * | 返回对称密钥加密算法名称。 |

### OH_CryptoSymCipher_Destroy()

```
void OH_CryptoSymCipher_Destroy(OH_CryptoSymCipher *ctx)
```

**描述**

销毁对称密钥加解密实例。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoSymCipher](capi-cryptosymcipherapi-oh-cryptosymcipher.md) *ctx | 指向对称密钥加解密实例。 |


