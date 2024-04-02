# Media Key Session Management (ArkTS)

Using the **MediaKeySession** class of the DRM module, you can manage **MediaKeySession** instances, generate media key requests, and process responses to these requests.

## How to Develop

Read [DRM](../../reference/apis-drm-kit/js-apis-drm.md) for the API reference.

1. Import the module.

   ```ts
   import drm from '@ohos.multimedia.drm';
   ```

2. Call **generateMediaKeyRequest** in the **MediaKeySession** class to generate a media key request. If the call fails, an error code is returned. For details about the error code types, see [DrmErrorCode](../../reference/apis-drm-kit/js-apis-drm.md#drmerrorcode).

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

3. Call **processMediaKeyResponse** in the **MediaKeySession** class to process a response to the media key request. If the call fails, an error code is returned. For details about the error code types, see [DrmErrorCode](../../reference/apis-drm-kit/js-apis-drm.md#drmerrorcode).

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

4. Call **checkMediaKeyStatus** in the **MediaKeySession** class to check the media key status of the current session. If the call fails, an error code is returned. For details about the error code types, see [DrmErrorCode](../../reference/apis-drm-kit/js-apis-drm.md#drmerrorcode).

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

5. Call **clearMediaKeys** in the **MediaKeySession** class to clear the media keys of the current session. If the call fails, an error code is returned. For details about the error code types, see [DrmErrorCode](../../reference/apis-drm-kit/js-apis-drm.md#drmerrorcode).

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

6. Call **generateOfflineReleaseRequest** in the **MediaKeySession** class to generate a request to release offline media keys. If the call fails, an error code is returned. For details about the error code types, see [DrmErrorCode](../../reference/apis-drm-kit/js-apis-drm.md#drmerrorcode).

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

7. Process a response to the request for releasing offline media keys.

   Call **processOfflineReleaseResponse** in the **MediaKeySession** class to process the response. If the call fails, an error code is returned. For details about the error code types, see [DrmErrorCode](../../reference/apis-drm-kit/js-apis-drm.md#drmerrorcode).

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

8. Restore offline media keys.

   Call **restoreOfflineMediaKeys** in the **MediaKeySession** class to restore the offline media keys. If the call fails, an error code is returned. For details about the error code types, see [DrmErrorCode](../../reference/apis-drm-kit/js-apis-drm.md#drmerrorcode).

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

9. Obtain the content protection level of this media key session.

   Call **getContentProtectionLevel** in the **MediaKeySession** class to obtain the content protection level of the current session. If the call fails, an error code is returned. For details about the error code types, see [DrmErrorCode](../../reference/apis-drm-kit/js-apis-drm.md#drmerrorcode).

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

10. Obtain the status of the secure decoder.

    Call **requireSecureDecoderModule** in the **MediaKeySession** class to obtain the status of the secure decoder. If the call fails, an error code is returned. For details about the error code types, see [DrmErrorCode](../../reference/apis-drm-kit/js-apis-drm.md#drmerrorcode).

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

11. Destroy this **MediaKeySession** instance.

    Call **destroy** in the **MediaKeySession** class to destroy this **MediaKeySession** instance. If the call fails, an error code is returned. For details about the error code types, see [DrmErrorCode](../../reference/apis-drm-kit/js-apis-drm.md#drmerrorcode).

    ```ts
    function destroy(mediaKeySession: MediaKeySession): void {
      mediaKeySession.destroy();
      return;
    }
    ```

12. Listen for the session status.

    You can listen for the following events: key request events, key expiry events, vendor-defined events, key update on expiry events, and key change events.

   - To listen for key request events, register the **keyRequired** callback function. This event can be listened for when a **MediaKeySession** instance is created. If this event callback is returned, a media key request starts. You can use **off** to deregister the callback function when listening is no longer required.

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

   - To listen for key expiry events, register the **keyExpired** callback function. This event can be listened for when a **MediaKeySession** instance is created. You can use **off** to deregister the callback function when listening is no longer required.

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

   - To listen for vendor-defined events, register the **vendorDefined** callback function. This event can be listened for when a **MediaKeySession** instance is created. You can use **off** to deregister the callback function when listening is no longer required.

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

   - To listen for key update on expiry events, register the **expirationUpdated** callback function. This event can be listened for when a **MediaKeySession** instance is created. You can use **off** to deregister the callback function when listening is no longer required.

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

   - To listen for key change events, register the **keyChanged** callback function. This event can be listened for when a **MediaKeySession** instance is created. You can use **off** to deregister the callback function when listening is no longer required.

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