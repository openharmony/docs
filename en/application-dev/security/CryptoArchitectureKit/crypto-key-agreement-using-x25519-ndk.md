# Key Agreement Using X25519 (C/C++)

<!--Kit: Crypto Architecture Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--Designer: @lanming-->
<!--Tester: @PAFT-->
<!--Adviser: @zengyawen-->

For details about the algorithm specifications, see [X25519](crypto-key-agreement-overview.md#x25519).

## How to Develop

1. Call [OH_CryptoAsymKeyGenerator_Create](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptoasymkeygenerator_create), [OH_CryptoAsymKeyGenerator_Generate](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptoasymkeygenerator_generate), and [OH_CryptoAsymKeyGenerator_Convert](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptoasymkeygenerator_convert) to generate an asymmetric key (**keyPair**) of the X25519 type.

   For details about how to generate an X25519 asymmetric key pair, see the following example. To learn more, see [X25519](crypto-asym-key-generation-conversion-spec.md#x25519) and [Randomly Generating an Asymmetric Key Pair](crypto-generate-asym-key-pair-randomly-ndk.md). There may be differences between the input parameters in the reference documents and those in the following example.

2. Call [OH_CryptoKeyAgreement_Create](../../reference/apis-crypto-architecture-kit/capi-crypto-key-agreement-h.md#oh_cryptokeyagreement_create) and specify the string parameter **X25519** to create a key protocol generator of the X25519 type.

3. Call [OH_CryptoKeyAgreement_GenerateSecret](../../reference/apis-crypto-architecture-kit/capi-crypto-key-agreement-h.md#oh_cryptokeyagreement_generatesecret) to perform key agreement based on the passed private key (**keyPair.priKey**) and public key (**keyPair.pubKey**) and return the shared key.

```C++
#include "CryptoArchitectureKit/crypto_architecture_kit.h"
#include "CryptoArchitectureKit/crypto_key_agreement.h"
#include <stdio.h>
#include <cstring>

static OH_Crypto_ErrCode doTestX25519KeyAgreement()
{
    uint8_t pubKeyArray[] = {48, 42, 48, 5, 6, 3, 43, 101, 110, 3, 33, 0, 36, 98, 216, 106, 74, 99, 179, 203, 81, 145,
                             147, 101, 139, 57, 74, 225, 119, 196, 207, 0, 50, 232, 93, 147, 188, 21, 225, 228, 54, 251,
                             230, 52};
    uint8_t priKeyArray[] = {48, 46, 2, 1, 0, 48, 5, 6, 3, 43, 101, 110, 4, 34, 4, 32, 112, 65, 156, 73, 65, 89, 183,
                             39, 119, 229, 110, 12, 192, 237, 186, 153, 21, 122, 28, 176, 248, 108, 22, 242, 239, 179,
                             106, 175, 85, 65, 214, 90};
    // Create an X25519 key generator.
    OH_CryptoAsymKeyGenerator *x25519Gen = nullptr;
    OH_Crypto_ErrCode ret = OH_CryptoAsymKeyGenerator_Create("X25519", &x25519Gen);
    if (ret != CRYPTO_SUCCESS) {
        return ret;
    }

    // Key pair A passed from an external system.
    Crypto_DataBlob pubKeyBlob = {pubKeyArray, sizeof(pubKeyArray)};
    Crypto_DataBlob priKeyBlob = {priKeyArray, sizeof(priKeyArray)};
    OH_CryptoKeyPair *keyPairA = nullptr;
    ret = OH_CryptoAsymKeyGenerator_Convert(x25519Gen, CRYPTO_DER, &pubKeyBlob, &priKeyBlob, &keyPairA);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoAsymKeyGenerator_Destroy(x25519Gen);
        return ret;
    }

    // Key pair B generated internally.
    OH_CryptoKeyPair *keyPairB = nullptr;
    ret = OH_CryptoAsymKeyGenerator_Generate(x25519Gen, &keyPairB);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoKeyPair_Destroy(keyPairA);
        OH_CryptoAsymKeyGenerator_Destroy(x25519Gen);
        return ret;
    }

    // Create a key agreement generator.
    OH_CryptoKeyAgreement *x25519KeyAgreement = nullptr;
    ret = OH_CryptoKeyAgreement_Create("X25519", &x25519KeyAgreement);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoKeyPair_Destroy(keyPairA);
        OH_CryptoKeyPair_Destroy(keyPairB);
        OH_CryptoAsymKeyGenerator_Destroy(x25519Gen);
        return ret;
    }

    // Use the public key of A and the private key of B to perform key agreement.
    OH_CryptoPrivKey *privKeyB = OH_CryptoKeyPair_GetPrivKey(keyPairB);
    OH_CryptoPubKey *pubKeyA = OH_CryptoKeyPair_GetPubKey(keyPairA);
    Crypto_DataBlob secret1 = {0};
    ret = OH_CryptoKeyAgreement_GenerateSecret(x25519KeyAgreement, privKeyB, pubKeyA, &secret1);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoKeyAgreement_Destroy(x25519KeyAgreement);
        OH_CryptoKeyPair_Destroy(keyPairA);
        OH_CryptoKeyPair_Destroy(keyPairB);
        OH_CryptoAsymKeyGenerator_Destroy(x25519Gen);
        return ret;
    }

    // Use the private key of A and the public key of B to perform key agreement.
    OH_CryptoPrivKey *privKeyA = OH_CryptoKeyPair_GetPrivKey(keyPairA);
    OH_CryptoPubKey *pubKeyB = OH_CryptoKeyPair_GetPubKey(keyPairB);
    Crypto_DataBlob secret2 = {0};
    ret = OH_CryptoKeyAgreement_GenerateSecret(x25519KeyAgreement, privKeyA, pubKeyB, &secret2);
    if (ret != CRYPTO_SUCCESS) {
        OH_Crypto_FreeDataBlob(&secret1);
        OH_CryptoKeyAgreement_Destroy(x25519KeyAgreement);
        OH_CryptoKeyPair_Destroy(keyPairA);
        OH_CryptoKeyPair_Destroy(keyPairB);
        OH_CryptoAsymKeyGenerator_Destroy(x25519Gen);
        return ret;
    }

    // Compare the secrets.
    if ((secret1.len == secret2.len) && (memcmp(secret1.data, secret2.data, secret1.len) == 0)) {
        printf("x25519 success\n");
    } else {
        printf("x25519 result is not equal\n");
        ret = CRYPTO_OPERTION_ERROR;
    }

    // Free resources.
    OH_Crypto_FreeDataBlob(&secret1);
    OH_Crypto_FreeDataBlob(&secret2);
    OH_CryptoKeyAgreement_Destroy(x25519KeyAgreement);
    OH_CryptoKeyPair_Destroy(keyPairA);
    OH_CryptoKeyPair_Destroy(keyPairB);
    OH_CryptoAsymKeyGenerator_Destroy(x25519Gen);
    return ret;
}
```
