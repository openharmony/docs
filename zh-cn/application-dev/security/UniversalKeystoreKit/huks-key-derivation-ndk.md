# 密钥派生(C/C++)


以HKDF256密钥为例，完成密钥派生。具体的场景介绍及支持的算法规格，请参考[密钥生成支持的算法](huks-key-generation-overview.md#支持的算法)。


## 开发步骤

**生成密钥**

1. 指定密钥别名。

2. 初始化密钥属性集，可指定参数TAG(可选)，OH_HUKS_TAG_DERIVED_AGREED_KEY_STORAGE_FLAG：
   - OH_HUKS_STORAGE_ONLY_USED_IN_HUKS：表示由该密钥派生出的密钥存储于HUKS中，由HUKS进行托管。
   - OH_HUKS_STORAGE_KEY_EXPORT_ALLOWED(默认)：表示由该密钥派生出的密钥直接导出给业务方，HUKS不对其进行托管服务。

3. 调用OH_Huks_GenerateKeyItem生成密钥，具体请参考[密钥生成](huks-key-generation-overview.md)。

除此之外，开发者也可以参考[密钥导入](huks-key-import-overview.md)，导入已有的密钥。

**密钥派生**

1. 获取密钥别名、指定对应的属性参数HuksOptions。

   应用在派生密钥时建议传入[OH_Huks_KeyStorageType](../../reference/native-apis/_huks_type_api.md#oh_huks_keystoragetype)中定义的类型：

   - HUKS_STORAGE_ONLY_USED_IN_HUKS：表示协商出的密钥仅在HUKS内使用。
   - HUKS_STORAGE_KEY_EXPORT_ALLOWED：表示不在HUKS内存储，协商后直接导出。
   - 若不传入，则默认同时支持存储和导出，存在安全风险，不推荐业务使用。

2. 调用[OH_Huks_InitSession](../../reference/native-apis/_huks_key_api.md#oh_huks_initsession)初始化密钥会话，并获取会话的句柄handle。

3. 调用[OH_Huks_UpdateSession](../../reference/native-apis/_huks_key_api.md#oh_huks_updatesession)更新密钥会话。

4. 调用[OH_Huks_FinishSession](../../reference/native-apis/_huks_key_api.md#oh_huks_finishsession)结束密钥会话，完成派生。

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
static const uint32_t DERIVE_KEY_SIZE_32 = 32;
static struct OH_Huks_Blob g_deriveKeyAlias = {
    (uint32_t)strlen("test_derive"),
    (uint8_t *)"test_derive"
};
static struct OH_Huks_Param g_genDeriveParams[] = {
    {
        .tag =  OH_HUKS_TAG_ALGORITHM,
        .uint32Param = OH_HUKS_ALG_AES
    }, {
        .tag =  OH_HUKS_TAG_PURPOSE,
        .uint32Param = OH_HUKS_KEY_PURPOSE_DERIVE
    }, {
        .tag =  OH_HUKS_TAG_DIGEST,
        .uint32Param = OH_HUKS_DIGEST_SHA256
    }, {
        .tag =  OH_HUKS_TAG_KEY_SIZE,
        .uint32Param = OH_HUKS_AES_KEY_SIZE_256
    }
};
static struct OH_Huks_Param g_hkdfParams[] = {
    {
        .tag =  OH_HUKS_TAG_ALGORITHM,
        .uint32Param = OH_HUKS_ALG_HKDF
    }, {
        .tag =  OH_HUKS_TAG_PURPOSE,
        .uint32Param = OH_HUKS_KEY_PURPOSE_DERIVE
    }, {
        .tag =  OH_HUKS_TAG_DIGEST,
        .uint32Param = OH_HUKS_DIGEST_SHA256
    }, {
        .tag =  OH_HUKS_TAG_DERIVE_KEY_SIZE,
        .uint32Param = DERIVE_KEY_SIZE_32
    }
};
static struct OH_Huks_Param g_hkdfFinishParams[] = {
    {
        .tag =  OH_HUKS_TAG_DERIVED_AGREED_KEY_STORAGE_FLAG,
        .uint32Param = OH_HUKS_STORAGE_ONLY_USED_IN_HUKS
    }, {
        .tag =  OH_HUKS_TAG_KEY_ALIAS,
        .blob = g_deriveKeyAlias
    }, {
        .tag =  OH_HUKS_TAG_ALGORITHM,
        .uint32Param = OH_HUKS_ALG_HKDF
    }, {
        .tag =  OH_HUKS_TAG_KEY_SIZE,
        .uint32Param = DERIVE_KEY_SIZE_32
    }, {
        .tag =  OH_HUKS_TAG_PURPOSE,
        .uint32Param = OH_HUKS_KEY_PURPOSE_DERIVE
    }, {
        .tag =  OH_HUKS_TAG_DIGEST,
        .uint32Param = OH_HUKS_DIGEST_SHA256
    }
};
static const uint32_t COMMON_SIZE = 2048;
static const char *g_deriveInData = "Hks_HKDF_Derive_Test_00000000000000000000000000000000000000000000000000000000000"
                                    "00000000000000000000000000000000000000000000000000000000000000000000000000000000"
                                    "0000000000000000000000000000000000000000000000000000000000000000000000000_string";
static napi_value DeriveKey(napi_env env, napi_callback_info info) 
{
    struct OH_Huks_Blob genAlias = {
        (uint32_t)strlen("test_signVerify"),
        (uint8_t *)"test_signVerify"
    };
    struct OH_Huks_Blob inData = {
        (uint32_t)strlen(g_deriveInData),
        (uint8_t *)g_deriveInData
    };
    struct OH_Huks_ParamSet *genParamSet = nullptr;
    struct OH_Huks_ParamSet *hkdfParamSet = nullptr;
    struct OH_Huks_ParamSet *hkdfFinishParamSet = nullptr;
    OH_Huks_Result ohResult;
    do {
        ohResult = InitParamSet(&genParamSet, g_genDeriveParams, sizeof(g_genDeriveParams) / sizeof(OH_Huks_Param));
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        
        ohResult = InitParamSet(&hkdfParamSet, g_hkdfParams, sizeof(g_hkdfParams) / sizeof(OH_Huks_Param));
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
           break;
        } 
        
        // finish paramset
        ohResult = InitParamSet(&hkdfFinishParamSet, g_hkdfFinishParams, sizeof(g_hkdfFinishParams) / sizeof(OH_Huks_Param));
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        
        /* 1. Generate Key */
        ohResult = OH_Huks_GenerateKeyItem(&genAlias, genParamSet, nullptr);
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        /* 2. Derive */
        // Init
        uint8_t handleD[sizeof(uint64_t)] = {0};
        struct OH_Huks_Blob handleDerive = { sizeof(uint64_t), handleD };
        ohResult = OH_Huks_InitSession(&genAlias, hkdfParamSet, &handleDerive, nullptr);
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        // Update
        uint8_t tmpOut[COMMON_SIZE] = {0};
        struct OH_Huks_Blob outData = { COMMON_SIZE, tmpOut };
        ohResult = OH_Huks_UpdateSession(&handleDerive, hkdfParamSet, &inData, &outData);
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        // Finish
        uint8_t outDataD[COMMON_SIZE] = {0};
        struct OH_Huks_Blob outDataDerive = { COMMON_SIZE, outDataD };
        ohResult = OH_Huks_FinishSession(&handleDerive, hkdfFinishParamSet, &inData, &outDataDerive);
    } while (0);
    (void)OH_Huks_DeleteKeyItem(&genAlias, nullptr);
    (void)OH_Huks_DeleteKeyItem(&g_deriveKeyAlias, nullptr);
    OH_Huks_FreeParamSet(&genParamSet);
    OH_Huks_FreeParamSet(&hkdfParamSet);
    OH_Huks_FreeParamSet(&hkdfFinishParamSet);
    
    napi_value ret;
    napi_create_int32(env, ohResult.errorCode, &ret);
    return ret;
}
```
