# 使用ECDH进行密钥协商(C/C++)

<!--Kit: Crypto Architecture Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--Designer: @lanming-->
<!--Tester: @PAFT-->
<!--Adviser: @zengyawen-->

对应的算法规格请查看[密钥协商算法规格：ECDH](crypto-key-agreement-overview.md#ecdh)。

## 开发步骤

1. 调用[OH_CryptoAsymKeyGenerator_Create](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptoasymkeygenerator_create)、[OH_CryptoAsymKeyGenerator_Generate](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptoasymkeygenerator_generate)、[OH_CryptoAsymKeyGenerator_Convert](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptoasymkeygenerator_convert)生成密钥算法为ECC、密钥长度为256位的非对称密钥（keyPair）。

   如何生成ECC非对称密钥，开发者可参考下文示例，并结合[非对称密钥生成和转换规格：ECC](crypto-asym-key-generation-conversion-spec.md#ecc)和[随机生成非对称密钥对](crypto-generate-asym-key-pair-randomly-ndk.md)理解。参考文档与当前示例可能存在入参差异，请在阅读时注意区分。

2. 调用[OH_CryptoKeyAgreement_Create](../../reference/apis-crypto-architecture-kit/capi-crypto-key-agreement-h.md#oh_cryptokeyagreement_create)，指定字符串参数'ECC256'，创建密钥算法为ECC、密钥长度为256位的密钥协商生成器。

3. 调用[OH_CryptoKeyAgreement_GenerateSecret](../../reference/apis-crypto-architecture-kit/capi-crypto-key-agreement-h.md#oh_cryptokeyagreement_generatesecret)，基于传入的私钥（keyPair.priKey）与公钥（keyPair.pubKey）进行密钥协商，返回共享密钥。

<!-- @[TestEcdh](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Security/CryptoArchitectureKit/KeyNegotiationCpp/entry/src/main/cpp/types/project/ECDH.cpp) -->

``` C++

#include "CryptoArchitectureKit/crypto_architecture_kit.h"
#include "CryptoArchitectureKit/crypto_key_agreement.h"
#include "file.h"
#include <cstdio>
#include <cstring>

static OH_Crypto_ErrCode GenerateSecret(OH_CryptoKeyAgreement *eccKeyAgreement, OH_CryptoKeyPair *keyPairA,
    OH_CryptoKeyPair *keyPairB, Crypto_DataBlob *secret)
{
    OH_CryptoPrivKey *privKey = OH_CryptoKeyPair_GetPrivKey(keyPairA);
    OH_CryptoPubKey *pubKey = OH_CryptoKeyPair_GetPubKey(keyPairB);
    return OH_CryptoKeyAgreement_GenerateSecret(eccKeyAgreement, privKey, pubKey, secret);
}

static OH_Crypto_ErrCode compareSecrets(const Crypto_DataBlob *secret1, const Crypto_DataBlob *secret2)
{
    if ((secret1->len == secret2->len) &&
        (memcmp(secret1->data, secret2->data, secret1->len) == 0)) {
        return CRYPTO_SUCCESS;
    }
    return CRYPTO_OPERTION_ERROR;
}

static OH_Crypto_ErrCode ConvertKeyPairByBlob(OH_CryptoAsymKeyGenerator *eccGen, OH_CryptoKeyPair **keyPair)
{
    uint8_t pubKeyArray[] = {48, 89, 48, 19, 6, 7, 42, 134, 72, 206, 61, 2, 1, 6, 8, 42, 134, 72, 206, 61, 3, 1, 7,
        3, 66, 0, 4, 83, 96, 142, 9, 86, 214, 126, 106, 247, 233, 92, 125, 4, 128, 138, 105, 246,
        162, 215, 71, 81, 58, 202, 121, 26, 105, 211, 55, 130, 45, 236, 143, 55, 16, 248, 75, 167,
        160, 167, 106, 2, 152, 243, 44, 68, 66, 0, 167, 99, 92, 235, 215, 159, 239, 28, 106, 124,
        171, 34, 145, 124, 174, 57, 92};
    uint8_t priKeyArray[] = {48, 49, 2, 1, 1, 4, 32, 115, 56, 137, 35, 207, 0, 60, 191, 90, 61, 136, 105, 210, 16,
        27, 4, 171, 57, 10, 61, 123, 40, 189, 28, 34, 207, 236, 22, 45, 223, 10, 189, 160, 10, 6,
        8, 42, 134, 72, 206, 61, 3, 1, 7};
    Crypto_DataBlob pubKeyBlob = {pubKeyArray, sizeof(pubKeyArray)};
    Crypto_DataBlob priKeyBlob = {priKeyArray, sizeof(priKeyArray)};
    return OH_CryptoAsymKeyGenerator_Convert(eccGen, CRYPTO_DER, &pubKeyBlob, &priKeyBlob, keyPair);
}

OH_Crypto_ErrCode doTestEcdhKeyAgreement()
{
    OH_CryptoAsymKeyGenerator *eccGen = nullptr;
    OH_CryptoKeyPair *keyPairA = nullptr;
    OH_CryptoKeyPair *keyPairB = nullptr;
    OH_CryptoKeyAgreement *eccKeyAgreement = nullptr;
    Crypto_DataBlob secret1 = { 0 };
    Crypto_DataBlob secret2 = { 0 };

    OH_Crypto_ErrCode ret = OH_CryptoAsymKeyGenerator_Create("ECC256", &eccGen);
    if (ret != CRYPTO_SUCCESS) {
        return ret;
    }

    ret = ConvertKeyPairByBlob(eccGen, &keyPairA);
    if (ret != CRYPTO_SUCCESS) {
        goto goto_cleanup;
    }

    ret = OH_CryptoAsymKeyGenerator_Generate(eccGen, &keyPairB);
    if (ret != CRYPTO_SUCCESS) {
        goto goto_cleanup;
    }

    ret = OH_CryptoKeyAgreement_Create("ECC256", &eccKeyAgreement);
    if (ret != CRYPTO_SUCCESS) {
        goto goto_cleanup;
    }

    // 使用A的公钥和B的私钥进行密钥协商。
    ret = GenerateSecret(eccKeyAgreement, keyPairB, keyPairA, &secret1);
    if (ret != CRYPTO_SUCCESS) {
        goto goto_cleanup;
    }

    // 使用A的私钥和B的公钥进行密钥协商。
    ret = GenerateSecret(eccKeyAgreement, keyPairA, keyPairB, &secret2);
    if (ret != CRYPTO_SUCCESS) {
        goto goto_cleanup;
    }

    // 比较两次协商的结果。
    ret = compareSecrets(&secret1, &secret2);
    if (ret != CRYPTO_SUCCESS) {
        printf("ecdh result is not equal\n");
        goto goto_cleanup;
    }

goto_cleanup:
    OH_Crypto_FreeDataBlob(&secret1);
    OH_Crypto_FreeDataBlob(&secret2);
    OH_CryptoKeyAgreement_Destroy(eccKeyAgreement);
    OH_CryptoKeyPair_Destroy(keyPairA);
    OH_CryptoKeyPair_Destroy(keyPairB);
    OH_CryptoAsymKeyGenerator_Destroy(eccGen);
    return ret;
}
```

