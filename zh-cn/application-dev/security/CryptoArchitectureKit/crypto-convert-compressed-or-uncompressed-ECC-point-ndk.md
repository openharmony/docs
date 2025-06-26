# 使用ECC压缩/非压缩点格式转换(C/C++)

支持将压缩/非压缩的点数据，转换为Point对象，用于密钥对象生成；也支持将Point对象转换为压缩/非压缩的点数据。<br>
ECC的算法规格请查看[非对称密钥生成和转换规格：ECC](crypto-asym-key-generation-conversion-spec.md#ecc)。<br>
通过传入字符串参数format，可指定获取的点数据格式。如果获取压缩格式，则指定format为："COMPRESSED"；获取非压缩格式，则指定format为："UNCOMPRESSED"。

## 指定非压缩点数据转换为压缩点数据

1. 指定uint8_t类型的ECC非压缩点数据，调用[OH_CryptoEcPoint_Create](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptoecpoint_create)，构造[OH_CryptoEcPoint](../../reference/apis-crypto-architecture-kit/capi-oh-cryptoecpoint.md)对象，用于生成点数据。
2. 调用[OH_CryptoEcPoint_Encode](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptoecpoint_encode)，获取压缩点数据。

```C++
#include "CryptoArchitectureKit/crypto_architecture_kit.h"

static OH_Crypto_ErrCode doTestEccPointUncompressedToCompressed()
{
    uint8_t pk[] = {
        4, 143, 39, 57, 249, 145, 50, 63, 222, 35, 70, 178, 121, 202, 154, 21, 146, 129, 75, 76, 63, 8, 195, 157, 111,
        40, 217, 215, 148, 120, 224, 205, 82, 83, 92, 185, 21, 211, 184, 5, 19, 114, 33, 86, 85, 228, 123, 242, 206,
        200, 98, 178, 184, 130, 35, 232, 45, 5, 202, 189, 11, 46, 163, 156, 152
    };
    Crypto_DataBlob pkData = {pk, sizeof(pk)};
    OH_CryptoEcPoint *point = nullptr;
    OH_Crypto_ErrCode ret = OH_CryptoEcPoint_Create("NID_brainpoolP256r1", &pkData, &point);
    if (ret != CRYPTO_SUCCESS) {
        return ret;
    }
    Crypto_DataBlob returnPointBlobData = {0};
    ret = OH_CryptoEcPoint_Encode(point, "COMPRESSED", &returnPointBlobData);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoEcPoint_Destroy(point);
        return ret;
    }
    OH_Crypto_FreeDataBlob(&returnPointBlobData);
    OH_CryptoEcPoint_Destroy(point);
    return ret;
}
```

## 指定压缩点数据获取密钥对象

1. 指定uint8_t类型的ECC压缩点数据，调用[OH_CryptoEcPoint_Create](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptoecpoint_create)，构造[OH_CryptoEcPoint](../../reference/apis-crypto-architecture-kit/capi-oh-cryptoecpoint.md)对象，用于生成点数据。
2. 调用[OH_CryptoEcPoint_Encode](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptoecpoint_encode)，获取非压缩点数据。

```C++
#include "CryptoArchitectureKit/crypto_architecture_kit.h"

static OH_Crypto_ErrCode doTestEccPointeccPointCompressedToPoint()
{
    uint8_t pk[] = {
        2, 143, 39, 57, 249, 145, 50, 63, 222, 35, 70, 178, 121, 202, 154, 21, 146, 129, 75, 76, 63, 8, 195, 157, 111,
        40, 217, 215, 148, 120, 224, 205, 82
    };
    Crypto_DataBlob pkData = {pk, sizeof(pk)};
    OH_CryptoEcPoint *point = nullptr;
    OH_Crypto_ErrCode ret = OH_CryptoEcPoint_Create("NID_brainpoolP256r1", &pkData, &point);
    if (ret != CRYPTO_SUCCESS) {
        return ret;
    }
    Crypto_DataBlob returnPointBlobData = {0};
    ret = OH_CryptoEcPoint_Encode(point, "UNCOMPRESSED", &returnPointBlobData);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoEcPoint_Destroy(point);
        return ret;
    }
    OH_Crypto_FreeDataBlob(&returnPointBlobData);
    OH_CryptoEcPoint_Destroy(point);
    return ret;
}
```