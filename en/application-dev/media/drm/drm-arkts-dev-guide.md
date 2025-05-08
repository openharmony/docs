# DRM Development (ArkTS)

You can call the ArkTS APIs of DRM Kit to implement digital copyright protection features such as DRM certificate management, DRM license management, DRM content authorization, and DRM content decryption.

DRM Kit provides MediaKeySystem to manage DRM certificates, DRM licenses, and MediaKeySession instances. MediaKeySession is responsible for authorizing DRM content and can work with Media Kit or AVCodec Kit to decrypt the DRM content, thereby enabling playback of DRM-protected content.

## How to Develop

Read [DRM](../../reference/apis-drm-kit/js-apis-drm.md) for the API reference.

1. Import the DRM Kit module.

   ```ts
   import { drm } from '@kit.DrmKit';
   ```

2. Import the BusinessError module to capture error codes from the DRM Kit APIs.

   ```ts
   import { BusinessError } from '@kit.BasicServicesKit';
   ```

3. (Optional) Obtain the name and ID list of the DRM solutions supported by the device.

   ```ts
   let description: drm.MediaKeySystemDescription[] = drm.getMediaKeySystems();
   ```

   If the returned array is empty, no DRM solution is supported by the device.

4. (Optional) Check whether the device supports the specified DRM solution based on the name, MIME type, and content protection level.

   ```ts
   let isSupported: boolean = drm.isMediaKeySystemSupported("com.clearplay.drm", "video/mp4", drm.ContentProtectionLevel.CONTENT_PROTECTION_LEVEL_SW_CRYPTO);
   ```

   The value **false** means that the device does not support the specified DRM solution.

5. Create a MediaKeySystem instance.

   ```ts
   let mediaKeySystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
   ```

   If the creation fails, **undefined** is returned, indicating that the device does not support the DRM solution.

6. (Optional) Set a MediaKeySystem status listener.

   Register the keySystemRequired callback to listen for DRM certificate request events. This event is triggered when the device needs a DRM certificate. You are advised to complete the certificate request and handling process at this point.

   ```ts
   mediaKeySystem.on('keySystemRequired', (eventInfo: drm.EventInfo) => {
     console.log('keySystemRequired' + 'extra:' + eventInfo.extraInfo + ' data:' + eventInfo.info);
       // Request and process the DRM certificate.
   });
   ```

7. (Optional) Obtain the status of the DRM certificate.

   ```ts
   let certificateStatus: drm.CertificateStatus = mediaKeySystem.getCertificateStatus();
   ```

8. (Optional) Generate a DRM certificate request and process its response.

   If the DRM certificate is not in the drm.CertificateStatus.CERT_STATUS_PROVISIONED state, generate a DRM certificate request and process its response.

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
   // Send drmRequest.data returned by the DRM certificate request to the DRM certificate service through a network request to obtain a response and process the response.
   let provisionResponseByte = new Uint8Array([0x00, 0x00, 0x00, 0x00]); // Response to the DRM certificate request.
   mediaKeySystem.processKeySystemResponse(provisionResponseByte).then(() => {
       console.info("processKeySystemResponse success");
   }).catch((err:BusinessError) =>{
       console.info("processKeySystemResponse err end", err.code);
   });
   ```

9. Create a MediaKeySession instance.

   Create a MediaKeySession instance with the default content protection level of the DRM solution.

   ```ts
   let mediaKeySession: drm.MediaKeySession = mediaKeySystem.createMediaKeySession();
   ```

10. (Optional) Set a MediaKeySession status listener.

    Listen for events of the MediaKeySession instance, including media key request events, media key expiration events, media key validity period update events, and media key change events.

    - Listen for media key request event. You are advised to complete the media key request and handling process at this point.

      ```ts
      mediaKeySession.on('keyRequired', (eventInfo: drm.EventInfo) => {
        console.log('keyRequired' + 'info:' + eventInfo.info + ' extraInfo:' + eventInfo.extraInfo);
          // Request and process the media key.
      });
      ```

    - Listen for media key expiration events.

      ```ts
      mediaKeySession.on('keyExpired', (eventInfo: drm.EventInfo) => {
        console.log('keyExpired' + 'info:' + eventInfo.info + ' extraInfo:' + eventInfo.extraInfo);
      });
      ```

    - Listen for media key validity period update events.

      ```ts
      mediaKeySession.on('expirationUpdate', (eventInfo: drm.EventInfo) => {
        console.log('expirationUpdate' + 'info:' + eventInfo.info + ' extraInfo:' + eventInfo.extraInfo);
      });
      ```

    - Listen for media key change events.

      ```ts
      mediaKeySession.on('keysChange', (keyInfo : drm.KeysInfo[], newKeyAvailable:boolean) => {
          for(let i = 0; i < keyInfo.length; i++){
              console.log('keysChange' + 'info:' + keyInfo[i].keyId + ' extraInfo:' + keyInfo[i].value);
          }
      });
      ```

11. (Optional) Check whether secure decoding is required.

    ```ts
    try {
      let status: boolean = mediaKeySession.requireSecureDecoderModule("video/avc");
    } catch (err) {
      let error = err as BusinessError;
      console.error(`requireSecureDecoderModule ERROR: ${error}`);
    }
    ```

12. Generate a media key request and process its response.

    After obtaining the DRM information of the DRM content, generate a media key request and process its response to request a license for DRM content authorization.

    ```ts
    // Generate initData based on PSSH in the DRM information as required by the DRM solution.
    let initData = new Uint8Array([0x00, 0x00, 0x00, 0x00]);
    // Set optional data based on the DRM solution.
    let optionalData:drm.OptionsData[] = [{
        name: "optionalDataName",
        value: "optionalDataValue"
    }];
    // Request and response for an online media key.
    mediaKeySession.generateMediaKeyRequest("video/mp4", initData, drm.MediaKeyType.MEDIA_KEY_TYPE_ONLINE, optionalData).then(async (licenseRequest: drm.MediaKeyRequest) => {
       console.info("generateMediaKeyRequest success", licenseRequest.mediaKeyRequestType, licenseRequest.data, licenseRequest.defaultURL);
       // Send licenseRequest.data returned by the media key request to the DRM service through a network request to obtain a media key response and process the response.
       let licenseResponse = new Uint8Array([0x00, 0x00, 0x00, 0x00]); // Media key response.
       mediaKeySession.processMediaKeyResponse(licenseResponse).then((mediaKeyId: Uint8Array) => {
         console.info("processMediaKeyResponse success");
       }).catch((err:BusinessError) =>{
         console.info("processMediaKeyResponse err end", err.code);
      });
    }).catch((err:BusinessError) =>{
      console.info("generateMediaKeyRequest err end", err.code);
    });
    // Request and response for an offline media key.
    let offlineMediaKeyId: Uint8Array;
    mediaKeySession.generateMediaKeyRequest("video/mp4", initData, drm.MediaKeyType.MEDIA_KEY_TYPE_OFFLINE, optionalData).then((licenseRequest: drm.MediaKeyRequest) => {
       console.info("generateMediaKeyRequest success", licenseRequest.mediaKeyRequestType, licenseRequest.data, licenseRequest.defaultURL);
       // Send licenseRequest.data returned by the media key request to the DRM service through a network request to obtain a media key response and process the response.
       let licenseResponse = new Uint8Array([0x00, 0x00, 0x00, 0x00]); // Media key response.
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

13. (Optional) Restore offline media keys.

    ```ts
    mediaKeySession.restoreOfflineMediaKeys(offlineMediaKeyId).then(() => {
      console.log("restoreOfflineMediaKeys success.");
    }).catch((err: BusinessError) => {
      console.error(`restoreOfflineMediaKeys: ERROR: ${err}`);
    });
    ```

14. (Optional) Check the status of media keys.

    ```ts
    let mediaKeyStatus: drm.MediaKeyStatus[]
    try {
      mediaKeyStatus = mediaKeySession.checkMediaKeyStatus()
    } catch (err) {
      let error = err as BusinessError;
      console.error(`checkMediaKeyStatus: ERROR: ${error}`);
    }
    ```

15. (Optional) Obtain the IDs of offline media keys, obtain their status, and clear the keys.

    The media key ID is used for offline media key management.

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

16. Destroy the MediaKeySession instance.

    Destroy the MediaKeySession instance when the encrypted content is decrypted and the instance is no longer needed.

    ```ts
    // Release resources when the MediaKeySession instance is no longer needed.
    mediaKeySession.destroy();
    ```

17. Destroy the MediaKeySystem instance.

    Destroy the MediaKeySystem instance when it is no longer needed.

    ```ts
    // Release resources when the MediaKeySystem instance is no longer needed.
    mediaKeySystem.destroy();
    ```
