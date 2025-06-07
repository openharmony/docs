# Encryption and Decryption by Segment with an AES Symmetric Key (GCM Mode) (C/C++)

For details about the algorithm specifications, see [AES](crypto-sym-encrypt-decrypt-spec.md#aes).

## Adding the Dynamic Library in the CMake Script
```txt
target_link_libraries(entry PUBLIC libohcrypto.so)
```

## How to Develop

**Creating an Object**

Call [OH_CryptoSymKeyGenerator_Create](../../reference/apis-crypto-architecture-kit/_crypto_sym_key_api.md#oh_cryptosymkeygenerator_create) and [OH_CryptoSymKeyGenerator_Generate](../../reference/apis-crypto-architecture-kit/_crypto_sym_key_api.md#oh_cryptosymkeygenerator_generate) to generate a 128-bit AES symmetric key (**OH_CryptoSymKey**).
   
In addition to the example in this topic, [AES](crypto-sym-key-generation-conversion-spec.md#aes) and [Randomly Generating a Symmetric Key](crypto-generate-sym-key-randomly-ndk.md) may help you better understand how to generate an AES symmetric key. Note that the input parameters in the reference documents may be different from those in the example below.

**Encrypting a Message**

1. Call [OH_CryptoSymCipher_Create](../../reference/apis-crypto-architecture-kit/_crypto_sym_cipher_api.md#oh_cryptosymcipher_create) with the string parameter **'AES128|GCM|PKCS7'** to create a **Cipher** instance for encryption. The key type is **AES128**, block cipher mode is **GCM**, and the padding mode is **PKCS7**.

2. Call [OH_CryptoSymCipherParams_Create](../../reference/apis-crypto-architecture-kit/_crypto_sym_cipher_api.md#oh_cryptosymcipherparams_create) to create a symmetric cipher parameter instance, and call [OH_CryptoSymCipherParams_SetParam](../../reference/apis-crypto-architecture-kit/_crypto_sym_cipher_api.md#oh_cryptosymcipherparams_setparam) to set cipher parameters.

3. Call [OH_CryptoSymCipher_Init](../../reference/apis-crypto-architecture-kit/_crypto_sym_cipher_api.md#oh_cryptosymcipher_init) to initialize the **Cipher** instance. Specifically, set **mode** to **CRYPTO_ENCRYPT_MODE**, and specify the key for encryption (**OH_CryptoSymKey**) and the encryption parameter instance (**OH_CryptoSymCipherParams**) corresponding to the GCM mode.

4. Set the size of the data to be passed in each time to 20 bytes, and call [OH_CryptoSymCipher_Update](../../reference/apis-crypto-architecture-kit/_crypto_sym_cipher_api.md#oh_cryptosymcipher_update) multiple times to pass in the data (plaintext) to be encrypted.
   
   - Currently, the amount of data to be passed in by a single **OH_CryptoSymCipher_Update()** is not limited. You can determine how to pass in data based on the data volume.
   - You are advised to check the result of each **OH_CryptoSymCipher_Update()**. If the result is not **null**, obtain the data and combine the data segments into complete ciphertext. The **OH_CryptoSymCipher_Update()** result may vary with the key specifications.
      
      If a block cipher mode (ECB or CBC) is used, data is encrypted and output based on the block size. That is, if the data of an **OH_CryptoSymCipher_Update()** operation matches the block size, the ciphertext is output. Otherwise, **null** is output, and the plaintext will be combined with the input data of the next **OH_CryptoSymCipher_Update()** to form a block. When **OH_CryptoSymCipher_Final()** is called, the unencrypted data is padded to the block size based on the specified padding mode, and then encrypted. The **OH_CryptoSymCipher_Update()** API works in the same way in decryption.

      If a stream cipher mode (CTR or OFB) is used, the ciphertext length is usually the same as the plaintext length.

6. Call [OH_CryptoSymCipher_Final](../../reference/apis-crypto-architecture-kit/_crypto_sym_cipher_api.md#oh_cryptosymcipher_final) to generate the ciphertext.
   
   - If data has been passed in by **OH_CryptoSymCipher_Update()**, pass in **null** in the **data** parameter of **OH_CryptoSymCipher_Final**.
   - The output of **OH_CryptoSymCipher_Final** may be **null**. To avoid exceptions, always check whether the result is **null** before accessing specific data.
   > **NOTE**<br>
   > If GCM mode is used, **authTag** returned by **OH_CryptoSymCipher_Final()** will be used to initialize the authentication information during decryption and needs to be saved.
   > In GCM mode, **authTag** must be of 16 bytes. It is used as the authentication information during decryption. In the example, **authTag** is of 16 bytes.

**Decrypting a Message**

1. Call [OH_CryptoSymCipher_Create](../../reference/apis-crypto-architecture-kit/_crypto_sym_cipher_api.md#oh_cryptosymcipher_create) with the string parameter **'AES128|GCM|PKCS7'** to create a **Cipher** instance for decryption. The key type is **AES128**, block cipher mode is **GCM**, and the padding mode is **PKCS7**.

2. Call [OH_CryptoSymCipherParams_SetParam](../../reference/apis-crypto-architecture-kit/_crypto_sym_cipher_api.md#oh_cryptosymcipherparams_setparam) to set **authTag** as the authentication information for decryption.
   
   In GCM mode, extract the last 16 bytes from the encrypted data as the authentication information for initializing the **Cipher** instance in decryption. In the example, **authTag** is of 16 bytes.

3. Call [OH_CryptoSymCipher_Init](../../reference/apis-crypto-architecture-kit/_crypto_sym_cipher_api.md#oh_cryptosymcipher_init) to initialize the **Cipher** instance. Specifically, set **mode** to **CRYPTO_DECRYPT_MODE**, and specify the key for decryption (**OH_CryptoSymKey**) and the decryption parameter instance (**OH_CryptoSymCipherParams**) corresponding to the GCM mode.

4. Set the size of the data to be passed in each time to 20 bytes, and call [OH_CryptoSymCipher_Update](../../reference/apis-crypto-architecture-kit/_crypto_sym_cipher_api.md#oh_cryptosymcipher_update) multiple times to pass in the data (ciphertext) to be decrypted.

5. Call [OH_CryptoSymCipher_Final](../../reference/apis-crypto-architecture-kit/_crypto_sym_cipher_api.md#oh_cryptosymcipher_final) to generate the plaintext.

**Destroying Objects**

Call [OH_CryptoSymKeyGenerator_Destroy](../../reference/apis-crypto-architecture-kit/_crypto_sym_key_api.md#oh_cryptosymkeygenerator_destroy), [OH_CryptoSymCipher_Destroy](../../reference/apis-crypto-architecture-kit/_crypto_sym_cipher_api.md#oh_cryptosymcipher_destroy), and [OH_CryptoSymCipherParams_Destroy](../../reference/apis-crypto-architecture-kit/_crypto_sym_cipher_api.md#oh_cryptosymcipherparams_destroy) to destroy the instances created.

**Example**

```c++
#include <string.h>
#include "CryptoArchitectureKit/crypto_common.h"
#include "CryptoArchitectureKit/crypto_sym_cipher.h"

#define OH_CRYPTO_GCM_TAG_LEN 16
#define OH_CRYPTO_MAX_TEST_DATA_LEN 128
static OH_Crypto_ErrCode doTestAesGcmSeg()
{
    OH_CryptoSymKeyGenerator *genCtx = nullptr;
    OH_CryptoSymCipher *encCtx = nullptr;
    OH_CryptoSymCipher *decCtx = nullptr;
    OH_CryptoSymKey *keyCtx = nullptr;
    OH_CryptoSymCipherParams *params = nullptr;

    char *plainText = const_cast<char *>("aaaaa.....bbbbb.....ccccc.....ddddd.....eee");
    Crypto_DataBlob msgBlob = {.data = (uint8_t *)(plainText), .len = strlen(plainText)};

    uint8_t aad[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    uint8_t tagArr[16] = {0};
    uint8_t iv[12] = {1, 2, 4, 12, 3, 4, 2, 3, 3, 2, 0, 4}; // iv is generated from an array of secure random numbers.
    Crypto_DataBlob tag = {.data = nullptr, .len = 0};
    Crypto_DataBlob ivBlob = {.data = iv, .len = sizeof(iv)};
    Crypto_DataBlob aadBlob = {.data = aad, .len = sizeof(aad)};
    Crypto_DataBlob encData = {.data = nullptr, .len = 0};
    Crypto_DataBlob decData = {.data = nullptr, .len = 0};
    Crypto_DataBlob tagInit = {.data = tagArr, .len = sizeof(tagArr)};
    int32_t cipherLen = 0;
    int blockSize = 20;
    int32_t randomLen = strlen(plainText);
    Crypto_DataBlob cipherBlob;
    // Define the encryption variables.
    int cnt = randomLen / blockSize;
    int rem = randomLen % blockSize;
    uint8_t cipherText[OH_CRYPTO_MAX_TEST_DATA_LEN] = {0};

    // Define the decryption variables.
    int decCnt = cipherLen / blockSize;
    int decRem = cipherLen % blockSize;
    int32_t plantLen = 0;
    uint8_t plantText[OH_CRYPTO_MAX_TEST_DATA_LEN] = {0};
    
    // Generate a key.
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
    ret = OH_CryptoSymCipherParams_SetParam(params, CRYPTO_AAD_DATABLOB, &aadBlob);
    if (ret != CRYPTO_SUCCESS) {
        goto end;
    }
    ret = OH_CryptoSymCipherParams_SetParam(params, CRYPTO_TAG_DATABLOB, &tagInit);
    if (ret != CRYPTO_SUCCESS) {
        goto end;
    }
    
    // Encrypt the message.
    ret = OH_CryptoSymCipher_Create("AES128|GCM|PKCS7", &encCtx);
    if (ret != CRYPTO_SUCCESS) {
        goto end;
    }
    ret = OH_CryptoSymCipher_Init(encCtx, CRYPTO_ENCRYPT_MODE, keyCtx, params);
    if (ret != CRYPTO_SUCCESS) {
        goto end;
    }
    
    for (int i = 0; i < cnt; i++) {
        msgBlob.len = blockSize;
        ret = OH_CryptoSymCipher_Update(encCtx, &msgBlob, &encData);
        if (ret != CRYPTO_SUCCESS) {
            goto end;
        }
        msgBlob.data += blockSize;
        memcpy(&cipherText[cipherLen], encData.data, encData.len);
        cipherLen += encData.len;
    }
    if (rem > 0) {
        msgBlob.len = rem;
        ret = OH_CryptoSymCipher_Update(encCtx, (Crypto_DataBlob *)&msgBlob, &encData);
        if (ret != CRYPTO_SUCCESS) {
            goto end;
        }
        memcpy(&cipherText[cipherLen], encData.data, encData.len);
        cipherLen += encData.len;
    }
    ret = OH_CryptoSymCipher_Final(encCtx, nullptr, &tag);
    if (ret != CRYPTO_SUCCESS) {
        goto end;
    }

    // Decrypt the message.
    cipherBlob = {.data = reinterpret_cast<uint8_t *>(cipherText), .len = (size_t)cipherLen};
    ret = OH_CryptoSymCipher_Create("AES128|GCM|PKCS7", &decCtx);
    if (ret != CRYPTO_SUCCESS) {
        goto end;
    }
    ret = OH_CryptoSymCipherParams_SetParam(params, CRYPTO_TAG_DATABLOB, &tag);
    if (ret != CRYPTO_SUCCESS) {
        goto end;
    }
    ret = OH_CryptoSymCipher_Init(decCtx, CRYPTO_DECRYPT_MODE, keyCtx, params);
    if (ret != CRYPTO_SUCCESS) {
        goto end;
    }
    for (int i = 0; i < decCnt; i++) {
        cipherBlob.len = blockSize;
        ret = OH_CryptoSymCipher_Update(decCtx, &cipherBlob, &decData);
        if (ret != CRYPTO_SUCCESS) {
            goto end;
        }
        cipherBlob.data += blockSize;
        memcpy(&plantText[plantLen], decData.data, decData.len);
        plantLen += decData.len;
    }
    if (decRem > 0) {
        cipherBlob.len = decRem;
        ret = OH_CryptoSymCipher_Update(decCtx, &cipherBlob, &decData);
        if (ret != CRYPTO_SUCCESS) {
            goto end;
        }
        memcpy(&plantText[plantLen], decData.data, decData.len);
        plantLen += decData.len;
    }
    ret = OH_CryptoSymCipher_Final(decCtx, nullptr, &decData);
    if (ret != CRYPTO_SUCCESS) {
        goto end;
    }

end:
    OH_CryptoSymCipherParams_Destroy(params);
    OH_CryptoSymCipher_Destroy(encCtx);
    OH_CryptoSymCipher_Destroy(decCtx);
    OH_CryptoSymKeyGenerator_Destroy(genCtx);
    OH_CryptoSymKey_Destroy(keyCtx);
    OH_Crypto_FreeDataBlob(&encData);
    OH_Crypto_FreeDataBlob(&tag);
    OH_Crypto_FreeDataBlob(&decData);
    return ret;
}
```
