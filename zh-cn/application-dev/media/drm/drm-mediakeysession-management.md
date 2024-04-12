# 会话管理(ArkTS)

DRM会话管理（MediaKeySession）支持MediaKeySession实例管理、许可证申请与处理等。

## 开发步骤

详细的API说明请参考[DRM API参考](../../reference/apis-drm-kit/js-apis-drm.md)。

1. 导入相关接口，导入方法如下。

   ```ts
   import drm from '@ohos.multimedia.drm';
   ```

2. 调用MediaKeySession类中的generateMediaKeyRequest方法，生成许可证请求。接口调用失败时，会返回相应错误码，错误码类型参见[DrmErrorCode](../../reference/apis-drm-kit/js-apis-drm.md#drmerrorcode)。

   ```ts
   function generateMediaKeyRequest(mimeType: string, initData: Uint8Array, mediakeyType: number, optionalData: OptionalData[]): Promise<MediaKeyRequest> {
    let mediaKeysystem: drm.mediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
    let mediaKeySession: drm.MediaKeySession = mediaKeysystem.createMediaKeySession();
    var uint8pssh = new Uint8Array([0x00, 0x00, 0x00, 0x00]);
    var optionalData = [
     {name : "optionalDataNameA", value : "optionalDataValueA"},
     {name : "optionalDataNameB", value : "optionalDataValueB"},
    ];
    mediaKeySession.generateMediaKeyRequest(mimeType, initData, mediakeyType, optionalData).then((mediaKeyRequest: drm.MediaKeyRequest) =>{
      console.log('generateMediaKeyRequest' + mediaKeyRequest);
    }).catch((err: BusinessError) => {
       console.error(`generateMediaKeyRequest: ERROR: ${err}`);
     });
    return mediaKeyRequest;
   }
   ```

3. 调用MediaKeySession类中的processMediaKeyResponse方法，处理许可证响应报文。接口调用失败时，会返回相应错误码，错误码类型参见[DrmErrorCode](../../reference/apis-drm-kit/js-apis-drm.md#drmerrorcode)。

   ```ts
   function processMediaKeyResponse(response: Uint8Array): Promise<Uint8Array> {
     let mediaKeysystem: drm.mediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
     let mediaKeySession: drm.MediaKeySession = mediaKeysystem.createMediaKeySession();
     mediaKeySession.processMediaKeyResponse(response).then((mediaKeyId: Uint8Array) => {
       console.log('processMediaKeyResponse:' + mediaKeyId);
     }).catch((err: BusinessError) => {
       console.error(`processMediaKeyResponse: ERROR: ${err}`);
     });
     return mediaKeyId;
   }
   ```

4. 调用MediaKeySession类中的checkMediaKeyStatus方法，检查当前会话的许可证状态。接口调用失败时，会返回相应错误码，错误码类型参见[DrmErrorCode](../../reference/apis-drm-kit/js-apis-drm.md#drmerrorcode)。

   ```ts
   function checkMediaKeyStatus(): MediaKeyStatus[] {
     let mediaKeysystem: drm.mediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
     let mediaKeySession: drm.MediaKeySession = mediaKeysystem.createMediaKeySession();
     try {
       let mediakeyStatus: drm.MediaKeyStatus[] =  mediaKeySession.checkMediaKeyStatus();
     } catch (err) {
       let error = err as BusinessError;
       console.error(`checkMediaKeyStatus ERROR: ${error}`);
     }
     return mediakeyStatus;
   }
   ```

5. 调用MediaKeySession类中的clearMediaKeys方法，删除当前会话的许可证。接口调用失败时，会返回相应错误码，错误码类型参见[DrmErrorCode](../../reference/apis-drm-kit/js-apis-drm.md#drmerrorcode)。

   ```ts
   function clearMediaKeys(): void {
     let mediaKeysystem: drm.mediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
     let mediaKeySession: drm.MediaKeySession = mediaKeysystem.createMediaKeySession();
     try {
       mediaKeySession.clearMediaKeys();
     } catch (err) {
       let error = err as BusinessError;
       console.error(`clearMediaKeys ERROR: ${error}`);
     }
   }
   ```

6. 调用MediaKeySession类中的generateOfflineReleaseRequest方法，生成离线许可证释放请求。接口调用失败会返回相应错误码，错误码类型参见[DrmErrorCode](../../reference/apis-drm-kit/js-apis-drm.md#drmerrorcode)。

   ```ts
   function generateOfflineReleaseRequest(mediakeyId: Uint8Array): Promise<Uint8Array> {
     let mediaKeysystem: drm.mediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
     let mediaKeySession: drm.MediaKeySession = mediaKeysystem.createMediaKeySession();
     var offlineReleaseRequest = new Uint8Array([0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00]);
     mediaKeySession.processMediaKeyResponse(offlineReleaseRequest).then((mediaKeyId: Uint8Array) => {
       console.log('processMediaKeyResponse:' + mediaKeyId);
     }).catch((err: BusinessError) => {
       console.error(`processMediaKeyResponse: ERROR: ${err}`);
     });
     mediaKeySession.generateOfflineReleaseRequest(offlineMediaKeyId).then((offlineReleaseRequest: Uint8Array) => {
       console.log('generateOfflineReleaseRequest:' + offlineReleaseRequest);
     }).catch((err: BusinessError) => {
       console.error(`generateOfflineReleaseRequest: ERROR: ${err}`);
     });
     return offlineReleaseRequest;
   }
   ```

7. 处理离线许可证释放响应。

   调用MediaKeySession类中的processOfflineReleaseResponse方法，处理离线许可证释放响应。接口调用失败会返回相应错误码，错误码类型参见[DrmErrorCode](../../reference/apis-drm-kit/js-apis-drm.md#drmerrorcode)。

   ```ts
   function processOfflineReleaseResponse(response: Uint8Array): Promise<void> {
     let mediaKeysystem: drm.mediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
     let mediaKeySession: drm.MediaKeySession = mediaKeysystem.createMediaKeySession();
     var offlineReleaseRequest = new Uint8Array([0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00]);
     mediaKeySession.processMediaKeyResponse(offlineReleaseRequest).then((mediaKeyId: Uint8Array) => {
      console.log('processMediaKeyResponse:' + mediaKeyId);
     }).catch((err: BusinessError) => {
       console.error(`processMediaKeyResponse: ERROR: ${err}`);
     });
     mediaKeySession.processOfflineReleaseResponse(offlineMediaKeyId, response).then(() => {
       console.log('processOfflineReleaseResponse:');
     }).catch((err: BusinessError) => {
       console.error(`processOfflineReleaseResponse: ERROR: ${err}`);
     });
   }
   ```

8. 恢复离线许可证。

   调用MediaKeySession类中的restoreOfflineMediaKeys方法，恢复离线许可证。接口调用失败会返回相应错误码，错误码类型参见[DrmErrorCode](../../reference/apis-drm-kit/js-apis-drm.md#drmerrorcode)。

   ```ts
   function restoreOfflineMediaKeys(mediakeyId: Uint8Array): Promise<void> {
     let mediaKeysystem: drm.mediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
     let mediaKeySession: drm.MediaKeySession = mediaKeysystem.createMediaKeySession();
     var response = new Uint8Array([0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00]);
     mediaKeySession.processOfflineReleaseResponse(mediakeyId, response).then(() => {
       console.log('processOfflineReleaseResponse');
     }).catch((err: BusinessError) => {
       console.error(`processOfflineReleaseResponse: ERROR: ${err}`);
     });
     mediaKeySession.restoreOfflineMediaKey(mediakeyId).then(() => {
      console.log("restoreOfflineMediaKeys");
     }).catch((err: BusinessError) => {
       console.error(`restoreOfflineMediaKeys: ERROR: ${err}`);
     });
   }
   ```

9. 获取当前会话的安全级别。

   调用MediaKeySession类中的getContentProtectionLevel方法，获取当前会话的安全级别。接口调用失败会返回相应错误码，错误码类型参见[DrmErrorCode](../../reference/apis-drm-kit/js-apis-drm.md#drmerrorcode)。

   ```ts
   function getContentProtectionLevel(): ContentProtectionLevel {
     let mediaKeysystem: drm.mediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
     let mediaKeySession: drm.MediaKeySession = mediaKeysystem.createMediaKeySession();
     try {
       let contentProtectionLevel: drm.ContentProtectionLevel = mediaKeySession.getContentProtectionLevel();
     } catch (err) {
       let error = err as BusinessError;
       console.error(`clearMediaKeys ERROR: ${error}`);
     }
      return contentProtectionLevel;
   }
   ```

10. 查询安全解码模块状态。

    调用MediaKeySession类中的requireSecureDecoderModule方法，查询安全解码模块状态。接口调用失败会返回相应错误码，错误码类型参见[DrmErrorCode](../../reference/apis-drm-kit/js-apis-drm.md#drmerrorcode)。

    ```ts
    function requireSecureDecoderModule(mimeType: string): boolean {
      let mediaKeysystem: drm.mediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
      let mediaKeySession: drm.MediaKeySession = mediaKeysystem.createMediaKeySession();
      try {
        let status: boolean = mediaKeySession.requireSecureDecoderModule(mimeType);
      } catch (err) {
        let error = err as BusinessError;
        console.error(`clearMediaKeys ERROR: ${error}`);
      }
      return status;
    }
    ```

11. 销毁MediaKeySession实例。

    调用MediaKeySession类中的destroy方法，销毁MediaKeySession实例。接口调用失败会返回相应错误码，错误码类型参见[DrmErrorCode](../../reference/apis-drm-kit/js-apis-drm.md#drmerrorcode)。

    ```ts
    function destroy(mediaKeySession: MediaKeySession): void {
      mediaKeySession.destroy();
      return;
    }
    ```

12. 状态监听。

    在播放器应用开发过程中，可以随时监听MediaKeySession信息状态，包括密钥请求事件监听、密钥过期事件监听、第三方自定义事件监听、密钥过期更新事件监听、密钥变化事件监听。

    - 通过注册固定的keyRequired回调函数获取监听设备证书请求，MediaKeySession创建成功时即可监听，有该事件返回结果则认为设备证书请求开始，不需要监听的时候使用off进行注销监听。

       ```ts
       function onRegisterkeyRequired(mediaKeysession: drm.MediaKeysession): void {
         mediaKeysession.on('keyRequired', (eventInfo: EventInfo) => {
           console.log('keyRequired' + 'info:' + eventInfo.info + ' extraInfo:' + eventInfo.extraInfo);
         });
         return;
       }
       ```

       ```ts
       function unregisterkeyRequired(mediaKeysession: drm.MediaKeysession): void {
         mediaKeysession.off('keyRequired');
         return;
       }
       ```

    - 通过注册固定的keyExpired回调函数获取监听密钥过期事件，MediaKeySession创建成功时即可监听，不需要监听的时候使用off进行注销监听。

       ```ts
       function onRegisterkeyExpired(mediaKeysession: drm.MediaKeysession): void {
         mediaKeysession.on('keyExpired', (eventInfo: EventInfo) => {
            console.log('keyExpired' + 'info:' + eventInfo.info + ' extraInfo:' + eventInfo.extraInfo);
         });
         return;
       }
       ```

       ```ts
       function unRegisterkeyExpired(mediaKeysession: drm.MediaKeysession): void {
         mediaKeysession.off('keyExpired');
         return;
       }
       ```

    - 通过注册固定的vendorDefined回调函数获取监听第三方自验证事件，MediaKeySession创建成功时即可监听，不需要监听的时候使用off进行注销监听。

       ```ts
       function onRegisterVendorDefined(mediaKeysession: drm.MediaKeysession): void {
         mediaKeysession.on('vendorDefined', (eventInfo: EventInfo) => {
           console.log('vendorDefined' + 'info:' + eventInfo.info + ' extraInfo:' + eventInfo.extraInfo);
         });
         return;
       }
       ```

       ```ts
       function unRegisterVendorDefined(mediaKeysession: drm.MediaKeysession): void {
         mediaKeysession.off('vendorDefined');
         return;
       }
       ```

    - 通过注册固定的expirationUpdated回调函数获取监听过期更新事件，MediaKeySession创建成功时即可监听，不需要监听的时候使用off进行注销监听。

       ```ts
       function onRegisterExpirationUpdated(mediaKeysession: drm.MediaKeysession): void {
         mediaKeysession.on('expirationUpdate', (eventInfo: EventInfo) => {
           console.log('expirationUpdate' + 'info:' + eventInfo.info + ' extraInfo:' + eventInfo.extraInfo);
         });
         return;
       }
       ```

       ```ts
       function unRegisterExpirationUpdated(mediaKeysession: drm.MediaKeysession): void {
         mediaKeysession.off('expirationUpdate');
         return;
       }
       ```

    - 通过注册固定的keyChanged回调函数获取监听密钥变化事件，MediaKeySession创建成功时即可监听，不需要监听的时候使用off进行注销监听。

       ```ts
       function onRegisterKeyChanged(mediaKeysession: drm.MediaKeysession): void {
         mediaKeysession.on('keysChange', (eventInfo: EventInfo) => {
           console.log('keysChange' + 'info:' + eventInfo.info + ' extraInfo:' + eventInfo.extraInfo);
         });
         return;
       }
       ```

       ```ts
       function unRegisterKeyChanged(mediaKeysession: drm.MediaKeysession): void {
         mediaKeysession.off('keysChange');
         return;
       }
       ```
