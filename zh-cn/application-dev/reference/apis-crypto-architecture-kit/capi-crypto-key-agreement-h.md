# crypto_key_agreement.h

## 概述

定义密钥协商接口。

**库：** libohcrypto.so

**引用文件：** <CryptoArchitectureKit/crypto_key_agreement.h>

**系统能力：** SystemCapability.Security.CryptoFramework

**起始版本：** 20

**相关模块：** [CryptoKeyAgreementApi](capi-cryptokeyagreementapi.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_CryptoKeyAgreement](capi-cryptokeyagreementapi-oh-cryptokeyagreement.md) | OH_CryptoKeyAgreement | 定义密钥协商结构。 |

### 函数

| 名称 | 描述 |
| -- | -- |
| [OH_Crypto_ErrCode OH_CryptoKeyAgreement_Create(const char *algoName, OH_CryptoKeyAgreement **ctx)](#oh_cryptokeyagreement_create) | 根据给定的算法名称创建密钥协商实例。 |
| [OH_Crypto_ErrCode OH_CryptoKeyAgreement_GenerateSecret(OH_CryptoKeyAgreement *ctx, OH_CryptoPrivKey *privkey,OH_CryptoPubKey *pubkey, Crypto_DataBlob *secret)](#oh_cryptokeyagreement_generatesecret) | 生成密钥协商的秘密值。 |
| [void OH_CryptoKeyAgreement_Destroy(OH_CryptoKeyAgreement *ctx)](#oh_cryptokeyagreement_destroy) | 销毁密钥协商实例。 |

## 函数说明

### OH_CryptoKeyAgreement_Create()

```
OH_Crypto_ErrCode OH_CryptoKeyAgreement_Create(const char *algoName, OH_CryptoKeyAgreement **ctx)
```

**描述**

根据给定的算法名称创建密钥协商实例。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char *algoName | 用于生成密钥协商实例的算法名称。<br>例如"ECC"、"X25519"。 |
| [OH_CryptoKeyAgreement](capi-cryptokeyagreementapi-oh-cryptokeyagreement.md) **ctx |密钥协商实例。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | CRYPTO_SUCCESS = 0 : 操作成功。<br>         CRYPTO_INVALID_PARAMS = 401 : 参数无效。<br>         CRYPTO_NOT_SUPPORTED = 801 : 操作不支持。<br>         CRYPTO_MEMORY_ERROR = 17620001 : 内存错误。<br>         CRYPTO_OPERTION_ERROR = 17630001 : 调用三方算法库API出错。 |

### OH_CryptoKeyAgreement_GenerateSecret()

```
OH_Crypto_ErrCode OH_CryptoKeyAgreement_GenerateSecret(OH_CryptoKeyAgreement *ctx, OH_CryptoPrivKey *privkey,OH_CryptoPubKey *pubkey, Crypto_DataBlob *secret)
```

**描述**

生成密钥协商的秘密值。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoKeyAgreement](capi-cryptokeyagreementapi-oh-cryptokeyagreement.md) *ctx |密钥协商实例。 |
| [OH_CryptoPrivKey](capi-cryptoasymkeyapi-oh-cryptoprivkey.md) *privkey | 私钥。 |
| [OH_CryptoPubKey](capi-cryptoasymkeyapi-oh-cryptopubkey.md) *pubkey | 公钥。 |
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *secret | 秘密值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | CRYPTO_SUCCESS = 0 : 操作成功。<br>         CRYPTO_INVALID_PARAMS = 401 : 参数无效。<br>         CRYPTO_NOT_SUPPORTED = 801 : 操作不支持。<br>         CRYPTO_MEMORY_ERROR = 17620001 : 内存错误。<br>         CRYPTO_OPERTION_ERROR = 17630001 : 调用三方算法库API出错。 |

### OH_CryptoKeyAgreement_Destroy()

```
void OH_CryptoKeyAgreement_Destroy(OH_CryptoKeyAgreement *ctx)
```

**描述**

销毁密钥协商实例。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoKeyAgreement](capi-cryptokeyagreementapi-oh-cryptokeyagreement.md) *ctx |密钥协商实例。 |


