# crypto_asym_cipher.h

<!--Kit: Crypto Architecture Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--Designer: @lanming-->
<!--Tester: @PAFT-->
<!--Adviser: @zengyawen-->

## 概述

定义非对称加解密接口。

**引用文件：** <CryptoArchitectureKit/crypto_asym_cipher.h>

**库：** libohcrypto.so

**系统能力：** SystemCapability.Security.CryptoFramework

**起始版本：** 20

**相关模块：** [CryptoAsymCipherApi](capi-cryptoasymcipherapi.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_CryptoAsymCipher](capi-cryptoasymcipherapi-oh-cryptoasymcipher.md) | OH_CryptoAsymCipher | 非对称加解密结构体，表示非对称加解密上下文。 |
| [OH_CryptoSm2CiphertextSpec](capi-cryptoasymcipherapi-oh-cryptosm2ciphertextspec.md) | OH_CryptoSm2CiphertextSpec | SM2密文规格结构体，表示SM2密文规格。 |

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [CryptoSm2CiphertextSpec_item](#cryptosm2ciphertextspec_item) | CryptoSm2CiphertextSpec_item | 定义SM2密文规格项类型。 |

### 函数

| 名称 | 描述 |
| -- | -- |
| [OH_Crypto_ErrCode OH_CryptoAsymCipher_Create(const char *algoName, OH_CryptoAsymCipher **ctx)](#oh_cryptoasymcipher_create) | 根据给定的算法名称创建非对称加解密上下文。<br> 注意：创建的资源必须通过[OH_CryptoAsymCipher_Destroy](capi-crypto-asym-cipher-h.md#oh_cryptoasymcipher_destroy)销毁。 |
| [OH_Crypto_ErrCode OH_CryptoAsymCipher_Init(OH_CryptoAsymCipher *ctx, Crypto_CipherMode mode, OH_CryptoKeyPair *key)](#oh_cryptoasymcipher_init) | 使用给定的加解密模式和密钥初始化非对称加解密上下文。 |
| [OH_Crypto_ErrCode OH_CryptoAsymCipher_Final(OH_CryptoAsymCipher *ctx, const Crypto_DataBlob *in, Crypto_DataBlob *out)](#oh_cryptoasymcipher_final) | 结束加解密操作。<br> 注意：使用完成后必须通过[OH_Crypto_FreeDataBlob](capi-crypto-common-h.md#oh_crypto_freedatablob)释放out内存。 |
| [void OH_CryptoAsymCipher_Destroy(OH_CryptoAsymCipher *ctx)](#oh_cryptoasymcipher_destroy) | 销毁非对称加解密上下文。 |
| [OH_Crypto_ErrCode OH_CryptoSm2CiphertextSpec_Create(Crypto_DataBlob *sm2Ciphertext, OH_CryptoSm2CiphertextSpec **spec)](#oh_cryptosm2ciphertextspec_create) | 创建SM2密文规格。<br> 注意：创建的资源必须通过[OH_CryptoSm2CiphertextSpec_Destroy](capi-crypto-asym-cipher-h.md#oh_cryptosm2ciphertextspec_destroy)销毁。 |
| [OH_Crypto_ErrCode OH_CryptoSm2CiphertextSpec_GetItem(OH_CryptoSm2CiphertextSpec *spec, CryptoSm2CiphertextSpec_item item, Crypto_DataBlob *out)](#oh_cryptosm2ciphertextspec_getitem) | 获取SM2密文的指定项。<br> 注意：使用完成后必须通过[OH_Crypto_FreeDataBlob](capi-crypto-common-h.md#oh_crypto_freedatablob)释放out内存。 |
| [OH_Crypto_ErrCode OH_CryptoSm2CiphertextSpec_SetItem(OH_CryptoSm2CiphertextSpec *spec, CryptoSm2CiphertextSpec_item item, Crypto_DataBlob *in)](#oh_cryptosm2ciphertextspec_setitem) | 设置SM2密文规格的指定项。 |
| [OH_Crypto_ErrCode OH_CryptoSm2CiphertextSpec_Encode(OH_CryptoSm2CiphertextSpec *spec, Crypto_DataBlob *out)](#oh_cryptosm2ciphertextspec_encode) | 将SM2密文规格编码为DER格式密文。<br> 注意：使用完成后必须通过[OH_Crypto_FreeDataBlob](capi-crypto-common-h.md#oh_crypto_freedatablob)释放out内存。 |
| [void OH_CryptoSm2CiphertextSpec_Destroy(OH_CryptoSm2CiphertextSpec *spec)](#oh_cryptosm2ciphertextspec_destroy) | 销毁SM2密文规格。 |

## 枚举类型说明

### CryptoSm2CiphertextSpec_item

```c
enum CryptoSm2CiphertextSpec_item
```

**描述**

定义SM2密文规格项类型。

**起始版本：** 20

| 枚举项 | 描述 |
| -- | -- |
| CRYPTO_SM2_CIPHERTEXT_C1_X = 0 | 公钥x，也称为C1x。 |
| CRYPTO_SM2_CIPHERTEXT_C1_Y = 1 | 公钥y，也称为C1y。 |
| CRYPTO_SM2_CIPHERTEXT_C2 = 2 | 哈希值，也称为C2。 |
| CRYPTO_SM2_CIPHERTEXT_C3 = 3 | 密文数据，也称为C3。 |


## 函数说明

### OH_CryptoAsymCipher_Create()

```c
OH_Crypto_ErrCode OH_CryptoAsymCipher_Create(const char *algoName, OH_CryptoAsymCipher **ctx)
```

**描述**

根据给定的算法名称创建非对称加解密上下文。

注意：创建的资源必须通过[OH_CryptoAsymCipher_Destroy](capi-crypto-asym-cipher-h.md#oh_cryptoasymcipher_destroy)销毁。

**起始版本：** 20

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char *algoName | [in] 非对称加解密算法名称，不能为NULL。取值如下：<br>- RSA算法PKCS1填充模式：取值为"RSA\|PKCS1"。<br>- RSA算法OAEP填充模式：格式为"RSA\|PKCS1_OAEP\|摘要\|MGF1摘要"，示例："RSA\|PKCS1_OAEP\|SHA256\|MGF1_SHA256"。摘要支持"MD5"、"SHA1"、"SHA224"、"SHA256"、"SHA384"、"SHA512"。MGF1摘要支持"MGF1_SHA1"、"MGF1_SHA224"、"MGF1_SHA256"、"MGF1_SHA384"、"MGF1_SHA512"。<br>- RSA算法NoPadding填充模式：取值为"RSA\|NoPadding"。<br>- SM2算法：格式为"SM2\|摘要"，示例："SM2\|SM3"。摘要支持"MD5"、"SHA1"、"SHA224"、"SHA256"、"SHA384"、"SHA512"、"SM3"。 |
| [OH_CryptoAsymCipher](capi-cryptoasymcipherapi-oh-cryptoasymcipher.md) **ctx | [out] 指向非对称加解密上下文指针的指针。ctx不能为NULL，*ctx必须为NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | CRYPTO_SUCCESS：操作成功。<br>CRYPTO_PARAMETER_CHECK_FAILED：algoName或ctx为NULL。<br>CRYPTO_NOT_SUPPORTED：不支持的算法。<br>CRYPTO_MEMORY_ERROR：内存分配失败。<br>CRYPTO_OPERTION_ERROR：加解密操作失败。 |

**参考：**

[OH_CryptoAsymCipher_Init](capi-crypto-asym-cipher-h.md#oh_cryptoasymcipher_init) 初始化非对称加解密上下文。


### OH_CryptoAsymCipher_Init()

```c
OH_Crypto_ErrCode OH_CryptoAsymCipher_Init(OH_CryptoAsymCipher *ctx, Crypto_CipherMode mode, OH_CryptoKeyPair *key)
```

**描述**

使用给定的加解密模式和密钥初始化非对称加解密上下文。

**起始版本：** 20

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoAsymCipher](capi-cryptoasymcipherapi-oh-cryptoasymcipher.md) *ctx | [in] 非对称加解密上下文。不能为NULL。 |
| [Crypto_CipherMode](capi-crypto-common-h.md#crypto_ciphermode) mode | [in] 加解密模式，加密或解密。 |
| [OH_CryptoKeyPair](capi-cryptoasymkeyapi-oh-cryptokeypair.md) *key | [in] 非对称密钥。不能为NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | CRYPTO_SUCCESS：操作成功。<br>CRYPTO_PARAMETER_CHECK_FAILED：ctx或key为NULL。<br>CRYPTO_NOT_SUPPORTED：不支持的操作或算法。<br>CRYPTO_MEMORY_ERROR：内存操作失败。<br>CRYPTO_OPERTION_ERROR：加解密初始化失败。 |

**参考：**

[OH_CryptoAsymCipher_Final](capi-crypto-asym-cipher-h.md#oh_cryptoasymcipher_final) 结束加解密操作。


### OH_CryptoAsymCipher_Final()

```c
OH_Crypto_ErrCode OH_CryptoAsymCipher_Final(OH_CryptoAsymCipher *ctx, const Crypto_DataBlob *in, Crypto_DataBlob *out)
```

**描述**

结束加解密操作。

注意：使用完成后必须通过[OH_Crypto_FreeDataBlob](capi-crypto-common-h.md#oh_crypto_freedatablob)释放out内存。

**起始版本：** 20

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoAsymCipher](capi-cryptoasymcipherapi-oh-cryptoasymcipher.md) *ctx | [in] 非对称加解密上下文。不能为NULL。 |
| [const Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *in | [in] 待加密或解密的数据。不能为NULL。 |
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *out | [out] 指向用于存储加密或解密结果的Crypto_DataBlob结构体的指针。不能为NULL。调用前需将out初始化为{0}，不要预分配out->data内存。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | CRYPTO_SUCCESS：操作成功。<br>CRYPTO_PARAMETER_CHECK_FAILED：ctx、in或out为NULL。<br>CRYPTO_NOT_SUPPORTED：不支持的操作或算法。<br>CRYPTO_MEMORY_ERROR：内存分配失败。<br>CRYPTO_OPERTION_ERROR：加解密完成失败。可能的原因：<br>RSA加密时明文超过密钥长度和填充模式允许的最大长度；<br>RSA解密时密钥错误或密文损坏；<br>SM2解密时密钥错误或密文损坏；<br>SM2密文的ASN.1结构无效。 |

### OH_CryptoAsymCipher_Destroy()

```c
void OH_CryptoAsymCipher_Destroy(OH_CryptoAsymCipher *ctx)
```

**描述**

销毁非对称加解密上下文。

**起始版本：** 20

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoAsymCipher](capi-cryptoasymcipherapi-oh-cryptoasymcipher.md) *ctx | [in] 非对称加解密上下文。 |

### OH_CryptoSm2CiphertextSpec_Create()

```c
OH_Crypto_ErrCode OH_CryptoSm2CiphertextSpec_Create(Crypto_DataBlob *sm2Ciphertext, OH_CryptoSm2CiphertextSpec **spec)
```

**描述**

创建SM2密文规格。

注意：创建的资源必须通过[OH_CryptoSm2CiphertextSpec_Destroy](capi-crypto-asym-cipher-h.md#oh_cryptosm2ciphertextspec_destroy)销毁。

**起始版本：** 20

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *sm2Ciphertext | [in] DER格式的SM2密文，如果为NULL则创建空的SM2密文规格。 |
| [OH_CryptoSm2CiphertextSpec](capi-cryptoasymcipherapi-oh-cryptosm2ciphertextspec.md) **spec | [out] 指向SM2密文规格指针的指针。spec不能为NULL，*spec必须为NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | CRYPTO_SUCCESS：操作成功。<br>CRYPTO_PARAMETER_CHECK_FAILED：spec为NULL。<br>CRYPTO_NOT_SUPPORTED：不支持的操作或算法。<br>CRYPTO_MEMORY_ERROR：内存分配失败。<br>CRYPTO_OPERTION_ERROR：解析SM2密文失败。可能的原因：输入数据不是有效的DER编码SM2密文。 |

**参考：**

[OH_CryptoSm2CiphertextSpec_GetItem](capi-crypto-asym-cipher-h.md#oh_cryptosm2ciphertextspec_getitem) 获取SM2密文的指定项。

[OH_CryptoSm2CiphertextSpec_SetItem](capi-crypto-asym-cipher-h.md#oh_cryptosm2ciphertextspec_setitem) 设置SM2密文规格的指定项。


### OH_CryptoSm2CiphertextSpec_GetItem()

```c
OH_Crypto_ErrCode OH_CryptoSm2CiphertextSpec_GetItem(OH_CryptoSm2CiphertextSpec *spec, CryptoSm2CiphertextSpec_item item, Crypto_DataBlob *out)
```

**描述**

获取SM2密文的指定项。

注意：使用完成后必须通过[OH_Crypto_FreeDataBlob](capi-crypto-common-h.md#oh_crypto_freedatablob)释放out内存。

**起始版本：** 20

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoSm2CiphertextSpec](capi-cryptoasymcipherapi-oh-cryptosm2ciphertextspec.md) *spec | [in] SM2密文规格。不能为NULL。 |
| [CryptoSm2CiphertextSpec_item](capi-crypto-asym-cipher-h.md#cryptosm2ciphertextspec_item) item | [in] SM2密文规格项。 |
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *out | [out] 指向用于存储输出数据的Crypto_DataBlob结构体的指针。不能为NULL。调用前需将out初始化为{0}，不要预分配out->data内存。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | CRYPTO_SUCCESS：操作成功。<br>CRYPTO_PARAMETER_CHECK_FAILED：spec或out为NULL。<br>CRYPTO_NOT_SUPPORTED：不支持的操作或算法。<br>CRYPTO_MEMORY_ERROR：内存分配失败。<br>CRYPTO_OPERTION_ERROR：加解密操作失败。 |

### OH_CryptoSm2CiphertextSpec_SetItem()

```c
OH_Crypto_ErrCode OH_CryptoSm2CiphertextSpec_SetItem(OH_CryptoSm2CiphertextSpec *spec, CryptoSm2CiphertextSpec_item item, Crypto_DataBlob *in)
```

**描述**

设置SM2密文规格的指定项。

**起始版本：** 20

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoSm2CiphertextSpec](capi-cryptoasymcipherapi-oh-cryptosm2ciphertextspec.md) *spec | [in] SM2密文规格。不能为NULL。 |
| [CryptoSm2CiphertextSpec_item](capi-crypto-asym-cipher-h.md#cryptosm2ciphertextspec_item) item | [in] SM2密文规格项。 |
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *in | [in] 输入数据。不能为NULL。本接口会对输入数据进行深拷贝，调用者在接口返回后可立即释放in。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | CRYPTO_SUCCESS：操作成功。<br>CRYPTO_PARAMETER_CHECK_FAILED：spec或in为NULL、in->data为NULL或in->len为0。<br>CRYPTO_NOT_SUPPORTED：不支持的操作或算法。<br>CRYPTO_MEMORY_ERROR：深拷贝的内存分配失败。<br>CRYPTO_OPERTION_ERROR：加解密操作失败。 |

**参考：**

[OH_CryptoSm2CiphertextSpec_Encode](capi-crypto-asym-cipher-h.md#oh_cryptosm2ciphertextspec_encode) 将SM2密文规格编码为DER格式密文。


### OH_CryptoSm2CiphertextSpec_Encode()

```c
OH_Crypto_ErrCode OH_CryptoSm2CiphertextSpec_Encode(OH_CryptoSm2CiphertextSpec *spec, Crypto_DataBlob *out)
```

**描述**

将SM2密文规格编码为DER格式密文。

注意：使用完成后必须通过[OH_Crypto_FreeDataBlob](capi-crypto-common-h.md#oh_crypto_freedatablob)释放out内存。

**起始版本：** 20

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoSm2CiphertextSpec](capi-cryptoasymcipherapi-oh-cryptosm2ciphertextspec.md) *spec | [in] SM2密文规格。不能为NULL。 |
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *out | [out] 指向用于存储编码数据的Crypto_DataBlob结构体的指针。不能为NULL。调用前需将out初始化为{0}，不要预分配out->data内存。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | CRYPTO_SUCCESS：操作成功。<br>CRYPTO_PARAMETER_CHECK_FAILED：spec或out为NULL，或SM2密文字段（C1X、C1Y、C2、C3）未设置，或C3（hashData）长度不为32字节。<br>CRYPTO_NOT_SUPPORTED：不支持的操作或算法。<br>CRYPTO_MEMORY_ERROR：内存操作失败。<br>CRYPTO_OPERTION_ERROR：编码失败。 |

### OH_CryptoSm2CiphertextSpec_Destroy()

```c
void OH_CryptoSm2CiphertextSpec_Destroy(OH_CryptoSm2CiphertextSpec *spec)
```

**描述**

销毁SM2密文规格。

**起始版本：** 20

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoSm2CiphertextSpec](capi-cryptoasymcipherapi-oh-cryptosm2ciphertextspec.md) *spec | [in] SM2密文规格。 |


