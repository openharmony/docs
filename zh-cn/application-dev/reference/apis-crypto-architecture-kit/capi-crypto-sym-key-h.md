# crypto_sym_key.h

<!--Kit: Crypto Architecture Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--Designer: @lanming-->
<!--Tester: @PAFT-->
<!--Adviser: @zengyawen-->

## 概述

定义对称密钥接口。

**库：** libohcrypto.so

**系统能力：** SystemCapability.Security.CryptoFramework

**起始版本：** 12

**相关模块：** [CryptoSymKeyApi](capi-cryptosymkeyapi.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_CryptoSymKey](capi-cryptosymkeyapi-oh-cryptosymkey.md) | OH_CryptoSymKey | 对称密钥结构体，表示对称密钥。 |
| [OH_CryptoSymKeyGenerator](capi-cryptosymkeyapi-oh-cryptosymkeygenerator.md) | OH_CryptoSymKeyGenerator | 对称密钥生成器结构体，表示对称密钥生成器。 |

### 函数

| 名称 | 描述 |
| -- | -- |
| [OH_Crypto_ErrCode OH_CryptoSymKeyGenerator_Create(const char *algoName, OH_CryptoSymKeyGenerator **ctx)](#oh_cryptosymkeygenerator_create) | 根据给定的算法名称创建对称密钥生成器。例如AES256。<br> 注意：创建的资源必须通过[OH_CryptoSymKeyGenerator_Destroy](capi-crypto-sym-key-h.md#oh_cryptosymkeygenerator_destroy)销毁。 |
| [OH_Crypto_ErrCode OH_CryptoSymKeyGenerator_Generate(OH_CryptoSymKeyGenerator *ctx, OH_CryptoSymKey **keyCtx)](#oh_cryptosymkeygenerator_generate) | 随机生成对称密钥。<br> 注意：使用完成后必须通过[OH_CryptoSymKey_Destroy](capi-crypto-sym-key-h.md#oh_cryptosymkey_destroy)销毁keyCtx内存。 |
| [OH_Crypto_ErrCode OH_CryptoSymKeyGenerator_Convert(OH_CryptoSymKeyGenerator *ctx, const Crypto_DataBlob *keyData, OH_CryptoSymKey **keyCtx)](#oh_cryptosymkeygenerator_convert) | 将对称密钥数据转换为对称密钥。<br> 注意：使用完成后必须通过[OH_CryptoSymKey_Destroy](capi-crypto-sym-key-h.md#oh_cryptosymkey_destroy)销毁keyCtx内存。 |
| [const char *OH_CryptoSymKeyGenerator_GetAlgoName(OH_CryptoSymKeyGenerator *ctx)](#oh_cryptosymkeygenerator_getalgoname) | 获取对称密钥生成器的算法名称。 |
| [void OH_CryptoSymKeyGenerator_Destroy(OH_CryptoSymKeyGenerator *ctx)](#oh_cryptosymkeygenerator_destroy) | 销毁对称密钥生成器。 |
| [const char *OH_CryptoSymKey_GetAlgoName(OH_CryptoSymKey *keyCtx)](#oh_cryptosymkey_getalgoname) | 从对称密钥中获取对称密钥算法名称。 |
| [OH_Crypto_ErrCode OH_CryptoSymKey_GetKeyData(OH_CryptoSymKey *keyCtx, Crypto_DataBlob *out)](#oh_cryptosymkey_getkeydata) | 从对称密钥中获取对称密钥数据。<br> 注意：使用完成后必须通过[OH_Crypto_FreeDataBlob](capi-crypto-common-h.md#oh_crypto_freedatablob)释放out内存。 |
| [void OH_CryptoSymKey_Destroy(OH_CryptoSymKey *keyCtx)](#oh_cryptosymkey_destroy) | 销毁对称密钥。 |

## 函数说明

### OH_CryptoSymKeyGenerator_Create()

```c
OH_Crypto_ErrCode OH_CryptoSymKeyGenerator_Create(const char *algoName, OH_CryptoSymKeyGenerator **ctx)
```

**描述**

根据给定的算法名称创建对称密钥生成器。例如AES256。

注意：创建的资源必须通过[OH_CryptoSymKeyGenerator_Destroy](capi-crypto-sym-key-h.md#oh_cryptosymkeygenerator_destroy)销毁

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char *algoName | [in] 对称密钥算法名称，不能为NULL。取值如下：<br>- 从API version 12开始支持"AES128"、"AES192"、"AES256"、"3DES192"、"HMAC\|SHA1"、"HMAC\|SHA224"、"HMAC\|SHA256"、"HMAC\|SHA384"、"HMAC\|SHA512"、"HMAC\|SM3"、"HMAC\|MD5"。从API version 26.0.0开始支持"HMAC\|SHA3-256"、"HMAC\|SHA3-384"、"HMAC\|SHA3-512"。<br>- 从API version 12开始支持"SM4_128"。<br>- 从API version 20开始支持"DES64"。<br>- 从API version 22开始支持"ChaCha20"。<br>- 从API version 26.0.0开始支持"RC2"、"RC4"、"Blowfish"、"CAST"。注意仅支持将对称密钥数据转换为对称密钥，不支持随机生成。 |
| [OH_CryptoSymKeyGenerator](capi-cryptosymkeyapi-oh-cryptosymkeygenerator.md) **ctx | [out] 指向对称密钥生成器指针的指针。ctx不能为NULL，*ctx必须为NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | CRYPTO_SUCCESS：操作成功。<br>CRYPTO_INVALID_PARAMS：ctx为NULL或algoName为NULL。<br>CRYPTO_NOT_SUPPORTED：不支持的算法。<br>CRYPTO_MEMORY_ERROR：内存分配失败。<br>CRYPTO_OPERTION_ERROR：密码操作失败。 |

**参考：**

[OH_CryptoSymKeyGenerator_Generate](capi-crypto-sym-key-h.md#oh_cryptosymkeygenerator_generate) 随机生成对称密钥。

[OH_CryptoSymKeyGenerator_Convert](capi-crypto-sym-key-h.md#oh_cryptosymkeygenerator_convert) 将对称密钥数据转换为对称密钥。


### OH_CryptoSymKeyGenerator_Generate()

```c
OH_Crypto_ErrCode OH_CryptoSymKeyGenerator_Generate(OH_CryptoSymKeyGenerator *ctx, OH_CryptoSymKey **keyCtx)
```

**描述**

随机生成对称密钥。

注意：使用完成后必须通过[OH_CryptoSymKey_Destroy](capi-crypto-sym-key-h.md#oh_cryptosymkey_destroy)销毁keyCtx内存。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoSymKeyGenerator](capi-cryptosymkeyapi-oh-cryptosymkeygenerator.md) *ctx | [in] 对称密钥生成器。不能为NULL。 |
| [OH_CryptoSymKey](capi-cryptosymkeyapi-oh-cryptosymkey.md) **keyCtx | [out] 指向对称密钥指针的指针。keyCtx不能为NULL，*keyCtx必须为NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | CRYPTO_SUCCESS：操作成功。<br>CRYPTO_INVALID_PARAMS：ctx或keyCtx为NULL。<br>CRYPTO_NOT_SUPPORTED：不支持的操作或算法。<br>CRYPTO_MEMORY_ERROR：内存操作失败。<br>CRYPTO_INVALID_CALL：无效的函数调用。可能的原因：算法不支持随机生成密钥（如RC2、RC4、Blowfish、CAST），请使用OH_CryptoSymKeyGenerator_Convert接口。适用版本：26.0.0+<br>CRYPTO_OPERTION_ERROR：密码操作失败。 |

### OH_CryptoSymKeyGenerator_Convert()

```c
OH_Crypto_ErrCode OH_CryptoSymKeyGenerator_Convert(OH_CryptoSymKeyGenerator *ctx, const Crypto_DataBlob *keyData, OH_CryptoSymKey **keyCtx)
```

**描述**

将对称密钥数据转换为对称密钥。

注意：使用完成后必须通过[OH_CryptoSymKey_Destroy](capi-crypto-sym-key-h.md#oh_cryptosymkey_destroy)销毁keyCtx内存。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoSymKeyGenerator](capi-cryptosymkeyapi-oh-cryptosymkeygenerator.md) *ctx | [in] 对称密钥生成器。不能为NULL。 |
| [const Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *keyData | [in] 用于生成对称密钥的数据。不能为NULL。 |
| [OH_CryptoSymKey](capi-cryptosymkeyapi-oh-cryptosymkey.md) **keyCtx | [out] 指向对称密钥指针的指针。keyCtx不能为NULL，*keyCtx必须为NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | CRYPTO_SUCCESS：操作成功。<br>CRYPTO_INVALID_PARAMS：ctx、keyData或keyCtx为NULL。<br>CRYPTO_NOT_SUPPORTED：不支持的操作或算法。<br>CRYPTO_MEMORY_ERROR：内存分配失败。<br>CRYPTO_OPERTION_ERROR：密码操作失败。 |

### OH_CryptoSymKeyGenerator_GetAlgoName()

```c
const char *OH_CryptoSymKeyGenerator_GetAlgoName(OH_CryptoSymKeyGenerator *ctx)
```

**描述**

获取对称密钥生成器的算法名称。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoSymKeyGenerator](capi-cryptosymkeyapi-oh-cryptosymkeygenerator.md) *ctx | [in] 对称密钥生成器。不能为NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| const char * | 返回对称密钥算法名称，不需要调用者释放，在生成器销毁后不可使用。 |

### OH_CryptoSymKeyGenerator_Destroy()

```c
void OH_CryptoSymKeyGenerator_Destroy(OH_CryptoSymKeyGenerator *ctx)
```

**描述**

销毁对称密钥生成器。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoSymKeyGenerator](capi-cryptosymkeyapi-oh-cryptosymkeygenerator.md) *ctx | [in] 对称密钥生成器。 |

### OH_CryptoSymKey_GetAlgoName()

```c
const char *OH_CryptoSymKey_GetAlgoName(OH_CryptoSymKey *keyCtx)
```

**描述**

从对称密钥中获取对称密钥算法名称。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoSymKey](capi-cryptosymkeyapi-oh-cryptosymkey.md) *keyCtx | [in] 对称密钥。不能为NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| const char * | 返回算法名称，不需要调用者释放，在密钥销毁后不可使用。 |

### OH_CryptoSymKey_GetKeyData()

```c
OH_Crypto_ErrCode OH_CryptoSymKey_GetKeyData(OH_CryptoSymKey *keyCtx, Crypto_DataBlob *out)
```

**描述**

从对称密钥中获取对称密钥数据。

注意：使用完成后必须通过[OH_Crypto_FreeDataBlob](capi-crypto-common-h.md#oh_crypto_freedatablob)释放out内存。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoSymKey](capi-cryptosymkeyapi-oh-cryptosymkey.md) *keyCtx | [in] 对称密钥。不能为NULL。 |
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *out | [out] 指向用于存储密钥数据的Crypto_DataBlob结构体的指针。不能为NULL。调用前需将out初始化为{0}，不要预分配out->data内存。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | CRYPTO_SUCCESS：操作成功。<br>CRYPTO_INVALID_PARAMS：keyCtx或out为NULL。<br>CRYPTO_NOT_SUPPORTED：不支持的操作或算法。<br>CRYPTO_MEMORY_ERROR：内存操作失败。<br>CRYPTO_OPERTION_ERROR：密码操作失败。 |

### OH_CryptoSymKey_Destroy()

```c
void OH_CryptoSymKey_Destroy(OH_CryptoSymKey *keyCtx)
```

**描述**

销毁对称密钥。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoSymKey](capi-cryptosymkeyapi-oh-cryptosymkey.md) *keyCtx | [in] 对称密钥。 |


