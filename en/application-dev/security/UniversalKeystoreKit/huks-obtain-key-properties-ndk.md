# Obtaining Key Properties (C/C++)

<!--Kit: Universal Keystore Kit-->
<!--Subsystem: Security-->
<!--Owner: @wutiantian-gitee-->
<!--Designer: @HighLowWorld-->
<!--Tester: @wxy1234564846-->
<!--Adviser: @zengyawen-->

This topic describes how to obtain properties of a key. Before the operation, ensure that the key exists in HUKS.
>**NOTE**<br>
> The mini-system devices do not support the operation for obtaining key properties.

## Add the dynamic library in the CMake script.
```txt
target_link_libraries(entry PUBLIC libhuks_ndk.z.so)
```
## How to Develop

1. Set parameters.
   - **keyAlias**: key alias encapsulated in an [OH_Huks_Blob](../../reference/apis-universal-keystore-kit/capi-hukstypeapi-oh-huks-blob.md) struct. The maximum length of the key alias is 128 bytes.
   - **paramSetIn**: This parameter is reserved. Leave it empty.
   - **paramSetOut**: result set used to hold the key properties obtained. It is an object of the [OH_Huks_ParamSet](../../reference/apis-universal-keystore-kit/capi-hukstypeapi-oh-huks-paramset.md) type. Ensure that there is enough memory for storing the key properties obtained.

2. Call [OH_Huks_GetKeyItemParamSet](../../reference/apis-universal-keystore-kit/capi-native-huks-api-h.md#oh_huks_getkeyitemparamset) to pass in the preceding parameters.

3. Check the return value. If the operation is successful, obtain the key properties from **paramSetOut**. If the operation fails, an error code is returned.

```c++
#include "huks/native_huks_api.h"
#include "huks/native_huks_param.h"
#include "napi/native_api.h"
#include <cstring>

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
        /* 1. Generate a key. */
        ohResult = OH_Huks_GenerateKeyItem(&aliasBlob, testGenerateKeyParamSet, nullptr);
    } while (0);
    OH_Huks_FreeParamSet(&testGenerateKeyParamSet);
    return ohResult;
}

static napi_value GetKeyParamSet(napi_env env, napi_callback_info info)
{
    /* 1. Set the key alias. */
    const char *alias = "test_key";
    struct OH_Huks_Blob aliasBlob = { .size = (uint32_t)strlen(alias), .data = (uint8_t *)alias };

    /* Generate a key. */
    OH_Huks_Result genResult = GenerateKeyHelper(alias);
    if (genResult.errorCode != OH_HUKS_SUCCESS) {
        napi_value ret;
        napi_create_int32(env, genResult.errorCode, &ret);
        return ret;
    }

    const size_t paramSetSize = 512;
    /* Request memory for outParamSet. */
     * Request memory according to your evaluated needs.
     */
    struct OH_Huks_ParamSet *outParamSet = static_cast<struct OH_Huks_ParamSet *>(malloc(paramSetSize));
    if (outParamSet == nullptr) {
        return nullptr;
    }
    outParamSet->paramSetSize = paramSetSize;
    struct OH_Huks_Result ohResult;
    do {
        /* 2. Obtain the key properties. */
        ohResult = OH_Huks_GetKeyItemParamSet(&aliasBlob, nullptr, outParamSet);
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        /* 3. Read key properties from outParamSet. For example, obtain OH_HUKS_TAG_PURPOSE. */
        OH_Huks_Param *purposeParam = nullptr; // No memory needs to be requested. After the parameter is obtained, the pointer points to the memory address of the parameter in the parameter set.
        ohResult = OH_Huks_GetParam(outParamSet, OH_HUKS_TAG_PURPOSE, &purposeParam);
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
    } while (0);
    OH_Huks_FreeParamSet(&outParamSet);
    napi_value ret;
    napi_create_int32(env, ohResult.errorCode, &ret);
    return ret;
}
```
