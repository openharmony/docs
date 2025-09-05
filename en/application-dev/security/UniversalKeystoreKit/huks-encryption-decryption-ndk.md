# Encryption and Decryption (C/C++)

<!--Kit: Universal Keystore Kit-->
<!--Subsystem: Security-->
<!--Owner: @wutiantian-gitee-->
<!--Designer: @HighLowWorld-->
<!--Tester: @wxy1234564846-->
<!--Adviser: @zengyawen-->

The topic uses a 256-bit AES key as an example to describe how to encrypt and decrypt data. For details about the scenarios and supported algorithms, see [Supported Algorithms](huks-key-generation-overview.md#supported-algorithms).

## Add the dynamic library in the CMake script.
```txt
target_link_libraries(entry PUBLIC libhuks_ndk.z.so)
```
## How to Develop

**Key Generation**

1. Specify the key alias. For details about the naming rules, see [Key Generation Overview and Algorithm Specifications](huks-key-generation-overview.md).

2. Initialize the key property set.

3. Use [OH_Huks_GenerateKeyItem](../../reference/apis-universal-keystore-kit/capi-native-huks-api-h.md#oh_huks_generatekeyitem) to generate a key. For details, see [Key Generation Overview and Algorithm Specifications](huks-key-generation-overview.md).

Alternatively, you can [import a key](huks-key-import-overview.md).

**Encryption**

1. Obtain the key alias.

2. Obtain the data to be encrypted.

3. Use [OH_Huks_InitParamSet](../../reference/apis-universal-keystore-kit/capi-native-huks-param-h.md#oh_huks_initparamset) to set algorithm parameters. If AES is used for encryption, the cipher mode and padding mode must be specified. In the following example, the cipher mode is **CBC** and the padding mode is **PKCS7**. In this case, the IV must be set.

4. Use [OH_Huks_InitSession](../../reference/apis-universal-keystore-kit/capi-native-huks-api-h.md#oh_huks_initsession) to initialize a key session and obtain the session handle.

5. Use [OH_Huks_FinishSession](../../reference/apis-universal-keystore-kit/capi-native-huks-api-h.md#oh_huks_finishsession) to finish the key session and obtain the encrypted ciphertext.

**Decryption**

1. Obtain the key alias.

2. Obtain the ciphertext to be decrypted.

3. Use [OH_Huks_InitParamSet](../../reference/apis-universal-keystore-kit/capi-native-huks-param-h.md#oh_huks_initparamset) to set algorithm parameters. If AES is used for decryption, the cipher mode and padding mode must be specified. In the following example, the cipher mode is CBC and the padding mode is PKCS7. In this case, the IV must be set.

4. Use [OH_Huks_InitSession](../../reference/apis-universal-keystore-kit/capi-native-huks-api-h.md#oh_huks_initsession) to initialize a key session and obtain the session handle.

5. Use [OH_Huks_FinishSession](../../reference/apis-universal-keystore-kit/capi-native-huks-api-h.md#oh_huks_finishsession) to finish the key session and obtain the decrypted data.

**Key Deletion**

Use **OH_Huks_DeleteKeyItem** to delete the key that is not required. For details, see [Deleting a Key](huks-delete-key-ndk.md).

```c++
#include "huks/native_huks_api.h"
#include "huks/native_huks_param.h"
#include "napi/native_api.h"
#include <string.h>
OH_Huks_Result InitParamSet(
    struct OH_Huks_ParamSet **paramSet,
    const struct OH_Huks_Param *params,
    uint32_t paramCount)
{
    OH_Huks_Result ret = OH_Huks_InitParamSet(paramSet);
    if (ret.errorCode != OH_HUKS_SUCCESS) {
        return ret;
    }
    ret = OH_Huks_AddParams(*paramSet, params, paramCount);
    if (ret.errorCode != OH_HUKS_SUCCESS) {
        OH_Huks_FreeParamSet(paramSet);
        return ret;
    }
    ret = OH_Huks_BuildParamSet(paramSet);
    if (ret.errorCode != OH_HUKS_SUCCESS) {
        OH_Huks_FreeParamSet(paramSet);
        return ret;
    }
    return ret;
}
static const uint32_t IV_SIZE = 16;
static uint8_t IV[IV_SIZE] = { 0 }; // this is a test value, for real use the iv should be different every time.
static struct OH_Huks_Param g_genEncDecParams[] = {
    {
        .tag = OH_HUKS_TAG_ALGORITHM,
        .uint32Param = OH_HUKS_ALG_AES
    }, {
        .tag = OH_HUKS_TAG_PURPOSE,
        .uint32Param = OH_HUKS_KEY_PURPOSE_ENCRYPT | OH_HUKS_KEY_PURPOSE_DECRYPT
    }, {
        .tag = OH_HUKS_TAG_KEY_SIZE,
        .uint32Param = OH_HUKS_AES_KEY_SIZE_256
    }, {
        .tag = OH_HUKS_TAG_PADDING,
        .uint32Param = OH_HUKS_PADDING_NONE
    }, {
        .tag = OH_HUKS_TAG_BLOCK_MODE,
        .uint32Param = OH_HUKS_MODE_CBC
    }
};
static struct OH_Huks_Param g_encryptParams[] = {
    {
        .tag = OH_HUKS_TAG_ALGORITHM,
        .uint32Param = OH_HUKS_ALG_AES
    }, {
        .tag = OH_HUKS_TAG_PURPOSE,
        .uint32Param = OH_HUKS_KEY_PURPOSE_ENCRYPT
    }, {
        .tag = OH_HUKS_TAG_KEY_SIZE,
        .uint32Param = OH_HUKS_AES_KEY_SIZE_256
    }, {
        .tag = OH_HUKS_TAG_PADDING,
        .uint32Param = OH_HUKS_PADDING_NONE
    }, {
        .tag = OH_HUKS_TAG_BLOCK_MODE,
        .uint32Param = OH_HUKS_MODE_CBC
    }, {
        .tag = OH_HUKS_TAG_IV,
        .blob = {
            .size = IV_SIZE,
            .data = (uint8_t *)IV // this is a test value, for real use the iv should be different every time.
        }
    }
};
static struct OH_Huks_Param g_decryptParams[] = {
    {
        .tag = OH_HUKS_TAG_ALGORITHM,
        .uint32Param = OH_HUKS_ALG_AES
    }, {
        .tag = OH_HUKS_TAG_PURPOSE,
        .uint32Param = OH_HUKS_KEY_PURPOSE_DECRYPT
    }, {
        .tag = OH_HUKS_TAG_KEY_SIZE,
        .uint32Param = OH_HUKS_AES_KEY_SIZE_256
    }, {
        .tag = OH_HUKS_TAG_PADDING,
        .uint32Param = OH_HUKS_PADDING_NONE
    }, {
        .tag = OH_HUKS_TAG_BLOCK_MODE,
        .uint32Param = OH_HUKS_MODE_CBC
    }, {
        .tag = OH_HUKS_TAG_IV,
        .blob = {
            .size = IV_SIZE,
            .data = (uint8_t *)IV // this is a test value, for real use the iv should be different every time. 
        }
    }
};
static const uint32_t AES_COMMON_SIZE = 1024;
OH_Huks_Result HksAesCipherTestEncrypt(
        const struct OH_Huks_Blob *keyAlias,
        const struct OH_Huks_ParamSet *encryptParamSet, const struct OH_Huks_Blob *inData, struct OH_Huks_Blob *cipherText)
{
    uint8_t handleE[sizeof(uint64_t)] = {0};
    struct OH_Huks_Blob handleEncrypt = {sizeof(uint64_t), handleE};
    OH_Huks_Result ret = OH_Huks_InitSession(keyAlias, encryptParamSet, &handleEncrypt, nullptr);
    if (ret.errorCode != OH_HUKS_SUCCESS) {
        return ret;
    }
    ret = OH_Huks_FinishSession(&handleEncrypt, encryptParamSet, inData, cipherText);
    return ret;
}
OH_Huks_Result HksAesCipherTestDecrypt(
    const struct OH_Huks_Blob *keyAlias,
    const struct OH_Huks_ParamSet *decryptParamSet, const struct OH_Huks_Blob *cipherText, struct OH_Huks_Blob *plainText,
    const struct OH_Huks_Blob *inData)
{
    uint8_t handleD[sizeof(uint64_t)] = {0};
    struct OH_Huks_Blob handleDecrypt = {sizeof(uint64_t), handleD};
    OH_Huks_Result ret = OH_Huks_InitSession(keyAlias, decryptParamSet, &handleDecrypt, nullptr);
    if (ret.errorCode != OH_HUKS_SUCCESS) {
        return ret;
    }
    ret = OH_Huks_FinishSession(&handleDecrypt, decryptParamSet, cipherText, plainText);
    return ret;
}
static napi_value EncDecKey(napi_env env, napi_callback_info info)
{
    char tmpKeyAlias[] = "test_enc_dec";
    struct OH_Huks_Blob keyAlias = { (uint32_t)strlen(tmpKeyAlias), (uint8_t *)tmpKeyAlias };
    struct OH_Huks_ParamSet *genParamSet = nullptr;
    struct OH_Huks_ParamSet *encryptParamSet = nullptr;
    struct OH_Huks_ParamSet *decryptParamSet = nullptr;
    OH_Huks_Result ohResult;
    do {
        /* 1. Generate Key */
        /*
        * Simulate the key generation scenario.
        * 1.1. Set the key alias.
        */
        /*
        * 1.2. Obtain the parameters for key generation.
        */
        ohResult = InitParamSet(&genParamSet, g_genEncDecParams, sizeof(g_genEncDecParams) / sizeof(OH_Huks_Param));
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        /*
        * 1.3. Call generateKeyItem to generate a key.
        */
        ohResult = OH_Huks_GenerateKeyItem(&keyAlias, genParamSet, nullptr);
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        /* 2. Encrypt */
        /*
        * Simulate the encryption scenario.
        * 2.1. Obtain the key alias.
        */
        /*
        * 2.2. Obtain the data to be encrypted.
        */
        /*
        * 2.3. Obtain the algorithm parameters for encryption.
        */
        ohResult = InitParamSet(&encryptParamSet, g_encryptParams, sizeof(g_encryptParams) / sizeof(OH_Huks_Param));
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        char tmpInData[] = "AES_ECB_INDATA_1";
        struct OH_Huks_Blob inData = { (uint32_t)strlen(tmpInData), (uint8_t *)tmpInData };
        uint8_t cipher[AES_COMMON_SIZE] = {0};
        struct OH_Huks_Blob cipherText = {AES_COMMON_SIZE, cipher};
        /*
        * 2.4. Call initSession to obtain a session handle.
        */
        /*
        * 2.5. Call finishSession to obtain the ciphertext.
        */
        ohResult = HksAesCipherTestEncrypt(&keyAlias, encryptParamSet, &inData, &cipherText);
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        /* 3. Decrypt */
        /*
        * Simulate the decryption scenario.
        * 3.1. Obtain the key alias.
        */
        /*
        * 3.2. Obtain the ciphertext to be decrypted.
        */
        /*
        * 3.3 Obtain the algorithm parameters for decryption.
        */
        ohResult = InitParamSet(&decryptParamSet, g_decryptParams, sizeof(g_decryptParams) / sizeof(OH_Huks_Param));
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        uint8_t plain[AES_COMMON_SIZE] = {0};
        struct OH_Huks_Blob plainText = {AES_COMMON_SIZE, plain};
        /*
        * 3.4. Call initSession to obtain a session handle.
        */
        /*
        * 3.5. Call finishSession to obtain the decrypted data.
        */
        ohResult = HksAesCipherTestDecrypt(&keyAlias, decryptParamSet, &cipherText, &plainText, &inData);
    } while (0);
    /* 4. Delete Key */
    /*
    * Simulate the key deletion scenario.
    * 4.1. Obtain the key alias.
    */
    /*
    * 4.2. Call deleteKeyItem to delete the key.   
    */
    (void)OH_Huks_DeleteKeyItem(&keyAlias, genParamSet);
        
    OH_Huks_FreeParamSet(&genParamSet);
    OH_Huks_FreeParamSet(&encryptParamSet);
    OH_Huks_FreeParamSet(&decryptParamSet);
    
    napi_value ret;
    napi_create_int32(env, ohResult.errorCode, &ret);
    return ret;
}
```
