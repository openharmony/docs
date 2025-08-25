# Generating an Asymmetric Key Pair Based on Key Parameters (C/C++)

<!--Kit: Crypto Architecture Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--Designer: @lanming-->
<!--Tester: @PAFT-->
<!--Adviser: @zengyawen-->

This topic walks you through on how to generate an RSA, an ECC, and an SM2 asymmetric key pair (**KeyPair**) based on the specified key parameters and obtain the key parameter properties.

The **KeyPair** object created can be used for subsequent operations, such as encryption and decryption. The obtained key parameter properties can be used for key storage and transfer.

## Generating an RSA Key Pair Based on Key Parameters

For details about the algorithm specifications, see [RSA](crypto-asym-key-generation-conversion-spec.md#rsa).

1. Call [OH_CryptoAsymKeySpec_Create](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptoasymkeyspec_create) to set the algorithm name to **RSA** and the key parameter type to **CRYPTO_ASYM_KEY_KEY_PAIR_SPEC** to create a parameter object (**keySpec**).

2. Specify the RSA key pair data (**pk**, **sk**, and **n**) of the uint8_t type and encapsulate them into [Crypto_DataBlob](../../reference/apis-crypto-architecture-kit/capi-cryptocommonapi-crypto-datablob.md).

3. Call [OH_CryptoAsymKeySpec_SetParam](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptoasymkeyspec_setparam) to set the parameter types to **CRYPTO_RSA_E_DATABLOB (pk)**, **CRYPTO_RSA_D_DATABLOB (sk)**, and **CRYPTO_RSA_N_DATABLOB (n)** respectively, and pass the encapsulated [Crypto_DataBlob](../../reference/apis-crypto-architecture-kit/capi-cryptocommonapi-crypto-datablob.md) in sequence to set the parameter object (**keySpec**).

   > **NOTE**
   > The values of **pk**, **sk**, and **n** must be positive numbers entered in big-endian mode.

4. Call [OH_CryptoAsymKeyGeneratorWithSpec_Create](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptoasymkeygeneratorwithspec_create) to pass the parameter object (**keySpec**) and create an asymmetric key generator (**generatorSpec**).

5. Call [OH_CryptoAsymKeyGeneratorWithSpec_GenKeyPair](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptoasymkeygeneratorwithspec_genkeypair) to generate an RSA key pair (**keyPair**).

6. Pass the private key and public key in the key pair, and call [OH_CryptoPrivKey_GetParam](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptoprivkey_getparam) and [OH_CryptoPubKey_GetParam](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptopubkey_getparam) to obtain the key parameters of the private key and public key in the RSA algorithm.

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

## Generating an ECC Key Pair Based on Key Parameters

For details about the algorithm specifications, see [ECC](crypto-asym-key-generation-conversion-spec.md#ecc).

1. Call [OH_CryptoAsymKeySpec_Create](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptoasymkeyspec_create) to set the algorithm name to **ECC** and the key parameter type to **CRYPTO_ASYM_KEY_COMMON_PARAMS_SPEC** to create a parameter object (**keySpec**).

2. Specify the common parameters (**p**, **a**, **b**, **gx**, **gy**, **n**, and **h**) contained in the ECC public and private keys of the uint8_t type and encapsulate them into [Crypto_DataBlob](../../reference/apis-crypto-architecture-kit/capi-cryptocommonapi-crypto-datablob.md).

3. Call [OH_CryptoAsymKeySpec_SetParam](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptoasymkeyspec_setparam) to set the parameter types to **CRYPTO_ECC_FP_P_DATABLOB (p)**, **CRYPTO_ECC_A_DATABLOB (a)**, **CRYPTO_ECC_B_DATABLOB (b)**, **CRYPTO_ECC_G_X_DATABLOB (gx)**, **CRYPTO_ECC_G_Y_DATABLOB (gy)**, **CRYPTO_ECC_N_DATABLOB (n)**, and **CRYPTO_ECC_H_INT (h)**, respectively, and pass the encapsulated [Crypto_DataBlob](../../reference/apis-crypto-architecture-kit/capi-cryptocommonapi-crypto-datablob.md) in sequence to the parameter object (**keySpec**).

   > **NOTE**
   > **p**, **a**, **b**, **gx**, **gy**, **n**, and **h** must be positive numbers entered in big-endian mode.

4. Call [OH_CryptoAsymKeyGeneratorWithSpec_Create](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptoasymkeygeneratorwithspec_create) to pass the parameter object (**keySpec**) and create an asymmetric key generator (**generatorSpec**).

5. Call [OH_CryptoAsymKeyGeneratorWithSpec_GenKeyPair](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptoasymkeygeneratorwithspec_genkeypair) to generate an ECC key pair (**keyPair**).

6. Pass the private key and public key in the key pair, and call [OH_CryptoPrivKey_GetParam](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptoprivkey_getparam) and [OH_CryptoPubKey_GetParam](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptopubkey_getparam) to obtain the key parameters of the private key and public key in the ECC algorithm.


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
    uint8_t h[] = {0x00, 0x00, 0x00, 0x01}; // Digit 1 in big-endian mode
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

## Generating an SM2 Key Pair Based on the Elliptic Curve Name

For details about the algorithm specifications, see [SM2](crypto-asym-key-generation-conversion-spec.md#sm2).

1. Call [OH_CryptoAsymKeySpec_Create](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptoasymkeyspec_create) to set the algorithm name to **SM2** and the key parameter type to **CRYPTO_ASYM_KEY_KEY_PAIR_SPEC** to create a key parameter object (**keySpec**).

2. Call [OH_CryptoAsymKeySpec_GenEcCommonParamsSpec](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptoasymkeyspec_geneccommonparamsspec) to generate an SM2 common parameter object (**sm2CommonSpec**) with the curve name set to **NID_sm2**.

3. Call [OH_CryptoAsymKeySpec_SetCommonParamsSpec](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptoasymkeyspec_setcommonparamsspec) to set the generated **sm2CommonSpec** to the key parameter object (**keySpec**).

4. Specify the SM2 key pair data (**pkx**, **pky**, and **sk**) of the uint8_t type and encapsulate them into [Crypto_DataBlob](../../reference/apis-crypto-architecture-kit/capi-cryptocommonapi-crypto-datablob.md).

5. Call [OH_CryptoAsymKeySpec_SetParam](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptoasymkeyspec_setparam) to set the parameter types to **CRYPTO_ECC_PK_X_DATABLOB (pkx)**, **CRYPTO_ECC_PK_Y_DATABLOB (pky)**, and **CRYPTO_ECC_SK_DATABLOB (sk)** respectively, and pass the encapsulated [Crypto_DataBlob](../../reference/apis-crypto-architecture-kit/capi-cryptocommonapi-crypto-datablob.md) in sequence to set the parameter object (**keySpec**).

   > **NOTE**
   > The values of **pkx**, **pky**, and **sk** must be positive numbers entered in big-endian mode.

6. Call [OH_CryptoAsymKeyGeneratorWithSpec_Create](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptoasymkeygeneratorwithspec_create) to pass the parameter object (**keySpec**) and create an asymmetric key generator (**generatorSpec**).

7. Call [OH_CryptoAsymKeyGeneratorWithSpec_GenKeyPair](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptoasymkeygeneratorwithspec_genkeypair) to generate an SM2 key pair (**keyPair**).

8. Pass the private key and public key in the key pair, and call [OH_CryptoPrivKey_GetParam](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptoprivkey_getparam) and [OH_CryptoPubKey_GetParam](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptopubkey_getparam) to obtain the key parameters of the private key and public key in the SM2 algorithm.

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
