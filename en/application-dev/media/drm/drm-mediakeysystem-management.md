# DRM Media Key System Management (ArkTS)

Using the **MediaKeySystem** class of the DRM module, you can manage **MediaKeySystem** instances, generate media key system requests to obtain DRM certificates, process responses to these requests, manage media key sessions, manage offline media keys, and obtain DRM statistics and device configuration information.

Before using DRM Kit, check whether the device supports the DRM capabilities of a specific DRM scheme.

In DRM Kit, the DRM scheme exists as a plug-in.

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

3. Check whether the device supports the specified DRM scheme.

   > **NOTE**
   >
   > The value **false** means that the device does not support the specified DRM scheme.

   ```ts
   let isSupported: boolean = drm.isMediaKeySystemSupported("com.clearplay.drm", "video/avc", drm.ContentProtectionLevel.CONTENT_PROTECTION_LEVEL_SW_CRYPTO);
   ```

4. (Optional) Obtain the name and ID list of the DRM schemes on the device.

   > **NOTE**
   >
   > If the returned array is empty, no DRM scheme is supported by the device.

   ```ts
   let description: drm.MediaKeySystemDescription[] = drm.getMediaKeySystems();
   ```

5. Create a **MediaKeySystem** instance.

   > **NOTE**
   >
   > If the creation fails, **undefined** is returned, indicating that the device does not support the DRM capability.

   ```ts
   let mediaKeySystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
   ```

6. (Optional) Obtain the UUID corresponding to the specified DRM scheme name.

   > **NOTE**
   >
   > If the length of the returned UUID is 0, no DRM scheme is supported by the device.

   ```ts
   let uuid: string = drm.getMediaKeySystemUuid("com.clearplay.drm");
   ```

7. (Optional) Set and obtain the configuration items supported by the DRM scheme.

    ```ts
    // If the DRM scheme supports configuration item setting, set the value of a configuration item of the string type supported by the DRM scheme.
    mediaKeySystem.setConfigurationString("configName", "configValue");
    // Obtain the value of a configuration item in the form of a string.
    let configValueString : string = mediaKeySystem.getConfigurationString("version");
    let configValueUint8ArrayA: Uint8Array = new Uint8Array([0x00, 0x00, 0x00, 0x00]);
    // If the DRM scheme supports configuration item setting, set the value of a configuration item of the array type supported by the DRM scheme.
    mediaKeySystem.setConfigurationByteArray("Uint8ArrayConfigName", configValueUint8ArrayA);
    // Obtain the value of a configuration item in the form of an array.
    let configValueUint8ArrayB: Uint8Array = mediaKeySystem.getConfigurationByteArray("Uint8ArrayConfigName");
    ```

8. (Optional) Obtain the maximum content protection level supported by the device.

    ```ts
    let contentProtectionLevel: drm.ContentProtectionLevel = drm.ContentProtectionLevel.CONTENT_PROTECTION_LEVEL_UNKNOWN;
    try {
      contentProtectionLevel = mediaKeySystem.getMaxContentProtectionLevel();
    } catch (err) {
      let error = err as BusinessError;
      console.error(`getMaxContentProtectionLevel ERROR: ${error}`);
    }
    ```

9. Start listening.

    Listen for the event indicating that the application requests a DRM certificate.

    Register the event **'keySystemRequired'**. This event can be listened for when a **MediaKeySystem** instance is created and is triggered when the application requests a DRM certificate.

    ```ts
    mediaKeySystem.on('keySystemRequired', (eventInfo: drm.EventInfo) => {
      console.log('keySystemRequired' + 'extra:' + eventInfo.extraInfo + ' data:' + eventInfo.info);
    });
    ```

10. (Optional) Obtain the status of the DRM certificate.

    ```ts
    let certificateStatus: drm.CertificateStatus = mediaKeySystem.getCertificateStatus();
    ```

11. Generate a provision request.

    During the creation of a **MediaKeySession** session, if no DRM certificate is available, the **keySystemRequired** event is triggered. In this case, the DRM certificate status on the device is obtained first. If the device does not have a DRM certificate or the DRM certificate status is abnormal (not **drm.CertificateStatus.CERT_STATUS_PROVISIONED**), a provision request is generated to obtain a DRM certificate.

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

12. Process the provision response.

    A response to the provision request is received. You need to process this response.

       ```ts
         // Send drmRequest.data returned by the provision request to the DRM certificate service through a network request to obtain a provision response and process the response.
         let provisionResponseByte = new Uint8Array([0x00, 0x00, 0x00, 0x00]);
         mediaKeySystem.processKeySystemResponse(provisionResponseByte).then(() => {
           console.info("processKeySystemResponse success");
         }).catch((err:BusinessError) =>{
           console.info("processKeySystemResponse err end", err.code);
         });
       ```

13. Create a **MediaKeySession** instance.

    Create a **MediaKeySession** instance with the specified content protection level or a **MediaKeySession** instance with the default content protection level of the DRM scheme.
     ```ts
     let mediaKeySession: drm.MediaKeySession = mediaKeySystem.createMediaKeySession();
     ```

14. (Optional) Obtain the list of offline media key IDs, which are used to manage offline media keys.

     ```ts
     let offlineMediaKeyIds: Uint8Array[] = mediaKeySystem.getOfflineMediaKeyIds();
     ```

15. (Optional) Obtain the status of offline media keys.

     ```ts
     try {
       let offlineMediaKeyStatus: drm.OfflineMediaKeyStatus = mediaKeySystem.getOfflineMediaKeyStatus(offlineMediaKeyIds[0]);
     } catch (err) {
       let error = err as BusinessError;
       console.error(`getOfflineMediaKeyStatus ERROR: ${error}`);
     }
     ```

16. (Optional) Clear offline media keys.

     ```ts
     try {
       mediaKeySystem.clearOfflineMediaKeys(offlineMediaKeyIds[0]);
     } catch (err) {
       let error = err as BusinessError;
       console.error(`clearOfflineMediaKeys ERROR: ${error}`);
     }
     ```

17. (Optional) Obtain DRM statistical information, including the number of current sessions, decryption times, and decryption failures, as well as the plug-in version.

     ```ts
     let statisticKeyValue: drm.StatisticKeyValue[] = mediaKeySystem.getStatistics();
     ```

18. Destroy the **MediaKeySession** instance.

    Destroy the **MediaKeySession** instance when the encrypted content is decrypted and the instance is no longer needed.

     ```ts
     // Release resources when the MediaKeySession instance is no longer needed.
     mediaKeySession.destroy();
     ```

19. Destroy this **MediaKeySystem** instance.

    Destroy the **MediaKeySystem** instance when it is no longer used.

     ```ts
     // Release resources when the MediaKeySystem instance is no longer needed.
     mediaKeySystem.destroy();
     ```