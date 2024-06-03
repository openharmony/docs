# 会话管理(C/C++)

DRM会话管理（MediaKeySession）支持MediaKeySession实例管理、许可证申请与处理等。

## 开发步骤

详细的API说明请参考[DRM API参考](../../reference/apis-drm-kit/_drm.md)。

1. 导入NDK接口，接口中提供了DRM相关的属性和方法，导入方法如下。

   ```c++
    #include "multimedia/drm_framework/interfaces/kits/c/drm_capi/common/native_drm_common.h"
    #include "multimedia/drm_framework/interfaces/kits/c/drm_capi/common/native_drm_err.h"
    #include "multimedia/drm_framework/interfaces/kits/c/drm_capi/include/native_mediakeysession.h"
    #include "multimedia/drm_framework/interfaces/kits/c/drm_capi/include/native_mediakeysystem.h"
   ```

2. 在CMake脚本中链接Drm NDK动态库。

   ```txt
    target_link_libraries(PUBLIC libnative_drm.so)
   ```

3. 调用MediaKeySession类中的OH_MediaKeySession_GenerateMediaKeyRequest方法生成许可证请求，MediaKeySession类中的OH_MediaKeySession_ProcessMediaKeyResponse方法进行响应处理。

   ```c++
    MediaKeySystem *keySystem = NULL;
    const char *name = "com.clearplay.drm";
    ret = OH_MediaKeySystem_Create(name, &keySystem);
    if (ret != DRM_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_Create failed.");
        return ret;
    }
    DRM_ContentProtectionLevel level = CONTENT_PROTECTION_LEVEL_HW_CRYPTO;
    MediaKeySession *keySession = NULL;
    ret = OH_MediaKeySystem_CreateMediaKeySession(keySystem, &level, &keySession);
    if (ret != DRM_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_CreateMediaKeySession failed.");
        return ret;
    }
    DRM_MediaKeyRequest mediaKeyRequest;
    DRM_MediaKeyRequestInfo info;
    uint8_t testData[MAX_INIT_DATA_LEN] = {0};
    memset(&info, 0, sizeof(DRM_MediaKeyRequestInfo));
    info.initDataLen = MAX_INIT_DATA_LEN;
    info.type = MEDIA_KEY_TYPE_ONLINE;
    memcpy(info.mimeType, (char *)"video/mp4", sizeof("video/mp4"));
    memcpy(info.initData, testData, sizeof(testData));
    memcpy(info.optionName[0], (char *)"optionalDataName", sizeof("optionalDataName"));
    memcpy(info.optionData[0], (char *)"optionalDataValue", sizeof("optionalDataValue"));
    info.optionsCount = 1;
    ret = OH_MediaKeySession_GenerateMediaKeyRequest(keySession,
        &info, &mediaKeyRequest);
    if (ret != DRM_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_MediaKeySession_GenerateMediaKeyRequest failed.");
        return ret;
    }
    uint8_t mediaKeyId[MAX_OFFLINE_MEDIA_KEY_ID_LEN];
    int32_t mediaKeyIdLen = MAX_OFFLINE_MEDIA_KEY_ID_LEN;
    uint8_t response[5] = {1, 2, 3, 4, 5};
    ret = OH_MediaKeySession_ProcessMediaKeyResponse(keySession,
        response, sizeof(response)/sizeof(uint8_t), mediaKeyId, &mediaKeyIdLen);
    if (ret != DRM_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_MediaKeySession_ProcessMediaKeyResponse failed.");
        return ret;
    }
    ret = OH_MediaKeySession_Destroy(keySession);
    if (ret != DRM_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_MediaKeySession_Destroy failed.");
        return ret;
    }
    ret = OH_MediaKeySystem_Destroy(keySystem);
    if (ret != DRM_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_Destroy failed.");
        return ret;
    }
   ```

4. 调用MediaKeySession类中的OH_MediaKeySession_CheckMediaKeyStatus方法查询许可证状态。

   ```c++
    MediaKeySystem *keySystem = NULL;
    const char *name = "com.clearplay.drm";
    ret = OH_MediaKeySystem_Create(name, &keySystem);
    if (ret != DRM_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_Create failed.");
        return ret;
    }
    DRM_ContentProtectionLevel level = CONTENT_PROTECTION_LEVEL_HW_CRYPTO;
    MediaKeySession *keySession = NULL;
    ret = OH_MediaKeySystem_CreateMediaKeySession(keySystem, &level, &keySession);
    if (ret != DRM_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_CreateMediaKeySession failed.");
        return ret;
    }
    DRM_MediaKeyStatus mediaKeyStatus;
    ret = OH_MediaKeySession_CheckMediaKeyStatus(keySession, &mediaKeyStatus);
    if (ret != DRM_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_MediaKeySession_CheckMediaKeyStatus failed.");
        return ret;
    }
    ret = OH_MediaKeySession_Destroy(keySession);
    if (ret != DRM_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_MediaKeySession_Destroy failed.");
        return ret;
    }
    ret = OH_MediaKeySystem_Destroy(keySystem);
    if (ret != DRM_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_Destroy failed.");
        return ret;
    }
   ```

5. 调用MediaKeySession类中的OH_MediaKeySession_ClearMediaKeys方法清理当前会话下所有许可证。

   ```c++
    MediaKeySystem *keySystem = NULL;
    const char *name = "com.clearplay.drm";
    ret = OH_MediaKeySystem_Create(name, &keySystem);
    if (ret != DRM_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_Create failed.");
        return ret;
    }
    DRM_ContentProtectionLevel level = CONTENT_PROTECTION_LEVEL_HW_CRYPTO;
    MediaKeySession *keySession = NULL;
    ret = OH_MediaKeySystem_CreateMediaKeySession(keySystem, &level, &keySession);
    if (ret != DRM_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_CreateMediaKeySession failed.");
        return ret;
    }
    ret = OH_MediaKeySession_ClearMediaKeys(keySession);
    if (ret != DRM_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_MediaKeySession_ClearMediaKeys failed.");
        return ret;
    }
    ret = OH_MediaKeySession_Destroy(keySession);
    if (ret != DRM_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_MediaKeySession_Destroy failed.");
        return ret;
    }
    ret = OH_MediaKeySystem_Destroy(keySystem);
    if (ret != DRM_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_Destroy failed.");
        return ret;
    }
   ```

6. 调用MediaKeySession类中的OH_MediaKeySession_GenerateOfflineReleaseRequest和OH_MediaKeySession_ProcessOfflineReleaseResponse方法生成离线许可证释放请求和处理离线许可证释放响应。

   ```c++
    MediaKeySystem *keySystem = NULL;
    const char *name = "com.clearplay.drm";
    ret = OH_MediaKeySystem_Create(name, &keySystem);
    if (ret != DRM_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_Create failed.");
        return ret;
    }
    DRM_ContentProtectionLevel level = CONTENT_PROTECTION_LEVEL_HW_CRYPTO;
    MediaKeySession *keySession = NULL;
    ret = OH_MediaKeySystem_CreateMediaKeySession(keySystem, &level, &keySession);
    if (ret != DRM_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_CreateMediaKeySession failed.");
        return ret;
    }
    uint8_t releaseRequest[MAX_MEDIA_KEY_REQUEST_DATA_LEN];
    int32_t releaseRequestLen = MAX_MEDIA_KEY_REQUEST_DATA_LEN;
    uint8_t mediaKeyId[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    int32_t mediaKeyIdLen = sizeof(mediaKeyId)/sizeof(uint8_t);
    ret = OH_MediaKeySession_GenerateOfflineReleaseRequest(keySession,
        mediaKeyId, mediaKeyIdLen, releaseRequest, &releaseRequestLen);
    if (ret != DRM_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_MediaKeySession_GenerateOfflineReleaseRequest failed.");
        return ret;
    }
    uint8_t keyReleaseResponse[128] = {0};
    int32_t keyReleaseResponseLen = sizeof(keyReleaseResponse)/sizeof(uint8_t);
    uint8_t offlineMediaKeyId[5] = {0};
    int32_t offlineMediaKeyIdLen = sizeof(offlineMediaKeyId)/sizeof(uint8_t);
    ret = OH_MediaKeySession_ProcessOfflineReleaseResponse(keySession, offlineMediaKeyId, offlineMediaKeyIdLen
        keyReleaseResponse, keyReleaseResponseLen);
    if (ret != DRM_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_MediaKeySession_ProcessOfflineReleaseResponse failed.");
        return ret;
    }
    ret = OH_MediaKeySession_Destroy(keySession);
    if (ret != DRM_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_MediaKeySession_Destroy failed.");
        return ret;
    }
    ret = OH_MediaKeySystem_Destroy(keySystem);
    if (ret != DRM_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_Destroy failed.");
        return ret;
    }
   ```

7. 调用MediaKeySession类中的OH_MediaKeySession_RestoreOfflineMediaKeys方法恢复离线许可证。

   ```c++
    MediaKeySystem *keySystem = NULL;
    const char *name = "com.clearplay.drm";
    ret = OH_MediaKeySystem_Create(name, &keySystem);
    if (ret != DRM_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_Create failed.");
        return ret;
    }
    DRM_ContentProtectionLevel level = CONTENT_PROTECTION_LEVEL_HW_CRYPTO;
    MediaKeySession *keySession = NULL;
    ret = OH_MediaKeySystem_CreateMediaKeySession(keySystem, &level, &keySession);
    if (ret != DRM_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_CreateMediaKeySession failed.");
        return ret;
    }
    uint8_t mediaKeyId[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    int32_t keyIdLen = sizeof(testRestoreId)/sizeof(uint8_t);
    ret = OH_MediaKeySession_RestoreOfflineMediaKeys(keySession, mediaKeyId, keyIdLen);
    if (ret != DRM_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_MediaKeySession_RestoreOfflineMediaKeys failed.");
        return ret;
    }
    ret = OH_MediaKeySession_Destroy(keySession);
    if (ret != DRM_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_MediaKeySession_Destroy failed.");
        return ret;
    }
    ret = OH_MediaKeySystem_Destroy(keySystem);
    if (ret != DRM_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_Destroy failed.");
        return ret;
    }
   ```

8. 调用MediaKeySession类中的OH_MediaKeySession_GetContentProtectionLevel方法获取当前会话的内容保护级别。

   ```c++
    MediaKeySystem *keySystem = NULL;
    const char *name = "com.clearplay.drm";
    ret = OH_MediaKeySystem_Create(name, &keySystem);
    if (ret != DRM_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_Create failed.");
        return ret;
    }
    DRM_ContentProtectionLevel level = CONTENT_PROTECTION_LEVEL_HW_CRYPTO;
    MediaKeySession *keySession = NULL;
    ret = OH_MediaKeySystem_CreateMediaKeySession(keySystem, &level, &keySession);
    if (ret != DRM_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_CreateMediaKeySession failed.");
        return ret;
    }
    DRM_ContentProtectionLevel sessionContentProtectionLevel;
    ret = OH_MediaKeySession_GetContentProtectionLevel(keySession,
        &sessionContentProtectionLevel);
    if (ret != DRM_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_MediaKeySession_GetContentProtectionLevel failed.");
        return ret;
    }
    ret = OH_MediaKeySession_Destroy(keySession);
    if (ret != DRM_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_MediaKeySession_Destroy failed.");
        return ret;
    }
    ret = OH_MediaKeySystem_Destroy(keySystem);
    if (ret != DRM_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_Destroy failed.");
        return ret;
    }
   ```

9. 调用MediaKeySession类中的OH_MediaKeySession_RequireSecureDecoderModule方法获取安全解码器状态。

   ```c++
    MediaKeySystem *keySystem = NULL;
    const char *name = "com.clearplay.drm";
    ret = OH_MediaKeySystem_Create(name, &keySystem);
    if (ret != DRM_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_Create failed.");
        return ret;
    }
    DRM_ContentProtectionLevel level = CONTENT_PROTECTION_LEVEL_HW_CRYPTO;
    MediaKeySession *keySession = NULL;
    ret = OH_MediaKeySystem_CreateMediaKeySession(keySystem, &level, &keySession);
    if (ret != DRM_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_CreateMediaKeySession failed.");
        return ret;
    }
    bool requireSecureDecoder;
    ret = OH_MediaKeySession_RequireSecureDecoderModule(keySession,
        "video/mp4", &requireSecureDecoder);
    if (ret != DRM_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_MediaKeySession_RequireSecureDecoderModule failed.");
        return ret;
    }
    ret = OH_MediaKeySession_Destroy(keySession);
    if (ret != DRM_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_MediaKeySession_Destroy failed.");
        return ret;
    }
    ret = OH_MediaKeySystem_Destroy(keySystem);
    if (ret != DRM_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_Destroy failed.");
        return ret;
    }
   ```

10. 调用MediaKeySession类中的OH_MediaKeySession_SetMediaKeySessionCallback方法设置MediaKeySystem监听回调。

    ```c++
    DRM_ErrCode TestSessoinEventCallBack(DRM_EventType  eventType, uint8_t *info,
    int32_t infoLen, char *extra)
    {
     return DRM_ERR_OK;
    }
    DRM_ErrCode TestSessoinKeyChangeCallBack(DRM_KeysInfo *keysInfo, bool newKeysAvailable)
    {
     return DRM_ERR_OK;
    }
    DRM_ErrCode MediaKeySession_SetMediaKeySessionCallback()
    {
     MediaKeySystem *keySystem = NULL;
     const char *name = "com.clearplay.drm";
     ret = OH_MediaKeySystem_Create(name, &keySystem);
     if (ret != DRM_OK) {
         OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_Create failed.");
         return ret;
     }
     DRM_ContentProtectionLevel level = CONTENT_PROTECTION_LEVEL_HW_CRYPTO;
     MediaKeySession *keySession = NULL;
     ret = OH_MediaKeySystem_CreateMediaKeySession(keySystem, &level, &keySession);
     if (ret != DRM_OK) {
         OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_CreateMediaKeySession failed.");
         return ret;
     }
     MediaKeySession_Callback sessionCallback = { TestSessoinEventCallBack, TestSessoinKeyChangeCallBack };
     ret = OH_MediaKeySession_SetMediaKeySessionCallback(keySession,
        &sessionCallback);
     if (ret != DRM_OK) {
         OH_LOG_ERROR(LOG_APP, "OH_MediaKeySession_SetMediaKeySessionCallback failed.");
         return ret;
     }
    }
    ```

11. 调用MediaKeySession类中的OH_MediaKeySession_SetCallback方法设置MediaKeySystem监听回调。

    ```c++
    DRM_ErrCode TestSessoinEventCallBackWithObj(MediaKeySession *mediaKeySessoin, DRM_EventType eventType,
    uint8_t *info, int32_t infoLen, char *extra)
    {
     return DRM_ERR_OK;
    }
    DRM_ErrCode TestSessoinKeyChangeCallBackWithObj(MediaKeySession *mediaKeySessoin, DRM_KeysInfo *keysInfo,
    bool hasNewGoodKeys)
    {
     return DRM_ERR_OK;
    }
    DRM_ErrCode MediaKeySession_SetMediaKeySessionCallbackWithObj()
    {
     MediaKeySystem *keySystem = NULL;
     const char *name = "com.clearplay.drm";
     ret = OH_MediaKeySystem_Create(name, &keySystem);
     if (ret != DRM_OK) {
         OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_Create failed.");
         return ret;
     }
     DRM_ContentProtectionLevel level = CONTENT_PROTECTION_LEVEL_HW_CRYPTO;
     MediaKeySession *keySession = NULL;
     ret = OH_MediaKeySystem_CreateMediaKeySession(keySystem, &level, &keySession);
     if (ret != DRM_OK) {
         OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_CreateMediaKeySession failed.");
         return ret;
     }
     OH_MediaKeySession_Callback sessionCallback = { TestSessoinEventCallBackWithObj, TestSessoinKeyChangeCallBackWithObj };
     ret = OH_MediaKeySession_SetCallback(keySession,
        &sessionCallback);
     if (ret != DRM_OK) {
         OH_LOG_ERROR(LOG_APP, "OH_MediaKeySession_SetCallback failed.");
         return ret;
     }
    }
    ```

12. 调用MediaKeySession类中的OH_MediaKeySession_Destroy方法销毁MediaKeySession实例。

    ```c++
    MediaKeySystem *keySystem = NULL;
    const char *name = "com.clearplay.drm";
    ret = OH_MediaKeySystem_Create(name, &keySystem);
    if (ret != DRM_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_Create failed.");
        return ret;
    }
    DRM_ContentProtectionLevel level = CONTENT_PROTECTION_LEVEL_HW_CRYPTO;
    MediaKeySession *keySession = NULL;
    ret = OH_MediaKeySystem_CreateMediaKeySession(keySystem, &level, &keySession);
    if (ret != DRM_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_CreateMediaKeySession failed.");
        return ret;
    }
    ret = OH_MediaKeySession_Destroy(keySession);
    if (ret != DRM_OK) {
      OH_LOG_ERROR(LOG_APP, "OH_MediaKeySession_Destroy failed.");
      return ret;
    }
    ret = OH_MediaKeySystem_Destroy(keySystem);
    if (ret != DRM_OK) {
      OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_Destroy failed.");
      return ret;
    }
    ```
