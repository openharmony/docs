# Randomly Generating a Symmetric Key (C/C++)

<!--Kit: Crypto Architecture Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--Designer: @lanming-->
<!--Tester: @PAFT-->
<!--Adviser: @zengyawen-->

The following uses AES and SM4 as an example to describe how to randomly generate a symmetric key (**OH_CryptoSymKey**).

The symmetric key (**OH_CryptoSymKey**) object created can be used for subsequent encryption and decryption operations, and the binary data can be used for key storage or transfer.

## Adding the Dynamic Library in the CMake Script
```txt
target_link_libraries(entry PUBLIC libohcrypto.so)
```

## Randomly Generating an AES Key

For details about the algorithm specifications, see [AES](crypto-sym-key-generation-conversion-spec.md#aes).

1. Call [OH_CryptoSymKeyGenerator_Create](../../reference/apis-crypto-architecture-kit/capi-crypto-sym-key-h.md#oh_cryptosymkeygenerator_create) with the string parameter **'AES256'** to create a symmetric key generator (**OH_CryptoSymKeyGenerator**) object for a 256-bit AES key.

2. Call [OH_CryptoSymKeyGenerator_Generate](../../reference/apis-crypto-architecture-kit/capi-crypto-sym-key-h.md#oh_cryptosymkeygenerator_generate) to randomly generate a symmetric key object (**OH_CryptoSymKey**).

3. Call [OH_CryptoSymKey_GetKeyData](../../reference/apis-crypto-architecture-kit/capi-crypto-sym-key-h.md#oh_cryptosymkey_getkeydata) to obtain the binary data of the key object.

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

## Randomly Generating an SM4 Key

For details about the algorithm specifications, see [SM4](crypto-sym-key-generation-conversion-spec.md#sm4).

1. Call [OH_CryptoSymKeyGenerator_Create](../../reference/apis-crypto-architecture-kit/capi-crypto-sym-key-h.md#oh_cryptosymkeygenerator_create) with the string parameter **'SM4_128'** to create a symmetric key generator (**OH_CryptoSymKeyGenerator**) object for a 128-bit SM4 key.

2. Call [OH_CryptoSymKeyGenerator_Generate](../../reference/apis-crypto-architecture-kit/capi-crypto-sym-key-h.md#oh_cryptosymkeygenerator_generate) to randomly generate a symmetric key object (**OH_CryptoSymKey**).

3. Call [OH_CryptoSymKey_GetKeyData](../../reference/apis-crypto-architecture-kit/capi-crypto-sym-key-h.md#oh_cryptosymkey_getkeydata) to obtain the binary data of the key object.

```c++
#include "CryptoArchitectureKit/crypto_common.h"
#include "CryptoArchitectureKit/crypto_sym_key.h"

static OH_Crypto_ErrCode testGenerateSM4Key()
{
    OH_CryptoSymKeyGenerator *ctx = nullptr;
    OH_CryptoSymKey *keyCtx = nullptr;
    Crypto_DataBlob out = {.data = nullptr, .len = 0}; // Binary data of the symmetric key.
    OH_Crypto_ErrCode ret = OH_CryptoSymKeyGenerator_Create("SM4_128", &ctx); // Create a symmetric key generator.
    if (ret != CRYPTO_SUCCESS) {
        return ret;
    }
    ret = OH_CryptoSymKeyGenerator_Generate(ctx, &keyCtx); // Randomly generate a symmetric key object.
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoSymKeyGenerator_Destroy(ctx);
        return ret;
    }
    ret = OH_CryptoSymKey_GetKeyData(keyCtx, &out); // Obtain the binary data of the symmetric key object.
    OH_CryptoSymKeyGenerator_Destroy(ctx);
    OH_CryptoSymKey_Destroy(keyCtx);
    if (ret != CRYPTO_SUCCESS) {
        return ret;
    }
    OH_Crypto_FreeDataBlob(&out);
    return ret;
}
```
