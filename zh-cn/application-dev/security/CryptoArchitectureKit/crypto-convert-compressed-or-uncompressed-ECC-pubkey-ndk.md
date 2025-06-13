# 使用ECC压缩/非压缩公钥格式转换(C/C++)

可通过指定ECC公钥数据生成公钥对象（[PubKey](../../reference/apis-crypto-architecture-kit/capi-oh-cryptopubkey.md)），也可从公钥对象中获取ECC公钥数据。
当前仅支持满足X509规范的ECC算法的压缩或非压缩格式的完整公钥数据。此处的公钥数据应当是完整的X509公钥，对于仅使用点数据的情况，请参考[使用ECC压缩/非压缩点格式转换](crypto-convert-compressed-or-uncompressed-ECC-point.md)。    
查看[非对称密钥生成和转换规格：ECC](crypto-asym-key-generation-conversion-spec.md#ecc)。  
通过传入字符串参数，可指定需要获取的ECC公钥数据格式。如果需要获取满足X509规范的压缩格式数据，则指定参数为："X509|COMPRESSED"；需要获取非压缩格式，则指定参数为："X509|UNCOMPRESSED"。

##  指定非压缩公钥数据转换为压缩公钥数据

1. 指定uint8_t类型的ECC非压缩公钥数据，封装成[Crypto_DataBlob](../../reference/apis-crypto-architecture-kit/capi-crypto-datablob.md)。  
公钥和私钥可单独传入，此处示例传入非压缩公钥。
2. 调用[OH_CryptoAsymKeyGenerator_Create](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptoasymkeygenerator_generate)，指定字符串参数'ECC_BrainPoolP256r1'，创建密钥算法为ECC、密钥长度为256位的非对称密钥生成器（OH_CryptoAsymKeyGenerator）。
3. 调用[OH_CryptoAsymKeyGenerator_Convert](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptoasymkeygenerator_convert)，传入封装后的[Crypto_DataBlob](../../reference/apis-crypto-architecture-kit/capi-crypto-datablob.md)，生成非对称密钥对象（OH_CryptoKeyPair）。
4. 调用[OH_CryptoPubKey_Encode](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptopubkey_encode)，设置参数为'X509|COMPRESSED'，获取压缩公钥数据的字节流。

```c++
#include "CryptoArchitectureKit/crypto_common.h"
#include "CryptoArchitectureKit/crypto_asym_key.h"

static OH_Crypto_ErrCode doTestEccDataCovert()
{
    OH_CryptoAsymKeyGenerator *generator = nullptr;
    OH_CryptoKeyPair *keyPair = nullptr;
    Crypto_DataBlob returnBlob = { .data = nullptr, .len = 0 };
    OH_Crypto_ErrCode ret = CRYPTO_INVALID_PARAMS;

    ret = OH_CryptoAsymKeyGenerator_Create("ECC_BrainPoolP256r1", &generator);
    if (ret != CRYPTO_SUCCESS) {
        return ret;
    }
    uint8_t pubKeyBlobData[] = {
        48, 90, 48, 20, 6, 7, 42, 134, 72, 206, 61, 2, 1, 6, 9, 43, 36, 3, 3, 2,
        8, 1, 1, 7, 3, 66, 0, 4, 143, 39, 57, 249, 145, 50, 63, 222, 35, 70, 178, 
        121, 202, 154, 21, 146, 129, 75, 76, 63, 8, 195, 157, 111, 40, 217, 215,
        148, 120, 224, 205, 82, 83, 92, 185, 21, 211, 184, 5, 19, 114, 33, 86, 85,
        228,123, 242, 206, 200, 98, 178, 184, 130, 35, 232, 45, 5, 202, 189, 11, 
        46, 163, 156, 152
    };
    Crypto_DataBlob pubKeyUncompressedBlob = {
        .data = pubKeyBlobData,
        .len = sizeof(pubKeyBlobData),
    };
    ret = OH_CryptoAsymKeyGenerator_Convert(generator, CRYPTO_DER, &pubKeyUncompressedBlob, nullptr, &keyPair);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoAsymKeyGenerator_Destroy(generator);
        return ret;
    }

    OH_CryptoPubKey *pubKey = OH_CryptoKeyPair_GetPubKey(keyPair);
    ret = OH_CryptoPubKey_Encode(pubKey, CRYPTO_DER, "X509|COMPRESSED", &returnBlob);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoAsymKeyGenerator_Destroy(generator);
        OH_CryptoKeyPair_Destroy(keyPair);
        return ret;
    }
    OH_CryptoAsymKeyGenerator_Destroy(generator);
    OH_CryptoKeyPair_Destroy(keyPair);
    return ret;
}
```
