# 数字版权保护(C/C++)

## 功能介绍

开发者可以调用DRM Kit的C/C++接口实现DRM证书管理、DRM许可证管理、DRM节目授权、DRM节目解密等数字版权保护功能。

DRM Kit提供MediaKeySystem实现DRM证书管理、DRM许可证管理功能，并管理MediaKeySession实例；MediaKeySession实现DRM节目授权，并可支持Media Kit或AVCodec Kit实现DRM节目解密以实现DRM节目播放。

## 开发步骤

详细的API说明请参考[DRM API](../../reference/apis-drm-kit/_drm.md)。

1. 导入DRM Kit接口。

    ```c++
    #include "multimedia/drm_framework/native_drm_common.h"
    #include "multimedia/drm_framework/native_drm_err.h"
    #include "multimedia/drm_framework/native_mediakeysession.h"
    #include "multimedia/drm_framework/native_mediakeysystem.h"
    ```

2. 在CMake脚本中链接动态库。

    ```txt
    target_link_libraries(PUBLIC libnative_drm.so)
    ```

3. 获取设备支持的DRM解决方案名称和唯一标识的列表。

    ```c++
    uint32_t count = 3; // count是当前设备实际支持的DRM插件的个数，用户根据实际情况设置。
    DRM_MediaKeySystemDescription descriptions[3];
    memset(descriptions, 0, sizeof(descriptions));
    Drm_ErrCode ret = OH_MediaKeySystem_GetMediaKeySystems(descriptions, &count);
    if (ret != DRM_ERR_OK) {
        printf("OH_MediaKeySystem_GetMediaKeySystems failed.");
    }
    ```

4. （可选）查询设备是否支持对应DRM解决方案名称、媒体类型、安全保护级别的DRM解决方案。

    ```c++
    bool isSupported = OH_MediaKeySystem_IsSupported3("com.clearplay.drm", "video/mp4", CONTENT_PROTECTION_LEVEL_SW_CRYPTO);
    if (isSupported != true) {
        printf("The device does not support the content protection level.");
    }
    ```

5. 创建MediaKeySystem实例。

    ```c++
    MediaKeySystem *mediaKeySystem = nullptr;
    ret = OH_MediaKeySystem_Create("com.clearplay.drm", &mediaKeySystem);
    if (ret != DRM_ERR_OK || mediaKeySystem == nullptr) {
        printf("OH_MediaKeySystem_Create failed.");
    }
    ```

6. （可选）设置MediaKeySystem事件监听回调。

    ```c++
    static Drm_ErrCode SystemCallBackWithObj(MediaKeySystem *mediaKeySystem, DRM_EventType eventType,
        uint8_t *info, int32_t infoLen, char *extra)
    {
        printf("SystemCallBackWithObj enter");
        if (eventType == EVENT_PROVISION_REQUIRED) {
            // 设备DRM证书请求和处理。
        }
        return DRM_ERR_OK;
    }

    ret = OH_MediaKeySystem_SetCallback(mediaKeySystem, SystemCallBackWithObj);
    if (ret != DRM_ERR_OK) {
        printf("OH_MediaKeySystem_SetCallback failed.");
    }
    ```

7. （可选）获取设备DRM证书状态。

    ```c++
    DRM_CertificateStatus certStatus = CERT_STATUS_INVALID;
    // 检查设备DRM证书状态。
    ret = OH_MediaKeySystem_GetCertificateStatus(mediaKeySystem, &certStatus);
    if (ret == DRM_ERR_OK && certStatus != CERT_STATUS_PROVISIONED) {
        // 设备DRM证书请求和处理。
    }
    ```

8. （可选）生成设备DRM证书请求与处理设备DRM证书响应。

    ```c++
    #define MAX_DRM_PROVISION_BUF_SIZE 24576 // 24576: (2 * 12 * 1024)
    unsigned char request[MAX_DRM_PROVISION_BUF_SIZE] = { 0x00 };  // 设备DRM证书request最大长度为MAX_DRM_PROVISION_BUF_SIZE，按实际大小申请。
    int32_t requestLen = MAX_DRM_PROVISION_BUF_SIZE;
    // DRM服务URL的最大长度为2048。
    char defaultUrl[2048] = { 0x00 };
    int32_t defaultUrlLen = 2048;
    ret = OH_MediaKeySystem_GenerateKeySystemRequest(mediaKeySystem, request, &requestLen, defaultUrl,
        defaultUrlLen);
    if (ret != DRM_ERR_OK) {
        printf("OH_MediaKeySystem_GenerateKeySystemRequest failed.");
    }
    /* 
      应用通过网络请求，将设备DRM证书请求信息传到DRM服务获取设备DRM证书请求响应keySystemResponse，
      再将设备DRM证书请求响应设置到设备上，请根据实际的数据和长度传入。
    */
    unsigned char keySystemResponse[MAX_DRM_PROVISION_BUF_SIZE] = {0x00};
    ret = OH_MediaKeySystem_ProcessKeySystemResponse(mediaKeySystem, keySystemResponse, sizeof(keySystemResponse));
    if (ret != DRM_ERR_OK) {
        printf("OH_MediaKeySystem_ProcessKeySystemResponse failed.");
    }
    ```

9. （可选）获取设备支持的最大内容保护级别。

    ```c++
    DRM_ContentProtectionLevel maxContentProtectionLevel = CONTENT_PROTECTION_LEVEL_UNKNOWN;
    ret = OH_MediaKeySystem_GetMaxContentProtectionLevel(mediaKeySystem, &maxContentProtectionLevel);
    if (ret != DRM_ERR_OK) {
        printf("OH_MediaKeySystem_GetMaxContentProtectionLevel failed.");
    }
    ```

10. 创建MediaKeySession实例。

    ```c++
    MediaKeySession *mediaKeySession = nullptr;
    DRM_ContentProtectionLevel contentProtectionLevel = CONTENT_PROTECTION_LEVEL_SW_CRYPTO; // 依据设备支持的内容保护级别设置。
    ret = OH_MediaKeySystem_CreateMediaKeySession(mediaKeySystem, &contentProtectionLevel, &mediaKeySession);
    if (ret != DRM_ERR_OK || mediaKeySession == nullptr) {
        printf("OH_MediaKeySystem_CreateMediaKeySession failed.");
    }
    ```

11. （可选）设置MediaKeySession事件监听回调。

    ```c++
    static Drm_ErrCode SessionEventCallBackWithObj(MediaKeySession *mediaKeySession, DRM_EventType eventType, uint8_t *info, int32_t infoLen, char *extra)
    {
        if (eventType == EVENT_KEY_REQUIRED) {
            // 媒体密钥请求与处理。
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

12. （可选）查询是否需要安全解码。

    ```c++
    bool requireSecureDecoder;
    ret = OH_MediaKeySession_RequireSecureDecoderModule(mediaKeySession, "video/avc", &requireSecureDecoder);
    if (ret != DRM_ERR_OK) {
        printf("OH_MediaKeySession_RequireSecureDecoderModule failed.");
    }
    ```

13. 生成媒体密钥请求与处理媒体密钥响应，以请求许可证完成DRM节目授权。

    ```c++
    #define MAX_DRM_MEDIA_KEY_RESPONSE_BUF_SIZE 24576 // 24576: (2 * 12 * 1024)
    DRM_MediaKeyRequest mediaKeyRequest;
    DRM_MediaKeyRequestInfo info;
    // initData对应码流中的pssh数据，请按实际数据填入。
    unsigned char initData[512] = {0x00};
    memset(&info, 0, sizeof(DRM_MediaKeyRequestInfo));
    info.initDataLen = sizeof(initData);
    info.type = MEDIA_KEY_TYPE_ONLINE; // MEDIA_KEY_TYPE_ONLINE: 在线媒体密钥请求类型; MEDIA_KEY_TYPE_OFFLINE: 离线媒体密钥请求类型。 
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
      应用通过网络请求DRM服务，获取媒体密钥响应mediaKeyResponse，将响应传到OH_MediaKeySession_ProcessMediaKeyResponse，
      若是离线媒体密钥响应处理，则返回离线媒体密钥标识mediaKeyId，请根据实际的数据和长度传入。
    */
    unsigned char mediaKeyId[128] = {0x00};
    int32_t mediaKeyIdLen = 128;
    // 媒体密钥响应长度最大为MAX_DRM_MEDIA_KEY_RESPONSE_BUF_SIZE，请按实际数据输入。
    unsigned char mediaKeyResponse[MAX_DRM_MEDIA_KEY_RESPONSE_BUF_SIZE] = {0x00};
    int32_t mediaKeyResponseLen = MAX_DRM_MEDIA_KEY_RESPONSE_BUF_SIZE;
    ret = OH_MediaKeySession_ProcessMediaKeyResponse(mediaKeySession, mediaKeyResponse,
        mediaKeyResponseLen, mediaKeyId, &mediaKeyIdLen);
    if (ret != DRM_ERR_OK) {
        printf("OH_MediaKeySession_ProcessMediaKeyResponse failed.");
    }
    ```

14. （可选）恢复离线媒体密钥。

    ```c++
    // 将指定媒体密钥标识的媒体密钥加载到当前会话。
    ret = OH_MediaKeySession_RestoreOfflineMediaKeys(mediaKeySession, mediaKeyId, mediaKeyIdLen);
    if (ret != DRM_ERR_OK) {
        printf("OH_MediaKeySession_RestoreOfflineMediaKeys failed.");
    }
    ```

15. （可选）检查媒体密钥状态。

    ```c++
    DRM_MediaKeyStatus mediaKeyStatus;
    ret = OH_MediaKeySession_CheckMediaKeyStatus(mediaKeySession, &mediaKeyStatus);
    if (ret != DRM_ERR_OK) {
        printf("OH_MediaKeySession_CheckMediaKeyStatus failed.");
    }
    ```

16. （可选）获取离线媒体密钥标识列表、获取离线媒体密钥状态与清除离线媒体密钥。

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

17. 销毁MediaKeySession实例。

    ```c++
    ret = OH_MediaKeySession_Destroy(mediaKeySession);
    if (ret != DRM_ERR_OK) {
        printf("OH_MediaKeySession_Destroy failed.");
    }
    ```

18. 销毁MediaKeySystem实例。

    ```c++
    ret = OH_MediaKeySystem_Destroy(mediaKeySystem);
    if (ret != DRM_ERR_OK) {
        printf("OH_MediaKeySystem_Destroy failed.");
    }
    ```