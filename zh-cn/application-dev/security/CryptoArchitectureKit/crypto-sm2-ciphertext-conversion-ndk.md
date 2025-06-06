# 使用SM2密文格式转换(C/C++)

当前支持的SM2密文格式为国密标准的ASN.1格式，其中各参数组合顺序为C1C3C2，具体参数含义请参考[转换SM2密文格式](crypto-asym-encrypt-decrypt-spec.md#转换sm2密文格式)。

开发者可指定SM2密文的参数，将其转换成符合国密标准的ASN.1格式密文。反之，也可以从国密标准的ASN.1格式密文中取出具体的SM2密文参数，便于开发者自行组合成其他格式的SM2密文。

**指定密文参数，生成标准ASN.1密文**

1. 调用[OH_CryptoSm2CiphertextSpec_Create](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-cipher-h.md#oh_cryptosm2ciphertextspec_create)，创建空的SM2密文规格对象。

2. 调用[OH_CryptoSm2CiphertextSpec_SetItem](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-cipher-h.md#oh_cryptosm2ciphertextspec_setitem)，设置密文的各个参数（C1.x、C1.y、C2、C3）。

3. 调用[OH_CryptoSm2CiphertextSpec_Encode](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-cipher-h.md#oh_cryptosm2ciphertextspec_encode)，生成ASN.1格式的密文（当前密文转换仅支持SM3，实现中只校验hash长度是否为32字节）。

4. 使用完毕后，调用[OH_CryptoSm2CiphertextSpec_Destroy](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-cipher-h.md#oh_cryptosm2ciphertextspec_destroy)销毁SM2密文规格对象。

```C++
#include "CryptoArchitectureKit/crypto_architecture_kit.h"

static OH_Crypto_ErrCode doTestGenCipherTextBySpec()
{
    // 准备SM2密文参数。
    uint8_t c1x[] = {45, 153, 88, 82, 104, 221, 226, 43, 174, 21, 122, 248, 5, 232, 105, 41, 92, 95, 102, 224,
                     216, 149, 85, 236, 110, 6, 64, 188, 149, 70, 70, 183};
    uint8_t c1y[] = {107, 93, 198, 247, 119, 18, 40, 110, 90, 156, 193, 158, 205, 113, 170, 128, 146, 109, 75,
                     17, 181, 109, 110, 91, 149, 5, 110, 233, 209, 78, 229, 96};
    uint8_t c2[] = {100, 227, 78, 195, 249, 179, 43, 70, 242, 69, 169, 10, 65, 123};
    uint8_t c3[] = {87, 167, 167, 247, 88, 146, 203, 234, 83, 126, 117, 129, 52, 142, 82, 54, 152, 226, 201, 111,
                    143, 115, 169, 125, 128, 42, 157, 31, 114, 198, 109, 244};

    // 创建空的SM2密文规格对象。
    OH_CryptoSm2CiphertextSpec *sm2CipherSpec = nullptr;
    OH_Crypto_ErrCode ret = OH_CryptoSm2CiphertextSpec_Create(nullptr, &sm2CipherSpec);
    if (ret != CRYPTO_SUCCESS) {
        return ret;
    }

    // 设置各个参数。
    Crypto_DataBlob c1xBlob = {c1x, sizeof(c1x)};
    Crypto_DataBlob c1yBlob = {c1y, sizeof(c1y)};
    Crypto_DataBlob c2Blob = {c2, sizeof(c2)};
    Crypto_DataBlob c3Blob = {c3, sizeof(c3)};

    ret = OH_CryptoSm2CiphertextSpec_SetItem(sm2CipherSpec, CRYPTO_SM2_CIPHERTEXT_C1_X, &c1xBlob);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoSm2CiphertextSpec_Destroy(sm2CipherSpec);
        return ret;
    }
    ret = OH_CryptoSm2CiphertextSpec_SetItem(sm2CipherSpec, CRYPTO_SM2_CIPHERTEXT_C1_Y, &c1yBlob);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoSm2CiphertextSpec_Destroy(sm2CipherSpec);
        return ret;
    }
    ret = OH_CryptoSm2CiphertextSpec_SetItem(sm2CipherSpec, CRYPTO_SM2_CIPHERTEXT_C2, &c2Blob);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoSm2CiphertextSpec_Destroy(sm2CipherSpec);
        return ret;
    }
    ret = OH_CryptoSm2CiphertextSpec_SetItem(sm2CipherSpec, CRYPTO_SM2_CIPHERTEXT_C3, &c3Blob);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoSm2CiphertextSpec_Destroy(sm2CipherSpec);
        return ret;
    }

    // 编码为ASN.1格式。
    Crypto_DataBlob encoded = { 0 };
    ret = OH_CryptoSm2CiphertextSpec_Encode(sm2CipherSpec, &encoded);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoSm2CiphertextSpec_Destroy(sm2CipherSpec);
        return ret;
    }

    // 清理资源。
    OH_Crypto_FreeDataBlob(&encoded);
    OH_CryptoSm2CiphertextSpec_Destroy(sm2CipherSpec);
    return ret;
}
```

**从标准ASN.1密文中获取密文参数**

1. 调用[OH_CryptoSm2CiphertextSpec_Create](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-cipher-h.md#oh_cryptosm2ciphertextspec_create)，从ASN.1格式密文创建SM2密文规格对象。

2. 调用[OH_CryptoSm2CiphertextSpec_GetItem](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-cipher-h.md#oh_cryptosm2ciphertextspec_getitem)，获取密文中的各个参数（C1.x、C1.y、C2、C3）。

3. 使用完毕后，调用[OH_CryptoSm2CiphertextSpec_Destroy](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-cipher-h.md#oh_cryptosm2ciphertextspec_destroy)销毁SM2密文规格对象。

```C++
static OH_Crypto_ErrCode doTestGetCipherTextSpec()
{
    // 准备标准ASN.1格式密文。
    uint8_t cipherTextArray[] = {48, 118, 2, 32, 45, 153, 88, 82, 104, 221, 226, 43, 174, 21, 122, 248, 5, 232, 105,
                                41, 92, 95, 102, 224, 216, 149, 85, 236, 110, 6, 64, 188, 149, 70, 70, 183, 2, 32, 107,
                                93, 198, 247, 119, 18, 40, 110, 90, 156, 193, 158, 205, 113, 170, 128, 146, 109, 75, 17,
                                181, 109, 110, 91, 149, 5, 110, 233, 209, 78, 229, 96, 4, 32, 87, 167, 167, 247, 88, 146,
                                203, 234, 83, 126, 117, 129, 52, 142, 82, 54, 152, 226, 201, 111, 143, 115, 169, 125, 128,
                                42, 157, 31, 114, 198, 109, 244, 4, 14, 100, 227, 78, 195, 249, 179, 43, 70, 242, 69, 169,
                                10, 65, 123};
    Crypto_DataBlob cipherText = {cipherTextArray, sizeof(cipherTextArray)};

    // 从ASN.1格式密文创建SM2密文规格对象。
    OH_CryptoSm2CiphertextSpec *sm2CipherSpec = nullptr;
    OH_Crypto_ErrCode ret = OH_CryptoSm2CiphertextSpec_Create(&cipherText, &sm2CipherSpec);
    if (ret != CRYPTO_SUCCESS) {
        return ret;
    }

    // 获取各个参数。
    Crypto_DataBlob c1x = { 0 };
    Crypto_DataBlob c1y = { 0 };
    Crypto_DataBlob c2 = { 0 };
    Crypto_DataBlob c3 = { 0 };

    ret = OH_CryptoSm2CiphertextSpec_GetItem(sm2CipherSpec, CRYPTO_SM2_CIPHERTEXT_C1_X, &c1x);
    if (ret != CRYPTO_SUCCESS) {
        goto EXIT;
    }
    ret = OH_CryptoSm2CiphertextSpec_GetItem(sm2CipherSpec, CRYPTO_SM2_CIPHERTEXT_C1_Y, &c1y);
    if (ret != CRYPTO_SUCCESS) {
        goto EXIT;
    }
    ret = OH_CryptoSm2CiphertextSpec_GetItem(sm2CipherSpec, CRYPTO_SM2_CIPHERTEXT_C2, &c2);
    if (ret != CRYPTO_SUCCESS) {
        goto EXIT;
    }
    ret = OH_CryptoSm2CiphertextSpec_GetItem(sm2CipherSpec, CRYPTO_SM2_CIPHERTEXT_C3, &c3);
    if (ret != CRYPTO_SUCCESS) {
        goto EXIT;
    }

EXIT:
    OH_Crypto_FreeDataBlob(&c1x);
    OH_Crypto_FreeDataBlob(&c1y);
    OH_Crypto_FreeDataBlob(&c2);
    OH_Crypto_FreeDataBlob(&c3);
    OH_CryptoSm2CiphertextSpec_Destroy(sm2CipherSpec);
    return ret;
}
```
