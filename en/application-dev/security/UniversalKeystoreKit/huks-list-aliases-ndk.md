# Querying Key Aliases (C/C++)

<!--Kit: Universal Keystore Kit-->
<!--Subsystem: Security-->
<!--Owner: @wutiantian-gitee-->
<!--Designer: @HighLowWorld-->
<!--Tester: @wxy1234564846-->
<!--Adviser: @zengyawen-->

This topic walks you through on how to query key aliases.

>**NOTE**<br>
> <!--RP1-->The mini-system devices<!--RP1End--> do not support query of key aliases.

## Add the dynamic library in the CMake script.
```txt
target_link_libraries(entry PUBLIC libhuks_ndk.z.so)
```

## How to Develop

1. Initialize the key property set to query the tags of key aliases. The tags support only [OH_HUKS_TAG_AUTH_STORAGE_LEVEL](../../reference/apis-universal-keystore-kit/capi-native-huks-type-h.md#oh_huks_authstoragelevel).

2. Call [OH_Huks_ListAliases](../../reference/apis-universal-keystore-kit/capi-native-huks-api-h.md#oh_huks_listaliases) to query key aliases.

 ```c++
/* Query key aliases. */
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
struct OH_Huks_Param g_testQueryParam[] = {
    {
        .tag = OH_HUKS_TAG_AUTH_STORAGE_LEVEL,
        .uint32Param = OH_HUKS_AUTH_STORAGE_LEVEL_DE
    }, 
};
static napi_value ListAliases(napi_env env, napi_callback_info info)
{
    struct OH_Huks_ParamSet *testQueryParamSet = nullptr;
    struct OH_Huks_KeyAliasSet *outData = nullptr;
    struct OH_Huks_Result ohResult;
    do {
        /* 1. Initialize the key property set. */
        ohResult = InitParamSet(&testQueryParamSet, g_testQueryParam,
            sizeof(g_testQueryParam) / sizeof(OH_Huks_Param));
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        /* 2. Query key aliases. */
        ohResult = OH_Huks_ListAliases(testQueryParamSet, &outData);
    } while (0);

    OH_Huks_FreeParamSet(&testQueryParamSet);
    OH_Huks_FreeKeyAliasSet(outData);
    napi_value ret;
    napi_create_int32(env, ohResult.errorCode, &ret);
    return ret;
}
```
