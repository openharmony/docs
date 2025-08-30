# Key Agreement Using DH (C/C++)

<!--Kit: Crypto Architecture Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--Designer: @lanming-->
<!--Tester: @PAFT-->
<!--Adviser: @zengyawen-->

For details about the algorithm specifications, see [DH](crypto-key-agreement-overview.md#dh).

## How to Develop

1. Call [OH_CryptoAsymKeyGenerator_Create](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptoasymkeygenerator_create) and [OH_CryptoAsymKeyGenerator_Generate](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptoasymkeygenerator_generate) to generate an asymmetric key (**keyPair**) of the DH_modp1536 type.

   For details about how to generate a DH asymmetric key pair, see the following example. To learn more, see [DH](crypto-asym-key-generation-conversion-spec.md#dh) and [Randomly Generating an Asymmetric Key Pair](crypto-generate-asym-key-pair-randomly-ndk.md). There may be differences between the input parameters in the reference documents and those in the following example.

2. Call [OH_CryptoKeyAgreement_Create](../../reference/apis-crypto-architecture-kit/capi-crypto-key-agreement-h.md#oh_cryptokeyagreement_create) and specify the string parameter **DH_modp1536** to create a key protocol generator of the DH_modp1536 type.

3. Call [OH_CryptoKeyAgreement_GenerateSecret](../../reference/apis-crypto-architecture-kit/capi-crypto-key-agreement-h.md#oh_cryptokeyagreement_generatesecret) to perform key agreement based on the passed private key (**keyPair.priKey**) and public key (**keyPair.pubKey**) and return the shared key.

```C++
#include "CryptoArchitectureKit/crypto_architecture_kit.h"
#include "CryptoArchitectureKit/crypto_key_agreement.h"
#include <stdio.h>
#include <cstring>

static OH_Crypto_ErrCode doTestDHKeyAgreement()
{
    // Create a DH key generator.
    OH_CryptoAsymKeyGenerator *dhGen = nullptr;
    OH_Crypto_ErrCode ret = OH_CryptoAsymKeyGenerator_Create("DH_modp1536", &dhGen);
    if (ret != CRYPTO_SUCCESS) {
        return ret;
    }

    // Generate public-private key pair A.
    OH_CryptoKeyPair *keyPairA = nullptr;
    ret = OH_CryptoAsymKeyGenerator_Generate(dhGen, &keyPairA);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoAsymKeyGenerator_Destroy(dhGen);
        return ret;
    }

    // Generate public-private key pair B.
    OH_CryptoKeyPair *keyPairB = nullptr;
    ret = OH_CryptoAsymKeyGenerator_Generate(dhGen, &keyPairB);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoKeyPair_Destroy(keyPairA);
        OH_CryptoAsymKeyGenerator_Destroy(dhGen);
        return ret;
    }

    // Create a key agreement generator.
    OH_CryptoKeyAgreement *dhKeyAgreement = nullptr;
    ret = OH_CryptoKeyAgreement_Create("DH_modp1536", &dhKeyAgreement);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoKeyPair_Destroy(keyPairA);
        OH_CryptoKeyPair_Destroy(keyPairB);
        OH_CryptoAsymKeyGenerator_Destroy(dhGen);
        return ret;
    }

    // Use the public key of A and the private key of B to perform key agreement.
    OH_CryptoPrivKey *privKeyB = OH_CryptoKeyPair_GetPrivKey(keyPairB);
    OH_CryptoPubKey *pubKeyA = OH_CryptoKeyPair_GetPubKey(keyPairA);
    Crypto_DataBlob secret1 = { 0 };
    ret = OH_CryptoKeyAgreement_GenerateSecret(dhKeyAgreement, privKeyB, pubKeyA, &secret1);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoKeyAgreement_Destroy(dhKeyAgreement);
        OH_CryptoKeyPair_Destroy(keyPairA);
        OH_CryptoKeyPair_Destroy(keyPairB);
        OH_CryptoAsymKeyGenerator_Destroy(dhGen);
        return ret;
    }

    // Use the public key of B and the private key of A to perform key agreement.
    OH_CryptoPrivKey *privKeyA = OH_CryptoKeyPair_GetPrivKey(keyPairA);
    OH_CryptoPubKey *pubKeyB = OH_CryptoKeyPair_GetPubKey(keyPairB);
    Crypto_DataBlob secret2 = { 0 };
    ret = OH_CryptoKeyAgreement_GenerateSecret(dhKeyAgreement, privKeyA, pubKeyB, &secret2);
    if (ret != CRYPTO_SUCCESS) {
        OH_Crypto_FreeDataBlob(&secret1);
        OH_CryptoKeyAgreement_Destroy(dhKeyAgreement);
        OH_CryptoKeyPair_Destroy(keyPairA);
        OH_CryptoKeyPair_Destroy(keyPairB);
        OH_CryptoAsymKeyGenerator_Destroy(dhGen);
        return ret;
    }

    // Compare the secrets.
    if ((secret1.len == secret2.len) &&
        (memcmp(secret1.data, secret2.data, secret1.len) == 0)) {
        printf("dh success\n");
    } else {
        printf("dh result is not equal\n");
        ret = CRYPTO_OPERTION_ERROR;
    }

    // Free resources.
    OH_Crypto_FreeDataBlob(&secret1);
    OH_Crypto_FreeDataBlob(&secret2);
    OH_CryptoKeyAgreement_Destroy(dhKeyAgreement);
    OH_CryptoKeyPair_Destroy(keyPairA);
    OH_CryptoKeyPair_Destroy(keyPairB);
    OH_CryptoAsymKeyGenerator_Destroy(dhGen);
    return ret;
}
```
