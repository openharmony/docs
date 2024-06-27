# 生成密钥(C/C++)


以生成ECC密钥为例，生成随机密钥。具体的场景介绍及支持的算法规格，请参考[密钥生成支持的算法](huks-key-generation-overview.md#支持的算法)。

> **注意：**
> 密钥别名中禁止包含个人数据等敏感信息。

## 在CMake脚本中链接相关动态库
```txt
   target_link_libraries(entry PUBLIC libhuks_ndk.z.so)
```

## 开发步骤

1. 指定待生成的密钥别名keyAlias。
   - 密钥别名的最大长度为64字节。
   - 对于不同业务间生成的密钥，HUKS将基于业务身份信息进行存储路径隔离，不会因为和其他业务密钥同名导致冲突。

2. 初始化密钥属性集。通过[OH_Huks_InitParamSet](../../reference/apis-universal-keystore-kit/_huks_param_set_api.md#oh_huks_initparamset)、[OH_Huks_AddParams](../../reference/apis-universal-keystore-kit/_huks_param_set_api.md#oh_huks_addparams)、[OH_Huks_BuildParamSet](../../reference/apis-universal-keystore-kit/_huks_param_set_api.md#oh_huks_buildparamset)构造密钥属性集paramSet。
   密钥属性集中必须包含[OH_Huks_KeyAlg](../../reference/apis-universal-keystore-kit/_huks_type_api.md#oh_huks_keyalg)、[OH_Huks_KeySize](../../reference/apis-universal-keystore-kit/_huks_type_api.md#oh_huks_keysize)、[OH_Huks_KeyPurpose](../../reference/apis-universal-keystore-kit/_huks_type_api.md#oh_huks_keypurpose)属性。

3. 调用[OH_Huks_GenerateKeyItem](../../reference/apis-universal-keystore-kit/_huks_key_api.md#oh_huks_generatekeyitem)，传入密钥别名和密钥属性集，生成密钥。

> **说明：**
> 如果业务再次使用相同别名调用HUKS生成密钥，HUKS将生成新密钥并直接覆盖历史的密钥文件。

```c++
/* 以下以生成ECC密钥为例 */
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
    /* 1.确定密钥别名 */
    const char *alias = "test_generate";
    struct OH_Huks_Blob aliasBlob = { .size = (uint32_t)strlen(alias), .data = (uint8_t *)alias };
    struct OH_Huks_ParamSet *testGenerateKeyParamSet = nullptr;
    struct OH_Huks_Result ohResult;
    do {
        /* 2.初始化密钥属性集 */
        ohResult = InitParamSet(&testGenerateKeyParamSet, g_testGenerateKeyParam,
            sizeof(g_testGenerateKeyParam) / sizeof(OH_Huks_Param));
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        /* 3.生成密钥 */
        ohResult = OH_Huks_GenerateKeyItem(&aliasBlob, testGenerateKeyParamSet, nullptr);
    } while (0);
    OH_Huks_FreeParamSet(&testGenerateKeyParamSet);
    napi_value ret;
    napi_create_int32(env, ohResult.errorCode, &ret);
    return ret;
}
```
