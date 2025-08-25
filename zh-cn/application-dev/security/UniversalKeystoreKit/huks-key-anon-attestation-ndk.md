# 匿名密钥证明(C/C++)

<!--Kit: Universal Keystore Kit-->
<!--Subsystem: Security-->
<!--Owner: @wutiantian-gitee-->
<!--Designer: @HighLowWorld-->
<!--Tester: @wxy1234564846-->
<!--Adviser: @zengyawen-->

在使用本功能时，需确保网络通畅。

## 在CMake脚本中链接相关动态库
```txt
target_link_libraries(entry PUBLIC libhuks_ndk.z.so)
```

## 开发步骤

1. 指定密钥别名，密钥别名命名规范参考[密钥生成介绍及算法规格](huks-key-generation-overview.md)。

2. 初始化参数集：通过[OH_Huks_InitParamSet](../../reference/apis-universal-keystore-kit/capi-native-huks-param-h.md#oh_huks_initparamset)、[OH_Huks_AddParams](../../reference/apis-universal-keystore-kit/capi-native-huks-param-h.md#oh_huks_addparams)、[OH_Huks_BuildParamSet](../../reference/apis-universal-keystore-kit/capi-native-huks-param-h.md#oh_huks_buildparamset)构造参数集paramSet，参数集中必须包含[OH_Huks_KeyAlg](../../reference/apis-universal-keystore-kit/capi-native-huks-type-h.md#oh_huks_keyalg)，[OH_Huks_KeySize](../../reference/apis-universal-keystore-kit/capi-native-huks-type-h.md#oh_huks_keysize)，[OH_Huks_KeyPurpose](../../reference/apis-universal-keystore-kit/capi-native-huks-type-h.md#oh_huks_keypurpose)属性。

3. 将密钥别名与参数集作为参数传入[OH_Huks_AnonAttestKeyItem](../../reference/apis-universal-keystore-kit/capi-native-huks-api-h.md#oh_huks_anonattestkeyitem)方法中，即可证明密钥。

```c++
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
static uint32_t g_size = 4096;
static uint32_t CERT_COUNT = 4;
void FreeCertChain(struct OH_Huks_CertChain *certChain, const uint32_t pos)
{
    if (certChain == nullptr || certChain->certs == nullptr) {
        return;
    }
    for (uint32_t j = 0; j < pos; j++) {
        if (certChain->certs[j].data != nullptr) {
            free(certChain->certs[j].data);
            certChain->certs[j].data = nullptr;
        }
    }
    if (certChain->certs != nullptr) {
        free(certChain->certs);
        certChain->certs = nullptr;
    }
}
int32_t ConstructDataToCertChain(struct OH_Huks_CertChain *certChain)
{
    if (certChain == nullptr) {
        return OH_HUKS_ERR_CODE_ILLEGAL_ARGUMENT;
    }
    certChain->certsCount = CERT_COUNT;
  
    certChain->certs = (struct OH_Huks_Blob *)malloc(sizeof(struct OH_Huks_Blob) * (certChain->certsCount));
    if (certChain->certs == nullptr) {
        return OH_HUKS_ERR_CODE_INTERNAL_ERROR;
    }
    for (uint32_t i = 0; i < certChain->certsCount; i++) {
        certChain->certs[i].size = g_size;
        certChain->certs[i].data = (uint8_t *)malloc(certChain->certs[i].size);
        if (certChain->certs[i].data == nullptr) {
            FreeCertChain(certChain, i);
            return OH_HUKS_ERR_CODE_INTERNAL_ERROR;
        }
    }
    return OH_HUKS_SUCCESS;
}
static struct OH_Huks_Param g_genAnonAttestParams[] = {
    { .tag = OH_HUKS_TAG_ALGORITHM, .uint32Param = OH_HUKS_ALG_RSA },
    { .tag = OH_HUKS_TAG_KEY_SIZE, .uint32Param = OH_HUKS_RSA_KEY_SIZE_2048 },
    { .tag = OH_HUKS_TAG_PURPOSE, .uint32Param = OH_HUKS_KEY_PURPOSE_VERIFY },
    { .tag = OH_HUKS_TAG_DIGEST, .uint32Param = OH_HUKS_DIGEST_SHA256 },
    { .tag = OH_HUKS_TAG_PADDING, .uint32Param = OH_HUKS_PADDING_PSS },
    { .tag = OH_HUKS_TAG_BLOCK_MODE, .uint32Param = OH_HUKS_MODE_ECB },
};
#define CHALLENGE_DATA "hi_challenge_data"
static struct OH_Huks_Blob g_challenge = { sizeof(CHALLENGE_DATA), (uint8_t *)CHALLENGE_DATA };
static napi_value AnonAttestKey(napi_env env, napi_callback_info info) 
{
    /* 1.确定密钥别名 */
    struct OH_Huks_Blob genAlias = {
        (uint32_t)strlen("test_anon_attest"),
        (uint8_t *)"test_anon_attest"
    };
    static struct OH_Huks_Param g_anonAttestParams[] = {
        { .tag = OH_HUKS_TAG_ATTESTATION_CHALLENGE, .blob = g_challenge },
        { .tag = OH_HUKS_TAG_ATTESTATION_ID_ALIAS, .blob = genAlias },
    };
    struct OH_Huks_ParamSet *genParamSet = nullptr;
    struct OH_Huks_ParamSet *anonAttestParamSet = nullptr;
    OH_Huks_Result ohResult;
    OH_Huks_Blob certs = { 0 };
    OH_Huks_CertChain certChain = { &certs, 0 };
    do {
        /* 2.初始化密钥参数集 */
        ohResult = InitParamSet(&genParamSet, g_genAnonAttestParams, sizeof(g_genAnonAttestParams) / sizeof(OH_Huks_Param));
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        ohResult = InitParamSet(&anonAttestParamSet, g_anonAttestParams, sizeof(g_anonAttestParams) / sizeof(OH_Huks_Param));
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        ohResult = OH_Huks_GenerateKeyItem(&genAlias, genParamSet, nullptr);
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        
        ohResult.errorCode = ConstructDataToCertChain(&certChain);
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        /* 3.证明密钥 */
        ohResult = OH_Huks_AnonAttestKeyItem(&genAlias, anonAttestParamSet, &certChain);
    } while (0);
    FreeCertChain(&certChain, CERT_COUNT);
    OH_Huks_FreeParamSet(&genParamSet);
    OH_Huks_FreeParamSet(&anonAttestParamSet);
    (void)OH_Huks_DeleteKeyItem(&genAlias, NULL);
    
    napi_value ret;
    napi_create_int32(env, ohResult.errorCode, &ret);
    return ret;
}
```
