# DRM Media Key System Management (C/C++)

Using the **MediaKeySystem** class of the DRM module, you can manage **MediaKeySystem** instances, generate media key system requests to obtain DRM certificates, process responses to these requests, manage media key sessions, manage offline media keys, and obtain DRM statistics and device configuration information. Before using DRM Kit, check whether the device supports the DRM capabilities of a specific DRM scheme. In DRM Kit, the DRM scheme exists as a plug-in.

## How to Develop

Read [DRM](../../reference/apis-drm-kit/_drm.md) for the API reference.

1. Import the NDK.

   ```c++
    #include "multimedia/drm_framework/native_drm_common.h"
    #include "multimedia/drm_framework/native_drm_err.h"
    #include "multimedia/drm_framework/native_mediakeysession.h"
    #include "multimedia/drm_framework/native_mediakeysystem.h"
   ```

2. Link the DRM NDK dynamic library in the CMake script.

   ```txt
    target_link_libraries(PUBLIC libnative_drm.so)
   ```

3. Check whether the device supports the DRM scheme based on the specified name, MIME type, and content protection level.

   ```c++
    bool isSupported = OH_MediaKeySystem_IsSupported3("com.clearplay.drm", "video/avc", CONTENT_PROTECTION_LEVEL_SW_CRYPTO);
    if (isSupported != true) {
        printf("The device does not support the content protection level.");
    }
   ```

4. (Optional) Obtain the name and ID list of the DRM schemes supported by the device.

   ```c++
    uint32_t count = 1; // count indicates the number of DRM plug-ins supported by the device. Pass in the actual number.
    DRM_MediaKeySystemDescription descriptions[1];
    memset(descriptions, 0, sizeof(descriptions));
    Drm_ErrCode ret = OH_MediaKeySystem_GetMediaKeySystems(descriptions, &count);
    if (ret != DRM_ERR_OK) {
        printf("OH_MediaKeySystem_GetMediaKeySystems failed.");
    }
   ```

5. Create a **MediaKeySystem** instance.

   ```c++
    MediaKeySystem *mediaKeySystem = NULL;
    Drm_ErrCode ret = OH_MediaKeySystem_Create("com.clearplay.drm", &mediaKeySystem);
    if (ret != DRM_ERR_OK) {
        printf("OH_MediaKeySystem_Create failed.");
    }
   ```

6. (Optional) Declare the MediaKeySystem event listener callback.

   ```c++
     // This callback applies to the scenario where there are multiple MediaKeySystem instances.
    static Drm_ErrCode SystemCallBack(DRM_EventType eventType, uint8_t *info, int32_t infoLen, char *extra)
    {
        printf("SystemCallBack");
    }
    // This callback applies to the scenario where there is only one MediaKeySystem instance.
    static Drm_ErrCode SystemCallBackWithObj(MediaKeySystem *mediaKeySystem, DRM_EventType eventType,
    uint8_t *info, int32_t infoLen, char *extra)
    {
        printf("TestSystemCallBackWithObj");
    }
   ```

7. (Optional) Set the MediaKeySystem event listener callback.

   ```c++
     // This callback applies to the scenario where there are multiple MediaKeySystem instances.
    Drm_ErrCode ret = OH_MediaKeySystem_SetMediaKeySystemCallback(mediaKeySystem, SystemCallBack);
    if (ret != DRM_ERR_OK) {
        printf("OH_MediaKeySystem_SetMediaKeySystemCallback failed.");
    }

    // This callback applies to the scenario where there is only one MediaKeySystem instance.
    ret = OH_MediaKeySystem_SetCallback(mediaKeySystem, SystemCallBackWithObj);
    if (ret != DRM_ERR_OK) {
        printf("OH_MediaKeySystem_SetCallback failed.");
    }
   ```

8. Create a **MediaKeySession** instance.

   ```c++
    MediaKeySession *mediaKeySession = nullptr;
    DRM_ContentProtectionLevel contentProtectionLevel = CONTENT_PROTECTION_LEVEL_SW_CRYPTO;
    ret = OH_MediaKeySystem_CreateMediaKeySession(mediaKeySystem, &contentProtectionLevel, &mediaKeySession);
    if (ret != DRM_ERR_OK || mediaKeySession == nullptr) {
        printf("OH_MediaKeySystem_CreateMediaKeySession failed.");
    }
   ```

9. Check the DRM certificate status of the device. If the device does not have a DRM certificate or the DRM certificate status is abnormal, generate a provision request to obtain a DRM certificate and process its response.

   ```c++
    unsigned char request[12288] = { 0x00 };  // The maximum length of a provision request is 12288. Apply for memory based on the actual length.
    int32_t requestLen = 12288;
    // The maximum length of the DRM service URL is 2048.
    char defaultUrl[2048] = { 0x00 };
    int32_t defaultUrlLen = 2048;
    DRM_CertificateStatus certStatus = CERT_STATUS_INVALID;
    // Check the DRM certificate status of the device.
    ret = OH_MediaKeySystem_GetCertificateStatus(mediaKeySystem, &certStatus);
    if (ret == DRM_ERR_OK && certStatus == CERT_STATUS_NOT_PROVISIONED) {
        ret = OH_MediaKeySystem_GenerateKeySystemRequest(mediaKeySystem, request, &requestLen, defaultUrl,
            defaultUrlLen);
        /* 
          The application sends a provision request to the DRM service through a network request, obtains a response,
          and sets the response to the device. Pass in the actual value and length.
        */
        unsigned char KeySystemResponse[12288] = {0x00};
        ret = OH_MediaKeySystem_ProcessKeySystemResponse(mediaKeySystem, KeySystemResponse, sizeof(KeySystemResponse));
        if (ret != DRM_ERR_OK) {
            printf("OH_MediaKeySystem_ProcessKeySystemResponse failed.");
        }
    }
   ```

10. (Optional) Obtain the IDs of offline media keys, obtain their status, and clear the keys.

       ```c++
        DRM_OfflineMediakeyIdArray offlineMediaKeyIds;
        ret = OH_MediaKeySystem_GetOfflineMediaKeyIds(mediaKeySystem, &offlineMediaKeyIds);
        if (ret != DRM_ERR_OK) {
            printf("OH_MediaKeySystem_GetOfflineMediaKeyIds failed.");
        }
        DRM_OfflineMediaKeyStatus OfflineMediaKeyStatus = OFFLINE_MEDIA_KEY_STATUS_UNKNOWN;
        ret = OH_MediaKeySystem_GetOfflineMediaKeyStatus(mediaKeySystem, offlineMediaKeyIds.ids[0], offlineMediaKeyIds.idsLen[0], &OfflineMediaKeyStatus);
        if (ret != DRM_ERR_OK) {
            printf("OH_MediaKeySystem_GetOfflineMediaKeyStatus failed.");
        }
        ret = OH_MediaKeySystem_ClearOfflineMediaKeys(mediaKeySystem, offlineMediaKeyIds.ids[0], offlineMediaKeyIds.idsLen[0]);
        if (ret != DRM_ERR_OK) {
            printf("OH_MediaKeySystem_ClearOfflineMediaKeys failed.");
        }
       ```

11. (Optional) Set and obtain the DRM configuration information.

    > **NOTE**
    >
    > The configuration information may vary according to the DRM scheme. The supported configuration item names are "vendor", "version", "description", "algorithms", "maxSessionNum", and "currentHDCPLevel." The DRM configuration information can be set only when the scheme supports the setting of configuration items.
    
       ```c++
        ret = OH_MediaKeySystem_SetConfigurationString(mediaKeySystem, "version", "2.0"); // Set the configuration information of the string type.
        if (ret == DRM_ERR_OK) {
            printf("MediaKeySystem_SetConfigurationString success");
        } else {
            printf("MediaKeySystem_SetConfigurationString failed. %d ", ret);
        }
        char value[32];
        int32_t valueLen = 32;
        // Obtain the value of a configuration item in the form of a string.
        ret = OH_MediaKeySystem_GetConfigurationString(mediaKeySystem, "version", value, valueLen);
        if (ret == DRM_ERR_OK) {
            printf("OH_MediaKeySystem_GetConfigurationString success");
        } else {
            printf("OH_MediaKeySystem_GetConfigurationString failed. %d ", ret);
        }
        // Set the configuration information of the character array type based on the actual data and length.
        uint8_t description[4] = {0x00, 0x00, 0x00, 0x00};
        ret = OH_MediaKeySystem_SetConfigurationByteArray(mediaKeySystem, "description", description, sizeof(description)/sizeof(uint8_t));
        if (ret == DRM_ERR_OK) {
            printf("OH_MediaKeySystem_SetConfigurationByteArray success ");
        } else {
            printf("OH_MediaKeySystem_SetConfigurationByteArray failed. %d ", ret);
        }
         // Obtain the configuration information of the character array type. Pass in the actual data.
        uint8_t descriptionValue[32];
        int32_t descriptionValueLen = 32;
        ret = OH_MediaKeySystem_GetConfigurationByteArray(mediaKeySystem, "description", descriptionValue, &descriptionValueLen);
        if (ret == DRM_ERR_OK) {
            printf("OH_MediaKeySystem_GetConfigurationByteArray success ");
        } else {
            printf("OH_MediaKeySystem_GetConfigurationByteArray failed. %d ", ret);
        }
       ```
    
12. (Optional) Obtain the maximum content protection level supported by the device.

       ```c++
        DRM_ContentProtectionLevel contentProtectionLevel = CONTENT_PROTECTION_LEVEL_UNKNOWN;
        ret = OH_MediaKeySystem_GetMaxContentProtectionLevel(mediaKeySystem, &contentProtectionLevel);
        if (ret != DRM_ERR_OK) {
            printf("OH_MediaKeySystem_GetMaxContentProtectionLevel failed.");
        }
       ```

13. Destroy the **MediaKeySession** instance.

       ```c++
        ret = OH_MediaKeySession_Destroy(mediaKeySession);
        if (ret != DRM_ERR_OK) {
            printf("OH_MediaKeySession_Destroy failed.");
        }
       ```

14. Destroy the **MediaKeySystem** instance.

       ```c++
        ret = OH_MediaKeySystem_Destroy(mediaKeySystem);
        if (ret != DRM_ERR_OK) {
            printf("OH_MediaKeySystem_Destroy failed.");
        }
       ```