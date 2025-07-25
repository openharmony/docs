# 消息摘要计算SHA256(C/C++)

对应的算法规格请查看[消息摘要计算算法规格](crypto-generate-message-digest-overview.md#支持的算法与规格)。

## 在CMake脚本中链接相关动态库
```txt
target_link_libraries(entry PUBLIC libohcrypto.so)
```

## 开发步骤

在调用update接口传入数据时，可以[一次性传入所有数据](#摘要算法一次性传入)，也可以把数据人工分段，然后[分段update](#分段摘要算法)。对于同一段数据而言，计算结果没有差异。对于数据量较大的数据，开发者可以根据实际需求选择是否分段传入。

下面分别提供两种方式的示例代码。

### 摘要算法（一次性传入）

1. 调用[OH_CryptoDigest_Create](../../reference/apis-crypto-architecture-kit/capi-crypto-digest-h.md#oh_cryptodigest_create)，指定摘要算法SHA256，生成摘要实例（OH_CryptoDigest）。

2. 调用[OH_CryptoDigest_Update](../../reference/apis-crypto-architecture-kit/capi-crypto-digest-h.md#oh_cryptodigest_update)，传入自定义消息，进行摘要更新计算。单次update长度没有限制。

3. 调用[OH_CryptoDigest_Final](../../reference/apis-crypto-architecture-kit/capi-crypto-digest-h.md#oh_cryptodigest_final)，获取摘要计算结果。

4. 调用[OH_CryptoDigest_GetLength](../../reference/apis-crypto-architecture-kit/capi-crypto-digest-h.md#oh_cryptodigest_getlength)，获取摘要计算长度，单位为字节。

5. 调用[OH_DigestCrypto_Destroy](../../reference/apis-crypto-architecture-kit/capi-crypto-digest-h.md#oh_digestcrypto_destroy)，销毁摘要实例（OH_CryptoDigest）。

- 以下使用单次传入数据，获取摘要计算结果为例：

```c++
#include "CryptoArchitectureKit/crypto_common.h"
#include "CryptoArchitectureKit/crypto_digest.h"
#include <string.h>

static OH_Crypto_ErrCode doTestMd()
{
    OH_Crypto_ErrCode ret;
    OH_CryptoDigest *ctx = nullptr;
    char *testData = const_cast<char *>("0123456789");
    Crypto_DataBlob in = {.data = (uint8_t *)(testData), .len = strlen(testData)};
    Crypto_DataBlob out = {.data = nullptr, .len = 0};
    int mdLen = 0;
    ret = OH_CryptoDigest_Create("SHA256", &ctx);
    if (ret != CRYPTO_SUCCESS) {
        return ret;
    }
    do {
        ret = OH_CryptoDigest_Update(ctx, &in);
        if (ret != CRYPTO_SUCCESS) {
            break;
        }
        ret = OH_CryptoDigest_Final(ctx, &out);
        if (ret != CRYPTO_SUCCESS) {
            break;
        }
        mdLen = OH_CryptoDigest_GetLength(ctx);
    } while (0);
    OH_Crypto_FreeDataBlob(&out);
    OH_DigestCrypto_Destroy(ctx);
    return ret;
}
```

### 分段摘要算法

1. 调用[OH_CryptoDigest_Create](../../reference/apis-crypto-architecture-kit/capi-crypto-digest-h.md#oh_cryptodigest_create)，指定摘要算法SHA256，生成摘要实例（OH_CryptoDigest）。

2. 传入自定义消息，将一次传入数据量设置为20字节，多次调用[OH_CryptoDigest_Update](../../reference/apis-crypto-architecture-kit/capi-crypto-digest-h.md#oh_cryptodigest_update)，进行摘要更新计算。

3. 调用[OH_CryptoDigest_Final](../../reference/apis-crypto-architecture-kit/capi-crypto-digest-h.md#oh_cryptodigest_final)，获取摘要计算结果。

4. 调用[OH_CryptoDigest_GetLength](../../reference/apis-crypto-architecture-kit/capi-crypto-digest-h.md#oh_cryptodigest_getlength)，获取摘要计算长度，单位为字节。

5. 调用[OH_DigestCrypto_Destroy](../../reference/apis-crypto-architecture-kit/capi-crypto-digest-h.md#oh_digestcrypto_destroy)，销毁摘要实例（OH_CryptoDigest）。

- 以下使用分段传入数据，获取摘要计算结果为例：

```c++
#include <stdlib.h>
#include "CryptoArchitectureKit/crypto_common.h"
#include "CryptoArchitectureKit/crypto_digest.h"
#define OH_CRYPTO_DIGEST_DATA_MAX (1024 * 1024 * 100)

static OH_Crypto_ErrCode doLoopMd()
{
    OH_Crypto_ErrCode ret;
    OH_CryptoDigest *ctx = nullptr;
    uint8_t *testData = (uint8_t *)malloc(OH_CRYPTO_DIGEST_DATA_MAX);
    if (testData == nullptr) {
        return CRYPTO_MEMORY_ERROR;
    }
    Crypto_DataBlob out = {.data = nullptr, .len = 0};
    int mdLen = 0;
    int isBlockSize = 20;
    int offset = 0;

    ret = OH_CryptoDigest_Create("SHA256", &ctx);
    if (ret != CRYPTO_SUCCESS) {
        return ret;
    }
    do {
        for (int i = 0; i < 640 / isBlockSize; i++) {
            Crypto_DataBlob in = {.data = reinterpret_cast<uint8_t *>(testData + offset),
                                .len = static_cast<size_t>(isBlockSize)};
            ret = OH_CryptoDigest_Update(ctx, &in);
            if (ret != CRYPTO_SUCCESS) {
                break;
            }
            offset += isBlockSize;
        }
        ret = OH_CryptoDigest_Final(ctx, &out);
        if (ret != CRYPTO_SUCCESS) {
            break;
        }
        mdLen = OH_CryptoDigest_GetLength(ctx);
    } while (0);
    OH_Crypto_FreeDataBlob(&out);
    OH_DigestCrypto_Destroy(ctx);
    free(testData);
    return ret;
}
```
