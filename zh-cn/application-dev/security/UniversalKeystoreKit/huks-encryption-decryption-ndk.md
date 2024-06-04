# 加解密(C/C++)


以AES 256密钥为例，完成加解密。具体的场景介绍及支持的算法规格，请参考[密钥生成支持的算法](huks-key-generation-overview.md#支持的算法)。

## 在CMake脚本中链接相关动态库
```txt
   target_link_libraries(entry PUBLIC libhuks_ndk.z.so)
```

## 开发步骤

**生成密钥**

1. 指定密钥别名。

2. 初始化密钥属性集。

3. 调用OH_Huks_GenerateKeyItem生成密钥，具体请参考[密钥生成](huks-key-generation-overview.md)。

除此之外，开发者也可以参考[密钥导入](huks-key-import-overview.md)，导入已有的密钥。

**加密**

1. 获取密钥别名。

2. 获取待加密的数据。

3. 调用[OH_Huks_InitParamSet](../../reference/apis-universal-keystore-kit/_huks_param_set_api.md#oh_huks_initparamset)指定算法参数配置。
   在下方示例中，使用算法AES进行加密时，必须要选择其对应分组模式以及填充模式，用例中选取的分组模式为CBC、填充模式为PKCS7，此时必须要填参数IV。

4. 调用[OH_Huks_InitSession](../../reference/apis-universal-keystore-kit/_huks_key_api.md#oh_huks_initsession)初始化密钥会话，并获取会话的句柄handle。

5. 调用[OH_Huks_FinishSession](../../reference/apis-universal-keystore-kit/_huks_key_api.md#oh_huks_finishsession)结束密钥会话，获取加密后的密文。

**解密**

1. 获取密钥别名。

2. 获取待解密的密文。

3. 调用[OH_Huks_InitParamSet](../../reference/apis-universal-keystore-kit/_huks_param_set_api.md#oh_huks_initparamset)指定算法参数配置。
   在下方示例中，使用算法AES进行解密时，必须要选择其对应分组模式以及填充模式，用例中选取的分组模式为CBC、填充模式为PKCS7，此时必须要填参数IV。

4. 调用[OH_Huks_InitSession](../../reference/apis-universal-keystore-kit/_huks_key_api.md#oh_huks_initsession)初始化密钥会话，并获取会话的句柄handle。

5. 调用[OH_Huks_FinishSession](../../reference/apis-universal-keystore-kit/_huks_key_api.md#oh_huks_finishsession)结束密钥会话，获取解密后的数据。

**删除密钥**

当密钥废弃不用时，需要调用OH_Huks_DeleteKeyItem删除密钥，具体请参考[密钥删除](huks-delete-key-ndk.md)。

```c++
#include "huks/native_huks_api.h"
#include "huks/native_huks_param.h"
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
static uint8_t IV[IV_SIZE] = { 0 }; // this is a test value, for real use the iv should be different every time
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
            .data = (uint8_t *)IV // this is a test value, for real use the iv should be different every time 
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
            .data = (uint8_t *)IV // this is a test value, for real use the iv should be different every time 
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
        * 模拟生成密钥场景
        * 1.1. 确定密钥别名
        */
        /*
        * 1.2. 获取生成密钥算法参数配置
        */
        ohResult = InitParamSet(&genParamSet, g_genEncDecParams, sizeof(g_genEncDecParams) / sizeof(OH_Huks_Param));
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        /*
        * 1.3. 调用generateKeyItem
        */
        ohResult = OH_Huks_GenerateKeyItem(&keyAlias, genParamSet, nullptr);
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        /* 2. Encrypt */
        /*
        * 模拟加密场景
        * 2.1. 获取密钥别名
        */
        /*
        * 2.2. 获取待加密的数据
        */
        /*
        * 2.3. 获取加密算法参数配置
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
        * 2.4. 调用initSession获取handle
        */
        /*
        * 2.5. 调用finishSession获取加密后的密文
        */
        ohResult = HksAesCipherTestEncrypt(&keyAlias, encryptParamSet, &inData, &cipherText);
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        /* 3. Decrypt */
        /*
        * 模拟解密场景
        * 3.1. 获取密钥别名
        */
        /*
        * 3.2. 获取待解密的密文
        */
        /*
        * 3.3. 获取解密算法参数配置
        */
        ohResult = InitParamSet(&decryptParamSet, g_decryptParams, sizeof(g_decryptParams) / sizeof(OH_Huks_Param));
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        uint8_t plain[AES_COMMON_SIZE] = {0};
        struct OH_Huks_Blob plainText = {AES_COMMON_SIZE, plain};
        /*
        * 3.4. 调用initSession获取handle
        */
        /*
        * 3.5. 调用finishSession获取解密后的数据
        */
        ohResult = HksAesCipherTestDecrypt(&keyAlias, decryptParamSet, &cipherText, &plainText, &inData);
    } while (0);
    /* 4. Delete Key */
    /*
    * 模拟删除密钥场景
    * 4.1. 获取密钥别名
    */
    /*
    * 4.2. 调用deleteKeyItem删除密钥    
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
