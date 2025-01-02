# DRM系统管理(C/C++)

DRM系统管理（MediaKeySystem）支持MediaKeySystem实例管理、设备DRM证书申请与处理、会话实例管理、离线媒体密钥管理、获取DRM度量统计信息、设备属性等。在使用DRM Kit功能时，先查询设备是否支持对应DRM解决方案的DRM功能。在DRM Kit里DRM解决方案以插件形式存在，所以也叫DRM插件。

## 开发步骤

详细的API说明请参考[DRM API参考](../../reference/apis-drm-kit/_drm.md)。

1. 导入NDK相关接口，导入方法如下。

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

3. 查询设备是否支持对应DRM解决方案名称、媒体类型、安全保护级别的DRM解决方案。

   ```c++
    bool isSupported = OH_MediaKeySystem_IsSupported3("com.clearplay.drm", "video/avc", CONTENT_PROTECTION_LEVEL_SW_CRYPTO);
    if (isSupported != true) {
        printf("The device does not support the content protection level.");
    }
   ```

4.（可选）获取设备支持的DRM解决方案的名称和唯一标识的列表。

   ```c++
    uint32_t count = 1; // count是当前设备实际支持的DRM插件的个数，用户根据实际情况设置
    DRM_MediaKeySystemDescription descriptions[1];
    memset(descriptions, 0, sizeof(descriptions));
    Drm_ErrCode ret = OH_MediaKeySystem_GetMediaKeySystems(descriptions, &count);
    if (ret != DRM_ERR_OK) {
        printf("OH_MediaKeySystem_GetMediaKeySystems failed.");
    }
   ```

5. 创建MediaKeySystem实例。

   ```c++
    MediaKeySystem *mediaKeySystem = NULL;
    Drm_ErrCode ret = OH_MediaKeySystem_Create("com.clearplay.drm", &mediaKeySystem);
    if (ret != DRM_ERR_OK) {
        printf("OH_MediaKeySystem_Create failed.");
    }
   ```

6.（可选）声明MediaKeySystem事件监听回调。

   ```c++
     // 适用于多个MediaKeySystem实例的场景
    static Drm_ErrCode SystemCallBack(DRM_EventType eventType, uint8_t *info, int32_t infoLen, char *extra)
    {
        printf("SystemCallBack");
    }
    // 适用于单个MediaKeySystem实例的场景。
    static Drm_ErrCode SystemCallBackWithObj(MediaKeySystem *mediaKeySystem, DRM_EventType eventType,
    uint8_t *info, int32_t infoLen, char *extra)
    {
        printf("TestSystemCallBackWithObj");
    }
   ```

7.（可选）设置MediaKeySystem事件监听回调。

   ```c++
     // 适用于多个MediaKeySystem实例的场景
    Drm_ErrCode ret = OH_MediaKeySystem_SetMediaKeySystemCallback(mediaKeySystem, SystemCallBack);
    if (ret != DRM_ERR_OK) {
        printf("OH_MediaKeySystem_SetMediaKeySystemCallback failed.");
    }

    // 适用于单个MediaKeySystem实例的场景。
    ret = OH_MediaKeySystem_SetCallback(mediaKeySystem, SystemCallBackWithObj);
    if (ret != DRM_ERR_OK) {
        printf("OH_MediaKeySystem_SetCallback failed.");
    }
   ```

8. 创建MediaKeySession会话实例。

   ```c++
    MediaKeySession *mediaKeySession = nullptr;
    DRM_ContentProtectionLevel contentProtectionLevel = CONTENT_PROTECTION_LEVEL_SW_CRYPTO;
    ret = OH_MediaKeySystem_CreateMediaKeySession(mediaKeySystem, &contentProtectionLevel, &mediaKeySession);
    if (ret != DRM_ERR_OK || mediaKeySession == nullptr) {
        printf("OH_MediaKeySystem_CreateMediaKeySession failed.");
    }
   ```

9. 检查设备DRM证书状态，设备DRM证书不存在或状态异常，则生成设备DRM证书请求，处理设备DRM证书响应。

   ```c++
    unsigned char request[12288] = { 0x00 };  // 设备DRM证书request最大长度为12288，按实际大小申请
    int32_t requestLen = 12288;
    // DRM服务URL的最大长度为2048
    char defaultUrl[2048] = { 0x00 };
    int32_t defaultUrlLen = 2048;
    DRM_CertificateStatus certStatus = CERT_STATUS_INVALID;
    // 检查设备DRM证书状态
    ret = OH_MediaKeySystem_GetCertificateStatus(mediaKeySystem, &certStatus);
    if (ret == DRM_ERR_OK && certStatus == CERT_STATUS_NOT_PROVISIONED) {
        ret = OH_MediaKeySystem_GenerateKeySystemRequest(mediaKeySystem, request, &requestLen, defaultUrl,
            defaultUrlLen);
        /* 
          应用通过网络请求，将设备DRM证书请求信息传到DRM服务获取设备DRM证书请求响应keySystemResponse，
          再将设备DRM证书请求响应设置到设备上，请根据实际值和长度传入
        */
        unsigned char KeySystemResponse[12288] = {0x00};
        ret = OH_MediaKeySystem_ProcessKeySystemResponse(mediaKeySystem, KeySystemResponse, sizeof(KeySystemResponse));
        if (ret != DRM_ERR_OK) {
            printf("OH_MediaKeySystem_ProcessKeySystemResponse failed.");
        }
    }
   ```

10. (可选)获取离线媒体密钥标识，获取离线媒体密钥状态、清理离线媒体密钥。

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

11. (可选)设置和获取DRM配置属性信息。

   > **说明：**
   >
   > 不同的DRM方案的配置属性信息可能存在差别，支持的属性名包含："vendor"、"version"、"description"、"algorithms"、"maxSessionNum"、"currentHDCPLevel"。需解决方案支持属性值设置能力才能设置DRM配置属性信息。

   ```c++
    ret = OH_MediaKeySystem_SetConfigurationString(mediaKeySystem, "version", "2.0"); // 设置字符串类型的配置信息
    if (ret == DRM_ERR_OK) {
        printf("MediaKeySystem_SetConfigurationString success");
    } else {
        printf("MediaKeySystem_SetConfigurationString failed. %d ", ret);
    }
    char value[32];
    int32_t valueLen = 32;
    // 获取字符串类型的配置信息
    ret = OH_MediaKeySystem_GetConfigurationString(mediaKeySystem, "version", value, valueLen);
    if (ret == DRM_ERR_OK) {
        printf("OH_MediaKeySystem_GetConfigurationString success");
    } else {
        printf("OH_MediaKeySystem_GetConfigurationString failed. %d ", ret);
    }
    // 设置字符数组类型的配置信息，请根据实际数据和长度传入
    uint8_t description[4] = {0x00, 0x00, 0x00, 0x00};
    ret = OH_MediaKeySystem_SetConfigurationByteArray(mediaKeySystem, "description", description, sizeof(description)/sizeof(uint8_t));
    if (ret == DRM_ERR_OK) {
        printf("OH_MediaKeySystem_SetConfigurationByteArray success ");
    } else {
        printf("OH_MediaKeySystem_SetConfigurationByteArray failed. %d ", ret);
    }
     // 获取字符数组类型的配置信息，根据DRM解决方案实际情况填入
    uint8_t descriptionValue[32];
    int32_t descriptionValueLen = 32;
    ret = OH_MediaKeySystem_GetConfigurationByteArray(mediaKeySystem, "description", descriptionValue, &descriptionValueLen);
    if (ret == DRM_ERR_OK) {
        printf("OH_MediaKeySystem_GetConfigurationByteArray success ");
    } else {
        printf("OH_MediaKeySystem_GetConfigurationByteArray failed. %d ", ret);
    }
   ```

12. （可选）获取设备支持的最大内容保护级别。

   ```c++
    DRM_ContentProtectionLevel contentProtectionLevel = CONTENT_PROTECTION_LEVEL_UNKNOWN;
    ret = OH_MediaKeySystem_GetMaxContentProtectionLevel(mediaKeySystem, &contentProtectionLevel);
    if (ret != DRM_ERR_OK) {
        printf("OH_MediaKeySystem_GetMaxContentProtectionLevel failed.");
    }
   ```

13. 销毁MediaKeySession实例。

   ```c++
    ret = OH_MediaKeySession_Destroy(mediaKeySession);
    if (ret != DRM_ERR_OK) {
        printf("OH_MediaKeySession_Destroy failed.");
    }
   ```

14. 销毁MediaKeySystem实例。

   ```c++
    ret = OH_MediaKeySystem_Destroy(mediaKeySystem);
    if (ret != DRM_ERR_OK) {
        printf("OH_MediaKeySystem_Destroy failed.");
    }
   ```