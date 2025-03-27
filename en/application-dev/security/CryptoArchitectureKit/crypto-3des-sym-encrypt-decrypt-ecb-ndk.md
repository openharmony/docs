# Encryption and Decryption with a 3DES Symmetric Key (ECB Mode) (C/C++)

For details about the algorithm specifications, see [3DES](crypto-sym-encrypt-decrypt-spec.md#3des).


## Adding the Dynamic Library in the CMake Script
```txt
target_link_libraries(entry PUBLIC libohcrypto.so)
```

## How to Develop

**Creating an Object**

Call [OH_CryptoSymKeyGenerator_Create](../../reference/apis-crypto-architecture-kit/_crypto_sym_key_api.md#oh_cryptosymkeygenerator_create) and [OH_CryptoSymKeyGenerator_Generate](../../reference/apis-crypto-architecture-kit/_crypto_sym_key_api.md#oh_cryptosymkeygenerator_generate) to generate a 192-bit 3DES symmetric key (**OH_CryptoSymKey**).

In addition to the example in this topic, [3DES](crypto-sym-key-generation-conversion-spec.md#3des) and [Converting Binary Data into a Symmetric Key](crypto-convert-binary-data-to-sym-key-ndk.md) may help you better understand how to generate a 3DES symmetric key pair. Note that the input parameters in the reference documents may be different from those in the example below.


**Encrypting a Message**

1. Call [OH_CryptoSymCipher_Create](../../reference/apis-crypto-architecture-kit/_crypto_sym_cipher_api.md#oh_cryptosymcipher_create) with the string parameter **'3DES192|ECB|PKCS7'** to create a **Cipher** instance for encryption. The key type is **3DES192**, block cipher mode is **ECB**, and the padding mode is **PKCS7**.

2. Call [OH_CryptoSymCipher_Init](../../reference/apis-crypto-architecture-kit/_crypto_sym_cipher_api.md#oh_cryptosymcipher_init) to initialize the **Cipher** instance. Specifically, set **mode** to **CRYPTO_ENCRYPT_MODE**, and specify the key for encryption (**OH_CryptoSymKey**).
   
   If ECB mode is used, set **params** to **null**.

3. Call [OH_CryptoSymCipher_Update](../../reference/apis-crypto-architecture-kit/_crypto_sym_cipher_api.md#oh_cryptosymcipher_update) to update the data (plaintext) to be encrypted.
   
   - If a small amount of data is to be encrypted, you can use **OH_CryptoSymCipher_Final()** immediately after **OH_CryptoSymCipher_Init()**.
   - If a large amount of data is to be encrypted, you can call **OH_CryptoSymCipher_Update** multiple times to pass in the data by segment.

4. Call [OH_CryptoSymCipher_Final](../../reference/apis-crypto-architecture-kit/_crypto_sym_cipher_api.md#oh_cryptosymcipher_final) to generate the ciphertext.
   
   - If **OH_CryptoSymCipher_Update** is used to pass in data, set **data** to **null**. If **OH_CryptoSymCipher_Final** is used to pass in data, pass in the plaintext via **data**.
   - The output of **OH_CryptoSymCipher_Final** may be **null**. To avoid exceptions, always check whether the result is **null** before accessing specific data.


**Decryption**

1. Call [OH_CryptoSymCipher_Create](../../reference/apis-crypto-architecture-kit/_crypto_sym_cipher_api.md#oh_cryptosymcipher_create) with the string parameter **'3DES192|ECB|PKCS7'** to create a **Cipher** instance for decryption. The key type is **3DES192**, block cipher mode is **ECB**, and the padding mode is **PKCS7**.

2. Call [OH_CryptoSymCipher_Init](../../reference/apis-crypto-architecture-kit/_crypto_sym_cipher_api.md#oh_cryptosymcipher_init) to initialize the **Cipher** instance. Specifically, set **mode** to **CRYPTO_DECRYPT_MODE**, and specify the key for decryption (**OH_CryptoSymKey**). When ECB mode is used, pass **null** to **params**.

3. Call [OH_CryptoSymCipher_Update](../../reference/apis-crypto-architecture-kit/_crypto_sym_cipher_api.md#oh_cryptosymcipher_update) to update the data (ciphertext) to be decrypted.
   
   - If a small amount of data is to be encrypted, you can use **OH_CryptoSymCipher_Final()** immediately after **OH_CryptoSymCipher_Init()**.
   - If a large amount of data is to be encrypted, you can call **OH_CryptoSymCipher_Update** multiple times to pass in the data by segment.
   - You can determine the method to use based on the data size. For example, if the data size is greater than 20 bytes, use **OH_CryptoSymCipher_Update**.

4. Call [OH_CryptoSymCipher_Final](../../reference/apis-crypto-architecture-kit/_crypto_sym_cipher_api.md#oh_cryptosymcipher_final) to generate the plaintext.

   - If **OH_CryptoSymCipher_Update** is used to pass in data, set **data** to **null**. If **OH_CryptoSymCipher_Final** is used to pass in data, pass in the ciphertext via **data**.
   - The output of **OH_CryptoSymCipher_Final** may be **null**. To avoid exceptions, always check whether the result is **null** before accessing specific data.

**Destroying Objects**

Call [OH_CryptoSymKeyGenerator_Destroy](../../reference/apis-crypto-architecture-kit/_crypto_sym_key_api.md#oh_cryptosymkeygenerator_destroy), [OH_CryptoSymCipher_Destroy](../../reference/apis-crypto-architecture-kit/_crypto_sym_cipher_api.md#oh_cryptosymcipher_destroy), [OH_CryptoSymKey_Destroy](../../reference/apis-crypto-architecture-kit/_crypto_sym_key_api.md#oh_cryptosymkey_destroy), and [OH_Crypto_FreeDataBlob](../../reference/apis-crypto-architecture-kit/_crypto_common_api.md#oh_crypto_freedatablob) to release the allocated memory and destroy objects.


```c++
#include "CryptoArchitectureKit/crypto_common.h"
#include "CryptoArchitectureKit/crypto_sym_cipher.h"
#include <string.h>

static OH_Crypto_ErrCode doTest3DesEcb()
{
    OH_CryptoSymKeyGenerator *genCtx = nullptr;
    OH_CryptoSymCipher *encCtx = nullptr;
    OH_CryptoSymCipher *decCtx = nullptr;
    OH_CryptoSymKey *keyCtx = nullptr;
    char *plainText = const_cast<char *>("this is test!");
    Crypto_DataBlob input = {.data = (uint8_t *)(plainText), .len = strlen(plainText)};
    Crypto_DataBlob encData = {.data = nullptr, .len = 0};
    Crypto_DataBlob decData = {.data = nullptr, .len = 0};

    // Generate a symmetric key randomly.
    OH_Crypto_ErrCode ret;
    ret = OH_CryptoSymKeyGenerator_Create("3DES192", &genCtx);
    if (ret != CRYPTO_SUCCESS) {
        goto end;
    }
    ret = OH_CryptoSymKeyGenerator_Generate(genCtx, &keyCtx);
    if (ret != CRYPTO_SUCCESS) {
        goto end;
    }

    // Encrypt data.
    ret = OH_CryptoSymCipher_Create("3DES192|ECB|PKCS7", &encCtx);
    if (ret != CRYPTO_SUCCESS) {
        goto end;
    }
    ret = OH_CryptoSymCipher_Init(encCtx, CRYPTO_ENCRYPT_MODE, keyCtx, nullptr);
    if (ret != CRYPTO_SUCCESS) {
        goto end;
    }
    ret = OH_CryptoSymCipher_Final(encCtx, &input, &encData);
    if (ret != CRYPTO_SUCCESS) {
        goto end;
    }

    // Decrypt data.
    ret = OH_CryptoSymCipher_Create("3DES192|ECB|PKCS7", &decCtx);
    if (ret != CRYPTO_SUCCESS) {
        goto end;
    }
    ret = OH_CryptoSymCipher_Init(decCtx, CRYPTO_DECRYPT_MODE, keyCtx, nullptr);
    if (ret != CRYPTO_SUCCESS) {
        goto end;
    }
    ret = OH_CryptoSymCipher_Final(decCtx, &encData, &decData);
    if (ret != CRYPTO_SUCCESS) {
        goto end;
    }

end:
    OH_CryptoSymCipher_Destroy(encCtx);
    OH_CryptoSymCipher_Destroy(decCtx);
    OH_CryptoSymKeyGenerator_Destroy(genCtx);
    OH_CryptoSymKey_Destroy(keyCtx);
    OH_Crypto_FreeDataBlob(&encData);
    OH_Crypto_FreeDataBlob(&decData);
    return ret;
}
```
