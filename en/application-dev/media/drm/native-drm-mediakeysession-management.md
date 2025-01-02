# DRM Media Key Session Management (C/C++)

The **MediaKeySystem** class of the DRM module supports media key management and media decryption. **MediaKeySession** instances are created and destroyed by **MediaKeySystem** instances.

## How to Develop

Read [DRM](../../reference/apis-drm-kit/_drm.md) for the API reference.

1. Import the NDK, which provides DRM-related attributes and methods.

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

3. Declare the MediaKeySystem event listener callback.

    ```c++
    // This callback applies to the scenario where there is only one MediaKeySystem instance.
    static Drm_ErrCode SessoinEventCallBack(DRM_EventType  eventType, uint8_t *info, int32_t infoLen, char *extra)
    {
        return DRM_ERR_OK;
    }

    static Drm_ErrCode SessoinKeyChangeCallBack(DRM_KeysInfo *keysInfo, bool newKeysAvailable)
    {
        return DRM_ERR_OK;
    }

    // This callback applies to the scenario where there are multiple MediaKeySystem instances.
    static Drm_ErrCode SessoinEventCallBackWithObj(MediaKeySession *mediaKeySessoin, DRM_EventType eventType, uint8_t *info, int32_t infoLen, char *extra)
    {
        return DRM_ERR_OK;
    }

    static Drm_ErrCode SessoinKeyChangeCallBackWithObj(MediaKeySession *mediaKeySessoin, DRM_KeysInfo *keysInfo, bool hasNewGoodKeys)
    {
        return DRM_ERR_OK;
    }
    ```

4. Set the MediaKeySystem event listener callback.

    ```c++
    // This callback applies to the scenario where there is only one MediaKeySystem instance.
    MediaKeySession_Callback sessionCallback = { SessoinEventCallBack, SessoinKeyChangeCallBack };
    Drm_ErrCode ret = OH_MediaKeySession_SetMediaKeySessionCallback(mediaKeySession, &sessionCallback);
    if (ret != DRM_ERR_OK) {
        printf("OH_MediaKeySession_SetMediaKeySessionCallback failed.");
    }

    // This callback applies to the scenario where there are multiple MediaKeySystem instances.
    OH_MediaKeySession_Callback sessionCallback = { SessoinEventCallBackWithObj, SessoinKeyChangeCallBackWithObj };
    ret = OH_MediaKeySession_SetCallback(mediaKeySession, &sessionCallback);
    if (ret != DRM_ERR_OK) {
        printf("OH_MediaKeySession_SetCallback failed.");
    }
    ```

5. Generate a media key request and process its response.

    ```c++
    DRM_MediaKeyRequest mediaKeyRequest;
    DRM_MediaKeyRequestInfo info;
    // initData corresponds to the PSSH data in the stream. Pass in the actual data.
    unsigned char initData[128] = {0x00};
    memset_s(&info, sizeof(DRM_MediaKeyRequestInfo), 0, sizeof(DRM_MediaKeyRequestInfo));
    info.initDataLen = sizeof(initData);
    info.type = MEDIA_KEY_TYPE_ONLINE;
    memcpy_s(info.mimeType, sizeof("video/avc"), (char *)"video/avc", sizeof("video/avc"));
    memcpy_s(info.initData, sizeof(initData), initData, sizeof(initData));
    memcpy_s(info.optionName[0], sizeof("optionalDataName"), (char *)"optionalDataName", sizeof("optionalDataName"));
    memcpy_s(info.optionData[0], sizeof("optionalDataValue"), (char *)"optionalDataValue", sizeof("optionalDataValue"));
    info.optionsCount = 1;
    ret = OH_MediaKeySession_GenerateMediaKeyRequest(mediaKeySession, &info, &mediaKeyRequest);
    if (ret != DRM_ERR_OK) {
        printf("OH_MediaKeySession_GenerateMediaKeyRequest failed.");
    }
    /* The composition of an offline media key ID varies according to the DRM scheme. You can obtain an ID in either of the following ways:
      1. The application calls OH_MediaKeySystem_GetOfflineMediaKeyIds to obtain the ID.
      2. The application requests the DRM service through the network, obtains a keySessionResponse, and sends the response to OH_MediaKeySession_ProcessMediaKeyResponse for parsing.
         An offline media key ID is obtained. The maximum length of a media key ID is 128. The following code is an example. Set the media key ID based on the actual media key data and length.
    */
    unsigned char mediaKeyId[26] = {0x00};
    int32_t mediaKeyIdLen = 26;
    // The maximum length of a media key response is 12288. Enter the actual length.
    unsigned char mediaKeyResponse[12288] = {0x00};
    int32_t mediaKeyResponseLen = 12288;
    ret = OH_MediaKeySession_ProcessMediaKeyResponse(mediaKeySession, mediaKeyResponse,
        mediaKeyResponseLen, mediaKeyId, &mediaKeyIdLen);
    if (ret != DRM_ERR_OK) {
        printf("OH_MediaKeySession_ProcessMediaKeyResponse failed.");
    }
    ```

6. (Optional) Check the media key status of the media key session.

    ```c++
    DRM_MediaKeyStatus mediaKeyStatus;
    ret = OH_MediaKeySession_CheckMediaKeyStatus(mediaKeySession, &mediaKeyStatus);
    if (ret != DRM_ERR_OK) {
        printf("OH_MediaKeySession_CheckMediaKeyStatus failed.");
    }
    ```

7. (Optional) Clear all media keys in the media key session.

    ```c++
    ret = OH_MediaKeySession_ClearMediaKeys(mediaKeySession);
    if (ret != DRM_ERR_OK) {
        printf("OH_MediaKeySession_ClearMediaKeys failed.");
    }
   ```

8. (Optional) Generate an offline media key release request and process its response.

    ```c++
    uint8_t releaseRequest[MAX_MEDIA_KEY_REQUEST_DATA_LEN];
    int32_t releaseRequestLen = MAX_MEDIA_KEY_REQUEST_DATA_LEN;
    ret = OH_MediaKeySession_GenerateOfflineReleaseRequest(mediaKeySession,
        mediaKeyId, mediaKeyIdLen, releaseRequest, &releaseRequestLen);
    if (ret != DRM_ERR_OK) {
        printf("OH_MediaKeySession_GenerateOfflineReleaseRequest failed.");
    }
    // keyReleaseResponse is obtained from the DRM service through the network request using the request body releaseRequest. Pass in the actual data obtained.
    unsigned char keyReleaseResponse[12288] = {0x00};
    int32_t keyReleaseResponseLen = 12288;
    ret = OH_MediaKeySession_ProcessOfflineReleaseResponse(mediaKeySession, mediaKeyId, mediaKeyIdLen,
       keyReleaseResponse, keyReleaseResponseLen);
    if (ret != DRM_ERR_OK) {
        printf("OH_MediaKeySession_ProcessOfflineReleaseResponse failed.");
    }
    ```

9. (Optional) Restore offline media keys.

    ```c++
    // Load the media key with the specified media key ID to the current session. The loaded media key can belong to the current session or another session.
    ret = OH_MediaKeySession_RestoreOfflineMediaKeys(mediaKeySession, mediaKeyId, mediaKeyIdLen);
    if (ret != DRM_ERR_OK) {
        printf("OH_MediaKeySession_RestoreOfflineMediaKeys failed.");
    }
   ```

10. (Optional) Call **OH_MediaKeySession_GetContentProtectionLevel** in the **MediaKeySession** class to obtain the content protection level of the current session.

    ```c++
    DRM_ContentProtectionLevel sessionContentProtectionLevel;
    ret = OH_MediaKeySession_GetContentProtectionLevel(mediaKeySession,
        &sessionContentProtectionLevel);
    if (ret != DRM_ERR_OK) {
        printf("OH_MediaKeySession_GetContentProtectionLevel failed.");
    }
    ```

11. (Optional) Check whether secure decoding is required.

    ```c++
    bool requireSecureDecoder;
    ret = OH_MediaKeySession_RequireSecureDecoderModule(mediaKeySession, "video/avc", &requireSecureDecoder);
    if (ret != DRM_ERR_OK) {
        printf("OH_MediaKeySession_RequireSecureDecoderModule failed.");
    }
    ```
