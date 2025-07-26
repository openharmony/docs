# 使用X25519进行密钥协商(C/C++)

对应的算法规格请查看[密钥协商算法规格：X25519](crypto-key-agreement-overview.md#x25519)。

## 开发步骤

1. 调用[OH_CryptoAsymKeyGenerator_Create](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptoasymkeygenerator_create)、[OH_CryptoAsymKeyGenerator_Generate](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptoasymkeygenerator_generate)、[OH_CryptoAsymKeyGenerator_Convert](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptoasymkeygenerator_convert)生成密钥算法为X25519的非对称密钥（keyPair）。

   如何生成X25519非对称密钥，开发者可参考下文示例，并结合[非对称密钥生成和转换规格：X25519](crypto-asym-key-generation-conversion-spec.md#x25519)和[随机生成非对称密钥对](crypto-generate-asym-key-pair-randomly-ndk.md)理解。参考文档与当前示例可能存在入参差异，请在阅读时注意区分。

2. 调用[OH_CryptoKeyAgreement_Create](../../reference/apis-crypto-architecture-kit/capi-crypto-key-agreement-h.md#oh_cryptokeyagreement_create)，指定字符串参数'X25519'，创建密钥算法为X25519的密钥协议生成器。

3. 调用[OH_CryptoKeyAgreement_GenerateSecret](../../reference/apis-crypto-architecture-kit/capi-crypto-key-agreement-h.md#oh_cryptokeyagreement_generatesecret)，基于传入的私钥（keyPair.priKey）与公钥（keyPair.pubKey）进行密钥协商，返回共享秘钥。

```C++
#include "CryptoArchitectureKit/crypto_architecture_kit.h"
#include "CryptoArchitectureKit/crypto_key_agreement.h"
#include <stdio.h>
#include <cstring>

static OH_Crypto_ErrCode doTestX25519KeyAgreement()
{
    uint8_t pubKeyArray[] = {48, 42, 48, 5, 6, 3, 43, 101, 110, 3, 33, 0, 36, 98, 216, 106, 74, 99, 179, 203, 81, 145,
                             147, 101, 139, 57, 74, 225, 119, 196, 207, 0, 50, 232, 93, 147, 188, 21, 225, 228, 54, 251,
                             230, 52};
    uint8_t priKeyArray[] = {48, 46, 2, 1, 0, 48, 5, 6, 3, 43, 101, 110, 4, 34, 4, 32, 112, 65, 156, 73, 65, 89, 183,
                             39, 119, 229, 110, 12, 192, 237, 186, 153, 21, 122, 28, 176, 248, 108, 22, 242, 239, 179,
                             106, 175, 85, 65, 214, 90};
    // 创建X25519密钥生成器。
    OH_CryptoAsymKeyGenerator *x25519Gen = nullptr;
    OH_Crypto_ErrCode ret = OH_CryptoAsymKeyGenerator_Create("X25519", &x25519Gen);
    if (ret != CRYPTO_SUCCESS) {
        return ret;
    }

    // 外部传入的公私钥对A。
    Crypto_DataBlob pubKeyBlob = {pubKeyArray, sizeof(pubKeyArray)};
    Crypto_DataBlob priKeyBlob = {priKeyArray, sizeof(priKeyArray)};
    OH_CryptoKeyPair *keyPairA = nullptr;
    ret = OH_CryptoAsymKeyGenerator_Convert(x25519Gen, CRYPTO_DER, &pubKeyBlob, &priKeyBlob, &keyPairA);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoAsymKeyGenerator_Destroy(x25519Gen);
        return ret;
    }

    // 内部生成的公私钥对B。
    OH_CryptoKeyPair *keyPairB = nullptr;
    ret = OH_CryptoAsymKeyGenerator_Generate(x25519Gen, &keyPairB);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoKeyPair_Destroy(keyPairA);
        OH_CryptoAsymKeyGenerator_Destroy(x25519Gen);
        return ret;
    }

    // 创建密钥协议生成器。
    OH_CryptoKeyAgreement *x25519KeyAgreement = nullptr;
    ret = OH_CryptoKeyAgreement_Create("X25519", &x25519KeyAgreement);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoKeyPair_Destroy(keyPairA);
        OH_CryptoKeyPair_Destroy(keyPairB);
        OH_CryptoAsymKeyGenerator_Destroy(x25519Gen);
        return ret;
    }

    // 使用A的公钥和B的私钥进行密钥协商。
    OH_CryptoPrivKey *privKeyB = OH_CryptoKeyPair_GetPrivKey(keyPairB);
    OH_CryptoPubKey *pubKeyA = OH_CryptoKeyPair_GetPubKey(keyPairA);
    Crypto_DataBlob secret1 = {0};
    ret = OH_CryptoKeyAgreement_GenerateSecret(x25519KeyAgreement, privKeyB, pubKeyA, &secret1);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoKeyAgreement_Destroy(x25519KeyAgreement);
        OH_CryptoKeyPair_Destroy(keyPairA);
        OH_CryptoKeyPair_Destroy(keyPairB);
        OH_CryptoAsymKeyGenerator_Destroy(x25519Gen);
        return ret;
    }

    // 使用A的私钥和B的公钥进行密钥协商。
    OH_CryptoPrivKey *privKeyA = OH_CryptoKeyPair_GetPrivKey(keyPairA);
    OH_CryptoPubKey *pubKeyB = OH_CryptoKeyPair_GetPubKey(keyPairB);
    Crypto_DataBlob secret2 = {0};
    ret = OH_CryptoKeyAgreement_GenerateSecret(x25519KeyAgreement, privKeyA, pubKeyB, &secret2);
    if (ret != CRYPTO_SUCCESS) {
        OH_Crypto_FreeDataBlob(&secret1);
        OH_CryptoKeyAgreement_Destroy(x25519KeyAgreement);
        OH_CryptoKeyPair_Destroy(keyPairA);
        OH_CryptoKeyPair_Destroy(keyPairB);
        OH_CryptoAsymKeyGenerator_Destroy(x25519Gen);
        return ret;
    }

    // 比较两次协商的结果。
    if ((secret1.len == secret2.len) && (memcmp(secret1.data, secret2.data, secret1.len) == 0)) {
        printf("x25519 success\n");
    } else {
        printf("x25519 result is not equal\n");
        ret = CRYPTO_OPERTION_ERROR;
    }

    // 清理资源。
    OH_Crypto_FreeDataBlob(&secret1);
    OH_Crypto_FreeDataBlob(&secret2);
    OH_CryptoKeyAgreement_Destroy(x25519KeyAgreement);
    OH_CryptoKeyPair_Destroy(keyPairA);
    OH_CryptoKeyPair_Destroy(keyPairB);
    OH_CryptoAsymKeyGenerator_Destroy(x25519Gen);
    return ret;
}
```
