# Checking a Key (C/C++)

<!--Kit: Universal Keystore Kit-->
<!--Subsystem: Security-->
<!--Owner: @wutiantian-gitee-->
<!--Designer: @HighLowWorld-->
<!--Tester: @wxy1234564846-->
<!--Adviser: @zengyawen-->

Check whether a key exists.

## Add the dynamic library in the CMake script.
```txt
target_link_libraries(entry PUBLIC libhuks_ndk.z.so)
```
## How to Develop

1. Construct the parameters.
   - Specify the key alias. For details about the naming rules, see [Key Generation Overview and Algorithm Specifications](huks-key-generation-overview.md).
   - Set the [property tags](../../reference/apis-universal-keystore-kit/capi-native-huks-type-h.md#oh_huks_tag) required for querying a key. By default, this parameter is left empty.

2. Call [OH_Huks_IsKeyItemExist](../../reference/apis-universal-keystore-kit/capi-native-huks-api-h.md#oh_huks_iskeyitemexist) to check whether the key exists.

```c++
#include "huks/native_huks_api.h"
#include "huks/native_huks_param.h"
#include "napi/native_api.h"
#include <cstring>

/* Generate an ECC key. */
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
        /* 1. Initialize the key property set. */
        ohResult = InitParamSet(&testGenerateKeyParamSet, g_testGenerateKeyParam,
                                sizeof(g_testGenerateKeyParam) / sizeof(OH_Huks_Param));
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        /* 2. Generate a key. */
        ohResult = OH_Huks_GenerateKeyItem(&aliasBlob, testGenerateKeyParamSet, nullptr);
    } while (0);
    OH_Huks_FreeParamSet(&testGenerateKeyParamSet);
    return ohResult;
}

static napi_value IsKeyExist(napi_env env, napi_callback_info info)
{
    /* 1. Obtain the key alias. */
    const char *alias = "test_key";
    struct OH_Huks_Blob keyAlias = {
        (uint32_t)strlen(alias),
        (uint8_t *)alias
    };

    /* Generate a key. */
    OH_Huks_Result genResult = GenerateKeyHelper(alias);
    if (genResult.errorCode != OH_HUKS_SUCCESS) {
        napi_value ret;
        napi_create_int32(env, genResult.errorCode, &ret);
        return ret;
    }

    /* 2. Call OH_Huks_IsKeyItemExist to check whether the key exists. */
    struct OH_Huks_Result ohResult = OH_Huks_IsKeyItemExist(&keyAlias, nullptr);

    napi_value ret;
    napi_create_int32(env, ohResult.errorCode, &ret);
    return ret;
}
```
