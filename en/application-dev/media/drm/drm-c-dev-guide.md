# DRM Development (C/C++)

## When to Use

You can call the C/C++ APIs of DRM Kit to implement digital copyright protection features such as DRM certificate management, DRM license management, DRM content authorization, and DRM content decryption.

DRM Kit provides MediaKeySystem to manage DRM certificates, DRM licenses, and MediaKeySession instances. MediaKeySession is responsible for authorizing DRM content and can work with Media Kit or AVCodec Kit to decrypt the DRM content, thereby enabling playback of DRM-protected content.

## How to Develop

Read [DRM](../../reference/apis-drm-kit/capi-drm.md) for the API reference.

1. Import the DRM Kit module.

    ```c++
    #include "multimedia/drm_framework/native_drm_common.h"
    #include "multimedia/drm_framework/native_drm_err.h"
    #include "multimedia/drm_framework/native_mediakeysession.h"
    #include "multimedia/drm_framework/native_mediakeysystem.h"
    ```

2. Link the dynamic libraries in the CMake script.

    ```txt
    target_link_libraries(PUBLIC libnative_drm.so)
    ```

3. Obtain the name and ID list of the DRM solutions supported by the device.

    ```c++
    uint32_t count = 3; // count indicates the number of DRM plugins supported by the device. Pass in the actual number.
    DRM_MediaKeySystemDescription descriptions[3];
    memset(descriptions, 0, sizeof(descriptions));
    Drm_ErrCode ret = OH_MediaKeySystem_GetMediaKeySystems(descriptions, &count);
    if (ret != DRM_ERR_OK) {
        printf("OH_MediaKeySystem_GetMediaKeySystems failed.");
    }
    ```

4. (Optional) Check whether the device supports the specified DRM solution based on the name, MIME type, and content protection level.

    ```c++
    bool isSupported = OH_MediaKeySystem_IsSupported3("com.clearplay.drm", "video/mp4", CONTENT_PROTECTION_LEVEL_SW_CRYPTO);
    if (isSupported != true) {
        printf("The device does not support the content protection level.");
    }
    ```

5. Create a MediaKeySystem instance.

    ```c++
    MediaKeySystem *mediaKeySystem = nullptr;
    ret = OH_MediaKeySystem_Create("com.clearplay.drm", &mediaKeySystem);
    if (ret != DRM_ERR_OK || mediaKeySystem == nullptr) {
        printf("OH_MediaKeySystem_Create failed.");
    }
    ```

6. (Optional) Set the MediaKeySystem event listener callback.

    ```c++
    static Drm_ErrCode SystemCallBackWithObj(MediaKeySystem *mediaKeySystem, DRM_EventType eventType,
        uint8_t *info, int32_t infoLen, char *extra)
    {
        printf("SystemCallBackWithObj enter");
        if (eventType == EVENT_PROVISION_REQUIRED) {
            // Request and process the DRM certificate.
        }
        return DRM_ERR_OK;
    }

    ret = OH_MediaKeySystem_SetCallback(mediaKeySystem, SystemCallBackWithObj);
    if (ret != DRM_ERR_OK) {
        printf("OH_MediaKeySystem_SetCallback failed.");
    }
    ```

7. (Optional) Obtain the status of the DRM certificate.

    ```c++
    DRM_CertificateStatus certStatus = CERT_STATUS_INVALID;
    // Check the DRM certificate status of the device.
    ret = OH_MediaKeySystem_GetCertificateStatus(mediaKeySystem, &certStatus);
    if (ret == DRM_ERR_OK && certStatus != CERT_STATUS_PROVISIONED) {
        // Request and process the DRM certificate.
    }
    ```

8. (Optional) Generate a DRM certificate request and process its response.

    ```c++
    #define MAX_DRM_PROVISION_BUF_SIZE 24576 // 24576: (2 * 12 * 1024)
    unsigned char request[MAX_DRM_PROVISION_BUF_SIZE] = { 0x00 };  // MAX_DRM_PROVISION_BUF_SIZE specifies the maximum length of a DRM certificate request. Apply for memory based on the actual length.
    int32_t requestLen = MAX_DRM_PROVISION_BUF_SIZE;
    // The maximum length of the DRM service URL is 2048.
    char defaultUrl[2048] = { 0x00 };
    int32_t defaultUrlLen = 2048;
    ret = OH_MediaKeySystem_GenerateKeySystemRequest(mediaKeySystem, request, &requestLen, defaultUrl,
        defaultUrlLen);
    if (ret != DRM_ERR_OK) {
        printf("OH_MediaKeySystem_GenerateKeySystemRequest failed.");
    }
    /* 
      The application sends a DRM certificate request to the DRM service through a network request, obtains a response,
      and sets the response to the device. Pass in the actual data and length.
    */
    unsigned char keySystemResponse[MAX_DRM_PROVISION_BUF_SIZE] = {0x00};
    ret = OH_MediaKeySystem_ProcessKeySystemResponse(mediaKeySystem, keySystemResponse, sizeof(keySystemResponse));
    if (ret != DRM_ERR_OK) {
        printf("OH_MediaKeySystem_ProcessKeySystemResponse failed.");
    }
    ```

9. (Optional) Obtain the maximum content protection level supported by the device.

    ```c++
    DRM_ContentProtectionLevel maxContentProtectionLevel = CONTENT_PROTECTION_LEVEL_UNKNOWN;
    ret = OH_MediaKeySystem_GetMaxContentProtectionLevel(mediaKeySystem, &maxContentProtectionLevel);
    if (ret != DRM_ERR_OK) {
        printf("OH_MediaKeySystem_GetMaxContentProtectionLevel failed.");
    }
    ```

10. Create a MediaKeySession instance.

    ```c++
    MediaKeySession *mediaKeySession = nullptr;
    DRM_ContentProtectionLevel contentProtectionLevel = CONTENT_PROTECTION_LEVEL_SW_CRYPTO; // Set the content protection level supported by the device.
    ret = OH_MediaKeySystem_CreateMediaKeySession(mediaKeySystem, &contentProtectionLevel, &mediaKeySession);
    if (ret != DRM_ERR_OK || mediaKeySession == nullptr) {
        printf("OH_MediaKeySystem_CreateMediaKeySession failed.");
    }
    ```

11. (Optional) Set the MediaKeySession event listener callback.

    ```c++
    static Drm_ErrCode SessionEventCallBackWithObj(MediaKeySession *mediaKeySession, DRM_EventType eventType, uint8_t *info, int32_t infoLen, char *extra)
    {
        if (eventType == EVENT_KEY_REQUIRED) {
            // Request and process the media key.
        }
        return DRM_ERR_OK;
    }

    static Drm_ErrCode SessionKeyChangeCallBackWithObj(MediaKeySession *mediaKeySession, DRM_KeysInfo *keysInfo, bool hasNewGoodKeys)
    {
        return DRM_ERR_OK;
    }

    OH_MediaKeySession_Callback sessionCallback = { SessionEventCallBackWithObj, SessionKeyChangeCallBackWithObj };
    ret = OH_MediaKeySession_SetCallback(mediaKeySession, &sessionCallback);
    if (ret != DRM_ERR_OK) {
        printf("OH_MediaKeySession_SetCallback failed.");
    }
    ```

12. (Optional) Check whether secure decoding is required.

    ```c++
    bool requireSecureDecoder;
    ret = OH_MediaKeySession_RequireSecureDecoderModule(mediaKeySession, "video/avc", &requireSecureDecoder);
    if (ret != DRM_ERR_OK) {
        printf("OH_MediaKeySession_RequireSecureDecoderModule failed.");
    }
    ```

13. Generate a media key request and process its response to request a license for DRM content authorization.

    ```c++
    #define MAX_DRM_MEDIA_KEY_RESPONSE_BUF_SIZE 24576 // 24576: (2 * 12 * 1024)
    DRM_MediaKeyRequest mediaKeyRequest;
    DRM_MediaKeyRequestInfo info;
    // initData corresponds to PSSH data in the stream. Pass in the actual data.
    unsigned char initData[512] = {0x00};
    memset(&info, 0, sizeof(DRM_MediaKeyRequestInfo));
    info.initDataLen = sizeof(initData);
    info.type = MEDIA_KEY_TYPE_ONLINE; // MEDIA_KEY_TYPE_ONLINE: online media key request; MEDIA_KEY_TYPE_OFFLINE: offline media key request.
    memcpy(info.mimeType, (char *)"video/mp4", sizeof("video/mp4"));
    memcpy(info.initData, initData, sizeof(initData));
    memcpy(info.optionName[0], (char *)"optionalDataName", sizeof("optionalDataName"));
    memcpy(info.optionData[0], (char *)"optionalDataValue", sizeof("optionalDataValue"));
    info.optionsCount = 1;
    ret = OH_MediaKeySession_GenerateMediaKeyRequest(mediaKeySession, &info, &mediaKeyRequest);
    if (ret != DRM_ERR_OK) {
        printf("OH_MediaKeySession_GenerateMediaKeyRequest failed.");
    }
    /*
      The application requests the DRM service through the network, obtains a media key response, and sends the response to OH_MediaKeySession_ProcessMediaKeyResponse.
      If the response is an offline media key response, the offline media key ID is returned. Set mediaKeyId based on the actual data and length.
    */
    unsigned char mediaKeyId[128] = {0x00};
    int32_t mediaKeyIdLen = 128;
    // MAX_DRM_MEDIA_KEY_RESPONSE_BUF_SIZE specifies the maximum length of a media key response. Pass in the actual length.
    unsigned char mediaKeyResponse[MAX_DRM_MEDIA_KEY_RESPONSE_BUF_SIZE] = {0x00};
    int32_t mediaKeyResponseLen = MAX_DRM_MEDIA_KEY_RESPONSE_BUF_SIZE;
    ret = OH_MediaKeySession_ProcessMediaKeyResponse(mediaKeySession, mediaKeyResponse,
        mediaKeyResponseLen, mediaKeyId, &mediaKeyIdLen);
    if (ret != DRM_ERR_OK) {
        printf("OH_MediaKeySession_ProcessMediaKeyResponse failed.");
    }
    ```

14. (Optional) Restore offline media keys.

    ```c++
    // Load the media key with the specified media key ID to the current session.
    ret = OH_MediaKeySession_RestoreOfflineMediaKeys(mediaKeySession, mediaKeyId, mediaKeyIdLen);
    if (ret != DRM_ERR_OK) {
        printf("OH_MediaKeySession_RestoreOfflineMediaKeys failed.");
    }
    ```

15. (Optional) Check the status of media keys.

    ```c++
    DRM_MediaKeyStatus mediaKeyStatus;
    ret = OH_MediaKeySession_CheckMediaKeyStatus(mediaKeySession, &mediaKeyStatus);
    if (ret != DRM_ERR_OK) {
        printf("OH_MediaKeySession_CheckMediaKeyStatus failed.");
    }
    ```

16. (Optional) Obtain the IDs of offline media keys, obtain their status, and clear the keys.

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

17. Destroy the MediaKeySession instance.

    ```c++
    ret = OH_MediaKeySession_Destroy(mediaKeySession);
    if (ret != DRM_ERR_OK) {
        printf("OH_MediaKeySession_Destroy failed.");
    }
    ```

18. Destroy the MediaKeySystem instance.

    ```c++
    ret = OH_MediaKeySystem_Destroy(mediaKeySystem);
    if (ret != DRM_ERR_OK) {
        printf("OH_MediaKeySystem_Destroy failed.");
    }
    ```
