# 明文导入密钥(C/C++)


以明文导入ECC密钥为例。具体的场景介绍及支持的算法规格，请参考[密钥导入的支持的算法](huks-key-import-overview.md#支持的算法)。

## 在CMake脚本中链接相关动态库
```txt
   target_link_libraries(entry PUBLIC libhuks_ndk.z.so)
```

## 开发步骤

1. 指定密钥别名keyAlias。
   密钥别名的最大长度为128字节。

2. 封装密钥属性集和密钥材料。通过[OH_Huks_InitParamSet](../../reference/apis-universal-keystore-kit/_huks_param_set_api.md#oh_huks_initparamset)、[OH_Huks_AddParams](../../reference/apis-universal-keystore-kit/_huks_param_set_api.md#oh_huks_addparams)、[OH_Huks_BuildParamSet](../../reference/apis-universal-keystore-kit/_huks_param_set_api.md#oh_huks_buildparamset)构造密钥属性集paramSet。
   - 密钥属性集中必须包含[OH_Huks_KeyAlg](../../reference/apis-universal-keystore-kit/_huks_type_api.md#oh_huks_keyalg)、[OH_Huks_KeySize](../../reference/apis-universal-keystore-kit/_huks_type_api.md#oh_huks_keysize)、[OH_Huks_KeyPurpose](../../reference/apis-universal-keystore-kit/_huks_type_api.md#oh_huks_keypurpose)属性。
   - 密钥材料须符合[HUKS密钥材料格式](huks-concepts.md#密钥材料格式)。

3. 调用[OH_Huks_ImportKeyItem](../../reference/apis-universal-keystore-kit/_huks_key_api.md#oh_huks_importkeyitem)，传入密钥别名和密钥属性集，导入密钥。

```c++
/* 以下以明文导入ECC密钥为例 */
#include "huks/native_huks_api.h"
#include "huks/native_huks_param.h"
#include <string.h>
OH_Huks_Result InitParamSet(struct OH_Huks_ParamSet **paramSet, const struct OH_Huks_Param *params,
                            uint32_t paramCount) {
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
struct OH_Huks_Param g_testImportKeyParam[] = {{.tag = OH_HUKS_TAG_ALGORITHM, .uint32Param = OH_HUKS_ALG_ECC},
                                                 {.tag = OH_HUKS_TAG_PURPOSE, .uint32Param = OH_HUKS_KEY_PURPOSE_AGREE},
                                                 {.tag = OH_HUKS_TAG_KEY_SIZE, .uint32Param = OH_HUKS_ECC_KEY_SIZE_256},
                                                 {.tag = OH_HUKS_TAG_DIGEST, .uint32Param = OH_HUKS_DIGEST_NONE}};

static napi_value ImportKey(napi_env env, napi_callback_info info) {
    const char *alias = "test_import";
    struct OH_Huks_Blob aliasBlob = {.size = (uint32_t)strlen(alias), .data = (uint8_t *)alias};
    /* DER格式的公钥，用于后续导入密钥 */
    uint8_t pubKey[OH_HUKS_ECC_KEY_SIZE_256] = {
        0x30, 0x2A, 0x30, 0x05, 0x06, 0x03, 0x2B, 0x65, 0x6E, 0x03, 0x21, 0x00, 0xD2, 0x36, 0x9E, 0xCF,
        0xF0, 0x61, 0x5B, 0x73, 0xCE, 0x4F, 0xF0, 0x40, 0x2B, 0x89, 0x18, 0x3E, 0x06, 0x33, 0x60, 0xC6
    };
    struct OH_Huks_Blob publicKey = {OH_HUKS_ECC_KEY_SIZE_256, pubKey};
    struct OH_Huks_ParamSet *testImportKeyParamSet = nullptr;
    struct OH_Huks_Result ohResult;
    do {
        ohResult = InitParamSet(&testImportKeyParamSet, g_testImportKeyParam,
                                sizeof(g_testImportKeyParam) / sizeof(OH_Huks_Param));
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
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
