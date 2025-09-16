# Importing a Key in Plaintext (C/C++)

<!--Kit: Universal Keystore Kit-->
<!--Subsystem: Security-->
<!--Owner: @wutiantian-gitee-->
<!--Designer: @HighLowWorld-->
<!--Tester: @wxy1234564846-->
<!--Adviser: @zengyawen-->

This topic walks you through on how to import an ECC key. For details about the scenarios and supported algorithm specifications, see [Supported Algorithms](huks-key-import-overview.md#supported-algorithms).

## Add the dynamic library in the CMake script.
```txt
target_link_libraries(entry PUBLIC libhuks_ndk.z.so)
```
## How to Develop

1. Specify the key alias. For details about the naming rules, see [Key Generation Overview and Algorithm Specifications](huks-key-generation-overview.md).

2. Encapsulate the key property set and key material. Construct **paramSet** using [OH_Huks_InitParamSet](../../reference/apis-universal-keystore-kit/capi-native-huks-param-h.md#oh_huks_initparamset), [OH_Huks_AddParams](../../reference/apis-universal-keystore-kit/capi-native-huks-param-h.md#oh_huks_addparams), and [OH_Huks_BuildParamSet](../../reference/apis-universal-keystore-kit/capi-native-huks-param-h.md#oh_huks_buildparamset).
   - The key property set must contain the [OH_Huks_KeyAlg](../../reference/apis-universal-keystore-kit/capi-native-huks-type-h.md#oh_huks_keyalg), [OH_Huks_KeySize](../../reference/apis-universal-keystore-kit/capi-native-huks-type-h.md#oh_huks_keysize), and [OH_Huks_KeyPurpose](../../reference/apis-universal-keystore-kit/capi-native-huks-type-h.md#oh_huks_keypurpose) properties.
   - The key material must comply with the [HUKS key material format](huks-concepts.md#key-material-format).

3. Call [OH_Huks_ImportKeyItem](../../reference/apis-universal-keystore-kit/capi-native-huks-api-h.md#oh_huks_importkeyitem) and pass in the key alias and key property set to import the key.

```c++
/* Import an AES key in plaintext. */
#include "huks/native_huks_api.h"
#include "huks/native_huks_param.h"
#include "napi/native_api.h"
#include <cstring>

#define OH_HUKS_AES_KEY_SIZE_32 32

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
struct OH_Huks_Param g_testImportKeyParam[] = {{.tag = OH_HUKS_TAG_ALGORITHM, .uint32Param = OH_HUKS_ALG_AES},
                                               {.tag = OH_HUKS_TAG_PURPOSE, .uint32Param = OH_HUKS_KEY_PURPOSE_ENCRYPT},
                                               {.tag = OH_HUKS_TAG_KEY_SIZE, .uint32Param = OH_HUKS_AES_KEY_SIZE_256},
                                               {.tag = OH_HUKS_TAG_DIGEST, .uint32Param = OH_HUKS_DIGEST_NONE}};

static napi_value ImportKey(napi_env env, napi_callback_info info) {
    const char *alias = "test_import";
    struct OH_Huks_Blob aliasBlob = {.size = (uint32_t)strlen(alias), .data = (uint8_t *)alias};
    /* Key in the DER format, which is used to import the key. */
    uint8_t pubKey[OH_HUKS_AES_KEY_SIZE_32] = {0xfb, 0x8b, 0x9f, 0x12, 0xa0, 0x83, 0x19, 0xbe, 0x6a, 0x6f, 0x63,
                                               0x2a, 0x7c, 0x86, 0xba, 0xca, 0x64, 0x0b, 0x88, 0x96, 0xe2, 0xfa,
                                               0x77, 0xbc, 0x71, 0xe3, 0x0f, 0x0f, 0x9e, 0x3c, 0xe5, 0xf9};
    struct OH_Huks_Blob publicKey = {OH_HUKS_AES_KEY_SIZE_32, pubKey};
    struct OH_Huks_ParamSet *testImportKeyParamSet = nullptr;
    struct OH_Huks_Result ohResult;
    do {
        ohResult = InitParamSet(&testImportKeyParamSet, g_testImportKeyParam,
                                sizeof(g_testImportKeyParam) / sizeof(OH_Huks_Param));
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        /* 4. Import Key */
        char newKey[] = "test_import";
        struct OH_Huks_Blob newKeyAlias = {.size = (uint32_t)strlen(newKey), .data = (uint8_t *)newKey};
        ohResult = OH_Huks_ImportKeyItem(&newKeyAlias, testImportKeyParamSet, &publicKey);
    } while (0);
    OH_Huks_FreeParamSet(&testImportKeyParamSet);
    napi_value ret;
    napi_create_int32(env, ohResult.errorCode, &ret);
    return ret;
}
```
