# 使用ChaCha20对称密钥加解密(C/C++)

<!--Kit: Crypto Architecture Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--Designer: @lanming-->
<!--Tester: @PAFT-->
<!--Adviser: @zengyawen-->

从API版本22开始，算法库支持该算法。

对应的算法规格请查看[对称密钥加解密算法规格：ChaCha20](crypto-encryption-decryption.md#chacha20)。

## 在CMake脚本中链接相关动态库
```txt
target_link_libraries(entry PUBLIC libohcrypto.so)
```
## 开发步骤

### 使用ChaCha20对称密钥加解密

**创建对象**

调用[OH_CryptoSymKeyGenerator_Create](../../reference/apis-crypto-architecture-kit/capi-crypto-sym-key-h.md#oh_cryptosymkeygenerator_create)、[OH_CryptoSymKeyGenerator_Generate](../../reference/apis-crypto-architecture-kit/capi-crypto-sym-key-h.md#oh_cryptosymkeygenerator_generate)，生成密钥算法为ChaCha20的对称密钥（OH_CryptoSymKey）。
   
如何生成ChaCha20对称密钥，开发者可参考下文示例，并结合[对称密钥生成和转换规格：ChaCha20](crypto-key-generation-conversion.md#chacha20)和[随机生成对称密钥](crypto-generate-sym-key-randomly-ndk.md)理解。参考文档与示例可能存在入参差异，请注意区分。

**加密**

1. 调用[OH_CryptoSymCipher_Create](../../reference/apis-crypto-architecture-kit/capi-crypto-sym-cipher-h.md#oh_cryptosymcipher_create)，指定字符串参数'ChaCha20'，创建对称密钥类型为ChaCha20的Cipher实例，用于完成加密操作。

2. 调用[OH_CryptoSymCipherParams_Create](../../reference/apis-crypto-architecture-kit/capi-crypto-sym-cipher-h.md#oh_cryptosymcipherparams_create)创建参数对象，调用[OH_CryptoSymCipherParams_SetParam](../../reference/apis-crypto-architecture-kit/capi-crypto-sym-cipher-h.md#oh_cryptosymcipherparams_setparam)设置对应的加密参数。

3. 调用[OH_CryptoSymCipher_Init](../../reference/apis-crypto-architecture-kit/capi-crypto-sym-cipher-h.md#oh_cryptosymcipher_init)，设置模式为加密（CRYPTO_ENCRYPT_MODE），指定加密密钥（OH_CryptoSymKey）和对应的加密参数（OH_CryptoSymCipherParams），初始化加密Cipher实例。

4. 调用[OH_CryptoSymCipher_Update](../../reference/apis-crypto-architecture-kit/capi-crypto-sym-cipher-h.md#oh_cryptosymcipher_update)，更新数据（明文）。

5. 调用[OH_CryptoSymCipher_Final](../../reference/apis-crypto-architecture-kit/capi-crypto-sym-cipher-h.md#oh_cryptosymcipher_final)，获取加密后的数据。
   
    > **说明：**
    >
    > 由于已使用update传入数据，此处data传入null。
    >
    > final输出结果可能为null，在访问具体数据前，需要先判断结果是否为null，避免产生异常。

6. 调用[OH_CryptoSymKeyGenerator_Destroy](../../reference/apis-crypto-architecture-kit/capi-crypto-sym-key-h.md#oh_cryptosymkeygenerator_destroy)、[OH_CryptoSymCipher_Destroy](../../reference/apis-crypto-architecture-kit/capi-crypto-sym-cipher-h.md#oh_cryptosymcipher_destroy)、[OH_CryptoSymCipherParams_Destroy](../../reference/apis-crypto-architecture-kit/capi-crypto-sym-cipher-h.md#oh_cryptosymcipherparams_destroy)销毁各对象。

**解密**

1. 调用[OH_CryptoSymCipher_Create](../../reference/apis-crypto-architecture-kit/capi-crypto-sym-cipher-h.md#oh_cryptosymcipher_create)，指定字符串参数'ChaCha20'，创建对称密钥类型为ChaCha20的Cipher实例，用于完成解密操作。

2. 调用[OH_CryptoSymCipher_Init](../../reference/apis-crypto-architecture-kit/capi-crypto-sym-cipher-h.md#oh_cryptosymcipher_init)，设置模式为解密（CRYPTO_DECRYPT_MODE），指定解密密钥（OH_CryptoSymKey）和对应的解密参数（OH_CryptoSymCipherParams），初始化解密Cipher实例。

3. 调用[OH_CryptoSymCipher_Update](../../reference/apis-crypto-architecture-kit/capi-crypto-sym-cipher-h.md#oh_cryptosymcipher_update)，更新数据（密文）。

4. 调用[OH_CryptoSymCipher_Final](../../reference/apis-crypto-architecture-kit/capi-crypto-sym-cipher-h.md#oh_cryptosymcipher_final)，获取解密后的数据。

<!-- @[encrypt_decrypt_chacha20_symkey](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Security/CryptoArchitectureKit/EncryptionDecryption/EncryptionDecryptionGuidanceChaCha20/entry/src/main/cpp/types/project/chacha20_encryption_decryption.cpp) -->

``` C++
#include "CryptoArchitectureKit/crypto_common.h"
#include "CryptoArchitectureKit/crypto_sym_cipher.h"
#include <cstring>
#include "file.h"

// 参数赋值函数
static OH_Crypto_ErrCode doChaCha20SetParams(Crypto_DataBlob *ivBlob, OH_CryptoSymCipherParams **params)
{
    OH_Crypto_ErrCode ret = OH_CryptoSymCipherParams_Create(params);
    if (ret != CRYPTO_SUCCESS) {
        return ret;
    }
    ret = OH_CryptoSymCipherParams_SetParam(*params, CRYPTO_IV_DATABLOB, ivBlob);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoSymCipherParams_Destroy(*params);
        *params = nullptr;
        return ret;
    }
    return ret;
}

// 加密函数
static OH_Crypto_ErrCode doChaCha20Encrypt(OH_CryptoSymKey *keyCtx, OH_CryptoSymCipherParams *params,
    Crypto_DataBlob *msgBlob, Crypto_DataBlob *encData)
{
    OH_CryptoSymCipher *encCtx = nullptr;
    OH_Crypto_ErrCode ret = OH_CryptoSymCipher_Create("ChaCha20", &encCtx);
    if (ret != CRYPTO_SUCCESS) {
        goto end;
    }
    ret = OH_CryptoSymCipher_Init(encCtx, CRYPTO_ENCRYPT_MODE, keyCtx, params);
    if (ret != CRYPTO_SUCCESS) {
        goto end;
    }
    ret = OH_CryptoSymCipher_Final(encCtx, msgBlob, encData);
    if (ret != CRYPTO_SUCCESS) {
        goto end;
    }

end:
    OH_CryptoSymCipher_Destroy(encCtx);
    return ret;
}

// 解密函数
static OH_Crypto_ErrCode doChaCha20Decrypt(OH_CryptoSymKey *keyCtx, OH_CryptoSymCipherParams *params,
    Crypto_DataBlob *encData, Crypto_DataBlob *decData)
{
    OH_CryptoSymCipher *decCtx = nullptr;
    OH_Crypto_ErrCode ret = OH_CryptoSymCipher_Create("ChaCha20", &decCtx);
    if (ret != CRYPTO_SUCCESS) {
        goto end;
    }
    ret = OH_CryptoSymCipher_Init(decCtx, CRYPTO_DECRYPT_MODE, keyCtx, params); // 解密使用的params与加密时相同。
    if (ret != CRYPTO_SUCCESS) {
        goto end;
    }
    ret = OH_CryptoSymCipher_Final(decCtx, encData, decData);
    if (ret != CRYPTO_SUCCESS) {
        goto end;
    }

end:
    OH_CryptoSymCipher_Destroy(decCtx);
    return ret;
}

OH_Crypto_ErrCode doTestChaCha20()
{
    OH_CryptoSymKeyGenerator *genCtx = nullptr;
    OH_CryptoSymKey *keyCtx = nullptr;
    OH_CryptoSymCipherParams *params = nullptr;
    Crypto_DataBlob encData = {.data = nullptr, .len = 0};
    Crypto_DataBlob decData = {.data = nullptr, .len = 0};
    char *plainText = const_cast<char *>("this is test!");
    Crypto_DataBlob msgBlob = {.data = (uint8_t *)(plainText), .len = strlen(plainText)};
    uint8_t iv[16] = {1, 2, 4, 12, 3, 4, 2, 3, 3, 2, 0, 4, 3, 1, 0, 10}; // 示例代码iv值，开发者可使用安全随机数生成。
    Crypto_DataBlob ivBlob = {.data = iv, .len = sizeof(iv)};
    // 生成对称密钥。
    OH_Crypto_ErrCode ret = OH_CryptoSymKeyGenerator_Create("ChaCha20", &genCtx);
    if (ret != CRYPTO_SUCCESS) {
        goto end;
    }
    ret = OH_CryptoSymKeyGenerator_Generate(genCtx, &keyCtx);
    if (ret != CRYPTO_SUCCESS) {
        goto end;
    }

    // 参数赋值。
    ret = doChaCha20SetParams(&ivBlob, &params);
    if (ret != CRYPTO_SUCCESS) {
        goto end;
    }

    // 加密。
    ret = doChaCha20Encrypt(keyCtx, params, &msgBlob, &encData);
    if (ret != CRYPTO_SUCCESS) {
        goto end;
    }

    // 解密。
    ret = doChaCha20Decrypt(keyCtx, params, &encData, &decData);
    if (ret != CRYPTO_SUCCESS) {
        goto end;
    }

end:
    OH_CryptoSymCipherParams_Destroy(params);
    OH_CryptoSymKeyGenerator_Destroy(genCtx);
    OH_CryptoSymKey_Destroy(keyCtx);
    OH_Crypto_FreeDataBlob(&encData);
    OH_Crypto_FreeDataBlob(&decData);
    return ret;
}
```

### 使用ChaCha20对称密钥（Poly1305模式）加解密

**创建对象**

调用[OH_CryptoSymKeyGenerator_Create](../../reference/apis-crypto-architecture-kit/capi-crypto-sym-key-h.md#oh_cryptosymkeygenerator_create)、[OH_CryptoSymKeyGenerator_Generate](../../reference/apis-crypto-architecture-kit/capi-crypto-sym-key-h.md#oh_cryptosymkeygenerator_generate)，生成密钥算法为ChaCha20的对称密钥（OH_CryptoSymKey）。
   
如何生成ChaCha20对称密钥，开发者可参考下文示例，并结合[对称密钥生成和转换规格：ChaCha20](crypto-key-generation-conversion.md#chacha20)和[随机生成对称密钥](crypto-generate-sym-key-randomly-ndk.md)理解。参考文档与示例可能存在入参差异，请注意区分。

**加密**

1. 调用[OH_CryptoSymCipher_Create](../../reference/apis-crypto-architecture-kit/capi-crypto-sym-cipher-h.md#oh_cryptosymcipher_create)，指定字符串参数'ChaCha20|Poly1305'，创建对称密钥类型为ChaCha20、模式为Poly1305的Cipher实例，用于完成加密操作。

2. 调用[OH_CryptoSymCipherParams_Create](../../reference/apis-crypto-architecture-kit/capi-crypto-sym-cipher-h.md#oh_cryptosymcipherparams_create)创建参数对象，调用[OH_CryptoSymCipherParams_SetParam](../../reference/apis-crypto-architecture-kit/capi-crypto-sym-cipher-h.md#oh_cryptosymcipherparams_setparam)设置对应的加密参数。

3. 调用[OH_CryptoSymCipher_Init](../../reference/apis-crypto-architecture-kit/capi-crypto-sym-cipher-h.md#oh_cryptosymcipher_init)，设置模式为加密（CRYPTO_ENCRYPT_MODE），指定加密密钥（OH_CryptoSymKey）和Poly1305模式对应的加密参数（OH_CryptoSymCipherParams），初始化加密Cipher实例。

4. 调用[OH_CryptoSymCipher_Update](../../reference/apis-crypto-architecture-kit/capi-crypto-sym-cipher-h.md#oh_cryptosymcipher_update)，更新数据（明文）。

5. 调用[OH_CryptoSymCipher_Final](../../reference/apis-crypto-architecture-kit/capi-crypto-sym-cipher-h.md#oh_cryptosymcipher_final)，获取加密后的数据。

    > **说明：**
    >
    > 由于已使用update传入数据，此处data传入null。
    >
    > final输出结果可能为null，在访问具体数据前，需要先判断结果是否为null，避免产生异常。

6. 使用[OH_CryptoSymCipherParams_Create](../../reference/apis-crypto-architecture-kit/capi-crypto-sym-cipher-h.md#oh_cryptosymcipherparams_create)创建Params，使用[OH_CryptoSymCipherParams_SetParam](../../reference/apis-crypto-architecture-kit/capi-crypto-sym-cipher-h.md#oh_cryptosymcipherparams_setparam)设置authTag，作为解密的认证信息。在Poly1305模式下，需要从加密后的数据中取出末尾16字节，作为解密时初始化的认证信息。

7. 调用[OH_CryptoSymKeyGenerator_Destroy](../../reference/apis-crypto-architecture-kit/capi-crypto-sym-key-h.md#oh_cryptosymkeygenerator_destroy)、[OH_CryptoSymCipher_Destroy](../../reference/apis-crypto-architecture-kit/capi-crypto-sym-cipher-h.md#oh_cryptosymcipher_destroy)、[OH_CryptoSymCipherParams_Destroy](../../reference/apis-crypto-architecture-kit/capi-crypto-sym-cipher-h.md#oh_cryptosymcipherparams_destroy)销毁各对象。

**解密**

1. 调用[OH_CryptoSymCipher_Create](../../reference/apis-crypto-architecture-kit/capi-crypto-sym-cipher-h.md#oh_cryptosymcipher_create)，指定字符串参数'ChaCha20|Poly1305'，创建对称密钥类型为ChaCha20、模式为Poly1305的Cipher实例，用于完成解密操作。

2. 调用[OH_CryptoSymCipher_Init](../../reference/apis-crypto-architecture-kit/capi-crypto-sym-cipher-h.md#oh_cryptosymcipher_init)，设置模式为解密（CRYPTO_DECRYPT_MODE），指定解密密钥（OH_CryptoSymKey）和Poly1305模式对应的解密参数（OH_CryptoSymCipherParams），初始化解密Cipher实例。

3. 调用[OH_CryptoSymCipher_Update](../../reference/apis-crypto-architecture-kit/capi-crypto-sym-cipher-h.md#oh_cryptosymcipher_update)，更新数据（密文）。

4. 调用[OH_CryptoSymCipher_Final](../../reference/apis-crypto-architecture-kit/capi-crypto-sym-cipher-h.md#oh_cryptosymcipher_final)，获取解密后的数据。

<!-- @[poly1305_encrypt_decrypt_chacha20_symkey](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Security/CryptoArchitectureKit/EncryptionDecryption/EncryptionDecryptionGuidanceChaCha20/entry/src/main/cpp/types/project/chacha20_poly1305_encryption_decryption.cpp) -->

``` C++
#include "CryptoArchitectureKit/crypto_common.h"
#include "CryptoArchitectureKit/crypto_sym_cipher.h"
#include <cstring>
#include "file.h"

// 参数赋值函数
static OH_Crypto_ErrCode doChaCha20Poly1305SetParams(Crypto_DataBlob *ivData, Crypto_DataBlob *aadData,
    Crypto_DataBlob *tagData, OH_CryptoSymCipherParams **params)
{
    OH_Crypto_ErrCode ret = OH_CryptoSymCipherParams_Create(params);
    if (ret != CRYPTO_SUCCESS) {
        return ret;
    }
    ret = OH_CryptoSymCipherParams_SetParam(*params, CRYPTO_IV_DATABLOB, ivData);
    if (ret != CRYPTO_SUCCESS) {
        goto end;
    }
    ret = OH_CryptoSymCipherParams_SetParam(*params, CRYPTO_AAD_DATABLOB, aadData);
    if (ret != CRYPTO_SUCCESS) {
        goto end;
    }
    ret = OH_CryptoSymCipherParams_SetParam(*params, CRYPTO_TAG_DATABLOB, tagData);
    if (ret != CRYPTO_SUCCESS) {
        goto end;
    }
    return ret;

end:
    OH_CryptoSymCipherParams_Destroy(*params);
    *params = nullptr;
    return ret;
}

// 加密函数
static OH_Crypto_ErrCode doChaCha20Poly1305Encrypt(OH_CryptoSymKey *keyCtx, OH_CryptoSymCipherParams *params,
    Crypto_DataBlob *msgBlob, Crypto_DataBlob *outUpdate, Crypto_DataBlob *tagOutPut)
{
    OH_CryptoSymCipher *encCtx = nullptr;
    OH_Crypto_ErrCode ret = OH_CryptoSymCipher_Create("ChaCha20|Poly1305", &encCtx);
    if (ret != CRYPTO_SUCCESS) {
        goto end;
    }
    ret = OH_CryptoSymCipher_Init(encCtx, CRYPTO_ENCRYPT_MODE, keyCtx, params);
    if (ret != CRYPTO_SUCCESS) {
        goto end;
    }
    ret = OH_CryptoSymCipher_Update(encCtx, msgBlob, outUpdate);
    if (ret != CRYPTO_SUCCESS) {
        goto end;
    }
    ret = OH_CryptoSymCipher_Final(encCtx, nullptr, tagOutPut);
    if (ret != CRYPTO_SUCCESS) {
        goto end;
    }

end:
    OH_CryptoSymCipher_Destroy(encCtx);
    return ret;
}

// 解密函数
static OH_Crypto_ErrCode doChaCha20Poly1305Decrypt(OH_CryptoSymKey *keyCtx, OH_CryptoSymCipherParams *params,
    Crypto_DataBlob *tagOutPut, Crypto_DataBlob *outUpdate, Crypto_DataBlob *decUpdate)
{
    OH_CryptoSymCipher *decCtx = nullptr;
    OH_Crypto_ErrCode ret = OH_CryptoSymCipherParams_SetParam(params, CRYPTO_TAG_DATABLOB, tagOutPut);
    if (ret != CRYPTO_SUCCESS) {
        return ret;
    }
    ret = OH_CryptoSymCipher_Create("ChaCha20|Poly1305", &decCtx);
    if (ret != CRYPTO_SUCCESS) {
        goto end;
    }
    ret = OH_CryptoSymCipher_Init(decCtx, CRYPTO_DECRYPT_MODE, keyCtx, params);
    if (ret != CRYPTO_SUCCESS) {
        goto end;
    }
    ret = OH_CryptoSymCipher_Final(decCtx, outUpdate, decUpdate);
    if (ret != CRYPTO_SUCCESS) {
        goto end;
    }

end:
    OH_CryptoSymCipher_Destroy(decCtx);
    return ret;
}

OH_Crypto_ErrCode doTestChaCha20Poly1305()
{
    OH_CryptoSymKeyGenerator *genCtx = nullptr;
    OH_CryptoSymKey *keyCtx = nullptr;
    OH_CryptoSymCipherParams *params = nullptr;

    Crypto_DataBlob outUpdate = {.data = nullptr, .len = 0};
    Crypto_DataBlob decUpdate = {.data = nullptr, .len = 0};

    uint8_t aad[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    uint8_t tag[16] = {0};
    uint8_t iv[12] = {1, 2, 4, 12, 3, 4, 2, 3, 3, 2, 0, 4}; // iv使用安全随机数生成。
    Crypto_DataBlob ivData = {.data = iv, .len = sizeof(iv)};
    Crypto_DataBlob aadData = {.data = aad, .len = sizeof(aad)};
    Crypto_DataBlob tagData = {.data = tag, .len = sizeof(tag)};
    Crypto_DataBlob tagOutPut = {.data = nullptr, .len = 0};
    char *plainText = const_cast<char *>("this is test!");
    Crypto_DataBlob msgBlob = {.data = (uint8_t *)(plainText), .len = strlen(plainText)};
    OH_Crypto_ErrCode ret = OH_CryptoSymKeyGenerator_Create("ChaCha20", &genCtx);
    if (ret != CRYPTO_SUCCESS) {
        goto end;
    }
    ret = OH_CryptoSymKeyGenerator_Generate(genCtx, &keyCtx);
    if (ret != CRYPTO_SUCCESS) {
        goto end;
    }

    // 参数赋值。
    ret = doChaCha20Poly1305SetParams(&ivData, &aadData, &tagData, &params);
    if (ret != CRYPTO_SUCCESS) {
        goto end;
    }

    // 加密。
    ret = doChaCha20Poly1305Encrypt(keyCtx, params, &msgBlob, &outUpdate, &tagOutPut);
    if (ret != CRYPTO_SUCCESS) {
        goto end;
    }

    // 解密。
    ret = doChaCha20Poly1305Decrypt(keyCtx, params, &tagOutPut, &outUpdate, &decUpdate);
    if (ret != CRYPTO_SUCCESS) {
        goto end;
    }

    // 释放资源。
end:
    OH_CryptoSymCipherParams_Destroy(params);
    OH_CryptoSymKeyGenerator_Destroy(genCtx);
    OH_CryptoSymKey_Destroy(keyCtx);
    OH_Crypto_FreeDataBlob(&outUpdate);
    OH_Crypto_FreeDataBlob(&decUpdate);
    OH_Crypto_FreeDataBlob(&tagOutPut);
    return ret;
}
```

