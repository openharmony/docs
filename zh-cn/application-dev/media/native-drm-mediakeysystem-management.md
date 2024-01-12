# DRM系统管理(C/C++)

DRM系统管理（MediaKeySession）支持MediaKeySystem实例管理、设备证书申请与处理、会话创建、离线许可证管理、获取DRM度量统计信息、设备属性等。

## 开发步骤

详细的API说明请参考[DRM API参考](../reference/native-apis/_o_h___drm.md)。

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

3. 调用MediaKeySession类中的OH_MediaKeySystem_GetMediaKeySystemName方法获取设备支持的MediaKeySystem名称。

   ```c++
    const uint8_t MAX_NAME_LEN = 16；
    const char *uuid = "com.wiseplay.drm";
    unsigned char name[][MAX_NAME_LEN];
    uint8_t nameLen = 0;
    ret = OH_MediaKeySystem_GetMediaKeySystemName(uuid, name, &nameLen);
    if (name == nullptr || ret != DRM_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_GetMediaKeySystemName failed.");
    }
   ```

4. 调用MediaKeySession类中的OH_MediaKeySystem_IsSupported方法查询设备是否支持对应名称、对应媒体类型、安全保护级别的DRM方案。

   ```c++
    const char *uuid = "com.wiseplay.drm";
    const char *mimeType = "video/mp4";
    DRM_ContentProtectionLevel securityLevel = CONTENT_PROTECTION_LEVEL_SW_CRYPTO;
    ret = OH_MediaKeySystem_IsSupported(uuid);
    if (ret != true) {
        OH_LOG_ERROR(LOG_APP, "The device does not support the DRM scheme.");
    }
    ret = OH_MediaKeySystem_IsSupported2(uuid, mimeType);
    if (ret != true) {
        OH_LOG_ERROR(LOG_APP, "The device does not support the DRM scheme.");
    }
    ret = OH_MediaKeySystem_IsSupported3(uuid, mimeType, securityLevel);
    if (ret != true) {
        OH_LOG_ERROR(LOG_APP, "The device does not support the DRM scheme.");
    }
   ```

5. 调用MediaKeySession类中的OH_MediaKeySystem_Create方法创建MediaKeySystem实例。

   ```c++
    MediaKeySystem *keySystem = NULL;
    const char *name = "com.wiseplay.drm";
    ret = OH_MediaKeySystem_Create(name, &keySystem);
    if (ret != DRM_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_Create failed.");
    }
   ```

6. 调用MediaKeySession类中的OH_MediaKeySystem_SetConfigurationString和OH_MediaKeySystem_GetConfigurationString方法设置和获取设备的配置属性信息，不同的DRM方案的配置属性信息可能存在差别，一般分为三类：设备属性、会话属性、输出保护状态属性。

   属性名一般包含："vendor"、"version"、"description"、"algorithms"、"maxSessionNum"、"maxHDCPLevel"、"currentHDCPLevel"、"maxADCPLevel"、"currentADCPLevel"等。

   ```c++
    // 创建MediaKeySystem实例
    MediaKeySystem *keySystem = NULL;
    const char *name = "com.wiseplay.drm";
    ret = OH_MediaKeySystem_Create(name, &keySystem);
    if (ret != DRM_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_Create failed.");
    }
    // 设置字符串类型的配置信息
    ret = MediaKeySystem_SetConfigurationString(System, "version", "2.0");
    if (ret == DRM_OK) {
        OH_LOG_INFO(LOG_APP, "MediaKeySystem_SetConfigurationString success ");
    } else {
        OH_LOG_ERROR(LOG_APP, "MediaKeySystem_SetConfigurationString failed. %d ", ret);
    }
     // 获取字符串类型的配置信息
    ret = OH_MediaKeySystem_GetConfigurationString(System, "version");
    if (ret == DRM_OK) {
        OH_LOG_INFO(LOG_APP, "OH_MediaKeySystem_GetConfigurationString success ");
    } else {
        OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_GetConfigurationString failed. %d ", ret);
    }
    // 设置字符数组类型的配置信息
    char description[5] = {1, 2, 3, 4, 5};
    ret = OH_MediaKeySystem_SetConfigurationByteArray(System, "description", description, 5);
    if (ret == DRM_OK) {
        OH_LOG_INFO(LOG_APP, "OH_MediaKeySystem_SetConfigurationByteArray success ");
    } else {
        OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_SetConfigurationByteArray failed. %d ", ret);
    }
     // 获取字符数组类型的配置信息
    unsigned char *descriptionValue = NULL;
    uint32_t descriptionValue = 0;
    ret = OH_MediaKeySystem_GetConfigurationByteArray(System, "description", &descriptionValue, &descriptionValue);
    if (ret == DRM_OK) {
        OH_LOG_INFO(LOG_APP, "OH_MediaKeySystem_GetConfigurationByteArray success ");
    } else {
        OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_GetConfigurationByteArray failed. %d ", ret);
    }
   ```

7. 调用MediaKeySession类中的OH_MediaKeySystem_GetMaxContentProtectionLevel方法获取最大的内容保护级别。

   ```c++
    MediaKeySystem *keySystem = NULL;
    const char *name = "com.wiseplay.drm";
    ret = OH_MediaKeySystem_Create(name, &keySystem);
    if (ret != DRM_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_Create failed.");
    }
    OH_DRM_ContentProtectionLevel contentProtectionLevel = CONTENT_PROTECTION_LEVEL_UNKNOWN;
    ret = OH_MediaKeySystem_GetMaxContentProtectionLevel(System, &contentProtectionLevel);
    if (ret != DRM_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_GetMaxContentProtectionLevel failed.");
    }
   ```

8. 调用MediaKeySession类中的OH_MediaKeySystem_SetMediaKeySystemCallback方法设置MediaKeySystem监听回调。

   ```c++
   OH_DrmErrCode TestSystemCallBack(OH_DRM_ListenerType eventType, OH_DRM_Uint8CharBufferPair *eventInfo)
   {
      OH_LOG_INFO(LOG_APP, "TestSystemCallBack");
   }
   OH_DrmErrCode MediaKeySystem_SetMediaKeySystemCallback()
   {
    MediaKeySystem *keySystem = NULL;
    const char *name = "com.wiseplay.drm";
    ret = OH_MediaKeySystem_Create(name, &keySystem);
    if (ret != DRM_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_Create failed.");
    }
    ret = OH_MediaKeySystem_SetMediaKeySystemCallback(System,
        TestSystemCallBack);
    if (ret != DRM_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_SetMediaKeySystemCallback failed.");
    }
    return ret;
   }
   ```

9. 调用MediaKeySession类中的OH_MediaKeySystem_CreateMediaKeySession方法创建MediaKeySession会话实例。

   ```c++
    MediaKeySystem *keySystem = NULL;
    const char *name = "com.wiseplay.drm";
    ret = OH_MediaKeySystem_Create(name, &keySystem);
    if (ret != DRM_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_Create failed.");
    }
    OH_DRM_ContentProtectionLevel level = CONTENT_PROTECTION_LEVEL_HW_CRYPTO;
    OH_MediaKeySession *Session = NULL;
    ret = OH_MediaKeySystem_CreateMediaKeySession(System, &level, &Session);
    if (ret != DRM_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_Create failed.");
    }
   ```

10. 调用MediaKeySession类中的OH_MediaKeySystem_GenerateKeySystemRequest方法生成设备证书请求，调用MediaKeySession类中的OH_MediaKeySystem_ProcessKeySystemResponse方法生成设备证书响应。

    ```c++
    OH_DrmErrCode MediaKeySystem_SetAndProcessMediaKeySystem()
    {
    unsigned char *request = NULL;
    int32_t requestLen;
    char *defaultUrl = NULL;
    int32_t defaultUrlLen;
    MediaKeySystem *keySystem = NULL;
    const char *name = "com.wiseplay.drm";
    ret = OH_MediaKeySystem_Create(name, &keySystem);
    if (ret != DRM_OK) {
      OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_Create failed.");
      return ret;
    }
    ret = OH_MediaKeySystem_GenerateKeySystemRequest(System, &request,
      &requestLen, &defaultUrl, &defaultUrlLen);
    if (ret != DRM_OK) {
      OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_GenerateKeySystemRequest failed.");
      return ret;
    }
    OH_DRM_Uint8Buffer keySystemResponse;
    unsigned char testKeySystemResponse[5] = {1, 2, 3, 4, 5};
    keySystemResponse.buffer = testKeySystemResponse;
    keySystemResponse.bufferLen = sizeof(testKeySystemResponse);
    ret = OH_MediaKeySystem_ProcessKeySystemResponse(System, keySystemResponse);
    if (ret != DRM_OK) {
      OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_GenerateKeySystemRequest failed.");
      free(request);
      free(defaultUrl);
      return ret;
    }
    free(request);
    free(defaultUrl);
    return ret;
    }
    ```

11. 调用MediaKeySession类中的OH_MediaKeySystem_GetOfflineMediaKeyIds方法获取离线许可证Id。

    ```c++
    MediaKeySystem *keySystem = NULL;
    const char *name = "com.wiseplay.drm";
    ret = OH_MediaKeySystem_Create(name, &keySystem);
    if (ret != DRM_OK) {
      OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_Create failed.");
      return ret;
    }
    int32_t mediaKeyIdsLen;
    OH_DRM_Uint8Buffer *mediaKeyIds = NULL;
    errNo = OH_MediaKeySystem_GetOfflineMediaKeyIds(System,
        &mediaKeyIds, &mediaKeyIdsLen);
    free(mediaKeyIds);
    ```

12. 调用MediaKeySession类中的OH_MediaKeySystem_GetOfflineMediaKeyStatus方法获取对应离线许可证状态。

    ```c++
    MediaKeySystem *keySystem = NULL;
    const char *name = "com.wiseplay.drm";
    ret = OH_MediaKeySystem_Create(name, &keySystem);
    if (ret != DRM_OK) {
      OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_Create failed.");
      return ret;
    }
    OH_DRM_OfflineMediaKeyStatus OfflineMediaKeyStatus = OFFLINE_MEDIA_KEY_STATUS_UNKNOWN;
    OH_DRM_Uint8Buffer mediaKeyIds;
    mediaKeyIds.buffer = mediaKeyId;
    mediaKeyIds.bufferLen = keyIdLen;
    ret = OH_MediaKeySystem_GetOfflineMediaKeyStatus(System, &mediaKeyIds, &OfflineMediaKeyStatus);
    if (ret != DRM_OK) {
      OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_GetOfflineMediaKeyStatus failed.");
      return ret;
    }
    ```

13. 调用MediaKeySession类中的OH_MediaKeySystem_ClearOfflineMediaKeys方法清理离线许可证。

    ```c++
    MediaKeySystem *keySystem = NULL;
    const char *name = "com.wiseplay.drm";
    ret = OH_MediaKeySystem_Create(name, &keySystem);
    if (ret != DRM_OK) {
      OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_Create failed.");
      return ret;
    }
    OH_DRM_Uint8Buffer mediaKeyIdToClear;
    unsigned char meidaKeyId[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    mediaKeyIdToClear.buffer = meidaKeyId;
    mediaKeyIdToClear.bufferLen = sizeof(meidaKeyId);
    ret = OH_MediaKeySystem_ClearOfflineMediaKeys(System,
        &mediaKeyIdToClear);
    if (ret != DRM_OK) {
      OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_ClearOfflineMediaKeys failed.");
      return ret;
    }
    ```

14. 调用MediaKeySession类中的OH_MediaKeySystem_GetCertificateStatus方法获取设备证书状态。

    ```c++
    MediaKeySystem *keySystem = NULL;
    const char *name = "com.wiseplay.drm";
    ret = OH_MediaKeySystem_Create(name, &keySystem);
    if (ret != DRM_OK) {
      OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_Create failed.");
      return ret;
    }
    OH_DRM_CertificateStatus certStatus;
    ret = OH_MediaKeySystem_GetCertificateStatus(mediaKeySystem,
        &certStatus);
    if (ret != DRM_OK) {
      OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_GetCertificateStatus failed.");
      return ret;
    }
    ```

15. 调用MediaKeySession类中的OH_MediaKeySystem_Destroy方法销毁MediaKeySystem实例。

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
