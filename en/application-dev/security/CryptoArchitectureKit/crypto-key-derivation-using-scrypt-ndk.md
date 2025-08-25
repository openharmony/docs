# Key Derivation Using Scrypt (C/C++)

<!--Kit: Crypto Architecture Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--Designer: @lanming-->
<!--Tester: @PAFT-->
<!--Adviser: @zengyawen-->

For details about the corresponding algorithm specifications, see [Scrypt](crypto-key-derivation-overview.md#scrypt).

## How to Develop

1. Call [OH_CryptoKdfParams_Create](../../reference/apis-crypto-architecture-kit/capi-crypto-kdf-h.md#oh_cryptokdfparams_create) and specify the string parameter **SCRYPT** to create a key derivation parameter object.

2. Call [OH_CryptoKdfParams_SetParam](../../reference/apis-crypto-architecture-kit/capi-crypto-kdf-h.md#oh_cryptokdfparams_setparam) to set the parameters required by SCRYPT.

When a key derivation failure occurs, check whether the following parameters are set:
   - **CRYPTO_KDF_KEY_DATABLOB**: original password used to generate the derived key.
   - **CRYPTO_KDF_SALT_DATABLOB**: salt value.
   - **CRYPTO_KDF_SCRYPT_N_UINT64**: CPU/memory overhead, which must be a power of 2.
   - **CRYPTO_KDF_SCRYPT_R_UINT64**: block size, which affects the degree of parallelism.
   - **CRYPTO_KDF_SCRYPT_P_UINT64**: parallelization.
   - **CRYPTO_KDF_SCRYPT_MAX_MEM_UINT64**: maximum memory limit (bytes).

3. Call [OH_CryptoKdf_Create](../../reference/apis-crypto-architecture-kit/capi-crypto-kdf-h.md#oh_cryptokdf_create) and specify the string parameter **SCRYPT** to create a key derivation function object.

4. Call [OH_CryptoKdf_Derive](../../reference/apis-crypto-architecture-kit/capi-crypto-kdf-h.md#oh_cryptokdf_derive) and specify the byte length of the target key.

```C++
#include "CryptoArchitectureKit/crypto_architecture_kit.h"
#include "CryptoArchitectureKit/crypto_kdf.h"
#include <stdio.h>
#include <cstring>

static OH_Crypto_ErrCode doTestScrypt()
{
    // Create a SCRYPT parameter object.
    OH_CryptoKdfParams *params = nullptr;
    OH_Crypto_ErrCode ret = OH_CryptoKdfParams_Create("SCRYPT", &params);
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

    // Set SCRYPT parameters.
    uint64_t n = 1024; // CPU/memory overhead.
    uint64_t r = 8; // Block size.
    uint64_t p = 16; // Parallelization.
    uint64_t maxMem = 1067008; // Maximum memory limit (bytes).

    Crypto_DataBlob nData = {
        .data = reinterpret_cast<uint8_t *>(&n),
        .len = sizeof(uint64_t)
    };
    Crypto_DataBlob rData = {
        .data = reinterpret_cast<uint8_t *>(&r),
        .len = sizeof(uint64_t)
    };
    Crypto_DataBlob pData = {
        .data = reinterpret_cast<uint8_t *>(&p),
        .len = sizeof(uint64_t)
    };
    Crypto_DataBlob maxMemData = {
        .data = reinterpret_cast<uint8_t *>(&maxMem),
        .len = sizeof(uint64_t)
    };

    ret = OH_CryptoKdfParams_SetParam(params, CRYPTO_KDF_SCRYPT_N_UINT64, &nData);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoKdfParams_Destroy(params);
        return ret;
    }
    ret = OH_CryptoKdfParams_SetParam(params, CRYPTO_KDF_SCRYPT_R_UINT64, &rData);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoKdfParams_Destroy(params);
        return ret;
    }
    ret = OH_CryptoKdfParams_SetParam(params, CRYPTO_KDF_SCRYPT_P_UINT64, &pData);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoKdfParams_Destroy(params);
        return ret;
    }
    ret = OH_CryptoKdfParams_SetParam(params, CRYPTO_KDF_SCRYPT_MAX_MEM_UINT64, &maxMemData);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoKdfParams_Destroy(params);
        return ret;
    }

    // Create a key derivation function object.
    OH_CryptoKdf *kdfCtx = nullptr;
    ret = OH_CryptoKdf_Create("SCRYPT", &kdfCtx);
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
