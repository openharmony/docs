# Deleting a Key (C/C++)

<!--Kit: Universal Keystore Kit-->
<!--Subsystem: Security-->
<!--Owner: @wutiantian-gitee-->
<!--Designer: @HighLowWorld-->
<!--Tester: @wxy1234564846-->
<!--Adviser: @zengyawen-->
<!-- md-trans-meta sourceCommit=563f6cbe97a48075421f43945c8ff7682c983314 translatedAt=2026-08-13T08:20:48.684Z pushedAt=2026-08-13T10:20:24.676Z -->

To ensure data security, delete the key that is no longer required.

The [Group Key](huks-group-key-overview.md) feature is supported since API version 23.

## Linking the Dynamic Library in the CMake Script

```txt
target_link_libraries(entry PUBLIC libhuks_ndk.z.so)
```

## How to Develop

The following uses deleting an ECC key as an example.

1. Specify the key alias. For details about the naming rules, see [Key Generation Overview and Algorithm Specifications](huks-key-generation-overview.md).

2. Initialize the key property set. This is used to specify the properties for deleting the key. If a single key or non-group key is deleted, this set can be left empty.

3. Use [OH_Huks_DeleteKeyItem](../../reference/apis-universal-keystore-kit/capi-native-huks-api-h.md#oh_huks_deletekeyitem) to delete the key.

<!-- @[key_deletion_cpp](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Security/UniversalKeystoreKit/KeyDeletion/entry/src/main/cpp/napi_init.cpp) -->

``` C++
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

/* 1. Generate a key. */
static OH_Huks_Result GenerateKeyHelper(const char *alias)
{
    struct OH_Huks_Blob aliasBlob = {.size = (uint32_t)strlen(alias), .data = (uint8_t *)alias};
    struct OH_Huks_ParamSet *testGenerateKeyParamSet = nullptr;
    struct OH_Huks_Result ohResult;

    do {
        ohResult = InitParamSet(&testGenerateKeyParamSet, g_testGenerateKeyParam,
                                sizeof(g_testGenerateKeyParam) / sizeof(OH_Huks_Param));
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }

        ohResult = OH_Huks_GenerateKeyItem(&aliasBlob, testGenerateKeyParamSet, nullptr);
    } while (0);
    
    OH_Huks_FreeParamSet(&testGenerateKeyParamSet);
    return ohResult;
}

static napi_value DeleteKey(napi_env env, napi_callback_info info)
{
    const char *alias = "test_key";
    struct OH_Huks_Blob keyAlias = {
        (uint32_t)strlen("test_key"),
        (uint8_t *)"test_key"
    };
    
    /* 1. Generate a key. */
    OH_Huks_Result genResult = GenerateKeyHelper(alias);
    if (genResult.errorCode != OH_HUKS_SUCCESS) {
        napi_value ret;
        napi_create_int32(env, genResult.errorCode, &ret);
        return ret;
    }

    /* 2. Delete the key. */
    struct OH_Huks_Result ohResult = OH_Huks_DeleteKeyItem(&keyAlias, nullptr);

    napi_value ret;
    napi_create_int32(env, ohResult.errorCode, &ret);
    return ret;
}
```