# 使用SM4对称密钥（GCM模式）加解密(C/C++)


对应的算法规格请查看[对称密钥加解密算法规格：SM4](crypto-sym-encrypt-decrypt-spec.md#sm4)。


## 在CMake脚本中链接相关动态库
```txt
target_link_libraries(entry PUBLIC libohcrypto.so)
```

**加密**


1. 调用[OH_CryptoSymKeyGenerator_Create](../../reference/apis-crypto-architecture-kit/_crypto_sym_key_api.md#oh_cryptosymkeygenerator_create)、[OH_CryptoSymKeyGenerator_Generate](../../reference/apis-crypto-architecture-kit/_crypto_sym_key_api.md#oh_cryptosymkeygenerator_generate)，生成密钥算法为SM4、密钥长度为128位的对称密钥（OH_CryptoSymKey）。
   
   如何生成SM4对称密钥，开发者可参考下文示例，并结合[对称密钥生成和转换规格：SM4](crypto-sym-key-generation-conversion-spec.md#sm4)和[随机生成对称密钥](crypto-generate-sym-key-randomly.md)理解，参考文档与当前示例可能存在入参差异，请在阅读时注意区分。

2. 调用[OH_CryptoSymCipher_Create](../../reference/apis-crypto-architecture-kit/_crypto_sym_cipher_api.md#oh_cryptosymcipher_create)，指定字符串参数'SM4_128|GCM|PKCS7'，创建对称密钥类型为SM4_128、分组模式为GCM、填充模式为PKCS7的Cipher实例，用于完成加密操作。

3. 调用[OH_CryptoSymCipherParams_Create](../../reference/apis-crypto-architecture-kit/_crypto_sym_cipher_api.md#oh_cryptosymcipherparams_create)创建参数对象，调用[OH_CryptoSymCipherParams_SetParam](../../reference/apis-crypto-architecture-kit/_crypto_sym_cipher_api.md#oh_cryptosymcipherparams_setparam)设置对应的加密参数。

4. 调用[OH_CryptoSymCipher_Init](../../reference/apis-crypto-architecture-kit/_crypto_sym_cipher_api.md#oh_cryptosymcipher_init)，设置模式为加密（CRYPTO_ENCRYPT_MODE），指定加密密钥（OH_CryptoSymKey）和GCM模式对应的加密参数（OH_CryptoSymCipherParams），初始化加密Cipher实例。

5. 调用[OH_CryptoSymCipher_Update](../../reference/apis-crypto-architecture-kit/_crypto_sym_cipher_api.md#oh_cryptosymcipher_update)，更新数据（明文）。
   
   当前单次update长度没有限制，开发者可以根据数据量判断如何调用update。

   - 当数据量较小时，可以在init完成后直接调用final。
   - 当数据量较大时，可以多次调用update，即分段加解密。

6. 调用[OH_CryptoSymCipher_Final](../../reference/apis-crypto-architecture-kit/_crypto_sym_cipher_api.md#oh_cryptosymcipher_final)，获取加密后的数据。
   - 由于已使用update传入数据，此处data传入null。
   - final输出结果可能为null，在访问具体数据前，需要先判断结果是否为null，避免产生异常。

7. 使用[OH_CryptoSymCipherParams_Create](../../reference/apis-crypto-architecture-kit/_crypto_sym_cipher_api.md#oh_cryptosymcipherparams_create)创建Params，使用[OH_CryptoSymCipherParams_SetParam](../../reference/apis-crypto-architecture-kit/_crypto_sym_cipher_api.md#oh_cryptosymcipherparams_setparam)设置authTag，作为解密的认证信息。在GCM模式下，需要从加密后的数据中取出末尾16字节，作为解密时初始化的认证信息。示例中authTag恰好为16字节。

8. 调用[OH_CryptoSymKeyGenerator_Destroy](../../reference/apis-crypto-architecture-kit/_crypto_sym_key_api.md#oh_cryptosymkeygenerator_destroy)、[OH_CryptoSymCipher_Destroy](../../reference/apis-crypto-architecture-kit/_crypto_sym_cipher_api.md#oh_cryptosymcipher_destroy)、[OH_CryptoSymCipherParams_Destroy](../../reference/apis-crypto-architecture-kit/_crypto_sym_cipher_api.md#oh_cryptosymcipherparams_destroy)销毁各对象。


**解密**

1. 调用[OH_CryptoSymCipher_Create](../../reference/apis-crypto-architecture-kit/_crypto_sym_cipher_api.md#oh_cryptosymcipher_create)，指定字符串参数'SM4_128|GCM|PKCS7'，创建对称密钥类型为SM4_128、分组模式为GCM、填充模式为PKCS7的Cipher实例，用于完成解密操作。

2. 调用[OH_CryptoSymCipher_Init](../../reference/apis-crypto-architecture-kit/_crypto_sym_cipher_api.md#oh_cryptosymcipher_init)，设置模式为解密（CRYPTO_DECRYPT_MODE），指定解密密钥（OH_CryptoSymKey）和GCM模式对应的解密参数（OH_CryptoSymCipherParams），初始化解密Cipher实例。

3. 调用[OH_CryptoSymCipher_Update](../../reference/apis-crypto-architecture-kit/_crypto_sym_cipher_api.md#oh_cryptosymcipher_update)，更新数据（密文）。

4. 调用[OH_CryptoSymCipher_Final](../../reference/apis-crypto-architecture-kit/_crypto_sym_cipher_api.md#oh_cryptosymcipher_final)，获取解密后的数据。


- 示例：

```c++
#include "CryptoArchitectureKit/crypto_common.h"
#include "CryptoArchitectureKit/crypto_sym_cipher.h"
#include <string.h>

static OH_Crypto_ErrCode doTestSm4Gcm()
{
    OH_CryptoSymKeyGenerator *genCtx = nullptr;
    OH_CryptoSymCipher *encCtx = nullptr;
    OH_CryptoSymCipher *decCtx = nullptr;
    OH_CryptoSymKey *keyCtx = nullptr;
    OH_CryptoSymCipherParams *params = nullptr;

    Crypto_DataBlob outUpdate = {.data = nullptr, .len = 0};
    Crypto_DataBlob decUpdate = {.data = nullptr, .len = 0};

    uint8_t aad[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    uint8_t tag[16] = {0};
    uint8_t iv[12] = {1, 2, 4, 12, 3, 4, 2, 3, 3, 2, 0, 4}; // iv使用安全随机数生成
    Crypto_DataBlob ivData = {.data = iv, .len = sizeof(iv)};
    Crypto_DataBlob aadData = {.data = aad, .len = sizeof(aad)};
    Crypto_DataBlob tagData = {.data = tag, .len = sizeof(tag)};
    Crypto_DataBlob tagOutPut = {.data = nullptr, .len = 0};
    char *plainText = const_cast<char *>("this is test!");
    Crypto_DataBlob msgBlob = {.data = (uint8_t *)(plainText), .len = strlen(plainText)};
    // 生成对称密钥
    OH_Crypto_ErrCode ret;
    ret = OH_CryptoSymKeyGenerator_Create("SM4_128", &genCtx);
    if (ret != CRYPTO_SUCCESS) {
        goto end;
    }
    ret = OH_CryptoSymKeyGenerator_Generate(genCtx, &keyCtx);
    if (ret != CRYPTO_SUCCESS) {
        goto end;
    }

    // 设置参数
    ret = OH_CryptoSymCipherParams_Create(&params);
    if (ret != CRYPTO_SUCCESS) {
        goto end;
    }
    ret = OH_CryptoSymCipherParams_SetParam(params, CRYPTO_IV_DATABLOB, &ivData);
    if (ret != CRYPTO_SUCCESS) {
        goto end;
    }
    ret = OH_CryptoSymCipherParams_SetParam(params, CRYPTO_AAD_DATABLOB, &aadData);
    if (ret != CRYPTO_SUCCESS) {
        goto end;
    }
    ret = OH_CryptoSymCipherParams_SetParam(params, CRYPTO_TAG_DATABLOB, &tagData);
    if (ret != CRYPTO_SUCCESS) {
        goto end;
    }

    // 加密
    ret = OH_CryptoSymCipher_Create("SM4_128|GCM|PKCS7", &encCtx);
    if (ret != CRYPTO_SUCCESS) {
        goto end;
    }
    ret = OH_CryptoSymCipher_Init(encCtx, CRYPTO_ENCRYPT_MODE, keyCtx, params);
    if (ret != CRYPTO_SUCCESS) {
        goto end;
    }
    ret = OH_CryptoSymCipher_Update(encCtx, &msgBlob, &outUpdate);
    if (ret != CRYPTO_SUCCESS) {
        goto end;
    }
    ret = OH_CryptoSymCipher_Final(encCtx, nullptr, &tagOutPut);
    if (ret != CRYPTO_SUCCESS) {
        goto end;
    }

    // 解密
    ret = OH_CryptoSymCipher_Create("SM4_128|GCM|PKCS7", &decCtx);
    if (ret != CRYPTO_SUCCESS) {
        goto end;
    }
    ret = OH_CryptoSymCipherParams_SetParam(params, CRYPTO_TAG_DATABLOB, &tagOutPut);
    if (ret != CRYPTO_SUCCESS) {
        goto end;
    }
    ret = OH_CryptoSymCipher_Init(decCtx, CRYPTO_DECRYPT_MODE, keyCtx, params);
    if (ret != CRYPTO_SUCCESS) {
        goto end;
    }
    ret = OH_CryptoSymCipher_Final(decCtx, &outUpdate, &decUpdate);
    if (ret != CRYPTO_SUCCESS) {
        goto end;
    }

    // 释放资源
end:
    OH_CryptoSymCipherParams_Destroy(params);
    OH_CryptoSymCipher_Destroy(encCtx);
    OH_CryptoSymCipher_Destroy(decCtx);
    OH_CryptoSymKeyGenerator_Destroy(genCtx);
    OH_CryptoSymKey_Destroy(keyCtx);
    OH_Crypto_FreeDataBlob(&outUpdate);
    OH_Crypto_FreeDataBlob(&decUpdate);
    OH_Crypto_FreeDataBlob(&tagOutPut);
    return ret;
}
```
