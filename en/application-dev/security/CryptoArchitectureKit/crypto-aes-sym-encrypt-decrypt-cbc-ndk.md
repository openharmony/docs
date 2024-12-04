# Encryption and Decryption with an AES Symmetric Key (CBC Mode) (C/C++)


For details about the algorithm specifications, see [AES](crypto-sym-encrypt-decrypt-spec.md#aes).


## Adding the Dynamic Library in the CMake Script
```txt
   target_link_libraries(entry PUBLIC libohcrypto.so)
```

## How to Develop


**Encryption**

1. Use [OH_CryptoSymKeyGenerator_Create](../../reference/apis-crypto-architecture-kit/_crypto_sym_key_api.md#oh_cryptosymkeygenerator_create) and [OH_CryptoSymKeyGenerator_Generate](../../reference/apis-crypto-architecture-kit/_crypto_sym_key_api.md#oh_cryptosymkeygenerator_generate) to generate a 128-bit AES symmetric key (**OH_CryptoSymKey**).
   
   In addition to the example in this topic, [AES](crypto-sym-key-generation-conversion-spec.md#aes) and [Randomly Generating a Symmetric Key](crypto-generate-sym-key-randomly-ndk.md) may help you better understand how to generate an AES symmetric key. Note that the input parameters in the reference documents may be different from those in the example below.

2. Use [OH_CryptoSymCipher_Create](../../reference/apis-crypto-architecture-kit/_crypto_sym_cipher_api.md#oh_cryptosymcipher_create) with the string parameter **'AES128|CBC|PKCS7'** to create a **Cipher** instance. The key type is **AES128**, block cipher mode is **CBC**, and the padding mode is **PKCS7**.

3. Use [OH_CryptoSymCipherParams_Create](../../reference/apis-crypto-architecture-kit/_crypto_sym_cipher_api.md#oh_cryptosymcipherparams_create) to create a symmetric cipher parameter instance, and use [OH_CryptoSymCipherParams_SetParam](../../reference/apis-crypto-architecture-kit/_crypto_sym_cipher_api.md#oh_cryptosymcipherparams_setparam) to set cipher parameters.

4. Use [OH_CryptoSymCipher_Init](../../reference/apis-crypto-architecture-kit/_crypto_sym_cipher_api.md#oh_cryptosymcipher_init) to initialize the **Cipher** instance. Specifically, set **mode** to **CRYPTO_ENCRYPT_MODE**, and specify the key for encryption (**OH_CryptoSymKey**) and the encryption parameter instance (**OH_CryptoSymCipherParams**) corresponding to the CBC mode.

5. If a small amount of data is to be encrypted, use [OH_CryptoSymCipher_Final](../../reference/apis-crypto-architecture-kit/_crypto_sym_cipher_api.md#oh_cryptosymcipher_final) to generate the encrypted data. If a large amount of data is to be encrypted, you can call [OH_CryptoSymCipher_Update](../../reference/apis-crypto-architecture-kit/_crypto_sym_cipher_api.md#oh_cryptosymcipher_update) multiple times to pass in the data by segment, and then use **OH_CryptoSymCipher_Final** to generate the ciphertext. 

6. Use [OH_CryptoSymKeyGenerator_Destroy](../../reference/apis-crypto-architecture-kit/_crypto_sym_key_api.md#oh_cryptosymkeygenerator_destroy), [OH_CryptoSymCipher_Destroy](../../reference/apis-crypto-architecture-kit/_crypto_sym_cipher_api.md#oh_cryptosymcipher_destroy), and [OH_CryptoSymCipherParams_Destroy](../../reference/apis-crypto-architecture-kit/_crypto_sym_cipher_api.md#oh_cryptosymcipherparams_destroy) to destroy the instances created.


**Decryption**


1. Use [OH_CryptoSymCipher_Init](../../reference/apis-crypto-architecture-kit/_crypto_sym_cipher_api.md#oh_cryptosymcipher_init) to initialize the **Cipher** instance. Specifically, set **mode** to **CRYPTO_DECRYPT_MODE**, and specify the key for decryption (**OH_CryptoSymKey**) and the decryption parameter instance (**OH_CryptoSymCipherParams**) corresponding to the CBC mode.

2. If a small amount of data is to be decrypted, use [OH_CryptoSymCipher_Final](../../reference/apis-crypto-architecture-kit/_crypto_sym_cipher_api.md#oh_cryptosymcipher_final) to generate the decrypted data. If a large amount of data is to be decrypted, you can call [OH_CryptoSymCipher_Update](../../reference/apis-crypto-architecture-kit/_crypto_sym_cipher_api.md#oh_cryptosymcipher_update) multiple times to pass in the data by segment, and then use **OH_CryptoSymCipher_Final** to generate the plaintext.



```c++
#include "CryptoArchitectureKit/crypto_common.h"
#include "CryptoArchitectureKit/crypto_sym_cipher.h"
#include <string.h>

static OH_Crypto_ErrCode doTestAesCbc()
{
    OH_CryptoSymKeyGenerator *genCtx = nullptr;
    OH_CryptoSymCipher *encCtx = nullptr;
    OH_CryptoSymCipher *decCtx = nullptr;
    OH_CryptoSymKey *keyCtx = nullptr;
    OH_CryptoSymCipherParams *params = nullptr;
    Crypto_DataBlob outUpdate = {.data = nullptr, .len = 0};
    Crypto_DataBlob decUpdate = {.data = nullptr, .len = 0};
    char *plainText = const_cast<char *>("this is test!");
    Crypto_DataBlob msgBlob = {.data = (uint8_t *)(plainText), .len = strlen(plainText)};
    uint8_t iv[16] = {1, 2, 4, 12, 3, 4, 2, 3, 3, 2, 0, 4, 3, 1, 0, 10}; // iv is generated from an array of secure random numbers.
    Crypto_DataBlob ivBlob = {.data = iv, .len = sizeof(iv)};
    // Generate a symmetric key.
    OH_Crypto_ErrCode ret;
    ret = OH_CryptoSymKeyGenerator_Create("AES128", &genCtx);
    if (ret != CRYPTO_SUCCESS) {
        goto end;
    }
    ret = OH_CryptoSymKeyGenerator_Generate(genCtx, &keyCtx);
    if (ret != CRYPTO_SUCCESS) {
        goto end;
    }
    
    // Set parameters.
    ret = OH_CryptoSymCipherParams_Create(&params);
    if (ret != CRYPTO_SUCCESS) {
        goto end;
    }
    ret = OH_CryptoSymCipherParams_SetParam(params, CRYPTO_IV_DATABLOB, &ivBlob);
    if (ret != CRYPTO_SUCCESS) {
        goto end;
    }
    
    // Encrypt data.
    ret = OH_CryptoSymCipher_Create("AES128|CBC|PKCS7", &encCtx);
    if (ret != CRYPTO_SUCCESS) {
        goto end;
    }
    ret = OH_CryptoSymCipher_Init(encCtx, CRYPTO_ENCRYPT_MODE, keyCtx, params);
    if (ret != CRYPTO_SUCCESS) {
        goto end;
    }
    ret = OH_CryptoSymCipher_Final(encCtx, &msgBlob, &outUpdate);
    if (ret != CRYPTO_SUCCESS) {
        goto end;
    }
    
    // Decrypt data.
    ret = OH_CryptoSymCipher_Create("AES128|CBC|PKCS7", &decCtx);
    if (ret != CRYPTO_SUCCESS) {
        goto end;
    }
    ret = OH_CryptoSymCipher_Init(decCtx, CRYPTO_DECRYPT_MODE, keyCtx, params);
    if (ret != CRYPTO_SUCCESS) {
        goto end;
    }
    ret = OH_CryptoSymCipher_Final(decCtx, &outUpdate, &decUpdate);
    if (ret != CRYPTO_SUCCESS) {
        goto end;
    }

end:
    OH_CryptoSymCipherParams_Destroy(params);
    OH_CryptoSymCipher_Destroy(encCtx);
    OH_CryptoSymCipher_Destroy(decCtx);
    OH_CryptoSymKeyGenerator_Destroy(genCtx);
    OH_CryptoSymKey_Destroy(keyCtx);
    OH_Crypto_FreeDataBlob(&outUpdate);
    OH_Crypto_FreeDataBlob(&decUpdate);
    return ret;
}
```
