# crypto_asym_cipher.h

## 概述

定义非对称密钥加密API。

**库：** libohcrypto.so

**引用文件：** <CryptoArchitectureKit/crypto_asym_cipher.h>

**系统能力：** SystemCapability.Security.CryptoFramework

**起始版本：** 20

**相关模块：** [CryptoAsymCipherApi](capi-cryptoasymcipherapi.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_CryptoAsymCipher](capi-cryptoasymcipherapi-oh-cryptoasymcipher.md) | OH_CryptoAsymCipher | 定义非对称加密结构。 |
| [OH_CryptoSm2CiphertextSpec](capi-cryptoasymcipherapi-oh-cryptosm2ciphertextspec.md) | OH_CryptoSm2CiphertextSpec | 定义SM2密文规范结构。 |

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [CryptoSm2CiphertextSpec_item](#cryptosm2ciphertextspec_item) | CryptoSm2CiphertextSpec_item | 定义SM2密文规范项类型。 |

### 函数

| 名称 | 描述 |
| -- | -- |
| [OH_Crypto_ErrCode OH_CryptoAsymCipher_Create(const char *algoName, OH_CryptoAsymCipher **ctx)](#oh_cryptoasymcipher_create) | 根据给定的算法名称创建非对称加密。 |
| [OH_Crypto_ErrCode OH_CryptoAsymCipher_Init(OH_CryptoAsymCipher *ctx, Crypto_CipherMode mode, OH_CryptoKeyPair *key)](#oh_cryptoasymcipher_init) | 初始化非对称加密。 |
| [OH_Crypto_ErrCode OH_CryptoAsymCipher_Final(OH_CryptoAsymCipher *ctx, const Crypto_DataBlob *in,Crypto_DataBlob *out)](#oh_cryptoasymcipher_final) | 完成非对称加密。 |
| [void OH_CryptoAsymCipher_Destroy(OH_CryptoAsymCipher *ctx)](#oh_cryptoasymcipher_destroy) | 销毁非对称加密上下文。 |
| [OH_Crypto_ErrCode OH_CryptoSm2CiphertextSpec_Create(Crypto_DataBlob *sm2Ciphertext, OH_CryptoSm2CiphertextSpec **spec)](#oh_cryptosm2ciphertextspec_create) | 创建SM2密文规范。 |
| [OH_Crypto_ErrCode OH_CryptoSm2CiphertextSpec_GetItem(OH_CryptoSm2CiphertextSpec *spec,CryptoSm2CiphertextSpec_item item, Crypto_DataBlob *out)](#oh_cryptosm2ciphertextspec_getitem) | 获取SM2密文规范中的指定项。 |
| [OH_Crypto_ErrCode OH_CryptoSm2CiphertextSpec_SetItem(OH_CryptoSm2CiphertextSpec *spec,CryptoSm2CiphertextSpec_item item, Crypto_DataBlob *in)](#oh_cryptosm2ciphertextspec_setitem) | 设置SM2密文规范中的指定项。 |
| [OH_Crypto_ErrCode OH_CryptoSm2CiphertextSpec_Encode(OH_CryptoSm2CiphertextSpec *spec, Crypto_DataBlob *out)](#oh_cryptosm2ciphertextspec_encode) | 将SM2密文规范编码为DER格式密文。 |
| [void OH_CryptoSm2CiphertextSpec_Destroy(OH_CryptoSm2CiphertextSpec *spec)](#oh_cryptosm2ciphertextspec_destroy) | 销毁SM2密文规范。 |

## 枚举类型说明

### CryptoSm2CiphertextSpec_item

```
enum CryptoSm2CiphertextSpec_item
```

**描述**

定义SM2密文规范项类型。

**起始版本：** 20

| 枚举项 | 描述 |
| -- | -- |
| CRYPTO_SM2_CIPHERTEXT_C1_X = 0 | 公钥x，也称为C1x。 |
| CRYPTO_SM2_CIPHERTEXT_C1_Y = 1 | 公钥y，也称为C1y。 |
| CRYPTO_SM2_CIPHERTEXT_C2 = 2 | 哈希值，也称为C2。 |
| CRYPTO_SM2_CIPHERTEXT_C3 = 3 | 密文数据，也称为C3。 |


## 函数说明

### OH_CryptoAsymCipher_Create()

```
OH_Crypto_ErrCode OH_CryptoAsymCipher_Create(const char *algoName, OH_CryptoAsymCipher **ctx)
```

**描述**

根据给定的算法名称创建非对称加密。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char *algoName | 用于生成加密的算法名称。<br>例如"RSA\|PKCS1_OAEP\|SHA384\|MGF1_SHA384", "SM2\|SM3"。 |
| [OH_CryptoAsymCipher](capi-cryptoasymcipherapi-oh-cryptoasymcipher.md) **ctx | 指向非对称加密上下文的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | CRYPTO_SUCCESS = 0 : 操作成功。<br>         CRYPTO_INVALID_PARAMS = 401 : 参数无效。<br>         CRYPTO_NOT_SUPPORTED = 801 : 操作不支持。<br>         CRYPTO_MEMORY_ERROR = 17620001 : 内存错误。<br>         CRYPTO_OPERTION_ERROR = 17630001 : 调用三方算法库API出错。 |

### OH_CryptoAsymCipher_Init()

```
OH_Crypto_ErrCode OH_CryptoAsymCipher_Init(OH_CryptoAsymCipher *ctx, Crypto_CipherMode mode, OH_CryptoKeyPair *key)
```

**描述**

初始化非对称加密。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoAsymCipher](capi-cryptoasymcipherapi-oh-cryptoasymcipher.md) *ctx | 非对称加密上下文。 |
| [Crypto_CipherMode](capi-crypto-common-h.md#crypto_ciphermode) mode | 加密模式是加密还是解密。 |
| [OH_CryptoKeyPair](capi-cryptoasymkeyapi-oh-cryptokeypair.md) *key | 非对称密钥。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) |         CRYPTO_SUCCESS = 0 : 操作成功。<br>         CRYPTO_INVALID_PARAMS = 401 : 参数无效。<br>         CRYPTO_NOT_SUPPORTED = 801 : 操作不支持。<br>         CRYPTO_MEMORY_ERROR = 17620001 : 内存错误。<br>         CRYPTO_OPERTION_ERROR = 17630001 : 调用三方算法库API出错。 |

**参考：**

[OH_CryptoAsymCipher_Final](#oh_cryptoasymcipher_final)

### OH_CryptoAsymCipher_Final()

```
OH_Crypto_ErrCode OH_CryptoAsymCipher_Final(OH_CryptoAsymCipher *ctx, const Crypto_DataBlob *in,Crypto_DataBlob *out)
```

**描述**

完成非对称加密。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoAsymCipher](capi-cryptoasymcipherapi-oh-cryptoasymcipher.md) *ctx | 非对称加密上下文。 |
| const [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *in | 要加密或解密的数据。 |
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *out | 最终加密或解密的数据。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | CRYPTO_SUCCESS = 0 : 操作成功。<br>         CRYPTO_INVALID_PARAMS = 401 : 参数无效。<br>         CRYPTO_NOT_SUPPORTED = 801 : 操作不支持。<br>         CRYPTO_MEMORY_ERROR = 17620001 : 内存错误。<br>         CRYPTO_OPERTION_ERROR = 17630001 : 调用三方算法库API出错。 |

**参考：**

[OH_CryptoAsymCipher_Init](#oh_cryptoasymcipher_init)

### OH_CryptoAsymCipher_Destroy()

```
void OH_CryptoAsymCipher_Destroy(OH_CryptoAsymCipher *ctx)
```

**描述**

销毁非对称加密上下文。

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoAsymCipher](capi-cryptoasymcipherapi-oh-cryptoasymcipher.md) *ctx | 非对称加密上下文。 |

### OH_CryptoSm2CiphertextSpec_Create()

```
OH_Crypto_ErrCode OH_CryptoSm2CiphertextSpec_Create(Crypto_DataBlob *sm2Ciphertext, OH_CryptoSm2CiphertextSpec **spec)
```

**描述**

创建SM2密文规范。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *sm2Ciphertext | SM2密文DER格式数据，如果为NULL则创建空的SM2密文规范。 |
| [OH_CryptoSm2CiphertextSpec](capi-cryptoasymcipherapi-oh-cryptosm2ciphertextspec.md) **spec |  输出的SM2密文规范。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) |       CRYPTO_SUCCESS = 0 : 操作成功。<br>         CRYPTO_INVALID_PARAMS = 401 : 参数无效。<br>         CRYPTO_NOT_SUPPORTED = 801 : 操作不支持。<br>         CRYPTO_MEMORY_ERROR = 17620001 : 内存错误。<br>         CRYPTO_OPERTION_ERROR = 17630001 : 调用三方算法库API出错。 |

### OH_CryptoSm2CiphertextSpec_GetItem()

```
OH_Crypto_ErrCode OH_CryptoSm2CiphertextSpec_GetItem(OH_CryptoSm2CiphertextSpec *spec,CryptoSm2CiphertextSpec_item item, Crypto_DataBlob *out)
```

**描述**

获取SM2密文规范中的指定项。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoSm2CiphertextSpec](capi-cryptoasymcipherapi-oh-cryptosm2ciphertextspec.md) *spec |  SM2密文规范。 |
| [CryptoSm2CiphertextSpec_item](#cryptosm2ciphertextspec_item) item | SM2密文规范项。 |
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *out | 输出数据。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) |       CRYPTO_SUCCESS = 0 : 操作成功。<br>         CRYPTO_INVALID_PARAMS = 401 : 参数无效。<br>         CRYPTO_NOT_SUPPORTED = 801 : 操作不支持。<br>         CRYPTO_MEMORY_ERROR = 17620001 : 内存错误。<br>         CRYPTO_OPERTION_ERROR = 17630001 : 调用三方算法库API出错。 |

### OH_CryptoSm2CiphertextSpec_SetItem()

```
OH_Crypto_ErrCode OH_CryptoSm2CiphertextSpec_SetItem(OH_CryptoSm2CiphertextSpec *spec,CryptoSm2CiphertextSpec_item item, Crypto_DataBlob *in)
```

**描述**

设置SM2密文规范中的指定项。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoSm2CiphertextSpec](capi-cryptoasymcipherapi-oh-cryptosm2ciphertextspec.md) *spec |  SM2密文规范。 |
| [CryptoSm2CiphertextSpec_item](#cryptosm2ciphertextspec_item) item | SM2密文规范项。 |
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *in | 输入数据。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) |       CRYPTO_SUCCESS = 0 : 操作成功。<br>         CRYPTO_INVALID_PARAMS = 401 : 参数无效。<br>         CRYPTO_NOT_SUPPORTED = 801 : 操作不支持。<br>         CRYPTO_MEMORY_ERROR = 17620001 : 内存错误。<br>         CRYPTO_OPERTION_ERROR = 17630001 : 调用三方算法库API出错。 |

### OH_CryptoSm2CiphertextSpec_Encode()

```
OH_Crypto_ErrCode OH_CryptoSm2CiphertextSpec_Encode(OH_CryptoSm2CiphertextSpec *spec, Crypto_DataBlob *out)
```

**描述**

将SM2密文规范编码为DER格式密文。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoSm2CiphertextSpec](capi-cryptoasymcipherapi-oh-cryptosm2ciphertextspec.md) *spec |  SM2密文规范。 |
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *out | 输出数据。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) |       CRYPTO_SUCCESS = 0 : 操作成功。<br>         CRYPTO_INVALID_PARAMS = 401 : 参数无效。<br>         CRYPTO_NOT_SUPPORTED = 801 : 操作不支持。<br>         CRYPTO_MEMORY_ERROR = 17620001 : 内存错误。<br>         CRYPTO_OPERTION_ERROR = 17630001 : 调用三方算法库API出错。 |

### OH_CryptoSm2CiphertextSpec_Destroy()

```
void OH_CryptoSm2CiphertextSpec_Destroy(OH_CryptoSm2CiphertextSpec *spec)
```

**描述**

销毁SM2密文规范。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoSm2CiphertextSpec](capi-cryptoasymcipherapi-oh-cryptosm2ciphertextspec.md) *spec |  SM2密文规范。 |


