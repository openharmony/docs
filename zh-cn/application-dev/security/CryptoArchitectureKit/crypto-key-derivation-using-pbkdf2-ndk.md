# 使用PBKDF2进行密钥派生(C/C++)

<!--Kit: Crypto Architecture Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--SE: @lanming-->
<!--TSE: @PAFT-->

对应的算法规格请查看[密钥派生算法规格：PBKDF2](crypto-key-derivation-overview.md#pbkdf2算法)。

## 开发步骤

1. 调用[OH_CryptoKdfParams_Create](../../reference/apis-crypto-architecture-kit/capi-crypto-kdf-h.md#oh_cryptokdfparams_create)，指定字符串参数'PBKDF2'，创建密钥派生参数对象。

2. 调用[OH_CryptoKdfParams_SetParam](../../reference/apis-crypto-architecture-kit/capi-crypto-kdf-h.md#oh_cryptokdfparams_setparam)，设置PBKDF2所需的参数。示例如下：
   - CRYPTO_KDF_KEY_DATABLOB：用于生成派生密钥的原始密码。
   - CRYPTO_KDF_SALT_DATABLOB：盐值。
   - CRYPTO_KDF_ITER_COUNT_INT：重复运算的次数，需要为正整数。

3. 调用[OH_CryptoKdf_Create](../../reference/apis-crypto-architecture-kit/capi-crypto-kdf-h.md#oh_cryptokdf_create)，指定字符串参数'PBKDF2|SHA256'，创建密钥派生函数对象。

4. 调用[OH_CryptoKdf_Derive](../../reference/apis-crypto-architecture-kit/capi-crypto-kdf-h.md#oh_cryptokdf_derive)，指定目标密钥的字节长度，进行密钥派生。

```C++
#include "CryptoArchitectureKit/crypto_architecture_kit.h"
#include <stdio.h>
#include <string.h>

static OH_Crypto_ErrCode doTestPbkdf2()
{
    // 创建PBKDF2参数对象。
    OH_CryptoKdfParams *params = nullptr;
    OH_Crypto_ErrCode ret = OH_CryptoKdfParams_Create("PBKDF2", &params);
    if (ret != CRYPTO_SUCCESS) {
        return ret;
    }

    // 设置密码。
    const char *password = "123456";
    Crypto_DataBlob passwordBlob = {
        .data = reinterpret_cast<uint8_t *>(const_cast<char *>(password)),
        .len = strlen(password)
    };
    ret = OH_CryptoKdfParams_SetParam(params, CRYPTO_KDF_KEY_DATABLOB, &passwordBlob);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoKdfParams_Destroy(params);
        return ret;
    }

    // 设置盐值。
    const char *salt = "saltstring";
    Crypto_DataBlob saltBlob = {
        .data = reinterpret_cast<uint8_t *>(const_cast<char *>(salt)),
        .len = strlen(salt)
    };
    ret = OH_CryptoKdfParams_SetParam(params, CRYPTO_KDF_SALT_DATABLOB, &saltBlob);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoKdfParams_Destroy(params);
        return ret;
    }

    // 设置迭代次数。
    int iterations = 10000;
    Crypto_DataBlob iterationsBlob = {
        .data = reinterpret_cast<uint8_t *>(&iterations),
        .len = sizeof(int)
    };
    ret = OH_CryptoKdfParams_SetParam(params, CRYPTO_KDF_ITER_COUNT_INT, &iterationsBlob);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoKdfParams_Destroy(params);
        return ret;
    }

    // 创建密钥派生函数对象。
    OH_CryptoKdf *kdfCtx = nullptr;
    ret = OH_CryptoKdf_Create("PBKDF2|SHA256", &kdfCtx);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoKdfParams_Destroy(params);
        return ret;
    }

    // 派生密钥。
    Crypto_DataBlob out = {0};
    uint32_t keyLength = 32; // 生成32字节的密钥。
    ret = OH_CryptoKdf_Derive(kdfCtx, params, keyLength, &out);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoKdf_Destroy(kdfCtx);
        OH_CryptoKdfParams_Destroy(params);
        return ret;
    }

    printf("Derived key length: %u\n", out.len);

    // 清理资源。
    OH_Crypto_FreeDataBlob(&out);
    OH_CryptoKdf_Destroy(kdfCtx);
    OH_CryptoKdfParams_Destroy(params);
    return CRYPTO_SUCCESS;
}
```