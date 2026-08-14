# Key Agreement (C/C++)

<!--Kit: Universal Keystore Kit-->
<!--Subsystem: Security-->
<!--Owner: @wutiantian-gitee-->
<!--Designer: @HighLowWorld-->
<!--Tester: @wxy1234564846-->
<!--Adviser: @zengyawen-->
<!-- md-trans-meta sourceCommit=3278ee705378631554cefba415ca42904851087c translatedAt=2026-08-13T08:23:54.675Z pushedAt=2026-08-13T10:20:24.706Z -->

This topic uses X25519, DH, and ECDH as an example to demonstrate how to perform key agreement for HUKS-managed keys. For details about the scenarios and supported algorithm specifications, see [Supported Algorithms](huks-key-agreement-overview.md#supported-algorithms).

## Linking the Dynamic Library in the CMake Script

```txt
target_link_libraries(entry PUBLIC libhuks_ndk.z.so)
```

## How to Develop

**Key Generation**

Generate an asymmetric key for device A and device B each. For details, see [Key Generation](huks-key-generation-overview.md) or [Key Import](huks-key-import-overview.md).

When generating a key, you can specify the **OH_HUKS_TAG_DERIVED_AGREED_KEY_STORAGE_FLAG** parameter (optional) to indicate whether the key generated is managed by HUKS.

**Key Export**

Export the public key of the asymmetric key pair of device A and device B. For details, see [Key Export](huks-export-key-arkts.md).

**Key Agreement**

Perform key agreement using the public key of the peer device and private key of the local device (that is, public key of device B and private key of device A for device A, and public key of device A and private key of device B for device B) to produce a shared secret.

During key agreement, you can set **OH_HUKS_TAG_DERIVED_AGREED_KEY_STORAGE_FLAG** (optional) to specify how the shared secret generated is managed.

- If this tag is set to **OH_HUKS_STORAGE_ONLY_USED_IN_HUKS**, the shared secret is managed by HUKS. That is, the shared secret is always in a secure environment throughout its lifecycle.

- If this tag is set to **OH_HUKS_STORAGE_KEY_EXPORT_ALLOWED**, the shared secret generated will be returned to the caller for management. That is, the service side ensures the key security.

- If this tag is not set, the shared secret generated can be either managed by HUKS or returned to the caller for management. The key protection mode can be set in the subsequent key agreement on the service side.

| Key Generation| Key Agreement| Specifications|
| -------- | -------- | -------- |
| OH_HUKS_STORAGE_ONLY_USED_IN_HUKS | OH_HUKS_STORAGE_ONLY_USED_IN_HUKS | The key is managed by HUKS.|
| OH_HUKS_STORAGE_KEY_EXPORT_ALLOWED | OH_HUKS_STORAGE_KEY_EXPORT_ALLOWED | The key is returned to the caller for management.|
| The tag is not set.| OH_HUKS_STORAGE_ONLY_USED_IN_HUKS | The key is managed by HUKS.|
| The tag is not set.| OH_HUKS_STORAGE_KEY_EXPORT_ALLOWED | The key is returned to the caller for management.|
| The tag is not set.| The tag is not set.| The key is returned to the caller for management.|

Note: The tag value set in key agreement should not conflict with the tag value set in key generation. The above table lists only valid settings.

**Key Deletion**

Delete the keys from device A and device B when the keys are not required. For details, see [Deleting a Key](huks-delete-key-ndk.md).

## Development Cases

The following uses X25519, DH, and ECDH keys as examples to perform key agreement.

### X25519 Asymmetric Key Agreement

Prepare the X25519 key agreement materials.

<!-- @[prepare_X25519_cpp](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Security/UniversalKeystoreKit/KeyUsage/KeyExchange/entry/src/main/cpp/types/projects/napi_X25519.cpp) -->

``` C++
#include "huks/native_huks_api.h"
#include "huks/native_huks_param.h"
#include "napi/native_api.h"
#include <cstring>
#include "file.h"

/* Initialize parameters. */
static OH_Huks_Result InitParamSet(struct OH_Huks_ParamSet **paramSet, const struct OH_Huks_Param *params,
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
static struct OH_Huks_Blob g_keyAliasFinal1001 = {(uint32_t)strlen("HksECDHAgreeKeyAliasTest001_1_final"),
                                                  (uint8_t *)"HksECDHAgreeKeyAliasTest001_1_final"};
/* Set the key parameter set. */
static struct OH_Huks_Param g_genAgreeParams[] = {
    {.tag = OH_HUKS_TAG_ALGORITHM, .uint32Param = OH_HUKS_ALG_X25519},
    {.tag = OH_HUKS_TAG_PURPOSE, .uint32Param = OH_HUKS_KEY_PURPOSE_AGREE},
    {.tag = OH_HUKS_TAG_KEY_SIZE, .uint32Param = OH_HUKS_CURVE25519_KEY_SIZE_256},
    {.tag = OH_HUKS_TAG_DIGEST, .uint32Param = OH_HUKS_DIGEST_NONE}};
static struct OH_Huks_Param g_agreeParamsInit01[] = {
    {.tag = OH_HUKS_TAG_ALGORITHM, .uint32Param = OH_HUKS_ALG_X25519},
    {.tag = OH_HUKS_TAG_PURPOSE, .uint32Param = OH_HUKS_KEY_PURPOSE_AGREE},
    {.tag = OH_HUKS_TAG_KEY_SIZE, .uint32Param = OH_HUKS_CURVE25519_KEY_SIZE_256},
    {.tag = OH_HUKS_TAG_DIGEST, .uint32Param = OH_HUKS_DIGEST_NONE}};
static struct OH_Huks_Param g_agreeParamsFinish01[] = {
    {.tag = OH_HUKS_TAG_DERIVED_AGREED_KEY_STORAGE_FLAG, .uint32Param = OH_HUKS_STORAGE_ONLY_USED_IN_HUKS},
    {.tag = OH_HUKS_TAG_ALGORITHM, .uint32Param = OH_HUKS_ALG_AES},
    {.tag = OH_HUKS_TAG_KEY_SIZE, .uint32Param = OH_HUKS_AES_KEY_SIZE_256},
    {.tag = OH_HUKS_TAG_PURPOSE, .uint32Param = OH_HUKS_KEY_PURPOSE_AGREE},
    {.tag = OH_HUKS_TAG_KEY_ALIAS, .blob = g_keyAliasFinal1001},
    {.tag = OH_HUKS_TAG_PADDING, .uint32Param = OH_HUKS_PADDING_NONE},
    {.tag = OH_HUKS_TAG_BLOCK_MODE, .uint32Param = OH_HUKS_MODE_ECB},
    {.tag = OH_HUKS_TAG_DIGEST, .uint32Param = OH_HUKS_DIGEST_NONE}};
static struct OH_Huks_Blob g_keyAliasFinal2001 = {(uint32_t)strlen("HksX25519AgreeKeyAliasTest001_2_final"),
                                                  (uint8_t *)"HksX25519AgreeKeyAliasTest001_2_final"};
static struct OH_Huks_Param g_agreeParamsInit02[] = {
    {.tag = OH_HUKS_TAG_ALGORITHM, .uint32Param = OH_HUKS_ALG_X25519},
    {.tag = OH_HUKS_TAG_PURPOSE, .uint32Param = OH_HUKS_KEY_PURPOSE_AGREE},
    {.tag = OH_HUKS_TAG_KEY_SIZE, .uint32Param = OH_HUKS_CURVE25519_KEY_SIZE_256},
    {.tag = OH_HUKS_TAG_DIGEST, .uint32Param = OH_HUKS_DIGEST_NONE}};
static struct OH_Huks_Param g_agreeParamsFinish02[] = {
    {.tag = OH_HUKS_TAG_DERIVED_AGREED_KEY_STORAGE_FLAG, .uint32Param = OH_HUKS_STORAGE_ONLY_USED_IN_HUKS},
    {.tag = OH_HUKS_TAG_ALGORITHM, .uint32Param = OH_HUKS_ALG_AES},
    {.tag = OH_HUKS_TAG_KEY_SIZE, .uint32Param = OH_HUKS_AES_KEY_SIZE_256},
    {.tag = OH_HUKS_TAG_PURPOSE, .uint32Param = OH_HUKS_KEY_PURPOSE_AGREE},
    {.tag = OH_HUKS_TAG_KEY_ALIAS, .blob = g_keyAliasFinal2001},
    {.tag = OH_HUKS_TAG_PADDING, .uint32Param = OH_HUKS_PADDING_NONE},
    {.tag = OH_HUKS_TAG_BLOCK_MODE, .uint32Param = OH_HUKS_MODE_ECB},
    {.tag = OH_HUKS_TAG_DIGEST, .uint32Param = OH_HUKS_DIGEST_NONE}};
static const uint32_t X25519_COMMON_SIZE = 256;
static struct OH_Huks_Blob g_keyAlias01001 = {(uint32_t)strlen("HksX25519AgreeKeyAliasTest001_1"),
                                              (uint8_t *)"HksX25519AgreeKeyAliasTest001_1"};
static struct OH_Huks_Blob g_keyAlias02001 = {(uint32_t)strlen("HksX25519AgreeKeyAliasTest001_2"),
                                              (uint8_t *)"HksX25519AgreeKeyAliasTest001_2"};
```

Perform key agreement.

<!-- @[key_agreement_X25519_cpp](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Security/UniversalKeystoreKit/KeyUsage/KeyExchange/entry/src/main/cpp/types/projects/napi_X25519.cpp) -->

``` C++
/* Export a key. */
OH_Huks_Result HksX25519AgreeExport(const struct OH_Huks_Blob *keyAlias1, const struct OH_Huks_Blob *keyAlias2,
    struct OH_Huks_Blob *publicKey1, struct OH_Huks_Blob *publicKey2,
    const struct OH_Huks_ParamSet *genParamSet)
{
    OH_Huks_Result ret = OH_Huks_ExportPublicKeyItem(keyAlias1, genParamSet, publicKey1);
    if (ret.errorCode != OH_HUKS_SUCCESS) {
        return ret;
    }
    ret = OH_Huks_ExportPublicKeyItem(keyAlias2, genParamSet, publicKey2);
    if (ret.errorCode != OH_HUKS_SUCCESS) {
        return ret;
    }
    return ret;
}
static const char *IN_DATA = "Hks_X25519_Agree_Test";
/* Perform key agreement. */
OH_Huks_Result HksX25519AgreeFinish(const struct OH_Huks_Blob *keyAlias, const struct OH_Huks_Blob *publicKey,
    const struct OH_Huks_ParamSet *initParamSet,
    const struct OH_Huks_ParamSet *finishParamSet, struct OH_Huks_Blob *outData)
{
    struct OH_Huks_Blob inData = {(uint32_t)strlen(IN_DATA), (uint8_t *)IN_DATA};
    uint8_t handleU[sizeof(uint64_t)] = {0};
    struct OH_Huks_Blob handle = {sizeof(uint64_t), handleU};
    OH_Huks_Result ret = OH_Huks_InitSession(keyAlias, initParamSet, &handle, nullptr);
    if (ret.errorCode != OH_HUKS_SUCCESS) {
        return ret;
    }
    uint8_t outDataU[X25519_COMMON_SIZE] = {0};
    struct OH_Huks_Blob outDataUpdate = {X25519_COMMON_SIZE, outDataU};
    ret = OH_Huks_UpdateSession(&handle, initParamSet, publicKey, &outDataUpdate);
    if (ret.errorCode != OH_HUKS_SUCCESS) {
        return ret;
    }
    ret = OH_Huks_FinishSession(&handle, finishParamSet, &inData, outData);
    if (ret.errorCode != OH_HUKS_SUCCESS) {
        return ret;
    }
    return ret;
}

static OH_Huks_Result InitializeAgreeParamSets(struct OH_Huks_ParamSet **genParamSet,
    struct OH_Huks_ParamSet **initParamSet01,
    struct OH_Huks_ParamSet **finishParamSet01,
    struct OH_Huks_ParamSet **initParamSet02,
    struct OH_Huks_ParamSet **finishParamSet02)
{
    OH_Huks_Result ohResult;
    
    ohResult = InitParamSet(genParamSet, g_genAgreeParams,
                            sizeof(g_genAgreeParams) / sizeof(OH_Huks_Param));
    if (ohResult.errorCode != OH_HUKS_SUCCESS) {
        return ohResult;
    }
    ohResult = InitParamSet(initParamSet01, g_agreeParamsInit01,
                            sizeof(g_agreeParamsInit01) / sizeof(OH_Huks_Param));
    if (ohResult.errorCode != OH_HUKS_SUCCESS) {
        return ohResult;
    }
    ohResult = InitParamSet(finishParamSet01, g_agreeParamsFinish01,
                            sizeof(g_agreeParamsFinish01) / sizeof(OH_Huks_Param));
    if (ohResult.errorCode != OH_HUKS_SUCCESS) {
        return ohResult;
    }
    ohResult = InitParamSet(initParamSet02, g_agreeParamsInit02,
                            sizeof(g_agreeParamsInit02) / sizeof(OH_Huks_Param));
    if (ohResult.errorCode != OH_HUKS_SUCCESS) {
        return ohResult;
    }
    ohResult = InitParamSet(finishParamSet02, g_agreeParamsFinish02,
                            sizeof(g_agreeParamsFinish02) / sizeof(OH_Huks_Param));
    return ohResult;
}

static OH_Huks_Result GenerateKeyPair(struct OH_Huks_ParamSet *genParamSet)
{
    OH_Huks_Result ohResult;
    
    /* Generate an asymmetric key pair for device A. */
    ohResult = OH_Huks_GenerateKeyItem(&g_keyAlias01001, genParamSet, nullptr);
    if (ohResult.errorCode != OH_HUKS_SUCCESS) {
        return ohResult;
    }
    
    /* Generate an asymmetric key pair for device B. */
    ohResult = OH_Huks_GenerateKeyItem(&g_keyAlias02001, genParamSet, nullptr);
    return ohResult;
}

static OH_Huks_Result KeyAgreement(struct OH_Huks_Blob *g_keyAlias,
    struct OH_Huks_Blob *publicKey,
    struct OH_Huks_Blob *outData,
    struct OH_Huks_ParamSet *initParamSet,
    struct OH_Huks_ParamSet *finishParamSet)
{
    OH_Huks_Result ohResult;
    
    ohResult = MallocAndCheckBlobData(outData, outData->size);
    if (ohResult.errorCode != OH_HUKS_SUCCESS) {
        return ohResult;
    }
    /* Perform key agreement. */
    ohResult = HksX25519AgreeFinish(g_keyAlias, publicKey, initParamSet, finishParamSet, outData);
    return ohResult;
}

static void CleanKey(struct OH_Huks_Blob *genKeyAlias,
    struct OH_Huks_Blob *genKeyAliasFinal,
    struct OH_Huks_ParamSet *genParamSet,
    struct OH_Huks_ParamSet **initParamSet,
    struct OH_Huks_ParamSet **finishParamSet)
{
    OH_Huks_DeleteKeyItem(genKeyAlias, genParamSet);
    OH_Huks_DeleteKeyItem(genKeyAliasFinal, NULL);
    OH_Huks_FreeParamSet(initParamSet);
    OH_Huks_FreeParamSet(finishParamSet);
}

/* Key agreement process. */
napi_value X25519AgreeKey(napi_env env, napi_callback_info info)
{
    struct OH_Huks_ParamSet *genParamSet = nullptr;
    struct OH_Huks_ParamSet *initParamSet01 = nullptr;
    struct OH_Huks_ParamSet *finishParamSet01 = nullptr;
    struct OH_Huks_ParamSet *initParamSet02 = nullptr;
    struct OH_Huks_ParamSet *finishParamSet02 = nullptr;
    struct OH_Huks_Blob publicKey01 = {.size = OH_HUKS_AES_KEY_SIZE_256, .data = nullptr};
    struct OH_Huks_Blob publicKey02 = {.size = OH_HUKS_AES_KEY_SIZE_256, .data = nullptr};
    struct OH_Huks_Blob outData01 = {.size = X25519_COMMON_SIZE, .data = nullptr};
    struct OH_Huks_Blob outData02 = {.size = X25519_COMMON_SIZE, .data = nullptr};
    OH_Huks_Result ohResult;
    do {
        /* 1. Set the key alias and key parameter set. */
        ohResult = InitializeAgreeParamSets(&genParamSet, &initParamSet01, &finishParamSet01,
                                            &initParamSet02, &finishParamSet02);
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        /* 2. Generate keys on device A and device B. */
        ohResult = GenerateKeyPair(genParamSet);
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        ohResult = MallocAndCheckBlobData(&publicKey01, publicKey01.size);
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        ohResult = MallocAndCheckBlobData(&publicKey02, publicKey02.size);
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        /* 3. Export the public key from device A and device B separately. */
        ohResult = HksX25519AgreeExport(&g_keyAlias01001, &g_keyAlias02001, &publicKey01, &publicKey02, genParamSet);
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        /* 4. Perform key agreement on device A and device B. */
        ohResult = KeyAgreement(&g_keyAlias01001, &publicKey02, &outData01, initParamSet01, finishParamSet01);
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        ohResult = KeyAgreement(&g_keyAlias02001, &publicKey01, &outData02, initParamSet02, finishParamSet02);
    } while (0);
    free(publicKey01.data);
    free(publicKey02.data);
    free(outData01.data);
    free(outData02.data);
    /* 5. Delete the keys from device A and device B. */
    CleanKey(&g_keyAlias01001, &g_keyAliasFinal1001, genParamSet, &initParamSet01, &finishParamSet01);
    CleanKey(&g_keyAlias02001, &g_keyAliasFinal2001, genParamSet, &initParamSet02, &finishParamSet02);
    OH_Huks_FreeParamSet(&genParamSet);

    napi_value ret;
    napi_create_int32(env, ohResult.errorCode, &ret);
    return ret;
}
```

<!-- -->

### DH Key Agreement

Prepare the DH key agreement materials.

<!-- @[prepare_DH_cpp](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Security/UniversalKeystoreKit/KeyUsage/KeyExchange/entry/src/main/cpp/types/projects/napi_DH.cpp) -->

``` C++
#include "huks/native_huks_api.h"
#include "huks/native_huks_param.h"
#include "napi/native_api.h"
#include <cstring>
#include "file.h"

/* Initialize parameters. */
static OH_Huks_Result InitParamSet(struct OH_Huks_ParamSet **paramSet, const struct OH_Huks_Param *params,
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
static struct OH_Huks_Blob g_keyAliasFinal1001 = {(uint32_t)strlen("HksDHAgreeKeyAliasTest001_1_final"),
                                                  (uint8_t *)"HksDHAgreeKeyAliasTest001_1_final"};
/* Set the key parameter set. */
static struct OH_Huks_Param g_genAgreeParams[] = {
    {.tag = OH_HUKS_TAG_ALGORITHM, .uint32Param = OH_HUKS_ALG_DH},
    {.tag = OH_HUKS_TAG_PURPOSE, .uint32Param = OH_HUKS_KEY_PURPOSE_AGREE},
    {.tag = OH_HUKS_TAG_KEY_SIZE, .uint32Param = OH_HUKS_DH_KEY_SIZE_2048}};
static struct OH_Huks_Param g_agreeParamsInit01[] = {
    {.tag = OH_HUKS_TAG_ALGORITHM, .uint32Param = OH_HUKS_ALG_DH},
    {.tag = OH_HUKS_TAG_PURPOSE, .uint32Param = OH_HUKS_KEY_PURPOSE_AGREE},
    {.tag = OH_HUKS_TAG_KEY_SIZE, .uint32Param = OH_HUKS_DH_KEY_SIZE_2048}};
static struct OH_Huks_Param g_agreeParamsFinish01[] = {
    {.tag = OH_HUKS_TAG_DERIVED_AGREED_KEY_STORAGE_FLAG, .uint32Param = OH_HUKS_STORAGE_KEY_EXPORT_ALLOWED},
    {.tag = OH_HUKS_TAG_ALGORITHM, .uint32Param = OH_HUKS_ALG_AES},
    {.tag = OH_HUKS_TAG_KEY_SIZE, .uint32Param = OH_HUKS_AES_KEY_SIZE_256},
    {.tag = OH_HUKS_TAG_PURPOSE, .uint32Param = OH_HUKS_KEY_PURPOSE_AGREE},
    {.tag = OH_HUKS_TAG_KEY_ALIAS, .blob = g_keyAliasFinal1001},
    {.tag = OH_HUKS_TAG_PADDING, .uint32Param = OH_HUKS_PADDING_NONE},
    {.tag = OH_HUKS_TAG_BLOCK_MODE, .uint32Param = OH_HUKS_MODE_ECB},
    {.tag = OH_HUKS_TAG_DIGEST, .uint32Param = OH_HUKS_DIGEST_NONE}};
static struct OH_Huks_Param g_agreeParamsFinish01_2[] = {
    {.tag = OH_HUKS_TAG_DERIVED_AGREED_KEY_STORAGE_FLAG, .uint32Param = OH_HUKS_STORAGE_ONLY_USED_IN_HUKS},
    {.tag = OH_HUKS_TAG_ALGORITHM, .uint32Param = OH_HUKS_ALG_AES},
    {.tag = OH_HUKS_TAG_KEY_SIZE, .uint32Param = OH_HUKS_AES_KEY_SIZE_256},
    {.tag = OH_HUKS_TAG_PURPOSE, .uint32Param = OH_HUKS_KEY_PURPOSE_AGREE},
    {.tag = OH_HUKS_TAG_KEY_ALIAS, .blob = g_keyAliasFinal1001},
    {.tag = OH_HUKS_TAG_PADDING, .uint32Param = OH_HUKS_PADDING_NONE},
    {.tag = OH_HUKS_TAG_BLOCK_MODE, .uint32Param = OH_HUKS_MODE_ECB},
    {.tag = OH_HUKS_TAG_DIGEST, .uint32Param = OH_HUKS_DIGEST_NONE}};
static struct OH_Huks_Blob g_keyAliasFinal2001 = {(uint32_t)strlen("HksDHAgreeKeyAliasTest001_2_final"),
                                                  (uint8_t *)"HksDHAgreeKeyAliasTest001_2_final"};
static struct OH_Huks_Param g_agreeParamsInit02[] = {
    {.tag = OH_HUKS_TAG_ALGORITHM, .uint32Param = OH_HUKS_ALG_DH},
    {.tag = OH_HUKS_TAG_PURPOSE, .uint32Param = OH_HUKS_KEY_PURPOSE_AGREE},
    {.tag = OH_HUKS_TAG_KEY_SIZE, .uint32Param = OH_HUKS_DH_KEY_SIZE_2048}};
static struct OH_Huks_Param g_agreeParamsFinish02[] = {
    {.tag = OH_HUKS_TAG_DERIVED_AGREED_KEY_STORAGE_FLAG, .uint32Param = OH_HUKS_STORAGE_KEY_EXPORT_ALLOWED},
    {.tag = OH_HUKS_TAG_ALGORITHM, .uint32Param = OH_HUKS_ALG_AES},
    {.tag = OH_HUKS_TAG_KEY_SIZE, .uint32Param = OH_HUKS_AES_KEY_SIZE_256},
    {.tag = OH_HUKS_TAG_PURPOSE, .uint32Param = OH_HUKS_KEY_PURPOSE_AGREE},
    {.tag = OH_HUKS_TAG_KEY_ALIAS, .blob = g_keyAliasFinal2001},
    {.tag = OH_HUKS_TAG_PADDING, .uint32Param = OH_HUKS_PADDING_NONE},
    {.tag = OH_HUKS_TAG_BLOCK_MODE, .uint32Param = OH_HUKS_MODE_ECB},
    {.tag = OH_HUKS_TAG_DIGEST, .uint32Param = OH_HUKS_DIGEST_NONE}};
static struct OH_Huks_Param g_agreeParamsFinish02_2[] = {
    {.tag = OH_HUKS_TAG_DERIVED_AGREED_KEY_STORAGE_FLAG, .uint32Param = OH_HUKS_STORAGE_ONLY_USED_IN_HUKS},
    {.tag = OH_HUKS_TAG_ALGORITHM, .uint32Param = OH_HUKS_ALG_AES},
    {.tag = OH_HUKS_TAG_KEY_SIZE, .uint32Param = OH_HUKS_AES_KEY_SIZE_256},
    {.tag = OH_HUKS_TAG_PURPOSE, .uint32Param = OH_HUKS_KEY_PURPOSE_AGREE},
    {.tag = OH_HUKS_TAG_KEY_ALIAS, .blob = g_keyAliasFinal2001},
    {.tag = OH_HUKS_TAG_PADDING, .uint32Param = OH_HUKS_PADDING_NONE},
    {.tag = OH_HUKS_TAG_BLOCK_MODE, .uint32Param = OH_HUKS_MODE_ECB},
    {.tag = OH_HUKS_TAG_DIGEST, .uint32Param = OH_HUKS_DIGEST_NONE}};
static const uint32_t DH_COMMON_SIZE = 2048;
static struct OH_Huks_Blob g_keyAlias01001 = {(uint32_t)strlen("HksDHAgreeKeyAliasTest001_1"),
                                              (uint8_t *)"HksDHAgreeKeyAliasTest001_1"};
static struct OH_Huks_Blob g_keyAlias02001 = {(uint32_t)strlen("HksDHAgreeKeyAliasTest001_2"),
                                              (uint8_t *)"HksDHAgreeKeyAliasTest001_2"};
```

Perform key agreement.

<!-- @[key_agreement_DH_cpp](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Security/UniversalKeystoreKit/KeyUsage/KeyExchange/entry/src/main/cpp/types/projects/napi_DH.cpp) -->

``` C++
static OH_Huks_Result MallocAndCheckBlobData(struct OH_Huks_Blob *blob, const uint32_t blobSize)
{
    struct OH_Huks_Result ret;
    ret.errorCode = OH_HUKS_SUCCESS;
    if (blobSize == 0 || blobSize > DH_COMMON_SIZE) {
        ret.errorCode = OH_HUKS_ERR_CODE_INTERNAL_ERROR;
        return ret;
    }
    blob->data = (uint8_t *)malloc(blobSize);
    if (blob->data == NULL) {
        ret.errorCode = OH_HUKS_ERR_CODE_INTERNAL_ERROR;
    }
    return ret;
}
/* Export a key. */
OH_Huks_Result HksDHAgreeExport(const struct OH_Huks_Blob *keyAlias1, const struct OH_Huks_Blob *keyAlias2,
    struct OH_Huks_Blob *publicKey1, struct OH_Huks_Blob *publicKey2,
    const struct OH_Huks_ParamSet *genParamSet)
{
    OH_Huks_Result ret = OH_Huks_ExportPublicKeyItem(keyAlias1, genParamSet, publicKey1);
    if (ret.errorCode != OH_HUKS_SUCCESS) {
        return ret;
    }
    ret = OH_Huks_ExportPublicKeyItem(keyAlias2, genParamSet, publicKey2);
    if (ret.errorCode != OH_HUKS_SUCCESS) {
        return ret;
    }
    return ret;
}
static const char *IN_DATA = "Hks_DH_Agree_Test";
/* Perform key agreement. */
OH_Huks_Result HksDHAgreeFinish(const struct OH_Huks_Blob *keyAlias, const struct OH_Huks_Blob *publicKey,
    const struct OH_Huks_ParamSet *initParamSet,
    const struct OH_Huks_ParamSet *finishParamSet, struct OH_Huks_Blob *outData)
{
    struct OH_Huks_Blob inData = {(uint32_t)strlen(IN_DATA), (uint8_t *)IN_DATA};
    uint8_t handleU[sizeof(uint64_t)] = {0};
    struct OH_Huks_Blob handle = {sizeof(uint64_t), handleU};
    OH_Huks_Result ret = OH_Huks_InitSession(keyAlias, initParamSet, &handle, nullptr);
    if (ret.errorCode != OH_HUKS_SUCCESS) {
        return ret;
    }
    uint8_t outDataU[DH_COMMON_SIZE] = {0};
    struct OH_Huks_Blob outDataUpdate = {DH_COMMON_SIZE, outDataU};
    ret = OH_Huks_UpdateSession(&handle, initParamSet, publicKey, &outDataUpdate);
    if (ret.errorCode != OH_HUKS_SUCCESS) {
        return ret;
    }
    ret = OH_Huks_FinishSession(&handle, finishParamSet, &inData, outData);
    if (ret.errorCode != OH_HUKS_SUCCESS) {
        return ret;
    }
    return ret;
}

static OH_Huks_Result InitializeAgreeParamSets(struct OH_Huks_ParamSet **genParamSet,
    struct OH_Huks_ParamSet **initParamSet01,
    struct OH_Huks_ParamSet **finishParamSet01,
    struct OH_Huks_ParamSet **initParamSet02,
    struct OH_Huks_ParamSet **finishParamSet02)
{
    OH_Huks_Result ohResult;
    
    ohResult = InitParamSet(genParamSet, g_genAgreeParams,
                            sizeof(g_genAgreeParams) / sizeof(OH_Huks_Param));
    if (ohResult.errorCode != OH_HUKS_SUCCESS) {
        return ohResult;
    }
    ohResult = InitParamSet(initParamSet01, g_agreeParamsInit01,
                            sizeof(g_agreeParamsInit01) / sizeof(OH_Huks_Param));
    if (ohResult.errorCode != OH_HUKS_SUCCESS) {
        return ohResult;
    }
    ohResult = InitParamSet(finishParamSet01, g_agreeParamsFinish01,
                            sizeof(g_agreeParamsFinish01) / sizeof(OH_Huks_Param));
    if (ohResult.errorCode != OH_HUKS_SUCCESS) {
        return ohResult;
    }
    ohResult = InitParamSet(initParamSet02, g_agreeParamsInit02,
                            sizeof(g_agreeParamsInit02) / sizeof(OH_Huks_Param));
    if (ohResult.errorCode != OH_HUKS_SUCCESS) {
        return ohResult;
    }
    ohResult = InitParamSet(finishParamSet02, g_agreeParamsFinish02,
                            sizeof(g_agreeParamsFinish02) / sizeof(OH_Huks_Param));
    return ohResult;
}

static OH_Huks_Result GenerateKeyPair(struct OH_Huks_ParamSet *genParamSet)
{
    OH_Huks_Result ohResult;
    
    /* Generate an asymmetric key pair for device A. */
    ohResult = OH_Huks_GenerateKeyItem(&g_keyAlias01001, genParamSet, nullptr);
    if (ohResult.errorCode != OH_HUKS_SUCCESS) {
        return ohResult;
    }
    
    /* Generate an asymmetric key pair for device B. */
    ohResult = OH_Huks_GenerateKeyItem(&g_keyAlias02001, genParamSet, nullptr);
    return ohResult;
}

static OH_Huks_Result KeyAgreement(struct OH_Huks_Blob *g_keyAlias,
    struct OH_Huks_Blob *publicKey,
    struct OH_Huks_Blob *outData,
    struct OH_Huks_ParamSet *initParamSet,
    struct OH_Huks_ParamSet *finishParamSet)
{
    OH_Huks_Result ohResult;
    
    ohResult = MallocAndCheckBlobData(outData, outData->size);
    if (ohResult.errorCode != OH_HUKS_SUCCESS) {
        return ohResult;
    }
    /* Perform key agreement. */
    ohResult = HksDHAgreeFinish(g_keyAlias, publicKey, initParamSet, finishParamSet, outData);
    return ohResult;
}

static void CleanKey(struct OH_Huks_Blob *genKeyAlias,
    struct OH_Huks_Blob *genKeyAliasFinal,
    struct OH_Huks_ParamSet *genParamSet,
    struct OH_Huks_ParamSet **initParamSet,
    struct OH_Huks_ParamSet **finishParamSet)
{
    OH_Huks_DeleteKeyItem(genKeyAlias, genParamSet);
    OH_Huks_DeleteKeyItem(genKeyAliasFinal, NULL);
    OH_Huks_FreeParamSet(initParamSet);
    OH_Huks_FreeParamSet(finishParamSet);
}

/* Key agreement process. */
napi_value DhAgreeKey(napi_env env, napi_callback_info info)
{
    struct OH_Huks_ParamSet *genParamSet = nullptr;
    struct OH_Huks_ParamSet *initParamSet01 = nullptr;
    struct OH_Huks_ParamSet *finishParamSet01 = nullptr;
    struct OH_Huks_ParamSet *initParamSet02 = nullptr;
    struct OH_Huks_ParamSet *finishParamSet02 = nullptr;
    struct OH_Huks_Blob publicKey01 = {.size = DH_COMMON_SIZE, .data = nullptr};
    struct OH_Huks_Blob publicKey02 = {.size = DH_COMMON_SIZE, .data = nullptr};
    struct OH_Huks_Blob outData01 = {.size = DH_COMMON_SIZE, .data = nullptr};
    struct OH_Huks_Blob outData02 = {.size = DH_COMMON_SIZE, .data = nullptr};

    OH_Huks_Result ohResult;
    do {
        /* 1. Set the key alias and key parameter set. */
        ohResult = InitializeAgreeParamSets(&genParamSet, &initParamSet01, &finishParamSet01,
                                            &initParamSet02, &finishParamSet02);
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        /* 2. Generate keys on device A and device B. */
        ohResult = GenerateKeyPair(genParamSet);
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        ohResult = MallocAndCheckBlobData(&publicKey01, publicKey01.size);
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        ohResult = MallocAndCheckBlobData(&publicKey02, publicKey02.size);
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        /* 3. Export the public key from device A and device B separately. */
        ohResult = HksDHAgreeExport(&g_keyAlias01001, &g_keyAlias02001, &publicKey01, &publicKey02, genParamSet);
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        /* 4. Perform key agreement on device A and device B. */
        ohResult = KeyAgreement(&g_keyAlias01001, &publicKey02, &outData01, initParamSet01, finishParamSet01);
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        ohResult = KeyAgreement(&g_keyAlias02001, &publicKey01, &outData02, initParamSet02, finishParamSet02);
    } while (0);
    free(publicKey01.data);
    free(publicKey02.data);
    free(outData01.data);
    free(outData02.data);
    /* 5. Delete the keys from device A and device B. */
    CleanKey(&g_keyAlias01001, &g_keyAliasFinal1001, genParamSet, &initParamSet01, &finishParamSet01);
    CleanKey(&g_keyAlias02001, &g_keyAliasFinal2001, genParamSet, &initParamSet02, &finishParamSet02);
    OH_Huks_FreeParamSet(&genParamSet);

    napi_value ret;
    napi_create_int32(env, ohResult.errorCode, &ret);
    return ret;
}
```

<!-- -->

### ECDH Key Agreement

Prepare the ECDH key agreement materials.

<!-- @[prepare_ECDH_cpp](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Security/UniversalKeystoreKit/KeyUsage/KeyExchange/entry/src/main/cpp/types/projects/napi_ECDH.cpp) -->

``` C++
#include "huks/native_huks_api.h"
#include "huks/native_huks_param.h"
#include "napi/native_api.h"
#include <cstring>
#include "file.h"

/* Initialize parameters. */
static OH_Huks_Result InitParamSet(struct OH_Huks_ParamSet **paramSet, const struct OH_Huks_Param *params,
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
static const uint32_t IV_SIZE = 16;
static uint8_t IV[IV_SIZE] = {0}; // this is a test value, for real use the iv should be different every time
static struct OH_Huks_Blob g_keyAliasFinal1001 = {(uint32_t)strlen("HksECDHAgreeKeyAliasTest001_1_final"),
                                                  (uint8_t *)"HksECDHAgreeKeyAliasTest001_1_final"};
/* Set the key parameter set. */
static struct OH_Huks_Param g_genAgreeParams[] = {
    {.tag = OH_HUKS_TAG_ALGORITHM, .uint32Param = OH_HUKS_ALG_ECC},
    {.tag = OH_HUKS_TAG_PURPOSE, .uint32Param = OH_HUKS_KEY_PURPOSE_AGREE},
    {.tag = OH_HUKS_TAG_KEY_SIZE, .uint32Param = OH_HUKS_ECC_KEY_SIZE_256},
    {.tag = OH_HUKS_TAG_DIGEST, .uint32Param = OH_HUKS_DIGEST_NONE}};
static struct OH_Huks_Param g_agreeParamsInit01[] = {
    {.tag = OH_HUKS_TAG_ALGORITHM, .uint32Param = OH_HUKS_ALG_ECDH},
    {.tag = OH_HUKS_TAG_PURPOSE, .uint32Param = OH_HUKS_KEY_PURPOSE_AGREE},
    {.tag = OH_HUKS_TAG_KEY_SIZE, .uint32Param = OH_HUKS_ECC_KEY_SIZE_256}};
static struct OH_Huks_Param g_agreeParamsFinish01[] = {
    {.tag = OH_HUKS_TAG_DERIVED_AGREED_KEY_STORAGE_FLAG, .uint32Param = OH_HUKS_STORAGE_ONLY_USED_IN_HUKS},
    {.tag = OH_HUKS_TAG_ALGORITHM, .uint32Param = OH_HUKS_ALG_AES},
    {.tag = OH_HUKS_TAG_KEY_SIZE, .uint32Param = OH_HUKS_AES_KEY_SIZE_256},
    {.tag = OH_HUKS_TAG_PURPOSE, .uint32Param = OH_HUKS_KEY_PURPOSE_AGREE},
    {.tag = OH_HUKS_TAG_KEY_ALIAS, .blob = g_keyAliasFinal1001},
    {.tag = OH_HUKS_TAG_PADDING, .uint32Param = OH_HUKS_PADDING_NONE},
    {.tag = OH_HUKS_TAG_BLOCK_MODE, .uint32Param = OH_HUKS_MODE_CBC}};
static struct OH_Huks_Blob g_keyAliasFinal2001 = {(uint32_t)strlen("HksECDHAgreeKeyAliasTest001_2_final"),
                                                  (uint8_t *)"HksECDHAgreeKeyAliasTest001_2_final"};
static struct OH_Huks_Param g_agreeParamsInit02[] = {
    {.tag = OH_HUKS_TAG_ALGORITHM, .uint32Param = OH_HUKS_ALG_ECDH},
    {.tag = OH_HUKS_TAG_PURPOSE, .uint32Param = OH_HUKS_KEY_PURPOSE_AGREE},
    {.tag = OH_HUKS_TAG_KEY_SIZE, .uint32Param = OH_HUKS_ECC_KEY_SIZE_256}};
static struct OH_Huks_Param g_agreeParamsFinish02[] = {
    {.tag = OH_HUKS_TAG_DERIVED_AGREED_KEY_STORAGE_FLAG, .uint32Param = OH_HUKS_STORAGE_ONLY_USED_IN_HUKS},
    {.tag = OH_HUKS_TAG_ALGORITHM, .uint32Param = OH_HUKS_ALG_AES},
    {.tag = OH_HUKS_TAG_KEY_SIZE, .uint32Param = OH_HUKS_AES_KEY_SIZE_256},
    {.tag = OH_HUKS_TAG_PURPOSE, .uint32Param = OH_HUKS_KEY_PURPOSE_AGREE},
    {.tag = OH_HUKS_TAG_KEY_ALIAS, .blob = g_keyAliasFinal2001},
    {.tag = OH_HUKS_TAG_PADDING, .uint32Param = OH_HUKS_PADDING_NONE},
    {.tag = OH_HUKS_TAG_BLOCK_MODE, .uint32Param = OH_HUKS_MODE_CBC}};
static const uint32_t ECDH_COMMON_SIZE = 1024;
static struct OH_Huks_Blob g_keyAlias01001 = {(uint32_t)strlen("HksECDHAgreeKeyAliasTest001_1"),
                                              (uint8_t *)"HksECDHAgreeKeyAliasTest001_1"};
static struct OH_Huks_Blob g_keyAlias02001 = {(uint32_t)strlen("HksECDHAgreeKeyAliasTest001_2"),
                                              (uint8_t *)"HksECDHAgreeKeyAliasTest001_2"};
```

<!-- -->

Functions for ECDH key agreement, including memory allocation, parameter initialization, key generation, and resource cleanup.

<!-- @[key_agreement_ECDH_cpp_one](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Security/UniversalKeystoreKit/KeyUsage/KeyExchange/entry/src/main/cpp/types/projects/napi_ECDH.cpp) -->

``` C++
static OH_Huks_Result MallocAndCheckBlobData(struct OH_Huks_Blob *blob, const uint32_t blobSize)
{
    struct OH_Huks_Result ret;
    ret.errorCode = OH_HUKS_SUCCESS;
    if (blobSize == 0 || blobSize > ECDH_COMMON_SIZE) {
        ret.errorCode = OH_HUKS_ERR_CODE_INTERNAL_ERROR;
        return ret;
    }
    blob->data = (uint8_t *)malloc(blobSize);
    if (blob->data == NULL) {
        ret.errorCode = OH_HUKS_ERR_CODE_INTERNAL_ERROR;
    }
    return ret;
}

/* Export a key. */
OH_Huks_Result HksEcdhAgreeExport(const struct OH_Huks_Blob *keyAlias1, const struct OH_Huks_Blob *keyAlias2,
                                  struct OH_Huks_Blob *publicKey1, struct OH_Huks_Blob *publicKey2,
                                  const struct OH_Huks_ParamSet *genParamSet)
{
    OH_Huks_Result ret = OH_Huks_ExportPublicKeyItem(keyAlias1, genParamSet, publicKey1);
    if (ret.errorCode != OH_HUKS_SUCCESS) {
        return ret;
    }
    ret = OH_Huks_ExportPublicKeyItem(keyAlias2, genParamSet, publicKey2);
    if (ret.errorCode != OH_HUKS_SUCCESS) {
        return ret;
    }
    return ret;
}
static const char *IN_DATA = "Hks_ECDH_Agree_Test_000000000000000000000000000000000000000000000000000000000000"
                              "00000000000000000000000000000000000000000000000000000000000000000000000000000000"
                              "0000000000000000000000000000000000000000000000000000000000000000000000000_string";
/* Perform key agreement. */
OH_Huks_Result HksEcdhAgreeFinish(const struct OH_Huks_Blob *keyAlias, const struct OH_Huks_Blob *publicKey,
                                  const struct OH_Huks_ParamSet *initParamSet,
                                  const struct OH_Huks_ParamSet *finishParamSet, struct OH_Huks_Blob *outData)
{
    struct OH_Huks_Blob inData = {(uint32_t)strlen(IN_DATA), (uint8_t *)IN_DATA};
    uint8_t handleU[sizeof(uint64_t)] = {0};
    struct OH_Huks_Blob handle = {sizeof(uint64_t), handleU};
    OH_Huks_Result ret = OH_Huks_InitSession(keyAlias, initParamSet, &handle, nullptr);
    if (ret.errorCode != OH_HUKS_SUCCESS) {
        return ret;
    }
    uint8_t outDataU[ECDH_COMMON_SIZE] = {0};
    struct OH_Huks_Blob outDataUpdate = {ECDH_COMMON_SIZE, outDataU};
    ret = OH_Huks_UpdateSession(&handle, initParamSet, publicKey, &outDataUpdate);
    if (ret.errorCode != OH_HUKS_SUCCESS) {
        return ret;
    }
    ret = OH_Huks_FinishSession(&handle, finishParamSet, &inData, outData);
    if (ret.errorCode != OH_HUKS_SUCCESS) {
        return ret;
    }
    return ret;
}


static OH_Huks_Result InitializeAgreeParamSets(struct OH_Huks_ParamSet **genParamSet,
    struct OH_Huks_ParamSet **initParamSet01,
    struct OH_Huks_ParamSet **finishParamSet01,
    struct OH_Huks_ParamSet **initParamSet02,
    struct OH_Huks_ParamSet **finishParamSet02)
{
    OH_Huks_Result ohResult;
    
    ohResult = InitParamSet(genParamSet, g_genAgreeParams,
                            sizeof(g_genAgreeParams) / sizeof(OH_Huks_Param));
    if (ohResult.errorCode != OH_HUKS_SUCCESS) {
        return ohResult;
    }
    ohResult = InitParamSet(initParamSet01, g_agreeParamsInit01,
                            sizeof(g_agreeParamsInit01) / sizeof(OH_Huks_Param));
    if (ohResult.errorCode != OH_HUKS_SUCCESS) {
        return ohResult;
    }
    ohResult = InitParamSet(finishParamSet01, g_agreeParamsFinish01,
                            sizeof(g_agreeParamsFinish01) / sizeof(OH_Huks_Param));
    if (ohResult.errorCode != OH_HUKS_SUCCESS) {
        return ohResult;
    }
    ohResult = InitParamSet(initParamSet02, g_agreeParamsInit02,
                            sizeof(g_agreeParamsInit02) / sizeof(OH_Huks_Param));
    if (ohResult.errorCode != OH_HUKS_SUCCESS) {
        return ohResult;
    }
    ohResult = InitParamSet(finishParamSet02, g_agreeParamsFinish02,
                            sizeof(g_agreeParamsFinish02) / sizeof(OH_Huks_Param));
    return ohResult;
}

static OH_Huks_Result GenerateKeyPair(struct OH_Huks_ParamSet *genParamSet)
{
    OH_Huks_Result ohResult;
    
    /* Generate an asymmetric key pair for device A. */
    ohResult = OH_Huks_GenerateKeyItem(&g_keyAlias01001, genParamSet, nullptr);
    if (ohResult.errorCode != OH_HUKS_SUCCESS) {
        return ohResult;
    }
    
    /* Generate an asymmetric key pair for device B. */
    ohResult = OH_Huks_GenerateKeyItem(&g_keyAlias02001, genParamSet, nullptr);
    return ohResult;
}

static OH_Huks_Result KeyAgreement(struct OH_Huks_Blob *g_keyAlias,
    struct OH_Huks_Blob *publicKey,
    struct OH_Huks_Blob *outData,
    struct OH_Huks_ParamSet *initParamSet,
    struct OH_Huks_ParamSet *finishParamSet)
{
    OH_Huks_Result ohResult;
    
    ohResult = MallocAndCheckBlobData(outData, outData->size);
    if (ohResult.errorCode != OH_HUKS_SUCCESS) {
        return ohResult;
    }
    /* Perform key agreement. */
    ohResult = HksEcdhAgreeFinish(g_keyAlias, publicKey, initParamSet, finishParamSet, outData);
    return ohResult;
}

static void CleanKey(struct OH_Huks_Blob *genKeyAlias,
    struct OH_Huks_Blob *genKeyAliasFinal,
    struct OH_Huks_ParamSet *genParamSet,
    struct OH_Huks_ParamSet **initParamSet,
    struct OH_Huks_ParamSet **finishParamSet)
{
    OH_Huks_DeleteKeyItem(genKeyAlias, genParamSet);
    OH_Huks_DeleteKeyItem(genKeyAliasFinal, NULL);
    OH_Huks_FreeParamSet(initParamSet);
    OH_Huks_FreeParamSet(finishParamSet);
}
```

<!-- -->

The complete workflow of ECDH key agreement is as follows:

<!-- @[key_agreement_ECDH_cpp_two](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Security/UniversalKeystoreKit/KeyUsage/KeyExchange/entry/src/main/cpp/types/projects/napi_ECDH.cpp) -->

``` C++
/* Key agreement process. */
napi_value EcdhAgreeKey(napi_env env, napi_callback_info info)
{
    struct OH_Huks_ParamSet *genParamSet = nullptr;
    struct OH_Huks_ParamSet *initParamSet01 = nullptr;
    struct OH_Huks_ParamSet *finishParamSet01 = nullptr;
    struct OH_Huks_ParamSet *initParamSet02 = nullptr;
    struct OH_Huks_ParamSet *finishParamSet02 = nullptr;
    struct OH_Huks_Blob publicKey01 = {.size = OH_HUKS_ECC_KEY_SIZE_256, .data = nullptr};
    struct OH_Huks_Blob publicKey02 = {.size = OH_HUKS_ECC_KEY_SIZE_256, .data = nullptr};
    struct OH_Huks_Blob outData01 = {.size = ECDH_COMMON_SIZE, .data = nullptr};
    struct OH_Huks_Blob outData02 = {.size = ECDH_COMMON_SIZE, .data = nullptr};
    OH_Huks_Result ohResult;
    do {
        /* 1. Set the key alias and key parameter set. */
        ohResult = InitializeAgreeParamSets(&genParamSet, &initParamSet01, &finishParamSet01,
                                            &initParamSet02, &finishParamSet02);
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        /* 2. Generate keys on device A and device B. */
        ohResult = GenerateKeyPair(genParamSet);
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        ohResult = MallocAndCheckBlobData(&publicKey01, publicKey01.size);
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        ohResult = MallocAndCheckBlobData(&publicKey02, publicKey02.size);
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        /* 3. Export the public key from device A and device B separately. */
        ohResult = HksEcdhAgreeExport(&g_keyAlias01001, &g_keyAlias02001, &publicKey01, &publicKey02, genParamSet);
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        /* 4. Perform key agreement on device A and device B. */
        ohResult = KeyAgreement(&g_keyAlias01001, &publicKey02, &outData01, initParamSet01, finishParamSet01);
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        ohResult = KeyAgreement(&g_keyAlias02001, &publicKey01, &outData02, initParamSet02, finishParamSet02);
    } while (0);
    free(publicKey01.data);
    free(publicKey02.data);
    free(outData01.data);
    free(outData02.data);
    /* 5. Delete the keys from device A and device B. */
    CleanKey(&g_keyAlias01001, &g_keyAliasFinal1001, genParamSet, &initParamSet01, &finishParamSet01);
    CleanKey(&g_keyAlias02001, &g_keyAliasFinal2001, genParamSet, &initParamSet02, &finishParamSet02);
    OH_Huks_FreeParamSet(&genParamSet);

    napi_value ret;
    napi_create_int32(env, ohResult.errorCode, &ret);
    return ret;
}
```