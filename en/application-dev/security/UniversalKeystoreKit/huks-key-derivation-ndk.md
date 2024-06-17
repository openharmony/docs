# Key Derivation (C/C++)


This topic walks you through on how to derive a 256-bit key using HKDF. For details about the scenarios and supported algorithms, see [Supported Algorithms](huks-key-generation-overview.md#supported-algorithms).

## Add the dynamic library in the CMake script.
```txt
   target_link_libraries(entry PUBLIC libhuks_ndk.z.so)
```

## How to Develop

**Key Generation**

1. Set the key alias.

2. Initialize the key property set. You can set **OH_HUKS_TAG_DERIVED_AGREED_KEY_STORAGE_FLAG** (optional) to specify how the key derived from this key is managed.

    - If this tag is set to **OH_HUKS_STORAGE_ONLY_USED_IN_HUKS**, the derived key is managed by HUKS. That is, the derived key is always in a secure environment throughout its lifecycle.

    - If this tag is set to **OH_HUKS_STORAGE_KEY_EXPORT_ALLOWED**, the derived key will be returned to the caller for management. That is, the service side ensures the key security.

    - If this tag is not set, the derived key can be either managed by HUKS or returned to the caller for management. The key protection mode can be set in the subsequent key derivation on the service side.

3. Use **OH_Huks_GenerateKeyItem** to generate a key. For details, see [Key Generation](huks-key-generation-overview.md).

Alternatively, you can [import a key](huks-key-import-overview.md).

**Key Derivation**

1. Obtain the key alias and set the **HuksOptions** parameter.

   You can set **OH_HUKS_TAG_DERIVED_AGREED_KEY_STORAGE_FLAG** to specify how the derived key is managed.

    | Key Generation| Key Derivation| Specifications|
    | -------- | -------- | -------- |
    | OH_HUKS_STORAGE_ONLY_USED_IN_HUKS | OH_HUKS_STORAGE_ONLY_USED_IN_HUKS | The key is managed by HUKS.|
    | OH_HUKS_STORAGE_KEY_EXPORT_ALLOWED | OH_HUKS_STORAGE_KEY_EXPORT_ALLOWED | The key is returned to the caller for management.|
    | The tag is not set.| OH_HUKS_STORAGE_ONLY_USED_IN_HUKS | The key is managed by HUKS.|
    | The tag is not set.| OH_HUKS_STORAGE_KEY_EXPORT_ALLOWED | The key is returned to the caller for management.|
    | The tag is not set.| The tag is not set.| The key is returned to the caller for management.|

    >**NOTE**<br>The tag value set in key derivation should not conflict with the tag value set in key generation. The above table lists only valid settings.

2. Use [OH_Huks_InitSession](../../reference/apis-universal-keystore-kit/_huks_key_api.md#oh_huks_initsession) to initialize a key session. The session handle is returned after the initialization.

3. Use [OH_Huks_UpdateSession](../../reference/apis-universal-keystore-kit/_huks_key_api.md#oh_huks_updatesession)n to process data.

4. Use [OH_Huks_FinishSession](../../reference/apis-universal-keystore-kit/_huks_key_api.md#oh_huks_finishsession) to derive a key.

**Key Deletion**

Use **OH_Huks_DeleteKeyItem** to delete the key that is not required. For details, see [Deleting a Key](huks-delete-key-ndk.md).

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
