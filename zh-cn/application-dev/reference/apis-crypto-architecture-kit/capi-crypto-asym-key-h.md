# crypto_asym_key.h

<!--Kit: Crypto Architecture Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--Designer: @lanming-->
<!--Tester: @PAFT-->
<!--Adviser: @zengyawen-->

## 概述

定义非对称密钥接口。

**引用文件：** <CryptoArchitectureKit/crypto_asym_key.h>

**库：** libohcrypto.so

**系统能力：** SystemCapability.Security.CryptoFramework

**起始版本：** 12

**相关模块：** [CryptoAsymKeyApi](capi-cryptoasymkeyapi.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_CryptoKeyPair](capi-cryptoasymkeyapi-oh-cryptokeypair.md) | OH_CryptoKeyPair | 密钥对结构体，表示密钥对。 |
| [OH_CryptoPubKey](capi-cryptoasymkeyapi-oh-cryptopubkey.md) | OH_CryptoPubKey | 公钥结构体，表示公钥。 |
| [OH_CryptoPrivKey](capi-cryptoasymkeyapi-oh-cryptoprivkey.md) | OH_CryptoPrivKey | 私钥结构体，表示私钥。 |
| [OH_CryptoAsymKeyGenerator](capi-cryptoasymkeyapi-oh-cryptoasymkeygenerator.md) | OH_CryptoAsymKeyGenerator | 非对称密钥生成器结构体，表示非对称密钥生成器。 |
| [OH_CryptoPrivKeyEncodingParams](capi-cryptoasymkeyapi-oh-cryptoprivkeyencodingparams.md) | OH_CryptoPrivKeyEncodingParams | 私钥编码参数结构体，表示私钥编码参数。 |
| [OH_CryptoAsymKeySpec](capi-cryptoasymkeyapi-oh-cryptoasymkeyspec.md) | OH_CryptoAsymKeySpec | 非对称密钥规格结构体，表示非对称密钥规格。 |
| [OH_CryptoAsymKeyGeneratorWithSpec](capi-cryptoasymkeyapi-oh-cryptoasymkeygeneratorwithspec.md) | OH_CryptoAsymKeyGeneratorWithSpec | 基于规格的非对称密钥生成器结构体，表示基于规格的非对称密钥生成器。 |
| [OH_CryptoEcPoint](capi-cryptoasymkeyapi-oh-cryptoecpoint.md) | OH_CryptoEcPoint | 椭圆曲线点结构体，表示椭圆曲线上的点。 |

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
| [OH_Crypto_ErrCode OH_CryptoAsymKeyGenerator_Create(const char *algoName, OH_CryptoAsymKeyGenerator **ctx)](#oh_cryptoasymkeygenerator_create) | 根据给定的算法名称创建非对称密钥生成器。<br> 注意：创建的资源必须通过[OH_CryptoAsymKeyGenerator_Destroy](capi-crypto-asym-key-h.md#oh_cryptoasymkeygenerator_destroy)销毁。  |
| [OH_Crypto_ErrCode OH_CryptoAsymKeyGenerator_Generate(OH_CryptoAsymKeyGenerator *ctx, OH_CryptoKeyPair **keyCtx)](#oh_cryptoasymkeygenerator_generate) | 生成非对称密钥对。注意：使用完成后必须通过[OH_CryptoKeyPair_Destroy](capi-crypto-asym-key-h.md#oh_cryptokeypair_destroy)销毁keyCtx内存。 |
| [OH_Crypto_ErrCode OH_CryptoAsymKeyGenerator_Convert(OH_CryptoAsymKeyGenerator *ctx, Crypto_EncodingType type, Crypto_DataBlob *pubKeyData, Crypto_DataBlob *priKeyData, OH_CryptoKeyPair **keyCtx)](#oh_cryptoasymkeygenerator_convert) | 将非对称密钥数据转换为密钥对。<br>注意：使用完成后必须通过[OH_CryptoKeyPair_Destroy](capi-crypto-asym-key-h.md#oh_cryptokeypair_destroy)销毁keyCtx内存。 |
| [const char *OH_CryptoAsymKeyGenerator_GetAlgoName(OH_CryptoAsymKeyGenerator *ctx)](#oh_cryptoasymkeygenerator_getalgoname) | 获取非对称密钥生成器的算法名称。 |
| [void OH_CryptoAsymKeyGenerator_Destroy(OH_CryptoAsymKeyGenerator *ctx)](#oh_cryptoasymkeygenerator_destroy) | 销毁非对称密钥生成器。 |
| [void OH_CryptoKeyPair_Destroy(OH_CryptoKeyPair *keyCtx)](#oh_cryptokeypair_destroy) | 销毁密钥对。 |
| [OH_CryptoPubKey *OH_CryptoKeyPair_GetPubKey(OH_CryptoKeyPair *keyCtx)](#oh_cryptokeypair_getpubkey) | 获取密钥对中的公钥。 |
| [OH_CryptoPrivKey *OH_CryptoKeyPair_GetPrivKey(OH_CryptoKeyPair *keyCtx)](#oh_cryptokeypair_getprivkey) | 获取密钥对中的私钥。 |
| [OH_Crypto_ErrCode OH_CryptoPubKey_Encode(OH_CryptoPubKey *key, Crypto_EncodingType type, const char *encodingStandard, Crypto_DataBlob *out)](#oh_cryptopubkey_encode) | 对公钥进行编码。<br>注意：使用完成后必须通过[OH_Crypto_FreeDataBlob](capi-crypto-common-h.md#oh_crypto_freedatablob)释放out内存。 |
| [OH_Crypto_ErrCode OH_CryptoPubKey_GetParam(OH_CryptoPubKey *key, CryptoAsymKey_ParamType item, Crypto_DataBlob *value)](#oh_cryptopubkey_getparam) | 获取公钥的指定参数。<br>注意：使用完成后必须通过[OH_Crypto_FreeDataBlob](capi-crypto-common-h.md#oh_crypto_freedatablob)释放value内存。 |
| [OH_Crypto_ErrCode OH_CryptoAsymKeyGenerator_SetPassword(OH_CryptoAsymKeyGenerator *ctx, const unsigned char *password, uint32_t passwordLen)](#oh_cryptoasymkeygenerator_setpassword) | 设置非对称密钥生成器的密码。如果需要使用[OH_CryptoAsymKeyGenerator_Convert](capi-crypto-asym-key-h.md#oh_cryptoasymkeygenerator_convert)将加密的私钥数据转换为密钥对，请调用此方法设置密码。 |
| [OH_Crypto_ErrCode OH_CryptoPrivKeyEncodingParams_Create(OH_CryptoPrivKeyEncodingParams **ctx)](#oh_cryptoprivkeyencodingparams_create) | 创建私钥编码参数。<br> 注意：创建的资源必须通过[OH_CryptoPrivKeyEncodingParams_Destroy](capi-crypto-asym-key-h.md#oh_cryptoprivkeyencodingparams_destroy)销毁。 |
| [OH_Crypto_ErrCode OH_CryptoPrivKeyEncodingParams_SetParam(OH_CryptoPrivKeyEncodingParams *ctx, CryptoPrivKeyEncoding_ParamType type, Crypto_DataBlob *value)](#oh_cryptoprivkeyencodingparams_setparam) | 设置私钥编码参数。 |
| [void OH_CryptoPrivKeyEncodingParams_Destroy(OH_CryptoPrivKeyEncodingParams *ctx)](#oh_cryptoprivkeyencodingparams_destroy) | 销毁私钥编码参数。 |
| [OH_Crypto_ErrCode OH_CryptoPrivKey_Encode(OH_CryptoPrivKey *key, Crypto_EncodingType type, const char *encodingStandard, OH_CryptoPrivKeyEncodingParams *params, Crypto_DataBlob *out)](#oh_cryptoprivkey_encode) | 对私钥进行编码。<br> 注意：使用完成后必须通过[OH_Crypto_FreeDataBlob](capi-crypto-common-h.md#oh_crypto_freedatablob)释放out内存。  |
| [OH_Crypto_ErrCode OH_CryptoPrivKey_GetParam(OH_CryptoPrivKey *key, CryptoAsymKey_ParamType item, Crypto_DataBlob *value)](#oh_cryptoprivkey_getparam) | 获取私钥的指定参数。<br> 注意：使用完成后必须通过[OH_Crypto_FreeDataBlob](capi-crypto-common-h.md#oh_crypto_freedatablob)释放out内存。 |
| [OH_Crypto_ErrCode OH_CryptoAsymKeySpec_GenEcCommonParamsSpec(const char *curveName, OH_CryptoAsymKeySpec **spec)](#oh_cryptoasymkeyspec_geneccommonparamsspec) | 生成EC通用参数规格。<br> 注意：使用完成后必须通过[OH_CryptoAsymKeySpec_Destroy](capi-crypto-asym-key-h.md#oh_cryptoasymkeyspec_destroy)销毁spec内存。  |
| [OH_Crypto_ErrCode OH_CryptoAsymKeySpec_GenDhCommonParamsSpec(int pLen, int skLen, OH_CryptoAsymKeySpec **spec)](#oh_cryptoasymkeyspec_gendhcommonparamsspec) | 生成DH通用参数规格。<br> 注意：使用完成后必须通过[OH_CryptoAsymKeySpec_Destroy](capi-crypto-asym-key-h.md#oh_cryptoasymkeyspec_destroy)销毁spec内存。  |
| [OH_Crypto_ErrCode OH_CryptoAsymKeySpec_Create(const char *algoName, CryptoAsymKeySpec_Type type, OH_CryptoAsymKeySpec **spec)](#oh_cryptoasymkeyspec_create) | 根据给定的算法名称和规格类型创建非对称密钥规格。<br> 注意：创建的资源必须通过[OH_CryptoAsymKeySpec_Destroy](capi-crypto-asym-key-h.md#oh_cryptoasymkeyspec_destroy)销毁。 |
| [OH_Crypto_ErrCode OH_CryptoAsymKeySpec_SetParam(OH_CryptoAsymKeySpec *spec, CryptoAsymKey_ParamType type, Crypto_DataBlob *value)](#oh_cryptoasymkeyspec_setparam) | 设置非对称密钥规格的指定参数。 |
| [OH_Crypto_ErrCode OH_CryptoAsymKeySpec_SetCommonParamsSpec(OH_CryptoAsymKeySpec *spec, OH_CryptoAsymKeySpec *commonParamsSpec)](#oh_cryptoasymkeyspec_setcommonparamsspec) | 将通用参数规格设置到非对称密钥规格中。 |
| [OH_Crypto_ErrCode OH_CryptoAsymKeySpec_GetParam(OH_CryptoAsymKeySpec *spec, CryptoAsymKey_ParamType type, Crypto_DataBlob *value)](#oh_cryptoasymkeyspec_getparam) | 获取非对称密钥规格的指定参数。<br> 注意：使用完成后必须通过[OH_Crypto_FreeDataBlob](capi-crypto-common-h.md#oh_crypto_freedatablob)释放value内存。  |
| [void OH_CryptoAsymKeySpec_Destroy(OH_CryptoAsymKeySpec *spec)](#oh_cryptoasymkeyspec_destroy) | 销毁非对称密钥规格。 |
| [OH_Crypto_ErrCode OH_CryptoAsymKeyGeneratorWithSpec_Create(OH_CryptoAsymKeySpec *keySpec, OH_CryptoAsymKeyGeneratorWithSpec **generator)](#oh_cryptoasymkeygeneratorwithspec_create) | 根据非对称密钥规格创建密钥生成器。<br> 注意：创建的资源必须通过[OH_CryptoAsymKeyGeneratorWithSpec_Destroy](capi-crypto-asym-key-h.md#oh_cryptoasymkeygeneratorwithspec_destroy)销毁。  |
| [OH_Crypto_ErrCode OH_CryptoAsymKeyGeneratorWithSpec_GenKeyPair(OH_CryptoAsymKeyGeneratorWithSpec *generator, OH_CryptoKeyPair **keyPair)](#oh_cryptoasymkeygeneratorwithspec_genkeypair) | 根据非对称密钥规格生成密钥对。<br> 注意：使用完成后必须通过[OH_CryptoKeyPair_Destroy](capi-crypto-asym-key-h.md#oh_cryptokeypair_destroy)释放keyPair内存。  |
| [void OH_CryptoAsymKeyGeneratorWithSpec_Destroy(OH_CryptoAsymKeyGeneratorWithSpec *generator)](#oh_cryptoasymkeygeneratorwithspec_destroy) | 销毁根据规格创建的非对称密钥生成器。 |
| [OH_Crypto_ErrCode OH_CryptoEcPoint_Create(const char *curveName, Crypto_DataBlob *ecKeyData, OH_CryptoEcPoint **point)](#oh_cryptoecpoint_create) | 创建椭圆曲线点。<br> 注意：创建的资源必须通过[OH_CryptoEcPoint_Destroy](capi-crypto-asym-key-h.md#oh_cryptoecpoint_destroy)销毁。 |
| [OH_Crypto_ErrCode OH_CryptoEcPoint_GetCoordinate(OH_CryptoEcPoint *point, Crypto_DataBlob *x, Crypto_DataBlob *y)](#oh_cryptoecpoint_getcoordinate) | 获取椭圆曲线点的x和y坐标。<br> 注意：使用完成后必须通过[OH_Crypto_FreeDataBlob](capi-crypto-common-h.md#oh_crypto_freedatablob)释放x和y内存。 |
| [OH_Crypto_ErrCode OH_CryptoEcPoint_SetCoordinate(OH_CryptoEcPoint *point, Crypto_DataBlob *x, Crypto_DataBlob *y)](#oh_cryptoecpoint_setcoordinate) | 设置椭圆曲线点的x和y坐标。 |
| [OH_Crypto_ErrCode OH_CryptoEcPoint_Encode(OH_CryptoEcPoint *point, const char *format, Crypto_DataBlob *out)](#oh_cryptoecpoint_encode) | 将椭圆曲线点编码为指定格式。<br> 注意：使用完成后必须通过[OH_Crypto_FreeDataBlob](capi-crypto-common-h.md#oh_crypto_freedatablob)释放out内存。  |
| [void OH_CryptoEcPoint_Destroy(OH_CryptoEcPoint *point)](#oh_cryptoecpoint_destroy) | 销毁椭圆曲线点。 |

## 枚举类型说明

### CryptoAsymKey_ParamType

```c
enum CryptoAsymKey_ParamType
```

**描述**

定义非对称密钥参数类型。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| CRYPTO_DSA_P_DATABLOB = 101 | 表示DSA算法的素数p。 |
| CRYPTO_DSA_Q_DATABLOB = 102 | 表示DSA算法的子素数q。 |
| CRYPTO_DSA_G_DATABLOB = 103 | 表示DSA算法的基g。 |
| CRYPTO_DSA_SK_DATABLOB = 104 | 表示DSA算法的私钥。 |
| CRYPTO_DSA_PK_DATABLOB = 105 | 表示DSA算法的公钥。 |
| CRYPTO_ECC_FP_P_DATABLOB = 201 | 表示椭圆曲线(EC)素数域的素数p。 |
| CRYPTO_ECC_A_DATABLOB = 202 | 表示椭圆曲线的第一个系数a。 |
| CRYPTO_ECC_B_DATABLOB = 203 | 表示椭圆曲线的第二个系数b。 |
| CRYPTO_ECC_G_X_DATABLOB = 204 | 表示基点g的仿射x坐标。 |
| CRYPTO_ECC_G_Y_DATABLOB = 205 | 表示基点g的仿射y坐标。 |
| CRYPTO_ECC_N_DATABLOB = 206 | 表示基点g的阶。 |
| CRYPTO_ECC_H_INT = 207 | 表示椭圆曲线的余因子。 |
| CRYPTO_ECC_SK_DATABLOB = 208 | 表示ECC私钥的私钥值。 |
| CRYPTO_ECC_PK_X_DATABLOB = 209 | 表示ECC公钥中公钥点的仿射x坐标。 |
| CRYPTO_ECC_PK_Y_DATABLOB = 210 | 表示ECC公钥中公钥点的仿射y坐标。 |
| CRYPTO_ECC_FIELD_TYPE_STR = 211 | 表示椭圆曲线有限域类型。 |
| CRYPTO_ECC_FIELD_SIZE_INT = 212 | 表示有限域的比特长度。 |
| CRYPTO_ECC_CURVE_NAME_STR = 213 | 表示SECG标准的曲线名称。 |
| CRYPTO_RSA_N_DATABLOB = 301 | 表示RSA算法的模数n。 |
| CRYPTO_RSA_D_DATABLOB = 302 | 表示RSA算法的私钥指数d。 |
| CRYPTO_RSA_E_DATABLOB = 303 | 表示RSA算法的公钥指数e。 |
| CRYPTO_DH_P_DATABLOB = 401 | 表示DH算法的素数p。 |
| CRYPTO_DH_G_DATABLOB = 402 | 表示DH算法的生成元g。 |
| CRYPTO_DH_L_INT = 403 | 表示DH算法中私钥长度的比特数。 |
| CRYPTO_DH_SK_DATABLOB = 404 | 表示DH私钥的私钥值。 |
| CRYPTO_DH_PK_DATABLOB = 405 | 表示DH公钥的公钥值。 |
| CRYPTO_ED25519_SK_DATABLOB = 501 | 表示ED25519私钥的私钥值。 |
| CRYPTO_ED25519_PK_DATABLOB = 502 | 表示ED25519公钥的公钥值。 |
| CRYPTO_X25519_SK_DATABLOB = 601 | 表示X25519私钥的私钥值。 |
| CRYPTO_X25519_PK_DATABLOB = 602 | 表示X25519公钥的公钥值。 |

### Crypto_EncodingType

```c
enum Crypto_EncodingType
```

**描述**

定义编码类型。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| CRYPTO_PEM = 0 | PEM格式。 |
| CRYPTO_DER = 1 | DER格式。 |

### CryptoPrivKeyEncoding_ParamType

```c
enum CryptoPrivKeyEncoding_ParamType
```

**描述**

定义私钥编码参数类型。

**起始版本：** 20

| 枚举项 | 描述 |
| -- | -- |
| CRYPTO_PRIVATE_KEY_ENCODING_PASSWORD_STR = 0 | 表示密码字符串。 |
| CRYPTO_PRIVATE_KEY_ENCODING_SYMMETRIC_CIPHER_STR = 1 | 对称加密算法名称，通过[OH_CryptoPrivKeyEncodingParams_SetParam](capi-crypto-asym-key-h.md#oh_cryptoprivkeyencodingparams_setparam)设置。取值："DES-EDE3-CBC"、"AES-128-CBC"、"AES-192-CBC"、"AES-256-CBC"。 |

### CryptoAsymKeySpec_Type

```c
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

```c
OH_Crypto_ErrCode OH_CryptoAsymKeyGenerator_Create(const char *algoName, OH_CryptoAsymKeyGenerator **ctx)
```

**描述**

根据给定的算法名称创建非对称密钥生成器。

注意：创建的资源必须通过[OH_CryptoAsymKeyGenerator_Destroy](capi-crypto-asym-key-h.md#oh_cryptoasymkeygenerator_destroy)销毁。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char *algoName | [in] 非对称密钥算法名称，不能为NULL。取值如下：<br>- 从API version 12开始支持RSA系列："RSA512"、"RSA768"、"RSA1024"、"RSA2048"、"RSA3072"、"RSA4096"、"RSA8192"。支持多素数格式，示例："RSA1024\|PRIMES_3"、"RSA4096\|PRIMES_4"、"RSA8192\|PRIMES_5"。<br>- 从API version 12开始支持ECC系列："ECC224"、"ECC256"、"ECC384"、"ECC521"。<br>- 从API version 12开始支持ECC BrainPool系列："ECC_BrainPoolP160r1"、"ECC_BrainPoolP160t1"、"ECC_BrainPoolP192r1"、"ECC_BrainPoolP192t1"、"ECC_BrainPoolP224r1"、"ECC_BrainPoolP224t1"、"ECC_BrainPoolP256r1"、"ECC_BrainPoolP256t1"、"ECC_BrainPoolP320r1"、"ECC_BrainPoolP320t1"、"ECC_BrainPoolP384r1"、"ECC_BrainPoolP384t1"、"ECC_BrainPoolP512r1"、"ECC_BrainPoolP512t1"。<br>- 从API version 12开始支持"SM2_256"、"Ed25519"、"X25519"。<br>- 从API version 12开始支持DSA系列："DSA1024"、"DSA2048"、"DSA3072"。<br>- 从API version 12开始支持DH系列："DH_modp1536"、"DH_modp2048"、"DH_modp3072"、"DH_modp4096"、"DH_modp6144"、"DH_modp8192"、"DH_ffdhe2048"、"DH_ffdhe3072"、"DH_ffdhe4096"、"DH_ffdhe6144"、"DH_ffdhe8192"。<br>- 从API version 14开始支持"ECC_Secp256k1"。<br>- 从API版本26.0.0开始支持"ECC192"。 |
| [OH_CryptoAsymKeyGenerator](capi-cryptoasymkeyapi-oh-cryptoasymkeygenerator.md) **ctx | [out] 指向非对称密钥生成器指针的指针。ctx不能为NULL，*ctx必须为NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | CRYPTO_SUCCESS：操作成功。<br>CRYPTO_INVALID_PARAMS：ctx为NULL或algoName为NULL。<br>CRYPTO_NOT_SUPPORTED：不支持的算法。<br>CRYPTO_MEMORY_ERROR：内存分配失败。<br>CRYPTO_OPERTION_ERROR：密码操作失败。 |

**参考：**

[OH_CryptoAsymKeyGenerator_Generate](capi-crypto-asym-key-h.md#oh_cryptoasymkeygenerator_generate) 生成非对称密钥对。

[OH_CryptoAsymKeyGenerator_Convert](capi-crypto-asym-key-h.md#oh_cryptoasymkeygenerator_convert) 将非对称密钥数据转换为密钥对。


### OH_CryptoAsymKeyGenerator_Generate()

```c
OH_Crypto_ErrCode OH_CryptoAsymKeyGenerator_Generate(OH_CryptoAsymKeyGenerator *ctx, OH_CryptoKeyPair **keyCtx)
```

**描述**

生成非对称密钥对。

注意：使用完成后必须通过[OH_CryptoKeyPair_Destroy](capi-crypto-asym-key-h.md#oh_cryptokeypair_destroy)销毁keyCtx内存。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoAsymKeyGenerator](capi-cryptoasymkeyapi-oh-cryptoasymkeygenerator.md) *ctx | [in] 非对称密钥生成器。不能为NULL。 |
| [OH_CryptoKeyPair](capi-cryptoasymkeyapi-oh-cryptokeypair.md) **keyCtx | [out] 指向密钥对指针的指针。keyCtx不能为NULL，*keyCtx必须为NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | CRYPTO_SUCCESS：操作成功。<br>CRYPTO_INVALID_PARAMS：ctx或keyCtx为NULL。<br>CRYPTO_NOT_SUPPORTED：不支持的操作或算法。<br>CRYPTO_MEMORY_ERROR：内存操作失败。<br>CRYPTO_OPERTION_ERROR：密码操作失败。 |

### OH_CryptoAsymKeyGenerator_Convert()

```c
OH_Crypto_ErrCode OH_CryptoAsymKeyGenerator_Convert(OH_CryptoAsymKeyGenerator *ctx, Crypto_EncodingType type, Crypto_DataBlob *pubKeyData, Crypto_DataBlob *priKeyData, OH_CryptoKeyPair **keyCtx)
```

**描述**

将非对称密钥数据转换为密钥对。

注意：使用完成后必须通过[OH_CryptoKeyPair_Destroy](capi-crypto-asym-key-h.md#oh_cryptokeypair_destroy)销毁keyCtx内存。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoAsymKeyGenerator](capi-cryptoasymkeyapi-oh-cryptoasymkeygenerator.md) *ctx | [in] 非对称密钥生成器。不能为NULL。 |
| [Crypto_EncodingType](capi-crypto-asym-key-h.md#crypto_encodingtype) type | [in] 编码类型。 |
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *pubKeyData | [in] 公钥数据，不能与priKeyData同时为NULL。 |
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *priKeyData | [in] 私钥数据，不能与pubKeyData同时为NULL。 |
| [OH_CryptoKeyPair](capi-cryptoasymkeyapi-oh-cryptokeypair.md) **keyCtx | [out] 指向密钥对指针的指针。keyCtx不能为NULL，*keyCtx必须为NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | CRYPTO_SUCCESS：操作成功。<br>CRYPTO_INVALID_PARAMS：ctx为NULL，pubKeyData和priKeyData同时为NULL，keyCtx为NULL或type不是有效的Crypto_EncodingType。<br>CRYPTO_NOT_SUPPORTED：不支持的密钥格式。<br>CRYPTO_MEMORY_ERROR：内存分配失败。<br>CRYPTO_OPERTION_ERROR：密钥转换失败。可能的原因：<br>密钥数据损坏或不是有效的PEM/DER格式，密钥数据与算法不匹配，或加密私钥的密码不正确。 |

### OH_CryptoAsymKeyGenerator_GetAlgoName()

```c
const char *OH_CryptoAsymKeyGenerator_GetAlgoName(OH_CryptoAsymKeyGenerator *ctx)
```

**描述**

获取非对称密钥生成器的算法名称。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoAsymKeyGenerator](capi-cryptoasymkeyapi-oh-cryptoasymkeygenerator.md) *ctx | [in] 非对称密钥生成器。不能为NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| const char * | 返回非对称密钥算法名称，不需要调用者释放，在生成器销毁后不可使用。<br>返回NULL，如果ctx是NULL。 |

### OH_CryptoAsymKeyGenerator_Destroy()

```c
void OH_CryptoAsymKeyGenerator_Destroy(OH_CryptoAsymKeyGenerator *ctx)
```

**描述**

销毁非对称密钥生成器。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoAsymKeyGenerator](capi-cryptoasymkeyapi-oh-cryptoasymkeygenerator.md) *ctx | [in] 非对称密钥生成器。 |

### OH_CryptoKeyPair_Destroy()

```c
void OH_CryptoKeyPair_Destroy(OH_CryptoKeyPair *keyCtx)
```

**描述**

销毁密钥对。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoKeyPair](capi-cryptoasymkeyapi-oh-cryptokeypair.md) *keyCtx | [in] 密钥对。 |

### OH_CryptoKeyPair_GetPubKey()

```c
OH_CryptoPubKey *OH_CryptoKeyPair_GetPubKey(OH_CryptoKeyPair *keyCtx)
```

**描述**

获取密钥对中的公钥。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoKeyPair](capi-cryptoasymkeyapi-oh-cryptokeypair.md) *keyCtx | [in] 密钥对。不能为NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_CryptoPubKey *](capi-cryptoasymkeyapi-oh-cryptopubkey.md) | 返回密钥对中的公钥。为内部引用，不需要单独销毁，在密钥对销毁后不可使用。<br>返回NULL，如果keyCtx为NULL或公钥不存在。 |

### OH_CryptoKeyPair_GetPrivKey()

```c
OH_CryptoPrivKey *OH_CryptoKeyPair_GetPrivKey(OH_CryptoKeyPair *keyCtx)
```

**描述**

获取密钥对中的私钥。

**起始版本：** 20

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoKeyPair](capi-cryptoasymkeyapi-oh-cryptokeypair.md) *keyCtx | [in] 密钥对。不能为NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_CryptoPrivKey *](capi-cryptoasymkeyapi-oh-cryptoprivkey.md) | 返回密钥对中的私钥。为内部引用，不需要单独销毁，在密钥对销毁后不可使用。<br>返回NULL，如果keyCtx为NULL或私钥不存在。 |

### OH_CryptoPubKey_Encode()

```c
OH_Crypto_ErrCode OH_CryptoPubKey_Encode(OH_CryptoPubKey *key, Crypto_EncodingType type, const char *encodingStandard, Crypto_DataBlob *out)
```

**描述**

对公钥进行编码。

注意：使用完成后必须通过[OH_Crypto_FreeDataBlob](capi-crypto-common-h.md#oh_crypto_freedatablob)释放out内存。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoPubKey](capi-cryptoasymkeyapi-oh-cryptopubkey.md) *key | [in] 公钥。不能为NULL。 |
| [Crypto_EncodingType](capi-crypto-asym-key-h.md#crypto_encodingtype) type | [in] 编码类型。 |
| const char *encodingStandard | [in] 编码标准，支持"X509"。不能为NULL。 |
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *out | [out] 指向用于存储编码结果的Crypto_DataBlob结构体的指针。不能为NULL。调用前需将out初始化为{0}，不要预分配out->data内存。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | CRYPTO_SUCCESS：操作成功。<br>CRYPTO_INVALID_PARAMS：key、out或encodingStandard为NULL，type不是   有效的Crypto_EncodingType，或编码标准与密钥类型不兼容。<br>CRYPTO_NOT_SUPPORTED：不支持的编码格式。<br>CRYPTO_MEMORY_ERROR：内存分配失败。<br>CRYPTO_OPERTION_ERROR：编码失败。 |

### OH_CryptoPubKey_GetParam()

```c
OH_Crypto_ErrCode OH_CryptoPubKey_GetParam(OH_CryptoPubKey *key, CryptoAsymKey_ParamType item, Crypto_DataBlob *value)
```

**描述**

获取公钥的指定参数。

注意：使用完成后必须通过[OH_Crypto_FreeDataBlob](capi-crypto-common-h.md#oh_crypto_freedatablob)释放value内存。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoPubKey](capi-cryptoasymkeyapi-oh-cryptopubkey.md) *key | [in] 公钥。不能为NULL。 |
| [CryptoAsymKey_ParamType](capi-crypto-asym-key-h.md#cryptoasymkey_paramtype) item | [in] 非对称密钥参数类型。 |
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *value | [out] 指向用于存储输出数据的Crypto_DataBlob结构体的指针。不能为NULL。调用前需将value初始化为{0}，不要预分配value->data内存。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | CRYPTO_SUCCESS：操作成功。<br>CRYPTO_INVALID_PARAMS：key或value为NULL，或该参数类型不支持该密钥算法。<br>CRYPTO_NOT_SUPPORTED：不支持的参数类型。<br>CRYPTO_MEMORY_ERROR：内存分配失败。<br>CRYPTO_OPERTION_ERROR：获取参数失败。 |

### OH_CryptoAsymKeyGenerator_SetPassword()

```c
OH_Crypto_ErrCode OH_CryptoAsymKeyGenerator_SetPassword(OH_CryptoAsymKeyGenerator *ctx, const unsigned char *password, uint32_t passwordLen)
```

**描述**

设置非对称密钥生成器的密码。如果需要使用[OH_CryptoAsymKeyGenerator_Convert](capi-crypto-asym-key-h.md#oh_cryptoasymkeygenerator_convert)将加密的私钥数据转换为密钥对，请调用此方法设置密码。

**起始版本：** 20

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoAsymKeyGenerator](capi-cryptoasymkeyapi-oh-cryptoasymkeygenerator.md) *ctx | [in] 非对称密钥生成器。不能为NULL。 |
| const unsigned char *password | [in] 密码。本接口会对password中的数据进行深拷贝，调用者在接口返回后可立即释放password。不能为NULL。 |
| uint32_t passwordLen | [in] 密码的字节长度。必须大于0。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | CRYPTO_SUCCESS：操作成功。<br>CRYPTO_NOT_SUPPORTED：不支持的操作或算法。<br>CRYPTO_MEMORY_ERROR：内存分配失败。<br>CRYPTO_PARAMETER_CHECK_FAILED：ctx或password为NULL，或passwordLen为0。<br>CRYPTO_OPERTION_ERROR：密码操作失败。 |

### OH_CryptoPrivKeyEncodingParams_Create()

```c
OH_Crypto_ErrCode OH_CryptoPrivKeyEncodingParams_Create(OH_CryptoPrivKeyEncodingParams **ctx)
```

**描述**

创建私钥编码参数。

注意：创建的资源必须通过[OH_CryptoPrivKeyEncodingParams_Destroy](capi-crypto-asym-key-h.md#oh_cryptoprivkeyencodingparams_destroy)销毁。

**起始版本：** 20

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoPrivKeyEncodingParams](capi-cryptoasymkeyapi-oh-cryptoprivkeyencodingparams.md) **ctx | [out] 指向私钥编码参数指针的指针。ctx不能为NULL，*ctx必须为NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | CRYPTO_SUCCESS：操作成功。<br>CRYPTO_PARAMETER_CHECK_FAILED：ctx为NULL。<br>CRYPTO_NOT_SUPPORTED：不支持的操作或算法。<br>CRYPTO_MEMORY_ERROR：内存分配失败。<br>CRYPTO_OPERTION_ERROR：密码操作失败。 |

**参考：**

[OH_CryptoPrivKeyEncodingParams_SetParam](capi-crypto-asym-key-h.md#oh_cryptoprivkeyencodingparams_setparam) 设置私钥编码参数。


### OH_CryptoPrivKeyEncodingParams_SetParam()

```c
OH_Crypto_ErrCode OH_CryptoPrivKeyEncodingParams_SetParam(OH_CryptoPrivKeyEncodingParams *ctx, CryptoPrivKeyEncoding_ParamType type, Crypto_DataBlob *value)
```

**描述**

设置私钥编码参数。

**起始版本：** 20

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoPrivKeyEncodingParams](capi-cryptoasymkeyapi-oh-cryptoprivkeyencodingparams.md) *ctx | [in] 私钥编码参数。不能为NULL。 |
| [CryptoPrivKeyEncoding_ParamType](capi-crypto-asym-key-h.md#cryptoprivkeyencoding_paramtype) type | [in] 私钥编码参数类型。 |
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *value | [in] 私钥编码参数值。本接口会对value中的数据进行深拷贝，调用者在接口返回后可立即释放value。不能为NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | CRYPTO_SUCCESS：操作成功。<br>CRYPTO_PARAMETER_CHECK_FAILED：ctx或value为NULL，value->data为NULL，value->len为0，或type无法识别。<br>CRYPTO_NOT_SUPPORTED：不支持的操作或算法。<br>CRYPTO_MEMORY_ERROR：深拷贝内存分配失败。<br>CRYPTO_OPERTION_ERROR：密码操作失败。 |

### OH_CryptoPrivKeyEncodingParams_Destroy()

```c
void OH_CryptoPrivKeyEncodingParams_Destroy(OH_CryptoPrivKeyEncodingParams *ctx)
```

**描述**

销毁私钥编码参数。

**起始版本：** 20

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoPrivKeyEncodingParams](capi-cryptoasymkeyapi-oh-cryptoprivkeyencodingparams.md) *ctx | [in] 私钥编码参数。 |

### OH_CryptoPrivKey_Encode()

```c
OH_Crypto_ErrCode OH_CryptoPrivKey_Encode(OH_CryptoPrivKey *key, Crypto_EncodingType type, const char *encodingStandard, OH_CryptoPrivKeyEncodingParams *params, Crypto_DataBlob *out)
```

**描述**

对私钥进行编码。

注意：使用完成后必须通过[OH_Crypto_FreeDataBlob](capi-crypto-common-h.md#oh_crypto_freedatablob)释放out内存。

**起始版本：** 20

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoPrivKey](capi-cryptoasymkeyapi-oh-cryptoprivkey.md) *key | [in] 私钥。不能为NULL。 |
| [Crypto_EncodingType](capi-crypto-asym-key-h.md#crypto_encodingtype) type | [in] 编码类型。 |
| const char *encodingStandard | [in] 编码标准，支持"PKCS8"和"PKCS1"。其中"PKCS1"仅支持RSA私钥。不能为NULL。 |
| [OH_CryptoPrivKeyEncodingParams](capi-cryptoasymkeyapi-oh-cryptoprivkeyencodingparams.md) *params | [in] 私钥编码参数，可以为NULL，如果需要加密私钥，应设置此参数。 |
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *out | [out] 指向用于存储编码结果的Crypto_DataBlob结构体的指针。不能为NULL。调用前需将out初始化为{0}，不要预分配out->data内存。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | CRYPTO_SUCCESS：操作成功。<br>CRYPTO_PARAMETER_CHECK_FAILED：key、out或encodingStandard为NULL，type不是有效的Crypto_EncodingType，或编码标准与密钥类型不兼容。<br>CRYPTO_NOT_SUPPORTED：不支持的编码格式。<br>CRYPTO_MEMORY_ERROR：内存分配失败。<br>CRYPTO_OPERTION_ERROR：编码失败。 |

### OH_CryptoPrivKey_GetParam()

```c
OH_Crypto_ErrCode OH_CryptoPrivKey_GetParam(OH_CryptoPrivKey *key, CryptoAsymKey_ParamType item, Crypto_DataBlob *value)
```

**描述**

获取私钥的指定参数。

注意：使用完成后必须通过[OH_Crypto_FreeDataBlob](capi-crypto-common-h.md#oh_crypto_freedatablob)释放value内存。

**起始版本：** 20

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoPrivKey](capi-cryptoasymkeyapi-oh-cryptoprivkey.md) *key | [in] 私钥。不能为NULL。 |
| [CryptoAsymKey_ParamType](capi-crypto-asym-key-h.md#cryptoasymkey_paramtype) item | [in] 非对称密钥参数类型。 |
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *value | [out] 指向用于存储输出数据的Crypto_DataBlob结构体的指针。不能为NULL。 调用前需将value初始化为{0}，不要预分配value->data内存。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | CRYPTO_SUCCESS：操作成功。<br>CRYPTO_PARAMETER_CHECK_FAILED：key或value为NULL，或该参数类型不支持该密钥算法。<br>CRYPTO_NOT_SUPPORTED：不支持的参数类型。<br>CRYPTO_MEMORY_ERROR：内存分配失败。<br>CRYPTO_OPERTION_ERROR：获取参数失败。 |

### OH_CryptoAsymKeySpec_GenEcCommonParamsSpec()

```c
OH_Crypto_ErrCode OH_CryptoAsymKeySpec_GenEcCommonParamsSpec(const char *curveName, OH_CryptoAsymKeySpec **spec)
```

**描述**

生成EC通用参数规格。

注意：使用完成后必须通过[OH_CryptoAsymKeySpec_Destroy](capi-crypto-asym-key-h.md#oh_cryptoasymkeyspec_destroy)销毁spec内存。

**起始版本：** 20

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char *curveName | [in] ECC曲线的NID（Name Identifier）字符串名称，不能为NULL。例如"NID_X9_62_prime256v1"、"NID_secp384r1"、"NID_secp521r1"、"NID_sm2"。 |
| [OH_CryptoAsymKeySpec](capi-cryptoasymkeyapi-oh-cryptoasymkeyspec.md) **spec | [out] 指向非对称密钥规格指针的指针。spec不能为NULL，*spec必须为NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | CRYPTO_SUCCESS：操作成功。<br>CRYPTO_PARAMETER_CHECK_FAILED：curveName或spec为NULL，或曲线名不是有效的椭圆曲线。<br>CRYPTO_NOT_SUPPORTED：不支持的曲线。<br>CRYPTO_MEMORY_ERROR：内存分配失败。<br>CRYPTO_OPERTION_ERROR：生成规格失败。 |

### OH_CryptoAsymKeySpec_GenDhCommonParamsSpec()

```c
OH_Crypto_ErrCode OH_CryptoAsymKeySpec_GenDhCommonParamsSpec(int pLen, int skLen, OH_CryptoAsymKeySpec **spec)
```

**描述**

生成DH通用参数规格。

注意：使用完成后必须通过[OH_CryptoAsymKeySpec_Destroy](capi-crypto-asym-key-h.md#oh_cryptoasymkeyspec_destroy)销毁spec内存。

**起始版本：** 20

**参数：**

| 参数项 | 描述 |
| -- | -- |
| int pLen | [in] 素数p的比特长度。 |
| int skLen | [in] 私钥的比特长度。 |
| [OH_CryptoAsymKeySpec](capi-cryptoasymkeyapi-oh-cryptoasymkeyspec.md) **spec | [out] 指向非对称密钥规格指针的指针。spec不能为NULL，*spec必须为NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | CRYPTO_SUCCESS：操作成功。<br>CRYPTO_PARAMETER_CHECK_FAILED：spec为NULL，pLen为负数，skLen为负数，或skLen大于pLen。<br>CRYPTO_NOT_SUPPORTED：不支持的操作或算法。<br>CRYPTO_MEMORY_ERROR：内存分配失败。<br>CRYPTO_OPERTION_ERROR：密码操作失败。 |

### OH_CryptoAsymKeySpec_Create()

```c
OH_Crypto_ErrCode OH_CryptoAsymKeySpec_Create(const char *algoName, CryptoAsymKeySpec_Type type, OH_CryptoAsymKeySpec **spec)
```

**描述**

根据给定的算法名称和规格类型创建非对称密钥规格。

注意：创建的资源必须通过[OH_CryptoAsymKeySpec_Destroy](capi-crypto-asym-key-h.md#oh_cryptoasymkeyspec_destroy)销毁。

**起始版本：** 20

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char *algoName | [in] 非对称密钥规格算法名称，不能为NULL。取值如下：<br>- 从API version 20开始支持"RSA"、"ECC"、"DSA"、"SM2"、"Ed25519"、"X25519"、"DH"。 |
| [CryptoAsymKeySpec_Type](capi-crypto-asym-key-h.md#cryptoasymkeyspec_type) type | [in] 非对称密钥规格类型。 |
| [OH_CryptoAsymKeySpec](capi-cryptoasymkeyapi-oh-cryptoasymkeyspec.md) **spec | [out] 指向非对称密钥规格指针的指针。spec不能为NULL，*spec必须为NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | CRYPTO_SUCCESS：操作成功。<br>CRYPTO_PARAMETER_CHECK_FAILED：algoName或spec为NULL，algoName不是支持的算法名称。<br>CRYPTO_NOT_SUPPORTED：不支持的操作或算法。<br>CRYPTO_MEMORY_ERROR：内存分配失败。<br>CRYPTO_OPERTION_ERROR：密码操作失败。 |

### OH_CryptoAsymKeySpec_SetParam()

```c
OH_Crypto_ErrCode OH_CryptoAsymKeySpec_SetParam(OH_CryptoAsymKeySpec *spec, CryptoAsymKey_ParamType type, Crypto_DataBlob *value)
```

**描述**

设置非对称密钥规格的指定参数。

**起始版本：** 20

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoAsymKeySpec](capi-cryptoasymkeyapi-oh-cryptoasymkeyspec.md) *spec | [in] 非对称密钥规格。不能为NULL。 |
| [CryptoAsymKey_ParamType](capi-crypto-asym-key-h.md#cryptoasymkey_paramtype) type | [in] 非对称密钥参数类型。 |
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *value | [in] 输入数据。本接口会对value中的数据进行深拷贝，调用者在接口返回后可立即释放value。不能为NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | CRYPTO_SUCCESS：操作成功。<br>CRYPTO_PARAMETER_CHECK_FAILED：spec或value为NULL，value->data为NULL，value->len为0，或该参数类型不支持该算法。<br>CRYPTO_NOT_SUPPORTED：不支持的操作或算法。<br>CRYPTO_MEMORY_ERROR：深拷贝内存分配失败。<br>CRYPTO_OPERTION_ERROR：密码操作失败。 |

### OH_CryptoAsymKeySpec_SetCommonParamsSpec()

```c
OH_Crypto_ErrCode OH_CryptoAsymKeySpec_SetCommonParamsSpec(OH_CryptoAsymKeySpec *spec, OH_CryptoAsymKeySpec *commonParamsSpec)
```

**描述**

将通用参数规格设置到非对称密钥规格中。

**起始版本：** 20

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoAsymKeySpec](capi-cryptoasymkeyapi-oh-cryptoasymkeyspec.md) *spec | [in] 非对称密钥规格。不能为NULL。 |
| [OH_CryptoAsymKeySpec](capi-cryptoasymkeyapi-oh-cryptoasymkeyspec.md) *commonParamsSpec | [in] 通用参数规格。本接口会对commonParamsSpec中的数据进行深拷贝，调用者在接口返回后可立即释放commonParamsSpec。不能为NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | CRYPTO_SUCCESS：操作成功。<br>CRYPTO_PARAMETER_CHECK_FAILED：spec或commonParamsSpec为NULL。<br>CRYPTO_NOT_SUPPORTED：不支持的操作或算法。<br>CRYPTO_MEMORY_ERROR：内存分配失败。<br>CRYPTO_OPERTION_ERROR：密码操作失败。 |

### OH_CryptoAsymKeySpec_GetParam()

```c
OH_Crypto_ErrCode OH_CryptoAsymKeySpec_GetParam(OH_CryptoAsymKeySpec *spec, CryptoAsymKey_ParamType type, Crypto_DataBlob *value)
```

**描述**

获取非对称密钥规格的指定参数。

注意：使用完成后必须通过[OH_Crypto_FreeDataBlob](capi-crypto-common-h.md#oh_crypto_freedatablob)释放value内存。

**起始版本：** 20

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoAsymKeySpec](capi-cryptoasymkeyapi-oh-cryptoasymkeyspec.md) *spec | [in] 非对称密钥规格。不能为NULL。 |
| [CryptoAsymKey_ParamType](capi-crypto-asym-key-h.md#cryptoasymkey_paramtype) type | [in] 非对称密钥参数类型。 |
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *value | [out] 指向用于存储输出数据的Crypto_DataBlob结构体的指针。不能为NULL。调用前需将value初始化为{0}，不要预分配value->data内存。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | CRYPTO_SUCCESS：操作成功。<br>CRYPTO_PARAMETER_CHECK_FAILED：spec或value为NULL，或该参数类型不支持该算法。<br>CRYPTO_NOT_SUPPORTED：不支持的操作或算法。<br>CRYPTO_MEMORY_ERROR：内存分配失败。<br>CRYPTO_OPERTION_ERROR：密码操作失败。 |

### OH_CryptoAsymKeySpec_Destroy()

```c
void OH_CryptoAsymKeySpec_Destroy(OH_CryptoAsymKeySpec *spec)
```

**描述**

销毁非对称密钥规格。

**起始版本：** 20

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoAsymKeySpec](capi-cryptoasymkeyapi-oh-cryptoasymkeyspec.md) *spec | [in] 非对称密钥规格。 |

### OH_CryptoAsymKeyGeneratorWithSpec_Create()

```c
OH_Crypto_ErrCode OH_CryptoAsymKeyGeneratorWithSpec_Create(OH_CryptoAsymKeySpec *keySpec, OH_CryptoAsymKeyGeneratorWithSpec **generator)
```

**描述**

根据非对称密钥规格创建密钥生成器。

注意：创建的资源必须通过[OH_CryptoAsymKeyGeneratorWithSpec_Destroy](capi-crypto-asym-key-h.md#oh_cryptoasymkeygeneratorwithspec_destroy)销毁。

**起始版本：** 20

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoAsymKeySpec](capi-cryptoasymkeyapi-oh-cryptoasymkeyspec.md) *keySpec | [in] 非对称密钥规格。不能为NULL。 |
| [OH_CryptoAsymKeyGeneratorWithSpec](capi-cryptoasymkeyapi-oh-cryptoasymkeygeneratorwithspec.md) **generator | [out] 指向基于规格的非对称密钥生成器指针的指针。generator不能为NULL，*generator必须为NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | CRYPTO_SUCCESS：操作成功。<br>CRYPTO_PARAMETER_CHECK_FAILED：keySpec或generator为NULL，或密钥规格参数不完整或无效。<br>CRYPTO_NOT_SUPPORTED：不支持的算法。<br>CRYPTO_MEMORY_ERROR：内存分配失败。<br>CRYPTO_OPERTION_ERROR：创建生成器失败。 |

**参考：**

[OH_CryptoAsymKeyGeneratorWithSpec_GenKeyPair](capi-crypto-asym-key-h.md#oh_cryptoasymkeygeneratorwithspec_genkeypair) 根据非对称密钥规格生成密钥对。


### OH_CryptoAsymKeyGeneratorWithSpec_GenKeyPair()

```c
OH_Crypto_ErrCode OH_CryptoAsymKeyGeneratorWithSpec_GenKeyPair(OH_CryptoAsymKeyGeneratorWithSpec *generator, OH_CryptoKeyPair **keyPair)
```

**描述**

根据非对称密钥规格生成密钥对。

注意：使用完成后必须通过[OH_CryptoKeyPair_Destroy](capi-crypto-asym-key-h.md#oh_cryptokeypair_destroy)释放keyPair内存。

**起始版本：** 20

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoAsymKeyGeneratorWithSpec](capi-cryptoasymkeyapi-oh-cryptoasymkeygeneratorwithspec.md) *generator | [in] 基于规格的非对称密钥生成器。不能为NULL。 |
| [OH_CryptoKeyPair](capi-cryptoasymkeyapi-oh-cryptokeypair.md) **keyPair | [out] 指向密钥对指针的指针。keyPair不能为NULL，*keyPair必须为NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | CRYPTO_SUCCESS：操作成功。<br>CRYPTO_PARAMETER_CHECK_FAILED：generator或keyPair为NULL。<br>CRYPTO_NOT_SUPPORTED：不支持的操作。<br>CRYPTO_MEMORY_ERROR：内存分配失败。<br>CRYPTO_OPERTION_ERROR：生成密钥对失败。可能的原因：密钥规格参数不完整或不一致。 |

### OH_CryptoAsymKeyGeneratorWithSpec_Destroy()

```c
void OH_CryptoAsymKeyGeneratorWithSpec_Destroy(OH_CryptoAsymKeyGeneratorWithSpec *generator)
```

**描述**

销毁根据规格创建的非对称密钥生成器。

**起始版本：** 20

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoAsymKeyGeneratorWithSpec](capi-cryptoasymkeyapi-oh-cryptoasymkeygeneratorwithspec.md) *generator | [in] 基于规格的非对称密钥生成器。 |

### OH_CryptoEcPoint_Create()

```c
OH_Crypto_ErrCode OH_CryptoEcPoint_Create(const char *curveName, Crypto_DataBlob *ecKeyData, OH_CryptoEcPoint **point)
```

**描述**

创建椭圆曲线点。

注意：创建的资源必须通过[OH_CryptoEcPoint_Destroy](capi-crypto-asym-key-h.md#oh_cryptoecpoint_destroy)销毁。

**起始版本：** 20

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char *curveName | [in] 椭圆曲线的NID（Name Identifier）字符串名称，不能为NULL。例如"NID_X9_62_prime256v1"、"NID_secp384r1"、"NID_secp521r1"、"NID_sm2"。 |
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *ecKeyData | [in] 椭圆曲线点数据，支持"04 \|\| x \|\| y"、"02 \|\| x"或"03 \|\| x"格式。可以为NULL。如果ecKeyData参数为NULL，将创建一个空的椭圆曲线点规格。 |
| [OH_CryptoEcPoint](capi-cryptoasymkeyapi-oh-cryptoecpoint.md) **point | [out] 指向椭圆曲线点指针的指针。point不能为NULL，*point必须为NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | CRYPTO_SUCCESS：操作成功。<br>CRYPTO_PARAMETER_CHECK_FAILED：curveName或point为NULL，或曲线名称无效。<br>CRYPTO_NOT_SUPPORTED：不支持的曲线。<br>CRYPTO_MEMORY_ERROR：内存分配失败。<br>CRYPTO_OPERTION_ERROR：创建EC点失败。可能的原因：点数据格式不正确。 |

**参考：**

[OH_CryptoEcPoint_GetCoordinate](capi-crypto-asym-key-h.md#oh_cryptoecpoint_getcoordinate) 获取椭圆曲线点的x和y坐标。

[OH_CryptoEcPoint_SetCoordinate](capi-crypto-asym-key-h.md#oh_cryptoecpoint_setcoordinate) 设置椭圆曲线点的x和y坐标。


### OH_CryptoEcPoint_GetCoordinate()

```c
OH_Crypto_ErrCode OH_CryptoEcPoint_GetCoordinate(OH_CryptoEcPoint *point, Crypto_DataBlob *x, Crypto_DataBlob *y)
```

**描述**

获取椭圆曲线点的x和y坐标。

注意：使用完成后必须通过[OH_Crypto_FreeDataBlob](capi-crypto-common-h.md#oh_crypto_freedatablob)释放x和y内存

**起始版本：** 20

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoEcPoint](capi-cryptoasymkeyapi-oh-cryptoecpoint.md) *point | [in] 椭圆曲线点。不能为NULL。 |
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *x | [out] 指向用于存储x坐标的Crypto_DataBlob结构体的指针。不能为NULL。调用前需将x初始化为{0}，不要预分配x->data内存。 |
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *y | [out] 指向用于存储y坐标的Crypto_DataBlob结构体的指针。不能为NULL。调用前需将y初始化为{0}，不要预分配y->data内存。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | CRYPTO_SUCCESS：操作成功。<br>CRYPTO_PARAMETER_CHECK_FAILED：point、x或y为NULL。<br>CRYPTO_NOT_SUPPORTED：不支持的操作或算法。<br>CRYPTO_MEMORY_ERROR：内存分配失败。<br>CRYPTO_OPERTION_ERROR：密码操作失败。 |

### OH_CryptoEcPoint_SetCoordinate()

```c
OH_Crypto_ErrCode OH_CryptoEcPoint_SetCoordinate(OH_CryptoEcPoint *point, Crypto_DataBlob *x, Crypto_DataBlob *y)
```

**描述**

设置椭圆曲线点的x和y坐标。

**起始版本：** 20

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoEcPoint](capi-cryptoasymkeyapi-oh-cryptoecpoint.md) *point | [in] 椭圆曲线点。不能为NULL。 |
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *x | [in] 椭圆曲线点的x坐标。本接口会对x和y中的数据进行深拷贝，调用者在接口返回后可立即释放x和y。不能为NULL。 |
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *y | [in] 椭圆曲线点的y坐标。不能为NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | CRYPTO_SUCCESS：操作成功。<br>CRYPTO_PARAMETER_CHECK_FAILED：point、x或y为NULL。<br>CRYPTO_NOT_SUPPORTED：不支持的操作或算法。<br>CRYPTO_MEMORY_ERROR：深拷贝内存分配失败。<br>CRYPTO_OPERTION_ERROR：密码操作失败。 |

**参考：**

[OH_CryptoEcPoint_Encode](capi-crypto-asym-key-h.md#oh_cryptoecpoint_encode) 将椭圆曲线点编码为指定格式。


### OH_CryptoEcPoint_Encode()

```c
OH_Crypto_ErrCode OH_CryptoEcPoint_Encode(OH_CryptoEcPoint *point, const char *format, Crypto_DataBlob *out)
```

**描述**

将椭圆曲线点编码为指定格式。

注意：使用完成后必须通过[OH_Crypto_FreeDataBlob](capi-crypto-common-h.md#oh_crypto_freedatablob)释放out内存。

**起始版本：** 20

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoEcPoint](capi-cryptoasymkeyapi-oh-cryptoecpoint.md) *point | [in] 椭圆曲线点。不能为NULL。 |
| const char *format | [in] 编码格式，不能为NULL。支持"UNCOMPRESSED"和"COMPRESSED"。 |
| [Crypto_DataBlob](capi-cryptocommonapi-crypto-datablob.md) *out | [out] 指向用于存储编码后椭圆曲线点数据的Crypto_DataBlob结构体的指针。不能为NULL。 调用前需将out初始化为{0}，不要预分配out->data内存。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Crypto_ErrCode](capi-crypto-common-h.md#oh_crypto_errcode) | CRYPTO_SUCCESS：操作成功。<br>CRYPTO_PARAMETER_CHECK_FAILED：point、format或out为NULL，或格式字符串不是有效的点格式。<br>CRYPTO_NOT_SUPPORTED：不支持的格式。<br>CRYPTO_MEMORY_ERROR：内存分配失败。<br>CRYPTO_OPERTION_ERROR：编码失败。可能的原因：该点不是有效的曲线点。 |

### OH_CryptoEcPoint_Destroy()

```c
void OH_CryptoEcPoint_Destroy(OH_CryptoEcPoint *point)
```

**描述**

销毁椭圆曲线点。

**起始版本：** 20

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_CryptoEcPoint](capi-cryptoasymkeyapi-oh-cryptoecpoint.md) *point | [in] 椭圆曲线点。 |


