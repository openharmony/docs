# DRM系统管理(ArkTS)

DRM系统管理（MediaKeySystem）支持MediaKeySystem实例管理、设备证书申请与处理、会话创建、离线许可证管理、获取DRM度量统计信息、设备属性等。

## 开发步骤

详细的API说明请参考[DRM API参考](../reference/apis/js-apis-drm.md)。

1. 导入相关接口，导入方法如下。

   ```ts
   import drm from '@ohos.multimedia.drm';
   ```

2. 调用MediaKeySyste类中的setConfigurationString(configName: string, value: string)方法，设置当前设备支持的字符串类型的属性值。接口调用失败时，会返回相应错误码，错误码类型参见[DrmErrorCode](../reference/apis/js-apis-drm.md#drmerrorcode)。

   ```ts
   function setConfigurationString(configName: string, value: string): void {
     let mediaKeysystem = drm.createMediaKeySystem("com.drm.clearplay");
     mediaKeysystem.setConfigurationString("configName", "configValue");
     return;
   }
   ```

3. 调用MediaKeySyste类中的getConfigurationString(configName: string)方法，获取字符串类型的设备相关设备属性。接口调用失败时，会返回相应错误码，错误码类型参见[DrmErrorCode](../reference/apis/js-apis-drm.md#drmerrorcode)。

   ```ts
   function getConfigurationString(configName: string): string {
     let mediaKeysystem = drm.createMediaKeySystem("com.drm.clearplay");
     mediaKeysystem.getConfigurationString("configName");
   }
   ```

4. 调用MediaKeySyste类中的setConfigurationByteArray(configName: string, value: Uint8Array)方法，设置当前设备支持的字符数组类型的属性值。接口调用失败时，会返回相应错误码，错误码类型参见[DrmErrorCode](../reference/apis/js-apis-drm.md#drmerrorcode)。

   ```ts
   function setConfigurationByteArray(configName: string, value: Uint8Array): void {
     let mediaKeysystem = drm.createMediaKeySystem("com.drm.clearplay");
     mediaKeysystem.setConfigurationByteArray("configName", "configValue");
     return;
   }
   ```

5. 调用MediaKeySyste类中的getConfigurationByteArray(configName: string): Uint8Array方法，获取字符数组类型的设备相关设备属性值。接口调用失败时，会返回相应错误码，错误码类型参见[DrmErrorCode](../reference/apis/js-apis-drm.md#drmerrorcode)。

   ```ts
   function getConfigurationByteArray(configName: string): Uint8Array {
     let mediaKeysystem = drm.createMediaKeySystem("com.drm.clearplay");
     mediaKeysystem.getConfigurationByteArray("configName");
   }
   ```

6. 调用MediaKeySyste类中的getMetrics(): MetricKeyValue[]方法，获取系统统计信息。其中包括当前会话数、插件版本信息、解密次数和解密失败次数。接口调用失败会返回相应错误码，错误码类型参见[DrmErrorCode](../reference/apis/js-apis-drm.md#drmerrorcode)。

   ```ts
   function getMetrics(): MetricKeyValue[] {
     let metricKeyValue = getMetrics();
     return metricKeyValue;
   }
   ```

7. 获取设备最大安全级别。

   调用MediaKeySyste类中的getMaxSecurityLevel(): SecurityLevel方法，获取设备支持的安全级别。接口调用失败会返回相应错误码，错误码类型参见[DrmErrorCode](../reference/apis/js-apis-drm.md#drmerrorcode)。

     ```ts
     function getMaxSecurityLevel(): SecurityLevel {
       let securityLevel = getMaxSecurityLevel();
       return securityLevel;
     }
     ```

8. 生成设备证书请求。

   调用MediaKeySyste类中的generateKeySystemRequest(): ProvisionRequest方法，获取设备证书请求。接口调用失败会返回相应错误码，错误码类型参见[DrmErrorCode](../reference/apis/js-apis-drm.md#drmerrorcode)。

     ```ts
     function generateKeySystemRequest(): ProvisionRequest {
       let provisionRequest = generateKeySystemRequest();
       return provisionRequest;
     }
     ```

9. 处理设备证书响应。

   调用MediaKeySyste类中的processKeySystemResponse(response: Uint8Array)方法，处理设备证书响应。接口调用失败会返回相应错误码，错误码类型参见[DrmErrorCode](../reference/apis/js-apis-drm.md#drmerrorcode)。

     ```ts
     function processKeySystemResponse(response: Uint8Array): void {
       processKeySystemResponse(response);
       return;
     }
     ```

10. 获取设备证书状态。

    调用MediaKeySyste类中的getCertificateStatus():CertificateStatus方法，获取设备证书状态。接口调用失败会返回相应错误码，错误码类型参见[DrmErrorCode](../reference/apis/js-apis-drm.md#drmerrorcode)。

      ```ts
      function getCertificateStatus():CertificateStatus {
        let certificateStatus = getCertificateStatus();
        return certificateStatus;
      }
      ```

11. 创建DRM会话。

    调用MediaKeySyste类中的createMediaKeySession(level: SecurityLevel): MediaKeySession方法，按指定安全级别进行创建会话。接口调用失败会返回相应错误码，错误码类型参见[DrmErrorCode](../reference/apis/js-apis-drm.md#drmerrorcode)。

      ```ts
      function createMediaKeySession(level: SecurityLevel): MediaKeySession {
        let mediaKeySession = createMediaKeySession(level);
        return mediaKeySession;
      }
      ```

12. 创建DRM会话。

    调用MediaKeySyste类中的createMediaKeySession(): MediaKeySession方法，创建会话。接口调用失败会返回相应错误码，错误码类型参见[DrmErrorCode](../reference/apis/js-apis-drm.md#drmerrorcode)。

      ```ts
      function createMediaKeySession(): MediaKeySession {
        let mediaKeySession = createMediaKeySession();
        return mediaKeySession;
      }
      ```

13. 获取离线许可证Id。

    调用MediaKeySyste类中的getOfflineLicenseIds(): Uint8Array[]方法，获取离线许可证Id。接口调用失败会返回相应错误码，错误码类型参见[DrmErrorCode](../reference/apis/js-apis-drm.md#drmerrorcode)。

      ```ts
      function getOfflineLicenseIds(): Uint8Array[] {
        let offlineLicenseIds = getOfflineLicenseIds();
        return offlineLicenseIds;
      }
      ```

14. 获取离线许可证状态。

    调用MediaKeySyste类中的getOfflineLicenseStatus(licenseId: Uint8Array): OfflineLicenseStatus方法，获取离线许可证状态。接口调用失败会返回相应错误码，错误码类型参见[DrmErrorCode](../reference/apis/js-apis-drm.md#drmerrorcode)。

      ```ts
      function getOfflineLicenseStatus(licenseId: Uint8Array): OfflineLicenseStatus {
        let offlineLicenseStatus = getOfflineLicenseStatus(licenseId);
        return offlineLicenseStatus;
      }
      ```

15. 移除离线许可证。

    调用MediaKeySyste类中的removeOfflineLicense(licenseId: Uint8Array): void方法，创建会话。接口调用失败会返回相应错误码，错误码类型参见[DrmErrorCode](../reference/apis/js-apis-drm.md#drmerrorcode)。

      ```ts
      function removeOfflineLicense(licenseId: Uint8Array): void {
        removeOfflineLicense(licenseId);
        return;
      }
      ```

16. 创建DRM会话。

    调用MediaKeySyste类中的createMediaKeySession(): MediaKeySession方法，创建会话。接口调用失败会返回相应错误码，错误码类型参见[DrmErrorCode](../reference/apis/js-apis-drm.md#drmerrorcode)。

      ```ts
      function createMediaKeySession(): MediaKeySession {
        let mediaKeySession = createMediaKeySession();
        return mediaKeySession;
      }
      ```

17. 销毁MediaKeySystem实例。

    调用MediaKeySyste类中的destroy(): void方法，销毁MediaKeySystem实例。接口调用失败会返回相应错误码，错误码类型参见[DrmErrorCode](../reference/apis/js-apis-drm.md#drmerrorcode)。

      ```ts
      function destroy(mediaKeySyste: MediaKeySyste): void {
        mediaKeySyste.destroy();
        return;
      }
      ```

18. 状态监听。

    在播放器应用开发过程中，可以随时监听MediaKeySystem信息状态，包括设备证书请求事件监听、会话丢失事件监听。

    - 通过注册固定的keySystemRequired回调函数获取监听设备证书请求，MediaKeySystem创建成功时即可监听，有该事件返回结果则认为设备证书请求开始，不需要监听的时候使用off进行注销监听。

      ```ts
      function onRegisterkeySystemRequired(mediaKeysystem: drm.MediaKeysystem): void {
        mediaKeysystem.on('keySystemRequired', (extra, data) => {
          console.log('keySystemRequired' + 'extra:' + extra + ' data:' +data);
        });
      }
      ```

      ```ts
      function unregisterkeySystemRequired(mediaKeysystem: drm.MediaKeysystem): void {
        mediaKeysystem.off('keySystemRequired');
      }
      ```

    - 通过注册固定的sessionLost回调函数获取监听会话丢失事件，MediaKeySystem创建成功时即可监听，不需要监听的时候使用off进行注销监听。

      ```ts
      function onRegisterSessionLost(mediaKeysystem: drm.MediaKeysystem): void {
        mediaKeysystem.on('sessionLost', (extra, data) => {
          console.log('sessionLost' + 'extra:' + extra + ' data:' +data);
        });
      }
      ```

      ```ts
      function unRegisterSessionLost(mediaKeysystem: drm.MediaKeysystem): void {
        mediaKeysystem.off('sessionLost');
      }
      ```
