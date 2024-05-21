# 系统管理(ArkTS)

DRM系统管理（MediaKeySystem）支持MediaKeySystem实例管理、设备证书申请与处理、会话创建、离线许可证管理、获取DRM度量统计信息、设备属性等。

## 开发步骤

详细的API说明请参考[DRM API参考](../../reference/apis-drm-kit/js-apis-drm.md)。

1. 导入相关接口，导入方法如下。

   ```ts
   import drm from '@ohos.multimedia.drm';
   ```

2. 导入BusinessError模块，用于获取drm模块相关接口抛出的错误码。

   ```ts
   import {BusinessError} from '@ohos.base';
   ```

3. 调用MediaKeySystem类中的setConfigurationString方法，设置当前设备支持的字符串类型的属性值。接口调用失败时，会返回相应错误码，错误码类型参见[DrmErrorCode](../../reference/apis-drm-kit/js-apis-drm.md#drmerrorcode)。

   ```ts
   function setConfigurationString(configName: string, value: string): void {
     let mediaKeysystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
     try {
       mediaKeysystem.setConfigurationString(configName, value);
    } catch (err) {
       let error = err as BusinessError;
       console.error(`setConfigurationString ERROR: ${error}`);
    }
     return ;
   }
   ```

4. 调用MediaKeySystem类中的getConfigurationString方法，获取字符串类型的设备相关设备属性。接口调用失败时，会返回相应错误码，错误码类型参见[DrmErrorCode](../../reference/apis-drm-kit/js-apis-drm.md#drmerrorcode)。

   ```ts
   function getConfigurationString(configName: string): string | undefined {
     let mediaKeysystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
     let configValue: string | undefined = undefined;
     try {
       configValue = mediaKeysystem.getConfigurationString(configName);
     } catch (err) {
       let error = err as BusinessError;
       console.error(`getConfigurationString ERROR: ${error}`);  
     }
     return configValue;
   }
   ```

5. 调用MediaKeySystem类中的setConfigurationByteArray方法，设置当前设备支持的字符数组类型的属性值。接口调用失败时，会返回相应错误码，错误码类型参见[DrmErrorCode](../../reference/apis-drm-kit/js-apis-drm.md#drmerrorcode)。

   ```ts
   function setConfigurationByteArray(configName: string, value: Uint8Array): void {
     let mediaKeysystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
     try {
       mediaKeysystem.setConfigurationByteArray(configName, value);
     } catch (err) {
       let error = err as BusinessError;
       console.error(`setConfigurationByteArray ERROR: ${error}`);  
     }
     return;
   }
   ```

6. 调用MediaKeySystem类中的getConfigurationByteArray方法，获取字符数组类型的设备相关设备属性值。接口调用失败时，会返回相应错误码，错误码类型参见[DrmErrorCode](../../reference/apis-drm-kit/js-apis-drm.md#drmerrorcode)。

   ```ts
   function getConfigurationByteArray(configName: string): Uint8Array | undefined {
     let mediaKeysystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
     let configValue: Uint8Array | undefined = undefined;
     try {
       configValue = mediaKeysystem.getConfigurationByteArray(configName);
     } catch (err) {
       let error = err as BusinessError;
       console.error(`getConfigurationByteArray ERROR: ${error}`);  
     }
     return configValue;
   }
   ```

7. 调用MediaKeySystem类中的getMetrics()方法，获取系统统计信息。其中包括当前会话数、插件版本信息、解密次数和解密失败次数。接口调用失败会返回相应错误码，错误码类型参见[DrmErrorCode](../../reference/apis-drm-kit/js-apis-drm.md#drmerrorcode)。

   ```ts
   function getStatistics(): drm.StatisticKeyValue[] {
     let mediaKeysystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
     let statisticKeyValue: drm.StatisticKeyValue[] = [];
     try {
       statisticKeyValue = mediaKeysystem.getStatistics();
     } catch (err) {
       let error = err as BusinessError;
       console.error(`getConfigurationByteArray ERROR: ${error}`);
     }
     return statisticKeyValue;
   }
   ```

8. 获取设备最大安全级别。

   调用MediaKeySystem类中的getMaxContentProtectionLevel方法，获取设备支持的安全级别。接口调用失败会返回相应错误码，错误码类型参见[DrmErrorCode](../../reference/apis-drm-kit/js-apis-drm.md#drmerrorcode)。

     ```ts
   function getMaxContentProtectionLevel(): drm.ContentProtectionLevel {
     let mediaKeysystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
     let contentProtectionLevel: drm.ContentProtectionLevel = drm.ContentProtectionLevel.CONTENT_PROTECTION_LEVEL_UNKNOWN;
     try {
       contentProtectionLevel = mediaKeysystem.getMaxContentProtectionLevel();
     } catch (err) {
       let error = err as BusinessError;
       console.error(`getMaxContentProtectionLevel ERROR: ${error}`);
     }
     return contentProtectionLevel;
   }
     ```

9. 生成设备证书请求。

   调用MediaKeySystem类中的generateKeySystemRequest方法，获取设备证书请求。接口调用失败会返回相应错误码，错误码类型参见[DrmErrorCode](../../reference/apis-drm-kit/js-apis-drm.md#drmerrorcode)。

     ```ts
   async function generateKeySystemRequest(): Promise<drm.ProvisionRequest | undefined> {
     let mediaKeysystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
     let provisionRequest: drm.ProvisionRequest | undefined = await mediaKeysystem.generateKeySystemRequest().catch((err: BusinessError) => {
        console.error(`generateKeySystemRequest: ERROR: ${err}`);
        return undefined;
      });
     return provisionRequest;
   }
     ```

10. 处理设备证书响应。

   调用MediaKeySystem类中的processKeySystemResponse方法，处理设备证书响应。接口调用失败会返回相应错误码，错误码类型参见[DrmErrorCode](../../reference/apis-drm-kit/js-apis-drm.md#drmerrorcode)。

   ```ts
   function processKeySystemResponse(response: Uint8Array): void {
     let mediaKeysystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
     mediaKeysystem.processKeySystemResponse(response).then(() => {
       console.log("processKeySystemResponse");
     }).catch((err: BusinessError) => {
       console.error(`processKeySystemResponse: ERROR: ${err}`);
     });
   }
   ```

11. 获取设备证书状态。

    调用MediaKeySystem类中的getCertificateStatus方法，获取设备证书状态。接口调用失败会返回相应错误码，错误码类型参见[DrmErrorCode](../../reference/apis-drm-kit/js-apis-drm.md#drmerrorcode)。

    ```ts
    function getCertificateStatus(): drm.CertificateStatus {
      let mediaKeysystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
      let certificateStatus: drm.CertificateStatus = drm.CertificateStatus.CERT_STATUS_PROVISIONED;
      try {
        certificateStatus = mediaKeysystem.getCertificateStatus();
      } catch (err) {
        let error = err as BusinessError;
        console.error(`getCertificateStatus ERROR: ${error}`);
      }
      return certificateStatus;
    }
    ```

12. 创建DRM会话。

    调用MediaKeySystem类中的createMediaKeySession方法，按指定安全级别进行创建会话。接口调用失败会返回相应错误码，错误码类型参见[DrmErrorCode](../../reference/apis-drm-kit/js-apis-drm.md#drmerrorcode)。

    ```ts
    function createMediaKeySession(level: drm.ContentProtectionLevel): drm.MediaKeySession | undefined {
      let mediaKeysystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
      let mediaKeySession: drm.MediaKeySession | undefined = undefined;
      try {
        mediaKeySession = mediaKeysystem.createMediaKeySession(level);
      } catch (err) {
        let error = err as BusinessError;
        console.error(`getCertificateStatus ERROR: ${error}`);
      }
      return mediaKeySession;
    }
    ```

13. 创建DRM会话。

    调用MediaKeySystem类中的createMediaKeySession方法，创建会话。接口调用失败会返回相应错误码，错误码类型参见[DrmErrorCode](../../reference/apis-drm-kit/js-apis-drm.md#drmerrorcode)。

    ```ts
    function createMediaKeySession(): drm.MediaKeySession | undefined {
      let mediaKeysystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
      let mediaKeySession: drm.MediaKeySession | undefined = undefined;
      try {
        mediaKeySession = mediaKeysystem.createMediaKeySession();
      } catch (err) {
        let error = err as BusinessError;
        console.error(`getCertificateStatus ERROR: ${error}`);
      }
      return mediaKeySession;
    }
    ```

14. 获取离线许可证Id。

    调用MediaKeySystem类中的getOfflineMediaKeyIds方法，获取离线许可证Id。接口调用失败会返回相应错误码，错误码类型参见[DrmErrorCode](../../reference/apis-drm-kit/js-apis-drm.md#drmerrorcode)。

    ```ts
    function getOfflineMediaKeyIds(): Uint8Array[] | undefined {
      let mediaKeysystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
      let offlineMediaKeyIds: Uint8Array[] | undefined = undefined;
      try {
        offlineMediaKeyIds = mediaKeysystem.getOfflineMediaKeyIds();
      } catch (err) {
        let error = err as BusinessError;
        console.error(`getOfflineMediaKeyIds ERROR: ${error}`);
      }
      return offlineMediaKeyIds;
    }
    ```

15. 获取离线许可证状态。

    调用MediaKeySystem类中的getOfflineMediaKeyStatus方法，获取离线许可证状态。接口调用失败会返回相应错误码，错误码类型参见[DrmErrorCode](../../reference/apis-drm-kit/js-apis-drm.md#drmerrorcode)。

    ```ts
    function getOfflineMediaKeyStatus(mediakeyId: Uint8Array): drm.OfflineMediaKeyStatus | undefined {
      let mediaKeysystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
      let offlineMediaKeyStatus: drm.OfflineMediaKeyStatus | undefined = undefined;
      try {
        offlineMediaKeyStatus = mediaKeysystem.getOfflineMediaKeyStatus(mediakeyId);
      } catch (err) {
        let error = err as BusinessError;
        console.error(`getOfflineMediaKeyStatus ERROR: ${error}`);
      }
      return offlineMediaKeyStatus;
    }
    ```

16. 移除离线许可证。

    调用MediaKeySystem类中的clearOfflineMediaKeys方法，移除离线许可证。接口调用失败会返回相应错误码，错误码类型参见[DrmErrorCode](../../reference/apis-drm-kit/js-apis-drm.md#drmerrorcode)。

    ```ts
    function clearOfflineMediaKeys(mediakeyId: Uint8Array): void {
      let mediaKeysystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
      try {
        mediaKeysystem.clearOfflineMediaKeys(mediakeyId);
      } catch (err) {
        let error = err as BusinessError;
        console.error(`clearOfflineMediaKeys ERROR: ${error}`);
      }
      return;
    }
    ```

17. 销毁MediaKeySystem实例。

    调用MediaKeySystem类中的destroy方法，销毁MediaKeySystem实例。接口调用失败会返回相应错误码，错误码类型参见[DrmErrorCode](../../reference/apis-drm-kit/js-apis-drm.md#drmerrorcode)。

    ```ts
    function destroy(mediaKeySystem: drm.MediaKeySystem): void {
      let mediaKeysystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
      try {
        mediaKeysystem.destroy();
      } catch (err) {
        let error = err as BusinessError;
        console.error(`mediaKeysystem destroy ERROR: ${error}`);
      }
      return;
    }
    ```

18. 状态监听。

    在播放器应用开发过程中，可以随时监听MediaKeySystem信息状态，包括设备证书请求事件监听。

    通过注册固定的keySystemRequired回调函数获取监听设备证书请求，MediaKeySystem创建成功时即可监听，有该事件返回结果则认为设备证书请求开始，不需要监听的时候使用off进行注销监听。

    ```ts
    function onRegisterkeySystemRequired(mediaKeysystem: drm.MediaKeySystem): void {
      mediaKeysystem.on('keySystemRequired', (eventInfo: drm.EventInfo) => {
        console.log('keySystemRequired' + 'extra:' + eventInfo.extraInfo + ' data:' + eventInfo.info);
      });
    }
    ```

    ```ts
    function unregisterkeySystemRequired(mediaKeysystem: drm.MediaKeySystem): void {
      mediaKeysystem.off('keySystemRequired');
    }
    ```
