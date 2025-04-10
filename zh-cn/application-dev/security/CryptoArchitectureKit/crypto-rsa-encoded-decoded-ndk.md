# RSA支持私钥的编码解码(C/C++)

**编码**

1. 调用[OH_CryptoAsymKeyGenerator_Create](../../reference/apis-crypto-architecture-kit/_crypto_asym_key_api.md#oh_cryptoasymkeygenerator_create)、[OH_CryptoAsymKeyGenerator_Generate](../../reference/apis-crypto-architecture-kit/_crypto_asym_key_api.md#oh_cryptoasymkeygenerator_generate)，生成RSA密钥类型为RSA2048、素数个数为2的非对称密钥对（keyPair）。keyPair对象中包括公钥PubKey、私钥PriKey。

   如何生成RSA非对称密钥对，开发者可参考下文示例，并结合[非对称密钥生成和转换规格：RSA](crypto-asym-key-generation-conversion-spec.md#rsa)和[随机生成非对称密钥对(C/C++)](crypto-generate-asym-key-pair-randomly-ndk.md)理解，参考文档与当前示例可能存在入参差异，请在阅读时注意区分。

2. 调用[OH_CryptoPrivKeyEncodingParams_Create](../../reference/apis-crypto-architecture-kit/_crypto_asym_key_api.md#oh_cryptoprivkeyencodingparams_create)创建参数对象（params），并通过[OH_CryptoPrivKeyEncodingParams_SetParam](../../reference/apis-crypto-architecture-kit/_crypto_asym_key_api.md#oh_cryptoprivkeyencodingparams_setparam)设置加密算法和密码。

3. 调用[OH_CryptoPrivKey_Encode](../../reference/apis-crypto-architecture-kit/_crypto_asym_key_api.md#oh_cryptoprivkey_encode)，传入参数CRYPTO_PEM/CRYPTO_DER、PKCS1/PCKS8和参数对象（params）生成编码后的私钥字符串。

**解码**

1. 调用[OH_CryptoAsymKeyGenerator_Create](../../reference/apis-crypto-architecture-kit/_crypto_asym_key_api.md#oh_cryptoasymkeygenerator_create)生成RSA非对称密钥生成器keyGen。

   如何生成RSA非对称密钥对，开发者可参考下文示例，并结合[非对称密钥生成和转换规格：RSA](crypto-asym-key-generation-conversion-spec.md#rsa)。

   **注意：**
   解码应该与编码传入的算法一致。
   不支持解码经过加密的私钥

- 编码示例：
```C++
#include "CryptoArchitectureKit/crypto_architecture_kit.h"

static OH_Crypto_ErrCode doTestPriKeyPkcs1Encoded()
{
    OH_CryptoAsymKeyGenerator *keyGen = nullptr;
    OH_Crypto_ErrCode ret = OH_CryptoAsymKeyGenerator_Create("RSA2048", &keyGen);
    if (ret != CRYPTO_SUCCESS) {
        return ret;
    }
    OH_CryptoKeyPair *keyPair = nullptr;
    ret = OH_CryptoAsymKeyGenerator_Generate(keyGen, &keyPair);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoAsymKeyGenerator_Destroy(keyGen);
        return ret;
    }

    OH_CryptoPrivKey *privKey = OH_CryptoKeyPair_GetPrivKey(keyPair);
    if (privKey == nullptr) {
        OH_CryptoKeyPair_Destroy(keyPair);
        OH_CryptoAsymKeyGenerator_Destroy(keyGen);
        return CRYPTO_OPERTION_ERROR;
    }
    OH_CryptoPrivKeyEncodingParams *params = nullptr;
    ret = OH_CryptoPrivKeyEncodingParams_Create(&params);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoKeyPair_Destroy(keyPair);
        OH_CryptoAsymKeyGenerator_Destroy(keyGen);
        return ret;
    }

    Crypto_DataBlob password = {(uint8_t *)"1234567890", 10};
    Crypto_DataBlob cipher = {(uint8_t *)"AES-128-CBC", 11};
    ret = OH_CryptoPrivKeyEncodingParams_SetParam(params, CRYPTO_PRIVATE_KEY_ENCODING_PASSWORD_STR, &password);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoPrivKeyEncodingParams_Destroy(params);
        OH_CryptoKeyPair_Destroy(keyPair);
        OH_CryptoAsymKeyGenerator_Destroy(keyGen);
        return ret;
    }
    ret = OH_CryptoPrivKeyEncodingParams_SetParam(params, CRYPTO_PRIVATE_KEY_ENCODING_SYMMETRIC_CIPHER_STR, &cipher);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoPrivKeyEncodingParams_Destroy(params);
        OH_CryptoKeyPair_Destroy(keyPair);
        OH_CryptoAsymKeyGenerator_Destroy(keyGen);
        return ret;
    }

    Crypto_DataBlob pemData = {0};
    ret = OH_CryptoPrivKey_Encode(privKey, CRYPTO_PEM, "PKCS1", params, &pemData);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoPrivKeyEncodingParams_Destroy(params);
        OH_CryptoKeyPair_Destroy(keyPair);
        OH_CryptoAsymKeyGenerator_Destroy(keyGen);
        return ret;
    }
    OH_Crypto_FreeDataBlob(&pemData);
    OH_CryptoPrivKeyEncodingParams_Destroy(params);
    OH_CryptoKeyPair_Destroy(keyPair);
    OH_CryptoAsymKeyGenerator_Destroy(keyGen);
    return ret;
}
```

- 解码示例：
```C++
#include "CryptoArchitectureKit/crypto_architecture_kit.h"
#include <string>

static OH_Crypto_ErrCode doTestConvertPemKeyByPromise()
{
    std::string priKeyPkcs1EncodingStr = "-----BEGIN RSA PRIVATE KEY-----\n"
                                         "MIIEpAIBAAKCAQEAs8sxjnUvQBQxUywaBDbBSzhJS97Lmg5gkbtwQWsGKMd6/2oC\n"
                                         "izOgI37sng7Xq98yWduivlwYVIhPc/pnBXjzQXiGgyz3FjimiG0pxv1rWLyjG6gA\n"
                                         "ex+6gmHzEkxnVPGbH420rI/4bp+Kiz1hQsSiS3qOCztj9NWIOS+eXpT7lRadlDtn\n"
                                         "uE39WXbve7qZDSp9MGLWc4upE5BrLMH4pcqFOL5nGuEvbtD4N3AGKmogmm3U8/Gg\n"
                                         "YLJ6l8a7+a2EFveGISJNlTR8z7KBWPF/z7vfQzMwrD5Ze8MQEb9skY/tIxHuerFb\n"
                                         "G0NvUeh3B7I8Hxa/gIYNlsvU9KocaqO18Mr/RwIDAQABAoIBADW2f6Cam7oeDjpV\n"
                                         "05Pss8SAFU2oStVEdE81Wy0AB0AJkFJb3lSt4KqaEaCKuJ3tOUKlHjKWmuIuMuZo\n"
                                         "KXz2DF5D3pOzzEGEPSRG0JNVREunV2c8wqAF85deIdsWnkw/PeOoVxCyljqeSSqd\n"
                                         "9L+YtQ+tll/+pzcOz/qdokeJZLu+G/fdO7vDf0+8u/lt/JBfBN34NUR10jMcpb/H\n"
                                         "qtxtX+aD2V1JUati+kJTdQBv6+1hV1M26RveS4LdByzl9lrP1fZjFg1NvhWBb7HR\n"
                                         "5zJM4SgNCOMVCi+Mcx9PDWC80t8+XnmICRUXOkni99qYCBU5w+2Iajh8If93LluY\n"
                                         "1TCpJHECgYEA7wITkc6MzYAbfrrKVnalk/3iJdSJIjbGO5wtDYZPXLuL14YVNLCX\n"
                                         "HJ2rzLNbAm7hRlGrudq7wlnKy1yjvsp2K3ueXGWJ5goPHMKPs4646v26gYpm1JI2\n"
                                         "fQEjzgy8Y/spEeI2WozE1D/a/6FUhzt0t5apx2muHr5uE0464BFebp8CgYEAwJNr\n"
                                         "2FuzyKf/Yamm69RAuHCb7CuKlD1Cx86k92mWo1USqKu8IgMIUgTh7VeqmpBeYRlB\n"
                                         "LRSEirLyuKpcKuIfaRQk8d/ELA/SAOYD9OpPBRmgrpuPZ+CpqHjhbpZ5qWYG4tjN\n"
                                         "0Au8+Drlck5mkBDjZ7LjPxc8kCEC1XDIEK2/NlkCgYEAlmJkFdY02gjFRBQbxBOb\n"
                                         "U2bnqI32S0TTriYyYtQjk2GeN9nx9dk2+5Zpxr8DgKBrtmck+igbA8qjwxljHmUd\n"
                                         "vXZmyhRJlCi4IYx6BqzCxXkopOGEmjP1fOn+sWNqFi6uRMZlFMyF/FbBYR8NpJlQ\n"
                                         "c0OlSAfCuy1u7U7H1LyZAlkCgYA3eYBEqE4HDJYdzSBfqRonx5CzHOvjvi4Bnv6Y\n"
                                         "oxsY3AXu/uHILnV0IyHuHCXyNoppkDvdP57a0afoGHNKiy8fNwVZg+tgAgKt7ZTQ\n"
                                         "NbsjrflCs19BPk/BT2kpUUGk0dZD/M51ExyRqW21Wu5iq+rGUZry7r+siUXmtIF9\n"
                                         "hH+jqQKBgQDY7w9+bBD3/6e7IESEOL4PluB2UXzbiGswOjGk76W2p68cUGsgogPk\n"
                                         "LDemIt/pFqouyPMgs8djKWfIMDQxhctsdxJ5nwdiciaHRAmbTI4Nmau6i3Rc3z78\n"
                                         "7eH0fQCVHJIdVjNu4v18dbsMG/sL9cs5XY8XJEdmGRx0WamZzfJaHA==\n"
                                         "-----END RSA PRIVATE KEY-----\n";

    OH_CryptoAsymKeyGenerator *keyGen = nullptr;
    OH_Crypto_ErrCode ret = OH_CryptoAsymKeyGenerator_Create("RSA2048", &keyGen);
    if (ret != CRYPTO_SUCCESS) {
        return ret;
    }

    OH_CryptoKeyPair *dupKeyPair = nullptr;
    Crypto_DataBlob priKeyPkcs1EncodingData = {};
    priKeyPkcs1EncodingData.data = reinterpret_cast<uint8_t *>(const_cast<char *>(priKeyPkcs1EncodingStr.c_str()));
    priKeyPkcs1EncodingData.len = strlen(priKeyPkcs1EncodingStr.c_str());
    ret = OH_CryptoAsymKeyGenerator_Convert(keyGen, CRYPTO_PEM, nullptr, &priKeyPkcs1EncodingData, &dupKeyPair);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoAsymKeyGenerator_Destroy(keyGen);
        return ret;
    }
    OH_CryptoKeyPair_Destroy(dupKeyPair);
    OH_CryptoAsymKeyGenerator_Destroy(keyGen);
    return ret;
}
```