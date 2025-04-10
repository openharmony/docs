# 指定密钥参数生成非对称密钥对(C/C++)

以RSA、ECC、SM2为例，根据指定的密钥参数，生成非对称密钥对（KeyPair），并获取密钥参数属性。

该对象可用于后续的加解密等操作。获取的密钥参数属性可用于存储或运输。

## 指定密钥参数生成RSA密钥对

对应的算法规格请查看[非对称密钥生成和转换规格：RSA](crypto-asym-key-generation-conversion-spec.md#rsa)。

1. 调用[OH_CryptoAsymKeySpec_Create](../../reference/apis-crypto-architecture-kit/_crypto_asym_key_api.md#oh_cryptoasymkeyspec_create)，指定算法名为"RSA"， 密钥参数类型为CRYPTO_ASYM_KEY_KEY_PAIR_SPEC，创建参数对象（keySpec）。

2. 指定uint8_t类型的RSA密钥对数据(pk、sk、n)，分别封装成[Crypto_DataBlob](../../reference/apis-crypto-architecture-kit/_crypto_common_api.md#crypto_datablob)。

3. 调用[OH_CryptoAsymKeySpec_SetParam](../../reference/apis-crypto-architecture-kit/_crypto_asym_key_api.md#oh_cryptoasymkeyspec_setparam)，指定参数类型分别为CRYPTO_RSA_E_DATABLOB(pk)、CRYPTO_RSA_D_DATABLOB(sk)、CRYPTO_RSA_N_DATABLOB(n), 依次传入封装后的[Crypto_DataBlob](../../reference/apis-crypto-architecture-kit/_crypto_common_api.md#crypto_datablob)，设置参数对象（keySpec）。

4. 调用[OH_CryptoAsymKeyGeneratorWithSpec_Create](../../reference/apis-crypto-architecture-kit/_crypto_asym_key_api.md#oh_cryptoasymkeygeneratorwithspec_create)，将参数对象（keySpec）传入，创建非对称密钥生成器（generatorSpec）。

5. 调用[OH_CryptoAsymKeyGeneratorWithSpec_GenKeyPair](../../reference/apis-crypto-architecture-kit/_crypto_asym_key_api.md#oh_cryptoasymkeygeneratorwithspec_genkeypair)，生成RSA密钥对（keyPair）。

6. 分别传入密钥对中的私钥和公钥，调用[OH_CryptoPrivKey_GetParam](../../reference/apis-crypto-architecture-kit/_crypto_asym_key_api.md#oh_cryptoprivkey_getparam)和[OH_CryptoPubKey_GetParam](../../reference/apis-crypto-architecture-kit/_crypto_asym_key_api.md#oh_cryptopubkey_getparam)，获取RSA算法中私钥和公钥的各种密钥参数。

```C++
#include "CryptoArchitectureKit/crypto_architecture_kit.h"

static OH_Crypto_ErrCode GetRsaKeyParams(OH_CryptoKeyPair *keyCtx, Crypto_DataBlob *pubKeyData,
                                         Crypto_DataBlob *privKeyData, Crypto_DataBlob *dataN)
{
    OH_CryptoPubKey *pubKey = OH_CryptoKeyPair_GetPubKey(keyCtx);
    if (pubKey == nullptr) {
        return CRYPTO_OPERTION_ERROR;
    }
    OH_Crypto_ErrCode ret = OH_CryptoPubKey_GetParam(pubKey, CRYPTO_RSA_E_DATABLOB, pubKeyData);
    if (ret != CRYPTO_SUCCESS) {
        return ret;
    }

    OH_CryptoPrivKey *privKey = OH_CryptoKeyPair_GetPrivKey(keyCtx);
    if (privKey == nullptr) {
        return CRYPTO_OPERTION_ERROR;
    }
    ret = OH_CryptoPrivKey_GetParam(privKey, CRYPTO_RSA_D_DATABLOB, privKeyData);
    if (ret != CRYPTO_SUCCESS) {
        return ret;
    }
    ret = OH_CryptoPrivKey_GetParam(privKey, CRYPTO_RSA_N_DATABLOB, dataN);
    return ret;
}

static void FreeRsaKeyParams(Crypto_DataBlob *pubKeyData, Crypto_DataBlob *privKeyData, Crypto_DataBlob *dataN)
{
    OH_Crypto_FreeDataBlob(pubKeyData);
    OH_Crypto_FreeDataBlob(privKeyData);
    OH_Crypto_FreeDataBlob(dataN);
}

static OH_Crypto_ErrCode doTestRsaGenKeyPairBySpec()
{
    uint8_t e[] = {0x01, 0x00, 0x01};
    uint8_t d[] = {0x51, 0x3a, 0x7d, 0x23, 0x34, 0xb3, 0x87, 0x96, 0xc2, 0x4a, 0x9e, 0x1e, 0x67, 0x1c, 0xdb, 0x5c,
                   0x22, 0xf6, 0x55, 0x85, 0xf8, 0xca, 0x0f, 0xb6, 0xb3, 0x28, 0x13, 0xd2, 0x0a, 0xc0, 0xdc, 0x28,
                   0xf5, 0xf0, 0xcc, 0xbe, 0xce, 0x96, 0xc9, 0xcb, 0x28, 0x80, 0x02, 0xeb, 0xa1, 0x81, 0xa0, 0xb0,
                   0x2c, 0x8b, 0xb5, 0x6c, 0xf8, 0xe4, 0x54, 0xa1, 0x5d, 0x5d, 0xb4, 0x7e, 0x8d, 0x5e, 0x59, 0x7e,
                   0x50, 0x3a, 0xc1, 0x6e, 0xc7, 0x17, 0x04, 0x37, 0x2e, 0x00, 0xf4, 0x41, 0x34, 0x23, 0xa2, 0x91,
                   0x4f, 0xf8, 0x07, 0xc7, 0xc0, 0xfb, 0xe7, 0x02, 0x47, 0x5e, 0xea, 0xa1, 0x67, 0xef, 0x9a, 0x39,
                   0x13, 0xf8, 0xad, 0x5b, 0x81, 0x23, 0xed, 0xde, 0xd2, 0x43, 0x47, 0x09, 0x5f, 0xdb, 0x19, 0xf5,
                   0x02, 0x05, 0x03, 0x97, 0x5f, 0xd1, 0xf0, 0x69, 0xe3, 0xd4, 0x80, 0x11, 0x69, 0x5d, 0x02, 0x18,
                   0x55, 0x63, 0x77, 0x74, 0x6f, 0x3c, 0xef, 0x9b, 0xaf, 0xef, 0x83, 0x06, 0x70, 0x6e, 0xa7, 0x5d,
                   0x62, 0xff, 0x8d, 0x6e, 0x26, 0xe5, 0xf2, 0x43, 0x01, 0x85, 0x81, 0x87, 0x82, 0xe5, 0x23, 0x87,
                   0x0f, 0x21, 0x70, 0x8a, 0x5b, 0x0b, 0x22, 0x17, 0xd0, 0xf7, 0x19, 0xff, 0x64, 0xe5, 0xf2, 0x2a,
                   0xbe, 0x65, 0xb5, 0xa1, 0x0a, 0x4e, 0x93, 0xb5, 0x94, 0xb4, 0x62, 0x39, 0xab, 0x36, 0x69, 0x50,
                   0x6b, 0xd7, 0x96, 0x00, 0x71, 0x24, 0x4e, 0x3a, 0xc0, 0xf9, 0x16, 0xdc, 0x98, 0x4c, 0x3c, 0x2f,
                   0x78, 0xa7, 0x13, 0x31, 0xe2, 0x64, 0xdd, 0x1e, 0xff, 0x3f, 0xe2, 0x4e, 0x5a, 0x9c, 0xf7, 0xd6,
                   0xc2, 0x82, 0x6f, 0xb6, 0x4c, 0x33, 0x00, 0xff, 0x66, 0x5e, 0xfb, 0x47, 0x17, 0xf5, 0x50, 0x2b,
                   0x51, 0x04, 0x0e, 0x8f, 0x3d, 0x3f, 0x44, 0xdc, 0x0d, 0xc5, 0x40, 0x4c, 0x21, 0xf6, 0xfd, 0x03};
    uint8_t n[] = {0xff, 0xa9, 0x30, 0x1f, 0xdf, 0xa9, 0xf8, 0xb9, 0x1c, 0xd4, 0x5a, 0x38, 0x10, 0x83, 0x9f, 0x97,
                   0x69, 0xae, 0x26, 0xa6, 0x13, 0xe5, 0x61, 0x19, 0xde, 0x34, 0xb6, 0x7e, 0x6f, 0xbc, 0xbc, 0xf4,
                   0x60, 0x1a, 0x4f, 0xd1, 0x2d, 0xa3, 0xd0, 0x51, 0x9f, 0x39, 0xcd, 0x84, 0x07, 0xa1, 0xcc, 0x98,
                   0x45, 0x66, 0x45, 0x8b, 0x7c, 0x03, 0x5e, 0xe6, 0xc7, 0x3c, 0xbf, 0x4d, 0xdb, 0x1d, 0x34, 0x1e,
                   0xc8, 0x94, 0x23, 0x23, 0xfb, 0x76, 0x9b, 0xa5, 0x0f, 0xcd, 0xc6, 0x60, 0x9e, 0xff, 0x0c, 0x20,
                   0x32, 0xd6, 0x45, 0xf8, 0x81, 0x1b, 0xf7, 0xe9, 0xe0, 0x96, 0x46, 0x6d, 0x8f, 0xe6, 0x43, 0xe5,
                   0x07, 0xa2, 0xba, 0xd7, 0xfa, 0xe7, 0x84, 0x87, 0x5b, 0x23, 0x8a, 0x00, 0x35, 0x31, 0x1b, 0xca,
                   0xa8, 0xe8, 0x8a, 0xff, 0x82, 0x3c, 0xf1, 0xe5, 0x9a, 0x33, 0x12, 0xb9, 0xec, 0x24, 0x1c, 0xfa,
                   0x4d, 0x4d, 0x21, 0xba, 0x2e, 0x5d, 0x92, 0x02, 0xa4, 0x78, 0x70, 0x05, 0x6a, 0xd3, 0x78, 0x2c,
                   0x83, 0xb7, 0x4e, 0x76, 0xd5, 0x75, 0x05, 0xa0, 0xc8, 0x0d, 0x3f, 0x91, 0xfc, 0xe8, 0xaa, 0x0b,
                   0x12, 0xdc, 0x89, 0xc7, 0xb4, 0xca, 0x9f, 0xe3, 0x27, 0x22, 0x36, 0x62, 0x7e, 0xc4, 0xf9, 0x32,
                   0x1f, 0x02, 0xea, 0x40, 0x2d, 0x5c, 0x41, 0xc1, 0xd9, 0xcb, 0x05, 0x70, 0x25, 0xe5, 0x01, 0x60,
                   0x36, 0xee, 0xe7, 0xc9, 0xf0, 0x03, 0x60, 0xe7, 0x95, 0x89, 0x9c, 0x67, 0x93, 0x1f, 0xbe, 0x13,
                   0x7f, 0x9e, 0xba, 0xa1, 0x2b, 0x95, 0x73, 0xb8, 0x42, 0x67, 0x26, 0x44, 0x49, 0x54, 0x67, 0xb3,
                   0x24, 0x58, 0x3e, 0x59, 0x8e, 0x20, 0x06, 0xb1, 0x36, 0x77, 0x85, 0x8d, 0x8e, 0xbc, 0xfb, 0x11,
                   0x32, 0x26, 0xd6, 0xe4, 0x34, 0x13, 0x78, 0x0e, 0x84, 0x8a, 0xe4, 0x9a, 0x19, 0x20, 0x06, 0x9c};
    Crypto_DataBlob eData = {.data = e, .len = sizeof(e)};
    Crypto_DataBlob dData = {.data = d, .len = sizeof(d)};
    Crypto_DataBlob nData = {.data = n, .len = sizeof(n)};

    OH_CryptoAsymKeySpec *keySpec = nullptr;
    OH_Crypto_ErrCode ret = OH_CryptoAsymKeySpec_Create("RSA", CRYPTO_ASYM_KEY_KEY_PAIR_SPEC, &keySpec);
    if (ret != CRYPTO_SUCCESS) {
        return ret;
    }
    ret = OH_CryptoAsymKeySpec_SetParam(keySpec, CRYPTO_RSA_E_DATABLOB, &eData);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoAsymKeySpec_Destroy(keySpec);
        return ret;
    }
    ret = OH_CryptoAsymKeySpec_SetParam(keySpec, CRYPTO_RSA_D_DATABLOB, &dData);
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
    Crypto_DataBlob dataD = {.data = nullptr, .len = 0};
    Crypto_DataBlob dataN = {.data = nullptr, .len = 0};
    ret = GetRsaKeyParams(keyPair, &dataE, &dataD, &dataN);
    if (ret != CRYPTO_SUCCESS) {
        FreeRsaKeyParams(&dataE, &dataD, &dataN);
        OH_CryptoKeyPair_Destroy(keyPair);
        OH_CryptoAsymKeyGeneratorWithSpec_Destroy(generatorSpec);
        OH_CryptoAsymKeySpec_Destroy(keySpec);
        return ret;
    }
    FreeRsaKeyParams(&dataE, &dataD, &dataN);
    OH_CryptoKeyPair_Destroy(keyPair);
    OH_CryptoAsymKeyGeneratorWithSpec_Destroy(generatorSpec);
    OH_CryptoAsymKeySpec_Destroy(keySpec);
    return ret;
}
```

## 指定密钥参数生成ECC密钥对

对应的算法规格请查看[非对称密钥生成和转换规格：ECC](crypto-asym-key-generation-conversion-spec.md#ecc)。

1. 调用[OH_CryptoAsymKeySpec_Create](../../reference/apis-crypto-architecture-kit/_crypto_asym_key_api.md#oh_cryptoasymkeyspec_create)，指定算法名为"ECC"， 密钥参数类型为CRYPTO_ASYM_KEY_COMMON_PARAMS_SPEC，创建参数对象（keySpec）。

2. 指定uint8_t类型的ECC公私钥包含的公共参数(p、a、b、gx、gy、n、h)，分别封装成[Crypto_DataBlob](../../reference/apis-crypto-architecture-kit/_crypto_common_api.md#crypto_datablob)。

3. 调用[OH_CryptoAsymKeySpec_SetParam](../../reference/apis-crypto-architecture-kit/_crypto_asym_key_api.md#oh_cryptoasymkeyspec_setparam)，指定参数类型分别为CRYPTO_ECC_FP_P_DATABLOB(p)、CRYPTO_ECC_A_DATABLOB(a)、CRYPTO_ECC_B_DATABLOB(b)、CRYPTO_ECC_G_X_DATABLOB(gx)、CRYPTO_ECC_G_Y_DATABLOB(gy)、CRYPTO_ECC_N_DATABLOB(n)、CRYPTO_ECC_H_INT(h), 依次传入封装后的[Crypto_DataBlob](../../reference/apis-crypto-architecture-kit/_crypto_common_api.md#crypto_datablob)，设置到参数对象（keySpec）。

4. 调用[OH_CryptoAsymKeyGeneratorWithSpec_Create](../../reference/apis-crypto-architecture-kit/_crypto_asym_key_api.md#oh_cryptoasymkeygeneratorwithspec_create)，将参数对象（keySpec）传入，创建非对称密钥生成器（generatorSpec）。

5. 调用[OH_CryptoAsymKeyGeneratorWithSpec_GenKeyPair](../../reference/apis-crypto-architecture-kit/_crypto_asym_key_api.md#oh_cryptoasymkeygeneratorwithspec_genkeypair)，生成ECC密钥对（keyPair）。

6. 分别传入密钥对中的私钥和公钥，调用[OH_CryptoPrivKey_GetParam](../../reference/apis-crypto-architecture-kit/_crypto_asym_key_api.md#oh_cryptoprivkey_getparam)和[OH_CryptoPubKey_GetParam](../../reference/apis-crypto-architecture-kit/_crypto_asym_key_api.md#oh_cryptopubkey_getparam)，获取ECC算法中私钥和公钥的各种密钥参数。


```C++
#include "CryptoArchitectureKit/crypto_architecture_kit.h"

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

static OH_Crypto_ErrCode doTestEccGenKeyPairBySpec()
{
    uint8_t p[] = {0x53, 0xec, 0x07, 0x31, 0x13, 0x00, 0x47, 0x87, 0x71, 0x1a, 0x1d, 0x90, 0x29, 0xa7, 0xd3, 0xac,
                   0x23, 0x11, 0xb7, 0x7f, 0x19, 0xda, 0xb1, 0x12, 0xb4, 0x56, 0x54, 0xed, 0x09, 0x71, 0x2f, 0x15,
                   0xdf, 0x41, 0xe6, 0x50, 0x7e, 0x6f, 0x5d, 0x0f, 0x28, 0x6d, 0x38, 0xa3, 0x82, 0x1e, 0xb9, 0x8c};
    uint8_t a[] = {0x26, 0x28, 0xce, 0x22, 0xdd, 0xc7, 0xa8, 0x04, 0xeb, 0xd4, 0x3a, 0x50, 0x4a, 0x81, 0xa5, 0x8a,
                   0x0f, 0xf9, 0x91, 0xba, 0xef, 0x65, 0x91, 0x13, 0x87, 0x27, 0xb2, 0x4f, 0x8e, 0xa2, 0xbe, 0xc2,
                   0xa0, 0xaf, 0x05, 0xce, 0x0a, 0x08, 0x72, 0x3c, 0x0c, 0x15, 0x8c, 0x3d, 0xc6, 0x82, 0xc3, 0x7b};
    uint8_t b[] = {0x11, 0x4c, 0x50, 0xfa, 0x96, 0x86, 0xb7, 0x3a, 0x94, 0xc9, 0xdb, 0x95, 0x02, 0x39, 0xb4, 0x7c,
                   0xd5, 0x62, 0xeb, 0x3e, 0xa5, 0x0e, 0x88, 0x2e, 0xa6, 0xd2, 0xdc, 0x07, 0xe1, 0x7d, 0xb7, 0x2f,
                   0x7c, 0x44, 0xf0, 0x16, 0x54, 0xb5, 0x39, 0x8b, 0x26, 0x28, 0xce, 0x22, 0xdd, 0xc7, 0xa8, 0x04};
    uint8_t gx[] = {0x1e, 0xaf, 0xd4, 0x47, 0xe2, 0xb2, 0x87, 0xef, 0xaa, 0x46, 0xd6, 0x36, 0x34, 0xe0, 0x26, 0xe8,
                    0xe8, 0x10, 0xbd, 0x0c, 0xfe, 0xca, 0x7f, 0xdb, 0xe3, 0x4f, 0xf1, 0x7e, 0xe7, 0xa3, 0x47, 0x88,
                    0x6b, 0x3f, 0xc1, 0xb7, 0x81, 0x3a, 0xa6, 0xa2, 0xff, 0x45, 0xcf, 0x68, 0xf0, 0x64, 0x1c, 0x1d};
    uint8_t gy[] = {0x15, 0x53, 0x3c, 0x26, 0x41, 0x03, 0x82, 0x42, 0x11, 0x81, 0x91, 0x77, 0x21, 0x46, 0x46, 0x0e,
                    0x28, 0x29, 0x91, 0xf9, 0x4f, 0x05, 0x9c, 0xe1, 0x64, 0x58, 0xec, 0xfe, 0x29, 0x0b, 0xb7, 0x62,
                    0x52, 0xd5, 0xcf, 0x95, 0x8e, 0xeb, 0xb1, 0x5c, 0xa4, 0xc2, 0xf9, 0x20, 0x75, 0x1d, 0xbe, 0x8a};
    uint8_t n[] = {0x65, 0x65, 0x04, 0xe9, 0x02, 0x32, 0x88, 0x3b, 0x10, 0xc3, 0x7f, 0x6b, 0xaf, 0xb6, 0x3a, 0xcf,
                   0xa7, 0x25, 0x04, 0xac, 0x6c, 0x6e, 0x16, 0x1f, 0xb3, 0x56, 0x54, 0xed, 0x09, 0x71, 0x2f, 0x15,
                   0xdf, 0x41, 0xe6, 0x50, 0x7e, 0x6f, 0x5d, 0x0f, 0x28, 0x6d, 0x38, 0xa3, 0x82, 0x1e, 0xb9, 0x8c};
    int h = 1;
    Crypto_DataBlob pData = {.data = p, .len = sizeof(p)};
    Crypto_DataBlob aData = {.data = a, .len = sizeof(a)};
    Crypto_DataBlob bData = {.data = b, .len = sizeof(b)};
    Crypto_DataBlob gxData = {.data = gx, .len = sizeof(gx)};
    Crypto_DataBlob gyData = {.data = gy, .len = sizeof(gy)};
    Crypto_DataBlob nData = {.data = n, .len = sizeof(n)};
    Crypto_DataBlob hData = {.data = (uint8_t *)(&h), .len = sizeof(int)};

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

1. 调用[OH_CryptoAsymKeySpec_Create](../../reference/apis-crypto-architecture-kit/_crypto_asym_key_api.md#oh_cryptoasymkeyspec_create)，指定算法名为"SM2"， 密钥参数类型为CRYPTO_ASYM_KEY_KEY_PAIR_SPEC，创建密钥参数对象（keySpec）。

2. 调用[OH_CryptoAsymKeySpec_GenEcCommonParamsSpec](../../reference/apis-crypto-architecture-kit/_crypto_asym_key_api.md#oh_cryptoasymkeyspec_geneccommonparamsspec)，指定曲线为"NID_sm2"， 生成SM2公共参数对象（sm2CommonSpec）。

3. 调用[OH_CryptoAsymKeySpec_SetCommonParamsSpec](../../reference/apis-crypto-architecture-kit/_crypto_asym_key_api.md#oh_cryptoasymkeyspec_setcommonparamsspec)，将生成SM2公共参数对象（sm2CommonSpec）设置到密钥参数对象（keySpec）。

4. 指定uint8_t类型的SM2密钥对数据(pkx、pky、sk)，分别封装成[Crypto_DataBlob](../../reference/apis-crypto-architecture-kit/_crypto_common_api.md#crypto_datablob)。

5. 调用[OH_CryptoAsymKeySpec_SetParam](../../reference/apis-crypto-architecture-kit/_crypto_asym_key_api.md#oh_cryptoasymkeyspec_setparam)CRYPTO_ECC_PK_X_DATABLOB(pkx)、CRYPTO_ECC_PK_Y_DATABLOB(pky)、CRYPTO_ECC_SK_DATABLOB(sk), 依次传入封装后的[Crypto_DataBlob](../../reference/apis-crypto-architecture-kit/_crypto_common_api.md#crypto_datablob)，设置到参数对象（keySpec）。

6. 调用[OH_CryptoAsymKeyGeneratorWithSpec_Create](../../reference/apis-crypto-architecture-kit/_crypto_asym_key_api.md#oh_cryptoasymkeygeneratorwithspec_create)，将参数对象（keySpec）传入，创建非对称密钥生成器（generatorSpec）。

7. 调用[OH_CryptoAsymKeyGeneratorWithSpec_GenKeyPair](../../reference/apis-crypto-architecture-kit/_crypto_asym_key_api.md#oh_cryptoasymkeygeneratorwithspec_genkeypair)，生成SM2密钥对（keyPair）。

8. 分别传入密钥对中的私钥和公钥，调用[OH_CryptoPrivKey_GetParam](../../reference/apis-crypto-architecture-kit/_crypto_asym_key_api.md#oh_cryptoprivkey_getparam)和[OH_CryptoPubKey_GetParam](../../reference/apis-crypto-architecture-kit/_crypto_asym_key_api.md#oh_cryptopubkey_getparam)，获取SM2算法中私钥和公钥的各种密钥参数。

```C++
#include "CryptoArchitectureKit/crypto_architecture_kit.h"

static OH_Crypto_ErrCode doTestSm2GenKeyPairBySpec()
{
    uint8_t pkX[] = {0xe3, 0x51, 0xb2, 0xe8, 0xb9, 0x38, 0xeb, 0xb0, 0xa5, 0xe9, 0x6f, 0x98, 0x20, 0x40, 0x6f, 0x67,
                     0x7d, 0x10, 0x46, 0xe7, 0xfd, 0x8d, 0x3b, 0xd8, 0x21, 0xb9, 0xc7, 0xc5, 0x83, 0x15, 0xcb, 0xa9};
    uint8_t pkY[] = {0xcd, 0x9d, 0xf9, 0x60, 0xcd, 0x3e, 0x9a, 0xc8, 0x5a, 0x4c, 0x6f, 0xd4, 0x09, 0xfd, 0x30, 0x0c,
                     0x6a, 0xf4, 0x2a, 0x58, 0x57, 0x31, 0x00, 0xe5, 0xf6, 0x2e, 0x4c, 0x8c, 0xf9, 0xee, 0xed, 0xfa};
    uint8_t sk[] = {0xd9, 0x62, 0x1d, 0x04, 0xdb, 0xcf, 0x74, 0xb6, 0x12, 0xcf, 0x49, 0x0b, 0x79, 0x5f, 0xbf, 0xe0,
                    0x3c, 0xe9, 0x99, 0x14, 0x8a, 0xd6, 0xde, 0x78, 0xf4, 0xbc, 0xc2, 0xc5, 0xe5, 0x8f, 0xbf, 0x5a};

    Crypto_DataBlob pkXData = {.data = pkX, .len = sizeof(pkX)};
    Crypto_DataBlob pkYData = {.data = pkY, .len = sizeof(pkY)};
    Crypto_DataBlob skData = {.data = sk, .len = sizeof(sk)};

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