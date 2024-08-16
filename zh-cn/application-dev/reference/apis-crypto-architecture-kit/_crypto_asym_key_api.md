# CryptoAsymKeyApi


## 概述

为应用提供非对称密钥相关接口功能。

**起始版本：** 12


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [crypto_asym_key.h](crypto__asym__key_8h.md) | 声明非对称密钥接口。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [OH_CryptoKeyPair](#oh_cryptokeypair) [OH_CryptoKeyPair](#oh_cryptokeypair) | 定义密钥对结构体。 | 
| typedef struct [OH_CryptoPubKey](#oh_cryptopubkey) [OH_CryptoPubKey](#oh_cryptopubkey) | 定义公钥结构体。 | 
| typedef struct [OH_CryptoAsymKeyGenerator](#oh_cryptoasymkeygenerator) [OH_CryptoAsymKeyGenerator](#oh_cryptoasymkeygenerator) | 定义非对称密钥生成器结构体。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [CryptoAsymKey_ParamType](#cryptoasymkey_paramtype) {<br/>CRYPTO_DSA_P_DATABLOB = 101, CRYPTO_DSA_Q_DATABLOB = 102,<br/>CRYPTO_DSA_G_DATABLOB = 103, CRYPTO_DSA_SK_DATABLOB = 104,<br/>CRYPTO_DSA_PK_DATABLOB = 105, CRYPTO_ECC_FP_P_DATABLOB = 201,<br/>CRYPTO_ECC_A_DATABLOB = 202, CRYPTO_ECC_B_DATABLOB = 203,<br/>CRYPTO_ECC_G_X_DATABLOB = 204, CRYPTO_ECC_G_Y_DATABLOB = 205,<br/>CRYPTO_ECC_N_DATABLOB = 206, CRYPTO_ECC_H_INT = 207,<br/>CRYPTO_ECC_SK_DATABLOB = 208, CRYPTO_ECC_PK_X_DATABLOB = 209,<br/>CRYPTO_ECC_PK_Y_DATABLOB = 210, CRYPTO_ECC_FIELD_TYPE_STR = 211,<br/>CRYPTO_ECC_FIELD_SIZE_INT = 212, CRYPTO_ECC_CURVE_NAME_STR = 213,<br/>CRYPTO_RSA_N_DATABLOB = 301, CRYPTO_RSA_D_DATABLOB = 302,<br/>CRYPTO_RSA_E_DATABLOB = 303, CRYPTO_DH_P_DATABLOB = 401,<br/>CRYPTO_DH_G_DATABLOB = 402, CRYPTO_DH_L_NUM = 403,<br/>CRYPTO_DH_SK_DATABLOB = 404, CRYPTO_DH_PK_DATABLOB = 405,<br/>CRYPTO_ED25519_SK_DATABLOB = 501, CRYPTO_ED25519_PK_DATABLOB = 502,<br/>CRYPTO_X25519_SK_DATABLOB = 601, CRYPTO_X25519_PK_DATABLOB = 602<br/>} | 定义非对称密钥参数类型。 | 
| [Crypto_EncodingType](#crypto_encodingtype) { CRYPTO_PEM = 0, CRYPTO_DER = 1 } | 定义编码格式。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode) [OH_CryptoAsymKeyGenerator_Create](#oh_cryptoasymkeygenerator_create) (const char \*algoName, [OH_CryptoAsymKeyGenerator](#oh_cryptoasymkeygenerator) \*\*ctx) | 通过指定算法名称的字符串，获取相应的非对称密钥生成器实例。 | 
| [OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode) [OH_CryptoAsymKeyGenerator_Generate](#oh_cryptoasymkeygenerator_generate) ([OH_CryptoAsymKeyGenerator](#oh_cryptoasymkeygenerator) \*ctx, [OH_CryptoKeyPair](#oh_cryptokeypair) \*\*keyCtx) | 随机生成非对称密钥（密钥对）。 | 
| [OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode) [OH_CryptoAsymKeyGenerator_Convert](#oh_cryptoasymkeygenerator_convert) ([OH_CryptoAsymKeyGenerator](#oh_cryptoasymkeygenerator) \*ctx, [Crypto_EncodingType](#crypto_encodingtype) type, [Crypto_DataBlob](_crypto___data_blob.md) \*pubKeyData, [Crypto_DataBlob](_crypto___data_blob.md) \*priKeyData, [OH_CryptoKeyPair](#oh_cryptokeypair) \*\*keyCtx) | 转换非对称密钥数据为密钥对。 | 
| const char \* [OH_CryptoAsymKeyGenerator_GetAlgoName](#oh_cryptoasymkeygenerator_getalgoname) ([OH_CryptoAsymKeyGenerator](#oh_cryptoasymkeygenerator) \*ctx) | 获取非对称密钥算法名称。 | 
| void [OH_CryptoAsymKeyGenerator_Destroy](#oh_cryptoasymkeygenerator_destroy) ([OH_CryptoAsymKeyGenerator](#oh_cryptoasymkeygenerator) \*ctx) | 销毁非对称密钥生成器实例。 | 
| void [OH_CryptoKeyPair_Destroy](#oh_cryptokeypair_destroy) ([OH_CryptoKeyPair](#oh_cryptokeypair) \*keyCtx) | 销毁非对称密钥对实例。 | 
| [OH_CryptoPubKey](#oh_cryptopubkey) \* [OH_CryptoKeyPair_GetPubKey](#oh_cryptokeypair_getpubkey) ([OH_CryptoKeyPair](#oh_cryptokeypair) \*keyCtx) | 从密钥对中获取公钥实例。 | 
| [OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode) [OH_CryptoPubKey_Encode](#oh_cryptopubkey_encode) ([OH_CryptoPubKey](#oh_cryptopubkey) \*key, [Crypto_EncodingType](#crypto_encodingtype) type, const char \*encodingStandard, [Crypto_DataBlob](_crypto___data_blob.md) \*out) | 根据指定的编码格式输出公钥数据。 | 
| [OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode) [OH_CryptoPubKey_GetParam](#oh_cryptopubkey_getparam) ([OH_CryptoPubKey](#oh_cryptopubkey) \*key, [CryptoAsymKey_ParamType](#cryptoasymkey_paramtype) item, [Crypto_DataBlob](_crypto___data_blob.md) \*value) | 从公钥实例获取指定参数。 | 


## 类型定义说明


### OH_CryptoAsymKeyGenerator

```
typedef struct OH_CryptoAsymKeyGenerator OH_CryptoAsymKeyGenerator
```

**描述**

定义非对称密钥生成器结构体。

**起始版本：** 12


### OH_CryptoKeyPair

```
typedef struct OH_CryptoKeyPair OH_CryptoKeyPair
```

**描述**

定义密钥对结构体。

**起始版本：** 12


### OH_CryptoPubKey

```
typedef struct OH_CryptoPubKey OH_CryptoPubKey
```

**描述**

定义公钥结构体。

**起始版本：** 12


## 枚举类型说明


### Crypto_EncodingType

```
enum Crypto_EncodingType
```

**描述**

定义编码格式。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| CRYPTO_PEM | PEM格式密钥类型。 | 
| CRYPTO_DER | DER格式密钥类型。 | 


### CryptoAsymKey_ParamType

```
enum CryptoAsymKey_ParamType
```

**描述**

定义非对称密钥参数类型。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| CRYPTO_DSA_P_DATABLOB | DSA算法的素模数p。 | 
| CRYPTO_DSA_Q_DATABLOB | DSA算法中密钥参数q（p-1的素因子）。 | 
| CRYPTO_DSA_G_DATABLOB | DSA算法的参数g。 | 
| CRYPTO_DSA_SK_DATABLOB | DSA算法的私钥sk。 | 
| CRYPTO_DSA_PK_DATABLOB | DSA算法的公钥pk。 | 
| CRYPTO_ECC_FP_P_DATABLOB | ECC算法中表示椭圆曲线Fp域的素数p。 | 
| CRYPTO_ECC_A_DATABLOB | ECC算法中椭圆曲线的第一个系数a。 | 
| CRYPTO_ECC_B_DATABLOB | ECC算法中椭圆曲线的第二个系数b。 | 
| CRYPTO_ECC_G_X_DATABLOB | ECC算法中基点g的x坐标。 | 
| CRYPTO_ECC_G_Y_DATABLOB | ECC算法中基点g的y坐标。 | 
| CRYPTO_ECC_N_DATABLOB | ECC算法中基点g的阶n。 | 
| CRYPTO_ECC_H_INT | ECC算法中的余因子h。 | 
| CRYPTO_ECC_SK_DATABLOB | ECC算法中的私钥sk。 | 
| CRYPTO_ECC_PK_X_DATABLOB | ECC算法中，公钥pk（椭圆曲线上的一个点）的x坐标。 | 
| CRYPTO_ECC_PK_Y_DATABLOB | ECC算法中，公钥pk（椭圆曲线上的一个点）的y坐标。 | 
| CRYPTO_ECC_FIELD_TYPE_STR | ECC算法中，椭圆曲线的域类型（当前只支持Fp域）。 | 
| CRYPTO_ECC_FIELD_SIZE_INT | ECC算法中域的大小，单位为bits（注：对于Fp域，域的大小为素数p的bits长度）。 | 
| CRYPTO_ECC_CURVE_NAME_STR | ECC算法中的SECG(Standards for Efficient Cryptography Group)曲线名称。 | 
| CRYPTO_RSA_N_DATABLOB | RSA算法中的模数n。 | 
| CRYPTO_RSA_D_DATABLOB | RSA算法中的私钥sk（即私钥指数d）。 | 
| CRYPTO_RSA_E_DATABLOB | RSA算法中的公钥pk（即公钥指数e）。 | 
| CRYPTO_DH_P_DATABLOB | DH算法中的素数p。 | 
| CRYPTO_DH_G_DATABLOB | DH算法中的参数g。 | 
| CRYPTO_DH_L_NUM | DH算法中私钥长度，单位为bit。 | 
| CRYPTO_DH_SK_DATABLOB | DH算法中的私钥sk。 | 
| CRYPTO_DH_PK_DATABLOB | DH算法中的公钥pk。 | 
| CRYPTO_ED25519_SK_DATABLOB | ED25519算法中的私钥sk。 | 
| CRYPTO_ED25519_PK_DATABLOB | ED25519算法中的公钥pk。 | 
| CRYPTO_X25519_SK_DATABLOB | X25519算法中的私钥sk。 | 
| CRYPTO_X25519_PK_DATABLOB | X25519算法中的公钥pk。 | 


## 函数说明


### OH_CryptoAsymKeyGenerator_Convert()

```
OH_Crypto_ErrCode OH_CryptoAsymKeyGenerator_Convert (OH_CryptoAsymKeyGenerator *ctx, Crypto_EncodingType type, Crypto_DataBlob *pubKeyData, Crypto_DataBlob *priKeyData, OH_CryptoKeyPair **keyCtx )
```

**描述**

转换非对称密钥数据为密钥对。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ctx | 非对称密钥生成器实例。 | 
| type | 编码格式。 | 
| pubKeyData | 公钥数据。 | 
| priKeyData | 私钥数据。 | 
| keyCtx | 指向非对称密钥对实例的指针。 | 

**返回：**

[OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode):

0 - 成功。

401 - 参数无效。

801 - 操作不支持。

17620001 - 内存错误。

17630001 - 调用三方算法库API出错。


### OH_CryptoAsymKeyGenerator_Create()

```
OH_Crypto_ErrCode OH_CryptoAsymKeyGenerator_Create (const char *algoName, OH_CryptoAsymKeyGenerator **ctx )
```

**描述**

通过指定算法名称的字符串，获取相应的非对称密钥生成器实例。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| algoName | 指定生成对称密钥生成器的算法名称。例如："RSA1024\|PRIMES_2" | 
| ctx | 指向非对称密钥生成器实例的指针。 | 

**返回：**

[OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode):

0 - 成功。

401 - 参数无效。

801 - 操作不支持。

17620001 - 内存错误。

17630001 - 调用三方算法库API出错。


### OH_CryptoAsymKeyGenerator_Destroy()

```
void OH_CryptoAsymKeyGenerator_Destroy (OH_CryptoAsymKeyGenerator *ctx)
```

**描述**

销毁非对称密钥生成器实例。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ctx | 非对称密钥生成器实例。 | 


### OH_CryptoAsymKeyGenerator_Generate()

```
OH_Crypto_ErrCode OH_CryptoAsymKeyGenerator_Generate (OH_CryptoAsymKeyGenerator *ctx, OH_CryptoKeyPair **keyCtx )
```

**描述**

随机生成非对称密钥（密钥对）。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ctx | 非对称密钥生成器实例。 | 
| keyCtx | 指向非对称密钥对实例的指针。 | 

**返回：**

[OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode):

0 - 成功。

401 - 参数无效。

801 - 操作不支持。

17620001 - 内存错误。

17630001 - 调用三方算法库API出错。


### OH_CryptoAsymKeyGenerator_GetAlgoName()

```
const char* OH_CryptoAsymKeyGenerator_GetAlgoName (OH_CryptoAsymKeyGenerator *ctx)
```

**描述**

获取非对称密钥算法名称。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ctx | 非对称密钥生成器实例。 | 

**返回：**

返回非对称密钥算法名称。


### OH_CryptoKeyPair_Destroy()

```
void OH_CryptoKeyPair_Destroy (OH_CryptoKeyPair *keyCtx)
```

**描述**

销毁非对称密钥对实例。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| keyCtx | 非对称密钥对实例。 | 


### OH_CryptoKeyPair_GetPubKey()

```
OH_CryptoPubKey* OH_CryptoKeyPair_GetPubKey (OH_CryptoKeyPair *keyCtx)
```

**描述**

从密钥对中获取公钥实例。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| keyCtx | 密钥对实例。 | 

**返回：**

返回从密钥对中得到的公钥实例。


### OH_CryptoPubKey_Encode()

```
OH_Crypto_ErrCode OH_CryptoPubKey_Encode (OH_CryptoPubKey *key, Crypto_EncodingType type, const char *encodingStandard, Crypto_DataBlob *out )
```

**描述**

根据指定的编码格式输出公钥数据。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| key | 公钥实例。 | 
| type | 编码类型。 | 
| encodingStandard | 编码格式。 | 
| out | 输出的公钥结果。 | 

**返回：**

[OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode):

0 - 成功。

401 - 参数无效。

801 - 操作不支持。

17620001 - 内存错误。

17630001 - 调用三方算法库API出错。


### OH_CryptoPubKey_GetParam()

```
OH_Crypto_ErrCode OH_CryptoPubKey_GetParam (OH_CryptoPubKey *key, CryptoAsymKey_ParamType item, Crypto_DataBlob *value )
```

**描述**

从公钥实例获取指定参数。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| key | 公钥实例。 | 
| item | 非对称密钥参数类型。 | 
| value | 参数输出值。 | 

**返回：**

[OH_Crypto_ErrCode](_crypto_common_api.md#oh_crypto_errcode): 0 - 成功。

401 - 参数无效。

801 - 操作不支持。

17620001 - 内存错误。

17630001 - 调用三方算法库API出错。
