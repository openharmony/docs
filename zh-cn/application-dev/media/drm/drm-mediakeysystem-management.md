# DRM系统管理(ArkTS)

DRM系统管理（MediaKeySystem）支持MediaKeySystem实例管理、设备DRM证书申请与处理、会话实例管理、离线媒体密钥管理、获取DRM度量统计信息、设备属性等。在使用DRM Kit功能时，先查询设备是否支持对应DRM解决方案的DRM功能。在DRM Kit里DRM解决方案以插件形式存在，所以也叫DRM插件。

## 开发步骤

详细的API说明请参考[DRM API参考](../../reference/apis-drm-kit/js-apis-drm.md)。

1. 导入相关接口，导入方法如下。

    ```ts
    import { drm } from '@kit.DrmKit';
    ```

2. 导入BusinessError模块，用于获取drm模块相关接口抛出的错误码。

    ```ts
    import { BusinessError } from '@kit.BasicServicesKit';
    ```

3. 查询设备是否支持对应的DRM解决方案。

   > **说明：**
   >
   > 如果查询为false，说明该设备不支持对应的DRM解决方案。

   ```ts
   let isSupported: boolean = drm.isMediaKeySystemSupported("com.clearplay.drm", "video/avc", drm.ContentProtectionLevel.CONTENT_PROTECTION_LEVEL_SW_CRYPTO);
   ```

4. （可选）获取设备上DRM解决方案的名称和唯一标识的列表。

   > **说明：**
   >
   > 如果查询出的数组为空，说明该设备中不存在支持的DRM解决方案。

   ```ts
   let description: drm.MediaKeySystemDescription[] = drm.getMediaKeySystems();
   ```

5. 创建MediaKeySystem实例。

   > **说明：**
   >
   > 如果创建失败则返回undefined，说明该设备不支持DRM能力。

   ```ts
   let mediaKeySystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
   ```

6. （可选）获取指定DRM解决方案名称对应的唯一标识。

   > **说明：**
   >
   > 如果查询出的uuid的长度为0，说明该设备中不存在支持的DRM解决方案。

   ```ts
   let uuid: string = drm.getMediaKeySystemUuid("com.clearplay.drm");
   ```

7. （可选）设置和获取DRM解决方案支持属性值。

    ```ts
    // DRM解决方案支持属性设置时，设置DRM解决方案支持的字符串类型的属性值
    mediaKeySystem.setConfigurationString("configName", "configValue");
    // 获取字符串类型的属性值
    let configValueString : string = mediaKeySystem.getConfigurationString("version");
    let configValueUint8ArrayA: Uint8Array = new Uint8Array([0x00, 0x00, 0x00, 0x00]);
    // DRM解决方案支持属性设置时，设置DRM解决方案支持的字符数组类型的属性值
    mediaKeySystem.setConfigurationByteArray("Uint8ArrayConfigName", configValueUint8ArrayA);
    // 获取字符数组类型的属性值
    let configValueUint8ArrayB: Uint8Array = mediaKeySystem.getConfigurationByteArray("Uint8ArrayConfigName");
    ```

8. （可选）获取设备支持的最大内容保护级别。

    ```ts
    let contentProtectionLevel: drm.ContentProtectionLevel = drm.ContentProtectionLevel.CONTENT_PROTECTION_LEVEL_UNKNOWN;
    try {
      contentProtectionLevel = mediaKeySystem.getMaxContentProtectionLevel();
    } catch (err) {
      let error = err as BusinessError;
      console.error(`getMaxContentProtectionLevel ERROR: ${error}`);
    }
    ```

9. 状态监听。

    监听MediaKeySystem设备DRM证书请求事件。

    通过注册的keySystemRequired回调函数监听设备DRM证书请求，MediaKeySystem创建成功时即可监听，需要设备DRM证书时触发。

    ```ts
    mediaKeySystem.on('keySystemRequired', (eventInfo: drm.EventInfo) => {
      console.log('keySystemRequired' + 'extra:' + eventInfo.extraInfo + ' data:' + eventInfo.info);
    });
    ```

10. （可选）获取设备DRM证书状态。

    ```ts
    let certificateStatus: drm.CertificateStatus = mediaKeySystem.getCertificateStatus();
    ```

11. 生成设备DRM证书请求。

   DRM解决方案创建MediaKeySession会话时，如果没有设备DRM证书会触发DRM证书请求事件，此时，先获取设备上设备DRM证书状态，若设备上没有DRM证书或DRM证书状态异常（状态不是drm.CertificateStatus.CERT_STATUS_PROVISIONED），生成设备DRM证书请求。

  ```ts
    if(certificateStatus != drm.CertificateStatus.CERT_STATUS_PROVISIONED){
      mediaKeySystem.generateKeySystemRequest().then(async (drmRequest: drm.ProvisionRequest) => {
        console.info("generateKeySystemRequest success", drmRequest.data, drmRequest.defaultURL);
      }).catch((err:BusinessError) =>{
          console.info("generateKeySystemRequest err end", err.code);
       });
    } else {
      console.info("The certificate already exists.");
    }
  ```

12. 处理设备DRM证书响应。

   在将设备DRM证书请求发送到DRM服务获取设备DRM证书请求响应后，处理设备DRM证书响应。

  ```ts
    // 将设备DRM证书请求返回的drmRequest.data通过网络请求发送给DRM证书服务获取设备DRM证书请求响应，设置设备DRM证书请求响应
    let provisionResponseByte = new Uint8Array([0x00, 0x00, 0x00, 0x00]);
    mediaKeySystem.processKeySystemResponse(provisionResponseByte).then(() => {
      console.info("processKeySystemResponse success");
    }).catch((err:BusinessError) =>{
      console.info("processKeySystemResponse err end", err.code);
    });
  ```

13. 创建MediaKeySession会话。

    创建指定内容保护级别的MediaKeySession会话、或创建DRM解决方案默认内容保护级别的MediaKeySession会话。
    ```ts
    let mediaKeySession: drm.MediaKeySession = mediaKeySystem.createMediaKeySession();
    ```

14. （可选）获取离线媒体密钥标识列表，媒体密钥标识用于对离线媒体密钥的管理。

    ```ts
    let offlineMediaKeyIds: Uint8Array[] = mediaKeySystem.getOfflineMediaKeyIds();
    ```

15. （可选）获取离线媒体密钥状态。

    ```ts
    try {
      let offlineMediaKeyStatus: drm.OfflineMediaKeyStatus = mediaKeySystem.getOfflineMediaKeyStatus(offlineMediaKeyIds[0]);
    } catch (err) {
      let error = err as BusinessError;
      console.error(`getOfflineMediaKeyStatus ERROR: ${error}`);
    }
    ```

16. （可选）移除离线媒体密钥。

    ```ts
    try {
      mediaKeySystem.clearOfflineMediaKeys(offlineMediaKeyIds[0]);
    } catch (err) {
      let error = err as BusinessError;
      console.error(`clearOfflineMediaKeys ERROR: ${error}`);
    }
    ```

17. （可选）获取DRM度量记录，包括当前会话数、插件版本信息、解密次数和解密失败次数等。

    ```ts
    let statisticKeyValue: drm.StatisticKeyValue[] = mediaKeySystem.getStatistics();
    ```

18. 销毁MediaKeySession实例。

    完成加密媒体解密，MediaKeySession实例不再使用时，销毁MediaKeySession实例。

    ```ts
    // MediaKeySession实例使用完需要进行资源释放
    mediaKeySession.destroy();
    ```

19. 销毁MediaKeySystem实例。

    完成DRM功能使用，MediaKeySystem实例不再使用，销毁MediaKeySystem实例。

    ```ts
    // MediaKeySystem实例使用完需要进行资源释放
    mediaKeySystem.destroy();
    ```