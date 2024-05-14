# 系统管理(C/C++)

DRM系统管理（MediaKeySystem）支持MediaKeySystem实例管理、设备证书申请与处理、会话创建、离线许可证管理、获取DRM度量统计信息、设备属性等。

## 开发步骤

详细的API说明请参考[DRM API参考](../../reference/apis-drm-kit/_drm.md)。

1. 导入NDK相关接口，导入方法如下。

   ```c++
    #include "multimedia/drm_framework/interfaces/kits/c/drm_capi/common/native_drm_common.h"
    #include "multimedia/drm_framework/interfaces/kits/c/drm_capi/common/native_drm_err.h"
    #include "multimedia/drm_framework/interfaces/kits/c/drm_capi/include/native_mediakeysession.h"
    #include "multimedia/drm_framework/interfaces/kits/c/drm_capi/include/native_mediakeysystem.h"
   ```

2. 在CMake脚本中链接Drm NDK动态库。

   ```txt
    target_link_libraries(PUBLIC libnative_drm.so)
   ```

3. 调用MediaKeySystem类中的OH_MediaKeySystem_IsSupported方法查询设备是否支持对应名称、对应媒体类型、安全保护级别的DRM方案。

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

4. 调用MediaKeySystem类中的OH_MediaKeySystem_GetMediaKeySystems方法获取设备支持对应的插件类型的name和uuid。

   ```c++
    // count 是当前设备实际支持的DRM插件的个数，用户根据实际情况设置
    uint32_t count = 1;
    DRM_MediaKeySystemDescription infos[1];
    memset(infos, 0, sizeof(infos));
    Drm_ErrCode ret = OH_MediaKeySystem_GetMediaKeySystems(infos, &count);
    if (ret != DRM_OK) {
     OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_GetMediaKeySystems failed.");
     return ret;
    }
   ```

5. 调用MediaKeySystem类中的OH_MediaKeySystem_Create方法创建MediaKeySystem实例。

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

6. 调用MediaKeySystem类中的OH_MediaKeySystem_SetConfigurationString和OH_MediaKeySystem_GetConfigurationString方法设置和获取设备的配置属性信息，不同的DRM方案的配置属性信息可能存在差别，一般分为三类：设备属性、会话属性、输出保护状态属性。

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
    ret = OH_MediaKeySystem_SetConfigurationString(keySystem, "version", "2.0");
    if (ret == DRM_OK) {
        OH_LOG_INFO(LOG_APP, "MediaKeySystem_SetConfigurationString success ");
    } else {
        OH_LOG_ERROR(LOG_APP, "MediaKeySystem_SetConfigurationString failed. %d ", ret);
    }
    char value[32];
    int32_t valueLen = 32;
     // 获取字符串类型的配置信息
    ret = OH_MediaKeySystem_GetConfigurationString(keySystem, "version", value, valueLen);
    if (ret == DRM_OK) {
        OH_LOG_INFO(LOG_APP, "OH_MediaKeySystem_GetConfigurationString success ");
    } else {
        OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_GetConfigurationString failed. %d ", ret);
    }
    // 设置字符数组类型的配置信息
    char description[5] = {1, 2, 3, 4, 5};
    ret = OH_MediaKeySystem_SetConfigurationByteArray(keySystem, "description", description, 5);
    if (ret == DRM_OK) {
        OH_LOG_INFO(LOG_APP, "OH_MediaKeySystem_SetConfigurationByteArray success ");
    } else {
        OH_LOG_ERROR(LOG_APP, "OH_MediaKeySystem_SetConfigurationByteArray failed. %d ", ret);
    }
     // 获取字符数组类型的配置信息
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

7. 调用MediaKeySystem类中的OH_MediaKeySystem_GetMaxContentProtectionLevel方法获取最大的内容保护级别。

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

8. 调用MediaKeySystem类中的OH_MediaKeySystem_SetMediaKeySystemCallback方法设置MediaKeySystem监听回调。

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

9. 调用MediaKeySystem类中的OH_MediaKeySystem_CreateMediaKeySession方法创建MediaKeySession会话实例。

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

10. 调用MediaKeySystem类中的OH_MediaKeySystem_GenerateKeySystemRequest方法生成设备证书请求，调用MediaKeySystem类中的OH_MediaKeySystem_ProcessKeySystemResponse方法生成设备证书响应。

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

11. 调用MediaKeySystem类中的OH_MediaKeySystem_GetOfflineMediaKeyIds方法获取离线许可证Id。

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

12. 调用MediaKeySystem类中的OH_MediaKeySystem_GetOfflineMediaKeyStatus方法获取对应离线许可证状态。

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

13. 调用MediaKeySystem类中的OH_MediaKeySystem_ClearOfflineMediaKeys方法清理离线许可证。

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

14. 调用MediaKeySystem类中的OH_MediaKeySystem_GetCertificateStatus方法获取设备证书状态。

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

15. 调用MediaKeySystem类中的OH_MediaKeySystem_Destroy方法销毁MediaKeySystem实例。

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
