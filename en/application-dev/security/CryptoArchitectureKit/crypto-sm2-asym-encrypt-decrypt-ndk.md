# Encryption and Decryption with an SM2 Asymmetric Key Pair (C/C++)

<!--Kit: Crypto Architecture Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--Designer: @lanming-->
<!--Tester: @PAFT-->
<!--Adviser: @zengyawen-->

For details about the algorithm specifications, see [SM2](crypto-asym-encrypt-decrypt-spec.md#sm2).

**Encryption**

1. Call [OH_CryptoAsymKeyGenerator_Create](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptoasymkeygenerator_create) and [OH_CryptoAsymKeyGenerator_Generate](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptoasymkeygenerator_generate) to generate an asymmetric key pair (**keyPair**) of the SM2_256 type. The **keyPair** object includes a public key (**PubKey**) and a private key (**PriKey**).

   For details about how to generate an SM2 asymmetric key pair, see the following example. To learn more, see [SM2](crypto-asym-key-generation-conversion-spec.md#sm2) and [Randomly Generating an Asymmetric Key Pair](crypto-generate-asym-key-pair-randomly-ndk.md). There may be differences between the input parameters in the reference documents and those in the following example.

2. Call [OH_CryptoAsymCipher_Create](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-cipher-h.md#oh_cryptoasymcipher_create) with the string parameter **'SM2_256|SM3'** to create a **Cipher** instance for encryption. The key type is **SM2_256**, and the digest algorithm is **SM3**.

3. Call [OH_CryptoAsymCipher_Init](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-cipher-h.md#oh_cryptoasymcipher_init) to initialize the **Cipher** instance. Specifically, set **mode** to **CRYPTO_ENCRYPT_MODE**, and specify the key for encryption (**keyPair**).

4. Call [OH_CryptoAsymCipher_Final](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-cipher-h.md#oh_cryptoasymcipher_final) and pass the plaintext to obtain the encrypted data.

   The output of **OH_CryptoAsymCipher_Final** may be **NULL**. To avoid exceptions, always check whether the result is **NULL** before accessing specific data.

**Decryption**

1. If SM2 is used, the **Cipher** instance cannot be initialized repeatedly. Call [OH_CryptoAsymCipher_Create](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-cipher-h.md#oh_cryptoasymcipher_create) to create a new **Cipher** instance.

2. Call [OH_CryptoAsymCipher_Init](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-cipher-h.md#oh_cryptoasymcipher_init) to initialize the **Cipher** instance. Specifically, set **mode** to **CRYPTO_DECRYPT_MODE**, and specify the key for decryption (**keyPair**).

3. Call [OH_CryptoAsymCipher_Final](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-cipher-h.md#oh_cryptoasymcipher_final) and pass the ciphertext to obtain the decrypted data.

```C++
#include "CryptoArchitectureKit/crypto_architecture_kit.h"
#include <algorithm>
#include <vector>
#include <string>

static std::vector<uint8_t> doTestSm2Enc(OH_CryptoKeyPair *keyPair, std::vector<uint8_t> &plainText)
{
    std::vector<uint8_t> cipherText;
    OH_CryptoAsymCipher *cipher = nullptr;
    OH_Crypto_ErrCode ret = OH_CryptoAsymCipher_Create("SM2_256|SM3", &cipher);
    if (ret != CRYPTO_SUCCESS) {
        return std::vector<uint8_t>{};
    }

    ret = OH_CryptoAsymCipher_Init(cipher, CRYPTO_ENCRYPT_MODE, keyPair);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoAsymCipher_Destroy(cipher);
        return std::vector<uint8_t>{};
    }

    Crypto_DataBlob in = {};
    in.data = plainText.data();
    in.len = plainText.size();
    Crypto_DataBlob out = {};
    ret = OH_CryptoAsymCipher_Final(cipher, &in, &out);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoAsymCipher_Destroy(cipher);
        return std::vector<uint8_t>{};
    }
    cipherText.insert(cipherText.end(), out.data, out.data + out.len);
    OH_Crypto_FreeDataBlob(&out);

    OH_CryptoAsymCipher_Destroy(cipher);
    return cipherText;
}

static std::vector<uint8_t> doTestSm2Dec(OH_CryptoKeyPair *keyPair, std::vector<uint8_t> &encryptText)
{
    std::vector<uint8_t> decryptText;
    OH_CryptoAsymCipher *cipher = nullptr;
    OH_Crypto_ErrCode ret = OH_CryptoAsymCipher_Create("SM2_256|SM3", &cipher);
    if (ret != CRYPTO_SUCCESS) {
        return std::vector<uint8_t>{};
    }

    ret = OH_CryptoAsymCipher_Init(cipher, CRYPTO_DECRYPT_MODE, keyPair);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoAsymCipher_Destroy(cipher);
        return std::vector<uint8_t>{};
    }

    Crypto_DataBlob in = {};
    in.data = encryptText.data();
    in.len = encryptText.size();
    Crypto_DataBlob out = {};
    ret = OH_CryptoAsymCipher_Final(cipher, &in, &out);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoAsymCipher_Destroy(cipher);
        return std::vector<uint8_t>{};
    }
    decryptText.insert(decryptText.end(), out.data, out.data + out.len);
    OH_Crypto_FreeDataBlob(&out);

    OH_CryptoAsymCipher_Destroy(cipher);
    return decryptText;
}

static OH_Crypto_ErrCode doTestSm2EncMessage()
{
    OH_CryptoAsymKeyGenerator *keyGen = nullptr;
    OH_Crypto_ErrCode ret = OH_CryptoAsymKeyGenerator_Create("SM2_256", &keyGen);
    if (ret != CRYPTO_SUCCESS) {
        return ret;
    }
    OH_CryptoKeyPair *keyPair = nullptr;
    ret = OH_CryptoAsymKeyGenerator_Generate(keyGen, &keyPair);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoAsymKeyGenerator_Destroy(keyGen);
        return ret;
    }

    std::string message = "This is a test";
    std::vector<uint8_t> plainText(message.begin(), message.end());
    std::vector<uint8_t> cipherText = doTestSm2Enc(keyPair, plainText);
    std::vector<uint8_t> decryptText = doTestSm2Dec(keyPair, cipherText);

    if ((plainText.size() != decryptText.size()) ||
        (!std::equal(plainText.begin(), plainText.end(), decryptText.begin()))) {
        OH_CryptoKeyPair_Destroy(keyPair);
        OH_CryptoAsymKeyGenerator_Destroy(keyGen);
        return CRYPTO_OPERTION_ERROR;
    }

    OH_CryptoKeyPair_Destroy(keyPair);
    OH_CryptoAsymKeyGenerator_Destroy(keyGen);
    return CRYPTO_SUCCESS;
}
```
