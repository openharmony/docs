# Key Derivation Using PBKDF2 (C/C++)

<!--Kit: Crypto Architecture Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--Designer: @lanming-->
<!--Tester: @PAFT-->
<!--Adviser: @zengyawen-->

For details about the corresponding algorithm specifications, see [PBKDF2](crypto-key-derivation-overview.md#pbkdf2).

## How to Develop

1. Call [OH_CryptoKdfParams_Create](../../reference/apis-crypto-architecture-kit/capi-crypto-kdf-h.md#oh_cryptokdfparams_create) and specify the string parameter **PBKDF2** to create a key derivation parameter object.

2. Call [OH_CryptoKdfParams_SetParam](../../reference/apis-crypto-architecture-kit/capi-crypto-kdf-h.md#oh_cryptokdfparams_setparam) to set the parameters required by PBKDF2. Example:
   - **CRYPTO_KDF_KEY_DATABLOB**: original password used to generate the derived key.
   - **CRYPTO_KDF_SALT_DATABLOB**: salt value.
   - **CRYPTO_KDF_ITER_COUNT_INT**: number of iterations. The value must be a positive integer.

3. Call [OH_CryptoKdf_Create](../../reference/apis-crypto-architecture-kit/capi-crypto-kdf-h.md#oh_cryptokdf_create) and specify the string parameter **PBKDF2|SHA256** to create a key derivation function object.

4. Call [OH_CryptoKdf_Derive](../../reference/apis-crypto-architecture-kit/capi-crypto-kdf-h.md#oh_cryptokdf_derive) and specify the byte length of the target key.

```C++
#include "CryptoArchitectureKit/crypto_architecture_kit.h"
#include <stdio.h>
#include <string.h>

static OH_Crypto_ErrCode doTestPbkdf2()
{
    // Create a PBKDF2 parameter object.
    OH_CryptoKdfParams *params = nullptr;
    OH_Crypto_ErrCode ret = OH_CryptoKdfParams_Create("PBKDF2", &params);
    if (ret != CRYPTO_SUCCESS) {
        return ret;
    }

    // Set the password.
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

    // Set the salt value.
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

    // Set the number of iterations.
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

    // Create a key derivation function object.
    OH_CryptoKdf *kdfCtx = nullptr;
    ret = OH_CryptoKdf_Create("PBKDF2|SHA256", &kdfCtx);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoKdfParams_Destroy(params);
        return ret;
    }

    // Derive a key.
    Crypto_DataBlob out = {0};
    uint32_t keyLength = 32; // Generate a 32-byte key.
    ret = OH_CryptoKdf_Derive(kdfCtx, params, keyLength, &out);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoKdf_Destroy(kdfCtx);
        OH_CryptoKdfParams_Destroy(params);
        return ret;
    }

    printf("Derived key length: %u\n", out.len);

    // Free resources.
    OH_Crypto_FreeDataBlob(&out);
    OH_CryptoKdf_Destroy(kdfCtx);
    OH_CryptoKdfParams_Destroy(params);
    return CRYPTO_SUCCESS;
}
```
