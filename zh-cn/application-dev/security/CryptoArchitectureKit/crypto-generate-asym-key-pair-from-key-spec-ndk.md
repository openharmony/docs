# 指定密钥参数生成非对称密钥对(C/C++)

以RSA、ECC、SM2为例，根据指定的密钥参数，生成非对称密钥对（KeyPair），并获取密钥参数属性。

该对象可用于后续的加解密等操作。获取的密钥参数属性可用于存储或运输。

## 指定密钥参数生成RSA密钥对

对应的算法规格请查看[非对称密钥生成和转换规格：RSA](crypto-asym-key-generation-conversion-spec.md#rsa)。

1. 调用[OH_CryptoAsymKeySpec_Create](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptoasymkeyspec_create)，指定算法名为"RSA"， 密钥参数类型为CRYPTO_ASYM_KEY_KEY_PAIR_SPEC，创建参数对象（keySpec）。

2. 指定uint8_t类型的RSA密钥对数据（pk、sk、n），分别封装成[Crypto_DataBlob](../../reference/apis-crypto-architecture-kit/capi-cryptocommonapi-crypto-datablob.md)。

3. 调用[OH_CryptoAsymKeySpec_SetParam](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptoasymkeyspec_setparam)，指定参数类型分别为CRYPTO_RSA_E_DATABLOB（pk）、CRYPTO_RSA_D_DATABLOB（sk）、CRYPTO_RSA_N_DATABLOB（n）, 依次传入封装后的[Crypto_DataBlob](../../reference/apis-crypto-architecture-kit/capi-cryptocommonapi-crypto-datablob.md)，设置参数对象（keySpec）。

   > **注意：**
   > pk、sk、n均要以大端模式输入，且必须为正数。

4. 调用[OH_CryptoAsymKeyGeneratorWithSpec_Create](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptoasymkeygeneratorwithspec_create)，将参数对象（keySpec）传入，创建非对称密钥生成器（generatorSpec）。

5. 调用[OH_CryptoAsymKeyGeneratorWithSpec_GenKeyPair](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptoasymkeygeneratorwithspec_genkeypair)，生成RSA密钥对（keyPair）。

6. 分别传入密钥对中的私钥和公钥，调用[OH_CryptoPrivKey_GetParam](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptoprivkey_getparam)和[OH_CryptoPubKey_GetParam](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptopubkey_getparam)，获取RSA算法中私钥和公钥的各种密钥参数。

```C++
#include "CryptoArchitectureKit/crypto_architecture_kit.h"
#include <string>

static OH_Crypto_ErrCode GetRsaKeyParams(OH_CryptoKeyPair *keyCtx, Crypto_DataBlob *pubKeyData,
                                         Crypto_DataBlob *dataN)
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

size_t ConvertHex(uint8_t* dest, size_t count, const char* src)
{
    size_t i;
    int value;

    for (i = 0; i < count && sscanf(src + i * 2, "%2x", &value) == 1; i++) {
        dest[i] = value;
    }
    return i;
}

static OH_Crypto_ErrCode doTestRsaGenKeyPairBySpec()
{
    std::string nStr = "9260d0750ae117eee55c3f3deaba74917521a262ee76007cdf8a56755ad73a1598a1408410a01434c3f5bc54a88b57fa19fc4328daea0750a4c44e88cff3b2382621b80f670464433e4336e6d003e8cd65bff211da144b88291c2259a00a72b711c116ef7686e8fee34e4d933c868187bdc26f7be071493c86f7a5941c3510806ad67b0f94d88f5cf5c02a092821d8626e8932b65c5bd8c92049c210932b7afa7ac59c0e886ae5c1edb00d8ce2c57633db26bd6639bff73cee82be9275c402b4cf2a4388da8cf8c64eefe1c5a0f5ab8057c39fa5c0589c3e253f0960332300f94bea44877b588e1edbde97cf2360727a09b775262d7ee552b3319b9266f05a25";
    std::string eStr = "010001";
    uint8_t n[1024] = {};
    uint8_t e[20] = {};
    size_t nLen = ConvertHex(n, nStr.size() / 2, nStr.c_str());
    size_t eLen = ConvertHex(e, eStr.size() / 2, eStr.c_str());
    Crypto_DataBlob nData = {.data = n, .len = nLen};
    Crypto_DataBlob eData = {.data = e, .len = eLen};

    OH_CryptoAsymKeySpec *keySpec = nullptr;
    OH_Crypto_ErrCode ret = OH_CryptoAsymKeySpec_Create("RSA", CRYPTO_ASYM_KEY_PUBLIC_KEY_SPEC, &keySpec);
    if (ret != CRYPTO_SUCCESS) {
        return ret;
    }
    ret = OH_CryptoAsymKeySpec_SetParam(keySpec, CRYPTO_RSA_E_DATABLOB, &eData);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoAsymKeySpec_Destroy(keySpec);
        return ret;
    }
    ret = OH_CryptoAsymKeySpec_SetParam(keySpec, CRYPTO_RSA_N_DATABLOB, &nData);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoAsymKeySpec_Destroy(keySpec);
        return ret;
    }

    OH_CryptoAsymKeyGeneratorWithSpec *generatorSpec = nullptr;
    ret = OH_CryptoAsymKeyGeneratorWithSpec_Create(keySpec, &generatorSpec);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoAsymKeySpec_Destroy(keySpec);
        return ret;
    }
    OH_CryptoKeyPair *keyPair = nullptr;
    ret = OH_CryptoAsymKeyGeneratorWithSpec_GenKeyPair(generatorSpec, &keyPair);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoAsymKeyGeneratorWithSpec_Destroy(generatorSpec);
        OH_CryptoAsymKeySpec_Destroy(keySpec);
        return ret;
    }

    Crypto_DataBlob dataE = {.data = nullptr, .len = 0};
    Crypto_DataBlob dataN = {.data = nullptr, .len = 0};
    ret = GetRsaKeyParams(keyPair, &dataE, &dataN);
    if (ret != CRYPTO_SUCCESS) {
        FreeRsaKeyParams(&dataE, &dataN);
        OH_CryptoKeyPair_Destroy(keyPair);
        OH_CryptoAsymKeyGeneratorWithSpec_Destroy(generatorSpec);
        OH_CryptoAsymKeySpec_Destroy(keySpec);
        return ret;
    }
    FreeRsaKeyParams(&dataE, &dataN);
    OH_CryptoKeyPair_Destroy(keyPair);
    OH_CryptoAsymKeyGeneratorWithSpec_Destroy(generatorSpec);
    OH_CryptoAsymKeySpec_Destroy(keySpec);
    return ret;
}
```

## 指定密钥参数生成ECC密钥对

对应的算法规格请查看[非对称密钥生成和转换规格：ECC](crypto-asym-key-generation-conversion-spec.md#ecc)。

1. 调用[OH_CryptoAsymKeySpec_Create](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptoasymkeyspec_create)，指定算法名为"ECC"， 密钥参数类型为CRYPTO_ASYM_KEY_COMMON_PARAMS_SPEC，创建参数对象（keySpec）。

2. 指定uint8_t类型的ECC公私钥包含的公共参数（p、a、b、gx、gy、n、h），分别封装成[Crypto_DataBlob](../../reference/apis-crypto-architecture-kit/capi-cryptocommonapi-crypto-datablob.md)。

3. 调用[OH_CryptoAsymKeySpec_SetParam](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptoasymkeyspec_setparam)，指定参数类型分别为CRYPTO_ECC_FP_P_DATABLOB（p）、CRYPTO_ECC_A_DATABLOB（a）、CRYPTO_ECC_B_DATABLOB（b）、CRYPTO_ECC_G_X_DATABLOB（gx）、CRYPTO_ECC_G_Y_DATABLOB（gy）、CRYPTO_ECC_N_DATABLOB（n）、CRYPTO_ECC_H_INT（h）, 依次传入封装后的[Crypto_DataBlob](../../reference/apis-crypto-architecture-kit/capi-cryptocommonapi-crypto-datablob.md)，设置到参数对象（keySpec）。

   > **注意：**
   > p、a、b、gx、gy、n、h均要以大端模式输入，且必须为正数。

4. 调用[OH_CryptoAsymKeyGeneratorWithSpec_Create](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptoasymkeygeneratorwithspec_create)，将参数对象（keySpec）传入，创建非对称密钥生成器（generatorSpec）。

5. 调用[OH_CryptoAsymKeyGeneratorWithSpec_GenKeyPair](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptoasymkeygeneratorwithspec_genkeypair)，生成ECC密钥对（keyPair）。

6. 分别传入密钥对中的私钥和公钥，调用[OH_CryptoPrivKey_GetParam](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptoprivkey_getparam)和[OH_CryptoPubKey_GetParam](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptopubkey_getparam)，获取ECC算法中私钥和公钥的各种密钥参数。


```C++
#include "CryptoArchitectureKit/crypto_architecture_kit.h"
#include <string>

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

static OH_Crypto_ErrCode GetEccCommonParams(OH_CryptoKeyPair *keyCtx, Crypto_DataBlob *pData,
                                         Crypto_DataBlob *aData, Crypto_DataBlob *bData, Crypto_DataBlob *gxData,
                                         Crypto_DataBlob *gyData, Crypto_DataBlob *nData, Crypto_DataBlob *hData)
{
    OH_CryptoPrivKey *privKey = OH_CryptoKeyPair_GetPrivKey(keyCtx);
    if (privKey == nullptr) {
        return CRYPTO_OPERTION_ERROR;
    }
    OH_Crypto_ErrCode ret = OH_CryptoPrivKey_GetParam(privKey, CRYPTO_ECC_FP_P_DATABLOB, pData);
    if (ret != CRYPTO_SUCCESS) {
        return ret;
    }
    ret = OH_CryptoPrivKey_GetParam(privKey, CRYPTO_ECC_A_DATABLOB, aData);
    if (ret != CRYPTO_SUCCESS) {
        return ret;
    }
    ret = OH_CryptoPrivKey_GetParam(privKey, CRYPTO_ECC_B_DATABLOB, bData);
    if (ret != CRYPTO_SUCCESS) {
        return ret;
    }
    ret = OH_CryptoPrivKey_GetParam(privKey, CRYPTO_ECC_G_X_DATABLOB, gxData);
    if (ret != CRYPTO_SUCCESS) {
        return ret;
    }
    ret = OH_CryptoPrivKey_GetParam(privKey, CRYPTO_ECC_G_Y_DATABLOB, gyData);
    if (ret != CRYPTO_SUCCESS) {
        return ret;
    }
    ret = OH_CryptoPrivKey_GetParam(privKey, CRYPTO_ECC_N_DATABLOB, nData);
    if (ret != CRYPTO_SUCCESS) {
        return ret;
    }
    ret = OH_CryptoPrivKey_GetParam(privKey, CRYPTO_ECC_H_INT, hData);
    if (ret != CRYPTO_SUCCESS) {
        return ret;
    }
    return ret;
}

static void FreeEccCommonParams(Crypto_DataBlob *pData, Crypto_DataBlob *aData, Crypto_DataBlob *bData,
                                Crypto_DataBlob *gxData, Crypto_DataBlob *gyData, Crypto_DataBlob *nData,
                                Crypto_DataBlob *hData)
{
    OH_Crypto_FreeDataBlob(pData);
    OH_Crypto_FreeDataBlob(aData);
    OH_Crypto_FreeDataBlob(bData);
    OH_Crypto_FreeDataBlob(gxData);
    OH_Crypto_FreeDataBlob(gyData);
    OH_Crypto_FreeDataBlob(nData);
    OH_Crypto_FreeDataBlob(hData);
}

size_t ConvertHex(uint8_t* dest, size_t count, const char* src)
{
    size_t i;
    int value;

    for (i = 0; i < count && sscanf(src + i * 2, "%2x", &value) == 1; i++) {
        dest[i] = value;
    }
    return i;
}

static OH_Crypto_ErrCode doTestEccGenKeyPairBySpec()
{
    std::string pStr = "ffffffffffffffffffffffffffffffff000000000000000000000001";
    std::string gxStr = "b70e0cbd6bb4bf7f321390b94a03c1d356c21122343280d6115c1d21";
    std::string gyStr = "bd376388b5f723fb4c22dfe6cd4375a05a07476444d5819985007e34";
    std::string aStr = "fffffffffffffffffffffffffffffffefffffffffffffffffffffffe";
    std::string bStr = "b4050a850c04b3abf54132565044b0b7d7bfd8ba270b39432355ffb4";
    std::string nStr = "ffffffffffffffffffffffffffff16a2e0b8f03e13dd29455c5c2a3d";
    uint8_t p[256] = {};
    uint8_t gx[256] = {};
    uint8_t gy[256] = {};
    uint8_t a[256] = {};
    uint8_t b[256] = {};
    uint8_t n[256] = {};
    uint8_t h[] = {0x00, 0x00, 0x00, 0x01}; // 1 大端序
    size_t pLen = ConvertHex(p, pStr.size() / 2, pStr.c_str());
    size_t gxLen = ConvertHex(gx, gxStr.size() / 2, gxStr.c_str());
    size_t gyLen = ConvertHex(gy, gyStr.size() / 2, gyStr.c_str());
    size_t aLen = ConvertHex(a, aStr.size() / 2, aStr.c_str());
    size_t bLen = ConvertHex(b, bStr.size() / 2, bStr.c_str());
    size_t nLen = ConvertHex(n, nStr.size() / 2, nStr.c_str());
    Crypto_DataBlob pData = {.data = p, .len = pLen};
    Crypto_DataBlob aData = {.data = a, .len = aLen};
    Crypto_DataBlob bData = {.data = b, .len = bLen};
    Crypto_DataBlob gxData = {.data = gx, .len = gxLen};
    Crypto_DataBlob gyData = {.data = gy, .len = gyLen};
    Crypto_DataBlob nData = {.data = n, .len = nLen};
    Crypto_DataBlob hData = {.data = h, .len = sizeof(h)};

    OH_CryptoAsymKeySpec *keySpec = nullptr;
    OH_Crypto_ErrCode ret = OH_CryptoAsymKeySpec_Create("ECC", CRYPTO_ASYM_KEY_COMMON_PARAMS_SPEC, &keySpec);
    if (ret != CRYPTO_SUCCESS) {
        return ret;
    }
    ret = OH_CryptoAsymKeySpec_SetParam(keySpec, CRYPTO_ECC_FP_P_DATABLOB, &pData);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoAsymKeySpec_Destroy(keySpec);
        return ret;
    }
    ret = OH_CryptoAsymKeySpec_SetParam(keySpec, CRYPTO_ECC_A_DATABLOB, &aData);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoAsymKeySpec_Destroy(keySpec);
        return ret;
    }
    ret = OH_CryptoAsymKeySpec_SetParam(keySpec, CRYPTO_ECC_B_DATABLOB, &bData);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoAsymKeySpec_Destroy(keySpec);
        return ret;
    }
    ret = OH_CryptoAsymKeySpec_SetParam(keySpec, CRYPTO_ECC_G_X_DATABLOB, &gxData);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoAsymKeySpec_Destroy(keySpec);
        return ret;
    }
    ret = OH_CryptoAsymKeySpec_SetParam(keySpec, CRYPTO_ECC_G_Y_DATABLOB, &gyData);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoAsymKeySpec_Destroy(keySpec);
        return ret;
    }
    ret = OH_CryptoAsymKeySpec_SetParam(keySpec, CRYPTO_ECC_N_DATABLOB, &nData);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoAsymKeySpec_Destroy(keySpec);
        return ret;
    }
    ret = OH_CryptoAsymKeySpec_SetParam(keySpec, CRYPTO_ECC_H_INT, &hData);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoAsymKeySpec_Destroy(keySpec);
        return ret;
    }

    OH_CryptoAsymKeyGeneratorWithSpec *generatorSpec = nullptr;
    ret = OH_CryptoAsymKeyGeneratorWithSpec_Create(keySpec, &generatorSpec);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoAsymKeySpec_Destroy(keySpec);
        return ret;
    }
    OH_CryptoKeyPair *keyPair = nullptr;
    ret = OH_CryptoAsymKeyGeneratorWithSpec_GenKeyPair(generatorSpec, &keyPair);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoAsymKeyGeneratorWithSpec_Destroy(generatorSpec);
        OH_CryptoAsymKeySpec_Destroy(keySpec);
        return ret;
    }

    Crypto_DataBlob dataPkX = {.data = nullptr, .len = 0};
    Crypto_DataBlob dataPkY = {.data = nullptr, .len = 0};
    Crypto_DataBlob dataSk = {.data = nullptr, .len = 0};
    ret = GetEccKeyParams(keyPair, &dataPkX, &dataPkY, &dataSk);
    if (ret != CRYPTO_SUCCESS) {
        FreeEccKeyParams(&dataPkX, &dataPkY, &dataSk);
        OH_CryptoKeyPair_Destroy(keyPair);
        OH_CryptoAsymKeySpec_Destroy(keySpec);
        OH_CryptoAsymKeyGeneratorWithSpec_Destroy(generatorSpec);
        return ret;
    }
    FreeEccKeyParams(&dataPkX, &dataPkY, &dataSk);
    Crypto_DataBlob dataP = {.data = nullptr, .len = 0};
    Crypto_DataBlob dataA = {.data = nullptr, .len = 0};
    Crypto_DataBlob dataB = {.data = nullptr, .len = 0};
    Crypto_DataBlob dataGx = {.data = nullptr, .len = 0};
    Crypto_DataBlob dataGy = {.data = nullptr, .len = 0};
    Crypto_DataBlob dataN = {.data = nullptr, .len = 0};
    Crypto_DataBlob dataH = {.data = nullptr, .len = 0};
    ret = GetEccCommonParams(keyPair, &dataP, &dataA, &dataB, &dataGx, &dataGy, &dataN, &dataH);
    if (ret != CRYPTO_SUCCESS) {
        FreeEccCommonParams(&dataP, &dataA, &dataB, &dataGx, &dataGy, &dataN, &dataH);
        OH_CryptoKeyPair_Destroy(keyPair);
        OH_CryptoAsymKeySpec_Destroy(keySpec);
        OH_CryptoAsymKeyGeneratorWithSpec_Destroy(generatorSpec);
        return ret;
    }
    FreeEccCommonParams(&dataP, &dataA, &dataB, &dataGx, &dataGy, &dataN, &dataH);
    OH_CryptoKeyPair_Destroy(keyPair);
    OH_CryptoAsymKeySpec_Destroy(keySpec);
    OH_CryptoAsymKeyGeneratorWithSpec_Destroy(generatorSpec);
    return ret;
}
```

## 根据椭圆曲线名生成SM2密钥对

对应的算法规格请查看[非对称密钥生成和转换规格：SM2](crypto-asym-key-generation-conversion-spec.md#sm2)。

1. 调用[OH_CryptoAsymKeySpec_Create](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptoasymkeyspec_create)，指定算法名为"SM2"， 密钥参数类型为CRYPTO_ASYM_KEY_KEY_PAIR_SPEC，创建密钥参数对象（keySpec）。

2. 调用[OH_CryptoAsymKeySpec_GenEcCommonParamsSpec](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptoasymkeyspec_geneccommonparamsspec)，指定曲线为"NID_sm2"， 生成SM2公共参数对象（sm2CommonSpec）。

3. 调用[OH_CryptoAsymKeySpec_SetCommonParamsSpec](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptoasymkeyspec_setcommonparamsspec)，将生成SM2公共参数对象（sm2CommonSpec）设置到密钥参数对象（keySpec）。

4. 指定uint8_t类型的SM2密钥对数据（pkx、pky、sk），分别封装成[Crypto_DataBlob](../../reference/apis-crypto-architecture-kit/capi-cryptocommonapi-crypto-datablob.md)。

5. 调用[OH_CryptoAsymKeySpec_SetParam](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptoasymkeyspec_setparam)，指定参数类型分别为CRYPTO_ECC_PK_X_DATABLOB（pkx）、CRYPTO_ECC_PK_Y_DATABLOB（pky）、CRYPTO_ECC_SK_DATABLOB（sk）, 依次传入封装后的[Crypto_DataBlob](../../reference/apis-crypto-architecture-kit/capi-cryptocommonapi-crypto-datablob.md)，设置到参数对象（keySpec）。

   > **注意：**
   > pkx、pky、sk均要以大端模式输入，且必须为正数。

6. 调用[OH_CryptoAsymKeyGeneratorWithSpec_Create](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptoasymkeygeneratorwithspec_create)，将参数对象（keySpec）传入，创建非对称密钥生成器（generatorSpec）。

7. 调用[OH_CryptoAsymKeyGeneratorWithSpec_GenKeyPair](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptoasymkeygeneratorwithspec_genkeypair)，生成SM2密钥对（keyPair）。

8. 分别传入密钥对中的私钥和公钥，调用[OH_CryptoPrivKey_GetParam](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptoprivkey_getparam)和[OH_CryptoPubKey_GetParam](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptopubkey_getparam)，获取SM2算法中私钥和公钥的各种密钥参数。

```C++
#include "CryptoArchitectureKit/crypto_architecture_kit.h"
#include <string>

size_t ConvertHex(uint8_t* dest, size_t count, const char* src)
{
    size_t i;
    int value;

    for (i = 0; i < count && sscanf(src + i * 2, "%2x", &value) == 1; i++) {
        dest[i] = value;
    }
    return i;
}

static OH_Crypto_ErrCode doTestSm2GenKeyPairBySpec()
{
    std::string pkXStr = "67F3B850BDC0BA5D3A29D8A0883C4B17612AB84F87F18E28F77D824A115C02C4";
    std::string pkYStr = "D48966CE754BBBEDD6501A1385E1B205C186E926ADED44287145E8897D4B2071";
    std::string skStr = "6330B599ECD23ABDC74B9A5B7B5E00E553005F72743101C5FAB83AEB579B7074";
    uint8_t pkX[256] = {};
    uint8_t pkY[256] = {};
    uint8_t sk[256] = {};
    size_t pkXLen = ConvertHex(pkX, pkXStr.size() / 2, pkXStr.c_str());
    size_t pkYLen = ConvertHex(pkY, pkYStr.size() / 2, pkYStr.c_str());
    size_t skLen = ConvertHex(sk, skStr.size() / 2, skStr.c_str());
    Crypto_DataBlob pkXData = {.data = pkX, .len = pkXLen};
    Crypto_DataBlob pkYData = {.data = pkY, .len = pkYLen};
    Crypto_DataBlob skData = {.data = sk, .len = skLen};

    OH_CryptoAsymKeySpec *keySpec = nullptr;
    OH_Crypto_ErrCode ret = OH_CryptoAsymKeySpec_Create("SM2", CRYPTO_ASYM_KEY_KEY_PAIR_SPEC, &keySpec);
    if (ret != CRYPTO_SUCCESS) {
        return ret;
    }
    OH_CryptoAsymKeySpec *sm2CommonSpec = nullptr;
    ret = OH_CryptoAsymKeySpec_GenEcCommonParamsSpec("NID_sm2", &sm2CommonSpec);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoAsymKeySpec_Destroy(keySpec);
        return ret;
    }
    ret = OH_CryptoAsymKeySpec_SetCommonParamsSpec(keySpec, sm2CommonSpec);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoAsymKeySpec_Destroy(sm2CommonSpec);
        OH_CryptoAsymKeySpec_Destroy(keySpec);
        return ret;
    }
    ret = OH_CryptoAsymKeySpec_SetParam(keySpec, CRYPTO_ECC_PK_X_DATABLOB, &pkXData);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoAsymKeySpec_Destroy(sm2CommonSpec);
        OH_CryptoAsymKeySpec_Destroy(keySpec);
        return ret;
    }
    ret = OH_CryptoAsymKeySpec_SetParam(keySpec, CRYPTO_ECC_PK_Y_DATABLOB, &pkYData);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoAsymKeySpec_Destroy(sm2CommonSpec);
        OH_CryptoAsymKeySpec_Destroy(keySpec);
        return ret;
    }
    ret = OH_CryptoAsymKeySpec_SetParam(keySpec, CRYPTO_ECC_SK_DATABLOB, &skData);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoAsymKeySpec_Destroy(sm2CommonSpec);
        OH_CryptoAsymKeySpec_Destroy(keySpec);
        return ret;
    }

    OH_CryptoAsymKeyGeneratorWithSpec *generatorSpec = nullptr;
    ret = OH_CryptoAsymKeyGeneratorWithSpec_Create(keySpec, &generatorSpec);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoAsymKeySpec_Destroy(sm2CommonSpec);
        OH_CryptoAsymKeySpec_Destroy(keySpec);
        return ret;
    }
    OH_CryptoKeyPair *keyPair = nullptr;
    ret = OH_CryptoAsymKeyGeneratorWithSpec_GenKeyPair(generatorSpec, &keyPair);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoAsymKeyGeneratorWithSpec_Destroy(generatorSpec);
        OH_CryptoAsymKeySpec_Destroy(sm2CommonSpec);
        OH_CryptoAsymKeySpec_Destroy(keySpec);
        return ret;
    }

    Crypto_DataBlob dataPkX = {.data = nullptr, .len = 0};
    Crypto_DataBlob dataPkY = {.data = nullptr, .len = 0};
    Crypto_DataBlob dataSk = {.data = nullptr, .len = 0};
    ret = GetEccKeyParams(keyPair, &dataPkX, &dataPkY, &dataSk);
    if (ret != CRYPTO_SUCCESS) {
        FreeEccKeyParams(&dataPkX, &dataPkY, &dataSk);
        OH_CryptoKeyPair_Destroy(keyPair);
        OH_CryptoAsymKeyGeneratorWithSpec_Destroy(generatorSpec);
        OH_CryptoAsymKeySpec_Destroy(sm2CommonSpec);
        OH_CryptoAsymKeySpec_Destroy(keySpec);
        return ret;
    }
    FreeEccKeyParams(&dataPkX, &dataPkY, &dataSk);
    OH_CryptoKeyPair_Destroy(keyPair);
    OH_CryptoAsymKeyGeneratorWithSpec_Destroy(generatorSpec);
    OH_CryptoAsymKeySpec_Destroy(sm2CommonSpec);
    OH_CryptoAsymKeySpec_Destroy(keySpec);
    return ret;
}
```