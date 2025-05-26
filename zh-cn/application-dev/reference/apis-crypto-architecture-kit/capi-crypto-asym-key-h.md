# crypto_asym_key.h

## 概述

声明非对称密钥接口。

**库：** libohcrypto.so

**引用文件：** <CryptoArchitectureKit/crypto_asym_key.h>

**系统能力：** SystemCapability.Security.CryptoFramework

**起始版本：** 12

**相关模块：** [CryptoAsymKeyApi](capi-cryptoasymkeyapi.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_CryptoKeyPair](capi-oh-cryptokeypair.md) | OH_CryptoKeyPair | 定义密钥对结构体。 |
| [OH_CryptoPubKey](capi-oh-cryptopubkey.md) | OH_CryptoPubKey | 定义公钥结构体。 |
| [OH_CryptoAsymKeyGenerator](capi-oh-cryptoasymkeygenerator.md) | OH_CryptoAsymKeyGenerator | 定义非对称密钥生成器结构体。 |

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [CryptoAsymKey_ParamType](#cryptoasymkey_paramtype) | CryptoAsymKey_ParamType | 定义非对称密钥参数类型。 |
| [Crypto_EncodingType](#crypto_encodingtype) | Crypto_EncodingType | 定义编码格式。 |

### 函数

| 名称 | 描述 |
| -- | -- |
| [OH_Crypto_ErrCode OH_CryptoAsymKeyGenerator_Create(const char *algoName, OH_CryptoAsymKeyGenerator **ctx)](#oh_cryptoasymkeygenerator_create) | 通过指定算法名称的字符串，获取相应的非对称密钥生成器实例。 |
| [OH_Crypto_ErrCode OH_CryptoAsymKeyGenerator_Generate(OH_CryptoAsymKeyGenerator *ctx, OH_CryptoKeyPair **keyCtx)](#oh_cryptoasymkeygenerator_generate) | 随机生成非对称密钥（密钥对）。 |
| [OH_Crypto_ErrCode OH_CryptoAsymKeyGenerator_Convert(OH_CryptoAsymKeyGenerator *ctx, Crypto_EncodingType type,Crypto_DataBlob *pubKeyData, Crypto_DataBlob *priKeyData, OH_CryptoKeyPair **keyCtx)](#oh_cryptoasymkeygenerator_convert) | 将非对称密钥数据转换为密钥对。 |
| [const char *OH_CryptoAsymKeyGenerator_GetAlgoName(OH_CryptoAsymKeyGenerator *ctx)](#oh_cryptoasymkeygenerator_getalgoname) | 获取非对称密钥算法名称。 |
| [void OH_CryptoAsymKeyGenerator_Destroy(OH_CryptoAsymKeyGenerator *ctx)](#oh_cryptoasymkeygenerator_destroy) | 销毁非对称密钥生成器实例。 |
| [void OH_CryptoKeyPair_Destroy(OH_CryptoKeyPair *keyCtx)](#oh_cryptokeypair_destroy) | 销毁非对称密钥对实例。 |
| [OH_CryptoPubKey *OH_CryptoKeyPair_GetPubKey(OH_CryptoKeyPair *keyCtx)](#oh_cryptokeypair_getpubkey) | 从密钥对中获取公钥实例。 |
| [OH_Crypto_ErrCode OH_CryptoPubKey_Encode(OH_CryptoPubKey *key, Crypto_EncodingType type,const char *encodingStandard, Crypto_DataBlob *out)](#oh_cryptopubkey_encode) | 根据指定的编码格式输出公钥数据。 |
| [OH_Crypto_ErrCode OH_CryptoPubKey_GetParam(OH_CryptoPubKey *key, CryptoAsymKey_ParamType item, Crypto_DataBlob *value)](#oh_cryptopubkey_getparam) | 从公钥实例获取指定参数。 |

## 枚举类型说明

### CryptoAsymKey_ParamType

```
enum CryptoAsymKey_ParamType
```

**描述**

定义非对称密钥参数类型。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| CRYPTO_DSA_P_DATABLOB = 101 | DSA算法的素模数p。 |
| CRYPTO_DSA_Q_DATABLOB = 102 | DSA算法中密钥参数q（p-1的素因子）。 |
| CRYPTO_DSA_G_DATABLOB = 103 | DSA算法的参数g。 |
| CRYPTO_DSA_SK_DATABLOB = 104 | DSA算法的私钥sk。 |
| CRYPTO_DSA_PK_DATABLOB = 105 | DSA算法的公钥pk。 |
| CRYPTO_ECC_FP_P_DATABLOB = 201 | ECC算法中表示椭圆曲线Fp域的素数p。 |
| CRYPTO_ECC_A_DATABLOB = 202 | ECC算法中椭圆曲线的第一个系数a。 |
| CRYPTO_ECC_B_DATABLOB = 203 | ECC算法中椭圆曲线的第二个系数b。 |
| CRYPTO_ECC_G_X_DATABLOB = 204 | ECC算法中基点g的x坐标。 |
| CRYPTO_ECC_G_Y_DATABLOB = 205 | ECC算法中基点g的y坐标。 |
| CRYPTO_ECC_N_DATABLOB = 206 | ECC算法中基点g的阶n。 |
| CRYPTO_ECC_H_INT = 207 | ECC算法中的余因子h。 |
| CRYPTO_ECC_SK_DATABLOB = 208 | ECC算法中的私钥sk。 |
| CRYPTO_ECC_PK_X_DATABLOB = 209 | ECC算法中，公钥pk（椭圆曲线上的一个点）的x坐标。 |
| CRYPTO_ECC_PK_Y_DATABLOB = 210 | ECC算法中，公钥pk（椭圆曲线上的一个点）的y坐标。 |
| CRYPTO_ECC_FIELD_TYPE_STR = 211 | ECC算法中，椭圆曲线的域类型（当前只支持Fp域）。 |
| CRYPTO_ECC_FIELD_SIZE_INT = 212 | ECC算法中域的大小，单位为bits（注：对于Fp域，域的大小为素数p的bits长度）。 |
| CRYPTO_ECC_CURVE_NAME_STR = 213 | ECC算法中的SECG（Standards for Efficient Cryptography Group）曲线名称。 |
| CRYPTO_RSA_N_DATABLOB = 301 | RSA算法中的模数n。 |
| CRYPTO_RSA_D_DATABLOB = 302 | RSA算法中的私钥sk（即私钥指数d）。 |
| CRYPTO_RSA_E_DATABLOB = 303 | RSA算法中的公钥pk（即公钥指数e）。 |
| CRYPTO_DH_P_DATABLOB = 401 | DH算法中的素数p。 |
| CRYPTO_DH_G_DATABLOB = 402 | DH算法中的参数g。 |
| CRYPTO_DH_L_INT = 403 | DH算法中私钥长度，单位为bit。 |
| CRYPTO_DH_SK_DATABLOB = 404 | DH算法中的私钥sk。 |
| CRYPTO_DH_PK_DATABLOB = 405 | DH算法中的公钥pk。 |
| CRYPTO_ED25519_SK_DATABLOB = 501 | ED25519算法中的私钥sk。 |
| CRYPTO_ED25519_PK_DATABLOB = 502 | ED25519算法中的公钥pk。 |
| CRYPTO_X25519_SK_DATABLOB = 601 | X25519算法中的私钥sk。 |
| CRYPTO_X25519_PK_DATABLOB = 602 | X25519算法中的公钥pk。 |

### Crypto_EncodingType

```
enum Crypto_EncodingType
```

**描述**

定义编码格式。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| CRYPTO_PEM = 0 | PEM格式密钥类型。 |
| CRYPTO_DER = 1 | DER格式密钥类型。 |

## 函数说明

### OH_CryptoAsymKeyGenerator_Create()

```
OH_Crypto_ErrCode OH_CryptoAsymKeyGenerator_Create(const char *algoName, OH_CryptoAsymKeyGenerator **ctx)
```

**描述**

通过指定算法名称的字符串，获取相应的非对称密钥生成器实例。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char *algoName |  用于生成生成器的算法名称。<br>例如"RSA1024\|PRIMES_2"。 |
| [OH_CryptoAsymKeyGenerator](capi-oh-cryptoasymkeygenerator.md) **ctx |  指向非对称密钥生成器上下文的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) |  CRYPTO_SUCCESS = 0 : 操作成功。<br>         CRYPTO_INVALID_PARAMS = 401 : 参数无效。<br>         CRYPTO_NOT_SUPPORTED = 801 : 操作不支持。<br>         CRYPTO_MEMORY_ERROR = 17620001 : 内存错误。<br>         CRYPTO_OPERTION_ERROR = 17630001 : 调用三方算法库API出错。 |

### OH_CryptoAsymKeyGenerator_Generate()

```
OH_Crypto_ErrCode OH_CryptoAsymKeyGenerator_Generate(OH_CryptoAsymKeyGenerator *ctx, OH_CryptoKeyPair **keyCtx)
```

**描述**

随机生成非对称密钥（密钥对）。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoAsymKeyGenerator](capi-oh-cryptoasymkeygenerator.md) *ctx |  非对称密钥生成器实例。 |
| [OH_CryptoKeyPair](capi-oh-cryptokeypair.md) **keyCtx |  指向非对称密钥对实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) |  CRYPTO_SUCCESS = 0 : 操作成功。<br>         CRYPTO_INVALID_PARAMS = 401 : 参数无效。<br>         CRYPTO_NOT_SUPPORTED = 801 : 操作不支持。<br>         CRYPTO_MEMORY_ERROR = 17620001 : 内存错误。<br>         CRYPTO_OPERTION_ERROR = 17630001 : 调用三方算法库API出错。 |

### OH_CryptoAsymKeyGenerator_Convert()

```
OH_Crypto_ErrCode OH_CryptoAsymKeyGenerator_Convert(OH_CryptoAsymKeyGenerator *ctx, Crypto_EncodingType type,Crypto_DataBlob *pubKeyData, Crypto_DataBlob *priKeyData, OH_CryptoKeyPair **keyCtx)
```

**描述**

将非对称密钥数据转换为密钥对。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoAsymKeyGenerator](capi-oh-cryptoasymkeygenerator.md) *ctx |  非对称密钥生成器实例。 |
| [Crypto_EncodingType](#crypto_encodingtype) type | 编码格式。 |
| [Crypto_DataBlob](capi-crypto-datablob.md) *pubKeyData |  公钥数据。 |
| [Crypto_DataBlob](capi-crypto-datablob.md) *priKeyData |  私钥数据。 |
| [OH_CryptoKeyPair](capi-oh-cryptokeypair.md) **keyCtx |  指向非对称密钥对实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) |  CRYPTO_SUCCESS = 0 : 操作成功。<br>         CRYPTO_INVALID_PARAMS = 401 : 参数无效。<br>         CRYPTO_NOT_SUPPORTED = 801 : 操作不支持。<br>         CRYPTO_MEMORY_ERROR = 17620001 : 内存错误。<br>         CRYPTO_OPERTION_ERROR = 17630001 : 调用三方算法库API出错。 |

### OH_CryptoAsymKeyGenerator_GetAlgoName()

```
const char *OH_CryptoAsymKeyGenerator_GetAlgoName(OH_CryptoAsymKeyGenerator *ctx)
```

**描述**

获取非对称密钥算法名称。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoAsymKeyGenerator](capi-oh-cryptoasymkeygenerator.md) *ctx | 非对称密钥生成器实例。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| const char | 返回非对称密钥算法名称。 |

### OH_CryptoAsymKeyGenerator_Destroy()

```
void OH_CryptoAsymKeyGenerator_Destroy(OH_CryptoAsymKeyGenerator *ctx)
```

**描述**

销毁非对称密钥生成器实例。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoAsymKeyGenerator](capi-oh-cryptoasymkeygenerator.md) *ctx |  非对称密钥生成器实例。 |

### OH_CryptoKeyPair_Destroy()

```
void OH_CryptoKeyPair_Destroy(OH_CryptoKeyPair *keyCtx)
```

**描述**

销毁非对称密钥对实例。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoKeyPair](capi-oh-cryptokeypair.md) *keyCtx |  密钥对实例。 |

### OH_CryptoKeyPair_GetPubKey()

```
OH_CryptoPubKey *OH_CryptoKeyPair_GetPubKey(OH_CryptoKeyPair *keyCtx)
```

**描述**

从密钥对中获取公钥实例。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoKeyPair](capi-oh-cryptokeypair.md) *keyCtx | 密钥对实例。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_CryptoPubKey](capi-oh-cryptopubkey.md) | 返回从密钥对中得到的公钥实例。 |

### OH_CryptoPubKey_Encode()

```
OH_Crypto_ErrCode OH_CryptoPubKey_Encode(OH_CryptoPubKey *key, Crypto_EncodingType type,const char *encodingStandard, Crypto_DataBlob *out)
```

**描述**

根据指定的编码格式输出公钥数据。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoPubKey](capi-oh-cryptopubkey.md) *key | 公钥实例。 |
| [Crypto_EncodingType](#crypto_encodingtype) type | 编码类型。 |
| const char *encodingStandard |  编码格式。 |
| [Crypto_DataBlob](capi-crypto-datablob.md) *out |  输出的公钥结果。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) |  CRYPTO_SUCCESS = 0 : 操作成功。<br>         CRYPTO_INVALID_PARAMS = 401 : 参数无效。<br>         CRYPTO_NOT_SUPPORTED = 801 : 操作不支持。<br>         CRYPTO_MEMORY_ERROR = 17620001 : 内存错误。<br>         CRYPTO_OPERTION_ERROR = 17630001 : 调用三方算法库API出错。 |

### OH_CryptoPubKey_GetParam()

```
OH_Crypto_ErrCode OH_CryptoPubKey_GetParam(OH_CryptoPubKey *key, CryptoAsymKey_ParamType item, Crypto_DataBlob *value)
```

**描述**

从公钥实例获取指定参数。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoPubKey](capi-oh-cryptopubkey.md) *key | 公钥实例。 |
| [CryptoAsymKey_ParamType](#cryptoasymkey_paramtype) item | 非对称密钥参数类型。 |
| [Crypto_DataBlob](capi-crypto-datablob.md) *value |  参数输出值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) |  CRYPTO_SUCCESS = 0 : 操作成功。<br>         CRYPTO_INVALID_PARAMS = 401 : 参数无效。<br>         CRYPTO_NOT_SUPPORTED = 801 : 操作不支持。<br>         CRYPTO_MEMORY_ERROR = 17620001 : 内存错误。<br>         CRYPTO_OPERTION_ERROR = 17630001 : 调用三方算法库API出错。 |
