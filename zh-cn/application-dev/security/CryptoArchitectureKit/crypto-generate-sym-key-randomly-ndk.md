# 随机生成对称密钥(C/C++)

<!--Kit: Crypto Architecture Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--Designer: @lanming-->
<!--Tester: @PAFT-->
<!--Adviser: @zengyawen-->

以AES和SM4为例，随机生成对称密钥（OH_CryptoSymKey）。

对称密钥对象可用于后续加解密操作，二进制数据可用于存储或运输。

## 在CMake脚本中链接相关动态库
```txt
target_link_libraries(entry PUBLIC libohcrypto.so)
```

## 随机生成AES密钥

对应的算法规格请查看[对称密钥生成和转换规格：AES](crypto-sym-key-generation-conversion-spec.md#aes)。

1. 调用[OH_CryptoSymKeyGenerator_Create](../../reference/apis-crypto-architecture-kit/capi-crypto-sym-key-h.md#oh_cryptosymkeygenerator_create)，指定字符串参数'AES256'，创建密钥算法为AES、密钥长度为256位的对称密钥生成器（OH_CryptoSymKeyGenerator）。

2. 调用[OH_CryptoSymKeyGenerator_Generate](../../reference/apis-crypto-architecture-kit/capi-crypto-sym-key-h.md#oh_cryptosymkeygenerator_generate)，随机生成对称密钥对象（OH_CryptoSymKey）。

3. 调用[OH_CryptoSymKey_GetKeyData](../../reference/apis-crypto-architecture-kit/capi-crypto-sym-key-h.md#oh_cryptosymkey_getkeydata)，获取密钥对象的二进制数据。

```c++
#include "CryptoArchitectureKit/crypto_common.h"
#include "CryptoArchitectureKit/crypto_sym_key.h"

static OH_Crypto_ErrCode testGenerateSymKey()
{
    OH_CryptoSymKeyGenerator *ctx = nullptr;
    OH_CryptoSymKey *keyCtx = nullptr;
    Crypto_DataBlob out = {.data = nullptr, .len = 0};
    OH_Crypto_ErrCode ret = OH_CryptoSymKeyGenerator_Create("AES256", &ctx);
    if (ret != CRYPTO_SUCCESS) {
        return ret;
    }
    ret = OH_CryptoSymKeyGenerator_Generate(ctx, &keyCtx);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoSymKeyGenerator_Destroy(ctx);
        return ret;
    }
    ret = OH_CryptoSymKey_GetKeyData(keyCtx, &out);
    OH_CryptoSymKeyGenerator_Destroy(ctx);
    OH_CryptoSymKey_Destroy(keyCtx);
    if (ret != CRYPTO_SUCCESS) {
        return ret;
    }
    OH_Crypto_FreeDataBlob(&out);
    return ret;
}
```

## 随机生成SM4密钥

对应的算法规格请查看[对称密钥生成和转换规格：SM4](crypto-sym-key-generation-conversion-spec.md#sm4)。

1. 调用[OH_CryptoSymKeyGenerator_Create](../../reference/apis-crypto-architecture-kit/capi-crypto-sym-key-h.md#oh_cryptosymkeygenerator_create)，指定字符串参数'SM4_128'，创建密钥算法为SM4、密钥长度为128位的对称密钥生成器（OH_CryptoSymKeyGenerator）。

2. 调用[OH_CryptoSymKeyGenerator_Generate](../../reference/apis-crypto-architecture-kit/capi-crypto-sym-key-h.md#oh_cryptosymkeygenerator_generate)，随机生成对称密钥对象（OH_CryptoSymKey）。

3. 调用[OH_CryptoSymKey_GetKeyData](../../reference/apis-crypto-architecture-kit/capi-crypto-sym-key-h.md#oh_cryptosymkey_getkeydata)，获取密钥对象的二进制数据。

```c++
#include "CryptoArchitectureKit/crypto_common.h"
#include "CryptoArchitectureKit/crypto_sym_key.h"

static OH_Crypto_ErrCode testGenerateSM4Key()
{
    OH_CryptoSymKeyGenerator *ctx = nullptr;
    OH_CryptoSymKey *keyCtx = nullptr;
    Crypto_DataBlob out = {.data = nullptr, .len = 0}; // 对称密钥二进制数据。
    OH_Crypto_ErrCode ret = OH_CryptoSymKeyGenerator_Create("SM4_128", &ctx); // 创建对称密钥生成器。
    if (ret != CRYPTO_SUCCESS) {
        return ret;
    }
    ret = OH_CryptoSymKeyGenerator_Generate(ctx, &keyCtx); // 随机生成对称密钥对象。
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoSymKeyGenerator_Destroy(ctx);
        return ret;
    }
    ret = OH_CryptoSymKey_GetKeyData(keyCtx, &out); // 获取对称密钥对象的二进制数据。
    OH_CryptoSymKeyGenerator_Destroy(ctx);
    OH_CryptoSymKey_Destroy(keyCtx);
    if (ret != CRYPTO_SUCCESS) {
        return ret;
    }
    OH_Crypto_FreeDataBlob(&out);
    return ret;
}
```
