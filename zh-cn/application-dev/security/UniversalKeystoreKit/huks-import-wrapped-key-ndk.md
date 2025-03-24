# 加密导入密钥(C/C++)


以加密导入ECDH密钥对为例，涉及业务侧加密密钥的[密钥生成](huks-key-generation-overview.md)、[协商](huks-key-agreement-overview.md)等操作不在本示例中体现。


具体的场景介绍及支持的算法规格，请参考[密钥导入的支持的算法](huks-key-import-overview.md#支持的算法)。

## 在CMake脚本中链接相关动态库
```txt
target_link_libraries(entry PUBLIC libhuks_ndk.z.so)
```

## 开发步骤
> **说明：**
> 下文中wrap指加密，unwrap指解密
1. 设备A（导入设备）将待导入密钥转换成[HUKS密钥材料格式](huks-concepts.md#密钥材料格式)To_Import_Key（仅针对非对称密钥，若待导入密钥是对称密钥则可省略此步骤）。

2. 设备B（被导入设备）生成一个加密导入用途的、用于协商的非对称密钥对Wrapping_Key（公钥Wrapping_Pk，私钥Wrapping_Sk），其密钥用途设置为unwrap，导出Wrapping_Key的公钥材料Wrapping_Pk并保存。

3. 设备A使用和设备B同样的算法，生成一个加密导入用途的、用于协商的非对称密钥对Caller_Key（公钥Caller_Pk，私钥Caller_Sk），导出Caller_Key的公钥材料Caller_Pk并保存。

4. 设备A生成一个对称密钥Caller_Kek，该密钥后续将用于加密To_Import_Key。

5. 设备A基于Caller_Key的私钥Caller_Sk和设备B Wrapping_Key的公钥Wrapping_Pk，协商出Shared_Key。

6. 设备A使用Caller_Kek加密To_Import_Key，生成To_Import_Key_Enc。

7. 设备A使用Shared_Key加密Caller_Kek，生成Caller_Kek_Enc。

8. 设备A封装Caller_Pk、Caller_Kek_Enc、To_Import_Key_Enc等加密导入的密钥材料并发送给设备B，加密导入密钥材料格式见[加密导入密钥材料格式](huks-key-import-overview.md#加密导入密钥材料格式)。

9. 设备B导入封装的加密密钥材料。

10. 设备A、B删除用于加密导入的密钥。

```c++
#include "huks/native_huks_api.h"
#include "huks/native_huks_param.h"
#include "napi/native_api.h"
#include <algorithm>
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
struct HksImportWrappedKeyTestParams {
    // server key, for real
    struct OH_Huks_Blob *wrappingKeyAlias;
    struct OH_Huks_ParamSet *genWrappingKeyParamSet;
    uint32_t publicKeySize;
    struct OH_Huks_Blob *callerKeyAlias;
    struct OH_Huks_ParamSet *genCallerKeyParamSet;
    struct OH_Huks_Blob *callerKekAlias;
    struct OH_Huks_Blob *callerKek;
    struct OH_Huks_ParamSet *importCallerKekParamSet;
    struct OH_Huks_Blob *callerAgreeKeyAlias;
    struct OH_Huks_ParamSet *agreeParamSet;
    struct OH_Huks_ParamSet *importWrappedKeyParamSet;
    struct OH_Huks_Blob *importedKeyAlias;
    struct OH_Huks_Blob *importedPlainKey;
    uint32_t keyMaterialLen;
};
static const uint32_t IV_SIZE = 16;
static uint8_t IV[IV_SIZE] = "bababababababab"; // 此处仅为测试数据，实际使用时该值每次应该不同
static const uint32_t WRAPPED_KEY_IV_SIZE = 16;
static uint8_t WRAPPED_KEY_IV[IV_SIZE] = "bababababababab"; // 此处仅为测试数据，实际使用时该值每次应该不同
static const uint32_t AAD_SIZE = 16;
static uint8_t AAD[AAD_SIZE] = "abababababababa"; // 此处仅为测试数据，实际使用时该值每次应该不同
static const uint32_t NONCE_SIZE = 12;
static uint8_t NONCE[NONCE_SIZE] = "hahahahahah"; // 此处仅为测试数据，实际使用时该值每次应该不同
static const uint32_t AEAD_TAG_SIZE = 16;
static const uint32_t X25519_256_SIZE = 256;
static struct OH_Huks_Blob g_wrappingKeyAliasAes256 = {.size = (uint32_t)strlen("test_wrappingKey_x25519_aes256"),
                                                       .data = (uint8_t *)"test_wrappingKey_x25519_aes256"};
static struct OH_Huks_Blob g_callerKeyAliasAes256 = {.size = (uint32_t)strlen("test_caller_key_x25519_aes256"),
                                                     .data = (uint8_t *)"test_caller_key_x25519_aes256"};
static struct OH_Huks_Blob g_callerKekAliasAes256 = {.size = (uint32_t)strlen("test_caller_kek_x25519_aes256"),
                                                     .data = (uint8_t *)"test_caller_kek_x25519_aes256"};
static struct OH_Huks_Blob g_callerAes256Kek = {.size = (uint32_t)strlen("This is kek to encrypt plain key"),
                                                .data = (uint8_t *)"This is kek to encrypt plain key"};
static struct OH_Huks_Blob g_callerAgreeKeyAliasAes256 = {.size =
                                                              (uint32_t)strlen("test_caller_agree_key_x25519_aes256"),
                                                          .data = (uint8_t *)"test_caller_agree_key_x25519_aes256"};
static struct OH_Huks_Blob g_importedKeyAliasAes256 = {.size = (uint32_t)strlen("test_import_key_x25519_aes256"),
                                                       .data = (uint8_t *)"test_import_key_x25519_aes256"};
static struct OH_Huks_Blob g_importedAes256PlainKey = {.size = (uint32_t)strlen("This is plain key to be imported"),
                                                       .data = (uint8_t *)"This is plain key to be imported"};
static struct OH_Huks_Param g_importWrappedAes256Params[] = {
    {.tag = OH_HUKS_TAG_ALGORITHM, .uint32Param = OH_HUKS_ALG_AES},
    {.tag = OH_HUKS_TAG_PURPOSE, .uint32Param = OH_HUKS_KEY_PURPOSE_ENCRYPT | OH_HUKS_KEY_PURPOSE_DECRYPT},
    {.tag = OH_HUKS_TAG_KEY_SIZE, .uint32Param = OH_HUKS_AES_KEY_SIZE_256},
    {.tag = OH_HUKS_TAG_PADDING, .uint32Param = OH_HUKS_PADDING_NONE},
    {.tag = OH_HUKS_TAG_BLOCK_MODE, .uint32Param = OH_HUKS_MODE_GCM},
    {.tag = OH_HUKS_TAG_DIGEST, .uint32Param = OH_HUKS_DIGEST_NONE},
    {.tag = OH_HUKS_TAG_UNWRAP_ALGORITHM_SUITE, .uint32Param = OH_HUKS_UNWRAP_SUITE_X25519_AES_256_GCM_NOPADDING},
    {.tag = OH_HUKS_TAG_ASSOCIATED_DATA,
     .blob = {.size = AAD_SIZE, .data = (uint8_t *)AAD}}, // 此处仅为测试数据，实际使用时该值应与调用者信息相关
    {.tag = OH_HUKS_TAG_NONCE,
     .blob = {.size = NONCE_SIZE, .data = (uint8_t *)NONCE}}}; // 此处仅为测试数据，实际使用时该值每次应该不同
static const uint32_t g_x25519PubKeySize = 32;
static struct OH_Huks_Param g_genWrappingKeyParams[] = {
    {.tag = OH_HUKS_TAG_ALGORITHM, .uint32Param = OH_HUKS_ALG_X25519},
    {.tag = OH_HUKS_TAG_PURPOSE, .uint32Param = OH_HUKS_KEY_PURPOSE_UNWRAP},
    {.tag = OH_HUKS_TAG_KEY_SIZE, .uint32Param = OH_HUKS_CURVE25519_KEY_SIZE_256}};
static struct OH_Huks_Param g_genCallerX25519Params[] = {
    {.tag = OH_HUKS_TAG_ALGORITHM, .uint32Param = OH_HUKS_ALG_X25519},
    {.tag = OH_HUKS_TAG_PURPOSE, .uint32Param = OH_HUKS_KEY_PURPOSE_AGREE},
    {.tag = OH_HUKS_TAG_KEY_SIZE, .uint32Param = OH_HUKS_CURVE25519_KEY_SIZE_256}};
static struct OH_Huks_Param g_importParamsCallerKek[] = {
    {.tag = OH_HUKS_TAG_ALGORITHM, .uint32Param = OH_HUKS_ALG_AES},
    {.tag = OH_HUKS_TAG_PURPOSE, .uint32Param = OH_HUKS_KEY_PURPOSE_ENCRYPT},
    {.tag = OH_HUKS_TAG_KEY_SIZE, .uint32Param = OH_HUKS_AES_KEY_SIZE_256},
    {.tag = OH_HUKS_TAG_PADDING, .uint32Param = OH_HUKS_PADDING_NONE},
    {.tag = OH_HUKS_TAG_BLOCK_MODE, .uint32Param = OH_HUKS_MODE_GCM},
    {.tag = OH_HUKS_TAG_DIGEST, .uint32Param = OH_HUKS_DIGEST_NONE},
    {.tag = OH_HUKS_TAG_IV,
     .blob = {.size = WRAPPED_KEY_IV_SIZE,
              .data = (uint8_t *)WRAPPED_KEY_IV}}}; // 此处仅为测试数据，实际使用时该值每次应该不同
static struct OH_Huks_Param g_callerAgreeParams[] = {
    {.tag = OH_HUKS_TAG_ALGORITHM, .uint32Param = OH_HUKS_ALG_X25519},
    {.tag = OH_HUKS_TAG_PURPOSE, .uint32Param = OH_HUKS_KEY_PURPOSE_AGREE},
    {.tag = OH_HUKS_TAG_KEY_SIZE, .uint32Param = OH_HUKS_CURVE25519_KEY_SIZE_256}};
static struct OH_Huks_Param g_aesKekEncryptParams[] = {
    {.tag = OH_HUKS_TAG_ALGORITHM, .uint32Param = OH_HUKS_ALG_AES},
    {.tag = OH_HUKS_TAG_PURPOSE, .uint32Param = OH_HUKS_KEY_PURPOSE_ENCRYPT},
    {.tag = OH_HUKS_TAG_KEY_SIZE, .uint32Param = OH_HUKS_AES_KEY_SIZE_256},
    {.tag = OH_HUKS_TAG_PADDING, .uint32Param = OH_HUKS_PADDING_NONE},
    {.tag = OH_HUKS_TAG_BLOCK_MODE, .uint32Param = OH_HUKS_MODE_GCM},
    {.tag = OH_HUKS_TAG_DIGEST, .uint32Param = OH_HUKS_DIGEST_NONE},
    {.tag = OH_HUKS_TAG_ASSOCIATED_DATA,
     .blob = {.size = AAD_SIZE, .data = (uint8_t *)AAD}}, // 此处仅为测试数据，实际使用时该值应与调用者信息相关
    {.tag = OH_HUKS_TAG_NONCE,
     .blob = {.size = NONCE_SIZE, .data = (uint8_t *)NONCE}}}; // 此处仅为测试数据，实际使用时该值每次应该不同
static struct OH_Huks_Param g_importAgreeKeyParams[] = {
    {.tag = OH_HUKS_TAG_ALGORITHM, .uint32Param = OH_HUKS_ALG_AES},
    {.tag = OH_HUKS_TAG_PURPOSE, .uint32Param = OH_HUKS_KEY_PURPOSE_ENCRYPT},
    {.tag = OH_HUKS_TAG_KEY_SIZE, .uint32Param = OH_HUKS_AES_KEY_SIZE_256},
    {.tag = OH_HUKS_TAG_PADDING, .uint32Param = OH_HUKS_PADDING_NONE},
    {.tag = OH_HUKS_TAG_BLOCK_MODE, .uint32Param = OH_HUKS_MODE_GCM},
    {.tag = OH_HUKS_TAG_DIGEST, .uint32Param = OH_HUKS_DIGEST_NONE},
    {.tag = OH_HUKS_TAG_IV,
     .blob = {.size = IV_SIZE, .data = (uint8_t *)IV}}}; // 此处仅为测试数据，实际使用时该值每次应该不同
OH_Huks_Result HuksAgreeKey(const struct OH_Huks_ParamSet *paramSet, const struct OH_Huks_Blob *keyAlias,
                            const struct OH_Huks_Blob *peerPublicKey, struct OH_Huks_Blob *agreedKey) {
    uint8_t temp[10] = {0};
    struct OH_Huks_Blob inData = {sizeof(temp), temp};
    uint8_t handleU[sizeof(uint64_t)] = {0};
    struct OH_Huks_Blob handle = {sizeof(uint64_t), handleU};
    OH_Huks_Result ret = OH_Huks_InitSession(keyAlias, paramSet, &handle, nullptr);
    if (ret.errorCode != (int32_t)OH_HUKS_SUCCESS) {
        return ret;
    }
    uint8_t outDataU[1024] = {0};
    struct OH_Huks_Blob outDataUpdate = {1024, outDataU};
    ret = OH_Huks_UpdateSession(&handle, paramSet, peerPublicKey, &outDataUpdate);
    if (ret.errorCode != (int32_t)OH_HUKS_SUCCESS) {
        return ret;
    }
    ret = OH_Huks_FinishSession(&handle, paramSet, &inData, agreedKey);
    if (ret.errorCode != (int32_t)OH_HUKS_SUCCESS) {
        return ret;
    }
    return ret;
}
OH_Huks_Result MallocAndCheckBlobData(struct OH_Huks_Blob *blob, const uint32_t blobSize) {
    struct OH_Huks_Result ret;
    ret.errorCode = OH_HUKS_SUCCESS;
    blob->data = (uint8_t *)malloc(blobSize);
    if (blob->data == NULL) {
        ret.errorCode = OH_HUKS_ERR_CODE_INTERNAL_ERROR;
    }
    return ret;
}
static const uint32_t TIMES = 4;
static const uint32_t MAX_UPDATE_SIZE = 64;
static const uint32_t MAX_OUTDATA_SIZE = MAX_UPDATE_SIZE * TIMES;
#define HUKS_FREE_BLOB(blob)                                                                                           \
    do {                                                                                                               \
        if ((blob).data != nullptr) {                                                                                  \
            free((blob).data);                                                                                         \
            (blob).data = nullptr;                                                                                     \
        }                                                                                                              \
        (blob).size = 0;                                                                                               \
    } while (0)
#define OH_HUKS_KEY_BYTES(keySize) (((keySize) + 7) / 8)
static OH_Huks_Result HksEncryptLoopUpdate(const struct OH_Huks_Blob *handle, const struct OH_Huks_ParamSet *paramSet,
                                           const struct OH_Huks_Blob *inData, struct OH_Huks_Blob *outData) {
    struct OH_Huks_Result ret;
    ret.errorCode = OH_HUKS_SUCCESS;
    struct OH_Huks_Blob inDataSeg = *inData;
    uint8_t *lastPtr = inData->data + inData->size - 1;
    struct OH_Huks_Blob outDataSeg = {MAX_OUTDATA_SIZE, NULL};
    uint8_t *cur = outData->data;
    outData->size = 0;
    inDataSeg.size = MAX_UPDATE_SIZE;
    bool isFinished = false;
    while (inDataSeg.data <= lastPtr) {
        if (inDataSeg.data + MAX_UPDATE_SIZE <= lastPtr) {
            outDataSeg.size = MAX_OUTDATA_SIZE;
        } else {
            isFinished = true;
            inDataSeg.size = lastPtr - inDataSeg.data + 1;
            break;
        }
        if (MallocAndCheckBlobData(&outDataSeg, outDataSeg.size).errorCode != (int32_t)OH_HUKS_SUCCESS) {
            ret.errorCode = OH_HUKS_ERR_CODE_INTERNAL_ERROR;
            return ret;
        }
        ret = OH_Huks_UpdateSession(handle, paramSet, &inDataSeg, &outDataSeg);
        if (ret.errorCode != (int32_t)OH_HUKS_SUCCESS) {
            free(outDataSeg.data);
            return ret;
        }
        std::copy(outDataSeg.data, outDataSeg.data + outDataSeg.size, cur);
        cur += outDataSeg.size;
        outData->size += outDataSeg.size;
        free(outDataSeg.data);
        if ((isFinished == false) && (inDataSeg.data + MAX_UPDATE_SIZE > lastPtr)) {
            ret.errorCode = OH_HUKS_ERR_CODE_INTERNAL_ERROR;
            return ret;
        }
        inDataSeg.data += MAX_UPDATE_SIZE;
    }
    struct OH_Huks_Blob outDataFinish = {inDataSeg.size * TIMES, NULL};
    if (MallocAndCheckBlobData(&outDataFinish, outDataFinish.size).errorCode != (int32_t)OH_HUKS_SUCCESS) {
        ret.errorCode = OH_HUKS_ERR_CODE_INTERNAL_ERROR;
        return ret;
    }
    ret = OH_Huks_FinishSession(handle, paramSet, &inDataSeg, &outDataFinish);
    if (ret.errorCode != OH_HUKS_SUCCESS) {
        free(outDataFinish.data);
        return ret;
    }
    std::copy(outDataFinish.data, outDataFinish.data + outDataFinish.size, cur);
    outData->size += outDataFinish.size;
    free(outDataFinish.data);
    return ret;
}
OH_Huks_Result HuksEncrypt(const struct OH_Huks_Blob *key, const struct OH_Huks_ParamSet *paramSet,
                           const struct OH_Huks_Blob *plainText, struct OH_Huks_Blob *cipherText) {
    uint8_t handle[sizeof(uint64_t)] = {0};
    struct OH_Huks_Blob handleBlob = {sizeof(uint64_t), handle};
    OH_Huks_Result ret = OH_Huks_InitSession(key, paramSet, &handleBlob, nullptr);
    if (ret.errorCode != OH_HUKS_SUCCESS) {
        return ret;
    }
    ret = HksEncryptLoopUpdate(&handleBlob, paramSet, plainText, cipherText);
    return ret;
}
static OH_Huks_Result BuildWrappedKeyData(struct OH_Huks_Blob **blobArray, uint32_t size,
                                          struct OH_Huks_Blob *outData) {
    uint32_t totalLength = size * sizeof(uint32_t);
    struct OH_Huks_Result ret;
    ret.errorCode = OH_HUKS_SUCCESS;
    /* 计算大小 */
    for (uint32_t i = 0; i < size; ++i) {
        totalLength += blobArray[i]->size;
    }
    struct OH_Huks_Blob outBlob = {0, nullptr};
    outBlob.size = totalLength;
    ret = MallocAndCheckBlobData(&outBlob, outBlob.size);
    if (ret.errorCode != OH_HUKS_SUCCESS) {
        return ret;
    }
    uint32_t offset = 0;
    /* 拷贝数据 */
    for (uint32_t i = 0; i < size; ++i) {
        if (totalLength - offset >= sizeof(blobArray[i]->size)) {
            std::copy(reinterpret_cast<uint8_t *>(&blobArray[i]->size),
                      reinterpret_cast<uint8_t *>(&blobArray[i]->size) + sizeof(blobArray[i]->size),
                      outBlob.data + offset);
        } else {
            ret.errorCode = OH_HUKS_ERR_CODE_INTERNAL_ERROR;
            return ret;
        }
        offset += sizeof(blobArray[i]->size);
        if (totalLength - offset >= blobArray[i]->size) {
            std::copy(blobArray[i]->data, blobArray[i]->data + blobArray[i]->size, outBlob.data + offset);
        } else {
            ret.errorCode = OH_HUKS_ERR_CODE_INTERNAL_ERROR;
            return ret;
        }
        offset += blobArray[i]->size;
    }
    outData->size = outBlob.size;
    outData->data = outBlob.data;
    return ret;
}
static OH_Huks_Result CheckParamsValid(const struct HksImportWrappedKeyTestParams *params) {
    struct OH_Huks_Result ret;
    ret.errorCode = OH_HUKS_SUCCESS;
    if (params == nullptr) {
        ret.errorCode = OH_HUKS_ERR_CODE_ILLEGAL_ARGUMENT;
        return ret;
    }
    if (params->wrappingKeyAlias == nullptr || params->genWrappingKeyParamSet == nullptr ||
        params->callerKeyAlias == nullptr || params->genCallerKeyParamSet == nullptr ||
        params->callerKekAlias == nullptr || params->callerKek == nullptr ||
        params->importCallerKekParamSet == nullptr || params->callerAgreeKeyAlias == nullptr ||
        params->agreeParamSet == nullptr || params->importWrappedKeyParamSet == nullptr ||
        params->importedKeyAlias == nullptr || params->importedPlainKey == nullptr) {
        ret.errorCode = OH_HUKS_ERR_CODE_ILLEGAL_ARGUMENT;
        return ret;
    }
    return ret;
}
static OH_Huks_Result GenerateAndExportHuksPublicKey(const struct HksImportWrappedKeyTestParams *params,
                                                     struct OH_Huks_Blob *huksPublicKey) {
    OH_Huks_Result ret = OH_Huks_GenerateKeyItem(params->wrappingKeyAlias, params->genWrappingKeyParamSet, nullptr);
    if (ret.errorCode != (int32_t)OH_HUKS_SUCCESS) {
        return ret;
    }
    huksPublicKey->size = params->publicKeySize;
    ret = MallocAndCheckBlobData(huksPublicKey, huksPublicKey->size);
    if (ret.errorCode != (int32_t)OH_HUKS_SUCCESS) {
        return ret;
    }
    ret = OH_Huks_ExportPublicKeyItem(params->wrappingKeyAlias, nullptr, huksPublicKey);
    return ret;
}
static OH_Huks_Result GenerateAndExportCallerPublicKey(const struct HksImportWrappedKeyTestParams *params,
                                                       struct OH_Huks_Blob *callerSelfPublicKey) {
    OH_Huks_Result ret = OH_Huks_GenerateKeyItem(params->callerKeyAlias, params->genCallerKeyParamSet, nullptr);
    if (ret.errorCode != (int32_t)OH_HUKS_SUCCESS) {
        return ret;
    }
    callerSelfPublicKey->size = params->publicKeySize;
    ret = MallocAndCheckBlobData(callerSelfPublicKey, callerSelfPublicKey->size);
    if (ret.errorCode != (int32_t)OH_HUKS_SUCCESS) {
        return ret;
    }
    ret = OH_Huks_ExportPublicKeyItem(params->callerKeyAlias, params->genWrappingKeyParamSet, callerSelfPublicKey);
    return ret;
}
static OH_Huks_Result ImportKekAndAgreeSharedSecret(const struct HksImportWrappedKeyTestParams *params,
                                                    const struct OH_Huks_Blob *huksPublicKey,
                                                    struct OH_Huks_Blob *outSharedKey) {
    OH_Huks_Result ret =
        OH_Huks_ImportKeyItem(params->callerKekAlias, params->importCallerKekParamSet, params->callerKek);
    if (ret.errorCode != (int32_t)OH_HUKS_SUCCESS) {
        return ret;
    }
    ret = MallocAndCheckBlobData(outSharedKey, outSharedKey->size);
    if (ret.errorCode != (int32_t)OH_HUKS_SUCCESS) {
        return ret;
    }
    ret = HuksAgreeKey(params->agreeParamSet, params->callerKeyAlias, huksPublicKey, outSharedKey);
    if (ret.errorCode != (int32_t)OH_HUKS_SUCCESS) {
        return ret;
    }
    struct OH_Huks_ParamSet *importAgreeKeyParams = nullptr;
    ret = InitParamSet(&importAgreeKeyParams, g_importAgreeKeyParams,
                       sizeof(g_importAgreeKeyParams) / sizeof(OH_Huks_Param));
    if (ret.errorCode != (int32_t)OH_HUKS_SUCCESS) {
        return ret;
    }
    ret = OH_Huks_ImportKeyItem(params->callerAgreeKeyAlias, importAgreeKeyParams, outSharedKey);
    OH_Huks_FreeParamSet(&importAgreeKeyParams);
    return ret;
}
static OH_Huks_Result EncryptImportedPlainKeyAndKek(const struct HksImportWrappedKeyTestParams *params,
                                                    struct OH_Huks_Blob *plainCipherText,
                                                    struct OH_Huks_Blob *kekCipherText) {
    struct OH_Huks_ParamSet *encryptParamSet = nullptr;
    OH_Huks_Result ret =
        InitParamSet(&encryptParamSet, g_aesKekEncryptParams, sizeof(g_aesKekEncryptParams) / sizeof(OH_Huks_Param));
    if (ret.errorCode != (int32_t)OH_HUKS_SUCCESS) {
        return ret;
    }
    ret = HuksEncrypt(params->callerKekAlias, encryptParamSet, params->importedPlainKey, plainCipherText);
    if (ret.errorCode != (int32_t)OH_HUKS_SUCCESS) {
        return ret;
    }
    ret = HuksEncrypt(params->callerAgreeKeyAlias, encryptParamSet, params->callerKek, kekCipherText);
    OH_Huks_FreeParamSet(&encryptParamSet);
    return ret;
}
static OH_Huks_Result ImportWrappedKey(const struct HksImportWrappedKeyTestParams *params,
                                       struct OH_Huks_Blob *plainCipher, struct OH_Huks_Blob *kekCipherText,
                                       struct OH_Huks_Blob *peerPublicKey, struct OH_Huks_Blob *wrappedKeyData) {
    struct OH_Huks_Blob commonAad = {.size = AAD_SIZE, .data = reinterpret_cast<uint8_t *>(AAD)};
    struct OH_Huks_Blob commonNonce = {.size = NONCE_SIZE, .data = reinterpret_cast<uint8_t *>(NONCE)};
    struct OH_Huks_Blob keyMaterialLen = {.size = sizeof(uint32_t), .data = (uint8_t *)&params->keyMaterialLen};
    /* 从密文中拷贝AEAD的tag并缩小其大小 */
    const uint32_t tagSize = AEAD_TAG_SIZE;
    uint8_t kekTagBuf[tagSize] = {0};
    struct OH_Huks_Blob kekTag = {.size = tagSize, .data = kekTagBuf};
    std::copy(plainCipher->data + (plainCipher->size - tagSize),
              plainCipher->data + (plainCipher->size - tagSize) + tagSize, kekTag.data);
    plainCipher->size -= tagSize;
    /* 从密钥加密密钥的密文中拷贝AEAD的tag并缩小其大小 */
    uint8_t agreeKeyTagBuf[tagSize] = {0};
    struct OH_Huks_Blob agreeKeyTag = {.size = tagSize, .data = agreeKeyTagBuf};
    std::copy(kekCipherText->data + (kekCipherText->size - tagSize),
              kekCipherText->data + (kekCipherText->size - tagSize) + tagSize, agreeKeyTagBuf);
    kekCipherText->size -= tagSize;
    struct OH_Huks_Blob *blobArray[] = {peerPublicKey, &commonAad,   &commonNonce, &agreeKeyTag,    kekCipherText,
                                        &commonAad,    &commonNonce, &kekTag,      &keyMaterialLen, plainCipher};
    OH_Huks_Result ret = BuildWrappedKeyData(blobArray, OH_HUKS_IMPORT_WRAPPED_KEY_TOTAL_BLOBS, wrappedKeyData);
    if (ret.errorCode != (int32_t)OH_HUKS_SUCCESS) {
        return ret;
    }
    struct OH_Huks_Param *purpose = nullptr;
    ret = OH_Huks_GetParam(params->importWrappedKeyParamSet, OH_HUKS_TAG_PURPOSE, &purpose);
    if (ret.errorCode != (int32_t)OH_HUKS_SUCCESS) {
        return ret;
    }
    ret = OH_Huks_ImportWrappedKeyItem(params->importedKeyAlias, params->wrappingKeyAlias,
                                       params->importWrappedKeyParamSet, wrappedKeyData);
    return ret;
}
OH_Huks_Result HksImportWrappedKeyTestCommonCase(const struct HksImportWrappedKeyTestParams *params) {
    OH_Huks_Result ret = CheckParamsValid(params);
    if (ret.errorCode != (int32_t)OH_HUKS_SUCCESS) {
        return ret;
    }
    struct OH_Huks_Blob huksPublicKey = {0, nullptr};
    struct OH_Huks_Blob callerSelfPublicKey = {0, nullptr};
    struct OH_Huks_Blob outSharedKey = {.size = OH_HUKS_KEY_BYTES(OH_HUKS_AES_KEY_SIZE_256), .data = nullptr};
    struct OH_Huks_Blob wrappedKeyData = {0, nullptr};
    uint8_t plainKeyCipherBuffer[OH_HUKS_MAX_KEY_SIZE] = {0};
    struct OH_Huks_Blob plainCipherText = {OH_HUKS_MAX_KEY_SIZE, plainKeyCipherBuffer};
    uint8_t kekCipherTextBuffer[OH_HUKS_MAX_KEY_SIZE] = {0};
    struct OH_Huks_Blob kekCipherText = {OH_HUKS_MAX_KEY_SIZE, kekCipherTextBuffer};
    /* 模拟加密导入密钥场景，设备A为远端设备（导入设备），设备B为本端设备（被导入设备） */
    do {
        /**
         * 1.设备A将待导入密钥转换成HUKS密钥材料格式To_Import_Key（仅针对非对称密钥，若待导入密钥是对称密钥则可省略此步骤），
         *   本示例使用g_importedAes256PlainKey（对称密钥）作为模拟
         */
        /* 2.设备B生成一个加密导入用途的、用于协商的非对称密钥对Wrapping_Key（公钥Wrapping_Pk，私钥Wrapping_Sk），其密钥用途设置为unwrap，导出Wrapping_Key公钥Wrapping_Pk存放在变量huksPublicKey中
         */
        ret = GenerateAndExportHuksPublicKey(params, &huksPublicKey);
        if (ret.errorCode != (int32_t)OH_HUKS_SUCCESS) {
            break;
        }
        /* 3.设备A使用和设备B同样的算法，生成一个加密导入用途的、用于协商的非对称密钥对Caller_Key（公钥Caller_Pk，私钥Caller_Sk），导出Caller_Key公钥Caller_Pk存放在变量callerSelfPublicKey中
         */
        ret = GenerateAndExportCallerPublicKey(params, &callerSelfPublicKey);
        if (ret.errorCode != (int32_t)OH_HUKS_SUCCESS) {
            break;
        }
        /**
         * 4. 设备A生成一个对称密钥Caller_Kek，该密钥后续将用于加密To_Import_Key
         * 5. 设备A基于Caller_Key的私钥Caller_Sk和设备B Wrapping_Key的公钥Wrapping_Pk，协商出Shared_Key
         */
        ret = ImportKekAndAgreeSharedSecret(params, &huksPublicKey, &outSharedKey);
        if (ret.errorCode != (int32_t)OH_HUKS_SUCCESS) {
            break;
        }
        /**
         * 6. 设备A使用Caller_Kek加密To_Import_Key，生成To_Import_Key_Enc
         * 7. 设备A使用Shared_Key加密Caller_Kek，生成Caller_Kek_Enc
         */
        ret = EncryptImportedPlainKeyAndKek(params, &plainCipherText, &kekCipherText);
        if (ret.errorCode != (int32_t)OH_HUKS_SUCCESS) {
            break;
        }
        /* 8. 设备A封装Caller_Pk、To_Import_Key_Enc、Caller_Kek_Enc等加密导入的材料并发送给设备B。
         * 本示例作为变量存放在callerSelfPublicKey，plainCipherText，kekCipherText
         * 9. 设备B导入封装的加密密钥材料
         */
        ret = ImportWrappedKey(params, &plainCipherText, &kekCipherText, &callerSelfPublicKey, &wrappedKeyData);
    } while (0);
    /* 10. 设备A、B删除用于加密导入的密钥 */
    HUKS_FREE_BLOB(huksPublicKey);
    HUKS_FREE_BLOB(callerSelfPublicKey);
    HUKS_FREE_BLOB(outSharedKey);
    HUKS_FREE_BLOB(wrappedKeyData);
    return ret;
}
void HksClearKeysForWrappedKeyTest(const struct HksImportWrappedKeyTestParams *params) {
    OH_Huks_Result ret = CheckParamsValid(params);
    if (ret.errorCode != (int32_t)OH_HUKS_SUCCESS) {
        return;
    }
    (void)OH_Huks_DeleteKeyItem(params->wrappingKeyAlias, nullptr);
    (void)OH_Huks_DeleteKeyItem(params->callerKeyAlias, nullptr);
    (void)OH_Huks_DeleteKeyItem(params->callerKekAlias, nullptr);
    (void)OH_Huks_DeleteKeyItem(params->callerAgreeKeyAlias, nullptr);
    (void)OH_Huks_DeleteKeyItem(params->importedKeyAlias, nullptr);
}
static OH_Huks_Result InitCommonTestParamsAndDoImport(struct HksImportWrappedKeyTestParams *importWrappedKeyTestParams,
                                                      const struct OH_Huks_Param *importedKeyParamSetArray,
                                                      uint32_t arraySize) {
    struct OH_Huks_ParamSet *genX25519KeyParamSet = nullptr;
    struct OH_Huks_ParamSet *genCallerKeyParamSet = nullptr;
    struct OH_Huks_ParamSet *callerImportParamsKek = nullptr;
    struct OH_Huks_ParamSet *agreeParamSet = nullptr;
    struct OH_Huks_ParamSet *importPlainKeyParams = nullptr;
    OH_Huks_Result ret;
    do {
        ret = InitParamSet(&genX25519KeyParamSet, g_genWrappingKeyParams,
                           sizeof(g_genWrappingKeyParams) / sizeof(OH_Huks_Param));
        if (ret.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        importWrappedKeyTestParams->genWrappingKeyParamSet = genX25519KeyParamSet;
        importWrappedKeyTestParams->publicKeySize = g_x25519PubKeySize;
        ret = InitParamSet(&genCallerKeyParamSet, g_genCallerX25519Params,
                           sizeof(g_genCallerX25519Params) / sizeof(OH_Huks_Param));
        if (ret.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        importWrappedKeyTestParams->genCallerKeyParamSet = genCallerKeyParamSet;
        ret = InitParamSet(&callerImportParamsKek, g_importParamsCallerKek,
                           sizeof(g_importParamsCallerKek) / sizeof(OH_Huks_Param));
        if (ret.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        importWrappedKeyTestParams->importCallerKekParamSet = callerImportParamsKek;
        ret = InitParamSet(&agreeParamSet, g_callerAgreeParams, sizeof(g_callerAgreeParams) / sizeof(OH_Huks_Param));
        if (ret.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        importWrappedKeyTestParams->agreeParamSet = agreeParamSet;
        ret = InitParamSet(&importPlainKeyParams, importedKeyParamSetArray, arraySize);
        if (ret.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        importWrappedKeyTestParams->importWrappedKeyParamSet = importPlainKeyParams;
        ret = HksImportWrappedKeyTestCommonCase(importWrappedKeyTestParams);
    } while (0);
    OH_Huks_FreeParamSet(&genX25519KeyParamSet);
    OH_Huks_FreeParamSet(&genCallerKeyParamSet);
    OH_Huks_FreeParamSet(&callerImportParamsKek);
    OH_Huks_FreeParamSet(&agreeParamSet);
    OH_Huks_FreeParamSet(&importPlainKeyParams);
    return ret;
}
static napi_value ImportWrappedKey(napi_env env, napi_callback_info info) {
    struct HksImportWrappedKeyTestParams importWrappedKeyTestParams001 = {0};
    importWrappedKeyTestParams001.wrappingKeyAlias = &g_wrappingKeyAliasAes256;
    importWrappedKeyTestParams001.keyMaterialLen = g_importedAes256PlainKey.size;
    importWrappedKeyTestParams001.callerKeyAlias = &g_callerKeyAliasAes256;
    importWrappedKeyTestParams001.callerKekAlias = &g_callerKekAliasAes256;
    importWrappedKeyTestParams001.callerKek = &g_callerAes256Kek;
    importWrappedKeyTestParams001.callerAgreeKeyAlias = &g_callerAgreeKeyAliasAes256;
    importWrappedKeyTestParams001.importedKeyAlias = &g_importedKeyAliasAes256;
    importWrappedKeyTestParams001.importedPlainKey = &g_importedAes256PlainKey;
    OH_Huks_Result ohResult =
        InitCommonTestParamsAndDoImport(&importWrappedKeyTestParams001, g_importWrappedAes256Params,
                                        sizeof(g_importWrappedAes256Params) / sizeof(struct OH_Huks_Param));
    HksClearKeysForWrappedKeyTest(&importWrappedKeyTestParams001);
    napi_value ret;
    napi_create_int32(env, ohResult.errorCode, &ret);
    return ret;
}
```


## 调测验证

调用[OH_Huks_IsKeyItemExist](../../reference/apis-universal-keystore-kit/_huks_key_api.md#oh_huks_iskeyitemexist)验证密钥是否存在，如密钥存在即表示密钥导入成功。

```c++
#include "huks/native_huks_api.h"
#include "huks/native_huks_param.h"
#include "napi/native_api.h"
#include <string.h>
static napi_value IsKeyExist(napi_env env, napi_callback_info info)
{
    /* 1.指定密钥别名 */
    struct OH_Huks_Blob keyAlias = {
        (uint32_t)strlen("test_key"),
        (uint8_t *)"test_key"
    };
    
    /* 2.调用OH_Huks_IsKeyItemExist判断密钥是否存在  */
    struct OH_Huks_Result ohResult = OH_Huks_IsKeyItemExist(&keyAlias, NULL);
    if (ohResult.errorCode != OH_HUKS_SUCCESS) {
        // 失败 
    } else {
        // 成功
    }
}
```
