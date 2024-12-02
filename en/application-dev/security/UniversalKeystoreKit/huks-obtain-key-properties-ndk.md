# Obtaining Key Properties (C/C++)


This topic describes how to obtain properties of a key. Before the operation, ensure that the key exists in HUKS.
>**NOTE**<br>
> The mini-system devices do not support the operation for obtaining key properties.

## Add the dynamic library in the CMake script.
```txt
   target_link_libraries(entry PUBLIC libhuks_ndk.z.so)
```

## How to Develop

1. Set parameters.
   - **keyAlias**: key alias encapsulated in an [OH_Huks_Blob](../../reference/apis-universal-keystore-kit/_o_h___huks___blob.md) struct. The maximum length of the key alias is 64 bytes.
   - **paramSetIn**: This parameter is reserved. Leave it empty.
   - **paramSetOut**: result set used to hold the key properties obtained. It is an object of the [OH_Huks_ParamSet](../../reference/apis-universal-keystore-kit/_o_h___huks___param_set.md) type. Ensure that there is enough memory for storing the key properties obtained.

2. Use [OH_Huks_GetKeyItemParamSet](../../reference/apis-universal-keystore-kit/_huks_key_api.md#oh_huks_getkeyitemparamset) to obtain key properties.

3. Check the return value. If the operation is successful, obtain the key properties from **paramSetOut**. If the operation fails, an error code is returned.

```c++
#include "huks/native_huks_api.h"
#include "huks/native_huks_param.h"
#include <string.h>
static napi_value GetKeyParamSet(napi_env env, napi_callback_info info)
{
    /* 1. Set the key alias. */
    const char *alias = "test_key";
    struct OH_Huks_Blob aliasBlob = { .size = (uint32_t)strlen(alias), .data = (uint8_t *)alias };
    /* Request memory for outParamSet. */
    struct OH_Huks_ParamSet *outParamSet = (struct OH_Huks_ParamSet *)malloc(512); // Request memory based on service requirements.
    if (outParamSet == nullptr) {
        return nullptr;
    }
    outParamSet->paramSetSize = 512;
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
