# 密钥协商(C/C++)

<!--Kit: Universal Keystore Kit-->
<!--Subsystem: Security-->
<!--Owner: @wutiantian-gitee-->
<!--Designer: @HighLowWorld-->
<!--Tester: @wxy1234564846-->
<!--Adviser: @zengyawen-->

以ECDH协商密钥类型为例，在密钥由HUKS管理的情况下，完成密钥协商。具体的场景介绍及支持的算法规格，请参考[密钥生成支持的算法](huks-key-generation-overview.md#支持的算法)。

## 在CMake脚本中链接相关动态库
```txt
target_link_libraries(entry PUBLIC libhuks_ndk.z.so)
```

## 开发步骤

**生成密钥**

设备A、设备B各自生成一个非对称密钥，具体请参考[密钥生成](huks-key-generation-overview.md)或[密钥导入](huks-key-import-overview.md)。

密钥生成时，可指定参数，OH_HUKS_TAG_DERIVED_AGREED_KEY_STORAGE_FLAG（可选），用于标识此步骤生成的密钥是否由HUKS管理。

**导出密钥**

设备A、B导出非对称密钥对的公钥材料，具体请参考[密钥导出](huks-export-key-arkts.md)。

**密钥协商**

设备A、B分别基于本端私钥和对端设备的公钥，协商出共享密钥。

密钥协商时，可指定参数OH_HUKS_TAG_DERIVED_AGREED_KEY_STORAGE_FLAG（可选），用于标识协商得到的密钥是否由HUKS管理。

- 当TAG设置为OH_HUKS_STORAGE_ONLY_USED_IN_HUKS时，表示基于该密钥协商出的密钥，由HUKS管理，可保证协商密钥全生命周期不出安全环境。

- 当TAG设置为OH_HUKS_STORAGE_KEY_EXPORT_ALLOWED时，表示基于该密钥协商出的密钥，返回给调用方管理，由业务自行保证密钥安全。

- 若业务未设置TAG的具体值，表示基于该密钥协商出的密钥，既可由HUKS管理，也可返回给调用方管理，业务可在后续协商时再选择使用何种方式保护密钥。

| 生成 | 协商 | 规格 |
| -------- | -------- | -------- |
| OH_HUKS_STORAGE_ONLY_USED_IN_HUKS | OH_HUKS_STORAGE_ONLY_USED_IN_HUKS | 密钥由HUKS管理 |
| OH_HUKS_STORAGE_KEY_EXPORT_ALLOWED | OH_HUKS_STORAGE_KEY_EXPORT_ALLOWED | 密钥返回给调用方管理 |
| 未指定TAG具体值 | OH_HUKS_STORAGE_ONLY_USED_IN_HUKS | 密钥由HUKS管理 |
| 未指定TAG具体值 | OH_HUKS_STORAGE_KEY_EXPORT_ALLOWED | 密钥返回给调用方管理 |
| 未指定TAG具体值 | 未指定TAG具体值 | 密钥返回给调用方管理 |

注：协商时指定的TAG值，不可与生成时指定的TAG值冲突。表格中仅列举有效的指定方式。

**删除密钥**

当密钥废弃不用时，设备A、B均需要删除密钥，具体请参考[密钥删除](huks-delete-key-ndk.md)。

```c++
#include "huks/native_huks_api.h"
#include "huks/native_huks_param.h"
#include "napi/native_api.h"
#include <string.h>
/* 初始化参数 */
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
static struct OH_Huks_Blob g_keyAliasFinal1001 = {
    (uint32_t)strlen("HksECDHAgreeKeyAliasTest001_1_final"),
    (uint8_t *)"HksECDHAgreeKeyAliasTest001_1_final"
};
/* 集成密钥参数集 */
static struct OH_Huks_Param g_genAgreeParams[] = {
    {
        .tag = OH_HUKS_TAG_ALGORITHM,
        .uint32Param = OH_HUKS_ALG_ECC
    }, {
        .tag = OH_HUKS_TAG_PURPOSE,
        .uint32Param = OH_HUKS_KEY_PURPOSE_AGREE
    }, {
        .tag = OH_HUKS_TAG_KEY_SIZE,
        .uint32Param = OH_HUKS_ECC_KEY_SIZE_256
    }, {
        .tag = OH_HUKS_TAG_DIGEST,
        .uint32Param = OH_HUKS_DIGEST_NONE
    }
};
static struct OH_Huks_Param g_agreeParamsInit01[] = {
    {
        .tag = OH_HUKS_TAG_ALGORITHM,
        .uint32Param = OH_HUKS_ALG_ECDH
    }, {
        .tag = OH_HUKS_TAG_PURPOSE,
        .uint32Param = OH_HUKS_KEY_PURPOSE_AGREE
    }, {
        .tag = OH_HUKS_TAG_KEY_SIZE,
        .uint32Param = OH_HUKS_ECC_KEY_SIZE_256
    }
};
static struct OH_Huks_Param g_agreeParamsFinish01[] = {
    {
        .tag = OH_HUKS_TAG_DERIVED_AGREED_KEY_STORAGE_FLAG,
        .uint32Param = OH_HUKS_STORAGE_ONLY_USED_IN_HUKS
    }, {
        .tag = OH_HUKS_TAG_ALGORITHM,
        .uint32Param = OH_HUKS_ALG_AES
    }, {
        .tag = OH_HUKS_TAG_KEY_SIZE,
        .uint32Param = OH_HUKS_AES_KEY_SIZE_256
    }, {
        .tag = OH_HUKS_TAG_PURPOSE,
        .uint32Param = OH_HUKS_KEY_PURPOSE_AGREE
    }, {
        .tag = OH_HUKS_TAG_KEY_ALIAS,
        .blob = g_keyAliasFinal1001
    }, {
        .tag = OH_HUKS_TAG_PADDING,
        .uint32Param = OH_HUKS_PADDING_NONE
    }, {
        .tag = OH_HUKS_TAG_BLOCK_MODE,
        .uint32Param = OH_HUKS_MODE_CBC
    }
};
static struct OH_Huks_Blob g_keyAliasFinal2001 = {
    (uint32_t)strlen("HksECDHAgreeKeyAliasTest001_2_final"),
    (uint8_t *)"HksECDHAgreeKeyAliasTest001_2_final"
};
static struct OH_Huks_Param g_agreeParamsInit02[] = {
    {
        .tag = OH_HUKS_TAG_ALGORITHM,
        .uint32Param = OH_HUKS_ALG_ECDH
    }, {
        .tag = OH_HUKS_TAG_PURPOSE,
        .uint32Param = OH_HUKS_KEY_PURPOSE_AGREE
    }, {
        .tag = OH_HUKS_TAG_KEY_SIZE,
        .uint32Param = OH_HUKS_ECC_KEY_SIZE_256
    }
};
static struct OH_Huks_Param g_agreeParamsFinish02[] = {
    {
        .tag = OH_HUKS_TAG_DERIVED_AGREED_KEY_STORAGE_FLAG,
        .uint32Param = OH_HUKS_STORAGE_ONLY_USED_IN_HUKS
    }, {
        .tag = OH_HUKS_TAG_ALGORITHM,
        .uint32Param = OH_HUKS_ALG_AES
    }, {
        .tag = OH_HUKS_TAG_KEY_SIZE,
        .uint32Param = OH_HUKS_AES_KEY_SIZE_256
    }, {
        .tag = OH_HUKS_TAG_PURPOSE,
        .uint32Param = OH_HUKS_KEY_PURPOSE_AGREE
    }, {
        .tag = OH_HUKS_TAG_KEY_ALIAS,
        .blob = g_keyAliasFinal2001
    }, {
        .tag = OH_HUKS_TAG_PADDING,
        .uint32Param = OH_HUKS_PADDING_NONE
    }, {
        .tag = OH_HUKS_TAG_BLOCK_MODE,
        .uint32Param = OH_HUKS_MODE_CBC
    }
};
static const uint32_t ECDH_COMMON_SIZE = 1024;
static struct OH_Huks_Blob g_keyAlias01001 = {
    (uint32_t)strlen("HksECDHAgreeKeyAliasTest001_1"),
    (uint8_t *)"HksECDHAgreeKeyAliasTest001_1"
};
static struct OH_Huks_Blob g_keyAlias02001 = {
    (uint32_t)strlen("HksECDHAgreeKeyAliasTest001_2"),
    (uint8_t *)"HksECDHAgreeKeyAliasTest001_2"
};
OH_Huks_Result MallocAndCheckBlobData(
    struct OH_Huks_Blob *blob,
    const uint32_t blobSize)
{
    struct OH_Huks_Result ret;
    ret.errorCode = OH_HUKS_SUCCESS;
    blob->data = (uint8_t *)malloc(blobSize);
    if (blob->data == NULL) {
        ret.errorCode = OH_HUKS_ERR_CODE_INTERNAL_ERROR;
    }
    return ret;
}
/* 导出密钥 */
OH_Huks_Result HksEcdhAgreeExport(const struct OH_Huks_Blob *keyAlias1, const struct OH_Huks_Blob *keyAlias2,
    struct OH_Huks_Blob *publicKey1, struct OH_Huks_Blob *publicKey2, const struct OH_Huks_ParamSet *genParamSet)
{
    OH_Huks_Result ret = OH_Huks_ExportPublicKeyItem(keyAlias1, genParamSet, publicKey1);
    if (ret.errorCode != OH_HUKS_SUCCESS) {
        return ret;
    }
    ret = OH_Huks_ExportPublicKeyItem(keyAlias2, genParamSet, publicKey2);
    if (ret.errorCode != OH_HUKS_SUCCESS) {
        return ret;
    }
    return ret;
}
static const char *g_inData = "Hks_ECDH_Agree_Test_000000000000000000000000000000000000000000000000000000000000"
                                    "00000000000000000000000000000000000000000000000000000000000000000000000000000000"
                                    "0000000000000000000000000000000000000000000000000000000000000000000000000_string";
/* 协商密钥操作 */
OH_Huks_Result HksEcdhAgreeFinish(const struct OH_Huks_Blob *keyAlias, const struct OH_Huks_Blob *publicKey,
    const struct OH_Huks_ParamSet *initParamSet, const struct OH_Huks_ParamSet *finishParamSet, struct OH_Huks_Blob *outData)
{
    struct OH_Huks_Blob inData = {
        (uint32_t)strlen(g_inData),
        (uint8_t *)g_inData
    };
    uint8_t handleU[sizeof(uint64_t)] = {0};
    struct OH_Huks_Blob handle = { sizeof(uint64_t), handleU };
    OH_Huks_Result ret = OH_Huks_InitSession(keyAlias, initParamSet, &handle, nullptr);
    if (ret.errorCode != OH_HUKS_SUCCESS) {
        return ret;
    }
    uint8_t outDataU[ECDH_COMMON_SIZE] = {0};
    struct OH_Huks_Blob outDataUpdate = { ECDH_COMMON_SIZE, outDataU };
    ret = OH_Huks_UpdateSession(&handle, initParamSet, publicKey, &outDataUpdate);
    if (ret.errorCode != OH_HUKS_SUCCESS) {
        return ret;
    }
    ret = OH_Huks_FinishSession(&handle, finishParamSet, &inData, outData);
    if (ret.errorCode != OH_HUKS_SUCCESS) {
        return ret;
    }
    return ret;
}
/* 协商密钥整体流程 */
static napi_value AgreeKey(napi_env env, napi_callback_info info)
{
    struct OH_Huks_ParamSet *genParamSet = nullptr;
    struct OH_Huks_ParamSet *initParamSet01 = nullptr;
    struct OH_Huks_ParamSet *finishParamSet01 = nullptr;
    struct OH_Huks_ParamSet *initParamSet02 = nullptr;
    struct OH_Huks_ParamSet *finishParamSet02 = nullptr;
    struct OH_Huks_Blob publicKey01 = { .size = OH_HUKS_ECC_KEY_SIZE_256, .data = nullptr };
    struct OH_Huks_Blob publicKey02 = { .size = OH_HUKS_ECC_KEY_SIZE_256, .data = nullptr };
    struct OH_Huks_Blob outData01 = { .size = ECDH_COMMON_SIZE, .data = nullptr };
    struct OH_Huks_Blob outData02 = { .size = ECDH_COMMON_SIZE, .data = nullptr };
    OH_Huks_Result ohResult;
    do {
        /* 1.确定密钥别名集成密钥参数集 */
        ohResult = InitParamSet(&genParamSet, g_genAgreeParams, sizeof(g_genAgreeParams) / sizeof(OH_Huks_Param));
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        ohResult = InitParamSet(&initParamSet01, g_agreeParamsInit01, sizeof(g_agreeParamsInit01) / sizeof(OH_Huks_Param));
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        ohResult = InitParamSet(&finishParamSet01, g_agreeParamsFinish01,
            sizeof(g_agreeParamsFinish01) / sizeof(OH_Huks_Param));
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        ohResult = InitParamSet(&initParamSet02, g_agreeParamsInit02, sizeof(g_agreeParamsInit02) / sizeof(OH_Huks_Param));
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        ohResult = InitParamSet(&finishParamSet02, g_agreeParamsFinish02,
            sizeof(g_agreeParamsFinish02) / sizeof(OH_Huks_Param));
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        /* 2.设备A生成密钥 */
        ohResult = OH_Huks_GenerateKeyItem(&g_keyAlias01001, genParamSet, nullptr);
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        /* 3.设备B生成密钥 */
        ohResult = OH_Huks_GenerateKeyItem(&g_keyAlias02001, genParamSet, nullptr);
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        ohResult = MallocAndCheckBlobData(&publicKey01, publicKey01.size);
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        ohResult = MallocAndCheckBlobData(&publicKey02, publicKey02.size);
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        /* 4.设备A、B导出公钥 */
        ohResult = HksEcdhAgreeExport(&g_keyAlias01001, &g_keyAlias02001, &publicKey01, &publicKey02, genParamSet);
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        ohResult = MallocAndCheckBlobData(&outData01, outData01.size);
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        ohResult = MallocAndCheckBlobData(&outData02, outData02.size);
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        /* 5.设备A协商密钥 */
        ohResult = HksEcdhAgreeFinish(&g_keyAlias01001, &publicKey02, initParamSet01, finishParamSet01, &outData01);
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        /* 5.设备B协商密钥 */
        ohResult = HksEcdhAgreeFinish(&g_keyAlias02001, &publicKey01, initParamSet02, finishParamSet02, &outData02);
    } while (0);
    free(publicKey01.data);
    free(publicKey02.data);
    free(outData01.data);
    free(outData02.data);
    /* 6.设备A、B删除密钥 */
    OH_Huks_DeleteKeyItem(&g_keyAlias01001, genParamSet);
    OH_Huks_DeleteKeyItem(&g_keyAlias02001, genParamSet);
    OH_Huks_DeleteKeyItem(&g_keyAliasFinal1001, NULL);
    OH_Huks_DeleteKeyItem(&g_keyAliasFinal2001, NULL);
    OH_Huks_FreeParamSet(&genParamSet);
    OH_Huks_FreeParamSet(&initParamSet01);
    OH_Huks_FreeParamSet(&finishParamSet01);
    OH_Huks_FreeParamSet(&initParamSet02);
    OH_Huks_FreeParamSet(&finishParamSet02);
    
    napi_value ret;
    napi_create_int32(env, ohResult.errorCode, &ret);
    return ret;
}
```
