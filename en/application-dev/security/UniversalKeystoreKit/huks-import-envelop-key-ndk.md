# Importing a Key Using a Digital Envelope (C/C++)

<!--Kit: Universal Keystore Kit-->
<!--Subsystem: Security-->
<!--Owner: @wutiantian-gitee-->
<!--Designer: @HighLowWorld-->
<!--Tester: @wxy1234564846-->
<!--Adviser: @zengyawen-->
<!-- md-trans-meta sourceCommit=d952bbd31d41cf1a9f05cfda257478eb0904ac62 translatedAt=2026-08-13T08:24:20.085Z pushedAt=2026-08-13T10:20:24.712Z -->

The [digital envelope](./huks-key-import-overview.md#digital-envelope-import) feature is supported since API version 23.

The following uses how to import RSA and AES keys using digital envelope as an example. For details about the scenarios and supported algorithms, see [Supported Algorithms](huks-key-import-overview.md#supported-algorithms). **The DSA algorithm is not supported for key import using digital envelope.**

To import keys using digital envelope, you need to use the [OH_HUKS_TAG_UNWRAP_ALGORITHM_SUITE](../../reference/apis-universal-keystore-kit/capi-native-huks-type-h.md#oh_huks_tag) whose value is [OH_HUKS_UNWRAP_SUITE_SM2_SM4_ECB_NOPADDING](../../reference/apis-universal-keystore-kit/capi-native-huks-type-h.md#oh_huks_algsuite).

When importing a key pair of an asymmetric key using digital envelope, you need to add the [OH_HUKS_TAG_ASYMMETRIC_PUBLIC_KEY_DATA](../../reference/apis-universal-keystore-kit/capi-native-huks-type-h.md#oh_huks_tag) tag and encapsulate the public key in X.509 DER format into the tag. Only key pairs can be imported for asymmetric keys.

## Linking the Dynamic Library in the CMake Script

```txt
target_link_libraries(entry PUBLIC libhuks_ndk.z.so)
```

## How to Develop

1. Device A (service side) generates an SM4 key (**cipherSm4**).

2. Device A uses the generated SM4 key to encrypt the key to be imported (**importKey**) in ECB/NoPadding mode, obtaining the encrypted key **enImportKey** = Encrypt(**cipherSm4**, **importKey**).

3. Device B (key importer) exports the SM2 public key. Device A receives the key.

4. Device A uses the received SM2 public key to encrypt the generated SM4 key (**enSm4** is set to **Encrypt(Sm2, cipherSm4)**).

5. Device A sends the digital envelope data to device B.

6. Device B uses [OH_Huks_ImportWrappedKeyItem](../../reference/apis-universal-keystore-kit/capi-native-huks-api-h.md#oh_huks_importwrappedkeyitem) to import the key using a digital envelope. If the key to be imported is a symmetric key, you only need to encrypt the raw key in this step. If the key pair of an asymmetric key is imported, encapsulate the public key in DER format and place it in [OH_HUKS_TAG_ASYMMETRIC_PUBLIC_KEY_DATA](../../reference/apis-universal-keystore-kit/capi-native-huks-type-h.md#oh_huks_tag).

> **NOTE**
>
> If the peer device is not an OpenHarmony device and does not support the key management service, the following requirements must be met when constructing the digital envelope data:
>
> - The SM2 encryption result is combined as C1C3C2, where C1x and C1y are 32 bytes each.
>
> - The SM2 encryption result uses the ASN.1 format, where bigint is stored in big-endian order.

### Example of Importing the RSA Key

```c
#include <string.h>
#include "napi/native_api.h"
#include "huks/native_huks_api.h"
#include "huks/native_huks_param.h"
#include "huks/native_huks_type.h"

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

void ConcatBlob(OH_Huks_Blob *data1, OH_Huks_Blob *data2, OH_Huks_Blob *outData) {
    if (outData == NULL || data1 == NULL || data2 == NULL) {
        return;
    }

    uint32_t offset = 0;
    memcpy(outData->data, &data1->size, sizeof(uint32_t));
    offset += sizeof(uint32_t);

    memcpy(outData->data + offset, data1->data, data1->size);
    offset += data1->size;

    memcpy(outData->data + offset, &data2->size, sizeof(uint32_t));
    offset += sizeof(uint32_t);

    memcpy(outData->data + offset, data2->data, data2->size);
    outData->size = data1->size + data2->size + 2 * sizeof(uint32_t);

    return;
}

// Used to generate an SM2 key, simulating the existing SM2 key of the importer.
static struct OH_Huks_Param gEnvelopIniSm2[] = {
    {.tag = OH_HUKS_TAG_PURPOSE, .uint32Param = OH_HUKS_KEY_PURPOSE_DECRYPT | OH_HUKS_KEY_PURPOSE_ENCRYPT},
    {.tag = OH_HUKS_TAG_ALGORITHM, .uint32Param = OH_HUKS_ALG_SM2},
    {.tag = OH_HUKS_TAG_KEY_SIZE, .uint32Param = OH_HUKS_SM2_KEY_SIZE_256},
    {.tag = OH_HUKS_TAG_DIGEST, .uint32Param = OH_HUKS_DIGEST_SM3},
    {.tag = OH_HUKS_TAG_PADDING, .uint32Param = OH_HUKS_PADDING_NONE},
};

// Used to simulate the importer's SM2 public key obtained by the service side.
static struct OH_Huks_Param gEnvelopEnSm2[] = {
    {.tag = OH_HUKS_TAG_PURPOSE, .uint32Param = OH_HUKS_KEY_PURPOSE_ENCRYPT},
    {.tag = OH_HUKS_TAG_ALGORITHM, .uint32Param = OH_HUKS_ALG_SM2},
    {.tag = OH_HUKS_TAG_KEY_SIZE, .uint32Param = OH_HUKS_SM2_KEY_SIZE_256},
    {.tag = OH_HUKS_TAG_DIGEST, .uint32Param = OH_HUKS_DIGEST_SM3},
    {.tag = OH_HUKS_TAG_PADDING, .uint32Param = OH_HUKS_PADDING_NONE},
};

// SM4 key plaintext
uint8_t sm4UintData[] = {
    0xb9, 0xef, 0x35, 0x49, 0xb7, 0x00, 0x91, 0x58, 0x0c, 0x6f, 0x43, 0x28, 0xf8, 0x95, 0x1c, 0x02,
};

OH_Huks_Blob gSm4Data = {sizeof(sm4UintData) / sizeof(sm4UintData[0]), sm4UintData};
uint8_t sm2KeyAliasUint8[] = "testKey";
OH_Huks_Blob gSm2KeyAlias = {.size = sizeof(sm2KeyAliasUint8), .data = sm2KeyAliasUint8};

static napi_value EnvelopImportKey(napi_env env, napi_callback_info info) {
    struct OH_Huks_ParamSet *sm2GenerateKeyParamSet = NULL;
    struct OH_Huks_Result ohResult;
    struct OH_Huks_ParamSet *sm2KeyData = NULL;
    napi_value ret;

    // Generate an SM2 key, simulating the SM2 key exported by device B.
    ohResult = InitParamSet(&sm2GenerateKeyParamSet, gEnvelopIniSm2, sizeof(gEnvelopIniSm2) / sizeof(OH_Huks_Param));
    if (ohResult.errorCode != OH_HUKS_SUCCESS) {
        napi_create_int32(env, ohResult.errorCode, &ret);
        return ret;
    }

    ohResult = OH_Huks_GenerateKeyItem(&gSm2KeyAlias, sm2GenerateKeyParamSet, sm2KeyData);
    if (ohResult.errorCode != OH_HUKS_SUCCESS) {
        OH_Huks_FreeParamSet(&sm2GenerateKeyParamSet);
        napi_create_int32(env, ohResult.errorCode, &ret);
        return ret;
    }

    uint8_t handleE[sizeof(uint64_t)] = {0};
    struct OH_Huks_Blob handleEncrypt = {sizeof(uint64_t), handleE};

    // Use the SM2 key for encryption.
    struct OH_Huks_ParamSet *sm2EnKeyParamSet = NULL;
    ohResult = InitParamSet(&sm2EnKeyParamSet, gEnvelopEnSm2, sizeof(gEnvelopEnSm2) / sizeof(OH_Huks_Param));
    if (ohResult.errorCode != OH_HUKS_SUCCESS) {
        OH_Huks_FreeParamSet(&sm2GenerateKeyParamSet);
        napi_create_int32(env, ohResult.errorCode, &ret);
        return ret;
    }

    ohResult = OH_Huks_InitSession(&gSm2KeyAlias, sm2EnKeyParamSet, &handleEncrypt, nullptr);
    if (ohResult.errorCode != OH_HUKS_SUCCESS) {
        OH_Huks_FreeParamSet(&sm2GenerateKeyParamSet);
        OH_Huks_FreeParamSet(&sm2EnKeyParamSet);
        napi_create_int32(env, ohResult.errorCode, &ret);
        return ret;
    }

    static const uint32_t SM4_SIZE = 128;
    uint8_t cipher[SM4_SIZE] = {0};
    struct OH_Huks_Blob cipherSm4Data = {SM4_SIZE, cipher};
    ohResult = OH_Huks_FinishSession(&handleEncrypt, sm2EnKeyParamSet, &gSm4Data, &cipherSm4Data);
    if (ohResult.errorCode != OH_HUKS_SUCCESS) {
        OH_Huks_FreeParamSet(&sm2GenerateKeyParamSet);
        OH_Huks_FreeParamSet(&sm2EnKeyParamSet);
        napi_create_int32(env, ohResult.errorCode, &ret);
        return ret;
    }

    uint8_t rsaUintPubKey[] = {
        0x30, 0x82, 0x01, 0x22, 0x30, 0x0d, 0x06, 0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01, 0x01, 0x01, 0x05,
        0x00, 0x03, 0x82, 0x01, 0x0f, 0x00, 0x30, 0x82, 0x01, 0x0a, 0x02, 0x82, 0x01, 0x01, 0x00, 0xa2, 0xd2, 0x3c,
        0xe9, 0x87, 0x8b, 0x48, 0x34, 0xdd, 0x41, 0xe0, 0x65, 0x39, 0xcc, 0xea, 0x25, 0x25, 0xa6, 0x9e, 0x9f, 0x20,
        0xc6, 0x13, 0x9f, 0xb2, 0xa7, 0xf3, 0x77, 0x69, 0xfd, 0xa9, 0xbd, 0xe8, 0x2c, 0xf3, 0x87, 0x3a, 0xc0, 0x2a,
        0x01, 0x1f, 0x8d, 0x0f, 0x59, 0x28, 0x34, 0xfb, 0xe3, 0x8d, 0x9b, 0xa1, 0xe0, 0xe4, 0x60, 0x7d, 0x20, 0x19,
        0x49, 0x6f, 0x13, 0x5e, 0xae, 0x3e, 0x4d, 0x6c, 0x31, 0x6c, 0x0b, 0x90, 0xf8, 0xd2, 0xf3, 0x45, 0x4f, 0x3b,
        0x9f, 0x8e, 0x3b, 0x77, 0x20, 0x9e, 0x54, 0xec, 0x7b, 0x54, 0x15, 0xf0, 0x09, 0x8f, 0x5a, 0xf9, 0x87, 0x9a,
        0x27, 0x23, 0x99, 0x64, 0x4d, 0x8c, 0x80, 0x5c, 0x2e, 0xee, 0xc3, 0x57, 0x6e, 0x3d, 0x91, 0xfb, 0x77, 0x67,
        0x3b, 0x8a, 0xed, 0x01, 0xb5, 0x91, 0x33, 0xa1, 0xaa, 0xb2, 0x0d, 0x49, 0x25, 0x7c, 0x4d, 0x42, 0xde, 0xfb,
        0xcd, 0xd6, 0x48, 0xb8, 0xce, 0xe7, 0x22, 0x71, 0x43, 0x54, 0x2c, 0x6b, 0xbb, 0xbf, 0x63, 0xdc, 0xea, 0x6f,
        0x77, 0x81, 0xe9, 0x07, 0xe0, 0x18, 0xb3, 0x1e, 0x78, 0x4b, 0xbc, 0x17, 0x77, 0x62, 0x25, 0xd9, 0xe7, 0x23,
        0x6c, 0x80, 0xad, 0xdc, 0x51, 0x18, 0x1b, 0x33, 0x56, 0x59, 0x15, 0x43, 0xcf, 0x51, 0xd9, 0xbc, 0x6d, 0xf7,
        0x68, 0xd1, 0xe8, 0xbf, 0x41, 0x36, 0xd1, 0x30, 0x92, 0x7b, 0x48, 0xd1, 0x00, 0xe2, 0x9d, 0x8e, 0x94, 0xee,
        0x20, 0x2a, 0x18, 0xb1, 0x04, 0xba, 0xe7, 0x19, 0xdc, 0x69, 0x36, 0xf7, 0x34, 0x4b, 0x16, 0x10, 0x10, 0x2a,
        0x46, 0x1c, 0x4e, 0x6e, 0x62, 0xe1, 0x25, 0x79, 0xd5, 0x5c, 0xf3, 0x9a, 0xeb, 0x1f, 0x3d, 0x82, 0xa3, 0xaa,
        0x79, 0xde, 0x23, 0xa1, 0x2b, 0x50, 0x6d, 0x68, 0x3e, 0x77, 0x33, 0xe0, 0xc9, 0x18, 0xbc, 0x65, 0x58, 0x63,
        0x7b, 0x02, 0x03, 0x01, 0x00, 0x01,
    };

    OH_Huks_Param rsaParams[] = {
        {.tag = OH_HUKS_TAG_ALGORITHM, .uint32Param = OH_HUKS_ALG_RSA},
        {.tag = OH_HUKS_TAG_KEY_SIZE, .uint32Param = OH_HUKS_RSA_KEY_SIZE_2048},
        {.tag = OH_HUKS_TAG_PURPOSE, .uint32Param = OH_HUKS_KEY_PURPOSE_ENCRYPT},
        {.tag = OH_HUKS_TAG_PADDING, .uint32Param = OH_HUKS_PADDING_NONE},
        {.tag = OH_HUKS_TAG_BLOCK_MODE, .uint32Param = OH_HUKS_MODE_ECB},
        {.tag = OH_HUKS_TAG_UNWRAP_ALGORITHM_SUITE, .uint32Param = OH_HUKS_UNWRAP_SUITE_SM2_SM4_ECB_NOPADDING},
        {.tag = OH_HUKS_TAG_IMPORT_KEY_TYPE, .uint32Param = OH_HUKS_KEY_TYPE_KEY_PAIR},
        {.tag = OH_HUKS_TAG_ASYMMETRIC_PUBLIC_KEY_DATA, .blob = {sizeof(rsaUintPubKey), rsaUintPubKey}},
    };

    struct OH_Huks_ParamSet *rsaParamSet = NULL;
    ohResult = InitParamSet(&rsaParamSet, rsaParams, sizeof(rsaParams) / sizeof(OH_Huks_Param));
    if (ohResult.errorCode != OH_HUKS_SUCCESS) {
        OH_Huks_FreeParamSet(&sm2GenerateKeyParamSet);
        OH_Huks_FreeParamSet(&sm2EnKeyParamSet);
        napi_create_int32(env, ohResult.errorCode, &ret);
        return ret;
    }
    
    // SM4 has been used for encryption, and the key is sm4UintData.
    uint8_t rsaPrivate[] = {
        0x4a, 0xce, 0x89, 0xa6, 0xda, 0x85, 0x6d, 0x56, 0xb3, 0xab, 0xc9, 0x70, 0x5e, 0x3f, 0xb6, 0x0e, 0x07, 0xdf,
        0xdf, 0x9c, 0xb3, 0x05, 0xd4, 0x8d, 0xc0, 0xac, 0x9b, 0x13, 0x3d, 0x1b, 0xdb, 0xa0, 0x46, 0x1a, 0xc8, 0x82,
        0x80, 0xe0, 0x2a, 0x28, 0x34, 0xa6, 0x4a, 0x97, 0x91, 0x58, 0xc8, 0x8c, 0x0f, 0xa2, 0xeb, 0xe1, 0xf8, 0x37,
        0x54, 0x99, 0x7e, 0xa1, 0xce, 0x1e, 0xf3, 0x8b, 0x8c, 0x8d, 0xec, 0x58, 0xb7, 0x32, 0x29, 0x36, 0x34, 0x46,
        0x92, 0x67, 0x09, 0xb3, 0xb4, 0xb3, 0x74, 0x3a, 0x77, 0x99, 0xd7, 0x4b, 0x1f, 0xf6, 0xa6, 0xb0, 0x99, 0x3d,
        0x3e, 0x92, 0xba, 0xcf, 0x83, 0xd0, 0x1e, 0x18, 0x68, 0x1a, 0xb5, 0xfe, 0x18, 0x6d, 0x9d, 0xc2, 0x39, 0x48,
        0x2e, 0x52, 0xfc, 0x33, 0x16, 0xb0, 0x58, 0xd5, 0xdf, 0x84, 0xbe, 0xfe, 0xe1, 0xfa, 0xa9, 0x65, 0x34, 0xb8,
        0x97, 0xa3, 0x9a, 0x45, 0x8a, 0x40, 0x4b, 0x09, 0xdf, 0x1c, 0x48, 0x57, 0x3f, 0xb2, 0x1f, 0xf3, 0x21, 0x7d,
        0xa8, 0xa5, 0xed, 0xe1, 0x61, 0x2f, 0xe0, 0xda, 0xae, 0x15, 0x22, 0x18, 0xf6, 0x84, 0x7d, 0x39, 0xae, 0x35,
        0x49, 0xec, 0xd8, 0x66, 0xff, 0x65, 0x7d, 0xd9, 0x74, 0x19, 0xad, 0x26, 0x64, 0xc0, 0x2d, 0x93, 0xf5, 0x83,
        0x7d, 0x8d, 0x98, 0x35, 0x2e, 0x67, 0xf9, 0xc0, 0xb1, 0xd7, 0x2b, 0xb5, 0x49, 0x98, 0x3a, 0x31, 0xa0, 0x66,
        0x71, 0x6e, 0x09, 0x70, 0xef, 0x56, 0x14, 0x9e, 0xb8, 0xd2, 0x17, 0x99, 0x44, 0x69, 0xcd, 0x3d, 0xcb, 0x3c,
        0xfe, 0xbe, 0x72, 0xc0, 0x43, 0x29, 0x86, 0x70, 0x9d, 0xa3, 0xc0, 0x68, 0xf6, 0x7e, 0x48, 0x2c, 0x4e, 0x48,
        0xe0, 0xf6, 0xa9, 0xcb, 0x28, 0x63, 0xe8, 0x33, 0xfc, 0xb4, 0x1a, 0x06, 0xf4, 0x13, 0x20, 0xfd, 0x90, 0x90,
        0x1c, 0x25, 0xd7, 0xf8,
    };
    OH_Huks_Blob rsaEnPrivateData = {sizeof(rsaPrivate), rsaPrivate};

    uint8_t importKey[1000] = {0};
    OH_Huks_Blob importKeyBlob = {0, importKey};
    ConcatBlob(&cipherSm4Data, &rsaEnPrivateData, &importKeyBlob);

    uint8_t importAlias[] = "importRsa";
    OH_Huks_Blob rsaKeyAlias = {(uint32_t)sizeof(importAlias), importAlias};
    ohResult = OH_Huks_ImportWrappedKeyItem(&rsaKeyAlias, &gSm2KeyAlias, rsaParamSet, &importKeyBlob);

    OH_Huks_FreeParamSet(&sm2EnKeyParamSet);
    OH_Huks_FreeParamSet(&sm2GenerateKeyParamSet);
    OH_Huks_FreeParamSet(&rsaParamSet);

    napi_create_int32(env, ohResult.errorCode, &ret);
    return ret;
}
```

### Example of Importing the AES Key

```c
#include <string.h>
#include "napi/native_api.h"
#include "huks/native_huks_api.h"
#include "huks/native_huks_param.h"
#include "huks/native_huks_type.h"

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

void ConcatBlob(OH_Huks_Blob *data1, OH_Huks_Blob *data2, OH_Huks_Blob *outData)
{
    if (outData == NULL || data1 == NULL || data2 == NULL) {
        return;
    }

    uint32_t offset = 0;
    memcpy(outData->data, &data1->size, sizeof(uint32_t));
    offset += sizeof(uint32_t);

    memcpy(outData->data + offset, data1->data, data1->size);
    offset += data1->size;

    memcpy(outData->data + offset, &data2->size, sizeof(uint32_t));
    offset += sizeof(uint32_t);

    memcpy(outData->data + offset, data2->data, data2->size);
    outData->size = data1->size + data2->size + 2 * sizeof(uint32_t);

    return;
}

// Used to generate an SM2 key, simulating the existing SM2 key of the importer.
static struct OH_Huks_Param gEnvelopIniSm2[] = {
    {.tag = OH_HUKS_TAG_PURPOSE, .uint32Param = OH_HUKS_KEY_PURPOSE_DECRYPT | OH_HUKS_KEY_PURPOSE_ENCRYPT},
    {.tag = OH_HUKS_TAG_ALGORITHM, .uint32Param = OH_HUKS_ALG_SM2},
    {.tag = OH_HUKS_TAG_KEY_SIZE, .uint32Param = OH_HUKS_SM2_KEY_SIZE_256},
    {.tag = OH_HUKS_TAG_DIGEST, .uint32Param = OH_HUKS_DIGEST_SM3},
    {.tag = OH_HUKS_TAG_PADDING, .uint32Param = OH_HUKS_PADDING_NONE},
};

// Used to simulate the importer's SM2 public key obtained by the service side.
static struct OH_Huks_Param gEnvelopEnSm2[] = {
    {.tag = OH_HUKS_TAG_PURPOSE, .uint32Param = OH_HUKS_KEY_PURPOSE_ENCRYPT},
    {.tag = OH_HUKS_TAG_ALGORITHM, .uint32Param = OH_HUKS_ALG_SM2},
    {.tag = OH_HUKS_TAG_KEY_SIZE, .uint32Param = OH_HUKS_SM2_KEY_SIZE_256},
    {.tag = OH_HUKS_TAG_DIGEST, .uint32Param = OH_HUKS_DIGEST_SM3},
    {.tag = OH_HUKS_TAG_PADDING, .uint32Param = OH_HUKS_PADDING_NONE},
};

// SM4 key plaintext
uint8_t sm4UintData[] = {
    0xb9, 0xef, 0x35, 0x49, 0xb7, 0x00, 0x91, 0x58, 0x0c, 0x6f, 0x43, 0x28, 0xf8, 0x95, 0x1c, 0x02,
};

OH_Huks_Blob gSm4Data = {sizeof(sm4UintData) / sizeof(sm4UintData[0]), sm4UintData};
uint8_t sm2KeyAliasUint8[] = "testKey";
OH_Huks_Blob gSm2KeyAlias = {.size = sizeof(sm2KeyAliasUint8), .data = sm2KeyAliasUint8};

static napi_value EnvelopImportKeyTest(napi_env env, napi_callback_info info)
{
    struct OH_Huks_ParamSet *sm2GenerateKeyParamSet = NULL;
    struct OH_Huks_Result ohResult;
    struct OH_Huks_ParamSet *sm2KeyData = NULL;
    struct OH_Huks_ParamSet *aesParamSet = NULL;
    struct OH_Huks_ParamSet *sm2EnKeyParamSet = NULL;
    napi_value ret;

    uint8_t aesAlias[] = "testAes";
    OH_Huks_Blob aesAliasBlob = {(uint32_t)sizeof(aesAlias), aesAlias};

    ohResult = InitParamSet(&sm2GenerateKeyParamSet, gEnvelopIniSm2, sizeof(gEnvelopIniSm2) / sizeof(OH_Huks_Param));
    if (ohResult.errorCode != OH_HUKS_SUCCESS) {
        napi_create_int32(env, ohResult.errorCode, &ret);
        return ret;
    }
    ohResult = OH_Huks_GenerateKeyItem(&gSm2KeyAlias, sm2GenerateKeyParamSet, sm2KeyData);
    if (ohResult.errorCode != OH_HUKS_SUCCESS) {
        OH_Huks_FreeParamSet(&sm2GenerateKeyParamSet);
        napi_create_int32(env, ohResult.errorCode, &ret);
        return ret;
    }
    uint8_t handleE[sizeof(uint64_t)] = {0};
    struct OH_Huks_Blob handleEncrypt = {sizeof(uint64_t), handleE};
    ohResult = InitParamSet(&sm2EnKeyParamSet, gEnvelopEnSm2, sizeof(gEnvelopEnSm2) / sizeof(OH_Huks_Param));
    if (ohResult.errorCode != OH_HUKS_SUCCESS) {
        OH_Huks_FreeParamSet(&sm2GenerateKeyParamSet);
        napi_create_int32(env, ohResult.errorCode, &ret);
        return ret;
    }

    ohResult = OH_Huks_InitSession(&gSm2KeyAlias, sm2EnKeyParamSet, &handleEncrypt, nullptr);
    if (ohResult.errorCode != OH_HUKS_SUCCESS) {
        OH_Huks_FreeParamSet(&sm2EnKeyParamSet);
        OH_Huks_FreeParamSet(&sm2GenerateKeyParamSet);
        napi_create_int32(env, ohResult.errorCode, &ret);
        return ret;
    }
    static const uint32_t SM4_SIZE = 128;
    uint8_t cipher[SM4_SIZE] = {0};
    struct OH_Huks_Blob cipherSm4Data = {SM4_SIZE, cipher};
    ohResult = OH_Huks_FinishSession(&handleEncrypt, sm2EnKeyParamSet, &gSm4Data, &cipherSm4Data);
    if (ohResult.errorCode != OH_HUKS_SUCCESS) {
        OH_Huks_FreeParamSet(&sm2EnKeyParamSet);
        OH_Huks_FreeParamSet(&sm2GenerateKeyParamSet);
        napi_create_int32(env, ohResult.errorCode, &ret);
        return ret;
    }

    OH_Huks_Param importAesParams[] = {
        {.tag = OH_HUKS_TAG_ALGORITHM, .uint32Param = OH_HUKS_ALG_AES},
        {.tag = OH_HUKS_TAG_PURPOSE, .uint32Param = OH_HUKS_KEY_PURPOSE_ENCRYPT | OH_HUKS_KEY_PURPOSE_DECRYPT},
        {.tag = OH_HUKS_TAG_BLOCK_MODE, .uint32Param = OH_HUKS_MODE_CBC},
        {.tag = OH_HUKS_TAG_PADDING, .uint32Param = OH_HUKS_PADDING_PKCS7},
        {.tag = OH_HUKS_TAG_UNWRAP_ALGORITHM_SUITE, .uint32Param = OH_HUKS_UNWRAP_SUITE_SM2_SM4_ECB_NOPADDING},
        {.tag = OH_HUKS_TAG_KEY_SIZE, .uint32Param = OH_HUKS_AES_KEY_SIZE_128}};

    ohResult = InitParamSet(&aesParamSet, importAesParams, sizeof(importAesParams) / sizeof(OH_Huks_Param));
    // SM4 has been used for encryption, and the key is sm4UintData.
    uint8_t importAesData[] = {
        0xa5, 0xa4, 0xef, 0x4b, 0x87, 0x69, 0xf1, 0xd0, 0x7c, 0xd0, 0x55, 0x9a, 0xe0, 0xb8, 0x8c, 0x36,
    };
    OH_Huks_Blob aesBlob = {sizeof(importAesData), importAesData};

    uint8_t importKey[1000] = {0};
    OH_Huks_Blob importKeyBlob = {0, importKey};
    ConcatBlob(&cipherSm4Data, &aesBlob, &importKeyBlob);

    ohResult = OH_Huks_ImportWrappedKeyItem(&aesAliasBlob, &gSm2KeyAlias, aesParamSet, &importKeyBlob);

    OH_Huks_FreeParamSet(&sm2EnKeyParamSet);
    OH_Huks_FreeParamSet(&sm2GenerateKeyParamSet);
    OH_Huks_FreeParamSet(&aesParamSet);

    return ret;
}
```