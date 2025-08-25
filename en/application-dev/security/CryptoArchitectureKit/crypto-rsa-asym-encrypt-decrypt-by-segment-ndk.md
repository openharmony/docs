# Encryption and Decryption by Segment with an RSA Asymmetric Key Pair (C/C++)

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

4. Call [OH_CryptoAsymCipher_Final](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-cipher-h.md#oh_cryptoasymcipher_final) for multiple times and pass the plaintext to obtain the encrypted data.

   - The output of **OH_CryptoAsymCipher_Final** may be **NULL**. To avoid exceptions, always check whether the result is **NULL** before accessing specific data.

   - In this example, the plaintext is split by 64 bytes and encrypted multiple times by a 1024-bit key. A 128-byte ciphertext is generated each time.
   > **NOTE**
   > Segment-based encryption and decryption of asymmetric keys means that when the plaintext is longer than the data length supported by a single encryption or decryption operation, the data to be encrypted or decrypted needs to be divided into segments of proper length. For details, see [Asymmetric Encryption and Decryption](crypto-encrypt-decrypt-by-segment.md#asymmetric-encryption-and-decryption).

**Decryption**

1. If RSA is used, the **Cipher** instance cannot be initialized repeatedly. Call [OH_CryptoAsymCipher_Create](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-cipher-h.md#oh_cryptoasymcipher_create) to create a new **Cipher** instance.

2. Call [OH_CryptoAsymCipher_Init](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-cipher-h.md#oh_cryptoasymcipher_init) to initialize the **Cipher** instance. Specifically, set **mode** to **CRYPTO_DECRYPT_MODE**, and specify the key for decryption (**keyPair**).

3. Call [OH_CryptoAsymCipher_Final](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-cipher-h.md#oh_cryptoasymcipher_final) for multiple times and pass the ciphertext to obtain the decrypted data.

- Example (using asynchronous APIs):

```C++
#include "CryptoArchitectureKit/crypto_architecture_kit.h"
#include <algorithm>
#include <vector>

static std::vector<uint8_t> doTestRsaEnc(OH_CryptoKeyPair *keyPair, std::vector<uint8_t> &plainText)
{
    std::vector<uint8_t> cipherText;
    OH_CryptoAsymCipher *cipher = nullptr;
    OH_Crypto_ErrCode ret = OH_CryptoAsymCipher_Create("RSA1024|PKCS1", &cipher);
    if (ret != CRYPTO_SUCCESS) {
        return std::vector<uint8_t>{};
    }

    ret = OH_CryptoAsymCipher_Init(cipher, CRYPTO_ENCRYPT_MODE, keyPair);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoAsymCipher_Destroy(cipher);
        return std::vector<uint8_t>{};
    }

    size_t plainTextSplitLen = 64;
    for (size_t i = 0; i < plainText.size(); i += plainTextSplitLen) {
        Crypto_DataBlob in = {};
        in.data = plainText.data() + i;
        if (i + plainTextSplitLen > plainText.size()) {
            in.len = plainText.size() - i;
        } else {
            in.len = plainTextSplitLen;
        }
        Crypto_DataBlob out = {};
        ret = OH_CryptoAsymCipher_Final(cipher, &in, &out);
        if (ret != CRYPTO_SUCCESS) {
            OH_CryptoAsymCipher_Destroy(cipher);
            return std::vector<uint8_t>{};
        }
        cipherText.insert(cipherText.end(), out.data, out.data + out.len);
        OH_Crypto_FreeDataBlob(&out);
    }

    OH_CryptoAsymCipher_Destroy(cipher);
    return cipherText;
}

static std::vector<uint8_t> doTestRsaDec(OH_CryptoKeyPair *keyPair, std::vector<uint8_t> &encryptText)
{
    std::vector<uint8_t> decryptText;
    OH_CryptoAsymCipher *cipher = nullptr;
    OH_Crypto_ErrCode ret = OH_CryptoAsymCipher_Create("RSA1024|PKCS1", &cipher);
    if (ret != CRYPTO_SUCCESS) {
        return std::vector<uint8_t>{};
    }

    ret = OH_CryptoAsymCipher_Init(cipher, CRYPTO_DECRYPT_MODE, keyPair);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoAsymCipher_Destroy(cipher);
        return std::vector<uint8_t>{};
    }

    size_t cipherTextSplitLen = 128; // Length of the ciphertext = Number of key bits/8
    for (size_t i = 0; i < encryptText.size(); i += cipherTextSplitLen) {
        Crypto_DataBlob in = {};
        in.data = encryptText.data() + i;
        if (i + cipherTextSplitLen > encryptText.size()) {
            in.len = encryptText.size() - i;
        } else {
            in.len = cipherTextSplitLen;
        }
        Crypto_DataBlob out = {};
        ret = OH_CryptoAsymCipher_Final(cipher, &in, &out);
        if (ret != CRYPTO_SUCCESS) {
            OH_CryptoAsymCipher_Destroy(cipher);
            return std::vector<uint8_t>{};
        }
        decryptText.insert(decryptText.end(), out.data, out.data + out.len);
        OH_Crypto_FreeDataBlob(&out);
    }

    OH_CryptoAsymCipher_Destroy(cipher);
    return decryptText;
}

static OH_Crypto_ErrCode doTestRsaEncLongMessage()
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

    std::string message =
        "This is a long plainTest! This is a long plainTest! This is a long plainTest!"
        "This is a long plainTest! This is a long plainTest! This is a long plainTest! This is a long plainTest!"
        "This is a long plainTest! This is a long plainTest! This is a long plainTest! This is a long plainTest!"
        "This is a long plainTest! This is a long plainTest! This is a long plainTest! This is a long plainTest!"
        "This is a long plainTest! This is a long plainTest! This is a long plainTest! This is a long plainTest!"
        "This is a long plainTest! This is a long plainTest! This is a long plainTest! This is a long plainTest!"
        "This is a long plainTest! This is a long plainTest! This is a long plainTest! This is a long plainTest!"
        "This is a long plainTest! This is a long plainTest! This is a long plainTest! This is a long plainTest!";

    std::vector<uint8_t> plainText(message.begin(), message.end());
    std::vector<uint8_t> cipherText = doTestRsaEnc(keyPair, plainText);
    std::vector<uint8_t> decryptText = doTestRsaDec(keyPair, cipherText);

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
