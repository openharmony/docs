# 数字版权保护(ArkTS)

开发者可以调用DRM Kit的ArkTS接口实现DRM证书管理、DRM许可证管理、DRM节目授权、DRM节目解密等数字版权保护功能。

DRM Kit提供MediaKeySystem实现DRM证书管理、DRM许可证管理功能，并管理MediaKeySession实例；MediaKeySession实现DRM节目授权，并可支持Media Kit或Media Kit/AVCodec Kit实现DRM节目解密以实现DRM节目播放。

## 开发步骤

详细的API说明请参考[DRM API](../../reference/apis-drm-kit/js-apis-drm.md)。

1. 导入DRM Kit接口。

   ```ts
   import { drm } from '@kit.DrmKit';
   ```

2. 导入BusinessError模块抛出Drm Kit接口的错误码。

   ```ts
   import { BusinessError } from '@kit.BasicServicesKit';
   ```

3. （可选）获取设备支持的DRM解决方案名称和唯一标识的列表。

   ```ts
   let description: drm.MediaKeySystemDescription[] = drm.getMediaKeySystems();
   ```

   如果获取结果数组为空，说明该设备中不存在支持的DRM解决方案。

4. （可选）查询设备是否支持对应DRM解决方案名称、媒体类型、安全保护级别的DRM解决方案。

   ```ts
   let isSupported: boolean = drm.isMediaKeySystemSupported("com.clearplay.drm", "video/mp4", drm.ContentProtectionLevel.CONTENT_PROTECTION_LEVEL_SW_CRYPTO);
   ```

   如果查询结果为false，说明该设备不支持对应的DRM解决方案。

5. 创建MediaKeySystem实例。

   ```ts
   let mediaKeySystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
   ```

   如果创建失败则返回undefined，说明该设备不支持该DRM解决方案。

6. （可选）设置MediaKeySystem状态监听事件。

   通过注册keySystemRequired回调函数监听设备DRM证书请求事件。该事件在需要设备DRM证书时触发，此时建议完成设备DRM证书请求与处理流程。

   ```ts
   mediaKeySystem.on('keySystemRequired', (eventInfo: drm.EventInfo) => {
     console.log('keySystemRequired' + 'extra:' + eventInfo.extraInfo + ' data:' + eventInfo.info);
       // 设备DRM证书请求与处理。
   });
   ```

7. （可选）获取设备DRM证书状态。

   ```ts
   let certificateStatus: drm.CertificateStatus = mediaKeySystem.getCertificateStatus();
   ```

8. （可选）生成设备DRM证书请求与处理设备DRM证书响应。

   如果设备DRM证书状态不是drm.CertificateStatus.CERT_STATUS_PROVISIONED，可以生成设备DRM证书请求，处理设备DRM证书响应。

   ```ts
   if(certificateStatus != drm.CertificateStatus.CERT_STATUS_PROVISIONED) {
       mediaKeySystem.generateKeySystemRequest().then(async (drmRequest: drm.ProvisionRequest) => {
           console.info("generateKeySystemRequest success", drmRequest.data, drmRequest.defaultURL);
       }).catch((err:BusinessError) =>{
           console.info("generateKeySystemRequest err end", err.code);
       });
   } else {
       console.info("The certificate already exists.");
   }
   // 将设备DRM证书请求返回的drmRequest.data通过网络请求发送给DRM证书服务获取设备DRM证书响应，并处理。
   let provisionResponseByte = new Uint8Array([0x00, 0x00, 0x00, 0x00]); // 设备DRM证书响应。
   mediaKeySystem.processKeySystemResponse(provisionResponseByte).then(() => {
       console.info("processKeySystemResponse success");
   }).catch((err:BusinessError) =>{
       console.info("processKeySystemResponse err end", err.code);
   });
   ```

9. 创建MediaKeySession实例。

   创建该DRM解决方案默认内容保护级别的MediaKeySession实例。

   ```ts
   let mediaKeySession: drm.MediaKeySession = mediaKeySystem.createMediaKeySession();
   ```

10. （可选）设置MediaKeySession状态监听事件。

    监听MediaKeySession实例的事件，包括媒体密钥请求事件、媒体密钥过期事件、媒体密钥有效期更新事件、媒体密钥变换事件等。

    - 监听媒体密钥请求事件，此时建议完成媒体密钥请求与处理流程。

      ```ts
      mediaKeySession.on('keyRequired', (eventInfo: drm.EventInfo) => {
        console.log('keyRequired' + 'info:' + eventInfo.info + ' extraInfo:' + eventInfo.extraInfo);
          // 媒体密钥请求与处理。
      });
      ```

    - 监听媒体密钥过期事件。

      ```ts
      mediaKeySession.on('keyExpired', (eventInfo: drm.EventInfo) => {
        console.log('keyExpired' + 'info:' + eventInfo.info + ' extraInfo:' + eventInfo.extraInfo);
      });
      ```

    - 监听媒体密钥有效期更新事件。

      ```ts
      mediaKeySession.on('expirationUpdate', (eventInfo: drm.EventInfo) => {
        console.log('expirationUpdate' + 'info:' + eventInfo.info + ' extraInfo:' + eventInfo.extraInfo);
      });
      ```

    - 监听媒体密钥变换事件。

      ```ts
      mediaKeySession.on('keysChange', (keyInfo : drm.KeysInfo[], newKeyAvailable:boolean) => {
          for(let i = 0; i < keyInfo.length; i++){
              console.log('keysChange' + 'info:' + keyInfo[i].keyId + ' extraInfo:' + keyInfo[i].value);
          }
      });
      ```

11. （可选）查询是否需要安全解码。

    ```ts
    try {
      let status: boolean = mediaKeySession.requireSecureDecoderModule("video/avc");
    } catch (err) {
      let error = err as BusinessError;
      console.error(`requireSecureDecoderModule ERROR: ${error}`);
    }
    ```

12. 生成媒体密钥请求与处理媒体密钥响应。

    获取到DRM节目中的DRM信息时，可以生成媒体密钥请求，处理媒体密钥响应，以请求许可证完成DRM节目授权。

    ```ts
    // 根据DRM解决方案要求，基于DRM信息中的pssh生成initData。
    let initData = new Uint8Array([0x00, 0x00, 0x00, 0x00]);
    // 根据DRM解决方案要求设置可选数据的值。
    let optionalData:drm.OptionsData[] = [{
        name: "optionalDataName",
        value: "optionalDataValue"
    }];
    // 在线媒体密钥请求和响应。
    mediaKeySession.generateMediaKeyRequest("video/mp4", initData, drm.MediaKeyType.MEDIA_KEY_TYPE_ONLINE, optionalData).then(async (licenseRequest: drm.MediaKeyRequest) => {
       console.info("generateMediaKeyRequest success", licenseRequest.mediaKeyRequestType, licenseRequest.data, licenseRequest.defaultURL);
       // 将媒体密钥请求返回的licenseRequest.data通过网络请求发送给DRM服务获取媒体密钥响应，并处理。
       let licenseResponse = new Uint8Array([0x00, 0x00, 0x00, 0x00]); // 媒体密钥响应。
       mediaKeySession.processMediaKeyResponse(licenseResponse).then((mediaKeyId: Uint8Array) => {
         console.info("processMediaKeyResponse success");
       }).catch((err:BusinessError) =>{
         console.info("processMediaKeyResponse err end", err.code);
      });
    }).catch((err:BusinessError) =>{
      console.info("generateMediaKeyRequest err end", err.code);
    });
    // 离线媒体密钥请求和响应。
    let offlineMediaKeyId: Uint8Array;
    mediaKeySession.generateMediaKeyRequest("video/mp4", initData, drm.MediaKeyType.MEDIA_KEY_TYPE_OFFLINE, optionalData).then((licenseRequest: drm.MediaKeyRequest) => {
       console.info("generateMediaKeyRequest success", licenseRequest.mediaKeyRequestType, licenseRequest.data, licenseRequest.defaultURL);
       // 将媒体密钥请求返回的licenseRequest.data通过网络请求发送给DRM服务获取媒体密钥响应，并处理。
       let licenseResponse = new Uint8Array([0x00, 0x00, 0x00, 0x00]); // 媒体密钥响应。
       mediaKeySession.processMediaKeyResponse(licenseResponse).then((mediaKeyId: Uint8Array) => {
         offlineMediaKeyId = new Uint8Array(mediaKeyId);
         console.info("processMediaKeyResponse success");
       }).catch((err:BusinessError) =>{
         console.info("processMediaKeyResponse err end", err.code);
      });
    }).catch((err:BusinessError) =>{
      console.info("generateMediaKeyRequest err end", err.code);
    });
      ```

13. （可选）恢复离线媒体密钥。

    ```ts
    mediaKeySession.restoreOfflineMediaKeys(offlineMediaKeyId).then(() => {
      console.log("restoreOfflineMediaKeys success.");
    }).catch((err: BusinessError) => {
      console.error(`restoreOfflineMediaKeys: ERROR: ${err}`);
    });
    ```

14. （可选）检查媒体密钥状态。

    ```ts
    let mediaKeyStatus: drm.MediaKeyStatus[]
    try {
      mediaKeyStatus = mediaKeySession.checkMediaKeyStatus()
    } catch (err) {
      let error = err as BusinessError;
      console.error(`checkMediaKeyStatus: ERROR: ${error}`);
    }
    ```

15. （可选）获取离线媒体密钥标识列表、获取离线媒体密钥状态与删除离线媒体密钥。

    媒体密钥标识用于对离线媒体密钥的管理媒体密钥标识用于对离线媒体密钥的管理。

    ```ts
    let offlineMediaKeyIds: Uint8Array[] = mediaKeySystem.getOfflineMediaKeyIds();
    try {
      let offlineMediaKeyStatus: drm.OfflineMediaKeyStatus = mediaKeySystem.getOfflineMediaKeyStatus(offlineMediaKeyIds[0]);
    } catch (err) {
      let error = err as BusinessError;
      console.error(`getOfflineMediaKeyStatus ERROR: ${error}`);
    }
    try {
      mediaKeySystem.clearOfflineMediaKeys(offlineMediaKeyIds[0]);
    } catch (err) {
      let error = err as BusinessError;
      console.error(`clearOfflineMediaKeys ERROR: ${error}`);
    }
    ```

16. 销毁MediaKeySession实例。

    完成加密媒体解密，MediaKeySession实例不再使用时，销毁MediaKeySession实例。

    ```ts
    // MediaKeySession实例使用完需要进行资源释放。
    mediaKeySession.destroy();
    ```

17. 销毁MediaKeySystem实例。

    完成DRM功能使用，MediaKeySystem实例不再使用，销毁MediaKeySystem实例。

    ```ts
    // MediaKeySystem实例使用完需要进行资源释放。
    mediaKeySystem.destroy();
    ```