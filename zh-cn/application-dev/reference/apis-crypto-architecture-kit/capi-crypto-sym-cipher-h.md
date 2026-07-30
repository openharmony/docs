# crypto_sym_cipher.h

<!--Kit: Crypto Architecture Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--Designer: @lanming-->
<!--Tester: @PAFT-->
<!--Adviser: @zengyawen-->

## 概述

定义对称密钥加解密接口。

**引用文件：** <CryptoArchitectureKit/crypto_sym_cipher.h>

**库：** libohcrypto.so

**系统能力：** SystemCapability.Security.CryptoFramework

**起始版本：** 12

**相关模块：** [CryptoSymCipherApi](capi-cryptosymcipherapi.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_CryptoSymCipher](capi-cryptosymcipherapi-oh-cryptosymcipher.md) | OH_CryptoSymCipher | 对称密钥加解密结构体，表示对称密钥加解密上下文。 |
| [OH_CryptoSymCipherParams](capi-cryptosymcipherapi-oh-cryptosymcipherparams.md) | OH_CryptoSymCipherParams | 对称密钥加解密参数结构体，表示对称密钥加解密参数。 |

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [CryptoSymCipher_ParamsType](#cryptosymcipher_paramstype) | CryptoSymCipher_ParamsType | 定义加解密参数类型。 |

### 函数

| 名称 | 描述 |
| -- | -- |
| [OH_Crypto_ErrCode OH_CryptoSymCipherParams_Create(OH_CryptoSymCipherParams **params)](#oh_cryptosymcipherparams_create) | 创建对称密钥加解密参数。<br> 注意：创建的资源必须通过[OH_CryptoSymCipherParams_Destroy](capi-crypto-sym-cipher-h.md#oh_cryptosymcipherparams_destroy)销毁。  |
| [OH_Crypto_ErrCode OH_CryptoSymCipherParams_SetParam(OH_CryptoSymCipherParams *params, CryptoSymCipher_ParamsType paramsType, Crypto_DataBlob *value)](#oh_cryptosymcipherparams_setparam) | 设置加解密参数。 |
| [void OH_CryptoSymCipherParams_Destroy(OH_CryptoSymCipherParams *params)](#oh_cryptosymcipherparams_destroy) | 销毁加解密参数。 |
| [OH_Crypto_ErrCode OH_CryptoSymCipher_Create(const char *algoName, OH_CryptoSymCipher **ctx)](#oh_cryptosymcipher_create) | 根据给定的算法名称创建对称密钥加解密上下文。<br> 注意：创建的资源必须通过[OH_CryptoSymCipher_Destroy](capi-crypto-sym-cipher-h.md#oh_cryptosymcipher_destroy)销毁。  |
| [OH_Crypto_ErrCode OH_CryptoSymCipher_Init(OH_CryptoSymCipher *ctx, Crypto_CipherMode mod, OH_CryptoSymKey *key, OH_CryptoSymCipherParams *params)](#oh_cryptosymcipher_init) | 使用给定的加解密模式、密钥和参数初始化加解密操作。 |
| [OH_Crypto_ErrCode OH_CryptoSymCipher_Update(OH_CryptoSymCipher *ctx, Crypto_DataBlob *in, Crypto_DataBlob *out)](#oh_cryptosymcipher_update) | 更新加解密数据，输出已加密或已解密的数据。<br> 注意：使用完成后必须通过[OH_Crypto_FreeDataBlob](capi-crypto-common-h.md#oh_crypto_freedatablob)释放out内存。  |
| [OH_Crypto_ErrCode OH_CryptoSymCipher_Final(OH_CryptoSymCipher *ctx, Crypto_DataBlob *in, Crypto_DataBlob *out)](#oh_cryptosymcipher_final) | 结束加解密操作，输出最终结果。<br> 注意：使用完成后必须通过[OH_Crypto_FreeDataBlob](capi-crypto-common-h.md#oh_crypto_freedatablob)释放out内存。 |
| [const char *OH_CryptoSymCipher_GetAlgoName(OH_CryptoSymCipher *ctx)](#oh_cryptosymcipher_getalgoname) | 获取对称密钥加解密算法名称。 |
| [void OH_CryptoSymCipher_Destroy(OH_CryptoSymCipher *ctx)](#oh_cryptosymcipher_destroy) | 销毁对称密钥加解密上下文。 |

## 枚举类型说明

### CryptoSymCipher_ParamsType

```c
enum CryptoSymCipher_ParamsType
```

**描述**

定义加解密参数类型。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| CRYPTO_IV_DATABLOB = 100 | 初始化向量(IV)参数。 |
| CRYPTO_AAD_DATABLOB = 101 | AEAD模式（如GCM、CCM）下的附加认证数据(AAD)。 |
| CRYPTO_TAG_DATABLOB = 102 | AEAD模式（如GCM、CCM）中的认证标签(Tag)，用于数据完整性校验。 |


## 函数说明

### OH_CryptoSymCipherParams_Create()

```c
OH_Crypto_ErrCode OH_CryptoSymCipherParams_Create(OH_CryptoSymCipherParams **params)
```

**描述**

创建对称密钥加解密参数。

注意：创建的资源必须通过[OH_CryptoSymCipherParams_Destroy](capi-crypto-sym-cipher-h.md#oh_cryptosymcipherparams_destroy)销毁。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoSymCipherParams](capi-cryptosymcipherapi-oh-cryptosymcipherparams.md) **params | [out] 指向加解密参数指针的指针。params不能为NULL，*params必须为NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | CRYPTO_SUCCESS：操作成功。<br>CRYPTO_INVALID_PARAMS：params为NULL。<br>CRYPTO_NOT_SUPPORTED：不支持的操作或算法。<br>CRYPTO_MEMORY_ERROR：内存操作失败。<br>CRYPTO_OPERTION_ERROR：加解密操作失败。 |

**参考：**

[OH_CryptoSymCipherParams_SetParam](capi-crypto-sym-cipher-h.md#oh_cryptosymcipherparams_setparam) 设置加解密参数。


### OH_CryptoSymCipherParams_SetParam()

```c
OH_Crypto_ErrCode OH_CryptoSymCipherParams_SetParam(OH_CryptoSymCipherParams *params, CryptoSymCipher_ParamsType paramsType, Crypto_DataBlob *value)
```

**描述**

设置加解密参数。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoSymCipherParams](capi-cryptosymcipherapi-oh-cryptosymcipherparams.md) *params | [in] 加解密参数。不能为NULL。 |
| [CryptoSymCipher_ParamsType](capi-crypto-sym-cipher-h.md#cryptosymcipher_paramstype) paramsType | [in] 设置的加解密参数类型。 |
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *value | [in] 参数值。本接口为浅拷贝，不会复制value中的数据。 调用者必须确保value指向的内存在[OH_CryptoSymCipher_Init](capi-crypto-sym-cipher-h.md#oh_cryptosymcipher_init)调用完成前保持有效。不能为NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | CRYPTO_SUCCESS：操作成功。<br>CRYPTO_INVALID_PARAMS：params或value为NULL，或paramsType无法识别。<br>CRYPTO_NOT_SUPPORTED：不支持的操作或算法。<br>CRYPTO_MEMORY_ERROR：内存操作失败。<br>CRYPTO_OPERTION_ERROR：加解密操作失败。 |

### OH_CryptoSymCipherParams_Destroy()

```c
void OH_CryptoSymCipherParams_Destroy(OH_CryptoSymCipherParams *params)
```

**描述**

销毁加解密参数。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoSymCipherParams](capi-cryptosymcipherapi-oh-cryptosymcipherparams.md) *params | [in] 加解密参数。 |

### OH_CryptoSymCipher_Create()

```c
OH_Crypto_ErrCode OH_CryptoSymCipher_Create(const char *algoName, OH_CryptoSymCipher **ctx)
```

**描述**

根据给定的算法名称创建对称密钥加解密上下文。

注意：创建的资源必须通过[OH_CryptoSymCipher_Destroy](capi-crypto-sym-cipher-h.md#oh_cryptosymcipher_destroy)销毁。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char *algoName | [in] 对称加解密算法名称，不能为NULL。格式为"算法\|模式\|填充"，各部分以"\|"分隔。算法包括：AES128、AES192、AES256、SM4_128、3DES192、DES64、ChaCha20、RC2、Blowfish、CAST。模式包括：ECB、CBC、CTR、OFB、CFB、CFB1、CFB8、CFB64、CFB128、GCM、CCM、XTS、Poly1305。填充包括：NoPadding、PKCS5、PKCS7。各算法支持情况如下：<br>- 从API version 12开始支持AES系列：AES128、AES192、AES256算法，ECB、CBC、CTR、OFB、CFB、GCM、CCM模式，填充为NoPadding、PKCS7。 示例："AES128\|GCM"、"AES256\|CBC\|PKCS7"。<br>- 从API version 12开始支持3DES系列：3DES192算法，ECB、CBC、OFB、CFB模式，填充为NoPadding、PKCS5、PKCS7。示例："3DES192\|CBC\|PKCS5"。<br>- 从API version 12开始支持SM4系列：SM4_128算法，ECB、CBC、CTR、OFB、CFB、CFB128、GCM模式，填充为NoPadding、PKCS7。示例："SM4_128\|CBC\|PKCS7"、"SM4_128\|GCM\|NoPadding"。<br>- 从API version 20开始支持DES系列：DES64算法，ECB、CBC、OFB、CFB模式，填充为NoPadding、PKCS5、PKCS7。示例："DES64\|CBC\|PKCS5"。<br>- 从API version 22开始支持AES128_WRAP、AES192_WRAP、AES256_WRAP算法。 示例："AES128_WRAP"、"AES192_WRAP"、"AES256_WRAP"。<br>- 从API version 22开始支持"ChaCha20"、"ChaCha20\|Poly1305"。 示例："ChaCha20\|Poly1305"、"ChaCha20"。<br>- 从API version 26.0.0开始支持AES算法，XTS模式。 示例："AES128\|XTS"、"AES256\|XTS"。注意不支持AES192。<br>- 从API version 26.0.0开始支持RC2算法，ECB、CBC、OFB、CFB模式，填充为NoPadding、PKCS5、PKCS7。 示例："RC2\|CBC\|PKCS5"。<br>- 从API version 26.0.0开始支持"RC4"。 示例："RC4"。<br>- 从API version 26.0.0开始支持Blowfish算法，ECB、CBC、OFB、CFB模式，填充为NoPadding、PKCS5、PKCS7。示例："Blowfish\|CBC\|PKCS5"。<br>- 从API version 26.0.0开始支持CAST算法，ECB、CBC、OFB、CFB模式，填充为NoPadding、PKCS5、PKCS7。 示例："CAST\|CBC\|PKCS5"。填充说明：<br>- ECB、CBC模式涉及填充：当明文长度不是算法分组大小的整数倍时，必须使用PKCS5或PKCS7填充；使用NoPadding时，输入数据长度必须是算法分组大小的整数倍（AES和SM4为16字节，DES、3DES、RC2、Blowfish和CAST为8字节）。<br>- CTR、OFB、CFB、CFB1、CFB8、CFB64、CFB128、GCM、CCM模式将分组密码转化为流模式，不需要填充，指定任意填充均按NoPadding处理。<br>- XTS模式不涉及填充，不需要指定填充字段，指定任意填充均按NoPadding处理。<br>- ChaCha20为流密码算法，不需要指定填充字段，指定任意填充均按NoPadding处理。 |
| [OH_CryptoSymCipher](capi-cryptosymcipherapi-oh-cryptosymcipher.md) **ctx | [out] 指向对称密钥加解密上下文指针的指针。ctx不能为NULL，*ctx必须为NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | CRYPTO_SUCCESS：操作成功。<br>CRYPTO_INVALID_PARAMS：ctx为NULL或algoName为NULL。<br>CRYPTO_NOT_SUPPORTED：不支持的算法。<br>CRYPTO_MEMORY_ERROR：内存分配失败。<br>CRYPTO_PARAMETER_CHECK_FAILED：参数无效。适用版本：20+<br>CRYPTO_OPERTION_ERROR：加解密操作失败。 |

**参考：**

[OH_CryptoSymCipher_Init](capi-crypto-sym-cipher-h.md#oh_cryptosymcipher_init) 使用给定的加解密模式、密钥和参数初始化加解密操作。


### OH_CryptoSymCipher_Init()

```c
OH_Crypto_ErrCode OH_CryptoSymCipher_Init(OH_CryptoSymCipher *ctx, Crypto_CipherMode mod, OH_CryptoSymKey *key, OH_CryptoSymCipherParams *params)
```

**描述**

使用给定的加解密模式、密钥和参数初始化加解密操作。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoSymCipher](capi-cryptosymcipherapi-oh-cryptosymcipher.md) *ctx | [in] 对称密钥加解密上下文。不能为NULL。 |
| [Crypto_CipherMode](capi-crypto-common-h.md#crypto_ciphermode) mod | [in] 加解密模式，加密或解密。 |
| [OH_CryptoSymKey](capi-cryptosymkeyapi-oh-cryptosymkey.md) *key | [in] 对称密钥。不能为NULL。 |
| [OH_CryptoSymCipherParams](capi-cryptosymcipherapi-oh-cryptosymcipherparams.md) *params | [in] 算法参数，例如IV。ECB模式下需为NULL，其他模式不能为NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | CRYPTO_SUCCESS：操作成功。<br>CRYPTO_INVALID_PARAMS：ctx或key为NULL，或非ECB模式下IV缺失或长度错误。<br>CRYPTO_NOT_SUPPORTED：不支持的操作。<br>CRYPTO_MEMORY_ERROR：内存分配失败。<br>CRYPTO_PARAMETER_CHECK_FAILED：参数无效。适用版本：20+<br>CRYPTO_OPERTION_ERROR：加解密初始化失败。可能的原因：密钥长度与算法不匹配。 |

**参考：**

[OH_CryptoSymCipher_Update](capi-crypto-sym-cipher-h.md#oh_cryptosymcipher_update) 更新加解密数据，输出已加密或已解密的数据。

[OH_CryptoSymCipher_Final](capi-crypto-sym-cipher-h.md#oh_cryptosymcipher_final) 结束加解密操作，输出最终结果。


### OH_CryptoSymCipher_Update()

```c
OH_Crypto_ErrCode OH_CryptoSymCipher_Update(OH_CryptoSymCipher *ctx, Crypto_DataBlob *in, Crypto_DataBlob *out)
```

**描述**

更新加解密数据，输出已加密或已解密的数据。

注意：使用完成后必须通过[OH_Crypto_FreeDataBlob](capi-crypto-common-h.md#oh_crypto_freedatablob)释放out内存。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoSymCipher](capi-cryptosymcipherapi-oh-cryptosymcipher.md) *ctx | [in] 对称密钥加解密上下文。不能为NULL。 |
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *in | [in] 待加密或解密的数据。不能为NULL。 |
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *out | [out] 指向用于存储更新数据的Crypto_DataBlob结构体的指针。不能为NULL。调用前需将out初始化为{0}，不要预分配out->data内存。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | CRYPTO_SUCCESS：操作成功。<br>CRYPTO_INVALID_PARAMS：ctx、in或out为NULL。<br>CRYPTO_NOT_SUPPORTED：不支持的操作或算法。<br>CRYPTO_MEMORY_ERROR：内存操作失败。<br>CRYPTO_PARAMETER_CHECK_FAILED：参数无效。适用版本：20+<br>CRYPTO_OPERTION_ERROR：加解密更新失败。 |

**参考：**

[OH_CryptoSymCipher_Final](capi-crypto-sym-cipher-h.md#oh_cryptosymcipher_final) 结束加解密操作，输出最终结果。


### OH_CryptoSymCipher_Final()

```c
OH_Crypto_ErrCode OH_CryptoSymCipher_Final(OH_CryptoSymCipher *ctx, Crypto_DataBlob *in, Crypto_DataBlob *out)
```

**描述**

结束加解密操作，输出最终结果。

注意：使用完成后必须通过[OH_Crypto_FreeDataBlob](capi-crypto-common-h.md#oh_crypto_freedatablob)释放out内存。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoSymCipher](capi-cryptosymcipherapi-oh-cryptosymcipher.md) *ctx | [in] 对称密钥加解密上下文。不能为NULL。 |
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *in | [in] 待加密或解密的数据。如果数据已通过[OH_CryptoSymCipher_Update](capi-crypto-sym-cipher-h.md#oh_cryptosymcipher_update)接口更新了所有数据，此参数可以为NULL。 |
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *out | [out] 指向用于存储最终结果的Crypto_DataBlob结构体的指针。不能为NULL。调用前需将out初始化为{0}，不要预分配out->data内存。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | CRYPTO_SUCCESS：操作成功。<br>CRYPTO_INVALID_PARAMS：ctx或out为NULL。<br>CRYPTO_NOT_SUPPORTED：不支持的操作或算法。<br>CRYPTO_MEMORY_ERROR：内存操作失败。<br>CRYPTO_PARAMETER_CHECK_FAILED：参数无效。适用版本：20+<br>CRYPTO_OPERTION_ERROR：加解密完成失败。可能的原因：<br>解密时IV或密钥错误；AEAD（GCM/CCM）认证标签验证失败（TAG、AAD、密文或密钥错误）；<br>分组密码（如AES-CBC/ECB）解密时密文长度不是分组大小的整数倍；<br>分组密码使用NoPadding加密时明文长度不是分组大小的整数倍。 |

### OH_CryptoSymCipher_GetAlgoName()

```c
const char *OH_CryptoSymCipher_GetAlgoName(OH_CryptoSymCipher *ctx)
```

**描述**

获取对称密钥加解密算法名称。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoSymCipher](capi-cryptosymcipherapi-oh-cryptosymcipher.md) *ctx | [in] 对称密钥加解密上下文。不能为NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| const char * | 返回对称密钥加解密算法名称，不需要调用者释放，在上下文销毁后不可使用。 |

### OH_CryptoSymCipher_Destroy()

```c
void OH_CryptoSymCipher_Destroy(OH_CryptoSymCipher *ctx)
```

**描述**

销毁对称密钥加解密上下文。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoSymCipher](capi-cryptosymcipherapi-oh-cryptosymcipher.md) *ctx | [in] 对称密钥加解密上下文。 |


