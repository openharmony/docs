# Non-anonymous Key Attestation (C/C++)

<!--Kit: Universal Keystore Kit-->
<!--Subsystem: Security-->
<!--Owner: @wutiantian-gitee-->
<!--Designer: @HighLowWorld-->
<!--Tester: @wxy1234564846-->
<!--Adviser: @zengyawen-->

The caller must have the [ohos.permission.ATTEST_KEY](../AccessToken/permissions-for-system-apps.md#ohospermissionattest_key) permission. You need to request the permission based on the APL of your permission. For details, see [Workflow for Using Permissions](../AccessToken/determine-application-mode.md).

## Add the dynamic library in the CMake script.
```txt
target_link_libraries(entry PUBLIC libhuks_ndk.z.so)
```

## How to Develop

1. Specify the key alias. For details about the naming rules, see [Key Generation Overview and Algorithm Specifications](huks-key-generation-overview.md).

2. Initialize the parameter set: Construct **paramSet** via [OH_Huks_InitParamSet](../../reference/apis-universal-keystore-kit/capi-native-huks-param-h.md#oh_huks_initparamset), [OH_Huks_AddParams](../../reference/apis-universal-keystore-kit/capi-native-huks-param-h.md#oh_huks_addparams), and [OH_Huks_BuildParamSet](../../reference/apis-universal-keystore-kit/capi-native-huks-param-h.md#oh_huks_buildparamset), and specify the algorithm, key size, and key usage attributes via [OH_HUKS_TAG_ALGORITHM](../../reference/apis-universal-keystore-kit/capi-native-huks-type-h.md#oh_huks_keyalg), [OH_HUKS_TAG_KEY_SIZE](../../reference/apis-universal-keystore-kit/capi-native-huks-type-h.md#oh_huks_keysize), and [OH_HUKS_TAG_PURPOSE](../../reference/apis-universal-keystore-kit/capi-native-huks-type-h.md#oh_huks_keypurpose).

3. Generate an asymmetric key. For details, see [Key Generation](huks-key-generation-ndk.md).

4. Use [OH_Huks_AttestKeyItem](../../reference/apis-universal-keystore-kit/capi-native-huks-api-h.md#oh_huks_attestkeyitem) with the key alias and parameter set to perform key attestation.

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
    return 0;
}
static struct OH_Huks_Param g_genAttestParams[] = {
    { .tag = OH_HUKS_TAG_ALGORITHM, .uint32Param = OH_HUKS_ALG_RSA },
    { .tag = OH_HUKS_TAG_KEY_SIZE, .uint32Param = OH_HUKS_RSA_KEY_SIZE_2048 },
    { .tag = OH_HUKS_TAG_PURPOSE, .uint32Param = OH_HUKS_KEY_PURPOSE_VERIFY },
    { .tag = OH_HUKS_TAG_DIGEST, .uint32Param = OH_HUKS_DIGEST_SHA256 },
    { .tag = OH_HUKS_TAG_PADDING, .uint32Param = OH_HUKS_PADDING_PSS },
    { .tag = OH_HUKS_TAG_BLOCK_MODE, .uint32Param = OH_HUKS_MODE_ECB },
};
#define CHALLENGE_DATA "hi_challenge_data"
static struct OH_Huks_Blob g_challenge = { sizeof(CHALLENGE_DATA), (uint8_t *)CHALLENGE_DATA };
static napi_value AttestKey(napi_env env, napi_callback_info info) 
{
    /* 1. Set the key alias. */
    struct OH_Huks_Blob genAlias = {
        (uint32_t)strlen("test_attest"),
        (uint8_t *)"test_attest"
    };
    static struct OH_Huks_Param g_attestParams[] = {
        { .tag = OH_HUKS_TAG_ATTESTATION_CHALLENGE, .blob = g_challenge },
        { .tag = OH_HUKS_TAG_ATTESTATION_ID_ALIAS, .blob = genAlias },
    };
    struct OH_Huks_ParamSet *genParamSet = nullptr;
    struct OH_Huks_ParamSet *attestParamSet = nullptr;
    OH_Huks_Result ohResult;
    OH_Huks_Blob certs = { 0 };
    OH_Huks_CertChain certChain = { &certs, 0 };
    do {
        /* 2. Initialize the key parameter set. */
        ohResult = InitParamSet(&genParamSet, g_genAttestParams, sizeof(g_genAttestParams) / sizeof(OH_Huks_Param));
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        ohResult = InitParamSet(&attestParamSet, g_attestParams, sizeof(g_attestParams) / sizeof(OH_Huks_Param));
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
        /* 3. Attest the key. */
        ohResult = OH_Huks_AttestKeyItem(&genAlias, attestParamSet, &certChain);
    } while (0);
    FreeCertChain(&certChain, CERT_COUNT);
    OH_Huks_FreeParamSet(&genParamSet);
    OH_Huks_FreeParamSet(&attestParamSet);
    (void)OH_Huks_DeleteKeyItem(&genAlias, NULL);
    
    napi_value ret;
    napi_create_int32(env, ohResult.errorCode, &ret);
    return ret;
}
```
