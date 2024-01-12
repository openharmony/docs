# DRM会话管理(C/C++)

DRM会话管理（MediaKeySession）支持MediaKeySession实例管理、许可证申请与处理等。

## 开发步骤

详细的API说明请参考[DRM API参考](../reference/native-apis/_drm.md)。

1. 导入NDK接口，接口中提供了DRM相关的属性和方法，导入方法如下。

   ```c++
    // 导入NDK接口头文件
    #include "multimedia/drm_framework/native_drm_common.h"
    #include "multimedia/drm_framework/native_drm_err.h"
    #include "multimedia/drm_framework/native_mediakeysession.h"
    #include "multimedia/drm_framework/native_mediakeysystem.h"
   ```

2. 在CMake脚本中链接Drm NDK动态库。

   ```txt
    target_link_libraries(PUBLIC libnative_drm.so)
   ```

3. 调用MediaKeySession类中的OH_MediaKeySession_GenerateMediaKeyRequest方法生成许可证请求，MediaKeySession类中的OH_MediaKeySession_ProcessMediaKeyResponse方法进行响应处理。

   ```c++
    MediaKeySystem *keySystem = NULL;
    const char *name = "com.wiseplay.drm";
    ret = OH_MediaKeySystem_Create(name, &keySystem);
    if (ret != DRM_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_Create failed.");
        return ret;
    }
    OH_DRM_ContentProtectionLevel level = CONTENT_PROTECTION_LEVEL_HW_CRYPTO;
    OH_MediaKeySession *keySession = NULL;
    ret = OH_MediaKeySystem_CreateMediaKeySession(System, &level, &keySession);
    if (ret != DRM_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_CreateMediaKeySession failed.");
        return ret;
    }
    unsigned char *mediaKeyRequest = NULL;
    int32_t mediaKeyRequestLen;
    OH_DRM_MediaKeyRequestInfo info;
    unsigned char testData[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    info.type = MEDIA_KEY_TYPE_ONLINE;
    info.mimeType.buffer = "video/mp4";
    info.mimeType.bufferLen = strlen("video/mp4");
    info.data.buffer = testData;
    info.data.bufferLen = sizeof(testData);
    info.optionsCount = 0;
    info.optionsData = NULL;
    ret = OH_MediaKeySession_GenerateMediaKeyRequest(keySession,
        &info, &mediaKeyRequest, &mediaKeyRequestLen);
    if (ret != DRM_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_MediaKeySession_GenerateMediaKeyRequest failed.");
        return ret;
    }
    free(mediaKeyRequest);
    mediaKeyRequest = NULL；
    unsigned char *mediaKeyId = NULL;
    int32_t mediaKeyIdLen;
    OH_DRM_Uint8Buffer keySessoinResponse;
    unsigned char testKeySessionResponse[5] = {1, 2, 3, 4, 5};
    keySessoinResponse.buffer = testKeySessionResponse;
    keySessoinResponse.bufferLen = sizeof(testKeySessionResponse);
    ret = OH_MediaKeySession_ProcessMediaKeyResponse(mediaKeySession,
        &keySessoinResponse, &mediaKeyId, &mediaKeyIdLen);
    if (ret != DRM_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_MediaKeySession_ProcessMediaKeyResponse failed.");
        return ret;
    }
    free(mediaKeyId);
    mediaKeyId = NULL;
   ```

4. 调用MediaKeySession类中的OH_MediaKeySession_CheckMediaKeyStatus方法查询许可证状态。

   ```c++
    MediaKeySystem *keySystem = NULL;
    const char *name = "com.wiseplay.drm";
    ret = OH_MediaKeySystem_Create(name, &keySystem);
    if (ret != DRM_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_Create failed.");
        return ret;
    }
    OH_DRM_ContentProtectionLevel level = CONTENT_PROTECTION_LEVEL_HW_CRYPTO;
    OH_MediaKeySession *keySession = NULL;
    ret = OH_MediaKeySystem_CreateMediaKeySession(System, &level, &keySession);
    if (ret != DRM_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_CreateMediaKeySession failed.");
        return ret;
    }
    OH_DRM_MediaKeyDescription *mediaKeyDescription = NULL;
    ret = OH_MediaKeySession_CheckMediaKeyStatus(keySession, &mediaKeyDescription);
    if (ret != DRM_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_MediaKeySession_CheckMediaKeyStatus failed.");
        return ret;
    }
    free(mediaKeyDescription);
    mediaKeyDescription = NULL;
   ```

5. 调用MediaKeySession类中的OH_MediaKeySession_ClearMediaKeys方法清理当前会话下所有许可证。

   ```c++
    MediaKeySystem *keySystem = NULL;
    const char *name = "com.wiseplay.drm";
    ret = OH_MediaKeySystem_Create(name, &keySystem);
    if (ret != DRM_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_Create failed.");
        return ret;
    }
    OH_DRM_ContentProtectionLevel level = CONTENT_PROTECTION_LEVEL_HW_CRYPTO;
    OH_MediaKeySession *keySession = NULL;
    ret = OH_MediaKeySystem_CreateMediaKeySession(System, &level, &keySession);
    if (ret != DRM_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_CreateMediaKeySession failed.");
        return ret;
    }
    ret = OH_MediaKeySession_ClearMediaKeys(keySession);
    if (ret != DRM_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_MediaKeySession_ClearMediaKeys failed.");
        return ret;
    }
   ```

6. 调用MediaKeySession类中的OH_MediaKeySession_GenerateOfflineReleaseRequest和OH_MediaKeySession_ProcessOfflineReleaseResponse方法生成离线许可证释放请求和处理离线许可证释放响应。

   ```c++
    MediaKeySystem *keySystem = NULL;
    const char *name = "com.wiseplay.drm";
    ret = OH_MediaKeySystem_Create(name, &keySystem);
    if (ret != DRM_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_Create failed.");
        return ret;
    }
    OH_DRM_ContentProtectionLevel level = CONTENT_PROTECTION_LEVEL_HW_CRYPTO;
    OH_MediaKeySession *keySession = NULL;
    ret = OH_MediaKeySystem_CreateMediaKeySession(System, &level, &keySession);
    if (ret != DRM_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_CreateMediaKeySession failed.");
        return ret;
    }
    unsigned char *releaseRequest = NULL;
    int32_t releaseRequestLen;
    OH_DRM_Uint8Buffer mediaKeyIdToRelease;
    unsigned char testReleaseId[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    mediaKeyIdToRelease.buffer = testReleaseId;
    mediaKeyIdToRelease.bufferLen = sizeof(testReleaseId);
    ret = OH_MediaKeySession_GenerateOfflineReleaseRequest(keySession,
        &mediaKeyIdToRelease, &releaseRequest, &releaseRequestLen);
    if (ret != DRM_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_MediaKeySession_GenerateOfflineReleaseRequest failed.");
        return ret;
    }
    free(releaseRequest);
    releaseRequest = NULL;
    OH_DRM_Uint8Buffer keyReleaseResponse;
    unsigned char testKeyReleaseResponse[5] = {1, 2, 3, 4, 5};
    keyReleaseResponse.buffer = testKeyReleaseResponse;
    keyReleaseResponse.bufferLen = sizeof(testKeyReleaseResponse);
    ret = OH_MediaKeySession_ProcessOfflineReleaseResponse(mediaKeySession,
        &mediaKeyIdToRelease, &keyReleaseResponse);
    if (ret != DRM_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_MediaKeySession_ProcessOfflineReleaseResponse failed.");
        return ret;
    }
   ```

7. 调用MediaKeySession类中的OH_MediaKeySession_RestoreOfflineMediaKeys方法恢复离线许可证。

   ```c++
    MediaKeySystem *keySystem = NULL;
    const char *name = "com.wiseplay.drm";
    ret = OH_MediaKeySystem_Create(name, &keySystem);
    if (ret != DRM_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_Create failed.");
        return ret;
    }
    OH_DRM_ContentProtectionLevel level = CONTENT_PROTECTION_LEVEL_HW_CRYPTO;
    OH_MediaKeySession *keySession = NULL;
    ret = OH_MediaKeySystem_CreateMediaKeySession(System, &level, &keySession);
    if (ret != DRM_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_CreateMediaKeySession failed.");
        return ret;
    }
    OH_DRM_Uint8Buffer mediaKeyIdToRestore;
    unsigned char testRestoreId[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    mediaKeyIdToRestore.buffer = testRestoreId;
    mediaKeyIdToRestore.bufferLen = sizeof(testRestoreId);
    ret = OH_MediaKeySession_RestoreOfflineMediaKeys(mediaKeySession,
        &mediaKeyIdToRestore);
    if (ret != DRM_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_MediaKeySession_RestoreOfflineMediaKeys failed.");
        return ret;
    }
   ```

8. 调用MediaKeySession类中的OH_MediaKeySession_GetContentProtectionLevel方法获取当前会话的内容保护级别。

   ```c++
    MediaKeySystem *keySystem = NULL;
    const char *name = "com.wiseplay.drm";
    ret = OH_MediaKeySystem_Create(name, &keySystem);
    if (ret != DRM_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_Create failed.");
        return ret;
    }
    OH_DRM_ContentProtectionLevel level = CONTENT_PROTECTION_LEVEL_HW_CRYPTO;
    OH_MediaKeySession *keySession = NULL;
    ret = OH_MediaKeySystem_CreateMediaKeySession(System, &level, &keySession);
    if (ret != DRM_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_CreateMediaKeySession failed.");
        return ret;
    }
    OH_DRM_ContentProtectionLevel sessionContentProtectionLevel;
    ret = OH_MediaKeySession_GetContentProtectionLevel(keySession,
        &sessionContentProtectionLevel);
    if (ret != DRM_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_MediaKeySession_GetContentProtectionLevel failed.");
        return ret;
    }
   ```

9. 调用MediaKeySession类中的OH_MediaKeySession_RequireSecureDecoderModule方法获取安全解码器状态。

   ```c++
    MediaKeySystem *keySystem = NULL;
    const char *name = "com.wiseplay.drm";
    ret = OH_MediaKeySystem_Create(name, &keySystem);
    if (ret != DRM_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_Create failed.");
        return ret;
    }
    OH_DRM_ContentProtectionLevel level = CONTENT_PROTECTION_LEVEL_HW_CRYPTO;
    OH_MediaKeySession *keySession = NULL;
    ret = OH_MediaKeySystem_CreateMediaKeySession(System, &level, &keySession);
    if (ret != DRM_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_CreateMediaKeySession failed.");
        return ret;
    }
    bool requireSecureDecoder;
    ret = OH_MediaKeySession_RequireSecureDecoderModule(mediaKeySession,
        "video/mp4", &requireSecureDecoder);
    if (ret != DRM_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_MediaKeySession_RequireSecureDecoderModule failed.");
        return ret;
    }
   ```

10. 调用MediaKeySession类中的OH_MediaKeySession_SetMediaKeySessionCallback方法设置MediaKeySystem监听回调。

    ```c++
    OH_DrmErrCode TestSessoinEventCallBack(OH_DRM_ListenerType eventType, OH_DRM_Uint8CharBufferPair *eventInfo)
    {
     return DRM_ERR_OK;
    }
    OH_DrmErrCode TestSessoinKeyChangeCallBack(OH_DRM_KeysInfo *keysInfo, bool hasNewGoodKeys)
    {
     return DRM_ERR_OK;
    }
    OH_DrmErrCode MediaKeySession_SetMediaKeySessionCallback()
    {
     MediaKeySystem *keySystem = NULL;
     const char *name = "com.wiseplay.drm";
     ret = OH_MediaKeySystem_Create(name, &keySystem);
     if (ret != DRM_OK) {
         OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_Create failed.");
         return ret;
     }
     OH_DRM_ContentProtectionLevel level = CONTENT_PROTECTION_LEVEL_HW_CRYPTO;
     OH_MediaKeySession *keySession = NULL;
     ret = OH_MediaKeySystem_CreateMediaKeySession(System, &level, &keySession);
     if (ret != DRM_OK) {
         OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_CreateMediaKeySession failed.");
         return ret;
     }
     OH_MediaKeySessionCallback sessionCallback;
     sessionCallback.eventCallback = TestSessoinEventCallBack;
     sessionCallback.keyChangeCallback = TestSessoinKeyChangeCallBack;
     ret = OH_MediaKeySession_SetMediaKeySessionCallback(mediaKeySession,
        &sessionCallback);
     if (ret != DRM_OK) {
         OH_LOG_ERROR(LOG_APP, "OH_MediaKeySession_SetMediaKeySessionCallback failed.");
         return ret;
     }
    }
    ```

11. 调用MediaKeySession类中的OH_MediaKeySession_Destroy方法销毁MediaKeySession实例。

    ```c++
    MediaKeySystem *keySystem = NULL;
    const char *name = "com.wiseplay.drm";
    ret = OH_MediaKeySystem_Create(name, &keySystem);
    if (ret != DRM_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_Create failed.");
        return ret;
    }
    OH_DRM_ContentProtectionLevel level = CONTENT_PROTECTION_LEVEL_HW_CRYPTO;
    OH_MediaKeySession *keySession = NULL;
    ret = OH_MediaKeySystem_CreateMediaKeySession(System, &level, &keySession);
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
