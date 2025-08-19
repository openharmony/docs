# SM2签名数据格式转换 (C/C++)

<!--Kit: Crypto Architecture Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--Designer: @lanming-->
<!--Tester: @PAFT-->
<!--Adviser: @zengyawen-->

当前支持DER格式与r、s格式互转的能力。
开发者可指定SM2密文的参数，将其转换成DER格式密文。反之，也可以从DER格式密文中提取出SM2的具体密文参数。

**指定密文参数，转换为DER格式**
1. 调用[OH_CryptoEccSignatureSpec_Create](../../reference/apis-crypto-architecture-kit/capi-crypto-signature-h.md#oh_cryptoeccsignaturespec_create)，创建[OH_CryptoEccSignatureSpec](../../reference/apis-crypto-architecture-kit/capi-cryptosignatureapi-oh-cryptoeccsignaturespec.md)对象，用于设置SM2密文参数。

2. 调用[OH_CryptoEccSignatureSpec_SetRAndS](../../reference/apis-crypto-architecture-kit/capi-crypto-signature-h.md#oh_cryptoeccsignaturespec_setrands)，将R、S设置到OH_CryptoEccSignatureSpec对象中。

3. 调用[OH_CryptoEccSignatureSpec_Encode](../../reference/apis-crypto-architecture-kit/capi-crypto-signature-h.md#oh_cryptoeccsignaturespec_encode)得到转换后的DER格式的密文。

4. 调用[OH_CryptoEccSignatureSpec_Destroy](../../reference/apis-crypto-architecture-kit/capi-crypto-signature-h.md#oh_cryptoeccsignaturespec_destroy)释放对象。

```c++
#include "CryptoArchitectureKit/crypto_common.h"
#include "CryptoArchitectureKit/crypto_asym_key.h"
#include "CryptoArchitectureKit/crypto_signature.h"

static OH_Crypto_ErrCode doTestSm2DataChange()
{
    static unsigned char g_rCoordinate[] = {
        107, 93,  198, 247, 119, 18,  40,  110, 90,  156, 193,
        158, 205, 113, 170, 128, 146, 109, 75,  17,  181, 109,
        110, 91,  149, 5,   110, 233, 209, 78,  229, 96};

    static unsigned char g_sCoordinate[] = {
        45,  153, 88,  82,  104, 221, 226, 43,  174, 21,  122,
        248, 5,   232, 105, 41,  92,  95,  102, 224, 216, 149,
        85,  236, 110, 6,   64,  188, 149, 70,  70,  183};

    // 由R和S生成DER格式的签名数据。
    OH_CryptoEccSignatureSpec *spec = NULL;
    Crypto_DataBlob r = {0};
    Crypto_DataBlob s = {0};
    r.data = g_rCoordinate;
    r.len = sizeof(g_rCoordinate);
    s.data = g_sCoordinate;
    s.len = sizeof(g_sCoordinate);
    OH_Crypto_ErrCode ret = OH_CryptoEccSignatureSpec_Create(NULL, &spec);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoEccSignatureSpec_Destroy(spec);
        return ret;
    }
    ret = OH_CryptoEccSignatureSpec_SetRAndS(spec, &r, &s);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoEccSignatureSpec_Destroy(spec);
        return ret;
    }
    Crypto_DataBlob sig = {0};
    ret = OH_CryptoEccSignatureSpec_Encode(spec, &sig);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoEccSignatureSpec_Destroy(spec);
        return ret;
    }
    OH_Crypto_FreeDataBlob(&sig);
    OH_CryptoEccSignatureSpec_Destroy(spec);
    spec = NULL;
    return CRYPTO_SUCCESS;

}
```

**指定DER格式，转换为r、s格式**

1. 调用[OH_CryptoEccSignatureSpec_Create](../../reference/apis-crypto-architecture-kit/capi-crypto-signature-h.md#oh_cryptoeccsignaturespec_create)传入签名数据，创建[OH_CryptoEccSignatureSpec](../../reference/apis-crypto-architecture-kit/capi-cryptosignatureapi-oh-cryptoeccsignaturespec.md)对象，用于获取转换后的数据。

2. 调用[OH_CryptoEccSignatureSpec_GetRAndS](../../reference/apis-crypto-architecture-kit/capi-crypto-signature-h.md#oh_cryptoeccsignaturespec_getrands)拿到转换后的数据r、s。

3. 调用[OH_CryptoEccSignatureSpec_Destroy](../../reference/apis-crypto-architecture-kit/capi-crypto-signature-h.md#oh_cryptoeccsignaturespec_destroy)释放内存。

```c++
#include "CryptoArchitectureKit/crypto_common.h"
#include "CryptoArchitectureKit/crypto_asym_key.h"
#include "CryptoArchitectureKit/crypto_signature.h"

static OH_Crypto_ErrCode doSm2GetRS() {
    uint8_t signText[] = {
        0x30, 0x45, 0x02, 0x21, 0x00, 0xab, 0xf8, 0xe2, 0x96, 0x7d, 0x5b, 0x28, 0xfb, 0x9a, 0xbd, 0x05, 0xa6,
        0x81, 0xd6, 0xb1, 0x55, 0x69, 0x22, 0x25, 0xd2, 0xa3, 0x5d, 0xa8, 0xc0, 0x96, 0xe0, 0x1d, 0x38, 0x74,
        0xa0, 0xc9, 0x4f, 0x02, 0x20, 0x20, 0x27, 0x04, 0x7a, 0x31, 0x94, 0xe7, 0x32, 0x61, 0xc3, 0x55, 0xa6,
        0x5e, 0x1e, 0xdd, 0x3d, 0x04, 0x1c, 0x1e, 0x2d, 0x8d, 0x8d, 0x45, 0xca, 0xd9, 0x40, 0xe8, 0x97, 0xcd,
        0x01, 0x18, 0xc5,
    };
    Crypto_DataBlob signBlob = {
        .data = reinterpret_cast<uint8_t *>(signText),
        .len = sizeof(signText)};

    OH_CryptoEccSignatureSpec *eccSignSpec = nullptr;
    OH_Crypto_ErrCode ret = OH_CryptoEccSignatureSpec_Create(&signBlob, &eccSignSpec);
    if (ret != CRYPTO_SUCCESS) {
        return ret;
    }

    Crypto_DataBlob r = {.data = nullptr, .len = 0};
    Crypto_DataBlob s = {.data = nullptr, .len = 0};
    ret = OH_CryptoEccSignatureSpec_GetRAndS(eccSignSpec, &r, &s);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoEccSignatureSpec_Destroy(eccSignSpec);
        return ret;
    }
    OH_Crypto_FreeDataBlob(&r);
    OH_Crypto_FreeDataBlob(&s);
    OH_CryptoEccSignatureSpec_Destroy(eccSignSpec);
    return CRYPTO_SUCCESS;
}
```
