# Converting SM2 Ciphertext (C/C++)

<!--Kit: Crypto Architecture Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--Designer: @lanming-->
<!--Tester: @PAFT-->
<!--Adviser: @zengyawen-->

The Crypto framework supports the SM2 ciphertext in ASN.1 format. The SM2 ciphertext consists of C1, C3 (the hash value), and C2 (the encrypted data). For details about the specifications, see [SM2 Ciphertext Format](crypto-asym-encrypt-decrypt-spec.md#sm2-ciphertext-format).

You can convert the SM2 ciphertext into ASN.1 format based on the SM2 parameters specified or obtain SM2 parameters from the SM2 ciphertext in ASN.1 format.

**Generating Ciphertext in ASN.1 Format**

1. Call [OH_CryptoSm2CiphertextSpec_Create](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-cipher-h.md#oh_cryptosm2ciphertextspec_create) to create an empty SM2 ciphertext specification object.

2. Call [OH_CryptoSm2CiphertextSpec_SetItem](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-cipher-h.md#oh_cryptosm2ciphertextspec_setitem) to set the ciphertext parameters (**C1.x**,** C1.y**, **C2**, and **C3**).

3. Call [OH_CryptoSm2CiphertextSpec_Encode](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-cipher-h.md#oh_cryptosm2ciphertextspec_encode) to generate ciphertext in ASN.1 format. (Currently, only SM3 ciphertext can be converted. During implementation, the hash length of 32 bytes is verified only.)

4. Call [OH_CryptoSm2CiphertextSpec_Destroy](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-cipher-h.md#oh_cryptosm2ciphertextspec_destroy) to destroy the SM2 ciphertext specification object.

```C++
#include "CryptoArchitectureKit/crypto_architecture_kit.h"

static OH_Crypto_ErrCode doTestGenCipherTextBySpec()
{
    // Prepare SM2 ciphertext parameters.
    uint8_t c1x[] = {45, 153, 88, 82, 104, 221, 226, 43, 174, 21, 122, 248, 5, 232, 105, 41, 92, 95, 102, 224,
                     216, 149, 85, 236, 110, 6, 64, 188, 149, 70, 70, 183};
    uint8_t c1y[] = {107, 93, 198, 247, 119, 18, 40, 110, 90, 156, 193, 158, 205, 113, 170, 128, 146, 109, 75,
                     17, 181, 109, 110, 91, 149, 5, 110, 233, 209, 78, 229, 96};
    uint8_t c2[] = {100, 227, 78, 195, 249, 179, 43, 70, 242, 69, 169, 10, 65, 123};
    uint8_t c3[] = {87, 167, 167, 247, 88, 146, 203, 234, 83, 126, 117, 129, 52, 142, 82, 54, 152, 226, 201, 111,
                    143, 115, 169, 125, 128, 42, 157, 31, 114, 198, 109, 244};

    // Create an empty SM2 ciphertext specification object.
    OH_CryptoSm2CiphertextSpec *sm2CipherSpec = nullptr;
    OH_Crypto_ErrCode ret = OH_CryptoSm2CiphertextSpec_Create(nullptr, &sm2CipherSpec);
    if (ret != CRYPTO_SUCCESS) {
        return ret;
    }

    // Set parameters.
    Crypto_DataBlob c1xBlob = {c1x, sizeof(c1x)};
    Crypto_DataBlob c1yBlob = {c1y, sizeof(c1y)};
    Crypto_DataBlob c2Blob = {c2, sizeof(c2)};
    Crypto_DataBlob c3Blob = {c3, sizeof(c3)};

    ret = OH_CryptoSm2CiphertextSpec_SetItem(sm2CipherSpec, CRYPTO_SM2_CIPHERTEXT_C1_X, &c1xBlob);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoSm2CiphertextSpec_Destroy(sm2CipherSpec);
        return ret;
    }
    ret = OH_CryptoSm2CiphertextSpec_SetItem(sm2CipherSpec, CRYPTO_SM2_CIPHERTEXT_C1_Y, &c1yBlob);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoSm2CiphertextSpec_Destroy(sm2CipherSpec);
        return ret;
    }
    ret = OH_CryptoSm2CiphertextSpec_SetItem(sm2CipherSpec, CRYPTO_SM2_CIPHERTEXT_C2, &c2Blob);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoSm2CiphertextSpec_Destroy(sm2CipherSpec);
        return ret;
    }
    ret = OH_CryptoSm2CiphertextSpec_SetItem(sm2CipherSpec, CRYPTO_SM2_CIPHERTEXT_C3, &c3Blob);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoSm2CiphertextSpec_Destroy(sm2CipherSpec);
        return ret;
    }

    // Encode the ciphertext in ASN.1 format.
    Crypto_DataBlob encoded = { 0 };
    ret = OH_CryptoSm2CiphertextSpec_Encode(sm2CipherSpec, &encoded);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoSm2CiphertextSpec_Destroy(sm2CipherSpec);
        return ret;
    }

    // Free resources.
    OH_Crypto_FreeDataBlob(&encoded);
    OH_CryptoSm2CiphertextSpec_Destroy(sm2CipherSpec);
    return ret;
}
```

**Obtaining Parameters from Ciphertext in ASN.1 Format**

1. Call [OH_CryptoSm2CiphertextSpec_Create](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-cipher-h.md#oh_cryptosm2ciphertextspec_create) to create an SM2 ciphertext specification object from the ASN.1 ciphertext.

2. Call [OH_CryptoSm2CiphertextSpec_GetItem](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-cipher-h.md#oh_cryptosm2ciphertextspec_getitem) to obtain the ciphertext parameters (**C1.x**, **C1.y**, **C2**, and **C3**).

3. Call [OH_CryptoSm2CiphertextSpec_Destroy](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-cipher-h.md#oh_cryptosm2ciphertextspec_destroy) to destroy the SM2 ciphertext specification object.

```C++
static OH_Crypto_ErrCode doTestGetCipherTextSpec()
{
    // Prepare the standard ASN.1 ciphertext.
    uint8_t cipherTextArray[] = {48, 118, 2, 32, 45, 153, 88, 82, 104, 221, 226, 43, 174, 21, 122, 248, 5, 232, 105,
                                41, 92, 95, 102, 224, 216, 149, 85, 236, 110, 6, 64, 188, 149, 70, 70, 183, 2, 32, 107,
                                93, 198, 247, 119, 18, 40, 110, 90, 156, 193, 158, 205, 113, 170, 128, 146, 109, 75, 17,
                                181, 109, 110, 91, 149, 5, 110, 233, 209, 78, 229, 96, 4, 32, 87, 167, 167, 247, 88, 146,
                                203, 234, 83, 126, 117, 129, 52, 142, 82, 54, 152, 226, 201, 111, 143, 115, 169, 125, 128,
                                42, 157, 31, 114, 198, 109, 244, 4, 14, 100, 227, 78, 195, 249, 179, 43, 70, 242, 69, 169,
                                10, 65, 123};
    Crypto_DataBlob cipherText = {cipherTextArray, sizeof(cipherTextArray)};

    // Create an SM2 ciphertext specification object from the ASN.1 ciphertext.
    OH_CryptoSm2CiphertextSpec *sm2CipherSpec = nullptr;
    OH_Crypto_ErrCode ret = OH_CryptoSm2CiphertextSpec_Create(&cipherText, &sm2CipherSpec);
    if (ret != CRYPTO_SUCCESS) {
        return ret;
    }

    // Obtain the parameters.
    Crypto_DataBlob c1x = { 0 };
    Crypto_DataBlob c1y = { 0 };
    Crypto_DataBlob c2 = { 0 };
    Crypto_DataBlob c3 = { 0 };

    ret = OH_CryptoSm2CiphertextSpec_GetItem(sm2CipherSpec, CRYPTO_SM2_CIPHERTEXT_C1_X, &c1x);
    if (ret != CRYPTO_SUCCESS) {
        goto EXIT;
    }
    ret = OH_CryptoSm2CiphertextSpec_GetItem(sm2CipherSpec, CRYPTO_SM2_CIPHERTEXT_C1_Y, &c1y);
    if (ret != CRYPTO_SUCCESS) {
        goto EXIT;
    }
    ret = OH_CryptoSm2CiphertextSpec_GetItem(sm2CipherSpec, CRYPTO_SM2_CIPHERTEXT_C2, &c2);
    if (ret != CRYPTO_SUCCESS) {
        goto EXIT;
    }
    ret = OH_CryptoSm2CiphertextSpec_GetItem(sm2CipherSpec, CRYPTO_SM2_CIPHERTEXT_C3, &c3);
    if (ret != CRYPTO_SUCCESS) {
        goto EXIT;
    }

EXIT:
    OH_Crypto_FreeDataBlob(&c1x);
    OH_Crypto_FreeDataBlob(&c1y);
    OH_Crypto_FreeDataBlob(&c2);
    OH_Crypto_FreeDataBlob(&c3);
    OH_CryptoSm2CiphertextSpec_Destroy(sm2CipherSpec);
    return ret;
}
```
