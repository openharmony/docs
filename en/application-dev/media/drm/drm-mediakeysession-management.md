# Media Key Session Management (ArkTS)

Using the **MediaKeySession** class of the DRM module, you can manage **MediaKeySession** instances, generate media key requests, and process responses to these requests.

## How to Develop

Read [DRM](../../reference/apis-drm-kit/js-apis-drm.md) for the API reference.

1. Import the module.

   ```ts
   import drm from '@ohos.multimedia.drm';
   ```

2. Import the **BusinessError** module, which provides the error codes thrown by the APIs of the DRM module.

   ```ts
   import {BusinessError} from '@ohos.base';
   ```

3. Call **generateMediaKeyRequest** in the **MediaKeySession** class to generate a media key request. If the call fails, an error code is returned. For details about the error code types, see [DrmErrorCode](../../reference/apis-drm-kit/js-apis-drm.md#drmerrorcode).

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

4. Call **processMediaKeyResponse** in the **MediaKeySession** class to process a response to the media key request. If the call fails, an error code is returned. For details about the error code types, see [DrmErrorCode](../../reference/apis-drm-kit/js-apis-drm.md#drmerrorcode).

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

5. Call **checkMediaKeyStatus** in the **MediaKeySession** class to check the media key status of the current session. If the call fails, an error code is returned. For details about the error code types, see [DrmErrorCode](../../reference/apis-drm-kit/js-apis-drm.md#drmerrorcode).

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

6. Call **clearMediaKeys** in the **MediaKeySession** class to clear the media keys of the current session. If the call fails, an error code is returned. For details about the error code types, see [DrmErrorCode](../../reference/apis-drm-kit/js-apis-drm.md#drmerrorcode).

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

7. Call **generateOfflineReleaseRequest** in the **MediaKeySession** class to generate a request to release offline media keys. If the call fails, an error code is returned. For details about the error code types, see [DrmErrorCode](../../reference/apis-drm-kit/js-apis-drm.md#drmerrorcode).

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

8. Process a response to the request for releasing offline media keys.

   Call **processOfflineReleaseResponse** in the **MediaKeySession** class to process the response. If the call fails, an error code is returned. For details about the error code types, see [DrmErrorCode](../../reference/apis-drm-kit/js-apis-drm.md#drmerrorcode).

   ```ts
   async function processOfflineReleaseResponse(response: Uint8Array): void {
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

9. Restore offline media keys.

   Call **restoreOfflineMediaKeys** in the **MediaKeySession** class to restore the offline media keys. If the call fails, an error code is returned. For details about the error code types, see [DrmErrorCode](../../reference/apis-drm-kit/js-apis-drm.md#drmerrorcode).

   ```ts
   function restoreOfflineMediaKeys(mediakeyId: Uint8Array): Promise<void> {
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

10. Obtain the content protection level of this media key session.

    Call **getContentProtectionLevel** in the **MediaKeySession** class to obtain the content protection level of the current session. If the call fails, an error code is returned. For details about the error code types, see [DrmErrorCode](../../reference/apis-drm-kit/js-apis-drm.md#drmerrorcode).
    
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
    
11. Obtain the status of the secure decoder.

    Call **requireSecureDecoderModule** in the **MediaKeySession** class to obtain the status of the secure decoder. If the call fails, an error code is returned. For details about the error code types, see [DrmErrorCode](../../reference/apis-drm-kit/js-apis-drm.md#drmerrorcode).

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

12. Destroy this **MediaKeySession** instance.

    Call **destroy** in the **MediaKeySession** class to destroy this **MediaKeySession** instance. If the call fails, an error code is returned. For details about the error code types, see [DrmErrorCode](../../reference/apis-drm-kit/js-apis-drm.md#drmerrorcode).

    ```ts
    function destroy(mediaKeySession: drm.MediaKeySession): void {
      mediaKeySession.destroy();
      return;
    }
    ```

13. Listen for the session status.

    You can listen for the following events: key request events, key expiry events, vendor-defined events, key update on expiry events, and key change events.

    - To listen for key request events, register the **keyRequired** callback function. This event can be listened for when a **MediaKeySession** instance is created. If this event callback is returned, a media key request starts. You can use **off** to deregister the callback function when listening is no longer required.

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

    - To listen for key expiry events, register the **keyExpired** callback function. This event can be listened for when a **MediaKeySession** instance is created. You can use **off** to deregister the callback function when listening is no longer required.

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

    - To listen for vendor-defined events, register the **vendorDefined** callback function. This event can be listened for when a **MediaKeySession** instance is created. You can use **off** to deregister the callback function when listening is no longer required.

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

    - To listen for key update on expiry events, register the **expirationUpdated** callback function. This event can be listened for when a **MediaKeySession** instance is created. You can use **off** to deregister the callback function when listening is no longer required.

       ```ts
       function onRegisterExpirationUpdated(mediaKeySession: drm.MediaKeySession): void {
         mediaKeySession.on('expirationUpdate', (eventInfo: drm.EventInfo) => {
           console.log('expirationUpdate' + 'info:' + eventInfo.info + ' extraInfo:' + eventInfo.extraInfo);
         });
         return;
       }
       ```

       ```ts
       function unRegisterExpirationUpdated(mediaKeySession: drm.MediaKeysession): void {
         mediaKeySession.off('expirationUpdate');
         return;
       }
       ```

    - To listen for key change events, register the **keyChanged** callback function. This event can be listened for when a **MediaKeySession** instance is created. You can use **off** to deregister the callback function when listening is no longer required.

       ```ts
       function onRegisterKeyChanged(mediaKeySession: drm.MediaKeySession): void {
         mediaKeySession.on('keysChange', (eventInfo: drm.EventInfo) => {
           console.log('keysChange' + 'info:' + eventInfo.info + ' extraInfo:' + eventInfo.extraInfo);
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