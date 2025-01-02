# Key Agreement (C/C++)


This topic walks you through on how to agree on an ECDH key that is used only in HUKS. For details about the scenarios and supported algorithms, see [Supported Algorithms](huks-key-generation-overview.md#supported-algorithms).

## Add the dynamic library in the CMake script.
```txt
   target_link_libraries(entry PUBLIC libhuks_ndk.z.so)
```

## How to Develop

**Key Generation**

Generate an asymmetric key for device A and device B each. For details, see [Key Generation](huks-key-generation-overview.md) or [Key Import](huks-key-import-overview.md).

When generating a key, you can set **OH_HUKS_TAG_DERIVED_AGREED_KEY_STORAGE_FLAG** (optional) to specify how the shared secret generated from this key through key agreement is managed.

- If this tag is set to **OH_HUKS_STORAGE_ONLY_USED_IN_HUKS**, the shared secret is managed by HUKS. That is, the shared secret is always in a secure environment throughout its lifecycle.

- If this tag is set to **OH_HUKS_STORAGE_KEY_EXPORT_ALLOWED**, the shared secret generated will be returned to the caller for management. That is, the service side ensures the key security.

- If this tag is not set, the shared secret generated can be either managed by HUKS or returned to the caller for management. The key protection mode can be set in the subsequent key agreement on the service side.

**Key Export**

Export the public key of the asymmetric key pair of device A and device B. For details, see [Key Export](huks-export-key-arkts.md).

**Key Agreement**

Perform key agreement using the public key of the peer device and private key of the local device (that is, public key of device B and private key of device A for device A, and public key of device A and private key of device B for device B) to produce a shared secret.

During key agreement, you can set **OH_HUKS_TAG_DERIVED_AGREED_KEY_STORAGE_FLAG** (optional) to specify how the shared secret generated is managed.

| Key Generation| Key Agreement| Specifications|
| -------- | -------- | -------- |
| OH_HUKS_STORAGE_ONLY_USED_IN_HUKS | OH_HUKS_STORAGE_ONLY_USED_IN_HUKS | The key is managed by HUKS.|
| OH_HUKS_STORAGE_KEY_EXPORT_ALLOWED | OH_HUKS_STORAGE_KEY_EXPORT_ALLOWED | The key is returned to the caller for management.|
| The tag is not set.| OH_HUKS_STORAGE_ONLY_USED_IN_HUKS | The key is managed by HUKS.|
| The tag is not set.| OH_HUKS_STORAGE_KEY_EXPORT_ALLOWED | The key is returned to the caller for management.|
| The tag is not set.| The tag is not set.| The key is returned to the caller for management.|

>**NOTE**<br>The tag value set in key agreement should not conflict with the tag value set in key generation. The above table lists only valid settings.

**Key Deletion**

Delete the keys from device A and device B when the keys are not required. For details, see [Deleting a Key](huks-delete-key-ndk.md).

```c++
#include "huks/native_huks_api.h"
#include "huks/native_huks_param.h"
#include <string.h>
/* Initialize parameters. */
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
static const uint32_t IV_SIZE = 16;
static uint8_t IV[IV_SIZE] = { 0 }; // this is a test value, for real use the iv should be different every time
static struct OH_Huks_Blob g_keyAliasFinal1001 = {
    (uint32_t)strlen("HksECDHAgreeKeyAliasTest001_1_final"),
    (uint8_t *)"HksECDHAgreeKeyAliasTest001_1_final"
};
/* Set the key parameter set. */
static struct OH_Huks_Param g_genAgreeParams[] = {
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
static struct OH_Huks_Param g_agreeParamsInit01[] = {
    {
        .tag = OH_HUKS_TAG_ALGORITHM,
        .uint32Param = OH_HUKS_ALG_ECDH
    }, {
        .tag = OH_HUKS_TAG_PURPOSE,
        .uint32Param = OH_HUKS_KEY_PURPOSE_AGREE
    }, {
        .tag = OH_HUKS_TAG_KEY_SIZE,
        .uint32Param = OH_HUKS_ECC_KEY_SIZE_256
    }
};
static struct OH_Huks_Param g_agreeParamsFinish01[] = {
    {
        .tag = OH_HUKS_TAG_DERIVED_AGREED_KEY_STORAGE_FLAG,
        .uint32Param = OH_HUKS_STORAGE_ONLY_USED_IN_HUKS
    }, {
        .tag = OH_HUKS_TAG_ALGORITHM,
        .uint32Param = OH_HUKS_ALG_AES
    }, {
        .tag = OH_HUKS_TAG_KEY_SIZE,
        .uint32Param = OH_HUKS_AES_KEY_SIZE_256
    }, {
        .tag = OH_HUKS_TAG_PURPOSE,
        .uint32Param = OH_HUKS_KEY_PURPOSE_AGREE
    }, {
        .tag = OH_HUKS_TAG_KEY_ALIAS,
        .blob = g_keyAliasFinal1001
    }, {
        .tag = OH_HUKS_TAG_PADDING,
        .uint32Param = OH_HUKS_PADDING_NONE
    }, {
        .tag = OH_HUKS_TAG_BLOCK_MODE,
        .uint32Param = OH_HUKS_MODE_CBC
    }
};
static struct OH_Huks_Blob g_keyAliasFinal2001 = {
    (uint32_t)strlen("HksECDHAgreeKeyAliasTest001_2_final"),
    (uint8_t *)"HksECDHAgreeKeyAliasTest001_2_final"
};
static struct OH_Huks_Param g_agreeParamsInit02[] = {
    {
        .tag = OH_HUKS_TAG_ALGORITHM,
        .uint32Param = OH_HUKS_ALG_ECDH
    }, {
        .tag = OH_HUKS_TAG_PURPOSE,
        .uint32Param = OH_HUKS_KEY_PURPOSE_AGREE
    }, {
        .tag = OH_HUKS_TAG_KEY_SIZE,
        .uint32Param = OH_HUKS_ECC_KEY_SIZE_256
    }
};
static struct OH_Huks_Param g_agreeParamsFinish02[] = {
    {
        .tag = OH_HUKS_TAG_DERIVED_AGREED_KEY_STORAGE_FLAG,
        .uint32Param = OH_HUKS_STORAGE_ONLY_USED_IN_HUKS
    }, {
        .tag = OH_HUKS_TAG_ALGORITHM,
        .uint32Param = OH_HUKS_ALG_AES
    }, {
        .tag = OH_HUKS_TAG_KEY_SIZE,
        .uint32Param = OH_HUKS_AES_KEY_SIZE_256
    }, {
        .tag = OH_HUKS_TAG_PURPOSE,
        .uint32Param = OH_HUKS_KEY_PURPOSE_AGREE
    }, {
        .tag = OH_HUKS_TAG_KEY_ALIAS,
        .blob = g_keyAliasFinal2001
    }, {
        .tag = OH_HUKS_TAG_PADDING,
        .uint32Param = OH_HUKS_PADDING_NONE
    }, {
        .tag = OH_HUKS_TAG_BLOCK_MODE,
        .uint32Param = OH_HUKS_MODE_CBC
    }
};
static const uint32_t ECDH_COMMON_SIZE = 1024;
static struct OH_Huks_Blob g_keyAlias01001 = {
    (uint32_t)strlen("HksECDHAgreeKeyAliasTest001_1"),
    (uint8_t *)"HksECDHAgreeKeyAliasTest001_1"
};
static struct OH_Huks_Blob g_keyAlias02001 = {
    (uint32_t)strlen("HksECDHAgreeKeyAliasTest001_2"),
    (uint8_t *)"HksECDHAgreeKeyAliasTest001_2"
};
OH_Huks_Result MallocAndCheckBlobData(
    struct OH_Huks_Blob *blob,
    const uint32_t blobSize)
{
    struct OH_Huks_Result ret;
    ret.errorCode = OH_HUKS_SUCCESS;
    blob->data = (uint8_t *)malloc(blobSize);
    if (blob->data == NULL) {
        ret.errorCode = OH_HUKS_ERR_CODE_INTERNAL_ERROR;
    }
    return ret;
}
/* Export a key. */
OH_Huks_Result HksEcdhAgreeExport(const struct OH_Huks_Blob *keyAlias1, const struct OH_Huks_Blob *keyAlias2,
    struct OH_Huks_Blob *publicKey1, struct OH_Huks_Blob *publicKey2, const struct OH_Huks_ParamSet *genParamSet)
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
static const char *g_inData = "Hks_ECDH_Agree_Test_000000000000000000000000000000000000000000000000000000000000"
                                    "00000000000000000000000000000000000000000000000000000000000000000000000000000000"
                                    "0000000000000000000000000000000000000000000000000000000000000000000000000_string";
/* Perform key agreement. */
OH_Huks_Result HksEcdhAgreeFinish(const struct OH_Huks_Blob *keyAlias, const struct OH_Huks_Blob *publicKey,
    const struct OH_Huks_ParamSet *initParamSet, const struct OH_Huks_ParamSet *finishParamSet, struct OH_Huks_Blob *outData)
{
    struct OH_Huks_Blob inData = {
        (uint32_t)strlen(g_inData),
        (uint8_t *)g_inData
    };
    uint8_t handleU[sizeof(uint64_t)] = {0};
    struct OH_Huks_Blob handle = { sizeof(uint64_t), handleU };
    OH_Huks_Result ret = OH_Huks_InitSession(keyAlias, initParamSet, &handle, nullptr);
    if (ret.errorCode != OH_HUKS_SUCCESS) {
        return ret;
    }
    uint8_t outDataU[ECDH_COMMON_SIZE] = {0};
    struct OH_Huks_Blob outDataUpdate = { ECDH_COMMON_SIZE, outDataU };
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
/* Key agreement process. */
static napi_value AgreeKey(napi_env env, napi_callback_info info)
{
    struct OH_Huks_ParamSet *genParamSet = nullptr;
    struct OH_Huks_ParamSet *initParamSet01 = nullptr;
    struct OH_Huks_ParamSet *finishParamSet01 = nullptr;
    struct OH_Huks_ParamSet *initParamSet02 = nullptr;
    struct OH_Huks_ParamSet *finishParamSet02 = nullptr;
    struct OH_Huks_Blob publicKey01 = { .size = OH_HUKS_ECC_KEY_SIZE_256, .data = nullptr };
    struct OH_Huks_Blob publicKey02 = { .size = OH_HUKS_ECC_KEY_SIZE_256, .data = nullptr };
    struct OH_Huks_Blob outData01 = { .size = ECDH_COMMON_SIZE, .data = nullptr };
    struct OH_Huks_Blob outData02 = { .size = ECDH_COMMON_SIZE, .data = nullptr };
    OH_Huks_Result ohResult;
    do {
        /* 1. Set the key alias and key parameter set. */
        ohResult = InitParamSet(&genParamSet, g_genAgreeParams, sizeof(g_genAgreeParams) / sizeof(OH_Huks_Param));
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        ohResult = InitParamSet(&initParamSet01, g_agreeParamsInit01, sizeof(g_agreeParamsInit01) / sizeof(OH_Huks_Param));
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        ohResult = InitParamSet(&finishParamSet01, g_agreeParamsFinish01,
            sizeof(g_agreeParamsFinish01) / sizeof(OH_Huks_Param));
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        ohResult = InitParamSet(&initParamSet02, g_agreeParamsInit02, sizeof(g_agreeParamsInit02) / sizeof(OH_Huks_Param));
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        ohResult = InitParamSet(&finishParamSet02, g_agreeParamsFinish02,
            sizeof(g_agreeParamsFinish02) / sizeof(OH_Huks_Param));
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        /* 2. Generate an asymmetric key pair for device A. */
        ohResult = OH_Huks_GenerateKeyItem(&g_keyAlias01001, genParamSet, nullptr);
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        /* 3. Generate an asymmetric key pair for device B. */
        ohResult = OH_Huks_GenerateKeyItem(&g_keyAlias02001, genParamSet, nullptr);
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
        /* 4. Export the public key from device A and device B separately. */
        ohResult = HksEcdhAgreeExport(&g_keyAlias01001, &g_keyAlias02001, &publicKey01, &publicKey02, genParamSet);
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        ohResult = MallocAndCheckBlobData(&outData01, outData01.size);
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        ohResult = MallocAndCheckBlobData(&outData02, outData02.size);
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        /* 5. Perform key agreement for device A. */
        ohResult = HksEcdhAgreeFinish(&g_keyAlias01001, &publicKey02, initParamSet01, finishParamSet01, &outData01);
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        /* 5. Perform key agreement for device B. */
        ohResult = HksEcdhAgreeFinish(&g_keyAlias02001, &publicKey01, initParamSet02, finishParamSet02, &outData02);
    } while (0);
    free(publicKey01.data);
    free(publicKey02.data);
    free(outData01.data);
    free(outData02.data);
    /* 6. Delete keys from device A and device B. */
    OH_Huks_DeleteKeyItem(&g_keyAlias01001, genParamSet);
    OH_Huks_DeleteKeyItem(&g_keyAlias02001, genParamSet);
    OH_Huks_DeleteKeyItem(&g_keyAliasFinal1001, NULL);
    OH_Huks_DeleteKeyItem(&g_keyAliasFinal2001, NULL);
    OH_Huks_FreeParamSet(&genParamSet);
    OH_Huks_FreeParamSet(&initParamSet01);
    OH_Huks_FreeParamSet(&finishParamSet01);
    OH_Huks_FreeParamSet(&initParamSet02);
    OH_Huks_FreeParamSet(&finishParamSet02);
    
    napi_value ret;
    napi_create_int32(env, ohResult.errorCode, &ret);
    return ret;
}
```
