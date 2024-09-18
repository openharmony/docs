# MD Operation (C/C++)


The message digest (MD) algorithm allows a fixed-length digest to be generated from data of arbitrary size by using the hash algorithm. The MD algorithm is also referred to as a hash algorithm or a one-way hash algorithm.


When the same digest algorithm is used, the generated digest (hash value) has the following features:


- The same message always results in the same hash value.

- The digest generated is of the fixed length no matter the length of messages. (The digest length is determined by the algorithm used).

- It is almost impossible to find two different messages with the same hash value. (The probability still exists, depending on the length of the digest.)


## Supported Algorithms and Specifications

The **Supported Type** column in the following table lists the algorithm to be used when a **Md** instance is created.

| MD Algorithm| Supported Type| API Version| 
| -------- | -------- | -------- |
| HASH | SHA1 | 9+ | 
| HASH | SHA224 | 9+ | 
| HASH | SHA256 | 9+ | 
| HASH | SHA384 | 9+ | 
| HASH | SHA512 | 9+ | 
| HASH | MD5 | 9+ | 
| HASH | SM3 | 10+ | 


## Adding the Dynamic Library in the CMake Script
```txt
   target_link_libraries(entry PUBLIC libohcrypto.so)
```


## How to Develop

During the MD operation, you can use **OH_CryptoDigest_Update()** to pass in all the data at a time or pass in data by segment. For the same piece of data, the result will be the same no matter how the data is passed. Use the appropriate method based on the data size.

The following provides examples of MD operations with different data passing methods.


### MD (Passing In Full Data)

1. Use [OH_CryptoDigest_Create](../../reference/apis-crypto-architecture-kit/_crypto_digest_api.md#oh_cryptodigest_create) with the MD algorithm **SHA256** to generate an MD operation instance ([OH_CryptoDigest](../../reference/apis-crypto-architecture-kit/_crypto_digest_api.md#oh_cryptodigest)).

2. Use [OH_CryptoDigest_Update](../../reference/apis-crypto-architecture-kit/_crypto_digest_api.md#oh_cryptodigest_update) to pass in the data for generating an MD. The amount of data to be passed in by a single **OH_CryptoDigest_Update()** operation is not limited.

3. Use [OH_CryptoDigest_Final](../../reference/apis-crypto-architecture-kit/_crypto_digest_api.md#oh_cryptodigest_final) to generate an MD.

4. Use [OH_CryptoDigest_GetLength](../../reference/apis-crypto-architecture-kit/_crypto_digest_api.md#oh_cryptodigest_getlength) to obtain the MD length, in bytes.

5. Use [OH_DigestCrypto_Destroy](../../reference/apis-crypto-architecture-kit/_crypto_digest_api.md#oh_digestcrypto_destroy) to destroy the [OH_CryptoDigest](../../reference/apis-crypto-architecture-kit/_crypto_digest_api.md#oh_cryptodigest) instance.

**Example**

```c++
#include "CryptoArchitectureKit/crypto_common.h"
#include "CryptoArchitectureKit/crypto_digest.h"

static OH_Crypto_ErrCode doTestMd()
{
    OH_Crypto_ErrCode ret;
    OH_CryptoDigest *ctx = nullptr;
    uint8_t testData[] = "0123456789";
    Crypto_DataBlob in = {.data = reinterpret_cast<uint8_t *>(testData), .len = sizeof(testData)};
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

### MD (Passing In Data by Segment)

1. Use [OH_CryptoDigest_Create](../../reference/apis-crypto-architecture-kit/_crypto_digest_api.md#oh_cryptodigest_create) with the MD algorithm **SHA256** to generate an MD operation instance ([OH_CryptoDigest](../../reference/apis-crypto-architecture-kit/_crypto_digest_api.md#oh_cryptodigest)).

2. Call [OH_CryptoDigest_Update](../../reference/apis-crypto-architecture-kit/_crypto_digest_api.md#oh_cryptodigest_update) multiple times to pass in 20 bytes each time.

3. Use [OH_CryptoDigest_Final](../../reference/apis-crypto-architecture-kit/_crypto_digest_api.md#oh_cryptodigest_final) to generate an MD.

4. Use [OH_CryptoDigest_GetLength](../../reference/apis-crypto-architecture-kit/_crypto_digest_api.md#oh_cryptodigest_getlength) to obtain the MD length, in bytes.

5. Use [OH_DigestCrypto_Destroy](../../reference/apis-crypto-architecture-kit/_crypto_digest_api.md#oh_digestcrypto_destroy) to destroy the [OH_CryptoDigest](../../reference/apis-crypto-architecture-kit/_crypto_digest_api.md#oh_cryptodigest) instance.

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
    return ret;
}
```
