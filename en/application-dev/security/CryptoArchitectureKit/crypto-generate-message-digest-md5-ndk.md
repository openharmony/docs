# Generating an MD Using MD5 (C/C++)

For details about the algorithm specifications, see [Supported Algorithms and Specifications](crypto-generate-message-digest-overview.md#supported-algorithms-and-specifications).

## Adding the Dynamic Library in the CMake Script
```txt
target_link_libraries(entry PUBLIC libohcrypto.so)
```


## How to Develop

During the MD operation, you can [pass in all the data at a time](#generating-an-md-by-passing-in-full-data) or [pass in data by segment](#generating-an-md-by-passing-in-data-by-segment). For the same piece of data, the result will be the same no matter how the data is passed. Use the appropriate method based on the data size.

The following provides examples of MD operations with different data passing methods.


### Generating an MD by Passing In Full Data

1. Call [OH_CryptoDigest_Create](../../reference/apis-crypto-architecture-kit/_crypto_digest_api.md#oh_cryptodigest_create) with the MD algorithm **MD5** to generate an MD operation instance (**OH_CryptoDigest**).

2. Call [OH_CryptoDigest_Update](../../reference/apis-crypto-architecture-kit/_crypto_digest_api.md#oh_cryptodigest_update) to pass in the data for generating an MD. The amount of data to be passed in by a single **Md.update()** call is not limited.

3. Call [OH_CryptoDigest_Final](../../reference/apis-crypto-architecture-kit/_crypto_digest_api.md#oh_cryptodigest_final) to generate an MD.

4. Call [OH_CryptoDigest_GetLength](../../reference/apis-crypto-architecture-kit/_crypto_digest_api.md#oh_cryptodigest_getlength) to obtain the MD length, in bytes.

5. Call [OH_DigestCrypto_Destroy](../../reference/apis-crypto-architecture-kit/_crypto_digest_api.md#oh_digestcrypto_destroy) to destroy the **OH_CryptoDigest** instance.

**Example**

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
    ret = OH_CryptoDigest_Create("MD5", &ctx);
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

### Generating an MD by Passing In Data by Segment

1. Call [OH_CryptoDigest_Create](../../reference/apis-crypto-architecture-kit/_crypto_digest_api.md#oh_cryptodigest_create) with the MD algorithm **MD5** to generate an MD operation instance (**OH_CryptoDigest**).

2. Call [OH_CryptoDigest_Update](../../reference/apis-crypto-architecture-kit/_crypto_digest_api.md#oh_cryptodigest_update) multiple times to pass in 20 bytes each time.

3. Call [OH_CryptoDigest_Final](../../reference/apis-crypto-architecture-kit/_crypto_digest_api.md#oh_cryptodigest_final) to generate an MD.

4. Call [OH_CryptoDigest_GetLength](../../reference/apis-crypto-architecture-kit/_crypto_digest_api.md#oh_cryptodigest_getlength) to obtain the MD length, in bytes.

5. Call [OH_DigestCrypto_Destroy](../../reference/apis-crypto-architecture-kit/_crypto_digest_api.md#oh_digestcrypto_destroy) to destroy the **OH_CryptoDigest** instance.

**Example**

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
    Crypto_DataBlob out = {.data = nullptr, .len = 0};
    int mdLen = 0;
    int isBlockSize = 20;
    int offset = 0;

    ret = OH_CryptoDigest_Create("MD5", &ctx);
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
    return ret;
}
```
