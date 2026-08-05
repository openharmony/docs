# 指定密钥参数生成非对称密钥对(C/C++)

<!--Kit: Crypto Architecture Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--Designer: @lanming-->
<!--Tester: @PAFT-->
<!--Adviser: @zengyawen-->

以RSA、ECC、SM2为例，根据指定的密钥参数，生成非对称密钥对（KeyPair），并获取密钥参数属性。

该对象可用于后续的加解密等操作。获取的密钥参数属性可用于存储或传输。

## 指定密钥参数生成RSA密钥对

对应的算法规格请查看[非对称密钥生成和转换规格：RSA](crypto-key-generation-conversion.md#rsa)。

1. 调用[OH_CryptoAsymKeySpec_Create](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptoasymkeyspec_create)，指定算法名为"RSA"， 密钥参数类型为CRYPTO_ASYM_KEY_PUBLIC_KEY_SPEC，创建参数对象（keySpec）。

2. 指定uint8_t类型的RSA密钥对数据（pk、sk、n），分别封装成[Crypto_DataBlob](../../reference/apis-crypto-architecture-kit/capi-cryptocommonapi-crypto-datablob.md)。

3. 调用[OH_CryptoAsymKeySpec_SetParam](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptoasymkeyspec_setparam)，指定参数类型分别为CRYPTO_RSA_E_DATABLOB（pk）、CRYPTO_RSA_D_DATABLOB（sk）、CRYPTO_RSA_N_DATABLOB（n），依次传入封装后的[Crypto_DataBlob](../../reference/apis-crypto-architecture-kit/capi-cryptocommonapi-crypto-datablob.md)，设置参数对象（keySpec）。

   > **注意：**
   > pk、sk、n均要以大端模式输入，且必须为正数。

4. 调用[OH_CryptoAsymKeyGeneratorWithSpec_Create](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptoasymkeygeneratorwithspec_create)，将参数对象（keySpec）传入，创建非对称密钥生成器（generatorSpec）。

5. 调用[OH_CryptoAsymKeyGeneratorWithSpec_GenKeyPair](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptoasymkeygeneratorwithspec_genkeypair)，生成RSA密钥对（keyPair）。

6. 分别传入密钥对中的私钥和公钥，调用[OH_CryptoPrivKey_GetParam](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptoprivkey_getparam)和[OH_CryptoPubKey_GetParam](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptopubkey_getparam)，获取RSA算法中私钥和公钥的各种密钥参数。

<!-- @[TestRsa](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Security/CryptoArchitectureKit/SpecifiedParametersGenerateAsymmetricKeyPair/entry/src/main/cpp/types/project/rsa.cpp) -->

``` C++

#include "CryptoArchitectureKit/crypto_architecture_kit.h"
#include <string>
#define SPLIT_SIZE 2

static OH_Crypto_ErrCode GetRsaKeyParams(OH_CryptoKeyPair *keyCtx, Crypto_DataBlob *pubKeyData, Crypto_DataBlob *dataN)
{
    OH_CryptoPubKey *pubKey = OH_CryptoKeyPair_GetPubKey(keyCtx);
    if (pubKey == nullptr) {
        return CRYPTO_OPERTION_ERROR;
    }
    OH_Crypto_ErrCode ret = OH_CryptoPubKey_GetParam(pubKey, CRYPTO_RSA_E_DATABLOB, pubKeyData);
    if (ret != CRYPTO_SUCCESS) {
        return ret;
    }
    return OH_CryptoPubKey_GetParam(pubKey, CRYPTO_RSA_N_DATABLOB, dataN);
}

static void FreeRsaKeyParams(Crypto_DataBlob *pubKeyData, Crypto_DataBlob *dataN)
{
    OH_Crypto_FreeDataBlob(pubKeyData);
    OH_Crypto_FreeDataBlob(dataN);
}

size_t RsaConvertHex(uint8_t* dest, size_t count, const char* src)
{
    size_t i;
    int value;

    for (i = 0; i < count && sscanf(src + i * SPLIT_SIZE, "%2x", &value) == 1; i++) {
        dest[i] = value;
    }
    return i;
}

struct RsaParams {
    Crypto_DataBlob nData;
    Crypto_DataBlob eData;
    uint8_t n[1024];
    uint8_t e[20];
};

static void PrepareRsaParams(RsaParams *params)
{
    std::string nStr = "9260d0750ae117eee55c3f3deaba74917521a262ee76007cdf8a56755ad73a1598a1408410a01434c3f"
    "5bc54a88b57fa19fc4328daea0750a4c44e88cff3b2382621b80f670464433e4336e6d003e8cd65bff211da144b88291c2259a"
    "00a72b711c116ef7686e8fee34e4d933c868187bdc26f7be071493c86f7a5941c3510806ad67b0f94d88f5cf5c02a092821d86"
    "26e8932b65c5bd8c92049c210932b7afa7ac59c0e886ae5c1edb00d8ce2c57633db26bd6639bff73cee82be9275c402b4cf2a4"
    "388da8cf8c64eefe1c5a0f5ab8057c39fa5c0589c3e253f0960332300f94bea44877b588e1edbde97cf2360727a09b775262d"
    "7ee552b3319b9266f05a25";
    std::string eStr = "010001";
    
    size_t nLen = RsaConvertHex(params->n, nStr.size() / SPLIT_SIZE, nStr.c_str());
    size_t eLen = RsaConvertHex(params->e, eStr.size() / SPLIT_SIZE, eStr.c_str());
    
    params->nData = {.data = params->n, .len = nLen};
    params->eData = {.data = params->e, .len = eLen};
}

static OH_Crypto_ErrCode CreateRsaKeySpec(RsaParams *params, OH_CryptoAsymKeySpec **keySpec)
{
    OH_Crypto_ErrCode ret = OH_CryptoAsymKeySpec_Create("RSA", CRYPTO_ASYM_KEY_PUBLIC_KEY_SPEC, keySpec);
    if (ret != CRYPTO_SUCCESS) {
        return ret;
    }
    
    ret = OH_CryptoAsymKeySpec_SetParam(*keySpec, CRYPTO_RSA_E_DATABLOB, &params->eData);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoAsymKeySpec_Destroy(*keySpec);
        return ret;
    }
    
    ret = OH_CryptoAsymKeySpec_SetParam(*keySpec, CRYPTO_RSA_N_DATABLOB, &params->nData);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoAsymKeySpec_Destroy(*keySpec);
        return ret;
    }
    
    return CRYPTO_SUCCESS;
}

static OH_Crypto_ErrCode GenerateRsaKeyPair(OH_CryptoAsymKeySpec *keySpec,
    OH_CryptoAsymKeyGeneratorWithSpec **generatorSpec, OH_CryptoKeyPair **keyPair)
{
    OH_Crypto_ErrCode ret = OH_CryptoAsymKeyGeneratorWithSpec_Create(keySpec, generatorSpec);
    if (ret != CRYPTO_SUCCESS) {
        return ret;
    }
    
    ret = OH_CryptoAsymKeyGeneratorWithSpec_GenKeyPair(*generatorSpec, keyPair);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoAsymKeyGeneratorWithSpec_Destroy(*generatorSpec);
        return ret;
    }
    
    return CRYPTO_SUCCESS;
}

static OH_Crypto_ErrCode ValidateRsaKeyPair(OH_CryptoKeyPair *keyPair)
{
    Crypto_DataBlob dataE = {.data = nullptr, .len = 0};
    Crypto_DataBlob dataN = {.data = nullptr, .len = 0};
    OH_Crypto_ErrCode ret = GetRsaKeyParams(keyPair, &dataE, &dataN);
    if (ret != CRYPTO_SUCCESS) {
        FreeRsaKeyParams(&dataE, &dataN);
        return ret;
    }
    FreeRsaKeyParams(&dataE, &dataN);
    return CRYPTO_SUCCESS;
}

OH_Crypto_ErrCode doTestRsaGenKeyPairBySpec()
{
    RsaParams params = {};
    PrepareRsaParams(&params);
    
    OH_CryptoAsymKeySpec *keySpec = nullptr;
    OH_Crypto_ErrCode ret = CreateRsaKeySpec(&params, &keySpec);
    if (ret != CRYPTO_SUCCESS) {
        return ret;
    }
    
    OH_CryptoAsymKeyGeneratorWithSpec *generatorSpec = nullptr;
    OH_CryptoKeyPair *keyPair = nullptr;
    ret = GenerateRsaKeyPair(keySpec, &generatorSpec, &keyPair);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoAsymKeySpec_Destroy(keySpec);
        return ret;
    }
    
    ret = ValidateRsaKeyPair(keyPair);
    
    OH_CryptoKeyPair_Destroy(keyPair);
    OH_CryptoAsymKeySpec_Destroy(keySpec);
    OH_CryptoAsymKeyGeneratorWithSpec_Destroy(generatorSpec);
    return ret;
}
```


## 指定密钥参数生成ECC密钥对

对应的算法规格请查看[非对称密钥生成和转换规格：ECC](crypto-key-generation-conversion.md#ecc)。

1. 调用[OH_CryptoAsymKeySpec_Create](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptoasymkeyspec_create)，指定算法名为"ECC"， 密钥参数类型为CRYPTO_ASYM_KEY_COMMON_PARAMS_SPEC，创建参数对象（keySpec）。

2. 指定uint8_t类型的ECC公私钥包含的公共参数（p、a、b、gx、gy、n、h），分别封装成[Crypto_DataBlob](../../reference/apis-crypto-architecture-kit/capi-cryptocommonapi-crypto-datablob.md)。

3. 调用[OH_CryptoAsymKeySpec_SetParam](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptoasymkeyspec_setparam)，指定参数类型分别为CRYPTO_ECC_FP_P_DATABLOB（p）、CRYPTO_ECC_A_DATABLOB（a）、CRYPTO_ECC_B_DATABLOB（b）、CRYPTO_ECC_G_X_DATABLOB（gx）、CRYPTO_ECC_G_Y_DATABLOB（gy）、CRYPTO_ECC_N_DATABLOB（n）、CRYPTO_ECC_H_INT（h），依次传入封装后的[Crypto_DataBlob](../../reference/apis-crypto-architecture-kit/capi-cryptocommonapi-crypto-datablob.md)，设置到参数对象（keySpec）。

   > **注意：**
   > p、a、b、gx、gy、n、h均要以大端模式输入，且必须为正数。

4. 调用[OH_CryptoAsymKeyGeneratorWithSpec_Create](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptoasymkeygeneratorwithspec_create)，将参数对象（keySpec）传入，创建非对称密钥生成器（generatorSpec）。

5. 调用[OH_CryptoAsymKeyGeneratorWithSpec_GenKeyPair](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptoasymkeygeneratorwithspec_genkeypair)，生成ECC密钥对（keyPair）。

6. 分别传入密钥对中的私钥和公钥，调用[OH_CryptoPrivKey_GetParam](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptoprivkey_getparam)和[OH_CryptoPubKey_GetParam](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptopubkey_getparam)，获取ECC算法中私钥和公钥的各种密钥参数。

<!-- @[TestEcc](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Security/CryptoArchitectureKit/SpecifiedParametersGenerateAsymmetricKeyPair/entry/src/main/cpp/types/project/ecc.cpp) -->

``` C++

#include "CryptoArchitectureKit/crypto_architecture_kit.h"
#include <string>

#define SPLIT_SIZE 2

static OH_Crypto_ErrCode GetEccKeyParams(OH_CryptoKeyPair *keyCtx, Crypto_DataBlob *pubKeyXData,
    Crypto_DataBlob *pubKeyYData, Crypto_DataBlob *privKeyData)
{
    OH_CryptoPubKey *pubKey = OH_CryptoKeyPair_GetPubKey(keyCtx);
    if (pubKey == nullptr) {
        return CRYPTO_OPERTION_ERROR;
    }
    OH_Crypto_ErrCode ret = OH_CryptoPubKey_GetParam(pubKey, CRYPTO_ECC_PK_X_DATABLOB, pubKeyXData);
    if (ret != CRYPTO_SUCCESS) {
        return ret;
    }
    ret = OH_CryptoPubKey_GetParam(pubKey, CRYPTO_ECC_PK_Y_DATABLOB, pubKeyYData);
    if (ret != CRYPTO_SUCCESS) {
        return ret;
    }

    OH_CryptoPrivKey *privKey = OH_CryptoKeyPair_GetPrivKey(keyCtx);
    if (privKey == nullptr) {
        return CRYPTO_OPERTION_ERROR;
    }
    ret = OH_CryptoPrivKey_GetParam(privKey, CRYPTO_ECC_SK_DATABLOB, privKeyData);
    return ret;
}

static void FreeEccKeyParams(Crypto_DataBlob *pubKeyXData, Crypto_DataBlob *pubKeyYData, Crypto_DataBlob *privKeyData)
{
    OH_Crypto_FreeDataBlob(pubKeyXData);
    OH_Crypto_FreeDataBlob(pubKeyYData);
    OH_Crypto_FreeDataBlob(privKeyData);
}

struct EccCommonParams {
    Crypto_DataBlob pData;
    Crypto_DataBlob aData;
    Crypto_DataBlob bData;
    Crypto_DataBlob gxData;
    Crypto_DataBlob gyData;
    Crypto_DataBlob nData;
    Crypto_DataBlob hData;
};

static OH_Crypto_ErrCode GetEccCommonParams(OH_CryptoKeyPair *keyCtx, EccCommonParams *params)
{
    OH_CryptoPrivKey *privKey = OH_CryptoKeyPair_GetPrivKey(keyCtx);
    if (privKey == nullptr) {
        return CRYPTO_OPERTION_ERROR;
    }
    OH_Crypto_ErrCode ret = OH_CryptoPrivKey_GetParam(privKey, CRYPTO_ECC_FP_P_DATABLOB, &params->pData);
    if (ret != CRYPTO_SUCCESS) {
        return ret;
    }
    ret = OH_CryptoPrivKey_GetParam(privKey, CRYPTO_ECC_A_DATABLOB, &params->aData);
    if (ret != CRYPTO_SUCCESS) {
        return ret;
    }
    ret = OH_CryptoPrivKey_GetParam(privKey, CRYPTO_ECC_B_DATABLOB, &params->bData);
    if (ret != CRYPTO_SUCCESS) {
        return ret;
    }
    ret = OH_CryptoPrivKey_GetParam(privKey, CRYPTO_ECC_G_X_DATABLOB, &params->gxData);
    if (ret != CRYPTO_SUCCESS) {
        return ret;
    }
    ret = OH_CryptoPrivKey_GetParam(privKey, CRYPTO_ECC_G_Y_DATABLOB, &params->gyData);
    if (ret != CRYPTO_SUCCESS) {
        return ret;
    }
    ret = OH_CryptoPrivKey_GetParam(privKey, CRYPTO_ECC_N_DATABLOB, &params->nData);
    if (ret != CRYPTO_SUCCESS) {
        return ret;
    }
    ret = OH_CryptoPrivKey_GetParam(privKey, CRYPTO_ECC_H_INT, &params->hData);
    if (ret != CRYPTO_SUCCESS) {
        return ret;
    }
    return ret;
}

static void FreeEccCommonParams(EccCommonParams *params)
{
    OH_Crypto_FreeDataBlob(&params->pData);
    OH_Crypto_FreeDataBlob(&params->aData);
    OH_Crypto_FreeDataBlob(&params->bData);
    OH_Crypto_FreeDataBlob(&params->gxData);
    OH_Crypto_FreeDataBlob(&params->gyData);
    OH_Crypto_FreeDataBlob(&params->nData);
    OH_Crypto_FreeDataBlob(&params->hData);
}

size_t ConvertHex(uint8_t* dest, size_t count, const char* src)
{
    size_t i;
    int value;

    for (i = 0; i < count && sscanf(src + i * SPLIT_SIZE, "%2x", &value) == 1; i++) {
        dest[i] = value;
    }
    return i;
}

struct EccParams {
    Crypto_DataBlob pData;
    Crypto_DataBlob aData;
    Crypto_DataBlob bData;
    Crypto_DataBlob gxData;
    Crypto_DataBlob gyData;
    Crypto_DataBlob nData;
    Crypto_DataBlob hData;
    uint8_t p[256];
    uint8_t gx[256];
    uint8_t gy[256];
    uint8_t a[256];
    uint8_t b[256];
    uint8_t n[256];
    uint8_t h[4];
};

static void PrepareEccParams(EccParams *params)
{
    std::string pStr = "ffffffffffffffffffffffffffffffff000000000000000000000001";
    std::string gxStr = "b70e0cbd6bb4bf7f321390b94a03c1d356c21122343280d6115c1d21";
    std::string gyStr = "bd376388b5f723fb4c22dfe6cd4375a05a07476444d5819985007e34";
    std::string aStr = "fffffffffffffffffffffffffffffffefffffffffffffffffffffffe";
    std::string bStr = "b4050a850c04b3abf54132565044b0b7d7bfd8ba270b39432355ffb4";
    std::string nStr = "ffffffffffffffffffffffffffff16a2e0b8f03e13dd29455c5c2a3d";
    uint8_t h[] = {0x00, 0x00, 0x00, 0x01}; // 大端序

    size_t pLen = ConvertHex(params->p, pStr.size() / SPLIT_SIZE, pStr.c_str());
    size_t gxLen = ConvertHex(params->gx, gxStr.size() / SPLIT_SIZE, gxStr.c_str());
    size_t gyLen = ConvertHex(params->gy, gyStr.size() / SPLIT_SIZE, gyStr.c_str());
    size_t aLen = ConvertHex(params->a, aStr.size() / SPLIT_SIZE, aStr.c_str());
    size_t bLen = ConvertHex(params->b, bStr.size() / SPLIT_SIZE, bStr.c_str());
    size_t nLen = ConvertHex(params->n, nStr.size() / SPLIT_SIZE, nStr.c_str());

    params->pData = {.data = params->p, .len = pLen};
    params->aData = {.data = params->a, .len = aLen};
    params->bData = {.data = params->b, .len = bLen};
    params->gxData = {.data = params->gx, .len = gxLen};
    params->gyData = {.data = params->gy, .len = gyLen};
    params->nData = {.data = params->n, .len = nLen};
    params->hData = {.data = h, .len = sizeof(h)};
}

static OH_Crypto_ErrCode CreateEccKeySpec(EccParams *params, OH_CryptoAsymKeySpec **keySpec)
{
    OH_Crypto_ErrCode ret = OH_CryptoAsymKeySpec_Create("ECC", CRYPTO_ASYM_KEY_COMMON_PARAMS_SPEC, keySpec);
    if (ret != CRYPTO_SUCCESS) {
        return ret;
    }

    ret = OH_CryptoAsymKeySpec_SetParam(*keySpec, CRYPTO_ECC_FP_P_DATABLOB, &params->pData);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoAsymKeySpec_Destroy(*keySpec);
        return ret;
    }

    ret = OH_CryptoAsymKeySpec_SetParam(*keySpec, CRYPTO_ECC_A_DATABLOB, &params->aData);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoAsymKeySpec_Destroy(*keySpec);
        return ret;
    }

    ret = OH_CryptoAsymKeySpec_SetParam(*keySpec, CRYPTO_ECC_B_DATABLOB, &params->bData);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoAsymKeySpec_Destroy(*keySpec);
        return ret;
    }

    ret = OH_CryptoAsymKeySpec_SetParam(*keySpec, CRYPTO_ECC_G_X_DATABLOB, &params->gxData);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoAsymKeySpec_Destroy(*keySpec);
        return ret;
    }

    ret = OH_CryptoAsymKeySpec_SetParam(*keySpec, CRYPTO_ECC_G_Y_DATABLOB, &params->gyData);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoAsymKeySpec_Destroy(*keySpec);
        return ret;
    }

    ret = OH_CryptoAsymKeySpec_SetParam(*keySpec, CRYPTO_ECC_N_DATABLOB, &params->nData);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoAsymKeySpec_Destroy(*keySpec);
        return ret;
    }

    ret = OH_CryptoAsymKeySpec_SetParam(*keySpec, CRYPTO_ECC_H_INT, &params->hData);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoAsymKeySpec_Destroy(*keySpec);
        return ret;
    }

    return CRYPTO_SUCCESS;
}

static OH_Crypto_ErrCode GenerateEccKeyPair(OH_CryptoAsymKeySpec *keySpec,
    OH_CryptoAsymKeyGeneratorWithSpec **generatorSpec, OH_CryptoKeyPair **keyPair)
{
    OH_Crypto_ErrCode ret = OH_CryptoAsymKeyGeneratorWithSpec_Create(keySpec, generatorSpec);
    if (ret != CRYPTO_SUCCESS) {
        return ret;
    }

    ret = OH_CryptoAsymKeyGeneratorWithSpec_GenKeyPair(*generatorSpec, keyPair);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoAsymKeyGeneratorWithSpec_Destroy(*generatorSpec);
        return ret;
    }

    return CRYPTO_SUCCESS;
}

static OH_Crypto_ErrCode ValidateEccKeyPair(OH_CryptoKeyPair *keyPair)
{
    Crypto_DataBlob dataPkX = {.data = nullptr, .len = 0};
    Crypto_DataBlob dataPkY = {.data = nullptr, .len = 0};
    Crypto_DataBlob dataSk = {.data = nullptr, .len = 0};
    OH_Crypto_ErrCode ret = GetEccKeyParams(keyPair, &dataPkX, &dataPkY, &dataSk);
    if (ret != CRYPTO_SUCCESS) {
        FreeEccKeyParams(&dataPkX, &dataPkY, &dataSk);
        return ret;
    }
    FreeEccKeyParams(&dataPkX, &dataPkY, &dataSk);

    EccCommonParams commonParams = {};
    ret = GetEccCommonParams(keyPair, &commonParams);
    if (ret != CRYPTO_SUCCESS) {
        FreeEccCommonParams(&commonParams);
        return ret;
    }
    FreeEccCommonParams(&commonParams);

    return CRYPTO_SUCCESS;
}

OH_Crypto_ErrCode doTestEccGenKeyPairBySpec()
{
    EccParams params = {};
    PrepareEccParams(&params);

    OH_CryptoAsymKeySpec *keySpec = nullptr;
    OH_Crypto_ErrCode ret = CreateEccKeySpec(&params, &keySpec);
    if (ret != CRYPTO_SUCCESS) {
        return ret;
    }

    OH_CryptoAsymKeyGeneratorWithSpec *generatorSpec = nullptr;
    OH_CryptoKeyPair *keyPair = nullptr;
    ret = GenerateEccKeyPair(keySpec, &generatorSpec, &keyPair);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoAsymKeySpec_Destroy(keySpec);
        return ret;
    }

    ret = ValidateEccKeyPair(keyPair);

    OH_CryptoKeyPair_Destroy(keyPair);
    OH_CryptoAsymKeySpec_Destroy(keySpec);
    OH_CryptoAsymKeyGeneratorWithSpec_Destroy(generatorSpec);
    return ret;
}
```


## 根据椭圆曲线名生成SM2密钥对

对应的算法规格请查看[非对称密钥生成和转换规格：SM2](crypto-key-generation-conversion.md#sm2)。

1. 调用[OH_CryptoAsymKeySpec_Create](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptoasymkeyspec_create)，指定算法名为"SM2"， 密钥参数类型为CRYPTO_ASYM_KEY_KEY_PAIR_SPEC，创建密钥参数对象（keySpec）。

2. 调用[OH_CryptoAsymKeySpec_GenEcCommonParamsSpec](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptoasymkeyspec_geneccommonparamsspec)，指定曲线为"NID_sm2"， 生成SM2公共参数对象（sm2CommonSpec）。

3. 调用[OH_CryptoAsymKeySpec_SetCommonParamsSpec](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptoasymkeyspec_setcommonparamsspec)，将生成SM2公共参数对象（sm2CommonSpec）设置到密钥参数对象（keySpec）。

4. 指定uint8_t类型的SM2密钥对数据（pkx、pky、sk），分别封装成[Crypto_DataBlob](../../reference/apis-crypto-architecture-kit/capi-cryptocommonapi-crypto-datablob.md)。

5. 调用[OH_CryptoAsymKeySpec_SetParam](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptoasymkeyspec_setparam)，指定参数类型分别为CRYPTO_ECC_PK_X_DATABLOB（pkx）、CRYPTO_ECC_PK_Y_DATABLOB（pky）、CRYPTO_ECC_SK_DATABLOB（sk），依次传入封装后的[Crypto_DataBlob](../../reference/apis-crypto-architecture-kit/capi-cryptocommonapi-crypto-datablob.md)，设置到参数对象（keySpec）。

   > **注意：**
   > pkx、pky、sk均要以大端模式输入，且必须为正数。

6. 调用[OH_CryptoAsymKeyGeneratorWithSpec_Create](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptoasymkeygeneratorwithspec_create)，将参数对象（keySpec）传入，创建非对称密钥生成器（generatorSpec）。

7. 调用[OH_CryptoAsymKeyGeneratorWithSpec_GenKeyPair](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptoasymkeygeneratorwithspec_genkeypair)，生成SM2密钥对（keyPair）。

8. 分别传入密钥对中的私钥和公钥，调用[OH_CryptoPrivKey_GetParam](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptoprivkey_getparam)和[OH_CryptoPubKey_GetParam](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptopubkey_getparam)，获取SM2算法中私钥和公钥的各种密钥参数。

<!-- @[TestSm2](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Security/CryptoArchitectureKit/SpecifiedParametersGenerateAsymmetricKeyPair/entry/src/main/cpp/types/project/sm2.cpp) -->

``` C++

#include "CryptoArchitectureKit/crypto_architecture_kit.h"
#include <string>
#define SPLIT_SIZE 2

static OH_Crypto_ErrCode GetEccKeyParams(OH_CryptoKeyPair *keyCtx, Crypto_DataBlob *pubKeyXData,
    Crypto_DataBlob *pubKeyYData, Crypto_DataBlob *privKeyData)
{
    OH_CryptoPubKey *pubKey = OH_CryptoKeyPair_GetPubKey(keyCtx);
    if (pubKey == nullptr) {
        return CRYPTO_OPERTION_ERROR;
    }
    OH_Crypto_ErrCode ret = OH_CryptoPubKey_GetParam(pubKey, CRYPTO_ECC_PK_X_DATABLOB, pubKeyXData);
    if (ret != CRYPTO_SUCCESS) {
        return ret;
    }
    ret = OH_CryptoPubKey_GetParam(pubKey, CRYPTO_ECC_PK_Y_DATABLOB, pubKeyYData);
    if (ret != CRYPTO_SUCCESS) {
        return ret;
    }

    OH_CryptoPrivKey *privKey = OH_CryptoKeyPair_GetPrivKey(keyCtx);
    if (privKey == nullptr) {
        return CRYPTO_OPERTION_ERROR;
    }
    ret = OH_CryptoPrivKey_GetParam(privKey, CRYPTO_ECC_SK_DATABLOB, privKeyData);
    return ret;
}

static void FreeEccKeyParams(Crypto_DataBlob *pubKeyXData, Crypto_DataBlob *pubKeyYData, Crypto_DataBlob *privKeyData)
{
    OH_Crypto_FreeDataBlob(pubKeyXData);
    OH_Crypto_FreeDataBlob(pubKeyYData);
    OH_Crypto_FreeDataBlob(privKeyData);
}

size_t Sm2ConvertHex(uint8_t* dest, size_t count, const char* src)
{
    size_t i;
    int value;

    for (i = 0; i < count && sscanf(src + i * SPLIT_SIZE, "%2x", &value) == 1; i++) {
        dest[i] = value;
    }
    return i;
}

struct Sm2Params {
    Crypto_DataBlob pkXData;
    Crypto_DataBlob pkYData;
    Crypto_DataBlob skData;
    uint8_t pkX[256];
    uint8_t pkY[256];
    uint8_t sk[256];
};

static void PrepareSm2Params(Sm2Params *params)
{
    std::string pkXStr = "67F3B850BDC0BA5D3A29D8A0883C4B17612AB84F87F18E28F77D824A115C02C4";
    std::string pkYStr = "D48966CE754BBBEDD6501A1385E1B205C186E926ADED44287145E8897D4B2071";
    std::string skStr = "6330B599ECD23ABDC74B9A5B7B5E00E553005F72743101C5FAB83AEB579B7074";
    
    size_t pkXLen = Sm2ConvertHex(params->pkX, pkXStr.size() / SPLIT_SIZE, pkXStr.c_str());
    size_t pkYLen = Sm2ConvertHex(params->pkY, pkYStr.size() / SPLIT_SIZE, pkYStr.c_str());
    size_t skLen = Sm2ConvertHex(params->sk, skStr.size() / SPLIT_SIZE, skStr.c_str());
    
    params->pkXData = {.data = params->pkX, .len = pkXLen};
    params->pkYData = {.data = params->pkY, .len = pkYLen};
    params->skData = {.data = params->sk, .len = skLen};
}

static OH_Crypto_ErrCode CreateSm2KeySpec(Sm2Params *params, OH_CryptoAsymKeySpec **keySpec,
    OH_CryptoAsymKeySpec **sm2CommonSpec)
{
    OH_Crypto_ErrCode ret = OH_CryptoAsymKeySpec_Create("SM2", CRYPTO_ASYM_KEY_KEY_PAIR_SPEC, keySpec);
    if (ret != CRYPTO_SUCCESS) {
        return ret;
    }
    
    ret = OH_CryptoAsymKeySpec_GenEcCommonParamsSpec("NID_sm2", sm2CommonSpec);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoAsymKeySpec_Destroy(*keySpec);
        return ret;
    }
    
    ret = OH_CryptoAsymKeySpec_SetCommonParamsSpec(*keySpec, *sm2CommonSpec);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoAsymKeySpec_Destroy(*sm2CommonSpec);
        OH_CryptoAsymKeySpec_Destroy(*keySpec);
        return ret;
    }
    
    ret = OH_CryptoAsymKeySpec_SetParam(*keySpec, CRYPTO_ECC_PK_X_DATABLOB, &params->pkXData);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoAsymKeySpec_Destroy(*sm2CommonSpec);
        OH_CryptoAsymKeySpec_Destroy(*keySpec);
        return ret;
    }
    
    ret = OH_CryptoAsymKeySpec_SetParam(*keySpec, CRYPTO_ECC_PK_Y_DATABLOB, &params->pkYData);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoAsymKeySpec_Destroy(*sm2CommonSpec);
        OH_CryptoAsymKeySpec_Destroy(*keySpec);
        return ret;
    }
    
    ret = OH_CryptoAsymKeySpec_SetParam(*keySpec, CRYPTO_ECC_SK_DATABLOB, &params->skData);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoAsymKeySpec_Destroy(*sm2CommonSpec);
        OH_CryptoAsymKeySpec_Destroy(*keySpec);
        return ret;
    }
    
    return CRYPTO_SUCCESS;
}

static OH_Crypto_ErrCode GenerateSm2KeyPair(OH_CryptoAsymKeySpec *keySpec,
    OH_CryptoAsymKeyGeneratorWithSpec **generatorSpec, OH_CryptoKeyPair **keyPair)
{
    OH_Crypto_ErrCode ret = OH_CryptoAsymKeyGeneratorWithSpec_Create(keySpec, generatorSpec);
    if (ret != CRYPTO_SUCCESS) {
        return ret;
    }
    
    ret = OH_CryptoAsymKeyGeneratorWithSpec_GenKeyPair(*generatorSpec, keyPair);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoAsymKeyGeneratorWithSpec_Destroy(*generatorSpec);
        return ret;
    }
    
    return CRYPTO_SUCCESS;
}

static OH_Crypto_ErrCode ValidateSm2KeyPair(OH_CryptoKeyPair *keyPair)
{
    Crypto_DataBlob dataPkX = {.data = nullptr, .len = 0};
    Crypto_DataBlob dataPkY = {.data = nullptr, .len = 0};
    Crypto_DataBlob dataSk = {.data = nullptr, .len = 0};
    OH_Crypto_ErrCode ret = GetEccKeyParams(keyPair, &dataPkX, &dataPkY, &dataSk);
    if (ret != CRYPTO_SUCCESS) {
        FreeEccKeyParams(&dataPkX, &dataPkY, &dataSk);
        return ret;
    }
    FreeEccKeyParams(&dataPkX, &dataPkY, &dataSk);
    return CRYPTO_SUCCESS;
}

OH_Crypto_ErrCode doTestSm2GenKeyPairBySpec()
{
    Sm2Params params = {};
    PrepareSm2Params(&params);
    
    OH_CryptoAsymKeySpec *keySpec = nullptr;
    OH_CryptoAsymKeySpec *sm2CommonSpec = nullptr;
    OH_Crypto_ErrCode ret = CreateSm2KeySpec(&params, &keySpec, &sm2CommonSpec);
    if (ret != CRYPTO_SUCCESS) {
        return ret;
    }
    
    OH_CryptoAsymKeyGeneratorWithSpec *generatorSpec = nullptr;
    OH_CryptoKeyPair *keyPair = nullptr;
    ret = GenerateSm2KeyPair(keySpec, &generatorSpec, &keyPair);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoAsymKeySpec_Destroy(sm2CommonSpec);
        OH_CryptoAsymKeySpec_Destroy(keySpec);
        return ret;
    }
    
    ret = ValidateSm2KeyPair(keyPair);
    
    OH_CryptoKeyPair_Destroy(keyPair);
    OH_CryptoAsymKeyGeneratorWithSpec_Destroy(generatorSpec);
    OH_CryptoAsymKeySpec_Destroy(sm2CommonSpec);
    OH_CryptoAsymKeySpec_Destroy(keySpec);
    return ret;
}
```

