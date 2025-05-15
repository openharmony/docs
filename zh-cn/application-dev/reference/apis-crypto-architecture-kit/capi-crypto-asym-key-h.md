# crypto_asym_key.h

## 概述

声明非对称密钥接口。

**库：** libohcrypto.so

**系统能力：** SystemCapability.Security.CryptoFramework

**起始版本：** 12

**相关模块：** [CryptoAsymKeyApi](capi-cryptoasymkeyapi.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_CryptoKeyPair](capi-oh-cryptokeypair.md) | OH_CryptoKeyPair | 定义密钥对结构。 |
| [OH_CryptoPubKey](capi-oh-cryptopubkey.md) | OH_CryptoPubKey | 定义公钥结构。 |
| [OH_CryptoPrivKey](capi-oh-cryptoprivkey.md) | OH_CryptoPrivKey | 定义私钥结构。 |
| [OH_CryptoAsymKeyGenerator](capi-oh-cryptoasymkeygenerator.md) | OH_CryptoAsymKeyGenerator | 定义非对称密钥生成器结构。 |
| [OH_CryptoPrivKeyEncodingParams](capi-oh-cryptoprivkeyencodingparams.md) | OH_CryptoPrivKeyEncodingParams | 定义私钥编码参数结构。 |
| [OH_CryptoAsymKeySpec](capi-oh-cryptoasymkeyspec.md) | OH_CryptoAsymKeySpec | 定义非对称密钥规格结构。 |
| [OH_CryptoAsymKeyGeneratorWithSpec](capi-oh-cryptoasymkeygeneratorwithspec.md) | OH_CryptoAsymKeyGeneratorWithSpec | 定义带规格的非对称密钥生成器。 |
| [OH_CryptoEcPoint](capi-oh-cryptoecpoint.md) | OH_CryptoEcPoint | 定义EC点结构。 |

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [CryptoAsymKey_ParamType](#cryptoasymkey_paramtype) | CryptoAsymKey_ParamType | 定义非对称密钥参数类型。 |
| [Crypto_EncodingType](#crypto_encodingtype) | Crypto_EncodingType | 定义编码类型。 |
| [CryptoPrivKeyEncoding_ParamType](#cryptoprivkeyencoding_paramtype) | CryptoPrivKeyEncoding_ParamType | 定义私钥编码参数类型。 |
| [CryptoAsymKeySpec_Type](#cryptoasymkeyspec_type) | CryptoAsymKeySpec_Type | 定义非对称密钥规格类型。 |

### 函数

| 名称 | 描述 |
| -- | -- |
| [OH_Crypto_ErrCode OH_CryptoAsymKeyGenerator_Create(const char *algoName, OH_CryptoAsymKeyGenerator **ctx)](#oh_cryptoasymkeygenerator_create) | 根据给定的算法名称创建非对称密钥生成器。 |
| [OH_Crypto_ErrCode OH_CryptoAsymKeyGenerator_Generate(OH_CryptoAsymKeyGenerator *ctx, OH_CryptoKeyPair **keyCtx)](#oh_cryptoasymkeygenerator_generate) | 生成非对称密钥(密钥对)。 |
| [OH_Crypto_ErrCode OH_CryptoAsymKeyGenerator_Convert(OH_CryptoAsymKeyGenerator *ctx, Crypto_EncodingType type,Crypto_DataBlob *pubKeyData, Crypto_DataBlob *priKeyData, OH_CryptoKeyPair **keyCtx)](#oh_cryptoasymkeygenerator_convert) | 将非对称密钥数据转换为密钥对。 |
| [const char *OH_CryptoAsymKeyGenerator_GetAlgoName(OH_CryptoAsymKeyGenerator *ctx)](#oh_cryptoasymkeygenerator_getalgoname) | 获取非对称密钥生成器的算法名称。 |
| [void OH_CryptoAsymKeyGenerator_Destroy(OH_CryptoAsymKeyGenerator *ctx)](#oh_cryptoasymkeygenerator_destroy) | 销毁非对称密钥生成器。 |
| [void OH_CryptoKeyPair_Destroy(OH_CryptoKeyPair *keyCtx)](#oh_cryptokeypair_destroy) | 销毁密钥对。 |
| [OH_CryptoPubKey *OH_CryptoKeyPair_GetPubKey(OH_CryptoKeyPair *keyCtx)](#oh_cryptokeypair_getpubkey) | 获取密钥对的公钥。 |
| [OH_CryptoPrivKey *OH_CryptoKeyPair_GetPrivKey(OH_CryptoKeyPair *keyCtx)](#oh_cryptokeypair_getprivkey) | 获取密钥对的私钥。 |
| [OH_Crypto_ErrCode OH_CryptoPubKey_Encode(OH_CryptoPubKey *key, Crypto_EncodingType type,const char *encodingStandard, Crypto_DataBlob *out)](#oh_cryptopubkey_encode) | 编码公钥。 |
| [OH_Crypto_ErrCode OH_CryptoPubKey_GetParam(OH_CryptoPubKey *key, CryptoAsymKey_ParamType item, Crypto_DataBlob *value)](#oh_cryptopubkey_getparam) | 获取公钥的指定参数。 |
| [OH_Crypto_ErrCode OH_CryptoPrivKeyEncodingParams_Create(OH_CryptoPrivKeyEncodingParams **ctx)](#oh_cryptoprivkeyencodingparams_create) | 创建私钥编码参数。 |
| [OH_Crypto_ErrCode OH_CryptoPrivKeyEncodingParams_SetParam(OH_CryptoPrivKeyEncodingParams *ctx,CryptoPrivKeyEncoding_ParamType type, Crypto_DataBlob *value)](#oh_cryptoprivkeyencodingparams_setparam) | 设置私钥编码参数。 |
| [void OH_CryptoPrivKeyEncodingParams_Destroy(OH_CryptoPrivKeyEncodingParams *ctx)](#oh_cryptoprivkeyencodingparams_destroy) | 销毁私钥编码参数。 |
| [OH_Crypto_ErrCode OH_CryptoPrivKey_Encode(OH_CryptoPrivKey *key, Crypto_EncodingType type,const char *encodingStandard, OH_CryptoPrivKeyEncodingParams *params, Crypto_DataBlob *out)](#oh_cryptoprivkey_encode) | 编码私钥。 |
| [OH_Crypto_ErrCode OH_CryptoPrivKey_GetParam(OH_CryptoPrivKey *key, CryptoAsymKey_ParamType item,Crypto_DataBlob *value)](#oh_cryptoprivkey_getparam) | 获取私钥的指定参数。 |
| [OH_Crypto_ErrCode OH_CryptoAsymKeySpec_GenEcCommonParamsSpec(const char *curveName, OH_CryptoAsymKeySpec **spec)](#oh_cryptoasymkeyspec_geneccommonparamsspec) | 生成EC通用参数规格。 |
| [OH_Crypto_ErrCode OH_CryptoAsymKeySpec_GenDhCommonParamsSpec(int pLen, int skLen, OH_CryptoAsymKeySpec **spec)](#oh_cryptoasymkeyspec_gendhcommonparamsspec) | 生成DH通用参数规格。 |
| [OH_Crypto_ErrCode OH_CryptoAsymKeySpec_Create(const char *algoName, CryptoAsymKeySpec_Type type,OH_CryptoAsymKeySpec **spec)](#oh_cryptoasymkeyspec_create) | 根据给定的算法名称和规格类型创建非对称密钥规格。 |
| [OH_Crypto_ErrCode OH_CryptoAsymKeySpec_SetParam(OH_CryptoAsymKeySpec *spec, CryptoAsymKey_ParamType type,Crypto_DataBlob *value)](#oh_cryptoasymkeyspec_setparam) | 设置非对称密钥规格的指定参数。 |
| [OH_Crypto_ErrCode OH_CryptoAsymKeySpec_SetCommonParamsSpec(OH_CryptoAsymKeySpec *spec,OH_CryptoAsymKeySpec *commonParamsSpec)](#oh_cryptoasymkeyspec_setcommonparamsspec) | 设置非对称密钥规格的通用参数规格。 |
| [OH_Crypto_ErrCode OH_CryptoAsymKeySpec_GetParam(OH_CryptoAsymKeySpec *spec, CryptoAsymKey_ParamType type,Crypto_DataBlob *value)](#oh_cryptoasymkeyspec_getparam) | 获取非对称密钥规格的指定参数。 |
| [void OH_CryptoAsymKeySpec_Destroy(OH_CryptoAsymKeySpec *spec)](#oh_cryptoasymkeyspec_destroy) | 销毁非对称密钥规格。 |
| [OH_Crypto_ErrCode OH_CryptoAsymKeyGeneratorWithSpec_Create(OH_CryptoAsymKeySpec *keySpec,OH_CryptoAsymKeyGeneratorWithSpec **generator)](#oh_cryptoasymkeygeneratorwithspec_create) | 创建带规格的非对称密钥生成器。 |
| [OH_Crypto_ErrCode OH_CryptoAsymKeyGeneratorWithSpec_GenKeyPair(OH_CryptoAsymKeyGeneratorWithSpec *generator,OH_CryptoKeyPair **keyPair)](#oh_cryptoasymkeygeneratorwithspec_genkeypair) | 根据非对称密钥规格生成密钥对。 |
| [void OH_CryptoAsymKeyGeneratorWithSpec_Destroy(OH_CryptoAsymKeyGeneratorWithSpec *generator)](#oh_cryptoasymkeygeneratorwithspec_destroy) | 销毁带规格的非对称密钥生成器。 |
| [OH_Crypto_ErrCode OH_CryptoEcPoint_Create(const char *curveName, Crypto_DataBlob *ecKeyData, OH_CryptoEcPoint **point)](#oh_cryptoecpoint_create) | 创建EC点。 |
| [OH_Crypto_ErrCode OH_CryptoEcPoint_GetCoordinate(OH_CryptoEcPoint *point, Crypto_DataBlob *x, Crypto_DataBlob *y)](#oh_cryptoecpoint_getcoordinate) | 获取EC点的x和y坐标。 |
| [OH_Crypto_ErrCode OH_CryptoEcPoint_SetCoordinate(OH_CryptoEcPoint *point, Crypto_DataBlob *x, Crypto_DataBlob *y)](#oh_cryptoecpoint_setcoordinate) | 设置EC点的x和y坐标。 |
| [OH_Crypto_ErrCode OH_CryptoEcPoint_Encode(OH_CryptoEcPoint *point, const char *format, Crypto_DataBlob *out)](#oh_cryptoecpoint_encode) | 将EC点编码为指定格式。 |
| [void OH_CryptoEcPoint_Destroy(OH_CryptoEcPoint *point)](#oh_cryptoecpoint_destroy) | 销毁EC点。 |

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
| CRYPTO_DSA_P_DATABLOB = 101 | 表示DSA素数p。 |
| CRYPTO_DSA_Q_DATABLOB = 102 | 表示DSA子素数q。 |
| CRYPTO_DSA_G_DATABLOB = 103 | 表示DSA基数g。 |
| CRYPTO_DSA_SK_DATABLOB = 104 | 表示DSA私钥。 |
| CRYPTO_DSA_PK_DATABLOB = 105 | 表示DSA公钥。 |
| CRYPTO_ECC_FP_P_DATABLOB = 201 | ECC算法中表示椭圆曲线（EC）素数有限域的素数 p。 |
| CRYPTO_ECC_A_DATABLOB = 202 | 表示椭圆曲线的第一系数a。 |
| CRYPTO_ECC_B_DATABLOB = 203 | 表示椭圆曲线的第二系数b。 |
| CRYPTO_ECC_G_X_DATABLOB = 204 | 表示基点g的仿射x坐标。 |
| CRYPTO_ECC_G_Y_DATABLOB = 205 | 表示基点g的仿射y坐标。 |
| CRYPTO_ECC_N_DATABLOB = 206 | 表示基点g的阶。 |
| CRYPTO_ECC_H_INT = 207 | 表示椭圆曲线的余因子。 |
| CRYPTO_ECC_SK_DATABLOB = 208 | 表示ECC私钥的私钥值。 |
| CRYPTO_ECC_PK_X_DATABLOB = 209 | 表示ECC公钥的公钥点的仿射x坐标。 |
| CRYPTO_ECC_PK_Y_DATABLOB = 210 | 表示ECC公钥的公钥点的仿射y坐标。 |
| CRYPTO_ECC_FIELD_TYPE_STR = 211 | 表示椭圆曲线有限域类型。 |
| CRYPTO_ECC_FIELD_SIZE_INT = 212 | 表示域大小(以位为单位)。 |
| CRYPTO_ECC_CURVE_NAME_STR = 213 | 表示根据SECG(高效密码学标准组)的曲线名称。 |
| CRYPTO_RSA_N_DATABLOB = 301 | 表示RSA算法的模数n。 |
| CRYPTO_RSA_D_DATABLOB = 302 | 表示RSA算法的私钥指数d。 |
| CRYPTO_RSA_E_DATABLOB = 303 | 表示RSA算法的公钥指数e。 |
| CRYPTO_DH_P_DATABLOB = 401 | 表示DH算法的素数p。 |
| CRYPTO_DH_G_DATABLOB = 402 | 表示DH算法的生成元g。 |
| CRYPTO_DH_L_INT = 403 | 表示DH算法中使用的私钥长度的位数。 |
| CRYPTO_DH_SK_DATABLOB = 404 | 表示DH私钥的私钥值。 |
| CRYPTO_DH_PK_DATABLOB = 405 | 表示DH公钥的公钥值。 |
| CRYPTO_ED25519_SK_DATABLOB = 501 | 表示ED25519私钥的私钥值。 |
| CRYPTO_ED25519_PK_DATABLOB = 502 | 表示ED25519公钥的公钥值。 |
| CRYPTO_X25519_SK_DATABLOB = 601 | 表示X25519私钥的私钥值。 |
| CRYPTO_X25519_PK_DATABLOB = 602 | 表示X25519公钥的公钥值。 |

### Crypto_EncodingType

```
enum Crypto_EncodingType
```

**描述**

定义编码类型。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| CRYPTO_PEM = 0 | PEM格式 |
| CRYPTO_DER = 1 | DER格式 |

### CryptoPrivKeyEncoding_ParamType

```
enum CryptoPrivKeyEncoding_ParamType
```

**描述**

定义私钥编码参数类型。

**起始版本：** 20

| 枚举项 | 描述 |
| -- | -- |
| CRYPTO_PRIVATE_KEY_ENCODING_PASSWORD_STR = 0 | 表示密码字符串。 |
| CRYPTO_PRIVATE_KEY_ENCODING_SYMMETRIC_CIPHER_STR = 1 | 表示对称加密字符串。 |

### CryptoAsymKeySpec_Type

```
enum CryptoAsymKeySpec_Type
```

**描述**

定义非对称密钥规格类型。

**起始版本：** 20

| 枚举项 | 描述 |
| -- | -- |
| CRYPTO_ASYM_KEY_COMMON_PARAMS_SPEC = 0 | 通用参数规格。 |
| CRYPTO_ASYM_KEY_PRIVATE_KEY_SPEC = 1 | 私钥规格。 |
| CRYPTO_ASYM_KEY_PUBLIC_KEY_SPEC = 2 | 公钥规格。 |
| CRYPTO_ASYM_KEY_KEY_PAIR_SPEC = 3 | 密钥对规格。 |


## 函数说明

### OH_CryptoAsymKeyGenerator_Create()

```
OH_Crypto_ErrCode OH_CryptoAsymKeyGenerator_Create(const char *algoName, OH_CryptoAsymKeyGenerator **ctx)
```

**描述**

根据给定的算法名称创建非对称密钥生成器。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char *algoName | algoName 用于生成生成器的算法名称。\n例如"RSA1024|PRIMES_2"。 |
| [OH_CryptoAsymKeyGenerator](capi-oh-cryptoasymkeygenerator.md) **ctx | ctx 指向非对称密钥生成器上下文的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h#oh_crypto_errcode) | [OH_Crypto_ErrCode](capi-crypto-common-h#oh_crypto_errcode): <br>         CRYPTO_SUCCESS = 0 : 操作成功。<br>         CRYPTO_INVALID_PARAMS = 401 : 参数无效。<br>         CRYPTO_NOT_SUPPORTED = 801 : 操作不支持。<br>         CRYPTO_MEMORY_ERROR = 17620001 : 内存错误。<br>         CRYPTO_OPERTION_ERROR = 17630001 : 调用三方算法库API出错。 |

### OH_CryptoAsymKeyGenerator_Generate()

```
OH_Crypto_ErrCode OH_CryptoAsymKeyGenerator_Generate(OH_CryptoAsymKeyGenerator *ctx, OH_CryptoKeyPair **keyCtx)
```

**描述**

生成非对称密钥(密钥对)。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoAsymKeyGenerator](capi-oh-cryptoasymkeygenerator.md) *ctx | ctx 非对称密钥生成器实例。 |
| [OH_CryptoKeyPair](capi-oh-cryptokeypair.md) **keyCtx | keyCtx 指向非对称密钥对实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h#oh_crypto_errcode) | [OH_Crypto_ErrCode](capi-crypto-common-h#oh_crypto_errcode): <br>         CRYPTO_SUCCESS = 0 : 操作成功。<br>         CRYPTO_INVALID_PARAMS = 401 : 参数无效。<br>         CRYPTO_NOT_SUPPORTED = 801 : 操作不支持。<br>         CRYPTO_MEMORY_ERROR = 17620001 : 内存错误。<br>         CRYPTO_OPERTION_ERROR = 17630001 : 调用三方算法库API出错。 |

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
| [OH_CryptoAsymKeyGenerator](capi-oh-cryptoasymkeygenerator.md) *ctx | ctx 非对称密钥生成器上下文。 |
| [Crypto_EncodingType](#crypto_encodingtype) type | 加密编码类型。 |
| [Crypto_DataBlob](capi-crypto-common-hcrypto_datablob.md) *pubKeyData | pubKeyData 公钥数据。 |
| [Crypto_DataBlob](capi-crypto-common-hcrypto_datablob.md) *priKeyData | priKeyData 私钥数据。 |
| [OH_CryptoKeyPair](capi-oh-cryptokeypair.md) **keyCtx | keyCtx 指向非对称密钥对实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h#oh_crypto_errcode) | [OH_Crypto_ErrCode](capi-crypto-common-h#oh_crypto_errcode): <br>         CRYPTO_SUCCESS = 0 : 操作成功。<br>         CRYPTO_INVALID_PARAMS = 401 : 参数无效。<br>         CRYPTO_NOT_SUPPORTED = 801 : 操作不支持。<br>         CRYPTO_MEMORY_ERROR = 17620001 : 内存错误。<br>         CRYPTO_OPERTION_ERROR = 17630001 : 调用三方算法库API出错。 |

### OH_CryptoAsymKeyGenerator_GetAlgoName()

```
const char *OH_CryptoAsymKeyGenerator_GetAlgoName(OH_CryptoAsymKeyGenerator *ctx)
```

**描述**

获取非对称密钥生成器的算法名称。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoAsymKeyGenerator](capi-oh-cryptoasymkeygenerator.md) *ctx | ctx 非对称密钥生成器上下文。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| const | 返回非对称密钥算法名称。 |

### OH_CryptoAsymKeyGenerator_Destroy()

```
void OH_CryptoAsymKeyGenerator_Destroy(OH_CryptoAsymKeyGenerator *ctx)
```

**描述**

销毁非对称密钥生成器。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoAsymKeyGenerator](capi-oh-cryptoasymkeygenerator.md) *ctx | ctx 非对称密钥生成器上下文。 |

### OH_CryptoKeyPair_Destroy()

```
void OH_CryptoKeyPair_Destroy(OH_CryptoKeyPair *keyCtx)
```

**描述**

销毁密钥对。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoKeyPair](capi-oh-cryptokeypair.md) *keyCtx | keyCtx 密钥对上下文。 |

### OH_CryptoKeyPair_GetPubKey()

```
OH_CryptoPubKey *OH_CryptoKeyPair_GetPubKey(OH_CryptoKeyPair *keyCtx)
```

**描述**

获取密钥对的公钥。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoKeyPair](capi-oh-cryptokeypair.md) *keyCtx | keyCtx 密钥对上下文。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_CryptoPubKey](capi-oh-cryptopubkey.md) | 返回密钥对中的公钥上下文。 |

### OH_CryptoKeyPair_GetPrivKey()

```
OH_CryptoPrivKey *OH_CryptoKeyPair_GetPrivKey(OH_CryptoKeyPair *keyCtx)
```

**描述**

获取密钥对的私钥。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoKeyPair](capi-oh-cryptokeypair.md) *keyCtx | keyCtx 密钥对上下文。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_CryptoPrivKey](capi-oh-cryptoprivkey.md) | 返回密钥对中的私钥上下文。 |

### OH_CryptoPubKey_Encode()

```
OH_Crypto_ErrCode OH_CryptoPubKey_Encode(OH_CryptoPubKey *key, Crypto_EncodingType type,const char *encodingStandard, Crypto_DataBlob *out)
```

**描述**

编码公钥。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoPubKey](capi-oh-cryptopubkey.md) *key | key 公钥实例。 |
| [Crypto_EncodingType](#crypto_encodingtype) type | 编码类型。 |
| const char *encodingStandard | encodingStandard 编码格式。 |
| [Crypto_DataBlob](capi-crypto-common-hcrypto_datablob.md) *out | out 输出的公钥结果。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h#oh_crypto_errcode) | [OH_Crypto_ErrCode](capi-crypto-common-h#oh_crypto_errcode): <br>         CRYPTO_SUCCESS = 0 : 操作成功。<br>         CRYPTO_INVALID_PARAMS = 401 : 参数无效。<br>         CRYPTO_NOT_SUPPORTED = 801 : 操作不支持。<br>         CRYPTO_MEMORY_ERROR = 17620001 : 内存错误。<br>         CRYPTO_OPERTION_ERROR = 17630001 : 调用三方算法库API出错。 |

### OH_CryptoPubKey_GetParam()

```
OH_Crypto_ErrCode OH_CryptoPubKey_GetParam(OH_CryptoPubKey *key, CryptoAsymKey_ParamType item, Crypto_DataBlob *value)
```

**描述**

获取公钥的指定参数。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoPubKey](capi-oh-cryptopubkey.md) *key | key 公钥。 |
| [CryptoAsymKey_ParamType](#cryptoasymkey_paramtype) item | 非对称密钥参数类型。 |
| [Crypto_DataBlob](capi-crypto-common-hcrypto_datablob.md) *value | value 参数输出值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h#oh_crypto_errcode) | [OH_Crypto_ErrCode](capi-crypto-common-h#oh_crypto_errcode): <br>         CRYPTO_SUCCESS = 0 : 操作成功。<br>         CRYPTO_INVALID_PARAMS = 401 : 参数无效。<br>         CRYPTO_NOT_SUPPORTED = 801 : 操作不支持。<br>         CRYPTO_MEMORY_ERROR = 17620001 : 内存错误。<br>         CRYPTO_OPERTION_ERROR = 17630001 : 调用三方算法库API出错。 |

### OH_CryptoPrivKeyEncodingParams_Create()

```
OH_Crypto_ErrCode OH_CryptoPrivKeyEncodingParams_Create(OH_CryptoPrivKeyEncodingParams **ctx)
```

**描述**

创建私钥编码参数。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoPrivKeyEncodingParams](capi-oh-cryptoprivkeyencodingparams.md) **ctx | ctx 私钥编码参数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h#oh_crypto_errcode) | [OH_Crypto_ErrCode](capi-crypto-common-h#oh_crypto_errcode): <br>         CRYPTO_SUCCESS = 0 : 操作成功。<br>         CRYPTO_INVALID_PARAMS = 401 : 参数无效。<br>         CRYPTO_NOT_SUPPORTED = 801 : 操作不支持。<br>         CRYPTO_MEMORY_ERROR = 17620001 : 内存错误。<br>         CRYPTO_OPERTION_ERROR = 17630001 : 调用三方算法库API出错。 |

### OH_CryptoPrivKeyEncodingParams_SetParam()

```
OH_Crypto_ErrCode OH_CryptoPrivKeyEncodingParams_SetParam(OH_CryptoPrivKeyEncodingParams *ctx,CryptoPrivKeyEncoding_ParamType type, Crypto_DataBlob *value)
```

**描述**

设置私钥编码参数。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoPrivKeyEncodingParams](capi-oh-cryptoprivkeyencodingparams.md) *ctx | ctx 私钥编码参数。 |
| [CryptoPrivKeyEncoding_ParamType](#cryptoprivkeyencoding_paramtype) type | 私钥编码参数类型。 |
| [Crypto_DataBlob](capi-crypto-common-hcrypto_datablob.md) *value | value 私钥编码参数值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h#oh_crypto_errcode) | [OH_Crypto_ErrCode](capi-crypto-common-h#oh_crypto_errcode): <br>         CRYPTO_SUCCESS = 0 : 操作成功。<br>         CRYPTO_INVALID_PARAMS = 401 : 参数无效。<br>         CRYPTO_NOT_SUPPORTED = 801 : 操作不支持。<br>         CRYPTO_MEMORY_ERROR = 17620001 : 内存错误。<br>         CRYPTO_OPERTION_ERROR = 17630001 : 调用三方算法库API出错。 |

### OH_CryptoPrivKeyEncodingParams_Destroy()

```
void OH_CryptoPrivKeyEncodingParams_Destroy(OH_CryptoPrivKeyEncodingParams *ctx)
```

**描述**

销毁私钥编码参数。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoPrivKeyEncodingParams](capi-oh-cryptoprivkeyencodingparams.md) *ctx | ctx 私钥编码参数。 |

### OH_CryptoPrivKey_Encode()

```
OH_Crypto_ErrCode OH_CryptoPrivKey_Encode(OH_CryptoPrivKey *key, Crypto_EncodingType type,const char *encodingStandard, OH_CryptoPrivKeyEncodingParams *params, Crypto_DataBlob *out)
```

**描述**

编码私钥。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoPrivKey](capi-oh-cryptoprivkey.md) *key | key 私钥。 |
| [Crypto_EncodingType](#crypto_encodingtype) type | 私钥编码类型。 |
| const char *encodingStandard | encodingStandard 编码标准。\n例如"PKCS8"。 |
| [OH_CryptoPrivKeyEncodingParams](capi-oh-cryptoprivkeyencodingparams.md) *params | params 私钥编码参数，可以为NULL，如果要加密私钥，则应设置此参数。 |
| [Crypto_DataBlob](capi-crypto-common-hcrypto_datablob.md) *out | out 编码结果。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h#oh_crypto_errcode) | [OH_Crypto_ErrCode](capi-crypto-common-h#oh_crypto_errcode): <br>         CRYPTO_SUCCESS = 0 : 操作成功。<br>         CRYPTO_INVALID_PARAMS = 401 : 参数无效。<br>         CRYPTO_NOT_SUPPORTED = 801 : 操作不支持。<br>         CRYPTO_MEMORY_ERROR = 17620001 : 内存错误。<br>         CRYPTO_OPERTION_ERROR = 17630001 : 调用三方算法库API出错。 |

### OH_CryptoPrivKey_GetParam()

```
OH_Crypto_ErrCode OH_CryptoPrivKey_GetParam(OH_CryptoPrivKey *key, CryptoAsymKey_ParamType item,Crypto_DataBlob *value)
```

**描述**

获取私钥的指定参数。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoPrivKey](capi-oh-cryptoprivkey.md) *key | key 私钥。 |
| [CryptoAsymKey_ParamType](#cryptoasymkey_paramtype) item | 非对称密钥参数类型。 |
| [Crypto_DataBlob](capi-crypto-common-hcrypto_datablob.md) *value | value 输出数据。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h#oh_crypto_errcode) | [OH_Crypto_ErrCode](capi-crypto-common-h#oh_crypto_errcode): <br>         CRYPTO_SUCCESS = 0 : 操作成功。<br>         CRYPTO_INVALID_PARAMS = 401 : 参数无效。<br>         CRYPTO_NOT_SUPPORTED = 801 : 操作不支持。<br>         CRYPTO_MEMORY_ERROR = 17620001 : 内存错误。<br>         CRYPTO_OPERTION_ERROR = 17630001 : 调用三方算法库API出错。 |

### OH_CryptoAsymKeySpec_GenEcCommonParamsSpec()

```
OH_Crypto_ErrCode OH_CryptoAsymKeySpec_GenEcCommonParamsSpec(const char *curveName, OH_CryptoAsymKeySpec **spec)
```

**描述**

生成EC通用参数规格。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char *curveName | curveName ECC曲线名称。 |
| [OH_CryptoAsymKeySpec](capi-oh-cryptoasymkeyspec.md) **spec | spec 指向EC通用参数规格的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h#oh_crypto_errcode) | [OH_Crypto_ErrCode](capi-crypto-common-h#oh_crypto_errcode): <br>         CRYPTO_SUCCESS = 0 : 操作成功。<br>         CRYPTO_INVALID_PARAMS = 401 : 参数无效。<br>         CRYPTO_NOT_SUPPORTED = 801 : 操作不支持。<br>         CRYPTO_MEMORY_ERROR = 17620001 : 内存错误。<br>         CRYPTO_OPERTION_ERROR = 17630001 : 调用三方算法库API出错。 |

### OH_CryptoAsymKeySpec_GenDhCommonParamsSpec()

```
OH_Crypto_ErrCode OH_CryptoAsymKeySpec_GenDhCommonParamsSpec(int pLen, int skLen, OH_CryptoAsymKeySpec **spec)
```

**描述**

生成DH通用参数规格。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| int pLen | 素数p的字节长度。 |
| int skLen | 私钥的字节长度。 |
| [OH_CryptoAsymKeySpec](capi-oh-cryptoasymkeyspec.md) **spec | spec 指向DH通用参数规格的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h#oh_crypto_errcode) | [OH_Crypto_ErrCode](capi-crypto-common-h#oh_crypto_errcode): <br>         CRYPTO_SUCCESS = 0 : 操作成功。<br>         CRYPTO_INVALID_PARAMS = 401 : 参数无效。<br>         CRYPTO_NOT_SUPPORTED = 801 : 操作不支持。<br>         CRYPTO_MEMORY_ERROR = 17620001 : 内存错误。<br>         CRYPTO_OPERTION_ERROR = 17630001 : 调用三方算法库API出错。 |

### OH_CryptoAsymKeySpec_Create()

```
OH_Crypto_ErrCode OH_CryptoAsymKeySpec_Create(const char *algoName, CryptoAsymKeySpec_Type type,OH_CryptoAsymKeySpec **spec)
```

**描述**

根据给定的算法名称和规格类型创建非对称密钥规格。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char *algoName | algoName 用于生成规格的算法名称。\n例如"RSA"。 |
| [CryptoAsymKeySpec_Type](#cryptoasymkeyspec_type) type | 非对称密钥规格类型。 |
| [OH_CryptoAsymKeySpec](capi-oh-cryptoasymkeyspec.md) **spec | spec 指向非对称密钥规格的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h#oh_crypto_errcode) | [OH_Crypto_ErrCode](capi-crypto-common-h#oh_crypto_errcode): <br>         CRYPTO_SUCCESS = 0 : 操作成功。<br>         CRYPTO_INVALID_PARAMS = 401 : 参数无效。<br>         CRYPTO_NOT_SUPPORTED = 801 : 操作不支持。<br>         CRYPTO_MEMORY_ERROR = 17620001 : 内存错误。<br>         CRYPTO_OPERTION_ERROR = 17630001 : 调用三方算法库API出错。 |

### OH_CryptoAsymKeySpec_SetParam()

```
OH_Crypto_ErrCode OH_CryptoAsymKeySpec_SetParam(OH_CryptoAsymKeySpec *spec, CryptoAsymKey_ParamType type,Crypto_DataBlob *value)
```

**描述**

设置非对称密钥规格的指定参数。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoAsymKeySpec](capi-oh-cryptoasymkeyspec.md) *spec | spec 非对称密钥规格。 |
| [CryptoAsymKey_ParamType](#cryptoasymkey_paramtype) type | 非对称密钥参数类型。 |
| [Crypto_DataBlob](capi-crypto-common-hcrypto_datablob.md) *value | value 输入数据。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h#oh_crypto_errcode) | [OH_Crypto_ErrCode](capi-crypto-common-h#oh_crypto_errcode): <br>         CRYPTO_SUCCESS = 0 : 操作成功。<br>         CRYPTO_INVALID_PARAMS = 401 : 参数无效。<br>         CRYPTO_NOT_SUPPORTED = 801 : 操作不支持。<br>         CRYPTO_MEMORY_ERROR = 17620001 : 内存错误。<br>         CRYPTO_OPERTION_ERROR = 17630001 : 调用三方算法库API出错。 |

### OH_CryptoAsymKeySpec_SetCommonParamsSpec()

```
OH_Crypto_ErrCode OH_CryptoAsymKeySpec_SetCommonParamsSpec(OH_CryptoAsymKeySpec *spec,OH_CryptoAsymKeySpec *commonParamsSpec)
```

**描述**

设置非对称密钥规格的通用参数规格。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoAsymKeySpec](capi-oh-cryptoasymkeyspec.md) *spec | spec 非对称密钥规格。 |
| [OH_CryptoAsymKeySpec](capi-oh-cryptoasymkeyspec.md) *commonParamsSpec | commonParamsSpec 通用参数规格。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h#oh_crypto_errcode) | [OH_Crypto_ErrCode](capi-crypto-common-h#oh_crypto_errcode): <br>         CRYPTO_SUCCESS = 0 : 操作成功。<br>         CRYPTO_INVALID_PARAMS = 401 : 参数无效。<br>         CRYPTO_NOT_SUPPORTED = 801 : 操作不支持。<br>         CRYPTO_MEMORY_ERROR = 17620001 : 内存错误。<br>         CRYPTO_OPERTION_ERROR = 17630001 : 调用三方算法库API出错。 |

### OH_CryptoAsymKeySpec_GetParam()

```
OH_Crypto_ErrCode OH_CryptoAsymKeySpec_GetParam(OH_CryptoAsymKeySpec *spec, CryptoAsymKey_ParamType type,Crypto_DataBlob *value)
```

**描述**

获取非对称密钥规格的指定参数。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoAsymKeySpec](capi-oh-cryptoasymkeyspec.md) *spec | spec 非对称密钥规格。 |
| [CryptoAsymKey_ParamType](#cryptoasymkey_paramtype) type | 非对称密钥参数类型。 |
| [Crypto_DataBlob](capi-crypto-common-hcrypto_datablob.md) *value | value 输出数据。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h#oh_crypto_errcode) | [OH_Crypto_ErrCode](capi-crypto-common-h#oh_crypto_errcode): <br>         CRYPTO_SUCCESS = 0 : 操作成功。<br>         CRYPTO_INVALID_PARAMS = 401 : 参数无效。<br>         CRYPTO_NOT_SUPPORTED = 801 : 操作不支持。<br>         CRYPTO_MEMORY_ERROR = 17620001 : 内存错误。<br>         CRYPTO_OPERTION_ERROR = 17630001 : 调用三方算法库API出错。 |

### OH_CryptoAsymKeySpec_Destroy()

```
void OH_CryptoAsymKeySpec_Destroy(OH_CryptoAsymKeySpec *spec)
```

**描述**

销毁非对称密钥规格。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoAsymKeySpec](capi-oh-cryptoasymkeyspec.md) *spec | spec 非对称密钥规格。 |

### OH_CryptoAsymKeyGeneratorWithSpec_Create()

```
OH_Crypto_ErrCode OH_CryptoAsymKeyGeneratorWithSpec_Create(OH_CryptoAsymKeySpec *keySpec,OH_CryptoAsymKeyGeneratorWithSpec **generator)
```

**描述**

创建带规格的非对称密钥生成器。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoAsymKeySpec](capi-oh-cryptoasymkeyspec.md) *keySpec | keySpec 非对称密钥规格。 |
| [OH_CryptoAsymKeyGeneratorWithSpec](capi-oh-cryptoasymkeygeneratorwithspec.md) **generator | generator 带规格的非对称密钥生成器。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h#oh_crypto_errcode) | [OH_Crypto_ErrCode](capi-crypto-common-h#oh_crypto_errcode): <br>         CRYPTO_SUCCESS = 0 : 操作成功。<br>         CRYPTO_INVALID_PARAMS = 401 : 参数无效。<br>         CRYPTO_NOT_SUPPORTED = 801 : 操作不支持。<br>         CRYPTO_MEMORY_ERROR = 17620001 : 内存错误。<br>         CRYPTO_OPERTION_ERROR = 17630001 : 调用三方算法库API出错。 |

### OH_CryptoAsymKeyGeneratorWithSpec_GenKeyPair()

```
OH_Crypto_ErrCode OH_CryptoAsymKeyGeneratorWithSpec_GenKeyPair(OH_CryptoAsymKeyGeneratorWithSpec *generator,OH_CryptoKeyPair **keyPair)
```

**描述**

根据非对称密钥规格生成密钥对。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoAsymKeyGeneratorWithSpec](capi-oh-cryptoasymkeygeneratorwithspec.md) *generator | generator 带规格的非对称密钥生成器。 |
| [OH_CryptoKeyPair](capi-oh-cryptokeypair.md) **keyPair | keyPair 指向密钥对的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h#oh_crypto_errcode) | [OH_Crypto_ErrCode](capi-crypto-common-h#oh_crypto_errcode): <br>         CRYPTO_SUCCESS = 0 : 操作成功。<br>         CRYPTO_INVALID_PARAMS = 401 : 参数无效。<br>         CRYPTO_NOT_SUPPORTED = 801 : 操作不支持。<br>         CRYPTO_MEMORY_ERROR = 17620001 : 内存错误。<br>         CRYPTO_OPERTION_ERROR = 17630001 : 调用三方算法库API出错。 |

### OH_CryptoAsymKeyGeneratorWithSpec_Destroy()

```
void OH_CryptoAsymKeyGeneratorWithSpec_Destroy(OH_CryptoAsymKeyGeneratorWithSpec *generator)
```

**描述**

销毁带规格的非对称密钥生成器。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoAsymKeyGeneratorWithSpec](capi-oh-cryptoasymkeygeneratorwithspec.md) *generator | generator 带规格的非对称密钥生成器。 |

### OH_CryptoEcPoint_Create()

```
OH_Crypto_ErrCode OH_CryptoEcPoint_Create(const char *curveName, Crypto_DataBlob *ecKeyData, OH_CryptoEcPoint **point)
```

**描述**

创建EC点。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char *curveName | curveName 曲线名称。 |
| [Crypto_DataBlob](capi-crypto-common-hcrypto_datablob.md) *ecKeyData | ecKeyData EC点数据，支持"04 || x || y"、"02 || x"或"03 || x"格式。如果ecKeyData参数为NULL，将创建一个空的EC点规格。 |
| [OH_CryptoEcPoint](capi-oh-cryptoecpoint.md) **point | point 指向EC点的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h#oh_crypto_errcode) | [OH_Crypto_ErrCode](capi-crypto-common-h#oh_crypto_errcode): <br>         CRYPTO_SUCCESS = 0 : 操作成功。<br>         CRYPTO_INVALID_PARAMS = 401 : 参数无效。<br>         CRYPTO_NOT_SUPPORTED = 801 : 操作不支持。<br>         CRYPTO_MEMORY_ERROR = 17620001 : 内存错误。<br>         CRYPTO_OPERTION_ERROR = 17630001 : 调用三方算法库API出错。 |

### OH_CryptoEcPoint_GetCoordinate()

```
OH_Crypto_ErrCode OH_CryptoEcPoint_GetCoordinate(OH_CryptoEcPoint *point, Crypto_DataBlob *x, Crypto_DataBlob *y)
```

**描述**

获取EC点的x和y坐标。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoEcPoint](capi-oh-cryptoecpoint.md) *point | point EC点。 |
| [Crypto_DataBlob](capi-crypto-common-hcrypto_datablob.md) *x | x EC点的x坐标,可以为NULL。 |
| [OH_CryptoEcPoint](capi-oh-cryptoecpoint.md) *point | y EC点的y坐标,可以为NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h#oh_crypto_errcode) | [OH_Crypto_ErrCode](capi-crypto-common-h#oh_crypto_errcode): <br>         CRYPTO_SUCCESS = 0 : 操作成功。<br>         CRYPTO_INVALID_PARAMS = 401 : 参数无效。<br>         CRYPTO_NOT_SUPPORTED = 801 : 操作不支持。<br>         CRYPTO_MEMORY_ERROR = 17620001 : 内存错误。<br>         CRYPTO_OPERTION_ERROR = 17630001 : 调用三方算法库API出错。 |

### OH_CryptoEcPoint_SetCoordinate()

```
OH_Crypto_ErrCode OH_CryptoEcPoint_SetCoordinate(OH_CryptoEcPoint *point, Crypto_DataBlob *x, Crypto_DataBlob *y)
```

**描述**

设置EC点的x和y坐标。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoEcPoint](capi-oh-cryptoecpoint.md) *point | point EC点。 |
| [Crypto_DataBlob](capi-crypto-common-hcrypto_datablob.md) *x | x EC点的x坐标。 |
| [OH_CryptoEcPoint](capi-oh-cryptoecpoint.md) *point | y EC点的y坐标。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h#oh_crypto_errcode) | [OH_Crypto_ErrCode](capi-crypto-common-h#oh_crypto_errcode): <br>         CRYPTO_SUCCESS = 0 : 操作成功。<br>         CRYPTO_INVALID_PARAMS = 401 : 参数无效。<br>         CRYPTO_NOT_SUPPORTED = 801 : 操作不支持。<br>         CRYPTO_MEMORY_ERROR = 17620001 : 内存错误。<br>         CRYPTO_OPERTION_ERROR = 17630001 : 调用三方算法库API出错。 |

### OH_CryptoEcPoint_Encode()

```
OH_Crypto_ErrCode OH_CryptoEcPoint_Encode(OH_CryptoEcPoint *point, const char *format, Crypto_DataBlob *out)
```

**描述**

将EC点编码为指定格式。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoEcPoint](capi-oh-cryptoecpoint.md) *point | point EC点。 |
| const char *format | format 编码格式,支持"UNCOMPRESSED"和"COMPRESSED"。 |
| [Crypto_DataBlob](capi-crypto-common-hcrypto_datablob.md) *out | out 编码后的EC点数据。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h#oh_crypto_errcode) | [OH_Crypto_ErrCode](capi-crypto-common-h#oh_crypto_errcode): <br>         CRYPTO_SUCCESS = 0 : 操作成功。<br>         CRYPTO_INVALID_PARAMS = 401 : 参数无效。<br>         CRYPTO_NOT_SUPPORTED = 801 : 操作不支持。<br>         CRYPTO_MEMORY_ERROR = 17620001 : 内存错误。<br>         CRYPTO_OPERTION_ERROR = 17630001 : 调用三方算法库API出错。 |

### OH_CryptoEcPoint_Destroy()

```
void OH_CryptoEcPoint_Destroy(OH_CryptoEcPoint *point)
```

**描述**

销毁EC点。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoEcPoint](capi-oh-cryptoecpoint.md) *point | point EC点。 |


