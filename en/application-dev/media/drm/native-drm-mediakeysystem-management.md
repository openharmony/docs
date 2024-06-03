# Media Key System Management (C/C++)

Using the **MediaKeySystem** class of the DRM module, you can manage **MediaKeySystem** instances, generate media key system requests, process responses to these requests, create media key sessions, manage offline media keys, and obtain DRM statistics and device configuration information.

## How to Develop

Read [DRM](../../reference/apis-drm-kit/_drm.md) for the API reference.

1. Import the NDK.

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

3. Call **OH_MediaKeySystem_IsSupported** in the **MediaKeySystem** class to check whether the device supports the media key system with a given name, MIME type, and content protection level.

   ```c++
    const char *uuid = "com.wiseplay.drm";
    const char *mimeType = "video/mp4";
    DRM_ContentProtectionLevel level = CONTENT_PROTECTION_LEVEL_SW_CRYPTO;
    ret = OH_MediaKeySystem_IsSupported(uuid);
    if (ret != true) {
        OH_LOG_ERROR(LOG_APP, "The device does not support the DRM scheme.");
    }
    ret = OH_MediaKeySystem_IsSupported2(uuid, mimeType);
    if (ret != true) {
        OH_LOG_ERROR(LOG_APP, "The device does not support the DRM scheme.");
    }
    ret = OH_MediaKeySystem_IsSupported3(uuid, mimeType, level);
    if (ret != true) {
        OH_LOG_ERROR(LOG_APP, "The device does not support the DRM scheme.");
    }
   ```

4. Call **OH_MediaKeySystem_GetMediaKeySystems** in the **MediaKeySystem** class to obtain the names and UUIDs of the DRM plug-ins supported by the device.

   ```c++
    // count indicates the number of DRM plug-ins supported by the device. Set this parameter based on your project requirements.
    uint32_t count = 1;
    DRM_MediaKeySystemDescription infos[1];
    memset(infos, 0, sizeof(infos));
    Drm_ErrCode ret = OH_MediaKeySystem_GetMediaKeySystems(infos, &count);
    if (ret != DRM_OK) {
     OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_GetMediaKeySystems failed.");
     return ret;
    }
   ```

5. Call **OH_MediaKeySystem_Create** in the **MediaKeySystem** class to create a **MediaKeySystem** instance.

   ```c++
    MediaKeySystem *keySystem = NULL;
    const char *name = "com.wiseplay.drm";
    ret = OH_MediaKeySystem_Create(name, &keySystem);
    if (ret != DRM_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_Create failed.");
    }
    ret = OH_MediaKeySystem_Destroy(keySystem);
    if (ret != DRM_OK) {
     OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_Destroy failed.");
     return ret;
    }
   ```

6. Call **OH_MediaKeySystem_SetConfigurationString** and **OH_MediaKeySystem_GetConfigurationString** in the **MediaKeySystem** class to set and obtain the device configuration information, respectively. The configuration information varies according to the DRM scheme and generally contains the following types: device attributes, session attributes, and output protection status attributes.

   The attribute names include "vendor", "version", "description", "algorithms", "maxSessionNum", "maxHDCPLevel", "currentHDCPLevel", "maxADCPLevel", and "currentADCPLevel".

   ```c++
    // Create a MediaKeySystem instance.
    MediaKeySystem *keySystem = NULL;
    const char *name = "com.wiseplay.drm";
    ret = OH_MediaKeySystem_Create(name, &keySystem);
    if (ret != DRM_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_Create failed.");
    }
    // Set a configuration item in the form of a string.
    ret = OH_MediaKeySystem_SetConfigurationString(keySystem, "version", "2.0");
    if (ret == DRM_OK) {
        OH_LOG_INFO(LOG_APP, "MediaKeySystem_SetConfigurationString success ");
    } else {
        OH_LOG_ERROR(LOG_APP, "MediaKeySystem_SetConfigurationString failed. %d ", ret);
    }
    char value[32];
    int32_t valueLen = 32;
     // Obtain the value of a configuration item in the form of a string.
    ret = OH_MediaKeySystem_GetConfigurationString(keySystem, "version", value, valueLen);
    if (ret == DRM_OK) {
        OH_LOG_INFO(LOG_APP, "OH_MediaKeySystem_GetConfigurationString success ");
    } else {
        OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_GetConfigurationString failed. %d ", ret);
    }
    // Set a configuration item in the form of a byte array.
    char description[5] = {1, 2, 3, 4, 5};
    ret = OH_MediaKeySystem_SetConfigurationByteArray(keySystem, "description", description, 5);
    if (ret == DRM_OK) {
        OH_LOG_INFO(LOG_APP, "OH_MediaKeySystem_SetConfigurationByteArray success ");
    } else {
        OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_SetConfigurationByteArray failed. %d ", ret);
    }
     // Obtain the value of a configuration item in the form of a byte array.
    unsigned char descriptionValue[32];
    uint32_t descriptionValueLen = 32;
    ret = OH_MediaKeySystem_GetConfigurationByteArray(keySystem, "description", descriptionValue, &descriptionValueLen);
    if (ret == DRM_OK) {
        OH_LOG_INFO(LOG_APP, "OH_MediaKeySystem_GetConfigurationByteArray success ");
    } else {
        OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_GetConfigurationByteArray failed. %d ", ret);
    }
    ret = OH_MediaKeySystem_Destroy(keySystem);
    if (ret != DRM_OK) {
     OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_Destroy failed.");
     return ret;
    }
   ```

7. Call **OH_MediaKeySystem_GetMaxContentProtectionLevel** in the **MediaKeySystem** class to obtain the maximum content protection level.

   ```c++
    MediaKeySystem *keySystem = NULL;
    const char *name = "com.wiseplay.drm";
    ret = OH_MediaKeySystem_Create(name, &keySystem);
    if (ret != DRM_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_Create failed.");
    }
    DRM_ContentProtectionLevel contentProtectionLevel = CONTENT_PROTECTION_LEVEL_UNKNOWN;
    ret = OH_MediaKeySystem_GetMaxContentProtectionLevel(keySystem, &contentProtectionLevel);
    if (ret != DRM_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_GetMaxContentProtectionLevel failed.");
    }
    ret = OH_MediaKeySystem_Destroy(keySystem);
    if (ret != DRM_OK) {
     OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_Destroy failed.");
     return ret;
    }
   ```

8. Call **OH_MediaKeySystem_SetMediaKeySystemCallback** in the **MediaKeySystem** class to set a callback to listen for the media key system status.

   ```c++
    DRM_ErrCode TestSystemCallBack(DRM_EventType eventType, uint8_t *info,
        int32_t infoLen, char *extra)
    {
        OH_LOG_INFO(LOG_APP, "TestSystemCallBack");
    }
    DRM_ErrCode MediaKeySystem_SetMediaKeySystemCallback()
    {
    MediaKeySystem *keySystem = NULL;
    const char *name = "com.wiseplay.drm";
    ret = OH_MediaKeySystem_Create(name, &keySystem);
    if (ret != DRM_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_Create failed.");
    }
    ret = OH_MediaKeySystem_SetMediaKeySystemCallback(keySystem,
        TestSystemCallBack);
    if (ret != DRM_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_SetMediaKeySystemCallback failed.");
    }
    ret = OH_MediaKeySystem_Destroy(keySystem);
    if (ret != DRM_OK) {
     OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_Destroy failed.");
     return ret;
    }
    return ret;
   }
   ```

9. Call **OH_MediaKeySystem_CreateMediaKeySession** in the **MediaKeySystem** class to create a **MediaKeySession** instance.

   ```c++
    MediaKeySystem *keySystem = NULL;
    const char *name = "com.wiseplay.drm";
    ret = OH_MediaKeySystem_Create(name, &keySystem);
    if (ret != DRM_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_Create failed.");
    }
    DRM_ContentProtectionLevel level = CONTENT_PROTECTION_LEVEL_HW_CRYPTO;
    MediaKeySession *keySession = NULL;
    ret = OH_MediaKeySystem_CreateMediaKeySession(keySystem, &level, &keySession);
    if (ret != DRM_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_CreateMediaKeySession failed.");
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

10. Call **OH_MediaKeySystem_GenerateKeySystemRequest** in the **MediaKeySystem** class to generate a media key system request, and call **OH_MediaKeySystem_ProcessKeySystemResponse** in the **MediaKeySystem** class to process a response to the request.

    ```c++
    DRM_ErrCode MediaKeySystem_SetAndProcessMediaKeySystem()
    {
     unsigned char *request = NULL;
     int32_t requestLen;
     char defaultUrl[MAX_DEFAULT_URL_LEN];
     MediaKeySystem *keySystem = NULL;
     const char *name = "com.wiseplay.drm";
     ret = OH_MediaKeySystem_Create(name, &keySystem);
     if (ret != DRM_OK) {
       OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_Create failed.");
       return ret;
     }

     ret = OH_MediaKeySystem_GenerateKeySystemRequest(keySystem, &request,
      &requestLen, &defaultUrl, MAX_DEFAULT_URL_LEN);
     if (ret != DRM_OK) {
       OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_GenerateKeySystemRequest failed.");
       return ret;
     }
     unsigned char keySystemResponse[50] = {0};
     size_t keySystemResponseLen = sizeof(keySystemResponse);
     ret = OH_MediaKeySystem_ProcessKeySystemResponse(keySystem, keySystemResponse, keySystemResponseLen);
     if (ret != DRM_OK) {
       OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_GenerateKeySystemRequest failed.");
       return ret;
     }
     ret = OH_MediaKeySystem_Destroy(keySystem);
     if (ret != DRM_OK) {
       OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_Destroy failed.");
       return ret;
     }
     return ret;
    }
    ```

11. Call **OH_MediaKeySystem_GetOfflineMediaKeyIds** in the **MediaKeySystem** class to obtain the IDs of offline media keys.

    ```c++
    MediaKeySystem *keySystem = NULL;
    const char *name = "com.wiseplay.drm";
    ret = OH_MediaKeySystem_Create(name, &keySystem);
    if (ret != DRM_OK) {
      OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_Create failed.");
      return ret;
    }
    DRM_OfflineMediakeyIdArray offlineMediaKeyIds;
    ret = OH_MediaKeySystem_GetOfflineMediaKeyIds(keySystem, &offlineMediaKeyIds);
    ret = OH_MediaKeySystem_Destroy(keySystem);
    if (ret != DRM_OK) {
      OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_Destroy failed.");
      return ret;
    }
    ```

12. Call **OH_MediaKeySystem_GetOfflineMediaKeyStatus** in the **MediaKeySystem** class to obtain the status of the offline media keys.

    ```c++
    MediaKeySystem *keySystem = NULL;
    const char *name = "com.wiseplay.drm";
    ret = OH_MediaKeySystem_Create(name, &keySystem);
    if (ret != DRM_OK) {
      OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_Create failed.");
      return ret;
    }
    DRM_OfflineMediaKeyStatus OfflineMediaKeyStatus = OFFLINE_MEDIA_KEY_STATUS_UNKNOWN;
    uint8_t offlineMediaKeyId[16] = "mediaKeyIdTest01";
    ret = OH_MediaKeySystem_GetOfflineMediaKeyStatus(keySystem, offlineMediaKeyId, sizeof(offlineMediaKeyId)/sizeof(uint8_t), &OfflineMediaKeyStatus);
    if (ret != DRM_OK) {
      OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_GetOfflineMediaKeyStatus failed.");
      return ret;
    }
    ret = OH_MediaKeySystem_Destroy(keySystem);
    if (ret != DRM_OK) {
      OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_Destroy failed.");
      return ret;
    }
    ```

13. Call **OH_MediaKeySystem_ClearOfflineMediaKeys** in the **MediaKeySystem** class to clear the offline media keys.

    ```c++
    MediaKeySystem *keySystem = NULL;
    const char *name = "com.wiseplay.drm";
    ret = OH_MediaKeySystem_Create(name, &keySystem);
    if (ret != DRM_OK) {
      OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_Create failed.");
      return ret;
    }
    uint8_t meidaKeyId[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    ret = OH_MediaKeySystem_ClearOfflineMediaKeys(keySystem,
        meidaKeyId, sizeof(meidaKeyId)/sizeof(uint8_t));
    if (ret != DRM_OK) {
      OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_ClearOfflineMediaKeys failed.");
      return ret;
    }
    ret = OH_MediaKeySystem_Destroy(keySystem);
    if (ret != DRM_OK) {
      OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_Destroy failed.");
      return ret;
    }
    ```

14. Call **OH_MediaKeySystem_GetCertificateStatus** in the **MediaKeySystem** class to obtain the device certificate status.

    ```c++
    MediaKeySystem *keySystem = NULL;
    const char *name = "com.wiseplay.drm";
    ret = OH_MediaKeySystem_Create(name, &keySystem);
    if (ret != DRM_OK) {
      OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_Create failed.");
      return ret;
    }
    DRM_CertificateStatus certStatus = CERT_STATUS_INVALID;
    ret = OH_MediaKeySystem_GetCertificateStatus(mediaKeySystem,
        &certStatus);
    if (ret != DRM_OK) {
      OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_GetCertificateStatus failed.");
      return ret;
    }
    ret = OH_MediaKeySystem_Destroy(keySystem);
    if (ret != DRM_OK) {
      OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_Destroy failed.");
      return ret;
    }
    ```

15. Call **OH_MediaKeySystem_Destroy** in the **MediaKeySystem** class to destroy this **MediaKeySystem** instance.

    ```c++
    MediaKeySystem *keySystem = NULL;
    const char *name = "com.wiseplay.drm";
    ret = OH_MediaKeySystem_Create(name, &keySystem);
    if (ret != DRM_OK) {
      OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_Create failed.");
      return ret;
    }
    ret = OH_MediaKeySystem_Destroy(keySystem);
    if (ret != DRM_OK) {
      OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_Destroy failed.");
      return ret;
    }
    ```
