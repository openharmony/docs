# Generating a Key (C/C++)

<!--Kit: Universal Keystore Kit-->
<!--Subsystem: Security-->
<!--Owner: @wutiantian-gitee-->
<!--Designer: @HighLowWorld-->
<!--Tester: @wxy1234564846-->
<!--Adviser: @zengyawen-->

This topic walks you through on how to randomly generate a key with the ECC algorithm. For details about the scenarios and supported algorithms, see [Supported Algorithms](huks-key-generation-overview.md#supported-algorithms).

> **NOTE**
> Key aliases must not contain sensitive information, such as personal data.

## Add the dynamic library in the CMake script.
```txt
target_link_libraries(entry PUBLIC libhuks_ndk.z.so)
```

## How to Develop

1. Set the alias (**keyAlias**) of the key to generate.
   - The key alias can contain a maximum of 128 bytes and cannot contain sensitive information, such as personal data.
   - For the keys generated for different services, HUKS isolates the storage paths based on the service identity information to prevent conflicts caused by the same key alias.

2. Initialize the key property set. Construct **paramSet** using [OH_Huks_InitParamSet](../../reference/apis-universal-keystore-kit/capi-native-huks-param-h.md#oh_huks_initparamset), [OH_Huks_AddParams](../../reference/apis-universal-keystore-kit/capi-native-huks-param-h.md#oh_huks_addparams), and [OH_Huks_BuildParamSet](../../reference/apis-universal-keystore-kit/capi-native-huks-param-h.md#oh_huks_buildparamset).
   The key property set must contain the [OH_Huks_KeyAlg](../../reference/apis-universal-keystore-kit/capi-native-huks-type-h.md#oh_huks_keyalg), [OH_Huks_KeySize](../../reference/apis-universal-keystore-kit/capi-native-huks-type-h.md#oh_huks_keysize), and [OH_Huks_KeyPurpose](../../reference/apis-universal-keystore-kit/capi-native-huks-type-h.md#oh_huks_keypurpose) properties. Note that a key can have only one purpose, and the purpose specified during key generation must match the key purpose during usage. Otherwise, an exception occurs.

3. Call [OH_Huks_GenerateKeyItem](../../reference/apis-universal-keystore-kit/capi-native-huks-api-h.md#oh_huks_generatekeyitem) and pass in the key alias and key property set to generate a key.

> **NOTE**<br>
> If the service uses the same key alias to call the HUKS API to generate a key again, HUKS will generate a new key and overwrite the historical key file.

```c++
/* Generate an ECC key. */
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
struct OH_Huks_Param g_testGenerateKeyParam[] = {
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
static napi_value GenerateKey(napi_env env, napi_callback_info info)
{
    /* 1. Set the key alias. */
    const char *alias = "test_generate";
    struct OH_Huks_Blob aliasBlob = { .size = (uint32_t)strlen(alias), .data = (uint8_t *)alias };
    struct OH_Huks_ParamSet *testGenerateKeyParamSet = nullptr;
    struct OH_Huks_Result ohResult;
    do {
        /* 2. Initialize the key property set. */
        ohResult = InitParamSet(&testGenerateKeyParamSet, g_testGenerateKeyParam,
            sizeof(g_testGenerateKeyParam) / sizeof(OH_Huks_Param));
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        /* 3. Generate a key. */
        ohResult = OH_Huks_GenerateKeyItem(&aliasBlob, testGenerateKeyParamSet, nullptr);
    } while (0);
    OH_Huks_FreeParamSet(&testGenerateKeyParamSet);
    napi_value ret;
    napi_create_int32(env, ohResult.errorCode, &ret);
    return ret;
}
```
