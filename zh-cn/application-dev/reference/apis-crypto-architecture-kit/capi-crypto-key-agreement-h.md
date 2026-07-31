# crypto_key_agreement.h

<!--Kit: Crypto Architecture Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--Designer: @lanming-->
<!--Tester: @PAFT-->
<!--Adviser: @zengyawen-->

## 概述

定义密钥协商接口。

**引用文件：** <CryptoArchitectureKit/crypto_key_agreement.h>

**库：** libohcrypto.so

**系统能力：** SystemCapability.Security.CryptoFramework

**起始版本：** 20

**相关模块：** [CryptoKeyAgreementApi](capi-cryptokeyagreementapi.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_CryptoKeyAgreement](capi-cryptokeyagreementapi-oh-cryptokeyagreement.md) | OH_CryptoKeyAgreement | 密钥协商结构体，表示密钥协商上下文。 |

### 函数

| 名称 | 描述 |
| -- | -- |
| [OH_Crypto_ErrCode OH_CryptoKeyAgreement_Create(const char *algoName, OH_CryptoKeyAgreement **ctx)](#oh_cryptokeyagreement_create) | 根据给定的算法名称创建密钥协商上下文。<br> 注意：创建的资源必须通过[OH_CryptoKeyAgreement_Destroy](capi-crypto-key-agreement-h.md#oh_cryptokeyagreement_destroy)销毁。  |
| [OH_Crypto_ErrCode OH_CryptoKeyAgreement_GenerateSecret(OH_CryptoKeyAgreement *ctx, OH_CryptoPrivKey *privkey, OH_CryptoPubKey *pubkey, Crypto_DataBlob *secret)](#oh_cryptokeyagreement_generatesecret) | 生成共享秘密值。<br> 注意：使用完成后必须通过[OH_Crypto_FreeDataBlob](capi-crypto-common-h.md#oh_crypto_freedatablob)释放secret内存。  |
| [void OH_CryptoKeyAgreement_Destroy(OH_CryptoKeyAgreement *ctx)](#oh_cryptokeyagreement_destroy) | 销毁密钥协商上下文。 |

## 函数说明

### OH_CryptoKeyAgreement_Create()

```c
OH_Crypto_ErrCode OH_CryptoKeyAgreement_Create(const char *algoName, OH_CryptoKeyAgreement **ctx)
```

**描述**

根据给定的算法名称创建密钥协商上下文。

注意：创建的资源必须通过[OH_CryptoKeyAgreement_Destroy](capi-crypto-key-agreement-h.md#oh_cryptokeyagreement_destroy)销毁。

**起始版本：** 20

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char *algoName | [in] 密钥协商算法名称，不能为NULL。取值如下：<br>- 从API version 20开始支持ECDH系列："ECC224"、"ECC256"、"ECC384"、"ECC521"。<br>- 从API version 20开始支持ECDH BrainPool系列："ECC_BrainPoolP160r1"、"ECC_BrainPoolP160t1"、"ECC_BrainPoolP192r1"、"ECC_BrainPoolP192t1"、"ECC_BrainPoolP224r1"、"ECC_BrainPoolP224t1"、"ECC_BrainPoolP256r1"、"ECC_BrainPoolP256t1"、"ECC_BrainPoolP320r1"、"ECC_BrainPoolP320t1"、"ECC_BrainPoolP384r1"、"ECC_BrainPoolP384t1"、"ECC_BrainPoolP512r1"、"ECC_BrainPoolP512t1"。<br>- 从API version 20开始支持"ECC_Secp256k1"。<br>- 从API version 20开始支持"X25519"。<br>- 从API version 20开始支持DH系列："DH_modp1536"、"DH_modp2048"、"DH_modp3072"、"DH_modp4096"、"DH_modp6144"、"DH_modp8192"、"DH_ffdhe2048"、"DH_ffdhe3072"、"DH_ffdhe4096"、"DH_ffdhe6144"、"DH_ffdhe8192"。<br>- 从API版本26.0.0开始支持"ECC192"。 |
| [OH_CryptoKeyAgreement](capi-cryptokeyagreementapi-oh-cryptokeyagreement.md) **ctx | [out] 指向密钥协商上下文指针的指针。ctx不能为NULL，*ctx必须为NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | CRYPTO_SUCCESS：操作成功。<br>CRYPTO_PARAMETER_CHECK_FAILED：algoName或ctx为NULL。<br>CRYPTO_NOT_SUPPORTED：不支持的算法。<br>CRYPTO_MEMORY_ERROR：内存分配失败。<br>CRYPTO_OPERTION_ERROR：密钥协商操作失败。 |

**参考：**

[OH_CryptoKeyAgreement_GenerateSecret](capi-crypto-key-agreement-h.md#oh_cryptokeyagreement_generatesecret) 生成共享秘密值。


### OH_CryptoKeyAgreement_GenerateSecret()

```c
OH_Crypto_ErrCode OH_CryptoKeyAgreement_GenerateSecret(OH_CryptoKeyAgreement *ctx, OH_CryptoPrivKey *privkey, OH_CryptoPubKey *pubkey, Crypto_DataBlob *secret)
```

**描述**

生成共享秘密值。

注意：使用完成后必须通过[OH_Crypto_FreeDataBlob](capi-crypto-common-h.md#oh_crypto_freedatablob)释放secret内存。

**起始版本：** 20

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoKeyAgreement](capi-cryptokeyagreementapi-oh-cryptokeyagreement.md) *ctx | [in] 密钥协商上下文。不能为NULL。 |
| [OH_CryptoPrivKey](capi-cryptoasymkeyapi-oh-cryptoprivkey.md) *privkey | [in] 私钥。不能为NULL。 |
| [OH_CryptoPubKey](capi-cryptoasymkeyapi-oh-cryptopubkey.md) *pubkey | [in] 公钥。不能为NULL。 |
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *secret | [out] 指向用于存储共享秘密值的Crypto_DataBlob结构体的指针。不能为NULL。调用前需将secret初始化为{0}，不要预分配secret->data内存。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | CRYPTO_SUCCESS：操作成功。<br>CRYPTO_PARAMETER_CHECK_FAILED：ctx、privkey、pubkey或secret为NULL。<br>CRYPTO_NOT_SUPPORTED：不支持的算法。<br>CRYPTO_MEMORY_ERROR：内存分配失败。<br>CRYPTO_OPERTION_ERROR：密钥协商操作失败。可能的原因：公钥和私钥不属于同一曲线或算法，或公钥数据无效。 |

### OH_CryptoKeyAgreement_Destroy()

```c
void OH_CryptoKeyAgreement_Destroy(OH_CryptoKeyAgreement *ctx)
```

**描述**

销毁密钥协商上下文。

**起始版本：** 20

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoKeyAgreement](capi-cryptokeyagreementapi-oh-cryptokeyagreement.md) *ctx | [in] 密钥协商上下文。 |


