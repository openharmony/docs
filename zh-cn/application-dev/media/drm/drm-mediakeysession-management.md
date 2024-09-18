# DRM会话管理(ArkTS)

DRM会话管理（MediaKeySession）支持媒体密钥管理及媒体解密等，MediaKeySession实例由系统管理里的MediaKeySystem实例创建和销毁。

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

3. 状态监听。

    监听MediaKeySession实例的事件，包括密钥请求事件、密钥过期事件、第三方自定义事件、密钥过期更新事件、密钥变换事件。

    - 监听密钥请求事件，媒体密钥请求时触发。

       ```ts
       mediaKeySession.on('keyRequired', (eventInfo: drm.EventInfo) => {
         console.log('keyRequired' + 'info:' + eventInfo.info + ' extraInfo:' + eventInfo.extraInfo);
       });
       ```

    - 监听媒体密钥过期事件，媒体密钥过期时触发。

       ```ts
       mediaKeySession.on('keyExpired', (eventInfo: drm.EventInfo) => {
          console.log('keyExpired' + 'info:' + eventInfo.info + ' extraInfo:' + eventInfo.extraInfo);
       });
       ```

    - 监听DRM解决方案自定义事件，DRM解决方案自定义事件发生时触发。

       ```ts
       mediaKeySession.on('vendorDefined', (eventInfo: drm.EventInfo) => {
         console.log('vendorDefined' + 'info:' + eventInfo.info + ' extraInfo:' + eventInfo.extraInfo);
       });
       ```

    - 监听媒体密钥过期更新事件，媒体密钥过期更新时触发。

       ```ts
       mediaKeySession.on('expirationUpdate', (eventInfo: drm.EventInfo) => {
         console.log('expirationUpdate' + 'info:' + eventInfo.info + ' extraInfo:' + eventInfo.extraInfo);
       });
       ```

    - 监听密钥变换事件，媒体密钥变换时触发。

       ```ts
       mediaKeySession.on('keysChange', (keyInfo : drm.KeysInfo[], newKeyAvailable:boolean) => {
         for(let i = 0; i < keyInfo.length; i++){
           console.log('keysChange' + 'info:' + keyInfo[i].keyId + ' extraInfo:' + keyInfo[i].value);
         }
       });
       ```

4. 生成媒体密钥请求、设置媒体密钥请求响应。

   ```ts
   let initData = new Uint8Array([0x00, 0x00, 0x00, 0x00]);
   // 根据DRM解决方案要求设置可选数据的值
   let optionalData:drm.OptionsData[] = [{
     name: "...",
     value: "..."
   }];
   // 以下示例完成在线媒体密钥请求和响应设置
   mediaKeySession.generateMediaKeyRequest("video/avc", initData, drm.MediaKeyType.MEDIA_KEY_TYPE_ONLINE, optionalData).then(async (licenseRequest) => {
      console.info("generateMediaKeyRequest success", licenseRequest.mediaKeyRequestType, licenseRequest.data, licenseRequest.defaultURL);
      // 将媒体密钥请求返回的licenseRequest.data通过网络请求发送给DRM服务获取媒体密钥请求响应，设置媒体密钥请求响应
      let licenseResponse = new Uint8Array([0x00, 0x00, 0x00, 0x00]);
      mediaKeySession.processMediaKeyResponse(licenseResponse).then((mediaKeyId: Uint8Array) => {
        console.info("processMediaKeyResponse success");
      }).catch((err:BusinessError) =>{
        console.info("processMediaKeyResponse err end", err.code);
     });
   }).catch((err:BusinessError) =>{
     console.info("generateMediaKeyRequest err end", err.code);
   });
   // 以下示例完成离线媒体密钥请求和响应设置
   let offlineMediaKeyId = new Uint8Array([0x00, 0x00, 0x00, 0x00]);
   mediaKeySession.generateMediaKeyRequest("video/avc", initData, drm.MediaKeyType.MEDIA_KEY_TYPE_OFFLINE, optionalData).then((licenseRequest: drm.MediaKeyRequest) => {
      console.info("generateMediaKeyRequest success", licenseRequest.mediaKeyRequestType, licenseRequest.data, licenseRequest.defaultURL);
      // 将媒体密钥请求返回的licenseRequest.data通过网络请求发送给DRM服务获取媒体密钥请求响应，设置媒体密钥请求响应
      let licenseResponse = new Uint8Array([0x00, 0x00, 0x00, 0x00]);
      mediaKeySession.processMediaKeyResponse(licenseResponse).then((mediaKeyId: Uint8Array) => {
	offlineMediaKeyId = mediaKeyId;
        console.info("processMediaKeyResponse success");
      }).catch((err:BusinessError) =>{
        console.info("processMediaKeyResponse err end", err.code);
     });
   }).catch((err:BusinessError) =>{
     console.info("generateMediaKeyRequest err end", err.code);
   });
   ```

5. （可选）检查当前MediaKeySession会话的媒体密钥状态。

    ```ts
    try {
      let keyvalue: drm.MediaKeyStatus[] = mediaKeySession.checkMediaKeyStatus();
      console.info("checkMediaKeyStatus success", keyvalue[0].value);
    } catch (err) {
      let error = err as BusinessError;
      console.error(`checkMediaKeyStatus ERROR: ${error}`);
    }
    ```

6. （可选）生成离线媒体密钥释放请求和处理离线媒体密钥释放响应。

   ```ts
   mediaKeySession.generateOfflineReleaseRequest(offlineMediaKeyId).then((OfflineReleaseRequest: Uint8Array) => {
     console.info("generateOfflineReleaseRequest success", OfflineReleaseRequest);
     // 将媒体密钥释放请求返回的OfflineReleaseRequest通过网络请求发送给DRM服务获取媒体密钥释放请求响应，设置媒体密钥释放请求响应
     let OfflineReleaseResponse = new Uint8Array([0x00, 0x00, 0x00, 0x00]);
     mediaKeySession.processOfflineReleaseResponse(offlineMediaKeyId, OfflineReleaseResponse).then(() => {
       console.info("processOfflineReleaseResponse success");
     }).catch((err:BusinessError) =>{
       console.info("processOfflineReleaseResponse err end", err.code);
     });
   }).catch((err:BusinessError) =>{
     console.info("generateOfflineReleaseRequest err end", err.code);
   });
   ```

7. （可选）恢复离线媒体密钥。

   ```ts
   // 恢复指定媒体密钥信息到当前会话
   mediaKeySession.restoreOfflineMediaKeys(offlineMediaKeyId).then(() => {
     console.log("restoreOfflineMediaKeys success.");
   }).catch((err: BusinessError) => {
     console.error(`restoreOfflineMediaKeys: ERROR: ${err}`);
   });
   ```

8. （可选）获取当前会话的安全级别。

    ```ts
    try {
      let contentProtectionLevel: drm.ContentProtectionLevel = mediaKeySession.getContentProtectionLevel();
    } catch (err) {
      let error = err as BusinessError;
      console.error(`getContentProtectionLevel ERROR: ${error}`);
    }
   ```

9. （可选）查询是否需要安全解码。

    ```ts
    try {
      let status: boolean = mediaKeySession.requireSecureDecoderModule("video/avc");
    } catch (err) {
      let error = err as BusinessError;
      console.error(`requireSecureDecoderModule ERROR: ${error}`);
    }
    ```

10. （可选）删除当前会话的媒体密钥。

    ```ts
    try {
       mediaKeySession.clearMediaKeys();
    } catch (err) {
      let error = err as BusinessError;
      console.error(`clearMediaKeys ERROR: ${error}`);
    }
    ```