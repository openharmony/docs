# 会话管理(ArkTS)

DRM会话管理（MediaKeySession）支持MediaKeySession实例管理、许可证申请与处理等。

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

3. 调用MediaKeySession类中的generateMediaKeyRequest方法，生成许可证请求。接口调用失败时，会返回相应错误码，错误码类型参见[DrmErrorCode](../../reference/apis-drm-kit/js-apis-drm.md#drmerrorcode)。

   ```ts
   async function generateMediaKeyRequest(mimeType: string, initData: Uint8Array, mediakeyType: number, optionsData: drm.OptionsData[]): Promise<drm.MediaKeyRequest | undefined> {
    let mediaKeysystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
    let mediaKeySession: drm.MediaKeySession = mediaKeysystem.createMediaKeySession();
    let mediaKeyRequest: drm.MediaKeyRequest | undefined = await mediaKeySession.generateMediaKeyRequest(mimeType, initData, mediakeyType, optionsData).catch((err: BusinessError) => {
       console.error(`generateMediaKeyRequest: ERROR: ${err}`);
       return undefined;
     });
    return mediaKeyRequest;
   }
   ```

4. 调用MediaKeySession类中的processMediaKeyResponse方法，处理许可证响应报文。接口调用失败时，会返回相应错误码，错误码类型参见[DrmErrorCode](../../reference/apis-drm-kit/js-apis-drm.md#drmerrorcode)。

   ```ts
   async function processMediaKeyResponse(response: Uint8Array): Promise<Uint8Array | undefined> {
     let mediaKeysystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
     let mediaKeySession: drm.MediaKeySession = mediaKeysystem.createMediaKeySession();
     let mediaKeyId: Uint8Array | undefined = await mediaKeySession.processMediaKeyResponse(response).catch((err: BusinessError) => {
       console.error(`processMediaKeyResponse: ERROR: ${err}`);
       return undefined;
     });
     return mediaKeyId;
   }
   ```

5. 调用MediaKeySession类中的checkMediaKeyStatus方法，检查当前会话的许可证状态。接口调用失败时，会返回相应错误码，错误码类型参见[DrmErrorCode](../../reference/apis-drm-kit/js-apis-drm.md#drmerrorcode)。

   ```ts
   function checkMediaKeyStatus(): drm.MediaKeyStatus[] | undefined {
     let mediaKeysystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
     let mediaKeySession: drm.MediaKeySession = mediaKeysystem.createMediaKeySession();
     let mediakeyStatus: drm.MediaKeyStatus[] | undefined = undefined;
     try {
       mediakeyStatus = mediaKeySession.checkMediaKeyStatus();
     } catch (err) {
       let error = err as BusinessError;
       console.error(`checkMediaKeyStatus ERROR: ${error}`);
     }
     return mediakeyStatus;
   }
   ```

6. 调用MediaKeySession类中的clearMediaKeys方法，删除当前会话的许可证。接口调用失败时，会返回相应错误码，错误码类型参见[DrmErrorCode](../../reference/apis-drm-kit/js-apis-drm.md#drmerrorcode)。

   ```ts
   function clearMediaKeys(): void {
     let mediaKeysystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
     let mediaKeySession: drm.MediaKeySession = mediaKeysystem.createMediaKeySession();
     try {
       mediaKeySession.clearMediaKeys();
     } catch (err) {
       let error = err as BusinessError;
       console.error(`clearMediaKeys ERROR: ${error}`);
     }
   }
   ```

7. 调用MediaKeySession类中的generateOfflineReleaseRequest方法，生成离线许可证释放请求。接口调用失败会返回相应错误码，错误码类型参见[DrmErrorCode](../../reference/apis-drm-kit/js-apis-drm.md#drmerrorcode)。

   ```ts
   async function generateOfflineReleaseRequest(response: Uint8Array): Promise<Uint8Array | undefined> {
     let mediaKeysystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
     let mediaKeySession: drm.MediaKeySession = mediaKeysystem.createMediaKeySession();
     let mediaKeyId: Uint8Array | undefined = await mediaKeySession.processMediaKeyResponse(response).catch((err: BusinessError) => {
       console.error(`processMediaKeyResponse: ERROR: ${err}`);
       return undefined;
     });
     let offlineReleaseRequest: Uint8Array | undefined = await mediaKeySession.generateOfflineReleaseRequest(mediaKeyId).catch((err: BusinessError) => {
       console.error(`generateOfflineReleaseRequest: ERROR: ${err}`);
       return undefined;
   });
     return offlineReleaseRequest;
   }
   ```

8. 处理离线许可证释放响应。

   调用MediaKeySession类中的processOfflineReleaseResponse方法，处理离线许可证释放响应。接口调用失败会返回相应错误码，错误码类型参见[DrmErrorCode](../../reference/apis-drm-kit/js-apis-drm.md#drmerrorcode)。

   ```ts
   async function processOfflineReleaseResponse(response: Uint8Array): Promise<void> {
     let mediaKeysystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
     let mediaKeySession: drm.MediaKeySession = mediaKeysystem.createMediaKeySession();
     let offlineReleaseRequest = new Uint8Array([0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00]);
     let mediaKeyId: Uint8Array | undefined = await mediaKeySession.processMediaKeyResponse(offlineReleaseRequest).catch((err: BusinessError) => {
       console.error(`processMediaKeyResponse: ERROR: ${err}`);
       return undefined;
     });
     await mediaKeySession.processOfflineReleaseResponse(mediaKeyId, response).catch((err: BusinessError) => {
       console.error(`processOfflineReleaseResponse: ERROR: ${err}`);
     });
   }
   ```

9. 恢复离线许可证。

   调用MediaKeySession类中的restoreOfflineMediaKeys方法，恢复离线许可证。接口调用失败会返回相应错误码，错误码类型参见[DrmErrorCode](../../reference/apis-drm-kit/js-apis-drm.md#drmerrorcode)。

   ```ts
   function restoreOfflineMediaKeys(mediakeyId: Uint8Array): void {
     let mediaKeysystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
     let mediaKeySession: drm.MediaKeySession = mediaKeysystem.createMediaKeySession();
     let response = new Uint8Array([0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00]);
     mediaKeySession.processOfflineReleaseResponse(mediakeyId, response).then(() => {
       console.log('processOfflineReleaseResponse');
     }).catch((err: BusinessError) => {
       console.error(`processOfflineReleaseResponse: ERROR: ${err}`);
     });
     mediaKeySession.restoreOfflineMediaKeys(mediakeyId).then(() => {
      console.log("restoreOfflineMediaKeys success.");
     }).catch((err: BusinessError) => {
       console.error(`restoreOfflineMediaKeys: ERROR: ${err}`);
     });
   }
   ```

10. 获取当前会话的安全级别。

   调用MediaKeySession类中的getContentProtectionLevel方法，获取当前会话的安全级别。接口调用失败会返回相应错误码，错误码类型参见[DrmErrorCode](../../reference/apis-drm-kit/js-apis-drm.md#drmerrorcode)。

   ```ts
   function getContentProtectionLevel(): drm.ContentProtectionLevel | undefined {
     let mediaKeysystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
     let mediaKeySession: drm.MediaKeySession = mediaKeysystem.createMediaKeySession();
     let contentProtectionLevel: drm.ContentProtectionLevel | undefined = undefined;
     try {
       contentProtectionLevel = mediaKeySession.getContentProtectionLevel();
     } catch (err) {
       let error = err as BusinessError;
       console.error(`clearMediaKeys ERROR: ${error}`);
     }
      return contentProtectionLevel;
   }
   ```

11. 查询安全解码模块状态。

    调用MediaKeySession类中的requireSecureDecoderModule方法，查询安全解码模块状态。接口调用失败会返回相应错误码，错误码类型参见[DrmErrorCode](../../reference/apis-drm-kit/js-apis-drm.md#drmerrorcode)。

    ```ts
    function requireSecureDecoderModule(mimeType: string): boolean {
      let mediaKeysystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
      let mediaKeySession: drm.MediaKeySession = mediaKeysystem.createMediaKeySession();
      let status: boolean = false;
      try {
        status = mediaKeySession.requireSecureDecoderModule(mimeType);
      } catch (err) {
        let error = err as BusinessError;
        console.error(`clearMediaKeys ERROR: ${error}`);
      }
      return status;
    }
    ```

12. 销毁MediaKeySession实例。

    调用MediaKeySession类中的destroy方法，销毁MediaKeySession实例。接口调用失败会返回相应错误码，错误码类型参见[DrmErrorCode](../../reference/apis-drm-kit/js-apis-drm.md#drmerrorcode)。

    ```ts
    function destroy(mediaKeySession: drm.MediaKeySession): void {
      mediaKeySession.destroy();
      return;
    }
    ```

13. 状态监听。

    在播放器应用开发过程中，可以随时监听MediaKeySession信息状态，包括密钥请求事件监听、密钥过期事件监听、第三方自定义事件监听、密钥过期更新事件监听、密钥变化事件监听。

    - 通过注册固定的keyRequired回调函数获取监听设备证书请求，MediaKeySession创建成功时即可监听，有该事件返回结果则认为设备证书请求开始，不需要监听的时候使用off进行注销监听。

       ```ts
       function onRegisterkeyRequired(mediaKeySession: drm.MediaKeySession): void {
         mediaKeySession.on('keyRequired', (eventInfo: drm.EventInfo) => {
           console.log('keyRequired' + 'info:' + eventInfo.info + ' extraInfo:' + eventInfo.extraInfo);
         });
         return;
       }
       ```

       ```ts
       function unregisterkeyRequired(mediaKeySession: drm.MediaKeySession): void {
         mediaKeySession.off('keyRequired');
         return;
       }
       ```

    - 通过注册固定的keyExpired回调函数获取监听密钥过期事件，MediaKeySession创建成功时即可监听，不需要监听的时候使用off进行注销监听。

       ```ts
       function onRegisterkeyExpired(mediaKeySession: drm.MediaKeySession): void {
         mediaKeySession.on('keyExpired', (eventInfo: drm.EventInfo) => {
            console.log('keyExpired' + 'info:' + eventInfo.info + ' extraInfo:' + eventInfo.extraInfo);
         });
         return;
       }
       ```

       ```ts
       function unRegisterkeyExpired(mediaKeySession: drm.MediaKeySession): void {
         mediaKeySession.off('keyExpired');
         return;
       }
       ```

    - 通过注册固定的vendorDefined回调函数获取监听第三方自验证事件，MediaKeySession创建成功时即可监听，不需要监听的时候使用off进行注销监听。

       ```ts
       function onRegisterVendorDefined(mediaKeySession: drm.MediaKeySession): void {
         mediaKeySession.on('vendorDefined', (eventInfo: drm.EventInfo) => {
           console.log('vendorDefined' + 'info:' + eventInfo.info + ' extraInfo:' + eventInfo.extraInfo);
         });
         return;
       }
       ```

       ```ts
       function unRegisterVendorDefined(mediaKeySession: drm.MediaKeySession): void {
         mediaKeySession.off('vendorDefined');
         return;
       }
       ```

    - 通过注册固定的expirationUpdated回调函数获取监听过期更新事件，MediaKeySession创建成功时即可监听，不需要监听的时候使用off进行注销监听。

       ```ts
       function onRegisterExpirationUpdated(mediaKeySession: drm.MediaKeySession): void {
         mediaKeySession.on('expirationUpdate', (eventInfo: drm.EventInfo) => {
           console.log('expirationUpdate' + 'info:' + eventInfo.info + ' extraInfo:' + eventInfo.extraInfo);
         });
         return;
       }
       ```

       ```ts
       function unRegisterExpirationUpdated(mediaKeySession: drm.MediaKeySession): void {
         mediaKeySession.off('expirationUpdate');
         return;
       }
       ```

    - 通过注册固定的keyChanged回调函数获取监听密钥变化事件，MediaKeySession创建成功时即可监听，不需要监听的时候使用off进行注销监听。

       ```ts
       function onRegisterKeyChanged(mediaKeySession: drm.MediaKeySession): void {
         mediaKeySession.on('keysChange', (keyInfo : drm.KeysInfo[], newKeyAvailable:boolean) => {
           for(let i = 0; i<keyInfo.length; i++){
             console.log('keysChange' + 'info:' + keyInfo[i].keyId + ' extraInfo:' + keyInfo[i].value);
           }
         });
         return;
       }
       ```

       ```ts
       function unRegisterKeyChanged(mediaKeySession: drm.MediaKeySession): void {
         mediaKeySession.off('keysChange');
         return;
       }
       ```
