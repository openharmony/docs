# 密钥导出(C/C++)

<!--Kit: Universal Keystore Kit-->
<!--Subsystem: Security-->
<!--Owner: @wutiantian-gitee-->
<!--SE: @HighLowWorld-->
<!--TSE: @wxy1234564846-->

业务需要获取持久化存储的非对称密钥的公钥时使用，当前支持ECC/RSA/ED25519/X25519/SM2的公钥导出。

>**说明：**
> 轻量级设备仅支持RSA公钥导出。

## 在CMake脚本中链接相关动态库
```txt
target_link_libraries(entry PUBLIC libhuks_ndk.z.so)
```

## 开发步骤

1. 构造对应参数。
   - keyAlias：密钥别名，封装成[OH_Huks_Blob](../../reference/apis-universal-keystore-kit/capi-hukstypeapi-oh-huks-blob.md)结构，密钥别名最大长度为128字节。
   - paramSetIn：预留参数，暂不需要处理，传空即可。
   - key：用于放置导出的公钥，为[OH_Huks_Blob](../../reference/apis-universal-keystore-kit/capi-hukstypeapi-oh-huks-blob.md)类型对象，需要业务提前申请好内存，需申请足够容纳获取到的密钥属性集的内存大小。

2. 调用接口[OH_Huks_GetKeyItemParamSet](../../reference/apis-universal-keystore-kit/capi-native-huks-api-h.md#oh_huks_getkeyitemparamset)，传入上述参数。

3. 返回值为成功码/错误码，导出公钥以标准的X.509规范的DER格式封装在参数key中，具体请参考[公钥材料格式](huks-concepts.md#公钥材料格式)。

```c++
#include "huks/native_huks_api.h"
#include "huks/native_huks_param.h"
#include "napi/native_api.h"
#include <cstring>

/* 以下以生成ECC密钥为例 */
OH_Huks_Result InitParamSet(struct OH_Huks_ParamSet **paramSet, const struct OH_Huks_Param *params,
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

struct OH_Huks_Param g_testGenerateKeyParam[] = {{.tag = OH_HUKS_TAG_ALGORITHM, .uint32Param = OH_HUKS_ALG_ECC},
                                                 {.tag = OH_HUKS_TAG_PURPOSE, .uint32Param = OH_HUKS_KEY_PURPOSE_AGREE},
                                                 {.tag = OH_HUKS_TAG_KEY_SIZE, .uint32Param = OH_HUKS_ECC_KEY_SIZE_256},
                                                 {.tag = OH_HUKS_TAG_DIGEST, .uint32Param = OH_HUKS_DIGEST_NONE}};

static OH_Huks_Result GenerateKeyHelper(const char *alias)
{
    struct OH_Huks_Blob aliasBlob = {.size = (uint32_t)strlen(alias), .data = (uint8_t *)alias};
    struct OH_Huks_ParamSet *testGenerateKeyParamSet = nullptr;
    struct OH_Huks_Result ohResult;
    do {
        /* 1.初始化密钥属性集 */
        ohResult = InitParamSet(&testGenerateKeyParamSet, g_testGenerateKeyParam,
                                sizeof(g_testGenerateKeyParam) / sizeof(OH_Huks_Param));
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        /* 2.生成密钥 */
        ohResult = OH_Huks_GenerateKeyItem(&aliasBlob, testGenerateKeyParamSet, nullptr);
    } while (0);
    OH_Huks_FreeParamSet(&testGenerateKeyParamSet);
    return ohResult;
}

static napi_value ExportKey(napi_env env, napi_callback_info info)
{
    /* 1. 参数构造：确定密钥别名 */
    const char *alias = "test_key";
    struct OH_Huks_Blob aliasBlob = { .size = (uint32_t)strlen(alias), .data = (uint8_t *)alias };

    /* 生成密钥 */
    OH_Huks_Result genResult = GenerateKeyHelper(alias);
    if (genResult.errorCode != OH_HUKS_SUCCESS) {
        napi_value ret;
        napi_create_int32(env, genResult.errorCode, &ret);
        return ret;
    }

    /* 构造参数：为待导出公钥申请内存 */
    uint8_t *pubKey = (uint8_t *)malloc(512); // 请业务按实际密钥大小评估申请
    if (pubKey == nullptr) {
        return nullptr;
    }
    struct OH_Huks_Blob keyBlob = { 256, pubKey };
    struct OH_Huks_Result ohResult;
    do {
        ohResult = OH_Huks_ExportPublicKeyItem(&aliasBlob, nullptr, &keyBlob);
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
    } while (0);
    free(pubKey);
    napi_value ret;
    napi_create_int32(env, ohResult.errorCode, &ret);
    return ret;
}
```
