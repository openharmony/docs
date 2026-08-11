# 数字信封导入密钥(C/C++)

<!--Kit: Universal Keystore Kit-->
<!--Subsystem: Security-->
<!--Owner: @wutiantian-gitee-->
<!--Designer: @HighLowWorld-->
<!--Tester: @wxy1234564846-->
<!--Adviser: @zengyawen-->

从API 23开始支持[数字信封](./huks-key-import-overview.md#数字信封导入)特性。

以数字信封导入RSA密钥和AES密钥为例。具体的场景介绍及支持的算法规格，请参考[密钥导入支持的算法](huks-key-import-overview.md#支持的算法)，其中**数字信封导入密钥不支持DSA算法**。

使用数字信封导入密钥需要使用[OH_HUKS_TAG_UNWRAP_ALGORITHM_SUITE](../../reference/apis-universal-keystore-kit/capi-native-huks-type-h.md#oh_huks_tag)，该标签值为[OH_HUKS_UNWRAP_SUITE_SM2_SM4_ECB_NOPADDING](../../reference/apis-universal-keystore-kit/capi-native-huks-type-h.md#oh_huks_algsuite)。

数字信封导入密钥时，如果是导入非对称密钥的密钥对，需要添加[OH_HUKS_TAG_ASYMMETRIC_PUBLIC_KEY_DATA](../../reference/apis-universal-keystore-kit/capi-native-huks-type-h.md#oh_huks_tag)标签，并将公钥以X.509 DER格式封装填入该标签，且针对非对称密钥仅支持以密钥对形式导入。

## 在CMake脚本中链接相关动态库
```txt
target_link_libraries(entry PUBLIC libhuks_ndk.z.so)
```
## 开发步骤
1. 业务方设备（设备A）生成SM4密钥，cipherSm4。
2. 设备A使用生成的SM4密钥，以ECB/NoPadding模式对导入的密钥importKey进行加密，得到加密后的密钥为enImportKey=Encrypt(cipherSm4, importKey)。
3. 密钥导入方（设备B）导出SM2公钥，设备A接收该密钥。
4. 设备A使用收到的SM2公钥加密生成的SM4密钥，enSm4=Encrypt(Sm2, cipherSm4)。
5. 设备A将数字信封数据发送给设备B。
6. 设备B使用[OH_Huks_ImportWrappedKeyItem](../../reference/apis-universal-keystore-kit/capi-native-huks-api-h.md#oh_huks_importwrappedkeyitem)导入数字信封密钥。若导入密钥是对称密钥，此步骤只需对裸密钥进行加密。若导入非对称密钥的密钥对，则将公钥以DER格式封装，并放入[OH_HUKS_TAG_ASYMMETRIC_PUBLIC_KEY_DATA](../../reference/apis-universal-keystore-kit/capi-native-huks-type-h.md#oh_huks_tag)中。

> **说明：**
>
> 若对端设备非OpenHarmony设备且不支持密钥管理服务，则在构造数字信封数据时需遵循以下要求：
>
> - SM2加密结果组合方式为C1C3C2，其中C1x和C1y各32字节；
>
> - SM2加密结果采用ASN.1格式，其中bigint采用大端的方式存储；

### RSA导入示例
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

// 用于生成Sm2密钥，模拟导入端已有的Sm2密钥
static struct OH_Huks_Param gEnvelopIniSm2[] = {
    {.tag = OH_HUKS_TAG_PURPOSE, .uint32Param = OH_HUKS_KEY_PURPOSE_DECRYPT | OH_HUKS_KEY_PURPOSE_ENCRYPT},
    {.tag = OH_HUKS_TAG_ALGORITHM, .uint32Param = OH_HUKS_ALG_SM2},
    {.tag = OH_HUKS_TAG_KEY_SIZE, .uint32Param = OH_HUKS_SM2_KEY_SIZE_256},
    {.tag = OH_HUKS_TAG_DIGEST, .uint32Param = OH_HUKS_DIGEST_SM3},
    {.tag = OH_HUKS_TAG_PADDING, .uint32Param = OH_HUKS_PADDING_NONE},
};

// 用于模拟业务方得到的导入端Sm2公钥
static struct OH_Huks_Param gEnvelopEnSm2[] = {
    {.tag = OH_HUKS_TAG_PURPOSE, .uint32Param = OH_HUKS_KEY_PURPOSE_ENCRYPT},
    {.tag = OH_HUKS_TAG_ALGORITHM, .uint32Param = OH_HUKS_ALG_SM2},
    {.tag = OH_HUKS_TAG_KEY_SIZE, .uint32Param = OH_HUKS_SM2_KEY_SIZE_256},
    {.tag = OH_HUKS_TAG_DIGEST, .uint32Param = OH_HUKS_DIGEST_SM3},
    {.tag = OH_HUKS_TAG_PADDING, .uint32Param = OH_HUKS_PADDING_NONE},
};

// Sm4密钥明文
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

    // 生成一个sm2密钥模拟设备B导出的sm2密钥
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

    // 使用sm2密钥加密
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
    
    // 已使用sm4加密，密钥为sm4UintData
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

### AES导入示例
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

// 用于生成Sm2密钥，模拟导入端已有的Sm2密钥
static struct OH_Huks_Param gEnvelopIniSm2[] = {
    {.tag = OH_HUKS_TAG_PURPOSE, .uint32Param = OH_HUKS_KEY_PURPOSE_DECRYPT | OH_HUKS_KEY_PURPOSE_ENCRYPT},
    {.tag = OH_HUKS_TAG_ALGORITHM, .uint32Param = OH_HUKS_ALG_SM2},
    {.tag = OH_HUKS_TAG_KEY_SIZE, .uint32Param = OH_HUKS_SM2_KEY_SIZE_256},
    {.tag = OH_HUKS_TAG_DIGEST, .uint32Param = OH_HUKS_DIGEST_SM3},
    {.tag = OH_HUKS_TAG_PADDING, .uint32Param = OH_HUKS_PADDING_NONE},
};

// 用于模拟业务方得到的导入端Sm2公钥
static struct OH_Huks_Param gEnvelopEnSm2[] = {
    {.tag = OH_HUKS_TAG_PURPOSE, .uint32Param = OH_HUKS_KEY_PURPOSE_ENCRYPT},
    {.tag = OH_HUKS_TAG_ALGORITHM, .uint32Param = OH_HUKS_ALG_SM2},
    {.tag = OH_HUKS_TAG_KEY_SIZE, .uint32Param = OH_HUKS_SM2_KEY_SIZE_256},
    {.tag = OH_HUKS_TAG_DIGEST, .uint32Param = OH_HUKS_DIGEST_SM3},
    {.tag = OH_HUKS_TAG_PADDING, .uint32Param = OH_HUKS_PADDING_NONE},
};

// Sm4密钥明文
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
    // 已使用sm4加密，密钥为sm4UintData
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