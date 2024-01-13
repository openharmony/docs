# DRM会话管理(ArkTS)

DRM会话管理（MediaKeySession）支持MediaKeySession实例管理、许可证申请与处理等。

## 开发步骤

详细的API说明请参考[DRM API参考](../reference/apis/js-apis-drm.md)。

1. 导入相关接口，导入方法如下。

   ```ts
   import drm from '@ohos.multimedia.drm';
   ```

2. 调用MediaKeySession类中的generateLicenseRequest(mimeType: string, initData: Uint8Array, licenseType: number, optionalData: OptionalData[]): LicenseRequest方法，生成许可证请求。接口调用失败时，会返回相应错误码，错误码类型参见[DrmErrorCode](../reference/apis/js-apis-drm.md#drmerrorcode)。

   ```ts
   function generateLicenseRequest(mimeType: string, initData: Uint8Array, licenseType: number, optionalData: OptionalData[]): LicenseRequest {
    let mediaKeysystem = drm.createMediaKeySystem("com.drm.clearplay");
    let mediaKeySession = mediaKeysystem.createMediaKeySession();
    var optionalData = [
     {name : "optionalDataNameA", value : "optionalDataValueA"},
     {name : "optionalDataNameB", value : "optionalDataValueB"},
    ];
    let licenseRequest =  mediaKeySession.generateLicenseRequest("video/mp4", uint8pssh, drm.LicenseType.LICENSE_TYPE_ONLINE, optionalData);
    return licenseRequest;
   }
   ```

3. 调用MediaKeySession类中的processLicenseResponse(response: Uint8Array): Uint8Array方法，处理许可证响应报文。接口调用失败时，会返回相应错误码，错误码类型参见[DrmErrorCode](../reference/apis/js-apis-drm.md#drmerrorcode)。

   ```ts
   function processLicenseResponse(response: Uint8Array): Uint8Array {
    let mediaKeysystem = drm.createMediaKeySystem("com.clearplay.drm");
    let mediaKeySession = mediaKeysystem.createMediaKeySession();
    let licenseId =  mediaKeySession.processLicenseResponse(Uint8Array.from("licenseResponse"));
   }
   ```

4. 调用MediaKeySession类中的checkLicenseStatus(): LicenseStatus[]方法，检查当前会话的许可证状态。接口调用失败时，会返回相应错误码，错误码类型参见[DrmErrorCode](../reference/apis/js-apis-drm.md#drmerrorcode)。

   ```ts
   function checkLicenseStatus(): LicenseStatus[] {
    let mediaKeysystem = drm.createMediaKeySystem("com.drm.clearplay");
    let mediaKeySession = mediaKeysystem.createMediaKeySession();
    let licenseStatus =  mediaKeySession.checkLicenseStatus();
    return licenseStatus;
   }
   ```

5. 调用MediaKeySession类中的removeLicense(): void方法，删除当前会话的许可证。接口调用失败时，会返回相应错误码，错误码类型参见[DrmErrorCode](../reference/apis/js-apis-drm.md#drmerrorcode)。

   ```ts
   function removeLicense(): void {
    let mediaKeysystem = drm.createMediaKeySystem("com.drm.clearplay");
    let mediaKeySession = mediaKeysystem.createMediaKeySession();
    mediaKeySession.removeLicense();
   }
   ```

6. 调用MediaKeySession类中的generateOfflineReleaseRequest(licenseId: Uint8Array): Uint8Array方法，生成离线许可证释放请求。接口调用失败会返回相应错误码，错误码类型参见[DrmErrorCode](../reference/apis/js-apis-drm.md#drmerrorcode)。

   ```ts
   function generateOfflineReleaseRequest(licenseId: Uint8Array): Uint8Array {
     let mediaKeysystem = drm.createMediaKeySystem("com.drm.clearplay");
     let mediaKeySession = mediaKeysystem.createMediaKeySession();
     let offlineLicenseId =  mediaKeySession.processLicenseResponse(Uint8Array.from("offlineReleaseRequest"));
     let offlineReleaseRequest = mediaKeySession.generateOfflineReleaseRequest(offlineLicenseId);
   }
   ```

7. 处理离线许可证释放响应。

   调用MediaKeySession类中的processOfflineReleaseResponse(licenseId: Uint8Array, response: Uint8Array): void方法，处理离线许可证释放响应。接口调用失败会返回相应错误码，错误码类型参见[DrmErrorCode](../reference/apis/js-apis-drm.md#drmerrorcode)。

   ```ts
   function processOfflineReleaseResponse(licenseId: Uint8Array, response: Uint8Array): void
   {
   let mediaKeysystem = drm.createMediaKeySystem("com.drm.clearplay");
   let mediaKeySession = mediaKeysystem.createMediaKeySession();
   let offlineLicenseId =  mediaKeySession.processLicenseResponse(Uint8Array.from("offlineReleaseRequest"));
   let offlineReleaseResponse = mediaKeySession.processOfflineReleaseResponse(offlineLicenseId, Uint8Array.from(response));
   }
   ```

8. 恢复离线许可证。

   调用MediaKeySession类中的restoreOfflineLicense(licenseId: Uint8Array): void方法，恢复离线许可证。接口调用失败会返回相应错误码，错误码类型参见[DrmErrorCode](../reference/apis/js-apis-drm.md#drmerrorcode)。

   ```ts
   function restoreOfflineLicense(licenseId: Uint8Array): void {
   let mediaKeysystem = drm.createMediaKeySystem("com.drm.clearplay");
   let mediaKeySession = mediaKeysystem.createMediaKeySession();
   let offlineReleaseResponse = mediaKeySession.processOfflineReleaseResponse(offlineLicenseId, Uint8Array.from(response));
   mediaKeySession.restoreOfflineLicense(offlineLicenseId);
   return;
   }
   ```

9. 处理设备证书响应。

   调用MediaKeySession类中的getSecurityLevel(): SecurityLevel方法，获取当前会话的安全级别。接口调用失败会返回相应错误码，错误码类型参见[DrmErrorCode](../reference/apis/js-apis-drm.md#drmerrorcode)。

   ```ts
   function getSecurityLevel(): SecurityLevel {
   let mediaKeysystem = drm.createMediaKeySystem("com.drm.clearplay");
   let mediaKeySession = mediaKeysystem.createMediaKeySession();
   let securityLevel = mediaKeySession.getSecurityLevel();
   return securityLevel;
   }
   ```

10. 获取设备证书状态。

    调用MediaKeySession类中的requireSecureDecoderModule(mimeType: string): boolean方法，查询安全解码模块状态。接口调用失败会返回相应错误码，错误码类型参见[DrmErrorCode](../reference/apis/js-apis-drm.md#drmerrorcode)。

    ```ts
    function requireSecureDecoderModule(mimeType: string): boolean {
    let mediaKeysystem = drm.createMediaKeySystem("com.drm.clearplay");
    let mediaKeySession = mediaKeysystem.createMediaKeySession();
    let status = mediaKeySession.requireSecureDecoderModule(mimeType);
    return status;
    }
    ```

11. 销毁MediaKeySystem实例。

    调用MediaKeySession类中的destroy(): void方法，销毁MediaKeySession实例。接口调用失败会返回相应错误码，错误码类型参见[DrmErrorCode](../reference/apis/js-apis-drm.md#drmerrorcode)。

    ```ts
    function destroy(mediaKeySession: MediaKeySession): void {
    mediaKeySession.destroy();
    return;
    }
    ```

12. 状态监听。

    在播放器应用开发过程中，可以随时监听MediaKeySession信息状态，包括keyneed事件监听、密钥过期事件监听、第三方自定义事件监听、密钥过期更新事件监听、密钥变化事件监听。

    - 通过注册固定的keySystemRequired回调函数获取监听设备证书请求，MediaKeySession创建成功时即可监听，有该事件返回结果则认为设备证书请求开始，不需要监听的时候使用off进行注销监听。

      ```ts
      function onRegisterkeyneed(mediaKeysession: drm.MediaKeysession): void {
        mediaKeysession.on('keyneed', (extra, data) => {
          console.log('keyneed' + 'extra:' + extra + ' data:' +data);
        });
      }
      ```

      ```ts
      function unregisterkeyneed(mediaKeysession: drm.MediaKeysession): void {
        mediaKeysession.off('keyneed');
      }
      ```

    - 通过注册固定的keyExpired回调函数获取监听密钥过期事件，MediaKeySession创建成功时即可监听，不需要监听的时候使用off进行注销监听。

      ```ts
      function onRegisterkeyExpired(mediaKeysession: drm.MediaKeysession): void {
        mediaKeysession.on('keyExpired', (extra, data) => {
          console.log('keyExpired' + 'extra:' + extra + ' data:' +data);
        });
      }
      ```

      ```ts
      function unRegisterkeyExpired(mediaKeysession: drm.MediaKeysession): void {
        mediaKeysession.off('keyExpired');
      }
      ```

    - 通过注册固定的vendorDefined回调函数获取监听第三方自验证事件，MediaKeySession创建成功时即可监听，不需要监听的时候使用off进行注销监听。

      ```ts
      function onRegisterVendorDefined(mediaKeysession: drm.MediaKeysession): void {
        mediaKeysession.on('vendorDefined', (extra, data) => {
          console.log('vendorDefined' + 'extra:' + extra + ' data:' +data);
        });
      }
      ```

      ```ts
      function unRegisterVendorDefined(mediaKeysession: drm.MediaKeysession): void {
        mediaKeysession.off('vendorDefined');
      }
      ```

    - 通过注册固定的expirationUpdated回调函数获取监听过期更新事件，MediaKeySession创建成功时即可监听，不需要监听的时候使用off进行注销监听。

      ```ts
      function onRegisterExpirationUpdated(mediaKeysession: drm.MediaKeysession): void {
        mediaKeysession.on('expirationUpdated', (extra, data) => {
          console.log('expirationUpdated' + 'extra:' + extra + ' data:' +data);
        });
      }
      ```

      ```ts
      function unRegisterExpirationUpdated(mediaKeysession: drm.MediaKeysession): void {
        mediaKeysession.off('expirationUpdated');
      }
      ```

    - 通过注册固定的keyChanged回调函数获取监听密钥变化事件，MediaKeySession创建成功时即可监听，不需要监听的时候使用off进行注销监听。

      ```ts
      function onRegisterKeyChanged(mediaKeysession: drm.MediaKeysession): void {
        mediaKeysession.on('keyChanged', (extra, data) => {
          console.log('keyChanged' + 'extra:' + extra + ' data:' +data);
        });
      }
      ```

      ```ts
      function unRegisterKeyChanged(mediaKeysession: drm.MediaKeysession): void {
        mediaKeysession.off('keyChanged');
      }
      ```
