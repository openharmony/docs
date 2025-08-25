# Key Agreement Using ECDH (C/C++)

<!--Kit: Crypto Architecture Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--Designer: @lanming-->
<!--Tester: @PAFT-->
<!--Adviser: @zengyawen-->

For details about the algorithm specifications, see [ECDH](crypto-key-agreement-overview.md#ecdh).

## How to Develop

1. Call [OH_CryptoAsymKeyGenerator_Create](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptoasymkeygenerator_create), [OH_CryptoAsymKeyGenerator_Generate](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptoasymkeygenerator_generate), and [OH_CryptoAsymKeyGenerator_Convert](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptoasymkeygenerator_convert) to generate a 256-bit asymmetric key (**keyPair**) of the ECC type.

   For details about how to generate an ECC asymmetric key pair, see the following example. To learn more, see [ECC](crypto-asym-key-generation-conversion-spec.md#ecc) and [Randomly Generating an Asymmetric Key Pair](crypto-generate-asym-key-pair-randomly-ndk.md). There may be differences between the input parameters in the reference documents and those in the following example.

2. Call [OH_CryptoKeyAgreement_Create](../../reference/apis-crypto-architecture-kit/capi-crypto-key-agreement-h.md#oh_cryptokeyagreement_create) and specify the string parameter **ECC256** to create a key protocol generator of the ECC type with the key length of 256 bits.

3. Call [OH_CryptoKeyAgreement_GenerateSecret](../../reference/apis-crypto-architecture-kit/capi-crypto-key-agreement-h.md#oh_cryptokeyagreement_generatesecret) to perform key agreement based on the passed private key (**keyPair.priKey**) and public key (**keyPair.pubKey**) and return the shared key.

```C++
#include "CryptoArchitectureKit/crypto_architecture_kit.h"
#include "CryptoArchitectureKit/crypto_key_agreement.h"
#include <stdio.h>
#include <cstring>

static OH_Crypto_ErrCode doTestEcdhKeyAgreement()
{
    // The public and private key pair data is transferred from an external system.
    uint8_t pubKeyArray[] = {48, 89, 48, 19, 6, 7, 42, 134, 72, 206, 61, 2, 1, 6, 8, 42, 134, 72, 206, 61, 3, 1, 7,
                            3, 66, 0, 4, 83, 96, 142, 9, 86, 214, 126, 106, 247, 233, 92, 125, 4, 128, 138, 105, 246,
                            162, 215, 71, 81, 58, 202, 121, 26, 105, 211, 55, 130, 45, 236, 143, 55, 16, 248, 75, 167,
                            160, 167, 106, 2, 152, 243, 44, 68, 66, 0, 167, 99, 92, 235, 215, 159, 239, 28, 106, 124,
                            171, 34, 145, 124, 174, 57, 92};
    uint8_t priKeyArray[] = {48, 49, 2, 1, 1, 4, 32, 115, 56, 137, 35, 207, 0, 60, 191, 90, 61, 136, 105, 210, 16,
                            27, 4, 171, 57, 10, 61, 123, 40, 189, 28, 34, 207, 236, 22, 45, 223, 10, 189, 160, 10, 6,
                            8, 42, 134, 72, 206, 61, 3, 1, 7};

    // Create an ECC key generator.
    OH_CryptoAsymKeyGenerator *eccGen = nullptr;
    OH_Crypto_ErrCode ret = OH_CryptoAsymKeyGenerator_Create("ECC256", &eccGen);
    if (ret != CRYPTO_SUCCESS) {
        return ret;
    }

    // Key pair A passed from an external system.
    Crypto_DataBlob pubKeyBlob = {pubKeyArray, sizeof(pubKeyArray)};
    Crypto_DataBlob priKeyBlob = {priKeyArray, sizeof(priKeyArray)};
    OH_CryptoKeyPair *keyPairA = nullptr;
    ret = OH_CryptoAsymKeyGenerator_Convert(eccGen, CRYPTO_DER, &pubKeyBlob, &priKeyBlob, &keyPairA);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoAsymKeyGenerator_Destroy(eccGen);
        return ret;
    }

    // Key pair B generated internally.
    OH_CryptoKeyPair *keyPairB = nullptr;
    ret = OH_CryptoAsymKeyGenerator_Generate(eccGen, &keyPairB);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoKeyPair_Destroy(keyPairA);
        OH_CryptoAsymKeyGenerator_Destroy(eccGen);
        return ret;
    }

    // Create a key agreement generator.
    OH_CryptoKeyAgreement *eccKeyAgreement = nullptr;
    ret = OH_CryptoKeyAgreement_Create("ECC256", &eccKeyAgreement);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoKeyPair_Destroy(keyPairA);
        OH_CryptoKeyPair_Destroy(keyPairB);
        OH_CryptoAsymKeyGenerator_Destroy(eccGen);
        return ret;
    }

    // Use the public key of A and the private key of B to perform key agreement.
    OH_CryptoPrivKey *privKeyB = OH_CryptoKeyPair_GetPrivKey(keyPairB);
    OH_CryptoPubKey *pubKeyA = OH_CryptoKeyPair_GetPubKey(keyPairA);
    Crypto_DataBlob secret1 = { 0 };
    ret = OH_CryptoKeyAgreement_GenerateSecret(eccKeyAgreement, privKeyB, pubKeyA, &secret1);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoKeyAgreement_Destroy(eccKeyAgreement);
        OH_CryptoKeyPair_Destroy(keyPairA);
        OH_CryptoKeyPair_Destroy(keyPairB);
        OH_CryptoAsymKeyGenerator_Destroy(eccGen);
        return ret;
    }

    // Use the private key of A and the public key of B to perform key agreement.
    OH_CryptoPrivKey *privKeyA = OH_CryptoKeyPair_GetPrivKey(keyPairA);
    OH_CryptoPubKey *pubKeyB = OH_CryptoKeyPair_GetPubKey(keyPairB);
    Crypto_DataBlob secret2 = { 0 };
    ret = OH_CryptoKeyAgreement_GenerateSecret(eccKeyAgreement, privKeyA, pubKeyB, &secret2);
    if (ret != CRYPTO_SUCCESS) {
        OH_Crypto_FreeDataBlob(&secret1);
        OH_CryptoKeyAgreement_Destroy(eccKeyAgreement);
        OH_CryptoKeyPair_Destroy(keyPairA);
        OH_CryptoKeyPair_Destroy(keyPairB);
        OH_CryptoAsymKeyGenerator_Destroy(eccGen);
        return ret;
    }

    // Compare the secrets.
    if ((secret1.len == secret2.len) &&
        (memcmp(secret1.data, secret2.data, secret1.len) == 0)) {
        printf("ecdh success\n");
    } else {
        printf("ecdh result is not equal\n");
        ret = CRYPTO_OPERTION_ERROR;
    }

    // Free resources.
    OH_Crypto_FreeDataBlob(&secret1);
    OH_Crypto_FreeDataBlob(&secret2);
    OH_CryptoKeyAgreement_Destroy(eccKeyAgreement);
    OH_CryptoKeyPair_Destroy(keyPairA);
    OH_CryptoKeyPair_Destroy(keyPairB);
    OH_CryptoAsymKeyGenerator_Destroy(eccGen);
    return ret;
}
```
