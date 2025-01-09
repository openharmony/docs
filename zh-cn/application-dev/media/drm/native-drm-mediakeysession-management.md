# DRM会话管理(C/C++)

DRM会话管理（MediaKeySession）支持媒体密钥管理及媒体解密等，MediaKeySession实例由系统管理里的MediaKeySystem实例创建和销毁。

## 开发步骤

详细的API说明请参考[DRM API参考](../../reference/apis-drm-kit/_drm.md)。

1. 导入NDK接口，接口中提供了DRM相关的属性和方法，导入方法如下。

   ```c++
    #include "multimedia/drm_framework/native_drm_common.h"
    #include "multimedia/drm_framework/native_drm_err.h"
    #include "multimedia/drm_framework/native_mediakeysession.h"
    #include "multimedia/drm_framework/native_mediakeysystem.h"
   ```

2. 在CMake脚本中链接Drm NDK动态库。

   ```txt
    target_link_libraries(PUBLIC libnative_drm.so)
   ```

3. 声明MediaKeySystem监听回调。

    ```c++
    // 适用于单个MediaKeySystem实例的场景。
    static Drm_ErrCode SessoinEventCallBack(DRM_EventType  eventType, uint8_t *info, int32_t infoLen, char *extra)
    {
        return DRM_ERR_OK;
    }

    static Drm_ErrCode SessoinKeyChangeCallBack(DRM_KeysInfo *keysInfo, bool newKeysAvailable)
    {
        return DRM_ERR_OK;
    }

    // 适用于多个MediaKeySystem实例的场景。
    static Drm_ErrCode SessoinEventCallBackWithObj(MediaKeySession *mediaKeySession, DRM_EventType eventType, uint8_t *info, int32_t infoLen, char *extra)
    {
        return DRM_ERR_OK;
    }

    static Drm_ErrCode SessoinKeyChangeCallBackWithObj(MediaKeySession *mediaKeySession, DRM_KeysInfo *keysInfo, bool hasNewGoodKeys)
    {
        return DRM_ERR_OK;
    }
    ```

4. 设置MediaKeySystem监听回调。

    ```c++
    // 适用于单个MediaKeySystem实例的场景。
    MediaKeySession_Callback sessionCallback = { SessoinEventCallBack, SessoinKeyChangeCallBack };
    Drm_ErrCode ret = OH_MediaKeySession_SetMediaKeySessionCallback(mediaKeySession, &sessionCallback);
    if (ret != DRM_ERR_OK) {
        printf("OH_MediaKeySession_SetMediaKeySessionCallback failed.");
    }

    // 适用于多个MediaKeySystem实例的场景。
    OH_MediaKeySession_Callback sessionCallback = { SessoinEventCallBackWithObj, SessoinKeyChangeCallBackWithObj };
    ret = OH_MediaKeySession_SetCallback(mediaKeySession, &sessionCallback);
    if (ret != DRM_ERR_OK) {
        printf("OH_MediaKeySession_SetCallback failed.");
    }
    ```

5. 生成媒体密钥请求，媒体密钥请求响应处理。

    ```c++
    DRM_MediaKeyRequest mediaKeyRequest;
    DRM_MediaKeyRequestInfo info;
    // initData对应码流中的pssh数据，请按实际数据填入
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
    /* 不同解决方案的离线媒体密钥标识组成不同，获取离线媒体密钥标识的方法有两种：
      1、应用调用OH_MediaKeySystem_GetOfflineMediaKeyIds接口获取离线媒体密钥标识；
      2、应用通过网络请求DRM服务，获取离线媒体密钥响应keySessionResponse，将响应传到OH_MediaKeySession_ProcessMediaKeyResponse解析
         出离线媒体密钥标识mediaKeyId；媒体密钥标识最大长度为128，如下代码所示，请根据实际的媒体密钥数据和长度传入；
    */
    unsigned char mediaKeyId[26] = {0x00};
    int32_t mediaKeyIdLen = 26;
    // 媒体密钥请求响应长度最大为12288，请按实际数据输入
    unsigned char mediaKeyResponse[12288] = {0x00};
    int32_t mediaKeyResponseLen = 12288;
    ret = OH_MediaKeySession_ProcessMediaKeyResponse(mediaKeySession, mediaKeyResponse,
        mediaKeyResponseLen, mediaKeyId, &mediaKeyIdLen);
    if (ret != DRM_ERR_OK) {
        printf("OH_MediaKeySession_ProcessMediaKeyResponse failed.");
    }
    ```

6. （可选）检查当前MediaKeySession会话的媒体密钥状态。

    ```c++
    DRM_MediaKeyStatus mediaKeyStatus;
    ret = OH_MediaKeySession_CheckMediaKeyStatus(mediaKeySession, &mediaKeyStatus);
    if (ret != DRM_ERR_OK) {
        printf("OH_MediaKeySession_CheckMediaKeyStatus failed.");
    }
    ```

7. （可选）清理当前会话下所有媒体密钥。

    ```c++
    ret = OH_MediaKeySession_ClearMediaKeys(mediaKeySession);
    if (ret != DRM_ERR_OK) {
        printf("OH_MediaKeySession_ClearMediaKeys failed.");
    }
   ```

8. （可选）生成离线媒体密钥释放请求和处理离线媒体密钥释放响应。

    ```c++
    uint8_t releaseRequest[MAX_MEDIA_KEY_REQUEST_DATA_LEN];
    int32_t releaseRequestLen = MAX_MEDIA_KEY_REQUEST_DATA_LEN;
    ret = OH_MediaKeySession_GenerateOfflineReleaseRequest(mediaKeySession,
        mediaKeyId, mediaKeyIdLen, releaseRequest, &releaseRequestLen);
    if (ret != DRM_ERR_OK) {
        printf("OH_MediaKeySession_GenerateOfflineReleaseRequest failed.");
    }
    // keyReleaseResponse是使用请求体releaseRequest通过网络请求从DRM服务获取的离线媒体密钥释放响应，请根据实际值传入
    unsigned char keyReleaseResponse[12288] = {0x00};
    int32_t keyReleaseResponseLen = 12288;
    ret = OH_MediaKeySession_ProcessOfflineReleaseResponse(mediaKeySession, mediaKeyId, mediaKeyIdLen,
       keyReleaseResponse, keyReleaseResponseLen);
    if (ret != DRM_ERR_OK) {
        printf("OH_MediaKeySession_ProcessOfflineReleaseResponse failed.");
    }
    ```

9. （可选）恢复离线媒体密钥到当前会话。

    ```c++
    // 将指定媒体密钥标识的媒体密钥加载到当前会话，被加载的媒体密钥可以是当前会话的也可以是其他会话的
    ret = OH_MediaKeySession_RestoreOfflineMediaKeys(mediaKeySession, mediaKeyId, mediaKeyIdLen);
    if (ret != DRM_ERR_OK) {
        printf("OH_MediaKeySession_RestoreOfflineMediaKeys failed.");
    }
   ```

10. （可选）调用MediaKeySession类中的OH_MediaKeySession_GetContentProtectionLevel方法获取当前会话的内容保护级别。

    ```c++
    DRM_ContentProtectionLevel sessionContentProtectionLevel;
    ret = OH_MediaKeySession_GetContentProtectionLevel(mediaKeySession,
        &sessionContentProtectionLevel);
    if (ret != DRM_ERR_OK) {
        printf("OH_MediaKeySession_GetContentProtectionLevel failed.");
    }
    ```

11. （可选）获取是否需要安全解码。

    ```c++
    bool requireSecureDecoder;
    ret = OH_MediaKeySession_RequireSecureDecoderModule(mediaKeySession, "video/avc", &requireSecureDecoder);
    if (ret != DRM_ERR_OK) {
        printf("OH_MediaKeySession_RequireSecureDecoderModule failed.");
    }
    ```