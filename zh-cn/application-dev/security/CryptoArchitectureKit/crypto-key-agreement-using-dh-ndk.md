# 使用DH进行密钥协商(C/C++)

<!--Kit: Crypto Architecture Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--Designer: @lanming-->
<!--Tester: @PAFT-->
<!--Adviser: @zengyawen-->

对应的算法规格请查看[密钥协商算法规格：DH](crypto-key-agreement-overview.md#dh)。

## 开发步骤

1. 调用[OH_CryptoAsymKeyGenerator_Create](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptoasymkeygenerator_create)、[OH_CryptoAsymKeyGenerator_Generate](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptoasymkeygenerator_generate)生成密钥算法为DH_modp1536的非对称密钥（keyPair）。

   如何生成DH非对称密钥，开发者可参考下文示例，并结合[非对称密钥生成和转换规格：DH](crypto-asym-key-generation-conversion-spec.md#dh)和[随机生成非对称密钥对](crypto-generate-asym-key-pair-randomly-ndk.md)理解。参考文档与当前示例可能存在入参差异，请在阅读时注意区分。

2. 调用[OH_CryptoKeyAgreement_Create](../../reference/apis-crypto-architecture-kit/capi-crypto-key-agreement-h.md#oh_cryptokeyagreement_create)，指定字符串参数'DH_modp1536'，创建密钥算法为DH_modp1536的密钥协议生成器。

3. 调用[OH_CryptoKeyAgreement_GenerateSecret](../../reference/apis-crypto-architecture-kit/capi-crypto-key-agreement-h.md#oh_cryptokeyagreement_generatesecret)，基于传入的私钥（keyPair.priKey）与公钥（keyPair.pubKey）进行密钥协商，返回共享秘钥。

```C++
#include "CryptoArchitectureKit/crypto_architecture_kit.h"
#include "CryptoArchitectureKit/crypto_key_agreement.h"
#include <stdio.h>
#include <cstring>

static OH_Crypto_ErrCode doTestDHKeyAgreement()
{
    // 创建DH密钥生成器。
    OH_CryptoAsymKeyGenerator *dhGen = nullptr;
    OH_Crypto_ErrCode ret = OH_CryptoAsymKeyGenerator_Create("DH_modp1536", &dhGen);
    if (ret != CRYPTO_SUCCESS) {
        return ret;
    }

    // 生成公私钥对A。
    OH_CryptoKeyPair *keyPairA = nullptr;
    ret = OH_CryptoAsymKeyGenerator_Generate(dhGen, &keyPairA);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoAsymKeyGenerator_Destroy(dhGen);
        return ret;
    }

    // 生成公私钥对B。
    OH_CryptoKeyPair *keyPairB = nullptr;
    ret = OH_CryptoAsymKeyGenerator_Generate(dhGen, &keyPairB);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoKeyPair_Destroy(keyPairA);
        OH_CryptoAsymKeyGenerator_Destroy(dhGen);
        return ret;
    }

    // 创建密钥协议生成器。
    OH_CryptoKeyAgreement *dhKeyAgreement = nullptr;
    ret = OH_CryptoKeyAgreement_Create("DH_modp1536", &dhKeyAgreement);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoKeyPair_Destroy(keyPairA);
        OH_CryptoKeyPair_Destroy(keyPairB);
        OH_CryptoAsymKeyGenerator_Destroy(dhGen);
        return ret;
    }

    // 使用A的公钥和B的私钥进行密钥协商。
    OH_CryptoPrivKey *privKeyB = OH_CryptoKeyPair_GetPrivKey(keyPairB);
    OH_CryptoPubKey *pubKeyA = OH_CryptoKeyPair_GetPubKey(keyPairA);
    Crypto_DataBlob secret1 = { 0 };
    ret = OH_CryptoKeyAgreement_GenerateSecret(dhKeyAgreement, privKeyB, pubKeyA, &secret1);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoKeyAgreement_Destroy(dhKeyAgreement);
        OH_CryptoKeyPair_Destroy(keyPairA);
        OH_CryptoKeyPair_Destroy(keyPairB);
        OH_CryptoAsymKeyGenerator_Destroy(dhGen);
        return ret;
    }

    // 使用B的公钥和A的私钥进行密钥协商。
    OH_CryptoPrivKey *privKeyA = OH_CryptoKeyPair_GetPrivKey(keyPairA);
    OH_CryptoPubKey *pubKeyB = OH_CryptoKeyPair_GetPubKey(keyPairB);
    Crypto_DataBlob secret2 = { 0 };
    ret = OH_CryptoKeyAgreement_GenerateSecret(dhKeyAgreement, privKeyA, pubKeyB, &secret2);
    if (ret != CRYPTO_SUCCESS) {
        OH_Crypto_FreeDataBlob(&secret1);
        OH_CryptoKeyAgreement_Destroy(dhKeyAgreement);
        OH_CryptoKeyPair_Destroy(keyPairA);
        OH_CryptoKeyPair_Destroy(keyPairB);
        OH_CryptoAsymKeyGenerator_Destroy(dhGen);
        return ret;
    }

    // 比较两次协商的结果。
    if ((secret1.len == secret2.len) &&
        (memcmp(secret1.data, secret2.data, secret1.len) == 0)) {
        printf("dh success\n");
    } else {
        printf("dh result is not equal\n");
        ret = CRYPTO_OPERTION_ERROR;
    }

    // 清理资源。
    OH_Crypto_FreeDataBlob(&secret1);
    OH_Crypto_FreeDataBlob(&secret2);
    OH_CryptoKeyAgreement_Destroy(dhKeyAgreement);
    OH_CryptoKeyPair_Destroy(keyPairA);
    OH_CryptoKeyPair_Destroy(keyPairB);
    OH_CryptoAsymKeyGenerator_Destroy(dhGen);
    return ret;
}
```
