# DRM Media Key Session Management (ArkTS)

The **MediaKeySystem** class of the DRM module supports media key management and media decryption. **MediaKeySession** instances are created and destroyed by **MediaKeySystem** instances.

## How to Develop

Read [DRM](../../reference/apis-drm-kit/js-apis-drm.md) for the API reference.

1. Import the module.

   ```ts
   import { drm } from '@kit.DrmKit';
   ```

2. Import the **BusinessError** module, which provides the error codes thrown by the APIs of the DRM module.

   ```ts
   import { BusinessError } from '@kit.BasicServicesKit';
   ```

3. Listen for the session status.

    You can listen for the following events of a **MediaKeySession** instance: key request events, key expiry events, vendor-defined events, key update on expiry events, and key change events.

    - Listen for key request events, which are triggered when a media key is requested.

       ```ts
       mediaKeySession.on('keyRequired', (eventInfo: drm.EventInfo) => {
         console.log('keyRequired' + 'info:' + eventInfo.info + ' extraInfo:' + eventInfo.extraInfo);
       });
       ```

    - Listen for key expiry events, which are triggered when a media key expires.

       ```ts
       mediaKeySession.on('keyExpired', (eventInfo: drm.EventInfo) => {
          console.log('keyExpired' + 'info:' + eventInfo.info + ' extraInfo:' + eventInfo.extraInfo);
       });
       ```

    - Listen for vendor-defined events, which are triggered when a custom event of the DRM scheme occurs.

       ```ts
       mediaKeySession.on('vendorDefined', (eventInfo: drm.EventInfo) => {
         console.log('vendorDefined' + 'info:' + eventInfo.info + ' extraInfo:' + eventInfo.extraInfo);
       });
       ```

    - Listen for key update on expiry events, which are triggered when a media key updates upon expiry.

       ```ts
       mediaKeySession.on('expirationUpdate', (eventInfo: drm.EventInfo) => {
         console.log('expirationUpdate' + 'info:' + eventInfo.info + ' extraInfo:' + eventInfo.extraInfo);
       });
       ```

    - Listen for key change events, which are triggered when a media key is changed.

       ```ts
       mediaKeySession.on('keysChange', (keyInfo : drm.KeysInfo[], newKeyAvailable:boolean) => {
         for(let i = 0; i < keyInfo.length; i++){
           console.log('keysChange' + 'info:' + keyInfo[i].keyId + ' extraInfo:' + keyInfo[i].value);
         }
       });
       ```

4. Generate a media key request and process its response.

   ```ts
   let initData = new Uint8Array([0x00, 0x00, 0x00, 0x00]);
   // Set optional data based on the DRM scheme.
   let optionalData:drm.OptionsData[] = [{
     name: "...",
     value: "..."
   }];
   // The following example shows how to set an online media key request and response.
   mediaKeySession.generateMediaKeyRequest("video/avc", initData, drm.MediaKeyType.MEDIA_KEY_TYPE_ONLINE, optionalData).then(async (licenseRequest) => {
      console.info("generateMediaKeyRequest success", licenseRequest.mediaKeyRequestType, licenseRequest.data, licenseRequest.defaultURL);
      // Send licenseRequest.data returned by the media key request to the DRM service through a network request to obtain a response and process the response.
      let licenseResponse = new Uint8Array([0x00, 0x00, 0x00, 0x00]);
      mediaKeySession.processMediaKeyResponse(licenseResponse).then((mediaKeyId: Uint8Array) => {
        console.info("processMediaKeyResponse success");
      }).catch((err:BusinessError) =>{
        console.info("processMediaKeyResponse err end", err.code);
     });
   }).catch((err:BusinessError) =>{
     console.info("generateMediaKeyRequest err end", err.code);
   });
   // The following example shows how to set an offline media key request and response.
   let offlineMediaKeyId = new Uint8Array([0x00, 0x00, 0x00, 0x00]);
   mediaKeySession.generateMediaKeyRequest("video/avc", initData, drm.MediaKeyType.MEDIA_KEY_TYPE_OFFLINE, optionalData).then((licenseRequest: drm.MediaKeyRequest) => {
      console.info("generateMediaKeyRequest success", licenseRequest.mediaKeyRequestType, licenseRequest.data, licenseRequest.defaultURL);
      // Send licenseRequest.data returned by the media key request to the DRM service through a network request to obtain a response and process the response.
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

5. (Optional) Check the media key status of the media key session.

    ```ts
    try {
      let keyvalue: drm.MediaKeyStatus[] = mediaKeySession.checkMediaKeyStatus();
      console.info("checkMediaKeyStatus success", keyvalue[0].value);
    } catch (err) {
      let error = err as BusinessError;
      console.error(`checkMediaKeyStatus ERROR: ${error}`);
    }
    ```

6. (Optional) Generate an offline media key release request and process its response.

   ```ts
   mediaKeySession.generateOfflineReleaseRequest(offlineMediaKeyId).then((OfflineReleaseRequest: Uint8Array) => {
     console.info("generateOfflineReleaseRequest success", OfflineReleaseRequest);
     // Send OfflineReleaseRequest returned by the offline media key release request to the DRM service through a network request to obtain a response and process the response.
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

7. (Optional) Restore offline media keys.

   ```ts
   // Restore the specified media key information to the media key session.
   mediaKeySession.restoreOfflineMediaKeys(offlineMediaKeyId).then(() => {
     console.log("restoreOfflineMediaKeys success.");
   }).catch((err: BusinessError) => {
     console.error(`restoreOfflineMediaKeys: ERROR: ${err}`);
   });
   ```

8. (Optional) Obtain the content protection level of the media key session.

    ```ts
    try {
      let contentProtectionLevel: drm.ContentProtectionLevel = mediaKeySession.getContentProtectionLevel();
    } catch (err) {
      let error = err as BusinessError;
      console.error(`getContentProtectionLevel ERROR: ${error}`);
    }
   ```

9. (Optional) Check whether secure decoding is required.

    ```ts
    try {
      let status: boolean = mediaKeySession.requireSecureDecoderModule("video/avc");
    } catch (err) {
      let error = err as BusinessError;
      console.error(`requireSecureDecoderModule ERROR: ${error}`);
    }
    ```

10. (Optional) Clear the media keys of the media key session.

    ```ts
    try {
       mediaKeySession.clearMediaKeys();
    } catch (err) {
      let error = err as BusinessError;
      console.error(`clearMediaKeys ERROR: ${error}`);
    }
    ```
