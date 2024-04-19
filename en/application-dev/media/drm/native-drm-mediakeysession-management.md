# Media Key Session Management (C/C++)

Using the **MediaKeySession** class of the DRM module, you can manage **MediaKeySession** instances, generate media key requests, and process responses to these requests.

## How to Develop

Read [DRM](../../reference/apis-drm-kit/_drm.md) for the API reference.

1. Import the NDK, which provides DRM-related attributes and methods.

   ```c++
    #include "multimedia/drm_framework/interfaces/kits/c/drm_capi/common/native_drm_common.h"
    #include "multimedia/drm_framework/interfaces/kits/c/drm_capi/common/native_drm_err.h"
    #include "multimedia/drm_framework/interfaces/kits/c/drm_capi/include/native_mediakeysession.h"
    #include "multimedia/drm_framework/interfaces/kits/c/drm_capi/include/native_mediakeysystem.h"
   ```

2. Link the DRM NDK dynamic library in the CMake script.

   ```txt
    target_link_libraries(PUBLIC libnative_drm.so)
   ```

3. Call **OH_MediaKeySession_GenerateMediaKeyRequest** in the **MediaKeySession** class to generate a media key request, and call **OH_MediaKeySession_ProcessMediaKeyResponse** to process a response to the request.

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

4. Call **OH_MediaKeySession_CheckMediaKeyStatus** in the **MediaKeySession** class to check the media key status.

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

5. Call **OH_MediaKeySession_ClearMediaKeys** in the **MediaKeySession** class to clear all media keys of the current session.

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

6. Call **OH_MediaKeySession_GenerateOfflineReleaseRequest** in the **MediaKeySession** class to generate a request to release offline media keys, and call **OH_MediaKeySession_ProcessOfflineReleaseResponse** to process a response to the request.

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

7. Call **OH_MediaKeySession_RestoreOfflineMediaKeys** in the **MediaKeySession** class to restore the offline media keys.

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

8. Call **OH_MediaKeySession_GetContentProtectionLevel** in the **MediaKeySession** class to obtain the content protection level of the current session.

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

9. Call **OH_MediaKeySession_RequireSecureDecoderModule** in the **MediaKeySession** class to obtain the secure decoder status.

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

10. Call **OH_MediaKeySession_SetMediaKeySessionCallback** in the **MediaKeySession** class to set a callback to listen for the media key session status.

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

11. Call **OH_MediaKeySession_Destroy** in the **MediaKeySession** class to destroy this **MediaKeySession** instance.

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
