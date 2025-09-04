# Encryption and Decryption with an RSA Asymmetric Key Pair (PKCS1) (C/C++)

<!--Kit: Crypto Architecture Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--Designer: @lanming-->
<!--Tester: @PAFT-->
<!--Adviser: @zengyawen-->

For details about the algorithm specifications, see [RSA](crypto-asym-encrypt-decrypt-spec.md#rsa).

**Encryption**

1. Call [OH_CryptoAsymKeyGenerator_Create](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptoasymkeygenerator_create) and [OH_CryptoAsymKeyGenerator_Generate](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptoasymkeygenerator_generate) to generate an asymmetric key pair (**keyPair**) of the RSA1024 type with two prime numbers. The **keyPair** object includes a public key (**PubKey**) and a private key (**PriKey**).

   For details about how to generate an RSA asymmetric key pair, see the following example. To learn more, see [RSA](crypto-asym-key-generation-conversion-spec.md#rsa) and [Randomly Generating an Asymmetric Key Pair](crypto-generate-asym-key-pair-randomly.md). There may be differences between the input parameters in the reference documents and those in the following example.

2. Call [OH_CryptoAsymCipher_Create](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-cipher-h.md#oh_cryptoasymcipher_create) with the string parameter **'RSA1024|PKCS1'** to create a **Cipher** instance for encryption. The key type is **RSA1024**, and the padding mode is **PKCS1**.

3. Call [OH_CryptoAsymCipher_Init](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-cipher-h.md#oh_cryptoasymcipher_init) to initialize the **Cipher** instance. Specifically, set **mode** to **CRYPTO_ENCRYPT_MODE**, and specify the key for encryption (**keyPair**).

4. Call [OH_CryptoAsymCipher_Final](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-cipher-h.md#oh_cryptoasymcipher_final) and pass the plaintext to obtain the encrypted data.

   - The output of **OH_CryptoAsymCipher_Final** may be **NULL**. To avoid exceptions, always check whether the result is **NULL** before accessing specific data.
   - If the data to be encrypted is considerably long, you can call **OH_CryptoAsymCipher_Final** multiple times to [pass in and encrypt the data by segment](crypto-rsa-asym-encrypt-decrypt-by-segment-ndk.md).

**Decryption**

1. If RSA is used, the **Cipher** instance cannot be initialized repeatedly. Call [OH_CryptoAsymCipher_Create](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-cipher-h.md#oh_cryptoasymcipher_create) to create a new **Cipher** instance.

2. Call [OH_CryptoAsymCipher_Init](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-cipher-h.md#oh_cryptoasymcipher_init) to initialize the **Cipher** instance. Specifically, set **mode** to **CRYPTO_DECRYPT_MODE**, and specify the key for decryption (**keyPair**).

3. Call [OH_CryptoAsymCipher_Final](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-cipher-h.md#oh_cryptoasymcipher_final) and pass the ciphertext to obtain the decrypted data.

```C++
#include "CryptoArchitectureKit/crypto_architecture_kit.h"

static OH_Crypto_ErrCode doTestRsaEncDec()
{
    OH_CryptoAsymKeyGenerator *keyGen = nullptr;
    OH_Crypto_ErrCode ret = OH_CryptoAsymKeyGenerator_Create("RSA1024", &keyGen);
    if (ret != CRYPTO_SUCCESS) {
        return ret;
    }

    OH_CryptoKeyPair *keyPair = nullptr;
    ret = OH_CryptoAsymKeyGenerator_Generate(keyGen, &keyPair);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoAsymKeyGenerator_Destroy(keyGen);
        return ret;
    }

    OH_CryptoAsymCipher *cipher = nullptr;
    ret = OH_CryptoAsymCipher_Create("RSA1024|PKCS1", &cipher);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoKeyPair_Destroy(keyPair);
        OH_CryptoAsymKeyGenerator_Destroy(keyGen);
        return ret;
    }

    ret = OH_CryptoAsymCipher_Init(cipher, CRYPTO_ENCRYPT_MODE, keyPair);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoAsymCipher_Destroy(cipher);
        OH_CryptoKeyPair_Destroy(keyPair);
        OH_CryptoAsymKeyGenerator_Destroy(keyGen);
        return ret;
    }

    const char *testData = "Hello, RSA!";
    Crypto_DataBlob in = {
        .data = (uint8_t *)testData,
        .len = strlen(testData)
    };

    Crypto_DataBlob out = { 0 };
    ret = OH_CryptoAsymCipher_Final(cipher, &in, &out);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoAsymCipher_Destroy(cipher);
        OH_CryptoKeyPair_Destroy(keyPair);
        OH_CryptoAsymKeyGenerator_Destroy(keyGen);
        return ret;
    }

    OH_CryptoAsymCipher_Destroy(cipher);
    cipher = nullptr;
    ret = OH_CryptoAsymCipher_Create("RSA1024|PKCS1", &cipher);
    if (ret != CRYPTO_SUCCESS) {
        OH_Crypto_FreeDataBlob(&out);
        OH_CryptoKeyPair_Destroy(keyPair);
        OH_CryptoAsymKeyGenerator_Destroy(keyGen);
        return ret;
    }

    ret = OH_CryptoAsymCipher_Init(cipher, CRYPTO_DECRYPT_MODE, keyPair);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoAsymCipher_Destroy(cipher);
        OH_Crypto_FreeDataBlob(&out);
        OH_CryptoKeyPair_Destroy(keyPair);
        OH_CryptoAsymKeyGenerator_Destroy(keyGen);
        return ret;
    }
    Crypto_DataBlob decrypted = { 0 };
    ret = OH_CryptoAsymCipher_Final(cipher, &out, &decrypted);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoAsymCipher_Destroy(cipher);
        OH_Crypto_FreeDataBlob(&out);
        OH_CryptoKeyPair_Destroy(keyPair);
        OH_CryptoAsymKeyGenerator_Destroy(keyGen);
        return ret;
    }
    if ((decrypted.len != strlen(testData)) || (memcmp(decrypted.data, testData, decrypted.len) != 0)) {
        OH_Crypto_FreeDataBlob(&decrypted);
        OH_CryptoAsymCipher_Destroy(cipher);
        OH_Crypto_FreeDataBlob(&out);
        OH_CryptoKeyPair_Destroy(keyPair);
        OH_CryptoAsymKeyGenerator_Destroy(keyGen);
        return CRYPTO_OPERTION_ERROR;
    }

    OH_Crypto_FreeDataBlob(&decrypted);
    OH_CryptoAsymCipher_Destroy(cipher);
    OH_Crypto_FreeDataBlob(&out);
    OH_CryptoKeyPair_Destroy(keyPair);
    OH_CryptoAsymKeyGenerator_Destroy(keyGen);
    return ret;
}
```
